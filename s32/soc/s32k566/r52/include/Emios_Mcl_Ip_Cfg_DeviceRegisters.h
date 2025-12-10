/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_MCL_IP_CFG_DEVICEREGISTERS_H
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "S32K566_EMIOS.h"
#include "S32K566_K566_GPR1.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_VENDOR_ID                       43
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION        9
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION                0
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION                8
#define EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define EMIOS_MCL_IP_GPT_SUPPORT_EMIOS          STD_ON
#define EMIOS_MCL_IP_PWM_SUPPORT_EMIOS          STD_ON
#define EMIOS_MCL_IP_ICU_SUPPORT_EMIOS          STD_ON
#define EMIOS_MCL_IP_OCU_SUPPORT_EMIOS          STD_ON

#ifdef __cplusplus
}
#endif

#endif /* EMIOS_MCL_IP_CFG_DEVICEREGISTERS_H */

