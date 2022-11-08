/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_ACE.h
 * @version 1.8
 * @date 2022-07-13
 * @brief Peripheral Access Layer for S32Z2_ACE
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32Z2_ACE_H_)  /* Check if memory map has not been already included */
#define S32Z2_ACE_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ACE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACE_Peripheral_Access_Layer ACE Peripheral Access Layer
 * @{
 */

/** ACE - Register Layout Typedef */
typedef struct {
  __O  uint64_t INIT_VEC;                          /**< , offset: 0x0 */
  __O  uint64_t DATA_IN;                           /**< , offset: 0x8 */
  uint8_t RESERVED_0[240];
  __I  uint64_t STATUS;                            /**< , offset: 0x100 */
  __IO uint64_t CONTROL;                           /**< , offset: 0x108 */
  uint8_t RESERVED_1[8];
  __IO uint64_t RESULT;                            /**< , offset: 0x118 */
  __IO uint64_t AUTH_TAG;                          /**< , offset: 0x120 */
  __I  uint64_t VERSION;                           /**< , offset: 0x128 */
} ACE_Type, *ACE_MemMapPtr;

/** Number of instances of the ACE module. */
#define ACE_INSTANCE_COUNT                       (2u)

/* ACE - Peripheral instance base addresses */
/** Peripheral AES__ACE__AHB base address */
#define IP_AES__ACE__AHB_BASE                    (0x47000000u)
/** Peripheral AES__ACE__AHB base pointer */
#define IP_AES__ACE__AHB                         ((ACE_Type *)IP_AES__ACE__AHB_BASE)
/** Peripheral AES__ACE__AHB2 base address */
#define IP_AES__ACE__AHB2_BASE                   (0x47000000u)
/** Peripheral AES__ACE__AHB2 base pointer */
#define IP_AES__ACE__AHB2                        ((ACE_Type *)IP_AES__ACE__AHB2_BASE)
/** Array initializer of ACE peripheral base addresses */
#define IP_ACE_BASE_ADDRS                        { IP_AES__ACE__AHB_BASE, IP_AES__ACE__AHB2_BASE }
/** Array initializer of ACE peripheral base pointers */
#define IP_ACE_BASE_PTRS                         { IP_AES__ACE__AHB, IP_AES__ACE__AHB2 }

/* ----------------------------------------------------------------------------
   -- ACE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACE_Register_Masks ACE Register Masks
 * @{
 */

/*! @name INIT_VEC -  */
/*! @{ */

#define ACE_INIT_VEC_DATA_MASK                   (0xFFFFFFFFFFFFFFFFU)
#define ACE_INIT_VEC_DATA_SHIFT                  (0U)
#define ACE_INIT_VEC_DATA_WIDTH                  (64U)
#define ACE_INIT_VEC_DATA(x)                     (((uint64_t)(((uint64_t)(x)) << ACE_INIT_VEC_DATA_SHIFT)) & ACE_INIT_VEC_DATA_MASK)
/*! @} */

/*! @name DATA_IN -  */
/*! @{ */

#define ACE_DATA_IN_DATA_MASK                    (0xFFFFFFFFFFFFFFFFU)
#define ACE_DATA_IN_DATA_SHIFT                   (0U)
#define ACE_DATA_IN_DATA_WIDTH                   (64U)
#define ACE_DATA_IN_DATA(x)                      (((uint64_t)(((uint64_t)(x)) << ACE_DATA_IN_DATA_SHIFT)) & ACE_DATA_IN_DATA_MASK)
/*! @} */

/*! @name STATUS -  */
/*! @{ */

#define ACE_STATUS_RFU_IRQ_MASK                  (0x1U)
#define ACE_STATUS_RFU_IRQ_SHIFT                 (0U)
#define ACE_STATUS_RFU_IRQ_WIDTH                 (1U)
#define ACE_STATUS_RFU_IRQ(x)                    (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_RFU_IRQ_SHIFT)) & ACE_STATUS_RFU_IRQ_MASK)

#define ACE_STATUS_BUSY_MASK                     (0x2U)
#define ACE_STATUS_BUSY_SHIFT                    (1U)
#define ACE_STATUS_BUSY_WIDTH                    (1U)
#define ACE_STATUS_BUSY(x)                       (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_BUSY_SHIFT)) & ACE_STATUS_BUSY_MASK)

#define ACE_STATUS_ERROR_MASK                    (0x1CU)
#define ACE_STATUS_ERROR_SHIFT                   (2U)
#define ACE_STATUS_ERROR_WIDTH                   (3U)
#define ACE_STATUS_ERROR(x)                      (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_ERROR_SHIFT)) & ACE_STATUS_ERROR_MASK)

#define ACE_STATUS_RFU2_MASK                     (0xFFE0U)
#define ACE_STATUS_RFU2_SHIFT                    (5U)
#define ACE_STATUS_RFU2_WIDTH                    (11U)
#define ACE_STATUS_RFU2(x)                       (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_RFU2_SHIFT)) & ACE_STATUS_RFU2_MASK)

#define ACE_STATUS_K_ERR_MASK                    (0x10000U)
#define ACE_STATUS_K_ERR_SHIFT                   (16U)
#define ACE_STATUS_K_ERR_WIDTH                   (1U)
#define ACE_STATUS_K_ERR(x)                      (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_K_ERR_SHIFT)) & ACE_STATUS_K_ERR_MASK)

#define ACE_STATUS_CMP_ERR_MASK                  (0x20000U)
#define ACE_STATUS_CMP_ERR_SHIFT                 (17U)
#define ACE_STATUS_CMP_ERR_WIDTH                 (1U)
#define ACE_STATUS_CMP_ERR(x)                    (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_CMP_ERR_SHIFT)) & ACE_STATUS_CMP_ERR_MASK)

#define ACE_STATUS_KD_ERR_MASK                   (0x40000U)
#define ACE_STATUS_KD_ERR_SHIFT                  (18U)
#define ACE_STATUS_KD_ERR_WIDTH                  (1U)
#define ACE_STATUS_KD_ERR(x)                     (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_KD_ERR_SHIFT)) & ACE_STATUS_KD_ERR_MASK)

#define ACE_STATUS_KP_ERR_MASK                   (0x80000U)
#define ACE_STATUS_KP_ERR_SHIFT                  (19U)
#define ACE_STATUS_KP_ERR_WIDTH                  (1U)
#define ACE_STATUS_KP_ERR(x)                     (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_KP_ERR_SHIFT)) & ACE_STATUS_KP_ERR_MASK)

#define ACE_STATUS_VERIFY_ERR_MASK               (0x100000U)
#define ACE_STATUS_VERIFY_ERR_SHIFT              (20U)
#define ACE_STATUS_VERIFY_ERR_WIDTH              (1U)
#define ACE_STATUS_VERIFY_ERR(x)                 (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_VERIFY_ERR_SHIFT)) & ACE_STATUS_VERIFY_ERR_MASK)

#define ACE_STATUS_DMA_ERR_MASK                  (0x200000U)
#define ACE_STATUS_DMA_ERR_SHIFT                 (21U)
#define ACE_STATUS_DMA_ERR_WIDTH                 (1U)
#define ACE_STATUS_DMA_ERR(x)                    (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_DMA_ERR_SHIFT)) & ACE_STATUS_DMA_ERR_MASK)

#define ACE_STATUS_ECC_ERR_MASK                  (0x400000U)
#define ACE_STATUS_ECC_ERR_SHIFT                 (22U)
#define ACE_STATUS_ECC_ERR_WIDTH                 (1U)
#define ACE_STATUS_ECC_ERR(x)                    (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_ECC_ERR_SHIFT)) & ACE_STATUS_ECC_ERR_MASK)

#define ACE_STATUS_DMA1_DID_ERR_MASK             (0x800000U)
#define ACE_STATUS_DMA1_DID_ERR_SHIFT            (23U)
#define ACE_STATUS_DMA1_DID_ERR_WIDTH            (1U)
#define ACE_STATUS_DMA1_DID_ERR(x)               (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_DMA1_DID_ERR_SHIFT)) & ACE_STATUS_DMA1_DID_ERR_MASK)

#define ACE_STATUS_DMA2_DID_ERR_MASK             (0x1000000U)
#define ACE_STATUS_DMA2_DID_ERR_SHIFT            (24U)
#define ACE_STATUS_DMA2_DID_ERR_WIDTH            (1U)
#define ACE_STATUS_DMA2_DID_ERR(x)               (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_DMA2_DID_ERR_SHIFT)) & ACE_STATUS_DMA2_DID_ERR_MASK)

#define ACE_STATUS_KP_CRC_ERR_MASK               (0x2000000U)
#define ACE_STATUS_KP_CRC_ERR_SHIFT              (25U)
#define ACE_STATUS_KP_CRC_ERR_WIDTH              (1U)
#define ACE_STATUS_KP_CRC_ERR(x)                 (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_KP_CRC_ERR_SHIFT)) & ACE_STATUS_KP_CRC_ERR_MASK)

#define ACE_STATUS_RFU_MASK                      (0xFFFFFFFFFC000000U)
#define ACE_STATUS_RFU_SHIFT                     (26U)
#define ACE_STATUS_RFU_WIDTH                     (38U)
#define ACE_STATUS_RFU(x)                        (((uint64_t)(((uint64_t)(x)) << ACE_STATUS_RFU_SHIFT)) & ACE_STATUS_RFU_MASK)
/*! @} */

/*! @name CONTROL -  */
/*! @{ */

#define ACE_CONTROL_ENABLE_MASK                  (0x1U)
#define ACE_CONTROL_ENABLE_SHIFT                 (0U)
#define ACE_CONTROL_ENABLE_WIDTH                 (1U)
#define ACE_CONTROL_ENABLE(x)                    (((uint64_t)(((uint64_t)(x)) << ACE_CONTROL_ENABLE_SHIFT)) & ACE_CONTROL_ENABLE_MASK)

#define ACE_CONTROL_RESET_MASK                   (0x2U)
#define ACE_CONTROL_RESET_SHIFT                  (1U)
#define ACE_CONTROL_RESET_WIDTH                  (1U)
#define ACE_CONTROL_RESET(x)                     (((uint64_t)(((uint64_t)(x)) << ACE_CONTROL_RESET_SHIFT)) & ACE_CONTROL_RESET_MASK)

#define ACE_CONTROL_MASK_MASK                    (0x1FCU)
#define ACE_CONTROL_MASK_SHIFT                   (2U)
#define ACE_CONTROL_MASK_WIDTH                   (7U)
#define ACE_CONTROL_MASK(x)                      (((uint64_t)(((uint64_t)(x)) << ACE_CONTROL_MASK_SHIFT)) & ACE_CONTROL_MASK_MASK)

#define ACE_CONTROL_RFU_MASK                     (0xFFFFFFFFFFFFFE00U)
#define ACE_CONTROL_RFU_SHIFT                    (9U)
#define ACE_CONTROL_RFU_WIDTH                    (55U)
#define ACE_CONTROL_RFU(x)                       (((uint64_t)(((uint64_t)(x)) << ACE_CONTROL_RFU_SHIFT)) & ACE_CONTROL_RFU_MASK)
/*! @} */

/*! @name RESULT -  */
/*! @{ */

#define ACE_RESULT_DATA_MASK                     (0xFFFFFFFFFFFFFFFFU)
#define ACE_RESULT_DATA_SHIFT                    (0U)
#define ACE_RESULT_DATA_WIDTH                    (64U)
#define ACE_RESULT_DATA(x)                       (((uint64_t)(((uint64_t)(x)) << ACE_RESULT_DATA_SHIFT)) & ACE_RESULT_DATA_MASK)
/*! @} */

/*! @name AUTH_TAG -  */
/*! @{ */

#define ACE_AUTH_TAG_DATA_MASK                   (0xFFFFFFFFFFFFFFFFU)
#define ACE_AUTH_TAG_DATA_SHIFT                  (0U)
#define ACE_AUTH_TAG_DATA_WIDTH                  (64U)
#define ACE_AUTH_TAG_DATA(x)                     (((uint64_t)(((uint64_t)(x)) << ACE_AUTH_TAG_DATA_SHIFT)) & ACE_AUTH_TAG_DATA_MASK)
/*! @} */

/*! @name VERSION -  */
/*! @{ */

#define ACE_VERSION_EXT_REV_MASK                 (0xFU)
#define ACE_VERSION_EXT_REV_SHIFT                (0U)
#define ACE_VERSION_EXT_REV_WIDTH                (4U)
#define ACE_VERSION_EXT_REV(x)                   (((uint64_t)(((uint64_t)(x)) << ACE_VERSION_EXT_REV_SHIFT)) & ACE_VERSION_EXT_REV_MASK)

#define ACE_VERSION_MINOR_REV2_MASK              (0xF0U)
#define ACE_VERSION_MINOR_REV2_SHIFT             (4U)
#define ACE_VERSION_MINOR_REV2_WIDTH             (4U)
#define ACE_VERSION_MINOR_REV2(x)                (((uint64_t)(((uint64_t)(x)) << ACE_VERSION_MINOR_REV2_SHIFT)) & ACE_VERSION_MINOR_REV2_MASK)

#define ACE_VERSION_MINOR_REV1_MASK              (0xF00U)
#define ACE_VERSION_MINOR_REV1_SHIFT             (8U)
#define ACE_VERSION_MINOR_REV1_WIDTH             (4U)
#define ACE_VERSION_MINOR_REV1(x)                (((uint64_t)(((uint64_t)(x)) << ACE_VERSION_MINOR_REV1_SHIFT)) & ACE_VERSION_MINOR_REV1_MASK)

#define ACE_VERSION_MAJOR_REV_MASK               (0xF000U)
#define ACE_VERSION_MAJOR_REV_SHIFT              (12U)
#define ACE_VERSION_MAJOR_REV_WIDTH              (4U)
#define ACE_VERSION_MAJOR_REV(x)                 (((uint64_t)(((uint64_t)(x)) << ACE_VERSION_MAJOR_REV_SHIFT)) & ACE_VERSION_MAJOR_REV_MASK)

#define ACE_VERSION_MILESTONE_MASK               (0x30000U)
#define ACE_VERSION_MILESTONE_SHIFT              (16U)
#define ACE_VERSION_MILESTONE_WIDTH              (2U)
#define ACE_VERSION_MILESTONE(x)                 (((uint64_t)(((uint64_t)(x)) << ACE_VERSION_MILESTONE_SHIFT)) & ACE_VERSION_MILESTONE_MASK)

#define ACE_VERSION_VERSION_RSVD_MASK            (0xFFFFFFFFFFFC0000U)
#define ACE_VERSION_VERSION_RSVD_SHIFT           (18U)
#define ACE_VERSION_VERSION_RSVD_WIDTH           (46U)
#define ACE_VERSION_VERSION_RSVD(x)              (((uint64_t)(((uint64_t)(x)) << ACE_VERSION_VERSION_RSVD_SHIFT)) & ACE_VERSION_VERSION_RSVD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ACE_Register_Masks */

/*!
 * @}
 */ /* end of group ACE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_ACE_H_) */
