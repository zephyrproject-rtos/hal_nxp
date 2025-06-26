/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETH_IP_H
#define NETC_ETH_IP_H

/**
*   @file Netc_Eth_Ip.h
*
*   @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Netc_Eth_Ip_Types.h"
#include "Eth_GeneralTypes.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_VENDOR_ID                    43
#define NETC_ETH_IP_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETH_IP_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETH_IP_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETH_IP_SW_MAJOR_VERSION             2
#define NETC_ETH_IP_SW_MINOR_VERSION             0
#define NETC_ETH_IP_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_Eth_Ip_Types.h */
#if (NETC_ETH_IP_VENDOR_ID != NETC_ETH_IP_TYPES_VENDOR_ID)
    #error "Netc_Eth_Ip.h and Netc_Eth_Ip_Types.h have different vendor ids"
#endif
#if ((NETC_ETH_IP_AR_RELEASE_MAJOR_VERSION    != NETC_ETH_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (NETC_ETH_IP_AR_RELEASE_MINOR_VERSION    != NETC_ETH_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (NETC_ETH_IP_AR_RELEASE_REVISION_VERSION != NETC_ETH_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Netc_Eth_Ip.h and Netc_Eth_Ip_Types.h are different"
#endif
#if ((NETC_ETH_IP_SW_MAJOR_VERSION != NETC_ETH_IP_TYPES_SW_MAJOR_VERSION) || \
     (NETC_ETH_IP_SW_MINOR_VERSION != NETC_ETH_IP_TYPES_SW_MINOR_VERSION) || \
     (NETC_ETH_IP_SW_PATCH_VERSION != NETC_ETH_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Netc_Eth_Ip.h and Netc_Eth_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define ETH_43_NETC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

NETC_ETH_IP_CONFIG_EXT

#define ETH_43_NETC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

#define NETC_ETH_IP_32BIT_SHIFT (32U)    /*!< 32 bits shift */
#define NETC_ETH_IP_24BIT_SHIFT (24U)    /*!< 24 bits shift */
#define NETC_ETH_IP_16BIT_SHIFT (16U)    /*!< 16 bits shift */
#define NETC_ETH_IP_8BIT_SHIFT  (8U)     /*!< 8 bits shift */

#define NETC_ETH_IP_0XFF_MASK                           (0xFFU)
#define NETC_ETH_IP_0XFFFF_MASK                         (0xFFFFU)
#define NETC_ETH_IP_0XFFFF0000_MASK                     (0xFFFF0000UL)

/* Macros for NTMP request message header */
#define NETC_ETH_IP_CMDBD_REQFMT_PROTOCOL_VERSION       (2U)      /*!< protocol version = 0x2 */
#define NETC_ETH_IP_CMDBD_REQFMT_NTMP_PROTOCOL_VERSION  (1U)      /*!< NTMP version is 2.0 */

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"

/** @brief Pointers to NETC internal driver state for each controller(SI). */
extern Netc_Eth_Ip_StateType *Netc_Eth_Ip_apxState[FEATURE_NETC_ETH_NUMBER_OF_CTRLS];
#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE

#include "Eth_43_NETC_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_NETC_START_SEC_CODE
#include "Eth_43_NETC_MemMap.h"

/*!
 * @brief Initializes the ENETC station interface
 *
 * This function initializes and enables the ENETC station instance, configuring receive and transmit control
 * settings, the receive and transmit descriptors rings and the MAC physical address.
 *
 * @param[in] ctrlIndex Instance number
 * @param[in] config Pointer to the instance configuration structure
 *
 * @retval NETC_ETH_IP_STATUS_SUCCESS The initialization was successful.
 * @retval NETC_ETH_IP_STATUS_TIMEOUT The initialization returned a timeout.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_Init(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config);

/**
* @brief            Ethernet controller function for starting TSN.
* @details          This function enables the statically configured TSN settings. If stream gating or time aware shaping is used, the API must be called after the clock is synchronized.
*                   Eth_Ip_StartTSN shall:
*                   - Populate all tables related to 802.1qci.
*
* @param[in]        ctrlIndex   Instance number
*
* @return           Result of the operation
* @retval           E_OK        success
* @retval           E_NOT_OK    TSN could not be started
*/
Std_ReturnType Netc_Eth_Ip_StartTSN(uint8 ctrlIndex);

/**
 * @brief            Add or Update Ingress Stream Identification Table Entry function
 * @details          External function for adding or updating one Ingress Stream Identification entry with "KEY_ELEMENT" access method.
 *                   That means only "KEY_ELEMENT" access method is supported.
 *
 * @param[in]        ctrlIndex        Instance number
 * @param[in]        Cmd              Add and Update commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        ISQGTableEntry   Pointer points to a Ingress Stream Identification entry structure Netc_Eth_Ip_IngrStremIdentificationTableDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddOrUpdateIngrStreamIdentificationTableEntry( const uint8 CtrlIndex,
                                                                                  Netc_Eth_Ip_CommandsType Cmd,
                                                                                  uint32 *MatchedEntries,
                                                                                  const Netc_Eth_Ip_IngrStremIdentificationTableDataType * ISITableEntry
                                                                                );

/**
 * @brief            Query Ingress Stream Identification Table Entry function
 * @details          External function for querying one Ingress Stream Identification entry with "KEY_ELEMENT" access method.
 *                   That means only "KEY_ELEMENT" access method is supported.
 *
 * @param[in]        ctrlIndex              Instance number
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        ISITableEntry          A pointer that provides the data with the "query" operation
 * @param[out]       ISITableEntry          A pointer that returns the data of a matched entry by "query" operation
 *                                          The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryIngrStreamIdentificationTableEntry( const uint8 CtrlIndex,
                                                                            uint32 *MatchedEntries,
                                                                            Netc_Eth_Ip_IngrStremIdentificationTableDataType * ISITableEntry
                                                                          );

/**
 * @brief            Delete Ingress Stream Identification Table Entry function
 * @details          External function for deleting one Ingress Stream Identification entry with "KEY_ELEMENT" access method.
 *                   That means only "KEY_ELEMENT" access method is supported.
 *
 * @param[in]        ctrlIndex              Instance number
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        ISITableEntry          A pointer that provides the data with the "delete" operation
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DeleteIngrStreamIdentificationTableEntry( const uint8 CtrlIndex,
                                                                                       uint32 *MatchedEntries,
                                                                                       const Netc_Eth_Ip_IngrStremIdentificationTableDataType * ISITableEntry
                                                                                     );

/**
 * @brief            Dump all Ingress Stream Identification Table Entries function
 * @details          External function for dumping all Ingress Stream Identification entries with "SEARCH_CRITERIA" access method.
 *                   That means only "SEARCH_CRITERIA" access method is supported.
 *
 * @param[in]        ctrlIndex              Instance number
 * @param[in]        NumberOfElements       Number of entries that want to be dumped
 * @param[out]       NumberOfElements       Number of entries that actually are dumped (number of existing entries)
 * @param[out]       ISITableList           A pointer that returns the list of NumberOfElements entries
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetIngrStreamIdentificationTable( const uint8 CtrlIndex,
                                                                     uint16 * NumberOfElements,
                                                                     Netc_Eth_Ip_IngrStremIdentificationTableDataType * ISITableList
                                                                   );

#if (NETC_ETH_NUMBER_OF_SGI_ENTRIES > 0U)
/**
 * @brief            Add or Update Stream Gate Instance Table Entry function
 * @details          External function for adding or updating one Stream Gate Instance entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        ctrlIndex        Instance number
 * @param[in]        Cmd              Add and Update commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        StreamGateInstanceTableEntry    Pointer points to a Stream Gate Instance entry structure Netc_Eth_Ip_StreamGateInstanceEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddOrUpdateStreamGateInstanceTableEntry( const uint8 CtrlIndex,
                                                                            Netc_Eth_Ip_CommandsType Cmd,
                                                                            uint32 *MatchedEntries,
                                                                            const Netc_Eth_Ip_StreamGateInstanceEntryDataType * StreamGateInstanceTableEntry
                                                                           );

/**
 * @brief            Query Stream Gate Instance Table Entry function
 * @details          External function for querying one Stream Gate Instance entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        ctrlIndex              Instance number
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        SGIEntryId             Stream Gate Instance entry ID
 * @param[out]       SGITableEntryRspData   A pointer that returns the data of a matched entry by "query" operation
 *                                          The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryStreamGateInstanceTableEntry( const uint8 CtrlIndex,
                                                                      uint32 *MatchedEntries,
                                                                      uint32 SGIEntryId,
                                                                      Netc_Eth_Ip_StreamGateInstanceEntryRspDataType * SGITableEntryRspData
                                                                    );

/**
 * @brief            Delete Stream Gate Instance Table Entry function
 * @details          External function for deleting one Stream Gate Instance entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        ctrlIndex              Instance number
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        SGIEntryId             Stream Gate Instance entry ID
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DeleteStreamGateInstanceTableEntry( const uint8 CtrlIndex,
                                                                       uint32 *MatchedEntries,
                                                                       uint32 SGIEntryId
                                                                     );
#endif /* (NETC_ETH_NUMBER_OF_SGI_ENTRIES > 0U) */

#if (NETC_ETH_NUMBER_OF_SGCL_ENTRIES > 0U)
/**
 * @brief            Add Stream Gate Control List Table Entry function
 * @details          External function for adding one Stream Gate Control List entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        ctrlIndex        Instance number
 * @param[in]        Cmd              Add and Update commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        SGCLTableEntry   Pointer points to a Stream Gate Control List entry structure Netc_Eth_Ip_SGCLTableDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddStreamGateControlListTableEntry( const uint8 CtrlIndex,
                                                                       Netc_Eth_Ip_CommandsType Cmd,
                                                                       uint32 *MatchedEntries,
                                                                       const Netc_Eth_Ip_SGCLTableDataType * SGCLTableEntry
                                                                     );

/**
 * @brief            Query Stream Gate Control List Table Entry function
 * @details          External function for querying one Stream Gate Control List entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        ctrlIndex              Instance number
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        SGCLEntryId            Stream Gate Control List entry ID
 * @param[in]        ListLen                Stream Gate Control List entry length, it has to be set to the same value as LIST_LENGTH when adding the entry
 * @param[out]       SGCLTableEntryRspData  A pointer that returns the data of a matched entry by "query" operation
 *                                          The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryStreamGateControlListTableEntry( const uint8 CtrlIndex,
                                                                         uint32 *MatchedEntries,
                                                                         uint32 SGCLEntryId,
                                                                         uint8 ListLen,
                                                                         Netc_Eth_Ip_SGCLTableDataType * SGCLTableEntryRspData
                                                                       );

/**
 * @brief            Delete Stream Gate Control List Table Entry function
 * @details          External function for deleting one Stream Gate Control List entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        ctrlIndex              Instance number
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        SGCLEntryId            Stream Gate Control List entry ID
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DeleteStreamGateControlListTableEntry( const uint8 CtrlIndex,
                                                                          uint32 *MatchedEntries,
                                                                          uint32 SGCLEntryId
                                                                        );
#endif /* (NETC_ETH_NUMBER_OF_SGCL_ENTRIES > 0U) */

/**
 * @brief            Add or Update Ingress Stream Table Entry function
 * @details          External function for adding or updating one Ingress Stream entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        ctrlIndex        Instance number
 * @param[in]        Cmd              Add and Update commands are supported
 * @param[out]       MatchedEntries   Number of matched entries
 * @param[in]        IngressStreamTableEntry    Pointer points to a Ingress Stream entry structure Netc_Eth_Ip_IngressStreamEntryDataType
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddOrUpdateIngressStreamTableEntry( const uint8 CtrlIndex,
                                                                       Netc_Eth_Ip_CommandsType Cmd,
                                                                       uint32 *MatchedEntries,
                                                                       const Netc_Eth_Ip_IngressStreamEntryDataType * IngressStreamTableEntry
                                                                     );

/**
 * @brief            Query Ingress Stream Table Entry function
 * @details          External function for querying one Ingress Stream entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        ctrlIndex              Instance number
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        IngressStreamEntryId     Ingress Stream table entry ID
 * @param[out]       IngressStreamTableEntry  A pointer that returns the data of a matched entry by "query" operation
 *                                            The data is valid only when MatchedEntries equals 1.
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryIngressStreamTableEntry( const uint8 CtrlIndex,
                                                                 uint32 *MatchedEntries,
                                                                 uint32 IngressStreamEntryId,
                                                                 Netc_Eth_Ip_IngressStreamEntryDataType * IngressStreamTableEntry
                                                               );

/**
 * @brief            Delete Ingress Stream Table Entry function
 * @details          External function for deleting one Ingress Stream entry with "Entry ID Match" access method.
 *                   That means only "Entry ID Match" access method is supported.
 *
 * @param[in]        ctrlIndex              Instance number
 * @param[out]       MatchedEntries         Number of matched entry
 * @param[in]        IngressStreamEntryId     Ingress Stream entry ID
 *
 * @return           Result of the operation
 * @retval           0 : NETC_ETH_IP_STATUS_SUCCESS, success
 * @retval           others : fail
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DeleteIngressStreamTableEntry( const uint8 CtrlIndex,
                                                                  uint32 *MatchedEntries,
                                                                  uint32 IngressStreamEntryId
                                                                );

/**
 * @brief            Set the credit based shaper slope
 * @details          Set the idle slope for the credit based shaper
 *
 * Parameters:
 * -[in]     ctrlIndex           Index of the controller within the context of the Ethernet Driver
 * -[in]     TrafficClass        The value range is 0 to 7
 * -[in]     idleSlope           Idleslope is the rate of credits that is accumulated (in bits per second)  when there  is  at  least  one packet waiting for transmission.
 */
Std_ReturnType Netc_Eth_Ip_ConfigureCreditBasedShaper(const uint8 ctrlIndex, const uint8 TrafficClass, const uint64 idleSlope);

/**
 * @brief            Enable/Disable the credit based shaper
 * @details          The credit based shaper TrafficClass is Enable/Disable
 *
 * Parameters:
 * -[in]     ctrlIndex            Index of the controller within the context of the Ethernet Driver
 * -[in]     TrafficClass         The value range is 0 to 7
 * -[in]     Enable               TRUE: enable credit based shaper. FALSE: disable credit based shaper.
 *
 */
Std_ReturnType Netc_Eth_Ip_EnableCreditBasedShaper(const uint8 ctrlIndex, const uint8 TrafficClass, const boolean Enable);

/*!
 * @brief Gets the current power state of the NETC instance
 *
 * @param[in] CtrlIndex Instance number
 * @return Netc_Eth_Ip_PowerStateType The power state of the controller
 */
Netc_Eth_Ip_PowerStateType Netc_Eth_Ip_GetPowerState(uint8 CtrlIndex);

/*!
 * @brief Enables the specified SI.
 *
 * @param[in] ctrlIndex SI number
 *
 * @retval NETC_ETH_IP_STATUS_SUCCESS The initialization was successful.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_EnableController(uint8 ctrlIndex);

/*!
 * @brief Disables the controller and resets all the configured transmit and receive buffers
 *
 * Warning: This function ignores all pending transmission and reception requests
 *
 * @param[in] ctrlIndex SI number
 *
 * @retval NETC_ETH_IP_STATUS_SUCCESS The controller was successfully disabled.
 * @retval NETC_ETH_IP_STATUS_ERROR   The controller cannot be disabled because of consuming pending ring.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DisableController(uint8 ctrlIndex);

/*!
 * @brief Provides a transmit buffer to be used by the application for transmission.
 *
 * This function provides an internal buffer which can further be used by the application
 * to store the transmit data.
 *
 * Note: The buffer will be marked as locked and won't be released until after a call to
 * Netc_Eth_Ip_GetTransmitStatus for the same buffer returns NETC_ETH_IP_STATUS_SUCCESS.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to get a buffer at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in]     ctrlIndex Instance number
 * @param[in]     ring   Ring number
 * @param[in,out] buff   In:  Buffer containing the desired length
 *                       Out: Buffer containing the granted length or available length in case of overflow.
 * @param[out]    buffId Index of the buffer (descriptor) within the ring.
 *                       If this information is not needed, this parameter should be NULL_PTR.
 * @retval NETC_ETH_IP_STATUS_SUCCESS The buffer has been successfully locked.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_BUSY All buffers are currently in use for the current ring.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW The requested buffer length cannot be granted.
 * @retval NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH The buffer length is smaller than minium of frame length.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTxBuff(uint8 ctrlIndex,
                                             uint8 ring,
                                             Netc_Eth_Ip_BufferType *buff,
                                             uint16 *buffId);

/*!
 * @brief Sends an Ethernet frame
 *
 * This function sends an Ethernet frame, contained in the buffer received as parameter.
 *
 * Note: Since the transmission of the frame is not complete when this function returns,
 * the application must not change/alter/re-use the provided buffer until after a call
 * to Netc_Eth_Ip_GetTransmitStatus for the same buffer returns NETC_ETH_IP_STATUS_SUCCESS.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to send a frame at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in] ctrlIndex Instance number
 * @param[in] ring The ring number
 * @param[in] buff The buffer containing the frame
 * @param[in] options Configuration options applicable to this buffer's transmission only.
 * Can be NULL_PTR, if no special option is required.
 * @retval NETC_ETH_IP_STATUS_SUCCESS       The frame was successfully enqueued for transmission.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_BUSY  All internal TX buffers are currently in use.
 * @retval NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH Length of the external buffer is smaller than minium of frame length.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW The requested buffer length cannot be granted.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendFrame(uint8 ctrlIndex,
                                             uint8 ring,
                                             #if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS)
                                             Netc_Eth_Ip_BufferType *buff,
                                             #else
                                             const Netc_Eth_Ip_BufferType *buff,
                                             #endif
                                             const Netc_Eth_Ip_TxOptionsType * options
                                            );


/*!
 * @brief Sends an Ethernet frame which is scattered in multiple buffers
 *
 * This function sends an Ethernet frame, contained in the buffers received as parameter.
 *
 * Note: Since the transmission of the frame is not complete when this function returns,
 * the application must not change/alter/re-use the provided buffer until after a call
 * to Netc_Eth_Ip_GetTransmitStatus for the same buffer returns NETC_ETH_IP_STATUS_SUCCESS.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to send a frame at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in] ctrlIndex Instance number
 * @param[in] ring The ring number
 * @param[in] Buffers The list of buffers containing the frame
 * @param[in] options Configuration options applicable to this buffer's transmission only.
 *                    Can be NULL_PTR, if no special option is required.
 * @param[in] NumBuffers Number of buffers available in Buffers
 * @retval NETC_ETH_IP_STATUS_SUCCESS       The frame was successfully enqueued for transmission.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_BUSY  All internal TX buffers are currently in use.
 * @retval NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH Length of the external buffer is smaller than minium of frame length.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW The requested buffer length cannot be granted.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendMultiBufferFrame(uint8 ctrlIndex,
                                                        uint8 ring,
                                                        const Netc_Eth_Ip_BufferType Buffers[],
                                                        const Netc_Eth_Ip_TxOptionsType *options,
                                                        uint16 NumBuffers);

/*!
 * @brief Provides a transmit buffer to be used by the application for transmission.
 *
 * This function will verify if there are enough descriptors free and that each of
 * the descriptors can hold the parts of the frame to be send using Netc_Eth_Ip_SendMultiBufferFrame.
 *
 * Note: This function will only return the first buffer descriptor index starting with which the
 * multi buffer frame can be sent.
 *
 * Important: This function is meant for internal use only and will be called from an upper layer to get
 * the first buffer descriptor index from a sequence of buffers that will be used for sending a
 * multi buffer frame.
 *
 * @param[in]     ctrlIndex     Instance number
 * @param[in]     ring          Ring number
 * @param[in]     NumBuffers    Number of buffers
 * @param[in]     BufferLength  List with the length of each chunk of the frame
 * @param[out]    buffId        Index of the buffer (descriptor) within the ring.
 * @retval NETC_ETH_IP_STATUS_SUCCESS The buffer has been successfully locked.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_BUSY All buffers are currently in use for the current ring.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW The requested buffer length cannot be granted.
 * @retval NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH The buffer length is smaller than minium of frame length.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTxMultiBuff(uint8 ctrlIndex,
                                                  uint8 ring,
                                                  uint16 NumBuffers,
                                                  const uint16 BufferLength[],
                                                  uint16 *buffId);

/*!
 * @brief Reads a received Ethernet frame
 *
 * This function reads the first received Ethernet frame in the Rx queue. The buffer received
 * as parameter will be updated by the driver and the .data field will point to a memory area
 * containing the frame data.
 *
 * Note: Once the application finished processing the buffer, it could be reused by the
 * driver for further receptions by invoking Netc_Eth_Ip_ProvideRxBuff.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to read a frame at the same time. This synchronization shall be implemented by the
 * application.
 *
 * @param[in]  ctrlIndex Instance number
 * @param[in]  ring The ring number
 * @param[out] buff The buffer containing the frame
 * @param[out] info Enhanced information related to the data contained by this receive buffer.
 * If this information is not needed, this parameter should be NULL_PTR.
 * @retval NETC_ETH_IP_STATUS_SUCCESS        A frame was successfully read.
 * @retval NETC_ETH_IP_STATUS_RX_QUEUE_EMPTY There is no available frame in the queue.
 * @retval NETC_ETH_IP_STATUS_ERROR       There is at least an error in reception.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ReadFrame(uint8 ctrlIndex,
                                             uint8 ring,
                                             Netc_Eth_Ip_BufferType *buff,
                                             Netc_Eth_Ip_RxInfoType *info
                                            );

/*!
 * @brief Provides a receive buffer to be used by the driver for reception.
 *
 * This function provides a buffer which can further be used by the reception mechanism
 * in order to store the received data.
 *
 * Note: The application can either provide a buffer previously obtained in a Netc_Eth_Ip_ReadFrame
 * call (when it is no longer needed after being fully processed), or allocate a new buffer.
 * The former approach is recommended as it has a simpler usage model and re-uses the same initial
 * memory range for the entire driver lifetime operation. The later approach could provide more
 * flexibility, but since it involves constant memory free/alloc operations it is only recommended
 * with an efficient pool-based memory allocator.
 *
 * Important: The driver does not ensure synchronization between different threads trying
 * to provide a buffer at the same time. This synchronization shall be implemented by the
 * application.
 *
 * Important: The application is responsible for providing one Rx buffer for every frame it
 * receives, otherwise the reception ring can fill-up, affecting further reception.
 *
 * Usage example:
 *
 * stat = Netc_Eth_Ip_ReadFrame(0U, 0U, &rxBuff);
 *
 * if (stat == NETC_ETH_IP_STATUS_SUCCESS)
 * {
 *     process_buffer(&rxBuff);
 *     Netc_Eth_Ip_ProvideRxBuff(0U, 0U, &rxBuff);
 * }
 *
 * @param[in] ctrlIndex Instance number
 * @param[in] ring The ring number
 * @param[in] buff The buffer to be added to the reception ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ProvideRxBuff(uint8 ctrlIndex,
                                                 uint8 ring,
                                                 const Netc_Eth_Ip_BufferType *buff);

/**
 * @brief This function will be used when RX should be used at maximum capacity, instead of providing
 *        one by one buffer for reception, a batch of buffers will be provided
 *
 * @param[in] CtrlIndex Instance number.
 * @param[in] Ring      The ring number.
 * @param[in] BuffList  This should be NULL_PTR if internal buffers are used, otherwise this should respect
 *                  the follwing indications:
 *                   - List of the external buffers used for descriptor restauration;
 * @param[inout] BuffListSize [IN]  Number of buffers in list. When the internal buffers are in use, this parameter shall
 *                                  contain the number of BD which need to be restored after a reception of a more than one packet.
 *                            [OUT] Returns how many Buffer Descriptors have been released.
 */
void Netc_Eth_Ip_ProvideMultipleRxBuff(const uint8 CtrlIndex,
                                                         const uint8 Ring,
                                                         uint8* const BuffList[],
                                                         uint16* BuffListSize);

/*!
 * @brief Checks if there are more frames available in the given queue
 *
 * This function takes a peek at the given Rx queue to check if there are more Ethernet
 * frames to be received. Its intended usage is to provide this information without
 * also extracting the frame as "Netc_Eth_Ip_ReadFrame".
 *
 * @param[in]  ctrlIndex Instance number
 * @param[in]  ring The ring number
 * @retval TRUE  There is an available frame in the queue.
 * @retval FALSE There is no available frame in the queue.
 */
boolean Netc_Eth_Ip_IsFrameAvailable(uint8 ctrlIndex,
                                     uint8 ring
                                    );
/*!
 * @brief Checks if the transmission of a buffer is complete.
 *
 * This function checks if the transmission of the given buffer is complete.
 *
 * TODO: Descrition should be improved to indicate that this is not normally
 * needed in regular transmit workflow since GetTxBuff already exposes HW
 * consumption of TX entries
 *
 * Note: If the buffer is not found in the Tx ring, the function will return NETC_ETH_IP_STATUS_BUFF_NOT_FOUND.
 *
 * @param[in]  CtrlIndex Instance number
 * @param[in]  ring The ring number
 * @param[in]  buff The transmit buffer for which the status shall be checked
 * @param[out] info Extended information related to the buffer. If this information is not needed,
 * this parameter should be NULL_PTR.
 * @retval NETC_ETH_IP_STATUS_TX_BUFF_BUSY    The frame is still enqueued for transmission.
 * @retval NETC_ETH_IP_STATUS_BUFF_NOT_FOUND  The buffer was not found in the Tx queue.
 * @retval NETC_ETH_IP_STATUS_ERROR        There is at least an error in transmission.
 * @retval NETC_ETH_IP_STATUS_SUCCESS         Otherwise.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTransmitStatus(uint8 ctrlIndex,
                                                     uint8 ring,
                                                     const Netc_Eth_Ip_BufferType * buff,
                                                     Netc_Eth_Ip_TxInfoType * info
                                                    );

/*!
 * @brief Configures the physical address of the MAC
 *
 * @param[in] CtrlIndex Instance number
 * @param[in] MacAddr The MAC address to be configured
 *
 * @retval NETC_ETH_IP_STATUS_SUCCESS Physical address of mac is configured successfully.
 * @retval NETC_ETH_IP_STATUS_TIMEOUT Changing the physical address was not changed because a timeout has occured.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetMacAddr(uint8 CtrlIndex, const uint8 *MacAddr);

/**
 * @brief Compute has value for MAC addr.
 *
 * @param MacAddr MAC address.
 * @return uint8  Hash value for MacAddr.
 */
uint8 Netc_Eth_Ip_ComputeMACHashValue(const uint8 *MacAddr);

/**
 * @brief Remove MAC addr in the software table.
 *
 * @param CtrlIndex        Index of the SI.
 * @param HashValue        Computed hash value.
 * @param MacAddr          MAC address.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS               - successfully operation
 *                                NETC_ETH_IP_STATUS_MAC_ADDR_TABLE_FULL   - unsuccessfully operation
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddMACHashFilterEntry(uint8 CtrlIndex, \
                                                         uint8 HashValue, \
                                                         const uint8 *MacAddr);

/**
 * @brief Remove MAC addr in the software table.
 *
 * @param CtrlIndex        Index of the SI.
 * @param HashValue        Computed hash value.
 * @param MacAddr          MAC address.
 * @param deleteAllEntries Allows the function to delete all Hash filter table entries or a specific entry.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR   - unsuccessfully operation
 *                                NETC_ETH_IP_STATUS_MAC_ADDR_NOT_FOUND - the current destination MAC was not
 *                                                                found in the hash filter table
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DeleteMACHashFilterEntry(const uint8 CtrlIndex, \
                                                            const uint8 HashValue, \
                                                            const uint8 *MacAddr, \
                                                            const boolean deleteAllEntries);

/**
 * @brief Gets the physical address of the MAC for a controller.
 *
 * @param[in]  CtrlIndex Instance number
 * @param[out] MacAddr The physical address of the MAC
 */
void Netc_Eth_Ip_GetMacAddr(uint8 CtrlIndex, uint8 *MacAddr);

/**
 * @brief Gets statistics from the specified counter
 *
 * @param[in] CtrlIndex Instance number
 * @param[in] Counter The counter to be read
 * @return The low 32-bit value of the requested counter
 */
uint32 Netc_Eth_Ip_GetCounter(uint8 CtrlIndex, Netc_Eth_Ip_CounterType Counter);

/**
 * @brief Gets statistics from the specified counter
 *
 * @param[in] CtrlIndex Instance number
 * @param[in] Counter The counter to be read
 * @return The 64-bit value of the requested counter
 */
uint64 Netc_Eth_Ip_GetCounter64(uint8 CtrlIndex, Netc_Eth_Ip_CounterType Counter);

/**
 * @brief Adds a hardware address to the hash filter. The destination address of
 * an incoming packet is passed through hash function and then is added as an
 * entry in the hash table.
 *
 * @param[in] CtrlIndex Instance number.
 * @param[in] MacAddr   Destination MAC address to be added in hash filter.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR   - unsuccessfully operation
 *                                NETC_ETH_IP_STATUS_MAC_ADDR_TABLE_FULL - MAC table used for hash filter is full
 *                                NETC_ETH_IP_STATUS_TIMEOUT - Only for VSIs - the command was not processed in the allotted time
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddMulticastDstAddrToHashFilter(const uint8 CtrlIndex, const uint8 *MacAddr);

/**
 * @brief Removes a hardware address from the hash filter. The destination address of
 * an incoming packet is passed through hash function and then is removed from
 * hash table.
 *
 * @param[in] CtrlIndex Instance number.
 * @param[in] MacAddr   Destination MAC address to be removed from hash filer.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR   - unsuccessfully operation
 *                                NETC_ETH_IP_STATUS_MAC_ADDR_NOT_FOUND - the current destination MAC was not
 *                                found in the hash filter table
 *                                NETC_ETH_IP_STATUS_TIMEOUT - Only for VSIs - the command was not processed in the allotted time
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_RemoveMulticastDstAddrFromHashFilter(const uint8 CtrlIndex, const uint8 *MacAddr);

/**
 * @brief Enables/Disables forwarding of the multicast traffic.
 *
 * @param[in]  CtrlIdx Instance number
 * @param[in]  EnableMulticast  TRUE -> cotroller will receive all the multicast traffic;
 *                     FALSE-> cotroller will stop receive all the multicast traffic;
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_TIMEOUT - Only for VSIs - the command was not processed in the allotted time
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetMulticastForwardAll(const uint8 CtrlIndex, const boolean EnableMulticast);

/**
 * @brief Disable multicast promiscuous and delete all entries in multicast MAC filter table.
 *
 * @param[in] CtrlIdx Instance number.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_TIMEOUT - Only for VSIs - the command was not processed in the allotted time
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_CloseMulticastReceiving(const uint8 CtrlIndex);
/**
 * @brief Realease multiple transmission buffers at once.
 *
 * @param CtrlIdx Instance number.
 * @param Ring    Ring number.
 */
void Netc_Eth_Ip_ReleaseTxBuffers(const uint8 CtrlIdx, const uint8 Ring);

/**
 * @brief Set the threshold values for Rx coalescing interrupt.
 *
 * @param[in]  CtrlIdx  Controller number
 * @param[in]  RingIdx  Ring Index on which the settings will be applied.
 * @param[in]  PacketsThreshold  No of packets after which the ISR will be triggered. Must be different than 0 in order to set the value.
 * @param[in]  TimerThreshold  No of ticks after which the ISR will be triggered. Must be different than 0 in order to set the value.
 *
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR - Either the coalescing interrupt is not enabled or the No of packets passed exceedes the
 *                                                        size of the ring.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetRxCoalescingThresholds(uint8 CtrlIdx, uint8 RingIdx, uint16 PacketsThreshold, uint32 TimerThreshold);

/**
 * @brief Set the threshold values for Tx coalescing interrupt.
 *
 * @param[in]  CtrlIdx  Controller number
 * @param[in]  RingIdx  Ring Index on which the settings will be applied.
 * @param[in]  PacketsThreshold  No of packets after which the ISR will be triggered. Must be different than 0 in order to set the value.
 *                               If a value which is not a power of two is passed through this parameter, than the actual number of packets configured
 *                               will be the greatest power of two which is smaller than the parameter value.
 * @param[in]  TimerThreshold  No of ticks after which the ISR will be triggered. Must be different than 0 in order to set the value.
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR - Either the coalescing interrupt is not enabled or the No of packets passed is equal
 *                                                          to or greater than the size of the ring.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetTxCoalescingThresholds(uint8 CtrlIdx, uint8 RingIdx, uint16 PacketsThreshold, uint32 TimerThreshold);

/**
 * @brief Add/Update time gate scheduling table entry.
 *
 * @param[in]  CtrlIndex Instance number
 * @param[in]  TimeGateSchedulingTableEntry  pointer to structure Netc_Eth_Ip_TimeGateSchedulingEntryDataType that contains the data of time gate scheduling entry
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddOrUpdateTimeGateSchedulingTableEntry( const uint8 CtrlIndex,
                                                                            const Netc_Eth_Ip_TimeGateSchedulingEntryDataType *TimeGateSchedulingTableEntry
                                                                          );

/**
 * @brief Enables/Disables time gate scheduling feature.
 *
 * @param[in]  CtrlIndex Instance number
 * @param[in]  Enable  TRUE -> time gate scheduling will be enabled;
 *                     FALSE-> time gate scheduling will be disabled;
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR - fail to enable time gating because Operational gate control list is active
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ConfigPortTimeGateScheduling( const uint8 CtrlIndex, const boolean Enable );

#if (NETC_ETH_IP_NUMBER_OF_RP_ENTRIES > 0)
/**
 * @brief Add/Update rate policer table entry.
 *
 * @param[in]  CtrlIndex Instance number
 * @param[in]  Cmd              Add and Update commands are supported
 * @param[out] MatchedEntries   Number of matched entries
 * @param[in]  RatePolicerTableEntry  pointer to structure Netc_Eth_Ip_RatePolicerEntryDataType that contains the data of rate policer entry
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddOrUpdateRatePolicerTableEntry( const uint8 CtrlIndex,
                                                                     Netc_Eth_Ip_CommandsType Cmd,
                                                                     uint32 *MatchedEntries,
                                                                     const Netc_Eth_Ip_RatePolicerEntryDataType * RatePolicerTableEntry
                                                                   );

/**
 * @brief Query rate policer table entry.
 *
 * @param[in]   CtrlIndex Instance number
 * @param[out]  MatchedEntries   Number of matched entries
 * @param[in]   RatePolicerEntryId       Rate policer table entry id
 * @param[out]  RatePolicerTableEntry    pointer to structure Netc_Eth_Ip_RatePolicerEntryRspDataType that contains the data of rate policer entry
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryRatePolicerTableEntry( const uint8 CtrlIndex,
                                                               uint32 *MatchedEntries,
                                                               uint32 RatePolicerEntryId,
                                                               Netc_Eth_Ip_RatePolicerEntryRspDataType * RatePolicerTableEntry
                                                             );

/**
 * @brief Delete rate policer table entry.
 *
 * @param[in]   CtrlIndex Instance number
 * @param[out]  MatchedEntries   Number of matched entries
 * @param[in]   RatePolicerEntryId       Rate policer table entry id
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DeleteRatePolicerTableEntry( const uint8 CtrlIndex,
                                                                uint32 *MatchedEntries,
                                                                uint32 RatePolicerEntryId
                                                              );
#endif /* (NETC_ETH_IP_NUMBER_OF_RP_ENTRIES > 0) */

/**
 * @brief Add MAC Filter Table entry.
 *
 * @param[in]  CtrlIndex Instance number
 * @param[in]  MacFilterTableEntry  pointer to structure Netc_Eth_Ip_MacFilterTableEntryDataType that contains the data of the MAC Filter Table entry
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddMacFilterTableEntry(const uint8 ctrlIndex, const Netc_Eth_Ip_MacFilterTableEntryDataType *MacFilterTableEntry);

/**
 * @brief Add MAC Filter Table entry.
 *
 * @param[in]  CtrlIndex Instance number
 * @param[in,out]  MacFilterTableEntry  pointer to structure Netc_Eth_Ip_MacFilterTableEntryDataType that contains the data of the MAC Filter Table entry
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryMacFilterTableEntry(const uint8 ctrlIndex, Netc_Eth_Ip_MacFilterTableEntryDataType *MacFilterTableEntry);

/**
 * @brief Add VLAN Filter Table entry.
 *
 * @param[in]  CtrlIndex Instance number
 * @param[in]  VLANTableEntry  pointer to structure Netc_Eth_Ip_VLANFilterTableEntryDataType that contains the data of the VLAN Filter Table entry
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddVLANFilterTableEntry( const uint8 ctrlIndex, const Netc_Eth_Ip_VLANFilterTableEntryDataType *VLANTableEntry);

/**
 * @brief Query VLAN Filter Table entry. Uses the entry ID for the entry and updates the rest of the fields in the structure if the entry is found.
 *
 * @param[in]  CtrlIndex Instance number
 * @param[in,out]  VLANTableEntry  pointer to structure Netc_Eth_Ip_VLANFilterTableEntryDataType that contains the data of the VLAN Filter Table entry
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryVLANFilterTableEntry(const uint8 ctrlIndex, Netc_Eth_Ip_VLANFilterTableEntryDataType *VLANTableEntry);

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
/**
 * @brief Set management information for a frame which will be send using management.
 *
 * @param CtrlIdx Instance number
 * @param BuffIdx Unique buffer index id.
 * @param SwitchIndex Index number of the switch to be used by the frame
 * @param PortIndex Index identifier of the switch's port to be used by the frame
 * @param Enable Enable/Disable management transmission on this frame.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ManagementFrame(const uint8 CtrlIdx, uint16 BuffIdx, uint8 SwitchIndex, uint8 PortIndex, boolean Enable);

/**
 * @brief Set a management frame to be sent as a timestamping one
 * @param CtrlIdx Instance number
 * @param BuffIdx Unique buffer index id.
 * @param Enable Enable/Disable timestamping for this frame
 **/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_TimestampTxFrame(const uint8 CtrlIdx, const uint16 BuffIdx, const boolean Enable);

/**
 * @brief
 *
 * @param CtrlIndex Instance number
 * @param Ring
 * @return void
 * @internal This function is not an API.

 */
void Netc_Eth_Ip_ReleaseUnusedTxBuff(uint8 CtrlIndex, uint8 Ring);

/**
 * @brief Get a pointer to the timestamp information of a particular TX frame.
 *
 * @param CtrlIdx Instance number
 * @param BuffIdx Unique buffer index id.
 * @param MgmtInfo Pointer to management information for the frame identified by BuffIdx
 * @param TimestampInfo Pointer to timestamp information for the frame identified by BuffIdx
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - succesfully returned a pointer to the latest timestamp information
 *                                NETC_ETH_IP_STATUS_ERROR - no timestamp information found for the requested frame
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTxTimestampInfo(const uint8 CtrlIdx, const uint32 BuffIdx, Netc_Eth_Ip_TxManagementInfoType **MgmtInfo, Netc_Eth_Ip_TxTimestampInfoType **TimestampInfo);

#endif /* NETC_ETH_0_USED */

/**
 * @brief Get a pointer to the Ingress timestamp information of a particular RX frame.
 *
 * @param[in] CtrlIdx - Index of the SI.
 * @param[in] DataPtr - Data buffer address of the received frame for which the timestamp information is requested.
 * @param[out] RxTimestampInfo  Pointer to the timestamp information.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - succesfully returned a pointer to the latest timestamp information
 *                                NETC_ETH_IP_STATUS_ERROR - no timestamp information found for the requested frame
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetRxTimestampInfo(const uint8 CtrlIdx, const uint8 *DataPtr, Netc_Eth_Ip_RxTimestampInfoType **RxTimestampInfo);

#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */

/**
 * @brief Function updates the time pointer value with the current sys time
 *
 * @param ctrlIndex Index of the Eth controller.
 * @param TimePtr Current time stamp pointer
 */
void Netc_Eth_Ip_GetSysTime(uint8 ctrlIndex, Netc_Eth_Ip_TimeType *TimePtr);

/**
 * @brief Function de-initialises VSI controller.
 * PSI de-init not supported since it will also reset all VSIs
 * VSI-PSI messaging interrupt needs to be configured for the VSI reconfiguration, done by the PSI
 *
 * @param ctrlIndex Index of the Eth controller.
 * @retval NETC_ETH_IP_STATUS_SUCCESS The de-initialization was successful.
 * @retval NETC_ETH_IP_STATUS_TIMEOUT The de-initialization returned a timeout.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_Deinit(uint8 ctrlIndex);

/**
 * @brief Checks the status of a transmissions and releases the resources
 * @internal This function is not an API, but an internal function that needs to be used in the upper layer.
 *
 *
 * @param ctrlIndex             Index of the SI.
 * @param ring                  Ring Number.
 * @param ConsumerIndex         Consumer read from HW.
 * @param buff                  Buffer address.
 * @param info                  Parameter where the timestamp and the the transmission status can be provided for the transmitted frame.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_TIMEOUT - Only for VSIs - the command was not processed in time
 * @internal This function is not an API.
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_CheckFrameStatus(uint8 ctrlIndex,
                                                    uint8 ring,
                                                    uint32 ConsumerIndex,
                                                    const uint8 *buff,
                                                    Netc_Eth_Ip_TxInfoType *info);

/**
 * @brief The Pcie Event Collector Interrupt handler
 * @internal This function is not an API. It must be added in the Interrupt Controller configuration as a handler.
 *
 * @param ctrlIndex             Index of the SI.
 * @return void
 */
void Netc_Eth_Ip_PCIe_AER_Handler(uint8 ctrlIndex);

/**
 * @brief         Enable/Disable the ingress port filter feature on ENETC port
 *
 * @param[in]     CtrlIndex            Index of the controller within the context of the Ethernet Driver
 * @param[in]     Enable               TRUE: enable ingress port filter feature. FALSE: disable ingress port filter feature.
 *
 */
Std_ReturnType Netc_Eth_Ip_EnableIngressPortFiltering(const uint8 CtrlIndex, boolean Enable );

/**
 * @brief Add ingress port filter table entry.
 *
 * @param[in]   CtrlIndex Instance number
 * @param[out]  MatchedEntries   Number of matched entries
 * @param[in]   IngressPortFilterTableEntry    pointer to structure Netc_Eth_Ip_IngressPortFilterEntryDataType that contains the data of ingress port filter entry
 * @param[out]  IngressPortFilterTableEntry    pointer to structure Netc_Eth_Ip_IngressPortFilterEntryDataType that contains the data of ingress port filter entry
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddIngressPortFilterTableEntry( uint8 CtrlIndex,
                                                                   uint32 *MatchedEntries,
                                                                   Netc_Eth_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry
                                                                 );

/**
 * @brief Query ingress port filter table entry.
 *
 * @param[in]   CtrlIndex Instance number
 * @param[out]  MatchedEntries   Number of matched entries
 * @param[in]   IngressPortFilterTableEntry    pointer to structure Netc_Eth_Ip_IngressPortFilterEntryDataType that contains the data of ingress port filter entry
 * @param[out]  IngressPortFilterTableEntry    pointer to structure Netc_Eth_Ip_IngressPortFilterEntryDataType that contains the data of ingress port filter entry
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryIngressPortFilterTableEntry( const uint8 CtrlIndex,
                                                                     uint32 *MatchedEntries,
                                                                     Netc_Eth_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry
                                                                   );

/**
 * @brief Delete ingress port filter table entry.
 *
 * @param[in]   CtrlIndex Instance number
 * @param[out]  MatchedEntries   Number of matched entries
 * @param[in]   IngressPortFilterEntryId       Ingress port filter table entry id
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DeleteIngressPortFilterTableEntry( const uint8 CtrlIndex,
                                                                      uint32 *MatchedEntries,
                                                                      uint32 IngressPortFilterEntryId
                                                                    );


/**
 * @brief This function dumps the Error Capture registers for a specific PCIE device (function).
* @param[in]  ctrlIndex                Index of the SI. Input Parameter
* @param[in]  function                 The PCIE function for which the error statistics are requested.Input Parameter
* @param[out] numberOfRegisters        This is an output parameter. The function returns the number of statistics registers that have been written in the Buffer parameter.
* @param[in]  siIndex                  This is an input parameter. Must be used only if he function is VSI or PSI. For PSI it must be set to 0 while for VSI must be set to the index of the SI.
*                                      For other functions(ENET, TIMER, SWITCH, EMDIO), this parameter is ignored.
* @param[in]  Buffers                  Array of pointers to Netc_Eth_Ip_ErrorCaptureRegisterInformation structures.
        *                              Application MUST allocate enough space for the maximum number of
        *                              registers that could have a function for Error detailing.
        *                              Netc driver offers two macros: NETC_ETH_IP_MAX_UNCORRECTABLE_ERROR_REPORTING_STATISTICS_LENGTH for the maximum number of
        *                              uncorrectable errors status registers among the PCIE function supported and
        *                              NETC_ETH_IP_MAX_CORRECTABLE_ERROR_REPORTING_STATISTICS_LENGTH for the maximum number of
        *                              correctable errors status registers among the PCIE function supported.
 * @return void
 */
void Netc_Eth_Ip_DumpErrorCapture (     const uint8 ctrlIdx,
                                        const Netc_Eth_Ip_PcieFunction function,
                                        uint8 *numberOfRegisters,
                                        uint8 siIndex,
                                        Netc_Eth_Ip_ErrorCaptureRegisterInformation* const Buffers[]);

/**
 * @brief This function gets Timer Syncronization State function.
* @param[in]  CtrlIndex                Index of the SI. Input Parameter
* @param[out]  SyncState                 Timer Syncronization State
*
* @return          Netc_Eth_Ip_StatusType
* @retval          NETC_ETH_IP_STATUS_SUCCESS: successful.
* @retval          NETC_ETH_IP_STATUS_TIMEOUT: failed
*/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetSyncState( const uint8 CtrlIndex,
                                                boolean *SyncState);
/*
 * @brief Query statistics Receive Flow Steering table entry.
 *
 * @param[in]   ctrlIndex Instance number
 * @param[in]   RfsTableEntry   Rfs Entry for querying
 * @param[out]  MatchedFramesNb    Number of matched frames
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryStatisticsRfsTableEntry(const uint8 ctrlIndex,
                                                                uint8 RfsEntryIdx,
                                                                 uint32 * MatchedFramesNb);

/**
 * @brief Query Receive Flow Steering table entry.
 *
 * @param[in]   ctrlIndex Instance number
 * @param[in]   RfsTableEntry   Rfs Entry for querying
 * @param[out]  RfsTableEntryAddr    Address of matched rfs entry
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryRfsTableEntry(const uint8 ctrlIndex,
                                                                uint8 RfsEntryIdx,
                                                                const uint32 * RfsTableEntryAddr);

/**
 * @brief Add Receive Flow Steering table entry.
 *
 * @param[in]   ctrlIndex Instance number
 * @param[in]   RfsTableEntry   Rfs Entry to add
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                others - error code from command ring
 */
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddRfsTableEntry(const uint8 ctrlIndex,
                                                     const Netc_Eth_Ip_RfsEntryType * RfsTableEntry);

/**
 * @brief This function sets SIs MAC address.
* @param[in]  CtrlIndex           Index of the current controller. Input Parameter
* @param[in]  SiId                Index of the SI which will have the MAC address changed. Input Parameter
* @param[in]  MacAddr             MAC address. Input Parameter
*
* @return          Netc_Eth_Ip_StatusType
* @retval          NETC_ETH_IP_STATUS_SUCCESS: successful.
* @retval          NETC_ETH_IP_STATUS_UNSUPPORTED: SI identified by ctrlIndex parameter has type different than PSI
*/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetSiPhysAddr( const uint8 CtrlIndex,
                                                    const uint8 SiId,
                                                    const uint8 *MacAddr);

#if defined(ERR_IPV_NETC_051247)
    #if (STD_ON == ERR_IPV_NETC_051247)
/**
 * @brief This function calculates CRC16 CCITT-FALSE for the VSItoPSI message
* @param[in]  MsgCommandConfig           Pointer to the message
* @param[in]  MsgLength                  Message length
*
* @return          uint16
* @retval          resulted crc
*/
uint16 Netc_Eth_Ip_VsiMsgCalculateCRC16(volatile Netc_Eth_Ip_VsiToPsiMsgType const *MsgCommandConfig, \
                                                    uint8 MsgLength);
    #endif
#endif

#if defined(NETC_ETH_IP_FILL_LEVEL_API_ENABLE)
#if (NETC_ETH_IP_FILL_LEVEL_API_ENABLE == STD_ON)
/**
 * @brief Get data on how much of a Tx Ring is occupied
 * @param[in]   CtrlIndex           Index of the current controller
 * @param[in]   RingIdx             Index of the queried Tx ring on the controller
 * @param[in]   FillInfo            Pointer to data structure to be populated with information about the Tx ring
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successful operation
 *                                others - function called with invalid parameters or null pointers
*/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTxRingFillLevel(const uint8 CtrlIndex, const uint8 RingIdx, Netc_Eth_Ip_FillLevelInfo * FillInfo);

/**
 * @brief Get data on how much of a Rx Ring is occupied
 * @param[in]   CtrlIndex           Index of the current controller
 * @param[in]   RingIdx             Index of the queried Rx ring on the controller
 * @param[in]   FillInfo            Pointer to data structure to be populated with information about the Rx ring
 *
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successful operation
 *                                others - function called with invalid parameters or null pointers
*/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetRxRingFillLevel(const uint8 CtrlIndex, const uint8 RingIdx, Netc_Eth_Ip_FillLevelInfo * FillInfo);
#endif  /* STD_ON == NETC_ETH_IP_FILL_LEVEL_API_ENABLE  */
#endif /* defined(NETC_ETH_IP_FILL_LEVEL_API_ENABLE) */

#define ETH_43_NETC_STOP_SEC_CODE
#include "Eth_43_NETC_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif
