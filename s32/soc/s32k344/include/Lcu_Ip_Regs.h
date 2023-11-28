/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef LCU_IP_TYPES_SOC_H_
#define LCU_IP_TYPES_SOC_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**
*   @file    Lcu_Ip_Regs.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - LCU IP driver header file.
*   @details
*
*   @addtogroup LCU_IP_DRIVER LCU IP Driver
*   @{
*/

#include "Lcu_Ip_Features.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_REGS_VENDOR_ID                       43
#define LCU_IP_REGS_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_REGS_AR_RELEASE_MINOR_VERSION        7
#define LCU_IP_REGS_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_REGS_SW_MAJOR_VERSION                3
#define LCU_IP_REGS_SW_MINOR_VERSION                0
#define LCU_IP_REGS_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Lcu_Ip_Features.h file are of the same vendor */
#if (LCU_IP_REGS_VENDOR_ID != LCU_IP_FEATURES_VENDOR_ID)
    #error "Lcu_Ip_Regs.h and Lcu_Ip_Features.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Features.h file are of the same Autosar version */
#if ((LCU_IP_REGS_AR_RELEASE_MAJOR_VERSION != LCU_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_REGS_AR_RELEASE_MINOR_VERSION != LCU_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_REGS_AR_RELEASE_REVISION_VERSION != LCU_IP_FEATURES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Regs.h and Lcu_Ip_Features.h are different"
#endif

/* Check if header file and Lcu_Ip_Features.h file are of the same Software version */
#if ((LCU_IP_REGS_SW_MAJOR_VERSION != LCU_IP_FEATURES_SW_MAJOR_VERSION) || \
     (LCU_IP_REGS_SW_MINOR_VERSION != LCU_IP_FEATURES_SW_MINOR_VERSION) || \
     (LCU_IP_REGS_SW_PATCH_VERSION != LCU_IP_FEATURES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Regs.h and Lcu_Ip_Features.h are different"
#endif


/*==================================================================================================
                                        LCU STRUCTURE
==================================================================================================*/

/*! @} */

#define LCU_FCTRL_FORCE_SENSE_COMMON_MASK           (0xFU)
#define LCU_FCTRL_FORCE_MODE_COMMON_MASK            (0x30U)
#define LCU_FCTRL_SYNC_SEL_COMMON_MASK              (0xC0U)

/*! @name FCTRL */
/*! @{ */
#define LCU_FCTRL_FORCE_SENSE_MASK(ID)              ((uint32_t)(LCU_FCTRL_FORCE_SENSE_COMMON_MASK) << ((uint32_t)(ID)*8U))
#define LCU_FCTRL_FORCE_SENSE_SHIFT(ID)             ((uint32_t)(ID)*8U)
#define LCU_FCTRL_FORCE_SENSE_WIDTH                 (4U)
#define LCU_FCTRL_FORCE_SENSE(ID,x)                 (((uint32_t)(((uint32_t)(x)) << (uint32_t)LCU_FCTRL_FORCE_SENSE_SHIFT(ID))) & (uint32_t)LCU_FCTRL_FORCE_SENSE_MASK(ID))
#define LCU_FCTRL_FORCE_MODE_MASK(ID)               ((uint32_t)(LCU_FCTRL_FORCE_MODE_COMMON_MASK) << ((uint32_t)(ID)*8U))
#define LCU_FCTRL_FORCE_MODE_SHIFT(ID)              (4U + ((uint32_t)(ID)*8U))
#define LCU_FCTRL_FORCE_MODE_WIDTH                  (2U)
#define LCU_FCTRL_FORCE_MODE(ID,x)                  (((uint32_t)(((uint32_t)(x)) << (uint32_t)LCU_FCTRL_FORCE_MODE_SHIFT(ID))) & (uint32_t)LCU_FCTRL_FORCE_MODE_MASK(ID))
#define LCU_FCTRL_SYNC_SEL_MASK(ID)                 ((uint32_t)(LCU_FCTRL_SYNC_SEL_COMMON_MASK) << ((uint32_t)(ID)*8U))
#define LCU_FCTRL_SYNC_SEL_SHIFT(ID)                (6U + ((uint32_t)(ID)*8U))
#define LCU_FCTRL_SYNC_SEL_WIDTH                    (2U)
#define LCU_FCTRL_SYNC_SEL(ID,x)                    (((uint32_t)(((uint32_t)(x)) << (uint32_t)LCU_FCTRL_SYNC_SEL_SHIFT(ID))) & (uint32_t)LCU_FCTRL_SYNC_SEL_MASK(ID))

/* LCU mapping inputID to position in register */
#define LCU_IP_MAPPING_INPUT_TO_LC(HwLcInputId)         (uint8_t)((uint8_t)(HwLcInputId) / LCU_NUM_INPUT_PER_LC)
#define LCU_IP_MAPPING_OUTPUT_TO_LC(HwLcOutputId)       (uint8_t)((uint8_t)(HwLcOutputId) / LCU_NUM_OUTPUT_PER_LC)
/* LCU mapping outputID to position in register */
#define LCU_IP_MAPPING_INTPUT_ID_TO_HW_INPUT(HwLcInputId)              ((uint8_t)((uint8_t)(HwLcInputId) % LCU_NUM_INPUT_PER_LC))
#define LCU_IP_MAPPING_OUTPUT_ID_TO_HW_OUTPUT(HwLcOutputId)            ((uint8_t)((uint8_t)(HwLcOutputId) % LCU_NUM_OUTPUT_PER_LC))
/** @} */

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef LCU_IP_TYPES_SOC_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
