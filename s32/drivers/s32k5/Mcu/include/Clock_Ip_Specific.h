/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_IP_SPECIFIC_H
#define CLOCK_IP_SPECIFIC_H

/**
*   @file    Clock_Ip_Specific.h
*   @version    0.8.0
*
*   @brief   CLOCK IP specific header file.
*   @details CLOCK IP specific header file.
*
*   @addtogroup CLOCK_DRIVER Clock Ip Driver
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
#include "Clock_Ip_Cfg_Defines.h"
#include "Mcal.h"

#if defined(CLOCK_IP_DERIVATIVE_001)
    #include "Clock_Ip_Derivative_001.h"
#endif
#if defined(CLOCK_IP_DERIVATIVE_002)
    #include "Clock_Ip_Derivative_002.h"
#endif
#if defined(CLOCK_IP_DERIVATIVE_003)
    #include "Clock_Ip_Derivative_003.h"
#endif



/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_SPECIFIC_VENDOR_ID                       43
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION        9
#define CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION                0
#define CLOCK_IP_SPECIFIC_SW_MINOR_VERSION                8
#define CLOCK_IP_SPECIFIC_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Specific.h file and Clock_Ip_Cfg_Defines.h file have same versions */
#if (CLOCK_IP_SPECIFIC_VENDOR_ID  != CLOCK_IP_CFG_DEFINES_VENDOR_ID)
    #error "Clock_Ip_Specific.h and Clock_Ip_Cfg_Defines.h have different vendor IDs"
#endif

/* Check if Clock_Ip_Specific.h file and Clock_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION != CLOCK_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Cfg_Defines.h are different"
#endif

/* Check if Clock_Ip_Specific.h file and Clock_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION != CLOCK_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_MINOR_VERSION != CLOCK_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_PATCH_VERSION != CLOCK_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Cfg_Defines.h are different"
#endif

#if defined(CLOCK_IP_DERIVATIVE_001)
    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_001.h file have same versions */
    #if (CLOCK_IP_SPECIFIC_VENDOR_ID  != CLOCK_IP_DERIVATIVE_001_VENDOR_ID)
        #error "Clock_Ip_Specific.h and Clock_Ip_Derivative_001.h have different vendor IDs"
    #endif

    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_001.h file are of the same Autosar version */
    #if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_DERIVATIVE_001_AR_RELEASE_MAJOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_DERIVATIVE_001_AR_RELEASE_MINOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION != CLOCK_IP_DERIVATIVE_001_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Derivative_001.h are different"
    #endif

    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_001.h file are of the same Software version */
    #if ((CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION != CLOCK_IP_DERIVATIVE_001_SW_MAJOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_SW_MINOR_VERSION != CLOCK_IP_DERIVATIVE_001_SW_MINOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_SW_PATCH_VERSION != CLOCK_IP_DERIVATIVE_001_SW_PATCH_VERSION))
        #error "Software Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Derivative_001.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip_Specific.h file and Mcal.h file are of the same Autosar version */
#if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Specific.h and Mcal.h are different"
#endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define CLOCK_IP_XOSC_INSTANCES_ARRAY_SIZE               2U
#define CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE                3U
#define CLOCK_IP_AU16_CLOCK_FEATURES                     0U

#define CLOCK_IP_MC_CGM_PCFS_DIVC_INIT_SHIFT             MC_CGM_PCFS_DIVC8_INIT_SHIFT
#define CLOCK_IP_MC_CGM_PCFS_DIVC_RATE_SHIFT             MC_CGM_PCFS_DIVC8_RATE_SHIFT
#define CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS         MC_CGM_SLC_0_CSS_SWIP_MASK
#define CLOCK_IP_MC_CGM_MUX_CSC_SAFE_SW_MASK             MC_CGM_SLC_0_CSC_SAFE_SW_MASK
#define CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK                MC_CGM_SLC_0_CSS_SWIP_MASK
#define CLOCK_IP_MC_CGM_MUX_CSC_CLK_SW_MASK              MC_CGM_SLC_0_CSC_CLK_SW_MASK
#define CLOCK_IP_MC_CGM_MUX_CSC_RMP_SW_MASK              MC_CGM_SLC_0_CSC_RMP_SW_MASK
#define CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_MASK               MC_CGM_SLC_0_CSS_SWTRG_MASK
#define CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_SHIFT              MC_CGM_SLC_0_CSS_SWTRG_SHIFT

#define CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_SUCCEEDED          1U
#define CLOCK_IP_MC_CGM_MUX_CSS_CLK_SW_NOT_REQUESTED     0U
#define MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_MASK            MC_CGM_SLC_0_DIV_UPD_STAT_DIV_STAT_MASK
#define MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_PENDING         MC_CGM_SLC_0_DIV_UPD_STAT_DIV_STAT_MASK
#define MC_CGM_MUX_DC_DE_MASK                            MC_CGM_SLC_0_DC_0_DE_MASK

#define MC_CGM_PCFS_DIVC_INIT(x)                         MC_CGM_PCFS_DIVC8_INIT(x)
#define MC_CGM_PCFS_DIVC_INIT_MASK                       MC_CGM_PCFS_DIVC8_INIT_MASK
#define MC_CGM_PCFS_DIVC_RATE(x)                         MC_CGM_PCFS_DIVC8_RATE(x)
#define MC_CGM_PCFS_DIVC_RATE_MASK                       MC_CGM_PCFS_DIVC8_RATE_MASK
#define MC_CGM_PCFS_DIVE_DIVE(x)                         MC_CGM_PCFS_DIVE8_DIVE(x)
#define MC_CGM_PCFS_DIVE_DIVE_MASK                       MC_CGM_PCFS_DIVE8_DIVE_MASK
#define MC_CGM_PCFS_DIVS_DIVS(x)                         MC_CGM_PCFS_DIVS8_DIVS(x)
#define MC_CGM_PCFS_DIVS_DIVS_MASK                       MC_CGM_PCFS_DIVS8_DIVS_MASK

#define CLOCK_IP_ALL_CALLBACKS_COUNT                     5U

#define CLOCK_IP_NUMBER_OF_HARDWARE_DFS                  4U
#define CLOCK_IP_NUMBER_OF_HARDWARE_PLL                  3U

#define CLOCK_IP_SELECTORS_SIZE                          39U
#define CLOCK_IP_CMU_INFO_SIZE                           1U


#define CLOCK_IP_SAFE_FREQUENCY                          50000000U


#define CLOCK_IP_FIRC_FREQUENCY                          400000000U
#define CLOCK_IP_DEFAULT_FXOSC_FREQUENCY                 40000000U

#define CLOCK_IP_MUX_DIVS_NO                             7U


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** XOSC - Register Layout Typedef */
typedef struct {
    uint32 CTRL;                        /**< XOSC Control Register, offset: 0x0 */
    const  uint32 STAT;                        /**< Oscillator Status Register, offset: 0x4 */
}volatile Clock_Ip_ExtOSCType;

typedef struct
{
    PLL_Type* PllInstance;
    uint8 DivsNo;

}Clock_Ip_PllType;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

extern Clock_Ip_ExtOSCType* const Clock_Ip_apxXosc[CLOCK_IP_XOSC_INSTANCES_ARRAY_SIZE];
extern Clock_Ip_PllType const Clock_Ip_apxPll[CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE];

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Clock start constant section data */
#define MCU_START_SEC_CONST_8
#include "Mcu_MemMap.h"

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_8
#include "Mcu_MemMap.h"

/* Clock start constant section data */
#define MCU_START_SEC_CONST_32
#include "Mcu_MemMap.h"

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_32
#include "Mcu_MemMap.h"



/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
void Clock_Ip_SpecificSetUserAccessAllowed(void);
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
void Clock_Ip_McMeEnterKey(void);

/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CLOCK_IP_SPECIFIC_H */

