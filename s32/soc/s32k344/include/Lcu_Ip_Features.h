/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef S32K3XX_LCU_IP_FEATURES_H_
#define S32K3XX_LCU_IP_FEATURES_H_

/**
*   @file    Lcu_Ip_Features.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - LCU IP driver header file.
*   @details
*
*   @addtogroup LCU_IP_DRIVER LCU IP Driver
*   @{
*/

#include "Mcal.h"
#include "S32K344_LCU.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_FEATURES_VENDOR_ID                       43
#define LCU_IP_FEATURES_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_FEATURES_AR_RELEASE_MINOR_VERSION        7
#define LCU_IP_FEATURES_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_FEATURES_SW_MAJOR_VERSION                3
#define LCU_IP_FEATURES_SW_MINOR_VERSION                0
#define LCU_IP_FEATURES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Mcal header file are of the same Autosar version */
#if ((LCU_IP_FEATURES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_FEATURES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lcu_Ip_Features.h and Mcal.h are different"
#endif
#endif


/*==================================================================================================
                                            DEFINES
==================================================================================================*/

/** Number of input/output per LC */
#define LCU_NUM_INPUT_PER_LC                        4U
#define LCU_NUM_OUTPUT_PER_LC                       4U

/*-------------------------------------------------------------------/
/                       INSTANCE RESET VALUE                         /
/-------------------------------------------------------------------*/
#define FORCE_FILTER_RESET_VALUE                    ((uint8)(0U))
#define FORCE_POLARITY_RESET_VALUE                  ((uint8)(0U))
#define COMBEN_RESET_VALUE                          ((uint8)(0U))
#define SW_SYNC_SEL_RESET_VALUE                     ((uint8)(0U))

/*-------------------------------------------------------------------/
/                   LUT AND FORCE MASK FOR INTERRUPT                 /
/-------------------------------------------------------------------*/
#define LUT_STS_EVENT_MASK                          ((uint32)(0x01U))
#define FORCE_STS_EVENT_MASK                        ((uint32)(0x0100U))
#define LUT_INT_ENABLE_MASK                         ((uint32)(0x01U))
#define FORCE_INT_ENABLE_MASK                       ((uint32)(0x10000U))
/** @} */

#endif  /* #ifndef S32K3XX_LCU_IP_FEATURES_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
