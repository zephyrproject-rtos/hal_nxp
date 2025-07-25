/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_IRQSTEER_H_
#define FSL_IRQSTEER_H_

#include "fsl_common.h"
#include "fsl_irqsteer_soc.h"

/*!
 * @addtogroup irqsteer
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! Version 2.0.2. */
#define FSL_IRQSTEER_DRIVER_VERSION (MAKE_VERSION(2, 0, 2))
/*! @} */

/*
 * imx95: one irq channel in one irqsteer instance
 */
/* Irq channel address offset */
#define IRQSTEER_CHANNEL_OFFSET 0x10000
/**
 * Use irq channel 1, CHAN_MASK29 register as an example:
 * irq channel 1, CHAN_MASK29 register offset:
 *   irqChanIdx = 1, regIdx = 29, regNum = 30
 *   (irqChanIdx * IRQSTEER_CHANNEL_OFFSET) + IRQSTEER_CTRL_STRIDE_OFF(regNum, 0) + 0x4 * (regIdx) + 0x4
 *   = (1 * 0x10000) + (30 * 4 * 0) + 0x4 * 29 + 0x4
 *   = 0x10000 + 0 + 0x74 + 0x4
 *   = 0x10078
 */
#define IRQSTEER_CTRL_STRIDE_OFF(regNum, stepIdx)	(regNum * 4 * stepIdx)
#define IRQSTEER_CHAN_MASK(irqChanIdx, regIdx, regNum)		((irqChanIdx * IRQSTEER_CHANNEL_OFFSET) + IRQSTEER_CTRL_STRIDE_OFF(regNum, 0) + 0x4 * (regIdx) + 0x4)
#define IRQSTEER_CHAN_SET(irqChanIdx, regIdx, regNum)		((irqChanIdx * IRQSTEER_CHANNEL_OFFSET) + IRQSTEER_CTRL_STRIDE_OFF(regNum, 1) + 0x4 * (regIdx) + 0x4)
#define IRQSTEER_CHAN_STATUS(irqChanIdx, regIdx, regNum)	((irqChanIdx * IRQSTEER_CHANNEL_OFFSET) + IRQSTEER_CTRL_STRIDE_OFF(regNum, 2) + 0x4 * (regIdx) + 0x4)
#define IRQSTEER_CHAN_MINTDIS(irqChanIdx, regNum)		((irqChanIdx * IRQSTEER_CHANNEL_OFFSET) + IRQSTEER_CTRL_STRIDE_OFF(regNum, 3) + 0x4)
#define IRQSTEER_CHAN_MSTRSTAT(irqChanIdx, regNum)	((irqChanIdx * IRQSTEER_CHANNEL_OFFSET) + IRQSTEER_CTRL_STRIDE_OFF(regNum, 3) + 0x8)

/* Generate register index */
#define IRQSTEER_GEN_REG_IDX(regNum, inputIdx) ((regNum - 1) - (inputIdx / IRQSTEER_INT_SRC_REG_WIDTH))

/* One interrupt map to one bit for a 32 bit width register */
#define IRQSTEER_INT_SRC_REG_WIDTH 32

/* IRQSTEER AGGREGATED(fixed) interrupt number per group is 64 */
#define IRQSTEER_AGGREGATED_INT_NUM_PER_GRP 64

/* Two slices(two registers of 32 bit = 64 bits) */
#define IRQSTEER_SLICE 2

/* 16 is arm interrupt, e.g stacktop, reset exception, hardfault exception... */
#define IRQSTEER_IRQ_OFFSET 16

/* Maximum number of IRQSTEER output channel(master) */
#define IRQSTEER_OUTPUT_CHAN_MAX_NUM (FSL_FEATURE_IRQSTEER_EXT_INT_MAX_NUM / IRQSTEER_AGGREGATED_INT_NUM_PER_GRP)

/* Maximum instance number of IRQSTEER */
#ifndef IRQSTEER_MAX_INST
#error "Pls define IRQSTEER_MAX_INST in devices/<soc part number>/drivers/<core name>/fsl_irqsteer_soc.h"
#endif

#ifndef MULTI_IRQSTEER_INFO
#error "Pls define MULTI_IRQSTEER_INFO in devices/<soc part number>/drivers/<core name>/fsl_irqsteer_soc.h"
#endif

#ifndef MULTI_IRQSTEER_CLOCKS
#error "Pls define MULTI_IRQSTEER_CLOCKS in devices/<soc part number>/drivers/<core name>/fsl_irqsteer_soc.h"
#endif

/* IRQ numbers of multiple irqsteer master(output channel) */
#ifndef MULTI_IRQSTEER_IRQS
#error "Pls define MULTI_IRQSTEER_IRQS in devices/<soc part number>/drivers/<core name>/fsl_irqsteer_soc.h"
#endif

/* The first IRQ number that extend by IRQSTEER(not IRQSTEER output channel IRQ number) */
#ifndef FSL_FEATURE_IRQSTEER_IRQ_START_INDEX
#error "Pls define FSL_FEATURE_IRQSTEER_IRQ_START_INDEX in devices/<soc part number>/<soc part number>_<core name>_feature.h"
#endif

/*!
 * @brief Find the instance index from base address and register offset mappings.
 */
typedef struct
{
    void *reg; /* Base address of peripheral's registers. */
    int32_t  intNum; /* Number of input interrupts that supported by irqsteer(..., 512, 640, 960,...) */
    int32_t  irqChanNum; /* Number of irqsteer instance irq channel(1,2,...) */
    int32_t  irqChanIdx; /* Index of irqsteer instance irq channel */
} irqsteer_info_t;

typedef struct
{
    const irqsteer_info_t* infoPtr;
    int32_t  regNum; /* Register numbers = intNum / 32, 32 is bit width of one register(..., 512/32=16, 640/32=20, 960/32=30,...) */
    int32_t  intGrpNum; /* Number of irqsteer output channel/interrupt group(8 defined grouping of 64 interrupts, it can support 8 * 64 = 512 interrupt input sourIRQn_Type So the irqsteer output channel/interrupt group number is 8) = intNum / 64,(..., 512/64=8,640/64=10,960/64=15) */
    const IRQn_Type  *irq; /* irqsteer irq number for output channels; e.g output channel 0 - 224(irq[0] = 224), output channel 1 - 225(irq[1] = 225),... */
} irqsteer_data_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*! @name Initialization and deinitialization */
/*! @{ */

/**
 * @brief Get the IRQSTEER data(some SoC information).
 *
 * This function gets the specified IRQSTEER data.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 */
irqsteer_data_t *IRQSTEER_GetIrqsteerData(int32_t instIdx);

/*!
 * @brief Initializes the IRQSTEER module.
 *
 * This function enables the clock gate for the specified IRQSTEER.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 */
void IRQSTEER_Init(int32_t instIdx);

/*!
 * @brief Deinitializes an IRQSTEER instance for operation.
 *
 * The clock gate for the specified IRQSTEER is disabled.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 */
void IRQSTEER_Deinit(int32_t instIdx);

/*!
 * @brief Enables an interrupt source.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param irq Interrupt(system interrupt number) to be routed. The interrupt must be an IRQSTEER source.
 */
void IRQSTEER_EnableInterrupt(int32_t instIdx, IRQn_Type irq);

/*! @} */

/*! @name Sources */
/*! @{ */

/*!
 * @brief Disables an interrupt source.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param irq Interrupt source number. The interrupt must be an IRQSTEER source.
 */
void IRQSTEER_DisableInterrupt(int32_t instIdx, IRQn_Type irq);

/*!
 * @brief Check if an interrupt source is enabled.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param irq Interrupt to be queried. The interrupt must be an IRQSTEER source.
 * @return true if the interrupt is not masked, false otherwise.
 */
static inline bool IRQSTEER_InterruptIsEnabled(int32_t instIdx, IRQn_Type irq)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);
    int32_t inputIdx = -1, bitOffset = 0;
    int32_t regIdx = 0;

    inputIdx = irq - FSL_FEATURE_IRQSTEER_IRQ_START_INDEX;
    assert(inputIdx >= 0);

    regIdx = IRQSTEER_GEN_REG_IDX(data->regNum, inputIdx);
    bitOffset = inputIdx % IRQSTEER_INT_SRC_REG_WIDTH;

    return ((*(volatile uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_MASK(data->infoPtr->irqChanIdx, regIdx, data->regNum)) &= (1U << bitOffset)) != 0U);
}

/*!
 * @brief Sets/Forces an interrupt.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param irq Interrupt to be set/forced. The interrupt must be an IRQSTEER source.
 * @param set Switcher of the interrupt set/force function. "true" means to set. "false" means not (normal operation).
 * @note This function is not affected by the function @ref IRQSTEER_DisableInterrupt
 * and @ref IRQSTEER_EnableInterrupt.
 */
static inline void IRQSTEER_SetInterrupt(int32_t instIdx, IRQn_Type irq, bool set)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);
    int32_t inputIdx = -1, bitOffset = 0;
    int32_t regIdx = 0;

    inputIdx = irq - FSL_FEATURE_IRQSTEER_IRQ_START_INDEX;
    assert(inputIdx >= 0);

    regIdx = IRQSTEER_GEN_REG_IDX(data->regNum, inputIdx);
    bitOffset = inputIdx % IRQSTEER_INT_SRC_REG_WIDTH;

    if (set)
    {
        *(volatile uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_SET(data->infoPtr->irqChanIdx, regIdx, data->regNum)) |= (1U << bitOffset);
    }
    else
    {
        *(volatile uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_SET(data->infoPtr->irqChanIdx, regIdx, data->regNum)) &= ~(1U << bitOffset);
    }
}

/*!
 * @brief Enables a master interrupt. By default, all the master interrupts are enabled.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param outputChanIdx Master index of interrupt sources to be routed, options available in enumeration
 * ::irqsteer_int_master_t.
 *
 * For example, to enable the interrupt sources of master 1:
 * @code
 *     IRQSTEER_EnableMasterInterrupt(IRQSTEERM33_INST, 1);
 * @endcode
 */
static inline void IRQSTEER_EnableMasterInterrupt(int32_t instIdx, int32_t outputChanIdx)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);
    *(volatile uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_MINTDIS(data->infoPtr->irqChanIdx, data->regNum)) &= ~(1U << outputChanIdx);
}

/*!
 * @brief Disables a master interrupt.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param outputChanIdx Master index of interrupt sources to be disabled, options available in enumeration
 * ::irqsteer_int_master_t.
 *
 * For example, to disable the interrupt sources of master 1:
 * @code
 *     IRQSTEER_DisableMasterInterrupt(IRQSTEER_M4_0, kIRQSTEER_InterruptMaster1);
 * @endcode
 */
static inline void IRQSTEER_DisableMasterInterrupt(int32_t instIdx, int32_t outputChanIdx)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);
    *(volatile uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_MINTDIS(data->infoPtr->irqChanIdx, data->regNum)) |= (1U << outputChanIdx);
}

/*! @} */

/*! @name Status */
/*! @{ */

/*!
 * @brief Checks the status of one specific IRQSTEER interrupt.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param irq Interrupt source status to be checked. The interrupt must be an IRQSTEER source.
 * @return The interrupt status. "true" means interrupt set. "false" means not.
 *
 * For example, to check whether interrupt from output 0 of Display 1 is set:
 * @code
 *     if (IRQSTEER_IsInterruptSet(IRQSTEER_DISPLAY1_INT_OUT0)
 *     {
 *         ...
 *     }
 * @endcode
 */
static inline bool IRQSTEER_IsInterruptSet(int32_t instIdx, IRQn_Type irq)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);
    int32_t inputIdx = -1, bitOffset = 0;
    int32_t regIdx = 0;

    inputIdx = irq - FSL_FEATURE_IRQSTEER_IRQ_START_INDEX;
    assert(inputIdx >= 0);

    regIdx = IRQSTEER_GEN_REG_IDX(data->regNum, inputIdx);
    bitOffset = inputIdx % IRQSTEER_INT_SRC_REG_WIDTH;

    return *(volatile uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_STATUS(data->infoPtr->irqChanIdx, regIdx, data->regNum)) & (1U << bitOffset);
}

/*!
 * @brief Checks the status of IRQSTEER master interrupt.
 *        The master interrupt status represents at least one interrupt is asserted or not among ALL interrupts.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @return The master interrupt status. "true" means at least one interrupt set. "false" means not.
 * @note The master interrupt status is not affected by the function @ref IRQSTEER_DisableMasterInterrupt.
 */
static inline bool IRQSTEER_IsMasterInterruptSet(int32_t instIdx)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);

    return *(volatile uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_MSTRSTAT(data->infoPtr->irqChanIdx, data->regNum));
}

/*!
 * @brief Gets the next interrupt source (currently set) of one specific master.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param outputChanIdx Master index of interrupt sources, options available in enumeration ::irqsteer_int_master_t.
 * @return The current set next interrupt source number of one specific master(output channel).
 *         Return IRQSTEER_INT_Invalid if no interrupt set.
 */
IRQn_Type IRQSTEER_GetMasterNextInterrupt(int32_t instIdx, int32_t outputChanIdx);

/*!
 * @brief Get the number of interrupt for a given master.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param outputChanIdx Master index of interrupt sources, options available in
 * enumeration ::irqsteer_int_master_t.
 * @return Number of interrupts for a given master.
 */
int32_t IRQSTEER_GetMasterIrqCount(int32_t instIdx, int32_t outputChanIdx);

/*!
 * @brief Get the status of the interrupts a master is in charge of.
 *
 * What this function does is it takes the CHn_STATUS registers associated
 * with the interrupts a master is in charge of and puts them in 64-bit
 * variable. The order they are put in the 64-bit variable is the following:
 * CHn_STATUS[i] : CHn_STATUS[i + 1], where CHn_STATUS[i + 1] is placed in
 * the least significant half of the 64-bit variable. Assuming a master is
 * in charge of 64 interrupts, the user may use the result of this function
 * as such: BIT(i) & IRQSTEER_GetMasterInterrupts() to check if interrupt i
 * is asserted.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param outputChanIdx Index of IRQSTEER output channel.
 * @return 64-bit variable containing the status of the interrupts a master is in charge of.
 */
uint64_t IRQSTEER_GetMasterInterruptsStatus(int32_t instIdx, int32_t outputChanIdx);

/*!
 * @brief Gets the status of IRQSTEER group interrupt.
 *        The group interrupt status represents all the interrupt status within the group specified.
 *        This API aims for facilitating the status return of one set of interrupts.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param outputChanIndex Index of the interrupt group(output channel) status to get.
 * @return The mask of the group interrupt status.
 *         Bit[n] set means the source with bit offset n in group intGroupIndex of IRQSTEER is asserted.
 */
static inline uint64_t IRQSTEER_GetGroupInterruptStatus(int32_t instIdx, int32_t outputChanIdx)
{
    return IRQSTEER_GetMasterInterruptsStatus(instIdx, outputChanIdx);
}

/**
 * @brief Common IRQSTEER interrupt handler.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param outputChanIdx Master index of interrupt sources. ref "int".
 */
void IRQSTEER_CommonIRQHandler(int32_t instIdx, int32_t outputChanIdx);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_IRQSTEER_H_ */
