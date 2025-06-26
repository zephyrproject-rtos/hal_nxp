/*
 * Copyright 2022-2025 NXP
*
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MRU_IP_CFG_H
#define MRU_IP_CFG_H

/**
*   @file    Mru_Ip_Cfg.h
*   @version 2.0.1
*
*   @brief   AUTOSAR Platform - Mru configuration header file.
*   @details This file is the header containing all the necessary information for MRU
*            module configuration(s).
*   @addtogroup MRU_IP_DRIVER_CONFIGURATION Mru Ip Driver Configuration
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
* 4) user callback header files
==================================================================================================*/
#include <zephyr/devicetree.h>
#include "Mcal.h"
#include "OsIf.h"
#include "Mru_Ip_CfgDefines.h"
#include "S32Z2_SMU_MRU.h"
#include "S32Z2_RTU_MRU.h"
#include "S32Z2_CE_MRU.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MRU_IP_VENDOR_ID_CFG                       43
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_CFG        4
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_CFG        7
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION_CFG     0
#define CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION_CFG                2
#define CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION_CFG                0
#define CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION_CFG                1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mru_Ip_Cfg.h and Mcal.h are different"
    #endif
    /* Check if the current file and OsIf.h header file are of the same version */
    #if ((CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_CFG != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mru_Ip_Cfg.h and OsIf.h are different"
    #endif
#endif

/* Check if Mru_Ip_CfgDefines.h and Mru_Ip_Cfg.h are of the same vendor */
#if (CDD_PLATFORM_MRU_IP_CFG_DEFINES_VENDOR_ID != CDD_PLATFORM_MRU_IP_VENDOR_ID_CFG)
    #error "Mru_Ip_CfgDefines.h and Mru_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Mru_Ip_CfgDefines.h file and Mru_Ip_Cfg.h file are of the same Autosar version */
#if ((CDD_PLATFORM_MRU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CDD_PLATFORM_MRU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CDD_PLATFORM_MRU_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Mru_Ip_CfgDefines.h and Mru_Ip_Cfg.h are different"
#endif
#if ((CDD_PLATFORM_MRU_IP_CFG_DEFINES_SW_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION_CFG) || \
     (CDD_PLATFORM_MRU_IP_CFG_DEFINES_SW_MINOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION_CFG) || \
     (CDD_PLATFORM_MRU_IP_CFG_DEFINES_SW_PATCH_VERSION != CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Mru_Ip_CfgDefines.h and Mru_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/

/* Not used by Zephyr integration but required to build the drivers */
#define MRU_IP_CONFIG_EXT

#if DT_NODE_HAS_STATUS(DT_NODELABEL(mru0), okay)
/**
* @brief RTU0_MRU0 is enabled and used.
*/
#define RTU0_MRU0_ENABLED                  (STD_ON)
/**
* @brief Instance number for RTU0_MRU0.
*/
#define MRU_IP_RTU0_MRU0_INSTANCE          (0U)
/**
* @brief Instance ID for RTU0_MRU0.
*/
#define MRU_IP_RTU0_MRU0_ID                (0U)
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(mru1), okay)
/**
* @brief RTU0_MRU1 is enabled and used.
*/
#define RTU0_MRU1_ENABLED                  (STD_ON)
/**
* @brief Instance number for RTU0_MRU1.
*/
#define MRU_IP_RTU0_MRU1_INSTANCE          (1U)
/**
* @brief Instance ID for RTU0_MRU1.
*/
#define MRU_IP_RTU0_MRU1_ID                (1U)
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(mru2), okay)
/**
* @brief RTU0_MRU2 is enabled and used.
*/
#define RTU0_MRU2_ENABLED                  (STD_ON)
/**
* @brief Instance number for RTU0_MRU2.
*/
#define MRU_IP_RTU0_MRU2_INSTANCE          (2U)
/**
* @brief Instance ID for RTU0_MRU2.
*/
#define MRU_IP_RTU0_MRU2_ID                (2U)
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(mru3), okay)
/**
* @brief RTU0_MRU3 is enabled and used.
*/
#define RTU0_MRU3_ENABLED                  (STD_ON)
/**
* @brief Instance number for RTU0_MRU3.
*/
#define MRU_IP_RTU0_MRU3_INSTANCE          (3U)
/**
* @brief Instance ID for RTU0_MRU3.
*/
#define MRU_IP_RTU0_MRU3_ID                (3U)
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(mru4), okay)
/**
* @brief RTU1_MRU4 is enabled and used.
*/
#define RTU1_MRU4_ENABLED                  (STD_ON)
/**
* @brief Instance number for RTU1_MRU4.
*/
#define MRU_IP_RTU1_MRU4_INSTANCE          (4U)
/**
* @brief Instance ID for RTU1_MRU4.
*/
#define MRU_IP_RTU1_MRU4_ID                (4U)
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(mru5), okay)
/**
* @brief RTU1_MRU5 is enabled and used.
*/
#define RTU1_MRU5_ENABLED                  (STD_ON)
/**
* @brief Instance number for RTU1_MRU5.
*/
#define MRU_IP_RTU1_MRU5_INSTANCE          (5U)
/**
* @brief Instance ID for RTU1_MRU5.
*/
#define MRU_IP_RTU1_MRU5_ID                (5U)
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(mru6), okay)
/**
* @brief RTU1_MRU6 is enabled and used.
*/
#define RTU1_MRU6_ENABLED                  (STD_ON)
/**
* @brief Instance number for RTU1_MRU6.
*/
#define MRU_IP_RTU1_MRU6_INSTANCE          (6U)
/**
* @brief Instance ID for RTU1_MRU6.
*/
#define MRU_IP_RTU1_MRU6_ID                (6U)
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(mru7), okay)
/**
* @brief RTU1_MRU7 is enabled and used.
*/
#define RTU1_MRU7_ENABLED                  (STD_ON)
/**
* @brief Instance number for RTU1_MRU7.
*/
#define MRU_IP_RTU1_MRU7_INSTANCE          (7U)
/**
* @brief Instance ID for RTU1_MRU7.
*/
#define MRU_IP_RTU1_MRU7_ID                (7U)
#endif

/**
* @brief Number of instance is used by the driver.
*/
#define MRU_IP_NUMBER_OF_INSTANCES    (8U)

/**
* @brief ID for interrupt group 0.
*/
#define MRU_IP_INT_GROUP_0  0
/**
* @brief ID for interrupt group 1.
*/
#define MRU_IP_INT_GROUP_1  1

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CONST_UNSPECIFIED
#include "Platform_MemMap.h"
extern RTU_MRU_Type* const Mru_Ip_apxRTU_Bases[RTU_MRU_INSTANCE_COUNT];
#define PLATFORM_STOP_SEC_CONST_UNSPECIFIED
#include "Platform_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif
#endif

/** @} */
