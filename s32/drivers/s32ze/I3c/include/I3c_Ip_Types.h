/*
 * Copyright 2021-2022 NXP
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
#define I3C_IP_SW_MAJOR_VERSION_TYPES             0
#define I3C_IP_SW_MINOR_VERSION_TYPES             9
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
* @brief I3c broadcast address.
*
* @details All I3c slave devices shall match this address. In addition, no I2c slave device shall match this address
*          because it is reserved and unused in I2c.
*
*/
#define I3C_IP_BROADCAST_ADDRESS                ((uint8)0x7E)

/**
* @brief I3C master error flags.
*
* @details These can be used with I3c_Ip_MasterGetError() function to filter the active errors.
*          Use these masks to check which specific errors/warnings occurred.
*
*/
#define I3C_IP_MASTER_ERROR_NACK                ((uint32)I3C_MERRWARN_NACK_MASK)        /**< Slave(s) NACKed the last address */
#define I3C_IP_MASTER_ERROR_WRITE_ABORT         ((uint32)I3C_MERRWARN_WRABT_MASK)       /**< Slave NACKed the write data */
#define I3C_IP_MASTER_ERROR_TERM                ((uint32)I3C_MERRWARN_TERM_MASK)        /**< Master terminated a slave read */
#define I3C_IP_MASTER_ERROR_PARITY              ((uint32)I3C_MERRWARN_HPAR_MASK)        /**< Parity error from a DDR read */
#define I3C_IP_MASTER_ERROR_CRC                 ((uint32)I3C_MERRWARN_HCRC_MASK)        /**< CRC error from a DDR read */
#define I3C_IP_MASTER_ERROR_OREAD               ((uint32)I3C_MERRWARN_OREAD_MASK)       /**< Read from MRDATAB register when FIFO empty */
#define I3C_IP_MASTER_ERROR_OWRITE              ((uint32)I3C_MERRWARN_OWRITE_MASK)      /**< Write to MWDATAB register when FIFO full */
#define I3C_IP_MASTER_ERROR_MSG                 ((uint32)I3C_MERRWARN_MSGERR_MASK)      /**< Read/write SDR/DDR mismatch */
#define I3C_IP_MASTER_ERROR_INVALID_REQUEST     ((uint32)I3C_MERRWARN_INVREQ_MASK)      /**< Invalid use of a request */
#define I3C_IP_MASTER_ERROR_TIMEOUT             ((uint32)I3C_MERRWARN_TIMEOUT_MASK)     /**< The module has stalled too long in a frame */
#if (STD_ON == I3C_IP_HDR_BT_SUPPORT)
#define I3C_IP_MASTER_ERROR_WRONG_SIZE          ((uint32)I3C_MERRWARN_WRONGSIZE_MASK)   /**< Set if read or write using MWDATAW or MRDATAW and not HDR-BT mode; likewise set if read or write using other than MWDATAW or MRDATAW with HDR-BT */
#define I3C_IP_MASTER_ERROR_BT_TX_UNDERRUN      ((uint32)I3C_MERRWARN_URUN_MASK)        /**< Underrun for HDR-BT on write when Tx FIFO goes empty */
#define I3C_IP_MASTER_ERROR_BT_NO_VERIFY        ((uint32)I3C_MERRWARN_HNOVERIFY_MASK)   /**< A read from Slave in HDR-BT was not verified by the Master, or a write by Master was not verified by the Slave */
#endif /* (STD_ON == I3C_IP_HDR_BT_SUPPORT) */

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
#define I3C_IP_SLAVE_ERROR_HDR_PARITY_ERROR     ((uint32)I3C_SERRWARN_HPAR_MASK)        /**< HDR parity error on message from master */
#define I3C_IP_SLAVE_ERROR_HDR_CRC              ((uint32)I3C_SERRWARN_HCRC_MASK)        /**< HDR-DDR CRC error on a message from master */
#define I3C_IP_SLAVE_ERROR_S0S1                 ((uint32)I3C_SERRWARN_S0S1_MASK)        /**< S0 or S1 error */
#define I3C_IP_SLAVE_ERROR_OREAD                ((uint32)I3C_SERRWARN_OREAD_MASK)       /**< The SRDATAB register was read for more bytes than were available */
#define I3C_IP_SLAVE_ERROR_OWRITE               ((uint32)I3C_SERRWARN_OWRITE_MASK)      /**< The SWDATA register was written when FULL */
#if (STD_ON == I3C_IP_HDR_BT_SUPPORT)
#define I3C_IP_SLAVE_ERROR_WRONG_SIZE           ((uint32)I3C_SERRWARN_WRONGSIZE_MASK)   /**< Set if read or write using WDATAW or RDATAW and not HDR-BT mode; likewise set if read or write using other than WDATAW or RDATAW with HDR-BT. Only possible if Wide word FIFO enabled */
#define I3C_IP_SLAVE_ERROR_BT_INV_REQ           ((uint32)I3C_SERRWARN_HINVREQ_MASK)     /**< Invalid request in HDR-BT */
#define I3C_IP_SLAVE_ERROR_BT_NO_VERIFY         ((uint32)I3C_SERRWARN_HNOVERIFY_MASK)   /**< An HDR-BT Read did not get verified by the Master */
#endif /* (STD_ON == I3C_IP_HDR_BT_SUPPORT) */

/**
* @brief I3C master status flags.
*
* @details These can be used with I3c_Ip_MasterGetStatus() function to filter the active status flags.
*          Use these masks to check which specific status is set.
*
*/
#define I3C_IP_MASTER_STATUS_IBIADDR            ((uint32)I3C_MSTATUS_IBIADDR_MASK)      /**< The address of the Slave Request (IBI, MR, HJ) */
#define I3C_IP_MASTER_STATUS_NOWMASTER          ((uint32)I3C_MSTATUS_NOWMASTER_MASK)    /**< Now this module is a master, but was previously a slave and mastership was handed */
#define I3C_IP_MASTER_STATUS_ERROR_WARNING      ((uint32)I3C_MSTATUS_ERRWARN_MASK)      /**< An error or warning occurred */
#define I3C_IP_MASTER_STATUS_IBIWON             ((uint32)I3C_MSTATUS_IBIWON_MASK)       /**< A slave request won the arbitration on a header address, regardless of whether it was ACKed/NACKed */
#define I3C_IP_MASTER_STATUS_TXNOTFULL          ((uint32)I3C_MSTATUS_TXNOTFULL_MASK)    /**< Tx FIFO not yet full, according to its watermark */
#define I3C_IP_MASTER_STATUS_RXPENDING          ((uint32)I3C_MSTATUS_RXPEND_MASK)       /**< Rx FIFO has receiving data bytes, according to its watermark */
#define I3C_IP_MASTER_STATUS_COMPLETE           ((uint32)I3C_MSTATUS_COMPLETE_MASK)     /**< A message has completed. For more details, please check the Reference Manual */
#define I3C_IP_MASTER_STATUS_CTRLDONE           ((uint32)I3C_MSTATUS_MCTRLDONE_MASK)    /**< A Master Control request was completed. For more details, please check the Reference Manual */
#define I3C_IP_MASTER_STATUS_SLVSTART           ((uint32)I3C_MSTATUS_SLVSTART_MASK)     /**< A slave is/was requesting a START by pulling the SDA low */
#define I3C_IP_MASTER_STATUS_IBITYPE            ((uint32)I3C_MSTATUS_IBITYPE_MASK)      /**< Slave request type (IBI, MR, HJ) */
#define I3C_IP_MASTER_STATUS_NACKED             ((uint32)I3C_MSTATUS_NACKED_MASK)       /**< The last address header was NACKed by the addressed slave */
#define I3C_IP_MASTER_STATUS_BETWEEN            ((uint32)I3C_MSTATUS_BETWEEN_MASK)      /**< Between messages or Dynamic Address Assignment. For more details, please check the Reference Manual */
#define I3C_IP_MASTER_STATUS_STATE              ((uint32)I3C_MSTATUS_STATE_MASK)        /**< Indicates the current master state */

/* These values can be used together with the above defines to get the actual value of the bit fields
   which have more than 1 bit length. */
#define I3C_IP_MASTER_STATUS_IBIADDR_SHIFT      (24U)
#define I3C_IP_MASTER_STATUS_IBITYPE_SHIFT      (6U)
#define I3C_IP_MASTER_STATUS_STATE_SHIFT        (0U)

/**
* @brief I3C slave status flags.
*
* @details These can be used with I3c_Ip_SlaveGetStatus() function to filter the active status flags.
*          Use these masks to check which specific status is set.
*
*/
#define I3C_IP_SLAVE_STATUS_TIMECTRL            ((uint32)I3C_SSTATUS_TIMECTRL_MASK)     /**< Indicates if time control is currently enabled */
#define I3C_IP_SLAVE_STATUS_ACTSTATE            ((uint32)I3C_SSTATUS_ACTSTATE_MASK)     /**< Activity state from Common Command Codes (CCC) */
#define I3C_IP_SLAVE_STATUS_HJDIS               ((uint32)I3C_SSTATUS_HJDIS_MASK)        /**< Hot-Join is disabled at this time. While Hot-Join is disabled, MCTRL requests will be held off */
#define I3C_IP_SLAVE_STATUS_MRDIS               ((uint32)I3C_SSTATUS_MRDIS_MASK)        /**< Master Requests are disabled at this time. While Master Requests are disabled, MCTRL requests will be held off */
#define I3C_IP_SLAVE_STATUS_IBIDIS              ((uint32)I3C_SSTATUS_IBIDIS_MASK)       /**< In-Band interrupts are disabled at this time. While Master Requests are disabled, MCTRL requests will be held off */
#define I3C_IP_SLAVE_STATUS_EVDET               ((uint32)I3C_SSTATUS_EVDET_MASK)        /**< Slave request details: if it was NACKed, ACKed, or sill waiting for START, Bus Available, or Bus-Idle (HJ) conditions */
#define I3C_IP_SLAVE_STATUS_EVENT               ((uint32)I3C_SSTATUS_EVENT_MASK)        /**< Slave request was sent and ACKed. For more details, please check the Reference Manual */
#define I3C_IP_SLAVE_STATUS_CHANDLED            ((uint32)I3C_SSTATUS_CHANDLED_MASK)     /**< A Common Command Code (CCC) is being handled by the module */
#define I3C_IP_SLAVE_STATUS_HDRMATCHED          ((uint32)I3C_SSTATUS_HDRMATCH_MASK)     /**< An HDR command matched this device’s I3C Dynamic Address */
#define I3C_IP_SLAVE_STATUS_ERROR_WARNING       ((uint32)I3C_SSTATUS_ERRWARN_MASK)      /**< An error or warning has occurred */
#define I3C_IP_SLAVE_STATUS_CCC                 ((uint32)I3C_SSTATUS_CCC_MASK)          /**< A Common Command Code (CCC) has been received, and is not handled by the I3C module */
#define I3C_IP_SLAVE_STATUS_DACHG               ((uint32)I3C_SSTATUS_DACHG_MASK)        /**< The Slave Dynamic Address (DA) has been assigned, re-assigned, or reset (lost) */
#define I3C_IP_SLAVE_STATUS_TXNOTFULL           ((uint32)I3C_SSTATUS_TXNOTFULL_MASK)    /**< Tx FIFO not yet full, according to its watermark */
#define I3C_IP_SLAVE_STATUS_RXPENDING           ((uint32)I3C_SSTATUS_RX_PEND_MASK)      /**< Rx FIFO has receiving data bytes, according to its watermark */
#define I3C_IP_SLAVE_STATUS_STOP                ((uint32)I3C_SSTATUS_STOP_MASK)         /**< STOP signal was detected on the bus */
#define I3C_IP_SLAVE_STATU_MATCHED              ((uint32)I3C_SSTATUS_MATCHED_MASK)      /**< An incoming header matched this device’s I3C Dynamic or I2C Static address (if any) */
#define I3C_IP_SLAVE_STATUS_START               ((uint32)I3C_SSTATUS_START_MASK)        /**< START or repeated START was seen after the START bit was last cleared */
#define I3C_IP_SLAVE_STATUS_STHDR               ((uint32)I3C_SSTATUS_STHDR_MASK)        /**< The I3C bus is in HDR-DDR mode. For more details, please check the Reference Manual */
#define I3C_IP_SLAVE_STATUS_STDAA               ((uint32)I3C_SSTATUS_STDAA_MASK)        /**< The I3C bus is in Enter Dynamic Address Assignment (ENTDAA) mode. For more details, please check the Reference Manual */
#define I3C_IP_SLAVE_STATUS_STREQWR             ((uint32)I3C_SSTATUS_STREQWR_MASK)      /**< The request in process is SDR write data from the master to this slave. For more details, please check the Reference Manual */
#define I3C_IP_SLAVE_STATUS_STREQRD             ((uint32)I3C_SSTATUS_STREQRD_MASK)      /**< The request in process is SDR read from this slave, or an IBI is pushed out. For more details, please check the Reference Manual */
#define I3C_IP_SLAVE_STATUS_STCCCH              ((uint32)I3C_SSTATUS_STCCCH_MASK)       /**< A Common Command Code (CCC) message is being handled automatically */
#define I3C_IP_SLAVE_STATUS_STMSG               ((uint32)I3C_SSTATUS_STMSG_MASK)        /**< This slave is listening to the bus traffic or responding. For more details, please check the Reference Manual */
#define I3C_IP_SLAVE_STATUS_STNOTSTOP           ((uint32)I3C_SSTATUS_STNOTSTOP_MASK)    /**< The I3c bus is busy (STOP has not been detected yet) */

/* These values can be used together with the above defines to get the actual value of the bit fields
   which have more than 1 bit length. */
#define I3C_IP_SLAVE_STATUS_TIMECTRL_SHIFT      (30U)
#define I3C_IP_SLAVE_STATUS_ACTSTATE_SHIFT      (28U)
#define I3C_IP_SLAVE_STATUS_EVDET_SHIFT         (20U)

/**
* @brief Indicates the current master operation mode.
*
*/
#define I3C_IP_MASTER_MODE_IDLE               (0x00U)    /**< Bus stopped */
#define I3C_IP_MASTER_MODE_SLAVE_REQUEST      (0x01U)    /**< Bus stopped but a slave is holding SDA low */
#define I3C_IP_MASTER_MODE_MSG_SDR            (0x02U)    /**< In SDR Message mode */
#define I3C_IP_MASTER_MODE_NORMAL_ACTIVE_SDR  (0x03U)    /**< In Normal Active SDR mode */
#define I3C_IP_MASTER_MODE_MSG_DDR            (0x04U)    /**< In DDR Message mode */
#if (STD_ON == I3C_IP_ENABLE_I3C_FEATURES)
#define I3C_IP_MASTER_MODE_DAA                (0x05U)    /**< In ENTDAA mode */
#endif /* (STD_ON == I3C_IP_ENABLE_I3C_FEATURES) */
#define I3C_IP_MASTER_MODE_IBI_ACK_NACK       (0x06U)    /**< Waiting on IBI ACK/NACK decision */
#define I3C_IP_MASTER_MODE_IBI_RECEIVE        (0x07U)     /**< Receiving an IBI */

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
    I3C_IP_REQUEST_IBI_ACK_NACK     = 0x03U,   /**< Manual IBI ACK or NACK */
    I3C_IP_REQUEST_PROCESS_DAA      = 0x04U,   /**< Process DAA */
    I3C_IP_REQUEST_FORCE_EXIT       = 0x06U,   /**< Emit Force Exit */
    I3C_IP_REQUEST_AUTO_IBI         = 0x07U    /**< Hold in a stopped state, but auto-emit START, I3C_IP_BROADCAST_ADDRESS to get an IBI*/
} I3c_Ip_MasterRequestType;

/**
* @brief Events which can trigger I3C master callback.
*
*/
typedef enum
{
    I3C_IP_MASTER_EVENT_SLAVE_START         = 0x00U,
    I3C_IP_MASTER_EVENT_CONTROL_DONE        = 0x01U,
    I3C_IP_MASTER_EVENT_COMPLETE            = 0x02U,
    I3C_IP_MASTER_EVENT_ARBITRATION_LOST    = 0x03U,
    I3C_IP_MASTER_EVENT_ERROR               = 0x04U,
    I3C_IP_MASTER_EVENT_NOW_MASTER          = 0x05U,
    I3C_IP_MASTER_EVENT_END_TRANSFER        = 0x06U,
    I3C_IP_MASTER_EVENT_HOT_JOIN            = 0x07U,
    I3C_IP_MASTER_EVENT_IBI                 = 0x08U,
    I3C_IP_MASTER_EVENT_MASTER_REQUEST      = 0x09U
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
    I3C_IP_MASTER_HIGH_KEEPER_WIRED_IN = 0x01U,    /**< Use pin_HK controls */
    I3C_IP_MASTER_PASSIVE_SDA          = 0x02U,    /**< Passive on SDA: can Hi-Z for Bus Free and hold */
    I3C_IP_MASTER_PASSIVE_SDA_SCL      = 0x03U     /**< Passive on SDA and SCL: can Hi-Z both for Bus Free, and can Hi-Z SDA for hold */
} I3c_Ip_MasterHighKeepType;

/**
* @brief Bus type with EmitStartAddr.
*
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
*/
typedef enum
{
    I3C_IP_WRITE   = 0x00U, /**< @brief Used to send data to a slave */
    I3C_IP_READ    = 0x01U  /**< @brief Used to receive data from a slave */
} I3c_Ip_DirectionType;

#if (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS)
/**
* @brief In-Band Interrupt (IBI) response.
*
*/
typedef enum
{
    I3C_IP_IBI_RESP_ACK            = 0x00U,    /**< ACK with/without mandatory byte */
    I3C_IP_IBI_RESP_NACK           = 0x01U,    /**< NACK */
    I3C_IP_IBI_RESP_ACK_MANDATORY  = 0x02U,    /**< ACK with mandatory byte */
    I3C_IP_IBI_RESP_MANUAL         = 0x03U     /**< Reserved */
} I3c_Ip_IbiResponseType;
#endif /* (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS) */

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
*/
typedef enum
{
    I3C_IP_STATUS_SUCCESS           = 0x00U,
    I3C_IP_STATUS_ERROR             = 0x01U,    /**< An error occurred on the I3C Bus */
    I3C_IP_STATUS_BUSY              = 0x02U,    /**< The I3C Bus is busy */
    I3C_IP_STATUS_TIMEOUT           = 0x03U,    /**< The module has stalled too long in a frame */
    I3C_IP_STATUS_MAX_SLAVES_EXCEED = 0x04U,    /**< This status signals that the number of Slave Devices (on the bus) which need a Dynamic Address
                                                     is larger than the number of available Dynamic Addresses. */
    I3C_IP_STATUS_IBI_WON           = 0x05U,    /**< IBI/MR/HJ won the arbitration on a header address */
    I3C_IP_STATUS_SLAVE_START       = 0x06U,
    I3C_IP_STATUS_CONTROL_DONE      = 0x07U
} I3c_Ip_StatusType;

/**
* @brief Indicates size of the transfer message.
*
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

#if (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS)
/**
* @brief Indicates the current slave operation mode.
*
*/
typedef enum
{
    I3C_IP_SLAVE_NORMAL_MODE        = 0x00U,    /**< Normal mode */
    I3C_IP_SLAVE_IBI_REQUEST        = 0x01U,    /**< Start an IBI event */
    I3C_IP_SLAVE_MASTER_REQUEST     = 0x02U,    /**< Start a MR or P2P event */
    I3C_IP_SLAVE_HOT_JOIN_REQUEST   = 0x03U     /**< Start a HJ event */
} I3c_Ip_SlaveRequestType;
#endif /* (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS) */

/**
* @brief Events which can trigger I3C slave callback.
*
*/
typedef enum
{
    I3C_IP_SLAVE_EVENT_START          = 0x00U,
    I3C_IP_SLAVE_EVENT_MATCHED        = 0x01U,
    I3C_IP_SLAVE_EVENT_STOP           = 0x02U,
    I3C_IP_SLAVE_EVENT_DA_CHANGED     = 0x03U,
    I3C_IP_SLAVE_EVENT_CCC_RECEIVED   = 0x04U,
    I3C_IP_SLAVE_EVENT_ERROR          = 0x05U,
    I3C_IP_SLAVE_EVENT_HDR_MATCHED    = 0x06U,
    I3C_IP_SLAVE_EVENT_CCC_HANDLED    = 0x07U,
    I3C_IP_SLAVE_EVENT_REQUEST        = 0x08U,
    I3C_IP_SLAVE_EVENT_TX_REQUEST     = 0x09U,
    I3C_IP_SLAVE_EVENT_RX_REQUEST     = 0x0AU,
    I3C_IP_SLAVE_EVENT_END_TRANSFER   = 0x0BU,
    I3C_IP_SLAVE_EVENT_RX_FULL        = 0x0CU,
    I3C_IP_SLAVE_EVENT_TX_EMPTY       = 0x0DU,
    I3C_IP_SLAVE_EVENT_HEADER_MATCHED = 0x0EU
} I3c_Ip_SlaveEventType;

/**
* @brief Common Command Codes.
*        These defines should be used with I3c_SendCommonCommandCode() and I3c_ReadCommonCommandCode().
*        For more details about each command, please see Mipi Basic Specifications v1.0 document.
*
*/

    #define I3C_IP_CCC_ENEC_BROADCAST      (0x00U)    /**< Enable events */
    #define I3C_IP_CCC_DISEC_BROADCAST     (0x01U)    /**< Disable events */
    #define I3C_IP_CCC_ENTAS0_BROADCAST    (0x02U)    /**< Enter activity state 0 */
    #define I3C_IP_CCC_ENTAS1_BROADCAST    (0x03U)    /**< Enter activity state 1 */
    #define I3C_IP_CCC_ENTAS2_BROADCAST    (0x04U)    /**< Enter activity state 2 */
    #define I3C_IP_CCC_ENTAS3_BROADCAST    (0x05U)    /**< Enter activity state 3 */
    #define I3C_IP_CCC_RSTDAA_BROADCAST    (0x06U)    /**< Reset Dynamic Address Assignment */
    #define I3C_IP_CCC_ENTDAA_BROADCAST    (0x07U)    /**< Enter Dynamic Address Assignment */
    #define I3C_IP_CCC_DEFTGTS_BROADCAST   (0x08U)    /**< Define list of target devices */
    #define I3C_IP_CCC_SETMWL_BROADCAST    (0x09U)    /**< Set maximum write length */
    #define I3C_IP_CCC_SETMRL_BROADCAST    (0x0AU)    /**< Set maximum read length */
    #define I3C_IP_CCC_ENTTM_BROADCAST     (0x0BU)    /**< Enter test mode */
    #define I3C_IP_CCC_ENDXFER_BROADCAST   (0x12U)    /**< Provides the framework for Controllers and Targets to exchange set-up parameters
                                                 for ending data transfers in supported HDR Modes. For HDR-DDR, it controls Data Transfer
                                                 Ending Procedure. For more details, please check MIPI I3c Basic Specification document. */
    #define I3C_IP_CCC_ENTHDR0_BROADCAST   (0x20U)    /**< Enter HDR-DDR mode */
    #define I3C_IP_CCC_ENEC_DIRECT         (0x80U)    /**< Enable events */
    #define I3C_IP_CCC_DISEC_DIRECT        (0x81U)    /**< Disable events */
    #define I3C_IP_CCC_ENTAS0_DIRECT       (0x82U)    /**< Enter activity state 0 */
    #define I3C_IP_CCC_ENTAS1_DIRECT       (0x83U)    /**< Enter activity state 1 */
    #define I3C_IP_CCC_ENTAS2_DIRECT       (0x84U)    /**< Enter activity state 2 */
    #define I3C_IP_CCC_ENTAS3_DIRECT       (0x85U)    /**< Enter activity state 3 */
    #define I3C_IP_CCC_RSTDAA_DIRECT       (0x86U)    /**< Reset Dynamic Address Assignment */
    #define I3C_IP_CCC_SETDASA_DIRECT      (0x87U)    /**< Set Dynamic Addres from Static Address */
    #define I3C_IP_CCC_SETNEWDA_DIRECT     (0x88U)    /**< Set New Dynamic Addres */
    #define I3C_IP_CCC_SETMWL_DIRECT       (0x89U)    /**< Set maximum write length */
    #define I3C_IP_CCC_SETMRL_DIRECT       (0x8AU)    /**< Set maximum read length */
    #define I3C_IP_CCC_GETMWL_DIRECT       (0x8BU)    /**< Get maximum write length */
    #define I3C_IP_CCC_GETMRL_DIRECT       (0x8CU)    /**< Get maximum read length */
    #define I3C_IP_CCC_GETPID_DIRECT       (0x8DU)    /**< Get Provisional ID */
    #define I3C_IP_CCC_GETBCR_DIRECT       (0x8EU)    /**< Get Bus Characteristic Register */
    #define I3C_IP_CCC_GETDCR_DIRECT       (0x8FU)    /**< Get Device Characteristic Register */
    #define I3C_IP_CCC_GETSTATUS_DIRECT    (0x90U)    /**< Get device status */
    #define I3C_IP_CCC_GETACCCR_DIRECT     (0x91U)    /**< Get accept mastership */
    #define I3C_IP_CCC_ENDXFER_DIRECT      (0x92U)    /**< Provides the framework for Controllers and Targets to exchange set-up parameters
                                                 for ending data transfers in supported HDR Modes. For HDR-DDR, it controls Data Transfer
                                                 Ending Procedure. For more details, please check MIPI I3c Basic Specification document. */
    #define I3C_IP_CCC_SETBRGTGT_DIRECT    (0x93U)    /**< Set bridge targets */
    #define I3C_IP_CCC_GETMXDS_DIRECT      (0x94U)     /**< Get maximum data speed */

#if (STD_ON == I3C_IP_ENABLE_I3C_FEATURES)
/**
* @brief Causes of slave Dynamic Address change.
*
*/
typedef enum
{
    I3C_IP_SLAVE_DA_NOT_CONFIGURED  = 0x00U,    /**< No info. DA was not configure. */
    I3C_IP_SLAVE_DA_CAUSE_ENTDAA    = 0x01U,    /**< DA assigned using ENTDAA command */
    I3C_IP_SLAVE_DA_CAUSE_SET       = 0x02U,    /**< DA assigned using SETDASA, SETAASA, or SETNEWDA command */
    I3C_IP_SLAVE_DA_CAUSE_RSTDAA    = 0x03U,    /**< DA cleared using RSTDAA command */
    I3C_IP_SLAVE_DA_CAUSE_AUTOMAP   = 0x04U     /**< Auto MAP change happened last. This may have changed this DA as well */
} I3c_Ip_SlaveDACauseType;
#endif /* (STD_ON == I3C_IP_ENABLE_I3C_FEATURES) */

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
typedef void (*I3c_Ip_MasterCallbackType)(I3c_Ip_MasterEventType Event);

#if (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS)
/**
* @brief Callback used to get the In-Band interrupt address, when the master lost the header arbitration.
*
*/
typedef void (*I3c_Ip_MasterGetIbiAddressCallback)(I3c_Ip_MasterEventType Event, uint8 IbiAddress);
#endif /* (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS) */

/**
* @brief Callback for all peripherals which supports I3C features for slave mode.
*
*/
typedef void (*I3c_Ip_SlaveCallbackType)(I3c_Ip_SlaveEventType Event);

/**
* @brief Contains the transfer options.
*        This structure must be configured at runtime, before calling Send/Receive API.
*
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
*/
typedef struct
{
    uint32 I2cBaudRate;                     /**< Desired I2C baud rate in Hz */
    uint32 OpenDrainBaudRate;               /**< Desired Open-Drain baud rate in Hz */
    uint32 PushPullBaudRate;                /**< Desired push-pull baud rate in Hz */
} I3c_Ip_MasterBaudRateType;

#if (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS)
/**
* @brief Contains the In-Band interrupt options for the following Slave Requests.
*        This structure should be set by the user at runtime.
*
*/
typedef struct
{
    boolean IbiSendStop;                    /**< If true, a STOP is emitted after the Slave Request has been processed */
    boolean EmitAutoIbi;                    /**< If TRUE, Auto IBI feature is used for the following In-Band interrupts.
                                                 Using Auto IBI feature means that the master holds in a stopped state and
                                                 emits START + 0x7E continuously such that it will always lose the header arbitration, in favor of the interrupt. */
    uint8 * IbiDataBuffer;                  /**< Buffer to store IBI data bytes, if any. This is used only to store IBI data bytes and will not be used for Hot-Join and Master Request
                                                 bcause they do not have transmitted data. If application does not use IBI with data, then this member's value can be set to NULL_PTR. */
} I3c_Ip_MasterIbiOptionType;
#endif /* (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS) */

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
#if (STD_ON == I3C_IP_ENABLE_I3C_FEATURES)
    const uint8 * DynamicAddressList;                                   /**< List of the dynamic addresses to be assigned during DAA process */
    uint8 DynamicAddressCount;                                          /**< Number of Dynamic Addresses to be assigned during DAA process */
#endif /* (STD_ON == I3C_IP_ENABLE_I3C_FEATURES) */
    I3c_Ip_TransferType TransferType;                                   /**< Type of the transfer: DMA/interrupts */
    boolean OpenDrainStop;                                              /**< If true, then STOP will be emitted at open-drain speeds even for I3C messages */
#if (STD_ON == I3C_IP_DMA_FEATURE_AVAILABLE)
    uint32 DmaTxChannel;                                                /**< DMA Tx channel ID */
    uint32 DmaRxChannel;                                                /**< DMA Rx channel ID */
#endif /* I3C_IP_DMA_FEATURE_AVAILABLE */
#if (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS)
    I3c_Ip_MasterIbiOptionType IbiOptions;                              /**< In-Band interrupt options for the following Slave Requests */
    I3c_Ip_IbiResponseType IbiResp;                                     /**< In-Band Interrupt response type */
#endif /* (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS) */
    I3c_Ip_MasterCallbackType MasterCallback;                           /**< Master callback function */
#if (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS)
    I3c_Ip_MasterGetIbiAddressCallback MasterGetIbiAddressCallback;     /**< This callback function is used to get the address of the slave which requested an In-Band interrupt. */
#endif /* (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS) */
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
    boolean EnableStartOptimization;            /**< If this is true, then all I3C Dynamic Addresses must be less than 0x40.
                                                     This improves the speed for sending the START header */
    boolean NoMandatoryByte;                    /**< If true, then the ADDRx from In-Band Interrupt Rules register
                                                     refer to slaves without mandatory byte */
#if (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS)
    uint8 * IbiAddressRegistry;                 /**< Addresses of the slaves which use In-Band Interrupts */
    uint8 SlavesIbiByteCount;                   /**< Number of slaves that use the In-Band Interrupt byte */
#endif /* (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS) */
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
    uint8 RepeatedStarts;                       /**< Number of Repeated STARTs on the I3c bus, before a STOP was detected.
                                                     When STOP signal is detected, this counter is reseted. */
    I3c_Ip_DirectionType Direction;             /**< Specifies the direction of the transfer, send or receive */
    I3c_Ip_TransferSizeType TransferSize;       /**< Transfer size: bytes or half words */
    I3c_Ip_TransferType TransferType;           /**< Type of the transfer: DMA/interrupts */
#if (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS)
    boolean ExtendedIbiData;                    /**< If true, then there are more bytes following the mandatory byte */
    uint8 CountExtraBytes;                      /**< The number of extra bytes past the Mandatory Data Byte */
#endif /* (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS) */
#if (STD_ON == I3C_IP_DMA_FEATURE_AVAILABLE)
    uint32 DmaTxChannel;                        /**< DMA Tx channel ID */
    uint32 DmaRxChannel;                        /**< DMA Rx channel ID */
#endif /* I3C_IP_DMA_FEATURE_AVAILABLE */
    I3c_Ip_SlaveCallbackType SlaveCallback;     /**< Slave callback function */
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
#if (STD_ON == I3C_IP_ENABLE_I3C_FEATURES)
    boolean MasterCapableDevice;                /**< If true, then this is a Master-Capable device and it can gain mastership */
#endif /* (STD_ON == I3C_IP_ENABLE_I3C_FEATURES) */
    boolean Nack;                               /**< If true, then the slave will NACK all requests to it, except a CCC broadcast */
    boolean MatchStartStop;                     /**< Whether to assert START/STOP status only if the slave is addressed */
    boolean IgnoreS0S1Error;                    /**< Whether to ignore S0/S1 error in SDR mode */
    boolean HighDataRateSupport;                /**< If true, the slave allow HDR-DDR messaging, if available */
    boolean OfflineSupport;                     /**< Whether to wait 60 us of bus quiet or HDR Exit Pattern to ensure bus is not in HDR mode and safely track the message */
    uint8 BusAvailableMatch;                   /**< Provides the count of the slow clock to count out 1 us (or more), to allow an In-Band Interrupt (IBI) to drive SDA low*/
    uint8 StaticAddress;                        /**< Slave's Static Address */
    uint8 BCR;                                  /**< Bus Characteristic Register */
    uint8 DCR;                                  /**< Device Characteristic Register */
    uint16 VendorId;                            /**< Slave Vendor ID */
    uint32 PartNumber;                          /**< Slave ID Part Number */
    uint8 VendorInformation;                    /**< Vendor Information */
    uint8 ActivityState;                        /**< Slave Activity State */
    uint8 PendingInt;                           /**< Pending Interrupt Number */
    uint8 MapIndex;                             /**< Index of Dynamic Address that the In-Band Interrupt is for */
    uint8 ClockFrequency;                       /**< Slave control clock frequency */
    uint8 ClockAccuracy;                        /**< Slave control clock accuracy */
#if (STD_ON == I3C_IP_SLAVE_RESET_SUPPORT)
    uint8 CustomTimeRecover;                    /**< Time to recover, in milliseconds, from a custom Reset, if enabled. This will be a custom RSTACT type. */
    uint8 ChipResetTimeRecover;                 /**< Time to recover, in seconds, from a full system/chip reset. */
    uint8 I3cResetTimeRecover;                  /**< Time to recover, in milliseconds from the I3C peripheral being reset. */
#endif /* (STD_ON == I3C_IP_SLAVE_RESET_SUPPORT) */
#if (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS)
    boolean HotJoinDevice;                      /**< If true, this is a Hot-Join Device and all specific requirements apply */
#endif /* (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS) */
    I3c_Ip_SlaveStateType * SlaveState;         /**< Pointer to the slave state structure */
} I3c_Ip_SlaveConfigType;

/**
* @brief Slave device characteristics structure
*
* This structure is used to store the characteristics of the I3C slave devices on the bus.
*
*/
typedef struct
{
#if (STD_ON == I3C_IP_ENABLE_I3C_FEATURES)
    uint8 DynamicAddress;   /**< Slave DA which was assigned by the master during DAA */
#endif /* (STD_ON == I3C_IP_ENABLE_I3C_FEATURES) */
    uint8 BCR;              /**< Bus Characteristic Register */
    uint8 DCR;              /**< Device Characteristic Register */
    uint16 VendorId;        /**< Slave Vendor ID */
    uint32 PartNumber;      /**< Slave ID Part Number */
} I3c_Ip_SlaveDeviceType;

/**
* @brief Type of the mapped address.
*
*/
typedef enum
{
    I3C_IP_SLAVE_MAP_DYNAMIC_ADDRESS  = 0U, /**< Dynamic Address is mapped */
    I3C_IP_SLAVE_MAP_STATIC_ADDRESS   = 1U  /**< Static Address is mapped */
} I3c_Ip_SlaveAddressType;

/**
* @brief Slave configure characteristics for the mapped addresses.
*
* This structure is used to configure the slave's characteristics for the mapped addresses.
*
*/
typedef struct
{
    boolean Enable;                         /**< If true, this map entry is enabled */
    uint8 Address;                          /**< If Enable = true, this is Static or Dynamic Address, depending on AddressType */
    I3c_Ip_SlaveAddressType AddressType;    /**< Type of the mapped address: Static or Dynamic */
#if (STD_ON == I3C_IP_SA10B_SUPPORT)
    uint8 SA10BitExtension;                 /**< Static Address extension to form a 10-bit address.This field is not supported on all platforms */
#endif /* (STD_ON == I3C_IP_SA10B_SUPPORT) */
    boolean Nack;                           /**< If true, all messages to this address will be NACKed */
#if (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT)
    boolean Auto;                           /**< If true, this slot is enabled for Auto Dynamic Address Assignment. Only applies if Enable = false */
    uint8 DCR;                              /**< If DCR is to be replaced by register, this provides the DCR value. */
#endif /* (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT) */
} I3c_Ip_SlaveMapAddressType;

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
