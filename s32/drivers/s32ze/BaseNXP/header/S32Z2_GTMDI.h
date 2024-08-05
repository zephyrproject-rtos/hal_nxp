/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_GTMDI.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_GTMDI
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
#if !defined(S32Z2_GTMDI_H_)  /* Check if memory map has not been already included */
#define S32Z2_GTMDI_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- GTMDI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GTMDI_Peripheral_Access_Layer GTMDI Peripheral Access Layer
 * @{
 */

/** GTMDI - Register Layout Typedef */
typedef struct {
  __I  uint32_t DID;                               /**< Device Identity, offset: 0x0 */
  uint8_t RESERVED_0[16];
  __IO uint32_t DC;                                /**< GTMDI Development Control, offset: 0x14 */
  __I  uint32_t DS;                                /**< GTMDI Development Status, offset: 0x18 */
  uint8_t RESERVED_1[16];
  __IO uint32_t TIM_WPC1;                          /**< TIM Watchpoint Control 1, offset: 0x2C */
  __IO uint32_t TIM_WPC2;                          /**< TIM Watchpoint Control 2, offset: 0x30 */
  uint8_t RESERVED_2[16];
  __IO uint32_t TOM_WPC1;                          /**< TOM Watchpoint Control 1, offset: 0x44 */
  __IO uint32_t TOM_WPC2;                          /**< TOM Watchpoint Control 2, offset: 0x48 */
  uint8_t RESERVED_3[16];
  __IO uint32_t ATOM_WPC1;                         /**< ATOM Watchpoint Control 1, offset: 0x5C */
  __IO uint32_t ATOM_WPC2;                         /**< ATOM Watchpoint Control 2, offset: 0x60 */
  uint8_t RESERVED_4[16];
  __IO uint32_t SPEA_WPC1;                         /**< SPEA Watchpoint Control 1, offset: 0x74 */
  __IO uint32_t SPEA_WPC2;                         /**< SPEA Watchpoint Control 2, offset: 0x78 */
  uint8_t RESERVED_5[16];
  __IO uint32_t SPEB_WPC1;                         /**< SPEB Watchpoint Control 1, offset: 0x8C */
  __IO uint32_t SPEB_WPC2;                         /**< SPEB Watchpoint Control 2, offset: 0x90 */
  uint8_t RESERVED_6[16];
  __IO uint32_t DPLL_WPC1;                         /**< DPLL Watchpoint Control 1, offset: 0xA4 */
  __IO uint32_t DPLL_WPC2;                         /**< DPLL Watchpoint Control 2, offset: 0xA8 */
  __IO uint32_t DPLL_WPC3;                         /**< DPLL Watchpoint Control 3, offset: 0xAC */
  __IO uint32_t DPLL_WPC4;                         /**< DPLL Watchpoint Control 4, offset: 0xB0 */
  __IO uint32_t DPLL_WPC5;                         /**< DPLL Watchpoint Control 5, offset: 0xB4 */
  __IO uint32_t DPLL_DTC;                          /**< DPLL Data Trace Control, offset: 0xB8 */
  uint8_t RESERVED_7[12];
  __IO uint32_t ARU_WPC1;                          /**< ARU Watchpoint Control 1, offset: 0xC8 */
  __IO uint32_t ARU_WPC2;                          /**< ARU Watchpoint Control 2, offset: 0xCC */
  __IO uint32_t ARU_D0H;                           /**< ARU Watchpoint DATA0H, offset: 0xD0 */
  __IO uint32_t ARU_D0L;                           /**< ARU Watchpoint DATA0L, offset: 0xD4 */
  __IO uint32_t ARU_D1H;                           /**< ARU Watchpoint DATA1H, offset: 0xD8 */
  __IO uint32_t ARU_D1L;                           /**< ARU Watchpoint ARUD1L, offset: 0xDC */
  __IO uint32_t ARU_DTC;                           /**< ARU Data Trace Control, offset: 0xE0 */
  uint8_t RESERVED_8[4];
  __IO uint32_t MCS_HBC;                           /**< MCS Hardware Breakpoint (HBP) Control, offset: 0xE8 */
  __IO uint32_t MCS_HLT;                           /**< MCS Halt Control, offset: 0xEC */
  __IO uint32_t MCSA_DC;                           /**< MCSA Development Control, offset: 0xF0 */
  uint8_t RESERVED_9[4];
  __IO uint32_t MCSA_WPC;                          /**< MCSA Watchpoint Control, offset: 0xF8 */
  __IO uint32_t MCSA_PTC;                          /**< MCSA Program Fetch Trace Control, offset: 0xFC */
  __IO uint32_t MCSA_DTC;                          /**< MCSA Data Trace Control, offset: 0x100 */
  __IO uint32_t MCSA_WPA1;                         /**< MCSA Watchpoint Address 1, offset: 0x104 */
  __IO uint32_t MCSA_WPA2;                         /**< MCSA Watchpoint Address 2, offset: 0x108 */
  __IO uint32_t MCSA_WPD1;                         /**< MCSA Watchpoint Data 1, offset: 0x10C */
  __IO uint32_t MCSA_WPD2;                         /**< MCSA Watchpoint Data 2, offset: 0x110 */
  __IO uint32_t MCSA_CE;                           /**< MCSA Channel Enable, offset: 0x114 */
  uint8_t RESERVED_10[4];
  __IO uint32_t MCSA_DTAR1;                        /**< MCSA Data Trace Address Range 1, offset: 0x11C */
  __IO uint32_t MCSA_DTAR2;                        /**< MCSA Data Trace Address Range 2, offset: 0x120 */
  uint8_t RESERVED_11[16];
  __IO uint32_t MCSB_DC;                           /**< MCSB Development Control, offset: 0x134 */
  uint8_t RESERVED_12[4];
  __IO uint32_t MCSB_WPC;                          /**< MCSB Watchpoint Control, offset: 0x13C */
  __IO uint32_t MCSB_PTC;                          /**< MCSB Program Fetch Trace Control, offset: 0x140 */
  __IO uint32_t MCSB_DTC;                          /**< MCSB Data Trace Control, offset: 0x144 */
  __IO uint32_t MCSB_WPA1;                         /**< MCSB Watchpoint Address 1, offset: 0x148 */
  __IO uint32_t MCSB_WPA2;                         /**< MCSB Watchpoint Address 2, offset: 0x14C */
  __IO uint32_t MCSB_WPD1;                         /**< MCSB Watchpoint Data 1, offset: 0x150 */
  __IO uint32_t MCSB_WPD2;                         /**< MCSB Watchpoint Data 2, offset: 0x154 */
  __IO uint32_t MCSB_CE;                           /**< MCSB Channel Enable, offset: 0x158 */
  uint8_t RESERVED_13[4];
  __IO uint32_t MCSB_DTAR1;                        /**< MCSB Data Trace Address Range 1, offset: 0x160 */
  __IO uint32_t MCSB_DTAR2;                        /**< MCSB Data Trace Address Range 2, offset: 0x164 */
  uint8_t RESERVED_14[16];
  __IO uint32_t TBU0_WPC1;                         /**< TBU0 Watchpoint Control 1, offset: 0x178 */
  __IO uint32_t TBU0_WPC2;                         /**< TBUn Watchpoint Control 2, offset: 0x17C */
  __IO uint32_t TBU0_D;                            /**< TBU0 Watchpoint DATA, offset: 0x180 */
  uint8_t RESERVED_15[16];
  __IO uint32_t TBU1_WPC1;                         /**< TBUn Watchpoint Control 1, offset: 0x194 */
  __IO uint32_t TBU1_WPC2;                         /**< TBUn Watchpoint Control 2, offset: 0x198 */
  __IO uint32_t TBU1_D;                            /**< TBUn Watchpoint DATA, offset: 0x19C */
  uint8_t RESERVED_16[16];
  __IO uint32_t TBU2_WPC1;                         /**< TBUn Watchpoint Control 1, offset: 0x1B0 */
  __IO uint32_t TBU2_WPC2;                         /**< TBUn Watchpoint Control 2, offset: 0x1B4 */
  __IO uint32_t TBU2_D;                            /**< TBUn Watchpoint DATA, offset: 0x1B8 */
  uint8_t RESERVED_17[16];
  __IO uint32_t TBU3_WPC1;                         /**< TBUn Watchpoint Control 1, offset: 0x1CC */
  __IO uint32_t TBU3_WPC2;                         /**< TBUn Watchpoint Control 2, offset: 0x1D0 */
  __IO uint32_t TBU3_D;                            /**< TBUn Watchpoint DATA, offset: 0x1D4 */
  uint8_t RESERVED_18[16];
  __IO uint32_t TIO_IN_WPC1;                       /**< TIO IN watchpoint control register 1, offset: 0x1E8 */
  __IO uint32_t TIO_IN_WPC2;                       /**< TIO IN watchpoint control register 2, offset: 0x1EC */
  uint8_t RESERVED_19[16];
  __IO uint32_t TIO_OUT_WPC1;                      /**< TIO OUT Watchpoint Control 1, offset: 0x200 */
  __IO uint32_t TIO_OUT_WPC2;                      /**< TIO OUT Watchpoint Control 2, offset: 0x204 */
  uint8_t RESERVED_20[352];
  __IO uint32_t ATID;                              /**< ATB Bus ID Control, offset: 0x368 */
  uint8_t RESERVED_21[3152];
  __I  uint32_t DEVARCH;                           /**< Device Architecture, offset: 0xFBC */
  uint8_t RESERVED_22[12];
  __I  uint32_t DEVTYPE;                           /**< Device Type Identifier, offset: 0xFCC */
  __I  uint32_t PIDR4;                             /**< Peripheral Identification 4, offset: 0xFD0 */
       uint32_t PIDR5;                             /**< Peripheral Identification 5, offset: 0xFD4 */
       uint32_t PIDR6;                             /**< Peripheral Identification 6, offset: 0xFD8 */
       uint32_t PIDR7;                             /**< Peripheral Identification 7, offset: 0xFDC */
  __I  uint32_t PIDR0;                             /**< Peripheral Identification 0, offset: 0xFE0 */
  __I  uint32_t PIDR1;                             /**< Peripheral Identification 1, offset: 0xFE4 */
  __I  uint32_t PIDR2;                             /**< Peripheral Identification 2, offset: 0xFE8 */
  __I  uint32_t PIDR3;                             /**< Peripheral Identification 3, offset: 0xFEC */
  __I  uint32_t CIDR0;                             /**< Component Identification 0, offset: 0xFF0 */
  __I  uint32_t CIDR1;                             /**< Component Identification 1, offset: 0xFF4 */
  __I  uint32_t CIDR2;                             /**< Component Identification 2, offset: 0xFF8 */
  __I  uint32_t CIDR3;                             /**< Component Identification 3, offset: 0xFFC */
} GTMDI_Type, *GTMDI_MemMapPtr;

/** Number of instances of the GTMDI module. */
#define GTMDI_INSTANCE_COUNT                     (1u)

/* GTMDI - Peripheral instance base addresses */
/** Peripheral GTMDI base address */
#define IP_GTMDI_BASE                            (0x4D480000u)
/** Peripheral GTMDI base pointer */
#define IP_GTMDI                                 ((GTMDI_Type *)IP_GTMDI_BASE)
/** Array initializer of GTMDI peripheral base addresses */
#define IP_GTMDI_BASE_ADDRS                      { IP_GTMDI_BASE }
/** Array initializer of GTMDI peripheral base pointers */
#define IP_GTMDI_BASE_PTRS                       { IP_GTMDI }

/* ----------------------------------------------------------------------------
   -- GTMDI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GTMDI_Register_Masks GTMDI Register Masks
 * @{
 */

/*! @name DID - Device Identity */
/*! @{ */

#define GTMDI_DID_IDCODE_MASK                    (0x1U)
#define GTMDI_DID_IDCODE_SHIFT                   (0U)
#define GTMDI_DID_IDCODE_WIDTH                   (1U)
#define GTMDI_DID_IDCODE(x)                      (((uint32_t)(((uint32_t)(x)) << GTMDI_DID_IDCODE_SHIFT)) & GTMDI_DID_IDCODE_MASK)

#define GTMDI_DID_MIC_MASK                       (0xFFEU)
#define GTMDI_DID_MIC_SHIFT                      (1U)
#define GTMDI_DID_MIC_WIDTH                      (11U)
#define GTMDI_DID_MIC(x)                         (((uint32_t)(((uint32_t)(x)) << GTMDI_DID_MIC_SHIFT)) & GTMDI_DID_MIC_MASK)

#define GTMDI_DID_PIN_MASK                       (0x3FF000U)
#define GTMDI_DID_PIN_SHIFT                      (12U)
#define GTMDI_DID_PIN_WIDTH                      (10U)
#define GTMDI_DID_PIN(x)                         (((uint32_t)(((uint32_t)(x)) << GTMDI_DID_PIN_SHIFT)) & GTMDI_DID_PIN_MASK)

#define GTMDI_DID_DC_MASK                        (0xFC00000U)
#define GTMDI_DID_DC_SHIFT                       (22U)
#define GTMDI_DID_DC_WIDTH                       (6U)
#define GTMDI_DID_DC(x)                          (((uint32_t)(((uint32_t)(x)) << GTMDI_DID_DC_SHIFT)) & GTMDI_DID_DC_MASK)

#define GTMDI_DID_PRN_MASK                       (0xF0000000U)
#define GTMDI_DID_PRN_SHIFT                      (28U)
#define GTMDI_DID_PRN_WIDTH                      (4U)
#define GTMDI_DID_PRN(x)                         (((uint32_t)(((uint32_t)(x)) << GTMDI_DID_PRN_SHIFT)) & GTMDI_DID_PRN_MASK)
/*! @} */

/*! @name DC - GTMDI Development Control */
/*! @{ */

#define GTMDI_DC_TSFT_MASK                       (0x1U)
#define GTMDI_DC_TSFT_SHIFT                      (0U)
#define GTMDI_DC_TSFT_WIDTH                      (1U)
#define GTMDI_DC_TSFT(x)                         (((uint32_t)(((uint32_t)(x)) << GTMDI_DC_TSFT_SHIFT)) & GTMDI_DC_TSFT_MASK)

#define GTMDI_DC_SDBE_MASK                       (0x4U)
#define GTMDI_DC_SDBE_SHIFT                      (2U)
#define GTMDI_DC_SDBE_WIDTH                      (1U)
#define GTMDI_DC_SDBE(x)                         (((uint32_t)(((uint32_t)(x)) << GTMDI_DC_SDBE_SHIFT)) & GTMDI_DC_SDBE_MASK)

#define GTMDI_DC_DBR_MASK                        (0x8U)
#define GTMDI_DC_DBR_SHIFT                       (3U)
#define GTMDI_DC_DBR_WIDTH                       (1U)
#define GTMDI_DC_DBR(x)                          (((uint32_t)(((uint32_t)(x)) << GTMDI_DC_DBR_SHIFT)) & GTMDI_DC_DBR_MASK)

#define GTMDI_DC_DBE_MASK                        (0x10U)
#define GTMDI_DC_DBE_SHIFT                       (4U)
#define GTMDI_DC_DBE_WIDTH                       (1U)
#define GTMDI_DC_DBE(x)                          (((uint32_t)(((uint32_t)(x)) << GTMDI_DC_DBE_SHIFT)) & GTMDI_DC_DBE_MASK)

#define GTMDI_DC_CHR_MASK                        (0x100U)
#define GTMDI_DC_CHR_SHIFT                       (8U)
#define GTMDI_DC_CHR_WIDTH                       (1U)
#define GTMDI_DC_CHR(x)                          (((uint32_t)(((uint32_t)(x)) << GTMDI_DC_CHR_SHIFT)) & GTMDI_DC_CHR_MASK)

#define GTMDI_DC_EOS1_MASK                       (0x1F0000U)
#define GTMDI_DC_EOS1_SHIFT                      (16U)
#define GTMDI_DC_EOS1_WIDTH                      (5U)
#define GTMDI_DC_EOS1(x)                         (((uint32_t)(((uint32_t)(x)) << GTMDI_DC_EOS1_SHIFT)) & GTMDI_DC_EOS1_MASK)

#define GTMDI_DC_EOS0_MASK                       (0x1F000000U)
#define GTMDI_DC_EOS0_SHIFT                      (24U)
#define GTMDI_DC_EOS0_WIDTH                      (5U)
#define GTMDI_DC_EOS0(x)                         (((uint32_t)(((uint32_t)(x)) << GTMDI_DC_EOS0_SHIFT)) & GTMDI_DC_EOS0_MASK)

#define GTMDI_DC_GDE_MASK                        (0x80000000U)
#define GTMDI_DC_GDE_SHIFT                       (31U)
#define GTMDI_DC_GDE_WIDTH                       (1U)
#define GTMDI_DC_GDE(x)                          (((uint32_t)(((uint32_t)(x)) << GTMDI_DC_GDE_SHIFT)) & GTMDI_DC_GDE_MASK)
/*! @} */

/*! @name DS - GTMDI Development Status */
/*! @{ */

#define GTMDI_DS_HS2_MASK                        (0xFFFFU)
#define GTMDI_DS_HS2_SHIFT                       (0U)
#define GTMDI_DS_HS2_WIDTH                       (16U)
#define GTMDI_DS_HS2(x)                          (((uint32_t)(((uint32_t)(x)) << GTMDI_DS_HS2_SHIFT)) & GTMDI_DS_HS2_MASK)

#define GTMDI_DS_HS1_MASK                        (0x7FFF0000U)
#define GTMDI_DS_HS1_SHIFT                       (16U)
#define GTMDI_DS_HS1_WIDTH                       (15U)
#define GTMDI_DS_HS1(x)                          (((uint32_t)(((uint32_t)(x)) << GTMDI_DS_HS1_SHIFT)) & GTMDI_DS_HS1_MASK)

#define GTMDI_DS_HLT_MASK                        (0x80000000U)
#define GTMDI_DS_HLT_SHIFT                       (31U)
#define GTMDI_DS_HLT_WIDTH                       (1U)
#define GTMDI_DS_HLT(x)                          (((uint32_t)(((uint32_t)(x)) << GTMDI_DS_HLT_SHIFT)) & GTMDI_DS_HLT_MASK)
/*! @} */

/*! @name TIM_WPC1 - TIM Watchpoint Control 1 */
/*! @{ */

#define GTMDI_TIM_WPC1_CHSEL2_MASK               (0x7U)
#define GTMDI_TIM_WPC1_CHSEL2_SHIFT              (0U)
#define GTMDI_TIM_WPC1_CHSEL2_WIDTH              (3U)
#define GTMDI_TIM_WPC1_CHSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC1_CHSEL2_SHIFT)) & GTMDI_TIM_WPC1_CHSEL2_MASK)

#define GTMDI_TIM_WPC1_WMC2_MASK                 (0x40U)
#define GTMDI_TIM_WPC1_WMC2_SHIFT                (6U)
#define GTMDI_TIM_WPC1_WMC2_WIDTH                (1U)
#define GTMDI_TIM_WPC1_WMC2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC1_WMC2_SHIFT)) & GTMDI_TIM_WPC1_WMC2_MASK)

#define GTMDI_TIM_WPC1_HEN2_MASK                 (0x80U)
#define GTMDI_TIM_WPC1_HEN2_SHIFT                (7U)
#define GTMDI_TIM_WPC1_HEN2_WIDTH                (1U)
#define GTMDI_TIM_WPC1_HEN2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC1_HEN2_SHIFT)) & GTMDI_TIM_WPC1_HEN2_MASK)

#define GTMDI_TIM_WPC1_SSEL2_MASK                (0x700U)
#define GTMDI_TIM_WPC1_SSEL2_SHIFT               (8U)
#define GTMDI_TIM_WPC1_SSEL2_WIDTH               (3U)
#define GTMDI_TIM_WPC1_SSEL2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC1_SSEL2_SHIFT)) & GTMDI_TIM_WPC1_SSEL2_MASK)

#define GTMDI_TIM_WPC1_TSS2_MASK                 (0x3000U)
#define GTMDI_TIM_WPC1_TSS2_SHIFT                (12U)
#define GTMDI_TIM_WPC1_TSS2_WIDTH                (2U)
#define GTMDI_TIM_WPC1_TSS2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC1_TSS2_SHIFT)) & GTMDI_TIM_WPC1_TSS2_MASK)

#define GTMDI_TIM_WPC1_CHSEL1_MASK               (0x70000U)
#define GTMDI_TIM_WPC1_CHSEL1_SHIFT              (16U)
#define GTMDI_TIM_WPC1_CHSEL1_WIDTH              (3U)
#define GTMDI_TIM_WPC1_CHSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC1_CHSEL1_SHIFT)) & GTMDI_TIM_WPC1_CHSEL1_MASK)

#define GTMDI_TIM_WPC1_WMC1_MASK                 (0x400000U)
#define GTMDI_TIM_WPC1_WMC1_SHIFT                (22U)
#define GTMDI_TIM_WPC1_WMC1_WIDTH                (1U)
#define GTMDI_TIM_WPC1_WMC1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC1_WMC1_SHIFT)) & GTMDI_TIM_WPC1_WMC1_MASK)

#define GTMDI_TIM_WPC1_HEN1_MASK                 (0x800000U)
#define GTMDI_TIM_WPC1_HEN1_SHIFT                (23U)
#define GTMDI_TIM_WPC1_HEN1_WIDTH                (1U)
#define GTMDI_TIM_WPC1_HEN1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC1_HEN1_SHIFT)) & GTMDI_TIM_WPC1_HEN1_MASK)

#define GTMDI_TIM_WPC1_SSEL1_MASK                (0x7000000U)
#define GTMDI_TIM_WPC1_SSEL1_SHIFT               (24U)
#define GTMDI_TIM_WPC1_SSEL1_WIDTH               (3U)
#define GTMDI_TIM_WPC1_SSEL1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC1_SSEL1_SHIFT)) & GTMDI_TIM_WPC1_SSEL1_MASK)

#define GTMDI_TIM_WPC1_TSS1_MASK                 (0x30000000U)
#define GTMDI_TIM_WPC1_TSS1_SHIFT                (28U)
#define GTMDI_TIM_WPC1_TSS1_WIDTH                (2U)
#define GTMDI_TIM_WPC1_TSS1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC1_TSS1_SHIFT)) & GTMDI_TIM_WPC1_TSS1_MASK)
/*! @} */

/*! @name TIM_WPC2 - TIM Watchpoint Control 2 */
/*! @{ */

#define GTMDI_TIM_WPC2_SEN2_MASK                 (0x1U)
#define GTMDI_TIM_WPC2_SEN2_SHIFT                (0U)
#define GTMDI_TIM_WPC2_SEN2_WIDTH                (1U)
#define GTMDI_TIM_WPC2_SEN2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC2_SEN2_SHIFT)) & GTMDI_TIM_WPC2_SEN2_MASK)

#define GTMDI_TIM_WPC2_TEN2_MASK                 (0x2U)
#define GTMDI_TIM_WPC2_TEN2_SHIFT                (1U)
#define GTMDI_TIM_WPC2_TEN2_WIDTH                (1U)
#define GTMDI_TIM_WPC2_TEN2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC2_TEN2_SHIFT)) & GTMDI_TIM_WPC2_TEN2_MASK)

#define GTMDI_TIM_WPC2_STSEL2_MASK               (0x30U)
#define GTMDI_TIM_WPC2_STSEL2_SHIFT              (4U)
#define GTMDI_TIM_WPC2_STSEL2_WIDTH              (2U)
#define GTMDI_TIM_WPC2_STSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC2_STSEL2_SHIFT)) & GTMDI_TIM_WPC2_STSEL2_MASK)

#define GTMDI_TIM_WPC2_WTSEL2_MASK               (0x7000U)
#define GTMDI_TIM_WPC2_WTSEL2_SHIFT              (12U)
#define GTMDI_TIM_WPC2_WTSEL2_WIDTH              (3U)
#define GTMDI_TIM_WPC2_WTSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC2_WTSEL2_SHIFT)) & GTMDI_TIM_WPC2_WTSEL2_MASK)

#define GTMDI_TIM_WPC2_SEN1_MASK                 (0x10000U)
#define GTMDI_TIM_WPC2_SEN1_SHIFT                (16U)
#define GTMDI_TIM_WPC2_SEN1_WIDTH                (1U)
#define GTMDI_TIM_WPC2_SEN1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC2_SEN1_SHIFT)) & GTMDI_TIM_WPC2_SEN1_MASK)

#define GTMDI_TIM_WPC2_TEN1_MASK                 (0x20000U)
#define GTMDI_TIM_WPC2_TEN1_SHIFT                (17U)
#define GTMDI_TIM_WPC2_TEN1_WIDTH                (1U)
#define GTMDI_TIM_WPC2_TEN1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC2_TEN1_SHIFT)) & GTMDI_TIM_WPC2_TEN1_MASK)

#define GTMDI_TIM_WPC2_STSEL1_MASK               (0x300000U)
#define GTMDI_TIM_WPC2_STSEL1_SHIFT              (20U)
#define GTMDI_TIM_WPC2_STSEL1_WIDTH              (2U)
#define GTMDI_TIM_WPC2_STSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC2_STSEL1_SHIFT)) & GTMDI_TIM_WPC2_STSEL1_MASK)

#define GTMDI_TIM_WPC2_WTSEL1_MASK               (0x70000000U)
#define GTMDI_TIM_WPC2_WTSEL1_SHIFT              (28U)
#define GTMDI_TIM_WPC2_WTSEL1_WIDTH              (3U)
#define GTMDI_TIM_WPC2_WTSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TIM_WPC2_WTSEL1_SHIFT)) & GTMDI_TIM_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name TOM_WPC1 - TOM Watchpoint Control 1 */
/*! @{ */

#define GTMDI_TOM_WPC1_CHSEL2_MASK               (0xFU)
#define GTMDI_TOM_WPC1_CHSEL2_SHIFT              (0U)
#define GTMDI_TOM_WPC1_CHSEL2_WIDTH              (4U)
#define GTMDI_TOM_WPC1_CHSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_CHSEL2_SHIFT)) & GTMDI_TOM_WPC1_CHSEL2_MASK)

#define GTMDI_TOM_WPC1_WMC2_MASK                 (0x40U)
#define GTMDI_TOM_WPC1_WMC2_SHIFT                (6U)
#define GTMDI_TOM_WPC1_WMC2_WIDTH                (1U)
#define GTMDI_TOM_WPC1_WMC2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_WMC2_SHIFT)) & GTMDI_TOM_WPC1_WMC2_MASK)

#define GTMDI_TOM_WPC1_HEN2_MASK                 (0x80U)
#define GTMDI_TOM_WPC1_HEN2_SHIFT                (7U)
#define GTMDI_TOM_WPC1_HEN2_WIDTH                (1U)
#define GTMDI_TOM_WPC1_HEN2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_HEN2_SHIFT)) & GTMDI_TOM_WPC1_HEN2_MASK)

#define GTMDI_TOM_WPC1_SSEL2_MASK                (0x700U)
#define GTMDI_TOM_WPC1_SSEL2_SHIFT               (8U)
#define GTMDI_TOM_WPC1_SSEL2_WIDTH               (3U)
#define GTMDI_TOM_WPC1_SSEL2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_SSEL2_SHIFT)) & GTMDI_TOM_WPC1_SSEL2_MASK)

#define GTMDI_TOM_WPC1_TSS2_MASK                 (0x3000U)
#define GTMDI_TOM_WPC1_TSS2_SHIFT                (12U)
#define GTMDI_TOM_WPC1_TSS2_WIDTH                (2U)
#define GTMDI_TOM_WPC1_TSS2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_TSS2_SHIFT)) & GTMDI_TOM_WPC1_TSS2_MASK)

#define GTMDI_TOM_WPC1_POL2_MASK                 (0x8000U)
#define GTMDI_TOM_WPC1_POL2_SHIFT                (15U)
#define GTMDI_TOM_WPC1_POL2_WIDTH                (1U)
#define GTMDI_TOM_WPC1_POL2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_POL2_SHIFT)) & GTMDI_TOM_WPC1_POL2_MASK)

#define GTMDI_TOM_WPC1_CHSEL1_MASK               (0xF0000U)
#define GTMDI_TOM_WPC1_CHSEL1_SHIFT              (16U)
#define GTMDI_TOM_WPC1_CHSEL1_WIDTH              (4U)
#define GTMDI_TOM_WPC1_CHSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_CHSEL1_SHIFT)) & GTMDI_TOM_WPC1_CHSEL1_MASK)

#define GTMDI_TOM_WPC1_WMC1_MASK                 (0x400000U)
#define GTMDI_TOM_WPC1_WMC1_SHIFT                (22U)
#define GTMDI_TOM_WPC1_WMC1_WIDTH                (1U)
#define GTMDI_TOM_WPC1_WMC1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_WMC1_SHIFT)) & GTMDI_TOM_WPC1_WMC1_MASK)

#define GTMDI_TOM_WPC1_HEN1_MASK                 (0x800000U)
#define GTMDI_TOM_WPC1_HEN1_SHIFT                (23U)
#define GTMDI_TOM_WPC1_HEN1_WIDTH                (1U)
#define GTMDI_TOM_WPC1_HEN1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_HEN1_SHIFT)) & GTMDI_TOM_WPC1_HEN1_MASK)

#define GTMDI_TOM_WPC1_SSEL1_MASK                (0x7000000U)
#define GTMDI_TOM_WPC1_SSEL1_SHIFT               (24U)
#define GTMDI_TOM_WPC1_SSEL1_WIDTH               (3U)
#define GTMDI_TOM_WPC1_SSEL1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_SSEL1_SHIFT)) & GTMDI_TOM_WPC1_SSEL1_MASK)

#define GTMDI_TOM_WPC1_TSS1_MASK                 (0x30000000U)
#define GTMDI_TOM_WPC1_TSS1_SHIFT                (28U)
#define GTMDI_TOM_WPC1_TSS1_WIDTH                (2U)
#define GTMDI_TOM_WPC1_TSS1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_TSS1_SHIFT)) & GTMDI_TOM_WPC1_TSS1_MASK)

#define GTMDI_TOM_WPC1_POL1_MASK                 (0x80000000U)
#define GTMDI_TOM_WPC1_POL1_SHIFT                (31U)
#define GTMDI_TOM_WPC1_POL1_WIDTH                (1U)
#define GTMDI_TOM_WPC1_POL1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC1_POL1_SHIFT)) & GTMDI_TOM_WPC1_POL1_MASK)
/*! @} */

/*! @name TOM_WPC2 - TOM Watchpoint Control 2 */
/*! @{ */

#define GTMDI_TOM_WPC2_SEN2_MASK                 (0x1U)
#define GTMDI_TOM_WPC2_SEN2_SHIFT                (0U)
#define GTMDI_TOM_WPC2_SEN2_WIDTH                (1U)
#define GTMDI_TOM_WPC2_SEN2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC2_SEN2_SHIFT)) & GTMDI_TOM_WPC2_SEN2_MASK)

#define GTMDI_TOM_WPC2_TEN2_MASK                 (0x2U)
#define GTMDI_TOM_WPC2_TEN2_SHIFT                (1U)
#define GTMDI_TOM_WPC2_TEN2_WIDTH                (1U)
#define GTMDI_TOM_WPC2_TEN2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC2_TEN2_SHIFT)) & GTMDI_TOM_WPC2_TEN2_MASK)

#define GTMDI_TOM_WPC2_STSEL2_MASK               (0x30U)
#define GTMDI_TOM_WPC2_STSEL2_SHIFT              (4U)
#define GTMDI_TOM_WPC2_STSEL2_WIDTH              (2U)
#define GTMDI_TOM_WPC2_STSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC2_STSEL2_SHIFT)) & GTMDI_TOM_WPC2_STSEL2_MASK)

#define GTMDI_TOM_WPC2_WTSEL2_MASK               (0x7000U)
#define GTMDI_TOM_WPC2_WTSEL2_SHIFT              (12U)
#define GTMDI_TOM_WPC2_WTSEL2_WIDTH              (3U)
#define GTMDI_TOM_WPC2_WTSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC2_WTSEL2_SHIFT)) & GTMDI_TOM_WPC2_WTSEL2_MASK)

#define GTMDI_TOM_WPC2_SEN1_MASK                 (0x10000U)
#define GTMDI_TOM_WPC2_SEN1_SHIFT                (16U)
#define GTMDI_TOM_WPC2_SEN1_WIDTH                (1U)
#define GTMDI_TOM_WPC2_SEN1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC2_SEN1_SHIFT)) & GTMDI_TOM_WPC2_SEN1_MASK)

#define GTMDI_TOM_WPC2_TEN1_MASK                 (0x20000U)
#define GTMDI_TOM_WPC2_TEN1_SHIFT                (17U)
#define GTMDI_TOM_WPC2_TEN1_WIDTH                (1U)
#define GTMDI_TOM_WPC2_TEN1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC2_TEN1_SHIFT)) & GTMDI_TOM_WPC2_TEN1_MASK)

#define GTMDI_TOM_WPC2_STSEL1_MASK               (0x300000U)
#define GTMDI_TOM_WPC2_STSEL1_SHIFT              (20U)
#define GTMDI_TOM_WPC2_STSEL1_WIDTH              (2U)
#define GTMDI_TOM_WPC2_STSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC2_STSEL1_SHIFT)) & GTMDI_TOM_WPC2_STSEL1_MASK)

#define GTMDI_TOM_WPC2_WTSEL1_MASK               (0x70000000U)
#define GTMDI_TOM_WPC2_WTSEL1_SHIFT              (28U)
#define GTMDI_TOM_WPC2_WTSEL1_WIDTH              (3U)
#define GTMDI_TOM_WPC2_WTSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_TOM_WPC2_WTSEL1_SHIFT)) & GTMDI_TOM_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name ATOM_WPC1 - ATOM Watchpoint Control 1 */
/*! @{ */

#define GTMDI_ATOM_WPC1_CHSEL2_MASK              (0x7U)
#define GTMDI_ATOM_WPC1_CHSEL2_SHIFT             (0U)
#define GTMDI_ATOM_WPC1_CHSEL2_WIDTH             (3U)
#define GTMDI_ATOM_WPC1_CHSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_CHSEL2_SHIFT)) & GTMDI_ATOM_WPC1_CHSEL2_MASK)

#define GTMDI_ATOM_WPC1_WMC2_MASK                (0x40U)
#define GTMDI_ATOM_WPC1_WMC2_SHIFT               (6U)
#define GTMDI_ATOM_WPC1_WMC2_WIDTH               (1U)
#define GTMDI_ATOM_WPC1_WMC2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_WMC2_SHIFT)) & GTMDI_ATOM_WPC1_WMC2_MASK)

#define GTMDI_ATOM_WPC1_HEN2_MASK                (0x80U)
#define GTMDI_ATOM_WPC1_HEN2_SHIFT               (7U)
#define GTMDI_ATOM_WPC1_HEN2_WIDTH               (1U)
#define GTMDI_ATOM_WPC1_HEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_HEN2_SHIFT)) & GTMDI_ATOM_WPC1_HEN2_MASK)

#define GTMDI_ATOM_WPC1_SSEL2_MASK               (0xF00U)
#define GTMDI_ATOM_WPC1_SSEL2_SHIFT              (8U)
#define GTMDI_ATOM_WPC1_SSEL2_WIDTH              (4U)
#define GTMDI_ATOM_WPC1_SSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_SSEL2_SHIFT)) & GTMDI_ATOM_WPC1_SSEL2_MASK)

#define GTMDI_ATOM_WPC1_TSS2_MASK                (0x3000U)
#define GTMDI_ATOM_WPC1_TSS2_SHIFT               (12U)
#define GTMDI_ATOM_WPC1_TSS2_WIDTH               (2U)
#define GTMDI_ATOM_WPC1_TSS2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_TSS2_SHIFT)) & GTMDI_ATOM_WPC1_TSS2_MASK)

#define GTMDI_ATOM_WPC1_POL2_MASK                (0x8000U)
#define GTMDI_ATOM_WPC1_POL2_SHIFT               (15U)
#define GTMDI_ATOM_WPC1_POL2_WIDTH               (1U)
#define GTMDI_ATOM_WPC1_POL2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_POL2_SHIFT)) & GTMDI_ATOM_WPC1_POL2_MASK)

#define GTMDI_ATOM_WPC1_CHSEL1_MASK              (0x70000U)
#define GTMDI_ATOM_WPC1_CHSEL1_SHIFT             (16U)
#define GTMDI_ATOM_WPC1_CHSEL1_WIDTH             (3U)
#define GTMDI_ATOM_WPC1_CHSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_CHSEL1_SHIFT)) & GTMDI_ATOM_WPC1_CHSEL1_MASK)

#define GTMDI_ATOM_WPC1_WMC1_MASK                (0x400000U)
#define GTMDI_ATOM_WPC1_WMC1_SHIFT               (22U)
#define GTMDI_ATOM_WPC1_WMC1_WIDTH               (1U)
#define GTMDI_ATOM_WPC1_WMC1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_WMC1_SHIFT)) & GTMDI_ATOM_WPC1_WMC1_MASK)

#define GTMDI_ATOM_WPC1_HEN1_MASK                (0x800000U)
#define GTMDI_ATOM_WPC1_HEN1_SHIFT               (23U)
#define GTMDI_ATOM_WPC1_HEN1_WIDTH               (1U)
#define GTMDI_ATOM_WPC1_HEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_HEN1_SHIFT)) & GTMDI_ATOM_WPC1_HEN1_MASK)

#define GTMDI_ATOM_WPC1_SSEL1_MASK               (0xF000000U)
#define GTMDI_ATOM_WPC1_SSEL1_SHIFT              (24U)
#define GTMDI_ATOM_WPC1_SSEL1_WIDTH              (4U)
#define GTMDI_ATOM_WPC1_SSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_SSEL1_SHIFT)) & GTMDI_ATOM_WPC1_SSEL1_MASK)

#define GTMDI_ATOM_WPC1_TSS1_MASK                (0x30000000U)
#define GTMDI_ATOM_WPC1_TSS1_SHIFT               (28U)
#define GTMDI_ATOM_WPC1_TSS1_WIDTH               (2U)
#define GTMDI_ATOM_WPC1_TSS1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_TSS1_SHIFT)) & GTMDI_ATOM_WPC1_TSS1_MASK)

#define GTMDI_ATOM_WPC1_POL1_MASK                (0x80000000U)
#define GTMDI_ATOM_WPC1_POL1_SHIFT               (31U)
#define GTMDI_ATOM_WPC1_POL1_WIDTH               (1U)
#define GTMDI_ATOM_WPC1_POL1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC1_POL1_SHIFT)) & GTMDI_ATOM_WPC1_POL1_MASK)
/*! @} */

/*! @name ATOM_WPC2 - ATOM Watchpoint Control 2 */
/*! @{ */

#define GTMDI_ATOM_WPC2_SEN2_MASK                (0x1U)
#define GTMDI_ATOM_WPC2_SEN2_SHIFT               (0U)
#define GTMDI_ATOM_WPC2_SEN2_WIDTH               (1U)
#define GTMDI_ATOM_WPC2_SEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC2_SEN2_SHIFT)) & GTMDI_ATOM_WPC2_SEN2_MASK)

#define GTMDI_ATOM_WPC2_TEN2_MASK                (0x2U)
#define GTMDI_ATOM_WPC2_TEN2_SHIFT               (1U)
#define GTMDI_ATOM_WPC2_TEN2_WIDTH               (1U)
#define GTMDI_ATOM_WPC2_TEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC2_TEN2_SHIFT)) & GTMDI_ATOM_WPC2_TEN2_MASK)

#define GTMDI_ATOM_WPC2_STSEL2_MASK              (0x30U)
#define GTMDI_ATOM_WPC2_STSEL2_SHIFT             (4U)
#define GTMDI_ATOM_WPC2_STSEL2_WIDTH             (2U)
#define GTMDI_ATOM_WPC2_STSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC2_STSEL2_SHIFT)) & GTMDI_ATOM_WPC2_STSEL2_MASK)

#define GTMDI_ATOM_WPC2_WTSEL2_MASK              (0x7000U)
#define GTMDI_ATOM_WPC2_WTSEL2_SHIFT             (12U)
#define GTMDI_ATOM_WPC2_WTSEL2_WIDTH             (3U)
#define GTMDI_ATOM_WPC2_WTSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC2_WTSEL2_SHIFT)) & GTMDI_ATOM_WPC2_WTSEL2_MASK)

#define GTMDI_ATOM_WPC2_SEN1_MASK                (0x10000U)
#define GTMDI_ATOM_WPC2_SEN1_SHIFT               (16U)
#define GTMDI_ATOM_WPC2_SEN1_WIDTH               (1U)
#define GTMDI_ATOM_WPC2_SEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC2_SEN1_SHIFT)) & GTMDI_ATOM_WPC2_SEN1_MASK)

#define GTMDI_ATOM_WPC2_TEN1_MASK                (0x20000U)
#define GTMDI_ATOM_WPC2_TEN1_SHIFT               (17U)
#define GTMDI_ATOM_WPC2_TEN1_WIDTH               (1U)
#define GTMDI_ATOM_WPC2_TEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC2_TEN1_SHIFT)) & GTMDI_ATOM_WPC2_TEN1_MASK)

#define GTMDI_ATOM_WPC2_STSEL1_MASK              (0x300000U)
#define GTMDI_ATOM_WPC2_STSEL1_SHIFT             (20U)
#define GTMDI_ATOM_WPC2_STSEL1_WIDTH             (2U)
#define GTMDI_ATOM_WPC2_STSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC2_STSEL1_SHIFT)) & GTMDI_ATOM_WPC2_STSEL1_MASK)

#define GTMDI_ATOM_WPC2_WTSEL1_MASK              (0x70000000U)
#define GTMDI_ATOM_WPC2_WTSEL1_SHIFT             (28U)
#define GTMDI_ATOM_WPC2_WTSEL1_WIDTH             (3U)
#define GTMDI_ATOM_WPC2_WTSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_ATOM_WPC2_WTSEL1_SHIFT)) & GTMDI_ATOM_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name SPEA_WPC1 - SPEA Watchpoint Control 1 */
/*! @{ */

#define GTMDI_SPEA_WPC1_HEN2_MASK                (0x2U)
#define GTMDI_SPEA_WPC1_HEN2_SHIFT               (1U)
#define GTMDI_SPEA_WPC1_HEN2_WIDTH               (1U)
#define GTMDI_SPEA_WPC1_HEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC1_HEN2_SHIFT)) & GTMDI_SPEA_WPC1_HEN2_MASK)

#define GTMDI_SPEA_WPC1_TSS2_MASK                (0x30U)
#define GTMDI_SPEA_WPC1_TSS2_SHIFT               (4U)
#define GTMDI_SPEA_WPC1_TSS2_WIDTH               (2U)
#define GTMDI_SPEA_WPC1_TSS2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC1_TSS2_SHIFT)) & GTMDI_SPEA_WPC1_TSS2_MASK)

#define GTMDI_SPEA_WPC1_WMC2_MASK                (0x40U)
#define GTMDI_SPEA_WPC1_WMC2_SHIFT               (6U)
#define GTMDI_SPEA_WPC1_WMC2_WIDTH               (1U)
#define GTMDI_SPEA_WPC1_WMC2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC1_WMC2_SHIFT)) & GTMDI_SPEA_WPC1_WMC2_MASK)

#define GTMDI_SPEA_WPC1_HEN1_MASK                (0x20000U)
#define GTMDI_SPEA_WPC1_HEN1_SHIFT               (17U)
#define GTMDI_SPEA_WPC1_HEN1_WIDTH               (1U)
#define GTMDI_SPEA_WPC1_HEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC1_HEN1_SHIFT)) & GTMDI_SPEA_WPC1_HEN1_MASK)

#define GTMDI_SPEA_WPC1_TSS1_MASK                (0x300000U)
#define GTMDI_SPEA_WPC1_TSS1_SHIFT               (20U)
#define GTMDI_SPEA_WPC1_TSS1_WIDTH               (2U)
#define GTMDI_SPEA_WPC1_TSS1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC1_TSS1_SHIFT)) & GTMDI_SPEA_WPC1_TSS1_MASK)

#define GTMDI_SPEA_WPC1_WMC1_MASK                (0x400000U)
#define GTMDI_SPEA_WPC1_WMC1_SHIFT               (22U)
#define GTMDI_SPEA_WPC1_WMC1_WIDTH               (1U)
#define GTMDI_SPEA_WPC1_WMC1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC1_WMC1_SHIFT)) & GTMDI_SPEA_WPC1_WMC1_MASK)

#define GTMDI_SPEA_WPC1_SSEL_MASK                (0x7000000U)
#define GTMDI_SPEA_WPC1_SSEL_SHIFT               (24U)
#define GTMDI_SPEA_WPC1_SSEL_WIDTH               (3U)
#define GTMDI_SPEA_WPC1_SSEL(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC1_SSEL_SHIFT)) & GTMDI_SPEA_WPC1_SSEL_MASK)
/*! @} */

/*! @name SPEA_WPC2 - SPEA Watchpoint Control 2 */
/*! @{ */

#define GTMDI_SPEA_WPC2_SEN2_MASK                (0x1U)
#define GTMDI_SPEA_WPC2_SEN2_SHIFT               (0U)
#define GTMDI_SPEA_WPC2_SEN2_WIDTH               (1U)
#define GTMDI_SPEA_WPC2_SEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC2_SEN2_SHIFT)) & GTMDI_SPEA_WPC2_SEN2_MASK)

#define GTMDI_SPEA_WPC2_TEN2_MASK                (0x2U)
#define GTMDI_SPEA_WPC2_TEN2_SHIFT               (1U)
#define GTMDI_SPEA_WPC2_TEN2_WIDTH               (1U)
#define GTMDI_SPEA_WPC2_TEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC2_TEN2_SHIFT)) & GTMDI_SPEA_WPC2_TEN2_MASK)

#define GTMDI_SPEA_WPC2_STSEL2_MASK              (0x30U)
#define GTMDI_SPEA_WPC2_STSEL2_SHIFT             (4U)
#define GTMDI_SPEA_WPC2_STSEL2_WIDTH             (2U)
#define GTMDI_SPEA_WPC2_STSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC2_STSEL2_SHIFT)) & GTMDI_SPEA_WPC2_STSEL2_MASK)

#define GTMDI_SPEA_WPC2_WTSEL2_MASK              (0x7000U)
#define GTMDI_SPEA_WPC2_WTSEL2_SHIFT             (12U)
#define GTMDI_SPEA_WPC2_WTSEL2_WIDTH             (3U)
#define GTMDI_SPEA_WPC2_WTSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC2_WTSEL2_SHIFT)) & GTMDI_SPEA_WPC2_WTSEL2_MASK)

#define GTMDI_SPEA_WPC2_SEN1_MASK                (0x10000U)
#define GTMDI_SPEA_WPC2_SEN1_SHIFT               (16U)
#define GTMDI_SPEA_WPC2_SEN1_WIDTH               (1U)
#define GTMDI_SPEA_WPC2_SEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC2_SEN1_SHIFT)) & GTMDI_SPEA_WPC2_SEN1_MASK)

#define GTMDI_SPEA_WPC2_TEN1_MASK                (0x20000U)
#define GTMDI_SPEA_WPC2_TEN1_SHIFT               (17U)
#define GTMDI_SPEA_WPC2_TEN1_WIDTH               (1U)
#define GTMDI_SPEA_WPC2_TEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC2_TEN1_SHIFT)) & GTMDI_SPEA_WPC2_TEN1_MASK)

#define GTMDI_SPEA_WPC2_STSEL1_MASK              (0x300000U)
#define GTMDI_SPEA_WPC2_STSEL1_SHIFT             (20U)
#define GTMDI_SPEA_WPC2_STSEL1_WIDTH             (2U)
#define GTMDI_SPEA_WPC2_STSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC2_STSEL1_SHIFT)) & GTMDI_SPEA_WPC2_STSEL1_MASK)

#define GTMDI_SPEA_WPC2_WTSEL1_MASK              (0x70000000U)
#define GTMDI_SPEA_WPC2_WTSEL1_SHIFT             (28U)
#define GTMDI_SPEA_WPC2_WTSEL1_WIDTH             (3U)
#define GTMDI_SPEA_WPC2_WTSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEA_WPC2_WTSEL1_SHIFT)) & GTMDI_SPEA_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name SPEB_WPC1 - SPEB Watchpoint Control 1 */
/*! @{ */

#define GTMDI_SPEB_WPC1_HEN2_MASK                (0x2U)
#define GTMDI_SPEB_WPC1_HEN2_SHIFT               (1U)
#define GTMDI_SPEB_WPC1_HEN2_WIDTH               (1U)
#define GTMDI_SPEB_WPC1_HEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC1_HEN2_SHIFT)) & GTMDI_SPEB_WPC1_HEN2_MASK)

#define GTMDI_SPEB_WPC1_TSS2_MASK                (0x30U)
#define GTMDI_SPEB_WPC1_TSS2_SHIFT               (4U)
#define GTMDI_SPEB_WPC1_TSS2_WIDTH               (2U)
#define GTMDI_SPEB_WPC1_TSS2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC1_TSS2_SHIFT)) & GTMDI_SPEB_WPC1_TSS2_MASK)

#define GTMDI_SPEB_WPC1_WMC2_MASK                (0x40U)
#define GTMDI_SPEB_WPC1_WMC2_SHIFT               (6U)
#define GTMDI_SPEB_WPC1_WMC2_WIDTH               (1U)
#define GTMDI_SPEB_WPC1_WMC2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC1_WMC2_SHIFT)) & GTMDI_SPEB_WPC1_WMC2_MASK)

#define GTMDI_SPEB_WPC1_HEN1_MASK                (0x20000U)
#define GTMDI_SPEB_WPC1_HEN1_SHIFT               (17U)
#define GTMDI_SPEB_WPC1_HEN1_WIDTH               (1U)
#define GTMDI_SPEB_WPC1_HEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC1_HEN1_SHIFT)) & GTMDI_SPEB_WPC1_HEN1_MASK)

#define GTMDI_SPEB_WPC1_TSS1_MASK                (0x300000U)
#define GTMDI_SPEB_WPC1_TSS1_SHIFT               (20U)
#define GTMDI_SPEB_WPC1_TSS1_WIDTH               (2U)
#define GTMDI_SPEB_WPC1_TSS1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC1_TSS1_SHIFT)) & GTMDI_SPEB_WPC1_TSS1_MASK)

#define GTMDI_SPEB_WPC1_WMC1_MASK                (0x400000U)
#define GTMDI_SPEB_WPC1_WMC1_SHIFT               (22U)
#define GTMDI_SPEB_WPC1_WMC1_WIDTH               (1U)
#define GTMDI_SPEB_WPC1_WMC1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC1_WMC1_SHIFT)) & GTMDI_SPEB_WPC1_WMC1_MASK)

#define GTMDI_SPEB_WPC1_SSEL_MASK                (0x7000000U)
#define GTMDI_SPEB_WPC1_SSEL_SHIFT               (24U)
#define GTMDI_SPEB_WPC1_SSEL_WIDTH               (3U)
#define GTMDI_SPEB_WPC1_SSEL(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC1_SSEL_SHIFT)) & GTMDI_SPEB_WPC1_SSEL_MASK)
/*! @} */

/*! @name SPEB_WPC2 - SPEB Watchpoint Control 2 */
/*! @{ */

#define GTMDI_SPEB_WPC2_SEN2_MASK                (0x1U)
#define GTMDI_SPEB_WPC2_SEN2_SHIFT               (0U)
#define GTMDI_SPEB_WPC2_SEN2_WIDTH               (1U)
#define GTMDI_SPEB_WPC2_SEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC2_SEN2_SHIFT)) & GTMDI_SPEB_WPC2_SEN2_MASK)

#define GTMDI_SPEB_WPC2_TEN2_MASK                (0x2U)
#define GTMDI_SPEB_WPC2_TEN2_SHIFT               (1U)
#define GTMDI_SPEB_WPC2_TEN2_WIDTH               (1U)
#define GTMDI_SPEB_WPC2_TEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC2_TEN2_SHIFT)) & GTMDI_SPEB_WPC2_TEN2_MASK)

#define GTMDI_SPEB_WPC2_STSEL2_MASK              (0x30U)
#define GTMDI_SPEB_WPC2_STSEL2_SHIFT             (4U)
#define GTMDI_SPEB_WPC2_STSEL2_WIDTH             (2U)
#define GTMDI_SPEB_WPC2_STSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC2_STSEL2_SHIFT)) & GTMDI_SPEB_WPC2_STSEL2_MASK)

#define GTMDI_SPEB_WPC2_WTSEL2_MASK              (0x7000U)
#define GTMDI_SPEB_WPC2_WTSEL2_SHIFT             (12U)
#define GTMDI_SPEB_WPC2_WTSEL2_WIDTH             (3U)
#define GTMDI_SPEB_WPC2_WTSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC2_WTSEL2_SHIFT)) & GTMDI_SPEB_WPC2_WTSEL2_MASK)

#define GTMDI_SPEB_WPC2_SEN1_MASK                (0x10000U)
#define GTMDI_SPEB_WPC2_SEN1_SHIFT               (16U)
#define GTMDI_SPEB_WPC2_SEN1_WIDTH               (1U)
#define GTMDI_SPEB_WPC2_SEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC2_SEN1_SHIFT)) & GTMDI_SPEB_WPC2_SEN1_MASK)

#define GTMDI_SPEB_WPC2_TEN1_MASK                (0x20000U)
#define GTMDI_SPEB_WPC2_TEN1_SHIFT               (17U)
#define GTMDI_SPEB_WPC2_TEN1_WIDTH               (1U)
#define GTMDI_SPEB_WPC2_TEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC2_TEN1_SHIFT)) & GTMDI_SPEB_WPC2_TEN1_MASK)

#define GTMDI_SPEB_WPC2_STSEL1_MASK              (0x300000U)
#define GTMDI_SPEB_WPC2_STSEL1_SHIFT             (20U)
#define GTMDI_SPEB_WPC2_STSEL1_WIDTH             (2U)
#define GTMDI_SPEB_WPC2_STSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC2_STSEL1_SHIFT)) & GTMDI_SPEB_WPC2_STSEL1_MASK)

#define GTMDI_SPEB_WPC2_WTSEL1_MASK              (0x70000000U)
#define GTMDI_SPEB_WPC2_WTSEL1_SHIFT             (28U)
#define GTMDI_SPEB_WPC2_WTSEL1_WIDTH             (3U)
#define GTMDI_SPEB_WPC2_WTSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_SPEB_WPC2_WTSEL1_SHIFT)) & GTMDI_SPEB_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name DPLL_WPC1 - DPLL Watchpoint Control 1 */
/*! @{ */

#define GTMDI_DPLL_WPC1_HEN2_MASK                (0x2U)
#define GTMDI_DPLL_WPC1_HEN2_SHIFT               (1U)
#define GTMDI_DPLL_WPC1_HEN2_WIDTH               (1U)
#define GTMDI_DPLL_WPC1_HEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC1_HEN2_SHIFT)) & GTMDI_DPLL_WPC1_HEN2_MASK)

#define GTMDI_DPLL_WPC1_WMC2_MASK                (0x40U)
#define GTMDI_DPLL_WPC1_WMC2_SHIFT               (6U)
#define GTMDI_DPLL_WPC1_WMC2_WIDTH               (1U)
#define GTMDI_DPLL_WPC1_WMC2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC1_WMC2_SHIFT)) & GTMDI_DPLL_WPC1_WMC2_MASK)

#define GTMDI_DPLL_WPC1_TSEL2A_MASK              (0x300U)
#define GTMDI_DPLL_WPC1_TSEL2A_SHIFT             (8U)
#define GTMDI_DPLL_WPC1_TSEL2A_WIDTH             (2U)
#define GTMDI_DPLL_WPC1_TSEL2A(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC1_TSEL2A_SHIFT)) & GTMDI_DPLL_WPC1_TSEL2A_MASK)

#define GTMDI_DPLL_WPC1_TSEL2B_MASK              (0x3000U)
#define GTMDI_DPLL_WPC1_TSEL2B_SHIFT             (12U)
#define GTMDI_DPLL_WPC1_TSEL2B_WIDTH             (2U)
#define GTMDI_DPLL_WPC1_TSEL2B(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC1_TSEL2B_SHIFT)) & GTMDI_DPLL_WPC1_TSEL2B_MASK)

#define GTMDI_DPLL_WPC1_HEN1_MASK                (0x20000U)
#define GTMDI_DPLL_WPC1_HEN1_SHIFT               (17U)
#define GTMDI_DPLL_WPC1_HEN1_WIDTH               (1U)
#define GTMDI_DPLL_WPC1_HEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC1_HEN1_SHIFT)) & GTMDI_DPLL_WPC1_HEN1_MASK)

#define GTMDI_DPLL_WPC1_TSS1_MASK                (0x300000U)
#define GTMDI_DPLL_WPC1_TSS1_SHIFT               (20U)
#define GTMDI_DPLL_WPC1_TSS1_WIDTH               (2U)
#define GTMDI_DPLL_WPC1_TSS1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC1_TSS1_SHIFT)) & GTMDI_DPLL_WPC1_TSS1_MASK)

#define GTMDI_DPLL_WPC1_WMC1_MASK                (0x400000U)
#define GTMDI_DPLL_WPC1_WMC1_SHIFT               (22U)
#define GTMDI_DPLL_WPC1_WMC1_WIDTH               (1U)
#define GTMDI_DPLL_WPC1_WMC1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC1_WMC1_SHIFT)) & GTMDI_DPLL_WPC1_WMC1_MASK)

#define GTMDI_DPLL_WPC1_TSEL1_MASK               (0x3000000U)
#define GTMDI_DPLL_WPC1_TSEL1_SHIFT              (24U)
#define GTMDI_DPLL_WPC1_TSEL1_WIDTH              (2U)
#define GTMDI_DPLL_WPC1_TSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC1_TSEL1_SHIFT)) & GTMDI_DPLL_WPC1_TSEL1_MASK)
/*! @} */

/*! @name DPLL_WPC2 - DPLL Watchpoint Control 2 */
/*! @{ */

#define GTMDI_DPLL_WPC2_SEN2_MASK                (0x1U)
#define GTMDI_DPLL_WPC2_SEN2_SHIFT               (0U)
#define GTMDI_DPLL_WPC2_SEN2_WIDTH               (1U)
#define GTMDI_DPLL_WPC2_SEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC2_SEN2_SHIFT)) & GTMDI_DPLL_WPC2_SEN2_MASK)

#define GTMDI_DPLL_WPC2_TEN2_MASK                (0x2U)
#define GTMDI_DPLL_WPC2_TEN2_SHIFT               (1U)
#define GTMDI_DPLL_WPC2_TEN2_WIDTH               (1U)
#define GTMDI_DPLL_WPC2_TEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC2_TEN2_SHIFT)) & GTMDI_DPLL_WPC2_TEN2_MASK)

#define GTMDI_DPLL_WPC2_STSEL2_MASK              (0x30U)
#define GTMDI_DPLL_WPC2_STSEL2_SHIFT             (4U)
#define GTMDI_DPLL_WPC2_STSEL2_WIDTH             (2U)
#define GTMDI_DPLL_WPC2_STSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC2_STSEL2_SHIFT)) & GTMDI_DPLL_WPC2_STSEL2_MASK)

#define GTMDI_DPLL_WPC2_WTSEL2_MASK              (0x7000U)
#define GTMDI_DPLL_WPC2_WTSEL2_SHIFT             (12U)
#define GTMDI_DPLL_WPC2_WTSEL2_WIDTH             (3U)
#define GTMDI_DPLL_WPC2_WTSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC2_WTSEL2_SHIFT)) & GTMDI_DPLL_WPC2_WTSEL2_MASK)

#define GTMDI_DPLL_WPC2_SEN1_MASK                (0x10000U)
#define GTMDI_DPLL_WPC2_SEN1_SHIFT               (16U)
#define GTMDI_DPLL_WPC2_SEN1_WIDTH               (1U)
#define GTMDI_DPLL_WPC2_SEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC2_SEN1_SHIFT)) & GTMDI_DPLL_WPC2_SEN1_MASK)

#define GTMDI_DPLL_WPC2_TEN1_MASK                (0x20000U)
#define GTMDI_DPLL_WPC2_TEN1_SHIFT               (17U)
#define GTMDI_DPLL_WPC2_TEN1_WIDTH               (1U)
#define GTMDI_DPLL_WPC2_TEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC2_TEN1_SHIFT)) & GTMDI_DPLL_WPC2_TEN1_MASK)

#define GTMDI_DPLL_WPC2_STSEL1_MASK              (0x300000U)
#define GTMDI_DPLL_WPC2_STSEL1_SHIFT             (20U)
#define GTMDI_DPLL_WPC2_STSEL1_WIDTH             (2U)
#define GTMDI_DPLL_WPC2_STSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC2_STSEL1_SHIFT)) & GTMDI_DPLL_WPC2_STSEL1_MASK)

#define GTMDI_DPLL_WPC2_WTSEL1_MASK              (0x70000000U)
#define GTMDI_DPLL_WPC2_WTSEL1_SHIFT             (28U)
#define GTMDI_DPLL_WPC2_WTSEL1_WIDTH             (3U)
#define GTMDI_DPLL_WPC2_WTSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC2_WTSEL1_SHIFT)) & GTMDI_DPLL_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name DPLL_WPC3 - DPLL Watchpoint Control 3 */
/*! @{ */

#define GTMDI_DPLL_WPC3_RAM_DATA_MASK            (0xFFFFFFU)
#define GTMDI_DPLL_WPC3_RAM_DATA_SHIFT           (0U)
#define GTMDI_DPLL_WPC3_RAM_DATA_WIDTH           (24U)
#define GTMDI_DPLL_WPC3_RAM_DATA(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC3_RAM_DATA_SHIFT)) & GTMDI_DPLL_WPC3_RAM_DATA_MASK)

#define GTMDI_DPLL_WPC3_DMASK_MASK               (0x10000000U)
#define GTMDI_DPLL_WPC3_DMASK_SHIFT              (28U)
#define GTMDI_DPLL_WPC3_DMASK_WIDTH              (1U)
#define GTMDI_DPLL_WPC3_DMASK(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC3_DMASK_SHIFT)) & GTMDI_DPLL_WPC3_DMASK_MASK)
/*! @} */

/*! @name DPLL_WPC4 - DPLL Watchpoint Control 4 */
/*! @{ */

#define GTMDI_DPLL_WPC4_RAM_ADDR_MASK_MASK       (0xFFFU)
#define GTMDI_DPLL_WPC4_RAM_ADDR_MASK_SHIFT      (0U)
#define GTMDI_DPLL_WPC4_RAM_ADDR_MASK_WIDTH      (12U)
#define GTMDI_DPLL_WPC4_RAM_ADDR_MASK(x)         (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC4_RAM_ADDR_MASK_SHIFT)) & GTMDI_DPLL_WPC4_RAM_ADDR_MASK_MASK)
/*! @} */

/*! @name DPLL_WPC5 - DPLL Watchpoint Control 5 */
/*! @{ */

#define GTMDI_DPLL_WPC5_RAM_ADDR_MASK            (0xFFFU)
#define GTMDI_DPLL_WPC5_RAM_ADDR_SHIFT           (0U)
#define GTMDI_DPLL_WPC5_RAM_ADDR_WIDTH           (12U)
#define GTMDI_DPLL_WPC5_RAM_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_WPC5_RAM_ADDR_SHIFT)) & GTMDI_DPLL_WPC5_RAM_ADDR_MASK)
/*! @} */

/*! @name DPLL_DTC - DPLL Data Trace Control */
/*! @{ */

#define GTMDI_DPLL_DTC_SEN_MASK                  (0x1U)
#define GTMDI_DPLL_DTC_SEN_SHIFT                 (0U)
#define GTMDI_DPLL_DTC_SEN_WIDTH                 (1U)
#define GTMDI_DPLL_DTC_SEN(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_DTC_SEN_SHIFT)) & GTMDI_DPLL_DTC_SEN_MASK)

#define GTMDI_DPLL_DTC_STSEL_MASK                (0x30U)
#define GTMDI_DPLL_DTC_STSEL_SHIFT               (4U)
#define GTMDI_DPLL_DTC_STSEL_WIDTH               (2U)
#define GTMDI_DPLL_DTC_STSEL(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_DTC_STSEL_SHIFT)) & GTMDI_DPLL_DTC_STSEL_MASK)

#define GTMDI_DPLL_DTC_DMC_MASK                  (0x40U)
#define GTMDI_DPLL_DTC_DMC_SHIFT                 (6U)
#define GTMDI_DPLL_DTC_DMC_WIDTH                 (1U)
#define GTMDI_DPLL_DTC_DMC(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_DTC_DMC_SHIFT)) & GTMDI_DPLL_DTC_DMC_MASK)

#define GTMDI_DPLL_DTC_RAMSEL_MASK               (0x300U)
#define GTMDI_DPLL_DTC_RAMSEL_SHIFT              (8U)
#define GTMDI_DPLL_DTC_RAMSEL_WIDTH              (2U)
#define GTMDI_DPLL_DTC_RAMSEL(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_DTC_RAMSEL_SHIFT)) & GTMDI_DPLL_DTC_RAMSEL_MASK)

#define GTMDI_DPLL_DTC_RWC_MASK                  (0x3000U)
#define GTMDI_DPLL_DTC_RWC_SHIFT                 (12U)
#define GTMDI_DPLL_DTC_RWC_WIDTH                 (2U)
#define GTMDI_DPLL_DTC_RWC(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_DPLL_DTC_RWC_SHIFT)) & GTMDI_DPLL_DTC_RWC_MASK)
/*! @} */

/*! @name ARU_WPC1 - ARU Watchpoint Control 1 */
/*! @{ */

#define GTMDI_ARU_WPC1_WMC2_MASK                 (0x40U)
#define GTMDI_ARU_WPC1_WMC2_SHIFT                (6U)
#define GTMDI_ARU_WPC1_WMC2_WIDTH                (1U)
#define GTMDI_ARU_WPC1_WMC2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC1_WMC2_SHIFT)) & GTMDI_ARU_WPC1_WMC2_MASK)

#define GTMDI_ARU_WPC1_HEN2_MASK                 (0x80U)
#define GTMDI_ARU_WPC1_HEN2_SHIFT                (7U)
#define GTMDI_ARU_WPC1_HEN2_WIDTH                (1U)
#define GTMDI_ARU_WPC1_HEN2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC1_HEN2_SHIFT)) & GTMDI_ARU_WPC1_HEN2_MASK)

#define GTMDI_ARU_WPC1_TSS2_MASK                 (0x1000U)
#define GTMDI_ARU_WPC1_TSS2_SHIFT                (12U)
#define GTMDI_ARU_WPC1_TSS2_WIDTH                (1U)
#define GTMDI_ARU_WPC1_TSS2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC1_TSS2_SHIFT)) & GTMDI_ARU_WPC1_TSS2_MASK)

#define GTMDI_ARU_WPC1_WMC1_MASK                 (0x400000U)
#define GTMDI_ARU_WPC1_WMC1_SHIFT                (22U)
#define GTMDI_ARU_WPC1_WMC1_WIDTH                (1U)
#define GTMDI_ARU_WPC1_WMC1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC1_WMC1_SHIFT)) & GTMDI_ARU_WPC1_WMC1_MASK)

#define GTMDI_ARU_WPC1_HEN1_MASK                 (0x800000U)
#define GTMDI_ARU_WPC1_HEN1_SHIFT                (23U)
#define GTMDI_ARU_WPC1_HEN1_WIDTH                (1U)
#define GTMDI_ARU_WPC1_HEN1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC1_HEN1_SHIFT)) & GTMDI_ARU_WPC1_HEN1_MASK)

#define GTMDI_ARU_WPC1_TSS1_MASK                 (0x10000000U)
#define GTMDI_ARU_WPC1_TSS1_SHIFT                (28U)
#define GTMDI_ARU_WPC1_TSS1_WIDTH                (1U)
#define GTMDI_ARU_WPC1_TSS1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC1_TSS1_SHIFT)) & GTMDI_ARU_WPC1_TSS1_MASK)
/*! @} */

/*! @name ARU_WPC2 - ARU Watchpoint Control 2 */
/*! @{ */

#define GTMDI_ARU_WPC2_SEN2_MASK                 (0x1U)
#define GTMDI_ARU_WPC2_SEN2_SHIFT                (0U)
#define GTMDI_ARU_WPC2_SEN2_WIDTH                (1U)
#define GTMDI_ARU_WPC2_SEN2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC2_SEN2_SHIFT)) & GTMDI_ARU_WPC2_SEN2_MASK)

#define GTMDI_ARU_WPC2_TEN2_MASK                 (0x2U)
#define GTMDI_ARU_WPC2_TEN2_SHIFT                (1U)
#define GTMDI_ARU_WPC2_TEN2_WIDTH                (1U)
#define GTMDI_ARU_WPC2_TEN2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC2_TEN2_SHIFT)) & GTMDI_ARU_WPC2_TEN2_MASK)

#define GTMDI_ARU_WPC2_STSEL2_MASK               (0x30U)
#define GTMDI_ARU_WPC2_STSEL2_SHIFT              (4U)
#define GTMDI_ARU_WPC2_STSEL2_WIDTH              (2U)
#define GTMDI_ARU_WPC2_STSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC2_STSEL2_SHIFT)) & GTMDI_ARU_WPC2_STSEL2_MASK)

#define GTMDI_ARU_WPC2_WTSEL2_MASK               (0x7000U)
#define GTMDI_ARU_WPC2_WTSEL2_SHIFT              (12U)
#define GTMDI_ARU_WPC2_WTSEL2_WIDTH              (3U)
#define GTMDI_ARU_WPC2_WTSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC2_WTSEL2_SHIFT)) & GTMDI_ARU_WPC2_WTSEL2_MASK)

#define GTMDI_ARU_WPC2_SEN1_MASK                 (0x10000U)
#define GTMDI_ARU_WPC2_SEN1_SHIFT                (16U)
#define GTMDI_ARU_WPC2_SEN1_WIDTH                (1U)
#define GTMDI_ARU_WPC2_SEN1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC2_SEN1_SHIFT)) & GTMDI_ARU_WPC2_SEN1_MASK)

#define GTMDI_ARU_WPC2_TEN1_MASK                 (0x20000U)
#define GTMDI_ARU_WPC2_TEN1_SHIFT                (17U)
#define GTMDI_ARU_WPC2_TEN1_WIDTH                (1U)
#define GTMDI_ARU_WPC2_TEN1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC2_TEN1_SHIFT)) & GTMDI_ARU_WPC2_TEN1_MASK)

#define GTMDI_ARU_WPC2_STSEL1_MASK               (0x300000U)
#define GTMDI_ARU_WPC2_STSEL1_SHIFT              (20U)
#define GTMDI_ARU_WPC2_STSEL1_WIDTH              (2U)
#define GTMDI_ARU_WPC2_STSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC2_STSEL1_SHIFT)) & GTMDI_ARU_WPC2_STSEL1_MASK)

#define GTMDI_ARU_WPC2_WTSEL1_MASK               (0x70000000U)
#define GTMDI_ARU_WPC2_WTSEL1_SHIFT              (28U)
#define GTMDI_ARU_WPC2_WTSEL1_WIDTH              (3U)
#define GTMDI_ARU_WPC2_WTSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_WPC2_WTSEL1_SHIFT)) & GTMDI_ARU_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name ARU_D0H - ARU Watchpoint DATA0H */
/*! @{ */

#define GTMDI_ARU_D0H_DATA0H_MASK                (0x1FFFFFFFU)
#define GTMDI_ARU_D0H_DATA0H_SHIFT               (0U)
#define GTMDI_ARU_D0H_DATA0H_WIDTH               (29U)
#define GTMDI_ARU_D0H_DATA0H(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_D0H_DATA0H_SHIFT)) & GTMDI_ARU_D0H_DATA0H_MASK)
/*! @} */

/*! @name ARU_D0L - ARU Watchpoint DATA0L */
/*! @{ */

#define GTMDI_ARU_D0L_DATA0L_MASK                (0x1FFFFFFFU)
#define GTMDI_ARU_D0L_DATA0L_SHIFT               (0U)
#define GTMDI_ARU_D0L_DATA0L_WIDTH               (29U)
#define GTMDI_ARU_D0L_DATA0L(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_D0L_DATA0L_SHIFT)) & GTMDI_ARU_D0L_DATA0L_MASK)
/*! @} */

/*! @name ARU_D1H - ARU Watchpoint DATA1H */
/*! @{ */

#define GTMDI_ARU_D1H_DATA1H_MASK                (0x1FFFFFFFU)
#define GTMDI_ARU_D1H_DATA1H_SHIFT               (0U)
#define GTMDI_ARU_D1H_DATA1H_WIDTH               (29U)
#define GTMDI_ARU_D1H_DATA1H(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_D1H_DATA1H_SHIFT)) & GTMDI_ARU_D1H_DATA1H_MASK)
/*! @} */

/*! @name ARU_D1L - ARU Watchpoint ARUD1L */
/*! @{ */

#define GTMDI_ARU_D1L_DATA1L_MASK                (0x1FFFFFFFU)
#define GTMDI_ARU_D1L_DATA1L_SHIFT               (0U)
#define GTMDI_ARU_D1L_DATA1L_WIDTH               (29U)
#define GTMDI_ARU_D1L_DATA1L(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_D1L_DATA1L_SHIFT)) & GTMDI_ARU_D1L_DATA1L_MASK)
/*! @} */

/*! @name ARU_DTC - ARU Data Trace Control */
/*! @{ */

#define GTMDI_ARU_DTC_SEN2_MASK                  (0x1U)
#define GTMDI_ARU_DTC_SEN2_SHIFT                 (0U)
#define GTMDI_ARU_DTC_SEN2_WIDTH                 (1U)
#define GTMDI_ARU_DTC_SEN2(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_DTC_SEN2_SHIFT)) & GTMDI_ARU_DTC_SEN2_MASK)

#define GTMDI_ARU_DTC_DMC2_MASK                  (0x2U)
#define GTMDI_ARU_DTC_DMC2_SHIFT                 (1U)
#define GTMDI_ARU_DTC_DMC2_WIDTH                 (1U)
#define GTMDI_ARU_DTC_DMC2(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_DTC_DMC2_SHIFT)) & GTMDI_ARU_DTC_DMC2_MASK)

#define GTMDI_ARU_DTC_STSEL2_MASK                (0x30U)
#define GTMDI_ARU_DTC_STSEL2_SHIFT               (4U)
#define GTMDI_ARU_DTC_STSEL2_WIDTH               (2U)
#define GTMDI_ARU_DTC_STSEL2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_DTC_STSEL2_SHIFT)) & GTMDI_ARU_DTC_STSEL2_MASK)

#define GTMDI_ARU_DTC_SEN1_MASK                  (0x10000U)
#define GTMDI_ARU_DTC_SEN1_SHIFT                 (16U)
#define GTMDI_ARU_DTC_SEN1_WIDTH                 (1U)
#define GTMDI_ARU_DTC_SEN1(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_DTC_SEN1_SHIFT)) & GTMDI_ARU_DTC_SEN1_MASK)

#define GTMDI_ARU_DTC_DMC1_MASK                  (0x20000U)
#define GTMDI_ARU_DTC_DMC1_SHIFT                 (17U)
#define GTMDI_ARU_DTC_DMC1_WIDTH                 (1U)
#define GTMDI_ARU_DTC_DMC1(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_DTC_DMC1_SHIFT)) & GTMDI_ARU_DTC_DMC1_MASK)

#define GTMDI_ARU_DTC_STSEL1_MASK                (0x300000U)
#define GTMDI_ARU_DTC_STSEL1_SHIFT               (20U)
#define GTMDI_ARU_DTC_STSEL1_WIDTH               (2U)
#define GTMDI_ARU_DTC_STSEL1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_ARU_DTC_STSEL1_SHIFT)) & GTMDI_ARU_DTC_STSEL1_MASK)
/*! @} */

/*! @name MCS_HBC - MCS Hardware Breakpoint (HBP) Control */
/*! @{ */

#define GTMDI_MCS_HBC_MCS0BE_MASK                (0x1U)
#define GTMDI_MCS_HBC_MCS0BE_SHIFT               (0U)
#define GTMDI_MCS_HBC_MCS0BE_WIDTH               (1U)
#define GTMDI_MCS_HBC_MCS0BE(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HBC_MCS0BE_SHIFT)) & GTMDI_MCS_HBC_MCS0BE_MASK)

#define GTMDI_MCS_HBC_MCS1BE_MASK                (0x2U)
#define GTMDI_MCS_HBC_MCS1BE_SHIFT               (1U)
#define GTMDI_MCS_HBC_MCS1BE_WIDTH               (1U)
#define GTMDI_MCS_HBC_MCS1BE(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HBC_MCS1BE_SHIFT)) & GTMDI_MCS_HBC_MCS1BE_MASK)

#define GTMDI_MCS_HBC_MCS2BE_MASK                (0x4U)
#define GTMDI_MCS_HBC_MCS2BE_SHIFT               (2U)
#define GTMDI_MCS_HBC_MCS2BE_WIDTH               (1U)
#define GTMDI_MCS_HBC_MCS2BE(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HBC_MCS2BE_SHIFT)) & GTMDI_MCS_HBC_MCS2BE_MASK)

#define GTMDI_MCS_HBC_MCS3BE_MASK                (0x8U)
#define GTMDI_MCS_HBC_MCS3BE_SHIFT               (3U)
#define GTMDI_MCS_HBC_MCS3BE_WIDTH               (1U)
#define GTMDI_MCS_HBC_MCS3BE(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HBC_MCS3BE_SHIFT)) & GTMDI_MCS_HBC_MCS3BE_MASK)
/*! @} */

/*! @name MCS_HLT - MCS Halt Control */
/*! @{ */

#define GTMDI_MCS_HLT_MCS0HBP0ICLR_MASK          (0x1U)
#define GTMDI_MCS_HLT_MCS0HBP0ICLR_SHIFT         (0U)
#define GTMDI_MCS_HLT_MCS0HBP0ICLR_WIDTH         (1U)
#define GTMDI_MCS_HLT_MCS0HBP0ICLR(x)            (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS0HBP0ICLR_SHIFT)) & GTMDI_MCS_HLT_MCS0HBP0ICLR_MASK)

#define GTMDI_MCS_HLT_MCS0HBP1ICLR_MASK          (0x2U)
#define GTMDI_MCS_HLT_MCS0HBP1ICLR_SHIFT         (1U)
#define GTMDI_MCS_HLT_MCS0HBP1ICLR_WIDTH         (1U)
#define GTMDI_MCS_HLT_MCS0HBP1ICLR(x)            (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS0HBP1ICLR_SHIFT)) & GTMDI_MCS_HLT_MCS0HBP1ICLR_MASK)

#define GTMDI_MCS_HLT_MCS1HBP0ICLR_MASK          (0x4U)
#define GTMDI_MCS_HLT_MCS1HBP0ICLR_SHIFT         (2U)
#define GTMDI_MCS_HLT_MCS1HBP0ICLR_WIDTH         (1U)
#define GTMDI_MCS_HLT_MCS1HBP0ICLR(x)            (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS1HBP0ICLR_SHIFT)) & GTMDI_MCS_HLT_MCS1HBP0ICLR_MASK)

#define GTMDI_MCS_HLT_MCS1HBP1ICLR_MASK          (0x8U)
#define GTMDI_MCS_HLT_MCS1HBP1ICLR_SHIFT         (3U)
#define GTMDI_MCS_HLT_MCS1HBP1ICLR_WIDTH         (1U)
#define GTMDI_MCS_HLT_MCS1HBP1ICLR(x)            (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS1HBP1ICLR_SHIFT)) & GTMDI_MCS_HLT_MCS1HBP1ICLR_MASK)

#define GTMDI_MCS_HLT_MCS2HBP0ICLR_MASK          (0x10U)
#define GTMDI_MCS_HLT_MCS2HBP0ICLR_SHIFT         (4U)
#define GTMDI_MCS_HLT_MCS2HBP0ICLR_WIDTH         (1U)
#define GTMDI_MCS_HLT_MCS2HBP0ICLR(x)            (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS2HBP0ICLR_SHIFT)) & GTMDI_MCS_HLT_MCS2HBP0ICLR_MASK)

#define GTMDI_MCS_HLT_MCS2HBP1ICLR_MASK          (0x20U)
#define GTMDI_MCS_HLT_MCS2HBP1ICLR_SHIFT         (5U)
#define GTMDI_MCS_HLT_MCS2HBP1ICLR_WIDTH         (1U)
#define GTMDI_MCS_HLT_MCS2HBP1ICLR(x)            (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS2HBP1ICLR_SHIFT)) & GTMDI_MCS_HLT_MCS2HBP1ICLR_MASK)

#define GTMDI_MCS_HLT_MCS3HBP0ICLR_MASK          (0x40U)
#define GTMDI_MCS_HLT_MCS3HBP0ICLR_SHIFT         (6U)
#define GTMDI_MCS_HLT_MCS3HBP0ICLR_WIDTH         (1U)
#define GTMDI_MCS_HLT_MCS3HBP0ICLR(x)            (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS3HBP0ICLR_SHIFT)) & GTMDI_MCS_HLT_MCS3HBP0ICLR_MASK)

#define GTMDI_MCS_HLT_MCS3HBP1ICLR_MASK          (0x80U)
#define GTMDI_MCS_HLT_MCS3HBP1ICLR_SHIFT         (7U)
#define GTMDI_MCS_HLT_MCS3HBP1ICLR_WIDTH         (1U)
#define GTMDI_MCS_HLT_MCS3HBP1ICLR(x)            (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS3HBP1ICLR_SHIFT)) & GTMDI_MCS_HLT_MCS3HBP1ICLR_MASK)

#define GTMDI_MCS_HLT_MCSSS_MASK                 (0x8000U)
#define GTMDI_MCS_HLT_MCSSS_SHIFT                (15U)
#define GTMDI_MCS_HLT_MCSSS_WIDTH                (1U)
#define GTMDI_MCS_HLT_MCSSS(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCSSS_SHIFT)) & GTMDI_MCS_HLT_MCSSS_MASK)

#define GTMDI_MCS_HLT_MCS0HBP0IS_MASK            (0x10000U)
#define GTMDI_MCS_HLT_MCS0HBP0IS_SHIFT           (16U)
#define GTMDI_MCS_HLT_MCS0HBP0IS_WIDTH           (1U)
#define GTMDI_MCS_HLT_MCS0HBP0IS(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS0HBP0IS_SHIFT)) & GTMDI_MCS_HLT_MCS0HBP0IS_MASK)

#define GTMDI_MCS_HLT_MCS0HBP1IS_MASK            (0x20000U)
#define GTMDI_MCS_HLT_MCS0HBP1IS_SHIFT           (17U)
#define GTMDI_MCS_HLT_MCS0HBP1IS_WIDTH           (1U)
#define GTMDI_MCS_HLT_MCS0HBP1IS(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS0HBP1IS_SHIFT)) & GTMDI_MCS_HLT_MCS0HBP1IS_MASK)

#define GTMDI_MCS_HLT_MCS1HBP0IS_MASK            (0x40000U)
#define GTMDI_MCS_HLT_MCS1HBP0IS_SHIFT           (18U)
#define GTMDI_MCS_HLT_MCS1HBP0IS_WIDTH           (1U)
#define GTMDI_MCS_HLT_MCS1HBP0IS(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS1HBP0IS_SHIFT)) & GTMDI_MCS_HLT_MCS1HBP0IS_MASK)

#define GTMDI_MCS_HLT_MCS1HBP1IS_MASK            (0x80000U)
#define GTMDI_MCS_HLT_MCS1HBP1IS_SHIFT           (19U)
#define GTMDI_MCS_HLT_MCS1HBP1IS_WIDTH           (1U)
#define GTMDI_MCS_HLT_MCS1HBP1IS(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS1HBP1IS_SHIFT)) & GTMDI_MCS_HLT_MCS1HBP1IS_MASK)

#define GTMDI_MCS_HLT_MCS2HBP0IS_MASK            (0x100000U)
#define GTMDI_MCS_HLT_MCS2HBP0IS_SHIFT           (20U)
#define GTMDI_MCS_HLT_MCS2HBP0IS_WIDTH           (1U)
#define GTMDI_MCS_HLT_MCS2HBP0IS(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS2HBP0IS_SHIFT)) & GTMDI_MCS_HLT_MCS2HBP0IS_MASK)

#define GTMDI_MCS_HLT_MCS2HBP1IS_MASK            (0x200000U)
#define GTMDI_MCS_HLT_MCS2HBP1IS_SHIFT           (21U)
#define GTMDI_MCS_HLT_MCS2HBP1IS_WIDTH           (1U)
#define GTMDI_MCS_HLT_MCS2HBP1IS(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS2HBP1IS_SHIFT)) & GTMDI_MCS_HLT_MCS2HBP1IS_MASK)

#define GTMDI_MCS_HLT_MCS3HBP0IS_MASK            (0x400000U)
#define GTMDI_MCS_HLT_MCS3HBP0IS_SHIFT           (22U)
#define GTMDI_MCS_HLT_MCS3HBP0IS_WIDTH           (1U)
#define GTMDI_MCS_HLT_MCS3HBP0IS(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS3HBP0IS_SHIFT)) & GTMDI_MCS_HLT_MCS3HBP0IS_MASK)

#define GTMDI_MCS_HLT_MCS3HBP1IS_MASK            (0x800000U)
#define GTMDI_MCS_HLT_MCS3HBP1IS_SHIFT           (23U)
#define GTMDI_MCS_HLT_MCS3HBP1IS_WIDTH           (1U)
#define GTMDI_MCS_HLT_MCS3HBP1IS(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_MCS3HBP1IS_SHIFT)) & GTMDI_MCS_HLT_MCS3HBP1IS_MASK)

#define GTMDI_MCS_HLT_HALTSTAT_MASK              (0x7000000U)
#define GTMDI_MCS_HLT_HALTSTAT_SHIFT             (24U)
#define GTMDI_MCS_HLT_HALTSTAT_WIDTH             (3U)
#define GTMDI_MCS_HLT_HALTSTAT(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_MCS_HLT_HALTSTAT_SHIFT)) & GTMDI_MCS_HLT_HALTSTAT_MASK)
/*! @} */

/*! @name MCSA_DC - MCSA Development Control */
/*! @{ */

#define GTMDI_MCSA_DC_MCS_SEL_MASK               (0x300U)
#define GTMDI_MCSA_DC_MCS_SEL_SHIFT              (8U)
#define GTMDI_MCSA_DC_MCS_SEL_WIDTH              (2U)
#define GTMDI_MCSA_DC_MCS_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DC_MCS_SEL_SHIFT)) & GTMDI_MCSA_DC_MCS_SEL_MASK)

#define GTMDI_MCSA_DC_INDA_MASK                  (0x80000000U)
#define GTMDI_MCSA_DC_INDA_SHIFT                 (31U)
#define GTMDI_MCSA_DC_INDA_WIDTH                 (1U)
#define GTMDI_MCSA_DC_INDA(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DC_INDA_SHIFT)) & GTMDI_MCSA_DC_INDA_MASK)
/*! @} */

/*! @name MCSA_WPC - MCSA Watchpoint Control */
/*! @{ */

#define GTMDI_MCSA_WPC_SEN_MASK                  (0x1U)
#define GTMDI_MCSA_WPC_SEN_SHIFT                 (0U)
#define GTMDI_MCSA_WPC_SEN_WIDTH                 (1U)
#define GTMDI_MCSA_WPC_SEN(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPC_SEN_SHIFT)) & GTMDI_MCSA_WPC_SEN_MASK)

#define GTMDI_MCSA_WPC_TEN_MASK                  (0x2U)
#define GTMDI_MCSA_WPC_TEN_SHIFT                 (1U)
#define GTMDI_MCSA_WPC_TEN_WIDTH                 (1U)
#define GTMDI_MCSA_WPC_TEN(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPC_TEN_SHIFT)) & GTMDI_MCSA_WPC_TEN_MASK)

#define GTMDI_MCSA_WPC_STSEL_MASK                (0x30U)
#define GTMDI_MCSA_WPC_STSEL_SHIFT               (4U)
#define GTMDI_MCSA_WPC_STSEL_WIDTH               (2U)
#define GTMDI_MCSA_WPC_STSEL(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPC_STSEL_SHIFT)) & GTMDI_MCSA_WPC_STSEL_MASK)

#define GTMDI_MCSA_WPC_HEN_MASK                  (0x80U)
#define GTMDI_MCSA_WPC_HEN_SHIFT                 (7U)
#define GTMDI_MCSA_WPC_HEN_WIDTH                 (1U)
#define GTMDI_MCSA_WPC_HEN(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPC_HEN_SHIFT)) & GTMDI_MCSA_WPC_HEN_MASK)

#define GTMDI_MCSA_WPC_EOC_MASK                  (0x100U)
#define GTMDI_MCSA_WPC_EOC_SHIFT                 (8U)
#define GTMDI_MCSA_WPC_EOC_WIDTH                 (1U)
#define GTMDI_MCSA_WPC_EOC(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPC_EOC_SHIFT)) & GTMDI_MCSA_WPC_EOC_MASK)

#define GTMDI_MCSA_WPC_HWO_MASK                  (0xC000U)
#define GTMDI_MCSA_WPC_HWO_SHIFT                 (14U)
#define GTMDI_MCSA_WPC_HWO_WIDTH                 (2U)
#define GTMDI_MCSA_WPC_HWO(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPC_HWO_SHIFT)) & GTMDI_MCSA_WPC_HWO_MASK)

#define GTMDI_MCSA_WPC_HME_MASK                  (0xF0000U)
#define GTMDI_MCSA_WPC_HME_SHIFT                 (16U)
#define GTMDI_MCSA_WPC_HME_WIDTH                 (4U)
#define GTMDI_MCSA_WPC_HME(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPC_HME_SHIFT)) & GTMDI_MCSA_WPC_HME_MASK)

#define GTMDI_MCSA_WPC_WMC_MASK                  (0x400000U)
#define GTMDI_MCSA_WPC_WMC_SHIFT                 (22U)
#define GTMDI_MCSA_WPC_WMC_WIDTH                 (1U)
#define GTMDI_MCSA_WPC_WMC(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPC_WMC_SHIFT)) & GTMDI_MCSA_WPC_WMC_MASK)

#define GTMDI_MCSA_WPC_HACH_MASK                 (0x3000000U)
#define GTMDI_MCSA_WPC_HACH_SHIFT                (24U)
#define GTMDI_MCSA_WPC_HACH_WIDTH                (2U)
#define GTMDI_MCSA_WPC_HACH(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPC_HACH_SHIFT)) & GTMDI_MCSA_WPC_HACH_MASK)
/*! @} */

/*! @name MCSA_PTC - MCSA Program Fetch Trace Control */
/*! @{ */

#define GTMDI_MCSA_PTC_SEN_MASK                  (0x1U)
#define GTMDI_MCSA_PTC_SEN_SHIFT                 (0U)
#define GTMDI_MCSA_PTC_SEN_WIDTH                 (1U)
#define GTMDI_MCSA_PTC_SEN(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_PTC_SEN_SHIFT)) & GTMDI_MCSA_PTC_SEN_MASK)

#define GTMDI_MCSA_PTC_FTC_MASK                  (0x40U)
#define GTMDI_MCSA_PTC_FTC_SHIFT                 (6U)
#define GTMDI_MCSA_PTC_FTC_WIDTH                 (1U)
#define GTMDI_MCSA_PTC_FTC(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_PTC_FTC_SHIFT)) & GTMDI_MCSA_PTC_FTC_MASK)

#define GTMDI_MCSA_PTC_PFTE_MASK                 (0x300U)
#define GTMDI_MCSA_PTC_PFTE_SHIFT                (8U)
#define GTMDI_MCSA_PTC_PFTE_WIDTH                (2U)
#define GTMDI_MCSA_PTC_PFTE(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_PTC_PFTE_SHIFT)) & GTMDI_MCSA_PTC_PFTE_MASK)

#define GTMDI_MCSA_PTC_PFTS_MASK                 (0x3000U)
#define GTMDI_MCSA_PTC_PFTS_SHIFT                (12U)
#define GTMDI_MCSA_PTC_PFTS_WIDTH                (2U)
#define GTMDI_MCSA_PTC_PFTS(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_PTC_PFTS_SHIFT)) & GTMDI_MCSA_PTC_PFTS_MASK)
/*! @} */

/*! @name MCSA_DTC - MCSA Data Trace Control */
/*! @{ */

#define GTMDI_MCSA_DTC_SEN_MASK                  (0x1U)
#define GTMDI_MCSA_DTC_SEN_SHIFT                 (0U)
#define GTMDI_MCSA_DTC_SEN_WIDTH                 (1U)
#define GTMDI_MCSA_DTC_SEN(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTC_SEN_SHIFT)) & GTMDI_MCSA_DTC_SEN_MASK)

#define GTMDI_MCSA_DTC_DTE_MASK                  (0x6U)
#define GTMDI_MCSA_DTC_DTE_SHIFT                 (1U)
#define GTMDI_MCSA_DTC_DTE_WIDTH                 (2U)
#define GTMDI_MCSA_DTC_DTE(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTC_DTE_SHIFT)) & GTMDI_MCSA_DTC_DTE_MASK)

#define GTMDI_MCSA_DTC_DTS_MASK                  (0x30U)
#define GTMDI_MCSA_DTC_DTS_SHIFT                 (4U)
#define GTMDI_MCSA_DTC_DTS_WIDTH                 (2U)
#define GTMDI_MCSA_DTC_DTS(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTC_DTS_SHIFT)) & GTMDI_MCSA_DTC_DTS_MASK)

#define GTMDI_MCSA_DTC_DTC_MASK                  (0x40U)
#define GTMDI_MCSA_DTC_DTC_SHIFT                 (6U)
#define GTMDI_MCSA_DTC_DTC_WIDTH                 (1U)
#define GTMDI_MCSA_DTC_DTC(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTC_DTC_SHIFT)) & GTMDI_MCSA_DTC_DTC_MASK)

#define GTMDI_MCSA_DTC_RWT1_MASK                 (0x300U)
#define GTMDI_MCSA_DTC_RWT1_SHIFT                (8U)
#define GTMDI_MCSA_DTC_RWT1_WIDTH                (2U)
#define GTMDI_MCSA_DTC_RWT1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTC_RWT1_SHIFT)) & GTMDI_MCSA_DTC_RWT1_MASK)

#define GTMDI_MCSA_DTC_RWT0_MASK                 (0x3000U)
#define GTMDI_MCSA_DTC_RWT0_SHIFT                (12U)
#define GTMDI_MCSA_DTC_RWT0_WIDTH                (2U)
#define GTMDI_MCSA_DTC_RWT0(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTC_RWT0_SHIFT)) & GTMDI_MCSA_DTC_RWT0_MASK)

#define GTMDI_MCSA_DTC_RC1_MASK                  (0x10000U)
#define GTMDI_MCSA_DTC_RC1_SHIFT                 (16U)
#define GTMDI_MCSA_DTC_RC1_WIDTH                 (1U)
#define GTMDI_MCSA_DTC_RC1(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTC_RC1_SHIFT)) & GTMDI_MCSA_DTC_RC1_MASK)

#define GTMDI_MCSA_DTC_RC0_MASK                  (0x20000U)
#define GTMDI_MCSA_DTC_RC0_SHIFT                 (17U)
#define GTMDI_MCSA_DTC_RC0_WIDTH                 (1U)
#define GTMDI_MCSA_DTC_RC0(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTC_RC0_SHIFT)) & GTMDI_MCSA_DTC_RC0_MASK)
/*! @} */

/*! @name MCSA_WPA1 - MCSA Watchpoint Address 1 */
/*! @{ */

#define GTMDI_MCSA_WPA1_HWA_MASK                 (0x3FFFU)
#define GTMDI_MCSA_WPA1_HWA_SHIFT                (0U)
#define GTMDI_MCSA_WPA1_HWA_WIDTH                (14U)
#define GTMDI_MCSA_WPA1_HWA(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPA1_HWA_SHIFT)) & GTMDI_MCSA_WPA1_HWA_MASK)

#define GTMDI_MCSA_WPA1_HWAM_MASK                (0x3FFF0000U)
#define GTMDI_MCSA_WPA1_HWAM_SHIFT               (16U)
#define GTMDI_MCSA_WPA1_HWAM_WIDTH               (14U)
#define GTMDI_MCSA_WPA1_HWAM(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPA1_HWAM_SHIFT)) & GTMDI_MCSA_WPA1_HWAM_MASK)
/*! @} */

/*! @name MCSA_WPA2 - MCSA Watchpoint Address 2 */
/*! @{ */

#define GTMDI_MCSA_WPA2_HWA_MASK                 (0x3FFFU)
#define GTMDI_MCSA_WPA2_HWA_SHIFT                (0U)
#define GTMDI_MCSA_WPA2_HWA_WIDTH                (14U)
#define GTMDI_MCSA_WPA2_HWA(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPA2_HWA_SHIFT)) & GTMDI_MCSA_WPA2_HWA_MASK)

#define GTMDI_MCSA_WPA2_HWAM_MASK                (0x3FFF0000U)
#define GTMDI_MCSA_WPA2_HWAM_SHIFT               (16U)
#define GTMDI_MCSA_WPA2_HWAM_WIDTH               (14U)
#define GTMDI_MCSA_WPA2_HWAM(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPA2_HWAM_SHIFT)) & GTMDI_MCSA_WPA2_HWAM_MASK)
/*! @} */

/*! @name MCSA_WPD1 - MCSA Watchpoint Data 1 */
/*! @{ */

#define GTMDI_MCSA_WPD1_HWD_MASK                 (0xFFFFFFFFU)
#define GTMDI_MCSA_WPD1_HWD_SHIFT                (0U)
#define GTMDI_MCSA_WPD1_HWD_WIDTH                (32U)
#define GTMDI_MCSA_WPD1_HWD(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPD1_HWD_SHIFT)) & GTMDI_MCSA_WPD1_HWD_MASK)
/*! @} */

/*! @name MCSA_WPD2 - MCSA Watchpoint Data 2 */
/*! @{ */

#define GTMDI_MCSA_WPD2_HWD_MASK                 (0xFFFFFFFFU)
#define GTMDI_MCSA_WPD2_HWD_SHIFT                (0U)
#define GTMDI_MCSA_WPD2_HWD_WIDTH                (32U)
#define GTMDI_MCSA_WPD2_HWD(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_WPD2_HWD_SHIFT)) & GTMDI_MCSA_WPD2_HWD_MASK)
/*! @} */

/*! @name MCSA_CE - MCSA Channel Enable */
/*! @{ */

#define GTMDI_MCSA_CE_WPCE_MASK                  (0xFFU)
#define GTMDI_MCSA_CE_WPCE_SHIFT                 (0U)
#define GTMDI_MCSA_CE_WPCE_WIDTH                 (8U)
#define GTMDI_MCSA_CE_WPCE(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_CE_WPCE_SHIFT)) & GTMDI_MCSA_CE_WPCE_MASK)

#define GTMDI_MCSA_CE_CDTE_MASK                  (0xFF0000U)
#define GTMDI_MCSA_CE_CDTE_SHIFT                 (16U)
#define GTMDI_MCSA_CE_CDTE_WIDTH                 (8U)
#define GTMDI_MCSA_CE_CDTE(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_CE_CDTE_SHIFT)) & GTMDI_MCSA_CE_CDTE_MASK)

#define GTMDI_MCSA_CE_CFTE_MASK                  (0xFF000000U)
#define GTMDI_MCSA_CE_CFTE_SHIFT                 (24U)
#define GTMDI_MCSA_CE_CFTE_WIDTH                 (8U)
#define GTMDI_MCSA_CE_CFTE(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_CE_CFTE_SHIFT)) & GTMDI_MCSA_CE_CFTE_MASK)
/*! @} */

/*! @name MCSA_DTAR1 - MCSA Data Trace Address Range 1 */
/*! @{ */

#define GTMDI_MCSA_DTAR1_DTEA_MASK               (0x7FFCU)
#define GTMDI_MCSA_DTAR1_DTEA_SHIFT              (2U)
#define GTMDI_MCSA_DTAR1_DTEA_WIDTH              (13U)
#define GTMDI_MCSA_DTAR1_DTEA(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTAR1_DTEA_SHIFT)) & GTMDI_MCSA_DTAR1_DTEA_MASK)

#define GTMDI_MCSA_DTAR1_DTSA_MASK               (0x7FFC0000U)
#define GTMDI_MCSA_DTAR1_DTSA_SHIFT              (18U)
#define GTMDI_MCSA_DTAR1_DTSA_WIDTH              (13U)
#define GTMDI_MCSA_DTAR1_DTSA(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTAR1_DTSA_SHIFT)) & GTMDI_MCSA_DTAR1_DTSA_MASK)
/*! @} */

/*! @name MCSA_DTAR2 - MCSA Data Trace Address Range 2 */
/*! @{ */

#define GTMDI_MCSA_DTAR2_DTEA_MASK               (0x7FFCU)
#define GTMDI_MCSA_DTAR2_DTEA_SHIFT              (2U)
#define GTMDI_MCSA_DTAR2_DTEA_WIDTH              (13U)
#define GTMDI_MCSA_DTAR2_DTEA(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTAR2_DTEA_SHIFT)) & GTMDI_MCSA_DTAR2_DTEA_MASK)

#define GTMDI_MCSA_DTAR2_DTSA_MASK               (0x7FFC0000U)
#define GTMDI_MCSA_DTAR2_DTSA_SHIFT              (18U)
#define GTMDI_MCSA_DTAR2_DTSA_WIDTH              (13U)
#define GTMDI_MCSA_DTAR2_DTSA(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSA_DTAR2_DTSA_SHIFT)) & GTMDI_MCSA_DTAR2_DTSA_MASK)
/*! @} */

/*! @name MCSB_DC - MCSB Development Control */
/*! @{ */

#define GTMDI_MCSB_DC_MCS_SEL_MASK               (0x300U)
#define GTMDI_MCSB_DC_MCS_SEL_SHIFT              (8U)
#define GTMDI_MCSB_DC_MCS_SEL_WIDTH              (2U)
#define GTMDI_MCSB_DC_MCS_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DC_MCS_SEL_SHIFT)) & GTMDI_MCSB_DC_MCS_SEL_MASK)

#define GTMDI_MCSB_DC_INDA_MASK                  (0x80000000U)
#define GTMDI_MCSB_DC_INDA_SHIFT                 (31U)
#define GTMDI_MCSB_DC_INDA_WIDTH                 (1U)
#define GTMDI_MCSB_DC_INDA(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DC_INDA_SHIFT)) & GTMDI_MCSB_DC_INDA_MASK)
/*! @} */

/*! @name MCSB_WPC - MCSB Watchpoint Control */
/*! @{ */

#define GTMDI_MCSB_WPC_SEN_MASK                  (0x1U)
#define GTMDI_MCSB_WPC_SEN_SHIFT                 (0U)
#define GTMDI_MCSB_WPC_SEN_WIDTH                 (1U)
#define GTMDI_MCSB_WPC_SEN(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPC_SEN_SHIFT)) & GTMDI_MCSB_WPC_SEN_MASK)

#define GTMDI_MCSB_WPC_TEN_MASK                  (0x2U)
#define GTMDI_MCSB_WPC_TEN_SHIFT                 (1U)
#define GTMDI_MCSB_WPC_TEN_WIDTH                 (1U)
#define GTMDI_MCSB_WPC_TEN(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPC_TEN_SHIFT)) & GTMDI_MCSB_WPC_TEN_MASK)

#define GTMDI_MCSB_WPC_STSEL_MASK                (0x30U)
#define GTMDI_MCSB_WPC_STSEL_SHIFT               (4U)
#define GTMDI_MCSB_WPC_STSEL_WIDTH               (2U)
#define GTMDI_MCSB_WPC_STSEL(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPC_STSEL_SHIFT)) & GTMDI_MCSB_WPC_STSEL_MASK)

#define GTMDI_MCSB_WPC_HEN_MASK                  (0x80U)
#define GTMDI_MCSB_WPC_HEN_SHIFT                 (7U)
#define GTMDI_MCSB_WPC_HEN_WIDTH                 (1U)
#define GTMDI_MCSB_WPC_HEN(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPC_HEN_SHIFT)) & GTMDI_MCSB_WPC_HEN_MASK)

#define GTMDI_MCSB_WPC_EOC_MASK                  (0x100U)
#define GTMDI_MCSB_WPC_EOC_SHIFT                 (8U)
#define GTMDI_MCSB_WPC_EOC_WIDTH                 (1U)
#define GTMDI_MCSB_WPC_EOC(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPC_EOC_SHIFT)) & GTMDI_MCSB_WPC_EOC_MASK)

#define GTMDI_MCSB_WPC_HWO_MASK                  (0xC000U)
#define GTMDI_MCSB_WPC_HWO_SHIFT                 (14U)
#define GTMDI_MCSB_WPC_HWO_WIDTH                 (2U)
#define GTMDI_MCSB_WPC_HWO(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPC_HWO_SHIFT)) & GTMDI_MCSB_WPC_HWO_MASK)

#define GTMDI_MCSB_WPC_HME_MASK                  (0xF0000U)
#define GTMDI_MCSB_WPC_HME_SHIFT                 (16U)
#define GTMDI_MCSB_WPC_HME_WIDTH                 (4U)
#define GTMDI_MCSB_WPC_HME(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPC_HME_SHIFT)) & GTMDI_MCSB_WPC_HME_MASK)

#define GTMDI_MCSB_WPC_WMC_MASK                  (0x400000U)
#define GTMDI_MCSB_WPC_WMC_SHIFT                 (22U)
#define GTMDI_MCSB_WPC_WMC_WIDTH                 (1U)
#define GTMDI_MCSB_WPC_WMC(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPC_WMC_SHIFT)) & GTMDI_MCSB_WPC_WMC_MASK)

#define GTMDI_MCSB_WPC_HACH_MASK                 (0x3000000U)
#define GTMDI_MCSB_WPC_HACH_SHIFT                (24U)
#define GTMDI_MCSB_WPC_HACH_WIDTH                (2U)
#define GTMDI_MCSB_WPC_HACH(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPC_HACH_SHIFT)) & GTMDI_MCSB_WPC_HACH_MASK)
/*! @} */

/*! @name MCSB_PTC - MCSB Program Fetch Trace Control */
/*! @{ */

#define GTMDI_MCSB_PTC_SEN_MASK                  (0x1U)
#define GTMDI_MCSB_PTC_SEN_SHIFT                 (0U)
#define GTMDI_MCSB_PTC_SEN_WIDTH                 (1U)
#define GTMDI_MCSB_PTC_SEN(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_PTC_SEN_SHIFT)) & GTMDI_MCSB_PTC_SEN_MASK)

#define GTMDI_MCSB_PTC_FTC_MASK                  (0x40U)
#define GTMDI_MCSB_PTC_FTC_SHIFT                 (6U)
#define GTMDI_MCSB_PTC_FTC_WIDTH                 (1U)
#define GTMDI_MCSB_PTC_FTC(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_PTC_FTC_SHIFT)) & GTMDI_MCSB_PTC_FTC_MASK)

#define GTMDI_MCSB_PTC_PFTE_MASK                 (0x300U)
#define GTMDI_MCSB_PTC_PFTE_SHIFT                (8U)
#define GTMDI_MCSB_PTC_PFTE_WIDTH                (2U)
#define GTMDI_MCSB_PTC_PFTE(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_PTC_PFTE_SHIFT)) & GTMDI_MCSB_PTC_PFTE_MASK)

#define GTMDI_MCSB_PTC_PFTS_MASK                 (0x3000U)
#define GTMDI_MCSB_PTC_PFTS_SHIFT                (12U)
#define GTMDI_MCSB_PTC_PFTS_WIDTH                (2U)
#define GTMDI_MCSB_PTC_PFTS(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_PTC_PFTS_SHIFT)) & GTMDI_MCSB_PTC_PFTS_MASK)
/*! @} */

/*! @name MCSB_DTC - MCSB Data Trace Control */
/*! @{ */

#define GTMDI_MCSB_DTC_SEN_MASK                  (0x1U)
#define GTMDI_MCSB_DTC_SEN_SHIFT                 (0U)
#define GTMDI_MCSB_DTC_SEN_WIDTH                 (1U)
#define GTMDI_MCSB_DTC_SEN(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTC_SEN_SHIFT)) & GTMDI_MCSB_DTC_SEN_MASK)

#define GTMDI_MCSB_DTC_DTE_MASK                  (0x6U)
#define GTMDI_MCSB_DTC_DTE_SHIFT                 (1U)
#define GTMDI_MCSB_DTC_DTE_WIDTH                 (2U)
#define GTMDI_MCSB_DTC_DTE(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTC_DTE_SHIFT)) & GTMDI_MCSB_DTC_DTE_MASK)

#define GTMDI_MCSB_DTC_DTS_MASK                  (0x30U)
#define GTMDI_MCSB_DTC_DTS_SHIFT                 (4U)
#define GTMDI_MCSB_DTC_DTS_WIDTH                 (2U)
#define GTMDI_MCSB_DTC_DTS(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTC_DTS_SHIFT)) & GTMDI_MCSB_DTC_DTS_MASK)

#define GTMDI_MCSB_DTC_DTC_MASK                  (0x40U)
#define GTMDI_MCSB_DTC_DTC_SHIFT                 (6U)
#define GTMDI_MCSB_DTC_DTC_WIDTH                 (1U)
#define GTMDI_MCSB_DTC_DTC(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTC_DTC_SHIFT)) & GTMDI_MCSB_DTC_DTC_MASK)

#define GTMDI_MCSB_DTC_RWT1_MASK                 (0x300U)
#define GTMDI_MCSB_DTC_RWT1_SHIFT                (8U)
#define GTMDI_MCSB_DTC_RWT1_WIDTH                (2U)
#define GTMDI_MCSB_DTC_RWT1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTC_RWT1_SHIFT)) & GTMDI_MCSB_DTC_RWT1_MASK)

#define GTMDI_MCSB_DTC_RWT0_MASK                 (0x3000U)
#define GTMDI_MCSB_DTC_RWT0_SHIFT                (12U)
#define GTMDI_MCSB_DTC_RWT0_WIDTH                (2U)
#define GTMDI_MCSB_DTC_RWT0(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTC_RWT0_SHIFT)) & GTMDI_MCSB_DTC_RWT0_MASK)

#define GTMDI_MCSB_DTC_RC1_MASK                  (0x10000U)
#define GTMDI_MCSB_DTC_RC1_SHIFT                 (16U)
#define GTMDI_MCSB_DTC_RC1_WIDTH                 (1U)
#define GTMDI_MCSB_DTC_RC1(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTC_RC1_SHIFT)) & GTMDI_MCSB_DTC_RC1_MASK)

#define GTMDI_MCSB_DTC_RC0_MASK                  (0x20000U)
#define GTMDI_MCSB_DTC_RC0_SHIFT                 (17U)
#define GTMDI_MCSB_DTC_RC0_WIDTH                 (1U)
#define GTMDI_MCSB_DTC_RC0(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTC_RC0_SHIFT)) & GTMDI_MCSB_DTC_RC0_MASK)
/*! @} */

/*! @name MCSB_WPA1 - MCSB Watchpoint Address 1 */
/*! @{ */

#define GTMDI_MCSB_WPA1_HWA_MASK                 (0x3FFFU)
#define GTMDI_MCSB_WPA1_HWA_SHIFT                (0U)
#define GTMDI_MCSB_WPA1_HWA_WIDTH                (14U)
#define GTMDI_MCSB_WPA1_HWA(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPA1_HWA_SHIFT)) & GTMDI_MCSB_WPA1_HWA_MASK)

#define GTMDI_MCSB_WPA1_HWAM_MASK                (0x3FFF0000U)
#define GTMDI_MCSB_WPA1_HWAM_SHIFT               (16U)
#define GTMDI_MCSB_WPA1_HWAM_WIDTH               (14U)
#define GTMDI_MCSB_WPA1_HWAM(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPA1_HWAM_SHIFT)) & GTMDI_MCSB_WPA1_HWAM_MASK)
/*! @} */

/*! @name MCSB_WPA2 - MCSB Watchpoint Address 2 */
/*! @{ */

#define GTMDI_MCSB_WPA2_HWA_MASK                 (0x3FFFU)
#define GTMDI_MCSB_WPA2_HWA_SHIFT                (0U)
#define GTMDI_MCSB_WPA2_HWA_WIDTH                (14U)
#define GTMDI_MCSB_WPA2_HWA(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPA2_HWA_SHIFT)) & GTMDI_MCSB_WPA2_HWA_MASK)

#define GTMDI_MCSB_WPA2_HWAM_MASK                (0x3FFF0000U)
#define GTMDI_MCSB_WPA2_HWAM_SHIFT               (16U)
#define GTMDI_MCSB_WPA2_HWAM_WIDTH               (14U)
#define GTMDI_MCSB_WPA2_HWAM(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPA2_HWAM_SHIFT)) & GTMDI_MCSB_WPA2_HWAM_MASK)
/*! @} */

/*! @name MCSB_WPD1 - MCSB Watchpoint Data 1 */
/*! @{ */

#define GTMDI_MCSB_WPD1_HWD_MASK                 (0xFFFFFFFFU)
#define GTMDI_MCSB_WPD1_HWD_SHIFT                (0U)
#define GTMDI_MCSB_WPD1_HWD_WIDTH                (32U)
#define GTMDI_MCSB_WPD1_HWD(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPD1_HWD_SHIFT)) & GTMDI_MCSB_WPD1_HWD_MASK)
/*! @} */

/*! @name MCSB_WPD2 - MCSB Watchpoint Data 2 */
/*! @{ */

#define GTMDI_MCSB_WPD2_HWD_MASK                 (0xFFFFFFFFU)
#define GTMDI_MCSB_WPD2_HWD_SHIFT                (0U)
#define GTMDI_MCSB_WPD2_HWD_WIDTH                (32U)
#define GTMDI_MCSB_WPD2_HWD(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_WPD2_HWD_SHIFT)) & GTMDI_MCSB_WPD2_HWD_MASK)
/*! @} */

/*! @name MCSB_CE - MCSB Channel Enable */
/*! @{ */

#define GTMDI_MCSB_CE_WPCE_MASK                  (0xFFU)
#define GTMDI_MCSB_CE_WPCE_SHIFT                 (0U)
#define GTMDI_MCSB_CE_WPCE_WIDTH                 (8U)
#define GTMDI_MCSB_CE_WPCE(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_CE_WPCE_SHIFT)) & GTMDI_MCSB_CE_WPCE_MASK)

#define GTMDI_MCSB_CE_CDTE_MASK                  (0xFF0000U)
#define GTMDI_MCSB_CE_CDTE_SHIFT                 (16U)
#define GTMDI_MCSB_CE_CDTE_WIDTH                 (8U)
#define GTMDI_MCSB_CE_CDTE(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_CE_CDTE_SHIFT)) & GTMDI_MCSB_CE_CDTE_MASK)

#define GTMDI_MCSB_CE_CFTE_MASK                  (0xFF000000U)
#define GTMDI_MCSB_CE_CFTE_SHIFT                 (24U)
#define GTMDI_MCSB_CE_CFTE_WIDTH                 (8U)
#define GTMDI_MCSB_CE_CFTE(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_CE_CFTE_SHIFT)) & GTMDI_MCSB_CE_CFTE_MASK)
/*! @} */

/*! @name MCSB_DTAR1 - MCSB Data Trace Address Range 1 */
/*! @{ */

#define GTMDI_MCSB_DTAR1_DTEA_MASK               (0x7FFCU)
#define GTMDI_MCSB_DTAR1_DTEA_SHIFT              (2U)
#define GTMDI_MCSB_DTAR1_DTEA_WIDTH              (13U)
#define GTMDI_MCSB_DTAR1_DTEA(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTAR1_DTEA_SHIFT)) & GTMDI_MCSB_DTAR1_DTEA_MASK)

#define GTMDI_MCSB_DTAR1_DTSA_MASK               (0x7FFC0000U)
#define GTMDI_MCSB_DTAR1_DTSA_SHIFT              (18U)
#define GTMDI_MCSB_DTAR1_DTSA_WIDTH              (13U)
#define GTMDI_MCSB_DTAR1_DTSA(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTAR1_DTSA_SHIFT)) & GTMDI_MCSB_DTAR1_DTSA_MASK)
/*! @} */

/*! @name MCSB_DTAR2 - MCSB Data Trace Address Range 2 */
/*! @{ */

#define GTMDI_MCSB_DTAR2_DTEA_MASK               (0x7FFCU)
#define GTMDI_MCSB_DTAR2_DTEA_SHIFT              (2U)
#define GTMDI_MCSB_DTAR2_DTEA_WIDTH              (13U)
#define GTMDI_MCSB_DTAR2_DTEA(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTAR2_DTEA_SHIFT)) & GTMDI_MCSB_DTAR2_DTEA_MASK)

#define GTMDI_MCSB_DTAR2_DTSA_MASK               (0x7FFC0000U)
#define GTMDI_MCSB_DTAR2_DTSA_SHIFT              (18U)
#define GTMDI_MCSB_DTAR2_DTSA_WIDTH              (13U)
#define GTMDI_MCSB_DTAR2_DTSA(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_MCSB_DTAR2_DTSA_SHIFT)) & GTMDI_MCSB_DTAR2_DTSA_MASK)
/*! @} */

/*! @name TBU0_WPC1 - TBU0 Watchpoint Control 1 */
/*! @{ */

#define GTMDI_TBU0_WPC1_WMC2_MASK                (0x40U)
#define GTMDI_TBU0_WPC1_WMC2_SHIFT               (6U)
#define GTMDI_TBU0_WPC1_WMC2_WIDTH               (1U)
#define GTMDI_TBU0_WPC1_WMC2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC1_WMC2_SHIFT)) & GTMDI_TBU0_WPC1_WMC2_MASK)

#define GTMDI_TBU0_WPC1_HEN2_MASK                (0x80U)
#define GTMDI_TBU0_WPC1_HEN2_SHIFT               (7U)
#define GTMDI_TBU0_WPC1_HEN2_WIDTH               (1U)
#define GTMDI_TBU0_WPC1_HEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC1_HEN2_SHIFT)) & GTMDI_TBU0_WPC1_HEN2_MASK)

#define GTMDI_TBU0_WPC1_TSS2_MASK                (0x7000U)
#define GTMDI_TBU0_WPC1_TSS2_SHIFT               (12U)
#define GTMDI_TBU0_WPC1_TSS2_WIDTH               (3U)
#define GTMDI_TBU0_WPC1_TSS2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC1_TSS2_SHIFT)) & GTMDI_TBU0_WPC1_TSS2_MASK)

#define GTMDI_TBU0_WPC1_WMC1_MASK                (0x400000U)
#define GTMDI_TBU0_WPC1_WMC1_SHIFT               (22U)
#define GTMDI_TBU0_WPC1_WMC1_WIDTH               (1U)
#define GTMDI_TBU0_WPC1_WMC1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC1_WMC1_SHIFT)) & GTMDI_TBU0_WPC1_WMC1_MASK)

#define GTMDI_TBU0_WPC1_HEN1_MASK                (0x800000U)
#define GTMDI_TBU0_WPC1_HEN1_SHIFT               (23U)
#define GTMDI_TBU0_WPC1_HEN1_WIDTH               (1U)
#define GTMDI_TBU0_WPC1_HEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC1_HEN1_SHIFT)) & GTMDI_TBU0_WPC1_HEN1_MASK)

#define GTMDI_TBU0_WPC1_TSS1_MASK                (0x70000000U)
#define GTMDI_TBU0_WPC1_TSS1_SHIFT               (28U)
#define GTMDI_TBU0_WPC1_TSS1_WIDTH               (3U)
#define GTMDI_TBU0_WPC1_TSS1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC1_TSS1_SHIFT)) & GTMDI_TBU0_WPC1_TSS1_MASK)
/*! @} */

/*! @name TBU0_WPC2 - TBUn Watchpoint Control 2 */
/*! @{ */

#define GTMDI_TBU0_WPC2_SEN2_MASK                (0x1U)
#define GTMDI_TBU0_WPC2_SEN2_SHIFT               (0U)
#define GTMDI_TBU0_WPC2_SEN2_WIDTH               (1U)
#define GTMDI_TBU0_WPC2_SEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC2_SEN2_SHIFT)) & GTMDI_TBU0_WPC2_SEN2_MASK)

#define GTMDI_TBU0_WPC2_TEN2_MASK                (0x2U)
#define GTMDI_TBU0_WPC2_TEN2_SHIFT               (1U)
#define GTMDI_TBU0_WPC2_TEN2_WIDTH               (1U)
#define GTMDI_TBU0_WPC2_TEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC2_TEN2_SHIFT)) & GTMDI_TBU0_WPC2_TEN2_MASK)

#define GTMDI_TBU0_WPC2_STSEL2_MASK              (0x30U)
#define GTMDI_TBU0_WPC2_STSEL2_SHIFT             (4U)
#define GTMDI_TBU0_WPC2_STSEL2_WIDTH             (2U)
#define GTMDI_TBU0_WPC2_STSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC2_STSEL2_SHIFT)) & GTMDI_TBU0_WPC2_STSEL2_MASK)

#define GTMDI_TBU0_WPC2_WTSEL2_MASK              (0x7000U)
#define GTMDI_TBU0_WPC2_WTSEL2_SHIFT             (12U)
#define GTMDI_TBU0_WPC2_WTSEL2_WIDTH             (3U)
#define GTMDI_TBU0_WPC2_WTSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC2_WTSEL2_SHIFT)) & GTMDI_TBU0_WPC2_WTSEL2_MASK)

#define GTMDI_TBU0_WPC2_SEN1_MASK                (0x10000U)
#define GTMDI_TBU0_WPC2_SEN1_SHIFT               (16U)
#define GTMDI_TBU0_WPC2_SEN1_WIDTH               (1U)
#define GTMDI_TBU0_WPC2_SEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC2_SEN1_SHIFT)) & GTMDI_TBU0_WPC2_SEN1_MASK)

#define GTMDI_TBU0_WPC2_TEN1_MASK                (0x20000U)
#define GTMDI_TBU0_WPC2_TEN1_SHIFT               (17U)
#define GTMDI_TBU0_WPC2_TEN1_WIDTH               (1U)
#define GTMDI_TBU0_WPC2_TEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC2_TEN1_SHIFT)) & GTMDI_TBU0_WPC2_TEN1_MASK)

#define GTMDI_TBU0_WPC2_STSEL1_MASK              (0x300000U)
#define GTMDI_TBU0_WPC2_STSEL1_SHIFT             (20U)
#define GTMDI_TBU0_WPC2_STSEL1_WIDTH             (2U)
#define GTMDI_TBU0_WPC2_STSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC2_STSEL1_SHIFT)) & GTMDI_TBU0_WPC2_STSEL1_MASK)

#define GTMDI_TBU0_WPC2_WTSEL1_MASK              (0x70000000U)
#define GTMDI_TBU0_WPC2_WTSEL1_SHIFT             (28U)
#define GTMDI_TBU0_WPC2_WTSEL1_WIDTH             (3U)
#define GTMDI_TBU0_WPC2_WTSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_WPC2_WTSEL1_SHIFT)) & GTMDI_TBU0_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name TBU0_D - TBU0 Watchpoint DATA */
/*! @{ */

#define GTMDI_TBU0_D_TBU0_DATA_MASK              (0x7FFFFFFU)
#define GTMDI_TBU0_D_TBU0_DATA_SHIFT             (0U)
#define GTMDI_TBU0_D_TBU0_DATA_WIDTH             (27U)
#define GTMDI_TBU0_D_TBU0_DATA(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU0_D_TBU0_DATA_SHIFT)) & GTMDI_TBU0_D_TBU0_DATA_MASK)
/*! @} */

/*! @name TBU1_WPC1 - TBUn Watchpoint Control 1 */
/*! @{ */

#define GTMDI_TBU1_WPC1_WMC2_MASK                (0x40U)
#define GTMDI_TBU1_WPC1_WMC2_SHIFT               (6U)
#define GTMDI_TBU1_WPC1_WMC2_WIDTH               (1U)
#define GTMDI_TBU1_WPC1_WMC2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC1_WMC2_SHIFT)) & GTMDI_TBU1_WPC1_WMC2_MASK)

#define GTMDI_TBU1_WPC1_HEN2_MASK                (0x80U)
#define GTMDI_TBU1_WPC1_HEN2_SHIFT               (7U)
#define GTMDI_TBU1_WPC1_HEN2_WIDTH               (1U)
#define GTMDI_TBU1_WPC1_HEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC1_HEN2_SHIFT)) & GTMDI_TBU1_WPC1_HEN2_MASK)

#define GTMDI_TBU1_WPC1_TSS2_MASK                (0x3000U)
#define GTMDI_TBU1_WPC1_TSS2_SHIFT               (12U)
#define GTMDI_TBU1_WPC1_TSS2_WIDTH               (2U)
#define GTMDI_TBU1_WPC1_TSS2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC1_TSS2_SHIFT)) & GTMDI_TBU1_WPC1_TSS2_MASK)

#define GTMDI_TBU1_WPC1_WMC1_MASK                (0x400000U)
#define GTMDI_TBU1_WPC1_WMC1_SHIFT               (22U)
#define GTMDI_TBU1_WPC1_WMC1_WIDTH               (1U)
#define GTMDI_TBU1_WPC1_WMC1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC1_WMC1_SHIFT)) & GTMDI_TBU1_WPC1_WMC1_MASK)

#define GTMDI_TBU1_WPC1_HEN1_MASK                (0x800000U)
#define GTMDI_TBU1_WPC1_HEN1_SHIFT               (23U)
#define GTMDI_TBU1_WPC1_HEN1_WIDTH               (1U)
#define GTMDI_TBU1_WPC1_HEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC1_HEN1_SHIFT)) & GTMDI_TBU1_WPC1_HEN1_MASK)

#define GTMDI_TBU1_WPC1_TSS1_MASK                (0x30000000U)
#define GTMDI_TBU1_WPC1_TSS1_SHIFT               (28U)
#define GTMDI_TBU1_WPC1_TSS1_WIDTH               (2U)
#define GTMDI_TBU1_WPC1_TSS1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC1_TSS1_SHIFT)) & GTMDI_TBU1_WPC1_TSS1_MASK)
/*! @} */

/*! @name TBU1_WPC2 - TBUn Watchpoint Control 2 */
/*! @{ */

#define GTMDI_TBU1_WPC2_SEN2_MASK                (0x1U)
#define GTMDI_TBU1_WPC2_SEN2_SHIFT               (0U)
#define GTMDI_TBU1_WPC2_SEN2_WIDTH               (1U)
#define GTMDI_TBU1_WPC2_SEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC2_SEN2_SHIFT)) & GTMDI_TBU1_WPC2_SEN2_MASK)

#define GTMDI_TBU1_WPC2_TEN2_MASK                (0x2U)
#define GTMDI_TBU1_WPC2_TEN2_SHIFT               (1U)
#define GTMDI_TBU1_WPC2_TEN2_WIDTH               (1U)
#define GTMDI_TBU1_WPC2_TEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC2_TEN2_SHIFT)) & GTMDI_TBU1_WPC2_TEN2_MASK)

#define GTMDI_TBU1_WPC2_STSEL2_MASK              (0x30U)
#define GTMDI_TBU1_WPC2_STSEL2_SHIFT             (4U)
#define GTMDI_TBU1_WPC2_STSEL2_WIDTH             (2U)
#define GTMDI_TBU1_WPC2_STSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC2_STSEL2_SHIFT)) & GTMDI_TBU1_WPC2_STSEL2_MASK)

#define GTMDI_TBU1_WPC2_WTSEL2_MASK              (0x7000U)
#define GTMDI_TBU1_WPC2_WTSEL2_SHIFT             (12U)
#define GTMDI_TBU1_WPC2_WTSEL2_WIDTH             (3U)
#define GTMDI_TBU1_WPC2_WTSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC2_WTSEL2_SHIFT)) & GTMDI_TBU1_WPC2_WTSEL2_MASK)

#define GTMDI_TBU1_WPC2_SEN1_MASK                (0x10000U)
#define GTMDI_TBU1_WPC2_SEN1_SHIFT               (16U)
#define GTMDI_TBU1_WPC2_SEN1_WIDTH               (1U)
#define GTMDI_TBU1_WPC2_SEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC2_SEN1_SHIFT)) & GTMDI_TBU1_WPC2_SEN1_MASK)

#define GTMDI_TBU1_WPC2_TEN1_MASK                (0x20000U)
#define GTMDI_TBU1_WPC2_TEN1_SHIFT               (17U)
#define GTMDI_TBU1_WPC2_TEN1_WIDTH               (1U)
#define GTMDI_TBU1_WPC2_TEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC2_TEN1_SHIFT)) & GTMDI_TBU1_WPC2_TEN1_MASK)

#define GTMDI_TBU1_WPC2_STSEL1_MASK              (0x300000U)
#define GTMDI_TBU1_WPC2_STSEL1_SHIFT             (20U)
#define GTMDI_TBU1_WPC2_STSEL1_WIDTH             (2U)
#define GTMDI_TBU1_WPC2_STSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC2_STSEL1_SHIFT)) & GTMDI_TBU1_WPC2_STSEL1_MASK)

#define GTMDI_TBU1_WPC2_WTSEL1_MASK              (0x70000000U)
#define GTMDI_TBU1_WPC2_WTSEL1_SHIFT             (28U)
#define GTMDI_TBU1_WPC2_WTSEL1_WIDTH             (3U)
#define GTMDI_TBU1_WPC2_WTSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_WPC2_WTSEL1_SHIFT)) & GTMDI_TBU1_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name TBU1_D - TBUn Watchpoint DATA */
/*! @{ */

#define GTMDI_TBU1_D_TBUn_DATA_MASK              (0xFFFFFFU)
#define GTMDI_TBU1_D_TBUn_DATA_SHIFT             (0U)
#define GTMDI_TBU1_D_TBUn_DATA_WIDTH             (24U)
#define GTMDI_TBU1_D_TBUn_DATA(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU1_D_TBUn_DATA_SHIFT)) & GTMDI_TBU1_D_TBUn_DATA_MASK)
/*! @} */

/*! @name TBU2_WPC1 - TBUn Watchpoint Control 1 */
/*! @{ */

#define GTMDI_TBU2_WPC1_WMC2_MASK                (0x40U)
#define GTMDI_TBU2_WPC1_WMC2_SHIFT               (6U)
#define GTMDI_TBU2_WPC1_WMC2_WIDTH               (1U)
#define GTMDI_TBU2_WPC1_WMC2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC1_WMC2_SHIFT)) & GTMDI_TBU2_WPC1_WMC2_MASK)

#define GTMDI_TBU2_WPC1_HEN2_MASK                (0x80U)
#define GTMDI_TBU2_WPC1_HEN2_SHIFT               (7U)
#define GTMDI_TBU2_WPC1_HEN2_WIDTH               (1U)
#define GTMDI_TBU2_WPC1_HEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC1_HEN2_SHIFT)) & GTMDI_TBU2_WPC1_HEN2_MASK)

#define GTMDI_TBU2_WPC1_TSS2_MASK                (0x3000U)
#define GTMDI_TBU2_WPC1_TSS2_SHIFT               (12U)
#define GTMDI_TBU2_WPC1_TSS2_WIDTH               (2U)
#define GTMDI_TBU2_WPC1_TSS2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC1_TSS2_SHIFT)) & GTMDI_TBU2_WPC1_TSS2_MASK)

#define GTMDI_TBU2_WPC1_WMC1_MASK                (0x400000U)
#define GTMDI_TBU2_WPC1_WMC1_SHIFT               (22U)
#define GTMDI_TBU2_WPC1_WMC1_WIDTH               (1U)
#define GTMDI_TBU2_WPC1_WMC1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC1_WMC1_SHIFT)) & GTMDI_TBU2_WPC1_WMC1_MASK)

#define GTMDI_TBU2_WPC1_HEN1_MASK                (0x800000U)
#define GTMDI_TBU2_WPC1_HEN1_SHIFT               (23U)
#define GTMDI_TBU2_WPC1_HEN1_WIDTH               (1U)
#define GTMDI_TBU2_WPC1_HEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC1_HEN1_SHIFT)) & GTMDI_TBU2_WPC1_HEN1_MASK)

#define GTMDI_TBU2_WPC1_TSS1_MASK                (0x30000000U)
#define GTMDI_TBU2_WPC1_TSS1_SHIFT               (28U)
#define GTMDI_TBU2_WPC1_TSS1_WIDTH               (2U)
#define GTMDI_TBU2_WPC1_TSS1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC1_TSS1_SHIFT)) & GTMDI_TBU2_WPC1_TSS1_MASK)
/*! @} */

/*! @name TBU2_WPC2 - TBUn Watchpoint Control 2 */
/*! @{ */

#define GTMDI_TBU2_WPC2_SEN2_MASK                (0x1U)
#define GTMDI_TBU2_WPC2_SEN2_SHIFT               (0U)
#define GTMDI_TBU2_WPC2_SEN2_WIDTH               (1U)
#define GTMDI_TBU2_WPC2_SEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC2_SEN2_SHIFT)) & GTMDI_TBU2_WPC2_SEN2_MASK)

#define GTMDI_TBU2_WPC2_TEN2_MASK                (0x2U)
#define GTMDI_TBU2_WPC2_TEN2_SHIFT               (1U)
#define GTMDI_TBU2_WPC2_TEN2_WIDTH               (1U)
#define GTMDI_TBU2_WPC2_TEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC2_TEN2_SHIFT)) & GTMDI_TBU2_WPC2_TEN2_MASK)

#define GTMDI_TBU2_WPC2_STSEL2_MASK              (0x30U)
#define GTMDI_TBU2_WPC2_STSEL2_SHIFT             (4U)
#define GTMDI_TBU2_WPC2_STSEL2_WIDTH             (2U)
#define GTMDI_TBU2_WPC2_STSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC2_STSEL2_SHIFT)) & GTMDI_TBU2_WPC2_STSEL2_MASK)

#define GTMDI_TBU2_WPC2_WTSEL2_MASK              (0x7000U)
#define GTMDI_TBU2_WPC2_WTSEL2_SHIFT             (12U)
#define GTMDI_TBU2_WPC2_WTSEL2_WIDTH             (3U)
#define GTMDI_TBU2_WPC2_WTSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC2_WTSEL2_SHIFT)) & GTMDI_TBU2_WPC2_WTSEL2_MASK)

#define GTMDI_TBU2_WPC2_SEN1_MASK                (0x10000U)
#define GTMDI_TBU2_WPC2_SEN1_SHIFT               (16U)
#define GTMDI_TBU2_WPC2_SEN1_WIDTH               (1U)
#define GTMDI_TBU2_WPC2_SEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC2_SEN1_SHIFT)) & GTMDI_TBU2_WPC2_SEN1_MASK)

#define GTMDI_TBU2_WPC2_TEN1_MASK                (0x20000U)
#define GTMDI_TBU2_WPC2_TEN1_SHIFT               (17U)
#define GTMDI_TBU2_WPC2_TEN1_WIDTH               (1U)
#define GTMDI_TBU2_WPC2_TEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC2_TEN1_SHIFT)) & GTMDI_TBU2_WPC2_TEN1_MASK)

#define GTMDI_TBU2_WPC2_STSEL1_MASK              (0x300000U)
#define GTMDI_TBU2_WPC2_STSEL1_SHIFT             (20U)
#define GTMDI_TBU2_WPC2_STSEL1_WIDTH             (2U)
#define GTMDI_TBU2_WPC2_STSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC2_STSEL1_SHIFT)) & GTMDI_TBU2_WPC2_STSEL1_MASK)

#define GTMDI_TBU2_WPC2_WTSEL1_MASK              (0x70000000U)
#define GTMDI_TBU2_WPC2_WTSEL1_SHIFT             (28U)
#define GTMDI_TBU2_WPC2_WTSEL1_WIDTH             (3U)
#define GTMDI_TBU2_WPC2_WTSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_WPC2_WTSEL1_SHIFT)) & GTMDI_TBU2_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name TBU2_D - TBUn Watchpoint DATA */
/*! @{ */

#define GTMDI_TBU2_D_TBUn_DATA_MASK              (0xFFFFFFU)
#define GTMDI_TBU2_D_TBUn_DATA_SHIFT             (0U)
#define GTMDI_TBU2_D_TBUn_DATA_WIDTH             (24U)
#define GTMDI_TBU2_D_TBUn_DATA(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU2_D_TBUn_DATA_SHIFT)) & GTMDI_TBU2_D_TBUn_DATA_MASK)
/*! @} */

/*! @name TBU3_WPC1 - TBUn Watchpoint Control 1 */
/*! @{ */

#define GTMDI_TBU3_WPC1_WMC2_MASK                (0x40U)
#define GTMDI_TBU3_WPC1_WMC2_SHIFT               (6U)
#define GTMDI_TBU3_WPC1_WMC2_WIDTH               (1U)
#define GTMDI_TBU3_WPC1_WMC2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC1_WMC2_SHIFT)) & GTMDI_TBU3_WPC1_WMC2_MASK)

#define GTMDI_TBU3_WPC1_HEN2_MASK                (0x80U)
#define GTMDI_TBU3_WPC1_HEN2_SHIFT               (7U)
#define GTMDI_TBU3_WPC1_HEN2_WIDTH               (1U)
#define GTMDI_TBU3_WPC1_HEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC1_HEN2_SHIFT)) & GTMDI_TBU3_WPC1_HEN2_MASK)

#define GTMDI_TBU3_WPC1_TSS2_MASK                (0x3000U)
#define GTMDI_TBU3_WPC1_TSS2_SHIFT               (12U)
#define GTMDI_TBU3_WPC1_TSS2_WIDTH               (2U)
#define GTMDI_TBU3_WPC1_TSS2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC1_TSS2_SHIFT)) & GTMDI_TBU3_WPC1_TSS2_MASK)

#define GTMDI_TBU3_WPC1_WMC1_MASK                (0x400000U)
#define GTMDI_TBU3_WPC1_WMC1_SHIFT               (22U)
#define GTMDI_TBU3_WPC1_WMC1_WIDTH               (1U)
#define GTMDI_TBU3_WPC1_WMC1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC1_WMC1_SHIFT)) & GTMDI_TBU3_WPC1_WMC1_MASK)

#define GTMDI_TBU3_WPC1_HEN1_MASK                (0x800000U)
#define GTMDI_TBU3_WPC1_HEN1_SHIFT               (23U)
#define GTMDI_TBU3_WPC1_HEN1_WIDTH               (1U)
#define GTMDI_TBU3_WPC1_HEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC1_HEN1_SHIFT)) & GTMDI_TBU3_WPC1_HEN1_MASK)

#define GTMDI_TBU3_WPC1_TSS1_MASK                (0x30000000U)
#define GTMDI_TBU3_WPC1_TSS1_SHIFT               (28U)
#define GTMDI_TBU3_WPC1_TSS1_WIDTH               (2U)
#define GTMDI_TBU3_WPC1_TSS1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC1_TSS1_SHIFT)) & GTMDI_TBU3_WPC1_TSS1_MASK)
/*! @} */

/*! @name TBU3_WPC2 - TBUn Watchpoint Control 2 */
/*! @{ */

#define GTMDI_TBU3_WPC2_SEN2_MASK                (0x1U)
#define GTMDI_TBU3_WPC2_SEN2_SHIFT               (0U)
#define GTMDI_TBU3_WPC2_SEN2_WIDTH               (1U)
#define GTMDI_TBU3_WPC2_SEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC2_SEN2_SHIFT)) & GTMDI_TBU3_WPC2_SEN2_MASK)

#define GTMDI_TBU3_WPC2_TEN2_MASK                (0x2U)
#define GTMDI_TBU3_WPC2_TEN2_SHIFT               (1U)
#define GTMDI_TBU3_WPC2_TEN2_WIDTH               (1U)
#define GTMDI_TBU3_WPC2_TEN2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC2_TEN2_SHIFT)) & GTMDI_TBU3_WPC2_TEN2_MASK)

#define GTMDI_TBU3_WPC2_STSEL2_MASK              (0x30U)
#define GTMDI_TBU3_WPC2_STSEL2_SHIFT             (4U)
#define GTMDI_TBU3_WPC2_STSEL2_WIDTH             (2U)
#define GTMDI_TBU3_WPC2_STSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC2_STSEL2_SHIFT)) & GTMDI_TBU3_WPC2_STSEL2_MASK)

#define GTMDI_TBU3_WPC2_WTSEL2_MASK              (0x7000U)
#define GTMDI_TBU3_WPC2_WTSEL2_SHIFT             (12U)
#define GTMDI_TBU3_WPC2_WTSEL2_WIDTH             (3U)
#define GTMDI_TBU3_WPC2_WTSEL2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC2_WTSEL2_SHIFT)) & GTMDI_TBU3_WPC2_WTSEL2_MASK)

#define GTMDI_TBU3_WPC2_SEN1_MASK                (0x10000U)
#define GTMDI_TBU3_WPC2_SEN1_SHIFT               (16U)
#define GTMDI_TBU3_WPC2_SEN1_WIDTH               (1U)
#define GTMDI_TBU3_WPC2_SEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC2_SEN1_SHIFT)) & GTMDI_TBU3_WPC2_SEN1_MASK)

#define GTMDI_TBU3_WPC2_TEN1_MASK                (0x20000U)
#define GTMDI_TBU3_WPC2_TEN1_SHIFT               (17U)
#define GTMDI_TBU3_WPC2_TEN1_WIDTH               (1U)
#define GTMDI_TBU3_WPC2_TEN1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC2_TEN1_SHIFT)) & GTMDI_TBU3_WPC2_TEN1_MASK)

#define GTMDI_TBU3_WPC2_STSEL1_MASK              (0x300000U)
#define GTMDI_TBU3_WPC2_STSEL1_SHIFT             (20U)
#define GTMDI_TBU3_WPC2_STSEL1_WIDTH             (2U)
#define GTMDI_TBU3_WPC2_STSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC2_STSEL1_SHIFT)) & GTMDI_TBU3_WPC2_STSEL1_MASK)

#define GTMDI_TBU3_WPC2_WTSEL1_MASK              (0x70000000U)
#define GTMDI_TBU3_WPC2_WTSEL1_SHIFT             (28U)
#define GTMDI_TBU3_WPC2_WTSEL1_WIDTH             (3U)
#define GTMDI_TBU3_WPC2_WTSEL1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_WPC2_WTSEL1_SHIFT)) & GTMDI_TBU3_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name TBU3_D - TBUn Watchpoint DATA */
/*! @{ */

#define GTMDI_TBU3_D_TBUn_DATA_MASK              (0xFFFFFFU)
#define GTMDI_TBU3_D_TBUn_DATA_SHIFT             (0U)
#define GTMDI_TBU3_D_TBUn_DATA_WIDTH             (24U)
#define GTMDI_TBU3_D_TBUn_DATA(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TBU3_D_TBUn_DATA_SHIFT)) & GTMDI_TBU3_D_TBUn_DATA_MASK)
/*! @} */

/*! @name TIO_IN_WPC1 - TIO IN watchpoint control register 1 */
/*! @{ */

#define GTMDI_TIO_IN_WPC1_CHSEL2_MASK            (0x7U)
#define GTMDI_TIO_IN_WPC1_CHSEL2_SHIFT           (0U)
#define GTMDI_TIO_IN_WPC1_CHSEL2_WIDTH           (3U)
#define GTMDI_TIO_IN_WPC1_CHSEL2(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC1_CHSEL2_SHIFT)) & GTMDI_TIO_IN_WPC1_CHSEL2_MASK)

#define GTMDI_TIO_IN_WPC1_WMC2_MASK              (0x40U)
#define GTMDI_TIO_IN_WPC1_WMC2_SHIFT             (6U)
#define GTMDI_TIO_IN_WPC1_WMC2_WIDTH             (1U)
#define GTMDI_TIO_IN_WPC1_WMC2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC1_WMC2_SHIFT)) & GTMDI_TIO_IN_WPC1_WMC2_MASK)

#define GTMDI_TIO_IN_WPC1_HEN2_MASK              (0x80U)
#define GTMDI_TIO_IN_WPC1_HEN2_SHIFT             (7U)
#define GTMDI_TIO_IN_WPC1_HEN2_WIDTH             (1U)
#define GTMDI_TIO_IN_WPC1_HEN2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC1_HEN2_SHIFT)) & GTMDI_TIO_IN_WPC1_HEN2_MASK)

#define GTMDI_TIO_IN_WPC1_SSEL2_MASK             (0xF00U)
#define GTMDI_TIO_IN_WPC1_SSEL2_SHIFT            (8U)
#define GTMDI_TIO_IN_WPC1_SSEL2_WIDTH            (4U)
#define GTMDI_TIO_IN_WPC1_SSEL2(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC1_SSEL2_SHIFT)) & GTMDI_TIO_IN_WPC1_SSEL2_MASK)

#define GTMDI_TIO_IN_WPC1_TSS2_MASK              (0x3000U)
#define GTMDI_TIO_IN_WPC1_TSS2_SHIFT             (12U)
#define GTMDI_TIO_IN_WPC1_TSS2_WIDTH             (2U)
#define GTMDI_TIO_IN_WPC1_TSS2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC1_TSS2_SHIFT)) & GTMDI_TIO_IN_WPC1_TSS2_MASK)

#define GTMDI_TIO_IN_WPC1_CHSEL1_MASK            (0x70000U)
#define GTMDI_TIO_IN_WPC1_CHSEL1_SHIFT           (16U)
#define GTMDI_TIO_IN_WPC1_CHSEL1_WIDTH           (3U)
#define GTMDI_TIO_IN_WPC1_CHSEL1(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC1_CHSEL1_SHIFT)) & GTMDI_TIO_IN_WPC1_CHSEL1_MASK)

#define GTMDI_TIO_IN_WPC1_WMC1_MASK              (0x400000U)
#define GTMDI_TIO_IN_WPC1_WMC1_SHIFT             (22U)
#define GTMDI_TIO_IN_WPC1_WMC1_WIDTH             (1U)
#define GTMDI_TIO_IN_WPC1_WMC1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC1_WMC1_SHIFT)) & GTMDI_TIO_IN_WPC1_WMC1_MASK)

#define GTMDI_TIO_IN_WPC1_HEN1_MASK              (0x800000U)
#define GTMDI_TIO_IN_WPC1_HEN1_SHIFT             (23U)
#define GTMDI_TIO_IN_WPC1_HEN1_WIDTH             (1U)
#define GTMDI_TIO_IN_WPC1_HEN1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC1_HEN1_SHIFT)) & GTMDI_TIO_IN_WPC1_HEN1_MASK)

#define GTMDI_TIO_IN_WPC1_SSEL1_MASK             (0xF000000U)
#define GTMDI_TIO_IN_WPC1_SSEL1_SHIFT            (24U)
#define GTMDI_TIO_IN_WPC1_SSEL1_WIDTH            (4U)
#define GTMDI_TIO_IN_WPC1_SSEL1(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC1_SSEL1_SHIFT)) & GTMDI_TIO_IN_WPC1_SSEL1_MASK)

#define GTMDI_TIO_IN_WPC1_TSS1_MASK              (0x30000000U)
#define GTMDI_TIO_IN_WPC1_TSS1_SHIFT             (28U)
#define GTMDI_TIO_IN_WPC1_TSS1_WIDTH             (2U)
#define GTMDI_TIO_IN_WPC1_TSS1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC1_TSS1_SHIFT)) & GTMDI_TIO_IN_WPC1_TSS1_MASK)
/*! @} */

/*! @name TIO_IN_WPC2 - TIO IN watchpoint control register 2 */
/*! @{ */

#define GTMDI_TIO_IN_WPC2_SEN2_MASK              (0x1U)
#define GTMDI_TIO_IN_WPC2_SEN2_SHIFT             (0U)
#define GTMDI_TIO_IN_WPC2_SEN2_WIDTH             (1U)
#define GTMDI_TIO_IN_WPC2_SEN2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC2_SEN2_SHIFT)) & GTMDI_TIO_IN_WPC2_SEN2_MASK)

#define GTMDI_TIO_IN_WPC2_TEN2_MASK              (0x2U)
#define GTMDI_TIO_IN_WPC2_TEN2_SHIFT             (1U)
#define GTMDI_TIO_IN_WPC2_TEN2_WIDTH             (1U)
#define GTMDI_TIO_IN_WPC2_TEN2(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC2_TEN2_SHIFT)) & GTMDI_TIO_IN_WPC2_TEN2_MASK)

#define GTMDI_TIO_IN_WPC2_STSEL2_MASK            (0x30U)
#define GTMDI_TIO_IN_WPC2_STSEL2_SHIFT           (4U)
#define GTMDI_TIO_IN_WPC2_STSEL2_WIDTH           (2U)
#define GTMDI_TIO_IN_WPC2_STSEL2(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC2_STSEL2_SHIFT)) & GTMDI_TIO_IN_WPC2_STSEL2_MASK)

#define GTMDI_TIO_IN_WPC2_WTSEL2_MASK            (0x7000U)
#define GTMDI_TIO_IN_WPC2_WTSEL2_SHIFT           (12U)
#define GTMDI_TIO_IN_WPC2_WTSEL2_WIDTH           (3U)
#define GTMDI_TIO_IN_WPC2_WTSEL2(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC2_WTSEL2_SHIFT)) & GTMDI_TIO_IN_WPC2_WTSEL2_MASK)

#define GTMDI_TIO_IN_WPC2_SEN1_MASK              (0x10000U)
#define GTMDI_TIO_IN_WPC2_SEN1_SHIFT             (16U)
#define GTMDI_TIO_IN_WPC2_SEN1_WIDTH             (1U)
#define GTMDI_TIO_IN_WPC2_SEN1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC2_SEN1_SHIFT)) & GTMDI_TIO_IN_WPC2_SEN1_MASK)

#define GTMDI_TIO_IN_WPC2_TEN1_MASK              (0x20000U)
#define GTMDI_TIO_IN_WPC2_TEN1_SHIFT             (17U)
#define GTMDI_TIO_IN_WPC2_TEN1_WIDTH             (1U)
#define GTMDI_TIO_IN_WPC2_TEN1(x)                (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC2_TEN1_SHIFT)) & GTMDI_TIO_IN_WPC2_TEN1_MASK)

#define GTMDI_TIO_IN_WPC2_STSEL1_MASK            (0x300000U)
#define GTMDI_TIO_IN_WPC2_STSEL1_SHIFT           (20U)
#define GTMDI_TIO_IN_WPC2_STSEL1_WIDTH           (2U)
#define GTMDI_TIO_IN_WPC2_STSEL1(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC2_STSEL1_SHIFT)) & GTMDI_TIO_IN_WPC2_STSEL1_MASK)

#define GTMDI_TIO_IN_WPC2_WTSEL1_MASK            (0x70000000U)
#define GTMDI_TIO_IN_WPC2_WTSEL1_SHIFT           (28U)
#define GTMDI_TIO_IN_WPC2_WTSEL1_WIDTH           (3U)
#define GTMDI_TIO_IN_WPC2_WTSEL1(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_IN_WPC2_WTSEL1_SHIFT)) & GTMDI_TIO_IN_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name TIO_OUT_WPC1 - TIO OUT Watchpoint Control 1 */
/*! @{ */

#define GTMDI_TIO_OUT_WPC1_CHSEL2_MASK           (0xFU)
#define GTMDI_TIO_OUT_WPC1_CHSEL2_SHIFT          (0U)
#define GTMDI_TIO_OUT_WPC1_CHSEL2_WIDTH          (4U)
#define GTMDI_TIO_OUT_WPC1_CHSEL2(x)             (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_CHSEL2_SHIFT)) & GTMDI_TIO_OUT_WPC1_CHSEL2_MASK)

#define GTMDI_TIO_OUT_WPC1_WMC2_MASK             (0x40U)
#define GTMDI_TIO_OUT_WPC1_WMC2_SHIFT            (6U)
#define GTMDI_TIO_OUT_WPC1_WMC2_WIDTH            (1U)
#define GTMDI_TIO_OUT_WPC1_WMC2(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_WMC2_SHIFT)) & GTMDI_TIO_OUT_WPC1_WMC2_MASK)

#define GTMDI_TIO_OUT_WPC1_HEN2_MASK             (0x80U)
#define GTMDI_TIO_OUT_WPC1_HEN2_SHIFT            (7U)
#define GTMDI_TIO_OUT_WPC1_HEN2_WIDTH            (1U)
#define GTMDI_TIO_OUT_WPC1_HEN2(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_HEN2_SHIFT)) & GTMDI_TIO_OUT_WPC1_HEN2_MASK)

#define GTMDI_TIO_OUT_WPC1_SSEL2_MASK            (0xF00U)
#define GTMDI_TIO_OUT_WPC1_SSEL2_SHIFT           (8U)
#define GTMDI_TIO_OUT_WPC1_SSEL2_WIDTH           (4U)
#define GTMDI_TIO_OUT_WPC1_SSEL2(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_SSEL2_SHIFT)) & GTMDI_TIO_OUT_WPC1_SSEL2_MASK)

#define GTMDI_TIO_OUT_WPC1_TSS2_MASK             (0x3000U)
#define GTMDI_TIO_OUT_WPC1_TSS2_SHIFT            (12U)
#define GTMDI_TIO_OUT_WPC1_TSS2_WIDTH            (2U)
#define GTMDI_TIO_OUT_WPC1_TSS2(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_TSS2_SHIFT)) & GTMDI_TIO_OUT_WPC1_TSS2_MASK)

#define GTMDI_TIO_OUT_WPC1_POL2_MASK             (0x8000U)
#define GTMDI_TIO_OUT_WPC1_POL2_SHIFT            (15U)
#define GTMDI_TIO_OUT_WPC1_POL2_WIDTH            (1U)
#define GTMDI_TIO_OUT_WPC1_POL2(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_POL2_SHIFT)) & GTMDI_TIO_OUT_WPC1_POL2_MASK)

#define GTMDI_TIO_OUT_WPC1_CHSEL1_MASK           (0xF0000U)
#define GTMDI_TIO_OUT_WPC1_CHSEL1_SHIFT          (16U)
#define GTMDI_TIO_OUT_WPC1_CHSEL1_WIDTH          (4U)
#define GTMDI_TIO_OUT_WPC1_CHSEL1(x)             (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_CHSEL1_SHIFT)) & GTMDI_TIO_OUT_WPC1_CHSEL1_MASK)

#define GTMDI_TIO_OUT_WPC1_WMC1_MASK             (0x400000U)
#define GTMDI_TIO_OUT_WPC1_WMC1_SHIFT            (22U)
#define GTMDI_TIO_OUT_WPC1_WMC1_WIDTH            (1U)
#define GTMDI_TIO_OUT_WPC1_WMC1(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_WMC1_SHIFT)) & GTMDI_TIO_OUT_WPC1_WMC1_MASK)

#define GTMDI_TIO_OUT_WPC1_HEN1_MASK             (0x800000U)
#define GTMDI_TIO_OUT_WPC1_HEN1_SHIFT            (23U)
#define GTMDI_TIO_OUT_WPC1_HEN1_WIDTH            (1U)
#define GTMDI_TIO_OUT_WPC1_HEN1(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_HEN1_SHIFT)) & GTMDI_TIO_OUT_WPC1_HEN1_MASK)

#define GTMDI_TIO_OUT_WPC1_SSEL1_MASK            (0xF000000U)
#define GTMDI_TIO_OUT_WPC1_SSEL1_SHIFT           (24U)
#define GTMDI_TIO_OUT_WPC1_SSEL1_WIDTH           (4U)
#define GTMDI_TIO_OUT_WPC1_SSEL1(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_SSEL1_SHIFT)) & GTMDI_TIO_OUT_WPC1_SSEL1_MASK)

#define GTMDI_TIO_OUT_WPC1_TSS1_MASK             (0x30000000U)
#define GTMDI_TIO_OUT_WPC1_TSS1_SHIFT            (28U)
#define GTMDI_TIO_OUT_WPC1_TSS1_WIDTH            (2U)
#define GTMDI_TIO_OUT_WPC1_TSS1(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_TSS1_SHIFT)) & GTMDI_TIO_OUT_WPC1_TSS1_MASK)

#define GTMDI_TIO_OUT_WPC1_POL1_MASK             (0x80000000U)
#define GTMDI_TIO_OUT_WPC1_POL1_SHIFT            (31U)
#define GTMDI_TIO_OUT_WPC1_POL1_WIDTH            (1U)
#define GTMDI_TIO_OUT_WPC1_POL1(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC1_POL1_SHIFT)) & GTMDI_TIO_OUT_WPC1_POL1_MASK)
/*! @} */

/*! @name TIO_OUT_WPC2 - TIO OUT Watchpoint Control 2 */
/*! @{ */

#define GTMDI_TIO_OUT_WPC2_SEN2_MASK             (0x1U)
#define GTMDI_TIO_OUT_WPC2_SEN2_SHIFT            (0U)
#define GTMDI_TIO_OUT_WPC2_SEN2_WIDTH            (1U)
#define GTMDI_TIO_OUT_WPC2_SEN2(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC2_SEN2_SHIFT)) & GTMDI_TIO_OUT_WPC2_SEN2_MASK)

#define GTMDI_TIO_OUT_WPC2_TEN2_MASK             (0x2U)
#define GTMDI_TIO_OUT_WPC2_TEN2_SHIFT            (1U)
#define GTMDI_TIO_OUT_WPC2_TEN2_WIDTH            (1U)
#define GTMDI_TIO_OUT_WPC2_TEN2(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC2_TEN2_SHIFT)) & GTMDI_TIO_OUT_WPC2_TEN2_MASK)

#define GTMDI_TIO_OUT_WPC2_STSEL2_MASK           (0x30U)
#define GTMDI_TIO_OUT_WPC2_STSEL2_SHIFT          (4U)
#define GTMDI_TIO_OUT_WPC2_STSEL2_WIDTH          (2U)
#define GTMDI_TIO_OUT_WPC2_STSEL2(x)             (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC2_STSEL2_SHIFT)) & GTMDI_TIO_OUT_WPC2_STSEL2_MASK)

#define GTMDI_TIO_OUT_WPC2_WTSEL2_MASK           (0x7000U)
#define GTMDI_TIO_OUT_WPC2_WTSEL2_SHIFT          (12U)
#define GTMDI_TIO_OUT_WPC2_WTSEL2_WIDTH          (3U)
#define GTMDI_TIO_OUT_WPC2_WTSEL2(x)             (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC2_WTSEL2_SHIFT)) & GTMDI_TIO_OUT_WPC2_WTSEL2_MASK)

#define GTMDI_TIO_OUT_WPC2_SEN1_MASK             (0x10000U)
#define GTMDI_TIO_OUT_WPC2_SEN1_SHIFT            (16U)
#define GTMDI_TIO_OUT_WPC2_SEN1_WIDTH            (1U)
#define GTMDI_TIO_OUT_WPC2_SEN1(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC2_SEN1_SHIFT)) & GTMDI_TIO_OUT_WPC2_SEN1_MASK)

#define GTMDI_TIO_OUT_WPC2_TEN1_MASK             (0x20000U)
#define GTMDI_TIO_OUT_WPC2_TEN1_SHIFT            (17U)
#define GTMDI_TIO_OUT_WPC2_TEN1_WIDTH            (1U)
#define GTMDI_TIO_OUT_WPC2_TEN1(x)               (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC2_TEN1_SHIFT)) & GTMDI_TIO_OUT_WPC2_TEN1_MASK)

#define GTMDI_TIO_OUT_WPC2_STSEL1_MASK           (0x300000U)
#define GTMDI_TIO_OUT_WPC2_STSEL1_SHIFT          (20U)
#define GTMDI_TIO_OUT_WPC2_STSEL1_WIDTH          (2U)
#define GTMDI_TIO_OUT_WPC2_STSEL1(x)             (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC2_STSEL1_SHIFT)) & GTMDI_TIO_OUT_WPC2_STSEL1_MASK)

#define GTMDI_TIO_OUT_WPC2_WTSEL1_MASK           (0x70000000U)
#define GTMDI_TIO_OUT_WPC2_WTSEL1_SHIFT          (28U)
#define GTMDI_TIO_OUT_WPC2_WTSEL1_WIDTH          (3U)
#define GTMDI_TIO_OUT_WPC2_WTSEL1(x)             (((uint32_t)(((uint32_t)(x)) << GTMDI_TIO_OUT_WPC2_WTSEL1_SHIFT)) & GTMDI_TIO_OUT_WPC2_WTSEL1_MASK)
/*! @} */

/*! @name ATID - ATB Bus ID Control */
/*! @{ */

#define GTMDI_ATID_ATID_MASK                     (0x7FU)
#define GTMDI_ATID_ATID_SHIFT                    (0U)
#define GTMDI_ATID_ATID_WIDTH                    (7U)
#define GTMDI_ATID_ATID(x)                       (((uint32_t)(((uint32_t)(x)) << GTMDI_ATID_ATID_SHIFT)) & GTMDI_ATID_ATID_MASK)
/*! @} */

/*! @name DEVARCH - Device Architecture */
/*! @{ */

#define GTMDI_DEVARCH_ARCHID_MASK                (0xFFFFU)
#define GTMDI_DEVARCH_ARCHID_SHIFT               (0U)
#define GTMDI_DEVARCH_ARCHID_WIDTH               (16U)
#define GTMDI_DEVARCH_ARCHID(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_DEVARCH_ARCHID_SHIFT)) & GTMDI_DEVARCH_ARCHID_MASK)

#define GTMDI_DEVARCH_ARCHREV_MASK               (0xF0000U)
#define GTMDI_DEVARCH_ARCHREV_SHIFT              (16U)
#define GTMDI_DEVARCH_ARCHREV_WIDTH              (4U)
#define GTMDI_DEVARCH_ARCHREV(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_DEVARCH_ARCHREV_SHIFT)) & GTMDI_DEVARCH_ARCHREV_MASK)

#define GTMDI_DEVARCH_PRESENT_MASK               (0x100000U)
#define GTMDI_DEVARCH_PRESENT_SHIFT              (20U)
#define GTMDI_DEVARCH_PRESENT_WIDTH              (1U)
#define GTMDI_DEVARCH_PRESENT(x)                 (((uint32_t)(((uint32_t)(x)) << GTMDI_DEVARCH_PRESENT_SHIFT)) & GTMDI_DEVARCH_PRESENT_MASK)

#define GTMDI_DEVARCH_ARCHITECT1_MASK            (0xFE00000U)
#define GTMDI_DEVARCH_ARCHITECT1_SHIFT           (21U)
#define GTMDI_DEVARCH_ARCHITECT1_WIDTH           (7U)
#define GTMDI_DEVARCH_ARCHITECT1(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_DEVARCH_ARCHITECT1_SHIFT)) & GTMDI_DEVARCH_ARCHITECT1_MASK)

#define GTMDI_DEVARCH_ARCHITECT2_MASK            (0xF0000000U)
#define GTMDI_DEVARCH_ARCHITECT2_SHIFT           (28U)
#define GTMDI_DEVARCH_ARCHITECT2_WIDTH           (4U)
#define GTMDI_DEVARCH_ARCHITECT2(x)              (((uint32_t)(((uint32_t)(x)) << GTMDI_DEVARCH_ARCHITECT2_SHIFT)) & GTMDI_DEVARCH_ARCHITECT2_MASK)
/*! @} */

/*! @name DEVTYPE - Device Type Identifier */
/*! @{ */

#define GTMDI_DEVTYPE_MAJOR_MASK                 (0xFU)
#define GTMDI_DEVTYPE_MAJOR_SHIFT                (0U)
#define GTMDI_DEVTYPE_MAJOR_WIDTH                (4U)
#define GTMDI_DEVTYPE_MAJOR(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_DEVTYPE_MAJOR_SHIFT)) & GTMDI_DEVTYPE_MAJOR_MASK)

#define GTMDI_DEVTYPE_SUB_MASK                   (0xF0U)
#define GTMDI_DEVTYPE_SUB_SHIFT                  (4U)
#define GTMDI_DEVTYPE_SUB_WIDTH                  (4U)
#define GTMDI_DEVTYPE_SUB(x)                     (((uint32_t)(((uint32_t)(x)) << GTMDI_DEVTYPE_SUB_SHIFT)) & GTMDI_DEVTYPE_SUB_MASK)
/*! @} */

/*! @name PIDR4 - Peripheral Identification 4 */
/*! @{ */

#define GTMDI_PIDR4_DES_2_MASK                   (0xFU)
#define GTMDI_PIDR4_DES_2_SHIFT                  (0U)
#define GTMDI_PIDR4_DES_2_WIDTH                  (4U)
#define GTMDI_PIDR4_DES_2(x)                     (((uint32_t)(((uint32_t)(x)) << GTMDI_PIDR4_DES_2_SHIFT)) & GTMDI_PIDR4_DES_2_MASK)

#define GTMDI_PIDR4_SIZE_MASK                    (0xF0U)
#define GTMDI_PIDR4_SIZE_SHIFT                   (4U)
#define GTMDI_PIDR4_SIZE_WIDTH                   (4U)
#define GTMDI_PIDR4_SIZE(x)                      (((uint32_t)(((uint32_t)(x)) << GTMDI_PIDR4_SIZE_SHIFT)) & GTMDI_PIDR4_SIZE_MASK)
/*! @} */

/*! @name PIDR0 - Peripheral Identification 0 */
/*! @{ */

#define GTMDI_PIDR0_PART_0_MASK                  (0xFFU)
#define GTMDI_PIDR0_PART_0_SHIFT                 (0U)
#define GTMDI_PIDR0_PART_0_WIDTH                 (8U)
#define GTMDI_PIDR0_PART_0(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_PIDR0_PART_0_SHIFT)) & GTMDI_PIDR0_PART_0_MASK)
/*! @} */

/*! @name PIDR1 - Peripheral Identification 1 */
/*! @{ */

#define GTMDI_PIDR1_PART_1_MASK                  (0xFU)
#define GTMDI_PIDR1_PART_1_SHIFT                 (0U)
#define GTMDI_PIDR1_PART_1_WIDTH                 (4U)
#define GTMDI_PIDR1_PART_1(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_PIDR1_PART_1_SHIFT)) & GTMDI_PIDR1_PART_1_MASK)

#define GTMDI_PIDR1_DES_0_MASK                   (0xF0U)
#define GTMDI_PIDR1_DES_0_SHIFT                  (4U)
#define GTMDI_PIDR1_DES_0_WIDTH                  (4U)
#define GTMDI_PIDR1_DES_0(x)                     (((uint32_t)(((uint32_t)(x)) << GTMDI_PIDR1_DES_0_SHIFT)) & GTMDI_PIDR1_DES_0_MASK)
/*! @} */

/*! @name PIDR2 - Peripheral Identification 2 */
/*! @{ */

#define GTMDI_PIDR2_DES_1_MASK                   (0x7U)
#define GTMDI_PIDR2_DES_1_SHIFT                  (0U)
#define GTMDI_PIDR2_DES_1_WIDTH                  (3U)
#define GTMDI_PIDR2_DES_1(x)                     (((uint32_t)(((uint32_t)(x)) << GTMDI_PIDR2_DES_1_SHIFT)) & GTMDI_PIDR2_DES_1_MASK)

#define GTMDI_PIDR2_JEDEC_MASK                   (0x8U)
#define GTMDI_PIDR2_JEDEC_SHIFT                  (3U)
#define GTMDI_PIDR2_JEDEC_WIDTH                  (1U)
#define GTMDI_PIDR2_JEDEC(x)                     (((uint32_t)(((uint32_t)(x)) << GTMDI_PIDR2_JEDEC_SHIFT)) & GTMDI_PIDR2_JEDEC_MASK)

#define GTMDI_PIDR2_Revision_MASK                (0xF0U)
#define GTMDI_PIDR2_Revision_SHIFT               (4U)
#define GTMDI_PIDR2_Revision_WIDTH               (4U)
#define GTMDI_PIDR2_Revision(x)                  (((uint32_t)(((uint32_t)(x)) << GTMDI_PIDR2_Revision_SHIFT)) & GTMDI_PIDR2_Revision_MASK)
/*! @} */

/*! @name PIDR3 - Peripheral Identification 3 */
/*! @{ */

#define GTMDI_PIDR3_CMOD_MASK                    (0xFU)
#define GTMDI_PIDR3_CMOD_SHIFT                   (0U)
#define GTMDI_PIDR3_CMOD_WIDTH                   (4U)
#define GTMDI_PIDR3_CMOD(x)                      (((uint32_t)(((uint32_t)(x)) << GTMDI_PIDR3_CMOD_SHIFT)) & GTMDI_PIDR3_CMOD_MASK)

#define GTMDI_PIDR3_REVAND_MASK                  (0xF0U)
#define GTMDI_PIDR3_REVAND_SHIFT                 (4U)
#define GTMDI_PIDR3_REVAND_WIDTH                 (4U)
#define GTMDI_PIDR3_REVAND(x)                    (((uint32_t)(((uint32_t)(x)) << GTMDI_PIDR3_REVAND_SHIFT)) & GTMDI_PIDR3_REVAND_MASK)
/*! @} */

/*! @name CIDR0 - Component Identification 0 */
/*! @{ */

#define GTMDI_CIDR0_PRMBL_1_MASK                 (0xFFU)
#define GTMDI_CIDR0_PRMBL_1_SHIFT                (0U)
#define GTMDI_CIDR0_PRMBL_1_WIDTH                (8U)
#define GTMDI_CIDR0_PRMBL_1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_CIDR0_PRMBL_1_SHIFT)) & GTMDI_CIDR0_PRMBL_1_MASK)
/*! @} */

/*! @name CIDR1 - Component Identification 1 */
/*! @{ */

#define GTMDI_CIDR1_PRMBL_1_MASK                 (0xFU)
#define GTMDI_CIDR1_PRMBL_1_SHIFT                (0U)
#define GTMDI_CIDR1_PRMBL_1_WIDTH                (4U)
#define GTMDI_CIDR1_PRMBL_1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_CIDR1_PRMBL_1_SHIFT)) & GTMDI_CIDR1_PRMBL_1_MASK)

#define GTMDI_CIDR1_Class_MASK                   (0xF0U)
#define GTMDI_CIDR1_Class_SHIFT                  (4U)
#define GTMDI_CIDR1_Class_WIDTH                  (4U)
#define GTMDI_CIDR1_Class(x)                     (((uint32_t)(((uint32_t)(x)) << GTMDI_CIDR1_Class_SHIFT)) & GTMDI_CIDR1_Class_MASK)
/*! @} */

/*! @name CIDR2 - Component Identification 2 */
/*! @{ */

#define GTMDI_CIDR2_PRMBL_2_MASK                 (0xFFU)
#define GTMDI_CIDR2_PRMBL_2_SHIFT                (0U)
#define GTMDI_CIDR2_PRMBL_2_WIDTH                (8U)
#define GTMDI_CIDR2_PRMBL_2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_CIDR2_PRMBL_2_SHIFT)) & GTMDI_CIDR2_PRMBL_2_MASK)
/*! @} */

/*! @name CIDR3 - Component Identification 3 */
/*! @{ */

#define GTMDI_CIDR3_PRMBL_3_MASK                 (0xFFU)
#define GTMDI_CIDR3_PRMBL_3_SHIFT                (0U)
#define GTMDI_CIDR3_PRMBL_3_WIDTH                (8U)
#define GTMDI_CIDR3_PRMBL_3(x)                   (((uint32_t)(((uint32_t)(x)) << GTMDI_CIDR3_PRMBL_3_SHIFT)) & GTMDI_CIDR3_PRMBL_3_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group GTMDI_Register_Masks */

/*!
 * @}
 */ /* end of group GTMDI_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_GTMDI_H_) */
