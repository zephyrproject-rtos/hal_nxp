/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K311_STCU.h
 * @version 1.2
 * @date 2023-01-10
 * @brief Peripheral Access Layer for S32K311_STCU
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
#if !defined(S32K311_STCU_H_)  /* Check if memory map has not been already included */
#define S32K311_STCU_H_

#include "S32K311_COMMON.h"

/* ----------------------------------------------------------------------------
   -- STCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STCU_Peripheral_Access_Layer STCU Peripheral Access Layer
 * @{
 */

/** STCU - Size of Registers Arrays */
#define STCU_LBSSW_COUNT                          4u
#define STCU_LBESW_COUNT                          4u
#define STCU_LBRMSW_COUNT                         4u
#define STCU_LBUFM_COUNT                          4u
#define STCU_MBSSW_COUNT                          8u
#define STCU_MBESW_COUNT                          8u
#define STCU_MBUFM_COUNT                          8u
#define STCU_LB_COUNT                             128u
#define STCU_MB_CTRL_COUNT                        256u

/** STCU - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[4];
  __IO uint32_t RUNSW;                             /**< STCU2 Run Software, offset: 0x4 */
  __O  uint32_t SKC;                               /**< STCU2 SK Code, offset: 0x8 */
  __IO uint32_t CFG;                               /**< STCU2 Configuration, offset: 0xC */
  uint8_t RESERVED_1[4];
  __IO uint32_t WDG;                               /**< STCU2 Watchdog Granularity, offset: 0x14 */
  uint8_t RESERVED_2[12];
  __IO uint32_t ERR_STAT;                          /**< STCU2 Error, offset: 0x24 */
  __IO uint32_t ERR_FM;                            /**< STCU2 Error FM, offset: 0x28 */
  uint8_t RESERVED_3[32];
  __I  uint32_t LBSSW[STCU_LBSSW_COUNT];           /**< STCU2 Online LBIST Status, array offset: 0x4C, array step: 0x4 */
  __I  uint32_t LBESW[STCU_LBESW_COUNT];           /**< STCU2 Online LBIST End Flag, array offset: 0x5C, array step: 0x4 */
  __IO uint32_t LBRMSW[STCU_LBRMSW_COUNT];         /**< STCU2 Online LBIST Reset Management, array offset: 0x6C, array step: 0x4 */
  __IO uint32_t LBUFM[STCU_LBUFM_COUNT];           /**< STCU2 Online LBIST Unrecoverable FM, array offset: 0x7C, array step: 0x4 */
  uint8_t RESERVED_4[128];
  __I  uint32_t MBSSW[STCU_MBSSW_COUNT];           /**< STCU2 Online MBIST Status, array offset: 0x10C, array step: 0x4 */
  uint8_t RESERVED_5[32];
  __I  uint32_t MBESW[STCU_MBESW_COUNT];           /**< STCU2 Online MBIST End Flag, array offset: 0x14C, array step: 0x4 */
  uint8_t RESERVED_6[32];
  __IO uint32_t MBUFM[STCU_MBUFM_COUNT];           /**< STCU2 MBIST Unrecoverable FM, array offset: 0x18C, array step: 0x4 */
  uint8_t RESERVED_7[84];
  struct {                                         /* offset: 0x200, array step: 0x40 */
    __IO uint32_t CTRL;                              /**< STCU2 LBIST Control, array offset: 0x200, array step: 0x40 */
    __IO uint32_t PCS;                               /**< STCU2 LBIST PC Stop, array offset: 0x204, array step: 0x40 */
    uint8_t RESERVED_0[24];
    __IO uint32_t MISRELSW;                          /**< STCU2 Online LBIST MISR Expected Low, array offset: 0x220, array step: 0x40 */
    uint8_t RESERVED_1[4];
    __I  uint32_t MISRRLSW;                          /**< STCU2 Online LBIST MISR Read Low, array offset: 0x228, array step: 0x40 */
    uint8_t RESERVED_2[20];
  } LB[STCU_LB_COUNT];
  __IO uint32_t ALGOSEL;                           /**< STCU2 Algorithm Select, offset: 0x2200 */
  uint8_t RESERVED_8[8];
  __IO uint32_t STGGR;                             /**< STCU2 MBIST Stagger, offset: 0x220C */
  __IO uint32_t BSTART;                            /**< STCU2 BIST Start, offset: 0x2210 */
  __IO uint32_t MB_CTRL[STCU_MB_CTRL_COUNT];       /**< STCU2 MBIST Control, array offset: 0x2214, array step: 0x4 */
} STCU_Type, *STCU_MemMapPtr;

/** Number of instances of the STCU module. */
#define STCU_INSTANCE_COUNT                      (1u)

/* STCU - Peripheral instance base addresses */
/** Peripheral STCU base address */
#define IP_STCU_BASE                             (0x403A0000u)
/** Peripheral STCU base pointer */
#define IP_STCU                                  ((STCU_Type *)IP_STCU_BASE)
/** Array initializer of STCU peripheral base addresses */
#define IP_STCU_BASE_ADDRS                       { IP_STCU_BASE }
/** Array initializer of STCU peripheral base pointers */
#define IP_STCU_BASE_PTRS                        { IP_STCU }

/* ----------------------------------------------------------------------------
   -- STCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STCU_Register_Masks STCU Register Masks
 * @{
 */

/*! @name RUNSW - STCU2 Run Software */
/*! @{ */

#define STCU_RUNSW_RUNSW_MASK                    (0x1U)
#define STCU_RUNSW_RUNSW_SHIFT                   (0U)
#define STCU_RUNSW_RUNSW_WIDTH                   (1U)
#define STCU_RUNSW_RUNSW(x)                      (((uint32_t)(((uint32_t)(x)) << STCU_RUNSW_RUNSW_SHIFT)) & STCU_RUNSW_RUNSW_MASK)

#define STCU_RUNSW_LBSWPLLEN_MASK                (0x100U)
#define STCU_RUNSW_LBSWPLLEN_SHIFT               (8U)
#define STCU_RUNSW_LBSWPLLEN_WIDTH               (1U)
#define STCU_RUNSW_LBSWPLLEN(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_RUNSW_LBSWPLLEN_SHIFT)) & STCU_RUNSW_LBSWPLLEN_MASK)

#define STCU_RUNSW_MBSWPLLEN_MASK                (0x200U)
#define STCU_RUNSW_MBSWPLLEN_SHIFT               (9U)
#define STCU_RUNSW_MBSWPLLEN_WIDTH               (1U)
#define STCU_RUNSW_MBSWPLLEN(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_RUNSW_MBSWPLLEN_SHIFT)) & STCU_RUNSW_MBSWPLLEN_MASK)
/*! @} */

/*! @name SKC - STCU2 SK Code */
/*! @{ */

#define STCU_SKC_SKC_MASK                        (0xFFFFFFFFU)
#define STCU_SKC_SKC_SHIFT                       (0U)
#define STCU_SKC_SKC_WIDTH                       (32U)
#define STCU_SKC_SKC(x)                          (((uint32_t)(((uint32_t)(x)) << STCU_SKC_SKC_SHIFT)) & STCU_SKC_SKC_MASK)
/*! @} */

/*! @name CFG - STCU2 Configuration */
/*! @{ */

#define STCU_CFG_CLK_CFG_MASK                    (0x7U)
#define STCU_CFG_CLK_CFG_SHIFT                   (0U)
#define STCU_CFG_CLK_CFG_WIDTH                   (3U)
#define STCU_CFG_CLK_CFG(x)                      (((uint32_t)(((uint32_t)(x)) << STCU_CFG_CLK_CFG_SHIFT)) & STCU_CFG_CLK_CFG_MASK)

#define STCU_CFG_WRP_MASK                        (0x100U)
#define STCU_CFG_WRP_SHIFT                       (8U)
#define STCU_CFG_WRP_WIDTH                       (1U)
#define STCU_CFG_WRP(x)                          (((uint32_t)(((uint32_t)(x)) << STCU_CFG_WRP_SHIFT)) & STCU_CFG_WRP_MASK)

#define STCU_CFG_LB_DELAY_MASK                   (0x1FE000U)
#define STCU_CFG_LB_DELAY_SHIFT                  (13U)
#define STCU_CFG_LB_DELAY_WIDTH                  (8U)
#define STCU_CFG_LB_DELAY(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_CFG_LB_DELAY_SHIFT)) & STCU_CFG_LB_DELAY_MASK)

#define STCU_CFG_PTR_MASK                        (0x7FE00000U)
#define STCU_CFG_PTR_SHIFT                       (21U)
#define STCU_CFG_PTR_WIDTH                       (10U)
#define STCU_CFG_PTR(x)                          (((uint32_t)(((uint32_t)(x)) << STCU_CFG_PTR_SHIFT)) & STCU_CFG_PTR_MASK)
/*! @} */

/*! @name WDG - STCU2 Watchdog Granularity */
/*! @{ */

#define STCU_WDG_WDGEOC_MASK                     (0xFFFFFFFFU)
#define STCU_WDG_WDGEOC_SHIFT                    (0U)
#define STCU_WDG_WDGEOC_WIDTH                    (32U)
#define STCU_WDG_WDGEOC(x)                       (((uint32_t)(((uint32_t)(x)) << STCU_WDG_WDGEOC_SHIFT)) & STCU_WDG_WDGEOC_MASK)
/*! @} */

/*! @name ERR_STAT - STCU2 Error */
/*! @{ */

#define STCU_ERR_STAT_RFSF_MASK                  (0x100U)
#define STCU_ERR_STAT_RFSF_SHIFT                 (8U)
#define STCU_ERR_STAT_RFSF_WIDTH                 (1U)
#define STCU_ERR_STAT_RFSF(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_RFSF_SHIFT)) & STCU_ERR_STAT_RFSF_MASK)

#define STCU_ERR_STAT_UFSF_MASK                  (0x200U)
#define STCU_ERR_STAT_UFSF_SHIFT                 (9U)
#define STCU_ERR_STAT_UFSF_WIDTH                 (1U)
#define STCU_ERR_STAT_UFSF(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_UFSF_SHIFT)) & STCU_ERR_STAT_UFSF_MASK)

#define STCU_ERR_STAT_INVPSW_MASK                (0x10000U)
#define STCU_ERR_STAT_INVPSW_SHIFT               (16U)
#define STCU_ERR_STAT_INVPSW_WIDTH               (1U)
#define STCU_ERR_STAT_INVPSW(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_INVPSW_SHIFT)) & STCU_ERR_STAT_INVPSW_MASK)

#define STCU_ERR_STAT_ENGESW_MASK                (0x20000U)
#define STCU_ERR_STAT_ENGESW_SHIFT               (17U)
#define STCU_ERR_STAT_ENGESW_WIDTH               (1U)
#define STCU_ERR_STAT_ENGESW(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_ENGESW_SHIFT)) & STCU_ERR_STAT_ENGESW_MASK)

#define STCU_ERR_STAT_WDTOSW_MASK                (0x80000U)
#define STCU_ERR_STAT_WDTOSW_SHIFT               (19U)
#define STCU_ERR_STAT_WDTOSW_WIDTH               (1U)
#define STCU_ERR_STAT_WDTOSW(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_WDTOSW_SHIFT)) & STCU_ERR_STAT_WDTOSW_MASK)

#define STCU_ERR_STAT_LOCKESW_MASK               (0x100000U)
#define STCU_ERR_STAT_LOCKESW_SHIFT              (20U)
#define STCU_ERR_STAT_LOCKESW_WIDTH              (1U)
#define STCU_ERR_STAT_LOCKESW(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_LOCKESW_SHIFT)) & STCU_ERR_STAT_LOCKESW_MASK)
/*! @} */

/*! @name ERR_FM - STCU2 Error FM */
/*! @{ */

#define STCU_ERR_FM_INVPUFM_MASK                 (0x1U)
#define STCU_ERR_FM_INVPUFM_SHIFT                (0U)
#define STCU_ERR_FM_INVPUFM_WIDTH                (1U)
#define STCU_ERR_FM_INVPUFM(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_ERR_FM_INVPUFM_SHIFT)) & STCU_ERR_FM_INVPUFM_MASK)

#define STCU_ERR_FM_ENGEUFM_MASK                 (0x2U)
#define STCU_ERR_FM_ENGEUFM_SHIFT                (1U)
#define STCU_ERR_FM_ENGEUFM_WIDTH                (1U)
#define STCU_ERR_FM_ENGEUFM(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_ERR_FM_ENGEUFM_SHIFT)) & STCU_ERR_FM_ENGEUFM_MASK)

#define STCU_ERR_FM_WDTOUFM_MASK                 (0x8U)
#define STCU_ERR_FM_WDTOUFM_SHIFT                (3U)
#define STCU_ERR_FM_WDTOUFM_WIDTH                (1U)
#define STCU_ERR_FM_WDTOUFM(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_ERR_FM_WDTOUFM_SHIFT)) & STCU_ERR_FM_WDTOUFM_MASK)

#define STCU_ERR_FM_LOCKEUFM_MASK                (0x10U)
#define STCU_ERR_FM_LOCKEUFM_SHIFT               (4U)
#define STCU_ERR_FM_LOCKEUFM_WIDTH               (1U)
#define STCU_ERR_FM_LOCKEUFM(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_ERR_FM_LOCKEUFM_SHIFT)) & STCU_ERR_FM_LOCKEUFM_MASK)
/*! @} */

/*! @name LBSSW - STCU2 Online LBIST Status */
/*! @{ */

#define STCU_LBSSW_LBSSW0_MASK                   (0x1U)
#define STCU_LBSSW_LBSSW0_SHIFT                  (0U)
#define STCU_LBSSW_LBSSW0_WIDTH                  (1U)
#define STCU_LBSSW_LBSSW0(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW0_SHIFT)) & STCU_LBSSW_LBSSW0_MASK)

#define STCU_LBSSW_LBSSW1_MASK                   (0x2U)
#define STCU_LBSSW_LBSSW1_SHIFT                  (1U)
#define STCU_LBSSW_LBSSW1_WIDTH                  (1U)
#define STCU_LBSSW_LBSSW1(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW1_SHIFT)) & STCU_LBSSW_LBSSW1_MASK)

#define STCU_LBSSW_LBSSW2_MASK                   (0x4U)
#define STCU_LBSSW_LBSSW2_SHIFT                  (2U)
#define STCU_LBSSW_LBSSW2_WIDTH                  (1U)
#define STCU_LBSSW_LBSSW2(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW2_SHIFT)) & STCU_LBSSW_LBSSW2_MASK)

#define STCU_LBSSW_LBSSW3_MASK                   (0x8U)
#define STCU_LBSSW_LBSSW3_SHIFT                  (3U)
#define STCU_LBSSW_LBSSW3_WIDTH                  (1U)
#define STCU_LBSSW_LBSSW3(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW3_SHIFT)) & STCU_LBSSW_LBSSW3_MASK)

#define STCU_LBSSW_LBSSW4_MASK                   (0x10U)
#define STCU_LBSSW_LBSSW4_SHIFT                  (4U)
#define STCU_LBSSW_LBSSW4_WIDTH                  (1U)
#define STCU_LBSSW_LBSSW4(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW4_SHIFT)) & STCU_LBSSW_LBSSW4_MASK)

#define STCU_LBSSW_LBSSW5_MASK                   (0x20U)
#define STCU_LBSSW_LBSSW5_SHIFT                  (5U)
#define STCU_LBSSW_LBSSW5_WIDTH                  (1U)
#define STCU_LBSSW_LBSSW5(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW5_SHIFT)) & STCU_LBSSW_LBSSW5_MASK)

#define STCU_LBSSW_LBSSW6_MASK                   (0x40U)
#define STCU_LBSSW_LBSSW6_SHIFT                  (6U)
#define STCU_LBSSW_LBSSW6_WIDTH                  (1U)
#define STCU_LBSSW_LBSSW6(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW6_SHIFT)) & STCU_LBSSW_LBSSW6_MASK)

#define STCU_LBSSW_LBSSW7_MASK                   (0x80U)
#define STCU_LBSSW_LBSSW7_SHIFT                  (7U)
#define STCU_LBSSW_LBSSW7_WIDTH                  (1U)
#define STCU_LBSSW_LBSSW7(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW7_SHIFT)) & STCU_LBSSW_LBSSW7_MASK)

#define STCU_LBSSW_LBSSW8_MASK                   (0x100U)
#define STCU_LBSSW_LBSSW8_SHIFT                  (8U)
#define STCU_LBSSW_LBSSW8_WIDTH                  (1U)
#define STCU_LBSSW_LBSSW8(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW8_SHIFT)) & STCU_LBSSW_LBSSW8_MASK)

#define STCU_LBSSW_LBSSW9_MASK                   (0x200U)
#define STCU_LBSSW_LBSSW9_SHIFT                  (9U)
#define STCU_LBSSW_LBSSW9_WIDTH                  (1U)
#define STCU_LBSSW_LBSSW9(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW9_SHIFT)) & STCU_LBSSW_LBSSW9_MASK)

#define STCU_LBSSW_LBSSW10_MASK                  (0x400U)
#define STCU_LBSSW_LBSSW10_SHIFT                 (10U)
#define STCU_LBSSW_LBSSW10_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW10(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW10_SHIFT)) & STCU_LBSSW_LBSSW10_MASK)

#define STCU_LBSSW_LBSSW11_MASK                  (0x800U)
#define STCU_LBSSW_LBSSW11_SHIFT                 (11U)
#define STCU_LBSSW_LBSSW11_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW11(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW11_SHIFT)) & STCU_LBSSW_LBSSW11_MASK)

#define STCU_LBSSW_LBSSW12_MASK                  (0x1000U)
#define STCU_LBSSW_LBSSW12_SHIFT                 (12U)
#define STCU_LBSSW_LBSSW12_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW12(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW12_SHIFT)) & STCU_LBSSW_LBSSW12_MASK)

#define STCU_LBSSW_LBSSW13_MASK                  (0x2000U)
#define STCU_LBSSW_LBSSW13_SHIFT                 (13U)
#define STCU_LBSSW_LBSSW13_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW13(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW13_SHIFT)) & STCU_LBSSW_LBSSW13_MASK)

#define STCU_LBSSW_LBSSW14_MASK                  (0x4000U)
#define STCU_LBSSW_LBSSW14_SHIFT                 (14U)
#define STCU_LBSSW_LBSSW14_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW14(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW14_SHIFT)) & STCU_LBSSW_LBSSW14_MASK)

#define STCU_LBSSW_LBSSW15_MASK                  (0x8000U)
#define STCU_LBSSW_LBSSW15_SHIFT                 (15U)
#define STCU_LBSSW_LBSSW15_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW15(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW15_SHIFT)) & STCU_LBSSW_LBSSW15_MASK)

#define STCU_LBSSW_LBSSW16_MASK                  (0x10000U)
#define STCU_LBSSW_LBSSW16_SHIFT                 (16U)
#define STCU_LBSSW_LBSSW16_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW16(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW16_SHIFT)) & STCU_LBSSW_LBSSW16_MASK)

#define STCU_LBSSW_LBSSW17_MASK                  (0x20000U)
#define STCU_LBSSW_LBSSW17_SHIFT                 (17U)
#define STCU_LBSSW_LBSSW17_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW17(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW17_SHIFT)) & STCU_LBSSW_LBSSW17_MASK)

#define STCU_LBSSW_LBSSW18_MASK                  (0x40000U)
#define STCU_LBSSW_LBSSW18_SHIFT                 (18U)
#define STCU_LBSSW_LBSSW18_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW18(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW18_SHIFT)) & STCU_LBSSW_LBSSW18_MASK)

#define STCU_LBSSW_LBSSW19_MASK                  (0x80000U)
#define STCU_LBSSW_LBSSW19_SHIFT                 (19U)
#define STCU_LBSSW_LBSSW19_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW19(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW19_SHIFT)) & STCU_LBSSW_LBSSW19_MASK)

#define STCU_LBSSW_LBSSW20_MASK                  (0x100000U)
#define STCU_LBSSW_LBSSW20_SHIFT                 (20U)
#define STCU_LBSSW_LBSSW20_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW20(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW20_SHIFT)) & STCU_LBSSW_LBSSW20_MASK)

#define STCU_LBSSW_LBSSW21_MASK                  (0x200000U)
#define STCU_LBSSW_LBSSW21_SHIFT                 (21U)
#define STCU_LBSSW_LBSSW21_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW21(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW21_SHIFT)) & STCU_LBSSW_LBSSW21_MASK)

#define STCU_LBSSW_LBSSW22_MASK                  (0x400000U)
#define STCU_LBSSW_LBSSW22_SHIFT                 (22U)
#define STCU_LBSSW_LBSSW22_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW22(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW22_SHIFT)) & STCU_LBSSW_LBSSW22_MASK)

#define STCU_LBSSW_LBSSW23_MASK                  (0x800000U)
#define STCU_LBSSW_LBSSW23_SHIFT                 (23U)
#define STCU_LBSSW_LBSSW23_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW23(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW23_SHIFT)) & STCU_LBSSW_LBSSW23_MASK)

#define STCU_LBSSW_LBSSW24_MASK                  (0x1000000U)
#define STCU_LBSSW_LBSSW24_SHIFT                 (24U)
#define STCU_LBSSW_LBSSW24_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW24(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW24_SHIFT)) & STCU_LBSSW_LBSSW24_MASK)

#define STCU_LBSSW_LBSSW25_MASK                  (0x2000000U)
#define STCU_LBSSW_LBSSW25_SHIFT                 (25U)
#define STCU_LBSSW_LBSSW25_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW25(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW25_SHIFT)) & STCU_LBSSW_LBSSW25_MASK)

#define STCU_LBSSW_LBSSW26_MASK                  (0x4000000U)
#define STCU_LBSSW_LBSSW26_SHIFT                 (26U)
#define STCU_LBSSW_LBSSW26_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW26(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW26_SHIFT)) & STCU_LBSSW_LBSSW26_MASK)

#define STCU_LBSSW_LBSSW27_MASK                  (0x8000000U)
#define STCU_LBSSW_LBSSW27_SHIFT                 (27U)
#define STCU_LBSSW_LBSSW27_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW27(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW27_SHIFT)) & STCU_LBSSW_LBSSW27_MASK)

#define STCU_LBSSW_LBSSW28_MASK                  (0x10000000U)
#define STCU_LBSSW_LBSSW28_SHIFT                 (28U)
#define STCU_LBSSW_LBSSW28_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW28(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW28_SHIFT)) & STCU_LBSSW_LBSSW28_MASK)

#define STCU_LBSSW_LBSSW29_MASK                  (0x20000000U)
#define STCU_LBSSW_LBSSW29_SHIFT                 (29U)
#define STCU_LBSSW_LBSSW29_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW29(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW29_SHIFT)) & STCU_LBSSW_LBSSW29_MASK)

#define STCU_LBSSW_LBSSW30_MASK                  (0x40000000U)
#define STCU_LBSSW_LBSSW30_SHIFT                 (30U)
#define STCU_LBSSW_LBSSW30_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW30(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW30_SHIFT)) & STCU_LBSSW_LBSSW30_MASK)

#define STCU_LBSSW_LBSSW31_MASK                  (0x80000000U)
#define STCU_LBSSW_LBSSW31_SHIFT                 (31U)
#define STCU_LBSSW_LBSSW31_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW31(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW31_SHIFT)) & STCU_LBSSW_LBSSW31_MASK)

#define STCU_LBSSW_LBSSW32_MASK                  (0x1U)
#define STCU_LBSSW_LBSSW32_SHIFT                 (0U)
#define STCU_LBSSW_LBSSW32_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW32(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW32_SHIFT)) & STCU_LBSSW_LBSSW32_MASK)

#define STCU_LBSSW_LBSSW33_MASK                  (0x2U)
#define STCU_LBSSW_LBSSW33_SHIFT                 (1U)
#define STCU_LBSSW_LBSSW33_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW33(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW33_SHIFT)) & STCU_LBSSW_LBSSW33_MASK)

#define STCU_LBSSW_LBSSW34_MASK                  (0x4U)
#define STCU_LBSSW_LBSSW34_SHIFT                 (2U)
#define STCU_LBSSW_LBSSW34_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW34(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW34_SHIFT)) & STCU_LBSSW_LBSSW34_MASK)

#define STCU_LBSSW_LBSSW35_MASK                  (0x8U)
#define STCU_LBSSW_LBSSW35_SHIFT                 (3U)
#define STCU_LBSSW_LBSSW35_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW35(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW35_SHIFT)) & STCU_LBSSW_LBSSW35_MASK)

#define STCU_LBSSW_LBSSW36_MASK                  (0x10U)
#define STCU_LBSSW_LBSSW36_SHIFT                 (4U)
#define STCU_LBSSW_LBSSW36_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW36(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW36_SHIFT)) & STCU_LBSSW_LBSSW36_MASK)

#define STCU_LBSSW_LBSSW37_MASK                  (0x20U)
#define STCU_LBSSW_LBSSW37_SHIFT                 (5U)
#define STCU_LBSSW_LBSSW37_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW37(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW37_SHIFT)) & STCU_LBSSW_LBSSW37_MASK)

#define STCU_LBSSW_LBSSW38_MASK                  (0x40U)
#define STCU_LBSSW_LBSSW38_SHIFT                 (6U)
#define STCU_LBSSW_LBSSW38_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW38(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW38_SHIFT)) & STCU_LBSSW_LBSSW38_MASK)

#define STCU_LBSSW_LBSSW39_MASK                  (0x80U)
#define STCU_LBSSW_LBSSW39_SHIFT                 (7U)
#define STCU_LBSSW_LBSSW39_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW39(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW39_SHIFT)) & STCU_LBSSW_LBSSW39_MASK)

#define STCU_LBSSW_LBSSW40_MASK                  (0x100U)
#define STCU_LBSSW_LBSSW40_SHIFT                 (8U)
#define STCU_LBSSW_LBSSW40_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW40(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW40_SHIFT)) & STCU_LBSSW_LBSSW40_MASK)

#define STCU_LBSSW_LBSSW41_MASK                  (0x200U)
#define STCU_LBSSW_LBSSW41_SHIFT                 (9U)
#define STCU_LBSSW_LBSSW41_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW41(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW41_SHIFT)) & STCU_LBSSW_LBSSW41_MASK)

#define STCU_LBSSW_LBSSW42_MASK                  (0x400U)
#define STCU_LBSSW_LBSSW42_SHIFT                 (10U)
#define STCU_LBSSW_LBSSW42_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW42(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW42_SHIFT)) & STCU_LBSSW_LBSSW42_MASK)

#define STCU_LBSSW_LBSSW43_MASK                  (0x800U)
#define STCU_LBSSW_LBSSW43_SHIFT                 (11U)
#define STCU_LBSSW_LBSSW43_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW43(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW43_SHIFT)) & STCU_LBSSW_LBSSW43_MASK)

#define STCU_LBSSW_LBSSW44_MASK                  (0x1000U)
#define STCU_LBSSW_LBSSW44_SHIFT                 (12U)
#define STCU_LBSSW_LBSSW44_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW44(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW44_SHIFT)) & STCU_LBSSW_LBSSW44_MASK)

#define STCU_LBSSW_LBSSW45_MASK                  (0x2000U)
#define STCU_LBSSW_LBSSW45_SHIFT                 (13U)
#define STCU_LBSSW_LBSSW45_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW45(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW45_SHIFT)) & STCU_LBSSW_LBSSW45_MASK)

#define STCU_LBSSW_LBSSW46_MASK                  (0x4000U)
#define STCU_LBSSW_LBSSW46_SHIFT                 (14U)
#define STCU_LBSSW_LBSSW46_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW46(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW46_SHIFT)) & STCU_LBSSW_LBSSW46_MASK)

#define STCU_LBSSW_LBSSW47_MASK                  (0x8000U)
#define STCU_LBSSW_LBSSW47_SHIFT                 (15U)
#define STCU_LBSSW_LBSSW47_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW47(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW47_SHIFT)) & STCU_LBSSW_LBSSW47_MASK)

#define STCU_LBSSW_LBSSW48_MASK                  (0x10000U)
#define STCU_LBSSW_LBSSW48_SHIFT                 (16U)
#define STCU_LBSSW_LBSSW48_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW48(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW48_SHIFT)) & STCU_LBSSW_LBSSW48_MASK)

#define STCU_LBSSW_LBSSW49_MASK                  (0x20000U)
#define STCU_LBSSW_LBSSW49_SHIFT                 (17U)
#define STCU_LBSSW_LBSSW49_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW49(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW49_SHIFT)) & STCU_LBSSW_LBSSW49_MASK)

#define STCU_LBSSW_LBSSW50_MASK                  (0x40000U)
#define STCU_LBSSW_LBSSW50_SHIFT                 (18U)
#define STCU_LBSSW_LBSSW50_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW50(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW50_SHIFT)) & STCU_LBSSW_LBSSW50_MASK)

#define STCU_LBSSW_LBSSW51_MASK                  (0x80000U)
#define STCU_LBSSW_LBSSW51_SHIFT                 (19U)
#define STCU_LBSSW_LBSSW51_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW51(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW51_SHIFT)) & STCU_LBSSW_LBSSW51_MASK)

#define STCU_LBSSW_LBSSW52_MASK                  (0x100000U)
#define STCU_LBSSW_LBSSW52_SHIFT                 (20U)
#define STCU_LBSSW_LBSSW52_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW52(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW52_SHIFT)) & STCU_LBSSW_LBSSW52_MASK)

#define STCU_LBSSW_LBSSW53_MASK                  (0x200000U)
#define STCU_LBSSW_LBSSW53_SHIFT                 (21U)
#define STCU_LBSSW_LBSSW53_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW53(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW53_SHIFT)) & STCU_LBSSW_LBSSW53_MASK)

#define STCU_LBSSW_LBSSW54_MASK                  (0x400000U)
#define STCU_LBSSW_LBSSW54_SHIFT                 (22U)
#define STCU_LBSSW_LBSSW54_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW54(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW54_SHIFT)) & STCU_LBSSW_LBSSW54_MASK)

#define STCU_LBSSW_LBSSW55_MASK                  (0x800000U)
#define STCU_LBSSW_LBSSW55_SHIFT                 (23U)
#define STCU_LBSSW_LBSSW55_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW55(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW55_SHIFT)) & STCU_LBSSW_LBSSW55_MASK)

#define STCU_LBSSW_LBSSW56_MASK                  (0x1000000U)
#define STCU_LBSSW_LBSSW56_SHIFT                 (24U)
#define STCU_LBSSW_LBSSW56_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW56(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW56_SHIFT)) & STCU_LBSSW_LBSSW56_MASK)

#define STCU_LBSSW_LBSSW57_MASK                  (0x2000000U)
#define STCU_LBSSW_LBSSW57_SHIFT                 (25U)
#define STCU_LBSSW_LBSSW57_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW57(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW57_SHIFT)) & STCU_LBSSW_LBSSW57_MASK)

#define STCU_LBSSW_LBSSW58_MASK                  (0x4000000U)
#define STCU_LBSSW_LBSSW58_SHIFT                 (26U)
#define STCU_LBSSW_LBSSW58_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW58(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW58_SHIFT)) & STCU_LBSSW_LBSSW58_MASK)

#define STCU_LBSSW_LBSSW59_MASK                  (0x8000000U)
#define STCU_LBSSW_LBSSW59_SHIFT                 (27U)
#define STCU_LBSSW_LBSSW59_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW59(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW59_SHIFT)) & STCU_LBSSW_LBSSW59_MASK)

#define STCU_LBSSW_LBSSW60_MASK                  (0x10000000U)
#define STCU_LBSSW_LBSSW60_SHIFT                 (28U)
#define STCU_LBSSW_LBSSW60_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW60(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW60_SHIFT)) & STCU_LBSSW_LBSSW60_MASK)

#define STCU_LBSSW_LBSSW61_MASK                  (0x20000000U)
#define STCU_LBSSW_LBSSW61_SHIFT                 (29U)
#define STCU_LBSSW_LBSSW61_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW61(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW61_SHIFT)) & STCU_LBSSW_LBSSW61_MASK)

#define STCU_LBSSW_LBSSW62_MASK                  (0x40000000U)
#define STCU_LBSSW_LBSSW62_SHIFT                 (30U)
#define STCU_LBSSW_LBSSW62_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW62(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW62_SHIFT)) & STCU_LBSSW_LBSSW62_MASK)

#define STCU_LBSSW_LBSSW63_MASK                  (0x80000000U)
#define STCU_LBSSW_LBSSW63_SHIFT                 (31U)
#define STCU_LBSSW_LBSSW63_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW63(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW63_SHIFT)) & STCU_LBSSW_LBSSW63_MASK)

#define STCU_LBSSW_LBSSW64_MASK                  (0x1U)
#define STCU_LBSSW_LBSSW64_SHIFT                 (0U)
#define STCU_LBSSW_LBSSW64_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW64(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW64_SHIFT)) & STCU_LBSSW_LBSSW64_MASK)

#define STCU_LBSSW_LBSSW65_MASK                  (0x2U)
#define STCU_LBSSW_LBSSW65_SHIFT                 (1U)
#define STCU_LBSSW_LBSSW65_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW65(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW65_SHIFT)) & STCU_LBSSW_LBSSW65_MASK)

#define STCU_LBSSW_LBSSW66_MASK                  (0x4U)
#define STCU_LBSSW_LBSSW66_SHIFT                 (2U)
#define STCU_LBSSW_LBSSW66_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW66(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW66_SHIFT)) & STCU_LBSSW_LBSSW66_MASK)

#define STCU_LBSSW_LBSSW67_MASK                  (0x8U)
#define STCU_LBSSW_LBSSW67_SHIFT                 (3U)
#define STCU_LBSSW_LBSSW67_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW67(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW67_SHIFT)) & STCU_LBSSW_LBSSW67_MASK)

#define STCU_LBSSW_LBSSW68_MASK                  (0x10U)
#define STCU_LBSSW_LBSSW68_SHIFT                 (4U)
#define STCU_LBSSW_LBSSW68_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW68(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW68_SHIFT)) & STCU_LBSSW_LBSSW68_MASK)

#define STCU_LBSSW_LBSSW69_MASK                  (0x20U)
#define STCU_LBSSW_LBSSW69_SHIFT                 (5U)
#define STCU_LBSSW_LBSSW69_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW69(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW69_SHIFT)) & STCU_LBSSW_LBSSW69_MASK)

#define STCU_LBSSW_LBSSW70_MASK                  (0x40U)
#define STCU_LBSSW_LBSSW70_SHIFT                 (6U)
#define STCU_LBSSW_LBSSW70_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW70(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW70_SHIFT)) & STCU_LBSSW_LBSSW70_MASK)

#define STCU_LBSSW_LBSSW71_MASK                  (0x80U)
#define STCU_LBSSW_LBSSW71_SHIFT                 (7U)
#define STCU_LBSSW_LBSSW71_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW71(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW71_SHIFT)) & STCU_LBSSW_LBSSW71_MASK)

#define STCU_LBSSW_LBSSW72_MASK                  (0x100U)
#define STCU_LBSSW_LBSSW72_SHIFT                 (8U)
#define STCU_LBSSW_LBSSW72_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW72(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW72_SHIFT)) & STCU_LBSSW_LBSSW72_MASK)

#define STCU_LBSSW_LBSSW73_MASK                  (0x200U)
#define STCU_LBSSW_LBSSW73_SHIFT                 (9U)
#define STCU_LBSSW_LBSSW73_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW73(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW73_SHIFT)) & STCU_LBSSW_LBSSW73_MASK)

#define STCU_LBSSW_LBSSW74_MASK                  (0x400U)
#define STCU_LBSSW_LBSSW74_SHIFT                 (10U)
#define STCU_LBSSW_LBSSW74_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW74(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW74_SHIFT)) & STCU_LBSSW_LBSSW74_MASK)

#define STCU_LBSSW_LBSSW75_MASK                  (0x800U)
#define STCU_LBSSW_LBSSW75_SHIFT                 (11U)
#define STCU_LBSSW_LBSSW75_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW75(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW75_SHIFT)) & STCU_LBSSW_LBSSW75_MASK)

#define STCU_LBSSW_LBSSW76_MASK                  (0x1000U)
#define STCU_LBSSW_LBSSW76_SHIFT                 (12U)
#define STCU_LBSSW_LBSSW76_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW76(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW76_SHIFT)) & STCU_LBSSW_LBSSW76_MASK)

#define STCU_LBSSW_LBSSW77_MASK                  (0x2000U)
#define STCU_LBSSW_LBSSW77_SHIFT                 (13U)
#define STCU_LBSSW_LBSSW77_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW77(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW77_SHIFT)) & STCU_LBSSW_LBSSW77_MASK)

#define STCU_LBSSW_LBSSW78_MASK                  (0x4000U)
#define STCU_LBSSW_LBSSW78_SHIFT                 (14U)
#define STCU_LBSSW_LBSSW78_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW78(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW78_SHIFT)) & STCU_LBSSW_LBSSW78_MASK)

#define STCU_LBSSW_LBSSW79_MASK                  (0x8000U)
#define STCU_LBSSW_LBSSW79_SHIFT                 (15U)
#define STCU_LBSSW_LBSSW79_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW79(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW79_SHIFT)) & STCU_LBSSW_LBSSW79_MASK)

#define STCU_LBSSW_LBSSW80_MASK                  (0x10000U)
#define STCU_LBSSW_LBSSW80_SHIFT                 (16U)
#define STCU_LBSSW_LBSSW80_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW80(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW80_SHIFT)) & STCU_LBSSW_LBSSW80_MASK)

#define STCU_LBSSW_LBSSW81_MASK                  (0x20000U)
#define STCU_LBSSW_LBSSW81_SHIFT                 (17U)
#define STCU_LBSSW_LBSSW81_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW81(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW81_SHIFT)) & STCU_LBSSW_LBSSW81_MASK)

#define STCU_LBSSW_LBSSW82_MASK                  (0x40000U)
#define STCU_LBSSW_LBSSW82_SHIFT                 (18U)
#define STCU_LBSSW_LBSSW82_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW82(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW82_SHIFT)) & STCU_LBSSW_LBSSW82_MASK)

#define STCU_LBSSW_LBSSW83_MASK                  (0x80000U)
#define STCU_LBSSW_LBSSW83_SHIFT                 (19U)
#define STCU_LBSSW_LBSSW83_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW83(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW83_SHIFT)) & STCU_LBSSW_LBSSW83_MASK)

#define STCU_LBSSW_LBSSW84_MASK                  (0x100000U)
#define STCU_LBSSW_LBSSW84_SHIFT                 (20U)
#define STCU_LBSSW_LBSSW84_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW84(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW84_SHIFT)) & STCU_LBSSW_LBSSW84_MASK)

#define STCU_LBSSW_LBSSW85_MASK                  (0x200000U)
#define STCU_LBSSW_LBSSW85_SHIFT                 (21U)
#define STCU_LBSSW_LBSSW85_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW85(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW85_SHIFT)) & STCU_LBSSW_LBSSW85_MASK)

#define STCU_LBSSW_LBSSW86_MASK                  (0x400000U)
#define STCU_LBSSW_LBSSW86_SHIFT                 (22U)
#define STCU_LBSSW_LBSSW86_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW86(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW86_SHIFT)) & STCU_LBSSW_LBSSW86_MASK)

#define STCU_LBSSW_LBSSW87_MASK                  (0x800000U)
#define STCU_LBSSW_LBSSW87_SHIFT                 (23U)
#define STCU_LBSSW_LBSSW87_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW87(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW87_SHIFT)) & STCU_LBSSW_LBSSW87_MASK)

#define STCU_LBSSW_LBSSW88_MASK                  (0x1000000U)
#define STCU_LBSSW_LBSSW88_SHIFT                 (24U)
#define STCU_LBSSW_LBSSW88_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW88(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW88_SHIFT)) & STCU_LBSSW_LBSSW88_MASK)

#define STCU_LBSSW_LBSSW89_MASK                  (0x2000000U)
#define STCU_LBSSW_LBSSW89_SHIFT                 (25U)
#define STCU_LBSSW_LBSSW89_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW89(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW89_SHIFT)) & STCU_LBSSW_LBSSW89_MASK)

#define STCU_LBSSW_LBSSW90_MASK                  (0x4000000U)
#define STCU_LBSSW_LBSSW90_SHIFT                 (26U)
#define STCU_LBSSW_LBSSW90_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW90(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW90_SHIFT)) & STCU_LBSSW_LBSSW90_MASK)

#define STCU_LBSSW_LBSSW91_MASK                  (0x8000000U)
#define STCU_LBSSW_LBSSW91_SHIFT                 (27U)
#define STCU_LBSSW_LBSSW91_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW91(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW91_SHIFT)) & STCU_LBSSW_LBSSW91_MASK)

#define STCU_LBSSW_LBSSW92_MASK                  (0x10000000U)
#define STCU_LBSSW_LBSSW92_SHIFT                 (28U)
#define STCU_LBSSW_LBSSW92_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW92(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW92_SHIFT)) & STCU_LBSSW_LBSSW92_MASK)

#define STCU_LBSSW_LBSSW93_MASK                  (0x20000000U)
#define STCU_LBSSW_LBSSW93_SHIFT                 (29U)
#define STCU_LBSSW_LBSSW93_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW93(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW93_SHIFT)) & STCU_LBSSW_LBSSW93_MASK)

#define STCU_LBSSW_LBSSW94_MASK                  (0x40000000U)
#define STCU_LBSSW_LBSSW94_SHIFT                 (30U)
#define STCU_LBSSW_LBSSW94_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW94(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW94_SHIFT)) & STCU_LBSSW_LBSSW94_MASK)

#define STCU_LBSSW_LBSSW95_MASK                  (0x80000000U)
#define STCU_LBSSW_LBSSW95_SHIFT                 (31U)
#define STCU_LBSSW_LBSSW95_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW95(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW95_SHIFT)) & STCU_LBSSW_LBSSW95_MASK)

#define STCU_LBSSW_LBSSW96_MASK                  (0x1U)
#define STCU_LBSSW_LBSSW96_SHIFT                 (0U)
#define STCU_LBSSW_LBSSW96_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW96(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW96_SHIFT)) & STCU_LBSSW_LBSSW96_MASK)

#define STCU_LBSSW_LBSSW97_MASK                  (0x2U)
#define STCU_LBSSW_LBSSW97_SHIFT                 (1U)
#define STCU_LBSSW_LBSSW97_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW97(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW97_SHIFT)) & STCU_LBSSW_LBSSW97_MASK)

#define STCU_LBSSW_LBSSW98_MASK                  (0x4U)
#define STCU_LBSSW_LBSSW98_SHIFT                 (2U)
#define STCU_LBSSW_LBSSW98_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW98(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW98_SHIFT)) & STCU_LBSSW_LBSSW98_MASK)

#define STCU_LBSSW_LBSSW99_MASK                  (0x8U)
#define STCU_LBSSW_LBSSW99_SHIFT                 (3U)
#define STCU_LBSSW_LBSSW99_WIDTH                 (1U)
#define STCU_LBSSW_LBSSW99(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW99_SHIFT)) & STCU_LBSSW_LBSSW99_MASK)

#define STCU_LBSSW_LBSSW100_MASK                 (0x10U)
#define STCU_LBSSW_LBSSW100_SHIFT                (4U)
#define STCU_LBSSW_LBSSW100_WIDTH                (1U)
#define STCU_LBSSW_LBSSW100(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW100_SHIFT)) & STCU_LBSSW_LBSSW100_MASK)

#define STCU_LBSSW_LBSSW101_MASK                 (0x20U)
#define STCU_LBSSW_LBSSW101_SHIFT                (5U)
#define STCU_LBSSW_LBSSW101_WIDTH                (1U)
#define STCU_LBSSW_LBSSW101(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW101_SHIFT)) & STCU_LBSSW_LBSSW101_MASK)

#define STCU_LBSSW_LBSSW102_MASK                 (0x40U)
#define STCU_LBSSW_LBSSW102_SHIFT                (6U)
#define STCU_LBSSW_LBSSW102_WIDTH                (1U)
#define STCU_LBSSW_LBSSW102(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW102_SHIFT)) & STCU_LBSSW_LBSSW102_MASK)

#define STCU_LBSSW_LBSSW103_MASK                 (0x80U)
#define STCU_LBSSW_LBSSW103_SHIFT                (7U)
#define STCU_LBSSW_LBSSW103_WIDTH                (1U)
#define STCU_LBSSW_LBSSW103(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW103_SHIFT)) & STCU_LBSSW_LBSSW103_MASK)

#define STCU_LBSSW_LBSSW104_MASK                 (0x100U)
#define STCU_LBSSW_LBSSW104_SHIFT                (8U)
#define STCU_LBSSW_LBSSW104_WIDTH                (1U)
#define STCU_LBSSW_LBSSW104(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW104_SHIFT)) & STCU_LBSSW_LBSSW104_MASK)

#define STCU_LBSSW_LBSSW105_MASK                 (0x200U)
#define STCU_LBSSW_LBSSW105_SHIFT                (9U)
#define STCU_LBSSW_LBSSW105_WIDTH                (1U)
#define STCU_LBSSW_LBSSW105(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW105_SHIFT)) & STCU_LBSSW_LBSSW105_MASK)

#define STCU_LBSSW_LBSSW106_MASK                 (0x400U)
#define STCU_LBSSW_LBSSW106_SHIFT                (10U)
#define STCU_LBSSW_LBSSW106_WIDTH                (1U)
#define STCU_LBSSW_LBSSW106(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW106_SHIFT)) & STCU_LBSSW_LBSSW106_MASK)

#define STCU_LBSSW_LBSSW107_MASK                 (0x800U)
#define STCU_LBSSW_LBSSW107_SHIFT                (11U)
#define STCU_LBSSW_LBSSW107_WIDTH                (1U)
#define STCU_LBSSW_LBSSW107(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW107_SHIFT)) & STCU_LBSSW_LBSSW107_MASK)

#define STCU_LBSSW_LBSSW108_MASK                 (0x1000U)
#define STCU_LBSSW_LBSSW108_SHIFT                (12U)
#define STCU_LBSSW_LBSSW108_WIDTH                (1U)
#define STCU_LBSSW_LBSSW108(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW108_SHIFT)) & STCU_LBSSW_LBSSW108_MASK)

#define STCU_LBSSW_LBSSW109_MASK                 (0x2000U)
#define STCU_LBSSW_LBSSW109_SHIFT                (13U)
#define STCU_LBSSW_LBSSW109_WIDTH                (1U)
#define STCU_LBSSW_LBSSW109(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW109_SHIFT)) & STCU_LBSSW_LBSSW109_MASK)

#define STCU_LBSSW_LBSSW110_MASK                 (0x4000U)
#define STCU_LBSSW_LBSSW110_SHIFT                (14U)
#define STCU_LBSSW_LBSSW110_WIDTH                (1U)
#define STCU_LBSSW_LBSSW110(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW110_SHIFT)) & STCU_LBSSW_LBSSW110_MASK)

#define STCU_LBSSW_LBSSW111_MASK                 (0x8000U)
#define STCU_LBSSW_LBSSW111_SHIFT                (15U)
#define STCU_LBSSW_LBSSW111_WIDTH                (1U)
#define STCU_LBSSW_LBSSW111(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW111_SHIFT)) & STCU_LBSSW_LBSSW111_MASK)

#define STCU_LBSSW_LBSSW112_MASK                 (0x10000U)
#define STCU_LBSSW_LBSSW112_SHIFT                (16U)
#define STCU_LBSSW_LBSSW112_WIDTH                (1U)
#define STCU_LBSSW_LBSSW112(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW112_SHIFT)) & STCU_LBSSW_LBSSW112_MASK)

#define STCU_LBSSW_LBSSW113_MASK                 (0x20000U)
#define STCU_LBSSW_LBSSW113_SHIFT                (17U)
#define STCU_LBSSW_LBSSW113_WIDTH                (1U)
#define STCU_LBSSW_LBSSW113(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW113_SHIFT)) & STCU_LBSSW_LBSSW113_MASK)

#define STCU_LBSSW_LBSSW114_MASK                 (0x40000U)
#define STCU_LBSSW_LBSSW114_SHIFT                (18U)
#define STCU_LBSSW_LBSSW114_WIDTH                (1U)
#define STCU_LBSSW_LBSSW114(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW114_SHIFT)) & STCU_LBSSW_LBSSW114_MASK)

#define STCU_LBSSW_LBSSW115_MASK                 (0x80000U)
#define STCU_LBSSW_LBSSW115_SHIFT                (19U)
#define STCU_LBSSW_LBSSW115_WIDTH                (1U)
#define STCU_LBSSW_LBSSW115(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW115_SHIFT)) & STCU_LBSSW_LBSSW115_MASK)

#define STCU_LBSSW_LBSSW116_MASK                 (0x100000U)
#define STCU_LBSSW_LBSSW116_SHIFT                (20U)
#define STCU_LBSSW_LBSSW116_WIDTH                (1U)
#define STCU_LBSSW_LBSSW116(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW116_SHIFT)) & STCU_LBSSW_LBSSW116_MASK)

#define STCU_LBSSW_LBSSW117_MASK                 (0x200000U)
#define STCU_LBSSW_LBSSW117_SHIFT                (21U)
#define STCU_LBSSW_LBSSW117_WIDTH                (1U)
#define STCU_LBSSW_LBSSW117(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW117_SHIFT)) & STCU_LBSSW_LBSSW117_MASK)

#define STCU_LBSSW_LBSSW118_MASK                 (0x400000U)
#define STCU_LBSSW_LBSSW118_SHIFT                (22U)
#define STCU_LBSSW_LBSSW118_WIDTH                (1U)
#define STCU_LBSSW_LBSSW118(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW118_SHIFT)) & STCU_LBSSW_LBSSW118_MASK)

#define STCU_LBSSW_LBSSW119_MASK                 (0x800000U)
#define STCU_LBSSW_LBSSW119_SHIFT                (23U)
#define STCU_LBSSW_LBSSW119_WIDTH                (1U)
#define STCU_LBSSW_LBSSW119(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW119_SHIFT)) & STCU_LBSSW_LBSSW119_MASK)

#define STCU_LBSSW_LBSSW120_MASK                 (0x1000000U)
#define STCU_LBSSW_LBSSW120_SHIFT                (24U)
#define STCU_LBSSW_LBSSW120_WIDTH                (1U)
#define STCU_LBSSW_LBSSW120(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW120_SHIFT)) & STCU_LBSSW_LBSSW120_MASK)

#define STCU_LBSSW_LBSSW121_MASK                 (0x2000000U)
#define STCU_LBSSW_LBSSW121_SHIFT                (25U)
#define STCU_LBSSW_LBSSW121_WIDTH                (1U)
#define STCU_LBSSW_LBSSW121(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW121_SHIFT)) & STCU_LBSSW_LBSSW121_MASK)

#define STCU_LBSSW_LBSSW122_MASK                 (0x4000000U)
#define STCU_LBSSW_LBSSW122_SHIFT                (26U)
#define STCU_LBSSW_LBSSW122_WIDTH                (1U)
#define STCU_LBSSW_LBSSW122(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW122_SHIFT)) & STCU_LBSSW_LBSSW122_MASK)

#define STCU_LBSSW_LBSSW123_MASK                 (0x8000000U)
#define STCU_LBSSW_LBSSW123_SHIFT                (27U)
#define STCU_LBSSW_LBSSW123_WIDTH                (1U)
#define STCU_LBSSW_LBSSW123(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW123_SHIFT)) & STCU_LBSSW_LBSSW123_MASK)

#define STCU_LBSSW_LBSSW124_MASK                 (0x10000000U)
#define STCU_LBSSW_LBSSW124_SHIFT                (28U)
#define STCU_LBSSW_LBSSW124_WIDTH                (1U)
#define STCU_LBSSW_LBSSW124(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW124_SHIFT)) & STCU_LBSSW_LBSSW124_MASK)

#define STCU_LBSSW_LBSSW125_MASK                 (0x20000000U)
#define STCU_LBSSW_LBSSW125_SHIFT                (29U)
#define STCU_LBSSW_LBSSW125_WIDTH                (1U)
#define STCU_LBSSW_LBSSW125(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW125_SHIFT)) & STCU_LBSSW_LBSSW125_MASK)

#define STCU_LBSSW_LBSSW126_MASK                 (0x40000000U)
#define STCU_LBSSW_LBSSW126_SHIFT                (30U)
#define STCU_LBSSW_LBSSW126_WIDTH                (1U)
#define STCU_LBSSW_LBSSW126(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW126_SHIFT)) & STCU_LBSSW_LBSSW126_MASK)

#define STCU_LBSSW_LBSSW127_MASK                 (0x80000000U)
#define STCU_LBSSW_LBSSW127_SHIFT                (31U)
#define STCU_LBSSW_LBSSW127_WIDTH                (1U)
#define STCU_LBSSW_LBSSW127(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW_LBSSW127_SHIFT)) & STCU_LBSSW_LBSSW127_MASK)
/*! @} */

/*! @name LBESW - STCU2 Online LBIST End Flag */
/*! @{ */

#define STCU_LBESW_LBESW0_MASK                   (0x1U)
#define STCU_LBESW_LBESW0_SHIFT                  (0U)
#define STCU_LBESW_LBESW0_WIDTH                  (1U)
#define STCU_LBESW_LBESW0(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW0_SHIFT)) & STCU_LBESW_LBESW0_MASK)

#define STCU_LBESW_LBESW1_MASK                   (0x2U)
#define STCU_LBESW_LBESW1_SHIFT                  (1U)
#define STCU_LBESW_LBESW1_WIDTH                  (1U)
#define STCU_LBESW_LBESW1(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW1_SHIFT)) & STCU_LBESW_LBESW1_MASK)

#define STCU_LBESW_LBESW2_MASK                   (0x4U)
#define STCU_LBESW_LBESW2_SHIFT                  (2U)
#define STCU_LBESW_LBESW2_WIDTH                  (1U)
#define STCU_LBESW_LBESW2(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW2_SHIFT)) & STCU_LBESW_LBESW2_MASK)

#define STCU_LBESW_LBESW3_MASK                   (0x8U)
#define STCU_LBESW_LBESW3_SHIFT                  (3U)
#define STCU_LBESW_LBESW3_WIDTH                  (1U)
#define STCU_LBESW_LBESW3(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW3_SHIFT)) & STCU_LBESW_LBESW3_MASK)

#define STCU_LBESW_LBESW4_MASK                   (0x10U)
#define STCU_LBESW_LBESW4_SHIFT                  (4U)
#define STCU_LBESW_LBESW4_WIDTH                  (1U)
#define STCU_LBESW_LBESW4(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW4_SHIFT)) & STCU_LBESW_LBESW4_MASK)

#define STCU_LBESW_LBESW5_MASK                   (0x20U)
#define STCU_LBESW_LBESW5_SHIFT                  (5U)
#define STCU_LBESW_LBESW5_WIDTH                  (1U)
#define STCU_LBESW_LBESW5(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW5_SHIFT)) & STCU_LBESW_LBESW5_MASK)

#define STCU_LBESW_LBESW6_MASK                   (0x40U)
#define STCU_LBESW_LBESW6_SHIFT                  (6U)
#define STCU_LBESW_LBESW6_WIDTH                  (1U)
#define STCU_LBESW_LBESW6(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW6_SHIFT)) & STCU_LBESW_LBESW6_MASK)

#define STCU_LBESW_LBESW7_MASK                   (0x80U)
#define STCU_LBESW_LBESW7_SHIFT                  (7U)
#define STCU_LBESW_LBESW7_WIDTH                  (1U)
#define STCU_LBESW_LBESW7(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW7_SHIFT)) & STCU_LBESW_LBESW7_MASK)

#define STCU_LBESW_LBESW8_MASK                   (0x100U)
#define STCU_LBESW_LBESW8_SHIFT                  (8U)
#define STCU_LBESW_LBESW8_WIDTH                  (1U)
#define STCU_LBESW_LBESW8(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW8_SHIFT)) & STCU_LBESW_LBESW8_MASK)

#define STCU_LBESW_LBESW9_MASK                   (0x200U)
#define STCU_LBESW_LBESW9_SHIFT                  (9U)
#define STCU_LBESW_LBESW9_WIDTH                  (1U)
#define STCU_LBESW_LBESW9(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW9_SHIFT)) & STCU_LBESW_LBESW9_MASK)

#define STCU_LBESW_LBESW10_MASK                  (0x400U)
#define STCU_LBESW_LBESW10_SHIFT                 (10U)
#define STCU_LBESW_LBESW10_WIDTH                 (1U)
#define STCU_LBESW_LBESW10(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW10_SHIFT)) & STCU_LBESW_LBESW10_MASK)

#define STCU_LBESW_LBESW11_MASK                  (0x800U)
#define STCU_LBESW_LBESW11_SHIFT                 (11U)
#define STCU_LBESW_LBESW11_WIDTH                 (1U)
#define STCU_LBESW_LBESW11(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW11_SHIFT)) & STCU_LBESW_LBESW11_MASK)

#define STCU_LBESW_LBESW12_MASK                  (0x1000U)
#define STCU_LBESW_LBESW12_SHIFT                 (12U)
#define STCU_LBESW_LBESW12_WIDTH                 (1U)
#define STCU_LBESW_LBESW12(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW12_SHIFT)) & STCU_LBESW_LBESW12_MASK)

#define STCU_LBESW_LBESW13_MASK                  (0x2000U)
#define STCU_LBESW_LBESW13_SHIFT                 (13U)
#define STCU_LBESW_LBESW13_WIDTH                 (1U)
#define STCU_LBESW_LBESW13(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW13_SHIFT)) & STCU_LBESW_LBESW13_MASK)

#define STCU_LBESW_LBESW14_MASK                  (0x4000U)
#define STCU_LBESW_LBESW14_SHIFT                 (14U)
#define STCU_LBESW_LBESW14_WIDTH                 (1U)
#define STCU_LBESW_LBESW14(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW14_SHIFT)) & STCU_LBESW_LBESW14_MASK)

#define STCU_LBESW_LBESW15_MASK                  (0x8000U)
#define STCU_LBESW_LBESW15_SHIFT                 (15U)
#define STCU_LBESW_LBESW15_WIDTH                 (1U)
#define STCU_LBESW_LBESW15(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW15_SHIFT)) & STCU_LBESW_LBESW15_MASK)

#define STCU_LBESW_LBESW16_MASK                  (0x10000U)
#define STCU_LBESW_LBESW16_SHIFT                 (16U)
#define STCU_LBESW_LBESW16_WIDTH                 (1U)
#define STCU_LBESW_LBESW16(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW16_SHIFT)) & STCU_LBESW_LBESW16_MASK)

#define STCU_LBESW_LBESW17_MASK                  (0x20000U)
#define STCU_LBESW_LBESW17_SHIFT                 (17U)
#define STCU_LBESW_LBESW17_WIDTH                 (1U)
#define STCU_LBESW_LBESW17(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW17_SHIFT)) & STCU_LBESW_LBESW17_MASK)

#define STCU_LBESW_LBESW18_MASK                  (0x40000U)
#define STCU_LBESW_LBESW18_SHIFT                 (18U)
#define STCU_LBESW_LBESW18_WIDTH                 (1U)
#define STCU_LBESW_LBESW18(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW18_SHIFT)) & STCU_LBESW_LBESW18_MASK)

#define STCU_LBESW_LBESW19_MASK                  (0x80000U)
#define STCU_LBESW_LBESW19_SHIFT                 (19U)
#define STCU_LBESW_LBESW19_WIDTH                 (1U)
#define STCU_LBESW_LBESW19(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW19_SHIFT)) & STCU_LBESW_LBESW19_MASK)

#define STCU_LBESW_LBESW20_MASK                  (0x100000U)
#define STCU_LBESW_LBESW20_SHIFT                 (20U)
#define STCU_LBESW_LBESW20_WIDTH                 (1U)
#define STCU_LBESW_LBESW20(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW20_SHIFT)) & STCU_LBESW_LBESW20_MASK)

#define STCU_LBESW_LBESW21_MASK                  (0x200000U)
#define STCU_LBESW_LBESW21_SHIFT                 (21U)
#define STCU_LBESW_LBESW21_WIDTH                 (1U)
#define STCU_LBESW_LBESW21(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW21_SHIFT)) & STCU_LBESW_LBESW21_MASK)

#define STCU_LBESW_LBESW22_MASK                  (0x400000U)
#define STCU_LBESW_LBESW22_SHIFT                 (22U)
#define STCU_LBESW_LBESW22_WIDTH                 (1U)
#define STCU_LBESW_LBESW22(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW22_SHIFT)) & STCU_LBESW_LBESW22_MASK)

#define STCU_LBESW_LBESW23_MASK                  (0x800000U)
#define STCU_LBESW_LBESW23_SHIFT                 (23U)
#define STCU_LBESW_LBESW23_WIDTH                 (1U)
#define STCU_LBESW_LBESW23(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW23_SHIFT)) & STCU_LBESW_LBESW23_MASK)

#define STCU_LBESW_LBESW24_MASK                  (0x1000000U)
#define STCU_LBESW_LBESW24_SHIFT                 (24U)
#define STCU_LBESW_LBESW24_WIDTH                 (1U)
#define STCU_LBESW_LBESW24(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW24_SHIFT)) & STCU_LBESW_LBESW24_MASK)

#define STCU_LBESW_LBESW25_MASK                  (0x2000000U)
#define STCU_LBESW_LBESW25_SHIFT                 (25U)
#define STCU_LBESW_LBESW25_WIDTH                 (1U)
#define STCU_LBESW_LBESW25(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW25_SHIFT)) & STCU_LBESW_LBESW25_MASK)

#define STCU_LBESW_LBESW26_MASK                  (0x4000000U)
#define STCU_LBESW_LBESW26_SHIFT                 (26U)
#define STCU_LBESW_LBESW26_WIDTH                 (1U)
#define STCU_LBESW_LBESW26(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW26_SHIFT)) & STCU_LBESW_LBESW26_MASK)

#define STCU_LBESW_LBESW27_MASK                  (0x8000000U)
#define STCU_LBESW_LBESW27_SHIFT                 (27U)
#define STCU_LBESW_LBESW27_WIDTH                 (1U)
#define STCU_LBESW_LBESW27(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW27_SHIFT)) & STCU_LBESW_LBESW27_MASK)

#define STCU_LBESW_LBESW28_MASK                  (0x10000000U)
#define STCU_LBESW_LBESW28_SHIFT                 (28U)
#define STCU_LBESW_LBESW28_WIDTH                 (1U)
#define STCU_LBESW_LBESW28(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW28_SHIFT)) & STCU_LBESW_LBESW28_MASK)

#define STCU_LBESW_LBESW29_MASK                  (0x20000000U)
#define STCU_LBESW_LBESW29_SHIFT                 (29U)
#define STCU_LBESW_LBESW29_WIDTH                 (1U)
#define STCU_LBESW_LBESW29(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW29_SHIFT)) & STCU_LBESW_LBESW29_MASK)

#define STCU_LBESW_LBESW30_MASK                  (0x40000000U)
#define STCU_LBESW_LBESW30_SHIFT                 (30U)
#define STCU_LBESW_LBESW30_WIDTH                 (1U)
#define STCU_LBESW_LBESW30(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW30_SHIFT)) & STCU_LBESW_LBESW30_MASK)

#define STCU_LBESW_LBESW31_MASK                  (0x80000000U)
#define STCU_LBESW_LBESW31_SHIFT                 (31U)
#define STCU_LBESW_LBESW31_WIDTH                 (1U)
#define STCU_LBESW_LBESW31(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW31_SHIFT)) & STCU_LBESW_LBESW31_MASK)

#define STCU_LBESW_LBESW32_MASK                  (0x1U)
#define STCU_LBESW_LBESW32_SHIFT                 (0U)
#define STCU_LBESW_LBESW32_WIDTH                 (1U)
#define STCU_LBESW_LBESW32(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW32_SHIFT)) & STCU_LBESW_LBESW32_MASK)

#define STCU_LBESW_LBESW33_MASK                  (0x2U)
#define STCU_LBESW_LBESW33_SHIFT                 (1U)
#define STCU_LBESW_LBESW33_WIDTH                 (1U)
#define STCU_LBESW_LBESW33(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW33_SHIFT)) & STCU_LBESW_LBESW33_MASK)

#define STCU_LBESW_LBESW34_MASK                  (0x4U)
#define STCU_LBESW_LBESW34_SHIFT                 (2U)
#define STCU_LBESW_LBESW34_WIDTH                 (1U)
#define STCU_LBESW_LBESW34(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW34_SHIFT)) & STCU_LBESW_LBESW34_MASK)

#define STCU_LBESW_LBESW35_MASK                  (0x8U)
#define STCU_LBESW_LBESW35_SHIFT                 (3U)
#define STCU_LBESW_LBESW35_WIDTH                 (1U)
#define STCU_LBESW_LBESW35(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW35_SHIFT)) & STCU_LBESW_LBESW35_MASK)

#define STCU_LBESW_LBESW36_MASK                  (0x10U)
#define STCU_LBESW_LBESW36_SHIFT                 (4U)
#define STCU_LBESW_LBESW36_WIDTH                 (1U)
#define STCU_LBESW_LBESW36(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW36_SHIFT)) & STCU_LBESW_LBESW36_MASK)

#define STCU_LBESW_LBESW37_MASK                  (0x20U)
#define STCU_LBESW_LBESW37_SHIFT                 (5U)
#define STCU_LBESW_LBESW37_WIDTH                 (1U)
#define STCU_LBESW_LBESW37(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW37_SHIFT)) & STCU_LBESW_LBESW37_MASK)

#define STCU_LBESW_LBESW38_MASK                  (0x40U)
#define STCU_LBESW_LBESW38_SHIFT                 (6U)
#define STCU_LBESW_LBESW38_WIDTH                 (1U)
#define STCU_LBESW_LBESW38(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW38_SHIFT)) & STCU_LBESW_LBESW38_MASK)

#define STCU_LBESW_LBESW39_MASK                  (0x80U)
#define STCU_LBESW_LBESW39_SHIFT                 (7U)
#define STCU_LBESW_LBESW39_WIDTH                 (1U)
#define STCU_LBESW_LBESW39(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW39_SHIFT)) & STCU_LBESW_LBESW39_MASK)

#define STCU_LBESW_LBESW40_MASK                  (0x100U)
#define STCU_LBESW_LBESW40_SHIFT                 (8U)
#define STCU_LBESW_LBESW40_WIDTH                 (1U)
#define STCU_LBESW_LBESW40(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW40_SHIFT)) & STCU_LBESW_LBESW40_MASK)

#define STCU_LBESW_LBESW41_MASK                  (0x200U)
#define STCU_LBESW_LBESW41_SHIFT                 (9U)
#define STCU_LBESW_LBESW41_WIDTH                 (1U)
#define STCU_LBESW_LBESW41(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW41_SHIFT)) & STCU_LBESW_LBESW41_MASK)

#define STCU_LBESW_LBESW42_MASK                  (0x400U)
#define STCU_LBESW_LBESW42_SHIFT                 (10U)
#define STCU_LBESW_LBESW42_WIDTH                 (1U)
#define STCU_LBESW_LBESW42(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW42_SHIFT)) & STCU_LBESW_LBESW42_MASK)

#define STCU_LBESW_LBESW43_MASK                  (0x800U)
#define STCU_LBESW_LBESW43_SHIFT                 (11U)
#define STCU_LBESW_LBESW43_WIDTH                 (1U)
#define STCU_LBESW_LBESW43(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW43_SHIFT)) & STCU_LBESW_LBESW43_MASK)

#define STCU_LBESW_LBESW44_MASK                  (0x1000U)
#define STCU_LBESW_LBESW44_SHIFT                 (12U)
#define STCU_LBESW_LBESW44_WIDTH                 (1U)
#define STCU_LBESW_LBESW44(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW44_SHIFT)) & STCU_LBESW_LBESW44_MASK)

#define STCU_LBESW_LBESW45_MASK                  (0x2000U)
#define STCU_LBESW_LBESW45_SHIFT                 (13U)
#define STCU_LBESW_LBESW45_WIDTH                 (1U)
#define STCU_LBESW_LBESW45(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW45_SHIFT)) & STCU_LBESW_LBESW45_MASK)

#define STCU_LBESW_LBESW46_MASK                  (0x4000U)
#define STCU_LBESW_LBESW46_SHIFT                 (14U)
#define STCU_LBESW_LBESW46_WIDTH                 (1U)
#define STCU_LBESW_LBESW46(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW46_SHIFT)) & STCU_LBESW_LBESW46_MASK)

#define STCU_LBESW_LBESW47_MASK                  (0x8000U)
#define STCU_LBESW_LBESW47_SHIFT                 (15U)
#define STCU_LBESW_LBESW47_WIDTH                 (1U)
#define STCU_LBESW_LBESW47(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW47_SHIFT)) & STCU_LBESW_LBESW47_MASK)

#define STCU_LBESW_LBESW48_MASK                  (0x10000U)
#define STCU_LBESW_LBESW48_SHIFT                 (16U)
#define STCU_LBESW_LBESW48_WIDTH                 (1U)
#define STCU_LBESW_LBESW48(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW48_SHIFT)) & STCU_LBESW_LBESW48_MASK)

#define STCU_LBESW_LBESW49_MASK                  (0x20000U)
#define STCU_LBESW_LBESW49_SHIFT                 (17U)
#define STCU_LBESW_LBESW49_WIDTH                 (1U)
#define STCU_LBESW_LBESW49(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW49_SHIFT)) & STCU_LBESW_LBESW49_MASK)

#define STCU_LBESW_LBESW50_MASK                  (0x40000U)
#define STCU_LBESW_LBESW50_SHIFT                 (18U)
#define STCU_LBESW_LBESW50_WIDTH                 (1U)
#define STCU_LBESW_LBESW50(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW50_SHIFT)) & STCU_LBESW_LBESW50_MASK)

#define STCU_LBESW_LBESW51_MASK                  (0x80000U)
#define STCU_LBESW_LBESW51_SHIFT                 (19U)
#define STCU_LBESW_LBESW51_WIDTH                 (1U)
#define STCU_LBESW_LBESW51(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW51_SHIFT)) & STCU_LBESW_LBESW51_MASK)

#define STCU_LBESW_LBESW52_MASK                  (0x100000U)
#define STCU_LBESW_LBESW52_SHIFT                 (20U)
#define STCU_LBESW_LBESW52_WIDTH                 (1U)
#define STCU_LBESW_LBESW52(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW52_SHIFT)) & STCU_LBESW_LBESW52_MASK)

#define STCU_LBESW_LBESW53_MASK                  (0x200000U)
#define STCU_LBESW_LBESW53_SHIFT                 (21U)
#define STCU_LBESW_LBESW53_WIDTH                 (1U)
#define STCU_LBESW_LBESW53(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW53_SHIFT)) & STCU_LBESW_LBESW53_MASK)

#define STCU_LBESW_LBESW54_MASK                  (0x400000U)
#define STCU_LBESW_LBESW54_SHIFT                 (22U)
#define STCU_LBESW_LBESW54_WIDTH                 (1U)
#define STCU_LBESW_LBESW54(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW54_SHIFT)) & STCU_LBESW_LBESW54_MASK)

#define STCU_LBESW_LBESW55_MASK                  (0x800000U)
#define STCU_LBESW_LBESW55_SHIFT                 (23U)
#define STCU_LBESW_LBESW55_WIDTH                 (1U)
#define STCU_LBESW_LBESW55(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW55_SHIFT)) & STCU_LBESW_LBESW55_MASK)

#define STCU_LBESW_LBESW56_MASK                  (0x1000000U)
#define STCU_LBESW_LBESW56_SHIFT                 (24U)
#define STCU_LBESW_LBESW56_WIDTH                 (1U)
#define STCU_LBESW_LBESW56(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW56_SHIFT)) & STCU_LBESW_LBESW56_MASK)

#define STCU_LBESW_LBESW57_MASK                  (0x2000000U)
#define STCU_LBESW_LBESW57_SHIFT                 (25U)
#define STCU_LBESW_LBESW57_WIDTH                 (1U)
#define STCU_LBESW_LBESW57(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW57_SHIFT)) & STCU_LBESW_LBESW57_MASK)

#define STCU_LBESW_LBESW58_MASK                  (0x4000000U)
#define STCU_LBESW_LBESW58_SHIFT                 (26U)
#define STCU_LBESW_LBESW58_WIDTH                 (1U)
#define STCU_LBESW_LBESW58(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW58_SHIFT)) & STCU_LBESW_LBESW58_MASK)

#define STCU_LBESW_LBESW59_MASK                  (0x8000000U)
#define STCU_LBESW_LBESW59_SHIFT                 (27U)
#define STCU_LBESW_LBESW59_WIDTH                 (1U)
#define STCU_LBESW_LBESW59(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW59_SHIFT)) & STCU_LBESW_LBESW59_MASK)

#define STCU_LBESW_LBESW60_MASK                  (0x10000000U)
#define STCU_LBESW_LBESW60_SHIFT                 (28U)
#define STCU_LBESW_LBESW60_WIDTH                 (1U)
#define STCU_LBESW_LBESW60(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW60_SHIFT)) & STCU_LBESW_LBESW60_MASK)

#define STCU_LBESW_LBESW61_MASK                  (0x20000000U)
#define STCU_LBESW_LBESW61_SHIFT                 (29U)
#define STCU_LBESW_LBESW61_WIDTH                 (1U)
#define STCU_LBESW_LBESW61(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW61_SHIFT)) & STCU_LBESW_LBESW61_MASK)

#define STCU_LBESW_LBESW62_MASK                  (0x40000000U)
#define STCU_LBESW_LBESW62_SHIFT                 (30U)
#define STCU_LBESW_LBESW62_WIDTH                 (1U)
#define STCU_LBESW_LBESW62(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW62_SHIFT)) & STCU_LBESW_LBESW62_MASK)

#define STCU_LBESW_LBESW63_MASK                  (0x80000000U)
#define STCU_LBESW_LBESW63_SHIFT                 (31U)
#define STCU_LBESW_LBESW63_WIDTH                 (1U)
#define STCU_LBESW_LBESW63(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW63_SHIFT)) & STCU_LBESW_LBESW63_MASK)

#define STCU_LBESW_LBESW64_MASK                  (0x1U)
#define STCU_LBESW_LBESW64_SHIFT                 (0U)
#define STCU_LBESW_LBESW64_WIDTH                 (1U)
#define STCU_LBESW_LBESW64(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW64_SHIFT)) & STCU_LBESW_LBESW64_MASK)

#define STCU_LBESW_LBESW65_MASK                  (0x2U)
#define STCU_LBESW_LBESW65_SHIFT                 (1U)
#define STCU_LBESW_LBESW65_WIDTH                 (1U)
#define STCU_LBESW_LBESW65(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW65_SHIFT)) & STCU_LBESW_LBESW65_MASK)

#define STCU_LBESW_LBESW66_MASK                  (0x4U)
#define STCU_LBESW_LBESW66_SHIFT                 (2U)
#define STCU_LBESW_LBESW66_WIDTH                 (1U)
#define STCU_LBESW_LBESW66(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW66_SHIFT)) & STCU_LBESW_LBESW66_MASK)

#define STCU_LBESW_LBESW67_MASK                  (0x8U)
#define STCU_LBESW_LBESW67_SHIFT                 (3U)
#define STCU_LBESW_LBESW67_WIDTH                 (1U)
#define STCU_LBESW_LBESW67(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW67_SHIFT)) & STCU_LBESW_LBESW67_MASK)

#define STCU_LBESW_LBESW68_MASK                  (0x10U)
#define STCU_LBESW_LBESW68_SHIFT                 (4U)
#define STCU_LBESW_LBESW68_WIDTH                 (1U)
#define STCU_LBESW_LBESW68(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW68_SHIFT)) & STCU_LBESW_LBESW68_MASK)

#define STCU_LBESW_LBESW69_MASK                  (0x20U)
#define STCU_LBESW_LBESW69_SHIFT                 (5U)
#define STCU_LBESW_LBESW69_WIDTH                 (1U)
#define STCU_LBESW_LBESW69(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW69_SHIFT)) & STCU_LBESW_LBESW69_MASK)

#define STCU_LBESW_LBESW70_MASK                  (0x40U)
#define STCU_LBESW_LBESW70_SHIFT                 (6U)
#define STCU_LBESW_LBESW70_WIDTH                 (1U)
#define STCU_LBESW_LBESW70(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW70_SHIFT)) & STCU_LBESW_LBESW70_MASK)

#define STCU_LBESW_LBESW71_MASK                  (0x80U)
#define STCU_LBESW_LBESW71_SHIFT                 (7U)
#define STCU_LBESW_LBESW71_WIDTH                 (1U)
#define STCU_LBESW_LBESW71(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW71_SHIFT)) & STCU_LBESW_LBESW71_MASK)

#define STCU_LBESW_LBESW72_MASK                  (0x100U)
#define STCU_LBESW_LBESW72_SHIFT                 (8U)
#define STCU_LBESW_LBESW72_WIDTH                 (1U)
#define STCU_LBESW_LBESW72(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW72_SHIFT)) & STCU_LBESW_LBESW72_MASK)

#define STCU_LBESW_LBESW73_MASK                  (0x200U)
#define STCU_LBESW_LBESW73_SHIFT                 (9U)
#define STCU_LBESW_LBESW73_WIDTH                 (1U)
#define STCU_LBESW_LBESW73(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW73_SHIFT)) & STCU_LBESW_LBESW73_MASK)

#define STCU_LBESW_LBESW74_MASK                  (0x400U)
#define STCU_LBESW_LBESW74_SHIFT                 (10U)
#define STCU_LBESW_LBESW74_WIDTH                 (1U)
#define STCU_LBESW_LBESW74(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW74_SHIFT)) & STCU_LBESW_LBESW74_MASK)

#define STCU_LBESW_LBESW75_MASK                  (0x800U)
#define STCU_LBESW_LBESW75_SHIFT                 (11U)
#define STCU_LBESW_LBESW75_WIDTH                 (1U)
#define STCU_LBESW_LBESW75(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW75_SHIFT)) & STCU_LBESW_LBESW75_MASK)

#define STCU_LBESW_LBESW76_MASK                  (0x1000U)
#define STCU_LBESW_LBESW76_SHIFT                 (12U)
#define STCU_LBESW_LBESW76_WIDTH                 (1U)
#define STCU_LBESW_LBESW76(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW76_SHIFT)) & STCU_LBESW_LBESW76_MASK)

#define STCU_LBESW_LBESW77_MASK                  (0x2000U)
#define STCU_LBESW_LBESW77_SHIFT                 (13U)
#define STCU_LBESW_LBESW77_WIDTH                 (1U)
#define STCU_LBESW_LBESW77(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW77_SHIFT)) & STCU_LBESW_LBESW77_MASK)

#define STCU_LBESW_LBESW78_MASK                  (0x4000U)
#define STCU_LBESW_LBESW78_SHIFT                 (14U)
#define STCU_LBESW_LBESW78_WIDTH                 (1U)
#define STCU_LBESW_LBESW78(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW78_SHIFT)) & STCU_LBESW_LBESW78_MASK)

#define STCU_LBESW_LBESW79_MASK                  (0x8000U)
#define STCU_LBESW_LBESW79_SHIFT                 (15U)
#define STCU_LBESW_LBESW79_WIDTH                 (1U)
#define STCU_LBESW_LBESW79(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW79_SHIFT)) & STCU_LBESW_LBESW79_MASK)

#define STCU_LBESW_LBESW80_MASK                  (0x10000U)
#define STCU_LBESW_LBESW80_SHIFT                 (16U)
#define STCU_LBESW_LBESW80_WIDTH                 (1U)
#define STCU_LBESW_LBESW80(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW80_SHIFT)) & STCU_LBESW_LBESW80_MASK)

#define STCU_LBESW_LBESW81_MASK                  (0x20000U)
#define STCU_LBESW_LBESW81_SHIFT                 (17U)
#define STCU_LBESW_LBESW81_WIDTH                 (1U)
#define STCU_LBESW_LBESW81(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW81_SHIFT)) & STCU_LBESW_LBESW81_MASK)

#define STCU_LBESW_LBESW82_MASK                  (0x40000U)
#define STCU_LBESW_LBESW82_SHIFT                 (18U)
#define STCU_LBESW_LBESW82_WIDTH                 (1U)
#define STCU_LBESW_LBESW82(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW82_SHIFT)) & STCU_LBESW_LBESW82_MASK)

#define STCU_LBESW_LBESW83_MASK                  (0x80000U)
#define STCU_LBESW_LBESW83_SHIFT                 (19U)
#define STCU_LBESW_LBESW83_WIDTH                 (1U)
#define STCU_LBESW_LBESW83(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW83_SHIFT)) & STCU_LBESW_LBESW83_MASK)

#define STCU_LBESW_LBESW84_MASK                  (0x100000U)
#define STCU_LBESW_LBESW84_SHIFT                 (20U)
#define STCU_LBESW_LBESW84_WIDTH                 (1U)
#define STCU_LBESW_LBESW84(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW84_SHIFT)) & STCU_LBESW_LBESW84_MASK)

#define STCU_LBESW_LBESW85_MASK                  (0x200000U)
#define STCU_LBESW_LBESW85_SHIFT                 (21U)
#define STCU_LBESW_LBESW85_WIDTH                 (1U)
#define STCU_LBESW_LBESW85(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW85_SHIFT)) & STCU_LBESW_LBESW85_MASK)

#define STCU_LBESW_LBESW86_MASK                  (0x400000U)
#define STCU_LBESW_LBESW86_SHIFT                 (22U)
#define STCU_LBESW_LBESW86_WIDTH                 (1U)
#define STCU_LBESW_LBESW86(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW86_SHIFT)) & STCU_LBESW_LBESW86_MASK)

#define STCU_LBESW_LBESW87_MASK                  (0x800000U)
#define STCU_LBESW_LBESW87_SHIFT                 (23U)
#define STCU_LBESW_LBESW87_WIDTH                 (1U)
#define STCU_LBESW_LBESW87(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW87_SHIFT)) & STCU_LBESW_LBESW87_MASK)

#define STCU_LBESW_LBESW88_MASK                  (0x1000000U)
#define STCU_LBESW_LBESW88_SHIFT                 (24U)
#define STCU_LBESW_LBESW88_WIDTH                 (1U)
#define STCU_LBESW_LBESW88(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW88_SHIFT)) & STCU_LBESW_LBESW88_MASK)

#define STCU_LBESW_LBESW89_MASK                  (0x2000000U)
#define STCU_LBESW_LBESW89_SHIFT                 (25U)
#define STCU_LBESW_LBESW89_WIDTH                 (1U)
#define STCU_LBESW_LBESW89(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW89_SHIFT)) & STCU_LBESW_LBESW89_MASK)

#define STCU_LBESW_LBESW90_MASK                  (0x4000000U)
#define STCU_LBESW_LBESW90_SHIFT                 (26U)
#define STCU_LBESW_LBESW90_WIDTH                 (1U)
#define STCU_LBESW_LBESW90(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW90_SHIFT)) & STCU_LBESW_LBESW90_MASK)

#define STCU_LBESW_LBESW91_MASK                  (0x8000000U)
#define STCU_LBESW_LBESW91_SHIFT                 (27U)
#define STCU_LBESW_LBESW91_WIDTH                 (1U)
#define STCU_LBESW_LBESW91(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW91_SHIFT)) & STCU_LBESW_LBESW91_MASK)

#define STCU_LBESW_LBESW92_MASK                  (0x10000000U)
#define STCU_LBESW_LBESW92_SHIFT                 (28U)
#define STCU_LBESW_LBESW92_WIDTH                 (1U)
#define STCU_LBESW_LBESW92(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW92_SHIFT)) & STCU_LBESW_LBESW92_MASK)

#define STCU_LBESW_LBESW93_MASK                  (0x20000000U)
#define STCU_LBESW_LBESW93_SHIFT                 (29U)
#define STCU_LBESW_LBESW93_WIDTH                 (1U)
#define STCU_LBESW_LBESW93(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW93_SHIFT)) & STCU_LBESW_LBESW93_MASK)

#define STCU_LBESW_LBESW94_MASK                  (0x40000000U)
#define STCU_LBESW_LBESW94_SHIFT                 (30U)
#define STCU_LBESW_LBESW94_WIDTH                 (1U)
#define STCU_LBESW_LBESW94(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW94_SHIFT)) & STCU_LBESW_LBESW94_MASK)

#define STCU_LBESW_LBESW95_MASK                  (0x80000000U)
#define STCU_LBESW_LBESW95_SHIFT                 (31U)
#define STCU_LBESW_LBESW95_WIDTH                 (1U)
#define STCU_LBESW_LBESW95(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW95_SHIFT)) & STCU_LBESW_LBESW95_MASK)

#define STCU_LBESW_LBESW96_MASK                  (0x1U)
#define STCU_LBESW_LBESW96_SHIFT                 (0U)
#define STCU_LBESW_LBESW96_WIDTH                 (1U)
#define STCU_LBESW_LBESW96(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW96_SHIFT)) & STCU_LBESW_LBESW96_MASK)

#define STCU_LBESW_LBESW97_MASK                  (0x2U)
#define STCU_LBESW_LBESW97_SHIFT                 (1U)
#define STCU_LBESW_LBESW97_WIDTH                 (1U)
#define STCU_LBESW_LBESW97(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW97_SHIFT)) & STCU_LBESW_LBESW97_MASK)

#define STCU_LBESW_LBESW98_MASK                  (0x4U)
#define STCU_LBESW_LBESW98_SHIFT                 (2U)
#define STCU_LBESW_LBESW98_WIDTH                 (1U)
#define STCU_LBESW_LBESW98(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW98_SHIFT)) & STCU_LBESW_LBESW98_MASK)

#define STCU_LBESW_LBESW99_MASK                  (0x8U)
#define STCU_LBESW_LBESW99_SHIFT                 (3U)
#define STCU_LBESW_LBESW99_WIDTH                 (1U)
#define STCU_LBESW_LBESW99(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW99_SHIFT)) & STCU_LBESW_LBESW99_MASK)

#define STCU_LBESW_LBESW100_MASK                 (0x10U)
#define STCU_LBESW_LBESW100_SHIFT                (4U)
#define STCU_LBESW_LBESW100_WIDTH                (1U)
#define STCU_LBESW_LBESW100(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW100_SHIFT)) & STCU_LBESW_LBESW100_MASK)

#define STCU_LBESW_LBESW101_MASK                 (0x20U)
#define STCU_LBESW_LBESW101_SHIFT                (5U)
#define STCU_LBESW_LBESW101_WIDTH                (1U)
#define STCU_LBESW_LBESW101(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW101_SHIFT)) & STCU_LBESW_LBESW101_MASK)

#define STCU_LBESW_LBESW102_MASK                 (0x40U)
#define STCU_LBESW_LBESW102_SHIFT                (6U)
#define STCU_LBESW_LBESW102_WIDTH                (1U)
#define STCU_LBESW_LBESW102(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW102_SHIFT)) & STCU_LBESW_LBESW102_MASK)

#define STCU_LBESW_LBESW103_MASK                 (0x80U)
#define STCU_LBESW_LBESW103_SHIFT                (7U)
#define STCU_LBESW_LBESW103_WIDTH                (1U)
#define STCU_LBESW_LBESW103(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW103_SHIFT)) & STCU_LBESW_LBESW103_MASK)

#define STCU_LBESW_LBESW104_MASK                 (0x100U)
#define STCU_LBESW_LBESW104_SHIFT                (8U)
#define STCU_LBESW_LBESW104_WIDTH                (1U)
#define STCU_LBESW_LBESW104(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW104_SHIFT)) & STCU_LBESW_LBESW104_MASK)

#define STCU_LBESW_LBESW105_MASK                 (0x200U)
#define STCU_LBESW_LBESW105_SHIFT                (9U)
#define STCU_LBESW_LBESW105_WIDTH                (1U)
#define STCU_LBESW_LBESW105(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW105_SHIFT)) & STCU_LBESW_LBESW105_MASK)

#define STCU_LBESW_LBESW106_MASK                 (0x400U)
#define STCU_LBESW_LBESW106_SHIFT                (10U)
#define STCU_LBESW_LBESW106_WIDTH                (1U)
#define STCU_LBESW_LBESW106(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW106_SHIFT)) & STCU_LBESW_LBESW106_MASK)

#define STCU_LBESW_LBESW107_MASK                 (0x800U)
#define STCU_LBESW_LBESW107_SHIFT                (11U)
#define STCU_LBESW_LBESW107_WIDTH                (1U)
#define STCU_LBESW_LBESW107(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW107_SHIFT)) & STCU_LBESW_LBESW107_MASK)

#define STCU_LBESW_LBESW108_MASK                 (0x1000U)
#define STCU_LBESW_LBESW108_SHIFT                (12U)
#define STCU_LBESW_LBESW108_WIDTH                (1U)
#define STCU_LBESW_LBESW108(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW108_SHIFT)) & STCU_LBESW_LBESW108_MASK)

#define STCU_LBESW_LBESW109_MASK                 (0x2000U)
#define STCU_LBESW_LBESW109_SHIFT                (13U)
#define STCU_LBESW_LBESW109_WIDTH                (1U)
#define STCU_LBESW_LBESW109(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW109_SHIFT)) & STCU_LBESW_LBESW109_MASK)

#define STCU_LBESW_LBESW110_MASK                 (0x4000U)
#define STCU_LBESW_LBESW110_SHIFT                (14U)
#define STCU_LBESW_LBESW110_WIDTH                (1U)
#define STCU_LBESW_LBESW110(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW110_SHIFT)) & STCU_LBESW_LBESW110_MASK)

#define STCU_LBESW_LBESW111_MASK                 (0x8000U)
#define STCU_LBESW_LBESW111_SHIFT                (15U)
#define STCU_LBESW_LBESW111_WIDTH                (1U)
#define STCU_LBESW_LBESW111(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW111_SHIFT)) & STCU_LBESW_LBESW111_MASK)

#define STCU_LBESW_LBESW112_MASK                 (0x10000U)
#define STCU_LBESW_LBESW112_SHIFT                (16U)
#define STCU_LBESW_LBESW112_WIDTH                (1U)
#define STCU_LBESW_LBESW112(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW112_SHIFT)) & STCU_LBESW_LBESW112_MASK)

#define STCU_LBESW_LBESW113_MASK                 (0x20000U)
#define STCU_LBESW_LBESW113_SHIFT                (17U)
#define STCU_LBESW_LBESW113_WIDTH                (1U)
#define STCU_LBESW_LBESW113(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW113_SHIFT)) & STCU_LBESW_LBESW113_MASK)

#define STCU_LBESW_LBESW114_MASK                 (0x40000U)
#define STCU_LBESW_LBESW114_SHIFT                (18U)
#define STCU_LBESW_LBESW114_WIDTH                (1U)
#define STCU_LBESW_LBESW114(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW114_SHIFT)) & STCU_LBESW_LBESW114_MASK)

#define STCU_LBESW_LBESW115_MASK                 (0x80000U)
#define STCU_LBESW_LBESW115_SHIFT                (19U)
#define STCU_LBESW_LBESW115_WIDTH                (1U)
#define STCU_LBESW_LBESW115(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW115_SHIFT)) & STCU_LBESW_LBESW115_MASK)

#define STCU_LBESW_LBESW116_MASK                 (0x100000U)
#define STCU_LBESW_LBESW116_SHIFT                (20U)
#define STCU_LBESW_LBESW116_WIDTH                (1U)
#define STCU_LBESW_LBESW116(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW116_SHIFT)) & STCU_LBESW_LBESW116_MASK)

#define STCU_LBESW_LBESW117_MASK                 (0x200000U)
#define STCU_LBESW_LBESW117_SHIFT                (21U)
#define STCU_LBESW_LBESW117_WIDTH                (1U)
#define STCU_LBESW_LBESW117(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW117_SHIFT)) & STCU_LBESW_LBESW117_MASK)

#define STCU_LBESW_LBESW118_MASK                 (0x400000U)
#define STCU_LBESW_LBESW118_SHIFT                (22U)
#define STCU_LBESW_LBESW118_WIDTH                (1U)
#define STCU_LBESW_LBESW118(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW118_SHIFT)) & STCU_LBESW_LBESW118_MASK)

#define STCU_LBESW_LBESW119_MASK                 (0x800000U)
#define STCU_LBESW_LBESW119_SHIFT                (23U)
#define STCU_LBESW_LBESW119_WIDTH                (1U)
#define STCU_LBESW_LBESW119(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW119_SHIFT)) & STCU_LBESW_LBESW119_MASK)

#define STCU_LBESW_LBESW120_MASK                 (0x1000000U)
#define STCU_LBESW_LBESW120_SHIFT                (24U)
#define STCU_LBESW_LBESW120_WIDTH                (1U)
#define STCU_LBESW_LBESW120(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW120_SHIFT)) & STCU_LBESW_LBESW120_MASK)

#define STCU_LBESW_LBESW121_MASK                 (0x2000000U)
#define STCU_LBESW_LBESW121_SHIFT                (25U)
#define STCU_LBESW_LBESW121_WIDTH                (1U)
#define STCU_LBESW_LBESW121(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW121_SHIFT)) & STCU_LBESW_LBESW121_MASK)

#define STCU_LBESW_LBESW122_MASK                 (0x4000000U)
#define STCU_LBESW_LBESW122_SHIFT                (26U)
#define STCU_LBESW_LBESW122_WIDTH                (1U)
#define STCU_LBESW_LBESW122(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW122_SHIFT)) & STCU_LBESW_LBESW122_MASK)

#define STCU_LBESW_LBESW123_MASK                 (0x8000000U)
#define STCU_LBESW_LBESW123_SHIFT                (27U)
#define STCU_LBESW_LBESW123_WIDTH                (1U)
#define STCU_LBESW_LBESW123(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW123_SHIFT)) & STCU_LBESW_LBESW123_MASK)

#define STCU_LBESW_LBESW124_MASK                 (0x10000000U)
#define STCU_LBESW_LBESW124_SHIFT                (28U)
#define STCU_LBESW_LBESW124_WIDTH                (1U)
#define STCU_LBESW_LBESW124(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW124_SHIFT)) & STCU_LBESW_LBESW124_MASK)

#define STCU_LBESW_LBESW125_MASK                 (0x20000000U)
#define STCU_LBESW_LBESW125_SHIFT                (29U)
#define STCU_LBESW_LBESW125_WIDTH                (1U)
#define STCU_LBESW_LBESW125(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW125_SHIFT)) & STCU_LBESW_LBESW125_MASK)

#define STCU_LBESW_LBESW126_MASK                 (0x40000000U)
#define STCU_LBESW_LBESW126_SHIFT                (30U)
#define STCU_LBESW_LBESW126_WIDTH                (1U)
#define STCU_LBESW_LBESW126(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW126_SHIFT)) & STCU_LBESW_LBESW126_MASK)

#define STCU_LBESW_LBESW127_MASK                 (0x80000000U)
#define STCU_LBESW_LBESW127_SHIFT                (31U)
#define STCU_LBESW_LBESW127_WIDTH                (1U)
#define STCU_LBESW_LBESW127(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBESW_LBESW127_SHIFT)) & STCU_LBESW_LBESW127_MASK)
/*! @} */

/*! @name LBRMSW - STCU2 Online LBIST Reset Management */
/*! @{ */

#define STCU_LBRMSW_LBRMSW0_MASK                 (0x1U)
#define STCU_LBRMSW_LBRMSW0_SHIFT                (0U)
#define STCU_LBRMSW_LBRMSW0_WIDTH                (1U)
#define STCU_LBRMSW_LBRMSW0(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW0_SHIFT)) & STCU_LBRMSW_LBRMSW0_MASK)

#define STCU_LBRMSW_LBRMSW1_MASK                 (0x2U)
#define STCU_LBRMSW_LBRMSW1_SHIFT                (1U)
#define STCU_LBRMSW_LBRMSW1_WIDTH                (1U)
#define STCU_LBRMSW_LBRMSW1(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW1_SHIFT)) & STCU_LBRMSW_LBRMSW1_MASK)

#define STCU_LBRMSW_LBRMSW2_MASK                 (0x4U)
#define STCU_LBRMSW_LBRMSW2_SHIFT                (2U)
#define STCU_LBRMSW_LBRMSW2_WIDTH                (1U)
#define STCU_LBRMSW_LBRMSW2(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW2_SHIFT)) & STCU_LBRMSW_LBRMSW2_MASK)

#define STCU_LBRMSW_LBRMSW3_MASK                 (0x8U)
#define STCU_LBRMSW_LBRMSW3_SHIFT                (3U)
#define STCU_LBRMSW_LBRMSW3_WIDTH                (1U)
#define STCU_LBRMSW_LBRMSW3(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW3_SHIFT)) & STCU_LBRMSW_LBRMSW3_MASK)

#define STCU_LBRMSW_LBRMSW4_MASK                 (0x10U)
#define STCU_LBRMSW_LBRMSW4_SHIFT                (4U)
#define STCU_LBRMSW_LBRMSW4_WIDTH                (1U)
#define STCU_LBRMSW_LBRMSW4(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW4_SHIFT)) & STCU_LBRMSW_LBRMSW4_MASK)

#define STCU_LBRMSW_LBRMSW5_MASK                 (0x20U)
#define STCU_LBRMSW_LBRMSW5_SHIFT                (5U)
#define STCU_LBRMSW_LBRMSW5_WIDTH                (1U)
#define STCU_LBRMSW_LBRMSW5(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW5_SHIFT)) & STCU_LBRMSW_LBRMSW5_MASK)

#define STCU_LBRMSW_LBRMSW6_MASK                 (0x40U)
#define STCU_LBRMSW_LBRMSW6_SHIFT                (6U)
#define STCU_LBRMSW_LBRMSW6_WIDTH                (1U)
#define STCU_LBRMSW_LBRMSW6(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW6_SHIFT)) & STCU_LBRMSW_LBRMSW6_MASK)

#define STCU_LBRMSW_LBRMSW7_MASK                 (0x80U)
#define STCU_LBRMSW_LBRMSW7_SHIFT                (7U)
#define STCU_LBRMSW_LBRMSW7_WIDTH                (1U)
#define STCU_LBRMSW_LBRMSW7(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW7_SHIFT)) & STCU_LBRMSW_LBRMSW7_MASK)

#define STCU_LBRMSW_LBRMSW8_MASK                 (0x100U)
#define STCU_LBRMSW_LBRMSW8_SHIFT                (8U)
#define STCU_LBRMSW_LBRMSW8_WIDTH                (1U)
#define STCU_LBRMSW_LBRMSW8(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW8_SHIFT)) & STCU_LBRMSW_LBRMSW8_MASK)

#define STCU_LBRMSW_LBRMSW9_MASK                 (0x200U)
#define STCU_LBRMSW_LBRMSW9_SHIFT                (9U)
#define STCU_LBRMSW_LBRMSW9_WIDTH                (1U)
#define STCU_LBRMSW_LBRMSW9(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW9_SHIFT)) & STCU_LBRMSW_LBRMSW9_MASK)

#define STCU_LBRMSW_LBRMSW10_MASK                (0x400U)
#define STCU_LBRMSW_LBRMSW10_SHIFT               (10U)
#define STCU_LBRMSW_LBRMSW10_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW10(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW10_SHIFT)) & STCU_LBRMSW_LBRMSW10_MASK)

#define STCU_LBRMSW_LBRMSW11_MASK                (0x800U)
#define STCU_LBRMSW_LBRMSW11_SHIFT               (11U)
#define STCU_LBRMSW_LBRMSW11_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW11(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW11_SHIFT)) & STCU_LBRMSW_LBRMSW11_MASK)

#define STCU_LBRMSW_LBRMSW12_MASK                (0x1000U)
#define STCU_LBRMSW_LBRMSW12_SHIFT               (12U)
#define STCU_LBRMSW_LBRMSW12_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW12(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW12_SHIFT)) & STCU_LBRMSW_LBRMSW12_MASK)

#define STCU_LBRMSW_LBRMSW13_MASK                (0x2000U)
#define STCU_LBRMSW_LBRMSW13_SHIFT               (13U)
#define STCU_LBRMSW_LBRMSW13_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW13(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW13_SHIFT)) & STCU_LBRMSW_LBRMSW13_MASK)

#define STCU_LBRMSW_LBRMSW14_MASK                (0x4000U)
#define STCU_LBRMSW_LBRMSW14_SHIFT               (14U)
#define STCU_LBRMSW_LBRMSW14_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW14(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW14_SHIFT)) & STCU_LBRMSW_LBRMSW14_MASK)

#define STCU_LBRMSW_LBRMSW15_MASK                (0x8000U)
#define STCU_LBRMSW_LBRMSW15_SHIFT               (15U)
#define STCU_LBRMSW_LBRMSW15_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW15(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW15_SHIFT)) & STCU_LBRMSW_LBRMSW15_MASK)

#define STCU_LBRMSW_LBRMSW16_MASK                (0x10000U)
#define STCU_LBRMSW_LBRMSW16_SHIFT               (16U)
#define STCU_LBRMSW_LBRMSW16_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW16(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW16_SHIFT)) & STCU_LBRMSW_LBRMSW16_MASK)

#define STCU_LBRMSW_LBRMSW17_MASK                (0x20000U)
#define STCU_LBRMSW_LBRMSW17_SHIFT               (17U)
#define STCU_LBRMSW_LBRMSW17_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW17(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW17_SHIFT)) & STCU_LBRMSW_LBRMSW17_MASK)

#define STCU_LBRMSW_LBRMSW18_MASK                (0x40000U)
#define STCU_LBRMSW_LBRMSW18_SHIFT               (18U)
#define STCU_LBRMSW_LBRMSW18_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW18(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW18_SHIFT)) & STCU_LBRMSW_LBRMSW18_MASK)

#define STCU_LBRMSW_LBRMSW19_MASK                (0x80000U)
#define STCU_LBRMSW_LBRMSW19_SHIFT               (19U)
#define STCU_LBRMSW_LBRMSW19_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW19(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW19_SHIFT)) & STCU_LBRMSW_LBRMSW19_MASK)

#define STCU_LBRMSW_LBRMSW20_MASK                (0x100000U)
#define STCU_LBRMSW_LBRMSW20_SHIFT               (20U)
#define STCU_LBRMSW_LBRMSW20_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW20(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW20_SHIFT)) & STCU_LBRMSW_LBRMSW20_MASK)

#define STCU_LBRMSW_LBRMSW21_MASK                (0x200000U)
#define STCU_LBRMSW_LBRMSW21_SHIFT               (21U)
#define STCU_LBRMSW_LBRMSW21_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW21(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW21_SHIFT)) & STCU_LBRMSW_LBRMSW21_MASK)

#define STCU_LBRMSW_LBRMSW22_MASK                (0x400000U)
#define STCU_LBRMSW_LBRMSW22_SHIFT               (22U)
#define STCU_LBRMSW_LBRMSW22_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW22(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW22_SHIFT)) & STCU_LBRMSW_LBRMSW22_MASK)

#define STCU_LBRMSW_LBRMSW23_MASK                (0x800000U)
#define STCU_LBRMSW_LBRMSW23_SHIFT               (23U)
#define STCU_LBRMSW_LBRMSW23_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW23(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW23_SHIFT)) & STCU_LBRMSW_LBRMSW23_MASK)

#define STCU_LBRMSW_LBRMSW24_MASK                (0x1000000U)
#define STCU_LBRMSW_LBRMSW24_SHIFT               (24U)
#define STCU_LBRMSW_LBRMSW24_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW24(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW24_SHIFT)) & STCU_LBRMSW_LBRMSW24_MASK)

#define STCU_LBRMSW_LBRMSW25_MASK                (0x2000000U)
#define STCU_LBRMSW_LBRMSW25_SHIFT               (25U)
#define STCU_LBRMSW_LBRMSW25_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW25(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW25_SHIFT)) & STCU_LBRMSW_LBRMSW25_MASK)

#define STCU_LBRMSW_LBRMSW26_MASK                (0x4000000U)
#define STCU_LBRMSW_LBRMSW26_SHIFT               (26U)
#define STCU_LBRMSW_LBRMSW26_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW26(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW26_SHIFT)) & STCU_LBRMSW_LBRMSW26_MASK)

#define STCU_LBRMSW_LBRMSW27_MASK                (0x8000000U)
#define STCU_LBRMSW_LBRMSW27_SHIFT               (27U)
#define STCU_LBRMSW_LBRMSW27_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW27(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW27_SHIFT)) & STCU_LBRMSW_LBRMSW27_MASK)

#define STCU_LBRMSW_LBRMSW28_MASK                (0x10000000U)
#define STCU_LBRMSW_LBRMSW28_SHIFT               (28U)
#define STCU_LBRMSW_LBRMSW28_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW28(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW28_SHIFT)) & STCU_LBRMSW_LBRMSW28_MASK)

#define STCU_LBRMSW_LBRMSW29_MASK                (0x20000000U)
#define STCU_LBRMSW_LBRMSW29_SHIFT               (29U)
#define STCU_LBRMSW_LBRMSW29_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW29(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW29_SHIFT)) & STCU_LBRMSW_LBRMSW29_MASK)

#define STCU_LBRMSW_LBRMSW30_MASK                (0x40000000U)
#define STCU_LBRMSW_LBRMSW30_SHIFT               (30U)
#define STCU_LBRMSW_LBRMSW30_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW30(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW30_SHIFT)) & STCU_LBRMSW_LBRMSW30_MASK)

#define STCU_LBRMSW_LBRMSW31_MASK                (0x80000000U)
#define STCU_LBRMSW_LBRMSW31_SHIFT               (31U)
#define STCU_LBRMSW_LBRMSW31_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW31(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW31_SHIFT)) & STCU_LBRMSW_LBRMSW31_MASK)

#define STCU_LBRMSW_LBRMSW32_MASK                (0x1U)
#define STCU_LBRMSW_LBRMSW32_SHIFT               (0U)
#define STCU_LBRMSW_LBRMSW32_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW32(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW32_SHIFT)) & STCU_LBRMSW_LBRMSW32_MASK)

#define STCU_LBRMSW_LBRMSW33_MASK                (0x2U)
#define STCU_LBRMSW_LBRMSW33_SHIFT               (1U)
#define STCU_LBRMSW_LBRMSW33_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW33(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW33_SHIFT)) & STCU_LBRMSW_LBRMSW33_MASK)

#define STCU_LBRMSW_LBRMSW34_MASK                (0x4U)
#define STCU_LBRMSW_LBRMSW34_SHIFT               (2U)
#define STCU_LBRMSW_LBRMSW34_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW34(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW34_SHIFT)) & STCU_LBRMSW_LBRMSW34_MASK)

#define STCU_LBRMSW_LBRMSW35_MASK                (0x8U)
#define STCU_LBRMSW_LBRMSW35_SHIFT               (3U)
#define STCU_LBRMSW_LBRMSW35_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW35(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW35_SHIFT)) & STCU_LBRMSW_LBRMSW35_MASK)

#define STCU_LBRMSW_LBRMSW36_MASK                (0x10U)
#define STCU_LBRMSW_LBRMSW36_SHIFT               (4U)
#define STCU_LBRMSW_LBRMSW36_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW36(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW36_SHIFT)) & STCU_LBRMSW_LBRMSW36_MASK)

#define STCU_LBRMSW_LBRMSW37_MASK                (0x20U)
#define STCU_LBRMSW_LBRMSW37_SHIFT               (5U)
#define STCU_LBRMSW_LBRMSW37_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW37(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW37_SHIFT)) & STCU_LBRMSW_LBRMSW37_MASK)

#define STCU_LBRMSW_LBRMSW38_MASK                (0x40U)
#define STCU_LBRMSW_LBRMSW38_SHIFT               (6U)
#define STCU_LBRMSW_LBRMSW38_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW38(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW38_SHIFT)) & STCU_LBRMSW_LBRMSW38_MASK)

#define STCU_LBRMSW_LBRMSW39_MASK                (0x80U)
#define STCU_LBRMSW_LBRMSW39_SHIFT               (7U)
#define STCU_LBRMSW_LBRMSW39_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW39(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW39_SHIFT)) & STCU_LBRMSW_LBRMSW39_MASK)

#define STCU_LBRMSW_LBRMSW40_MASK                (0x100U)
#define STCU_LBRMSW_LBRMSW40_SHIFT               (8U)
#define STCU_LBRMSW_LBRMSW40_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW40(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW40_SHIFT)) & STCU_LBRMSW_LBRMSW40_MASK)

#define STCU_LBRMSW_LBRMSW41_MASK                (0x200U)
#define STCU_LBRMSW_LBRMSW41_SHIFT               (9U)
#define STCU_LBRMSW_LBRMSW41_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW41(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW41_SHIFT)) & STCU_LBRMSW_LBRMSW41_MASK)

#define STCU_LBRMSW_LBRMSW42_MASK                (0x400U)
#define STCU_LBRMSW_LBRMSW42_SHIFT               (10U)
#define STCU_LBRMSW_LBRMSW42_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW42(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW42_SHIFT)) & STCU_LBRMSW_LBRMSW42_MASK)

#define STCU_LBRMSW_LBRMSW43_MASK                (0x800U)
#define STCU_LBRMSW_LBRMSW43_SHIFT               (11U)
#define STCU_LBRMSW_LBRMSW43_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW43(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW43_SHIFT)) & STCU_LBRMSW_LBRMSW43_MASK)

#define STCU_LBRMSW_LBRMSW44_MASK                (0x1000U)
#define STCU_LBRMSW_LBRMSW44_SHIFT               (12U)
#define STCU_LBRMSW_LBRMSW44_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW44(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW44_SHIFT)) & STCU_LBRMSW_LBRMSW44_MASK)

#define STCU_LBRMSW_LBRMSW45_MASK                (0x2000U)
#define STCU_LBRMSW_LBRMSW45_SHIFT               (13U)
#define STCU_LBRMSW_LBRMSW45_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW45(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW45_SHIFT)) & STCU_LBRMSW_LBRMSW45_MASK)

#define STCU_LBRMSW_LBRMSW46_MASK                (0x4000U)
#define STCU_LBRMSW_LBRMSW46_SHIFT               (14U)
#define STCU_LBRMSW_LBRMSW46_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW46(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW46_SHIFT)) & STCU_LBRMSW_LBRMSW46_MASK)

#define STCU_LBRMSW_LBRMSW47_MASK                (0x8000U)
#define STCU_LBRMSW_LBRMSW47_SHIFT               (15U)
#define STCU_LBRMSW_LBRMSW47_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW47(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW47_SHIFT)) & STCU_LBRMSW_LBRMSW47_MASK)

#define STCU_LBRMSW_LBRMSW48_MASK                (0x10000U)
#define STCU_LBRMSW_LBRMSW48_SHIFT               (16U)
#define STCU_LBRMSW_LBRMSW48_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW48(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW48_SHIFT)) & STCU_LBRMSW_LBRMSW48_MASK)

#define STCU_LBRMSW_LBRMSW49_MASK                (0x20000U)
#define STCU_LBRMSW_LBRMSW49_SHIFT               (17U)
#define STCU_LBRMSW_LBRMSW49_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW49(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW49_SHIFT)) & STCU_LBRMSW_LBRMSW49_MASK)

#define STCU_LBRMSW_LBRMSW50_MASK                (0x40000U)
#define STCU_LBRMSW_LBRMSW50_SHIFT               (18U)
#define STCU_LBRMSW_LBRMSW50_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW50(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW50_SHIFT)) & STCU_LBRMSW_LBRMSW50_MASK)

#define STCU_LBRMSW_LBRMSW51_MASK                (0x80000U)
#define STCU_LBRMSW_LBRMSW51_SHIFT               (19U)
#define STCU_LBRMSW_LBRMSW51_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW51(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW51_SHIFT)) & STCU_LBRMSW_LBRMSW51_MASK)

#define STCU_LBRMSW_LBRMSW52_MASK                (0x100000U)
#define STCU_LBRMSW_LBRMSW52_SHIFT               (20U)
#define STCU_LBRMSW_LBRMSW52_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW52(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW52_SHIFT)) & STCU_LBRMSW_LBRMSW52_MASK)

#define STCU_LBRMSW_LBRMSW53_MASK                (0x200000U)
#define STCU_LBRMSW_LBRMSW53_SHIFT               (21U)
#define STCU_LBRMSW_LBRMSW53_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW53(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW53_SHIFT)) & STCU_LBRMSW_LBRMSW53_MASK)

#define STCU_LBRMSW_LBRMSW54_MASK                (0x400000U)
#define STCU_LBRMSW_LBRMSW54_SHIFT               (22U)
#define STCU_LBRMSW_LBRMSW54_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW54(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW54_SHIFT)) & STCU_LBRMSW_LBRMSW54_MASK)

#define STCU_LBRMSW_LBRMSW55_MASK                (0x800000U)
#define STCU_LBRMSW_LBRMSW55_SHIFT               (23U)
#define STCU_LBRMSW_LBRMSW55_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW55(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW55_SHIFT)) & STCU_LBRMSW_LBRMSW55_MASK)

#define STCU_LBRMSW_LBRMSW56_MASK                (0x1000000U)
#define STCU_LBRMSW_LBRMSW56_SHIFT               (24U)
#define STCU_LBRMSW_LBRMSW56_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW56(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW56_SHIFT)) & STCU_LBRMSW_LBRMSW56_MASK)

#define STCU_LBRMSW_LBRMSW57_MASK                (0x2000000U)
#define STCU_LBRMSW_LBRMSW57_SHIFT               (25U)
#define STCU_LBRMSW_LBRMSW57_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW57(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW57_SHIFT)) & STCU_LBRMSW_LBRMSW57_MASK)

#define STCU_LBRMSW_LBRMSW58_MASK                (0x4000000U)
#define STCU_LBRMSW_LBRMSW58_SHIFT               (26U)
#define STCU_LBRMSW_LBRMSW58_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW58(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW58_SHIFT)) & STCU_LBRMSW_LBRMSW58_MASK)

#define STCU_LBRMSW_LBRMSW59_MASK                (0x8000000U)
#define STCU_LBRMSW_LBRMSW59_SHIFT               (27U)
#define STCU_LBRMSW_LBRMSW59_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW59(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW59_SHIFT)) & STCU_LBRMSW_LBRMSW59_MASK)

#define STCU_LBRMSW_LBRMSW60_MASK                (0x10000000U)
#define STCU_LBRMSW_LBRMSW60_SHIFT               (28U)
#define STCU_LBRMSW_LBRMSW60_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW60(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW60_SHIFT)) & STCU_LBRMSW_LBRMSW60_MASK)

#define STCU_LBRMSW_LBRMSW61_MASK                (0x20000000U)
#define STCU_LBRMSW_LBRMSW61_SHIFT               (29U)
#define STCU_LBRMSW_LBRMSW61_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW61(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW61_SHIFT)) & STCU_LBRMSW_LBRMSW61_MASK)

#define STCU_LBRMSW_LBRMSW62_MASK                (0x40000000U)
#define STCU_LBRMSW_LBRMSW62_SHIFT               (30U)
#define STCU_LBRMSW_LBRMSW62_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW62(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW62_SHIFT)) & STCU_LBRMSW_LBRMSW62_MASK)

#define STCU_LBRMSW_LBRMSW63_MASK                (0x80000000U)
#define STCU_LBRMSW_LBRMSW63_SHIFT               (31U)
#define STCU_LBRMSW_LBRMSW63_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW63(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW63_SHIFT)) & STCU_LBRMSW_LBRMSW63_MASK)

#define STCU_LBRMSW_LBRMSW64_MASK                (0x1U)
#define STCU_LBRMSW_LBRMSW64_SHIFT               (0U)
#define STCU_LBRMSW_LBRMSW64_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW64(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW64_SHIFT)) & STCU_LBRMSW_LBRMSW64_MASK)

#define STCU_LBRMSW_LBRMSW65_MASK                (0x2U)
#define STCU_LBRMSW_LBRMSW65_SHIFT               (1U)
#define STCU_LBRMSW_LBRMSW65_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW65(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW65_SHIFT)) & STCU_LBRMSW_LBRMSW65_MASK)

#define STCU_LBRMSW_LBRMSW66_MASK                (0x4U)
#define STCU_LBRMSW_LBRMSW66_SHIFT               (2U)
#define STCU_LBRMSW_LBRMSW66_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW66(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW66_SHIFT)) & STCU_LBRMSW_LBRMSW66_MASK)

#define STCU_LBRMSW_LBRMSW67_MASK                (0x8U)
#define STCU_LBRMSW_LBRMSW67_SHIFT               (3U)
#define STCU_LBRMSW_LBRMSW67_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW67(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW67_SHIFT)) & STCU_LBRMSW_LBRMSW67_MASK)

#define STCU_LBRMSW_LBRMSW68_MASK                (0x10U)
#define STCU_LBRMSW_LBRMSW68_SHIFT               (4U)
#define STCU_LBRMSW_LBRMSW68_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW68(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW68_SHIFT)) & STCU_LBRMSW_LBRMSW68_MASK)

#define STCU_LBRMSW_LBRMSW69_MASK                (0x20U)
#define STCU_LBRMSW_LBRMSW69_SHIFT               (5U)
#define STCU_LBRMSW_LBRMSW69_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW69(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW69_SHIFT)) & STCU_LBRMSW_LBRMSW69_MASK)

#define STCU_LBRMSW_LBRMSW70_MASK                (0x40U)
#define STCU_LBRMSW_LBRMSW70_SHIFT               (6U)
#define STCU_LBRMSW_LBRMSW70_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW70(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW70_SHIFT)) & STCU_LBRMSW_LBRMSW70_MASK)

#define STCU_LBRMSW_LBRMSW71_MASK                (0x80U)
#define STCU_LBRMSW_LBRMSW71_SHIFT               (7U)
#define STCU_LBRMSW_LBRMSW71_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW71(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW71_SHIFT)) & STCU_LBRMSW_LBRMSW71_MASK)

#define STCU_LBRMSW_LBRMSW72_MASK                (0x100U)
#define STCU_LBRMSW_LBRMSW72_SHIFT               (8U)
#define STCU_LBRMSW_LBRMSW72_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW72(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW72_SHIFT)) & STCU_LBRMSW_LBRMSW72_MASK)

#define STCU_LBRMSW_LBRMSW73_MASK                (0x200U)
#define STCU_LBRMSW_LBRMSW73_SHIFT               (9U)
#define STCU_LBRMSW_LBRMSW73_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW73(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW73_SHIFT)) & STCU_LBRMSW_LBRMSW73_MASK)

#define STCU_LBRMSW_LBRMSW74_MASK                (0x400U)
#define STCU_LBRMSW_LBRMSW74_SHIFT               (10U)
#define STCU_LBRMSW_LBRMSW74_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW74(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW74_SHIFT)) & STCU_LBRMSW_LBRMSW74_MASK)

#define STCU_LBRMSW_LBRMSW75_MASK                (0x800U)
#define STCU_LBRMSW_LBRMSW75_SHIFT               (11U)
#define STCU_LBRMSW_LBRMSW75_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW75(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW75_SHIFT)) & STCU_LBRMSW_LBRMSW75_MASK)

#define STCU_LBRMSW_LBRMSW76_MASK                (0x1000U)
#define STCU_LBRMSW_LBRMSW76_SHIFT               (12U)
#define STCU_LBRMSW_LBRMSW76_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW76(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW76_SHIFT)) & STCU_LBRMSW_LBRMSW76_MASK)

#define STCU_LBRMSW_LBRMSW77_MASK                (0x2000U)
#define STCU_LBRMSW_LBRMSW77_SHIFT               (13U)
#define STCU_LBRMSW_LBRMSW77_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW77(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW77_SHIFT)) & STCU_LBRMSW_LBRMSW77_MASK)

#define STCU_LBRMSW_LBRMSW78_MASK                (0x4000U)
#define STCU_LBRMSW_LBRMSW78_SHIFT               (14U)
#define STCU_LBRMSW_LBRMSW78_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW78(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW78_SHIFT)) & STCU_LBRMSW_LBRMSW78_MASK)

#define STCU_LBRMSW_LBRMSW79_MASK                (0x8000U)
#define STCU_LBRMSW_LBRMSW79_SHIFT               (15U)
#define STCU_LBRMSW_LBRMSW79_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW79(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW79_SHIFT)) & STCU_LBRMSW_LBRMSW79_MASK)

#define STCU_LBRMSW_LBRMSW80_MASK                (0x10000U)
#define STCU_LBRMSW_LBRMSW80_SHIFT               (16U)
#define STCU_LBRMSW_LBRMSW80_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW80(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW80_SHIFT)) & STCU_LBRMSW_LBRMSW80_MASK)

#define STCU_LBRMSW_LBRMSW81_MASK                (0x20000U)
#define STCU_LBRMSW_LBRMSW81_SHIFT               (17U)
#define STCU_LBRMSW_LBRMSW81_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW81(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW81_SHIFT)) & STCU_LBRMSW_LBRMSW81_MASK)

#define STCU_LBRMSW_LBRMSW82_MASK                (0x40000U)
#define STCU_LBRMSW_LBRMSW82_SHIFT               (18U)
#define STCU_LBRMSW_LBRMSW82_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW82(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW82_SHIFT)) & STCU_LBRMSW_LBRMSW82_MASK)

#define STCU_LBRMSW_LBRMSW83_MASK                (0x80000U)
#define STCU_LBRMSW_LBRMSW83_SHIFT               (19U)
#define STCU_LBRMSW_LBRMSW83_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW83(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW83_SHIFT)) & STCU_LBRMSW_LBRMSW83_MASK)

#define STCU_LBRMSW_LBRMSW84_MASK                (0x100000U)
#define STCU_LBRMSW_LBRMSW84_SHIFT               (20U)
#define STCU_LBRMSW_LBRMSW84_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW84(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW84_SHIFT)) & STCU_LBRMSW_LBRMSW84_MASK)

#define STCU_LBRMSW_LBRMSW85_MASK                (0x200000U)
#define STCU_LBRMSW_LBRMSW85_SHIFT               (21U)
#define STCU_LBRMSW_LBRMSW85_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW85(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW85_SHIFT)) & STCU_LBRMSW_LBRMSW85_MASK)

#define STCU_LBRMSW_LBRMSW86_MASK                (0x400000U)
#define STCU_LBRMSW_LBRMSW86_SHIFT               (22U)
#define STCU_LBRMSW_LBRMSW86_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW86(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW86_SHIFT)) & STCU_LBRMSW_LBRMSW86_MASK)

#define STCU_LBRMSW_LBRMSW87_MASK                (0x800000U)
#define STCU_LBRMSW_LBRMSW87_SHIFT               (23U)
#define STCU_LBRMSW_LBRMSW87_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW87(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW87_SHIFT)) & STCU_LBRMSW_LBRMSW87_MASK)

#define STCU_LBRMSW_LBRMSW88_MASK                (0x1000000U)
#define STCU_LBRMSW_LBRMSW88_SHIFT               (24U)
#define STCU_LBRMSW_LBRMSW88_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW88(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW88_SHIFT)) & STCU_LBRMSW_LBRMSW88_MASK)

#define STCU_LBRMSW_LBRMSW89_MASK                (0x2000000U)
#define STCU_LBRMSW_LBRMSW89_SHIFT               (25U)
#define STCU_LBRMSW_LBRMSW89_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW89(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW89_SHIFT)) & STCU_LBRMSW_LBRMSW89_MASK)

#define STCU_LBRMSW_LBRMSW90_MASK                (0x4000000U)
#define STCU_LBRMSW_LBRMSW90_SHIFT               (26U)
#define STCU_LBRMSW_LBRMSW90_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW90(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW90_SHIFT)) & STCU_LBRMSW_LBRMSW90_MASK)

#define STCU_LBRMSW_LBRMSW91_MASK                (0x8000000U)
#define STCU_LBRMSW_LBRMSW91_SHIFT               (27U)
#define STCU_LBRMSW_LBRMSW91_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW91(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW91_SHIFT)) & STCU_LBRMSW_LBRMSW91_MASK)

#define STCU_LBRMSW_LBRMSW92_MASK                (0x10000000U)
#define STCU_LBRMSW_LBRMSW92_SHIFT               (28U)
#define STCU_LBRMSW_LBRMSW92_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW92(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW92_SHIFT)) & STCU_LBRMSW_LBRMSW92_MASK)

#define STCU_LBRMSW_LBRMSW93_MASK                (0x20000000U)
#define STCU_LBRMSW_LBRMSW93_SHIFT               (29U)
#define STCU_LBRMSW_LBRMSW93_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW93(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW93_SHIFT)) & STCU_LBRMSW_LBRMSW93_MASK)

#define STCU_LBRMSW_LBRMSW94_MASK                (0x40000000U)
#define STCU_LBRMSW_LBRMSW94_SHIFT               (30U)
#define STCU_LBRMSW_LBRMSW94_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW94(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW94_SHIFT)) & STCU_LBRMSW_LBRMSW94_MASK)

#define STCU_LBRMSW_LBRMSW95_MASK                (0x80000000U)
#define STCU_LBRMSW_LBRMSW95_SHIFT               (31U)
#define STCU_LBRMSW_LBRMSW95_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW95(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW95_SHIFT)) & STCU_LBRMSW_LBRMSW95_MASK)

#define STCU_LBRMSW_LBRMSW96_MASK                (0x1U)
#define STCU_LBRMSW_LBRMSW96_SHIFT               (0U)
#define STCU_LBRMSW_LBRMSW96_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW96(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW96_SHIFT)) & STCU_LBRMSW_LBRMSW96_MASK)

#define STCU_LBRMSW_LBRMSW97_MASK                (0x2U)
#define STCU_LBRMSW_LBRMSW97_SHIFT               (1U)
#define STCU_LBRMSW_LBRMSW97_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW97(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW97_SHIFT)) & STCU_LBRMSW_LBRMSW97_MASK)

#define STCU_LBRMSW_LBRMSW98_MASK                (0x4U)
#define STCU_LBRMSW_LBRMSW98_SHIFT               (2U)
#define STCU_LBRMSW_LBRMSW98_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW98(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW98_SHIFT)) & STCU_LBRMSW_LBRMSW98_MASK)

#define STCU_LBRMSW_LBRMSW99_MASK                (0x8U)
#define STCU_LBRMSW_LBRMSW99_SHIFT               (3U)
#define STCU_LBRMSW_LBRMSW99_WIDTH               (1U)
#define STCU_LBRMSW_LBRMSW99(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW99_SHIFT)) & STCU_LBRMSW_LBRMSW99_MASK)

#define STCU_LBRMSW_LBRMSW100_MASK               (0x10U)
#define STCU_LBRMSW_LBRMSW100_SHIFT              (4U)
#define STCU_LBRMSW_LBRMSW100_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW100(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW100_SHIFT)) & STCU_LBRMSW_LBRMSW100_MASK)

#define STCU_LBRMSW_LBRMSW101_MASK               (0x20U)
#define STCU_LBRMSW_LBRMSW101_SHIFT              (5U)
#define STCU_LBRMSW_LBRMSW101_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW101(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW101_SHIFT)) & STCU_LBRMSW_LBRMSW101_MASK)

#define STCU_LBRMSW_LBRMSW102_MASK               (0x40U)
#define STCU_LBRMSW_LBRMSW102_SHIFT              (6U)
#define STCU_LBRMSW_LBRMSW102_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW102(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW102_SHIFT)) & STCU_LBRMSW_LBRMSW102_MASK)

#define STCU_LBRMSW_LBRMSW103_MASK               (0x80U)
#define STCU_LBRMSW_LBRMSW103_SHIFT              (7U)
#define STCU_LBRMSW_LBRMSW103_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW103(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW103_SHIFT)) & STCU_LBRMSW_LBRMSW103_MASK)

#define STCU_LBRMSW_LBRMSW104_MASK               (0x100U)
#define STCU_LBRMSW_LBRMSW104_SHIFT              (8U)
#define STCU_LBRMSW_LBRMSW104_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW104(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW104_SHIFT)) & STCU_LBRMSW_LBRMSW104_MASK)

#define STCU_LBRMSW_LBRMSW105_MASK               (0x200U)
#define STCU_LBRMSW_LBRMSW105_SHIFT              (9U)
#define STCU_LBRMSW_LBRMSW105_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW105(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW105_SHIFT)) & STCU_LBRMSW_LBRMSW105_MASK)

#define STCU_LBRMSW_LBRMSW106_MASK               (0x400U)
#define STCU_LBRMSW_LBRMSW106_SHIFT              (10U)
#define STCU_LBRMSW_LBRMSW106_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW106(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW106_SHIFT)) & STCU_LBRMSW_LBRMSW106_MASK)

#define STCU_LBRMSW_LBRMSW107_MASK               (0x800U)
#define STCU_LBRMSW_LBRMSW107_SHIFT              (11U)
#define STCU_LBRMSW_LBRMSW107_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW107(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW107_SHIFT)) & STCU_LBRMSW_LBRMSW107_MASK)

#define STCU_LBRMSW_LBRMSW108_MASK               (0x1000U)
#define STCU_LBRMSW_LBRMSW108_SHIFT              (12U)
#define STCU_LBRMSW_LBRMSW108_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW108(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW108_SHIFT)) & STCU_LBRMSW_LBRMSW108_MASK)

#define STCU_LBRMSW_LBRMSW109_MASK               (0x2000U)
#define STCU_LBRMSW_LBRMSW109_SHIFT              (13U)
#define STCU_LBRMSW_LBRMSW109_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW109(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW109_SHIFT)) & STCU_LBRMSW_LBRMSW109_MASK)

#define STCU_LBRMSW_LBRMSW110_MASK               (0x4000U)
#define STCU_LBRMSW_LBRMSW110_SHIFT              (14U)
#define STCU_LBRMSW_LBRMSW110_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW110(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW110_SHIFT)) & STCU_LBRMSW_LBRMSW110_MASK)

#define STCU_LBRMSW_LBRMSW111_MASK               (0x8000U)
#define STCU_LBRMSW_LBRMSW111_SHIFT              (15U)
#define STCU_LBRMSW_LBRMSW111_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW111(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW111_SHIFT)) & STCU_LBRMSW_LBRMSW111_MASK)

#define STCU_LBRMSW_LBRMSW112_MASK               (0x10000U)
#define STCU_LBRMSW_LBRMSW112_SHIFT              (16U)
#define STCU_LBRMSW_LBRMSW112_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW112(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW112_SHIFT)) & STCU_LBRMSW_LBRMSW112_MASK)

#define STCU_LBRMSW_LBRMSW113_MASK               (0x20000U)
#define STCU_LBRMSW_LBRMSW113_SHIFT              (17U)
#define STCU_LBRMSW_LBRMSW113_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW113(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW113_SHIFT)) & STCU_LBRMSW_LBRMSW113_MASK)

#define STCU_LBRMSW_LBRMSW114_MASK               (0x40000U)
#define STCU_LBRMSW_LBRMSW114_SHIFT              (18U)
#define STCU_LBRMSW_LBRMSW114_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW114(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW114_SHIFT)) & STCU_LBRMSW_LBRMSW114_MASK)

#define STCU_LBRMSW_LBRMSW115_MASK               (0x80000U)
#define STCU_LBRMSW_LBRMSW115_SHIFT              (19U)
#define STCU_LBRMSW_LBRMSW115_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW115(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW115_SHIFT)) & STCU_LBRMSW_LBRMSW115_MASK)

#define STCU_LBRMSW_LBRMSW116_MASK               (0x100000U)
#define STCU_LBRMSW_LBRMSW116_SHIFT              (20U)
#define STCU_LBRMSW_LBRMSW116_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW116(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW116_SHIFT)) & STCU_LBRMSW_LBRMSW116_MASK)

#define STCU_LBRMSW_LBRMSW117_MASK               (0x200000U)
#define STCU_LBRMSW_LBRMSW117_SHIFT              (21U)
#define STCU_LBRMSW_LBRMSW117_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW117(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW117_SHIFT)) & STCU_LBRMSW_LBRMSW117_MASK)

#define STCU_LBRMSW_LBRMSW118_MASK               (0x400000U)
#define STCU_LBRMSW_LBRMSW118_SHIFT              (22U)
#define STCU_LBRMSW_LBRMSW118_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW118(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW118_SHIFT)) & STCU_LBRMSW_LBRMSW118_MASK)

#define STCU_LBRMSW_LBRMSW119_MASK               (0x800000U)
#define STCU_LBRMSW_LBRMSW119_SHIFT              (23U)
#define STCU_LBRMSW_LBRMSW119_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW119(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW119_SHIFT)) & STCU_LBRMSW_LBRMSW119_MASK)

#define STCU_LBRMSW_LBRMSW120_MASK               (0x1000000U)
#define STCU_LBRMSW_LBRMSW120_SHIFT              (24U)
#define STCU_LBRMSW_LBRMSW120_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW120(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW120_SHIFT)) & STCU_LBRMSW_LBRMSW120_MASK)

#define STCU_LBRMSW_LBRMSW121_MASK               (0x2000000U)
#define STCU_LBRMSW_LBRMSW121_SHIFT              (25U)
#define STCU_LBRMSW_LBRMSW121_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW121(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW121_SHIFT)) & STCU_LBRMSW_LBRMSW121_MASK)

#define STCU_LBRMSW_LBRMSW122_MASK               (0x4000000U)
#define STCU_LBRMSW_LBRMSW122_SHIFT              (26U)
#define STCU_LBRMSW_LBRMSW122_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW122(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW122_SHIFT)) & STCU_LBRMSW_LBRMSW122_MASK)

#define STCU_LBRMSW_LBRMSW123_MASK               (0x8000000U)
#define STCU_LBRMSW_LBRMSW123_SHIFT              (27U)
#define STCU_LBRMSW_LBRMSW123_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW123(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW123_SHIFT)) & STCU_LBRMSW_LBRMSW123_MASK)

#define STCU_LBRMSW_LBRMSW124_MASK               (0x10000000U)
#define STCU_LBRMSW_LBRMSW124_SHIFT              (28U)
#define STCU_LBRMSW_LBRMSW124_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW124(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW124_SHIFT)) & STCU_LBRMSW_LBRMSW124_MASK)

#define STCU_LBRMSW_LBRMSW125_MASK               (0x20000000U)
#define STCU_LBRMSW_LBRMSW125_SHIFT              (29U)
#define STCU_LBRMSW_LBRMSW125_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW125(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW125_SHIFT)) & STCU_LBRMSW_LBRMSW125_MASK)

#define STCU_LBRMSW_LBRMSW126_MASK               (0x40000000U)
#define STCU_LBRMSW_LBRMSW126_SHIFT              (30U)
#define STCU_LBRMSW_LBRMSW126_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW126(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW126_SHIFT)) & STCU_LBRMSW_LBRMSW126_MASK)

#define STCU_LBRMSW_LBRMSW127_MASK               (0x80000000U)
#define STCU_LBRMSW_LBRMSW127_SHIFT              (31U)
#define STCU_LBRMSW_LBRMSW127_WIDTH              (1U)
#define STCU_LBRMSW_LBRMSW127(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW_LBRMSW127_SHIFT)) & STCU_LBRMSW_LBRMSW127_MASK)
/*! @} */

/*! @name LBUFM - STCU2 Online LBIST Unrecoverable FM */
/*! @{ */

#define STCU_LBUFM_LBUFM0_MASK                   (0x1U)
#define STCU_LBUFM_LBUFM0_SHIFT                  (0U)
#define STCU_LBUFM_LBUFM0_WIDTH                  (1U)
#define STCU_LBUFM_LBUFM0(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM0_SHIFT)) & STCU_LBUFM_LBUFM0_MASK)

#define STCU_LBUFM_LBUFM1_MASK                   (0x2U)
#define STCU_LBUFM_LBUFM1_SHIFT                  (1U)
#define STCU_LBUFM_LBUFM1_WIDTH                  (1U)
#define STCU_LBUFM_LBUFM1(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM1_SHIFT)) & STCU_LBUFM_LBUFM1_MASK)

#define STCU_LBUFM_LBUFM2_MASK                   (0x4U)
#define STCU_LBUFM_LBUFM2_SHIFT                  (2U)
#define STCU_LBUFM_LBUFM2_WIDTH                  (1U)
#define STCU_LBUFM_LBUFM2(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM2_SHIFT)) & STCU_LBUFM_LBUFM2_MASK)

#define STCU_LBUFM_LBUFM3_MASK                   (0x8U)
#define STCU_LBUFM_LBUFM3_SHIFT                  (3U)
#define STCU_LBUFM_LBUFM3_WIDTH                  (1U)
#define STCU_LBUFM_LBUFM3(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM3_SHIFT)) & STCU_LBUFM_LBUFM3_MASK)

#define STCU_LBUFM_LBUFM4_MASK                   (0x10U)
#define STCU_LBUFM_LBUFM4_SHIFT                  (4U)
#define STCU_LBUFM_LBUFM4_WIDTH                  (1U)
#define STCU_LBUFM_LBUFM4(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM4_SHIFT)) & STCU_LBUFM_LBUFM4_MASK)

#define STCU_LBUFM_LBUFM5_MASK                   (0x20U)
#define STCU_LBUFM_LBUFM5_SHIFT                  (5U)
#define STCU_LBUFM_LBUFM5_WIDTH                  (1U)
#define STCU_LBUFM_LBUFM5(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM5_SHIFT)) & STCU_LBUFM_LBUFM5_MASK)

#define STCU_LBUFM_LBUFM6_MASK                   (0x40U)
#define STCU_LBUFM_LBUFM6_SHIFT                  (6U)
#define STCU_LBUFM_LBUFM6_WIDTH                  (1U)
#define STCU_LBUFM_LBUFM6(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM6_SHIFT)) & STCU_LBUFM_LBUFM6_MASK)

#define STCU_LBUFM_LBUFM7_MASK                   (0x80U)
#define STCU_LBUFM_LBUFM7_SHIFT                  (7U)
#define STCU_LBUFM_LBUFM7_WIDTH                  (1U)
#define STCU_LBUFM_LBUFM7(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM7_SHIFT)) & STCU_LBUFM_LBUFM7_MASK)

#define STCU_LBUFM_LBUFM8_MASK                   (0x100U)
#define STCU_LBUFM_LBUFM8_SHIFT                  (8U)
#define STCU_LBUFM_LBUFM8_WIDTH                  (1U)
#define STCU_LBUFM_LBUFM8(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM8_SHIFT)) & STCU_LBUFM_LBUFM8_MASK)

#define STCU_LBUFM_LBUFM9_MASK                   (0x200U)
#define STCU_LBUFM_LBUFM9_SHIFT                  (9U)
#define STCU_LBUFM_LBUFM9_WIDTH                  (1U)
#define STCU_LBUFM_LBUFM9(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM9_SHIFT)) & STCU_LBUFM_LBUFM9_MASK)

#define STCU_LBUFM_LBUFM10_MASK                  (0x400U)
#define STCU_LBUFM_LBUFM10_SHIFT                 (10U)
#define STCU_LBUFM_LBUFM10_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM10(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM10_SHIFT)) & STCU_LBUFM_LBUFM10_MASK)

#define STCU_LBUFM_LBUFM11_MASK                  (0x800U)
#define STCU_LBUFM_LBUFM11_SHIFT                 (11U)
#define STCU_LBUFM_LBUFM11_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM11(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM11_SHIFT)) & STCU_LBUFM_LBUFM11_MASK)

#define STCU_LBUFM_LBUFM12_MASK                  (0x1000U)
#define STCU_LBUFM_LBUFM12_SHIFT                 (12U)
#define STCU_LBUFM_LBUFM12_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM12(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM12_SHIFT)) & STCU_LBUFM_LBUFM12_MASK)

#define STCU_LBUFM_LBUFM13_MASK                  (0x2000U)
#define STCU_LBUFM_LBUFM13_SHIFT                 (13U)
#define STCU_LBUFM_LBUFM13_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM13(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM13_SHIFT)) & STCU_LBUFM_LBUFM13_MASK)

#define STCU_LBUFM_LBUFM14_MASK                  (0x4000U)
#define STCU_LBUFM_LBUFM14_SHIFT                 (14U)
#define STCU_LBUFM_LBUFM14_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM14(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM14_SHIFT)) & STCU_LBUFM_LBUFM14_MASK)

#define STCU_LBUFM_LBUFM15_MASK                  (0x8000U)
#define STCU_LBUFM_LBUFM15_SHIFT                 (15U)
#define STCU_LBUFM_LBUFM15_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM15(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM15_SHIFT)) & STCU_LBUFM_LBUFM15_MASK)

#define STCU_LBUFM_LBUFM16_MASK                  (0x10000U)
#define STCU_LBUFM_LBUFM16_SHIFT                 (16U)
#define STCU_LBUFM_LBUFM16_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM16(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM16_SHIFT)) & STCU_LBUFM_LBUFM16_MASK)

#define STCU_LBUFM_LBUFM17_MASK                  (0x20000U)
#define STCU_LBUFM_LBUFM17_SHIFT                 (17U)
#define STCU_LBUFM_LBUFM17_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM17(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM17_SHIFT)) & STCU_LBUFM_LBUFM17_MASK)

#define STCU_LBUFM_LBUFM18_MASK                  (0x40000U)
#define STCU_LBUFM_LBUFM18_SHIFT                 (18U)
#define STCU_LBUFM_LBUFM18_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM18(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM18_SHIFT)) & STCU_LBUFM_LBUFM18_MASK)

#define STCU_LBUFM_LBUFM19_MASK                  (0x80000U)
#define STCU_LBUFM_LBUFM19_SHIFT                 (19U)
#define STCU_LBUFM_LBUFM19_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM19(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM19_SHIFT)) & STCU_LBUFM_LBUFM19_MASK)

#define STCU_LBUFM_LBUFM20_MASK                  (0x100000U)
#define STCU_LBUFM_LBUFM20_SHIFT                 (20U)
#define STCU_LBUFM_LBUFM20_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM20(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM20_SHIFT)) & STCU_LBUFM_LBUFM20_MASK)

#define STCU_LBUFM_LBUFM21_MASK                  (0x200000U)
#define STCU_LBUFM_LBUFM21_SHIFT                 (21U)
#define STCU_LBUFM_LBUFM21_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM21(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM21_SHIFT)) & STCU_LBUFM_LBUFM21_MASK)

#define STCU_LBUFM_LBUFM22_MASK                  (0x400000U)
#define STCU_LBUFM_LBUFM22_SHIFT                 (22U)
#define STCU_LBUFM_LBUFM22_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM22(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM22_SHIFT)) & STCU_LBUFM_LBUFM22_MASK)

#define STCU_LBUFM_LBUFM23_MASK                  (0x800000U)
#define STCU_LBUFM_LBUFM23_SHIFT                 (23U)
#define STCU_LBUFM_LBUFM23_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM23(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM23_SHIFT)) & STCU_LBUFM_LBUFM23_MASK)

#define STCU_LBUFM_LBUFM24_MASK                  (0x1000000U)
#define STCU_LBUFM_LBUFM24_SHIFT                 (24U)
#define STCU_LBUFM_LBUFM24_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM24(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM24_SHIFT)) & STCU_LBUFM_LBUFM24_MASK)

#define STCU_LBUFM_LBUFM25_MASK                  (0x2000000U)
#define STCU_LBUFM_LBUFM25_SHIFT                 (25U)
#define STCU_LBUFM_LBUFM25_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM25(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM25_SHIFT)) & STCU_LBUFM_LBUFM25_MASK)

#define STCU_LBUFM_LBUFM26_MASK                  (0x4000000U)
#define STCU_LBUFM_LBUFM26_SHIFT                 (26U)
#define STCU_LBUFM_LBUFM26_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM26(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM26_SHIFT)) & STCU_LBUFM_LBUFM26_MASK)

#define STCU_LBUFM_LBUFM27_MASK                  (0x8000000U)
#define STCU_LBUFM_LBUFM27_SHIFT                 (27U)
#define STCU_LBUFM_LBUFM27_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM27(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM27_SHIFT)) & STCU_LBUFM_LBUFM27_MASK)

#define STCU_LBUFM_LBUFM28_MASK                  (0x10000000U)
#define STCU_LBUFM_LBUFM28_SHIFT                 (28U)
#define STCU_LBUFM_LBUFM28_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM28(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM28_SHIFT)) & STCU_LBUFM_LBUFM28_MASK)

#define STCU_LBUFM_LBUFM29_MASK                  (0x20000000U)
#define STCU_LBUFM_LBUFM29_SHIFT                 (29U)
#define STCU_LBUFM_LBUFM29_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM29(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM29_SHIFT)) & STCU_LBUFM_LBUFM29_MASK)

#define STCU_LBUFM_LBUFM30_MASK                  (0x40000000U)
#define STCU_LBUFM_LBUFM30_SHIFT                 (30U)
#define STCU_LBUFM_LBUFM30_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM30(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM30_SHIFT)) & STCU_LBUFM_LBUFM30_MASK)

#define STCU_LBUFM_LBUFM31_MASK                  (0x80000000U)
#define STCU_LBUFM_LBUFM31_SHIFT                 (31U)
#define STCU_LBUFM_LBUFM31_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM31(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM31_SHIFT)) & STCU_LBUFM_LBUFM31_MASK)

#define STCU_LBUFM_LBUFM32_MASK                  (0x1U)
#define STCU_LBUFM_LBUFM32_SHIFT                 (0U)
#define STCU_LBUFM_LBUFM32_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM32(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM32_SHIFT)) & STCU_LBUFM_LBUFM32_MASK)

#define STCU_LBUFM_LBUFM33_MASK                  (0x2U)
#define STCU_LBUFM_LBUFM33_SHIFT                 (1U)
#define STCU_LBUFM_LBUFM33_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM33(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM33_SHIFT)) & STCU_LBUFM_LBUFM33_MASK)

#define STCU_LBUFM_LBUFM34_MASK                  (0x4U)
#define STCU_LBUFM_LBUFM34_SHIFT                 (2U)
#define STCU_LBUFM_LBUFM34_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM34(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM34_SHIFT)) & STCU_LBUFM_LBUFM34_MASK)

#define STCU_LBUFM_LBUFM35_MASK                  (0x8U)
#define STCU_LBUFM_LBUFM35_SHIFT                 (3U)
#define STCU_LBUFM_LBUFM35_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM35(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM35_SHIFT)) & STCU_LBUFM_LBUFM35_MASK)

#define STCU_LBUFM_LBUFM36_MASK                  (0x10U)
#define STCU_LBUFM_LBUFM36_SHIFT                 (4U)
#define STCU_LBUFM_LBUFM36_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM36(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM36_SHIFT)) & STCU_LBUFM_LBUFM36_MASK)

#define STCU_LBUFM_LBUFM37_MASK                  (0x20U)
#define STCU_LBUFM_LBUFM37_SHIFT                 (5U)
#define STCU_LBUFM_LBUFM37_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM37(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM37_SHIFT)) & STCU_LBUFM_LBUFM37_MASK)

#define STCU_LBUFM_LBUFM38_MASK                  (0x40U)
#define STCU_LBUFM_LBUFM38_SHIFT                 (6U)
#define STCU_LBUFM_LBUFM38_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM38(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM38_SHIFT)) & STCU_LBUFM_LBUFM38_MASK)

#define STCU_LBUFM_LBUFM39_MASK                  (0x80U)
#define STCU_LBUFM_LBUFM39_SHIFT                 (7U)
#define STCU_LBUFM_LBUFM39_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM39(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM39_SHIFT)) & STCU_LBUFM_LBUFM39_MASK)

#define STCU_LBUFM_LBUFM40_MASK                  (0x100U)
#define STCU_LBUFM_LBUFM40_SHIFT                 (8U)
#define STCU_LBUFM_LBUFM40_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM40(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM40_SHIFT)) & STCU_LBUFM_LBUFM40_MASK)

#define STCU_LBUFM_LBUFM41_MASK                  (0x200U)
#define STCU_LBUFM_LBUFM41_SHIFT                 (9U)
#define STCU_LBUFM_LBUFM41_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM41(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM41_SHIFT)) & STCU_LBUFM_LBUFM41_MASK)

#define STCU_LBUFM_LBUFM42_MASK                  (0x400U)
#define STCU_LBUFM_LBUFM42_SHIFT                 (10U)
#define STCU_LBUFM_LBUFM42_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM42(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM42_SHIFT)) & STCU_LBUFM_LBUFM42_MASK)

#define STCU_LBUFM_LBUFM43_MASK                  (0x800U)
#define STCU_LBUFM_LBUFM43_SHIFT                 (11U)
#define STCU_LBUFM_LBUFM43_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM43(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM43_SHIFT)) & STCU_LBUFM_LBUFM43_MASK)

#define STCU_LBUFM_LBUFM44_MASK                  (0x1000U)
#define STCU_LBUFM_LBUFM44_SHIFT                 (12U)
#define STCU_LBUFM_LBUFM44_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM44(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM44_SHIFT)) & STCU_LBUFM_LBUFM44_MASK)

#define STCU_LBUFM_LBUFM45_MASK                  (0x2000U)
#define STCU_LBUFM_LBUFM45_SHIFT                 (13U)
#define STCU_LBUFM_LBUFM45_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM45(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM45_SHIFT)) & STCU_LBUFM_LBUFM45_MASK)

#define STCU_LBUFM_LBUFM46_MASK                  (0x4000U)
#define STCU_LBUFM_LBUFM46_SHIFT                 (14U)
#define STCU_LBUFM_LBUFM46_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM46(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM46_SHIFT)) & STCU_LBUFM_LBUFM46_MASK)

#define STCU_LBUFM_LBUFM47_MASK                  (0x8000U)
#define STCU_LBUFM_LBUFM47_SHIFT                 (15U)
#define STCU_LBUFM_LBUFM47_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM47(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM47_SHIFT)) & STCU_LBUFM_LBUFM47_MASK)

#define STCU_LBUFM_LBUFM48_MASK                  (0x10000U)
#define STCU_LBUFM_LBUFM48_SHIFT                 (16U)
#define STCU_LBUFM_LBUFM48_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM48(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM48_SHIFT)) & STCU_LBUFM_LBUFM48_MASK)

#define STCU_LBUFM_LBUFM49_MASK                  (0x20000U)
#define STCU_LBUFM_LBUFM49_SHIFT                 (17U)
#define STCU_LBUFM_LBUFM49_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM49(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM49_SHIFT)) & STCU_LBUFM_LBUFM49_MASK)

#define STCU_LBUFM_LBUFM50_MASK                  (0x40000U)
#define STCU_LBUFM_LBUFM50_SHIFT                 (18U)
#define STCU_LBUFM_LBUFM50_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM50(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM50_SHIFT)) & STCU_LBUFM_LBUFM50_MASK)

#define STCU_LBUFM_LBUFM51_MASK                  (0x80000U)
#define STCU_LBUFM_LBUFM51_SHIFT                 (19U)
#define STCU_LBUFM_LBUFM51_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM51(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM51_SHIFT)) & STCU_LBUFM_LBUFM51_MASK)

#define STCU_LBUFM_LBUFM52_MASK                  (0x100000U)
#define STCU_LBUFM_LBUFM52_SHIFT                 (20U)
#define STCU_LBUFM_LBUFM52_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM52(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM52_SHIFT)) & STCU_LBUFM_LBUFM52_MASK)

#define STCU_LBUFM_LBUFM53_MASK                  (0x200000U)
#define STCU_LBUFM_LBUFM53_SHIFT                 (21U)
#define STCU_LBUFM_LBUFM53_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM53(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM53_SHIFT)) & STCU_LBUFM_LBUFM53_MASK)

#define STCU_LBUFM_LBUFM54_MASK                  (0x400000U)
#define STCU_LBUFM_LBUFM54_SHIFT                 (22U)
#define STCU_LBUFM_LBUFM54_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM54(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM54_SHIFT)) & STCU_LBUFM_LBUFM54_MASK)

#define STCU_LBUFM_LBUFM55_MASK                  (0x800000U)
#define STCU_LBUFM_LBUFM55_SHIFT                 (23U)
#define STCU_LBUFM_LBUFM55_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM55(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM55_SHIFT)) & STCU_LBUFM_LBUFM55_MASK)

#define STCU_LBUFM_LBUFM56_MASK                  (0x1000000U)
#define STCU_LBUFM_LBUFM56_SHIFT                 (24U)
#define STCU_LBUFM_LBUFM56_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM56(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM56_SHIFT)) & STCU_LBUFM_LBUFM56_MASK)

#define STCU_LBUFM_LBUFM57_MASK                  (0x2000000U)
#define STCU_LBUFM_LBUFM57_SHIFT                 (25U)
#define STCU_LBUFM_LBUFM57_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM57(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM57_SHIFT)) & STCU_LBUFM_LBUFM57_MASK)

#define STCU_LBUFM_LBUFM58_MASK                  (0x4000000U)
#define STCU_LBUFM_LBUFM58_SHIFT                 (26U)
#define STCU_LBUFM_LBUFM58_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM58(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM58_SHIFT)) & STCU_LBUFM_LBUFM58_MASK)

#define STCU_LBUFM_LBUFM59_MASK                  (0x8000000U)
#define STCU_LBUFM_LBUFM59_SHIFT                 (27U)
#define STCU_LBUFM_LBUFM59_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM59(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM59_SHIFT)) & STCU_LBUFM_LBUFM59_MASK)

#define STCU_LBUFM_LBUFM60_MASK                  (0x10000000U)
#define STCU_LBUFM_LBUFM60_SHIFT                 (28U)
#define STCU_LBUFM_LBUFM60_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM60(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM60_SHIFT)) & STCU_LBUFM_LBUFM60_MASK)

#define STCU_LBUFM_LBUFM61_MASK                  (0x20000000U)
#define STCU_LBUFM_LBUFM61_SHIFT                 (29U)
#define STCU_LBUFM_LBUFM61_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM61(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM61_SHIFT)) & STCU_LBUFM_LBUFM61_MASK)

#define STCU_LBUFM_LBUFM62_MASK                  (0x40000000U)
#define STCU_LBUFM_LBUFM62_SHIFT                 (30U)
#define STCU_LBUFM_LBUFM62_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM62(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM62_SHIFT)) & STCU_LBUFM_LBUFM62_MASK)

#define STCU_LBUFM_LBUFM63_MASK                  (0x80000000U)
#define STCU_LBUFM_LBUFM63_SHIFT                 (31U)
#define STCU_LBUFM_LBUFM63_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM63(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM63_SHIFT)) & STCU_LBUFM_LBUFM63_MASK)

#define STCU_LBUFM_LBUFM64_MASK                  (0x1U)
#define STCU_LBUFM_LBUFM64_SHIFT                 (0U)
#define STCU_LBUFM_LBUFM64_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM64(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM64_SHIFT)) & STCU_LBUFM_LBUFM64_MASK)

#define STCU_LBUFM_LBUFM65_MASK                  (0x2U)
#define STCU_LBUFM_LBUFM65_SHIFT                 (1U)
#define STCU_LBUFM_LBUFM65_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM65(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM65_SHIFT)) & STCU_LBUFM_LBUFM65_MASK)

#define STCU_LBUFM_LBUFM66_MASK                  (0x4U)
#define STCU_LBUFM_LBUFM66_SHIFT                 (2U)
#define STCU_LBUFM_LBUFM66_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM66(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM66_SHIFT)) & STCU_LBUFM_LBUFM66_MASK)

#define STCU_LBUFM_LBUFM67_MASK                  (0x8U)
#define STCU_LBUFM_LBUFM67_SHIFT                 (3U)
#define STCU_LBUFM_LBUFM67_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM67(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM67_SHIFT)) & STCU_LBUFM_LBUFM67_MASK)

#define STCU_LBUFM_LBUFM68_MASK                  (0x10U)
#define STCU_LBUFM_LBUFM68_SHIFT                 (4U)
#define STCU_LBUFM_LBUFM68_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM68(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM68_SHIFT)) & STCU_LBUFM_LBUFM68_MASK)

#define STCU_LBUFM_LBUFM69_MASK                  (0x20U)
#define STCU_LBUFM_LBUFM69_SHIFT                 (5U)
#define STCU_LBUFM_LBUFM69_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM69(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM69_SHIFT)) & STCU_LBUFM_LBUFM69_MASK)

#define STCU_LBUFM_LBUFM70_MASK                  (0x40U)
#define STCU_LBUFM_LBUFM70_SHIFT                 (6U)
#define STCU_LBUFM_LBUFM70_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM70(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM70_SHIFT)) & STCU_LBUFM_LBUFM70_MASK)

#define STCU_LBUFM_LBUFM71_MASK                  (0x80U)
#define STCU_LBUFM_LBUFM71_SHIFT                 (7U)
#define STCU_LBUFM_LBUFM71_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM71(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM71_SHIFT)) & STCU_LBUFM_LBUFM71_MASK)

#define STCU_LBUFM_LBUFM72_MASK                  (0x100U)
#define STCU_LBUFM_LBUFM72_SHIFT                 (8U)
#define STCU_LBUFM_LBUFM72_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM72(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM72_SHIFT)) & STCU_LBUFM_LBUFM72_MASK)

#define STCU_LBUFM_LBUFM73_MASK                  (0x200U)
#define STCU_LBUFM_LBUFM73_SHIFT                 (9U)
#define STCU_LBUFM_LBUFM73_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM73(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM73_SHIFT)) & STCU_LBUFM_LBUFM73_MASK)

#define STCU_LBUFM_LBUFM74_MASK                  (0x400U)
#define STCU_LBUFM_LBUFM74_SHIFT                 (10U)
#define STCU_LBUFM_LBUFM74_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM74(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM74_SHIFT)) & STCU_LBUFM_LBUFM74_MASK)

#define STCU_LBUFM_LBUFM75_MASK                  (0x800U)
#define STCU_LBUFM_LBUFM75_SHIFT                 (11U)
#define STCU_LBUFM_LBUFM75_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM75(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM75_SHIFT)) & STCU_LBUFM_LBUFM75_MASK)

#define STCU_LBUFM_LBUFM76_MASK                  (0x1000U)
#define STCU_LBUFM_LBUFM76_SHIFT                 (12U)
#define STCU_LBUFM_LBUFM76_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM76(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM76_SHIFT)) & STCU_LBUFM_LBUFM76_MASK)

#define STCU_LBUFM_LBUFM77_MASK                  (0x2000U)
#define STCU_LBUFM_LBUFM77_SHIFT                 (13U)
#define STCU_LBUFM_LBUFM77_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM77(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM77_SHIFT)) & STCU_LBUFM_LBUFM77_MASK)

#define STCU_LBUFM_LBUFM78_MASK                  (0x4000U)
#define STCU_LBUFM_LBUFM78_SHIFT                 (14U)
#define STCU_LBUFM_LBUFM78_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM78(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM78_SHIFT)) & STCU_LBUFM_LBUFM78_MASK)

#define STCU_LBUFM_LBUFM79_MASK                  (0x8000U)
#define STCU_LBUFM_LBUFM79_SHIFT                 (15U)
#define STCU_LBUFM_LBUFM79_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM79(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM79_SHIFT)) & STCU_LBUFM_LBUFM79_MASK)

#define STCU_LBUFM_LBUFM80_MASK                  (0x10000U)
#define STCU_LBUFM_LBUFM80_SHIFT                 (16U)
#define STCU_LBUFM_LBUFM80_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM80(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM80_SHIFT)) & STCU_LBUFM_LBUFM80_MASK)

#define STCU_LBUFM_LBUFM81_MASK                  (0x20000U)
#define STCU_LBUFM_LBUFM81_SHIFT                 (17U)
#define STCU_LBUFM_LBUFM81_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM81(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM81_SHIFT)) & STCU_LBUFM_LBUFM81_MASK)

#define STCU_LBUFM_LBUFM82_MASK                  (0x40000U)
#define STCU_LBUFM_LBUFM82_SHIFT                 (18U)
#define STCU_LBUFM_LBUFM82_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM82(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM82_SHIFT)) & STCU_LBUFM_LBUFM82_MASK)

#define STCU_LBUFM_LBUFM83_MASK                  (0x80000U)
#define STCU_LBUFM_LBUFM83_SHIFT                 (19U)
#define STCU_LBUFM_LBUFM83_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM83(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM83_SHIFT)) & STCU_LBUFM_LBUFM83_MASK)

#define STCU_LBUFM_LBUFM84_MASK                  (0x100000U)
#define STCU_LBUFM_LBUFM84_SHIFT                 (20U)
#define STCU_LBUFM_LBUFM84_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM84(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM84_SHIFT)) & STCU_LBUFM_LBUFM84_MASK)

#define STCU_LBUFM_LBUFM85_MASK                  (0x200000U)
#define STCU_LBUFM_LBUFM85_SHIFT                 (21U)
#define STCU_LBUFM_LBUFM85_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM85(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM85_SHIFT)) & STCU_LBUFM_LBUFM85_MASK)

#define STCU_LBUFM_LBUFM86_MASK                  (0x400000U)
#define STCU_LBUFM_LBUFM86_SHIFT                 (22U)
#define STCU_LBUFM_LBUFM86_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM86(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM86_SHIFT)) & STCU_LBUFM_LBUFM86_MASK)

#define STCU_LBUFM_LBUFM87_MASK                  (0x800000U)
#define STCU_LBUFM_LBUFM87_SHIFT                 (23U)
#define STCU_LBUFM_LBUFM87_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM87(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM87_SHIFT)) & STCU_LBUFM_LBUFM87_MASK)

#define STCU_LBUFM_LBUFM88_MASK                  (0x1000000U)
#define STCU_LBUFM_LBUFM88_SHIFT                 (24U)
#define STCU_LBUFM_LBUFM88_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM88(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM88_SHIFT)) & STCU_LBUFM_LBUFM88_MASK)

#define STCU_LBUFM_LBUFM89_MASK                  (0x2000000U)
#define STCU_LBUFM_LBUFM89_SHIFT                 (25U)
#define STCU_LBUFM_LBUFM89_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM89(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM89_SHIFT)) & STCU_LBUFM_LBUFM89_MASK)

#define STCU_LBUFM_LBUFM90_MASK                  (0x4000000U)
#define STCU_LBUFM_LBUFM90_SHIFT                 (26U)
#define STCU_LBUFM_LBUFM90_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM90(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM90_SHIFT)) & STCU_LBUFM_LBUFM90_MASK)

#define STCU_LBUFM_LBUFM91_MASK                  (0x8000000U)
#define STCU_LBUFM_LBUFM91_SHIFT                 (27U)
#define STCU_LBUFM_LBUFM91_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM91(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM91_SHIFT)) & STCU_LBUFM_LBUFM91_MASK)

#define STCU_LBUFM_LBUFM92_MASK                  (0x10000000U)
#define STCU_LBUFM_LBUFM92_SHIFT                 (28U)
#define STCU_LBUFM_LBUFM92_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM92(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM92_SHIFT)) & STCU_LBUFM_LBUFM92_MASK)

#define STCU_LBUFM_LBUFM93_MASK                  (0x20000000U)
#define STCU_LBUFM_LBUFM93_SHIFT                 (29U)
#define STCU_LBUFM_LBUFM93_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM93(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM93_SHIFT)) & STCU_LBUFM_LBUFM93_MASK)

#define STCU_LBUFM_LBUFM94_MASK                  (0x40000000U)
#define STCU_LBUFM_LBUFM94_SHIFT                 (30U)
#define STCU_LBUFM_LBUFM94_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM94(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM94_SHIFT)) & STCU_LBUFM_LBUFM94_MASK)

#define STCU_LBUFM_LBUFM95_MASK                  (0x80000000U)
#define STCU_LBUFM_LBUFM95_SHIFT                 (31U)
#define STCU_LBUFM_LBUFM95_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM95(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM95_SHIFT)) & STCU_LBUFM_LBUFM95_MASK)

#define STCU_LBUFM_LBUFM96_MASK                  (0x1U)
#define STCU_LBUFM_LBUFM96_SHIFT                 (0U)
#define STCU_LBUFM_LBUFM96_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM96(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM96_SHIFT)) & STCU_LBUFM_LBUFM96_MASK)

#define STCU_LBUFM_LBUFM97_MASK                  (0x2U)
#define STCU_LBUFM_LBUFM97_SHIFT                 (1U)
#define STCU_LBUFM_LBUFM97_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM97(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM97_SHIFT)) & STCU_LBUFM_LBUFM97_MASK)

#define STCU_LBUFM_LBUFM98_MASK                  (0x4U)
#define STCU_LBUFM_LBUFM98_SHIFT                 (2U)
#define STCU_LBUFM_LBUFM98_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM98(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM98_SHIFT)) & STCU_LBUFM_LBUFM98_MASK)

#define STCU_LBUFM_LBUFM99_MASK                  (0x8U)
#define STCU_LBUFM_LBUFM99_SHIFT                 (3U)
#define STCU_LBUFM_LBUFM99_WIDTH                 (1U)
#define STCU_LBUFM_LBUFM99(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM99_SHIFT)) & STCU_LBUFM_LBUFM99_MASK)

#define STCU_LBUFM_LBUFM100_MASK                 (0x10U)
#define STCU_LBUFM_LBUFM100_SHIFT                (4U)
#define STCU_LBUFM_LBUFM100_WIDTH                (1U)
#define STCU_LBUFM_LBUFM100(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM100_SHIFT)) & STCU_LBUFM_LBUFM100_MASK)

#define STCU_LBUFM_LBUFM101_MASK                 (0x20U)
#define STCU_LBUFM_LBUFM101_SHIFT                (5U)
#define STCU_LBUFM_LBUFM101_WIDTH                (1U)
#define STCU_LBUFM_LBUFM101(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM101_SHIFT)) & STCU_LBUFM_LBUFM101_MASK)

#define STCU_LBUFM_LBUFM102_MASK                 (0x40U)
#define STCU_LBUFM_LBUFM102_SHIFT                (6U)
#define STCU_LBUFM_LBUFM102_WIDTH                (1U)
#define STCU_LBUFM_LBUFM102(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM102_SHIFT)) & STCU_LBUFM_LBUFM102_MASK)

#define STCU_LBUFM_LBUFM103_MASK                 (0x80U)
#define STCU_LBUFM_LBUFM103_SHIFT                (7U)
#define STCU_LBUFM_LBUFM103_WIDTH                (1U)
#define STCU_LBUFM_LBUFM103(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM103_SHIFT)) & STCU_LBUFM_LBUFM103_MASK)

#define STCU_LBUFM_LBUFM104_MASK                 (0x100U)
#define STCU_LBUFM_LBUFM104_SHIFT                (8U)
#define STCU_LBUFM_LBUFM104_WIDTH                (1U)
#define STCU_LBUFM_LBUFM104(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM104_SHIFT)) & STCU_LBUFM_LBUFM104_MASK)

#define STCU_LBUFM_LBUFM105_MASK                 (0x200U)
#define STCU_LBUFM_LBUFM105_SHIFT                (9U)
#define STCU_LBUFM_LBUFM105_WIDTH                (1U)
#define STCU_LBUFM_LBUFM105(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM105_SHIFT)) & STCU_LBUFM_LBUFM105_MASK)

#define STCU_LBUFM_LBUFM106_MASK                 (0x400U)
#define STCU_LBUFM_LBUFM106_SHIFT                (10U)
#define STCU_LBUFM_LBUFM106_WIDTH                (1U)
#define STCU_LBUFM_LBUFM106(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM106_SHIFT)) & STCU_LBUFM_LBUFM106_MASK)

#define STCU_LBUFM_LBUFM107_MASK                 (0x800U)
#define STCU_LBUFM_LBUFM107_SHIFT                (11U)
#define STCU_LBUFM_LBUFM107_WIDTH                (1U)
#define STCU_LBUFM_LBUFM107(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM107_SHIFT)) & STCU_LBUFM_LBUFM107_MASK)

#define STCU_LBUFM_LBUFM108_MASK                 (0x1000U)
#define STCU_LBUFM_LBUFM108_SHIFT                (12U)
#define STCU_LBUFM_LBUFM108_WIDTH                (1U)
#define STCU_LBUFM_LBUFM108(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM108_SHIFT)) & STCU_LBUFM_LBUFM108_MASK)

#define STCU_LBUFM_LBUFM109_MASK                 (0x2000U)
#define STCU_LBUFM_LBUFM109_SHIFT                (13U)
#define STCU_LBUFM_LBUFM109_WIDTH                (1U)
#define STCU_LBUFM_LBUFM109(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM109_SHIFT)) & STCU_LBUFM_LBUFM109_MASK)

#define STCU_LBUFM_LBUFM110_MASK                 (0x4000U)
#define STCU_LBUFM_LBUFM110_SHIFT                (14U)
#define STCU_LBUFM_LBUFM110_WIDTH                (1U)
#define STCU_LBUFM_LBUFM110(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM110_SHIFT)) & STCU_LBUFM_LBUFM110_MASK)

#define STCU_LBUFM_LBUFM111_MASK                 (0x8000U)
#define STCU_LBUFM_LBUFM111_SHIFT                (15U)
#define STCU_LBUFM_LBUFM111_WIDTH                (1U)
#define STCU_LBUFM_LBUFM111(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM111_SHIFT)) & STCU_LBUFM_LBUFM111_MASK)

#define STCU_LBUFM_LBUFM112_MASK                 (0x10000U)
#define STCU_LBUFM_LBUFM112_SHIFT                (16U)
#define STCU_LBUFM_LBUFM112_WIDTH                (1U)
#define STCU_LBUFM_LBUFM112(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM112_SHIFT)) & STCU_LBUFM_LBUFM112_MASK)

#define STCU_LBUFM_LBUFM113_MASK                 (0x20000U)
#define STCU_LBUFM_LBUFM113_SHIFT                (17U)
#define STCU_LBUFM_LBUFM113_WIDTH                (1U)
#define STCU_LBUFM_LBUFM113(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM113_SHIFT)) & STCU_LBUFM_LBUFM113_MASK)

#define STCU_LBUFM_LBUFM114_MASK                 (0x40000U)
#define STCU_LBUFM_LBUFM114_SHIFT                (18U)
#define STCU_LBUFM_LBUFM114_WIDTH                (1U)
#define STCU_LBUFM_LBUFM114(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM114_SHIFT)) & STCU_LBUFM_LBUFM114_MASK)

#define STCU_LBUFM_LBUFM115_MASK                 (0x80000U)
#define STCU_LBUFM_LBUFM115_SHIFT                (19U)
#define STCU_LBUFM_LBUFM115_WIDTH                (1U)
#define STCU_LBUFM_LBUFM115(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM115_SHIFT)) & STCU_LBUFM_LBUFM115_MASK)

#define STCU_LBUFM_LBUFM116_MASK                 (0x100000U)
#define STCU_LBUFM_LBUFM116_SHIFT                (20U)
#define STCU_LBUFM_LBUFM116_WIDTH                (1U)
#define STCU_LBUFM_LBUFM116(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM116_SHIFT)) & STCU_LBUFM_LBUFM116_MASK)

#define STCU_LBUFM_LBUFM117_MASK                 (0x200000U)
#define STCU_LBUFM_LBUFM117_SHIFT                (21U)
#define STCU_LBUFM_LBUFM117_WIDTH                (1U)
#define STCU_LBUFM_LBUFM117(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM117_SHIFT)) & STCU_LBUFM_LBUFM117_MASK)

#define STCU_LBUFM_LBUFM118_MASK                 (0x400000U)
#define STCU_LBUFM_LBUFM118_SHIFT                (22U)
#define STCU_LBUFM_LBUFM118_WIDTH                (1U)
#define STCU_LBUFM_LBUFM118(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM118_SHIFT)) & STCU_LBUFM_LBUFM118_MASK)

#define STCU_LBUFM_LBUFM119_MASK                 (0x800000U)
#define STCU_LBUFM_LBUFM119_SHIFT                (23U)
#define STCU_LBUFM_LBUFM119_WIDTH                (1U)
#define STCU_LBUFM_LBUFM119(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM119_SHIFT)) & STCU_LBUFM_LBUFM119_MASK)

#define STCU_LBUFM_LBUFM120_MASK                 (0x1000000U)
#define STCU_LBUFM_LBUFM120_SHIFT                (24U)
#define STCU_LBUFM_LBUFM120_WIDTH                (1U)
#define STCU_LBUFM_LBUFM120(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM120_SHIFT)) & STCU_LBUFM_LBUFM120_MASK)

#define STCU_LBUFM_LBUFM121_MASK                 (0x2000000U)
#define STCU_LBUFM_LBUFM121_SHIFT                (25U)
#define STCU_LBUFM_LBUFM121_WIDTH                (1U)
#define STCU_LBUFM_LBUFM121(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM121_SHIFT)) & STCU_LBUFM_LBUFM121_MASK)

#define STCU_LBUFM_LBUFM122_MASK                 (0x4000000U)
#define STCU_LBUFM_LBUFM122_SHIFT                (26U)
#define STCU_LBUFM_LBUFM122_WIDTH                (1U)
#define STCU_LBUFM_LBUFM122(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM122_SHIFT)) & STCU_LBUFM_LBUFM122_MASK)

#define STCU_LBUFM_LBUFM123_MASK                 (0x8000000U)
#define STCU_LBUFM_LBUFM123_SHIFT                (27U)
#define STCU_LBUFM_LBUFM123_WIDTH                (1U)
#define STCU_LBUFM_LBUFM123(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM123_SHIFT)) & STCU_LBUFM_LBUFM123_MASK)

#define STCU_LBUFM_LBUFM124_MASK                 (0x10000000U)
#define STCU_LBUFM_LBUFM124_SHIFT                (28U)
#define STCU_LBUFM_LBUFM124_WIDTH                (1U)
#define STCU_LBUFM_LBUFM124(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM124_SHIFT)) & STCU_LBUFM_LBUFM124_MASK)

#define STCU_LBUFM_LBUFM125_MASK                 (0x20000000U)
#define STCU_LBUFM_LBUFM125_SHIFT                (29U)
#define STCU_LBUFM_LBUFM125_WIDTH                (1U)
#define STCU_LBUFM_LBUFM125(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM125_SHIFT)) & STCU_LBUFM_LBUFM125_MASK)

#define STCU_LBUFM_LBUFM126_MASK                 (0x40000000U)
#define STCU_LBUFM_LBUFM126_SHIFT                (30U)
#define STCU_LBUFM_LBUFM126_WIDTH                (1U)
#define STCU_LBUFM_LBUFM126(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM126_SHIFT)) & STCU_LBUFM_LBUFM126_MASK)

#define STCU_LBUFM_LBUFM127_MASK                 (0x80000000U)
#define STCU_LBUFM_LBUFM127_SHIFT                (31U)
#define STCU_LBUFM_LBUFM127_WIDTH                (1U)
#define STCU_LBUFM_LBUFM127(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM_LBUFM127_SHIFT)) & STCU_LBUFM_LBUFM127_MASK)
/*! @} */

/*! @name MBSSW - STCU2 Online MBIST Status */
/*! @{ */

#define STCU_MBSSW_MBSSW0_MASK                   (0x1U)
#define STCU_MBSSW_MBSSW0_SHIFT                  (0U)
#define STCU_MBSSW_MBSSW0_WIDTH                  (1U)
#define STCU_MBSSW_MBSSW0(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW0_SHIFT)) & STCU_MBSSW_MBSSW0_MASK)

#define STCU_MBSSW_MBSSW1_MASK                   (0x2U)
#define STCU_MBSSW_MBSSW1_SHIFT                  (1U)
#define STCU_MBSSW_MBSSW1_WIDTH                  (1U)
#define STCU_MBSSW_MBSSW1(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW1_SHIFT)) & STCU_MBSSW_MBSSW1_MASK)

#define STCU_MBSSW_MBSSW2_MASK                   (0x4U)
#define STCU_MBSSW_MBSSW2_SHIFT                  (2U)
#define STCU_MBSSW_MBSSW2_WIDTH                  (1U)
#define STCU_MBSSW_MBSSW2(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW2_SHIFT)) & STCU_MBSSW_MBSSW2_MASK)

#define STCU_MBSSW_MBSSW3_MASK                   (0x8U)
#define STCU_MBSSW_MBSSW3_SHIFT                  (3U)
#define STCU_MBSSW_MBSSW3_WIDTH                  (1U)
#define STCU_MBSSW_MBSSW3(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW3_SHIFT)) & STCU_MBSSW_MBSSW3_MASK)

#define STCU_MBSSW_MBSSW4_MASK                   (0x10U)
#define STCU_MBSSW_MBSSW4_SHIFT                  (4U)
#define STCU_MBSSW_MBSSW4_WIDTH                  (1U)
#define STCU_MBSSW_MBSSW4(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW4_SHIFT)) & STCU_MBSSW_MBSSW4_MASK)

#define STCU_MBSSW_MBSSW5_MASK                   (0x20U)
#define STCU_MBSSW_MBSSW5_SHIFT                  (5U)
#define STCU_MBSSW_MBSSW5_WIDTH                  (1U)
#define STCU_MBSSW_MBSSW5(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW5_SHIFT)) & STCU_MBSSW_MBSSW5_MASK)

#define STCU_MBSSW_MBSSW6_MASK                   (0x40U)
#define STCU_MBSSW_MBSSW6_SHIFT                  (6U)
#define STCU_MBSSW_MBSSW6_WIDTH                  (1U)
#define STCU_MBSSW_MBSSW6(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW6_SHIFT)) & STCU_MBSSW_MBSSW6_MASK)

#define STCU_MBSSW_MBSSW7_MASK                   (0x80U)
#define STCU_MBSSW_MBSSW7_SHIFT                  (7U)
#define STCU_MBSSW_MBSSW7_WIDTH                  (1U)
#define STCU_MBSSW_MBSSW7(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW7_SHIFT)) & STCU_MBSSW_MBSSW7_MASK)

#define STCU_MBSSW_MBSSW8_MASK                   (0x100U)
#define STCU_MBSSW_MBSSW8_SHIFT                  (8U)
#define STCU_MBSSW_MBSSW8_WIDTH                  (1U)
#define STCU_MBSSW_MBSSW8(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW8_SHIFT)) & STCU_MBSSW_MBSSW8_MASK)

#define STCU_MBSSW_MBSSW9_MASK                   (0x200U)
#define STCU_MBSSW_MBSSW9_SHIFT                  (9U)
#define STCU_MBSSW_MBSSW9_WIDTH                  (1U)
#define STCU_MBSSW_MBSSW9(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW9_SHIFT)) & STCU_MBSSW_MBSSW9_MASK)

#define STCU_MBSSW_MBSSW10_MASK                  (0x400U)
#define STCU_MBSSW_MBSSW10_SHIFT                 (10U)
#define STCU_MBSSW_MBSSW10_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW10(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW10_SHIFT)) & STCU_MBSSW_MBSSW10_MASK)

#define STCU_MBSSW_MBSSW11_MASK                  (0x800U)
#define STCU_MBSSW_MBSSW11_SHIFT                 (11U)
#define STCU_MBSSW_MBSSW11_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW11(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW11_SHIFT)) & STCU_MBSSW_MBSSW11_MASK)

#define STCU_MBSSW_MBSSW12_MASK                  (0x1000U)
#define STCU_MBSSW_MBSSW12_SHIFT                 (12U)
#define STCU_MBSSW_MBSSW12_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW12(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW12_SHIFT)) & STCU_MBSSW_MBSSW12_MASK)

#define STCU_MBSSW_MBSSW13_MASK                  (0x2000U)
#define STCU_MBSSW_MBSSW13_SHIFT                 (13U)
#define STCU_MBSSW_MBSSW13_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW13(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW13_SHIFT)) & STCU_MBSSW_MBSSW13_MASK)

#define STCU_MBSSW_MBSSW14_MASK                  (0x4000U)
#define STCU_MBSSW_MBSSW14_SHIFT                 (14U)
#define STCU_MBSSW_MBSSW14_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW14(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW14_SHIFT)) & STCU_MBSSW_MBSSW14_MASK)

#define STCU_MBSSW_MBSSW15_MASK                  (0x8000U)
#define STCU_MBSSW_MBSSW15_SHIFT                 (15U)
#define STCU_MBSSW_MBSSW15_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW15(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW15_SHIFT)) & STCU_MBSSW_MBSSW15_MASK)

#define STCU_MBSSW_MBSSW16_MASK                  (0x10000U)
#define STCU_MBSSW_MBSSW16_SHIFT                 (16U)
#define STCU_MBSSW_MBSSW16_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW16(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW16_SHIFT)) & STCU_MBSSW_MBSSW16_MASK)

#define STCU_MBSSW_MBSSW17_MASK                  (0x20000U)
#define STCU_MBSSW_MBSSW17_SHIFT                 (17U)
#define STCU_MBSSW_MBSSW17_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW17(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW17_SHIFT)) & STCU_MBSSW_MBSSW17_MASK)

#define STCU_MBSSW_MBSSW18_MASK                  (0x40000U)
#define STCU_MBSSW_MBSSW18_SHIFT                 (18U)
#define STCU_MBSSW_MBSSW18_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW18(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW18_SHIFT)) & STCU_MBSSW_MBSSW18_MASK)

#define STCU_MBSSW_MBSSW19_MASK                  (0x80000U)
#define STCU_MBSSW_MBSSW19_SHIFT                 (19U)
#define STCU_MBSSW_MBSSW19_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW19(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW19_SHIFT)) & STCU_MBSSW_MBSSW19_MASK)

#define STCU_MBSSW_MBSSW20_MASK                  (0x100000U)
#define STCU_MBSSW_MBSSW20_SHIFT                 (20U)
#define STCU_MBSSW_MBSSW20_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW20(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW20_SHIFT)) & STCU_MBSSW_MBSSW20_MASK)

#define STCU_MBSSW_MBSSW21_MASK                  (0x200000U)
#define STCU_MBSSW_MBSSW21_SHIFT                 (21U)
#define STCU_MBSSW_MBSSW21_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW21(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW21_SHIFT)) & STCU_MBSSW_MBSSW21_MASK)

#define STCU_MBSSW_MBSSW22_MASK                  (0x400000U)
#define STCU_MBSSW_MBSSW22_SHIFT                 (22U)
#define STCU_MBSSW_MBSSW22_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW22(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW22_SHIFT)) & STCU_MBSSW_MBSSW22_MASK)

#define STCU_MBSSW_MBSSW23_MASK                  (0x800000U)
#define STCU_MBSSW_MBSSW23_SHIFT                 (23U)
#define STCU_MBSSW_MBSSW23_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW23(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW23_SHIFT)) & STCU_MBSSW_MBSSW23_MASK)

#define STCU_MBSSW_MBSSW24_MASK                  (0x1000000U)
#define STCU_MBSSW_MBSSW24_SHIFT                 (24U)
#define STCU_MBSSW_MBSSW24_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW24(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW24_SHIFT)) & STCU_MBSSW_MBSSW24_MASK)

#define STCU_MBSSW_MBSSW25_MASK                  (0x2000000U)
#define STCU_MBSSW_MBSSW25_SHIFT                 (25U)
#define STCU_MBSSW_MBSSW25_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW25(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW25_SHIFT)) & STCU_MBSSW_MBSSW25_MASK)

#define STCU_MBSSW_MBSSW26_MASK                  (0x4000000U)
#define STCU_MBSSW_MBSSW26_SHIFT                 (26U)
#define STCU_MBSSW_MBSSW26_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW26(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW26_SHIFT)) & STCU_MBSSW_MBSSW26_MASK)

#define STCU_MBSSW_MBSSW27_MASK                  (0x8000000U)
#define STCU_MBSSW_MBSSW27_SHIFT                 (27U)
#define STCU_MBSSW_MBSSW27_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW27(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW27_SHIFT)) & STCU_MBSSW_MBSSW27_MASK)

#define STCU_MBSSW_MBSSW28_MASK                  (0x10000000U)
#define STCU_MBSSW_MBSSW28_SHIFT                 (28U)
#define STCU_MBSSW_MBSSW28_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW28(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW28_SHIFT)) & STCU_MBSSW_MBSSW28_MASK)

#define STCU_MBSSW_MBSSW29_MASK                  (0x20000000U)
#define STCU_MBSSW_MBSSW29_SHIFT                 (29U)
#define STCU_MBSSW_MBSSW29_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW29(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW29_SHIFT)) & STCU_MBSSW_MBSSW29_MASK)

#define STCU_MBSSW_MBSSW30_MASK                  (0x40000000U)
#define STCU_MBSSW_MBSSW30_SHIFT                 (30U)
#define STCU_MBSSW_MBSSW30_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW30(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW30_SHIFT)) & STCU_MBSSW_MBSSW30_MASK)

#define STCU_MBSSW_MBSSW31_MASK                  (0x80000000U)
#define STCU_MBSSW_MBSSW31_SHIFT                 (31U)
#define STCU_MBSSW_MBSSW31_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW31(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW31_SHIFT)) & STCU_MBSSW_MBSSW31_MASK)

#define STCU_MBSSW_MBSSW32_MASK                  (0x1U)
#define STCU_MBSSW_MBSSW32_SHIFT                 (0U)
#define STCU_MBSSW_MBSSW32_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW32(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW32_SHIFT)) & STCU_MBSSW_MBSSW32_MASK)

#define STCU_MBSSW_MBSSW33_MASK                  (0x2U)
#define STCU_MBSSW_MBSSW33_SHIFT                 (1U)
#define STCU_MBSSW_MBSSW33_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW33(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW33_SHIFT)) & STCU_MBSSW_MBSSW33_MASK)

#define STCU_MBSSW_MBSSW34_MASK                  (0x4U)
#define STCU_MBSSW_MBSSW34_SHIFT                 (2U)
#define STCU_MBSSW_MBSSW34_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW34(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW34_SHIFT)) & STCU_MBSSW_MBSSW34_MASK)

#define STCU_MBSSW_MBSSW35_MASK                  (0x8U)
#define STCU_MBSSW_MBSSW35_SHIFT                 (3U)
#define STCU_MBSSW_MBSSW35_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW35(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW35_SHIFT)) & STCU_MBSSW_MBSSW35_MASK)

#define STCU_MBSSW_MBSSW36_MASK                  (0x10U)
#define STCU_MBSSW_MBSSW36_SHIFT                 (4U)
#define STCU_MBSSW_MBSSW36_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW36(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW36_SHIFT)) & STCU_MBSSW_MBSSW36_MASK)

#define STCU_MBSSW_MBSSW37_MASK                  (0x20U)
#define STCU_MBSSW_MBSSW37_SHIFT                 (5U)
#define STCU_MBSSW_MBSSW37_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW37(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW37_SHIFT)) & STCU_MBSSW_MBSSW37_MASK)

#define STCU_MBSSW_MBSSW38_MASK                  (0x40U)
#define STCU_MBSSW_MBSSW38_SHIFT                 (6U)
#define STCU_MBSSW_MBSSW38_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW38(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW38_SHIFT)) & STCU_MBSSW_MBSSW38_MASK)

#define STCU_MBSSW_MBSSW39_MASK                  (0x80U)
#define STCU_MBSSW_MBSSW39_SHIFT                 (7U)
#define STCU_MBSSW_MBSSW39_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW39(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW39_SHIFT)) & STCU_MBSSW_MBSSW39_MASK)

#define STCU_MBSSW_MBSSW40_MASK                  (0x100U)
#define STCU_MBSSW_MBSSW40_SHIFT                 (8U)
#define STCU_MBSSW_MBSSW40_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW40(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW40_SHIFT)) & STCU_MBSSW_MBSSW40_MASK)

#define STCU_MBSSW_MBSSW41_MASK                  (0x200U)
#define STCU_MBSSW_MBSSW41_SHIFT                 (9U)
#define STCU_MBSSW_MBSSW41_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW41(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW41_SHIFT)) & STCU_MBSSW_MBSSW41_MASK)

#define STCU_MBSSW_MBSSW42_MASK                  (0x400U)
#define STCU_MBSSW_MBSSW42_SHIFT                 (10U)
#define STCU_MBSSW_MBSSW42_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW42(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW42_SHIFT)) & STCU_MBSSW_MBSSW42_MASK)

#define STCU_MBSSW_MBSSW43_MASK                  (0x800U)
#define STCU_MBSSW_MBSSW43_SHIFT                 (11U)
#define STCU_MBSSW_MBSSW43_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW43(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW43_SHIFT)) & STCU_MBSSW_MBSSW43_MASK)

#define STCU_MBSSW_MBSSW44_MASK                  (0x1000U)
#define STCU_MBSSW_MBSSW44_SHIFT                 (12U)
#define STCU_MBSSW_MBSSW44_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW44(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW44_SHIFT)) & STCU_MBSSW_MBSSW44_MASK)

#define STCU_MBSSW_MBSSW45_MASK                  (0x2000U)
#define STCU_MBSSW_MBSSW45_SHIFT                 (13U)
#define STCU_MBSSW_MBSSW45_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW45(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW45_SHIFT)) & STCU_MBSSW_MBSSW45_MASK)

#define STCU_MBSSW_MBSSW46_MASK                  (0x4000U)
#define STCU_MBSSW_MBSSW46_SHIFT                 (14U)
#define STCU_MBSSW_MBSSW46_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW46(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW46_SHIFT)) & STCU_MBSSW_MBSSW46_MASK)

#define STCU_MBSSW_MBSSW47_MASK                  (0x8000U)
#define STCU_MBSSW_MBSSW47_SHIFT                 (15U)
#define STCU_MBSSW_MBSSW47_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW47(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW47_SHIFT)) & STCU_MBSSW_MBSSW47_MASK)

#define STCU_MBSSW_MBSSW48_MASK                  (0x10000U)
#define STCU_MBSSW_MBSSW48_SHIFT                 (16U)
#define STCU_MBSSW_MBSSW48_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW48(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW48_SHIFT)) & STCU_MBSSW_MBSSW48_MASK)

#define STCU_MBSSW_MBSSW49_MASK                  (0x20000U)
#define STCU_MBSSW_MBSSW49_SHIFT                 (17U)
#define STCU_MBSSW_MBSSW49_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW49(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW49_SHIFT)) & STCU_MBSSW_MBSSW49_MASK)

#define STCU_MBSSW_MBSSW50_MASK                  (0x40000U)
#define STCU_MBSSW_MBSSW50_SHIFT                 (18U)
#define STCU_MBSSW_MBSSW50_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW50(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW50_SHIFT)) & STCU_MBSSW_MBSSW50_MASK)

#define STCU_MBSSW_MBSSW51_MASK                  (0x80000U)
#define STCU_MBSSW_MBSSW51_SHIFT                 (19U)
#define STCU_MBSSW_MBSSW51_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW51(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW51_SHIFT)) & STCU_MBSSW_MBSSW51_MASK)

#define STCU_MBSSW_MBSSW52_MASK                  (0x100000U)
#define STCU_MBSSW_MBSSW52_SHIFT                 (20U)
#define STCU_MBSSW_MBSSW52_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW52(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW52_SHIFT)) & STCU_MBSSW_MBSSW52_MASK)

#define STCU_MBSSW_MBSSW53_MASK                  (0x200000U)
#define STCU_MBSSW_MBSSW53_SHIFT                 (21U)
#define STCU_MBSSW_MBSSW53_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW53(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW53_SHIFT)) & STCU_MBSSW_MBSSW53_MASK)

#define STCU_MBSSW_MBSSW54_MASK                  (0x400000U)
#define STCU_MBSSW_MBSSW54_SHIFT                 (22U)
#define STCU_MBSSW_MBSSW54_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW54(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW54_SHIFT)) & STCU_MBSSW_MBSSW54_MASK)

#define STCU_MBSSW_MBSSW55_MASK                  (0x800000U)
#define STCU_MBSSW_MBSSW55_SHIFT                 (23U)
#define STCU_MBSSW_MBSSW55_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW55(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW55_SHIFT)) & STCU_MBSSW_MBSSW55_MASK)

#define STCU_MBSSW_MBSSW56_MASK                  (0x1000000U)
#define STCU_MBSSW_MBSSW56_SHIFT                 (24U)
#define STCU_MBSSW_MBSSW56_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW56(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW56_SHIFT)) & STCU_MBSSW_MBSSW56_MASK)

#define STCU_MBSSW_MBSSW57_MASK                  (0x2000000U)
#define STCU_MBSSW_MBSSW57_SHIFT                 (25U)
#define STCU_MBSSW_MBSSW57_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW57(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW57_SHIFT)) & STCU_MBSSW_MBSSW57_MASK)

#define STCU_MBSSW_MBSSW58_MASK                  (0x4000000U)
#define STCU_MBSSW_MBSSW58_SHIFT                 (26U)
#define STCU_MBSSW_MBSSW58_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW58(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW58_SHIFT)) & STCU_MBSSW_MBSSW58_MASK)

#define STCU_MBSSW_MBSSW59_MASK                  (0x8000000U)
#define STCU_MBSSW_MBSSW59_SHIFT                 (27U)
#define STCU_MBSSW_MBSSW59_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW59(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW59_SHIFT)) & STCU_MBSSW_MBSSW59_MASK)

#define STCU_MBSSW_MBSSW60_MASK                  (0x10000000U)
#define STCU_MBSSW_MBSSW60_SHIFT                 (28U)
#define STCU_MBSSW_MBSSW60_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW60(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW60_SHIFT)) & STCU_MBSSW_MBSSW60_MASK)

#define STCU_MBSSW_MBSSW61_MASK                  (0x20000000U)
#define STCU_MBSSW_MBSSW61_SHIFT                 (29U)
#define STCU_MBSSW_MBSSW61_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW61(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW61_SHIFT)) & STCU_MBSSW_MBSSW61_MASK)

#define STCU_MBSSW_MBSSW62_MASK                  (0x40000000U)
#define STCU_MBSSW_MBSSW62_SHIFT                 (30U)
#define STCU_MBSSW_MBSSW62_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW62(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW62_SHIFT)) & STCU_MBSSW_MBSSW62_MASK)

#define STCU_MBSSW_MBSSW63_MASK                  (0x80000000U)
#define STCU_MBSSW_MBSSW63_SHIFT                 (31U)
#define STCU_MBSSW_MBSSW63_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW63(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW63_SHIFT)) & STCU_MBSSW_MBSSW63_MASK)

#define STCU_MBSSW_MBSSW64_MASK                  (0x1U)
#define STCU_MBSSW_MBSSW64_SHIFT                 (0U)
#define STCU_MBSSW_MBSSW64_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW64(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW64_SHIFT)) & STCU_MBSSW_MBSSW64_MASK)

#define STCU_MBSSW_MBSSW65_MASK                  (0x2U)
#define STCU_MBSSW_MBSSW65_SHIFT                 (1U)
#define STCU_MBSSW_MBSSW65_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW65(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW65_SHIFT)) & STCU_MBSSW_MBSSW65_MASK)

#define STCU_MBSSW_MBSSW66_MASK                  (0x4U)
#define STCU_MBSSW_MBSSW66_SHIFT                 (2U)
#define STCU_MBSSW_MBSSW66_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW66(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW66_SHIFT)) & STCU_MBSSW_MBSSW66_MASK)

#define STCU_MBSSW_MBSSW67_MASK                  (0x8U)
#define STCU_MBSSW_MBSSW67_SHIFT                 (3U)
#define STCU_MBSSW_MBSSW67_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW67(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW67_SHIFT)) & STCU_MBSSW_MBSSW67_MASK)

#define STCU_MBSSW_MBSSW68_MASK                  (0x10U)
#define STCU_MBSSW_MBSSW68_SHIFT                 (4U)
#define STCU_MBSSW_MBSSW68_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW68(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW68_SHIFT)) & STCU_MBSSW_MBSSW68_MASK)

#define STCU_MBSSW_MBSSW69_MASK                  (0x20U)
#define STCU_MBSSW_MBSSW69_SHIFT                 (5U)
#define STCU_MBSSW_MBSSW69_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW69(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW69_SHIFT)) & STCU_MBSSW_MBSSW69_MASK)

#define STCU_MBSSW_MBSSW70_MASK                  (0x40U)
#define STCU_MBSSW_MBSSW70_SHIFT                 (6U)
#define STCU_MBSSW_MBSSW70_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW70(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW70_SHIFT)) & STCU_MBSSW_MBSSW70_MASK)

#define STCU_MBSSW_MBSSW71_MASK                  (0x80U)
#define STCU_MBSSW_MBSSW71_SHIFT                 (7U)
#define STCU_MBSSW_MBSSW71_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW71(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW71_SHIFT)) & STCU_MBSSW_MBSSW71_MASK)

#define STCU_MBSSW_MBSSW72_MASK                  (0x100U)
#define STCU_MBSSW_MBSSW72_SHIFT                 (8U)
#define STCU_MBSSW_MBSSW72_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW72(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW72_SHIFT)) & STCU_MBSSW_MBSSW72_MASK)

#define STCU_MBSSW_MBSSW73_MASK                  (0x200U)
#define STCU_MBSSW_MBSSW73_SHIFT                 (9U)
#define STCU_MBSSW_MBSSW73_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW73(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW73_SHIFT)) & STCU_MBSSW_MBSSW73_MASK)

#define STCU_MBSSW_MBSSW74_MASK                  (0x400U)
#define STCU_MBSSW_MBSSW74_SHIFT                 (10U)
#define STCU_MBSSW_MBSSW74_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW74(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW74_SHIFT)) & STCU_MBSSW_MBSSW74_MASK)

#define STCU_MBSSW_MBSSW75_MASK                  (0x800U)
#define STCU_MBSSW_MBSSW75_SHIFT                 (11U)
#define STCU_MBSSW_MBSSW75_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW75(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW75_SHIFT)) & STCU_MBSSW_MBSSW75_MASK)

#define STCU_MBSSW_MBSSW76_MASK                  (0x1000U)
#define STCU_MBSSW_MBSSW76_SHIFT                 (12U)
#define STCU_MBSSW_MBSSW76_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW76(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW76_SHIFT)) & STCU_MBSSW_MBSSW76_MASK)

#define STCU_MBSSW_MBSSW77_MASK                  (0x2000U)
#define STCU_MBSSW_MBSSW77_SHIFT                 (13U)
#define STCU_MBSSW_MBSSW77_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW77(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW77_SHIFT)) & STCU_MBSSW_MBSSW77_MASK)

#define STCU_MBSSW_MBSSW78_MASK                  (0x4000U)
#define STCU_MBSSW_MBSSW78_SHIFT                 (14U)
#define STCU_MBSSW_MBSSW78_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW78(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW78_SHIFT)) & STCU_MBSSW_MBSSW78_MASK)

#define STCU_MBSSW_MBSSW79_MASK                  (0x8000U)
#define STCU_MBSSW_MBSSW79_SHIFT                 (15U)
#define STCU_MBSSW_MBSSW79_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW79(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW79_SHIFT)) & STCU_MBSSW_MBSSW79_MASK)

#define STCU_MBSSW_MBSSW80_MASK                  (0x10000U)
#define STCU_MBSSW_MBSSW80_SHIFT                 (16U)
#define STCU_MBSSW_MBSSW80_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW80(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW80_SHIFT)) & STCU_MBSSW_MBSSW80_MASK)

#define STCU_MBSSW_MBSSW81_MASK                  (0x20000U)
#define STCU_MBSSW_MBSSW81_SHIFT                 (17U)
#define STCU_MBSSW_MBSSW81_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW81(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW81_SHIFT)) & STCU_MBSSW_MBSSW81_MASK)

#define STCU_MBSSW_MBSSW82_MASK                  (0x40000U)
#define STCU_MBSSW_MBSSW82_SHIFT                 (18U)
#define STCU_MBSSW_MBSSW82_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW82(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW82_SHIFT)) & STCU_MBSSW_MBSSW82_MASK)

#define STCU_MBSSW_MBSSW83_MASK                  (0x80000U)
#define STCU_MBSSW_MBSSW83_SHIFT                 (19U)
#define STCU_MBSSW_MBSSW83_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW83(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW83_SHIFT)) & STCU_MBSSW_MBSSW83_MASK)

#define STCU_MBSSW_MBSSW84_MASK                  (0x100000U)
#define STCU_MBSSW_MBSSW84_SHIFT                 (20U)
#define STCU_MBSSW_MBSSW84_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW84(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW84_SHIFT)) & STCU_MBSSW_MBSSW84_MASK)

#define STCU_MBSSW_MBSSW85_MASK                  (0x200000U)
#define STCU_MBSSW_MBSSW85_SHIFT                 (21U)
#define STCU_MBSSW_MBSSW85_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW85(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW85_SHIFT)) & STCU_MBSSW_MBSSW85_MASK)

#define STCU_MBSSW_MBSSW86_MASK                  (0x400000U)
#define STCU_MBSSW_MBSSW86_SHIFT                 (22U)
#define STCU_MBSSW_MBSSW86_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW86(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW86_SHIFT)) & STCU_MBSSW_MBSSW86_MASK)

#define STCU_MBSSW_MBSSW87_MASK                  (0x800000U)
#define STCU_MBSSW_MBSSW87_SHIFT                 (23U)
#define STCU_MBSSW_MBSSW87_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW87(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW87_SHIFT)) & STCU_MBSSW_MBSSW87_MASK)

#define STCU_MBSSW_MBSSW88_MASK                  (0x1000000U)
#define STCU_MBSSW_MBSSW88_SHIFT                 (24U)
#define STCU_MBSSW_MBSSW88_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW88(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW88_SHIFT)) & STCU_MBSSW_MBSSW88_MASK)

#define STCU_MBSSW_MBSSW89_MASK                  (0x2000000U)
#define STCU_MBSSW_MBSSW89_SHIFT                 (25U)
#define STCU_MBSSW_MBSSW89_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW89(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW89_SHIFT)) & STCU_MBSSW_MBSSW89_MASK)

#define STCU_MBSSW_MBSSW90_MASK                  (0x4000000U)
#define STCU_MBSSW_MBSSW90_SHIFT                 (26U)
#define STCU_MBSSW_MBSSW90_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW90(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW90_SHIFT)) & STCU_MBSSW_MBSSW90_MASK)

#define STCU_MBSSW_MBSSW91_MASK                  (0x8000000U)
#define STCU_MBSSW_MBSSW91_SHIFT                 (27U)
#define STCU_MBSSW_MBSSW91_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW91(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW91_SHIFT)) & STCU_MBSSW_MBSSW91_MASK)

#define STCU_MBSSW_MBSSW92_MASK                  (0x10000000U)
#define STCU_MBSSW_MBSSW92_SHIFT                 (28U)
#define STCU_MBSSW_MBSSW92_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW92(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW92_SHIFT)) & STCU_MBSSW_MBSSW92_MASK)

#define STCU_MBSSW_MBSSW93_MASK                  (0x20000000U)
#define STCU_MBSSW_MBSSW93_SHIFT                 (29U)
#define STCU_MBSSW_MBSSW93_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW93(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW93_SHIFT)) & STCU_MBSSW_MBSSW93_MASK)

#define STCU_MBSSW_MBSSW94_MASK                  (0x40000000U)
#define STCU_MBSSW_MBSSW94_SHIFT                 (30U)
#define STCU_MBSSW_MBSSW94_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW94(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW94_SHIFT)) & STCU_MBSSW_MBSSW94_MASK)

#define STCU_MBSSW_MBSSW95_MASK                  (0x80000000U)
#define STCU_MBSSW_MBSSW95_SHIFT                 (31U)
#define STCU_MBSSW_MBSSW95_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW95(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW95_SHIFT)) & STCU_MBSSW_MBSSW95_MASK)

#define STCU_MBSSW_MBSSW96_MASK                  (0x1U)
#define STCU_MBSSW_MBSSW96_SHIFT                 (0U)
#define STCU_MBSSW_MBSSW96_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW96(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW96_SHIFT)) & STCU_MBSSW_MBSSW96_MASK)

#define STCU_MBSSW_MBSSW97_MASK                  (0x2U)
#define STCU_MBSSW_MBSSW97_SHIFT                 (1U)
#define STCU_MBSSW_MBSSW97_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW97(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW97_SHIFT)) & STCU_MBSSW_MBSSW97_MASK)

#define STCU_MBSSW_MBSSW98_MASK                  (0x4U)
#define STCU_MBSSW_MBSSW98_SHIFT                 (2U)
#define STCU_MBSSW_MBSSW98_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW98(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW98_SHIFT)) & STCU_MBSSW_MBSSW98_MASK)

#define STCU_MBSSW_MBSSW99_MASK                  (0x8U)
#define STCU_MBSSW_MBSSW99_SHIFT                 (3U)
#define STCU_MBSSW_MBSSW99_WIDTH                 (1U)
#define STCU_MBSSW_MBSSW99(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW99_SHIFT)) & STCU_MBSSW_MBSSW99_MASK)

#define STCU_MBSSW_MBSSW100_MASK                 (0x10U)
#define STCU_MBSSW_MBSSW100_SHIFT                (4U)
#define STCU_MBSSW_MBSSW100_WIDTH                (1U)
#define STCU_MBSSW_MBSSW100(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW100_SHIFT)) & STCU_MBSSW_MBSSW100_MASK)

#define STCU_MBSSW_MBSSW101_MASK                 (0x20U)
#define STCU_MBSSW_MBSSW101_SHIFT                (5U)
#define STCU_MBSSW_MBSSW101_WIDTH                (1U)
#define STCU_MBSSW_MBSSW101(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW101_SHIFT)) & STCU_MBSSW_MBSSW101_MASK)

#define STCU_MBSSW_MBSSW102_MASK                 (0x40U)
#define STCU_MBSSW_MBSSW102_SHIFT                (6U)
#define STCU_MBSSW_MBSSW102_WIDTH                (1U)
#define STCU_MBSSW_MBSSW102(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW102_SHIFT)) & STCU_MBSSW_MBSSW102_MASK)

#define STCU_MBSSW_MBSSW103_MASK                 (0x80U)
#define STCU_MBSSW_MBSSW103_SHIFT                (7U)
#define STCU_MBSSW_MBSSW103_WIDTH                (1U)
#define STCU_MBSSW_MBSSW103(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW103_SHIFT)) & STCU_MBSSW_MBSSW103_MASK)

#define STCU_MBSSW_MBSSW104_MASK                 (0x100U)
#define STCU_MBSSW_MBSSW104_SHIFT                (8U)
#define STCU_MBSSW_MBSSW104_WIDTH                (1U)
#define STCU_MBSSW_MBSSW104(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW104_SHIFT)) & STCU_MBSSW_MBSSW104_MASK)

#define STCU_MBSSW_MBSSW105_MASK                 (0x200U)
#define STCU_MBSSW_MBSSW105_SHIFT                (9U)
#define STCU_MBSSW_MBSSW105_WIDTH                (1U)
#define STCU_MBSSW_MBSSW105(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW105_SHIFT)) & STCU_MBSSW_MBSSW105_MASK)

#define STCU_MBSSW_MBSSW106_MASK                 (0x400U)
#define STCU_MBSSW_MBSSW106_SHIFT                (10U)
#define STCU_MBSSW_MBSSW106_WIDTH                (1U)
#define STCU_MBSSW_MBSSW106(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW106_SHIFT)) & STCU_MBSSW_MBSSW106_MASK)

#define STCU_MBSSW_MBSSW107_MASK                 (0x800U)
#define STCU_MBSSW_MBSSW107_SHIFT                (11U)
#define STCU_MBSSW_MBSSW107_WIDTH                (1U)
#define STCU_MBSSW_MBSSW107(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW107_SHIFT)) & STCU_MBSSW_MBSSW107_MASK)

#define STCU_MBSSW_MBSSW108_MASK                 (0x1000U)
#define STCU_MBSSW_MBSSW108_SHIFT                (12U)
#define STCU_MBSSW_MBSSW108_WIDTH                (1U)
#define STCU_MBSSW_MBSSW108(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW108_SHIFT)) & STCU_MBSSW_MBSSW108_MASK)

#define STCU_MBSSW_MBSSW109_MASK                 (0x2000U)
#define STCU_MBSSW_MBSSW109_SHIFT                (13U)
#define STCU_MBSSW_MBSSW109_WIDTH                (1U)
#define STCU_MBSSW_MBSSW109(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW109_SHIFT)) & STCU_MBSSW_MBSSW109_MASK)

#define STCU_MBSSW_MBSSW110_MASK                 (0x4000U)
#define STCU_MBSSW_MBSSW110_SHIFT                (14U)
#define STCU_MBSSW_MBSSW110_WIDTH                (1U)
#define STCU_MBSSW_MBSSW110(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW110_SHIFT)) & STCU_MBSSW_MBSSW110_MASK)

#define STCU_MBSSW_MBSSW111_MASK                 (0x8000U)
#define STCU_MBSSW_MBSSW111_SHIFT                (15U)
#define STCU_MBSSW_MBSSW111_WIDTH                (1U)
#define STCU_MBSSW_MBSSW111(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW111_SHIFT)) & STCU_MBSSW_MBSSW111_MASK)

#define STCU_MBSSW_MBSSW112_MASK                 (0x10000U)
#define STCU_MBSSW_MBSSW112_SHIFT                (16U)
#define STCU_MBSSW_MBSSW112_WIDTH                (1U)
#define STCU_MBSSW_MBSSW112(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW112_SHIFT)) & STCU_MBSSW_MBSSW112_MASK)

#define STCU_MBSSW_MBSSW113_MASK                 (0x20000U)
#define STCU_MBSSW_MBSSW113_SHIFT                (17U)
#define STCU_MBSSW_MBSSW113_WIDTH                (1U)
#define STCU_MBSSW_MBSSW113(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW113_SHIFT)) & STCU_MBSSW_MBSSW113_MASK)

#define STCU_MBSSW_MBSSW114_MASK                 (0x40000U)
#define STCU_MBSSW_MBSSW114_SHIFT                (18U)
#define STCU_MBSSW_MBSSW114_WIDTH                (1U)
#define STCU_MBSSW_MBSSW114(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW114_SHIFT)) & STCU_MBSSW_MBSSW114_MASK)

#define STCU_MBSSW_MBSSW115_MASK                 (0x80000U)
#define STCU_MBSSW_MBSSW115_SHIFT                (19U)
#define STCU_MBSSW_MBSSW115_WIDTH                (1U)
#define STCU_MBSSW_MBSSW115(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW115_SHIFT)) & STCU_MBSSW_MBSSW115_MASK)

#define STCU_MBSSW_MBSSW116_MASK                 (0x100000U)
#define STCU_MBSSW_MBSSW116_SHIFT                (20U)
#define STCU_MBSSW_MBSSW116_WIDTH                (1U)
#define STCU_MBSSW_MBSSW116(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW116_SHIFT)) & STCU_MBSSW_MBSSW116_MASK)

#define STCU_MBSSW_MBSSW117_MASK                 (0x200000U)
#define STCU_MBSSW_MBSSW117_SHIFT                (21U)
#define STCU_MBSSW_MBSSW117_WIDTH                (1U)
#define STCU_MBSSW_MBSSW117(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW117_SHIFT)) & STCU_MBSSW_MBSSW117_MASK)

#define STCU_MBSSW_MBSSW118_MASK                 (0x400000U)
#define STCU_MBSSW_MBSSW118_SHIFT                (22U)
#define STCU_MBSSW_MBSSW118_WIDTH                (1U)
#define STCU_MBSSW_MBSSW118(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW118_SHIFT)) & STCU_MBSSW_MBSSW118_MASK)

#define STCU_MBSSW_MBSSW119_MASK                 (0x800000U)
#define STCU_MBSSW_MBSSW119_SHIFT                (23U)
#define STCU_MBSSW_MBSSW119_WIDTH                (1U)
#define STCU_MBSSW_MBSSW119(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW119_SHIFT)) & STCU_MBSSW_MBSSW119_MASK)

#define STCU_MBSSW_MBSSW120_MASK                 (0x1000000U)
#define STCU_MBSSW_MBSSW120_SHIFT                (24U)
#define STCU_MBSSW_MBSSW120_WIDTH                (1U)
#define STCU_MBSSW_MBSSW120(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW120_SHIFT)) & STCU_MBSSW_MBSSW120_MASK)

#define STCU_MBSSW_MBSSW121_MASK                 (0x2000000U)
#define STCU_MBSSW_MBSSW121_SHIFT                (25U)
#define STCU_MBSSW_MBSSW121_WIDTH                (1U)
#define STCU_MBSSW_MBSSW121(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW121_SHIFT)) & STCU_MBSSW_MBSSW121_MASK)

#define STCU_MBSSW_MBSSW122_MASK                 (0x4000000U)
#define STCU_MBSSW_MBSSW122_SHIFT                (26U)
#define STCU_MBSSW_MBSSW122_WIDTH                (1U)
#define STCU_MBSSW_MBSSW122(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW122_SHIFT)) & STCU_MBSSW_MBSSW122_MASK)

#define STCU_MBSSW_MBSSW123_MASK                 (0x8000000U)
#define STCU_MBSSW_MBSSW123_SHIFT                (27U)
#define STCU_MBSSW_MBSSW123_WIDTH                (1U)
#define STCU_MBSSW_MBSSW123(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW123_SHIFT)) & STCU_MBSSW_MBSSW123_MASK)

#define STCU_MBSSW_MBSSW124_MASK                 (0x10000000U)
#define STCU_MBSSW_MBSSW124_SHIFT                (28U)
#define STCU_MBSSW_MBSSW124_WIDTH                (1U)
#define STCU_MBSSW_MBSSW124(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW124_SHIFT)) & STCU_MBSSW_MBSSW124_MASK)

#define STCU_MBSSW_MBSSW125_MASK                 (0x20000000U)
#define STCU_MBSSW_MBSSW125_SHIFT                (29U)
#define STCU_MBSSW_MBSSW125_WIDTH                (1U)
#define STCU_MBSSW_MBSSW125(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW125_SHIFT)) & STCU_MBSSW_MBSSW125_MASK)

#define STCU_MBSSW_MBSSW126_MASK                 (0x40000000U)
#define STCU_MBSSW_MBSSW126_SHIFT                (30U)
#define STCU_MBSSW_MBSSW126_WIDTH                (1U)
#define STCU_MBSSW_MBSSW126(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW126_SHIFT)) & STCU_MBSSW_MBSSW126_MASK)

#define STCU_MBSSW_MBSSW127_MASK                 (0x80000000U)
#define STCU_MBSSW_MBSSW127_SHIFT                (31U)
#define STCU_MBSSW_MBSSW127_WIDTH                (1U)
#define STCU_MBSSW_MBSSW127(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW127_SHIFT)) & STCU_MBSSW_MBSSW127_MASK)

#define STCU_MBSSW_MBSSW128_MASK                 (0x1U)
#define STCU_MBSSW_MBSSW128_SHIFT                (0U)
#define STCU_MBSSW_MBSSW128_WIDTH                (1U)
#define STCU_MBSSW_MBSSW128(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW128_SHIFT)) & STCU_MBSSW_MBSSW128_MASK)

#define STCU_MBSSW_MBSSW129_MASK                 (0x2U)
#define STCU_MBSSW_MBSSW129_SHIFT                (1U)
#define STCU_MBSSW_MBSSW129_WIDTH                (1U)
#define STCU_MBSSW_MBSSW129(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW129_SHIFT)) & STCU_MBSSW_MBSSW129_MASK)

#define STCU_MBSSW_MBSSW130_MASK                 (0x4U)
#define STCU_MBSSW_MBSSW130_SHIFT                (2U)
#define STCU_MBSSW_MBSSW130_WIDTH                (1U)
#define STCU_MBSSW_MBSSW130(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW130_SHIFT)) & STCU_MBSSW_MBSSW130_MASK)

#define STCU_MBSSW_MBSSW131_MASK                 (0x8U)
#define STCU_MBSSW_MBSSW131_SHIFT                (3U)
#define STCU_MBSSW_MBSSW131_WIDTH                (1U)
#define STCU_MBSSW_MBSSW131(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW131_SHIFT)) & STCU_MBSSW_MBSSW131_MASK)

#define STCU_MBSSW_MBSSW132_MASK                 (0x10U)
#define STCU_MBSSW_MBSSW132_SHIFT                (4U)
#define STCU_MBSSW_MBSSW132_WIDTH                (1U)
#define STCU_MBSSW_MBSSW132(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW132_SHIFT)) & STCU_MBSSW_MBSSW132_MASK)

#define STCU_MBSSW_MBSSW133_MASK                 (0x20U)
#define STCU_MBSSW_MBSSW133_SHIFT                (5U)
#define STCU_MBSSW_MBSSW133_WIDTH                (1U)
#define STCU_MBSSW_MBSSW133(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW133_SHIFT)) & STCU_MBSSW_MBSSW133_MASK)

#define STCU_MBSSW_MBSSW134_MASK                 (0x40U)
#define STCU_MBSSW_MBSSW134_SHIFT                (6U)
#define STCU_MBSSW_MBSSW134_WIDTH                (1U)
#define STCU_MBSSW_MBSSW134(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW134_SHIFT)) & STCU_MBSSW_MBSSW134_MASK)

#define STCU_MBSSW_MBSSW135_MASK                 (0x80U)
#define STCU_MBSSW_MBSSW135_SHIFT                (7U)
#define STCU_MBSSW_MBSSW135_WIDTH                (1U)
#define STCU_MBSSW_MBSSW135(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW135_SHIFT)) & STCU_MBSSW_MBSSW135_MASK)

#define STCU_MBSSW_MBSSW136_MASK                 (0x100U)
#define STCU_MBSSW_MBSSW136_SHIFT                (8U)
#define STCU_MBSSW_MBSSW136_WIDTH                (1U)
#define STCU_MBSSW_MBSSW136(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW136_SHIFT)) & STCU_MBSSW_MBSSW136_MASK)

#define STCU_MBSSW_MBSSW137_MASK                 (0x200U)
#define STCU_MBSSW_MBSSW137_SHIFT                (9U)
#define STCU_MBSSW_MBSSW137_WIDTH                (1U)
#define STCU_MBSSW_MBSSW137(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW137_SHIFT)) & STCU_MBSSW_MBSSW137_MASK)

#define STCU_MBSSW_MBSSW138_MASK                 (0x400U)
#define STCU_MBSSW_MBSSW138_SHIFT                (10U)
#define STCU_MBSSW_MBSSW138_WIDTH                (1U)
#define STCU_MBSSW_MBSSW138(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW138_SHIFT)) & STCU_MBSSW_MBSSW138_MASK)

#define STCU_MBSSW_MBSSW139_MASK                 (0x800U)
#define STCU_MBSSW_MBSSW139_SHIFT                (11U)
#define STCU_MBSSW_MBSSW139_WIDTH                (1U)
#define STCU_MBSSW_MBSSW139(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW139_SHIFT)) & STCU_MBSSW_MBSSW139_MASK)

#define STCU_MBSSW_MBSSW140_MASK                 (0x1000U)
#define STCU_MBSSW_MBSSW140_SHIFT                (12U)
#define STCU_MBSSW_MBSSW140_WIDTH                (1U)
#define STCU_MBSSW_MBSSW140(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW140_SHIFT)) & STCU_MBSSW_MBSSW140_MASK)

#define STCU_MBSSW_MBSSW141_MASK                 (0x2000U)
#define STCU_MBSSW_MBSSW141_SHIFT                (13U)
#define STCU_MBSSW_MBSSW141_WIDTH                (1U)
#define STCU_MBSSW_MBSSW141(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW141_SHIFT)) & STCU_MBSSW_MBSSW141_MASK)

#define STCU_MBSSW_MBSSW142_MASK                 (0x4000U)
#define STCU_MBSSW_MBSSW142_SHIFT                (14U)
#define STCU_MBSSW_MBSSW142_WIDTH                (1U)
#define STCU_MBSSW_MBSSW142(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW142_SHIFT)) & STCU_MBSSW_MBSSW142_MASK)

#define STCU_MBSSW_MBSSW143_MASK                 (0x8000U)
#define STCU_MBSSW_MBSSW143_SHIFT                (15U)
#define STCU_MBSSW_MBSSW143_WIDTH                (1U)
#define STCU_MBSSW_MBSSW143(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW143_SHIFT)) & STCU_MBSSW_MBSSW143_MASK)

#define STCU_MBSSW_MBSSW144_MASK                 (0x10000U)
#define STCU_MBSSW_MBSSW144_SHIFT                (16U)
#define STCU_MBSSW_MBSSW144_WIDTH                (1U)
#define STCU_MBSSW_MBSSW144(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW144_SHIFT)) & STCU_MBSSW_MBSSW144_MASK)

#define STCU_MBSSW_MBSSW145_MASK                 (0x20000U)
#define STCU_MBSSW_MBSSW145_SHIFT                (17U)
#define STCU_MBSSW_MBSSW145_WIDTH                (1U)
#define STCU_MBSSW_MBSSW145(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW145_SHIFT)) & STCU_MBSSW_MBSSW145_MASK)

#define STCU_MBSSW_MBSSW146_MASK                 (0x40000U)
#define STCU_MBSSW_MBSSW146_SHIFT                (18U)
#define STCU_MBSSW_MBSSW146_WIDTH                (1U)
#define STCU_MBSSW_MBSSW146(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW146_SHIFT)) & STCU_MBSSW_MBSSW146_MASK)

#define STCU_MBSSW_MBSSW147_MASK                 (0x80000U)
#define STCU_MBSSW_MBSSW147_SHIFT                (19U)
#define STCU_MBSSW_MBSSW147_WIDTH                (1U)
#define STCU_MBSSW_MBSSW147(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW147_SHIFT)) & STCU_MBSSW_MBSSW147_MASK)

#define STCU_MBSSW_MBSSW148_MASK                 (0x100000U)
#define STCU_MBSSW_MBSSW148_SHIFT                (20U)
#define STCU_MBSSW_MBSSW148_WIDTH                (1U)
#define STCU_MBSSW_MBSSW148(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW148_SHIFT)) & STCU_MBSSW_MBSSW148_MASK)

#define STCU_MBSSW_MBSSW149_MASK                 (0x200000U)
#define STCU_MBSSW_MBSSW149_SHIFT                (21U)
#define STCU_MBSSW_MBSSW149_WIDTH                (1U)
#define STCU_MBSSW_MBSSW149(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW149_SHIFT)) & STCU_MBSSW_MBSSW149_MASK)

#define STCU_MBSSW_MBSSW150_MASK                 (0x400000U)
#define STCU_MBSSW_MBSSW150_SHIFT                (22U)
#define STCU_MBSSW_MBSSW150_WIDTH                (1U)
#define STCU_MBSSW_MBSSW150(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW150_SHIFT)) & STCU_MBSSW_MBSSW150_MASK)

#define STCU_MBSSW_MBSSW151_MASK                 (0x800000U)
#define STCU_MBSSW_MBSSW151_SHIFT                (23U)
#define STCU_MBSSW_MBSSW151_WIDTH                (1U)
#define STCU_MBSSW_MBSSW151(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW151_SHIFT)) & STCU_MBSSW_MBSSW151_MASK)

#define STCU_MBSSW_MBSSW152_MASK                 (0x1000000U)
#define STCU_MBSSW_MBSSW152_SHIFT                (24U)
#define STCU_MBSSW_MBSSW152_WIDTH                (1U)
#define STCU_MBSSW_MBSSW152(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW152_SHIFT)) & STCU_MBSSW_MBSSW152_MASK)

#define STCU_MBSSW_MBSSW153_MASK                 (0x2000000U)
#define STCU_MBSSW_MBSSW153_SHIFT                (25U)
#define STCU_MBSSW_MBSSW153_WIDTH                (1U)
#define STCU_MBSSW_MBSSW153(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW153_SHIFT)) & STCU_MBSSW_MBSSW153_MASK)

#define STCU_MBSSW_MBSSW154_MASK                 (0x4000000U)
#define STCU_MBSSW_MBSSW154_SHIFT                (26U)
#define STCU_MBSSW_MBSSW154_WIDTH                (1U)
#define STCU_MBSSW_MBSSW154(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW154_SHIFT)) & STCU_MBSSW_MBSSW154_MASK)

#define STCU_MBSSW_MBSSW155_MASK                 (0x8000000U)
#define STCU_MBSSW_MBSSW155_SHIFT                (27U)
#define STCU_MBSSW_MBSSW155_WIDTH                (1U)
#define STCU_MBSSW_MBSSW155(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW155_SHIFT)) & STCU_MBSSW_MBSSW155_MASK)

#define STCU_MBSSW_MBSSW156_MASK                 (0x10000000U)
#define STCU_MBSSW_MBSSW156_SHIFT                (28U)
#define STCU_MBSSW_MBSSW156_WIDTH                (1U)
#define STCU_MBSSW_MBSSW156(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW156_SHIFT)) & STCU_MBSSW_MBSSW156_MASK)

#define STCU_MBSSW_MBSSW157_MASK                 (0x20000000U)
#define STCU_MBSSW_MBSSW157_SHIFT                (29U)
#define STCU_MBSSW_MBSSW157_WIDTH                (1U)
#define STCU_MBSSW_MBSSW157(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW157_SHIFT)) & STCU_MBSSW_MBSSW157_MASK)

#define STCU_MBSSW_MBSSW158_MASK                 (0x40000000U)
#define STCU_MBSSW_MBSSW158_SHIFT                (30U)
#define STCU_MBSSW_MBSSW158_WIDTH                (1U)
#define STCU_MBSSW_MBSSW158(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW158_SHIFT)) & STCU_MBSSW_MBSSW158_MASK)

#define STCU_MBSSW_MBSSW159_MASK                 (0x80000000U)
#define STCU_MBSSW_MBSSW159_SHIFT                (31U)
#define STCU_MBSSW_MBSSW159_WIDTH                (1U)
#define STCU_MBSSW_MBSSW159(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW159_SHIFT)) & STCU_MBSSW_MBSSW159_MASK)

#define STCU_MBSSW_MBSSW160_MASK                 (0x1U)
#define STCU_MBSSW_MBSSW160_SHIFT                (0U)
#define STCU_MBSSW_MBSSW160_WIDTH                (1U)
#define STCU_MBSSW_MBSSW160(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW160_SHIFT)) & STCU_MBSSW_MBSSW160_MASK)

#define STCU_MBSSW_MBSSW161_MASK                 (0x2U)
#define STCU_MBSSW_MBSSW161_SHIFT                (1U)
#define STCU_MBSSW_MBSSW161_WIDTH                (1U)
#define STCU_MBSSW_MBSSW161(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW161_SHIFT)) & STCU_MBSSW_MBSSW161_MASK)

#define STCU_MBSSW_MBSSW162_MASK                 (0x4U)
#define STCU_MBSSW_MBSSW162_SHIFT                (2U)
#define STCU_MBSSW_MBSSW162_WIDTH                (1U)
#define STCU_MBSSW_MBSSW162(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW162_SHIFT)) & STCU_MBSSW_MBSSW162_MASK)

#define STCU_MBSSW_MBSSW163_MASK                 (0x8U)
#define STCU_MBSSW_MBSSW163_SHIFT                (3U)
#define STCU_MBSSW_MBSSW163_WIDTH                (1U)
#define STCU_MBSSW_MBSSW163(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW163_SHIFT)) & STCU_MBSSW_MBSSW163_MASK)

#define STCU_MBSSW_MBSSW164_MASK                 (0x10U)
#define STCU_MBSSW_MBSSW164_SHIFT                (4U)
#define STCU_MBSSW_MBSSW164_WIDTH                (1U)
#define STCU_MBSSW_MBSSW164(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW164_SHIFT)) & STCU_MBSSW_MBSSW164_MASK)

#define STCU_MBSSW_MBSSW165_MASK                 (0x20U)
#define STCU_MBSSW_MBSSW165_SHIFT                (5U)
#define STCU_MBSSW_MBSSW165_WIDTH                (1U)
#define STCU_MBSSW_MBSSW165(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW165_SHIFT)) & STCU_MBSSW_MBSSW165_MASK)

#define STCU_MBSSW_MBSSW166_MASK                 (0x40U)
#define STCU_MBSSW_MBSSW166_SHIFT                (6U)
#define STCU_MBSSW_MBSSW166_WIDTH                (1U)
#define STCU_MBSSW_MBSSW166(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW166_SHIFT)) & STCU_MBSSW_MBSSW166_MASK)

#define STCU_MBSSW_MBSSW167_MASK                 (0x80U)
#define STCU_MBSSW_MBSSW167_SHIFT                (7U)
#define STCU_MBSSW_MBSSW167_WIDTH                (1U)
#define STCU_MBSSW_MBSSW167(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW167_SHIFT)) & STCU_MBSSW_MBSSW167_MASK)

#define STCU_MBSSW_MBSSW168_MASK                 (0x100U)
#define STCU_MBSSW_MBSSW168_SHIFT                (8U)
#define STCU_MBSSW_MBSSW168_WIDTH                (1U)
#define STCU_MBSSW_MBSSW168(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW168_SHIFT)) & STCU_MBSSW_MBSSW168_MASK)

#define STCU_MBSSW_MBSSW169_MASK                 (0x200U)
#define STCU_MBSSW_MBSSW169_SHIFT                (9U)
#define STCU_MBSSW_MBSSW169_WIDTH                (1U)
#define STCU_MBSSW_MBSSW169(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW169_SHIFT)) & STCU_MBSSW_MBSSW169_MASK)

#define STCU_MBSSW_MBSSW170_MASK                 (0x400U)
#define STCU_MBSSW_MBSSW170_SHIFT                (10U)
#define STCU_MBSSW_MBSSW170_WIDTH                (1U)
#define STCU_MBSSW_MBSSW170(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW170_SHIFT)) & STCU_MBSSW_MBSSW170_MASK)

#define STCU_MBSSW_MBSSW171_MASK                 (0x800U)
#define STCU_MBSSW_MBSSW171_SHIFT                (11U)
#define STCU_MBSSW_MBSSW171_WIDTH                (1U)
#define STCU_MBSSW_MBSSW171(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW171_SHIFT)) & STCU_MBSSW_MBSSW171_MASK)

#define STCU_MBSSW_MBSSW172_MASK                 (0x1000U)
#define STCU_MBSSW_MBSSW172_SHIFT                (12U)
#define STCU_MBSSW_MBSSW172_WIDTH                (1U)
#define STCU_MBSSW_MBSSW172(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW172_SHIFT)) & STCU_MBSSW_MBSSW172_MASK)

#define STCU_MBSSW_MBSSW173_MASK                 (0x2000U)
#define STCU_MBSSW_MBSSW173_SHIFT                (13U)
#define STCU_MBSSW_MBSSW173_WIDTH                (1U)
#define STCU_MBSSW_MBSSW173(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW173_SHIFT)) & STCU_MBSSW_MBSSW173_MASK)

#define STCU_MBSSW_MBSSW174_MASK                 (0x4000U)
#define STCU_MBSSW_MBSSW174_SHIFT                (14U)
#define STCU_MBSSW_MBSSW174_WIDTH                (1U)
#define STCU_MBSSW_MBSSW174(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW174_SHIFT)) & STCU_MBSSW_MBSSW174_MASK)

#define STCU_MBSSW_MBSSW175_MASK                 (0x8000U)
#define STCU_MBSSW_MBSSW175_SHIFT                (15U)
#define STCU_MBSSW_MBSSW175_WIDTH                (1U)
#define STCU_MBSSW_MBSSW175(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW175_SHIFT)) & STCU_MBSSW_MBSSW175_MASK)

#define STCU_MBSSW_MBSSW176_MASK                 (0x10000U)
#define STCU_MBSSW_MBSSW176_SHIFT                (16U)
#define STCU_MBSSW_MBSSW176_WIDTH                (1U)
#define STCU_MBSSW_MBSSW176(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW176_SHIFT)) & STCU_MBSSW_MBSSW176_MASK)

#define STCU_MBSSW_MBSSW177_MASK                 (0x20000U)
#define STCU_MBSSW_MBSSW177_SHIFT                (17U)
#define STCU_MBSSW_MBSSW177_WIDTH                (1U)
#define STCU_MBSSW_MBSSW177(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW177_SHIFT)) & STCU_MBSSW_MBSSW177_MASK)

#define STCU_MBSSW_MBSSW178_MASK                 (0x40000U)
#define STCU_MBSSW_MBSSW178_SHIFT                (18U)
#define STCU_MBSSW_MBSSW178_WIDTH                (1U)
#define STCU_MBSSW_MBSSW178(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW178_SHIFT)) & STCU_MBSSW_MBSSW178_MASK)

#define STCU_MBSSW_MBSSW179_MASK                 (0x80000U)
#define STCU_MBSSW_MBSSW179_SHIFT                (19U)
#define STCU_MBSSW_MBSSW179_WIDTH                (1U)
#define STCU_MBSSW_MBSSW179(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW179_SHIFT)) & STCU_MBSSW_MBSSW179_MASK)

#define STCU_MBSSW_MBSSW180_MASK                 (0x100000U)
#define STCU_MBSSW_MBSSW180_SHIFT                (20U)
#define STCU_MBSSW_MBSSW180_WIDTH                (1U)
#define STCU_MBSSW_MBSSW180(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW180_SHIFT)) & STCU_MBSSW_MBSSW180_MASK)

#define STCU_MBSSW_MBSSW181_MASK                 (0x200000U)
#define STCU_MBSSW_MBSSW181_SHIFT                (21U)
#define STCU_MBSSW_MBSSW181_WIDTH                (1U)
#define STCU_MBSSW_MBSSW181(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW181_SHIFT)) & STCU_MBSSW_MBSSW181_MASK)

#define STCU_MBSSW_MBSSW182_MASK                 (0x400000U)
#define STCU_MBSSW_MBSSW182_SHIFT                (22U)
#define STCU_MBSSW_MBSSW182_WIDTH                (1U)
#define STCU_MBSSW_MBSSW182(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW182_SHIFT)) & STCU_MBSSW_MBSSW182_MASK)

#define STCU_MBSSW_MBSSW183_MASK                 (0x800000U)
#define STCU_MBSSW_MBSSW183_SHIFT                (23U)
#define STCU_MBSSW_MBSSW183_WIDTH                (1U)
#define STCU_MBSSW_MBSSW183(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW183_SHIFT)) & STCU_MBSSW_MBSSW183_MASK)

#define STCU_MBSSW_MBSSW184_MASK                 (0x1000000U)
#define STCU_MBSSW_MBSSW184_SHIFT                (24U)
#define STCU_MBSSW_MBSSW184_WIDTH                (1U)
#define STCU_MBSSW_MBSSW184(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW184_SHIFT)) & STCU_MBSSW_MBSSW184_MASK)

#define STCU_MBSSW_MBSSW185_MASK                 (0x2000000U)
#define STCU_MBSSW_MBSSW185_SHIFT                (25U)
#define STCU_MBSSW_MBSSW185_WIDTH                (1U)
#define STCU_MBSSW_MBSSW185(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW185_SHIFT)) & STCU_MBSSW_MBSSW185_MASK)

#define STCU_MBSSW_MBSSW186_MASK                 (0x4000000U)
#define STCU_MBSSW_MBSSW186_SHIFT                (26U)
#define STCU_MBSSW_MBSSW186_WIDTH                (1U)
#define STCU_MBSSW_MBSSW186(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW186_SHIFT)) & STCU_MBSSW_MBSSW186_MASK)

#define STCU_MBSSW_MBSSW187_MASK                 (0x8000000U)
#define STCU_MBSSW_MBSSW187_SHIFT                (27U)
#define STCU_MBSSW_MBSSW187_WIDTH                (1U)
#define STCU_MBSSW_MBSSW187(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW187_SHIFT)) & STCU_MBSSW_MBSSW187_MASK)

#define STCU_MBSSW_MBSSW188_MASK                 (0x10000000U)
#define STCU_MBSSW_MBSSW188_SHIFT                (28U)
#define STCU_MBSSW_MBSSW188_WIDTH                (1U)
#define STCU_MBSSW_MBSSW188(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW188_SHIFT)) & STCU_MBSSW_MBSSW188_MASK)

#define STCU_MBSSW_MBSSW189_MASK                 (0x20000000U)
#define STCU_MBSSW_MBSSW189_SHIFT                (29U)
#define STCU_MBSSW_MBSSW189_WIDTH                (1U)
#define STCU_MBSSW_MBSSW189(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW189_SHIFT)) & STCU_MBSSW_MBSSW189_MASK)

#define STCU_MBSSW_MBSSW190_MASK                 (0x40000000U)
#define STCU_MBSSW_MBSSW190_SHIFT                (30U)
#define STCU_MBSSW_MBSSW190_WIDTH                (1U)
#define STCU_MBSSW_MBSSW190(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW190_SHIFT)) & STCU_MBSSW_MBSSW190_MASK)

#define STCU_MBSSW_MBSSW191_MASK                 (0x80000000U)
#define STCU_MBSSW_MBSSW191_SHIFT                (31U)
#define STCU_MBSSW_MBSSW191_WIDTH                (1U)
#define STCU_MBSSW_MBSSW191(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW191_SHIFT)) & STCU_MBSSW_MBSSW191_MASK)

#define STCU_MBSSW_MBSSW192_MASK                 (0x1U)
#define STCU_MBSSW_MBSSW192_SHIFT                (0U)
#define STCU_MBSSW_MBSSW192_WIDTH                (1U)
#define STCU_MBSSW_MBSSW192(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW192_SHIFT)) & STCU_MBSSW_MBSSW192_MASK)

#define STCU_MBSSW_MBSSW193_MASK                 (0x2U)
#define STCU_MBSSW_MBSSW193_SHIFT                (1U)
#define STCU_MBSSW_MBSSW193_WIDTH                (1U)
#define STCU_MBSSW_MBSSW193(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW193_SHIFT)) & STCU_MBSSW_MBSSW193_MASK)

#define STCU_MBSSW_MBSSW194_MASK                 (0x4U)
#define STCU_MBSSW_MBSSW194_SHIFT                (2U)
#define STCU_MBSSW_MBSSW194_WIDTH                (1U)
#define STCU_MBSSW_MBSSW194(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW194_SHIFT)) & STCU_MBSSW_MBSSW194_MASK)

#define STCU_MBSSW_MBSSW195_MASK                 (0x8U)
#define STCU_MBSSW_MBSSW195_SHIFT                (3U)
#define STCU_MBSSW_MBSSW195_WIDTH                (1U)
#define STCU_MBSSW_MBSSW195(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW195_SHIFT)) & STCU_MBSSW_MBSSW195_MASK)

#define STCU_MBSSW_MBSSW196_MASK                 (0x10U)
#define STCU_MBSSW_MBSSW196_SHIFT                (4U)
#define STCU_MBSSW_MBSSW196_WIDTH                (1U)
#define STCU_MBSSW_MBSSW196(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW196_SHIFT)) & STCU_MBSSW_MBSSW196_MASK)

#define STCU_MBSSW_MBSSW197_MASK                 (0x20U)
#define STCU_MBSSW_MBSSW197_SHIFT                (5U)
#define STCU_MBSSW_MBSSW197_WIDTH                (1U)
#define STCU_MBSSW_MBSSW197(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW197_SHIFT)) & STCU_MBSSW_MBSSW197_MASK)

#define STCU_MBSSW_MBSSW198_MASK                 (0x40U)
#define STCU_MBSSW_MBSSW198_SHIFT                (6U)
#define STCU_MBSSW_MBSSW198_WIDTH                (1U)
#define STCU_MBSSW_MBSSW198(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW198_SHIFT)) & STCU_MBSSW_MBSSW198_MASK)

#define STCU_MBSSW_MBSSW199_MASK                 (0x80U)
#define STCU_MBSSW_MBSSW199_SHIFT                (7U)
#define STCU_MBSSW_MBSSW199_WIDTH                (1U)
#define STCU_MBSSW_MBSSW199(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW199_SHIFT)) & STCU_MBSSW_MBSSW199_MASK)

#define STCU_MBSSW_MBSSW200_MASK                 (0x100U)
#define STCU_MBSSW_MBSSW200_SHIFT                (8U)
#define STCU_MBSSW_MBSSW200_WIDTH                (1U)
#define STCU_MBSSW_MBSSW200(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW200_SHIFT)) & STCU_MBSSW_MBSSW200_MASK)

#define STCU_MBSSW_MBSSW201_MASK                 (0x200U)
#define STCU_MBSSW_MBSSW201_SHIFT                (9U)
#define STCU_MBSSW_MBSSW201_WIDTH                (1U)
#define STCU_MBSSW_MBSSW201(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW201_SHIFT)) & STCU_MBSSW_MBSSW201_MASK)

#define STCU_MBSSW_MBSSW202_MASK                 (0x400U)
#define STCU_MBSSW_MBSSW202_SHIFT                (10U)
#define STCU_MBSSW_MBSSW202_WIDTH                (1U)
#define STCU_MBSSW_MBSSW202(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW202_SHIFT)) & STCU_MBSSW_MBSSW202_MASK)

#define STCU_MBSSW_MBSSW203_MASK                 (0x800U)
#define STCU_MBSSW_MBSSW203_SHIFT                (11U)
#define STCU_MBSSW_MBSSW203_WIDTH                (1U)
#define STCU_MBSSW_MBSSW203(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW203_SHIFT)) & STCU_MBSSW_MBSSW203_MASK)

#define STCU_MBSSW_MBSSW204_MASK                 (0x1000U)
#define STCU_MBSSW_MBSSW204_SHIFT                (12U)
#define STCU_MBSSW_MBSSW204_WIDTH                (1U)
#define STCU_MBSSW_MBSSW204(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW204_SHIFT)) & STCU_MBSSW_MBSSW204_MASK)

#define STCU_MBSSW_MBSSW205_MASK                 (0x2000U)
#define STCU_MBSSW_MBSSW205_SHIFT                (13U)
#define STCU_MBSSW_MBSSW205_WIDTH                (1U)
#define STCU_MBSSW_MBSSW205(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW205_SHIFT)) & STCU_MBSSW_MBSSW205_MASK)

#define STCU_MBSSW_MBSSW206_MASK                 (0x4000U)
#define STCU_MBSSW_MBSSW206_SHIFT                (14U)
#define STCU_MBSSW_MBSSW206_WIDTH                (1U)
#define STCU_MBSSW_MBSSW206(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW206_SHIFT)) & STCU_MBSSW_MBSSW206_MASK)

#define STCU_MBSSW_MBSSW207_MASK                 (0x8000U)
#define STCU_MBSSW_MBSSW207_SHIFT                (15U)
#define STCU_MBSSW_MBSSW207_WIDTH                (1U)
#define STCU_MBSSW_MBSSW207(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW207_SHIFT)) & STCU_MBSSW_MBSSW207_MASK)

#define STCU_MBSSW_MBSSW208_MASK                 (0x10000U)
#define STCU_MBSSW_MBSSW208_SHIFT                (16U)
#define STCU_MBSSW_MBSSW208_WIDTH                (1U)
#define STCU_MBSSW_MBSSW208(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW208_SHIFT)) & STCU_MBSSW_MBSSW208_MASK)

#define STCU_MBSSW_MBSSW209_MASK                 (0x20000U)
#define STCU_MBSSW_MBSSW209_SHIFT                (17U)
#define STCU_MBSSW_MBSSW209_WIDTH                (1U)
#define STCU_MBSSW_MBSSW209(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW209_SHIFT)) & STCU_MBSSW_MBSSW209_MASK)

#define STCU_MBSSW_MBSSW210_MASK                 (0x40000U)
#define STCU_MBSSW_MBSSW210_SHIFT                (18U)
#define STCU_MBSSW_MBSSW210_WIDTH                (1U)
#define STCU_MBSSW_MBSSW210(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW210_SHIFT)) & STCU_MBSSW_MBSSW210_MASK)

#define STCU_MBSSW_MBSSW211_MASK                 (0x80000U)
#define STCU_MBSSW_MBSSW211_SHIFT                (19U)
#define STCU_MBSSW_MBSSW211_WIDTH                (1U)
#define STCU_MBSSW_MBSSW211(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW211_SHIFT)) & STCU_MBSSW_MBSSW211_MASK)

#define STCU_MBSSW_MBSSW212_MASK                 (0x100000U)
#define STCU_MBSSW_MBSSW212_SHIFT                (20U)
#define STCU_MBSSW_MBSSW212_WIDTH                (1U)
#define STCU_MBSSW_MBSSW212(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW212_SHIFT)) & STCU_MBSSW_MBSSW212_MASK)

#define STCU_MBSSW_MBSSW213_MASK                 (0x200000U)
#define STCU_MBSSW_MBSSW213_SHIFT                (21U)
#define STCU_MBSSW_MBSSW213_WIDTH                (1U)
#define STCU_MBSSW_MBSSW213(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW213_SHIFT)) & STCU_MBSSW_MBSSW213_MASK)

#define STCU_MBSSW_MBSSW214_MASK                 (0x400000U)
#define STCU_MBSSW_MBSSW214_SHIFT                (22U)
#define STCU_MBSSW_MBSSW214_WIDTH                (1U)
#define STCU_MBSSW_MBSSW214(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW214_SHIFT)) & STCU_MBSSW_MBSSW214_MASK)

#define STCU_MBSSW_MBSSW215_MASK                 (0x800000U)
#define STCU_MBSSW_MBSSW215_SHIFT                (23U)
#define STCU_MBSSW_MBSSW215_WIDTH                (1U)
#define STCU_MBSSW_MBSSW215(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW215_SHIFT)) & STCU_MBSSW_MBSSW215_MASK)

#define STCU_MBSSW_MBSSW216_MASK                 (0x1000000U)
#define STCU_MBSSW_MBSSW216_SHIFT                (24U)
#define STCU_MBSSW_MBSSW216_WIDTH                (1U)
#define STCU_MBSSW_MBSSW216(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW216_SHIFT)) & STCU_MBSSW_MBSSW216_MASK)

#define STCU_MBSSW_MBSSW217_MASK                 (0x2000000U)
#define STCU_MBSSW_MBSSW217_SHIFT                (25U)
#define STCU_MBSSW_MBSSW217_WIDTH                (1U)
#define STCU_MBSSW_MBSSW217(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW217_SHIFT)) & STCU_MBSSW_MBSSW217_MASK)

#define STCU_MBSSW_MBSSW218_MASK                 (0x4000000U)
#define STCU_MBSSW_MBSSW218_SHIFT                (26U)
#define STCU_MBSSW_MBSSW218_WIDTH                (1U)
#define STCU_MBSSW_MBSSW218(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW218_SHIFT)) & STCU_MBSSW_MBSSW218_MASK)

#define STCU_MBSSW_MBSSW219_MASK                 (0x8000000U)
#define STCU_MBSSW_MBSSW219_SHIFT                (27U)
#define STCU_MBSSW_MBSSW219_WIDTH                (1U)
#define STCU_MBSSW_MBSSW219(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW219_SHIFT)) & STCU_MBSSW_MBSSW219_MASK)

#define STCU_MBSSW_MBSSW220_MASK                 (0x10000000U)
#define STCU_MBSSW_MBSSW220_SHIFT                (28U)
#define STCU_MBSSW_MBSSW220_WIDTH                (1U)
#define STCU_MBSSW_MBSSW220(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW220_SHIFT)) & STCU_MBSSW_MBSSW220_MASK)

#define STCU_MBSSW_MBSSW221_MASK                 (0x20000000U)
#define STCU_MBSSW_MBSSW221_SHIFT                (29U)
#define STCU_MBSSW_MBSSW221_WIDTH                (1U)
#define STCU_MBSSW_MBSSW221(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW221_SHIFT)) & STCU_MBSSW_MBSSW221_MASK)

#define STCU_MBSSW_MBSSW222_MASK                 (0x40000000U)
#define STCU_MBSSW_MBSSW222_SHIFT                (30U)
#define STCU_MBSSW_MBSSW222_WIDTH                (1U)
#define STCU_MBSSW_MBSSW222(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW222_SHIFT)) & STCU_MBSSW_MBSSW222_MASK)

#define STCU_MBSSW_MBSSW223_MASK                 (0x80000000U)
#define STCU_MBSSW_MBSSW223_SHIFT                (31U)
#define STCU_MBSSW_MBSSW223_WIDTH                (1U)
#define STCU_MBSSW_MBSSW223(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW223_SHIFT)) & STCU_MBSSW_MBSSW223_MASK)

#define STCU_MBSSW_MBSSW224_MASK                 (0x1U)
#define STCU_MBSSW_MBSSW224_SHIFT                (0U)
#define STCU_MBSSW_MBSSW224_WIDTH                (1U)
#define STCU_MBSSW_MBSSW224(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW224_SHIFT)) & STCU_MBSSW_MBSSW224_MASK)

#define STCU_MBSSW_MBSSW225_MASK                 (0x2U)
#define STCU_MBSSW_MBSSW225_SHIFT                (1U)
#define STCU_MBSSW_MBSSW225_WIDTH                (1U)
#define STCU_MBSSW_MBSSW225(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW225_SHIFT)) & STCU_MBSSW_MBSSW225_MASK)

#define STCU_MBSSW_MBSSW226_MASK                 (0x4U)
#define STCU_MBSSW_MBSSW226_SHIFT                (2U)
#define STCU_MBSSW_MBSSW226_WIDTH                (1U)
#define STCU_MBSSW_MBSSW226(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW226_SHIFT)) & STCU_MBSSW_MBSSW226_MASK)

#define STCU_MBSSW_MBSSW227_MASK                 (0x8U)
#define STCU_MBSSW_MBSSW227_SHIFT                (3U)
#define STCU_MBSSW_MBSSW227_WIDTH                (1U)
#define STCU_MBSSW_MBSSW227(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW227_SHIFT)) & STCU_MBSSW_MBSSW227_MASK)

#define STCU_MBSSW_MBSSW228_MASK                 (0x10U)
#define STCU_MBSSW_MBSSW228_SHIFT                (4U)
#define STCU_MBSSW_MBSSW228_WIDTH                (1U)
#define STCU_MBSSW_MBSSW228(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW228_SHIFT)) & STCU_MBSSW_MBSSW228_MASK)

#define STCU_MBSSW_MBSSW229_MASK                 (0x20U)
#define STCU_MBSSW_MBSSW229_SHIFT                (5U)
#define STCU_MBSSW_MBSSW229_WIDTH                (1U)
#define STCU_MBSSW_MBSSW229(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW229_SHIFT)) & STCU_MBSSW_MBSSW229_MASK)

#define STCU_MBSSW_MBSSW230_MASK                 (0x40U)
#define STCU_MBSSW_MBSSW230_SHIFT                (6U)
#define STCU_MBSSW_MBSSW230_WIDTH                (1U)
#define STCU_MBSSW_MBSSW230(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW230_SHIFT)) & STCU_MBSSW_MBSSW230_MASK)

#define STCU_MBSSW_MBSSW231_MASK                 (0x80U)
#define STCU_MBSSW_MBSSW231_SHIFT                (7U)
#define STCU_MBSSW_MBSSW231_WIDTH                (1U)
#define STCU_MBSSW_MBSSW231(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW231_SHIFT)) & STCU_MBSSW_MBSSW231_MASK)

#define STCU_MBSSW_MBSSW232_MASK                 (0x100U)
#define STCU_MBSSW_MBSSW232_SHIFT                (8U)
#define STCU_MBSSW_MBSSW232_WIDTH                (1U)
#define STCU_MBSSW_MBSSW232(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW232_SHIFT)) & STCU_MBSSW_MBSSW232_MASK)

#define STCU_MBSSW_MBSSW233_MASK                 (0x200U)
#define STCU_MBSSW_MBSSW233_SHIFT                (9U)
#define STCU_MBSSW_MBSSW233_WIDTH                (1U)
#define STCU_MBSSW_MBSSW233(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW233_SHIFT)) & STCU_MBSSW_MBSSW233_MASK)

#define STCU_MBSSW_MBSSW234_MASK                 (0x400U)
#define STCU_MBSSW_MBSSW234_SHIFT                (10U)
#define STCU_MBSSW_MBSSW234_WIDTH                (1U)
#define STCU_MBSSW_MBSSW234(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW234_SHIFT)) & STCU_MBSSW_MBSSW234_MASK)

#define STCU_MBSSW_MBSSW235_MASK                 (0x800U)
#define STCU_MBSSW_MBSSW235_SHIFT                (11U)
#define STCU_MBSSW_MBSSW235_WIDTH                (1U)
#define STCU_MBSSW_MBSSW235(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW235_SHIFT)) & STCU_MBSSW_MBSSW235_MASK)

#define STCU_MBSSW_MBSSW236_MASK                 (0x1000U)
#define STCU_MBSSW_MBSSW236_SHIFT                (12U)
#define STCU_MBSSW_MBSSW236_WIDTH                (1U)
#define STCU_MBSSW_MBSSW236(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW236_SHIFT)) & STCU_MBSSW_MBSSW236_MASK)

#define STCU_MBSSW_MBSSW237_MASK                 (0x2000U)
#define STCU_MBSSW_MBSSW237_SHIFT                (13U)
#define STCU_MBSSW_MBSSW237_WIDTH                (1U)
#define STCU_MBSSW_MBSSW237(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW237_SHIFT)) & STCU_MBSSW_MBSSW237_MASK)

#define STCU_MBSSW_MBSSW238_MASK                 (0x4000U)
#define STCU_MBSSW_MBSSW238_SHIFT                (14U)
#define STCU_MBSSW_MBSSW238_WIDTH                (1U)
#define STCU_MBSSW_MBSSW238(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW238_SHIFT)) & STCU_MBSSW_MBSSW238_MASK)

#define STCU_MBSSW_MBSSW239_MASK                 (0x8000U)
#define STCU_MBSSW_MBSSW239_SHIFT                (15U)
#define STCU_MBSSW_MBSSW239_WIDTH                (1U)
#define STCU_MBSSW_MBSSW239(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW239_SHIFT)) & STCU_MBSSW_MBSSW239_MASK)

#define STCU_MBSSW_MBSSW240_MASK                 (0x10000U)
#define STCU_MBSSW_MBSSW240_SHIFT                (16U)
#define STCU_MBSSW_MBSSW240_WIDTH                (1U)
#define STCU_MBSSW_MBSSW240(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW240_SHIFT)) & STCU_MBSSW_MBSSW240_MASK)

#define STCU_MBSSW_MBSSW241_MASK                 (0x20000U)
#define STCU_MBSSW_MBSSW241_SHIFT                (17U)
#define STCU_MBSSW_MBSSW241_WIDTH                (1U)
#define STCU_MBSSW_MBSSW241(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW241_SHIFT)) & STCU_MBSSW_MBSSW241_MASK)

#define STCU_MBSSW_MBSSW242_MASK                 (0x40000U)
#define STCU_MBSSW_MBSSW242_SHIFT                (18U)
#define STCU_MBSSW_MBSSW242_WIDTH                (1U)
#define STCU_MBSSW_MBSSW242(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW242_SHIFT)) & STCU_MBSSW_MBSSW242_MASK)

#define STCU_MBSSW_MBSSW243_MASK                 (0x80000U)
#define STCU_MBSSW_MBSSW243_SHIFT                (19U)
#define STCU_MBSSW_MBSSW243_WIDTH                (1U)
#define STCU_MBSSW_MBSSW243(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW243_SHIFT)) & STCU_MBSSW_MBSSW243_MASK)

#define STCU_MBSSW_MBSSW244_MASK                 (0x100000U)
#define STCU_MBSSW_MBSSW244_SHIFT                (20U)
#define STCU_MBSSW_MBSSW244_WIDTH                (1U)
#define STCU_MBSSW_MBSSW244(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW244_SHIFT)) & STCU_MBSSW_MBSSW244_MASK)

#define STCU_MBSSW_MBSSW245_MASK                 (0x200000U)
#define STCU_MBSSW_MBSSW245_SHIFT                (21U)
#define STCU_MBSSW_MBSSW245_WIDTH                (1U)
#define STCU_MBSSW_MBSSW245(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW245_SHIFT)) & STCU_MBSSW_MBSSW245_MASK)

#define STCU_MBSSW_MBSSW246_MASK                 (0x400000U)
#define STCU_MBSSW_MBSSW246_SHIFT                (22U)
#define STCU_MBSSW_MBSSW246_WIDTH                (1U)
#define STCU_MBSSW_MBSSW246(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW246_SHIFT)) & STCU_MBSSW_MBSSW246_MASK)

#define STCU_MBSSW_MBSSW247_MASK                 (0x800000U)
#define STCU_MBSSW_MBSSW247_SHIFT                (23U)
#define STCU_MBSSW_MBSSW247_WIDTH                (1U)
#define STCU_MBSSW_MBSSW247(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW247_SHIFT)) & STCU_MBSSW_MBSSW247_MASK)

#define STCU_MBSSW_MBSSW248_MASK                 (0x1000000U)
#define STCU_MBSSW_MBSSW248_SHIFT                (24U)
#define STCU_MBSSW_MBSSW248_WIDTH                (1U)
#define STCU_MBSSW_MBSSW248(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW248_SHIFT)) & STCU_MBSSW_MBSSW248_MASK)

#define STCU_MBSSW_MBSSW249_MASK                 (0x2000000U)
#define STCU_MBSSW_MBSSW249_SHIFT                (25U)
#define STCU_MBSSW_MBSSW249_WIDTH                (1U)
#define STCU_MBSSW_MBSSW249(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW249_SHIFT)) & STCU_MBSSW_MBSSW249_MASK)

#define STCU_MBSSW_MBSSW250_MASK                 (0x4000000U)
#define STCU_MBSSW_MBSSW250_SHIFT                (26U)
#define STCU_MBSSW_MBSSW250_WIDTH                (1U)
#define STCU_MBSSW_MBSSW250(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW250_SHIFT)) & STCU_MBSSW_MBSSW250_MASK)

#define STCU_MBSSW_MBSSW251_MASK                 (0x8000000U)
#define STCU_MBSSW_MBSSW251_SHIFT                (27U)
#define STCU_MBSSW_MBSSW251_WIDTH                (1U)
#define STCU_MBSSW_MBSSW251(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW251_SHIFT)) & STCU_MBSSW_MBSSW251_MASK)

#define STCU_MBSSW_MBSSW252_MASK                 (0x10000000U)
#define STCU_MBSSW_MBSSW252_SHIFT                (28U)
#define STCU_MBSSW_MBSSW252_WIDTH                (1U)
#define STCU_MBSSW_MBSSW252(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW252_SHIFT)) & STCU_MBSSW_MBSSW252_MASK)

#define STCU_MBSSW_MBSSW253_MASK                 (0x20000000U)
#define STCU_MBSSW_MBSSW253_SHIFT                (29U)
#define STCU_MBSSW_MBSSW253_WIDTH                (1U)
#define STCU_MBSSW_MBSSW253(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW253_SHIFT)) & STCU_MBSSW_MBSSW253_MASK)

#define STCU_MBSSW_MBSSW254_MASK                 (0x40000000U)
#define STCU_MBSSW_MBSSW254_SHIFT                (30U)
#define STCU_MBSSW_MBSSW254_WIDTH                (1U)
#define STCU_MBSSW_MBSSW254(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW254_SHIFT)) & STCU_MBSSW_MBSSW254_MASK)

#define STCU_MBSSW_MBSSW255_MASK                 (0x80000000U)
#define STCU_MBSSW_MBSSW255_SHIFT                (31U)
#define STCU_MBSSW_MBSSW255_WIDTH                (1U)
#define STCU_MBSSW_MBSSW255(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW_MBSSW255_SHIFT)) & STCU_MBSSW_MBSSW255_MASK)
/*! @} */

/*! @name MBESW - STCU2 Online MBIST End Flag */
/*! @{ */

#define STCU_MBESW_MBESW0_MASK                   (0x1U)
#define STCU_MBESW_MBESW0_SHIFT                  (0U)
#define STCU_MBESW_MBESW0_WIDTH                  (1U)
#define STCU_MBESW_MBESW0(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW0_SHIFT)) & STCU_MBESW_MBESW0_MASK)

#define STCU_MBESW_MBESW1_MASK                   (0x2U)
#define STCU_MBESW_MBESW1_SHIFT                  (1U)
#define STCU_MBESW_MBESW1_WIDTH                  (1U)
#define STCU_MBESW_MBESW1(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW1_SHIFT)) & STCU_MBESW_MBESW1_MASK)

#define STCU_MBESW_MBESW2_MASK                   (0x4U)
#define STCU_MBESW_MBESW2_SHIFT                  (2U)
#define STCU_MBESW_MBESW2_WIDTH                  (1U)
#define STCU_MBESW_MBESW2(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW2_SHIFT)) & STCU_MBESW_MBESW2_MASK)

#define STCU_MBESW_MBESW3_MASK                   (0x8U)
#define STCU_MBESW_MBESW3_SHIFT                  (3U)
#define STCU_MBESW_MBESW3_WIDTH                  (1U)
#define STCU_MBESW_MBESW3(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW3_SHIFT)) & STCU_MBESW_MBESW3_MASK)

#define STCU_MBESW_MBESW4_MASK                   (0x10U)
#define STCU_MBESW_MBESW4_SHIFT                  (4U)
#define STCU_MBESW_MBESW4_WIDTH                  (1U)
#define STCU_MBESW_MBESW4(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW4_SHIFT)) & STCU_MBESW_MBESW4_MASK)

#define STCU_MBESW_MBESW5_MASK                   (0x20U)
#define STCU_MBESW_MBESW5_SHIFT                  (5U)
#define STCU_MBESW_MBESW5_WIDTH                  (1U)
#define STCU_MBESW_MBESW5(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW5_SHIFT)) & STCU_MBESW_MBESW5_MASK)

#define STCU_MBESW_MBESW6_MASK                   (0x40U)
#define STCU_MBESW_MBESW6_SHIFT                  (6U)
#define STCU_MBESW_MBESW6_WIDTH                  (1U)
#define STCU_MBESW_MBESW6(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW6_SHIFT)) & STCU_MBESW_MBESW6_MASK)

#define STCU_MBESW_MBESW7_MASK                   (0x80U)
#define STCU_MBESW_MBESW7_SHIFT                  (7U)
#define STCU_MBESW_MBESW7_WIDTH                  (1U)
#define STCU_MBESW_MBESW7(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW7_SHIFT)) & STCU_MBESW_MBESW7_MASK)

#define STCU_MBESW_MBESW8_MASK                   (0x100U)
#define STCU_MBESW_MBESW8_SHIFT                  (8U)
#define STCU_MBESW_MBESW8_WIDTH                  (1U)
#define STCU_MBESW_MBESW8(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW8_SHIFT)) & STCU_MBESW_MBESW8_MASK)

#define STCU_MBESW_MBESW9_MASK                   (0x200U)
#define STCU_MBESW_MBESW9_SHIFT                  (9U)
#define STCU_MBESW_MBESW9_WIDTH                  (1U)
#define STCU_MBESW_MBESW9(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW9_SHIFT)) & STCU_MBESW_MBESW9_MASK)

#define STCU_MBESW_MBESW10_MASK                  (0x400U)
#define STCU_MBESW_MBESW10_SHIFT                 (10U)
#define STCU_MBESW_MBESW10_WIDTH                 (1U)
#define STCU_MBESW_MBESW10(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW10_SHIFT)) & STCU_MBESW_MBESW10_MASK)

#define STCU_MBESW_MBESW11_MASK                  (0x800U)
#define STCU_MBESW_MBESW11_SHIFT                 (11U)
#define STCU_MBESW_MBESW11_WIDTH                 (1U)
#define STCU_MBESW_MBESW11(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW11_SHIFT)) & STCU_MBESW_MBESW11_MASK)

#define STCU_MBESW_MBESW12_MASK                  (0x1000U)
#define STCU_MBESW_MBESW12_SHIFT                 (12U)
#define STCU_MBESW_MBESW12_WIDTH                 (1U)
#define STCU_MBESW_MBESW12(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW12_SHIFT)) & STCU_MBESW_MBESW12_MASK)

#define STCU_MBESW_MBESW13_MASK                  (0x2000U)
#define STCU_MBESW_MBESW13_SHIFT                 (13U)
#define STCU_MBESW_MBESW13_WIDTH                 (1U)
#define STCU_MBESW_MBESW13(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW13_SHIFT)) & STCU_MBESW_MBESW13_MASK)

#define STCU_MBESW_MBESW14_MASK                  (0x4000U)
#define STCU_MBESW_MBESW14_SHIFT                 (14U)
#define STCU_MBESW_MBESW14_WIDTH                 (1U)
#define STCU_MBESW_MBESW14(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW14_SHIFT)) & STCU_MBESW_MBESW14_MASK)

#define STCU_MBESW_MBESW15_MASK                  (0x8000U)
#define STCU_MBESW_MBESW15_SHIFT                 (15U)
#define STCU_MBESW_MBESW15_WIDTH                 (1U)
#define STCU_MBESW_MBESW15(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW15_SHIFT)) & STCU_MBESW_MBESW15_MASK)

#define STCU_MBESW_MBESW16_MASK                  (0x10000U)
#define STCU_MBESW_MBESW16_SHIFT                 (16U)
#define STCU_MBESW_MBESW16_WIDTH                 (1U)
#define STCU_MBESW_MBESW16(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW16_SHIFT)) & STCU_MBESW_MBESW16_MASK)

#define STCU_MBESW_MBESW17_MASK                  (0x20000U)
#define STCU_MBESW_MBESW17_SHIFT                 (17U)
#define STCU_MBESW_MBESW17_WIDTH                 (1U)
#define STCU_MBESW_MBESW17(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW17_SHIFT)) & STCU_MBESW_MBESW17_MASK)

#define STCU_MBESW_MBESW18_MASK                  (0x40000U)
#define STCU_MBESW_MBESW18_SHIFT                 (18U)
#define STCU_MBESW_MBESW18_WIDTH                 (1U)
#define STCU_MBESW_MBESW18(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW18_SHIFT)) & STCU_MBESW_MBESW18_MASK)

#define STCU_MBESW_MBESW19_MASK                  (0x80000U)
#define STCU_MBESW_MBESW19_SHIFT                 (19U)
#define STCU_MBESW_MBESW19_WIDTH                 (1U)
#define STCU_MBESW_MBESW19(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW19_SHIFT)) & STCU_MBESW_MBESW19_MASK)

#define STCU_MBESW_MBESW20_MASK                  (0x100000U)
#define STCU_MBESW_MBESW20_SHIFT                 (20U)
#define STCU_MBESW_MBESW20_WIDTH                 (1U)
#define STCU_MBESW_MBESW20(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW20_SHIFT)) & STCU_MBESW_MBESW20_MASK)

#define STCU_MBESW_MBESW21_MASK                  (0x200000U)
#define STCU_MBESW_MBESW21_SHIFT                 (21U)
#define STCU_MBESW_MBESW21_WIDTH                 (1U)
#define STCU_MBESW_MBESW21(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW21_SHIFT)) & STCU_MBESW_MBESW21_MASK)

#define STCU_MBESW_MBESW22_MASK                  (0x400000U)
#define STCU_MBESW_MBESW22_SHIFT                 (22U)
#define STCU_MBESW_MBESW22_WIDTH                 (1U)
#define STCU_MBESW_MBESW22(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW22_SHIFT)) & STCU_MBESW_MBESW22_MASK)

#define STCU_MBESW_MBESW23_MASK                  (0x800000U)
#define STCU_MBESW_MBESW23_SHIFT                 (23U)
#define STCU_MBESW_MBESW23_WIDTH                 (1U)
#define STCU_MBESW_MBESW23(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW23_SHIFT)) & STCU_MBESW_MBESW23_MASK)

#define STCU_MBESW_MBESW24_MASK                  (0x1000000U)
#define STCU_MBESW_MBESW24_SHIFT                 (24U)
#define STCU_MBESW_MBESW24_WIDTH                 (1U)
#define STCU_MBESW_MBESW24(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW24_SHIFT)) & STCU_MBESW_MBESW24_MASK)

#define STCU_MBESW_MBESW25_MASK                  (0x2000000U)
#define STCU_MBESW_MBESW25_SHIFT                 (25U)
#define STCU_MBESW_MBESW25_WIDTH                 (1U)
#define STCU_MBESW_MBESW25(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW25_SHIFT)) & STCU_MBESW_MBESW25_MASK)

#define STCU_MBESW_MBESW26_MASK                  (0x4000000U)
#define STCU_MBESW_MBESW26_SHIFT                 (26U)
#define STCU_MBESW_MBESW26_WIDTH                 (1U)
#define STCU_MBESW_MBESW26(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW26_SHIFT)) & STCU_MBESW_MBESW26_MASK)

#define STCU_MBESW_MBESW27_MASK                  (0x8000000U)
#define STCU_MBESW_MBESW27_SHIFT                 (27U)
#define STCU_MBESW_MBESW27_WIDTH                 (1U)
#define STCU_MBESW_MBESW27(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW27_SHIFT)) & STCU_MBESW_MBESW27_MASK)

#define STCU_MBESW_MBESW28_MASK                  (0x10000000U)
#define STCU_MBESW_MBESW28_SHIFT                 (28U)
#define STCU_MBESW_MBESW28_WIDTH                 (1U)
#define STCU_MBESW_MBESW28(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW28_SHIFT)) & STCU_MBESW_MBESW28_MASK)

#define STCU_MBESW_MBESW29_MASK                  (0x20000000U)
#define STCU_MBESW_MBESW29_SHIFT                 (29U)
#define STCU_MBESW_MBESW29_WIDTH                 (1U)
#define STCU_MBESW_MBESW29(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW29_SHIFT)) & STCU_MBESW_MBESW29_MASK)

#define STCU_MBESW_MBESW30_MASK                  (0x40000000U)
#define STCU_MBESW_MBESW30_SHIFT                 (30U)
#define STCU_MBESW_MBESW30_WIDTH                 (1U)
#define STCU_MBESW_MBESW30(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW30_SHIFT)) & STCU_MBESW_MBESW30_MASK)

#define STCU_MBESW_MBESW31_MASK                  (0x80000000U)
#define STCU_MBESW_MBESW31_SHIFT                 (31U)
#define STCU_MBESW_MBESW31_WIDTH                 (1U)
#define STCU_MBESW_MBESW31(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW31_SHIFT)) & STCU_MBESW_MBESW31_MASK)

#define STCU_MBESW_MBESW32_MASK                  (0x1U)
#define STCU_MBESW_MBESW32_SHIFT                 (0U)
#define STCU_MBESW_MBESW32_WIDTH                 (1U)
#define STCU_MBESW_MBESW32(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW32_SHIFT)) & STCU_MBESW_MBESW32_MASK)

#define STCU_MBESW_MBESW33_MASK                  (0x2U)
#define STCU_MBESW_MBESW33_SHIFT                 (1U)
#define STCU_MBESW_MBESW33_WIDTH                 (1U)
#define STCU_MBESW_MBESW33(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW33_SHIFT)) & STCU_MBESW_MBESW33_MASK)

#define STCU_MBESW_MBESW34_MASK                  (0x4U)
#define STCU_MBESW_MBESW34_SHIFT                 (2U)
#define STCU_MBESW_MBESW34_WIDTH                 (1U)
#define STCU_MBESW_MBESW34(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW34_SHIFT)) & STCU_MBESW_MBESW34_MASK)

#define STCU_MBESW_MBESW35_MASK                  (0x8U)
#define STCU_MBESW_MBESW35_SHIFT                 (3U)
#define STCU_MBESW_MBESW35_WIDTH                 (1U)
#define STCU_MBESW_MBESW35(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW35_SHIFT)) & STCU_MBESW_MBESW35_MASK)

#define STCU_MBESW_MBESW36_MASK                  (0x10U)
#define STCU_MBESW_MBESW36_SHIFT                 (4U)
#define STCU_MBESW_MBESW36_WIDTH                 (1U)
#define STCU_MBESW_MBESW36(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW36_SHIFT)) & STCU_MBESW_MBESW36_MASK)

#define STCU_MBESW_MBESW37_MASK                  (0x20U)
#define STCU_MBESW_MBESW37_SHIFT                 (5U)
#define STCU_MBESW_MBESW37_WIDTH                 (1U)
#define STCU_MBESW_MBESW37(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW37_SHIFT)) & STCU_MBESW_MBESW37_MASK)

#define STCU_MBESW_MBESW38_MASK                  (0x40U)
#define STCU_MBESW_MBESW38_SHIFT                 (6U)
#define STCU_MBESW_MBESW38_WIDTH                 (1U)
#define STCU_MBESW_MBESW38(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW38_SHIFT)) & STCU_MBESW_MBESW38_MASK)

#define STCU_MBESW_MBESW39_MASK                  (0x80U)
#define STCU_MBESW_MBESW39_SHIFT                 (7U)
#define STCU_MBESW_MBESW39_WIDTH                 (1U)
#define STCU_MBESW_MBESW39(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW39_SHIFT)) & STCU_MBESW_MBESW39_MASK)

#define STCU_MBESW_MBESW40_MASK                  (0x100U)
#define STCU_MBESW_MBESW40_SHIFT                 (8U)
#define STCU_MBESW_MBESW40_WIDTH                 (1U)
#define STCU_MBESW_MBESW40(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW40_SHIFT)) & STCU_MBESW_MBESW40_MASK)

#define STCU_MBESW_MBESW41_MASK                  (0x200U)
#define STCU_MBESW_MBESW41_SHIFT                 (9U)
#define STCU_MBESW_MBESW41_WIDTH                 (1U)
#define STCU_MBESW_MBESW41(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW41_SHIFT)) & STCU_MBESW_MBESW41_MASK)

#define STCU_MBESW_MBESW42_MASK                  (0x400U)
#define STCU_MBESW_MBESW42_SHIFT                 (10U)
#define STCU_MBESW_MBESW42_WIDTH                 (1U)
#define STCU_MBESW_MBESW42(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW42_SHIFT)) & STCU_MBESW_MBESW42_MASK)

#define STCU_MBESW_MBESW43_MASK                  (0x800U)
#define STCU_MBESW_MBESW43_SHIFT                 (11U)
#define STCU_MBESW_MBESW43_WIDTH                 (1U)
#define STCU_MBESW_MBESW43(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW43_SHIFT)) & STCU_MBESW_MBESW43_MASK)

#define STCU_MBESW_MBESW44_MASK                  (0x1000U)
#define STCU_MBESW_MBESW44_SHIFT                 (12U)
#define STCU_MBESW_MBESW44_WIDTH                 (1U)
#define STCU_MBESW_MBESW44(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW44_SHIFT)) & STCU_MBESW_MBESW44_MASK)

#define STCU_MBESW_MBESW45_MASK                  (0x2000U)
#define STCU_MBESW_MBESW45_SHIFT                 (13U)
#define STCU_MBESW_MBESW45_WIDTH                 (1U)
#define STCU_MBESW_MBESW45(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW45_SHIFT)) & STCU_MBESW_MBESW45_MASK)

#define STCU_MBESW_MBESW46_MASK                  (0x4000U)
#define STCU_MBESW_MBESW46_SHIFT                 (14U)
#define STCU_MBESW_MBESW46_WIDTH                 (1U)
#define STCU_MBESW_MBESW46(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW46_SHIFT)) & STCU_MBESW_MBESW46_MASK)

#define STCU_MBESW_MBESW47_MASK                  (0x8000U)
#define STCU_MBESW_MBESW47_SHIFT                 (15U)
#define STCU_MBESW_MBESW47_WIDTH                 (1U)
#define STCU_MBESW_MBESW47(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW47_SHIFT)) & STCU_MBESW_MBESW47_MASK)

#define STCU_MBESW_MBESW48_MASK                  (0x10000U)
#define STCU_MBESW_MBESW48_SHIFT                 (16U)
#define STCU_MBESW_MBESW48_WIDTH                 (1U)
#define STCU_MBESW_MBESW48(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW48_SHIFT)) & STCU_MBESW_MBESW48_MASK)

#define STCU_MBESW_MBESW49_MASK                  (0x20000U)
#define STCU_MBESW_MBESW49_SHIFT                 (17U)
#define STCU_MBESW_MBESW49_WIDTH                 (1U)
#define STCU_MBESW_MBESW49(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW49_SHIFT)) & STCU_MBESW_MBESW49_MASK)

#define STCU_MBESW_MBESW50_MASK                  (0x40000U)
#define STCU_MBESW_MBESW50_SHIFT                 (18U)
#define STCU_MBESW_MBESW50_WIDTH                 (1U)
#define STCU_MBESW_MBESW50(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW50_SHIFT)) & STCU_MBESW_MBESW50_MASK)

#define STCU_MBESW_MBESW51_MASK                  (0x80000U)
#define STCU_MBESW_MBESW51_SHIFT                 (19U)
#define STCU_MBESW_MBESW51_WIDTH                 (1U)
#define STCU_MBESW_MBESW51(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW51_SHIFT)) & STCU_MBESW_MBESW51_MASK)

#define STCU_MBESW_MBESW52_MASK                  (0x100000U)
#define STCU_MBESW_MBESW52_SHIFT                 (20U)
#define STCU_MBESW_MBESW52_WIDTH                 (1U)
#define STCU_MBESW_MBESW52(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW52_SHIFT)) & STCU_MBESW_MBESW52_MASK)

#define STCU_MBESW_MBESW53_MASK                  (0x200000U)
#define STCU_MBESW_MBESW53_SHIFT                 (21U)
#define STCU_MBESW_MBESW53_WIDTH                 (1U)
#define STCU_MBESW_MBESW53(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW53_SHIFT)) & STCU_MBESW_MBESW53_MASK)

#define STCU_MBESW_MBESW54_MASK                  (0x400000U)
#define STCU_MBESW_MBESW54_SHIFT                 (22U)
#define STCU_MBESW_MBESW54_WIDTH                 (1U)
#define STCU_MBESW_MBESW54(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW54_SHIFT)) & STCU_MBESW_MBESW54_MASK)

#define STCU_MBESW_MBESW55_MASK                  (0x800000U)
#define STCU_MBESW_MBESW55_SHIFT                 (23U)
#define STCU_MBESW_MBESW55_WIDTH                 (1U)
#define STCU_MBESW_MBESW55(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW55_SHIFT)) & STCU_MBESW_MBESW55_MASK)

#define STCU_MBESW_MBESW56_MASK                  (0x1000000U)
#define STCU_MBESW_MBESW56_SHIFT                 (24U)
#define STCU_MBESW_MBESW56_WIDTH                 (1U)
#define STCU_MBESW_MBESW56(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW56_SHIFT)) & STCU_MBESW_MBESW56_MASK)

#define STCU_MBESW_MBESW57_MASK                  (0x2000000U)
#define STCU_MBESW_MBESW57_SHIFT                 (25U)
#define STCU_MBESW_MBESW57_WIDTH                 (1U)
#define STCU_MBESW_MBESW57(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW57_SHIFT)) & STCU_MBESW_MBESW57_MASK)

#define STCU_MBESW_MBESW58_MASK                  (0x4000000U)
#define STCU_MBESW_MBESW58_SHIFT                 (26U)
#define STCU_MBESW_MBESW58_WIDTH                 (1U)
#define STCU_MBESW_MBESW58(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW58_SHIFT)) & STCU_MBESW_MBESW58_MASK)

#define STCU_MBESW_MBESW59_MASK                  (0x8000000U)
#define STCU_MBESW_MBESW59_SHIFT                 (27U)
#define STCU_MBESW_MBESW59_WIDTH                 (1U)
#define STCU_MBESW_MBESW59(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW59_SHIFT)) & STCU_MBESW_MBESW59_MASK)

#define STCU_MBESW_MBESW60_MASK                  (0x10000000U)
#define STCU_MBESW_MBESW60_SHIFT                 (28U)
#define STCU_MBESW_MBESW60_WIDTH                 (1U)
#define STCU_MBESW_MBESW60(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW60_SHIFT)) & STCU_MBESW_MBESW60_MASK)

#define STCU_MBESW_MBESW61_MASK                  (0x20000000U)
#define STCU_MBESW_MBESW61_SHIFT                 (29U)
#define STCU_MBESW_MBESW61_WIDTH                 (1U)
#define STCU_MBESW_MBESW61(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW61_SHIFT)) & STCU_MBESW_MBESW61_MASK)

#define STCU_MBESW_MBESW62_MASK                  (0x40000000U)
#define STCU_MBESW_MBESW62_SHIFT                 (30U)
#define STCU_MBESW_MBESW62_WIDTH                 (1U)
#define STCU_MBESW_MBESW62(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW62_SHIFT)) & STCU_MBESW_MBESW62_MASK)

#define STCU_MBESW_MBESW63_MASK                  (0x80000000U)
#define STCU_MBESW_MBESW63_SHIFT                 (31U)
#define STCU_MBESW_MBESW63_WIDTH                 (1U)
#define STCU_MBESW_MBESW63(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW63_SHIFT)) & STCU_MBESW_MBESW63_MASK)

#define STCU_MBESW_MBESW64_MASK                  (0x1U)
#define STCU_MBESW_MBESW64_SHIFT                 (0U)
#define STCU_MBESW_MBESW64_WIDTH                 (1U)
#define STCU_MBESW_MBESW64(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW64_SHIFT)) & STCU_MBESW_MBESW64_MASK)

#define STCU_MBESW_MBESW65_MASK                  (0x2U)
#define STCU_MBESW_MBESW65_SHIFT                 (1U)
#define STCU_MBESW_MBESW65_WIDTH                 (1U)
#define STCU_MBESW_MBESW65(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW65_SHIFT)) & STCU_MBESW_MBESW65_MASK)

#define STCU_MBESW_MBESW66_MASK                  (0x4U)
#define STCU_MBESW_MBESW66_SHIFT                 (2U)
#define STCU_MBESW_MBESW66_WIDTH                 (1U)
#define STCU_MBESW_MBESW66(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW66_SHIFT)) & STCU_MBESW_MBESW66_MASK)

#define STCU_MBESW_MBESW67_MASK                  (0x8U)
#define STCU_MBESW_MBESW67_SHIFT                 (3U)
#define STCU_MBESW_MBESW67_WIDTH                 (1U)
#define STCU_MBESW_MBESW67(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW67_SHIFT)) & STCU_MBESW_MBESW67_MASK)

#define STCU_MBESW_MBESW68_MASK                  (0x10U)
#define STCU_MBESW_MBESW68_SHIFT                 (4U)
#define STCU_MBESW_MBESW68_WIDTH                 (1U)
#define STCU_MBESW_MBESW68(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW68_SHIFT)) & STCU_MBESW_MBESW68_MASK)

#define STCU_MBESW_MBESW69_MASK                  (0x20U)
#define STCU_MBESW_MBESW69_SHIFT                 (5U)
#define STCU_MBESW_MBESW69_WIDTH                 (1U)
#define STCU_MBESW_MBESW69(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW69_SHIFT)) & STCU_MBESW_MBESW69_MASK)

#define STCU_MBESW_MBESW70_MASK                  (0x40U)
#define STCU_MBESW_MBESW70_SHIFT                 (6U)
#define STCU_MBESW_MBESW70_WIDTH                 (1U)
#define STCU_MBESW_MBESW70(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW70_SHIFT)) & STCU_MBESW_MBESW70_MASK)

#define STCU_MBESW_MBESW71_MASK                  (0x80U)
#define STCU_MBESW_MBESW71_SHIFT                 (7U)
#define STCU_MBESW_MBESW71_WIDTH                 (1U)
#define STCU_MBESW_MBESW71(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW71_SHIFT)) & STCU_MBESW_MBESW71_MASK)

#define STCU_MBESW_MBESW72_MASK                  (0x100U)
#define STCU_MBESW_MBESW72_SHIFT                 (8U)
#define STCU_MBESW_MBESW72_WIDTH                 (1U)
#define STCU_MBESW_MBESW72(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW72_SHIFT)) & STCU_MBESW_MBESW72_MASK)

#define STCU_MBESW_MBESW73_MASK                  (0x200U)
#define STCU_MBESW_MBESW73_SHIFT                 (9U)
#define STCU_MBESW_MBESW73_WIDTH                 (1U)
#define STCU_MBESW_MBESW73(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW73_SHIFT)) & STCU_MBESW_MBESW73_MASK)

#define STCU_MBESW_MBESW74_MASK                  (0x400U)
#define STCU_MBESW_MBESW74_SHIFT                 (10U)
#define STCU_MBESW_MBESW74_WIDTH                 (1U)
#define STCU_MBESW_MBESW74(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW74_SHIFT)) & STCU_MBESW_MBESW74_MASK)

#define STCU_MBESW_MBESW75_MASK                  (0x800U)
#define STCU_MBESW_MBESW75_SHIFT                 (11U)
#define STCU_MBESW_MBESW75_WIDTH                 (1U)
#define STCU_MBESW_MBESW75(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW75_SHIFT)) & STCU_MBESW_MBESW75_MASK)

#define STCU_MBESW_MBESW76_MASK                  (0x1000U)
#define STCU_MBESW_MBESW76_SHIFT                 (12U)
#define STCU_MBESW_MBESW76_WIDTH                 (1U)
#define STCU_MBESW_MBESW76(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW76_SHIFT)) & STCU_MBESW_MBESW76_MASK)

#define STCU_MBESW_MBESW77_MASK                  (0x2000U)
#define STCU_MBESW_MBESW77_SHIFT                 (13U)
#define STCU_MBESW_MBESW77_WIDTH                 (1U)
#define STCU_MBESW_MBESW77(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW77_SHIFT)) & STCU_MBESW_MBESW77_MASK)

#define STCU_MBESW_MBESW78_MASK                  (0x4000U)
#define STCU_MBESW_MBESW78_SHIFT                 (14U)
#define STCU_MBESW_MBESW78_WIDTH                 (1U)
#define STCU_MBESW_MBESW78(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW78_SHIFT)) & STCU_MBESW_MBESW78_MASK)

#define STCU_MBESW_MBESW79_MASK                  (0x8000U)
#define STCU_MBESW_MBESW79_SHIFT                 (15U)
#define STCU_MBESW_MBESW79_WIDTH                 (1U)
#define STCU_MBESW_MBESW79(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW79_SHIFT)) & STCU_MBESW_MBESW79_MASK)

#define STCU_MBESW_MBESW80_MASK                  (0x10000U)
#define STCU_MBESW_MBESW80_SHIFT                 (16U)
#define STCU_MBESW_MBESW80_WIDTH                 (1U)
#define STCU_MBESW_MBESW80(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW80_SHIFT)) & STCU_MBESW_MBESW80_MASK)

#define STCU_MBESW_MBESW81_MASK                  (0x20000U)
#define STCU_MBESW_MBESW81_SHIFT                 (17U)
#define STCU_MBESW_MBESW81_WIDTH                 (1U)
#define STCU_MBESW_MBESW81(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW81_SHIFT)) & STCU_MBESW_MBESW81_MASK)

#define STCU_MBESW_MBESW82_MASK                  (0x40000U)
#define STCU_MBESW_MBESW82_SHIFT                 (18U)
#define STCU_MBESW_MBESW82_WIDTH                 (1U)
#define STCU_MBESW_MBESW82(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW82_SHIFT)) & STCU_MBESW_MBESW82_MASK)

#define STCU_MBESW_MBESW83_MASK                  (0x80000U)
#define STCU_MBESW_MBESW83_SHIFT                 (19U)
#define STCU_MBESW_MBESW83_WIDTH                 (1U)
#define STCU_MBESW_MBESW83(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW83_SHIFT)) & STCU_MBESW_MBESW83_MASK)

#define STCU_MBESW_MBESW84_MASK                  (0x100000U)
#define STCU_MBESW_MBESW84_SHIFT                 (20U)
#define STCU_MBESW_MBESW84_WIDTH                 (1U)
#define STCU_MBESW_MBESW84(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW84_SHIFT)) & STCU_MBESW_MBESW84_MASK)

#define STCU_MBESW_MBESW85_MASK                  (0x200000U)
#define STCU_MBESW_MBESW85_SHIFT                 (21U)
#define STCU_MBESW_MBESW85_WIDTH                 (1U)
#define STCU_MBESW_MBESW85(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW85_SHIFT)) & STCU_MBESW_MBESW85_MASK)

#define STCU_MBESW_MBESW86_MASK                  (0x400000U)
#define STCU_MBESW_MBESW86_SHIFT                 (22U)
#define STCU_MBESW_MBESW86_WIDTH                 (1U)
#define STCU_MBESW_MBESW86(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW86_SHIFT)) & STCU_MBESW_MBESW86_MASK)

#define STCU_MBESW_MBESW87_MASK                  (0x800000U)
#define STCU_MBESW_MBESW87_SHIFT                 (23U)
#define STCU_MBESW_MBESW87_WIDTH                 (1U)
#define STCU_MBESW_MBESW87(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW87_SHIFT)) & STCU_MBESW_MBESW87_MASK)

#define STCU_MBESW_MBESW88_MASK                  (0x1000000U)
#define STCU_MBESW_MBESW88_SHIFT                 (24U)
#define STCU_MBESW_MBESW88_WIDTH                 (1U)
#define STCU_MBESW_MBESW88(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW88_SHIFT)) & STCU_MBESW_MBESW88_MASK)

#define STCU_MBESW_MBESW89_MASK                  (0x2000000U)
#define STCU_MBESW_MBESW89_SHIFT                 (25U)
#define STCU_MBESW_MBESW89_WIDTH                 (1U)
#define STCU_MBESW_MBESW89(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW89_SHIFT)) & STCU_MBESW_MBESW89_MASK)

#define STCU_MBESW_MBESW90_MASK                  (0x4000000U)
#define STCU_MBESW_MBESW90_SHIFT                 (26U)
#define STCU_MBESW_MBESW90_WIDTH                 (1U)
#define STCU_MBESW_MBESW90(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW90_SHIFT)) & STCU_MBESW_MBESW90_MASK)

#define STCU_MBESW_MBESW91_MASK                  (0x8000000U)
#define STCU_MBESW_MBESW91_SHIFT                 (27U)
#define STCU_MBESW_MBESW91_WIDTH                 (1U)
#define STCU_MBESW_MBESW91(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW91_SHIFT)) & STCU_MBESW_MBESW91_MASK)

#define STCU_MBESW_MBESW92_MASK                  (0x10000000U)
#define STCU_MBESW_MBESW92_SHIFT                 (28U)
#define STCU_MBESW_MBESW92_WIDTH                 (1U)
#define STCU_MBESW_MBESW92(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW92_SHIFT)) & STCU_MBESW_MBESW92_MASK)

#define STCU_MBESW_MBESW93_MASK                  (0x20000000U)
#define STCU_MBESW_MBESW93_SHIFT                 (29U)
#define STCU_MBESW_MBESW93_WIDTH                 (1U)
#define STCU_MBESW_MBESW93(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW93_SHIFT)) & STCU_MBESW_MBESW93_MASK)

#define STCU_MBESW_MBESW94_MASK                  (0x40000000U)
#define STCU_MBESW_MBESW94_SHIFT                 (30U)
#define STCU_MBESW_MBESW94_WIDTH                 (1U)
#define STCU_MBESW_MBESW94(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW94_SHIFT)) & STCU_MBESW_MBESW94_MASK)

#define STCU_MBESW_MBESW95_MASK                  (0x80000000U)
#define STCU_MBESW_MBESW95_SHIFT                 (31U)
#define STCU_MBESW_MBESW95_WIDTH                 (1U)
#define STCU_MBESW_MBESW95(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW95_SHIFT)) & STCU_MBESW_MBESW95_MASK)

#define STCU_MBESW_MBESW96_MASK                  (0x1U)
#define STCU_MBESW_MBESW96_SHIFT                 (0U)
#define STCU_MBESW_MBESW96_WIDTH                 (1U)
#define STCU_MBESW_MBESW96(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW96_SHIFT)) & STCU_MBESW_MBESW96_MASK)

#define STCU_MBESW_MBESW97_MASK                  (0x2U)
#define STCU_MBESW_MBESW97_SHIFT                 (1U)
#define STCU_MBESW_MBESW97_WIDTH                 (1U)
#define STCU_MBESW_MBESW97(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW97_SHIFT)) & STCU_MBESW_MBESW97_MASK)

#define STCU_MBESW_MBESW98_MASK                  (0x4U)
#define STCU_MBESW_MBESW98_SHIFT                 (2U)
#define STCU_MBESW_MBESW98_WIDTH                 (1U)
#define STCU_MBESW_MBESW98(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW98_SHIFT)) & STCU_MBESW_MBESW98_MASK)

#define STCU_MBESW_MBESW99_MASK                  (0x8U)
#define STCU_MBESW_MBESW99_SHIFT                 (3U)
#define STCU_MBESW_MBESW99_WIDTH                 (1U)
#define STCU_MBESW_MBESW99(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW99_SHIFT)) & STCU_MBESW_MBESW99_MASK)

#define STCU_MBESW_MBESW100_MASK                 (0x10U)
#define STCU_MBESW_MBESW100_SHIFT                (4U)
#define STCU_MBESW_MBESW100_WIDTH                (1U)
#define STCU_MBESW_MBESW100(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW100_SHIFT)) & STCU_MBESW_MBESW100_MASK)

#define STCU_MBESW_MBESW101_MASK                 (0x20U)
#define STCU_MBESW_MBESW101_SHIFT                (5U)
#define STCU_MBESW_MBESW101_WIDTH                (1U)
#define STCU_MBESW_MBESW101(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW101_SHIFT)) & STCU_MBESW_MBESW101_MASK)

#define STCU_MBESW_MBESW102_MASK                 (0x40U)
#define STCU_MBESW_MBESW102_SHIFT                (6U)
#define STCU_MBESW_MBESW102_WIDTH                (1U)
#define STCU_MBESW_MBESW102(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW102_SHIFT)) & STCU_MBESW_MBESW102_MASK)

#define STCU_MBESW_MBESW103_MASK                 (0x80U)
#define STCU_MBESW_MBESW103_SHIFT                (7U)
#define STCU_MBESW_MBESW103_WIDTH                (1U)
#define STCU_MBESW_MBESW103(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW103_SHIFT)) & STCU_MBESW_MBESW103_MASK)

#define STCU_MBESW_MBESW104_MASK                 (0x100U)
#define STCU_MBESW_MBESW104_SHIFT                (8U)
#define STCU_MBESW_MBESW104_WIDTH                (1U)
#define STCU_MBESW_MBESW104(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW104_SHIFT)) & STCU_MBESW_MBESW104_MASK)

#define STCU_MBESW_MBESW105_MASK                 (0x200U)
#define STCU_MBESW_MBESW105_SHIFT                (9U)
#define STCU_MBESW_MBESW105_WIDTH                (1U)
#define STCU_MBESW_MBESW105(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW105_SHIFT)) & STCU_MBESW_MBESW105_MASK)

#define STCU_MBESW_MBESW106_MASK                 (0x400U)
#define STCU_MBESW_MBESW106_SHIFT                (10U)
#define STCU_MBESW_MBESW106_WIDTH                (1U)
#define STCU_MBESW_MBESW106(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW106_SHIFT)) & STCU_MBESW_MBESW106_MASK)

#define STCU_MBESW_MBESW107_MASK                 (0x800U)
#define STCU_MBESW_MBESW107_SHIFT                (11U)
#define STCU_MBESW_MBESW107_WIDTH                (1U)
#define STCU_MBESW_MBESW107(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW107_SHIFT)) & STCU_MBESW_MBESW107_MASK)

#define STCU_MBESW_MBESW108_MASK                 (0x1000U)
#define STCU_MBESW_MBESW108_SHIFT                (12U)
#define STCU_MBESW_MBESW108_WIDTH                (1U)
#define STCU_MBESW_MBESW108(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW108_SHIFT)) & STCU_MBESW_MBESW108_MASK)

#define STCU_MBESW_MBESW109_MASK                 (0x2000U)
#define STCU_MBESW_MBESW109_SHIFT                (13U)
#define STCU_MBESW_MBESW109_WIDTH                (1U)
#define STCU_MBESW_MBESW109(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW109_SHIFT)) & STCU_MBESW_MBESW109_MASK)

#define STCU_MBESW_MBESW110_MASK                 (0x4000U)
#define STCU_MBESW_MBESW110_SHIFT                (14U)
#define STCU_MBESW_MBESW110_WIDTH                (1U)
#define STCU_MBESW_MBESW110(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW110_SHIFT)) & STCU_MBESW_MBESW110_MASK)

#define STCU_MBESW_MBESW111_MASK                 (0x8000U)
#define STCU_MBESW_MBESW111_SHIFT                (15U)
#define STCU_MBESW_MBESW111_WIDTH                (1U)
#define STCU_MBESW_MBESW111(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW111_SHIFT)) & STCU_MBESW_MBESW111_MASK)

#define STCU_MBESW_MBESW112_MASK                 (0x10000U)
#define STCU_MBESW_MBESW112_SHIFT                (16U)
#define STCU_MBESW_MBESW112_WIDTH                (1U)
#define STCU_MBESW_MBESW112(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW112_SHIFT)) & STCU_MBESW_MBESW112_MASK)

#define STCU_MBESW_MBESW113_MASK                 (0x20000U)
#define STCU_MBESW_MBESW113_SHIFT                (17U)
#define STCU_MBESW_MBESW113_WIDTH                (1U)
#define STCU_MBESW_MBESW113(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW113_SHIFT)) & STCU_MBESW_MBESW113_MASK)

#define STCU_MBESW_MBESW114_MASK                 (0x40000U)
#define STCU_MBESW_MBESW114_SHIFT                (18U)
#define STCU_MBESW_MBESW114_WIDTH                (1U)
#define STCU_MBESW_MBESW114(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW114_SHIFT)) & STCU_MBESW_MBESW114_MASK)

#define STCU_MBESW_MBESW115_MASK                 (0x80000U)
#define STCU_MBESW_MBESW115_SHIFT                (19U)
#define STCU_MBESW_MBESW115_WIDTH                (1U)
#define STCU_MBESW_MBESW115(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW115_SHIFT)) & STCU_MBESW_MBESW115_MASK)

#define STCU_MBESW_MBESW116_MASK                 (0x100000U)
#define STCU_MBESW_MBESW116_SHIFT                (20U)
#define STCU_MBESW_MBESW116_WIDTH                (1U)
#define STCU_MBESW_MBESW116(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW116_SHIFT)) & STCU_MBESW_MBESW116_MASK)

#define STCU_MBESW_MBESW117_MASK                 (0x200000U)
#define STCU_MBESW_MBESW117_SHIFT                (21U)
#define STCU_MBESW_MBESW117_WIDTH                (1U)
#define STCU_MBESW_MBESW117(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW117_SHIFT)) & STCU_MBESW_MBESW117_MASK)

#define STCU_MBESW_MBESW118_MASK                 (0x400000U)
#define STCU_MBESW_MBESW118_SHIFT                (22U)
#define STCU_MBESW_MBESW118_WIDTH                (1U)
#define STCU_MBESW_MBESW118(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW118_SHIFT)) & STCU_MBESW_MBESW118_MASK)

#define STCU_MBESW_MBESW119_MASK                 (0x800000U)
#define STCU_MBESW_MBESW119_SHIFT                (23U)
#define STCU_MBESW_MBESW119_WIDTH                (1U)
#define STCU_MBESW_MBESW119(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW119_SHIFT)) & STCU_MBESW_MBESW119_MASK)

#define STCU_MBESW_MBESW120_MASK                 (0x1000000U)
#define STCU_MBESW_MBESW120_SHIFT                (24U)
#define STCU_MBESW_MBESW120_WIDTH                (1U)
#define STCU_MBESW_MBESW120(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW120_SHIFT)) & STCU_MBESW_MBESW120_MASK)

#define STCU_MBESW_MBESW121_MASK                 (0x2000000U)
#define STCU_MBESW_MBESW121_SHIFT                (25U)
#define STCU_MBESW_MBESW121_WIDTH                (1U)
#define STCU_MBESW_MBESW121(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW121_SHIFT)) & STCU_MBESW_MBESW121_MASK)

#define STCU_MBESW_MBESW122_MASK                 (0x4000000U)
#define STCU_MBESW_MBESW122_SHIFT                (26U)
#define STCU_MBESW_MBESW122_WIDTH                (1U)
#define STCU_MBESW_MBESW122(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW122_SHIFT)) & STCU_MBESW_MBESW122_MASK)

#define STCU_MBESW_MBESW123_MASK                 (0x8000000U)
#define STCU_MBESW_MBESW123_SHIFT                (27U)
#define STCU_MBESW_MBESW123_WIDTH                (1U)
#define STCU_MBESW_MBESW123(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW123_SHIFT)) & STCU_MBESW_MBESW123_MASK)

#define STCU_MBESW_MBESW124_MASK                 (0x10000000U)
#define STCU_MBESW_MBESW124_SHIFT                (28U)
#define STCU_MBESW_MBESW124_WIDTH                (1U)
#define STCU_MBESW_MBESW124(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW124_SHIFT)) & STCU_MBESW_MBESW124_MASK)

#define STCU_MBESW_MBESW125_MASK                 (0x20000000U)
#define STCU_MBESW_MBESW125_SHIFT                (29U)
#define STCU_MBESW_MBESW125_WIDTH                (1U)
#define STCU_MBESW_MBESW125(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW125_SHIFT)) & STCU_MBESW_MBESW125_MASK)

#define STCU_MBESW_MBESW126_MASK                 (0x40000000U)
#define STCU_MBESW_MBESW126_SHIFT                (30U)
#define STCU_MBESW_MBESW126_WIDTH                (1U)
#define STCU_MBESW_MBESW126(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW126_SHIFT)) & STCU_MBESW_MBESW126_MASK)

#define STCU_MBESW_MBESW127_MASK                 (0x80000000U)
#define STCU_MBESW_MBESW127_SHIFT                (31U)
#define STCU_MBESW_MBESW127_WIDTH                (1U)
#define STCU_MBESW_MBESW127(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW127_SHIFT)) & STCU_MBESW_MBESW127_MASK)

#define STCU_MBESW_MBESW128_MASK                 (0x1U)
#define STCU_MBESW_MBESW128_SHIFT                (0U)
#define STCU_MBESW_MBESW128_WIDTH                (1U)
#define STCU_MBESW_MBESW128(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW128_SHIFT)) & STCU_MBESW_MBESW128_MASK)

#define STCU_MBESW_MBESW129_MASK                 (0x2U)
#define STCU_MBESW_MBESW129_SHIFT                (1U)
#define STCU_MBESW_MBESW129_WIDTH                (1U)
#define STCU_MBESW_MBESW129(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW129_SHIFT)) & STCU_MBESW_MBESW129_MASK)

#define STCU_MBESW_MBESW130_MASK                 (0x4U)
#define STCU_MBESW_MBESW130_SHIFT                (2U)
#define STCU_MBESW_MBESW130_WIDTH                (1U)
#define STCU_MBESW_MBESW130(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW130_SHIFT)) & STCU_MBESW_MBESW130_MASK)

#define STCU_MBESW_MBESW131_MASK                 (0x8U)
#define STCU_MBESW_MBESW131_SHIFT                (3U)
#define STCU_MBESW_MBESW131_WIDTH                (1U)
#define STCU_MBESW_MBESW131(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW131_SHIFT)) & STCU_MBESW_MBESW131_MASK)

#define STCU_MBESW_MBESW132_MASK                 (0x10U)
#define STCU_MBESW_MBESW132_SHIFT                (4U)
#define STCU_MBESW_MBESW132_WIDTH                (1U)
#define STCU_MBESW_MBESW132(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW132_SHIFT)) & STCU_MBESW_MBESW132_MASK)

#define STCU_MBESW_MBESW133_MASK                 (0x20U)
#define STCU_MBESW_MBESW133_SHIFT                (5U)
#define STCU_MBESW_MBESW133_WIDTH                (1U)
#define STCU_MBESW_MBESW133(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW133_SHIFT)) & STCU_MBESW_MBESW133_MASK)

#define STCU_MBESW_MBESW134_MASK                 (0x40U)
#define STCU_MBESW_MBESW134_SHIFT                (6U)
#define STCU_MBESW_MBESW134_WIDTH                (1U)
#define STCU_MBESW_MBESW134(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW134_SHIFT)) & STCU_MBESW_MBESW134_MASK)

#define STCU_MBESW_MBESW135_MASK                 (0x80U)
#define STCU_MBESW_MBESW135_SHIFT                (7U)
#define STCU_MBESW_MBESW135_WIDTH                (1U)
#define STCU_MBESW_MBESW135(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW135_SHIFT)) & STCU_MBESW_MBESW135_MASK)

#define STCU_MBESW_MBESW136_MASK                 (0x100U)
#define STCU_MBESW_MBESW136_SHIFT                (8U)
#define STCU_MBESW_MBESW136_WIDTH                (1U)
#define STCU_MBESW_MBESW136(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW136_SHIFT)) & STCU_MBESW_MBESW136_MASK)

#define STCU_MBESW_MBESW137_MASK                 (0x200U)
#define STCU_MBESW_MBESW137_SHIFT                (9U)
#define STCU_MBESW_MBESW137_WIDTH                (1U)
#define STCU_MBESW_MBESW137(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW137_SHIFT)) & STCU_MBESW_MBESW137_MASK)

#define STCU_MBESW_MBESW138_MASK                 (0x400U)
#define STCU_MBESW_MBESW138_SHIFT                (10U)
#define STCU_MBESW_MBESW138_WIDTH                (1U)
#define STCU_MBESW_MBESW138(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW138_SHIFT)) & STCU_MBESW_MBESW138_MASK)

#define STCU_MBESW_MBESW139_MASK                 (0x800U)
#define STCU_MBESW_MBESW139_SHIFT                (11U)
#define STCU_MBESW_MBESW139_WIDTH                (1U)
#define STCU_MBESW_MBESW139(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW139_SHIFT)) & STCU_MBESW_MBESW139_MASK)

#define STCU_MBESW_MBESW140_MASK                 (0x1000U)
#define STCU_MBESW_MBESW140_SHIFT                (12U)
#define STCU_MBESW_MBESW140_WIDTH                (1U)
#define STCU_MBESW_MBESW140(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW140_SHIFT)) & STCU_MBESW_MBESW140_MASK)

#define STCU_MBESW_MBESW141_MASK                 (0x2000U)
#define STCU_MBESW_MBESW141_SHIFT                (13U)
#define STCU_MBESW_MBESW141_WIDTH                (1U)
#define STCU_MBESW_MBESW141(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW141_SHIFT)) & STCU_MBESW_MBESW141_MASK)

#define STCU_MBESW_MBESW142_MASK                 (0x4000U)
#define STCU_MBESW_MBESW142_SHIFT                (14U)
#define STCU_MBESW_MBESW142_WIDTH                (1U)
#define STCU_MBESW_MBESW142(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW142_SHIFT)) & STCU_MBESW_MBESW142_MASK)

#define STCU_MBESW_MBESW143_MASK                 (0x8000U)
#define STCU_MBESW_MBESW143_SHIFT                (15U)
#define STCU_MBESW_MBESW143_WIDTH                (1U)
#define STCU_MBESW_MBESW143(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW143_SHIFT)) & STCU_MBESW_MBESW143_MASK)

#define STCU_MBESW_MBESW144_MASK                 (0x10000U)
#define STCU_MBESW_MBESW144_SHIFT                (16U)
#define STCU_MBESW_MBESW144_WIDTH                (1U)
#define STCU_MBESW_MBESW144(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW144_SHIFT)) & STCU_MBESW_MBESW144_MASK)

#define STCU_MBESW_MBESW145_MASK                 (0x20000U)
#define STCU_MBESW_MBESW145_SHIFT                (17U)
#define STCU_MBESW_MBESW145_WIDTH                (1U)
#define STCU_MBESW_MBESW145(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW145_SHIFT)) & STCU_MBESW_MBESW145_MASK)

#define STCU_MBESW_MBESW146_MASK                 (0x40000U)
#define STCU_MBESW_MBESW146_SHIFT                (18U)
#define STCU_MBESW_MBESW146_WIDTH                (1U)
#define STCU_MBESW_MBESW146(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW146_SHIFT)) & STCU_MBESW_MBESW146_MASK)

#define STCU_MBESW_MBESW147_MASK                 (0x80000U)
#define STCU_MBESW_MBESW147_SHIFT                (19U)
#define STCU_MBESW_MBESW147_WIDTH                (1U)
#define STCU_MBESW_MBESW147(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW147_SHIFT)) & STCU_MBESW_MBESW147_MASK)

#define STCU_MBESW_MBESW148_MASK                 (0x100000U)
#define STCU_MBESW_MBESW148_SHIFT                (20U)
#define STCU_MBESW_MBESW148_WIDTH                (1U)
#define STCU_MBESW_MBESW148(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW148_SHIFT)) & STCU_MBESW_MBESW148_MASK)

#define STCU_MBESW_MBESW149_MASK                 (0x200000U)
#define STCU_MBESW_MBESW149_SHIFT                (21U)
#define STCU_MBESW_MBESW149_WIDTH                (1U)
#define STCU_MBESW_MBESW149(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW149_SHIFT)) & STCU_MBESW_MBESW149_MASK)

#define STCU_MBESW_MBESW150_MASK                 (0x400000U)
#define STCU_MBESW_MBESW150_SHIFT                (22U)
#define STCU_MBESW_MBESW150_WIDTH                (1U)
#define STCU_MBESW_MBESW150(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW150_SHIFT)) & STCU_MBESW_MBESW150_MASK)

#define STCU_MBESW_MBESW151_MASK                 (0x800000U)
#define STCU_MBESW_MBESW151_SHIFT                (23U)
#define STCU_MBESW_MBESW151_WIDTH                (1U)
#define STCU_MBESW_MBESW151(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW151_SHIFT)) & STCU_MBESW_MBESW151_MASK)

#define STCU_MBESW_MBESW152_MASK                 (0x1000000U)
#define STCU_MBESW_MBESW152_SHIFT                (24U)
#define STCU_MBESW_MBESW152_WIDTH                (1U)
#define STCU_MBESW_MBESW152(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW152_SHIFT)) & STCU_MBESW_MBESW152_MASK)

#define STCU_MBESW_MBESW153_MASK                 (0x2000000U)
#define STCU_MBESW_MBESW153_SHIFT                (25U)
#define STCU_MBESW_MBESW153_WIDTH                (1U)
#define STCU_MBESW_MBESW153(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW153_SHIFT)) & STCU_MBESW_MBESW153_MASK)

#define STCU_MBESW_MBESW154_MASK                 (0x4000000U)
#define STCU_MBESW_MBESW154_SHIFT                (26U)
#define STCU_MBESW_MBESW154_WIDTH                (1U)
#define STCU_MBESW_MBESW154(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW154_SHIFT)) & STCU_MBESW_MBESW154_MASK)

#define STCU_MBESW_MBESW155_MASK                 (0x8000000U)
#define STCU_MBESW_MBESW155_SHIFT                (27U)
#define STCU_MBESW_MBESW155_WIDTH                (1U)
#define STCU_MBESW_MBESW155(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW155_SHIFT)) & STCU_MBESW_MBESW155_MASK)

#define STCU_MBESW_MBESW156_MASK                 (0x10000000U)
#define STCU_MBESW_MBESW156_SHIFT                (28U)
#define STCU_MBESW_MBESW156_WIDTH                (1U)
#define STCU_MBESW_MBESW156(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW156_SHIFT)) & STCU_MBESW_MBESW156_MASK)

#define STCU_MBESW_MBESW157_MASK                 (0x20000000U)
#define STCU_MBESW_MBESW157_SHIFT                (29U)
#define STCU_MBESW_MBESW157_WIDTH                (1U)
#define STCU_MBESW_MBESW157(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW157_SHIFT)) & STCU_MBESW_MBESW157_MASK)

#define STCU_MBESW_MBESW158_MASK                 (0x40000000U)
#define STCU_MBESW_MBESW158_SHIFT                (30U)
#define STCU_MBESW_MBESW158_WIDTH                (1U)
#define STCU_MBESW_MBESW158(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW158_SHIFT)) & STCU_MBESW_MBESW158_MASK)

#define STCU_MBESW_MBESW159_MASK                 (0x80000000U)
#define STCU_MBESW_MBESW159_SHIFT                (31U)
#define STCU_MBESW_MBESW159_WIDTH                (1U)
#define STCU_MBESW_MBESW159(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW159_SHIFT)) & STCU_MBESW_MBESW159_MASK)

#define STCU_MBESW_MBESW160_MASK                 (0x1U)
#define STCU_MBESW_MBESW160_SHIFT                (0U)
#define STCU_MBESW_MBESW160_WIDTH                (1U)
#define STCU_MBESW_MBESW160(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW160_SHIFT)) & STCU_MBESW_MBESW160_MASK)

#define STCU_MBESW_MBESW161_MASK                 (0x2U)
#define STCU_MBESW_MBESW161_SHIFT                (1U)
#define STCU_MBESW_MBESW161_WIDTH                (1U)
#define STCU_MBESW_MBESW161(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW161_SHIFT)) & STCU_MBESW_MBESW161_MASK)

#define STCU_MBESW_MBESW162_MASK                 (0x4U)
#define STCU_MBESW_MBESW162_SHIFT                (2U)
#define STCU_MBESW_MBESW162_WIDTH                (1U)
#define STCU_MBESW_MBESW162(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW162_SHIFT)) & STCU_MBESW_MBESW162_MASK)

#define STCU_MBESW_MBESW163_MASK                 (0x8U)
#define STCU_MBESW_MBESW163_SHIFT                (3U)
#define STCU_MBESW_MBESW163_WIDTH                (1U)
#define STCU_MBESW_MBESW163(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW163_SHIFT)) & STCU_MBESW_MBESW163_MASK)

#define STCU_MBESW_MBESW164_MASK                 (0x10U)
#define STCU_MBESW_MBESW164_SHIFT                (4U)
#define STCU_MBESW_MBESW164_WIDTH                (1U)
#define STCU_MBESW_MBESW164(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW164_SHIFT)) & STCU_MBESW_MBESW164_MASK)

#define STCU_MBESW_MBESW165_MASK                 (0x20U)
#define STCU_MBESW_MBESW165_SHIFT                (5U)
#define STCU_MBESW_MBESW165_WIDTH                (1U)
#define STCU_MBESW_MBESW165(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW165_SHIFT)) & STCU_MBESW_MBESW165_MASK)

#define STCU_MBESW_MBESW166_MASK                 (0x40U)
#define STCU_MBESW_MBESW166_SHIFT                (6U)
#define STCU_MBESW_MBESW166_WIDTH                (1U)
#define STCU_MBESW_MBESW166(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW166_SHIFT)) & STCU_MBESW_MBESW166_MASK)

#define STCU_MBESW_MBESW167_MASK                 (0x80U)
#define STCU_MBESW_MBESW167_SHIFT                (7U)
#define STCU_MBESW_MBESW167_WIDTH                (1U)
#define STCU_MBESW_MBESW167(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW167_SHIFT)) & STCU_MBESW_MBESW167_MASK)

#define STCU_MBESW_MBESW168_MASK                 (0x100U)
#define STCU_MBESW_MBESW168_SHIFT                (8U)
#define STCU_MBESW_MBESW168_WIDTH                (1U)
#define STCU_MBESW_MBESW168(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW168_SHIFT)) & STCU_MBESW_MBESW168_MASK)

#define STCU_MBESW_MBESW169_MASK                 (0x200U)
#define STCU_MBESW_MBESW169_SHIFT                (9U)
#define STCU_MBESW_MBESW169_WIDTH                (1U)
#define STCU_MBESW_MBESW169(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW169_SHIFT)) & STCU_MBESW_MBESW169_MASK)

#define STCU_MBESW_MBESW170_MASK                 (0x400U)
#define STCU_MBESW_MBESW170_SHIFT                (10U)
#define STCU_MBESW_MBESW170_WIDTH                (1U)
#define STCU_MBESW_MBESW170(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW170_SHIFT)) & STCU_MBESW_MBESW170_MASK)

#define STCU_MBESW_MBESW171_MASK                 (0x800U)
#define STCU_MBESW_MBESW171_SHIFT                (11U)
#define STCU_MBESW_MBESW171_WIDTH                (1U)
#define STCU_MBESW_MBESW171(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW171_SHIFT)) & STCU_MBESW_MBESW171_MASK)

#define STCU_MBESW_MBESW172_MASK                 (0x1000U)
#define STCU_MBESW_MBESW172_SHIFT                (12U)
#define STCU_MBESW_MBESW172_WIDTH                (1U)
#define STCU_MBESW_MBESW172(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW172_SHIFT)) & STCU_MBESW_MBESW172_MASK)

#define STCU_MBESW_MBESW173_MASK                 (0x2000U)
#define STCU_MBESW_MBESW173_SHIFT                (13U)
#define STCU_MBESW_MBESW173_WIDTH                (1U)
#define STCU_MBESW_MBESW173(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW173_SHIFT)) & STCU_MBESW_MBESW173_MASK)

#define STCU_MBESW_MBESW174_MASK                 (0x4000U)
#define STCU_MBESW_MBESW174_SHIFT                (14U)
#define STCU_MBESW_MBESW174_WIDTH                (1U)
#define STCU_MBESW_MBESW174(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW174_SHIFT)) & STCU_MBESW_MBESW174_MASK)

#define STCU_MBESW_MBESW175_MASK                 (0x8000U)
#define STCU_MBESW_MBESW175_SHIFT                (15U)
#define STCU_MBESW_MBESW175_WIDTH                (1U)
#define STCU_MBESW_MBESW175(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW175_SHIFT)) & STCU_MBESW_MBESW175_MASK)

#define STCU_MBESW_MBESW176_MASK                 (0x10000U)
#define STCU_MBESW_MBESW176_SHIFT                (16U)
#define STCU_MBESW_MBESW176_WIDTH                (1U)
#define STCU_MBESW_MBESW176(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW176_SHIFT)) & STCU_MBESW_MBESW176_MASK)

#define STCU_MBESW_MBESW177_MASK                 (0x20000U)
#define STCU_MBESW_MBESW177_SHIFT                (17U)
#define STCU_MBESW_MBESW177_WIDTH                (1U)
#define STCU_MBESW_MBESW177(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW177_SHIFT)) & STCU_MBESW_MBESW177_MASK)

#define STCU_MBESW_MBESW178_MASK                 (0x40000U)
#define STCU_MBESW_MBESW178_SHIFT                (18U)
#define STCU_MBESW_MBESW178_WIDTH                (1U)
#define STCU_MBESW_MBESW178(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW178_SHIFT)) & STCU_MBESW_MBESW178_MASK)

#define STCU_MBESW_MBESW179_MASK                 (0x80000U)
#define STCU_MBESW_MBESW179_SHIFT                (19U)
#define STCU_MBESW_MBESW179_WIDTH                (1U)
#define STCU_MBESW_MBESW179(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW179_SHIFT)) & STCU_MBESW_MBESW179_MASK)

#define STCU_MBESW_MBESW180_MASK                 (0x100000U)
#define STCU_MBESW_MBESW180_SHIFT                (20U)
#define STCU_MBESW_MBESW180_WIDTH                (1U)
#define STCU_MBESW_MBESW180(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW180_SHIFT)) & STCU_MBESW_MBESW180_MASK)

#define STCU_MBESW_MBESW181_MASK                 (0x200000U)
#define STCU_MBESW_MBESW181_SHIFT                (21U)
#define STCU_MBESW_MBESW181_WIDTH                (1U)
#define STCU_MBESW_MBESW181(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW181_SHIFT)) & STCU_MBESW_MBESW181_MASK)

#define STCU_MBESW_MBESW182_MASK                 (0x400000U)
#define STCU_MBESW_MBESW182_SHIFT                (22U)
#define STCU_MBESW_MBESW182_WIDTH                (1U)
#define STCU_MBESW_MBESW182(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW182_SHIFT)) & STCU_MBESW_MBESW182_MASK)

#define STCU_MBESW_MBESW183_MASK                 (0x800000U)
#define STCU_MBESW_MBESW183_SHIFT                (23U)
#define STCU_MBESW_MBESW183_WIDTH                (1U)
#define STCU_MBESW_MBESW183(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW183_SHIFT)) & STCU_MBESW_MBESW183_MASK)

#define STCU_MBESW_MBESW184_MASK                 (0x1000000U)
#define STCU_MBESW_MBESW184_SHIFT                (24U)
#define STCU_MBESW_MBESW184_WIDTH                (1U)
#define STCU_MBESW_MBESW184(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW184_SHIFT)) & STCU_MBESW_MBESW184_MASK)

#define STCU_MBESW_MBESW185_MASK                 (0x2000000U)
#define STCU_MBESW_MBESW185_SHIFT                (25U)
#define STCU_MBESW_MBESW185_WIDTH                (1U)
#define STCU_MBESW_MBESW185(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW185_SHIFT)) & STCU_MBESW_MBESW185_MASK)

#define STCU_MBESW_MBESW186_MASK                 (0x4000000U)
#define STCU_MBESW_MBESW186_SHIFT                (26U)
#define STCU_MBESW_MBESW186_WIDTH                (1U)
#define STCU_MBESW_MBESW186(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW186_SHIFT)) & STCU_MBESW_MBESW186_MASK)

#define STCU_MBESW_MBESW187_MASK                 (0x8000000U)
#define STCU_MBESW_MBESW187_SHIFT                (27U)
#define STCU_MBESW_MBESW187_WIDTH                (1U)
#define STCU_MBESW_MBESW187(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW187_SHIFT)) & STCU_MBESW_MBESW187_MASK)

#define STCU_MBESW_MBESW188_MASK                 (0x10000000U)
#define STCU_MBESW_MBESW188_SHIFT                (28U)
#define STCU_MBESW_MBESW188_WIDTH                (1U)
#define STCU_MBESW_MBESW188(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW188_SHIFT)) & STCU_MBESW_MBESW188_MASK)

#define STCU_MBESW_MBESW189_MASK                 (0x20000000U)
#define STCU_MBESW_MBESW189_SHIFT                (29U)
#define STCU_MBESW_MBESW189_WIDTH                (1U)
#define STCU_MBESW_MBESW189(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW189_SHIFT)) & STCU_MBESW_MBESW189_MASK)

#define STCU_MBESW_MBESW190_MASK                 (0x40000000U)
#define STCU_MBESW_MBESW190_SHIFT                (30U)
#define STCU_MBESW_MBESW190_WIDTH                (1U)
#define STCU_MBESW_MBESW190(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW190_SHIFT)) & STCU_MBESW_MBESW190_MASK)

#define STCU_MBESW_MBESW191_MASK                 (0x80000000U)
#define STCU_MBESW_MBESW191_SHIFT                (31U)
#define STCU_MBESW_MBESW191_WIDTH                (1U)
#define STCU_MBESW_MBESW191(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW191_SHIFT)) & STCU_MBESW_MBESW191_MASK)

#define STCU_MBESW_MBESW192_MASK                 (0x1U)
#define STCU_MBESW_MBESW192_SHIFT                (0U)
#define STCU_MBESW_MBESW192_WIDTH                (1U)
#define STCU_MBESW_MBESW192(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW192_SHIFT)) & STCU_MBESW_MBESW192_MASK)

#define STCU_MBESW_MBESW193_MASK                 (0x2U)
#define STCU_MBESW_MBESW193_SHIFT                (1U)
#define STCU_MBESW_MBESW193_WIDTH                (1U)
#define STCU_MBESW_MBESW193(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW193_SHIFT)) & STCU_MBESW_MBESW193_MASK)

#define STCU_MBESW_MBESW194_MASK                 (0x4U)
#define STCU_MBESW_MBESW194_SHIFT                (2U)
#define STCU_MBESW_MBESW194_WIDTH                (1U)
#define STCU_MBESW_MBESW194(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW194_SHIFT)) & STCU_MBESW_MBESW194_MASK)

#define STCU_MBESW_MBESW195_MASK                 (0x8U)
#define STCU_MBESW_MBESW195_SHIFT                (3U)
#define STCU_MBESW_MBESW195_WIDTH                (1U)
#define STCU_MBESW_MBESW195(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW195_SHIFT)) & STCU_MBESW_MBESW195_MASK)

#define STCU_MBESW_MBESW196_MASK                 (0x10U)
#define STCU_MBESW_MBESW196_SHIFT                (4U)
#define STCU_MBESW_MBESW196_WIDTH                (1U)
#define STCU_MBESW_MBESW196(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW196_SHIFT)) & STCU_MBESW_MBESW196_MASK)

#define STCU_MBESW_MBESW197_MASK                 (0x20U)
#define STCU_MBESW_MBESW197_SHIFT                (5U)
#define STCU_MBESW_MBESW197_WIDTH                (1U)
#define STCU_MBESW_MBESW197(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW197_SHIFT)) & STCU_MBESW_MBESW197_MASK)

#define STCU_MBESW_MBESW198_MASK                 (0x40U)
#define STCU_MBESW_MBESW198_SHIFT                (6U)
#define STCU_MBESW_MBESW198_WIDTH                (1U)
#define STCU_MBESW_MBESW198(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW198_SHIFT)) & STCU_MBESW_MBESW198_MASK)

#define STCU_MBESW_MBESW199_MASK                 (0x80U)
#define STCU_MBESW_MBESW199_SHIFT                (7U)
#define STCU_MBESW_MBESW199_WIDTH                (1U)
#define STCU_MBESW_MBESW199(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW199_SHIFT)) & STCU_MBESW_MBESW199_MASK)

#define STCU_MBESW_MBESW200_MASK                 (0x100U)
#define STCU_MBESW_MBESW200_SHIFT                (8U)
#define STCU_MBESW_MBESW200_WIDTH                (1U)
#define STCU_MBESW_MBESW200(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW200_SHIFT)) & STCU_MBESW_MBESW200_MASK)

#define STCU_MBESW_MBESW201_MASK                 (0x200U)
#define STCU_MBESW_MBESW201_SHIFT                (9U)
#define STCU_MBESW_MBESW201_WIDTH                (1U)
#define STCU_MBESW_MBESW201(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW201_SHIFT)) & STCU_MBESW_MBESW201_MASK)

#define STCU_MBESW_MBESW202_MASK                 (0x400U)
#define STCU_MBESW_MBESW202_SHIFT                (10U)
#define STCU_MBESW_MBESW202_WIDTH                (1U)
#define STCU_MBESW_MBESW202(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW202_SHIFT)) & STCU_MBESW_MBESW202_MASK)

#define STCU_MBESW_MBESW203_MASK                 (0x800U)
#define STCU_MBESW_MBESW203_SHIFT                (11U)
#define STCU_MBESW_MBESW203_WIDTH                (1U)
#define STCU_MBESW_MBESW203(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW203_SHIFT)) & STCU_MBESW_MBESW203_MASK)

#define STCU_MBESW_MBESW204_MASK                 (0x1000U)
#define STCU_MBESW_MBESW204_SHIFT                (12U)
#define STCU_MBESW_MBESW204_WIDTH                (1U)
#define STCU_MBESW_MBESW204(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW204_SHIFT)) & STCU_MBESW_MBESW204_MASK)

#define STCU_MBESW_MBESW205_MASK                 (0x2000U)
#define STCU_MBESW_MBESW205_SHIFT                (13U)
#define STCU_MBESW_MBESW205_WIDTH                (1U)
#define STCU_MBESW_MBESW205(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW205_SHIFT)) & STCU_MBESW_MBESW205_MASK)

#define STCU_MBESW_MBESW206_MASK                 (0x4000U)
#define STCU_MBESW_MBESW206_SHIFT                (14U)
#define STCU_MBESW_MBESW206_WIDTH                (1U)
#define STCU_MBESW_MBESW206(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW206_SHIFT)) & STCU_MBESW_MBESW206_MASK)

#define STCU_MBESW_MBESW207_MASK                 (0x8000U)
#define STCU_MBESW_MBESW207_SHIFT                (15U)
#define STCU_MBESW_MBESW207_WIDTH                (1U)
#define STCU_MBESW_MBESW207(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW207_SHIFT)) & STCU_MBESW_MBESW207_MASK)

#define STCU_MBESW_MBESW208_MASK                 (0x10000U)
#define STCU_MBESW_MBESW208_SHIFT                (16U)
#define STCU_MBESW_MBESW208_WIDTH                (1U)
#define STCU_MBESW_MBESW208(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW208_SHIFT)) & STCU_MBESW_MBESW208_MASK)

#define STCU_MBESW_MBESW209_MASK                 (0x20000U)
#define STCU_MBESW_MBESW209_SHIFT                (17U)
#define STCU_MBESW_MBESW209_WIDTH                (1U)
#define STCU_MBESW_MBESW209(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW209_SHIFT)) & STCU_MBESW_MBESW209_MASK)

#define STCU_MBESW_MBESW210_MASK                 (0x40000U)
#define STCU_MBESW_MBESW210_SHIFT                (18U)
#define STCU_MBESW_MBESW210_WIDTH                (1U)
#define STCU_MBESW_MBESW210(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW210_SHIFT)) & STCU_MBESW_MBESW210_MASK)

#define STCU_MBESW_MBESW211_MASK                 (0x80000U)
#define STCU_MBESW_MBESW211_SHIFT                (19U)
#define STCU_MBESW_MBESW211_WIDTH                (1U)
#define STCU_MBESW_MBESW211(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW211_SHIFT)) & STCU_MBESW_MBESW211_MASK)

#define STCU_MBESW_MBESW212_MASK                 (0x100000U)
#define STCU_MBESW_MBESW212_SHIFT                (20U)
#define STCU_MBESW_MBESW212_WIDTH                (1U)
#define STCU_MBESW_MBESW212(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW212_SHIFT)) & STCU_MBESW_MBESW212_MASK)

#define STCU_MBESW_MBESW213_MASK                 (0x200000U)
#define STCU_MBESW_MBESW213_SHIFT                (21U)
#define STCU_MBESW_MBESW213_WIDTH                (1U)
#define STCU_MBESW_MBESW213(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW213_SHIFT)) & STCU_MBESW_MBESW213_MASK)

#define STCU_MBESW_MBESW214_MASK                 (0x400000U)
#define STCU_MBESW_MBESW214_SHIFT                (22U)
#define STCU_MBESW_MBESW214_WIDTH                (1U)
#define STCU_MBESW_MBESW214(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW214_SHIFT)) & STCU_MBESW_MBESW214_MASK)

#define STCU_MBESW_MBESW215_MASK                 (0x800000U)
#define STCU_MBESW_MBESW215_SHIFT                (23U)
#define STCU_MBESW_MBESW215_WIDTH                (1U)
#define STCU_MBESW_MBESW215(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW215_SHIFT)) & STCU_MBESW_MBESW215_MASK)

#define STCU_MBESW_MBESW216_MASK                 (0x1000000U)
#define STCU_MBESW_MBESW216_SHIFT                (24U)
#define STCU_MBESW_MBESW216_WIDTH                (1U)
#define STCU_MBESW_MBESW216(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW216_SHIFT)) & STCU_MBESW_MBESW216_MASK)

#define STCU_MBESW_MBESW217_MASK                 (0x2000000U)
#define STCU_MBESW_MBESW217_SHIFT                (25U)
#define STCU_MBESW_MBESW217_WIDTH                (1U)
#define STCU_MBESW_MBESW217(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW217_SHIFT)) & STCU_MBESW_MBESW217_MASK)

#define STCU_MBESW_MBESW218_MASK                 (0x4000000U)
#define STCU_MBESW_MBESW218_SHIFT                (26U)
#define STCU_MBESW_MBESW218_WIDTH                (1U)
#define STCU_MBESW_MBESW218(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW218_SHIFT)) & STCU_MBESW_MBESW218_MASK)

#define STCU_MBESW_MBESW219_MASK                 (0x8000000U)
#define STCU_MBESW_MBESW219_SHIFT                (27U)
#define STCU_MBESW_MBESW219_WIDTH                (1U)
#define STCU_MBESW_MBESW219(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW219_SHIFT)) & STCU_MBESW_MBESW219_MASK)

#define STCU_MBESW_MBESW220_MASK                 (0x10000000U)
#define STCU_MBESW_MBESW220_SHIFT                (28U)
#define STCU_MBESW_MBESW220_WIDTH                (1U)
#define STCU_MBESW_MBESW220(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW220_SHIFT)) & STCU_MBESW_MBESW220_MASK)

#define STCU_MBESW_MBESW221_MASK                 (0x20000000U)
#define STCU_MBESW_MBESW221_SHIFT                (29U)
#define STCU_MBESW_MBESW221_WIDTH                (1U)
#define STCU_MBESW_MBESW221(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW221_SHIFT)) & STCU_MBESW_MBESW221_MASK)

#define STCU_MBESW_MBESW222_MASK                 (0x40000000U)
#define STCU_MBESW_MBESW222_SHIFT                (30U)
#define STCU_MBESW_MBESW222_WIDTH                (1U)
#define STCU_MBESW_MBESW222(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW222_SHIFT)) & STCU_MBESW_MBESW222_MASK)

#define STCU_MBESW_MBESW223_MASK                 (0x80000000U)
#define STCU_MBESW_MBESW223_SHIFT                (31U)
#define STCU_MBESW_MBESW223_WIDTH                (1U)
#define STCU_MBESW_MBESW223(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW223_SHIFT)) & STCU_MBESW_MBESW223_MASK)

#define STCU_MBESW_MBESW224_MASK                 (0x1U)
#define STCU_MBESW_MBESW224_SHIFT                (0U)
#define STCU_MBESW_MBESW224_WIDTH                (1U)
#define STCU_MBESW_MBESW224(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW224_SHIFT)) & STCU_MBESW_MBESW224_MASK)

#define STCU_MBESW_MBESW225_MASK                 (0x2U)
#define STCU_MBESW_MBESW225_SHIFT                (1U)
#define STCU_MBESW_MBESW225_WIDTH                (1U)
#define STCU_MBESW_MBESW225(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW225_SHIFT)) & STCU_MBESW_MBESW225_MASK)

#define STCU_MBESW_MBESW226_MASK                 (0x4U)
#define STCU_MBESW_MBESW226_SHIFT                (2U)
#define STCU_MBESW_MBESW226_WIDTH                (1U)
#define STCU_MBESW_MBESW226(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW226_SHIFT)) & STCU_MBESW_MBESW226_MASK)

#define STCU_MBESW_MBESW227_MASK                 (0x8U)
#define STCU_MBESW_MBESW227_SHIFT                (3U)
#define STCU_MBESW_MBESW227_WIDTH                (1U)
#define STCU_MBESW_MBESW227(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW227_SHIFT)) & STCU_MBESW_MBESW227_MASK)

#define STCU_MBESW_MBESW228_MASK                 (0x10U)
#define STCU_MBESW_MBESW228_SHIFT                (4U)
#define STCU_MBESW_MBESW228_WIDTH                (1U)
#define STCU_MBESW_MBESW228(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW228_SHIFT)) & STCU_MBESW_MBESW228_MASK)

#define STCU_MBESW_MBESW229_MASK                 (0x20U)
#define STCU_MBESW_MBESW229_SHIFT                (5U)
#define STCU_MBESW_MBESW229_WIDTH                (1U)
#define STCU_MBESW_MBESW229(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW229_SHIFT)) & STCU_MBESW_MBESW229_MASK)

#define STCU_MBESW_MBESW230_MASK                 (0x40U)
#define STCU_MBESW_MBESW230_SHIFT                (6U)
#define STCU_MBESW_MBESW230_WIDTH                (1U)
#define STCU_MBESW_MBESW230(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW230_SHIFT)) & STCU_MBESW_MBESW230_MASK)

#define STCU_MBESW_MBESW231_MASK                 (0x80U)
#define STCU_MBESW_MBESW231_SHIFT                (7U)
#define STCU_MBESW_MBESW231_WIDTH                (1U)
#define STCU_MBESW_MBESW231(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW231_SHIFT)) & STCU_MBESW_MBESW231_MASK)

#define STCU_MBESW_MBESW232_MASK                 (0x100U)
#define STCU_MBESW_MBESW232_SHIFT                (8U)
#define STCU_MBESW_MBESW232_WIDTH                (1U)
#define STCU_MBESW_MBESW232(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW232_SHIFT)) & STCU_MBESW_MBESW232_MASK)

#define STCU_MBESW_MBESW233_MASK                 (0x200U)
#define STCU_MBESW_MBESW233_SHIFT                (9U)
#define STCU_MBESW_MBESW233_WIDTH                (1U)
#define STCU_MBESW_MBESW233(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW233_SHIFT)) & STCU_MBESW_MBESW233_MASK)

#define STCU_MBESW_MBESW234_MASK                 (0x400U)
#define STCU_MBESW_MBESW234_SHIFT                (10U)
#define STCU_MBESW_MBESW234_WIDTH                (1U)
#define STCU_MBESW_MBESW234(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW234_SHIFT)) & STCU_MBESW_MBESW234_MASK)

#define STCU_MBESW_MBESW235_MASK                 (0x800U)
#define STCU_MBESW_MBESW235_SHIFT                (11U)
#define STCU_MBESW_MBESW235_WIDTH                (1U)
#define STCU_MBESW_MBESW235(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW235_SHIFT)) & STCU_MBESW_MBESW235_MASK)

#define STCU_MBESW_MBESW236_MASK                 (0x1000U)
#define STCU_MBESW_MBESW236_SHIFT                (12U)
#define STCU_MBESW_MBESW236_WIDTH                (1U)
#define STCU_MBESW_MBESW236(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW236_SHIFT)) & STCU_MBESW_MBESW236_MASK)

#define STCU_MBESW_MBESW237_MASK                 (0x2000U)
#define STCU_MBESW_MBESW237_SHIFT                (13U)
#define STCU_MBESW_MBESW237_WIDTH                (1U)
#define STCU_MBESW_MBESW237(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW237_SHIFT)) & STCU_MBESW_MBESW237_MASK)

#define STCU_MBESW_MBESW238_MASK                 (0x4000U)
#define STCU_MBESW_MBESW238_SHIFT                (14U)
#define STCU_MBESW_MBESW238_WIDTH                (1U)
#define STCU_MBESW_MBESW238(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW238_SHIFT)) & STCU_MBESW_MBESW238_MASK)

#define STCU_MBESW_MBESW239_MASK                 (0x8000U)
#define STCU_MBESW_MBESW239_SHIFT                (15U)
#define STCU_MBESW_MBESW239_WIDTH                (1U)
#define STCU_MBESW_MBESW239(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW239_SHIFT)) & STCU_MBESW_MBESW239_MASK)

#define STCU_MBESW_MBESW240_MASK                 (0x10000U)
#define STCU_MBESW_MBESW240_SHIFT                (16U)
#define STCU_MBESW_MBESW240_WIDTH                (1U)
#define STCU_MBESW_MBESW240(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW240_SHIFT)) & STCU_MBESW_MBESW240_MASK)

#define STCU_MBESW_MBESW241_MASK                 (0x20000U)
#define STCU_MBESW_MBESW241_SHIFT                (17U)
#define STCU_MBESW_MBESW241_WIDTH                (1U)
#define STCU_MBESW_MBESW241(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW241_SHIFT)) & STCU_MBESW_MBESW241_MASK)

#define STCU_MBESW_MBESW242_MASK                 (0x40000U)
#define STCU_MBESW_MBESW242_SHIFT                (18U)
#define STCU_MBESW_MBESW242_WIDTH                (1U)
#define STCU_MBESW_MBESW242(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW242_SHIFT)) & STCU_MBESW_MBESW242_MASK)

#define STCU_MBESW_MBESW243_MASK                 (0x80000U)
#define STCU_MBESW_MBESW243_SHIFT                (19U)
#define STCU_MBESW_MBESW243_WIDTH                (1U)
#define STCU_MBESW_MBESW243(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW243_SHIFT)) & STCU_MBESW_MBESW243_MASK)

#define STCU_MBESW_MBESW244_MASK                 (0x100000U)
#define STCU_MBESW_MBESW244_SHIFT                (20U)
#define STCU_MBESW_MBESW244_WIDTH                (1U)
#define STCU_MBESW_MBESW244(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW244_SHIFT)) & STCU_MBESW_MBESW244_MASK)

#define STCU_MBESW_MBESW245_MASK                 (0x200000U)
#define STCU_MBESW_MBESW245_SHIFT                (21U)
#define STCU_MBESW_MBESW245_WIDTH                (1U)
#define STCU_MBESW_MBESW245(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW245_SHIFT)) & STCU_MBESW_MBESW245_MASK)

#define STCU_MBESW_MBESW246_MASK                 (0x400000U)
#define STCU_MBESW_MBESW246_SHIFT                (22U)
#define STCU_MBESW_MBESW246_WIDTH                (1U)
#define STCU_MBESW_MBESW246(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW246_SHIFT)) & STCU_MBESW_MBESW246_MASK)

#define STCU_MBESW_MBESW247_MASK                 (0x800000U)
#define STCU_MBESW_MBESW247_SHIFT                (23U)
#define STCU_MBESW_MBESW247_WIDTH                (1U)
#define STCU_MBESW_MBESW247(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW247_SHIFT)) & STCU_MBESW_MBESW247_MASK)

#define STCU_MBESW_MBESW248_MASK                 (0x1000000U)
#define STCU_MBESW_MBESW248_SHIFT                (24U)
#define STCU_MBESW_MBESW248_WIDTH                (1U)
#define STCU_MBESW_MBESW248(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW248_SHIFT)) & STCU_MBESW_MBESW248_MASK)

#define STCU_MBESW_MBESW249_MASK                 (0x2000000U)
#define STCU_MBESW_MBESW249_SHIFT                (25U)
#define STCU_MBESW_MBESW249_WIDTH                (1U)
#define STCU_MBESW_MBESW249(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW249_SHIFT)) & STCU_MBESW_MBESW249_MASK)

#define STCU_MBESW_MBESW250_MASK                 (0x4000000U)
#define STCU_MBESW_MBESW250_SHIFT                (26U)
#define STCU_MBESW_MBESW250_WIDTH                (1U)
#define STCU_MBESW_MBESW250(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW250_SHIFT)) & STCU_MBESW_MBESW250_MASK)

#define STCU_MBESW_MBESW251_MASK                 (0x8000000U)
#define STCU_MBESW_MBESW251_SHIFT                (27U)
#define STCU_MBESW_MBESW251_WIDTH                (1U)
#define STCU_MBESW_MBESW251(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW251_SHIFT)) & STCU_MBESW_MBESW251_MASK)

#define STCU_MBESW_MBESW252_MASK                 (0x10000000U)
#define STCU_MBESW_MBESW252_SHIFT                (28U)
#define STCU_MBESW_MBESW252_WIDTH                (1U)
#define STCU_MBESW_MBESW252(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW252_SHIFT)) & STCU_MBESW_MBESW252_MASK)

#define STCU_MBESW_MBESW253_MASK                 (0x20000000U)
#define STCU_MBESW_MBESW253_SHIFT                (29U)
#define STCU_MBESW_MBESW253_WIDTH                (1U)
#define STCU_MBESW_MBESW253(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW253_SHIFT)) & STCU_MBESW_MBESW253_MASK)

#define STCU_MBESW_MBESW254_MASK                 (0x40000000U)
#define STCU_MBESW_MBESW254_SHIFT                (30U)
#define STCU_MBESW_MBESW254_WIDTH                (1U)
#define STCU_MBESW_MBESW254(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW254_SHIFT)) & STCU_MBESW_MBESW254_MASK)

#define STCU_MBESW_MBESW255_MASK                 (0x80000000U)
#define STCU_MBESW_MBESW255_SHIFT                (31U)
#define STCU_MBESW_MBESW255_WIDTH                (1U)
#define STCU_MBESW_MBESW255(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW_MBESW255_SHIFT)) & STCU_MBESW_MBESW255_MASK)
/*! @} */

/*! @name MBUFM - STCU2 MBIST Unrecoverable FM */
/*! @{ */

#define STCU_MBUFM_MBUFM0_MASK                   (0x1U)
#define STCU_MBUFM_MBUFM0_SHIFT                  (0U)
#define STCU_MBUFM_MBUFM0_WIDTH                  (1U)
#define STCU_MBUFM_MBUFM0(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM0_SHIFT)) & STCU_MBUFM_MBUFM0_MASK)

#define STCU_MBUFM_MBUFM1_MASK                   (0x2U)
#define STCU_MBUFM_MBUFM1_SHIFT                  (1U)
#define STCU_MBUFM_MBUFM1_WIDTH                  (1U)
#define STCU_MBUFM_MBUFM1(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM1_SHIFT)) & STCU_MBUFM_MBUFM1_MASK)

#define STCU_MBUFM_MBUFM2_MASK                   (0x4U)
#define STCU_MBUFM_MBUFM2_SHIFT                  (2U)
#define STCU_MBUFM_MBUFM2_WIDTH                  (1U)
#define STCU_MBUFM_MBUFM2(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM2_SHIFT)) & STCU_MBUFM_MBUFM2_MASK)

#define STCU_MBUFM_MBUFM3_MASK                   (0x8U)
#define STCU_MBUFM_MBUFM3_SHIFT                  (3U)
#define STCU_MBUFM_MBUFM3_WIDTH                  (1U)
#define STCU_MBUFM_MBUFM3(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM3_SHIFT)) & STCU_MBUFM_MBUFM3_MASK)

#define STCU_MBUFM_MBUFM4_MASK                   (0x10U)
#define STCU_MBUFM_MBUFM4_SHIFT                  (4U)
#define STCU_MBUFM_MBUFM4_WIDTH                  (1U)
#define STCU_MBUFM_MBUFM4(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM4_SHIFT)) & STCU_MBUFM_MBUFM4_MASK)

#define STCU_MBUFM_MBUFM5_MASK                   (0x20U)
#define STCU_MBUFM_MBUFM5_SHIFT                  (5U)
#define STCU_MBUFM_MBUFM5_WIDTH                  (1U)
#define STCU_MBUFM_MBUFM5(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM5_SHIFT)) & STCU_MBUFM_MBUFM5_MASK)

#define STCU_MBUFM_MBUFM6_MASK                   (0x40U)
#define STCU_MBUFM_MBUFM6_SHIFT                  (6U)
#define STCU_MBUFM_MBUFM6_WIDTH                  (1U)
#define STCU_MBUFM_MBUFM6(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM6_SHIFT)) & STCU_MBUFM_MBUFM6_MASK)

#define STCU_MBUFM_MBUFM7_MASK                   (0x80U)
#define STCU_MBUFM_MBUFM7_SHIFT                  (7U)
#define STCU_MBUFM_MBUFM7_WIDTH                  (1U)
#define STCU_MBUFM_MBUFM7(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM7_SHIFT)) & STCU_MBUFM_MBUFM7_MASK)

#define STCU_MBUFM_MBUFM8_MASK                   (0x100U)
#define STCU_MBUFM_MBUFM8_SHIFT                  (8U)
#define STCU_MBUFM_MBUFM8_WIDTH                  (1U)
#define STCU_MBUFM_MBUFM8(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM8_SHIFT)) & STCU_MBUFM_MBUFM8_MASK)

#define STCU_MBUFM_MBUFM9_MASK                   (0x200U)
#define STCU_MBUFM_MBUFM9_SHIFT                  (9U)
#define STCU_MBUFM_MBUFM9_WIDTH                  (1U)
#define STCU_MBUFM_MBUFM9(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM9_SHIFT)) & STCU_MBUFM_MBUFM9_MASK)

#define STCU_MBUFM_MBUFM10_MASK                  (0x400U)
#define STCU_MBUFM_MBUFM10_SHIFT                 (10U)
#define STCU_MBUFM_MBUFM10_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM10(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM10_SHIFT)) & STCU_MBUFM_MBUFM10_MASK)

#define STCU_MBUFM_MBUFM11_MASK                  (0x800U)
#define STCU_MBUFM_MBUFM11_SHIFT                 (11U)
#define STCU_MBUFM_MBUFM11_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM11(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM11_SHIFT)) & STCU_MBUFM_MBUFM11_MASK)

#define STCU_MBUFM_MBUFM12_MASK                  (0x1000U)
#define STCU_MBUFM_MBUFM12_SHIFT                 (12U)
#define STCU_MBUFM_MBUFM12_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM12(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM12_SHIFT)) & STCU_MBUFM_MBUFM12_MASK)

#define STCU_MBUFM_MBUFM13_MASK                  (0x2000U)
#define STCU_MBUFM_MBUFM13_SHIFT                 (13U)
#define STCU_MBUFM_MBUFM13_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM13(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM13_SHIFT)) & STCU_MBUFM_MBUFM13_MASK)

#define STCU_MBUFM_MBUFM14_MASK                  (0x4000U)
#define STCU_MBUFM_MBUFM14_SHIFT                 (14U)
#define STCU_MBUFM_MBUFM14_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM14(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM14_SHIFT)) & STCU_MBUFM_MBUFM14_MASK)

#define STCU_MBUFM_MBUFM15_MASK                  (0x8000U)
#define STCU_MBUFM_MBUFM15_SHIFT                 (15U)
#define STCU_MBUFM_MBUFM15_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM15(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM15_SHIFT)) & STCU_MBUFM_MBUFM15_MASK)

#define STCU_MBUFM_MBUFM16_MASK                  (0x10000U)
#define STCU_MBUFM_MBUFM16_SHIFT                 (16U)
#define STCU_MBUFM_MBUFM16_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM16(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM16_SHIFT)) & STCU_MBUFM_MBUFM16_MASK)

#define STCU_MBUFM_MBUFM17_MASK                  (0x20000U)
#define STCU_MBUFM_MBUFM17_SHIFT                 (17U)
#define STCU_MBUFM_MBUFM17_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM17(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM17_SHIFT)) & STCU_MBUFM_MBUFM17_MASK)

#define STCU_MBUFM_MBUFM18_MASK                  (0x40000U)
#define STCU_MBUFM_MBUFM18_SHIFT                 (18U)
#define STCU_MBUFM_MBUFM18_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM18(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM18_SHIFT)) & STCU_MBUFM_MBUFM18_MASK)

#define STCU_MBUFM_MBUFM19_MASK                  (0x80000U)
#define STCU_MBUFM_MBUFM19_SHIFT                 (19U)
#define STCU_MBUFM_MBUFM19_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM19(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM19_SHIFT)) & STCU_MBUFM_MBUFM19_MASK)

#define STCU_MBUFM_MBUFM20_MASK                  (0x100000U)
#define STCU_MBUFM_MBUFM20_SHIFT                 (20U)
#define STCU_MBUFM_MBUFM20_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM20(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM20_SHIFT)) & STCU_MBUFM_MBUFM20_MASK)

#define STCU_MBUFM_MBUFM21_MASK                  (0x200000U)
#define STCU_MBUFM_MBUFM21_SHIFT                 (21U)
#define STCU_MBUFM_MBUFM21_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM21(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM21_SHIFT)) & STCU_MBUFM_MBUFM21_MASK)

#define STCU_MBUFM_MBUFM22_MASK                  (0x400000U)
#define STCU_MBUFM_MBUFM22_SHIFT                 (22U)
#define STCU_MBUFM_MBUFM22_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM22(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM22_SHIFT)) & STCU_MBUFM_MBUFM22_MASK)

#define STCU_MBUFM_MBUFM23_MASK                  (0x800000U)
#define STCU_MBUFM_MBUFM23_SHIFT                 (23U)
#define STCU_MBUFM_MBUFM23_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM23(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM23_SHIFT)) & STCU_MBUFM_MBUFM23_MASK)

#define STCU_MBUFM_MBUFM24_MASK                  (0x1000000U)
#define STCU_MBUFM_MBUFM24_SHIFT                 (24U)
#define STCU_MBUFM_MBUFM24_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM24(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM24_SHIFT)) & STCU_MBUFM_MBUFM24_MASK)

#define STCU_MBUFM_MBUFM25_MASK                  (0x2000000U)
#define STCU_MBUFM_MBUFM25_SHIFT                 (25U)
#define STCU_MBUFM_MBUFM25_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM25(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM25_SHIFT)) & STCU_MBUFM_MBUFM25_MASK)

#define STCU_MBUFM_MBUFM26_MASK                  (0x4000000U)
#define STCU_MBUFM_MBUFM26_SHIFT                 (26U)
#define STCU_MBUFM_MBUFM26_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM26(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM26_SHIFT)) & STCU_MBUFM_MBUFM26_MASK)

#define STCU_MBUFM_MBUFM27_MASK                  (0x8000000U)
#define STCU_MBUFM_MBUFM27_SHIFT                 (27U)
#define STCU_MBUFM_MBUFM27_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM27(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM27_SHIFT)) & STCU_MBUFM_MBUFM27_MASK)

#define STCU_MBUFM_MBUFM28_MASK                  (0x10000000U)
#define STCU_MBUFM_MBUFM28_SHIFT                 (28U)
#define STCU_MBUFM_MBUFM28_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM28(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM28_SHIFT)) & STCU_MBUFM_MBUFM28_MASK)

#define STCU_MBUFM_MBUFM29_MASK                  (0x20000000U)
#define STCU_MBUFM_MBUFM29_SHIFT                 (29U)
#define STCU_MBUFM_MBUFM29_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM29(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM29_SHIFT)) & STCU_MBUFM_MBUFM29_MASK)

#define STCU_MBUFM_MBUFM30_MASK                  (0x40000000U)
#define STCU_MBUFM_MBUFM30_SHIFT                 (30U)
#define STCU_MBUFM_MBUFM30_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM30(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM30_SHIFT)) & STCU_MBUFM_MBUFM30_MASK)

#define STCU_MBUFM_MBUFM31_MASK                  (0x80000000U)
#define STCU_MBUFM_MBUFM31_SHIFT                 (31U)
#define STCU_MBUFM_MBUFM31_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM31(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM31_SHIFT)) & STCU_MBUFM_MBUFM31_MASK)

#define STCU_MBUFM_MBUFM32_MASK                  (0x1U)
#define STCU_MBUFM_MBUFM32_SHIFT                 (0U)
#define STCU_MBUFM_MBUFM32_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM32(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM32_SHIFT)) & STCU_MBUFM_MBUFM32_MASK)

#define STCU_MBUFM_MBUFM33_MASK                  (0x2U)
#define STCU_MBUFM_MBUFM33_SHIFT                 (1U)
#define STCU_MBUFM_MBUFM33_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM33(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM33_SHIFT)) & STCU_MBUFM_MBUFM33_MASK)

#define STCU_MBUFM_MBUFM34_MASK                  (0x4U)
#define STCU_MBUFM_MBUFM34_SHIFT                 (2U)
#define STCU_MBUFM_MBUFM34_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM34(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM34_SHIFT)) & STCU_MBUFM_MBUFM34_MASK)

#define STCU_MBUFM_MBUFM35_MASK                  (0x8U)
#define STCU_MBUFM_MBUFM35_SHIFT                 (3U)
#define STCU_MBUFM_MBUFM35_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM35(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM35_SHIFT)) & STCU_MBUFM_MBUFM35_MASK)

#define STCU_MBUFM_MBUFM36_MASK                  (0x10U)
#define STCU_MBUFM_MBUFM36_SHIFT                 (4U)
#define STCU_MBUFM_MBUFM36_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM36(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM36_SHIFT)) & STCU_MBUFM_MBUFM36_MASK)

#define STCU_MBUFM_MBUFM37_MASK                  (0x20U)
#define STCU_MBUFM_MBUFM37_SHIFT                 (5U)
#define STCU_MBUFM_MBUFM37_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM37(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM37_SHIFT)) & STCU_MBUFM_MBUFM37_MASK)

#define STCU_MBUFM_MBUFM38_MASK                  (0x40U)
#define STCU_MBUFM_MBUFM38_SHIFT                 (6U)
#define STCU_MBUFM_MBUFM38_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM38(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM38_SHIFT)) & STCU_MBUFM_MBUFM38_MASK)

#define STCU_MBUFM_MBUFM39_MASK                  (0x80U)
#define STCU_MBUFM_MBUFM39_SHIFT                 (7U)
#define STCU_MBUFM_MBUFM39_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM39(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM39_SHIFT)) & STCU_MBUFM_MBUFM39_MASK)

#define STCU_MBUFM_MBUFM40_MASK                  (0x100U)
#define STCU_MBUFM_MBUFM40_SHIFT                 (8U)
#define STCU_MBUFM_MBUFM40_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM40(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM40_SHIFT)) & STCU_MBUFM_MBUFM40_MASK)

#define STCU_MBUFM_MBUFM41_MASK                  (0x200U)
#define STCU_MBUFM_MBUFM41_SHIFT                 (9U)
#define STCU_MBUFM_MBUFM41_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM41(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM41_SHIFT)) & STCU_MBUFM_MBUFM41_MASK)

#define STCU_MBUFM_MBUFM42_MASK                  (0x400U)
#define STCU_MBUFM_MBUFM42_SHIFT                 (10U)
#define STCU_MBUFM_MBUFM42_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM42(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM42_SHIFT)) & STCU_MBUFM_MBUFM42_MASK)

#define STCU_MBUFM_MBUFM43_MASK                  (0x800U)
#define STCU_MBUFM_MBUFM43_SHIFT                 (11U)
#define STCU_MBUFM_MBUFM43_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM43(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM43_SHIFT)) & STCU_MBUFM_MBUFM43_MASK)

#define STCU_MBUFM_MBUFM44_MASK                  (0x1000U)
#define STCU_MBUFM_MBUFM44_SHIFT                 (12U)
#define STCU_MBUFM_MBUFM44_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM44(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM44_SHIFT)) & STCU_MBUFM_MBUFM44_MASK)

#define STCU_MBUFM_MBUFM45_MASK                  (0x2000U)
#define STCU_MBUFM_MBUFM45_SHIFT                 (13U)
#define STCU_MBUFM_MBUFM45_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM45(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM45_SHIFT)) & STCU_MBUFM_MBUFM45_MASK)

#define STCU_MBUFM_MBUFM46_MASK                  (0x4000U)
#define STCU_MBUFM_MBUFM46_SHIFT                 (14U)
#define STCU_MBUFM_MBUFM46_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM46(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM46_SHIFT)) & STCU_MBUFM_MBUFM46_MASK)

#define STCU_MBUFM_MBUFM47_MASK                  (0x8000U)
#define STCU_MBUFM_MBUFM47_SHIFT                 (15U)
#define STCU_MBUFM_MBUFM47_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM47(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM47_SHIFT)) & STCU_MBUFM_MBUFM47_MASK)

#define STCU_MBUFM_MBUFM48_MASK                  (0x10000U)
#define STCU_MBUFM_MBUFM48_SHIFT                 (16U)
#define STCU_MBUFM_MBUFM48_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM48(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM48_SHIFT)) & STCU_MBUFM_MBUFM48_MASK)

#define STCU_MBUFM_MBUFM49_MASK                  (0x20000U)
#define STCU_MBUFM_MBUFM49_SHIFT                 (17U)
#define STCU_MBUFM_MBUFM49_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM49(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM49_SHIFT)) & STCU_MBUFM_MBUFM49_MASK)

#define STCU_MBUFM_MBUFM50_MASK                  (0x40000U)
#define STCU_MBUFM_MBUFM50_SHIFT                 (18U)
#define STCU_MBUFM_MBUFM50_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM50(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM50_SHIFT)) & STCU_MBUFM_MBUFM50_MASK)

#define STCU_MBUFM_MBUFM51_MASK                  (0x80000U)
#define STCU_MBUFM_MBUFM51_SHIFT                 (19U)
#define STCU_MBUFM_MBUFM51_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM51(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM51_SHIFT)) & STCU_MBUFM_MBUFM51_MASK)

#define STCU_MBUFM_MBUFM52_MASK                  (0x100000U)
#define STCU_MBUFM_MBUFM52_SHIFT                 (20U)
#define STCU_MBUFM_MBUFM52_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM52(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM52_SHIFT)) & STCU_MBUFM_MBUFM52_MASK)

#define STCU_MBUFM_MBUFM53_MASK                  (0x200000U)
#define STCU_MBUFM_MBUFM53_SHIFT                 (21U)
#define STCU_MBUFM_MBUFM53_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM53(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM53_SHIFT)) & STCU_MBUFM_MBUFM53_MASK)

#define STCU_MBUFM_MBUFM54_MASK                  (0x400000U)
#define STCU_MBUFM_MBUFM54_SHIFT                 (22U)
#define STCU_MBUFM_MBUFM54_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM54(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM54_SHIFT)) & STCU_MBUFM_MBUFM54_MASK)

#define STCU_MBUFM_MBUFM55_MASK                  (0x800000U)
#define STCU_MBUFM_MBUFM55_SHIFT                 (23U)
#define STCU_MBUFM_MBUFM55_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM55(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM55_SHIFT)) & STCU_MBUFM_MBUFM55_MASK)

#define STCU_MBUFM_MBUFM56_MASK                  (0x1000000U)
#define STCU_MBUFM_MBUFM56_SHIFT                 (24U)
#define STCU_MBUFM_MBUFM56_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM56(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM56_SHIFT)) & STCU_MBUFM_MBUFM56_MASK)

#define STCU_MBUFM_MBUFM57_MASK                  (0x2000000U)
#define STCU_MBUFM_MBUFM57_SHIFT                 (25U)
#define STCU_MBUFM_MBUFM57_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM57(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM57_SHIFT)) & STCU_MBUFM_MBUFM57_MASK)

#define STCU_MBUFM_MBUFM58_MASK                  (0x4000000U)
#define STCU_MBUFM_MBUFM58_SHIFT                 (26U)
#define STCU_MBUFM_MBUFM58_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM58(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM58_SHIFT)) & STCU_MBUFM_MBUFM58_MASK)

#define STCU_MBUFM_MBUFM59_MASK                  (0x8000000U)
#define STCU_MBUFM_MBUFM59_SHIFT                 (27U)
#define STCU_MBUFM_MBUFM59_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM59(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM59_SHIFT)) & STCU_MBUFM_MBUFM59_MASK)

#define STCU_MBUFM_MBUFM60_MASK                  (0x10000000U)
#define STCU_MBUFM_MBUFM60_SHIFT                 (28U)
#define STCU_MBUFM_MBUFM60_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM60(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM60_SHIFT)) & STCU_MBUFM_MBUFM60_MASK)

#define STCU_MBUFM_MBUFM61_MASK                  (0x20000000U)
#define STCU_MBUFM_MBUFM61_SHIFT                 (29U)
#define STCU_MBUFM_MBUFM61_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM61(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM61_SHIFT)) & STCU_MBUFM_MBUFM61_MASK)

#define STCU_MBUFM_MBUFM62_MASK                  (0x40000000U)
#define STCU_MBUFM_MBUFM62_SHIFT                 (30U)
#define STCU_MBUFM_MBUFM62_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM62(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM62_SHIFT)) & STCU_MBUFM_MBUFM62_MASK)

#define STCU_MBUFM_MBUFM63_MASK                  (0x80000000U)
#define STCU_MBUFM_MBUFM63_SHIFT                 (31U)
#define STCU_MBUFM_MBUFM63_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM63(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM63_SHIFT)) & STCU_MBUFM_MBUFM63_MASK)

#define STCU_MBUFM_MBUFM64_MASK                  (0x1U)
#define STCU_MBUFM_MBUFM64_SHIFT                 (0U)
#define STCU_MBUFM_MBUFM64_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM64(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM64_SHIFT)) & STCU_MBUFM_MBUFM64_MASK)

#define STCU_MBUFM_MBUFM65_MASK                  (0x2U)
#define STCU_MBUFM_MBUFM65_SHIFT                 (1U)
#define STCU_MBUFM_MBUFM65_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM65(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM65_SHIFT)) & STCU_MBUFM_MBUFM65_MASK)

#define STCU_MBUFM_MBUFM66_MASK                  (0x4U)
#define STCU_MBUFM_MBUFM66_SHIFT                 (2U)
#define STCU_MBUFM_MBUFM66_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM66(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM66_SHIFT)) & STCU_MBUFM_MBUFM66_MASK)

#define STCU_MBUFM_MBUFM67_MASK                  (0x8U)
#define STCU_MBUFM_MBUFM67_SHIFT                 (3U)
#define STCU_MBUFM_MBUFM67_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM67(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM67_SHIFT)) & STCU_MBUFM_MBUFM67_MASK)

#define STCU_MBUFM_MBUFM68_MASK                  (0x10U)
#define STCU_MBUFM_MBUFM68_SHIFT                 (4U)
#define STCU_MBUFM_MBUFM68_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM68(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM68_SHIFT)) & STCU_MBUFM_MBUFM68_MASK)

#define STCU_MBUFM_MBUFM69_MASK                  (0x20U)
#define STCU_MBUFM_MBUFM69_SHIFT                 (5U)
#define STCU_MBUFM_MBUFM69_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM69(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM69_SHIFT)) & STCU_MBUFM_MBUFM69_MASK)

#define STCU_MBUFM_MBUFM70_MASK                  (0x40U)
#define STCU_MBUFM_MBUFM70_SHIFT                 (6U)
#define STCU_MBUFM_MBUFM70_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM70(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM70_SHIFT)) & STCU_MBUFM_MBUFM70_MASK)

#define STCU_MBUFM_MBUFM71_MASK                  (0x80U)
#define STCU_MBUFM_MBUFM71_SHIFT                 (7U)
#define STCU_MBUFM_MBUFM71_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM71(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM71_SHIFT)) & STCU_MBUFM_MBUFM71_MASK)

#define STCU_MBUFM_MBUFM72_MASK                  (0x100U)
#define STCU_MBUFM_MBUFM72_SHIFT                 (8U)
#define STCU_MBUFM_MBUFM72_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM72(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM72_SHIFT)) & STCU_MBUFM_MBUFM72_MASK)

#define STCU_MBUFM_MBUFM73_MASK                  (0x200U)
#define STCU_MBUFM_MBUFM73_SHIFT                 (9U)
#define STCU_MBUFM_MBUFM73_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM73(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM73_SHIFT)) & STCU_MBUFM_MBUFM73_MASK)

#define STCU_MBUFM_MBUFM74_MASK                  (0x400U)
#define STCU_MBUFM_MBUFM74_SHIFT                 (10U)
#define STCU_MBUFM_MBUFM74_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM74(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM74_SHIFT)) & STCU_MBUFM_MBUFM74_MASK)

#define STCU_MBUFM_MBUFM75_MASK                  (0x800U)
#define STCU_MBUFM_MBUFM75_SHIFT                 (11U)
#define STCU_MBUFM_MBUFM75_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM75(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM75_SHIFT)) & STCU_MBUFM_MBUFM75_MASK)

#define STCU_MBUFM_MBUFM76_MASK                  (0x1000U)
#define STCU_MBUFM_MBUFM76_SHIFT                 (12U)
#define STCU_MBUFM_MBUFM76_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM76(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM76_SHIFT)) & STCU_MBUFM_MBUFM76_MASK)

#define STCU_MBUFM_MBUFM77_MASK                  (0x2000U)
#define STCU_MBUFM_MBUFM77_SHIFT                 (13U)
#define STCU_MBUFM_MBUFM77_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM77(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM77_SHIFT)) & STCU_MBUFM_MBUFM77_MASK)

#define STCU_MBUFM_MBUFM78_MASK                  (0x4000U)
#define STCU_MBUFM_MBUFM78_SHIFT                 (14U)
#define STCU_MBUFM_MBUFM78_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM78(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM78_SHIFT)) & STCU_MBUFM_MBUFM78_MASK)

#define STCU_MBUFM_MBUFM79_MASK                  (0x8000U)
#define STCU_MBUFM_MBUFM79_SHIFT                 (15U)
#define STCU_MBUFM_MBUFM79_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM79(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM79_SHIFT)) & STCU_MBUFM_MBUFM79_MASK)

#define STCU_MBUFM_MBUFM80_MASK                  (0x10000U)
#define STCU_MBUFM_MBUFM80_SHIFT                 (16U)
#define STCU_MBUFM_MBUFM80_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM80(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM80_SHIFT)) & STCU_MBUFM_MBUFM80_MASK)

#define STCU_MBUFM_MBUFM81_MASK                  (0x20000U)
#define STCU_MBUFM_MBUFM81_SHIFT                 (17U)
#define STCU_MBUFM_MBUFM81_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM81(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM81_SHIFT)) & STCU_MBUFM_MBUFM81_MASK)

#define STCU_MBUFM_MBUFM82_MASK                  (0x40000U)
#define STCU_MBUFM_MBUFM82_SHIFT                 (18U)
#define STCU_MBUFM_MBUFM82_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM82(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM82_SHIFT)) & STCU_MBUFM_MBUFM82_MASK)

#define STCU_MBUFM_MBUFM83_MASK                  (0x80000U)
#define STCU_MBUFM_MBUFM83_SHIFT                 (19U)
#define STCU_MBUFM_MBUFM83_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM83(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM83_SHIFT)) & STCU_MBUFM_MBUFM83_MASK)

#define STCU_MBUFM_MBUFM84_MASK                  (0x100000U)
#define STCU_MBUFM_MBUFM84_SHIFT                 (20U)
#define STCU_MBUFM_MBUFM84_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM84(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM84_SHIFT)) & STCU_MBUFM_MBUFM84_MASK)

#define STCU_MBUFM_MBUFM85_MASK                  (0x200000U)
#define STCU_MBUFM_MBUFM85_SHIFT                 (21U)
#define STCU_MBUFM_MBUFM85_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM85(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM85_SHIFT)) & STCU_MBUFM_MBUFM85_MASK)

#define STCU_MBUFM_MBUFM86_MASK                  (0x400000U)
#define STCU_MBUFM_MBUFM86_SHIFT                 (22U)
#define STCU_MBUFM_MBUFM86_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM86(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM86_SHIFT)) & STCU_MBUFM_MBUFM86_MASK)

#define STCU_MBUFM_MBUFM87_MASK                  (0x800000U)
#define STCU_MBUFM_MBUFM87_SHIFT                 (23U)
#define STCU_MBUFM_MBUFM87_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM87(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM87_SHIFT)) & STCU_MBUFM_MBUFM87_MASK)

#define STCU_MBUFM_MBUFM88_MASK                  (0x1000000U)
#define STCU_MBUFM_MBUFM88_SHIFT                 (24U)
#define STCU_MBUFM_MBUFM88_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM88(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM88_SHIFT)) & STCU_MBUFM_MBUFM88_MASK)

#define STCU_MBUFM_MBUFM89_MASK                  (0x2000000U)
#define STCU_MBUFM_MBUFM89_SHIFT                 (25U)
#define STCU_MBUFM_MBUFM89_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM89(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM89_SHIFT)) & STCU_MBUFM_MBUFM89_MASK)

#define STCU_MBUFM_MBUFM90_MASK                  (0x4000000U)
#define STCU_MBUFM_MBUFM90_SHIFT                 (26U)
#define STCU_MBUFM_MBUFM90_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM90(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM90_SHIFT)) & STCU_MBUFM_MBUFM90_MASK)

#define STCU_MBUFM_MBUFM91_MASK                  (0x8000000U)
#define STCU_MBUFM_MBUFM91_SHIFT                 (27U)
#define STCU_MBUFM_MBUFM91_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM91(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM91_SHIFT)) & STCU_MBUFM_MBUFM91_MASK)

#define STCU_MBUFM_MBUFM92_MASK                  (0x10000000U)
#define STCU_MBUFM_MBUFM92_SHIFT                 (28U)
#define STCU_MBUFM_MBUFM92_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM92(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM92_SHIFT)) & STCU_MBUFM_MBUFM92_MASK)

#define STCU_MBUFM_MBUFM93_MASK                  (0x20000000U)
#define STCU_MBUFM_MBUFM93_SHIFT                 (29U)
#define STCU_MBUFM_MBUFM93_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM93(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM93_SHIFT)) & STCU_MBUFM_MBUFM93_MASK)

#define STCU_MBUFM_MBUFM94_MASK                  (0x40000000U)
#define STCU_MBUFM_MBUFM94_SHIFT                 (30U)
#define STCU_MBUFM_MBUFM94_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM94(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM94_SHIFT)) & STCU_MBUFM_MBUFM94_MASK)

#define STCU_MBUFM_MBUFM95_MASK                  (0x80000000U)
#define STCU_MBUFM_MBUFM95_SHIFT                 (31U)
#define STCU_MBUFM_MBUFM95_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM95(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM95_SHIFT)) & STCU_MBUFM_MBUFM95_MASK)

#define STCU_MBUFM_MBUFM96_MASK                  (0x1U)
#define STCU_MBUFM_MBUFM96_SHIFT                 (0U)
#define STCU_MBUFM_MBUFM96_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM96(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM96_SHIFT)) & STCU_MBUFM_MBUFM96_MASK)

#define STCU_MBUFM_MBUFM97_MASK                  (0x2U)
#define STCU_MBUFM_MBUFM97_SHIFT                 (1U)
#define STCU_MBUFM_MBUFM97_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM97(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM97_SHIFT)) & STCU_MBUFM_MBUFM97_MASK)

#define STCU_MBUFM_MBUFM98_MASK                  (0x4U)
#define STCU_MBUFM_MBUFM98_SHIFT                 (2U)
#define STCU_MBUFM_MBUFM98_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM98(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM98_SHIFT)) & STCU_MBUFM_MBUFM98_MASK)

#define STCU_MBUFM_MBUFM99_MASK                  (0x8U)
#define STCU_MBUFM_MBUFM99_SHIFT                 (3U)
#define STCU_MBUFM_MBUFM99_WIDTH                 (1U)
#define STCU_MBUFM_MBUFM99(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM99_SHIFT)) & STCU_MBUFM_MBUFM99_MASK)

#define STCU_MBUFM_MBUFM100_MASK                 (0x10U)
#define STCU_MBUFM_MBUFM100_SHIFT                (4U)
#define STCU_MBUFM_MBUFM100_WIDTH                (1U)
#define STCU_MBUFM_MBUFM100(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM100_SHIFT)) & STCU_MBUFM_MBUFM100_MASK)

#define STCU_MBUFM_MBUFM101_MASK                 (0x20U)
#define STCU_MBUFM_MBUFM101_SHIFT                (5U)
#define STCU_MBUFM_MBUFM101_WIDTH                (1U)
#define STCU_MBUFM_MBUFM101(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM101_SHIFT)) & STCU_MBUFM_MBUFM101_MASK)

#define STCU_MBUFM_MBUFM102_MASK                 (0x40U)
#define STCU_MBUFM_MBUFM102_SHIFT                (6U)
#define STCU_MBUFM_MBUFM102_WIDTH                (1U)
#define STCU_MBUFM_MBUFM102(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM102_SHIFT)) & STCU_MBUFM_MBUFM102_MASK)

#define STCU_MBUFM_MBUFM103_MASK                 (0x80U)
#define STCU_MBUFM_MBUFM103_SHIFT                (7U)
#define STCU_MBUFM_MBUFM103_WIDTH                (1U)
#define STCU_MBUFM_MBUFM103(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM103_SHIFT)) & STCU_MBUFM_MBUFM103_MASK)

#define STCU_MBUFM_MBUFM104_MASK                 (0x100U)
#define STCU_MBUFM_MBUFM104_SHIFT                (8U)
#define STCU_MBUFM_MBUFM104_WIDTH                (1U)
#define STCU_MBUFM_MBUFM104(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM104_SHIFT)) & STCU_MBUFM_MBUFM104_MASK)

#define STCU_MBUFM_MBUFM105_MASK                 (0x200U)
#define STCU_MBUFM_MBUFM105_SHIFT                (9U)
#define STCU_MBUFM_MBUFM105_WIDTH                (1U)
#define STCU_MBUFM_MBUFM105(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM105_SHIFT)) & STCU_MBUFM_MBUFM105_MASK)

#define STCU_MBUFM_MBUFM106_MASK                 (0x400U)
#define STCU_MBUFM_MBUFM106_SHIFT                (10U)
#define STCU_MBUFM_MBUFM106_WIDTH                (1U)
#define STCU_MBUFM_MBUFM106(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM106_SHIFT)) & STCU_MBUFM_MBUFM106_MASK)

#define STCU_MBUFM_MBUFM107_MASK                 (0x800U)
#define STCU_MBUFM_MBUFM107_SHIFT                (11U)
#define STCU_MBUFM_MBUFM107_WIDTH                (1U)
#define STCU_MBUFM_MBUFM107(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM107_SHIFT)) & STCU_MBUFM_MBUFM107_MASK)

#define STCU_MBUFM_MBUFM108_MASK                 (0x1000U)
#define STCU_MBUFM_MBUFM108_SHIFT                (12U)
#define STCU_MBUFM_MBUFM108_WIDTH                (1U)
#define STCU_MBUFM_MBUFM108(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM108_SHIFT)) & STCU_MBUFM_MBUFM108_MASK)

#define STCU_MBUFM_MBUFM109_MASK                 (0x2000U)
#define STCU_MBUFM_MBUFM109_SHIFT                (13U)
#define STCU_MBUFM_MBUFM109_WIDTH                (1U)
#define STCU_MBUFM_MBUFM109(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM109_SHIFT)) & STCU_MBUFM_MBUFM109_MASK)

#define STCU_MBUFM_MBUFM110_MASK                 (0x4000U)
#define STCU_MBUFM_MBUFM110_SHIFT                (14U)
#define STCU_MBUFM_MBUFM110_WIDTH                (1U)
#define STCU_MBUFM_MBUFM110(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM110_SHIFT)) & STCU_MBUFM_MBUFM110_MASK)

#define STCU_MBUFM_MBUFM111_MASK                 (0x8000U)
#define STCU_MBUFM_MBUFM111_SHIFT                (15U)
#define STCU_MBUFM_MBUFM111_WIDTH                (1U)
#define STCU_MBUFM_MBUFM111(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM111_SHIFT)) & STCU_MBUFM_MBUFM111_MASK)

#define STCU_MBUFM_MBUFM112_MASK                 (0x10000U)
#define STCU_MBUFM_MBUFM112_SHIFT                (16U)
#define STCU_MBUFM_MBUFM112_WIDTH                (1U)
#define STCU_MBUFM_MBUFM112(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM112_SHIFT)) & STCU_MBUFM_MBUFM112_MASK)

#define STCU_MBUFM_MBUFM113_MASK                 (0x20000U)
#define STCU_MBUFM_MBUFM113_SHIFT                (17U)
#define STCU_MBUFM_MBUFM113_WIDTH                (1U)
#define STCU_MBUFM_MBUFM113(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM113_SHIFT)) & STCU_MBUFM_MBUFM113_MASK)

#define STCU_MBUFM_MBUFM114_MASK                 (0x40000U)
#define STCU_MBUFM_MBUFM114_SHIFT                (18U)
#define STCU_MBUFM_MBUFM114_WIDTH                (1U)
#define STCU_MBUFM_MBUFM114(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM114_SHIFT)) & STCU_MBUFM_MBUFM114_MASK)

#define STCU_MBUFM_MBUFM115_MASK                 (0x80000U)
#define STCU_MBUFM_MBUFM115_SHIFT                (19U)
#define STCU_MBUFM_MBUFM115_WIDTH                (1U)
#define STCU_MBUFM_MBUFM115(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM115_SHIFT)) & STCU_MBUFM_MBUFM115_MASK)

#define STCU_MBUFM_MBUFM116_MASK                 (0x100000U)
#define STCU_MBUFM_MBUFM116_SHIFT                (20U)
#define STCU_MBUFM_MBUFM116_WIDTH                (1U)
#define STCU_MBUFM_MBUFM116(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM116_SHIFT)) & STCU_MBUFM_MBUFM116_MASK)

#define STCU_MBUFM_MBUFM117_MASK                 (0x200000U)
#define STCU_MBUFM_MBUFM117_SHIFT                (21U)
#define STCU_MBUFM_MBUFM117_WIDTH                (1U)
#define STCU_MBUFM_MBUFM117(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM117_SHIFT)) & STCU_MBUFM_MBUFM117_MASK)

#define STCU_MBUFM_MBUFM118_MASK                 (0x400000U)
#define STCU_MBUFM_MBUFM118_SHIFT                (22U)
#define STCU_MBUFM_MBUFM118_WIDTH                (1U)
#define STCU_MBUFM_MBUFM118(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM118_SHIFT)) & STCU_MBUFM_MBUFM118_MASK)

#define STCU_MBUFM_MBUFM119_MASK                 (0x800000U)
#define STCU_MBUFM_MBUFM119_SHIFT                (23U)
#define STCU_MBUFM_MBUFM119_WIDTH                (1U)
#define STCU_MBUFM_MBUFM119(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM119_SHIFT)) & STCU_MBUFM_MBUFM119_MASK)

#define STCU_MBUFM_MBUFM120_MASK                 (0x1000000U)
#define STCU_MBUFM_MBUFM120_SHIFT                (24U)
#define STCU_MBUFM_MBUFM120_WIDTH                (1U)
#define STCU_MBUFM_MBUFM120(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM120_SHIFT)) & STCU_MBUFM_MBUFM120_MASK)

#define STCU_MBUFM_MBUFM121_MASK                 (0x2000000U)
#define STCU_MBUFM_MBUFM121_SHIFT                (25U)
#define STCU_MBUFM_MBUFM121_WIDTH                (1U)
#define STCU_MBUFM_MBUFM121(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM121_SHIFT)) & STCU_MBUFM_MBUFM121_MASK)

#define STCU_MBUFM_MBUFM122_MASK                 (0x4000000U)
#define STCU_MBUFM_MBUFM122_SHIFT                (26U)
#define STCU_MBUFM_MBUFM122_WIDTH                (1U)
#define STCU_MBUFM_MBUFM122(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM122_SHIFT)) & STCU_MBUFM_MBUFM122_MASK)

#define STCU_MBUFM_MBUFM123_MASK                 (0x8000000U)
#define STCU_MBUFM_MBUFM123_SHIFT                (27U)
#define STCU_MBUFM_MBUFM123_WIDTH                (1U)
#define STCU_MBUFM_MBUFM123(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM123_SHIFT)) & STCU_MBUFM_MBUFM123_MASK)

#define STCU_MBUFM_MBUFM124_MASK                 (0x10000000U)
#define STCU_MBUFM_MBUFM124_SHIFT                (28U)
#define STCU_MBUFM_MBUFM124_WIDTH                (1U)
#define STCU_MBUFM_MBUFM124(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM124_SHIFT)) & STCU_MBUFM_MBUFM124_MASK)

#define STCU_MBUFM_MBUFM125_MASK                 (0x20000000U)
#define STCU_MBUFM_MBUFM125_SHIFT                (29U)
#define STCU_MBUFM_MBUFM125_WIDTH                (1U)
#define STCU_MBUFM_MBUFM125(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM125_SHIFT)) & STCU_MBUFM_MBUFM125_MASK)

#define STCU_MBUFM_MBUFM126_MASK                 (0x40000000U)
#define STCU_MBUFM_MBUFM126_SHIFT                (30U)
#define STCU_MBUFM_MBUFM126_WIDTH                (1U)
#define STCU_MBUFM_MBUFM126(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM126_SHIFT)) & STCU_MBUFM_MBUFM126_MASK)

#define STCU_MBUFM_MBUFM127_MASK                 (0x80000000U)
#define STCU_MBUFM_MBUFM127_SHIFT                (31U)
#define STCU_MBUFM_MBUFM127_WIDTH                (1U)
#define STCU_MBUFM_MBUFM127(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM127_SHIFT)) & STCU_MBUFM_MBUFM127_MASK)

#define STCU_MBUFM_MBUFM128_MASK                 (0x1U)
#define STCU_MBUFM_MBUFM128_SHIFT                (0U)
#define STCU_MBUFM_MBUFM128_WIDTH                (1U)
#define STCU_MBUFM_MBUFM128(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM128_SHIFT)) & STCU_MBUFM_MBUFM128_MASK)

#define STCU_MBUFM_MBUFM129_MASK                 (0x2U)
#define STCU_MBUFM_MBUFM129_SHIFT                (1U)
#define STCU_MBUFM_MBUFM129_WIDTH                (1U)
#define STCU_MBUFM_MBUFM129(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM129_SHIFT)) & STCU_MBUFM_MBUFM129_MASK)

#define STCU_MBUFM_MBUFM130_MASK                 (0x4U)
#define STCU_MBUFM_MBUFM130_SHIFT                (2U)
#define STCU_MBUFM_MBUFM130_WIDTH                (1U)
#define STCU_MBUFM_MBUFM130(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM130_SHIFT)) & STCU_MBUFM_MBUFM130_MASK)

#define STCU_MBUFM_MBUFM131_MASK                 (0x8U)
#define STCU_MBUFM_MBUFM131_SHIFT                (3U)
#define STCU_MBUFM_MBUFM131_WIDTH                (1U)
#define STCU_MBUFM_MBUFM131(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM131_SHIFT)) & STCU_MBUFM_MBUFM131_MASK)

#define STCU_MBUFM_MBUFM132_MASK                 (0x10U)
#define STCU_MBUFM_MBUFM132_SHIFT                (4U)
#define STCU_MBUFM_MBUFM132_WIDTH                (1U)
#define STCU_MBUFM_MBUFM132(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM132_SHIFT)) & STCU_MBUFM_MBUFM132_MASK)

#define STCU_MBUFM_MBUFM133_MASK                 (0x20U)
#define STCU_MBUFM_MBUFM133_SHIFT                (5U)
#define STCU_MBUFM_MBUFM133_WIDTH                (1U)
#define STCU_MBUFM_MBUFM133(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM133_SHIFT)) & STCU_MBUFM_MBUFM133_MASK)

#define STCU_MBUFM_MBUFM134_MASK                 (0x40U)
#define STCU_MBUFM_MBUFM134_SHIFT                (6U)
#define STCU_MBUFM_MBUFM134_WIDTH                (1U)
#define STCU_MBUFM_MBUFM134(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM134_SHIFT)) & STCU_MBUFM_MBUFM134_MASK)

#define STCU_MBUFM_MBUFM135_MASK                 (0x80U)
#define STCU_MBUFM_MBUFM135_SHIFT                (7U)
#define STCU_MBUFM_MBUFM135_WIDTH                (1U)
#define STCU_MBUFM_MBUFM135(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM135_SHIFT)) & STCU_MBUFM_MBUFM135_MASK)

#define STCU_MBUFM_MBUFM136_MASK                 (0x100U)
#define STCU_MBUFM_MBUFM136_SHIFT                (8U)
#define STCU_MBUFM_MBUFM136_WIDTH                (1U)
#define STCU_MBUFM_MBUFM136(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM136_SHIFT)) & STCU_MBUFM_MBUFM136_MASK)

#define STCU_MBUFM_MBUFM137_MASK                 (0x200U)
#define STCU_MBUFM_MBUFM137_SHIFT                (9U)
#define STCU_MBUFM_MBUFM137_WIDTH                (1U)
#define STCU_MBUFM_MBUFM137(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM137_SHIFT)) & STCU_MBUFM_MBUFM137_MASK)

#define STCU_MBUFM_MBUFM138_MASK                 (0x400U)
#define STCU_MBUFM_MBUFM138_SHIFT                (10U)
#define STCU_MBUFM_MBUFM138_WIDTH                (1U)
#define STCU_MBUFM_MBUFM138(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM138_SHIFT)) & STCU_MBUFM_MBUFM138_MASK)

#define STCU_MBUFM_MBUFM139_MASK                 (0x800U)
#define STCU_MBUFM_MBUFM139_SHIFT                (11U)
#define STCU_MBUFM_MBUFM139_WIDTH                (1U)
#define STCU_MBUFM_MBUFM139(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM139_SHIFT)) & STCU_MBUFM_MBUFM139_MASK)

#define STCU_MBUFM_MBUFM140_MASK                 (0x1000U)
#define STCU_MBUFM_MBUFM140_SHIFT                (12U)
#define STCU_MBUFM_MBUFM140_WIDTH                (1U)
#define STCU_MBUFM_MBUFM140(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM140_SHIFT)) & STCU_MBUFM_MBUFM140_MASK)

#define STCU_MBUFM_MBUFM141_MASK                 (0x2000U)
#define STCU_MBUFM_MBUFM141_SHIFT                (13U)
#define STCU_MBUFM_MBUFM141_WIDTH                (1U)
#define STCU_MBUFM_MBUFM141(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM141_SHIFT)) & STCU_MBUFM_MBUFM141_MASK)

#define STCU_MBUFM_MBUFM142_MASK                 (0x4000U)
#define STCU_MBUFM_MBUFM142_SHIFT                (14U)
#define STCU_MBUFM_MBUFM142_WIDTH                (1U)
#define STCU_MBUFM_MBUFM142(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM142_SHIFT)) & STCU_MBUFM_MBUFM142_MASK)

#define STCU_MBUFM_MBUFM143_MASK                 (0x8000U)
#define STCU_MBUFM_MBUFM143_SHIFT                (15U)
#define STCU_MBUFM_MBUFM143_WIDTH                (1U)
#define STCU_MBUFM_MBUFM143(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM143_SHIFT)) & STCU_MBUFM_MBUFM143_MASK)

#define STCU_MBUFM_MBUFM144_MASK                 (0x10000U)
#define STCU_MBUFM_MBUFM144_SHIFT                (16U)
#define STCU_MBUFM_MBUFM144_WIDTH                (1U)
#define STCU_MBUFM_MBUFM144(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM144_SHIFT)) & STCU_MBUFM_MBUFM144_MASK)

#define STCU_MBUFM_MBUFM145_MASK                 (0x20000U)
#define STCU_MBUFM_MBUFM145_SHIFT                (17U)
#define STCU_MBUFM_MBUFM145_WIDTH                (1U)
#define STCU_MBUFM_MBUFM145(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM145_SHIFT)) & STCU_MBUFM_MBUFM145_MASK)

#define STCU_MBUFM_MBUFM146_MASK                 (0x40000U)
#define STCU_MBUFM_MBUFM146_SHIFT                (18U)
#define STCU_MBUFM_MBUFM146_WIDTH                (1U)
#define STCU_MBUFM_MBUFM146(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM146_SHIFT)) & STCU_MBUFM_MBUFM146_MASK)

#define STCU_MBUFM_MBUFM147_MASK                 (0x80000U)
#define STCU_MBUFM_MBUFM147_SHIFT                (19U)
#define STCU_MBUFM_MBUFM147_WIDTH                (1U)
#define STCU_MBUFM_MBUFM147(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM147_SHIFT)) & STCU_MBUFM_MBUFM147_MASK)

#define STCU_MBUFM_MBUFM148_MASK                 (0x100000U)
#define STCU_MBUFM_MBUFM148_SHIFT                (20U)
#define STCU_MBUFM_MBUFM148_WIDTH                (1U)
#define STCU_MBUFM_MBUFM148(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM148_SHIFT)) & STCU_MBUFM_MBUFM148_MASK)

#define STCU_MBUFM_MBUFM149_MASK                 (0x200000U)
#define STCU_MBUFM_MBUFM149_SHIFT                (21U)
#define STCU_MBUFM_MBUFM149_WIDTH                (1U)
#define STCU_MBUFM_MBUFM149(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM149_SHIFT)) & STCU_MBUFM_MBUFM149_MASK)

#define STCU_MBUFM_MBUFM150_MASK                 (0x400000U)
#define STCU_MBUFM_MBUFM150_SHIFT                (22U)
#define STCU_MBUFM_MBUFM150_WIDTH                (1U)
#define STCU_MBUFM_MBUFM150(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM150_SHIFT)) & STCU_MBUFM_MBUFM150_MASK)

#define STCU_MBUFM_MBUFM151_MASK                 (0x800000U)
#define STCU_MBUFM_MBUFM151_SHIFT                (23U)
#define STCU_MBUFM_MBUFM151_WIDTH                (1U)
#define STCU_MBUFM_MBUFM151(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM151_SHIFT)) & STCU_MBUFM_MBUFM151_MASK)

#define STCU_MBUFM_MBUFM152_MASK                 (0x1000000U)
#define STCU_MBUFM_MBUFM152_SHIFT                (24U)
#define STCU_MBUFM_MBUFM152_WIDTH                (1U)
#define STCU_MBUFM_MBUFM152(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM152_SHIFT)) & STCU_MBUFM_MBUFM152_MASK)

#define STCU_MBUFM_MBUFM153_MASK                 (0x2000000U)
#define STCU_MBUFM_MBUFM153_SHIFT                (25U)
#define STCU_MBUFM_MBUFM153_WIDTH                (1U)
#define STCU_MBUFM_MBUFM153(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM153_SHIFT)) & STCU_MBUFM_MBUFM153_MASK)

#define STCU_MBUFM_MBUFM154_MASK                 (0x4000000U)
#define STCU_MBUFM_MBUFM154_SHIFT                (26U)
#define STCU_MBUFM_MBUFM154_WIDTH                (1U)
#define STCU_MBUFM_MBUFM154(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM154_SHIFT)) & STCU_MBUFM_MBUFM154_MASK)

#define STCU_MBUFM_MBUFM155_MASK                 (0x8000000U)
#define STCU_MBUFM_MBUFM155_SHIFT                (27U)
#define STCU_MBUFM_MBUFM155_WIDTH                (1U)
#define STCU_MBUFM_MBUFM155(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM155_SHIFT)) & STCU_MBUFM_MBUFM155_MASK)

#define STCU_MBUFM_MBUFM156_MASK                 (0x10000000U)
#define STCU_MBUFM_MBUFM156_SHIFT                (28U)
#define STCU_MBUFM_MBUFM156_WIDTH                (1U)
#define STCU_MBUFM_MBUFM156(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM156_SHIFT)) & STCU_MBUFM_MBUFM156_MASK)

#define STCU_MBUFM_MBUFM157_MASK                 (0x20000000U)
#define STCU_MBUFM_MBUFM157_SHIFT                (29U)
#define STCU_MBUFM_MBUFM157_WIDTH                (1U)
#define STCU_MBUFM_MBUFM157(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM157_SHIFT)) & STCU_MBUFM_MBUFM157_MASK)

#define STCU_MBUFM_MBUFM158_MASK                 (0x40000000U)
#define STCU_MBUFM_MBUFM158_SHIFT                (30U)
#define STCU_MBUFM_MBUFM158_WIDTH                (1U)
#define STCU_MBUFM_MBUFM158(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM158_SHIFT)) & STCU_MBUFM_MBUFM158_MASK)

#define STCU_MBUFM_MBUFM159_MASK                 (0x80000000U)
#define STCU_MBUFM_MBUFM159_SHIFT                (31U)
#define STCU_MBUFM_MBUFM159_WIDTH                (1U)
#define STCU_MBUFM_MBUFM159(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM159_SHIFT)) & STCU_MBUFM_MBUFM159_MASK)

#define STCU_MBUFM_MBUFM160_MASK                 (0x1U)
#define STCU_MBUFM_MBUFM160_SHIFT                (0U)
#define STCU_MBUFM_MBUFM160_WIDTH                (1U)
#define STCU_MBUFM_MBUFM160(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM160_SHIFT)) & STCU_MBUFM_MBUFM160_MASK)

#define STCU_MBUFM_MBUFM161_MASK                 (0x2U)
#define STCU_MBUFM_MBUFM161_SHIFT                (1U)
#define STCU_MBUFM_MBUFM161_WIDTH                (1U)
#define STCU_MBUFM_MBUFM161(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM161_SHIFT)) & STCU_MBUFM_MBUFM161_MASK)

#define STCU_MBUFM_MBUFM162_MASK                 (0x4U)
#define STCU_MBUFM_MBUFM162_SHIFT                (2U)
#define STCU_MBUFM_MBUFM162_WIDTH                (1U)
#define STCU_MBUFM_MBUFM162(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM162_SHIFT)) & STCU_MBUFM_MBUFM162_MASK)

#define STCU_MBUFM_MBUFM163_MASK                 (0x8U)
#define STCU_MBUFM_MBUFM163_SHIFT                (3U)
#define STCU_MBUFM_MBUFM163_WIDTH                (1U)
#define STCU_MBUFM_MBUFM163(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM163_SHIFT)) & STCU_MBUFM_MBUFM163_MASK)

#define STCU_MBUFM_MBUFM164_MASK                 (0x10U)
#define STCU_MBUFM_MBUFM164_SHIFT                (4U)
#define STCU_MBUFM_MBUFM164_WIDTH                (1U)
#define STCU_MBUFM_MBUFM164(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM164_SHIFT)) & STCU_MBUFM_MBUFM164_MASK)

#define STCU_MBUFM_MBUFM165_MASK                 (0x20U)
#define STCU_MBUFM_MBUFM165_SHIFT                (5U)
#define STCU_MBUFM_MBUFM165_WIDTH                (1U)
#define STCU_MBUFM_MBUFM165(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM165_SHIFT)) & STCU_MBUFM_MBUFM165_MASK)

#define STCU_MBUFM_MBUFM166_MASK                 (0x40U)
#define STCU_MBUFM_MBUFM166_SHIFT                (6U)
#define STCU_MBUFM_MBUFM166_WIDTH                (1U)
#define STCU_MBUFM_MBUFM166(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM166_SHIFT)) & STCU_MBUFM_MBUFM166_MASK)

#define STCU_MBUFM_MBUFM167_MASK                 (0x80U)
#define STCU_MBUFM_MBUFM167_SHIFT                (7U)
#define STCU_MBUFM_MBUFM167_WIDTH                (1U)
#define STCU_MBUFM_MBUFM167(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM167_SHIFT)) & STCU_MBUFM_MBUFM167_MASK)

#define STCU_MBUFM_MBUFM168_MASK                 (0x100U)
#define STCU_MBUFM_MBUFM168_SHIFT                (8U)
#define STCU_MBUFM_MBUFM168_WIDTH                (1U)
#define STCU_MBUFM_MBUFM168(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM168_SHIFT)) & STCU_MBUFM_MBUFM168_MASK)

#define STCU_MBUFM_MBUFM169_MASK                 (0x200U)
#define STCU_MBUFM_MBUFM169_SHIFT                (9U)
#define STCU_MBUFM_MBUFM169_WIDTH                (1U)
#define STCU_MBUFM_MBUFM169(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM169_SHIFT)) & STCU_MBUFM_MBUFM169_MASK)

#define STCU_MBUFM_MBUFM170_MASK                 (0x400U)
#define STCU_MBUFM_MBUFM170_SHIFT                (10U)
#define STCU_MBUFM_MBUFM170_WIDTH                (1U)
#define STCU_MBUFM_MBUFM170(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM170_SHIFT)) & STCU_MBUFM_MBUFM170_MASK)

#define STCU_MBUFM_MBUFM171_MASK                 (0x800U)
#define STCU_MBUFM_MBUFM171_SHIFT                (11U)
#define STCU_MBUFM_MBUFM171_WIDTH                (1U)
#define STCU_MBUFM_MBUFM171(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM171_SHIFT)) & STCU_MBUFM_MBUFM171_MASK)

#define STCU_MBUFM_MBUFM172_MASK                 (0x1000U)
#define STCU_MBUFM_MBUFM172_SHIFT                (12U)
#define STCU_MBUFM_MBUFM172_WIDTH                (1U)
#define STCU_MBUFM_MBUFM172(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM172_SHIFT)) & STCU_MBUFM_MBUFM172_MASK)

#define STCU_MBUFM_MBUFM173_MASK                 (0x2000U)
#define STCU_MBUFM_MBUFM173_SHIFT                (13U)
#define STCU_MBUFM_MBUFM173_WIDTH                (1U)
#define STCU_MBUFM_MBUFM173(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM173_SHIFT)) & STCU_MBUFM_MBUFM173_MASK)

#define STCU_MBUFM_MBUFM174_MASK                 (0x4000U)
#define STCU_MBUFM_MBUFM174_SHIFT                (14U)
#define STCU_MBUFM_MBUFM174_WIDTH                (1U)
#define STCU_MBUFM_MBUFM174(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM174_SHIFT)) & STCU_MBUFM_MBUFM174_MASK)

#define STCU_MBUFM_MBUFM175_MASK                 (0x8000U)
#define STCU_MBUFM_MBUFM175_SHIFT                (15U)
#define STCU_MBUFM_MBUFM175_WIDTH                (1U)
#define STCU_MBUFM_MBUFM175(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM175_SHIFT)) & STCU_MBUFM_MBUFM175_MASK)

#define STCU_MBUFM_MBUFM176_MASK                 (0x10000U)
#define STCU_MBUFM_MBUFM176_SHIFT                (16U)
#define STCU_MBUFM_MBUFM176_WIDTH                (1U)
#define STCU_MBUFM_MBUFM176(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM176_SHIFT)) & STCU_MBUFM_MBUFM176_MASK)

#define STCU_MBUFM_MBUFM177_MASK                 (0x20000U)
#define STCU_MBUFM_MBUFM177_SHIFT                (17U)
#define STCU_MBUFM_MBUFM177_WIDTH                (1U)
#define STCU_MBUFM_MBUFM177(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM177_SHIFT)) & STCU_MBUFM_MBUFM177_MASK)

#define STCU_MBUFM_MBUFM178_MASK                 (0x40000U)
#define STCU_MBUFM_MBUFM178_SHIFT                (18U)
#define STCU_MBUFM_MBUFM178_WIDTH                (1U)
#define STCU_MBUFM_MBUFM178(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM178_SHIFT)) & STCU_MBUFM_MBUFM178_MASK)

#define STCU_MBUFM_MBUFM179_MASK                 (0x80000U)
#define STCU_MBUFM_MBUFM179_SHIFT                (19U)
#define STCU_MBUFM_MBUFM179_WIDTH                (1U)
#define STCU_MBUFM_MBUFM179(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM179_SHIFT)) & STCU_MBUFM_MBUFM179_MASK)

#define STCU_MBUFM_MBUFM180_MASK                 (0x100000U)
#define STCU_MBUFM_MBUFM180_SHIFT                (20U)
#define STCU_MBUFM_MBUFM180_WIDTH                (1U)
#define STCU_MBUFM_MBUFM180(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM180_SHIFT)) & STCU_MBUFM_MBUFM180_MASK)

#define STCU_MBUFM_MBUFM181_MASK                 (0x200000U)
#define STCU_MBUFM_MBUFM181_SHIFT                (21U)
#define STCU_MBUFM_MBUFM181_WIDTH                (1U)
#define STCU_MBUFM_MBUFM181(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM181_SHIFT)) & STCU_MBUFM_MBUFM181_MASK)

#define STCU_MBUFM_MBUFM182_MASK                 (0x400000U)
#define STCU_MBUFM_MBUFM182_SHIFT                (22U)
#define STCU_MBUFM_MBUFM182_WIDTH                (1U)
#define STCU_MBUFM_MBUFM182(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM182_SHIFT)) & STCU_MBUFM_MBUFM182_MASK)

#define STCU_MBUFM_MBUFM183_MASK                 (0x800000U)
#define STCU_MBUFM_MBUFM183_SHIFT                (23U)
#define STCU_MBUFM_MBUFM183_WIDTH                (1U)
#define STCU_MBUFM_MBUFM183(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM183_SHIFT)) & STCU_MBUFM_MBUFM183_MASK)

#define STCU_MBUFM_MBUFM184_MASK                 (0x1000000U)
#define STCU_MBUFM_MBUFM184_SHIFT                (24U)
#define STCU_MBUFM_MBUFM184_WIDTH                (1U)
#define STCU_MBUFM_MBUFM184(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM184_SHIFT)) & STCU_MBUFM_MBUFM184_MASK)

#define STCU_MBUFM_MBUFM185_MASK                 (0x2000000U)
#define STCU_MBUFM_MBUFM185_SHIFT                (25U)
#define STCU_MBUFM_MBUFM185_WIDTH                (1U)
#define STCU_MBUFM_MBUFM185(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM185_SHIFT)) & STCU_MBUFM_MBUFM185_MASK)

#define STCU_MBUFM_MBUFM186_MASK                 (0x4000000U)
#define STCU_MBUFM_MBUFM186_SHIFT                (26U)
#define STCU_MBUFM_MBUFM186_WIDTH                (1U)
#define STCU_MBUFM_MBUFM186(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM186_SHIFT)) & STCU_MBUFM_MBUFM186_MASK)

#define STCU_MBUFM_MBUFM187_MASK                 (0x8000000U)
#define STCU_MBUFM_MBUFM187_SHIFT                (27U)
#define STCU_MBUFM_MBUFM187_WIDTH                (1U)
#define STCU_MBUFM_MBUFM187(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM187_SHIFT)) & STCU_MBUFM_MBUFM187_MASK)

#define STCU_MBUFM_MBUFM188_MASK                 (0x10000000U)
#define STCU_MBUFM_MBUFM188_SHIFT                (28U)
#define STCU_MBUFM_MBUFM188_WIDTH                (1U)
#define STCU_MBUFM_MBUFM188(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM188_SHIFT)) & STCU_MBUFM_MBUFM188_MASK)

#define STCU_MBUFM_MBUFM189_MASK                 (0x20000000U)
#define STCU_MBUFM_MBUFM189_SHIFT                (29U)
#define STCU_MBUFM_MBUFM189_WIDTH                (1U)
#define STCU_MBUFM_MBUFM189(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM189_SHIFT)) & STCU_MBUFM_MBUFM189_MASK)

#define STCU_MBUFM_MBUFM190_MASK                 (0x40000000U)
#define STCU_MBUFM_MBUFM190_SHIFT                (30U)
#define STCU_MBUFM_MBUFM190_WIDTH                (1U)
#define STCU_MBUFM_MBUFM190(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM190_SHIFT)) & STCU_MBUFM_MBUFM190_MASK)

#define STCU_MBUFM_MBUFM191_MASK                 (0x80000000U)
#define STCU_MBUFM_MBUFM191_SHIFT                (31U)
#define STCU_MBUFM_MBUFM191_WIDTH                (1U)
#define STCU_MBUFM_MBUFM191(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM191_SHIFT)) & STCU_MBUFM_MBUFM191_MASK)

#define STCU_MBUFM_MBUFM192_MASK                 (0x1U)
#define STCU_MBUFM_MBUFM192_SHIFT                (0U)
#define STCU_MBUFM_MBUFM192_WIDTH                (1U)
#define STCU_MBUFM_MBUFM192(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM192_SHIFT)) & STCU_MBUFM_MBUFM192_MASK)

#define STCU_MBUFM_MBUFM193_MASK                 (0x2U)
#define STCU_MBUFM_MBUFM193_SHIFT                (1U)
#define STCU_MBUFM_MBUFM193_WIDTH                (1U)
#define STCU_MBUFM_MBUFM193(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM193_SHIFT)) & STCU_MBUFM_MBUFM193_MASK)

#define STCU_MBUFM_MBUFM194_MASK                 (0x4U)
#define STCU_MBUFM_MBUFM194_SHIFT                (2U)
#define STCU_MBUFM_MBUFM194_WIDTH                (1U)
#define STCU_MBUFM_MBUFM194(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM194_SHIFT)) & STCU_MBUFM_MBUFM194_MASK)

#define STCU_MBUFM_MBUFM195_MASK                 (0x8U)
#define STCU_MBUFM_MBUFM195_SHIFT                (3U)
#define STCU_MBUFM_MBUFM195_WIDTH                (1U)
#define STCU_MBUFM_MBUFM195(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM195_SHIFT)) & STCU_MBUFM_MBUFM195_MASK)

#define STCU_MBUFM_MBUFM196_MASK                 (0x10U)
#define STCU_MBUFM_MBUFM196_SHIFT                (4U)
#define STCU_MBUFM_MBUFM196_WIDTH                (1U)
#define STCU_MBUFM_MBUFM196(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM196_SHIFT)) & STCU_MBUFM_MBUFM196_MASK)

#define STCU_MBUFM_MBUFM197_MASK                 (0x20U)
#define STCU_MBUFM_MBUFM197_SHIFT                (5U)
#define STCU_MBUFM_MBUFM197_WIDTH                (1U)
#define STCU_MBUFM_MBUFM197(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM197_SHIFT)) & STCU_MBUFM_MBUFM197_MASK)

#define STCU_MBUFM_MBUFM198_MASK                 (0x40U)
#define STCU_MBUFM_MBUFM198_SHIFT                (6U)
#define STCU_MBUFM_MBUFM198_WIDTH                (1U)
#define STCU_MBUFM_MBUFM198(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM198_SHIFT)) & STCU_MBUFM_MBUFM198_MASK)

#define STCU_MBUFM_MBUFM199_MASK                 (0x80U)
#define STCU_MBUFM_MBUFM199_SHIFT                (7U)
#define STCU_MBUFM_MBUFM199_WIDTH                (1U)
#define STCU_MBUFM_MBUFM199(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM199_SHIFT)) & STCU_MBUFM_MBUFM199_MASK)

#define STCU_MBUFM_MBUFM200_MASK                 (0x100U)
#define STCU_MBUFM_MBUFM200_SHIFT                (8U)
#define STCU_MBUFM_MBUFM200_WIDTH                (1U)
#define STCU_MBUFM_MBUFM200(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM200_SHIFT)) & STCU_MBUFM_MBUFM200_MASK)

#define STCU_MBUFM_MBUFM201_MASK                 (0x200U)
#define STCU_MBUFM_MBUFM201_SHIFT                (9U)
#define STCU_MBUFM_MBUFM201_WIDTH                (1U)
#define STCU_MBUFM_MBUFM201(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM201_SHIFT)) & STCU_MBUFM_MBUFM201_MASK)

#define STCU_MBUFM_MBUFM202_MASK                 (0x400U)
#define STCU_MBUFM_MBUFM202_SHIFT                (10U)
#define STCU_MBUFM_MBUFM202_WIDTH                (1U)
#define STCU_MBUFM_MBUFM202(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM202_SHIFT)) & STCU_MBUFM_MBUFM202_MASK)

#define STCU_MBUFM_MBUFM203_MASK                 (0x800U)
#define STCU_MBUFM_MBUFM203_SHIFT                (11U)
#define STCU_MBUFM_MBUFM203_WIDTH                (1U)
#define STCU_MBUFM_MBUFM203(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM203_SHIFT)) & STCU_MBUFM_MBUFM203_MASK)

#define STCU_MBUFM_MBUFM204_MASK                 (0x1000U)
#define STCU_MBUFM_MBUFM204_SHIFT                (12U)
#define STCU_MBUFM_MBUFM204_WIDTH                (1U)
#define STCU_MBUFM_MBUFM204(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM204_SHIFT)) & STCU_MBUFM_MBUFM204_MASK)

#define STCU_MBUFM_MBUFM205_MASK                 (0x2000U)
#define STCU_MBUFM_MBUFM205_SHIFT                (13U)
#define STCU_MBUFM_MBUFM205_WIDTH                (1U)
#define STCU_MBUFM_MBUFM205(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM205_SHIFT)) & STCU_MBUFM_MBUFM205_MASK)

#define STCU_MBUFM_MBUFM206_MASK                 (0x4000U)
#define STCU_MBUFM_MBUFM206_SHIFT                (14U)
#define STCU_MBUFM_MBUFM206_WIDTH                (1U)
#define STCU_MBUFM_MBUFM206(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM206_SHIFT)) & STCU_MBUFM_MBUFM206_MASK)

#define STCU_MBUFM_MBUFM207_MASK                 (0x8000U)
#define STCU_MBUFM_MBUFM207_SHIFT                (15U)
#define STCU_MBUFM_MBUFM207_WIDTH                (1U)
#define STCU_MBUFM_MBUFM207(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM207_SHIFT)) & STCU_MBUFM_MBUFM207_MASK)

#define STCU_MBUFM_MBUFM208_MASK                 (0x10000U)
#define STCU_MBUFM_MBUFM208_SHIFT                (16U)
#define STCU_MBUFM_MBUFM208_WIDTH                (1U)
#define STCU_MBUFM_MBUFM208(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM208_SHIFT)) & STCU_MBUFM_MBUFM208_MASK)

#define STCU_MBUFM_MBUFM209_MASK                 (0x20000U)
#define STCU_MBUFM_MBUFM209_SHIFT                (17U)
#define STCU_MBUFM_MBUFM209_WIDTH                (1U)
#define STCU_MBUFM_MBUFM209(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM209_SHIFT)) & STCU_MBUFM_MBUFM209_MASK)

#define STCU_MBUFM_MBUFM210_MASK                 (0x40000U)
#define STCU_MBUFM_MBUFM210_SHIFT                (18U)
#define STCU_MBUFM_MBUFM210_WIDTH                (1U)
#define STCU_MBUFM_MBUFM210(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM210_SHIFT)) & STCU_MBUFM_MBUFM210_MASK)

#define STCU_MBUFM_MBUFM211_MASK                 (0x80000U)
#define STCU_MBUFM_MBUFM211_SHIFT                (19U)
#define STCU_MBUFM_MBUFM211_WIDTH                (1U)
#define STCU_MBUFM_MBUFM211(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM211_SHIFT)) & STCU_MBUFM_MBUFM211_MASK)

#define STCU_MBUFM_MBUFM212_MASK                 (0x100000U)
#define STCU_MBUFM_MBUFM212_SHIFT                (20U)
#define STCU_MBUFM_MBUFM212_WIDTH                (1U)
#define STCU_MBUFM_MBUFM212(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM212_SHIFT)) & STCU_MBUFM_MBUFM212_MASK)

#define STCU_MBUFM_MBUFM213_MASK                 (0x200000U)
#define STCU_MBUFM_MBUFM213_SHIFT                (21U)
#define STCU_MBUFM_MBUFM213_WIDTH                (1U)
#define STCU_MBUFM_MBUFM213(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM213_SHIFT)) & STCU_MBUFM_MBUFM213_MASK)

#define STCU_MBUFM_MBUFM214_MASK                 (0x400000U)
#define STCU_MBUFM_MBUFM214_SHIFT                (22U)
#define STCU_MBUFM_MBUFM214_WIDTH                (1U)
#define STCU_MBUFM_MBUFM214(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM214_SHIFT)) & STCU_MBUFM_MBUFM214_MASK)

#define STCU_MBUFM_MBUFM215_MASK                 (0x800000U)
#define STCU_MBUFM_MBUFM215_SHIFT                (23U)
#define STCU_MBUFM_MBUFM215_WIDTH                (1U)
#define STCU_MBUFM_MBUFM215(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM215_SHIFT)) & STCU_MBUFM_MBUFM215_MASK)

#define STCU_MBUFM_MBUFM216_MASK                 (0x1000000U)
#define STCU_MBUFM_MBUFM216_SHIFT                (24U)
#define STCU_MBUFM_MBUFM216_WIDTH                (1U)
#define STCU_MBUFM_MBUFM216(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM216_SHIFT)) & STCU_MBUFM_MBUFM216_MASK)

#define STCU_MBUFM_MBUFM217_MASK                 (0x2000000U)
#define STCU_MBUFM_MBUFM217_SHIFT                (25U)
#define STCU_MBUFM_MBUFM217_WIDTH                (1U)
#define STCU_MBUFM_MBUFM217(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM217_SHIFT)) & STCU_MBUFM_MBUFM217_MASK)

#define STCU_MBUFM_MBUFM218_MASK                 (0x4000000U)
#define STCU_MBUFM_MBUFM218_SHIFT                (26U)
#define STCU_MBUFM_MBUFM218_WIDTH                (1U)
#define STCU_MBUFM_MBUFM218(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM218_SHIFT)) & STCU_MBUFM_MBUFM218_MASK)

#define STCU_MBUFM_MBUFM219_MASK                 (0x8000000U)
#define STCU_MBUFM_MBUFM219_SHIFT                (27U)
#define STCU_MBUFM_MBUFM219_WIDTH                (1U)
#define STCU_MBUFM_MBUFM219(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM219_SHIFT)) & STCU_MBUFM_MBUFM219_MASK)

#define STCU_MBUFM_MBUFM220_MASK                 (0x10000000U)
#define STCU_MBUFM_MBUFM220_SHIFT                (28U)
#define STCU_MBUFM_MBUFM220_WIDTH                (1U)
#define STCU_MBUFM_MBUFM220(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM220_SHIFT)) & STCU_MBUFM_MBUFM220_MASK)

#define STCU_MBUFM_MBUFM221_MASK                 (0x20000000U)
#define STCU_MBUFM_MBUFM221_SHIFT                (29U)
#define STCU_MBUFM_MBUFM221_WIDTH                (1U)
#define STCU_MBUFM_MBUFM221(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM221_SHIFT)) & STCU_MBUFM_MBUFM221_MASK)

#define STCU_MBUFM_MBUFM222_MASK                 (0x40000000U)
#define STCU_MBUFM_MBUFM222_SHIFT                (30U)
#define STCU_MBUFM_MBUFM222_WIDTH                (1U)
#define STCU_MBUFM_MBUFM222(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM222_SHIFT)) & STCU_MBUFM_MBUFM222_MASK)

#define STCU_MBUFM_MBUFM223_MASK                 (0x80000000U)
#define STCU_MBUFM_MBUFM223_SHIFT                (31U)
#define STCU_MBUFM_MBUFM223_WIDTH                (1U)
#define STCU_MBUFM_MBUFM223(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM223_SHIFT)) & STCU_MBUFM_MBUFM223_MASK)

#define STCU_MBUFM_MBUFM224_MASK                 (0x1U)
#define STCU_MBUFM_MBUFM224_SHIFT                (0U)
#define STCU_MBUFM_MBUFM224_WIDTH                (1U)
#define STCU_MBUFM_MBUFM224(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM224_SHIFT)) & STCU_MBUFM_MBUFM224_MASK)

#define STCU_MBUFM_MBUFM225_MASK                 (0x2U)
#define STCU_MBUFM_MBUFM225_SHIFT                (1U)
#define STCU_MBUFM_MBUFM225_WIDTH                (1U)
#define STCU_MBUFM_MBUFM225(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM225_SHIFT)) & STCU_MBUFM_MBUFM225_MASK)

#define STCU_MBUFM_MBUFM226_MASK                 (0x4U)
#define STCU_MBUFM_MBUFM226_SHIFT                (2U)
#define STCU_MBUFM_MBUFM226_WIDTH                (1U)
#define STCU_MBUFM_MBUFM226(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM226_SHIFT)) & STCU_MBUFM_MBUFM226_MASK)

#define STCU_MBUFM_MBUFM227_MASK                 (0x8U)
#define STCU_MBUFM_MBUFM227_SHIFT                (3U)
#define STCU_MBUFM_MBUFM227_WIDTH                (1U)
#define STCU_MBUFM_MBUFM227(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM227_SHIFT)) & STCU_MBUFM_MBUFM227_MASK)

#define STCU_MBUFM_MBUFM228_MASK                 (0x10U)
#define STCU_MBUFM_MBUFM228_SHIFT                (4U)
#define STCU_MBUFM_MBUFM228_WIDTH                (1U)
#define STCU_MBUFM_MBUFM228(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM228_SHIFT)) & STCU_MBUFM_MBUFM228_MASK)

#define STCU_MBUFM_MBUFM229_MASK                 (0x20U)
#define STCU_MBUFM_MBUFM229_SHIFT                (5U)
#define STCU_MBUFM_MBUFM229_WIDTH                (1U)
#define STCU_MBUFM_MBUFM229(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM229_SHIFT)) & STCU_MBUFM_MBUFM229_MASK)

#define STCU_MBUFM_MBUFM230_MASK                 (0x40U)
#define STCU_MBUFM_MBUFM230_SHIFT                (6U)
#define STCU_MBUFM_MBUFM230_WIDTH                (1U)
#define STCU_MBUFM_MBUFM230(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM230_SHIFT)) & STCU_MBUFM_MBUFM230_MASK)

#define STCU_MBUFM_MBUFM231_MASK                 (0x80U)
#define STCU_MBUFM_MBUFM231_SHIFT                (7U)
#define STCU_MBUFM_MBUFM231_WIDTH                (1U)
#define STCU_MBUFM_MBUFM231(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM231_SHIFT)) & STCU_MBUFM_MBUFM231_MASK)

#define STCU_MBUFM_MBUFM232_MASK                 (0x100U)
#define STCU_MBUFM_MBUFM232_SHIFT                (8U)
#define STCU_MBUFM_MBUFM232_WIDTH                (1U)
#define STCU_MBUFM_MBUFM232(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM232_SHIFT)) & STCU_MBUFM_MBUFM232_MASK)

#define STCU_MBUFM_MBUFM233_MASK                 (0x200U)
#define STCU_MBUFM_MBUFM233_SHIFT                (9U)
#define STCU_MBUFM_MBUFM233_WIDTH                (1U)
#define STCU_MBUFM_MBUFM233(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM233_SHIFT)) & STCU_MBUFM_MBUFM233_MASK)

#define STCU_MBUFM_MBUFM234_MASK                 (0x400U)
#define STCU_MBUFM_MBUFM234_SHIFT                (10U)
#define STCU_MBUFM_MBUFM234_WIDTH                (1U)
#define STCU_MBUFM_MBUFM234(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM234_SHIFT)) & STCU_MBUFM_MBUFM234_MASK)

#define STCU_MBUFM_MBUFM235_MASK                 (0x800U)
#define STCU_MBUFM_MBUFM235_SHIFT                (11U)
#define STCU_MBUFM_MBUFM235_WIDTH                (1U)
#define STCU_MBUFM_MBUFM235(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM235_SHIFT)) & STCU_MBUFM_MBUFM235_MASK)

#define STCU_MBUFM_MBUFM236_MASK                 (0x1000U)
#define STCU_MBUFM_MBUFM236_SHIFT                (12U)
#define STCU_MBUFM_MBUFM236_WIDTH                (1U)
#define STCU_MBUFM_MBUFM236(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM236_SHIFT)) & STCU_MBUFM_MBUFM236_MASK)

#define STCU_MBUFM_MBUFM237_MASK                 (0x2000U)
#define STCU_MBUFM_MBUFM237_SHIFT                (13U)
#define STCU_MBUFM_MBUFM237_WIDTH                (1U)
#define STCU_MBUFM_MBUFM237(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM237_SHIFT)) & STCU_MBUFM_MBUFM237_MASK)

#define STCU_MBUFM_MBUFM238_MASK                 (0x4000U)
#define STCU_MBUFM_MBUFM238_SHIFT                (14U)
#define STCU_MBUFM_MBUFM238_WIDTH                (1U)
#define STCU_MBUFM_MBUFM238(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM238_SHIFT)) & STCU_MBUFM_MBUFM238_MASK)

#define STCU_MBUFM_MBUFM239_MASK                 (0x8000U)
#define STCU_MBUFM_MBUFM239_SHIFT                (15U)
#define STCU_MBUFM_MBUFM239_WIDTH                (1U)
#define STCU_MBUFM_MBUFM239(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM239_SHIFT)) & STCU_MBUFM_MBUFM239_MASK)

#define STCU_MBUFM_MBUFM240_MASK                 (0x10000U)
#define STCU_MBUFM_MBUFM240_SHIFT                (16U)
#define STCU_MBUFM_MBUFM240_WIDTH                (1U)
#define STCU_MBUFM_MBUFM240(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM240_SHIFT)) & STCU_MBUFM_MBUFM240_MASK)

#define STCU_MBUFM_MBUFM241_MASK                 (0x20000U)
#define STCU_MBUFM_MBUFM241_SHIFT                (17U)
#define STCU_MBUFM_MBUFM241_WIDTH                (1U)
#define STCU_MBUFM_MBUFM241(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM241_SHIFT)) & STCU_MBUFM_MBUFM241_MASK)

#define STCU_MBUFM_MBUFM242_MASK                 (0x40000U)
#define STCU_MBUFM_MBUFM242_SHIFT                (18U)
#define STCU_MBUFM_MBUFM242_WIDTH                (1U)
#define STCU_MBUFM_MBUFM242(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM242_SHIFT)) & STCU_MBUFM_MBUFM242_MASK)

#define STCU_MBUFM_MBUFM243_MASK                 (0x80000U)
#define STCU_MBUFM_MBUFM243_SHIFT                (19U)
#define STCU_MBUFM_MBUFM243_WIDTH                (1U)
#define STCU_MBUFM_MBUFM243(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM243_SHIFT)) & STCU_MBUFM_MBUFM243_MASK)

#define STCU_MBUFM_MBUFM244_MASK                 (0x100000U)
#define STCU_MBUFM_MBUFM244_SHIFT                (20U)
#define STCU_MBUFM_MBUFM244_WIDTH                (1U)
#define STCU_MBUFM_MBUFM244(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM244_SHIFT)) & STCU_MBUFM_MBUFM244_MASK)

#define STCU_MBUFM_MBUFM245_MASK                 (0x200000U)
#define STCU_MBUFM_MBUFM245_SHIFT                (21U)
#define STCU_MBUFM_MBUFM245_WIDTH                (1U)
#define STCU_MBUFM_MBUFM245(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM245_SHIFT)) & STCU_MBUFM_MBUFM245_MASK)

#define STCU_MBUFM_MBUFM246_MASK                 (0x400000U)
#define STCU_MBUFM_MBUFM246_SHIFT                (22U)
#define STCU_MBUFM_MBUFM246_WIDTH                (1U)
#define STCU_MBUFM_MBUFM246(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM246_SHIFT)) & STCU_MBUFM_MBUFM246_MASK)

#define STCU_MBUFM_MBUFM247_MASK                 (0x800000U)
#define STCU_MBUFM_MBUFM247_SHIFT                (23U)
#define STCU_MBUFM_MBUFM247_WIDTH                (1U)
#define STCU_MBUFM_MBUFM247(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM247_SHIFT)) & STCU_MBUFM_MBUFM247_MASK)

#define STCU_MBUFM_MBUFM248_MASK                 (0x1000000U)
#define STCU_MBUFM_MBUFM248_SHIFT                (24U)
#define STCU_MBUFM_MBUFM248_WIDTH                (1U)
#define STCU_MBUFM_MBUFM248(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM248_SHIFT)) & STCU_MBUFM_MBUFM248_MASK)

#define STCU_MBUFM_MBUFM249_MASK                 (0x2000000U)
#define STCU_MBUFM_MBUFM249_SHIFT                (25U)
#define STCU_MBUFM_MBUFM249_WIDTH                (1U)
#define STCU_MBUFM_MBUFM249(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM249_SHIFT)) & STCU_MBUFM_MBUFM249_MASK)

#define STCU_MBUFM_MBUFM250_MASK                 (0x4000000U)
#define STCU_MBUFM_MBUFM250_SHIFT                (26U)
#define STCU_MBUFM_MBUFM250_WIDTH                (1U)
#define STCU_MBUFM_MBUFM250(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM250_SHIFT)) & STCU_MBUFM_MBUFM250_MASK)

#define STCU_MBUFM_MBUFM251_MASK                 (0x8000000U)
#define STCU_MBUFM_MBUFM251_SHIFT                (27U)
#define STCU_MBUFM_MBUFM251_WIDTH                (1U)
#define STCU_MBUFM_MBUFM251(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM251_SHIFT)) & STCU_MBUFM_MBUFM251_MASK)

#define STCU_MBUFM_MBUFM252_MASK                 (0x10000000U)
#define STCU_MBUFM_MBUFM252_SHIFT                (28U)
#define STCU_MBUFM_MBUFM252_WIDTH                (1U)
#define STCU_MBUFM_MBUFM252(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM252_SHIFT)) & STCU_MBUFM_MBUFM252_MASK)

#define STCU_MBUFM_MBUFM253_MASK                 (0x20000000U)
#define STCU_MBUFM_MBUFM253_SHIFT                (29U)
#define STCU_MBUFM_MBUFM253_WIDTH                (1U)
#define STCU_MBUFM_MBUFM253(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM253_SHIFT)) & STCU_MBUFM_MBUFM253_MASK)

#define STCU_MBUFM_MBUFM254_MASK                 (0x40000000U)
#define STCU_MBUFM_MBUFM254_SHIFT                (30U)
#define STCU_MBUFM_MBUFM254_WIDTH                (1U)
#define STCU_MBUFM_MBUFM254(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM254_SHIFT)) & STCU_MBUFM_MBUFM254_MASK)

#define STCU_MBUFM_MBUFM255_MASK                 (0x80000000U)
#define STCU_MBUFM_MBUFM255_SHIFT                (31U)
#define STCU_MBUFM_MBUFM255_WIDTH                (1U)
#define STCU_MBUFM_MBUFM255(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM_MBUFM255_SHIFT)) & STCU_MBUFM_MBUFM255_MASK)
/*! @} */

/*! @name CTRL - STCU2 LBIST Control */
/*! @{ */

#define STCU_CTRL_CWS_MASK                       (0x3FU)
#define STCU_CTRL_CWS_SHIFT                      (0U)
#define STCU_CTRL_CWS_WIDTH                      (6U)
#define STCU_CTRL_CWS(x)                         (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_CWS_SHIFT)) & STCU_CTRL_CWS_MASK)

#define STCU_CTRL_SCEN_ON_MASK                   (0xF00U)
#define STCU_CTRL_SCEN_ON_SHIFT                  (8U)
#define STCU_CTRL_SCEN_ON_WIDTH                  (4U)
#define STCU_CTRL_SCEN_ON(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_SCEN_ON_SHIFT)) & STCU_CTRL_SCEN_ON_MASK)

#define STCU_CTRL_SCEN_OFF_MASK                  (0xF000U)
#define STCU_CTRL_SCEN_OFF_SHIFT                 (12U)
#define STCU_CTRL_SCEN_OFF_WIDTH                 (4U)
#define STCU_CTRL_SCEN_OFF(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_SCEN_OFF_SHIFT)) & STCU_CTRL_SCEN_OFF_MASK)

#define STCU_CTRL_SHS_MASK                       (0x70000U)
#define STCU_CTRL_SHS_SHIFT                      (16U)
#define STCU_CTRL_SHS_WIDTH                      (3U)
#define STCU_CTRL_SHS(x)                         (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_SHS_SHIFT)) & STCU_CTRL_SHS_MASK)

#define STCU_CTRL_PTR_MASK                       (0x7FE00000U)
#define STCU_CTRL_PTR_SHIFT                      (21U)
#define STCU_CTRL_PTR_WIDTH                      (10U)
#define STCU_CTRL_PTR(x)                         (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_PTR_SHIFT)) & STCU_CTRL_PTR_MASK)

#define STCU_CTRL_CSM_MASK                       (0x80000000U)
#define STCU_CTRL_CSM_SHIFT                      (31U)
#define STCU_CTRL_CSM_WIDTH                      (1U)
#define STCU_CTRL_CSM(x)                         (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_CSM_SHIFT)) & STCU_CTRL_CSM_MASK)
/*! @} */

/*! @name PCS - STCU2 LBIST PC Stop */
/*! @{ */

#define STCU_PCS_PCS_MASK                        (0x3FFFFFFU)
#define STCU_PCS_PCS_SHIFT                       (0U)
#define STCU_PCS_PCS_WIDTH                       (26U)
#define STCU_PCS_PCS(x)                          (((uint32_t)(((uint32_t)(x)) << STCU_PCS_PCS_SHIFT)) & STCU_PCS_PCS_MASK)
/*! @} */

/*! @name MISRELSW - STCU2 Online LBIST MISR Expected Low */
/*! @{ */

#define STCU_MISRELSW_MISRESWx_MASK              (0xFU)
#define STCU_MISRELSW_MISRESWx_SHIFT             (0U)
#define STCU_MISRELSW_MISRESWx_WIDTH             (4U)
#define STCU_MISRELSW_MISRESWx(x)                (((uint32_t)(((uint32_t)(x)) << STCU_MISRELSW_MISRESWx_SHIFT)) & STCU_MISRELSW_MISRESWx_MASK)
/*! @} */

/*! @name MISRRLSW - STCU2 Online LBIST MISR Read Low */
/*! @{ */

#define STCU_MISRRLSW_MISRRSWx_MASK              (0xFU)
#define STCU_MISRRLSW_MISRRSWx_SHIFT             (0U)
#define STCU_MISRRLSW_MISRRSWx_WIDTH             (4U)
#define STCU_MISRRLSW_MISRRSWx(x)                (((uint32_t)(((uint32_t)(x)) << STCU_MISRRLSW_MISRRSWx_SHIFT)) & STCU_MISRRLSW_MISRRSWx_MASK)
/*! @} */

/*! @name ALGOSEL - STCU2 Algorithm Select */
/*! @{ */

#define STCU_ALGOSEL_ALGOSEL0_MASK               (0x1U)
#define STCU_ALGOSEL_ALGOSEL0_SHIFT              (0U)
#define STCU_ALGOSEL_ALGOSEL0_WIDTH              (1U)
#define STCU_ALGOSEL_ALGOSEL0(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL0_SHIFT)) & STCU_ALGOSEL_ALGOSEL0_MASK)

#define STCU_ALGOSEL_ALGOSEL1_MASK               (0x2U)
#define STCU_ALGOSEL_ALGOSEL1_SHIFT              (1U)
#define STCU_ALGOSEL_ALGOSEL1_WIDTH              (1U)
#define STCU_ALGOSEL_ALGOSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL1_SHIFT)) & STCU_ALGOSEL_ALGOSEL1_MASK)

#define STCU_ALGOSEL_ALGOSEL2_MASK               (0x4U)
#define STCU_ALGOSEL_ALGOSEL2_SHIFT              (2U)
#define STCU_ALGOSEL_ALGOSEL2_WIDTH              (1U)
#define STCU_ALGOSEL_ALGOSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL2_SHIFT)) & STCU_ALGOSEL_ALGOSEL2_MASK)

#define STCU_ALGOSEL_ALGOSEL3_MASK               (0x8U)
#define STCU_ALGOSEL_ALGOSEL3_SHIFT              (3U)
#define STCU_ALGOSEL_ALGOSEL3_WIDTH              (1U)
#define STCU_ALGOSEL_ALGOSEL3(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL3_SHIFT)) & STCU_ALGOSEL_ALGOSEL3_MASK)

#define STCU_ALGOSEL_ALGOSEL4_MASK               (0x10U)
#define STCU_ALGOSEL_ALGOSEL4_SHIFT              (4U)
#define STCU_ALGOSEL_ALGOSEL4_WIDTH              (1U)
#define STCU_ALGOSEL_ALGOSEL4(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL4_SHIFT)) & STCU_ALGOSEL_ALGOSEL4_MASK)

#define STCU_ALGOSEL_ALGOSEL5_MASK               (0x20U)
#define STCU_ALGOSEL_ALGOSEL5_SHIFT              (5U)
#define STCU_ALGOSEL_ALGOSEL5_WIDTH              (1U)
#define STCU_ALGOSEL_ALGOSEL5(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL5_SHIFT)) & STCU_ALGOSEL_ALGOSEL5_MASK)

#define STCU_ALGOSEL_ALGOSEL6_MASK               (0x40U)
#define STCU_ALGOSEL_ALGOSEL6_SHIFT              (6U)
#define STCU_ALGOSEL_ALGOSEL6_WIDTH              (1U)
#define STCU_ALGOSEL_ALGOSEL6(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL6_SHIFT)) & STCU_ALGOSEL_ALGOSEL6_MASK)

#define STCU_ALGOSEL_ALGOSEL7_MASK               (0x80U)
#define STCU_ALGOSEL_ALGOSEL7_SHIFT              (7U)
#define STCU_ALGOSEL_ALGOSEL7_WIDTH              (1U)
#define STCU_ALGOSEL_ALGOSEL7(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL7_SHIFT)) & STCU_ALGOSEL_ALGOSEL7_MASK)

#define STCU_ALGOSEL_ALGOSEL8_MASK               (0x100U)
#define STCU_ALGOSEL_ALGOSEL8_SHIFT              (8U)
#define STCU_ALGOSEL_ALGOSEL8_WIDTH              (1U)
#define STCU_ALGOSEL_ALGOSEL8(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL8_SHIFT)) & STCU_ALGOSEL_ALGOSEL8_MASK)

#define STCU_ALGOSEL_ALGOSEL9_MASK               (0x200U)
#define STCU_ALGOSEL_ALGOSEL9_SHIFT              (9U)
#define STCU_ALGOSEL_ALGOSEL9_WIDTH              (1U)
#define STCU_ALGOSEL_ALGOSEL9(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL9_SHIFT)) & STCU_ALGOSEL_ALGOSEL9_MASK)

#define STCU_ALGOSEL_ALGOSEL10_MASK              (0x400U)
#define STCU_ALGOSEL_ALGOSEL10_SHIFT             (10U)
#define STCU_ALGOSEL_ALGOSEL10_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL10(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL10_SHIFT)) & STCU_ALGOSEL_ALGOSEL10_MASK)

#define STCU_ALGOSEL_ALGOSEL11_MASK              (0x800U)
#define STCU_ALGOSEL_ALGOSEL11_SHIFT             (11U)
#define STCU_ALGOSEL_ALGOSEL11_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL11(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL11_SHIFT)) & STCU_ALGOSEL_ALGOSEL11_MASK)

#define STCU_ALGOSEL_ALGOSEL12_MASK              (0x1000U)
#define STCU_ALGOSEL_ALGOSEL12_SHIFT             (12U)
#define STCU_ALGOSEL_ALGOSEL12_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL12(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL12_SHIFT)) & STCU_ALGOSEL_ALGOSEL12_MASK)

#define STCU_ALGOSEL_ALGOSEL13_MASK              (0x2000U)
#define STCU_ALGOSEL_ALGOSEL13_SHIFT             (13U)
#define STCU_ALGOSEL_ALGOSEL13_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL13(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL13_SHIFT)) & STCU_ALGOSEL_ALGOSEL13_MASK)

#define STCU_ALGOSEL_ALGOSEL14_MASK              (0x4000U)
#define STCU_ALGOSEL_ALGOSEL14_SHIFT             (14U)
#define STCU_ALGOSEL_ALGOSEL14_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL14(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL14_SHIFT)) & STCU_ALGOSEL_ALGOSEL14_MASK)

#define STCU_ALGOSEL_ALGOSEL15_MASK              (0x8000U)
#define STCU_ALGOSEL_ALGOSEL15_SHIFT             (15U)
#define STCU_ALGOSEL_ALGOSEL15_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL15(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL15_SHIFT)) & STCU_ALGOSEL_ALGOSEL15_MASK)

#define STCU_ALGOSEL_ALGOSEL16_MASK              (0x10000U)
#define STCU_ALGOSEL_ALGOSEL16_SHIFT             (16U)
#define STCU_ALGOSEL_ALGOSEL16_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL16(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL16_SHIFT)) & STCU_ALGOSEL_ALGOSEL16_MASK)

#define STCU_ALGOSEL_ALGOSEL17_MASK              (0x20000U)
#define STCU_ALGOSEL_ALGOSEL17_SHIFT             (17U)
#define STCU_ALGOSEL_ALGOSEL17_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL17(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL17_SHIFT)) & STCU_ALGOSEL_ALGOSEL17_MASK)

#define STCU_ALGOSEL_ALGOSEL18_MASK              (0x40000U)
#define STCU_ALGOSEL_ALGOSEL18_SHIFT             (18U)
#define STCU_ALGOSEL_ALGOSEL18_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL18(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL18_SHIFT)) & STCU_ALGOSEL_ALGOSEL18_MASK)

#define STCU_ALGOSEL_ALGOSEL19_MASK              (0x80000U)
#define STCU_ALGOSEL_ALGOSEL19_SHIFT             (19U)
#define STCU_ALGOSEL_ALGOSEL19_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL19(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL19_SHIFT)) & STCU_ALGOSEL_ALGOSEL19_MASK)

#define STCU_ALGOSEL_ALGOSEL20_MASK              (0x100000U)
#define STCU_ALGOSEL_ALGOSEL20_SHIFT             (20U)
#define STCU_ALGOSEL_ALGOSEL20_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL20(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL20_SHIFT)) & STCU_ALGOSEL_ALGOSEL20_MASK)

#define STCU_ALGOSEL_ALGOSEL21_MASK              (0x200000U)
#define STCU_ALGOSEL_ALGOSEL21_SHIFT             (21U)
#define STCU_ALGOSEL_ALGOSEL21_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL21(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL21_SHIFT)) & STCU_ALGOSEL_ALGOSEL21_MASK)

#define STCU_ALGOSEL_ALGOSEL22_MASK              (0x400000U)
#define STCU_ALGOSEL_ALGOSEL22_SHIFT             (22U)
#define STCU_ALGOSEL_ALGOSEL22_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL22(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL22_SHIFT)) & STCU_ALGOSEL_ALGOSEL22_MASK)

#define STCU_ALGOSEL_ALGOSEL23_MASK              (0x800000U)
#define STCU_ALGOSEL_ALGOSEL23_SHIFT             (23U)
#define STCU_ALGOSEL_ALGOSEL23_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL23(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL23_SHIFT)) & STCU_ALGOSEL_ALGOSEL23_MASK)

#define STCU_ALGOSEL_ALGOSEL24_MASK              (0x1000000U)
#define STCU_ALGOSEL_ALGOSEL24_SHIFT             (24U)
#define STCU_ALGOSEL_ALGOSEL24_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL24(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL24_SHIFT)) & STCU_ALGOSEL_ALGOSEL24_MASK)

#define STCU_ALGOSEL_ALGOSEL25_MASK              (0x2000000U)
#define STCU_ALGOSEL_ALGOSEL25_SHIFT             (25U)
#define STCU_ALGOSEL_ALGOSEL25_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL25(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL25_SHIFT)) & STCU_ALGOSEL_ALGOSEL25_MASK)

#define STCU_ALGOSEL_ALGOSEL26_MASK              (0x4000000U)
#define STCU_ALGOSEL_ALGOSEL26_SHIFT             (26U)
#define STCU_ALGOSEL_ALGOSEL26_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL26(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL26_SHIFT)) & STCU_ALGOSEL_ALGOSEL26_MASK)

#define STCU_ALGOSEL_ALGOSEL27_MASK              (0x8000000U)
#define STCU_ALGOSEL_ALGOSEL27_SHIFT             (27U)
#define STCU_ALGOSEL_ALGOSEL27_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL27(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL27_SHIFT)) & STCU_ALGOSEL_ALGOSEL27_MASK)

#define STCU_ALGOSEL_ALGOSEL28_MASK              (0x10000000U)
#define STCU_ALGOSEL_ALGOSEL28_SHIFT             (28U)
#define STCU_ALGOSEL_ALGOSEL28_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL28(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL28_SHIFT)) & STCU_ALGOSEL_ALGOSEL28_MASK)

#define STCU_ALGOSEL_ALGOSEL29_MASK              (0x20000000U)
#define STCU_ALGOSEL_ALGOSEL29_SHIFT             (29U)
#define STCU_ALGOSEL_ALGOSEL29_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL29(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL29_SHIFT)) & STCU_ALGOSEL_ALGOSEL29_MASK)

#define STCU_ALGOSEL_ALGOSEL30_MASK              (0x40000000U)
#define STCU_ALGOSEL_ALGOSEL30_SHIFT             (30U)
#define STCU_ALGOSEL_ALGOSEL30_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL30(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL30_SHIFT)) & STCU_ALGOSEL_ALGOSEL30_MASK)

#define STCU_ALGOSEL_ALGOSEL31_MASK              (0x80000000U)
#define STCU_ALGOSEL_ALGOSEL31_SHIFT             (31U)
#define STCU_ALGOSEL_ALGOSEL31_WIDTH             (1U)
#define STCU_ALGOSEL_ALGOSEL31(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL31_SHIFT)) & STCU_ALGOSEL_ALGOSEL31_MASK)
/*! @} */

/*! @name STGGR - STCU2 MBIST Stagger */
/*! @{ */

#define STCU_STGGR_STAG_MASK                     (0xFFFFFFFFU)
#define STCU_STGGR_STAG_SHIFT                    (0U)
#define STCU_STGGR_STAG_WIDTH                    (32U)
#define STCU_STGGR_STAG(x)                       (((uint32_t)(((uint32_t)(x)) << STCU_STGGR_STAG_SHIFT)) & STCU_STGGR_STAG_MASK)
/*! @} */

/*! @name BSTART - STCU2 BIST Start */
/*! @{ */

#define STCU_BSTART_BSTART0_MASK                 (0x1U)
#define STCU_BSTART_BSTART0_SHIFT                (0U)
#define STCU_BSTART_BSTART0_WIDTH                (1U)
#define STCU_BSTART_BSTART0(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART0_SHIFT)) & STCU_BSTART_BSTART0_MASK)

#define STCU_BSTART_BSTART1_MASK                 (0x2U)
#define STCU_BSTART_BSTART1_SHIFT                (1U)
#define STCU_BSTART_BSTART1_WIDTH                (1U)
#define STCU_BSTART_BSTART1(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART1_SHIFT)) & STCU_BSTART_BSTART1_MASK)

#define STCU_BSTART_BSTART2_MASK                 (0x4U)
#define STCU_BSTART_BSTART2_SHIFT                (2U)
#define STCU_BSTART_BSTART2_WIDTH                (1U)
#define STCU_BSTART_BSTART2(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART2_SHIFT)) & STCU_BSTART_BSTART2_MASK)

#define STCU_BSTART_BSTART3_MASK                 (0x8U)
#define STCU_BSTART_BSTART3_SHIFT                (3U)
#define STCU_BSTART_BSTART3_WIDTH                (1U)
#define STCU_BSTART_BSTART3(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART3_SHIFT)) & STCU_BSTART_BSTART3_MASK)

#define STCU_BSTART_BSTART4_MASK                 (0x10U)
#define STCU_BSTART_BSTART4_SHIFT                (4U)
#define STCU_BSTART_BSTART4_WIDTH                (1U)
#define STCU_BSTART_BSTART4(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART4_SHIFT)) & STCU_BSTART_BSTART4_MASK)

#define STCU_BSTART_BSTART5_MASK                 (0x20U)
#define STCU_BSTART_BSTART5_SHIFT                (5U)
#define STCU_BSTART_BSTART5_WIDTH                (1U)
#define STCU_BSTART_BSTART5(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART5_SHIFT)) & STCU_BSTART_BSTART5_MASK)

#define STCU_BSTART_BSTART6_MASK                 (0x40U)
#define STCU_BSTART_BSTART6_SHIFT                (6U)
#define STCU_BSTART_BSTART6_WIDTH                (1U)
#define STCU_BSTART_BSTART6(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART6_SHIFT)) & STCU_BSTART_BSTART6_MASK)

#define STCU_BSTART_BSTART7_MASK                 (0x80U)
#define STCU_BSTART_BSTART7_SHIFT                (7U)
#define STCU_BSTART_BSTART7_WIDTH                (1U)
#define STCU_BSTART_BSTART7(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART7_SHIFT)) & STCU_BSTART_BSTART7_MASK)

#define STCU_BSTART_BSTART8_MASK                 (0x100U)
#define STCU_BSTART_BSTART8_SHIFT                (8U)
#define STCU_BSTART_BSTART8_WIDTH                (1U)
#define STCU_BSTART_BSTART8(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART8_SHIFT)) & STCU_BSTART_BSTART8_MASK)

#define STCU_BSTART_BSTART9_MASK                 (0x200U)
#define STCU_BSTART_BSTART9_SHIFT                (9U)
#define STCU_BSTART_BSTART9_WIDTH                (1U)
#define STCU_BSTART_BSTART9(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART9_SHIFT)) & STCU_BSTART_BSTART9_MASK)

#define STCU_BSTART_BSTART10_MASK                (0x400U)
#define STCU_BSTART_BSTART10_SHIFT               (10U)
#define STCU_BSTART_BSTART10_WIDTH               (1U)
#define STCU_BSTART_BSTART10(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART10_SHIFT)) & STCU_BSTART_BSTART10_MASK)

#define STCU_BSTART_BSTART11_MASK                (0x800U)
#define STCU_BSTART_BSTART11_SHIFT               (11U)
#define STCU_BSTART_BSTART11_WIDTH               (1U)
#define STCU_BSTART_BSTART11(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART11_SHIFT)) & STCU_BSTART_BSTART11_MASK)

#define STCU_BSTART_BSTART12_MASK                (0x1000U)
#define STCU_BSTART_BSTART12_SHIFT               (12U)
#define STCU_BSTART_BSTART12_WIDTH               (1U)
#define STCU_BSTART_BSTART12(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART12_SHIFT)) & STCU_BSTART_BSTART12_MASK)

#define STCU_BSTART_BSTART13_MASK                (0x2000U)
#define STCU_BSTART_BSTART13_SHIFT               (13U)
#define STCU_BSTART_BSTART13_WIDTH               (1U)
#define STCU_BSTART_BSTART13(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART13_SHIFT)) & STCU_BSTART_BSTART13_MASK)

#define STCU_BSTART_BSTART14_MASK                (0x4000U)
#define STCU_BSTART_BSTART14_SHIFT               (14U)
#define STCU_BSTART_BSTART14_WIDTH               (1U)
#define STCU_BSTART_BSTART14(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART14_SHIFT)) & STCU_BSTART_BSTART14_MASK)

#define STCU_BSTART_BSTART15_MASK                (0x8000U)
#define STCU_BSTART_BSTART15_SHIFT               (15U)
#define STCU_BSTART_BSTART15_WIDTH               (1U)
#define STCU_BSTART_BSTART15(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART15_SHIFT)) & STCU_BSTART_BSTART15_MASK)

#define STCU_BSTART_BSTART16_MASK                (0x10000U)
#define STCU_BSTART_BSTART16_SHIFT               (16U)
#define STCU_BSTART_BSTART16_WIDTH               (1U)
#define STCU_BSTART_BSTART16(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART16_SHIFT)) & STCU_BSTART_BSTART16_MASK)

#define STCU_BSTART_BSTART17_MASK                (0x20000U)
#define STCU_BSTART_BSTART17_SHIFT               (17U)
#define STCU_BSTART_BSTART17_WIDTH               (1U)
#define STCU_BSTART_BSTART17(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART17_SHIFT)) & STCU_BSTART_BSTART17_MASK)

#define STCU_BSTART_BSTART18_MASK                (0x40000U)
#define STCU_BSTART_BSTART18_SHIFT               (18U)
#define STCU_BSTART_BSTART18_WIDTH               (1U)
#define STCU_BSTART_BSTART18(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART18_SHIFT)) & STCU_BSTART_BSTART18_MASK)

#define STCU_BSTART_BSTART19_MASK                (0x80000U)
#define STCU_BSTART_BSTART19_SHIFT               (19U)
#define STCU_BSTART_BSTART19_WIDTH               (1U)
#define STCU_BSTART_BSTART19(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART19_SHIFT)) & STCU_BSTART_BSTART19_MASK)

#define STCU_BSTART_BSTART20_MASK                (0x100000U)
#define STCU_BSTART_BSTART20_SHIFT               (20U)
#define STCU_BSTART_BSTART20_WIDTH               (1U)
#define STCU_BSTART_BSTART20(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART20_SHIFT)) & STCU_BSTART_BSTART20_MASK)

#define STCU_BSTART_BSTART21_MASK                (0x200000U)
#define STCU_BSTART_BSTART21_SHIFT               (21U)
#define STCU_BSTART_BSTART21_WIDTH               (1U)
#define STCU_BSTART_BSTART21(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART21_SHIFT)) & STCU_BSTART_BSTART21_MASK)

#define STCU_BSTART_BSTART22_MASK                (0x400000U)
#define STCU_BSTART_BSTART22_SHIFT               (22U)
#define STCU_BSTART_BSTART22_WIDTH               (1U)
#define STCU_BSTART_BSTART22(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART22_SHIFT)) & STCU_BSTART_BSTART22_MASK)

#define STCU_BSTART_BSTART23_MASK                (0x800000U)
#define STCU_BSTART_BSTART23_SHIFT               (23U)
#define STCU_BSTART_BSTART23_WIDTH               (1U)
#define STCU_BSTART_BSTART23(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART23_SHIFT)) & STCU_BSTART_BSTART23_MASK)

#define STCU_BSTART_BSTART24_MASK                (0x1000000U)
#define STCU_BSTART_BSTART24_SHIFT               (24U)
#define STCU_BSTART_BSTART24_WIDTH               (1U)
#define STCU_BSTART_BSTART24(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART24_SHIFT)) & STCU_BSTART_BSTART24_MASK)

#define STCU_BSTART_BSTART25_MASK                (0x2000000U)
#define STCU_BSTART_BSTART25_SHIFT               (25U)
#define STCU_BSTART_BSTART25_WIDTH               (1U)
#define STCU_BSTART_BSTART25(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART25_SHIFT)) & STCU_BSTART_BSTART25_MASK)

#define STCU_BSTART_BSTART26_MASK                (0x4000000U)
#define STCU_BSTART_BSTART26_SHIFT               (26U)
#define STCU_BSTART_BSTART26_WIDTH               (1U)
#define STCU_BSTART_BSTART26(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART26_SHIFT)) & STCU_BSTART_BSTART26_MASK)

#define STCU_BSTART_BSTART27_MASK                (0x8000000U)
#define STCU_BSTART_BSTART27_SHIFT               (27U)
#define STCU_BSTART_BSTART27_WIDTH               (1U)
#define STCU_BSTART_BSTART27(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART27_SHIFT)) & STCU_BSTART_BSTART27_MASK)

#define STCU_BSTART_BSTART28_MASK                (0x10000000U)
#define STCU_BSTART_BSTART28_SHIFT               (28U)
#define STCU_BSTART_BSTART28_WIDTH               (1U)
#define STCU_BSTART_BSTART28(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART28_SHIFT)) & STCU_BSTART_BSTART28_MASK)

#define STCU_BSTART_BSTART29_MASK                (0x20000000U)
#define STCU_BSTART_BSTART29_SHIFT               (29U)
#define STCU_BSTART_BSTART29_WIDTH               (1U)
#define STCU_BSTART_BSTART29(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART29_SHIFT)) & STCU_BSTART_BSTART29_MASK)

#define STCU_BSTART_BSTART30_MASK                (0x40000000U)
#define STCU_BSTART_BSTART30_SHIFT               (30U)
#define STCU_BSTART_BSTART30_WIDTH               (1U)
#define STCU_BSTART_BSTART30(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART30_SHIFT)) & STCU_BSTART_BSTART30_MASK)

#define STCU_BSTART_BSTART31_MASK                (0x80000000U)
#define STCU_BSTART_BSTART31_SHIFT               (31U)
#define STCU_BSTART_BSTART31_WIDTH               (1U)
#define STCU_BSTART_BSTART31(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART31_SHIFT)) & STCU_BSTART_BSTART31_MASK)
/*! @} */

/*! @name MB_CTRL - STCU2 MBIST Control */
/*! @{ */

#define STCU_MB_CTRL_BSEL_MASK                   (0x100000U)
#define STCU_MB_CTRL_BSEL_SHIFT                  (20U)
#define STCU_MB_CTRL_BSEL_WIDTH                  (1U)
#define STCU_MB_CTRL_BSEL(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MB_CTRL_BSEL_SHIFT)) & STCU_MB_CTRL_BSEL_MASK)

#define STCU_MB_CTRL_PTR_MASK                    (0x7FE00000U)
#define STCU_MB_CTRL_PTR_SHIFT                   (21U)
#define STCU_MB_CTRL_PTR_WIDTH                   (10U)
#define STCU_MB_CTRL_PTR(x)                      (((uint32_t)(((uint32_t)(x)) << STCU_MB_CTRL_PTR_SHIFT)) & STCU_MB_CTRL_PTR_MASK)

#define STCU_MB_CTRL_CSM_MASK                    (0x80000000U)
#define STCU_MB_CTRL_CSM_SHIFT                   (31U)
#define STCU_MB_CTRL_CSM_WIDTH                   (1U)
#define STCU_MB_CTRL_CSM(x)                      (((uint32_t)(((uint32_t)(x)) << STCU_MB_CTRL_CSM_SHIFT)) & STCU_MB_CTRL_CSM_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group STCU_Register_Masks */

/*!
 * @}
 */ /* end of group STCU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K311_STCU_H_) */
