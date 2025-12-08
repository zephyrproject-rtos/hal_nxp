/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_NETC_TMR_BASE.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_NETC_TMR_BASE
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
#if !defined(S32K566_NETC_TMR_BASE_H_)  /* Check if memory map has not been already included */
#define S32K566_NETC_TMR_BASE_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- NETC_TMR_BASE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_TMR_BASE_Peripheral_Access_Layer NETC_TMR_BASE Peripheral Access Layer
 * @{
 */

/** NETC_TMR_BASE - Size of Registers Arrays */
#define NETC_TMR_BASE_ALL_REG_ARRAYS_TMR_ALARMM_COUNT 2u
#define NETC_TMR_BASE_ALL_REG_ARRAYS_TMR_FIPERF_COUNT 3u
#define NETC_TMR_BASE_ALL_REG_ARRAYS_TMR_ETTSN_COUNT 2u
#define NETC_TMR_BASE_ALL_REG_ARRAYS_COUNT        1u
#define NETC_TMR_BASE_AVTP_NUM_COUNT              4u

/** NETC_TMR_BASE - Register Layout Typedef */
typedef struct NETC_TMR_BASE_Struct {
  struct NETC_TMR_BASE_ALL_REG_ARRAYS {            /* offset: 0x0, array step: 0xFC */
    __I  uint32_t TMR_ID;                            /**< Module ID, array offset: 0x0, array step: 0xFC */
    uint8_t RESERVED_0[4];
    __I  uint32_t TMR_CAPR;                          /**< Timer Capability, array offset: 0x8, array step: 0xFC */
    uint8_t RESERVED_1[20];
    __I  uint32_t TMR_FRT_L;                         /**< Timer Free Running Time Low, array offset: 0x20, array step: 0xFC */
    __I  uint32_t TMR_FRT_H;                         /**< Timer Free Running Time High, array offset: 0x24, array step: 0xFC */
    __I  uint32_t TMR_SRT_L;                         /**< Timer Synchronous Time Low, array offset: 0x28, array step: 0xFC */
    __I  uint32_t TMR_SRT_H;                         /**< Timer Synchronous Time High, array offset: 0x2C, array step: 0xFC */
    __I  uint32_t TMR_DEF_CNT_L;                     /**< Default Nanosecond Timer Counter Low, array offset: 0x30, array step: 0xFC */
    __I  uint32_t TMR_DEF_CNT_H;                     /**< Default Nanosecond Timer Counter High, array offset: 0x34, array step: 0xFC */
    uint8_t RESERVED_2[72];
    __IO uint32_t TMR_CTRL;                          /**< Timer Control, array offset: 0x80, array step: 0xFC */
    __IO uint32_t TMR_TEVENT;                        /**< Timer Event, array offset: 0x84, array step: 0xFC */
    __IO uint32_t TMR_TEMASK;                        /**< Timer Event Mask, array offset: 0x88, array step: 0xFC */
    __IO uint32_t TMR_MSIVEC;                        /**< Timer MSI-X Vector, array offset: 0x8C, array step: 0xFC */
    uint8_t RESERVED_3[4];
    __I  uint32_t TMR_STAT;                          /**< Timer Status, array offset: 0x94, array step: 0xFC */
    __IO uint32_t TMR_CNT_L;                         /**< Timer Counter Low, array offset: 0x98, array step: 0xFC */
    __IO uint32_t TMR_CNT_H;                         /**< Timer Counter High, array offset: 0x9C, array step: 0xFC */
    __IO uint32_t TMR_ADD;                           /**< Timer Addend, array offset: 0xA0, array step: 0xFC */
    __I  uint32_t TMR_ACC;                           /**< Timer Accumulator, array offset: 0xA4, array step: 0xFC */
    __IO uint32_t TMR_PRSC;                          /**< Timer Prescale, array offset: 0xA8, array step: 0xFC */
    __IO uint32_t TMR_ECTRL;                         /**< Extended Timer Control, array offset: 0xAC, array step: 0xFC */
    __IO uint32_t TMROFF_L;                          /**< Timer Offset Low, array offset: 0xB0, array step: 0xFC */
    __IO uint32_t TMROFF_H;                          /**< Timer Offset High, array offset: 0xB4, array step: 0xFC */
    struct NETC_TMR_BASE_ALL_REG_ARRAYS_TMR_ALARMM {    /* offset: 0xB8, array step: index*0xFC, index2*0x8 */
      __IO uint32_t TMR_ALARM_L;                       /**< Alarm Time Comparator Low, array offset: 0xB8, array step: index*0xFC, index2*0x8 */
      __IO uint32_t TMR_ALARM_H;                       /**< Alarm Time Comparator High, array offset: 0xBC, array step: index*0xFC, index2*0x8 */
    } TMR_ALARMM[NETC_TMR_BASE_ALL_REG_ARRAYS_TMR_ALARMM_COUNT];
    uint8_t RESERVED_4[4];
    __IO uint32_t TMR_ALARM_CTRL;                    /**< Timer Alarm Control, array offset: 0xCC, array step: 0xFC */
    __IO uint32_t TMR_FIPER[NETC_TMR_BASE_ALL_REG_ARRAYS_TMR_FIPERF_COUNT];   /**< Timer Fixed-Interval Period, array offset: 0xD0, array step: index*0xFC, index2*0x4 */
    __IO uint32_t TMR_FIPER_CTRL;                    /**< Timer FIPER Control, array offset: 0xDC, array step: 0xFC */
    struct NETC_TMR_BASE_ALL_REG_ARRAYS_TMR_ETTSN {    /* offset: 0xE0, array step: index*0xFC, index2*0x8 */
      __I  uint32_t TMR_ETTS_L;                        /**< External Trigger Stamp Low, array offset: 0xE0, array step: index*0xFC, index2*0x8 */
      __I  uint32_t TMR_ETTS_H;                        /**< External Trigger Stamp High, array offset: 0xE4, array step: index*0xFC, index2*0x8 */
    } TMR_ETTSN[NETC_TMR_BASE_ALL_REG_ARRAYS_TMR_ETTSN_COUNT];
    __I  uint32_t TMR_CUR_TIME_L;                    /**< Timer Current Time Low, array offset: 0xF0, array step: 0xFC */
    __I  uint32_t TMR_CUR_TIME_H;                    /**< Timer Current Time High, array offset: 0xF4, array step: 0xFC */
    __IO uint32_t TMR_PARAM;                         /**< Timer Parameter, array offset: 0xF8, array step: 0xFC */
  } ALL_REG_ARRAYS[NETC_TMR_BASE_ALL_REG_ARRAYS_COUNT];
  uint8_t RESERVED_0[130828];
  __I  uint32_t TM_CAPR;                           /**< Timer Media Capability, offset: 0x20008 */
  uint8_t RESERVED_1[244];
  struct NETC_TMR_BASE_AVTP_NUM {                  /* offset: 0x20100, array step: 0x20 */
    __IO uint32_t PTCMR;                             /**< Timer Control Mode 0..Timer Control Mode 3, array offset: 0x20100, array step: 0x20 */
    __I  uint32_t PTCSR;                             /**< Timer Control Status 0..Timer Control Status 3, array offset: 0x20104, array step: 0x20 */
    __IO uint32_t PTSTDR;                            /**< Timestamp Transit Delay 0..Timestamp Transit Delay 3, array offset: 0x20108, array step: 0x20 */
    __IO uint32_t PTCCR;                             /**< Timer Compare Capture 0..Timer Compare Capture 3, array offset: 0x2010C, array step: 0x20 */
    __IO uint32_t PTSAUBAR;                          /**< Timestamp Array Upper Base 0..Timestamp Array Upper Base 3, array offset: 0x20110, array step: 0x20 */
    __IO uint32_t PTSALBAR;                          /**< Timestamp Array Lower Base 0..Timestamp Array Lower Base 3, array offset: 0x20114, array step: 0x20 */
    __IO uint32_t PTSACIR;                           /**< Timestamp Array Consumer Index 0..Timestamp Array Consumer Index 3, array offset: 0x20118, array step: 0x20 */
    __IO uint32_t PTSAPIR;                           /**< Timestamp Array Producer Index 0..Timestamp Array Producer Index 3, array offset: 0x2011C, array step: 0x20 */
  } AVTP_NUM[NETC_TMR_BASE_AVTP_NUM_COUNT];
  uint8_t RESERVED_2[32];
  __IO uint32_t PIER;                              /**< Interrupt Enable, offset: 0x201A0 */
  __IO uint32_t PIDR;                              /**< Interrupt Detect, offset: 0x201A4 */
  __IO uint32_t PMSIVR;                            /**< MSI-X Vector, offset: 0x201A8 */
  uint8_t RESERVED_3[4];
  __IO uint32_t TMR_CAR;                           /**< Timer Interface Cache Attribute 0, offset: 0x201B0 */
} NETC_TMR_BASE_Type, *NETC_TMR_BASE_MemMapPtr;

/** Number of instances of the NETC_TMR_BASE module. */
#define NETC_TMR_BASE_INSTANCE_COUNT             (1u)

/* NETC_TMR_BASE - Peripheral instance base addresses */
/** Peripheral NETC__TMR0_BASE base address */
#define IP_NETC__TMR0_BASE_BASE                  (0x6D0C0000u)
/** Peripheral NETC__TMR0_BASE base pointer */
#define IP_NETC__TMR0_BASE                       ((NETC_TMR_BASE_Type *)IP_NETC__TMR0_BASE_BASE)
/** Array initializer of NETC_TMR_BASE peripheral base addresses */
#define IP_NETC_TMR_BASE_BASE_ADDRS              { IP_NETC__TMR0_BASE_BASE }
/** Array initializer of NETC_TMR_BASE peripheral base pointers */
#define IP_NETC_TMR_BASE_BASE_PTRS               { IP_NETC__TMR0_BASE }

/* ----------------------------------------------------------------------------
   -- NETC_TMR_BASE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_TMR_BASE_Register_Masks NETC_TMR_BASE Register Masks
 * @{
 */

/*! @name TMR_ID - Module ID */
/*! @{ */

#define NETC_TMR_BASE_TMR_ID_REV_MN_MASK         (0xFFU)
#define NETC_TMR_BASE_TMR_ID_REV_MN_SHIFT        (0U)
#define NETC_TMR_BASE_TMR_ID_REV_MN_WIDTH        (8U)
#define NETC_TMR_BASE_TMR_ID_REV_MN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ID_REV_MN_SHIFT)) & NETC_TMR_BASE_TMR_ID_REV_MN_MASK)

#define NETC_TMR_BASE_TMR_ID_REV_MJ_MASK         (0xFF00U)
#define NETC_TMR_BASE_TMR_ID_REV_MJ_SHIFT        (8U)
#define NETC_TMR_BASE_TMR_ID_REV_MJ_WIDTH        (8U)
#define NETC_TMR_BASE_TMR_ID_REV_MJ(x)           (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ID_REV_MJ_SHIFT)) & NETC_TMR_BASE_TMR_ID_REV_MJ_MASK)

#define NETC_TMR_BASE_TMR_ID_TMR_ID_MASK         (0xFFFF0000U)
#define NETC_TMR_BASE_TMR_ID_TMR_ID_SHIFT        (16U)
#define NETC_TMR_BASE_TMR_ID_TMR_ID_WIDTH        (16U)
#define NETC_TMR_BASE_TMR_ID_TMR_ID(x)           (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ID_TMR_ID_SHIFT)) & NETC_TMR_BASE_TMR_ID_TMR_ID_MASK)
/*! @} */

/*! @name TMR_CAPR - Timer Capability */
/*! @{ */

#define NETC_TMR_BASE_TMR_CAPR_ECADJ_MASK        (0x2U)
#define NETC_TMR_BASE_TMR_CAPR_ECADJ_SHIFT       (1U)
#define NETC_TMR_BASE_TMR_CAPR_ECADJ_WIDTH       (1U)
#define NETC_TMR_BASE_TMR_CAPR_ECADJ(x)          (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CAPR_ECADJ_SHIFT)) & NETC_TMR_BASE_TMR_CAPR_ECADJ_MASK)

#define NETC_TMR_BASE_TMR_CAPR_IEEE_8021AS_REV_MASK (0x4U)
#define NETC_TMR_BASE_TMR_CAPR_IEEE_8021AS_REV_SHIFT (2U)
#define NETC_TMR_BASE_TMR_CAPR_IEEE_8021AS_REV_WIDTH (1U)
#define NETC_TMR_BASE_TMR_CAPR_IEEE_8021AS_REV(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CAPR_IEEE_8021AS_REV_SHIFT)) & NETC_TMR_BASE_TMR_CAPR_IEEE_8021AS_REV_MASK)

#define NETC_TMR_BASE_TMR_CAPR_IEEE_1722_MASK    (0x200U)
#define NETC_TMR_BASE_TMR_CAPR_IEEE_1722_SHIFT   (9U)
#define NETC_TMR_BASE_TMR_CAPR_IEEE_1722_WIDTH   (1U)
#define NETC_TMR_BASE_TMR_CAPR_IEEE_1722(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CAPR_IEEE_1722_SHIFT)) & NETC_TMR_BASE_TMR_CAPR_IEEE_1722_MASK)

#define NETC_TMR_BASE_TMR_CAPR_NUM_MSIX_MASK     (0x10000U)
#define NETC_TMR_BASE_TMR_CAPR_NUM_MSIX_SHIFT    (16U)
#define NETC_TMR_BASE_TMR_CAPR_NUM_MSIX_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_CAPR_NUM_MSIX(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CAPR_NUM_MSIX_SHIFT)) & NETC_TMR_BASE_TMR_CAPR_NUM_MSIX_MASK)
/*! @} */

/*! @name TMR_FRT_L - Timer Free Running Time Low */
/*! @{ */

#define NETC_TMR_BASE_TMR_FRT_L_TMR_FRT_L_MASK   (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_FRT_L_TMR_FRT_L_SHIFT  (0U)
#define NETC_TMR_BASE_TMR_FRT_L_TMR_FRT_L_WIDTH  (32U)
#define NETC_TMR_BASE_TMR_FRT_L_TMR_FRT_L(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FRT_L_TMR_FRT_L_SHIFT)) & NETC_TMR_BASE_TMR_FRT_L_TMR_FRT_L_MASK)
/*! @} */

/*! @name TMR_FRT_H - Timer Free Running Time High */
/*! @{ */

#define NETC_TMR_BASE_TMR_FRT_H_TMR_FRT_H_MASK   (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_FRT_H_TMR_FRT_H_SHIFT  (0U)
#define NETC_TMR_BASE_TMR_FRT_H_TMR_FRT_H_WIDTH  (32U)
#define NETC_TMR_BASE_TMR_FRT_H_TMR_FRT_H(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FRT_H_TMR_FRT_H_SHIFT)) & NETC_TMR_BASE_TMR_FRT_H_TMR_FRT_H_MASK)
/*! @} */

/*! @name TMR_SRT_L - Timer Synchronous Time Low */
/*! @{ */

#define NETC_TMR_BASE_TMR_SRT_L_TMR_SRT_L_MASK   (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_SRT_L_TMR_SRT_L_SHIFT  (0U)
#define NETC_TMR_BASE_TMR_SRT_L_TMR_SRT_L_WIDTH  (32U)
#define NETC_TMR_BASE_TMR_SRT_L_TMR_SRT_L(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_SRT_L_TMR_SRT_L_SHIFT)) & NETC_TMR_BASE_TMR_SRT_L_TMR_SRT_L_MASK)
/*! @} */

/*! @name TMR_SRT_H - Timer Synchronous Time High */
/*! @{ */

#define NETC_TMR_BASE_TMR_SRT_H_TMR_SRT_H_MASK   (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_SRT_H_TMR_SRT_H_SHIFT  (0U)
#define NETC_TMR_BASE_TMR_SRT_H_TMR_SRT_H_WIDTH  (32U)
#define NETC_TMR_BASE_TMR_SRT_H_TMR_SRT_H(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_SRT_H_TMR_SRT_H_SHIFT)) & NETC_TMR_BASE_TMR_SRT_H_TMR_SRT_H_MASK)
/*! @} */

/*! @name TMR_DEF_CNT_L - Default Nanosecond Timer Counter Low */
/*! @{ */

#define NETC_TMR_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L_MASK (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L_SHIFT (0U)
#define NETC_TMR_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L_WIDTH (32U)
#define NETC_TMR_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L_SHIFT)) & NETC_TMR_BASE_TMR_DEF_CNT_L_TMR_DEF_CNT_L_MASK)
/*! @} */

/*! @name TMR_DEF_CNT_H - Default Nanosecond Timer Counter High */
/*! @{ */

#define NETC_TMR_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H_MASK (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H_SHIFT (0U)
#define NETC_TMR_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H_WIDTH (32U)
#define NETC_TMR_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H_SHIFT)) & NETC_TMR_BASE_TMR_DEF_CNT_H_TMR_DEF_CNT_H_MASK)
/*! @} */

/*! @name TMR_CTRL - Timer Control */
/*! @{ */

#define NETC_TMR_BASE_TMR_CTRL_CK_SEL_MASK       (0x3U)
#define NETC_TMR_BASE_TMR_CTRL_CK_SEL_SHIFT      (0U)
#define NETC_TMR_BASE_TMR_CTRL_CK_SEL_WIDTH      (2U)
#define NETC_TMR_BASE_TMR_CTRL_CK_SEL(x)         (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_CK_SEL_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_CK_SEL_MASK)

#define NETC_TMR_BASE_TMR_CTRL_TE_MASK           (0x4U)
#define NETC_TMR_BASE_TMR_CTRL_TE_SHIFT          (2U)
#define NETC_TMR_BASE_TMR_CTRL_TE_WIDTH          (1U)
#define NETC_TMR_BASE_TMR_CTRL_TE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_TE_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_TE_MASK)

#define NETC_TMR_BASE_TMR_CTRL_TMSR_MASK         (0x20U)
#define NETC_TMR_BASE_TMR_CTRL_TMSR_SHIFT        (5U)
#define NETC_TMR_BASE_TMR_CTRL_TMSR_WIDTH        (1U)
#define NETC_TMR_BASE_TMR_CTRL_TMSR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_TMSR_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_TMSR_MASK)

#define NETC_TMR_BASE_TMR_CTRL_CIPH_MASK         (0x40U)
#define NETC_TMR_BASE_TMR_CTRL_CIPH_SHIFT        (6U)
#define NETC_TMR_BASE_TMR_CTRL_CIPH_WIDTH        (1U)
#define NETC_TMR_BASE_TMR_CTRL_CIPH(x)           (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_CIPH_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_CIPH_MASK)

#define NETC_TMR_BASE_TMR_CTRL_COPH_MASK         (0x80U)
#define NETC_TMR_BASE_TMR_CTRL_COPH_SHIFT        (7U)
#define NETC_TMR_BASE_TMR_CTRL_COPH_WIDTH        (1U)
#define NETC_TMR_BASE_TMR_CTRL_COPH(x)           (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_COPH_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_COPH_MASK)

#define NETC_TMR_BASE_TMR_CTRL_ETEP1_MASK        (0x100U)
#define NETC_TMR_BASE_TMR_CTRL_ETEP1_SHIFT       (8U)
#define NETC_TMR_BASE_TMR_CTRL_ETEP1_WIDTH       (1U)
#define NETC_TMR_BASE_TMR_CTRL_ETEP1(x)          (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_ETEP1_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_ETEP1_MASK)

#define NETC_TMR_BASE_TMR_CTRL_ETEP2_MASK        (0x200U)
#define NETC_TMR_BASE_TMR_CTRL_ETEP2_SHIFT       (9U)
#define NETC_TMR_BASE_TMR_CTRL_ETEP2_WIDTH       (1U)
#define NETC_TMR_BASE_TMR_CTRL_ETEP2(x)          (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_ETEP2_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_ETEP2_MASK)

#define NETC_TMR_BASE_TMR_CTRL_LDR_MASK          (0x800U)
#define NETC_TMR_BASE_TMR_CTRL_LDR_SHIFT         (11U)
#define NETC_TMR_BASE_TMR_CTRL_LDR_WIDTH         (1U)
#define NETC_TMR_BASE_TMR_CTRL_LDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_LDR_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_LDR_MASK)

#define NETC_TMR_BASE_TMR_CTRL_PTM_MASK          (0x1000U)
#define NETC_TMR_BASE_TMR_CTRL_PTM_SHIFT         (12U)
#define NETC_TMR_BASE_TMR_CTRL_PTM_WIDTH         (1U)
#define NETC_TMR_BASE_TMR_CTRL_PTM(x)            (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_PTM_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_PTM_MASK)

#define NETC_TMR_BASE_TMR_CTRL_COMP_MODE_MASK    (0x8000U)
#define NETC_TMR_BASE_TMR_CTRL_COMP_MODE_SHIFT   (15U)
#define NETC_TMR_BASE_TMR_CTRL_COMP_MODE_WIDTH   (1U)
#define NETC_TMR_BASE_TMR_CTRL_COMP_MODE(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_COMP_MODE_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_COMP_MODE_MASK)

#define NETC_TMR_BASE_TMR_CTRL_TCLK_PERIOD_MASK  (0x3FF0000U)
#define NETC_TMR_BASE_TMR_CTRL_TCLK_PERIOD_SHIFT (16U)
#define NETC_TMR_BASE_TMR_CTRL_TCLK_PERIOD_WIDTH (10U)
#define NETC_TMR_BASE_TMR_CTRL_TCLK_PERIOD(x)    (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_TCLK_PERIOD_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_TCLK_PERIOD_MASK)

#define NETC_TMR_BASE_TMR_CTRL_PP2L_MASK         (0x4000000U)
#define NETC_TMR_BASE_TMR_CTRL_PP2L_SHIFT        (26U)
#define NETC_TMR_BASE_TMR_CTRL_PP2L_WIDTH        (1U)
#define NETC_TMR_BASE_TMR_CTRL_PP2L(x)           (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_PP2L_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_PP2L_MASK)

#define NETC_TMR_BASE_TMR_CTRL_PP1L_MASK         (0x8000000U)
#define NETC_TMR_BASE_TMR_CTRL_PP1L_SHIFT        (27U)
#define NETC_TMR_BASE_TMR_CTRL_PP1L_WIDTH        (1U)
#define NETC_TMR_BASE_TMR_CTRL_PP1L(x)           (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_PP1L_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_PP1L_MASK)

#define NETC_TMR_BASE_TMR_CTRL_FS_MASK           (0x10000000U)
#define NETC_TMR_BASE_TMR_CTRL_FS_SHIFT          (28U)
#define NETC_TMR_BASE_TMR_CTRL_FS_WIDTH          (1U)
#define NETC_TMR_BASE_TMR_CTRL_FS(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_FS_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_FS_MASK)

#define NETC_TMR_BASE_TMR_CTRL_SHADOW_DIS_MASK   (0x20000000U)
#define NETC_TMR_BASE_TMR_CTRL_SHADOW_DIS_SHIFT  (29U)
#define NETC_TMR_BASE_TMR_CTRL_SHADOW_DIS_WIDTH  (1U)
#define NETC_TMR_BASE_TMR_CTRL_SHADOW_DIS(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_SHADOW_DIS_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_SHADOW_DIS_MASK)

#define NETC_TMR_BASE_TMR_CTRL_ALM2P_MASK        (0x40000000U)
#define NETC_TMR_BASE_TMR_CTRL_ALM2P_SHIFT       (30U)
#define NETC_TMR_BASE_TMR_CTRL_ALM2P_WIDTH       (1U)
#define NETC_TMR_BASE_TMR_CTRL_ALM2P(x)          (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_ALM2P_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_ALM2P_MASK)

#define NETC_TMR_BASE_TMR_CTRL_ALM1P_MASK        (0x80000000U)
#define NETC_TMR_BASE_TMR_CTRL_ALM1P_SHIFT       (31U)
#define NETC_TMR_BASE_TMR_CTRL_ALM1P_WIDTH       (1U)
#define NETC_TMR_BASE_TMR_CTRL_ALM1P(x)          (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CTRL_ALM1P_SHIFT)) & NETC_TMR_BASE_TMR_CTRL_ALM1P_MASK)
/*! @} */

/*! @name TMR_TEVENT - Timer Event */
/*! @{ */

#define NETC_TMR_BASE_TMR_TEVENT_PP3EN_MASK      (0x20U)
#define NETC_TMR_BASE_TMR_TEVENT_PP3EN_SHIFT     (5U)
#define NETC_TMR_BASE_TMR_TEVENT_PP3EN_WIDTH     (1U)
#define NETC_TMR_BASE_TMR_TEVENT_PP3EN(x)        (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_PP3EN_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_PP3EN_MASK)

#define NETC_TMR_BASE_TMR_TEVENT_PP2EN_MASK      (0x40U)
#define NETC_TMR_BASE_TMR_TEVENT_PP2EN_SHIFT     (6U)
#define NETC_TMR_BASE_TMR_TEVENT_PP2EN_WIDTH     (1U)
#define NETC_TMR_BASE_TMR_TEVENT_PP2EN(x)        (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_PP2EN_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_PP2EN_MASK)

#define NETC_TMR_BASE_TMR_TEVENT_PP1EN_MASK      (0x80U)
#define NETC_TMR_BASE_TMR_TEVENT_PP1EN_SHIFT     (7U)
#define NETC_TMR_BASE_TMR_TEVENT_PP1EN_WIDTH     (1U)
#define NETC_TMR_BASE_TMR_TEVENT_PP1EN(x)        (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_PP1EN_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_PP1EN_MASK)

#define NETC_TMR_BASE_TMR_TEVENT_ETS1_LOST_MASK  (0x8000U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1_LOST_SHIFT (15U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1_LOST_WIDTH (1U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1_LOST(x)    (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_ETS1_LOST_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_ETS1_LOST_MASK)

#define NETC_TMR_BASE_TMR_TEVENT_ALM1EN_MASK     (0x10000U)
#define NETC_TMR_BASE_TMR_TEVENT_ALM1EN_SHIFT    (16U)
#define NETC_TMR_BASE_TMR_TEVENT_ALM1EN_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_TEVENT_ALM1EN(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_ALM1EN_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_ALM1EN_MASK)

#define NETC_TMR_BASE_TMR_TEVENT_ALM2EN_MASK     (0x20000U)
#define NETC_TMR_BASE_TMR_TEVENT_ALM2EN_SHIFT    (17U)
#define NETC_TMR_BASE_TMR_TEVENT_ALM2EN_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_TEVENT_ALM2EN(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_ALM2EN_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_ALM2EN_MASK)

#define NETC_TMR_BASE_TMR_TEVENT_ETS1_THREN_MASK (0x100000U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1_THREN_SHIFT (20U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1_THREN_WIDTH (1U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1_THREN(x)   (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_ETS1_THREN_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_ETS1_THREN_MASK)

#define NETC_TMR_BASE_TMR_TEVENT_ETS2_THREN_MASK (0x200000U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS2_THREN_SHIFT (21U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS2_THREN_WIDTH (1U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS2_THREN(x)   (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_ETS2_THREN_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_ETS2_THREN_MASK)

#define NETC_TMR_BASE_TMR_TEVENT_ETS1EN_MASK     (0x1000000U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1EN_SHIFT    (24U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1EN_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1EN(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_ETS1EN_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_ETS1EN_MASK)

#define NETC_TMR_BASE_TMR_TEVENT_ETS2EN_MASK     (0x2000000U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS2EN_SHIFT    (25U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS2EN_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS2EN(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_ETS2EN_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_ETS2EN_MASK)

#define NETC_TMR_BASE_TMR_TEVENT_ETS1_OVEN_MASK  (0x10000000U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1_OVEN_SHIFT (28U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1_OVEN_WIDTH (1U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS1_OVEN(x)    (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_ETS1_OVEN_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_ETS1_OVEN_MASK)

#define NETC_TMR_BASE_TMR_TEVENT_ETS2_OVEN_MASK  (0x20000000U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS2_OVEN_SHIFT (29U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS2_OVEN_WIDTH (1U)
#define NETC_TMR_BASE_TMR_TEVENT_ETS2_OVEN(x)    (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEVENT_ETS2_OVEN_SHIFT)) & NETC_TMR_BASE_TMR_TEVENT_ETS2_OVEN_MASK)
/*! @} */

/*! @name TMR_TEMASK - Timer Event Mask */
/*! @{ */

#define NETC_TMR_BASE_TMR_TEMASK_PP3EN_MASK      (0x20U)
#define NETC_TMR_BASE_TMR_TEMASK_PP3EN_SHIFT     (5U)
#define NETC_TMR_BASE_TMR_TEMASK_PP3EN_WIDTH     (1U)
#define NETC_TMR_BASE_TMR_TEMASK_PP3EN(x)        (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_PP3EN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_PP3EN_MASK)

#define NETC_TMR_BASE_TMR_TEMASK_PP2EN_MASK      (0x40U)
#define NETC_TMR_BASE_TMR_TEMASK_PP2EN_SHIFT     (6U)
#define NETC_TMR_BASE_TMR_TEMASK_PP2EN_WIDTH     (1U)
#define NETC_TMR_BASE_TMR_TEMASK_PP2EN(x)        (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_PP2EN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_PP2EN_MASK)

#define NETC_TMR_BASE_TMR_TEMASK_PP1EN_MASK      (0x80U)
#define NETC_TMR_BASE_TMR_TEMASK_PP1EN_SHIFT     (7U)
#define NETC_TMR_BASE_TMR_TEMASK_PP1EN_WIDTH     (1U)
#define NETC_TMR_BASE_TMR_TEMASK_PP1EN(x)        (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_PP1EN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_PP1EN_MASK)

#define NETC_TMR_BASE_TMR_TEMASK_ETS1_LOST_EN_MASK (0x8000U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1_LOST_EN_SHIFT (15U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1_LOST_EN_WIDTH (1U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1_LOST_EN(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_ETS1_LOST_EN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_ETS1_LOST_EN_MASK)

#define NETC_TMR_BASE_TMR_TEMASK_ALM1EN_MASK     (0x10000U)
#define NETC_TMR_BASE_TMR_TEMASK_ALM1EN_SHIFT    (16U)
#define NETC_TMR_BASE_TMR_TEMASK_ALM1EN_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_TEMASK_ALM1EN(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_ALM1EN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_ALM1EN_MASK)

#define NETC_TMR_BASE_TMR_TEMASK_ALM2EN_MASK     (0x20000U)
#define NETC_TMR_BASE_TMR_TEMASK_ALM2EN_SHIFT    (17U)
#define NETC_TMR_BASE_TMR_TEMASK_ALM2EN_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_TEMASK_ALM2EN(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_ALM2EN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_ALM2EN_MASK)

#define NETC_TMR_BASE_TMR_TEMASK_ETS1_THREN_MASK (0x100000U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1_THREN_SHIFT (20U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1_THREN_WIDTH (1U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1_THREN(x)   (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_ETS1_THREN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_ETS1_THREN_MASK)

#define NETC_TMR_BASE_TMR_TEMASK_ETS2_THREN_MASK (0x200000U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS2_THREN_SHIFT (21U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS2_THREN_WIDTH (1U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS2_THREN(x)   (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_ETS2_THREN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_ETS2_THREN_MASK)

#define NETC_TMR_BASE_TMR_TEMASK_ETS1EN_MASK     (0x1000000U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1EN_SHIFT    (24U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1EN_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1EN(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_ETS1EN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_ETS1EN_MASK)

#define NETC_TMR_BASE_TMR_TEMASK_ETS2EN_MASK     (0x2000000U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS2EN_SHIFT    (25U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS2EN_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS2EN(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_ETS2EN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_ETS2EN_MASK)

#define NETC_TMR_BASE_TMR_TEMASK_ETS1_OVEN_MASK  (0x10000000U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1_OVEN_SHIFT (28U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1_OVEN_WIDTH (1U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS1_OVEN(x)    (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_ETS1_OVEN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_ETS1_OVEN_MASK)

#define NETC_TMR_BASE_TMR_TEMASK_ETS2_OVEN_MASK  (0x20000000U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS2_OVEN_SHIFT (29U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS2_OVEN_WIDTH (1U)
#define NETC_TMR_BASE_TMR_TEMASK_ETS2_OVEN(x)    (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_TEMASK_ETS2_OVEN_SHIFT)) & NETC_TMR_BASE_TMR_TEMASK_ETS2_OVEN_MASK)
/*! @} */

/*! @name TMR_MSIVEC - Timer MSI-X Vector */
/*! @{ */

#define NETC_TMR_BASE_TMR_MSIVEC_VECTOR_MASK     (0x1U)
#define NETC_TMR_BASE_TMR_MSIVEC_VECTOR_SHIFT    (0U)
#define NETC_TMR_BASE_TMR_MSIVEC_VECTOR_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_MSIVEC_VECTOR(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_MSIVEC_VECTOR_SHIFT)) & NETC_TMR_BASE_TMR_MSIVEC_VECTOR_MASK)
/*! @} */

/*! @name TMR_STAT - Timer Status */
/*! @{ */

#define NETC_TMR_BASE_TMR_STAT_ETS1_VLD_MASK     (0x1000000U)
#define NETC_TMR_BASE_TMR_STAT_ETS1_VLD_SHIFT    (24U)
#define NETC_TMR_BASE_TMR_STAT_ETS1_VLD_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_STAT_ETS1_VLD(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_STAT_ETS1_VLD_SHIFT)) & NETC_TMR_BASE_TMR_STAT_ETS1_VLD_MASK)

#define NETC_TMR_BASE_TMR_STAT_ETS2_VLD_MASK     (0x2000000U)
#define NETC_TMR_BASE_TMR_STAT_ETS2_VLD_SHIFT    (25U)
#define NETC_TMR_BASE_TMR_STAT_ETS2_VLD_WIDTH    (1U)
#define NETC_TMR_BASE_TMR_STAT_ETS2_VLD(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_STAT_ETS2_VLD_SHIFT)) & NETC_TMR_BASE_TMR_STAT_ETS2_VLD_MASK)

#define NETC_TMR_BASE_TMR_STAT_RCD_MASK          (0x80000000U)
#define NETC_TMR_BASE_TMR_STAT_RCD_SHIFT         (31U)
#define NETC_TMR_BASE_TMR_STAT_RCD_WIDTH         (1U)
#define NETC_TMR_BASE_TMR_STAT_RCD(x)            (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_STAT_RCD_SHIFT)) & NETC_TMR_BASE_TMR_STAT_RCD_MASK)
/*! @} */

/*! @name TMR_CNT_L - Timer Counter Low */
/*! @{ */

#define NETC_TMR_BASE_TMR_CNT_L_TMR_CNT_L_MASK   (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_CNT_L_TMR_CNT_L_SHIFT  (0U)
#define NETC_TMR_BASE_TMR_CNT_L_TMR_CNT_L_WIDTH  (32U)
#define NETC_TMR_BASE_TMR_CNT_L_TMR_CNT_L(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CNT_L_TMR_CNT_L_SHIFT)) & NETC_TMR_BASE_TMR_CNT_L_TMR_CNT_L_MASK)
/*! @} */

/*! @name TMR_CNT_H - Timer Counter High */
/*! @{ */

#define NETC_TMR_BASE_TMR_CNT_H_TMR_CNT_H_MASK   (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_CNT_H_TMR_CNT_H_SHIFT  (0U)
#define NETC_TMR_BASE_TMR_CNT_H_TMR_CNT_H_WIDTH  (32U)
#define NETC_TMR_BASE_TMR_CNT_H_TMR_CNT_H(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CNT_H_TMR_CNT_H_SHIFT)) & NETC_TMR_BASE_TMR_CNT_H_TMR_CNT_H_MASK)
/*! @} */

/*! @name TMR_ADD - Timer Addend */
/*! @{ */

#define NETC_TMR_BASE_TMR_ADD_ADDEND_MASK        (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_ADD_ADDEND_SHIFT       (0U)
#define NETC_TMR_BASE_TMR_ADD_ADDEND_WIDTH       (32U)
#define NETC_TMR_BASE_TMR_ADD_ADDEND(x)          (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ADD_ADDEND_SHIFT)) & NETC_TMR_BASE_TMR_ADD_ADDEND_MASK)
/*! @} */

/*! @name TMR_ACC - Timer Accumulator */
/*! @{ */

#define NETC_TMR_BASE_TMR_ACC_TMR_ACC_MASK       (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_ACC_TMR_ACC_SHIFT      (0U)
#define NETC_TMR_BASE_TMR_ACC_TMR_ACC_WIDTH      (32U)
#define NETC_TMR_BASE_TMR_ACC_TMR_ACC(x)         (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ACC_TMR_ACC_SHIFT)) & NETC_TMR_BASE_TMR_ACC_TMR_ACC_MASK)
/*! @} */

/*! @name TMR_PRSC - Timer Prescale */
/*! @{ */

#define NETC_TMR_BASE_TMR_PRSC_PRSC_OCK_MASK     (0xFFFFU)
#define NETC_TMR_BASE_TMR_PRSC_PRSC_OCK_SHIFT    (0U)
#define NETC_TMR_BASE_TMR_PRSC_PRSC_OCK_WIDTH    (16U)
#define NETC_TMR_BASE_TMR_PRSC_PRSC_OCK(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_PRSC_PRSC_OCK_SHIFT)) & NETC_TMR_BASE_TMR_PRSC_PRSC_OCK_MASK)
/*! @} */

/*! @name TMR_ECTRL - Extended Timer Control */
/*! @{ */

#define NETC_TMR_BASE_TMR_ECTRL_ETFF_THR_MASK    (0xFU)
#define NETC_TMR_BASE_TMR_ECTRL_ETFF_THR_SHIFT   (0U)
#define NETC_TMR_BASE_TMR_ECTRL_ETFF_THR_WIDTH   (4U)
#define NETC_TMR_BASE_TMR_ECTRL_ETFF_THR(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ECTRL_ETFF_THR_SHIFT)) & NETC_TMR_BASE_TMR_ECTRL_ETFF_THR_MASK)
/*! @} */

/*! @name TMROFF_L - Timer Offset Low */
/*! @{ */

#define NETC_TMR_BASE_TMROFF_L_TMROFF_L_MASK     (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMROFF_L_TMROFF_L_SHIFT    (0U)
#define NETC_TMR_BASE_TMROFF_L_TMROFF_L_WIDTH    (32U)
#define NETC_TMR_BASE_TMROFF_L_TMROFF_L(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMROFF_L_TMROFF_L_SHIFT)) & NETC_TMR_BASE_TMROFF_L_TMROFF_L_MASK)
/*! @} */

/*! @name TMROFF_H - Timer Offset High */
/*! @{ */

#define NETC_TMR_BASE_TMROFF_H_TMROFF_H_MASK     (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMROFF_H_TMROFF_H_SHIFT    (0U)
#define NETC_TMR_BASE_TMROFF_H_TMROFF_H_WIDTH    (32U)
#define NETC_TMR_BASE_TMROFF_H_TMROFF_H(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMROFF_H_TMROFF_H_SHIFT)) & NETC_TMR_BASE_TMROFF_H_TMROFF_H_MASK)
/*! @} */

/*! @name TMR_ALARM_L - Alarm Time Comparator Low */
/*! @{ */

#define NETC_TMR_BASE_TMR_ALARM_L_ALARM_L_MASK   (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_ALARM_L_ALARM_L_SHIFT  (0U)
#define NETC_TMR_BASE_TMR_ALARM_L_ALARM_L_WIDTH  (32U)
#define NETC_TMR_BASE_TMR_ALARM_L_ALARM_L(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ALARM_L_ALARM_L_SHIFT)) & NETC_TMR_BASE_TMR_ALARM_L_ALARM_L_MASK)
/*! @} */

/*! @name TMR_ALARM_H - Alarm Time Comparator High */
/*! @{ */

#define NETC_TMR_BASE_TMR_ALARM_H_ALARM_H_MASK   (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_ALARM_H_ALARM_H_SHIFT  (0U)
#define NETC_TMR_BASE_TMR_ALARM_H_ALARM_H_WIDTH  (32U)
#define NETC_TMR_BASE_TMR_ALARM_H_ALARM_H(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ALARM_H_ALARM_H_SHIFT)) & NETC_TMR_BASE_TMR_ALARM_H_ALARM_H_MASK)
/*! @} */

/*! @name TMR_ALARM_CTRL - Timer Alarm Control */
/*! @{ */

#define NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM1_PW_MASK (0x1FU)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM1_PW_SHIFT (0U)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM1_PW_WIDTH (5U)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM1_PW(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM1_PW_SHIFT)) & NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM1_PW_MASK)

#define NETC_TMR_BASE_TMR_ALARM_CTRL_PG1_MASK    (0x80U)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_PG1_SHIFT   (7U)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_PG1_WIDTH   (1U)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_PG1(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ALARM_CTRL_PG1_SHIFT)) & NETC_TMR_BASE_TMR_ALARM_CTRL_PG1_MASK)

#define NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM2_PW_MASK (0x1F00U)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM2_PW_SHIFT (8U)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM2_PW_WIDTH (5U)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM2_PW(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM2_PW_SHIFT)) & NETC_TMR_BASE_TMR_ALARM_CTRL_ALARM2_PW_MASK)

#define NETC_TMR_BASE_TMR_ALARM_CTRL_PG2_MASK    (0x8000U)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_PG2_SHIFT   (15U)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_PG2_WIDTH   (1U)
#define NETC_TMR_BASE_TMR_ALARM_CTRL_PG2(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ALARM_CTRL_PG2_SHIFT)) & NETC_TMR_BASE_TMR_ALARM_CTRL_PG2_MASK)
/*! @} */

/*! @name TMR_FIPER - Timer Fixed-Interval Period */
/*! @{ */

#define NETC_TMR_BASE_TMR_FIPER_FIPER_MASK       (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_FIPER_FIPER_SHIFT      (0U)
#define NETC_TMR_BASE_TMR_FIPER_FIPER_WIDTH      (32U)
#define NETC_TMR_BASE_TMR_FIPER_FIPER(x)         (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FIPER_FIPER_SHIFT)) & NETC_TMR_BASE_TMR_FIPER_FIPER_MASK)
/*! @} */

/*! @name TMR_FIPER_CTRL - Timer FIPER Control */
/*! @{ */

#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_PW_MASK (0x1FU)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_PW_SHIFT (0U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_PW_WIDTH (5U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_PW(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_PW_SHIFT)) & NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_PW_MASK)

#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG1_MASK    (0x40U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG1_SHIFT   (6U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG1_WIDTH   (1U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG1(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FIPER_CTRL_PG1_SHIFT)) & NETC_TMR_BASE_TMR_FIPER_CTRL_PG1_MASK)

#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_DIS_MASK (0x80U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_DIS_SHIFT (7U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_DIS_WIDTH (1U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_DIS(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_DIS_SHIFT)) & NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER1_DIS_MASK)

#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_PW_MASK (0x1F00U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_PW_SHIFT (8U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_PW_WIDTH (5U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_PW(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_PW_SHIFT)) & NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_PW_MASK)

#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG2_MASK    (0x4000U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG2_SHIFT   (14U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG2_WIDTH   (1U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG2(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FIPER_CTRL_PG2_SHIFT)) & NETC_TMR_BASE_TMR_FIPER_CTRL_PG2_MASK)

#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_DIS_MASK (0x8000U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_DIS_SHIFT (15U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_DIS_WIDTH (1U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_DIS(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_DIS_SHIFT)) & NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER2_DIS_MASK)

#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_PW_MASK (0x1F0000U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_PW_SHIFT (16U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_PW_WIDTH (5U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_PW(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_PW_SHIFT)) & NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_PW_MASK)

#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG3_MASK    (0x400000U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG3_SHIFT   (22U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG3_WIDTH   (1U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_PG3(x)      (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FIPER_CTRL_PG3_SHIFT)) & NETC_TMR_BASE_TMR_FIPER_CTRL_PG3_MASK)

#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_DIS_MASK (0x800000U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_DIS_SHIFT (23U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_DIS_WIDTH (1U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_DIS(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_DIS_SHIFT)) & NETC_TMR_BASE_TMR_FIPER_CTRL_FIPER3_DIS_MASK)

#define NETC_TMR_BASE_TMR_FIPER_CTRL_RELAY_EN_MASK (0x1000000U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_RELAY_EN_SHIFT (24U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_RELAY_EN_WIDTH (1U)
#define NETC_TMR_BASE_TMR_FIPER_CTRL_RELAY_EN(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_FIPER_CTRL_RELAY_EN_SHIFT)) & NETC_TMR_BASE_TMR_FIPER_CTRL_RELAY_EN_MASK)
/*! @} */

/*! @name TMR_ETTS_L - External Trigger Stamp Low */
/*! @{ */

#define NETC_TMR_BASE_TMR_ETTS_L_ETTS_L_MASK     (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_ETTS_L_ETTS_L_SHIFT    (0U)
#define NETC_TMR_BASE_TMR_ETTS_L_ETTS_L_WIDTH    (32U)
#define NETC_TMR_BASE_TMR_ETTS_L_ETTS_L(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ETTS_L_ETTS_L_SHIFT)) & NETC_TMR_BASE_TMR_ETTS_L_ETTS_L_MASK)
/*! @} */

/*! @name TMR_ETTS_H - External Trigger Stamp High */
/*! @{ */

#define NETC_TMR_BASE_TMR_ETTS_H_ETTS_H_MASK     (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_ETTS_H_ETTS_H_SHIFT    (0U)
#define NETC_TMR_BASE_TMR_ETTS_H_ETTS_H_WIDTH    (32U)
#define NETC_TMR_BASE_TMR_ETTS_H_ETTS_H(x)       (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_ETTS_H_ETTS_H_SHIFT)) & NETC_TMR_BASE_TMR_ETTS_H_ETTS_H_MASK)
/*! @} */

/*! @name TMR_CUR_TIME_L - Timer Current Time Low */
/*! @{ */

#define NETC_TMR_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L_MASK (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L_SHIFT (0U)
#define NETC_TMR_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L_WIDTH (32U)
#define NETC_TMR_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L_SHIFT)) & NETC_TMR_BASE_TMR_CUR_TIME_L_TMR_CUR_TIME_L_MASK)
/*! @} */

/*! @name TMR_CUR_TIME_H - Timer Current Time High */
/*! @{ */

#define NETC_TMR_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H_MASK (0xFFFFFFFFU)
#define NETC_TMR_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H_SHIFT (0U)
#define NETC_TMR_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H_WIDTH (32U)
#define NETC_TMR_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H(x) (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H_SHIFT)) & NETC_TMR_BASE_TMR_CUR_TIME_H_TMR_CUR_TIME_H_MASK)
/*! @} */

/*! @name TMR_PARAM - Timer Parameter */
/*! @{ */

#define NETC_TMR_BASE_TMR_PARAM_SYNC_MASK        (0x1U)
#define NETC_TMR_BASE_TMR_PARAM_SYNC_SHIFT       (0U)
#define NETC_TMR_BASE_TMR_PARAM_SYNC_WIDTH       (1U)
#define NETC_TMR_BASE_TMR_PARAM_SYNC(x)          (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_PARAM_SYNC_SHIFT)) & NETC_TMR_BASE_TMR_PARAM_SYNC_MASK)

#define NETC_TMR_BASE_TMR_PARAM_PARAM_VAL_MASK   (0xFFFFFFFEU)
#define NETC_TMR_BASE_TMR_PARAM_PARAM_VAL_SHIFT  (1U)
#define NETC_TMR_BASE_TMR_PARAM_PARAM_VAL_WIDTH  (31U)
#define NETC_TMR_BASE_TMR_PARAM_PARAM_VAL(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_PARAM_PARAM_VAL_SHIFT)) & NETC_TMR_BASE_TMR_PARAM_PARAM_VAL_MASK)
/*! @} */

/*! @name TM_CAPR - Timer Media Capability */
/*! @{ */

#define NETC_TMR_BASE_TM_CAPR_NUM_CH_MASK        (0x7U)
#define NETC_TMR_BASE_TM_CAPR_NUM_CH_SHIFT       (0U)
#define NETC_TMR_BASE_TM_CAPR_NUM_CH_WIDTH       (3U)
#define NETC_TMR_BASE_TM_CAPR_NUM_CH(x)          (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TM_CAPR_NUM_CH_SHIFT)) & NETC_TMR_BASE_TM_CAPR_NUM_CH_MASK)

#define NETC_TMR_BASE_TM_CAPR_NUM_MSIX_MASK      (0x10000U)
#define NETC_TMR_BASE_TM_CAPR_NUM_MSIX_SHIFT     (16U)
#define NETC_TMR_BASE_TM_CAPR_NUM_MSIX_WIDTH     (1U)
#define NETC_TMR_BASE_TM_CAPR_NUM_MSIX(x)        (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TM_CAPR_NUM_MSIX_SHIFT)) & NETC_TMR_BASE_TM_CAPR_NUM_MSIX_MASK)
/*! @} */

/*! @name PTCMR - Timer Control Mode 0..Timer Control Mode 3 */
/*! @{ */

#define NETC_TMR_BASE_PTCMR_TMODE_MASK           (0xFU)
#define NETC_TMR_BASE_PTCMR_TMODE_SHIFT          (0U)
#define NETC_TMR_BASE_PTCMR_TMODE_WIDTH          (4U)
#define NETC_TMR_BASE_PTCMR_TMODE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTCMR_TMODE_SHIFT)) & NETC_TMR_BASE_PTCMR_TMODE_MASK)

#define NETC_TMR_BASE_PTCMR_TDRE_MASK            (0x10U)
#define NETC_TMR_BASE_PTCMR_TDRE_SHIFT           (4U)
#define NETC_TMR_BASE_PTCMR_TDRE_WIDTH           (1U)
#define NETC_TMR_BASE_PTCMR_TDRE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTCMR_TDRE_SHIFT)) & NETC_TMR_BASE_PTCMR_TDRE_MASK)

#define NETC_TMR_BASE_PTCMR_THRESHOLD_MASK       (0x7E0U)
#define NETC_TMR_BASE_PTCMR_THRESHOLD_SHIFT      (5U)
#define NETC_TMR_BASE_PTCMR_THRESHOLD_WIDTH      (6U)
#define NETC_TMR_BASE_PTCMR_THRESHOLD(x)         (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTCMR_THRESHOLD_SHIFT)) & NETC_TMR_BASE_PTCMR_THRESHOLD_MASK)

#define NETC_TMR_BASE_PTCMR_TPCW_MASK            (0xF800U)
#define NETC_TMR_BASE_PTCMR_TPCW_SHIFT           (11U)
#define NETC_TMR_BASE_PTCMR_TPCW_WIDTH           (5U)
#define NETC_TMR_BASE_PTCMR_TPCW(x)              (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTCMR_TPCW_SHIFT)) & NETC_TMR_BASE_PTCMR_TPCW_MASK)
/*! @} */

/*! @name PTCSR - Timer Control Status 0..Timer Control Status 3 */
/*! @{ */

#define NETC_TMR_BASE_PTCSR_TF_MASK              (0x1U)
#define NETC_TMR_BASE_PTCSR_TF_SHIFT             (0U)
#define NETC_TMR_BASE_PTCSR_TF_WIDTH             (1U)
#define NETC_TMR_BASE_PTCSR_TF(x)                (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTCSR_TF_SHIFT)) & NETC_TMR_BASE_PTCSR_TF_MASK)

#define NETC_TMR_BASE_PTCSR_TRF_MASK             (0x2U)
#define NETC_TMR_BASE_PTCSR_TRF_SHIFT            (1U)
#define NETC_TMR_BASE_PTCSR_TRF_WIDTH            (1U)
#define NETC_TMR_BASE_PTCSR_TRF(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTCSR_TRF_SHIFT)) & NETC_TMR_BASE_PTCSR_TRF_MASK)

#define NETC_TMR_BASE_PTCSR_TTC_MASK             (0x4U)
#define NETC_TMR_BASE_PTCSR_TTC_SHIFT            (2U)
#define NETC_TMR_BASE_PTCSR_TTC_WIDTH            (1U)
#define NETC_TMR_BASE_PTCSR_TTC(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTCSR_TTC_SHIFT)) & NETC_TMR_BASE_PTCSR_TTC_MASK)

#define NETC_TMR_BASE_PTCSR_TAE_MASK             (0x8U)
#define NETC_TMR_BASE_PTCSR_TAE_SHIFT            (3U)
#define NETC_TMR_BASE_PTCSR_TAE_WIDTH            (1U)
#define NETC_TMR_BASE_PTCSR_TAE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTCSR_TAE_SHIFT)) & NETC_TMR_BASE_PTCSR_TAE_MASK)
/*! @} */

/*! @name PTSTDR - Timestamp Transit Delay 0..Timestamp Transit Delay 3 */
/*! @{ */

#define NETC_TMR_BASE_PTSTDR_TD_MASK             (0xFFFFFFFFU)
#define NETC_TMR_BASE_PTSTDR_TD_SHIFT            (0U)
#define NETC_TMR_BASE_PTSTDR_TD_WIDTH            (32U)
#define NETC_TMR_BASE_PTSTDR_TD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTSTDR_TD_SHIFT)) & NETC_TMR_BASE_PTSTDR_TD_MASK)
/*! @} */

/*! @name PTCCR - Timer Compare Capture 0..Timer Compare Capture 3 */
/*! @{ */

#define NETC_TMR_BASE_PTCCR_TCC_MASK             (0xFFFFFFFFU)
#define NETC_TMR_BASE_PTCCR_TCC_SHIFT            (0U)
#define NETC_TMR_BASE_PTCCR_TCC_WIDTH            (32U)
#define NETC_TMR_BASE_PTCCR_TCC(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTCCR_TCC_SHIFT)) & NETC_TMR_BASE_PTCCR_TCC_MASK)
/*! @} */

/*! @name PTSAUBAR - Timestamp Array Upper Base 0..Timestamp Array Upper Base 3 */
/*! @{ */

#define NETC_TMR_BASE_PTSAUBAR_BASE_UADDR_MASK   (0xFFFFFFFFU)
#define NETC_TMR_BASE_PTSAUBAR_BASE_UADDR_SHIFT  (0U)
#define NETC_TMR_BASE_PTSAUBAR_BASE_UADDR_WIDTH  (32U)
#define NETC_TMR_BASE_PTSAUBAR_BASE_UADDR(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTSAUBAR_BASE_UADDR_SHIFT)) & NETC_TMR_BASE_PTSAUBAR_BASE_UADDR_MASK)
/*! @} */

/*! @name PTSALBAR - Timestamp Array Lower Base 0..Timestamp Array Lower Base 3 */
/*! @{ */

#define NETC_TMR_BASE_PTSALBAR_BASE_LADDR_MASK   (0xFFFFFF00U)
#define NETC_TMR_BASE_PTSALBAR_BASE_LADDR_SHIFT  (8U)
#define NETC_TMR_BASE_PTSALBAR_BASE_LADDR_WIDTH  (24U)
#define NETC_TMR_BASE_PTSALBAR_BASE_LADDR(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTSALBAR_BASE_LADDR_SHIFT)) & NETC_TMR_BASE_PTSALBAR_BASE_LADDR_MASK)
/*! @} */

/*! @name PTSACIR - Timestamp Array Consumer Index 0..Timestamp Array Consumer Index 3 */
/*! @{ */

#define NETC_TMR_BASE_PTSACIR_CI_MASK            (0x7FU)
#define NETC_TMR_BASE_PTSACIR_CI_SHIFT           (0U)
#define NETC_TMR_BASE_PTSACIR_CI_WIDTH           (7U)
#define NETC_TMR_BASE_PTSACIR_CI(x)              (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTSACIR_CI_SHIFT)) & NETC_TMR_BASE_PTSACIR_CI_MASK)
/*! @} */

/*! @name PTSAPIR - Timestamp Array Producer Index 0..Timestamp Array Producer Index 3 */
/*! @{ */

#define NETC_TMR_BASE_PTSAPIR_PI_MASK            (0x7FU)
#define NETC_TMR_BASE_PTSAPIR_PI_SHIFT           (0U)
#define NETC_TMR_BASE_PTSAPIR_PI_WIDTH           (7U)
#define NETC_TMR_BASE_PTSAPIR_PI(x)              (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PTSAPIR_PI_SHIFT)) & NETC_TMR_BASE_PTSAPIR_PI_MASK)
/*! @} */

/*! @name PIER - Interrupt Enable */
/*! @{ */

#define NETC_TMR_BASE_PIER_TF0IE_MASK            (0x1U)
#define NETC_TMR_BASE_PIER_TF0IE_SHIFT           (0U)
#define NETC_TMR_BASE_PIER_TF0IE_WIDTH           (1U)
#define NETC_TMR_BASE_PIER_TF0IE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TF0IE_SHIFT)) & NETC_TMR_BASE_PIER_TF0IE_MASK)

#define NETC_TMR_BASE_PIER_TRF0IE_MASK           (0x2U)
#define NETC_TMR_BASE_PIER_TRF0IE_SHIFT          (1U)
#define NETC_TMR_BASE_PIER_TRF0IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TRF0IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TRF0IE_SHIFT)) & NETC_TMR_BASE_PIER_TRF0IE_MASK)

#define NETC_TMR_BASE_PIER_TTC0IE_MASK           (0x4U)
#define NETC_TMR_BASE_PIER_TTC0IE_SHIFT          (2U)
#define NETC_TMR_BASE_PIER_TTC0IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TTC0IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TTC0IE_SHIFT)) & NETC_TMR_BASE_PIER_TTC0IE_MASK)

#define NETC_TMR_BASE_PIER_TAE0IE_MASK           (0x8U)
#define NETC_TMR_BASE_PIER_TAE0IE_SHIFT          (3U)
#define NETC_TMR_BASE_PIER_TAE0IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TAE0IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TAE0IE_SHIFT)) & NETC_TMR_BASE_PIER_TAE0IE_MASK)

#define NETC_TMR_BASE_PIER_TF1IE_MASK            (0x10U)
#define NETC_TMR_BASE_PIER_TF1IE_SHIFT           (4U)
#define NETC_TMR_BASE_PIER_TF1IE_WIDTH           (1U)
#define NETC_TMR_BASE_PIER_TF1IE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TF1IE_SHIFT)) & NETC_TMR_BASE_PIER_TF1IE_MASK)

#define NETC_TMR_BASE_PIER_TRF1IE_MASK           (0x20U)
#define NETC_TMR_BASE_PIER_TRF1IE_SHIFT          (5U)
#define NETC_TMR_BASE_PIER_TRF1IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TRF1IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TRF1IE_SHIFT)) & NETC_TMR_BASE_PIER_TRF1IE_MASK)

#define NETC_TMR_BASE_PIER_TTC1IE_MASK           (0x40U)
#define NETC_TMR_BASE_PIER_TTC1IE_SHIFT          (6U)
#define NETC_TMR_BASE_PIER_TTC1IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TTC1IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TTC1IE_SHIFT)) & NETC_TMR_BASE_PIER_TTC1IE_MASK)

#define NETC_TMR_BASE_PIER_TAE1IE_MASK           (0x80U)
#define NETC_TMR_BASE_PIER_TAE1IE_SHIFT          (7U)
#define NETC_TMR_BASE_PIER_TAE1IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TAE1IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TAE1IE_SHIFT)) & NETC_TMR_BASE_PIER_TAE1IE_MASK)

#define NETC_TMR_BASE_PIER_TF2IE_MASK            (0x100U)
#define NETC_TMR_BASE_PIER_TF2IE_SHIFT           (8U)
#define NETC_TMR_BASE_PIER_TF2IE_WIDTH           (1U)
#define NETC_TMR_BASE_PIER_TF2IE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TF2IE_SHIFT)) & NETC_TMR_BASE_PIER_TF2IE_MASK)

#define NETC_TMR_BASE_PIER_TRF2IE_MASK           (0x200U)
#define NETC_TMR_BASE_PIER_TRF2IE_SHIFT          (9U)
#define NETC_TMR_BASE_PIER_TRF2IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TRF2IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TRF2IE_SHIFT)) & NETC_TMR_BASE_PIER_TRF2IE_MASK)

#define NETC_TMR_BASE_PIER_TTC2IE_MASK           (0x400U)
#define NETC_TMR_BASE_PIER_TTC2IE_SHIFT          (10U)
#define NETC_TMR_BASE_PIER_TTC2IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TTC2IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TTC2IE_SHIFT)) & NETC_TMR_BASE_PIER_TTC2IE_MASK)

#define NETC_TMR_BASE_PIER_TAE2IE_MASK           (0x800U)
#define NETC_TMR_BASE_PIER_TAE2IE_SHIFT          (11U)
#define NETC_TMR_BASE_PIER_TAE2IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TAE2IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TAE2IE_SHIFT)) & NETC_TMR_BASE_PIER_TAE2IE_MASK)

#define NETC_TMR_BASE_PIER_TF3IE_MASK            (0x1000U)
#define NETC_TMR_BASE_PIER_TF3IE_SHIFT           (12U)
#define NETC_TMR_BASE_PIER_TF3IE_WIDTH           (1U)
#define NETC_TMR_BASE_PIER_TF3IE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TF3IE_SHIFT)) & NETC_TMR_BASE_PIER_TF3IE_MASK)

#define NETC_TMR_BASE_PIER_TRF3IE_MASK           (0x2000U)
#define NETC_TMR_BASE_PIER_TRF3IE_SHIFT          (13U)
#define NETC_TMR_BASE_PIER_TRF3IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TRF3IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TRF3IE_SHIFT)) & NETC_TMR_BASE_PIER_TRF3IE_MASK)

#define NETC_TMR_BASE_PIER_TTC3IE_MASK           (0x4000U)
#define NETC_TMR_BASE_PIER_TTC3IE_SHIFT          (14U)
#define NETC_TMR_BASE_PIER_TTC3IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TTC3IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TTC3IE_SHIFT)) & NETC_TMR_BASE_PIER_TTC3IE_MASK)

#define NETC_TMR_BASE_PIER_TAE3IE_MASK           (0x8000U)
#define NETC_TMR_BASE_PIER_TAE3IE_SHIFT          (15U)
#define NETC_TMR_BASE_PIER_TAE3IE_WIDTH          (1U)
#define NETC_TMR_BASE_PIER_TAE3IE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIER_TAE3IE_SHIFT)) & NETC_TMR_BASE_PIER_TAE3IE_MASK)
/*! @} */

/*! @name PIDR - Interrupt Detect */
/*! @{ */

#define NETC_TMR_BASE_PIDR_TF0_MASK              (0x1U)
#define NETC_TMR_BASE_PIDR_TF0_SHIFT             (0U)
#define NETC_TMR_BASE_PIDR_TF0_WIDTH             (1U)
#define NETC_TMR_BASE_PIDR_TF0(x)                (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TF0_SHIFT)) & NETC_TMR_BASE_PIDR_TF0_MASK)

#define NETC_TMR_BASE_PIDR_TRF0_MASK             (0x2U)
#define NETC_TMR_BASE_PIDR_TRF0_SHIFT            (1U)
#define NETC_TMR_BASE_PIDR_TRF0_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TRF0(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TRF0_SHIFT)) & NETC_TMR_BASE_PIDR_TRF0_MASK)

#define NETC_TMR_BASE_PIDR_TTC0_MASK             (0x4U)
#define NETC_TMR_BASE_PIDR_TTC0_SHIFT            (2U)
#define NETC_TMR_BASE_PIDR_TTC0_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TTC0(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TTC0_SHIFT)) & NETC_TMR_BASE_PIDR_TTC0_MASK)

#define NETC_TMR_BASE_PIDR_TAE0_MASK             (0x8U)
#define NETC_TMR_BASE_PIDR_TAE0_SHIFT            (3U)
#define NETC_TMR_BASE_PIDR_TAE0_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TAE0(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TAE0_SHIFT)) & NETC_TMR_BASE_PIDR_TAE0_MASK)

#define NETC_TMR_BASE_PIDR_TF1_MASK              (0x10U)
#define NETC_TMR_BASE_PIDR_TF1_SHIFT             (4U)
#define NETC_TMR_BASE_PIDR_TF1_WIDTH             (1U)
#define NETC_TMR_BASE_PIDR_TF1(x)                (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TF1_SHIFT)) & NETC_TMR_BASE_PIDR_TF1_MASK)

#define NETC_TMR_BASE_PIDR_TRF1_MASK             (0x20U)
#define NETC_TMR_BASE_PIDR_TRF1_SHIFT            (5U)
#define NETC_TMR_BASE_PIDR_TRF1_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TRF1(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TRF1_SHIFT)) & NETC_TMR_BASE_PIDR_TRF1_MASK)

#define NETC_TMR_BASE_PIDR_TTC1_MASK             (0x40U)
#define NETC_TMR_BASE_PIDR_TTC1_SHIFT            (6U)
#define NETC_TMR_BASE_PIDR_TTC1_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TTC1(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TTC1_SHIFT)) & NETC_TMR_BASE_PIDR_TTC1_MASK)

#define NETC_TMR_BASE_PIDR_TAE1_MASK             (0x80U)
#define NETC_TMR_BASE_PIDR_TAE1_SHIFT            (7U)
#define NETC_TMR_BASE_PIDR_TAE1_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TAE1(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TAE1_SHIFT)) & NETC_TMR_BASE_PIDR_TAE1_MASK)

#define NETC_TMR_BASE_PIDR_TF2_MASK              (0x100U)
#define NETC_TMR_BASE_PIDR_TF2_SHIFT             (8U)
#define NETC_TMR_BASE_PIDR_TF2_WIDTH             (1U)
#define NETC_TMR_BASE_PIDR_TF2(x)                (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TF2_SHIFT)) & NETC_TMR_BASE_PIDR_TF2_MASK)

#define NETC_TMR_BASE_PIDR_TRF2_MASK             (0x200U)
#define NETC_TMR_BASE_PIDR_TRF2_SHIFT            (9U)
#define NETC_TMR_BASE_PIDR_TRF2_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TRF2(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TRF2_SHIFT)) & NETC_TMR_BASE_PIDR_TRF2_MASK)

#define NETC_TMR_BASE_PIDR_TTC2_MASK             (0x400U)
#define NETC_TMR_BASE_PIDR_TTC2_SHIFT            (10U)
#define NETC_TMR_BASE_PIDR_TTC2_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TTC2(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TTC2_SHIFT)) & NETC_TMR_BASE_PIDR_TTC2_MASK)

#define NETC_TMR_BASE_PIDR_TAE2_MASK             (0x800U)
#define NETC_TMR_BASE_PIDR_TAE2_SHIFT            (11U)
#define NETC_TMR_BASE_PIDR_TAE2_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TAE2(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TAE2_SHIFT)) & NETC_TMR_BASE_PIDR_TAE2_MASK)

#define NETC_TMR_BASE_PIDR_TF3_MASK              (0x1000U)
#define NETC_TMR_BASE_PIDR_TF3_SHIFT             (12U)
#define NETC_TMR_BASE_PIDR_TF3_WIDTH             (1U)
#define NETC_TMR_BASE_PIDR_TF3(x)                (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TF3_SHIFT)) & NETC_TMR_BASE_PIDR_TF3_MASK)

#define NETC_TMR_BASE_PIDR_TRF3_MASK             (0x2000U)
#define NETC_TMR_BASE_PIDR_TRF3_SHIFT            (13U)
#define NETC_TMR_BASE_PIDR_TRF3_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TRF3(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TRF3_SHIFT)) & NETC_TMR_BASE_PIDR_TRF3_MASK)

#define NETC_TMR_BASE_PIDR_TTC3_MASK             (0x4000U)
#define NETC_TMR_BASE_PIDR_TTC3_SHIFT            (14U)
#define NETC_TMR_BASE_PIDR_TTC3_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TTC3(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TTC3_SHIFT)) & NETC_TMR_BASE_PIDR_TTC3_MASK)

#define NETC_TMR_BASE_PIDR_TAE3_MASK             (0x8000U)
#define NETC_TMR_BASE_PIDR_TAE3_SHIFT            (15U)
#define NETC_TMR_BASE_PIDR_TAE3_WIDTH            (1U)
#define NETC_TMR_BASE_PIDR_TAE3(x)               (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PIDR_TAE3_SHIFT)) & NETC_TMR_BASE_PIDR_TAE3_MASK)
/*! @} */

/*! @name PMSIVR - MSI-X Vector */
/*! @{ */

#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN0_MASK   (0x1U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN0_SHIFT  (0U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN0_WIDTH  (1U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN0(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PMSIVR_VECTOR_CHAN0_SHIFT)) & NETC_TMR_BASE_PMSIVR_VECTOR_CHAN0_MASK)

#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN1_MASK   (0x10U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN1_SHIFT  (4U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN1_WIDTH  (1U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN1(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PMSIVR_VECTOR_CHAN1_SHIFT)) & NETC_TMR_BASE_PMSIVR_VECTOR_CHAN1_MASK)

#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN2_MASK   (0x100U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN2_SHIFT  (8U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN2_WIDTH  (1U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN2(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PMSIVR_VECTOR_CHAN2_SHIFT)) & NETC_TMR_BASE_PMSIVR_VECTOR_CHAN2_MASK)

#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN3_MASK   (0x1000U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN3_SHIFT  (12U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN3_WIDTH  (1U)
#define NETC_TMR_BASE_PMSIVR_VECTOR_CHAN3(x)     (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_PMSIVR_VECTOR_CHAN3_SHIFT)) & NETC_TMR_BASE_PMSIVR_VECTOR_CHAN3_MASK)
/*! @} */

/*! @name TMR_CAR - Timer Interface Cache Attribute 0 */
/*! @{ */

#define NETC_TMR_BASE_TMR_CAR_WRCACHE_MASK       (0xF00U)
#define NETC_TMR_BASE_TMR_CAR_WRCACHE_SHIFT      (8U)
#define NETC_TMR_BASE_TMR_CAR_WRCACHE_WIDTH      (4U)
#define NETC_TMR_BASE_TMR_CAR_WRCACHE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CAR_WRCACHE_SHIFT)) & NETC_TMR_BASE_TMR_CAR_WRCACHE_MASK)

#define NETC_TMR_BASE_TMR_CAR_WRDOMAIN_MASK      (0x3000U)
#define NETC_TMR_BASE_TMR_CAR_WRDOMAIN_SHIFT     (12U)
#define NETC_TMR_BASE_TMR_CAR_WRDOMAIN_WIDTH     (2U)
#define NETC_TMR_BASE_TMR_CAR_WRDOMAIN(x)        (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CAR_WRDOMAIN_SHIFT)) & NETC_TMR_BASE_TMR_CAR_WRDOMAIN_MASK)

#define NETC_TMR_BASE_TMR_CAR_WRSNP_MASK         (0x4000U)
#define NETC_TMR_BASE_TMR_CAR_WRSNP_SHIFT        (14U)
#define NETC_TMR_BASE_TMR_CAR_WRSNP_WIDTH        (1U)
#define NETC_TMR_BASE_TMR_CAR_WRSNP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CAR_WRSNP_SHIFT)) & NETC_TMR_BASE_TMR_CAR_WRSNP_MASK)

#define NETC_TMR_BASE_TMR_CAR_RDCACHE_MASK       (0xF000000U)
#define NETC_TMR_BASE_TMR_CAR_RDCACHE_SHIFT      (24U)
#define NETC_TMR_BASE_TMR_CAR_RDCACHE_WIDTH      (4U)
#define NETC_TMR_BASE_TMR_CAR_RDCACHE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CAR_RDCACHE_SHIFT)) & NETC_TMR_BASE_TMR_CAR_RDCACHE_MASK)

#define NETC_TMR_BASE_TMR_CAR_RDDOMAIN_MASK      (0x30000000U)
#define NETC_TMR_BASE_TMR_CAR_RDDOMAIN_SHIFT     (28U)
#define NETC_TMR_BASE_TMR_CAR_RDDOMAIN_WIDTH     (2U)
#define NETC_TMR_BASE_TMR_CAR_RDDOMAIN(x)        (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CAR_RDDOMAIN_SHIFT)) & NETC_TMR_BASE_TMR_CAR_RDDOMAIN_MASK)

#define NETC_TMR_BASE_TMR_CAR_RDSNP_MASK         (0x40000000U)
#define NETC_TMR_BASE_TMR_CAR_RDSNP_SHIFT        (30U)
#define NETC_TMR_BASE_TMR_CAR_RDSNP_WIDTH        (1U)
#define NETC_TMR_BASE_TMR_CAR_RDSNP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_TMR_BASE_TMR_CAR_RDSNP_SHIFT)) & NETC_TMR_BASE_TMR_CAR_RDSNP_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group NETC_TMR_BASE_Register_Masks */

/*!
 * @}
 */ /* end of group NETC_TMR_BASE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_NETC_TMR_BASE_H_) */
