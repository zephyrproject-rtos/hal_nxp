/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Mru_Ip_Types.h
*
*   @brief   MRU IP driver types header file.
*   @details MRU IP driver types header file.

*   @addtogroup MRU_IP_DRIVER Mru Ip Driver
*   @{
*/

#ifndef CDD_MRU_IP_TYPES_H
#define CDD_MRU_IP_TYPES_H

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
#include "Mru_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MRU_IP_TYPES_VENDOR_ID                    43
#define CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define CDD_PLATFORM_MRU_IP_TYPES_SW_MAJOR_VERSION             2
#define CDD_PLATFORM_MRU_IP_TYPES_SW_MINOR_VERSION             0
#define CDD_PLATFORM_MRU_IP_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types header file are of the same Autosar version */
#if ((CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Mru_Ip_Types.h and Std_Types.h are different"
#endif
#endif

/* Check if Mru_Ip_Types.h header file and Mru_Ip_Cfg.h configuration header file are of the same vendor */
#if (CDD_PLATFORM_MRU_IP_TYPES_VENDOR_ID != CDD_PLATFORM_MRU_IP_VENDOR_ID_CFG)
    #error "Mru_Ip_Types.h and Mru_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Mru_Ip_Types.h header file and Mru_Ip_Cfg.h  configuration header file are of the same Autosar version */
#if ((CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_MINOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Mru_Ip_Types.h and Mru_Ip_Cfg.h are different"
#endif
/* Check if Mru_Ip_Types.h header file and Mru_Ip_Cfg.h configuration header file are of the same software version */
#if ((CDD_PLATFORM_MRU_IP_TYPES_SW_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION_CFG) || \
     (CDD_PLATFORM_MRU_IP_TYPES_SW_MINOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION_CFG) || \
     (CDD_PLATFORM_MRU_IP_TYPES_SW_PATCH_VERSION != CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Mru_Ip_Types.h and Mru_Ip_Cfg.h are different"
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

/**
 * @brief      Mru Return values
 * @details    Return information after transmit or read mailbox.
 *
 */
 #define  MRU_IP_STATUS_SUCCESS   0u /**< Successful operation. */
 #define  MRU_IP_STATUS_FAIL      1u /**< Failed operation. */
 #define  MRU_IP_STATUS_TIMEOUT   2u /**< Timeout operation. */
/**
 * @brief      Mru Mailbox status
 */
#define MRU_IP_MAILBOX_INACTIVE   0u /**< Mailbox status is inactive. */
#define MRU_IP_MAILBOX_ACTIVE     1u /**< Mailbox status is active. */

/** @brief   Type defining the possible return types. */
typedef uint8 Mru_Ip_StatusType;


/** @brief   Type defining the Mailbox status.*/
typedef uint8 Mru_Ip_MBStatusType;

/** @brief   Structure defining the data configuration for the transmitting channel. */
typedef struct  
{
   uint8 NumTxMB;                         /**< The number of MailBox used. */ 
   volatile uint32 * const * MBAddList;   /**< List of MailBox address used. */
   const uint8 * TxMBList;                /**< List of MailBox used. */ 
   volatile uint32 * ChMBSTATAdd;         /**< The data configuartion for MBSTAT register. */
   uint8 LastTxMBIndex;                   /**< Last MailBox which is enabled by receiver. */
   boolean bOverwriteMBEnb;               /**< Allow overwriting to mailbox. */
} Mru_Ip_TransmitChannelType;

/** @brief   Structure defining channels information in a Mru instance for the reset instance. */
typedef struct  
{
   uint32 MBStatusMask;       /**< MB Status Mask. */
   volatile uint32 * ChMBSTATAdd;   /**< Address of channel MBSTAT register. */
}Mru_Ip_ResetChOfInsType;

/** @brief   Structure defining the data configuration for the reset instance. */
typedef struct  
{
   uint8 NumChannel;                               /**< The number of channel. */ 
   const Mru_Ip_ResetChOfInsType *MruResetChOfInsCfg;  /**< Struct define channels information in a Mru instance . */
} Mru_Ip_ResetInstanceType;

/** @brief   ISR notification function type for receiving channel. */
typedef void (*Mru_Ip_ReceiveNotificationType)(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief   Structure defining the data configuration for the receiving channel. */
typedef struct  
{
   uint8 ChannelId;                                      /**< Channel Id of the receiving channel. */
   uint8 InstanceId;                                     /**< Instance Id of the hardware unit. */
   uint8 ChannelIndex;                                   /**< Channel Index. */
   uint8 NumRxMB;                                        /**< The number of MailBox used. */ 
   const uint8 * ListRxMB;                                     /**< The list of MailBox used. */ 
   volatile const uint32 * const * MBAddList;                  /**< List of MailBox address used. */
   uint32 * RxBuffer;                                    /**< Receiving buffer. */
   Mru_Ip_ReceiveNotificationType ReceiveNotification;   /**< Store pointer for ISR notification function */
} Mru_Ip_ReceiveChannelType;

/** @brief   Structure defining the pointer configuration link to the receiving channel configuration. */
typedef struct  
{
   const Mru_Ip_ReceiveChannelType * ReceiveChCfg;   /**< Receiving channel configuration */
} Mru_Ip_MBLinkReceiveChannelType;

/** @brief   Structure defining the configuration for the channel. */
typedef struct  
{
   volatile uint32 * ChCFG0Add;                    /**< Address CH_CFG0 register. */
   uint32 ChCFG0;                                  /**< The data configuartion for CH_CFG0 register. */
   volatile uint32 * ChCFG1Add;                    /**< Address CH_CFG1 register. */
   uint32 ChCFG1;                                  /**< The data configuartion for CH_CFG1 register. */
   volatile uint32 * ChMBSTATAdd;                  /**< The data configuartion for MBSTAT register. */
   uint32 NumMailbox;                              /**< Number of Mailbox. */
   boolean bSkipInitChannel;                       /**< Skip the initialization of channel. */
   const Mru_Ip_MBLinkReceiveChannelType (* MBLinkReceiveChCfg)[NOTIFY_STATUS_COUNT]; /**< Link Mailbox to the receiving channel configuration corresponding to groups interrupt. */
} Mru_Ip_ChannelCfgType;

/** @brief   Structure defining information needed for MRU driver initialization. */
typedef struct  
{ 
   uint8 InstanceId;                               /**< Instance Id of the hardware unit. */
   uint8 NumChannel;                               /**< Number of channel. */
   const Mru_Ip_ChannelCfgType * ChannelCfg;       /**< The configuration of receiving channels  */
   volatile const uint32 * NOTIFYAdd[NOTIFY_STATUS_COUNT];
   uint8 StateIndex;                               /**< State index for the HW unit  */
} Mru_Ip_ConfigType;

/** @brief   Structure defining information needed for internal state of the driver. */
typedef struct
{
   const Mru_Ip_ConfigType * HWUnitConfig;         /**< The HW unit configuration. */ 
} Mru_Ip_StateStructureType;
/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*MRU_IP_TYPES*/

/** @} */
