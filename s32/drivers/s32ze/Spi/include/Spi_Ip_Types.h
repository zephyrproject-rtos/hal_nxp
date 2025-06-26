/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SPI_IP_TYPES_H
#define SPI_IP_TYPES_H

/**
*   @file    Spi_Ip_Types.h
*
*   @brief   SPI IP driver types header file.
*   @details SPI IP driver types header file.

*   @addtogroup SPI_IP_DRIVER Spi Ip Driver
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
#include "Std_Types.h"
#include "Spi_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IP_TYPES_VENDOR_ID                    43
#define SPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define SPI_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define SPI_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define SPI_IP_TYPES_SW_MAJOR_VERSION             2
#define SPI_IP_TYPES_SW_MINOR_VERSION             0
#define SPI_IP_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((SPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif

/* Check if Spi_Ip_Types.h header file and Spi_Ip_Cfg.h configuration header file are of the same vendor */
#if (SPI_IP_TYPES_VENDOR_ID != SPI_IP_VENDOR_ID_CFG)
    #error "Spi_Ip_Types.h and Spi_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Spi_Ip_Types.h header file and Spi_Ip_Cfg.h  configuration header file are of the same Autosar version */
#if ((SPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION != SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SPI_IP_TYPES_AR_RELEASE_MINOR_VERSION != SPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SPI_IP_TYPES_AR_RELEASE_REVISION_VERSION != SPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Spi_Ip_Types.h and Spi_Ip_Cfg.h are different"
#endif
/* Check if Spi_Ip_Types.h header file and Spi_Ip_Cfg.h configuration header file are of the same software version */
#if ((SPI_IP_TYPES_SW_MAJOR_VERSION != SPI_IP_SW_MAJOR_VERSION_CFG) || \
     (SPI_IP_TYPES_SW_MINOR_VERSION != SPI_IP_SW_MINOR_VERSION_CFG) || \
     (SPI_IP_TYPES_SW_PATCH_VERSION != SPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Spi_Ip_Types.h and Spi_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** @brief   Enum defining the possible events which triggers end of transfer callback.
*
* @implements Spi_Ip_EventType_enum
*/
typedef enum
{
    SPI_IP_EVENT_END_TRANSFER = 0, /**< The transfer is successfully done. */
    SPI_IP_EVENT_FAULT = 1         /**< The transfer failed due to overflow/underflow. */
} Spi_Ip_EventType;

/** @brief   Callback for all peripherals which supports SPI features. */
typedef void (*Spi_Ip_CallbackType)(uint8 Instance, Spi_Ip_EventType Event);

/** @brief   Enum defining the possible transfer modes.
*
* @implements Spi_Ip_ModeType_enum
*/
typedef enum
{
    SPI_IP_POLLING = 0, /**< For polling mode the application must call periodically Spi_Ip_ManageBuffers after asynchronous transfers. */
    SPI_IP_INTERRUPT   /**< For interrupt mode the application doesn't need to perform any additional operations after asynchronous transfers.
                            The application must enable the interrupt requests and install the right callbacks. */
} Spi_Ip_ModeType;

/** @brief   Enum defining the possible states of hardware unit.
 * @implements Spi_Ip_HwStatusType_enum
*/
typedef enum
{
    SPI_IP_UNINIT = 0u, /**< Module is not initialized. */
    SPI_IP_IDLE = 1u, /**< Module is not used. */
    SPI_IP_BUSY = 2u,   /**< A transfer is in progress. */
    SPI_IP_FAULT = 3u   /**< During last transfer a fault occurred. */
} Spi_Ip_HwStatusType;

/** @brief   Enum defining the possible return types.
*
* @implements Spi_Ip_StatusType_enum
*/
typedef enum
{
    SPI_IP_STATUS_SUCCESS = 0u, /**< Successful operation. */
    SPI_IP_STATUS_FAIL    = 1u, /**< Failed operation. */
    SPI_IP_FIFO_ERROR     = 2u, /**< Overflow or underflow error. */
    SPI_IP_TIMEOUT        = 3u  /**< Timeout error. */
} Spi_Ip_StatusType;

/** @brief   Structure defining some parameters often change of the spi bus. */
typedef struct
{
    uint8 FrameSize;    /**< Frame size configured */
    boolean Lsb;    /**< Transfer LSB first or MSB first */
    uint32 DefaultData;  /**< Default data to send when TxBuffer is NULL_PTR */
} Spi_Ip_DeviceParamsType;

/** @brief   Structure defining the parameters of the spi bus. */
typedef struct
{
    uint8 Instance; /**< Instance of the hardware unit. */
    #if (SPI_IP_DUAL_CLOCK_MODE == STD_ON)
    uint32 Ctar[2u];         /**< CTAR register which contains clocking and frame size configuration. */
    #else
    uint32 Ctar;         /**< CTAR register which contains clocking and frame size configuration. */
    #endif
    uint32 Ctare;        /**< CTARE registers which contains frame size configuration. */
    uint16 PushrCmd;     /**< PUSHR CMD Fifo register which contains CS and continuos mode. */
    Spi_Ip_DeviceParamsType * DeviceParams; /**< Contain configuration for bit order, frame size, default transmit data. */
} Spi_Ip_ExternalDeviceType;

#if (SPI_IP_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   Specifies the Clock Modes.
*/
typedef enum
{
    SPI_IP_NORMAL_CLOCK = 0,        /**< @brief Clock reference is from SpiClockRef. */
    SPI_IP_ALTERNATE_CLOCK          /**< @brief Clock reference is from SpiAlternateClockRef. */
}Spi_Ip_DualClockModeType;
#endif

#if ((SPI_IP_DMA_USED == STD_ON) && (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
/** @brief   Structure defining transmition command needed for Dma Fast transfer. */
typedef struct
{
    uint16 DmaFastPushrCmd;   /**< PUSHR CMD Fifo register which contains CS and continuos mode. */
    uint16 DmaFastPushrCmdLast;   /**< PUSHR CMD Fifo register which contains CS and disable continuos mode. */
    uint32 DefaultData;  /**< Default data to send when TxBuffer is NULL_PTR */
} Spi_Ip_CmdDmaFastType;

/** @brief   Structure defining information needed for Dma Fast transfer session.
* @implements Spi_Ip_FastTransferType_struct
*/
typedef struct
{
    const Spi_Ip_ExternalDeviceType *ExternalDevice; /**< Point to external device configuration */
    const uint8* TxBuffer;  /**< Store pointer for Tx buffer */
    uint8* RxBuffer;  /**< Store pointer for Rx buffer */
    uint32 DefaultData;  /**< Default data to send when TxBuffer is NULL_PTR */
    uint16 Length;  /**< Number of bytes to be sent */
    boolean KeepCs;  /**< Keep CS signal after transfer session completed */
} Spi_Ip_FastTransferType;
#endif

/** @brief   Structure defining information needed for SPI driver initialization. */
typedef struct
{
    uint8 Instance; /**< Instance of the hardware unit. */
    uint32  Mcr; /**< Select master/slave. */
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    boolean SlaveMode;
    #endif
    #if (SPI_IP_DMA_USED == STD_ON)
    boolean DmaUsed;    /**< DMA is used or not */
    uint8   TxDmaChannel;    /**< Id of TX DMA channel for transmition */
    uint8   TxCmdDmaChannel;    /**< Id of CMD DMA channel for transmition */
    uint8 NumTxCmdDmaSGId;  /**< Number of TCD Scatter Gather for CMD DMA channel */
    const uint8 *TxCmdDmaSGId;    /**< Point to list of TCD Scatter Gather Id for CMD DMA channel */
    uint8   RxDmaChannel;    /**< Id of RX DMA channel for receive */
    #if (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    uint8 MaxNumOfFastTransfer; /**< Maximum number of transfers in Dma Fast */
    Spi_Ip_CmdDmaFastType *CmdDmaFast; /**< Point to list of PUSH command used in Dma Fast transfer */
    uint8 NumberRxSG; /**< Number of TCD Scatter Gather for Rx DMA channel used in Dma Fast transfer */
    const uint8 *TxDmaFastSGId; /**< Point to list of TCD Scatter Gather Id for Tx DMA channel used in Dma Fast transfer */
    const uint8 *RxDmaFastSGId; /**< Point to list of TCD Scatter Gather Id for Rx DMA channel used in Dma Fast transfer */
    #endif
    #endif
    Spi_Ip_ModeType TransferMode; /**< Transfer mode for HWunit */
    uint8 StateIndex; /**< State of current transfer  */
} Spi_Ip_ConfigType;

/** @brief   Structure defining information needed for internal state of the driver. */
typedef struct
{
    #if (SPI_IP_DUAL_CLOCK_MODE == STD_ON)
    Spi_Ip_DualClockModeType ClockMode; /**< Store current clock mode for HWunit */
    #endif
    Spi_Ip_ModeType TransferMode; /**< Store current transfer mode for HWunit */
    Spi_Ip_HwStatusType Status; /**< 0 = available, 1 = busy, 2 = fail due to overflow or underflow */
    uint8* RxBuffer;  /**< Store pointer for Rx buffer */
    const uint8* TxBuffer;  /**< Store pointer for Tx buffer */
    Spi_Ip_CallbackType Callback;  /**< Store pointer for call back function */
    uint16 RxIndex;  /**< Store current Rx index to receive data in Rx buffer */
    uint16 TxIndex;  /**< Store current Tx index to transmit data in Tx buffer */
    uint16 ExpectedFifoReads;    /**< Store number of frames needs to be receive for current transfer */
    uint16 ExpectedFifoWrites;   /**< Store number of frames needs to be transmit for current transfer */
    uint16 ExpectedCmdFifoWrites;   /**< Store number of frames needs to be transmit for current transfer */
    uint16 PushrCmd;   /**< PUSHR CMD Fifo register which contains CS and continuos mode. */
    boolean KeepCs;   /**< Keep CS signal after tranfers completed. */
    uint16 CurrentTxFifoSlot;   /**< Number of TX FIFO slots are current available. */
    uint16 Pushr0Repeat; /**< Number of times to write PushrCmds[0] to FIFO >*/
    uint16 Pushr0RepeatIndex; /**< Counter for Pushr0Repeat >*/
    uint16 PushrCmds[3]; /**< Pushr Cmds to be written to FIFO >*/
    uint16 DTCPValue[3]; /**< Values of DTCP to be written in CTARE0-3 >*/
    uint16 NbCmds; /**< Number of different Cmds >*/
    uint16 NbCmdsIndex; /**< Counter for NbCmds >*/
    const Spi_Ip_ConfigType *PhyUnitConfig;
    const Spi_Ip_ExternalDeviceType *ExternalDevice;
} Spi_Ip_StateStructureType;

typedef struct
{
    boolean KeepCs; /**< Keep CS asserted after the next transfer */
    Spi_Ip_DeviceParamsType *DeviceParams; /**< Device params to be updated. If null, device params are not updated */
} Spi_Ip_TransferAdjustmentType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*SPI_IP_TYPES*/
