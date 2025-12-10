/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file           CompilerDefinition.h
*   @version 0.8.0
*
*   @brief   AUTOSAR BaseNXP - SWS Compiler abstraction
*   @details The file Compiler.h provides macros for the encapsulation of definitions and
*            declarations.
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup BASENXP_COMPONENT
*   @{
*/

#ifndef COMPILERDEFINITION_H
#define COMPILERDEFINITION_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the compiler abstraction header file and also in
          the module's description file.
@{
*/
#define COMPILERDEFINITION_VENDOR_ID                      43
#define COMPILERDEFINITION_AR_RELEASE_MAJOR_VERSION       4
#define COMPILERDEFINITION_AR_RELEASE_MINOR_VERSION       9
#define COMPILERDEFINITION_AR_RELEASE_REVISION_VERSION    0
#define COMPILERDEFINITION_SW_MAJOR_VERSION               0
#define COMPILERDEFINITION_SW_MINOR_VERSION               8
#define COMPILERDEFINITION_SW_PATCH_VERSION               0
/**@}*/
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef __ghs__
    /**
    * @brief Symbol required to be defined when GreenHills compiler is used.
    */
    #define _GREENHILLS_C_S32K5XX_
#endif
#ifdef __DCC__
    /**
    * @brief Symbol required to be defined when Diab compiler is used.
    */
    #define _DIABDATA_C_S32K5XX_
#endif
#ifdef __MWERKS__
    /**
    * @brief Symbol required to be defined when Codewarrior compiler is used.
    */
    #define _CODEWARRIOR_C_S32K5XX_
#endif
#if (defined(__GNUC__) && !defined(__DCC__) && !defined(__CC_ARM) && !defined(__ARMCC_VERSION) && !defined(__clang__))
         /**
        * @brief Symbol required to be defined when GCC ARM compiler is used.
        */
        #define _GCC_C_S32K5XX_
 #endif
#ifdef __CC_ARM
        /**
        * @brief Symbol required to be defined when DS5 ARM compiler is used.
        */
        #define _ARM_DS5_C_S32K5XX_
#endif
#ifdef __ICCARM__
        /**
        * @brief Symbol required to be defined when IAR compiler is used.
        */
        #define _IAR_C_S32K5XX_
#endif
#ifdef __ARMCC_VERSION
    #if __ARMCC_VERSION >= 60000
         /**
        * @brief Symbol required to be defined when ARM-DS6 compiler is used.
        */
        #define _ARM_DS6_S32K5XX_
    #endif
#endif

#ifdef __clang__
    #ifdef __riscv
         /**
        * @brief Symbol required to be defined when ZEN-V compiler is used.
        */
        #define _ZEN_V_S32K5XX_
    #endif
#endif

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

#endif /* #ifndef COMPILERDEFINITION_H */

/** @} */
