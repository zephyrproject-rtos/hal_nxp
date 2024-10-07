/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file    Srx_Ip_Irq.c
*   @version 2.0.1
*
*   @brief   AUTOSAR Sent - Low level part of Sent driver.
*   @details This file contains the functions defined by AutoSAR.
*
*   @addtogroup SRX_IP_DRIVER
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
/**
* @file           Srx_Ip_Irq.c
*/
#include "Mcal.h"
#include "Srx_Ip.h"
#include "Srx_Ip_Types.h"
#include "Srx_Ip_HwAccess.h"
#ifdef SRX_IP_DMA_FEATURE_ENABLE
#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
#endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* The integration of incompatible files shall be avoided. */
/**
* @file           Srx_Ip_Irq.c
*/
#define SRX_IP_IRQ_VENDOR_ID_C                    43
#define SRX_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
#define SRX_IP_IRQ_AR_RELEASE_MINOR_VERSION_C     7
#define SRX_IP_IRQ_AR_RELEASE_REVISION_VERSION_C  0
#define SRX_IP_IRQ_SW_MAJOR_VERSION_C             2
#define SRX_IP_IRQ_SW_MINOR_VERSION_C             0
#define SRX_IP_IRQ_SW_PATCH_VERSION_C             1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (SRX_IP_IRQ_VENDOR_ID_C != SRX_IP_TYPES_VENDOR_ID)
#error "Srx_Ip_Irq.c and Srx_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Srx_Ip.h   header file are of the same Autosar version */
#if ((SRX_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != SRX_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SRX_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != SRX_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SRX_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != SRX_IP_TYPES_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Srx_Ip_Irq.c and Srx_Ip_Types.h are different"
#endif

/* Check if current file and Srx_Ip.h  header file are of the same software version */
#if ((SRX_IP_IRQ_SW_MAJOR_VERSION_C != SRX_IP_TYPES_SW_MAJOR_VERSION) || \
     (SRX_IP_IRQ_SW_MINOR_VERSION_C != SRX_IP_TYPES_SW_MINOR_VERSION) || \
     (SRX_IP_IRQ_SW_PATCH_VERSION_C != SRX_IP_TYPES_SW_PATCH_VERSION))
  #error "Software Version Numbers of Srx_Ip_Irq.c and Srx_Ip_Types.h are different"
#endif

/* Check if current file and Mcal.h header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((SRX_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SRX_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Srx_Ip_Irq.c and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"

#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
    void Srx_Ip_DmaFastCtrl0Ch0CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl0Ch1CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl0Ch2CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl0Ch3CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl0Ch4CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl0Ch5CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl0Ch6CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl0Ch7CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl1Ch0CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl1Ch1CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl1Ch2CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl1Ch3CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl1Ch4CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl1Ch5CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl1Ch6CompletionNotif(void);
    void Srx_Ip_DmaFastCtrl1Ch7CompletionNotif(void);

    void Srx_Ip_DmaSerialCtrl0Ch0CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl0Ch1CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl0Ch2CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl0Ch3CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl0Ch4CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl0Ch5CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl0Ch6CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl0Ch7CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl1Ch0CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl1Ch1CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl1Ch2CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl1Ch3CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl1Ch4CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl1Ch5CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl1Ch6CompletionNotif(void);
    void Srx_Ip_DmaSerialCtrl1Ch7CompletionNotif(void);
#endif
#if (SRX_IP_INTERRUPT_COMBINED == STD_ON)

/* SERIAL MESSAGE COMBINED HANDLER */
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_COMBINED
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Combined);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_COMBINED
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Combined);
    #endif

/* FAST MESSAGE COMBINED HANDLER */
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_COMBINED
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Combined);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_COMBINED
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Combined);
    #endif

/* ERROR COMBINED HANDLER */
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_COMBINED
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Combined);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_COMBINED
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Combined);
    #endif
#else
/* SERIAL MESSAGE CHANNEL HANDLER */
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH0
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch0);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH1
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch1);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH2
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch2);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH3
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch3);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH4
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch4);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH5
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch5);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH6
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch6);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH7
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch7);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH0
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch0);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH1
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch1);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH2
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch2);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH3
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch3);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH4
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch4);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH5
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch5);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH6
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch6);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH7
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch7);
    #endif

/* FAST MESSAGE CHANNEL HANDLER */
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH0
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch0);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH1
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch1);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH2
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch2);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH3
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch3);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH4
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch4);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH5
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch5);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH6
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch6);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH7
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch7);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH0
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch0);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH1
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch1);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH2
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch2);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH3
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch3);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH4
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch4);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH5
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch5);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH6
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch6);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH7
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch7);
    #endif

/* ERROR CHANNEL HANDLER */
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH0
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch0);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH1
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch1);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH2
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch2);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH3
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch3);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH4
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch4);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH5
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch5);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH6
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch6);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH7
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch7);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH0
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch0);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH1
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch1);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH2
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch2);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH3
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch3);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH4
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch4);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH5
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch5);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH6
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch6);
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH7
        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch7);
    #endif
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 0 channel 0
    */
    void Srx_Ip_DmaFastCtrl0Ch0CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 0U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 0 channel 1
    */
    void Srx_Ip_DmaFastCtrl0Ch1CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 1U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 0 channel 2
    */
    void Srx_Ip_DmaFastCtrl0Ch2CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 2U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 0 channel 3
    */
    void Srx_Ip_DmaFastCtrl0Ch3CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 3U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 0 channel 8
    */
    void Srx_Ip_DmaFastCtrl0Ch4CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 4U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 0 channel 7
    */
    void Srx_Ip_DmaFastCtrl0Ch5CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 5U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 0 channel 7
    */
    void Srx_Ip_DmaFastCtrl0Ch6CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 6U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 0 channel 7
    */
    void Srx_Ip_DmaFastCtrl0Ch7CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 7U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 1 channel 0
    */
    void Srx_Ip_DmaFastCtrl1Ch0CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 0U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 1 channel 1
    */
    void Srx_Ip_DmaFastCtrl1Ch1CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 1U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 1 channel 2
    */
    void Srx_Ip_DmaFastCtrl1Ch2CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 2U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 1 channel 3
    */
    void Srx_Ip_DmaFastCtrl1Ch3CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 3U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 1 channel 4
    */
    void Srx_Ip_DmaFastCtrl1Ch4CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 4U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 1 channel 5
    */
    void Srx_Ip_DmaFastCtrl1Ch5CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 5U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 1 channel 6
    */
    void Srx_Ip_DmaFastCtrl1Ch6CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 6U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Fast message on SENT controller 1 channel 7
    */
    void Srx_Ip_DmaFastCtrl1Ch7CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 7U, SRX_IP_FAST_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 0 channel 0
    */
    void Srx_Ip_DmaSerialCtrl0Ch0CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 0U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 0 channel 1
    */
    void Srx_Ip_DmaSerialCtrl0Ch1CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 1U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 0 channel 2
    */
    void Srx_Ip_DmaSerialCtrl0Ch2CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 2U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 0 channel 3
    */
    void Srx_Ip_DmaSerialCtrl0Ch3CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 3U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 0 channel 8
    */
    void Srx_Ip_DmaSerialCtrl0Ch4CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 4U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 0 channel 7
    */
    void Srx_Ip_DmaSerialCtrl0Ch5CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 5U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 0 channel 7
    */
    void Srx_Ip_DmaSerialCtrl0Ch6CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 6U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 0 channel 7
    */
    void Srx_Ip_DmaSerialCtrl0Ch7CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(0U, 7U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 1 channel 0
    */
    void Srx_Ip_DmaSerialCtrl1Ch0CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 0U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 1 channel 1
    */
    void Srx_Ip_DmaSerialCtrl1Ch1CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 1U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 1 channel 2
    */
    void Srx_Ip_DmaSerialCtrl1Ch2CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 2U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 1 channel 3
    */
    void Srx_Ip_DmaSerialCtrl1Ch3CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 3U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 1 channel 4
    */
    void Srx_Ip_DmaSerialCtrl1Ch4CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 4U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 1 channel 5
    */
    void Srx_Ip_DmaSerialCtrl1Ch5CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 5U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 1 channel 6
    */
    void Srx_Ip_DmaSerialCtrl1Ch6CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 6U, SRX_IP_SERIAL_MSG_ONLY);
    }

    /**
    * @brief          Independent Dma handler.
    * @details        Dma handler for Serial message on SENT controller 1 channel 7
    */
    void Srx_Ip_DmaSerialCtrl1Ch7CompletionNotif(void)
    {
        Srx_Ip_DmaNotificationHandler(1U, 7U, SRX_IP_SERIAL_MSG_ONLY);
    }
#endif


/* =================== FAST MESSAGE HANDLER ========================= */
#if (SRX_IP_INTERRUPT_COMBINED == STD_ON)

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_COMBINED
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 0
        *
        * @isr
        */
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Combined)
        {
            Srx_Ip_ProcessMsgCombinedInterrupt(0U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_COMBINED
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 1
        *
        * @isr
        */
        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Combined)
        {
            Srx_Ip_ProcessMsgCombinedInterrupt(1U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

#else

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH0
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 0 CHANNEL 0
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch0)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 0U, SRX_IP_FAST_MSG_ONLY);

        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH1
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 0 CHANNEL 1
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch1)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 1U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH2
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 0 CHANNEL 2
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch2)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 2U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH3
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 0 CHANNEL 3
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch3)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 3U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH4
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 0 CHANNEL 4
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch4)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 4U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH5
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 0 CHANNEL 5
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch5)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 5U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH6
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 0 CHANNEL 6
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch6)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 6U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL0_CH7
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 0 CHANNEL 7
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl0_Ch7)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 7U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH0
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 1 CHANNEL 0
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch0)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 0U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH1
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 1 CHANNEL 1
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch1)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 1U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH2
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 1 CHANNEL 2
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch2)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 2U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH3
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 1 CHANNEL 3
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch3)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 3U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH4
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 1 CHANNEL 4
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch4)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 4U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH5
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 1 CHANNEL 5
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch5)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 5U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH6
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 1 CHANNEL 6
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch6)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 6U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_FAST_MESSAGE_HANDLER_CTRL1_CH7
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Fast message on SENT 1 CHANNEL 7
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessFastMessageHandler_Ctrl1_Ch7)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 7U, SRX_IP_FAST_MSG_ONLY);
        }
    #endif
#endif  /* end SRX_IP_INTERRUPT_COMBINED = STD_OFF */

/* =================== SERIAL MESSAGE HANDLER ========================= */
#if (SRX_IP_INTERRUPT_COMBINED == STD_ON)
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_COMBINED
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 0
        *
        * @isr
        */
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Combined)
        {
            Srx_Ip_ProcessMsgCombinedInterrupt(0U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif
    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_COMBINED
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 1
        *
        * @isr
        */
        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Combined)
        {
            Srx_Ip_ProcessMsgCombinedInterrupt(1U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

#else

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH0
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 0 CHANNEL 0
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch0)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 0U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH1
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 0 CHANNEL 1
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch1)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 1U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH2
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 0 CHANNEL 2
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch2)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 2U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH3
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 0 CHANNEL 3
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch3)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 3U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH4
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 0 CHANNEL 4
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch4)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 4U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH5
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 0 CHANNEL 5
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch5)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 5U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH6
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 0 CHANNEL 6
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch6)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 6U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL0_CH7
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 0 CHANNEL 7
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl0_Ch7)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(0U, 7U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH0
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 1 CHANNEL 0
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch0)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 0U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH1
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 1 CHANNEL 1
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch1)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 1U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH2
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 1 CHANNEL 2
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch2)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 2U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH3
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 1 CHANNEL 3
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch3)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 3U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH4
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 1 CHANNEL 4
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch4)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 4U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH5
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 1 CHANNEL 5
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch5)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 5U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH6
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 1 CHANNEL 6
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch6)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 6U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_SERIAL_MESSAGE_HANDLER_CTRL1_CH7
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Serial message on SENT 1 CHANNEL 7
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessSerialMessageHandler_Ctrl1_Ch7)
        {
            Srx_Ip_ProcessMsgChannelInterrupt(1U, 7U, SRX_IP_SERIAL_MSG_ONLY);
        }
    #endif

#endif

/* =================== ERROR HANDLER ========================= */
#if (SRX_IP_INTERRUPT_COMBINED == STD_ON)
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_COMBINED
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 0
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Combined)
        {
            Srx_Ip_ProcessErrorCombinedInterrupt(0U);
        }
    #endif
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_COMBINED
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 1
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Combined)
        {
            Srx_Ip_ProcessErrorCombinedInterrupt(1U);
        }
    #endif
#else
    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH0
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 0 CHANNEL 0
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch0)
        {
            Srx_Ip_ProcessChannelError(0U, 0U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH1
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 0 CHANNEL 1
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch1)
        {
            Srx_Ip_ProcessChannelError(0U, 1U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH2
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 0 CHANNEL 2
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch2)
        {
            Srx_Ip_ProcessChannelError(0U, 2U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH3
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 0 CHANNEL 3
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch3)
        {
            Srx_Ip_ProcessChannelError(0U, 3U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH4
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 0 CHANNEL 4
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch4)
        {
            Srx_Ip_ProcessChannelError(0U, 4U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH5
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 0 CHANNEL 5
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch5)
        {
            Srx_Ip_ProcessChannelError(0U, 5U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH6
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 0 CHANNEL 6
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch6)
        {
            Srx_Ip_ProcessChannelError(0U, 6U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL0_CH7
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 0 CHANNEL 7
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl0_Ch7)
        {
            Srx_Ip_ProcessChannelError(0U, 7U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH0
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 1 CHANNEL 0
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch0)
        {
            Srx_Ip_ProcessChannelError(1U, 0U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH1
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 1 CHANNEL 1
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch1)
        {
            Srx_Ip_ProcessChannelError(1U, 1U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH2
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 1 CHANNEL 2
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch2)
        {
            Srx_Ip_ProcessChannelError(1U, 2U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH3
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 1 CHANNEL 3
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch3)
        {
            Srx_Ip_ProcessChannelError(1U, 3U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH4
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 1 CHANNEL 4
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch4)
        {
            Srx_Ip_ProcessChannelError(1U, 4U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH5
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 1 CHANNEL 5
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch5)
        {
            Srx_Ip_ProcessChannelError(1U, 5U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH6
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 1 CHANNEL 6
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch6)
        {
            Srx_Ip_ProcessChannelError(1U, 6U, SRX_IP_INTERRUPT);
        }
    #endif

    #ifdef SRX_IP_ISR_PROCESS_ERROR_HANDLER_CTRL1_CH7
        /**
        * @brief          Independent interrupt handler.
        * @details        Interrupt handler for Error on SENT 1 CHANNEL 7
        *
        * @isr
        */

        ISR(Srx_Ip_IsrProcessErrorHandler_Ctrl1_Ch7)
        {
            Srx_Ip_ProcessChannelError(1U, 7U, SRX_IP_INTERRUPT);
        }
    #endif

#endif

#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
