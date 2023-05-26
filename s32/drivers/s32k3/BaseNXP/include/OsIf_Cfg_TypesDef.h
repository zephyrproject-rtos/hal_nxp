/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef OSIF_CFG_TYPESDEF_H
#define OSIF_CFG_TYPESDEF_H

/**
*   @file       OsIf_Cfg_TypesDef.h
*   @version 3.0.0
*
*
*   @addtogroup osif_drv
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
#include "OsIf_Cfg.h"

#if STD_ON == OSIF_DEV_ERROR_DETECT
#if defined(USING_OS_AUTOSAROS)
#include "Det.h"
#endif /* defined(USING_OS_AUTOSAROS) */
#include "Devassert.h"
#define OSIF_DEV_ASSERT(x) DevAssert(x)
#else
#define OSIF_DEV_ASSERT(x) (void)(x)
#endif /* STD_ON == OSIF_DEV_ERROR_DETECT */

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_CFG_TYPESDEF_VENDOR_ID                    43
#define OSIF_CFG_TYPESDEF_AR_RELEASE_MAJOR_VERSION     4
#define OSIF_CFG_TYPESDEF_AR_RELEASE_MINOR_VERSION     7
#define OSIF_CFG_TYPESDEF_AR_RELEASE_REVISION_VERSION  0
#define OSIF_CFG_TYPESDEF_SW_MAJOR_VERSION             3
#define OSIF_CFG_TYPESDEF_SW_MINOR_VERSION             0
#define OSIF_CFG_TYPESDEF_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against OsIf_Cfg.h */
#if (OSIF_CFG_TYPESDEF_VENDOR_ID != OSIF_CFG_VENDOR_ID)
    #error "OsIf_Cfg_TypesDef.h and OsIf_Cfg.h have different vendor ids"
#endif
#if ((OSIF_CFG_TYPESDEF_AR_RELEASE_MAJOR_VERSION    != OSIF_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_CFG_TYPESDEF_AR_RELEASE_MINOR_VERSION    != OSIF_CFG_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_CFG_TYPESDEF_AR_RELEASE_REVISION_VERSION != OSIF_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Cfg_TypesDef.h and OsIf_Cfg.h are different"
#endif
#if ((OSIF_CFG_TYPESDEF_SW_MAJOR_VERSION != OSIF_CFG_SW_MAJOR_VERSION) || \
     (OSIF_CFG_TYPESDEF_SW_MINOR_VERSION != OSIF_CFG_SW_MINOR_VERSION) || \
     (OSIF_CFG_TYPESDEF_SW_PATCH_VERSION != OSIF_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Cfg_TypesDef.h and OsIf_Cfg.h are different"
#endif

/* Checks against StandardTypes.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((OSIF_CFG_TYPESDEF_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (OSIF_CFG_TYPESDEF_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of OsIf_Cfg_TypesDef.h and StandardTypes.h are different"
    #endif
#endif

#if STD_ON == OSIF_DEV_ERROR_DETECT
#if defined(USING_OS_AUTOSAROS)
/* Checks against Det.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((OSIF_CFG_TYPESDEF_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
         (OSIF_CFG_TYPESDEF_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of OsIf_Cfg_TypesDef.h and Det.h are different"
    #endif
#endif
#endif /* defined(USING_OS_AUTOSAROS) */

/* Checks against Devassert.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((OSIF_CFG_TYPESDEF_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (OSIF_CFG_TYPESDEF_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of OsIf_Cfg_TypesDef.h and Devassert.h are different"
    #endif
#endif
#endif /* STD_ON == OSIF_DEV_ERROR_DETECT */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* OSIF Service IDs */
#define OSIF_SID_INIT                    (0x01U)
#define OSIF_SID_GETCOUNTER              (0x02U)
#define OSIF_SID_GETELAPSED              (0x03U)
#define OSIF_SID_SETTIMERFREQ            (0x04U)
#define OSIF_SID_US2TICKS                (0x05U)

/* OSIF DET Error Codes */                    
#define OSIF_E_UNINIT                    (0x01U)
#define OSIF_E_INV_API                   (0x02U)
#define OSIF_E_INV_CORE_IDX              (0x03U)
#define OSIF_E_INIT_FAILED               (0x04U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct 
{
    uint32 counterId;
    uint32 counterFrequency;
} OsIf_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif /* __cplusplus */
  
/** @} */

#endif /* OSIF_CFG_TYPESDEF_H */
