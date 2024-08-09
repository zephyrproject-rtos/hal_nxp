/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_DDRC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_DDRC
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
#if !defined(S32Z2_DDRC_H_)  /* Check if memory map has not been already included */
#define S32Z2_DDRC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DDRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDRC_Peripheral_Access_Layer DDRC Peripheral Access Layer
 * @{
 */

/** DDRC - Size of Registers Arrays */
#define DDRC_CS_BNDS_COUNT                        2u
#define DDRC_CS_CONFIG_COUNT                      2u
#define DDRC_DDR_MTP_COUNT                        10u

/** DDRC - Register Layout Typedef */
typedef struct {
  struct DDRC_CS_BNDS {                            /* offset: 0x0, array step: 0x8 */
    __IO uint32_t CS_BNDS;                           /**< Rank 0 Memory Bounds..Rank 1 Memory Bounds, array offset: 0x0, array step: 0x8 */
    uint8_t RESERVED_0[4];
  } CS_BNDS[DDRC_CS_BNDS_COUNT];
  uint8_t RESERVED_0[16];
  __IO uint32_t REMAP_0A;                          /**< Remap Region 0A Configuration, offset: 0x20 */
  __IO uint32_t REMAP_0B;                          /**< Remap Region 0B Configuration, offset: 0x24 */
  __IO uint32_t REMAP_1A;                          /**< Remap Region 1A Configuration, offset: 0x28 */
  __IO uint32_t REMAP_1B;                          /**< Remap Region 1B Configuration, offset: 0x2C */
  __IO uint32_t REMAP_2A;                          /**< Remap Region 2A Configuration, offset: 0x30 */
  __IO uint32_t REMAP_2B;                          /**< Remap Region 2B Configuration, offset: 0x34 */
  __IO uint32_t REMAP_3A;                          /**< Remap Region 3A Configuration, offset: 0x38 */
  __IO uint32_t REMAP_3B;                          /**< Remap Region 3B Configuration, offset: 0x3C */
  __IO uint32_t DDR_ADDR_DEC_0;                    /**< DDRC Address Decode 0, offset: 0x40 */
  __IO uint32_t DDR_ADDR_DEC_1;                    /**< DDRC Address Decode 1, offset: 0x44 */
  __IO uint32_t DDR_ADDR_DEC_2;                    /**< DDRC Address Decode 2, offset: 0x48 */
  __IO uint32_t DDR_ADDR_DEC_3;                    /**< DDRC Address Decode 3, offset: 0x4C */
  __IO uint32_t DDR_ADDR_DEC_4;                    /**< DDRC Address Decode 4, offset: 0x50 */
  __IO uint32_t DDR_ADDR_DEC_5;                    /**< DDRC Address Decode 5, offset: 0x54 */
  __IO uint32_t DDR_ADDR_DEC_6;                    /**< DDRC Address Decode 6, offset: 0x58 */
  __IO uint32_t DDR_ADDR_DEC_7;                    /**< DDRC Address Decode 7, offset: 0x5C */
  __IO uint32_t DDR_ADDR_DEC_8;                    /**< DDRC Address Decode 8, offset: 0x60 */
  __IO uint32_t DDR_ADDR_DEC_9;                    /**< DDRC Address Decode 9, offset: 0x64 */
  uint8_t RESERVED_1[24];
  __IO uint32_t CS_CONFIG[DDRC_CS_CONFIG_COUNT];   /**< Rank 0 Configuration..Rank 1 Configuration, array offset: 0x80, array step: 0x4 */
  uint8_t RESERVED_2[120];
  __IO uint32_t TIMING_CFG_3;                      /**< DDR SDRAM Timing Configuration 3, offset: 0x100 */
  __IO uint32_t TIMING_CFG_0;                      /**< DDR SDRAM Timing Configuration 0, offset: 0x104 */
  __IO uint32_t TIMING_CFG_1;                      /**< DDR SDRAM Timing Configuration 1, offset: 0x108 */
  __IO uint32_t TIMING_CFG_2;                      /**< DDR SDRAM Timing Configuration 2, offset: 0x10C */
  __IO uint32_t DDR_SDRAM_CFG;                     /**< DDR SDRAM Control Configuration, offset: 0x110 */
  __IO uint32_t DDR_SDRAM_CFG_2;                   /**< DDR SDRAM Control Configuration 2, offset: 0x114 */
  uint8_t RESERVED_3[8];
  __IO uint32_t DDR_SDRAM_MD_CNTL;                 /**< DDR SDRAM Mode Control, offset: 0x120 */
  __IO uint32_t DDR_SDRAM_INTERVAL;                /**< DDR SDRAM Interval Configuration, offset: 0x124 */
  __IO uint32_t DDR_DATA_INIT;                     /**< DDR SDRAM Data Initialization, offset: 0x128 */
  uint8_t RESERVED_4[52];
  __IO uint32_t TIMING_CFG_4;                      /**< DDR SDRAM Timing Configuration 4, offset: 0x160 */
  uint8_t RESERVED_5[8];
  __IO uint32_t TIMING_CFG_7;                      /**< DDR SDRAM Timing Configuration 7, offset: 0x16C */
  __IO uint32_t DDR_ZQ_CNTL;                       /**< DDR SDRAM ZQ Calibration Control, offset: 0x170 */
  uint8_t RESERVED_6[8];
  __IO uint32_t DDR_SR_CNTR;                       /**< DDR SDRAM Self-Refresh Counter, offset: 0x17C */
  uint8_t RESERVED_7[208];
  __IO uint32_t TIMING_CFG_8;                      /**< DDR SDRAM Timing Configuration 8, offset: 0x250 */
  __IO uint32_t TIMING_CFG_9;                      /**< DDR SDRAM timing configuration 9, offset: 0x254 */
  uint8_t RESERVED_8[4];
  __IO uint32_t TIMING_CFG_11;                     /**< DDR SDRAM Timing Configuration 11, offset: 0x25C */
  __IO uint32_t DDR_SDRAM_CFG_3;                   /**< DDR SDRAM Control Configuration 3, offset: 0x260 */
  uint8_t RESERVED_9[92];
  __I  uint32_t DDR_SDRAM_REF_RATE;                /**< DDR Refresh Rate, offset: 0x2C0 */
  uint8_t RESERVED_10[1340];
  __IO uint32_t TX_CFG_1;                          /**< Transaction Configuration Register 1, offset: 0x800 */
  uint8_t RESERVED_11[28];
  __IO uint32_t FFI_CFG;                           /**< Freedom From Interference Configuration, offset: 0x820 */
  __IO uint32_t FFI_CFG2;                          /**< Freedom From Interference Configuration 2, offset: 0x824 */
  uint8_t RESERVED_12[764];
  __IO uint32_t DDRDSR_2;                          /**< DDR SDRAM Debug Status 2, offset: 0xB24 */
  uint8_t RESERVED_13[208];
  __I  uint32_t DDR_IP_REV1;                       /**< DDRC Revision 1, offset: 0xBF8 */
  uint8_t RESERVED_14[260];
  __IO uint32_t DDR_MTCR;                          /**< DDR SDRAM Memory Test Control, offset: 0xD00 */
  uint8_t RESERVED_15[28];
  __IO uint32_t DDR_MTP[DDRC_DDR_MTP_COUNT];       /**< DDR SDRAM Memory Test Pattern n, array offset: 0xD20, array step: 0x4 */
  uint8_t RESERVED_16[24];
  __IO uint32_t DDR_MT_ST_EXT_ADDR;                /**< DDR SDRAM Memory Test Start Extended Address, offset: 0xD60 */
  __IO uint32_t DDR_MT_ST_ADDR;                    /**< DDR SDRAM Memory Test Start Address, offset: 0xD64 */
  __IO uint32_t DDR_MT_END_EXT_ADDR;               /**< DDR SDRAM Memory Test End Extended Address, offset: 0xD68 */
  __IO uint32_t DDR_MT_END_ADDR;                   /**< DDR SDRAM Memory Test End Address, offset: 0xD6C */
  uint8_t RESERVED_17[144];
  __IO uint32_t PMGC0;                             /**< Performance Monitor Global Control, offset: 0xE00 */
  uint8_t RESERVED_18[12];
  __IO uint32_t PMLCA0;                            /**< Performance Monitor Local Control A0, offset: 0xE10 */
  __IO uint32_t PMLCB0;                            /**< Performance Monitor Local Control B0, offset: 0xE14 */
  __IO uint32_t PMC0A;                             /**< PMC 0a, offset: 0xE18 */
  __IO uint32_t PMC0B;                             /**< PMC 0b, offset: 0xE1C */
  __IO uint32_t PMLCA1;                            /**< Performance Monitor Local Control A, offset: 0xE20 */
  __IO uint32_t PMLCB1;                            /**< Performance Monitor Local Control B, offset: 0xE24 */
  __IO uint32_t PMC1;                              /**< Performance Monitor Counter, offset: 0xE28 */
  uint8_t RESERVED_19[4];
  __IO uint32_t PMLCA2;                            /**< Performance Monitor Local Control A, offset: 0xE30 */
  __IO uint32_t PMLCB2;                            /**< Performance Monitor Local Control B, offset: 0xE34 */
  __IO uint32_t PMC2;                              /**< Performance Monitor Counter, offset: 0xE38 */
  uint8_t RESERVED_20[4];
  __IO uint32_t PMLCA3;                            /**< Performance Monitor Local Control A, offset: 0xE40 */
  __IO uint32_t PMLCB3;                            /**< Performance Monitor Local Control B, offset: 0xE44 */
  __IO uint32_t PMC3;                              /**< Performance Monitor Counter, offset: 0xE48 */
  uint8_t RESERVED_21[4];
  __IO uint32_t PMLCA4;                            /**< Performance Monitor Local Control A, offset: 0xE50 */
  __IO uint32_t PMLCB4;                            /**< Performance Monitor Local Control B, offset: 0xE54 */
  __IO uint32_t PMC4;                              /**< Performance Monitor Counter, offset: 0xE58 */
  uint8_t RESERVED_22[4];
  __IO uint32_t PMLCA5;                            /**< Performance Monitor Local Control A, offset: 0xE60 */
  __IO uint32_t PMLCB5;                            /**< Performance Monitor Local Control B, offset: 0xE64 */
  __IO uint32_t PMC5;                              /**< Performance Monitor Counter, offset: 0xE68 */
  uint8_t RESERVED_23[4];
  __IO uint32_t PMLCA6;                            /**< Performance Monitor Local Control A, offset: 0xE70 */
  __IO uint32_t PMLCB6;                            /**< Performance Monitor Local Control B, offset: 0xE74 */
  __IO uint32_t PMC6;                              /**< Performance Monitor Counter, offset: 0xE78 */
  uint8_t RESERVED_24[4];
  __IO uint32_t PMLCA7;                            /**< Performance Monitor Local Control A, offset: 0xE80 */
  __IO uint32_t PMLCB7;                            /**< Performance Monitor Local Control B, offset: 0xE84 */
  __IO uint32_t PMC7;                              /**< Performance Monitor Counter, offset: 0xE88 */
  uint8_t RESERVED_25[4];
  __IO uint32_t PMLCA8;                            /**< Performance Monitor Local Control A, offset: 0xE90 */
  __IO uint32_t PMLCB8;                            /**< Performance Monitor Local Control B, offset: 0xE94 */
  __IO uint32_t PMC8;                              /**< Performance Monitor Counter, offset: 0xE98 */
  uint8_t RESERVED_26[4];
  __IO uint32_t PMLCA9;                            /**< Performance Monitor Local Control A, offset: 0xEA0 */
  __IO uint32_t PMLCB9;                            /**< Performance Monitor Local Control B, offset: 0xEA4 */
  __IO uint32_t PMC9;                              /**< Performance Monitor Counter, offset: 0xEA8 */
  uint8_t RESERVED_27[4];
  __IO uint32_t PMLCA10;                           /**< Performance Monitor Local Control A, offset: 0xEB0 */
  __IO uint32_t PMLCB10;                           /**< Performance Monitor Local Control B, offset: 0xEB4 */
  __IO uint32_t PMC10;                             /**< Performance Monitor Counter, offset: 0xEB8 */
  uint8_t RESERVED_28[324];
  __IO uint32_t ERR_EN;                            /**< Error Enable, offset: 0x1000 */
  uint8_t RESERVED_29[252];
  __IO uint32_t DATA_ERR_INJECT_HI;                /**< Memory Data Path Error Injection Mask High, offset: 0x1100 */
  __IO uint32_t DATA_ERR_INJECT_LO;                /**< Memory Data Path Error Injection Mask Low, offset: 0x1104 */
  __IO uint32_t ERR_INJECT;                        /**< Memory Data Path Error Injection Mask ECC, offset: 0x1108 */
  __IO uint32_t ADDR_ERR_INJ;                      /**< Address Error Inject, offset: 0x110C */
  uint8_t RESERVED_30[8];
  __IO uint32_t CAPTURE_EXT_DATA_HI;               /**< Memory Extended Data Path Read Capture High, offset: 0x1118 */
  __IO uint32_t CAPTURE_EXT_DATA_LO;               /**< Memory Extended Data Path Read Capture Low, offset: 0x111C */
  __IO uint32_t CAPTURE_DATA_HI;                   /**< Memory Data Path Read Capture High, offset: 0x1120 */
  __IO uint32_t CAPTURE_DATA_LO;                   /**< Memory Data Path Read Capture Low, offset: 0x1124 */
  __IO uint32_t CAPTURE_ECC;                       /**< Memory Data Path Read Capture ECC, offset: 0x1128 */
  uint8_t RESERVED_31[20];
  __IO uint32_t ERR_DETECT;                        /**< Memory Error Detect, offset: 0x1140 */
  __IO uint32_t ERR_DISABLE;                       /**< Memory Error Disable, offset: 0x1144 */
  __IO uint32_t ERR_INT_EN;                        /**< Memory Error Interrupt Enable, offset: 0x1148 */
  __IO uint32_t CAPTURE_ATTRIBUTES;                /**< Memory Error Attributes Capture, offset: 0x114C */
  __IO uint32_t CAPTURE_ADDRESS;                   /**< Memory Error Address Capture, offset: 0x1150 */
  __IO uint32_t CAPTURE_EXT_ADDRESS;               /**< Memory Error Extended Address Capture, offset: 0x1154 */
  __IO uint32_t ERR_SBE;                           /**< Single-Bit ECC Memory Error Management, offset: 0x1158 */
  uint8_t RESERVED_32[164];
  __IO uint32_t REG_LKSTP_CNTL;                    /**< Lockstep Register Control, offset: 0x1200 */
  uint8_t RESERVED_33[12];
  __IO uint32_t REG_CRC_GRP_1;                     /**< Register CRC Code For Group 1, offset: 0x1210 */
  __IO uint32_t REG_CRC_GRP_2;                     /**< Register CRC Code For Group 2, offset: 0x1214 */
  uint8_t RESERVED_34[40];
  __IO uint32_t ECC_REG_0;                         /**< ECC Region 0 Configuration, offset: 0x1240 */
  __IO uint32_t ECC_REG_1;                         /**< ECC Region 1 Configuration, offset: 0x1244 */
  __IO uint32_t ECC_REG_2;                         /**< ECC Region 2 Configuration, offset: 0x1248 */
  __IO uint32_t ECC_REG_3;                         /**< ECC Region 3 Configuration, offset: 0x124C */
  __IO uint32_t ECC_REG_4;                         /**< ECC Region 4 Configuration, offset: 0x1250 */
  __IO uint32_t ECC_REG_5;                         /**< ECC Region 5 Configuration, offset: 0x1254 */
  __IO uint32_t ECC_REG_6;                         /**< ECC Region 6 Configuration, offset: 0x1258 */
  __IO uint32_t ECC_REG_7;                         /**< ECC Region 7 Configuration, offset: 0x125C */
} DDRC_Type, *DDRC_MemMapPtr;

/** Number of instances of the DDRC module. */
#define DDRC_INSTANCE_COUNT                      (1u)

/* DDRC - Peripheral instance base addresses */
/** Peripheral DDR base address */
#define IP_DDR_BASE                              (0x72000000u)
/** Peripheral DDR base pointer */
#define IP_DDR                                   ((DDRC_Type *)IP_DDR_BASE)
/** Array initializer of DDRC peripheral base addresses */
#define IP_DDRC_BASE_ADDRS                       { IP_DDR_BASE }
/** Array initializer of DDRC peripheral base pointers */
#define IP_DDRC_BASE_PTRS                        { IP_DDR }

/* ----------------------------------------------------------------------------
   -- DDRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDRC_Register_Masks DDRC Register Masks
 * @{
 */

/*! @name CS_BNDS - Rank 0 Memory Bounds..Rank 1 Memory Bounds */
/*! @{ */

#define DDRC_CS_BNDS_EA_MASK                     (0xFFFFU)
#define DDRC_CS_BNDS_EA_SHIFT                    (0U)
#define DDRC_CS_BNDS_EA_WIDTH                    (16U)
#define DDRC_CS_BNDS_EA(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_CS_BNDS_EA_SHIFT)) & DDRC_CS_BNDS_EA_MASK)

#define DDRC_CS_BNDS_SA_MASK                     (0xFFFF0000U)
#define DDRC_CS_BNDS_SA_SHIFT                    (16U)
#define DDRC_CS_BNDS_SA_WIDTH                    (16U)
#define DDRC_CS_BNDS_SA(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_CS_BNDS_SA_SHIFT)) & DDRC_CS_BNDS_SA_MASK)
/*! @} */

/*! @name REMAP_0A - Remap Region 0A Configuration */
/*! @{ */

#define DDRC_REMAP_0A_REG_0_REMAP_ADDR_MASK      (0xFFFU)
#define DDRC_REMAP_0A_REG_0_REMAP_ADDR_SHIFT     (0U)
#define DDRC_REMAP_0A_REG_0_REMAP_ADDR_WIDTH     (12U)
#define DDRC_REMAP_0A_REG_0_REMAP_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_0A_REG_0_REMAP_ADDR_SHIFT)) & DDRC_REMAP_0A_REG_0_REMAP_ADDR_MASK)

#define DDRC_REMAP_0A_REG_0_REMAP_EN_MASK        (0x80000000U)
#define DDRC_REMAP_0A_REG_0_REMAP_EN_SHIFT       (31U)
#define DDRC_REMAP_0A_REG_0_REMAP_EN_WIDTH       (1U)
#define DDRC_REMAP_0A_REG_0_REMAP_EN(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_0A_REG_0_REMAP_EN_SHIFT)) & DDRC_REMAP_0A_REG_0_REMAP_EN_MASK)
/*! @} */

/*! @name REMAP_0B - Remap Region 0B Configuration */
/*! @{ */

#define DDRC_REMAP_0B_REG_0_EA_MASK              (0xFFFU)
#define DDRC_REMAP_0B_REG_0_EA_SHIFT             (0U)
#define DDRC_REMAP_0B_REG_0_EA_WIDTH             (12U)
#define DDRC_REMAP_0B_REG_0_EA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_0B_REG_0_EA_SHIFT)) & DDRC_REMAP_0B_REG_0_EA_MASK)

#define DDRC_REMAP_0B_REG_0_SA_MASK              (0xFFF0000U)
#define DDRC_REMAP_0B_REG_0_SA_SHIFT             (16U)
#define DDRC_REMAP_0B_REG_0_SA_WIDTH             (12U)
#define DDRC_REMAP_0B_REG_0_SA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_0B_REG_0_SA_SHIFT)) & DDRC_REMAP_0B_REG_0_SA_MASK)
/*! @} */

/*! @name REMAP_1A - Remap Region 1A Configuration */
/*! @{ */

#define DDRC_REMAP_1A_REG_1_REMAP_ADDR_MASK      (0xFFFU)
#define DDRC_REMAP_1A_REG_1_REMAP_ADDR_SHIFT     (0U)
#define DDRC_REMAP_1A_REG_1_REMAP_ADDR_WIDTH     (12U)
#define DDRC_REMAP_1A_REG_1_REMAP_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_1A_REG_1_REMAP_ADDR_SHIFT)) & DDRC_REMAP_1A_REG_1_REMAP_ADDR_MASK)

#define DDRC_REMAP_1A_REG_1_REMAP_EN_MASK        (0x80000000U)
#define DDRC_REMAP_1A_REG_1_REMAP_EN_SHIFT       (31U)
#define DDRC_REMAP_1A_REG_1_REMAP_EN_WIDTH       (1U)
#define DDRC_REMAP_1A_REG_1_REMAP_EN(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_1A_REG_1_REMAP_EN_SHIFT)) & DDRC_REMAP_1A_REG_1_REMAP_EN_MASK)
/*! @} */

/*! @name REMAP_1B - Remap Region 1B Configuration */
/*! @{ */

#define DDRC_REMAP_1B_REG_1_EA_MASK              (0xFFFU)
#define DDRC_REMAP_1B_REG_1_EA_SHIFT             (0U)
#define DDRC_REMAP_1B_REG_1_EA_WIDTH             (12U)
#define DDRC_REMAP_1B_REG_1_EA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_1B_REG_1_EA_SHIFT)) & DDRC_REMAP_1B_REG_1_EA_MASK)

#define DDRC_REMAP_1B_REG_1_SA_MASK              (0xFFF0000U)
#define DDRC_REMAP_1B_REG_1_SA_SHIFT             (16U)
#define DDRC_REMAP_1B_REG_1_SA_WIDTH             (12U)
#define DDRC_REMAP_1B_REG_1_SA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_1B_REG_1_SA_SHIFT)) & DDRC_REMAP_1B_REG_1_SA_MASK)
/*! @} */

/*! @name REMAP_2A - Remap Region 2A Configuration */
/*! @{ */

#define DDRC_REMAP_2A_REG_2_REMAP_ADDR_MASK      (0xFFFU)
#define DDRC_REMAP_2A_REG_2_REMAP_ADDR_SHIFT     (0U)
#define DDRC_REMAP_2A_REG_2_REMAP_ADDR_WIDTH     (12U)
#define DDRC_REMAP_2A_REG_2_REMAP_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_2A_REG_2_REMAP_ADDR_SHIFT)) & DDRC_REMAP_2A_REG_2_REMAP_ADDR_MASK)

#define DDRC_REMAP_2A_REG_2_REMAP_EN_MASK        (0x80000000U)
#define DDRC_REMAP_2A_REG_2_REMAP_EN_SHIFT       (31U)
#define DDRC_REMAP_2A_REG_2_REMAP_EN_WIDTH       (1U)
#define DDRC_REMAP_2A_REG_2_REMAP_EN(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_2A_REG_2_REMAP_EN_SHIFT)) & DDRC_REMAP_2A_REG_2_REMAP_EN_MASK)
/*! @} */

/*! @name REMAP_2B - Remap Region 2B Configuration */
/*! @{ */

#define DDRC_REMAP_2B_REG_2_EA_MASK              (0xFFFU)
#define DDRC_REMAP_2B_REG_2_EA_SHIFT             (0U)
#define DDRC_REMAP_2B_REG_2_EA_WIDTH             (12U)
#define DDRC_REMAP_2B_REG_2_EA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_2B_REG_2_EA_SHIFT)) & DDRC_REMAP_2B_REG_2_EA_MASK)

#define DDRC_REMAP_2B_REG_2_SA_MASK              (0xFFF0000U)
#define DDRC_REMAP_2B_REG_2_SA_SHIFT             (16U)
#define DDRC_REMAP_2B_REG_2_SA_WIDTH             (12U)
#define DDRC_REMAP_2B_REG_2_SA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_2B_REG_2_SA_SHIFT)) & DDRC_REMAP_2B_REG_2_SA_MASK)
/*! @} */

/*! @name REMAP_3A - Remap Region 3A Configuration */
/*! @{ */

#define DDRC_REMAP_3A_REG_3_REMAP_ADDR_MASK      (0xFFFU)
#define DDRC_REMAP_3A_REG_3_REMAP_ADDR_SHIFT     (0U)
#define DDRC_REMAP_3A_REG_3_REMAP_ADDR_WIDTH     (12U)
#define DDRC_REMAP_3A_REG_3_REMAP_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_3A_REG_3_REMAP_ADDR_SHIFT)) & DDRC_REMAP_3A_REG_3_REMAP_ADDR_MASK)

#define DDRC_REMAP_3A_REG_3_REMAP_EN_MASK        (0x80000000U)
#define DDRC_REMAP_3A_REG_3_REMAP_EN_SHIFT       (31U)
#define DDRC_REMAP_3A_REG_3_REMAP_EN_WIDTH       (1U)
#define DDRC_REMAP_3A_REG_3_REMAP_EN(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_3A_REG_3_REMAP_EN_SHIFT)) & DDRC_REMAP_3A_REG_3_REMAP_EN_MASK)
/*! @} */

/*! @name REMAP_3B - Remap Region 3B Configuration */
/*! @{ */

#define DDRC_REMAP_3B_REG_3_EA_MASK              (0xFFFU)
#define DDRC_REMAP_3B_REG_3_EA_SHIFT             (0U)
#define DDRC_REMAP_3B_REG_3_EA_WIDTH             (12U)
#define DDRC_REMAP_3B_REG_3_EA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_3B_REG_3_EA_SHIFT)) & DDRC_REMAP_3B_REG_3_EA_MASK)

#define DDRC_REMAP_3B_REG_3_SA_MASK              (0xFFF0000U)
#define DDRC_REMAP_3B_REG_3_SA_SHIFT             (16U)
#define DDRC_REMAP_3B_REG_3_SA_WIDTH             (12U)
#define DDRC_REMAP_3B_REG_3_SA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_3B_REG_3_SA_SHIFT)) & DDRC_REMAP_3B_REG_3_SA_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_0 - DDRC Address Decode 0 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_0_ROW14_OVRD_MASK      (0xFCU)
#define DDRC_DDR_ADDR_DEC_0_ROW14_OVRD_SHIFT     (2U)
#define DDRC_DDR_ADDR_DEC_0_ROW14_OVRD_WIDTH     (6U)
#define DDRC_DDR_ADDR_DEC_0_ROW14_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_0_ROW14_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_0_ROW14_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_0_ROW15_OVRD_MASK      (0xFC00U)
#define DDRC_DDR_ADDR_DEC_0_ROW15_OVRD_SHIFT     (10U)
#define DDRC_DDR_ADDR_DEC_0_ROW15_OVRD_WIDTH     (6U)
#define DDRC_DDR_ADDR_DEC_0_ROW15_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_0_ROW15_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_0_ROW15_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_0_ROW16_OVRD_MASK      (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_0_ROW16_OVRD_SHIFT     (18U)
#define DDRC_DDR_ADDR_DEC_0_ROW16_OVRD_WIDTH     (6U)
#define DDRC_DDR_ADDR_DEC_0_ROW16_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_0_ROW16_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_0_ROW16_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_0_ROW17_OVRD_MASK      (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_0_ROW17_OVRD_SHIFT     (26U)
#define DDRC_DDR_ADDR_DEC_0_ROW17_OVRD_WIDTH     (6U)
#define DDRC_DDR_ADDR_DEC_0_ROW17_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_0_ROW17_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_0_ROW17_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_1 - DDRC Address Decode 1 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_1_ROW10_OVRD_MASK      (0xFCU)
#define DDRC_DDR_ADDR_DEC_1_ROW10_OVRD_SHIFT     (2U)
#define DDRC_DDR_ADDR_DEC_1_ROW10_OVRD_WIDTH     (6U)
#define DDRC_DDR_ADDR_DEC_1_ROW10_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_1_ROW10_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_1_ROW10_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_1_ROW11_OVRD_MASK      (0xFC00U)
#define DDRC_DDR_ADDR_DEC_1_ROW11_OVRD_SHIFT     (10U)
#define DDRC_DDR_ADDR_DEC_1_ROW11_OVRD_WIDTH     (6U)
#define DDRC_DDR_ADDR_DEC_1_ROW11_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_1_ROW11_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_1_ROW11_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_1_ROW12_OVRD_MASK      (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_1_ROW12_OVRD_SHIFT     (18U)
#define DDRC_DDR_ADDR_DEC_1_ROW12_OVRD_WIDTH     (6U)
#define DDRC_DDR_ADDR_DEC_1_ROW12_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_1_ROW12_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_1_ROW12_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_1_ROW13_OVRD_MASK      (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_1_ROW13_OVRD_SHIFT     (26U)
#define DDRC_DDR_ADDR_DEC_1_ROW13_OVRD_WIDTH     (6U)
#define DDRC_DDR_ADDR_DEC_1_ROW13_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_1_ROW13_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_1_ROW13_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_2 - DDRC Address Decode 2 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_2_ROW6_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_2_ROW6_OVRD_SHIFT      (2U)
#define DDRC_DDR_ADDR_DEC_2_ROW6_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_2_ROW6_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_2_ROW6_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_2_ROW6_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_2_ROW7_OVRD_MASK       (0xFC00U)
#define DDRC_DDR_ADDR_DEC_2_ROW7_OVRD_SHIFT      (10U)
#define DDRC_DDR_ADDR_DEC_2_ROW7_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_2_ROW7_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_2_ROW7_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_2_ROW7_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_2_ROW8_OVRD_MASK       (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_2_ROW8_OVRD_SHIFT      (18U)
#define DDRC_DDR_ADDR_DEC_2_ROW8_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_2_ROW8_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_2_ROW8_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_2_ROW8_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_2_ROW9_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_2_ROW9_OVRD_SHIFT      (26U)
#define DDRC_DDR_ADDR_DEC_2_ROW9_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_2_ROW9_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_2_ROW9_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_2_ROW9_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_3 - DDRC Address Decode 3 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_3_ROW2_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_3_ROW2_OVRD_SHIFT      (2U)
#define DDRC_DDR_ADDR_DEC_3_ROW2_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_3_ROW2_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_3_ROW2_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_3_ROW2_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_3_ROW3_OVRD_MASK       (0xFC00U)
#define DDRC_DDR_ADDR_DEC_3_ROW3_OVRD_SHIFT      (10U)
#define DDRC_DDR_ADDR_DEC_3_ROW3_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_3_ROW3_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_3_ROW3_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_3_ROW3_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_3_ROW4_OVRD_MASK       (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_3_ROW4_OVRD_SHIFT      (18U)
#define DDRC_DDR_ADDR_DEC_3_ROW4_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_3_ROW4_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_3_ROW4_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_3_ROW4_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_3_ROW5_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_3_ROW5_OVRD_SHIFT      (26U)
#define DDRC_DDR_ADDR_DEC_3_ROW5_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_3_ROW5_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_3_ROW5_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_3_ROW5_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_4 - DDRC Address Decode 4 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_4_COL9_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_4_COL9_OVRD_SHIFT      (2U)
#define DDRC_DDR_ADDR_DEC_4_COL9_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_4_COL9_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_4_COL9_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_4_COL9_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_4_COL10_OVRD_MASK      (0xFC00U)
#define DDRC_DDR_ADDR_DEC_4_COL10_OVRD_SHIFT     (10U)
#define DDRC_DDR_ADDR_DEC_4_COL10_OVRD_WIDTH     (6U)
#define DDRC_DDR_ADDR_DEC_4_COL10_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_4_COL10_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_4_COL10_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_4_ROW0_OVRD_MASK       (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_4_ROW0_OVRD_SHIFT      (18U)
#define DDRC_DDR_ADDR_DEC_4_ROW0_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_4_ROW0_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_4_ROW0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_4_ROW0_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_4_ROW1_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_4_ROW1_OVRD_SHIFT      (26U)
#define DDRC_DDR_ADDR_DEC_4_ROW1_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_4_ROW1_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_4_ROW1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_4_ROW1_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_5 - DDRC Address Decode 5 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_5_COL5_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_5_COL5_OVRD_SHIFT      (2U)
#define DDRC_DDR_ADDR_DEC_5_COL5_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_5_COL5_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_5_COL5_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_5_COL5_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_5_COL6_OVRD_MASK       (0xFC00U)
#define DDRC_DDR_ADDR_DEC_5_COL6_OVRD_SHIFT      (10U)
#define DDRC_DDR_ADDR_DEC_5_COL6_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_5_COL6_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_5_COL6_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_5_COL6_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_5_COL7_OVRD_MASK       (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_5_COL7_OVRD_SHIFT      (18U)
#define DDRC_DDR_ADDR_DEC_5_COL7_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_5_COL7_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_5_COL7_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_5_COL7_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_5_COL8_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_5_COL8_OVRD_SHIFT      (26U)
#define DDRC_DDR_ADDR_DEC_5_COL8_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_5_COL8_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_5_COL8_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_5_COL8_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_6 - DDRC Address Decode 6 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_6_COL1_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_6_COL1_OVRD_SHIFT      (2U)
#define DDRC_DDR_ADDR_DEC_6_COL1_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_6_COL1_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_6_COL1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_6_COL1_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_6_COL2_OVRD_MASK       (0xFC00U)
#define DDRC_DDR_ADDR_DEC_6_COL2_OVRD_SHIFT      (10U)
#define DDRC_DDR_ADDR_DEC_6_COL2_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_6_COL2_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_6_COL2_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_6_COL2_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_6_COL3_OVRD_MASK       (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_6_COL3_OVRD_SHIFT      (18U)
#define DDRC_DDR_ADDR_DEC_6_COL3_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_6_COL3_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_6_COL3_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_6_COL3_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_6_COL4_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_6_COL4_OVRD_SHIFT      (26U)
#define DDRC_DDR_ADDR_DEC_6_COL4_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_6_COL4_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_6_COL4_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_6_COL4_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_7 - DDRC Address Decode 7 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_7_CID1_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_7_CID1_OVRD_SHIFT      (2U)
#define DDRC_DDR_ADDR_DEC_7_CID1_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_7_CID1_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_7_CID1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_7_CID1_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_7_BA0_OVRD_MASK        (0xFC00U)
#define DDRC_DDR_ADDR_DEC_7_BA0_OVRD_SHIFT       (10U)
#define DDRC_DDR_ADDR_DEC_7_BA0_OVRD_WIDTH       (6U)
#define DDRC_DDR_ADDR_DEC_7_BA0_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_7_BA0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_7_BA0_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_7_BA1_OVRD_MASK        (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_7_BA1_OVRD_SHIFT       (18U)
#define DDRC_DDR_ADDR_DEC_7_BA1_OVRD_WIDTH       (6U)
#define DDRC_DDR_ADDR_DEC_7_BA1_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_7_BA1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_7_BA1_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_7_COL0_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_7_COL0_OVRD_SHIFT      (26U)
#define DDRC_DDR_ADDR_DEC_7_COL0_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_7_COL0_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_7_COL0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_7_COL0_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_8 - DDRC Address Decode 8 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_8_BG1_OVRD_MASK        (0xFCU)
#define DDRC_DDR_ADDR_DEC_8_BG1_OVRD_SHIFT       (2U)
#define DDRC_DDR_ADDR_DEC_8_BG1_OVRD_WIDTH       (6U)
#define DDRC_DDR_ADDR_DEC_8_BG1_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_8_BG1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_8_BG1_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_8_CS0_OVRD_MASK        (0xFC00U)
#define DDRC_DDR_ADDR_DEC_8_CS0_OVRD_SHIFT       (10U)
#define DDRC_DDR_ADDR_DEC_8_CS0_OVRD_WIDTH       (6U)
#define DDRC_DDR_ADDR_DEC_8_CS0_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_8_CS0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_8_CS0_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_8_CS1_OVRD_MASK        (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_8_CS1_OVRD_SHIFT       (18U)
#define DDRC_DDR_ADDR_DEC_8_CS1_OVRD_WIDTH       (6U)
#define DDRC_DDR_ADDR_DEC_8_CS1_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_8_CS1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_8_CS1_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_8_CID0_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_8_CID0_OVRD_SHIFT      (26U)
#define DDRC_DDR_ADDR_DEC_8_CID0_OVRD_WIDTH      (6U)
#define DDRC_DDR_ADDR_DEC_8_CID0_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_8_CID0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_8_CID0_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_9 - DDRC Address Decode 9 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_9_ADDR_DEC_OVRD_MASK   (0x1U)
#define DDRC_DDR_ADDR_DEC_9_ADDR_DEC_OVRD_SHIFT  (0U)
#define DDRC_DDR_ADDR_DEC_9_ADDR_DEC_OVRD_WIDTH  (1U)
#define DDRC_DDR_ADDR_DEC_9_ADDR_DEC_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_9_ADDR_DEC_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_9_ADDR_DEC_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_9_BG0_OVRD_MASK        (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_9_BG0_OVRD_SHIFT       (26U)
#define DDRC_DDR_ADDR_DEC_9_BG0_OVRD_WIDTH       (6U)
#define DDRC_DDR_ADDR_DEC_9_BG0_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_9_BG0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_9_BG0_OVRD_MASK)
/*! @} */

/*! @name CS_CONFIG - Rank 0 Configuration..Rank 1 Configuration */
/*! @{ */

#define DDRC_CS_CONFIG_COL_BITS_CS_MASK          (0x7U)
#define DDRC_CS_CONFIG_COL_BITS_CS_SHIFT         (0U)
#define DDRC_CS_CONFIG_COL_BITS_CS_WIDTH         (3U)
#define DDRC_CS_CONFIG_COL_BITS_CS(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_CS_CONFIG_COL_BITS_CS_SHIFT)) & DDRC_CS_CONFIG_COL_BITS_CS_MASK)

#define DDRC_CS_CONFIG_BG_BITS_CS_MASK           (0x30U)
#define DDRC_CS_CONFIG_BG_BITS_CS_SHIFT          (4U)
#define DDRC_CS_CONFIG_BG_BITS_CS_WIDTH          (2U)
#define DDRC_CS_CONFIG_BG_BITS_CS(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_CS_CONFIG_BG_BITS_CS_SHIFT)) & DDRC_CS_CONFIG_BG_BITS_CS_MASK)

#define DDRC_CS_CONFIG_ROW_BITS_CS_MASK          (0x700U)
#define DDRC_CS_CONFIG_ROW_BITS_CS_SHIFT         (8U)
#define DDRC_CS_CONFIG_ROW_BITS_CS_WIDTH         (3U)
#define DDRC_CS_CONFIG_ROW_BITS_CS(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_CS_CONFIG_ROW_BITS_CS_SHIFT)) & DDRC_CS_CONFIG_ROW_BITS_CS_MASK)

#define DDRC_CS_CONFIG_AP_EN_MASK                (0x800000U)
#define DDRC_CS_CONFIG_AP_EN_SHIFT               (23U)
#define DDRC_CS_CONFIG_AP_EN_WIDTH               (1U)
#define DDRC_CS_CONFIG_AP_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_CS_CONFIG_AP_EN_SHIFT)) & DDRC_CS_CONFIG_AP_EN_MASK)

#define DDRC_CS_CONFIG_CS_EN_MASK                (0x80000000U)
#define DDRC_CS_CONFIG_CS_EN_SHIFT               (31U)
#define DDRC_CS_CONFIG_CS_EN_WIDTH               (1U)
#define DDRC_CS_CONFIG_CS_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_CS_CONFIG_CS_EN_SHIFT)) & DDRC_CS_CONFIG_CS_EN_MASK)
/*! @} */

/*! @name TIMING_CFG_3 - DDR SDRAM Timing Configuration 3 */
/*! @{ */

#define DDRC_TIMING_CFG_3_EXT_WRTORD_MASK        (0x1U)
#define DDRC_TIMING_CFG_3_EXT_WRTORD_SHIFT       (0U)
#define DDRC_TIMING_CFG_3_EXT_WRTORD_WIDTH       (1U)
#define DDRC_TIMING_CFG_3_EXT_WRTORD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_WRTORD_SHIFT)) & DDRC_TIMING_CFG_3_EXT_WRTORD_MASK)

#define DDRC_TIMING_CFG_3_EXT_ACTTOACT_MASK      (0x2U)
#define DDRC_TIMING_CFG_3_EXT_ACTTOACT_SHIFT     (1U)
#define DDRC_TIMING_CFG_3_EXT_ACTTOACT_WIDTH     (1U)
#define DDRC_TIMING_CFG_3_EXT_ACTTOACT(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_ACTTOACT_SHIFT)) & DDRC_TIMING_CFG_3_EXT_ACTTOACT_MASK)

#define DDRC_TIMING_CFG_3_EXT_FOUR_ACT_MASK      (0x8U)
#define DDRC_TIMING_CFG_3_EXT_FOUR_ACT_SHIFT     (3U)
#define DDRC_TIMING_CFG_3_EXT_FOUR_ACT_WIDTH     (1U)
#define DDRC_TIMING_CFG_3_EXT_FOUR_ACT(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_FOUR_ACT_SHIFT)) & DDRC_TIMING_CFG_3_EXT_FOUR_ACT_MASK)

#define DDRC_TIMING_CFG_3_EXT_CKE_PLS_MASK       (0x30U)
#define DDRC_TIMING_CFG_3_EXT_CKE_PLS_SHIFT      (4U)
#define DDRC_TIMING_CFG_3_EXT_CKE_PLS_WIDTH      (2U)
#define DDRC_TIMING_CFG_3_EXT_CKE_PLS(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_CKE_PLS_SHIFT)) & DDRC_TIMING_CFG_3_EXT_CKE_PLS_MASK)

#define DDRC_TIMING_CFG_3_EXT_WRREC_MASK         (0x300U)
#define DDRC_TIMING_CFG_3_EXT_WRREC_SHIFT        (8U)
#define DDRC_TIMING_CFG_3_EXT_WRREC_WIDTH        (2U)
#define DDRC_TIMING_CFG_3_EXT_WRREC(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_WRREC_SHIFT)) & DDRC_TIMING_CFG_3_EXT_WRREC_MASK)

#define DDRC_TIMING_CFG_3_EXT_WR_LAT_2_MASK      (0x800U)
#define DDRC_TIMING_CFG_3_EXT_WR_LAT_2_SHIFT     (11U)
#define DDRC_TIMING_CFG_3_EXT_WR_LAT_2_WIDTH     (1U)
#define DDRC_TIMING_CFG_3_EXT_WR_LAT_2(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_WR_LAT_2_SHIFT)) & DDRC_TIMING_CFG_3_EXT_WR_LAT_2_MASK)

#define DDRC_TIMING_CFG_3_EXT_CASLAT_MASK        (0x7000U)
#define DDRC_TIMING_CFG_3_EXT_CASLAT_SHIFT       (12U)
#define DDRC_TIMING_CFG_3_EXT_CASLAT_WIDTH       (3U)
#define DDRC_TIMING_CFG_3_EXT_CASLAT(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_CASLAT_SHIFT)) & DDRC_TIMING_CFG_3_EXT_CASLAT_MASK)

#define DDRC_TIMING_CFG_3_EXT_REFREC_MASK        (0x3F0000U)
#define DDRC_TIMING_CFG_3_EXT_REFREC_SHIFT       (16U)
#define DDRC_TIMING_CFG_3_EXT_REFREC_WIDTH       (6U)
#define DDRC_TIMING_CFG_3_EXT_REFREC(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_REFREC_SHIFT)) & DDRC_TIMING_CFG_3_EXT_REFREC_MASK)

#define DDRC_TIMING_CFG_3_EXT_ACTTORW_MASK       (0xC00000U)
#define DDRC_TIMING_CFG_3_EXT_ACTTORW_SHIFT      (22U)
#define DDRC_TIMING_CFG_3_EXT_ACTTORW_WIDTH      (2U)
#define DDRC_TIMING_CFG_3_EXT_ACTTORW(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_ACTTORW_SHIFT)) & DDRC_TIMING_CFG_3_EXT_ACTTORW_MASK)

#define DDRC_TIMING_CFG_3_EXT_ACTTOPRE_MASK      (0x7000000U)
#define DDRC_TIMING_CFG_3_EXT_ACTTOPRE_SHIFT     (24U)
#define DDRC_TIMING_CFG_3_EXT_ACTTOPRE_WIDTH     (3U)
#define DDRC_TIMING_CFG_3_EXT_ACTTOPRE(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_ACTTOPRE_SHIFT)) & DDRC_TIMING_CFG_3_EXT_ACTTOPRE_MASK)

#define DDRC_TIMING_CFG_3_EXT_PRETOACT_MASK      (0x30000000U)
#define DDRC_TIMING_CFG_3_EXT_PRETOACT_SHIFT     (28U)
#define DDRC_TIMING_CFG_3_EXT_PRETOACT_WIDTH     (2U)
#define DDRC_TIMING_CFG_3_EXT_PRETOACT(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_PRETOACT_SHIFT)) & DDRC_TIMING_CFG_3_EXT_PRETOACT_MASK)
/*! @} */

/*! @name TIMING_CFG_0 - DDR SDRAM Timing Configuration 0 */
/*! @{ */

#define DDRC_TIMING_CFG_0_MRS_CYC_MASK           (0x3FU)
#define DDRC_TIMING_CFG_0_MRS_CYC_SHIFT          (0U)
#define DDRC_TIMING_CFG_0_MRS_CYC_WIDTH          (6U)
#define DDRC_TIMING_CFG_0_MRS_CYC(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_MRS_CYC_SHIFT)) & DDRC_TIMING_CFG_0_MRS_CYC_MASK)

#define DDRC_TIMING_CFG_0_EXT_ACT_PD_EXIT_MASK   (0x1000U)
#define DDRC_TIMING_CFG_0_EXT_ACT_PD_EXIT_SHIFT  (12U)
#define DDRC_TIMING_CFG_0_EXT_ACT_PD_EXIT_WIDTH  (1U)
#define DDRC_TIMING_CFG_0_EXT_ACT_PD_EXIT(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_EXT_ACT_PD_EXIT_SHIFT)) & DDRC_TIMING_CFG_0_EXT_ACT_PD_EXIT_MASK)

#define DDRC_TIMING_CFG_0_EXT_PRE_PD_EXIT_MASK   (0xC000U)
#define DDRC_TIMING_CFG_0_EXT_PRE_PD_EXIT_SHIFT  (14U)
#define DDRC_TIMING_CFG_0_EXT_PRE_PD_EXIT_WIDTH  (2U)
#define DDRC_TIMING_CFG_0_EXT_PRE_PD_EXIT(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_EXT_PRE_PD_EXIT_SHIFT)) & DDRC_TIMING_CFG_0_EXT_PRE_PD_EXIT_MASK)

#define DDRC_TIMING_CFG_0_PRE_PD_EXIT_MASK       (0xF0000U)
#define DDRC_TIMING_CFG_0_PRE_PD_EXIT_SHIFT      (16U)
#define DDRC_TIMING_CFG_0_PRE_PD_EXIT_WIDTH      (4U)
#define DDRC_TIMING_CFG_0_PRE_PD_EXIT(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_PRE_PD_EXIT_SHIFT)) & DDRC_TIMING_CFG_0_PRE_PD_EXIT_MASK)

#define DDRC_TIMING_CFG_0_ACT_PD_EXIT_MASK       (0xF00000U)
#define DDRC_TIMING_CFG_0_ACT_PD_EXIT_SHIFT      (20U)
#define DDRC_TIMING_CFG_0_ACT_PD_EXIT_WIDTH      (4U)
#define DDRC_TIMING_CFG_0_ACT_PD_EXIT(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_ACT_PD_EXIT_SHIFT)) & DDRC_TIMING_CFG_0_ACT_PD_EXIT_MASK)

#define DDRC_TIMING_CFG_0_WWT_MASK               (0x3000000U)
#define DDRC_TIMING_CFG_0_WWT_SHIFT              (24U)
#define DDRC_TIMING_CFG_0_WWT_WIDTH              (2U)
#define DDRC_TIMING_CFG_0_WWT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_WWT_SHIFT)) & DDRC_TIMING_CFG_0_WWT_MASK)

#define DDRC_TIMING_CFG_0_RRT_MASK               (0xC000000U)
#define DDRC_TIMING_CFG_0_RRT_SHIFT              (26U)
#define DDRC_TIMING_CFG_0_RRT_WIDTH              (2U)
#define DDRC_TIMING_CFG_0_RRT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_RRT_SHIFT)) & DDRC_TIMING_CFG_0_RRT_MASK)

#define DDRC_TIMING_CFG_0_WRT_MASK               (0x30000000U)
#define DDRC_TIMING_CFG_0_WRT_SHIFT              (28U)
#define DDRC_TIMING_CFG_0_WRT_WIDTH              (2U)
#define DDRC_TIMING_CFG_0_WRT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_WRT_SHIFT)) & DDRC_TIMING_CFG_0_WRT_MASK)

#define DDRC_TIMING_CFG_0_RWT_MASK               (0xC0000000U)
#define DDRC_TIMING_CFG_0_RWT_SHIFT              (30U)
#define DDRC_TIMING_CFG_0_RWT_WIDTH              (2U)
#define DDRC_TIMING_CFG_0_RWT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_RWT_SHIFT)) & DDRC_TIMING_CFG_0_RWT_MASK)
/*! @} */

/*! @name TIMING_CFG_1 - DDR SDRAM Timing Configuration 1 */
/*! @{ */

#define DDRC_TIMING_CFG_1_WRTORD_MASK            (0xFU)
#define DDRC_TIMING_CFG_1_WRTORD_SHIFT           (0U)
#define DDRC_TIMING_CFG_1_WRTORD_WIDTH           (4U)
#define DDRC_TIMING_CFG_1_WRTORD(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_WRTORD_SHIFT)) & DDRC_TIMING_CFG_1_WRTORD_MASK)

#define DDRC_TIMING_CFG_1_ACTTOACT_MASK          (0xF0U)
#define DDRC_TIMING_CFG_1_ACTTOACT_SHIFT         (4U)
#define DDRC_TIMING_CFG_1_ACTTOACT_WIDTH         (4U)
#define DDRC_TIMING_CFG_1_ACTTOACT(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_ACTTOACT_SHIFT)) & DDRC_TIMING_CFG_1_ACTTOACT_MASK)

#define DDRC_TIMING_CFG_1_WRREC_MASK             (0xF00U)
#define DDRC_TIMING_CFG_1_WRREC_SHIFT            (8U)
#define DDRC_TIMING_CFG_1_WRREC_WIDTH            (4U)
#define DDRC_TIMING_CFG_1_WRREC(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_WRREC_SHIFT)) & DDRC_TIMING_CFG_1_WRREC_MASK)

#define DDRC_TIMING_CFG_1_REFREC_MASK            (0xF000U)
#define DDRC_TIMING_CFG_1_REFREC_SHIFT           (12U)
#define DDRC_TIMING_CFG_1_REFREC_WIDTH           (4U)
#define DDRC_TIMING_CFG_1_REFREC(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_REFREC_SHIFT)) & DDRC_TIMING_CFG_1_REFREC_MASK)

#define DDRC_TIMING_CFG_1_CASLAT_MASK            (0xE0000U)
#define DDRC_TIMING_CFG_1_CASLAT_SHIFT           (17U)
#define DDRC_TIMING_CFG_1_CASLAT_WIDTH           (3U)
#define DDRC_TIMING_CFG_1_CASLAT(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_CASLAT_SHIFT)) & DDRC_TIMING_CFG_1_CASLAT_MASK)

#define DDRC_TIMING_CFG_1_ACTTORW_MASK           (0xF00000U)
#define DDRC_TIMING_CFG_1_ACTTORW_SHIFT          (20U)
#define DDRC_TIMING_CFG_1_ACTTORW_WIDTH          (4U)
#define DDRC_TIMING_CFG_1_ACTTORW(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_ACTTORW_SHIFT)) & DDRC_TIMING_CFG_1_ACTTORW_MASK)

#define DDRC_TIMING_CFG_1_ACTTOPRE_MASK          (0xF000000U)
#define DDRC_TIMING_CFG_1_ACTTOPRE_SHIFT         (24U)
#define DDRC_TIMING_CFG_1_ACTTOPRE_WIDTH         (4U)
#define DDRC_TIMING_CFG_1_ACTTOPRE(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_ACTTOPRE_SHIFT)) & DDRC_TIMING_CFG_1_ACTTOPRE_MASK)

#define DDRC_TIMING_CFG_1_PRETOACT_MASK          (0xF0000000U)
#define DDRC_TIMING_CFG_1_PRETOACT_SHIFT         (28U)
#define DDRC_TIMING_CFG_1_PRETOACT_WIDTH         (4U)
#define DDRC_TIMING_CFG_1_PRETOACT(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_PRETOACT_SHIFT)) & DDRC_TIMING_CFG_1_PRETOACT_MASK)
/*! @} */

/*! @name TIMING_CFG_2 - DDR SDRAM Timing Configuration 2 */
/*! @{ */

#define DDRC_TIMING_CFG_2_FOUR_ACT_MASK          (0x3FU)
#define DDRC_TIMING_CFG_2_FOUR_ACT_SHIFT         (0U)
#define DDRC_TIMING_CFG_2_FOUR_ACT_WIDTH         (6U)
#define DDRC_TIMING_CFG_2_FOUR_ACT(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_FOUR_ACT_SHIFT)) & DDRC_TIMING_CFG_2_FOUR_ACT_MASK)

#define DDRC_TIMING_CFG_2_CKE_PLS_MASK           (0x1C0U)
#define DDRC_TIMING_CFG_2_CKE_PLS_SHIFT          (6U)
#define DDRC_TIMING_CFG_2_CKE_PLS_WIDTH          (3U)
#define DDRC_TIMING_CFG_2_CKE_PLS(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_CKE_PLS_SHIFT)) & DDRC_TIMING_CFG_2_CKE_PLS_MASK)

#define DDRC_TIMING_CFG_2_RD_TO_PRE_MASK         (0x3E000U)
#define DDRC_TIMING_CFG_2_RD_TO_PRE_SHIFT        (13U)
#define DDRC_TIMING_CFG_2_RD_TO_PRE_WIDTH        (5U)
#define DDRC_TIMING_CFG_2_RD_TO_PRE(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_RD_TO_PRE_SHIFT)) & DDRC_TIMING_CFG_2_RD_TO_PRE_MASK)

#define DDRC_TIMING_CFG_2_EXT_WR_LAT_MASK        (0x40000U)
#define DDRC_TIMING_CFG_2_EXT_WR_LAT_SHIFT       (18U)
#define DDRC_TIMING_CFG_2_EXT_WR_LAT_WIDTH       (1U)
#define DDRC_TIMING_CFG_2_EXT_WR_LAT(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_EXT_WR_LAT_SHIFT)) & DDRC_TIMING_CFG_2_EXT_WR_LAT_MASK)

#define DDRC_TIMING_CFG_2_WR_LAT_MASK            (0x780000U)
#define DDRC_TIMING_CFG_2_WR_LAT_SHIFT           (19U)
#define DDRC_TIMING_CFG_2_WR_LAT_WIDTH           (4U)
#define DDRC_TIMING_CFG_2_WR_LAT(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_WR_LAT_SHIFT)) & DDRC_TIMING_CFG_2_WR_LAT_MASK)

#define DDRC_TIMING_CFG_2_DERATE_VAL_MASK        (0xF0000000U)
#define DDRC_TIMING_CFG_2_DERATE_VAL_SHIFT       (28U)
#define DDRC_TIMING_CFG_2_DERATE_VAL_WIDTH       (4U)
#define DDRC_TIMING_CFG_2_DERATE_VAL(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_DERATE_VAL_SHIFT)) & DDRC_TIMING_CFG_2_DERATE_VAL_MASK)
/*! @} */

/*! @name DDR_SDRAM_CFG - DDR SDRAM Control Configuration */
/*! @{ */

#define DDRC_DDR_SDRAM_CFG_BI_MASK               (0x1U)
#define DDRC_DDR_SDRAM_CFG_BI_SHIFT              (0U)
#define DDRC_DDR_SDRAM_CFG_BI_WIDTH              (1U)
#define DDRC_DDR_SDRAM_CFG_BI(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_BI_SHIFT)) & DDRC_DDR_SDRAM_CFG_BI_MASK)

#define DDRC_DDR_SDRAM_CFG_MEM_HALT_MASK         (0x2U)
#define DDRC_DDR_SDRAM_CFG_MEM_HALT_SHIFT        (1U)
#define DDRC_DDR_SDRAM_CFG_MEM_HALT_WIDTH        (1U)
#define DDRC_DDR_SDRAM_CFG_MEM_HALT(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_MEM_HALT_SHIFT)) & DDRC_DDR_SDRAM_CFG_MEM_HALT_MASK)

#define DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL_MASK     (0x7F00U)
#define DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL_SHIFT    (8U)
#define DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL_WIDTH    (7U)
#define DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL_SHIFT)) & DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL_MASK)

#define DDRC_DDR_SDRAM_CFG_DBW_MASK              (0x180000U)
#define DDRC_DDR_SDRAM_CFG_DBW_SHIFT             (19U)
#define DDRC_DDR_SDRAM_CFG_DBW_WIDTH             (2U)
#define DDRC_DDR_SDRAM_CFG_DBW(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_DBW_SHIFT)) & DDRC_DDR_SDRAM_CFG_DBW_MASK)

#define DDRC_DDR_SDRAM_CFG_DYN_PWR_MASK          (0x200000U)
#define DDRC_DDR_SDRAM_CFG_DYN_PWR_SHIFT         (21U)
#define DDRC_DDR_SDRAM_CFG_DYN_PWR_WIDTH         (1U)
#define DDRC_DDR_SDRAM_CFG_DYN_PWR(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_DYN_PWR_SHIFT)) & DDRC_DDR_SDRAM_CFG_DYN_PWR_MASK)

#define DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_MASK       (0x7000000U)
#define DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_SHIFT      (24U)
#define DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_WIDTH      (3U)
#define DDRC_DDR_SDRAM_CFG_SDRAM_TYPE(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_SHIFT)) & DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_MASK)

#define DDRC_DDR_SDRAM_CFG_SREN_MASK             (0x40000000U)
#define DDRC_DDR_SDRAM_CFG_SREN_SHIFT            (30U)
#define DDRC_DDR_SDRAM_CFG_SREN_WIDTH            (1U)
#define DDRC_DDR_SDRAM_CFG_SREN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_SREN_SHIFT)) & DDRC_DDR_SDRAM_CFG_SREN_MASK)

#define DDRC_DDR_SDRAM_CFG_MEM_EN_MASK           (0x80000000U)
#define DDRC_DDR_SDRAM_CFG_MEM_EN_SHIFT          (31U)
#define DDRC_DDR_SDRAM_CFG_MEM_EN_WIDTH          (1U)
#define DDRC_DDR_SDRAM_CFG_MEM_EN(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_MEM_EN_SHIFT)) & DDRC_DDR_SDRAM_CFG_MEM_EN_MASK)
/*! @} */

/*! @name DDR_SDRAM_CFG_2 - DDR SDRAM Control Configuration 2 */
/*! @{ */

#define DDRC_DDR_SDRAM_CFG_2_D_INIT_MASK         (0x10U)
#define DDRC_DDR_SDRAM_CFG_2_D_INIT_SHIFT        (4U)
#define DDRC_DDR_SDRAM_CFG_2_D_INIT_WIDTH        (1U)
#define DDRC_DDR_SDRAM_CFG_2_D_INIT(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_2_D_INIT_SHIFT)) & DDRC_DDR_SDRAM_CFG_2_D_INIT_MASK)

#define DDRC_DDR_SDRAM_CFG_2_NUM_PR_MASK         (0xF000U)
#define DDRC_DDR_SDRAM_CFG_2_NUM_PR_SHIFT        (12U)
#define DDRC_DDR_SDRAM_CFG_2_NUM_PR_WIDTH        (4U)
#define DDRC_DDR_SDRAM_CFG_2_NUM_PR(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_2_NUM_PR_SHIFT)) & DDRC_DDR_SDRAM_CFG_2_NUM_PR_MASK)

#define DDRC_DDR_SDRAM_CFG_2_MCK_DIS_MASK        (0xF000000U)
#define DDRC_DDR_SDRAM_CFG_2_MCK_DIS_SHIFT       (24U)
#define DDRC_DDR_SDRAM_CFG_2_MCK_DIS_WIDTH       (4U)
#define DDRC_DDR_SDRAM_CFG_2_MCK_DIS(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_2_MCK_DIS_SHIFT)) & DDRC_DDR_SDRAM_CFG_2_MCK_DIS_MASK)

#define DDRC_DDR_SDRAM_CFG_2_FRC_SR_MASK         (0x80000000U)
#define DDRC_DDR_SDRAM_CFG_2_FRC_SR_SHIFT        (31U)
#define DDRC_DDR_SDRAM_CFG_2_FRC_SR_WIDTH        (1U)
#define DDRC_DDR_SDRAM_CFG_2_FRC_SR(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_2_FRC_SR_SHIFT)) & DDRC_DDR_SDRAM_CFG_2_FRC_SR_MASK)
/*! @} */

/*! @name DDR_SDRAM_MD_CNTL - DDR SDRAM Mode Control */
/*! @{ */

#define DDRC_DDR_SDRAM_MD_CNTL_MD_VALUE_MASK     (0x3FFFFU)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_VALUE_SHIFT    (0U)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_VALUE_WIDTH    (18U)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_VALUE(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_MD_VALUE_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_MD_VALUE_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL_MASK     (0x300000U)
#define DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL_SHIFT    (20U)
#define DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL_WIDTH    (2U)
#define DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_SET_PRE_MASK      (0x400000U)
#define DDRC_DDR_SDRAM_MD_CNTL_SET_PRE_SHIFT     (22U)
#define DDRC_DDR_SDRAM_MD_CNTL_SET_PRE_WIDTH     (1U)
#define DDRC_DDR_SDRAM_MD_CNTL_SET_PRE(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_SET_PRE_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_SET_PRE_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_SET_REF_MASK      (0x800000U)
#define DDRC_DDR_SDRAM_MD_CNTL_SET_REF_SHIFT     (23U)
#define DDRC_DDR_SDRAM_MD_CNTL_SET_REF_WIDTH     (1U)
#define DDRC_DDR_SDRAM_MD_CNTL_SET_REF(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_SET_REF_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_SET_REF_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_MD_SEL_MASK       (0xF000000U)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_SEL_SHIFT      (24U)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_SEL_WIDTH      (4U)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_SEL(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_MD_SEL_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_MD_SEL_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_CS_SEL_MASK       (0x70000000U)
#define DDRC_DDR_SDRAM_MD_CNTL_CS_SEL_SHIFT      (28U)
#define DDRC_DDR_SDRAM_MD_CNTL_CS_SEL_WIDTH      (3U)
#define DDRC_DDR_SDRAM_MD_CNTL_CS_SEL(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_CS_SEL_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_CS_SEL_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_MD_EN_MASK        (0x80000000U)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_EN_SHIFT       (31U)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_EN_WIDTH       (1U)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_EN(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_MD_EN_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_MD_EN_MASK)
/*! @} */

/*! @name DDR_SDRAM_INTERVAL - DDR SDRAM Interval Configuration */
/*! @{ */

#define DDRC_DDR_SDRAM_INTERVAL_BSTOPRE_MASK     (0x3FFFU)
#define DDRC_DDR_SDRAM_INTERVAL_BSTOPRE_SHIFT    (0U)
#define DDRC_DDR_SDRAM_INTERVAL_BSTOPRE_WIDTH    (14U)
#define DDRC_DDR_SDRAM_INTERVAL_BSTOPRE(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_INTERVAL_BSTOPRE_SHIFT)) & DDRC_DDR_SDRAM_INTERVAL_BSTOPRE_MASK)

#define DDRC_DDR_SDRAM_INTERVAL_REFINT_MASK      (0xFFFF0000U)
#define DDRC_DDR_SDRAM_INTERVAL_REFINT_SHIFT     (16U)
#define DDRC_DDR_SDRAM_INTERVAL_REFINT_WIDTH     (16U)
#define DDRC_DDR_SDRAM_INTERVAL_REFINT(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_INTERVAL_REFINT_SHIFT)) & DDRC_DDR_SDRAM_INTERVAL_REFINT_MASK)
/*! @} */

/*! @name DDR_DATA_INIT - DDR SDRAM Data Initialization */
/*! @{ */

#define DDRC_DDR_DATA_INIT_INIT_VALUE_MASK       (0xFFFFFFFFU)
#define DDRC_DDR_DATA_INIT_INIT_VALUE_SHIFT      (0U)
#define DDRC_DDR_DATA_INIT_INIT_VALUE_WIDTH      (32U)
#define DDRC_DDR_DATA_INIT_INIT_VALUE(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_DATA_INIT_INIT_VALUE_SHIFT)) & DDRC_DDR_DATA_INIT_INIT_VALUE_MASK)
/*! @} */

/*! @name TIMING_CFG_4 - DDR SDRAM Timing Configuration 4 */
/*! @{ */

#define DDRC_TIMING_CFG_4_DLL_LOCK_MASK          (0x3U)
#define DDRC_TIMING_CFG_4_DLL_LOCK_SHIFT         (0U)
#define DDRC_TIMING_CFG_4_DLL_LOCK_WIDTH         (2U)
#define DDRC_TIMING_CFG_4_DLL_LOCK(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_DLL_LOCK_SHIFT)) & DDRC_TIMING_CFG_4_DLL_LOCK_MASK)

#define DDRC_TIMING_CFG_4_EXT_REFINT_MASK        (0x10U)
#define DDRC_TIMING_CFG_4_EXT_REFINT_SHIFT       (4U)
#define DDRC_TIMING_CFG_4_EXT_REFINT_WIDTH       (1U)
#define DDRC_TIMING_CFG_4_EXT_REFINT(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_EXT_REFINT_SHIFT)) & DDRC_TIMING_CFG_4_EXT_REFINT_MASK)

#define DDRC_TIMING_CFG_4_EXT_WWT_MASK           (0x300U)
#define DDRC_TIMING_CFG_4_EXT_WWT_SHIFT          (8U)
#define DDRC_TIMING_CFG_4_EXT_WWT_WIDTH          (2U)
#define DDRC_TIMING_CFG_4_EXT_WWT(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_EXT_WWT_SHIFT)) & DDRC_TIMING_CFG_4_EXT_WWT_MASK)

#define DDRC_TIMING_CFG_4_EXT_RRT_MASK           (0xC00U)
#define DDRC_TIMING_CFG_4_EXT_RRT_SHIFT          (10U)
#define DDRC_TIMING_CFG_4_EXT_RRT_WIDTH          (2U)
#define DDRC_TIMING_CFG_4_EXT_RRT(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_EXT_RRT_SHIFT)) & DDRC_TIMING_CFG_4_EXT_RRT_MASK)

#define DDRC_TIMING_CFG_4_EXT_WRT_MASK           (0x3000U)
#define DDRC_TIMING_CFG_4_EXT_WRT_SHIFT          (12U)
#define DDRC_TIMING_CFG_4_EXT_WRT_WIDTH          (2U)
#define DDRC_TIMING_CFG_4_EXT_WRT(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_EXT_WRT_SHIFT)) & DDRC_TIMING_CFG_4_EXT_WRT_MASK)

#define DDRC_TIMING_CFG_4_EXT_RWT_MASK           (0xC000U)
#define DDRC_TIMING_CFG_4_EXT_RWT_SHIFT          (14U)
#define DDRC_TIMING_CFG_4_EXT_RWT_WIDTH          (2U)
#define DDRC_TIMING_CFG_4_EXT_RWT(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_EXT_RWT_SHIFT)) & DDRC_TIMING_CFG_4_EXT_RWT_MASK)

#define DDRC_TIMING_CFG_4_WWT_MASK               (0xF0000U)
#define DDRC_TIMING_CFG_4_WWT_SHIFT              (16U)
#define DDRC_TIMING_CFG_4_WWT_WIDTH              (4U)
#define DDRC_TIMING_CFG_4_WWT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_WWT_SHIFT)) & DDRC_TIMING_CFG_4_WWT_MASK)

#define DDRC_TIMING_CFG_4_RRT_MASK               (0xF00000U)
#define DDRC_TIMING_CFG_4_RRT_SHIFT              (20U)
#define DDRC_TIMING_CFG_4_RRT_WIDTH              (4U)
#define DDRC_TIMING_CFG_4_RRT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_RRT_SHIFT)) & DDRC_TIMING_CFG_4_RRT_MASK)

#define DDRC_TIMING_CFG_4_WRT_MASK               (0xF000000U)
#define DDRC_TIMING_CFG_4_WRT_SHIFT              (24U)
#define DDRC_TIMING_CFG_4_WRT_WIDTH              (4U)
#define DDRC_TIMING_CFG_4_WRT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_WRT_SHIFT)) & DDRC_TIMING_CFG_4_WRT_MASK)

#define DDRC_TIMING_CFG_4_RWT_MASK               (0xF0000000U)
#define DDRC_TIMING_CFG_4_RWT_SHIFT              (28U)
#define DDRC_TIMING_CFG_4_RWT_WIDTH              (4U)
#define DDRC_TIMING_CFG_4_RWT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_RWT_SHIFT)) & DDRC_TIMING_CFG_4_RWT_MASK)
/*! @} */

/*! @name TIMING_CFG_7 - DDR SDRAM Timing Configuration 7 */
/*! @{ */

#define DDRC_TIMING_CFG_7_CKSRX_MASK             (0xF00000U)
#define DDRC_TIMING_CFG_7_CKSRX_SHIFT            (20U)
#define DDRC_TIMING_CFG_7_CKSRX_WIDTH            (4U)
#define DDRC_TIMING_CFG_7_CKSRX(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_7_CKSRX_SHIFT)) & DDRC_TIMING_CFG_7_CKSRX_MASK)

#define DDRC_TIMING_CFG_7_CKSRE_MASK             (0xF000000U)
#define DDRC_TIMING_CFG_7_CKSRE_SHIFT            (24U)
#define DDRC_TIMING_CFG_7_CKSRE_WIDTH            (4U)
#define DDRC_TIMING_CFG_7_CKSRE(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_7_CKSRE_SHIFT)) & DDRC_TIMING_CFG_7_CKSRE_MASK)

#define DDRC_TIMING_CFG_7_CKE_RST_MASK           (0x30000000U)
#define DDRC_TIMING_CFG_7_CKE_RST_SHIFT          (28U)
#define DDRC_TIMING_CFG_7_CKE_RST_WIDTH          (2U)
#define DDRC_TIMING_CFG_7_CKE_RST(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_7_CKE_RST_SHIFT)) & DDRC_TIMING_CFG_7_CKE_RST_MASK)
/*! @} */

/*! @name DDR_ZQ_CNTL - DDR SDRAM ZQ Calibration Control */
/*! @{ */

#define DDRC_DDR_ZQ_CNTL_ZQCS_INT_MASK           (0xFU)
#define DDRC_DDR_ZQ_CNTL_ZQCS_INT_SHIFT          (0U)
#define DDRC_DDR_ZQ_CNTL_ZQCS_INT_WIDTH          (4U)
#define DDRC_DDR_ZQ_CNTL_ZQCS_INT(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ZQ_CNTL_ZQCS_INT_SHIFT)) & DDRC_DDR_ZQ_CNTL_ZQCS_INT_MASK)

#define DDRC_DDR_ZQ_CNTL_ZQCS_MASK               (0xF00U)
#define DDRC_DDR_ZQ_CNTL_ZQCS_SHIFT              (8U)
#define DDRC_DDR_ZQ_CNTL_ZQCS_WIDTH              (4U)
#define DDRC_DDR_ZQ_CNTL_ZQCS(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ZQ_CNTL_ZQCS_SHIFT)) & DDRC_DDR_ZQ_CNTL_ZQCS_MASK)

#define DDRC_DDR_ZQ_CNTL_ZQOPER_MASK             (0xF0000U)
#define DDRC_DDR_ZQ_CNTL_ZQOPER_SHIFT            (16U)
#define DDRC_DDR_ZQ_CNTL_ZQOPER_WIDTH            (4U)
#define DDRC_DDR_ZQ_CNTL_ZQOPER(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ZQ_CNTL_ZQOPER_SHIFT)) & DDRC_DDR_ZQ_CNTL_ZQOPER_MASK)

#define DDRC_DDR_ZQ_CNTL_ZQINIT_MASK             (0xF000000U)
#define DDRC_DDR_ZQ_CNTL_ZQINIT_SHIFT            (24U)
#define DDRC_DDR_ZQ_CNTL_ZQINIT_WIDTH            (4U)
#define DDRC_DDR_ZQ_CNTL_ZQINIT(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ZQ_CNTL_ZQINIT_SHIFT)) & DDRC_DDR_ZQ_CNTL_ZQINIT_MASK)

#define DDRC_DDR_ZQ_CNTL_ZQ_EN_MASK              (0x80000000U)
#define DDRC_DDR_ZQ_CNTL_ZQ_EN_SHIFT             (31U)
#define DDRC_DDR_ZQ_CNTL_ZQ_EN_WIDTH             (1U)
#define DDRC_DDR_ZQ_CNTL_ZQ_EN(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ZQ_CNTL_ZQ_EN_SHIFT)) & DDRC_DDR_ZQ_CNTL_ZQ_EN_MASK)
/*! @} */

/*! @name DDR_SR_CNTR - DDR SDRAM Self-Refresh Counter */
/*! @{ */

#define DDRC_DDR_SR_CNTR_SR_IT_MASK              (0xF0000U)
#define DDRC_DDR_SR_CNTR_SR_IT_SHIFT             (16U)
#define DDRC_DDR_SR_CNTR_SR_IT_WIDTH             (4U)
#define DDRC_DDR_SR_CNTR_SR_IT(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SR_CNTR_SR_IT_SHIFT)) & DDRC_DDR_SR_CNTR_SR_IT_MASK)
/*! @} */

/*! @name TIMING_CFG_8 - DDR SDRAM Timing Configuration 8 */
/*! @{ */

#define DDRC_TIMING_CFG_8_PRE_ALL_REC_MASK       (0x3FU)
#define DDRC_TIMING_CFG_8_PRE_ALL_REC_SHIFT      (0U)
#define DDRC_TIMING_CFG_8_PRE_ALL_REC_WIDTH      (6U)
#define DDRC_TIMING_CFG_8_PRE_ALL_REC(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_8_PRE_ALL_REC_SHIFT)) & DDRC_TIMING_CFG_8_PRE_ALL_REC_MASK)
/*! @} */

/*! @name TIMING_CFG_9 - DDR SDRAM timing configuration 9 */
/*! @{ */

#define DDRC_TIMING_CFG_9_REFTOREF_PB_MASK       (0x3FFU)
#define DDRC_TIMING_CFG_9_REFTOREF_PB_SHIFT      (0U)
#define DDRC_TIMING_CFG_9_REFTOREF_PB_WIDTH      (10U)
#define DDRC_TIMING_CFG_9_REFTOREF_PB(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_9_REFTOREF_PB_SHIFT)) & DDRC_TIMING_CFG_9_REFTOREF_PB_MASK)

#define DDRC_TIMING_CFG_9_REFREC_PB_MASK         (0x3FF0000U)
#define DDRC_TIMING_CFG_9_REFREC_PB_SHIFT        (16U)
#define DDRC_TIMING_CFG_9_REFREC_PB_WIDTH        (10U)
#define DDRC_TIMING_CFG_9_REFREC_PB(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_9_REFREC_PB_SHIFT)) & DDRC_TIMING_CFG_9_REFREC_PB_MASK)
/*! @} */

/*! @name TIMING_CFG_11 - DDR SDRAM Timing Configuration 11 */
/*! @{ */

#define DDRC_TIMING_CFG_11_MWWT_MASK             (0xFU)
#define DDRC_TIMING_CFG_11_MWWT_SHIFT            (0U)
#define DDRC_TIMING_CFG_11_MWWT_WIDTH            (4U)
#define DDRC_TIMING_CFG_11_MWWT(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_11_MWWT_SHIFT)) & DDRC_TIMING_CFG_11_MWWT_MASK)

#define DDRC_TIMING_CFG_11_PRE_TO_PRE_MASK       (0xF00U)
#define DDRC_TIMING_CFG_11_PRE_TO_PRE_SHIFT      (8U)
#define DDRC_TIMING_CFG_11_PRE_TO_PRE_WIDTH      (4U)
#define DDRC_TIMING_CFG_11_PRE_TO_PRE(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_11_PRE_TO_PRE_SHIFT)) & DDRC_TIMING_CFG_11_PRE_TO_PRE_MASK)
/*! @} */

/*! @name DDR_SDRAM_CFG_3 - DDR SDRAM Control Configuration 3 */
/*! @{ */

#define DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_MASK  (0x2U)
#define DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_SHIFT (1U)
#define DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_WIDTH (1U)
#define DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_MASK)

#define DDRC_DDR_SDRAM_CFG_3_NON_PWR_2_MASK      (0x8U)
#define DDRC_DDR_SDRAM_CFG_3_NON_PWR_2_SHIFT     (3U)
#define DDRC_DDR_SDRAM_CFG_3_NON_PWR_2_WIDTH     (1U)
#define DDRC_DDR_SDRAM_CFG_3_NON_PWR_2(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_NON_PWR_2_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_NON_PWR_2_MASK)

#define DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_MASK (0x80U)
#define DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_SHIFT (7U)
#define DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_WIDTH (1U)
#define DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN(x)  (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_MASK)

#define DDRC_DDR_SDRAM_CFG_3_DRAIN_FOR_SR_MASK   (0x800U)
#define DDRC_DDR_SDRAM_CFG_3_DRAIN_FOR_SR_SHIFT  (11U)
#define DDRC_DDR_SDRAM_CFG_3_DRAIN_FOR_SR_WIDTH  (1U)
#define DDRC_DDR_SDRAM_CFG_3_DRAIN_FOR_SR(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_DRAIN_FOR_SR_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_DRAIN_FOR_SR_MASK)

#define DDRC_DDR_SDRAM_CFG_3_DM_CFG_MASK         (0x7000U)
#define DDRC_DDR_SDRAM_CFG_3_DM_CFG_SHIFT        (12U)
#define DDRC_DDR_SDRAM_CFG_3_DM_CFG_WIDTH        (3U)
#define DDRC_DDR_SDRAM_CFG_3_DM_CFG(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_DM_CFG_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_DM_CFG_MASK)

#define DDRC_DDR_SDRAM_CFG_3_DDRC_RST_MASK       (0x80000000U)
#define DDRC_DDR_SDRAM_CFG_3_DDRC_RST_SHIFT      (31U)
#define DDRC_DDR_SDRAM_CFG_3_DDRC_RST_WIDTH      (1U)
#define DDRC_DDR_SDRAM_CFG_3_DDRC_RST(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_DDRC_RST_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_DDRC_RST_MASK)
/*! @} */

/*! @name DDR_SDRAM_REF_RATE - DDR Refresh Rate */
/*! @{ */

#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_MASK (0xFFU)
#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_SHIFT (0U)
#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_WIDTH (8U)
#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1(x)  (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_SHIFT)) & DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_MASK)

#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_MASK (0xFF00U)
#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_SHIFT (8U)
#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_WIDTH (8U)
#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0(x)  (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_SHIFT)) & DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_MASK)
/*! @} */

/*! @name TX_CFG_1 - Transaction Configuration Register 1 */
/*! @{ */

#define DDRC_TX_CFG_1_TS_DEPTH_MASK              (0xF80U)
#define DDRC_TX_CFG_1_TS_DEPTH_SHIFT             (7U)
#define DDRC_TX_CFG_1_TS_DEPTH_WIDTH             (5U)
#define DDRC_TX_CFG_1_TS_DEPTH(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_TX_CFG_1_TS_DEPTH_SHIFT)) & DDRC_TX_CFG_1_TS_DEPTH_MASK)
/*! @} */

/*! @name FFI_CFG - Freedom From Interference Configuration */
/*! @{ */

#define DDRC_FFI_CFG_GRP_3_DID_MASK              (0xFU)
#define DDRC_FFI_CFG_GRP_3_DID_SHIFT             (0U)
#define DDRC_FFI_CFG_GRP_3_DID_WIDTH             (4U)
#define DDRC_FFI_CFG_GRP_3_DID(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG_GRP_3_DID_SHIFT)) & DDRC_FFI_CFG_GRP_3_DID_MASK)

#define DDRC_FFI_CFG_BNS_CNT_EN_MASK             (0x10U)
#define DDRC_FFI_CFG_BNS_CNT_EN_SHIFT            (4U)
#define DDRC_FFI_CFG_BNS_CNT_EN_WIDTH            (1U)
#define DDRC_FFI_CFG_BNS_CNT_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG_BNS_CNT_EN_SHIFT)) & DDRC_FFI_CFG_BNS_CNT_EN_MASK)

#define DDRC_FFI_CFG_GRP_DEF_EN_MASK             (0x20U)
#define DDRC_FFI_CFG_GRP_DEF_EN_SHIFT            (5U)
#define DDRC_FFI_CFG_GRP_DEF_EN_WIDTH            (1U)
#define DDRC_FFI_CFG_GRP_DEF_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG_GRP_DEF_EN_SHIFT)) & DDRC_FFI_CFG_GRP_DEF_EN_MASK)

#define DDRC_FFI_CFG_GRP_3_AEN_MASK              (0x40U)
#define DDRC_FFI_CFG_GRP_3_AEN_SHIFT             (6U)
#define DDRC_FFI_CFG_GRP_3_AEN_WIDTH             (1U)
#define DDRC_FFI_CFG_GRP_3_AEN(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG_GRP_3_AEN_SHIFT)) & DDRC_FFI_CFG_GRP_3_AEN_MASK)

#define DDRC_FFI_CFG_GRP_3_EN_MASK               (0x80U)
#define DDRC_FFI_CFG_GRP_3_EN_SHIFT              (7U)
#define DDRC_FFI_CFG_GRP_3_EN_WIDTH              (1U)
#define DDRC_FFI_CFG_GRP_3_EN(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG_GRP_3_EN_SHIFT)) & DDRC_FFI_CFG_GRP_3_EN_MASK)

#define DDRC_FFI_CFG_GRP_2_DID_MASK              (0xF00U)
#define DDRC_FFI_CFG_GRP_2_DID_SHIFT             (8U)
#define DDRC_FFI_CFG_GRP_2_DID_WIDTH             (4U)
#define DDRC_FFI_CFG_GRP_2_DID(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG_GRP_2_DID_SHIFT)) & DDRC_FFI_CFG_GRP_2_DID_MASK)

#define DDRC_FFI_CFG_GRP_2_EN_MASK               (0x8000U)
#define DDRC_FFI_CFG_GRP_2_EN_SHIFT              (15U)
#define DDRC_FFI_CFG_GRP_2_EN_WIDTH              (1U)
#define DDRC_FFI_CFG_GRP_2_EN(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG_GRP_2_EN_SHIFT)) & DDRC_FFI_CFG_GRP_2_EN_MASK)

#define DDRC_FFI_CFG_GRP_1_DID_MASK              (0xF0000U)
#define DDRC_FFI_CFG_GRP_1_DID_SHIFT             (16U)
#define DDRC_FFI_CFG_GRP_1_DID_WIDTH             (4U)
#define DDRC_FFI_CFG_GRP_1_DID(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG_GRP_1_DID_SHIFT)) & DDRC_FFI_CFG_GRP_1_DID_MASK)

#define DDRC_FFI_CFG_GRP_1_EN_MASK               (0x800000U)
#define DDRC_FFI_CFG_GRP_1_EN_SHIFT              (23U)
#define DDRC_FFI_CFG_GRP_1_EN_WIDTH              (1U)
#define DDRC_FFI_CFG_GRP_1_EN(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG_GRP_1_EN_SHIFT)) & DDRC_FFI_CFG_GRP_1_EN_MASK)

#define DDRC_FFI_CFG_GRP_0_DID_MASK              (0xF000000U)
#define DDRC_FFI_CFG_GRP_0_DID_SHIFT             (24U)
#define DDRC_FFI_CFG_GRP_0_DID_WIDTH             (4U)
#define DDRC_FFI_CFG_GRP_0_DID(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG_GRP_0_DID_SHIFT)) & DDRC_FFI_CFG_GRP_0_DID_MASK)

#define DDRC_FFI_CFG_GRP_0_EN_MASK               (0x80000000U)
#define DDRC_FFI_CFG_GRP_0_EN_SHIFT              (31U)
#define DDRC_FFI_CFG_GRP_0_EN_WIDTH              (1U)
#define DDRC_FFI_CFG_GRP_0_EN(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG_GRP_0_EN_SHIFT)) & DDRC_FFI_CFG_GRP_0_EN_MASK)
/*! @} */

/*! @name FFI_CFG2 - Freedom From Interference Configuration 2 */
/*! @{ */

#define DDRC_FFI_CFG2_INF_DEF_BNS_MASK           (0x1U)
#define DDRC_FFI_CFG2_INF_DEF_BNS_SHIFT          (0U)
#define DDRC_FFI_CFG2_INF_DEF_BNS_WIDTH          (1U)
#define DDRC_FFI_CFG2_INF_DEF_BNS(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG2_INF_DEF_BNS_SHIFT)) & DDRC_FFI_CFG2_INF_DEF_BNS_MASK)

#define DDRC_FFI_CFG2_BNS_CNT_CNFG_MASK          (0x1F0U)
#define DDRC_FFI_CFG2_BNS_CNT_CNFG_SHIFT         (4U)
#define DDRC_FFI_CFG2_BNS_CNT_CNFG_WIDTH         (5U)
#define DDRC_FFI_CFG2_BNS_CNT_CNFG(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_FFI_CFG2_BNS_CNT_CNFG_SHIFT)) & DDRC_FFI_CFG2_BNS_CNT_CNFG_MASK)
/*! @} */

/*! @name DDRDSR_2 - DDR SDRAM Debug Status 2 */
/*! @{ */

#define DDRC_DDRDSR_2_RPD_END_MASK               (0x1U)
#define DDRC_DDRDSR_2_RPD_END_SHIFT              (0U)
#define DDRC_DDRDSR_2_RPD_END_WIDTH              (1U)
#define DDRC_DDRDSR_2_RPD_END(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DDRDSR_2_RPD_END_SHIFT)) & DDRC_DDRDSR_2_RPD_END_MASK)

#define DDRC_DDRDSR_2_RPD_ST_MASK                (0x2U)
#define DDRC_DDRDSR_2_RPD_ST_SHIFT               (1U)
#define DDRC_DDRDSR_2_RPD_ST_WIDTH               (1U)
#define DDRC_DDRDSR_2_RPD_ST(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_DDRDSR_2_RPD_ST_SHIFT)) & DDRC_DDRDSR_2_RPD_ST_MASK)

#define DDRC_DDRDSR_2_PHY_INIT_CMPLT_MASK        (0x4U)
#define DDRC_DDRDSR_2_PHY_INIT_CMPLT_SHIFT       (2U)
#define DDRC_DDRDSR_2_PHY_INIT_CMPLT_WIDTH       (1U)
#define DDRC_DDRDSR_2_PHY_INIT_CMPLT(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDRDSR_2_PHY_INIT_CMPLT_SHIFT)) & DDRC_DDRDSR_2_PHY_INIT_CMPLT_MASK)

#define DDRC_DDRDSR_2_NML_MASK                   (0x40000000U)
#define DDRC_DDRDSR_2_NML_SHIFT                  (30U)
#define DDRC_DDRDSR_2_NML_WIDTH                  (1U)
#define DDRC_DDRDSR_2_NML(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_DDRDSR_2_NML_SHIFT)) & DDRC_DDRDSR_2_NML_MASK)

#define DDRC_DDRDSR_2_IDLE_MASK                  (0x80000000U)
#define DDRC_DDRDSR_2_IDLE_SHIFT                 (31U)
#define DDRC_DDRDSR_2_IDLE_WIDTH                 (1U)
#define DDRC_DDRDSR_2_IDLE(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_DDRDSR_2_IDLE_SHIFT)) & DDRC_DDRDSR_2_IDLE_MASK)
/*! @} */

/*! @name DDR_IP_REV1 - DDRC Revision 1 */
/*! @{ */

#define DDRC_DDR_IP_REV1_IP_MN_MASK              (0xFFU)
#define DDRC_DDR_IP_REV1_IP_MN_SHIFT             (0U)
#define DDRC_DDR_IP_REV1_IP_MN_WIDTH             (8U)
#define DDRC_DDR_IP_REV1_IP_MN(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_IP_REV1_IP_MN_SHIFT)) & DDRC_DDR_IP_REV1_IP_MN_MASK)

#define DDRC_DDR_IP_REV1_IP_MJ_MASK              (0xFF00U)
#define DDRC_DDR_IP_REV1_IP_MJ_SHIFT             (8U)
#define DDRC_DDR_IP_REV1_IP_MJ_WIDTH             (8U)
#define DDRC_DDR_IP_REV1_IP_MJ(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_IP_REV1_IP_MJ_SHIFT)) & DDRC_DDR_IP_REV1_IP_MJ_MASK)

#define DDRC_DDR_IP_REV1_IP_ID_MASK              (0xFFFF0000U)
#define DDRC_DDR_IP_REV1_IP_ID_SHIFT             (16U)
#define DDRC_DDR_IP_REV1_IP_ID_WIDTH             (16U)
#define DDRC_DDR_IP_REV1_IP_ID(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_IP_REV1_IP_ID_SHIFT)) & DDRC_DDR_IP_REV1_IP_ID_MASK)
/*! @} */

/*! @name DDR_MTCR - DDR SDRAM Memory Test Control */
/*! @{ */

#define DDRC_DDR_MTCR_MT_STAT_MASK               (0x1U)
#define DDRC_DDR_MTCR_MT_STAT_SHIFT              (0U)
#define DDRC_DDR_MTCR_MT_STAT_WIDTH              (1U)
#define DDRC_DDR_MTCR_MT_STAT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTCR_MT_STAT_SHIFT)) & DDRC_DDR_MTCR_MT_STAT_MASK)

#define DDRC_DDR_MTCR_MT_ADDR_EN_MASK            (0x200U)
#define DDRC_DDR_MTCR_MT_ADDR_EN_SHIFT           (9U)
#define DDRC_DDR_MTCR_MT_ADDR_EN_WIDTH           (1U)
#define DDRC_DDR_MTCR_MT_ADDR_EN(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTCR_MT_ADDR_EN_SHIFT)) & DDRC_DDR_MTCR_MT_ADDR_EN_MASK)

#define DDRC_DDR_MTCR_MT_TRNARND_MASK            (0xF0000U)
#define DDRC_DDR_MTCR_MT_TRNARND_SHIFT           (16U)
#define DDRC_DDR_MTCR_MT_TRNARND_WIDTH           (4U)
#define DDRC_DDR_MTCR_MT_TRNARND(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTCR_MT_TRNARND_SHIFT)) & DDRC_DDR_MTCR_MT_TRNARND_MASK)

#define DDRC_DDR_MTCR_MT_TYP_MASK                (0x3000000U)
#define DDRC_DDR_MTCR_MT_TYP_SHIFT               (24U)
#define DDRC_DDR_MTCR_MT_TYP_WIDTH               (2U)
#define DDRC_DDR_MTCR_MT_TYP(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTCR_MT_TYP_SHIFT)) & DDRC_DDR_MTCR_MT_TYP_MASK)

#define DDRC_DDR_MTCR_MT_EN_MASK                 (0x80000000U)
#define DDRC_DDR_MTCR_MT_EN_SHIFT                (31U)
#define DDRC_DDR_MTCR_MT_EN_WIDTH                (1U)
#define DDRC_DDR_MTCR_MT_EN(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTCR_MT_EN_SHIFT)) & DDRC_DDR_MTCR_MT_EN_MASK)
/*! @} */

/*! @name DDR_MTP - DDR SDRAM Memory Test Pattern n */
/*! @{ */

#define DDRC_DDR_MTP_DDR_PATT_MASK               (0xFFFFFFFFU)
#define DDRC_DDR_MTP_DDR_PATT_SHIFT              (0U)
#define DDRC_DDR_MTP_DDR_PATT_WIDTH              (32U)
#define DDRC_DDR_MTP_DDR_PATT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTP_DDR_PATT_SHIFT)) & DDRC_DDR_MTP_DDR_PATT_MASK)
/*! @} */

/*! @name DDR_MT_ST_EXT_ADDR - DDR SDRAM Memory Test Start Extended Address */
/*! @{ */

#define DDRC_DDR_MT_ST_EXT_ADDR_MT_ST_EXT_ADDR_MASK (0xFFU)
#define DDRC_DDR_MT_ST_EXT_ADDR_MT_ST_EXT_ADDR_SHIFT (0U)
#define DDRC_DDR_MT_ST_EXT_ADDR_MT_ST_EXT_ADDR_WIDTH (8U)
#define DDRC_DDR_MT_ST_EXT_ADDR_MT_ST_EXT_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MT_ST_EXT_ADDR_MT_ST_EXT_ADDR_SHIFT)) & DDRC_DDR_MT_ST_EXT_ADDR_MT_ST_EXT_ADDR_MASK)
/*! @} */

/*! @name DDR_MT_ST_ADDR - DDR SDRAM Memory Test Start Address */
/*! @{ */

#define DDRC_DDR_MT_ST_ADDR_MT_ST_ADDR_MASK      (0xFFFFFFFFU)
#define DDRC_DDR_MT_ST_ADDR_MT_ST_ADDR_SHIFT     (0U)
#define DDRC_DDR_MT_ST_ADDR_MT_ST_ADDR_WIDTH     (32U)
#define DDRC_DDR_MT_ST_ADDR_MT_ST_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MT_ST_ADDR_MT_ST_ADDR_SHIFT)) & DDRC_DDR_MT_ST_ADDR_MT_ST_ADDR_MASK)
/*! @} */

/*! @name DDR_MT_END_EXT_ADDR - DDR SDRAM Memory Test End Extended Address */
/*! @{ */

#define DDRC_DDR_MT_END_EXT_ADDR_MT_END_EXT_ADDR_MASK (0xFFU)
#define DDRC_DDR_MT_END_EXT_ADDR_MT_END_EXT_ADDR_SHIFT (0U)
#define DDRC_DDR_MT_END_EXT_ADDR_MT_END_EXT_ADDR_WIDTH (8U)
#define DDRC_DDR_MT_END_EXT_ADDR_MT_END_EXT_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MT_END_EXT_ADDR_MT_END_EXT_ADDR_SHIFT)) & DDRC_DDR_MT_END_EXT_ADDR_MT_END_EXT_ADDR_MASK)
/*! @} */

/*! @name DDR_MT_END_ADDR - DDR SDRAM Memory Test End Address */
/*! @{ */

#define DDRC_DDR_MT_END_ADDR_MT_END_ADDR_MASK    (0xFFFFFFFFU)
#define DDRC_DDR_MT_END_ADDR_MT_END_ADDR_SHIFT   (0U)
#define DDRC_DDR_MT_END_ADDR_MT_END_ADDR_WIDTH   (32U)
#define DDRC_DDR_MT_END_ADDR_MT_END_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MT_END_ADDR_MT_END_ADDR_SHIFT)) & DDRC_DDR_MT_END_ADDR_MT_END_ADDR_MASK)
/*! @} */

/*! @name PMGC0 - Performance Monitor Global Control */
/*! @{ */

#define DDRC_PMGC0_FCECE_MASK                    (0x20000000U)
#define DDRC_PMGC0_FCECE_SHIFT                   (29U)
#define DDRC_PMGC0_FCECE_WIDTH                   (1U)
#define DDRC_PMGC0_FCECE(x)                      (((uint32_t)(((uint32_t)(x)) << DDRC_PMGC0_FCECE_SHIFT)) & DDRC_PMGC0_FCECE_MASK)

#define DDRC_PMGC0_PMIE_MASK                     (0x40000000U)
#define DDRC_PMGC0_PMIE_SHIFT                    (30U)
#define DDRC_PMGC0_PMIE_WIDTH                    (1U)
#define DDRC_PMGC0_PMIE(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_PMGC0_PMIE_SHIFT)) & DDRC_PMGC0_PMIE_MASK)

#define DDRC_PMGC0_FAC_MASK                      (0x80000000U)
#define DDRC_PMGC0_FAC_SHIFT                     (31U)
#define DDRC_PMGC0_FAC_WIDTH                     (1U)
#define DDRC_PMGC0_FAC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMGC0_FAC_SHIFT)) & DDRC_PMGC0_FAC_MASK)
/*! @} */

/*! @name PMLCA0 - Performance Monitor Local Control A0 */
/*! @{ */

#define DDRC_PMLCA0_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA0_CE_SHIFT                     (26U)
#define DDRC_PMLCA0_CE_WIDTH                     (1U)
#define DDRC_PMLCA0_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA0_CE_SHIFT)) & DDRC_PMLCA0_CE_MASK)

#define DDRC_PMLCA0_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA0_FC_SHIFT                     (31U)
#define DDRC_PMLCA0_FC_WIDTH                     (1U)
#define DDRC_PMLCA0_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA0_FC_SHIFT)) & DDRC_PMLCA0_FC_MASK)
/*! @} */

/*! @name PMLCB0 - Performance Monitor Local Control B0 */
/*! @{ */

#define DDRC_PMLCB0_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB0_TRIGOFFCNTL_SHIFT            (16U)
#define DDRC_PMLCB0_TRIGOFFCNTL_WIDTH            (2U)
#define DDRC_PMLCB0_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB0_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB0_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB0_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB0_TRIGONCNTL_SHIFT             (18U)
#define DDRC_PMLCB0_TRIGONCNTL_WIDTH             (2U)
#define DDRC_PMLCB0_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB0_TRIGONCNTL_SHIFT)) & DDRC_PMLCB0_TRIGONCNTL_MASK)

#define DDRC_PMLCB0_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB0_TRIGOFFSEL_SHIFT             (20U)
#define DDRC_PMLCB0_TRIGOFFSEL_WIDTH             (4U)
#define DDRC_PMLCB0_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB0_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB0_TRIGOFFSEL_MASK)

#define DDRC_PMLCB0_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB0_TRIGONSEL_SHIFT              (26U)
#define DDRC_PMLCB0_TRIGONSEL_WIDTH              (4U)
#define DDRC_PMLCB0_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB0_TRIGONSEL_SHIFT)) & DDRC_PMLCB0_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC0A - PMC 0a */
/*! @{ */

#define DDRC_PMC0A_PMC0_MASK                     (0xFFFFFFFFU)
#define DDRC_PMC0A_PMC0_SHIFT                    (0U)
#define DDRC_PMC0A_PMC0_WIDTH                    (32U)
#define DDRC_PMC0A_PMC0(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_PMC0A_PMC0_SHIFT)) & DDRC_PMC0A_PMC0_MASK)
/*! @} */

/*! @name PMC0B - PMC 0b */
/*! @{ */

#define DDRC_PMC0B_PMC0_MASK                     (0xFFFFFFFFU)
#define DDRC_PMC0B_PMC0_SHIFT                    (0U)
#define DDRC_PMC0B_PMC0_WIDTH                    (32U)
#define DDRC_PMC0B_PMC0(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_PMC0B_PMC0_SHIFT)) & DDRC_PMC0B_PMC0_MASK)
/*! @} */

/*! @name PMLCA1 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA1_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA1_BDIST_SHIFT                  (0U)
#define DDRC_PMLCA1_BDIST_WIDTH                  (6U)
#define DDRC_PMLCA1_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_BDIST_SHIFT)) & DDRC_PMLCA1_BDIST_MASK)

#define DDRC_PMLCA1_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA1_BGRAN_SHIFT                  (6U)
#define DDRC_PMLCA1_BGRAN_WIDTH                  (5U)
#define DDRC_PMLCA1_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_BGRAN_SHIFT)) & DDRC_PMLCA1_BGRAN_MASK)

#define DDRC_PMLCA1_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA1_BSIZE_SHIFT                  (11U)
#define DDRC_PMLCA1_BSIZE_WIDTH                  (5U)
#define DDRC_PMLCA1_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_BSIZE_SHIFT)) & DDRC_PMLCA1_BSIZE_MASK)

#define DDRC_PMLCA1_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA1_EVENT_SHIFT                  (16U)
#define DDRC_PMLCA1_EVENT_WIDTH                  (7U)
#define DDRC_PMLCA1_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_EVENT_SHIFT)) & DDRC_PMLCA1_EVENT_MASK)

#define DDRC_PMLCA1_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA1_CE_SHIFT                     (26U)
#define DDRC_PMLCA1_CE_WIDTH                     (1U)
#define DDRC_PMLCA1_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_CE_SHIFT)) & DDRC_PMLCA1_CE_MASK)

#define DDRC_PMLCA1_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA1_FC_SHIFT                     (31U)
#define DDRC_PMLCA1_FC_WIDTH                     (1U)
#define DDRC_PMLCA1_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_FC_SHIFT)) & DDRC_PMLCA1_FC_MASK)
/*! @} */

/*! @name PMLCB1 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB1_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB1_THRESHOLD_SHIFT              (0U)
#define DDRC_PMLCB1_THRESHOLD_WIDTH              (6U)
#define DDRC_PMLCB1_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_THRESHOLD_SHIFT)) & DDRC_PMLCB1_THRESHOLD_MASK)

#define DDRC_PMLCB1_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB1_TBMULT_SHIFT                 (8U)
#define DDRC_PMLCB1_TBMULT_WIDTH                 (3U)
#define DDRC_PMLCB1_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_TBMULT_SHIFT)) & DDRC_PMLCB1_TBMULT_MASK)

#define DDRC_PMLCB1_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB1_TRIGOFFCNTL_SHIFT            (16U)
#define DDRC_PMLCB1_TRIGOFFCNTL_WIDTH            (2U)
#define DDRC_PMLCB1_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB1_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB1_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB1_TRIGONCNTL_SHIFT             (18U)
#define DDRC_PMLCB1_TRIGONCNTL_WIDTH             (2U)
#define DDRC_PMLCB1_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_TRIGONCNTL_SHIFT)) & DDRC_PMLCB1_TRIGONCNTL_MASK)

#define DDRC_PMLCB1_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB1_TRIGOFFSEL_SHIFT             (20U)
#define DDRC_PMLCB1_TRIGOFFSEL_WIDTH             (4U)
#define DDRC_PMLCB1_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB1_TRIGOFFSEL_MASK)

#define DDRC_PMLCB1_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB1_TRIGONSEL_SHIFT              (26U)
#define DDRC_PMLCB1_TRIGONSEL_WIDTH              (4U)
#define DDRC_PMLCB1_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_TRIGONSEL_SHIFT)) & DDRC_PMLCB1_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC1 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC1_PMC1_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC1_PMC1_SHIFT                     (0U)
#define DDRC_PMC1_PMC1_WIDTH                     (32U)
#define DDRC_PMC1_PMC1(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC1_PMC1_SHIFT)) & DDRC_PMC1_PMC1_MASK)
/*! @} */

/*! @name PMLCA2 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA2_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA2_BDIST_SHIFT                  (0U)
#define DDRC_PMLCA2_BDIST_WIDTH                  (6U)
#define DDRC_PMLCA2_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_BDIST_SHIFT)) & DDRC_PMLCA2_BDIST_MASK)

#define DDRC_PMLCA2_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA2_BGRAN_SHIFT                  (6U)
#define DDRC_PMLCA2_BGRAN_WIDTH                  (5U)
#define DDRC_PMLCA2_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_BGRAN_SHIFT)) & DDRC_PMLCA2_BGRAN_MASK)

#define DDRC_PMLCA2_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA2_BSIZE_SHIFT                  (11U)
#define DDRC_PMLCA2_BSIZE_WIDTH                  (5U)
#define DDRC_PMLCA2_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_BSIZE_SHIFT)) & DDRC_PMLCA2_BSIZE_MASK)

#define DDRC_PMLCA2_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA2_EVENT_SHIFT                  (16U)
#define DDRC_PMLCA2_EVENT_WIDTH                  (7U)
#define DDRC_PMLCA2_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_EVENT_SHIFT)) & DDRC_PMLCA2_EVENT_MASK)

#define DDRC_PMLCA2_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA2_CE_SHIFT                     (26U)
#define DDRC_PMLCA2_CE_WIDTH                     (1U)
#define DDRC_PMLCA2_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_CE_SHIFT)) & DDRC_PMLCA2_CE_MASK)

#define DDRC_PMLCA2_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA2_FC_SHIFT                     (31U)
#define DDRC_PMLCA2_FC_WIDTH                     (1U)
#define DDRC_PMLCA2_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_FC_SHIFT)) & DDRC_PMLCA2_FC_MASK)
/*! @} */

/*! @name PMLCB2 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB2_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB2_THRESHOLD_SHIFT              (0U)
#define DDRC_PMLCB2_THRESHOLD_WIDTH              (6U)
#define DDRC_PMLCB2_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_THRESHOLD_SHIFT)) & DDRC_PMLCB2_THRESHOLD_MASK)

#define DDRC_PMLCB2_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB2_TBMULT_SHIFT                 (8U)
#define DDRC_PMLCB2_TBMULT_WIDTH                 (3U)
#define DDRC_PMLCB2_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_TBMULT_SHIFT)) & DDRC_PMLCB2_TBMULT_MASK)

#define DDRC_PMLCB2_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB2_TRIGOFFCNTL_SHIFT            (16U)
#define DDRC_PMLCB2_TRIGOFFCNTL_WIDTH            (2U)
#define DDRC_PMLCB2_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB2_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB2_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB2_TRIGONCNTL_SHIFT             (18U)
#define DDRC_PMLCB2_TRIGONCNTL_WIDTH             (2U)
#define DDRC_PMLCB2_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_TRIGONCNTL_SHIFT)) & DDRC_PMLCB2_TRIGONCNTL_MASK)

#define DDRC_PMLCB2_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB2_TRIGOFFSEL_SHIFT             (20U)
#define DDRC_PMLCB2_TRIGOFFSEL_WIDTH             (4U)
#define DDRC_PMLCB2_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB2_TRIGOFFSEL_MASK)

#define DDRC_PMLCB2_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB2_TRIGONSEL_SHIFT              (26U)
#define DDRC_PMLCB2_TRIGONSEL_WIDTH              (4U)
#define DDRC_PMLCB2_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_TRIGONSEL_SHIFT)) & DDRC_PMLCB2_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC2 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC2_PMC2_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC2_PMC2_SHIFT                     (0U)
#define DDRC_PMC2_PMC2_WIDTH                     (32U)
#define DDRC_PMC2_PMC2(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC2_PMC2_SHIFT)) & DDRC_PMC2_PMC2_MASK)
/*! @} */

/*! @name PMLCA3 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA3_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA3_BDIST_SHIFT                  (0U)
#define DDRC_PMLCA3_BDIST_WIDTH                  (6U)
#define DDRC_PMLCA3_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_BDIST_SHIFT)) & DDRC_PMLCA3_BDIST_MASK)

#define DDRC_PMLCA3_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA3_BGRAN_SHIFT                  (6U)
#define DDRC_PMLCA3_BGRAN_WIDTH                  (5U)
#define DDRC_PMLCA3_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_BGRAN_SHIFT)) & DDRC_PMLCA3_BGRAN_MASK)

#define DDRC_PMLCA3_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA3_BSIZE_SHIFT                  (11U)
#define DDRC_PMLCA3_BSIZE_WIDTH                  (5U)
#define DDRC_PMLCA3_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_BSIZE_SHIFT)) & DDRC_PMLCA3_BSIZE_MASK)

#define DDRC_PMLCA3_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA3_EVENT_SHIFT                  (16U)
#define DDRC_PMLCA3_EVENT_WIDTH                  (7U)
#define DDRC_PMLCA3_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_EVENT_SHIFT)) & DDRC_PMLCA3_EVENT_MASK)

#define DDRC_PMLCA3_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA3_CE_SHIFT                     (26U)
#define DDRC_PMLCA3_CE_WIDTH                     (1U)
#define DDRC_PMLCA3_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_CE_SHIFT)) & DDRC_PMLCA3_CE_MASK)

#define DDRC_PMLCA3_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA3_FC_SHIFT                     (31U)
#define DDRC_PMLCA3_FC_WIDTH                     (1U)
#define DDRC_PMLCA3_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_FC_SHIFT)) & DDRC_PMLCA3_FC_MASK)
/*! @} */

/*! @name PMLCB3 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB3_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB3_THRESHOLD_SHIFT              (0U)
#define DDRC_PMLCB3_THRESHOLD_WIDTH              (6U)
#define DDRC_PMLCB3_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_THRESHOLD_SHIFT)) & DDRC_PMLCB3_THRESHOLD_MASK)

#define DDRC_PMLCB3_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB3_TBMULT_SHIFT                 (8U)
#define DDRC_PMLCB3_TBMULT_WIDTH                 (3U)
#define DDRC_PMLCB3_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_TBMULT_SHIFT)) & DDRC_PMLCB3_TBMULT_MASK)

#define DDRC_PMLCB3_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB3_TRIGOFFCNTL_SHIFT            (16U)
#define DDRC_PMLCB3_TRIGOFFCNTL_WIDTH            (2U)
#define DDRC_PMLCB3_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB3_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB3_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB3_TRIGONCNTL_SHIFT             (18U)
#define DDRC_PMLCB3_TRIGONCNTL_WIDTH             (2U)
#define DDRC_PMLCB3_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_TRIGONCNTL_SHIFT)) & DDRC_PMLCB3_TRIGONCNTL_MASK)

#define DDRC_PMLCB3_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB3_TRIGOFFSEL_SHIFT             (20U)
#define DDRC_PMLCB3_TRIGOFFSEL_WIDTH             (4U)
#define DDRC_PMLCB3_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB3_TRIGOFFSEL_MASK)

#define DDRC_PMLCB3_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB3_TRIGONSEL_SHIFT              (26U)
#define DDRC_PMLCB3_TRIGONSEL_WIDTH              (4U)
#define DDRC_PMLCB3_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_TRIGONSEL_SHIFT)) & DDRC_PMLCB3_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC3 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC3_PMC3_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC3_PMC3_SHIFT                     (0U)
#define DDRC_PMC3_PMC3_WIDTH                     (32U)
#define DDRC_PMC3_PMC3(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC3_PMC3_SHIFT)) & DDRC_PMC3_PMC3_MASK)
/*! @} */

/*! @name PMLCA4 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA4_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA4_BDIST_SHIFT                  (0U)
#define DDRC_PMLCA4_BDIST_WIDTH                  (6U)
#define DDRC_PMLCA4_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_BDIST_SHIFT)) & DDRC_PMLCA4_BDIST_MASK)

#define DDRC_PMLCA4_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA4_BGRAN_SHIFT                  (6U)
#define DDRC_PMLCA4_BGRAN_WIDTH                  (5U)
#define DDRC_PMLCA4_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_BGRAN_SHIFT)) & DDRC_PMLCA4_BGRAN_MASK)

#define DDRC_PMLCA4_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA4_BSIZE_SHIFT                  (11U)
#define DDRC_PMLCA4_BSIZE_WIDTH                  (5U)
#define DDRC_PMLCA4_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_BSIZE_SHIFT)) & DDRC_PMLCA4_BSIZE_MASK)

#define DDRC_PMLCA4_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA4_EVENT_SHIFT                  (16U)
#define DDRC_PMLCA4_EVENT_WIDTH                  (7U)
#define DDRC_PMLCA4_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_EVENT_SHIFT)) & DDRC_PMLCA4_EVENT_MASK)

#define DDRC_PMLCA4_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA4_CE_SHIFT                     (26U)
#define DDRC_PMLCA4_CE_WIDTH                     (1U)
#define DDRC_PMLCA4_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_CE_SHIFT)) & DDRC_PMLCA4_CE_MASK)

#define DDRC_PMLCA4_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA4_FC_SHIFT                     (31U)
#define DDRC_PMLCA4_FC_WIDTH                     (1U)
#define DDRC_PMLCA4_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_FC_SHIFT)) & DDRC_PMLCA4_FC_MASK)
/*! @} */

/*! @name PMLCB4 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB4_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB4_THRESHOLD_SHIFT              (0U)
#define DDRC_PMLCB4_THRESHOLD_WIDTH              (6U)
#define DDRC_PMLCB4_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_THRESHOLD_SHIFT)) & DDRC_PMLCB4_THRESHOLD_MASK)

#define DDRC_PMLCB4_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB4_TBMULT_SHIFT                 (8U)
#define DDRC_PMLCB4_TBMULT_WIDTH                 (3U)
#define DDRC_PMLCB4_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_TBMULT_SHIFT)) & DDRC_PMLCB4_TBMULT_MASK)

#define DDRC_PMLCB4_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB4_TRIGOFFCNTL_SHIFT            (16U)
#define DDRC_PMLCB4_TRIGOFFCNTL_WIDTH            (2U)
#define DDRC_PMLCB4_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB4_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB4_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB4_TRIGONCNTL_SHIFT             (18U)
#define DDRC_PMLCB4_TRIGONCNTL_WIDTH             (2U)
#define DDRC_PMLCB4_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_TRIGONCNTL_SHIFT)) & DDRC_PMLCB4_TRIGONCNTL_MASK)

#define DDRC_PMLCB4_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB4_TRIGOFFSEL_SHIFT             (20U)
#define DDRC_PMLCB4_TRIGOFFSEL_WIDTH             (4U)
#define DDRC_PMLCB4_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB4_TRIGOFFSEL_MASK)

#define DDRC_PMLCB4_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB4_TRIGONSEL_SHIFT              (26U)
#define DDRC_PMLCB4_TRIGONSEL_WIDTH              (4U)
#define DDRC_PMLCB4_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_TRIGONSEL_SHIFT)) & DDRC_PMLCB4_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC4 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC4_PMC4_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC4_PMC4_SHIFT                     (0U)
#define DDRC_PMC4_PMC4_WIDTH                     (32U)
#define DDRC_PMC4_PMC4(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC4_PMC4_SHIFT)) & DDRC_PMC4_PMC4_MASK)
/*! @} */

/*! @name PMLCA5 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA5_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA5_BDIST_SHIFT                  (0U)
#define DDRC_PMLCA5_BDIST_WIDTH                  (6U)
#define DDRC_PMLCA5_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_BDIST_SHIFT)) & DDRC_PMLCA5_BDIST_MASK)

#define DDRC_PMLCA5_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA5_BGRAN_SHIFT                  (6U)
#define DDRC_PMLCA5_BGRAN_WIDTH                  (5U)
#define DDRC_PMLCA5_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_BGRAN_SHIFT)) & DDRC_PMLCA5_BGRAN_MASK)

#define DDRC_PMLCA5_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA5_BSIZE_SHIFT                  (11U)
#define DDRC_PMLCA5_BSIZE_WIDTH                  (5U)
#define DDRC_PMLCA5_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_BSIZE_SHIFT)) & DDRC_PMLCA5_BSIZE_MASK)

#define DDRC_PMLCA5_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA5_EVENT_SHIFT                  (16U)
#define DDRC_PMLCA5_EVENT_WIDTH                  (7U)
#define DDRC_PMLCA5_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_EVENT_SHIFT)) & DDRC_PMLCA5_EVENT_MASK)

#define DDRC_PMLCA5_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA5_CE_SHIFT                     (26U)
#define DDRC_PMLCA5_CE_WIDTH                     (1U)
#define DDRC_PMLCA5_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_CE_SHIFT)) & DDRC_PMLCA5_CE_MASK)

#define DDRC_PMLCA5_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA5_FC_SHIFT                     (31U)
#define DDRC_PMLCA5_FC_WIDTH                     (1U)
#define DDRC_PMLCA5_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_FC_SHIFT)) & DDRC_PMLCA5_FC_MASK)
/*! @} */

/*! @name PMLCB5 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB5_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB5_THRESHOLD_SHIFT              (0U)
#define DDRC_PMLCB5_THRESHOLD_WIDTH              (6U)
#define DDRC_PMLCB5_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_THRESHOLD_SHIFT)) & DDRC_PMLCB5_THRESHOLD_MASK)

#define DDRC_PMLCB5_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB5_TBMULT_SHIFT                 (8U)
#define DDRC_PMLCB5_TBMULT_WIDTH                 (3U)
#define DDRC_PMLCB5_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_TBMULT_SHIFT)) & DDRC_PMLCB5_TBMULT_MASK)

#define DDRC_PMLCB5_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB5_TRIGOFFCNTL_SHIFT            (16U)
#define DDRC_PMLCB5_TRIGOFFCNTL_WIDTH            (2U)
#define DDRC_PMLCB5_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB5_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB5_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB5_TRIGONCNTL_SHIFT             (18U)
#define DDRC_PMLCB5_TRIGONCNTL_WIDTH             (2U)
#define DDRC_PMLCB5_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_TRIGONCNTL_SHIFT)) & DDRC_PMLCB5_TRIGONCNTL_MASK)

#define DDRC_PMLCB5_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB5_TRIGOFFSEL_SHIFT             (20U)
#define DDRC_PMLCB5_TRIGOFFSEL_WIDTH             (4U)
#define DDRC_PMLCB5_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB5_TRIGOFFSEL_MASK)

#define DDRC_PMLCB5_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB5_TRIGONSEL_SHIFT              (26U)
#define DDRC_PMLCB5_TRIGONSEL_WIDTH              (4U)
#define DDRC_PMLCB5_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_TRIGONSEL_SHIFT)) & DDRC_PMLCB5_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC5 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC5_PMC5_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC5_PMC5_SHIFT                     (0U)
#define DDRC_PMC5_PMC5_WIDTH                     (32U)
#define DDRC_PMC5_PMC5(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC5_PMC5_SHIFT)) & DDRC_PMC5_PMC5_MASK)
/*! @} */

/*! @name PMLCA6 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA6_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA6_BDIST_SHIFT                  (0U)
#define DDRC_PMLCA6_BDIST_WIDTH                  (6U)
#define DDRC_PMLCA6_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_BDIST_SHIFT)) & DDRC_PMLCA6_BDIST_MASK)

#define DDRC_PMLCA6_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA6_BGRAN_SHIFT                  (6U)
#define DDRC_PMLCA6_BGRAN_WIDTH                  (5U)
#define DDRC_PMLCA6_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_BGRAN_SHIFT)) & DDRC_PMLCA6_BGRAN_MASK)

#define DDRC_PMLCA6_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA6_BSIZE_SHIFT                  (11U)
#define DDRC_PMLCA6_BSIZE_WIDTH                  (5U)
#define DDRC_PMLCA6_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_BSIZE_SHIFT)) & DDRC_PMLCA6_BSIZE_MASK)

#define DDRC_PMLCA6_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA6_EVENT_SHIFT                  (16U)
#define DDRC_PMLCA6_EVENT_WIDTH                  (7U)
#define DDRC_PMLCA6_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_EVENT_SHIFT)) & DDRC_PMLCA6_EVENT_MASK)

#define DDRC_PMLCA6_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA6_CE_SHIFT                     (26U)
#define DDRC_PMLCA6_CE_WIDTH                     (1U)
#define DDRC_PMLCA6_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_CE_SHIFT)) & DDRC_PMLCA6_CE_MASK)

#define DDRC_PMLCA6_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA6_FC_SHIFT                     (31U)
#define DDRC_PMLCA6_FC_WIDTH                     (1U)
#define DDRC_PMLCA6_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_FC_SHIFT)) & DDRC_PMLCA6_FC_MASK)
/*! @} */

/*! @name PMLCB6 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB6_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB6_THRESHOLD_SHIFT              (0U)
#define DDRC_PMLCB6_THRESHOLD_WIDTH              (6U)
#define DDRC_PMLCB6_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_THRESHOLD_SHIFT)) & DDRC_PMLCB6_THRESHOLD_MASK)

#define DDRC_PMLCB6_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB6_TBMULT_SHIFT                 (8U)
#define DDRC_PMLCB6_TBMULT_WIDTH                 (3U)
#define DDRC_PMLCB6_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_TBMULT_SHIFT)) & DDRC_PMLCB6_TBMULT_MASK)

#define DDRC_PMLCB6_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB6_TRIGOFFCNTL_SHIFT            (16U)
#define DDRC_PMLCB6_TRIGOFFCNTL_WIDTH            (2U)
#define DDRC_PMLCB6_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB6_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB6_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB6_TRIGONCNTL_SHIFT             (18U)
#define DDRC_PMLCB6_TRIGONCNTL_WIDTH             (2U)
#define DDRC_PMLCB6_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_TRIGONCNTL_SHIFT)) & DDRC_PMLCB6_TRIGONCNTL_MASK)

#define DDRC_PMLCB6_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB6_TRIGOFFSEL_SHIFT             (20U)
#define DDRC_PMLCB6_TRIGOFFSEL_WIDTH             (4U)
#define DDRC_PMLCB6_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB6_TRIGOFFSEL_MASK)

#define DDRC_PMLCB6_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB6_TRIGONSEL_SHIFT              (26U)
#define DDRC_PMLCB6_TRIGONSEL_WIDTH              (4U)
#define DDRC_PMLCB6_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_TRIGONSEL_SHIFT)) & DDRC_PMLCB6_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC6 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC6_PMC6_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC6_PMC6_SHIFT                     (0U)
#define DDRC_PMC6_PMC6_WIDTH                     (32U)
#define DDRC_PMC6_PMC6(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC6_PMC6_SHIFT)) & DDRC_PMC6_PMC6_MASK)
/*! @} */

/*! @name PMLCA7 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA7_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA7_BDIST_SHIFT                  (0U)
#define DDRC_PMLCA7_BDIST_WIDTH                  (6U)
#define DDRC_PMLCA7_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_BDIST_SHIFT)) & DDRC_PMLCA7_BDIST_MASK)

#define DDRC_PMLCA7_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA7_BGRAN_SHIFT                  (6U)
#define DDRC_PMLCA7_BGRAN_WIDTH                  (5U)
#define DDRC_PMLCA7_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_BGRAN_SHIFT)) & DDRC_PMLCA7_BGRAN_MASK)

#define DDRC_PMLCA7_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA7_BSIZE_SHIFT                  (11U)
#define DDRC_PMLCA7_BSIZE_WIDTH                  (5U)
#define DDRC_PMLCA7_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_BSIZE_SHIFT)) & DDRC_PMLCA7_BSIZE_MASK)

#define DDRC_PMLCA7_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA7_EVENT_SHIFT                  (16U)
#define DDRC_PMLCA7_EVENT_WIDTH                  (7U)
#define DDRC_PMLCA7_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_EVENT_SHIFT)) & DDRC_PMLCA7_EVENT_MASK)

#define DDRC_PMLCA7_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA7_CE_SHIFT                     (26U)
#define DDRC_PMLCA7_CE_WIDTH                     (1U)
#define DDRC_PMLCA7_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_CE_SHIFT)) & DDRC_PMLCA7_CE_MASK)

#define DDRC_PMLCA7_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA7_FC_SHIFT                     (31U)
#define DDRC_PMLCA7_FC_WIDTH                     (1U)
#define DDRC_PMLCA7_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_FC_SHIFT)) & DDRC_PMLCA7_FC_MASK)
/*! @} */

/*! @name PMLCB7 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB7_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB7_THRESHOLD_SHIFT              (0U)
#define DDRC_PMLCB7_THRESHOLD_WIDTH              (6U)
#define DDRC_PMLCB7_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_THRESHOLD_SHIFT)) & DDRC_PMLCB7_THRESHOLD_MASK)

#define DDRC_PMLCB7_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB7_TBMULT_SHIFT                 (8U)
#define DDRC_PMLCB7_TBMULT_WIDTH                 (3U)
#define DDRC_PMLCB7_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_TBMULT_SHIFT)) & DDRC_PMLCB7_TBMULT_MASK)

#define DDRC_PMLCB7_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB7_TRIGOFFCNTL_SHIFT            (16U)
#define DDRC_PMLCB7_TRIGOFFCNTL_WIDTH            (2U)
#define DDRC_PMLCB7_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB7_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB7_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB7_TRIGONCNTL_SHIFT             (18U)
#define DDRC_PMLCB7_TRIGONCNTL_WIDTH             (2U)
#define DDRC_PMLCB7_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_TRIGONCNTL_SHIFT)) & DDRC_PMLCB7_TRIGONCNTL_MASK)

#define DDRC_PMLCB7_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB7_TRIGOFFSEL_SHIFT             (20U)
#define DDRC_PMLCB7_TRIGOFFSEL_WIDTH             (4U)
#define DDRC_PMLCB7_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB7_TRIGOFFSEL_MASK)

#define DDRC_PMLCB7_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB7_TRIGONSEL_SHIFT              (26U)
#define DDRC_PMLCB7_TRIGONSEL_WIDTH              (4U)
#define DDRC_PMLCB7_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_TRIGONSEL_SHIFT)) & DDRC_PMLCB7_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC7 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC7_PMC7_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC7_PMC7_SHIFT                     (0U)
#define DDRC_PMC7_PMC7_WIDTH                     (32U)
#define DDRC_PMC7_PMC7(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC7_PMC7_SHIFT)) & DDRC_PMC7_PMC7_MASK)
/*! @} */

/*! @name PMLCA8 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA8_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA8_BDIST_SHIFT                  (0U)
#define DDRC_PMLCA8_BDIST_WIDTH                  (6U)
#define DDRC_PMLCA8_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_BDIST_SHIFT)) & DDRC_PMLCA8_BDIST_MASK)

#define DDRC_PMLCA8_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA8_BGRAN_SHIFT                  (6U)
#define DDRC_PMLCA8_BGRAN_WIDTH                  (5U)
#define DDRC_PMLCA8_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_BGRAN_SHIFT)) & DDRC_PMLCA8_BGRAN_MASK)

#define DDRC_PMLCA8_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA8_BSIZE_SHIFT                  (11U)
#define DDRC_PMLCA8_BSIZE_WIDTH                  (5U)
#define DDRC_PMLCA8_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_BSIZE_SHIFT)) & DDRC_PMLCA8_BSIZE_MASK)

#define DDRC_PMLCA8_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA8_EVENT_SHIFT                  (16U)
#define DDRC_PMLCA8_EVENT_WIDTH                  (7U)
#define DDRC_PMLCA8_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_EVENT_SHIFT)) & DDRC_PMLCA8_EVENT_MASK)

#define DDRC_PMLCA8_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA8_CE_SHIFT                     (26U)
#define DDRC_PMLCA8_CE_WIDTH                     (1U)
#define DDRC_PMLCA8_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_CE_SHIFT)) & DDRC_PMLCA8_CE_MASK)

#define DDRC_PMLCA8_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA8_FC_SHIFT                     (31U)
#define DDRC_PMLCA8_FC_WIDTH                     (1U)
#define DDRC_PMLCA8_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_FC_SHIFT)) & DDRC_PMLCA8_FC_MASK)
/*! @} */

/*! @name PMLCB8 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB8_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB8_THRESHOLD_SHIFT              (0U)
#define DDRC_PMLCB8_THRESHOLD_WIDTH              (6U)
#define DDRC_PMLCB8_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_THRESHOLD_SHIFT)) & DDRC_PMLCB8_THRESHOLD_MASK)

#define DDRC_PMLCB8_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB8_TBMULT_SHIFT                 (8U)
#define DDRC_PMLCB8_TBMULT_WIDTH                 (3U)
#define DDRC_PMLCB8_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_TBMULT_SHIFT)) & DDRC_PMLCB8_TBMULT_MASK)

#define DDRC_PMLCB8_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB8_TRIGOFFCNTL_SHIFT            (16U)
#define DDRC_PMLCB8_TRIGOFFCNTL_WIDTH            (2U)
#define DDRC_PMLCB8_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB8_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB8_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB8_TRIGONCNTL_SHIFT             (18U)
#define DDRC_PMLCB8_TRIGONCNTL_WIDTH             (2U)
#define DDRC_PMLCB8_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_TRIGONCNTL_SHIFT)) & DDRC_PMLCB8_TRIGONCNTL_MASK)

#define DDRC_PMLCB8_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB8_TRIGOFFSEL_SHIFT             (20U)
#define DDRC_PMLCB8_TRIGOFFSEL_WIDTH             (4U)
#define DDRC_PMLCB8_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB8_TRIGOFFSEL_MASK)

#define DDRC_PMLCB8_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB8_TRIGONSEL_SHIFT              (26U)
#define DDRC_PMLCB8_TRIGONSEL_WIDTH              (4U)
#define DDRC_PMLCB8_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_TRIGONSEL_SHIFT)) & DDRC_PMLCB8_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC8 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC8_PMC8_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC8_PMC8_SHIFT                     (0U)
#define DDRC_PMC8_PMC8_WIDTH                     (32U)
#define DDRC_PMC8_PMC8(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC8_PMC8_SHIFT)) & DDRC_PMC8_PMC8_MASK)
/*! @} */

/*! @name PMLCA9 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA9_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA9_BDIST_SHIFT                  (0U)
#define DDRC_PMLCA9_BDIST_WIDTH                  (6U)
#define DDRC_PMLCA9_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_BDIST_SHIFT)) & DDRC_PMLCA9_BDIST_MASK)

#define DDRC_PMLCA9_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA9_BGRAN_SHIFT                  (6U)
#define DDRC_PMLCA9_BGRAN_WIDTH                  (5U)
#define DDRC_PMLCA9_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_BGRAN_SHIFT)) & DDRC_PMLCA9_BGRAN_MASK)

#define DDRC_PMLCA9_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA9_BSIZE_SHIFT                  (11U)
#define DDRC_PMLCA9_BSIZE_WIDTH                  (5U)
#define DDRC_PMLCA9_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_BSIZE_SHIFT)) & DDRC_PMLCA9_BSIZE_MASK)

#define DDRC_PMLCA9_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA9_EVENT_SHIFT                  (16U)
#define DDRC_PMLCA9_EVENT_WIDTH                  (7U)
#define DDRC_PMLCA9_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_EVENT_SHIFT)) & DDRC_PMLCA9_EVENT_MASK)

#define DDRC_PMLCA9_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA9_CE_SHIFT                     (26U)
#define DDRC_PMLCA9_CE_WIDTH                     (1U)
#define DDRC_PMLCA9_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_CE_SHIFT)) & DDRC_PMLCA9_CE_MASK)

#define DDRC_PMLCA9_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA9_FC_SHIFT                     (31U)
#define DDRC_PMLCA9_FC_WIDTH                     (1U)
#define DDRC_PMLCA9_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_FC_SHIFT)) & DDRC_PMLCA9_FC_MASK)
/*! @} */

/*! @name PMLCB9 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB9_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB9_THRESHOLD_SHIFT              (0U)
#define DDRC_PMLCB9_THRESHOLD_WIDTH              (6U)
#define DDRC_PMLCB9_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_THRESHOLD_SHIFT)) & DDRC_PMLCB9_THRESHOLD_MASK)

#define DDRC_PMLCB9_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB9_TBMULT_SHIFT                 (8U)
#define DDRC_PMLCB9_TBMULT_WIDTH                 (3U)
#define DDRC_PMLCB9_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_TBMULT_SHIFT)) & DDRC_PMLCB9_TBMULT_MASK)

#define DDRC_PMLCB9_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB9_TRIGOFFCNTL_SHIFT            (16U)
#define DDRC_PMLCB9_TRIGOFFCNTL_WIDTH            (2U)
#define DDRC_PMLCB9_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB9_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB9_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB9_TRIGONCNTL_SHIFT             (18U)
#define DDRC_PMLCB9_TRIGONCNTL_WIDTH             (2U)
#define DDRC_PMLCB9_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_TRIGONCNTL_SHIFT)) & DDRC_PMLCB9_TRIGONCNTL_MASK)

#define DDRC_PMLCB9_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB9_TRIGOFFSEL_SHIFT             (20U)
#define DDRC_PMLCB9_TRIGOFFSEL_WIDTH             (4U)
#define DDRC_PMLCB9_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB9_TRIGOFFSEL_MASK)

#define DDRC_PMLCB9_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB9_TRIGONSEL_SHIFT              (26U)
#define DDRC_PMLCB9_TRIGONSEL_WIDTH              (4U)
#define DDRC_PMLCB9_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_TRIGONSEL_SHIFT)) & DDRC_PMLCB9_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC9 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC9_PMC9_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC9_PMC9_SHIFT                     (0U)
#define DDRC_PMC9_PMC9_WIDTH                     (32U)
#define DDRC_PMC9_PMC9(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC9_PMC9_SHIFT)) & DDRC_PMC9_PMC9_MASK)
/*! @} */

/*! @name PMLCA10 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA10_BDIST_MASK                  (0x3FU)
#define DDRC_PMLCA10_BDIST_SHIFT                 (0U)
#define DDRC_PMLCA10_BDIST_WIDTH                 (6U)
#define DDRC_PMLCA10_BDIST(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_BDIST_SHIFT)) & DDRC_PMLCA10_BDIST_MASK)

#define DDRC_PMLCA10_BGRAN_MASK                  (0x7C0U)
#define DDRC_PMLCA10_BGRAN_SHIFT                 (6U)
#define DDRC_PMLCA10_BGRAN_WIDTH                 (5U)
#define DDRC_PMLCA10_BGRAN(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_BGRAN_SHIFT)) & DDRC_PMLCA10_BGRAN_MASK)

#define DDRC_PMLCA10_BSIZE_MASK                  (0xF800U)
#define DDRC_PMLCA10_BSIZE_SHIFT                 (11U)
#define DDRC_PMLCA10_BSIZE_WIDTH                 (5U)
#define DDRC_PMLCA10_BSIZE(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_BSIZE_SHIFT)) & DDRC_PMLCA10_BSIZE_MASK)

#define DDRC_PMLCA10_EVENT_MASK                  (0x7F0000U)
#define DDRC_PMLCA10_EVENT_SHIFT                 (16U)
#define DDRC_PMLCA10_EVENT_WIDTH                 (7U)
#define DDRC_PMLCA10_EVENT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_EVENT_SHIFT)) & DDRC_PMLCA10_EVENT_MASK)

#define DDRC_PMLCA10_CE_MASK                     (0x4000000U)
#define DDRC_PMLCA10_CE_SHIFT                    (26U)
#define DDRC_PMLCA10_CE_WIDTH                    (1U)
#define DDRC_PMLCA10_CE(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_CE_SHIFT)) & DDRC_PMLCA10_CE_MASK)

#define DDRC_PMLCA10_FC_MASK                     (0x80000000U)
#define DDRC_PMLCA10_FC_SHIFT                    (31U)
#define DDRC_PMLCA10_FC_WIDTH                    (1U)
#define DDRC_PMLCA10_FC(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_FC_SHIFT)) & DDRC_PMLCA10_FC_MASK)
/*! @} */

/*! @name PMLCB10 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB10_THRESHOLD_MASK              (0x3FU)
#define DDRC_PMLCB10_THRESHOLD_SHIFT             (0U)
#define DDRC_PMLCB10_THRESHOLD_WIDTH             (6U)
#define DDRC_PMLCB10_THRESHOLD(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_THRESHOLD_SHIFT)) & DDRC_PMLCB10_THRESHOLD_MASK)

#define DDRC_PMLCB10_TBMULT_MASK                 (0x700U)
#define DDRC_PMLCB10_TBMULT_SHIFT                (8U)
#define DDRC_PMLCB10_TBMULT_WIDTH                (3U)
#define DDRC_PMLCB10_TBMULT(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_TBMULT_SHIFT)) & DDRC_PMLCB10_TBMULT_MASK)

#define DDRC_PMLCB10_TRIGOFFCNTL_MASK            (0x30000U)
#define DDRC_PMLCB10_TRIGOFFCNTL_SHIFT           (16U)
#define DDRC_PMLCB10_TRIGOFFCNTL_WIDTH           (2U)
#define DDRC_PMLCB10_TRIGOFFCNTL(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB10_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB10_TRIGONCNTL_MASK             (0xC0000U)
#define DDRC_PMLCB10_TRIGONCNTL_SHIFT            (18U)
#define DDRC_PMLCB10_TRIGONCNTL_WIDTH            (2U)
#define DDRC_PMLCB10_TRIGONCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_TRIGONCNTL_SHIFT)) & DDRC_PMLCB10_TRIGONCNTL_MASK)

#define DDRC_PMLCB10_TRIGOFFSEL_MASK             (0xF00000U)
#define DDRC_PMLCB10_TRIGOFFSEL_SHIFT            (20U)
#define DDRC_PMLCB10_TRIGOFFSEL_WIDTH            (4U)
#define DDRC_PMLCB10_TRIGOFFSEL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB10_TRIGOFFSEL_MASK)

#define DDRC_PMLCB10_TRIGONSEL_MASK              (0x3C000000U)
#define DDRC_PMLCB10_TRIGONSEL_SHIFT             (26U)
#define DDRC_PMLCB10_TRIGONSEL_WIDTH             (4U)
#define DDRC_PMLCB10_TRIGONSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_TRIGONSEL_SHIFT)) & DDRC_PMLCB10_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC10 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC10_PMC10_MASK                    (0xFFFFFFFFU)
#define DDRC_PMC10_PMC10_SHIFT                   (0U)
#define DDRC_PMC10_PMC10_WIDTH                   (32U)
#define DDRC_PMC10_PMC10(x)                      (((uint32_t)(((uint32_t)(x)) << DDRC_PMC10_PMC10_SHIFT)) & DDRC_PMC10_PMC10_MASK)
/*! @} */

/*! @name ERR_EN - Error Enable */
/*! @{ */

#define DDRC_ERR_EN_WTE_EN_MASK                  (0x1U)
#define DDRC_ERR_EN_WTE_EN_SHIFT                 (0U)
#define DDRC_ERR_EN_WTE_EN_WIDTH                 (1U)
#define DDRC_ERR_EN_WTE_EN(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_WTE_EN_SHIFT)) & DDRC_ERR_EN_WTE_EN_MASK)

#define DDRC_ERR_EN_RTE_EN_MASK                  (0x2U)
#define DDRC_ERR_EN_RTE_EN_SHIFT                 (1U)
#define DDRC_ERR_EN_RTE_EN_WIDTH                 (1U)
#define DDRC_ERR_EN_RTE_EN(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_RTE_EN_SHIFT)) & DDRC_ERR_EN_RTE_EN_MASK)

#define DDRC_ERR_EN_LKSTP_2_EN_MASK              (0x4U)
#define DDRC_ERR_EN_LKSTP_2_EN_SHIFT             (2U)
#define DDRC_ERR_EN_LKSTP_2_EN_WIDTH             (1U)
#define DDRC_ERR_EN_LKSTP_2_EN(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_LKSTP_2_EN_SHIFT)) & DDRC_ERR_EN_LKSTP_2_EN_MASK)

#define DDRC_ERR_EN_LKSTP_1_EN_MASK              (0x8U)
#define DDRC_ERR_EN_LKSTP_1_EN_SHIFT             (3U)
#define DDRC_ERR_EN_LKSTP_1_EN_WIDTH             (1U)
#define DDRC_ERR_EN_LKSTP_1_EN(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_LKSTP_1_EN_SHIFT)) & DDRC_ERR_EN_LKSTP_1_EN_MASK)

#define DDRC_ERR_EN_PAR_1_EN_MASK                (0x20U)
#define DDRC_ERR_EN_PAR_1_EN_SHIFT               (5U)
#define DDRC_ERR_EN_PAR_1_EN_WIDTH               (1U)
#define DDRC_ERR_EN_PAR_1_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_PAR_1_EN_SHIFT)) & DDRC_ERR_EN_PAR_1_EN_MASK)

#define DDRC_ERR_EN_ECC_EN_RAM_2_MASK            (0x40U)
#define DDRC_ERR_EN_ECC_EN_RAM_2_SHIFT           (6U)
#define DDRC_ERR_EN_ECC_EN_RAM_2_WIDTH           (1U)
#define DDRC_ERR_EN_ECC_EN_RAM_2(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_ECC_EN_RAM_2_SHIFT)) & DDRC_ERR_EN_ECC_EN_RAM_2_MASK)

#define DDRC_ERR_EN_ECC_EN_RAM_1_MASK            (0x80U)
#define DDRC_ERR_EN_ECC_EN_RAM_1_SHIFT           (7U)
#define DDRC_ERR_EN_ECC_EN_RAM_1_WIDTH           (1U)
#define DDRC_ERR_EN_ECC_EN_RAM_1(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_ECC_EN_RAM_1_SHIFT)) & DDRC_ERR_EN_ECC_EN_RAM_1_MASK)

#define DDRC_ERR_EN_CRC_2_EN_MASK                (0x100U)
#define DDRC_ERR_EN_CRC_2_EN_SHIFT               (8U)
#define DDRC_ERR_EN_CRC_2_EN_WIDTH               (1U)
#define DDRC_ERR_EN_CRC_2_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_CRC_2_EN_SHIFT)) & DDRC_ERR_EN_CRC_2_EN_MASK)

#define DDRC_ERR_EN_CRC_1_EN_MASK                (0x200U)
#define DDRC_ERR_EN_CRC_1_EN_SHIFT               (9U)
#define DDRC_ERR_EN_CRC_1_EN_WIDTH               (1U)
#define DDRC_ERR_EN_CRC_1_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_CRC_1_EN_SHIFT)) & DDRC_ERR_EN_CRC_1_EN_MASK)

#define DDRC_ERR_EN_INLINE_ECC_EN_MASK           (0x40000000U)
#define DDRC_ERR_EN_INLINE_ECC_EN_SHIFT          (30U)
#define DDRC_ERR_EN_INLINE_ECC_EN_WIDTH          (1U)
#define DDRC_ERR_EN_INLINE_ECC_EN(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_INLINE_ECC_EN_SHIFT)) & DDRC_ERR_EN_INLINE_ECC_EN_MASK)

#define DDRC_ERR_EN_ECC_EN_MASK                  (0x80000000U)
#define DDRC_ERR_EN_ECC_EN_SHIFT                 (31U)
#define DDRC_ERR_EN_ECC_EN_WIDTH                 (1U)
#define DDRC_ERR_EN_ECC_EN(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_ECC_EN_SHIFT)) & DDRC_ERR_EN_ECC_EN_MASK)
/*! @} */

/*! @name DATA_ERR_INJECT_HI - Memory Data Path Error Injection Mask High */
/*! @{ */

#define DDRC_DATA_ERR_INJECT_HI_EIMH_MASK        (0xFFFFFFFFU)
#define DDRC_DATA_ERR_INJECT_HI_EIMH_SHIFT       (0U)
#define DDRC_DATA_ERR_INJECT_HI_EIMH_WIDTH       (32U)
#define DDRC_DATA_ERR_INJECT_HI_EIMH(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DATA_ERR_INJECT_HI_EIMH_SHIFT)) & DDRC_DATA_ERR_INJECT_HI_EIMH_MASK)
/*! @} */

/*! @name DATA_ERR_INJECT_LO - Memory Data Path Error Injection Mask Low */
/*! @{ */

#define DDRC_DATA_ERR_INJECT_LO_EIML_MASK        (0xFFFFFFFFU)
#define DDRC_DATA_ERR_INJECT_LO_EIML_SHIFT       (0U)
#define DDRC_DATA_ERR_INJECT_LO_EIML_WIDTH       (32U)
#define DDRC_DATA_ERR_INJECT_LO_EIML(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DATA_ERR_INJECT_LO_EIML_SHIFT)) & DDRC_DATA_ERR_INJECT_LO_EIML_MASK)
/*! @} */

/*! @name ERR_INJECT - Memory Data Path Error Injection Mask ECC */
/*! @{ */

#define DDRC_ERR_INJECT_EEIM_MASK                (0xFFU)
#define DDRC_ERR_INJECT_EEIM_SHIFT               (0U)
#define DDRC_ERR_INJECT_EEIM_WIDTH               (8U)
#define DDRC_ERR_INJECT_EEIM(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_EEIM_SHIFT)) & DDRC_ERR_INJECT_EEIM_MASK)

#define DDRC_ERR_INJECT_EIEN_MASK                (0x100U)
#define DDRC_ERR_INJECT_EIEN_SHIFT               (8U)
#define DDRC_ERR_INJECT_EIEN_WIDTH               (1U)
#define DDRC_ERR_INJECT_EIEN(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_EIEN_SHIFT)) & DDRC_ERR_INJECT_EIEN_MASK)

#define DDRC_ERR_INJECT_NUM_ECC_INJ_MASK         (0xF000U)
#define DDRC_ERR_INJECT_NUM_ECC_INJ_SHIFT        (12U)
#define DDRC_ERR_INJECT_NUM_ECC_INJ_WIDTH        (4U)
#define DDRC_ERR_INJECT_NUM_ECC_INJ(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_NUM_ECC_INJ_SHIFT)) & DDRC_ERR_INJECT_NUM_ECC_INJ_MASK)

#define DDRC_ERR_INJECT_PIEN_MASK                (0x10000U)
#define DDRC_ERR_INJECT_PIEN_SHIFT               (16U)
#define DDRC_ERR_INJECT_PIEN_WIDTH               (1U)
#define DDRC_ERR_INJECT_PIEN(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_PIEN_SHIFT)) & DDRC_ERR_INJECT_PIEN_MASK)

#define DDRC_ERR_INJECT_INTEIN_MASK              (0x20000U)
#define DDRC_ERR_INJECT_INTEIN_SHIFT             (17U)
#define DDRC_ERR_INJECT_INTEIN_WIDTH             (1U)
#define DDRC_ERR_INJECT_INTEIN(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_INTEIN_SHIFT)) & DDRC_ERR_INJECT_INTEIN_MASK)

#define DDRC_ERR_INJECT_INTIES_MASK              (0x1C0000U)
#define DDRC_ERR_INJECT_INTIES_SHIFT             (18U)
#define DDRC_ERR_INJECT_INTIES_WIDTH             (3U)
#define DDRC_ERR_INJECT_INTIES(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_INTIES_SHIFT)) & DDRC_ERR_INJECT_INTIES_MASK)

#define DDRC_ERR_INJECT_ECC_INJ_SRC_MASK         (0x600000U)
#define DDRC_ERR_INJECT_ECC_INJ_SRC_SHIFT        (21U)
#define DDRC_ERR_INJECT_ECC_INJ_SRC_WIDTH        (2U)
#define DDRC_ERR_INJECT_ECC_INJ_SRC(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_ECC_INJ_SRC_SHIFT)) & DDRC_ERR_INJECT_ECC_INJ_SRC_MASK)

#define DDRC_ERR_INJECT_FRC2B_MASK               (0x800000U)
#define DDRC_ERR_INJECT_FRC2B_SHIFT              (23U)
#define DDRC_ERR_INJECT_FRC2B_WIDTH              (1U)
#define DDRC_ERR_INJECT_FRC2B(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_FRC2B_SHIFT)) & DDRC_ERR_INJECT_FRC2B_MASK)

#define DDRC_ERR_INJECT_PAR_INJ_SRC_MASK         (0x3000000U)
#define DDRC_ERR_INJECT_PAR_INJ_SRC_SHIFT        (24U)
#define DDRC_ERR_INJECT_PAR_INJ_SRC_WIDTH        (2U)
#define DDRC_ERR_INJECT_PAR_INJ_SRC(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_PAR_INJ_SRC_SHIFT)) & DDRC_ERR_INJECT_PAR_INJ_SRC_MASK)

#define DDRC_ERR_INJECT_ADDR_TEN_MASK            (0x80000000U)
#define DDRC_ERR_INJECT_ADDR_TEN_SHIFT           (31U)
#define DDRC_ERR_INJECT_ADDR_TEN_WIDTH           (1U)
#define DDRC_ERR_INJECT_ADDR_TEN(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_ADDR_TEN_SHIFT)) & DDRC_ERR_INJECT_ADDR_TEN_MASK)
/*! @} */

/*! @name ADDR_ERR_INJ - Address Error Inject */
/*! @{ */

#define DDRC_ADDR_ERR_INJ_ADDR_MASK              (0xFFFFFFFFU)
#define DDRC_ADDR_ERR_INJ_ADDR_SHIFT             (0U)
#define DDRC_ADDR_ERR_INJ_ADDR_WIDTH             (32U)
#define DDRC_ADDR_ERR_INJ_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_ADDR_ERR_INJ_ADDR_SHIFT)) & DDRC_ADDR_ERR_INJ_ADDR_MASK)
/*! @} */

/*! @name CAPTURE_EXT_DATA_HI - Memory Extended Data Path Read Capture High */
/*! @{ */

#define DDRC_CAPTURE_EXT_DATA_HI_ECEHD_MASK      (0xFFFFFFFFU)
#define DDRC_CAPTURE_EXT_DATA_HI_ECEHD_SHIFT     (0U)
#define DDRC_CAPTURE_EXT_DATA_HI_ECEHD_WIDTH     (32U)
#define DDRC_CAPTURE_EXT_DATA_HI_ECEHD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_EXT_DATA_HI_ECEHD_SHIFT)) & DDRC_CAPTURE_EXT_DATA_HI_ECEHD_MASK)
/*! @} */

/*! @name CAPTURE_EXT_DATA_LO - Memory Extended Data Path Read Capture Low */
/*! @{ */

#define DDRC_CAPTURE_EXT_DATA_LO_ECELD_MASK      (0xFFFFFFFFU)
#define DDRC_CAPTURE_EXT_DATA_LO_ECELD_SHIFT     (0U)
#define DDRC_CAPTURE_EXT_DATA_LO_ECELD_WIDTH     (32U)
#define DDRC_CAPTURE_EXT_DATA_LO_ECELD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_EXT_DATA_LO_ECELD_SHIFT)) & DDRC_CAPTURE_EXT_DATA_LO_ECELD_MASK)
/*! @} */

/*! @name CAPTURE_DATA_HI - Memory Data Path Read Capture High */
/*! @{ */

#define DDRC_CAPTURE_DATA_HI_ECHD_MASK           (0xFFFFFFFFU)
#define DDRC_CAPTURE_DATA_HI_ECHD_SHIFT          (0U)
#define DDRC_CAPTURE_DATA_HI_ECHD_WIDTH          (32U)
#define DDRC_CAPTURE_DATA_HI_ECHD(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_DATA_HI_ECHD_SHIFT)) & DDRC_CAPTURE_DATA_HI_ECHD_MASK)
/*! @} */

/*! @name CAPTURE_DATA_LO - Memory Data Path Read Capture Low */
/*! @{ */

#define DDRC_CAPTURE_DATA_LO_ECLD_MASK           (0xFFFFFFFFU)
#define DDRC_CAPTURE_DATA_LO_ECLD_SHIFT          (0U)
#define DDRC_CAPTURE_DATA_LO_ECLD_WIDTH          (32U)
#define DDRC_CAPTURE_DATA_LO_ECLD(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_DATA_LO_ECLD_SHIFT)) & DDRC_CAPTURE_DATA_LO_ECLD_MASK)
/*! @} */

/*! @name CAPTURE_ECC - Memory Data Path Read Capture ECC */
/*! @{ */

#define DDRC_CAPTURE_ECC_ECE_MASK                (0xFFFFFFFFU)
#define DDRC_CAPTURE_ECC_ECE_SHIFT               (0U)
#define DDRC_CAPTURE_ECC_ECE_WIDTH               (32U)
#define DDRC_CAPTURE_ECC_ECE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_ECC_ECE_SHIFT)) & DDRC_CAPTURE_ECC_ECE_MASK)
/*! @} */

/*! @name ERR_DETECT - Memory Error Detect */
/*! @{ */

#define DDRC_ERR_DETECT_MSE_MASK                 (0x1U)
#define DDRC_ERR_DETECT_MSE_SHIFT                (0U)
#define DDRC_ERR_DETECT_MSE_WIDTH                (1U)
#define DDRC_ERR_DETECT_MSE(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_MSE_SHIFT)) & DDRC_ERR_DETECT_MSE_MASK)

#define DDRC_ERR_DETECT_SBE_MASK                 (0x4U)
#define DDRC_ERR_DETECT_SBE_SHIFT                (2U)
#define DDRC_ERR_DETECT_SBE_WIDTH                (1U)
#define DDRC_ERR_DETECT_SBE(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_SBE_SHIFT)) & DDRC_ERR_DETECT_SBE_MASK)

#define DDRC_ERR_DETECT_MBE_MASK                 (0x8U)
#define DDRC_ERR_DETECT_MBE_SHIFT                (3U)
#define DDRC_ERR_DETECT_MBE_WIDTH                (1U)
#define DDRC_ERR_DETECT_MBE(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_MBE_SHIFT)) & DDRC_ERR_DETECT_MBE_MASK)

#define DDRC_ERR_DETECT_REFRATEE_MASK            (0x80U)
#define DDRC_ERR_DETECT_REFRATEE_SHIFT           (7U)
#define DDRC_ERR_DETECT_REFRATEE_WIDTH           (1U)
#define DDRC_ERR_DETECT_REFRATEE(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_REFRATEE_SHIFT)) & DDRC_ERR_DETECT_REFRATEE_MASK)

#define DDRC_ERR_DETECT_LKSTP2E_MASK             (0x100U)
#define DDRC_ERR_DETECT_LKSTP2E_SHIFT            (8U)
#define DDRC_ERR_DETECT_LKSTP2E_WIDTH            (1U)
#define DDRC_ERR_DETECT_LKSTP2E(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_LKSTP2E_SHIFT)) & DDRC_ERR_DETECT_LKSTP2E_MASK)

#define DDRC_ERR_DETECT_LKSTP1E_MASK             (0x200U)
#define DDRC_ERR_DETECT_LKSTP1E_SHIFT            (9U)
#define DDRC_ERR_DETECT_LKSTP1E_WIDTH            (1U)
#define DDRC_ERR_DETECT_LKSTP1E(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_LKSTP1E_SHIFT)) & DDRC_ERR_DETECT_LKSTP1E_MASK)

#define DDRC_ERR_DETECT_PHYE_MASK                (0x10000U)
#define DDRC_ERR_DETECT_PHYE_SHIFT               (16U)
#define DDRC_ERR_DETECT_PHYE_WIDTH               (1U)
#define DDRC_ERR_DETECT_PHYE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_PHYE_SHIFT)) & DDRC_ERR_DETECT_PHYE_MASK)

#define DDRC_ERR_DETECT_IPE_MASK                 (0x80000U)
#define DDRC_ERR_DETECT_IPE_SHIFT                (19U)
#define DDRC_ERR_DETECT_IPE_WIDTH                (1U)
#define DDRC_ERR_DETECT_IPE(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_IPE_SHIFT)) & DDRC_ERR_DETECT_IPE_MASK)

#define DDRC_ERR_DETECT_UPDTMTE_MASK             (0x100000U)
#define DDRC_ERR_DETECT_UPDTMTE_SHIFT            (20U)
#define DDRC_ERR_DETECT_UPDTMTE_WIDTH            (1U)
#define DDRC_ERR_DETECT_UPDTMTE(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_UPDTMTE_SHIFT)) & DDRC_ERR_DETECT_UPDTMTE_MASK)

#define DDRC_ERR_DETECT_CRCE_MASK                (0x200000U)
#define DDRC_ERR_DETECT_CRCE_SHIFT               (21U)
#define DDRC_ERR_DETECT_CRCE_WIDTH               (1U)
#define DDRC_ERR_DETECT_CRCE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_CRCE_SHIFT)) & DDRC_ERR_DETECT_CRCE_MASK)

#define DDRC_ERR_DETECT_SMBE2_MASK               (0x400000U)
#define DDRC_ERR_DETECT_SMBE2_SHIFT              (22U)
#define DDRC_ERR_DETECT_SMBE2_WIDTH              (1U)
#define DDRC_ERR_DETECT_SMBE2(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_SMBE2_SHIFT)) & DDRC_ERR_DETECT_SMBE2_MASK)

#define DDRC_ERR_DETECT_SMBE1_MASK               (0x800000U)
#define DDRC_ERR_DETECT_SMBE1_SHIFT              (23U)
#define DDRC_ERR_DETECT_SMBE1_WIDTH              (1U)
#define DDRC_ERR_DETECT_SMBE1(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_SMBE1_SHIFT)) & DDRC_ERR_DETECT_SMBE1_MASK)

#define DDRC_ERR_DETECT_SSBE2_MASK               (0x1000000U)
#define DDRC_ERR_DETECT_SSBE2_SHIFT              (24U)
#define DDRC_ERR_DETECT_SSBE2_WIDTH              (1U)
#define DDRC_ERR_DETECT_SSBE2(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_SSBE2_SHIFT)) & DDRC_ERR_DETECT_SSBE2_MASK)

#define DDRC_ERR_DETECT_SSBE1_MASK               (0x2000000U)
#define DDRC_ERR_DETECT_SSBE1_SHIFT              (25U)
#define DDRC_ERR_DETECT_SSBE1_WIDTH              (1U)
#define DDRC_ERR_DETECT_SSBE1(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_SSBE1_SHIFT)) & DDRC_ERR_DETECT_SSBE1_MASK)

#define DDRC_ERR_DETECT_WTAGE_MASK               (0x4000000U)
#define DDRC_ERR_DETECT_WTAGE_SHIFT              (26U)
#define DDRC_ERR_DETECT_WTAGE_WIDTH              (1U)
#define DDRC_ERR_DETECT_WTAGE(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_WTAGE_SHIFT)) & DDRC_ERR_DETECT_WTAGE_MASK)

#define DDRC_ERR_DETECT_RTAGE_MASK               (0x8000000U)
#define DDRC_ERR_DETECT_RTAGE_SHIFT              (27U)
#define DDRC_ERR_DETECT_RTAGE_WIDTH              (1U)
#define DDRC_ERR_DETECT_RTAGE(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_RTAGE_SHIFT)) & DDRC_ERR_DETECT_RTAGE_MASK)

#define DDRC_ERR_DETECT_WTTE_MASK                (0x10000000U)
#define DDRC_ERR_DETECT_WTTE_SHIFT               (28U)
#define DDRC_ERR_DETECT_WTTE_WIDTH               (1U)
#define DDRC_ERR_DETECT_WTTE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_WTTE_SHIFT)) & DDRC_ERR_DETECT_WTTE_MASK)

#define DDRC_ERR_DETECT_RTTE_MASK                (0x20000000U)
#define DDRC_ERR_DETECT_RTTE_SHIFT               (29U)
#define DDRC_ERR_DETECT_RTTE_WIDTH               (1U)
#define DDRC_ERR_DETECT_RTTE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_RTTE_SHIFT)) & DDRC_ERR_DETECT_RTTE_MASK)

#define DDRC_ERR_DETECT_RTMTE_MASK               (0x40000000U)
#define DDRC_ERR_DETECT_RTMTE_SHIFT              (30U)
#define DDRC_ERR_DETECT_RTMTE_WIDTH              (1U)
#define DDRC_ERR_DETECT_RTMTE(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_RTMTE_SHIFT)) & DDRC_ERR_DETECT_RTMTE_MASK)

#define DDRC_ERR_DETECT_MME_MASK                 (0x80000000U)
#define DDRC_ERR_DETECT_MME_SHIFT                (31U)
#define DDRC_ERR_DETECT_MME_WIDTH                (1U)
#define DDRC_ERR_DETECT_MME(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_MME_SHIFT)) & DDRC_ERR_DETECT_MME_MASK)
/*! @} */

/*! @name ERR_DISABLE - Memory Error Disable */
/*! @{ */

#define DDRC_ERR_DISABLE_MSED_MASK               (0x1U)
#define DDRC_ERR_DISABLE_MSED_SHIFT              (0U)
#define DDRC_ERR_DISABLE_MSED_WIDTH              (1U)
#define DDRC_ERR_DISABLE_MSED(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_MSED_SHIFT)) & DDRC_ERR_DISABLE_MSED_MASK)

#define DDRC_ERR_DISABLE_SBED_MASK               (0x4U)
#define DDRC_ERR_DISABLE_SBED_SHIFT              (2U)
#define DDRC_ERR_DISABLE_SBED_WIDTH              (1U)
#define DDRC_ERR_DISABLE_SBED(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_SBED_SHIFT)) & DDRC_ERR_DISABLE_SBED_MASK)

#define DDRC_ERR_DISABLE_MBED_MASK               (0x8U)
#define DDRC_ERR_DISABLE_MBED_SHIFT              (3U)
#define DDRC_ERR_DISABLE_MBED_WIDTH              (1U)
#define DDRC_ERR_DISABLE_MBED(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_MBED_SHIFT)) & DDRC_ERR_DISABLE_MBED_MASK)

#define DDRC_ERR_DISABLE_REFRATEED_MASK          (0x80U)
#define DDRC_ERR_DISABLE_REFRATEED_SHIFT         (7U)
#define DDRC_ERR_DISABLE_REFRATEED_WIDTH         (1U)
#define DDRC_ERR_DISABLE_REFRATEED(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_REFRATEED_SHIFT)) & DDRC_ERR_DISABLE_REFRATEED_MASK)

#define DDRC_ERR_DISABLE_PHYED_MASK              (0x10000U)
#define DDRC_ERR_DISABLE_PHYED_SHIFT             (16U)
#define DDRC_ERR_DISABLE_PHYED_WIDTH             (1U)
#define DDRC_ERR_DISABLE_PHYED(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_PHYED_SHIFT)) & DDRC_ERR_DISABLE_PHYED_MASK)

#define DDRC_ERR_DISABLE_UPDTMTED_MASK           (0x100000U)
#define DDRC_ERR_DISABLE_UPDTMTED_SHIFT          (20U)
#define DDRC_ERR_DISABLE_UPDTMTED_WIDTH          (1U)
#define DDRC_ERR_DISABLE_UPDTMTED(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_UPDTMTED_SHIFT)) & DDRC_ERR_DISABLE_UPDTMTED_MASK)
/*! @} */

/*! @name ERR_INT_EN - Memory Error Interrupt Enable */
/*! @{ */

#define DDRC_ERR_INT_EN_MSEE_MASK                (0x1U)
#define DDRC_ERR_INT_EN_MSEE_SHIFT               (0U)
#define DDRC_ERR_INT_EN_MSEE_WIDTH               (1U)
#define DDRC_ERR_INT_EN_MSEE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_MSEE_SHIFT)) & DDRC_ERR_INT_EN_MSEE_MASK)

#define DDRC_ERR_INT_EN_SBEE_MASK                (0x4U)
#define DDRC_ERR_INT_EN_SBEE_SHIFT               (2U)
#define DDRC_ERR_INT_EN_SBEE_WIDTH               (1U)
#define DDRC_ERR_INT_EN_SBEE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_SBEE_SHIFT)) & DDRC_ERR_INT_EN_SBEE_MASK)

#define DDRC_ERR_INT_EN_MBEE_MASK                (0x8U)
#define DDRC_ERR_INT_EN_MBEE_SHIFT               (3U)
#define DDRC_ERR_INT_EN_MBEE_WIDTH               (1U)
#define DDRC_ERR_INT_EN_MBEE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_MBEE_SHIFT)) & DDRC_ERR_INT_EN_MBEE_MASK)

#define DDRC_ERR_INT_EN_SSBE12E_MASK             (0x10U)
#define DDRC_ERR_INT_EN_SSBE12E_SHIFT            (4U)
#define DDRC_ERR_INT_EN_SSBE12E_WIDTH            (1U)
#define DDRC_ERR_INT_EN_SSBE12E(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_SSBE12E_SHIFT)) & DDRC_ERR_INT_EN_SSBE12E_MASK)

#define DDRC_ERR_INT_EN_REFRATEEE_MASK           (0x80U)
#define DDRC_ERR_INT_EN_REFRATEEE_SHIFT          (7U)
#define DDRC_ERR_INT_EN_REFRATEEE_WIDTH          (1U)
#define DDRC_ERR_INT_EN_REFRATEEE(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_REFRATEEE_SHIFT)) & DDRC_ERR_INT_EN_REFRATEEE_MASK)

#define DDRC_ERR_INT_EN_PHYEE_MASK               (0x10000U)
#define DDRC_ERR_INT_EN_PHYEE_SHIFT              (16U)
#define DDRC_ERR_INT_EN_PHYEE_WIDTH              (1U)
#define DDRC_ERR_INT_EN_PHYEE(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_PHYEE_SHIFT)) & DDRC_ERR_INT_EN_PHYEE_MASK)

#define DDRC_ERR_INT_EN_UPDTMTEE_MASK            (0x100000U)
#define DDRC_ERR_INT_EN_UPDTMTEE_SHIFT           (20U)
#define DDRC_ERR_INT_EN_UPDTMTEE_WIDTH           (1U)
#define DDRC_ERR_INT_EN_UPDTMTEE(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_UPDTMTEE_SHIFT)) & DDRC_ERR_INT_EN_UPDTMTEE_MASK)
/*! @} */

/*! @name CAPTURE_ATTRIBUTES - Memory Error Attributes Capture */
/*! @{ */

#define DDRC_CAPTURE_ATTRIBUTES_VLD_MASK         (0x1U)
#define DDRC_CAPTURE_ATTRIBUTES_VLD_SHIFT        (0U)
#define DDRC_CAPTURE_ATTRIBUTES_VLD_WIDTH        (1U)
#define DDRC_CAPTURE_ATTRIBUTES_VLD(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_ATTRIBUTES_VLD_SHIFT)) & DDRC_CAPTURE_ATTRIBUTES_VLD_MASK)

#define DDRC_CAPTURE_ATTRIBUTES_TTYP_MASK        (0x3000U)
#define DDRC_CAPTURE_ATTRIBUTES_TTYP_SHIFT       (12U)
#define DDRC_CAPTURE_ATTRIBUTES_TTYP_WIDTH       (2U)
#define DDRC_CAPTURE_ATTRIBUTES_TTYP(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_ATTRIBUTES_TTYP_SHIFT)) & DDRC_CAPTURE_ATTRIBUTES_TTYP_MASK)

#define DDRC_CAPTURE_ATTRIBUTES_BNUM_MASK        (0x70000000U)
#define DDRC_CAPTURE_ATTRIBUTES_BNUM_SHIFT       (28U)
#define DDRC_CAPTURE_ATTRIBUTES_BNUM_WIDTH       (3U)
#define DDRC_CAPTURE_ATTRIBUTES_BNUM(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_ATTRIBUTES_BNUM_SHIFT)) & DDRC_CAPTURE_ATTRIBUTES_BNUM_MASK)
/*! @} */

/*! @name CAPTURE_ADDRESS - Memory Error Address Capture */
/*! @{ */

#define DDRC_CAPTURE_ADDRESS_CADDR_MASK          (0xFFFFFFFFU)
#define DDRC_CAPTURE_ADDRESS_CADDR_SHIFT         (0U)
#define DDRC_CAPTURE_ADDRESS_CADDR_WIDTH         (32U)
#define DDRC_CAPTURE_ADDRESS_CADDR(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_ADDRESS_CADDR_SHIFT)) & DDRC_CAPTURE_ADDRESS_CADDR_MASK)
/*! @} */

/*! @name CAPTURE_EXT_ADDRESS - Memory Error Extended Address Capture */
/*! @{ */

#define DDRC_CAPTURE_EXT_ADDRESS_CEADDR_MASK     (0xFFU)
#define DDRC_CAPTURE_EXT_ADDRESS_CEADDR_SHIFT    (0U)
#define DDRC_CAPTURE_EXT_ADDRESS_CEADDR_WIDTH    (8U)
#define DDRC_CAPTURE_EXT_ADDRESS_CEADDR(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_EXT_ADDRESS_CEADDR_SHIFT)) & DDRC_CAPTURE_EXT_ADDRESS_CEADDR_MASK)
/*! @} */

/*! @name ERR_SBE - Single-Bit ECC Memory Error Management */
/*! @{ */

#define DDRC_ERR_SBE_SBEC_MASK                   (0xFFU)
#define DDRC_ERR_SBE_SBEC_SHIFT                  (0U)
#define DDRC_ERR_SBE_SBEC_WIDTH                  (8U)
#define DDRC_ERR_SBE_SBEC(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_SBE_SBEC_SHIFT)) & DDRC_ERR_SBE_SBEC_MASK)

#define DDRC_ERR_SBE_SBET_MASK                   (0xFF0000U)
#define DDRC_ERR_SBE_SBET_SHIFT                  (16U)
#define DDRC_ERR_SBE_SBET_WIDTH                  (8U)
#define DDRC_ERR_SBE_SBET(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_SBE_SBET_SHIFT)) & DDRC_ERR_SBE_SBET_MASK)
/*! @} */

/*! @name REG_LKSTP_CNTL - Lockstep Register Control */
/*! @{ */

#define DDRC_REG_LKSTP_CNTL_CLR_LKSTP2_MASK      (0x1U)
#define DDRC_REG_LKSTP_CNTL_CLR_LKSTP2_SHIFT     (0U)
#define DDRC_REG_LKSTP_CNTL_CLR_LKSTP2_WIDTH     (1U)
#define DDRC_REG_LKSTP_CNTL_CLR_LKSTP2(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_REG_LKSTP_CNTL_CLR_LKSTP2_SHIFT)) & DDRC_REG_LKSTP_CNTL_CLR_LKSTP2_MASK)

#define DDRC_REG_LKSTP_CNTL_CLR_LKSTP1_MASK      (0x2U)
#define DDRC_REG_LKSTP_CNTL_CLR_LKSTP1_SHIFT     (1U)
#define DDRC_REG_LKSTP_CNTL_CLR_LKSTP1_WIDTH     (1U)
#define DDRC_REG_LKSTP_CNTL_CLR_LKSTP1(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_REG_LKSTP_CNTL_CLR_LKSTP1_SHIFT)) & DDRC_REG_LKSTP_CNTL_CLR_LKSTP1_MASK)
/*! @} */

/*! @name REG_CRC_GRP_1 - Register CRC Code For Group 1 */
/*! @{ */

#define DDRC_REG_CRC_GRP_1_CRC_1_MASK            (0xFFFFFFFFU)
#define DDRC_REG_CRC_GRP_1_CRC_1_SHIFT           (0U)
#define DDRC_REG_CRC_GRP_1_CRC_1_WIDTH           (32U)
#define DDRC_REG_CRC_GRP_1_CRC_1(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_REG_CRC_GRP_1_CRC_1_SHIFT)) & DDRC_REG_CRC_GRP_1_CRC_1_MASK)
/*! @} */

/*! @name REG_CRC_GRP_2 - Register CRC Code For Group 2 */
/*! @{ */

#define DDRC_REG_CRC_GRP_2_CRC_2_MASK            (0xFFFFFFFFU)
#define DDRC_REG_CRC_GRP_2_CRC_2_SHIFT           (0U)
#define DDRC_REG_CRC_GRP_2_CRC_2_WIDTH           (32U)
#define DDRC_REG_CRC_GRP_2_CRC_2(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_REG_CRC_GRP_2_CRC_2_SHIFT)) & DDRC_REG_CRC_GRP_2_CRC_2_MASK)
/*! @} */

/*! @name ECC_REG_0 - ECC Region 0 Configuration */
/*! @{ */

#define DDRC_ECC_REG_0_REG_0_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_0_REG_0_EA_SHIFT            (0U)
#define DDRC_ECC_REG_0_REG_0_EA_WIDTH            (12U)
#define DDRC_ECC_REG_0_REG_0_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_0_REG_0_EA_SHIFT)) & DDRC_ECC_REG_0_REG_0_EA_MASK)

#define DDRC_ECC_REG_0_REG_0_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_0_REG_0_SA_SHIFT            (16U)
#define DDRC_ECC_REG_0_REG_0_SA_WIDTH            (12U)
#define DDRC_ECC_REG_0_REG_0_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_0_REG_0_SA_SHIFT)) & DDRC_ECC_REG_0_REG_0_SA_MASK)

#define DDRC_ECC_REG_0_REG_0_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_0_REG_0_EN_SHIFT            (31U)
#define DDRC_ECC_REG_0_REG_0_EN_WIDTH            (1U)
#define DDRC_ECC_REG_0_REG_0_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_0_REG_0_EN_SHIFT)) & DDRC_ECC_REG_0_REG_0_EN_MASK)
/*! @} */

/*! @name ECC_REG_1 - ECC Region 1 Configuration */
/*! @{ */

#define DDRC_ECC_REG_1_REG_1_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_1_REG_1_EA_SHIFT            (0U)
#define DDRC_ECC_REG_1_REG_1_EA_WIDTH            (12U)
#define DDRC_ECC_REG_1_REG_1_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_1_REG_1_EA_SHIFT)) & DDRC_ECC_REG_1_REG_1_EA_MASK)

#define DDRC_ECC_REG_1_REG_1_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_1_REG_1_SA_SHIFT            (16U)
#define DDRC_ECC_REG_1_REG_1_SA_WIDTH            (12U)
#define DDRC_ECC_REG_1_REG_1_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_1_REG_1_SA_SHIFT)) & DDRC_ECC_REG_1_REG_1_SA_MASK)

#define DDRC_ECC_REG_1_REG_1_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_1_REG_1_EN_SHIFT            (31U)
#define DDRC_ECC_REG_1_REG_1_EN_WIDTH            (1U)
#define DDRC_ECC_REG_1_REG_1_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_1_REG_1_EN_SHIFT)) & DDRC_ECC_REG_1_REG_1_EN_MASK)
/*! @} */

/*! @name ECC_REG_2 - ECC Region 2 Configuration */
/*! @{ */

#define DDRC_ECC_REG_2_REG_2_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_2_REG_2_EA_SHIFT            (0U)
#define DDRC_ECC_REG_2_REG_2_EA_WIDTH            (12U)
#define DDRC_ECC_REG_2_REG_2_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_2_REG_2_EA_SHIFT)) & DDRC_ECC_REG_2_REG_2_EA_MASK)

#define DDRC_ECC_REG_2_REG_2_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_2_REG_2_SA_SHIFT            (16U)
#define DDRC_ECC_REG_2_REG_2_SA_WIDTH            (12U)
#define DDRC_ECC_REG_2_REG_2_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_2_REG_2_SA_SHIFT)) & DDRC_ECC_REG_2_REG_2_SA_MASK)

#define DDRC_ECC_REG_2_REG_2_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_2_REG_2_EN_SHIFT            (31U)
#define DDRC_ECC_REG_2_REG_2_EN_WIDTH            (1U)
#define DDRC_ECC_REG_2_REG_2_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_2_REG_2_EN_SHIFT)) & DDRC_ECC_REG_2_REG_2_EN_MASK)
/*! @} */

/*! @name ECC_REG_3 - ECC Region 3 Configuration */
/*! @{ */

#define DDRC_ECC_REG_3_REG_3_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_3_REG_3_EA_SHIFT            (0U)
#define DDRC_ECC_REG_3_REG_3_EA_WIDTH            (12U)
#define DDRC_ECC_REG_3_REG_3_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_3_REG_3_EA_SHIFT)) & DDRC_ECC_REG_3_REG_3_EA_MASK)

#define DDRC_ECC_REG_3_REG_3_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_3_REG_3_SA_SHIFT            (16U)
#define DDRC_ECC_REG_3_REG_3_SA_WIDTH            (12U)
#define DDRC_ECC_REG_3_REG_3_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_3_REG_3_SA_SHIFT)) & DDRC_ECC_REG_3_REG_3_SA_MASK)

#define DDRC_ECC_REG_3_REG_3_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_3_REG_3_EN_SHIFT            (31U)
#define DDRC_ECC_REG_3_REG_3_EN_WIDTH            (1U)
#define DDRC_ECC_REG_3_REG_3_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_3_REG_3_EN_SHIFT)) & DDRC_ECC_REG_3_REG_3_EN_MASK)
/*! @} */

/*! @name ECC_REG_4 - ECC Region 4 Configuration */
/*! @{ */

#define DDRC_ECC_REG_4_REG_4_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_4_REG_4_EA_SHIFT            (0U)
#define DDRC_ECC_REG_4_REG_4_EA_WIDTH            (12U)
#define DDRC_ECC_REG_4_REG_4_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_4_REG_4_EA_SHIFT)) & DDRC_ECC_REG_4_REG_4_EA_MASK)

#define DDRC_ECC_REG_4_REG_4_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_4_REG_4_SA_SHIFT            (16U)
#define DDRC_ECC_REG_4_REG_4_SA_WIDTH            (12U)
#define DDRC_ECC_REG_4_REG_4_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_4_REG_4_SA_SHIFT)) & DDRC_ECC_REG_4_REG_4_SA_MASK)

#define DDRC_ECC_REG_4_REG_4_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_4_REG_4_EN_SHIFT            (31U)
#define DDRC_ECC_REG_4_REG_4_EN_WIDTH            (1U)
#define DDRC_ECC_REG_4_REG_4_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_4_REG_4_EN_SHIFT)) & DDRC_ECC_REG_4_REG_4_EN_MASK)
/*! @} */

/*! @name ECC_REG_5 - ECC Region 5 Configuration */
/*! @{ */

#define DDRC_ECC_REG_5_REG_5_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_5_REG_5_EA_SHIFT            (0U)
#define DDRC_ECC_REG_5_REG_5_EA_WIDTH            (12U)
#define DDRC_ECC_REG_5_REG_5_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_5_REG_5_EA_SHIFT)) & DDRC_ECC_REG_5_REG_5_EA_MASK)

#define DDRC_ECC_REG_5_REG_5_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_5_REG_5_SA_SHIFT            (16U)
#define DDRC_ECC_REG_5_REG_5_SA_WIDTH            (12U)
#define DDRC_ECC_REG_5_REG_5_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_5_REG_5_SA_SHIFT)) & DDRC_ECC_REG_5_REG_5_SA_MASK)

#define DDRC_ECC_REG_5_REG_5_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_5_REG_5_EN_SHIFT            (31U)
#define DDRC_ECC_REG_5_REG_5_EN_WIDTH            (1U)
#define DDRC_ECC_REG_5_REG_5_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_5_REG_5_EN_SHIFT)) & DDRC_ECC_REG_5_REG_5_EN_MASK)
/*! @} */

/*! @name ECC_REG_6 - ECC Region 6 Configuration */
/*! @{ */

#define DDRC_ECC_REG_6_REG_6_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_6_REG_6_EA_SHIFT            (0U)
#define DDRC_ECC_REG_6_REG_6_EA_WIDTH            (12U)
#define DDRC_ECC_REG_6_REG_6_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_6_REG_6_EA_SHIFT)) & DDRC_ECC_REG_6_REG_6_EA_MASK)

#define DDRC_ECC_REG_6_REG_6_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_6_REG_6_SA_SHIFT            (16U)
#define DDRC_ECC_REG_6_REG_6_SA_WIDTH            (12U)
#define DDRC_ECC_REG_6_REG_6_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_6_REG_6_SA_SHIFT)) & DDRC_ECC_REG_6_REG_6_SA_MASK)

#define DDRC_ECC_REG_6_REG_6_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_6_REG_6_EN_SHIFT            (31U)
#define DDRC_ECC_REG_6_REG_6_EN_WIDTH            (1U)
#define DDRC_ECC_REG_6_REG_6_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_6_REG_6_EN_SHIFT)) & DDRC_ECC_REG_6_REG_6_EN_MASK)
/*! @} */

/*! @name ECC_REG_7 - ECC Region 7 Configuration */
/*! @{ */

#define DDRC_ECC_REG_7_REG_7_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_7_REG_7_EA_SHIFT            (0U)
#define DDRC_ECC_REG_7_REG_7_EA_WIDTH            (12U)
#define DDRC_ECC_REG_7_REG_7_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_7_REG_7_EA_SHIFT)) & DDRC_ECC_REG_7_REG_7_EA_MASK)

#define DDRC_ECC_REG_7_REG_7_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_7_REG_7_SA_SHIFT            (16U)
#define DDRC_ECC_REG_7_REG_7_SA_WIDTH            (12U)
#define DDRC_ECC_REG_7_REG_7_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_7_REG_7_SA_SHIFT)) & DDRC_ECC_REG_7_REG_7_SA_MASK)

#define DDRC_ECC_REG_7_REG_7_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_7_REG_7_EN_SHIFT            (31U)
#define DDRC_ECC_REG_7_REG_7_EN_WIDTH            (1U)
#define DDRC_ECC_REG_7_REG_7_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_7_REG_7_EN_SHIFT)) & DDRC_ECC_REG_7_REG_7_EN_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DDRC_Register_Masks */

/*!
 * @}
 */ /* end of group DDRC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_DDRC_H_) */
