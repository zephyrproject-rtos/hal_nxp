/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LINFLEXD_UART_IP_TYPES_H
#define LINFLEXD_UART_IP_TYPES_H

/**
*   @file
*   @defgroup linflexd_uart_ip Linflexd UART IPL
*   @addtogroup  linflexd_uart_ip Linflexd UART IPL
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
#include "Std_Types.h"
#include "Linflexd_Uart_Ip_HwAccess.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_UART_IP_TYPES_VENDOR_ID                    43
#define LINFLEXD_UART_IP_TYPES_MODULE_ID                    255
#define LINFLEXD_UART_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define LINFLEXD_UART_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define LINFLEXD_UART_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define LINFLEXD_UART_IP_TYPES_SW_MAJOR_VERSION             2
#define LINFLEXD_UART_IP_TYPES_SW_MINOR_VERSION             0
#define LINFLEXD_UART_IP_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Linflexd_Uart_Ip_HwAccess.h */
#if (LINFLEXD_UART_IP_HWACCESS_VENDOR_ID != LINFLEXD_UART_IP_TYPES_VENDOR_ID)
    #error "Linflexd_Uart_Ip_HwAccess.h and Linflexd_Uart_Ip_Types.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != LINFLEXD_UART_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != LINFLEXD_UART_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != LINFLEXD_UART_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_HwAccess.h and Linflexd_Uart_Ip_Types.h are different"
#endif
#if ((LINFLEXD_UART_IP_HWACCESS_SW_MAJOR_VERSION != LINFLEXD_UART_IP_TYPES_SW_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_HWACCESS_SW_MINOR_VERSION != LINFLEXD_UART_IP_TYPES_SW_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_HWACCESS_SW_PATCH_VERSION != LINFLEXD_UART_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Uart_Ip_HwAccess.h and Linflexd_Uart_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Std_Types.h header file are of the same Autosar version */
    #if ((LINFLEXD_UART_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_UART_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Linflexd_Uart_Ip_Types.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       TYPES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
 * @brief Type of UART a-sync transfer (based on interrupts or DMA).
 *
 *
 */
typedef enum
{
    LINFLEXD_UART_IP_USING_DMA         = 0U,    /**< @brief The driver will use DMA to perform UART transfer */
    LINFLEXD_UART_IP_USING_INTERRUPTS  = 1U     /**< @brief The driver will use interrupts to perform UART transfer */
} Linflexd_Uart_Ip_TransferType;

/**
* @brief          The type operation of an LinflexD Uart channel.
*/
typedef enum
{
    LINFLEXD_UART_IP_SEND    = (uint8)0x00U, /**< @brief The sending operation */
    LINFLEXD_UART_IP_RECEIVE = (uint8)0x01U  /**< @brief The receiving operation */
} Linflexd_Uart_Ip_DataDirectionType;

/**
 * @brief Driver status type.
 *
 *
 * */
typedef enum
{
    LINFLEXD_UART_IP_STATUS_SUCCESS                    = 0x00U,  /**< @brief Generic operation success status */
    LINFLEXD_UART_IP_STATUS_ERROR                      = 0x01U,  /**< @brief Generic operation failure status */
    LINFLEXD_UART_IP_STATUS_BUSY                       = 0x02U,  /**< @brief Generic operation busy status */
    LINFLEXD_UART_IP_STATUS_TIMEOUT                    = 0x03U,  /**< @brief Generic operation timeout status */
    LINFLEXD_UART_IP_STATUS_TX_UNDERRUN                = 0x04U,  /**< @brief TX underrun error */
    LINFLEXD_UART_IP_STATUS_RX_OVERRUN                 = 0x05U,  /**< @brief RX overrun error */
    LINFLEXD_UART_IP_STATUS_ABORTED                    = 0x06U,  /**< @brief* A transfer was aborted */
    LINFLEXD_UART_IP_STATUS_FRAMING_ERROR              = 0x07U,  /**< @brief Framing error */
    LINFLEXD_UART_IP_STATUS_PARITY_ERROR               = 0x08U,  /**< @brief Parity error */
    LINFLEXD_UART_IP_STATUS_NOISE_ERROR                = 0x09U,  /**< @brief Noise error */
    LINFLEXD_UART_IP_STATUS_DMA_ERROR                  = 0x10U,  /**< @brief DMA error */
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
    LINFLEXD_UART_IP_STATUS_RX_IDLE_STATE              = 0x11U,  /**< @brief The idle state of the reception line is generated */
#endif
} Linflexd_Uart_Ip_StatusType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief Define the enum of the Events which can trigger UART callback
 *
 * @details This enum should include the Events for all platforms.
 *
 *
 */
typedef enum
{
    LINFLEXD_UART_IP_EVENT_RX_FULL          = 0x00U,    /**< @brief Rx buffer is full */
    LINFLEXD_UART_IP_EVENT_TX_EMPTY         = 0x01U,    /**< @brief Tx buffer is empty */
    LINFLEXD_UART_IP_EVENT_END_TRANSFER     = 0x02U,    /**< @brief The current transfer is ending */
    LINFLEXD_UART_IP_EVENT_ERROR            = 0x03U,    /**< @brief An error occured during transfer */
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
    LINFLEXD_UART_IP_EVENT_IDLE_STATE       = 0x04U    /**< @brief The idle state of the reception line is generated*/
#endif
} Linflexd_Uart_Ip_EventType;

/**
 * @brief Callback for all peripherals which support UART features
 *
 *
 */
typedef void (*Linflexd_Uart_Ip_CallbackType)(const uint8 HwInstance,
                                              const Linflexd_Uart_Ip_EventType Event,
                                              const void *UserData);


/**
 * @brief Runtime State of the UART driver.
 *
 *
 */
typedef struct
{
    uint32 Baudrate;                                     /**< @brief Variable that indicates if structure belongs to an instance already initialized.*/
    const uint8 * TxBuff;                                  /**< @brief The buffer of data being sent.*/
    uint8 * RxBuff;                                        /**< @brief The buffer of received data.*/
    volatile uint32 TxSize;                              /**< @brief The remaining number of bytes to be transmitted. */
    volatile uint32 RxSize;                              /**< @brief The remaining number of bytes to be received. */
    volatile boolean IsTxBusy;                             /**< @brief True if there is an active transmit.*/
    volatile boolean IsRxBusy;                             /**< @brief True if there is an active receive.*/
    volatile Linflexd_Uart_Ip_StatusType TransmitStatus;   /**< @brief Status of last driver transmit operation */
    volatile Linflexd_Uart_Ip_StatusType ReceiveStatus;    /**< @brief Status of last driver receive operation */
    boolean IsDriverInitialized;                           /**< @brief Variable that indicates if driver is initialized or not */

} Linflexd_Uart_Ip_StateStructureType;

/**
 *  @brief LINFLEXD configuration structure
 *
 * Implements : Linflexd_Uart_Ip_UserConfigType
 */
typedef struct
{
    uint32 BaudRate;                                 /**< @brief Baudrate value*/
    uint32 BaudRateMantissa;                         /**< @brief Baudrate mantissa*/
    uint8 BaudRateDivisor;                           /**< @brief Baudrate Divisor*/
    uint8 BaudRateFractionalDivisor;                 /**< @brief Fractional Baudrate*/
    /**
     *
     * @brief    Parity control - enabled/disabled
     * @details: This parameter is valid only for 8/16 bits words;
     *           for 7/15 word length parity is always enabled
     */
    boolean ParityCheck;

    Linflexd_Uart_Ip_ParityType ParityType;            /**< @brief always 0/always 1/even/odd */
    Linflexd_Uart_Ip_StopBitsCountType StopBitsCount;  /**< @brief number of stop bits, 1 stop bit (default) or 2 stop bits */
    Linflexd_Uart_Ip_WordLengthType WordLength;        /**< @brief number of bits per transmitted/received word */
    Linflexd_Uart_Ip_TransferType TransferType;        /**< @brief Type of UART transfer (interrupt/dma based) */
    Linflexd_Uart_Ip_CallbackType Callback;         /**< @brief Callback to invoke for handling uart event */
    void * CallbackParam;                            /**< @brief Receive callback parameter pointer.*/
#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
    uint32 RxDMAChannel;                               /**< @brief DMA channel number for DMA-based rx.
                                                                    If DMA mode is not used this field will be ignored. */
    uint32 TxDMAChannel;                               /**< @brief DMA channel number for DMA-based tx.
                                                                    If DMA mode is not used this field will be ignored. */
#endif
    Linflexd_Uart_Ip_StateStructureType* StateStruct;  /**< @brief Runtime state structure refference */

} Linflexd_Uart_Ip_UserConfigType;

 /**
*
* @brief   Baudrate values supported by the driver
*/
typedef enum
{
    LINFLEXD_UART_BAUDRATE_1200   = 1200U,
    LINFLEXD_UART_BAUDRATE_2400   = 2400U,
    LINFLEXD_UART_BAUDRATE_4800   = 4800U,
    LINFLEXD_UART_BAUDRATE_7200   = 7200U,
    LINFLEXD_UART_BAUDRATE_9600   = 9600U,
    LINFLEXD_UART_BAUDRATE_14400  = 14400U,
    LINFLEXD_UART_BAUDRATE_19200  = 19200U,
    LINFLEXD_UART_BAUDRATE_28800  = 28800U,
    LINFLEXD_UART_BAUDRATE_38400  = 38400U,
    LINFLEXD_UART_BAUDRATE_57600  = 57600U,
    LINFLEXD_UART_BAUDRATE_115200 = 115200U,
    LINFLEXD_UART_BAUDRATE_230400 = 230400U,
    LINFLEXD_UART_BAUDRATE_460800 = 460800U,
    LINFLEXD_UART_BAUDRATE_921600 = 921600U,
    LINFLEXD_UART_BAUDRATE_1843200 = 1843200U
}
Linflexd_Uart_Ip_BaudrateType;
/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/**  @} */

#endif /* LINFLEXD_UART_IP_TYPES_H */
