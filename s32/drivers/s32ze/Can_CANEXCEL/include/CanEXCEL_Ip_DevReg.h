/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
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

#define CANXL_IP_FILTER_BANK_SIZE (0x798U)

#define CANXL_IP_MRU_MAILBOX_NO (4U)

#define IP_CANXL_TBS_BASE_PTRS { IP_CANXL_0_TBS, IP_CANXL_1_TBS }

#define CANXL_IP_HAS_ABORT (STD_OFF)

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
#define CANEXCEL_IP_SYSS_CLEAR_DEFAULT_VALUE_U32           ((uint32)0xFFFF0F03U)
/**
* @brief Clear Mask for Default value for the CH1_MBSTAT register for CANEXCEL MRU
*/
#define CANEXCEL_IP_CH1_MBSTAT_CLEAR_DEFAULT_VALUE_U32       ((uint32)0x0000F000U)

/** @} */

#endif /* CANEXCEL_IP_DEVREG_H_ */
