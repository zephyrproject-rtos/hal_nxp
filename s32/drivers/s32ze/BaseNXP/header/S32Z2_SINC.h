/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SINC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SINC
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
#if !defined(S32Z2_SINC_H_)  /* Check if memory map has not been already included */
#define S32Z2_SINC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SINC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SINC_Peripheral_Access_Layer SINC Peripheral Access Layer
 * @{
 */

/** SINC - Size of Registers Arrays */
#define SINC_CHANNEL_COUNT                        4u

/** SINC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAMETER;                         /**< Parameters, offset: 0x4 */
  __IO uint32_t MCR;                               /**< Main Control, offset: 0x8 */
  __IO uint32_t NIE;                               /**< Normal Interrupt Enable, offset: 0xC */
  __IO uint32_t EIE;                               /**< Error Interrupt Enable, offset: 0x10 */
  __IO uint32_t FIFOIE;                            /**< FIFO And CAD Error Interrupt Enable, offset: 0x14 */
  __IO uint32_t NIS;                               /**< Normal Interrupt Status, offset: 0x18 */
  __IO uint32_t EIS;                               /**< Error Interrupt Status, offset: 0x1C */
  __IO uint32_t FIFOIS;                            /**< FIFO And CAD Error Interrupt Status, offset: 0x20 */
  __I  uint32_t SR;                                /**< Status, offset: 0x24 */
  uint8_t RESERVED_0[16];
  struct SINC_CHANNEL {                            /* offset: 0x38, array step: 0x30 */
    __IO uint32_t CCR;                               /**< Channel 0 Control..Channel 3 Control, array offset: 0x38, array step: 0x30 */
    __IO uint32_t CDR;                               /**< Channel 0 Data Rate..Channel 3 Data Rate, array offset: 0x3C, array step: 0x30 */
    __IO uint32_t CCFR;                              /**< Channel 0 Configuration..Channel 3 Configuration, array offset: 0x40, array step: 0x30 */
    __IO uint32_t CPROT;                             /**< Channel 0 Protection..Channel 3 Protection, array offset: 0x44, array step: 0x30 */
    __IO uint32_t CBIAS;                             /**< Channel 0 Bias..Channel 3 Bias, array offset: 0x48, array step: 0x30 */
    __IO uint32_t CLOLMT;                            /**< Channel 0 Low Limit..Channel 3 Low Limit, array offset: 0x4C, array step: 0x30 */
    __IO uint32_t CHILMT;                            /**< Channel 0 High Limit..Channel 3 High Limit, array offset: 0x50, array step: 0x30 */
    __I  uint32_t CRDATA;                            /**< Channel 0 Result Data..Channel 3 Result Data, array offset: 0x54, array step: 0x30 */
    __IO uint32_t CMPDATA;                           /**< Channel 0 Multipurpose Data..Channel 3 Multipurpose Data, array offset: 0x58, array step: 0x30 */
    __IO uint32_t CACFR;                             /**< Channel 0 Advanced Configuration..Channel 3 Advanced Configuration, array offset: 0x5C, array step: 0x30 */
    __IO uint32_t CSR;                               /**< Channel 0 Status..Channel 3 Status, array offset: 0x60, array step: 0x30 */
    __I  uint32_t CDBGR;                             /**< Channel 0 Debug..Channel 3 Debug, array offset: 0x64, array step: 0x30 */
  } CHANNEL[SINC_CHANNEL_COUNT];
} SINC_Type, *SINC_MemMapPtr;

/** Number of instances of the SINC module. */
#define SINC_INSTANCE_COUNT                      (1u)

/* SINC - Peripheral instance base addresses */
/** Peripheral SINC base address */
#define IP_SINC_BASE                             (0x403A0000u)
/** Peripheral SINC base pointer */
#define IP_SINC                                  ((SINC_Type *)IP_SINC_BASE)
/** Array initializer of SINC peripheral base addresses */
#define IP_SINC_BASE_ADDRS                       { IP_SINC_BASE }
/** Array initializer of SINC peripheral base pointers */
#define IP_SINC_BASE_PTRS                        { IP_SINC }

/* ----------------------------------------------------------------------------
   -- SINC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SINC_Register_Masks SINC Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define SINC_VERID_FEATURE_MASK                  (0xFFFFU)
#define SINC_VERID_FEATURE_SHIFT                 (0U)
#define SINC_VERID_FEATURE_WIDTH                 (16U)
#define SINC_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_VERID_FEATURE_SHIFT)) & SINC_VERID_FEATURE_MASK)

#define SINC_VERID_MINOR_MASK                    (0xFF0000U)
#define SINC_VERID_MINOR_SHIFT                   (16U)
#define SINC_VERID_MINOR_WIDTH                   (8U)
#define SINC_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_VERID_MINOR_SHIFT)) & SINC_VERID_MINOR_MASK)

#define SINC_VERID_MAJOR_MASK                    (0xFF000000U)
#define SINC_VERID_MAJOR_SHIFT                   (24U)
#define SINC_VERID_MAJOR_WIDTH                   (8U)
#define SINC_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_VERID_MAJOR_SHIFT)) & SINC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAMETER - Parameters */
/*! @{ */

#define SINC_PARAMETER_FIFO_DEPTH_MASK           (0x1FU)
#define SINC_PARAMETER_FIFO_DEPTH_SHIFT          (0U)
#define SINC_PARAMETER_FIFO_DEPTH_WIDTH          (5U)
#define SINC_PARAMETER_FIFO_DEPTH(x)             (((uint32_t)(((uint32_t)(x)) << SINC_PARAMETER_FIFO_DEPTH_SHIFT)) & SINC_PARAMETER_FIFO_DEPTH_MASK)

#define SINC_PARAMETER_FLT_NUM_MASK              (0xF00U)
#define SINC_PARAMETER_FLT_NUM_SHIFT             (8U)
#define SINC_PARAMETER_FLT_NUM_WIDTH             (4U)
#define SINC_PARAMETER_FLT_NUM(x)                (((uint32_t)(((uint32_t)(x)) << SINC_PARAMETER_FLT_NUM_SHIFT)) & SINC_PARAMETER_FLT_NUM_MASK)

#define SINC_PARAMETER_PF_ORD_SEL_MASK           (0x180000U)
#define SINC_PARAMETER_PF_ORD_SEL_SHIFT          (19U)
#define SINC_PARAMETER_PF_ORD_SEL_WIDTH          (2U)
#define SINC_PARAMETER_PF_ORD_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SINC_PARAMETER_PF_ORD_SEL_SHIFT)) & SINC_PARAMETER_PF_ORD_SEL_MASK)
/*! @} */

/*! @name MCR - Main Control */
/*! @{ */

#define SINC_MCR_STRIG0_MASK                     (0x1U)
#define SINC_MCR_STRIG0_SHIFT                    (0U)
#define SINC_MCR_STRIG0_WIDTH                    (1U)
#define SINC_MCR_STRIG0(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_MCR_STRIG0_SHIFT)) & SINC_MCR_STRIG0_MASK)

#define SINC_MCR_STRIG1_MASK                     (0x2U)
#define SINC_MCR_STRIG1_SHIFT                    (1U)
#define SINC_MCR_STRIG1_WIDTH                    (1U)
#define SINC_MCR_STRIG1(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_MCR_STRIG1_SHIFT)) & SINC_MCR_STRIG1_MASK)

#define SINC_MCR_STRIG2_MASK                     (0x4U)
#define SINC_MCR_STRIG2_SHIFT                    (2U)
#define SINC_MCR_STRIG2_WIDTH                    (1U)
#define SINC_MCR_STRIG2(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_MCR_STRIG2_SHIFT)) & SINC_MCR_STRIG2_MASK)

#define SINC_MCR_STRIG3_MASK                     (0x8U)
#define SINC_MCR_STRIG3_SHIFT                    (3U)
#define SINC_MCR_STRIG3_WIDTH                    (1U)
#define SINC_MCR_STRIG3(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_MCR_STRIG3_SHIFT)) & SINC_MCR_STRIG3_MASK)

#define SINC_MCR_DOZEN_MASK                      (0x400U)
#define SINC_MCR_DOZEN_SHIFT                     (10U)
#define SINC_MCR_DOZEN_WIDTH                     (1U)
#define SINC_MCR_DOZEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_MCR_DOZEN_SHIFT)) & SINC_MCR_DOZEN_MASK)

#define SINC_MCR_RST_MASK                        (0x2000U)
#define SINC_MCR_RST_SHIFT                       (13U)
#define SINC_MCR_RST_WIDTH                       (1U)
#define SINC_MCR_RST(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_MCR_RST_SHIFT)) & SINC_MCR_RST_MASK)

#define SINC_MCR_MEN_MASK                        (0x8000U)
#define SINC_MCR_MEN_SHIFT                       (15U)
#define SINC_MCR_MEN_WIDTH                       (1U)
#define SINC_MCR_MEN(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_MCR_MEN_SHIFT)) & SINC_MCR_MEN_MASK)

#define SINC_MCR_MCLKDIV_MASK                    (0xFF0000U)
#define SINC_MCR_MCLKDIV_SHIFT                   (16U)
#define SINC_MCR_MCLKDIV_WIDTH                   (8U)
#define SINC_MCR_MCLKDIV(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_MCR_MCLKDIV_SHIFT)) & SINC_MCR_MCLKDIV_MASK)

#define SINC_MCR_PRESCALE_MASK                   (0x6000000U)
#define SINC_MCR_PRESCALE_SHIFT                  (25U)
#define SINC_MCR_PRESCALE_WIDTH                  (2U)
#define SINC_MCR_PRESCALE(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_MCR_PRESCALE_SHIFT)) & SINC_MCR_PRESCALE_MASK)

#define SINC_MCR_MCLK0DIS_MASK                   (0x8000000U)
#define SINC_MCR_MCLK0DIS_SHIFT                  (27U)
#define SINC_MCR_MCLK0DIS_WIDTH                  (1U)
#define SINC_MCR_MCLK0DIS(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_MCR_MCLK0DIS_SHIFT)) & SINC_MCR_MCLK0DIS_MASK)

#define SINC_MCR_MCLK1DIS_MASK                   (0x10000000U)
#define SINC_MCR_MCLK1DIS_SHIFT                  (28U)
#define SINC_MCR_MCLK1DIS_WIDTH                  (1U)
#define SINC_MCR_MCLK1DIS(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_MCR_MCLK1DIS_SHIFT)) & SINC_MCR_MCLK1DIS_MASK)

#define SINC_MCR_MCLK2DIS_MASK                   (0x20000000U)
#define SINC_MCR_MCLK2DIS_SHIFT                  (29U)
#define SINC_MCR_MCLK2DIS_WIDTH                  (1U)
#define SINC_MCR_MCLK2DIS(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_MCR_MCLK2DIS_SHIFT)) & SINC_MCR_MCLK2DIS_MASK)
/*! @} */

/*! @name NIE - Normal Interrupt Enable */
/*! @{ */

#define SINC_NIE_COCIE0_MASK                     (0x1U)
#define SINC_NIE_COCIE0_SHIFT                    (0U)
#define SINC_NIE_COCIE0_WIDTH                    (1U)
#define SINC_NIE_COCIE0(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_COCIE0_SHIFT)) & SINC_NIE_COCIE0_MASK)

#define SINC_NIE_COCIE1_MASK                     (0x2U)
#define SINC_NIE_COCIE1_SHIFT                    (1U)
#define SINC_NIE_COCIE1_WIDTH                    (1U)
#define SINC_NIE_COCIE1(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_COCIE1_SHIFT)) & SINC_NIE_COCIE1_MASK)

#define SINC_NIE_COCIE2_MASK                     (0x4U)
#define SINC_NIE_COCIE2_SHIFT                    (2U)
#define SINC_NIE_COCIE2_WIDTH                    (1U)
#define SINC_NIE_COCIE2(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_COCIE2_SHIFT)) & SINC_NIE_COCIE2_MASK)

#define SINC_NIE_COCIE3_MASK                     (0x8U)
#define SINC_NIE_COCIE3_SHIFT                    (3U)
#define SINC_NIE_COCIE3_WIDTH                    (1U)
#define SINC_NIE_COCIE3(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_COCIE3_SHIFT)) & SINC_NIE_COCIE3_MASK)

#define SINC_NIE_CHFIE0_MASK                     (0x100U)
#define SINC_NIE_CHFIE0_SHIFT                    (8U)
#define SINC_NIE_CHFIE0_WIDTH                    (1U)
#define SINC_NIE_CHFIE0(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_CHFIE0_SHIFT)) & SINC_NIE_CHFIE0_MASK)

#define SINC_NIE_CHFIE1_MASK                     (0x200U)
#define SINC_NIE_CHFIE1_SHIFT                    (9U)
#define SINC_NIE_CHFIE1_WIDTH                    (1U)
#define SINC_NIE_CHFIE1(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_CHFIE1_SHIFT)) & SINC_NIE_CHFIE1_MASK)

#define SINC_NIE_CHFIE2_MASK                     (0x400U)
#define SINC_NIE_CHFIE2_SHIFT                    (10U)
#define SINC_NIE_CHFIE2_WIDTH                    (1U)
#define SINC_NIE_CHFIE2(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_CHFIE2_SHIFT)) & SINC_NIE_CHFIE2_MASK)

#define SINC_NIE_CHFIE3_MASK                     (0x800U)
#define SINC_NIE_CHFIE3_SHIFT                    (11U)
#define SINC_NIE_CHFIE3_WIDTH                    (1U)
#define SINC_NIE_CHFIE3(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_CHFIE3_SHIFT)) & SINC_NIE_CHFIE3_MASK)

#define SINC_NIE_ZCDIE0_MASK                     (0x10000U)
#define SINC_NIE_ZCDIE0_SHIFT                    (16U)
#define SINC_NIE_ZCDIE0_WIDTH                    (1U)
#define SINC_NIE_ZCDIE0(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_ZCDIE0_SHIFT)) & SINC_NIE_ZCDIE0_MASK)

#define SINC_NIE_ZCDIE1_MASK                     (0x20000U)
#define SINC_NIE_ZCDIE1_SHIFT                    (17U)
#define SINC_NIE_ZCDIE1_WIDTH                    (1U)
#define SINC_NIE_ZCDIE1(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_ZCDIE1_SHIFT)) & SINC_NIE_ZCDIE1_MASK)

#define SINC_NIE_ZCDIE2_MASK                     (0x40000U)
#define SINC_NIE_ZCDIE2_SHIFT                    (18U)
#define SINC_NIE_ZCDIE2_WIDTH                    (1U)
#define SINC_NIE_ZCDIE2(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_ZCDIE2_SHIFT)) & SINC_NIE_ZCDIE2_MASK)

#define SINC_NIE_ZCDIE3_MASK                     (0x80000U)
#define SINC_NIE_ZCDIE3_SHIFT                    (19U)
#define SINC_NIE_ZCDIE3_WIDTH                    (1U)
#define SINC_NIE_ZCDIE3(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_NIE_ZCDIE3_SHIFT)) & SINC_NIE_ZCDIE3_MASK)
/*! @} */

/*! @name EIE - Error Interrupt Enable */
/*! @{ */

#define SINC_EIE_SCDIE0_MASK                     (0x1U)
#define SINC_EIE_SCDIE0_SHIFT                    (0U)
#define SINC_EIE_SCDIE0_WIDTH                    (1U)
#define SINC_EIE_SCDIE0(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_EIE_SCDIE0_SHIFT)) & SINC_EIE_SCDIE0_MASK)

#define SINC_EIE_SCDIE1_MASK                     (0x2U)
#define SINC_EIE_SCDIE1_SHIFT                    (1U)
#define SINC_EIE_SCDIE1_WIDTH                    (1U)
#define SINC_EIE_SCDIE1(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_EIE_SCDIE1_SHIFT)) & SINC_EIE_SCDIE1_MASK)

#define SINC_EIE_SCDIE2_MASK                     (0x4U)
#define SINC_EIE_SCDIE2_SHIFT                    (2U)
#define SINC_EIE_SCDIE2_WIDTH                    (1U)
#define SINC_EIE_SCDIE2(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_EIE_SCDIE2_SHIFT)) & SINC_EIE_SCDIE2_MASK)

#define SINC_EIE_SCDIE3_MASK                     (0x8U)
#define SINC_EIE_SCDIE3_SHIFT                    (3U)
#define SINC_EIE_SCDIE3_WIDTH                    (1U)
#define SINC_EIE_SCDIE3(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_EIE_SCDIE3_SHIFT)) & SINC_EIE_SCDIE3_MASK)

#define SINC_EIE_WLMTIE0_MASK                    (0x100U)
#define SINC_EIE_WLMTIE0_SHIFT                   (8U)
#define SINC_EIE_WLMTIE0_WIDTH                   (1U)
#define SINC_EIE_WLMTIE0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_WLMTIE0_SHIFT)) & SINC_EIE_WLMTIE0_MASK)

#define SINC_EIE_WLMTIE1_MASK                    (0x200U)
#define SINC_EIE_WLMTIE1_SHIFT                   (9U)
#define SINC_EIE_WLMTIE1_WIDTH                   (1U)
#define SINC_EIE_WLMTIE1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_WLMTIE1_SHIFT)) & SINC_EIE_WLMTIE1_MASK)

#define SINC_EIE_WLMTIE2_MASK                    (0x400U)
#define SINC_EIE_WLMTIE2_SHIFT                   (10U)
#define SINC_EIE_WLMTIE2_WIDTH                   (1U)
#define SINC_EIE_WLMTIE2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_WLMTIE2_SHIFT)) & SINC_EIE_WLMTIE2_MASK)

#define SINC_EIE_WLMTIE3_MASK                    (0x800U)
#define SINC_EIE_WLMTIE3_SHIFT                   (11U)
#define SINC_EIE_WLMTIE3_WIDTH                   (1U)
#define SINC_EIE_WLMTIE3(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_WLMTIE3_SHIFT)) & SINC_EIE_WLMTIE3_MASK)

#define SINC_EIE_LLMTIE0_MASK                    (0x10000U)
#define SINC_EIE_LLMTIE0_SHIFT                   (16U)
#define SINC_EIE_LLMTIE0_WIDTH                   (1U)
#define SINC_EIE_LLMTIE0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_LLMTIE0_SHIFT)) & SINC_EIE_LLMTIE0_MASK)

#define SINC_EIE_LLMTIE1_MASK                    (0x20000U)
#define SINC_EIE_LLMTIE1_SHIFT                   (17U)
#define SINC_EIE_LLMTIE1_WIDTH                   (1U)
#define SINC_EIE_LLMTIE1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_LLMTIE1_SHIFT)) & SINC_EIE_LLMTIE1_MASK)

#define SINC_EIE_LLMTIE2_MASK                    (0x40000U)
#define SINC_EIE_LLMTIE2_SHIFT                   (18U)
#define SINC_EIE_LLMTIE2_WIDTH                   (1U)
#define SINC_EIE_LLMTIE2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_LLMTIE2_SHIFT)) & SINC_EIE_LLMTIE2_MASK)

#define SINC_EIE_LLMTIE3_MASK                    (0x80000U)
#define SINC_EIE_LLMTIE3_SHIFT                   (19U)
#define SINC_EIE_LLMTIE3_WIDTH                   (1U)
#define SINC_EIE_LLMTIE3(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_LLMTIE3_SHIFT)) & SINC_EIE_LLMTIE3_MASK)

#define SINC_EIE_HLMTIE0_MASK                    (0x1000000U)
#define SINC_EIE_HLMTIE0_SHIFT                   (24U)
#define SINC_EIE_HLMTIE0_WIDTH                   (1U)
#define SINC_EIE_HLMTIE0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_HLMTIE0_SHIFT)) & SINC_EIE_HLMTIE0_MASK)

#define SINC_EIE_HLMTIE1_MASK                    (0x2000000U)
#define SINC_EIE_HLMTIE1_SHIFT                   (25U)
#define SINC_EIE_HLMTIE1_WIDTH                   (1U)
#define SINC_EIE_HLMTIE1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_HLMTIE1_SHIFT)) & SINC_EIE_HLMTIE1_MASK)

#define SINC_EIE_HLMTIE2_MASK                    (0x4000000U)
#define SINC_EIE_HLMTIE2_SHIFT                   (26U)
#define SINC_EIE_HLMTIE2_WIDTH                   (1U)
#define SINC_EIE_HLMTIE2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_HLMTIE2_SHIFT)) & SINC_EIE_HLMTIE2_MASK)

#define SINC_EIE_HLMTIE3_MASK                    (0x8000000U)
#define SINC_EIE_HLMTIE3_SHIFT                   (27U)
#define SINC_EIE_HLMTIE3_WIDTH                   (1U)
#define SINC_EIE_HLMTIE3(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_EIE_HLMTIE3_SHIFT)) & SINC_EIE_HLMTIE3_MASK)
/*! @} */

/*! @name FIFOIE - FIFO And CAD Error Interrupt Enable */
/*! @{ */

#define SINC_FIFOIE_FUNFIE0_MASK                 (0x1U)
#define SINC_FIFOIE_FUNFIE0_SHIFT                (0U)
#define SINC_FIFOIE_FUNFIE0_WIDTH                (1U)
#define SINC_FIFOIE_FUNFIE0(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FUNFIE0_SHIFT)) & SINC_FIFOIE_FUNFIE0_MASK)

#define SINC_FIFOIE_FUNFIE1_MASK                 (0x2U)
#define SINC_FIFOIE_FUNFIE1_SHIFT                (1U)
#define SINC_FIFOIE_FUNFIE1_WIDTH                (1U)
#define SINC_FIFOIE_FUNFIE1(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FUNFIE1_SHIFT)) & SINC_FIFOIE_FUNFIE1_MASK)

#define SINC_FIFOIE_FUNFIE2_MASK                 (0x4U)
#define SINC_FIFOIE_FUNFIE2_SHIFT                (2U)
#define SINC_FIFOIE_FUNFIE2_WIDTH                (1U)
#define SINC_FIFOIE_FUNFIE2(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FUNFIE2_SHIFT)) & SINC_FIFOIE_FUNFIE2_MASK)

#define SINC_FIFOIE_FUNFIE3_MASK                 (0x8U)
#define SINC_FIFOIE_FUNFIE3_SHIFT                (3U)
#define SINC_FIFOIE_FUNFIE3_WIDTH                (1U)
#define SINC_FIFOIE_FUNFIE3(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FUNFIE3_SHIFT)) & SINC_FIFOIE_FUNFIE3_MASK)

#define SINC_FIFOIE_FOVFIE0_MASK                 (0x100U)
#define SINC_FIFOIE_FOVFIE0_SHIFT                (8U)
#define SINC_FIFOIE_FOVFIE0_WIDTH                (1U)
#define SINC_FIFOIE_FOVFIE0(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FOVFIE0_SHIFT)) & SINC_FIFOIE_FOVFIE0_MASK)

#define SINC_FIFOIE_FOVFIE1_MASK                 (0x200U)
#define SINC_FIFOIE_FOVFIE1_SHIFT                (9U)
#define SINC_FIFOIE_FOVFIE1_WIDTH                (1U)
#define SINC_FIFOIE_FOVFIE1(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FOVFIE1_SHIFT)) & SINC_FIFOIE_FOVFIE1_MASK)

#define SINC_FIFOIE_FOVFIE2_MASK                 (0x400U)
#define SINC_FIFOIE_FOVFIE2_SHIFT                (10U)
#define SINC_FIFOIE_FOVFIE2_WIDTH                (1U)
#define SINC_FIFOIE_FOVFIE2(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FOVFIE2_SHIFT)) & SINC_FIFOIE_FOVFIE2_MASK)

#define SINC_FIFOIE_FOVFIE3_MASK                 (0x800U)
#define SINC_FIFOIE_FOVFIE3_SHIFT                (11U)
#define SINC_FIFOIE_FOVFIE3_WIDTH                (1U)
#define SINC_FIFOIE_FOVFIE3(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_FOVFIE3_SHIFT)) & SINC_FIFOIE_FOVFIE3_MASK)

#define SINC_FIFOIE_CADIE0_MASK                  (0x10000U)
#define SINC_FIFOIE_CADIE0_SHIFT                 (16U)
#define SINC_FIFOIE_CADIE0_WIDTH                 (1U)
#define SINC_FIFOIE_CADIE0(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_CADIE0_SHIFT)) & SINC_FIFOIE_CADIE0_MASK)

#define SINC_FIFOIE_CADIE1_MASK                  (0x20000U)
#define SINC_FIFOIE_CADIE1_SHIFT                 (17U)
#define SINC_FIFOIE_CADIE1_WIDTH                 (1U)
#define SINC_FIFOIE_CADIE1(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_CADIE1_SHIFT)) & SINC_FIFOIE_CADIE1_MASK)

#define SINC_FIFOIE_CADIE2_MASK                  (0x40000U)
#define SINC_FIFOIE_CADIE2_SHIFT                 (18U)
#define SINC_FIFOIE_CADIE2_WIDTH                 (1U)
#define SINC_FIFOIE_CADIE2(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_CADIE2_SHIFT)) & SINC_FIFOIE_CADIE2_MASK)

#define SINC_FIFOIE_CADIE3_MASK                  (0x80000U)
#define SINC_FIFOIE_CADIE3_SHIFT                 (19U)
#define SINC_FIFOIE_CADIE3_WIDTH                 (1U)
#define SINC_FIFOIE_CADIE3(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_CADIE3_SHIFT)) & SINC_FIFOIE_CADIE3_MASK)

#define SINC_FIFOIE_SATIE0_MASK                  (0x1000000U)
#define SINC_FIFOIE_SATIE0_SHIFT                 (24U)
#define SINC_FIFOIE_SATIE0_WIDTH                 (1U)
#define SINC_FIFOIE_SATIE0(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_SATIE0_SHIFT)) & SINC_FIFOIE_SATIE0_MASK)

#define SINC_FIFOIE_SATIE1_MASK                  (0x2000000U)
#define SINC_FIFOIE_SATIE1_SHIFT                 (25U)
#define SINC_FIFOIE_SATIE1_WIDTH                 (1U)
#define SINC_FIFOIE_SATIE1(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_SATIE1_SHIFT)) & SINC_FIFOIE_SATIE1_MASK)

#define SINC_FIFOIE_SATIE2_MASK                  (0x4000000U)
#define SINC_FIFOIE_SATIE2_SHIFT                 (26U)
#define SINC_FIFOIE_SATIE2_WIDTH                 (1U)
#define SINC_FIFOIE_SATIE2(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_SATIE2_SHIFT)) & SINC_FIFOIE_SATIE2_MASK)

#define SINC_FIFOIE_SATIE3_MASK                  (0x8000000U)
#define SINC_FIFOIE_SATIE3_SHIFT                 (27U)
#define SINC_FIFOIE_SATIE3_WIDTH                 (1U)
#define SINC_FIFOIE_SATIE3(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIE_SATIE3_SHIFT)) & SINC_FIFOIE_SATIE3_MASK)
/*! @} */

/*! @name NIS - Normal Interrupt Status */
/*! @{ */

#define SINC_NIS_COC0_MASK                       (0x1U)
#define SINC_NIS_COC0_SHIFT                      (0U)
#define SINC_NIS_COC0_WIDTH                      (1U)
#define SINC_NIS_COC0(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_COC0_SHIFT)) & SINC_NIS_COC0_MASK)

#define SINC_NIS_COC1_MASK                       (0x2U)
#define SINC_NIS_COC1_SHIFT                      (1U)
#define SINC_NIS_COC1_WIDTH                      (1U)
#define SINC_NIS_COC1(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_COC1_SHIFT)) & SINC_NIS_COC1_MASK)

#define SINC_NIS_COC2_MASK                       (0x4U)
#define SINC_NIS_COC2_SHIFT                      (2U)
#define SINC_NIS_COC2_WIDTH                      (1U)
#define SINC_NIS_COC2(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_COC2_SHIFT)) & SINC_NIS_COC2_MASK)

#define SINC_NIS_COC3_MASK                       (0x8U)
#define SINC_NIS_COC3_SHIFT                      (3U)
#define SINC_NIS_COC3_WIDTH                      (1U)
#define SINC_NIS_COC3(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_COC3_SHIFT)) & SINC_NIS_COC3_MASK)

#define SINC_NIS_CHF0_MASK                       (0x100U)
#define SINC_NIS_CHF0_SHIFT                      (8U)
#define SINC_NIS_CHF0_WIDTH                      (1U)
#define SINC_NIS_CHF0(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_CHF0_SHIFT)) & SINC_NIS_CHF0_MASK)

#define SINC_NIS_CHF1_MASK                       (0x200U)
#define SINC_NIS_CHF1_SHIFT                      (9U)
#define SINC_NIS_CHF1_WIDTH                      (1U)
#define SINC_NIS_CHF1(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_CHF1_SHIFT)) & SINC_NIS_CHF1_MASK)

#define SINC_NIS_CHF2_MASK                       (0x400U)
#define SINC_NIS_CHF2_SHIFT                      (10U)
#define SINC_NIS_CHF2_WIDTH                      (1U)
#define SINC_NIS_CHF2(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_CHF2_SHIFT)) & SINC_NIS_CHF2_MASK)

#define SINC_NIS_CHF3_MASK                       (0x800U)
#define SINC_NIS_CHF3_SHIFT                      (11U)
#define SINC_NIS_CHF3_WIDTH                      (1U)
#define SINC_NIS_CHF3(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_CHF3_SHIFT)) & SINC_NIS_CHF3_MASK)

#define SINC_NIS_ZCD0_MASK                       (0x10000U)
#define SINC_NIS_ZCD0_SHIFT                      (16U)
#define SINC_NIS_ZCD0_WIDTH                      (1U)
#define SINC_NIS_ZCD0(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_ZCD0_SHIFT)) & SINC_NIS_ZCD0_MASK)

#define SINC_NIS_ZCD1_MASK                       (0x20000U)
#define SINC_NIS_ZCD1_SHIFT                      (17U)
#define SINC_NIS_ZCD1_WIDTH                      (1U)
#define SINC_NIS_ZCD1(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_ZCD1_SHIFT)) & SINC_NIS_ZCD1_MASK)

#define SINC_NIS_ZCD2_MASK                       (0x40000U)
#define SINC_NIS_ZCD2_SHIFT                      (18U)
#define SINC_NIS_ZCD2_WIDTH                      (1U)
#define SINC_NIS_ZCD2(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_ZCD2_SHIFT)) & SINC_NIS_ZCD2_MASK)

#define SINC_NIS_ZCD3_MASK                       (0x80000U)
#define SINC_NIS_ZCD3_SHIFT                      (19U)
#define SINC_NIS_ZCD3_WIDTH                      (1U)
#define SINC_NIS_ZCD3(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_NIS_ZCD3_SHIFT)) & SINC_NIS_ZCD3_MASK)
/*! @} */

/*! @name EIS - Error Interrupt Status */
/*! @{ */

#define SINC_EIS_SCD0_MASK                       (0x1U)
#define SINC_EIS_SCD0_SHIFT                      (0U)
#define SINC_EIS_SCD0_WIDTH                      (1U)
#define SINC_EIS_SCD0(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_EIS_SCD0_SHIFT)) & SINC_EIS_SCD0_MASK)

#define SINC_EIS_SCD1_MASK                       (0x2U)
#define SINC_EIS_SCD1_SHIFT                      (1U)
#define SINC_EIS_SCD1_WIDTH                      (1U)
#define SINC_EIS_SCD1(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_EIS_SCD1_SHIFT)) & SINC_EIS_SCD1_MASK)

#define SINC_EIS_SCD2_MASK                       (0x4U)
#define SINC_EIS_SCD2_SHIFT                      (2U)
#define SINC_EIS_SCD2_WIDTH                      (1U)
#define SINC_EIS_SCD2(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_EIS_SCD2_SHIFT)) & SINC_EIS_SCD2_MASK)

#define SINC_EIS_SCD3_MASK                       (0x8U)
#define SINC_EIS_SCD3_SHIFT                      (3U)
#define SINC_EIS_SCD3_WIDTH                      (1U)
#define SINC_EIS_SCD3(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_EIS_SCD3_SHIFT)) & SINC_EIS_SCD3_MASK)

#define SINC_EIS_WLMT0_MASK                      (0x100U)
#define SINC_EIS_WLMT0_SHIFT                     (8U)
#define SINC_EIS_WLMT0_WIDTH                     (1U)
#define SINC_EIS_WLMT0(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_WLMT0_SHIFT)) & SINC_EIS_WLMT0_MASK)

#define SINC_EIS_WLMT1_MASK                      (0x200U)
#define SINC_EIS_WLMT1_SHIFT                     (9U)
#define SINC_EIS_WLMT1_WIDTH                     (1U)
#define SINC_EIS_WLMT1(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_WLMT1_SHIFT)) & SINC_EIS_WLMT1_MASK)

#define SINC_EIS_WLMT2_MASK                      (0x400U)
#define SINC_EIS_WLMT2_SHIFT                     (10U)
#define SINC_EIS_WLMT2_WIDTH                     (1U)
#define SINC_EIS_WLMT2(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_WLMT2_SHIFT)) & SINC_EIS_WLMT2_MASK)

#define SINC_EIS_WLMT3_MASK                      (0x800U)
#define SINC_EIS_WLMT3_SHIFT                     (11U)
#define SINC_EIS_WLMT3_WIDTH                     (1U)
#define SINC_EIS_WLMT3(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_WLMT3_SHIFT)) & SINC_EIS_WLMT3_MASK)

#define SINC_EIS_LLMT0_MASK                      (0x10000U)
#define SINC_EIS_LLMT0_SHIFT                     (16U)
#define SINC_EIS_LLMT0_WIDTH                     (1U)
#define SINC_EIS_LLMT0(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_LLMT0_SHIFT)) & SINC_EIS_LLMT0_MASK)

#define SINC_EIS_LLMT1_MASK                      (0x20000U)
#define SINC_EIS_LLMT1_SHIFT                     (17U)
#define SINC_EIS_LLMT1_WIDTH                     (1U)
#define SINC_EIS_LLMT1(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_LLMT1_SHIFT)) & SINC_EIS_LLMT1_MASK)

#define SINC_EIS_LLMT2_MASK                      (0x40000U)
#define SINC_EIS_LLMT2_SHIFT                     (18U)
#define SINC_EIS_LLMT2_WIDTH                     (1U)
#define SINC_EIS_LLMT2(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_LLMT2_SHIFT)) & SINC_EIS_LLMT2_MASK)

#define SINC_EIS_LLMT3_MASK                      (0x80000U)
#define SINC_EIS_LLMT3_SHIFT                     (19U)
#define SINC_EIS_LLMT3_WIDTH                     (1U)
#define SINC_EIS_LLMT3(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_LLMT3_SHIFT)) & SINC_EIS_LLMT3_MASK)

#define SINC_EIS_HLMT0_MASK                      (0x1000000U)
#define SINC_EIS_HLMT0_SHIFT                     (24U)
#define SINC_EIS_HLMT0_WIDTH                     (1U)
#define SINC_EIS_HLMT0(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_HLMT0_SHIFT)) & SINC_EIS_HLMT0_MASK)

#define SINC_EIS_HLMT1_MASK                      (0x2000000U)
#define SINC_EIS_HLMT1_SHIFT                     (25U)
#define SINC_EIS_HLMT1_WIDTH                     (1U)
#define SINC_EIS_HLMT1(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_HLMT1_SHIFT)) & SINC_EIS_HLMT1_MASK)

#define SINC_EIS_HLMT2_MASK                      (0x4000000U)
#define SINC_EIS_HLMT2_SHIFT                     (26U)
#define SINC_EIS_HLMT2_WIDTH                     (1U)
#define SINC_EIS_HLMT2(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_HLMT2_SHIFT)) & SINC_EIS_HLMT2_MASK)

#define SINC_EIS_HLMT3_MASK                      (0x8000000U)
#define SINC_EIS_HLMT3_SHIFT                     (27U)
#define SINC_EIS_HLMT3_WIDTH                     (1U)
#define SINC_EIS_HLMT3(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_EIS_HLMT3_SHIFT)) & SINC_EIS_HLMT3_MASK)
/*! @} */

/*! @name FIFOIS - FIFO And CAD Error Interrupt Status */
/*! @{ */

#define SINC_FIFOIS_FUNF0_MASK                   (0x1U)
#define SINC_FIFOIS_FUNF0_SHIFT                  (0U)
#define SINC_FIFOIS_FUNF0_WIDTH                  (1U)
#define SINC_FIFOIS_FUNF0(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FUNF0_SHIFT)) & SINC_FIFOIS_FUNF0_MASK)

#define SINC_FIFOIS_FUNF1_MASK                   (0x2U)
#define SINC_FIFOIS_FUNF1_SHIFT                  (1U)
#define SINC_FIFOIS_FUNF1_WIDTH                  (1U)
#define SINC_FIFOIS_FUNF1(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FUNF1_SHIFT)) & SINC_FIFOIS_FUNF1_MASK)

#define SINC_FIFOIS_FUNF2_MASK                   (0x4U)
#define SINC_FIFOIS_FUNF2_SHIFT                  (2U)
#define SINC_FIFOIS_FUNF2_WIDTH                  (1U)
#define SINC_FIFOIS_FUNF2(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FUNF2_SHIFT)) & SINC_FIFOIS_FUNF2_MASK)

#define SINC_FIFOIS_FUNF3_MASK                   (0x8U)
#define SINC_FIFOIS_FUNF3_SHIFT                  (3U)
#define SINC_FIFOIS_FUNF3_WIDTH                  (1U)
#define SINC_FIFOIS_FUNF3(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FUNF3_SHIFT)) & SINC_FIFOIS_FUNF3_MASK)

#define SINC_FIFOIS_FOVF0_MASK                   (0x100U)
#define SINC_FIFOIS_FOVF0_SHIFT                  (8U)
#define SINC_FIFOIS_FOVF0_WIDTH                  (1U)
#define SINC_FIFOIS_FOVF0(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FOVF0_SHIFT)) & SINC_FIFOIS_FOVF0_MASK)

#define SINC_FIFOIS_FOVF1_MASK                   (0x200U)
#define SINC_FIFOIS_FOVF1_SHIFT                  (9U)
#define SINC_FIFOIS_FOVF1_WIDTH                  (1U)
#define SINC_FIFOIS_FOVF1(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FOVF1_SHIFT)) & SINC_FIFOIS_FOVF1_MASK)

#define SINC_FIFOIS_FOVF2_MASK                   (0x400U)
#define SINC_FIFOIS_FOVF2_SHIFT                  (10U)
#define SINC_FIFOIS_FOVF2_WIDTH                  (1U)
#define SINC_FIFOIS_FOVF2(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FOVF2_SHIFT)) & SINC_FIFOIS_FOVF2_MASK)

#define SINC_FIFOIS_FOVF3_MASK                   (0x800U)
#define SINC_FIFOIS_FOVF3_SHIFT                  (11U)
#define SINC_FIFOIS_FOVF3_WIDTH                  (1U)
#define SINC_FIFOIS_FOVF3(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_FOVF3_SHIFT)) & SINC_FIFOIS_FOVF3_MASK)

#define SINC_FIFOIS_CAD0_MASK                    (0x10000U)
#define SINC_FIFOIS_CAD0_SHIFT                   (16U)
#define SINC_FIFOIS_CAD0_WIDTH                   (1U)
#define SINC_FIFOIS_CAD0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_CAD0_SHIFT)) & SINC_FIFOIS_CAD0_MASK)

#define SINC_FIFOIS_CAD1_MASK                    (0x20000U)
#define SINC_FIFOIS_CAD1_SHIFT                   (17U)
#define SINC_FIFOIS_CAD1_WIDTH                   (1U)
#define SINC_FIFOIS_CAD1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_CAD1_SHIFT)) & SINC_FIFOIS_CAD1_MASK)

#define SINC_FIFOIS_CAD2_MASK                    (0x40000U)
#define SINC_FIFOIS_CAD2_SHIFT                   (18U)
#define SINC_FIFOIS_CAD2_WIDTH                   (1U)
#define SINC_FIFOIS_CAD2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_CAD2_SHIFT)) & SINC_FIFOIS_CAD2_MASK)

#define SINC_FIFOIS_CAD3_MASK                    (0x80000U)
#define SINC_FIFOIS_CAD3_SHIFT                   (19U)
#define SINC_FIFOIS_CAD3_WIDTH                   (1U)
#define SINC_FIFOIS_CAD3(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_CAD3_SHIFT)) & SINC_FIFOIS_CAD3_MASK)

#define SINC_FIFOIS_SAT0_MASK                    (0x1000000U)
#define SINC_FIFOIS_SAT0_SHIFT                   (24U)
#define SINC_FIFOIS_SAT0_WIDTH                   (1U)
#define SINC_FIFOIS_SAT0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_SAT0_SHIFT)) & SINC_FIFOIS_SAT0_MASK)

#define SINC_FIFOIS_SAT1_MASK                    (0x2000000U)
#define SINC_FIFOIS_SAT1_SHIFT                   (25U)
#define SINC_FIFOIS_SAT1_WIDTH                   (1U)
#define SINC_FIFOIS_SAT1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_SAT1_SHIFT)) & SINC_FIFOIS_SAT1_MASK)

#define SINC_FIFOIS_SAT2_MASK                    (0x4000000U)
#define SINC_FIFOIS_SAT2_SHIFT                   (26U)
#define SINC_FIFOIS_SAT2_WIDTH                   (1U)
#define SINC_FIFOIS_SAT2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_SAT2_SHIFT)) & SINC_FIFOIS_SAT2_MASK)

#define SINC_FIFOIS_SAT3_MASK                    (0x8000000U)
#define SINC_FIFOIS_SAT3_SHIFT                   (27U)
#define SINC_FIFOIS_SAT3_WIDTH                   (1U)
#define SINC_FIFOIS_SAT3(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_FIFOIS_SAT3_SHIFT)) & SINC_FIFOIS_SAT3_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define SINC_SR_CIP0_MASK                        (0x1U)
#define SINC_SR_CIP0_SHIFT                       (0U)
#define SINC_SR_CIP0_WIDTH                       (1U)
#define SINC_SR_CIP0(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_SR_CIP0_SHIFT)) & SINC_SR_CIP0_MASK)

#define SINC_SR_CIP1_MASK                        (0x2U)
#define SINC_SR_CIP1_SHIFT                       (1U)
#define SINC_SR_CIP1_WIDTH                       (1U)
#define SINC_SR_CIP1(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_SR_CIP1_SHIFT)) & SINC_SR_CIP1_MASK)

#define SINC_SR_CIP2_MASK                        (0x4U)
#define SINC_SR_CIP2_SHIFT                       (2U)
#define SINC_SR_CIP2_WIDTH                       (1U)
#define SINC_SR_CIP2(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_SR_CIP2_SHIFT)) & SINC_SR_CIP2_MASK)

#define SINC_SR_CIP3_MASK                        (0x8U)
#define SINC_SR_CIP3_SHIFT                       (3U)
#define SINC_SR_CIP3_WIDTH                       (1U)
#define SINC_SR_CIP3(x)                          (((uint32_t)(((uint32_t)(x)) << SINC_SR_CIP3_SHIFT)) & SINC_SR_CIP3_MASK)

#define SINC_SR_CHRDY0_MASK                      (0x100U)
#define SINC_SR_CHRDY0_SHIFT                     (8U)
#define SINC_SR_CHRDY0_WIDTH                     (1U)
#define SINC_SR_CHRDY0(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_SR_CHRDY0_SHIFT)) & SINC_SR_CHRDY0_MASK)

#define SINC_SR_CHRDY1_MASK                      (0x200U)
#define SINC_SR_CHRDY1_SHIFT                     (9U)
#define SINC_SR_CHRDY1_WIDTH                     (1U)
#define SINC_SR_CHRDY1(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_SR_CHRDY1_SHIFT)) & SINC_SR_CHRDY1_MASK)

#define SINC_SR_CHRDY2_MASK                      (0x400U)
#define SINC_SR_CHRDY2_SHIFT                     (10U)
#define SINC_SR_CHRDY2_WIDTH                     (1U)
#define SINC_SR_CHRDY2(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_SR_CHRDY2_SHIFT)) & SINC_SR_CHRDY2_MASK)

#define SINC_SR_CHRDY3_MASK                      (0x800U)
#define SINC_SR_CHRDY3_SHIFT                     (11U)
#define SINC_SR_CHRDY3_WIDTH                     (1U)
#define SINC_SR_CHRDY3(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_SR_CHRDY3_SHIFT)) & SINC_SR_CHRDY3_MASK)

#define SINC_SR_FIFOEMPTY0_MASK                  (0x10000U)
#define SINC_SR_FIFOEMPTY0_SHIFT                 (16U)
#define SINC_SR_FIFOEMPTY0_WIDTH                 (1U)
#define SINC_SR_FIFOEMPTY0(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_SR_FIFOEMPTY0_SHIFT)) & SINC_SR_FIFOEMPTY0_MASK)

#define SINC_SR_FIFOEMPTY1_MASK                  (0x20000U)
#define SINC_SR_FIFOEMPTY1_SHIFT                 (17U)
#define SINC_SR_FIFOEMPTY1_WIDTH                 (1U)
#define SINC_SR_FIFOEMPTY1(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_SR_FIFOEMPTY1_SHIFT)) & SINC_SR_FIFOEMPTY1_MASK)

#define SINC_SR_FIFOEMPTY2_MASK                  (0x40000U)
#define SINC_SR_FIFOEMPTY2_SHIFT                 (18U)
#define SINC_SR_FIFOEMPTY2_WIDTH                 (1U)
#define SINC_SR_FIFOEMPTY2(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_SR_FIFOEMPTY2_SHIFT)) & SINC_SR_FIFOEMPTY2_MASK)

#define SINC_SR_FIFOEMPTY3_MASK                  (0x80000U)
#define SINC_SR_FIFOEMPTY3_SHIFT                 (19U)
#define SINC_SR_FIFOEMPTY3_WIDTH                 (1U)
#define SINC_SR_FIFOEMPTY3(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_SR_FIFOEMPTY3_SHIFT)) & SINC_SR_FIFOEMPTY3_MASK)

#define SINC_SR_MCLKRDY0_MASK                    (0x1000000U)
#define SINC_SR_MCLKRDY0_SHIFT                   (24U)
#define SINC_SR_MCLKRDY0_WIDTH                   (1U)
#define SINC_SR_MCLKRDY0(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_SR_MCLKRDY0_SHIFT)) & SINC_SR_MCLKRDY0_MASK)

#define SINC_SR_MCLKRDY1_MASK                    (0x2000000U)
#define SINC_SR_MCLKRDY1_SHIFT                   (25U)
#define SINC_SR_MCLKRDY1_WIDTH                   (1U)
#define SINC_SR_MCLKRDY1(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_SR_MCLKRDY1_SHIFT)) & SINC_SR_MCLKRDY1_MASK)

#define SINC_SR_MCLKRDY2_MASK                    (0x4000000U)
#define SINC_SR_MCLKRDY2_SHIFT                   (26U)
#define SINC_SR_MCLKRDY2_WIDTH                   (1U)
#define SINC_SR_MCLKRDY2(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_SR_MCLKRDY2_SHIFT)) & SINC_SR_MCLKRDY2_MASK)
/*! @} */

/*! @name CCR - Channel 0 Control..Channel 3 Control */
/*! @{ */

#define SINC_CCR_CHEN_MASK                       (0x1U)
#define SINC_CCR_CHEN_SHIFT                      (0U)
#define SINC_CCR_CHEN_WIDTH                      (1U)
#define SINC_CCR_CHEN(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CCR_CHEN_SHIFT)) & SINC_CCR_CHEN_MASK)

#define SINC_CCR_PFEN_MASK                       (0x2U)
#define SINC_CCR_PFEN_SHIFT                      (1U)
#define SINC_CCR_PFEN_WIDTH                      (1U)
#define SINC_CCR_PFEN(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CCR_PFEN_SHIFT)) & SINC_CCR_PFEN_MASK)

#define SINC_CCR_DMAEN_MASK                      (0x8U)
#define SINC_CCR_DMAEN_SHIFT                     (3U)
#define SINC_CCR_DMAEN_WIDTH                     (1U)
#define SINC_CCR_DMAEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCR_DMAEN_SHIFT)) & SINC_CCR_DMAEN_MASK)

#define SINC_CCR_SCDEN_MASK                      (0x100U)
#define SINC_CCR_SCDEN_SHIFT                     (8U)
#define SINC_CCR_SCDEN_WIDTH                     (1U)
#define SINC_CCR_SCDEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCR_SCDEN_SHIFT)) & SINC_CCR_SCDEN_MASK)

#define SINC_CCR_CADEN_MASK                      (0x200U)
#define SINC_CCR_CADEN_SHIFT                     (9U)
#define SINC_CCR_CADEN_WIDTH                     (1U)
#define SINC_CCR_CADEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCR_CADEN_SHIFT)) & SINC_CCR_CADEN_MASK)

#define SINC_CCR_ZCDEN_MASK                      (0x1000U)
#define SINC_CCR_ZCDEN_SHIFT                     (12U)
#define SINC_CCR_ZCDEN_WIDTH                     (1U)
#define SINC_CCR_ZCDEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCR_ZCDEN_SHIFT)) & SINC_CCR_ZCDEN_MASK)

#define SINC_CCR_LMTEN_MASK                      (0x2000U)
#define SINC_CCR_LMTEN_SHIFT                     (13U)
#define SINC_CCR_LMTEN_WIDTH                     (1U)
#define SINC_CCR_LMTEN(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCR_LMTEN_SHIFT)) & SINC_CCR_LMTEN_MASK)

#define SINC_CCR_FIFOEN_MASK                     (0x4000U)
#define SINC_CCR_FIFOEN_SHIFT                    (14U)
#define SINC_CCR_FIFOEN_WIDTH                    (1U)
#define SINC_CCR_FIFOEN(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCR_FIFOEN_SHIFT)) & SINC_CCR_FIFOEN_MASK)

#define SINC_CCR_DBGSEL_MASK                     (0xF00000U)
#define SINC_CCR_DBGSEL_SHIFT                    (20U)
#define SINC_CCR_DBGSEL_WIDTH                    (4U)
#define SINC_CCR_DBGSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCR_DBGSEL_SHIFT)) & SINC_CCR_DBGSEL_MASK)
/*! @} */

/*! @name CDR - Channel 0 Data Rate..Channel 3 Data Rate */
/*! @{ */

#define SINC_CDR_PFOSR_MASK                      (0x7FFU)
#define SINC_CDR_PFOSR_SHIFT                     (0U)
#define SINC_CDR_PFOSR_WIDTH                     (11U)
#define SINC_CDR_PFOSR(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CDR_PFOSR_SHIFT)) & SINC_CDR_PFOSR_MASK)

#define SINC_CDR_PFORD_MASK                      (0x1800U)
#define SINC_CDR_PFORD_SHIFT                     (11U)
#define SINC_CDR_PFORD_WIDTH                     (2U)
#define SINC_CDR_PFORD(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CDR_PFORD_SHIFT)) & SINC_CDR_PFORD_MASK)

#define SINC_CDR_PFCM_MASK                       (0xC000U)
#define SINC_CDR_PFCM_SHIFT                      (14U)
#define SINC_CDR_PFCM_WIDTH                      (2U)
#define SINC_CDR_PFCM(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CDR_PFCM_SHIFT)) & SINC_CDR_PFCM_MASK)
/*! @} */

/*! @name CCFR - Channel 0 Configuration..Channel 3 Configuration */
/*! @{ */

#define SINC_CCFR_PFSFT_MASK                     (0x1FU)
#define SINC_CCFR_PFSFT_SHIFT                    (0U)
#define SINC_CCFR_PFSFT_WIDTH                    (5U)
#define SINC_CCFR_PFSFT(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_PFSFT_SHIFT)) & SINC_CCFR_PFSFT_MASK)

#define SINC_CCFR_RDFMT_MASK                     (0x40U)
#define SINC_CCFR_RDFMT_SHIFT                    (6U)
#define SINC_CCFR_RDFMT_WIDTH                    (1U)
#define SINC_CCFR_RDFMT(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_RDFMT_SHIFT)) & SINC_CCFR_RDFMT_MASK)

#define SINC_CCFR_FIFOWMK_MASK                   (0x3C00U)
#define SINC_CCFR_FIFOWMK_SHIFT                  (10U)
#define SINC_CCFR_FIFOWMK_WIDTH                  (4U)
#define SINC_CCFR_FIFOWMK(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_FIFOWMK_SHIFT)) & SINC_CCFR_FIFOWMK_MASK)

#define SINC_CCFR_IBFMT_MASK                     (0x30000U)
#define SINC_CCFR_IBFMT_SHIFT                    (16U)
#define SINC_CCFR_IBFMT_WIDTH                    (2U)
#define SINC_CCFR_IBFMT(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_IBFMT_SHIFT)) & SINC_CCFR_IBFMT_MASK)

#define SINC_CCFR_ICSEL_MASK                     (0x1C0000U)
#define SINC_CCFR_ICSEL_SHIFT                    (18U)
#define SINC_CCFR_ICSEL_WIDTH                    (3U)
#define SINC_CCFR_ICSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_ICSEL_SHIFT)) & SINC_CCFR_ICSEL_MASK)

#define SINC_CCFR_ICESEL_MASK                    (0xE00000U)
#define SINC_CCFR_ICESEL_SHIFT                   (21U)
#define SINC_CCFR_ICESEL_WIDTH                   (3U)
#define SINC_CCFR_ICESEL(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_ICESEL_SHIFT)) & SINC_CCFR_ICESEL_MASK)

#define SINC_CCFR_ITSEL_MASK                     (0x3000000U)
#define SINC_CCFR_ITSEL_SHIFT                    (24U)
#define SINC_CCFR_ITSEL_WIDTH                    (2U)
#define SINC_CCFR_ITSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_ITSEL_SHIFT)) & SINC_CCFR_ITSEL_MASK)

#define SINC_CCFR_IBSEL_MASK                     (0xC000000U)
#define SINC_CCFR_IBSEL_SHIFT                    (26U)
#define SINC_CCFR_IBSEL_WIDTH                    (2U)
#define SINC_CCFR_IBSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_IBSEL_SHIFT)) & SINC_CCFR_IBSEL_MASK)

#define SINC_CCFR_ITLVL_MASK                     (0x10000000U)
#define SINC_CCFR_ITLVL_SHIFT                    (28U)
#define SINC_CCFR_ITLVL_WIDTH                    (1U)
#define SINC_CCFR_ITLVL(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_ITLVL_SHIFT)) & SINC_CCFR_ITLVL_MASK)

#define SINC_CCFR_ZCOP_MASK                      (0xC0000000U)
#define SINC_CCFR_ZCOP_SHIFT                     (30U)
#define SINC_CCFR_ZCOP_WIDTH                     (2U)
#define SINC_CCFR_ZCOP(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CCFR_ZCOP_SHIFT)) & SINC_CCFR_ZCOP_MASK)
/*! @} */

/*! @name CPROT - Channel 0 Protection..Channel 3 Protection */
/*! @{ */

#define SINC_CPROT_SCDLMT_MASK                   (0xFFU)
#define SINC_CPROT_SCDLMT_SHIFT                  (0U)
#define SINC_CPROT_SCDLMT_WIDTH                  (8U)
#define SINC_CPROT_SCDLMT(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_SCDLMT_SHIFT)) & SINC_CPROT_SCDLMT_MASK)

#define SINC_CPROT_SCDCM_MASK                    (0x800U)
#define SINC_CPROT_SCDCM_SHIFT                   (11U)
#define SINC_CPROT_SCDCM_WIDTH                   (1U)
#define SINC_CPROT_SCDCM(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_SCDCM_SHIFT)) & SINC_CPROT_SCDCM_MASK)

#define SINC_CPROT_SCDOP_MASK                    (0x3000U)
#define SINC_CPROT_SCDOP_SHIFT                   (12U)
#define SINC_CPROT_SCDOP_WIDTH                   (2U)
#define SINC_CPROT_SCDOP(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_SCDOP_SHIFT)) & SINC_CPROT_SCDOP_MASK)

#define SINC_CPROT_LMTOP_MASK                    (0xC000U)
#define SINC_CPROT_LMTOP_SHIFT                   (14U)
#define SINC_CPROT_LMTOP_WIDTH                   (2U)
#define SINC_CPROT_LMTOP(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_LMTOP_SHIFT)) & SINC_CPROT_LMTOP_MASK)

#define SINC_CPROT_CADLMT_MASK                   (0xF0000U)
#define SINC_CPROT_CADLMT_SHIFT                  (16U)
#define SINC_CPROT_CADLMT_WIDTH                  (4U)
#define SINC_CPROT_CADLMT(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_CADLMT_SHIFT)) & SINC_CPROT_CADLMT_MASK)

#define SINC_CPROT_CADBK_MASK                    (0x4000000U)
#define SINC_CPROT_CADBK_SHIFT                   (26U)
#define SINC_CPROT_CADBK_WIDTH                   (1U)
#define SINC_CPROT_CADBK(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_CADBK_SHIFT)) & SINC_CPROT_CADBK_MASK)

#define SINC_CPROT_SCDBK_MASK                    (0x8000000U)
#define SINC_CPROT_SCDBK_SHIFT                   (27U)
#define SINC_CPROT_SCDBK_WIDTH                   (1U)
#define SINC_CPROT_SCDBK(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_SCDBK_SHIFT)) & SINC_CPROT_SCDBK_MASK)

#define SINC_CPROT_LLMTBK_MASK                   (0x20000000U)
#define SINC_CPROT_LLMTBK_SHIFT                  (29U)
#define SINC_CPROT_LLMTBK_WIDTH                  (1U)
#define SINC_CPROT_LLMTBK(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_LLMTBK_SHIFT)) & SINC_CPROT_LLMTBK_MASK)

#define SINC_CPROT_WLMTBK_MASK                   (0x40000000U)
#define SINC_CPROT_WLMTBK_SHIFT                  (30U)
#define SINC_CPROT_WLMTBK_WIDTH                  (1U)
#define SINC_CPROT_WLMTBK(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_WLMTBK_SHIFT)) & SINC_CPROT_WLMTBK_MASK)

#define SINC_CPROT_HLMTBK_MASK                   (0x80000000U)
#define SINC_CPROT_HLMTBK_SHIFT                  (31U)
#define SINC_CPROT_HLMTBK_WIDTH                  (1U)
#define SINC_CPROT_HLMTBK(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CPROT_HLMTBK_SHIFT)) & SINC_CPROT_HLMTBK_MASK)
/*! @} */

/*! @name CBIAS - Channel 0 Bias..Channel 3 Bias */
/*! @{ */

#define SINC_CBIAS_BIAS_MASK                     (0xFFFFFF00U)
#define SINC_CBIAS_BIAS_SHIFT                    (8U)
#define SINC_CBIAS_BIAS_WIDTH                    (24U)
#define SINC_CBIAS_BIAS(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CBIAS_BIAS_SHIFT)) & SINC_CBIAS_BIAS_MASK)
/*! @} */

/*! @name CLOLMT - Channel 0 Low Limit..Channel 3 Low Limit */
/*! @{ */

#define SINC_CLOLMT_LOLMT_MASK                   (0xFFFFFF00U)
#define SINC_CLOLMT_LOLMT_SHIFT                  (8U)
#define SINC_CLOLMT_LOLMT_WIDTH                  (24U)
#define SINC_CLOLMT_LOLMT(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CLOLMT_LOLMT_SHIFT)) & SINC_CLOLMT_LOLMT_MASK)
/*! @} */

/*! @name CHILMT - Channel 0 High Limit..Channel 3 High Limit */
/*! @{ */

#define SINC_CHILMT_HILMT_MASK                   (0xFFFFFF00U)
#define SINC_CHILMT_HILMT_SHIFT                  (8U)
#define SINC_CHILMT_HILMT_WIDTH                  (24U)
#define SINC_CHILMT_HILMT(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CHILMT_HILMT_SHIFT)) & SINC_CHILMT_HILMT_MASK)
/*! @} */

/*! @name CRDATA - Channel 0 Result Data..Channel 3 Result Data */
/*! @{ */

#define SINC_CRDATA_RDATA_MASK                   (0xFFFFFF00U)
#define SINC_CRDATA_RDATA_SHIFT                  (8U)
#define SINC_CRDATA_RDATA_WIDTH                  (24U)
#define SINC_CRDATA_RDATA(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CRDATA_RDATA_SHIFT)) & SINC_CRDATA_RDATA_MASK)
/*! @} */

/*! @name CMPDATA - Channel 0 Multipurpose Data..Channel 3 Multipurpose Data */
/*! @{ */

#define SINC_CMPDATA_MPDATA_MASK                 (0xFFFFFFFFU)
#define SINC_CMPDATA_MPDATA_SHIFT                (0U)
#define SINC_CMPDATA_MPDATA_WIDTH                (32U)
#define SINC_CMPDATA_MPDATA(x)                   (((uint32_t)(((uint32_t)(x)) << SINC_CMPDATA_MPDATA_SHIFT)) & SINC_CMPDATA_MPDATA_MASK)
/*! @} */

/*! @name CACFR - Channel 0 Advanced Configuration..Channel 3 Advanced Configuration */
/*! @{ */

#define SINC_CACFR_HPFA_MASK                     (0xF0000U)
#define SINC_CACFR_HPFA_SHIFT                    (16U)
#define SINC_CACFR_HPFA_WIDTH                    (4U)
#define SINC_CACFR_HPFA(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CACFR_HPFA_SHIFT)) & SINC_CACFR_HPFA_MASK)

#define SINC_CACFR_IBDLY_MASK                    (0xF00000U)
#define SINC_CACFR_IBDLY_SHIFT                   (20U)
#define SINC_CACFR_IBDLY_WIDTH                   (4U)
#define SINC_CACFR_IBDLY(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CACFR_IBDLY_SHIFT)) & SINC_CACFR_IBDLY_MASK)
/*! @} */

/*! @name CSR - Channel 0 Status..Channel 3 Status */
/*! @{ */

#define SINC_CSR_FIFOAVIL_MASK                   (0x1FU)
#define SINC_CSR_FIFOAVIL_SHIFT                  (0U)
#define SINC_CSR_FIFOAVIL_WIDTH                  (5U)
#define SINC_CSR_FIFOAVIL(x)                     (((uint32_t)(((uint32_t)(x)) << SINC_CSR_FIFOAVIL_SHIFT)) & SINC_CSR_FIFOAVIL_MASK)

#define SINC_CSR_PSRDY_MASK                      (0x80U)
#define SINC_CSR_PSRDY_SHIFT                     (7U)
#define SINC_CSR_PSRDY_WIDTH                     (1U)
#define SINC_CSR_PSRDY(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CSR_PSRDY_SHIFT)) & SINC_CSR_PSRDY_MASK)

#define SINC_CSR_PFSAT_MASK                      (0x100U)
#define SINC_CSR_PFSAT_SHIFT                     (8U)
#define SINC_CSR_PFSAT_WIDTH                     (1U)
#define SINC_CSR_PFSAT(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CSR_PFSAT_SHIFT)) & SINC_CSR_PFSAT_MASK)

#define SINC_CSR_HPFSAT_MASK                     (0x200U)
#define SINC_CSR_HPFSAT_SHIFT                    (9U)
#define SINC_CSR_HPFSAT_WIDTH                    (1U)
#define SINC_CSR_HPFSAT(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CSR_HPFSAT_SHIFT)) & SINC_CSR_HPFSAT_MASK)

#define SINC_CSR_SFTSAT_MASK                     (0x400U)
#define SINC_CSR_SFTSAT_SHIFT                    (10U)
#define SINC_CSR_SFTSAT_WIDTH                    (1U)
#define SINC_CSR_SFTSAT(x)                       (((uint32_t)(((uint32_t)(x)) << SINC_CSR_SFTSAT_SHIFT)) & SINC_CSR_SFTSAT_MASK)

#define SINC_CSR_BIASSAT_MASK                    (0x800U)
#define SINC_CSR_BIASSAT_SHIFT                   (11U)
#define SINC_CSR_BIASSAT_WIDTH                   (1U)
#define SINC_CSR_BIASSAT(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CSR_BIASSAT_SHIFT)) & SINC_CSR_BIASSAT_MASK)

#define SINC_CSR_RDRS_MASK                       (0x1000U)
#define SINC_CSR_RDRS_SHIFT                      (12U)
#define SINC_CSR_RDRS_WIDTH                      (1U)
#define SINC_CSR_RDRS(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CSR_RDRS_SHIFT)) & SINC_CSR_RDRS_MASK)

#define SINC_CSR_SRDS_MASK                       (0x2000U)
#define SINC_CSR_SRDS_SHIFT                      (13U)
#define SINC_CSR_SRDS_WIDTH                      (1U)
#define SINC_CSR_SRDS(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CSR_SRDS_SHIFT)) & SINC_CSR_SRDS_MASK)

#define SINC_CSR_DBGRS_MASK                      (0xC000U)
#define SINC_CSR_DBGRS_SHIFT                     (14U)
#define SINC_CSR_DBGRS_WIDTH                     (2U)
#define SINC_CSR_DBGRS(x)                        (((uint32_t)(((uint32_t)(x)) << SINC_CSR_DBGRS_SHIFT)) & SINC_CSR_DBGRS_MASK)

#define SINC_CSR_CNUM_MASK                       (0x7F0000U)
#define SINC_CSR_CNUM_SHIFT                      (16U)
#define SINC_CSR_CNUM_WIDTH                      (7U)
#define SINC_CSR_CNUM(x)                         (((uint32_t)(((uint32_t)(x)) << SINC_CSR_CNUM_SHIFT)) & SINC_CSR_CNUM_MASK)

#define SINC_CSR_CNUM_OV_MASK                    (0x800000U)
#define SINC_CSR_CNUM_OV_SHIFT                   (23U)
#define SINC_CSR_CNUM_OV_WIDTH                   (1U)
#define SINC_CSR_CNUM_OV(x)                      (((uint32_t)(((uint32_t)(x)) << SINC_CSR_CNUM_OV_SHIFT)) & SINC_CSR_CNUM_OV_MASK)
/*! @} */

/*! @name CDBGR - Channel 0 Debug..Channel 3 Debug */
/*! @{ */

#define SINC_CDBGR_DBGDATA_MASK                  (0xFFFFFFFFU)
#define SINC_CDBGR_DBGDATA_SHIFT                 (0U)
#define SINC_CDBGR_DBGDATA_WIDTH                 (32U)
#define SINC_CDBGR_DBGDATA(x)                    (((uint32_t)(((uint32_t)(x)) << SINC_CDBGR_DBGDATA_SHIFT)) & SINC_CDBGR_DBGDATA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SINC_Register_Masks */

/*!
 * @}
 */ /* end of group SINC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SINC_H_) */
