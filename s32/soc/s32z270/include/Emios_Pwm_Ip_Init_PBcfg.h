/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_PWM_IP_INIT_PBCFG_H
#define EMIOS_PWM_IP_INIT_PBCFG_H

/**
*   @file       Emios_Pwm_Ip_Init_PBcfg.h
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
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
#include <zephyr/devicetree.h>

#include "Emios_Pwm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_INIT_PB_CFG_VENDOR_ID                       43
#define EMIOS_PWM_IP_INIT_PB_CFG_MODULE_ID                       121
#define EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_PWM_IP_INIT_PB_CFG_SW_MAJOR_VERSION                2
#define EMIOS_PWM_IP_INIT_PB_CFG_SW_MINOR_VERSION                0
#define EMIOS_PWM_IP_INIT_PB_CFG_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Emios_Pwm_Ip_Types header file are of the same vendor */
#if (EMIOS_PWM_IP_INIT_PB_CFG_VENDOR_ID != EMIOS_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_Init_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Types header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_Init_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Types header file are of the same software version */
#if ((EMIOS_PWM_IP_INIT_PB_CFG_SW_MAJOR_VERSION != EMIOS_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_SW_MINOR_VERSION != EMIOS_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_SW_PATCH_VERSION != EMIOS_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_Init_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

#define DT_DRV_COMPAT                     nxp_s32_emios_pwm

#define EMIOS_OPWFMB_MODE_USED(node_id)                                                    \
            COND_CODE_1(DT_NODE_HAS_PROP(node_id, pwm_mode),                               \
                       (DT_ENUM_HAS_VALUE(node_id, pwm_mode, opwfmb)),                     \
                       (0)) ||

#define IS_EMIOS_OPWFMB_MODE_USED(n)                                                       \
            DT_INST_FOREACH_CHILD_STATUS_OKAY(n, EMIOS_OPWFMB_MODE_USED)

#define EMIOS_OPWMB_MODE_USED(node_id)                                                     \
            COND_CODE_1(DT_NODE_HAS_PROP(node_id, pwm_mode),                               \
                       (DT_ENUM_HAS_VALUE(node_id, pwm_mode, opwmb)),                      \
                       (0)) ||

#define IS_EMIOS_OPWMB_MODE_USED(n)                                                        \
            DT_INST_FOREACH_CHILD_STATUS_OKAY(n, EMIOS_OPWMB_MODE_USED)

#define EMIOS_OPWMCB_MODE_USED(node_id)                                                    \
            COND_CODE_1(DT_NODE_HAS_PROP(node_id, pwm_mode),                               \
                       (DT_ENUM_HAS_VALUE(node_id, pwm_mode, opwmcb_trail_edge) ||         \
                        DT_ENUM_HAS_VALUE(node_id, pwm_mode, opwmcb_lead_edge)             \
                        ),(0)) ||

#define IS_EMIOS_OPWMCB_MODE_USED(n)                                                       \
            DT_INST_FOREACH_CHILD_STATUS_OKAY(n, EMIOS_OPWMCB_MODE_USED)
/* Macro to enable the mode operations. */
#if DT_INST_FOREACH_STATUS_OKAY(IS_EMIOS_OPWFMB_MODE_USED) 0
#define EMIOS_PWM_IP_MODE_OPWFMB_USED
#endif

#if DT_INST_FOREACH_STATUS_OKAY(IS_EMIOS_OPWMB_MODE_USED) 0
#define EMIOS_PWM_IP_MODE_OPWMB_USED
#endif

#if DT_INST_FOREACH_STATUS_OKAY(IS_EMIOS_OPWMCB_MODE_USED) 0
#define EMIOS_PWM_IP_MODE_OPWMCB_USED
#endif

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


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_PWM_IP_INIT_PBCFG_H */

