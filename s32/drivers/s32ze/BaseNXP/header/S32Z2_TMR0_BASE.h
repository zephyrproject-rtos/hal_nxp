/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_TMR0_BASE.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_TMR0_BASE
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
#if !defined(S32Z2_TMR0_BASE_H_)  /* Check if memory map has not been already included */
#define S32Z2_TMR0_BASE_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TMR0_BASE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMR0_BASE_Peripheral_Access_Layer TMR0_BASE Peripheral Access Layer
 * @{
 */

/** TMR0_BASE - Size of Registers Arrays */
#define TMR0_BASE_TMR_FIPERF_COUNT                3u

/** TMR0_BASE - Register Layout Typedef */
typedef struct {
  __I  uint32_t TMR_ID;                            /**< Module ID Register, offset: 0x0 */
  uint8_t RESERVED_0[4];
  __I  uint32_t TMR_CAPR;                          /**< Timer Capability Register, offset: 0x8 */
  uint8_t RESERVED_1[20];
  __I  uint32_t TMR_FRT_L;                         /**< Timer free running time low register, offset: 0x20 */
  __I  uint32_t TMR_FRT_H;                         /**< Timer free running time high register, offset: 0x24 */
  __I  uint32_t TMR_SRT_L;                         /**< Timer synchronous time low register, offset: 0x28 */
  __I  uint32_t TMR_SRT_H;                         /**< Timer synchronous time high register., offset: 0x2C */
  __I  uint32_t TMR_DEF_CNT_L;                     /**< Default ns timer counter low register, offset: 0x30 */
  __I  uint32_t TMR_DEF_CNT_H;                     /**< Default ns timer counter high register, offset: 0x34 */
  uint8_t RESERVED_2[72];
  __IO uint32_t TMR_CTRL;                          /**< Timer Control Register, offset: 0x80 */
  __IO uint32_t TMR_TEVENT;                        /**< Timer Event Register, offset: 0x84 */
  __IO uint32_t TMR_TEMASK;                        /**< Timer event mask register, offset: 0x88 */
  uint8_t RESERVED_3[8];
  __I  uint32_t TMR_STAT;                          /**< Timer status register, offset: 0x94 */
  __IO uint32_t TMR_CNT_L;                         /**< Timer counter low register, offset: 0x98 */
  __IO uint32_t TMR_CNT_H;                         /**< Timer counter high register, offset: 0x9C */
  __IO uint32_t TMR_ADD;                           /**< Timer addend register, offset: 0xA0 */
  __I  uint32_t TMR_ACC;                           /**< Timer accumulator register, offset: 0xA4 */
  __IO uint32_t TMR_PRSC;                          /**< Timer prescale register, offset: 0xA8 */
  __IO uint32_t TMR_ECTRL;                         /**< Extended timer control register, offset: 0xAC */
  __IO uint32_t TMROFF_L;                          /**< Timer offset low register, offset: 0xB0 */
  __IO uint32_t TMROFF_H;                          /**< Timer offset high register, offset: 0xB4 */
  __IO uint32_t TMR_ALARM1_L;                      /**< Alarm 1 time comparator low register, offset: 0xB8 */
  __IO uint32_t TMR_ALARM1_H;                      /**< Alarm 1 time comparator high register, offset: 0xBC */
  __IO uint32_t TMR_ALARM2_L;                      /**< Alarm 2 time comparator low register, offset: 0xC0 */
  __IO uint32_t TMR_ALARM2_H;                      /**< Alarm 2 time comparator high register, offset: 0xC4 */
  uint8_t RESERVED_4[4];
  __IO uint32_t TMR_ALARM_CTRL;                    /**< Timer Alarm Control Register, offset: 0xCC */
  __IO uint32_t TMR_FIPER[TMR0_BASE_TMR_FIPERF_COUNT]; /**< Timer 1 fixed interval period register..Timer 3 fixed interval period register, array offset: 0xD0, array step: 0x4 */
  __IO uint32_t TMR_FIPER_CTRL;                    /**< Timer FIPER Control Register, offset: 0xDC */
  __I  uint32_t TMR_ETTS1_L;                       /**< External trigger stamp register, offset: 0xE0 */
  __I  uint32_t TMR_ETTS1_H;                       /**< External trigger stamp register, offset: 0xE4 */
  __I  uint32_t TMR_ETTS2_L;                       /**< External trigger stamp register, offset: 0xE8 */
  __I  uint32_t TMR_ETTS2_H;                       /**< External trigger stamp register, offset: 0xEC */
  __I  uint32_t TMR_CUR_TIME_L;                    /**< Timer current time low register, offset: 0xF0 */
  __I  uint32_t TMR_CUR_TIME_H;                    /**< Timer current time high register, offset: 0xF4 */
  __IO uint32_t TMR_PARAM;                         /**< Timer parameter register, offset: 0xF8 */
} TMR0_BASE_Type, *TMR0_BASE_MemMapPtr;

/** Number of instances of the TMR0_BASE module. */
#define TMR0_BASE_INSTANCE_COUNT                 (1u)

/* TMR0_BASE - Peripheral instance base addresses */
/** Peripheral NETC__TMR0_BASE base address */
#define IP_NETC__TMR0_BASE_BASE                  (0x74B40000u)
/** Peripheral NETC__TMR0_BASE base pointer */
#define IP_NETC__TMR0_BASE                       ((TMR0_BASE_Type *)IP_NETC__TMR0_BASE_BASE)
/** Array initializer of TMR0_BASE peripheral base addresses */
#define IP_TMR0_BASE_BASE_ADDRS                  { IP_NETC__TMR0_BASE_BASE }
/** Array initializer of TMR0_BASE peripheral base pointers */
#define IP_TMR0_BASE_BASE_PTRS                   { IP_NETC__TMR0_BASE }

/* ----------------------------------------------------------------------------
   -- TMR0_BASE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMR0_BASE_Register_Masks TMR0_BASE Register Masks
 * @{
 */

/*! @name TMR_ID - Module ID Register */
/*! @{ */

#define TMR0_BASE_TMR_ID_REV_MN_MASK             (0xFFU)
#define TMR0_BASE_TMR_ID_REV_MN_SHIFT            (0U)
#define TMR0_BASE_TMR_ID_REV_MN_WIDTH            (8U)
#define TMR0_BASE_TMR_ID_REV_MN(x)               (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ID_REV_MN_SHIFT)) & TMR0_BASE_TMR_ID_REV_MN_MASK)

#define TMR0_BASE_TMR_ID_REV_MJ_MASK             (0xFF00U)
#define TMR0_BASE_TMR_ID_REV_MJ_SHIFT            (8U)
#define TMR0_BASE_TMR_ID_REV_MJ_WIDTH            (8U)
#define TMR0_BASE_TMR_ID_REV_MJ(x)               (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ID_REV_MJ_SHIFT)) & TMR0_BASE_TMR_ID_REV_MJ_MASK)

#define TMR0_BASE_TMR_ID_TMR_ID_MASK             (0xFFFF0000U)
#define TMR0_BASE_TMR_ID_TMR_ID_SHIFT            (16U)
#define TMR0_BASE_TMR_ID_TMR_ID_WIDTH            (16U)
#define TMR0_BASE_TMR_ID_TMR_ID(x)               (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ID_TMR_ID_SHIFT)) & TMR0_BASE_TMR_ID_TMR_ID_MASK)
/*! @} */

/*! @name TMR_CAPR - Timer Capability Register */
/*! @{ */

#define TMR0_BASE_TMR_CAPR_IEEE_1722_MASK        (0x1U)
#define TMR0_BASE_TMR_CAPR_IEEE_1722_SHIFT       (0U)
#define TMR0_BASE_TMR_CAPR_IEEE_1722_WIDTH       (1U)
#define TMR0_BASE_TMR_CAPR_IEEE_1722(x)          (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CAPR_IEEE_1722_SHIFT)) & TMR0_BASE_TMR_CAPR_IEEE_1722_MASK)

#define TMR0_BASE_TMR_CAPR_ECADJ_MASK            (0x2U)
#define TMR0_BASE_TMR_CAPR_ECADJ_SHIFT           (1U)
#define TMR0_BASE_TMR_CAPR_ECADJ_WIDTH           (1U)
#define TMR0_BASE_TMR_CAPR_ECADJ(x)              (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CAPR_ECADJ_SHIFT)) & TMR0_BASE_TMR_CAPR_ECADJ_MASK)

#define TMR0_BASE_TMR_CAPR_IEEE_8021AS_REV_MASK  (0x4U)
#define TMR0_BASE_TMR_CAPR_IEEE_8021AS_REV_SHIFT (2U)
#define TMR0_BASE_TMR_CAPR_IEEE_8021AS_REV_WIDTH (1U)
#define TMR0_BASE_TMR_CAPR_IEEE_8021AS_REV(x)    (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CAPR_IEEE_8021AS_REV_SHIFT)) & TMR0_BASE_TMR_CAPR_IEEE_8021AS_REV_MASK)

#define TMR0_BASE_TMR_CAPR_NUM_MSIX_MASK         (0x10000U)
#define TMR0_BASE_TMR_CAPR_NUM_MSIX_SHIFT        (16U)
#define TMR0_BASE_TMR_CAPR_NUM_MSIX_WIDTH        (1U)
#define TMR0_BASE_TMR_CAPR_NUM_MSIX(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CAPR_NUM_MSIX_SHIFT)) & TMR0_BASE_TMR_CAPR_NUM_MSIX_MASK)
/*! @} */

/*! @name TMR_FRT_L - Timer free running time low register */
/*! @{ */

#define TMR0_BASE_TMR_FRT_L_TMR_FRT_L_MASK       (0xFFFFFFFFU)
#define TMR0_BASE_TMR_FRT_L_TMR_FRT_L_SHIFT      (0U)
#define TMR0_BASE_TMR_FRT_L_TMR_FRT_L_WIDTH      (32U)
#define TMR0_BASE_TMR_FRT_L_TMR_FRT_L(x)         (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FRT_L_TMR_FRT_L_SHIFT)) & TMR0_BASE_TMR_FRT_L_TMR_FRT_L_MASK)
/*! @} */

/*! @name TMR_FRT_H - Timer free running time high register */
/*! @{ */

#define TMR0_BASE_TMR_FRT_H_TMR_FRT_H_MASK       (0xFFFFFFFFU)
#define TMR0_BASE_TMR_FRT_H_TMR_FRT_H_SHIFT      (0U)
#define TMR0_BASE_TMR_FRT_H_TMR_FRT_H_WIDTH      (32U)
#define TMR0_BASE_TMR_FRT_H_TMR_FRT_H(x)         (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FRT_H_TMR_FRT_H_SHIFT)) & TMR0_BASE_TMR_FRT_H_TMR_FRT_H_MASK)
/*! @} */

/*! @name TMR_SRT_L - Timer synchronous time low register */
/*! @{ */

#define TMR0_BASE_TMR_SRT_L_TMR_SRT_L_MASK       (0xFFFFFFFFU)
#define TMR0_BASE_TMR_SRT_L_TMR_SRT_L_SHIFT      (0U)
#define TMR0_BASE_TMR_SRT_L_TMR_SRT_L_WIDTH      (32U)
#define TMR0_BASE_TMR_SRT_L_TMR_SRT_L(x)         (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_SRT_L_TMR_SRT_L_SHIFT)) & TMR0_BASE_TMR_SRT_L_TMR_SRT_L_MASK)
/*! @} */

/*! @name TMR_SRT_H - Timer synchronous time high register. */
/*! @{ */

#define TMR0_BASE_TMR_SRT_H_TMR_SRT_H_MASK       (0xFFFFFFFFU)
#define TMR0_BASE_TMR_SRT_H_TMR_SRT_H_SHIFT      (0U)
#define TMR0_BASE_TMR_SRT_H_TMR_SRT_H_WIDTH      (32U)
#define TMR0_BASE_TMR_SRT_H_TMR_SRT_H(x)         (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_SRT_H_TMR_SRT_H_SHIFT)) & TMR0_BASE_TMR_SRT_H_TMR_SRT_H_MASK)
/*! @} */

/*! @name TMR_DEF_CNT_L - Default ns timer counter low register */
/*! @{ */

#define TMR0_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L_MASK (0xFFFFFFFFU)
#define TMR0_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L_SHIFT (0U)
#define TMR0_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L_WIDTH (32U)
#define TMR0_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L(x) (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L_SHIFT)) & TMR0_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L_MASK)
/*! @} */

/*! @name TMR_DEF_CNT_H - Default ns timer counter high register */
/*! @{ */

#define TMR0_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H_MASK (0xFFFFFFFFU)
#define TMR0_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H_SHIFT (0U)
#define TMR0_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H_WIDTH (32U)
#define TMR0_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H(x) (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H_SHIFT)) & TMR0_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H_MASK)
/*! @} */

/*! @name TMR_CTRL - Timer Control Register */
/*! @{ */

#define TMR0_BASE_TMR_CTRL_CK_SEL_MASK           (0x3U)
#define TMR0_BASE_TMR_CTRL_CK_SEL_SHIFT          (0U)
#define TMR0_BASE_TMR_CTRL_CK_SEL_WIDTH          (2U)
#define TMR0_BASE_TMR_CTRL_CK_SEL(x)             (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_CK_SEL_SHIFT)) & TMR0_BASE_TMR_CTRL_CK_SEL_MASK)

#define TMR0_BASE_TMR_CTRL_TE_MASK               (0x4U)
#define TMR0_BASE_TMR_CTRL_TE_SHIFT              (2U)
#define TMR0_BASE_TMR_CTRL_TE_WIDTH              (1U)
#define TMR0_BASE_TMR_CTRL_TE(x)                 (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_TE_SHIFT)) & TMR0_BASE_TMR_CTRL_TE_MASK)

#define TMR0_BASE_TMR_CTRL_CIPH_MASK             (0x40U)
#define TMR0_BASE_TMR_CTRL_CIPH_SHIFT            (6U)
#define TMR0_BASE_TMR_CTRL_CIPH_WIDTH            (1U)
#define TMR0_BASE_TMR_CTRL_CIPH(x)               (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_CIPH_SHIFT)) & TMR0_BASE_TMR_CTRL_CIPH_MASK)

#define TMR0_BASE_TMR_CTRL_COPH_MASK             (0x80U)
#define TMR0_BASE_TMR_CTRL_COPH_SHIFT            (7U)
#define TMR0_BASE_TMR_CTRL_COPH_WIDTH            (1U)
#define TMR0_BASE_TMR_CTRL_COPH(x)               (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_COPH_SHIFT)) & TMR0_BASE_TMR_CTRL_COPH_MASK)

#define TMR0_BASE_TMR_CTRL_ETEP1_MASK            (0x100U)
#define TMR0_BASE_TMR_CTRL_ETEP1_SHIFT           (8U)
#define TMR0_BASE_TMR_CTRL_ETEP1_WIDTH           (1U)
#define TMR0_BASE_TMR_CTRL_ETEP1(x)              (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_ETEP1_SHIFT)) & TMR0_BASE_TMR_CTRL_ETEP1_MASK)

#define TMR0_BASE_TMR_CTRL_ETEP2_MASK            (0x200U)
#define TMR0_BASE_TMR_CTRL_ETEP2_SHIFT           (9U)
#define TMR0_BASE_TMR_CTRL_ETEP2_WIDTH           (1U)
#define TMR0_BASE_TMR_CTRL_ETEP2(x)              (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_ETEP2_SHIFT)) & TMR0_BASE_TMR_CTRL_ETEP2_MASK)

#define TMR0_BASE_TMR_CTRL_TCLK_PERIOD_MASK      (0x3FF0000U)
#define TMR0_BASE_TMR_CTRL_TCLK_PERIOD_SHIFT     (16U)
#define TMR0_BASE_TMR_CTRL_TCLK_PERIOD_WIDTH     (10U)
#define TMR0_BASE_TMR_CTRL_TCLK_PERIOD(x)        (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_TCLK_PERIOD_SHIFT)) & TMR0_BASE_TMR_CTRL_TCLK_PERIOD_MASK)

#define TMR0_BASE_TMR_CTRL_PP2L_MASK             (0x4000000U)
#define TMR0_BASE_TMR_CTRL_PP2L_SHIFT            (26U)
#define TMR0_BASE_TMR_CTRL_PP2L_WIDTH            (1U)
#define TMR0_BASE_TMR_CTRL_PP2L(x)               (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_PP2L_SHIFT)) & TMR0_BASE_TMR_CTRL_PP2L_MASK)

#define TMR0_BASE_TMR_CTRL_PP1L_MASK             (0x8000000U)
#define TMR0_BASE_TMR_CTRL_PP1L_SHIFT            (27U)
#define TMR0_BASE_TMR_CTRL_PP1L_WIDTH            (1U)
#define TMR0_BASE_TMR_CTRL_PP1L(x)               (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_PP1L_SHIFT)) & TMR0_BASE_TMR_CTRL_PP1L_MASK)

#define TMR0_BASE_TMR_CTRL_FS_MASK               (0x10000000U)
#define TMR0_BASE_TMR_CTRL_FS_SHIFT              (28U)
#define TMR0_BASE_TMR_CTRL_FS_WIDTH              (1U)
#define TMR0_BASE_TMR_CTRL_FS(x)                 (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_FS_SHIFT)) & TMR0_BASE_TMR_CTRL_FS_MASK)

#define TMR0_BASE_TMR_CTRL_ALM2P_MASK            (0x40000000U)
#define TMR0_BASE_TMR_CTRL_ALM2P_SHIFT           (30U)
#define TMR0_BASE_TMR_CTRL_ALM2P_WIDTH           (1U)
#define TMR0_BASE_TMR_CTRL_ALM2P(x)              (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_ALM2P_SHIFT)) & TMR0_BASE_TMR_CTRL_ALM2P_MASK)

#define TMR0_BASE_TMR_CTRL_ALM1P_MASK            (0x80000000U)
#define TMR0_BASE_TMR_CTRL_ALM1P_SHIFT           (31U)
#define TMR0_BASE_TMR_CTRL_ALM1P_WIDTH           (1U)
#define TMR0_BASE_TMR_CTRL_ALM1P(x)              (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CTRL_ALM1P_SHIFT)) & TMR0_BASE_TMR_CTRL_ALM1P_MASK)
/*! @} */

/*! @name TMR_TEVENT - Timer Event Register */
/*! @{ */

#define TMR0_BASE_TMR_TEVENT_PP3EN_MASK          (0x20U)
#define TMR0_BASE_TMR_TEVENT_PP3EN_SHIFT         (5U)
#define TMR0_BASE_TMR_TEVENT_PP3EN_WIDTH         (1U)
#define TMR0_BASE_TMR_TEVENT_PP3EN(x)            (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEVENT_PP3EN_SHIFT)) & TMR0_BASE_TMR_TEVENT_PP3EN_MASK)

#define TMR0_BASE_TMR_TEVENT_PP2EN_MASK          (0x40U)
#define TMR0_BASE_TMR_TEVENT_PP2EN_SHIFT         (6U)
#define TMR0_BASE_TMR_TEVENT_PP2EN_WIDTH         (1U)
#define TMR0_BASE_TMR_TEVENT_PP2EN(x)            (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEVENT_PP2EN_SHIFT)) & TMR0_BASE_TMR_TEVENT_PP2EN_MASK)

#define TMR0_BASE_TMR_TEVENT_PP1EN_MASK          (0x80U)
#define TMR0_BASE_TMR_TEVENT_PP1EN_SHIFT         (7U)
#define TMR0_BASE_TMR_TEVENT_PP1EN_WIDTH         (1U)
#define TMR0_BASE_TMR_TEVENT_PP1EN(x)            (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEVENT_PP1EN_SHIFT)) & TMR0_BASE_TMR_TEVENT_PP1EN_MASK)

#define TMR0_BASE_TMR_TEVENT_ALM1EN_MASK         (0x10000U)
#define TMR0_BASE_TMR_TEVENT_ALM1EN_SHIFT        (16U)
#define TMR0_BASE_TMR_TEVENT_ALM1EN_WIDTH        (1U)
#define TMR0_BASE_TMR_TEVENT_ALM1EN(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEVENT_ALM1EN_SHIFT)) & TMR0_BASE_TMR_TEVENT_ALM1EN_MASK)

#define TMR0_BASE_TMR_TEVENT_ALM2EN_MASK         (0x20000U)
#define TMR0_BASE_TMR_TEVENT_ALM2EN_SHIFT        (17U)
#define TMR0_BASE_TMR_TEVENT_ALM2EN_WIDTH        (1U)
#define TMR0_BASE_TMR_TEVENT_ALM2EN(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEVENT_ALM2EN_SHIFT)) & TMR0_BASE_TMR_TEVENT_ALM2EN_MASK)

#define TMR0_BASE_TMR_TEVENT_ETS1_THREN_MASK     (0x100000U)
#define TMR0_BASE_TMR_TEVENT_ETS1_THREN_SHIFT    (20U)
#define TMR0_BASE_TMR_TEVENT_ETS1_THREN_WIDTH    (1U)
#define TMR0_BASE_TMR_TEVENT_ETS1_THREN(x)       (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEVENT_ETS1_THREN_SHIFT)) & TMR0_BASE_TMR_TEVENT_ETS1_THREN_MASK)

#define TMR0_BASE_TMR_TEVENT_ETS2_THREN_MASK     (0x200000U)
#define TMR0_BASE_TMR_TEVENT_ETS2_THREN_SHIFT    (21U)
#define TMR0_BASE_TMR_TEVENT_ETS2_THREN_WIDTH    (1U)
#define TMR0_BASE_TMR_TEVENT_ETS2_THREN(x)       (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEVENT_ETS2_THREN_SHIFT)) & TMR0_BASE_TMR_TEVENT_ETS2_THREN_MASK)

#define TMR0_BASE_TMR_TEVENT_ETS1EN_MASK         (0x1000000U)
#define TMR0_BASE_TMR_TEVENT_ETS1EN_SHIFT        (24U)
#define TMR0_BASE_TMR_TEVENT_ETS1EN_WIDTH        (1U)
#define TMR0_BASE_TMR_TEVENT_ETS1EN(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEVENT_ETS1EN_SHIFT)) & TMR0_BASE_TMR_TEVENT_ETS1EN_MASK)

#define TMR0_BASE_TMR_TEVENT_ETS2EN_MASK         (0x2000000U)
#define TMR0_BASE_TMR_TEVENT_ETS2EN_SHIFT        (25U)
#define TMR0_BASE_TMR_TEVENT_ETS2EN_WIDTH        (1U)
#define TMR0_BASE_TMR_TEVENT_ETS2EN(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEVENT_ETS2EN_SHIFT)) & TMR0_BASE_TMR_TEVENT_ETS2EN_MASK)

#define TMR0_BASE_TMR_TEVENT_ETS1_OVEN_MASK      (0x10000000U)
#define TMR0_BASE_TMR_TEVENT_ETS1_OVEN_SHIFT     (28U)
#define TMR0_BASE_TMR_TEVENT_ETS1_OVEN_WIDTH     (1U)
#define TMR0_BASE_TMR_TEVENT_ETS1_OVEN(x)        (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEVENT_ETS1_OVEN_SHIFT)) & TMR0_BASE_TMR_TEVENT_ETS1_OVEN_MASK)

#define TMR0_BASE_TMR_TEVENT_ETS2_OVEN_MASK      (0x20000000U)
#define TMR0_BASE_TMR_TEVENT_ETS2_OVEN_SHIFT     (29U)
#define TMR0_BASE_TMR_TEVENT_ETS2_OVEN_WIDTH     (1U)
#define TMR0_BASE_TMR_TEVENT_ETS2_OVEN(x)        (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEVENT_ETS2_OVEN_SHIFT)) & TMR0_BASE_TMR_TEVENT_ETS2_OVEN_MASK)
/*! @} */

/*! @name TMR_TEMASK - Timer event mask register */
/*! @{ */

#define TMR0_BASE_TMR_TEMASK_PP3EN_MASK          (0x20U)
#define TMR0_BASE_TMR_TEMASK_PP3EN_SHIFT         (5U)
#define TMR0_BASE_TMR_TEMASK_PP3EN_WIDTH         (1U)
#define TMR0_BASE_TMR_TEMASK_PP3EN(x)            (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEMASK_PP3EN_SHIFT)) & TMR0_BASE_TMR_TEMASK_PP3EN_MASK)

#define TMR0_BASE_TMR_TEMASK_PP2EN_MASK          (0x40U)
#define TMR0_BASE_TMR_TEMASK_PP2EN_SHIFT         (6U)
#define TMR0_BASE_TMR_TEMASK_PP2EN_WIDTH         (1U)
#define TMR0_BASE_TMR_TEMASK_PP2EN(x)            (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEMASK_PP2EN_SHIFT)) & TMR0_BASE_TMR_TEMASK_PP2EN_MASK)

#define TMR0_BASE_TMR_TEMASK_PP1EN_MASK          (0x80U)
#define TMR0_BASE_TMR_TEMASK_PP1EN_SHIFT         (7U)
#define TMR0_BASE_TMR_TEMASK_PP1EN_WIDTH         (1U)
#define TMR0_BASE_TMR_TEMASK_PP1EN(x)            (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEMASK_PP1EN_SHIFT)) & TMR0_BASE_TMR_TEMASK_PP1EN_MASK)

#define TMR0_BASE_TMR_TEMASK_ALM1EN_MASK         (0x10000U)
#define TMR0_BASE_TMR_TEMASK_ALM1EN_SHIFT        (16U)
#define TMR0_BASE_TMR_TEMASK_ALM1EN_WIDTH        (1U)
#define TMR0_BASE_TMR_TEMASK_ALM1EN(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEMASK_ALM1EN_SHIFT)) & TMR0_BASE_TMR_TEMASK_ALM1EN_MASK)

#define TMR0_BASE_TMR_TEMASK_ALM2EN_MASK         (0x20000U)
#define TMR0_BASE_TMR_TEMASK_ALM2EN_SHIFT        (17U)
#define TMR0_BASE_TMR_TEMASK_ALM2EN_WIDTH        (1U)
#define TMR0_BASE_TMR_TEMASK_ALM2EN(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEMASK_ALM2EN_SHIFT)) & TMR0_BASE_TMR_TEMASK_ALM2EN_MASK)

#define TMR0_BASE_TMR_TEMASK_ETS1_THREN_MASK     (0x100000U)
#define TMR0_BASE_TMR_TEMASK_ETS1_THREN_SHIFT    (20U)
#define TMR0_BASE_TMR_TEMASK_ETS1_THREN_WIDTH    (1U)
#define TMR0_BASE_TMR_TEMASK_ETS1_THREN(x)       (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEMASK_ETS1_THREN_SHIFT)) & TMR0_BASE_TMR_TEMASK_ETS1_THREN_MASK)

#define TMR0_BASE_TMR_TEMASK_ETS2_THREN_MASK     (0x200000U)
#define TMR0_BASE_TMR_TEMASK_ETS2_THREN_SHIFT    (21U)
#define TMR0_BASE_TMR_TEMASK_ETS2_THREN_WIDTH    (1U)
#define TMR0_BASE_TMR_TEMASK_ETS2_THREN(x)       (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEMASK_ETS2_THREN_SHIFT)) & TMR0_BASE_TMR_TEMASK_ETS2_THREN_MASK)

#define TMR0_BASE_TMR_TEMASK_ETS1EN_MASK         (0x1000000U)
#define TMR0_BASE_TMR_TEMASK_ETS1EN_SHIFT        (24U)
#define TMR0_BASE_TMR_TEMASK_ETS1EN_WIDTH        (1U)
#define TMR0_BASE_TMR_TEMASK_ETS1EN(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEMASK_ETS1EN_SHIFT)) & TMR0_BASE_TMR_TEMASK_ETS1EN_MASK)

#define TMR0_BASE_TMR_TEMASK_ETS2EN_MASK         (0x2000000U)
#define TMR0_BASE_TMR_TEMASK_ETS2EN_SHIFT        (25U)
#define TMR0_BASE_TMR_TEMASK_ETS2EN_WIDTH        (1U)
#define TMR0_BASE_TMR_TEMASK_ETS2EN(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEMASK_ETS2EN_SHIFT)) & TMR0_BASE_TMR_TEMASK_ETS2EN_MASK)

#define TMR0_BASE_TMR_TEMASK_ETS1_OVEN_MASK      (0x10000000U)
#define TMR0_BASE_TMR_TEMASK_ETS1_OVEN_SHIFT     (28U)
#define TMR0_BASE_TMR_TEMASK_ETS1_OVEN_WIDTH     (1U)
#define TMR0_BASE_TMR_TEMASK_ETS1_OVEN(x)        (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEMASK_ETS1_OVEN_SHIFT)) & TMR0_BASE_TMR_TEMASK_ETS1_OVEN_MASK)

#define TMR0_BASE_TMR_TEMASK_ETS2_OVEN_MASK      (0x20000000U)
#define TMR0_BASE_TMR_TEMASK_ETS2_OVEN_SHIFT     (29U)
#define TMR0_BASE_TMR_TEMASK_ETS2_OVEN_WIDTH     (1U)
#define TMR0_BASE_TMR_TEMASK_ETS2_OVEN(x)        (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_TEMASK_ETS2_OVEN_SHIFT)) & TMR0_BASE_TMR_TEMASK_ETS2_OVEN_MASK)
/*! @} */

/*! @name TMR_STAT - Timer status register */
/*! @{ */

#define TMR0_BASE_TMR_STAT_ETS1_VLD_MASK         (0x1000000U)
#define TMR0_BASE_TMR_STAT_ETS1_VLD_SHIFT        (24U)
#define TMR0_BASE_TMR_STAT_ETS1_VLD_WIDTH        (1U)
#define TMR0_BASE_TMR_STAT_ETS1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_STAT_ETS1_VLD_SHIFT)) & TMR0_BASE_TMR_STAT_ETS1_VLD_MASK)

#define TMR0_BASE_TMR_STAT_ETS2_VLD_MASK         (0x2000000U)
#define TMR0_BASE_TMR_STAT_ETS2_VLD_SHIFT        (25U)
#define TMR0_BASE_TMR_STAT_ETS2_VLD_WIDTH        (1U)
#define TMR0_BASE_TMR_STAT_ETS2_VLD(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_STAT_ETS2_VLD_SHIFT)) & TMR0_BASE_TMR_STAT_ETS2_VLD_MASK)

#define TMR0_BASE_TMR_STAT_RCD_MASK              (0x80000000U)
#define TMR0_BASE_TMR_STAT_RCD_SHIFT             (31U)
#define TMR0_BASE_TMR_STAT_RCD_WIDTH             (1U)
#define TMR0_BASE_TMR_STAT_RCD(x)                (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_STAT_RCD_SHIFT)) & TMR0_BASE_TMR_STAT_RCD_MASK)
/*! @} */

/*! @name TMR_CNT_L - Timer counter low register */
/*! @{ */

#define TMR0_BASE_TMR_CNT_L_TMR_CNT_L_MASK       (0xFFFFFFFFU)
#define TMR0_BASE_TMR_CNT_L_TMR_CNT_L_SHIFT      (0U)
#define TMR0_BASE_TMR_CNT_L_TMR_CNT_L_WIDTH      (32U)
#define TMR0_BASE_TMR_CNT_L_TMR_CNT_L(x)         (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CNT_L_TMR_CNT_L_SHIFT)) & TMR0_BASE_TMR_CNT_L_TMR_CNT_L_MASK)
/*! @} */

/*! @name TMR_CNT_H - Timer counter high register */
/*! @{ */

#define TMR0_BASE_TMR_CNT_H_TMR_CNT_H_MASK       (0xFFFFFFFFU)
#define TMR0_BASE_TMR_CNT_H_TMR_CNT_H_SHIFT      (0U)
#define TMR0_BASE_TMR_CNT_H_TMR_CNT_H_WIDTH      (32U)
#define TMR0_BASE_TMR_CNT_H_TMR_CNT_H(x)         (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CNT_H_TMR_CNT_H_SHIFT)) & TMR0_BASE_TMR_CNT_H_TMR_CNT_H_MASK)
/*! @} */

/*! @name TMR_ADD - Timer addend register */
/*! @{ */

#define TMR0_BASE_TMR_ADD_ADDEND_MASK            (0xFFFFFFFFU)
#define TMR0_BASE_TMR_ADD_ADDEND_SHIFT           (0U)
#define TMR0_BASE_TMR_ADD_ADDEND_WIDTH           (32U)
#define TMR0_BASE_TMR_ADD_ADDEND(x)              (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ADD_ADDEND_SHIFT)) & TMR0_BASE_TMR_ADD_ADDEND_MASK)
/*! @} */

/*! @name TMR_ACC - Timer accumulator register */
/*! @{ */

#define TMR0_BASE_TMR_ACC_TMR_ACC_MASK           (0xFFFFFFFFU)
#define TMR0_BASE_TMR_ACC_TMR_ACC_SHIFT          (0U)
#define TMR0_BASE_TMR_ACC_TMR_ACC_WIDTH          (32U)
#define TMR0_BASE_TMR_ACC_TMR_ACC(x)             (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ACC_TMR_ACC_SHIFT)) & TMR0_BASE_TMR_ACC_TMR_ACC_MASK)
/*! @} */

/*! @name TMR_PRSC - Timer prescale register */
/*! @{ */

#define TMR0_BASE_TMR_PRSC_PRSC_OCK_MASK         (0xFFFFU)
#define TMR0_BASE_TMR_PRSC_PRSC_OCK_SHIFT        (0U)
#define TMR0_BASE_TMR_PRSC_PRSC_OCK_WIDTH        (16U)
#define TMR0_BASE_TMR_PRSC_PRSC_OCK(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_PRSC_PRSC_OCK_SHIFT)) & TMR0_BASE_TMR_PRSC_PRSC_OCK_MASK)
/*! @} */

/*! @name TMR_ECTRL - Extended timer control register */
/*! @{ */

#define TMR0_BASE_TMR_ECTRL_ETFF_THR_MASK        (0xFU)
#define TMR0_BASE_TMR_ECTRL_ETFF_THR_SHIFT       (0U)
#define TMR0_BASE_TMR_ECTRL_ETFF_THR_WIDTH       (4U)
#define TMR0_BASE_TMR_ECTRL_ETFF_THR(x)          (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ECTRL_ETFF_THR_SHIFT)) & TMR0_BASE_TMR_ECTRL_ETFF_THR_MASK)
/*! @} */

/*! @name TMROFF_L - Timer offset low register */
/*! @{ */

#define TMR0_BASE_TMROFF_L_TMROFF_L_MASK         (0xFFFFFFFFU)
#define TMR0_BASE_TMROFF_L_TMROFF_L_SHIFT        (0U)
#define TMR0_BASE_TMROFF_L_TMROFF_L_WIDTH        (32U)
#define TMR0_BASE_TMROFF_L_TMROFF_L(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMROFF_L_TMROFF_L_SHIFT)) & TMR0_BASE_TMROFF_L_TMROFF_L_MASK)
/*! @} */

/*! @name TMROFF_H - Timer offset high register */
/*! @{ */

#define TMR0_BASE_TMROFF_H_TMROFF_H_MASK         (0xFFFFFFFFU)
#define TMR0_BASE_TMROFF_H_TMROFF_H_SHIFT        (0U)
#define TMR0_BASE_TMROFF_H_TMROFF_H_WIDTH        (32U)
#define TMR0_BASE_TMROFF_H_TMROFF_H(x)           (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMROFF_H_TMROFF_H_SHIFT)) & TMR0_BASE_TMROFF_H_TMROFF_H_MASK)
/*! @} */

/*! @name TMR_ALARM1_L - Alarm 1 time comparator low register */
/*! @{ */

#define TMR0_BASE_TMR_ALARM1_L_ALARM_L_MASK      (0xFFFFFFFFU)
#define TMR0_BASE_TMR_ALARM1_L_ALARM_L_SHIFT     (0U)
#define TMR0_BASE_TMR_ALARM1_L_ALARM_L_WIDTH     (32U)
#define TMR0_BASE_TMR_ALARM1_L_ALARM_L(x)        (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ALARM1_L_ALARM_L_SHIFT)) & TMR0_BASE_TMR_ALARM1_L_ALARM_L_MASK)
/*! @} */

/*! @name TMR_ALARM1_H - Alarm 1 time comparator high register */
/*! @{ */

#define TMR0_BASE_TMR_ALARM1_H_ALARM_H_MASK      (0xFFFFFFFFU)
#define TMR0_BASE_TMR_ALARM1_H_ALARM_H_SHIFT     (0U)
#define TMR0_BASE_TMR_ALARM1_H_ALARM_H_WIDTH     (32U)
#define TMR0_BASE_TMR_ALARM1_H_ALARM_H(x)        (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ALARM1_H_ALARM_H_SHIFT)) & TMR0_BASE_TMR_ALARM1_H_ALARM_H_MASK)
/*! @} */

/*! @name TMR_ALARM2_L - Alarm 2 time comparator low register */
/*! @{ */

#define TMR0_BASE_TMR_ALARM2_L_ALARM_L_MASK      (0xFFFFFFFFU)
#define TMR0_BASE_TMR_ALARM2_L_ALARM_L_SHIFT     (0U)
#define TMR0_BASE_TMR_ALARM2_L_ALARM_L_WIDTH     (32U)
#define TMR0_BASE_TMR_ALARM2_L_ALARM_L(x)        (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ALARM2_L_ALARM_L_SHIFT)) & TMR0_BASE_TMR_ALARM2_L_ALARM_L_MASK)
/*! @} */

/*! @name TMR_ALARM2_H - Alarm 2 time comparator high register */
/*! @{ */

#define TMR0_BASE_TMR_ALARM2_H_ALARM_H_MASK      (0xFFFFFFFFU)
#define TMR0_BASE_TMR_ALARM2_H_ALARM_H_SHIFT     (0U)
#define TMR0_BASE_TMR_ALARM2_H_ALARM_H_WIDTH     (32U)
#define TMR0_BASE_TMR_ALARM2_H_ALARM_H(x)        (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ALARM2_H_ALARM_H_SHIFT)) & TMR0_BASE_TMR_ALARM2_H_ALARM_H_MASK)
/*! @} */

/*! @name TMR_ALARM_CTRL - Timer Alarm Control Register */
/*! @{ */

#define TMR0_BASE_TMR_ALARM_CTRL_ALARM1_PW_MASK  (0x1FU)
#define TMR0_BASE_TMR_ALARM_CTRL_ALARM1_PW_SHIFT (0U)
#define TMR0_BASE_TMR_ALARM_CTRL_ALARM1_PW_WIDTH (5U)
#define TMR0_BASE_TMR_ALARM_CTRL_ALARM1_PW(x)    (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ALARM_CTRL_ALARM1_PW_SHIFT)) & TMR0_BASE_TMR_ALARM_CTRL_ALARM1_PW_MASK)

#define TMR0_BASE_TMR_ALARM_CTRL_PG1_MASK        (0x80U)
#define TMR0_BASE_TMR_ALARM_CTRL_PG1_SHIFT       (7U)
#define TMR0_BASE_TMR_ALARM_CTRL_PG1_WIDTH       (1U)
#define TMR0_BASE_TMR_ALARM_CTRL_PG1(x)          (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ALARM_CTRL_PG1_SHIFT)) & TMR0_BASE_TMR_ALARM_CTRL_PG1_MASK)

#define TMR0_BASE_TMR_ALARM_CTRL_ALARM2_PW_MASK  (0x1F00U)
#define TMR0_BASE_TMR_ALARM_CTRL_ALARM2_PW_SHIFT (8U)
#define TMR0_BASE_TMR_ALARM_CTRL_ALARM2_PW_WIDTH (5U)
#define TMR0_BASE_TMR_ALARM_CTRL_ALARM2_PW(x)    (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ALARM_CTRL_ALARM2_PW_SHIFT)) & TMR0_BASE_TMR_ALARM_CTRL_ALARM2_PW_MASK)

#define TMR0_BASE_TMR_ALARM_CTRL_PG2_MASK        (0x8000U)
#define TMR0_BASE_TMR_ALARM_CTRL_PG2_SHIFT       (15U)
#define TMR0_BASE_TMR_ALARM_CTRL_PG2_WIDTH       (1U)
#define TMR0_BASE_TMR_ALARM_CTRL_PG2(x)          (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ALARM_CTRL_PG2_SHIFT)) & TMR0_BASE_TMR_ALARM_CTRL_PG2_MASK)
/*! @} */

/*! @name TMR_FIPER - Timer 1 fixed interval period register..Timer 3 fixed interval period register */
/*! @{ */

#define TMR0_BASE_TMR_FIPER_FIPER_MASK           (0xFFFFFFFFU)
#define TMR0_BASE_TMR_FIPER_FIPER_SHIFT          (0U)
#define TMR0_BASE_TMR_FIPER_FIPER_WIDTH          (32U)
#define TMR0_BASE_TMR_FIPER_FIPER(x)             (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FIPER_FIPER_SHIFT)) & TMR0_BASE_TMR_FIPER_FIPER_MASK)
/*! @} */

/*! @name TMR_FIPER_CTRL - Timer FIPER Control Register */
/*! @{ */

#define TMR0_BASE_TMR_FIPER_CTRL_FIPER1_PW_MASK  (0x1FU)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER1_PW_SHIFT (0U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER1_PW_WIDTH (5U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER1_PW(x)    (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FIPER_CTRL_FIPER1_PW_SHIFT)) & TMR0_BASE_TMR_FIPER_CTRL_FIPER1_PW_MASK)

#define TMR0_BASE_TMR_FIPER_CTRL_PG1_MASK        (0x40U)
#define TMR0_BASE_TMR_FIPER_CTRL_PG1_SHIFT       (6U)
#define TMR0_BASE_TMR_FIPER_CTRL_PG1_WIDTH       (1U)
#define TMR0_BASE_TMR_FIPER_CTRL_PG1(x)          (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FIPER_CTRL_PG1_SHIFT)) & TMR0_BASE_TMR_FIPER_CTRL_PG1_MASK)

#define TMR0_BASE_TMR_FIPER_CTRL_FIPER1_DIS_MASK (0x80U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER1_DIS_SHIFT (7U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER1_DIS_WIDTH (1U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER1_DIS(x)   (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FIPER_CTRL_FIPER1_DIS_SHIFT)) & TMR0_BASE_TMR_FIPER_CTRL_FIPER1_DIS_MASK)

#define TMR0_BASE_TMR_FIPER_CTRL_FIPER2_PW_MASK  (0x1F00U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER2_PW_SHIFT (8U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER2_PW_WIDTH (5U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER2_PW(x)    (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FIPER_CTRL_FIPER2_PW_SHIFT)) & TMR0_BASE_TMR_FIPER_CTRL_FIPER2_PW_MASK)

#define TMR0_BASE_TMR_FIPER_CTRL_PG2_MASK        (0x4000U)
#define TMR0_BASE_TMR_FIPER_CTRL_PG2_SHIFT       (14U)
#define TMR0_BASE_TMR_FIPER_CTRL_PG2_WIDTH       (1U)
#define TMR0_BASE_TMR_FIPER_CTRL_PG2(x)          (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FIPER_CTRL_PG2_SHIFT)) & TMR0_BASE_TMR_FIPER_CTRL_PG2_MASK)

#define TMR0_BASE_TMR_FIPER_CTRL_FIPER2_DIS_MASK (0x8000U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER2_DIS_SHIFT (15U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER2_DIS_WIDTH (1U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER2_DIS(x)   (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FIPER_CTRL_FIPER2_DIS_SHIFT)) & TMR0_BASE_TMR_FIPER_CTRL_FIPER2_DIS_MASK)

#define TMR0_BASE_TMR_FIPER_CTRL_FIPER3_PW_MASK  (0x1F0000U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER3_PW_SHIFT (16U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER3_PW_WIDTH (5U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER3_PW(x)    (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FIPER_CTRL_FIPER3_PW_SHIFT)) & TMR0_BASE_TMR_FIPER_CTRL_FIPER3_PW_MASK)

#define TMR0_BASE_TMR_FIPER_CTRL_PG3_MASK        (0x400000U)
#define TMR0_BASE_TMR_FIPER_CTRL_PG3_SHIFT       (22U)
#define TMR0_BASE_TMR_FIPER_CTRL_PG3_WIDTH       (1U)
#define TMR0_BASE_TMR_FIPER_CTRL_PG3(x)          (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FIPER_CTRL_PG3_SHIFT)) & TMR0_BASE_TMR_FIPER_CTRL_PG3_MASK)

#define TMR0_BASE_TMR_FIPER_CTRL_FIPER3_DIS_MASK (0x800000U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER3_DIS_SHIFT (23U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER3_DIS_WIDTH (1U)
#define TMR0_BASE_TMR_FIPER_CTRL_FIPER3_DIS(x)   (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_FIPER_CTRL_FIPER3_DIS_SHIFT)) & TMR0_BASE_TMR_FIPER_CTRL_FIPER3_DIS_MASK)
/*! @} */

/*! @name TMR_ETTS1_L - External trigger stamp register */
/*! @{ */

#define TMR0_BASE_TMR_ETTS1_L_ETTS_L_MASK        (0xFFFFFFFFU)
#define TMR0_BASE_TMR_ETTS1_L_ETTS_L_SHIFT       (0U)
#define TMR0_BASE_TMR_ETTS1_L_ETTS_L_WIDTH       (32U)
#define TMR0_BASE_TMR_ETTS1_L_ETTS_L(x)          (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ETTS1_L_ETTS_L_SHIFT)) & TMR0_BASE_TMR_ETTS1_L_ETTS_L_MASK)
/*! @} */

/*! @name TMR_ETTS1_H - External trigger stamp register */
/*! @{ */

#define TMR0_BASE_TMR_ETTS1_H_ETTS_H_MASK        (0xFFFFFFFFU)
#define TMR0_BASE_TMR_ETTS1_H_ETTS_H_SHIFT       (0U)
#define TMR0_BASE_TMR_ETTS1_H_ETTS_H_WIDTH       (32U)
#define TMR0_BASE_TMR_ETTS1_H_ETTS_H(x)          (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ETTS1_H_ETTS_H_SHIFT)) & TMR0_BASE_TMR_ETTS1_H_ETTS_H_MASK)
/*! @} */

/*! @name TMR_ETTS2_L - External trigger stamp register */
/*! @{ */

#define TMR0_BASE_TMR_ETTS2_L_ETTS_L_MASK        (0xFFFFFFFFU)
#define TMR0_BASE_TMR_ETTS2_L_ETTS_L_SHIFT       (0U)
#define TMR0_BASE_TMR_ETTS2_L_ETTS_L_WIDTH       (32U)
#define TMR0_BASE_TMR_ETTS2_L_ETTS_L(x)          (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ETTS2_L_ETTS_L_SHIFT)) & TMR0_BASE_TMR_ETTS2_L_ETTS_L_MASK)
/*! @} */

/*! @name TMR_ETTS2_H - External trigger stamp register */
/*! @{ */

#define TMR0_BASE_TMR_ETTS2_H_ETTS_H_MASK        (0xFFFFFFFFU)
#define TMR0_BASE_TMR_ETTS2_H_ETTS_H_SHIFT       (0U)
#define TMR0_BASE_TMR_ETTS2_H_ETTS_H_WIDTH       (32U)
#define TMR0_BASE_TMR_ETTS2_H_ETTS_H(x)          (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_ETTS2_H_ETTS_H_SHIFT)) & TMR0_BASE_TMR_ETTS2_H_ETTS_H_MASK)
/*! @} */

/*! @name TMR_CUR_TIME_L - Timer current time low register */
/*! @{ */

#define TMR0_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L_MASK (0xFFFFFFFFU)
#define TMR0_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L_SHIFT (0U)
#define TMR0_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L_WIDTH (32U)
#define TMR0_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L(x) (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L_SHIFT)) & TMR0_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L_MASK)
/*! @} */

/*! @name TMR_CUR_TIME_H - Timer current time high register */
/*! @{ */

#define TMR0_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H_MASK (0xFFFFFFFFU)
#define TMR0_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H_SHIFT (0U)
#define TMR0_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H_WIDTH (32U)
#define TMR0_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H(x) (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H_SHIFT)) & TMR0_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H_MASK)
/*! @} */

/*! @name TMR_PARAM - Timer parameter register */
/*! @{ */

#define TMR0_BASE_TMR_PARAM_SYNC_MASK            (0x1U)
#define TMR0_BASE_TMR_PARAM_SYNC_SHIFT           (0U)
#define TMR0_BASE_TMR_PARAM_SYNC_WIDTH           (1U)
#define TMR0_BASE_TMR_PARAM_SYNC(x)              (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_PARAM_SYNC_SHIFT)) & TMR0_BASE_TMR_PARAM_SYNC_MASK)

#define TMR0_BASE_TMR_PARAM_PARAM_VAL_MASK       (0xFFFFFFFEU)
#define TMR0_BASE_TMR_PARAM_PARAM_VAL_SHIFT      (1U)
#define TMR0_BASE_TMR_PARAM_PARAM_VAL_WIDTH      (31U)
#define TMR0_BASE_TMR_PARAM_PARAM_VAL(x)         (((uint32_t)(((uint32_t)(x)) << TMR0_BASE_TMR_PARAM_PARAM_VAL_SHIFT)) & TMR0_BASE_TMR_PARAM_PARAM_VAL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TMR0_BASE_Register_Masks */

/*!
 * @}
 */ /* end of group TMR0_BASE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_TMR0_BASE_H_) */
