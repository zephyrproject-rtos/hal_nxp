/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_FLEXPWM.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_FLEXPWM
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
#if !defined(S32K39_FLEXPWM_H_)  /* Check if memory map has not been already included */
#define S32K39_FLEXPWM_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- FLEXPWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXPWM_Peripheral_Access_Layer FLEXPWM Peripheral Access Layer
 * @{
 */

/** FLEXPWM - Size of Registers Arrays */
#define FLEXPWM_SM_COUNT                          4u
#define FLEXPWM_FAULT_COUNT                       1u

/** FLEXPWM - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x60 */
    __I  uint16_t SMCNT;                             /**< Submodule Counter, array offset: 0x0, array step: 0x60 */
    __IO uint16_t SMINIT;                            /**< Submodule Initial Count, array offset: 0x2, array step: 0x60 */
    __IO uint16_t SMCTRL2;                           /**< Submodule Control 2, array offset: 0x4, array step: 0x60 */
    __IO uint16_t SMCTRL;                            /**< Submodule Control, array offset: 0x6, array step: 0x60 */
    uint8_t RESERVED_0[2];
    __IO uint16_t SMVAL0;                            /**< Submodule Value 0, array offset: 0xA, array step: 0x60 */
    __IO uint16_t SMFRACVAL1;                        /**< Submodule Fractional Value 1, array offset: 0xC, array step: 0x60 */
    __IO uint16_t SMVAL1;                            /**< Submodule Value 1, array offset: 0xE, array step: 0x60 */
    __IO uint16_t SMFRACVAL2;                        /**< Submodule Fractional Value 2, array offset: 0x10, array step: 0x60 */
    __IO uint16_t SMVAL2;                            /**< Submodule Value 2, array offset: 0x12, array step: 0x60 */
    __IO uint16_t SMFRACVAL3;                        /**< Submodule Fractional Value 3, array offset: 0x14, array step: 0x60 */
    __IO uint16_t SMVAL3;                            /**< Submodule Value 3, array offset: 0x16, array step: 0x60 */
    __IO uint16_t SMFRACVAL4;                        /**< Submodule Fractional Value 4, array offset: 0x18, array step: 0x60 */
    __IO uint16_t SMVAL4;                            /**< Submodule Value 4, array offset: 0x1A, array step: 0x60 */
    __IO uint16_t SMFRACVAL5;                        /**< Submodule Fractional Value 5, array offset: 0x1C, array step: 0x60 */
    __IO uint16_t SMVAL5;                            /**< Submodule Value 5, array offset: 0x1E, array step: 0x60 */
    __IO uint16_t SMFRCTRL;                          /**< Submodule Fractional Control, array offset: 0x20, array step: 0x60 */
    __IO uint16_t SMOCTRL;                           /**< Submodule Output Control, array offset: 0x22, array step: 0x60 */
    __IO uint16_t SMSTS;                             /**< Submodule Status, array offset: 0x24, array step: 0x60 */
    __IO uint16_t SMINTEN;                           /**< Submodule Interrupt Enable, array offset: 0x26, array step: 0x60 */
    __IO uint16_t SMDMAEN;                           /**< Submodule DMA Enable, array offset: 0x28, array step: 0x60 */
    __IO uint16_t SMTCTRL;                           /**< Submodule Output Trigger Control, array offset: 0x2A, array step: 0x60 */
    __IO uint16_t SMDISMAP0;                         /**< Submodule Fault Disable Mapping, array offset: 0x2C, array step: 0x60 */
    __IO uint16_t SMDISMAP1;                         /**< Submodule Fault Disable Mapping, array offset: 0x2E, array step: 0x60 */
    __IO uint16_t SMDTCNT0;                          /**< Submodule Deadtime Count 0, array offset: 0x30, array step: 0x60 */
    __IO uint16_t SMDTCNT1;                          /**< Submodule Deadtime Count 1, array offset: 0x32, array step: 0x60 */
    __IO uint16_t SMCAPTCTRLA;                       /**< Submodule Capture Control A, array offset: 0x34, array step: 0x60 */
    __IO uint16_t SMCAPTCOMPA;                       /**< Submodule Capture Compare A, array offset: 0x36, array step: 0x60 */
    __IO uint16_t SMCAPTCTRLB;                       /**< Submodule Capture Control B, array offset: 0x38, array step: 0x60 */
    __IO uint16_t SMCAPTCOMPB;                       /**< Submodule Capture Compare B, array offset: 0x3A, array step: 0x60 */
    __IO uint16_t SMCAPTCTRLX;                       /**< Submodule Capture Control X, array offset: 0x3C, array step: 0x60 */
    __IO uint16_t SMCAPTCOMPX;                       /**< Submodule Capture Compare X, array offset: 0x3E, array step: 0x60 */
    __I  uint16_t SMCVAL0;                           /**< Submodule Capture Value 0, array offset: 0x40, array step: 0x60 */
    __I  uint16_t SMCVAL0CYC;                        /**< Submodule Capture Value 0 Cycle, array offset: 0x42, array step: 0x60 */
    __I  uint16_t SMCVAL1;                           /**< Submodule Capture Value 1, array offset: 0x44, array step: 0x60 */
    __I  uint16_t SMCVAL1CYC;                        /**< Submodule Capture Value 1 Cycle, array offset: 0x46, array step: 0x60 */
    __I  uint16_t SMCVAL2;                           /**< Submodule Capture Value 2, array offset: 0x48, array step: 0x60 */
    __I  uint16_t SMCVAL2CYC;                        /**< Submodule Capture Value 2 Cycle, array offset: 0x4A, array step: 0x60 */
    __I  uint16_t SMCVAL3;                           /**< Submodule Capture Value 3, array offset: 0x4C, array step: 0x60 */
    __I  uint16_t SMCVAL3CYC;                        /**< Submodule Capture Value 3 Cycle, array offset: 0x4E, array step: 0x60 */
    __I  uint16_t SMCVAL4;                           /**< Submodule Capture Value 4, array offset: 0x50, array step: 0x60 */
    __I  uint16_t SMCVAL4CYC;                        /**< Submodule Capture Value 4 Cycle, array offset: 0x52, array step: 0x60 */
    __I  uint16_t SMCVAL5;                           /**< Submodule Capture Value 5, array offset: 0x54, array step: 0x60 */
    __I  uint16_t SMCVAL5CYC;                        /**< Submodule Capture Value 5 Cycle, array offset: 0x56, array step: 0x60 */
    __IO uint16_t SMPHASEDLY;                        /**< Submodule Phase Delay, array offset: 0x58, array step: 0x60 */
    uint8_t RESERVED_1[6];
  } SM[FLEXPWM_SM_COUNT];
  __IO uint16_t OUTEN;                             /**< Output Enable, offset: 0x180 */
  __IO uint16_t MASK;                              /**< Mask, offset: 0x182 */
  __IO uint16_t SWCOUT;                            /**< Software Controlled Output, offset: 0x184 */
  __IO uint16_t DTSRCSEL;                          /**< PWM Source Select, offset: 0x186 */
  __IO uint16_t MCTRL;                             /**< Master Control, offset: 0x188 */
  __IO uint16_t MCTRL2;                            /**< Master Control 2, offset: 0x18A */
  struct {                                         /* offset: 0x18C, array step: 0xA */
    __IO uint16_t FCTRL;                             /**< Fault Control, array offset: 0x18C, array step: 0xA */
    __IO uint16_t FSTS;                              /**< Fault Status, array offset: 0x18E, array step: 0xA */
    __IO uint16_t FFILT;                             /**< Fault Filter, array offset: 0x190, array step: 0xA */
    __IO uint16_t FTST;                              /**< Fault Test, array offset: 0x192, array step: 0xA */
    __IO uint16_t FCTRL2;                            /**< Fault Control 2, array offset: 0x194, array step: 0xA */
  } FAULT[FLEXPWM_FAULT_COUNT];
  uint8_t RESERVED_0[18];
  __IO uint16_t DLLCTRL;                           /**< DLL Control, offset: 0x1A8 */
  uint8_t RESERVED_1[6];
  __IO uint16_t DLLSR;                             /**< DLL Status, offset: 0x1B0 */
  uint8_t RESERVED_2[6];
  __IO uint16_t SM0BIST_CTRL;                      /**< Submodule BIST Control, offset: 0x1B8 */
  __IO uint16_t SM0BIST_CTRL1;                     /**< Submodule BIST Control, offset: 0x1BA */
  __IO uint16_t SM1BIST_CTRL;                      /**< Submodule BIST Control, offset: 0x1BC */
  __IO uint16_t SM1BIST_CTRL1;                     /**< Submodule BIST Control, offset: 0x1BE */
  __IO uint16_t SM2BIST_CTRL;                      /**< Submodule BIST Control, offset: 0x1C0 */
  __IO uint16_t SM2BIST_CTRL1;                     /**< Submodule BIST Control, offset: 0x1C2 */
  __IO uint16_t SM3BIST_CTRL;                      /**< Submodule BIST Control, offset: 0x1C4 */
  __IO uint16_t SM3BIST_CTRL1;                     /**< Submodule BIST Control, offset: 0x1C6 */
  __I  uint16_t SM0BIST_STATUS;                    /**< Submodule BIST Status, offset: 0x1C8 */
  __I  uint16_t SM0BIST_STATUS1;                   /**< Submodule BIST Status, offset: 0x1CA */
  __I  uint16_t SM1BIST_STATUS;                    /**< Submodule BIST Status, offset: 0x1CC */
  __I  uint16_t SM1BIST_STATUS1;                   /**< Submodule BIST Status, offset: 0x1CE */
  __I  uint16_t SM2BIST_STATUS;                    /**< Submodule BIST Status, offset: 0x1D0 */
  __I  uint16_t SM2BIST_STATUS1;                   /**< Submodule BIST Status, offset: 0x1D2 */
  __I  uint16_t SM3BIST_STATUS;                    /**< Submodule BIST Status, offset: 0x1D4 */
  __I  uint16_t SM3BIST_STATUS1;                   /**< Submodule BIST Status, offset: 0x1D6 */
} FLEXPWM_Type, *FLEXPWM_MemMapPtr;

/** Number of instances of the FLEXPWM module. */
#define FLEXPWM_INSTANCE_COUNT                   (2u)

/* FLEXPWM - Peripheral instance base addresses */
/** Peripheral EFLEXPWM_0 base address */
#define IP_EFLEXPWM_0_BASE                       (0x406B8000u)
/** Peripheral EFLEXPWM_0 base pointer */
#define IP_EFLEXPWM_0                            ((FLEXPWM_Type *)IP_EFLEXPWM_0_BASE)
/** Peripheral EFLEXPWM_1 base address */
#define IP_EFLEXPWM_1_BASE                       (0x406BC000u)
/** Peripheral EFLEXPWM_1 base pointer */
#define IP_EFLEXPWM_1                            ((FLEXPWM_Type *)IP_EFLEXPWM_1_BASE)
/** Array initializer of FLEXPWM peripheral base addresses */
#define IP_FLEXPWM_BASE_ADDRS                    { IP_EFLEXPWM_0_BASE, IP_EFLEXPWM_1_BASE }
/** Array initializer of FLEXPWM peripheral base pointers */
#define IP_FLEXPWM_BASE_PTRS                     { IP_EFLEXPWM_0, IP_EFLEXPWM_1 }

/* ----------------------------------------------------------------------------
   -- FLEXPWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXPWM_Register_Masks FLEXPWM Register Masks
 * @{
 */

/*! @name SMCNT - Submodule Counter */
/*! @{ */

#define FLEXPWM_SMCNT_CNT_MASK                   (0xFFFFU)
#define FLEXPWM_SMCNT_CNT_SHIFT                  (0U)
#define FLEXPWM_SMCNT_CNT_WIDTH                  (16U)
#define FLEXPWM_SMCNT_CNT(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCNT_CNT_SHIFT)) & FLEXPWM_SMCNT_CNT_MASK)
/*! @} */

/*! @name SMINIT - Submodule Initial Count */
/*! @{ */

#define FLEXPWM_SMINIT_INIT_MASK                 (0xFFFFU)
#define FLEXPWM_SMINIT_INIT_SHIFT                (0U)
#define FLEXPWM_SMINIT_INIT_WIDTH                (16U)
#define FLEXPWM_SMINIT_INIT(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMINIT_INIT_SHIFT)) & FLEXPWM_SMINIT_INIT_MASK)
/*! @} */

/*! @name SMCTRL2 - Submodule Control 2 */
/*! @{ */

#define FLEXPWM_SMCTRL2_CLK_SEL_MASK             (0x3U)
#define FLEXPWM_SMCTRL2_CLK_SEL_SHIFT            (0U)
#define FLEXPWM_SMCTRL2_CLK_SEL_WIDTH            (2U)
#define FLEXPWM_SMCTRL2_CLK_SEL(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_CLK_SEL_SHIFT)) & FLEXPWM_SMCTRL2_CLK_SEL_MASK)

#define FLEXPWM_SMCTRL2_RELOAD_SEL_MASK          (0x4U)
#define FLEXPWM_SMCTRL2_RELOAD_SEL_SHIFT         (2U)
#define FLEXPWM_SMCTRL2_RELOAD_SEL_WIDTH         (1U)
#define FLEXPWM_SMCTRL2_RELOAD_SEL(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_RELOAD_SEL_SHIFT)) & FLEXPWM_SMCTRL2_RELOAD_SEL_MASK)

#define FLEXPWM_SMCTRL2_FORCE_SEL_MASK           (0x38U)
#define FLEXPWM_SMCTRL2_FORCE_SEL_SHIFT          (3U)
#define FLEXPWM_SMCTRL2_FORCE_SEL_WIDTH          (3U)
#define FLEXPWM_SMCTRL2_FORCE_SEL(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_FORCE_SEL_SHIFT)) & FLEXPWM_SMCTRL2_FORCE_SEL_MASK)

#define FLEXPWM_SMCTRL2_FORCE_MASK               (0x40U)
#define FLEXPWM_SMCTRL2_FORCE_SHIFT              (6U)
#define FLEXPWM_SMCTRL2_FORCE_WIDTH              (1U)
#define FLEXPWM_SMCTRL2_FORCE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_FORCE_SHIFT)) & FLEXPWM_SMCTRL2_FORCE_MASK)

#define FLEXPWM_SMCTRL2_FRCEN_MASK               (0x80U)
#define FLEXPWM_SMCTRL2_FRCEN_SHIFT              (7U)
#define FLEXPWM_SMCTRL2_FRCEN_WIDTH              (1U)
#define FLEXPWM_SMCTRL2_FRCEN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_FRCEN_SHIFT)) & FLEXPWM_SMCTRL2_FRCEN_MASK)

#define FLEXPWM_SMCTRL2_INIT_SEL_MASK            (0x300U)
#define FLEXPWM_SMCTRL2_INIT_SEL_SHIFT           (8U)
#define FLEXPWM_SMCTRL2_INIT_SEL_WIDTH           (2U)
#define FLEXPWM_SMCTRL2_INIT_SEL(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_INIT_SEL_SHIFT)) & FLEXPWM_SMCTRL2_INIT_SEL_MASK)

#define FLEXPWM_SMCTRL2_PWMX_INIT_MASK           (0x400U)
#define FLEXPWM_SMCTRL2_PWMX_INIT_SHIFT          (10U)
#define FLEXPWM_SMCTRL2_PWMX_INIT_WIDTH          (1U)
#define FLEXPWM_SMCTRL2_PWMX_INIT(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_PWMX_INIT_SHIFT)) & FLEXPWM_SMCTRL2_PWMX_INIT_MASK)

#define FLEXPWM_SMCTRL2_PWM45_INIT_MASK          (0x800U)
#define FLEXPWM_SMCTRL2_PWM45_INIT_SHIFT         (11U)
#define FLEXPWM_SMCTRL2_PWM45_INIT_WIDTH         (1U)
#define FLEXPWM_SMCTRL2_PWM45_INIT(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_PWM45_INIT_SHIFT)) & FLEXPWM_SMCTRL2_PWM45_INIT_MASK)

#define FLEXPWM_SMCTRL2_PWM23_INIT_MASK          (0x1000U)
#define FLEXPWM_SMCTRL2_PWM23_INIT_SHIFT         (12U)
#define FLEXPWM_SMCTRL2_PWM23_INIT_WIDTH         (1U)
#define FLEXPWM_SMCTRL2_PWM23_INIT(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_PWM23_INIT_SHIFT)) & FLEXPWM_SMCTRL2_PWM23_INIT_MASK)

#define FLEXPWM_SMCTRL2_INDEP_MASK               (0x2000U)
#define FLEXPWM_SMCTRL2_INDEP_SHIFT              (13U)
#define FLEXPWM_SMCTRL2_INDEP_WIDTH              (1U)
#define FLEXPWM_SMCTRL2_INDEP(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_INDEP_SHIFT)) & FLEXPWM_SMCTRL2_INDEP_MASK)

#define FLEXPWM_SMCTRL2_WAITEN_MASK              (0x4000U)
#define FLEXPWM_SMCTRL2_WAITEN_SHIFT             (14U)
#define FLEXPWM_SMCTRL2_WAITEN_WIDTH             (1U)
#define FLEXPWM_SMCTRL2_WAITEN(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_WAITEN_SHIFT)) & FLEXPWM_SMCTRL2_WAITEN_MASK)

#define FLEXPWM_SMCTRL2_DBGEN_MASK               (0x8000U)
#define FLEXPWM_SMCTRL2_DBGEN_SHIFT              (15U)
#define FLEXPWM_SMCTRL2_DBGEN_WIDTH              (1U)
#define FLEXPWM_SMCTRL2_DBGEN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL2_DBGEN_SHIFT)) & FLEXPWM_SMCTRL2_DBGEN_MASK)
/*! @} */

/*! @name SMCTRL - Submodule Control */
/*! @{ */

#define FLEXPWM_SMCTRL_DBLEN_MASK                (0x1U)
#define FLEXPWM_SMCTRL_DBLEN_SHIFT               (0U)
#define FLEXPWM_SMCTRL_DBLEN_WIDTH               (1U)
#define FLEXPWM_SMCTRL_DBLEN(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL_DBLEN_SHIFT)) & FLEXPWM_SMCTRL_DBLEN_MASK)

#define FLEXPWM_SMCTRL_DBLX_MASK                 (0x2U)
#define FLEXPWM_SMCTRL_DBLX_SHIFT                (1U)
#define FLEXPWM_SMCTRL_DBLX_WIDTH                (1U)
#define FLEXPWM_SMCTRL_DBLX(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL_DBLX_SHIFT)) & FLEXPWM_SMCTRL_DBLX_MASK)

#define FLEXPWM_SMCTRL_LDMOD_MASK                (0x4U)
#define FLEXPWM_SMCTRL_LDMOD_SHIFT               (2U)
#define FLEXPWM_SMCTRL_LDMOD_WIDTH               (1U)
#define FLEXPWM_SMCTRL_LDMOD(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL_LDMOD_SHIFT)) & FLEXPWM_SMCTRL_LDMOD_MASK)

#define FLEXPWM_SMCTRL_SPLIT_MASK                (0x8U)
#define FLEXPWM_SMCTRL_SPLIT_SHIFT               (3U)
#define FLEXPWM_SMCTRL_SPLIT_WIDTH               (1U)
#define FLEXPWM_SMCTRL_SPLIT(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL_SPLIT_SHIFT)) & FLEXPWM_SMCTRL_SPLIT_MASK)

#define FLEXPWM_SMCTRL_PRSC_MASK                 (0x70U)
#define FLEXPWM_SMCTRL_PRSC_SHIFT                (4U)
#define FLEXPWM_SMCTRL_PRSC_WIDTH                (3U)
#define FLEXPWM_SMCTRL_PRSC(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL_PRSC_SHIFT)) & FLEXPWM_SMCTRL_PRSC_MASK)

#define FLEXPWM_SMCTRL_COMPMODE_MASK             (0x80U)
#define FLEXPWM_SMCTRL_COMPMODE_SHIFT            (7U)
#define FLEXPWM_SMCTRL_COMPMODE_WIDTH            (1U)
#define FLEXPWM_SMCTRL_COMPMODE(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL_COMPMODE_SHIFT)) & FLEXPWM_SMCTRL_COMPMODE_MASK)

#define FLEXPWM_SMCTRL_DT_MASK                   (0x300U)
#define FLEXPWM_SMCTRL_DT_SHIFT                  (8U)
#define FLEXPWM_SMCTRL_DT_WIDTH                  (2U)
#define FLEXPWM_SMCTRL_DT(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL_DT_SHIFT)) & FLEXPWM_SMCTRL_DT_MASK)

#define FLEXPWM_SMCTRL_FULL_MASK                 (0x400U)
#define FLEXPWM_SMCTRL_FULL_SHIFT                (10U)
#define FLEXPWM_SMCTRL_FULL_WIDTH                (1U)
#define FLEXPWM_SMCTRL_FULL(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL_FULL_SHIFT)) & FLEXPWM_SMCTRL_FULL_MASK)

#define FLEXPWM_SMCTRL_HALF_MASK                 (0x800U)
#define FLEXPWM_SMCTRL_HALF_SHIFT                (11U)
#define FLEXPWM_SMCTRL_HALF_WIDTH                (1U)
#define FLEXPWM_SMCTRL_HALF(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL_HALF_SHIFT)) & FLEXPWM_SMCTRL_HALF_MASK)

#define FLEXPWM_SMCTRL_LDFQ_MASK                 (0xF000U)
#define FLEXPWM_SMCTRL_LDFQ_SHIFT                (12U)
#define FLEXPWM_SMCTRL_LDFQ_WIDTH                (4U)
#define FLEXPWM_SMCTRL_LDFQ(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCTRL_LDFQ_SHIFT)) & FLEXPWM_SMCTRL_LDFQ_MASK)
/*! @} */

/*! @name SMVAL0 - Submodule Value 0 */
/*! @{ */

#define FLEXPWM_SMVAL0_VAL0_MASK                 (0xFFFFU)
#define FLEXPWM_SMVAL0_VAL0_SHIFT                (0U)
#define FLEXPWM_SMVAL0_VAL0_WIDTH                (16U)
#define FLEXPWM_SMVAL0_VAL0(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMVAL0_VAL0_SHIFT)) & FLEXPWM_SMVAL0_VAL0_MASK)
/*! @} */

/*! @name SMFRACVAL1 - Submodule Fractional Value 1 */
/*! @{ */

#define FLEXPWM_SMFRACVAL1_FRACVAL1_MASK         (0xF800U)
#define FLEXPWM_SMFRACVAL1_FRACVAL1_SHIFT        (11U)
#define FLEXPWM_SMFRACVAL1_FRACVAL1_WIDTH        (5U)
#define FLEXPWM_SMFRACVAL1_FRACVAL1(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMFRACVAL1_FRACVAL1_SHIFT)) & FLEXPWM_SMFRACVAL1_FRACVAL1_MASK)
/*! @} */

/*! @name SMVAL1 - Submodule Value 1 */
/*! @{ */

#define FLEXPWM_SMVAL1_VAL1_MASK                 (0xFFFFU)
#define FLEXPWM_SMVAL1_VAL1_SHIFT                (0U)
#define FLEXPWM_SMVAL1_VAL1_WIDTH                (16U)
#define FLEXPWM_SMVAL1_VAL1(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMVAL1_VAL1_SHIFT)) & FLEXPWM_SMVAL1_VAL1_MASK)
/*! @} */

/*! @name SMFRACVAL2 - Submodule Fractional Value 2 */
/*! @{ */

#define FLEXPWM_SMFRACVAL2_FRACVAL2_MASK         (0xF800U)
#define FLEXPWM_SMFRACVAL2_FRACVAL2_SHIFT        (11U)
#define FLEXPWM_SMFRACVAL2_FRACVAL2_WIDTH        (5U)
#define FLEXPWM_SMFRACVAL2_FRACVAL2(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMFRACVAL2_FRACVAL2_SHIFT)) & FLEXPWM_SMFRACVAL2_FRACVAL2_MASK)
/*! @} */

/*! @name SMVAL2 - Submodule Value 2 */
/*! @{ */

#define FLEXPWM_SMVAL2_VAL2_MASK                 (0xFFFFU)
#define FLEXPWM_SMVAL2_VAL2_SHIFT                (0U)
#define FLEXPWM_SMVAL2_VAL2_WIDTH                (16U)
#define FLEXPWM_SMVAL2_VAL2(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMVAL2_VAL2_SHIFT)) & FLEXPWM_SMVAL2_VAL2_MASK)
/*! @} */

/*! @name SMFRACVAL3 - Submodule Fractional Value 3 */
/*! @{ */

#define FLEXPWM_SMFRACVAL3_FRACVAL3_MASK         (0xF800U)
#define FLEXPWM_SMFRACVAL3_FRACVAL3_SHIFT        (11U)
#define FLEXPWM_SMFRACVAL3_FRACVAL3_WIDTH        (5U)
#define FLEXPWM_SMFRACVAL3_FRACVAL3(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMFRACVAL3_FRACVAL3_SHIFT)) & FLEXPWM_SMFRACVAL3_FRACVAL3_MASK)
/*! @} */

/*! @name SMVAL3 - Submodule Value 3 */
/*! @{ */

#define FLEXPWM_SMVAL3_VAL3_MASK                 (0xFFFFU)
#define FLEXPWM_SMVAL3_VAL3_SHIFT                (0U)
#define FLEXPWM_SMVAL3_VAL3_WIDTH                (16U)
#define FLEXPWM_SMVAL3_VAL3(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMVAL3_VAL3_SHIFT)) & FLEXPWM_SMVAL3_VAL3_MASK)
/*! @} */

/*! @name SMFRACVAL4 - Submodule Fractional Value 4 */
/*! @{ */

#define FLEXPWM_SMFRACVAL4_FRACVAL4_MASK         (0xF800U)
#define FLEXPWM_SMFRACVAL4_FRACVAL4_SHIFT        (11U)
#define FLEXPWM_SMFRACVAL4_FRACVAL4_WIDTH        (5U)
#define FLEXPWM_SMFRACVAL4_FRACVAL4(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMFRACVAL4_FRACVAL4_SHIFT)) & FLEXPWM_SMFRACVAL4_FRACVAL4_MASK)
/*! @} */

/*! @name SMVAL4 - Submodule Value 4 */
/*! @{ */

#define FLEXPWM_SMVAL4_VAL4_MASK                 (0xFFFFU)
#define FLEXPWM_SMVAL4_VAL4_SHIFT                (0U)
#define FLEXPWM_SMVAL4_VAL4_WIDTH                (16U)
#define FLEXPWM_SMVAL4_VAL4(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMVAL4_VAL4_SHIFT)) & FLEXPWM_SMVAL4_VAL4_MASK)
/*! @} */

/*! @name SMFRACVAL5 - Submodule Fractional Value 5 */
/*! @{ */

#define FLEXPWM_SMFRACVAL5_FRACVAL5_MASK         (0xF800U)
#define FLEXPWM_SMFRACVAL5_FRACVAL5_SHIFT        (11U)
#define FLEXPWM_SMFRACVAL5_FRACVAL5_WIDTH        (5U)
#define FLEXPWM_SMFRACVAL5_FRACVAL5(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMFRACVAL5_FRACVAL5_SHIFT)) & FLEXPWM_SMFRACVAL5_FRACVAL5_MASK)
/*! @} */

/*! @name SMVAL5 - Submodule Value 5 */
/*! @{ */

#define FLEXPWM_SMVAL5_VAL5_MASK                 (0xFFFFU)
#define FLEXPWM_SMVAL5_VAL5_SHIFT                (0U)
#define FLEXPWM_SMVAL5_VAL5_WIDTH                (16U)
#define FLEXPWM_SMVAL5_VAL5(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMVAL5_VAL5_SHIFT)) & FLEXPWM_SMVAL5_VAL5_MASK)
/*! @} */

/*! @name SMFRCTRL - Submodule Fractional Control */
/*! @{ */

#define FLEXPWM_SMFRCTRL_FRAC1_EN_MASK           (0x2U)
#define FLEXPWM_SMFRCTRL_FRAC1_EN_SHIFT          (1U)
#define FLEXPWM_SMFRCTRL_FRAC1_EN_WIDTH          (1U)
#define FLEXPWM_SMFRCTRL_FRAC1_EN(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMFRCTRL_FRAC1_EN_SHIFT)) & FLEXPWM_SMFRCTRL_FRAC1_EN_MASK)

#define FLEXPWM_SMFRCTRL_FRAC23_EN_MASK          (0x4U)
#define FLEXPWM_SMFRCTRL_FRAC23_EN_SHIFT         (2U)
#define FLEXPWM_SMFRCTRL_FRAC23_EN_WIDTH         (1U)
#define FLEXPWM_SMFRCTRL_FRAC23_EN(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMFRCTRL_FRAC23_EN_SHIFT)) & FLEXPWM_SMFRCTRL_FRAC23_EN_MASK)

#define FLEXPWM_SMFRCTRL_FRAC45_EN_MASK          (0x10U)
#define FLEXPWM_SMFRCTRL_FRAC45_EN_SHIFT         (4U)
#define FLEXPWM_SMFRCTRL_FRAC45_EN_WIDTH         (1U)
#define FLEXPWM_SMFRCTRL_FRAC45_EN(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMFRCTRL_FRAC45_EN_SHIFT)) & FLEXPWM_SMFRCTRL_FRAC45_EN_MASK)

#define FLEXPWM_SMFRCTRL_FRAC_PU_MASK            (0x100U)
#define FLEXPWM_SMFRCTRL_FRAC_PU_SHIFT           (8U)
#define FLEXPWM_SMFRCTRL_FRAC_PU_WIDTH           (1U)
#define FLEXPWM_SMFRCTRL_FRAC_PU(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMFRCTRL_FRAC_PU_SHIFT)) & FLEXPWM_SMFRCTRL_FRAC_PU_MASK)
/*! @} */

/*! @name SMOCTRL - Submodule Output Control */
/*! @{ */

#define FLEXPWM_SMOCTRL_PWMXFS_MASK              (0x3U)
#define FLEXPWM_SMOCTRL_PWMXFS_SHIFT             (0U)
#define FLEXPWM_SMOCTRL_PWMXFS_WIDTH             (2U)
#define FLEXPWM_SMOCTRL_PWMXFS(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMOCTRL_PWMXFS_SHIFT)) & FLEXPWM_SMOCTRL_PWMXFS_MASK)

#define FLEXPWM_SMOCTRL_PWMBFS_MASK              (0xCU)
#define FLEXPWM_SMOCTRL_PWMBFS_SHIFT             (2U)
#define FLEXPWM_SMOCTRL_PWMBFS_WIDTH             (2U)
#define FLEXPWM_SMOCTRL_PWMBFS(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMOCTRL_PWMBFS_SHIFT)) & FLEXPWM_SMOCTRL_PWMBFS_MASK)

#define FLEXPWM_SMOCTRL_PWMAFS_MASK              (0x30U)
#define FLEXPWM_SMOCTRL_PWMAFS_SHIFT             (4U)
#define FLEXPWM_SMOCTRL_PWMAFS_WIDTH             (2U)
#define FLEXPWM_SMOCTRL_PWMAFS(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMOCTRL_PWMAFS_SHIFT)) & FLEXPWM_SMOCTRL_PWMAFS_MASK)

#define FLEXPWM_SMOCTRL_POLX_MASK                (0x100U)
#define FLEXPWM_SMOCTRL_POLX_SHIFT               (8U)
#define FLEXPWM_SMOCTRL_POLX_WIDTH               (1U)
#define FLEXPWM_SMOCTRL_POLX(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMOCTRL_POLX_SHIFT)) & FLEXPWM_SMOCTRL_POLX_MASK)

#define FLEXPWM_SMOCTRL_POLB_MASK                (0x200U)
#define FLEXPWM_SMOCTRL_POLB_SHIFT               (9U)
#define FLEXPWM_SMOCTRL_POLB_WIDTH               (1U)
#define FLEXPWM_SMOCTRL_POLB(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMOCTRL_POLB_SHIFT)) & FLEXPWM_SMOCTRL_POLB_MASK)

#define FLEXPWM_SMOCTRL_POLA_MASK                (0x400U)
#define FLEXPWM_SMOCTRL_POLA_SHIFT               (10U)
#define FLEXPWM_SMOCTRL_POLA_WIDTH               (1U)
#define FLEXPWM_SMOCTRL_POLA(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMOCTRL_POLA_SHIFT)) & FLEXPWM_SMOCTRL_POLA_MASK)

#define FLEXPWM_SMOCTRL_PWMX_IN_MASK             (0x2000U)
#define FLEXPWM_SMOCTRL_PWMX_IN_SHIFT            (13U)
#define FLEXPWM_SMOCTRL_PWMX_IN_WIDTH            (1U)
#define FLEXPWM_SMOCTRL_PWMX_IN(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMOCTRL_PWMX_IN_SHIFT)) & FLEXPWM_SMOCTRL_PWMX_IN_MASK)

#define FLEXPWM_SMOCTRL_PWMB_IN_MASK             (0x4000U)
#define FLEXPWM_SMOCTRL_PWMB_IN_SHIFT            (14U)
#define FLEXPWM_SMOCTRL_PWMB_IN_WIDTH            (1U)
#define FLEXPWM_SMOCTRL_PWMB_IN(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMOCTRL_PWMB_IN_SHIFT)) & FLEXPWM_SMOCTRL_PWMB_IN_MASK)

#define FLEXPWM_SMOCTRL_PWMA_IN_MASK             (0x8000U)
#define FLEXPWM_SMOCTRL_PWMA_IN_SHIFT            (15U)
#define FLEXPWM_SMOCTRL_PWMA_IN_WIDTH            (1U)
#define FLEXPWM_SMOCTRL_PWMA_IN(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMOCTRL_PWMA_IN_SHIFT)) & FLEXPWM_SMOCTRL_PWMA_IN_MASK)
/*! @} */

/*! @name SMSTS - Submodule Status */
/*! @{ */

#define FLEXPWM_SMSTS_CMPF_MASK                  (0x3FU)
#define FLEXPWM_SMSTS_CMPF_SHIFT                 (0U)
#define FLEXPWM_SMSTS_CMPF_WIDTH                 (6U)
#define FLEXPWM_SMSTS_CMPF(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMSTS_CMPF_SHIFT)) & FLEXPWM_SMSTS_CMPF_MASK)

#define FLEXPWM_SMSTS_CFX0_MASK                  (0x40U)
#define FLEXPWM_SMSTS_CFX0_SHIFT                 (6U)
#define FLEXPWM_SMSTS_CFX0_WIDTH                 (1U)
#define FLEXPWM_SMSTS_CFX0(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMSTS_CFX0_SHIFT)) & FLEXPWM_SMSTS_CFX0_MASK)

#define FLEXPWM_SMSTS_CFX1_MASK                  (0x80U)
#define FLEXPWM_SMSTS_CFX1_SHIFT                 (7U)
#define FLEXPWM_SMSTS_CFX1_WIDTH                 (1U)
#define FLEXPWM_SMSTS_CFX1(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMSTS_CFX1_SHIFT)) & FLEXPWM_SMSTS_CFX1_MASK)

#define FLEXPWM_SMSTS_CFB0_MASK                  (0x100U)
#define FLEXPWM_SMSTS_CFB0_SHIFT                 (8U)
#define FLEXPWM_SMSTS_CFB0_WIDTH                 (1U)
#define FLEXPWM_SMSTS_CFB0(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMSTS_CFB0_SHIFT)) & FLEXPWM_SMSTS_CFB0_MASK)

#define FLEXPWM_SMSTS_CFB1_MASK                  (0x200U)
#define FLEXPWM_SMSTS_CFB1_SHIFT                 (9U)
#define FLEXPWM_SMSTS_CFB1_WIDTH                 (1U)
#define FLEXPWM_SMSTS_CFB1(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMSTS_CFB1_SHIFT)) & FLEXPWM_SMSTS_CFB1_MASK)

#define FLEXPWM_SMSTS_CFA0_MASK                  (0x400U)
#define FLEXPWM_SMSTS_CFA0_SHIFT                 (10U)
#define FLEXPWM_SMSTS_CFA0_WIDTH                 (1U)
#define FLEXPWM_SMSTS_CFA0(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMSTS_CFA0_SHIFT)) & FLEXPWM_SMSTS_CFA0_MASK)

#define FLEXPWM_SMSTS_CFA1_MASK                  (0x800U)
#define FLEXPWM_SMSTS_CFA1_SHIFT                 (11U)
#define FLEXPWM_SMSTS_CFA1_WIDTH                 (1U)
#define FLEXPWM_SMSTS_CFA1(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMSTS_CFA1_SHIFT)) & FLEXPWM_SMSTS_CFA1_MASK)

#define FLEXPWM_SMSTS_RF_MASK                    (0x1000U)
#define FLEXPWM_SMSTS_RF_SHIFT                   (12U)
#define FLEXPWM_SMSTS_RF_WIDTH                   (1U)
#define FLEXPWM_SMSTS_RF(x)                      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMSTS_RF_SHIFT)) & FLEXPWM_SMSTS_RF_MASK)

#define FLEXPWM_SMSTS_REF_MASK                   (0x2000U)
#define FLEXPWM_SMSTS_REF_SHIFT                  (13U)
#define FLEXPWM_SMSTS_REF_WIDTH                  (1U)
#define FLEXPWM_SMSTS_REF(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMSTS_REF_SHIFT)) & FLEXPWM_SMSTS_REF_MASK)

#define FLEXPWM_SMSTS_RUF_MASK                   (0x4000U)
#define FLEXPWM_SMSTS_RUF_SHIFT                  (14U)
#define FLEXPWM_SMSTS_RUF_WIDTH                  (1U)
#define FLEXPWM_SMSTS_RUF(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMSTS_RUF_SHIFT)) & FLEXPWM_SMSTS_RUF_MASK)
/*! @} */

/*! @name SMINTEN - Submodule Interrupt Enable */
/*! @{ */

#define FLEXPWM_SMINTEN_CMPIE_MASK               (0x3FU)
#define FLEXPWM_SMINTEN_CMPIE_SHIFT              (0U)
#define FLEXPWM_SMINTEN_CMPIE_WIDTH              (6U)
#define FLEXPWM_SMINTEN_CMPIE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMINTEN_CMPIE_SHIFT)) & FLEXPWM_SMINTEN_CMPIE_MASK)

#define FLEXPWM_SMINTEN_CX0IE_MASK               (0x40U)
#define FLEXPWM_SMINTEN_CX0IE_SHIFT              (6U)
#define FLEXPWM_SMINTEN_CX0IE_WIDTH              (1U)
#define FLEXPWM_SMINTEN_CX0IE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMINTEN_CX0IE_SHIFT)) & FLEXPWM_SMINTEN_CX0IE_MASK)

#define FLEXPWM_SMINTEN_CX1IE_MASK               (0x80U)
#define FLEXPWM_SMINTEN_CX1IE_SHIFT              (7U)
#define FLEXPWM_SMINTEN_CX1IE_WIDTH              (1U)
#define FLEXPWM_SMINTEN_CX1IE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMINTEN_CX1IE_SHIFT)) & FLEXPWM_SMINTEN_CX1IE_MASK)

#define FLEXPWM_SMINTEN_CB0IE_MASK               (0x100U)
#define FLEXPWM_SMINTEN_CB0IE_SHIFT              (8U)
#define FLEXPWM_SMINTEN_CB0IE_WIDTH              (1U)
#define FLEXPWM_SMINTEN_CB0IE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMINTEN_CB0IE_SHIFT)) & FLEXPWM_SMINTEN_CB0IE_MASK)

#define FLEXPWM_SMINTEN_CB1IE_MASK               (0x200U)
#define FLEXPWM_SMINTEN_CB1IE_SHIFT              (9U)
#define FLEXPWM_SMINTEN_CB1IE_WIDTH              (1U)
#define FLEXPWM_SMINTEN_CB1IE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMINTEN_CB1IE_SHIFT)) & FLEXPWM_SMINTEN_CB1IE_MASK)

#define FLEXPWM_SMINTEN_CA0IE_MASK               (0x400U)
#define FLEXPWM_SMINTEN_CA0IE_SHIFT              (10U)
#define FLEXPWM_SMINTEN_CA0IE_WIDTH              (1U)
#define FLEXPWM_SMINTEN_CA0IE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMINTEN_CA0IE_SHIFT)) & FLEXPWM_SMINTEN_CA0IE_MASK)

#define FLEXPWM_SMINTEN_CA1IE_MASK               (0x800U)
#define FLEXPWM_SMINTEN_CA1IE_SHIFT              (11U)
#define FLEXPWM_SMINTEN_CA1IE_WIDTH              (1U)
#define FLEXPWM_SMINTEN_CA1IE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMINTEN_CA1IE_SHIFT)) & FLEXPWM_SMINTEN_CA1IE_MASK)

#define FLEXPWM_SMINTEN_RIE_MASK                 (0x1000U)
#define FLEXPWM_SMINTEN_RIE_SHIFT                (12U)
#define FLEXPWM_SMINTEN_RIE_WIDTH                (1U)
#define FLEXPWM_SMINTEN_RIE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMINTEN_RIE_SHIFT)) & FLEXPWM_SMINTEN_RIE_MASK)

#define FLEXPWM_SMINTEN_REIE_MASK                (0x2000U)
#define FLEXPWM_SMINTEN_REIE_SHIFT               (13U)
#define FLEXPWM_SMINTEN_REIE_WIDTH               (1U)
#define FLEXPWM_SMINTEN_REIE(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMINTEN_REIE_SHIFT)) & FLEXPWM_SMINTEN_REIE_MASK)
/*! @} */

/*! @name SMDMAEN - Submodule DMA Enable */
/*! @{ */

#define FLEXPWM_SMDMAEN_CX0DE_MASK               (0x1U)
#define FLEXPWM_SMDMAEN_CX0DE_SHIFT              (0U)
#define FLEXPWM_SMDMAEN_CX0DE_WIDTH              (1U)
#define FLEXPWM_SMDMAEN_CX0DE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDMAEN_CX0DE_SHIFT)) & FLEXPWM_SMDMAEN_CX0DE_MASK)

#define FLEXPWM_SMDMAEN_CX1DE_MASK               (0x2U)
#define FLEXPWM_SMDMAEN_CX1DE_SHIFT              (1U)
#define FLEXPWM_SMDMAEN_CX1DE_WIDTH              (1U)
#define FLEXPWM_SMDMAEN_CX1DE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDMAEN_CX1DE_SHIFT)) & FLEXPWM_SMDMAEN_CX1DE_MASK)

#define FLEXPWM_SMDMAEN_CB0DE_MASK               (0x4U)
#define FLEXPWM_SMDMAEN_CB0DE_SHIFT              (2U)
#define FLEXPWM_SMDMAEN_CB0DE_WIDTH              (1U)
#define FLEXPWM_SMDMAEN_CB0DE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDMAEN_CB0DE_SHIFT)) & FLEXPWM_SMDMAEN_CB0DE_MASK)

#define FLEXPWM_SMDMAEN_CB1DE_MASK               (0x8U)
#define FLEXPWM_SMDMAEN_CB1DE_SHIFT              (3U)
#define FLEXPWM_SMDMAEN_CB1DE_WIDTH              (1U)
#define FLEXPWM_SMDMAEN_CB1DE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDMAEN_CB1DE_SHIFT)) & FLEXPWM_SMDMAEN_CB1DE_MASK)

#define FLEXPWM_SMDMAEN_CA0DE_MASK               (0x10U)
#define FLEXPWM_SMDMAEN_CA0DE_SHIFT              (4U)
#define FLEXPWM_SMDMAEN_CA0DE_WIDTH              (1U)
#define FLEXPWM_SMDMAEN_CA0DE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDMAEN_CA0DE_SHIFT)) & FLEXPWM_SMDMAEN_CA0DE_MASK)

#define FLEXPWM_SMDMAEN_CA1DE_MASK               (0x20U)
#define FLEXPWM_SMDMAEN_CA1DE_SHIFT              (5U)
#define FLEXPWM_SMDMAEN_CA1DE_WIDTH              (1U)
#define FLEXPWM_SMDMAEN_CA1DE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDMAEN_CA1DE_SHIFT)) & FLEXPWM_SMDMAEN_CA1DE_MASK)

#define FLEXPWM_SMDMAEN_CAPTDE_MASK              (0xC0U)
#define FLEXPWM_SMDMAEN_CAPTDE_SHIFT             (6U)
#define FLEXPWM_SMDMAEN_CAPTDE_WIDTH             (2U)
#define FLEXPWM_SMDMAEN_CAPTDE(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDMAEN_CAPTDE_SHIFT)) & FLEXPWM_SMDMAEN_CAPTDE_MASK)

#define FLEXPWM_SMDMAEN_FAND_MASK                (0x100U)
#define FLEXPWM_SMDMAEN_FAND_SHIFT               (8U)
#define FLEXPWM_SMDMAEN_FAND_WIDTH               (1U)
#define FLEXPWM_SMDMAEN_FAND(x)                  (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDMAEN_FAND_SHIFT)) & FLEXPWM_SMDMAEN_FAND_MASK)

#define FLEXPWM_SMDMAEN_VALDE_MASK               (0x200U)
#define FLEXPWM_SMDMAEN_VALDE_SHIFT              (9U)
#define FLEXPWM_SMDMAEN_VALDE_WIDTH              (1U)
#define FLEXPWM_SMDMAEN_VALDE(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDMAEN_VALDE_SHIFT)) & FLEXPWM_SMDMAEN_VALDE_MASK)
/*! @} */

/*! @name SMTCTRL - Submodule Output Trigger Control */
/*! @{ */

#define FLEXPWM_SMTCTRL_OUT_TRIG_EN_MASK         (0x3FU)
#define FLEXPWM_SMTCTRL_OUT_TRIG_EN_SHIFT        (0U)
#define FLEXPWM_SMTCTRL_OUT_TRIG_EN_WIDTH        (6U)
#define FLEXPWM_SMTCTRL_OUT_TRIG_EN(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMTCTRL_OUT_TRIG_EN_SHIFT)) & FLEXPWM_SMTCTRL_OUT_TRIG_EN_MASK)

#define FLEXPWM_SMTCTRL_TRGFRQ_MASK              (0x1000U)
#define FLEXPWM_SMTCTRL_TRGFRQ_SHIFT             (12U)
#define FLEXPWM_SMTCTRL_TRGFRQ_WIDTH             (1U)
#define FLEXPWM_SMTCTRL_TRGFRQ(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMTCTRL_TRGFRQ_SHIFT)) & FLEXPWM_SMTCTRL_TRGFRQ_MASK)

#define FLEXPWM_SMTCTRL_PWBOT1_MASK              (0x4000U)
#define FLEXPWM_SMTCTRL_PWBOT1_SHIFT             (14U)
#define FLEXPWM_SMTCTRL_PWBOT1_WIDTH             (1U)
#define FLEXPWM_SMTCTRL_PWBOT1(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMTCTRL_PWBOT1_SHIFT)) & FLEXPWM_SMTCTRL_PWBOT1_MASK)

#define FLEXPWM_SMTCTRL_PWAOT0_MASK              (0x8000U)
#define FLEXPWM_SMTCTRL_PWAOT0_SHIFT             (15U)
#define FLEXPWM_SMTCTRL_PWAOT0_WIDTH             (1U)
#define FLEXPWM_SMTCTRL_PWAOT0(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMTCTRL_PWAOT0_SHIFT)) & FLEXPWM_SMTCTRL_PWAOT0_MASK)
/*! @} */

/*! @name SMDISMAP0 - Submodule Fault Disable Mapping */
/*! @{ */

#define FLEXPWM_SMDISMAP0_DIS0A_MASK             (0xFU)
#define FLEXPWM_SMDISMAP0_DIS0A_SHIFT            (0U)
#define FLEXPWM_SMDISMAP0_DIS0A_WIDTH            (4U)
#define FLEXPWM_SMDISMAP0_DIS0A(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDISMAP0_DIS0A_SHIFT)) & FLEXPWM_SMDISMAP0_DIS0A_MASK)

#define FLEXPWM_SMDISMAP0_DIS0B_MASK             (0xF0U)
#define FLEXPWM_SMDISMAP0_DIS0B_SHIFT            (4U)
#define FLEXPWM_SMDISMAP0_DIS0B_WIDTH            (4U)
#define FLEXPWM_SMDISMAP0_DIS0B(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDISMAP0_DIS0B_SHIFT)) & FLEXPWM_SMDISMAP0_DIS0B_MASK)

#define FLEXPWM_SMDISMAP0_DIS0X_MASK             (0xF00U)
#define FLEXPWM_SMDISMAP0_DIS0X_SHIFT            (8U)
#define FLEXPWM_SMDISMAP0_DIS0X_WIDTH            (4U)
#define FLEXPWM_SMDISMAP0_DIS0X(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDISMAP0_DIS0X_SHIFT)) & FLEXPWM_SMDISMAP0_DIS0X_MASK)
/*! @} */

/*! @name SMDISMAP1 - Submodule Fault Disable Mapping */
/*! @{ */

#define FLEXPWM_SMDISMAP1_DIS1A_MASK             (0xFU)
#define FLEXPWM_SMDISMAP1_DIS1A_SHIFT            (0U)
#define FLEXPWM_SMDISMAP1_DIS1A_WIDTH            (4U)
#define FLEXPWM_SMDISMAP1_DIS1A(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDISMAP1_DIS1A_SHIFT)) & FLEXPWM_SMDISMAP1_DIS1A_MASK)

#define FLEXPWM_SMDISMAP1_DIS1B_MASK             (0xF0U)
#define FLEXPWM_SMDISMAP1_DIS1B_SHIFT            (4U)
#define FLEXPWM_SMDISMAP1_DIS1B_WIDTH            (4U)
#define FLEXPWM_SMDISMAP1_DIS1B(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDISMAP1_DIS1B_SHIFT)) & FLEXPWM_SMDISMAP1_DIS1B_MASK)

#define FLEXPWM_SMDISMAP1_DIS1X_MASK             (0xF00U)
#define FLEXPWM_SMDISMAP1_DIS1X_SHIFT            (8U)
#define FLEXPWM_SMDISMAP1_DIS1X_WIDTH            (4U)
#define FLEXPWM_SMDISMAP1_DIS1X(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDISMAP1_DIS1X_SHIFT)) & FLEXPWM_SMDISMAP1_DIS1X_MASK)
/*! @} */

/*! @name SMDTCNT0 - Submodule Deadtime Count 0 */
/*! @{ */

#define FLEXPWM_SMDTCNT0_DTCNT0_MASK             (0xFFFFU)
#define FLEXPWM_SMDTCNT0_DTCNT0_SHIFT            (0U)
#define FLEXPWM_SMDTCNT0_DTCNT0_WIDTH            (16U)
#define FLEXPWM_SMDTCNT0_DTCNT0(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDTCNT0_DTCNT0_SHIFT)) & FLEXPWM_SMDTCNT0_DTCNT0_MASK)
/*! @} */

/*! @name SMDTCNT1 - Submodule Deadtime Count 1 */
/*! @{ */

#define FLEXPWM_SMDTCNT1_DTCNT1_MASK             (0xFFFFU)
#define FLEXPWM_SMDTCNT1_DTCNT1_SHIFT            (0U)
#define FLEXPWM_SMDTCNT1_DTCNT1_WIDTH            (16U)
#define FLEXPWM_SMDTCNT1_DTCNT1(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMDTCNT1_DTCNT1_SHIFT)) & FLEXPWM_SMDTCNT1_DTCNT1_MASK)
/*! @} */

/*! @name SMCAPTCTRLA - Submodule Capture Control A */
/*! @{ */

#define FLEXPWM_SMCAPTCTRLA_ARMA_MASK            (0x1U)
#define FLEXPWM_SMCAPTCTRLA_ARMA_SHIFT           (0U)
#define FLEXPWM_SMCAPTCTRLA_ARMA_WIDTH           (1U)
#define FLEXPWM_SMCAPTCTRLA_ARMA(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLA_ARMA_SHIFT)) & FLEXPWM_SMCAPTCTRLA_ARMA_MASK)

#define FLEXPWM_SMCAPTCTRLA_ONESHOTA_MASK        (0x2U)
#define FLEXPWM_SMCAPTCTRLA_ONESHOTA_SHIFT       (1U)
#define FLEXPWM_SMCAPTCTRLA_ONESHOTA_WIDTH       (1U)
#define FLEXPWM_SMCAPTCTRLA_ONESHOTA(x)          (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLA_ONESHOTA_SHIFT)) & FLEXPWM_SMCAPTCTRLA_ONESHOTA_MASK)

#define FLEXPWM_SMCAPTCTRLA_EDGA0_MASK           (0xCU)
#define FLEXPWM_SMCAPTCTRLA_EDGA0_SHIFT          (2U)
#define FLEXPWM_SMCAPTCTRLA_EDGA0_WIDTH          (2U)
#define FLEXPWM_SMCAPTCTRLA_EDGA0(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLA_EDGA0_SHIFT)) & FLEXPWM_SMCAPTCTRLA_EDGA0_MASK)

#define FLEXPWM_SMCAPTCTRLA_EDGA1_MASK           (0x30U)
#define FLEXPWM_SMCAPTCTRLA_EDGA1_SHIFT          (4U)
#define FLEXPWM_SMCAPTCTRLA_EDGA1_WIDTH          (2U)
#define FLEXPWM_SMCAPTCTRLA_EDGA1(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLA_EDGA1_SHIFT)) & FLEXPWM_SMCAPTCTRLA_EDGA1_MASK)

#define FLEXPWM_SMCAPTCTRLA_INP_SELA_MASK        (0x40U)
#define FLEXPWM_SMCAPTCTRLA_INP_SELA_SHIFT       (6U)
#define FLEXPWM_SMCAPTCTRLA_INP_SELA_WIDTH       (1U)
#define FLEXPWM_SMCAPTCTRLA_INP_SELA(x)          (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLA_INP_SELA_SHIFT)) & FLEXPWM_SMCAPTCTRLA_INP_SELA_MASK)

#define FLEXPWM_SMCAPTCTRLA_EDGCNTA_EN_MASK      (0x80U)
#define FLEXPWM_SMCAPTCTRLA_EDGCNTA_EN_SHIFT     (7U)
#define FLEXPWM_SMCAPTCTRLA_EDGCNTA_EN_WIDTH     (1U)
#define FLEXPWM_SMCAPTCTRLA_EDGCNTA_EN(x)        (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLA_EDGCNTA_EN_SHIFT)) & FLEXPWM_SMCAPTCTRLA_EDGCNTA_EN_MASK)

#define FLEXPWM_SMCAPTCTRLA_CFAWM_MASK           (0x300U)
#define FLEXPWM_SMCAPTCTRLA_CFAWM_SHIFT          (8U)
#define FLEXPWM_SMCAPTCTRLA_CFAWM_WIDTH          (2U)
#define FLEXPWM_SMCAPTCTRLA_CFAWM(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLA_CFAWM_SHIFT)) & FLEXPWM_SMCAPTCTRLA_CFAWM_MASK)

#define FLEXPWM_SMCAPTCTRLA_CA0CNT_MASK          (0x1C00U)
#define FLEXPWM_SMCAPTCTRLA_CA0CNT_SHIFT         (10U)
#define FLEXPWM_SMCAPTCTRLA_CA0CNT_WIDTH         (3U)
#define FLEXPWM_SMCAPTCTRLA_CA0CNT(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLA_CA0CNT_SHIFT)) & FLEXPWM_SMCAPTCTRLA_CA0CNT_MASK)

#define FLEXPWM_SMCAPTCTRLA_CA1CNT_MASK          (0xE000U)
#define FLEXPWM_SMCAPTCTRLA_CA1CNT_SHIFT         (13U)
#define FLEXPWM_SMCAPTCTRLA_CA1CNT_WIDTH         (3U)
#define FLEXPWM_SMCAPTCTRLA_CA1CNT(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLA_CA1CNT_SHIFT)) & FLEXPWM_SMCAPTCTRLA_CA1CNT_MASK)
/*! @} */

/*! @name SMCAPTCOMPA - Submodule Capture Compare A */
/*! @{ */

#define FLEXPWM_SMCAPTCOMPA_EDGCMPA_MASK         (0xFFU)
#define FLEXPWM_SMCAPTCOMPA_EDGCMPA_SHIFT        (0U)
#define FLEXPWM_SMCAPTCOMPA_EDGCMPA_WIDTH        (8U)
#define FLEXPWM_SMCAPTCOMPA_EDGCMPA(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCOMPA_EDGCMPA_SHIFT)) & FLEXPWM_SMCAPTCOMPA_EDGCMPA_MASK)

#define FLEXPWM_SMCAPTCOMPA_EDGCNTA_MASK         (0xFF00U)
#define FLEXPWM_SMCAPTCOMPA_EDGCNTA_SHIFT        (8U)
#define FLEXPWM_SMCAPTCOMPA_EDGCNTA_WIDTH        (8U)
#define FLEXPWM_SMCAPTCOMPA_EDGCNTA(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCOMPA_EDGCNTA_SHIFT)) & FLEXPWM_SMCAPTCOMPA_EDGCNTA_MASK)
/*! @} */

/*! @name SMCAPTCTRLB - Submodule Capture Control B */
/*! @{ */

#define FLEXPWM_SMCAPTCTRLB_ARMB_MASK            (0x1U)
#define FLEXPWM_SMCAPTCTRLB_ARMB_SHIFT           (0U)
#define FLEXPWM_SMCAPTCTRLB_ARMB_WIDTH           (1U)
#define FLEXPWM_SMCAPTCTRLB_ARMB(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLB_ARMB_SHIFT)) & FLEXPWM_SMCAPTCTRLB_ARMB_MASK)

#define FLEXPWM_SMCAPTCTRLB_ONESHOTB_MASK        (0x2U)
#define FLEXPWM_SMCAPTCTRLB_ONESHOTB_SHIFT       (1U)
#define FLEXPWM_SMCAPTCTRLB_ONESHOTB_WIDTH       (1U)
#define FLEXPWM_SMCAPTCTRLB_ONESHOTB(x)          (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLB_ONESHOTB_SHIFT)) & FLEXPWM_SMCAPTCTRLB_ONESHOTB_MASK)

#define FLEXPWM_SMCAPTCTRLB_EDGB0_MASK           (0xCU)
#define FLEXPWM_SMCAPTCTRLB_EDGB0_SHIFT          (2U)
#define FLEXPWM_SMCAPTCTRLB_EDGB0_WIDTH          (2U)
#define FLEXPWM_SMCAPTCTRLB_EDGB0(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLB_EDGB0_SHIFT)) & FLEXPWM_SMCAPTCTRLB_EDGB0_MASK)

#define FLEXPWM_SMCAPTCTRLB_EDGB1_MASK           (0x30U)
#define FLEXPWM_SMCAPTCTRLB_EDGB1_SHIFT          (4U)
#define FLEXPWM_SMCAPTCTRLB_EDGB1_WIDTH          (2U)
#define FLEXPWM_SMCAPTCTRLB_EDGB1(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLB_EDGB1_SHIFT)) & FLEXPWM_SMCAPTCTRLB_EDGB1_MASK)

#define FLEXPWM_SMCAPTCTRLB_INP_SELB_MASK        (0x40U)
#define FLEXPWM_SMCAPTCTRLB_INP_SELB_SHIFT       (6U)
#define FLEXPWM_SMCAPTCTRLB_INP_SELB_WIDTH       (1U)
#define FLEXPWM_SMCAPTCTRLB_INP_SELB(x)          (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLB_INP_SELB_SHIFT)) & FLEXPWM_SMCAPTCTRLB_INP_SELB_MASK)

#define FLEXPWM_SMCAPTCTRLB_EDGCNTB_EN_MASK      (0x80U)
#define FLEXPWM_SMCAPTCTRLB_EDGCNTB_EN_SHIFT     (7U)
#define FLEXPWM_SMCAPTCTRLB_EDGCNTB_EN_WIDTH     (1U)
#define FLEXPWM_SMCAPTCTRLB_EDGCNTB_EN(x)        (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLB_EDGCNTB_EN_SHIFT)) & FLEXPWM_SMCAPTCTRLB_EDGCNTB_EN_MASK)

#define FLEXPWM_SMCAPTCTRLB_CFBWM_MASK           (0x300U)
#define FLEXPWM_SMCAPTCTRLB_CFBWM_SHIFT          (8U)
#define FLEXPWM_SMCAPTCTRLB_CFBWM_WIDTH          (2U)
#define FLEXPWM_SMCAPTCTRLB_CFBWM(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLB_CFBWM_SHIFT)) & FLEXPWM_SMCAPTCTRLB_CFBWM_MASK)

#define FLEXPWM_SMCAPTCTRLB_CB0CNT_MASK          (0x1C00U)
#define FLEXPWM_SMCAPTCTRLB_CB0CNT_SHIFT         (10U)
#define FLEXPWM_SMCAPTCTRLB_CB0CNT_WIDTH         (3U)
#define FLEXPWM_SMCAPTCTRLB_CB0CNT(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLB_CB0CNT_SHIFT)) & FLEXPWM_SMCAPTCTRLB_CB0CNT_MASK)

#define FLEXPWM_SMCAPTCTRLB_CB1CNT_MASK          (0xE000U)
#define FLEXPWM_SMCAPTCTRLB_CB1CNT_SHIFT         (13U)
#define FLEXPWM_SMCAPTCTRLB_CB1CNT_WIDTH         (3U)
#define FLEXPWM_SMCAPTCTRLB_CB1CNT(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLB_CB1CNT_SHIFT)) & FLEXPWM_SMCAPTCTRLB_CB1CNT_MASK)
/*! @} */

/*! @name SMCAPTCOMPB - Submodule Capture Compare B */
/*! @{ */

#define FLEXPWM_SMCAPTCOMPB_EDGCMPB_MASK         (0xFFU)
#define FLEXPWM_SMCAPTCOMPB_EDGCMPB_SHIFT        (0U)
#define FLEXPWM_SMCAPTCOMPB_EDGCMPB_WIDTH        (8U)
#define FLEXPWM_SMCAPTCOMPB_EDGCMPB(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCOMPB_EDGCMPB_SHIFT)) & FLEXPWM_SMCAPTCOMPB_EDGCMPB_MASK)

#define FLEXPWM_SMCAPTCOMPB_EDGCNTB_MASK         (0xFF00U)
#define FLEXPWM_SMCAPTCOMPB_EDGCNTB_SHIFT        (8U)
#define FLEXPWM_SMCAPTCOMPB_EDGCNTB_WIDTH        (8U)
#define FLEXPWM_SMCAPTCOMPB_EDGCNTB(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCOMPB_EDGCNTB_SHIFT)) & FLEXPWM_SMCAPTCOMPB_EDGCNTB_MASK)
/*! @} */

/*! @name SMCAPTCTRLX - Submodule Capture Control X */
/*! @{ */

#define FLEXPWM_SMCAPTCTRLX_ARMX_MASK            (0x1U)
#define FLEXPWM_SMCAPTCTRLX_ARMX_SHIFT           (0U)
#define FLEXPWM_SMCAPTCTRLX_ARMX_WIDTH           (1U)
#define FLEXPWM_SMCAPTCTRLX_ARMX(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLX_ARMX_SHIFT)) & FLEXPWM_SMCAPTCTRLX_ARMX_MASK)

#define FLEXPWM_SMCAPTCTRLX_ONESHOTX_MASK        (0x2U)
#define FLEXPWM_SMCAPTCTRLX_ONESHOTX_SHIFT       (1U)
#define FLEXPWM_SMCAPTCTRLX_ONESHOTX_WIDTH       (1U)
#define FLEXPWM_SMCAPTCTRLX_ONESHOTX(x)          (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLX_ONESHOTX_SHIFT)) & FLEXPWM_SMCAPTCTRLX_ONESHOTX_MASK)

#define FLEXPWM_SMCAPTCTRLX_EDGX0_MASK           (0xCU)
#define FLEXPWM_SMCAPTCTRLX_EDGX0_SHIFT          (2U)
#define FLEXPWM_SMCAPTCTRLX_EDGX0_WIDTH          (2U)
#define FLEXPWM_SMCAPTCTRLX_EDGX0(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLX_EDGX0_SHIFT)) & FLEXPWM_SMCAPTCTRLX_EDGX0_MASK)

#define FLEXPWM_SMCAPTCTRLX_EDGX1_MASK           (0x30U)
#define FLEXPWM_SMCAPTCTRLX_EDGX1_SHIFT          (4U)
#define FLEXPWM_SMCAPTCTRLX_EDGX1_WIDTH          (2U)
#define FLEXPWM_SMCAPTCTRLX_EDGX1(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLX_EDGX1_SHIFT)) & FLEXPWM_SMCAPTCTRLX_EDGX1_MASK)

#define FLEXPWM_SMCAPTCTRLX_INP_SELX_MASK        (0x40U)
#define FLEXPWM_SMCAPTCTRLX_INP_SELX_SHIFT       (6U)
#define FLEXPWM_SMCAPTCTRLX_INP_SELX_WIDTH       (1U)
#define FLEXPWM_SMCAPTCTRLX_INP_SELX(x)          (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLX_INP_SELX_SHIFT)) & FLEXPWM_SMCAPTCTRLX_INP_SELX_MASK)

#define FLEXPWM_SMCAPTCTRLX_EDGCNTX_EN_MASK      (0x80U)
#define FLEXPWM_SMCAPTCTRLX_EDGCNTX_EN_SHIFT     (7U)
#define FLEXPWM_SMCAPTCTRLX_EDGCNTX_EN_WIDTH     (1U)
#define FLEXPWM_SMCAPTCTRLX_EDGCNTX_EN(x)        (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLX_EDGCNTX_EN_SHIFT)) & FLEXPWM_SMCAPTCTRLX_EDGCNTX_EN_MASK)

#define FLEXPWM_SMCAPTCTRLX_CFXWM_MASK           (0x300U)
#define FLEXPWM_SMCAPTCTRLX_CFXWM_SHIFT          (8U)
#define FLEXPWM_SMCAPTCTRLX_CFXWM_WIDTH          (2U)
#define FLEXPWM_SMCAPTCTRLX_CFXWM(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLX_CFXWM_SHIFT)) & FLEXPWM_SMCAPTCTRLX_CFXWM_MASK)

#define FLEXPWM_SMCAPTCTRLX_CX0CNT_MASK          (0x1C00U)
#define FLEXPWM_SMCAPTCTRLX_CX0CNT_SHIFT         (10U)
#define FLEXPWM_SMCAPTCTRLX_CX0CNT_WIDTH         (3U)
#define FLEXPWM_SMCAPTCTRLX_CX0CNT(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLX_CX0CNT_SHIFT)) & FLEXPWM_SMCAPTCTRLX_CX0CNT_MASK)

#define FLEXPWM_SMCAPTCTRLX_CX1CNT_MASK          (0xE000U)
#define FLEXPWM_SMCAPTCTRLX_CX1CNT_SHIFT         (13U)
#define FLEXPWM_SMCAPTCTRLX_CX1CNT_WIDTH         (3U)
#define FLEXPWM_SMCAPTCTRLX_CX1CNT(x)            (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCTRLX_CX1CNT_SHIFT)) & FLEXPWM_SMCAPTCTRLX_CX1CNT_MASK)
/*! @} */

/*! @name SMCAPTCOMPX - Submodule Capture Compare X */
/*! @{ */

#define FLEXPWM_SMCAPTCOMPX_EDGCMPX_MASK         (0xFFU)
#define FLEXPWM_SMCAPTCOMPX_EDGCMPX_SHIFT        (0U)
#define FLEXPWM_SMCAPTCOMPX_EDGCMPX_WIDTH        (8U)
#define FLEXPWM_SMCAPTCOMPX_EDGCMPX(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCOMPX_EDGCMPX_SHIFT)) & FLEXPWM_SMCAPTCOMPX_EDGCMPX_MASK)

#define FLEXPWM_SMCAPTCOMPX_EDGCNTX_MASK         (0xFF00U)
#define FLEXPWM_SMCAPTCOMPX_EDGCNTX_SHIFT        (8U)
#define FLEXPWM_SMCAPTCOMPX_EDGCNTX_WIDTH        (8U)
#define FLEXPWM_SMCAPTCOMPX_EDGCNTX(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCAPTCOMPX_EDGCNTX_SHIFT)) & FLEXPWM_SMCAPTCOMPX_EDGCNTX_MASK)
/*! @} */

/*! @name SMCVAL0 - Submodule Capture Value 0 */
/*! @{ */

#define FLEXPWM_SMCVAL0_CAPTVAL0_MASK            (0xFFFFU)
#define FLEXPWM_SMCVAL0_CAPTVAL0_SHIFT           (0U)
#define FLEXPWM_SMCVAL0_CAPTVAL0_WIDTH           (16U)
#define FLEXPWM_SMCVAL0_CAPTVAL0(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL0_CAPTVAL0_SHIFT)) & FLEXPWM_SMCVAL0_CAPTVAL0_MASK)
/*! @} */

/*! @name SMCVAL0CYC - Submodule Capture Value 0 Cycle */
/*! @{ */

#define FLEXPWM_SMCVAL0CYC_CVAL0CYC_MASK         (0xFU)
#define FLEXPWM_SMCVAL0CYC_CVAL0CYC_SHIFT        (0U)
#define FLEXPWM_SMCVAL0CYC_CVAL0CYC_WIDTH        (4U)
#define FLEXPWM_SMCVAL0CYC_CVAL0CYC(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL0CYC_CVAL0CYC_SHIFT)) & FLEXPWM_SMCVAL0CYC_CVAL0CYC_MASK)
/*! @} */

/*! @name SMCVAL1 - Submodule Capture Value 1 */
/*! @{ */

#define FLEXPWM_SMCVAL1_CAPTVAL1_MASK            (0xFFFFU)
#define FLEXPWM_SMCVAL1_CAPTVAL1_SHIFT           (0U)
#define FLEXPWM_SMCVAL1_CAPTVAL1_WIDTH           (16U)
#define FLEXPWM_SMCVAL1_CAPTVAL1(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL1_CAPTVAL1_SHIFT)) & FLEXPWM_SMCVAL1_CAPTVAL1_MASK)
/*! @} */

/*! @name SMCVAL1CYC - Submodule Capture Value 1 Cycle */
/*! @{ */

#define FLEXPWM_SMCVAL1CYC_CVAL1CYC_MASK         (0xFU)
#define FLEXPWM_SMCVAL1CYC_CVAL1CYC_SHIFT        (0U)
#define FLEXPWM_SMCVAL1CYC_CVAL1CYC_WIDTH        (4U)
#define FLEXPWM_SMCVAL1CYC_CVAL1CYC(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL1CYC_CVAL1CYC_SHIFT)) & FLEXPWM_SMCVAL1CYC_CVAL1CYC_MASK)
/*! @} */

/*! @name SMCVAL2 - Submodule Capture Value 2 */
/*! @{ */

#define FLEXPWM_SMCVAL2_CAPTVAL2_MASK            (0xFFFFU)
#define FLEXPWM_SMCVAL2_CAPTVAL2_SHIFT           (0U)
#define FLEXPWM_SMCVAL2_CAPTVAL2_WIDTH           (16U)
#define FLEXPWM_SMCVAL2_CAPTVAL2(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL2_CAPTVAL2_SHIFT)) & FLEXPWM_SMCVAL2_CAPTVAL2_MASK)
/*! @} */

/*! @name SMCVAL2CYC - Submodule Capture Value 2 Cycle */
/*! @{ */

#define FLEXPWM_SMCVAL2CYC_CVAL2CYC_MASK         (0xFU)
#define FLEXPWM_SMCVAL2CYC_CVAL2CYC_SHIFT        (0U)
#define FLEXPWM_SMCVAL2CYC_CVAL2CYC_WIDTH        (4U)
#define FLEXPWM_SMCVAL2CYC_CVAL2CYC(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL2CYC_CVAL2CYC_SHIFT)) & FLEXPWM_SMCVAL2CYC_CVAL2CYC_MASK)
/*! @} */

/*! @name SMCVAL3 - Submodule Capture Value 3 */
/*! @{ */

#define FLEXPWM_SMCVAL3_CAPTVAL3_MASK            (0xFFFFU)
#define FLEXPWM_SMCVAL3_CAPTVAL3_SHIFT           (0U)
#define FLEXPWM_SMCVAL3_CAPTVAL3_WIDTH           (16U)
#define FLEXPWM_SMCVAL3_CAPTVAL3(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL3_CAPTVAL3_SHIFT)) & FLEXPWM_SMCVAL3_CAPTVAL3_MASK)
/*! @} */

/*! @name SMCVAL3CYC - Submodule Capture Value 3 Cycle */
/*! @{ */

#define FLEXPWM_SMCVAL3CYC_CVAL3CYC_MASK         (0xFU)
#define FLEXPWM_SMCVAL3CYC_CVAL3CYC_SHIFT        (0U)
#define FLEXPWM_SMCVAL3CYC_CVAL3CYC_WIDTH        (4U)
#define FLEXPWM_SMCVAL3CYC_CVAL3CYC(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL3CYC_CVAL3CYC_SHIFT)) & FLEXPWM_SMCVAL3CYC_CVAL3CYC_MASK)
/*! @} */

/*! @name SMCVAL4 - Submodule Capture Value 4 */
/*! @{ */

#define FLEXPWM_SMCVAL4_CAPTVAL4_MASK            (0xFFFFU)
#define FLEXPWM_SMCVAL4_CAPTVAL4_SHIFT           (0U)
#define FLEXPWM_SMCVAL4_CAPTVAL4_WIDTH           (16U)
#define FLEXPWM_SMCVAL4_CAPTVAL4(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL4_CAPTVAL4_SHIFT)) & FLEXPWM_SMCVAL4_CAPTVAL4_MASK)
/*! @} */

/*! @name SMCVAL4CYC - Submodule Capture Value 4 Cycle */
/*! @{ */

#define FLEXPWM_SMCVAL4CYC_CVAL4CYC_MASK         (0xFU)
#define FLEXPWM_SMCVAL4CYC_CVAL4CYC_SHIFT        (0U)
#define FLEXPWM_SMCVAL4CYC_CVAL4CYC_WIDTH        (4U)
#define FLEXPWM_SMCVAL4CYC_CVAL4CYC(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL4CYC_CVAL4CYC_SHIFT)) & FLEXPWM_SMCVAL4CYC_CVAL4CYC_MASK)
/*! @} */

/*! @name SMCVAL5 - Submodule Capture Value 5 */
/*! @{ */

#define FLEXPWM_SMCVAL5_CAPTVAL5_MASK            (0xFFFFU)
#define FLEXPWM_SMCVAL5_CAPTVAL5_SHIFT           (0U)
#define FLEXPWM_SMCVAL5_CAPTVAL5_WIDTH           (16U)
#define FLEXPWM_SMCVAL5_CAPTVAL5(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL5_CAPTVAL5_SHIFT)) & FLEXPWM_SMCVAL5_CAPTVAL5_MASK)
/*! @} */

/*! @name SMCVAL5CYC - Submodule Capture Value 5 Cycle */
/*! @{ */

#define FLEXPWM_SMCVAL5CYC_CVAL5CYC_MASK         (0xFU)
#define FLEXPWM_SMCVAL5CYC_CVAL5CYC_SHIFT        (0U)
#define FLEXPWM_SMCVAL5CYC_CVAL5CYC_WIDTH        (4U)
#define FLEXPWM_SMCVAL5CYC_CVAL5CYC(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMCVAL5CYC_CVAL5CYC_SHIFT)) & FLEXPWM_SMCVAL5CYC_CVAL5CYC_MASK)
/*! @} */

/*! @name SMPHASEDLY - Submodule Phase Delay */
/*! @{ */

#define FLEXPWM_SMPHASEDLY_PHASEDLY_MASK         (0xFFFFU)
#define FLEXPWM_SMPHASEDLY_PHASEDLY_SHIFT        (0U)
#define FLEXPWM_SMPHASEDLY_PHASEDLY_WIDTH        (16U)
#define FLEXPWM_SMPHASEDLY_PHASEDLY(x)           (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SMPHASEDLY_PHASEDLY_SHIFT)) & FLEXPWM_SMPHASEDLY_PHASEDLY_MASK)
/*! @} */

/*! @name OUTEN - Output Enable */
/*! @{ */

#define FLEXPWM_OUTEN_PWMX_EN_MASK               (0xFU)
#define FLEXPWM_OUTEN_PWMX_EN_SHIFT              (0U)
#define FLEXPWM_OUTEN_PWMX_EN_WIDTH              (4U)
#define FLEXPWM_OUTEN_PWMX_EN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OUTEN_PWMX_EN_SHIFT)) & FLEXPWM_OUTEN_PWMX_EN_MASK)

#define FLEXPWM_OUTEN_PWMB_EN_MASK               (0xF0U)
#define FLEXPWM_OUTEN_PWMB_EN_SHIFT              (4U)
#define FLEXPWM_OUTEN_PWMB_EN_WIDTH              (4U)
#define FLEXPWM_OUTEN_PWMB_EN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OUTEN_PWMB_EN_SHIFT)) & FLEXPWM_OUTEN_PWMB_EN_MASK)

#define FLEXPWM_OUTEN_PWMA_EN_MASK               (0xF00U)
#define FLEXPWM_OUTEN_PWMA_EN_SHIFT              (8U)
#define FLEXPWM_OUTEN_PWMA_EN_WIDTH              (4U)
#define FLEXPWM_OUTEN_PWMA_EN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_OUTEN_PWMA_EN_SHIFT)) & FLEXPWM_OUTEN_PWMA_EN_MASK)
/*! @} */

/*! @name MASK - Mask */
/*! @{ */

#define FLEXPWM_MASK_MASKX_MASK                  (0xFU)
#define FLEXPWM_MASK_MASKX_SHIFT                 (0U)
#define FLEXPWM_MASK_MASKX_WIDTH                 (4U)
#define FLEXPWM_MASK_MASKX(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MASK_MASKX_SHIFT)) & FLEXPWM_MASK_MASKX_MASK)

#define FLEXPWM_MASK_MASKB_MASK                  (0xF0U)
#define FLEXPWM_MASK_MASKB_SHIFT                 (4U)
#define FLEXPWM_MASK_MASKB_WIDTH                 (4U)
#define FLEXPWM_MASK_MASKB(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MASK_MASKB_SHIFT)) & FLEXPWM_MASK_MASKB_MASK)

#define FLEXPWM_MASK_MASKA_MASK                  (0xF00U)
#define FLEXPWM_MASK_MASKA_SHIFT                 (8U)
#define FLEXPWM_MASK_MASKA_WIDTH                 (4U)
#define FLEXPWM_MASK_MASKA(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MASK_MASKA_SHIFT)) & FLEXPWM_MASK_MASKA_MASK)

#define FLEXPWM_MASK_UPDATE_MASK_MASK            (0xF000U)
#define FLEXPWM_MASK_UPDATE_MASK_SHIFT           (12U)
#define FLEXPWM_MASK_UPDATE_MASK_WIDTH           (4U)
#define FLEXPWM_MASK_UPDATE_MASK(x)              (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MASK_UPDATE_MASK_SHIFT)) & FLEXPWM_MASK_UPDATE_MASK_MASK)
/*! @} */

/*! @name SWCOUT - Software Controlled Output */
/*! @{ */

#define FLEXPWM_SWCOUT_SM0OUT45_MASK             (0x1U)
#define FLEXPWM_SWCOUT_SM0OUT45_SHIFT            (0U)
#define FLEXPWM_SWCOUT_SM0OUT45_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM0OUT45(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM0OUT45_SHIFT)) & FLEXPWM_SWCOUT_SM0OUT45_MASK)

#define FLEXPWM_SWCOUT_SM0OUT23_MASK             (0x2U)
#define FLEXPWM_SWCOUT_SM0OUT23_SHIFT            (1U)
#define FLEXPWM_SWCOUT_SM0OUT23_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM0OUT23(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM0OUT23_SHIFT)) & FLEXPWM_SWCOUT_SM0OUT23_MASK)

#define FLEXPWM_SWCOUT_SM1OUT45_MASK             (0x4U)
#define FLEXPWM_SWCOUT_SM1OUT45_SHIFT            (2U)
#define FLEXPWM_SWCOUT_SM1OUT45_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM1OUT45(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM1OUT45_SHIFT)) & FLEXPWM_SWCOUT_SM1OUT45_MASK)

#define FLEXPWM_SWCOUT_SM1OUT23_MASK             (0x8U)
#define FLEXPWM_SWCOUT_SM1OUT23_SHIFT            (3U)
#define FLEXPWM_SWCOUT_SM1OUT23_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM1OUT23(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM1OUT23_SHIFT)) & FLEXPWM_SWCOUT_SM1OUT23_MASK)

#define FLEXPWM_SWCOUT_SM2OUT45_MASK             (0x10U)
#define FLEXPWM_SWCOUT_SM2OUT45_SHIFT            (4U)
#define FLEXPWM_SWCOUT_SM2OUT45_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM2OUT45(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM2OUT45_SHIFT)) & FLEXPWM_SWCOUT_SM2OUT45_MASK)

#define FLEXPWM_SWCOUT_SM2OUT23_MASK             (0x20U)
#define FLEXPWM_SWCOUT_SM2OUT23_SHIFT            (5U)
#define FLEXPWM_SWCOUT_SM2OUT23_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM2OUT23(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM2OUT23_SHIFT)) & FLEXPWM_SWCOUT_SM2OUT23_MASK)

#define FLEXPWM_SWCOUT_SM3OUT45_MASK             (0x40U)
#define FLEXPWM_SWCOUT_SM3OUT45_SHIFT            (6U)
#define FLEXPWM_SWCOUT_SM3OUT45_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM3OUT45(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM3OUT45_SHIFT)) & FLEXPWM_SWCOUT_SM3OUT45_MASK)

#define FLEXPWM_SWCOUT_SM3OUT23_MASK             (0x80U)
#define FLEXPWM_SWCOUT_SM3OUT23_SHIFT            (7U)
#define FLEXPWM_SWCOUT_SM3OUT23_WIDTH            (1U)
#define FLEXPWM_SWCOUT_SM3OUT23(x)               (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SWCOUT_SM3OUT23_SHIFT)) & FLEXPWM_SWCOUT_SM3OUT23_MASK)
/*! @} */

/*! @name DTSRCSEL - PWM Source Select */
/*! @{ */

#define FLEXPWM_DTSRCSEL_SM0SEL45_MASK           (0x3U)
#define FLEXPWM_DTSRCSEL_SM0SEL45_SHIFT          (0U)
#define FLEXPWM_DTSRCSEL_SM0SEL45_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM0SEL45(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM0SEL45_SHIFT)) & FLEXPWM_DTSRCSEL_SM0SEL45_MASK)

#define FLEXPWM_DTSRCSEL_SM0SEL23_MASK           (0xCU)
#define FLEXPWM_DTSRCSEL_SM0SEL23_SHIFT          (2U)
#define FLEXPWM_DTSRCSEL_SM0SEL23_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM0SEL23(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM0SEL23_SHIFT)) & FLEXPWM_DTSRCSEL_SM0SEL23_MASK)

#define FLEXPWM_DTSRCSEL_SM1SEL45_MASK           (0x30U)
#define FLEXPWM_DTSRCSEL_SM1SEL45_SHIFT          (4U)
#define FLEXPWM_DTSRCSEL_SM1SEL45_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM1SEL45(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM1SEL45_SHIFT)) & FLEXPWM_DTSRCSEL_SM1SEL45_MASK)

#define FLEXPWM_DTSRCSEL_SM1SEL23_MASK           (0xC0U)
#define FLEXPWM_DTSRCSEL_SM1SEL23_SHIFT          (6U)
#define FLEXPWM_DTSRCSEL_SM1SEL23_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM1SEL23(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM1SEL23_SHIFT)) & FLEXPWM_DTSRCSEL_SM1SEL23_MASK)

#define FLEXPWM_DTSRCSEL_SM2SEL45_MASK           (0x300U)
#define FLEXPWM_DTSRCSEL_SM2SEL45_SHIFT          (8U)
#define FLEXPWM_DTSRCSEL_SM2SEL45_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM2SEL45(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM2SEL45_SHIFT)) & FLEXPWM_DTSRCSEL_SM2SEL45_MASK)

#define FLEXPWM_DTSRCSEL_SM2SEL23_MASK           (0xC00U)
#define FLEXPWM_DTSRCSEL_SM2SEL23_SHIFT          (10U)
#define FLEXPWM_DTSRCSEL_SM2SEL23_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM2SEL23(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM2SEL23_SHIFT)) & FLEXPWM_DTSRCSEL_SM2SEL23_MASK)

#define FLEXPWM_DTSRCSEL_SM3SEL45_MASK           (0x3000U)
#define FLEXPWM_DTSRCSEL_SM3SEL45_SHIFT          (12U)
#define FLEXPWM_DTSRCSEL_SM3SEL45_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM3SEL45(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM3SEL45_SHIFT)) & FLEXPWM_DTSRCSEL_SM3SEL45_MASK)

#define FLEXPWM_DTSRCSEL_SM3SEL23_MASK           (0xC000U)
#define FLEXPWM_DTSRCSEL_SM3SEL23_SHIFT          (14U)
#define FLEXPWM_DTSRCSEL_SM3SEL23_WIDTH          (2U)
#define FLEXPWM_DTSRCSEL_SM3SEL23(x)             (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DTSRCSEL_SM3SEL23_SHIFT)) & FLEXPWM_DTSRCSEL_SM3SEL23_MASK)
/*! @} */

/*! @name MCTRL - Master Control */
/*! @{ */

#define FLEXPWM_MCTRL_LDOK_MASK                  (0xFU)
#define FLEXPWM_MCTRL_LDOK_SHIFT                 (0U)
#define FLEXPWM_MCTRL_LDOK_WIDTH                 (4U)
#define FLEXPWM_MCTRL_LDOK(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MCTRL_LDOK_SHIFT)) & FLEXPWM_MCTRL_LDOK_MASK)

#define FLEXPWM_MCTRL_CLDOK_MASK                 (0xF0U)
#define FLEXPWM_MCTRL_CLDOK_SHIFT                (4U)
#define FLEXPWM_MCTRL_CLDOK_WIDTH                (4U)
#define FLEXPWM_MCTRL_CLDOK(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MCTRL_CLDOK_SHIFT)) & FLEXPWM_MCTRL_CLDOK_MASK)

#define FLEXPWM_MCTRL_RUN_MASK                   (0xF00U)
#define FLEXPWM_MCTRL_RUN_SHIFT                  (8U)
#define FLEXPWM_MCTRL_RUN_WIDTH                  (4U)
#define FLEXPWM_MCTRL_RUN(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MCTRL_RUN_SHIFT)) & FLEXPWM_MCTRL_RUN_MASK)

#define FLEXPWM_MCTRL_IPOL_MASK                  (0xF000U)
#define FLEXPWM_MCTRL_IPOL_SHIFT                 (12U)
#define FLEXPWM_MCTRL_IPOL_WIDTH                 (4U)
#define FLEXPWM_MCTRL_IPOL(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MCTRL_IPOL_SHIFT)) & FLEXPWM_MCTRL_IPOL_MASK)
/*! @} */

/*! @name MCTRL2 - Master Control 2 */
/*! @{ */

#define FLEXPWM_MCTRL2_MONPLL_MASK               (0x3U)
#define FLEXPWM_MCTRL2_MONPLL_SHIFT              (0U)
#define FLEXPWM_MCTRL2_MONPLL_WIDTH              (2U)
#define FLEXPWM_MCTRL2_MONPLL(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_MCTRL2_MONPLL_SHIFT)) & FLEXPWM_MCTRL2_MONPLL_MASK)
/*! @} */

/*! @name FCTRL - Fault Control */
/*! @{ */

#define FLEXPWM_FCTRL_FIE_MASK                   (0xFU)
#define FLEXPWM_FCTRL_FIE_SHIFT                  (0U)
#define FLEXPWM_FCTRL_FIE_WIDTH                  (4U)
#define FLEXPWM_FCTRL_FIE(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FCTRL_FIE_SHIFT)) & FLEXPWM_FCTRL_FIE_MASK)

#define FLEXPWM_FCTRL_FSAFE_MASK                 (0xF0U)
#define FLEXPWM_FCTRL_FSAFE_SHIFT                (4U)
#define FLEXPWM_FCTRL_FSAFE_WIDTH                (4U)
#define FLEXPWM_FCTRL_FSAFE(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FCTRL_FSAFE_SHIFT)) & FLEXPWM_FCTRL_FSAFE_MASK)

#define FLEXPWM_FCTRL_FAUTO_MASK                 (0xF00U)
#define FLEXPWM_FCTRL_FAUTO_SHIFT                (8U)
#define FLEXPWM_FCTRL_FAUTO_WIDTH                (4U)
#define FLEXPWM_FCTRL_FAUTO(x)                   (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FCTRL_FAUTO_SHIFT)) & FLEXPWM_FCTRL_FAUTO_MASK)

#define FLEXPWM_FCTRL_FLVL_MASK                  (0xF000U)
#define FLEXPWM_FCTRL_FLVL_SHIFT                 (12U)
#define FLEXPWM_FCTRL_FLVL_WIDTH                 (4U)
#define FLEXPWM_FCTRL_FLVL(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FCTRL_FLVL_SHIFT)) & FLEXPWM_FCTRL_FLVL_MASK)
/*! @} */

/*! @name FSTS - Fault Status */
/*! @{ */

#define FLEXPWM_FSTS_FFLAG_MASK                  (0xFU)
#define FLEXPWM_FSTS_FFLAG_SHIFT                 (0U)
#define FLEXPWM_FSTS_FFLAG_WIDTH                 (4U)
#define FLEXPWM_FSTS_FFLAG(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FSTS_FFLAG_SHIFT)) & FLEXPWM_FSTS_FFLAG_MASK)

#define FLEXPWM_FSTS_FFULL_MASK                  (0xF0U)
#define FLEXPWM_FSTS_FFULL_SHIFT                 (4U)
#define FLEXPWM_FSTS_FFULL_WIDTH                 (4U)
#define FLEXPWM_FSTS_FFULL(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FSTS_FFULL_SHIFT)) & FLEXPWM_FSTS_FFULL_MASK)

#define FLEXPWM_FSTS_FFPIN_MASK                  (0xF00U)
#define FLEXPWM_FSTS_FFPIN_SHIFT                 (8U)
#define FLEXPWM_FSTS_FFPIN_WIDTH                 (4U)
#define FLEXPWM_FSTS_FFPIN(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FSTS_FFPIN_SHIFT)) & FLEXPWM_FSTS_FFPIN_MASK)

#define FLEXPWM_FSTS_FHALF_MASK                  (0xF000U)
#define FLEXPWM_FSTS_FHALF_SHIFT                 (12U)
#define FLEXPWM_FSTS_FHALF_WIDTH                 (4U)
#define FLEXPWM_FSTS_FHALF(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FSTS_FHALF_SHIFT)) & FLEXPWM_FSTS_FHALF_MASK)
/*! @} */

/*! @name FFILT - Fault Filter */
/*! @{ */

#define FLEXPWM_FFILT_FILT_PER_MASK              (0xFFU)
#define FLEXPWM_FFILT_FILT_PER_SHIFT             (0U)
#define FLEXPWM_FFILT_FILT_PER_WIDTH             (8U)
#define FLEXPWM_FFILT_FILT_PER(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FFILT_FILT_PER_SHIFT)) & FLEXPWM_FFILT_FILT_PER_MASK)

#define FLEXPWM_FFILT_FILT_CNT_MASK              (0x700U)
#define FLEXPWM_FFILT_FILT_CNT_SHIFT             (8U)
#define FLEXPWM_FFILT_FILT_CNT_WIDTH             (3U)
#define FLEXPWM_FFILT_FILT_CNT(x)                (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FFILT_FILT_CNT_SHIFT)) & FLEXPWM_FFILT_FILT_CNT_MASK)

#define FLEXPWM_FFILT_GSTR_MASK                  (0x8000U)
#define FLEXPWM_FFILT_GSTR_SHIFT                 (15U)
#define FLEXPWM_FFILT_GSTR_WIDTH                 (1U)
#define FLEXPWM_FFILT_GSTR(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FFILT_GSTR_SHIFT)) & FLEXPWM_FFILT_GSTR_MASK)
/*! @} */

/*! @name FTST - Fault Test */
/*! @{ */

#define FLEXPWM_FTST_FTEST_MASK                  (0x1U)
#define FLEXPWM_FTST_FTEST_SHIFT                 (0U)
#define FLEXPWM_FTST_FTEST_WIDTH                 (1U)
#define FLEXPWM_FTST_FTEST(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FTST_FTEST_SHIFT)) & FLEXPWM_FTST_FTEST_MASK)
/*! @} */

/*! @name FCTRL2 - Fault Control 2 */
/*! @{ */

#define FLEXPWM_FCTRL2_NOCOMB_MASK               (0xFU)
#define FLEXPWM_FCTRL2_NOCOMB_SHIFT              (0U)
#define FLEXPWM_FCTRL2_NOCOMB_WIDTH              (4U)
#define FLEXPWM_FCTRL2_NOCOMB(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_FCTRL2_NOCOMB_SHIFT)) & FLEXPWM_FCTRL2_NOCOMB_MASK)
/*! @} */

/*! @name DLLCTRL - DLL Control */
/*! @{ */

#define FLEXPWM_DLLCTRL_DLLEN_MASK               (0x1U)
#define FLEXPWM_DLLCTRL_DLLEN_SHIFT              (0U)
#define FLEXPWM_DLLCTRL_DLLEN_WIDTH              (1U)
#define FLEXPWM_DLLCTRL_DLLEN(x)                 (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DLLCTRL_DLLEN_SHIFT)) & FLEXPWM_DLLCTRL_DLLEN_MASK)
/*! @} */

/*! @name DLLSR - DLL Status */
/*! @{ */

#define FLEXPWM_DLLSR_LOCK_MASK                  (0x1U)
#define FLEXPWM_DLLSR_LOCK_SHIFT                 (0U)
#define FLEXPWM_DLLSR_LOCK_WIDTH                 (1U)
#define FLEXPWM_DLLSR_LOCK(x)                    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DLLSR_LOCK_SHIFT)) & FLEXPWM_DLLSR_LOCK_MASK)

#define FLEXPWM_DLLSR_LOL_MASK                   (0x2U)
#define FLEXPWM_DLLSR_LOL_SHIFT                  (1U)
#define FLEXPWM_DLLSR_LOL_WIDTH                  (1U)
#define FLEXPWM_DLLSR_LOL(x)                     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_DLLSR_LOL_SHIFT)) & FLEXPWM_DLLSR_LOL_MASK)
/*! @} */

/*! @name SM0BIST_CTRL - Submodule BIST Control */
/*! @{ */

#define FLEXPWM_SM0BIST_CTRL_BIST_ENABLE_MASK    (0x1U)
#define FLEXPWM_SM0BIST_CTRL_BIST_ENABLE_SHIFT   (0U)
#define FLEXPWM_SM0BIST_CTRL_BIST_ENABLE_WIDTH   (1U)
#define FLEXPWM_SM0BIST_CTRL_BIST_ENABLE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_CTRL_BIST_ENABLE_SHIFT)) & FLEXPWM_SM0BIST_CTRL_BIST_ENABLE_MASK)

#define FLEXPWM_SM0BIST_CTRL_CLK_INITIAL_MASK    (0x3EU)
#define FLEXPWM_SM0BIST_CTRL_CLK_INITIAL_SHIFT   (1U)
#define FLEXPWM_SM0BIST_CTRL_CLK_INITIAL_WIDTH   (5U)
#define FLEXPWM_SM0BIST_CTRL_CLK_INITIAL(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_CTRL_CLK_INITIAL_SHIFT)) & FLEXPWM_SM0BIST_CTRL_CLK_INITIAL_MASK)

#define FLEXPWM_SM0BIST_CTRL_TOGGLE_MODE_MASK    (0x40U)
#define FLEXPWM_SM0BIST_CTRL_TOGGLE_MODE_SHIFT   (6U)
#define FLEXPWM_SM0BIST_CTRL_TOGGLE_MODE_WIDTH   (1U)
#define FLEXPWM_SM0BIST_CTRL_TOGGLE_MODE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_CTRL_TOGGLE_MODE_SHIFT)) & FLEXPWM_SM0BIST_CTRL_TOGGLE_MODE_MASK)

#define FLEXPWM_SM0BIST_CTRL_MANUAL_TOGGLE_MASK  (0x80U)
#define FLEXPWM_SM0BIST_CTRL_MANUAL_TOGGLE_SHIFT (7U)
#define FLEXPWM_SM0BIST_CTRL_MANUAL_TOGGLE_WIDTH (1U)
#define FLEXPWM_SM0BIST_CTRL_MANUAL_TOGGLE(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_CTRL_MANUAL_TOGGLE_SHIFT)) & FLEXPWM_SM0BIST_CTRL_MANUAL_TOGGLE_MASK)

#define FLEXPWM_SM0BIST_CTRL_CLK_FINAL_MASK      (0x1F00U)
#define FLEXPWM_SM0BIST_CTRL_CLK_FINAL_SHIFT     (8U)
#define FLEXPWM_SM0BIST_CTRL_CLK_FINAL_WIDTH     (5U)
#define FLEXPWM_SM0BIST_CTRL_CLK_FINAL(x)        (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_CTRL_CLK_FINAL_SHIFT)) & FLEXPWM_SM0BIST_CTRL_CLK_FINAL_MASK)

#define FLEXPWM_SM0BIST_CTRL_COUNTER_THRESHOLD_MASK (0xE000U)
#define FLEXPWM_SM0BIST_CTRL_COUNTER_THRESHOLD_SHIFT (13U)
#define FLEXPWM_SM0BIST_CTRL_COUNTER_THRESHOLD_WIDTH (3U)
#define FLEXPWM_SM0BIST_CTRL_COUNTER_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_CTRL_COUNTER_THRESHOLD_SHIFT)) & FLEXPWM_SM0BIST_CTRL_COUNTER_THRESHOLD_MASK)
/*! @} */

/*! @name SM0BIST_CTRL1 - Submodule BIST Control */
/*! @{ */

#define FLEXPWM_SM0BIST_CTRL1_DATA_INITIAL_MASK  (0x1FU)
#define FLEXPWM_SM0BIST_CTRL1_DATA_INITIAL_SHIFT (0U)
#define FLEXPWM_SM0BIST_CTRL1_DATA_INITIAL_WIDTH (5U)
#define FLEXPWM_SM0BIST_CTRL1_DATA_INITIAL(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_CTRL1_DATA_INITIAL_SHIFT)) & FLEXPWM_SM0BIST_CTRL1_DATA_INITIAL_MASK)

#define FLEXPWM_SM0BIST_CTRL1_DATA_FINAL_MASK    (0x1F00U)
#define FLEXPWM_SM0BIST_CTRL1_DATA_FINAL_SHIFT   (8U)
#define FLEXPWM_SM0BIST_CTRL1_DATA_FINAL_WIDTH   (5U)
#define FLEXPWM_SM0BIST_CTRL1_DATA_FINAL(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_CTRL1_DATA_FINAL_SHIFT)) & FLEXPWM_SM0BIST_CTRL1_DATA_FINAL_MASK)
/*! @} */

/*! @name SM1BIST_CTRL - Submodule BIST Control */
/*! @{ */

#define FLEXPWM_SM1BIST_CTRL_BIST_ENABLE_MASK    (0x1U)
#define FLEXPWM_SM1BIST_CTRL_BIST_ENABLE_SHIFT   (0U)
#define FLEXPWM_SM1BIST_CTRL_BIST_ENABLE_WIDTH   (1U)
#define FLEXPWM_SM1BIST_CTRL_BIST_ENABLE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_CTRL_BIST_ENABLE_SHIFT)) & FLEXPWM_SM1BIST_CTRL_BIST_ENABLE_MASK)

#define FLEXPWM_SM1BIST_CTRL_CLK_INITIAL_MASK    (0x3EU)
#define FLEXPWM_SM1BIST_CTRL_CLK_INITIAL_SHIFT   (1U)
#define FLEXPWM_SM1BIST_CTRL_CLK_INITIAL_WIDTH   (5U)
#define FLEXPWM_SM1BIST_CTRL_CLK_INITIAL(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_CTRL_CLK_INITIAL_SHIFT)) & FLEXPWM_SM1BIST_CTRL_CLK_INITIAL_MASK)

#define FLEXPWM_SM1BIST_CTRL_TOGGLE_MODE_MASK    (0x40U)
#define FLEXPWM_SM1BIST_CTRL_TOGGLE_MODE_SHIFT   (6U)
#define FLEXPWM_SM1BIST_CTRL_TOGGLE_MODE_WIDTH   (1U)
#define FLEXPWM_SM1BIST_CTRL_TOGGLE_MODE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_CTRL_TOGGLE_MODE_SHIFT)) & FLEXPWM_SM1BIST_CTRL_TOGGLE_MODE_MASK)

#define FLEXPWM_SM1BIST_CTRL_MANUAL_TOGGLE_MASK  (0x80U)
#define FLEXPWM_SM1BIST_CTRL_MANUAL_TOGGLE_SHIFT (7U)
#define FLEXPWM_SM1BIST_CTRL_MANUAL_TOGGLE_WIDTH (1U)
#define FLEXPWM_SM1BIST_CTRL_MANUAL_TOGGLE(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_CTRL_MANUAL_TOGGLE_SHIFT)) & FLEXPWM_SM1BIST_CTRL_MANUAL_TOGGLE_MASK)

#define FLEXPWM_SM1BIST_CTRL_CLK_FINAL_MASK      (0x1F00U)
#define FLEXPWM_SM1BIST_CTRL_CLK_FINAL_SHIFT     (8U)
#define FLEXPWM_SM1BIST_CTRL_CLK_FINAL_WIDTH     (5U)
#define FLEXPWM_SM1BIST_CTRL_CLK_FINAL(x)        (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_CTRL_CLK_FINAL_SHIFT)) & FLEXPWM_SM1BIST_CTRL_CLK_FINAL_MASK)

#define FLEXPWM_SM1BIST_CTRL_COUNTER_THRESHOLD_MASK (0xE000U)
#define FLEXPWM_SM1BIST_CTRL_COUNTER_THRESHOLD_SHIFT (13U)
#define FLEXPWM_SM1BIST_CTRL_COUNTER_THRESHOLD_WIDTH (3U)
#define FLEXPWM_SM1BIST_CTRL_COUNTER_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_CTRL_COUNTER_THRESHOLD_SHIFT)) & FLEXPWM_SM1BIST_CTRL_COUNTER_THRESHOLD_MASK)
/*! @} */

/*! @name SM1BIST_CTRL1 - Submodule BIST Control */
/*! @{ */

#define FLEXPWM_SM1BIST_CTRL1_DATA_INITIAL_MASK  (0x1FU)
#define FLEXPWM_SM1BIST_CTRL1_DATA_INITIAL_SHIFT (0U)
#define FLEXPWM_SM1BIST_CTRL1_DATA_INITIAL_WIDTH (5U)
#define FLEXPWM_SM1BIST_CTRL1_DATA_INITIAL(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_CTRL1_DATA_INITIAL_SHIFT)) & FLEXPWM_SM1BIST_CTRL1_DATA_INITIAL_MASK)

#define FLEXPWM_SM1BIST_CTRL1_DATA_FINAL_MASK    (0x1F00U)
#define FLEXPWM_SM1BIST_CTRL1_DATA_FINAL_SHIFT   (8U)
#define FLEXPWM_SM1BIST_CTRL1_DATA_FINAL_WIDTH   (5U)
#define FLEXPWM_SM1BIST_CTRL1_DATA_FINAL(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_CTRL1_DATA_FINAL_SHIFT)) & FLEXPWM_SM1BIST_CTRL1_DATA_FINAL_MASK)
/*! @} */

/*! @name SM2BIST_CTRL - Submodule BIST Control */
/*! @{ */

#define FLEXPWM_SM2BIST_CTRL_BIST_ENABLE_MASK    (0x1U)
#define FLEXPWM_SM2BIST_CTRL_BIST_ENABLE_SHIFT   (0U)
#define FLEXPWM_SM2BIST_CTRL_BIST_ENABLE_WIDTH   (1U)
#define FLEXPWM_SM2BIST_CTRL_BIST_ENABLE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_CTRL_BIST_ENABLE_SHIFT)) & FLEXPWM_SM2BIST_CTRL_BIST_ENABLE_MASK)

#define FLEXPWM_SM2BIST_CTRL_CLK_INITIAL_MASK    (0x3EU)
#define FLEXPWM_SM2BIST_CTRL_CLK_INITIAL_SHIFT   (1U)
#define FLEXPWM_SM2BIST_CTRL_CLK_INITIAL_WIDTH   (5U)
#define FLEXPWM_SM2BIST_CTRL_CLK_INITIAL(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_CTRL_CLK_INITIAL_SHIFT)) & FLEXPWM_SM2BIST_CTRL_CLK_INITIAL_MASK)

#define FLEXPWM_SM2BIST_CTRL_TOGGLE_MODE_MASK    (0x40U)
#define FLEXPWM_SM2BIST_CTRL_TOGGLE_MODE_SHIFT   (6U)
#define FLEXPWM_SM2BIST_CTRL_TOGGLE_MODE_WIDTH   (1U)
#define FLEXPWM_SM2BIST_CTRL_TOGGLE_MODE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_CTRL_TOGGLE_MODE_SHIFT)) & FLEXPWM_SM2BIST_CTRL_TOGGLE_MODE_MASK)

#define FLEXPWM_SM2BIST_CTRL_MANUAL_TOGGLE_MASK  (0x80U)
#define FLEXPWM_SM2BIST_CTRL_MANUAL_TOGGLE_SHIFT (7U)
#define FLEXPWM_SM2BIST_CTRL_MANUAL_TOGGLE_WIDTH (1U)
#define FLEXPWM_SM2BIST_CTRL_MANUAL_TOGGLE(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_CTRL_MANUAL_TOGGLE_SHIFT)) & FLEXPWM_SM2BIST_CTRL_MANUAL_TOGGLE_MASK)

#define FLEXPWM_SM2BIST_CTRL_CLK_FINAL_MASK      (0x1F00U)
#define FLEXPWM_SM2BIST_CTRL_CLK_FINAL_SHIFT     (8U)
#define FLEXPWM_SM2BIST_CTRL_CLK_FINAL_WIDTH     (5U)
#define FLEXPWM_SM2BIST_CTRL_CLK_FINAL(x)        (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_CTRL_CLK_FINAL_SHIFT)) & FLEXPWM_SM2BIST_CTRL_CLK_FINAL_MASK)

#define FLEXPWM_SM2BIST_CTRL_COUNTER_THRESHOLD_MASK (0xE000U)
#define FLEXPWM_SM2BIST_CTRL_COUNTER_THRESHOLD_SHIFT (13U)
#define FLEXPWM_SM2BIST_CTRL_COUNTER_THRESHOLD_WIDTH (3U)
#define FLEXPWM_SM2BIST_CTRL_COUNTER_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_CTRL_COUNTER_THRESHOLD_SHIFT)) & FLEXPWM_SM2BIST_CTRL_COUNTER_THRESHOLD_MASK)
/*! @} */

/*! @name SM2BIST_CTRL1 - Submodule BIST Control */
/*! @{ */

#define FLEXPWM_SM2BIST_CTRL1_DATA_INITIAL_MASK  (0x1FU)
#define FLEXPWM_SM2BIST_CTRL1_DATA_INITIAL_SHIFT (0U)
#define FLEXPWM_SM2BIST_CTRL1_DATA_INITIAL_WIDTH (5U)
#define FLEXPWM_SM2BIST_CTRL1_DATA_INITIAL(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_CTRL1_DATA_INITIAL_SHIFT)) & FLEXPWM_SM2BIST_CTRL1_DATA_INITIAL_MASK)

#define FLEXPWM_SM2BIST_CTRL1_DATA_FINAL_MASK    (0x1F00U)
#define FLEXPWM_SM2BIST_CTRL1_DATA_FINAL_SHIFT   (8U)
#define FLEXPWM_SM2BIST_CTRL1_DATA_FINAL_WIDTH   (5U)
#define FLEXPWM_SM2BIST_CTRL1_DATA_FINAL(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_CTRL1_DATA_FINAL_SHIFT)) & FLEXPWM_SM2BIST_CTRL1_DATA_FINAL_MASK)
/*! @} */

/*! @name SM3BIST_CTRL - Submodule BIST Control */
/*! @{ */

#define FLEXPWM_SM3BIST_CTRL_BIST_ENABLE_MASK    (0x1U)
#define FLEXPWM_SM3BIST_CTRL_BIST_ENABLE_SHIFT   (0U)
#define FLEXPWM_SM3BIST_CTRL_BIST_ENABLE_WIDTH   (1U)
#define FLEXPWM_SM3BIST_CTRL_BIST_ENABLE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_CTRL_BIST_ENABLE_SHIFT)) & FLEXPWM_SM3BIST_CTRL_BIST_ENABLE_MASK)

#define FLEXPWM_SM3BIST_CTRL_CLK_INITIAL_MASK    (0x3EU)
#define FLEXPWM_SM3BIST_CTRL_CLK_INITIAL_SHIFT   (1U)
#define FLEXPWM_SM3BIST_CTRL_CLK_INITIAL_WIDTH   (5U)
#define FLEXPWM_SM3BIST_CTRL_CLK_INITIAL(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_CTRL_CLK_INITIAL_SHIFT)) & FLEXPWM_SM3BIST_CTRL_CLK_INITIAL_MASK)

#define FLEXPWM_SM3BIST_CTRL_TOGGLE_MODE_MASK    (0x40U)
#define FLEXPWM_SM3BIST_CTRL_TOGGLE_MODE_SHIFT   (6U)
#define FLEXPWM_SM3BIST_CTRL_TOGGLE_MODE_WIDTH   (1U)
#define FLEXPWM_SM3BIST_CTRL_TOGGLE_MODE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_CTRL_TOGGLE_MODE_SHIFT)) & FLEXPWM_SM3BIST_CTRL_TOGGLE_MODE_MASK)

#define FLEXPWM_SM3BIST_CTRL_MANUAL_TOGGLE_MASK  (0x80U)
#define FLEXPWM_SM3BIST_CTRL_MANUAL_TOGGLE_SHIFT (7U)
#define FLEXPWM_SM3BIST_CTRL_MANUAL_TOGGLE_WIDTH (1U)
#define FLEXPWM_SM3BIST_CTRL_MANUAL_TOGGLE(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_CTRL_MANUAL_TOGGLE_SHIFT)) & FLEXPWM_SM3BIST_CTRL_MANUAL_TOGGLE_MASK)

#define FLEXPWM_SM3BIST_CTRL_CLK_FINAL_MASK      (0x1F00U)
#define FLEXPWM_SM3BIST_CTRL_CLK_FINAL_SHIFT     (8U)
#define FLEXPWM_SM3BIST_CTRL_CLK_FINAL_WIDTH     (5U)
#define FLEXPWM_SM3BIST_CTRL_CLK_FINAL(x)        (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_CTRL_CLK_FINAL_SHIFT)) & FLEXPWM_SM3BIST_CTRL_CLK_FINAL_MASK)

#define FLEXPWM_SM3BIST_CTRL_COUNTER_THRESHOLD_MASK (0xE000U)
#define FLEXPWM_SM3BIST_CTRL_COUNTER_THRESHOLD_SHIFT (13U)
#define FLEXPWM_SM3BIST_CTRL_COUNTER_THRESHOLD_WIDTH (3U)
#define FLEXPWM_SM3BIST_CTRL_COUNTER_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_CTRL_COUNTER_THRESHOLD_SHIFT)) & FLEXPWM_SM3BIST_CTRL_COUNTER_THRESHOLD_MASK)
/*! @} */

/*! @name SM3BIST_CTRL1 - Submodule BIST Control */
/*! @{ */

#define FLEXPWM_SM3BIST_CTRL1_DATA_INITIAL_MASK  (0x1FU)
#define FLEXPWM_SM3BIST_CTRL1_DATA_INITIAL_SHIFT (0U)
#define FLEXPWM_SM3BIST_CTRL1_DATA_INITIAL_WIDTH (5U)
#define FLEXPWM_SM3BIST_CTRL1_DATA_INITIAL(x)    (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_CTRL1_DATA_INITIAL_SHIFT)) & FLEXPWM_SM3BIST_CTRL1_DATA_INITIAL_MASK)

#define FLEXPWM_SM3BIST_CTRL1_DATA_FINAL_MASK    (0x1F00U)
#define FLEXPWM_SM3BIST_CTRL1_DATA_FINAL_SHIFT   (8U)
#define FLEXPWM_SM3BIST_CTRL1_DATA_FINAL_WIDTH   (5U)
#define FLEXPWM_SM3BIST_CTRL1_DATA_FINAL(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_CTRL1_DATA_FINAL_SHIFT)) & FLEXPWM_SM3BIST_CTRL1_DATA_FINAL_MASK)
/*! @} */

/*! @name SM0BIST_STATUS - Submodule BIST Status */
/*! @{ */

#define FLEXPWM_SM0BIST_STATUS_BIST_DONE_MASK    (0x1U)
#define FLEXPWM_SM0BIST_STATUS_BIST_DONE_SHIFT   (0U)
#define FLEXPWM_SM0BIST_STATUS_BIST_DONE_WIDTH   (1U)
#define FLEXPWM_SM0BIST_STATUS_BIST_DONE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_STATUS_BIST_DONE_SHIFT)) & FLEXPWM_SM0BIST_STATUS_BIST_DONE_MASK)

#define FLEXPWM_SM0BIST_STATUS_BIST_PASS_MASK    (0x2U)
#define FLEXPWM_SM0BIST_STATUS_BIST_PASS_SHIFT   (1U)
#define FLEXPWM_SM0BIST_STATUS_BIST_PASS_WIDTH   (1U)
#define FLEXPWM_SM0BIST_STATUS_BIST_PASS(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_STATUS_BIST_PASS_SHIFT)) & FLEXPWM_SM0BIST_STATUS_BIST_PASS_MASK)

#define FLEXPWM_SM0BIST_STATUS_FAIL_CLK_MASK     (0x1F00U)
#define FLEXPWM_SM0BIST_STATUS_FAIL_CLK_SHIFT    (8U)
#define FLEXPWM_SM0BIST_STATUS_FAIL_CLK_WIDTH    (5U)
#define FLEXPWM_SM0BIST_STATUS_FAIL_CLK(x)       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_STATUS_FAIL_CLK_SHIFT)) & FLEXPWM_SM0BIST_STATUS_FAIL_CLK_MASK)
/*! @} */

/*! @name SM0BIST_STATUS1 - Submodule BIST Status */
/*! @{ */

#define FLEXPWM_SM0BIST_STATUS1_FAIL_DATA_MASK   (0x1FU)
#define FLEXPWM_SM0BIST_STATUS1_FAIL_DATA_SHIFT  (0U)
#define FLEXPWM_SM0BIST_STATUS1_FAIL_DATA_WIDTH  (5U)
#define FLEXPWM_SM0BIST_STATUS1_FAIL_DATA(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM0BIST_STATUS1_FAIL_DATA_SHIFT)) & FLEXPWM_SM0BIST_STATUS1_FAIL_DATA_MASK)
/*! @} */

/*! @name SM1BIST_STATUS - Submodule BIST Status */
/*! @{ */

#define FLEXPWM_SM1BIST_STATUS_BIST_DONE_MASK    (0x1U)
#define FLEXPWM_SM1BIST_STATUS_BIST_DONE_SHIFT   (0U)
#define FLEXPWM_SM1BIST_STATUS_BIST_DONE_WIDTH   (1U)
#define FLEXPWM_SM1BIST_STATUS_BIST_DONE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_STATUS_BIST_DONE_SHIFT)) & FLEXPWM_SM1BIST_STATUS_BIST_DONE_MASK)

#define FLEXPWM_SM1BIST_STATUS_BIST_PASS_MASK    (0x2U)
#define FLEXPWM_SM1BIST_STATUS_BIST_PASS_SHIFT   (1U)
#define FLEXPWM_SM1BIST_STATUS_BIST_PASS_WIDTH   (1U)
#define FLEXPWM_SM1BIST_STATUS_BIST_PASS(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_STATUS_BIST_PASS_SHIFT)) & FLEXPWM_SM1BIST_STATUS_BIST_PASS_MASK)

#define FLEXPWM_SM1BIST_STATUS_FAIL_CLK_MASK     (0x1F00U)
#define FLEXPWM_SM1BIST_STATUS_FAIL_CLK_SHIFT    (8U)
#define FLEXPWM_SM1BIST_STATUS_FAIL_CLK_WIDTH    (5U)
#define FLEXPWM_SM1BIST_STATUS_FAIL_CLK(x)       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_STATUS_FAIL_CLK_SHIFT)) & FLEXPWM_SM1BIST_STATUS_FAIL_CLK_MASK)
/*! @} */

/*! @name SM1BIST_STATUS1 - Submodule BIST Status */
/*! @{ */

#define FLEXPWM_SM1BIST_STATUS1_FAIL_DATA_MASK   (0x1FU)
#define FLEXPWM_SM1BIST_STATUS1_FAIL_DATA_SHIFT  (0U)
#define FLEXPWM_SM1BIST_STATUS1_FAIL_DATA_WIDTH  (5U)
#define FLEXPWM_SM1BIST_STATUS1_FAIL_DATA(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM1BIST_STATUS1_FAIL_DATA_SHIFT)) & FLEXPWM_SM1BIST_STATUS1_FAIL_DATA_MASK)
/*! @} */

/*! @name SM2BIST_STATUS - Submodule BIST Status */
/*! @{ */

#define FLEXPWM_SM2BIST_STATUS_BIST_DONE_MASK    (0x1U)
#define FLEXPWM_SM2BIST_STATUS_BIST_DONE_SHIFT   (0U)
#define FLEXPWM_SM2BIST_STATUS_BIST_DONE_WIDTH   (1U)
#define FLEXPWM_SM2BIST_STATUS_BIST_DONE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_STATUS_BIST_DONE_SHIFT)) & FLEXPWM_SM2BIST_STATUS_BIST_DONE_MASK)

#define FLEXPWM_SM2BIST_STATUS_BIST_PASS_MASK    (0x2U)
#define FLEXPWM_SM2BIST_STATUS_BIST_PASS_SHIFT   (1U)
#define FLEXPWM_SM2BIST_STATUS_BIST_PASS_WIDTH   (1U)
#define FLEXPWM_SM2BIST_STATUS_BIST_PASS(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_STATUS_BIST_PASS_SHIFT)) & FLEXPWM_SM2BIST_STATUS_BIST_PASS_MASK)

#define FLEXPWM_SM2BIST_STATUS_FAIL_CLK_MASK     (0x1F00U)
#define FLEXPWM_SM2BIST_STATUS_FAIL_CLK_SHIFT    (8U)
#define FLEXPWM_SM2BIST_STATUS_FAIL_CLK_WIDTH    (5U)
#define FLEXPWM_SM2BIST_STATUS_FAIL_CLK(x)       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_STATUS_FAIL_CLK_SHIFT)) & FLEXPWM_SM2BIST_STATUS_FAIL_CLK_MASK)
/*! @} */

/*! @name SM2BIST_STATUS1 - Submodule BIST Status */
/*! @{ */

#define FLEXPWM_SM2BIST_STATUS1_FAIL_DATA_MASK   (0x1FU)
#define FLEXPWM_SM2BIST_STATUS1_FAIL_DATA_SHIFT  (0U)
#define FLEXPWM_SM2BIST_STATUS1_FAIL_DATA_WIDTH  (5U)
#define FLEXPWM_SM2BIST_STATUS1_FAIL_DATA(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM2BIST_STATUS1_FAIL_DATA_SHIFT)) & FLEXPWM_SM2BIST_STATUS1_FAIL_DATA_MASK)
/*! @} */

/*! @name SM3BIST_STATUS - Submodule BIST Status */
/*! @{ */

#define FLEXPWM_SM3BIST_STATUS_BIST_DONE_MASK    (0x1U)
#define FLEXPWM_SM3BIST_STATUS_BIST_DONE_SHIFT   (0U)
#define FLEXPWM_SM3BIST_STATUS_BIST_DONE_WIDTH   (1U)
#define FLEXPWM_SM3BIST_STATUS_BIST_DONE(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_STATUS_BIST_DONE_SHIFT)) & FLEXPWM_SM3BIST_STATUS_BIST_DONE_MASK)

#define FLEXPWM_SM3BIST_STATUS_BIST_PASS_MASK    (0x2U)
#define FLEXPWM_SM3BIST_STATUS_BIST_PASS_SHIFT   (1U)
#define FLEXPWM_SM3BIST_STATUS_BIST_PASS_WIDTH   (1U)
#define FLEXPWM_SM3BIST_STATUS_BIST_PASS(x)      (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_STATUS_BIST_PASS_SHIFT)) & FLEXPWM_SM3BIST_STATUS_BIST_PASS_MASK)

#define FLEXPWM_SM3BIST_STATUS_FAIL_CLK_MASK     (0x1F00U)
#define FLEXPWM_SM3BIST_STATUS_FAIL_CLK_SHIFT    (8U)
#define FLEXPWM_SM3BIST_STATUS_FAIL_CLK_WIDTH    (5U)
#define FLEXPWM_SM3BIST_STATUS_FAIL_CLK(x)       (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_STATUS_FAIL_CLK_SHIFT)) & FLEXPWM_SM3BIST_STATUS_FAIL_CLK_MASK)
/*! @} */

/*! @name SM3BIST_STATUS1 - Submodule BIST Status */
/*! @{ */

#define FLEXPWM_SM3BIST_STATUS1_FAIL_DATA_MASK   (0x1FU)
#define FLEXPWM_SM3BIST_STATUS1_FAIL_DATA_SHIFT  (0U)
#define FLEXPWM_SM3BIST_STATUS1_FAIL_DATA_WIDTH  (5U)
#define FLEXPWM_SM3BIST_STATUS1_FAIL_DATA(x)     (((uint16_t)(((uint16_t)(x)) << FLEXPWM_SM3BIST_STATUS1_FAIL_DATA_SHIFT)) & FLEXPWM_SM3BIST_STATUS1_FAIL_DATA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group FLEXPWM_Register_Masks */

/*!
 * @}
 */ /* end of group FLEXPWM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_FLEXPWM_H_) */
