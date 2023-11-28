/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef TRGMUX_IP_DEVASSERT_H_
#define TRGMUX_IP_DEVASSERT_H_

/**
*   @file    Trgmux_Ip_Devassert.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Trgmux Ip driver header file.
*   @details
*
*   @addtogroup TRGMUX_IP_DRIVER TRGMUX IP Driver
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
#include "Trgmux_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_DEVASSERT_VENDOR_ID                    43
#define TRGMUX_IP_DEVASSERT_MODULE_ID                    255
#define TRGMUX_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION     4
#define TRGMUX_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION     7
#define TRGMUX_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION  0
#define TRGMUX_IP_DEVASSERT_SW_MAJOR_VERSION             3
#define TRGMUX_IP_DEVASSERT_SW_MINOR_VERSION             0
#define TRGMUX_IP_DEVASSERT_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Trgmux_Ip_Types.h file are of the same vendor */
#if (TRGMUX_IP_DEVASSERT_VENDOR_ID != TRGMUX_IP_TYPES_VENDOR_ID)
    #error "Trgmux_Ip_Devassert.h and Trgmux_Ip_Types.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip_Types.h file are of the same Autosar version */
#if ((TRGMUX_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_Devassert.h and Trgmux_Ip_Types.h are different"
#endif

/* Check if header file and Trgmux_Ip_Types.h file are of the same Software version */
#if ((TRGMUX_IP_DEVASSERT_SW_MAJOR_VERSION != TRGMUX_IP_TYPES_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_DEVASSERT_SW_MINOR_VERSION != TRGMUX_IP_TYPES_SW_MINOR_VERSION) || \
     (TRGMUX_IP_DEVASSERT_SW_PATCH_VERSION != TRGMUX_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_Devassert.h and Trgmux_Ip_Types.h are different"
#endif

#if (STD_ON == TRGMUX_IP_IS_AVAILABLE)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

#if (STD_ON == TRGMUX_IP_DEV_ERROR_DETECT)
    /* Implement default assert macro */
    static inline void Trgmux_Ip_DevAssert(volatile boolean x)
    {
        if(x) { } else { ASM_KEYWORD("BKPT #0"); for(;;) {} }
    }
    #define TRGMUX_IP_DEV_ASSERT(x) Trgmux_Ip_DevAssert(x)
#else
    /* Assert macro does nothing */
    #define TRGMUX_IP_DEV_ASSERT(x) ((void)0)
#endif /* STD_ON == TRGMUX_IP_DEV_ERROR_DETECT */

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* TRGMUX_IP_IS_AVAILABLE */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef TRGMUX_IP_DEVASSERT_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
