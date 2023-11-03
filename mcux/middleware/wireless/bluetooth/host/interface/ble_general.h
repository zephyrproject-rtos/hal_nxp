/*! *********************************************************************************
 * \defgroup BLE BLE General Definitions
 * @{
 ********************************************************************************** */
/*! *********************************************************************************
* Copyright (c) 2014, Freescale Semiconductor, Inc.
* Copyright 2016-2022 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef BLE_GENERAL_H
#define BLE_GENERAL_H

/************************************************************************************
*************************************************************************************
* Include
*************************************************************************************
************************************************************************************/
#include "EmbeddedTypes.h"
#include "FunctionLib.h"
#include "fsl_os_abstraction.h"
#include "ble_constants.h"
#include "ble_sig_defines.h"
#include "ble_utils.h"

/************************************************************************************
*************************************************************************************
* Public constants & macros
*************************************************************************************
************************************************************************************/
#if gBLE50_d
/* Maximum number of Advertising sets handled by the Host tables. */
#define gMaxAdvSets_c                           2U
#endif

#define gInvalidDeviceId_c                          (0xFFU)
#define gInvalidNvmIndex_c                          (0xFFU)

/*! Boundary values for the Connection Parameters (Standard GAP). */
#define gcConnectionIntervalMin_c                   (0x0006U)
#define gcConnectionIntervalMax_c                   (0x0C80U)
#define gcConnectionSlaveLatencyMax_c               (0x01F3U)
#define gcConnectionSupervisionTimeoutMin_c         (0x000AU)
#define gcConnectionSupervisionTimeoutMax_c         (0x0C80U)

/*! Default values for the Connection Parameters (Preferred). */

/*! connIntervalmin = Conn_Interval_Min * 1.25 ms */
/*! Value of 0xFFFF indicates no specific minimum. */
#ifndef gcConnectionIntervalMinDefault_c
#define gcConnectionIntervalMinDefault_c            (40U)
#endif

/*! connIntervalmax = Conn_Interval_Max * 1.25 ms */
/*! Value of 0xFFFF indicates no specific maximum. */
#ifndef gcConnectionIntervalMaxDefault_c
#define gcConnectionIntervalMaxDefault_c            (160U)
#endif

#ifndef gcConnectionSlaveLatencyDefault_c
#define gcConnectionSlaveLatencyDefault_c           (0U)
#endif

/*! Time = N * 10 ms */
#ifndef gcConnectionSupervisionTimeoutDefault_c
#define gcConnectionSupervisionTimeoutDefault_c     (2000U)
#endif

/*! Time = N * 0.625 ms */
#ifndef gcConnectionEventMinDefault_c
#define gcConnectionEventMinDefault_c               (0U)
#endif

/*! Time = N * 0.625 ms */
#ifndef gcConnectionEventMaxDefault_c
#define gcConnectionEventMaxDefault_c               (0U)
#endif

/*! When unit testing is performed, access from unit test module to static functions/variables
 * within the tested module is not possible and therefore the static storage class identifier
 * shall be removed */
#ifdef gUnitTesting_d
#define STATIC
#else
#define STATIC static
#endif

/*
 *
 * Device addresses may be:
 *
 * -> public
 * -> random -> static
 *           -> private -> resolvable
 *                      -> non-resolvable
 *
 */

/*! Bluetooth Device Address Types */
#define gBleAddrTypePublic_c    (0x00U) /*!< Public Device Address - fixed into the Controller by the manufacturer. */
#define gBleAddrTypeRandom_c    (0x01U) /*!< Random Device Address - set by the Host into the Controller for privacy reasons. */

/*! PRA condition: check the 6th byte - MSB should be 0; 2nd MSB should be 1. */
#define Ble_IsPrivateResolvableDeviceAddress(bleAddress)  \
    ( ((bleAddress[5]) & (BIT7|BIT6)) == BIT6 )

/*! PNRA condition: check the 6th byte - MSB should be 0; 2nd MSB should be 0. */
#define Ble_IsPrivateNonresolvableDeviceAddress(bleAddress)  \
    ( ((bleAddress[5]) & (BIT7|BIT6)) == 0U )

/*! RSA condition: check the 6th byte - MSB should be 1; 2nd MSB should be 1. */
#define Ble_IsRandomStaticDeviceAddress(bleAddress)  \
    ( ((bleAddress[5]) & (BIT7|BIT6)) == (BIT7|BIT6) )

/*! A macro used to compare two device addresses */
#define Ble_DeviceAddressesMatch(bleAddress1, bleAddress2) \
        FLib_MemCmp(bleAddress1, bleAddress2, gcBleDeviceAddressSize_c)

/*! A macro used to copy device addresses */
#define Ble_CopyDeviceAddress(destinationAddress, sourceAddress) \
        FLib_MemCpy(destinationAddress, sourceAddress, gcBleDeviceAddressSize_c);

#define gBleUuidType16_c                    0x01U        /*!< 16-bit standard UUID */
#define gBleUuidType128_c                   0x02U        /*!< 128-bit long/custom UUID */
#define gBleUuidType32_c                    0x03U        /*!< 32-bit UUID - not available as ATT UUID format */

#define gLePhy1MFlag_c                      BIT0         /*!< Host prefers to use LE 1M Tx/Rx Phy, possibly among others */
#define gLePhy2MFlag_c                      BIT1         /*!< Host prefers to use LE 2M Tx/Rx Phy, possibly among others */
#define gLePhyCodedFlag_c                   BIT2         /*!< Host prefers to use LE Coded Tx/Rx Phy, possibly among others */

/*! Initiator filter policy values */
#define gUseDeviceAddress_c                 0x00U        /*!< Initiates a connection with a specific device identified by its address. */
#define gUseWhiteList_c                     0x01U        /*!< Initiates connections with all the devices in the White List at the same time. */

/*! Scanning filter policy values */
#define gScanAll_c                          0x00U        /*!< Scans all advertising packets. */
#define gScanWithWhiteList_c                0x01U        /*!< Scans advertising packets using the White List. */

/*! Privacy mode values */
#define gNetworkPrivacy_c                   0x00U       /*!< Use Network Privacy Mode for the peer device (default) */
#define gDevicePrivacy_c                    0x01U       /*!< Use Device Privacy Mode for the peer device */

#define gBleMaxActiveConnections (Ble_HostGetGlobalConfig()->connStorageGlobalConfig.bleMaxActiveConnectionsField)

/************************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
************************************************************************************/
/*! BLE result type - the return value of BLE API functions */
typedef enum bleResult_tag
{
    /*
    *
    * Generic result values, base = 0x0000
    *
    */

    gBleStatusBase_c = 0x0000U,                                                              /*!< General status base. */
    gBleSuccess_c                                               = gBleStatusBase_c | 0x00U,  /*!< Function executed successfully. */

    gBleInvalidParameter_c                                      = gBleStatusBase_c | 0x01U,  /*!< Parameter has an invalid value or is outside the accepted range. */
    gBleOverflow_c                                              = gBleStatusBase_c | 0x02U,  /*!< An internal limit is reached. */
    gBleUnavailable_c                                           = gBleStatusBase_c | 0x03U,  /*!< A requested parameter is not available. */
    gBleFeatureNotSupported_c                                   = gBleStatusBase_c | 0x04U,  /*!< The requested feature is not supported by this stack version. */
    gBleOutOfMemory_c                                           = gBleStatusBase_c | 0x05U,  /*!< An internal memory allocation failed. */
    gBleAlreadyInitialized_c                                    = gBleStatusBase_c | 0x06U,  /*!< Ble_HostInitialize function is incorrectly called a second time. */
    gBleOsError_c                                               = gBleStatusBase_c | 0x07U,  /*!< An error occurred at the OS level. */
    gBleUnexpectedError_c                                       = gBleStatusBase_c | 0x08U,  /*!< A "should never get here"-type error occurred. */
    gBleInvalidState_c                                          = gBleStatusBase_c | 0x09U,  /*!< The requested API cannot be called in the current state. */
    gBleTimerError_c                                            = gBleStatusBase_c | 0x0AU,  /*!< Timer allocation failed. */

    /*
    *
    * HCI result values
    *
    */

    gHciStatusBase_c = 0x0100U,
    gHciSuccess_c                                               = gBleSuccess_c,
    /* HCI standard status codes */
    gHciUnknownHciCommand_c                                     = gHciStatusBase_c | 0x01U,
    gHciUnknownConnectionIdentifier_c                           = gHciStatusBase_c | 0x02U,
    gHciHardwareFailure_c                                       = gHciStatusBase_c | 0x03U,
    gHciPageTimeout_c                                           = gHciStatusBase_c | 0x04U,
    gHciAuthenticationFailure_c                                 = gHciStatusBase_c | 0x05U,
    gHciPinOrKeyMissing_c                                       = gHciStatusBase_c | 0x06U,
    gHciMemoryCapacityExceeded_c                                = gHciStatusBase_c | 0x07U,
    gHciConnectionTimeout_c                                     = gHciStatusBase_c | 0x08U,
    gHciConnectionLimitExceeded_c                               = gHciStatusBase_c | 0x09U,
    gHciSynchronousConnectionLimitToADeviceExceeded_c           = gHciStatusBase_c | 0x0AU,
    gHciAclConnectionAlreadyExists_c                            = gHciStatusBase_c | 0x0BU,
    gHciCommandDisallowed_c                                     = gHciStatusBase_c | 0x0CU,
    gHciConnectionRejectedDueToLimitedResources_c               = gHciStatusBase_c | 0x0DU,
    gHciConnectionRejectedDueToSecurityReasons_c                = gHciStatusBase_c | 0x0EU,
    gHciConnectionRejectedDueToUnacceptableBdAddr_c             = gHciStatusBase_c | 0x0FU,
    gHciConnectionAcceptTimeoutExceeded_c                       = gHciStatusBase_c | 0x10U,
    gHciUnsupportedFeatureOrParameterValue_c                    = gHciStatusBase_c | 0x11U,
    gHciInvalidHciCommandParameters_c                           = gHciStatusBase_c | 0x12U,
    gHciRemoteUserTerminatedConnection_c                        = gHciStatusBase_c | 0x13U,
    gHciRemoteDeviceTerminatedConnectionLowResources_c          = gHciStatusBase_c | 0x14U,
    gHciRemoteDeviceTerminatedConnectionPowerOff_c              = gHciStatusBase_c | 0x15U,
    gHciConnectionTerminatedByLocalHost_c                       = gHciStatusBase_c | 0x16U,
    gHciRepeatedAttempts_c                                      = gHciStatusBase_c | 0x17U,
    gHciPairingNotAllowed_c                                     = gHciStatusBase_c | 0x18U,
    gHciUnknownLpmPdu_c                                         = gHciStatusBase_c | 0x19U,
    gHciUnsupportedRemoteFeature_c                              = gHciStatusBase_c | 0x1AU,
    gHciScoOffsetRejected_c                                     = gHciStatusBase_c | 0x1BU,
    gHciScoIntervalRejected_c                                   = gHciStatusBase_c | 0x1CU,
    gHciScoAirModeRejected_c                                    = gHciStatusBase_c | 0x1DU,
    gHciInvalidLpmParameters_c                                  = gHciStatusBase_c | 0x1EU,
    gHciUnspecifiedError_c                                      = gHciStatusBase_c | 0x1FU,
    gHciUnsupportedLpmParameterValue_c                          = gHciStatusBase_c | 0x20U,
    gHciRoleChangeNotAllowed_c                                  = gHciStatusBase_c | 0x21U,
    gHciLLResponseTimeout_c                                     = gHciStatusBase_c | 0x22U,
    gHciLmpErrorTransactionCollision_c                          = gHciStatusBase_c | 0x23U,
    gHciLmpPduNotAllowed_c                                      = gHciStatusBase_c | 0x24U,
    gHciEncryptionModeNotAcceptable_c                           = gHciStatusBase_c | 0x25U,
    gHciLinkKeyCannotBeChanged_c                                = gHciStatusBase_c | 0x26U,
    gHciRequestedQosNotSupported_c                              = gHciStatusBase_c | 0x27U,
    gHciInstantPassed_c                                         = gHciStatusBase_c | 0x28U,
    gHciPairingWithUnitKeyNotSupported_c                        = gHciStatusBase_c | 0x29U,
    gHciDifferentTransactionCollision_c                         = gHciStatusBase_c | 0x2AU,
    gHciReserved_0x2B_c                                         = gHciStatusBase_c | 0x2BU,
    gHciQosNotAcceptableParameter_c                             = gHciStatusBase_c | 0x2CU,
    gHciQosRejected_c                                           = gHciStatusBase_c | 0x2DU,
    gHciChannelClassificationNotSupported_c                     = gHciStatusBase_c | 0x2EU,
    gHciInsufficientSecurity_c                                  = gHciStatusBase_c | 0x2FU,
    gHciParameterOutOfMandatoryRange_c                          = gHciStatusBase_c | 0x30U,
    gHciReserved_0x31_c                                         = gHciStatusBase_c | 0x31U,
    gHciRoleSwitchPending_c                                     = gHciStatusBase_c | 0x32U,
    gHciReserved_0x33_c                                         = gHciStatusBase_c | 0x33U,
    gHciReservedSlotViolation_c                                 = gHciStatusBase_c | 0x34U,
    gHciRoleSwitchFailed_c                                      = gHciStatusBase_c | 0x35U,
    gHciExtendedInquiryResponseTooLarge_c                       = gHciStatusBase_c | 0x36U,
    gHciSecureSimplePairingNotSupportedByHost_c                 = gHciStatusBase_c | 0x37U,
    gHciHostBusyPairing_c                                       = gHciStatusBase_c | 0x38U,
    gHciConnectionRejectedDueToNoSuitableChannelFound_c         = gHciStatusBase_c | 0x39U,
    gHciControllerBusy_c                                        = gHciStatusBase_c | 0x3AU,
    gHciUnacceptableConnectionParameters_c                      = gHciStatusBase_c | 0x3BU,
    gHciDirectedAdvertisingTimeout_c                            = gHciStatusBase_c | 0x3CU,
    gHciConnectionTerminatedDueToMicFailure_c                   = gHciStatusBase_c | 0x3DU,
    gHciConnectionFailedToBeEstablishedOrSyncTimeout_c          = gHciStatusBase_c | 0x3EU,
    gHciMacConnectionFailed_c                                   = gHciStatusBase_c | 0x3FU,
    gHciCoarseClockAdjustmentRejected_c                         = gHciStatusBase_c | 0x40U,
    gHciType0SubmapNotDefined_c                                 = gHciStatusBase_c | 0x41U,
    gHciUnknownAdvertisingIdentifier_c                          = gHciStatusBase_c | 0x42U,
    gHciLimitReached_c                                          = gHciStatusBase_c | 0x43U,
    gHciOperationCancelledByHost_c                              = gHciStatusBase_c | 0x44U,

    /* HCI internal status codes */
    gHciAlreadyInit_c                                           = gHciStatusBase_c | 0xA0U,
    gHciInvalidParameter_c                                      = gHciStatusBase_c | 0xA1U,
    gHciCallbackNotInstalled_c                                  = gHciStatusBase_c | 0xA2U,
    gHciCallbackAlreadyInstalled_c                              = gHciStatusBase_c | 0xA3U,
    gHciCommandNotSupported_c                                   = gHciStatusBase_c | 0xA4U,
    gHciEventNotSupported_c                                     = gHciStatusBase_c | 0xA5U,
    gHciTransportError_c                                        = gHciStatusBase_c | 0xA6U,

    /*
    *
    * Controller result values
    *
    */
    gCtrlStatusBase_c = 0x0200U,
    gCtrlSuccess_c                                              = gBleSuccess_c,

    /*
    *
    * L2CAP result values
    *
    */
    gL2caStatusBase_c = 0x0300U,
    gL2caSuccess_c                                              = gBleSuccess_c,
    /* L2CAP standard status codes */

    /* L2CAP internal status codes */
    gL2caAlreadyInit_c                                          = gL2caStatusBase_c | 0xF0U,
    gL2caInsufficientResources_c                                = gL2caStatusBase_c | 0xF1U,
    gL2caCallbackNotInstalled_c                                 = gL2caStatusBase_c | 0xF2U,
    gL2caCallbackAlreadyInstalled_c                             = gL2caStatusBase_c | 0xF3U,
    gL2caLePsmInvalid_c                                         = gL2caStatusBase_c | 0xF4U,
    gL2caLePsmAlreadyRegistered_c                               = gL2caStatusBase_c | 0xF5U,
    gL2caLePsmNotRegistered_c                                   = gL2caStatusBase_c | 0xF6U,
    gL2caLePsmInsufficientResources_c                           = gL2caStatusBase_c | 0xF7U,
    gL2caChannelInvalid_c                                       = gL2caStatusBase_c | 0xF8U,
    gL2caChannelClosed_c                                        = gL2caStatusBase_c | 0xF9U,
    gL2caChannelAlreadyConnected_c                              = gL2caStatusBase_c | 0xFAU,
    gL2caConnectionParametersRejected_c                         = gL2caStatusBase_c | 0xFBU,
    gL2caChannelBusy_c                                          = gL2caStatusBase_c | 0xFCU,

    gL2caInvalidParameter_c                                     = gL2caStatusBase_c | 0xFEU,
    gL2caError_c                                                = gL2caStatusBase_c | 0xFFU,

    /*
    *
    * SMP result values
    *
    */
    gSmStatusBase_c = 0x0400U,
    gSmSuccess_c                                                = gBleSuccess_c,

    gSmNullCBFunction_c                                         = gSmStatusBase_c | 0x01U,
    gSmCommandNotSupported_c                                    = gSmStatusBase_c | 0x02U, /*!< The Security Manager (SM) does not have the required features or version to support this command */
    gSmUnexpectedCommand_c                                      = gSmStatusBase_c | 0x03U, /*!< This command is not or cannot be handled in the current context of the SM.  */
    gSmInvalidCommandCode_c                                     = gSmStatusBase_c | 0x04U, /*!< The provided SM command code is invalid. */
    gSmInvalidCommandLength_c                                   = gSmStatusBase_c | 0x05U, /*!< The provided command length is not valid for the SM command code. */
    gSmInvalidCommandParameter_c                                = gSmStatusBase_c | 0x06U, /*!< One of the parameters of the SM command is not valid. */
    gSmInvalidDeviceId_c                                        = gSmStatusBase_c | 0x07U, /*!< The provided Device ID is invalid. */
    gSmInvalidInternalOperation_c                               = gSmStatusBase_c | 0x08U, /*!< There is a problem with the internal state of the SM. This should not happen during normal operation.
                                                                                           *   A memory corruption or invalid operation may have occurred.  */
    gSmInvalidConnectionHandle_c                                = gSmStatusBase_c | 0x09U, /*!< The target device does not have a valid connection handle. It might be disconnected. */
    gSmInproperKeyDistributionField_c                           = gSmStatusBase_c | 0x0AU, /*!< The Responder upper layer has set to "1" one or more flags in the Initiator or Responder Key Distribution Fields
                                                                                           *   from the Pairing Request which were set to "0" by the peer device. */
    gSmUnexpectedKeyType_c                                      = gSmStatusBase_c | 0x0BU, /*!< The Responder upper layer has set a key type field in the Passkey Request Reply
                                                                                           *   command, which is different than the field negotiated with the peer device. */
    gSmUnexpectedPairingTerminationReason_c                     = gSmStatusBase_c | 0x0CU, /*!< The upper layer tried to cancel the pairing procedure with an unexpected
                                                                                           *   pairing failure reason for the current phase of the pairing procedure. */
    gSmUnexpectedKeyset_c                                       = gSmStatusBase_c | 0x0DU, /*!< The Responder upper layer is trying to distribute keys which were not requested during the pairing procedure
                                                                                           *   or the peer device has sent a Key Distribution packet which was not expected. */
    gSmSmpTimeoutOccurred_c                                     = gSmStatusBase_c | 0x0EU, /*!< An SMP timeout has occurred for the peer device.
                                                                                           *   No more operations are accepted until a new physical link is established. */
    gSmUnknownSmpPacketType_c                                   = gSmStatusBase_c | 0x0FU, /*!< An SMP packet with an unknown (or invalid) type has been received. */
    gSmInvalidSmpPacketLength_c                                 = gSmStatusBase_c | 0x10U, /*!< An SMP packet with an invalid length for the SMP packet type has been received. */
    gSmInvalidSmpPacketParameter_c                              = gSmStatusBase_c | 0x11U, /*!< An SMP packet with an invalid parameter has been received. */
    gSmReceivedUnexpectedSmpPacket_c                            = gSmStatusBase_c | 0x12U, /*!< An unexpected SMP packet was received. */
    gSmReceivedSmpPacketFromUnknownDevice_c                     = gSmStatusBase_c | 0x13U, /*!< An SMP packet is received but the source Device ID cannot be identified. */
    gSmReceivedUnexpectedHciEvent_c                             = gSmStatusBase_c | 0x14U, /*!< An HCI event has been received which cannot be handled by the SM or cannot be
                                                                                           *   handled in the current context. */
    gSmReceivedHciEventFromUnknownDevice_c                      = gSmStatusBase_c | 0x15U, /*!< An HCI event is received but the source Device ID cannot be identified. */
    gSmInvalidHciEventParameter_c                               = gSmStatusBase_c | 0x16U, /*!< An HCI Event is received with an invalid parameter. */
    gSmLlConnectionEncryptionInProgress_c                       = gSmStatusBase_c | 0x17U, /*!< A Link Layer Connection encryption was requested by the upper layer or attempted internally by
                                                                                           *   the SM, but it could no be completed because an encryption was already in progress.
                                                                                           *   This situation could lead to an SMP Pairing Failure when the SM cannot encrypt the
                                                                                           *   link with the STK. An unspecified pairing failure reason is used in this instance. */
    gSmLlConnectionEncryptionFailure_c                          = gSmStatusBase_c | 0x18U, /*!< The Link Layer connection encryption procedure has failed. */
    gSmInsufficientResources_c                                  = gSmStatusBase_c | 0x19U, /*!< The SM could not allocate resources to perform operations (memory or timers). */
    /* LE SC statuses. */
    gSmOobDataAddressMismatch_c                                 = gSmStatusBase_c | 0x1AU, /*!< The address of the peer contained in the remote OOB data sent to the stack does not match
                                                                                           *   the address used by the remote device for the connection/pairing procedure. */
    gSmSmpPacketReceivedAfterTimeoutOccurred_c                  = gSmStatusBase_c | 0x1BU, /*!< A SMP packet has been received from a peer device for which a pairing procedure has timed out.
                                                                                           *   No further operations are permitted until a new connection is established. */
    gSmReceivedTimerEventForUnknownDevice_c                     = gSmStatusBase_c | 0x1CU, /*!< An Timer event is received but the source Device ID cannot be identified. */
    gSmUnattainableLocalDeviceSecRequirements_c                 = gSmStatusBase_c | 0x1DU, /*!< The provided pairing parameters cannot lead to a Pairing Procedure which satisfies the minimum
                                                                                               security properties for the local device. */
    gSmUnattainableLocalDeviceMinKeySize_c                      = gSmStatusBase_c | 0x1EU, /*!< The provided pairing parameters cannot lead to a Pairing Procedure which satisfies the minimum
                                                                                               encryption key size for the local device. */
    gSmUnattainableSlaveSecReqRequirements_c                    = gSmStatusBase_c | 0x1FU, /*!< The provided pairing parameters cannot lead to a Pairing Procedure which satisfies the minimum
                                                                                               security properties requested by the local device via a SMP Slave Security Request. */

    /* Added for the GAP layer to signal the application about pairing failed reasons. */
    gSmPairingErrorPasskeyEntryFailed_c                         = gSmStatusBase_c | 0x31U,
    gSmPairingErrorConfirmValueFailed_c                         = gSmStatusBase_c | 0x32U,
    gSmPairingErrorCommandNotSupported_c                        = gSmStatusBase_c | 0x33U,
    gSmPairingErrorInvalidParameters_c                          = gSmStatusBase_c | 0x34U,
    gSmPairingErrorUnknownReason_c                              = gSmStatusBase_c | 0x35U,
    gSmPairingErrorTimeout_c                                    = gSmStatusBase_c | 0x36U,
    gSmPairingErrorAuthenticationRequirements_c                 = gSmStatusBase_c | 0x37U,
    gSmPairingAlreadyStarted_c                                  = gSmStatusBase_c | 0x38U,

    /* SM Tool Box statuses. */
    gSmTbResolvableAddressDoesNotMatchIrk_c                     = gSmStatusBase_c | 0x60U, /*!< The provided Resolvable Private Address and IRK do not match. */
    gSmTbInvalidDataSignature_c                                 = gSmStatusBase_c | 0x61U, /*!< The provided data signature does not match the computed data signature. */

    /*
    *
    * ATT result values
    *
    */
    gAttStatusBase_c = 0x0500U,                                                      /*!< ATT status base. */
    gAttSuccess_c                                               = gBleSuccess_c,    /*!< Alias. */

    /* ATT error codes as defined in "att_errors.h" are added to the gAttStatusBase_c. */

    /*
    *
    * GATT result values
    *
    */
    gGattStatusBase_c = 0x0600U,                                                         /*!< GATT status base. */
    gGattSuccess_c                                              = gBleSuccess_c,        /*!< Alias.  */

    gGattAnotherProcedureInProgress_c                     = gGattStatusBase_c | 0x01U,   /*!< Trying to start a GATT procedure while one is already in progress. */
    gGattLongAttributePacketsCorrupted_c                  = gGattStatusBase_c | 0x02U,   /*!< Writing a Long Characteristic failed because Prepare Write Request packets were corrupted. */
    gGattMultipleAttributesOverflow_c                     = gGattStatusBase_c | 0x03U,   /*!< Too many Characteristics are given for a Read Multiple Characteristic procedure. */
    gGattUnexpectedReadMultipleResponseLength_c           = gGattStatusBase_c | 0x04U,   /*!< Read Multiple Characteristic procedure failed because unexpectedly long data was read. */
    gGattInvalidValueLength_c                             = gGattStatusBase_c | 0x05U,   /*!< An invalid value length was supplied to a Characteristic Read/Write operation. */
    gGattServerTimeout_c                                  = gGattStatusBase_c | 0x06U,   /*!< No response was received from the Server. */

    gGattIndicationAlreadyInProgress_c                    = gGattStatusBase_c | 0x07U,   /*!< A Server Indication is already waiting for Client Confirmation. */
    gGattClientConfirmationTimeout_c                      = gGattStatusBase_c | 0x08U,   /*!< No Confirmation was received from the Client after a Server Indication. */

    gGattInvalidPduReceived_c                             = gGattStatusBase_c | 0x09U,   /*!< An invalid PDU length was received. */
    gGattPeerDisconnected_c                               = gGattStatusBase_c | 0x0AU,   /*!< An ongoing GATT procedure could not be finished due to peer's disconnection. */
    gGattMtuExchangeInProgress_c                          = gGattStatusBase_c | 0x0BU,   /*!< A Server Indication is already waiting for Client Confirmation. */
    gGattConnectionSecurityRequirementsNotMet_c           = gGattStatusBase_c | 0x0DU,   /*!< Client cannot initiate communication if the device security requirements are not met,
                                                                                               e.g., link is not yet encrypted/authenticated. */
    /*
    *
    * GAP result values
    *
    */
    gGapStatusBase_c = 0x0700U,                                                          /*!< GAP status base. */
    gGapSuccess_c                                               = gBleSuccess_c,        /*!< Alias. */

    gGapAdvDataTooLong_c                                  = gGapStatusBase_c | 0x01U,    /*!< Trying to set too many bytes in the advertising payload. */
    gGapScanRspDataTooLong_c                              = gGapStatusBase_c | 0x02U,    /*!< Trying to set too many bytes in the scan response payload. */
    gGapDeviceNotBonded_c                                 = gGapStatusBase_c | 0x03U,    /*!< Trying to execute an API that is only available for bonded devices. */
    gGapAnotherProcedureInProgress_c                      = gGapStatusBase_c | 0x04U,    /*!< Trying to start a GAP procedure while one is already in progress. */

    /*
    *
    * Reserved result values
    *
    */
    gDevDbStatusBase_c = 0x0800U,                                                                /*!< DeviceDatabase status base. */
    gDevDbSuccess_c                                             = gBleSuccess_c,                /*!< Alias. */

    gDevDbCccdLimitReached_c                                    = gDevDbStatusBase_c | 0x01U,    /*!< CCCD value cannot be saved because Server's CCCD list is full for the current client. */
    gDevDbCccdNotFound_c                                        = gDevDbStatusBase_c | 0x02U,    /*!< CCCD with the given handle is not found in the Server's list for the current client. */

    /*
    *
    * GATT_DB result values
    *
    */
    gGattDbStatusBase_c = 0x0900U,                                                               /*!< GATT Database status base. */
    gGattDbSuccess_c                                            = gBleSuccess_c,                /*!< Alias. */

    gGattDbInvalidHandle_c                                      = gGattDbStatusBase_c | 0x01U,   /*!< An invalid handle was passed as parameter. */
    gGattDbCharacteristicNotFound_c                             = gGattDbStatusBase_c | 0x02U,   /*!< Characteristic was not found. */
    gGattDbCccdNotFound_c                                       = gGattDbStatusBase_c | 0x03U,   /*!< CCCD was not found. */
    gGattDbServiceNotFound_c                                    = gGattDbStatusBase_c | 0x04U,   /*!< Service Declaration was not found. */
    gGattDbDescriptorNotFound_c                                 = gGattDbStatusBase_c | 0x05U,   /*!< Characteristic Descriptor was not found. */

} bleResult_t;

/*! Unique identifier type for a connected device. */
typedef uint8_t deviceId_t;

/*! Bluetooth Device Address Type - Size: 1 Octet, Range: [gBleAddrTypePublic_c:gBleAddrTypeRandom_c] */
typedef uint8_t bleAddressType_t;

/*! Bluetooth Device Address - array of 6 bytes. */
typedef uint8_t bleDeviceAddress_t[gcBleDeviceAddressSize_c];

/*! Bluetooth Identity Address - array of 6 bytes. */
typedef struct
{
    bleAddressType_t    idAddressType; /*!< Public or Random (static). */
    bleDeviceAddress_t  idAddress;     /*!< 6-byte address. */
} bleIdentityAddress_t;

/*! Bluetooth UUID type - values chosen to correspond with the ATT UUID format */
typedef uint8_t bleUuidType_t;

/*! Union for a Bluetooth UUID; selected according to an accompanying bleUuidType_t */
typedef union {
    uint16_t    uuid16;         /*!< For gBleUuidType16_c. */
    uint32_t    uuid32;         /*!< For gBleUuidType32_c. */
    uint8_t     uuid128[16];    /*!< For gBleUuidType128_c. */
} bleUuid_t;

/*! Advertising Type */
typedef enum {
    gAdvConnectableUndirected_c                 = 0x00U,     /*!< Answers to both connect and scan requests. */
    gAdvDirectedHighDutyCycle_c                 = 0x01U,     /*!< Answers only to connect requests; smaller advertising interval for quicker connection. */
    gAdvScannable_c                             = 0x02U,     /*!< Answers only to scan requests. */
    gAdvNonConnectable_c                        = 0x03U,     /*!< Does not answer to connect nor scan requests. */
    gAdvDirectedLowDutyCycle_c                  = 0x04U      /*!< Answers only to connect requests; larger advertising interval. */
} bleAdvertisingType_t;

/*! Advertising Event properties */
typedef uint16_t bleAdvReportEventProperties_t;
typedef enum
{
    gAdvEventConnectable_c    = BIT0, /*!< Connectable Advertisement */
    gAdvEventScannable_c      = BIT1, /*!< Scannable Advertisement */
    gAdvEventDirected_c       = BIT2, /*!< Directed Advertisement */
    gAdvEventScanResponse_c   = BIT3, /*!< Scan Response */
    gAdvEventLegacy_c         = BIT4, /*!< Legacy Advertisement PDU */
    gAdvEventAnonymous_c      = BIT5, /*!< Anonymous Advertisement */
} bleAdvReportEventProperties_tag;

/*! Advertising Request properties */
typedef uint16_t bleAdvRequestProperties_t;
typedef enum
{
    gAdvReqConnectable_c    = BIT0, /*!< Connectable Advertising */
    gAdvReqScannable_c      = BIT1, /*!< Scannable Advertising */
    gAdvReqDirected_c       = BIT2, /*!< Directed Advertising */
    gAdvReqHighDutyCycle_c  = BIT3, /*!< High Duty Cycle */
    gAdvReqLegacy_c         = BIT4, /*!< Legacy Advertising PDU */
    gAdvReqAnonymous_c      = BIT5, /*!< Anonymous Advertising */
    gAdvIncludeTxPower_c    = BIT6, /*!< Set this option to include the Tx power in advertising packet. */
} bleAdvRequestProperties_tag;

typedef struct
{
    uint8_t     enableChannel37:    1;  /*!< Bit for channel 37. */
    uint8_t     enableChannel38:    1;  /*!< Bit for channel 38. */
    uint8_t     enableChannel39:    1;  /*!< Bit for channel 39. */
    uint8_t     reserved:           5;  /*!< Reserved for future use. */
} bleAdvertisingChannelMap_t;

typedef enum
{
    gBleAdvFilterAllowScanFromAnyAllowConnFromAny_c     = 0x00U,     /*!< White List is ignored. */
    gBleAdvFilterAllowScanFromWLAllowConnFromAny_c      = 0x01U,     /*!< White List is used only for Scan Requests. */
    gBleAdvFilterAllowScanFromAnyAllowConnFromWL_c      = 0x02U,     /*!< White List is used only for Connection Requests. */
    gBleAdvFilterAllowScanFromWLAllowConnFromWL_c       = 0x03U,     /*!< White List is used for both Scan and Connection Requests. */
} bleAdvertisingFilterPolicy_t;

typedef enum
{
    gBleLlConnectionMaster_c        = 0x00U, /*!< Link Layer Master Role */
    gBleLlConnectionSlave_c         = 0x01U, /*!< Link Layer Slave Role */
} bleLlConnectionRole_t;

typedef uint8_t bleMasterClockAccuracy_t;
typedef enum
{
    gBleMasterClkAcc500ppm_c        = 0x00U,
    gBleMasterClkAcc250ppm_c        = 0x01U,
    gBleMasterClkAcc150ppm_c        = 0x02U,
    gBleMasterClkAcc100ppm_c        = 0x03U,
    gBleMasterClkAcc75ppm_c         = 0x04U,
    gBleMasterClkAcc50ppm_c         = 0x05U,
    gBleMasterClkAcc30ppm_c         = 0x06U,
    gBleMasterClkAcc20ppm_c         = 0x07U,
} bleMasterClockAccuracy_tag;

typedef enum
{
    gBleAdvRepAdvInd_c              = 0x00U, /* Connectable undirected advertising (ADV_IND) */
    gBleAdvRepAdvDirectInd_c        = 0x01U, /* Connectable directed advertising (ADV_DIRECT_IND) */
    gBleAdvRepAdvScanInd_c          = 0x02U, /* Scannable undirected advertising (ADV_SCAN_IND) */
    gBleAdvRepAdvNonconnInd_c       = 0x03U, /* Non Connectable undirected advertising (ADV_NONCONN_IND) */
    gBleAdvRepScanRsp_c             = 0x04U, /* Scan Response (SCAN_RSP) */
} bleAdvertisingReportEventType_t;

typedef enum
{
    gHciCommandPacket_c          = 0x01U, /*!<  HCI Command */
    gHciDataPacket_c             = 0x02U, /*!<  L2CAP Data Packet */
    gHciSynchronousDataPacket_c  = 0x03U, /*!<  Not used in BLE */
    gHciEventPacket_c            = 0x04U, /*!<  HCI Event */
} hciPacketType_t;

/*! Scanning type enumeration. */
typedef enum {
    gScanTypePassive_c   = 0x00U,     /*!< Passive Scanning - advertising packets are immediately reported to the Host. */
    gScanTypeActive_c    = 0x01U      /*!< Active Scanning - the scanner sends scan requests to the advertiser and reports to the Host after the scan response is received. */
} bleScanType_t;

/*! Scanning filter policy enumeration - Size: 1 Octet, Range: [gScanAll_c:gScanWithWhiteList_c] */
typedef uint8_t bleScanningFilterPolicy_t;

/*! Initiator filter policy enumeration - Size: 1 Octet, Range: [gUseDeviceAddress_c:gUseWhiteList_c] */
typedef uint8_t bleInitiatorFilterPolicy_t;

/*! Privacy Mode enumeration - Size: 1 Octet, Range: [gNetworkPrivacy_c:gDevicePrivacy_c] */
typedef uint8_t blePrivacyMode_t;

typedef enum
{
    gReadCurrentTxPowerLevel_c   = 0x00U, /*!< Current TX Power level. */
    gReadMaximumTxPowerLevel_c   = 0x01U, /*!< Maximum recorded TX Power level. */
} bleTransmitPowerLevelType_t;

typedef enum
{
    gTxPowerAdvChannel_c         = 0x00U, /*!< Advertising channel type when setting Tx Power. */
    gTxPowerConnChannel_c        = 0x01U, /*!< Connection channel type when setting Tx Power. */
} bleTransmitPowerChannelType_t;

typedef enum
{
    gBleFreq2402MHz_c       = 0x00U,
    gBleFreq2404MHz_c       = 0x01U,
    gBleFreq2406MHz_c       = 0x02U,
    gBleFreq2408MHz_c       = 0x03U,
    gBleFreq2410MHz_c       = 0x04U,
    gBleFreq2412MHz_c       = 0x05U,
    gBleFreq2414MHz_c       = 0x06U,
    gBleFreq2416MHz_c       = 0x07U,
    gBleFreq2418MHz_c       = 0x08U,
    gBleFreq2420MHz_c       = 0x09U,
    gBleFreq2422MHz_c       = 0x0AU,
    gBleFreq2424MHz_c       = 0x0BU,
    gBleFreq2426MHz_c       = 0x0CU,
    gBleFreq2428MHz_c       = 0x0DU,
    gBleFreq2430MHz_c       = 0x0EU,
    gBleFreq2432MHz_c       = 0x0FU,
    gBleFreq2434MHz_c       = 0x10U,
    gBleFreq2436MHz_c       = 0x11U,
    gBleFreq2438MHz_c       = 0x12U,
    gBleFreq2440MHz_c       = 0x13U,
    gBleFreq2442MHz_c       = 0x14U,
    gBleFreq2444MHz_c       = 0x15U,
    gBleFreq2446MHz_c       = 0x16U,
    gBleFreq2448MHz_c       = 0x17U,
    gBleFreq2450MHz_c       = 0x18U,
    gBleFreq2452MHz_c       = 0x19U,
    gBleFreq2454MHz_c       = 0x1AU,
    gBleFreq2456MHz_c       = 0x1BU,
    gBleFreq2458MHz_c       = 0x1CU,
    gBleFreq2460MHz_c       = 0x1DU,
    gBleFreq2462MHz_c       = 0x1EU,
    gBleFreq2464MHz_c       = 0x1FU,
    gBleFreq2466MHz_c       = 0x20U,
    gBleFreq2468MHz_c       = 0x21U,
    gBleFreq2470MHz_c       = 0x22U,
    gBleFreq2472MHz_c       = 0x23U,
    gBleFreq2474MHz_c       = 0x24U,
    gBleFreq2476MHz_c       = 0x25U,
    gBleFreq2478MHz_c       = 0x26U,
    gBleFreq2480MHz_c       = 0x27U,
} bleChannelFrequency_t;

/*! Bluetooth Channel map - array of 5 bytes. */
typedef uint8_t bleChannelMap_t[gcBleChannelMapSize_c];

typedef enum
{
    gBleTestPacketPayloadPrbs9_c            = 0x00U,
    gBleTestPacketPayloadPattern11110000_c  = 0x01U,
    gBleTestPacketPayloadPattern10101010_c  = 0x02U,
    gBleTestPacketPayloadPrbs15_c           = 0x03U,
    gBleTestPacketPayloadPatternAllBits1_c  = 0x04U,
    gBleTestPacketPayloadPatternAllBits0_c  = 0x05U,
    gBleTestPacketPayloadPattern00001111_c  = 0x06U,
    gBleTestPacketPayloadPattern01010101_c  = 0x07U,
} bleTxTestPacketPayload_t;

typedef enum
{
    bleHwErrCodeNoError_c                   = 0x00U,
} bleHardwareErrorCode_t;

typedef struct
{
    uint8_t     randomValue[gSmpLeScRandomValueSize_c];          /*!< LE SC OOB r (Random value) */
    uint8_t     confirmValue[gSmpLeScRandomConfirmValueSize_c];  /*!< LE SC OOB Cr (Random Confirm value) */
} gapLeScOobData_t;

/*! Generic Event Type */
typedef enum {
    gInitializationComplete_c,                  /*!< Initial setup started by Ble_HostInitialize is complete. */
    gInternalError_c,                           /*!< An internal error occurred. */
    gAdvertisingSetupFailed_c,                  /*!< Error during advertising setup. */
    gAdvertisingParametersSetupComplete_c,      /*!< Advertising parameters have been successfully set. Response to Gap_SetAdvertisingParameters. */
    gAdvertisingDataSetupComplete_c,            /*!< Advertising and/or scan response data has been successfully set. Response to Gap_SetAdvertisingData. */
    gWhiteListSizeRead_c,                       /*!< Contains the White List size. Response to Gap_ReadWhiteListSize. */
    gDeviceAddedToWhiteList_c,                  /*!< Device has been added to White List. Response to Gap_AddDeviceToWhiteList. */
    gDeviceRemovedFromWhiteList_c,              /*!< Device has been removed from the White List. Response to Gap_RemoveDeviceFromWhiteList. */
    gWhiteListCleared_c,                        /*!< White List has been cleared. Response to Gap_ClearWhiteList. */
    gRandomAddressReady_c,                      /*!< A random device address has been created. Response to Gap_CreateRandomDeviceAddress. */
    gCreateConnectionCanceled_c,                /*!< Connection initiation was successfully cancelled. Response to Gap_CancelInitiatingConnection. */
    gPublicAddressRead_c,                       /*!< Contains the public device address. Response to Gap_ReadPublicDeviceAddress. */
    gAdvTxPowerLevelRead_c,                     /*!< Contains the TX power on the advertising channel. Response to Gap_ReadAdvertisingTxPowerLevel. */
    gPrivateResolvableAddressVerified_c,        /*!< Contains the result of PRA verification. Response to Gap_VerifyPrivateResolvableAddress. */
    gRandomAddressSet_c,                        /*!< Random address has been set into the Controller. Response to Gap_SetRandomAddress. */
    gControllerResetComplete_c,                 /*!< Controller has been successfully reset. */
    gLeScPublicKeyRegenerated_c,                /*!< The private/public key pair used for LE Secure Connections pairing has been regenerated. */
    gLeScLocalOobData_c,                        /*!< Local OOB data used for LE Secure Connections pairing. */
    gHostPrivacyStateChanged_c,                 /*!< Host Privacy was enabled or disabled. */
    gControllerPrivacyStateChanged_c,           /*!< Controller Privacy was enabled or disabled. */
    gControllerTestEvent_c,                     /*!< Controller Test was started or stopped. */
    gTxPowerLevelSetComplete_c,                 /*!< Controller Tx Power Level set complete or invalid. */
    gLePhyEvent_c,                              /*!< Phy Mode of a connection has been updated by the Controller. */
    gControllerNotificationEvent_c,             /*!< Controller Enhanced Notification received.*/
    gBondCreatedEvent_c,                        /*!< Bond Created Event signalling the stack created a bond after pairing or at app request.*/
    gChannelMapSet_c,                           /*!< Channel map set complete in the Controller. */

    gExtAdvertisingParametersSetupComplete_c,   /*!< Extended advertising parameters have been successfully set. */
    gExtAdvertisingDataSetupComplete_c,         /*!< Extended advertising data has been successfully set. */
    gExtAdvertisingSetRemoveComplete_c,         /*!< An advertising set has been removed from the Controller. */
    gPeriodicAdvParamSetupComplete_c,           /*!< Periodic advertising parameters have been successfully set. */
    gPeriodicAdvDataSetupComplete_c,            /*!< Periodic advertising data have been successfully set. */
    gPeriodicAdvListUpdateComplete_c,           /*!< Periodic advertiser list has been successfully updated. */
    gPeriodicAdvCreateSyncCancelled_c,          /*!< Periodic advertising create sync command was successfully cancelled */
    gTxEntryAvailable_c                         /*!< This event is generated when a TX entry becomes available after they were all in use. */
} gapGenericEventType_t;

/*! Internal Error Source - the command that triggered the error */
typedef enum {
    gHciCommandStatus_c,
    gCheckPrivateResolvableAddress_c,
    gVerifySignature_c,
    gAddNewConnection_c,
    gResetController_c,
    gSetEventMask_c,
    gReadLeBufferSize_c,
    gSetLeEventMask_c,
    gReadDeviceAddress_c,
    gReadLocalSupportedFeatures_c,
    gReadWhiteListSize_c,
    gClearWhiteList_c,
    gAddDeviceToWhiteList_c,
    gRemoveDeviceFromWhiteList_c,
    gCancelCreateConnection_c,
    gReadRadioPower_c,
    gSetRandomAddress_c,
    gCreateRandomAddress_c,
    gEncryptLink_c,
    gProvideLongTermKey_c,
    gDenyLongTermKey_c,
    gConnect_c,
    gDisconnect_c,
    gTerminatePairing_c,
    gSendSlaveSecurityRequest_c,
    gEnterPasskey_c,
    gProvideOob_c,
    gSendSmpKeys_c,
    gWriteSuggestedDefaultDataLength_c,
    gReadSuggestedDefaultDataLength_c,
    gUpdateLeDataLength_c,
    gEnableHostPrivacy_c,
    gEnableControllerPrivacy_c,
    gLeScSendKeypressNotification_c,
    gLeScSetPeerOobData_c,
    gLeScGetLocalOobData_c,
    gLeScValidateNumericValue_c,
    gLeScRegeneratePublicKey_c,
    gLeSetResolvablePrivateAddressTimeout_c,
    gDefaultPairingProcedure_c,
    gLeControllerTest_c,
    gLeReadPhy_c,
    gLeSetPhy_c,
    gSaveKeys_c,
    gSetChannelMap_c,
    gReadLocalSupportedCommands_c,
    gEnableLdmTimer_c,
    gRemoveAdvertisingSet_c,
    gLePeriodicAdvSyncEstb_c,
    gLePeriodicAdvSyncLost_c,
    gLeRemoveDeviceFromPeriodicAdvList_c,
    gLeClearPeriodicAdvList_c,
    gLeAddDeviceToPeriodicAdvList_c,
    gLeReadNumOfSupportedAdvSets_c,
    gLeReadPeriodicAdvListSize_c,
    gLeReadMaxAdvDataLen_c,
    gPeriodicAdvCreateSync,
    gPeriodicAdvCancelSync,
    gPeriodicAdvTerminateSync,
    gL2capRxPacket_c,
    gExtAdvReportProcess_c,
} gapInternalErrorSource_t;

/*! Internal Error Event Data */
typedef struct {
    bleResult_t                 errorCode;          /*!< Host Stack error code. */
    gapInternalErrorSource_t    errorSource;        /*!< The command that generated the error; useful when it is not obvious from the error code. */
    uint16_t                    hciCommandOpcode;   /*!< Only for errorSource = gHciCommandStatus_c; the HCI Command that received an error status. */
} gapInternalError_t;

/*! Controller Test Event Type */
typedef enum
{
    gControllerReceiverTestStarted_c,
    gControllerTransmitterTestStarted_c,
    gControllerTestEnded_c,
} gapControllerTestEventType_t;

/*! Controller Test Event */
typedef struct {
    gapControllerTestEventType_t    testEventType;
    uint16_t                        receivedPackets; /* Valid only if testEventType == gControllerTestEnded_c and the test was a Receiver Test. */
} gapControllerTestEvent_t;

/*! Le All Phys Preferences flags. */
typedef enum {
    gLeTxPhyNoPreference_c        = BIT0,   /*!< Host has no preference for Tx Phy */
    gLeRxPhyNoPreference_c        = BIT1,   /*!< Host has no preference for Rx Phy */
} gapLeAllPhyFlags_t;

/*! Le Tx/Rx Phys Preferences flags. */
typedef uint8_t gapLePhyFlags_t;

/*! Le Phys Options Preferences flags. */
typedef enum {
    gLeCodingNoPreference_c = 0x00U,         /*!< Host has no preference on the LE Coded Phy */
    gLeCodingS2_c           = 0x01U,         /*!< Host prefers to use S=2 on the LE Coded Phy */
    gLeCodingS8_c           = 0x02U,         /*!< Host prefers to use S=8 on the LE Coded Phy */
} gapLePhyOptionsFlags_t;

/*! Le Tx/Rx Phys. */
typedef uint8_t gapLePhyMode_t;
typedef enum  {
    gLePhy1M_c            = 0x01U,         /*!< Tx/Rx Phy on the connection is LE 1M */
    gLePhy2M_c            = 0x02U,         /*!< Tx/Rx Phy on the connection is LE 2M */
    gLePhyCoded_c         = 0x03U,         /*!< Tx/Rx Phy on the connection is LE Coded */
} gapLePhyMode_tag;

/*! Phy Event Type */
typedef enum
{
    gPhySetDefaultComplete_c,               /*!< Gap_LeSetPhy default mode was successful */
    gPhyRead_c,                             /*!< Gap_LeReadPhy return values */
    gPhyUpdateComplete_c,                   /*!< Gap_LeSetPhy return values for a connection or an update occurred */
} gapPhyEventType_t;

/*! Phy Event */
typedef struct {
    gapPhyEventType_t    phyEventType;
    deviceId_t           deviceId;      /* Valid only if phyEventType == gPhyRead_c or gPhyUpdateComplete_c. */
    uint8_t              txPhy;         /* Valid only if phyEventType == gPhyRead_c or gPhyUpdateComplete_c. */
    uint8_t              rxPhy;         /* Valid only if phyEventType == gPhyRead_c or gPhyUpdateComplete_c. */
} gapPhyEvent_t;

/*! Controller Enhanced Notification Event Type */
typedef uint16_t bleNotificationEventType_t;
typedef enum
{
    gNotifEventNone_c           =  0x00,         /*!< No enhanced notification event enabled */
    gNotifConnEventOver_c       =  BIT0,         /*!< Connection event over */
    gNotifConnRxPdu_c           =  BIT1,         /*!< Connection Rx PDU */
    gNotifAdvEventOver_c        =  BIT2,         /*!< Advertising event over */
    gNotifAdvTx_c               =  BIT3,         /*!< Advertising ADV transmitted */
    gNotifAdvScanReqRx_c        =  BIT4,         /*!< Advertising SCAN REQ Rx */
    gNotifAdvConnReqRx_c        =  BIT5,         /*!< Advertising CONN REQ Rx */
    gNotifScanEventOver_c       =  BIT6,         /*!< Scanning event over */
    gNotifScanAdvPktRx_c        =  BIT7,         /*!< Scanning ADV PKT Rx */
    gNotifScanRspRx_c           =  BIT8,         /*!< Scanning SCAN RSP Rx */
    gNotifScanReqTx_c           =  BIT9,         /*!< Scanning SCAN REQ Tx */
    gNotifConnCreated_c         = BIT10,         /*!< Connection created */
} bleNotificationEventType_tag;

/*! Controller Enhanced Notification Event */
typedef struct {
    bleNotificationEventType_t eventType;       /*!< Enhanced notification event type */
    deviceId_t                 deviceId;        /*!< Device id of the peer, valid for connection events */
    int8_t                     rssi;            /*!< RSSI, valid for Rx event types */
    uint8_t                    channel;         /*!< Channel, valid for conn event over or Rx/Tx events */
    uint16_t                   ce_counter;      /*!< Connection event counter, valid for conn event over or Conn Rx event */
    bleResult_t                status;          /*!< Status of the request to select which events to be enabled/disabled */
    uint16_t                   timestamp;       /*!< Timestamp in 625 us slots, valid for Conn Rx event and Conn Created event */
    uint8_t                    adv_handle;      /*!< Advertising Handle, valid for advertising events, if multiple ADV sets supported */
} bleNotificationEvent_t;

/*! gInitializationComplete_c event data */
typedef struct {
    uint32_t supportedFeatures;
    uint16_t maxAdvDataSize;
    uint8_t  numOfSupportedAdvSets;
    uint8_t  periodicAdvListSize;
}gapInitComplete_t;

/*! Bond Created Event */
typedef struct bleBondCreatedEvent_tag {
    uint8_t             nvmIndex;    /*!< NVM index for the new created bond */
    bleAddressType_t    addressType; /*!< Public or Random (static) address of the bond */
    bleDeviceAddress_t  address;     /*!< Address of the bond */
} bleBondCreatedEvent_t;

/*! Address Ready Event */
typedef struct gapAddrReadyEvent_t_tag {
    bleDeviceAddress_t  aAddress;   /*!< Generated device address */
    uint8_t             advHandle;  /*!< Advertising set handle if the generated device address will be used on an extended set.
                                         Reserved value 0xFF for other purposes: legacy advertising or scanning and initiating address. */
} gapAddrReadyEvent_t;

/*! Generic Event Structure = type + data */
typedef struct {
    gapGenericEventType_t  eventType;       /*!< Event type. */
    union {
        gapInternalError_t          internalError;              /*!< Data for the gInternalError_c event. The error that has occurred and the command that triggered it. */
        uint8_t                     whiteListSize;              /*!< Data for the gWhiteListSizeReady_c event. The size of the White List. */
        bleDeviceAddress_t          aAddress;                   /*!< Data for the gPublicAddressRead_c event. Contains the requested device address. */
        gapAddrReadyEvent_t         addrReady;                  /*!< Data for the gRandomAddressReady_c event. Contains the generated device address and advertising handle if applicable (0xFF otherwise). */
        uint8_t                     advHandle;                  /*!< Data for the gRandomAddressSet_c event. Contains the handle of the configured advertising set or 0xFF for legacy advertising. */
        bleResult_t                 setupFailError;             /*!< Data for the gAdvertisingSetupFailed_c event. The error that occurred during the advertising setup. */
        int8_t                      advTxPowerLevel_dBm;        /*!< Data for the gExtAdvertisingParametersSetupComplete_c and gAdvTxPowerLevelRead_c events. Value in dBm. */
        bool_t                      verified;                   /*!< Data for the gPrivateResolvableAddressVerified_c event. TRUE if the PRA was resolved with the given IRK. */
        gapLeScOobData_t            localOobData;               /*!< Data for the gLeScLocalOobData_c event. Contains local OOB data for LESC Pairing. */
        bool_t                      newHostPrivacyState;        /*!< Data for the gHostPrivacyStateChanged_c event. TRUE if enabled, FALSE if disabled. */
        bool_t                      newControllerPrivacyState;  /*!< Data for the gControllerPrivacyStateChanged_c event. TRUE if enabled, FALSE if disabled. */
        gapControllerTestEvent_t    testEvent;                  /*!< Data for the gControllerTestEvent_c event. Contains test event type and received packets. */
        bleResult_t                 txPowerLevelSetStatus;      /*!< Data for the gTxPowerLevelSetComplete_c event. Status of the set request. */
        gapPhyEvent_t               phyEvent;                   /*!< Data for the gLePhyEvent_c event. Contains Tx and Rx Phy for a connection. */
        deviceId_t                  deviceId;                   /*!< Data for the gTxEntryAvailable_c event. */
        gapInitComplete_t           initCompleteData;           /*!< Data for the gInitializationComplete_c event. Contains the supported features, number of advertising sets
                                                                     and the size of the periodic advertiser list */
        bleNotificationEvent_t      notifEvent;                 /*!< Data for the gControllerNotificationEvent_c event. Contains status and adv/scan/conn event data. */
        bleBondCreatedEvent_t       bondCreatedEvent;           /*!< Data for the gBondCreatedEvent_c event. Contains the NVM index and the address of the bond. */
    } eventData;                            /*!< Event data, selected according to event type. */
} gapGenericEvent_t;

/*! Generic Callback prototype. */
typedef void (*gapGenericCallback_t)
(
    gapGenericEvent_t* pGenericEvent  /*!< Generic event. */
);

/*! Host-to-Controller API prototype. */
typedef bleResult_t (*hciHostToControllerInterface_t)
(
    hciPacketType_t packetType,     /*!< HCI Packet Type. */
    void* pPacket,                  /*!< Pointer to packet payload. */
    uint16_t packetSize             /*!< Packet payload size. */
);

typedef struct
{
    uint32_t raw[(gBleBondIdentityHeaderSize_c + 3U) / sizeof(uint32_t)];
} bleBondIdentityHeaderBlob_t;

typedef struct
{
    uint32_t raw[(gBleBondDataDynamicSize_c + 3U) / sizeof(uint32_t)];
} bleBondDataDynamicBlob_t;

typedef struct
{
    uint32_t raw[(gBleBondDataStaticSize_c + 3U) / sizeof(uint32_t)];
} bleBondDataStaticBlob_t;

typedef struct
{
    uint32_t raw[(gBleBondDataDeviceInfoSize_c + 3U) / sizeof(uint32_t)];
} bleBondDataDeviceInfoBlob_t;

typedef struct
{
    uint32_t raw[(gBleBondDataDescriptorSize_c + 3U) / sizeof(uint32_t)];
}bleBondDataDescriptorBlob_t;

typedef struct
{
    bleBondIdentityHeaderBlob_t     bondHeader;
    bleBondDataDynamicBlob_t        bondDataBlobDynamic;
    bleBondDataStaticBlob_t         bondDataBlobStatic;
    bleBondDataDescriptorBlob_t     bondDataDescriptors[gcGapMaximumSavedCccds_c];
    bleBondDataDeviceInfoBlob_t     bondDataBlobDeviceInfo;
}bleBondDataBlob_t;

typedef struct bleGapGlobalConfig_tag
{
    uint8_t gapMaximumBondedDevicesField;
    uint8_t gapGapMaximumSavedCccdsField;
    uint8_t gapControllerResolvingListSizeField;
    uint8_t gapGapMaxServiceSpecificSecurityRequirementsField;
    uint8_t *pServiceSecurityRequirementsField;
    bleBondIdentityHeaderBlob_t *pBondIdentityHeaderBlobsField;
    uint8_t *pControllerPrivacyIdentitiesField;
    uint8_t *pCAR_SupportField;
    uint16_t gapDefaultTxOctetsField;
    uint16_t gapDefaultTxTimeField;
    uint16_t gapHostPrivacyTimeoutField;
    uint16_t gapControllerPrivacyTimeoutField;
    bool_t gapLeSecureConnectionsOnlyModeField;
    bool_t gapLeScOobHasMitmProtectionField;
    uint8_t maxAdvReportQueueSize;
    uint8_t gapSimultaneousEAChainedReportsField;
    uint32_t gapFreeEAReportMsField;
    bool_t gAdvSetsUseSameRandomAddrField;

    /* Can be used for only static memory allocation or mem alloc
    forever */
    void *pExtention;
}bleGapGlobalConfig_t;

typedef struct bleGattGlobalConfig_tag
{
    uint16_t gcGattServerMtuField;
    uint8_t gattMaxHandleCountForWriteNotificationsField;
    uint16_t *pGattWriteNotificationHandlesField;
    uint8_t gattMaxHandleCountForReadNotificationsField;
    uint16_t *pGattReadNotificationHandlesField;

    /* Queued Writes server globals, supporting gAppMaxConnections_c clients */
    const uint8_t gattDbMaxPrepareWriteOperationsInQueueField;
    const uint8_t gattDbMaxPrepareWriteClientsField;
    uint8_t *pGattDbPrepareWriteQueueIndexesField;
    uint8_t **ppPrepareWriteQueuesField;
    uint32_t *pGattServiceChangedIndicationStorageField;

    /* Can be used for only static memory allocation or mem alloc
    forever */
    void *pExtention;
}bleGattGlobalConfig_t;

typedef struct bleHostConnStorageGlobalConfig_tag
{
    /* BLE Host connection storage */
    const uint8_t bleMaxActiveConnectionsField;
    uint32_t *pAttConnStorageField;
    uint32_t *pActiveDevicesStorageField;

    /* Can be used for only static memory allocation or mem alloc
    forever */
    void *pExtention;
}bleHostConnStorageGlobalConfig_t;

typedef struct bleL2caGlobalConfig_tag
{
    const uint8_t l2caMaxLePsmSupportedField;
    const uint8_t l2caMaxLeCbChannelsField;
    uint32_t *pL2caPsmStorageField;
    uint32_t *pL2caCbChannelStorageField;
    const uint8_t maxL2caQueueSizeField;

    /* Can be used for only static memory allocation or mem alloc
    forever */
    void *pExtention;
}bleL2caGlobalConfig_t;

typedef struct bleHostGlobalControllerConfig_tag
{
    bool_t hostInitResetControllerField;

    /* Can be used for only static memory allocation or mem alloc
    forever */
    void *pExtention;
}bleHostGlobalControllerConfig_t;

typedef struct bleHostGlobalHostTaskConfig_tag
{
    /*! App to Host message queue for the Host Task */
    uint8_t *pApp2Host_TaskQueue;
    /*! HCI to Host message queue for the Host Task */
    uint8_t *pHci2Host_TaskQueue;
    /*! Event for the Host Task Queue */
    osaEventId_t *pHost_TaskEvent;

    /* Can be used for only static memory allocation or mem alloc
    forever */
    void *pExtention;
}bleHostGlobalHostTaskConfig_t;

typedef struct bleHostGlobalFrameworkConfig_tag
{
    const uint8_t *useRtosField;

    /* Can be used for only static memory allocation or mem alloc
    forever */
    void *pExtention;
}bleHostGlobalFrameworkConfig_t;

typedef struct bleHostGlobalConfig_tag
{
    bleGapGlobalConfig_t gapGlobalConfig;
    bleGattGlobalConfig_t gattGlobalConfig;
    bleHostConnStorageGlobalConfig_t connStorageGlobalConfig;
    bleL2caGlobalConfig_t l2caGlobalConfig;
    bleHostGlobalControllerConfig_t hostGlobalControllerConfig;
    bleHostGlobalHostTaskConfig_t hostGlobalHostTaskConfig;
    bleHostGlobalFrameworkConfig_t fwkConfig;
}bleHostGlobalConfig_t;

typedef enum bleHostConfigStorageCheckerType
{
    eAttConnStorageSize = 0x01,
    eActiveDevicesStorageSize,
    eL2caLeCbChannelEntrySize,
    eL2caLePsmEntrySize,
    eBleHostGlobalConfigSize,
} bleHostConfigStorageCheckerType_t;

typedef uint32_t LeSupportedFeatures_t;
typedef enum
{
    gLeEncryption_c                            = 1U << (0U * 8U + 0U), /* 0 */
    gLeConnectionParametersRequestProcedure_c  = 1U << (0U * 8U + 1U), /* 1 */
    gLeExtendedRejectIndication_c              = 1U << (0U * 8U + 2U), /* 2 */
    gLeSlaveInitiatedFeaturesExchange_c        = 1U << (0U * 8U + 3U), /* 3 */
    gLePing_c                                  = 1U << (0U * 8U + 4U), /* 4 */
    /* BLE v4.2 */
    gLeDataPacketLengthExtension_c             = 1U << (0U * 8U + 5U), /* 5 */
    gLeLlPrivacy_c                             = 1U << (0U * 8U + 6U), /* 6 */
    gLeExtendedScannerFilterPolicies_c         = 1U << (0U * 8U + 7U), /* 7 */
    /* BLE v5.0 */
    gLe2MbPhy_c                                = 1U << (1U * 8U + 0U), /* 8 */
    gLeStableModulationIdxTx_c                 = 1U << (1U * 8U + 1U), /* 9 */
    gLeStableModulationIdxRx_c                 = 1U << (1U * 8U + 2U), /* 10 */
    gLeCodedPhy_c                              = 1U << (1U * 8U + 3U), /* 11 */
    gLeExtendedAdv_c                           = 1U << (1U * 8U + 4U), /* 12 */
    gLePeriodicAdv_c                           = 1U << (1U * 8U + 5U), /* 13 */
    gLeChannelSelAlg2_c                        = 1U << (1U * 8U + 6U), /* 14 */
    gLePowerClass1_c                           = 1U << (1U * 8U + 7U), /* 15 */
    gLeMinNumOfUsedChanProcedure_c             = 1U << (2U * 8U + 0U), /* 16 */
} LeSupportedFeatures_tag;


/************************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*! *********************************************************************************
* \brief  Performs master initialization of the BLE Host stack.
*
* \param[in] genericCallback  Callback used to propagate GAP generic events to the application.
* \param[in] hostToControllerInterface  LE Controller uplink interface function pointer
*
* \return  gBleSuccess_c or error.
*
* \remarks Application must wait for the gInitializationComplete_c generic event.
*
********************************************************************************** */
bleResult_t Ble_HostInitialize
(
    gapGenericCallback_t            genericCallback,
    hciHostToControllerInterface_t  hostToControllerInterface
);

/*! *********************************************************************************
* \brief  This is the BLE Host downlink interface function.
*
* \param[in] packetType     The type of the packet sent by the LE Controller
* \param[in] pHciPacket     Pointer to the packet sent by the LE Controller
* \param[in] packetSize     Number of bytes sent by the LE Controller
*
* \return gBleSuccess_c or gBleOutOfMemory_c
*
* \remarks This function must be registered as a callback by the LE Controller and called
* to send HCI packets (events and LE-U data) to the BLE Host.
*
********************************************************************************** */
bleResult_t Ble_HciRecv
(
    hciPacketType_t     packetType,
    void*               pHciPacket,
    uint16_t            packetSize
);

/*! *********************************************************************************
* \brief  Function used to initialize the BLE host stack
*
* \param[in] pHostGlobalConfig     Config structure allocated by the application
*
* \return void
*
* \remarks The function has to be called prior to call any functionnality of the
*          BLE host stack
*
********************************************************************************** */
void Ble_HostConfigInit
(
    bleHostGlobalConfig_t* pHostGlobalConfig
);

/*! *********************************************************************************
* \brief  The function allows to check that the size of shared structure between the
 *        application and the ble host stack
*
* \param[in] storageType            The type of storage to check
* \param[in] appMaxConnectionGiven  Max connection
* \param[in] sizeGiven              The size of the type to check
*
* \return gBleSuccess_c, gBleOutOfMemory_c or gBleInvalidParameter_c
*
*
********************************************************************************** */
bleResult_t Ble_HostConfigMemoryCheck
(
    bleHostConfigStorageCheckerType_t storageType,
    uint32_t appMaxConnectionGiven,
    uint32_t sizeGiven
);

/*! *********************************************************************************
* \brief  Returs the pointer of the host configuration structure
*
* \return pointer of the host configuration structure
*
*
********************************************************************************** */
bleHostGlobalConfig_t* Ble_HostGetGlobalConfig(void);

#ifdef __cplusplus
}
#endif

#endif /* _BLE_GENERAL_H_ */

/*! *********************************************************************************
* @}
********************************************************************************** */
