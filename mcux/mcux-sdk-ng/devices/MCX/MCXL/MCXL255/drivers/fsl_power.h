/*
 * Copyright 2025 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_POWER_H
#define _FSL_POWER_H

#include "fsl_common.h"

#include "fsl_pmu.h"

/*!
 * @addtogroup power
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief power driver version 2.2.0. */
#define FSL_POWER_DRIVER_VERSION (MAKE_VERSION(2, 2, 0))
/*@}*/

#if __CORTEX_M == 33U
#define POWER_SHARED_RAM_BASE_ADDR (0xA1000000UL)
#elif __CORTEX_M == 0U
#define POWER_SHARED_RAM_BASE_ADDR (0x0UL)
#endif /* __CORTEX_M == 33U */

#ifndef POWER_MU_TRANSFER_TIMEOUT
#ifdef CONFIG_POWER_MU_TRANSFER_TIMEOUT
#define POWER_MU_TRANSFER_TIMEOUT CONFIG_POWER_MU_TRANSFER_TIMEOUT
#else
#define POWER_MU_TRANSFER_TIMEOUT 0U
#endif /* CONFIG_POWER_MU_TRANSFER_TIMEOUT */
#endif /* POWER_MU_TRANSFER_TIMEOUT */

#ifndef POWER_CONTEXT_SAVING_DPD2_TO_DPD1_SYNC_TIMEOUT
#ifdef CONFIG_POWER_CONTEXT_SAVING_DPD2_TO_DPD1_SYNC_TIMEOUT
#define POWER_CONTEXT_SAVING_DPD2_TO_DPD1_SYNC_TIMEOUT CONFIG_POWER_CONTEXT_SAVING_DPD2_TO_DPD1_SYNC_TIMEOUT
#else
#define POWER_CONTEXT_SAVING_DPD2_TO_DPD1_SYNC_TIMEOUT 0U
#endif /* CONFIG_POWER_CONTEXT_SAVING_DPD2_TO_DPD1_SYNC_TIMEOUT */
#endif /* POWER_CONTEXT_SAVING_DPD2_TO_DPD1_SYNC_TIMEOUT */

enum
{
    kStatus_POWER_MuTransferError   = MAKE_STATUS(kStatusGroup_POWER, 0), /*!< Failed due to MU transfer error. */
    kStatus_POWER_RequestNotAllowed = MAKE_STATUS(kStatusGroup_POWER, 1), /*!< Request not allowed by the other core. */
    kStatus_Power_HandleDuplicated = MAKE_STATUS(kStatusGroup_POWER, 2), /*!< Shared handle has already been created. */
    kStatus_Power_NotInTargetMode  = MAKE_STATUS(kStatusGroup_POWER, 3), /*!< Not in the target low-power mode. */
    kStatus_Power_NackWithMultiReasons =
        MAKE_STATUS(kStatusGroup_POWER, 4),                              /*!< NACK received with multiple reasons. */
    kStatus_Power_SyncFailed = MAKE_STATUS(kStatusGroup_POWER, 5),       /*!< Failed to synchronize the two cores. */
    kStatus_Power_CM0PNotWFI = MAKE_STATUS(kStatusGroup_POWER, 6),       /*!< CM0P did not execute WFI after approval
                                                                           to enter the requested low-power mode. */
    kStatus_Power_WakeupFromDPD1    = MAKE_STATUS(kStatusGroup_POWER, 7), /*!< Woke up from DPD1 successfully. */
    kStatus_Power_WakeupFromDPD2    = MAKE_STATUS(kStatusGroup_POWER, 8), /*!< Woke up from DPD2 successfully. */
    kStatus_Power_DualCoreNotSynced = MAKE_STATUS(kStatusGroup_POWER, 9), /*!< The two cores are not synchronized. */
};

/*!
 * @brief The enumeration of low power modes.
 */
typedef enum _power_low_power_mode
{
    kPower_Sleep          = 0U, /*!< Sleep Mode. */
    kPower_DeepSleep      = 1U, /*!< Deep Sleep Mode. */
    kPower_PowerDown1     = 2U, /*!< Power Down 1 mode. */
    kPower_PowerDown2     = 3U, /*!< Power Down 2 mode.*/
    kPower_DeepPowerDown1 = 4U, /*!< Deep Power Down 1 mode. */
    kPower_DeepPowerDown2 = 5U, /*!< Deep Power Down 2 mode. */
    kPower_DeepPowerDown3 = 6U, /*!< Deep Power Down 3 mode. */
    kPower_ShutDown       = 7,  /*!< ShutDown Mode */
    kPower_Active         = 8U, /*!< Active Mode. */
} power_low_power_mode_t;

typedef bool (*power_user_callback_t)(power_low_power_mode_t targetPowerMode, void *ptrPowerConfig, void *userData);

/*!
 * @brief Encodes a wakeup source into a 32-bit code.
 *
 * @note Bit field layout:
 * - bits [7:0]   : AON control-bit index.
 * - bits [23:20] : External pin edge (1 = rising, 2 = falling, 3 = both edges).
 * - bits [27:24] : Wakeup domain (0 = Main only, 1 = AON only, 2 = both Main and AON).
 *   In some low-power modes (e.g. PD2), only the AON domain can be woken.
 */
#define POWER_ENCODE_WS(wakeupDomain, pinEdge, aonIndex)                                        \
    (uint32_t)(((uint32_t)(aonIndex) & 0xFFUL) | (((uint32_t)(pinEdge) << 20UL) & 0xF00000UL) | \
               (((uint32_t)(wakeupDomain) << 24UL) & (0xF000000UL)))

#define POWER_DECODE_WS(wsCode)                     \
    aonIndex     = (wsCode) & 0xFFUL;               \
    pinEdge      = ((wsCode) & 0xF00000UL) >> 20UL; \
    wakeupDomain = ((wsCode) & 0xF000000UL) >> 24UL

/*!
 * @brief The enumeration of wakeup sources for different low power modes.
 *
 */
typedef enum _power_wakeup_source
{
    kPower_WS_NONE = 0xFFFFFFFFUL,

    kPower_WS_Main_RtcAlarm0 = POWER_ENCODE_WS(0U, 0U, 0U), /*!< RTC Alarm0 as wakeup source, only wakeup Main Domain */
    kPower_WS_Aon_RtcAlarm0  = POWER_ENCODE_WS(1U, 0U, 0U), /*!< RTC Alarm0 as wakeup source, only wakeup AON Domain */
    kPower_WS_Both_RtcAlarm0 = POWER_ENCODE_WS(2U, 0U, 0U), /*!< RTC Alarm0 as wakeup source,
                                                          wakeup both Main and AON Domains */

    kPower_WS_Main_RtcAlarm1 = POWER_ENCODE_WS(0U, 0U, 1U), /*!< RTC Alarm1 as wakeup source, only wakeup Main Domain */
    kPower_WS_Aon_RtcAlarm1  = POWER_ENCODE_WS(1U, 0U, 1U), /*!< RTC Alarm1 as wakeup source, only wakeup AON Domain */
    kPower_WS_Both_RtcAlarm1 = POWER_ENCODE_WS(2U, 0U, 1U), /*!< RTC Alarm1 as wakeup source,
                                                            wakeup both Main and AON Domains */

    kPower_WS_Main_QTimerIrq = POWER_ENCODE_WS(0U, 0U, 2U), /*!< QTimer IRQ as wakeup source, only wakeup Main Domain */
    kPower_WS_Aon_QTimerIrq  = POWER_ENCODE_WS(1U, 0U, 2U), /*!< QTimer IRQ as wakeup source, only wakeup AON Domain */
    kPower_WS_Both_QTimerIrq = POWER_ENCODE_WS(2U, 0U, 2U), /*!< QTimer IRQ as wakeup source,
                                                            wakeup both Main and AON Domains */

    kPower_WS_Main_RtcWDT = POWER_ENCODE_WS(0U, 0U, 3U), /*!< RTC watch dog as wakeup source, only wakeup Main Domain */
    kPower_WS_Aon_RtcWDT  = POWER_ENCODE_WS(1U, 0U, 3U), /*!< RTC watch dog as wakeup source, only wakeup AON Domain */
    kPower_WS_Both_RtcWDT = POWER_ENCODE_WS(2U, 0U, 3U), /*!< RTC watch dog as wakeup source,
                                                         wakeup both Main and AON Domains */

    kPower_WS_Main_RtcXtalFail = POWER_ENCODE_WS(0U, 0U, 4U),         /*!< RTC XTAL fail as wakeup source,
                                                                    only wakeup Main Domain */
    kPower_WS_Aon_RtcXtalFail = POWER_ENCODE_WS(1U, 0U, 4U),          /*!< RTC XTAL fail as wakeup source,
                                                                     only wakeup AON Domain */
    kPower_WS_Both_RtcXtalFail = POWER_ENCODE_WS(2U, 0U, 4U),         /*!< RTC XTAL fail as wakeup source,
                                                                    wakeup both Main and AON Domains */

    kPower_WS_Main_ExternalINTFallEdge = POWER_ENCODE_WS(0U, 2U, 5U), /*!< External INT falling edge as
                                                                    wakeup source, only wakeup Main Domain */
    kPower_WS_Aon_ExternalINTFallEdge = POWER_ENCODE_WS(1U, 2U, 5U),  /*!< External INT falling edge as
                                                                    wakeup  source, only wakeup AON Domain */
    kPower_WS_Both_ExternalINTFallEdge = POWER_ENCODE_WS(2U, 2U, 5U), /*!< External INT falling edge as
                                                                wakeup source, wakeup both Main and AON Domains */

    kPower_WS_Main_ExternalINTRiseEdge = POWER_ENCODE_WS(0U, 1U, 5U), /*!< External INT rising edge as
                                                                    wakeup source, only wakeup Main Domain */
    kPower_WS_Aon_ExternalINTRiseEdge = POWER_ENCODE_WS(1U, 1U, 5U),  /*!< External INT rising edge as
                                                                    wakeup  source, only wakeup AON Domain */
    kPower_WS_Both_ExternalINTRiseEdge = POWER_ENCODE_WS(2U, 1U, 5U), /*!< External INT rising edge as
                                                                wakeup source, wakeup both Main and AON Domains */

    kPower_WS_Main_SMMTimer = POWER_ENCODE_WS(0U, 0U, 6U),            /*!< Deep sleep counter as wakeup source,
                                                                          only wakeup Main Domain */
    kPower_WS_Aon_SMMTimer = POWER_ENCODE_WS(1U, 0U, 6U),             /*!< Deep sleep counter as wakeup source, only
                                                                          wakeup AON Domain */
    kPower_WS_Both_SMMTimer = POWER_ENCODE_WS(2U, 0U, 6U),            /*!< Deep sleep counter as wakeup source,
                                                                          wakeup both Main and AON Domains */

    kPower_WS_Main_Comparator = POWER_ENCODE_WS(0U, 0U, 7U),          /*!< Voltage comparator as wakeup source,
                                                                     only wakeup Main Domain */
    kPower_WS_Aon_Comparator = POWER_ENCODE_WS(1U, 0U, 7U),           /*!< Voltage comparator as wakeup source,
                                                                      only  wakeup AON Domain */
    kPower_WS_Both_Comparator = POWER_ENCODE_WS(2U, 0U, 7U),          /*!< Voltage comparator as wakeup source,
                                                                     wakeup both Main and AON Domains */

    kPower_WS_Main_AonHsGpioWakeup0 = POWER_ENCODE_WS(0U, 0U, 8U),    /*!< HS_GPIO wakeup0 as wakeup
                                                                        source, only wakeup Main Domain */
    kPower_WS_Aon_AonHsGpioWakeup0 = POWER_ENCODE_WS(1U, 0U, 8U),     /*!< HS_GPIO wakeup0 as wakeup source,
                                                                        only wakeup AON Domain */
    kPower_WS_Both_AonHsGpioWakeup0 = POWER_ENCODE_WS(2U, 0U, 8U),    /*!< HS_GPIO wakeup0 as wakeup
                                                                        source, wakeup both Main and AON Domains */

    kPower_WS_Main_Lpuart0 = POWER_ENCODE_WS(0U, 0U, 9U),             /*!< LPUART0 Interrupt as wakeup source, only
                                                                           wakeup Main Domain */
    kPower_WS_Aon_Lpuart0 = POWER_ENCODE_WS(1U, 0U, 9U),              /*!< LPUART0 Interrupt as wakeup source, only
                                                                           wakeup AON Domain */
    kPower_WS_Both_Lpuart0 = POWER_ENCODE_WS(2U, 0U, 9U),             /*!< LPUART0 Interrupt as wakeup source,
                                                                           wakeup both Main and AON Domains */

    kPower_WS_Main_AdvcOrACMP = POWER_ENCODE_WS(0U, 0U, 10U),         /*!< ADVC or ACMP as wakeup source, only
                                                                        wakeup Main Domain */
    kPower_WS_Aon_AdvcOrACMP = POWER_ENCODE_WS(1U, 0U, 10U),          /*!< ADVC or ACMP as wakeup source, only
                                                                         wakeup AON Domain */
    kPower_WS_Both_AdvcOrACMP = POWER_ENCODE_WS(2U, 0U, 10U),         /*!< ADVC or ACMP as wakeup source,
                                                                        wakeup both Main and AON Domains */

    kPower_WS_Main_Lpi2cInt = POWER_ENCODE_WS(0U, 0U, 11U),           /*!< AON Lpi2c interrupt as wakeup source,
                                                                          only wakeup Main Domain */
    kPower_WS_Aon_Lpi2cInt = POWER_ENCODE_WS(1U, 0U, 11U),            /*!< AON Lpi2c interrupt as wakeup source,
                                                                          only wakeup AON Domain */
    kPower_WS_Both_Lpi2cInt = POWER_ENCODE_WS(2U, 0U, 11U),           /*!< AON Lpi2c interrupt as wakeup source,
                                                                      wakeup both Main and AON Domains */

    kPower_WS_Main_AdcInt = POWER_ENCODE_WS(0U, 0U, 12U),             /*!< ADC interrupt as wakeup source, only
                                                                        wakeup Main Domain */
    kPower_WS_Aon_AdcInt = POWER_ENCODE_WS(1U, 0U, 12U),              /*!< ADC interrupt as wakeup source, only
                                                                        wakeup AON Domain */
    kPower_WS_Both_AdcInt = POWER_ENCODE_WS(2U, 0U, 12U),             /*!< ADC interrupt as wakeup source,
                                                                           wakeup both Main and AON Domains */

    kPower_WS_Main_LptmrInt = POWER_ENCODE_WS(0U, 0U, 13U),           /*!< LPTMR interrupt as wakeup source, only
                                                                         wakeup Main Domain */
    kPower_WS_Aon_LptmrInt = POWER_ENCODE_WS(1U, 0U, 13U),            /*!< LPTMR interrupt as wakeup source, only
                                                                           wakeup AON Domain */
    kPower_WS_Both_LptmrInt = POWER_ENCODE_WS(2U, 0U, 13U),           /*!< LPTMR interrupt as wakeup source,
                                                                          wakeup both Main and AON Domains */

    kPower_WS_Main_TamperDetect = POWER_ENCODE_WS(0U, 0U, 14U),       /*!< Tamper detect as wakeup source,
                                                                          only wakeup Main Domain */
    kPower_WS_Aon_TamperDetect = POWER_ENCODE_WS(1U, 0U, 14U),        /*!< Tamper detect as wakeup source, only
                                                                           wakeup AON Domain */
    kPower_WS_Both_TamperDetect = POWER_ENCODE_WS(2U, 0U, 14U),       /*!< Tamper detect as wakeup source,
                                                                          wakeup both Main and AON Domains */

    kPower_WS_Main_LcdInt = POWER_ENCODE_WS(0U, 0U, 15U),             /*!< LCD interrupt as wakeup source, only
                                                                        wakeup Main Domain */
    kPower_WS_Aon_LcdInt = POWER_ENCODE_WS(1U, 0U, 15U),              /*!< LCD interrupt as wakeup source, only
                                                                            wakeup AON Domain */
    kPower_WS_Both_LcdInt = POWER_ENCODE_WS(2U, 0U, 15U),             /*!< LCD interrupt as wakeup source,
                                                                        wakeup both Main and AON Domains */
} power_wakeup_source_t;

/*!
 * @brief
 * @anchor power_main_domain_sram_array_t
 */
enum _power_main_domain_sram_array
{
    kPower_MainDomainNoneRams  = 0UL,
    kPower_MainDomainRamX0     = 1UL << 0UL, /*!< Main Domain RAM X0, bitmask representation for power control */
    kPower_MainDomainRamX1     = 1UL << 1UL, /*!< Main Domain RAM X1, bitmask representation for power control */
    kPower_MainDomainRamA0     = 1UL << 2UL, /*!< Main Domain RAM A0, bitmask representation for power control */
    kPower_MainDomainRamA1     = 1UL << 3UL, /*!< Main Domain RAM A1, bitmask representation for power control */
    kPower_MainDomainRamA2     = 1UL << 4UL, /*!< Main Domain RAM A2, bitmask representation for power control */
    kPower_MainDomainRamA3     = 1UL << 5UL, /*!< Main Domain RAM A3, bitmask representation for power control */
    kPower_MainDomainRamB0     = 1UL << 6UL, /*!< Main Domain RAM B0, bitmask representation for power control */
    kPower_MainDomainRamB1     = 1UL << 7UL, /*!< Main Domain RAM B1, bitmask representation for power control */
    kPower_MainDomainRamB2ToB4 = 1UL << 8UL, /*!< Main Domain RAM B2 to B4, bitmask representation for power control */
    kPower_MainDomainAllRams   = 0x1FFUL,    /*!< Represents all RAMs in the Main Domain, bitmask for power control */
};

/*!
 * @brief The enumeration of VDD_CORE_AON output voltage.
 */
typedef enum _power_vdd_core_aon_output_voltage
{
    kPower_VddCoreAon_820mV       = 0x14U, /*!< The output voltage of VDD_CORE_AON is about 820mV. */
    kPower_VddCoreAon_801mV       = 0x16U, /*!< The output voltage of VDD_CORE_AON is about 801mV. */
    kPower_VddCoreAon_782mV       = 0x18U, /*!< The output voltage of VDD_CORE_AON is about 782mV. */
    kPower_VddCoreAon_763mV       = 0x1AU, /*!< The output voltage of VDD_CORE_AON is about 763mV. */
    kPower_VddCoreAon_744mV       = 0x1CU, /*!< The output voltage of VDD_CORE_AON is about 744mV. */
    kPower_VddCoreAon_725mV       = 0x1EU, /*!< The output voltage of VDD_CORE_AON is about 725mV. */
    kPower_VddCoreAon_706mV       = 0x20U, /*!< The output voltage of VDD_CORE_AON is about 706mV. */
    kPower_VddCoreAon_687mV       = 0x22U, /*!< The output voltage of VDD_CORE_AON is about 687mV. */
    kPower_VddCoreAon_668mV       = 0x24U, /*!< The output voltage of VDD_CORE_AON is about 668mV. */
    kPower_VddCoreAon_649mV       = 0x26U, /*!< The output voltage of VDD_CORE_AON is about 649mV. */
    kPower_VddCoreAon_630mV       = 0x28U, /*!< The output voltage of VDD_CORE_AON is about 630mV. */
    kPower_VddCoreAon_611mV       = 0x2AU, /*!< The output voltage of VDD_CORE_AON is about 611mV. */
    kPower_VddCoreAon_592mV       = 0x2CU, /*!< The output voltage of VDD_CORE_AON is about 592mV. */
    kPower_VddCoreAon_AdvcControl = 0xFFU, /*!< The output voltage of VDD_CORE_AON is controlled by ADVC. */
} power_vdd_core_output_voltage_t;

/*!
 * @brief
 * @anchor power_aon_domain_sram_array_t
 */
enum _power_aon_domain_sram_array
{
    kPower_AonDomainNoneRams       = 0UL,        /*!< No AON Domain RAMs. */
    kPower_AonDomainRam1stHalf16kB = 1UL << 0UL, /*!< First half (16kB) of AON Domain RAM, bitmask for power control */
    kPower_AonDomainRam2nd8kB      = 1UL << 1UL, /*!< Second 8kB of AON Domain RAM, bitmask for power control */
    kPower_AonDomainRamLower8kB    = 1UL << 2UL, /*!< Lower 8kB of AON Domain RAM, bitmask for power control */
    kPower_AonDomainAllRams        = 0x7UL, /*!< Represents all RAMs in the AON Domain, bitmask for power control */
};

/*!
 * @brief Enumeration of power MU message directions.
 */
typedef enum _power_mu_message_direction
{
    kPower_MsgDirMainToAon = 0U, /*!< Message direction from Main to AON domain */
    kPower_MsgDirAonToMain = 1U, /*!< Message direction from AON to Main domain */
} power_mu_message_direction_t;

/*!
 * @brief Enumeration of power MU message types.
 */
typedef enum _power_mu_message_type
{
    kPower_MsgTypeRequest = 0U, /*!< Message type is a request */
    kPower_MsgTypeACK     = 1U, /*!< Message type is response with ACKnowledgment */
    kPower_MsgTypeNACK    = 2U, /*!< Message type is response with Negative ACKnowledgment */
    kPower_MsgTypeSync    = 3U, /*!< Message type is to sync dual cores. */
} power_mu_message_type_t;

/*!
 * @brief The reason of NACK response.
 */
typedef enum _power_mu_nack_reason
{
    kPower_MsgNACK_ChannelMisMatch      = 1U << 0U, /*!< NACK response due to channel mismatch. */
    kPower_MsgNACK_TargetModeNotAllowed = 1U << 1U, /*!< NACK response due to target mode not allowed.. */
    kPower_MsgNACK_WrongMsgReceived     = 1U << 2U, /*!< NACK response due to wrong message. */
} power_mu_nack_reason_t;

/*!
 * @brief Configuration structure for deep sleep mode.
 */
typedef struct _power_ds_config
{
} power_ds_config_t;

/*!
 * @brief Configuration structure for power down 1 mode.
 */
typedef struct _power_pd1_config
{
    power_wakeup_source_t mainWakeupSource; /*!< Specify the wakeup source to main domain. If the selected wakeup
                                            source is not already enabled, it will be enabled before entering PD1 mode.
                                            Setting it to #kPower_WS_NONE indicates that this structure does not
                                            control any wakeup source. Pre-enabled wakeup sources are not affected.
                                             Wakeup sources can also be enabled manually by
                                             invoking Power_EnableWakeupSource().  */
    uint32_t mainRamArraysToRetain : 16U;   /*!< Bitmask representing the main domain RAM
                                                  arrays to retain during power down */
    uint32_t disableBandgap : 1U;           /*!< Flag to indicate whether to disable the bandgap during power down */
    uint32_t enableIVSMode : 1U;            /*!< Enable/disable IVS mode for the Main domain SRAM retention. */
} power_pd1_config_t;

/*!
 * @brief Configuration structure for power down 2 mode.
 */
typedef struct _power_pd2_config
{
    power_wakeup_source_t mainWakeupSource; /* Specify the wakeup source to main domain. If the selected wakeup
                                            source is not already enabled, it will be enabled before entering PD2 mode.
                                            Setting it to #kPower_WS_NONE indicates that this structure does not
                                            control any wakeup source. Pre-enabled wakeup sources are not affected.
                                             Wakeup sources can also be enabled manually by
                                             invoking Power_EnableWakeupSource().. */
    power_wakeup_source_t aonWakeupSource;  /* Specify the wakeup source to aon domain. If the selected wakeup
                                            source is not already enabled, it will be enabled before entering PD2 mode.
                                            Setting it to #kPower_WS_NONE indicates that this structure does not
                                            control any wakeup source. Pre-enabled wakeup sources are not affected.
                                             Wakeup sources can also be enabled manually by
                                             invoking Power_EnableWakeupSource(). */
    uint32_t mainRamArraysToRetain : 16U;   /*!< Bitmask representing the main domain RAM arrays
                                              to retain during DPD2 mode */
    uint32_t aonRamArraysToRetain : 16U;    /*!< Bitmask representing the AON domain RAM arrays
                                              to retain during DPD2 mode */
    uint32_t enableIVSMode : 1U;            /*!< Enable/disable IVS mode for the Main domain SRAM retention. */
    uint32_t disableBandgap : 1U;           /*!< Flag to indicate whether to disable the bandgap during DPD2 mode */
    uint32_t disableFRO10M : 1U; /*!< Flag to indicate whether to disable the FRO10M clock during DPD2 mode */
    power_vdd_core_output_voltage_t vddCoreAonVoltage : 8U; /*!< Specify output voltage of VDD_CORE_AON */
} power_pd2_config_t;

/*!
 * @brief Enumeration of follow power transition.
 */
typedef enum _power_dpd1_transition
{
    kPower_Dpd1ToActive = 0U,      /*!< Transition from DPD1 to Active mode */
    kPower_Dpd1ToDpd2WakeToDpd1,   /*!< Transition from DPD1 to DPD2 wakeup to DPD1 mode */
    kPower_Dpd1ToDpd2WakeToActive, /*!< Transition from DPD1 to DPD2 wakeup to Active mode */
} power_dpd1_transition_t;

/*!
 * @brief Configuration structure for deep power down mode 1.
 *
 */
typedef struct _power_dpd1_config
{
    power_wakeup_source_t mainWakeupSource; /* Specify the wakeup source to main domain. If the selected wakeup
                                           source is not already enabled, it will be enabled before entering DPD1 mode.
                                           Setting it to #kPower_WS_NONE indicates that this structure does not
                                           control any wakeup source. Pre-enabled wakeup sources are not affected.
                                            Wakeup sources can also be enabled manually by
                                            invoking Power_EnableWakeupSource(). */
    uint32_t
        mainRamArraysToRetain : 16U; /*!< Bitmask representing the main domain RAM arrays to retain during power down */
    uint32_t disableBandgap : 1U;    /*!< Flag to indicate whether to disable the bandgap during power down */
    uint32_t enableIVSMode : 1U;     /*!< Enable/disable IVS mode for the Main domain SRAM retention. */
    power_dpd1_transition_t
             nextTrans : 2U;         /*!< Next transition after DPD1 mode, refer to @ref power_dpd1_transition_t */
    uint32_t saveContext : 1U;       /*!< True to save basic register context into stack, false to do not save. */
    uint32_t disableFRO10M : 1U;     /*!< Flag to indicate whether to disable the FRO10M clock during DPD1 mode */
    uint32_t reserved : 2U;          /*!< Reserved for using. */
    power_vdd_core_output_voltage_t vddCoreAonVoltage : 8U; /*!< Specify output voltage of VDD_CORE_AON */
} power_dpd1_config_t;

/*!
 * @brief Configuration structure for deep power down mode 2.
 */
typedef struct _power_dpd2_config
{
    power_wakeup_source_t mainWakeupSource; /*!< Specify the wakeup source to main domain. If the selected wakeup
                                            source is not already enabled, it will be enabled before entering DPD2 mode.
                                            Setting it to #kPower_WS_NONE indicates that this structure does not
                                            control any wakeup source. Pre-enabled wakeup sources are not affected.
                                             Wakeup sources can also be enabled manually by
                                             invoking Power_EnableWakeupSource(). */
    power_wakeup_source_t aonWakeupSource;  /*!< Specify the wakeup source to aon domain. If the selected wakeup
                                            source is not already enabled, it will be enabled before entering DPD2 mode.
                                            Setting it to #kPower_WS_NONE indicates that this structure does not
                                            control any wakeup source. Pre-enabled wakeup sources are not affected.
                                             Wakeup sources can also be enabled manually by
                                             invoking Power_EnableWakeupSource(). */
    uint32_t
        mainRamArraysToRetain : 16U; /*!< Bitmask representing the main domain RAM arrays to retain during DPD2 mode */
    uint32_t
        aonRamArraysToRetain : 16U;  /*!< Bitmask representing the AON domain RAM arrays to retain during DPD2 mode */
    uint32_t enableIVSMode : 1U;     /*!< Enable/disable IVS mode for the Main domain SRAM retention. */
    uint32_t disableBandgap : 1U;    /*!< Flag to indicate whether to disable the bandgap during DPD2 mode */
    uint32_t switchToX32K : 1U;      /*!< Flag to indicate whether to switch to X32K clock source during DPD2 mode */
    uint32_t disableFRO10M : 1U;     /*!< Flag to indicate whether to disable the FRO10M clock during DPD2 mode */
    uint32_t wakeToDpd1 : 1U;        /*!< Flag to indicate whether to wake up to DPD1 mode after DPD2 mode */
    uint32_t saveContext : 1U;       /*!< True to save basic register context into stack, false to do not save. */
    uint32_t disableFRO2M : 1U;      /*!< True to disable FRO2M, false to do not disable. */
    uint32_t reserved : 1U;          /*!< Reserved for using. */
    power_vdd_core_output_voltage_t
        dpd2VddCoreAonVoltage : 8U;  /*!< Specify output voltage of VDD_CORE AON in DPD2 mode,
                                     in type of @ref power_vdd_core_output_voltage_t. */
} power_dpd2_config_t;

/*!
 * @brief Configuration structure for deep power down mode 3.
 */
typedef struct _power_dpd3_config
{
    power_wakeup_source_t wakeupSource; /*!< Specify the wakeup source to main and aon domain. If the selected wakeup
                                            source is not already enabled, it will be enabled before entering DPD3 mode.
                                            Setting it to #kPower_WS_NONE indicates that this structure does not
                                            control any wakeup source. Pre-enabled wakeup sources are not affected.
                                             Wakeup sources can also be enabled manually by
                                             invoking Power_EnableWakeupSource(). */
} power_dpd3_config_t;

/*!
 * @brief Configuration structure for shut down.
 */
typedef struct _power_sd_config
{
    power_wakeup_source_t wakeupSource; /*!< Specify the wakeup source to main and aon domain. If the selected wakeup
                                            source is not already enabled, it will be enabled before entering SD mode.
                                            Setting it to #kPower_WS_NONE indicates that this structure does not
                                            control any wakeup source. Pre-enabled wakeup sources are not affected.
                                             Wakeup sources can also be enabled manually by
                                             invoking Power_EnableWakeupSource().  */
    pmu_fro16k_output_freq_t fro16KOutputFreq; /*!< Specify the output frequency of FRO16K */
} power_sd_config_t;

/*!
 * @brief The structure of dumped wakeup source information.
 */
typedef struct _power_wakeup_source_info
{
    uint32_t aonWakeupSourceMask;  /*!< The mask of wakeup sources in AON domain. */
    uint32_t mainWakeupSourceMask; /*!< The mask of wakeup sources in Main domain. */
} power_wakeup_source_info_t;

/*!
 * @brief Structure to handle power management operations.
 */
typedef struct _power_handle
{
    uint32_t lpConfig[4U]; /*!< Buffer (4 x 32-bit words) for storing the most recent low-power configuration. */
    power_user_callback_t cm33Callback;                /*!< Callback function for CM33 core operations,
                                                             in type of @ref power_user_callback_t */
    void                 *cm33UserData;                /*!< User data pointer for CM33 core operations */
    power_user_callback_t cm0pCallback;                /*!< Callback function for CM0+ core operations,
                                                             in type of @ref power_user_callback_t */
    void                      *cm0pUserData;           /*!< User data pointer for CM0+ core operations */
    power_wakeup_source_info_t enabledWsInfo;          /*!< Used to record all enabled wakeup sources. */
    uint32_t                   muChannelId : 4U;       /*!< MU channel ID used for power communication. */
    power_low_power_mode_t     targetPowerMode : 4U;   /*!< Target low-power mode requested by this core. */
    power_low_power_mode_t     previousPowerMode : 4U; /*!< Previously entered low-power mode. */
    uint32_t                   dualCoreSynced : 1U;    /*!< Set when the two cores are synchronized. */
    uint32_t                   requestCM33Start : 1U;  /*!< CM0P-side flag requesting CM33 to run the entry sequence. */
    uint32_t                   cm0pWFI : 1U;           /*!< CM0P has executed WFI (used for PD2/DPD2/DPD3/SD). */
} power_handle_t;

/*!
 * @brief Inform the other core that it attempts to create a handle.
 */
typedef struct _power_drv_config
{
    uint32_t muChannelId : 4U; /*!< MU channel ID used by the power driver. */
    uint32_t noSyncCM0P : 1U;  /*!< If true, skip synchronizing with CM0P; if false, perform blocking sync. */
} power_drv_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Create the shared power handle.
 *
 * This function initializes the shared @ref power_handle_t in the shared RAM and, unless
 * @ref power_drv_config_t::noSyncCM0P is true, attempts to synchronize with the other core.
 *
 * @note Please invoke this function before using other APIs.
 *
 * @param[in] handle Pointer to @ref power_handle_t in **shared RAM**.
 * @param[in] config Pointer to @ref power_drv_config_t.
 *
 * @retval kStatus_Success                 Handle created (and cores synchronized if requested).
 * @retval kStatus_Power_HandleDuplicated  A shared handle has already been created by the peer.
 * @retval kStatus_POWER_MuTransferError   MU synchronization/transfer error.
 * @retval kStatus_Timeout                 Timed out while waiting for MU response (if timeout enabled).
 */
status_t Power_CreateHandle(power_handle_t *handle, const power_drv_config_t *config);

/*!
 * @brief Dump the current shared handle into a local buffer.
 *
 * @param[out] ptrDumpBuffer Pointer to a @ref power_handle_t to receive the copy.
 */
void Power_DumpHandleValue(power_handle_t *ptrDumpBuffer);

/*!
 * @brief Get the configuration of the latest requested low-power mode.
 *
 * @param[out] config Pointer to a buffer large enough to hold the configuration structure
 *                    that matches @ref Power_GetTargetLowPowerMode().
 *                    The actual type depends on the saved target mode (e.g. @ref power_pd2_config_t).
 */
void Power_GetPowerModeConfig(void *config);

/*!
 * @brief Get the offset of shared handle in shared RAM.
 *
 * @return Offset of shared handle in shared RAM, in bytes.
 */
uint32_t Power_GetHandleOffset(void);

/*!
 * @brief Restore the shared handle from offset in shared RAM.
 *
 * @param[in] offset Offset of shared handle in shared RAM, in bytes.
 */
void Power_RestoreHandleOffset(uint32_t offset);

/*!
 * @brief Synchronizes the two cores in a blocking manner.
 *
 * @retval kStatus_Success               Synchronized successfully.
 * @retval kStatus_Power_HandleDuplicated The peer reports a duplicated handle.
 * @retval kStatus_POWER_MuTransferError MU transfer error.
 * @retval kStatus_Timeout               Timed out while waiting for MU response (if timeout enabled).
 */
status_t Power_SyncDualCoreBlocking(void);

/*!
 * @name Wakeup Source Control Interfaces
 * @{
 */

/*!
 * @brief Enable input wakeup source, once enabled it will be effective until disabled.
 *
 * @details The enabled wakeup sources are recorded, and set to register before entering low power modes.
 *
 * @note There are two ways to enable wakeup source: The first one is invoking Power_EnableWakeupSource(), the
 * way is used to enable more than one wakeup source; The second one is specify the wakeup source in configuration
 * of low power mode.
 *
 * @param[in] ws Specify the coded wakeup source, please refer to @ref power_wakeup_source_t for details.
 */
void Power_EnableWakeupSource(power_wakeup_source_t ws);

/*!
 * @brief Disable input wakeup source.
 *
 * @param[in] ws Specify the coded wakeup source, please refer to @ref power_wakeup_source_t for details.
 */
void Power_DisableWakeupSource(power_wakeup_source_t ws);

/*!
 * @brief Disable all enabled wakeup sources to both main domain and aon domain.
 */
void Power_DisableAllWakeupSources(void);

/*!
 * @brief Dump information of all configured wakeup sources, in type of @ref power_wakeup_source_info_t.
 *
 * @param[out] ptrWsInfo Pointer to the variable to store dumped wakeup source information.
 */
void Power_DumpEnabledWakeSource(power_wakeup_source_info_t *ptrWsInfo);

/*!
 * @brief Get latest mask of wakeup sources which cause the wakeup to main CPU.
 *
 * @param[out] ptrWakeupSourceMask Pointer to the variable to store mask of wakeup sources.
 */
void Power_GetWakeupSource(uint32_t *ptrWakeupSourceMask);

/*!
 * @brief Check whether the selected wakeup source is already enabled, if it is then disable it.
 *
 * @param ws Specify the wakeup source in type of @ref power_wakeup_source_t.
 */
void Power_CheckThenDisableWakeupSource(power_wakeup_source_t ws);

/*!
 * @brief Check whether the selected wakeup source is disabled, if it is then enable it.
 *
 * @param ws Specify the wakeup source in type of @ref power_wakeup_source_t.
 */
void Power_CheckThenEnableWakeupSource(power_wakeup_source_t ws);

/*!
 * @}
 */

/*!
 * @name Use callback Control Interfaces
 * @{
 */

/*!
 * @brief Register user callback.
 *
 * @param[in] callback Pointer to callback in type of @ref power_user_callback_t.
 * @param[in] userData Pointer to user data.
 */
void Power_RegisterUserCallback(power_user_callback_t callback, void *userData);

/*!
 * @brief Unregister user callback.
 */
void Power_UnRegisterUserCallback(void);

/*! @} */

/*!
 * @name Low Power Modes Control Interfaces
 * @{
 */

/*!
 * @brief Get the target low power mode of latest request.
 *
 * @return The target low power mode @ref power_low_power_mode_t of latest request.
 */
power_low_power_mode_t Power_GetTargetLowPowerMode(void);

/*!
 * @brief Get previous power mode.
 *
 * @return The previous power mode.
 */
power_low_power_mode_t Power_GetPreviousPowerMode(void);

/*!
 * @brief Reset previous power mode as active mode.
 */
void Power_ResetPreviousPowerMode(void);

/*!
 * @brief Update previous power mode as input low power mode.
 *
 * @param lpMode The low power mode to update, in type of @ref power_low_power_mode_t.
 */
void Power_UpdatePreviousPowerMode(power_low_power_mode_t lpMode);
/*!
 * @brief Get current power mode.
 *
 * @param[out] ptrCurLpMode Pointer to store current low power mode
 *
 * @retval kStatus_Success Successfully retrieved current low power mode.
 */
status_t Power_GetCurrentPowerMode(power_low_power_mode_t *ptrCurLpMode);

/*!
 * @brief Get the target low power mode.
 *
 * @return Requested low power mode, in type of @ref power_low_power_mode_t.
 */
power_low_power_mode_t Power_GetTargetPowerMode(void);

/*!
 * @brief Clear the target low power mode.
 */
void Power_ClearTargetPowerMode(void);

/*!
 * @brief Clear all low power settings.
 */
void Power_ClearLpPowerSettings(void);

/*!
 * @brief Enter selected low power mode.
 *
 * @param[in] lowpowerMode Indicate specific target low power mode.
 * @param[in] config Pointer to the matching configuration structure.
 *
 * @retval kStatus_Success                   Entered the target mode (or queued the sequence on peer core).
 * @retval kStatus_POWER_MuTransferError     MU transfer error.
 * @retval kStatus_POWER_RequestNotAllowed   Request rejected by the peer.
 * @retval kStatus_Power_DualCoreNotSynced   The two cores are not synchronized (for modes requiring sync).
 * @retval kStatus_Timeout                   Timed out while waiting for MU response (if timeout enabled).
 */
status_t Power_EnterLowPowerMode(power_low_power_mode_t lowpowerMode, void *config);

/*!
 * @brief Enter the sleep mode.
 *
 * This function is used to put the system into sleep mode.
 *
 * @retval kStatus_Success Successfully entered sleep mode.
 * @retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * @retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterSleep(void);

/*!
 * @brief Enter Deep Sleep mode.
 *
 * This function attempts to put the system into Deep Sleep mode with the provided configuration.
 *
 * @param[in] config Pointer to the Deep Sleep mode configuration.
 *
 * @retval kStatus_Success Successfully entered Deep Sleep mode.
 * @retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * @retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterDeepSleep(power_ds_config_t *config);

/*!
 * @brief Enter Power Down 1 mode.
 *
 * This function attempts to put the system into Power Down 1 mode with the provided configuration.
 *
 * @param[in] config Pointer to the Power Down 1 mode configuration.
 *
 * @retval kStatus_Success Successfully entered Power Down 1 mode.
 * @retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * @retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterPowerDown1(power_pd1_config_t *config);

/*!
 * @brief Enter Power Down 2 mode.
 *
 * This function attempts to put the system into Power Down 2 mode with the provided configuration.
 *
 * @param[in] config Pointer to the Power Down 2 mode configuration.
 *
 * @retval kStatus_Success Successfully entered Power Down 2 mode.
 * @retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * @retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterPowerDown2(power_pd2_config_t *config);

/*!
 * @brief Enter Deep Power Down 1 mode.
 *
 * This function attempts to put the system into Deep Power Down 1 mode with the provided configuration.
 *
 * @note If attempting to enable context saving feature, please ensure RAM blocks used by stack are retained.
 *
 * @param[in] config Pointer to the Deep Power Down 1 mode configuration.
 *
 * @retval kStatus_Success Successfully entered Deep Power Down 1 mode.
 * @retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * @retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterDeepPowerDown1(power_dpd1_config_t *config);

/*!
 * @brief Get the next transition after Deep Power Down 1 mode.
 *
 * @return Next transition after Deep Power Down 1 mode, in type of @ref power_dpd1_transition_t.
 */
power_dpd1_transition_t Power_GetDeepPowerDown1NextTransition(void);

/*!
 * @brief Enter Deep Power Down 2 mode.
 *
 * This function attempts to put the system into Deep Power Down 2 mode with the provided configuration.
 *
 * @note If attempting to enable context saving feature, please ensure RAM blocks used by stack are retained.
 *
 * @param[in] config Pointer to the Deep Power Down 2 mode configuration.
 *
 * @retval kStatus_Success                 Entered DPD2 (or completed the request sequence).
 * @retval kStatus_Power_WakeupFromDPD2    Returned from DPD2 with context restored (when context saving enabled).
 * @retval kStatus_POWER_MuTransferError   MU transfer error.
 * @retval kStatus_POWER_RequestNotAllowed Request rejected by the peer.
 * @retval kStatus_Power_DualCoreNotSynced Cores are not synchronized.
 * @retval kStatus_Timeout                 Timed out while waiting for MU response / cross-core sync.
 */
status_t Power_EnterDeepPowerDown2(power_dpd2_config_t *config);

/*!
 * @brief Enter Deep Power Down 3 mode.
 *
 * This function attempts to put the system into Deep Power Down 3 mode with the provided configuration.
 *
 * @param[in] config Pointer to the Deep Power Down 3 mode configuration.
 *
 * @retval kStatus_Success                 Entered DPD3 (or completed the request sequence).
 * @retval kStatus_POWER_MuTransferError   MU transfer error.
 * @retval kStatus_POWER_RequestNotAllowed Request rejected by the peer.
 * @retval kStatus_Power_DualCoreNotSynced Cores are not synchronized.
 * @retval kStatus_Timeout                 Timed out while waiting for MU response (if timeout enabled).
 */
status_t Power_EnterDeepPowerDown3(power_dpd3_config_t *config);

/*!
 * @brief Enter Shutdown mode.
 *
 * This function attempts to put the system into Shutdown mode with the provided configuration.
 *
 * @param[in] config Pointer to the Shutdown mode configuration.
 *
 * @retval kStatus_Success                 Entered Shutdown (or completed the request sequence).
 * @retval kStatus_POWER_MuTransferError   MU transfer error.
 * @retval kStatus_POWER_RequestNotAllowed Request rejected by the peer.
 * @retval kStatus_Power_DualCoreNotSynced Cores are not synchronized.
 * @retval kStatus_Timeout                 Timed out while waiting for MU response (if timeout enabled).
 */
status_t Power_EnterShutDown(power_sd_config_t *config);

/*!
 * @brief Save current context into stack.
 *      ---------    <-----High address
        |  D15  |       -----
        ---------           |
        |  D14  |           |
        ---------           |
        |  D13  |           |
        ---------           |
        |  D12  |           |
        ---------           |---- Only CM33
        |  D11  |           |
        ---------           |
        |  D10  |           |
        ---------           |
        |  D9   |           |
        ---------           |
        |  D8   |       -----
        ---------
        |  LR   |
        ---------
        |  R12  |
        ---------
        |  R11  |
        ---------
        |  R10  |
        ---------
        |  R9   |
        ---------
        |  R8   |
        ---------
        |  R7   |
        ---------
        |  R6   |
        ---------
        |  R5   |
        ---------
        |  R4   |
        ---------
        | handle|
        | value |
        ---------
        | handle|
        | addr  |
        ---------
        | ASPR  |
        ---------
        | PSR   |
        ---------
        |PRIMASK|
        ---------
        |CONTROL|
        ---------  <------ SP Address saved in backup register
 *
 * @note User can use this function to save context before entering low power modes which will reset system.
 * @note For CM33 project, LSB_BCKP1, LSB_BCKP2, MSB_BCKP2 are used.
 * @note For CM0P project, MSB_BCKP1 is used.
 *
 * @param handleAddr The address of handle.
 *
 * @retval 0 Return 0 before entering low power modes.
 * @retval 1 Return 1 after waking up from low power modes.
 */
uint32_t Power_PushContext(uint32_t handleAddr);

/*!
 * @brief Restore saved context from stack.
 *
 * @note User can use this function to restore context after waking up from low power modes which reset system.
 */
void Power_LowPowerBoot(void);

/*!
 * @}
 *
 */

/*! @name Power MU Transfer Callback
 *  @{
 */

/*!
 * @brief Get type of received MU message.
 *
 * @param message The received message.
 *
 * @return The type of MU message.
 */
power_mu_message_type_t Power_GetMuMessageType(uint32_t message);

/*!
 * @brief Get direction of received MU message.
 *
 * @param message The received message.
 *
 * @return The direction of MU message.
 */
power_mu_message_direction_t Power_GetMuMessageDir(uint32_t message);

/*!
 * @brief The callback when one core want to sync with another, that is when the message type is #kPower_MsgTypeSync.
 *
 * @param message Received message value.
 * @param channelId The channel which transfer the message.
 *
 * @retval kStatus_Power_SyncFailed Failed to sync between dual cores.
 * @retval kStatus_Success Sync dual cores successfully.
 */
status_t Power_MuSyncCallback(uint32_t message, uint32_t channelId);

/*!
 * @brief Interpret request message from requester.
 *
 * @param message The message which request from requester.
 *
 * @retval kStatus_POWER_MuTransferError Something wrong during transfer.
 * @retval kStatus_POWER_RequestNotAllowed Request is not allowed.
 * @retval kStatus_Success Interpret request message successfully.
 */
status_t Power_InterpretRequest(uint32_t message);

/*!
 * @brief Interpret a MU response message.
 *
 * @param[in] message The response message sent to the requester.
 *
 * @retval kStatus_Success                 The response has been interpreted successfully (ACK).
 * @retval kStatus_POWER_MuTransferError   Invalid message or MU error.
 * @retval kStatus_POWER_RequestNotAllowed NACK due to target mode not allowed.
 * @retval kStatus_Power_NackWithMultiReasons NACK with multiple reasons.
 */
status_t Power_InterpretResponse(uint32_t message);

/*!
 * @brief Callback function for handling power MU messages.
 *
 * @details This function is called when a power MU message is received. It processes the message
 * based on the given message content and the channel ID.
 *
 * @note This function integrate #Power_MuSyncCallback(), #Power_InterpretRequest(), and
 * #Power_InterpretResponse().
 *
 * @param[in] message The received power MU message.
 * @param[in] channelId The ID of the channel on which the message was received.
 *
 * @retval kStatus_Power_SyncFailed Failed to sync between dual cores.
 * @retval kStatus_POWER_MuTransferError Something wrong during transfer.
 * @retval kStatus_POWER_RequestNotAllowed Request is not allowed.
 * @retval kStatus_Success Interpret request/response message successfully.
 */
status_t Power_MuMessageCallback(uint32_t message, uint32_t channelId);
/*!
 * @}
 */

/*!
 * @}
 */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* __FSL_POWER_H */
