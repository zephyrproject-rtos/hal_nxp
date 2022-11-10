/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SOC_IPS_H
#define SOC_IPS_H

/**
*   @file    Soc_Ips.h
*   @brief   Include platform types
*   @addtogroup BASENXP_COMPONENT
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform_Types.h"
#include "IpVersionMacros.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SOC_IPS_VENDOR_ID                    43
#define SOC_IPS_MODULE_ID                    0
#define SOC_IPS_AR_RELEASE_MAJOR_VERSION     4
#define SOC_IPS_AR_RELEASE_MINOR_VERSION     7
#define SOC_IPS_AR_RELEASE_REVISION_VERSION  0
#define SOC_IPS_SW_MAJOR_VERSION             0
#define SOC_IPS_SW_MINOR_VERSION             9
#define SOC_IPS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Platform_Types.h header file are of the same Autosar version */
    #if ((SOC_IPS_AR_RELEASE_MAJOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (SOC_IPS_AR_RELEASE_MINOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Soc_Ips.h and Platform_Types.h are different"
    #endif

    /* Check if source file and IpVersionMacros.h header file are of the same Autosar version */
    #if ((SOC_IPS_AR_RELEASE_MAJOR_VERSION != IPVERSIONMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (SOC_IPS_AR_RELEASE_MINOR_VERSION != IPVERSIONMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Soc_Ips.h and IpVersionMacros.h are different"
    #endif
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/
/* 31 = 0x1F = ARM_PLATFORM
 * 53 = 0x35 = S32Z27x DERIVATIVE ID
 * 01 = 0x01 = Rev. 1
 * 11 = 0x01 = Draft A      (A-B-C-D-E-F-G-H-I-J-K-L-M-N-O-P-Q-R-S-T-U-V-W-X-Y-Z)
*/

/**
* @brief PMC IP Version: PMC v03.00.01.00
* @details S32Z27XM33 IP Versions
*/
#define IPV_PMC                  (0x1F350101UL)


/**
* @brief PIT_RTI IP Version: PIT_RTI v05.00.06.11
* @details S32Z27XM33 IP Versions
*/
#define IPV_PIT              (0x1F350101UL)


/**
* @brief RTC IP Version: RTC 00.00.03.06
* @details S32Z27XM33 IP Versions
*/
#define IPV_RTC                (0x1F350101UL)


/**
* @brief ADCDIG IP Version: v00.00.18.00
* @details S32Z27XM33 IP Versions
*/
#define IPV_ADCDIG               (0x1F350101UL)


/**
* @brief SIUL2 IP Version: v00.00.00.10
* @details S32Z27XM33 IP Versions
*/
#define IPV_SIULV2               (0x1F350101UL)

/**
* @brief MC IP Version: D_IP_magic_carpet_SYN_302 [v07.00.02.03]
* @details S32Z27XM33 IP Versions
*/
#define IPV_MC                (0x1F350101UL)

/**
* @brief PLLDIG IP Version: DA_IP_PLL_SYS_C40ESF3_008 [v00.00.03.04]
* @details S32Z27XM33 IP Versions
*/
#define IPV_PLLDIG               (0x1F350101UL)

/**
* @brief FXOSC IP Version: DA_IP_FXOSC_C [v40.00.00.02.05]
* @details S32Z27XM33 IP Versions
*/
#define IPV_FXOSC               (0x1F350101UL)

/**
* @brief FIRC IP Version: D_IP_FIRC_SYN_SPEC [v00.00.00.21]
* @details S32Z27XM33 IP Versions
*/
#define IPV_FIRC                (0x1F350101UL)

/**
* @brief GMAC IP Version: D_IP_3P_ENET_MAC_SYN_017 [v02.00.00.08]
* @details S32Z27XM33 IP Versions
*/
#define IPV_GMAC                (0x1F350101UL)  

/**
* @brief C40ASF IP Version: M_IP_c40asf_spec [v00.00.00.04]
* @details S32Z27XM33 IP Versions
*/
#define IPV_C40ASF              (0x1F350101UL) 

/**
* @brief PFLASH IP Version: pflash_c40asf_s32k_spec [v00.00.00.11]
* @details S32Z27XM33 IP Versions
*/
#define IPV_PFLASH              (0x1F350101UL)

/**
* @brief C40ASF IP Version: M_IP_c40asf_spec [v00.00.00.04]
* @details S32Z27XM33 IP Versions
*/
#define IPV_FLASH_ARRAY         (0x1F350101UL) 

/**
* @brief PFLASH IP Version: pflash_c40asf_s32k_spec [v00.00.00.11]
* @details S32Z27XM33 IP Versions
*/
#define IPV_FLASH_CONTROLLER    (0x1F350101UL)  

/**
* @brief QSPI IP Version: QSPI d_ip_quadspi_v2_sync_spec.025
* @details S32Z27XM33 IP Versions
*/
#define IPV_QSPI                (0x1F350101UL)          

/**
* @brief Clock Monitoring Unit Frequency Check (CMU_FC) IP Version
* @details S32Z27XM33 IP Versions
*/
#define IPV_CMU_FC              (0x1F350101UL) 

/*==================================================================================================
*                              REGISTER PROTECTION (REG_PROT)
==================================================================================================*/
/**
* @brief Register Protection IP Version
* @details S32Z27XM33 IP Versions
*/
#define IPV_REG_PROT                  (0x1F350101UL)
 
/*==================================================================================================
*                              Software Erratas for Hardware Erratas
==================================================================================================*/
/**
* @brief Hardware errata for FMC: (e10716)
* @details e10716 RTC: Timer Alarm Flag can assert erroneously
*/
#define ERR_IPV_RTC_0001         (STD_ON)

/**
* @brief Hardware errata for LPSPI: (ERR050456)
* @details ERR050456 LPSPI: Reset to fifo does not work as expected
*/
#define ERR_IPV_LPSPIV2_0001         (STD_ON)

/**
* @brief Hardware errata for LINFlexD: (e007274)
* @details e007274 LINFlexD: Consecutive headers received by LIN Slave triggers the LIN FSM to an unexpected state.
*/
#define ERR_IPV_LINFLEXD_E007274    (STD_ON)

/**
* @brief Hardware errata for MC_RGM: (ERR051163)
* @details ERR051163 MC_RGM: Incorrect destructive reset event status
*/
#define ERR_IPV_MC_RGM_0001         (STD_ON)

/**
* @brief Hardware errata for EMIOS: (ERR009978)
* @details ERR009978 EMIOS: eMIOS: Unexpected channel flag assertion during GPIO to
MCB mode transition
*/
#define ERR_IPV_EMIOS_009978        (STD_ON)
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Enable CACHE management feature
* @details Global define to enable CACHE management at runtime
*/
#define MCAL_CACHE_RUNTIME_MNGMNT (STD_ON)

/**
* @brief number of EMIOS channels per each interrupt
* @details S32Z27XM33 Platform specific Defines/Configurations for EMIOS.
* Can be 1U, 2U, 4U, etc.. depending on the platform
*/
#define EMIOS_CHANNELS_PER_INTERRUPT (4U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/**
* @brief User Mode feature is enabled
* @details User Mode feature - MCAL is configured to run in supervisor mode, by default.
*/

#ifdef MCAL_ENABLE_SUPERVISOR_MODE
    #undef MCAL_ENABLE_USER_MODE_SUPPORT
#endif
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif


/** @} */

#endif /* SOC_IPS_H */
