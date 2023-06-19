/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ADC_SAR_IP_H
#define ADC_SAR_IP_H

/**
*   @file
*
*   @addtogroup adc_sar_ip Adc Sar IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc_Sar_Ip_Types.h"
#include "Adc_Sar_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION       7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION    0
#define ADC_SAR_IP_SW_MAJOR_VERSION               3
#define ADC_SAR_IP_SW_MINOR_VERSION               0
#define ADC_SAR_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Sar_Ip.h file and Adc_Sar_Ip_Types.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID != ADC_SAR_IP_VENDOR_ID_TYPES)
    #error "Adc_Sar_Ip.h and Adc_Sar_Ip_Types.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip.h file and Adc_Sar_Ip_Types.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip.h and Adc_Sar_Ip_Types.h are different"
#endif

/* Check if Adc_Sar_Ip.h file and Adc_Sar_Ip_Types.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION != ADC_SAR_IP_SW_MAJOR_VERSION_TYPES) || \
     (ADC_SAR_IP_SW_MINOR_VERSION != ADC_SAR_IP_SW_MINOR_VERSION_TYPES) || \
     (ADC_SAR_IP_SW_PATCH_VERSION != ADC_SAR_IP_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip.h and Adc_Sar_Ip_Types.h are different"
#endif

/* Check if Adc_Sar_Ip.h file and Adc_Sar_Ip_Cfg.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID != ADC_SAR_IP_VENDOR_ID_CFG)
    #error "Adc_Sar_Ip.h and Adc_Sar_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip.h file and Adc_Sar_Ip_Cfg.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip.h and Adc_Sar_Ip_Cfg.h are different"
#endif

/* Check if Adc_Sar_Ip.h file and Adc_Sar_Ip_Cfg.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION != ADC_SAR_IP_SW_MAJOR_VERSION_CFG) || \
     (ADC_SAR_IP_SW_MINOR_VERSION != ADC_SAR_IP_SW_MINOR_VERSION_CFG) || \
     (ADC_SAR_IP_SW_PATCH_VERSION != ADC_SAR_IP_SW_PATCH_VERSION_CFG) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip.h and Adc_Sar_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                     DEFINITIONS
==================================================================================================*/
/*!
 * @brief Macros for status and notification flags
 *
 * These flags map to internal hardware flags in different registers, but are
 * grouped together for convenience.
 *
 */
#define ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN    ((uint32)1U << 0U)
#define ADC_SAR_IP_NOTIF_FLAG_NORMAL_EOC         ((uint32)1U << 1U)
#define ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN  ((uint32)1U << 2U)
#define ADC_SAR_IP_NOTIF_FLAG_INJECTED_EOC       ((uint32)1U << 3U)
#define ADC_SAR_IP_NOTIF_FLAG_CTU_EOC            ((uint32)1U << 4U)
#define ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN   ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN
#define ADC_SAR_IP_STATUS_FLAG_NORMAL_EOC        ADC_SAR_IP_NOTIF_FLAG_NORMAL_EOC
#define ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN
#define ADC_SAR_IP_STATUS_FLAG_INJECTED_EOC      ADC_SAR_IP_NOTIF_FLAG_INJECTED_EOC
#define ADC_SAR_IP_STATUS_FLAG_CTU_EOC           ADC_SAR_IP_NOTIF_FLAG_CTU_EOC
#define ADC_SAR_IP_STATUS_FLAG_CALIBRATED        ((uint32)1U << 5U)
#define ADC_SAR_IP_STATUS_FLAG_NORMAL_STARTED    ((uint32)1U << 6U)
#define ADC_SAR_IP_STATUS_FLAG_INJECTED_STARTED  ((uint32)1U << 7U)
#define ADC_SAR_IP_STATUS_FLAG_INJECTED_ABORTED  ((uint32)1U << 8U)
#define ADC_SAR_IP_STATUS_FLAG_CTU_STARTED       ((uint32)1U << 9U)
#define ADC_SAR_IP_STATUS_FLAG_AUTOCLOCKOFF      ((uint32)1U << 10U)

#define ADC_SAR_IP_STATUS_FLAG_ALL       (ADC_SAR_IP_STATUS_FLAG_NORMAL_EOC | \
                                          ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN | \
                                          ADC_SAR_IP_STATUS_FLAG_INJECTED_EOC | \
                                          ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN | \
                                          ADC_SAR_IP_STATUS_FLAG_CTU_EOC | \
                                          ADC_SAR_IP_STATUS_FLAG_CALIBRATED | \
                                          ADC_SAR_IP_STATUS_FLAG_NORMAL_STARTED | \
                                          ADC_SAR_IP_STATUS_FLAG_INJECTED_STARTED | \
                                          ADC_SAR_IP_STATUS_FLAG_INJECTED_ABORTED | \
                                          ADC_SAR_IP_STATUS_FLAG_CTU_STARTED | \
                                          ADC_SAR_IP_STATUS_FLAG_AUTOCLOCKOFF \
                                          )
#define ADC_SAR_IP_NOTIF_FLAG_ALL        (ADC_SAR_IP_NOTIF_FLAG_NORMAL_EOC | \
                                          ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | \
                                          ADC_SAR_IP_NOTIF_FLAG_INJECTED_EOC | \
                                          ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN | \
                                          ADC_SAR_IP_NOTIF_FLAG_CTU_EOC \
                                          )


/*!
 * @brief Macros for channel notifications
 *
 * These notification flags map to internal hardware flags in different registers,
 * but are grouped together for convenience.
 *
 */
#define ADC_SAR_IP_CHAN_NOTIF_EOC      ((uint32)1U << 0U)
#define ADC_SAR_IP_CHAN_NOTIF_WDG      ((uint32)1U << 1U)

#define ADC_SAR_IP_CHAN_NOTIF_FLAG_ALL (ADC_SAR_IP_CHAN_NOTIF_EOC | \
                                        ADC_SAR_IP_CHAN_NOTIF_WDG \
                                        )


/*!
 * @brief Macros for watchdog registers
 *
 * These macros help decode and compose bit mask for watchdog functionality
 *
 */
#define ADC_SAR_IP_WDG_HIGH_FLAG                  ((uint8)1U << 1U)
#define ADC_SAR_IP_WDG_LOW_FLAG                   ((uint8)1U << 0U)

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/*!
* @brief Return the address of the specified data register
*
* This function returns the address of the specified data register
*
* @param[in] u32Instance - ADC instance number
* @param[in] u32ChannelIndex - adc channel of the Hw unit
* @return status:
*  - value of the address of the data for the specified channel
*/
uint32 Adc_Sar_Ip_GetDataAddress(uint32 u32Instance,
                                 uint32 u32ChannelIndex);

/*!
 * @brief Initialize ADC_SAR module
 *
 * This function initializes the ADC_SAR module by configuring all
 * available features.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] pConfig - configuration struct pointer
 * @return status:
 *  - ADC_SAR_IP_STATUS_SUCCESS: init successful
 *  - ADC_SAR_IP_STATUS_TIMEOUT: init step timed out
 */
Adc_Sar_Ip_StatusType Adc_Sar_Ip_Init(const uint32 u32Instance,
                                      const Adc_Sar_Ip_ConfigType * const pConfig);

/*!
 * @brief Deinitialize ADC_SAR module
 *
 * This function resets the ADC internal registers to default values.
 *
 * @param[in] u32Instance - ADC instance number
 * @return status:
 *  - ADC_SAR_IP_STATUS_SUCCESS: deinit successful
 *  - ADC_SAR_IP_STATUS_TIMEOUT: deinit step timed out
 */
Adc_Sar_Ip_StatusType Adc_Sar_Ip_Deinit(const uint32 u32Instance);

/*!
 * @brief Configures the converter chains the given configuration structure
 *
 * This function configures the ADC Normal and Injected Chains with the options
 * provided in the structure.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] pChansIdxMask - channel configuration structure
 * @param[in] pChainType - conversion chain (Normal or Injected)
 * @return void
 */
void Adc_Sar_Ip_ChainConfig(const uint32 u32Instance,
                            const Adc_Sar_Ip_ChansIdxMaskType * const pChansIdxMask,
                            const Adc_Sar_Ip_ConvChainType pChainType);

/*!
 * @brief Enable a channel
 *
 * This function enables a channel in a specified conversion chain
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] pChainType - conversion chain (Normal or Injected)
 * @param[in] u32ChnIdx - channel 0
 * @return void
 */
void Adc_Sar_Ip_EnableChannel(const uint32 u32Instance,
                              const Adc_Sar_Ip_ConvChainType pChainType,
                              const uint32 u32ChnIdx);

/*!
 * @brief Disable a channel
 *
 * This function disables a channel in a specified conversion chain
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] pChainType - conversion chain (Normal or Injected)
 * @param[in] u32ChnIdx - channel 0
 * @return void
 */
void Adc_Sar_Ip_DisableChannel(const uint32 u32Instance,
                              const Adc_Sar_Ip_ConvChainType pChainType,
                              const uint32 u32ChnIdx);

#if (ADC_SAR_IP_SET_RESOLUTION == STD_ON)
/*!
 * @brief Set conversion resolution
 *
 * This function sets the conversion resolution (number of bits per conversion data)
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] eResolution - conversion resolution
 * @return void
 */
void Adc_Sar_Ip_SetResolution(const uint32 u32Instance,
                              const Adc_Sar_Ip_Resolution eResolution);
#endif /* (ADC_SAR_IP_SET_RESOLUTION == STD_ON) */

/*!
 * @brief Start conversion
 *
 * This function starts a conversion channel (Normal or Injected)
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] pChainType - conversion chain (Normal or Injected)
 * @return void
 */
void Adc_Sar_Ip_StartConversion(const uint32 u32Instance,
                                const Adc_Sar_Ip_ConvChainType pChainType);

/*!
 * @brief Get the status flags
 *
 * This function returns the status flags of the ADC.
 *
 * @param[in] u32Instance - ADC instance number
 * @return the status flag bit-mask
 */
uint32 Adc_Sar_Ip_GetStatusFlags(const uint32 u32Instance);

/*!
 * @brief Clear the status flags
 *
 * This function clears the status flags of the ADC.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] u32Mask - bit-mask of flags to clear
 * @return void
 */
void Adc_Sar_Ip_ClearStatusFlags(const uint32 u32Instance,
                                 const uint32 u32Mask);

/*!
 * @brief Self test
 *
 * This function executes a self test on the ADC instance.
 *
 * @param[in] u32Instance - ADC instance number
 * @return status:
 *  - ADC_SAR_IP_STATUS_SUCCESS: self testing successful
 *  - ADC_SAR_IP_STATUS_TIMEOUT: self testing step timed out
 */
Adc_Sar_Ip_StatusType Adc_Sar_Ip_SelfTest(const uint32 u32Instance);

/*!
 * @brief Get conversion results for a conversion chain
 *
 * This function gets the conversion results for the selected Conversion Chain.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] pChainType - conversion chain (Normal, Injected or CTU)
 * @param[in] u32Length - the length of the buffer
 * @param[out] pResults - the output buffer
 * @return the number of values written in the buffer (max length)
 */
uint32 Adc_Sar_Ip_GetConvDataToArray(const uint32 u32Instance,
                                     const Adc_Sar_Ip_ConvChainType pChainType,
                                     const uint32 u32Length,
                                     uint16 * const pResults);

/*!
 * @brief Get conversion results for a conversion chain with extended information
 *
 * This function gets the conversion results for the selected Conversion Chain, with
 * extended information about each conversion result (channel index, valid an overwritten
 * properties and conversion data). This function should be used in case of configurations
 * with overlapping channel lists in different chains, resulting in overwrite of conversion
 * data when a higher priority chain is executed before all data was read.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] pChainType - conversion chain (Normal, Injected or CTU)
 * @param[in] u32Length - the length of the buffer
 * @param[out] pResults - the output buffer
 * @return the number of values written in the buffer (max length)
 */
uint32 Adc_Sar_Ip_GetConvResultsToArray(const uint32 u32Instance,
                                        const Adc_Sar_Ip_ConvChainType pChainType,
                                        const uint32 u32Length,
                                        Adc_Sar_Ip_ChanResultType * const pResults);

/*!
 * @brief Return the result of the conversion
 *
 * This function returns the result of the conversion for a single channel
 *
 * @param [in] u32Instance - ADC instance number
 * @param [in] u32ChnIdx - channel 0
 * @return conversion data
 */
uint16 Adc_Sar_Ip_GetConvData(const uint32 u32Instance,
                              const uint32 u32ChnIdx);

/*!
 * @brief Return the result and the status of the conversion
 *
 * This function returns the result and the status of the conversion
 * for a single channel
 *
 * @param [in] u32Instance - ADC instance number
 * @param [in] u32ChnIdx - channel 0
 * @param [in] pChainType - conversion chain (Normal, Injected or CTU)
 * @param [out] pResult - pointer to the buffer where the result will be written
 * @return void
 */
void Adc_Sar_Ip_GetConvResult(const uint32 u32Instance,
                              const uint32  u32ChnIdx,
                              const Adc_Sar_Ip_ConvChainType pChainType,
                              Adc_Sar_Ip_ChanResultType * const pResult);

/*!
 * @brief Perform Calibration of the ADC
 *
 * This function performs a calibration of the ADC. The maximum input clock
 * frequency for the ADC is 80 MHz, checked with assertions if DEV_ASSERT is
 * enabled. After calibration, the ADC is left in Powerup state (PWDN bit is clear).
 *
 * @param[in] u32Instance - ADC instance number
 * @return the calibration result
 *  - ADC_SAR_IP_STATUS_SUCCESS: calibration successful
 *  - ADC_SAR_IP_STATUS_TIMEOUT: calibration step timed out
 *  - ADC_SAR_IP_STATUS_ERROR: calibration failed
 */
Adc_Sar_Ip_StatusType Adc_Sar_Ip_DoCalibration(const uint32 u32Instance);

/*!
 * @brief Power up the ADC
 *
 * This function enables the ADC (disables the Power Down feature).
 *
 * @param[in] u32Instance - ADC instance number
 * @return status:
 *  - ADC_SAR_IP_STATUS_SUCCESS: power up successful
 *  - ADC_SAR_IP_STATUS_TIMEOUT: power up failed
 */
Adc_Sar_Ip_StatusType Adc_Sar_Ip_Powerup(const uint32 u32Instance);

/*!
 * @brief Power down the ADC
 *
 * This function disables the ADC (enables the Power Down feature).
 *
 * @param[in] u32Instance - ADC instance number
 * @return status:
 *  - ADC_SAR_IP_STATUS_SUCCESS: power down successful
 *  - ADC_SAR_IP_STATUS_TIMEOUT: power down failed
 */
Adc_Sar_Ip_StatusType Adc_Sar_Ip_Powerdown(const uint32 u32Instance);

#if ( \
     (STD_ON == ADC_SAR_IP_ECH_ENABLED) || (STD_ON == ADC_SAR_IP_JECH_ENABLED) || \
     (STD_ON == ADC_SAR_IP_EOC_ENABLED) || \
     ((FEATURE_ADC_HAS_CTU == 1U) && (STD_ON == ADC_SAR_IP_EOCTU_ENABLED)) \
    )
/*!
 * @brief Enable ADC interrupts
 *
 * This function enables ADC interrupts.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] u32NotificationMask - mask of interrupts to enable (of status flags)
 * @return void
 */
void Adc_Sar_Ip_EnableNotifications(const uint32 u32Instance,
                                    const uint32 u32NotificationMask);

/*!
 * @brief Disable ADC interrupts
 *
 * This function disables ADC interrupts.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] u32NotificationMask - mask of interrupts to disable (of status flags)
 * @return void
 */
void Adc_Sar_Ip_DisableNotifications(const uint32 u32Instance,
                                     const uint32 u32NotificationMask);
#endif /* (STD_ON == ADC_SAR_IP_ECH_ENABLED) .. */

#if ((STD_ON == ADC_SAR_IP_WDG_ENABLED) || (STD_ON == ADC_SAR_IP_EOC_ENABLED))
/*!
 * @brief Enable ADC interrupt for a channel
 *
 * This function enables interrupt generation on End of Conversion and watchdog
 * events for a single channel.
 * The mask parameter can be set using the defines provided in the driver header
 * file that have the pattern ADC_SAR_IP_CHAN_NOTIF_... e.g. ADC_SAR_IP_CHAN_NOTIF_EOC.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] u32ChnIdx - channel 0
 * @param[in] u32Mask - mask selecting targeted events
 * @return void
 */
void Adc_Sar_Ip_EnableChannelNotifications(const uint32 u32Instance,
                                           const uint32 u32ChnIdx,
                                           const uint32 u32Mask);

/*!
 * @brief Disable ADC interrupt for a channel
 *
 * This function disables interrupt generation on End of Conversion and watchdog
 * events for a single channel.
 * The mask parameter can be set using the defines provided in the driver header
 * file that have the pattern ADC_SAR_IP_CHAN_NOTIF_... e.g. ADC_SAR_IP_CHAN_NOTIF_EOC.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] u32ChnIdx - channel 0
 * @param[in] u32Mask - mask selecting targeted events
 * @return void
 */
void Adc_Sar_Ip_DisableChannelNotifications(const uint32 u32Instance,
                                            const uint32 u32ChnIdx,
                                            const uint32 u32Mask);
#endif /* ((STD_ON == ADC_SAR_IP_WDG_ENABLED) || (STD_ON == ADC_SAR_IP_EOC_ENABLED)) */

/*!
 * @brief Set the ADC clocks
 *
 * This function initializes the ADC clock configuration.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] pConfig - the clock configuration
 * @return status:
 *  - ADC_SAR_IP_STATUS_SUCCESS: set successful
 *  - ADC_SAR_IP_STATUS_TIMEOUT: power up or down sequence timed out
 */
Adc_Sar_Ip_StatusType Adc_Sar_Ip_SetClockMode(const uint32 u32Instance,
                                              const Adc_Sar_Ip_ClockConfigType * const pConfig);

#if FEATURE_ADC_HAS_CONVERSION_TIMING
/*!
 * @brief Set the sample times
 *
 * This function sets the sample times for each channnel group.
 * Note: aSampleTimes must contain the sample times in order of the channel
 * groups, e.g. sample time for the channel group 1 must be on the first position.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] aSampleTimes - array with size ADC_SAR_IP_NUM_GROUP_CHAN containing sample times for each channel group
 * @return void
 */
void Adc_Sar_Ip_SetSampleTimes(const uint32 u32Instance,
                               const uint8 * const aSampleTimes);
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */

#if FEATURE_ADC_HAS_AVERAGING
/*!
 * @brief Configure averaging
 *
 * This function enables averaging and selects the number of conversions to average.
 * The mask parameter should be set using the Adc_Sar_Ip_AvgSelectType enum elements
 * that have the pattern ADC_SAR_IP_AVG_... e.g. ADC_SAR_IP_AVG_4_CONV.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] bAvgEn - enable or disable averaging
 * @param[in] eAvgSel - selects number of conversions to average
 * @return void
 */
void Adc_Sar_Ip_SetAveraging(const uint32 u32Instance,
                             const boolean bAvgEn,
                             const Adc_Sar_Ip_AvgSelectType eAvgSel);
#endif /* FEATURE_ADC_HAS_AVERAGING */

/*!
 * @brief Abort ongoing conversion
 *
 * This function aborts an ongoing conversion.
 *
 * @param[in] u32Instance - ADC instance number
 * @return void
 */
void Adc_Sar_Ip_AbortConversion(const uint32 u32Instance);

/*!
 * @brief Abort ongoing chain conversion
 *
 * This function aborts an ongoing chain of conversions.
 * If scan(continuos) mode is selected, then bAllowRestart selects whether
 * the abort command restarts the chain or stops it. For one shot conversion,
 * this should be FALSE.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] bBlocking - wait and check that the ongoing conversion has stopped
 * @param[in] bAllowRestart - restart continuos conversion instead of aborting
 * @return status:
 *  - ADC_SAR_IP_STATUS_SUCCESS: abort successful
 *  - ADC_SAR_IP_STATUS_TIMEOUT: ongoing conversion could not be stopped
 * @return void
 */
Adc_Sar_Ip_StatusType Adc_Sar_Ip_AbortChain(const uint32 u32Instance,
                                            const boolean bBlocking,
                                            const boolean bAllowRestart);

#if FEATURE_ADC_HAS_PRESAMPLING
/*!
 * @brief Set the Presampling Source for the channel group
 *
 * This function configures the Presampling Source for a channel group.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] pChanGroup - the channel group
 * @param[in] pPresampleSource - the presampling source
 * @return void
 */
void Adc_Sar_Ip_SetPresamplingSource(const uint32 u32Instance,
                                     const Adc_Sar_Ip_ChanGroupType pChanGroup,
                                     const Adc_Sar_Ip_PresamplingSourceType pPresampleSource);

/*!
 * @brief Enable Presampling on one channel
 *
 * This function enables the Presampling on one channel of the ADC.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] u32ChnIdx - channel 0
 * @return void
 */
void Adc_Sar_Ip_EnableChannelPresampling(const uint32 u32Instance,
                                         const uint32 u32ChnIdx);

/*!
 * @brief Disable Presampling on one channel
 *
 * This function disables the Presampling on one channel of the ADC.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] u32ChnIdx - channel 0
 * @return void
 */
void Adc_Sar_Ip_DisableChannelPresampling(const uint32 u32Instance,
                                          const uint32 u32ChnIdx);

/*!
 * @brief Enable Conversion Presampled Data
 *
 * This function enables bypass of the Sampling Phase, resulting in a conversion
 * of the presampled data. This is available only for channels that have presampling
 * enabled.
 *
 * @param[in] u32Instance - ADC instance number
 * @return void
 */
void Adc_Sar_Ip_EnablePresampleConversion(const uint32 u32Instance);

/*!
 * @brief Disable Conversion of Presampled Data
 *
 * This function disables Sampling Phase bypass.
 *
 * @param[in] u32Instance - ADC instance number
 * @return void
 */
void Adc_Sar_Ip_DisablePresampleConversion(const uint32 u32Instance);
#endif /* FEATURE_ADC_HAS_PRESAMPLING */

/*!
 * @brief Enable DMA Requests
 *
 * This function enables requests to DMA from ADC
 *
 * @param[in] u32Instance - ADC instance number
 * @return void
 */
void Adc_Sar_Ip_EnableDma(const uint32 u32Instance);

/*!
 * @brief Disable DMA Requests
 *
 * This function disables requests to DMA from ADC
 *
 * @param[in] u32Instance - ADC instance number
 * @return void
 */
void Adc_Sar_Ip_DisableDma(const uint32 u32Instance);

/*!
 * @brief Enable DMA on one channel
 *
 * This function enables DMA requests triggered by End of Conversion event from
 * a selected channel.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] u32ChnIdx - channel 0
 * @return void
 */
void Adc_Sar_Ip_EnableChannelDma(const uint32 u32Instance,
                                 const uint32 u32ChnIdx);

/*!
 * @brief Disable DMA on one channel
 *
 * This function disables DMA requests triggered by End of Conversion event from
 * a selected channel.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] u32ChnIdx - channel 0
 * @return void
 */
void Adc_Sar_Ip_DisableChannelDma(const uint32 u32Instance,
                                  const uint32 u32ChnIdx);

/*!
 * @brief Disable DMA on all channels
 *
 * This function disables DMA requests triggered by End of Conversion event from
 * all channels.
 *
 * @param[in] u32Instance - ADC instance number
 * @return void
 */
void Adc_Sar_Ip_DisableChannelDmaAll(const uint32 u32Instance);

/*!
 * @brief Set DMA Request Clear Source
 *
 * This function selects the DMA Request Flag Clear Source.
 *
 * @param[in] u32Instance - ADC instance number
 * @param[in] pDmaClear - the clear source for DMA Requests (Ack from DMA Controller or
    read of data registers)
 * @return void
 */
void Adc_Sar_Ip_SetDmaClearSource(const uint32 u32Instance,
                                  const Adc_Sar_Ip_ClearSourceType pDmaClear);

#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
/*!
 * @brief Configure watchdog threshold register
 *
 * This function configures the high/low thresholds for a certain register.
 *
 * @param [in] u32Instance - ADC instance number
 * @param [in] u8RegisterIdx - the index of the register
 * @param [in] pThresholdValues - the threshold values
 * @return void
 */
void Adc_Sar_Ip_SetWdgThreshold(const uint32 u32Instance,
                                const uint8 u8RegisterIdx,
                                const Adc_Sar_Ip_WdgThresholdType * const pThresholdValues);
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */

/*!
 * @brief Configure conversion mode
 *
 * This function configures the used conversion mode.
 * Note: The selected ADC instance must be in the IDLE state.
 *
 * @param [in] u32Instance - ADC instance number
 * @param [in] eConvMode - selected conversion mode
 * @return void
 */
void Adc_Sar_Ip_SetConversionMode(const uint32 u32Instance,
                                 const Adc_Sar_Ip_ConvModeType eConvMode);

#if FEATURE_ADC_HAS_CTU
/*!
 * @brief Configure CTU mode
 *
 * This function configures the CTU mode and enable.
 *
 * @param [in] u32Instance - ADC instance number
 * @param [in] eCtuMode - selected CTU mode
 * @return status:
 *  - ADC_SAR_IP_STATUS_SUCCESS: set successful
 *  - ADC_SAR_IP_STATUS_TIMEOUT: power up or down sequence timed out
 */
Adc_Sar_Ip_StatusType Adc_Sar_Ip_SetCtuMode(const uint32 u32Instance,
                                            const Adc_Sar_Ip_CtuModeType eCtuMode);
#endif /* FEATURE_ADC_HAS_CTU */

#if (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE)
#if (FEATURE_ADC_HAS_INJ_EXT_TRIGGER || FEATURE_ADC_HAS_EXT_TRIGGER)
/*!
 * @brief Configure external trigger
 *
 * This function configures the external trigger.
 *
 * @param [in] u32Instance - ADC instance number
 * @param [in] eTriggerEdge - selected external trigger type
 * @param [in] eTrggerSrc - selects normal, auxiliary normal or injected trigger
 * @return void
 */
void Adc_Sar_Ip_SetExternalTrigger(const uint32 u32Instance,
                                   const Adc_Sar_Ip_ExtTriggerEdgeType eTriggerEdge,
                                   const Adc_Sar_Ip_ExtTriggerSourceType eTrggerSrc);
#endif /* (FEATURE_ADC_HAS_INJ_EXT_TRIGGER || FEATURE_ADC_HAS_EXT_TRIGGER) */
#endif /* (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE) */

#if FEATURE_ADC_HAS_TEMPSENSE_CHN
#if (ADC_SAR_IP_TEMPSENSE_ENABLED == STD_ON)
/*!
 * @brief Calculates the temperature on chip from the provided parameter.
 *
 * This function calculate the temperature on chip from the provided parameter
 * Note: u16AdcVref and u16TempSenseVsupply parameters must be in fixed point format
 * (1 bit for the sign, 11 bits for the integer part and 4 bits for the decimal part)
 *
 * @param [in] u32AdcInstance - Adc instance number
 * @param [in] u32TempInstance - TempSense instance number
 * @param [in] u16TempSenseAdcConvData - data measured on the ADC internal channel
 *             corresponding to TempSense, with 12 bit resolution
 * @return uint16: The temperature on chip in degrees C, expressed in fixed point format
 */
uint16 Adc_Sar_Ip_TempSenseCalculateTemp(const uint32 u32AdcInstance,
                                         const uint32 u32TempInstance,
                                         const uint16 u16TempSenseAdcConvData);

/*!
 * @brief Get the temperature on chip directly.
 *
 * This function starts a normal software conversion on tempsense channel with One-shot mode
 * and calculates the temperature on chip from the data conversion. At the end, tempsense
 * channel will be disabled. The previous initialized configuration may be affected by
 * calling this function
 * Note: u16AdcVref and u16TempSenseVsupply parameters must be in fixed point format
 * (1 bit for the sign, 11 bits for the integer part and 4 bits for the decimal part).
 * The function is synchronous: waits until the ADC conversion completes or timeout occurs
 *
 * @param [in] u32AdcInstance - Adc instance number
 * @param [in] u32TempInstance - TempSense instance number
 * @param [out] pTempSenseVal - The temperature on chip in degrees C, expressed in fixed point format
 * @return status:
 *  - ADC_SAR_IP_STATUS_SUCCESS: Get temperature successfully
 *  - ADC_SAR_IP_STATUS_TIMEOUT: Adc conversion did not complete
 */
Adc_Sar_Ip_StatusType Adc_Sar_Ip_TempSenseGetTemp(const uint32 u32AdcInstance,
                                                  const uint32 u32TempInstance,
                                                  uint16 * const pTempSenseVal);

/*!
 * @brief Enables the temperature sensor
 *
 * This function enables the temperature sensor.
 *
 * @param [in] u32Instance - TempSense instance number
 * @return void
 */
void Adc_Sar_Ip_TempSenseEnable(const uint32 u32Instance);

/*!
 * @brief Disables the temperature sensor
 *
 * This function disables the temperature sensor.
 *
 * @param [in] u32Instance - TempSense instance number
 * @return void
 */
void Adc_Sar_Ip_TempSenseDisable(const uint32 u32Instance);
#endif /* (ADC_SAR_IP_TEMPSENSE_ENABLED == STD_ON) */
#endif /* FEATURE_ADC_HAS_TEMPSENSE_CHN */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_H */
