/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*
 * CanEXCEL_Ip_DevReg.h
 *
 *  Created on: May 4, 2022
 *      Author: nxf31634
 */

#ifndef CANEXCEL_IP_DEVREG_H_
#define CANEXCEL_IP_DEVREG_H_

/**
*   @file CanEXCEL_Ip_DevReg.h
*
*   @addtogroup CanEXCEL
*   @{
*/

#include "CanEXCEL_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANEXCEL_IP_DEVREG_VENDOR_ID_H                      43
#define CANEXCEL_IP_DEVREG_AR_RELEASE_MINOR_VERSION_H       9
#define CANEXCEL_IP_DEVREG_AR_RELEASE_MAJOR_VERSION_H   4
#define CANEXCEL_IP_DEVREG_AR_RELEASE_REVISION_VERSION_H    0
#define CANEXCEL_IP_DEVREG_SW_MAJOR_VERSION_H               0
#define CANEXCEL_IP_DEVREG_SW_MINOR_VERSION_H               8
#define CANEXCEL_IP_DEVREG_SW_PATCH_VERSION_H               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanEXCEL_Ip_CfgDefines.h are of the same vendor */
#if (CANEXCEL_IP_DEVREG_VENDOR_ID_H != CANEXCEL_IP_CFGDEFINES_VENDOR_ID_H)
    #error "CanEXCEL_Ip_DevReg.h and CanEXCEL_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and CCanEXCEL_Ip_CfgDefines.h are of the same Autosar version */
#if ((CANEXCEL_IP_DEVREG_AR_RELEASE_MAJOR_VERSION_H    != CANEXCEL_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_DEVREG_AR_RELEASE_MINOR_VERSION_H    != CANEXCEL_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION_H) || \
     (CANEXCEL_IP_DEVREG_AR_RELEASE_REVISION_VERSION_H != CANEXCEL_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION_H) \
)
    #error "AutoSar Version Numbers of CanEXCEL_Ip_DevReg.h and CanEXCEL_Ip_CfgDefines.h are different"
#endif
/* Check if current file and CanEXCEL_Ip_CfgDefines.h are of the same Software version */
#if ((CANEXCEL_IP_DEVREG_SW_MAJOR_VERSION_H != CANEXCEL_IP_CFGDEFINES_SW_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_DEVREG_SW_MINOR_VERSION_H != CANEXCEL_IP_CFGDEFINES_SW_MINOR_VERSION_H) || \
     (CANEXCEL_IP_DEVREG_SW_PATCH_VERSION_H != CANEXCEL_IP_CFGDEFINES_SW_PATCH_VERSION_H) \
)
    #error "Software Version Numbers of CanEXCEL_Ip_DevReg.h and CanEXCEL_Ip_CfgDefines.h are different"
#endif

#define CANXL_IP_FILTER_BANK_SIZE (0x798U)

#define CANXL_IP_MRU_MAILBOX_NO (4U)

#define CANXL_IP_HAS_ABORT (STD_ON)

#define IP_CANXL_TBS_BASE_PTRS { IP_GPR_0 }

#define CANXL_IP_TBS_SELECTOR GPR_RWF_6

#define CAN_TBS_Type K566_GPR0_Type

#define CAN_TBS_CAN_TS_SEL_TS_SEL(x) (K566_GPR0_GPR_RWF_6_TS_EN(1u) | K566_GPR0_GPR_RWF_6_TS_SEL(x))

/**
* @brief Default value for the BCFG2 register
*/
#define CANEXCEL_IP_BCFG2_DEFAULT_VALUE_U32               ((uint32)0x20000000U)
/**
* @brief Default value for the BNCBT register
*/
#define CANEXCEL_IP_BNCBT_DEFAULT_VALUE_U32               ((uint32)0x03C0F03EU)
/**
* @brief Default value for the BFDCBT register
*/
#define CANEXCEL_IP_BFDCBT_DEFAULT_VALUE_U32               ((uint32)0x00C0300EU)
/**
* @brief Default value for the BXDCBT register
*/
#define CANEXCEL_IP_BXDCBT_DEFAULT_VALUE_U32               ((uint32)0x00C0300EU)
/**
* @brief Clear Mask for Default value for the SYSS register
*/
#define CANEXCEL_IP_SYSS_CLEAR_DEFAULT_VALUE_U32           ((uint32)0xFFFF0F02U)
/**
* @brief Clear Mask for Default value for the CH1_MBSTAT register for CANEXCEL MRU
*/
#define CANEXCEL_IP_CH1_MBSTAT_CLEAR_DEFAULT_VALUE_U32       ((uint32)0x0000F000U)
/** @} */

#endif /* CANEXCEL_IP_DEVREG_H_ */
