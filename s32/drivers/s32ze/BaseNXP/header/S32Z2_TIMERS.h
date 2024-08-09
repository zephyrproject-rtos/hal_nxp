/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_TIMERS.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_TIMERS
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
#if !defined(S32Z2_TIMERS_H_)  /* Check if memory map has not been already included */
#define S32Z2_TIMERS_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TIMERS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TIMERS_Peripheral_Access_Layer TIMERS Peripheral Access Layer
 * @{
 */

/** TIMERS - Register Layout Typedef */
typedef struct {
  __IO uint32_t TIMER0_CFG;                        /**< TIMER0 CFG, offset: 0x0 */
  __IO uint32_t TIMER0_EW;                         /**< TIMER0 EW, offset: 0x4 */
  __I  uint32_t TIMER0_CC;                         /**< TIMER0 CC, offset: 0x8 */
  __IO uint32_t TIMER0_SC;                         /**< TIMER0 SC, offset: 0xC */
  __IO uint32_t TIMER1_CFG;                        /**< TIMER1 CFG, offset: 0x10 */
  __IO uint32_t TIMER1_EW;                         /**< TIMER1 EW, offset: 0x14 */
  __I  uint32_t TIMER1_CC;                         /**< TIMER1 CC, offset: 0x18 */
  __IO uint32_t TIMER1_SC;                         /**< TIMER1 SC, offset: 0x1C */
  __IO uint32_t TIMER2_CFG;                        /**< TIMER2 CFG, offset: 0x20 */
  __IO uint32_t TIMER2_EW;                         /**< TIMER2 EW, offset: 0x24 */
  __I  uint32_t TIMER2_CC;                         /**< TIMER2 CC, offset: 0x28 */
  __IO uint32_t TIMER2_SC;                         /**< TIMER2 SC, offset: 0x2C */
  __IO uint32_t TIMER3_CFG;                        /**< TIMER3 CFG, offset: 0x30 */
  __IO uint32_t TIMER3_EW;                         /**< TIMER3 EW, offset: 0x34 */
  __I  uint32_t TIMER3_CC;                         /**< TIMER3 CC, offset: 0x38 */
  __IO uint32_t TIMER3_SC;                         /**< TIMER3 SC, offset: 0x3C */
} TIMERS_Type, *TIMERS_MemMapPtr;

/** Number of instances of the TIMERS module. */
#define TIMERS_INSTANCE_COUNT                    (1u)

/* TIMERS - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__TIMERS base address */
#define IP_CEVA_SPF2__TIMERS_BASE                (0x24402000u)
/** Peripheral CEVA_SPF2__TIMERS base pointer */
#define IP_CEVA_SPF2__TIMERS                     ((TIMERS_Type *)IP_CEVA_SPF2__TIMERS_BASE)
/** Array initializer of TIMERS peripheral base addresses */
#define IP_TIMERS_BASE_ADDRS                     { IP_CEVA_SPF2__TIMERS_BASE }
/** Array initializer of TIMERS peripheral base pointers */
#define IP_TIMERS_BASE_PTRS                      { IP_CEVA_SPF2__TIMERS }

/* ----------------------------------------------------------------------------
   -- TIMERS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TIMERS_Register_Masks TIMERS Register Masks
 * @{
 */

/*! @name TIMER0_CFG - TIMER0 CFG */
/*! @{ */

#define TIMERS_TIMER0_CFG_TS_MASK                (0x3U)
#define TIMERS_TIMER0_CFG_TS_SHIFT               (0U)
#define TIMERS_TIMER0_CFG_TS_WIDTH               (2U)
#define TIMERS_TIMER0_CFG_TS(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CFG_TS_SHIFT)) & TIMERS_TIMER0_CFG_TS_MASK)

#define TIMERS_TIMER0_CFG_CM_MASK                (0x1CU)
#define TIMERS_TIMER0_CFG_CM_SHIFT               (2U)
#define TIMERS_TIMER0_CFG_CM_WIDTH               (3U)
#define TIMERS_TIMER0_CFG_CM(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CFG_CM_SHIFT)) & TIMERS_TIMER0_CFG_CM_MASK)

#define TIMERS_TIMER0_CFG_ES_MASK                (0x20U)
#define TIMERS_TIMER0_CFG_ES_SHIFT               (5U)
#define TIMERS_TIMER0_CFG_ES_WIDTH               (1U)
#define TIMERS_TIMER0_CFG_ES(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CFG_ES_SHIFT)) & TIMERS_TIMER0_CFG_ES_MASK)

#define TIMERS_TIMER0_CFG_TP_MASK                (0x40U)
#define TIMERS_TIMER0_CFG_TP_SHIFT               (6U)
#define TIMERS_TIMER0_CFG_TP_WIDTH               (1U)
#define TIMERS_TIMER0_CFG_TP(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CFG_TP_SHIFT)) & TIMERS_TIMER0_CFG_TP_MASK)

#define TIMERS_TIMER0_CFG_TM_MASK                (0x180U)
#define TIMERS_TIMER0_CFG_TM_SHIFT               (7U)
#define TIMERS_TIMER0_CFG_TM_WIDTH               (2U)
#define TIMERS_TIMER0_CFG_TM(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CFG_TM_SHIFT)) & TIMERS_TIMER0_CFG_TM_MASK)

#define TIMERS_TIMER0_CFG_CAS_MASK               (0x400U)
#define TIMERS_TIMER0_CFG_CAS_SHIFT              (10U)
#define TIMERS_TIMER0_CFG_CAS_WIDTH              (1U)
#define TIMERS_TIMER0_CFG_CAS(x)                 (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CFG_CAS_SHIFT)) & TIMERS_TIMER0_CFG_CAS_MASK)

#define TIMERS_TIMER0_CFG_RES_MASK               (0x10000U)
#define TIMERS_TIMER0_CFG_RES_SHIFT              (16U)
#define TIMERS_TIMER0_CFG_RES_WIDTH              (1U)
#define TIMERS_TIMER0_CFG_RES(x)                 (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CFG_RES_SHIFT)) & TIMERS_TIMER0_CFG_RES_MASK)

#define TIMERS_TIMER0_CFG_PC_MASK                (0x20000U)
#define TIMERS_TIMER0_CFG_PC_SHIFT               (17U)
#define TIMERS_TIMER0_CFG_PC_WIDTH               (1U)
#define TIMERS_TIMER0_CFG_PC(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CFG_PC_SHIFT)) & TIMERS_TIMER0_CFG_PC_MASK)

#define TIMERS_TIMER0_CFG_CT_MASK                (0x40000U)
#define TIMERS_TIMER0_CFG_CT_SHIFT               (18U)
#define TIMERS_TIMER0_CFG_CT_WIDTH               (1U)
#define TIMERS_TIMER0_CFG_CT(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CFG_CT_SHIFT)) & TIMERS_TIMER0_CFG_CT_MASK)

#define TIMERS_TIMER0_CFG_RU_MASK                (0x80000U)
#define TIMERS_TIMER0_CFG_RU_SHIFT               (19U)
#define TIMERS_TIMER0_CFG_RU_WIDTH               (1U)
#define TIMERS_TIMER0_CFG_RU(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CFG_RU_SHIFT)) & TIMERS_TIMER0_CFG_RU_MASK)

#define TIMERS_TIMER0_CFG_BPEN_MASK              (0x100000U)
#define TIMERS_TIMER0_CFG_BPEN_SHIFT             (20U)
#define TIMERS_TIMER0_CFG_BPEN_WIDTH             (1U)
#define TIMERS_TIMER0_CFG_BPEN(x)                (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CFG_BPEN_SHIFT)) & TIMERS_TIMER0_CFG_BPEN_MASK)
/*! @} */

/*! @name TIMER0_EW - TIMER0 EW */
/*! @{ */

#define TIMERS_TIMER0_EW_EW_MASK                 (0x1U)
#define TIMERS_TIMER0_EW_EW_SHIFT                (0U)
#define TIMERS_TIMER0_EW_EW_WIDTH                (1U)
#define TIMERS_TIMER0_EW_EW(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_EW_EW_SHIFT)) & TIMERS_TIMER0_EW_EW_MASK)
/*! @} */

/*! @name TIMER0_CC - TIMER0 CC */
/*! @{ */

#define TIMERS_TIMER0_CC_CC_MASK                 (0xFFFFFFFFU)
#define TIMERS_TIMER0_CC_CC_SHIFT                (0U)
#define TIMERS_TIMER0_CC_CC_WIDTH                (32U)
#define TIMERS_TIMER0_CC_CC(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_CC_CC_SHIFT)) & TIMERS_TIMER0_CC_CC_MASK)
/*! @} */

/*! @name TIMER0_SC - TIMER0 SC */
/*! @{ */

#define TIMERS_TIMER0_SC_SC_MASK                 (0xFFFFFFFFU)
#define TIMERS_TIMER0_SC_SC_SHIFT                (0U)
#define TIMERS_TIMER0_SC_SC_WIDTH                (32U)
#define TIMERS_TIMER0_SC_SC(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER0_SC_SC_SHIFT)) & TIMERS_TIMER0_SC_SC_MASK)
/*! @} */

/*! @name TIMER1_CFG - TIMER1 CFG */
/*! @{ */

#define TIMERS_TIMER1_CFG_TS_MASK                (0x3U)
#define TIMERS_TIMER1_CFG_TS_SHIFT               (0U)
#define TIMERS_TIMER1_CFG_TS_WIDTH               (2U)
#define TIMERS_TIMER1_CFG_TS(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER1_CFG_TS_SHIFT)) & TIMERS_TIMER1_CFG_TS_MASK)

#define TIMERS_TIMER1_CFG_CM_MASK                (0x1CU)
#define TIMERS_TIMER1_CFG_CM_SHIFT               (2U)
#define TIMERS_TIMER1_CFG_CM_WIDTH               (3U)
#define TIMERS_TIMER1_CFG_CM(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER1_CFG_CM_SHIFT)) & TIMERS_TIMER1_CFG_CM_MASK)

#define TIMERS_TIMER1_CFG_ES_MASK                (0x20U)
#define TIMERS_TIMER1_CFG_ES_SHIFT               (5U)
#define TIMERS_TIMER1_CFG_ES_WIDTH               (1U)
#define TIMERS_TIMER1_CFG_ES(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER1_CFG_ES_SHIFT)) & TIMERS_TIMER1_CFG_ES_MASK)

#define TIMERS_TIMER1_CFG_RES_MASK               (0x10000U)
#define TIMERS_TIMER1_CFG_RES_SHIFT              (16U)
#define TIMERS_TIMER1_CFG_RES_WIDTH              (1U)
#define TIMERS_TIMER1_CFG_RES(x)                 (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER1_CFG_RES_SHIFT)) & TIMERS_TIMER1_CFG_RES_MASK)

#define TIMERS_TIMER1_CFG_PC_MASK                (0x20000U)
#define TIMERS_TIMER1_CFG_PC_SHIFT               (17U)
#define TIMERS_TIMER1_CFG_PC_WIDTH               (1U)
#define TIMERS_TIMER1_CFG_PC(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER1_CFG_PC_SHIFT)) & TIMERS_TIMER1_CFG_PC_MASK)

#define TIMERS_TIMER1_CFG_RU_MASK                (0x80000U)
#define TIMERS_TIMER1_CFG_RU_SHIFT               (19U)
#define TIMERS_TIMER1_CFG_RU_WIDTH               (1U)
#define TIMERS_TIMER1_CFG_RU(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER1_CFG_RU_SHIFT)) & TIMERS_TIMER1_CFG_RU_MASK)

#define TIMERS_TIMER1_CFG_BPEN_MASK              (0x100000U)
#define TIMERS_TIMER1_CFG_BPEN_SHIFT             (20U)
#define TIMERS_TIMER1_CFG_BPEN_WIDTH             (1U)
#define TIMERS_TIMER1_CFG_BPEN(x)                (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER1_CFG_BPEN_SHIFT)) & TIMERS_TIMER1_CFG_BPEN_MASK)
/*! @} */

/*! @name TIMER1_EW - TIMER1 EW */
/*! @{ */

#define TIMERS_TIMER1_EW_EW_MASK                 (0x1U)
#define TIMERS_TIMER1_EW_EW_SHIFT                (0U)
#define TIMERS_TIMER1_EW_EW_WIDTH                (1U)
#define TIMERS_TIMER1_EW_EW(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER1_EW_EW_SHIFT)) & TIMERS_TIMER1_EW_EW_MASK)
/*! @} */

/*! @name TIMER1_CC - TIMER1 CC */
/*! @{ */

#define TIMERS_TIMER1_CC_CC_MASK                 (0xFFFFFFFFU)
#define TIMERS_TIMER1_CC_CC_SHIFT                (0U)
#define TIMERS_TIMER1_CC_CC_WIDTH                (32U)
#define TIMERS_TIMER1_CC_CC(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER1_CC_CC_SHIFT)) & TIMERS_TIMER1_CC_CC_MASK)
/*! @} */

/*! @name TIMER1_SC - TIMER1 SC */
/*! @{ */

#define TIMERS_TIMER1_SC_SC_MASK                 (0xFFFFFFFFU)
#define TIMERS_TIMER1_SC_SC_SHIFT                (0U)
#define TIMERS_TIMER1_SC_SC_WIDTH                (32U)
#define TIMERS_TIMER1_SC_SC(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER1_SC_SC_SHIFT)) & TIMERS_TIMER1_SC_SC_MASK)
/*! @} */

/*! @name TIMER2_CFG - TIMER2 CFG */
/*! @{ */

#define TIMERS_TIMER2_CFG_TS_MASK                (0x3U)
#define TIMERS_TIMER2_CFG_TS_SHIFT               (0U)
#define TIMERS_TIMER2_CFG_TS_WIDTH               (2U)
#define TIMERS_TIMER2_CFG_TS(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER2_CFG_TS_SHIFT)) & TIMERS_TIMER2_CFG_TS_MASK)

#define TIMERS_TIMER2_CFG_CM_MASK                (0x1CU)
#define TIMERS_TIMER2_CFG_CM_SHIFT               (2U)
#define TIMERS_TIMER2_CFG_CM_WIDTH               (3U)
#define TIMERS_TIMER2_CFG_CM(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER2_CFG_CM_SHIFT)) & TIMERS_TIMER2_CFG_CM_MASK)

#define TIMERS_TIMER2_CFG_ES_MASK                (0x20U)
#define TIMERS_TIMER2_CFG_ES_SHIFT               (5U)
#define TIMERS_TIMER2_CFG_ES_WIDTH               (1U)
#define TIMERS_TIMER2_CFG_ES(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER2_CFG_ES_SHIFT)) & TIMERS_TIMER2_CFG_ES_MASK)

#define TIMERS_TIMER2_CFG_CAS_MASK               (0x400U)
#define TIMERS_TIMER2_CFG_CAS_SHIFT              (10U)
#define TIMERS_TIMER2_CFG_CAS_WIDTH              (1U)
#define TIMERS_TIMER2_CFG_CAS(x)                 (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER2_CFG_CAS_SHIFT)) & TIMERS_TIMER2_CFG_CAS_MASK)

#define TIMERS_TIMER2_CFG_RES_MASK               (0x10000U)
#define TIMERS_TIMER2_CFG_RES_SHIFT              (16U)
#define TIMERS_TIMER2_CFG_RES_WIDTH              (1U)
#define TIMERS_TIMER2_CFG_RES(x)                 (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER2_CFG_RES_SHIFT)) & TIMERS_TIMER2_CFG_RES_MASK)

#define TIMERS_TIMER2_CFG_PC_MASK                (0x20000U)
#define TIMERS_TIMER2_CFG_PC_SHIFT               (17U)
#define TIMERS_TIMER2_CFG_PC_WIDTH               (1U)
#define TIMERS_TIMER2_CFG_PC(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER2_CFG_PC_SHIFT)) & TIMERS_TIMER2_CFG_PC_MASK)

#define TIMERS_TIMER2_CFG_RU_MASK                (0x80000U)
#define TIMERS_TIMER2_CFG_RU_SHIFT               (19U)
#define TIMERS_TIMER2_CFG_RU_WIDTH               (1U)
#define TIMERS_TIMER2_CFG_RU(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER2_CFG_RU_SHIFT)) & TIMERS_TIMER2_CFG_RU_MASK)

#define TIMERS_TIMER2_CFG_BPEN_MASK              (0x100000U)
#define TIMERS_TIMER2_CFG_BPEN_SHIFT             (20U)
#define TIMERS_TIMER2_CFG_BPEN_WIDTH             (1U)
#define TIMERS_TIMER2_CFG_BPEN(x)                (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER2_CFG_BPEN_SHIFT)) & TIMERS_TIMER2_CFG_BPEN_MASK)
/*! @} */

/*! @name TIMER2_EW - TIMER2 EW */
/*! @{ */

#define TIMERS_TIMER2_EW_EW_MASK                 (0x1U)
#define TIMERS_TIMER2_EW_EW_SHIFT                (0U)
#define TIMERS_TIMER2_EW_EW_WIDTH                (1U)
#define TIMERS_TIMER2_EW_EW(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER2_EW_EW_SHIFT)) & TIMERS_TIMER2_EW_EW_MASK)
/*! @} */

/*! @name TIMER2_CC - TIMER2 CC */
/*! @{ */

#define TIMERS_TIMER2_CC_CC_MASK                 (0xFFFFFFFFU)
#define TIMERS_TIMER2_CC_CC_SHIFT                (0U)
#define TIMERS_TIMER2_CC_CC_WIDTH                (32U)
#define TIMERS_TIMER2_CC_CC(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER2_CC_CC_SHIFT)) & TIMERS_TIMER2_CC_CC_MASK)
/*! @} */

/*! @name TIMER2_SC - TIMER2 SC */
/*! @{ */

#define TIMERS_TIMER2_SC_SC_MASK                 (0xFFFFFFFFU)
#define TIMERS_TIMER2_SC_SC_SHIFT                (0U)
#define TIMERS_TIMER2_SC_SC_WIDTH                (32U)
#define TIMERS_TIMER2_SC_SC(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER2_SC_SC_SHIFT)) & TIMERS_TIMER2_SC_SC_MASK)
/*! @} */

/*! @name TIMER3_CFG - TIMER3 CFG */
/*! @{ */

#define TIMERS_TIMER3_CFG_TS_MASK                (0x3U)
#define TIMERS_TIMER3_CFG_TS_SHIFT               (0U)
#define TIMERS_TIMER3_CFG_TS_WIDTH               (2U)
#define TIMERS_TIMER3_CFG_TS(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER3_CFG_TS_SHIFT)) & TIMERS_TIMER3_CFG_TS_MASK)

#define TIMERS_TIMER3_CFG_CM_MASK                (0x1CU)
#define TIMERS_TIMER3_CFG_CM_SHIFT               (2U)
#define TIMERS_TIMER3_CFG_CM_WIDTH               (3U)
#define TIMERS_TIMER3_CFG_CM(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER3_CFG_CM_SHIFT)) & TIMERS_TIMER3_CFG_CM_MASK)

#define TIMERS_TIMER3_CFG_ES_MASK                (0x20U)
#define TIMERS_TIMER3_CFG_ES_SHIFT               (5U)
#define TIMERS_TIMER3_CFG_ES_WIDTH               (1U)
#define TIMERS_TIMER3_CFG_ES(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER3_CFG_ES_SHIFT)) & TIMERS_TIMER3_CFG_ES_MASK)

#define TIMERS_TIMER3_CFG_RES_MASK               (0x10000U)
#define TIMERS_TIMER3_CFG_RES_SHIFT              (16U)
#define TIMERS_TIMER3_CFG_RES_WIDTH              (1U)
#define TIMERS_TIMER3_CFG_RES(x)                 (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER3_CFG_RES_SHIFT)) & TIMERS_TIMER3_CFG_RES_MASK)

#define TIMERS_TIMER3_CFG_PC_MASK                (0x20000U)
#define TIMERS_TIMER3_CFG_PC_SHIFT               (17U)
#define TIMERS_TIMER3_CFG_PC_WIDTH               (1U)
#define TIMERS_TIMER3_CFG_PC(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER3_CFG_PC_SHIFT)) & TIMERS_TIMER3_CFG_PC_MASK)

#define TIMERS_TIMER3_CFG_RU_MASK                (0x80000U)
#define TIMERS_TIMER3_CFG_RU_SHIFT               (19U)
#define TIMERS_TIMER3_CFG_RU_WIDTH               (1U)
#define TIMERS_TIMER3_CFG_RU(x)                  (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER3_CFG_RU_SHIFT)) & TIMERS_TIMER3_CFG_RU_MASK)

#define TIMERS_TIMER3_CFG_BPEN_MASK              (0x100000U)
#define TIMERS_TIMER3_CFG_BPEN_SHIFT             (20U)
#define TIMERS_TIMER3_CFG_BPEN_WIDTH             (1U)
#define TIMERS_TIMER3_CFG_BPEN(x)                (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER3_CFG_BPEN_SHIFT)) & TIMERS_TIMER3_CFG_BPEN_MASK)
/*! @} */

/*! @name TIMER3_EW - TIMER3 EW */
/*! @{ */

#define TIMERS_TIMER3_EW_EW_MASK                 (0x1U)
#define TIMERS_TIMER3_EW_EW_SHIFT                (0U)
#define TIMERS_TIMER3_EW_EW_WIDTH                (1U)
#define TIMERS_TIMER3_EW_EW(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER3_EW_EW_SHIFT)) & TIMERS_TIMER3_EW_EW_MASK)
/*! @} */

/*! @name TIMER3_CC - TIMER3 CC */
/*! @{ */

#define TIMERS_TIMER3_CC_CC_MASK                 (0xFFFFFFFFU)
#define TIMERS_TIMER3_CC_CC_SHIFT                (0U)
#define TIMERS_TIMER3_CC_CC_WIDTH                (32U)
#define TIMERS_TIMER3_CC_CC(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER3_CC_CC_SHIFT)) & TIMERS_TIMER3_CC_CC_MASK)
/*! @} */

/*! @name TIMER3_SC - TIMER3 SC */
/*! @{ */

#define TIMERS_TIMER3_SC_SC_MASK                 (0xFFFFFFFFU)
#define TIMERS_TIMER3_SC_SC_SHIFT                (0U)
#define TIMERS_TIMER3_SC_SC_WIDTH                (32U)
#define TIMERS_TIMER3_SC_SC(x)                   (((uint32_t)(((uint32_t)(x)) << TIMERS_TIMER3_SC_SC_SHIFT)) & TIMERS_TIMER3_SC_SC_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TIMERS_Register_Masks */

/*!
 * @}
 */ /* end of group TIMERS_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_TIMERS_H_) */
