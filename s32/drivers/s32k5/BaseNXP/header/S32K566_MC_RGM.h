/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_MC_RGM.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_MC_RGM
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
#if !defined(S32K566_MC_RGM_H_)  /* Check if memory map has not been already included */
#define S32K566_MC_RGM_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MC_RGM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_RGM_Peripheral_Access_Layer MC_RGM Peripheral Access Layer
 * @{
 */

/** MC_RGM - Size of Registers Arrays */
#define MC_RGM_BOOT_CFG_COUNT                     2u

/** MC_RGM - Register Layout Typedef */
typedef struct MC_RGM_Struct {
  __IO uint32_t DES;                               /**< Destructive Event Status Register, offset: 0x0 */
  __IO uint32_t DERD;                              /**< Destructive Event Reset Disable Register, offset: 0x4 */
  __IO uint32_t FES;                               /**< Functional /External Reset Status Register, offset: 0x8 */
  __IO uint32_t FERD;                              /**< Functional Event Reset Disable Register, offset: 0xC */
  uint8_t RESERVED_0[4];
  __IO uint32_t FREC;                              /**< Functional Reset Escalation Counter Register, offset: 0x14 */
  __IO uint32_t FRET;                              /**< Functional Reset Escalation Threshold Register, offset: 0x18 */
  __IO uint32_t DRET;                              /**< Destructive Reset Escalation Threshold Register, offset: 0x1C */
  __IO uint32_t ERCTRL;                            /**< External Reset Control Register, offset: 0x20 */
  uint8_t RESERVED_1[16];
  __IO uint32_t REDL;                              /**< Reset Event During LPRUN, offset: 0x34 */
  uint8_t RESERVED_2[8];
  __IO uint32_t PRST0_0;                           /**< Peripheral Reset, offset: 0x40 */
  uint8_t RESERVED_3[4];
  __IO uint32_t PRST1_0;                           /**< Peripheral Reset, offset: 0x48 */
  uint8_t RESERVED_4[4];
  __IO uint32_t PRST2_0;                           /**< Peripheral Reset, offset: 0x50 */
  uint8_t RESERVED_5[4];
  __IO uint32_t PRST3_0;                           /**< Peripheral Reset, offset: 0x58 */
  uint8_t RESERVED_6[4];
  __IO uint32_t PRST4_0;                           /**< Peripheral Reset, offset: 0x60 */
  uint8_t RESERVED_7[4];
  __IO uint32_t PRST5_0;                           /**< Peripheral Reset, offset: 0x68 */
  uint8_t RESERVED_8[4];
  __IO uint32_t PRST6_0;                           /**< Peripheral Reset, offset: 0x70 */
  uint8_t RESERVED_9[4];
  __IO uint32_t PRST7_0;                           /**< Peripheral Reset, offset: 0x78 */
  uint8_t RESERVED_10[196];
  __I  uint32_t PSTAT0_0;                          /**< Peripheral Reset Status Register, offset: 0x140 */
  uint8_t RESERVED_11[4];
  __I  uint32_t PSTAT1_0;                          /**< Peripheral Reset Status Register, offset: 0x148 */
  uint8_t RESERVED_12[4];
  __I  uint32_t PSTAT2_0;                          /**< Peripheral Reset Status Register, offset: 0x150 */
  uint8_t RESERVED_13[4];
  __I  uint32_t PSTAT3_0;                          /**< Peripheral Reset Status Register, offset: 0x158 */
  uint8_t RESERVED_14[4];
  __I  uint32_t PSTAT4_0;                          /**< Peripheral Reset Status Register, offset: 0x160 */
  uint8_t RESERVED_15[4];
  __I  uint32_t PSTAT5_0;                          /**< Peripheral Reset Status Register, offset: 0x168 */
  uint8_t RESERVED_16[4];
  __I  uint32_t PSTAT6_0;                          /**< Peripheral Reset Status Register, offset: 0x170 */
  uint8_t RESERVED_17[4];
  __I  uint32_t PSTAT7_0;                          /**< Peripheral Reset Status Register, offset: 0x178 */
  uint8_t RESERVED_18[212];
  __IO uint32_t PRST_LPC;                          /**< Peripheral Reset LP Core, offset: 0x250 */
  __I  uint32_t PLPCSTAT;                          /**< Peripheral LP Core Status, offset: 0x254 */
  uint8_t RESERVED_19[8];
  __IO uint32_t CTL_KEY;                           /**< Control Key Register, offset: 0x260 */
  __IO uint32_t MODE_CONF;                         /**< Mode Configuration Register, offset: 0x264 */
  uint8_t RESERVED_20[8];
  __IO uint32_t EVT_STAT;                          /**< Event Status, offset: 0x270 */
  __IO uint32_t FPHTEC;                            /**< Functional Reset Entry Phase Timer Enable Control, offset: 0x274 */
  __IO uint32_t FPHTV;                             /**< Functional Reset Entry Phase Timer Value, offset: 0x278 */
  __IO uint32_t FPHTC;                             /**< Functional Reset Entry Phase Timer Control, offset: 0x27C */
  __IO uint32_t FPHTES;                            /**< Functional Reset Entry Phase Timer Expiry Status, offset: 0x280 */
  __I  uint32_t BOOT_VAL;                          /**< Boot Mode Value, offset: 0x284 */
  uint8_t RESERVED_21[8];
  __IO uint32_t BOOT_CFG[MC_RGM_BOOT_CFG_COUNT];   /**< Boot Configurations, array offset: 0x290, array step: 0x4 */
  uint8_t RESERVED_22[24];
  __IO uint32_t STDBYRTR;                          /**< Standby Request Timeout Register, offset: 0x2B0 */
  __I  uint32_t MODE_STAT;                         /**< Mode Status Register, offset: 0x2B4 */
  __IO uint32_t DRATO;                             /**< Destructive Request Acknowledge Timeout Register, offset: 0x2B8 */
} MC_RGM_Type, *MC_RGM_MemMapPtr;

/** Number of instances of the MC_RGM module. */
#define MC_RGM_INSTANCE_COUNT                    (1u)

/* MC_RGM - Peripheral instance base addresses */
/** Peripheral LPE_MC_RGM base address */
#define IP_LPE_MC_RGM_BASE                       (0x42074000u)
/** Peripheral LPE_MC_RGM base pointer */
#define IP_LPE_MC_RGM                            ((MC_RGM_Type *)IP_LPE_MC_RGM_BASE)
/** Array initializer of MC_RGM peripheral base addresses */
#define IP_MC_RGM_BASE_ADDRS                     { IP_LPE_MC_RGM_BASE }
/** Array initializer of MC_RGM peripheral base pointers */
#define IP_MC_RGM_BASE_PTRS                      { IP_LPE_MC_RGM }

/* ----------------------------------------------------------------------------
   -- MC_RGM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_RGM_Register_Masks MC_RGM Register Masks
 * @{
 */

/*! @name DES - Destructive Event Status Register */
/*! @{ */

#define MC_RGM_DES_F_DR_0_MASK                   (0x1U)
#define MC_RGM_DES_F_DR_0_SHIFT                  (0U)
#define MC_RGM_DES_F_DR_0_WIDTH                  (1U)
#define MC_RGM_DES_F_DR_0(x)                     (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_F_DR_0_SHIFT)) & MC_RGM_DES_F_DR_0_MASK)

#define MC_RGM_DES_F_DR_1_MASK                   (0x2U)
#define MC_RGM_DES_F_DR_1_SHIFT                  (1U)
#define MC_RGM_DES_F_DR_1_WIDTH                  (1U)
#define MC_RGM_DES_F_DR_1(x)                     (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_F_DR_1_SHIFT)) & MC_RGM_DES_F_DR_1_MASK)

#define MC_RGM_DES_F_DR_2_MASK                   (0x4U)
#define MC_RGM_DES_F_DR_2_SHIFT                  (2U)
#define MC_RGM_DES_F_DR_2_WIDTH                  (1U)
#define MC_RGM_DES_F_DR_2(x)                     (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_F_DR_2_SHIFT)) & MC_RGM_DES_F_DR_2_MASK)

#define MC_RGM_DES_F_DR_3_MASK                   (0x8U)
#define MC_RGM_DES_F_DR_3_SHIFT                  (3U)
#define MC_RGM_DES_F_DR_3_WIDTH                  (1U)
#define MC_RGM_DES_F_DR_3(x)                     (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_F_DR_3_SHIFT)) & MC_RGM_DES_F_DR_3_MASK)

#define MC_RGM_DES_RGM_FRE_MASK                  (0x400U)
#define MC_RGM_DES_RGM_FRE_SHIFT                 (10U)
#define MC_RGM_DES_RGM_FRE_WIDTH                 (1U)
#define MC_RGM_DES_RGM_FRE(x)                    (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_RGM_FRE_SHIFT)) & MC_RGM_DES_RGM_FRE_MASK)

#define MC_RGM_DES_PLL0_LOL_MASK                 (0x800U)
#define MC_RGM_DES_PLL0_LOL_SHIFT                (11U)
#define MC_RGM_DES_PLL0_LOL_WIDTH                (1U)
#define MC_RGM_DES_PLL0_LOL(x)                   (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_PLL0_LOL_SHIFT)) & MC_RGM_DES_PLL0_LOL_MASK)

#define MC_RGM_DES_SW_DEST_RST_MASK              (0x1000U)
#define MC_RGM_DES_SW_DEST_RST_SHIFT             (12U)
#define MC_RGM_DES_SW_DEST_RST_WIDTH             (1U)
#define MC_RGM_DES_SW_DEST_RST(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_SW_DEST_RST_SHIFT)) & MC_RGM_DES_SW_DEST_RST_MASK)

#define MC_RGM_DES_CPE_PLL_LOL_MASK              (0x2000U)
#define MC_RGM_DES_CPE_PLL_LOL_SHIFT             (13U)
#define MC_RGM_DES_CPE_PLL_LOL_WIDTH             (1U)
#define MC_RGM_DES_CPE_PLL_LOL(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_CPE_PLL_LOL_SHIFT)) & MC_RGM_DES_CPE_PLL_LOL_MASK)

#define MC_RGM_DES_CSTCU_URF_MASK                (0x4000U)
#define MC_RGM_DES_CSTCU_URF_SHIFT               (14U)
#define MC_RGM_DES_CSTCU_URF_WIDTH               (1U)
#define MC_RGM_DES_CSTCU_URF(x)                  (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_CSTCU_URF_SHIFT)) & MC_RGM_DES_CSTCU_URF_MASK)

#define MC_RGM_DES_DEBUG_DEST_RST_MASK           (0x8000U)
#define MC_RGM_DES_DEBUG_DEST_RST_SHIFT          (15U)
#define MC_RGM_DES_DEBUG_DEST_RST_WIDTH          (1U)
#define MC_RGM_DES_DEBUG_DEST_RST(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_DEBUG_DEST_RST_SHIFT)) & MC_RGM_DES_DEBUG_DEST_RST_MASK)

#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_32k_RESET_REQ_B_MASK (0x10000U)
#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_32k_RESET_REQ_B_SHIFT (16U)
#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_32k_RESET_REQ_B_WIDTH (1U)
#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_32k_RESET_REQ_B(x) (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_HSE2_TOP__S4v1_LMDA_32k_RESET_REQ_B_SHIFT)) & MC_RGM_DES_HSE2_TOP__S4v1_LMDA_32k_RESET_REQ_B_MASK)

#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_RESET_REQ_B_MASK (0x20000U)
#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_RESET_REQ_B_SHIFT (17U)
#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_RESET_REQ_B_WIDTH (1U)
#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_RESET_REQ_B(x) (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_HSE2_TOP__S4v1_LMDA_RESET_REQ_B_SHIFT)) & MC_RGM_DES_HSE2_TOP__S4v1_LMDA_RESET_REQ_B_MASK)

#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_SYS_FAIL_MASK (0x40000U)
#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_SYS_FAIL_SHIFT (18U)
#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_SYS_FAIL_WIDTH (1U)
#define MC_RGM_DES_HSE2_TOP__S4v1_LMDA_SYS_FAIL(x) (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_HSE2_TOP__S4v1_LMDA_SYS_FAIL_SHIFT)) & MC_RGM_DES_HSE2_TOP__S4v1_LMDA_SYS_FAIL_MASK)

#define MC_RGM_DES_HSE2_TOP__S4v1_EVENT_SYS_RESET_REQ_MASK (0x80000U)
#define MC_RGM_DES_HSE2_TOP__S4v1_EVENT_SYS_RESET_REQ_SHIFT (19U)
#define MC_RGM_DES_HSE2_TOP__S4v1_EVENT_SYS_RESET_REQ_WIDTH (1U)
#define MC_RGM_DES_HSE2_TOP__S4v1_EVENT_SYS_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_HSE2_TOP__S4v1_EVENT_SYS_RESET_REQ_SHIFT)) & MC_RGM_DES_HSE2_TOP__S4v1_EVENT_SYS_RESET_REQ_MASK)

#define MC_RGM_DES_SYS_DIV_FAIL_MASK             (0x100000U)
#define MC_RGM_DES_SYS_DIV_FAIL_SHIFT            (20U)
#define MC_RGM_DES_SYS_DIV_FAIL_WIDTH            (1U)
#define MC_RGM_DES_SYS_DIV_FAIL(x)               (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_SYS_DIV_FAIL_SHIFT)) & MC_RGM_DES_SYS_DIV_FAIL_MASK)

#define MC_RGM_DES_VFCCU_DEST_RST_MASK           (0x200000U)
#define MC_RGM_DES_VFCCU_DEST_RST_SHIFT          (21U)
#define MC_RGM_DES_VFCCU_DEST_RST_WIDTH          (1U)
#define MC_RGM_DES_VFCCU_DEST_RST(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_VFCCU_DEST_RST_SHIFT)) & MC_RGM_DES_VFCCU_DEST_RST_MASK)

#define MC_RGM_DES_CSTCU_DEST_MASK               (0x1000000U)
#define MC_RGM_DES_CSTCU_DEST_SHIFT              (24U)
#define MC_RGM_DES_CSTCU_DEST_WIDTH              (1U)
#define MC_RGM_DES_CSTCU_DEST(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_CSTCU_DEST_SHIFT)) & MC_RGM_DES_CSTCU_DEST_MASK)

#define MC_RGM_DES_FUNC_RST_ENTRY_TIMEOUT_MASK   (0x2000000U)
#define MC_RGM_DES_FUNC_RST_ENTRY_TIMEOUT_SHIFT  (25U)
#define MC_RGM_DES_FUNC_RST_ENTRY_TIMEOUT_WIDTH  (1U)
#define MC_RGM_DES_FUNC_RST_ENTRY_TIMEOUT(x)     (((uint32_t)(((uint32_t)(x)) << MC_RGM_DES_FUNC_RST_ENTRY_TIMEOUT_SHIFT)) & MC_RGM_DES_FUNC_RST_ENTRY_TIMEOUT_MASK)
/*! @} */

/*! @name DERD - Destructive Event Reset Disable Register */
/*! @{ */

#define MC_RGM_DERD_D_F_DR_0_MASK                (0x1U)
#define MC_RGM_DERD_D_F_DR_0_SHIFT               (0U)
#define MC_RGM_DERD_D_F_DR_0_WIDTH               (1U)
#define MC_RGM_DERD_D_F_DR_0(x)                  (((uint32_t)(((uint32_t)(x)) << MC_RGM_DERD_D_F_DR_0_SHIFT)) & MC_RGM_DERD_D_F_DR_0_MASK)

#define MC_RGM_DERD_D_F_DR_1_MASK                (0x2U)
#define MC_RGM_DERD_D_F_DR_1_SHIFT               (1U)
#define MC_RGM_DERD_D_F_DR_1_WIDTH               (1U)
#define MC_RGM_DERD_D_F_DR_1(x)                  (((uint32_t)(((uint32_t)(x)) << MC_RGM_DERD_D_F_DR_1_SHIFT)) & MC_RGM_DERD_D_F_DR_1_MASK)

#define MC_RGM_DERD_D_F_DR_2_MASK                (0x4U)
#define MC_RGM_DERD_D_F_DR_2_SHIFT               (2U)
#define MC_RGM_DERD_D_F_DR_2_WIDTH               (1U)
#define MC_RGM_DERD_D_F_DR_2(x)                  (((uint32_t)(((uint32_t)(x)) << MC_RGM_DERD_D_F_DR_2_SHIFT)) & MC_RGM_DERD_D_F_DR_2_MASK)

#define MC_RGM_DERD_D_F_DR_3_MASK                (0x8U)
#define MC_RGM_DERD_D_F_DR_3_SHIFT               (3U)
#define MC_RGM_DERD_D_F_DR_3_WIDTH               (1U)
#define MC_RGM_DERD_D_F_DR_3(x)                  (((uint32_t)(((uint32_t)(x)) << MC_RGM_DERD_D_F_DR_3_SHIFT)) & MC_RGM_DERD_D_F_DR_3_MASK)

#define MC_RGM_DERD_D_PLL0_LOL_MASK              (0x800U)
#define MC_RGM_DERD_D_PLL0_LOL_SHIFT             (11U)
#define MC_RGM_DERD_D_PLL0_LOL_WIDTH             (1U)
#define MC_RGM_DERD_D_PLL0_LOL(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_DERD_D_PLL0_LOL_SHIFT)) & MC_RGM_DERD_D_PLL0_LOL_MASK)

#define MC_RGM_DERD_D_CPE_PLL_LOL_MASK           (0x2000U)
#define MC_RGM_DERD_D_CPE_PLL_LOL_SHIFT          (13U)
#define MC_RGM_DERD_D_CPE_PLL_LOL_WIDTH          (1U)
#define MC_RGM_DERD_D_CPE_PLL_LOL(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_DERD_D_CPE_PLL_LOL_SHIFT)) & MC_RGM_DERD_D_CPE_PLL_LOL_MASK)

#define MC_RGM_DERD_D_DEBUG_DEST_RST_MASK        (0x8000U)
#define MC_RGM_DERD_D_DEBUG_DEST_RST_SHIFT       (15U)
#define MC_RGM_DERD_D_DEBUG_DEST_RST_WIDTH       (1U)
#define MC_RGM_DERD_D_DEBUG_DEST_RST(x)          (((uint32_t)(((uint32_t)(x)) << MC_RGM_DERD_D_DEBUG_DEST_RST_SHIFT)) & MC_RGM_DERD_D_DEBUG_DEST_RST_MASK)
/*! @} */

/*! @name FES - Functional /External Reset Status Register */
/*! @{ */

#define MC_RGM_FES_F_EXR_MASK                    (0x1U)
#define MC_RGM_FES_F_EXR_SHIFT                   (0U)
#define MC_RGM_FES_F_EXR_WIDTH                   (1U)
#define MC_RGM_FES_F_EXR(x)                      (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_F_EXR_SHIFT)) & MC_RGM_FES_F_EXR_MASK)

#define MC_RGM_FES_PLL1_LOL_MASK                 (0x2U)
#define MC_RGM_FES_PLL1_LOL_SHIFT                (1U)
#define MC_RGM_FES_PLL1_LOL_WIDTH                (1U)
#define MC_RGM_FES_PLL1_LOL(x)                   (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_PLL1_LOL_SHIFT)) & MC_RGM_FES_PLL1_LOL_MASK)

#define MC_RGM_FES_DEBUG_SUB_JTAGC_JTAG_RST_B_MASK (0x4U)
#define MC_RGM_FES_DEBUG_SUB_JTAGC_JTAG_RST_B_SHIFT (2U)
#define MC_RGM_FES_DEBUG_SUB_JTAGC_JTAG_RST_B_WIDTH (1U)
#define MC_RGM_FES_DEBUG_SUB_JTAGC_JTAG_RST_B(x) (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_DEBUG_SUB_JTAGC_JTAG_RST_B_SHIFT)) & MC_RGM_FES_DEBUG_SUB_JTAGC_JTAG_RST_B_MASK)

#define MC_RGM_FES_LPE_MC_ME_o_FUNC_RESETSEQ_REQ_MASK (0x8U)
#define MC_RGM_FES_LPE_MC_ME_o_FUNC_RESETSEQ_REQ_SHIFT (3U)
#define MC_RGM_FES_LPE_MC_ME_o_FUNC_RESETSEQ_REQ_WIDTH (1U)
#define MC_RGM_FES_LPE_MC_ME_o_FUNC_RESETSEQ_REQ(x) (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_LPE_MC_ME_o_FUNC_RESETSEQ_REQ_SHIFT)) & MC_RGM_FES_LPE_MC_ME_o_FUNC_RESETSEQ_REQ_MASK)

#define MC_RGM_FES_SWT_STARTUP_MASK              (0x100U)
#define MC_RGM_FES_SWT_STARTUP_SHIFT             (8U)
#define MC_RGM_FES_SWT_STARTUP_WIDTH             (1U)
#define MC_RGM_FES_SWT_STARTUP(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_SWT_STARTUP_SHIFT)) & MC_RGM_FES_SWT_STARTUP_MASK)

#define MC_RGM_FES_LPE_SWT_MASK                  (0x200U)
#define MC_RGM_FES_LPE_SWT_SHIFT                 (9U)
#define MC_RGM_FES_LPE_SWT_WIDTH                 (1U)
#define MC_RGM_FES_LPE_SWT(x)                    (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_LPE_SWT_SHIFT)) & MC_RGM_FES_LPE_SWT_MASK)

#define MC_RGM_FES_DEBUG_FUNC_RST_MASK           (0x400U)
#define MC_RGM_FES_DEBUG_FUNC_RST_SHIFT          (10U)
#define MC_RGM_FES_DEBUG_FUNC_RST_WIDTH          (1U)
#define MC_RGM_FES_DEBUG_FUNC_RST(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_DEBUG_FUNC_RST_SHIFT)) & MC_RGM_FES_DEBUG_FUNC_RST_MASK)

#define MC_RGM_FES_ST_DONE_MASK                  (0x800U)
#define MC_RGM_FES_ST_DONE_SHIFT                 (11U)
#define MC_RGM_FES_ST_DONE_WIDTH                 (1U)
#define MC_RGM_FES_ST_DONE(x)                    (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_ST_DONE_SHIFT)) & MC_RGM_FES_ST_DONE_MASK)

#define MC_RGM_FES_FCCU_FUNC_RST_MASK            (0x1000U)
#define MC_RGM_FES_FCCU_FUNC_RST_SHIFT           (12U)
#define MC_RGM_FES_FCCU_FUNC_RST_WIDTH           (1U)
#define MC_RGM_FES_FCCU_FUNC_RST(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_FCCU_FUNC_RST_SHIFT)) & MC_RGM_FES_FCCU_FUNC_RST_MASK)

#define MC_RGM_FES_HSE2_TOP__S4v1_LMDA_LIFECYCLE_BRICKED_MASK (0x10000U)
#define MC_RGM_FES_HSE2_TOP__S4v1_LMDA_LIFECYCLE_BRICKED_SHIFT (16U)
#define MC_RGM_FES_HSE2_TOP__S4v1_LMDA_LIFECYCLE_BRICKED_WIDTH (1U)
#define MC_RGM_FES_HSE2_TOP__S4v1_LMDA_LIFECYCLE_BRICKED(x) (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_HSE2_TOP__S4v1_LMDA_LIFECYCLE_BRICKED_SHIFT)) & MC_RGM_FES_HSE2_TOP__S4v1_LMDA_LIFECYCLE_BRICKED_MASK)

#define MC_RGM_FES_HSE2_TOP__s4v1_WDOG_RESET_REQ_N_MASK (0x20000U)
#define MC_RGM_FES_HSE2_TOP__s4v1_WDOG_RESET_REQ_N_SHIFT (17U)
#define MC_RGM_FES_HSE2_TOP__s4v1_WDOG_RESET_REQ_N_WIDTH (1U)
#define MC_RGM_FES_HSE2_TOP__s4v1_WDOG_RESET_REQ_N(x) (((uint32_t)(((uint32_t)(x)) << MC_RGM_FES_HSE2_TOP__s4v1_WDOG_RESET_REQ_N_SHIFT)) & MC_RGM_FES_HSE2_TOP__s4v1_WDOG_RESET_REQ_N_MASK)
/*! @} */

/*! @name FERD - Functional Event Reset Disable Register */
/*! @{ */

#define MC_RGM_FERD_D_PLL1_LOL_MASK              (0x2U)
#define MC_RGM_FERD_D_PLL1_LOL_SHIFT             (1U)
#define MC_RGM_FERD_D_PLL1_LOL_WIDTH             (1U)
#define MC_RGM_FERD_D_PLL1_LOL(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FERD_D_PLL1_LOL_SHIFT)) & MC_RGM_FERD_D_PLL1_LOL_MASK)

#define MC_RGM_FERD_D_DEBUG_FUNC_RST_MASK        (0x400U)
#define MC_RGM_FERD_D_DEBUG_FUNC_RST_SHIFT       (10U)
#define MC_RGM_FERD_D_DEBUG_FUNC_RST_WIDTH       (1U)
#define MC_RGM_FERD_D_DEBUG_FUNC_RST(x)          (((uint32_t)(((uint32_t)(x)) << MC_RGM_FERD_D_DEBUG_FUNC_RST_SHIFT)) & MC_RGM_FERD_D_DEBUG_FUNC_RST_MASK)
/*! @} */

/*! @name FREC - Functional Reset Escalation Counter Register */
/*! @{ */

#define MC_RGM_FREC_FREC_MASK                    (0xFU)
#define MC_RGM_FREC_FREC_SHIFT                   (0U)
#define MC_RGM_FREC_FREC_WIDTH                   (4U)
#define MC_RGM_FREC_FREC(x)                      (((uint32_t)(((uint32_t)(x)) << MC_RGM_FREC_FREC_SHIFT)) & MC_RGM_FREC_FREC_MASK)
/*! @} */

/*! @name FRET - Functional Reset Escalation Threshold Register */
/*! @{ */

#define MC_RGM_FRET_FRET_MASK                    (0xFU)
#define MC_RGM_FRET_FRET_SHIFT                   (0U)
#define MC_RGM_FRET_FRET_WIDTH                   (4U)
#define MC_RGM_FRET_FRET(x)                      (((uint32_t)(((uint32_t)(x)) << MC_RGM_FRET_FRET_SHIFT)) & MC_RGM_FRET_FRET_MASK)
/*! @} */

/*! @name DRET - Destructive Reset Escalation Threshold Register */
/*! @{ */

#define MC_RGM_DRET_DRET_MASK                    (0xFU)
#define MC_RGM_DRET_DRET_SHIFT                   (0U)
#define MC_RGM_DRET_DRET_WIDTH                   (4U)
#define MC_RGM_DRET_DRET(x)                      (((uint32_t)(((uint32_t)(x)) << MC_RGM_DRET_DRET_SHIFT)) & MC_RGM_DRET_DRET_MASK)
/*! @} */

/*! @name ERCTRL - External Reset Control Register */
/*! @{ */

#define MC_RGM_ERCTRL_ERASSERT_MASK              (0x1U)
#define MC_RGM_ERCTRL_ERASSERT_SHIFT             (0U)
#define MC_RGM_ERCTRL_ERASSERT_WIDTH             (1U)
#define MC_RGM_ERCTRL_ERASSERT(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_ERCTRL_ERASSERT_SHIFT)) & MC_RGM_ERCTRL_ERASSERT_MASK)
/*! @} */

/*! @name REDL - Reset Event During LPRUN */
/*! @{ */

#define MC_RGM_REDL_DES_RES_MASK                 (0x1U)
#define MC_RGM_REDL_DES_RES_SHIFT                (0U)
#define MC_RGM_REDL_DES_RES_WIDTH                (1U)
#define MC_RGM_REDL_DES_RES(x)                   (((uint32_t)(((uint32_t)(x)) << MC_RGM_REDL_DES_RES_SHIFT)) & MC_RGM_REDL_DES_RES_MASK)

#define MC_RGM_REDL_FES_RES_MASK                 (0x2U)
#define MC_RGM_REDL_FES_RES_SHIFT                (1U)
#define MC_RGM_REDL_FES_RES_WIDTH                (1U)
#define MC_RGM_REDL_FES_RES(x)                   (((uint32_t)(((uint32_t)(x)) << MC_RGM_REDL_FES_RES_SHIFT)) & MC_RGM_REDL_FES_RES_MASK)
/*! @} */

/*! @name PRST0_0 - Peripheral Reset */
/*! @{ */

#define MC_RGM_PRST0_0_PERIPH_0_RST_MASK         (0x1U)
#define MC_RGM_PRST0_0_PERIPH_0_RST_SHIFT        (0U)
#define MC_RGM_PRST0_0_PERIPH_0_RST_WIDTH        (1U)
#define MC_RGM_PRST0_0_PERIPH_0_RST(x)           (((uint32_t)(((uint32_t)(x)) << MC_RGM_PRST0_0_PERIPH_0_RST_SHIFT)) & MC_RGM_PRST0_0_PERIPH_0_RST_MASK)
/*! @} */

/*! @name PRST1_0 - Peripheral Reset */
/*! @{ */

#define MC_RGM_PRST1_0_PERIPH_64_RST_MASK        (0x1U)
#define MC_RGM_PRST1_0_PERIPH_64_RST_SHIFT       (0U)
#define MC_RGM_PRST1_0_PERIPH_64_RST_WIDTH       (1U)
#define MC_RGM_PRST1_0_PERIPH_64_RST(x)          (((uint32_t)(((uint32_t)(x)) << MC_RGM_PRST1_0_PERIPH_64_RST_SHIFT)) & MC_RGM_PRST1_0_PERIPH_64_RST_MASK)
/*! @} */

/*! @name PRST2_0 - Peripheral Reset */
/*! @{ */

#define MC_RGM_PRST2_0_PERIPH_128_RST_MASK       (0x1U)
#define MC_RGM_PRST2_0_PERIPH_128_RST_SHIFT      (0U)
#define MC_RGM_PRST2_0_PERIPH_128_RST_WIDTH      (1U)
#define MC_RGM_PRST2_0_PERIPH_128_RST(x)         (((uint32_t)(((uint32_t)(x)) << MC_RGM_PRST2_0_PERIPH_128_RST_SHIFT)) & MC_RGM_PRST2_0_PERIPH_128_RST_MASK)
/*! @} */

/*! @name PRST3_0 - Peripheral Reset */
/*! @{ */

#define MC_RGM_PRST3_0_PERIPH_192_RST_MASK       (0x1U)
#define MC_RGM_PRST3_0_PERIPH_192_RST_SHIFT      (0U)
#define MC_RGM_PRST3_0_PERIPH_192_RST_WIDTH      (1U)
#define MC_RGM_PRST3_0_PERIPH_192_RST(x)         (((uint32_t)(((uint32_t)(x)) << MC_RGM_PRST3_0_PERIPH_192_RST_SHIFT)) & MC_RGM_PRST3_0_PERIPH_192_RST_MASK)
/*! @} */

/*! @name PRST4_0 - Peripheral Reset */
/*! @{ */

#define MC_RGM_PRST4_0_PERIPH_256_RST_MASK       (0x1U)
#define MC_RGM_PRST4_0_PERIPH_256_RST_SHIFT      (0U)
#define MC_RGM_PRST4_0_PERIPH_256_RST_WIDTH      (1U)
#define MC_RGM_PRST4_0_PERIPH_256_RST(x)         (((uint32_t)(((uint32_t)(x)) << MC_RGM_PRST4_0_PERIPH_256_RST_SHIFT)) & MC_RGM_PRST4_0_PERIPH_256_RST_MASK)
/*! @} */

/*! @name PRST5_0 - Peripheral Reset */
/*! @{ */

#define MC_RGM_PRST5_0_PERIPH_320_RST_MASK       (0x1U)
#define MC_RGM_PRST5_0_PERIPH_320_RST_SHIFT      (0U)
#define MC_RGM_PRST5_0_PERIPH_320_RST_WIDTH      (1U)
#define MC_RGM_PRST5_0_PERIPH_320_RST(x)         (((uint32_t)(((uint32_t)(x)) << MC_RGM_PRST5_0_PERIPH_320_RST_SHIFT)) & MC_RGM_PRST5_0_PERIPH_320_RST_MASK)
/*! @} */

/*! @name PRST6_0 - Peripheral Reset */
/*! @{ */

#define MC_RGM_PRST6_0_PERIPH_384_RST_MASK       (0x1U)
#define MC_RGM_PRST6_0_PERIPH_384_RST_SHIFT      (0U)
#define MC_RGM_PRST6_0_PERIPH_384_RST_WIDTH      (1U)
#define MC_RGM_PRST6_0_PERIPH_384_RST(x)         (((uint32_t)(((uint32_t)(x)) << MC_RGM_PRST6_0_PERIPH_384_RST_SHIFT)) & MC_RGM_PRST6_0_PERIPH_384_RST_MASK)
/*! @} */

/*! @name PRST7_0 - Peripheral Reset */
/*! @{ */

#define MC_RGM_PRST7_0_PERIPH_448_RST_MASK       (0x1U)
#define MC_RGM_PRST7_0_PERIPH_448_RST_SHIFT      (0U)
#define MC_RGM_PRST7_0_PERIPH_448_RST_WIDTH      (1U)
#define MC_RGM_PRST7_0_PERIPH_448_RST(x)         (((uint32_t)(((uint32_t)(x)) << MC_RGM_PRST7_0_PERIPH_448_RST_SHIFT)) & MC_RGM_PRST7_0_PERIPH_448_RST_MASK)
/*! @} */

/*! @name PSTAT0_0 - Peripheral Reset Status Register */
/*! @{ */

#define MC_RGM_PSTAT0_0_PERIPH_0_STAT_MASK       (0x1U)
#define MC_RGM_PSTAT0_0_PERIPH_0_STAT_SHIFT      (0U)
#define MC_RGM_PSTAT0_0_PERIPH_0_STAT_WIDTH      (1U)
#define MC_RGM_PSTAT0_0_PERIPH_0_STAT(x)         (((uint32_t)(((uint32_t)(x)) << MC_RGM_PSTAT0_0_PERIPH_0_STAT_SHIFT)) & MC_RGM_PSTAT0_0_PERIPH_0_STAT_MASK)
/*! @} */

/*! @name PSTAT1_0 - Peripheral Reset Status Register */
/*! @{ */

#define MC_RGM_PSTAT1_0_PERIPH_64_STAT_MASK      (0x1U)
#define MC_RGM_PSTAT1_0_PERIPH_64_STAT_SHIFT     (0U)
#define MC_RGM_PSTAT1_0_PERIPH_64_STAT_WIDTH     (1U)
#define MC_RGM_PSTAT1_0_PERIPH_64_STAT(x)        (((uint32_t)(((uint32_t)(x)) << MC_RGM_PSTAT1_0_PERIPH_64_STAT_SHIFT)) & MC_RGM_PSTAT1_0_PERIPH_64_STAT_MASK)
/*! @} */

/*! @name PSTAT2_0 - Peripheral Reset Status Register */
/*! @{ */

#define MC_RGM_PSTAT2_0_PERIPH_128_STAT_MASK     (0x1U)
#define MC_RGM_PSTAT2_0_PERIPH_128_STAT_SHIFT    (0U)
#define MC_RGM_PSTAT2_0_PERIPH_128_STAT_WIDTH    (1U)
#define MC_RGM_PSTAT2_0_PERIPH_128_STAT(x)       (((uint32_t)(((uint32_t)(x)) << MC_RGM_PSTAT2_0_PERIPH_128_STAT_SHIFT)) & MC_RGM_PSTAT2_0_PERIPH_128_STAT_MASK)
/*! @} */

/*! @name PSTAT3_0 - Peripheral Reset Status Register */
/*! @{ */

#define MC_RGM_PSTAT3_0_PERIPH_192_STAT_MASK     (0x1U)
#define MC_RGM_PSTAT3_0_PERIPH_192_STAT_SHIFT    (0U)
#define MC_RGM_PSTAT3_0_PERIPH_192_STAT_WIDTH    (1U)
#define MC_RGM_PSTAT3_0_PERIPH_192_STAT(x)       (((uint32_t)(((uint32_t)(x)) << MC_RGM_PSTAT3_0_PERIPH_192_STAT_SHIFT)) & MC_RGM_PSTAT3_0_PERIPH_192_STAT_MASK)
/*! @} */

/*! @name PSTAT4_0 - Peripheral Reset Status Register */
/*! @{ */

#define MC_RGM_PSTAT4_0_PERIPH_256_STAT_MASK     (0x1U)
#define MC_RGM_PSTAT4_0_PERIPH_256_STAT_SHIFT    (0U)
#define MC_RGM_PSTAT4_0_PERIPH_256_STAT_WIDTH    (1U)
#define MC_RGM_PSTAT4_0_PERIPH_256_STAT(x)       (((uint32_t)(((uint32_t)(x)) << MC_RGM_PSTAT4_0_PERIPH_256_STAT_SHIFT)) & MC_RGM_PSTAT4_0_PERIPH_256_STAT_MASK)
/*! @} */

/*! @name PSTAT5_0 - Peripheral Reset Status Register */
/*! @{ */

#define MC_RGM_PSTAT5_0_PERIPH_320_STAT_MASK     (0x1U)
#define MC_RGM_PSTAT5_0_PERIPH_320_STAT_SHIFT    (0U)
#define MC_RGM_PSTAT5_0_PERIPH_320_STAT_WIDTH    (1U)
#define MC_RGM_PSTAT5_0_PERIPH_320_STAT(x)       (((uint32_t)(((uint32_t)(x)) << MC_RGM_PSTAT5_0_PERIPH_320_STAT_SHIFT)) & MC_RGM_PSTAT5_0_PERIPH_320_STAT_MASK)
/*! @} */

/*! @name PSTAT6_0 - Peripheral Reset Status Register */
/*! @{ */

#define MC_RGM_PSTAT6_0_PERIPH_384_STAT_MASK     (0x1U)
#define MC_RGM_PSTAT6_0_PERIPH_384_STAT_SHIFT    (0U)
#define MC_RGM_PSTAT6_0_PERIPH_384_STAT_WIDTH    (1U)
#define MC_RGM_PSTAT6_0_PERIPH_384_STAT(x)       (((uint32_t)(((uint32_t)(x)) << MC_RGM_PSTAT6_0_PERIPH_384_STAT_SHIFT)) & MC_RGM_PSTAT6_0_PERIPH_384_STAT_MASK)
/*! @} */

/*! @name PSTAT7_0 - Peripheral Reset Status Register */
/*! @{ */

#define MC_RGM_PSTAT7_0_PERIPH_448_STAT_MASK     (0x1U)
#define MC_RGM_PSTAT7_0_PERIPH_448_STAT_SHIFT    (0U)
#define MC_RGM_PSTAT7_0_PERIPH_448_STAT_WIDTH    (1U)
#define MC_RGM_PSTAT7_0_PERIPH_448_STAT(x)       (((uint32_t)(((uint32_t)(x)) << MC_RGM_PSTAT7_0_PERIPH_448_STAT_SHIFT)) & MC_RGM_PSTAT7_0_PERIPH_448_STAT_MASK)
/*! @} */

/*! @name PRST_LPC - Peripheral Reset LP Core */
/*! @{ */

#define MC_RGM_PRST_LPC_LPC0_RST_MASK            (0x1U)
#define MC_RGM_PRST_LPC_LPC0_RST_SHIFT           (0U)
#define MC_RGM_PRST_LPC_LPC0_RST_WIDTH           (1U)
#define MC_RGM_PRST_LPC_LPC0_RST(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_PRST_LPC_LPC0_RST_SHIFT)) & MC_RGM_PRST_LPC_LPC0_RST_MASK)
/*! @} */

/*! @name PLPCSTAT - Peripheral LP Core Status */
/*! @{ */

#define MC_RGM_PLPCSTAT_LPC0_RSTS_MASK           (0x1U)
#define MC_RGM_PLPCSTAT_LPC0_RSTS_SHIFT          (0U)
#define MC_RGM_PLPCSTAT_LPC0_RSTS_WIDTH          (1U)
#define MC_RGM_PLPCSTAT_LPC0_RSTS(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_PLPCSTAT_LPC0_RSTS_SHIFT)) & MC_RGM_PLPCSTAT_LPC0_RSTS_MASK)
/*! @} */

/*! @name CTL_KEY - Control Key Register */
/*! @{ */

#define MC_RGM_CTL_KEY_KEY_MASK                  (0xFFFFU)
#define MC_RGM_CTL_KEY_KEY_SHIFT                 (0U)
#define MC_RGM_CTL_KEY_KEY_WIDTH                 (16U)
#define MC_RGM_CTL_KEY_KEY(x)                    (((uint32_t)(((uint32_t)(x)) << MC_RGM_CTL_KEY_KEY_SHIFT)) & MC_RGM_CTL_KEY_KEY_MASK)
/*! @} */

/*! @name MODE_CONF - Mode Configuration Register */
/*! @{ */

#define MC_RGM_MODE_CONF_POR_RST_MASK            (0x1U)
#define MC_RGM_MODE_CONF_POR_RST_SHIFT           (0U)
#define MC_RGM_MODE_CONF_POR_RST_WIDTH           (1U)
#define MC_RGM_MODE_CONF_POR_RST(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_MODE_CONF_POR_RST_SHIFT)) & MC_RGM_MODE_CONF_POR_RST_MASK)

#define MC_RGM_MODE_CONF_DEST_RST_MASK           (0x2U)
#define MC_RGM_MODE_CONF_DEST_RST_SHIFT          (1U)
#define MC_RGM_MODE_CONF_DEST_RST_WIDTH          (1U)
#define MC_RGM_MODE_CONF_DEST_RST(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_MODE_CONF_DEST_RST_SHIFT)) & MC_RGM_MODE_CONF_DEST_RST_MASK)

#define MC_RGM_MODE_CONF_FUNC_RST_MASK           (0x4U)
#define MC_RGM_MODE_CONF_FUNC_RST_SHIFT          (2U)
#define MC_RGM_MODE_CONF_FUNC_RST_WIDTH          (1U)
#define MC_RGM_MODE_CONF_FUNC_RST(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_MODE_CONF_FUNC_RST_SHIFT)) & MC_RGM_MODE_CONF_FUNC_RST_MASK)

#define MC_RGM_MODE_CONF_FULL_WKUP_MASK          (0x2000U)
#define MC_RGM_MODE_CONF_FULL_WKUP_SHIFT         (13U)
#define MC_RGM_MODE_CONF_FULL_WKUP_WIDTH         (1U)
#define MC_RGM_MODE_CONF_FULL_WKUP(x)            (((uint32_t)(((uint32_t)(x)) << MC_RGM_MODE_CONF_FULL_WKUP_SHIFT)) & MC_RGM_MODE_CONF_FULL_WKUP_MASK)

#define MC_RGM_MODE_CONF_LPRUN_MASK              (0x4000U)
#define MC_RGM_MODE_CONF_LPRUN_SHIFT             (14U)
#define MC_RGM_MODE_CONF_LPRUN_WIDTH             (1U)
#define MC_RGM_MODE_CONF_LPRUN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_MODE_CONF_LPRUN_SHIFT)) & MC_RGM_MODE_CONF_LPRUN_MASK)

#define MC_RGM_MODE_CONF_STANDBY_MASK            (0x8000U)
#define MC_RGM_MODE_CONF_STANDBY_SHIFT           (15U)
#define MC_RGM_MODE_CONF_STANDBY_WIDTH           (1U)
#define MC_RGM_MODE_CONF_STANDBY(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_MODE_CONF_STANDBY_SHIFT)) & MC_RGM_MODE_CONF_STANDBY_MASK)

#define MC_RGM_MODE_CONF_STDBRTOEN_MASK          (0x10000U)
#define MC_RGM_MODE_CONF_STDBRTOEN_SHIFT         (16U)
#define MC_RGM_MODE_CONF_STDBRTOEN_WIDTH         (1U)
#define MC_RGM_MODE_CONF_STDBRTOEN(x)            (((uint32_t)(((uint32_t)(x)) << MC_RGM_MODE_CONF_STDBRTOEN_SHIFT)) & MC_RGM_MODE_CONF_STDBRTOEN_MASK)
/*! @} */

/*! @name EVT_STAT - Event Status */
/*! @{ */

#define MC_RGM_EVT_STAT_F_POR_MASK               (0x1U)
#define MC_RGM_EVT_STAT_F_POR_SHIFT              (0U)
#define MC_RGM_EVT_STAT_F_POR_WIDTH              (1U)
#define MC_RGM_EVT_STAT_F_POR(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_EVT_STAT_F_POR_SHIFT)) & MC_RGM_EVT_STAT_F_POR_MASK)

#define MC_RGM_EVT_STAT_F_SUST_MASK              (0x2U)
#define MC_RGM_EVT_STAT_F_SUST_SHIFT             (1U)
#define MC_RGM_EVT_STAT_F_SUST_WIDTH             (1U)
#define MC_RGM_EVT_STAT_F_SUST(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_EVT_STAT_F_SUST_SHIFT)) & MC_RGM_EVT_STAT_F_SUST_MASK)

#define MC_RGM_EVT_STAT_F_FPM1_MASK              (0x4U)
#define MC_RGM_EVT_STAT_F_FPM1_SHIFT             (2U)
#define MC_RGM_EVT_STAT_F_FPM1_WIDTH             (1U)
#define MC_RGM_EVT_STAT_F_FPM1(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_EVT_STAT_F_FPM1_SHIFT)) & MC_RGM_EVT_STAT_F_FPM1_MASK)

#define MC_RGM_EVT_STAT_F_PM1_5_MASK             (0x8U)
#define MC_RGM_EVT_STAT_F_PM1_5_SHIFT            (3U)
#define MC_RGM_EVT_STAT_F_PM1_5_WIDTH            (1U)
#define MC_RGM_EVT_STAT_F_PM1_5(x)               (((uint32_t)(((uint32_t)(x)) << MC_RGM_EVT_STAT_F_PM1_5_SHIFT)) & MC_RGM_EVT_STAT_F_PM1_5_MASK)

#define MC_RGM_EVT_STAT_F_DES_MASK               (0x10U)
#define MC_RGM_EVT_STAT_F_DES_SHIFT              (4U)
#define MC_RGM_EVT_STAT_F_DES_WIDTH              (1U)
#define MC_RGM_EVT_STAT_F_DES(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_EVT_STAT_F_DES_SHIFT)) & MC_RGM_EVT_STAT_F_DES_MASK)

#define MC_RGM_EVT_STAT_F_FES_MASK               (0x20U)
#define MC_RGM_EVT_STAT_F_FES_SHIFT              (5U)
#define MC_RGM_EVT_STAT_F_FES_WIDTH              (1U)
#define MC_RGM_EVT_STAT_F_FES(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_EVT_STAT_F_FES_SHIFT)) & MC_RGM_EVT_STAT_F_FES_MASK)

#define MC_RGM_EVT_STAT_F_MTIP_MASK              (0x80U)
#define MC_RGM_EVT_STAT_F_MTIP_SHIFT             (7U)
#define MC_RGM_EVT_STAT_F_MTIP_WIDTH             (1U)
#define MC_RGM_EVT_STAT_F_MTIP(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_EVT_STAT_F_MTIP_SHIFT)) & MC_RGM_EVT_STAT_F_MTIP_MASK)
/*! @} */

/*! @name FPHTEC - Functional Reset Entry Phase Timer Enable Control */
/*! @{ */

#define MC_RGM_FPHTEC_PHASE0EN_MASK              (0x1U)
#define MC_RGM_FPHTEC_PHASE0EN_SHIFT             (0U)
#define MC_RGM_FPHTEC_PHASE0EN_WIDTH             (1U)
#define MC_RGM_FPHTEC_PHASE0EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTEC_PHASE0EN_SHIFT)) & MC_RGM_FPHTEC_PHASE0EN_MASK)

#define MC_RGM_FPHTEC_PHASE1EN_MASK              (0x2U)
#define MC_RGM_FPHTEC_PHASE1EN_SHIFT             (1U)
#define MC_RGM_FPHTEC_PHASE1EN_WIDTH             (1U)
#define MC_RGM_FPHTEC_PHASE1EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTEC_PHASE1EN_SHIFT)) & MC_RGM_FPHTEC_PHASE1EN_MASK)

#define MC_RGM_FPHTEC_PHASE2EN_MASK              (0x4U)
#define MC_RGM_FPHTEC_PHASE2EN_SHIFT             (2U)
#define MC_RGM_FPHTEC_PHASE2EN_WIDTH             (1U)
#define MC_RGM_FPHTEC_PHASE2EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTEC_PHASE2EN_SHIFT)) & MC_RGM_FPHTEC_PHASE2EN_MASK)

#define MC_RGM_FPHTEC_PHASE3EN_MASK              (0x8U)
#define MC_RGM_FPHTEC_PHASE3EN_SHIFT             (3U)
#define MC_RGM_FPHTEC_PHASE3EN_WIDTH             (1U)
#define MC_RGM_FPHTEC_PHASE3EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTEC_PHASE3EN_SHIFT)) & MC_RGM_FPHTEC_PHASE3EN_MASK)

#define MC_RGM_FPHTEC_PHASE4EN_MASK              (0x10U)
#define MC_RGM_FPHTEC_PHASE4EN_SHIFT             (4U)
#define MC_RGM_FPHTEC_PHASE4EN_WIDTH             (1U)
#define MC_RGM_FPHTEC_PHASE4EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTEC_PHASE4EN_SHIFT)) & MC_RGM_FPHTEC_PHASE4EN_MASK)

#define MC_RGM_FPHTEC_PHASE5EN_MASK              (0x20U)
#define MC_RGM_FPHTEC_PHASE5EN_SHIFT             (5U)
#define MC_RGM_FPHTEC_PHASE5EN_WIDTH             (1U)
#define MC_RGM_FPHTEC_PHASE5EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTEC_PHASE5EN_SHIFT)) & MC_RGM_FPHTEC_PHASE5EN_MASK)

#define MC_RGM_FPHTEC_PHASE6EN_MASK              (0x40U)
#define MC_RGM_FPHTEC_PHASE6EN_SHIFT             (6U)
#define MC_RGM_FPHTEC_PHASE6EN_WIDTH             (1U)
#define MC_RGM_FPHTEC_PHASE6EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTEC_PHASE6EN_SHIFT)) & MC_RGM_FPHTEC_PHASE6EN_MASK)

#define MC_RGM_FPHTEC_PHASE7EN_MASK              (0x80U)
#define MC_RGM_FPHTEC_PHASE7EN_SHIFT             (7U)
#define MC_RGM_FPHTEC_PHASE7EN_WIDTH             (1U)
#define MC_RGM_FPHTEC_PHASE7EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTEC_PHASE7EN_SHIFT)) & MC_RGM_FPHTEC_PHASE7EN_MASK)
/*! @} */

/*! @name FPHTV - Functional Reset Entry Phase Timer Value */
/*! @{ */

#define MC_RGM_FPHTV_TIMEOUT_VAL_MASK            (0xFFFFFFFFU)
#define MC_RGM_FPHTV_TIMEOUT_VAL_SHIFT           (0U)
#define MC_RGM_FPHTV_TIMEOUT_VAL_WIDTH           (32U)
#define MC_RGM_FPHTV_TIMEOUT_VAL(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTV_TIMEOUT_VAL_SHIFT)) & MC_RGM_FPHTV_TIMEOUT_VAL_MASK)
/*! @} */

/*! @name FPHTC - Functional Reset Entry Phase Timer Control */
/*! @{ */

#define MC_RGM_FPHTC_PHASE0EN_MASK               (0x1U)
#define MC_RGM_FPHTC_PHASE0EN_SHIFT              (0U)
#define MC_RGM_FPHTC_PHASE0EN_WIDTH              (1U)
#define MC_RGM_FPHTC_PHASE0EN(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTC_PHASE0EN_SHIFT)) & MC_RGM_FPHTC_PHASE0EN_MASK)

#define MC_RGM_FPHTC_PHASE1EN_MASK               (0x2U)
#define MC_RGM_FPHTC_PHASE1EN_SHIFT              (1U)
#define MC_RGM_FPHTC_PHASE1EN_WIDTH              (1U)
#define MC_RGM_FPHTC_PHASE1EN(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTC_PHASE1EN_SHIFT)) & MC_RGM_FPHTC_PHASE1EN_MASK)

#define MC_RGM_FPHTC_PHASE2EN_MASK               (0x4U)
#define MC_RGM_FPHTC_PHASE2EN_SHIFT              (2U)
#define MC_RGM_FPHTC_PHASE2EN_WIDTH              (1U)
#define MC_RGM_FPHTC_PHASE2EN(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTC_PHASE2EN_SHIFT)) & MC_RGM_FPHTC_PHASE2EN_MASK)

#define MC_RGM_FPHTC_PHASE3EN_MASK               (0x8U)
#define MC_RGM_FPHTC_PHASE3EN_SHIFT              (3U)
#define MC_RGM_FPHTC_PHASE3EN_WIDTH              (1U)
#define MC_RGM_FPHTC_PHASE3EN(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTC_PHASE3EN_SHIFT)) & MC_RGM_FPHTC_PHASE3EN_MASK)

#define MC_RGM_FPHTC_PHASE4EN_MASK               (0x10U)
#define MC_RGM_FPHTC_PHASE4EN_SHIFT              (4U)
#define MC_RGM_FPHTC_PHASE4EN_WIDTH              (1U)
#define MC_RGM_FPHTC_PHASE4EN(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTC_PHASE4EN_SHIFT)) & MC_RGM_FPHTC_PHASE4EN_MASK)

#define MC_RGM_FPHTC_PHASE5EN_MASK               (0x20U)
#define MC_RGM_FPHTC_PHASE5EN_SHIFT              (5U)
#define MC_RGM_FPHTC_PHASE5EN_WIDTH              (1U)
#define MC_RGM_FPHTC_PHASE5EN(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTC_PHASE5EN_SHIFT)) & MC_RGM_FPHTC_PHASE5EN_MASK)

#define MC_RGM_FPHTC_PHASE6EN_MASK               (0x40U)
#define MC_RGM_FPHTC_PHASE6EN_SHIFT              (6U)
#define MC_RGM_FPHTC_PHASE6EN_WIDTH              (1U)
#define MC_RGM_FPHTC_PHASE6EN(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTC_PHASE6EN_SHIFT)) & MC_RGM_FPHTC_PHASE6EN_MASK)

#define MC_RGM_FPHTC_PHASE7EN_MASK               (0x80U)
#define MC_RGM_FPHTC_PHASE7EN_SHIFT              (7U)
#define MC_RGM_FPHTC_PHASE7EN_WIDTH              (1U)
#define MC_RGM_FPHTC_PHASE7EN(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTC_PHASE7EN_SHIFT)) & MC_RGM_FPHTC_PHASE7EN_MASK)
/*! @} */

/*! @name FPHTES - Functional Reset Entry Phase Timer Expiry Status */
/*! @{ */

#define MC_RGM_FPHTES_PHASE0EN_MASK              (0x1U)
#define MC_RGM_FPHTES_PHASE0EN_SHIFT             (0U)
#define MC_RGM_FPHTES_PHASE0EN_WIDTH             (1U)
#define MC_RGM_FPHTES_PHASE0EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTES_PHASE0EN_SHIFT)) & MC_RGM_FPHTES_PHASE0EN_MASK)

#define MC_RGM_FPHTES_PHASE1EN_MASK              (0x2U)
#define MC_RGM_FPHTES_PHASE1EN_SHIFT             (1U)
#define MC_RGM_FPHTES_PHASE1EN_WIDTH             (1U)
#define MC_RGM_FPHTES_PHASE1EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTES_PHASE1EN_SHIFT)) & MC_RGM_FPHTES_PHASE1EN_MASK)

#define MC_RGM_FPHTES_PHASE2EN_MASK              (0x4U)
#define MC_RGM_FPHTES_PHASE2EN_SHIFT             (2U)
#define MC_RGM_FPHTES_PHASE2EN_WIDTH             (1U)
#define MC_RGM_FPHTES_PHASE2EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTES_PHASE2EN_SHIFT)) & MC_RGM_FPHTES_PHASE2EN_MASK)

#define MC_RGM_FPHTES_PHASE3EN_MASK              (0x8U)
#define MC_RGM_FPHTES_PHASE3EN_SHIFT             (3U)
#define MC_RGM_FPHTES_PHASE3EN_WIDTH             (1U)
#define MC_RGM_FPHTES_PHASE3EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTES_PHASE3EN_SHIFT)) & MC_RGM_FPHTES_PHASE3EN_MASK)

#define MC_RGM_FPHTES_PHASE4EN_MASK              (0x10U)
#define MC_RGM_FPHTES_PHASE4EN_SHIFT             (4U)
#define MC_RGM_FPHTES_PHASE4EN_WIDTH             (1U)
#define MC_RGM_FPHTES_PHASE4EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTES_PHASE4EN_SHIFT)) & MC_RGM_FPHTES_PHASE4EN_MASK)

#define MC_RGM_FPHTES_PHASE5EN_MASK              (0x20U)
#define MC_RGM_FPHTES_PHASE5EN_SHIFT             (5U)
#define MC_RGM_FPHTES_PHASE5EN_WIDTH             (1U)
#define MC_RGM_FPHTES_PHASE5EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTES_PHASE5EN_SHIFT)) & MC_RGM_FPHTES_PHASE5EN_MASK)

#define MC_RGM_FPHTES_PHASE6EN_MASK              (0x40U)
#define MC_RGM_FPHTES_PHASE6EN_SHIFT             (6U)
#define MC_RGM_FPHTES_PHASE6EN_WIDTH             (1U)
#define MC_RGM_FPHTES_PHASE6EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTES_PHASE6EN_SHIFT)) & MC_RGM_FPHTES_PHASE6EN_MASK)

#define MC_RGM_FPHTES_PHASE7EN_MASK              (0x80U)
#define MC_RGM_FPHTES_PHASE7EN_SHIFT             (7U)
#define MC_RGM_FPHTES_PHASE7EN_WIDTH             (1U)
#define MC_RGM_FPHTES_PHASE7EN(x)                (((uint32_t)(((uint32_t)(x)) << MC_RGM_FPHTES_PHASE7EN_SHIFT)) & MC_RGM_FPHTES_PHASE7EN_MASK)
/*! @} */

/*! @name BOOT_VAL - Boot Mode Value */
/*! @{ */

#define MC_RGM_BOOT_VAL_BMODE_MASK               (0xFFFFU)
#define MC_RGM_BOOT_VAL_BMODE_SHIFT              (0U)
#define MC_RGM_BOOT_VAL_BMODE_WIDTH              (16U)
#define MC_RGM_BOOT_VAL_BMODE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_VAL_BMODE_SHIFT)) & MC_RGM_BOOT_VAL_BMODE_MASK)
/*! @} */

/*! @name BOOT_CFG - Boot Configurations */
/*! @{ */

#define MC_RGM_BOOT_CFG_BOOTCFG0_MASK            (0x1U)
#define MC_RGM_BOOT_CFG_BOOTCFG0_SHIFT           (0U)
#define MC_RGM_BOOT_CFG_BOOTCFG0_WIDTH           (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG0(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG0_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG0_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG1_MASK            (0x2U)
#define MC_RGM_BOOT_CFG_BOOTCFG1_SHIFT           (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG1_WIDTH           (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG1(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG1_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG1_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG2_MASK            (0x4U)
#define MC_RGM_BOOT_CFG_BOOTCFG2_SHIFT           (2U)
#define MC_RGM_BOOT_CFG_BOOTCFG2_WIDTH           (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG2(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG2_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG2_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG3_MASK            (0x8U)
#define MC_RGM_BOOT_CFG_BOOTCFG3_SHIFT           (3U)
#define MC_RGM_BOOT_CFG_BOOTCFG3_WIDTH           (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG3(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG3_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG3_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG4_MASK            (0x10U)
#define MC_RGM_BOOT_CFG_BOOTCFG4_SHIFT           (4U)
#define MC_RGM_BOOT_CFG_BOOTCFG4_WIDTH           (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG4(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG4_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG4_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG5_MASK            (0x20U)
#define MC_RGM_BOOT_CFG_BOOTCFG5_SHIFT           (5U)
#define MC_RGM_BOOT_CFG_BOOTCFG5_WIDTH           (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG5(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG5_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG5_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG6_MASK            (0x40U)
#define MC_RGM_BOOT_CFG_BOOTCFG6_SHIFT           (6U)
#define MC_RGM_BOOT_CFG_BOOTCFG6_WIDTH           (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG6(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG6_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG6_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG7_MASK            (0x80U)
#define MC_RGM_BOOT_CFG_BOOTCFG7_SHIFT           (7U)
#define MC_RGM_BOOT_CFG_BOOTCFG7_WIDTH           (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG7(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG7_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG7_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG8_MASK            (0x100U)
#define MC_RGM_BOOT_CFG_BOOTCFG8_SHIFT           (8U)
#define MC_RGM_BOOT_CFG_BOOTCFG8_WIDTH           (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG8(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG8_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG8_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG9_MASK            (0x200U)
#define MC_RGM_BOOT_CFG_BOOTCFG9_SHIFT           (9U)
#define MC_RGM_BOOT_CFG_BOOTCFG9_WIDTH           (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG9(x)              (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG9_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG9_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG10_MASK           (0x400U)
#define MC_RGM_BOOT_CFG_BOOTCFG10_SHIFT          (10U)
#define MC_RGM_BOOT_CFG_BOOTCFG10_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG10(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG10_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG10_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG11_MASK           (0x800U)
#define MC_RGM_BOOT_CFG_BOOTCFG11_SHIFT          (11U)
#define MC_RGM_BOOT_CFG_BOOTCFG11_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG11(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG11_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG11_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG12_MASK           (0x1000U)
#define MC_RGM_BOOT_CFG_BOOTCFG12_SHIFT          (12U)
#define MC_RGM_BOOT_CFG_BOOTCFG12_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG12(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG12_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG12_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG13_MASK           (0x2000U)
#define MC_RGM_BOOT_CFG_BOOTCFG13_SHIFT          (13U)
#define MC_RGM_BOOT_CFG_BOOTCFG13_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG13(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG13_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG13_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG14_MASK           (0x4000U)
#define MC_RGM_BOOT_CFG_BOOTCFG14_SHIFT          (14U)
#define MC_RGM_BOOT_CFG_BOOTCFG14_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG14(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG14_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG14_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG15_MASK           (0x8000U)
#define MC_RGM_BOOT_CFG_BOOTCFG15_SHIFT          (15U)
#define MC_RGM_BOOT_CFG_BOOTCFG15_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG15(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG15_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG15_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG16_MASK           (0x10000U)
#define MC_RGM_BOOT_CFG_BOOTCFG16_SHIFT          (16U)
#define MC_RGM_BOOT_CFG_BOOTCFG16_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG16(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG16_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG16_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG17_MASK           (0x20000U)
#define MC_RGM_BOOT_CFG_BOOTCFG17_SHIFT          (17U)
#define MC_RGM_BOOT_CFG_BOOTCFG17_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG17(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG17_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG17_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG18_MASK           (0x40000U)
#define MC_RGM_BOOT_CFG_BOOTCFG18_SHIFT          (18U)
#define MC_RGM_BOOT_CFG_BOOTCFG18_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG18(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG18_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG18_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG19_MASK           (0x80000U)
#define MC_RGM_BOOT_CFG_BOOTCFG19_SHIFT          (19U)
#define MC_RGM_BOOT_CFG_BOOTCFG19_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG19(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG19_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG19_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG20_MASK           (0x100000U)
#define MC_RGM_BOOT_CFG_BOOTCFG20_SHIFT          (20U)
#define MC_RGM_BOOT_CFG_BOOTCFG20_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG20(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG20_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG20_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG21_MASK           (0x200000U)
#define MC_RGM_BOOT_CFG_BOOTCFG21_SHIFT          (21U)
#define MC_RGM_BOOT_CFG_BOOTCFG21_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG21(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG21_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG21_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG22_MASK           (0x400000U)
#define MC_RGM_BOOT_CFG_BOOTCFG22_SHIFT          (22U)
#define MC_RGM_BOOT_CFG_BOOTCFG22_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG22(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG22_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG22_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG23_MASK           (0x800000U)
#define MC_RGM_BOOT_CFG_BOOTCFG23_SHIFT          (23U)
#define MC_RGM_BOOT_CFG_BOOTCFG23_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG23(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG23_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG23_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG24_MASK           (0x1000000U)
#define MC_RGM_BOOT_CFG_BOOTCFG24_SHIFT          (24U)
#define MC_RGM_BOOT_CFG_BOOTCFG24_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG24(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG24_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG24_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG25_MASK           (0x2000000U)
#define MC_RGM_BOOT_CFG_BOOTCFG25_SHIFT          (25U)
#define MC_RGM_BOOT_CFG_BOOTCFG25_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG25(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG25_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG25_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG26_MASK           (0x4000000U)
#define MC_RGM_BOOT_CFG_BOOTCFG26_SHIFT          (26U)
#define MC_RGM_BOOT_CFG_BOOTCFG26_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG26(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG26_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG26_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG27_MASK           (0x8000000U)
#define MC_RGM_BOOT_CFG_BOOTCFG27_SHIFT          (27U)
#define MC_RGM_BOOT_CFG_BOOTCFG27_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG27(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG27_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG27_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG28_MASK           (0x10000000U)
#define MC_RGM_BOOT_CFG_BOOTCFG28_SHIFT          (28U)
#define MC_RGM_BOOT_CFG_BOOTCFG28_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG28(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG28_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG28_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG29_MASK           (0x20000000U)
#define MC_RGM_BOOT_CFG_BOOTCFG29_SHIFT          (29U)
#define MC_RGM_BOOT_CFG_BOOTCFG29_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG29(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG29_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG29_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG30_MASK           (0x40000000U)
#define MC_RGM_BOOT_CFG_BOOTCFG30_SHIFT          (30U)
#define MC_RGM_BOOT_CFG_BOOTCFG30_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG30(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG30_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG30_MASK)

#define MC_RGM_BOOT_CFG_BOOTCFG31_MASK           (0x80000000U)
#define MC_RGM_BOOT_CFG_BOOTCFG31_SHIFT          (31U)
#define MC_RGM_BOOT_CFG_BOOTCFG31_WIDTH          (1U)
#define MC_RGM_BOOT_CFG_BOOTCFG31(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_BOOT_CFG_BOOTCFG31_SHIFT)) & MC_RGM_BOOT_CFG_BOOTCFG31_MASK)
/*! @} */

/*! @name STDBYRTR - Standby Request Timeout Register */
/*! @{ */

#define MC_RGM_STDBYRTR_STDBYRT_MASK             (0xFFFFU)
#define MC_RGM_STDBYRTR_STDBYRT_SHIFT            (0U)
#define MC_RGM_STDBYRTR_STDBYRT_WIDTH            (16U)
#define MC_RGM_STDBYRTR_STDBYRT(x)               (((uint32_t)(((uint32_t)(x)) << MC_RGM_STDBYRTR_STDBYRT_SHIFT)) & MC_RGM_STDBYRTR_STDBYRT_MASK)
/*! @} */

/*! @name MODE_STAT - Mode Status Register */
/*! @{ */

#define MC_RGM_MODE_STAT_CUR_MODE_MASK           (0x7U)
#define MC_RGM_MODE_STAT_CUR_MODE_SHIFT          (0U)
#define MC_RGM_MODE_STAT_CUR_MODE_WIDTH          (3U)
#define MC_RGM_MODE_STAT_CUR_MODE(x)             (((uint32_t)(((uint32_t)(x)) << MC_RGM_MODE_STAT_CUR_MODE_SHIFT)) & MC_RGM_MODE_STAT_CUR_MODE_MASK)

#define MC_RGM_MODE_STAT_PREV_MODE_MASK          (0x38U)
#define MC_RGM_MODE_STAT_PREV_MODE_SHIFT         (3U)
#define MC_RGM_MODE_STAT_PREV_MODE_WIDTH         (3U)
#define MC_RGM_MODE_STAT_PREV_MODE(x)            (((uint32_t)(((uint32_t)(x)) << MC_RGM_MODE_STAT_PREV_MODE_SHIFT)) & MC_RGM_MODE_STAT_PREV_MODE_MASK)
/*! @} */

/*! @name DRATO - Destructive Request Acknowledge Timeout Register */
/*! @{ */

#define MC_RGM_DRATO_DES_RATO_MASK               (0x1U)
#define MC_RGM_DRATO_DES_RATO_SHIFT              (0U)
#define MC_RGM_DRATO_DES_RATO_WIDTH              (1U)
#define MC_RGM_DRATO_DES_RATO(x)                 (((uint32_t)(((uint32_t)(x)) << MC_RGM_DRATO_DES_RATO_SHIFT)) & MC_RGM_DRATO_DES_RATO_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MC_RGM_Register_Masks */

/*!
 * @}
 */ /* end of group MC_RGM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_MC_RGM_H_) */
