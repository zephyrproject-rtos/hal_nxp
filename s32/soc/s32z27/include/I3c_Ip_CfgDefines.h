/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef I3C_IP_CFGDEFINES_H
#define I3C_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup i3c_ip_config I3c IPL Configuration
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
#include "StandardTypes.h"
#include "OsIf.h"
#include "S32Z2_I3C.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I3C_IP_VENDOR_ID_CFGDEFINES                    43
#define I3C_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     4
#define I3C_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES     7
#define I3C_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES  0
#define I3C_IP_SW_MAJOR_VERSION_CFGDEFINES             0
#define I3C_IP_SW_MINOR_VERSION_CFGDEFINES             9
#define I3C_IP_SW_PATCH_VERSION_CFGDEFINES             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and StandardTypes header file are of the same Autosar version */
#if ((I3C_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     != STD_AR_RELEASE_MAJOR_VERSION) || \
     (I3C_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of I3c_Ip_CfgDefines.h and StandardTypes.h are different"
#endif

/* Check if current file and OsIf header file are of the same Autosar version */
#if ((I3C_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (I3C_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES     != OSIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of I3c_Ip_CfgDefines.h and OsIf.h are different"
#endif

#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief  This define indicate that the I3c Dev Error Detection is enabled or disabled
*/
#define I3C_IP_DEV_ERROR_DETECT                (STD_OFF)

/**
* @brief  This define indicate that the I3c DMA feature is enabled or disabled
*/
#define I3C_IP_DMA_FEATURE_AVAILABLE           (STD_OFF)

/**
* @brief  This define indicate that the I3C Osif Timeout Method
*/
#define I3C_IP_TIMEOUT_TYPE                    (OSIF_COUNTER_SYSTEM)

/**
* @brief  This define indicate that the I3C Timeout Value
*/
#define I3C_IP_TIMEOUT_VALUE                   (30000U)

/**
* @brief  This define indicate that the I3C Tx Fifo Size supported
*/
#define I3C_IP_TX_FIFO_SIZE                    (16U)

/**
* @brief  This define indicate that the I3C Rx Fifo Size supported
*/
#define I3C_IP_RX_FIFO_SIZE                    (16U)

/**
* @brief  This define indicate that the I3C maximum slave devices supported
*/
#define I3C_IP_MAX_DEVICES                     (11U)

/**
* @brief  These defines indicate which hardware instances are available for this platform
*/
#define I3C0_IP_INSTANCE_AVAILABLE             (STD_ON)
#define I3C1_IP_INSTANCE_AVAILABLE             (STD_ON)
#define I3C2_IP_INSTANCE_AVAILABLE             (STD_ON)

/**
* @brief  This define indicate that the 10-bit Static Address is supported for this platform
*/
#define I3C_IP_SA10B_SUPPORT                   (STD_OFF)


/**
* @brief  This define indicate that the HDR-BT mode is supported for this platform
*/
#define I3C_IP_HDR_BT_SUPPORT                  (STD_ON)

/**
* @brief  This define indicate that the SMAPCTRL array is supported for this platform
*/
#define I3C_IP_SMAPCTRL_ARRAY_SUPPORT          (STD_ON)

/**
* @brief  This define indicate that the Self Reset is supported for this platform
*/
#define I3C_IP_SELF_RESET_SUPPORT              (STD_ON)

/**
* @brief  This define indicate that the Slave Reset is supported for this platform
*/
#define I3C_IP_SLAVE_RESET_SUPPORT             (STD_ON)

/**
* @brief  This define indicate the maximum number of slave mapped addresses for this platform
*/
#define I3C_IP_MAX_MAP_ADDRESSES               (4U)

/**
* @brief  This define indicate that Slave Requests feature is enabled or disabled.
*/
#define I3C_IP_ENABLE_SLAVE_REQUESTS           (STD_OFF)

#if (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS)
/**
* @brief  This states if this platform has more than 4 IBI extra data bytes.
*         This is a specific parameter and might change when more platforms available.
*/
#define I3C_IP_OVER_IBI_EXTRA_DATA_BYTES_THR   (STD_OFF)
#endif /* (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS) */

/**
* @brief  This define indicate that I3c features is enabled or disabled.
*/
#define I3C_IP_ENABLE_I3C_FEATURES             (STD_OFF)

/**
* @brief  This define indicate that Dynamic Address Assignment process is enabled/disabled at Init() function.
*/
#define I3C_IP_ENABLE_DAA_INIT_TIME            (STD_OFF)
/**
* @brief  This define indicate if errata ERR051162 is applicable.
*/
#define I3C_IP_ERR051162_APPLICABLE            (STD_ON)

/**
* @brief  I3c channel name to Hw Unit id mapping
*/
#define I3cChannel_0                   (2U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

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

#endif /* I3C_IP_CFGDEFINES_H */
