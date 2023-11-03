/*! *********************************************************************************
 * \defgroup CONTROLLER - Controller Interface
 * @{
 ********************************************************************************** */
/*! *********************************************************************************
* Copyright (c) 2014, Freescale Semiconductor, Inc.
* Copyright 2016-2017 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef _QN_BLE_CONFIG_H_
#define _QN_BLE_CONFIG_H_

/*! @brief GAP role: CFG_CENTRAL, CFG_PERIPHERAL, CFG_OBSERVER, CFG_BROADCASTER, CFG_ALLROLES */
#if !( defined(CFG_CENTRAL) || defined(CFG_PERIPHERAL) || defined(CFG_OBSERVER) || defined(CFG_BROADCASTER) )
#define CFG_ALLROLES
#endif


#define K32W061_MAX_CONNECTION          (8)
#define K32W061_MAX_WHITELIST           (26)

/*! @brief Max number of devices in white list supported by K32W061 */
#if (gPWR_CpuClk_48MHz)
    #define K32W061_MAX_IP_WHITELIST    (46)
    #define K32W061_MAX_RESOL_ADDR_LIST (8)
#else
    #define K32W061_MAX_IP_WHITELIST    (36)
    #define K32W061_MAX_RESOL_ADDR_LIST (6)
#endif


/*! @brief Maximum connected devices number (Link number).
    Select the appropriate number for your application and get optimized memory usage. */
#if defined (gAppMaxConnections_c)
    #if (gAppMaxConnections_c > K32W061_MAX_CONNECTION)
        #error "Max Supported connection is 8"
    #else
        #define CFG_CON_DEV_MAX         (gAppMaxConnections_c)
    #endif
#else
    #define CFG_CON_DEV_MAX             (K32W061_MAX_CONNECTION)
#endif


/*! @brief Number of devices in the white list */
#if defined (gMaxWhiteListSize_c)
    #if (gMaxWhiteListSize_c > K32W061_MAX_IP_WHITELIST)
        #error "gMaxWhiteListSize_c > to Max Whitelist supported by IP"
    #else
        #define CFG_BLE_WHITELIST_MAX   (gMaxWhiteListSize_c)
    #endif
#else
    #define CFG_BLE_WHITELIST_MAX       (K32W061_MAX_WHITELIST)
#endif


/*! @brief Number of devices in the Resolution Address List */
#if defined (gMaxResolvingListSize_c)
    #if (gMaxResolvingListSize_c > K32W061_MAX_RESOL_ADDR_LIST)
        #error "gMaxResolvingListSize_c > to Max Resolve Address supported by IP"
    #else
        #define CFG_BLE_RESOL_ADDR_LIST_MAX     (gMaxResolvingListSize_c)
    #endif
#else
    #define CFG_BLE_RESOL_ADDR_LIST_MAX         (K32W061_MAX_RESOL_ADDR_LIST)
#endif


/*! @brief Number of devices capacity for the scan filtering */
#if defined (gMaxDuplicateFilter_c)
    #define CFG_BLE_DUPLICATE_FILTER_MAX        (gMaxDuplicateFilter_c)
#else
    #define CFG_BLE_DUPLICATE_FILTER_MAX        (10)
#endif


/*! @brief TX buffer size */
#if defined (gTxBufferDataSize_c)
    #if (gTxBufferDataSize_c > 260)
        #error "TX Buffer data size > 260"
    #else
        #define CFG_REG_BLE_EM_TX_BUFFER_DATA_SIZE (gTxBufferDataSize_c)
    #endif
#else
    #define CFG_REG_BLE_EM_TX_BUFFER_DATA_SIZE      (260)
#endif

/*! @brief RX buffer size */
#if defined (gRxBufferSize_c)
    #if (gRxBufferSize_c > 260)
        #error "RX Buffer size > 260"
    #else
        #define CFG_REG_BLE_EM_RX_BUFFER_SIZE       (gRxBufferSize_c)
    #endif
#else
    #define CFG_REG_BLE_EM_RX_BUFFER_SIZE           (260)
#endif

/*! @brief TX power range [E2-0A] (-30 to 10 dbm) */
#if defined (gPWR_DtmDefaultTxPwr_c)
    #if (((gPWR_DtmDefaultTxPwr_c > 0xA) && (gPWR_DtmDefaultTxPwr_c < 0xE2 )) || (gPWR_DtmDefaultTxPwr_c > 0xFF))
        #error "Incorrect TX PWR value"
    #else
        #define CFG_DEF_TXPWR_DTM_DBM               (gPWR_DtmDefaultTxPwr_c)
    #endif
#else
    #define CFG_DEF_TXPWR_DTM_DBM                   (10)
#endif

/*! @brief EA programming latency for only 1 activity */
#define CFG_BLE_PROG_LATENCY_DFT                    (2)

/*! @brief Local Sleep Clock accuracy in PPM */
#if defined (gLocalSleepClkAccuracyPpm)
#define CFG_LOCAL_SCA_PPM                           (gLocalSleepClkAccuracyPpm)
#else
#define CFG_LOCAL_SCA_PPM                           (500)
#endif

/*! @brief Minimum number of connection event for instant calculation (6 according to the SIG) */
#if defined (gMWS_MinInstantConEvt_c)
    #if (gMWS_MinInstantConEvt_c < 6)
        #error "gMWS_MinInstantConEvt_c < 6"
    #else
        #define CFG_MIN_INSTANT_CON_EVT             (gMWS_MinInstantConEvt_c)
        #define CFG_LLD_UTIL_MIN_INSTANT_CON_EVT    (gMWS_MinInstantConEvt_c)
    #endif
#else
#define CFG_MIN_INSTANT_CON_EVT                     (6)
#define CFG_LLD_UTIL_MIN_INSTANT_CON_EVT            (6)
#endif

/*! @brief Number of BLE slots (625us) per second */
#define NB_BLE_SLOTS_PER_SEC                        1600U

/*! @brief Number of BLE slots per hour */
#define NB_BLE_SLOTS_PER_HOUR                       (3600*NB_BLE_SLOTS_PER_SEC)

/*! @brief Max number of BLE slots : greater values cause conversion to 32k ticks to fail */
#define MAX_SUPPORTED_NB_SLOTS                      (NB_BLE_SLOTS_PER_HOUR*35) /* 35h */

/*! @brief Sleep Duration Value in periodic wake-up mode */
#define CFG_MAX_SLEEP_DURATION_PERIODIC_WAKEUP      (NB_BLE_SLOTS_PER_SEC/2U)   /* defaults to 500ms */

/*! @brief Sleep Duration Value in external wake-up mode */
/*
 * Sleep Duration Value in external wake-up mode
 * This value cannot be greater than MAX_SUPPORTED_NB_SLOTS i.e. 35h.
 * */
#define CFG_MAX_SLEEP_DURATION_EXTERNAL_WAKEUP      (NB_BLE_SLOTS_PER_HOUR*24)  /* default to 24h */


#if (CFG_MAX_SLEEP_DURATION_EXTERNAL_WAKEUP > MAX_SUPPORTED_NB_SLOTS)
/* Prevent erroneous configuration that could lead to assert of bad execution in BLE controller library */
#error "Sleep duration larger than 35h is unsupported"
#endif

#define CFG_HEAP_NON_RET_SIZE                       (0)

#endif /* _QN_BLE_CONFIG_H_ */
