/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_TMU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_TMU
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
#if !defined(S32Z2_TMU_H_)  /* Check if memory map has not been already included */
#define S32Z2_TMU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Peripheral_Access_Layer TMU Peripheral Access Layer
 * @{
 */

/** TMU - Size of Registers Arrays */
#define TMU_TRITRATSR_COUNT                       5u
#define TMU_NUM_SITE_RC_COUNT                     16u

/** TMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t TMR;                               /**< Mode, offset: 0x0 */
  __IO uint32_t TSR;                               /**< Status, offset: 0x4 */
  __IO uint32_t TMSR;                              /**< Monitor Site, offset: 0x8 */
  __IO uint32_t TMTMIR;                            /**< Monitor Temperature Measurement Interval, offset: 0xC */
  uint8_t RESERVED_0[16];
  __IO uint32_t TIER;                              /**< Interrupt Enable, offset: 0x20 */
  __IO uint32_t TIDR;                              /**< Interrupt Detect, offset: 0x24 */
  uint8_t RESERVED_1[8];
  __IO uint32_t TIISCR;                            /**< Interrupt Immediate Site Capture, offset: 0x30 */
  __IO uint32_t TIASCR;                            /**< Interrupt Average Site Capture, offset: 0x34 */
  __IO uint32_t TICSCR;                            /**< Interrupt Critical Site Capture, offset: 0x38 */
  uint8_t RESERVED_2[4];
  __IO uint32_t TMHTCR;                            /**< Monitor High Temperature Capture, offset: 0x40 */
  __IO uint32_t TMLTCR;                            /**< Monitor Low Temperature Capture, offset: 0x44 */
  __IO uint32_t TMRTRCR;                           /**< Monitor Rising Temperature Rate Capture, offset: 0x48 */
  __IO uint32_t TMFTRCR;                           /**< Monitor Falling Temperature Rate Capture, offset: 0x4C */
  __IO uint32_t TMHTITR;                           /**< Monitor High Temperature Immediate Threshold, offset: 0x50 */
  __IO uint32_t TMHTATR;                           /**< Monitor High Temperature Average Threshold, offset: 0x54 */
  __IO uint32_t TMHTACTR;                          /**< Monitor High Temperature Average Critical Threshold, offset: 0x58 */
  uint8_t RESERVED_3[4];
  __IO uint32_t TMLTITR;                           /**< Monitor Low Temperature Immediate Threshold, offset: 0x60 */
  __IO uint32_t TMLTATR;                           /**< Monitor Low Temperature Average Threshold, offset: 0x64 */
  __IO uint32_t TMLTACTR;                          /**< Monitor Low Temperature Average Critical Threshold, offset: 0x68 */
  uint8_t RESERVED_4[4];
  __IO uint32_t TMRTRCTR;                          /**< Monitor Rising Temperature Rate Critical Threshold, offset: 0x70 */
  __IO uint32_t TMFTRCTR;                          /**< Monitor Falling Temperature Rate Critical Threshold, offset: 0x74 */
  uint8_t RESERVED_5[8];
  __IO uint32_t TTCFGR;                            /**< Temperature Configuration, offset: 0x80 */
  __IO uint32_t TSCFGR;                            /**< Sensor Configuration, offset: 0x84 */
  uint8_t RESERVED_6[120];
  struct TMU_TRITRATSR {                           /* offset: 0x100, array step: 0x10 */
    __I  uint32_t TRITSR;                            /**< Report Immediate Temperature at Site, array offset: 0x100, array step: 0x10 */
    __I  uint32_t TRATSR;                            /**< Report Average Temperature at Site, array offset: 0x104, array step: 0x10 */
    uint8_t RESERVED_0[8];
  } TRITRATSR[TMU_TRITRATSR_COUNT];
  uint8_t RESERVED_7[3504];
  __IO uint32_t TCMCFG;                            /**< Central Module Configuration, offset: 0xF00 */
  uint8_t RESERVED_8[12];
  __IO uint32_t TTRCR[TMU_NUM_SITE_RC_COUNT];      /**< Temperature Range Control 0..Temperature Range Control 15, array offset: 0xF10, array step: 0x4 */
} TMU_Type, *TMU_MemMapPtr;

/** Number of instances of the TMU module. */
#define TMU_INSTANCE_COUNT                       (1u)

/* TMU - Peripheral instance base addresses */
/** Peripheral TMU base address */
#define IP_TMU_BASE                              (0x402B0000u)
/** Peripheral TMU base pointer */
#define IP_TMU                                   ((TMU_Type *)IP_TMU_BASE)
/** Array initializer of TMU peripheral base addresses */
#define IP_TMU_BASE_ADDRS                        { IP_TMU_BASE }
/** Array initializer of TMU peripheral base pointers */
#define IP_TMU_BASE_PTRS                         { IP_TMU }

/* ----------------------------------------------------------------------------
   -- TMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Register_Masks TMU Register Masks
 * @{
 */

/*! @name TMR - Mode */
/*! @{ */

#define TMU_TMR_ALPF_MASK                        (0x3000000U)
#define TMU_TMR_ALPF_SHIFT                       (24U)
#define TMU_TMR_ALPF_WIDTH                       (2U)
#define TMU_TMR_ALPF(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TMR_ALPF_SHIFT)) & TMU_TMR_ALPF_MASK)

#define TMU_TMR_CMD_MASK                         (0x20000000U)
#define TMU_TMR_CMD_SHIFT                        (29U)
#define TMU_TMR_CMD_WIDTH                        (1U)
#define TMU_TMR_CMD(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TMR_CMD_SHIFT)) & TMU_TMR_CMD_MASK)

#define TMU_TMR_MODE_MASK                        (0xC0000000U)
#define TMU_TMR_MODE_SHIFT                       (30U)
#define TMU_TMR_MODE_WIDTH                       (2U)
#define TMU_TMR_MODE(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TMR_MODE_SHIFT)) & TMU_TMR_MODE_MASK)
/*! @} */

/*! @name TSR - Status */
/*! @{ */

#define TMU_TSR_ORH_MASK                         (0x10000000U)
#define TMU_TSR_ORH_SHIFT                        (28U)
#define TMU_TSR_ORH_WIDTH                        (1U)
#define TMU_TSR_ORH(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TSR_ORH_SHIFT)) & TMU_TSR_ORH_MASK)

#define TMU_TSR_ORL_MASK                         (0x20000000U)
#define TMU_TSR_ORL_SHIFT                        (29U)
#define TMU_TSR_ORL_WIDTH                        (1U)
#define TMU_TSR_ORL(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TSR_ORL_SHIFT)) & TMU_TSR_ORL_MASK)

#define TMU_TSR_MIE_MASK                         (0x40000000U)
#define TMU_TSR_MIE_SHIFT                        (30U)
#define TMU_TSR_MIE_WIDTH                        (1U)
#define TMU_TSR_MIE(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TSR_MIE_SHIFT)) & TMU_TSR_MIE_MASK)

#define TMU_TSR_TB_MASK                          (0x80000000U)
#define TMU_TSR_TB_SHIFT                         (31U)
#define TMU_TSR_TB_WIDTH                         (1U)
#define TMU_TSR_TB(x)                            (((uint32_t)(((uint32_t)(x)) << TMU_TSR_TB_SHIFT)) & TMU_TSR_TB_MASK)
/*! @} */

/*! @name TMSR - Monitor Site */
/*! @{ */

#define TMU_TMSR_SITE_MASK                       (0x1FU)
#define TMU_TMSR_SITE_SHIFT                      (0U)
#define TMU_TMSR_SITE_WIDTH                      (5U)
#define TMU_TMSR_SITE(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TMSR_SITE_SHIFT)) & TMU_TMSR_SITE_MASK)
/*! @} */

/*! @name TMTMIR - Monitor Temperature Measurement Interval */
/*! @{ */

#define TMU_TMTMIR_TMI_MASK                      (0xFU)
#define TMU_TMTMIR_TMI_SHIFT                     (0U)
#define TMU_TMTMIR_TMI_WIDTH                     (4U)
#define TMU_TMTMIR_TMI(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMTMIR_TMI_SHIFT)) & TMU_TMTMIR_TMI_MASK)
/*! @} */

/*! @name TIER - Interrupt Enable */
/*! @{ */

#define TMU_TIER_FTRCTIE_MASK                    (0x1000000U)
#define TMU_TIER_FTRCTIE_SHIFT                   (24U)
#define TMU_TIER_FTRCTIE_WIDTH                   (1U)
#define TMU_TIER_FTRCTIE(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_FTRCTIE_SHIFT)) & TMU_TIER_FTRCTIE_MASK)

#define TMU_TIER_RTRCTIE_MASK                    (0x2000000U)
#define TMU_TIER_RTRCTIE_SHIFT                   (25U)
#define TMU_TIER_RTRCTIE_WIDTH                   (1U)
#define TMU_TIER_RTRCTIE(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_RTRCTIE_SHIFT)) & TMU_TIER_RTRCTIE_MASK)

#define TMU_TIER_ALTCTIE_MASK                    (0x4000000U)
#define TMU_TIER_ALTCTIE_SHIFT                   (26U)
#define TMU_TIER_ALTCTIE_WIDTH                   (1U)
#define TMU_TIER_ALTCTIE(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ALTCTIE_SHIFT)) & TMU_TIER_ALTCTIE_MASK)

#define TMU_TIER_ALTTIE_MASK                     (0x8000000U)
#define TMU_TIER_ALTTIE_SHIFT                    (27U)
#define TMU_TIER_ALTTIE_WIDTH                    (1U)
#define TMU_TIER_ALTTIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ALTTIE_SHIFT)) & TMU_TIER_ALTTIE_MASK)

#define TMU_TIER_ILTTIE_MASK                     (0x10000000U)
#define TMU_TIER_ILTTIE_SHIFT                    (28U)
#define TMU_TIER_ILTTIE_WIDTH                    (1U)
#define TMU_TIER_ILTTIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ILTTIE_SHIFT)) & TMU_TIER_ILTTIE_MASK)

#define TMU_TIER_AHTCTIE_MASK                    (0x20000000U)
#define TMU_TIER_AHTCTIE_SHIFT                   (29U)
#define TMU_TIER_AHTCTIE_WIDTH                   (1U)
#define TMU_TIER_AHTCTIE(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_AHTCTIE_SHIFT)) & TMU_TIER_AHTCTIE_MASK)

#define TMU_TIER_AHTTIE_MASK                     (0x40000000U)
#define TMU_TIER_AHTTIE_SHIFT                    (30U)
#define TMU_TIER_AHTTIE_WIDTH                    (1U)
#define TMU_TIER_AHTTIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_AHTTIE_SHIFT)) & TMU_TIER_AHTTIE_MASK)

#define TMU_TIER_IHTTIE_MASK                     (0x80000000U)
#define TMU_TIER_IHTTIE_SHIFT                    (31U)
#define TMU_TIER_IHTTIE_WIDTH                    (1U)
#define TMU_TIER_IHTTIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_IHTTIE_SHIFT)) & TMU_TIER_IHTTIE_MASK)
/*! @} */

/*! @name TIDR - Interrupt Detect */
/*! @{ */

#define TMU_TIDR_FTRCT_MASK                      (0x1000000U)
#define TMU_TIDR_FTRCT_SHIFT                     (24U)
#define TMU_TIDR_FTRCT_WIDTH                     (1U)
#define TMU_TIDR_FTRCT(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_FTRCT_SHIFT)) & TMU_TIDR_FTRCT_MASK)

#define TMU_TIDR_RTRCT_MASK                      (0x2000000U)
#define TMU_TIDR_RTRCT_SHIFT                     (25U)
#define TMU_TIDR_RTRCT_WIDTH                     (1U)
#define TMU_TIDR_RTRCT(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_RTRCT_SHIFT)) & TMU_TIDR_RTRCT_MASK)

#define TMU_TIDR_ALTCT_MASK                      (0x4000000U)
#define TMU_TIDR_ALTCT_SHIFT                     (26U)
#define TMU_TIDR_ALTCT_WIDTH                     (1U)
#define TMU_TIDR_ALTCT(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ALTCT_SHIFT)) & TMU_TIDR_ALTCT_MASK)

#define TMU_TIDR_ALTT_MASK                       (0x8000000U)
#define TMU_TIDR_ALTT_SHIFT                      (27U)
#define TMU_TIDR_ALTT_WIDTH                      (1U)
#define TMU_TIDR_ALTT(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ALTT_SHIFT)) & TMU_TIDR_ALTT_MASK)

#define TMU_TIDR_ILTT_MASK                       (0x10000000U)
#define TMU_TIDR_ILTT_SHIFT                      (28U)
#define TMU_TIDR_ILTT_WIDTH                      (1U)
#define TMU_TIDR_ILTT(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ILTT_SHIFT)) & TMU_TIDR_ILTT_MASK)

#define TMU_TIDR_AHTCT_MASK                      (0x20000000U)
#define TMU_TIDR_AHTCT_SHIFT                     (29U)
#define TMU_TIDR_AHTCT_WIDTH                     (1U)
#define TMU_TIDR_AHTCT(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_AHTCT_SHIFT)) & TMU_TIDR_AHTCT_MASK)

#define TMU_TIDR_AHTT_MASK                       (0x40000000U)
#define TMU_TIDR_AHTT_SHIFT                      (30U)
#define TMU_TIDR_AHTT_WIDTH                      (1U)
#define TMU_TIDR_AHTT(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_AHTT_SHIFT)) & TMU_TIDR_AHTT_MASK)

#define TMU_TIDR_IHTT_MASK                       (0x80000000U)
#define TMU_TIDR_IHTT_SHIFT                      (31U)
#define TMU_TIDR_IHTT_WIDTH                      (1U)
#define TMU_TIDR_IHTT(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_IHTT_SHIFT)) & TMU_TIDR_IHTT_MASK)
/*! @} */

/*! @name TIISCR - Interrupt Immediate Site Capture */
/*! @{ */

#define TMU_TIISCR_SITE_MASK                     (0x1FU)
#define TMU_TIISCR_SITE_SHIFT                    (0U)
#define TMU_TIISCR_SITE_WIDTH                    (5U)
#define TMU_TIISCR_SITE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIISCR_SITE_SHIFT)) & TMU_TIISCR_SITE_MASK)
/*! @} */

/*! @name TIASCR - Interrupt Average Site Capture */
/*! @{ */

#define TMU_TIASCR_SITE_MASK                     (0x1FU)
#define TMU_TIASCR_SITE_SHIFT                    (0U)
#define TMU_TIASCR_SITE_WIDTH                    (5U)
#define TMU_TIASCR_SITE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIASCR_SITE_SHIFT)) & TMU_TIASCR_SITE_MASK)
/*! @} */

/*! @name TICSCR - Interrupt Critical Site Capture */
/*! @{ */

#define TMU_TICSCR_SITE_MASK                     (0x1FU)
#define TMU_TICSCR_SITE_SHIFT                    (0U)
#define TMU_TICSCR_SITE_WIDTH                    (5U)
#define TMU_TICSCR_SITE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TICSCR_SITE_SHIFT)) & TMU_TICSCR_SITE_MASK)
/*! @} */

/*! @name TMHTCR - Monitor High Temperature Capture */
/*! @{ */

#define TMU_TMHTCR_TEMP_MASK                     (0x1FFU)
#define TMU_TMHTCR_TEMP_SHIFT                    (0U)
#define TMU_TMHTCR_TEMP_WIDTH                    (9U)
#define TMU_TMHTCR_TEMP(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMHTCR_TEMP_SHIFT)) & TMU_TMHTCR_TEMP_MASK)

#define TMU_TMHTCR_TP5_MASK                      (0x200U)
#define TMU_TMHTCR_TP5_SHIFT                     (9U)
#define TMU_TMHTCR_TP5_WIDTH                     (1U)
#define TMU_TMHTCR_TP5(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMHTCR_TP5_SHIFT)) & TMU_TMHTCR_TP5_MASK)

#define TMU_TMHTCR_V_MASK                        (0x80000000U)
#define TMU_TMHTCR_V_SHIFT                       (31U)
#define TMU_TMHTCR_V_WIDTH                       (1U)
#define TMU_TMHTCR_V(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TMHTCR_V_SHIFT)) & TMU_TMHTCR_V_MASK)
/*! @} */

/*! @name TMLTCR - Monitor Low Temperature Capture */
/*! @{ */

#define TMU_TMLTCR_TEMP_MASK                     (0x1FFU)
#define TMU_TMLTCR_TEMP_SHIFT                    (0U)
#define TMU_TMLTCR_TEMP_WIDTH                    (9U)
#define TMU_TMLTCR_TEMP(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMLTCR_TEMP_SHIFT)) & TMU_TMLTCR_TEMP_MASK)

#define TMU_TMLTCR_TP5_MASK                      (0x200U)
#define TMU_TMLTCR_TP5_SHIFT                     (9U)
#define TMU_TMLTCR_TP5_WIDTH                     (1U)
#define TMU_TMLTCR_TP5(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMLTCR_TP5_SHIFT)) & TMU_TMLTCR_TP5_MASK)

#define TMU_TMLTCR_V_MASK                        (0x80000000U)
#define TMU_TMLTCR_V_SHIFT                       (31U)
#define TMU_TMLTCR_V_WIDTH                       (1U)
#define TMU_TMLTCR_V(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TMLTCR_V_SHIFT)) & TMU_TMLTCR_V_MASK)
/*! @} */

/*! @name TMRTRCR - Monitor Rising Temperature Rate Capture */
/*! @{ */

#define TMU_TMRTRCR_TEMP_MASK                    (0xFFU)
#define TMU_TMRTRCR_TEMP_SHIFT                   (0U)
#define TMU_TMRTRCR_TEMP_WIDTH                   (8U)
#define TMU_TMRTRCR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMRTRCR_TEMP_SHIFT)) & TMU_TMRTRCR_TEMP_MASK)

#define TMU_TMRTRCR_V_MASK                       (0x80000000U)
#define TMU_TMRTRCR_V_SHIFT                      (31U)
#define TMU_TMRTRCR_V_WIDTH                      (1U)
#define TMU_TMRTRCR_V(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TMRTRCR_V_SHIFT)) & TMU_TMRTRCR_V_MASK)
/*! @} */

/*! @name TMFTRCR - Monitor Falling Temperature Rate Capture */
/*! @{ */

#define TMU_TMFTRCR_TEMP_MASK                    (0xFFU)
#define TMU_TMFTRCR_TEMP_SHIFT                   (0U)
#define TMU_TMFTRCR_TEMP_WIDTH                   (8U)
#define TMU_TMFTRCR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMFTRCR_TEMP_SHIFT)) & TMU_TMFTRCR_TEMP_MASK)

#define TMU_TMFTRCR_V_MASK                       (0x80000000U)
#define TMU_TMFTRCR_V_SHIFT                      (31U)
#define TMU_TMFTRCR_V_WIDTH                      (1U)
#define TMU_TMFTRCR_V(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TMFTRCR_V_SHIFT)) & TMU_TMFTRCR_V_MASK)
/*! @} */

/*! @name TMHTITR - Monitor High Temperature Immediate Threshold */
/*! @{ */

#define TMU_TMHTITR_TEMP_MASK                    (0x1FFU)
#define TMU_TMHTITR_TEMP_SHIFT                   (0U)
#define TMU_TMHTITR_TEMP_WIDTH                   (9U)
#define TMU_TMHTITR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMHTITR_TEMP_SHIFT)) & TMU_TMHTITR_TEMP_MASK)

#define TMU_TMHTITR_EN_MASK                      (0x80000000U)
#define TMU_TMHTITR_EN_SHIFT                     (31U)
#define TMU_TMHTITR_EN_WIDTH                     (1U)
#define TMU_TMHTITR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMHTITR_EN_SHIFT)) & TMU_TMHTITR_EN_MASK)
/*! @} */

/*! @name TMHTATR - Monitor High Temperature Average Threshold */
/*! @{ */

#define TMU_TMHTATR_TEMP_MASK                    (0x1FFU)
#define TMU_TMHTATR_TEMP_SHIFT                   (0U)
#define TMU_TMHTATR_TEMP_WIDTH                   (9U)
#define TMU_TMHTATR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMHTATR_TEMP_SHIFT)) & TMU_TMHTATR_TEMP_MASK)

#define TMU_TMHTATR_EN_MASK                      (0x80000000U)
#define TMU_TMHTATR_EN_SHIFT                     (31U)
#define TMU_TMHTATR_EN_WIDTH                     (1U)
#define TMU_TMHTATR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMHTATR_EN_SHIFT)) & TMU_TMHTATR_EN_MASK)
/*! @} */

/*! @name TMHTACTR - Monitor High Temperature Average Critical Threshold */
/*! @{ */

#define TMU_TMHTACTR_TEMP_MASK                   (0x1FFU)
#define TMU_TMHTACTR_TEMP_SHIFT                  (0U)
#define TMU_TMHTACTR_TEMP_WIDTH                  (9U)
#define TMU_TMHTACTR_TEMP(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMHTACTR_TEMP_SHIFT)) & TMU_TMHTACTR_TEMP_MASK)

#define TMU_TMHTACTR_EN_MASK                     (0x80000000U)
#define TMU_TMHTACTR_EN_SHIFT                    (31U)
#define TMU_TMHTACTR_EN_WIDTH                    (1U)
#define TMU_TMHTACTR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMHTACTR_EN_SHIFT)) & TMU_TMHTACTR_EN_MASK)
/*! @} */

/*! @name TMLTITR - Monitor Low Temperature Immediate Threshold */
/*! @{ */

#define TMU_TMLTITR_TEMP_MASK                    (0x1FFU)
#define TMU_TMLTITR_TEMP_SHIFT                   (0U)
#define TMU_TMLTITR_TEMP_WIDTH                   (9U)
#define TMU_TMLTITR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMLTITR_TEMP_SHIFT)) & TMU_TMLTITR_TEMP_MASK)

#define TMU_TMLTITR_EN_MASK                      (0x80000000U)
#define TMU_TMLTITR_EN_SHIFT                     (31U)
#define TMU_TMLTITR_EN_WIDTH                     (1U)
#define TMU_TMLTITR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMLTITR_EN_SHIFT)) & TMU_TMLTITR_EN_MASK)
/*! @} */

/*! @name TMLTATR - Monitor Low Temperature Average Threshold */
/*! @{ */

#define TMU_TMLTATR_TEMP_MASK                    (0x1FFU)
#define TMU_TMLTATR_TEMP_SHIFT                   (0U)
#define TMU_TMLTATR_TEMP_WIDTH                   (9U)
#define TMU_TMLTATR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMLTATR_TEMP_SHIFT)) & TMU_TMLTATR_TEMP_MASK)

#define TMU_TMLTATR_EN_MASK                      (0x80000000U)
#define TMU_TMLTATR_EN_SHIFT                     (31U)
#define TMU_TMLTATR_EN_WIDTH                     (1U)
#define TMU_TMLTATR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMLTATR_EN_SHIFT)) & TMU_TMLTATR_EN_MASK)
/*! @} */

/*! @name TMLTACTR - Monitor Low Temperature Average Critical Threshold */
/*! @{ */

#define TMU_TMLTACTR_TEMP_MASK                   (0x1FFU)
#define TMU_TMLTACTR_TEMP_SHIFT                  (0U)
#define TMU_TMLTACTR_TEMP_WIDTH                  (9U)
#define TMU_TMLTACTR_TEMP(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMLTACTR_TEMP_SHIFT)) & TMU_TMLTACTR_TEMP_MASK)

#define TMU_TMLTACTR_EN_MASK                     (0x80000000U)
#define TMU_TMLTACTR_EN_SHIFT                    (31U)
#define TMU_TMLTACTR_EN_WIDTH                    (1U)
#define TMU_TMLTACTR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMLTACTR_EN_SHIFT)) & TMU_TMLTACTR_EN_MASK)
/*! @} */

/*! @name TMRTRCTR - Monitor Rising Temperature Rate Critical Threshold */
/*! @{ */

#define TMU_TMRTRCTR_TEMP_MASK                   (0xFFU)
#define TMU_TMRTRCTR_TEMP_SHIFT                  (0U)
#define TMU_TMRTRCTR_TEMP_WIDTH                  (8U)
#define TMU_TMRTRCTR_TEMP(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMRTRCTR_TEMP_SHIFT)) & TMU_TMRTRCTR_TEMP_MASK)

#define TMU_TMRTRCTR_EN_MASK                     (0x80000000U)
#define TMU_TMRTRCTR_EN_SHIFT                    (31U)
#define TMU_TMRTRCTR_EN_WIDTH                    (1U)
#define TMU_TMRTRCTR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMRTRCTR_EN_SHIFT)) & TMU_TMRTRCTR_EN_MASK)
/*! @} */

/*! @name TMFTRCTR - Monitor Falling Temperature Rate Critical Threshold */
/*! @{ */

#define TMU_TMFTRCTR_TEMP_MASK                   (0xFFU)
#define TMU_TMFTRCTR_TEMP_SHIFT                  (0U)
#define TMU_TMFTRCTR_TEMP_WIDTH                  (8U)
#define TMU_TMFTRCTR_TEMP(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMFTRCTR_TEMP_SHIFT)) & TMU_TMFTRCTR_TEMP_MASK)

#define TMU_TMFTRCTR_EN_MASK                     (0x80000000U)
#define TMU_TMFTRCTR_EN_SHIFT                    (31U)
#define TMU_TMFTRCTR_EN_WIDTH                    (1U)
#define TMU_TMFTRCTR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMFTRCTR_EN_SHIFT)) & TMU_TMFTRCTR_EN_MASK)
/*! @} */

/*! @name TTCFGR - Temperature Configuration */
/*! @{ */

#define TMU_TTCFGR_CAL_PT_MASK                   (0xFU)
#define TMU_TTCFGR_CAL_PT_SHIFT                  (0U)
#define TMU_TTCFGR_CAL_PT_WIDTH                  (4U)
#define TMU_TTCFGR_CAL_PT(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TTCFGR_CAL_PT_SHIFT)) & TMU_TTCFGR_CAL_PT_MASK)
/*! @} */

/*! @name TSCFGR - Sensor Configuration */
/*! @{ */

#define TMU_TSCFGR_SENSOR_MASK                   (0x1FFU)
#define TMU_TSCFGR_SENSOR_SHIFT                  (0U)
#define TMU_TSCFGR_SENSOR_WIDTH                  (9U)
#define TMU_TSCFGR_SENSOR(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TSCFGR_SENSOR_SHIFT)) & TMU_TSCFGR_SENSOR_MASK)
/*! @} */

/*! @name TRITSR - Report Immediate Temperature at Site */
/*! @{ */

#define TMU_TRITSR_TEMP_MASK                     (0x1FFU)
#define TMU_TRITSR_TEMP_SHIFT                    (0U)
#define TMU_TRITSR_TEMP_WIDTH                    (9U)
#define TMU_TRITSR_TEMP(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_TEMP_SHIFT)) & TMU_TRITSR_TEMP_MASK)

#define TMU_TRITSR_TP5_MASK                      (0x200U)
#define TMU_TRITSR_TP5_SHIFT                     (9U)
#define TMU_TRITSR_TP5_WIDTH                     (1U)
#define TMU_TRITSR_TP5(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_TP5_SHIFT)) & TMU_TRITSR_TP5_MASK)

#define TMU_TRITSR_V_MASK                        (0x80000000U)
#define TMU_TRITSR_V_SHIFT                       (31U)
#define TMU_TRITSR_V_WIDTH                       (1U)
#define TMU_TRITSR_V(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_V_SHIFT)) & TMU_TRITSR_V_MASK)
/*! @} */

/*! @name TRATSR - Report Average Temperature at Site */
/*! @{ */

#define TMU_TRATSR_TEMP_MASK                     (0x1FFU)
#define TMU_TRATSR_TEMP_SHIFT                    (0U)
#define TMU_TRATSR_TEMP_WIDTH                    (9U)
#define TMU_TRATSR_TEMP(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TRATSR_TEMP_SHIFT)) & TMU_TRATSR_TEMP_MASK)

#define TMU_TRATSR_V_MASK                        (0x80000000U)
#define TMU_TRATSR_V_SHIFT                       (31U)
#define TMU_TRATSR_V_WIDTH                       (1U)
#define TMU_TRATSR_V(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TRATSR_V_SHIFT)) & TMU_TRATSR_V_MASK)
/*! @} */

/*! @name TCMCFG - Central Module Configuration */
/*! @{ */

#define TMU_TCMCFG_DAC_OFFSET_MASK               (0x7FU)
#define TMU_TCMCFG_DAC_OFFSET_SHIFT              (0U)
#define TMU_TCMCFG_DAC_OFFSET_WIDTH              (7U)
#define TMU_TCMCFG_DAC_OFFSET(x)                 (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_DAC_OFFSET_SHIFT)) & TMU_TCMCFG_DAC_OFFSET_MASK)

#define TMU_TCMCFG_CMET_MASK                     (0x300U)
#define TMU_TCMCFG_CMET_SHIFT                    (8U)
#define TMU_TCMCFG_CMET_WIDTH                    (2U)
#define TMU_TCMCFG_CMET(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_CMET_SHIFT)) & TMU_TCMCFG_CMET_MASK)

#define TMU_TCMCFG_DFD_MASK                      (0xC00U)
#define TMU_TCMCFG_DFD_SHIFT                     (10U)
#define TMU_TCMCFG_DFD_WIDTH                     (2U)
#define TMU_TCMCFG_DFD(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_DFD_SHIFT)) & TMU_TCMCFG_DFD_MASK)

#define TMU_TCMCFG_CLK_DIV_MASK                  (0xF000U)
#define TMU_TCMCFG_CLK_DIV_SHIFT                 (12U)
#define TMU_TCMCFG_CLK_DIV_WIDTH                 (4U)
#define TMU_TCMCFG_CLK_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_CLK_DIV_SHIFT)) & TMU_TCMCFG_CLK_DIV_MASK)

#define TMU_TCMCFG_SAR_RDY_MASK                  (0x10000U)
#define TMU_TCMCFG_SAR_RDY_SHIFT                 (16U)
#define TMU_TCMCFG_SAR_RDY_WIDTH                 (1U)
#define TMU_TCMCFG_SAR_RDY(x)                    (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_SAR_RDY_SHIFT)) & TMU_TCMCFG_SAR_RDY_MASK)

#define TMU_TCMCFG_RCTC_MASK                     (0x7000000U)
#define TMU_TCMCFG_RCTC_SHIFT                    (24U)
#define TMU_TCMCFG_RCTC_WIDTH                    (3U)
#define TMU_TCMCFG_RCTC(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_RCTC_SHIFT)) & TMU_TCMCFG_RCTC_MASK)

#define TMU_TCMCFG_DEMA_MASK                     (0x10000000U)
#define TMU_TCMCFG_DEMA_SHIFT                    (28U)
#define TMU_TCMCFG_DEMA_WIDTH                    (1U)
#define TMU_TCMCFG_DEMA(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_DEMA_SHIFT)) & TMU_TCMCFG_DEMA_MASK)

#define TMU_TCMCFG_OCS_MASK                      (0x20000000U)
#define TMU_TCMCFG_OCS_SHIFT                     (29U)
#define TMU_TCMCFG_OCS_WIDTH                     (1U)
#define TMU_TCMCFG_OCS(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_OCS_SHIFT)) & TMU_TCMCFG_OCS_MASK)

#define TMU_TCMCFG_OCM_MASK                      (0x40000000U)
#define TMU_TCMCFG_OCM_SHIFT                     (30U)
#define TMU_TCMCFG_OCM_WIDTH                     (1U)
#define TMU_TCMCFG_OCM(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_OCM_SHIFT)) & TMU_TCMCFG_OCM_MASK)

#define TMU_TCMCFG_DPM_MASK                      (0x80000000U)
#define TMU_TCMCFG_DPM_SHIFT                     (31U)
#define TMU_TCMCFG_DPM_WIDTH                     (1U)
#define TMU_TCMCFG_DPM(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TCMCFG_DPM_SHIFT)) & TMU_TCMCFG_DPM_MASK)
/*! @} */

/*! @name TTRCR - Temperature Range Control 0..Temperature Range Control 15 */
/*! @{ */

#define TMU_TTRCR_TEMP_MASK                      (0x1FFU)
#define TMU_TTRCR_TEMP_SHIFT                     (0U)
#define TMU_TTRCR_TEMP_WIDTH                     (9U)
#define TMU_TTRCR_TEMP(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TTRCR_TEMP_SHIFT)) & TMU_TTRCR_TEMP_MASK)

#define TMU_TTRCR_V_MASK                         (0x80000000U)
#define TMU_TTRCR_V_SHIFT                        (31U)
#define TMU_TTRCR_V_WIDTH                        (1U)
#define TMU_TTRCR_V(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TTRCR_V_SHIFT)) & TMU_TTRCR_V_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TMU_Register_Masks */

/*!
 * @}
 */ /* end of group TMU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_TMU_H_) */
