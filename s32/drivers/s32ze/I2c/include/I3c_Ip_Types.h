/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef I3C_IP_TYPES_H
#define I3C_IP_TYPES_H

/**
*   @file
*
*   @addtogroup i3c_ip
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
#include "I3c_Ip_CfgDefines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I3C_IP_VENDOR_ID_TYPES                    43
#define I3C_IP_MODULE_ID_TYPES                    255
#define I3C_IP_AR_RELEASE_MAJOR_VERSION_TYPES     4
#define I3C_IP_AR_RELEASE_MINOR_VERSION_TYPES     7
#define I3C_IP_AR_RELEASE_REVISION_VERSION_TYPES  0
#define I3C_IP_SW_MAJOR_VERSION_TYPES             1
#define I3C_IP_SW_MINOR_VERSION_TYPES             0
#define I3C_IP_SW_PATCH_VERSION_TYPES             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and I3c_Ip_CfgDefines header file are of the same vendor */
#if (I3C_IP_VENDOR_ID_TYPES != I3C_IP_VENDOR_ID_CFGDEFINES)
    #error "I3c_Ip_Types.h and I3c_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if current file and I3c_Ip_CfgDefines header file are of the same Autosar version */
#if ((I3C_IP_AR_RELEASE_MAJOR_VERSION_TYPES     != I3C_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (I3C_IP_AR_RELEASE_MINOR_VERSION_TYPES     != I3C_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (I3C_IP_AR_RELEASE_REVISION_VERSION_TYPES  != I3C_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES))
    #error "AutoSar Version Numbers of I3c_Ip_Types.h and I3c_Ip_CfgDefines.h are different"
#endif

/* Check if current file and I3c_Ip_CfgDefines header file are of the same software version */
#if ((I3C_IP_SW_MAJOR_VERSION_TYPES != I3C_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (I3C_IP_SW_MINOR_VERSION_TYPES != I3C_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (I3C_IP_SW_PATCH_VERSION_TYPES != I3C_IP_SW_PATCH_VERSION_CFGDEFINES))
    #error "Software Version Numbers of I3c_Ip_Types.h and I3c_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief I3C master error flags.
*
* @details These can be used with I3c_Ip_MasterGetError() function to filter the active errors.
*          Use these masks to check which specific errors/warnings occurred.
*
*/
#define I3C_IP_MASTER_ERROR_NACK                ((uint32)I3C_MERRWARN_NACK_MASK)        /**< Slave(s) NACKed the last address */
#define I3C_IP_MASTER_ERROR_WRITE_ABORT         ((uint32)I3C_MERRWARN_WRABT_MASK)       /**< Slave NACKed the write data */
#define I3C_IP_MASTER_ERROR_OREAD               ((uint32)I3C_MERRWARN_OREAD_MASK)       /**< Read from MRDATAB register when FIFO empty */
#define I3C_IP_MASTER_ERROR_OWRITE              ((uint32)I3C_MERRWARN_OWRITE_MASK)      /**< Write to MWDATAB register when FIFO full */
#define I3C_IP_MASTER_ERROR_MSG                 ((uint32)I3C_MERRWARN_MSGERR_MASK)      /**< Read/write SDR/DDR mismatch */
#define I3C_IP_MASTER_ERROR_INVALID_REQUEST     ((uint32)I3C_MERRWARN_INVREQ_MASK)      /**< Invalid use of a request */
#define I3C_IP_MASTER_ERROR_TIMEOUT             ((uint32)I3C_MERRWARN_TIMEOUT_MASK)     /**< The module has stalled too long in a frame */

/**
* @brief I3C slave error flags.
*
* @details These can be used with I3c_Ip_SlaveGetError() function to filter the active errors.
*          Use these masks to check which specific errors/warnings occurred.
*
*/
#define I3C_IP_SLAVE_ERROR_RX_OVERRUN           ((uint32)I3C_SERRWARN_ORUN_MASK)        /**< Slave internal RX buffer/FIFO overrun */
#define I3C_IP_SLAVE_ERROR_TX_UNDERRUN          ((uint32)I3C_SERRWARN_URUN_MASK)        /**< Slave internal TX buffer/FIFO underrun */
#define I3C_IP_SLAVE_ERROR_TX_UNDERRUN_NACK     ((uint32)I3C_SERRWARN_URUNNACK_MASK)    /**< The internal Tx buffer/FIFO was underrun in the read header and so the module NACKed the header*/
#define I3C_IP_SLAVE_ERROR_TERM                 ((uint32)I3C_SERRWARN_TERM_MASK)        /**< Master terminated a read from slave */
#define I3C_IP_SLAVE_ERROR_INVALID_START        ((uint32)I3C_SERRWARN_INVSTART_MASK)    /**< Invalid start with SCL falling while SDA = 1 is in a STOP condition */
#define I3C_IP_SLAVE_ERROR_SDR_PARITY           ((uint32)I3C_SERRWARN_SPAR_MASK)        /**< SDR parity error on message from master */
#define I3C_IP_SLAVE_ERROR_OREAD                ((uint32)I3C_SERRWARN_OREAD_MASK)       /**< The SRDATAB register was read for more bytes than were available */
#define I3C_IP_SLAVE_ERROR_OWRITE               ((uint32)I3C_SERRWARN_OWRITE_MASK)      /**< The SWDATA register was written when FULL */

/**
* @brief I3C master status flags.
*
* @details These can be used with I3c_Ip_MasterGetStatus() function to filter the active status flags.
*          Use these masks to check which specific status is set.
*
*/
#define I3C_IP_MASTER_STATUS_ERROR_WARNING      ((uint32)I3C_MSTATUS_ERRWARN_MASK)      /**< An error or warning occurred */
#define I3C_IP_MASTER_STATUS_TXNOTFULL          ((uint32)I3C_MSTATUS_TXNOTFULL_MASK)    /**< Tx FIFO not yet full, according to its watermark */
#define I3C_IP_MASTER_STATUS_RXPENDING          ((uint32)I3C_MSTATUS_RXPEND_MASK)       /**< Rx FIFO has receiving data bytes, according to its watermark */
#define I3C_IP_MASTER_STATUS_COMPLETE           ((uint32)I3C_MSTATUS_COMPLETE_MASK)     /**< A message has completed. For more details, please check the Reference Manual */
#define I3C_IP_MASTER_STATUS_CTRLDONE           ((uint32)I3C_MSTATUS_MCTRLDONE_MASK)    /**< A Master Control request was completed. For more details, please check the Reference Manual */
#define I3C_IP_MASTER_STATUS_NACKED             ((uint32)I3C_MSTATUS_NACKED_MASK)       /**< The last address header was NACKed by the addressed slave */

/* All status flags */
#define I3C_IP_MASTER_STATUS_ALL                   (I3C_IP_MASTER_STATUS_ERROR_WARNING | \
                                                    I3C_IP_MASTER_STATUS_TXNOTFULL | \
                                                    I3C_IP_MASTER_STATUS_RXPENDING | \
                                                    I3C_IP_MASTER_STATUS_COMPLETE | \
                                                    I3C_IP_MASTER_STATUS_CTRLDONE | \
                                                    I3C_IP_MASTER_STATUS_NACKED)

/**
* @brief I3C slave status flags.
*
* @details These can be used with I3c_Ip_SlaveGetStatus() function to filter the active status flags.
*          Use these masks to check which specific status is set.
*
*/
#define I3C_IP_SLAVE_STATUS_ERROR_WARNING       ((uint32)I3C_SSTATUS_ERRWARN_MASK)      /**< An error or warning has occurred */
#define I3C_IP_SLAVE_STATUS_TXNOTFULL           ((uint32)I3C_SSTATUS_TXNOTFULL_MASK)    /**< Tx FIFO not yet full, according to its watermark */
#define I3C_IP_SLAVE_STATUS_RXPENDING           ((uint32)I3C_SSTATUS_RX_PEND_MASK)      /**< Rx FIFO has receiving data bytes, according to its watermark */
#define I3C_IP_SLAVE_STATUS_STOP                ((uint32)I3C_SSTATUS_STOP_MASK)         /**< STOP signal was detected on the bus */
#define I3C_IP_SLAVE_STATU_MATCHED              ((uint32)I3C_SSTATUS_MATCHED_MASK)      /**< An incoming header matched this device’s I3C Dynamic or I2C Static address (if any) */
#define I3C_IP_SLAVE_STATUS_START               ((uint32)I3C_SSTATUS_START_MASK)        /**< START or repeated START was seen after the START bit was last cleared */
#define I3C_IP_SLAVE_STATUS_STREQWR             ((uint32)I3C_SSTATUS_STREQWR_MASK)      /**< The request in process is SDR write data from the master to this slave. For more details, please check the Reference Manual */
#define I3C_IP_SLAVE_STATUS_STREQRD             ((uint32)I3C_SSTATUS_STREQRD_MASK)      /**< The request in process is SDR read from this slave, or an IBI is pushed out. For more details, please check the Reference Manual */
#define I3C_IP_SLAVE_STATUS_STMSG               ((uint32)I3C_SSTATUS_STMSG_MASK)        /**< This slave is listening to the bus traffic or responding. For more details, please check the Reference Manual */
#define I3C_IP_SLAVE_STATUS_STNOTSTOP           ((uint32)I3C_SSTATUS_STNOTSTOP_MASK)    /**< The I3c bus is busy (STOP has not been detected yet) */

/* All status flags */
#define I3C_IP_SLAVE_STATUS_ALL                    (I3C_IP_SLAVE_STATUS_ERROR_WARNING | \
                                                    I3C_IP_SLAVE_STATUS_TXNOTFULL | \
                                                    I3C_IP_SLAVE_STATUS_RXPENDING | \
                                                    I3C_IP_SLAVE_STATUS_STOP | \
                                                    I3C_IP_SLAVE_STATU_MATCHED | \
                                                    I3C_IP_SLAVE_STATUS_START | \
                                                    I3C_IP_SLAVE_STATUS_STREQWR | \
                                                    I3C_IP_SLAVE_STATUS_STREQRD | \
                                                    I3C_IP_SLAVE_STATUS_STMSG | \
                                                    I3C_IP_SLAVE_STATUS_STNOTSTOP)

/**
* @brief Indicates the current master operation mode.
*
*/
#define I3C_IP_MASTER_MODE_IDLE               (0x00U)    /**< Bus stopped */
#define I3C_IP_MASTER_MODE_NORMACT            (0x03U)    /**< Repeated START*/
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
* @brief Emits the requested operation when doing in pieces vs. by message.
*
*/
typedef enum
{
    I3C_IP_REQUEST_NONE             = 0x00U,   /**< No request */
    I3C_IP_REQUEST_EMIT_START_ADDR  = 0x01U,   /**< Emit START and ADDRESS on the bus */
    I3C_IP_REQUEST_EMIT_STOP        = 0x02U,   /**< Emit STOP on the bus */
} I3c_Ip_MasterRequestType;

/**
* @brief Events which can trigger I3C master callback.
*
*/
typedef enum
{
    I3C_IP_MASTER_EVENT_CONTROL_DONE        = 0x00U,
    I3C_IP_MASTER_EVENT_COMPLETE            = 0x01U,
    I3C_IP_MASTER_EVENT_END_TRANSFER        = 0x02U,
    I3C_IP_MASTER_EVENT_ERROR               = 0x03U,
} I3c_Ip_MasterEventType;

/**
* @brief Indicates if the master is enabled and what states are allowed for it (the master).
*
*/
typedef enum
{
    I3C_IP_MASTER_OFF          = 0x00U,    /**< Master is not enabled */
    I3C_IP_MASTER_ON           = 0x01U,    /**< Master is enabled */
    I3C_IP_MASTER_CAPABLE      = 0x02U     /**< Master capable, but operating as a slave */
} I3c_Ip_MasterEnableType;

/**
* @brief Indicates how High-Keeper is to be supported.
*
*/
typedef enum
{
    I3C_IP_MASTER_HIGH_KEEPER_NONE     = 0x00U,    /**< Use PUR to hold SCL high */
    I3C_IP_MASTER_PASSIVE_SDA_SCL      = 0x03U     /**< Passive on SDA and SCL: can Hi-Z both for Bus Free, and can Hi-Z SDA for hold */
} I3c_Ip_MasterHighKeepType;

/**
* @brief Bus type with EmitStartAddr.
*
* @implements I3c_Ip_BusType_enum
*/
typedef enum
{
    I3C_IP_BUS_TYPE_I3C_SDR    = 0x00U,    /**< I3C SDR mode */
    I3C_IP_BUS_TYPE_I2C        = 0x01U,    /**< I2C mode */
    I3C_IP_BUS_TYPE_I3C_DDR    = 0x02U     /**< I3C HDR-DDR mode */
} I3c_Ip_BusType;

/**
* @brief Direction: send/receive.
*
* @implements I3c_Ip_DirectionType_enum
*/
typedef enum
{
    I3C_IP_WRITE   = 0x00U, /**< @brief Used to send data to a slave */
    I3C_IP_READ    = 0x01U  /**< @brief Used to receive data from a slave */
} I3c_Ip_DirectionType;

/**
* @brief Watermark of Tx/RX INT/DMA trigger level.
*
*/
typedef enum
{
    I3C_IP_FIFO_TRIGGER_ON_EMPTY        = 0x00U,    /**< Trigger on empty */
    I3C_IP_FIFO_TRIGGER_ON_ONE_QUARTER  = 0x01U,    /**< Trigger on 1/4 full or less in Rx, and on 1/4 full or more in Tx */
    I3C_IP_FIFO_TRIGGER_ON_ONE_HALF     = 0x02U,    /**< Trigger on 1/2 full or less in Rx, and on 1/4 full or more in Tx */
    I3C_IP_FIFO_TRIGGER_ON_ALMOST_FULL  = 0x03U     /**< Trigger on 1 less than full or less in Rx, and on 3/4 full or more in Tx */
} I3c_Ip_FifoTriggerLevelType;

/**
* @brief I3C specific error codes.
*
* @implements I3c_Ip_StatusType_enum
*/
typedef enum
{
    I3C_IP_STATUS_SUCCESS           = 0x00U,
    I3C_IP_STATUS_ERROR             = 0x01U,    /**< An error occurred on the I3C Bus */
    I3C_IP_STATUS_BUSY              = 0x02U,    /**< The I3C Bus is busy */
    I3C_IP_STATUS_TIMEOUT           = 0x03U,    /**< The module has stalled too long in a frame */
    I3C_IP_STATUS_CONTROL_DONE      = 0x04U
} I3c_Ip_StatusType;

/**
* @brief Indicates size of the transfer message.
*
* @implements I3c_Ip_TransferSizeType_enum
*/
typedef enum
{
    I3C_IP_TRANSFER_BYTES      = 0x00U,    /**< Send/read in bytes */
    I3C_IP_TRANSFER_HALF_WORDS = 0x01U     /**< Send/read in half-words */
} I3c_Ip_TransferSizeType;

/**
* @brief Type of I3C transfer (based on interrupts or DMA)
*
*/
typedef enum
{
#if (STD_ON == I3C_IP_DMA_FEATURE_AVAILABLE)
    I3C_IP_USING_DMA            = 0x00U,    /**< The driver will use DMA to perform a transfer */
#endif /* I3C_IP_DMA_FEATURE_AVAILABLE */
    I3C_IP_USING_INTERRUPTS     = 0x01U     /**< The driver will use interrupts to perform a transfer */
} I3c_Ip_TransferType;

/**
* @brief Events which can trigger I3C slave callback.
*
*/
typedef enum
{
    I3C_IP_SLAVE_EVENT_START          = 0x00U,
    I3C_IP_SLAVE_EVENT_STOP           = 0x01U,
    I3C_IP_SLAVE_EVENT_ERROR          = 0x02U,
    I3C_IP_SLAVE_EVENT_TX_REQUEST     = 0x03U,
    I3C_IP_SLAVE_EVENT_RX_REQUEST     = 0x04U,
    I3C_IP_SLAVE_EVENT_END_TRANSFER   = 0x05U,
    I3C_IP_SLAVE_EVENT_RX_FULL        = 0x06U,
    I3C_IP_SLAVE_EVENT_TX_EMPTY       = 0x07U,
    I3C_IP_SLAVE_EVENT_HEADER_MATCHED = 0x08U
} I3c_Ip_SlaveEventType;

/**
* @brief Definition of the I3C Hw Unit mode.
*
*/
typedef enum
{
    I3C_IP_MASTER_MODE         = 0x0U, /**< The module is an I3C Master */
    I3C_IP_SLAVE_MODE          = 0x1U, /**< The module is an I3C Slave */
    I3C_IP_MASTER_CAPABLE_MODE = 0x2U  /**< The I3C module is master-capable; however the module is operating as a slave now.
                                            When used from the start, the I3C module will start as a slave, but will be prepared to switch to master mode using specific procedures. */
} I3c_Ip_MasterSlaveModeType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Callback for all peripherals which supports I3C features for master mode.
*
*/
typedef void (*I3c_Ip_MasterCallbackType)(I3c_Ip_MasterEventType Event, uint8 Channel);

/**
* @brief Callback for all peripherals which supports I3C features for slave mode.
*
*/
typedef void (*I3c_Ip_SlaveCallbackType)(I3c_Ip_SlaveEventType Event, uint8 Channel);

/**
* @brief Contains the transfer options.
*        This structure must be configured at runtime, before calling Send/Receive API.
*
* @implements I3c_Ip_TransferConfigType_struct
*/
typedef struct
{
    uint8 SlaveAddress;                     /**< Slave Device Address */
    boolean SendStop;                       /**< Specifies if either a STOP or repeated START signal shall be emitted */
    I3c_Ip_DirectionType Direction;         /**< Specifies the direction of the transfer, send or receive */
    I3c_Ip_TransferSizeType TransferSize;   /**< Specifies if the transfer is in half words or in bytes */
    I3c_Ip_BusType BusType;                 /**< Bus Type: SDR, DDR, I2C */
} I3c_Ip_TransferConfigType;

/**
* @brief Contains the baud rates options.
*        This structure should be set by the user at runtime.
*
* @implements I3c_Ip_MasterBaudRateType_struct
*/
typedef struct
{
    uint32 I2cBaudRate;                     /**< Desired I2C baud rate in Hz */
    uint32 OpenDrainBaudRate;               /**< Desired Open-Drain baud rate in Hz */
    uint32 PushPullBaudRate;                /**< Desired push-pull baud rate in Hz */
} I3c_Ip_MasterBaudRateType;

/**
* @brief Master internal context structure
*
* This structure is used by the master-mode driver for its internal logic.
*
*/
typedef struct
{
    uint32 BufferSize;                                                  /**< Tx/Rx buffer size */
    const uint8 * TxDataBuffer;                                         /**< Pointer to Tx data buffer */
    uint8 * RxDataBuffer;                                               /**< Pointer to Rx data buffer */
    volatile I3c_Ip_StatusType Status;                                  /**< Status of the last driver operation */
    I3c_Ip_TransferConfigType TransferOption;                           /**< Transfer options */
    I3c_Ip_TransferType TransferType;                                   /**< Type of the transfer: DMA/interrupts */
    boolean OpenDrainStop;                                              /**< If true, then STOP will be emitted at open-drain speeds even for I3C messages */
#if (STD_ON == I3C_IP_DMA_FEATURE_AVAILABLE)
    uint32 DmaTxChannel;                                                /**< DMA Tx channel ID */
    uint32 DmaRxChannel;                                                /**< DMA Rx channel ID */
#endif /* I3C_IP_DMA_FEATURE_AVAILABLE */
    I3c_Ip_MasterCallbackType MasterCallback;                           /**< Master callback function */
    uint8 MasterCallbackParam;
} I3c_Ip_MasterStateType;

/**
* @brief Master configuration structure
*
* This structure is used to provide configuration parameters for the I3C master.
*
*/
typedef struct
{
    I3c_Ip_MasterEnableType MasterEnable;       /**< Enable master mode */
    boolean DisableTimeout;                     /**< Disable timeout to prevent application errors (MERRWARN) */
    I3c_Ip_MasterHighKeepType MasterHighKeeper; /**< High keeper mode setting */
    uint8 I2cBaud;                              /**< I2C baud in cycles */
    uint8 OpenDrainBaud;                        /**< I3C open-drain baud rate in cycles */
    uint8 PushPullBaud;                         /**< I3C push-pull baud rate in cycles */
    uint8 PushPullLow;                          /**< Adder for push-pull low, to create a duty-cycle with a longer low period */
    boolean OpenDrainHighPP;                    /**< Optional field that allows for the I3C open drain to be long low and short high */
    uint8 Skew;                                 /**< Number of FCLK counts for an SDA change after SCL for I3C push-pull */
    I3c_Ip_MasterStateType * MasterState;       /**< Pointer to the master state structure */
} I3c_Ip_MasterConfigType;

/**
* @brief Slave internal context structure
*
* This structure is used by the slave-mode driver for its internal logic.
*
*/
typedef struct
{
    uint32 BufferSize;                          /**< Tx/Rx buffer size */
    uint8 * DataBuffer;                         /**< Pointer to data buffer */
    volatile I3c_Ip_StatusType Status;          /**< Slave status */
    volatile uint8 RepeatedStarts;                       /**< Number of Repeated STARTs on the I3c bus, before a STOP was detected.
                                                     When STOP signal is detected, this counter is reseted. */
    I3c_Ip_DirectionType Direction;             /**< Specifies the direction of the transfer, send or receive */
    I3c_Ip_TransferSizeType TransferSize;       /**< Transfer size: bytes or half words */
    I3c_Ip_TransferType TransferType;           /**< Type of the transfer: DMA/interrupts */
#if (STD_ON == I3C_IP_DMA_FEATURE_AVAILABLE)
    uint32 DmaTxChannel;                        /**< DMA Tx channel ID */
    uint32 DmaRxChannel;                        /**< DMA Rx channel ID */
#endif /* I3C_IP_DMA_FEATURE_AVAILABLE */
    I3c_Ip_SlaveCallbackType SlaveCallback;     /**< Slave callback function */
    uint8 SlaveCallbackParam;
} I3c_Ip_SlaveStateType;

/**
* @brief Slave configuration structure
*
* This structure is used to provide configuration parameters for the I3C slave.
*
*/
typedef struct
{
    boolean SlaveEnable;                        /**< If true, then a slave can operate on the I2C or I3C bus. Otherwise, ignore I2C or I3C bus */
    boolean Nack;                               /**< If true, then the slave will NACK all requests to it, except a CCC broadcast */
    boolean MatchStartStop;                     /**< Whether to assert START/STOP status only if the slave is addressed */
    uint8 StaticAddress;                        /**< Slave's Static Address */
    I3c_Ip_SlaveStateType * SlaveState;         /**< Pointer to the slave state structure */
} I3c_Ip_SlaveConfigType;

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

#endif /* I3C_IP_TYPES_H */
