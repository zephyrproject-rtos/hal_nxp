/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_PLL.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_PLL
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
#if !defined(S32K566_PLL_H_)  /* Check if memory map has not been already included */
#define S32K566_PLL_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PLL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLL_Peripheral_Access_Layer PLL Peripheral Access Layer
 * @{
 */

/** PLL - Register Layout Typedef */
typedef struct PLL_Struct {
  struct PLL_CTRL {                                /* offset: 0x0 */
    __IO uint32_t RW;                                /**< PLL Control, offset: 0x0 */
    __IO uint32_t SET;                               /**< PLL Control, offset: 0x4 */
    __IO uint32_t CLR;                               /**< PLL Control, offset: 0x8 */
    __IO uint32_t TOG;                               /**< PLL Control, offset: 0xC */
  } CTRL;
  uint8_t RESERVED_0[48];
  struct PLL_SPREAD_SPECTRUM {                     /* offset: 0x40 */
    __IO uint32_t RW;                                /**< PLL Spread Spectrum, offset: 0x40 */
    __IO uint32_t SET;                               /**< PLL Spread Spectrum, offset: 0x44 */
    __IO uint32_t CLR;                               /**< PLL Spread Spectrum, offset: 0x48 */
    __IO uint32_t TOG;                               /**< PLL Spread Spectrum, offset: 0x4C */
  } SPREAD_SPECTRUM;
  struct PLL_NUMERATOR {                           /* offset: 0x50 */
    __IO uint32_t RW;                                /**< PLL Numerator, offset: 0x50 */
    __IO uint32_t SET;                               /**< PLL Numerator, offset: 0x54 */
    __IO uint32_t CLR;                               /**< PLL Numerator, offset: 0x58 */
    __IO uint32_t TOG;                               /**< PLL Numerator, offset: 0x5C */
  } NUMERATOR;
  struct PLL_DENOMINATOR {                         /* offset: 0x60 */
    __IO uint32_t RW;                                /**< PLL Denominator, offset: 0x60 */
    __IO uint32_t SET;                               /**< PLL Denominator, offset: 0x64 */
    __IO uint32_t CLR;                               /**< PLL Denominator, offset: 0x68 */
    __IO uint32_t TOG;                               /**< PLL Denominator, offset: 0x6C */
  } DENOMINATOR;
  struct PLL_DIV {                                 /* offset: 0x70 */
    __IO uint32_t RW;                                /**< PLL Dividers, offset: 0x70 */
    __IO uint32_t SET;                               /**< PLL Dividers, offset: 0x74 */
    __IO uint32_t CLR;                               /**< PLL Dividers, offset: 0x78 */
    __IO uint32_t TOG;                               /**< PLL Dividers, offset: 0x7C */
  } DIV;
  struct PLL_DFS_CTRL_0 {                          /* offset: 0x80 */
    __IO uint32_t RW;                                /**< DFS Control, offset: 0x80, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t SET;                               /**< DFS Control, offset: 0x84, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t CLR;                               /**< DFS Control, offset: 0x88, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t TOG;                               /**< DFS Control, offset: 0x8C, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
  } DFS_CTRL_0;
  struct PLL_DFS_DIV_0 {                           /* offset: 0x90 */
    __IO uint32_t RW;                                /**< DFS Division, offset: 0x90, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t SET;                               /**< DFS Division, offset: 0x94, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t CLR;                               /**< DFS Division, offset: 0x98, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t TOG;                               /**< DFS Division, offset: 0x9C, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
  } DFS_DIV_0;
  struct PLL_DFS_CTRL_1 {                          /* offset: 0xA0 */
    __IO uint32_t RW;                                /**< DFS Control, offset: 0xA0, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t SET;                               /**< DFS Control, offset: 0xA4, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t CLR;                               /**< DFS Control, offset: 0xA8, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t TOG;                               /**< DFS Control, offset: 0xAC, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
  } DFS_CTRL_1;
  struct PLL_DFS_DIV_1 {                           /* offset: 0xB0 */
    __IO uint32_t RW;                                /**< DFS Division, offset: 0xB0, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t SET;                               /**< DFS Division, offset: 0xB4, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t CLR;                               /**< DFS Division, offset: 0xB8, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t TOG;                               /**< DFS Division, offset: 0xBC, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
  } DFS_DIV_1;
  struct PLL_DFS_CTRL_2 {                          /* offset: 0xC0 */
    __IO uint32_t RW;                                /**< DFS Control, offset: 0xC0, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t SET;                               /**< DFS Control, offset: 0xC4, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t CLR;                               /**< DFS Control, offset: 0xC8, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t TOG;                               /**< DFS Control, offset: 0xCC, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
  } DFS_CTRL_2;
  struct PLL_DFS_DIV_2 {                           /* offset: 0xD0 */
    __IO uint32_t RW;                                /**< DFS Division, offset: 0xD0, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t SET;                               /**< DFS Division, offset: 0xD4, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t CLR;                               /**< DFS Division, offset: 0xD8, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t TOG;                               /**< DFS Division, offset: 0xDC, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
  } DFS_DIV_2;
  struct PLL_DFS_CTRL_3 {                          /* offset: 0xE0 */
    __IO uint32_t RW;                                /**< DFS Control, offset: 0xE0, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t SET;                               /**< DFS Control, offset: 0xE4, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t CLR;                               /**< DFS Control, offset: 0xE8, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t TOG;                               /**< DFS Control, offset: 0xEC, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
  } DFS_CTRL_3;
  struct PLL_DFS_DIV_3 {                           /* offset: 0xF0 */
    __IO uint32_t RW;                                /**< DFS Division, offset: 0xF0, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t SET;                               /**< DFS Division, offset: 0xF4, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t CLR;                               /**< DFS Division, offset: 0xF8, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
    __IO uint32_t TOG;                               /**< DFS Division, offset: 0xFC, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
  } DFS_DIV_3;
  uint8_t RESERVED_1[128];
  __IO uint32_t PLL_OUTPUT_DIVIDER_0;              /**< PLL Output Divider, offset: 0x180 */
  uint8_t RESERVED_2[140];
  struct PLL_PLL_CLK_ODIV {                        /* offset: 0x210 */
    __IO uint32_t RW;                                /**< PLL Clock Output Divider, offset: 0x210 */
    __IO uint32_t SET;                               /**< PLL Clock Output Divider, offset: 0x214 */
    __IO uint32_t CLR;                               /**< PLL Clock Output Divider, offset: 0x218 */
    __IO uint32_t TOG;                               /**< PLL Clock Output Divider, offset: 0x21C */
  } PLL_CLK_ODIV;
  __IO uint32_t PLL_STATUS;                        /**< PLL Status, offset: 0x220 */
  __I  uint32_t DFS_STATUS;                        /**< DFS Status, offset: 0x224, available only on: PLL_0 (missing on CPE_PLL, PLL_1) */
} PLL_Type, *PLL_MemMapPtr;

/** Number of instances of the PLL module. */
#define PLL_INSTANCE_COUNT                       (3u)

/* PLL - Peripheral instance base addresses */
/** Peripheral CPE_PLL base address */
#define IP_CPE_PLL_BASE                          (0x41078000u)
/** Peripheral CPE_PLL base pointer */
#define IP_CPE_PLL                               ((PLL_Type *)IP_CPE_PLL_BASE)
/** Peripheral PLL_0 base address */
#define IP_PLL_0_BASE                            (0x404BC000u)
/** Peripheral PLL_0 base pointer */
#define IP_PLL_0                                 ((PLL_Type *)IP_PLL_0_BASE)
/** Peripheral PLL_1 base address */
#define IP_PLL_1_BASE                            (0x40B40000u)
/** Peripheral PLL_1 base pointer */
#define IP_PLL_1                                 ((PLL_Type *)IP_PLL_1_BASE)
/** Array initializer of PLL peripheral base addresses */
#define IP_PLL_BASE_ADDRS                        { IP_CPE_PLL_BASE, IP_PLL_0_BASE, IP_PLL_1_BASE }
/** Array initializer of PLL peripheral base pointers */
#define IP_PLL_BASE_PTRS                         { IP_CPE_PLL, IP_PLL_0, IP_PLL_1 }

/* ----------------------------------------------------------------------------
   -- PLL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLL_Register_Masks PLL Register Masks
 * @{
 */

/*! @name CTRL - PLL Control */
/*! @{ */

#define PLL_CTRL_POWERUP_MASK                    (0x1U)
#define PLL_CTRL_POWERUP_SHIFT                   (0U)
#define PLL_CTRL_POWERUP_WIDTH                   (1U)
#define PLL_CTRL_POWERUP(x)                      (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_POWERUP_SHIFT)) & PLL_CTRL_POWERUP_MASK)

#define PLL_CTRL_CLKMUX_EN_MASK                  (0x2U)
#define PLL_CTRL_CLKMUX_EN_SHIFT                 (1U)
#define PLL_CTRL_CLKMUX_EN_WIDTH                 (1U)
#define PLL_CTRL_CLKMUX_EN(x)                    (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_CLKMUX_EN_SHIFT)) & PLL_CTRL_CLKMUX_EN_MASK)

#define PLL_CTRL_REFCLKOUT_EN_MASK               (0x8U)
#define PLL_CTRL_REFCLKOUT_EN_SHIFT              (3U)
#define PLL_CTRL_REFCLKOUT_EN_WIDTH              (1U)
#define PLL_CTRL_REFCLKOUT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_REFCLKOUT_EN_SHIFT)) & PLL_CTRL_REFCLKOUT_EN_MASK)

#define PLL_CTRL_SPREADCTL_MASK                  (0x100U)
#define PLL_CTRL_SPREADCTL_SHIFT                 (8U)
#define PLL_CTRL_SPREADCTL_WIDTH                 (1U)
#define PLL_CTRL_SPREADCTL(x)                    (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_SPREADCTL_SHIFT)) & PLL_CTRL_SPREADCTL_MASK)

#define PLL_CTRL_MULTIPHASE_SDM_DISABLE_MASK     (0x1000U)
#define PLL_CTRL_MULTIPHASE_SDM_DISABLE_SHIFT    (12U)
#define PLL_CTRL_MULTIPHASE_SDM_DISABLE_WIDTH    (1U)
#define PLL_CTRL_MULTIPHASE_SDM_DISABLE(x)       (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_MULTIPHASE_SDM_DISABLE_SHIFT)) & PLL_CTRL_MULTIPHASE_SDM_DISABLE_MASK)

#define PLL_CTRL_REF_CLK_SEL_MASK                (0x10000U)
#define PLL_CTRL_REF_CLK_SEL_SHIFT               (16U)
#define PLL_CTRL_REF_CLK_SEL_WIDTH               (1U)
#define PLL_CTRL_REF_CLK_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_REF_CLK_SEL_SHIFT)) & PLL_CTRL_REF_CLK_SEL_MASK)
/*! @} */

/*! @name SPREAD_SPECTRUM - PLL Spread Spectrum */
/*! @{ */

#define PLL_SPREAD_SPECTRUM_STEP_MASK            (0x7FFFU)
#define PLL_SPREAD_SPECTRUM_STEP_SHIFT           (0U)
#define PLL_SPREAD_SPECTRUM_STEP_WIDTH           (15U)
#define PLL_SPREAD_SPECTRUM_STEP(x)              (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_STEP_SHIFT)) & PLL_SPREAD_SPECTRUM_STEP_MASK)

#define PLL_SPREAD_SPECTRUM_ENABLE_MASK          (0x8000U)
#define PLL_SPREAD_SPECTRUM_ENABLE_SHIFT         (15U)
#define PLL_SPREAD_SPECTRUM_ENABLE_WIDTH         (1U)
#define PLL_SPREAD_SPECTRUM_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_ENABLE_SHIFT)) & PLL_SPREAD_SPECTRUM_ENABLE_MASK)

#define PLL_SPREAD_SPECTRUM_STOP_MASK            (0xFFFF0000U)
#define PLL_SPREAD_SPECTRUM_STOP_SHIFT           (16U)
#define PLL_SPREAD_SPECTRUM_STOP_WIDTH           (16U)
#define PLL_SPREAD_SPECTRUM_STOP(x)              (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_STOP_SHIFT)) & PLL_SPREAD_SPECTRUM_STOP_MASK)
/*! @} */

/*! @name NUMERATOR - PLL Numerator */
/*! @{ */

#define PLL_NUMERATOR_MFN_MASK                   (0xFFFFFFFCU)
#define PLL_NUMERATOR_MFN_SHIFT                  (2U)
#define PLL_NUMERATOR_MFN_WIDTH                  (30U)
#define PLL_NUMERATOR_MFN(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_NUMERATOR_MFN_SHIFT)) & PLL_NUMERATOR_MFN_MASK)
/*! @} */

/*! @name DENOMINATOR - PLL Denominator */
/*! @{ */

#define PLL_DENOMINATOR_MFD_MASK                 (0x3FFFFFFFU)
#define PLL_DENOMINATOR_MFD_SHIFT                (0U)
#define PLL_DENOMINATOR_MFD_WIDTH                (30U)
#define PLL_DENOMINATOR_MFD(x)                   (((uint32_t)(((uint32_t)(x)) << PLL_DENOMINATOR_MFD_SHIFT)) & PLL_DENOMINATOR_MFD_MASK)
/*! @} */

/*! @name DIV - PLL Dividers */
/*! @{ */

#define PLL_DIV_RDIV_MASK                        (0xE000U)
#define PLL_DIV_RDIV_SHIFT                       (13U)
#define PLL_DIV_RDIV_WIDTH                       (3U)
#define PLL_DIV_RDIV(x)                          (((uint32_t)(((uint32_t)(x)) << PLL_DIV_RDIV_SHIFT)) & PLL_DIV_RDIV_MASK)

#define PLL_DIV_MFI_MASK                         (0x1FF0000U)
#define PLL_DIV_MFI_SHIFT                        (16U)
#define PLL_DIV_MFI_WIDTH                        (9U)
#define PLL_DIV_MFI(x)                           (((uint32_t)(((uint32_t)(x)) << PLL_DIV_MFI_SHIFT)) & PLL_DIV_MFI_MASK)
/*! @} */

/*! @name DFS_CTRL_0 - DFS Control */
/*! @{ */

#define PLL_DFS_CTRL_0_BYPASS_EN_MASK            (0x800000U)
#define PLL_DFS_CTRL_0_BYPASS_EN_SHIFT           (23U)
#define PLL_DFS_CTRL_0_BYPASS_EN_WIDTH           (1U)
#define PLL_DFS_CTRL_0_BYPASS_EN(x)              (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_0_BYPASS_EN_SHIFT)) & PLL_DFS_CTRL_0_BYPASS_EN_MASK)

#define PLL_DFS_CTRL_0_CLKOUT_EN_MASK            (0x40000000U)
#define PLL_DFS_CTRL_0_CLKOUT_EN_SHIFT           (30U)
#define PLL_DFS_CTRL_0_CLKOUT_EN_WIDTH           (1U)
#define PLL_DFS_CTRL_0_CLKOUT_EN(x)              (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_0_CLKOUT_EN_SHIFT)) & PLL_DFS_CTRL_0_CLKOUT_EN_MASK)

#define PLL_DFS_CTRL_0_ENABLE_MASK               (0x80000000U)
#define PLL_DFS_CTRL_0_ENABLE_SHIFT              (31U)
#define PLL_DFS_CTRL_0_ENABLE_WIDTH              (1U)
#define PLL_DFS_CTRL_0_ENABLE(x)                 (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_0_ENABLE_SHIFT)) & PLL_DFS_CTRL_0_ENABLE_MASK)
/*! @} */

/*! @name DFS_DIV_0 - DFS Division */
/*! @{ */

#define PLL_DFS_DIV_0_MFN_MASK                   (0x7U)
#define PLL_DFS_DIV_0_MFN_SHIFT                  (0U)
#define PLL_DFS_DIV_0_MFN_WIDTH                  (3U)
#define PLL_DFS_DIV_0_MFN(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_DFS_DIV_0_MFN_SHIFT)) & PLL_DFS_DIV_0_MFN_MASK)

#define PLL_DFS_DIV_0_MFI_MASK                   (0xFF00U)
#define PLL_DFS_DIV_0_MFI_SHIFT                  (8U)
#define PLL_DFS_DIV_0_MFI_WIDTH                  (8U)
#define PLL_DFS_DIV_0_MFI(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_DFS_DIV_0_MFI_SHIFT)) & PLL_DFS_DIV_0_MFI_MASK)
/*! @} */

/*! @name DFS_CTRL_1 - DFS Control */
/*! @{ */

#define PLL_DFS_CTRL_1_BYPASS_EN_MASK            (0x800000U)
#define PLL_DFS_CTRL_1_BYPASS_EN_SHIFT           (23U)
#define PLL_DFS_CTRL_1_BYPASS_EN_WIDTH           (1U)
#define PLL_DFS_CTRL_1_BYPASS_EN(x)              (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_1_BYPASS_EN_SHIFT)) & PLL_DFS_CTRL_1_BYPASS_EN_MASK)

#define PLL_DFS_CTRL_1_CLKOUT_EN_MASK            (0x40000000U)
#define PLL_DFS_CTRL_1_CLKOUT_EN_SHIFT           (30U)
#define PLL_DFS_CTRL_1_CLKOUT_EN_WIDTH           (1U)
#define PLL_DFS_CTRL_1_CLKOUT_EN(x)              (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_1_CLKOUT_EN_SHIFT)) & PLL_DFS_CTRL_1_CLKOUT_EN_MASK)

#define PLL_DFS_CTRL_1_ENABLE_MASK               (0x80000000U)
#define PLL_DFS_CTRL_1_ENABLE_SHIFT              (31U)
#define PLL_DFS_CTRL_1_ENABLE_WIDTH              (1U)
#define PLL_DFS_CTRL_1_ENABLE(x)                 (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_1_ENABLE_SHIFT)) & PLL_DFS_CTRL_1_ENABLE_MASK)
/*! @} */

/*! @name DFS_DIV_1 - DFS Division */
/*! @{ */

#define PLL_DFS_DIV_1_MFN_MASK                   (0x7U)
#define PLL_DFS_DIV_1_MFN_SHIFT                  (0U)
#define PLL_DFS_DIV_1_MFN_WIDTH                  (3U)
#define PLL_DFS_DIV_1_MFN(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_DFS_DIV_1_MFN_SHIFT)) & PLL_DFS_DIV_1_MFN_MASK)

#define PLL_DFS_DIV_1_MFI_MASK                   (0xFF00U)
#define PLL_DFS_DIV_1_MFI_SHIFT                  (8U)
#define PLL_DFS_DIV_1_MFI_WIDTH                  (8U)
#define PLL_DFS_DIV_1_MFI(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_DFS_DIV_1_MFI_SHIFT)) & PLL_DFS_DIV_1_MFI_MASK)
/*! @} */

/*! @name DFS_CTRL_2 - DFS Control */
/*! @{ */

#define PLL_DFS_CTRL_2_BYPASS_EN_MASK            (0x800000U)
#define PLL_DFS_CTRL_2_BYPASS_EN_SHIFT           (23U)
#define PLL_DFS_CTRL_2_BYPASS_EN_WIDTH           (1U)
#define PLL_DFS_CTRL_2_BYPASS_EN(x)              (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_2_BYPASS_EN_SHIFT)) & PLL_DFS_CTRL_2_BYPASS_EN_MASK)

#define PLL_DFS_CTRL_2_CLKOUT_EN_MASK            (0x40000000U)
#define PLL_DFS_CTRL_2_CLKOUT_EN_SHIFT           (30U)
#define PLL_DFS_CTRL_2_CLKOUT_EN_WIDTH           (1U)
#define PLL_DFS_CTRL_2_CLKOUT_EN(x)              (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_2_CLKOUT_EN_SHIFT)) & PLL_DFS_CTRL_2_CLKOUT_EN_MASK)

#define PLL_DFS_CTRL_2_ENABLE_MASK               (0x80000000U)
#define PLL_DFS_CTRL_2_ENABLE_SHIFT              (31U)
#define PLL_DFS_CTRL_2_ENABLE_WIDTH              (1U)
#define PLL_DFS_CTRL_2_ENABLE(x)                 (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_2_ENABLE_SHIFT)) & PLL_DFS_CTRL_2_ENABLE_MASK)
/*! @} */

/*! @name DFS_DIV_2 - DFS Division */
/*! @{ */

#define PLL_DFS_DIV_2_MFN_MASK                   (0x7U)
#define PLL_DFS_DIV_2_MFN_SHIFT                  (0U)
#define PLL_DFS_DIV_2_MFN_WIDTH                  (3U)
#define PLL_DFS_DIV_2_MFN(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_DFS_DIV_2_MFN_SHIFT)) & PLL_DFS_DIV_2_MFN_MASK)

#define PLL_DFS_DIV_2_MFI_MASK                   (0xFF00U)
#define PLL_DFS_DIV_2_MFI_SHIFT                  (8U)
#define PLL_DFS_DIV_2_MFI_WIDTH                  (8U)
#define PLL_DFS_DIV_2_MFI(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_DFS_DIV_2_MFI_SHIFT)) & PLL_DFS_DIV_2_MFI_MASK)
/*! @} */

/*! @name DFS_CTRL_3 - DFS Control */
/*! @{ */

#define PLL_DFS_CTRL_3_BYPASS_EN_MASK            (0x800000U)
#define PLL_DFS_CTRL_3_BYPASS_EN_SHIFT           (23U)
#define PLL_DFS_CTRL_3_BYPASS_EN_WIDTH           (1U)
#define PLL_DFS_CTRL_3_BYPASS_EN(x)              (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_3_BYPASS_EN_SHIFT)) & PLL_DFS_CTRL_3_BYPASS_EN_MASK)

#define PLL_DFS_CTRL_3_CLKOUT_EN_MASK            (0x40000000U)
#define PLL_DFS_CTRL_3_CLKOUT_EN_SHIFT           (30U)
#define PLL_DFS_CTRL_3_CLKOUT_EN_WIDTH           (1U)
#define PLL_DFS_CTRL_3_CLKOUT_EN(x)              (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_3_CLKOUT_EN_SHIFT)) & PLL_DFS_CTRL_3_CLKOUT_EN_MASK)

#define PLL_DFS_CTRL_3_ENABLE_MASK               (0x80000000U)
#define PLL_DFS_CTRL_3_ENABLE_SHIFT              (31U)
#define PLL_DFS_CTRL_3_ENABLE_WIDTH              (1U)
#define PLL_DFS_CTRL_3_ENABLE(x)                 (((uint32_t)(((uint32_t)(x)) << PLL_DFS_CTRL_3_ENABLE_SHIFT)) & PLL_DFS_CTRL_3_ENABLE_MASK)
/*! @} */

/*! @name DFS_DIV_3 - DFS Division */
/*! @{ */

#define PLL_DFS_DIV_3_MFN_MASK                   (0x7U)
#define PLL_DFS_DIV_3_MFN_SHIFT                  (0U)
#define PLL_DFS_DIV_3_MFN_WIDTH                  (3U)
#define PLL_DFS_DIV_3_MFN(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_DFS_DIV_3_MFN_SHIFT)) & PLL_DFS_DIV_3_MFN_MASK)

#define PLL_DFS_DIV_3_MFI_MASK                   (0xFF00U)
#define PLL_DFS_DIV_3_MFI_SHIFT                  (8U)
#define PLL_DFS_DIV_3_MFI_WIDTH                  (8U)
#define PLL_DFS_DIV_3_MFI(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_DFS_DIV_3_MFI_SHIFT)) & PLL_DFS_DIV_3_MFI_MASK)
/*! @} */

/*! @name PLL_OUTPUT_DIVIDER_0 - PLL Output Divider */
/*! @{ */

#define PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_MASK (0xFF0000U)
#define PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_SHIFT (16U)
#define PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_WIDTH (8U)
#define PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV(x)   (((uint32_t)(((uint32_t)(x)) << PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_SHIFT)) & PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_MASK)

#define PLL_PLL_OUTPUT_DIVIDER_0_DE_MASK         (0x80000000U)
#define PLL_PLL_OUTPUT_DIVIDER_0_DE_SHIFT        (31U)
#define PLL_PLL_OUTPUT_DIVIDER_0_DE_WIDTH        (1U)
#define PLL_PLL_OUTPUT_DIVIDER_0_DE(x)           (((uint32_t)(((uint32_t)(x)) << PLL_PLL_OUTPUT_DIVIDER_0_DE_SHIFT)) & PLL_PLL_OUTPUT_DIVIDER_0_DE_MASK)
/*! @} */

/*! @name PLL_CLK_ODIV - PLL Clock Output Divider */
/*! @{ */

#define PLL_PLL_CLK_ODIV_ODIV_MASK               (0xFFU)
#define PLL_PLL_CLK_ODIV_ODIV_SHIFT              (0U)
#define PLL_PLL_CLK_ODIV_ODIV_WIDTH              (8U)
#define PLL_PLL_CLK_ODIV_ODIV(x)                 (((uint32_t)(((uint32_t)(x)) << PLL_PLL_CLK_ODIV_ODIV_SHIFT)) & PLL_PLL_CLK_ODIV_ODIV_MASK)
/*! @} */

/*! @name PLL_STATUS - PLL Status */
/*! @{ */

#define PLL_PLL_STATUS_PLL_LOCK_MASK             (0x1U)
#define PLL_PLL_STATUS_PLL_LOCK_SHIFT            (0U)
#define PLL_PLL_STATUS_PLL_LOCK_WIDTH            (1U)
#define PLL_PLL_STATUS_PLL_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << PLL_PLL_STATUS_PLL_LOCK_SHIFT)) & PLL_PLL_STATUS_PLL_LOCK_MASK)

#define PLL_PLL_STATUS_PLL_LOL_MASK              (0x2U)
#define PLL_PLL_STATUS_PLL_LOL_SHIFT             (1U)
#define PLL_PLL_STATUS_PLL_LOL_WIDTH             (1U)
#define PLL_PLL_STATUS_PLL_LOL(x)                (((uint32_t)(((uint32_t)(x)) << PLL_PLL_STATUS_PLL_LOL_SHIFT)) & PLL_PLL_STATUS_PLL_LOL_MASK)

#define PLL_PLL_STATUS_ANA_MFN_MASK              (0xFFFFFFFCU)
#define PLL_PLL_STATUS_ANA_MFN_SHIFT             (2U)
#define PLL_PLL_STATUS_ANA_MFN_WIDTH             (30U)
#define PLL_PLL_STATUS_ANA_MFN(x)                (((uint32_t)(((uint32_t)(x)) << PLL_PLL_STATUS_ANA_MFN_SHIFT)) & PLL_PLL_STATUS_ANA_MFN_MASK)
/*! @} */

/*! @name DFS_STATUS - DFS Status */
/*! @{ */

#define PLL_DFS_STATUS_DFS_OK_MASK               (0xFU)
#define PLL_DFS_STATUS_DFS_OK_SHIFT              (0U)
#define PLL_DFS_STATUS_DFS_OK_WIDTH              (4U)
#define PLL_DFS_STATUS_DFS_OK(x)                 (((uint32_t)(((uint32_t)(x)) << PLL_DFS_STATUS_DFS_OK_SHIFT)) & PLL_DFS_STATUS_DFS_OK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PLL_Register_Masks */

/*!
 * @}
 */ /* end of group PLL_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_PLL_H_) */
