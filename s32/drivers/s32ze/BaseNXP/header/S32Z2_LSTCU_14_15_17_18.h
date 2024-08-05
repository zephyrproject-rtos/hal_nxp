/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_LSTCU_14_15_17_18.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_LSTCU_14_15_17_18
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
#if !defined(S32Z2_LSTCU_14_15_17_18_H_)  /* Check if memory map has not been already included */
#define S32Z2_LSTCU_14_15_17_18_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LSTCU_14_15_17_18 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LSTCU_14_15_17_18_Peripheral_Access_Layer LSTCU_14_15_17_18 Peripheral Access Layer
 * @{
 */

/** LSTCU_14_15_17_18 - Size of Registers Arrays */
#define LSTCU_14_15_17_18_MBIST_SCH_PTR_COUNT     2u
#define LSTCU_14_15_17_18_LBIST_SCH_PTR_COUNT     1u

/** LSTCU_14_15_17_18 - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[8];
  __IO uint32_t ERR_STAT;                          /**< Error Status, offset: 0x8 */
  uint8_t RESERVED_1[4];
  __IO uint32_t ERR_FM;                            /**< Error Fault Mapping, offset: 0x10 */
  uint8_t RESERVED_2[76];
  __I  uint32_t MB_RSTAT0;                         /**< MBIST Run Status 0, offset: 0x60 */
  __I  uint32_t MB_RSTAT1;                         /**< MBIST Run Status 1, offset: 0x64 */
  uint8_t RESERVED_3[152];
  __I  uint32_t LB_RSTAT0;                         /**< LBIST Run Status 0, offset: 0x100 */
  uint8_t RESERVED_4[124];
  __IO uint32_t MBFM0;                             /**< MBIST Fault Mapping 0, offset: 0x180 */
  __IO uint32_t MBFM1;                             /**< MBIST Fault Mapping 1, offset: 0x184 */
  uint8_t RESERVED_5[152];
  __IO uint32_t LBFM0;                             /**< LBIST Fault Mapping 0, offset: 0x220 */
  uint8_t RESERVED_6[60];
  __IO uint32_t STAG;                              /**< Stagger, offset: 0x260 */
  uint8_t RESERVED_7[12];
  __IO uint32_t PH1_DUR;                           /**< Phase 1 Duration, offset: 0x270 */
  uint8_t RESERVED_8[140];
  __IO uint32_t MBPTR[LSTCU_14_15_17_18_MBIST_SCH_PTR_COUNT]; /**< MBIST Scheduler Pointer, array offset: 0x300, array step: 0x4 */
  uint8_t RESERVED_9[152];
  __IO uint32_t LBPTR[LSTCU_14_15_17_18_LBIST_SCH_PTR_COUNT]; /**< LBIST Scheduler Pointer, array offset: 0x3A0, array step: 0x4 */
} LSTCU_14_15_17_18_Type, *LSTCU_14_15_17_18_MemMapPtr;

/** Number of instances of the LSTCU_14_15_17_18 module. */
#define LSTCU_14_15_17_18_INSTANCE_COUNT         (4u)

/* LSTCU_14_15_17_18 - Peripheral instance base addresses */
/** Peripheral LSTCU_14 base address */
#define IP_LSTCU_14_BASE                         (0x4C009000u)
/** Peripheral LSTCU_14 base pointer */
#define IP_LSTCU_14                              ((LSTCU_14_15_17_18_Type *)IP_LSTCU_14_BASE)
/** Peripheral LSTCU_15 base address */
#define IP_LSTCU_15_BASE                         (0x4C00A000u)
/** Peripheral LSTCU_15 base pointer */
#define IP_LSTCU_15                              ((LSTCU_14_15_17_18_Type *)IP_LSTCU_15_BASE)
/** Peripheral LSTCU_17 base address */
#define IP_LSTCU_17_BASE                         (0x4C809000u)
/** Peripheral LSTCU_17 base pointer */
#define IP_LSTCU_17                              ((LSTCU_14_15_17_18_Type *)IP_LSTCU_17_BASE)
/** Peripheral LSTCU_18 base address */
#define IP_LSTCU_18_BASE                         (0x4C80A000u)
/** Peripheral LSTCU_18 base pointer */
#define IP_LSTCU_18                              ((LSTCU_14_15_17_18_Type *)IP_LSTCU_18_BASE)
/** Array initializer of LSTCU_14_15_17_18 peripheral base addresses */
#define IP_LSTCU_14_15_17_18_BASE_ADDRS          { IP_LSTCU_14_BASE, IP_LSTCU_15_BASE, IP_LSTCU_17_BASE, IP_LSTCU_18_BASE }
/** Array initializer of LSTCU_14_15_17_18 peripheral base pointers */
#define IP_LSTCU_14_15_17_18_BASE_PTRS           { IP_LSTCU_14, IP_LSTCU_15, IP_LSTCU_17, IP_LSTCU_18 }

/* ----------------------------------------------------------------------------
   -- LSTCU_14_15_17_18 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LSTCU_14_15_17_18_Register_Masks LSTCU_14_15_17_18 Register Masks
 * @{
 */

/*! @name ERR_STAT - Error Status */
/*! @{ */

#define LSTCU_14_15_17_18_ERR_STAT_INVP_MB_MASK  (0x2U)
#define LSTCU_14_15_17_18_ERR_STAT_INVP_MB_SHIFT (1U)
#define LSTCU_14_15_17_18_ERR_STAT_INVP_MB_WIDTH (1U)
#define LSTCU_14_15_17_18_ERR_STAT_INVP_MB(x)    (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_ERR_STAT_INVP_MB_SHIFT)) & LSTCU_14_15_17_18_ERR_STAT_INVP_MB_MASK)

#define LSTCU_14_15_17_18_ERR_STAT_INVP_LB_MASK  (0x4U)
#define LSTCU_14_15_17_18_ERR_STAT_INVP_LB_SHIFT (2U)
#define LSTCU_14_15_17_18_ERR_STAT_INVP_LB_WIDTH (1U)
#define LSTCU_14_15_17_18_ERR_STAT_INVP_LB(x)    (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_ERR_STAT_INVP_LB_SHIFT)) & LSTCU_14_15_17_18_ERR_STAT_INVP_LB_MASK)

#define LSTCU_14_15_17_18_ERR_STAT_UFSF_MASK     (0x10000U)
#define LSTCU_14_15_17_18_ERR_STAT_UFSF_SHIFT    (16U)
#define LSTCU_14_15_17_18_ERR_STAT_UFSF_WIDTH    (1U)
#define LSTCU_14_15_17_18_ERR_STAT_UFSF(x)       (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_ERR_STAT_UFSF_SHIFT)) & LSTCU_14_15_17_18_ERR_STAT_UFSF_MASK)

#define LSTCU_14_15_17_18_ERR_STAT_RFSF_MASK     (0x20000U)
#define LSTCU_14_15_17_18_ERR_STAT_RFSF_SHIFT    (17U)
#define LSTCU_14_15_17_18_ERR_STAT_RFSF_WIDTH    (1U)
#define LSTCU_14_15_17_18_ERR_STAT_RFSF(x)       (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_ERR_STAT_RFSF_SHIFT)) & LSTCU_14_15_17_18_ERR_STAT_RFSF_MASK)
/*! @} */

/*! @name ERR_FM - Error Fault Mapping */
/*! @{ */

#define LSTCU_14_15_17_18_ERR_FM_INVPFMMB_MASK   (0x2U)
#define LSTCU_14_15_17_18_ERR_FM_INVPFMMB_SHIFT  (1U)
#define LSTCU_14_15_17_18_ERR_FM_INVPFMMB_WIDTH  (1U)
#define LSTCU_14_15_17_18_ERR_FM_INVPFMMB(x)     (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_ERR_FM_INVPFMMB_SHIFT)) & LSTCU_14_15_17_18_ERR_FM_INVPFMMB_MASK)

#define LSTCU_14_15_17_18_ERR_FM_INVPFMLB_MASK   (0x4U)
#define LSTCU_14_15_17_18_ERR_FM_INVPFMLB_SHIFT  (2U)
#define LSTCU_14_15_17_18_ERR_FM_INVPFMLB_WIDTH  (1U)
#define LSTCU_14_15_17_18_ERR_FM_INVPFMLB(x)     (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_ERR_FM_INVPFMLB_SHIFT)) & LSTCU_14_15_17_18_ERR_FM_INVPFMLB_MASK)
/*! @} */

/*! @name MB_RSTAT0 - MBIST Run Status 0 */
/*! @{ */

#define LSTCU_14_15_17_18_MB_RSTAT0_MBSTAT0_MASK (0x1U)
#define LSTCU_14_15_17_18_MB_RSTAT0_MBSTAT0_SHIFT (0U)
#define LSTCU_14_15_17_18_MB_RSTAT0_MBSTAT0_WIDTH (1U)
#define LSTCU_14_15_17_18_MB_RSTAT0_MBSTAT0(x)   (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_MB_RSTAT0_MBSTAT0_SHIFT)) & LSTCU_14_15_17_18_MB_RSTAT0_MBSTAT0_MASK)
/*! @} */

/*! @name MB_RSTAT1 - MBIST Run Status 1 */
/*! @{ */

#define LSTCU_14_15_17_18_MB_RSTAT1_MBSTAT0_MASK (0x1U)
#define LSTCU_14_15_17_18_MB_RSTAT1_MBSTAT0_SHIFT (0U)
#define LSTCU_14_15_17_18_MB_RSTAT1_MBSTAT0_WIDTH (1U)
#define LSTCU_14_15_17_18_MB_RSTAT1_MBSTAT0(x)   (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_MB_RSTAT1_MBSTAT0_SHIFT)) & LSTCU_14_15_17_18_MB_RSTAT1_MBSTAT0_MASK)
/*! @} */

/*! @name LB_RSTAT0 - LBIST Run Status 0 */
/*! @{ */

#define LSTCU_14_15_17_18_LB_RSTAT0_LBSTAT0_MASK (0x1U)
#define LSTCU_14_15_17_18_LB_RSTAT0_LBSTAT0_SHIFT (0U)
#define LSTCU_14_15_17_18_LB_RSTAT0_LBSTAT0_WIDTH (1U)
#define LSTCU_14_15_17_18_LB_RSTAT0_LBSTAT0(x)   (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_LB_RSTAT0_LBSTAT0_SHIFT)) & LSTCU_14_15_17_18_LB_RSTAT0_LBSTAT0_MASK)
/*! @} */

/*! @name MBFM0 - MBIST Fault Mapping 0 */
/*! @{ */

#define LSTCU_14_15_17_18_MBFM0_MBSTATFM0_MASK   (0x1U)
#define LSTCU_14_15_17_18_MBFM0_MBSTATFM0_SHIFT  (0U)
#define LSTCU_14_15_17_18_MBFM0_MBSTATFM0_WIDTH  (1U)
#define LSTCU_14_15_17_18_MBFM0_MBSTATFM0(x)     (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_MBFM0_MBSTATFM0_SHIFT)) & LSTCU_14_15_17_18_MBFM0_MBSTATFM0_MASK)
/*! @} */

/*! @name MBFM1 - MBIST Fault Mapping 1 */
/*! @{ */

#define LSTCU_14_15_17_18_MBFM1_MBSTATFM0_MASK   (0x1U)
#define LSTCU_14_15_17_18_MBFM1_MBSTATFM0_SHIFT  (0U)
#define LSTCU_14_15_17_18_MBFM1_MBSTATFM0_WIDTH  (1U)
#define LSTCU_14_15_17_18_MBFM1_MBSTATFM0(x)     (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_MBFM1_MBSTATFM0_SHIFT)) & LSTCU_14_15_17_18_MBFM1_MBSTATFM0_MASK)
/*! @} */

/*! @name LBFM0 - LBIST Fault Mapping 0 */
/*! @{ */

#define LSTCU_14_15_17_18_LBFM0_LBSTATFM0_MASK   (0x1U)
#define LSTCU_14_15_17_18_LBFM0_LBSTATFM0_SHIFT  (0U)
#define LSTCU_14_15_17_18_LBFM0_LBSTATFM0_WIDTH  (1U)
#define LSTCU_14_15_17_18_LBFM0_LBSTATFM0(x)     (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_LBFM0_LBSTATFM0_SHIFT)) & LSTCU_14_15_17_18_LBFM0_LBSTATFM0_MASK)
/*! @} */

/*! @name STAG - Stagger */
/*! @{ */

#define LSTCU_14_15_17_18_STAG_MB_DELAY_MASK     (0xFF00U)
#define LSTCU_14_15_17_18_STAG_MB_DELAY_SHIFT    (8U)
#define LSTCU_14_15_17_18_STAG_MB_DELAY_WIDTH    (8U)
#define LSTCU_14_15_17_18_STAG_MB_DELAY(x)       (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_STAG_MB_DELAY_SHIFT)) & LSTCU_14_15_17_18_STAG_MB_DELAY_MASK)

#define LSTCU_14_15_17_18_STAG_LB_DELAY_MASK     (0xFF0000U)
#define LSTCU_14_15_17_18_STAG_LB_DELAY_SHIFT    (16U)
#define LSTCU_14_15_17_18_STAG_LB_DELAY_WIDTH    (8U)
#define LSTCU_14_15_17_18_STAG_LB_DELAY(x)       (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_STAG_LB_DELAY_SHIFT)) & LSTCU_14_15_17_18_STAG_LB_DELAY_MASK)
/*! @} */

/*! @name PH1_DUR - Phase 1 Duration */
/*! @{ */

#define LSTCU_14_15_17_18_PH1_DUR_PH1DUR_MASK    (0x3FFU)
#define LSTCU_14_15_17_18_PH1_DUR_PH1DUR_SHIFT   (0U)
#define LSTCU_14_15_17_18_PH1_DUR_PH1DUR_WIDTH   (10U)
#define LSTCU_14_15_17_18_PH1_DUR_PH1DUR(x)      (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_PH1_DUR_PH1DUR_SHIFT)) & LSTCU_14_15_17_18_PH1_DUR_PH1DUR_MASK)
/*! @} */

/*! @name MBPTR - MBIST Scheduler Pointer */
/*! @{ */

#define LSTCU_14_15_17_18_MBPTR_MBPTR_MASK       (0xFFU)
#define LSTCU_14_15_17_18_MBPTR_MBPTR_SHIFT      (0U)
#define LSTCU_14_15_17_18_MBPTR_MBPTR_WIDTH      (8U)
#define LSTCU_14_15_17_18_MBPTR_MBPTR(x)         (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_MBPTR_MBPTR_SHIFT)) & LSTCU_14_15_17_18_MBPTR_MBPTR_MASK)

#define LSTCU_14_15_17_18_MBPTR_MBCSM_MASK       (0x100U)
#define LSTCU_14_15_17_18_MBPTR_MBCSM_SHIFT      (8U)
#define LSTCU_14_15_17_18_MBPTR_MBCSM_WIDTH      (1U)
#define LSTCU_14_15_17_18_MBPTR_MBCSM(x)         (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_MBPTR_MBCSM_SHIFT)) & LSTCU_14_15_17_18_MBPTR_MBCSM_MASK)

#define LSTCU_14_15_17_18_MBPTR_MBEOL_MASK       (0x80000000U)
#define LSTCU_14_15_17_18_MBPTR_MBEOL_SHIFT      (31U)
#define LSTCU_14_15_17_18_MBPTR_MBEOL_WIDTH      (1U)
#define LSTCU_14_15_17_18_MBPTR_MBEOL(x)         (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_MBPTR_MBEOL_SHIFT)) & LSTCU_14_15_17_18_MBPTR_MBEOL_MASK)
/*! @} */

/*! @name LBPTR - LBIST Scheduler Pointer */
/*! @{ */

#define LSTCU_14_15_17_18_LBPTR_LBPTR_MASK       (0xFFU)
#define LSTCU_14_15_17_18_LBPTR_LBPTR_SHIFT      (0U)
#define LSTCU_14_15_17_18_LBPTR_LBPTR_WIDTH      (8U)
#define LSTCU_14_15_17_18_LBPTR_LBPTR(x)         (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_LBPTR_LBPTR_SHIFT)) & LSTCU_14_15_17_18_LBPTR_LBPTR_MASK)

#define LSTCU_14_15_17_18_LBPTR_LBCSM_MASK       (0x100U)
#define LSTCU_14_15_17_18_LBPTR_LBCSM_SHIFT      (8U)
#define LSTCU_14_15_17_18_LBPTR_LBCSM_WIDTH      (1U)
#define LSTCU_14_15_17_18_LBPTR_LBCSM(x)         (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_LBPTR_LBCSM_SHIFT)) & LSTCU_14_15_17_18_LBPTR_LBCSM_MASK)

#define LSTCU_14_15_17_18_LBPTR_LBEOL_MASK       (0x80000000U)
#define LSTCU_14_15_17_18_LBPTR_LBEOL_SHIFT      (31U)
#define LSTCU_14_15_17_18_LBPTR_LBEOL_WIDTH      (1U)
#define LSTCU_14_15_17_18_LBPTR_LBEOL(x)         (((uint32_t)(((uint32_t)(x)) << LSTCU_14_15_17_18_LBPTR_LBEOL_SHIFT)) & LSTCU_14_15_17_18_LBPTR_LBEOL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LSTCU_14_15_17_18_Register_Masks */

/*!
 * @}
 */ /* end of group LSTCU_14_15_17_18_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_LSTCU_14_15_17_18_H_) */
