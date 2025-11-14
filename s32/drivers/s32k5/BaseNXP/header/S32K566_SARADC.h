/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_SARADC.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_SARADC
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
#if !defined(S32K566_SARADC_H_)  /* Check if memory map has not been already included */
#define S32K566_SARADC_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SARADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SARADC_Peripheral_Access_Layer SARADC Peripheral Access Layer
 * @{
 */

/** SARADC - Size of Registers Arrays */
#define SARADC_THRHLN_COUNT                       4u
#define SARADC_CD0_P_COUNT                        16u
#define SARADC_CD0_M_COUNT                        16u
#define SARADC_CD1_P_COUNT                        11u
#define SARADC_CD1_M_COUNT                        11u
#define SARADC_CD2_P_COUNT                        16u
#define SARADC_CD2_M_COUNT                        16u

/** SARADC - Register Layout Typedef */
typedef struct SARADC_Struct {
  __IO uint32_t MC;                                /**< Main Configuration, offset: 0x0 */
  __IO uint32_t MS;                                /**< Main Status, offset: 0x4 */
  __IO uint32_t CALBIST;                           /**< Control and Calibration Status, offset: 0x8 */
  uint8_t RESERVED_0[4];
  __IO uint32_t IS;                                /**< Interrupt Status, offset: 0x10 */
  __IO uint32_t CEOCF0;                            /**< Channel End of Conversion Flag for Type 0, offset: 0x14 */
  __IO uint32_t CEOCF1;                            /**< Channel End of Conversion Flag for Type 1, offset: 0x18 */
  __IO uint32_t CEOCF2;                            /**< Channel End of Conversion Flag for Type 2, offset: 0x1C */
  __IO uint32_t IM;                                /**< Interrupt Mask, offset: 0x20 */
  __IO uint32_t CIM0;                              /**< EOC Interrupt Enable for Type 0, offset: 0x24 */
  __IO uint32_t CIM1;                              /**< EOC Interrupt Enable for Type 1, offset: 0x28 */
  __IO uint32_t CIM2;                              /**< EOC Interrupt Enable for Type 2, offset: 0x2C */
  __IO uint32_t WTIS;                              /**< Analog Watchdog Threshold Interrupt Status, offset: 0x30 */
  __IO uint32_t WTIM;                              /**< Analog Watchdog Threshold Interrupt Mask, offset: 0x34 */
  uint8_t RESERVED_1[8];
  __IO uint32_t DMAE;                              /**< Direct Memory Access Configuration, offset: 0x40 */
  __IO uint32_t DMA0;                              /**< DMA Request Enable for Type 0, offset: 0x44 */
  __IO uint32_t DMA1;                              /**< DMA Request Enable for Type 1, offset: 0x48 */
  __IO uint32_t DMA2;                              /**< DMA Request Enable for Type 2, offset: 0x4C */
  uint8_t RESERVED_2[16];
  __IO uint32_t THRHL[SARADC_THRHLN_COUNT];        /**< Analog Watchdog Threshold Values, array offset: 0x60, array step: 0x4 */
  uint8_t RESERVED_3[48];
  __IO uint32_t SMPLTSEL;                          /**< Sample Time Select, offset: 0xA0 */
  __IO uint32_t NCM0;                              /**< Normal Conversion Mask for Type 0, offset: 0xA4 */
  __IO uint32_t NCM1;                              /**< Normal Conversion Mask for Type 1, offset: 0xA8 */
  __IO uint32_t NCM2;                              /**< Normal Conversion Mask for Type 2, offset: 0xAC */
  uint8_t RESERVED_4[4];
  __IO uint32_t JCM0;                              /**< Injected Conversion Mask for Type 0, offset: 0xB4 */
  __IO uint32_t JCM1;                              /**< Injected Conversion Mask for Type 1, offset: 0xB8 */
  __IO uint32_t JCM2;                              /**< Injected Conversion Mask for Type 2, offset: 0xBC */
  uint8_t RESERVED_5[4];
  __IO uint32_t DSD;                               /**< Delay Start of Data Conversion, offset: 0xC4 */
  __IO uint32_t PUDLY;                             /**< Power Up Delay, offset: 0xC8 */
  uint8_t RESERVED_6[52];
  __I  uint32_t CD0_P[SARADC_CD0_P_COUNT];         /**< Type 0 Input n Conversion Data, array offset: 0x100, array step: 0x4 */
  __I  uint32_t CD0_M[SARADC_CD0_M_COUNT];         /**< Type 0 Input n Conversion Data, array offset: 0x140, array step: 0x4 */
  __I  uint32_t CD1_P[SARADC_CD1_P_COUNT];         /**< Type 1 Input n Conversion Data, array offset: 0x180, array step: 0x4 */
  uint8_t RESERVED_7[20];
  __I  uint32_t CD1_M[SARADC_CD1_M_COUNT];         /**< Type 1 Input n Conversion Data, array offset: 0x1C0, array step: 0x4 */
  uint8_t RESERVED_8[20];
  __I  uint32_t CD2_P[SARADC_CD2_P_COUNT];         /**< Type 2 input n Conversion Data, array offset: 0x200, array step: 0x4 */
  __I  uint32_t CD2_M[SARADC_CD2_M_COUNT];         /**< Type 2 input n Conversion Data, array offset: 0x240, array step: 0x4 */
  uint8_t RESERVED_9[48];
  __IO uint32_t CWSEL_0_0;                         /**< Channel Analog Watchdog Select for Type 0, offset: 0x2B0 */
  __IO uint32_t CWSEL_0_1;                         /**< Channel Analog Watchdog Select for Type 0, offset: 0x2B4 */
  __IO uint32_t CWSEL_0_2;                         /**< Channel Analog Watchdog Select for Type 0, offset: 0x2B8 */
  __IO uint32_t CWSEL_0_3;                         /**< Channel Analog Watchdog Select for Type 0, offset: 0x2BC */
  __IO uint32_t CWSEL_1_0;                         /**< Channel Analog Watchdog Select for Type 1, offset: 0x2C0 */
  __IO uint32_t CWSEL_1_1;                         /**< Channel Analog Watchdog Select for Type 1, offset: 0x2C4 */
  __IO uint32_t CWSEL_1_2;                         /**< Channel Analog Watchdog Select for Type 1, offset: 0x2C8 */
  __IO uint32_t CWSEL_1_3;                         /**< Channel Analog Watchdog Select for Type 1, offset: 0x2CC */
  __IO uint32_t CWSEL_2_0;                         /**< Channel Analog Watchdog Select for Type 2, offset: 0x2D0 */
  __IO uint32_t CWSEL_2_1;                         /**< Channel Analog Watchdog Select for Type 2, offset: 0x2D4 */
  __IO uint32_t CWSEL_2_2;                         /**< Channel Analog Watchdog Select for Type 2, offset: 0x2D8 */
  __IO uint32_t CWSEL_2_3;                         /**< Channel Analog Watchdog Select for Type 2, offset: 0x2DC */
  __IO uint32_t CWEN0;                             /**< Channel Watchdog Enable for Type 0, offset: 0x2E0 */
  __IO uint32_t CWEN1;                             /**< Channel Watchdog Enable for Type 1, offset: 0x2E4 */
  __IO uint32_t CWEN2;                             /**< Channel Watchdog Enable for Type 2, offset: 0x2E8 */
  uint8_t RESERVED_10[4];
  __IO uint32_t AWOR0;                             /**< Analog Watchdog Out of Range for Type 0, offset: 0x2F0 */
  __IO uint32_t AWOR1;                             /**< Analog Watchdog Out of Range for Type 1, offset: 0x2F4 */
  __IO uint32_t AWOR2;                             /**< Analog Watchdog Out of Range for Type 2, offset: 0x2F8 */
  uint8_t RESERVED_11[68];
  __IO uint32_t STC1;                              /**< Self-Test Configuration 1, offset: 0x340 */
  __IO uint32_t STC2;                              /**< Self-Test Configuration 2, offset: 0x344 */
  uint8_t RESERVED_12[4];
  __IO uint32_t STBR;                              /**< Self-Test Baud Rate, offset: 0x34C */
  __IO uint32_t STS1_P;                            /**< Self-Test Status 1 for P-SARADC, offset: 0x350 */
  __IO uint32_t STS1_M;                            /**< Self-Test Status 1 for M-SARADC, offset: 0x354 */
  __I  uint32_t STS2_P;                            /**< Self-Test Status 2 for P-SARADC, offset: 0x358 */
  __I  uint32_t STS2_M;                            /**< Self-Test Status 2 for M-SARADC, offset: 0x35C */
  __I  uint32_t STS3_P;                            /**< Self-Test Status 3 for P-SARADC, offset: 0x360 */
  __I  uint32_t STS3_M;                            /**< Self-Test Status 3 for M-SARADC, offset: 0x364 */
  __I  uint32_t STS4_P;                            /**< Self-Test Status 4 for P-SARADC, offset: 0x368 */
  __I  uint32_t STS4_M;                            /**< Self-Test Status 4 for M-SARADC, offset: 0x36C */
  __I  uint32_t STD1_P;                            /**< Self-Test Conversion Data 1 for P-SARADC, offset: 0x370 */
  __I  uint32_t STD1_M;                            /**< Self-Test Conversion Data 1 for M-SARADC, offset: 0x374 */
  __I  uint32_t STD2_P;                            /**< Self-Test Conversion Data 2 for P-SARADC, offset: 0x378 */
  __I  uint32_t STD2_M;                            /**< Self-Test Conversion Data 2 for M-SARADC, offset: 0x37C */
  __IO uint32_t STAWVBG;                           /**< Self Test Analog Watchdog Threshold for Bandgap Supply, offset: 0x380 */
  __IO uint32_t STAWVDDI;                          /**< Self Test Analog Watchdog Threshold for VDD (Integer Part), offset: 0x384 */
  __IO uint32_t STAWVDDF;                          /**< Self Test Analog Watchdog Threshold for VDD (Fractional Part), offset: 0x388 */
  __IO uint32_t STAWVRHL;                          /**< Self Test Analog Watchdog Threshold for Reference High Supply, offset: 0x38C */
  __IO uint32_t STAWOFS;                           /**< Self Test Analog Watchdog Threshold for Offset, offset: 0x390 */
  __IO uint32_t STAWCAPM;                          /**< Self Test Analog Watchdog Threshold for MSB Capacitor, offset: 0x394 */
  __IO uint32_t STAWCAPI;                          /**< Self Test Analog Watchdog Threshold for ISB Capacitor, offset: 0x398 */
  __IO uint32_t STAWCAPL;                          /**< Self Test Analog Watchdog Threshold for LSB Capacitor, offset: 0x39C */
  uint8_t RESERVED_13[8];
  __IO uint32_t GCC_P;                             /**< Gain Calibration Control for P-SARADC Converter, offset: 0x3A8 */
  __IO uint32_t GCC_M;                             /**< Gain Calibration Control for M-SARADC SARADC Converter, offset: 0x3AC */
  __IO uint32_t GCR_P;                             /**< Gain Calculation Result for P-SARADC Converter, offset: 0x3B0 */
  __IO uint32_t GCR_M;                             /**< Gain Calculation Result for M-SARADC Converter, offset: 0x3B4 */
  uint8_t RESERVED_14[268];
  __I  uint32_t CALSTSP0;                          /**< Calibration Fail Status 0 for P-SARADC, offset: 0x4C4 */
  __I  uint32_t CALSTSP1;                          /**< Calibration Fail Status 1 for P-SARADC, offset: 0x4C8 */
  __I  uint32_t CALSTSM0;                          /**< Calibration Fail Status 0 for M-SARADC, offset: 0x4CC */
  __I  uint32_t CALSTSM1;                          /**< Calibration Fail Status 1 for M-SARADC, offset: 0x4D0 */
} SARADC_Type, *SARADC_MemMapPtr;

/** Number of instances of the SARADC module. */
#define SARADC_INSTANCE_COUNT                    3

/* SARADC - Peripheral instance base addresses */
/** Peripheral LPE_SARADC base address */
#define IP_LPE_SARADC_BASE                       (0x4213C000u)
/** Peripheral LPE_SARADC base pointer */
#define IP_LPE_SARADC                            ((SARADC_Type *)IP_LPE_SARADC_BASE)
/** Peripheral SARADC_0 base address */
#define IP_SARADC_0_BASE                         (0x40698000u)
/** Peripheral SARADC_0 base pointer */
#define IP_SARADC_0                              ((SARADC_Type *)IP_SARADC_0_BASE)
/** Peripheral SARADC_1 base address */
#define IP_SARADC_1_BASE                         (0x4088C000u)
/** Peripheral SARADC_1 base pointer */
#define IP_SARADC_1                              ((SARADC_Type *)IP_SARADC_1_BASE)
/** Array initializer of SARADC peripheral base addresses */
#define IP_SARADC_BASE_ADDRS                     { IP_LPE_SARADC_BASE, IP_SARADC_0_BASE, IP_SARADC_1_BASE }
/** Array initializer of SARADC peripheral base pointers */
#define IP_SARADC_BASE_PTRS                      { IP_LPE_SARADC, IP_SARADC_0, IP_SARADC_1 }

/* ----------------------------------------------------------------------------
   -- SARADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SARADC_Register_Masks SARADC Register Masks
 * @{
 */

/*! @name MC - Main Configuration */
/*! @{ */

#define SARADC_MC_PWDN_MASK                      (0x1U)
#define SARADC_MC_PWDN_SHIFT                     (0U)
#define SARADC_MC_PWDN_WIDTH                     (1U)
#define SARADC_MC_PWDN(x)                        (((uint32_t)(((uint32_t)(x)) << SARADC_MC_PWDN_SHIFT)) & SARADC_MC_PWDN_MASK)

#define SARADC_MC_ADCLKSEL_MASK                  (0x6U)
#define SARADC_MC_ADCLKSEL_SHIFT                 (1U)
#define SARADC_MC_ADCLKSEL_WIDTH                 (2U)
#define SARADC_MC_ADCLKSEL(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_MC_ADCLKSEL_SHIFT)) & SARADC_MC_ADCLKSEL_MASK)

#define SARADC_MC_ADCLKDIV_MASK                  (0x8U)
#define SARADC_MC_ADCLKDIV_SHIFT                 (3U)
#define SARADC_MC_ADCLKDIV_WIDTH                 (1U)
#define SARADC_MC_ADCLKDIV(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_MC_ADCLKDIV_SHIFT)) & SARADC_MC_ADCLKDIV_MASK)

#define SARADC_MC_ACKO_MASK                      (0x20U)
#define SARADC_MC_ACKO_SHIFT                     (5U)
#define SARADC_MC_ACKO_WIDTH                     (1U)
#define SARADC_MC_ACKO(x)                        (((uint32_t)(((uint32_t)(x)) << SARADC_MC_ACKO_SHIFT)) & SARADC_MC_ACKO_MASK)

#define SARADC_MC_STOP_MASK                      (0x40U)
#define SARADC_MC_STOP_SHIFT                     (6U)
#define SARADC_MC_STOP_WIDTH                     (1U)
#define SARADC_MC_STOP(x)                        (((uint32_t)(((uint32_t)(x)) << SARADC_MC_STOP_SHIFT)) & SARADC_MC_STOP_MASK)

#define SARADC_MC_STOPCHN_MASK                   (0x80U)
#define SARADC_MC_STOPCHN_SHIFT                  (7U)
#define SARADC_MC_STOPCHN_WIDTH                  (1U)
#define SARADC_MC_STOPCHN(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_MC_STOPCHN_SHIFT)) & SARADC_MC_STOPCHN_MASK)

#define SARADC_MC_AVGS_MASK                      (0x600U)
#define SARADC_MC_AVGS_SHIFT                     (9U)
#define SARADC_MC_AVGS_WIDTH                     (2U)
#define SARADC_MC_AVGS(x)                        (((uint32_t)(((uint32_t)(x)) << SARADC_MC_AVGS_SHIFT)) & SARADC_MC_AVGS_MASK)

#define SARADC_MC_AVGEN_MASK                     (0x800U)
#define SARADC_MC_AVGEN_SHIFT                    (11U)
#define SARADC_MC_AVGEN_WIDTH                    (1U)
#define SARADC_MC_AVGEN(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_MC_AVGEN_SHIFT)) & SARADC_MC_AVGEN_MASK)

#define SARADC_MC_CTYPE_MASK                     (0x3000U)
#define SARADC_MC_CTYPE_SHIFT                    (12U)
#define SARADC_MC_CTYPE_WIDTH                    (2U)
#define SARADC_MC_CTYPE(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_MC_CTYPE_SHIFT)) & SARADC_MC_CTYPE_MASK)

#define SARADC_MC_STCL_MASK                      (0x8000U)
#define SARADC_MC_STCL_SHIFT                     (15U)
#define SARADC_MC_STCL_WIDTH                     (1U)
#define SARADC_MC_STCL(x)                        (((uint32_t)(((uint32_t)(x)) << SARADC_MC_STCL_SHIFT)) & SARADC_MC_STCL_MASK)

#define SARADC_MC_CTUMODE_MASK                   (0x10000U)
#define SARADC_MC_CTUMODE_SHIFT                  (16U)
#define SARADC_MC_CTUMODE_WIDTH                  (1U)
#define SARADC_MC_CTUMODE(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_MC_CTUMODE_SHIFT)) & SARADC_MC_CTUMODE_MASK)

#define SARADC_MC_CTUEN_MASK                     (0x20000U)
#define SARADC_MC_CTUEN_SHIFT                    (17U)
#define SARADC_MC_CTUEN_WIDTH                    (1U)
#define SARADC_MC_CTUEN(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_MC_CTUEN_SHIFT)) & SARADC_MC_CTUEN_MASK)

#define SARADC_MC_JSTART_MASK                    (0x100000U)
#define SARADC_MC_JSTART_SHIFT                   (20U)
#define SARADC_MC_JSTART_WIDTH                   (1U)
#define SARADC_MC_JSTART(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_MC_JSTART_SHIFT)) & SARADC_MC_JSTART_MASK)

#define SARADC_MC_JEDGE_MASK                     (0x200000U)
#define SARADC_MC_JEDGE_SHIFT                    (21U)
#define SARADC_MC_JEDGE_WIDTH                    (1U)
#define SARADC_MC_JEDGE(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_MC_JEDGE_SHIFT)) & SARADC_MC_JEDGE_MASK)

#define SARADC_MC_JTRGEN_MASK                    (0x400000U)
#define SARADC_MC_JTRGEN_SHIFT                   (22U)
#define SARADC_MC_JTRGEN_WIDTH                   (1U)
#define SARADC_MC_JTRGEN(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_MC_JTRGEN_SHIFT)) & SARADC_MC_JTRGEN_MASK)

#define SARADC_MC_NSTART_MASK                    (0x1000000U)
#define SARADC_MC_NSTART_SHIFT                   (24U)
#define SARADC_MC_NSTART_WIDTH                   (1U)
#define SARADC_MC_NSTART(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_MC_NSTART_SHIFT)) & SARADC_MC_NSTART_MASK)

#define SARADC_MC_XSTRTEN_MASK                   (0x2000000U)
#define SARADC_MC_XSTRTEN_SHIFT                  (25U)
#define SARADC_MC_XSTRTEN_WIDTH                  (1U)
#define SARADC_MC_XSTRTEN(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_MC_XSTRTEN_SHIFT)) & SARADC_MC_XSTRTEN_MASK)

#define SARADC_MC_EDGE_MASK                      (0x4000000U)
#define SARADC_MC_EDGE_SHIFT                     (26U)
#define SARADC_MC_EDGE_WIDTH                     (1U)
#define SARADC_MC_EDGE(x)                        (((uint32_t)(((uint32_t)(x)) << SARADC_MC_EDGE_SHIFT)) & SARADC_MC_EDGE_MASK)

#define SARADC_MC_TRGEN_MASK                     (0x8000000U)
#define SARADC_MC_TRGEN_SHIFT                    (27U)
#define SARADC_MC_TRGEN_WIDTH                    (1U)
#define SARADC_MC_TRGEN(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_MC_TRGEN_SHIFT)) & SARADC_MC_TRGEN_MASK)

#define SARADC_MC_MODE_MASK                      (0x20000000U)
#define SARADC_MC_MODE_SHIFT                     (29U)
#define SARADC_MC_MODE_WIDTH                     (1U)
#define SARADC_MC_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << SARADC_MC_MODE_SHIFT)) & SARADC_MC_MODE_MASK)

#define SARADC_MC_WLSIDE_MASK                    (0x40000000U)
#define SARADC_MC_WLSIDE_SHIFT                   (30U)
#define SARADC_MC_WLSIDE_WIDTH                   (1U)
#define SARADC_MC_WLSIDE(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_MC_WLSIDE_SHIFT)) & SARADC_MC_WLSIDE_MASK)

#define SARADC_MC_OWREN_MASK                     (0x80000000U)
#define SARADC_MC_OWREN_SHIFT                    (31U)
#define SARADC_MC_OWREN_WIDTH                    (1U)
#define SARADC_MC_OWREN(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_MC_OWREN_SHIFT)) & SARADC_MC_OWREN_MASK)
/*! @} */

/*! @name MS - Main Status */
/*! @{ */

#define SARADC_MS_ADCSTS_MASK                    (0xFU)
#define SARADC_MS_ADCSTS_SHIFT                   (0U)
#define SARADC_MS_ADCSTS_WIDTH                   (4U)
#define SARADC_MS_ADCSTS(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_MS_ADCSTS_SHIFT)) & SARADC_MS_ADCSTS_MASK)

#define SARADC_MS_ACKO_MASK                      (0x20U)
#define SARADC_MS_ACKO_SHIFT                     (5U)
#define SARADC_MS_ACKO_WIDTH                     (1U)
#define SARADC_MS_ACKO(x)                        (((uint32_t)(((uint32_t)(x)) << SARADC_MS_ACKO_SHIFT)) & SARADC_MS_ACKO_MASK)

#define SARADC_MS_CHADDR_MASK                    (0xFE00U)
#define SARADC_MS_CHADDR_SHIFT                   (9U)
#define SARADC_MS_CHADDR_WIDTH                   (7U)
#define SARADC_MS_CHADDR(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_MS_CHADDR_SHIFT)) & SARADC_MS_CHADDR_MASK)

#define SARADC_MS_CTUSTART_MASK                  (0x10000U)
#define SARADC_MS_CTUSTART_SHIFT                 (16U)
#define SARADC_MS_CTUSTART_WIDTH                 (1U)
#define SARADC_MS_CTUSTART(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_MS_CTUSTART_SHIFT)) & SARADC_MS_CTUSTART_MASK)

#define SARADC_MS_SELF_TST_MASK                  (0x40000U)
#define SARADC_MS_SELF_TST_SHIFT                 (18U)
#define SARADC_MS_SELF_TST_WIDTH                 (1U)
#define SARADC_MS_SELF_TST(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_MS_SELF_TST_SHIFT)) & SARADC_MS_SELF_TST_MASK)

#define SARADC_MS_JSTART_MASK                    (0x100000U)
#define SARADC_MS_JSTART_SHIFT                   (20U)
#define SARADC_MS_JSTART_WIDTH                   (1U)
#define SARADC_MS_JSTART(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_MS_JSTART_SHIFT)) & SARADC_MS_JSTART_MASK)

#define SARADC_MS_JSTOP_MASK                     (0x800000U)
#define SARADC_MS_JSTOP_SHIFT                    (23U)
#define SARADC_MS_JSTOP_WIDTH                    (1U)
#define SARADC_MS_JSTOP(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_MS_JSTOP_SHIFT)) & SARADC_MS_JSTOP_MASK)

#define SARADC_MS_NSTART_MASK                    (0x1000000U)
#define SARADC_MS_NSTART_SHIFT                   (24U)
#define SARADC_MS_NSTART_WIDTH                   (1U)
#define SARADC_MS_NSTART(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_MS_NSTART_SHIFT)) & SARADC_MS_NSTART_MASK)

#define SARADC_MS_CALFAIL_MASK                   (0x8000000U)
#define SARADC_MS_CALFAIL_SHIFT                  (27U)
#define SARADC_MS_CALFAIL_WIDTH                  (1U)
#define SARADC_MS_CALFAIL(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_MS_CALFAIL_SHIFT)) & SARADC_MS_CALFAIL_MASK)

#define SARADC_MS_OFSBUSY_MASK                   (0x10000000U)
#define SARADC_MS_OFSBUSY_SHIFT                  (28U)
#define SARADC_MS_OFSBUSY_WIDTH                  (1U)
#define SARADC_MS_OFSBUSY(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_MS_OFSBUSY_SHIFT)) & SARADC_MS_OFSBUSY_MASK)

#define SARADC_MS_CALBUSY_MASK                   (0x20000000U)
#define SARADC_MS_CALBUSY_SHIFT                  (29U)
#define SARADC_MS_CALBUSY_WIDTH                  (1U)
#define SARADC_MS_CALBUSY(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_MS_CALBUSY_SHIFT)) & SARADC_MS_CALBUSY_MASK)

#define SARADC_MS_CAP_DONE_MASK                  (0x40000000U)
#define SARADC_MS_CAP_DONE_SHIFT                 (30U)
#define SARADC_MS_CAP_DONE_WIDTH                 (1U)
#define SARADC_MS_CAP_DONE(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_MS_CAP_DONE_SHIFT)) & SARADC_MS_CAP_DONE_MASK)

#define SARADC_MS_OFS_DONE_MASK                  (0x80000000U)
#define SARADC_MS_OFS_DONE_SHIFT                 (31U)
#define SARADC_MS_OFS_DONE_WIDTH                 (1U)
#define SARADC_MS_OFS_DONE(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_MS_OFS_DONE_SHIFT)) & SARADC_MS_OFS_DONE_MASK)
/*! @} */

/*! @name CALBIST - Control and Calibration Status */
/*! @{ */

#define SARADC_CALBIST_CAL_AVGS_MASK             (0xFU)
#define SARADC_CALBIST_CAL_AVGS_SHIFT            (0U)
#define SARADC_CALBIST_CAL_AVGS_WIDTH            (4U)
#define SARADC_CALBIST_CAL_AVGS(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CALBIST_CAL_AVGS_SHIFT)) & SARADC_CALBIST_CAL_AVGS_MASK)

#define SARADC_CALBIST_CALAVGEN_MASK             (0x10U)
#define SARADC_CALBIST_CALAVGEN_SHIFT            (4U)
#define SARADC_CALBIST_CALAVGEN_WIDTH            (1U)
#define SARADC_CALBIST_CALAVGEN(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CALBIST_CALAVGEN_SHIFT)) & SARADC_CALBIST_CALAVGEN_MASK)

#define SARADC_CALBIST_CST_LONG_MASK             (0x80U)
#define SARADC_CALBIST_CST_LONG_SHIFT            (7U)
#define SARADC_CALBIST_CST_LONG_WIDTH            (1U)
#define SARADC_CALBIST_CST_LONG(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CALBIST_CST_LONG_SHIFT)) & SARADC_CALBIST_CST_LONG_MASK)

#define SARADC_CALBIST_CAP_REQ_MASK              (0x100U)
#define SARADC_CALBIST_CAP_REQ_SHIFT             (8U)
#define SARADC_CALBIST_CAP_REQ_WIDTH             (1U)
#define SARADC_CALBIST_CAP_REQ(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CALBIST_CAP_REQ_SHIFT)) & SARADC_CALBIST_CAP_REQ_MASK)

#define SARADC_CALBIST_OFS_REQ_MASK              (0x200U)
#define SARADC_CALBIST_OFS_REQ_SHIFT             (9U)
#define SARADC_CALBIST_OFS_REQ_WIDTH             (1U)
#define SARADC_CALBIST_OFS_REQ(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CALBIST_OFS_REQ_SHIFT)) & SARADC_CALBIST_OFS_REQ_MASK)

#define SARADC_CALBIST_FRCOFFM_MASK              (0x10000U)
#define SARADC_CALBIST_FRCOFFM_SHIFT             (16U)
#define SARADC_CALBIST_FRCOFFM_WIDTH             (1U)
#define SARADC_CALBIST_FRCOFFM(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CALBIST_FRCOFFM_SHIFT)) & SARADC_CALBIST_FRCOFFM_MASK)

#define SARADC_CALBIST_FRCOFFP_MASK              (0x20000U)
#define SARADC_CALBIST_FRCOFFP_SHIFT             (17U)
#define SARADC_CALBIST_FRCOFFP_WIDTH             (1U)
#define SARADC_CALBIST_FRCOFFP(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CALBIST_FRCOFFP_SHIFT)) & SARADC_CALBIST_FRCOFFP_MASK)

#define SARADC_CALBIST_OFFBSTEN_MASK             (0x40000U)
#define SARADC_CALBIST_OFFBSTEN_SHIFT            (18U)
#define SARADC_CALBIST_OFFBSTEN_WIDTH            (1U)
#define SARADC_CALBIST_OFFBSTEN(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CALBIST_OFFBSTEN_SHIFT)) & SARADC_CALBIST_OFFBSTEN_MASK)
/*! @} */

/*! @name IS - Interrupt Status */
/*! @{ */

#define SARADC_IS_ECH_MASK                       (0x1U)
#define SARADC_IS_ECH_SHIFT                      (0U)
#define SARADC_IS_ECH_WIDTH                      (1U)
#define SARADC_IS_ECH(x)                         (((uint32_t)(((uint32_t)(x)) << SARADC_IS_ECH_SHIFT)) & SARADC_IS_ECH_MASK)

#define SARADC_IS_EOC_MASK                       (0x2U)
#define SARADC_IS_EOC_SHIFT                      (1U)
#define SARADC_IS_EOC_WIDTH                      (1U)
#define SARADC_IS_EOC(x)                         (((uint32_t)(((uint32_t)(x)) << SARADC_IS_EOC_SHIFT)) & SARADC_IS_EOC_MASK)

#define SARADC_IS_JECH_MASK                      (0x4U)
#define SARADC_IS_JECH_SHIFT                     (2U)
#define SARADC_IS_JECH_WIDTH                     (1U)
#define SARADC_IS_JECH(x)                        (((uint32_t)(((uint32_t)(x)) << SARADC_IS_JECH_SHIFT)) & SARADC_IS_JECH_MASK)

#define SARADC_IS_JEOC_MASK                      (0x8U)
#define SARADC_IS_JEOC_SHIFT                     (3U)
#define SARADC_IS_JEOC_WIDTH                     (1U)
#define SARADC_IS_JEOC(x)                        (((uint32_t)(((uint32_t)(x)) << SARADC_IS_JEOC_SHIFT)) & SARADC_IS_JEOC_MASK)

#define SARADC_IS_EOBCTU_MASK                    (0x10U)
#define SARADC_IS_EOBCTU_SHIFT                   (4U)
#define SARADC_IS_EOBCTU_WIDTH                   (1U)
#define SARADC_IS_EOBCTU(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_IS_EOBCTU_SHIFT)) & SARADC_IS_EOBCTU_MASK)
/*! @} */

/*! @name CEOCF0 - Channel End of Conversion Flag for Type 0 */
/*! @{ */

#define SARADC_CEOCF0_T0_IEOCF0_MASK             (0x1U)
#define SARADC_CEOCF0_T0_IEOCF0_SHIFT            (0U)
#define SARADC_CEOCF0_T0_IEOCF0_WIDTH            (1U)
#define SARADC_CEOCF0_T0_IEOCF0(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF0_SHIFT)) & SARADC_CEOCF0_T0_IEOCF0_MASK)

#define SARADC_CEOCF0_T0_IEOCF1_MASK             (0x2U)
#define SARADC_CEOCF0_T0_IEOCF1_SHIFT            (1U)
#define SARADC_CEOCF0_T0_IEOCF1_WIDTH            (1U)
#define SARADC_CEOCF0_T0_IEOCF1(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF1_SHIFT)) & SARADC_CEOCF0_T0_IEOCF1_MASK)

#define SARADC_CEOCF0_T0_IEOCF2_MASK             (0x4U)
#define SARADC_CEOCF0_T0_IEOCF2_SHIFT            (2U)
#define SARADC_CEOCF0_T0_IEOCF2_WIDTH            (1U)
#define SARADC_CEOCF0_T0_IEOCF2(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF2_SHIFT)) & SARADC_CEOCF0_T0_IEOCF2_MASK)

#define SARADC_CEOCF0_T0_IEOCF3_MASK             (0x8U)
#define SARADC_CEOCF0_T0_IEOCF3_SHIFT            (3U)
#define SARADC_CEOCF0_T0_IEOCF3_WIDTH            (1U)
#define SARADC_CEOCF0_T0_IEOCF3(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF3_SHIFT)) & SARADC_CEOCF0_T0_IEOCF3_MASK)

#define SARADC_CEOCF0_T0_IEOCF4_MASK             (0x10U)
#define SARADC_CEOCF0_T0_IEOCF4_SHIFT            (4U)
#define SARADC_CEOCF0_T0_IEOCF4_WIDTH            (1U)
#define SARADC_CEOCF0_T0_IEOCF4(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF4_SHIFT)) & SARADC_CEOCF0_T0_IEOCF4_MASK)

#define SARADC_CEOCF0_T0_IEOCF5_MASK             (0x20U)
#define SARADC_CEOCF0_T0_IEOCF5_SHIFT            (5U)
#define SARADC_CEOCF0_T0_IEOCF5_WIDTH            (1U)
#define SARADC_CEOCF0_T0_IEOCF5(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF5_SHIFT)) & SARADC_CEOCF0_T0_IEOCF5_MASK)

#define SARADC_CEOCF0_T0_IEOCF6_MASK             (0x40U)
#define SARADC_CEOCF0_T0_IEOCF6_SHIFT            (6U)
#define SARADC_CEOCF0_T0_IEOCF6_WIDTH            (1U)
#define SARADC_CEOCF0_T0_IEOCF6(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF6_SHIFT)) & SARADC_CEOCF0_T0_IEOCF6_MASK)

#define SARADC_CEOCF0_T0_IEOCF7_MASK             (0x80U)
#define SARADC_CEOCF0_T0_IEOCF7_SHIFT            (7U)
#define SARADC_CEOCF0_T0_IEOCF7_WIDTH            (1U)
#define SARADC_CEOCF0_T0_IEOCF7(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF7_SHIFT)) & SARADC_CEOCF0_T0_IEOCF7_MASK)

#define SARADC_CEOCF0_T0_IEOCF8_MASK             (0x100U)
#define SARADC_CEOCF0_T0_IEOCF8_SHIFT            (8U)
#define SARADC_CEOCF0_T0_IEOCF8_WIDTH            (1U)
#define SARADC_CEOCF0_T0_IEOCF8(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF8_SHIFT)) & SARADC_CEOCF0_T0_IEOCF8_MASK)

#define SARADC_CEOCF0_T0_IEOCF9_MASK             (0x200U)
#define SARADC_CEOCF0_T0_IEOCF9_SHIFT            (9U)
#define SARADC_CEOCF0_T0_IEOCF9_WIDTH            (1U)
#define SARADC_CEOCF0_T0_IEOCF9(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF9_SHIFT)) & SARADC_CEOCF0_T0_IEOCF9_MASK)

#define SARADC_CEOCF0_T0_IEOCF10_MASK            (0x400U)
#define SARADC_CEOCF0_T0_IEOCF10_SHIFT           (10U)
#define SARADC_CEOCF0_T0_IEOCF10_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF10(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF10_SHIFT)) & SARADC_CEOCF0_T0_IEOCF10_MASK)

#define SARADC_CEOCF0_T0_IEOCF11_MASK            (0x800U)
#define SARADC_CEOCF0_T0_IEOCF11_SHIFT           (11U)
#define SARADC_CEOCF0_T0_IEOCF11_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF11(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF11_SHIFT)) & SARADC_CEOCF0_T0_IEOCF11_MASK)

#define SARADC_CEOCF0_T0_IEOCF12_MASK            (0x1000U)
#define SARADC_CEOCF0_T0_IEOCF12_SHIFT           (12U)
#define SARADC_CEOCF0_T0_IEOCF12_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF12(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF12_SHIFT)) & SARADC_CEOCF0_T0_IEOCF12_MASK)

#define SARADC_CEOCF0_T0_IEOCF13_MASK            (0x2000U)
#define SARADC_CEOCF0_T0_IEOCF13_SHIFT           (13U)
#define SARADC_CEOCF0_T0_IEOCF13_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF13(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF13_SHIFT)) & SARADC_CEOCF0_T0_IEOCF13_MASK)

#define SARADC_CEOCF0_T0_IEOCF14_MASK            (0x4000U)
#define SARADC_CEOCF0_T0_IEOCF14_SHIFT           (14U)
#define SARADC_CEOCF0_T0_IEOCF14_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF14(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF14_SHIFT)) & SARADC_CEOCF0_T0_IEOCF14_MASK)

#define SARADC_CEOCF0_T0_IEOCF15_MASK            (0x8000U)
#define SARADC_CEOCF0_T0_IEOCF15_SHIFT           (15U)
#define SARADC_CEOCF0_T0_IEOCF15_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF15(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF15_SHIFT)) & SARADC_CEOCF0_T0_IEOCF15_MASK)

#define SARADC_CEOCF0_T0_IEOCF16_MASK            (0x10000U)
#define SARADC_CEOCF0_T0_IEOCF16_SHIFT           (16U)
#define SARADC_CEOCF0_T0_IEOCF16_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF16(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF16_SHIFT)) & SARADC_CEOCF0_T0_IEOCF16_MASK)

#define SARADC_CEOCF0_T0_IEOCF17_MASK            (0x20000U)
#define SARADC_CEOCF0_T0_IEOCF17_SHIFT           (17U)
#define SARADC_CEOCF0_T0_IEOCF17_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF17(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF17_SHIFT)) & SARADC_CEOCF0_T0_IEOCF17_MASK)

#define SARADC_CEOCF0_T0_IEOCF18_MASK            (0x40000U)
#define SARADC_CEOCF0_T0_IEOCF18_SHIFT           (18U)
#define SARADC_CEOCF0_T0_IEOCF18_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF18(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF18_SHIFT)) & SARADC_CEOCF0_T0_IEOCF18_MASK)

#define SARADC_CEOCF0_T0_IEOCF19_MASK            (0x80000U)
#define SARADC_CEOCF0_T0_IEOCF19_SHIFT           (19U)
#define SARADC_CEOCF0_T0_IEOCF19_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF19(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF19_SHIFT)) & SARADC_CEOCF0_T0_IEOCF19_MASK)

#define SARADC_CEOCF0_T0_IEOCF20_MASK            (0x100000U)
#define SARADC_CEOCF0_T0_IEOCF20_SHIFT           (20U)
#define SARADC_CEOCF0_T0_IEOCF20_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF20(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF20_SHIFT)) & SARADC_CEOCF0_T0_IEOCF20_MASK)

#define SARADC_CEOCF0_T0_IEOCF21_MASK            (0x200000U)
#define SARADC_CEOCF0_T0_IEOCF21_SHIFT           (21U)
#define SARADC_CEOCF0_T0_IEOCF21_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF21(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF21_SHIFT)) & SARADC_CEOCF0_T0_IEOCF21_MASK)

#define SARADC_CEOCF0_T0_IEOCF22_MASK            (0x400000U)
#define SARADC_CEOCF0_T0_IEOCF22_SHIFT           (22U)
#define SARADC_CEOCF0_T0_IEOCF22_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF22(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF22_SHIFT)) & SARADC_CEOCF0_T0_IEOCF22_MASK)

#define SARADC_CEOCF0_T0_IEOCF23_MASK            (0x800000U)
#define SARADC_CEOCF0_T0_IEOCF23_SHIFT           (23U)
#define SARADC_CEOCF0_T0_IEOCF23_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF23(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF23_SHIFT)) & SARADC_CEOCF0_T0_IEOCF23_MASK)

#define SARADC_CEOCF0_T0_IEOCF24_MASK            (0x1000000U)
#define SARADC_CEOCF0_T0_IEOCF24_SHIFT           (24U)
#define SARADC_CEOCF0_T0_IEOCF24_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF24(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF24_SHIFT)) & SARADC_CEOCF0_T0_IEOCF24_MASK)

#define SARADC_CEOCF0_T0_IEOCF25_MASK            (0x2000000U)
#define SARADC_CEOCF0_T0_IEOCF25_SHIFT           (25U)
#define SARADC_CEOCF0_T0_IEOCF25_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF25(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF25_SHIFT)) & SARADC_CEOCF0_T0_IEOCF25_MASK)

#define SARADC_CEOCF0_T0_IEOCF26_MASK            (0x4000000U)
#define SARADC_CEOCF0_T0_IEOCF26_SHIFT           (26U)
#define SARADC_CEOCF0_T0_IEOCF26_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF26(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF26_SHIFT)) & SARADC_CEOCF0_T0_IEOCF26_MASK)

#define SARADC_CEOCF0_T0_IEOCF27_MASK            (0x8000000U)
#define SARADC_CEOCF0_T0_IEOCF27_SHIFT           (27U)
#define SARADC_CEOCF0_T0_IEOCF27_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF27(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF27_SHIFT)) & SARADC_CEOCF0_T0_IEOCF27_MASK)

#define SARADC_CEOCF0_T0_IEOCF28_MASK            (0x10000000U)
#define SARADC_CEOCF0_T0_IEOCF28_SHIFT           (28U)
#define SARADC_CEOCF0_T0_IEOCF28_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF28(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF28_SHIFT)) & SARADC_CEOCF0_T0_IEOCF28_MASK)

#define SARADC_CEOCF0_T0_IEOCF29_MASK            (0x20000000U)
#define SARADC_CEOCF0_T0_IEOCF29_SHIFT           (29U)
#define SARADC_CEOCF0_T0_IEOCF29_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF29(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF29_SHIFT)) & SARADC_CEOCF0_T0_IEOCF29_MASK)

#define SARADC_CEOCF0_T0_IEOCF30_MASK            (0x40000000U)
#define SARADC_CEOCF0_T0_IEOCF30_SHIFT           (30U)
#define SARADC_CEOCF0_T0_IEOCF30_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF30(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF30_SHIFT)) & SARADC_CEOCF0_T0_IEOCF30_MASK)

#define SARADC_CEOCF0_T0_IEOCF31_MASK            (0x80000000U)
#define SARADC_CEOCF0_T0_IEOCF31_SHIFT           (31U)
#define SARADC_CEOCF0_T0_IEOCF31_WIDTH           (1U)
#define SARADC_CEOCF0_T0_IEOCF31(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF0_T0_IEOCF31_SHIFT)) & SARADC_CEOCF0_T0_IEOCF31_MASK)
/*! @} */

/*! @name CEOCF1 - Channel End of Conversion Flag for Type 1 */
/*! @{ */

#define SARADC_CEOCF1_T1_IEOCF0_MASK             (0x1U)
#define SARADC_CEOCF1_T1_IEOCF0_SHIFT            (0U)
#define SARADC_CEOCF1_T1_IEOCF0_WIDTH            (1U)
#define SARADC_CEOCF1_T1_IEOCF0(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF0_SHIFT)) & SARADC_CEOCF1_T1_IEOCF0_MASK)

#define SARADC_CEOCF1_T1_IEOCF1_MASK             (0x2U)
#define SARADC_CEOCF1_T1_IEOCF1_SHIFT            (1U)
#define SARADC_CEOCF1_T1_IEOCF1_WIDTH            (1U)
#define SARADC_CEOCF1_T1_IEOCF1(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF1_SHIFT)) & SARADC_CEOCF1_T1_IEOCF1_MASK)

#define SARADC_CEOCF1_T1_IEOCF2_MASK             (0x4U)
#define SARADC_CEOCF1_T1_IEOCF2_SHIFT            (2U)
#define SARADC_CEOCF1_T1_IEOCF2_WIDTH            (1U)
#define SARADC_CEOCF1_T1_IEOCF2(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF2_SHIFT)) & SARADC_CEOCF1_T1_IEOCF2_MASK)

#define SARADC_CEOCF1_T1_IEOCF3_MASK             (0x8U)
#define SARADC_CEOCF1_T1_IEOCF3_SHIFT            (3U)
#define SARADC_CEOCF1_T1_IEOCF3_WIDTH            (1U)
#define SARADC_CEOCF1_T1_IEOCF3(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF3_SHIFT)) & SARADC_CEOCF1_T1_IEOCF3_MASK)

#define SARADC_CEOCF1_T1_IEOCF4_MASK             (0x10U)
#define SARADC_CEOCF1_T1_IEOCF4_SHIFT            (4U)
#define SARADC_CEOCF1_T1_IEOCF4_WIDTH            (1U)
#define SARADC_CEOCF1_T1_IEOCF4(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF4_SHIFT)) & SARADC_CEOCF1_T1_IEOCF4_MASK)

#define SARADC_CEOCF1_T1_IEOCF5_MASK             (0x20U)
#define SARADC_CEOCF1_T1_IEOCF5_SHIFT            (5U)
#define SARADC_CEOCF1_T1_IEOCF5_WIDTH            (1U)
#define SARADC_CEOCF1_T1_IEOCF5(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF5_SHIFT)) & SARADC_CEOCF1_T1_IEOCF5_MASK)

#define SARADC_CEOCF1_T1_IEOCF6_MASK             (0x40U)
#define SARADC_CEOCF1_T1_IEOCF6_SHIFT            (6U)
#define SARADC_CEOCF1_T1_IEOCF6_WIDTH            (1U)
#define SARADC_CEOCF1_T1_IEOCF6(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF6_SHIFT)) & SARADC_CEOCF1_T1_IEOCF6_MASK)

#define SARADC_CEOCF1_T1_IEOCF7_MASK             (0x80U)
#define SARADC_CEOCF1_T1_IEOCF7_SHIFT            (7U)
#define SARADC_CEOCF1_T1_IEOCF7_WIDTH            (1U)
#define SARADC_CEOCF1_T1_IEOCF7(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF7_SHIFT)) & SARADC_CEOCF1_T1_IEOCF7_MASK)

#define SARADC_CEOCF1_T1_IEOCF8_MASK             (0x100U)
#define SARADC_CEOCF1_T1_IEOCF8_SHIFT            (8U)
#define SARADC_CEOCF1_T1_IEOCF8_WIDTH            (1U)
#define SARADC_CEOCF1_T1_IEOCF8(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF8_SHIFT)) & SARADC_CEOCF1_T1_IEOCF8_MASK)

#define SARADC_CEOCF1_T1_IEOCF9_MASK             (0x200U)
#define SARADC_CEOCF1_T1_IEOCF9_SHIFT            (9U)
#define SARADC_CEOCF1_T1_IEOCF9_WIDTH            (1U)
#define SARADC_CEOCF1_T1_IEOCF9(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF9_SHIFT)) & SARADC_CEOCF1_T1_IEOCF9_MASK)

#define SARADC_CEOCF1_T1_IEOCF10_MASK            (0x400U)
#define SARADC_CEOCF1_T1_IEOCF10_SHIFT           (10U)
#define SARADC_CEOCF1_T1_IEOCF10_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF10(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF10_SHIFT)) & SARADC_CEOCF1_T1_IEOCF10_MASK)

#define SARADC_CEOCF1_T1_IEOCF16_MASK            (0x10000U)
#define SARADC_CEOCF1_T1_IEOCF16_SHIFT           (16U)
#define SARADC_CEOCF1_T1_IEOCF16_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF16(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF16_SHIFT)) & SARADC_CEOCF1_T1_IEOCF16_MASK)

#define SARADC_CEOCF1_T1_IEOCF17_MASK            (0x20000U)
#define SARADC_CEOCF1_T1_IEOCF17_SHIFT           (17U)
#define SARADC_CEOCF1_T1_IEOCF17_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF17(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF17_SHIFT)) & SARADC_CEOCF1_T1_IEOCF17_MASK)

#define SARADC_CEOCF1_T1_IEOCF18_MASK            (0x40000U)
#define SARADC_CEOCF1_T1_IEOCF18_SHIFT           (18U)
#define SARADC_CEOCF1_T1_IEOCF18_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF18(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF18_SHIFT)) & SARADC_CEOCF1_T1_IEOCF18_MASK)

#define SARADC_CEOCF1_T1_IEOCF19_MASK            (0x80000U)
#define SARADC_CEOCF1_T1_IEOCF19_SHIFT           (19U)
#define SARADC_CEOCF1_T1_IEOCF19_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF19(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF19_SHIFT)) & SARADC_CEOCF1_T1_IEOCF19_MASK)

#define SARADC_CEOCF1_T1_IEOCF20_MASK            (0x100000U)
#define SARADC_CEOCF1_T1_IEOCF20_SHIFT           (20U)
#define SARADC_CEOCF1_T1_IEOCF20_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF20(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF20_SHIFT)) & SARADC_CEOCF1_T1_IEOCF20_MASK)

#define SARADC_CEOCF1_T1_IEOCF21_MASK            (0x200000U)
#define SARADC_CEOCF1_T1_IEOCF21_SHIFT           (21U)
#define SARADC_CEOCF1_T1_IEOCF21_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF21(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF21_SHIFT)) & SARADC_CEOCF1_T1_IEOCF21_MASK)

#define SARADC_CEOCF1_T1_IEOCF22_MASK            (0x400000U)
#define SARADC_CEOCF1_T1_IEOCF22_SHIFT           (22U)
#define SARADC_CEOCF1_T1_IEOCF22_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF22(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF22_SHIFT)) & SARADC_CEOCF1_T1_IEOCF22_MASK)

#define SARADC_CEOCF1_T1_IEOCF23_MASK            (0x800000U)
#define SARADC_CEOCF1_T1_IEOCF23_SHIFT           (23U)
#define SARADC_CEOCF1_T1_IEOCF23_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF23(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF23_SHIFT)) & SARADC_CEOCF1_T1_IEOCF23_MASK)

#define SARADC_CEOCF1_T1_IEOCF24_MASK            (0x1000000U)
#define SARADC_CEOCF1_T1_IEOCF24_SHIFT           (24U)
#define SARADC_CEOCF1_T1_IEOCF24_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF24(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF24_SHIFT)) & SARADC_CEOCF1_T1_IEOCF24_MASK)

#define SARADC_CEOCF1_T1_IEOCF25_MASK            (0x2000000U)
#define SARADC_CEOCF1_T1_IEOCF25_SHIFT           (25U)
#define SARADC_CEOCF1_T1_IEOCF25_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF25(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF25_SHIFT)) & SARADC_CEOCF1_T1_IEOCF25_MASK)

#define SARADC_CEOCF1_T1_IEOCF26_MASK            (0x4000000U)
#define SARADC_CEOCF1_T1_IEOCF26_SHIFT           (26U)
#define SARADC_CEOCF1_T1_IEOCF26_WIDTH           (1U)
#define SARADC_CEOCF1_T1_IEOCF26(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF1_T1_IEOCF26_SHIFT)) & SARADC_CEOCF1_T1_IEOCF26_MASK)
/*! @} */

/*! @name CEOCF2 - Channel End of Conversion Flag for Type 2 */
/*! @{ */

#define SARADC_CEOCF2_T2_IEOCF0_MASK             (0x1U)
#define SARADC_CEOCF2_T2_IEOCF0_SHIFT            (0U)
#define SARADC_CEOCF2_T2_IEOCF0_WIDTH            (1U)
#define SARADC_CEOCF2_T2_IEOCF0(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF0_SHIFT)) & SARADC_CEOCF2_T2_IEOCF0_MASK)

#define SARADC_CEOCF2_T2_IEOCF1_MASK             (0x2U)
#define SARADC_CEOCF2_T2_IEOCF1_SHIFT            (1U)
#define SARADC_CEOCF2_T2_IEOCF1_WIDTH            (1U)
#define SARADC_CEOCF2_T2_IEOCF1(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF1_SHIFT)) & SARADC_CEOCF2_T2_IEOCF1_MASK)

#define SARADC_CEOCF2_T2_IEOCF2_MASK             (0x4U)
#define SARADC_CEOCF2_T2_IEOCF2_SHIFT            (2U)
#define SARADC_CEOCF2_T2_IEOCF2_WIDTH            (1U)
#define SARADC_CEOCF2_T2_IEOCF2(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF2_SHIFT)) & SARADC_CEOCF2_T2_IEOCF2_MASK)

#define SARADC_CEOCF2_T2_IEOCF3_MASK             (0x8U)
#define SARADC_CEOCF2_T2_IEOCF3_SHIFT            (3U)
#define SARADC_CEOCF2_T2_IEOCF3_WIDTH            (1U)
#define SARADC_CEOCF2_T2_IEOCF3(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF3_SHIFT)) & SARADC_CEOCF2_T2_IEOCF3_MASK)

#define SARADC_CEOCF2_T2_IEOCF4_MASK             (0x10U)
#define SARADC_CEOCF2_T2_IEOCF4_SHIFT            (4U)
#define SARADC_CEOCF2_T2_IEOCF4_WIDTH            (1U)
#define SARADC_CEOCF2_T2_IEOCF4(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF4_SHIFT)) & SARADC_CEOCF2_T2_IEOCF4_MASK)

#define SARADC_CEOCF2_T2_IEOCF5_MASK             (0x20U)
#define SARADC_CEOCF2_T2_IEOCF5_SHIFT            (5U)
#define SARADC_CEOCF2_T2_IEOCF5_WIDTH            (1U)
#define SARADC_CEOCF2_T2_IEOCF5(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF5_SHIFT)) & SARADC_CEOCF2_T2_IEOCF5_MASK)

#define SARADC_CEOCF2_T2_IEOCF6_MASK             (0x40U)
#define SARADC_CEOCF2_T2_IEOCF6_SHIFT            (6U)
#define SARADC_CEOCF2_T2_IEOCF6_WIDTH            (1U)
#define SARADC_CEOCF2_T2_IEOCF6(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF6_SHIFT)) & SARADC_CEOCF2_T2_IEOCF6_MASK)

#define SARADC_CEOCF2_T2_IEOCF7_MASK             (0x80U)
#define SARADC_CEOCF2_T2_IEOCF7_SHIFT            (7U)
#define SARADC_CEOCF2_T2_IEOCF7_WIDTH            (1U)
#define SARADC_CEOCF2_T2_IEOCF7(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF7_SHIFT)) & SARADC_CEOCF2_T2_IEOCF7_MASK)

#define SARADC_CEOCF2_T2_IEOCF8_MASK             (0x100U)
#define SARADC_CEOCF2_T2_IEOCF8_SHIFT            (8U)
#define SARADC_CEOCF2_T2_IEOCF8_WIDTH            (1U)
#define SARADC_CEOCF2_T2_IEOCF8(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF8_SHIFT)) & SARADC_CEOCF2_T2_IEOCF8_MASK)

#define SARADC_CEOCF2_T2_IEOCF9_MASK             (0x200U)
#define SARADC_CEOCF2_T2_IEOCF9_SHIFT            (9U)
#define SARADC_CEOCF2_T2_IEOCF9_WIDTH            (1U)
#define SARADC_CEOCF2_T2_IEOCF9(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF9_SHIFT)) & SARADC_CEOCF2_T2_IEOCF9_MASK)

#define SARADC_CEOCF2_T2_IEOCF10_MASK            (0x400U)
#define SARADC_CEOCF2_T2_IEOCF10_SHIFT           (10U)
#define SARADC_CEOCF2_T2_IEOCF10_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF10(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF10_SHIFT)) & SARADC_CEOCF2_T2_IEOCF10_MASK)

#define SARADC_CEOCF2_T2_IEOCF11_MASK            (0x800U)
#define SARADC_CEOCF2_T2_IEOCF11_SHIFT           (11U)
#define SARADC_CEOCF2_T2_IEOCF11_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF11(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF11_SHIFT)) & SARADC_CEOCF2_T2_IEOCF11_MASK)

#define SARADC_CEOCF2_T2_IEOCF12_MASK            (0x1000U)
#define SARADC_CEOCF2_T2_IEOCF12_SHIFT           (12U)
#define SARADC_CEOCF2_T2_IEOCF12_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF12(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF12_SHIFT)) & SARADC_CEOCF2_T2_IEOCF12_MASK)

#define SARADC_CEOCF2_T2_IEOCF13_MASK            (0x2000U)
#define SARADC_CEOCF2_T2_IEOCF13_SHIFT           (13U)
#define SARADC_CEOCF2_T2_IEOCF13_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF13(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF13_SHIFT)) & SARADC_CEOCF2_T2_IEOCF13_MASK)

#define SARADC_CEOCF2_T2_IEOCF14_MASK            (0x4000U)
#define SARADC_CEOCF2_T2_IEOCF14_SHIFT           (14U)
#define SARADC_CEOCF2_T2_IEOCF14_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF14(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF14_SHIFT)) & SARADC_CEOCF2_T2_IEOCF14_MASK)

#define SARADC_CEOCF2_T2_IEOCF15_MASK            (0x8000U)
#define SARADC_CEOCF2_T2_IEOCF15_SHIFT           (15U)
#define SARADC_CEOCF2_T2_IEOCF15_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF15(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF15_SHIFT)) & SARADC_CEOCF2_T2_IEOCF15_MASK)

#define SARADC_CEOCF2_T2_IEOCF16_MASK            (0x10000U)
#define SARADC_CEOCF2_T2_IEOCF16_SHIFT           (16U)
#define SARADC_CEOCF2_T2_IEOCF16_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF16(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF16_SHIFT)) & SARADC_CEOCF2_T2_IEOCF16_MASK)

#define SARADC_CEOCF2_T2_IEOCF17_MASK            (0x20000U)
#define SARADC_CEOCF2_T2_IEOCF17_SHIFT           (17U)
#define SARADC_CEOCF2_T2_IEOCF17_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF17(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF17_SHIFT)) & SARADC_CEOCF2_T2_IEOCF17_MASK)

#define SARADC_CEOCF2_T2_IEOCF18_MASK            (0x40000U)
#define SARADC_CEOCF2_T2_IEOCF18_SHIFT           (18U)
#define SARADC_CEOCF2_T2_IEOCF18_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF18(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF18_SHIFT)) & SARADC_CEOCF2_T2_IEOCF18_MASK)

#define SARADC_CEOCF2_T2_IEOCF19_MASK            (0x80000U)
#define SARADC_CEOCF2_T2_IEOCF19_SHIFT           (19U)
#define SARADC_CEOCF2_T2_IEOCF19_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF19(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF19_SHIFT)) & SARADC_CEOCF2_T2_IEOCF19_MASK)

#define SARADC_CEOCF2_T2_IEOCF20_MASK            (0x100000U)
#define SARADC_CEOCF2_T2_IEOCF20_SHIFT           (20U)
#define SARADC_CEOCF2_T2_IEOCF20_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF20(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF20_SHIFT)) & SARADC_CEOCF2_T2_IEOCF20_MASK)

#define SARADC_CEOCF2_T2_IEOCF21_MASK            (0x200000U)
#define SARADC_CEOCF2_T2_IEOCF21_SHIFT           (21U)
#define SARADC_CEOCF2_T2_IEOCF21_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF21(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF21_SHIFT)) & SARADC_CEOCF2_T2_IEOCF21_MASK)

#define SARADC_CEOCF2_T2_IEOCF22_MASK            (0x400000U)
#define SARADC_CEOCF2_T2_IEOCF22_SHIFT           (22U)
#define SARADC_CEOCF2_T2_IEOCF22_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF22(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF22_SHIFT)) & SARADC_CEOCF2_T2_IEOCF22_MASK)

#define SARADC_CEOCF2_T2_IEOCF23_MASK            (0x800000U)
#define SARADC_CEOCF2_T2_IEOCF23_SHIFT           (23U)
#define SARADC_CEOCF2_T2_IEOCF23_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF23(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF23_SHIFT)) & SARADC_CEOCF2_T2_IEOCF23_MASK)

#define SARADC_CEOCF2_T2_IEOCF24_MASK            (0x1000000U)
#define SARADC_CEOCF2_T2_IEOCF24_SHIFT           (24U)
#define SARADC_CEOCF2_T2_IEOCF24_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF24(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF24_SHIFT)) & SARADC_CEOCF2_T2_IEOCF24_MASK)

#define SARADC_CEOCF2_T2_IEOCF25_MASK            (0x2000000U)
#define SARADC_CEOCF2_T2_IEOCF25_SHIFT           (25U)
#define SARADC_CEOCF2_T2_IEOCF25_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF25(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF25_SHIFT)) & SARADC_CEOCF2_T2_IEOCF25_MASK)

#define SARADC_CEOCF2_T2_IEOCF26_MASK            (0x4000000U)
#define SARADC_CEOCF2_T2_IEOCF26_SHIFT           (26U)
#define SARADC_CEOCF2_T2_IEOCF26_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF26(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF26_SHIFT)) & SARADC_CEOCF2_T2_IEOCF26_MASK)

#define SARADC_CEOCF2_T2_IEOCF27_MASK            (0x8000000U)
#define SARADC_CEOCF2_T2_IEOCF27_SHIFT           (27U)
#define SARADC_CEOCF2_T2_IEOCF27_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF27(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF27_SHIFT)) & SARADC_CEOCF2_T2_IEOCF27_MASK)

#define SARADC_CEOCF2_T2_IEOCF28_MASK            (0x10000000U)
#define SARADC_CEOCF2_T2_IEOCF28_SHIFT           (28U)
#define SARADC_CEOCF2_T2_IEOCF28_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF28(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF28_SHIFT)) & SARADC_CEOCF2_T2_IEOCF28_MASK)

#define SARADC_CEOCF2_T2_IEOCF29_MASK            (0x20000000U)
#define SARADC_CEOCF2_T2_IEOCF29_SHIFT           (29U)
#define SARADC_CEOCF2_T2_IEOCF29_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF29(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF29_SHIFT)) & SARADC_CEOCF2_T2_IEOCF29_MASK)

#define SARADC_CEOCF2_T2_IEOCF30_MASK            (0x40000000U)
#define SARADC_CEOCF2_T2_IEOCF30_SHIFT           (30U)
#define SARADC_CEOCF2_T2_IEOCF30_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF30(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF30_SHIFT)) & SARADC_CEOCF2_T2_IEOCF30_MASK)

#define SARADC_CEOCF2_T2_IEOCF31_MASK            (0x80000000U)
#define SARADC_CEOCF2_T2_IEOCF31_SHIFT           (31U)
#define SARADC_CEOCF2_T2_IEOCF31_WIDTH           (1U)
#define SARADC_CEOCF2_T2_IEOCF31(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_CEOCF2_T2_IEOCF31_SHIFT)) & SARADC_CEOCF2_T2_IEOCF31_MASK)
/*! @} */

/*! @name IM - Interrupt Mask */
/*! @{ */

#define SARADC_IM_MSKECH_MASK                    (0x1U)
#define SARADC_IM_MSKECH_SHIFT                   (0U)
#define SARADC_IM_MSKECH_WIDTH                   (1U)
#define SARADC_IM_MSKECH(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_IM_MSKECH_SHIFT)) & SARADC_IM_MSKECH_MASK)

#define SARADC_IM_MSKEOC_MASK                    (0x2U)
#define SARADC_IM_MSKEOC_SHIFT                   (1U)
#define SARADC_IM_MSKEOC_WIDTH                   (1U)
#define SARADC_IM_MSKEOC(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_IM_MSKEOC_SHIFT)) & SARADC_IM_MSKEOC_MASK)

#define SARADC_IM_MSKJECH_MASK                   (0x4U)
#define SARADC_IM_MSKJECH_SHIFT                  (2U)
#define SARADC_IM_MSKJECH_WIDTH                  (1U)
#define SARADC_IM_MSKJECH(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_IM_MSKJECH_SHIFT)) & SARADC_IM_MSKJECH_MASK)

#define SARADC_IM_MSKJEOC_MASK                   (0x8U)
#define SARADC_IM_MSKJEOC_SHIFT                  (3U)
#define SARADC_IM_MSKJEOC_WIDTH                  (1U)
#define SARADC_IM_MSKJEOC(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_IM_MSKJEOC_SHIFT)) & SARADC_IM_MSKJEOC_MASK)

#define SARADC_IM_MSKEOBCTU_MASK                 (0x10U)
#define SARADC_IM_MSKEOBCTU_SHIFT                (4U)
#define SARADC_IM_MSKEOBCTU_WIDTH                (1U)
#define SARADC_IM_MSKEOBCTU(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_IM_MSKEOBCTU_SHIFT)) & SARADC_IM_MSKEOBCTU_MASK)
/*! @} */

/*! @name CIM0 - EOC Interrupt Enable for Type 0 */
/*! @{ */

#define SARADC_CIM0_T0EOCIEN0_MASK               (0x1U)
#define SARADC_CIM0_T0EOCIEN0_SHIFT              (0U)
#define SARADC_CIM0_T0EOCIEN0_WIDTH              (1U)
#define SARADC_CIM0_T0EOCIEN0(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN0_SHIFT)) & SARADC_CIM0_T0EOCIEN0_MASK)

#define SARADC_CIM0_T0EOCIEN1_MASK               (0x2U)
#define SARADC_CIM0_T0EOCIEN1_SHIFT              (1U)
#define SARADC_CIM0_T0EOCIEN1_WIDTH              (1U)
#define SARADC_CIM0_T0EOCIEN1(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN1_SHIFT)) & SARADC_CIM0_T0EOCIEN1_MASK)

#define SARADC_CIM0_T0EOCIEN2_MASK               (0x4U)
#define SARADC_CIM0_T0EOCIEN2_SHIFT              (2U)
#define SARADC_CIM0_T0EOCIEN2_WIDTH              (1U)
#define SARADC_CIM0_T0EOCIEN2(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN2_SHIFT)) & SARADC_CIM0_T0EOCIEN2_MASK)

#define SARADC_CIM0_T0EOCIEN3_MASK               (0x8U)
#define SARADC_CIM0_T0EOCIEN3_SHIFT              (3U)
#define SARADC_CIM0_T0EOCIEN3_WIDTH              (1U)
#define SARADC_CIM0_T0EOCIEN3(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN3_SHIFT)) & SARADC_CIM0_T0EOCIEN3_MASK)

#define SARADC_CIM0_T0EOCIEN4_MASK               (0x10U)
#define SARADC_CIM0_T0EOCIEN4_SHIFT              (4U)
#define SARADC_CIM0_T0EOCIEN4_WIDTH              (1U)
#define SARADC_CIM0_T0EOCIEN4(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN4_SHIFT)) & SARADC_CIM0_T0EOCIEN4_MASK)

#define SARADC_CIM0_T0EOCIEN5_MASK               (0x20U)
#define SARADC_CIM0_T0EOCIEN5_SHIFT              (5U)
#define SARADC_CIM0_T0EOCIEN5_WIDTH              (1U)
#define SARADC_CIM0_T0EOCIEN5(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN5_SHIFT)) & SARADC_CIM0_T0EOCIEN5_MASK)

#define SARADC_CIM0_T0EOCIEN6_MASK               (0x40U)
#define SARADC_CIM0_T0EOCIEN6_SHIFT              (6U)
#define SARADC_CIM0_T0EOCIEN6_WIDTH              (1U)
#define SARADC_CIM0_T0EOCIEN6(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN6_SHIFT)) & SARADC_CIM0_T0EOCIEN6_MASK)

#define SARADC_CIM0_T0EOCIEN7_MASK               (0x80U)
#define SARADC_CIM0_T0EOCIEN7_SHIFT              (7U)
#define SARADC_CIM0_T0EOCIEN7_WIDTH              (1U)
#define SARADC_CIM0_T0EOCIEN7(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN7_SHIFT)) & SARADC_CIM0_T0EOCIEN7_MASK)

#define SARADC_CIM0_T0EOCIEN8_MASK               (0x100U)
#define SARADC_CIM0_T0EOCIEN8_SHIFT              (8U)
#define SARADC_CIM0_T0EOCIEN8_WIDTH              (1U)
#define SARADC_CIM0_T0EOCIEN8(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN8_SHIFT)) & SARADC_CIM0_T0EOCIEN8_MASK)

#define SARADC_CIM0_T0EOCIEN9_MASK               (0x200U)
#define SARADC_CIM0_T0EOCIEN9_SHIFT              (9U)
#define SARADC_CIM0_T0EOCIEN9_WIDTH              (1U)
#define SARADC_CIM0_T0EOCIEN9(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN9_SHIFT)) & SARADC_CIM0_T0EOCIEN9_MASK)

#define SARADC_CIM0_T0EOCIEN10_MASK              (0x400U)
#define SARADC_CIM0_T0EOCIEN10_SHIFT             (10U)
#define SARADC_CIM0_T0EOCIEN10_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN10(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN10_SHIFT)) & SARADC_CIM0_T0EOCIEN10_MASK)

#define SARADC_CIM0_T0EOCIEN11_MASK              (0x800U)
#define SARADC_CIM0_T0EOCIEN11_SHIFT             (11U)
#define SARADC_CIM0_T0EOCIEN11_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN11(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN11_SHIFT)) & SARADC_CIM0_T0EOCIEN11_MASK)

#define SARADC_CIM0_T0EOCIEN12_MASK              (0x1000U)
#define SARADC_CIM0_T0EOCIEN12_SHIFT             (12U)
#define SARADC_CIM0_T0EOCIEN12_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN12(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN12_SHIFT)) & SARADC_CIM0_T0EOCIEN12_MASK)

#define SARADC_CIM0_T0EOCIEN13_MASK              (0x2000U)
#define SARADC_CIM0_T0EOCIEN13_SHIFT             (13U)
#define SARADC_CIM0_T0EOCIEN13_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN13(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN13_SHIFT)) & SARADC_CIM0_T0EOCIEN13_MASK)

#define SARADC_CIM0_T0EOCIEN14_MASK              (0x4000U)
#define SARADC_CIM0_T0EOCIEN14_SHIFT             (14U)
#define SARADC_CIM0_T0EOCIEN14_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN14(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN14_SHIFT)) & SARADC_CIM0_T0EOCIEN14_MASK)

#define SARADC_CIM0_T0EOCIEN15_MASK              (0x8000U)
#define SARADC_CIM0_T0EOCIEN15_SHIFT             (15U)
#define SARADC_CIM0_T0EOCIEN15_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN15(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN15_SHIFT)) & SARADC_CIM0_T0EOCIEN15_MASK)

#define SARADC_CIM0_T0EOCIEN16_MASK              (0x10000U)
#define SARADC_CIM0_T0EOCIEN16_SHIFT             (16U)
#define SARADC_CIM0_T0EOCIEN16_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN16(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN16_SHIFT)) & SARADC_CIM0_T0EOCIEN16_MASK)

#define SARADC_CIM0_T0EOCIEN17_MASK              (0x20000U)
#define SARADC_CIM0_T0EOCIEN17_SHIFT             (17U)
#define SARADC_CIM0_T0EOCIEN17_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN17(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN17_SHIFT)) & SARADC_CIM0_T0EOCIEN17_MASK)

#define SARADC_CIM0_T0EOCIEN18_MASK              (0x40000U)
#define SARADC_CIM0_T0EOCIEN18_SHIFT             (18U)
#define SARADC_CIM0_T0EOCIEN18_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN18(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN18_SHIFT)) & SARADC_CIM0_T0EOCIEN18_MASK)

#define SARADC_CIM0_T0EOCIEN19_MASK              (0x80000U)
#define SARADC_CIM0_T0EOCIEN19_SHIFT             (19U)
#define SARADC_CIM0_T0EOCIEN19_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN19(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN19_SHIFT)) & SARADC_CIM0_T0EOCIEN19_MASK)

#define SARADC_CIM0_T0EOCIEN20_MASK              (0x100000U)
#define SARADC_CIM0_T0EOCIEN20_SHIFT             (20U)
#define SARADC_CIM0_T0EOCIEN20_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN20(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN20_SHIFT)) & SARADC_CIM0_T0EOCIEN20_MASK)

#define SARADC_CIM0_T0EOCIEN21_MASK              (0x200000U)
#define SARADC_CIM0_T0EOCIEN21_SHIFT             (21U)
#define SARADC_CIM0_T0EOCIEN21_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN21(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN21_SHIFT)) & SARADC_CIM0_T0EOCIEN21_MASK)

#define SARADC_CIM0_T0EOCIEN22_MASK              (0x400000U)
#define SARADC_CIM0_T0EOCIEN22_SHIFT             (22U)
#define SARADC_CIM0_T0EOCIEN22_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN22(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN22_SHIFT)) & SARADC_CIM0_T0EOCIEN22_MASK)

#define SARADC_CIM0_T0EOCIEN23_MASK              (0x800000U)
#define SARADC_CIM0_T0EOCIEN23_SHIFT             (23U)
#define SARADC_CIM0_T0EOCIEN23_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN23(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN23_SHIFT)) & SARADC_CIM0_T0EOCIEN23_MASK)

#define SARADC_CIM0_T0EOCIEN24_MASK              (0x1000000U)
#define SARADC_CIM0_T0EOCIEN24_SHIFT             (24U)
#define SARADC_CIM0_T0EOCIEN24_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN24(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN24_SHIFT)) & SARADC_CIM0_T0EOCIEN24_MASK)

#define SARADC_CIM0_T0EOCIEN25_MASK              (0x2000000U)
#define SARADC_CIM0_T0EOCIEN25_SHIFT             (25U)
#define SARADC_CIM0_T0EOCIEN25_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN25(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN25_SHIFT)) & SARADC_CIM0_T0EOCIEN25_MASK)

#define SARADC_CIM0_T0EOCIEN26_MASK              (0x4000000U)
#define SARADC_CIM0_T0EOCIEN26_SHIFT             (26U)
#define SARADC_CIM0_T0EOCIEN26_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN26(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN26_SHIFT)) & SARADC_CIM0_T0EOCIEN26_MASK)

#define SARADC_CIM0_T0EOCIEN27_MASK              (0x8000000U)
#define SARADC_CIM0_T0EOCIEN27_SHIFT             (27U)
#define SARADC_CIM0_T0EOCIEN27_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN27(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN27_SHIFT)) & SARADC_CIM0_T0EOCIEN27_MASK)

#define SARADC_CIM0_T0EOCIEN28_MASK              (0x10000000U)
#define SARADC_CIM0_T0EOCIEN28_SHIFT             (28U)
#define SARADC_CIM0_T0EOCIEN28_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN28(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN28_SHIFT)) & SARADC_CIM0_T0EOCIEN28_MASK)

#define SARADC_CIM0_T0EOCIEN29_MASK              (0x20000000U)
#define SARADC_CIM0_T0EOCIEN29_SHIFT             (29U)
#define SARADC_CIM0_T0EOCIEN29_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN29(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN29_SHIFT)) & SARADC_CIM0_T0EOCIEN29_MASK)

#define SARADC_CIM0_T0EOCIEN30_MASK              (0x40000000U)
#define SARADC_CIM0_T0EOCIEN30_SHIFT             (30U)
#define SARADC_CIM0_T0EOCIEN30_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN30(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN30_SHIFT)) & SARADC_CIM0_T0EOCIEN30_MASK)

#define SARADC_CIM0_T0EOCIEN31_MASK              (0x80000000U)
#define SARADC_CIM0_T0EOCIEN31_SHIFT             (31U)
#define SARADC_CIM0_T0EOCIEN31_WIDTH             (1U)
#define SARADC_CIM0_T0EOCIEN31(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM0_T0EOCIEN31_SHIFT)) & SARADC_CIM0_T0EOCIEN31_MASK)
/*! @} */

/*! @name CIM1 - EOC Interrupt Enable for Type 1 */
/*! @{ */

#define SARADC_CIM1_T1EOCIEN0_MASK               (0x1U)
#define SARADC_CIM1_T1EOCIEN0_SHIFT              (0U)
#define SARADC_CIM1_T1EOCIEN0_WIDTH              (1U)
#define SARADC_CIM1_T1EOCIEN0(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN0_SHIFT)) & SARADC_CIM1_T1EOCIEN0_MASK)

#define SARADC_CIM1_T1EOCIEN1_MASK               (0x2U)
#define SARADC_CIM1_T1EOCIEN1_SHIFT              (1U)
#define SARADC_CIM1_T1EOCIEN1_WIDTH              (1U)
#define SARADC_CIM1_T1EOCIEN1(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN1_SHIFT)) & SARADC_CIM1_T1EOCIEN1_MASK)

#define SARADC_CIM1_T1EOCIEN2_MASK               (0x4U)
#define SARADC_CIM1_T1EOCIEN2_SHIFT              (2U)
#define SARADC_CIM1_T1EOCIEN2_WIDTH              (1U)
#define SARADC_CIM1_T1EOCIEN2(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN2_SHIFT)) & SARADC_CIM1_T1EOCIEN2_MASK)

#define SARADC_CIM1_T1EOCIEN3_MASK               (0x8U)
#define SARADC_CIM1_T1EOCIEN3_SHIFT              (3U)
#define SARADC_CIM1_T1EOCIEN3_WIDTH              (1U)
#define SARADC_CIM1_T1EOCIEN3(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN3_SHIFT)) & SARADC_CIM1_T1EOCIEN3_MASK)

#define SARADC_CIM1_T1EOCIEN4_MASK               (0x10U)
#define SARADC_CIM1_T1EOCIEN4_SHIFT              (4U)
#define SARADC_CIM1_T1EOCIEN4_WIDTH              (1U)
#define SARADC_CIM1_T1EOCIEN4(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN4_SHIFT)) & SARADC_CIM1_T1EOCIEN4_MASK)

#define SARADC_CIM1_T1EOCIEN5_MASK               (0x20U)
#define SARADC_CIM1_T1EOCIEN5_SHIFT              (5U)
#define SARADC_CIM1_T1EOCIEN5_WIDTH              (1U)
#define SARADC_CIM1_T1EOCIEN5(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN5_SHIFT)) & SARADC_CIM1_T1EOCIEN5_MASK)

#define SARADC_CIM1_T1EOCIEN6_MASK               (0x40U)
#define SARADC_CIM1_T1EOCIEN6_SHIFT              (6U)
#define SARADC_CIM1_T1EOCIEN6_WIDTH              (1U)
#define SARADC_CIM1_T1EOCIEN6(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN6_SHIFT)) & SARADC_CIM1_T1EOCIEN6_MASK)

#define SARADC_CIM1_T1EOCIEN7_MASK               (0x80U)
#define SARADC_CIM1_T1EOCIEN7_SHIFT              (7U)
#define SARADC_CIM1_T1EOCIEN7_WIDTH              (1U)
#define SARADC_CIM1_T1EOCIEN7(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN7_SHIFT)) & SARADC_CIM1_T1EOCIEN7_MASK)

#define SARADC_CIM1_T1EOCIEN8_MASK               (0x100U)
#define SARADC_CIM1_T1EOCIEN8_SHIFT              (8U)
#define SARADC_CIM1_T1EOCIEN8_WIDTH              (1U)
#define SARADC_CIM1_T1EOCIEN8(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN8_SHIFT)) & SARADC_CIM1_T1EOCIEN8_MASK)

#define SARADC_CIM1_T1EOCIEN9_MASK               (0x200U)
#define SARADC_CIM1_T1EOCIEN9_SHIFT              (9U)
#define SARADC_CIM1_T1EOCIEN9_WIDTH              (1U)
#define SARADC_CIM1_T1EOCIEN9(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN9_SHIFT)) & SARADC_CIM1_T1EOCIEN9_MASK)

#define SARADC_CIM1_T1EOCIEN10_MASK              (0x400U)
#define SARADC_CIM1_T1EOCIEN10_SHIFT             (10U)
#define SARADC_CIM1_T1EOCIEN10_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN10(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN10_SHIFT)) & SARADC_CIM1_T1EOCIEN10_MASK)

#define SARADC_CIM1_T1EOCIEN16_MASK              (0x10000U)
#define SARADC_CIM1_T1EOCIEN16_SHIFT             (16U)
#define SARADC_CIM1_T1EOCIEN16_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN16(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN16_SHIFT)) & SARADC_CIM1_T1EOCIEN16_MASK)

#define SARADC_CIM1_T1EOCIEN17_MASK              (0x20000U)
#define SARADC_CIM1_T1EOCIEN17_SHIFT             (17U)
#define SARADC_CIM1_T1EOCIEN17_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN17(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN17_SHIFT)) & SARADC_CIM1_T1EOCIEN17_MASK)

#define SARADC_CIM1_T1EOCIEN18_MASK              (0x40000U)
#define SARADC_CIM1_T1EOCIEN18_SHIFT             (18U)
#define SARADC_CIM1_T1EOCIEN18_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN18(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN18_SHIFT)) & SARADC_CIM1_T1EOCIEN18_MASK)

#define SARADC_CIM1_T1EOCIEN19_MASK              (0x80000U)
#define SARADC_CIM1_T1EOCIEN19_SHIFT             (19U)
#define SARADC_CIM1_T1EOCIEN19_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN19(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN19_SHIFT)) & SARADC_CIM1_T1EOCIEN19_MASK)

#define SARADC_CIM1_T1EOCIEN20_MASK              (0x100000U)
#define SARADC_CIM1_T1EOCIEN20_SHIFT             (20U)
#define SARADC_CIM1_T1EOCIEN20_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN20(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN20_SHIFT)) & SARADC_CIM1_T1EOCIEN20_MASK)

#define SARADC_CIM1_T1EOCIEN21_MASK              (0x200000U)
#define SARADC_CIM1_T1EOCIEN21_SHIFT             (21U)
#define SARADC_CIM1_T1EOCIEN21_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN21(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN21_SHIFT)) & SARADC_CIM1_T1EOCIEN21_MASK)

#define SARADC_CIM1_T1EOCIEN22_MASK              (0x400000U)
#define SARADC_CIM1_T1EOCIEN22_SHIFT             (22U)
#define SARADC_CIM1_T1EOCIEN22_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN22(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN22_SHIFT)) & SARADC_CIM1_T1EOCIEN22_MASK)

#define SARADC_CIM1_T1EOCIEN23_MASK              (0x800000U)
#define SARADC_CIM1_T1EOCIEN23_SHIFT             (23U)
#define SARADC_CIM1_T1EOCIEN23_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN23(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN23_SHIFT)) & SARADC_CIM1_T1EOCIEN23_MASK)

#define SARADC_CIM1_T1EOCIEN24_MASK              (0x1000000U)
#define SARADC_CIM1_T1EOCIEN24_SHIFT             (24U)
#define SARADC_CIM1_T1EOCIEN24_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN24(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN24_SHIFT)) & SARADC_CIM1_T1EOCIEN24_MASK)

#define SARADC_CIM1_T1EOCIEN25_MASK              (0x2000000U)
#define SARADC_CIM1_T1EOCIEN25_SHIFT             (25U)
#define SARADC_CIM1_T1EOCIEN25_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN25(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN25_SHIFT)) & SARADC_CIM1_T1EOCIEN25_MASK)

#define SARADC_CIM1_T1EOCIEN26_MASK              (0x4000000U)
#define SARADC_CIM1_T1EOCIEN26_SHIFT             (26U)
#define SARADC_CIM1_T1EOCIEN26_WIDTH             (1U)
#define SARADC_CIM1_T1EOCIEN26(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM1_T1EOCIEN26_SHIFT)) & SARADC_CIM1_T1EOCIEN26_MASK)
/*! @} */

/*! @name CIM2 - EOC Interrupt Enable for Type 2 */
/*! @{ */

#define SARADC_CIM2_T1EOCIEN0_MASK               (0x1U)
#define SARADC_CIM2_T1EOCIEN0_SHIFT              (0U)
#define SARADC_CIM2_T1EOCIEN0_WIDTH              (1U)
#define SARADC_CIM2_T1EOCIEN0(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN0_SHIFT)) & SARADC_CIM2_T1EOCIEN0_MASK)

#define SARADC_CIM2_T1EOCIEN1_MASK               (0x2U)
#define SARADC_CIM2_T1EOCIEN1_SHIFT              (1U)
#define SARADC_CIM2_T1EOCIEN1_WIDTH              (1U)
#define SARADC_CIM2_T1EOCIEN1(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN1_SHIFT)) & SARADC_CIM2_T1EOCIEN1_MASK)

#define SARADC_CIM2_T1EOCIEN2_MASK               (0x4U)
#define SARADC_CIM2_T1EOCIEN2_SHIFT              (2U)
#define SARADC_CIM2_T1EOCIEN2_WIDTH              (1U)
#define SARADC_CIM2_T1EOCIEN2(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN2_SHIFT)) & SARADC_CIM2_T1EOCIEN2_MASK)

#define SARADC_CIM2_T1EOCIEN3_MASK               (0x8U)
#define SARADC_CIM2_T1EOCIEN3_SHIFT              (3U)
#define SARADC_CIM2_T1EOCIEN3_WIDTH              (1U)
#define SARADC_CIM2_T1EOCIEN3(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN3_SHIFT)) & SARADC_CIM2_T1EOCIEN3_MASK)

#define SARADC_CIM2_T1EOCIEN4_MASK               (0x10U)
#define SARADC_CIM2_T1EOCIEN4_SHIFT              (4U)
#define SARADC_CIM2_T1EOCIEN4_WIDTH              (1U)
#define SARADC_CIM2_T1EOCIEN4(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN4_SHIFT)) & SARADC_CIM2_T1EOCIEN4_MASK)

#define SARADC_CIM2_T1EOCIEN5_MASK               (0x20U)
#define SARADC_CIM2_T1EOCIEN5_SHIFT              (5U)
#define SARADC_CIM2_T1EOCIEN5_WIDTH              (1U)
#define SARADC_CIM2_T1EOCIEN5(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN5_SHIFT)) & SARADC_CIM2_T1EOCIEN5_MASK)

#define SARADC_CIM2_T1EOCIEN6_MASK               (0x40U)
#define SARADC_CIM2_T1EOCIEN6_SHIFT              (6U)
#define SARADC_CIM2_T1EOCIEN6_WIDTH              (1U)
#define SARADC_CIM2_T1EOCIEN6(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN6_SHIFT)) & SARADC_CIM2_T1EOCIEN6_MASK)

#define SARADC_CIM2_T1EOCIEN7_MASK               (0x80U)
#define SARADC_CIM2_T1EOCIEN7_SHIFT              (7U)
#define SARADC_CIM2_T1EOCIEN7_WIDTH              (1U)
#define SARADC_CIM2_T1EOCIEN7(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN7_SHIFT)) & SARADC_CIM2_T1EOCIEN7_MASK)

#define SARADC_CIM2_T1EOCIEN8_MASK               (0x100U)
#define SARADC_CIM2_T1EOCIEN8_SHIFT              (8U)
#define SARADC_CIM2_T1EOCIEN8_WIDTH              (1U)
#define SARADC_CIM2_T1EOCIEN8(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN8_SHIFT)) & SARADC_CIM2_T1EOCIEN8_MASK)

#define SARADC_CIM2_T1EOCIEN9_MASK               (0x200U)
#define SARADC_CIM2_T1EOCIEN9_SHIFT              (9U)
#define SARADC_CIM2_T1EOCIEN9_WIDTH              (1U)
#define SARADC_CIM2_T1EOCIEN9(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN9_SHIFT)) & SARADC_CIM2_T1EOCIEN9_MASK)

#define SARADC_CIM2_T1EOCIEN10_MASK              (0x400U)
#define SARADC_CIM2_T1EOCIEN10_SHIFT             (10U)
#define SARADC_CIM2_T1EOCIEN10_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN10(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN10_SHIFT)) & SARADC_CIM2_T1EOCIEN10_MASK)

#define SARADC_CIM2_T1EOCIEN11_MASK              (0x800U)
#define SARADC_CIM2_T1EOCIEN11_SHIFT             (11U)
#define SARADC_CIM2_T1EOCIEN11_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN11(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN11_SHIFT)) & SARADC_CIM2_T1EOCIEN11_MASK)

#define SARADC_CIM2_T1EOCIEN12_MASK              (0x1000U)
#define SARADC_CIM2_T1EOCIEN12_SHIFT             (12U)
#define SARADC_CIM2_T1EOCIEN12_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN12(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN12_SHIFT)) & SARADC_CIM2_T1EOCIEN12_MASK)

#define SARADC_CIM2_T1EOCIEN13_MASK              (0x2000U)
#define SARADC_CIM2_T1EOCIEN13_SHIFT             (13U)
#define SARADC_CIM2_T1EOCIEN13_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN13(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN13_SHIFT)) & SARADC_CIM2_T1EOCIEN13_MASK)

#define SARADC_CIM2_T1EOCIEN14_MASK              (0x4000U)
#define SARADC_CIM2_T1EOCIEN14_SHIFT             (14U)
#define SARADC_CIM2_T1EOCIEN14_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN14(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN14_SHIFT)) & SARADC_CIM2_T1EOCIEN14_MASK)

#define SARADC_CIM2_T1EOCIEN15_MASK              (0x8000U)
#define SARADC_CIM2_T1EOCIEN15_SHIFT             (15U)
#define SARADC_CIM2_T1EOCIEN15_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN15(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN15_SHIFT)) & SARADC_CIM2_T1EOCIEN15_MASK)

#define SARADC_CIM2_T1EOCIEN16_MASK              (0x10000U)
#define SARADC_CIM2_T1EOCIEN16_SHIFT             (16U)
#define SARADC_CIM2_T1EOCIEN16_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN16(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN16_SHIFT)) & SARADC_CIM2_T1EOCIEN16_MASK)

#define SARADC_CIM2_T1EOCIEN17_MASK              (0x20000U)
#define SARADC_CIM2_T1EOCIEN17_SHIFT             (17U)
#define SARADC_CIM2_T1EOCIEN17_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN17(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN17_SHIFT)) & SARADC_CIM2_T1EOCIEN17_MASK)

#define SARADC_CIM2_T1EOCIEN18_MASK              (0x40000U)
#define SARADC_CIM2_T1EOCIEN18_SHIFT             (18U)
#define SARADC_CIM2_T1EOCIEN18_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN18(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN18_SHIFT)) & SARADC_CIM2_T1EOCIEN18_MASK)

#define SARADC_CIM2_T1EOCIEN19_MASK              (0x80000U)
#define SARADC_CIM2_T1EOCIEN19_SHIFT             (19U)
#define SARADC_CIM2_T1EOCIEN19_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN19(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN19_SHIFT)) & SARADC_CIM2_T1EOCIEN19_MASK)

#define SARADC_CIM2_T1EOCIEN20_MASK              (0x100000U)
#define SARADC_CIM2_T1EOCIEN20_SHIFT             (20U)
#define SARADC_CIM2_T1EOCIEN20_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN20(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN20_SHIFT)) & SARADC_CIM2_T1EOCIEN20_MASK)

#define SARADC_CIM2_T1EOCIEN21_MASK              (0x200000U)
#define SARADC_CIM2_T1EOCIEN21_SHIFT             (21U)
#define SARADC_CIM2_T1EOCIEN21_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN21(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN21_SHIFT)) & SARADC_CIM2_T1EOCIEN21_MASK)

#define SARADC_CIM2_T1EOCIEN22_MASK              (0x400000U)
#define SARADC_CIM2_T1EOCIEN22_SHIFT             (22U)
#define SARADC_CIM2_T1EOCIEN22_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN22(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN22_SHIFT)) & SARADC_CIM2_T1EOCIEN22_MASK)

#define SARADC_CIM2_T1EOCIEN23_MASK              (0x800000U)
#define SARADC_CIM2_T1EOCIEN23_SHIFT             (23U)
#define SARADC_CIM2_T1EOCIEN23_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN23(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN23_SHIFT)) & SARADC_CIM2_T1EOCIEN23_MASK)

#define SARADC_CIM2_T1EOCIEN24_MASK              (0x1000000U)
#define SARADC_CIM2_T1EOCIEN24_SHIFT             (24U)
#define SARADC_CIM2_T1EOCIEN24_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN24(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN24_SHIFT)) & SARADC_CIM2_T1EOCIEN24_MASK)

#define SARADC_CIM2_T1EOCIEN25_MASK              (0x2000000U)
#define SARADC_CIM2_T1EOCIEN25_SHIFT             (25U)
#define SARADC_CIM2_T1EOCIEN25_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN25(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN25_SHIFT)) & SARADC_CIM2_T1EOCIEN25_MASK)

#define SARADC_CIM2_T1EOCIEN26_MASK              (0x4000000U)
#define SARADC_CIM2_T1EOCIEN26_SHIFT             (26U)
#define SARADC_CIM2_T1EOCIEN26_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN26(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN26_SHIFT)) & SARADC_CIM2_T1EOCIEN26_MASK)

#define SARADC_CIM2_T1EOCIEN27_MASK              (0x8000000U)
#define SARADC_CIM2_T1EOCIEN27_SHIFT             (27U)
#define SARADC_CIM2_T1EOCIEN27_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN27(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN27_SHIFT)) & SARADC_CIM2_T1EOCIEN27_MASK)

#define SARADC_CIM2_T1EOCIEN28_MASK              (0x10000000U)
#define SARADC_CIM2_T1EOCIEN28_SHIFT             (28U)
#define SARADC_CIM2_T1EOCIEN28_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN28(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN28_SHIFT)) & SARADC_CIM2_T1EOCIEN28_MASK)

#define SARADC_CIM2_T1EOCIEN29_MASK              (0x20000000U)
#define SARADC_CIM2_T1EOCIEN29_SHIFT             (29U)
#define SARADC_CIM2_T1EOCIEN29_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN29(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN29_SHIFT)) & SARADC_CIM2_T1EOCIEN29_MASK)

#define SARADC_CIM2_T1EOCIEN30_MASK              (0x40000000U)
#define SARADC_CIM2_T1EOCIEN30_SHIFT             (30U)
#define SARADC_CIM2_T1EOCIEN30_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN30(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN30_SHIFT)) & SARADC_CIM2_T1EOCIEN30_MASK)

#define SARADC_CIM2_T1EOCIEN31_MASK              (0x80000000U)
#define SARADC_CIM2_T1EOCIEN31_SHIFT             (31U)
#define SARADC_CIM2_T1EOCIEN31_WIDTH             (1U)
#define SARADC_CIM2_T1EOCIEN31(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_CIM2_T1EOCIEN31_SHIFT)) & SARADC_CIM2_T1EOCIEN31_MASK)
/*! @} */

/*! @name WTIS - Analog Watchdog Threshold Interrupt Status */
/*! @{ */

#define SARADC_WTIS_WDG0_L_MASK                  (0x1U)
#define SARADC_WTIS_WDG0_L_SHIFT                 (0U)
#define SARADC_WTIS_WDG0_L_WIDTH                 (1U)
#define SARADC_WTIS_WDG0_L(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_WTIS_WDG0_L_SHIFT)) & SARADC_WTIS_WDG0_L_MASK)

#define SARADC_WTIS_WDG1_L_MASK                  (0x2U)
#define SARADC_WTIS_WDG1_L_SHIFT                 (1U)
#define SARADC_WTIS_WDG1_L_WIDTH                 (1U)
#define SARADC_WTIS_WDG1_L(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_WTIS_WDG1_L_SHIFT)) & SARADC_WTIS_WDG1_L_MASK)

#define SARADC_WTIS_WDG2_L_MASK                  (0x4U)
#define SARADC_WTIS_WDG2_L_SHIFT                 (2U)
#define SARADC_WTIS_WDG2_L_WIDTH                 (1U)
#define SARADC_WTIS_WDG2_L(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_WTIS_WDG2_L_SHIFT)) & SARADC_WTIS_WDG2_L_MASK)

#define SARADC_WTIS_WDG3_L_MASK                  (0x8U)
#define SARADC_WTIS_WDG3_L_SHIFT                 (3U)
#define SARADC_WTIS_WDG3_L_WIDTH                 (1U)
#define SARADC_WTIS_WDG3_L(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_WTIS_WDG3_L_SHIFT)) & SARADC_WTIS_WDG3_L_MASK)

#define SARADC_WTIS_WDG4_H_MASK                  (0x10U)
#define SARADC_WTIS_WDG4_H_SHIFT                 (4U)
#define SARADC_WTIS_WDG4_H_WIDTH                 (1U)
#define SARADC_WTIS_WDG4_H(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_WTIS_WDG4_H_SHIFT)) & SARADC_WTIS_WDG4_H_MASK)

#define SARADC_WTIS_WDG5_H_MASK                  (0x20U)
#define SARADC_WTIS_WDG5_H_SHIFT                 (5U)
#define SARADC_WTIS_WDG5_H_WIDTH                 (1U)
#define SARADC_WTIS_WDG5_H(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_WTIS_WDG5_H_SHIFT)) & SARADC_WTIS_WDG5_H_MASK)

#define SARADC_WTIS_WDG6_H_MASK                  (0x40U)
#define SARADC_WTIS_WDG6_H_SHIFT                 (6U)
#define SARADC_WTIS_WDG6_H_WIDTH                 (1U)
#define SARADC_WTIS_WDG6_H(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_WTIS_WDG6_H_SHIFT)) & SARADC_WTIS_WDG6_H_MASK)

#define SARADC_WTIS_WDG7_H_MASK                  (0x80U)
#define SARADC_WTIS_WDG7_H_SHIFT                 (7U)
#define SARADC_WTIS_WDG7_H_WIDTH                 (1U)
#define SARADC_WTIS_WDG7_H(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_WTIS_WDG7_H_SHIFT)) & SARADC_WTIS_WDG7_H_MASK)
/*! @} */

/*! @name WTIM - Analog Watchdog Threshold Interrupt Mask */
/*! @{ */

#define SARADC_WTIM_MSKWDG0_L_MASK               (0x1U)
#define SARADC_WTIM_MSKWDG0_L_SHIFT              (0U)
#define SARADC_WTIM_MSKWDG0_L_WIDTH              (1U)
#define SARADC_WTIM_MSKWDG0_L(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_WTIM_MSKWDG0_L_SHIFT)) & SARADC_WTIM_MSKWDG0_L_MASK)

#define SARADC_WTIM_MSKWDG1_L_MASK               (0x2U)
#define SARADC_WTIM_MSKWDG1_L_SHIFT              (1U)
#define SARADC_WTIM_MSKWDG1_L_WIDTH              (1U)
#define SARADC_WTIM_MSKWDG1_L(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_WTIM_MSKWDG1_L_SHIFT)) & SARADC_WTIM_MSKWDG1_L_MASK)

#define SARADC_WTIM_MSKWDG2_L_MASK               (0x4U)
#define SARADC_WTIM_MSKWDG2_L_SHIFT              (2U)
#define SARADC_WTIM_MSKWDG2_L_WIDTH              (1U)
#define SARADC_WTIM_MSKWDG2_L(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_WTIM_MSKWDG2_L_SHIFT)) & SARADC_WTIM_MSKWDG2_L_MASK)

#define SARADC_WTIM_MSKWDG3_L_MASK               (0x8U)
#define SARADC_WTIM_MSKWDG3_L_SHIFT              (3U)
#define SARADC_WTIM_MSKWDG3_L_WIDTH              (1U)
#define SARADC_WTIM_MSKWDG3_L(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_WTIM_MSKWDG3_L_SHIFT)) & SARADC_WTIM_MSKWDG3_L_MASK)

#define SARADC_WTIM_MSKWDG4_H_MASK               (0x10U)
#define SARADC_WTIM_MSKWDG4_H_SHIFT              (4U)
#define SARADC_WTIM_MSKWDG4_H_WIDTH              (1U)
#define SARADC_WTIM_MSKWDG4_H(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_WTIM_MSKWDG4_H_SHIFT)) & SARADC_WTIM_MSKWDG4_H_MASK)

#define SARADC_WTIM_MSKWDG5_H_MASK               (0x20U)
#define SARADC_WTIM_MSKWDG5_H_SHIFT              (5U)
#define SARADC_WTIM_MSKWDG5_H_WIDTH              (1U)
#define SARADC_WTIM_MSKWDG5_H(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_WTIM_MSKWDG5_H_SHIFT)) & SARADC_WTIM_MSKWDG5_H_MASK)

#define SARADC_WTIM_MSKWDG6_H_MASK               (0x40U)
#define SARADC_WTIM_MSKWDG6_H_SHIFT              (6U)
#define SARADC_WTIM_MSKWDG6_H_WIDTH              (1U)
#define SARADC_WTIM_MSKWDG6_H(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_WTIM_MSKWDG6_H_SHIFT)) & SARADC_WTIM_MSKWDG6_H_MASK)

#define SARADC_WTIM_MSKWDG7_H_MASK               (0x80U)
#define SARADC_WTIM_MSKWDG7_H_SHIFT              (7U)
#define SARADC_WTIM_MSKWDG7_H_WIDTH              (1U)
#define SARADC_WTIM_MSKWDG7_H(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_WTIM_MSKWDG7_H_SHIFT)) & SARADC_WTIM_MSKWDG7_H_MASK)
/*! @} */

/*! @name DMAE - Direct Memory Access Configuration */
/*! @{ */

#define SARADC_DMAE_DMAEN_MASK                   (0x1U)
#define SARADC_DMAE_DMAEN_SHIFT                  (0U)
#define SARADC_DMAE_DMAEN_WIDTH                  (1U)
#define SARADC_DMAE_DMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_DMAE_DMAEN_SHIFT)) & SARADC_DMAE_DMAEN_MASK)

#define SARADC_DMAE_DCLR_MASK                    (0x2U)
#define SARADC_DMAE_DCLR_SHIFT                   (1U)
#define SARADC_DMAE_DCLR_WIDTH                   (1U)
#define SARADC_DMAE_DCLR(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_DMAE_DCLR_SHIFT)) & SARADC_DMAE_DCLR_MASK)
/*! @} */

/*! @name DMA0 - DMA Request Enable for Type 0 */
/*! @{ */

#define SARADC_DMA0_T0DMAEN0_MASK                (0x1U)
#define SARADC_DMA0_T0DMAEN0_SHIFT               (0U)
#define SARADC_DMA0_T0DMAEN0_WIDTH               (1U)
#define SARADC_DMA0_T0DMAEN0(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN0_SHIFT)) & SARADC_DMA0_T0DMAEN0_MASK)

#define SARADC_DMA0_T0DMAEN1_MASK                (0x2U)
#define SARADC_DMA0_T0DMAEN1_SHIFT               (1U)
#define SARADC_DMA0_T0DMAEN1_WIDTH               (1U)
#define SARADC_DMA0_T0DMAEN1(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN1_SHIFT)) & SARADC_DMA0_T0DMAEN1_MASK)

#define SARADC_DMA0_T0DMAEN2_MASK                (0x4U)
#define SARADC_DMA0_T0DMAEN2_SHIFT               (2U)
#define SARADC_DMA0_T0DMAEN2_WIDTH               (1U)
#define SARADC_DMA0_T0DMAEN2(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN2_SHIFT)) & SARADC_DMA0_T0DMAEN2_MASK)

#define SARADC_DMA0_T0DMAEN3_MASK                (0x8U)
#define SARADC_DMA0_T0DMAEN3_SHIFT               (3U)
#define SARADC_DMA0_T0DMAEN3_WIDTH               (1U)
#define SARADC_DMA0_T0DMAEN3(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN3_SHIFT)) & SARADC_DMA0_T0DMAEN3_MASK)

#define SARADC_DMA0_T0DMAEN4_MASK                (0x10U)
#define SARADC_DMA0_T0DMAEN4_SHIFT               (4U)
#define SARADC_DMA0_T0DMAEN4_WIDTH               (1U)
#define SARADC_DMA0_T0DMAEN4(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN4_SHIFT)) & SARADC_DMA0_T0DMAEN4_MASK)

#define SARADC_DMA0_T0DMAEN5_MASK                (0x20U)
#define SARADC_DMA0_T0DMAEN5_SHIFT               (5U)
#define SARADC_DMA0_T0DMAEN5_WIDTH               (1U)
#define SARADC_DMA0_T0DMAEN5(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN5_SHIFT)) & SARADC_DMA0_T0DMAEN5_MASK)

#define SARADC_DMA0_T0DMAEN6_MASK                (0x40U)
#define SARADC_DMA0_T0DMAEN6_SHIFT               (6U)
#define SARADC_DMA0_T0DMAEN6_WIDTH               (1U)
#define SARADC_DMA0_T0DMAEN6(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN6_SHIFT)) & SARADC_DMA0_T0DMAEN6_MASK)

#define SARADC_DMA0_T0DMAEN7_MASK                (0x80U)
#define SARADC_DMA0_T0DMAEN7_SHIFT               (7U)
#define SARADC_DMA0_T0DMAEN7_WIDTH               (1U)
#define SARADC_DMA0_T0DMAEN7(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN7_SHIFT)) & SARADC_DMA0_T0DMAEN7_MASK)

#define SARADC_DMA0_T0DMAEN8_MASK                (0x100U)
#define SARADC_DMA0_T0DMAEN8_SHIFT               (8U)
#define SARADC_DMA0_T0DMAEN8_WIDTH               (1U)
#define SARADC_DMA0_T0DMAEN8(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN8_SHIFT)) & SARADC_DMA0_T0DMAEN8_MASK)

#define SARADC_DMA0_T0DMAEN9_MASK                (0x200U)
#define SARADC_DMA0_T0DMAEN9_SHIFT               (9U)
#define SARADC_DMA0_T0DMAEN9_WIDTH               (1U)
#define SARADC_DMA0_T0DMAEN9(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN9_SHIFT)) & SARADC_DMA0_T0DMAEN9_MASK)

#define SARADC_DMA0_T0DMAEN10_MASK               (0x400U)
#define SARADC_DMA0_T0DMAEN10_SHIFT              (10U)
#define SARADC_DMA0_T0DMAEN10_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN10(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN10_SHIFT)) & SARADC_DMA0_T0DMAEN10_MASK)

#define SARADC_DMA0_T0DMAEN11_MASK               (0x800U)
#define SARADC_DMA0_T0DMAEN11_SHIFT              (11U)
#define SARADC_DMA0_T0DMAEN11_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN11(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN11_SHIFT)) & SARADC_DMA0_T0DMAEN11_MASK)

#define SARADC_DMA0_T0DMAEN12_MASK               (0x1000U)
#define SARADC_DMA0_T0DMAEN12_SHIFT              (12U)
#define SARADC_DMA0_T0DMAEN12_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN12(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN12_SHIFT)) & SARADC_DMA0_T0DMAEN12_MASK)

#define SARADC_DMA0_T0DMAEN13_MASK               (0x2000U)
#define SARADC_DMA0_T0DMAEN13_SHIFT              (13U)
#define SARADC_DMA0_T0DMAEN13_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN13(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN13_SHIFT)) & SARADC_DMA0_T0DMAEN13_MASK)

#define SARADC_DMA0_T0DMAEN14_MASK               (0x4000U)
#define SARADC_DMA0_T0DMAEN14_SHIFT              (14U)
#define SARADC_DMA0_T0DMAEN14_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN14(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN14_SHIFT)) & SARADC_DMA0_T0DMAEN14_MASK)

#define SARADC_DMA0_T0DMAEN15_MASK               (0x8000U)
#define SARADC_DMA0_T0DMAEN15_SHIFT              (15U)
#define SARADC_DMA0_T0DMAEN15_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN15(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN15_SHIFT)) & SARADC_DMA0_T0DMAEN15_MASK)

#define SARADC_DMA0_T0DMAEN16_MASK               (0x10000U)
#define SARADC_DMA0_T0DMAEN16_SHIFT              (16U)
#define SARADC_DMA0_T0DMAEN16_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN16(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN16_SHIFT)) & SARADC_DMA0_T0DMAEN16_MASK)

#define SARADC_DMA0_T0DMAEN17_MASK               (0x20000U)
#define SARADC_DMA0_T0DMAEN17_SHIFT              (17U)
#define SARADC_DMA0_T0DMAEN17_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN17(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN17_SHIFT)) & SARADC_DMA0_T0DMAEN17_MASK)

#define SARADC_DMA0_T0DMAEN18_MASK               (0x40000U)
#define SARADC_DMA0_T0DMAEN18_SHIFT              (18U)
#define SARADC_DMA0_T0DMAEN18_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN18(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN18_SHIFT)) & SARADC_DMA0_T0DMAEN18_MASK)

#define SARADC_DMA0_T0DMAEN19_MASK               (0x80000U)
#define SARADC_DMA0_T0DMAEN19_SHIFT              (19U)
#define SARADC_DMA0_T0DMAEN19_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN19(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN19_SHIFT)) & SARADC_DMA0_T0DMAEN19_MASK)

#define SARADC_DMA0_T0DMAEN20_MASK               (0x100000U)
#define SARADC_DMA0_T0DMAEN20_SHIFT              (20U)
#define SARADC_DMA0_T0DMAEN20_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN20(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN20_SHIFT)) & SARADC_DMA0_T0DMAEN20_MASK)

#define SARADC_DMA0_T0DMAEN21_MASK               (0x200000U)
#define SARADC_DMA0_T0DMAEN21_SHIFT              (21U)
#define SARADC_DMA0_T0DMAEN21_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN21(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN21_SHIFT)) & SARADC_DMA0_T0DMAEN21_MASK)

#define SARADC_DMA0_T0DMAEN22_MASK               (0x400000U)
#define SARADC_DMA0_T0DMAEN22_SHIFT              (22U)
#define SARADC_DMA0_T0DMAEN22_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN22(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN22_SHIFT)) & SARADC_DMA0_T0DMAEN22_MASK)

#define SARADC_DMA0_T0DMAEN23_MASK               (0x800000U)
#define SARADC_DMA0_T0DMAEN23_SHIFT              (23U)
#define SARADC_DMA0_T0DMAEN23_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN23(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN23_SHIFT)) & SARADC_DMA0_T0DMAEN23_MASK)

#define SARADC_DMA0_T0DMAEN24_MASK               (0x1000000U)
#define SARADC_DMA0_T0DMAEN24_SHIFT              (24U)
#define SARADC_DMA0_T0DMAEN24_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN24(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN24_SHIFT)) & SARADC_DMA0_T0DMAEN24_MASK)

#define SARADC_DMA0_T0DMAEN25_MASK               (0x2000000U)
#define SARADC_DMA0_T0DMAEN25_SHIFT              (25U)
#define SARADC_DMA0_T0DMAEN25_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN25(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN25_SHIFT)) & SARADC_DMA0_T0DMAEN25_MASK)

#define SARADC_DMA0_T0DMAEN26_MASK               (0x4000000U)
#define SARADC_DMA0_T0DMAEN26_SHIFT              (26U)
#define SARADC_DMA0_T0DMAEN26_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN26(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN26_SHIFT)) & SARADC_DMA0_T0DMAEN26_MASK)

#define SARADC_DMA0_T0DMAEN27_MASK               (0x8000000U)
#define SARADC_DMA0_T0DMAEN27_SHIFT              (27U)
#define SARADC_DMA0_T0DMAEN27_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN27(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN27_SHIFT)) & SARADC_DMA0_T0DMAEN27_MASK)

#define SARADC_DMA0_T0DMAEN28_MASK               (0x10000000U)
#define SARADC_DMA0_T0DMAEN28_SHIFT              (28U)
#define SARADC_DMA0_T0DMAEN28_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN28(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN28_SHIFT)) & SARADC_DMA0_T0DMAEN28_MASK)

#define SARADC_DMA0_T0DMAEN29_MASK               (0x20000000U)
#define SARADC_DMA0_T0DMAEN29_SHIFT              (29U)
#define SARADC_DMA0_T0DMAEN29_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN29(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN29_SHIFT)) & SARADC_DMA0_T0DMAEN29_MASK)

#define SARADC_DMA0_T0DMAEN30_MASK               (0x40000000U)
#define SARADC_DMA0_T0DMAEN30_SHIFT              (30U)
#define SARADC_DMA0_T0DMAEN30_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN30(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN30_SHIFT)) & SARADC_DMA0_T0DMAEN30_MASK)

#define SARADC_DMA0_T0DMAEN31_MASK               (0x80000000U)
#define SARADC_DMA0_T0DMAEN31_SHIFT              (31U)
#define SARADC_DMA0_T0DMAEN31_WIDTH              (1U)
#define SARADC_DMA0_T0DMAEN31(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA0_T0DMAEN31_SHIFT)) & SARADC_DMA0_T0DMAEN31_MASK)
/*! @} */

/*! @name DMA1 - DMA Request Enable for Type 1 */
/*! @{ */

#define SARADC_DMA1_T1DMAEN0_MASK                (0x1U)
#define SARADC_DMA1_T1DMAEN0_SHIFT               (0U)
#define SARADC_DMA1_T1DMAEN0_WIDTH               (1U)
#define SARADC_DMA1_T1DMAEN0(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN0_SHIFT)) & SARADC_DMA1_T1DMAEN0_MASK)

#define SARADC_DMA1_T1DMAEN1_MASK                (0x2U)
#define SARADC_DMA1_T1DMAEN1_SHIFT               (1U)
#define SARADC_DMA1_T1DMAEN1_WIDTH               (1U)
#define SARADC_DMA1_T1DMAEN1(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN1_SHIFT)) & SARADC_DMA1_T1DMAEN1_MASK)

#define SARADC_DMA1_T1DMAEN2_MASK                (0x4U)
#define SARADC_DMA1_T1DMAEN2_SHIFT               (2U)
#define SARADC_DMA1_T1DMAEN2_WIDTH               (1U)
#define SARADC_DMA1_T1DMAEN2(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN2_SHIFT)) & SARADC_DMA1_T1DMAEN2_MASK)

#define SARADC_DMA1_T1DMAEN3_MASK                (0x8U)
#define SARADC_DMA1_T1DMAEN3_SHIFT               (3U)
#define SARADC_DMA1_T1DMAEN3_WIDTH               (1U)
#define SARADC_DMA1_T1DMAEN3(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN3_SHIFT)) & SARADC_DMA1_T1DMAEN3_MASK)

#define SARADC_DMA1_T1DMAEN4_MASK                (0x10U)
#define SARADC_DMA1_T1DMAEN4_SHIFT               (4U)
#define SARADC_DMA1_T1DMAEN4_WIDTH               (1U)
#define SARADC_DMA1_T1DMAEN4(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN4_SHIFT)) & SARADC_DMA1_T1DMAEN4_MASK)

#define SARADC_DMA1_T1DMAEN5_MASK                (0x20U)
#define SARADC_DMA1_T1DMAEN5_SHIFT               (5U)
#define SARADC_DMA1_T1DMAEN5_WIDTH               (1U)
#define SARADC_DMA1_T1DMAEN5(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN5_SHIFT)) & SARADC_DMA1_T1DMAEN5_MASK)

#define SARADC_DMA1_T1DMAEN6_MASK                (0x40U)
#define SARADC_DMA1_T1DMAEN6_SHIFT               (6U)
#define SARADC_DMA1_T1DMAEN6_WIDTH               (1U)
#define SARADC_DMA1_T1DMAEN6(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN6_SHIFT)) & SARADC_DMA1_T1DMAEN6_MASK)

#define SARADC_DMA1_T1DMAEN7_MASK                (0x80U)
#define SARADC_DMA1_T1DMAEN7_SHIFT               (7U)
#define SARADC_DMA1_T1DMAEN7_WIDTH               (1U)
#define SARADC_DMA1_T1DMAEN7(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN7_SHIFT)) & SARADC_DMA1_T1DMAEN7_MASK)

#define SARADC_DMA1_T1DMAEN8_MASK                (0x100U)
#define SARADC_DMA1_T1DMAEN8_SHIFT               (8U)
#define SARADC_DMA1_T1DMAEN8_WIDTH               (1U)
#define SARADC_DMA1_T1DMAEN8(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN8_SHIFT)) & SARADC_DMA1_T1DMAEN8_MASK)

#define SARADC_DMA1_T1DMAEN9_MASK                (0x200U)
#define SARADC_DMA1_T1DMAEN9_SHIFT               (9U)
#define SARADC_DMA1_T1DMAEN9_WIDTH               (1U)
#define SARADC_DMA1_T1DMAEN9(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN9_SHIFT)) & SARADC_DMA1_T1DMAEN9_MASK)

#define SARADC_DMA1_T1DMAEN10_MASK               (0x400U)
#define SARADC_DMA1_T1DMAEN10_SHIFT              (10U)
#define SARADC_DMA1_T1DMAEN10_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN10(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN10_SHIFT)) & SARADC_DMA1_T1DMAEN10_MASK)

#define SARADC_DMA1_T1DMAEN16_MASK               (0x10000U)
#define SARADC_DMA1_T1DMAEN16_SHIFT              (16U)
#define SARADC_DMA1_T1DMAEN16_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN16(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN16_SHIFT)) & SARADC_DMA1_T1DMAEN16_MASK)

#define SARADC_DMA1_T1DMAEN17_MASK               (0x20000U)
#define SARADC_DMA1_T1DMAEN17_SHIFT              (17U)
#define SARADC_DMA1_T1DMAEN17_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN17(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN17_SHIFT)) & SARADC_DMA1_T1DMAEN17_MASK)

#define SARADC_DMA1_T1DMAEN18_MASK               (0x40000U)
#define SARADC_DMA1_T1DMAEN18_SHIFT              (18U)
#define SARADC_DMA1_T1DMAEN18_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN18(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN18_SHIFT)) & SARADC_DMA1_T1DMAEN18_MASK)

#define SARADC_DMA1_T1DMAEN19_MASK               (0x80000U)
#define SARADC_DMA1_T1DMAEN19_SHIFT              (19U)
#define SARADC_DMA1_T1DMAEN19_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN19(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN19_SHIFT)) & SARADC_DMA1_T1DMAEN19_MASK)

#define SARADC_DMA1_T1DMAEN20_MASK               (0x100000U)
#define SARADC_DMA1_T1DMAEN20_SHIFT              (20U)
#define SARADC_DMA1_T1DMAEN20_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN20(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN20_SHIFT)) & SARADC_DMA1_T1DMAEN20_MASK)

#define SARADC_DMA1_T1DMAEN21_MASK               (0x200000U)
#define SARADC_DMA1_T1DMAEN21_SHIFT              (21U)
#define SARADC_DMA1_T1DMAEN21_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN21(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN21_SHIFT)) & SARADC_DMA1_T1DMAEN21_MASK)

#define SARADC_DMA1_T1DMAEN22_MASK               (0x400000U)
#define SARADC_DMA1_T1DMAEN22_SHIFT              (22U)
#define SARADC_DMA1_T1DMAEN22_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN22(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN22_SHIFT)) & SARADC_DMA1_T1DMAEN22_MASK)

#define SARADC_DMA1_T1DMAEN23_MASK               (0x800000U)
#define SARADC_DMA1_T1DMAEN23_SHIFT              (23U)
#define SARADC_DMA1_T1DMAEN23_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN23(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN23_SHIFT)) & SARADC_DMA1_T1DMAEN23_MASK)

#define SARADC_DMA1_T1DMAEN24_MASK               (0x1000000U)
#define SARADC_DMA1_T1DMAEN24_SHIFT              (24U)
#define SARADC_DMA1_T1DMAEN24_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN24(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN24_SHIFT)) & SARADC_DMA1_T1DMAEN24_MASK)

#define SARADC_DMA1_T1DMAEN25_MASK               (0x2000000U)
#define SARADC_DMA1_T1DMAEN25_SHIFT              (25U)
#define SARADC_DMA1_T1DMAEN25_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN25(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN25_SHIFT)) & SARADC_DMA1_T1DMAEN25_MASK)

#define SARADC_DMA1_T1DMAEN26_MASK               (0x4000000U)
#define SARADC_DMA1_T1DMAEN26_SHIFT              (26U)
#define SARADC_DMA1_T1DMAEN26_WIDTH              (1U)
#define SARADC_DMA1_T1DMAEN26(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA1_T1DMAEN26_SHIFT)) & SARADC_DMA1_T1DMAEN26_MASK)
/*! @} */

/*! @name DMA2 - DMA Request Enable for Type 2 */
/*! @{ */

#define SARADC_DMA2_T2DMAEN0_MASK                (0x1U)
#define SARADC_DMA2_T2DMAEN0_SHIFT               (0U)
#define SARADC_DMA2_T2DMAEN0_WIDTH               (1U)
#define SARADC_DMA2_T2DMAEN0(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN0_SHIFT)) & SARADC_DMA2_T2DMAEN0_MASK)

#define SARADC_DMA2_T2DMAEN1_MASK                (0x2U)
#define SARADC_DMA2_T2DMAEN1_SHIFT               (1U)
#define SARADC_DMA2_T2DMAEN1_WIDTH               (1U)
#define SARADC_DMA2_T2DMAEN1(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN1_SHIFT)) & SARADC_DMA2_T2DMAEN1_MASK)

#define SARADC_DMA2_T2DMAEN2_MASK                (0x4U)
#define SARADC_DMA2_T2DMAEN2_SHIFT               (2U)
#define SARADC_DMA2_T2DMAEN2_WIDTH               (1U)
#define SARADC_DMA2_T2DMAEN2(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN2_SHIFT)) & SARADC_DMA2_T2DMAEN2_MASK)

#define SARADC_DMA2_T2DMAEN3_MASK                (0x8U)
#define SARADC_DMA2_T2DMAEN3_SHIFT               (3U)
#define SARADC_DMA2_T2DMAEN3_WIDTH               (1U)
#define SARADC_DMA2_T2DMAEN3(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN3_SHIFT)) & SARADC_DMA2_T2DMAEN3_MASK)

#define SARADC_DMA2_T2DMAEN4_MASK                (0x10U)
#define SARADC_DMA2_T2DMAEN4_SHIFT               (4U)
#define SARADC_DMA2_T2DMAEN4_WIDTH               (1U)
#define SARADC_DMA2_T2DMAEN4(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN4_SHIFT)) & SARADC_DMA2_T2DMAEN4_MASK)

#define SARADC_DMA2_T2DMAEN5_MASK                (0x20U)
#define SARADC_DMA2_T2DMAEN5_SHIFT               (5U)
#define SARADC_DMA2_T2DMAEN5_WIDTH               (1U)
#define SARADC_DMA2_T2DMAEN5(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN5_SHIFT)) & SARADC_DMA2_T2DMAEN5_MASK)

#define SARADC_DMA2_T2DMAEN6_MASK                (0x40U)
#define SARADC_DMA2_T2DMAEN6_SHIFT               (6U)
#define SARADC_DMA2_T2DMAEN6_WIDTH               (1U)
#define SARADC_DMA2_T2DMAEN6(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN6_SHIFT)) & SARADC_DMA2_T2DMAEN6_MASK)

#define SARADC_DMA2_T2DMAEN7_MASK                (0x80U)
#define SARADC_DMA2_T2DMAEN7_SHIFT               (7U)
#define SARADC_DMA2_T2DMAEN7_WIDTH               (1U)
#define SARADC_DMA2_T2DMAEN7(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN7_SHIFT)) & SARADC_DMA2_T2DMAEN7_MASK)

#define SARADC_DMA2_T2DMAEN8_MASK                (0x100U)
#define SARADC_DMA2_T2DMAEN8_SHIFT               (8U)
#define SARADC_DMA2_T2DMAEN8_WIDTH               (1U)
#define SARADC_DMA2_T2DMAEN8(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN8_SHIFT)) & SARADC_DMA2_T2DMAEN8_MASK)

#define SARADC_DMA2_T2DMAEN9_MASK                (0x200U)
#define SARADC_DMA2_T2DMAEN9_SHIFT               (9U)
#define SARADC_DMA2_T2DMAEN9_WIDTH               (1U)
#define SARADC_DMA2_T2DMAEN9(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN9_SHIFT)) & SARADC_DMA2_T2DMAEN9_MASK)

#define SARADC_DMA2_T2DMAEN10_MASK               (0x400U)
#define SARADC_DMA2_T2DMAEN10_SHIFT              (10U)
#define SARADC_DMA2_T2DMAEN10_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN10(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN10_SHIFT)) & SARADC_DMA2_T2DMAEN10_MASK)

#define SARADC_DMA2_T2DMAEN11_MASK               (0x800U)
#define SARADC_DMA2_T2DMAEN11_SHIFT              (11U)
#define SARADC_DMA2_T2DMAEN11_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN11(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN11_SHIFT)) & SARADC_DMA2_T2DMAEN11_MASK)

#define SARADC_DMA2_T2DMAEN12_MASK               (0x1000U)
#define SARADC_DMA2_T2DMAEN12_SHIFT              (12U)
#define SARADC_DMA2_T2DMAEN12_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN12(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN12_SHIFT)) & SARADC_DMA2_T2DMAEN12_MASK)

#define SARADC_DMA2_T2DMAEN13_MASK               (0x2000U)
#define SARADC_DMA2_T2DMAEN13_SHIFT              (13U)
#define SARADC_DMA2_T2DMAEN13_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN13(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN13_SHIFT)) & SARADC_DMA2_T2DMAEN13_MASK)

#define SARADC_DMA2_T2DMAEN14_MASK               (0x4000U)
#define SARADC_DMA2_T2DMAEN14_SHIFT              (14U)
#define SARADC_DMA2_T2DMAEN14_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN14(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN14_SHIFT)) & SARADC_DMA2_T2DMAEN14_MASK)

#define SARADC_DMA2_T2DMAEN15_MASK               (0x8000U)
#define SARADC_DMA2_T2DMAEN15_SHIFT              (15U)
#define SARADC_DMA2_T2DMAEN15_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN15(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN15_SHIFT)) & SARADC_DMA2_T2DMAEN15_MASK)

#define SARADC_DMA2_T2DMAEN16_MASK               (0x10000U)
#define SARADC_DMA2_T2DMAEN16_SHIFT              (16U)
#define SARADC_DMA2_T2DMAEN16_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN16(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN16_SHIFT)) & SARADC_DMA2_T2DMAEN16_MASK)

#define SARADC_DMA2_T2DMAEN17_MASK               (0x20000U)
#define SARADC_DMA2_T2DMAEN17_SHIFT              (17U)
#define SARADC_DMA2_T2DMAEN17_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN17(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN17_SHIFT)) & SARADC_DMA2_T2DMAEN17_MASK)

#define SARADC_DMA2_T2DMAEN18_MASK               (0x40000U)
#define SARADC_DMA2_T2DMAEN18_SHIFT              (18U)
#define SARADC_DMA2_T2DMAEN18_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN18(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN18_SHIFT)) & SARADC_DMA2_T2DMAEN18_MASK)

#define SARADC_DMA2_T2DMAEN19_MASK               (0x80000U)
#define SARADC_DMA2_T2DMAEN19_SHIFT              (19U)
#define SARADC_DMA2_T2DMAEN19_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN19(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN19_SHIFT)) & SARADC_DMA2_T2DMAEN19_MASK)

#define SARADC_DMA2_T2DMAEN20_MASK               (0x100000U)
#define SARADC_DMA2_T2DMAEN20_SHIFT              (20U)
#define SARADC_DMA2_T2DMAEN20_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN20(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN20_SHIFT)) & SARADC_DMA2_T2DMAEN20_MASK)

#define SARADC_DMA2_T2DMAEN21_MASK               (0x200000U)
#define SARADC_DMA2_T2DMAEN21_SHIFT              (21U)
#define SARADC_DMA2_T2DMAEN21_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN21(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN21_SHIFT)) & SARADC_DMA2_T2DMAEN21_MASK)

#define SARADC_DMA2_T2DMAEN22_MASK               (0x400000U)
#define SARADC_DMA2_T2DMAEN22_SHIFT              (22U)
#define SARADC_DMA2_T2DMAEN22_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN22(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN22_SHIFT)) & SARADC_DMA2_T2DMAEN22_MASK)

#define SARADC_DMA2_T2DMAEN23_MASK               (0x800000U)
#define SARADC_DMA2_T2DMAEN23_SHIFT              (23U)
#define SARADC_DMA2_T2DMAEN23_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN23(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN23_SHIFT)) & SARADC_DMA2_T2DMAEN23_MASK)

#define SARADC_DMA2_T2DMAEN24_MASK               (0x1000000U)
#define SARADC_DMA2_T2DMAEN24_SHIFT              (24U)
#define SARADC_DMA2_T2DMAEN24_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN24(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN24_SHIFT)) & SARADC_DMA2_T2DMAEN24_MASK)

#define SARADC_DMA2_T2DMAEN25_MASK               (0x2000000U)
#define SARADC_DMA2_T2DMAEN25_SHIFT              (25U)
#define SARADC_DMA2_T2DMAEN25_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN25(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN25_SHIFT)) & SARADC_DMA2_T2DMAEN25_MASK)

#define SARADC_DMA2_T2DMAEN26_MASK               (0x4000000U)
#define SARADC_DMA2_T2DMAEN26_SHIFT              (26U)
#define SARADC_DMA2_T2DMAEN26_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN26(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN26_SHIFT)) & SARADC_DMA2_T2DMAEN26_MASK)

#define SARADC_DMA2_T2DMAEN27_MASK               (0x8000000U)
#define SARADC_DMA2_T2DMAEN27_SHIFT              (27U)
#define SARADC_DMA2_T2DMAEN27_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN27(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN27_SHIFT)) & SARADC_DMA2_T2DMAEN27_MASK)

#define SARADC_DMA2_T2DMAEN28_MASK               (0x10000000U)
#define SARADC_DMA2_T2DMAEN28_SHIFT              (28U)
#define SARADC_DMA2_T2DMAEN28_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN28(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN28_SHIFT)) & SARADC_DMA2_T2DMAEN28_MASK)

#define SARADC_DMA2_T2DMAEN29_MASK               (0x20000000U)
#define SARADC_DMA2_T2DMAEN29_SHIFT              (29U)
#define SARADC_DMA2_T2DMAEN29_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN29(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN29_SHIFT)) & SARADC_DMA2_T2DMAEN29_MASK)

#define SARADC_DMA2_T2DMAEN30_MASK               (0x40000000U)
#define SARADC_DMA2_T2DMAEN30_SHIFT              (30U)
#define SARADC_DMA2_T2DMAEN30_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN30(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN30_SHIFT)) & SARADC_DMA2_T2DMAEN30_MASK)

#define SARADC_DMA2_T2DMAEN31_MASK               (0x80000000U)
#define SARADC_DMA2_T2DMAEN31_SHIFT              (31U)
#define SARADC_DMA2_T2DMAEN31_WIDTH              (1U)
#define SARADC_DMA2_T2DMAEN31(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_DMA2_T2DMAEN31_SHIFT)) & SARADC_DMA2_T2DMAEN31_MASK)
/*! @} */

/*! @name THRHL - Analog Watchdog Threshold Values */
/*! @{ */

#define SARADC_THRHL_THRL_MASK                   (0xFFFFU)
#define SARADC_THRHL_THRL_SHIFT                  (0U)
#define SARADC_THRHL_THRL_WIDTH                  (16U)
#define SARADC_THRHL_THRL(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_THRHL_THRL_SHIFT)) & SARADC_THRHL_THRL_MASK)

#define SARADC_THRHL_THRH_MASK                   (0xFFFF0000U)
#define SARADC_THRHL_THRH_SHIFT                  (16U)
#define SARADC_THRHL_THRH_WIDTH                  (16U)
#define SARADC_THRHL_THRH(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_THRHL_THRH_SHIFT)) & SARADC_THRHL_THRH_MASK)
/*! @} */

/*! @name SMPLTSEL - Sample Time Select */
/*! @{ */

#define SARADC_SMPLTSEL_STS_0_MASK               (0x7U)
#define SARADC_SMPLTSEL_STS_0_SHIFT              (0U)
#define SARADC_SMPLTSEL_STS_0_WIDTH              (3U)
#define SARADC_SMPLTSEL_STS_0(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_SMPLTSEL_STS_0_SHIFT)) & SARADC_SMPLTSEL_STS_0_MASK)

#define SARADC_SMPLTSEL_STS_1_MASK               (0x700U)
#define SARADC_SMPLTSEL_STS_1_SHIFT              (8U)
#define SARADC_SMPLTSEL_STS_1_WIDTH              (3U)
#define SARADC_SMPLTSEL_STS_1(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_SMPLTSEL_STS_1_SHIFT)) & SARADC_SMPLTSEL_STS_1_MASK)

#define SARADC_SMPLTSEL_STS_2_MASK               (0x70000U)
#define SARADC_SMPLTSEL_STS_2_SHIFT              (16U)
#define SARADC_SMPLTSEL_STS_2_WIDTH              (3U)
#define SARADC_SMPLTSEL_STS_2(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_SMPLTSEL_STS_2_SHIFT)) & SARADC_SMPLTSEL_STS_2_MASK)
/*! @} */

/*! @name NCM0 - Normal Conversion Mask for Type 0 */
/*! @{ */

#define SARADC_NCM0_CH0_MASK                     (0x1U)
#define SARADC_NCM0_CH0_SHIFT                    (0U)
#define SARADC_NCM0_CH0_WIDTH                    (1U)
#define SARADC_NCM0_CH0(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH0_SHIFT)) & SARADC_NCM0_CH0_MASK)

#define SARADC_NCM0_CH1_MASK                     (0x2U)
#define SARADC_NCM0_CH1_SHIFT                    (1U)
#define SARADC_NCM0_CH1_WIDTH                    (1U)
#define SARADC_NCM0_CH1(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH1_SHIFT)) & SARADC_NCM0_CH1_MASK)

#define SARADC_NCM0_CH2_MASK                     (0x4U)
#define SARADC_NCM0_CH2_SHIFT                    (2U)
#define SARADC_NCM0_CH2_WIDTH                    (1U)
#define SARADC_NCM0_CH2(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH2_SHIFT)) & SARADC_NCM0_CH2_MASK)

#define SARADC_NCM0_CH3_MASK                     (0x8U)
#define SARADC_NCM0_CH3_SHIFT                    (3U)
#define SARADC_NCM0_CH3_WIDTH                    (1U)
#define SARADC_NCM0_CH3(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH3_SHIFT)) & SARADC_NCM0_CH3_MASK)

#define SARADC_NCM0_CH4_MASK                     (0x10U)
#define SARADC_NCM0_CH4_SHIFT                    (4U)
#define SARADC_NCM0_CH4_WIDTH                    (1U)
#define SARADC_NCM0_CH4(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH4_SHIFT)) & SARADC_NCM0_CH4_MASK)

#define SARADC_NCM0_CH5_MASK                     (0x20U)
#define SARADC_NCM0_CH5_SHIFT                    (5U)
#define SARADC_NCM0_CH5_WIDTH                    (1U)
#define SARADC_NCM0_CH5(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH5_SHIFT)) & SARADC_NCM0_CH5_MASK)

#define SARADC_NCM0_CH6_MASK                     (0x40U)
#define SARADC_NCM0_CH6_SHIFT                    (6U)
#define SARADC_NCM0_CH6_WIDTH                    (1U)
#define SARADC_NCM0_CH6(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH6_SHIFT)) & SARADC_NCM0_CH6_MASK)

#define SARADC_NCM0_CH7_MASK                     (0x80U)
#define SARADC_NCM0_CH7_SHIFT                    (7U)
#define SARADC_NCM0_CH7_WIDTH                    (1U)
#define SARADC_NCM0_CH7(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH7_SHIFT)) & SARADC_NCM0_CH7_MASK)

#define SARADC_NCM0_CH8_MASK                     (0x100U)
#define SARADC_NCM0_CH8_SHIFT                    (8U)
#define SARADC_NCM0_CH8_WIDTH                    (1U)
#define SARADC_NCM0_CH8(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH8_SHIFT)) & SARADC_NCM0_CH8_MASK)

#define SARADC_NCM0_CH9_MASK                     (0x200U)
#define SARADC_NCM0_CH9_SHIFT                    (9U)
#define SARADC_NCM0_CH9_WIDTH                    (1U)
#define SARADC_NCM0_CH9(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH9_SHIFT)) & SARADC_NCM0_CH9_MASK)

#define SARADC_NCM0_CH10_MASK                    (0x400U)
#define SARADC_NCM0_CH10_SHIFT                   (10U)
#define SARADC_NCM0_CH10_WIDTH                   (1U)
#define SARADC_NCM0_CH10(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH10_SHIFT)) & SARADC_NCM0_CH10_MASK)

#define SARADC_NCM0_CH11_MASK                    (0x800U)
#define SARADC_NCM0_CH11_SHIFT                   (11U)
#define SARADC_NCM0_CH11_WIDTH                   (1U)
#define SARADC_NCM0_CH11(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH11_SHIFT)) & SARADC_NCM0_CH11_MASK)

#define SARADC_NCM0_CH12_MASK                    (0x1000U)
#define SARADC_NCM0_CH12_SHIFT                   (12U)
#define SARADC_NCM0_CH12_WIDTH                   (1U)
#define SARADC_NCM0_CH12(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH12_SHIFT)) & SARADC_NCM0_CH12_MASK)

#define SARADC_NCM0_CH13_MASK                    (0x2000U)
#define SARADC_NCM0_CH13_SHIFT                   (13U)
#define SARADC_NCM0_CH13_WIDTH                   (1U)
#define SARADC_NCM0_CH13(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH13_SHIFT)) & SARADC_NCM0_CH13_MASK)

#define SARADC_NCM0_CH14_MASK                    (0x4000U)
#define SARADC_NCM0_CH14_SHIFT                   (14U)
#define SARADC_NCM0_CH14_WIDTH                   (1U)
#define SARADC_NCM0_CH14(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH14_SHIFT)) & SARADC_NCM0_CH14_MASK)

#define SARADC_NCM0_CH15_MASK                    (0x8000U)
#define SARADC_NCM0_CH15_SHIFT                   (15U)
#define SARADC_NCM0_CH15_WIDTH                   (1U)
#define SARADC_NCM0_CH15(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH15_SHIFT)) & SARADC_NCM0_CH15_MASK)

#define SARADC_NCM0_CH16_MASK                    (0x10000U)
#define SARADC_NCM0_CH16_SHIFT                   (16U)
#define SARADC_NCM0_CH16_WIDTH                   (1U)
#define SARADC_NCM0_CH16(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH16_SHIFT)) & SARADC_NCM0_CH16_MASK)

#define SARADC_NCM0_CH17_MASK                    (0x20000U)
#define SARADC_NCM0_CH17_SHIFT                   (17U)
#define SARADC_NCM0_CH17_WIDTH                   (1U)
#define SARADC_NCM0_CH17(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH17_SHIFT)) & SARADC_NCM0_CH17_MASK)

#define SARADC_NCM0_CH18_MASK                    (0x40000U)
#define SARADC_NCM0_CH18_SHIFT                   (18U)
#define SARADC_NCM0_CH18_WIDTH                   (1U)
#define SARADC_NCM0_CH18(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH18_SHIFT)) & SARADC_NCM0_CH18_MASK)

#define SARADC_NCM0_CH19_MASK                    (0x80000U)
#define SARADC_NCM0_CH19_SHIFT                   (19U)
#define SARADC_NCM0_CH19_WIDTH                   (1U)
#define SARADC_NCM0_CH19(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH19_SHIFT)) & SARADC_NCM0_CH19_MASK)

#define SARADC_NCM0_CH20_MASK                    (0x100000U)
#define SARADC_NCM0_CH20_SHIFT                   (20U)
#define SARADC_NCM0_CH20_WIDTH                   (1U)
#define SARADC_NCM0_CH20(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH20_SHIFT)) & SARADC_NCM0_CH20_MASK)

#define SARADC_NCM0_CH21_MASK                    (0x200000U)
#define SARADC_NCM0_CH21_SHIFT                   (21U)
#define SARADC_NCM0_CH21_WIDTH                   (1U)
#define SARADC_NCM0_CH21(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH21_SHIFT)) & SARADC_NCM0_CH21_MASK)

#define SARADC_NCM0_CH22_MASK                    (0x400000U)
#define SARADC_NCM0_CH22_SHIFT                   (22U)
#define SARADC_NCM0_CH22_WIDTH                   (1U)
#define SARADC_NCM0_CH22(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH22_SHIFT)) & SARADC_NCM0_CH22_MASK)

#define SARADC_NCM0_CH23_MASK                    (0x800000U)
#define SARADC_NCM0_CH23_SHIFT                   (23U)
#define SARADC_NCM0_CH23_WIDTH                   (1U)
#define SARADC_NCM0_CH23(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH23_SHIFT)) & SARADC_NCM0_CH23_MASK)

#define SARADC_NCM0_CH24_MASK                    (0x1000000U)
#define SARADC_NCM0_CH24_SHIFT                   (24U)
#define SARADC_NCM0_CH24_WIDTH                   (1U)
#define SARADC_NCM0_CH24(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH24_SHIFT)) & SARADC_NCM0_CH24_MASK)

#define SARADC_NCM0_CH25_MASK                    (0x2000000U)
#define SARADC_NCM0_CH25_SHIFT                   (25U)
#define SARADC_NCM0_CH25_WIDTH                   (1U)
#define SARADC_NCM0_CH25(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH25_SHIFT)) & SARADC_NCM0_CH25_MASK)

#define SARADC_NCM0_CH26_MASK                    (0x4000000U)
#define SARADC_NCM0_CH26_SHIFT                   (26U)
#define SARADC_NCM0_CH26_WIDTH                   (1U)
#define SARADC_NCM0_CH26(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH26_SHIFT)) & SARADC_NCM0_CH26_MASK)

#define SARADC_NCM0_CH27_MASK                    (0x8000000U)
#define SARADC_NCM0_CH27_SHIFT                   (27U)
#define SARADC_NCM0_CH27_WIDTH                   (1U)
#define SARADC_NCM0_CH27(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH27_SHIFT)) & SARADC_NCM0_CH27_MASK)

#define SARADC_NCM0_CH28_MASK                    (0x10000000U)
#define SARADC_NCM0_CH28_SHIFT                   (28U)
#define SARADC_NCM0_CH28_WIDTH                   (1U)
#define SARADC_NCM0_CH28(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH28_SHIFT)) & SARADC_NCM0_CH28_MASK)

#define SARADC_NCM0_CH29_MASK                    (0x20000000U)
#define SARADC_NCM0_CH29_SHIFT                   (29U)
#define SARADC_NCM0_CH29_WIDTH                   (1U)
#define SARADC_NCM0_CH29(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH29_SHIFT)) & SARADC_NCM0_CH29_MASK)

#define SARADC_NCM0_CH30_MASK                    (0x40000000U)
#define SARADC_NCM0_CH30_SHIFT                   (30U)
#define SARADC_NCM0_CH30_WIDTH                   (1U)
#define SARADC_NCM0_CH30(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH30_SHIFT)) & SARADC_NCM0_CH30_MASK)

#define SARADC_NCM0_CH31_MASK                    (0x80000000U)
#define SARADC_NCM0_CH31_SHIFT                   (31U)
#define SARADC_NCM0_CH31_WIDTH                   (1U)
#define SARADC_NCM0_CH31(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM0_CH31_SHIFT)) & SARADC_NCM0_CH31_MASK)
/*! @} */

/*! @name NCM1 - Normal Conversion Mask for Type 1 */
/*! @{ */

#define SARADC_NCM1_CH0_MASK                     (0x1U)
#define SARADC_NCM1_CH0_SHIFT                    (0U)
#define SARADC_NCM1_CH0_WIDTH                    (1U)
#define SARADC_NCM1_CH0(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH0_SHIFT)) & SARADC_NCM1_CH0_MASK)

#define SARADC_NCM1_CH1_MASK                     (0x2U)
#define SARADC_NCM1_CH1_SHIFT                    (1U)
#define SARADC_NCM1_CH1_WIDTH                    (1U)
#define SARADC_NCM1_CH1(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH1_SHIFT)) & SARADC_NCM1_CH1_MASK)

#define SARADC_NCM1_CH2_MASK                     (0x4U)
#define SARADC_NCM1_CH2_SHIFT                    (2U)
#define SARADC_NCM1_CH2_WIDTH                    (1U)
#define SARADC_NCM1_CH2(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH2_SHIFT)) & SARADC_NCM1_CH2_MASK)

#define SARADC_NCM1_CH3_MASK                     (0x8U)
#define SARADC_NCM1_CH3_SHIFT                    (3U)
#define SARADC_NCM1_CH3_WIDTH                    (1U)
#define SARADC_NCM1_CH3(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH3_SHIFT)) & SARADC_NCM1_CH3_MASK)

#define SARADC_NCM1_CH4_MASK                     (0x10U)
#define SARADC_NCM1_CH4_SHIFT                    (4U)
#define SARADC_NCM1_CH4_WIDTH                    (1U)
#define SARADC_NCM1_CH4(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH4_SHIFT)) & SARADC_NCM1_CH4_MASK)

#define SARADC_NCM1_CH5_MASK                     (0x20U)
#define SARADC_NCM1_CH5_SHIFT                    (5U)
#define SARADC_NCM1_CH5_WIDTH                    (1U)
#define SARADC_NCM1_CH5(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH5_SHIFT)) & SARADC_NCM1_CH5_MASK)

#define SARADC_NCM1_CH6_MASK                     (0x40U)
#define SARADC_NCM1_CH6_SHIFT                    (6U)
#define SARADC_NCM1_CH6_WIDTH                    (1U)
#define SARADC_NCM1_CH6(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH6_SHIFT)) & SARADC_NCM1_CH6_MASK)

#define SARADC_NCM1_CH7_MASK                     (0x80U)
#define SARADC_NCM1_CH7_SHIFT                    (7U)
#define SARADC_NCM1_CH7_WIDTH                    (1U)
#define SARADC_NCM1_CH7(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH7_SHIFT)) & SARADC_NCM1_CH7_MASK)

#define SARADC_NCM1_CH8_MASK                     (0x100U)
#define SARADC_NCM1_CH8_SHIFT                    (8U)
#define SARADC_NCM1_CH8_WIDTH                    (1U)
#define SARADC_NCM1_CH8(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH8_SHIFT)) & SARADC_NCM1_CH8_MASK)

#define SARADC_NCM1_CH9_MASK                     (0x200U)
#define SARADC_NCM1_CH9_SHIFT                    (9U)
#define SARADC_NCM1_CH9_WIDTH                    (1U)
#define SARADC_NCM1_CH9(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH9_SHIFT)) & SARADC_NCM1_CH9_MASK)

#define SARADC_NCM1_CH10_MASK                    (0x400U)
#define SARADC_NCM1_CH10_SHIFT                   (10U)
#define SARADC_NCM1_CH10_WIDTH                   (1U)
#define SARADC_NCM1_CH10(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH10_SHIFT)) & SARADC_NCM1_CH10_MASK)

#define SARADC_NCM1_CH16_MASK                    (0x10000U)
#define SARADC_NCM1_CH16_SHIFT                   (16U)
#define SARADC_NCM1_CH16_WIDTH                   (1U)
#define SARADC_NCM1_CH16(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH16_SHIFT)) & SARADC_NCM1_CH16_MASK)

#define SARADC_NCM1_CH17_MASK                    (0x20000U)
#define SARADC_NCM1_CH17_SHIFT                   (17U)
#define SARADC_NCM1_CH17_WIDTH                   (1U)
#define SARADC_NCM1_CH17(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH17_SHIFT)) & SARADC_NCM1_CH17_MASK)

#define SARADC_NCM1_CH18_MASK                    (0x40000U)
#define SARADC_NCM1_CH18_SHIFT                   (18U)
#define SARADC_NCM1_CH18_WIDTH                   (1U)
#define SARADC_NCM1_CH18(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH18_SHIFT)) & SARADC_NCM1_CH18_MASK)

#define SARADC_NCM1_CH19_MASK                    (0x80000U)
#define SARADC_NCM1_CH19_SHIFT                   (19U)
#define SARADC_NCM1_CH19_WIDTH                   (1U)
#define SARADC_NCM1_CH19(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH19_SHIFT)) & SARADC_NCM1_CH19_MASK)

#define SARADC_NCM1_CH20_MASK                    (0x100000U)
#define SARADC_NCM1_CH20_SHIFT                   (20U)
#define SARADC_NCM1_CH20_WIDTH                   (1U)
#define SARADC_NCM1_CH20(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH20_SHIFT)) & SARADC_NCM1_CH20_MASK)

#define SARADC_NCM1_CH21_MASK                    (0x200000U)
#define SARADC_NCM1_CH21_SHIFT                   (21U)
#define SARADC_NCM1_CH21_WIDTH                   (1U)
#define SARADC_NCM1_CH21(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH21_SHIFT)) & SARADC_NCM1_CH21_MASK)

#define SARADC_NCM1_CH22_MASK                    (0x400000U)
#define SARADC_NCM1_CH22_SHIFT                   (22U)
#define SARADC_NCM1_CH22_WIDTH                   (1U)
#define SARADC_NCM1_CH22(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH22_SHIFT)) & SARADC_NCM1_CH22_MASK)

#define SARADC_NCM1_CH23_MASK                    (0x800000U)
#define SARADC_NCM1_CH23_SHIFT                   (23U)
#define SARADC_NCM1_CH23_WIDTH                   (1U)
#define SARADC_NCM1_CH23(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH23_SHIFT)) & SARADC_NCM1_CH23_MASK)

#define SARADC_NCM1_CH24_MASK                    (0x1000000U)
#define SARADC_NCM1_CH24_SHIFT                   (24U)
#define SARADC_NCM1_CH24_WIDTH                   (1U)
#define SARADC_NCM1_CH24(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH24_SHIFT)) & SARADC_NCM1_CH24_MASK)

#define SARADC_NCM1_CH25_MASK                    (0x2000000U)
#define SARADC_NCM1_CH25_SHIFT                   (25U)
#define SARADC_NCM1_CH25_WIDTH                   (1U)
#define SARADC_NCM1_CH25(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH25_SHIFT)) & SARADC_NCM1_CH25_MASK)

#define SARADC_NCM1_CH26_MASK                    (0x4000000U)
#define SARADC_NCM1_CH26_SHIFT                   (26U)
#define SARADC_NCM1_CH26_WIDTH                   (1U)
#define SARADC_NCM1_CH26(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM1_CH26_SHIFT)) & SARADC_NCM1_CH26_MASK)
/*! @} */

/*! @name NCM2 - Normal Conversion Mask for Type 2 */
/*! @{ */

#define SARADC_NCM2_CH0_MASK                     (0x1U)
#define SARADC_NCM2_CH0_SHIFT                    (0U)
#define SARADC_NCM2_CH0_WIDTH                    (1U)
#define SARADC_NCM2_CH0(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH0_SHIFT)) & SARADC_NCM2_CH0_MASK)

#define SARADC_NCM2_CH1_MASK                     (0x2U)
#define SARADC_NCM2_CH1_SHIFT                    (1U)
#define SARADC_NCM2_CH1_WIDTH                    (1U)
#define SARADC_NCM2_CH1(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH1_SHIFT)) & SARADC_NCM2_CH1_MASK)

#define SARADC_NCM2_CH2_MASK                     (0x4U)
#define SARADC_NCM2_CH2_SHIFT                    (2U)
#define SARADC_NCM2_CH2_WIDTH                    (1U)
#define SARADC_NCM2_CH2(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH2_SHIFT)) & SARADC_NCM2_CH2_MASK)

#define SARADC_NCM2_CH3_MASK                     (0x8U)
#define SARADC_NCM2_CH3_SHIFT                    (3U)
#define SARADC_NCM2_CH3_WIDTH                    (1U)
#define SARADC_NCM2_CH3(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH3_SHIFT)) & SARADC_NCM2_CH3_MASK)

#define SARADC_NCM2_CH4_MASK                     (0x10U)
#define SARADC_NCM2_CH4_SHIFT                    (4U)
#define SARADC_NCM2_CH4_WIDTH                    (1U)
#define SARADC_NCM2_CH4(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH4_SHIFT)) & SARADC_NCM2_CH4_MASK)

#define SARADC_NCM2_CH5_MASK                     (0x20U)
#define SARADC_NCM2_CH5_SHIFT                    (5U)
#define SARADC_NCM2_CH5_WIDTH                    (1U)
#define SARADC_NCM2_CH5(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH5_SHIFT)) & SARADC_NCM2_CH5_MASK)

#define SARADC_NCM2_CH6_MASK                     (0x40U)
#define SARADC_NCM2_CH6_SHIFT                    (6U)
#define SARADC_NCM2_CH6_WIDTH                    (1U)
#define SARADC_NCM2_CH6(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH6_SHIFT)) & SARADC_NCM2_CH6_MASK)

#define SARADC_NCM2_CH7_MASK                     (0x80U)
#define SARADC_NCM2_CH7_SHIFT                    (7U)
#define SARADC_NCM2_CH7_WIDTH                    (1U)
#define SARADC_NCM2_CH7(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH7_SHIFT)) & SARADC_NCM2_CH7_MASK)

#define SARADC_NCM2_CH8_MASK                     (0x100U)
#define SARADC_NCM2_CH8_SHIFT                    (8U)
#define SARADC_NCM2_CH8_WIDTH                    (1U)
#define SARADC_NCM2_CH8(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH8_SHIFT)) & SARADC_NCM2_CH8_MASK)

#define SARADC_NCM2_CH9_MASK                     (0x200U)
#define SARADC_NCM2_CH9_SHIFT                    (9U)
#define SARADC_NCM2_CH9_WIDTH                    (1U)
#define SARADC_NCM2_CH9(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH9_SHIFT)) & SARADC_NCM2_CH9_MASK)

#define SARADC_NCM2_CH10_MASK                    (0x400U)
#define SARADC_NCM2_CH10_SHIFT                   (10U)
#define SARADC_NCM2_CH10_WIDTH                   (1U)
#define SARADC_NCM2_CH10(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH10_SHIFT)) & SARADC_NCM2_CH10_MASK)

#define SARADC_NCM2_CH11_MASK                    (0x800U)
#define SARADC_NCM2_CH11_SHIFT                   (11U)
#define SARADC_NCM2_CH11_WIDTH                   (1U)
#define SARADC_NCM2_CH11(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH11_SHIFT)) & SARADC_NCM2_CH11_MASK)

#define SARADC_NCM2_CH12_MASK                    (0x1000U)
#define SARADC_NCM2_CH12_SHIFT                   (12U)
#define SARADC_NCM2_CH12_WIDTH                   (1U)
#define SARADC_NCM2_CH12(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH12_SHIFT)) & SARADC_NCM2_CH12_MASK)

#define SARADC_NCM2_CH13_MASK                    (0x2000U)
#define SARADC_NCM2_CH13_SHIFT                   (13U)
#define SARADC_NCM2_CH13_WIDTH                   (1U)
#define SARADC_NCM2_CH13(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH13_SHIFT)) & SARADC_NCM2_CH13_MASK)

#define SARADC_NCM2_CH14_MASK                    (0x4000U)
#define SARADC_NCM2_CH14_SHIFT                   (14U)
#define SARADC_NCM2_CH14_WIDTH                   (1U)
#define SARADC_NCM2_CH14(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH14_SHIFT)) & SARADC_NCM2_CH14_MASK)

#define SARADC_NCM2_CH15_MASK                    (0x8000U)
#define SARADC_NCM2_CH15_SHIFT                   (15U)
#define SARADC_NCM2_CH15_WIDTH                   (1U)
#define SARADC_NCM2_CH15(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH15_SHIFT)) & SARADC_NCM2_CH15_MASK)

#define SARADC_NCM2_CH16_MASK                    (0x10000U)
#define SARADC_NCM2_CH16_SHIFT                   (16U)
#define SARADC_NCM2_CH16_WIDTH                   (1U)
#define SARADC_NCM2_CH16(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH16_SHIFT)) & SARADC_NCM2_CH16_MASK)

#define SARADC_NCM2_CH17_MASK                    (0x20000U)
#define SARADC_NCM2_CH17_SHIFT                   (17U)
#define SARADC_NCM2_CH17_WIDTH                   (1U)
#define SARADC_NCM2_CH17(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH17_SHIFT)) & SARADC_NCM2_CH17_MASK)

#define SARADC_NCM2_CH18_MASK                    (0x40000U)
#define SARADC_NCM2_CH18_SHIFT                   (18U)
#define SARADC_NCM2_CH18_WIDTH                   (1U)
#define SARADC_NCM2_CH18(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH18_SHIFT)) & SARADC_NCM2_CH18_MASK)

#define SARADC_NCM2_CH19_MASK                    (0x80000U)
#define SARADC_NCM2_CH19_SHIFT                   (19U)
#define SARADC_NCM2_CH19_WIDTH                   (1U)
#define SARADC_NCM2_CH19(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH19_SHIFT)) & SARADC_NCM2_CH19_MASK)

#define SARADC_NCM2_CH20_MASK                    (0x100000U)
#define SARADC_NCM2_CH20_SHIFT                   (20U)
#define SARADC_NCM2_CH20_WIDTH                   (1U)
#define SARADC_NCM2_CH20(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH20_SHIFT)) & SARADC_NCM2_CH20_MASK)

#define SARADC_NCM2_CH21_MASK                    (0x200000U)
#define SARADC_NCM2_CH21_SHIFT                   (21U)
#define SARADC_NCM2_CH21_WIDTH                   (1U)
#define SARADC_NCM2_CH21(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH21_SHIFT)) & SARADC_NCM2_CH21_MASK)

#define SARADC_NCM2_CH22_MASK                    (0x400000U)
#define SARADC_NCM2_CH22_SHIFT                   (22U)
#define SARADC_NCM2_CH22_WIDTH                   (1U)
#define SARADC_NCM2_CH22(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH22_SHIFT)) & SARADC_NCM2_CH22_MASK)

#define SARADC_NCM2_CH23_MASK                    (0x800000U)
#define SARADC_NCM2_CH23_SHIFT                   (23U)
#define SARADC_NCM2_CH23_WIDTH                   (1U)
#define SARADC_NCM2_CH23(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH23_SHIFT)) & SARADC_NCM2_CH23_MASK)

#define SARADC_NCM2_CH24_MASK                    (0x1000000U)
#define SARADC_NCM2_CH24_SHIFT                   (24U)
#define SARADC_NCM2_CH24_WIDTH                   (1U)
#define SARADC_NCM2_CH24(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH24_SHIFT)) & SARADC_NCM2_CH24_MASK)

#define SARADC_NCM2_CH25_MASK                    (0x2000000U)
#define SARADC_NCM2_CH25_SHIFT                   (25U)
#define SARADC_NCM2_CH25_WIDTH                   (1U)
#define SARADC_NCM2_CH25(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH25_SHIFT)) & SARADC_NCM2_CH25_MASK)

#define SARADC_NCM2_CH26_MASK                    (0x4000000U)
#define SARADC_NCM2_CH26_SHIFT                   (26U)
#define SARADC_NCM2_CH26_WIDTH                   (1U)
#define SARADC_NCM2_CH26(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH26_SHIFT)) & SARADC_NCM2_CH26_MASK)

#define SARADC_NCM2_CH27_MASK                    (0x8000000U)
#define SARADC_NCM2_CH27_SHIFT                   (27U)
#define SARADC_NCM2_CH27_WIDTH                   (1U)
#define SARADC_NCM2_CH27(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH27_SHIFT)) & SARADC_NCM2_CH27_MASK)

#define SARADC_NCM2_CH28_MASK                    (0x10000000U)
#define SARADC_NCM2_CH28_SHIFT                   (28U)
#define SARADC_NCM2_CH28_WIDTH                   (1U)
#define SARADC_NCM2_CH28(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH28_SHIFT)) & SARADC_NCM2_CH28_MASK)

#define SARADC_NCM2_CH29_MASK                    (0x20000000U)
#define SARADC_NCM2_CH29_SHIFT                   (29U)
#define SARADC_NCM2_CH29_WIDTH                   (1U)
#define SARADC_NCM2_CH29(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH29_SHIFT)) & SARADC_NCM2_CH29_MASK)

#define SARADC_NCM2_CH30_MASK                    (0x40000000U)
#define SARADC_NCM2_CH30_SHIFT                   (30U)
#define SARADC_NCM2_CH30_WIDTH                   (1U)
#define SARADC_NCM2_CH30(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH30_SHIFT)) & SARADC_NCM2_CH30_MASK)

#define SARADC_NCM2_CH31_MASK                    (0x80000000U)
#define SARADC_NCM2_CH31_SHIFT                   (31U)
#define SARADC_NCM2_CH31_WIDTH                   (1U)
#define SARADC_NCM2_CH31(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_NCM2_CH31_SHIFT)) & SARADC_NCM2_CH31_MASK)
/*! @} */

/*! @name JCM0 - Injected Conversion Mask for Type 0 */
/*! @{ */

#define SARADC_JCM0_CH0_MASK                     (0x1U)
#define SARADC_JCM0_CH0_SHIFT                    (0U)
#define SARADC_JCM0_CH0_WIDTH                    (1U)
#define SARADC_JCM0_CH0(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH0_SHIFT)) & SARADC_JCM0_CH0_MASK)

#define SARADC_JCM0_CH1_MASK                     (0x2U)
#define SARADC_JCM0_CH1_SHIFT                    (1U)
#define SARADC_JCM0_CH1_WIDTH                    (1U)
#define SARADC_JCM0_CH1(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH1_SHIFT)) & SARADC_JCM0_CH1_MASK)

#define SARADC_JCM0_CH2_MASK                     (0x4U)
#define SARADC_JCM0_CH2_SHIFT                    (2U)
#define SARADC_JCM0_CH2_WIDTH                    (1U)
#define SARADC_JCM0_CH2(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH2_SHIFT)) & SARADC_JCM0_CH2_MASK)

#define SARADC_JCM0_CH3_MASK                     (0x8U)
#define SARADC_JCM0_CH3_SHIFT                    (3U)
#define SARADC_JCM0_CH3_WIDTH                    (1U)
#define SARADC_JCM0_CH3(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH3_SHIFT)) & SARADC_JCM0_CH3_MASK)

#define SARADC_JCM0_CH4_MASK                     (0x10U)
#define SARADC_JCM0_CH4_SHIFT                    (4U)
#define SARADC_JCM0_CH4_WIDTH                    (1U)
#define SARADC_JCM0_CH4(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH4_SHIFT)) & SARADC_JCM0_CH4_MASK)

#define SARADC_JCM0_CH5_MASK                     (0x20U)
#define SARADC_JCM0_CH5_SHIFT                    (5U)
#define SARADC_JCM0_CH5_WIDTH                    (1U)
#define SARADC_JCM0_CH5(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH5_SHIFT)) & SARADC_JCM0_CH5_MASK)

#define SARADC_JCM0_CH6_MASK                     (0x40U)
#define SARADC_JCM0_CH6_SHIFT                    (6U)
#define SARADC_JCM0_CH6_WIDTH                    (1U)
#define SARADC_JCM0_CH6(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH6_SHIFT)) & SARADC_JCM0_CH6_MASK)

#define SARADC_JCM0_CH7_MASK                     (0x80U)
#define SARADC_JCM0_CH7_SHIFT                    (7U)
#define SARADC_JCM0_CH7_WIDTH                    (1U)
#define SARADC_JCM0_CH7(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH7_SHIFT)) & SARADC_JCM0_CH7_MASK)

#define SARADC_JCM0_CH8_MASK                     (0x100U)
#define SARADC_JCM0_CH8_SHIFT                    (8U)
#define SARADC_JCM0_CH8_WIDTH                    (1U)
#define SARADC_JCM0_CH8(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH8_SHIFT)) & SARADC_JCM0_CH8_MASK)

#define SARADC_JCM0_CH9_MASK                     (0x200U)
#define SARADC_JCM0_CH9_SHIFT                    (9U)
#define SARADC_JCM0_CH9_WIDTH                    (1U)
#define SARADC_JCM0_CH9(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH9_SHIFT)) & SARADC_JCM0_CH9_MASK)

#define SARADC_JCM0_CH10_MASK                    (0x400U)
#define SARADC_JCM0_CH10_SHIFT                   (10U)
#define SARADC_JCM0_CH10_WIDTH                   (1U)
#define SARADC_JCM0_CH10(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH10_SHIFT)) & SARADC_JCM0_CH10_MASK)

#define SARADC_JCM0_CH11_MASK                    (0x800U)
#define SARADC_JCM0_CH11_SHIFT                   (11U)
#define SARADC_JCM0_CH11_WIDTH                   (1U)
#define SARADC_JCM0_CH11(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH11_SHIFT)) & SARADC_JCM0_CH11_MASK)

#define SARADC_JCM0_CH12_MASK                    (0x1000U)
#define SARADC_JCM0_CH12_SHIFT                   (12U)
#define SARADC_JCM0_CH12_WIDTH                   (1U)
#define SARADC_JCM0_CH12(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH12_SHIFT)) & SARADC_JCM0_CH12_MASK)

#define SARADC_JCM0_CH13_MASK                    (0x2000U)
#define SARADC_JCM0_CH13_SHIFT                   (13U)
#define SARADC_JCM0_CH13_WIDTH                   (1U)
#define SARADC_JCM0_CH13(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH13_SHIFT)) & SARADC_JCM0_CH13_MASK)

#define SARADC_JCM0_CH14_MASK                    (0x4000U)
#define SARADC_JCM0_CH14_SHIFT                   (14U)
#define SARADC_JCM0_CH14_WIDTH                   (1U)
#define SARADC_JCM0_CH14(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH14_SHIFT)) & SARADC_JCM0_CH14_MASK)

#define SARADC_JCM0_CH15_MASK                    (0x8000U)
#define SARADC_JCM0_CH15_SHIFT                   (15U)
#define SARADC_JCM0_CH15_WIDTH                   (1U)
#define SARADC_JCM0_CH15(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH15_SHIFT)) & SARADC_JCM0_CH15_MASK)

#define SARADC_JCM0_CH16_MASK                    (0x10000U)
#define SARADC_JCM0_CH16_SHIFT                   (16U)
#define SARADC_JCM0_CH16_WIDTH                   (1U)
#define SARADC_JCM0_CH16(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH16_SHIFT)) & SARADC_JCM0_CH16_MASK)

#define SARADC_JCM0_CH17_MASK                    (0x20000U)
#define SARADC_JCM0_CH17_SHIFT                   (17U)
#define SARADC_JCM0_CH17_WIDTH                   (1U)
#define SARADC_JCM0_CH17(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH17_SHIFT)) & SARADC_JCM0_CH17_MASK)

#define SARADC_JCM0_CH18_MASK                    (0x40000U)
#define SARADC_JCM0_CH18_SHIFT                   (18U)
#define SARADC_JCM0_CH18_WIDTH                   (1U)
#define SARADC_JCM0_CH18(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH18_SHIFT)) & SARADC_JCM0_CH18_MASK)

#define SARADC_JCM0_CH19_MASK                    (0x80000U)
#define SARADC_JCM0_CH19_SHIFT                   (19U)
#define SARADC_JCM0_CH19_WIDTH                   (1U)
#define SARADC_JCM0_CH19(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH19_SHIFT)) & SARADC_JCM0_CH19_MASK)

#define SARADC_JCM0_CH20_MASK                    (0x100000U)
#define SARADC_JCM0_CH20_SHIFT                   (20U)
#define SARADC_JCM0_CH20_WIDTH                   (1U)
#define SARADC_JCM0_CH20(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH20_SHIFT)) & SARADC_JCM0_CH20_MASK)

#define SARADC_JCM0_CH21_MASK                    (0x200000U)
#define SARADC_JCM0_CH21_SHIFT                   (21U)
#define SARADC_JCM0_CH21_WIDTH                   (1U)
#define SARADC_JCM0_CH21(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH21_SHIFT)) & SARADC_JCM0_CH21_MASK)

#define SARADC_JCM0_CH22_MASK                    (0x400000U)
#define SARADC_JCM0_CH22_SHIFT                   (22U)
#define SARADC_JCM0_CH22_WIDTH                   (1U)
#define SARADC_JCM0_CH22(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH22_SHIFT)) & SARADC_JCM0_CH22_MASK)

#define SARADC_JCM0_CH23_MASK                    (0x800000U)
#define SARADC_JCM0_CH23_SHIFT                   (23U)
#define SARADC_JCM0_CH23_WIDTH                   (1U)
#define SARADC_JCM0_CH23(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH23_SHIFT)) & SARADC_JCM0_CH23_MASK)

#define SARADC_JCM0_CH24_MASK                    (0x1000000U)
#define SARADC_JCM0_CH24_SHIFT                   (24U)
#define SARADC_JCM0_CH24_WIDTH                   (1U)
#define SARADC_JCM0_CH24(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH24_SHIFT)) & SARADC_JCM0_CH24_MASK)

#define SARADC_JCM0_CH25_MASK                    (0x2000000U)
#define SARADC_JCM0_CH25_SHIFT                   (25U)
#define SARADC_JCM0_CH25_WIDTH                   (1U)
#define SARADC_JCM0_CH25(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH25_SHIFT)) & SARADC_JCM0_CH25_MASK)

#define SARADC_JCM0_CH26_MASK                    (0x4000000U)
#define SARADC_JCM0_CH26_SHIFT                   (26U)
#define SARADC_JCM0_CH26_WIDTH                   (1U)
#define SARADC_JCM0_CH26(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH26_SHIFT)) & SARADC_JCM0_CH26_MASK)

#define SARADC_JCM0_CH27_MASK                    (0x8000000U)
#define SARADC_JCM0_CH27_SHIFT                   (27U)
#define SARADC_JCM0_CH27_WIDTH                   (1U)
#define SARADC_JCM0_CH27(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH27_SHIFT)) & SARADC_JCM0_CH27_MASK)

#define SARADC_JCM0_CH28_MASK                    (0x10000000U)
#define SARADC_JCM0_CH28_SHIFT                   (28U)
#define SARADC_JCM0_CH28_WIDTH                   (1U)
#define SARADC_JCM0_CH28(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH28_SHIFT)) & SARADC_JCM0_CH28_MASK)

#define SARADC_JCM0_CH29_MASK                    (0x20000000U)
#define SARADC_JCM0_CH29_SHIFT                   (29U)
#define SARADC_JCM0_CH29_WIDTH                   (1U)
#define SARADC_JCM0_CH29(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH29_SHIFT)) & SARADC_JCM0_CH29_MASK)

#define SARADC_JCM0_CH30_MASK                    (0x40000000U)
#define SARADC_JCM0_CH30_SHIFT                   (30U)
#define SARADC_JCM0_CH30_WIDTH                   (1U)
#define SARADC_JCM0_CH30(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH30_SHIFT)) & SARADC_JCM0_CH30_MASK)

#define SARADC_JCM0_CH31_MASK                    (0x80000000U)
#define SARADC_JCM0_CH31_SHIFT                   (31U)
#define SARADC_JCM0_CH31_WIDTH                   (1U)
#define SARADC_JCM0_CH31(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM0_CH31_SHIFT)) & SARADC_JCM0_CH31_MASK)
/*! @} */

/*! @name JCM1 - Injected Conversion Mask for Type 1 */
/*! @{ */

#define SARADC_JCM1_CH0_MASK                     (0x1U)
#define SARADC_JCM1_CH0_SHIFT                    (0U)
#define SARADC_JCM1_CH0_WIDTH                    (1U)
#define SARADC_JCM1_CH0(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH0_SHIFT)) & SARADC_JCM1_CH0_MASK)

#define SARADC_JCM1_CH1_MASK                     (0x2U)
#define SARADC_JCM1_CH1_SHIFT                    (1U)
#define SARADC_JCM1_CH1_WIDTH                    (1U)
#define SARADC_JCM1_CH1(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH1_SHIFT)) & SARADC_JCM1_CH1_MASK)

#define SARADC_JCM1_CH2_MASK                     (0x4U)
#define SARADC_JCM1_CH2_SHIFT                    (2U)
#define SARADC_JCM1_CH2_WIDTH                    (1U)
#define SARADC_JCM1_CH2(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH2_SHIFT)) & SARADC_JCM1_CH2_MASK)

#define SARADC_JCM1_CH3_MASK                     (0x8U)
#define SARADC_JCM1_CH3_SHIFT                    (3U)
#define SARADC_JCM1_CH3_WIDTH                    (1U)
#define SARADC_JCM1_CH3(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH3_SHIFT)) & SARADC_JCM1_CH3_MASK)

#define SARADC_JCM1_CH4_MASK                     (0x10U)
#define SARADC_JCM1_CH4_SHIFT                    (4U)
#define SARADC_JCM1_CH4_WIDTH                    (1U)
#define SARADC_JCM1_CH4(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH4_SHIFT)) & SARADC_JCM1_CH4_MASK)

#define SARADC_JCM1_CH5_MASK                     (0x20U)
#define SARADC_JCM1_CH5_SHIFT                    (5U)
#define SARADC_JCM1_CH5_WIDTH                    (1U)
#define SARADC_JCM1_CH5(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH5_SHIFT)) & SARADC_JCM1_CH5_MASK)

#define SARADC_JCM1_CH6_MASK                     (0x40U)
#define SARADC_JCM1_CH6_SHIFT                    (6U)
#define SARADC_JCM1_CH6_WIDTH                    (1U)
#define SARADC_JCM1_CH6(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH6_SHIFT)) & SARADC_JCM1_CH6_MASK)

#define SARADC_JCM1_CH7_MASK                     (0x80U)
#define SARADC_JCM1_CH7_SHIFT                    (7U)
#define SARADC_JCM1_CH7_WIDTH                    (1U)
#define SARADC_JCM1_CH7(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH7_SHIFT)) & SARADC_JCM1_CH7_MASK)

#define SARADC_JCM1_CH8_MASK                     (0x100U)
#define SARADC_JCM1_CH8_SHIFT                    (8U)
#define SARADC_JCM1_CH8_WIDTH                    (1U)
#define SARADC_JCM1_CH8(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH8_SHIFT)) & SARADC_JCM1_CH8_MASK)

#define SARADC_JCM1_CH9_MASK                     (0x200U)
#define SARADC_JCM1_CH9_SHIFT                    (9U)
#define SARADC_JCM1_CH9_WIDTH                    (1U)
#define SARADC_JCM1_CH9(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH9_SHIFT)) & SARADC_JCM1_CH9_MASK)

#define SARADC_JCM1_CH10_MASK                    (0x400U)
#define SARADC_JCM1_CH10_SHIFT                   (10U)
#define SARADC_JCM1_CH10_WIDTH                   (1U)
#define SARADC_JCM1_CH10(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH10_SHIFT)) & SARADC_JCM1_CH10_MASK)

#define SARADC_JCM1_CH16_MASK                    (0x10000U)
#define SARADC_JCM1_CH16_SHIFT                   (16U)
#define SARADC_JCM1_CH16_WIDTH                   (1U)
#define SARADC_JCM1_CH16(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH16_SHIFT)) & SARADC_JCM1_CH16_MASK)

#define SARADC_JCM1_CH17_MASK                    (0x20000U)
#define SARADC_JCM1_CH17_SHIFT                   (17U)
#define SARADC_JCM1_CH17_WIDTH                   (1U)
#define SARADC_JCM1_CH17(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH17_SHIFT)) & SARADC_JCM1_CH17_MASK)

#define SARADC_JCM1_CH18_MASK                    (0x40000U)
#define SARADC_JCM1_CH18_SHIFT                   (18U)
#define SARADC_JCM1_CH18_WIDTH                   (1U)
#define SARADC_JCM1_CH18(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH18_SHIFT)) & SARADC_JCM1_CH18_MASK)

#define SARADC_JCM1_CH19_MASK                    (0x80000U)
#define SARADC_JCM1_CH19_SHIFT                   (19U)
#define SARADC_JCM1_CH19_WIDTH                   (1U)
#define SARADC_JCM1_CH19(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH19_SHIFT)) & SARADC_JCM1_CH19_MASK)

#define SARADC_JCM1_CH20_MASK                    (0x100000U)
#define SARADC_JCM1_CH20_SHIFT                   (20U)
#define SARADC_JCM1_CH20_WIDTH                   (1U)
#define SARADC_JCM1_CH20(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH20_SHIFT)) & SARADC_JCM1_CH20_MASK)

#define SARADC_JCM1_CH21_MASK                    (0x200000U)
#define SARADC_JCM1_CH21_SHIFT                   (21U)
#define SARADC_JCM1_CH21_WIDTH                   (1U)
#define SARADC_JCM1_CH21(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH21_SHIFT)) & SARADC_JCM1_CH21_MASK)

#define SARADC_JCM1_CH22_MASK                    (0x400000U)
#define SARADC_JCM1_CH22_SHIFT                   (22U)
#define SARADC_JCM1_CH22_WIDTH                   (1U)
#define SARADC_JCM1_CH22(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH22_SHIFT)) & SARADC_JCM1_CH22_MASK)

#define SARADC_JCM1_CH23_MASK                    (0x800000U)
#define SARADC_JCM1_CH23_SHIFT                   (23U)
#define SARADC_JCM1_CH23_WIDTH                   (1U)
#define SARADC_JCM1_CH23(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH23_SHIFT)) & SARADC_JCM1_CH23_MASK)

#define SARADC_JCM1_CH24_MASK                    (0x1000000U)
#define SARADC_JCM1_CH24_SHIFT                   (24U)
#define SARADC_JCM1_CH24_WIDTH                   (1U)
#define SARADC_JCM1_CH24(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH24_SHIFT)) & SARADC_JCM1_CH24_MASK)

#define SARADC_JCM1_CH25_MASK                    (0x2000000U)
#define SARADC_JCM1_CH25_SHIFT                   (25U)
#define SARADC_JCM1_CH25_WIDTH                   (1U)
#define SARADC_JCM1_CH25(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH25_SHIFT)) & SARADC_JCM1_CH25_MASK)

#define SARADC_JCM1_CH26_MASK                    (0x4000000U)
#define SARADC_JCM1_CH26_SHIFT                   (26U)
#define SARADC_JCM1_CH26_WIDTH                   (1U)
#define SARADC_JCM1_CH26(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM1_CH26_SHIFT)) & SARADC_JCM1_CH26_MASK)
/*! @} */

/*! @name JCM2 - Injected Conversion Mask for Type 2 */
/*! @{ */

#define SARADC_JCM2_CH0_MASK                     (0x1U)
#define SARADC_JCM2_CH0_SHIFT                    (0U)
#define SARADC_JCM2_CH0_WIDTH                    (1U)
#define SARADC_JCM2_CH0(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH0_SHIFT)) & SARADC_JCM2_CH0_MASK)

#define SARADC_JCM2_CH1_MASK                     (0x2U)
#define SARADC_JCM2_CH1_SHIFT                    (1U)
#define SARADC_JCM2_CH1_WIDTH                    (1U)
#define SARADC_JCM2_CH1(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH1_SHIFT)) & SARADC_JCM2_CH1_MASK)

#define SARADC_JCM2_CH2_MASK                     (0x4U)
#define SARADC_JCM2_CH2_SHIFT                    (2U)
#define SARADC_JCM2_CH2_WIDTH                    (1U)
#define SARADC_JCM2_CH2(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH2_SHIFT)) & SARADC_JCM2_CH2_MASK)

#define SARADC_JCM2_CH3_MASK                     (0x8U)
#define SARADC_JCM2_CH3_SHIFT                    (3U)
#define SARADC_JCM2_CH3_WIDTH                    (1U)
#define SARADC_JCM2_CH3(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH3_SHIFT)) & SARADC_JCM2_CH3_MASK)

#define SARADC_JCM2_CH4_MASK                     (0x10U)
#define SARADC_JCM2_CH4_SHIFT                    (4U)
#define SARADC_JCM2_CH4_WIDTH                    (1U)
#define SARADC_JCM2_CH4(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH4_SHIFT)) & SARADC_JCM2_CH4_MASK)

#define SARADC_JCM2_CH5_MASK                     (0x20U)
#define SARADC_JCM2_CH5_SHIFT                    (5U)
#define SARADC_JCM2_CH5_WIDTH                    (1U)
#define SARADC_JCM2_CH5(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH5_SHIFT)) & SARADC_JCM2_CH5_MASK)

#define SARADC_JCM2_CH6_MASK                     (0x40U)
#define SARADC_JCM2_CH6_SHIFT                    (6U)
#define SARADC_JCM2_CH6_WIDTH                    (1U)
#define SARADC_JCM2_CH6(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH6_SHIFT)) & SARADC_JCM2_CH6_MASK)

#define SARADC_JCM2_CH7_MASK                     (0x80U)
#define SARADC_JCM2_CH7_SHIFT                    (7U)
#define SARADC_JCM2_CH7_WIDTH                    (1U)
#define SARADC_JCM2_CH7(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH7_SHIFT)) & SARADC_JCM2_CH7_MASK)

#define SARADC_JCM2_CH8_MASK                     (0x100U)
#define SARADC_JCM2_CH8_SHIFT                    (8U)
#define SARADC_JCM2_CH8_WIDTH                    (1U)
#define SARADC_JCM2_CH8(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH8_SHIFT)) & SARADC_JCM2_CH8_MASK)

#define SARADC_JCM2_CH9_MASK                     (0x200U)
#define SARADC_JCM2_CH9_SHIFT                    (9U)
#define SARADC_JCM2_CH9_WIDTH                    (1U)
#define SARADC_JCM2_CH9(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH9_SHIFT)) & SARADC_JCM2_CH9_MASK)

#define SARADC_JCM2_CH10_MASK                    (0x400U)
#define SARADC_JCM2_CH10_SHIFT                   (10U)
#define SARADC_JCM2_CH10_WIDTH                   (1U)
#define SARADC_JCM2_CH10(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH10_SHIFT)) & SARADC_JCM2_CH10_MASK)

#define SARADC_JCM2_CH11_MASK                    (0x800U)
#define SARADC_JCM2_CH11_SHIFT                   (11U)
#define SARADC_JCM2_CH11_WIDTH                   (1U)
#define SARADC_JCM2_CH11(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH11_SHIFT)) & SARADC_JCM2_CH11_MASK)

#define SARADC_JCM2_CH12_MASK                    (0x1000U)
#define SARADC_JCM2_CH12_SHIFT                   (12U)
#define SARADC_JCM2_CH12_WIDTH                   (1U)
#define SARADC_JCM2_CH12(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH12_SHIFT)) & SARADC_JCM2_CH12_MASK)

#define SARADC_JCM2_CH13_MASK                    (0x2000U)
#define SARADC_JCM2_CH13_SHIFT                   (13U)
#define SARADC_JCM2_CH13_WIDTH                   (1U)
#define SARADC_JCM2_CH13(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH13_SHIFT)) & SARADC_JCM2_CH13_MASK)

#define SARADC_JCM2_CH14_MASK                    (0x4000U)
#define SARADC_JCM2_CH14_SHIFT                   (14U)
#define SARADC_JCM2_CH14_WIDTH                   (1U)
#define SARADC_JCM2_CH14(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH14_SHIFT)) & SARADC_JCM2_CH14_MASK)

#define SARADC_JCM2_CH15_MASK                    (0x8000U)
#define SARADC_JCM2_CH15_SHIFT                   (15U)
#define SARADC_JCM2_CH15_WIDTH                   (1U)
#define SARADC_JCM2_CH15(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH15_SHIFT)) & SARADC_JCM2_CH15_MASK)

#define SARADC_JCM2_CH16_MASK                    (0x10000U)
#define SARADC_JCM2_CH16_SHIFT                   (16U)
#define SARADC_JCM2_CH16_WIDTH                   (1U)
#define SARADC_JCM2_CH16(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH16_SHIFT)) & SARADC_JCM2_CH16_MASK)

#define SARADC_JCM2_CH17_MASK                    (0x20000U)
#define SARADC_JCM2_CH17_SHIFT                   (17U)
#define SARADC_JCM2_CH17_WIDTH                   (1U)
#define SARADC_JCM2_CH17(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH17_SHIFT)) & SARADC_JCM2_CH17_MASK)

#define SARADC_JCM2_CH18_MASK                    (0x40000U)
#define SARADC_JCM2_CH18_SHIFT                   (18U)
#define SARADC_JCM2_CH18_WIDTH                   (1U)
#define SARADC_JCM2_CH18(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH18_SHIFT)) & SARADC_JCM2_CH18_MASK)

#define SARADC_JCM2_CH19_MASK                    (0x80000U)
#define SARADC_JCM2_CH19_SHIFT                   (19U)
#define SARADC_JCM2_CH19_WIDTH                   (1U)
#define SARADC_JCM2_CH19(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH19_SHIFT)) & SARADC_JCM2_CH19_MASK)

#define SARADC_JCM2_CH20_MASK                    (0x100000U)
#define SARADC_JCM2_CH20_SHIFT                   (20U)
#define SARADC_JCM2_CH20_WIDTH                   (1U)
#define SARADC_JCM2_CH20(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH20_SHIFT)) & SARADC_JCM2_CH20_MASK)

#define SARADC_JCM2_CH21_MASK                    (0x200000U)
#define SARADC_JCM2_CH21_SHIFT                   (21U)
#define SARADC_JCM2_CH21_WIDTH                   (1U)
#define SARADC_JCM2_CH21(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH21_SHIFT)) & SARADC_JCM2_CH21_MASK)

#define SARADC_JCM2_CH22_MASK                    (0x400000U)
#define SARADC_JCM2_CH22_SHIFT                   (22U)
#define SARADC_JCM2_CH22_WIDTH                   (1U)
#define SARADC_JCM2_CH22(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH22_SHIFT)) & SARADC_JCM2_CH22_MASK)

#define SARADC_JCM2_CH23_MASK                    (0x800000U)
#define SARADC_JCM2_CH23_SHIFT                   (23U)
#define SARADC_JCM2_CH23_WIDTH                   (1U)
#define SARADC_JCM2_CH23(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH23_SHIFT)) & SARADC_JCM2_CH23_MASK)

#define SARADC_JCM2_CH24_MASK                    (0x1000000U)
#define SARADC_JCM2_CH24_SHIFT                   (24U)
#define SARADC_JCM2_CH24_WIDTH                   (1U)
#define SARADC_JCM2_CH24(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH24_SHIFT)) & SARADC_JCM2_CH24_MASK)

#define SARADC_JCM2_CH25_MASK                    (0x2000000U)
#define SARADC_JCM2_CH25_SHIFT                   (25U)
#define SARADC_JCM2_CH25_WIDTH                   (1U)
#define SARADC_JCM2_CH25(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH25_SHIFT)) & SARADC_JCM2_CH25_MASK)

#define SARADC_JCM2_CH26_MASK                    (0x4000000U)
#define SARADC_JCM2_CH26_SHIFT                   (26U)
#define SARADC_JCM2_CH26_WIDTH                   (1U)
#define SARADC_JCM2_CH26(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH26_SHIFT)) & SARADC_JCM2_CH26_MASK)

#define SARADC_JCM2_CH27_MASK                    (0x8000000U)
#define SARADC_JCM2_CH27_SHIFT                   (27U)
#define SARADC_JCM2_CH27_WIDTH                   (1U)
#define SARADC_JCM2_CH27(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH27_SHIFT)) & SARADC_JCM2_CH27_MASK)

#define SARADC_JCM2_CH28_MASK                    (0x10000000U)
#define SARADC_JCM2_CH28_SHIFT                   (28U)
#define SARADC_JCM2_CH28_WIDTH                   (1U)
#define SARADC_JCM2_CH28(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH28_SHIFT)) & SARADC_JCM2_CH28_MASK)

#define SARADC_JCM2_CH29_MASK                    (0x20000000U)
#define SARADC_JCM2_CH29_SHIFT                   (29U)
#define SARADC_JCM2_CH29_WIDTH                   (1U)
#define SARADC_JCM2_CH29(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH29_SHIFT)) & SARADC_JCM2_CH29_MASK)

#define SARADC_JCM2_CH30_MASK                    (0x40000000U)
#define SARADC_JCM2_CH30_SHIFT                   (30U)
#define SARADC_JCM2_CH30_WIDTH                   (1U)
#define SARADC_JCM2_CH30(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH30_SHIFT)) & SARADC_JCM2_CH30_MASK)

#define SARADC_JCM2_CH31_MASK                    (0x80000000U)
#define SARADC_JCM2_CH31_SHIFT                   (31U)
#define SARADC_JCM2_CH31_WIDTH                   (1U)
#define SARADC_JCM2_CH31(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_JCM2_CH31_SHIFT)) & SARADC_JCM2_CH31_MASK)
/*! @} */

/*! @name DSD - Delay Start of Data Conversion */
/*! @{ */

#define SARADC_DSD_DLY_CNTR_MASK                 (0xFFFFU)
#define SARADC_DSD_DLY_CNTR_SHIFT                (0U)
#define SARADC_DSD_DLY_CNTR_WIDTH                (16U)
#define SARADC_DSD_DLY_CNTR(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_DSD_DLY_CNTR_SHIFT)) & SARADC_DSD_DLY_CNTR_MASK)
/*! @} */

/*! @name PUDLY - Power Up Delay */
/*! @{ */

#define SARADC_PUDLY_PUED_MASK                   (0x3FFU)
#define SARADC_PUDLY_PUED_SHIFT                  (0U)
#define SARADC_PUDLY_PUED_WIDTH                  (10U)
#define SARADC_PUDLY_PUED(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_PUDLY_PUED_SHIFT)) & SARADC_PUDLY_PUED_MASK)
/*! @} */

/*! @name CD0_P - Type 0 Input n Conversion Data */
/*! @{ */

#define SARADC_CD0_P_CDATA_MASK                  (0xFFFFU)
#define SARADC_CD0_P_CDATA_SHIFT                 (0U)
#define SARADC_CD0_P_CDATA_WIDTH                 (16U)
#define SARADC_CD0_P_CDATA(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD0_P_CDATA_SHIFT)) & SARADC_CD0_P_CDATA_MASK)

#define SARADC_CD0_P_RESULT_MASK                 (0x30000U)
#define SARADC_CD0_P_RESULT_SHIFT                (16U)
#define SARADC_CD0_P_RESULT_WIDTH                (2U)
#define SARADC_CD0_P_RESULT(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CD0_P_RESULT_SHIFT)) & SARADC_CD0_P_RESULT_MASK)

#define SARADC_CD0_P_OVERW_MASK                  (0x40000U)
#define SARADC_CD0_P_OVERW_SHIFT                 (18U)
#define SARADC_CD0_P_OVERW_WIDTH                 (1U)
#define SARADC_CD0_P_OVERW(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD0_P_OVERW_SHIFT)) & SARADC_CD0_P_OVERW_MASK)

#define SARADC_CD0_P_VALID_MASK                  (0x80000U)
#define SARADC_CD0_P_VALID_SHIFT                 (19U)
#define SARADC_CD0_P_VALID_WIDTH                 (1U)
#define SARADC_CD0_P_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD0_P_VALID_SHIFT)) & SARADC_CD0_P_VALID_MASK)
/*! @} */

/*! @name CD0_M - Type 0 Input n Conversion Data */
/*! @{ */

#define SARADC_CD0_M_CDATA_MASK                  (0xFFFFU)
#define SARADC_CD0_M_CDATA_SHIFT                 (0U)
#define SARADC_CD0_M_CDATA_WIDTH                 (16U)
#define SARADC_CD0_M_CDATA(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD0_M_CDATA_SHIFT)) & SARADC_CD0_M_CDATA_MASK)

#define SARADC_CD0_M_RESULT_MASK                 (0x30000U)
#define SARADC_CD0_M_RESULT_SHIFT                (16U)
#define SARADC_CD0_M_RESULT_WIDTH                (2U)
#define SARADC_CD0_M_RESULT(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CD0_M_RESULT_SHIFT)) & SARADC_CD0_M_RESULT_MASK)

#define SARADC_CD0_M_OVERW_MASK                  (0x40000U)
#define SARADC_CD0_M_OVERW_SHIFT                 (18U)
#define SARADC_CD0_M_OVERW_WIDTH                 (1U)
#define SARADC_CD0_M_OVERW(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD0_M_OVERW_SHIFT)) & SARADC_CD0_M_OVERW_MASK)

#define SARADC_CD0_M_VALID_MASK                  (0x80000U)
#define SARADC_CD0_M_VALID_SHIFT                 (19U)
#define SARADC_CD0_M_VALID_WIDTH                 (1U)
#define SARADC_CD0_M_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD0_M_VALID_SHIFT)) & SARADC_CD0_M_VALID_MASK)
/*! @} */

/*! @name CD1_P - Type 1 Input n Conversion Data */
/*! @{ */

#define SARADC_CD1_P_CDATA_MASK                  (0xFFFFU)
#define SARADC_CD1_P_CDATA_SHIFT                 (0U)
#define SARADC_CD1_P_CDATA_WIDTH                 (16U)
#define SARADC_CD1_P_CDATA(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD1_P_CDATA_SHIFT)) & SARADC_CD1_P_CDATA_MASK)

#define SARADC_CD1_P_RESULT_MASK                 (0x30000U)
#define SARADC_CD1_P_RESULT_SHIFT                (16U)
#define SARADC_CD1_P_RESULT_WIDTH                (2U)
#define SARADC_CD1_P_RESULT(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CD1_P_RESULT_SHIFT)) & SARADC_CD1_P_RESULT_MASK)

#define SARADC_CD1_P_OVERW_MASK                  (0x40000U)
#define SARADC_CD1_P_OVERW_SHIFT                 (18U)
#define SARADC_CD1_P_OVERW_WIDTH                 (1U)
#define SARADC_CD1_P_OVERW(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD1_P_OVERW_SHIFT)) & SARADC_CD1_P_OVERW_MASK)

#define SARADC_CD1_P_VALID_MASK                  (0x80000U)
#define SARADC_CD1_P_VALID_SHIFT                 (19U)
#define SARADC_CD1_P_VALID_WIDTH                 (1U)
#define SARADC_CD1_P_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD1_P_VALID_SHIFT)) & SARADC_CD1_P_VALID_MASK)
/*! @} */

/*! @name CD1_M - Type 1 Input n Conversion Data */
/*! @{ */

#define SARADC_CD1_M_CDATA_MASK                  (0xFFFFU)
#define SARADC_CD1_M_CDATA_SHIFT                 (0U)
#define SARADC_CD1_M_CDATA_WIDTH                 (16U)
#define SARADC_CD1_M_CDATA(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD1_M_CDATA_SHIFT)) & SARADC_CD1_M_CDATA_MASK)

#define SARADC_CD1_M_RESULT_MASK                 (0x30000U)
#define SARADC_CD1_M_RESULT_SHIFT                (16U)
#define SARADC_CD1_M_RESULT_WIDTH                (2U)
#define SARADC_CD1_M_RESULT(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CD1_M_RESULT_SHIFT)) & SARADC_CD1_M_RESULT_MASK)

#define SARADC_CD1_M_OVERW_MASK                  (0x40000U)
#define SARADC_CD1_M_OVERW_SHIFT                 (18U)
#define SARADC_CD1_M_OVERW_WIDTH                 (1U)
#define SARADC_CD1_M_OVERW(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD1_M_OVERW_SHIFT)) & SARADC_CD1_M_OVERW_MASK)

#define SARADC_CD1_M_VALID_MASK                  (0x80000U)
#define SARADC_CD1_M_VALID_SHIFT                 (19U)
#define SARADC_CD1_M_VALID_WIDTH                 (1U)
#define SARADC_CD1_M_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD1_M_VALID_SHIFT)) & SARADC_CD1_M_VALID_MASK)
/*! @} */

/*! @name CD2_P - Type 2 input n Conversion Data */
/*! @{ */

#define SARADC_CD2_P_CDATA_MASK                  (0xFFFFU)
#define SARADC_CD2_P_CDATA_SHIFT                 (0U)
#define SARADC_CD2_P_CDATA_WIDTH                 (16U)
#define SARADC_CD2_P_CDATA(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD2_P_CDATA_SHIFT)) & SARADC_CD2_P_CDATA_MASK)

#define SARADC_CD2_P_RESULT_MASK                 (0x30000U)
#define SARADC_CD2_P_RESULT_SHIFT                (16U)
#define SARADC_CD2_P_RESULT_WIDTH                (2U)
#define SARADC_CD2_P_RESULT(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CD2_P_RESULT_SHIFT)) & SARADC_CD2_P_RESULT_MASK)

#define SARADC_CD2_P_OVERW_MASK                  (0x40000U)
#define SARADC_CD2_P_OVERW_SHIFT                 (18U)
#define SARADC_CD2_P_OVERW_WIDTH                 (1U)
#define SARADC_CD2_P_OVERW(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD2_P_OVERW_SHIFT)) & SARADC_CD2_P_OVERW_MASK)

#define SARADC_CD2_P_VALID_MASK                  (0x80000U)
#define SARADC_CD2_P_VALID_SHIFT                 (19U)
#define SARADC_CD2_P_VALID_WIDTH                 (1U)
#define SARADC_CD2_P_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD2_P_VALID_SHIFT)) & SARADC_CD2_P_VALID_MASK)
/*! @} */

/*! @name CD2_M - Type 2 input n Conversion Data */
/*! @{ */

#define SARADC_CD2_M_CDATA_MASK                  (0xFFFFU)
#define SARADC_CD2_M_CDATA_SHIFT                 (0U)
#define SARADC_CD2_M_CDATA_WIDTH                 (16U)
#define SARADC_CD2_M_CDATA(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD2_M_CDATA_SHIFT)) & SARADC_CD2_M_CDATA_MASK)

#define SARADC_CD2_M_RESULT_MASK                 (0x30000U)
#define SARADC_CD2_M_RESULT_SHIFT                (16U)
#define SARADC_CD2_M_RESULT_WIDTH                (2U)
#define SARADC_CD2_M_RESULT(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CD2_M_RESULT_SHIFT)) & SARADC_CD2_M_RESULT_MASK)

#define SARADC_CD2_M_OVERW_MASK                  (0x40000U)
#define SARADC_CD2_M_OVERW_SHIFT                 (18U)
#define SARADC_CD2_M_OVERW_WIDTH                 (1U)
#define SARADC_CD2_M_OVERW(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD2_M_OVERW_SHIFT)) & SARADC_CD2_M_OVERW_MASK)

#define SARADC_CD2_M_VALID_MASK                  (0x80000U)
#define SARADC_CD2_M_VALID_SHIFT                 (19U)
#define SARADC_CD2_M_VALID_WIDTH                 (1U)
#define SARADC_CD2_M_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CD2_M_VALID_SHIFT)) & SARADC_CD2_M_VALID_MASK)
/*! @} */

/*! @name CWSEL_0_0 - Channel Analog Watchdog Select for Type 0 */
/*! @{ */

#define SARADC_CWSEL_0_0_WSEL_T00_0_MASK         (0x3U)
#define SARADC_CWSEL_0_0_WSEL_T00_0_SHIFT        (0U)
#define SARADC_CWSEL_0_0_WSEL_T00_0_WIDTH        (2U)
#define SARADC_CWSEL_0_0_WSEL_T00_0(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_0_WSEL_T00_0_SHIFT)) & SARADC_CWSEL_0_0_WSEL_T00_0_MASK)

#define SARADC_CWSEL_0_0_WSEL_T00_1_MASK         (0x30U)
#define SARADC_CWSEL_0_0_WSEL_T00_1_SHIFT        (4U)
#define SARADC_CWSEL_0_0_WSEL_T00_1_WIDTH        (2U)
#define SARADC_CWSEL_0_0_WSEL_T00_1(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_0_WSEL_T00_1_SHIFT)) & SARADC_CWSEL_0_0_WSEL_T00_1_MASK)

#define SARADC_CWSEL_0_0_WSEL_T00_2_MASK         (0x300U)
#define SARADC_CWSEL_0_0_WSEL_T00_2_SHIFT        (8U)
#define SARADC_CWSEL_0_0_WSEL_T00_2_WIDTH        (2U)
#define SARADC_CWSEL_0_0_WSEL_T00_2(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_0_WSEL_T00_2_SHIFT)) & SARADC_CWSEL_0_0_WSEL_T00_2_MASK)

#define SARADC_CWSEL_0_0_WSEL_T00_3_MASK         (0x3000U)
#define SARADC_CWSEL_0_0_WSEL_T00_3_SHIFT        (12U)
#define SARADC_CWSEL_0_0_WSEL_T00_3_WIDTH        (2U)
#define SARADC_CWSEL_0_0_WSEL_T00_3(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_0_WSEL_T00_3_SHIFT)) & SARADC_CWSEL_0_0_WSEL_T00_3_MASK)

#define SARADC_CWSEL_0_0_WSEL_T00_4_MASK         (0x30000U)
#define SARADC_CWSEL_0_0_WSEL_T00_4_SHIFT        (16U)
#define SARADC_CWSEL_0_0_WSEL_T00_4_WIDTH        (2U)
#define SARADC_CWSEL_0_0_WSEL_T00_4(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_0_WSEL_T00_4_SHIFT)) & SARADC_CWSEL_0_0_WSEL_T00_4_MASK)

#define SARADC_CWSEL_0_0_WSEL_T00_5_MASK         (0x300000U)
#define SARADC_CWSEL_0_0_WSEL_T00_5_SHIFT        (20U)
#define SARADC_CWSEL_0_0_WSEL_T00_5_WIDTH        (2U)
#define SARADC_CWSEL_0_0_WSEL_T00_5(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_0_WSEL_T00_5_SHIFT)) & SARADC_CWSEL_0_0_WSEL_T00_5_MASK)

#define SARADC_CWSEL_0_0_WSEL_T00_6_MASK         (0x3000000U)
#define SARADC_CWSEL_0_0_WSEL_T00_6_SHIFT        (24U)
#define SARADC_CWSEL_0_0_WSEL_T00_6_WIDTH        (2U)
#define SARADC_CWSEL_0_0_WSEL_T00_6(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_0_WSEL_T00_6_SHIFT)) & SARADC_CWSEL_0_0_WSEL_T00_6_MASK)

#define SARADC_CWSEL_0_0_WSEL_T00_7_MASK         (0x30000000U)
#define SARADC_CWSEL_0_0_WSEL_T00_7_SHIFT        (28U)
#define SARADC_CWSEL_0_0_WSEL_T00_7_WIDTH        (2U)
#define SARADC_CWSEL_0_0_WSEL_T00_7(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_0_WSEL_T00_7_SHIFT)) & SARADC_CWSEL_0_0_WSEL_T00_7_MASK)
/*! @} */

/*! @name CWSEL_0_1 - Channel Analog Watchdog Select for Type 0 */
/*! @{ */

#define SARADC_CWSEL_0_1_WSEL_T01_8_MASK         (0x3U)
#define SARADC_CWSEL_0_1_WSEL_T01_8_SHIFT        (0U)
#define SARADC_CWSEL_0_1_WSEL_T01_8_WIDTH        (2U)
#define SARADC_CWSEL_0_1_WSEL_T01_8(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_1_WSEL_T01_8_SHIFT)) & SARADC_CWSEL_0_1_WSEL_T01_8_MASK)

#define SARADC_CWSEL_0_1_WSEL_T01_9_MASK         (0x30U)
#define SARADC_CWSEL_0_1_WSEL_T01_9_SHIFT        (4U)
#define SARADC_CWSEL_0_1_WSEL_T01_9_WIDTH        (2U)
#define SARADC_CWSEL_0_1_WSEL_T01_9(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_1_WSEL_T01_9_SHIFT)) & SARADC_CWSEL_0_1_WSEL_T01_9_MASK)

#define SARADC_CWSEL_0_1_WSEL_T01_10_MASK        (0x300U)
#define SARADC_CWSEL_0_1_WSEL_T01_10_SHIFT       (8U)
#define SARADC_CWSEL_0_1_WSEL_T01_10_WIDTH       (2U)
#define SARADC_CWSEL_0_1_WSEL_T01_10(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_1_WSEL_T01_10_SHIFT)) & SARADC_CWSEL_0_1_WSEL_T01_10_MASK)

#define SARADC_CWSEL_0_1_WSEL_T01_11_MASK        (0x3000U)
#define SARADC_CWSEL_0_1_WSEL_T01_11_SHIFT       (12U)
#define SARADC_CWSEL_0_1_WSEL_T01_11_WIDTH       (2U)
#define SARADC_CWSEL_0_1_WSEL_T01_11(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_1_WSEL_T01_11_SHIFT)) & SARADC_CWSEL_0_1_WSEL_T01_11_MASK)

#define SARADC_CWSEL_0_1_WSEL_T01_12_MASK        (0x30000U)
#define SARADC_CWSEL_0_1_WSEL_T01_12_SHIFT       (16U)
#define SARADC_CWSEL_0_1_WSEL_T01_12_WIDTH       (2U)
#define SARADC_CWSEL_0_1_WSEL_T01_12(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_1_WSEL_T01_12_SHIFT)) & SARADC_CWSEL_0_1_WSEL_T01_12_MASK)

#define SARADC_CWSEL_0_1_WSEL_T01_13_MASK        (0x300000U)
#define SARADC_CWSEL_0_1_WSEL_T01_13_SHIFT       (20U)
#define SARADC_CWSEL_0_1_WSEL_T01_13_WIDTH       (2U)
#define SARADC_CWSEL_0_1_WSEL_T01_13(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_1_WSEL_T01_13_SHIFT)) & SARADC_CWSEL_0_1_WSEL_T01_13_MASK)

#define SARADC_CWSEL_0_1_WSEL_T01_14_MASK        (0x3000000U)
#define SARADC_CWSEL_0_1_WSEL_T01_14_SHIFT       (24U)
#define SARADC_CWSEL_0_1_WSEL_T01_14_WIDTH       (2U)
#define SARADC_CWSEL_0_1_WSEL_T01_14(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_1_WSEL_T01_14_SHIFT)) & SARADC_CWSEL_0_1_WSEL_T01_14_MASK)

#define SARADC_CWSEL_0_1_WSEL_T01_15_MASK        (0x30000000U)
#define SARADC_CWSEL_0_1_WSEL_T01_15_SHIFT       (28U)
#define SARADC_CWSEL_0_1_WSEL_T01_15_WIDTH       (2U)
#define SARADC_CWSEL_0_1_WSEL_T01_15(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_1_WSEL_T01_15_SHIFT)) & SARADC_CWSEL_0_1_WSEL_T01_15_MASK)
/*! @} */

/*! @name CWSEL_0_2 - Channel Analog Watchdog Select for Type 0 */
/*! @{ */

#define SARADC_CWSEL_0_2_WSEL_T02_16_MASK        (0x3U)
#define SARADC_CWSEL_0_2_WSEL_T02_16_SHIFT       (0U)
#define SARADC_CWSEL_0_2_WSEL_T02_16_WIDTH       (2U)
#define SARADC_CWSEL_0_2_WSEL_T02_16(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_2_WSEL_T02_16_SHIFT)) & SARADC_CWSEL_0_2_WSEL_T02_16_MASK)

#define SARADC_CWSEL_0_2_WSEL_T02_17_MASK        (0x30U)
#define SARADC_CWSEL_0_2_WSEL_T02_17_SHIFT       (4U)
#define SARADC_CWSEL_0_2_WSEL_T02_17_WIDTH       (2U)
#define SARADC_CWSEL_0_2_WSEL_T02_17(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_2_WSEL_T02_17_SHIFT)) & SARADC_CWSEL_0_2_WSEL_T02_17_MASK)

#define SARADC_CWSEL_0_2_WSEL_T02_18_MASK        (0x300U)
#define SARADC_CWSEL_0_2_WSEL_T02_18_SHIFT       (8U)
#define SARADC_CWSEL_0_2_WSEL_T02_18_WIDTH       (2U)
#define SARADC_CWSEL_0_2_WSEL_T02_18(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_2_WSEL_T02_18_SHIFT)) & SARADC_CWSEL_0_2_WSEL_T02_18_MASK)

#define SARADC_CWSEL_0_2_WSEL_T02_19_MASK        (0x3000U)
#define SARADC_CWSEL_0_2_WSEL_T02_19_SHIFT       (12U)
#define SARADC_CWSEL_0_2_WSEL_T02_19_WIDTH       (2U)
#define SARADC_CWSEL_0_2_WSEL_T02_19(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_2_WSEL_T02_19_SHIFT)) & SARADC_CWSEL_0_2_WSEL_T02_19_MASK)

#define SARADC_CWSEL_0_2_WSEL_T02_20_MASK        (0x30000U)
#define SARADC_CWSEL_0_2_WSEL_T02_20_SHIFT       (16U)
#define SARADC_CWSEL_0_2_WSEL_T02_20_WIDTH       (2U)
#define SARADC_CWSEL_0_2_WSEL_T02_20(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_2_WSEL_T02_20_SHIFT)) & SARADC_CWSEL_0_2_WSEL_T02_20_MASK)

#define SARADC_CWSEL_0_2_WSEL_T02_21_MASK        (0x300000U)
#define SARADC_CWSEL_0_2_WSEL_T02_21_SHIFT       (20U)
#define SARADC_CWSEL_0_2_WSEL_T02_21_WIDTH       (2U)
#define SARADC_CWSEL_0_2_WSEL_T02_21(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_2_WSEL_T02_21_SHIFT)) & SARADC_CWSEL_0_2_WSEL_T02_21_MASK)

#define SARADC_CWSEL_0_2_WSEL_T02_22_MASK        (0x3000000U)
#define SARADC_CWSEL_0_2_WSEL_T02_22_SHIFT       (24U)
#define SARADC_CWSEL_0_2_WSEL_T02_22_WIDTH       (2U)
#define SARADC_CWSEL_0_2_WSEL_T02_22(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_2_WSEL_T02_22_SHIFT)) & SARADC_CWSEL_0_2_WSEL_T02_22_MASK)

#define SARADC_CWSEL_0_2_WSEL_T02_23_MASK        (0x30000000U)
#define SARADC_CWSEL_0_2_WSEL_T02_23_SHIFT       (28U)
#define SARADC_CWSEL_0_2_WSEL_T02_23_WIDTH       (2U)
#define SARADC_CWSEL_0_2_WSEL_T02_23(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_2_WSEL_T02_23_SHIFT)) & SARADC_CWSEL_0_2_WSEL_T02_23_MASK)
/*! @} */

/*! @name CWSEL_0_3 - Channel Analog Watchdog Select for Type 0 */
/*! @{ */

#define SARADC_CWSEL_0_3_WSEL_T03_24_MASK        (0x3U)
#define SARADC_CWSEL_0_3_WSEL_T03_24_SHIFT       (0U)
#define SARADC_CWSEL_0_3_WSEL_T03_24_WIDTH       (2U)
#define SARADC_CWSEL_0_3_WSEL_T03_24(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_3_WSEL_T03_24_SHIFT)) & SARADC_CWSEL_0_3_WSEL_T03_24_MASK)

#define SARADC_CWSEL_0_3_WSEL_T03_25_MASK        (0x30U)
#define SARADC_CWSEL_0_3_WSEL_T03_25_SHIFT       (4U)
#define SARADC_CWSEL_0_3_WSEL_T03_25_WIDTH       (2U)
#define SARADC_CWSEL_0_3_WSEL_T03_25(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_3_WSEL_T03_25_SHIFT)) & SARADC_CWSEL_0_3_WSEL_T03_25_MASK)

#define SARADC_CWSEL_0_3_WSEL_T03_26_MASK        (0x300U)
#define SARADC_CWSEL_0_3_WSEL_T03_26_SHIFT       (8U)
#define SARADC_CWSEL_0_3_WSEL_T03_26_WIDTH       (2U)
#define SARADC_CWSEL_0_3_WSEL_T03_26(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_3_WSEL_T03_26_SHIFT)) & SARADC_CWSEL_0_3_WSEL_T03_26_MASK)

#define SARADC_CWSEL_0_3_WSEL_T03_27_MASK        (0x3000U)
#define SARADC_CWSEL_0_3_WSEL_T03_27_SHIFT       (12U)
#define SARADC_CWSEL_0_3_WSEL_T03_27_WIDTH       (2U)
#define SARADC_CWSEL_0_3_WSEL_T03_27(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_3_WSEL_T03_27_SHIFT)) & SARADC_CWSEL_0_3_WSEL_T03_27_MASK)

#define SARADC_CWSEL_0_3_WSEL_T03_28_MASK        (0x30000U)
#define SARADC_CWSEL_0_3_WSEL_T03_28_SHIFT       (16U)
#define SARADC_CWSEL_0_3_WSEL_T03_28_WIDTH       (2U)
#define SARADC_CWSEL_0_3_WSEL_T03_28(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_3_WSEL_T03_28_SHIFT)) & SARADC_CWSEL_0_3_WSEL_T03_28_MASK)

#define SARADC_CWSEL_0_3_WSEL_T03_29_MASK        (0x300000U)
#define SARADC_CWSEL_0_3_WSEL_T03_29_SHIFT       (20U)
#define SARADC_CWSEL_0_3_WSEL_T03_29_WIDTH       (2U)
#define SARADC_CWSEL_0_3_WSEL_T03_29(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_3_WSEL_T03_29_SHIFT)) & SARADC_CWSEL_0_3_WSEL_T03_29_MASK)

#define SARADC_CWSEL_0_3_WSEL_T03_30_MASK        (0x3000000U)
#define SARADC_CWSEL_0_3_WSEL_T03_30_SHIFT       (24U)
#define SARADC_CWSEL_0_3_WSEL_T03_30_WIDTH       (2U)
#define SARADC_CWSEL_0_3_WSEL_T03_30(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_3_WSEL_T03_30_SHIFT)) & SARADC_CWSEL_0_3_WSEL_T03_30_MASK)

#define SARADC_CWSEL_0_3_WSEL_T03_31_MASK        (0x30000000U)
#define SARADC_CWSEL_0_3_WSEL_T03_31_SHIFT       (28U)
#define SARADC_CWSEL_0_3_WSEL_T03_31_WIDTH       (2U)
#define SARADC_CWSEL_0_3_WSEL_T03_31(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_0_3_WSEL_T03_31_SHIFT)) & SARADC_CWSEL_0_3_WSEL_T03_31_MASK)
/*! @} */

/*! @name CWSEL_1_0 - Channel Analog Watchdog Select for Type 1 */
/*! @{ */

#define SARADC_CWSEL_1_0_WSEL_T10_0_MASK         (0x3U)
#define SARADC_CWSEL_1_0_WSEL_T10_0_SHIFT        (0U)
#define SARADC_CWSEL_1_0_WSEL_T10_0_WIDTH        (2U)
#define SARADC_CWSEL_1_0_WSEL_T10_0(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_0_WSEL_T10_0_SHIFT)) & SARADC_CWSEL_1_0_WSEL_T10_0_MASK)

#define SARADC_CWSEL_1_0_WSEL_T10_1_MASK         (0x30U)
#define SARADC_CWSEL_1_0_WSEL_T10_1_SHIFT        (4U)
#define SARADC_CWSEL_1_0_WSEL_T10_1_WIDTH        (2U)
#define SARADC_CWSEL_1_0_WSEL_T10_1(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_0_WSEL_T10_1_SHIFT)) & SARADC_CWSEL_1_0_WSEL_T10_1_MASK)

#define SARADC_CWSEL_1_0_WSEL_T10_2_MASK         (0x300U)
#define SARADC_CWSEL_1_0_WSEL_T10_2_SHIFT        (8U)
#define SARADC_CWSEL_1_0_WSEL_T10_2_WIDTH        (2U)
#define SARADC_CWSEL_1_0_WSEL_T10_2(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_0_WSEL_T10_2_SHIFT)) & SARADC_CWSEL_1_0_WSEL_T10_2_MASK)

#define SARADC_CWSEL_1_0_WSEL_T10_3_MASK         (0x3000U)
#define SARADC_CWSEL_1_0_WSEL_T10_3_SHIFT        (12U)
#define SARADC_CWSEL_1_0_WSEL_T10_3_WIDTH        (2U)
#define SARADC_CWSEL_1_0_WSEL_T10_3(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_0_WSEL_T10_3_SHIFT)) & SARADC_CWSEL_1_0_WSEL_T10_3_MASK)

#define SARADC_CWSEL_1_0_WSEL_T10_4_MASK         (0x30000U)
#define SARADC_CWSEL_1_0_WSEL_T10_4_SHIFT        (16U)
#define SARADC_CWSEL_1_0_WSEL_T10_4_WIDTH        (2U)
#define SARADC_CWSEL_1_0_WSEL_T10_4(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_0_WSEL_T10_4_SHIFT)) & SARADC_CWSEL_1_0_WSEL_T10_4_MASK)

#define SARADC_CWSEL_1_0_WSEL_T10_5_MASK         (0x300000U)
#define SARADC_CWSEL_1_0_WSEL_T10_5_SHIFT        (20U)
#define SARADC_CWSEL_1_0_WSEL_T10_5_WIDTH        (2U)
#define SARADC_CWSEL_1_0_WSEL_T10_5(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_0_WSEL_T10_5_SHIFT)) & SARADC_CWSEL_1_0_WSEL_T10_5_MASK)

#define SARADC_CWSEL_1_0_WSEL_T10_6_MASK         (0x3000000U)
#define SARADC_CWSEL_1_0_WSEL_T10_6_SHIFT        (24U)
#define SARADC_CWSEL_1_0_WSEL_T10_6_WIDTH        (2U)
#define SARADC_CWSEL_1_0_WSEL_T10_6(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_0_WSEL_T10_6_SHIFT)) & SARADC_CWSEL_1_0_WSEL_T10_6_MASK)

#define SARADC_CWSEL_1_0_WSEL_T10_7_MASK         (0x30000000U)
#define SARADC_CWSEL_1_0_WSEL_T10_7_SHIFT        (28U)
#define SARADC_CWSEL_1_0_WSEL_T10_7_WIDTH        (2U)
#define SARADC_CWSEL_1_0_WSEL_T10_7(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_0_WSEL_T10_7_SHIFT)) & SARADC_CWSEL_1_0_WSEL_T10_7_MASK)
/*! @} */

/*! @name CWSEL_1_1 - Channel Analog Watchdog Select for Type 1 */
/*! @{ */

#define SARADC_CWSEL_1_1_WSEL_T11_8_MASK         (0x3U)
#define SARADC_CWSEL_1_1_WSEL_T11_8_SHIFT        (0U)
#define SARADC_CWSEL_1_1_WSEL_T11_8_WIDTH        (2U)
#define SARADC_CWSEL_1_1_WSEL_T11_8(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_1_WSEL_T11_8_SHIFT)) & SARADC_CWSEL_1_1_WSEL_T11_8_MASK)

#define SARADC_CWSEL_1_1_WSEL_T11_9_MASK         (0x30U)
#define SARADC_CWSEL_1_1_WSEL_T11_9_SHIFT        (4U)
#define SARADC_CWSEL_1_1_WSEL_T11_9_WIDTH        (2U)
#define SARADC_CWSEL_1_1_WSEL_T11_9(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_1_WSEL_T11_9_SHIFT)) & SARADC_CWSEL_1_1_WSEL_T11_9_MASK)

#define SARADC_CWSEL_1_1_WSEL_T11_10_MASK        (0x300U)
#define SARADC_CWSEL_1_1_WSEL_T11_10_SHIFT       (8U)
#define SARADC_CWSEL_1_1_WSEL_T11_10_WIDTH       (2U)
#define SARADC_CWSEL_1_1_WSEL_T11_10(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_1_WSEL_T11_10_SHIFT)) & SARADC_CWSEL_1_1_WSEL_T11_10_MASK)
/*! @} */

/*! @name CWSEL_1_2 - Channel Analog Watchdog Select for Type 1 */
/*! @{ */

#define SARADC_CWSEL_1_2_WSEL_T12_16_MASK        (0x3U)
#define SARADC_CWSEL_1_2_WSEL_T12_16_SHIFT       (0U)
#define SARADC_CWSEL_1_2_WSEL_T12_16_WIDTH       (2U)
#define SARADC_CWSEL_1_2_WSEL_T12_16(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_2_WSEL_T12_16_SHIFT)) & SARADC_CWSEL_1_2_WSEL_T12_16_MASK)

#define SARADC_CWSEL_1_2_WSEL_T12_17_MASK        (0x30U)
#define SARADC_CWSEL_1_2_WSEL_T12_17_SHIFT       (4U)
#define SARADC_CWSEL_1_2_WSEL_T12_17_WIDTH       (2U)
#define SARADC_CWSEL_1_2_WSEL_T12_17(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_2_WSEL_T12_17_SHIFT)) & SARADC_CWSEL_1_2_WSEL_T12_17_MASK)

#define SARADC_CWSEL_1_2_WSEL_T12_18_MASK        (0x300U)
#define SARADC_CWSEL_1_2_WSEL_T12_18_SHIFT       (8U)
#define SARADC_CWSEL_1_2_WSEL_T12_18_WIDTH       (2U)
#define SARADC_CWSEL_1_2_WSEL_T12_18(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_2_WSEL_T12_18_SHIFT)) & SARADC_CWSEL_1_2_WSEL_T12_18_MASK)

#define SARADC_CWSEL_1_2_WSEL_T12_19_MASK        (0x3000U)
#define SARADC_CWSEL_1_2_WSEL_T12_19_SHIFT       (12U)
#define SARADC_CWSEL_1_2_WSEL_T12_19_WIDTH       (2U)
#define SARADC_CWSEL_1_2_WSEL_T12_19(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_2_WSEL_T12_19_SHIFT)) & SARADC_CWSEL_1_2_WSEL_T12_19_MASK)

#define SARADC_CWSEL_1_2_WSEL_T12_20_MASK        (0x30000U)
#define SARADC_CWSEL_1_2_WSEL_T12_20_SHIFT       (16U)
#define SARADC_CWSEL_1_2_WSEL_T12_20_WIDTH       (2U)
#define SARADC_CWSEL_1_2_WSEL_T12_20(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_2_WSEL_T12_20_SHIFT)) & SARADC_CWSEL_1_2_WSEL_T12_20_MASK)

#define SARADC_CWSEL_1_2_WSEL_T12_21_MASK        (0x300000U)
#define SARADC_CWSEL_1_2_WSEL_T12_21_SHIFT       (20U)
#define SARADC_CWSEL_1_2_WSEL_T12_21_WIDTH       (2U)
#define SARADC_CWSEL_1_2_WSEL_T12_21(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_2_WSEL_T12_21_SHIFT)) & SARADC_CWSEL_1_2_WSEL_T12_21_MASK)

#define SARADC_CWSEL_1_2_WSEL_T12_22_MASK        (0x3000000U)
#define SARADC_CWSEL_1_2_WSEL_T12_22_SHIFT       (24U)
#define SARADC_CWSEL_1_2_WSEL_T12_22_WIDTH       (2U)
#define SARADC_CWSEL_1_2_WSEL_T12_22(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_2_WSEL_T12_22_SHIFT)) & SARADC_CWSEL_1_2_WSEL_T12_22_MASK)

#define SARADC_CWSEL_1_2_WSEL_T12_23_MASK        (0x30000000U)
#define SARADC_CWSEL_1_2_WSEL_T12_23_SHIFT       (28U)
#define SARADC_CWSEL_1_2_WSEL_T12_23_WIDTH       (2U)
#define SARADC_CWSEL_1_2_WSEL_T12_23(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_2_WSEL_T12_23_SHIFT)) & SARADC_CWSEL_1_2_WSEL_T12_23_MASK)
/*! @} */

/*! @name CWSEL_1_3 - Channel Analog Watchdog Select for Type 1 */
/*! @{ */

#define SARADC_CWSEL_1_3_WSEL_T13_24_MASK        (0x3U)
#define SARADC_CWSEL_1_3_WSEL_T13_24_SHIFT       (0U)
#define SARADC_CWSEL_1_3_WSEL_T13_24_WIDTH       (2U)
#define SARADC_CWSEL_1_3_WSEL_T13_24(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_3_WSEL_T13_24_SHIFT)) & SARADC_CWSEL_1_3_WSEL_T13_24_MASK)

#define SARADC_CWSEL_1_3_WSEL_T13_25_MASK        (0x30U)
#define SARADC_CWSEL_1_3_WSEL_T13_25_SHIFT       (4U)
#define SARADC_CWSEL_1_3_WSEL_T13_25_WIDTH       (2U)
#define SARADC_CWSEL_1_3_WSEL_T13_25(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_3_WSEL_T13_25_SHIFT)) & SARADC_CWSEL_1_3_WSEL_T13_25_MASK)

#define SARADC_CWSEL_1_3_WSEL_T13_26_MASK        (0x300U)
#define SARADC_CWSEL_1_3_WSEL_T13_26_SHIFT       (8U)
#define SARADC_CWSEL_1_3_WSEL_T13_26_WIDTH       (2U)
#define SARADC_CWSEL_1_3_WSEL_T13_26(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_1_3_WSEL_T13_26_SHIFT)) & SARADC_CWSEL_1_3_WSEL_T13_26_MASK)
/*! @} */

/*! @name CWSEL_2_0 - Channel Analog Watchdog Select for Type 2 */
/*! @{ */

#define SARADC_CWSEL_2_0_WSEL_T20_0_MASK         (0x3U)
#define SARADC_CWSEL_2_0_WSEL_T20_0_SHIFT        (0U)
#define SARADC_CWSEL_2_0_WSEL_T20_0_WIDTH        (2U)
#define SARADC_CWSEL_2_0_WSEL_T20_0(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_0_WSEL_T20_0_SHIFT)) & SARADC_CWSEL_2_0_WSEL_T20_0_MASK)

#define SARADC_CWSEL_2_0_WSEL_T20_1_MASK         (0x30U)
#define SARADC_CWSEL_2_0_WSEL_T20_1_SHIFT        (4U)
#define SARADC_CWSEL_2_0_WSEL_T20_1_WIDTH        (2U)
#define SARADC_CWSEL_2_0_WSEL_T20_1(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_0_WSEL_T20_1_SHIFT)) & SARADC_CWSEL_2_0_WSEL_T20_1_MASK)

#define SARADC_CWSEL_2_0_WSEL_T20_2_MASK         (0x300U)
#define SARADC_CWSEL_2_0_WSEL_T20_2_SHIFT        (8U)
#define SARADC_CWSEL_2_0_WSEL_T20_2_WIDTH        (2U)
#define SARADC_CWSEL_2_0_WSEL_T20_2(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_0_WSEL_T20_2_SHIFT)) & SARADC_CWSEL_2_0_WSEL_T20_2_MASK)

#define SARADC_CWSEL_2_0_WSEL_T20_3_MASK         (0x3000U)
#define SARADC_CWSEL_2_0_WSEL_T20_3_SHIFT        (12U)
#define SARADC_CWSEL_2_0_WSEL_T20_3_WIDTH        (2U)
#define SARADC_CWSEL_2_0_WSEL_T20_3(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_0_WSEL_T20_3_SHIFT)) & SARADC_CWSEL_2_0_WSEL_T20_3_MASK)

#define SARADC_CWSEL_2_0_WSEL_T20_4_MASK         (0x30000U)
#define SARADC_CWSEL_2_0_WSEL_T20_4_SHIFT        (16U)
#define SARADC_CWSEL_2_0_WSEL_T20_4_WIDTH        (2U)
#define SARADC_CWSEL_2_0_WSEL_T20_4(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_0_WSEL_T20_4_SHIFT)) & SARADC_CWSEL_2_0_WSEL_T20_4_MASK)

#define SARADC_CWSEL_2_0_WSEL_T20_5_MASK         (0x300000U)
#define SARADC_CWSEL_2_0_WSEL_T20_5_SHIFT        (20U)
#define SARADC_CWSEL_2_0_WSEL_T20_5_WIDTH        (2U)
#define SARADC_CWSEL_2_0_WSEL_T20_5(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_0_WSEL_T20_5_SHIFT)) & SARADC_CWSEL_2_0_WSEL_T20_5_MASK)

#define SARADC_CWSEL_2_0_WSEL_T20_6_MASK         (0x3000000U)
#define SARADC_CWSEL_2_0_WSEL_T20_6_SHIFT        (24U)
#define SARADC_CWSEL_2_0_WSEL_T20_6_WIDTH        (2U)
#define SARADC_CWSEL_2_0_WSEL_T20_6(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_0_WSEL_T20_6_SHIFT)) & SARADC_CWSEL_2_0_WSEL_T20_6_MASK)

#define SARADC_CWSEL_2_0_WSEL_T20_7_MASK         (0x30000000U)
#define SARADC_CWSEL_2_0_WSEL_T20_7_SHIFT        (28U)
#define SARADC_CWSEL_2_0_WSEL_T20_7_WIDTH        (2U)
#define SARADC_CWSEL_2_0_WSEL_T20_7(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_0_WSEL_T20_7_SHIFT)) & SARADC_CWSEL_2_0_WSEL_T20_7_MASK)
/*! @} */

/*! @name CWSEL_2_1 - Channel Analog Watchdog Select for Type 2 */
/*! @{ */

#define SARADC_CWSEL_2_1_WSEL_T21_8_MASK         (0x3U)
#define SARADC_CWSEL_2_1_WSEL_T21_8_SHIFT        (0U)
#define SARADC_CWSEL_2_1_WSEL_T21_8_WIDTH        (2U)
#define SARADC_CWSEL_2_1_WSEL_T21_8(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_1_WSEL_T21_8_SHIFT)) & SARADC_CWSEL_2_1_WSEL_T21_8_MASK)

#define SARADC_CWSEL_2_1_WSEL_T21_9_MASK         (0x30U)
#define SARADC_CWSEL_2_1_WSEL_T21_9_SHIFT        (4U)
#define SARADC_CWSEL_2_1_WSEL_T21_9_WIDTH        (2U)
#define SARADC_CWSEL_2_1_WSEL_T21_9(x)           (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_1_WSEL_T21_9_SHIFT)) & SARADC_CWSEL_2_1_WSEL_T21_9_MASK)

#define SARADC_CWSEL_2_1_WSEL_T21_10_MASK        (0x300U)
#define SARADC_CWSEL_2_1_WSEL_T21_10_SHIFT       (8U)
#define SARADC_CWSEL_2_1_WSEL_T21_10_WIDTH       (2U)
#define SARADC_CWSEL_2_1_WSEL_T21_10(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_1_WSEL_T21_10_SHIFT)) & SARADC_CWSEL_2_1_WSEL_T21_10_MASK)

#define SARADC_CWSEL_2_1_WSEL_T21_11_MASK        (0x3000U)
#define SARADC_CWSEL_2_1_WSEL_T21_11_SHIFT       (12U)
#define SARADC_CWSEL_2_1_WSEL_T21_11_WIDTH       (2U)
#define SARADC_CWSEL_2_1_WSEL_T21_11(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_1_WSEL_T21_11_SHIFT)) & SARADC_CWSEL_2_1_WSEL_T21_11_MASK)

#define SARADC_CWSEL_2_1_WSEL_T21_12_MASK        (0x30000U)
#define SARADC_CWSEL_2_1_WSEL_T21_12_SHIFT       (16U)
#define SARADC_CWSEL_2_1_WSEL_T21_12_WIDTH       (2U)
#define SARADC_CWSEL_2_1_WSEL_T21_12(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_1_WSEL_T21_12_SHIFT)) & SARADC_CWSEL_2_1_WSEL_T21_12_MASK)

#define SARADC_CWSEL_2_1_WSEL_T21_13_MASK        (0x300000U)
#define SARADC_CWSEL_2_1_WSEL_T21_13_SHIFT       (20U)
#define SARADC_CWSEL_2_1_WSEL_T21_13_WIDTH       (2U)
#define SARADC_CWSEL_2_1_WSEL_T21_13(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_1_WSEL_T21_13_SHIFT)) & SARADC_CWSEL_2_1_WSEL_T21_13_MASK)

#define SARADC_CWSEL_2_1_WSEL_T21_14_MASK        (0x3000000U)
#define SARADC_CWSEL_2_1_WSEL_T21_14_SHIFT       (24U)
#define SARADC_CWSEL_2_1_WSEL_T21_14_WIDTH       (2U)
#define SARADC_CWSEL_2_1_WSEL_T21_14(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_1_WSEL_T21_14_SHIFT)) & SARADC_CWSEL_2_1_WSEL_T21_14_MASK)

#define SARADC_CWSEL_2_1_WSEL_T21_15_MASK        (0x30000000U)
#define SARADC_CWSEL_2_1_WSEL_T21_15_SHIFT       (28U)
#define SARADC_CWSEL_2_1_WSEL_T21_15_WIDTH       (2U)
#define SARADC_CWSEL_2_1_WSEL_T21_15(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_1_WSEL_T21_15_SHIFT)) & SARADC_CWSEL_2_1_WSEL_T21_15_MASK)
/*! @} */

/*! @name CWSEL_2_2 - Channel Analog Watchdog Select for Type 2 */
/*! @{ */

#define SARADC_CWSEL_2_2_WSEL_T22_16_MASK        (0x3U)
#define SARADC_CWSEL_2_2_WSEL_T22_16_SHIFT       (0U)
#define SARADC_CWSEL_2_2_WSEL_T22_16_WIDTH       (2U)
#define SARADC_CWSEL_2_2_WSEL_T22_16(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_2_WSEL_T22_16_SHIFT)) & SARADC_CWSEL_2_2_WSEL_T22_16_MASK)

#define SARADC_CWSEL_2_2_WSEL_T22_17_MASK        (0x30U)
#define SARADC_CWSEL_2_2_WSEL_T22_17_SHIFT       (4U)
#define SARADC_CWSEL_2_2_WSEL_T22_17_WIDTH       (2U)
#define SARADC_CWSEL_2_2_WSEL_T22_17(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_2_WSEL_T22_17_SHIFT)) & SARADC_CWSEL_2_2_WSEL_T22_17_MASK)

#define SARADC_CWSEL_2_2_WSEL_T22_18_MASK        (0x300U)
#define SARADC_CWSEL_2_2_WSEL_T22_18_SHIFT       (8U)
#define SARADC_CWSEL_2_2_WSEL_T22_18_WIDTH       (2U)
#define SARADC_CWSEL_2_2_WSEL_T22_18(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_2_WSEL_T22_18_SHIFT)) & SARADC_CWSEL_2_2_WSEL_T22_18_MASK)

#define SARADC_CWSEL_2_2_WSEL_T22_19_MASK        (0x3000U)
#define SARADC_CWSEL_2_2_WSEL_T22_19_SHIFT       (12U)
#define SARADC_CWSEL_2_2_WSEL_T22_19_WIDTH       (2U)
#define SARADC_CWSEL_2_2_WSEL_T22_19(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_2_WSEL_T22_19_SHIFT)) & SARADC_CWSEL_2_2_WSEL_T22_19_MASK)

#define SARADC_CWSEL_2_2_WSEL_T22_20_MASK        (0x30000U)
#define SARADC_CWSEL_2_2_WSEL_T22_20_SHIFT       (16U)
#define SARADC_CWSEL_2_2_WSEL_T22_20_WIDTH       (2U)
#define SARADC_CWSEL_2_2_WSEL_T22_20(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_2_WSEL_T22_20_SHIFT)) & SARADC_CWSEL_2_2_WSEL_T22_20_MASK)

#define SARADC_CWSEL_2_2_WSEL_T22_21_MASK        (0x300000U)
#define SARADC_CWSEL_2_2_WSEL_T22_21_SHIFT       (20U)
#define SARADC_CWSEL_2_2_WSEL_T22_21_WIDTH       (2U)
#define SARADC_CWSEL_2_2_WSEL_T22_21(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_2_WSEL_T22_21_SHIFT)) & SARADC_CWSEL_2_2_WSEL_T22_21_MASK)

#define SARADC_CWSEL_2_2_WSEL_T22_22_MASK        (0x3000000U)
#define SARADC_CWSEL_2_2_WSEL_T22_22_SHIFT       (24U)
#define SARADC_CWSEL_2_2_WSEL_T22_22_WIDTH       (2U)
#define SARADC_CWSEL_2_2_WSEL_T22_22(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_2_WSEL_T22_22_SHIFT)) & SARADC_CWSEL_2_2_WSEL_T22_22_MASK)

#define SARADC_CWSEL_2_2_WSEL_T22_23_MASK        (0x30000000U)
#define SARADC_CWSEL_2_2_WSEL_T22_23_SHIFT       (28U)
#define SARADC_CWSEL_2_2_WSEL_T22_23_WIDTH       (2U)
#define SARADC_CWSEL_2_2_WSEL_T22_23(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_2_WSEL_T22_23_SHIFT)) & SARADC_CWSEL_2_2_WSEL_T22_23_MASK)
/*! @} */

/*! @name CWSEL_2_3 - Channel Analog Watchdog Select for Type 2 */
/*! @{ */

#define SARADC_CWSEL_2_3_WSEL_T23_24_MASK        (0x3U)
#define SARADC_CWSEL_2_3_WSEL_T23_24_SHIFT       (0U)
#define SARADC_CWSEL_2_3_WSEL_T23_24_WIDTH       (2U)
#define SARADC_CWSEL_2_3_WSEL_T23_24(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_3_WSEL_T23_24_SHIFT)) & SARADC_CWSEL_2_3_WSEL_T23_24_MASK)

#define SARADC_CWSEL_2_3_WSEL_T23_25_MASK        (0x30U)
#define SARADC_CWSEL_2_3_WSEL_T23_25_SHIFT       (4U)
#define SARADC_CWSEL_2_3_WSEL_T23_25_WIDTH       (2U)
#define SARADC_CWSEL_2_3_WSEL_T23_25(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_3_WSEL_T23_25_SHIFT)) & SARADC_CWSEL_2_3_WSEL_T23_25_MASK)

#define SARADC_CWSEL_2_3_WSEL_T23_26_MASK        (0x300U)
#define SARADC_CWSEL_2_3_WSEL_T23_26_SHIFT       (8U)
#define SARADC_CWSEL_2_3_WSEL_T23_26_WIDTH       (2U)
#define SARADC_CWSEL_2_3_WSEL_T23_26(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_3_WSEL_T23_26_SHIFT)) & SARADC_CWSEL_2_3_WSEL_T23_26_MASK)

#define SARADC_CWSEL_2_3_WSEL_T23_27_MASK        (0x3000U)
#define SARADC_CWSEL_2_3_WSEL_T23_27_SHIFT       (12U)
#define SARADC_CWSEL_2_3_WSEL_T23_27_WIDTH       (2U)
#define SARADC_CWSEL_2_3_WSEL_T23_27(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_3_WSEL_T23_27_SHIFT)) & SARADC_CWSEL_2_3_WSEL_T23_27_MASK)

#define SARADC_CWSEL_2_3_WSEL_T23_28_MASK        (0x30000U)
#define SARADC_CWSEL_2_3_WSEL_T23_28_SHIFT       (16U)
#define SARADC_CWSEL_2_3_WSEL_T23_28_WIDTH       (2U)
#define SARADC_CWSEL_2_3_WSEL_T23_28(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_3_WSEL_T23_28_SHIFT)) & SARADC_CWSEL_2_3_WSEL_T23_28_MASK)

#define SARADC_CWSEL_2_3_WSEL_T23_29_MASK        (0x300000U)
#define SARADC_CWSEL_2_3_WSEL_T23_29_SHIFT       (20U)
#define SARADC_CWSEL_2_3_WSEL_T23_29_WIDTH       (2U)
#define SARADC_CWSEL_2_3_WSEL_T23_29(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_3_WSEL_T23_29_SHIFT)) & SARADC_CWSEL_2_3_WSEL_T23_29_MASK)

#define SARADC_CWSEL_2_3_WSEL_T23_30_MASK        (0x3000000U)
#define SARADC_CWSEL_2_3_WSEL_T23_30_SHIFT       (24U)
#define SARADC_CWSEL_2_3_WSEL_T23_30_WIDTH       (2U)
#define SARADC_CWSEL_2_3_WSEL_T23_30(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_3_WSEL_T23_30_SHIFT)) & SARADC_CWSEL_2_3_WSEL_T23_30_MASK)

#define SARADC_CWSEL_2_3_WSEL_T23_31_MASK        (0x30000000U)
#define SARADC_CWSEL_2_3_WSEL_T23_31_SHIFT       (28U)
#define SARADC_CWSEL_2_3_WSEL_T23_31_WIDTH       (2U)
#define SARADC_CWSEL_2_3_WSEL_T23_31(x)          (((uint32_t)(((uint32_t)(x)) << SARADC_CWSEL_2_3_WSEL_T23_31_SHIFT)) & SARADC_CWSEL_2_3_WSEL_T23_31_MASK)
/*! @} */

/*! @name CWEN0 - Channel Watchdog Enable for Type 0 */
/*! @{ */

#define SARADC_CWEN0_CWEN0_MASK                  (0x1U)
#define SARADC_CWEN0_CWEN0_SHIFT                 (0U)
#define SARADC_CWEN0_CWEN0_WIDTH                 (1U)
#define SARADC_CWEN0_CWEN0(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN0_SHIFT)) & SARADC_CWEN0_CWEN0_MASK)

#define SARADC_CWEN0_CWEN1_MASK                  (0x2U)
#define SARADC_CWEN0_CWEN1_SHIFT                 (1U)
#define SARADC_CWEN0_CWEN1_WIDTH                 (1U)
#define SARADC_CWEN0_CWEN1(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN1_SHIFT)) & SARADC_CWEN0_CWEN1_MASK)

#define SARADC_CWEN0_CWEN2_MASK                  (0x4U)
#define SARADC_CWEN0_CWEN2_SHIFT                 (2U)
#define SARADC_CWEN0_CWEN2_WIDTH                 (1U)
#define SARADC_CWEN0_CWEN2(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN2_SHIFT)) & SARADC_CWEN0_CWEN2_MASK)

#define SARADC_CWEN0_CWEN3_MASK                  (0x8U)
#define SARADC_CWEN0_CWEN3_SHIFT                 (3U)
#define SARADC_CWEN0_CWEN3_WIDTH                 (1U)
#define SARADC_CWEN0_CWEN3(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN3_SHIFT)) & SARADC_CWEN0_CWEN3_MASK)

#define SARADC_CWEN0_CWEN4_MASK                  (0x10U)
#define SARADC_CWEN0_CWEN4_SHIFT                 (4U)
#define SARADC_CWEN0_CWEN4_WIDTH                 (1U)
#define SARADC_CWEN0_CWEN4(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN4_SHIFT)) & SARADC_CWEN0_CWEN4_MASK)

#define SARADC_CWEN0_CWEN5_MASK                  (0x20U)
#define SARADC_CWEN0_CWEN5_SHIFT                 (5U)
#define SARADC_CWEN0_CWEN5_WIDTH                 (1U)
#define SARADC_CWEN0_CWEN5(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN5_SHIFT)) & SARADC_CWEN0_CWEN5_MASK)

#define SARADC_CWEN0_CWEN6_MASK                  (0x40U)
#define SARADC_CWEN0_CWEN6_SHIFT                 (6U)
#define SARADC_CWEN0_CWEN6_WIDTH                 (1U)
#define SARADC_CWEN0_CWEN6(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN6_SHIFT)) & SARADC_CWEN0_CWEN6_MASK)

#define SARADC_CWEN0_CWEN7_MASK                  (0x80U)
#define SARADC_CWEN0_CWEN7_SHIFT                 (7U)
#define SARADC_CWEN0_CWEN7_WIDTH                 (1U)
#define SARADC_CWEN0_CWEN7(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN7_SHIFT)) & SARADC_CWEN0_CWEN7_MASK)

#define SARADC_CWEN0_CWEN8_MASK                  (0x100U)
#define SARADC_CWEN0_CWEN8_SHIFT                 (8U)
#define SARADC_CWEN0_CWEN8_WIDTH                 (1U)
#define SARADC_CWEN0_CWEN8(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN8_SHIFT)) & SARADC_CWEN0_CWEN8_MASK)

#define SARADC_CWEN0_CWEN9_MASK                  (0x200U)
#define SARADC_CWEN0_CWEN9_SHIFT                 (9U)
#define SARADC_CWEN0_CWEN9_WIDTH                 (1U)
#define SARADC_CWEN0_CWEN9(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN9_SHIFT)) & SARADC_CWEN0_CWEN9_MASK)

#define SARADC_CWEN0_CWEN10_MASK                 (0x400U)
#define SARADC_CWEN0_CWEN10_SHIFT                (10U)
#define SARADC_CWEN0_CWEN10_WIDTH                (1U)
#define SARADC_CWEN0_CWEN10(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN10_SHIFT)) & SARADC_CWEN0_CWEN10_MASK)

#define SARADC_CWEN0_CWEN11_MASK                 (0x800U)
#define SARADC_CWEN0_CWEN11_SHIFT                (11U)
#define SARADC_CWEN0_CWEN11_WIDTH                (1U)
#define SARADC_CWEN0_CWEN11(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN11_SHIFT)) & SARADC_CWEN0_CWEN11_MASK)

#define SARADC_CWEN0_CWEN12_MASK                 (0x1000U)
#define SARADC_CWEN0_CWEN12_SHIFT                (12U)
#define SARADC_CWEN0_CWEN12_WIDTH                (1U)
#define SARADC_CWEN0_CWEN12(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN12_SHIFT)) & SARADC_CWEN0_CWEN12_MASK)

#define SARADC_CWEN0_CWEN13_MASK                 (0x2000U)
#define SARADC_CWEN0_CWEN13_SHIFT                (13U)
#define SARADC_CWEN0_CWEN13_WIDTH                (1U)
#define SARADC_CWEN0_CWEN13(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN13_SHIFT)) & SARADC_CWEN0_CWEN13_MASK)

#define SARADC_CWEN0_CWEN14_MASK                 (0x4000U)
#define SARADC_CWEN0_CWEN14_SHIFT                (14U)
#define SARADC_CWEN0_CWEN14_WIDTH                (1U)
#define SARADC_CWEN0_CWEN14(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN14_SHIFT)) & SARADC_CWEN0_CWEN14_MASK)

#define SARADC_CWEN0_CWEN15_MASK                 (0x8000U)
#define SARADC_CWEN0_CWEN15_SHIFT                (15U)
#define SARADC_CWEN0_CWEN15_WIDTH                (1U)
#define SARADC_CWEN0_CWEN15(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN15_SHIFT)) & SARADC_CWEN0_CWEN15_MASK)

#define SARADC_CWEN0_CWEN16_MASK                 (0x10000U)
#define SARADC_CWEN0_CWEN16_SHIFT                (16U)
#define SARADC_CWEN0_CWEN16_WIDTH                (1U)
#define SARADC_CWEN0_CWEN16(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN16_SHIFT)) & SARADC_CWEN0_CWEN16_MASK)

#define SARADC_CWEN0_CWEN17_MASK                 (0x20000U)
#define SARADC_CWEN0_CWEN17_SHIFT                (17U)
#define SARADC_CWEN0_CWEN17_WIDTH                (1U)
#define SARADC_CWEN0_CWEN17(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN17_SHIFT)) & SARADC_CWEN0_CWEN17_MASK)

#define SARADC_CWEN0_CWEN18_MASK                 (0x40000U)
#define SARADC_CWEN0_CWEN18_SHIFT                (18U)
#define SARADC_CWEN0_CWEN18_WIDTH                (1U)
#define SARADC_CWEN0_CWEN18(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN18_SHIFT)) & SARADC_CWEN0_CWEN18_MASK)

#define SARADC_CWEN0_CWEN19_MASK                 (0x80000U)
#define SARADC_CWEN0_CWEN19_SHIFT                (19U)
#define SARADC_CWEN0_CWEN19_WIDTH                (1U)
#define SARADC_CWEN0_CWEN19(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN19_SHIFT)) & SARADC_CWEN0_CWEN19_MASK)

#define SARADC_CWEN0_CWEN20_MASK                 (0x100000U)
#define SARADC_CWEN0_CWEN20_SHIFT                (20U)
#define SARADC_CWEN0_CWEN20_WIDTH                (1U)
#define SARADC_CWEN0_CWEN20(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN20_SHIFT)) & SARADC_CWEN0_CWEN20_MASK)

#define SARADC_CWEN0_CWEN21_MASK                 (0x200000U)
#define SARADC_CWEN0_CWEN21_SHIFT                (21U)
#define SARADC_CWEN0_CWEN21_WIDTH                (1U)
#define SARADC_CWEN0_CWEN21(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN21_SHIFT)) & SARADC_CWEN0_CWEN21_MASK)

#define SARADC_CWEN0_CWEN22_MASK                 (0x400000U)
#define SARADC_CWEN0_CWEN22_SHIFT                (22U)
#define SARADC_CWEN0_CWEN22_WIDTH                (1U)
#define SARADC_CWEN0_CWEN22(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN22_SHIFT)) & SARADC_CWEN0_CWEN22_MASK)

#define SARADC_CWEN0_CWEN23_MASK                 (0x800000U)
#define SARADC_CWEN0_CWEN23_SHIFT                (23U)
#define SARADC_CWEN0_CWEN23_WIDTH                (1U)
#define SARADC_CWEN0_CWEN23(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN23_SHIFT)) & SARADC_CWEN0_CWEN23_MASK)

#define SARADC_CWEN0_CWEN24_MASK                 (0x1000000U)
#define SARADC_CWEN0_CWEN24_SHIFT                (24U)
#define SARADC_CWEN0_CWEN24_WIDTH                (1U)
#define SARADC_CWEN0_CWEN24(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN24_SHIFT)) & SARADC_CWEN0_CWEN24_MASK)

#define SARADC_CWEN0_CWEN25_MASK                 (0x2000000U)
#define SARADC_CWEN0_CWEN25_SHIFT                (25U)
#define SARADC_CWEN0_CWEN25_WIDTH                (1U)
#define SARADC_CWEN0_CWEN25(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN25_SHIFT)) & SARADC_CWEN0_CWEN25_MASK)

#define SARADC_CWEN0_CWEN26_MASK                 (0x4000000U)
#define SARADC_CWEN0_CWEN26_SHIFT                (26U)
#define SARADC_CWEN0_CWEN26_WIDTH                (1U)
#define SARADC_CWEN0_CWEN26(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN26_SHIFT)) & SARADC_CWEN0_CWEN26_MASK)

#define SARADC_CWEN0_CWEN27_MASK                 (0x8000000U)
#define SARADC_CWEN0_CWEN27_SHIFT                (27U)
#define SARADC_CWEN0_CWEN27_WIDTH                (1U)
#define SARADC_CWEN0_CWEN27(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN27_SHIFT)) & SARADC_CWEN0_CWEN27_MASK)

#define SARADC_CWEN0_CWEN28_MASK                 (0x10000000U)
#define SARADC_CWEN0_CWEN28_SHIFT                (28U)
#define SARADC_CWEN0_CWEN28_WIDTH                (1U)
#define SARADC_CWEN0_CWEN28(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN28_SHIFT)) & SARADC_CWEN0_CWEN28_MASK)

#define SARADC_CWEN0_CWEN29_MASK                 (0x20000000U)
#define SARADC_CWEN0_CWEN29_SHIFT                (29U)
#define SARADC_CWEN0_CWEN29_WIDTH                (1U)
#define SARADC_CWEN0_CWEN29(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN29_SHIFT)) & SARADC_CWEN0_CWEN29_MASK)

#define SARADC_CWEN0_CWEN30_MASK                 (0x40000000U)
#define SARADC_CWEN0_CWEN30_SHIFT                (30U)
#define SARADC_CWEN0_CWEN30_WIDTH                (1U)
#define SARADC_CWEN0_CWEN30(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN30_SHIFT)) & SARADC_CWEN0_CWEN30_MASK)

#define SARADC_CWEN0_CWEN31_MASK                 (0x80000000U)
#define SARADC_CWEN0_CWEN31_SHIFT                (31U)
#define SARADC_CWEN0_CWEN31_WIDTH                (1U)
#define SARADC_CWEN0_CWEN31(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN0_CWEN31_SHIFT)) & SARADC_CWEN0_CWEN31_MASK)
/*! @} */

/*! @name CWEN1 - Channel Watchdog Enable for Type 1 */
/*! @{ */

#define SARADC_CWEN1_CWEN0_MASK                  (0x1U)
#define SARADC_CWEN1_CWEN0_SHIFT                 (0U)
#define SARADC_CWEN1_CWEN0_WIDTH                 (1U)
#define SARADC_CWEN1_CWEN0(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN0_SHIFT)) & SARADC_CWEN1_CWEN0_MASK)

#define SARADC_CWEN1_CWEN1_MASK                  (0x2U)
#define SARADC_CWEN1_CWEN1_SHIFT                 (1U)
#define SARADC_CWEN1_CWEN1_WIDTH                 (1U)
#define SARADC_CWEN1_CWEN1(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN1_SHIFT)) & SARADC_CWEN1_CWEN1_MASK)

#define SARADC_CWEN1_CWEN2_MASK                  (0x4U)
#define SARADC_CWEN1_CWEN2_SHIFT                 (2U)
#define SARADC_CWEN1_CWEN2_WIDTH                 (1U)
#define SARADC_CWEN1_CWEN2(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN2_SHIFT)) & SARADC_CWEN1_CWEN2_MASK)

#define SARADC_CWEN1_CWEN3_MASK                  (0x8U)
#define SARADC_CWEN1_CWEN3_SHIFT                 (3U)
#define SARADC_CWEN1_CWEN3_WIDTH                 (1U)
#define SARADC_CWEN1_CWEN3(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN3_SHIFT)) & SARADC_CWEN1_CWEN3_MASK)

#define SARADC_CWEN1_CWEN4_MASK                  (0x10U)
#define SARADC_CWEN1_CWEN4_SHIFT                 (4U)
#define SARADC_CWEN1_CWEN4_WIDTH                 (1U)
#define SARADC_CWEN1_CWEN4(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN4_SHIFT)) & SARADC_CWEN1_CWEN4_MASK)

#define SARADC_CWEN1_CWEN5_MASK                  (0x20U)
#define SARADC_CWEN1_CWEN5_SHIFT                 (5U)
#define SARADC_CWEN1_CWEN5_WIDTH                 (1U)
#define SARADC_CWEN1_CWEN5(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN5_SHIFT)) & SARADC_CWEN1_CWEN5_MASK)

#define SARADC_CWEN1_CWEN6_MASK                  (0x40U)
#define SARADC_CWEN1_CWEN6_SHIFT                 (6U)
#define SARADC_CWEN1_CWEN6_WIDTH                 (1U)
#define SARADC_CWEN1_CWEN6(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN6_SHIFT)) & SARADC_CWEN1_CWEN6_MASK)

#define SARADC_CWEN1_CWEN7_MASK                  (0x80U)
#define SARADC_CWEN1_CWEN7_SHIFT                 (7U)
#define SARADC_CWEN1_CWEN7_WIDTH                 (1U)
#define SARADC_CWEN1_CWEN7(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN7_SHIFT)) & SARADC_CWEN1_CWEN7_MASK)

#define SARADC_CWEN1_CWEN8_MASK                  (0x100U)
#define SARADC_CWEN1_CWEN8_SHIFT                 (8U)
#define SARADC_CWEN1_CWEN8_WIDTH                 (1U)
#define SARADC_CWEN1_CWEN8(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN8_SHIFT)) & SARADC_CWEN1_CWEN8_MASK)

#define SARADC_CWEN1_CWEN9_MASK                  (0x200U)
#define SARADC_CWEN1_CWEN9_SHIFT                 (9U)
#define SARADC_CWEN1_CWEN9_WIDTH                 (1U)
#define SARADC_CWEN1_CWEN9(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN9_SHIFT)) & SARADC_CWEN1_CWEN9_MASK)

#define SARADC_CWEN1_CWEN10_MASK                 (0x400U)
#define SARADC_CWEN1_CWEN10_SHIFT                (10U)
#define SARADC_CWEN1_CWEN10_WIDTH                (1U)
#define SARADC_CWEN1_CWEN10(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN10_SHIFT)) & SARADC_CWEN1_CWEN10_MASK)

#define SARADC_CWEN1_CWEN16_MASK                 (0x10000U)
#define SARADC_CWEN1_CWEN16_SHIFT                (16U)
#define SARADC_CWEN1_CWEN16_WIDTH                (1U)
#define SARADC_CWEN1_CWEN16(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN16_SHIFT)) & SARADC_CWEN1_CWEN16_MASK)

#define SARADC_CWEN1_CWEN17_MASK                 (0x20000U)
#define SARADC_CWEN1_CWEN17_SHIFT                (17U)
#define SARADC_CWEN1_CWEN17_WIDTH                (1U)
#define SARADC_CWEN1_CWEN17(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN17_SHIFT)) & SARADC_CWEN1_CWEN17_MASK)

#define SARADC_CWEN1_CWEN18_MASK                 (0x40000U)
#define SARADC_CWEN1_CWEN18_SHIFT                (18U)
#define SARADC_CWEN1_CWEN18_WIDTH                (1U)
#define SARADC_CWEN1_CWEN18(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN18_SHIFT)) & SARADC_CWEN1_CWEN18_MASK)

#define SARADC_CWEN1_CWEN19_MASK                 (0x80000U)
#define SARADC_CWEN1_CWEN19_SHIFT                (19U)
#define SARADC_CWEN1_CWEN19_WIDTH                (1U)
#define SARADC_CWEN1_CWEN19(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN19_SHIFT)) & SARADC_CWEN1_CWEN19_MASK)

#define SARADC_CWEN1_CWEN20_MASK                 (0x100000U)
#define SARADC_CWEN1_CWEN20_SHIFT                (20U)
#define SARADC_CWEN1_CWEN20_WIDTH                (1U)
#define SARADC_CWEN1_CWEN20(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN20_SHIFT)) & SARADC_CWEN1_CWEN20_MASK)

#define SARADC_CWEN1_CWEN21_MASK                 (0x200000U)
#define SARADC_CWEN1_CWEN21_SHIFT                (21U)
#define SARADC_CWEN1_CWEN21_WIDTH                (1U)
#define SARADC_CWEN1_CWEN21(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN21_SHIFT)) & SARADC_CWEN1_CWEN21_MASK)

#define SARADC_CWEN1_CWEN22_MASK                 (0x400000U)
#define SARADC_CWEN1_CWEN22_SHIFT                (22U)
#define SARADC_CWEN1_CWEN22_WIDTH                (1U)
#define SARADC_CWEN1_CWEN22(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN22_SHIFT)) & SARADC_CWEN1_CWEN22_MASK)

#define SARADC_CWEN1_CWEN23_MASK                 (0x800000U)
#define SARADC_CWEN1_CWEN23_SHIFT                (23U)
#define SARADC_CWEN1_CWEN23_WIDTH                (1U)
#define SARADC_CWEN1_CWEN23(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN23_SHIFT)) & SARADC_CWEN1_CWEN23_MASK)

#define SARADC_CWEN1_CWEN24_MASK                 (0x1000000U)
#define SARADC_CWEN1_CWEN24_SHIFT                (24U)
#define SARADC_CWEN1_CWEN24_WIDTH                (1U)
#define SARADC_CWEN1_CWEN24(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN24_SHIFT)) & SARADC_CWEN1_CWEN24_MASK)

#define SARADC_CWEN1_CWEN25_MASK                 (0x2000000U)
#define SARADC_CWEN1_CWEN25_SHIFT                (25U)
#define SARADC_CWEN1_CWEN25_WIDTH                (1U)
#define SARADC_CWEN1_CWEN25(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN25_SHIFT)) & SARADC_CWEN1_CWEN25_MASK)

#define SARADC_CWEN1_CWEN26_MASK                 (0x4000000U)
#define SARADC_CWEN1_CWEN26_SHIFT                (26U)
#define SARADC_CWEN1_CWEN26_WIDTH                (1U)
#define SARADC_CWEN1_CWEN26(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN1_CWEN26_SHIFT)) & SARADC_CWEN1_CWEN26_MASK)
/*! @} */

/*! @name CWEN2 - Channel Watchdog Enable for Type 2 */
/*! @{ */

#define SARADC_CWEN2_CWEN0_MASK                  (0x1U)
#define SARADC_CWEN2_CWEN0_SHIFT                 (0U)
#define SARADC_CWEN2_CWEN0_WIDTH                 (1U)
#define SARADC_CWEN2_CWEN0(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN0_SHIFT)) & SARADC_CWEN2_CWEN0_MASK)

#define SARADC_CWEN2_CWEN1_MASK                  (0x2U)
#define SARADC_CWEN2_CWEN1_SHIFT                 (1U)
#define SARADC_CWEN2_CWEN1_WIDTH                 (1U)
#define SARADC_CWEN2_CWEN1(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN1_SHIFT)) & SARADC_CWEN2_CWEN1_MASK)

#define SARADC_CWEN2_CWEN2_MASK                  (0x4U)
#define SARADC_CWEN2_CWEN2_SHIFT                 (2U)
#define SARADC_CWEN2_CWEN2_WIDTH                 (1U)
#define SARADC_CWEN2_CWEN2(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN2_SHIFT)) & SARADC_CWEN2_CWEN2_MASK)

#define SARADC_CWEN2_CWEN3_MASK                  (0x8U)
#define SARADC_CWEN2_CWEN3_SHIFT                 (3U)
#define SARADC_CWEN2_CWEN3_WIDTH                 (1U)
#define SARADC_CWEN2_CWEN3(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN3_SHIFT)) & SARADC_CWEN2_CWEN3_MASK)

#define SARADC_CWEN2_CWEN4_MASK                  (0x10U)
#define SARADC_CWEN2_CWEN4_SHIFT                 (4U)
#define SARADC_CWEN2_CWEN4_WIDTH                 (1U)
#define SARADC_CWEN2_CWEN4(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN4_SHIFT)) & SARADC_CWEN2_CWEN4_MASK)

#define SARADC_CWEN2_CWEN5_MASK                  (0x20U)
#define SARADC_CWEN2_CWEN5_SHIFT                 (5U)
#define SARADC_CWEN2_CWEN5_WIDTH                 (1U)
#define SARADC_CWEN2_CWEN5(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN5_SHIFT)) & SARADC_CWEN2_CWEN5_MASK)

#define SARADC_CWEN2_CWEN6_MASK                  (0x40U)
#define SARADC_CWEN2_CWEN6_SHIFT                 (6U)
#define SARADC_CWEN2_CWEN6_WIDTH                 (1U)
#define SARADC_CWEN2_CWEN6(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN6_SHIFT)) & SARADC_CWEN2_CWEN6_MASK)

#define SARADC_CWEN2_CWEN7_MASK                  (0x80U)
#define SARADC_CWEN2_CWEN7_SHIFT                 (7U)
#define SARADC_CWEN2_CWEN7_WIDTH                 (1U)
#define SARADC_CWEN2_CWEN7(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN7_SHIFT)) & SARADC_CWEN2_CWEN7_MASK)

#define SARADC_CWEN2_CWEN8_MASK                  (0x100U)
#define SARADC_CWEN2_CWEN8_SHIFT                 (8U)
#define SARADC_CWEN2_CWEN8_WIDTH                 (1U)
#define SARADC_CWEN2_CWEN8(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN8_SHIFT)) & SARADC_CWEN2_CWEN8_MASK)

#define SARADC_CWEN2_CWEN9_MASK                  (0x200U)
#define SARADC_CWEN2_CWEN9_SHIFT                 (9U)
#define SARADC_CWEN2_CWEN9_WIDTH                 (1U)
#define SARADC_CWEN2_CWEN9(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN9_SHIFT)) & SARADC_CWEN2_CWEN9_MASK)

#define SARADC_CWEN2_CWEN10_MASK                 (0x400U)
#define SARADC_CWEN2_CWEN10_SHIFT                (10U)
#define SARADC_CWEN2_CWEN10_WIDTH                (1U)
#define SARADC_CWEN2_CWEN10(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN10_SHIFT)) & SARADC_CWEN2_CWEN10_MASK)

#define SARADC_CWEN2_CWEN11_MASK                 (0x800U)
#define SARADC_CWEN2_CWEN11_SHIFT                (11U)
#define SARADC_CWEN2_CWEN11_WIDTH                (1U)
#define SARADC_CWEN2_CWEN11(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN11_SHIFT)) & SARADC_CWEN2_CWEN11_MASK)

#define SARADC_CWEN2_CWEN12_MASK                 (0x1000U)
#define SARADC_CWEN2_CWEN12_SHIFT                (12U)
#define SARADC_CWEN2_CWEN12_WIDTH                (1U)
#define SARADC_CWEN2_CWEN12(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN12_SHIFT)) & SARADC_CWEN2_CWEN12_MASK)

#define SARADC_CWEN2_CWEN13_MASK                 (0x2000U)
#define SARADC_CWEN2_CWEN13_SHIFT                (13U)
#define SARADC_CWEN2_CWEN13_WIDTH                (1U)
#define SARADC_CWEN2_CWEN13(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN13_SHIFT)) & SARADC_CWEN2_CWEN13_MASK)

#define SARADC_CWEN2_CWEN14_MASK                 (0x4000U)
#define SARADC_CWEN2_CWEN14_SHIFT                (14U)
#define SARADC_CWEN2_CWEN14_WIDTH                (1U)
#define SARADC_CWEN2_CWEN14(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN14_SHIFT)) & SARADC_CWEN2_CWEN14_MASK)

#define SARADC_CWEN2_CWEN15_MASK                 (0x8000U)
#define SARADC_CWEN2_CWEN15_SHIFT                (15U)
#define SARADC_CWEN2_CWEN15_WIDTH                (1U)
#define SARADC_CWEN2_CWEN15(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN15_SHIFT)) & SARADC_CWEN2_CWEN15_MASK)

#define SARADC_CWEN2_CWEN16_MASK                 (0x10000U)
#define SARADC_CWEN2_CWEN16_SHIFT                (16U)
#define SARADC_CWEN2_CWEN16_WIDTH                (1U)
#define SARADC_CWEN2_CWEN16(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN16_SHIFT)) & SARADC_CWEN2_CWEN16_MASK)

#define SARADC_CWEN2_CWEN17_MASK                 (0x20000U)
#define SARADC_CWEN2_CWEN17_SHIFT                (17U)
#define SARADC_CWEN2_CWEN17_WIDTH                (1U)
#define SARADC_CWEN2_CWEN17(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN17_SHIFT)) & SARADC_CWEN2_CWEN17_MASK)

#define SARADC_CWEN2_CWEN18_MASK                 (0x40000U)
#define SARADC_CWEN2_CWEN18_SHIFT                (18U)
#define SARADC_CWEN2_CWEN18_WIDTH                (1U)
#define SARADC_CWEN2_CWEN18(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN18_SHIFT)) & SARADC_CWEN2_CWEN18_MASK)

#define SARADC_CWEN2_CWEN19_MASK                 (0x80000U)
#define SARADC_CWEN2_CWEN19_SHIFT                (19U)
#define SARADC_CWEN2_CWEN19_WIDTH                (1U)
#define SARADC_CWEN2_CWEN19(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN19_SHIFT)) & SARADC_CWEN2_CWEN19_MASK)

#define SARADC_CWEN2_CWEN20_MASK                 (0x100000U)
#define SARADC_CWEN2_CWEN20_SHIFT                (20U)
#define SARADC_CWEN2_CWEN20_WIDTH                (1U)
#define SARADC_CWEN2_CWEN20(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN20_SHIFT)) & SARADC_CWEN2_CWEN20_MASK)

#define SARADC_CWEN2_CWEN21_MASK                 (0x200000U)
#define SARADC_CWEN2_CWEN21_SHIFT                (21U)
#define SARADC_CWEN2_CWEN21_WIDTH                (1U)
#define SARADC_CWEN2_CWEN21(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN21_SHIFT)) & SARADC_CWEN2_CWEN21_MASK)

#define SARADC_CWEN2_CWEN22_MASK                 (0x400000U)
#define SARADC_CWEN2_CWEN22_SHIFT                (22U)
#define SARADC_CWEN2_CWEN22_WIDTH                (1U)
#define SARADC_CWEN2_CWEN22(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN22_SHIFT)) & SARADC_CWEN2_CWEN22_MASK)

#define SARADC_CWEN2_CWEN23_MASK                 (0x800000U)
#define SARADC_CWEN2_CWEN23_SHIFT                (23U)
#define SARADC_CWEN2_CWEN23_WIDTH                (1U)
#define SARADC_CWEN2_CWEN23(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN23_SHIFT)) & SARADC_CWEN2_CWEN23_MASK)

#define SARADC_CWEN2_CWEN24_MASK                 (0x1000000U)
#define SARADC_CWEN2_CWEN24_SHIFT                (24U)
#define SARADC_CWEN2_CWEN24_WIDTH                (1U)
#define SARADC_CWEN2_CWEN24(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN24_SHIFT)) & SARADC_CWEN2_CWEN24_MASK)

#define SARADC_CWEN2_CWEN25_MASK                 (0x2000000U)
#define SARADC_CWEN2_CWEN25_SHIFT                (25U)
#define SARADC_CWEN2_CWEN25_WIDTH                (1U)
#define SARADC_CWEN2_CWEN25(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN25_SHIFT)) & SARADC_CWEN2_CWEN25_MASK)

#define SARADC_CWEN2_CWEN26_MASK                 (0x4000000U)
#define SARADC_CWEN2_CWEN26_SHIFT                (26U)
#define SARADC_CWEN2_CWEN26_WIDTH                (1U)
#define SARADC_CWEN2_CWEN26(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN26_SHIFT)) & SARADC_CWEN2_CWEN26_MASK)

#define SARADC_CWEN2_CWEN27_MASK                 (0x8000000U)
#define SARADC_CWEN2_CWEN27_SHIFT                (27U)
#define SARADC_CWEN2_CWEN27_WIDTH                (1U)
#define SARADC_CWEN2_CWEN27(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN27_SHIFT)) & SARADC_CWEN2_CWEN27_MASK)

#define SARADC_CWEN2_CWEN28_MASK                 (0x10000000U)
#define SARADC_CWEN2_CWEN28_SHIFT                (28U)
#define SARADC_CWEN2_CWEN28_WIDTH                (1U)
#define SARADC_CWEN2_CWEN28(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN28_SHIFT)) & SARADC_CWEN2_CWEN28_MASK)

#define SARADC_CWEN2_CWEN29_MASK                 (0x20000000U)
#define SARADC_CWEN2_CWEN29_SHIFT                (29U)
#define SARADC_CWEN2_CWEN29_WIDTH                (1U)
#define SARADC_CWEN2_CWEN29(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN29_SHIFT)) & SARADC_CWEN2_CWEN29_MASK)

#define SARADC_CWEN2_CWEN30_MASK                 (0x40000000U)
#define SARADC_CWEN2_CWEN30_SHIFT                (30U)
#define SARADC_CWEN2_CWEN30_WIDTH                (1U)
#define SARADC_CWEN2_CWEN30(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN30_SHIFT)) & SARADC_CWEN2_CWEN30_MASK)

#define SARADC_CWEN2_CWEN31_MASK                 (0x80000000U)
#define SARADC_CWEN2_CWEN31_SHIFT                (31U)
#define SARADC_CWEN2_CWEN31_WIDTH                (1U)
#define SARADC_CWEN2_CWEN31(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CWEN2_CWEN31_SHIFT)) & SARADC_CWEN2_CWEN31_MASK)
/*! @} */

/*! @name AWOR0 - Analog Watchdog Out of Range for Type 0 */
/*! @{ */

#define SARADC_AWOR0_AWOR_CH0_MASK               (0x1U)
#define SARADC_AWOR0_AWOR_CH0_SHIFT              (0U)
#define SARADC_AWOR0_AWOR_CH0_WIDTH              (1U)
#define SARADC_AWOR0_AWOR_CH0(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH0_SHIFT)) & SARADC_AWOR0_AWOR_CH0_MASK)

#define SARADC_AWOR0_AWOR_CH1_MASK               (0x2U)
#define SARADC_AWOR0_AWOR_CH1_SHIFT              (1U)
#define SARADC_AWOR0_AWOR_CH1_WIDTH              (1U)
#define SARADC_AWOR0_AWOR_CH1(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH1_SHIFT)) & SARADC_AWOR0_AWOR_CH1_MASK)

#define SARADC_AWOR0_AWOR_CH2_MASK               (0x4U)
#define SARADC_AWOR0_AWOR_CH2_SHIFT              (2U)
#define SARADC_AWOR0_AWOR_CH2_WIDTH              (1U)
#define SARADC_AWOR0_AWOR_CH2(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH2_SHIFT)) & SARADC_AWOR0_AWOR_CH2_MASK)

#define SARADC_AWOR0_AWOR_CH3_MASK               (0x8U)
#define SARADC_AWOR0_AWOR_CH3_SHIFT              (3U)
#define SARADC_AWOR0_AWOR_CH3_WIDTH              (1U)
#define SARADC_AWOR0_AWOR_CH3(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH3_SHIFT)) & SARADC_AWOR0_AWOR_CH3_MASK)

#define SARADC_AWOR0_AWOR_CH4_MASK               (0x10U)
#define SARADC_AWOR0_AWOR_CH4_SHIFT              (4U)
#define SARADC_AWOR0_AWOR_CH4_WIDTH              (1U)
#define SARADC_AWOR0_AWOR_CH4(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH4_SHIFT)) & SARADC_AWOR0_AWOR_CH4_MASK)

#define SARADC_AWOR0_AWOR_CH5_MASK               (0x20U)
#define SARADC_AWOR0_AWOR_CH5_SHIFT              (5U)
#define SARADC_AWOR0_AWOR_CH5_WIDTH              (1U)
#define SARADC_AWOR0_AWOR_CH5(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH5_SHIFT)) & SARADC_AWOR0_AWOR_CH5_MASK)

#define SARADC_AWOR0_AWOR_CH6_MASK               (0x40U)
#define SARADC_AWOR0_AWOR_CH6_SHIFT              (6U)
#define SARADC_AWOR0_AWOR_CH6_WIDTH              (1U)
#define SARADC_AWOR0_AWOR_CH6(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH6_SHIFT)) & SARADC_AWOR0_AWOR_CH6_MASK)

#define SARADC_AWOR0_AWOR_CH7_MASK               (0x80U)
#define SARADC_AWOR0_AWOR_CH7_SHIFT              (7U)
#define SARADC_AWOR0_AWOR_CH7_WIDTH              (1U)
#define SARADC_AWOR0_AWOR_CH7(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH7_SHIFT)) & SARADC_AWOR0_AWOR_CH7_MASK)

#define SARADC_AWOR0_AWOR_CH8_MASK               (0x100U)
#define SARADC_AWOR0_AWOR_CH8_SHIFT              (8U)
#define SARADC_AWOR0_AWOR_CH8_WIDTH              (1U)
#define SARADC_AWOR0_AWOR_CH8(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH8_SHIFT)) & SARADC_AWOR0_AWOR_CH8_MASK)

#define SARADC_AWOR0_AWOR_CH9_MASK               (0x200U)
#define SARADC_AWOR0_AWOR_CH9_SHIFT              (9U)
#define SARADC_AWOR0_AWOR_CH9_WIDTH              (1U)
#define SARADC_AWOR0_AWOR_CH9(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH9_SHIFT)) & SARADC_AWOR0_AWOR_CH9_MASK)

#define SARADC_AWOR0_AWOR_CH10_MASK              (0x400U)
#define SARADC_AWOR0_AWOR_CH10_SHIFT             (10U)
#define SARADC_AWOR0_AWOR_CH10_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH10(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH10_SHIFT)) & SARADC_AWOR0_AWOR_CH10_MASK)

#define SARADC_AWOR0_AWOR_CH11_MASK              (0x800U)
#define SARADC_AWOR0_AWOR_CH11_SHIFT             (11U)
#define SARADC_AWOR0_AWOR_CH11_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH11(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH11_SHIFT)) & SARADC_AWOR0_AWOR_CH11_MASK)

#define SARADC_AWOR0_AWOR_CH12_MASK              (0x1000U)
#define SARADC_AWOR0_AWOR_CH12_SHIFT             (12U)
#define SARADC_AWOR0_AWOR_CH12_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH12(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH12_SHIFT)) & SARADC_AWOR0_AWOR_CH12_MASK)

#define SARADC_AWOR0_AWOR_CH13_MASK              (0x2000U)
#define SARADC_AWOR0_AWOR_CH13_SHIFT             (13U)
#define SARADC_AWOR0_AWOR_CH13_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH13(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH13_SHIFT)) & SARADC_AWOR0_AWOR_CH13_MASK)

#define SARADC_AWOR0_AWOR_CH14_MASK              (0x4000U)
#define SARADC_AWOR0_AWOR_CH14_SHIFT             (14U)
#define SARADC_AWOR0_AWOR_CH14_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH14(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH14_SHIFT)) & SARADC_AWOR0_AWOR_CH14_MASK)

#define SARADC_AWOR0_AWOR_CH15_MASK              (0x8000U)
#define SARADC_AWOR0_AWOR_CH15_SHIFT             (15U)
#define SARADC_AWOR0_AWOR_CH15_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH15(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH15_SHIFT)) & SARADC_AWOR0_AWOR_CH15_MASK)

#define SARADC_AWOR0_AWOR_CH16_MASK              (0x10000U)
#define SARADC_AWOR0_AWOR_CH16_SHIFT             (16U)
#define SARADC_AWOR0_AWOR_CH16_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH16(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH16_SHIFT)) & SARADC_AWOR0_AWOR_CH16_MASK)

#define SARADC_AWOR0_AWOR_CH17_MASK              (0x20000U)
#define SARADC_AWOR0_AWOR_CH17_SHIFT             (17U)
#define SARADC_AWOR0_AWOR_CH17_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH17(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH17_SHIFT)) & SARADC_AWOR0_AWOR_CH17_MASK)

#define SARADC_AWOR0_AWOR_CH18_MASK              (0x40000U)
#define SARADC_AWOR0_AWOR_CH18_SHIFT             (18U)
#define SARADC_AWOR0_AWOR_CH18_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH18(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH18_SHIFT)) & SARADC_AWOR0_AWOR_CH18_MASK)

#define SARADC_AWOR0_AWOR_CH19_MASK              (0x80000U)
#define SARADC_AWOR0_AWOR_CH19_SHIFT             (19U)
#define SARADC_AWOR0_AWOR_CH19_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH19(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH19_SHIFT)) & SARADC_AWOR0_AWOR_CH19_MASK)

#define SARADC_AWOR0_AWOR_CH20_MASK              (0x100000U)
#define SARADC_AWOR0_AWOR_CH20_SHIFT             (20U)
#define SARADC_AWOR0_AWOR_CH20_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH20(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH20_SHIFT)) & SARADC_AWOR0_AWOR_CH20_MASK)

#define SARADC_AWOR0_AWOR_CH21_MASK              (0x200000U)
#define SARADC_AWOR0_AWOR_CH21_SHIFT             (21U)
#define SARADC_AWOR0_AWOR_CH21_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH21(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH21_SHIFT)) & SARADC_AWOR0_AWOR_CH21_MASK)

#define SARADC_AWOR0_AWOR_CH22_MASK              (0x400000U)
#define SARADC_AWOR0_AWOR_CH22_SHIFT             (22U)
#define SARADC_AWOR0_AWOR_CH22_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH22(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH22_SHIFT)) & SARADC_AWOR0_AWOR_CH22_MASK)

#define SARADC_AWOR0_AWOR_CH23_MASK              (0x800000U)
#define SARADC_AWOR0_AWOR_CH23_SHIFT             (23U)
#define SARADC_AWOR0_AWOR_CH23_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH23(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH23_SHIFT)) & SARADC_AWOR0_AWOR_CH23_MASK)

#define SARADC_AWOR0_AWOR_CH24_MASK              (0x1000000U)
#define SARADC_AWOR0_AWOR_CH24_SHIFT             (24U)
#define SARADC_AWOR0_AWOR_CH24_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH24(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH24_SHIFT)) & SARADC_AWOR0_AWOR_CH24_MASK)

#define SARADC_AWOR0_AWOR_CH25_MASK              (0x2000000U)
#define SARADC_AWOR0_AWOR_CH25_SHIFT             (25U)
#define SARADC_AWOR0_AWOR_CH25_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH25(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH25_SHIFT)) & SARADC_AWOR0_AWOR_CH25_MASK)

#define SARADC_AWOR0_AWOR_CH26_MASK              (0x4000000U)
#define SARADC_AWOR0_AWOR_CH26_SHIFT             (26U)
#define SARADC_AWOR0_AWOR_CH26_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH26(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH26_SHIFT)) & SARADC_AWOR0_AWOR_CH26_MASK)

#define SARADC_AWOR0_AWOR_CH27_MASK              (0x8000000U)
#define SARADC_AWOR0_AWOR_CH27_SHIFT             (27U)
#define SARADC_AWOR0_AWOR_CH27_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH27(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH27_SHIFT)) & SARADC_AWOR0_AWOR_CH27_MASK)

#define SARADC_AWOR0_AWOR_CH28_MASK              (0x10000000U)
#define SARADC_AWOR0_AWOR_CH28_SHIFT             (28U)
#define SARADC_AWOR0_AWOR_CH28_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH28(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH28_SHIFT)) & SARADC_AWOR0_AWOR_CH28_MASK)

#define SARADC_AWOR0_AWOR_CH29_MASK              (0x20000000U)
#define SARADC_AWOR0_AWOR_CH29_SHIFT             (29U)
#define SARADC_AWOR0_AWOR_CH29_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH29(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH29_SHIFT)) & SARADC_AWOR0_AWOR_CH29_MASK)

#define SARADC_AWOR0_AWOR_CH30_MASK              (0x40000000U)
#define SARADC_AWOR0_AWOR_CH30_SHIFT             (30U)
#define SARADC_AWOR0_AWOR_CH30_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH30(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH30_SHIFT)) & SARADC_AWOR0_AWOR_CH30_MASK)

#define SARADC_AWOR0_AWOR_CH31_MASK              (0x80000000U)
#define SARADC_AWOR0_AWOR_CH31_SHIFT             (31U)
#define SARADC_AWOR0_AWOR_CH31_WIDTH             (1U)
#define SARADC_AWOR0_AWOR_CH31(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR0_AWOR_CH31_SHIFT)) & SARADC_AWOR0_AWOR_CH31_MASK)
/*! @} */

/*! @name AWOR1 - Analog Watchdog Out of Range for Type 1 */
/*! @{ */

#define SARADC_AWOR1_AWOR_CH0_MASK               (0x1U)
#define SARADC_AWOR1_AWOR_CH0_SHIFT              (0U)
#define SARADC_AWOR1_AWOR_CH0_WIDTH              (1U)
#define SARADC_AWOR1_AWOR_CH0(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH0_SHIFT)) & SARADC_AWOR1_AWOR_CH0_MASK)

#define SARADC_AWOR1_AWOR_CH1_MASK               (0x2U)
#define SARADC_AWOR1_AWOR_CH1_SHIFT              (1U)
#define SARADC_AWOR1_AWOR_CH1_WIDTH              (1U)
#define SARADC_AWOR1_AWOR_CH1(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH1_SHIFT)) & SARADC_AWOR1_AWOR_CH1_MASK)

#define SARADC_AWOR1_AWOR_CH2_MASK               (0x4U)
#define SARADC_AWOR1_AWOR_CH2_SHIFT              (2U)
#define SARADC_AWOR1_AWOR_CH2_WIDTH              (1U)
#define SARADC_AWOR1_AWOR_CH2(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH2_SHIFT)) & SARADC_AWOR1_AWOR_CH2_MASK)

#define SARADC_AWOR1_AWOR_CH3_MASK               (0x8U)
#define SARADC_AWOR1_AWOR_CH3_SHIFT              (3U)
#define SARADC_AWOR1_AWOR_CH3_WIDTH              (1U)
#define SARADC_AWOR1_AWOR_CH3(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH3_SHIFT)) & SARADC_AWOR1_AWOR_CH3_MASK)

#define SARADC_AWOR1_AWOR_CH4_MASK               (0x10U)
#define SARADC_AWOR1_AWOR_CH4_SHIFT              (4U)
#define SARADC_AWOR1_AWOR_CH4_WIDTH              (1U)
#define SARADC_AWOR1_AWOR_CH4(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH4_SHIFT)) & SARADC_AWOR1_AWOR_CH4_MASK)

#define SARADC_AWOR1_AWOR_CH5_MASK               (0x20U)
#define SARADC_AWOR1_AWOR_CH5_SHIFT              (5U)
#define SARADC_AWOR1_AWOR_CH5_WIDTH              (1U)
#define SARADC_AWOR1_AWOR_CH5(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH5_SHIFT)) & SARADC_AWOR1_AWOR_CH5_MASK)

#define SARADC_AWOR1_AWOR_CH6_MASK               (0x40U)
#define SARADC_AWOR1_AWOR_CH6_SHIFT              (6U)
#define SARADC_AWOR1_AWOR_CH6_WIDTH              (1U)
#define SARADC_AWOR1_AWOR_CH6(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH6_SHIFT)) & SARADC_AWOR1_AWOR_CH6_MASK)

#define SARADC_AWOR1_AWOR_CH7_MASK               (0x80U)
#define SARADC_AWOR1_AWOR_CH7_SHIFT              (7U)
#define SARADC_AWOR1_AWOR_CH7_WIDTH              (1U)
#define SARADC_AWOR1_AWOR_CH7(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH7_SHIFT)) & SARADC_AWOR1_AWOR_CH7_MASK)

#define SARADC_AWOR1_AWOR_CH8_MASK               (0x100U)
#define SARADC_AWOR1_AWOR_CH8_SHIFT              (8U)
#define SARADC_AWOR1_AWOR_CH8_WIDTH              (1U)
#define SARADC_AWOR1_AWOR_CH8(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH8_SHIFT)) & SARADC_AWOR1_AWOR_CH8_MASK)

#define SARADC_AWOR1_AWOR_CH9_MASK               (0x200U)
#define SARADC_AWOR1_AWOR_CH9_SHIFT              (9U)
#define SARADC_AWOR1_AWOR_CH9_WIDTH              (1U)
#define SARADC_AWOR1_AWOR_CH9(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH9_SHIFT)) & SARADC_AWOR1_AWOR_CH9_MASK)

#define SARADC_AWOR1_AWOR_CH10_MASK              (0x400U)
#define SARADC_AWOR1_AWOR_CH10_SHIFT             (10U)
#define SARADC_AWOR1_AWOR_CH10_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH10(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH10_SHIFT)) & SARADC_AWOR1_AWOR_CH10_MASK)

#define SARADC_AWOR1_AWOR_CH16_MASK              (0x10000U)
#define SARADC_AWOR1_AWOR_CH16_SHIFT             (16U)
#define SARADC_AWOR1_AWOR_CH16_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH16(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH16_SHIFT)) & SARADC_AWOR1_AWOR_CH16_MASK)

#define SARADC_AWOR1_AWOR_CH17_MASK              (0x20000U)
#define SARADC_AWOR1_AWOR_CH17_SHIFT             (17U)
#define SARADC_AWOR1_AWOR_CH17_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH17(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH17_SHIFT)) & SARADC_AWOR1_AWOR_CH17_MASK)

#define SARADC_AWOR1_AWOR_CH18_MASK              (0x40000U)
#define SARADC_AWOR1_AWOR_CH18_SHIFT             (18U)
#define SARADC_AWOR1_AWOR_CH18_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH18(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH18_SHIFT)) & SARADC_AWOR1_AWOR_CH18_MASK)

#define SARADC_AWOR1_AWOR_CH19_MASK              (0x80000U)
#define SARADC_AWOR1_AWOR_CH19_SHIFT             (19U)
#define SARADC_AWOR1_AWOR_CH19_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH19(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH19_SHIFT)) & SARADC_AWOR1_AWOR_CH19_MASK)

#define SARADC_AWOR1_AWOR_CH20_MASK              (0x100000U)
#define SARADC_AWOR1_AWOR_CH20_SHIFT             (20U)
#define SARADC_AWOR1_AWOR_CH20_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH20(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH20_SHIFT)) & SARADC_AWOR1_AWOR_CH20_MASK)

#define SARADC_AWOR1_AWOR_CH21_MASK              (0x200000U)
#define SARADC_AWOR1_AWOR_CH21_SHIFT             (21U)
#define SARADC_AWOR1_AWOR_CH21_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH21(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH21_SHIFT)) & SARADC_AWOR1_AWOR_CH21_MASK)

#define SARADC_AWOR1_AWOR_CH22_MASK              (0x400000U)
#define SARADC_AWOR1_AWOR_CH22_SHIFT             (22U)
#define SARADC_AWOR1_AWOR_CH22_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH22(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH22_SHIFT)) & SARADC_AWOR1_AWOR_CH22_MASK)

#define SARADC_AWOR1_AWOR_CH23_MASK              (0x800000U)
#define SARADC_AWOR1_AWOR_CH23_SHIFT             (23U)
#define SARADC_AWOR1_AWOR_CH23_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH23(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH23_SHIFT)) & SARADC_AWOR1_AWOR_CH23_MASK)

#define SARADC_AWOR1_AWOR_CH24_MASK              (0x1000000U)
#define SARADC_AWOR1_AWOR_CH24_SHIFT             (24U)
#define SARADC_AWOR1_AWOR_CH24_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH24(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH24_SHIFT)) & SARADC_AWOR1_AWOR_CH24_MASK)

#define SARADC_AWOR1_AWOR_CH25_MASK              (0x2000000U)
#define SARADC_AWOR1_AWOR_CH25_SHIFT             (25U)
#define SARADC_AWOR1_AWOR_CH25_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH25(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH25_SHIFT)) & SARADC_AWOR1_AWOR_CH25_MASK)

#define SARADC_AWOR1_AWOR_CH26_MASK              (0x4000000U)
#define SARADC_AWOR1_AWOR_CH26_SHIFT             (26U)
#define SARADC_AWOR1_AWOR_CH26_WIDTH             (1U)
#define SARADC_AWOR1_AWOR_CH26(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR1_AWOR_CH26_SHIFT)) & SARADC_AWOR1_AWOR_CH26_MASK)
/*! @} */

/*! @name AWOR2 - Analog Watchdog Out of Range for Type 2 */
/*! @{ */

#define SARADC_AWOR2_AWOR_CH0_MASK               (0x1U)
#define SARADC_AWOR2_AWOR_CH0_SHIFT              (0U)
#define SARADC_AWOR2_AWOR_CH0_WIDTH              (1U)
#define SARADC_AWOR2_AWOR_CH0(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH0_SHIFT)) & SARADC_AWOR2_AWOR_CH0_MASK)

#define SARADC_AWOR2_AWOR_CH1_MASK               (0x2U)
#define SARADC_AWOR2_AWOR_CH1_SHIFT              (1U)
#define SARADC_AWOR2_AWOR_CH1_WIDTH              (1U)
#define SARADC_AWOR2_AWOR_CH1(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH1_SHIFT)) & SARADC_AWOR2_AWOR_CH1_MASK)

#define SARADC_AWOR2_AWOR_CH2_MASK               (0x4U)
#define SARADC_AWOR2_AWOR_CH2_SHIFT              (2U)
#define SARADC_AWOR2_AWOR_CH2_WIDTH              (1U)
#define SARADC_AWOR2_AWOR_CH2(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH2_SHIFT)) & SARADC_AWOR2_AWOR_CH2_MASK)

#define SARADC_AWOR2_AWOR_CH3_MASK               (0x8U)
#define SARADC_AWOR2_AWOR_CH3_SHIFT              (3U)
#define SARADC_AWOR2_AWOR_CH3_WIDTH              (1U)
#define SARADC_AWOR2_AWOR_CH3(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH3_SHIFT)) & SARADC_AWOR2_AWOR_CH3_MASK)

#define SARADC_AWOR2_AWOR_CH4_MASK               (0x10U)
#define SARADC_AWOR2_AWOR_CH4_SHIFT              (4U)
#define SARADC_AWOR2_AWOR_CH4_WIDTH              (1U)
#define SARADC_AWOR2_AWOR_CH4(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH4_SHIFT)) & SARADC_AWOR2_AWOR_CH4_MASK)

#define SARADC_AWOR2_AWOR_CH5_MASK               (0x20U)
#define SARADC_AWOR2_AWOR_CH5_SHIFT              (5U)
#define SARADC_AWOR2_AWOR_CH5_WIDTH              (1U)
#define SARADC_AWOR2_AWOR_CH5(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH5_SHIFT)) & SARADC_AWOR2_AWOR_CH5_MASK)

#define SARADC_AWOR2_AWOR_CH6_MASK               (0x40U)
#define SARADC_AWOR2_AWOR_CH6_SHIFT              (6U)
#define SARADC_AWOR2_AWOR_CH6_WIDTH              (1U)
#define SARADC_AWOR2_AWOR_CH6(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH6_SHIFT)) & SARADC_AWOR2_AWOR_CH6_MASK)

#define SARADC_AWOR2_AWOR_CH7_MASK               (0x80U)
#define SARADC_AWOR2_AWOR_CH7_SHIFT              (7U)
#define SARADC_AWOR2_AWOR_CH7_WIDTH              (1U)
#define SARADC_AWOR2_AWOR_CH7(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH7_SHIFT)) & SARADC_AWOR2_AWOR_CH7_MASK)

#define SARADC_AWOR2_AWOR_CH8_MASK               (0x100U)
#define SARADC_AWOR2_AWOR_CH8_SHIFT              (8U)
#define SARADC_AWOR2_AWOR_CH8_WIDTH              (1U)
#define SARADC_AWOR2_AWOR_CH8(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH8_SHIFT)) & SARADC_AWOR2_AWOR_CH8_MASK)

#define SARADC_AWOR2_AWOR_CH9_MASK               (0x200U)
#define SARADC_AWOR2_AWOR_CH9_SHIFT              (9U)
#define SARADC_AWOR2_AWOR_CH9_WIDTH              (1U)
#define SARADC_AWOR2_AWOR_CH9(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH9_SHIFT)) & SARADC_AWOR2_AWOR_CH9_MASK)

#define SARADC_AWOR2_AWOR_CH10_MASK              (0x400U)
#define SARADC_AWOR2_AWOR_CH10_SHIFT             (10U)
#define SARADC_AWOR2_AWOR_CH10_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH10(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH10_SHIFT)) & SARADC_AWOR2_AWOR_CH10_MASK)

#define SARADC_AWOR2_AWOR_CH11_MASK              (0x800U)
#define SARADC_AWOR2_AWOR_CH11_SHIFT             (11U)
#define SARADC_AWOR2_AWOR_CH11_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH11(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH11_SHIFT)) & SARADC_AWOR2_AWOR_CH11_MASK)

#define SARADC_AWOR2_AWOR_CH12_MASK              (0x1000U)
#define SARADC_AWOR2_AWOR_CH12_SHIFT             (12U)
#define SARADC_AWOR2_AWOR_CH12_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH12(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH12_SHIFT)) & SARADC_AWOR2_AWOR_CH12_MASK)

#define SARADC_AWOR2_AWOR_CH13_MASK              (0x2000U)
#define SARADC_AWOR2_AWOR_CH13_SHIFT             (13U)
#define SARADC_AWOR2_AWOR_CH13_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH13(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH13_SHIFT)) & SARADC_AWOR2_AWOR_CH13_MASK)

#define SARADC_AWOR2_AWOR_CH14_MASK              (0x4000U)
#define SARADC_AWOR2_AWOR_CH14_SHIFT             (14U)
#define SARADC_AWOR2_AWOR_CH14_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH14(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH14_SHIFT)) & SARADC_AWOR2_AWOR_CH14_MASK)

#define SARADC_AWOR2_AWOR_CH15_MASK              (0x8000U)
#define SARADC_AWOR2_AWOR_CH15_SHIFT             (15U)
#define SARADC_AWOR2_AWOR_CH15_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH15(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH15_SHIFT)) & SARADC_AWOR2_AWOR_CH15_MASK)

#define SARADC_AWOR2_AWOR_CH16_MASK              (0x10000U)
#define SARADC_AWOR2_AWOR_CH16_SHIFT             (16U)
#define SARADC_AWOR2_AWOR_CH16_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH16(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH16_SHIFT)) & SARADC_AWOR2_AWOR_CH16_MASK)

#define SARADC_AWOR2_AWOR_CH17_MASK              (0x20000U)
#define SARADC_AWOR2_AWOR_CH17_SHIFT             (17U)
#define SARADC_AWOR2_AWOR_CH17_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH17(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH17_SHIFT)) & SARADC_AWOR2_AWOR_CH17_MASK)

#define SARADC_AWOR2_AWOR_CH18_MASK              (0x40000U)
#define SARADC_AWOR2_AWOR_CH18_SHIFT             (18U)
#define SARADC_AWOR2_AWOR_CH18_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH18(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH18_SHIFT)) & SARADC_AWOR2_AWOR_CH18_MASK)

#define SARADC_AWOR2_AWOR_CH19_MASK              (0x80000U)
#define SARADC_AWOR2_AWOR_CH19_SHIFT             (19U)
#define SARADC_AWOR2_AWOR_CH19_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH19(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH19_SHIFT)) & SARADC_AWOR2_AWOR_CH19_MASK)

#define SARADC_AWOR2_AWOR_CH20_MASK              (0x100000U)
#define SARADC_AWOR2_AWOR_CH20_SHIFT             (20U)
#define SARADC_AWOR2_AWOR_CH20_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH20(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH20_SHIFT)) & SARADC_AWOR2_AWOR_CH20_MASK)

#define SARADC_AWOR2_AWOR_CH21_MASK              (0x200000U)
#define SARADC_AWOR2_AWOR_CH21_SHIFT             (21U)
#define SARADC_AWOR2_AWOR_CH21_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH21(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH21_SHIFT)) & SARADC_AWOR2_AWOR_CH21_MASK)

#define SARADC_AWOR2_AWOR_CH22_MASK              (0x400000U)
#define SARADC_AWOR2_AWOR_CH22_SHIFT             (22U)
#define SARADC_AWOR2_AWOR_CH22_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH22(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH22_SHIFT)) & SARADC_AWOR2_AWOR_CH22_MASK)

#define SARADC_AWOR2_AWOR_CH23_MASK              (0x800000U)
#define SARADC_AWOR2_AWOR_CH23_SHIFT             (23U)
#define SARADC_AWOR2_AWOR_CH23_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH23(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH23_SHIFT)) & SARADC_AWOR2_AWOR_CH23_MASK)

#define SARADC_AWOR2_AWOR_CH24_MASK              (0x1000000U)
#define SARADC_AWOR2_AWOR_CH24_SHIFT             (24U)
#define SARADC_AWOR2_AWOR_CH24_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH24(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH24_SHIFT)) & SARADC_AWOR2_AWOR_CH24_MASK)

#define SARADC_AWOR2_AWOR_CH25_MASK              (0x2000000U)
#define SARADC_AWOR2_AWOR_CH25_SHIFT             (25U)
#define SARADC_AWOR2_AWOR_CH25_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH25(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH25_SHIFT)) & SARADC_AWOR2_AWOR_CH25_MASK)

#define SARADC_AWOR2_AWOR_CH26_MASK              (0x4000000U)
#define SARADC_AWOR2_AWOR_CH26_SHIFT             (26U)
#define SARADC_AWOR2_AWOR_CH26_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH26(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH26_SHIFT)) & SARADC_AWOR2_AWOR_CH26_MASK)

#define SARADC_AWOR2_AWOR_CH27_MASK              (0x8000000U)
#define SARADC_AWOR2_AWOR_CH27_SHIFT             (27U)
#define SARADC_AWOR2_AWOR_CH27_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH27(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH27_SHIFT)) & SARADC_AWOR2_AWOR_CH27_MASK)

#define SARADC_AWOR2_AWOR_CH28_MASK              (0x10000000U)
#define SARADC_AWOR2_AWOR_CH28_SHIFT             (28U)
#define SARADC_AWOR2_AWOR_CH28_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH28(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH28_SHIFT)) & SARADC_AWOR2_AWOR_CH28_MASK)

#define SARADC_AWOR2_AWOR_CH29_MASK              (0x20000000U)
#define SARADC_AWOR2_AWOR_CH29_SHIFT             (29U)
#define SARADC_AWOR2_AWOR_CH29_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH29(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH29_SHIFT)) & SARADC_AWOR2_AWOR_CH29_MASK)

#define SARADC_AWOR2_AWOR_CH30_MASK              (0x40000000U)
#define SARADC_AWOR2_AWOR_CH30_SHIFT             (30U)
#define SARADC_AWOR2_AWOR_CH30_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH30(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH30_SHIFT)) & SARADC_AWOR2_AWOR_CH30_MASK)

#define SARADC_AWOR2_AWOR_CH31_MASK              (0x80000000U)
#define SARADC_AWOR2_AWOR_CH31_SHIFT             (31U)
#define SARADC_AWOR2_AWOR_CH31_WIDTH             (1U)
#define SARADC_AWOR2_AWOR_CH31(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_AWOR2_AWOR_CH31_SHIFT)) & SARADC_AWOR2_AWOR_CH31_MASK)
/*! @} */

/*! @name STC1 - Self-Test Configuration 1 */
/*! @{ */

#define SARADC_STC1_AWDEVBG_MASK                 (0x1U)
#define SARADC_STC1_AWDEVBG_SHIFT                (0U)
#define SARADC_STC1_AWDEVBG_WIDTH                (1U)
#define SARADC_STC1_AWDEVBG(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STC1_AWDEVBG_SHIFT)) & SARADC_STC1_AWDEVBG_MASK)

#define SARADC_STC1_AWDEVDD_MASK                 (0x2U)
#define SARADC_STC1_AWDEVDD_SHIFT                (1U)
#define SARADC_STC1_AWDEVDD_WIDTH                (1U)
#define SARADC_STC1_AWDEVDD(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STC1_AWDEVDD_SHIFT)) & SARADC_STC1_AWDEVDD_MASK)

#define SARADC_STC1_AWDEVRHL_MASK                (0x4U)
#define SARADC_STC1_AWDEVRHL_SHIFT               (2U)
#define SARADC_STC1_AWDEVRHL_WIDTH               (1U)
#define SARADC_STC1_AWDEVRHL(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC1_AWDEVRHL_SHIFT)) & SARADC_STC1_AWDEVRHL_MASK)

#define SARADC_STC1_WDTESPLY_MASK                (0x8U)
#define SARADC_STC1_WDTESPLY_SHIFT               (3U)
#define SARADC_STC1_WDTESPLY_WIDTH               (1U)
#define SARADC_STC1_WDTESPLY(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC1_WDTESPLY_SHIFT)) & SARADC_STC1_WDTESPLY_MASK)

#define SARADC_STC1_AWDEOFS_MASK                 (0x100U)
#define SARADC_STC1_AWDEOFS_SHIFT                (8U)
#define SARADC_STC1_AWDEOFS_WIDTH                (1U)
#define SARADC_STC1_AWDEOFS(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STC1_AWDEOFS_SHIFT)) & SARADC_STC1_AWDEOFS_MASK)

#define SARADC_STC1_WDTEOFS_MASK                 (0x200U)
#define SARADC_STC1_WDTEOFS_SHIFT                (9U)
#define SARADC_STC1_WDTEOFS_WIDTH                (1U)
#define SARADC_STC1_WDTEOFS(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STC1_WDTEOFS_SHIFT)) & SARADC_STC1_WDTEOFS_MASK)

#define SARADC_STC1_AWDECAP_MASK                 (0x10000U)
#define SARADC_STC1_AWDECAP_SHIFT                (16U)
#define SARADC_STC1_AWDECAP_WIDTH                (1U)
#define SARADC_STC1_AWDECAP(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STC1_AWDECAP_SHIFT)) & SARADC_STC1_AWDECAP_MASK)

#define SARADC_STC1_WDTECAP_MASK                 (0x20000U)
#define SARADC_STC1_WDTECAP_SHIFT                (17U)
#define SARADC_STC1_WDTECAP_WIDTH                (1U)
#define SARADC_STC1_WDTECAP(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STC1_WDTECAP_SHIFT)) & SARADC_STC1_WDTECAP_MASK)
/*! @} */

/*! @name STC2 - Self-Test Configuration 2 */
/*! @{ */

#define SARADC_STC2_FMA_S_MASK                   (0x1U)
#define SARADC_STC2_FMA_S_SHIFT                  (0U)
#define SARADC_STC2_FMA_S_WIDTH                  (1U)
#define SARADC_STC2_FMA_S(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_FMA_S_SHIFT)) & SARADC_STC2_FMA_S_MASK)

#define SARADC_STC2_FMA_OFS_MASK                 (0x2U)
#define SARADC_STC2_FMA_OFS_SHIFT                (1U)
#define SARADC_STC2_FMA_OFS_WIDTH                (1U)
#define SARADC_STC2_FMA_OFS(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_FMA_OFS_SHIFT)) & SARADC_STC2_FMA_OFS_MASK)

#define SARADC_STC2_FMA_CAP_MASK                 (0x4U)
#define SARADC_STC2_FMA_CAP_SHIFT                (2U)
#define SARADC_STC2_FMA_CAP_WIDTH                (1U)
#define SARADC_STC2_FMA_CAP(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_FMA_CAP_SHIFT)) & SARADC_STC2_FMA_CAP_MASK)

#define SARADC_STC2_FMAWDTER_MASK                (0x8U)
#define SARADC_STC2_FMAWDTER_SHIFT               (3U)
#define SARADC_STC2_FMAWDTER_WIDTH               (1U)
#define SARADC_STC2_FMAWDTER(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_FMAWDTER_SHIFT)) & SARADC_STC2_FMAWDTER_MASK)

#define SARADC_STC2_FMAWDSER_MASK                (0x10U)
#define SARADC_STC2_FMAWDSER_SHIFT               (4U)
#define SARADC_STC2_FMAWDSER_WIDTH               (1U)
#define SARADC_STC2_FMAWDSER(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_FMAWDSER_SHIFT)) & SARADC_STC2_FMAWDSER_MASK)

#define SARADC_STC2_ST_EN_MASK                   (0x20U)
#define SARADC_STC2_ST_EN_SHIFT                  (5U)
#define SARADC_STC2_ST_EN_WIDTH                  (1U)
#define SARADC_STC2_ST_EN(x)                     (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_ST_EN_SHIFT)) & SARADC_STC2_ST_EN_MASK)

#define SARADC_STC2_MSKVBGER_MASK                (0x40U)
#define SARADC_STC2_MSKVBGER_SHIFT               (6U)
#define SARADC_STC2_MSKVBGER_WIDTH               (1U)
#define SARADC_STC2_MSKVBGER(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKVBGER_SHIFT)) & SARADC_STC2_MSKVBGER_MASK)

#define SARADC_STC2_MSKVDDER_MASK                (0x80U)
#define SARADC_STC2_MSKVDDER_SHIFT               (7U)
#define SARADC_STC2_MSKVDDER_WIDTH               (1U)
#define SARADC_STC2_MSKVDDER(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKVDDER_SHIFT)) & SARADC_STC2_MSKVDDER_MASK)

#define SARADC_STC2_MSKVRERR_MASK                (0x100U)
#define SARADC_STC2_MSKVRERR_SHIFT               (8U)
#define SARADC_STC2_MSKVRERR_WIDTH               (1U)
#define SARADC_STC2_MSKVRERR(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKVRERR_SHIFT)) & SARADC_STC2_MSKVRERR_MASK)

#define SARADC_STC2_MSKOFSER_MASK                (0x200U)
#define SARADC_STC2_MSKOFSER_SHIFT               (9U)
#define SARADC_STC2_MSKOFSER_WIDTH               (1U)
#define SARADC_STC2_MSKOFSER(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKOFSER_SHIFT)) & SARADC_STC2_MSKOFSER_MASK)

#define SARADC_STC2_MSKCAPER_MASK                (0x400U)
#define SARADC_STC2_MSKCAPER_SHIFT               (10U)
#define SARADC_STC2_MSKCAPER_WIDTH               (1U)
#define SARADC_STC2_MSKCAPER(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKCAPER_SHIFT)) & SARADC_STC2_MSKCAPER_MASK)

#define SARADC_STC2_MSKEOA_S_MASK                (0x800U)
#define SARADC_STC2_MSKEOA_S_SHIFT               (11U)
#define SARADC_STC2_MSKEOA_S_WIDTH               (1U)
#define SARADC_STC2_MSKEOA_S(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKEOA_S_SHIFT)) & SARADC_STC2_MSKEOA_S_MASK)

#define SARADC_STC2_MSKEOA_O_MASK                (0x1000U)
#define SARADC_STC2_MSKEOA_O_SHIFT               (12U)
#define SARADC_STC2_MSKEOA_O_WIDTH               (1U)
#define SARADC_STC2_MSKEOA_O(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKEOA_O_SHIFT)) & SARADC_STC2_MSKEOA_O_MASK)

#define SARADC_STC2_MSKEOA_C_MASK                (0x2000U)
#define SARADC_STC2_MSKEOA_C_SHIFT               (13U)
#define SARADC_STC2_MSKEOA_C_WIDTH               (1U)
#define SARADC_STC2_MSKEOA_C(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKEOA_C_SHIFT)) & SARADC_STC2_MSKEOA_C_MASK)

#define SARADC_STC2_MSKEOC_S_MASK                (0x4000U)
#define SARADC_STC2_MSKEOC_S_SHIFT               (14U)
#define SARADC_STC2_MSKEOC_S_WIDTH               (1U)
#define SARADC_STC2_MSKEOC_S(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKEOC_S_SHIFT)) & SARADC_STC2_MSKEOC_S_MASK)

#define SARADC_STC2_MSKEOC_O_MASK                (0x8000U)
#define SARADC_STC2_MSKEOC_O_SHIFT               (15U)
#define SARADC_STC2_MSKEOC_O_WIDTH               (1U)
#define SARADC_STC2_MSKEOC_O(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKEOC_O_SHIFT)) & SARADC_STC2_MSKEOC_O_MASK)

#define SARADC_STC2_MSKEOC_C_MASK                (0x10000U)
#define SARADC_STC2_MSKEOC_C_SHIFT               (16U)
#define SARADC_STC2_MSKEOC_C_WIDTH               (1U)
#define SARADC_STC2_MSKEOC_C(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKEOC_C_SHIFT)) & SARADC_STC2_MSKEOC_C_MASK)

#define SARADC_STC2_MSKWDERR_MASK                (0x20000U)
#define SARADC_STC2_MSKWDERR_SHIFT               (17U)
#define SARADC_STC2_MSKWDERR_WIDTH               (1U)
#define SARADC_STC2_MSKWDERR(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_MSKWDERR_SHIFT)) & SARADC_STC2_MSKWDERR_MASK)

#define SARADC_STC2_SERR_MASK                    (0x40000U)
#define SARADC_STC2_SERR_SHIFT                   (18U)
#define SARADC_STC2_SERR_WIDTH                   (1U)
#define SARADC_STC2_SERR(x)                      (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_SERR_SHIFT)) & SARADC_STC2_SERR_MASK)

#define SARADC_STC2_ALG_MASK                     (0xC0000000U)
#define SARADC_STC2_ALG_SHIFT                    (30U)
#define SARADC_STC2_ALG_WIDTH                    (2U)
#define SARADC_STC2_ALG(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_STC2_ALG_SHIFT)) & SARADC_STC2_ALG_MASK)
/*! @} */

/*! @name STBR - Self-Test Baud Rate */
/*! @{ */

#define SARADC_STBR_BR_MASK                      (0xFFU)
#define SARADC_STBR_BR_SHIFT                     (0U)
#define SARADC_STBR_BR_WIDTH                     (8U)
#define SARADC_STBR_BR(x)                        (((uint32_t)(((uint32_t)(x)) << SARADC_STBR_BR_SHIFT)) & SARADC_STBR_BR_MASK)

#define SARADC_STBR_WDT_MASK                     (0x70000U)
#define SARADC_STBR_WDT_SHIFT                    (16U)
#define SARADC_STBR_WDT_WIDTH                    (3U)
#define SARADC_STBR_WDT(x)                       (((uint32_t)(((uint32_t)(x)) << SARADC_STBR_WDT_SHIFT)) & SARADC_STBR_WDT_MASK)
/*! @} */

/*! @name STS1_P - Self-Test Status 1 for P-SARADC */
/*! @{ */

#define SARADC_STS1_P_VRNUMBER_MASK              (0x7U)
#define SARADC_STS1_P_VRNUMBER_SHIFT             (0U)
#define SARADC_STS1_P_VRNUMBER_WIDTH             (3U)
#define SARADC_STS1_P_VRNUMBER(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_VRNUMBER_SHIFT)) & SARADC_STS1_P_VRNUMBER_MASK)

#define SARADC_STS1_P_ERRVBG_MASK                (0x8U)
#define SARADC_STS1_P_ERRVBG_SHIFT               (3U)
#define SARADC_STS1_P_ERRVBG_WIDTH               (1U)
#define SARADC_STS1_P_ERRVBG(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_ERRVBG_SHIFT)) & SARADC_STS1_P_ERRVBG_MASK)

#define SARADC_STS1_P_ERRVDD_MASK                (0x10U)
#define SARADC_STS1_P_ERRVDD_SHIFT               (4U)
#define SARADC_STS1_P_ERRVDD_WIDTH               (1U)
#define SARADC_STS1_P_ERRVDD(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_ERRVDD_SHIFT)) & SARADC_STS1_P_ERRVDD_MASK)

#define SARADC_STS1_P_ERRVRTST_MASK              (0x20U)
#define SARADC_STS1_P_ERRVRTST_SHIFT             (5U)
#define SARADC_STS1_P_ERRVRTST_WIDTH             (1U)
#define SARADC_STS1_P_ERRVRTST(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_ERRVRTST_SHIFT)) & SARADC_STS1_P_ERRVRTST_MASK)

#define SARADC_STS1_P_ERROFS_MASK                (0x40U)
#define SARADC_STS1_P_ERROFS_SHIFT               (6U)
#define SARADC_STS1_P_ERROFS_WIDTH               (1U)
#define SARADC_STS1_P_ERROFS(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_ERROFS_SHIFT)) & SARADC_STS1_P_ERROFS_MASK)

#define SARADC_STS1_P_ERRCAP_MASK                (0x80U)
#define SARADC_STS1_P_ERRCAP_SHIFT               (7U)
#define SARADC_STS1_P_ERRCAP_WIDTH               (1U)
#define SARADC_STS1_P_ERRCAP(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_ERRCAP_SHIFT)) & SARADC_STS1_P_ERRCAP_MASK)

#define SARADC_STS1_P_CAPNUM_MASK                (0xFF00U)
#define SARADC_STS1_P_CAPNUM_SHIFT               (8U)
#define SARADC_STS1_P_CAPNUM_WIDTH               (8U)
#define SARADC_STS1_P_CAPNUM(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_CAPNUM_SHIFT)) & SARADC_STS1_P_CAPNUM_MASK)

#define SARADC_STS1_P_WDGEOA_S_MASK              (0x10000U)
#define SARADC_STS1_P_WDGEOA_S_SHIFT             (16U)
#define SARADC_STS1_P_WDGEOA_S_WIDTH             (1U)
#define SARADC_STS1_P_WDGEOA_S(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_WDGEOA_S_SHIFT)) & SARADC_STS1_P_WDGEOA_S_MASK)

#define SARADC_STS1_P_WDGEOA_O_MASK              (0x20000U)
#define SARADC_STS1_P_WDGEOA_O_SHIFT             (17U)
#define SARADC_STS1_P_WDGEOA_O_WIDTH             (1U)
#define SARADC_STS1_P_WDGEOA_O(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_WDGEOA_O_SHIFT)) & SARADC_STS1_P_WDGEOA_O_MASK)

#define SARADC_STS1_P_WDGEOA_C_MASK              (0x40000U)
#define SARADC_STS1_P_WDGEOA_C_SHIFT             (18U)
#define SARADC_STS1_P_WDGEOA_C_WIDTH             (1U)
#define SARADC_STS1_P_WDGEOA_C(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_WDGEOA_C_SHIFT)) & SARADC_STS1_P_WDGEOA_C_MASK)

#define SARADC_STS1_P_STEOCSUP_MASK              (0x80000U)
#define SARADC_STS1_P_STEOCSUP_SHIFT             (19U)
#define SARADC_STS1_P_STEOCSUP_WIDTH             (1U)
#define SARADC_STS1_P_STEOCSUP(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_STEOCSUP_SHIFT)) & SARADC_STS1_P_STEOCSUP_MASK)

#define SARADC_STS1_P_STEOCOFS_MASK              (0x100000U)
#define SARADC_STS1_P_STEOCOFS_SHIFT             (20U)
#define SARADC_STS1_P_STEOCOFS_WIDTH             (1U)
#define SARADC_STS1_P_STEOCOFS(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_STEOCOFS_SHIFT)) & SARADC_STS1_P_STEOCOFS_MASK)

#define SARADC_STS1_P_STEOCCAP_MASK              (0x200000U)
#define SARADC_STS1_P_STEOCCAP_SHIFT             (21U)
#define SARADC_STS1_P_STEOCCAP_WIDTH             (1U)
#define SARADC_STS1_P_STEOCCAP(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_STEOCCAP_SHIFT)) & SARADC_STS1_P_STEOCCAP_MASK)

#define SARADC_STS1_P_OVERWR_MASK                (0x400000U)
#define SARADC_STS1_P_OVERWR_SHIFT               (22U)
#define SARADC_STS1_P_OVERWR_WIDTH               (1U)
#define SARADC_STS1_P_OVERWR(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_OVERWR_SHIFT)) & SARADC_STS1_P_OVERWR_MASK)

#define SARADC_STS1_P_WDTERR_MASK                (0x800000U)
#define SARADC_STS1_P_WDTERR_SHIFT               (23U)
#define SARADC_STS1_P_WDTERR_WIDTH               (1U)
#define SARADC_STS1_P_WDTERR(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_P_WDTERR_SHIFT)) & SARADC_STS1_P_WDTERR_MASK)
/*! @} */

/*! @name STS1_M - Self-Test Status 1 for M-SARADC */
/*! @{ */

#define SARADC_STS1_M_VRNUMBER_MASK              (0x7U)
#define SARADC_STS1_M_VRNUMBER_SHIFT             (0U)
#define SARADC_STS1_M_VRNUMBER_WIDTH             (3U)
#define SARADC_STS1_M_VRNUMBER(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_VRNUMBER_SHIFT)) & SARADC_STS1_M_VRNUMBER_MASK)

#define SARADC_STS1_M_ERRVBG_MASK                (0x8U)
#define SARADC_STS1_M_ERRVBG_SHIFT               (3U)
#define SARADC_STS1_M_ERRVBG_WIDTH               (1U)
#define SARADC_STS1_M_ERRVBG(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_ERRVBG_SHIFT)) & SARADC_STS1_M_ERRVBG_MASK)

#define SARADC_STS1_M_ERRVDD_MASK                (0x10U)
#define SARADC_STS1_M_ERRVDD_SHIFT               (4U)
#define SARADC_STS1_M_ERRVDD_WIDTH               (1U)
#define SARADC_STS1_M_ERRVDD(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_ERRVDD_SHIFT)) & SARADC_STS1_M_ERRVDD_MASK)

#define SARADC_STS1_M_ERRVRTST_MASK              (0x20U)
#define SARADC_STS1_M_ERRVRTST_SHIFT             (5U)
#define SARADC_STS1_M_ERRVRTST_WIDTH             (1U)
#define SARADC_STS1_M_ERRVRTST(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_ERRVRTST_SHIFT)) & SARADC_STS1_M_ERRVRTST_MASK)

#define SARADC_STS1_M_ERROFS_MASK                (0x40U)
#define SARADC_STS1_M_ERROFS_SHIFT               (6U)
#define SARADC_STS1_M_ERROFS_WIDTH               (1U)
#define SARADC_STS1_M_ERROFS(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_ERROFS_SHIFT)) & SARADC_STS1_M_ERROFS_MASK)

#define SARADC_STS1_M_ERRCAP_MASK                (0x80U)
#define SARADC_STS1_M_ERRCAP_SHIFT               (7U)
#define SARADC_STS1_M_ERRCAP_WIDTH               (1U)
#define SARADC_STS1_M_ERRCAP(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_ERRCAP_SHIFT)) & SARADC_STS1_M_ERRCAP_MASK)

#define SARADC_STS1_M_CAPNUM_MASK                (0xFF00U)
#define SARADC_STS1_M_CAPNUM_SHIFT               (8U)
#define SARADC_STS1_M_CAPNUM_WIDTH               (8U)
#define SARADC_STS1_M_CAPNUM(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_CAPNUM_SHIFT)) & SARADC_STS1_M_CAPNUM_MASK)

#define SARADC_STS1_M_WDGEOA_S_MASK              (0x10000U)
#define SARADC_STS1_M_WDGEOA_S_SHIFT             (16U)
#define SARADC_STS1_M_WDGEOA_S_WIDTH             (1U)
#define SARADC_STS1_M_WDGEOA_S(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_WDGEOA_S_SHIFT)) & SARADC_STS1_M_WDGEOA_S_MASK)

#define SARADC_STS1_M_WDGEOA_O_MASK              (0x20000U)
#define SARADC_STS1_M_WDGEOA_O_SHIFT             (17U)
#define SARADC_STS1_M_WDGEOA_O_WIDTH             (1U)
#define SARADC_STS1_M_WDGEOA_O(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_WDGEOA_O_SHIFT)) & SARADC_STS1_M_WDGEOA_O_MASK)

#define SARADC_STS1_M_WDGEOA_C_MASK              (0x40000U)
#define SARADC_STS1_M_WDGEOA_C_SHIFT             (18U)
#define SARADC_STS1_M_WDGEOA_C_WIDTH             (1U)
#define SARADC_STS1_M_WDGEOA_C(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_WDGEOA_C_SHIFT)) & SARADC_STS1_M_WDGEOA_C_MASK)

#define SARADC_STS1_M_STEOCSUP_MASK              (0x80000U)
#define SARADC_STS1_M_STEOCSUP_SHIFT             (19U)
#define SARADC_STS1_M_STEOCSUP_WIDTH             (1U)
#define SARADC_STS1_M_STEOCSUP(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_STEOCSUP_SHIFT)) & SARADC_STS1_M_STEOCSUP_MASK)

#define SARADC_STS1_M_STEOCOFS_MASK              (0x100000U)
#define SARADC_STS1_M_STEOCOFS_SHIFT             (20U)
#define SARADC_STS1_M_STEOCOFS_WIDTH             (1U)
#define SARADC_STS1_M_STEOCOFS(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_STEOCOFS_SHIFT)) & SARADC_STS1_M_STEOCOFS_MASK)

#define SARADC_STS1_M_STEOCCAP_MASK              (0x200000U)
#define SARADC_STS1_M_STEOCCAP_SHIFT             (21U)
#define SARADC_STS1_M_STEOCCAP_WIDTH             (1U)
#define SARADC_STS1_M_STEOCCAP(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_STEOCCAP_SHIFT)) & SARADC_STS1_M_STEOCCAP_MASK)

#define SARADC_STS1_M_OVERWR_MASK                (0x400000U)
#define SARADC_STS1_M_OVERWR_SHIFT               (22U)
#define SARADC_STS1_M_OVERWR_WIDTH               (1U)
#define SARADC_STS1_M_OVERWR(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_OVERWR_SHIFT)) & SARADC_STS1_M_OVERWR_MASK)

#define SARADC_STS1_M_WDTERR_MASK                (0x800000U)
#define SARADC_STS1_M_WDTERR_SHIFT               (23U)
#define SARADC_STS1_M_WDTERR_WIDTH               (1U)
#define SARADC_STS1_M_WDTERR(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STS1_M_WDTERR_SHIFT)) & SARADC_STS1_M_WDTERR_MASK)
/*! @} */

/*! @name STS2_P - Self-Test Status 2 for P-SARADC */
/*! @{ */

#define SARADC_STS2_P_DATVBGER_MASK              (0xFFFFU)
#define SARADC_STS2_P_DATVBGER_SHIFT             (0U)
#define SARADC_STS2_P_DATVBGER_WIDTH             (16U)
#define SARADC_STS2_P_DATVBGER(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS2_P_DATVBGER_SHIFT)) & SARADC_STS2_P_DATVBGER_MASK)

#define SARADC_STS2_P_DATVRER_MASK               (0xFFFF0000U)
#define SARADC_STS2_P_DATVRER_SHIFT              (16U)
#define SARADC_STS2_P_DATVRER_WIDTH              (16U)
#define SARADC_STS2_P_DATVRER(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_STS2_P_DATVRER_SHIFT)) & SARADC_STS2_P_DATVRER_MASK)
/*! @} */

/*! @name STS2_M - Self-Test Status 2 for M-SARADC */
/*! @{ */

#define SARADC_STS2_M_DATVBGER_MASK              (0xFFFFU)
#define SARADC_STS2_M_DATVBGER_SHIFT             (0U)
#define SARADC_STS2_M_DATVBGER_WIDTH             (16U)
#define SARADC_STS2_M_DATVBGER(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS2_M_DATVBGER_SHIFT)) & SARADC_STS2_M_DATVBGER_MASK)

#define SARADC_STS2_M_DATVRER_MASK               (0xFFFF0000U)
#define SARADC_STS2_M_DATVRER_SHIFT              (16U)
#define SARADC_STS2_M_DATVRER_WIDTH              (16U)
#define SARADC_STS2_M_DATVRER(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_STS2_M_DATVRER_SHIFT)) & SARADC_STS2_M_DATVRER_MASK)
/*! @} */

/*! @name STS3_P - Self-Test Status 3 for P-SARADC */
/*! @{ */

#define SARADC_STS3_P_DATVDERI_MASK              (0x3U)
#define SARADC_STS3_P_DATVDERI_SHIFT             (0U)
#define SARADC_STS3_P_DATVDERI_WIDTH             (2U)
#define SARADC_STS3_P_DATVDERI(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS3_P_DATVDERI_SHIFT)) & SARADC_STS3_P_DATVDERI_MASK)

#define SARADC_STS3_P_OVFERVDD_MASK              (0x8000U)
#define SARADC_STS3_P_OVFERVDD_SHIFT             (15U)
#define SARADC_STS3_P_OVFERVDD_WIDTH             (1U)
#define SARADC_STS3_P_OVFERVDD(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS3_P_OVFERVDD_SHIFT)) & SARADC_STS3_P_OVFERVDD_MASK)

#define SARADC_STS3_P_DATVDERF_MASK              (0xFFFF0000U)
#define SARADC_STS3_P_DATVDERF_SHIFT             (16U)
#define SARADC_STS3_P_DATVDERF_WIDTH             (16U)
#define SARADC_STS3_P_DATVDERF(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS3_P_DATVDERF_SHIFT)) & SARADC_STS3_P_DATVDERF_MASK)
/*! @} */

/*! @name STS3_M - Self-Test Status 3 for M-SARADC */
/*! @{ */

#define SARADC_STS3_M_DATVDERI_MASK              (0x3U)
#define SARADC_STS3_M_DATVDERI_SHIFT             (0U)
#define SARADC_STS3_M_DATVDERI_WIDTH             (2U)
#define SARADC_STS3_M_DATVDERI(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS3_M_DATVDERI_SHIFT)) & SARADC_STS3_M_DATVDERI_MASK)

#define SARADC_STS3_M_OVFERVDD_MASK              (0x8000U)
#define SARADC_STS3_M_OVFERVDD_SHIFT             (15U)
#define SARADC_STS3_M_OVFERVDD_WIDTH             (1U)
#define SARADC_STS3_M_OVFERVDD(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS3_M_OVFERVDD_SHIFT)) & SARADC_STS3_M_OVFERVDD_MASK)

#define SARADC_STS3_M_DATVDERF_MASK              (0xFFFF0000U)
#define SARADC_STS3_M_DATVDERF_SHIFT             (16U)
#define SARADC_STS3_M_DATVDERF_WIDTH             (16U)
#define SARADC_STS3_M_DATVDERF(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS3_M_DATVDERF_SHIFT)) & SARADC_STS3_M_DATVDERF_MASK)
/*! @} */

/*! @name STS4_P - Self-Test Status 4 for P-SARADC */
/*! @{ */

#define SARADC_STS4_P_DATOFSER_MASK              (0xFFFFU)
#define SARADC_STS4_P_DATOFSER_SHIFT             (0U)
#define SARADC_STS4_P_DATOFSER_WIDTH             (16U)
#define SARADC_STS4_P_DATOFSER(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS4_P_DATOFSER_SHIFT)) & SARADC_STS4_P_DATOFSER_MASK)

#define SARADC_STS4_P_DATCAPER_MASK              (0xFFFF0000U)
#define SARADC_STS4_P_DATCAPER_SHIFT             (16U)
#define SARADC_STS4_P_DATCAPER_WIDTH             (16U)
#define SARADC_STS4_P_DATCAPER(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS4_P_DATCAPER_SHIFT)) & SARADC_STS4_P_DATCAPER_MASK)
/*! @} */

/*! @name STS4_M - Self-Test Status 4 for M-SARADC */
/*! @{ */

#define SARADC_STS4_M_DATOFSER_MASK              (0xFFFFU)
#define SARADC_STS4_M_DATOFSER_SHIFT             (0U)
#define SARADC_STS4_M_DATOFSER_WIDTH             (16U)
#define SARADC_STS4_M_DATOFSER(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS4_M_DATOFSER_SHIFT)) & SARADC_STS4_M_DATOFSER_MASK)

#define SARADC_STS4_M_DATCAPER_MASK              (0xFFFF0000U)
#define SARADC_STS4_M_DATCAPER_SHIFT             (16U)
#define SARADC_STS4_M_DATCAPER_WIDTH             (16U)
#define SARADC_STS4_M_DATCAPER(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STS4_M_DATCAPER_SHIFT)) & SARADC_STS4_M_DATCAPER_MASK)
/*! @} */

/*! @name STD1_P - Self-Test Conversion Data 1 for P-SARADC */
/*! @{ */

#define SARADC_STD1_P_TCDATA_MASK                (0xFFFFU)
#define SARADC_STD1_P_TCDATA_SHIFT               (0U)
#define SARADC_STD1_P_TCDATA_WIDTH               (16U)
#define SARADC_STD1_P_TCDATA(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STD1_P_TCDATA_SHIFT)) & SARADC_STD1_P_TCDATA_MASK)

#define SARADC_STD1_P_OWERWR_MASK                (0x40000U)
#define SARADC_STD1_P_OWERWR_SHIFT               (18U)
#define SARADC_STD1_P_OWERWR_WIDTH               (1U)
#define SARADC_STD1_P_OWERWR(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STD1_P_OWERWR_SHIFT)) & SARADC_STD1_P_OWERWR_MASK)

#define SARADC_STD1_P_VALID_MASK                 (0x80000U)
#define SARADC_STD1_P_VALID_SHIFT                (19U)
#define SARADC_STD1_P_VALID_WIDTH                (1U)
#define SARADC_STD1_P_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STD1_P_VALID_SHIFT)) & SARADC_STD1_P_VALID_MASK)
/*! @} */

/*! @name STD1_M - Self-Test Conversion Data 1 for M-SARADC */
/*! @{ */

#define SARADC_STD1_M_TCDATA_MASK                (0xFFFFU)
#define SARADC_STD1_M_TCDATA_SHIFT               (0U)
#define SARADC_STD1_M_TCDATA_WIDTH               (16U)
#define SARADC_STD1_M_TCDATA(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STD1_M_TCDATA_SHIFT)) & SARADC_STD1_M_TCDATA_MASK)

#define SARADC_STD1_M_OWERWR_MASK                (0x40000U)
#define SARADC_STD1_M_OWERWR_SHIFT               (18U)
#define SARADC_STD1_M_OWERWR_WIDTH               (1U)
#define SARADC_STD1_M_OWERWR(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STD1_M_OWERWR_SHIFT)) & SARADC_STD1_M_OWERWR_MASK)

#define SARADC_STD1_M_VALID_MASK                 (0x80000U)
#define SARADC_STD1_M_VALID_SHIFT                (19U)
#define SARADC_STD1_M_VALID_WIDTH                (1U)
#define SARADC_STD1_M_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STD1_M_VALID_SHIFT)) & SARADC_STD1_M_VALID_MASK)
/*! @} */

/*! @name STD2_P - Self-Test Conversion Data 2 for P-SARADC */
/*! @{ */

#define SARADC_STD2_P_ITCDATA_MASK               (0x3U)
#define SARADC_STD2_P_ITCDATA_SHIFT              (0U)
#define SARADC_STD2_P_ITCDATA_WIDTH              (2U)
#define SARADC_STD2_P_ITCDATA(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_STD2_P_ITCDATA_SHIFT)) & SARADC_STD2_P_ITCDATA_MASK)

#define SARADC_STD2_P_OWERWR_MASK                (0x4000U)
#define SARADC_STD2_P_OWERWR_SHIFT               (14U)
#define SARADC_STD2_P_OWERWR_WIDTH               (1U)
#define SARADC_STD2_P_OWERWR(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STD2_P_OWERWR_SHIFT)) & SARADC_STD2_P_OWERWR_MASK)

#define SARADC_STD2_P_VALID_MASK                 (0x8000U)
#define SARADC_STD2_P_VALID_SHIFT                (15U)
#define SARADC_STD2_P_VALID_WIDTH                (1U)
#define SARADC_STD2_P_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STD2_P_VALID_SHIFT)) & SARADC_STD2_P_VALID_MASK)

#define SARADC_STD2_P_FTCDATA_MASK               (0xFFFF0000U)
#define SARADC_STD2_P_FTCDATA_SHIFT              (16U)
#define SARADC_STD2_P_FTCDATA_WIDTH              (16U)
#define SARADC_STD2_P_FTCDATA(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_STD2_P_FTCDATA_SHIFT)) & SARADC_STD2_P_FTCDATA_MASK)
/*! @} */

/*! @name STD2_M - Self-Test Conversion Data 2 for M-SARADC */
/*! @{ */

#define SARADC_STD2_M_ITCDATA_MASK               (0x3U)
#define SARADC_STD2_M_ITCDATA_SHIFT              (0U)
#define SARADC_STD2_M_ITCDATA_WIDTH              (2U)
#define SARADC_STD2_M_ITCDATA(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_STD2_M_ITCDATA_SHIFT)) & SARADC_STD2_M_ITCDATA_MASK)

#define SARADC_STD2_M_OWERWR_MASK                (0x4000U)
#define SARADC_STD2_M_OWERWR_SHIFT               (14U)
#define SARADC_STD2_M_OWERWR_WIDTH               (1U)
#define SARADC_STD2_M_OWERWR(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_STD2_M_OWERWR_SHIFT)) & SARADC_STD2_M_OWERWR_MASK)

#define SARADC_STD2_M_VALID_MASK                 (0x8000U)
#define SARADC_STD2_M_VALID_SHIFT                (15U)
#define SARADC_STD2_M_VALID_WIDTH                (1U)
#define SARADC_STD2_M_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_STD2_M_VALID_SHIFT)) & SARADC_STD2_M_VALID_MASK)

#define SARADC_STD2_M_FTCDATA_MASK               (0xFFFF0000U)
#define SARADC_STD2_M_FTCDATA_SHIFT              (16U)
#define SARADC_STD2_M_FTCDATA_WIDTH              (16U)
#define SARADC_STD2_M_FTCDATA(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_STD2_M_FTCDATA_SHIFT)) & SARADC_STD2_M_FTCDATA_MASK)
/*! @} */

/*! @name STAWVBG - Self Test Analog Watchdog Threshold for Bandgap Supply */
/*! @{ */

#define SARADC_STAWVBG_THRLVBG_MASK              (0xFFFFU)
#define SARADC_STAWVBG_THRLVBG_SHIFT             (0U)
#define SARADC_STAWVBG_THRLVBG_WIDTH             (16U)
#define SARADC_STAWVBG_THRLVBG(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STAWVBG_THRLVBG_SHIFT)) & SARADC_STAWVBG_THRLVBG_MASK)

#define SARADC_STAWVBG_THRHVBG_MASK              (0xFFFF0000U)
#define SARADC_STAWVBG_THRHVBG_SHIFT             (16U)
#define SARADC_STAWVBG_THRHVBG_WIDTH             (16U)
#define SARADC_STAWVBG_THRHVBG(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STAWVBG_THRHVBG_SHIFT)) & SARADC_STAWVBG_THRHVBG_MASK)
/*! @} */

/*! @name STAWVDDI - Self Test Analog Watchdog Threshold for VDD (Integer Part) */
/*! @{ */

#define SARADC_STAWVDDI_THRLVDDI_MASK            (0xFFFFU)
#define SARADC_STAWVDDI_THRLVDDI_SHIFT           (0U)
#define SARADC_STAWVDDI_THRLVDDI_WIDTH           (16U)
#define SARADC_STAWVDDI_THRLVDDI(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_STAWVDDI_THRLVDDI_SHIFT)) & SARADC_STAWVDDI_THRLVDDI_MASK)

#define SARADC_STAWVDDI_THRHVDDI_MASK            (0xFFFF0000U)
#define SARADC_STAWVDDI_THRHVDDI_SHIFT           (16U)
#define SARADC_STAWVDDI_THRHVDDI_WIDTH           (16U)
#define SARADC_STAWVDDI_THRHVDDI(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_STAWVDDI_THRHVDDI_SHIFT)) & SARADC_STAWVDDI_THRHVDDI_MASK)
/*! @} */

/*! @name STAWVDDF - Self Test Analog Watchdog Threshold for VDD (Fractional Part) */
/*! @{ */

#define SARADC_STAWVDDF_THRLVDDF_MASK            (0xFFFFU)
#define SARADC_STAWVDDF_THRLVDDF_SHIFT           (0U)
#define SARADC_STAWVDDF_THRLVDDF_WIDTH           (16U)
#define SARADC_STAWVDDF_THRLVDDF(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_STAWVDDF_THRLVDDF_SHIFT)) & SARADC_STAWVDDF_THRLVDDF_MASK)

#define SARADC_STAWVDDF_THRHVDDF_MASK            (0xFFFF0000U)
#define SARADC_STAWVDDF_THRHVDDF_SHIFT           (16U)
#define SARADC_STAWVDDF_THRHVDDF_WIDTH           (16U)
#define SARADC_STAWVDDF_THRHVDDF(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_STAWVDDF_THRHVDDF_SHIFT)) & SARADC_STAWVDDF_THRHVDDF_MASK)
/*! @} */

/*! @name STAWVRHL - Self Test Analog Watchdog Threshold for Reference High Supply */
/*! @{ */

#define SARADC_STAWVRHL_THRLVRHL_MASK            (0xFFFFU)
#define SARADC_STAWVRHL_THRLVRHL_SHIFT           (0U)
#define SARADC_STAWVRHL_THRLVRHL_WIDTH           (16U)
#define SARADC_STAWVRHL_THRLVRHL(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_STAWVRHL_THRLVRHL_SHIFT)) & SARADC_STAWVRHL_THRLVRHL_MASK)

#define SARADC_STAWVRHL_VRCORXN_MASK             (0xFF0000U)
#define SARADC_STAWVRHL_VRCORXN_SHIFT            (16U)
#define SARADC_STAWVRHL_VRCORXN_WIDTH            (8U)
#define SARADC_STAWVRHL_VRCORXN(x)               (((uint32_t)(((uint32_t)(x)) << SARADC_STAWVRHL_VRCORXN_SHIFT)) & SARADC_STAWVRHL_VRCORXN_MASK)

#define SARADC_STAWVRHL_VREFL_MASK               (0xFF000000U)
#define SARADC_STAWVRHL_VREFL_SHIFT              (24U)
#define SARADC_STAWVRHL_VREFL_WIDTH              (8U)
#define SARADC_STAWVRHL_VREFL(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_STAWVRHL_VREFL_SHIFT)) & SARADC_STAWVRHL_VREFL_MASK)
/*! @} */

/*! @name STAWOFS - Self Test Analog Watchdog Threshold for Offset */
/*! @{ */

#define SARADC_STAWOFS_THRLOFS_MASK              (0xFFFFU)
#define SARADC_STAWOFS_THRLOFS_SHIFT             (0U)
#define SARADC_STAWOFS_THRLOFS_WIDTH             (16U)
#define SARADC_STAWOFS_THRLOFS(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STAWOFS_THRLOFS_SHIFT)) & SARADC_STAWOFS_THRLOFS_MASK)

#define SARADC_STAWOFS_THRHOFS_MASK              (0xFFFF0000U)
#define SARADC_STAWOFS_THRHOFS_SHIFT             (16U)
#define SARADC_STAWOFS_THRHOFS_WIDTH             (16U)
#define SARADC_STAWOFS_THRHOFS(x)                (((uint32_t)(((uint32_t)(x)) << SARADC_STAWOFS_THRHOFS_SHIFT)) & SARADC_STAWOFS_THRHOFS_MASK)
/*! @} */

/*! @name STAWCAPM - Self Test Analog Watchdog Threshold for MSB Capacitor */
/*! @{ */

#define SARADC_STAWCAPM_THRLCAPM_MASK            (0xFFFFU)
#define SARADC_STAWCAPM_THRLCAPM_SHIFT           (0U)
#define SARADC_STAWCAPM_THRLCAPM_WIDTH           (16U)
#define SARADC_STAWCAPM_THRLCAPM(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_STAWCAPM_THRLCAPM_SHIFT)) & SARADC_STAWCAPM_THRLCAPM_MASK)

#define SARADC_STAWCAPM_THRHCAPM_MASK            (0xFFFF0000U)
#define SARADC_STAWCAPM_THRHCAPM_SHIFT           (16U)
#define SARADC_STAWCAPM_THRHCAPM_WIDTH           (16U)
#define SARADC_STAWCAPM_THRHCAPM(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_STAWCAPM_THRHCAPM_SHIFT)) & SARADC_STAWCAPM_THRHCAPM_MASK)
/*! @} */

/*! @name STAWCAPI - Self Test Analog Watchdog Threshold for ISB Capacitor */
/*! @{ */

#define SARADC_STAWCAPI_THRLCAPI_MASK            (0xFFFFU)
#define SARADC_STAWCAPI_THRLCAPI_SHIFT           (0U)
#define SARADC_STAWCAPI_THRLCAPI_WIDTH           (16U)
#define SARADC_STAWCAPI_THRLCAPI(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_STAWCAPI_THRLCAPI_SHIFT)) & SARADC_STAWCAPI_THRLCAPI_MASK)

#define SARADC_STAWCAPI_THRHCAPI_MASK            (0xFFFF0000U)
#define SARADC_STAWCAPI_THRHCAPI_SHIFT           (16U)
#define SARADC_STAWCAPI_THRHCAPI_WIDTH           (16U)
#define SARADC_STAWCAPI_THRHCAPI(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_STAWCAPI_THRHCAPI_SHIFT)) & SARADC_STAWCAPI_THRHCAPI_MASK)
/*! @} */

/*! @name STAWCAPL - Self Test Analog Watchdog Threshold for LSB Capacitor */
/*! @{ */

#define SARADC_STAWCAPL_THRLCAPL_MASK            (0xFFFFU)
#define SARADC_STAWCAPL_THRLCAPL_SHIFT           (0U)
#define SARADC_STAWCAPL_THRLCAPL_WIDTH           (16U)
#define SARADC_STAWCAPL_THRLCAPL(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_STAWCAPL_THRLCAPL_SHIFT)) & SARADC_STAWCAPL_THRLCAPL_MASK)

#define SARADC_STAWCAPL_THRHCAPL_MASK            (0xFFFF0000U)
#define SARADC_STAWCAPL_THRHCAPL_SHIFT           (16U)
#define SARADC_STAWCAPL_THRHCAPL_WIDTH           (16U)
#define SARADC_STAWCAPL_THRHCAPL(x)              (((uint32_t)(((uint32_t)(x)) << SARADC_STAWCAPL_THRHCAPL_SHIFT)) & SARADC_STAWCAPL_THRHCAPL_MASK)
/*! @} */

/*! @name GCC_P - Gain Calibration Control for P-SARADC Converter */
/*! @{ */

#define SARADC_GCC_P_GAIN_CAL_MASK               (0x1FFFFU)
#define SARADC_GCC_P_GAIN_CAL_SHIFT              (0U)
#define SARADC_GCC_P_GAIN_CAL_WIDTH              (17U)
#define SARADC_GCC_P_GAIN_CAL(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_GCC_P_GAIN_CAL_SHIFT)) & SARADC_GCC_P_GAIN_CAL_MASK)

#define SARADC_GCC_P_VALID_MASK                  (0x1000000U)
#define SARADC_GCC_P_VALID_SHIFT                 (24U)
#define SARADC_GCC_P_VALID_WIDTH                 (1U)
#define SARADC_GCC_P_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_GCC_P_VALID_SHIFT)) & SARADC_GCC_P_VALID_MASK)
/*! @} */

/*! @name GCC_M - Gain Calibration Control for M-SARADC SARADC Converter */
/*! @{ */

#define SARADC_GCC_M_GAIN_CAL_MASK               (0x1FFFFU)
#define SARADC_GCC_M_GAIN_CAL_SHIFT              (0U)
#define SARADC_GCC_M_GAIN_CAL_WIDTH              (17U)
#define SARADC_GCC_M_GAIN_CAL(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_GCC_M_GAIN_CAL_SHIFT)) & SARADC_GCC_M_GAIN_CAL_MASK)

#define SARADC_GCC_M_VALID_MASK                  (0x1000000U)
#define SARADC_GCC_M_VALID_SHIFT                 (24U)
#define SARADC_GCC_M_VALID_WIDTH                 (1U)
#define SARADC_GCC_M_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_GCC_M_VALID_SHIFT)) & SARADC_GCC_M_VALID_MASK)
/*! @} */

/*! @name GCR_P - Gain Calculation Result for P-SARADC Converter */
/*! @{ */

#define SARADC_GCR_P_GCALR_MASK                  (0x1FFFFU)
#define SARADC_GCR_P_GCALR_SHIFT                 (0U)
#define SARADC_GCR_P_GCALR_WIDTH                 (17U)
#define SARADC_GCR_P_GCALR(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_GCR_P_GCALR_SHIFT)) & SARADC_GCR_P_GCALR_MASK)

#define SARADC_GCR_P_VALID_MASK                  (0x1000000U)
#define SARADC_GCR_P_VALID_SHIFT                 (24U)
#define SARADC_GCR_P_VALID_WIDTH                 (1U)
#define SARADC_GCR_P_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_GCR_P_VALID_SHIFT)) & SARADC_GCR_P_VALID_MASK)
/*! @} */

/*! @name GCR_M - Gain Calculation Result for M-SARADC Converter */
/*! @{ */

#define SARADC_GCR_M_GCALR_MASK                  (0x1FFFFU)
#define SARADC_GCR_M_GCALR_SHIFT                 (0U)
#define SARADC_GCR_M_GCALR_WIDTH                 (17U)
#define SARADC_GCR_M_GCALR(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_GCR_M_GCALR_SHIFT)) & SARADC_GCR_M_GCALR_MASK)

#define SARADC_GCR_M_VALID_MASK                  (0x1000000U)
#define SARADC_GCR_M_VALID_SHIFT                 (24U)
#define SARADC_GCR_M_VALID_WIDTH                 (1U)
#define SARADC_GCR_M_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << SARADC_GCR_M_VALID_SHIFT)) & SARADC_GCR_M_VALID_MASK)
/*! @} */

/*! @name CALSTSP0 - Calibration Fail Status 0 for P-SARADC */
/*! @{ */

#define SARADC_CALSTSP0_CAP0_MASK                (0x1U)
#define SARADC_CALSTSP0_CAP0_SHIFT               (0U)
#define SARADC_CALSTSP0_CAP0_WIDTH               (1U)
#define SARADC_CALSTSP0_CAP0(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP0_SHIFT)) & SARADC_CALSTSP0_CAP0_MASK)

#define SARADC_CALSTSP0_CAP1_MASK                (0x2U)
#define SARADC_CALSTSP0_CAP1_SHIFT               (1U)
#define SARADC_CALSTSP0_CAP1_WIDTH               (1U)
#define SARADC_CALSTSP0_CAP1(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP1_SHIFT)) & SARADC_CALSTSP0_CAP1_MASK)

#define SARADC_CALSTSP0_CAP2_MASK                (0x4U)
#define SARADC_CALSTSP0_CAP2_SHIFT               (2U)
#define SARADC_CALSTSP0_CAP2_WIDTH               (1U)
#define SARADC_CALSTSP0_CAP2(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP2_SHIFT)) & SARADC_CALSTSP0_CAP2_MASK)

#define SARADC_CALSTSP0_CAP3_MASK                (0x8U)
#define SARADC_CALSTSP0_CAP3_SHIFT               (3U)
#define SARADC_CALSTSP0_CAP3_WIDTH               (1U)
#define SARADC_CALSTSP0_CAP3(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP3_SHIFT)) & SARADC_CALSTSP0_CAP3_MASK)

#define SARADC_CALSTSP0_CAP4_MASK                (0x10U)
#define SARADC_CALSTSP0_CAP4_SHIFT               (4U)
#define SARADC_CALSTSP0_CAP4_WIDTH               (1U)
#define SARADC_CALSTSP0_CAP4(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP4_SHIFT)) & SARADC_CALSTSP0_CAP4_MASK)

#define SARADC_CALSTSP0_CAP5_MASK                (0x20U)
#define SARADC_CALSTSP0_CAP5_SHIFT               (5U)
#define SARADC_CALSTSP0_CAP5_WIDTH               (1U)
#define SARADC_CALSTSP0_CAP5(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP5_SHIFT)) & SARADC_CALSTSP0_CAP5_MASK)

#define SARADC_CALSTSP0_CAP6_MASK                (0x40U)
#define SARADC_CALSTSP0_CAP6_SHIFT               (6U)
#define SARADC_CALSTSP0_CAP6_WIDTH               (1U)
#define SARADC_CALSTSP0_CAP6(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP6_SHIFT)) & SARADC_CALSTSP0_CAP6_MASK)

#define SARADC_CALSTSP0_CAP7_MASK                (0x80U)
#define SARADC_CALSTSP0_CAP7_SHIFT               (7U)
#define SARADC_CALSTSP0_CAP7_WIDTH               (1U)
#define SARADC_CALSTSP0_CAP7(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP7_SHIFT)) & SARADC_CALSTSP0_CAP7_MASK)

#define SARADC_CALSTSP0_CAP8_MASK                (0x100U)
#define SARADC_CALSTSP0_CAP8_SHIFT               (8U)
#define SARADC_CALSTSP0_CAP8_WIDTH               (1U)
#define SARADC_CALSTSP0_CAP8(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP8_SHIFT)) & SARADC_CALSTSP0_CAP8_MASK)

#define SARADC_CALSTSP0_CAP9_MASK                (0x200U)
#define SARADC_CALSTSP0_CAP9_SHIFT               (9U)
#define SARADC_CALSTSP0_CAP9_WIDTH               (1U)
#define SARADC_CALSTSP0_CAP9(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP9_SHIFT)) & SARADC_CALSTSP0_CAP9_MASK)

#define SARADC_CALSTSP0_CAP10_MASK               (0x400U)
#define SARADC_CALSTSP0_CAP10_SHIFT              (10U)
#define SARADC_CALSTSP0_CAP10_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP10(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP10_SHIFT)) & SARADC_CALSTSP0_CAP10_MASK)

#define SARADC_CALSTSP0_CAP11_MASK               (0x800U)
#define SARADC_CALSTSP0_CAP11_SHIFT              (11U)
#define SARADC_CALSTSP0_CAP11_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP11(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP11_SHIFT)) & SARADC_CALSTSP0_CAP11_MASK)

#define SARADC_CALSTSP0_CAP12_MASK               (0x1000U)
#define SARADC_CALSTSP0_CAP12_SHIFT              (12U)
#define SARADC_CALSTSP0_CAP12_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP12(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP12_SHIFT)) & SARADC_CALSTSP0_CAP12_MASK)

#define SARADC_CALSTSP0_CAP13_MASK               (0x2000U)
#define SARADC_CALSTSP0_CAP13_SHIFT              (13U)
#define SARADC_CALSTSP0_CAP13_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP13(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP13_SHIFT)) & SARADC_CALSTSP0_CAP13_MASK)

#define SARADC_CALSTSP0_CAP14_MASK               (0x4000U)
#define SARADC_CALSTSP0_CAP14_SHIFT              (14U)
#define SARADC_CALSTSP0_CAP14_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP14(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP14_SHIFT)) & SARADC_CALSTSP0_CAP14_MASK)

#define SARADC_CALSTSP0_CAP15_MASK               (0x8000U)
#define SARADC_CALSTSP0_CAP15_SHIFT              (15U)
#define SARADC_CALSTSP0_CAP15_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP15(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP15_SHIFT)) & SARADC_CALSTSP0_CAP15_MASK)

#define SARADC_CALSTSP0_CAP16_MASK               (0x10000U)
#define SARADC_CALSTSP0_CAP16_SHIFT              (16U)
#define SARADC_CALSTSP0_CAP16_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP16(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP16_SHIFT)) & SARADC_CALSTSP0_CAP16_MASK)

#define SARADC_CALSTSP0_CAP17_MASK               (0x20000U)
#define SARADC_CALSTSP0_CAP17_SHIFT              (17U)
#define SARADC_CALSTSP0_CAP17_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP17(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP17_SHIFT)) & SARADC_CALSTSP0_CAP17_MASK)

#define SARADC_CALSTSP0_CAP18_MASK               (0x40000U)
#define SARADC_CALSTSP0_CAP18_SHIFT              (18U)
#define SARADC_CALSTSP0_CAP18_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP18(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP18_SHIFT)) & SARADC_CALSTSP0_CAP18_MASK)

#define SARADC_CALSTSP0_CAP19_MASK               (0x80000U)
#define SARADC_CALSTSP0_CAP19_SHIFT              (19U)
#define SARADC_CALSTSP0_CAP19_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP19(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP19_SHIFT)) & SARADC_CALSTSP0_CAP19_MASK)

#define SARADC_CALSTSP0_CAP20_MASK               (0x100000U)
#define SARADC_CALSTSP0_CAP20_SHIFT              (20U)
#define SARADC_CALSTSP0_CAP20_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP20(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP20_SHIFT)) & SARADC_CALSTSP0_CAP20_MASK)

#define SARADC_CALSTSP0_CAP21_MASK               (0x200000U)
#define SARADC_CALSTSP0_CAP21_SHIFT              (21U)
#define SARADC_CALSTSP0_CAP21_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP21(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP21_SHIFT)) & SARADC_CALSTSP0_CAP21_MASK)

#define SARADC_CALSTSP0_CAP22_MASK               (0x400000U)
#define SARADC_CALSTSP0_CAP22_SHIFT              (22U)
#define SARADC_CALSTSP0_CAP22_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP22(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP22_SHIFT)) & SARADC_CALSTSP0_CAP22_MASK)

#define SARADC_CALSTSP0_CAP23_MASK               (0x800000U)
#define SARADC_CALSTSP0_CAP23_SHIFT              (23U)
#define SARADC_CALSTSP0_CAP23_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP23(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP23_SHIFT)) & SARADC_CALSTSP0_CAP23_MASK)

#define SARADC_CALSTSP0_CAP24_MASK               (0x1000000U)
#define SARADC_CALSTSP0_CAP24_SHIFT              (24U)
#define SARADC_CALSTSP0_CAP24_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP24(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP24_SHIFT)) & SARADC_CALSTSP0_CAP24_MASK)

#define SARADC_CALSTSP0_CAP25_MASK               (0x2000000U)
#define SARADC_CALSTSP0_CAP25_SHIFT              (25U)
#define SARADC_CALSTSP0_CAP25_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP25(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP25_SHIFT)) & SARADC_CALSTSP0_CAP25_MASK)

#define SARADC_CALSTSP0_CAP26_MASK               (0x4000000U)
#define SARADC_CALSTSP0_CAP26_SHIFT              (26U)
#define SARADC_CALSTSP0_CAP26_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP26(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP26_SHIFT)) & SARADC_CALSTSP0_CAP26_MASK)

#define SARADC_CALSTSP0_CAP27_MASK               (0x8000000U)
#define SARADC_CALSTSP0_CAP27_SHIFT              (27U)
#define SARADC_CALSTSP0_CAP27_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP27(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP27_SHIFT)) & SARADC_CALSTSP0_CAP27_MASK)

#define SARADC_CALSTSP0_CAP28_MASK               (0x10000000U)
#define SARADC_CALSTSP0_CAP28_SHIFT              (28U)
#define SARADC_CALSTSP0_CAP28_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP28(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP28_SHIFT)) & SARADC_CALSTSP0_CAP28_MASK)

#define SARADC_CALSTSP0_CAP29_MASK               (0x20000000U)
#define SARADC_CALSTSP0_CAP29_SHIFT              (29U)
#define SARADC_CALSTSP0_CAP29_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP29(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP29_SHIFT)) & SARADC_CALSTSP0_CAP29_MASK)

#define SARADC_CALSTSP0_CAP30_MASK               (0x40000000U)
#define SARADC_CALSTSP0_CAP30_SHIFT              (30U)
#define SARADC_CALSTSP0_CAP30_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP30(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP30_SHIFT)) & SARADC_CALSTSP0_CAP30_MASK)

#define SARADC_CALSTSP0_CAP31_MASK               (0x80000000U)
#define SARADC_CALSTSP0_CAP31_SHIFT              (31U)
#define SARADC_CALSTSP0_CAP31_WIDTH              (1U)
#define SARADC_CALSTSP0_CAP31(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP0_CAP31_SHIFT)) & SARADC_CALSTSP0_CAP31_MASK)
/*! @} */

/*! @name CALSTSP1 - Calibration Fail Status 1 for P-SARADC */
/*! @{ */

#define SARADC_CALSTSP1_CAP32_MASK               (0x1U)
#define SARADC_CALSTSP1_CAP32_SHIFT              (0U)
#define SARADC_CALSTSP1_CAP32_WIDTH              (1U)
#define SARADC_CALSTSP1_CAP32(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP1_CAP32_SHIFT)) & SARADC_CALSTSP1_CAP32_MASK)

#define SARADC_CALSTSP1_OFS_MASK                 (0x2U)
#define SARADC_CALSTSP1_OFS_SHIFT                (1U)
#define SARADC_CALSTSP1_OFS_WIDTH                (1U)
#define SARADC_CALSTSP1_OFS(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSP1_OFS_SHIFT)) & SARADC_CALSTSP1_OFS_MASK)
/*! @} */

/*! @name CALSTSM0 - Calibration Fail Status 0 for M-SARADC */
/*! @{ */

#define SARADC_CALSTSM0_CAP0_MASK                (0x1U)
#define SARADC_CALSTSM0_CAP0_SHIFT               (0U)
#define SARADC_CALSTSM0_CAP0_WIDTH               (1U)
#define SARADC_CALSTSM0_CAP0(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP0_SHIFT)) & SARADC_CALSTSM0_CAP0_MASK)

#define SARADC_CALSTSM0_CAP1_MASK                (0x2U)
#define SARADC_CALSTSM0_CAP1_SHIFT               (1U)
#define SARADC_CALSTSM0_CAP1_WIDTH               (1U)
#define SARADC_CALSTSM0_CAP1(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP1_SHIFT)) & SARADC_CALSTSM0_CAP1_MASK)

#define SARADC_CALSTSM0_CAP2_MASK                (0x4U)
#define SARADC_CALSTSM0_CAP2_SHIFT               (2U)
#define SARADC_CALSTSM0_CAP2_WIDTH               (1U)
#define SARADC_CALSTSM0_CAP2(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP2_SHIFT)) & SARADC_CALSTSM0_CAP2_MASK)

#define SARADC_CALSTSM0_CAP3_MASK                (0x8U)
#define SARADC_CALSTSM0_CAP3_SHIFT               (3U)
#define SARADC_CALSTSM0_CAP3_WIDTH               (1U)
#define SARADC_CALSTSM0_CAP3(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP3_SHIFT)) & SARADC_CALSTSM0_CAP3_MASK)

#define SARADC_CALSTSM0_CAP4_MASK                (0x10U)
#define SARADC_CALSTSM0_CAP4_SHIFT               (4U)
#define SARADC_CALSTSM0_CAP4_WIDTH               (1U)
#define SARADC_CALSTSM0_CAP4(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP4_SHIFT)) & SARADC_CALSTSM0_CAP4_MASK)

#define SARADC_CALSTSM0_CAP5_MASK                (0x20U)
#define SARADC_CALSTSM0_CAP5_SHIFT               (5U)
#define SARADC_CALSTSM0_CAP5_WIDTH               (1U)
#define SARADC_CALSTSM0_CAP5(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP5_SHIFT)) & SARADC_CALSTSM0_CAP5_MASK)

#define SARADC_CALSTSM0_CAP6_MASK                (0x40U)
#define SARADC_CALSTSM0_CAP6_SHIFT               (6U)
#define SARADC_CALSTSM0_CAP6_WIDTH               (1U)
#define SARADC_CALSTSM0_CAP6(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP6_SHIFT)) & SARADC_CALSTSM0_CAP6_MASK)

#define SARADC_CALSTSM0_CAP7_MASK                (0x80U)
#define SARADC_CALSTSM0_CAP7_SHIFT               (7U)
#define SARADC_CALSTSM0_CAP7_WIDTH               (1U)
#define SARADC_CALSTSM0_CAP7(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP7_SHIFT)) & SARADC_CALSTSM0_CAP7_MASK)

#define SARADC_CALSTSM0_CAP8_MASK                (0x100U)
#define SARADC_CALSTSM0_CAP8_SHIFT               (8U)
#define SARADC_CALSTSM0_CAP8_WIDTH               (1U)
#define SARADC_CALSTSM0_CAP8(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP8_SHIFT)) & SARADC_CALSTSM0_CAP8_MASK)

#define SARADC_CALSTSM0_CAP9_MASK                (0x200U)
#define SARADC_CALSTSM0_CAP9_SHIFT               (9U)
#define SARADC_CALSTSM0_CAP9_WIDTH               (1U)
#define SARADC_CALSTSM0_CAP9(x)                  (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP9_SHIFT)) & SARADC_CALSTSM0_CAP9_MASK)

#define SARADC_CALSTSM0_CAP10_MASK               (0x400U)
#define SARADC_CALSTSM0_CAP10_SHIFT              (10U)
#define SARADC_CALSTSM0_CAP10_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP10(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP10_SHIFT)) & SARADC_CALSTSM0_CAP10_MASK)

#define SARADC_CALSTSM0_CAP11_MASK               (0x800U)
#define SARADC_CALSTSM0_CAP11_SHIFT              (11U)
#define SARADC_CALSTSM0_CAP11_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP11(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP11_SHIFT)) & SARADC_CALSTSM0_CAP11_MASK)

#define SARADC_CALSTSM0_CAP12_MASK               (0x1000U)
#define SARADC_CALSTSM0_CAP12_SHIFT              (12U)
#define SARADC_CALSTSM0_CAP12_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP12(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP12_SHIFT)) & SARADC_CALSTSM0_CAP12_MASK)

#define SARADC_CALSTSM0_CAP13_MASK               (0x2000U)
#define SARADC_CALSTSM0_CAP13_SHIFT              (13U)
#define SARADC_CALSTSM0_CAP13_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP13(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP13_SHIFT)) & SARADC_CALSTSM0_CAP13_MASK)

#define SARADC_CALSTSM0_CAP14_MASK               (0x4000U)
#define SARADC_CALSTSM0_CAP14_SHIFT              (14U)
#define SARADC_CALSTSM0_CAP14_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP14(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP14_SHIFT)) & SARADC_CALSTSM0_CAP14_MASK)

#define SARADC_CALSTSM0_CAP15_MASK               (0x8000U)
#define SARADC_CALSTSM0_CAP15_SHIFT              (15U)
#define SARADC_CALSTSM0_CAP15_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP15(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP15_SHIFT)) & SARADC_CALSTSM0_CAP15_MASK)

#define SARADC_CALSTSM0_CAP16_MASK               (0x10000U)
#define SARADC_CALSTSM0_CAP16_SHIFT              (16U)
#define SARADC_CALSTSM0_CAP16_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP16(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP16_SHIFT)) & SARADC_CALSTSM0_CAP16_MASK)

#define SARADC_CALSTSM0_CAP17_MASK               (0x20000U)
#define SARADC_CALSTSM0_CAP17_SHIFT              (17U)
#define SARADC_CALSTSM0_CAP17_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP17(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP17_SHIFT)) & SARADC_CALSTSM0_CAP17_MASK)

#define SARADC_CALSTSM0_CAP18_MASK               (0x40000U)
#define SARADC_CALSTSM0_CAP18_SHIFT              (18U)
#define SARADC_CALSTSM0_CAP18_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP18(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP18_SHIFT)) & SARADC_CALSTSM0_CAP18_MASK)

#define SARADC_CALSTSM0_CAP19_MASK               (0x80000U)
#define SARADC_CALSTSM0_CAP19_SHIFT              (19U)
#define SARADC_CALSTSM0_CAP19_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP19(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP19_SHIFT)) & SARADC_CALSTSM0_CAP19_MASK)

#define SARADC_CALSTSM0_CAP20_MASK               (0x100000U)
#define SARADC_CALSTSM0_CAP20_SHIFT              (20U)
#define SARADC_CALSTSM0_CAP20_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP20(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP20_SHIFT)) & SARADC_CALSTSM0_CAP20_MASK)

#define SARADC_CALSTSM0_CAP21_MASK               (0x200000U)
#define SARADC_CALSTSM0_CAP21_SHIFT              (21U)
#define SARADC_CALSTSM0_CAP21_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP21(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP21_SHIFT)) & SARADC_CALSTSM0_CAP21_MASK)

#define SARADC_CALSTSM0_CAP22_MASK               (0x400000U)
#define SARADC_CALSTSM0_CAP22_SHIFT              (22U)
#define SARADC_CALSTSM0_CAP22_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP22(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP22_SHIFT)) & SARADC_CALSTSM0_CAP22_MASK)

#define SARADC_CALSTSM0_CAP23_MASK               (0x800000U)
#define SARADC_CALSTSM0_CAP23_SHIFT              (23U)
#define SARADC_CALSTSM0_CAP23_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP23(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP23_SHIFT)) & SARADC_CALSTSM0_CAP23_MASK)

#define SARADC_CALSTSM0_CAP24_MASK               (0x1000000U)
#define SARADC_CALSTSM0_CAP24_SHIFT              (24U)
#define SARADC_CALSTSM0_CAP24_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP24(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP24_SHIFT)) & SARADC_CALSTSM0_CAP24_MASK)

#define SARADC_CALSTSM0_CAP25_MASK               (0x2000000U)
#define SARADC_CALSTSM0_CAP25_SHIFT              (25U)
#define SARADC_CALSTSM0_CAP25_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP25(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP25_SHIFT)) & SARADC_CALSTSM0_CAP25_MASK)

#define SARADC_CALSTSM0_CAP26_MASK               (0x4000000U)
#define SARADC_CALSTSM0_CAP26_SHIFT              (26U)
#define SARADC_CALSTSM0_CAP26_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP26(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP26_SHIFT)) & SARADC_CALSTSM0_CAP26_MASK)

#define SARADC_CALSTSM0_CAP27_MASK               (0x8000000U)
#define SARADC_CALSTSM0_CAP27_SHIFT              (27U)
#define SARADC_CALSTSM0_CAP27_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP27(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP27_SHIFT)) & SARADC_CALSTSM0_CAP27_MASK)

#define SARADC_CALSTSM0_CAP28_MASK               (0x10000000U)
#define SARADC_CALSTSM0_CAP28_SHIFT              (28U)
#define SARADC_CALSTSM0_CAP28_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP28(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP28_SHIFT)) & SARADC_CALSTSM0_CAP28_MASK)

#define SARADC_CALSTSM0_CAP29_MASK               (0x20000000U)
#define SARADC_CALSTSM0_CAP29_SHIFT              (29U)
#define SARADC_CALSTSM0_CAP29_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP29(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP29_SHIFT)) & SARADC_CALSTSM0_CAP29_MASK)

#define SARADC_CALSTSM0_CAP30_MASK               (0x40000000U)
#define SARADC_CALSTSM0_CAP30_SHIFT              (30U)
#define SARADC_CALSTSM0_CAP30_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP30(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP30_SHIFT)) & SARADC_CALSTSM0_CAP30_MASK)

#define SARADC_CALSTSM0_CAP31_MASK               (0x80000000U)
#define SARADC_CALSTSM0_CAP31_SHIFT              (31U)
#define SARADC_CALSTSM0_CAP31_WIDTH              (1U)
#define SARADC_CALSTSM0_CAP31(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM0_CAP31_SHIFT)) & SARADC_CALSTSM0_CAP31_MASK)
/*! @} */

/*! @name CALSTSM1 - Calibration Fail Status 1 for M-SARADC */
/*! @{ */

#define SARADC_CALSTSM1_CAP32_MASK               (0x1U)
#define SARADC_CALSTSM1_CAP32_SHIFT              (0U)
#define SARADC_CALSTSM1_CAP32_WIDTH              (1U)
#define SARADC_CALSTSM1_CAP32(x)                 (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM1_CAP32_SHIFT)) & SARADC_CALSTSM1_CAP32_MASK)

#define SARADC_CALSTSM1_OFS_MASK                 (0x2U)
#define SARADC_CALSTSM1_OFS_SHIFT                (1U)
#define SARADC_CALSTSM1_OFS_WIDTH                (1U)
#define SARADC_CALSTSM1_OFS(x)                   (((uint32_t)(((uint32_t)(x)) << SARADC_CALSTSM1_OFS_SHIFT)) & SARADC_CALSTSM1_OFS_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SARADC_Register_Masks */

/*!
 * @}
 */ /* end of group SARADC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_SARADC_H_) */
