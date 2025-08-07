/**
*   @file    hse_target.h
*

*   @brief   HSE Target options.
*   @details This file contains macros used for target options.
*
*   @addtogroup hse_target HSE Targets
*   @{
*/
/*==================================================================================================
*
*   Platform             : HSE_S32ZE
*   FW Type              : STANDARD
*   SW Version           : 2.37.0
*
*   Copyright 2019-2024 NXP
*
*   Redistribution and use in source and binary forms, with or without modification,
*   are permitted provided that the following conditions are met:
*
*   1. Redistributions of source code must retain the above copyright notice, this list
*      of conditions and the following disclaimer.
*
*   2. Redistributions in binary form must reproduce the above copyright notice, this
*      list of conditions and the following disclaimer in the documentation and/or
*      other materials provided with the distribution.
*
*   3. Neither the name of the copyright holder nor the names of its
*      contributors may be used to endorse or promote products derived from this
*      software without specific prior written permission.
*
*   This software is owned or controlled by NXP and may only be used strictly in accordance with
*   the applicable license terms. By expressly accepting such terms or by downloading, installing,
*   activating and/or otherwise using the software, you are agreeing that you have read, and that
*   you agree to comply with and are bound by, such license terms. If you do not agree to
*   be bound by the applicable license terms, then you may not retain, install, activate or
*   otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef TARGET_H
#define TARGET_H


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           hse_target.h
*/
#include "hse_compile_defs.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* ***********************************************
* Define HSE FW type
**************************************************/
#define HSE_STANDARD_FW 0

/* ***********************************************
* Define current configuration
**************************************************/
#define HSE_PLATFORM       HSE_S32ZE              /**< @brief  HSE Platform. */
#define HSE_FWTYPE         HSE_STANDARD_FW         /**< @brief  HSE FW Type. */

/** @brief    HSE Firmware Version */
#define HSE_FW_VERSION { \
    0U,     /* reserved */ \
    30U,     /* socTypeId */ \
    0U,     /* fwTypeId */ \
    2U,     /* majorVersion */ \
    37U,     /* minorVersion */ \
    0U      /* patchVersion */ \
}

/** @brief    HSE Firmware Build Information */
#define HSE_FW_BUILD_INFO { \
    0x7334ca80eb18d330ULL,     /* build unique identifier*/ \
    20240531UL,                   /* build date */ \
    82312UL                    /* build time */  \
}

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* TARGET_H */

/** @} */
