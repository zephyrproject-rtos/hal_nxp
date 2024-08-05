/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_LSTCU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_LSTCU
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
#if !defined(S32Z2_LSTCU_H_)  /* Check if memory map has not been already included */
#define S32Z2_LSTCU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LSTCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LSTCU_Peripheral_Access_Layer LSTCU Peripheral Access Layer
 * @{
 */

/** LSTCU - Size of Registers Arrays */
#define LSTCU_MBIST_SCH_PTR_COUNT                 1u
#define LSTCU_LBIST_SCH_PTR_COUNT                 1u

/** LSTCU - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[8];
  __IO uint32_t ERR_STAT;                          /**< Error Status, offset: 0x8 */
  uint8_t RESERVED_1[4];
  __IO uint32_t ERR_FM;                            /**< Error Fault Mapping, offset: 0x10 */
  uint8_t RESERVED_2[76];
  __I  uint32_t MB_RSTAT0;                         /**< MBIST Run Status 0, offset: 0x60 */
  uint8_t RESERVED_3[156];
  __I  uint32_t LB_RSTAT0;                         /**< LBIST Run Status 0, offset: 0x100, not available in all instances (available on 10 out of 14) */
  uint8_t RESERVED_4[124];
  __IO uint32_t MBFM0;                             /**< MBIST Fault Mapping 0, offset: 0x180 */
  uint8_t RESERVED_5[156];
  __IO uint32_t LBFM0;                             /**< LBIST Fault Mapping 0, offset: 0x220, not available in all instances (available on 10 out of 14) */
  uint8_t RESERVED_6[60];
  __IO uint32_t STAG;                              /**< Stagger, offset: 0x260 */
  uint8_t RESERVED_7[12];
  __IO uint32_t PH1_DUR;                           /**< Phase 1 Duration, offset: 0x270 */
  __IO uint32_t ISODUR;                            /**< Isolation Duration, offset: 0x274 */
  __IO uint32_t SRCENDUR;                          /**< Synchronous Reset Clock Enable Duration, offset: 0x278 */
  uint8_t RESERVED_8[132];
  __IO uint32_t MBPTR[LSTCU_MBIST_SCH_PTR_COUNT];  /**< MBIST Scheduler Pointer, array offset: 0x300, array step: 0x4 */
  uint8_t RESERVED_9[156];
  __IO uint32_t LBPTR[LSTCU_LBIST_SCH_PTR_COUNT];  /**< LBIST Scheduler Pointer, array offset: 0x3A0, array step: 0x4, not available in all instances (available on 10 out of 14) */
} LSTCU_Type, *LSTCU_MemMapPtr;

/** Number of instances of the LSTCU module. */
#define LSTCU_INSTANCE_COUNT                     (14u)

/* LSTCU - Peripheral instance base addresses */
/** Peripheral LSTCU_0 base address */
#define IP_LSTCU_0_BASE                          (0x4D408000u)
/** Peripheral LSTCU_0 base pointer */
#define IP_LSTCU_0                               ((LSTCU_Type *)IP_LSTCU_0_BASE)
/** Peripheral LSTCU_1 base address */
#define IP_LSTCU_1_BASE                          (0x4D208000u)
/** Peripheral LSTCU_1 base pointer */
#define IP_LSTCU_1                               ((LSTCU_Type *)IP_LSTCU_1_BASE)
/** Peripheral LSTCU_2 base address */
#define IP_LSTCU_2_BASE                          (0x4D108000u)
/** Peripheral LSTCU_2 base pointer */
#define IP_LSTCU_2                               ((LSTCU_Type *)IP_LSTCU_2_BASE)
/** Peripheral LSTCU_3 base address */
#define IP_LSTCU_3_BASE                          (0x4D288000u)
/** Peripheral LSTCU_3 base pointer */
#define IP_LSTCU_3                               ((LSTCU_Type *)IP_LSTCU_3_BASE)
/** Peripheral LSTCU_4 base address */
#define IP_LSTCU_4_BASE                          (0x4D308000u)
/** Peripheral LSTCU_4 base pointer */
#define IP_LSTCU_4                               ((LSTCU_Type *)IP_LSTCU_4_BASE)
/** Peripheral LSTCU_5 base address */
#define IP_LSTCU_5_BASE                          (0x4D388000u)
/** Peripheral LSTCU_5 base pointer */
#define IP_LSTCU_5                               ((LSTCU_Type *)IP_LSTCU_5_BASE)
/** Peripheral LSTCU_6 base address */
#define IP_LSTCU_6_BASE                          (0x4D008000u)
/** Peripheral LSTCU_6 base pointer */
#define IP_LSTCU_6                               ((LSTCU_Type *)IP_LSTCU_6_BASE)
/** Peripheral LSTCU_7 base address */
#define IP_LSTCU_7_BASE                          (0x4D209000u)
/** Peripheral LSTCU_7 base pointer */
#define IP_LSTCU_7                               ((LSTCU_Type *)IP_LSTCU_7_BASE)
/** Peripheral LSTCU_8 base address */
#define IP_LSTCU_8_BASE                          (0x4D289000u)
/** Peripheral LSTCU_8 base pointer */
#define IP_LSTCU_8                               ((LSTCU_Type *)IP_LSTCU_8_BASE)
/** Peripheral LSTCU_9 base address */
#define IP_LSTCU_9_BASE                          (0x4D409000u)
/** Peripheral LSTCU_9 base pointer */
#define IP_LSTCU_9                               ((LSTCU_Type *)IP_LSTCU_9_BASE)
/** Peripheral LSTCU_10 base address */
#define IP_LSTCU_10_BASE                         (0x4D109000u)
/** Peripheral LSTCU_10 base pointer */
#define IP_LSTCU_10                              ((LSTCU_Type *)IP_LSTCU_10_BASE)
/** Peripheral LSTCU_11 base address */
#define IP_LSTCU_11_BASE                         (0x4D10A000u)
/** Peripheral LSTCU_11 base pointer */
#define IP_LSTCU_11                              ((LSTCU_Type *)IP_LSTCU_11_BASE)
/** Peripheral LSTCU_12 base address */
#define IP_LSTCU_12_BASE                         (0x4D309000u)
/** Peripheral LSTCU_12 base pointer */
#define IP_LSTCU_12                              ((LSTCU_Type *)IP_LSTCU_12_BASE)
/** Peripheral LSTCU_19 base address */
#define IP_LSTCU_19_BASE                         (0x4D389000u)
/** Peripheral LSTCU_19 base pointer */
#define IP_LSTCU_19                              ((LSTCU_Type *)IP_LSTCU_19_BASE)
/** Array initializer of LSTCU peripheral base addresses */
#define IP_LSTCU_BASE_ADDRS                      { IP_LSTCU_0_BASE, IP_LSTCU_1_BASE, IP_LSTCU_2_BASE, IP_LSTCU_3_BASE, IP_LSTCU_4_BASE, IP_LSTCU_5_BASE, IP_LSTCU_6_BASE, IP_LSTCU_7_BASE, IP_LSTCU_8_BASE, IP_LSTCU_9_BASE, IP_LSTCU_10_BASE, IP_LSTCU_11_BASE, IP_LSTCU_12_BASE, IP_LSTCU_19_BASE }
/** Array initializer of LSTCU peripheral base pointers */
#define IP_LSTCU_BASE_PTRS                       { IP_LSTCU_0, IP_LSTCU_1, IP_LSTCU_2, IP_LSTCU_3, IP_LSTCU_4, IP_LSTCU_5, IP_LSTCU_6, IP_LSTCU_7, IP_LSTCU_8, IP_LSTCU_9, IP_LSTCU_10, IP_LSTCU_11, IP_LSTCU_12, IP_LSTCU_19 }

/* ----------------------------------------------------------------------------
   -- LSTCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LSTCU_Register_Masks LSTCU Register Masks
 * @{
 */

/*! @name ERR_STAT - Error Status */
/*! @{ */

#define LSTCU_ERR_STAT_INVP_MB_MASK              (0x2U)
#define LSTCU_ERR_STAT_INVP_MB_SHIFT             (1U)
#define LSTCU_ERR_STAT_INVP_MB_WIDTH             (1U)
#define LSTCU_ERR_STAT_INVP_MB(x)                (((uint32_t)(((uint32_t)(x)) << LSTCU_ERR_STAT_INVP_MB_SHIFT)) & LSTCU_ERR_STAT_INVP_MB_MASK)

#define LSTCU_ERR_STAT_INVP_LB_MASK              (0x4U)
#define LSTCU_ERR_STAT_INVP_LB_SHIFT             (2U)
#define LSTCU_ERR_STAT_INVP_LB_WIDTH             (1U)
#define LSTCU_ERR_STAT_INVP_LB(x)                (((uint32_t)(((uint32_t)(x)) << LSTCU_ERR_STAT_INVP_LB_SHIFT)) & LSTCU_ERR_STAT_INVP_LB_MASK)

#define LSTCU_ERR_STAT_UFSF_MASK                 (0x10000U)
#define LSTCU_ERR_STAT_UFSF_SHIFT                (16U)
#define LSTCU_ERR_STAT_UFSF_WIDTH                (1U)
#define LSTCU_ERR_STAT_UFSF(x)                   (((uint32_t)(((uint32_t)(x)) << LSTCU_ERR_STAT_UFSF_SHIFT)) & LSTCU_ERR_STAT_UFSF_MASK)

#define LSTCU_ERR_STAT_RFSF_MASK                 (0x20000U)
#define LSTCU_ERR_STAT_RFSF_SHIFT                (17U)
#define LSTCU_ERR_STAT_RFSF_WIDTH                (1U)
#define LSTCU_ERR_STAT_RFSF(x)                   (((uint32_t)(((uint32_t)(x)) << LSTCU_ERR_STAT_RFSF_SHIFT)) & LSTCU_ERR_STAT_RFSF_MASK)
/*! @} */

/*! @name ERR_FM - Error Fault Mapping */
/*! @{ */

#define LSTCU_ERR_FM_INVPFMMB_MASK               (0x2U)
#define LSTCU_ERR_FM_INVPFMMB_SHIFT              (1U)
#define LSTCU_ERR_FM_INVPFMMB_WIDTH              (1U)
#define LSTCU_ERR_FM_INVPFMMB(x)                 (((uint32_t)(((uint32_t)(x)) << LSTCU_ERR_FM_INVPFMMB_SHIFT)) & LSTCU_ERR_FM_INVPFMMB_MASK)

#define LSTCU_ERR_FM_INVPFMLB_MASK               (0x4U)
#define LSTCU_ERR_FM_INVPFMLB_SHIFT              (2U)
#define LSTCU_ERR_FM_INVPFMLB_WIDTH              (1U)
#define LSTCU_ERR_FM_INVPFMLB(x)                 (((uint32_t)(((uint32_t)(x)) << LSTCU_ERR_FM_INVPFMLB_SHIFT)) & LSTCU_ERR_FM_INVPFMLB_MASK)
/*! @} */

/*! @name MB_RSTAT0 - MBIST Run Status 0 */
/*! @{ */

#define LSTCU_MB_RSTAT0_MBSTAT0_MASK             (0x1U)
#define LSTCU_MB_RSTAT0_MBSTAT0_SHIFT            (0U)
#define LSTCU_MB_RSTAT0_MBSTAT0_WIDTH            (1U)
#define LSTCU_MB_RSTAT0_MBSTAT0(x)               (((uint32_t)(((uint32_t)(x)) << LSTCU_MB_RSTAT0_MBSTAT0_SHIFT)) & LSTCU_MB_RSTAT0_MBSTAT0_MASK)
/*! @} */

/*! @name LB_RSTAT0 - LBIST Run Status 0 */
/*! @{ */

#define LSTCU_LB_RSTAT0_LBSTAT0_MASK             (0x1U)
#define LSTCU_LB_RSTAT0_LBSTAT0_SHIFT            (0U)
#define LSTCU_LB_RSTAT0_LBSTAT0_WIDTH            (1U)
#define LSTCU_LB_RSTAT0_LBSTAT0(x)               (((uint32_t)(((uint32_t)(x)) << LSTCU_LB_RSTAT0_LBSTAT0_SHIFT)) & LSTCU_LB_RSTAT0_LBSTAT0_MASK)
/*! @} */

/*! @name MBFM0 - MBIST Fault Mapping 0 */
/*! @{ */

#define LSTCU_MBFM0_MBSTATFM0_MASK               (0x1U)
#define LSTCU_MBFM0_MBSTATFM0_SHIFT              (0U)
#define LSTCU_MBFM0_MBSTATFM0_WIDTH              (1U)
#define LSTCU_MBFM0_MBSTATFM0(x)                 (((uint32_t)(((uint32_t)(x)) << LSTCU_MBFM0_MBSTATFM0_SHIFT)) & LSTCU_MBFM0_MBSTATFM0_MASK)
/*! @} */

/*! @name LBFM0 - LBIST Fault Mapping 0 */
/*! @{ */

#define LSTCU_LBFM0_LBSTATFM0_MASK               (0x1U)
#define LSTCU_LBFM0_LBSTATFM0_SHIFT              (0U)
#define LSTCU_LBFM0_LBSTATFM0_WIDTH              (1U)
#define LSTCU_LBFM0_LBSTATFM0(x)                 (((uint32_t)(((uint32_t)(x)) << LSTCU_LBFM0_LBSTATFM0_SHIFT)) & LSTCU_LBFM0_LBSTATFM0_MASK)
/*! @} */

/*! @name STAG - Stagger */
/*! @{ */

#define LSTCU_STAG_MB_DELAY_MASK                 (0xFF00U)
#define LSTCU_STAG_MB_DELAY_SHIFT                (8U)
#define LSTCU_STAG_MB_DELAY_WIDTH                (8U)
#define LSTCU_STAG_MB_DELAY(x)                   (((uint32_t)(((uint32_t)(x)) << LSTCU_STAG_MB_DELAY_SHIFT)) & LSTCU_STAG_MB_DELAY_MASK)

#define LSTCU_STAG_LB_DELAY_MASK                 (0xFF0000U)
#define LSTCU_STAG_LB_DELAY_SHIFT                (16U)
#define LSTCU_STAG_LB_DELAY_WIDTH                (8U)
#define LSTCU_STAG_LB_DELAY(x)                   (((uint32_t)(((uint32_t)(x)) << LSTCU_STAG_LB_DELAY_SHIFT)) & LSTCU_STAG_LB_DELAY_MASK)
/*! @} */

/*! @name PH1_DUR - Phase 1 Duration */
/*! @{ */

#define LSTCU_PH1_DUR_PH1DUR_MASK                (0x3FFU)
#define LSTCU_PH1_DUR_PH1DUR_SHIFT               (0U)
#define LSTCU_PH1_DUR_PH1DUR_WIDTH               (10U)
#define LSTCU_PH1_DUR_PH1DUR(x)                  (((uint32_t)(((uint32_t)(x)) << LSTCU_PH1_DUR_PH1DUR_SHIFT)) & LSTCU_PH1_DUR_PH1DUR_MASK)
/*! @} */

/*! @name ISODUR - Isolation Duration */
/*! @{ */

#define LSTCU_ISODUR_EN_DUR_MASK                 (0x3FFU)
#define LSTCU_ISODUR_EN_DUR_SHIFT                (0U)
#define LSTCU_ISODUR_EN_DUR_WIDTH                (10U)
#define LSTCU_ISODUR_EN_DUR(x)                   (((uint32_t)(((uint32_t)(x)) << LSTCU_ISODUR_EN_DUR_SHIFT)) & LSTCU_ISODUR_EN_DUR_MASK)

#define LSTCU_ISODUR_DIS_DUR_MASK                (0x3FF0000U)
#define LSTCU_ISODUR_DIS_DUR_SHIFT               (16U)
#define LSTCU_ISODUR_DIS_DUR_WIDTH               (10U)
#define LSTCU_ISODUR_DIS_DUR(x)                  (((uint32_t)(((uint32_t)(x)) << LSTCU_ISODUR_DIS_DUR_SHIFT)) & LSTCU_ISODUR_DIS_DUR_MASK)
/*! @} */

/*! @name SRCENDUR - Synchronous Reset Clock Enable Duration */
/*! @{ */

#define LSTCU_SRCENDUR_CLKENDUR_MASK             (0x3FFU)
#define LSTCU_SRCENDUR_CLKENDUR_SHIFT            (0U)
#define LSTCU_SRCENDUR_CLKENDUR_WIDTH            (10U)
#define LSTCU_SRCENDUR_CLKENDUR(x)               (((uint32_t)(((uint32_t)(x)) << LSTCU_SRCENDUR_CLKENDUR_SHIFT)) & LSTCU_SRCENDUR_CLKENDUR_MASK)
/*! @} */

/*! @name MBPTR - MBIST Scheduler Pointer */
/*! @{ */

#define LSTCU_MBPTR_MBPTR_MASK                   (0xFFU)
#define LSTCU_MBPTR_MBPTR_SHIFT                  (0U)
#define LSTCU_MBPTR_MBPTR_WIDTH                  (8U)
#define LSTCU_MBPTR_MBPTR(x)                     (((uint32_t)(((uint32_t)(x)) << LSTCU_MBPTR_MBPTR_SHIFT)) & LSTCU_MBPTR_MBPTR_MASK)

#define LSTCU_MBPTR_MBCSM_MASK                   (0x100U)
#define LSTCU_MBPTR_MBCSM_SHIFT                  (8U)
#define LSTCU_MBPTR_MBCSM_WIDTH                  (1U)
#define LSTCU_MBPTR_MBCSM(x)                     (((uint32_t)(((uint32_t)(x)) << LSTCU_MBPTR_MBCSM_SHIFT)) & LSTCU_MBPTR_MBCSM_MASK)

#define LSTCU_MBPTR_MBEOL_MASK                   (0x80000000U)
#define LSTCU_MBPTR_MBEOL_SHIFT                  (31U)
#define LSTCU_MBPTR_MBEOL_WIDTH                  (1U)
#define LSTCU_MBPTR_MBEOL(x)                     (((uint32_t)(((uint32_t)(x)) << LSTCU_MBPTR_MBEOL_SHIFT)) & LSTCU_MBPTR_MBEOL_MASK)
/*! @} */

/*! @name LBPTR - LBIST Scheduler Pointer */
/*! @{ */

#define LSTCU_LBPTR_LBPTR_MASK                   (0xFFU)
#define LSTCU_LBPTR_LBPTR_SHIFT                  (0U)
#define LSTCU_LBPTR_LBPTR_WIDTH                  (8U)
#define LSTCU_LBPTR_LBPTR(x)                     (((uint32_t)(((uint32_t)(x)) << LSTCU_LBPTR_LBPTR_SHIFT)) & LSTCU_LBPTR_LBPTR_MASK)

#define LSTCU_LBPTR_LBCSM_MASK                   (0x100U)
#define LSTCU_LBPTR_LBCSM_SHIFT                  (8U)
#define LSTCU_LBPTR_LBCSM_WIDTH                  (1U)
#define LSTCU_LBPTR_LBCSM(x)                     (((uint32_t)(((uint32_t)(x)) << LSTCU_LBPTR_LBCSM_SHIFT)) & LSTCU_LBPTR_LBCSM_MASK)

#define LSTCU_LBPTR_LBEOL_MASK                   (0x80000000U)
#define LSTCU_LBPTR_LBEOL_SHIFT                  (31U)
#define LSTCU_LBPTR_LBEOL_WIDTH                  (1U)
#define LSTCU_LBPTR_LBEOL(x)                     (((uint32_t)(((uint32_t)(x)) << LSTCU_LBPTR_LBEOL_SHIFT)) & LSTCU_LBPTR_LBEOL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LSTCU_Register_Masks */

/*!
 * @}
 */ /* end of group LSTCU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_LSTCU_H_) */
