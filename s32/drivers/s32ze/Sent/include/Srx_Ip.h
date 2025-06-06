/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Srx_Ip.h
*   @version 2.0.1
*
*   @brief   AUTOSAR Sent - Low level header of Sent driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
*
*   @addtogroup SRX_IP_DRIVER
*   @{
*/

#ifndef SRX_IP_H
#define SRX_IP_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Srx_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SRX_IP_VENDOR_ID                    43
#define SRX_IP_AR_RELEASE_MAJOR_VERSION     4
#define SRX_IP_AR_RELEASE_MINOR_VERSION     7

#define SRX_IP_AR_RELEASE_REVISION_VERSION  0
#define SRX_IP_SW_MAJOR_VERSION             2
#define SRX_IP_SW_MINOR_VERSION             0
#define SRX_IP_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                           MACROS
=====================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"

/**
* @brief        Function that initializes the SENT controller.
* @details      This function initializes register for SENT controller.
*
* @param[in]    pController - Pointer point to controller configuration
*
* @return       void
*
*/
void Srx_Ip_InitController
(
    const Srx_Ip_ControllerConfigType* pController
);

/**
* @brief        Function that de-initializes the SENT controller.
* @details      This function de-initializes register for SENT controller and its channel which "ControllerId" is index of controller
*
* @param[in]    ControllerId - Controller index in configuration
*
* @return       void
*
*/
void Srx_Ip_DeInitController
(
    uint8 ControllerId
);

/**
* @brief        Function that performs polling of Sent Fast and/or Serial Message on a channel.
* @details      This function performs polling of Fast and/or Serial Message on channel and notify for user by channel notification.
*
* @param        ControllerId        : The index of controller.
* @param        ChannelId           : The index of channel.
* @param        ReceivedMsgType     : The type of message should be received.
*
* @return       E_OK : Channel request has been accepted.
*               E_NOT_OK : Channel request has not been accepted.
*
*/
Srx_Ip_StatusType Srx_Ip_GetChannelMsgData
(
    uint8  ControllerId,
    uint8  ChannelId,
    Srx_Ip_ReceivedMsgType ReceivedMsgType
);

/**
* @brief        Function that performs polling of Sent Fast and/or Serial Message on all configured channel at a specific controller.
* @details      Function that performs polling of Sent Fast and/or Serial Message on all configured channel at a specific controller.
*
* @param        ControllerId        : The index of controller.
* @param        ReceivedMsgType     : The type of message should be received.
*
* @return      void
*
*/
void Srx_Ip_GetControllerMsgData
(
    uint8  ControllerId,
    Srx_Ip_ReceivedMsgType ReceivedMsgType
);

/**
* @brief        This function shall enable a specific channel in order to start receiving from the bus.
* @brief        This function shall enable a specific channel in order to start receiving from the bus.
*
* @param        ControllerId        : The index of controller.
* @param        ChannelId           : The index of channel.
*
* @return       E_OK : Channel request has been accepted.
*               E_NOT_OK : Channel request has not been accepted.
*
*/
Srx_Ip_StatusType Srx_Ip_StartChannelReceiving
(
    uint8  ControllerId,
    uint8  ChannelId
);

/**
* @brief        This function shall disable a specific channel in order to stop receiving from the bus.
* @brief        This function shall disable a specific channel in order to stop receiving from the bus.
*
* @param        ControllerId        : The index of controller.
* @param        ChannelId           : The index of channel.
*
* @return       E_OK : Channel request has been accepted.
*               E_NOT_OK : Channel request has not been accepted.
*
*/
Srx_Ip_StatusType Srx_Ip_StopChannelReceiving
(
    uint8  ControllerId,
    uint8  ChannelId
);

#if (SRX_IP_INTERRUPT_COMBINED == STD_ON)
/**
* @brief       Interrupt handler for fast and serial msg in case using combined interrupt on interrupt mode.
* @brief        Interrupt handler for fast and serial msg in case using combined interrupt on interrupt mode.
*
* @param        HwCtrlOffset:       The offset of controller.
* @param        ReceivedMsgType:    The type of message should be received.
*
* @return       void
*
*/
void Srx_Ip_ProcessMsgCombinedInterrupt
(
    uint8 HwCtrlOffset,
    Srx_Ip_ReceivedMsgType ReceivedMsgType
);

/**
* @brief       Error handler for fast and serial incase using combined interrupt on interrupt mode.
* @brief       Error handler for fast and serial incase using combined interrupt on interrupt mode.
*
* @param        HwCtrlOffset:       The offset of controller.
*
* @return       void
*
*/
void Srx_Ip_ProcessErrorCombinedInterrupt
(
    uint8 HwCtrlOffset
);
#else

/**
* @brief       Process fast and serial msg interrupt in case using separated interrupt.
* @brief       Process fast and serial msg interrupt in case using separated interrupt.
*
* @param        HwCtrlOffset:       The offset of controller.
* @param        HwChnlOffset:       The offset of channel.
* @param        ReceivedMsgType:    The type of message should be received.
*
* @return       void
*
*/
void Srx_Ip_ProcessMsgChannelInterrupt
(
    uint8 HwCtrlOffset,
    uint8 HwChnlOffset,
    Srx_Ip_ReceivedMsgType ReceivedMsgType
);
#endif

#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
/**
*   @brief          This function initializes DMA for Fast
*
* @param        HwCtrlOffset:       The offset of controller.
* @param        HwChnlOffset:       The offset of channel.
* @param        ReceivedMsgType:    The type of message should be received.
*
* @return       void
*
*/
void Srx_Ip_DmaNotificationHandler
(
    uint8 HwCtrlOffset,
    uint8 HwChnlOffset,
    Srx_Ip_ReceivedMsgType ReceivedMsgType
);
#endif

/**
* @brief       Process error handler of specific channel in case not using interrupt mode with combined interrupt
* @brief       Process error handler of specific channel in case not using interrupt mode with combined interrupt.
*
* @param        HwCtrlOffset: The offset of controller.
* @param        HwChnlOffset: The offset of channel.
* @param        Mode:         Controller mode
*
* @return       void
*
*/
void Srx_Ip_ProcessChannelError
(
    uint8 HwCtrlOffset,
    uint8 HwChnlOffset,
    Srx_Ip_ReceivedMode Mode
);
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#ifdef __cplusplus
          }
#endif

#endif /* SRX_IP_H */

/** @} */
