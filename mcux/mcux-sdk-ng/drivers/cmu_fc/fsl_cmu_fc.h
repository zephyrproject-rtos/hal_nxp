/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_CMU_FC_H_
#define FSL_CMU_FC_H_

#include "fsl_common.h"
/*!
 * @addtogroup cmu_fc
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 *******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief Defines CMU_FC driver version. */
#define FSL_CMU_FC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief List of CMU_FC status */
typedef enum _cmu_fc_status_flags
{
    kCMU_FC_Running           = CMU_FC_SR_RS(1U),  /*!< Frequency check running */
    kCMU_FC_HigherThanHighThr = CMU_FC_SR_FHH(1U), /*!< Frequency higher than high frequency reference threshold */
    kCMU_FC_LowerThanLowThr   = CMU_FC_SR_FLL(1U)  /*!< Frequency lower than low frequency reference threshold */
} cmu_fc_status_flags_t;

typedef enum _cmu_fc_interrupt_flags
{
    kCMU_FC_LowerThanLowThrInterruptEnable        = CMU_FC_IER_FLLIE_MASK,   /*!< Frequency Lower than Low Frequency Reference
                                                                                  Threshold Synchronous Interrupt Enable */
    kCMU_FC_HigherThanHighThrInterruptEnable      = CMU_FC_IER_FHHIE_MASK,   /*!< Frequency Higher than High Frequency Reference
                                                                                  Threshold Synchronous Interrupt Enable */
    kCMU_FC_LowerThanLowThrAsyncInterruptEnable   = CMU_FC_IER_FLLAIE_MASK,  /*!< Frequency Lower than Low Frequency Reference 
                                                                                 Threshold Asynchronous Interrupt Enable */
    kCMU_FC_HigherThanHighThrAsyncInterruptEnable = CMU_FC_IER_FHHAIE_MASK   /*!< Frequency Higher than High Frequency Reference 
                                                                                  Threshold Asynchronous Interrupt Enable */
} cmu_fc_interrupt_flags_t;

/*! @brief Describes CMU_FC configuration structure. */
typedef struct
{
    uint32_t refClockCount;   /*!< defines the duration of the checking operation in number of reference_clock cycles */
    uint32_t interruptEnable; /*!< Enable interrupt for specific event */
    uint32_t highThresholdCnt; /*!< Clock count for high frequency reference threshold of the monitored clock */
    uint32_t lowThresholdCnt;  /*!< Clock count for lower frequency reference Threshold of the monitored clock */
} cmu_fc_config_t;

/*! @brief Define CMU_FC interrupt callback function pointer*/
typedef void (*cmu_fc_callback_t)(uint32_t flags);

/*******************************************************************************
 * API
 *******************************************************************************/
extern void CMU_FC_DriverIRQHandler(uint32_t idx);

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initializes CMU_FC configure structure.
 *
 * This function initializes the CMU_FC configure structure to default value. The default
 * value are:
 * @code
 *  config->refClockCount = CMU_FC_RCCR_REF_CNT_MASK;
 *  config->interruptEnable = kCMU_FC_LowerThanLowThrAsyncInterruptEnable | kCMU_FC_HigherThanHighThrAsyncInterruptEnable;
 * @endcode
 *
 * @param config Pointer to CMU_FC config structure.
 * @see cmu_fc_config_t
 */
void CMU_FC_GetDefaultConfig(cmu_fc_config_t *config);

/*!
 * @brief Initializes the CMU_FC.
 *
 * This function configures the peripheral for basic operation.
 *
 * @param base   CMU_FC peripheral base address
 * @param config The configuration of CMU_FC
 * @retval kStatus_Success Successfully initialize CMU_FC.
 * @retval kStatus_Fail Initialize failed, because the module can not be initialized when GCR[FCE] = 1.
 */
status_t CMU_FC_Init(CMU_FC_Type *base, const cmu_fc_config_t *config);

/*!
 * @brief Shuts down the CMU_FC.
 *
 * @param base CMU_FC peripheral base address
 */
void CMU_FC_Deinit(CMU_FC_Type *base);

/*! @}*/

/*!
 * @name Status Interface
 * @{
 */

/*!
 * @brief Clear status in SR register.
 *
 * @param base CMU_FC peripheral base address
 * @param mask Mask of CMU_FC status flags to clear.
 */
static inline void CMU_FC_ClearStatusFlags(CMU_FC_Type *base, uint32_t mask)
{
    base->SR = mask;
}

/*!
 * @brief Get status in SR register
 *
 * @param base        CMU_FC peripheral base address
 * @return FLL, FHH and RS bit field in SR register
 */
static inline uint32_t CMU_FC_GetStatusFlags(CMU_FC_Type *base)
{
    return (base->SR & (CMU_FC_SR_FLL_MASK | CMU_FC_SR_FHH_MASK | CMU_FC_SR_RS_MASK));
}

/*! @}*/

/*!
 * @name CMU_FC clock configuration
 * @{
 */

/*!
 * @brief Calculate minimum reference clock count cycle.
 *
 * Note: Higher values of reference count results in longer metering window, leading to better
          accuracy in metered clock measurement.
 * @param ref_clk Reference clock frequency
 * @param bus_clk CMU_FC bus clock
 * @param monitored_clk The expected frequency of monitored clock
 * @return Minimum reference count
 */
uint32_t CMU_FC_CalcMinRefClkCnt(uint32_t ref_clk, uint32_t bus_clk, uint32_t monitored_clk);

/*!
 * @brief Calculate optimum high frequency reference threshold and low frequency reference threshold
 *
 * @param config Pointer to a CMU_FC configuration structure
 * @param monitored_clk The expected frequency of monitored clock
 * @param monitored_clk_deviation The deviation of monitored clock
 * @param ref_clk Reference clock frequency
 * @param ref_clk_deviation The deviation of reference clock
 */
void CMU_FC_CalcOptimumThreshold(cmu_fc_config_t *config,
                                 uint32_t monitored_clk,
                                 float monitored_clk_deviation,
                                 uint32_t ref_clk,
                                 float ref_clk_deviation);

/*!
 * @brief Set reference clock count
 * Note:
 *   Writes to RCCR are disabled after GCR[FCE] = 1.
 * @param base         CMU_FC peripheral base address
 * @param cnt          The reference clock count to be set.
 */
static inline void CMU_FC_SetRefClkCnt(CMU_FC_Type *base, uint32_t cnt)
{
    base->RCCR = cnt;
}

/*!
 * @brief Set high reference value for the monitored clock.
 * Note:
 *   Writes to HTCR are disabled after GCR[FCE] = 1.
 * @param base         CMU_FC peripheral base address
 * @param cnt          The reference clock count to be set.
 */
static inline void CMU_FC_SetHighThresholdClkCnt(CMU_FC_Type *base, uint32_t cnt)
{
    base->HTCR = cnt;
}

/*!
 * @brief Set low reference value for the monitored clock.
 * Note:
 *   Writes to LTCR are disabled after GCR[FCE] = 1.
 * @param base         CMU_FC peripheral base address
 * @param cnt          The reference clock count to be set.
 */
static inline void CMU_FC_SetLowThresholdClkCnt(CMU_FC_Type *base, uint32_t cnt)
{
    base->LTCR = cnt;
}

/*! @}*/

/*!
 * @name CMU_FC Checking start/stop configuration
 * @{
 */

/*!
 * @brief Start the frequency checking.
 *
 * This function write value into CMU_FC_GCR_FCE register to enable the CMU_FC
 *
 * @param base CMU_FC peripheral base address
 */
static inline void CMU_FC_StartFreqChecking(CMU_FC_Type *base)
{
    base->GCR |= CMU_FC_GCR_FCE_MASK;
    while (0U == (base->SR & CMU_FC_SR_RS_MASK))
    {
        /* Safety critical applications must poll SR[RS] to determine when checking operation starts */
    }
}
/*!
 * @brief Stop frequency checking.
 *
 * This function write value into CMU_FC_GCR_FCE register to disable the CMU_FC.
 *
 * Note: To stop the ongoing operation, write 0 to FCE only when SR[RS] = 1
 *
 * @param base CMU_FC peripheral base address
 */
static inline void CMU_FC_StopFreqChecking(CMU_FC_Type *base)
{
    base->GCR &= ~CMU_FC_GCR_FCE_MASK;
    while (CMU_FC_SR_RS_MASK == (base->SR & CMU_FC_SR_RS_MASK))
    {
        /* Safety critical applications must poll SR[RS] to determine when checking operation stops */
    }
}

/*! @}*/

/*!
 * @brief Enable frequency check Interrupt
 * Note: Writes to IER are disabled after GCR[FCE] = 1.
 * @param base      CMU_FC peripheral base address
 */
static inline void CMU_FC_EnableInterrupts(CMU_FC_Type *base, uint32_t mask)
{
    /* Enable only either asynchronous FLL event interrupt or synchronous FLL event interrupt at a time. */
    assert((mask & (CMU_FC_IER_FLLAIE_MASK | CMU_FC_IER_FLLIE_MASK)) != (CMU_FC_IER_FLLAIE_MASK | CMU_FC_IER_FLLIE_MASK));
    /* Enable only either asynchronous FHH event interrupt or synchronous FHH event interrupt at a time. */
    assert((mask & (CMU_FC_IER_FHHAIE_MASK | CMU_FC_IER_FHHIE_MASK)) != (CMU_FC_IER_FHHAIE_MASK | CMU_FC_IER_FHHIE_MASK));
    base->IER |= mask;
}

/*!
 * @brief Disable frequency check Interrupt
 * Note: Writes to IER are disabled after GCR[FCE] = 1.
 * @param base      CMU_FC peripheral base address
 */
static inline void CMU_FC_DisableInterrupts(CMU_FC_Type *base, uint32_t mask)
{
    base->IER &= ~mask;
}

/*!
 * @brief Register callback.
 *
 * @param base      CMU_FC peripheral base address
 * @param cb_func   callback function
 */
void CMU_FC_RegisterCallBack(CMU_FC_Type *base, cmu_fc_callback_t cb_func);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_CMU_FC_H_ */
