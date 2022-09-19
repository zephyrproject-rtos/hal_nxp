/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LINFLEXD_UART_IP_DEFINES_H
#define LINFLEXD_UART_IP_DEFINES_H

/**
*   @file
*   @defgroup linflexd_uart_ip Linflexd UART IPL
*   @addtogroup  linflexd_uart_ip Linflexd UART IPL
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
* 4) user callback header files
==================================================================================================*/
#include <zephyr/devicetree.h>
#include "S32Z2_LINFLEXD.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_UART_IP_DEFINES_VENDOR_ID                     43
#define LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MAJOR_VERSION      4
#define LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MINOR_VERSION      7
#define LINFLEXD_UART_IP_DEFINES_AR_RELEASE_REVISION_VERSION   0
#define LINFLEXD_UART_IP_DEFINES_SW_MAJOR_VERSION              0
#define LINFLEXD_UART_IP_DEFINES_SW_MINOR_VERSION              9
#define LINFLEXD_UART_IP_DEFINES_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_Defines.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/
/* @brief Development error detection */
#define LINFLEXD_UART_IP_DEV_ERROR_DETECT       (STD_OFF)

/* @brief Total number of channels configured */
#define LINFLEXD_UART_IP_NUMBER_OF_INSTANCES    (DT_NUM_INST_STATUS_OKAY(nxp_s32_linflexd))

/* @brief Uart Osif source counter. This parameter is used to select between different OsIf counter implementation */
#define LINFLEXD_UART_IP_TIMEOUT_TYPE           (OSIF_COUNTER_DUMMY)

/* @brief Number of loops before returning STATUS_TIMEOUT.*/
#define LINFLEXD_UART_IP_TIMEOUT_VALUE_US       (0)

/* @brief LINFLEXD rx/tx/error interrupt lines ored together. */
#define LINFLEXD_UART_IP_ORED_INT_LINES         (1U)

/* @brief LINFlexD DMA support */
#define LINFLEXD_UART_IP_HAS_DMA_ENABLED        (STD_OFF)

/* @brief LINFlexD User-mode support */
#define LINFLEXD_UART_IP_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

/* @brief LINFLEXD DMA enabled instances */
#define LINFLEXD_UART_IP_INST_HAS_DMA   {(boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE}

/* @brief Support for Uart Timeout Interrupt. If this parameter has been configured to TRUE, the Uart driver will enable Timeout Interrupt. */
#define LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT  (STD_OFF)

#if (STD_ON == LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT)
    /* @brief Array of instances that have loopback mode enabled. */
    #define LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT_PER_INSTANCE  {(boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE}
#endif

/* @brief Support for Internal Loopback. If this parameter has been configured to TRUE, the Uart driver will be executed in Loopback mode. */
#define LINFLEXD_UART_IP_ENABLE_INTERNAL_LOOPBACK  (STD_OFF)

#if (STD_ON == LINFLEXD_UART_IP_ENABLE_INTERNAL_LOOPBACK)
    /* @brief Array of instances that have loopback mode enabled. */
    #define LINFLEXD_UART_IP_ENABLE_INTERNAL_LOOPBACK_PER_INSTANCE  {(boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE, (boolean) FALSE}
#endif

/* Check the driver user mode is enabled only when the MCAL_ENABLE_USER_MODE_SUPPORT is enabled */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == LINFLEXD_UART_IP_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Uart in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
  #endif /* (STD_ON == LINFLEXD_UART_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

#ifdef MCAL_LINFLEX_REG_PROT_AVAILABLE
    #if ((STD_ON == LINFLEXD_UART_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == MCAL_LINFLEX_REG_PROT_AVAILABLE))
        /* @brief User mode enabled. */
        #define LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_ON)
    #else
        /* @brief User mode disabled. */
        #define LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_OFF)
    #endif
#else
    /* @brief User mode disabled. */
    #define LINFLEXD_UART_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_OFF)
#endif /* MCAL_LINFLEX_REG_PROT_AVAILABLE */
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINFLEXD_UART_IP_DEFINES_H */
