/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_irqsteer.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.irqsteer"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Whether the irqsteer is initialized */
static bool s_irqsteerInit[IRQSTEER_MAX_INST];
/**
 * @brief Array to map IRQSTEER instance number to info.
 */
static const irqsteer_info_t s_irqsteerInfo[IRQSTEER_MAX_INST] = MULTI_IRQSTEER_INFO;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/**
 * @brief Array to map IRQSTEER instance number to clock name.
 */
static const clock_ip_name_t s_irqsteerClockName[IRQSTEER_MAX_INST] = MULTI_IRQSTEER_CLOCKS;
#endif

/**
 * @brief Array to map IRQSTEER instance number to IRQ number.
 */
static const IRQn_Type s_irqsteerIRQNumber[IRQSTEER_MAX_INST][IRQSTEER_OUTPUT_CHAN_MAX_NUM] = MULTI_IRQSTEER_IRQS;

/**
 * @brief Array to map IRQSTEER instance number to info.
 */
static irqsteer_data_t s_irqsteerData[IRQSTEER_MAX_INST];

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief Initializes the IRQSTEER module.
 *
 * This function enables the clock gate for the specified IRQSTEER.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 */
void IRQSTEER_Init(int32_t instIdx)
{
    if (s_irqsteerInit[instIdx] == false)
    {
        int32_t i = 0;
        irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
        /* Enable clock. */
        (void)CLOCK_EnableClock(s_irqsteerClockName[instIdx]);
#endif
        /* Fill structure s_irqsteerData */
        data->infoPtr = &s_irqsteerInfo[instIdx];

        assert(data->infoPtr->irqChanIdx < data->infoPtr->irqChanNum);
        data->regNum = s_irqsteerInfo[instIdx].intNum / IRQSTEER_INT_SRC_REG_WIDTH;
        data->intGrpNum = s_irqsteerInfo[instIdx].intNum / IRQSTEER_AGGREGATED_INT_NUM_PER_GRP;
        data->irq = (const IRQn_Type *)&s_irqsteerIRQNumber[instIdx];

        /* Mask all interrupts. */
        for (i = 0; i < data->regNum; i++)
        {
            *(volatile uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_MASK(data->infoPtr->irqChanIdx, i, data->regNum)) = 0U;
        }

        for (i = 0; i < data->intGrpNum; i++)
        {
            /* Enable NVIC/GIC vectors for all IRQSTEER master(output channels). */
            (void)EnableIRQ(data->irq[i]);
        }

        s_irqsteerInit[instIdx] = true;
    }
}

/**
 * @brief Deinitializes an IRQSTEER instance for operation.
 *
 * The clock gate for the specified IRQSTEER is disabled.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 */
void IRQSTEER_Deinit(int32_t instIdx)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);
    int32_t i;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable clock. */
    (void)CLOCK_DisableClock(s_irqsteerClockName[instIdx]);
#endif

    /* Disable NVIC vectors for all IRQSTEER master. */
    for (i = 0; i < data->intGrpNum; i++)
    {
        (void)DisableIRQ(data->irq[i]);
    }
}

/*!
 * @brief Enables an interrupt source.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param irq Interrupt(system interrupt number) to be routed. The interrupt must be an IRQSTEER source.
 */
void IRQSTEER_EnableInterrupt(int32_t instIdx, IRQn_Type irq)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);
    int32_t inputIdx = -1, bitOffset = 0;
    int32_t regIdx = 0;

    /* Make sure that the group channel interrupt is enabled */
    IRQSTEER_Init(instIdx);
    inputIdx = irq - FSL_FEATURE_IRQSTEER_IRQ_START_INDEX;
    assert(inputIdx >= 0);

    regIdx = IRQSTEER_GEN_REG_IDX(data->regNum, inputIdx);
    bitOffset = inputIdx % IRQSTEER_INT_SRC_REG_WIDTH;

    *(volatile uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_MASK(data->infoPtr->irqChanIdx, regIdx, data->regNum)) |= (1U << bitOffset);
}

/*! @} */

/*! @name Sources */
/*! @{ */

/*!
 * @brief Disables an interrupt source.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param irq Interrupt source number. The interrupt must be an IRQSTEER source.
 */
void IRQSTEER_DisableInterrupt(int32_t instIdx, IRQn_Type irq)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);
    int32_t inputIdx = -1, bitOffset = 0;
    int32_t regIdx = 0;

    inputIdx = irq - FSL_FEATURE_IRQSTEER_IRQ_START_INDEX;
    assert(inputIdx >= 0);

    regIdx = IRQSTEER_GEN_REG_IDX(data->regNum, inputIdx);
    bitOffset = inputIdx % IRQSTEER_INT_SRC_REG_WIDTH;

    *(volatile uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_MASK(data->infoPtr->irqChanIdx, regIdx, data->regNum)) &= ~(1U << bitOffset);
}

/**
 * @brief Get the IRQSTEER data(some SoC information).
 *
 * This function gets the specified IRQSTEER data.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 */
irqsteer_data_t *IRQSTEER_GetIrqsteerData(int32_t instIdx)
{
    assert(instIdx < IRQSTEER_MAX_INST);

    return &s_irqsteerData[instIdx];
}

/*
 * @brief Get the number of interrupt for a given master.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param outputChanIdx Master index of interrupt sources, options available in
 * enumeration ::int.
 * @return Number of interrupts for a given master(output channel).
 */
int32_t IRQSTEER_GetMasterIrqCount(int32_t instIdx, int32_t outputChanIdx)
{
    int32_t count;
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);

    /*
     * With IRQSTEER, each interrupt group has 32 interrupt sources. How many
     * interrupt groups are connected to one interrupt master, it relates to
     * the SOC integration.
     *
     * There are two cases based on SOC integration:
     *
     * 1. The interrupt group count (number of CHn_MASKx registers) is even number.
     *    In this case, every two interrupt groups are connected to one interrupt master.
     *    So each master has 64 interrupt sources connected.
     * 2. The interrupt group count (number of CHn_MASKx registers) is odd number.
     *    In this case, master 0 is connected to one interrupt group, while other masters
     *    are all connected to two interrupt groups.
     *    So each master 0 has 32 interrupt sources connected, and for other masters,
     *    every master has 64 interrupt sources connected.
     */
    if ((data->regNum % 2U) == 0U)
    {
        count = IRQSTEER_AGGREGATED_INT_NUM_PER_GRP;
    }
    else
    {
        if (outputChanIdx == 0U)
        {
            count = IRQSTEER_INT_SRC_REG_WIDTH;
        }
        else
        {
            count = IRQSTEER_AGGREGATED_INT_NUM_PER_GRP;
        }
    }

    return count;
}

static int32_t IRQSTEER_GetRegIdx(int32_t instIdx, int32_t outputChanIdx, int32_t slice)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);
    int32_t base = data->regNum - 1 - outputChanIdx * IRQSTEER_SLICE;

    if (data->regNum % 2) {
        return base + slice;
    } else {
        return base - slice;
    }
}

/**
 * @brief Gets the next system interrupt source number (currently set) of one specific master(output channel).
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param outputChanIdx Master index of interrupt sources. ref "int".
 * @return The current set next interrupt source number of one specific master.
 *         Return IRQSTEER_INT_Invalid if no interrupt set.
 */
IRQn_Type IRQSTEER_GetMasterNextInterrupt(int32_t instIdx, int32_t outputChanIdx)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);
    int32_t bitOffset, regIdx, sliceNum;
    unsigned chanStatus;
    int32_t i, j;
    int32_t idx = 0;
    int32_t inputIdx = 0;
    IRQn_Type irqNum = NotAvail_IRQn;

    sliceNum = IRQSTEER_GetMasterIrqCount(instIdx, outputChanIdx) / IRQSTEER_INT_SRC_REG_WIDTH;

    for (i = 0; i < sliceNum; i++)
    {
        bitOffset = 0;

        /* Compute the index of the register to be queried */
        regIdx = IRQSTEER_GetRegIdx(instIdx, outputChanIdx, i);

        /* Get register's value */
        chanStatus = *(uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_STATUS(data->infoPtr->irqChanIdx, regIdx, data->regNum));

        for (j = 0; j < IRQSTEER_INT_SRC_REG_WIDTH; j++)
        {
            if ((chanStatus & 1U) != 0U)
            {
                /*
                 * idx
                 * 3   REG26(32bit)-inputs(127:96) +\
                 *                                   +-- output channel 1
                 * 2   REG27(32bit)-inputs(95:64)  +/
                 * 1   REG28(32bit)-inputs(63:32)  +\
                 *                                   +-- output channel 0
                 * 0   REG29(32bit)-inputs[31:0)   +/
                 */
                 idx = (data->regNum - 1) - regIdx;
                 inputIdx = idx * IRQSTEER_INT_SRC_REG_WIDTH + bitOffset;
                 irqNum = (IRQn_Type)(inputIdx + FSL_FEATURE_IRQSTEER_IRQ_START_INDEX);
                 return irqNum;
            }

            bitOffset++;
            chanStatus = chanStatus >> 1U;
        }
    }

    return NotAvail_IRQn;
}

/**
 * @brief Get current set extend interrupts status of one specific master(output channel).
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param outputChanIdx Master index of interrupt sources. ref "int".
 * @return The current set extend interrupt status of one specific master(output channel).
 */
uint64_t IRQSTEER_GetMasterInterruptsStatus(int32_t instIdx, int32_t outputChanIdx)
{
    irqsteer_data_t *data = IRQSTEER_GetIrqsteerData(instIdx);
    int32_t sliceNum, i, regIdx;
    uint32_t chanStatus;
    uint64_t interrupts;

    interrupts = 0UL;
    sliceNum = IRQSTEER_GetMasterIrqCount(instIdx, outputChanIdx) / IRQSTEER_INT_SRC_REG_WIDTH;

    for (i = 0; i < sliceNum; i++) {
        regIdx = IRQSTEER_GetRegIdx(instIdx, outputChanIdx, i);

        chanStatus = *(uint32_t *)((uint32_t)data->infoPtr->reg + IRQSTEER_CHAN_STATUS(data->infoPtr->irqChanIdx, regIdx, data->regNum));

        interrupts |= ((uint64_t)chanStatus << (IRQSTEER_INT_SRC_REG_WIDTH * i));
    }

    return interrupts;
}

/**
 * @brief Common IRQSTEER interrupt handler.
 *
 * @param instIdx base address index in IRQSTEER peripheral base array.
 * @param outputChanIdx Master index of interrupt sources. ref "int".
 */
void IRQSTEER_CommonIRQHandler(int32_t instIdx, int32_t outputChanIdx)
{
    IRQn_Type intSource = NotAvail_IRQn;
    int32_t isr = 0;

    intSource = IRQSTEER_GetMasterNextInterrupt(instIdx, outputChanIdx);
    if (NotAvail_IRQn != intSource)
    {
#if defined(__CORTEX_M)
        /*
         * +-------------------------------------------------------------------------------------------------------------+
         * | isr vector table           |  vector offset | exception number |  IRQ number  |  comments                   |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  Initial SP value          |  0x0           |        N/A       |   N/A        |                             |
         * +-------------------------------------------------------------------------------+                             |
         * |  Reset                     |  0x4           |        1         |   N/A        |                             |
         * +-------------------------------------------------------------------------------+                             |
         * |  NMI                       |  0x8           |        2         |   -14        |                             |
         * +-------------------------------------------------------------------------------+   system exception          |
         * |  Hard fault                |  0xc           |        3         |   -13        |                             |
         * +-------------------------------------------------------------------------------+                             |
         * |  Memory management fault   |  0x10          |        4         |   -12        |                             |
         * +-------------------------------------------------------------------------------+                             |
         * |  Bus fault                 |  0x14          |        5         |   -11        |                             |
         * +-------------------------------------------------------------------------------+                             |
         * |  Usage fault               |  0x18          |        6         |   -10        |                             |
         * +-------------------------------------------------------------------------------+                             |
         * |  Reserved                  |  0x1c          |        7~10      |   -9~-6      |                             |
         * +-------------------------------------------------------------------------------+                             |
         * |  SVCall                    |  0x2c          |        11        |    -5        |                             |
         * +-------------------------------------------------------------------------------+                             |
         * |  Reserved for Debug        |  0x30          |        12        |    -4        |                             |
         * +-------------------------------------------------------------------------------+                             |
         * |  Reserved                  |  0x34          |        13        |    -3        |                             |
         * +-------------------------------------------------------------------------------+                             |
         * |  PendSV                    |  0x38          |        14        |    -2        |                             |
         * +-------------------------------------------------------------------------------+                             |
         * |  Systick                   |  0x3c          |        15        |    -1        |                             |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQ0                      |  0x40          |        16 + 0    |    0         |  peripheral exception       |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQ1                      |  0x44          |        16 + 1    |    1         |  peripheral exception       |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQn                      |  0x4*n + 0x40  |        16 + n    |    1         |  peripheral exception       |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQ224                    |  0x4*224 + 0x40|        16 + 224  |    224       |  peripheral exception       |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQ225                    |  0x4*225 + 0x40|        16 + 225  |    225       |  peripheral exception       |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQ...                    |  0x4*... + 0x40|        16 + ...  |    ...       |  peripheral exception       |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQ236                    |  0x4*236 + 0x40|        16 + 236  |    236       |  peripheral exception       |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQ237                    |  0x4*237 + 0x40|        16 + 237  |    237       |  peripheral exception       |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQ238                    |  0x4*238 + 0x40|        16 + 238  |    238       |extend exception by irqsteer |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQx                      |  0x4*x + 0x40  |        16 + x    |    x         |extend exception by irqsteer |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQy                      |  0x4*y + 0x40  |        16 + y    |    y         |extend exception by irqsteer |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQz                      |  0x4*z + 0x40  |        16 + z    |    z         |extend exception by irqsteer |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQ...                    |  0x4*... + 0x40|        16 + ...  |    ...       |extend exception by irqsteer |
         * +-------------------------------------------------------------------------------------------------------------+
         * |  IRQ1069                   |0x4*1069 + 0x40 |        16 + 1069 |    1069      |extend exception by irqsteer |
         * +-------------------------------------------------------------------------------------------------------------+
         * Note:
         * 16: IRQSTEER_IRQ_OFFSET
         * 64: irqsteer extend interrupts per output channel(per group)
         * 237: maximum irq number of system interrupt controller(GIC/NVIC)
         * 1069: irqsteer output channel number * 64 + 237
         */
        isr = *(int32_t *)(SCB->VTOR + (((int)intSource + IRQSTEER_IRQ_OFFSET) << 2U));
#endif

        if (isr != 0)
        {
            ((void (*)(void))isr)();
        }
    }
}
