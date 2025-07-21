/*
 * Copyright 2025 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_POWER_H
#define _FSL_POWER_H

#include "fsl_common.h"

/*!
 * @addtogroup power
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief power driver version 2.0.0. */
#define FSL_POWER_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#if __CORTEX_M == 33U
#define POWER_SHARED_RAM_BASE_ADDR (0xA1000000UL)
#elif __CORTEX_M == 0U
#define POWER_SHARED_RAM_BASE_ADDR (0x0UL)
#endif /* __CORTEX_M == 33U */

enum
{
    kStatus_POWER_MuTransferError = MAKE_STATUS(kStatusGroup_POWER, 0),      /*!< Fail due to Mu transfer error. */
    kStatus_POWER_RequestNotAllowed = MAKE_STATUS(kStatusGroup_POWER, 1),    /*!< Request not allowed by another core. */
    kStatus_Power_HandleDuplicated = MAKE_STATUS(kStatusGroup_POWER, 2),     /*!< Handle already be created. */
    kStatus_Power_NotInTargetMode = MAKE_STATUS(kStatusGroup_POWER, 3),      /*!< Not in target low power mode. */
};

/*!
 * @brief The enumeration of low power modes.
 * 
 */
typedef enum _power_low_power_mode
{
    kPower_Sleep = 0U,              /*!< Sleep Mode. */
    kPower_DeepSleep = 1U,          /*!< Deep Sleep Mode. */
    kPower_PowerDown1 = 2U,         /*!< Power Down Mode 1. */
    kPower_PowerDown2 = 3U,         /*!< Power Down Mode 2.*/
    kPower_DeepPowerDown1 = 4U,     /*!< Deep Power Down Mode 1. */
    kPower_DeepPowerDown2 = 5U,     /*!< Deep Power Down Mode 2. */
    kPower_DeepPowerDown3 = 6U,     /*!< Deep Power Down Mode 3. */
    kPower_ShutDown = 7,            /*!< ShutDown Mode */
    kPower_Active = 8U,             /*!< Active Mode. */
} power_low_power_mode_t;

typedef bool (*power_user_callback_t)(power_low_power_mode_t targetPowerMode, void *ptrPowerConfig, void *userData);

/*!
 * @brief Encode wakeup source code.
 *
 * @note
 *    bit 7 - 0: aon control bit index;
 *    bit 15 - 8: wuu control bit index;
 *    bit 19 - 16: wuu event(0: interrupt, 1: DMA request, 2: trigger event);
 *    bit 23 - 20: external pin edge(1: rising edge, 2: falling edge, 3: any edge);
 *    bit 27 - 24: Wakeup domain(0: only Main, 1: only Aon, 2: Both Main and Aon), in some low power mode(such as PD2) 
 *                  it is possible only wakeup Aon Domain.
 *    bit 30: external pin or internal module(0: internal module, 1: external pin);
 *    bit 31: wakeup source in aon domain or cm33 domain(0: In AON domain, 1: In CM33 domain).
 *
 */
#define POWER_ENCODE_WS(cm33Ws, wuuExtPin, wakeupDomain, pinEdge, wuuEvent, wuuIndex, aonIndex)                           \
    ((((uint32_t)(cm33Ws) << 31UL) & (0x80000000UL)) | (((uint32_t)(wuuExtPin) << 30UL) & (0x40000000UL)) | \
     (((uint32_t)(pinEdge) << 20UL) & 0xF00000UL) | (((uint32_t)(wuuEvent) << 16UL) & 0xF0000UL) |          \
     (((uint32_t)(wuuIndex) << 8UL) & 0xFF00UL) | ((uint32_t)(aonIndex)&0xFFUL) | \
     (((uint32_t)(wakeupDomain) << 24UL) & (0xF000000UL)))

#define POWER_DECODE_WS(wsCode)                           \
    aonIndex    = (wsCode)&0xFFUL;                        \
    wuuIndex    = ((wsCode)&0xFF00UL) >> 8UL;             \
    wuuEvent    = ((wsCode)&0xF0000UL) >> 16UL;           \
    pinEdge     = ((wsCode)&0xF00000UL) >> 20UL;          \
    isWuuExtPin = (bool)(((wsCode)&0x40000000UL) != 0UL); \
    isCm33Ws    = (bool)(((wsCode)&0x80000000UL) != 0UL); \
    wakeupDomain = ((wsCode)&0xF000000UL) >> 24UL

#define POWER_DPD2_WS_BIT_MASK     (0xFFUL)
#define POWER_DPD3_WS_BIT_MASK     (0x37UL)
#define POWER_SHUTDOWN_WS_BIT_MASK (0x20UL)

/*!
 * @brief The enumeration of wakeup sources for different low power modes.
 *
 */
typedef enum _power_wakeup_source
{
    kPower_WS_Main_RtcAlarm0 = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 0U),   /*!< RTC Alarm0 as wakeup source, only
    wakeup Main Domain */
    kPower_WS_Aon_RtcAlarm0 = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 0U),    /*!< RTC Alarm0 as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_RtcAlarm0 = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 0U),  /*!< RTC Alarm0 as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_RtcAlarm1 = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 1U),   /*!< RTC Alarm1 as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_RtcAlarm1 = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 1U),    /*!< RTC Alarm1 as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_RtcAlarm1 = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 1U),  /*!< RTC Alarm1 as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_QTimerIrq = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 2U),   /*!< QTimer IRQ as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_QTimerIrq = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 2U),    /*!< QTimer IRQ as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_QTimerIrq = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 2U),  /*!< QTimer IRQ as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_RtcWDT = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 3U),      /*!< RTC watch dog as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_RtcWDT = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 3U),       /*!< RTC watch dog as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_RtcWDT = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 3U),     /*!< RTC watch dog as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_RtcXtalFail = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 4U), /*!< RTC XTAL fail as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_RtcXtalFail = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 4U),  /*!< RTC XTAL fail as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_RtcXtalFail = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 4U), /*!< RTC XTAL fail as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_ExternalINTFallEdge = POWER_ENCODE_WS(0U, 0U, 0U, 2U, 0U, 0U, 5U), /*!< External INT falling edge as wakeup
    source, only wakeup Main Domain */
    kPower_WS_Aon_ExternalINTFallEdge = POWER_ENCODE_WS(0U, 0U, 1U, 2U, 0U, 0U, 5U), /*!< External INT falling edge as wakeup
    source, only wakeup AON Domain */
    kPower_WS_Both_ExternalINTFallEdge = POWER_ENCODE_WS(0U, 0U, 2U, 2U, 0U, 0U, 5U), /*!< External INT falling edge as wakeup
    source, wakeup both Main and AON Domains */

    kPower_WS_Main_ExternalINTRiseEdge = POWER_ENCODE_WS(0U, 0U, 0U, 1U, 0U, 0U, 5U), /*!< External INT rising edge as wakeup
    source, only wakeup Main Domain */
    kPower_WS_Aon_ExternalINTRiseEdge = POWER_ENCODE_WS(0U, 0U, 1U, 1U, 0U, 0U, 5U), /*!< External INT rising edge as wakeup
    source, only wakeup AON Domain */
    kPower_WS_Both_ExternalINTRiseEdge = POWER_ENCODE_WS(0U, 0U, 2U, 1U, 0U, 0U, 5U), /*!< External INT rising edge as wakeup
    source, wakeup both Main and AON Domains */

    kPower_WS_Main_SMMTimer = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 6U),   /*!< Deep sleep counter as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_SMMTimer = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 6U),    /*!< Deep sleep counter as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_SMMTimer = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 6U),  /*!< Deep sleep counter as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_Comparator = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 7U),          /*!< Voltage comparator as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_Comparator = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 7U),           /*!< Voltage comparator as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_Comparator = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 7U),         /*!< Voltage comparator as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_AonHsGpioWakeup0 = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 8U),   /*!< HS_GPIO wakeup0 as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_AonHsGpioWakeup0 = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 8U),    /*!< HS_GPIO wakeup0 as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_AonHsGpioWakeup0 = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 8U),  /*!< HS_GPIO wakeup0 as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_Lpuart0 = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 9U), /*!< LPUART0 Interrupt as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_Lpuart0 = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 9U),  /*!< LPUART0 Interrupt as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_Lpuart0 = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 9U), /*!< LPUART0 Interrupt as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_AdvcOrACMP = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 10U),  /*!< ADVC or ACMP as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_AdvcOrACMP = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 10U),   /*!< ADVC or ACMP as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_AdvcOrACMP = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 10U),  /*!< ADVC or ACMP as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_Lpi2cInt = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 11U),    /*!< AON Lpi2c interrupt as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_Lpi2cInt = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 11U),     /*!< AON Lpi2c interrupt as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_Lpi2cInt = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 11U),    /*!< AON Lpi2c interrupt as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_AdcInt   = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 12U),    /*!< ADC interrupt as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_AdcInt   = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 12U),     /*!< ADC interrupt as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_AdcInt   = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 12U),    /*!< ADC interrupt as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_LptmrInt = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 13U),     /*!< LPTMR interrupt as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_LptmrInt = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 13U),      /*!< LPTMR interrupt as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_LptmrInt = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 13U),     /*!< LPTMR interrupt as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_TamperDetect = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 14U), /*!< Tamper detect as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_TamperDetect = POWER_ENCODE_WS(0U, 0U, 1U, 0U, 0U, 0U, 14U),  /*!< Tamper detect as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_TamperDetect = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 14U), /*!< Tamper detect as wakeup source, 
        wakeup both Main and AON Domains */

    kPower_WS_Main_LcdInt = POWER_ENCODE_WS(0U, 0U, 0U, 0U, 0U, 0U, 15U),       /*!< LCD interrupt as wakeup source, only
        wakeup Main Domain */
    kPower_WS_Aon_LcdInt = POWER_ENCODE_WS(0U, 0U, 1U,  0U, 0U, 0U, 15U),       /*!< LCD interrupt as wakeup source, only
        wakeup AON Domain */
    kPower_WS_Both_LcdInt = POWER_ENCODE_WS(0U, 0U, 2U, 0U, 0U, 0U, 15U),      /*!< LCD interrupt as wakeup source, 
        wakeup both Main and AON Domains */

    /* Following wakeup sources reside in CM33 domain and shall not wakeup device from Power Down mode. */
    kPower_WS_Main_P0_0RiseEdgeInt = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 2U, 0U),  /*!< Pin P0_0 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_0RiseEdgeDma = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 2U, 0U),  /*!< Pin P0_0 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_0RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 2U, 0U), /*!< Pin P0_0 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_0FallEdgeInt = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 2U, 0U),  /*!< Pin P0_0 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_0FallEdgeDma = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 2U, 0U),  /*!< Pin P0_0 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_0FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 2U, 0U), /*!< Pin P0_0 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_0AnyEdgeInt = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 2U, 0U),   /*!< Pin P0_0 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_0AnyEdgeDma = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 2U, 0U),   /*!< Pin P0_0 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_0AnyEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 2U, 0U),  /*!< Pin P0_0 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P0_15RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 6U, 0U), /*!< Pin P0_15 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_15RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 6U, 0U), /*!< Pin P0_15 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_15RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 6U, 0U), /*!< Pin P0_15 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_15FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 6U, 0U), /*!< Pin P0_15 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_15FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 6U, 0U), /*!< Pin P0_15 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_15FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 6U, 0U), /*!< Pin P0_15 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_15AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 6U, 0U), /*!< Pin P0_15 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_15AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 6U, 0U), /*!< Pin P0_15 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_15AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 6U, 0U), /*!< Pin P0_15 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P1_16RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 7U, 0U), /*!< Pin P1_16 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_16RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 7U, 0U), /*!< Pin P1_16 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_16RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 7U, 0U), /*!< Pin P1_16 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_16FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 7U, 0U), /*!< Pin P1_16 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_16FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 7U, 0U), /*!< Pin P1_16 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_16FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 7U, 0U), /*!< Pin P1_16 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_16AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 7U, 0U), /*!< Pin P1_16 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_16AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 7U, 0U), /*!< Pin P1_16 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_16AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 7U, 0U), /*!< Pin P1_16 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P1_17RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 8U, 0U), /*!< Pin P1_17 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_17RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 8U, 0U), /*!< Pin P1_17 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_17RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 8U, 0U), /*!< Pin P1_17 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_17FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 8U, 0U), /*!< Pin P1_17 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_17FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 8U, 0U), /*!< Pin P1_17 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_17FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 8U, 0U), /*!< Pin P1_17 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_17AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 8U, 0U), /*!< Pin P1_17 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_17AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 8U, 0U), /*!< Pin P1_17 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_17AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 8U, 0U), /*!< Pin P1_17 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P0_20RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 9U, 0U), /*!< Pin P0_20 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_20RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 9U, 0U), /*!< Pin P0_20 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_20RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 9U, 0U), /*!< Pin P0_20 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_20FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 9U, 0U), /*!< Pin P0_20 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_20FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 9U, 0U), /*!< Pin P0_20 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_20FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 9U, 0U), /*!< Pin P0_20 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_20AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 9U, 0U), /*!< Pin P0_20 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_20AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 9U, 0U), /*!< Pin P0_20 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_20AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 9U, 0U), /*!< Pin P0_20 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P0_23RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 10U, 0U), /*!< Pin P0_23 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_23RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 10U, 0U), /*!< Pin P0_23 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_23RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 10U, 0U), /*!< Pin P0_23 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_23FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 10U, 0U), /*!< Pin P0_23 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_23FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 10U, 0U), /*!< Pin P0_23 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_23FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 10U, 0U), /*!< Pin P0_23 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_23AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 10U, 0U), /*!< Pin P0_23 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_23AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 10U, 0U), /*!< Pin P0_23 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_23AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 10U, 0U), /*!< Pin P0_23 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P0_3RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 11U, 0U), /*!< Pin P0_3 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_3RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 11U, 0U), /*!< Pin P0_3 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_3RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 11U, 0U), /*!< Pin P0_3 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_3FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 11U, 0U), /*!< Pin P0_3 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_3FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 11U, 0U), /*!< Pin P0_3 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_3FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 11U, 0U), /*!< Pin P0_3 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_3AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 11U, 0U), /*!< Pin P0_3 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_3AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 11U, 0U), /*!< Pin P0_3 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_3AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 11U, 0U), /*!< Pin P0_3 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P0_4RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 12U, 0U), /*!< Pin P0_4 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_4RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 12U, 0U), /*!< Pin P0_4 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_4RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 12U, 0U), /*!< Pin P0_4 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_4FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 12U, 0U), /*!< Pin P0_4 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_4FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 12U, 0U), /*!< Pin P0_4 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_4FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 12U, 0U), /*!< Pin P0_4 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_4AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 12U, 0U), /*!< Pin P0_4 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_4AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 12U, 0U), /*!< Pin P0_4 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_4AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 12U, 0U), /*!< Pin P0_4 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P0_13RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 18U, 0U), /*!< Pin P0_13 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_13RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 18U, 0U), /*!< Pin P0_13 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_13RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 18U, 0U), /*!< Pin P0_13 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_13FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 18U, 0U), /*!< Pin P0_13 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_13FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 18U, 0U), /*!< Pin P0_13 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_13FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 18U, 0U), /*!< Pin P0_13 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_13AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 18U, 0U), /*!< Pin P0_13 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_13AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 18U, 0U), /*!< Pin P0_13 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P0_13AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 18U, 0U), /*!< Pin P0_13 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P1_13RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 19U, 0U), /*!< Pin P1_13 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_13RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 19U, 0U), /*!< Pin P1_13 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_13RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 19U, 0U), /*!< Pin P1_13 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_13FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 19U, 0U), /*!< Pin P1_13 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_13FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 19U, 0U), /*!< Pin P1_13 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_13FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 19U, 0U), /*!< Pin P1_13 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_13AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 19U, 0U), /*!< Pin P1_13 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_13AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 19U, 0U), /*!< Pin P1_13 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_13AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 19U, 0U), /*!< Pin P1_13 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P1_1RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 20U, 0U), /*!< Pin P1_1 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_1RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 20U, 0U), /*!< Pin P1_1 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_1RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 20U, 0U), /*!< Pin P1_1 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_1FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 20U, 0U), /*!< Pin P1_1 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_1FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 20U, 0U), /*!< Pin P1_1 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_1FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 20U, 0U), /*!< Pin P1_1 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_1AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 20U, 0U), /*!< Pin P1_1 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_1AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 20U, 0U), /*!< Pin P1_1 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_1AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 20U, 0U), /*!< Pin P1_1 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P1_2RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 22U, 0U), /*!< Pin P1_2 rising edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_2RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 22U, 0U), /*!< Pin P1_2 rising edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_2RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 22U, 0U), /*!< Pin P1_2 rising edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_2FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 22U, 0U), /*!< Pin P1_2 falling edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_2FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 22U, 0U), /*!< Pin P1_2 falling edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_2FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 22U, 0U), /*!< Pin P1_2 falling edge trigger as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_2AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 22U, 0U),  /*!< Pin P1_2 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_2AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 22U, 0U), /*!< Pin P1_2 any edge DMA request as
    wakeup source, can be used to wakeup from DS mode. */
    kPower_WS_Main_P1_2AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 22U, 0U), /*!< Pin P1_2 any edge interrupt as
    wakeup source, can be used to wakeup from DS mode. */

    kPower_WS_Main_P1_5RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 23U, 0U),   /*!< P1_5 pin rising edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_5RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 23U, 0U),   /*!< P1_5 pin rising edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_5RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 23U, 0U),   /*!< P1_5 pin rising edge trigger as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_5FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 23U, 0U),   /*!< P1_5 pin falling edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_5FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 23U, 0U),   /*!< P1_5 pin falling edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_5FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 23U, 0U),   /*!< P1_5 pin falling edge trigger as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_5AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 23U, 0U),   /*!< P1_5 pin any edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_5AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 23U, 0U),   /*!< P1_5 pin any edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_5AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 23U, 0U),   /*!< P1_5 pin any edge trigger as wakeup source, wakeup Main Domain */

    kPower_WS_Main_P1_14RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 5U, 0U),  /*!< P1_14 pin rising edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_14RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 5U, 0U),  /*!< P1_14 pin rising edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_14RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 5U, 0U),  /*!< P1_14 pin rising edge trigger as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_14FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 5U, 0U),  /*!< P1_14 pin falling edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_14FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 5U, 0U),  /*!< P1_14 pin falling edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_14FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 5U, 0U),  /*!< P1_14 pin falling edge trigger as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_14AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 5U, 0U),  /*!< P1_14 pin any edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_14AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 5U, 0U),  /*!< P1_14 pin any edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_14AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 5U, 0U),  /*!< P1_14 pin any edge trigger as wakeup source, wakeup Main Domain */

    kPower_WS_Main_P1_19RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 25U, 0U),  /*!< P1_19 pin rising edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_19RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 25U, 0U),  /*!< P1_19 pin rising edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_19RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 25U, 0U),  /*!< P1_19 pin rising edge trigger as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_19FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 25U, 0U),  /*!< P1_19 pin falling edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_19FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 25U, 0U),  /*!< P1_19 pin falling edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_19FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 25U, 0U),  /*!< P1_19 pin falling edge trigger as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_19AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 25U, 0U),  /*!< P1_19 pin any edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_19AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 25U, 0U),  /*!< P1_19 pin any edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_19AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 25U, 0U),  /*!< P1_19 pin any edge trigger as wakeup source, wakeup Main Domain */

    kPower_WS_Main_P1_23RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 26U, 0U),  /*!< P1_23 pin rising edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_23RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 26U, 0U),  /*!< P1_23 pin rising edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_23RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 26U, 0U),  /*!< P1_23 pin rising edge trigger as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_23FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 26U, 0U),  /*!< P1_23 pin falling edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_23FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 26U, 0U),  /*!< P1_23 pin falling edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_23FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 26U, 0U),  /*!< P1_23 pin falling edge trigger as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_23AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 26U, 0U),  /*!< P1_23 pin any edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_23AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 26U, 0U),  /*!< P1_23 pin any edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_23AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 26U, 0U),  /*!< P1_23 pin any edge trigger as wakeup source, wakeup Main Domain */

    kPower_WS_Main_P1_22RiseEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 0U, 27U, 0U),  /*!< P1_22 pin rising edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_22RiseEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 1U, 27U, 0U),  /*!< P1_22 pin rising edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_22RiseEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 1U, 2U, 27U, 0U),  /*!< P1_22 pin rising edge trigger as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_22FallEdgeInt  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 0U, 27U, 0U),  /*!< P1_22 pin falling edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_22FallEdgeDma  = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 1U, 27U, 0U),  /*!< P1_22 pin falling edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_22FallEdgeTrig = POWER_ENCODE_WS(1U, 1U, 0U, 2U, 2U, 27U, 0U),  /*!< P1_22 pin falling edge trigger as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_22AnyEdgeInt   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 0U, 27U, 0U),  /*!< P1_22 pin any edge interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_22AnyEdgeDma   = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 1U, 27U, 0U),  /*!< P1_22 pin any edge DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_P1_22AnyEdgeTrig  = POWER_ENCODE_WS(1U, 1U, 0U, 3U, 2U, 27U, 0U),  /*!< P1_22 pin any edge trigger as wakeup source, wakeup Main Domain */

    kPower_WS_Main_Lptmr0Int  = POWER_ENCODE_WS(1U, 0U, 0U, 0U, 0U, 6U, 0U),  /*!< LPTMR0 interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_Cmp0Int    = POWER_ENCODE_WS(1U, 0U, 0U, 0U, 0U, 8U, 0U),  /*!< CMP0 interrupt as wakeup source, wakeup Main Domain */
    kPower_WS_Main_Lptmr0Dma  = POWER_ENCODE_WS(1U, 0U, 0U, 0U, 1U, 4U, 0U),  /*!< LPTMR0 DMA as wakeup source, wakeup Main Domain */
    kPower_WS_Main_Lptmr0Trig = POWER_ENCODE_WS(1U, 0U, 0U, 0U, 1U, 6U, 0U),  /*!< LPTMR0 trigger as wakeup source, wakeup Main Domain */
    kPower_WS_Main_Cmp0DMA    = POWER_ENCODE_WS(1U, 0U, 0U, 0U, 1U, 8U, 0U),  /*!< CMP0 DMA as wakeup source, wakeup Main Domain */
} power_wakeup_source_t;

/*!
 * @brief The structure of dumped wakeup source information.
 */
typedef struct _power_wakeup_source_info
{
    uint32_t aonWakeupSourceMask;    /*!< The mask of wakeup sources in AON domain. */
    uint32_t wuuPinIntEnable[2];     /*!< Information of enabled Pin interrupts. */
    uint32_t wuuModuleIntEnable;     /*!< Information of enabled internal module interrupts. */
    uint32_t wuuModuleDmaTrigEnable; /*!< Information of enabled internal module DMA request/trigger. */
    uint32_t wuuPinDmaTrigConfig[2]; /*!< Information of enabled pin DMA request/trigger. */
} power_wakeup_source_info_t;

/*!
 * @brief 
 * @anchor power_main_domain_sram_array_t
 */
enum _power_main_domain_sram_array
{
    kPower_MainDomainNoneRams = 0UL,
    kPower_MainDomainRamX0 = 1UL << 0UL,  /*!< Main Domain RAM X0, bitmask representation for power control */
    kPower_MainDomainRamX1 = 1UL << 1UL,  /*!< Main Domain RAM X1, bitmask representation for power control */
    kPower_MainDomainRamA0 = 1UL << 2UL,  /*!< Main Domain RAM A0, bitmask representation for power control */
    kPower_MainDomainRamA1 = 1UL << 3UL,  /*!< Main Domain RAM A1, bitmask representation for power control */
    kPower_MainDomainRamA2 = 1UL << 4UL,  /*!< Main Domain RAM A2, bitmask representation for power control */
    kPower_MainDomainRamA3 = 1UL << 5UL,  /*!< Main Domain RAM A3, bitmask representation for power control */
    kPower_MainDomainRamB0 = 1UL << 6UL,  /*!< Main Domain RAM B0, bitmask representation for power control */
    kPower_MainDomainRamB1 = 1UL << 7UL,  /*!< Main Domain RAM B1, bitmask representation for power control */
    kPower_MainDomainRamB2ToB4 = 1UL << 8UL,  /*!< Main Domain RAM B2 to B4, bitmask representation for power control */
    kPower_MainDomainAllRams = 0x1FFUL,  /*!< Represents all RAMs in the Main Domain, bitmask for power control */
};

/*!
 * @brief 
 * @anchor power_aon_domain_sram_array_t
 */
enum _power_aon_domain_sram_array
{
    kPower_AonDomainNoneRams = 0UL,               /*!< No AON Domain RAMs. */
    kPower_AonDomainRam1stHalf16kB = 1UL << 0UL,  /*!< First half (16kB) of AON Domain RAM, bitmask for power control */
    kPower_AonDomainRam2nd8kB = 1UL << 1UL,       /*!< Second 8kB of AON Domain RAM, bitmask for power control */
    kPower_AonDomainRamLower8kB = 1UL << 2UL,     /*!< Lower 8kB of AON Domain RAM, bitmask for power control */
    kPower_AonDomainAllRams = 0x7UL,              /*!< Represents all RAMs in the AON Domain, bitmask for power control */
};

/*!
 * @brief Enumeration of power MU message directions.
 */
typedef enum _power_mu_message_direction
{
    kPower_MsgDirMainToAon = 0U,  /*!< Message direction from Main to AON domain */
    kPower_MsgDirAonToMain = 1U,  /*!< Message direction from AON to Main domain */
} power_mu_message_direction_t;

/*!
 * @brief Enumeration of power MU message types.
 */
typedef enum _power_mu_message_type
{
    kPower_MsgTypeRequest = 0U,  /*!< Message type is a request */
    kPower_MsgTypeACK = 1U,      /*!< Message type is an ACKnowledgment */
    kPower_MsgTypeNACK = 2U,     /*!< Message type is a Negative ACKnowledgment */
} power_mu_message_type_t;

/*!
 * @brief Union representing a power MU message.
 */
typedef union _power_mu_message
{
    struct {
        uint32_t syncCode : 8U;  /*!< Synchronization code for the message */
        power_mu_message_type_t type : 2U;  /*!< Type of the message, refer to @ref power_mu_message_type_t */
        power_mu_message_direction_t direction : 1U;  /*!< Direction of the message, refer to @ref power_mu_message_direction_t */
        power_low_power_mode_t reqestLowPowerMode : 4U;  /*!< Requested low power mode */
        bool init : 1U;  /*!< Initialization flag */
        uint32_t sharedHandleAddrOff : 16U;  /*!< Offset from shared ram base address */
    } strcutFormat;
    uint32_t wordFormat;  /*!< Message in word format */
} power_mu_message_t;

/*!
 * @brief Output voltage options for VDDCore in low power modes.
 * 
 */
typedef enum _power_vdd_core_output_voltage
{
    kPower_VddCoreOutput1P0V,
} power_vdd_core_output_voltage_t;

typedef struct _power_ds_config
{

} power_ds_config_t;

/*!
 * @brief Configuration structure for power down mode.
 */
typedef struct _power_pd1_config
{
    uint32_t mainRamArraysToRetain : 16U;  /*!< Bitmask representing the main domain RAM arrays to retain during power down */
    power_vdd_core_output_voltage_t VDDCoreOutputVoltage : 8U;
    bool disableBandgap : 1U;             /*!< Flag to indicate whether to disable the bandgap during power down */
    bool enableIVSMode : 1U;              /*!< Enable/disable IVS mode for the Main domain SRAM retention. */
} power_pd1_config_t;

typedef struct _power_pd2_config
{
    uint32_t mainRamArraysToRetain : 16U;  /*!< Bitmask representing the main domain RAM arrays to retain during DPD2 mode */
    uint32_t  aonRamArraysToRetain : 16U;   /*!< Bitmask representing the AON domain RAM arrays to retain during DPD2 mode */
    power_vdd_core_output_voltage_t VDDCoreOutputVoltage : 8U; 
    bool enableIVSMode : 1U;              /*!< Enable/disable IVS mode for the Main domain SRAM retention. */
    bool disableBandgap : 1U;             /*!< Flag to indicate whether to disable the bandgap during DPD2 mode */
    bool switchToX32K : 1U;               /*!< Flag to indicate whether to switch to X32K clock source during DPD2 mode */
    bool disableFRO10M : 1U;        /*!< Flag to indicate whether to disable the FRO10M clock during DPD2 mode */
} power_pd2_config_t;

/*!
 * @brief Enumeration of follow power transition.
 */
typedef enum _power_dpd1_transition
{
    kPower_Dpd1ToActive = 0U,   /*!< Transition from DPD1 to Active mode */
    kPower_Dpd1ToDpd2WakeToDpd1, /*!< Transition from DPD1 to DPD2 wakeup to DPD1 mode */
    kPower_Dpd1ToDpd2WakeToActive, /*!< Transition from DPD1 to DPD2 wakeup to Active mode */
} power_dpd1_transition_t;

/*!
 * @brief Configuration structure for deep power down mode 1.
 * 
 */
typedef struct _power_dpd1_config
{
    uint32_t mainRamArraysToRetain : 16U;  /*!< Bitmask representing the main domain RAM arrays to retain during power down */
    power_vdd_core_output_voltage_t VDDCoreOutputVoltage : 8U;
    bool disableBandgap : 1U;             /*!< Flag to indicate whether to disable the bandgap during power down */
    bool enableIVSMode : 1U;              /*!< Enable/disable IVS mode for the Main domain SRAM retention. */
    power_dpd1_transition_t nextTrans: 2U;  /*!< Next transition after DPD1 mode, refer to @ref power_dpd1_transition_t */
} power_dpd1_config_t;

/*!
 * @brief Configuration structure for deep power down mode 2.
 */
typedef struct _power_dpd2_config
{
    uint32_t mainRamArraysToRetain : 16U;  /*!< Bitmask representing the main domain RAM arrays to retain during DPD2 mode */
    uint32_t  aonRamArraysToRetain : 16U;   /*!< Bitmask representing the AON domain RAM arrays to retain during DPD2 mode */
    power_vdd_core_output_voltage_t VDDCoreOutputVoltage : 8U; 
    bool enableIVSMode : 1U;              /*!< Enable/disable IVS mode for the Main domain SRAM retention. */
    bool disableBandgap : 1U;             /*!< Flag to indicate whether to disable the bandgap during DPD2 mode */
    bool switchToX32K : 1U;               /*!< Flag to indicate whether to switch to X32K clock source during DPD2 mode */
    bool disableFRO10M : 1U;        /*!< Flag to indicate whether to disable the FRO10M clock during DPD2 mode */
    bool wakeToDpd1 : 1U;           /*!< Flag to indicate whether to wake up to DPD1 mode after DPD2 mode */
} power_dpd2_config_t;

/*!
 * @brief Configuration structure for deep power down mode 3.
 */
typedef struct _power_dpd3_config
{
    power_vdd_core_output_voltage_t VDDCoreOutputVoltage : 8U;
} power_dpd3_config_t;

/*!
 * @brief Configuration structure for shut down.
 */
typedef struct _power_sd_config
{
} power_sd_config_t;


/*!
 * @brief Structure to handle power management operations.
 */
typedef struct _power_handle
{
    uint32_t muChannelId;  /*!< ID of the Message Unit (MU) channel used for power communication */
    power_low_power_mode_t targetPowerMode;  /*!< Current low power mode of the system */
    uint32_t lpConfig[2U];  /*!< Array of two 32-bit values for low power configuration */
    bool dualCoreSynced;  /*!< Flag indicating whether dual cores are synchronized */
    bool requestCM33Start;  /*!< Flag indicating whether a request to start CM33 core is made */
    power_user_callback_t cm33Callback; /*!< Callback function for CM33 core operations, in type of @ref power_user_callback_t */
    void *cm33UserData; /*!< User data pointer for CM33 core operations */
    power_user_callback_t cm0pCallback; /*!< Callback function for CM0+ core operations, in type of @ref power_user_callback_t */
    void *cm0pUserData;     /*!< User data pointer for CM0+ core operations */
} power_handle_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Create shared power handle.
 * 
 * @param[in] handle Pointer to a handle in type of @ref power_handle_t, must be in shared RAM.
 * @param[in] muChannelId MU channel ID used by power driver.
 *
 * @retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * @retval kStatus_Power_HandleDuplicated Shared power handle already be created.
 * @retval kStatus_Success Created handle successfully.
 */
status_t Power_CreateHandle(power_handle_t *handle,
                            uint32_t muChannelId);

void Power_DumpHandleValue(power_handle_t *ptrDumpBuffer);

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
 * @name Wakeup Source Control Interfaces
 * @{
 */

/*!
 * @brief Enable input wakeup source, once enabled it will be effective until disabled
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
 * @brief Dump information of all configured wakeup sources, in type of @ref power_wakeup_source_info_t.
 *
 * @param[out] ptrWsInfo Pointer to the variable to store dumped wakeup source information.
 */
void Power_DumpEnabledWakeSource(power_wakeup_source_info_t *ptrWsInfo);

/*!
 * @brief Get latest mask of wakeup sources which cause the wake-up to main CPU.
 *
 * @param[out] ptrWakeupSourceMask Pointer to the variable to store mask of wakeup sources.
 */
void Power_GetWakeupSource(uint32_t *ptrWakeupSourceMask);

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
 * @brief 
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
void Power_ClearTargatePowerMode(void);

/*!
 * @brief Clear all low power settings.
 */
void Power_ClearLpPowerSettings(void);

/*!
* @brief Enter selected low power mode.
* 
* @param[in] lowpowerMode Indicate specific low power mode.
* @param config Point to low power configurations.
*
* @retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
* @retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
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
 * @param[in] config Pointer to the Deep Power Down 2 mode configuration.
 * 
 * @retval kStatus_Success Successfully entered Deep Power Down 2 mode.
 * @retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * @retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterDeepPowerDown2(power_dpd2_config_t *config);

/*!
 * @brief Enter Deep Power Down 3 mode.
 * 
 * This function attempts to put the system into Deep Power Down 3 mode with the provided configuration.
 * 
 * @param[in] config Pointer to the Deep Power Down 3 mode configuration.
 * 
 * @retval kStatus_Success Successfully entered Deep Power Down 3 mode.
 * @retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * @retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterDeepPowerDown3(power_dpd3_config_t *config);

/*!
 * @brief Enter Shutdown mode.
 * 
 * This function attempts to put the system into Shutdown mode with the provided configuration.
 * 
 * @param[in] config Pointer to the Shutdown mode configuration.
 * 
 * @retval kStatus_Success Successfully entered Shutdown mode.
 * @retval kStatus_POWER_MuTransferError Something error occurs during MU transfer.
 * @retval kStatus_POWER_RequestNotAllowed Request not allowed by another core.
 */
status_t Power_EnterShutDown(power_sd_config_t *config);

/*!
 * @}
 *
 */


/*!@name Power MU Transfer Callback
 @{
 */

/*!
 * @brief Callback function for handling power MU messages.
 * 
 * This function is called when a power MU message is received. It processes the message
 * based on the given message content and the channel ID.
 * 
 * @param[in] message The received power MU message.
 * @param[in] channelId The ID of the channel on which the message was received.
 * 
 * @retval None This function does not return a value.
 */
void Power_MuMessageCallback(uint32_t message, uint32_t channelId);


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
