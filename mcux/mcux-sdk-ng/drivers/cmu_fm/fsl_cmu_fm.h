/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_CMU_FM_H_
#define FSL_CMU_FM_H_

#include "fsl_common.h"
/*!
 * @addtogroup cmu_fm
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 *******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief Defines CMU_FM driver version. */
#define FSL_CMU_FM_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief List of CMU_FM status */
typedef enum _cmu_fm_status_flags
{
    kCMU_FM_Running       = CMU_FM_SR_RS(1U),   /*!< Frequency meter running */
    kCMU_FM_MeterTimeout  = CMU_FM_SR_FMTO(1U), /*!< Frequency meter time out */
    kCMU_FM_MeterComplete = CMU_FM_SR_FMC(1U)   /*!< Frequency meter complete */
} cmu_fm_status_flags_t;

/*! @brief Describes CMU_FM configuration structure. */
typedef struct
{
    uint32_t refClockCount; /*!< defines the duration of the metering operation in number of reference_clock cycles */
    bool enableInterrupt;   /*!< Enable/Disable frequency meter complete interrupt */
} cmu_fm_config_t;

/*! @brief Define CMU_FM interrupt callback function pointer*/
typedef void (*cmu_fm_callback_t)(uint32_t flags);

/*******************************************************************************
 * API
 *******************************************************************************/
extern void CMU_FM_DriverIRQHandler(uint32_t idx);

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initializes CMU_FM configure structure.
 *
 * This function initializes the CMU_FM configure structure to default value. The default
 * value are:
 * @code
 *  config->refClockCount = CMU_FM_RCCR_REF_CNT_MASK;
 *  config->enableInterrupt = true;
 * @endcode
 *
 * @param config Pointer to CMU_FM config structure.
 * @see cmu_fm_config_t
 */
void CMU_FM_GetDefaultConfig(cmu_fm_config_t *config);

/*!
 * @brief Initializes the CMU_FM.
 *
 * This function configures the peripheral for basic operation.
 *
 * @param base   CMU_FM peripheral base address
 * @param config The configuration of CMU_FM
 * @retval kStatus_Success Successfully initialize CMU_FM.
 * @retval kStatus_Fail Initialize failed, because the module can not be initialized when GCR[FME] = 1.
 */
status_t CMU_FM_Init(CMU_FM_Type *base, const cmu_fm_config_t *config);

/*!
 * @brief Shuts down the CMU_FM.
 *
 * @param base CMU_FM peripheral base address
 */
void CMU_FM_Deinit(CMU_FM_Type *base);

/*! @}*/

/*!
 * @name Status Interface
 * @{
 */

/*!
 * @brief Clear status in SR register.
 *
 * @param base CMU_FM peripheral base address
 * @param mask Mask of CMU_FM status flags to clear.
 */
static inline void CMU_FM_ClearStatusFlags(CMU_FM_Type *base, uint32_t mask)
{
    /* Writing one clears FMC and FMTO field based on mask*/
    base->SR = mask;
}

/*!
 * @brief Get status in SR register
 *
 * @param base        CMU_FM peripheral base address
 * @return FMC, FMTO and RS bit field in SR register
 */
static inline uint32_t CMU_FM_GetStatusFlags(CMU_FM_Type *base)
{
    return (base->SR & (CMU_FM_SR_FMC_MASK | CMU_FM_SR_FMTO_MASK | CMU_FM_SR_RS_MASK));
}

/*! @}*/

/*!
 * @name CMU_FM clock configuration
 * @{
 */

/*!
 * @brief Calculate minimum reference clock count cycle.
 *
 * Note: Higher values of reference count results in longer metering window, leading to better
         accuracy in metered clock measurement.
 * @param ref_clk Reference clock frequency
 * @param bus_clk CMU_FM bus clock
 * @param monitored_clk The expected frequency of monitored clock
 * @return Minimum reference count
 */
uint32_t CMU_FM_CalcMinRefClkCnt(uint32_t ref_clk, uint32_t bus_clk, uint32_t monitored_clk);

/*!
 * @brief Set reference clock count
 * Note:
 *   Writes to RCCR are disabled after GCR[FME] = 1.
 * @param base         CMU_FM peripheral base address
 * @param cnt          The reference clock count to be set.
 */
static inline void CMU_FM_SetRefClkCnt(CMU_FM_Type *base, uint32_t cnt)
{
    base->RCCR = cnt;
}

/*!
 * @brief Obtain the metered clock count cycles.
 *
 * @param base CMU_FM peripheral base address
 * @param cnt metered clock count cycles
 * @return metered clock count cycles.
 */
static inline uint32_t CMU_FM_GetMeteredClkCnt(CMU_FM_Type *base)
{
    return ((base->SR & CMU_FM_SR_MET_CNT_MASK) >> CMU_FM_SR_MET_CNT_SHIFT);
}

/*! @}*/

/*!
 * @name CMU_FM Metering configuration
 * @{
 */

/*!
 * @brief Start the frequency metering.
 *
 * This function write value into CMU_FM_GCR_FME register to enable the CMU_FM
 *
 * @param base CMU_FM peripheral base address
 */
static inline void CMU_FM_StartFreqMetering(CMU_FM_Type *base)
{
    base->GCR |= CMU_FM_GCR_FME_MASK;
    while (0U == (base->SR & CMU_FM_SR_RS_MASK))
    {
        /* Safety critical applications must poll SR[RS] to determine when metering operation starts */
    }
}
/*!
 * @brief Stop frequency metering.
 *
 * This function write value into CMU_FM_GCR_FME register to disable the CMU_FM.
 *
 * Note: To stop the ongoing operation, write 0 to FME only when SR[RS] = 1
 *
 * @param base CMU_FM peripheral base address
 */
static inline void CMU_FM_StopFreqMetering(CMU_FM_Type *base)
{
    base->GCR &= ~CMU_FM_GCR_FME_MASK;
    while (CMU_FM_SR_RS_MASK == (base->SR & CMU_FM_SR_RS_MASK))
    {
        /* Safety critical applications must poll SR[RS] to determine when metering operation stops */
    }
}

/*! @}*/

/*!
 * @brief Calculate the frequency of the metered clock signal.
 *
 * @param meteredClkCnt The clock count cycles of metered clock
 * @param refClKCnt The clock count cycles of reference clock
 * @param refClkFreq The frequency of reference clock
 * @return The frequency of metered clock
 */
static inline uint32_t CMU_FM_CalcMeteredClkFreq(uint32_t meteredClkCnt, uint32_t refClKCnt, uint32_t refClkFreq)
{
    return (uint32_t)(((float)meteredClkCnt * (float)refClkFreq) / (float)refClKCnt);
}

/*!
 * @brief Enable frequency meter complete Interrupt
 * Note: Writes to IER are disabled after GCR[FME] = 1.
 * @param base      CMU_FM peripheral base address
 */
static inline void CMU_FM_EnableInterrupts(CMU_FM_Type *base)
{
    base->IER |= CMU_FM_IER_FMCIE_MASK;
}

/*!
 * @brief Disable frequency meter complete Interrupt
 * Note: Writes to IER are disabled after GCR[FME] = 1.
 * @param base      CMU_FM peripheral base address
 */
static inline void CMU_FM_DisableInterrupts(CMU_FM_Type *base)
{
    base->IER &= ~CMU_FM_IER_FMCIE_MASK;
}

/*!
 * @brief Register callback.
 *
 * @param base      CMU_FM peripheral base address
 * @param cb_func   callback function
 */
void CMU_FM_RegisterCallBack(CMU_FM_Type *base, cmu_fm_callback_t cb_func);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_CMU_FM_H_ */
