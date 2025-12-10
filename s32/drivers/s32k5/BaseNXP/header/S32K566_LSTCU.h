/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_LSTCU.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_LSTCU
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
#if !defined(S32K566_LSTCU_H_)  /* Check if memory map has not been already included */
#define S32K566_LSTCU_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LSTCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LSTCU_Peripheral_Access_Layer LSTCU Peripheral Access Layer
 * @{
 */

/** LSTCU - Size of Registers Arrays */
#define LSTCU_MBIST_SCH_PTR_COUNT                 3u
#define LSTCU_LBIST_SCH_PTR_COUNT                 1u

/** LSTCU - Register Layout Typedef */
typedef struct LSTCU_Struct {
  uint8_t RESERVED_0[8];
  __IO uint32_t ERR_STAT;                          /**< Error Status, offset: 0x8 */
  uint8_t RESERVED_1[4];
  __IO uint32_t ERR_FM;                            /**< Error Fault Mapping, offset: 0x10 */
  uint8_t RESERVED_2[76];
  __I  uint32_t MB_RSTAT0;                         /**< MBIST Run Status 0, offset: 0x60 */
  __I  uint32_t MB_RSTAT1;                         /**< MBIST Run Status 1, offset: 0x64, not available in all instances (available on 3 out of 12) */
  __I  uint32_t MB_RSTAT2;                         /**< MBIST Run Status 2, offset: 0x68, not available in all instances (available on 1 out of 12) */
  uint8_t RESERVED_3[148];
  __I  uint32_t LB_RSTAT0;                         /**< LBIST Run Status 0, offset: 0x100, not available in all instances (available on 4 out of 12) */
  uint8_t RESERVED_4[124];
  __IO uint32_t MBFM0;                             /**< MBIST Fault Mapping 0, offset: 0x180 */
  __IO uint32_t MBFM1;                             /**< MBIST Fault Mapping 1, offset: 0x184, not available in all instances (available on 3 out of 12) */
  __IO uint32_t MBFM2;                             /**< MBIST Fault Mapping 2, offset: 0x188, not available in all instances (available on 1 out of 12) */
  uint8_t RESERVED_5[148];
  __IO uint32_t LBFM0;                             /**< LBIST Fault Mapping 0, offset: 0x220, not available in all instances (available on 4 out of 12) */
  uint8_t RESERVED_6[60];
  __IO uint32_t STAG;                              /**< Stagger, offset: 0x260 */
  uint8_t RESERVED_7[12];
  __IO uint32_t PH1_DUR;                           /**< Phase 1 Duration, offset: 0x270 */
  __IO uint32_t ISODUR;                            /**< Isolation Duration, offset: 0x274 */
  __IO uint32_t SRCENDUR;                          /**< Synchronous Reset Clock Enable Duration, offset: 0x278 */
  uint8_t RESERVED_8[132];
  __IO uint32_t MBPTR[LSTCU_MBIST_SCH_PTR_COUNT];  /**< MBIST Scheduler Pointer, array offset: 0x300, array step: 0x4, irregular array, not all indices are valid */
  uint8_t RESERVED_9[148];
  __IO uint32_t LBPTR[LSTCU_LBIST_SCH_PTR_COUNT];  /**< LBIST Scheduler Pointer, array offset: 0x3A0, array step: 0x4, not available in all instances (available on 4 out of 12) */
} LSTCU_Type, *LSTCU_MemMapPtr;

/** Number of instances of the LSTCU module. */
#define LSTCU_INSTANCE_COUNT                     (12u)

/* LSTCU - Peripheral instance base addresses */
/** Peripheral CPE_LSTCU base address */
#define IP_CPE_LSTCU_BASE                        (0x9000u)
/** Peripheral CPE_LSTCU base pointer */
#define IP_CPE_LSTCU                             ((LSTCU_Type *)IP_CPE_LSTCU_BASE)
/** Peripheral LPE_LSTCU base address */
#define IP_LPE_LSTCU_BASE                        (0x405C9800u)
/** Peripheral LPE_LSTCU base pointer */
#define IP_LPE_LSTCU                             ((LSTCU_Type *)IP_LPE_LSTCU_BASE)
/** Peripheral LSTCU_1 base address */
#define IP_LSTCU_1_BASE                          (0x405D3800u)
/** Peripheral LSTCU_1 base pointer */
#define IP_LSTCU_1                               ((LSTCU_Type *)IP_LSTCU_1_BASE)
/** Peripheral LSTCU_3 base address */
#define IP_LSTCU_3_BASE                          (0x405D4800u)
/** Peripheral LSTCU_3 base pointer */
#define IP_LSTCU_3                               ((LSTCU_Type *)IP_LSTCU_3_BASE)
/** Peripheral LSTCU_4 base address */
#define IP_LSTCU_4_BASE                          (0x405D5800u)
/** Peripheral LSTCU_4 base pointer */
#define IP_LSTCU_4                               ((LSTCU_Type *)IP_LSTCU_4_BASE)
/** Peripheral LSTCU_SE base address */
#define IP_LSTCU_SE_BASE                         (0x405CE800u)
/** Peripheral LSTCU_SE base pointer */
#define IP_LSTCU_SE                              ((LSTCU_Type *)IP_LSTCU_SE_BASE)
/** Peripheral LSTCU_SOG base address */
#define IP_LSTCU_SOG_BASE                        (0x405CD800u)
/** Peripheral LSTCU_SOG base pointer */
#define IP_LSTCU_SOG                             ((LSTCU_Type *)IP_LSTCU_SOG_BASE)
/** Peripheral LSTCU_SYN_CORE base address */
#define IP_LSTCU_SYN_CORE_BASE                   (0x405D0800u)
/** Peripheral LSTCU_SYN_CORE base pointer */
#define IP_LSTCU_SYN_CORE                        ((LSTCU_Type *)IP_LSTCU_SYN_CORE_BASE)
/** Peripheral LSTCU_SYN_CORE3 base address */
#define IP_LSTCU_SYN_CORE3_BASE                  (0x405D2800u)
/** Peripheral LSTCU_SYN_CORE3 base pointer */
#define IP_LSTCU_SYN_CORE3                       ((LSTCU_Type *)IP_LSTCU_SYN_CORE3_BASE)
/** Peripheral LSTCU_SYN_CORE12 base address */
#define IP_LSTCU_SYN_CORE12_BASE                 (0x405D1800u)
/** Peripheral LSTCU_SYN_CORE12 base pointer */
#define IP_LSTCU_SYN_CORE12                      ((LSTCU_Type *)IP_LSTCU_SYN_CORE12_BASE)
/** Peripheral LSTCU_SYN_HSPI base address */
#define IP_LSTCU_SYN_HSPI_BASE                   (0x405CC800u)
/** Peripheral LSTCU_SYN_HSPI base pointer */
#define IP_LSTCU_SYN_HSPI                        ((LSTCU_Type *)IP_LSTCU_SYN_HSPI_BASE)
/** Peripheral LSTCU_SYN_NETC base address */
#define IP_LSTCU_SYN_NETC_BASE                   (0x405CB800u)
/** Peripheral LSTCU_SYN_NETC base pointer */
#define IP_LSTCU_SYN_NETC                        ((LSTCU_Type *)IP_LSTCU_SYN_NETC_BASE)
/** Array initializer of LSTCU peripheral base addresses */
#define IP_LSTCU_BASE_ADDRS                      { IP_CPE_LSTCU_BASE, IP_LPE_LSTCU_BASE, IP_LSTCU_1_BASE, IP_LSTCU_3_BASE, IP_LSTCU_4_BASE, IP_LSTCU_SE_BASE, IP_LSTCU_SOG_BASE, IP_LSTCU_SYN_CORE_BASE, IP_LSTCU_SYN_CORE3_BASE, IP_LSTCU_SYN_CORE12_BASE, IP_LSTCU_SYN_HSPI_BASE, IP_LSTCU_SYN_NETC_BASE }
/** Array initializer of LSTCU peripheral base pointers */
#define IP_LSTCU_BASE_PTRS                       { IP_CPE_LSTCU, IP_LPE_LSTCU, IP_LSTCU_1, IP_LSTCU_3, IP_LSTCU_4, IP_LSTCU_SE, IP_LSTCU_SOG, IP_LSTCU_SYN_CORE, IP_LSTCU_SYN_CORE3, IP_LSTCU_SYN_CORE12, IP_LSTCU_SYN_HSPI, IP_LSTCU_SYN_NETC }

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

#define LSTCU_MB_RSTAT0_MBSTAT_MASK              (0x3U)
#define LSTCU_MB_RSTAT0_MBSTAT_SHIFT             (0U)
#define LSTCU_MB_RSTAT0_MBSTAT_WIDTH             (2U)
#define LSTCU_MB_RSTAT0_MBSTAT(x)                (((uint32_t)(((uint32_t)(x)) << LSTCU_MB_RSTAT0_MBSTAT_SHIFT)) & LSTCU_MB_RSTAT0_MBSTAT_MASK)
/*! @} */

/*! @name MB_RSTAT1 - MBIST Run Status 1 */
/*! @{ */

#define LSTCU_MB_RSTAT1_MBSTAT_MASK              (0x3U)
#define LSTCU_MB_RSTAT1_MBSTAT_SHIFT             (0U)
#define LSTCU_MB_RSTAT1_MBSTAT_WIDTH             (2U)
#define LSTCU_MB_RSTAT1_MBSTAT(x)                (((uint32_t)(((uint32_t)(x)) << LSTCU_MB_RSTAT1_MBSTAT_SHIFT)) & LSTCU_MB_RSTAT1_MBSTAT_MASK)
/*! @} */

/*! @name MB_RSTAT2 - MBIST Run Status 2 */
/*! @{ */

#define LSTCU_MB_RSTAT2_MBSTAT_MASK              (0x3U)
#define LSTCU_MB_RSTAT2_MBSTAT_SHIFT             (0U)
#define LSTCU_MB_RSTAT2_MBSTAT_WIDTH             (2U)
#define LSTCU_MB_RSTAT2_MBSTAT(x)                (((uint32_t)(((uint32_t)(x)) << LSTCU_MB_RSTAT2_MBSTAT_SHIFT)) & LSTCU_MB_RSTAT2_MBSTAT_MASK)
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

#define LSTCU_MBFM0_MBSTATFM_MASK                (0x3U)
#define LSTCU_MBFM0_MBSTATFM_SHIFT               (0U)
#define LSTCU_MBFM0_MBSTATFM_WIDTH               (2U)
#define LSTCU_MBFM0_MBSTATFM(x)                  (((uint32_t)(((uint32_t)(x)) << LSTCU_MBFM0_MBSTATFM_SHIFT)) & LSTCU_MBFM0_MBSTATFM_MASK)
/*! @} */

/*! @name MBFM1 - MBIST Fault Mapping 1 */
/*! @{ */

#define LSTCU_MBFM1_MBSTATFM_MASK                (0x3U)
#define LSTCU_MBFM1_MBSTATFM_SHIFT               (0U)
#define LSTCU_MBFM1_MBSTATFM_WIDTH               (2U)
#define LSTCU_MBFM1_MBSTATFM(x)                  (((uint32_t)(((uint32_t)(x)) << LSTCU_MBFM1_MBSTATFM_SHIFT)) & LSTCU_MBFM1_MBSTATFM_MASK)
/*! @} */

/*! @name MBFM2 - MBIST Fault Mapping 2 */
/*! @{ */

#define LSTCU_MBFM2_MBSTATFM_MASK                (0x3U)
#define LSTCU_MBFM2_MBSTATFM_SHIFT               (0U)
#define LSTCU_MBFM2_MBSTATFM_WIDTH               (2U)
#define LSTCU_MBFM2_MBSTATFM(x)                  (((uint32_t)(((uint32_t)(x)) << LSTCU_MBFM2_MBSTATFM_SHIFT)) & LSTCU_MBFM2_MBSTATFM_MASK)
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

#endif  /* #if !defined(S32K566_LSTCU_H_) */
