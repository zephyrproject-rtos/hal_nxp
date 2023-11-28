/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/* Prevention from multiple including the same header */
#ifndef TRGMUX_IP_TRUSTEDFUNCTIONS_H
#define TRGMUX_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Trgmux_Ip_TrustedFunctions.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Trgmux Ip driver source file.
*   @details
*
*   @addtogroup TRGMUX_IP_DRIVER TRGMUX IP Driver
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

#include "Trgmux_Ip_Types.h"
#include "Trgmux_Ip_Cfg_Defines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define TRGMUX_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                3
#define TRGMUX_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define TRGMUX_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (STD_ON == TRGMUX_IP_IS_AVAILABLE)

/* Check if Trgmux_Ip_TrustedFunctions.h file and Trgmux_Ip_Types file are of the same vendor */
#if (TRGMUX_IP_TRUSTEDFUNCTIONS_VENDOR_ID != TRGMUX_IP_TYPES_VENDOR_ID)
    #error "Trgmux_Ip_TrustedFunctions.h and Trgmux_Ip_Types have different vendor ids"
#endif

/* Check if Trgmux_Ip_TrustedFunctions.h file and Trgmux_Ip_Types file are of the same Autosar version */
#if ((TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_TrustedFunctions.h and Trgmux_Ip_Types are different"
#endif

/* Check if Trgmux_Ip_TrustedFunctions.h file and Trgmux_Ip_Types file are of the same Software version */
#if ((TRGMUX_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != TRGMUX_IP_TYPES_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != TRGMUX_IP_TYPES_SW_MINOR_VERSION) || \
     (TRGMUX_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != TRGMUX_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_TrustedFunctions.h and Trgmux_Ip_Types are different"
#endif

/* Check if Trgmux_Ip_TrustedFunctions.h file and Trgmux_Ip_Cfg_Defines file are of the same vendor */
#if (TRGMUX_IP_TRUSTEDFUNCTIONS_VENDOR_ID != TRGMUX_IP_CFG_DEFINES_VENDOR_ID)
    #error "Trgmux_Ip_TrustedFunctions.h and Trgmux_Ip_Cfg_Defines have different vendor ids"
#endif


/* Check if Trgmux_Ip_TrustedFunctions.h file and Trgmux_Ip_Cfg_Defines file are of the same Autosar version */
#if ((TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_TrustedFunctions.h and Trgmux_Ip_Cfg_Defines are different"
#endif

/* Check if Trgmux_Ip_TrustedFunctions.h file and Trgmux_Ip_Cfg_Defines file are of the same Software version */
#if ((TRGMUX_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != TRGMUX_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != TRGMUX_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (TRGMUX_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != TRGMUX_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_TrustedFunctions.h and Trgmux_Ip_Cfg_Defines are different"
#endif

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

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#if (defined(MCAL_ENABLE_USER_MODE_SUPPORT) && (STD_ON == TRGMUX_IP_USER_MODE_SUPPORT_IS_AVAILABLE))

#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

/**
 * @brief        Initialize the Trgmux
 *
 * @param[in]    pxTrgmuxInit     Pointer to the initialization structure.
 * @return       None
 *
 */
extern Trgmux_Ip_StatusType hwAcc_Init(TRGMUX_Type * const pTrgmux);

/**
 * @brief        Mapping the Input for the Output
 *
 * @param[in]    pxTrgmuxInit     Pointer to the initialization structure.
 * @param[in]    Input            Specifies the Input.
 * @param[in]    Output           Specifies the Output
 * @return       None
 *
 */
extern void hwAcc_SetInputForOutput(TRGMUX_Type * const pTrgmux, uint8 Instance, const uint32 Input, const uint32 Output);

/**
 * @brief        Lock the Output
 *
 * @param[in]    pxTrgmuxInit     Pointer to the initialization structure.
 * @param[in]    Output           Specifies the Output
 * @return       None
 *
 */
extern void hwAcc_SetLockForOutput(TRGMUX_Type * const pTrgmux, const uint32 Output);

/**
 * @brief        Get Lock status for the Output
 *
 * @param[in]    pxTrgmuxInit     Pointer to the initialization structure.
 * @param[in]    Output           Specifies the Output
 * @return       None
 *
 */
extern boolean hwAcc_GetLockForOutput(const TRGMUX_Type * const pTrgmux, const uint32 Output);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"


#endif /* TRGMUX_IP_USER_MODE_SUPPORT_IS_AVAILABLE == STD_ON */

#endif /* STD_ON == TRGMUX_IP_IS_AVAILABLE */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* TRGMUX_IP_TRUSTEDFUNCTIONS_H */


/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
