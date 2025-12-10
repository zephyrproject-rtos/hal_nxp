/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_PORT_IP_DEFINES
#define SIUL2_PORT_IP_DEFINES

/**
*   @file    Siul2_Port_Ip_Defines.h
*
*   @addtogroup Port_CFG
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
#include "S32K566_SIUL2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_DEFINES_VENDOR_ID_H                       43
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_H        4
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_H        9
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_H     0
#define SIUL2_PORT_IP_DEFINES_SW_MAJOR_VERSION_H                0
#define SIUL2_PORT_IP_DEFINES_SW_MINOR_VERSION_H                8
#define SIUL2_PORT_IP_DEFINES_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define IP_SIUL2_2_BASE             ((0x4208C000u))
#define IP_SIUL2_2                  ((SIUL2_Type *)IP_SIUL2_2_BASE)

#define SIUL2_MSCR_SRE_MASK     SIUL2_MSCR_SRC_MASK
#define SIUL2_MSCR_SRE_SHIFT    SIUL2_MSCR_SRC_SHIFT
#define SIUL2_MSCR_SRE(x)       SIUL2_MSCR_SRC(x)

#define SIUL2_1_IMCR_IDX_OFFSET_U32        ((uint32)1000u)
#define SIUL2_2_IMCR_IDX_OFFSET_U32        ((uint32)2000u)
#define SIUL2_3_IMCR_IDX_OFFSET_U32        ((uint32)3000u)
#define SIUL2_4_IMCR_IDX_OFFSET_U32        ((uint32)4000u)

#define SIUL2_PORT_IP_MULTIPLE_SIUL2_INSTANCES

/**
* @brief Number of SIUL2 instances present on the subderivative
*/
#define SIUL2_NUM_SIUL2_INSTANCES_U8 (5)

/**
* @brief Macros defined for the SIUL2 IPV that are protected.
*/
#define MCAL_SIUL2_REG_PROT_AVAILABLE   (STD_ON)

/**
* @brief Support for User mode.
* If this parameter has been configured to STD_ON, the PORT driver code can be executed from both supervisor and user mode.
*/
#define PORT_ENABLE_USER_MODE_SUPPORT   (STD_OFF)
/**
* @brief Support for REG_PROT in SIUL2 IP.
*        If the current platform implements REG_PROT for SIUL2 IP, this parameter will be defined, and will enable REG_PROT configuration for SIUL2 IP in PORT drvier
*/
#define PORT_SIUL2_REG_PROT_AVAILABLE   (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef PORT_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Port in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
        #endif /* (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT) */
    #endif /* ifdef PORT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/* Pre-processor switch to enable/disable development error detection for Siul2 Ip API */
#define SIUL2_PORT_IP_DEV_ERROR_DETECT                         (STD_ON)

/**
* @brief Defines specifying number of IMCRs for each of the SIUL2 instances on the platform
*/
#define PORT_SIUL2_0_IMCRS_IDX_END_U16     ((uint16)235)
#define PORT_SIUL2_1_IMCRS_IDX_END_U16     ((uint16)1170)
#define PORT_SIUL2_2_IMCRS_IDX_END_U16     ((uint16)2109)
#define PORT_SIUL2_3_IMCRS_IDX_END_U16     ((uint16)3228)
#define PORT_SIUL2_4_IMCRS_IDX_END_U16     ((uint16)4216)
/* Pre-processor switch to enable/disable VirtWrapper support */
#define PORT_VIRTWRAPPER_SUPPORT                      (STD_OFF)

/*! @brief SIUL2 module has 1 bit SMC */
#define FEATURE_SIUL2_PORT_IP_HAS_ONEBIT_SAFEMODE               (STD_ON)
/*! @brief SIUL2 module has 1 bit SRC */
#define SIUL2_PORT_IP_HAS_ONEBIT_SLEWRATE                       (STD_ON)

/*! @brief SIUL2 module has RCVR bit */
#define FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT               (STD_ON)
/*! @brief SIUL2 module has ICE bit */
#define FEATURE_SIUL2_PORT_IP_HAS_INJECTION_CURRENT_DETECTION   (STD_ON)
/*! @brief SIUL2 module has INV bit */
#define FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA                   (STD_ON)
/*! @brief SIUL2 module has PKE_PD2 bit */
#define FEATURE_SIUL2_PORT_IP_HAS_PAD_KEEPING_ENABLE_2          (STD_ON)
/*! @brief SIUL2 module has PKE_PD1 bit */
#define FEATURE_SIUL2_PORT_IP_HAS_PAD_KEEPING_ENABLE_1          (STD_ON)
/*! @brief SIUL2 module has PKE bit */
#define FEATURE_SIUL2_PORT_IP_HAS_PAD_KEEPING                   (STD_ON)
/*! @brief SIUL2 module has DSE bit */
#define FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH                (STD_ON)
/*! @brief SIUL2 module has IFE bit */
#define FEATURE_SIUL2_PORT_IP_HAS_INPUT_FILTER                  (STD_ON)

#define SIUL2_0_MSCR_BASE                (IP_SIUL2_0->MSCR)
#define SIUL2_1_MSCR_BASE                (IP_SIUL2_1->MSCR)
#define SIUL2_2_MSCR_BASE                (IP_SIUL2_2->MSCR)
#define SIUL2_3_MSCR_BASE                (IP_SIUL2_3->MSCR)
#define SIUL2_4_MSCR_BASE                (IP_SIUL2_4->MSCR)

/** SIUL2_0 */
/** Peripheral PORTA base pointer. Pins start from PAD_000 to PAD_015. */
#define PORTA                            ((Siul2_Port_Ip_PortType *)(SIUL2_0_MSCR_BASE + 0x00))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
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

#endif /* SIUL2_PORT_IP_DEFINES */

