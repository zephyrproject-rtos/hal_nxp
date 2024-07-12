/*
 * Copyright 2021-2024 NXP
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
#define I3C_IP_SW_MAJOR_VERSION_CFGDEFINES             1
#define I3C_IP_SW_MINOR_VERSION_CFGDEFINES             0
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
#define I3C_MASTER_0 0

/**
* @brief  This define indicate that the I3c DMA feature is enabled or disabled
*/
#define I3C_IP_DMA_FEATURE_AVAILABLE           (STD_OFF)

/**
* @brief  This define indicate that the I3C Osif Timeout Method
*/
#define I3C_IP_TIMEOUT_TYPE                    (OSIF_COUNTER_DUMMY)

/**
* @brief  This define indicate that the I3C Timeout Value
*/
#define I3C_IP_TIMEOUT_VALUE                   (50000U)

/**
* @brief  This define indicate that the I3C Tx Fifo Size supported
*/
#define I3C_IP_TX_FIFO_SIZE                    (16U)

/**
* @brief  This define indicate that the I3C Rx Fifo Size supported
*/
#define I3C_IP_RX_FIFO_SIZE                    (16U)

/**
* brief  This define to check dev_assert
*/
#define I3C_IP_DEV_ASSET(x)                    (void)(x)
/* brief Define reset value for some registers*/
#define I3C_IP_SCONFIG_RESET_VALUE    (0x002F0060U)
#define I3C_IP_SDMACTRL_RESET_VALUE   (0x10U)
#define I3C_IP_SDATACTRL_RESET_VALUE  (0x80000030U)
#define I3C_IP_MDATACTRL_RESET_VALUE  (0x80000030U)
#define I3C_IP_MDMACTRL_RESET_VALUE   (0x10U)
#define I3C_IP_MCTRL_RESET_VALUE      (0x0U)
#define I3C_IP_MCONFIG_RESET_VALUE    (0x0U)
/**
* @brief SCL maximum frequency (in Hz) when in I2C Mode
*
* @details Then in I2C Mode, I3c Standard specifies a maximum SCL frequency of 1MHz when communicating
*          with devices that support Fast Mode+. If only Fast Mode is supported, maximum SCL frequency should be 400kHz.
*/
#define I3C_IP_MAX_I2C_BAUD_RATE   (1200000U)

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

