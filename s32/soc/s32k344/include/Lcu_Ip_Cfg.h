/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/* Prevention from multiple including the same header */
#ifndef LCU_IP_CFG_H_
#define LCU_IP_CFG_H_


/*******************************************************************************
 * Included files
 ******************************************************************************/

#include "Lcu_Ip_Init_PBcfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_CFG_VENDOR_ID                       43
#define LCU_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_CFG_AR_RELEASE_MINOR_VERSION        7
#define LCU_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_CFG_SW_MAJOR_VERSION                3
#define LCU_IP_CFG_SW_MINOR_VERSION                0
#define LCU_IP_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Lcu_Ip_Init_PBcfg.h file are of the same vendor */
#if (LCU_IP_CFG_VENDOR_ID != LCU_IP_INIT_PBCFG_VENDOR_ID)
    #error "Lcu_Ip_Cfg.h and Lcu_Ip_Init_PBcfg.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Init_PBcfg.h file are of the same Autosar version */
#if ((LCU_IP_CFG_AR_RELEASE_MAJOR_VERSION != LCU_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_CFG_AR_RELEASE_MINOR_VERSION != LCU_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_CFG_AR_RELEASE_REVISION_VERSION != LCU_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Cfg.h and Lcu_Ip_Init_PBcfg.h are different"
#endif

/* Check if header file and Lcu_Ip_INIT_PBcfg.h file are of the same Software version */
#if ((LCU_IP_CFG_SW_MAJOR_VERSION != LCU_IP_INIT_PBCFG_SW_MAJOR_VERSION) || \
     (LCU_IP_CFG_SW_MINOR_VERSION != LCU_IP_INIT_PBCFG_SW_MINOR_VERSION) || \
     (LCU_IP_CFG_SW_PATCH_VERSION != LCU_IP_INIT_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Cfg.h and Lcu_Ip_Init_PBcfg.h are different"
#endif

/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/

/* Number Of Configured Logic Instances */
#define LCU_IP_NOF_CFG_LOGIC_INSTANCES    ((uint32)1U)

/* Logic Instance 0 */
#define LCU_LOGIC_INSTANCE_0              ((uint32)0U)


/* Number Of Configured Logic Inputs */
#define LCU_IP_NOF_CFG_LOGIC_INPUTS       ((uint32)4U)

/* Logic Instance 0 */
#define LCU_LOGIC_INPUT_0                 ((uint32)0U)

/* Logic Instance 1 */
#define LCU_LOGIC_INPUT_1                 ((uint32)1U)

/* Logic Instance 2 */
#define LCU_LOGIC_INPUT_2                 ((uint32)2U)

/* Logic Instance 3 */
#define LCU_LOGIC_INPUT_3                 ((uint32)3U)


/* Number Of Configured Logic Outputs */
#define LCU_IP_NOF_CFG_LOGIC_OUTPUTS      ((uint32)4U)

/* Logic Instance 0 */
#define LCU_LOGIC_OUTPUT_0                ((uint32)0U)

/* Logic Instance 1 */
#define LCU_LOGIC_OUTPUT_1                ((uint32)1U)

/* Logic Instance 2 */
#define LCU_LOGIC_OUTPUT_2                ((uint32)2U)

/* Logic Instance 3 */
#define LCU_LOGIC_OUTPUT_3                ((uint32)3U)

#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"
extern const Lcu_Ip_InitType Lcu_Ip_xLcuInitPB;
/* LCU Input De-Initialization Structure */
extern const Lcu_Ip_LogicInputConfigType Lcu_Ip_xLogicInputResetConfig;

/* LCU Output De-Initialization Structure */
extern const Lcu_Ip_LogicOutputConfigType Lcu_Ip_xLogicOutputResetConfig;

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

#define MCL_START_SEC_CODE
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

void Lcu0_Ip_IRQHandler(void);

void Lcu1_Ip_IRQHandler(void);

#define MCL_STOP_SEC_CODE
/* @violates @ref Mcl_Lcu_h_REF_1 MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once. */
#include "Mcl_MemMap.h"

#endif  /* #ifndef LCU_IP_CFG_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
