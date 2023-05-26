/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef POWER_IP_AEC_TYPES_H
#define POWER_IP_AEC_TYPES_H

/**
*   @file       Power_Ip_AEC_Types.h
*   @version    3.0.0
*
*   @brief   POWER IP driver header file.
*   @details POWER IP driver header file.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif




/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Cfg_Defines.h"
#include "Mcal.h"
#if (defined(POWER_IP_S32M244) || defined(POWER_IP_S32M242))
  #include "S32M24x_AEC_AE.h"
#endif
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_AEC_TYPES_VENDOR_ID                       43
#define POWER_IP_AEC_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_AEC_TYPES_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_AEC_TYPES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_AEC_TYPES_SW_MAJOR_VERSION                3
#define POWER_IP_AEC_TYPES_SW_MINOR_VERSION                0
#define POWER_IP_AEC_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_AEC_Types.h file and Mcal.h file are of the same Autosar version */
#if ((POWER_IP_AEC_TYPES_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AEC_TYPES_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_AEC_Types.h and Mcal.h are different"
#endif
#endif

/* Check if Power_Ip_AEC_Types.h file and Power_Ip_Cfg_Defines.h file have same versions */
#if (POWER_IP_AEC_TYPES_VENDOR_ID  != POWER_IP_CFG_DEFINES_VENDOR_ID)
    #error "Power_Ip_AEC_Types.h and Power_Ip_Cfg_Defines.h have different vendor IDs"
#endif

/* Check if Power_Ip_AEC_Types.h file and Power_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((POWER_IP_AEC_TYPES_AR_RELEASE_MAJOR_VERSION    != POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AEC_TYPES_AR_RELEASE_MINOR_VERSION    != POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AEC_TYPES_AR_RELEASE_REVISION_VERSION != POWER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_AEC_Types.h and Power_Ip_Cfg_Defines.h are different"
#endif

/* Check if Power_Ip_AEC_Types.h file and Power_Ip_Cfg_Defines.h file are of the same Software version */
#if ((POWER_IP_AEC_TYPES_SW_MAJOR_VERSION != POWER_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (POWER_IP_AEC_TYPES_SW_MINOR_VERSION != POWER_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (POWER_IP_AEC_TYPES_SW_PATCH_VERSION != POWER_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_AEC_Types.h and Power_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define AEC_AE_RSTGEN_CFG_REGS_OTP_ENABLE_U16          ((uint16)(0x0001))
#define AEC_AE_RSTGEN_CFG_REGS_OTP_DISABLE_U16         ((uint16)(0x0000))
#define AEC_AE_RSTGEN_CFG_CANPHY_ENABLE_U16            ((uint16)(0x0002))
#define AEC_AE_RSTGEN_CFG_CANPHY_DISABLE_U16           ((uint16)(0x0000))
#define AEC_AE_RSTGEN_CFG_LINPHY_HP_ENABLE_U16         ((uint16)(0x0004))
#define AEC_AE_RSTGEN_CFG_LINPHY_HP_DISABLE_U16        ((uint16)(0x0000))
#define AEC_AE_RSTGEN_CFG_LINPHY_LP_ENABLE_U16         ((uint16)(0x0008))
#define AEC_AE_RSTGEN_CFG_LINPHY_LP_DISABLE_U16        ((uint16)(0x0000))
#define AEC_AE_RSTGEN_CFG_GDU_ENABLE_U16               ((uint16)(0x0010))
#define AEC_AE_RSTGEN_CFG_GDU_DISABLE_U16              ((uint16)(0x0000))
#define AEC_AE_RSTGEN_CFG_HVI_ENABLE_U16               ((uint16)(0x0020))
#define AEC_AE_RSTGEN_CFG_HVI_DISABLE_U16              ((uint16)(0x0000))
#define AEC_AE_RSTGEN_CFG_DPGA_ENABLE_U16              ((uint16)(0x0040))
#define AEC_AE_RSTGEN_CFG_DPGA_DISABLE_U16             ((uint16)(0x0000))
#define AEC_AE_RSTGEN_CFG_TEMPSENSOR_ENABLE_U16        ((uint16)(0x0080))
#define AEC_AE_RSTGEN_CFG_TEMPSENSOR_DISABLE_U16       ((uint16)(0x0000))
#define AEC_AE_RSTGEN_CFG_CXPI_ENABLE_U16              ((uint16)(0x0100))
#define AEC_AE_RSTGEN_CFG_CXPI_DISABLE_U16             ((uint16)(0x0000))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            Configuration for AEC.
* @details          The Reset generator configuration (AEC_RSTGEN_CFG)
*/
typedef struct
{
    uint16 Rstgencfg;                   /**< @brief Reset generator configuration (AEC_RSTGEN_CFG). */
} Power_Ip_AEC_ConfigType;

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
#endif /* POWER_IP_AEC_TYPES_H */

