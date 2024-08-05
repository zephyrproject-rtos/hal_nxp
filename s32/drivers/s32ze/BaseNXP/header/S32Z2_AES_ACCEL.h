/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_AES_ACCEL.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_AES_ACCEL
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
#if !defined(S32Z2_AES_ACCEL_H_)  /* Check if memory map has not been already included */
#define S32Z2_AES_ACCEL_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- AES_ACCEL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AES_ACCEL_Peripheral_Access_Layer AES_ACCEL Peripheral Access Layer
 * @{
 */

/** AES_ACCEL - Size of Registers Arrays */
#define AES_ACCEL_ACCEL_COUNT                     8u

/** AES_ACCEL - Register Layout Typedef */
typedef struct {
  struct AES_ACCEL_ACCEL {                         /* offset: 0x0, array step: 0x1000 */
    __IO uint32_t LEN;                               /**< LEN, array offset: 0x0, array step: 0x1000 */
    __IO uint32_t AILEN;                             /**< AAD/IV length, array offset: 0x4, array step: 0x1000 */
    __IO uint32_t CRYPT;                             /**< CRYPT, array offset: 0x8, array step: 0x1000 */
    __I  uint32_t OWNSTAT;                           /**< OWN_Status, array offset: 0xC, array step: 0x1000 */
    __IO uint32_t TLVAL;                             /**< Timer Load Value, array offset: 0x10, array step: 0x1000 */
    __I  uint32_t CVAL;                              /**< Current Timer Value, array offset: 0x14, array step: 0x1000 */
    __IO uint32_t TCTRL;                             /**< Timer Control, array offset: 0x18, array step: 0x1000 */
    __IO uint32_t TFLG;                              /**< Timer Flag, array offset: 0x1C, array step: 0x1000 */
    __IO uint32_t FEEDINTMAP;                        /**< FEEDINTMAP, array offset: 0x20, array step: 0x1000 */
    __IO uint32_t RESULTINTMAP;                      /**< RESULTINTMAP, array offset: 0x24, array step: 0x1000 */
    uint8_t RESERVED_0[4056];
  } ACCEL[AES_ACCEL_ACCEL_COUNT];
} AES_ACCEL_Type, *AES_ACCEL_MemMapPtr;

/** Number of instances of the AES_ACCEL module. */
#define AES_ACCEL_INSTANCE_COUNT                 (1u)

/* AES_ACCEL - Peripheral instance base addresses */
/** Peripheral AES__AES_ACCEL base address */
#define IP_AES__AES_ACCEL_BASE                   (0x472A0000u)
/** Peripheral AES__AES_ACCEL base pointer */
#define IP_AES__AES_ACCEL                        ((AES_ACCEL_Type *)IP_AES__AES_ACCEL_BASE)
/** Array initializer of AES_ACCEL peripheral base addresses */
#define IP_AES_ACCEL_BASE_ADDRS                  { IP_AES__AES_ACCEL_BASE }
/** Array initializer of AES_ACCEL peripheral base pointers */
#define IP_AES_ACCEL_BASE_PTRS                   { IP_AES__AES_ACCEL }

/* ----------------------------------------------------------------------------
   -- AES_ACCEL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AES_ACCEL_Register_Masks AES_ACCEL Register Masks
 * @{
 */

/*! @name LEN - LEN */
/*! @{ */

#define AES_ACCEL_LEN_TLEN_MASK                  (0x7FFFFU)
#define AES_ACCEL_LEN_TLEN_SHIFT                 (0U)
#define AES_ACCEL_LEN_TLEN_WIDTH                 (19U)
#define AES_ACCEL_LEN_TLEN(x)                    (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_LEN_TLEN_SHIFT)) & AES_ACCEL_LEN_TLEN_MASK)
/*! @} */

/*! @name AILEN - AAD/IV length */
/*! @{ */

#define AES_ACCEL_AILEN_AAD_MASK                 (0x7FFFFU)
#define AES_ACCEL_AILEN_AAD_SHIFT                (0U)
#define AES_ACCEL_AILEN_AAD_WIDTH                (19U)
#define AES_ACCEL_AILEN_AAD(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN_AAD_SHIFT)) & AES_ACCEL_AILEN_AAD_MASK)

#define AES_ACCEL_AILEN_IVLEN_MASK               (0x7F000000U)
#define AES_ACCEL_AILEN_IVLEN_SHIFT              (24U)
#define AES_ACCEL_AILEN_IVLEN_WIDTH              (7U)
#define AES_ACCEL_AILEN_IVLEN(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_AILEN_IVLEN_SHIFT)) & AES_ACCEL_AILEN_IVLEN_MASK)
/*! @} */

/*! @name CRYPT - CRYPT */
/*! @{ */

#define AES_ACCEL_CRYPT_MASK_MASK                (0x7FU)
#define AES_ACCEL_CRYPT_MASK_SHIFT               (0U)
#define AES_ACCEL_CRYPT_MASK_WIDTH               (7U)
#define AES_ACCEL_CRYPT_MASK(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT_MASK_SHIFT)) & AES_ACCEL_CRYPT_MASK_MASK)

#define AES_ACCEL_CRYPT_CMODE_MASK               (0xF00U)
#define AES_ACCEL_CRYPT_CMODE_SHIFT              (8U)
#define AES_ACCEL_CRYPT_CMODE_WIDTH              (4U)
#define AES_ACCEL_CRYPT_CMODE(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT_CMODE_SHIFT)) & AES_ACCEL_CRYPT_CMODE_MASK)

#define AES_ACCEL_CRYPT_CO_MASK                  (0x3000U)
#define AES_ACCEL_CRYPT_CO_SHIFT                 (12U)
#define AES_ACCEL_CRYPT_CO_WIDTH                 (2U)
#define AES_ACCEL_CRYPT_CO(x)                    (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT_CO_SHIFT)) & AES_ACCEL_CRYPT_CO_MASK)

#define AES_ACCEL_CRYPT_KSLOT_MASK               (0x7F0000U)
#define AES_ACCEL_CRYPT_KSLOT_SHIFT              (16U)
#define AES_ACCEL_CRYPT_KSLOT_WIDTH              (7U)
#define AES_ACCEL_CRYPT_KSLOT(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CRYPT_KSLOT_SHIFT)) & AES_ACCEL_CRYPT_KSLOT_MASK)
/*! @} */

/*! @name OWNSTAT - OWN_Status */
/*! @{ */

#define AES_ACCEL_OWNSTAT_DID_MASK               (0xFU)
#define AES_ACCEL_OWNSTAT_DID_SHIFT              (0U)
#define AES_ACCEL_OWNSTAT_DID_WIDTH              (4U)
#define AES_ACCEL_OWNSTAT_DID(x)                 (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT_DID_SHIFT)) & AES_ACCEL_OWNSTAT_DID_MASK)

#define AES_ACCEL_OWNSTAT_NS_MASK                (0x40U)
#define AES_ACCEL_OWNSTAT_NS_SHIFT               (6U)
#define AES_ACCEL_OWNSTAT_NS_WIDTH               (1U)
#define AES_ACCEL_OWNSTAT_NS(x)                  (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT_NS_SHIFT)) & AES_ACCEL_OWNSTAT_NS_MASK)

#define AES_ACCEL_OWNSTAT_PRIV_MASK              (0x80U)
#define AES_ACCEL_OWNSTAT_PRIV_SHIFT             (7U)
#define AES_ACCEL_OWNSTAT_PRIV_WIDTH             (1U)
#define AES_ACCEL_OWNSTAT_PRIV(x)                (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_OWNSTAT_PRIV_SHIFT)) & AES_ACCEL_OWNSTAT_PRIV_MASK)
/*! @} */

/*! @name TLVAL - Timer Load Value */
/*! @{ */

#define AES_ACCEL_TLVAL_TSV_MASK                 (0xFFFFU)
#define AES_ACCEL_TLVAL_TSV_SHIFT                (0U)
#define AES_ACCEL_TLVAL_TSV_WIDTH                (16U)
#define AES_ACCEL_TLVAL_TSV(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TLVAL_TSV_SHIFT)) & AES_ACCEL_TLVAL_TSV_MASK)
/*! @} */

/*! @name CVAL - Current Timer Value */
/*! @{ */

#define AES_ACCEL_CVAL_TVL_MASK                  (0xFFFFU)
#define AES_ACCEL_CVAL_TVL_SHIFT                 (0U)
#define AES_ACCEL_CVAL_TVL_WIDTH                 (16U)
#define AES_ACCEL_CVAL_TVL(x)                    (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_CVAL_TVL_SHIFT)) & AES_ACCEL_CVAL_TVL_MASK)
/*! @} */

/*! @name TCTRL - Timer Control */
/*! @{ */

#define AES_ACCEL_TCTRL_TEN_MASK                 (0x1U)
#define AES_ACCEL_TCTRL_TEN_SHIFT                (0U)
#define AES_ACCEL_TCTRL_TEN_WIDTH                (1U)
#define AES_ACCEL_TCTRL_TEN(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL_TEN_SHIFT)) & AES_ACCEL_TCTRL_TEN_MASK)

#define AES_ACCEL_TCTRL_TIE_MASK                 (0x2U)
#define AES_ACCEL_TCTRL_TIE_SHIFT                (1U)
#define AES_ACCEL_TCTRL_TIE_WIDTH                (1U)
#define AES_ACCEL_TCTRL_TIE(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL_TIE_SHIFT)) & AES_ACCEL_TCTRL_TIE_MASK)

#define AES_ACCEL_TCTRL_FRZ_MASK                 (0x4U)
#define AES_ACCEL_TCTRL_FRZ_SHIFT                (2U)
#define AES_ACCEL_TCTRL_FRZ_WIDTH                (1U)
#define AES_ACCEL_TCTRL_FRZ(x)                   (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TCTRL_FRZ_SHIFT)) & AES_ACCEL_TCTRL_FRZ_MASK)
/*! @} */

/*! @name TFLG - Timer Flag */
/*! @{ */

#define AES_ACCEL_TFLG_TIF_MASK                  (0x1U)
#define AES_ACCEL_TFLG_TIF_SHIFT                 (0U)
#define AES_ACCEL_TFLG_TIF_WIDTH                 (1U)
#define AES_ACCEL_TFLG_TIF(x)                    (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_TFLG_TIF_SHIFT)) & AES_ACCEL_TFLG_TIF_MASK)
/*! @} */

/*! @name FEEDINTMAP - FEEDINTMAP */
/*! @{ */

#define AES_ACCEL_FEEDINTMAP_FIEN0_MASK          (0x1U)
#define AES_ACCEL_FEEDINTMAP_FIEN0_SHIFT         (0U)
#define AES_ACCEL_FEEDINTMAP_FIEN0_WIDTH         (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN0(x)            (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN0_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN0_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN1_MASK          (0x2U)
#define AES_ACCEL_FEEDINTMAP_FIEN1_SHIFT         (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN1_WIDTH         (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN1(x)            (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN1_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN1_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN2_MASK          (0x4U)
#define AES_ACCEL_FEEDINTMAP_FIEN2_SHIFT         (2U)
#define AES_ACCEL_FEEDINTMAP_FIEN2_WIDTH         (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN2(x)            (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN2_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN2_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN3_MASK          (0x8U)
#define AES_ACCEL_FEEDINTMAP_FIEN3_SHIFT         (3U)
#define AES_ACCEL_FEEDINTMAP_FIEN3_WIDTH         (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN3(x)            (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN3_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN3_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN4_MASK          (0x10U)
#define AES_ACCEL_FEEDINTMAP_FIEN4_SHIFT         (4U)
#define AES_ACCEL_FEEDINTMAP_FIEN4_WIDTH         (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN4(x)            (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN4_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN4_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN5_MASK          (0x20U)
#define AES_ACCEL_FEEDINTMAP_FIEN5_SHIFT         (5U)
#define AES_ACCEL_FEEDINTMAP_FIEN5_WIDTH         (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN5(x)            (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN5_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN5_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN6_MASK          (0x40U)
#define AES_ACCEL_FEEDINTMAP_FIEN6_SHIFT         (6U)
#define AES_ACCEL_FEEDINTMAP_FIEN6_WIDTH         (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN6(x)            (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN6_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN6_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN7_MASK          (0x80U)
#define AES_ACCEL_FEEDINTMAP_FIEN7_SHIFT         (7U)
#define AES_ACCEL_FEEDINTMAP_FIEN7_WIDTH         (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN7(x)            (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN7_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN7_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN8_MASK          (0x100U)
#define AES_ACCEL_FEEDINTMAP_FIEN8_SHIFT         (8U)
#define AES_ACCEL_FEEDINTMAP_FIEN8_WIDTH         (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN8(x)            (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN8_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN8_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN9_MASK          (0x200U)
#define AES_ACCEL_FEEDINTMAP_FIEN9_SHIFT         (9U)
#define AES_ACCEL_FEEDINTMAP_FIEN9_WIDTH         (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN9(x)            (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN9_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN9_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN10_MASK         (0x400U)
#define AES_ACCEL_FEEDINTMAP_FIEN10_SHIFT        (10U)
#define AES_ACCEL_FEEDINTMAP_FIEN10_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN10(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN10_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN10_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN11_MASK         (0x800U)
#define AES_ACCEL_FEEDINTMAP_FIEN11_SHIFT        (11U)
#define AES_ACCEL_FEEDINTMAP_FIEN11_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN11(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN11_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN11_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN12_MASK         (0x1000U)
#define AES_ACCEL_FEEDINTMAP_FIEN12_SHIFT        (12U)
#define AES_ACCEL_FEEDINTMAP_FIEN12_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN12(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN12_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN12_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN13_MASK         (0x2000U)
#define AES_ACCEL_FEEDINTMAP_FIEN13_SHIFT        (13U)
#define AES_ACCEL_FEEDINTMAP_FIEN13_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN13(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN13_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN13_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN14_MASK         (0x4000U)
#define AES_ACCEL_FEEDINTMAP_FIEN14_SHIFT        (14U)
#define AES_ACCEL_FEEDINTMAP_FIEN14_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN14(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN14_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN14_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN15_MASK         (0x8000U)
#define AES_ACCEL_FEEDINTMAP_FIEN15_SHIFT        (15U)
#define AES_ACCEL_FEEDINTMAP_FIEN15_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN15(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN15_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN15_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN16_MASK         (0x10000U)
#define AES_ACCEL_FEEDINTMAP_FIEN16_SHIFT        (16U)
#define AES_ACCEL_FEEDINTMAP_FIEN16_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN16(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN16_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN16_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN17_MASK         (0x20000U)
#define AES_ACCEL_FEEDINTMAP_FIEN17_SHIFT        (17U)
#define AES_ACCEL_FEEDINTMAP_FIEN17_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN17(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN17_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN17_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN18_MASK         (0x40000U)
#define AES_ACCEL_FEEDINTMAP_FIEN18_SHIFT        (18U)
#define AES_ACCEL_FEEDINTMAP_FIEN18_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN18(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN18_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN18_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN19_MASK         (0x80000U)
#define AES_ACCEL_FEEDINTMAP_FIEN19_SHIFT        (19U)
#define AES_ACCEL_FEEDINTMAP_FIEN19_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN19(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN19_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN19_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN20_MASK         (0x100000U)
#define AES_ACCEL_FEEDINTMAP_FIEN20_SHIFT        (20U)
#define AES_ACCEL_FEEDINTMAP_FIEN20_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN20(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN20_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN20_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN21_MASK         (0x200000U)
#define AES_ACCEL_FEEDINTMAP_FIEN21_SHIFT        (21U)
#define AES_ACCEL_FEEDINTMAP_FIEN21_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN21(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN21_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN21_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN22_MASK         (0x400000U)
#define AES_ACCEL_FEEDINTMAP_FIEN22_SHIFT        (22U)
#define AES_ACCEL_FEEDINTMAP_FIEN22_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN22(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN22_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN22_MASK)

#define AES_ACCEL_FEEDINTMAP_FIEN23_MASK         (0x800000U)
#define AES_ACCEL_FEEDINTMAP_FIEN23_SHIFT        (23U)
#define AES_ACCEL_FEEDINTMAP_FIEN23_WIDTH        (1U)
#define AES_ACCEL_FEEDINTMAP_FIEN23(x)           (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_FEEDINTMAP_FIEN23_SHIFT)) & AES_ACCEL_FEEDINTMAP_FIEN23_MASK)
/*! @} */

/*! @name RESULTINTMAP - RESULTINTMAP */
/*! @{ */

#define AES_ACCEL_RESULTINTMAP_RIEN0_MASK        (0x1U)
#define AES_ACCEL_RESULTINTMAP_RIEN0_SHIFT       (0U)
#define AES_ACCEL_RESULTINTMAP_RIEN0_WIDTH       (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN0(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN0_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN0_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN1_MASK        (0x2U)
#define AES_ACCEL_RESULTINTMAP_RIEN1_SHIFT       (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN1_WIDTH       (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN1(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN1_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN1_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN2_MASK        (0x4U)
#define AES_ACCEL_RESULTINTMAP_RIEN2_SHIFT       (2U)
#define AES_ACCEL_RESULTINTMAP_RIEN2_WIDTH       (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN2(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN2_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN2_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN3_MASK        (0x8U)
#define AES_ACCEL_RESULTINTMAP_RIEN3_SHIFT       (3U)
#define AES_ACCEL_RESULTINTMAP_RIEN3_WIDTH       (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN3(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN3_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN3_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN4_MASK        (0x10U)
#define AES_ACCEL_RESULTINTMAP_RIEN4_SHIFT       (4U)
#define AES_ACCEL_RESULTINTMAP_RIEN4_WIDTH       (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN4(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN4_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN4_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN5_MASK        (0x20U)
#define AES_ACCEL_RESULTINTMAP_RIEN5_SHIFT       (5U)
#define AES_ACCEL_RESULTINTMAP_RIEN5_WIDTH       (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN5(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN5_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN5_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN6_MASK        (0x40U)
#define AES_ACCEL_RESULTINTMAP_RIEN6_SHIFT       (6U)
#define AES_ACCEL_RESULTINTMAP_RIEN6_WIDTH       (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN6(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN6_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN6_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN7_MASK        (0x80U)
#define AES_ACCEL_RESULTINTMAP_RIEN7_SHIFT       (7U)
#define AES_ACCEL_RESULTINTMAP_RIEN7_WIDTH       (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN7(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN7_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN7_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN8_MASK        (0x100U)
#define AES_ACCEL_RESULTINTMAP_RIEN8_SHIFT       (8U)
#define AES_ACCEL_RESULTINTMAP_RIEN8_WIDTH       (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN8(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN8_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN8_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN9_MASK        (0x200U)
#define AES_ACCEL_RESULTINTMAP_RIEN9_SHIFT       (9U)
#define AES_ACCEL_RESULTINTMAP_RIEN9_WIDTH       (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN9(x)          (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN9_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN9_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN10_MASK       (0x400U)
#define AES_ACCEL_RESULTINTMAP_RIEN10_SHIFT      (10U)
#define AES_ACCEL_RESULTINTMAP_RIEN10_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN10(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN10_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN10_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN11_MASK       (0x800U)
#define AES_ACCEL_RESULTINTMAP_RIEN11_SHIFT      (11U)
#define AES_ACCEL_RESULTINTMAP_RIEN11_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN11(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN11_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN11_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN12_MASK       (0x1000U)
#define AES_ACCEL_RESULTINTMAP_RIEN12_SHIFT      (12U)
#define AES_ACCEL_RESULTINTMAP_RIEN12_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN12(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN12_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN12_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN13_MASK       (0x2000U)
#define AES_ACCEL_RESULTINTMAP_RIEN13_SHIFT      (13U)
#define AES_ACCEL_RESULTINTMAP_RIEN13_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN13(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN13_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN13_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN14_MASK       (0x4000U)
#define AES_ACCEL_RESULTINTMAP_RIEN14_SHIFT      (14U)
#define AES_ACCEL_RESULTINTMAP_RIEN14_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN14(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN14_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN14_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN15_MASK       (0x8000U)
#define AES_ACCEL_RESULTINTMAP_RIEN15_SHIFT      (15U)
#define AES_ACCEL_RESULTINTMAP_RIEN15_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN15(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN15_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN15_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN16_MASK       (0x10000U)
#define AES_ACCEL_RESULTINTMAP_RIEN16_SHIFT      (16U)
#define AES_ACCEL_RESULTINTMAP_RIEN16_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN16(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN16_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN16_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN17_MASK       (0x20000U)
#define AES_ACCEL_RESULTINTMAP_RIEN17_SHIFT      (17U)
#define AES_ACCEL_RESULTINTMAP_RIEN17_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN17(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN17_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN17_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN18_MASK       (0x40000U)
#define AES_ACCEL_RESULTINTMAP_RIEN18_SHIFT      (18U)
#define AES_ACCEL_RESULTINTMAP_RIEN18_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN18(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN18_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN18_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN19_MASK       (0x80000U)
#define AES_ACCEL_RESULTINTMAP_RIEN19_SHIFT      (19U)
#define AES_ACCEL_RESULTINTMAP_RIEN19_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN19(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN19_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN19_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN20_MASK       (0x100000U)
#define AES_ACCEL_RESULTINTMAP_RIEN20_SHIFT      (20U)
#define AES_ACCEL_RESULTINTMAP_RIEN20_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN20(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN20_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN20_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN21_MASK       (0x200000U)
#define AES_ACCEL_RESULTINTMAP_RIEN21_SHIFT      (21U)
#define AES_ACCEL_RESULTINTMAP_RIEN21_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN21(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN21_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN21_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN22_MASK       (0x400000U)
#define AES_ACCEL_RESULTINTMAP_RIEN22_SHIFT      (22U)
#define AES_ACCEL_RESULTINTMAP_RIEN22_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN22(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN22_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN22_MASK)

#define AES_ACCEL_RESULTINTMAP_RIEN23_MASK       (0x800000U)
#define AES_ACCEL_RESULTINTMAP_RIEN23_SHIFT      (23U)
#define AES_ACCEL_RESULTINTMAP_RIEN23_WIDTH      (1U)
#define AES_ACCEL_RESULTINTMAP_RIEN23(x)         (((uint32_t)(((uint32_t)(x)) << AES_ACCEL_RESULTINTMAP_RIEN23_SHIFT)) & AES_ACCEL_RESULTINTMAP_RIEN23_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group AES_ACCEL_Register_Masks */

/*!
 * @}
 */ /* end of group AES_ACCEL_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_AES_ACCEL_H_) */
