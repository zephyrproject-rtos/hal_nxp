/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef REG_ESYS_H
#define REG_ESYS_H

/**
*   @file
*
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


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define REG_ESYS_VENDOR_ID                    43
#define REG_ESYS_MODULE_ID                    0
#define REG_ESYS_AR_RELEASE_MAJOR_VERSION     4
#define REG_ESYS_AR_RELEASE_MINOR_VERSION     7
#define REG_ESYS_AR_RELEASE_REVISION_VERSION  0
#define REG_ESYS_SW_MAJOR_VERSION             2
#define REG_ESYS_SW_MINOR_VERSION             0
#define REG_ESYS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                   REGISTER PROTECTION (REG_PROT)                                  
==================================================================================================*/
/**
* @brief Macros defined for the IPVs that are protected.
*/

#define MCAL_AXBS_REG_PROT_AVAILABLE              (STD_OFF)
#define MCAL_XBIC_REG_PROT_AVAILABLE              (STD_OFF)
#define MCAL_DMA_REG_PROT_AVAILABLE               (STD_OFF)
#define MCAL_DMAMUX_REG_PROT_AVAILABLE            (STD_OFF)
#define MCAL_CRC_REG_PROT_AVAILABLE               (STD_OFF)
#define MCAL_SIUL2_REG_PROT_AVAILABLE             (STD_OFF)
#define MCAL_STM_REG_PROT_AVAILABLE               (STD_OFF)
#define MCAL_PRAMC_REG_PROT_AVAILABLE             (STD_OFF)
#define MCAL_PFLASH_REG_PROT_AVAILABLE            (STD_OFF)
#define MCAL_C40ASF_REG_PROT_AVAILABLE            (STD_OFF)
#define MCAL_DCM_REG_PROT_AVAILABLE               (STD_OFF)
#define MCAL_CMU_REG_PROT_AVAILABLE               (STD_OFF)
#define MCAL_FXOSC_REG_PROT_AVAILABLE             (STD_OFF)
#define MCAL_MC_RGM_REG_PROT_AVAILABLE            (STD_OFF)
#define MCAL_MC_CGM_REG_PROT_AVAILABLE            (STD_OFF)
#define MCAL_MC_ME_REG_PROT_AVAILABLE             (STD_OFF)
#define MCAL_PLLDIG_REG_PROT_AVAILABLE            (STD_OFF)
#define MCAL_PMC_REG_PROT_AVAILABLE               (STD_OFF)
#define MCAL_FTM_REG_PROT_AVAILABLE               (STD_OFF)
#define MCAL_SRTC_REG_PROT_AVAILABLE              (STD_ON)

/**
* @brief Macros defined for the protection size
*/
#define SRTC_PROT_MEM_U32                          ((uint32)0x00000004UL)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif


/** @} */

#endif /* REG_ESYS_H */
