/*! *********************************************************************************
 * \defgroup BLE_CONFIG BLE Configuration Constants
 * @{
 ********************************************************************************** */
/*! *********************************************************************************
* Copyright (c) 2014, Freescale Semiconductor, Inc.
* Copyright 2016-2020 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef BLE_CONSTANTS_H
#define BLE_CONSTANTS_H

/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/
/*! Size of a BLE Device Address */
#define gcBleDeviceAddressSize_c        (6U)

/*! Size of bond data structures for a bonded device  */
#define gBleBondIdentityHeaderSize_c    (32U)
#define gBleBondDataDynamicSize_c       (8U)
#define gBleBondDataStaticSize_c        (56U)
#define gBleBondDataDeviceInfoSize_c    (60U)
#define gBleBondDataDescriptorSize_c    (4U)

/*! Maximum number of CCCDs */
#ifndef gcGapMaximumSavedCccds_c
#define gcGapMaximumSavedCccds_c        (16U)
#endif

/*! Maximum number of attributes that require authorization */
#define gcGapMaxAuthorizationHandles_c  (1U)

/*! Bonding Data Size */
#define gBleBondDataSize_c              (gBleBondIdentityHeaderSize_c + gBleBondDataDynamicSize_c + \
                                         gBleBondDataStaticSize_c + gBleBondDataDeviceInfoSize_c  + \
                                        (gBleBondDataDescriptorSize_c * gcGapMaximumSavedCccds_c))

/*! Size of long UUIDs */
#define gcBleLongUuidSize_c             ((uint16_t)(16U))

/*! Maximum Long Term Key size in bytes */
#define gcSmpMaxLtkSize_c               (16U)

/*! Identity Resolving Key size in bytes */
#define gcSmpIrkSize_c                  (16U)

/*! Connection Signature Resolving Key size in bytes */
#define gcSmpCsrkSize_c                 (16U)

/*! Maximum Rand size in bytes */
#define gcSmpMaxRandSize_c              (8U)

/*! SMP OOB size in bytes */
#define gcSmpOobSize_c  (16U)

/*! SMP LE Secure Connections Pairing Random size in bytes */
#define gSmpLeScRandomValueSize_c           (16U)

/*! SMP LE Secure Connections Pairing Confirm size in bytes */
#define gSmpLeScRandomConfirmValueSize_c    (16U)

/*! Maximum device name size */
#define gcGapMaxDeviceNameSize_c        (19U)

/*! Maximum size of advertising and scan response data */
#define gcGapMaxAdvertisingDataLength_c (31U)

/*! Default value of the ATT_MTU */
#define gAttDefaultMtu_c                (23U)

/*! Maximum possible value of the ATT_MTU for this device. This is used during the MTU Exchange. */
#define gAttMaxMtu_c                    (247U)

/*! The maximum length of an attribute value shall be 512 octets. */
#define gAttMaxValueLength_c            (512U)

/*! Channel the number of the UART hardware module (For example, if UART1 is used, this value should be 1). */
#define gHciTransportUartChannel_c                  (1U)

/*! Number of bytes reserved for storing application-specific information about a device */
#define gcReservedFlashSizeForCustomInformation_c   (40U)

/*! Size of a channel map in a connection */
#define gcBleChannelMapSize_c           (5U)

#define gBleMinTxOctets_c       (27U)
#define gBleMinTxTime_c         (328U)
#define gBleMaxTxOctets_c       (251U)      /*! Data Packet Length Extension, regardless of PHY */
#define gBleMaxTxTime_c         (2120U)     /*! Data Packet Length Extension, Coded PHY not supported */
#define gBleMaxTxTimeCodedPhy_c (17040U)    /*! Data Packet Length Extension, Coded PHY supported */

/*! Maximum value of the advertising SID. */
#define gBleExtAdvMaxSetId_c            (0x0FU)

/*! Maximum value of the periodic advertising handle. */
#define gBlePeriodicAdvMaxSyncHandle_c  (0x0EFFU)

/*! SID of the legacy advertising set. */
#define gBleExtAdvLegacySetId_c         (0x00U)

/*! Handle of the legacy advertising set. */
#define gBleExtAdvLegacySetHandle_c     gBleExtAdvLegacySetId_c

/*! Default SID for extended advertising. */
#define gBleExtAdvDefaultSetId_c        (0x00U)

/*! Default handle for extended advertising. */
#define gBleExtAdvDefaultSetHandle_c    gBleExtAdvDefaultSetId_c

/*! Host has no preference for Tx Power */
#define gBleAdvTxPowerNoPreference_c    (127)

/*! No advertising duration. Advertising to continue until the Host disables it. */
#define gBleExtAdvNoDuration_c          (0x0000U)

/*! Default advertising duration in high duty directed advertising 1.28s = 1280ms/10ms(unit) = 128 */
#define gBleHighDutyDirectedAdvDuration (0x80U)

/*! No maximum number of advertising events. */
#define gBleExtAdvNoMaxEvents_c         (0x00U)

/*! Periodic advertising default handle. */
#define gBlePeriodicAdvDefaultHandle_c  (gBleExtAdvDefaultSetHandle_c)

/*! Minimum value for the sync_timeout parameter */
#define gBlePeriodicAdvSyncTimeoutMin_c (0x000A)

/*! Maximum value for the sync_timeout parameter */
#define gBlePeriodicAdvSyncTimeoutMax_c (0x4000)

/*! Maximum value for the skip parameter */
#define gBlePeriodicAdvSkipMax_c        (0x01F3)

/*! Maximum length of an AD structure */
#define gBleMaxADStructureLength_c      (254U)

/*! Maximum length of Extended Advertising Data */
#define gBleMaxExtAdvDataLength_c       (1650U)

/*! Maximum value in us of AUX Offset(13 bits) in AuxPtr in 300us units, i.e. ((1 << 13) - 1) * 300 */
#define gBleExtAdvMaxAuxOffsetUsec_c    (0x257ED4U)

#endif /* BLE_CONSTANTS_H */

/*! *********************************************************************************
* @}
********************************************************************************** */
