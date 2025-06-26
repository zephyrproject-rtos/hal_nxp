/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_RTU_PMC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_RTU_PMC
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
#if !defined(S32Z2_RTU_PMC_H_)  /* Check if memory map has not been already included */
#define S32Z2_RTU_PMC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- RTU_PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTU_PMC_Peripheral_Access_Layer RTU_PMC Peripheral Access Layer
 * @{
 */

/** RTU_PMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Main Control Register, offset: 0x0 */
  __IO uint32_t MCR;                               /**< Memory Control Register, offset: 0x4 */
  __IO uint32_t BER;                               /**< Byte Enable Register, offset: 0x8 */
  __IO uint32_t PCR;                               /**< Program Control Register, offset: 0xC */
  __I  uint32_t RPR;                               /**< Read Pipeline Register, offset: 0x10 */
  __IO uint32_t STOPADDR;                          /**< Stop Address Register, offset: 0x14 */
  __IO uint32_t CADDR;                             /**< Column Address Register, offset: 0x18 */
  __IO uint32_t RADDR;                             /**< Row Address Register, offset: 0x1C */
  __IO uint32_t X0;                                /**< X Data Register 0, offset: 0x20 */
  __IO uint32_t X1;                                /**< X Data Register 1, offset: 0x24 */
  __IO uint32_t X2;                                /**< X Data Register 2, offset: 0x28 */
  __IO uint32_t X3;                                /**< X Data Register 3, offset: 0x2C */
  __IO uint32_t X4;                                /**< X Data Register 4, offset: 0x30 */
  __IO uint32_t X5;                                /**< X Data Register 5, offset: 0x34 */
  __IO uint32_t X6;                                /**< X Data Register 6, offset: 0x38 */
  __IO uint32_t X7;                                /**< X Data Register 7, offset: 0x3C */
  __IO uint32_t Y0;                                /**< Y Data Register 0, offset: 0x40 */
  __IO uint32_t Y1;                                /**< Y Data Register 1, offset: 0x44 */
  __IO uint32_t Y2;                                /**< Y Data Register 2, offset: 0x48 */
  __IO uint32_t Y3;                                /**< Y Data Register 3, offset: 0x4C */
  __IO uint32_t Y4;                                /**< Y Data Register 4, offset: 0x50 */
  __IO uint32_t Y5;                                /**< Y Data Register 5, offset: 0x54 */
  __IO uint32_t Y6;                                /**< Y Data Register 6, offset: 0x58 */
  __IO uint32_t Y7;                                /**< Y Data Register 7, offset: 0x5C */
  __IO uint32_t AIR;                               /**< Auxiliary Input Register, offset: 0x60 */
  __IO uint32_t AOR;                               /**< Auxiliary Output Register, offset: 0x64 */
  uint8_t RESERVED_0[24];
  __IO uint32_t DM0;                               /**< Data Mask Register 0, offset: 0x80 */
  __IO uint32_t DM1;                               /**< Data Mask Register 1, offset: 0x84 */
  __IO uint32_t DM2;                               /**< Data Mask Register 2, offset: 0x88 */
  __IO uint32_t DM3;                               /**< Data Mask Register 3, offset: 0x8C */
  __IO uint32_t DM4;                               /**< Data Mask Register 4, offset: 0x90 */
  __IO uint32_t DM5;                               /**< Data Mask Register 5, offset: 0x94 */
  __IO uint32_t DM6;                               /**< Data Mask Register 6, offset: 0x98 */
  __IO uint32_t DM7;                               /**< Data Mask Register 7, offset: 0x9C */
  uint8_t RESERVED_1[96];
  __IO uint32_t P0;                                /**< Program Register 0, offset: 0x100 */
  __IO uint32_t P1;                                /**< Program Register 1, offset: 0x104 */
  __IO uint32_t P2;                                /**< Program Register 2, offset: 0x108 */
  __IO uint32_t P3;                                /**< Program Register 3, offset: 0x10C */
  __IO uint32_t P4;                                /**< Program Register 4, offset: 0x110 */
  __IO uint32_t P5;                                /**< Program Register 5, offset: 0x114 */
  __IO uint32_t P6;                                /**< Program Register 6, offset: 0x118 */
  __IO uint32_t P7;                                /**< Program Register 7, offset: 0x11C */
  __IO uint32_t P8;                                /**< Program Register 8, offset: 0x120 */
  __IO uint32_t P9;                                /**< Program Register 9, offset: 0x124 */
  __IO uint32_t P10;                               /**< Program Register 10, offset: 0x128 */
  __IO uint32_t P11;                               /**< Program Register 11, offset: 0x12C */
  __IO uint32_t P12;                               /**< Program Register 12, offset: 0x130 */
  __IO uint32_t P13;                               /**< Program Register 13, offset: 0x134 */
  __IO uint32_t P14;                               /**< Program Register 14, offset: 0x138 */
  __IO uint32_t P15;                               /**< Program Register 15, offset: 0x13C */
  __IO uint32_t P16;                               /**< Program Register 16, offset: 0x140 */
  __IO uint32_t P17;                               /**< Program Register 17, offset: 0x144 */
  __IO uint32_t P18;                               /**< Program Register 18, offset: 0x148 */
  __IO uint32_t P19;                               /**< Program Register 19, offset: 0x14C */
  __IO uint32_t P20;                               /**< Program Register 20, offset: 0x150 */
  __IO uint32_t P21;                               /**< Program Register 21, offset: 0x154 */
  __IO uint32_t P22;                               /**< Program Register 22, offset: 0x158 */
  __IO uint32_t P23;                               /**< Program Register 23, offset: 0x15C */
  __IO uint32_t P24;                               /**< Program Register 24, offset: 0x160 */
  __IO uint32_t P25;                               /**< Program Register 25, offset: 0x164 */
  __IO uint32_t P26;                               /**< Program Register 26, offset: 0x168 */
  __IO uint32_t P27;                               /**< Program Register 27, offset: 0x16C */
  __IO uint32_t P28;                               /**< Program Register 28, offset: 0x170 */
  __IO uint32_t P29;                               /**< Program Register 29, offset: 0x174 */
  __IO uint32_t P30;                               /**< Program Register 30, offset: 0x178 */
  __IO uint32_t P31;                               /**< Program Register 31, offset: 0x17C */
  uint8_t RESERVED_2[3456];
  __I  uint32_t ITCTRL;                            /**< Integration Mode Control Register, offset: 0xF00 */
  uint8_t RESERVED_3[156];
  __IO uint32_t CLAIMSET;                          /**< Claim Tag Set Register, offset: 0xFA0 */
  __IO uint32_t CLAIMCLR;                          /**< Claim Tag Clear Register, offset: 0xFA4 */
  __I  uint32_t DEVAFF0;                           /**< Device Affinity 0 Register, offset: 0xFA8 */
  __I  uint32_t DEVAFF1;                           /**< Device Affinity 1 Register, offset: 0xFAC */
       uint32_t LAR;                               /**< Lock Access Register, offset: 0xFB0 */
       uint32_t LSR;                               /**< Lock Status Register, offset: 0xFB4 */
       uint32_t AUTHSTATUS;                        /**< Authentication Status Register, offset: 0xFB8 */
  __I  uint32_t DEVARCH;                           /**< Device Architecture Register, offset: 0xFBC */
       uint32_t DEVID2;                            /**< Device ID Register 2, offset: 0xFC0 */
       uint32_t DEVID1;                            /**< Device ID Register 1, offset: 0xFC4 */
       uint32_t DEVID;                             /**< Device ID Register, offset: 0xFC8 */
  __I  uint32_t DEVTYPE;                           /**< Device Type Identifier Register, offset: 0xFCC */
  __I  uint32_t PIDR4;                             /**< Peripheral Identification Register 4, offset: 0xFD0 */
       uint32_t PIDR5;                             /**< Peripheral Identification Register 5, offset: 0xFD4 */
       uint32_t PIDR6;                             /**< Peripheral Identification Register 6, offset: 0xFD8 */
       uint32_t PIDR7;                             /**< Peripheral Identification Register 7, offset: 0xFDC */
  __I  uint32_t PIDR0;                             /**< Peripheral Identification Register 0, offset: 0xFE0 */
  __I  uint32_t PIDR1;                             /**< Peripheral Identification Register 1, offset: 0xFE4 */
  __I  uint32_t PIDR2;                             /**< Peripheral Identification Register 2, offset: 0xFE8 */
  __I  uint32_t PIDR3;                             /**< Peripheral Identification Register 3, offset: 0xFEC */
  __I  uint32_t CIDR0;                             /**< Component Identification Register 0, offset: 0xFF0 */
  __I  uint32_t CIDR1;                             /**< Component Identification Register 1, offset: 0xFF4 */
  __I  uint32_t CIDR2;                             /**< Component Identification Register 2, offset: 0xFF8 */
  __I  uint32_t CIDR3;                             /**< Component Identification Register 3, offset: 0xFFC */
} RTU_PMC_Type, *RTU_PMC_MemMapPtr;

/** Number of instances of the RTU_PMC module. */
#define RTU_PMC_INSTANCE_COUNT                   (2u)

/* RTU_PMC - Peripheral instance base addresses */
/** Peripheral RTU0__PMC base address */
#define IP_RTU0__PMC_BASE                        (0x761B0000u)
/** Peripheral RTU0__PMC base pointer */
#define IP_RTU0__PMC                             ((RTU_PMC_Type *)IP_RTU0__PMC_BASE)
/** Peripheral RTU1__PMC base address */
#define IP_RTU1__PMC_BASE                        (0x769B0000u)
/** Peripheral RTU1__PMC base pointer */
#define IP_RTU1__PMC                             ((RTU_PMC_Type *)IP_RTU1__PMC_BASE)
/** Array initializer of RTU_PMC peripheral base addresses */
#define IP_RTU_PMC_BASE_ADDRS                    { IP_RTU0__PMC_BASE, IP_RTU1__PMC_BASE }
/** Array initializer of RTU_PMC peripheral base pointers */
#define IP_RTU_PMC_BASE_PTRS                     { IP_RTU0__PMC, IP_RTU1__PMC }

/* ----------------------------------------------------------------------------
   -- RTU_PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTU_PMC_Register_Masks RTU_PMC Register Masks
 * @{
 */

/*! @name CTRL - Main Control Register */
/*! @{ */

#define RTU_PMC_CTRL_PEEN_MASK                   (0x1U)
#define RTU_PMC_CTRL_PEEN_SHIFT                  (0U)
#define RTU_PMC_CTRL_PEEN_WIDTH                  (1U)
#define RTU_PMC_CTRL_PEEN(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_PEEN_SHIFT)) & RTU_PMC_CTRL_PEEN_MASK)

#define RTU_PMC_CTRL_PES_MASK                    (0x2U)
#define RTU_PMC_CTRL_PES_SHIFT                   (1U)
#define RTU_PMC_CTRL_PES_WIDTH                   (1U)
#define RTU_PMC_CTRL_PES(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_PES_SHIFT)) & RTU_PMC_CTRL_PES_MASK)

#define RTU_PMC_CTRL_TCSEN_MASK                  (0x4U)
#define RTU_PMC_CTRL_TCSEN_SHIFT                 (2U)
#define RTU_PMC_CTRL_TCSEN_WIDTH                 (1U)
#define RTU_PMC_CTRL_TCSEN(x)                    (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_TCSEN_SHIFT)) & RTU_PMC_CTRL_TCSEN_MASK)

#define RTU_PMC_CTRL_EXECO_MASK                  (0x8U)
#define RTU_PMC_CTRL_EXECO_SHIFT                 (3U)
#define RTU_PMC_CTRL_EXECO_WIDTH                 (1U)
#define RTU_PMC_CTRL_EXECO(x)                    (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_EXECO_SHIFT)) & RTU_PMC_CTRL_EXECO_MASK)

#define RTU_PMC_CTRL_STOPF_MASK                  (0x10U)
#define RTU_PMC_CTRL_STOPF_SHIFT                 (4U)
#define RTU_PMC_CTRL_STOPF_WIDTH                 (1U)
#define RTU_PMC_CTRL_STOPF(x)                    (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_STOPF_SHIFT)) & RTU_PMC_CTRL_STOPF_MASK)

#define RTU_PMC_CTRL_TE_MASK                     (0x20U)
#define RTU_PMC_CTRL_TE_SHIFT                    (5U)
#define RTU_PMC_CTRL_TE_WIDTH                    (1U)
#define RTU_PMC_CTRL_TE(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_TE_SHIFT)) & RTU_PMC_CTRL_TE_MASK)

#define RTU_PMC_CTRL_TESEN_MASK                  (0x40U)
#define RTU_PMC_CTRL_TESEN_SHIFT                 (6U)
#define RTU_PMC_CTRL_TESEN_WIDTH                 (1U)
#define RTU_PMC_CTRL_TESEN(x)                    (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_TESEN_SHIFT)) & RTU_PMC_CTRL_TESEN_MASK)

#define RTU_PMC_CTRL_TF_MASK                     (0x80U)
#define RTU_PMC_CTRL_TF_SHIFT                    (7U)
#define RTU_PMC_CTRL_TF_WIDTH                    (1U)
#define RTU_PMC_CTRL_TF(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_TF_SHIFT)) & RTU_PMC_CTRL_TF_MASK)

#define RTU_PMC_CTRL_TFSEN_MASK                  (0x100U)
#define RTU_PMC_CTRL_TFSEN_SHIFT                 (8U)
#define RTU_PMC_CTRL_TFSEN_WIDTH                 (1U)
#define RTU_PMC_CTRL_TFSEN(x)                    (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_TFSEN_SHIFT)) & RTU_PMC_CTRL_TFSEN_MASK)

#define RTU_PMC_CTRL_ADDRCD_MASK                 (0x200U)
#define RTU_PMC_CTRL_ADDRCD_SHIFT                (9U)
#define RTU_PMC_CTRL_ADDRCD_WIDTH                (1U)
#define RTU_PMC_CTRL_ADDRCD(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_ADDRCD_SHIFT)) & RTU_PMC_CTRL_ADDRCD_MASK)

#define RTU_PMC_CTRL_ADDRID_MASK                 (0x400U)
#define RTU_PMC_CTRL_ADDRID_SHIFT                (10U)
#define RTU_PMC_CTRL_ADDRID_WIDTH                (1U)
#define RTU_PMC_CTRL_ADDRID(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_ADDRID_SHIFT)) & RTU_PMC_CTRL_ADDRID_MASK)

#define RTU_PMC_CTRL_TEN_MASK                    (0x800U)
#define RTU_PMC_CTRL_TEN_SHIFT                   (11U)
#define RTU_PMC_CTRL_TEN_WIDTH                   (1U)
#define RTU_PMC_CTRL_TEN(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_TEN_SHIFT)) & RTU_PMC_CTRL_TEN_MASK)

#define RTU_PMC_CTRL_STATE_MASK                  (0x3000U)
#define RTU_PMC_CTRL_STATE_SHIFT                 (12U)
#define RTU_PMC_CTRL_STATE_WIDTH                 (2U)
#define RTU_PMC_CTRL_STATE(x)                    (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_STATE_SHIFT)) & RTU_PMC_CTRL_STATE_MASK)

#define RTU_PMC_CTRL_MBISTACK_MASK               (0x4000U)
#define RTU_PMC_CTRL_MBISTACK_SHIFT              (14U)
#define RTU_PMC_CTRL_MBISTACK_WIDTH              (1U)
#define RTU_PMC_CTRL_MBISTACK(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_MBISTACK_SHIFT)) & RTU_PMC_CTRL_MBISTACK_MASK)

#define RTU_PMC_CTRL_MBISTCFG_MASK               (0xFFFF0000U)
#define RTU_PMC_CTRL_MBISTCFG_SHIFT              (16U)
#define RTU_PMC_CTRL_MBISTCFG_WIDTH              (16U)
#define RTU_PMC_CTRL_MBISTCFG(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CTRL_MBISTCFG_SHIFT)) & RTU_PMC_CTRL_MBISTCFG_MASK)
/*! @} */

/*! @name MCR - Memory Control Register */
/*! @{ */

#define RTU_PMC_MCR_ARRAY_MASK                   (0xFFU)
#define RTU_PMC_MCR_ARRAY_SHIFT                  (0U)
#define RTU_PMC_MCR_ARRAY_WIDTH                  (8U)
#define RTU_PMC_MCR_ARRAY(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_MCR_ARRAY_SHIFT)) & RTU_PMC_MCR_ARRAY_MASK)

#define RTU_PMC_MCR_PD_MASK                      (0x1F00U)
#define RTU_PMC_MCR_PD_SHIFT                     (8U)
#define RTU_PMC_MCR_PD_WIDTH                     (5U)
#define RTU_PMC_MCR_PD(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_MCR_PD_SHIFT)) & RTU_PMC_MCR_PD_MASK)

#define RTU_PMC_MCR_RCO_MASK                     (0x1E000U)
#define RTU_PMC_MCR_RCO_SHIFT                    (13U)
#define RTU_PMC_MCR_RCO_WIDTH                    (4U)
#define RTU_PMC_MCR_RCO(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_MCR_RCO_SHIFT)) & RTU_PMC_MCR_RCO_MASK)

#define RTU_PMC_MCR_CCW_MASK                     (0x60000U)
#define RTU_PMC_MCR_CCW_SHIFT                    (17U)
#define RTU_PMC_MCR_CCW_WIDTH                    (2U)
#define RTU_PMC_MCR_CCW(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_MCR_CCW_SHIFT)) & RTU_PMC_MCR_CCW_MASK)

#define RTU_PMC_MCR_RCW_MASK                     (0x3E00000U)
#define RTU_PMC_MCR_RCW_SHIFT                    (21U)
#define RTU_PMC_MCR_RCW_WIDTH                    (5U)
#define RTU_PMC_MCR_RCW(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_MCR_RCW_SHIFT)) & RTU_PMC_MCR_RCW_MASK)
/*! @} */

/*! @name BER - Byte Enable Register */
/*! @{ */

#define RTU_PMC_BER_BE_MASK                      (0xFFFFFFFFU)
#define RTU_PMC_BER_BE_SHIFT                     (0U)
#define RTU_PMC_BER_BE_WIDTH                     (32U)
#define RTU_PMC_BER_BE(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_BER_BE_SHIFT)) & RTU_PMC_BER_BE_MASK)
/*! @} */

/*! @name PCR - Program Control Register */
/*! @{ */

#define RTU_PMC_PCR_PC_MASK                      (0x1FU)
#define RTU_PMC_PCR_PC_SHIFT                     (0U)
#define RTU_PMC_PCR_PC_WIDTH                     (5U)
#define RTU_PMC_PCR_PC(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_PCR_PC_SHIFT)) & RTU_PMC_PCR_PC_MASK)
/*! @} */

/*! @name RPR - Read Pipeline Register */
/*! @{ */

#define RTU_PMC_RPR_R_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_RPR_R_SHIFT                      (0U)
#define RTU_PMC_RPR_R_WIDTH                      (32U)
#define RTU_PMC_RPR_R(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_RPR_R_SHIFT)) & RTU_PMC_RPR_R_MASK)
/*! @} */

/*! @name STOPADDR - Stop Address Register */
/*! @{ */

#define RTU_PMC_STOPADDR_SA_MASK                 (0xFFFFFFFFU)
#define RTU_PMC_STOPADDR_SA_SHIFT                (0U)
#define RTU_PMC_STOPADDR_SA_WIDTH                (32U)
#define RTU_PMC_STOPADDR_SA(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_PMC_STOPADDR_SA_SHIFT)) & RTU_PMC_STOPADDR_SA_MASK)
/*! @} */

/*! @name CADDR - Column Address Register */
/*! @{ */

#define RTU_PMC_CADDR_CA_MASK                    (0x1FU)
#define RTU_PMC_CADDR_CA_SHIFT                   (0U)
#define RTU_PMC_CADDR_CA_WIDTH                   (5U)
#define RTU_PMC_CADDR_CA(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CADDR_CA_SHIFT)) & RTU_PMC_CADDR_CA_MASK)
/*! @} */

/*! @name RADDR - Row Address Register */
/*! @{ */

#define RTU_PMC_RADDR_RA_MASK                    (0x3FFFFFFFU)
#define RTU_PMC_RADDR_RA_SHIFT                   (0U)
#define RTU_PMC_RADDR_RA_WIDTH                   (30U)
#define RTU_PMC_RADDR_RA(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_RADDR_RA_SHIFT)) & RTU_PMC_RADDR_RA_MASK)
/*! @} */

/*! @name X0 - X Data Register 0 */
/*! @{ */

#define RTU_PMC_X0_X0_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_X0_X0_SHIFT                      (0U)
#define RTU_PMC_X0_X0_WIDTH                      (32U)
#define RTU_PMC_X0_X0(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_X0_X0_SHIFT)) & RTU_PMC_X0_X0_MASK)
/*! @} */

/*! @name X1 - X Data Register 1 */
/*! @{ */

#define RTU_PMC_X1_X1_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_X1_X1_SHIFT                      (0U)
#define RTU_PMC_X1_X1_WIDTH                      (32U)
#define RTU_PMC_X1_X1(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_X1_X1_SHIFT)) & RTU_PMC_X1_X1_MASK)
/*! @} */

/*! @name X2 - X Data Register 2 */
/*! @{ */

#define RTU_PMC_X2_X2_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_X2_X2_SHIFT                      (0U)
#define RTU_PMC_X2_X2_WIDTH                      (32U)
#define RTU_PMC_X2_X2(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_X2_X2_SHIFT)) & RTU_PMC_X2_X2_MASK)
/*! @} */

/*! @name X3 - X Data Register 3 */
/*! @{ */

#define RTU_PMC_X3_X3_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_X3_X3_SHIFT                      (0U)
#define RTU_PMC_X3_X3_WIDTH                      (32U)
#define RTU_PMC_X3_X3(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_X3_X3_SHIFT)) & RTU_PMC_X3_X3_MASK)
/*! @} */

/*! @name X4 - X Data Register 4 */
/*! @{ */

#define RTU_PMC_X4_X4_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_X4_X4_SHIFT                      (0U)
#define RTU_PMC_X4_X4_WIDTH                      (32U)
#define RTU_PMC_X4_X4(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_X4_X4_SHIFT)) & RTU_PMC_X4_X4_MASK)
/*! @} */

/*! @name X5 - X Data Register 5 */
/*! @{ */

#define RTU_PMC_X5_X5_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_X5_X5_SHIFT                      (0U)
#define RTU_PMC_X5_X5_WIDTH                      (32U)
#define RTU_PMC_X5_X5(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_X5_X5_SHIFT)) & RTU_PMC_X5_X5_MASK)
/*! @} */

/*! @name X6 - X Data Register 6 */
/*! @{ */

#define RTU_PMC_X6_X6_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_X6_X6_SHIFT                      (0U)
#define RTU_PMC_X6_X6_WIDTH                      (32U)
#define RTU_PMC_X6_X6(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_X6_X6_SHIFT)) & RTU_PMC_X6_X6_MASK)
/*! @} */

/*! @name X7 - X Data Register 7 */
/*! @{ */

#define RTU_PMC_X7_X7_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_X7_X7_SHIFT                      (0U)
#define RTU_PMC_X7_X7_WIDTH                      (32U)
#define RTU_PMC_X7_X7(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_X7_X7_SHIFT)) & RTU_PMC_X7_X7_MASK)
/*! @} */

/*! @name Y0 - Y Data Register 0 */
/*! @{ */

#define RTU_PMC_Y0_Y0_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_Y0_Y0_SHIFT                      (0U)
#define RTU_PMC_Y0_Y0_WIDTH                      (32U)
#define RTU_PMC_Y0_Y0(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_Y0_Y0_SHIFT)) & RTU_PMC_Y0_Y0_MASK)
/*! @} */

/*! @name Y1 - Y Data Register 1 */
/*! @{ */

#define RTU_PMC_Y1_Y1_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_Y1_Y1_SHIFT                      (0U)
#define RTU_PMC_Y1_Y1_WIDTH                      (32U)
#define RTU_PMC_Y1_Y1(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_Y1_Y1_SHIFT)) & RTU_PMC_Y1_Y1_MASK)
/*! @} */

/*! @name Y2 - Y Data Register 2 */
/*! @{ */

#define RTU_PMC_Y2_Y2_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_Y2_Y2_SHIFT                      (0U)
#define RTU_PMC_Y2_Y2_WIDTH                      (32U)
#define RTU_PMC_Y2_Y2(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_Y2_Y2_SHIFT)) & RTU_PMC_Y2_Y2_MASK)
/*! @} */

/*! @name Y3 - Y Data Register 3 */
/*! @{ */

#define RTU_PMC_Y3_Y3_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_Y3_Y3_SHIFT                      (0U)
#define RTU_PMC_Y3_Y3_WIDTH                      (32U)
#define RTU_PMC_Y3_Y3(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_Y3_Y3_SHIFT)) & RTU_PMC_Y3_Y3_MASK)
/*! @} */

/*! @name Y4 - Y Data Register 4 */
/*! @{ */

#define RTU_PMC_Y4_Y4_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_Y4_Y4_SHIFT                      (0U)
#define RTU_PMC_Y4_Y4_WIDTH                      (32U)
#define RTU_PMC_Y4_Y4(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_Y4_Y4_SHIFT)) & RTU_PMC_Y4_Y4_MASK)
/*! @} */

/*! @name Y5 - Y Data Register 5 */
/*! @{ */

#define RTU_PMC_Y5_Y5_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_Y5_Y5_SHIFT                      (0U)
#define RTU_PMC_Y5_Y5_WIDTH                      (32U)
#define RTU_PMC_Y5_Y5(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_Y5_Y5_SHIFT)) & RTU_PMC_Y5_Y5_MASK)
/*! @} */

/*! @name Y6 - Y Data Register 6 */
/*! @{ */

#define RTU_PMC_Y6_Y6_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_Y6_Y6_SHIFT                      (0U)
#define RTU_PMC_Y6_Y6_WIDTH                      (32U)
#define RTU_PMC_Y6_Y6(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_Y6_Y6_SHIFT)) & RTU_PMC_Y6_Y6_MASK)
/*! @} */

/*! @name Y7 - Y Data Register 7 */
/*! @{ */

#define RTU_PMC_Y7_Y7_MASK                       (0xFFFFFFFFU)
#define RTU_PMC_Y7_Y7_SHIFT                      (0U)
#define RTU_PMC_Y7_Y7_WIDTH                      (32U)
#define RTU_PMC_Y7_Y7(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_Y7_Y7_SHIFT)) & RTU_PMC_Y7_Y7_MASK)
/*! @} */

/*! @name AIR - Auxiliary Input Register */
/*! @{ */

#define RTU_PMC_AIR_AIR_MASK                     (0xFFFFFFFFU)
#define RTU_PMC_AIR_AIR_SHIFT                    (0U)
#define RTU_PMC_AIR_AIR_WIDTH                    (32U)
#define RTU_PMC_AIR_AIR(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_AIR_AIR_SHIFT)) & RTU_PMC_AIR_AIR_MASK)
/*! @} */

/*! @name AOR - Auxiliary Output Register */
/*! @{ */

#define RTU_PMC_AOR_AOR_MASK                     (0xFFFFFFFFU)
#define RTU_PMC_AOR_AOR_SHIFT                    (0U)
#define RTU_PMC_AOR_AOR_WIDTH                    (32U)
#define RTU_PMC_AOR_AOR(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_AOR_AOR_SHIFT)) & RTU_PMC_AOR_AOR_MASK)
/*! @} */

/*! @name DM0 - Data Mask Register 0 */
/*! @{ */

#define RTU_PMC_DM0_DM0_MASK                     (0xFFFFFFFFU)
#define RTU_PMC_DM0_DM0_SHIFT                    (0U)
#define RTU_PMC_DM0_DM0_WIDTH                    (32U)
#define RTU_PMC_DM0_DM0(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DM0_DM0_SHIFT)) & RTU_PMC_DM0_DM0_MASK)
/*! @} */

/*! @name DM1 - Data Mask Register 1 */
/*! @{ */

#define RTU_PMC_DM1_DM1_MASK                     (0xFFFFFFFFU)
#define RTU_PMC_DM1_DM1_SHIFT                    (0U)
#define RTU_PMC_DM1_DM1_WIDTH                    (32U)
#define RTU_PMC_DM1_DM1(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DM1_DM1_SHIFT)) & RTU_PMC_DM1_DM1_MASK)
/*! @} */

/*! @name DM2 - Data Mask Register 2 */
/*! @{ */

#define RTU_PMC_DM2_DM2_MASK                     (0xFFFFFFFFU)
#define RTU_PMC_DM2_DM2_SHIFT                    (0U)
#define RTU_PMC_DM2_DM2_WIDTH                    (32U)
#define RTU_PMC_DM2_DM2(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DM2_DM2_SHIFT)) & RTU_PMC_DM2_DM2_MASK)
/*! @} */

/*! @name DM3 - Data Mask Register 3 */
/*! @{ */

#define RTU_PMC_DM3_DM3_MASK                     (0xFFFFFFFFU)
#define RTU_PMC_DM3_DM3_SHIFT                    (0U)
#define RTU_PMC_DM3_DM3_WIDTH                    (32U)
#define RTU_PMC_DM3_DM3(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DM3_DM3_SHIFT)) & RTU_PMC_DM3_DM3_MASK)
/*! @} */

/*! @name DM4 - Data Mask Register 4 */
/*! @{ */

#define RTU_PMC_DM4_DM4_MASK                     (0xFFFFFFFFU)
#define RTU_PMC_DM4_DM4_SHIFT                    (0U)
#define RTU_PMC_DM4_DM4_WIDTH                    (32U)
#define RTU_PMC_DM4_DM4(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DM4_DM4_SHIFT)) & RTU_PMC_DM4_DM4_MASK)
/*! @} */

/*! @name DM5 - Data Mask Register 5 */
/*! @{ */

#define RTU_PMC_DM5_DM5_MASK                     (0xFFFFFFFFU)
#define RTU_PMC_DM5_DM5_SHIFT                    (0U)
#define RTU_PMC_DM5_DM5_WIDTH                    (32U)
#define RTU_PMC_DM5_DM5(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DM5_DM5_SHIFT)) & RTU_PMC_DM5_DM5_MASK)
/*! @} */

/*! @name DM6 - Data Mask Register 6 */
/*! @{ */

#define RTU_PMC_DM6_DM6_MASK                     (0xFFFFFFFFU)
#define RTU_PMC_DM6_DM6_SHIFT                    (0U)
#define RTU_PMC_DM6_DM6_WIDTH                    (32U)
#define RTU_PMC_DM6_DM6(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DM6_DM6_SHIFT)) & RTU_PMC_DM6_DM6_MASK)
/*! @} */

/*! @name DM7 - Data Mask Register 7 */
/*! @{ */

#define RTU_PMC_DM7_DM7_MASK                     (0xFFFFFFFFU)
#define RTU_PMC_DM7_DM7_SHIFT                    (0U)
#define RTU_PMC_DM7_DM7_WIDTH                    (32U)
#define RTU_PMC_DM7_DM7(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DM7_DM7_SHIFT)) & RTU_PMC_DM7_DM7_MASK)
/*! @} */

/*! @name P0 - Program Register 0 */
/*! @{ */

#define RTU_PMC_P0_OP_MASK                       (0x3U)
#define RTU_PMC_P0_OP_SHIFT                      (0U)
#define RTU_PMC_P0_OP_WIDTH                      (2U)
#define RTU_PMC_P0_OP(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P0_OP_SHIFT)) & RTU_PMC_P0_OP_MASK)

#define RTU_PMC_P0_TRANS_MASK                    (0x30U)
#define RTU_PMC_P0_TRANS_SHIFT                   (4U)
#define RTU_PMC_P0_TRANS_WIDTH                   (2U)
#define RTU_PMC_P0_TRANS(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P0_TRANS_SHIFT)) & RTU_PMC_P0_TRANS_MASK)

#define RTU_PMC_P0_DREG_MASK                     (0x40U)
#define RTU_PMC_P0_DREG_SHIFT                    (6U)
#define RTU_PMC_P0_DREG_WIDTH                    (1U)
#define RTU_PMC_P0_DREG(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P0_DREG_SHIFT)) & RTU_PMC_P0_DREG_MASK)

#define RTU_PMC_P0_DPOL_MASK                     (0x80U)
#define RTU_PMC_P0_DPOL_SHIFT                    (7U)
#define RTU_PMC_P0_DPOL_WIDTH                    (1U)
#define RTU_PMC_P0_DPOL(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P0_DPOL_SHIFT)) & RTU_PMC_P0_DPOL_MASK)

#define RTU_PMC_P0_UA_MASK                       (0x100U)
#define RTU_PMC_P0_UA_SHIFT                      (8U)
#define RTU_PMC_P0_UA_WIDTH                      (1U)
#define RTU_PMC_P0_UA(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P0_UA_SHIFT)) & RTU_PMC_P0_UA_MASK)

#define RTU_PMC_P0_AO_MASK                       (0x200U)
#define RTU_PMC_P0_AO_SHIFT                      (9U)
#define RTU_PMC_P0_AO_WIDTH                      (1U)
#define RTU_PMC_P0_AO(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P0_AO_SHIFT)) & RTU_PMC_P0_AO_MASK)
/*! @} */

/*! @name P1 - Program Register 1 */
/*! @{ */

#define RTU_PMC_P1_OP_MASK                       (0x3U)
#define RTU_PMC_P1_OP_SHIFT                      (0U)
#define RTU_PMC_P1_OP_WIDTH                      (2U)
#define RTU_PMC_P1_OP(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P1_OP_SHIFT)) & RTU_PMC_P1_OP_MASK)

#define RTU_PMC_P1_TRANS_MASK                    (0x30U)
#define RTU_PMC_P1_TRANS_SHIFT                   (4U)
#define RTU_PMC_P1_TRANS_WIDTH                   (2U)
#define RTU_PMC_P1_TRANS(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P1_TRANS_SHIFT)) & RTU_PMC_P1_TRANS_MASK)

#define RTU_PMC_P1_DREG_MASK                     (0x40U)
#define RTU_PMC_P1_DREG_SHIFT                    (6U)
#define RTU_PMC_P1_DREG_WIDTH                    (1U)
#define RTU_PMC_P1_DREG(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P1_DREG_SHIFT)) & RTU_PMC_P1_DREG_MASK)

#define RTU_PMC_P1_DPOL_MASK                     (0x80U)
#define RTU_PMC_P1_DPOL_SHIFT                    (7U)
#define RTU_PMC_P1_DPOL_WIDTH                    (1U)
#define RTU_PMC_P1_DPOL(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P1_DPOL_SHIFT)) & RTU_PMC_P1_DPOL_MASK)

#define RTU_PMC_P1_UA_MASK                       (0x100U)
#define RTU_PMC_P1_UA_SHIFT                      (8U)
#define RTU_PMC_P1_UA_WIDTH                      (1U)
#define RTU_PMC_P1_UA(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P1_UA_SHIFT)) & RTU_PMC_P1_UA_MASK)

#define RTU_PMC_P1_AO_MASK                       (0x200U)
#define RTU_PMC_P1_AO_SHIFT                      (9U)
#define RTU_PMC_P1_AO_WIDTH                      (1U)
#define RTU_PMC_P1_AO(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P1_AO_SHIFT)) & RTU_PMC_P1_AO_MASK)
/*! @} */

/*! @name P2 - Program Register 2 */
/*! @{ */

#define RTU_PMC_P2_OP_MASK                       (0x3U)
#define RTU_PMC_P2_OP_SHIFT                      (0U)
#define RTU_PMC_P2_OP_WIDTH                      (2U)
#define RTU_PMC_P2_OP(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P2_OP_SHIFT)) & RTU_PMC_P2_OP_MASK)

#define RTU_PMC_P2_TRANS_MASK                    (0x30U)
#define RTU_PMC_P2_TRANS_SHIFT                   (4U)
#define RTU_PMC_P2_TRANS_WIDTH                   (2U)
#define RTU_PMC_P2_TRANS(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P2_TRANS_SHIFT)) & RTU_PMC_P2_TRANS_MASK)

#define RTU_PMC_P2_DREG_MASK                     (0x40U)
#define RTU_PMC_P2_DREG_SHIFT                    (6U)
#define RTU_PMC_P2_DREG_WIDTH                    (1U)
#define RTU_PMC_P2_DREG(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P2_DREG_SHIFT)) & RTU_PMC_P2_DREG_MASK)

#define RTU_PMC_P2_DPOL_MASK                     (0x80U)
#define RTU_PMC_P2_DPOL_SHIFT                    (7U)
#define RTU_PMC_P2_DPOL_WIDTH                    (1U)
#define RTU_PMC_P2_DPOL(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P2_DPOL_SHIFT)) & RTU_PMC_P2_DPOL_MASK)

#define RTU_PMC_P2_UA_MASK                       (0x100U)
#define RTU_PMC_P2_UA_SHIFT                      (8U)
#define RTU_PMC_P2_UA_WIDTH                      (1U)
#define RTU_PMC_P2_UA(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P2_UA_SHIFT)) & RTU_PMC_P2_UA_MASK)

#define RTU_PMC_P2_AO_MASK                       (0x200U)
#define RTU_PMC_P2_AO_SHIFT                      (9U)
#define RTU_PMC_P2_AO_WIDTH                      (1U)
#define RTU_PMC_P2_AO(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P2_AO_SHIFT)) & RTU_PMC_P2_AO_MASK)
/*! @} */

/*! @name P3 - Program Register 3 */
/*! @{ */

#define RTU_PMC_P3_OP_MASK                       (0x3U)
#define RTU_PMC_P3_OP_SHIFT                      (0U)
#define RTU_PMC_P3_OP_WIDTH                      (2U)
#define RTU_PMC_P3_OP(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P3_OP_SHIFT)) & RTU_PMC_P3_OP_MASK)

#define RTU_PMC_P3_TRANS_MASK                    (0x30U)
#define RTU_PMC_P3_TRANS_SHIFT                   (4U)
#define RTU_PMC_P3_TRANS_WIDTH                   (2U)
#define RTU_PMC_P3_TRANS(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P3_TRANS_SHIFT)) & RTU_PMC_P3_TRANS_MASK)

#define RTU_PMC_P3_DREG_MASK                     (0x40U)
#define RTU_PMC_P3_DREG_SHIFT                    (6U)
#define RTU_PMC_P3_DREG_WIDTH                    (1U)
#define RTU_PMC_P3_DREG(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P3_DREG_SHIFT)) & RTU_PMC_P3_DREG_MASK)

#define RTU_PMC_P3_DPOL_MASK                     (0x80U)
#define RTU_PMC_P3_DPOL_SHIFT                    (7U)
#define RTU_PMC_P3_DPOL_WIDTH                    (1U)
#define RTU_PMC_P3_DPOL(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P3_DPOL_SHIFT)) & RTU_PMC_P3_DPOL_MASK)

#define RTU_PMC_P3_UA_MASK                       (0x100U)
#define RTU_PMC_P3_UA_SHIFT                      (8U)
#define RTU_PMC_P3_UA_WIDTH                      (1U)
#define RTU_PMC_P3_UA(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P3_UA_SHIFT)) & RTU_PMC_P3_UA_MASK)

#define RTU_PMC_P3_AO_MASK                       (0x200U)
#define RTU_PMC_P3_AO_SHIFT                      (9U)
#define RTU_PMC_P3_AO_WIDTH                      (1U)
#define RTU_PMC_P3_AO(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P3_AO_SHIFT)) & RTU_PMC_P3_AO_MASK)
/*! @} */

/*! @name P4 - Program Register 4 */
/*! @{ */

#define RTU_PMC_P4_OP_MASK                       (0x3U)
#define RTU_PMC_P4_OP_SHIFT                      (0U)
#define RTU_PMC_P4_OP_WIDTH                      (2U)
#define RTU_PMC_P4_OP(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P4_OP_SHIFT)) & RTU_PMC_P4_OP_MASK)

#define RTU_PMC_P4_TRANS_MASK                    (0x30U)
#define RTU_PMC_P4_TRANS_SHIFT                   (4U)
#define RTU_PMC_P4_TRANS_WIDTH                   (2U)
#define RTU_PMC_P4_TRANS(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P4_TRANS_SHIFT)) & RTU_PMC_P4_TRANS_MASK)

#define RTU_PMC_P4_DREG_MASK                     (0x40U)
#define RTU_PMC_P4_DREG_SHIFT                    (6U)
#define RTU_PMC_P4_DREG_WIDTH                    (1U)
#define RTU_PMC_P4_DREG(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P4_DREG_SHIFT)) & RTU_PMC_P4_DREG_MASK)

#define RTU_PMC_P4_DPOL_MASK                     (0x80U)
#define RTU_PMC_P4_DPOL_SHIFT                    (7U)
#define RTU_PMC_P4_DPOL_WIDTH                    (1U)
#define RTU_PMC_P4_DPOL(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P4_DPOL_SHIFT)) & RTU_PMC_P4_DPOL_MASK)

#define RTU_PMC_P4_UA_MASK                       (0x100U)
#define RTU_PMC_P4_UA_SHIFT                      (8U)
#define RTU_PMC_P4_UA_WIDTH                      (1U)
#define RTU_PMC_P4_UA(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P4_UA_SHIFT)) & RTU_PMC_P4_UA_MASK)

#define RTU_PMC_P4_AO_MASK                       (0x200U)
#define RTU_PMC_P4_AO_SHIFT                      (9U)
#define RTU_PMC_P4_AO_WIDTH                      (1U)
#define RTU_PMC_P4_AO(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P4_AO_SHIFT)) & RTU_PMC_P4_AO_MASK)
/*! @} */

/*! @name P5 - Program Register 5 */
/*! @{ */

#define RTU_PMC_P5_OP_MASK                       (0x3U)
#define RTU_PMC_P5_OP_SHIFT                      (0U)
#define RTU_PMC_P5_OP_WIDTH                      (2U)
#define RTU_PMC_P5_OP(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P5_OP_SHIFT)) & RTU_PMC_P5_OP_MASK)

#define RTU_PMC_P5_TRANS_MASK                    (0x30U)
#define RTU_PMC_P5_TRANS_SHIFT                   (4U)
#define RTU_PMC_P5_TRANS_WIDTH                   (2U)
#define RTU_PMC_P5_TRANS(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P5_TRANS_SHIFT)) & RTU_PMC_P5_TRANS_MASK)

#define RTU_PMC_P5_DREG_MASK                     (0x40U)
#define RTU_PMC_P5_DREG_SHIFT                    (6U)
#define RTU_PMC_P5_DREG_WIDTH                    (1U)
#define RTU_PMC_P5_DREG(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P5_DREG_SHIFT)) & RTU_PMC_P5_DREG_MASK)

#define RTU_PMC_P5_DPOL_MASK                     (0x80U)
#define RTU_PMC_P5_DPOL_SHIFT                    (7U)
#define RTU_PMC_P5_DPOL_WIDTH                    (1U)
#define RTU_PMC_P5_DPOL(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P5_DPOL_SHIFT)) & RTU_PMC_P5_DPOL_MASK)

#define RTU_PMC_P5_UA_MASK                       (0x100U)
#define RTU_PMC_P5_UA_SHIFT                      (8U)
#define RTU_PMC_P5_UA_WIDTH                      (1U)
#define RTU_PMC_P5_UA(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P5_UA_SHIFT)) & RTU_PMC_P5_UA_MASK)

#define RTU_PMC_P5_AO_MASK                       (0x200U)
#define RTU_PMC_P5_AO_SHIFT                      (9U)
#define RTU_PMC_P5_AO_WIDTH                      (1U)
#define RTU_PMC_P5_AO(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P5_AO_SHIFT)) & RTU_PMC_P5_AO_MASK)
/*! @} */

/*! @name P6 - Program Register 6 */
/*! @{ */

#define RTU_PMC_P6_OP_MASK                       (0x3U)
#define RTU_PMC_P6_OP_SHIFT                      (0U)
#define RTU_PMC_P6_OP_WIDTH                      (2U)
#define RTU_PMC_P6_OP(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P6_OP_SHIFT)) & RTU_PMC_P6_OP_MASK)

#define RTU_PMC_P6_TRANS_MASK                    (0x30U)
#define RTU_PMC_P6_TRANS_SHIFT                   (4U)
#define RTU_PMC_P6_TRANS_WIDTH                   (2U)
#define RTU_PMC_P6_TRANS(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P6_TRANS_SHIFT)) & RTU_PMC_P6_TRANS_MASK)

#define RTU_PMC_P6_DREG_MASK                     (0x40U)
#define RTU_PMC_P6_DREG_SHIFT                    (6U)
#define RTU_PMC_P6_DREG_WIDTH                    (1U)
#define RTU_PMC_P6_DREG(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P6_DREG_SHIFT)) & RTU_PMC_P6_DREG_MASK)

#define RTU_PMC_P6_DPOL_MASK                     (0x80U)
#define RTU_PMC_P6_DPOL_SHIFT                    (7U)
#define RTU_PMC_P6_DPOL_WIDTH                    (1U)
#define RTU_PMC_P6_DPOL(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P6_DPOL_SHIFT)) & RTU_PMC_P6_DPOL_MASK)

#define RTU_PMC_P6_UA_MASK                       (0x100U)
#define RTU_PMC_P6_UA_SHIFT                      (8U)
#define RTU_PMC_P6_UA_WIDTH                      (1U)
#define RTU_PMC_P6_UA(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P6_UA_SHIFT)) & RTU_PMC_P6_UA_MASK)

#define RTU_PMC_P6_AO_MASK                       (0x200U)
#define RTU_PMC_P6_AO_SHIFT                      (9U)
#define RTU_PMC_P6_AO_WIDTH                      (1U)
#define RTU_PMC_P6_AO(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P6_AO_SHIFT)) & RTU_PMC_P6_AO_MASK)
/*! @} */

/*! @name P7 - Program Register 7 */
/*! @{ */

#define RTU_PMC_P7_OP_MASK                       (0x3U)
#define RTU_PMC_P7_OP_SHIFT                      (0U)
#define RTU_PMC_P7_OP_WIDTH                      (2U)
#define RTU_PMC_P7_OP(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P7_OP_SHIFT)) & RTU_PMC_P7_OP_MASK)

#define RTU_PMC_P7_TRANS_MASK                    (0x30U)
#define RTU_PMC_P7_TRANS_SHIFT                   (4U)
#define RTU_PMC_P7_TRANS_WIDTH                   (2U)
#define RTU_PMC_P7_TRANS(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P7_TRANS_SHIFT)) & RTU_PMC_P7_TRANS_MASK)

#define RTU_PMC_P7_DREG_MASK                     (0x40U)
#define RTU_PMC_P7_DREG_SHIFT                    (6U)
#define RTU_PMC_P7_DREG_WIDTH                    (1U)
#define RTU_PMC_P7_DREG(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P7_DREG_SHIFT)) & RTU_PMC_P7_DREG_MASK)

#define RTU_PMC_P7_DPOL_MASK                     (0x80U)
#define RTU_PMC_P7_DPOL_SHIFT                    (7U)
#define RTU_PMC_P7_DPOL_WIDTH                    (1U)
#define RTU_PMC_P7_DPOL(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P7_DPOL_SHIFT)) & RTU_PMC_P7_DPOL_MASK)

#define RTU_PMC_P7_UA_MASK                       (0x100U)
#define RTU_PMC_P7_UA_SHIFT                      (8U)
#define RTU_PMC_P7_UA_WIDTH                      (1U)
#define RTU_PMC_P7_UA(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P7_UA_SHIFT)) & RTU_PMC_P7_UA_MASK)

#define RTU_PMC_P7_AO_MASK                       (0x200U)
#define RTU_PMC_P7_AO_SHIFT                      (9U)
#define RTU_PMC_P7_AO_WIDTH                      (1U)
#define RTU_PMC_P7_AO(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P7_AO_SHIFT)) & RTU_PMC_P7_AO_MASK)
/*! @} */

/*! @name P8 - Program Register 8 */
/*! @{ */

#define RTU_PMC_P8_OP_MASK                       (0x3U)
#define RTU_PMC_P8_OP_SHIFT                      (0U)
#define RTU_PMC_P8_OP_WIDTH                      (2U)
#define RTU_PMC_P8_OP(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P8_OP_SHIFT)) & RTU_PMC_P8_OP_MASK)

#define RTU_PMC_P8_TRANS_MASK                    (0x30U)
#define RTU_PMC_P8_TRANS_SHIFT                   (4U)
#define RTU_PMC_P8_TRANS_WIDTH                   (2U)
#define RTU_PMC_P8_TRANS(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P8_TRANS_SHIFT)) & RTU_PMC_P8_TRANS_MASK)

#define RTU_PMC_P8_DREG_MASK                     (0x40U)
#define RTU_PMC_P8_DREG_SHIFT                    (6U)
#define RTU_PMC_P8_DREG_WIDTH                    (1U)
#define RTU_PMC_P8_DREG(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P8_DREG_SHIFT)) & RTU_PMC_P8_DREG_MASK)

#define RTU_PMC_P8_DPOL_MASK                     (0x80U)
#define RTU_PMC_P8_DPOL_SHIFT                    (7U)
#define RTU_PMC_P8_DPOL_WIDTH                    (1U)
#define RTU_PMC_P8_DPOL(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P8_DPOL_SHIFT)) & RTU_PMC_P8_DPOL_MASK)

#define RTU_PMC_P8_UA_MASK                       (0x100U)
#define RTU_PMC_P8_UA_SHIFT                      (8U)
#define RTU_PMC_P8_UA_WIDTH                      (1U)
#define RTU_PMC_P8_UA(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P8_UA_SHIFT)) & RTU_PMC_P8_UA_MASK)

#define RTU_PMC_P8_AO_MASK                       (0x200U)
#define RTU_PMC_P8_AO_SHIFT                      (9U)
#define RTU_PMC_P8_AO_WIDTH                      (1U)
#define RTU_PMC_P8_AO(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P8_AO_SHIFT)) & RTU_PMC_P8_AO_MASK)
/*! @} */

/*! @name P9 - Program Register 9 */
/*! @{ */

#define RTU_PMC_P9_OP_MASK                       (0x3U)
#define RTU_PMC_P9_OP_SHIFT                      (0U)
#define RTU_PMC_P9_OP_WIDTH                      (2U)
#define RTU_PMC_P9_OP(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P9_OP_SHIFT)) & RTU_PMC_P9_OP_MASK)

#define RTU_PMC_P9_TRANS_MASK                    (0x30U)
#define RTU_PMC_P9_TRANS_SHIFT                   (4U)
#define RTU_PMC_P9_TRANS_WIDTH                   (2U)
#define RTU_PMC_P9_TRANS(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P9_TRANS_SHIFT)) & RTU_PMC_P9_TRANS_MASK)

#define RTU_PMC_P9_DREG_MASK                     (0x40U)
#define RTU_PMC_P9_DREG_SHIFT                    (6U)
#define RTU_PMC_P9_DREG_WIDTH                    (1U)
#define RTU_PMC_P9_DREG(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P9_DREG_SHIFT)) & RTU_PMC_P9_DREG_MASK)

#define RTU_PMC_P9_DPOL_MASK                     (0x80U)
#define RTU_PMC_P9_DPOL_SHIFT                    (7U)
#define RTU_PMC_P9_DPOL_WIDTH                    (1U)
#define RTU_PMC_P9_DPOL(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P9_DPOL_SHIFT)) & RTU_PMC_P9_DPOL_MASK)

#define RTU_PMC_P9_UA_MASK                       (0x100U)
#define RTU_PMC_P9_UA_SHIFT                      (8U)
#define RTU_PMC_P9_UA_WIDTH                      (1U)
#define RTU_PMC_P9_UA(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P9_UA_SHIFT)) & RTU_PMC_P9_UA_MASK)

#define RTU_PMC_P9_AO_MASK                       (0x200U)
#define RTU_PMC_P9_AO_SHIFT                      (9U)
#define RTU_PMC_P9_AO_WIDTH                      (1U)
#define RTU_PMC_P9_AO(x)                         (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P9_AO_SHIFT)) & RTU_PMC_P9_AO_MASK)
/*! @} */

/*! @name P10 - Program Register 10 */
/*! @{ */

#define RTU_PMC_P10_OP_MASK                      (0x3U)
#define RTU_PMC_P10_OP_SHIFT                     (0U)
#define RTU_PMC_P10_OP_WIDTH                     (2U)
#define RTU_PMC_P10_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P10_OP_SHIFT)) & RTU_PMC_P10_OP_MASK)

#define RTU_PMC_P10_TRANS_MASK                   (0x30U)
#define RTU_PMC_P10_TRANS_SHIFT                  (4U)
#define RTU_PMC_P10_TRANS_WIDTH                  (2U)
#define RTU_PMC_P10_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P10_TRANS_SHIFT)) & RTU_PMC_P10_TRANS_MASK)

#define RTU_PMC_P10_DREG_MASK                    (0x40U)
#define RTU_PMC_P10_DREG_SHIFT                   (6U)
#define RTU_PMC_P10_DREG_WIDTH                   (1U)
#define RTU_PMC_P10_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P10_DREG_SHIFT)) & RTU_PMC_P10_DREG_MASK)

#define RTU_PMC_P10_DPOL_MASK                    (0x80U)
#define RTU_PMC_P10_DPOL_SHIFT                   (7U)
#define RTU_PMC_P10_DPOL_WIDTH                   (1U)
#define RTU_PMC_P10_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P10_DPOL_SHIFT)) & RTU_PMC_P10_DPOL_MASK)

#define RTU_PMC_P10_UA_MASK                      (0x100U)
#define RTU_PMC_P10_UA_SHIFT                     (8U)
#define RTU_PMC_P10_UA_WIDTH                     (1U)
#define RTU_PMC_P10_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P10_UA_SHIFT)) & RTU_PMC_P10_UA_MASK)

#define RTU_PMC_P10_AO_MASK                      (0x200U)
#define RTU_PMC_P10_AO_SHIFT                     (9U)
#define RTU_PMC_P10_AO_WIDTH                     (1U)
#define RTU_PMC_P10_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P10_AO_SHIFT)) & RTU_PMC_P10_AO_MASK)
/*! @} */

/*! @name P11 - Program Register 11 */
/*! @{ */

#define RTU_PMC_P11_OP_MASK                      (0x3U)
#define RTU_PMC_P11_OP_SHIFT                     (0U)
#define RTU_PMC_P11_OP_WIDTH                     (2U)
#define RTU_PMC_P11_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P11_OP_SHIFT)) & RTU_PMC_P11_OP_MASK)

#define RTU_PMC_P11_TRANS_MASK                   (0x30U)
#define RTU_PMC_P11_TRANS_SHIFT                  (4U)
#define RTU_PMC_P11_TRANS_WIDTH                  (2U)
#define RTU_PMC_P11_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P11_TRANS_SHIFT)) & RTU_PMC_P11_TRANS_MASK)

#define RTU_PMC_P11_DREG_MASK                    (0x40U)
#define RTU_PMC_P11_DREG_SHIFT                   (6U)
#define RTU_PMC_P11_DREG_WIDTH                   (1U)
#define RTU_PMC_P11_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P11_DREG_SHIFT)) & RTU_PMC_P11_DREG_MASK)

#define RTU_PMC_P11_DPOL_MASK                    (0x80U)
#define RTU_PMC_P11_DPOL_SHIFT                   (7U)
#define RTU_PMC_P11_DPOL_WIDTH                   (1U)
#define RTU_PMC_P11_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P11_DPOL_SHIFT)) & RTU_PMC_P11_DPOL_MASK)

#define RTU_PMC_P11_UA_MASK                      (0x100U)
#define RTU_PMC_P11_UA_SHIFT                     (8U)
#define RTU_PMC_P11_UA_WIDTH                     (1U)
#define RTU_PMC_P11_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P11_UA_SHIFT)) & RTU_PMC_P11_UA_MASK)

#define RTU_PMC_P11_AO_MASK                      (0x200U)
#define RTU_PMC_P11_AO_SHIFT                     (9U)
#define RTU_PMC_P11_AO_WIDTH                     (1U)
#define RTU_PMC_P11_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P11_AO_SHIFT)) & RTU_PMC_P11_AO_MASK)
/*! @} */

/*! @name P12 - Program Register 12 */
/*! @{ */

#define RTU_PMC_P12_OP_MASK                      (0x3U)
#define RTU_PMC_P12_OP_SHIFT                     (0U)
#define RTU_PMC_P12_OP_WIDTH                     (2U)
#define RTU_PMC_P12_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P12_OP_SHIFT)) & RTU_PMC_P12_OP_MASK)

#define RTU_PMC_P12_TRANS_MASK                   (0x30U)
#define RTU_PMC_P12_TRANS_SHIFT                  (4U)
#define RTU_PMC_P12_TRANS_WIDTH                  (2U)
#define RTU_PMC_P12_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P12_TRANS_SHIFT)) & RTU_PMC_P12_TRANS_MASK)

#define RTU_PMC_P12_DREG_MASK                    (0x40U)
#define RTU_PMC_P12_DREG_SHIFT                   (6U)
#define RTU_PMC_P12_DREG_WIDTH                   (1U)
#define RTU_PMC_P12_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P12_DREG_SHIFT)) & RTU_PMC_P12_DREG_MASK)

#define RTU_PMC_P12_DPOL_MASK                    (0x80U)
#define RTU_PMC_P12_DPOL_SHIFT                   (7U)
#define RTU_PMC_P12_DPOL_WIDTH                   (1U)
#define RTU_PMC_P12_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P12_DPOL_SHIFT)) & RTU_PMC_P12_DPOL_MASK)

#define RTU_PMC_P12_UA_MASK                      (0x100U)
#define RTU_PMC_P12_UA_SHIFT                     (8U)
#define RTU_PMC_P12_UA_WIDTH                     (1U)
#define RTU_PMC_P12_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P12_UA_SHIFT)) & RTU_PMC_P12_UA_MASK)

#define RTU_PMC_P12_AO_MASK                      (0x200U)
#define RTU_PMC_P12_AO_SHIFT                     (9U)
#define RTU_PMC_P12_AO_WIDTH                     (1U)
#define RTU_PMC_P12_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P12_AO_SHIFT)) & RTU_PMC_P12_AO_MASK)
/*! @} */

/*! @name P13 - Program Register 13 */
/*! @{ */

#define RTU_PMC_P13_OP_MASK                      (0x3U)
#define RTU_PMC_P13_OP_SHIFT                     (0U)
#define RTU_PMC_P13_OP_WIDTH                     (2U)
#define RTU_PMC_P13_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P13_OP_SHIFT)) & RTU_PMC_P13_OP_MASK)

#define RTU_PMC_P13_TRANS_MASK                   (0x30U)
#define RTU_PMC_P13_TRANS_SHIFT                  (4U)
#define RTU_PMC_P13_TRANS_WIDTH                  (2U)
#define RTU_PMC_P13_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P13_TRANS_SHIFT)) & RTU_PMC_P13_TRANS_MASK)

#define RTU_PMC_P13_DREG_MASK                    (0x40U)
#define RTU_PMC_P13_DREG_SHIFT                   (6U)
#define RTU_PMC_P13_DREG_WIDTH                   (1U)
#define RTU_PMC_P13_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P13_DREG_SHIFT)) & RTU_PMC_P13_DREG_MASK)

#define RTU_PMC_P13_DPOL_MASK                    (0x80U)
#define RTU_PMC_P13_DPOL_SHIFT                   (7U)
#define RTU_PMC_P13_DPOL_WIDTH                   (1U)
#define RTU_PMC_P13_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P13_DPOL_SHIFT)) & RTU_PMC_P13_DPOL_MASK)

#define RTU_PMC_P13_UA_MASK                      (0x100U)
#define RTU_PMC_P13_UA_SHIFT                     (8U)
#define RTU_PMC_P13_UA_WIDTH                     (1U)
#define RTU_PMC_P13_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P13_UA_SHIFT)) & RTU_PMC_P13_UA_MASK)

#define RTU_PMC_P13_AO_MASK                      (0x200U)
#define RTU_PMC_P13_AO_SHIFT                     (9U)
#define RTU_PMC_P13_AO_WIDTH                     (1U)
#define RTU_PMC_P13_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P13_AO_SHIFT)) & RTU_PMC_P13_AO_MASK)
/*! @} */

/*! @name P14 - Program Register 14 */
/*! @{ */

#define RTU_PMC_P14_OP_MASK                      (0x3U)
#define RTU_PMC_P14_OP_SHIFT                     (0U)
#define RTU_PMC_P14_OP_WIDTH                     (2U)
#define RTU_PMC_P14_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P14_OP_SHIFT)) & RTU_PMC_P14_OP_MASK)

#define RTU_PMC_P14_TRANS_MASK                   (0x30U)
#define RTU_PMC_P14_TRANS_SHIFT                  (4U)
#define RTU_PMC_P14_TRANS_WIDTH                  (2U)
#define RTU_PMC_P14_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P14_TRANS_SHIFT)) & RTU_PMC_P14_TRANS_MASK)

#define RTU_PMC_P14_DREG_MASK                    (0x40U)
#define RTU_PMC_P14_DREG_SHIFT                   (6U)
#define RTU_PMC_P14_DREG_WIDTH                   (1U)
#define RTU_PMC_P14_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P14_DREG_SHIFT)) & RTU_PMC_P14_DREG_MASK)

#define RTU_PMC_P14_DPOL_MASK                    (0x80U)
#define RTU_PMC_P14_DPOL_SHIFT                   (7U)
#define RTU_PMC_P14_DPOL_WIDTH                   (1U)
#define RTU_PMC_P14_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P14_DPOL_SHIFT)) & RTU_PMC_P14_DPOL_MASK)

#define RTU_PMC_P14_UA_MASK                      (0x100U)
#define RTU_PMC_P14_UA_SHIFT                     (8U)
#define RTU_PMC_P14_UA_WIDTH                     (1U)
#define RTU_PMC_P14_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P14_UA_SHIFT)) & RTU_PMC_P14_UA_MASK)

#define RTU_PMC_P14_AO_MASK                      (0x200U)
#define RTU_PMC_P14_AO_SHIFT                     (9U)
#define RTU_PMC_P14_AO_WIDTH                     (1U)
#define RTU_PMC_P14_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P14_AO_SHIFT)) & RTU_PMC_P14_AO_MASK)
/*! @} */

/*! @name P15 - Program Register 15 */
/*! @{ */

#define RTU_PMC_P15_OP_MASK                      (0x3U)
#define RTU_PMC_P15_OP_SHIFT                     (0U)
#define RTU_PMC_P15_OP_WIDTH                     (2U)
#define RTU_PMC_P15_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P15_OP_SHIFT)) & RTU_PMC_P15_OP_MASK)

#define RTU_PMC_P15_TRANS_MASK                   (0x30U)
#define RTU_PMC_P15_TRANS_SHIFT                  (4U)
#define RTU_PMC_P15_TRANS_WIDTH                  (2U)
#define RTU_PMC_P15_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P15_TRANS_SHIFT)) & RTU_PMC_P15_TRANS_MASK)

#define RTU_PMC_P15_DREG_MASK                    (0x40U)
#define RTU_PMC_P15_DREG_SHIFT                   (6U)
#define RTU_PMC_P15_DREG_WIDTH                   (1U)
#define RTU_PMC_P15_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P15_DREG_SHIFT)) & RTU_PMC_P15_DREG_MASK)

#define RTU_PMC_P15_DPOL_MASK                    (0x80U)
#define RTU_PMC_P15_DPOL_SHIFT                   (7U)
#define RTU_PMC_P15_DPOL_WIDTH                   (1U)
#define RTU_PMC_P15_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P15_DPOL_SHIFT)) & RTU_PMC_P15_DPOL_MASK)

#define RTU_PMC_P15_UA_MASK                      (0x100U)
#define RTU_PMC_P15_UA_SHIFT                     (8U)
#define RTU_PMC_P15_UA_WIDTH                     (1U)
#define RTU_PMC_P15_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P15_UA_SHIFT)) & RTU_PMC_P15_UA_MASK)

#define RTU_PMC_P15_AO_MASK                      (0x200U)
#define RTU_PMC_P15_AO_SHIFT                     (9U)
#define RTU_PMC_P15_AO_WIDTH                     (1U)
#define RTU_PMC_P15_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P15_AO_SHIFT)) & RTU_PMC_P15_AO_MASK)
/*! @} */

/*! @name P16 - Program Register 16 */
/*! @{ */

#define RTU_PMC_P16_OP_MASK                      (0x3U)
#define RTU_PMC_P16_OP_SHIFT                     (0U)
#define RTU_PMC_P16_OP_WIDTH                     (2U)
#define RTU_PMC_P16_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P16_OP_SHIFT)) & RTU_PMC_P16_OP_MASK)

#define RTU_PMC_P16_TRANS_MASK                   (0x30U)
#define RTU_PMC_P16_TRANS_SHIFT                  (4U)
#define RTU_PMC_P16_TRANS_WIDTH                  (2U)
#define RTU_PMC_P16_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P16_TRANS_SHIFT)) & RTU_PMC_P16_TRANS_MASK)

#define RTU_PMC_P16_DREG_MASK                    (0x40U)
#define RTU_PMC_P16_DREG_SHIFT                   (6U)
#define RTU_PMC_P16_DREG_WIDTH                   (1U)
#define RTU_PMC_P16_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P16_DREG_SHIFT)) & RTU_PMC_P16_DREG_MASK)

#define RTU_PMC_P16_DPOL_MASK                    (0x80U)
#define RTU_PMC_P16_DPOL_SHIFT                   (7U)
#define RTU_PMC_P16_DPOL_WIDTH                   (1U)
#define RTU_PMC_P16_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P16_DPOL_SHIFT)) & RTU_PMC_P16_DPOL_MASK)

#define RTU_PMC_P16_UA_MASK                      (0x100U)
#define RTU_PMC_P16_UA_SHIFT                     (8U)
#define RTU_PMC_P16_UA_WIDTH                     (1U)
#define RTU_PMC_P16_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P16_UA_SHIFT)) & RTU_PMC_P16_UA_MASK)

#define RTU_PMC_P16_AO_MASK                      (0x200U)
#define RTU_PMC_P16_AO_SHIFT                     (9U)
#define RTU_PMC_P16_AO_WIDTH                     (1U)
#define RTU_PMC_P16_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P16_AO_SHIFT)) & RTU_PMC_P16_AO_MASK)
/*! @} */

/*! @name P17 - Program Register 17 */
/*! @{ */

#define RTU_PMC_P17_OP_MASK                      (0x3U)
#define RTU_PMC_P17_OP_SHIFT                     (0U)
#define RTU_PMC_P17_OP_WIDTH                     (2U)
#define RTU_PMC_P17_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P17_OP_SHIFT)) & RTU_PMC_P17_OP_MASK)

#define RTU_PMC_P17_TRANS_MASK                   (0x30U)
#define RTU_PMC_P17_TRANS_SHIFT                  (4U)
#define RTU_PMC_P17_TRANS_WIDTH                  (2U)
#define RTU_PMC_P17_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P17_TRANS_SHIFT)) & RTU_PMC_P17_TRANS_MASK)

#define RTU_PMC_P17_DREG_MASK                    (0x40U)
#define RTU_PMC_P17_DREG_SHIFT                   (6U)
#define RTU_PMC_P17_DREG_WIDTH                   (1U)
#define RTU_PMC_P17_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P17_DREG_SHIFT)) & RTU_PMC_P17_DREG_MASK)

#define RTU_PMC_P17_DPOL_MASK                    (0x80U)
#define RTU_PMC_P17_DPOL_SHIFT                   (7U)
#define RTU_PMC_P17_DPOL_WIDTH                   (1U)
#define RTU_PMC_P17_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P17_DPOL_SHIFT)) & RTU_PMC_P17_DPOL_MASK)

#define RTU_PMC_P17_UA_MASK                      (0x100U)
#define RTU_PMC_P17_UA_SHIFT                     (8U)
#define RTU_PMC_P17_UA_WIDTH                     (1U)
#define RTU_PMC_P17_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P17_UA_SHIFT)) & RTU_PMC_P17_UA_MASK)

#define RTU_PMC_P17_AO_MASK                      (0x200U)
#define RTU_PMC_P17_AO_SHIFT                     (9U)
#define RTU_PMC_P17_AO_WIDTH                     (1U)
#define RTU_PMC_P17_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P17_AO_SHIFT)) & RTU_PMC_P17_AO_MASK)
/*! @} */

/*! @name P18 - Program Register 18 */
/*! @{ */

#define RTU_PMC_P18_OP_MASK                      (0x3U)
#define RTU_PMC_P18_OP_SHIFT                     (0U)
#define RTU_PMC_P18_OP_WIDTH                     (2U)
#define RTU_PMC_P18_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P18_OP_SHIFT)) & RTU_PMC_P18_OP_MASK)

#define RTU_PMC_P18_TRANS_MASK                   (0x30U)
#define RTU_PMC_P18_TRANS_SHIFT                  (4U)
#define RTU_PMC_P18_TRANS_WIDTH                  (2U)
#define RTU_PMC_P18_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P18_TRANS_SHIFT)) & RTU_PMC_P18_TRANS_MASK)

#define RTU_PMC_P18_DREG_MASK                    (0x40U)
#define RTU_PMC_P18_DREG_SHIFT                   (6U)
#define RTU_PMC_P18_DREG_WIDTH                   (1U)
#define RTU_PMC_P18_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P18_DREG_SHIFT)) & RTU_PMC_P18_DREG_MASK)

#define RTU_PMC_P18_DPOL_MASK                    (0x80U)
#define RTU_PMC_P18_DPOL_SHIFT                   (7U)
#define RTU_PMC_P18_DPOL_WIDTH                   (1U)
#define RTU_PMC_P18_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P18_DPOL_SHIFT)) & RTU_PMC_P18_DPOL_MASK)

#define RTU_PMC_P18_UA_MASK                      (0x100U)
#define RTU_PMC_P18_UA_SHIFT                     (8U)
#define RTU_PMC_P18_UA_WIDTH                     (1U)
#define RTU_PMC_P18_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P18_UA_SHIFT)) & RTU_PMC_P18_UA_MASK)

#define RTU_PMC_P18_AO_MASK                      (0x200U)
#define RTU_PMC_P18_AO_SHIFT                     (9U)
#define RTU_PMC_P18_AO_WIDTH                     (1U)
#define RTU_PMC_P18_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P18_AO_SHIFT)) & RTU_PMC_P18_AO_MASK)
/*! @} */

/*! @name P19 - Program Register 19 */
/*! @{ */

#define RTU_PMC_P19_OP_MASK                      (0x3U)
#define RTU_PMC_P19_OP_SHIFT                     (0U)
#define RTU_PMC_P19_OP_WIDTH                     (2U)
#define RTU_PMC_P19_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P19_OP_SHIFT)) & RTU_PMC_P19_OP_MASK)

#define RTU_PMC_P19_TRANS_MASK                   (0x30U)
#define RTU_PMC_P19_TRANS_SHIFT                  (4U)
#define RTU_PMC_P19_TRANS_WIDTH                  (2U)
#define RTU_PMC_P19_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P19_TRANS_SHIFT)) & RTU_PMC_P19_TRANS_MASK)

#define RTU_PMC_P19_DREG_MASK                    (0x40U)
#define RTU_PMC_P19_DREG_SHIFT                   (6U)
#define RTU_PMC_P19_DREG_WIDTH                   (1U)
#define RTU_PMC_P19_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P19_DREG_SHIFT)) & RTU_PMC_P19_DREG_MASK)

#define RTU_PMC_P19_DPOL_MASK                    (0x80U)
#define RTU_PMC_P19_DPOL_SHIFT                   (7U)
#define RTU_PMC_P19_DPOL_WIDTH                   (1U)
#define RTU_PMC_P19_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P19_DPOL_SHIFT)) & RTU_PMC_P19_DPOL_MASK)

#define RTU_PMC_P19_UA_MASK                      (0x100U)
#define RTU_PMC_P19_UA_SHIFT                     (8U)
#define RTU_PMC_P19_UA_WIDTH                     (1U)
#define RTU_PMC_P19_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P19_UA_SHIFT)) & RTU_PMC_P19_UA_MASK)

#define RTU_PMC_P19_AO_MASK                      (0x200U)
#define RTU_PMC_P19_AO_SHIFT                     (9U)
#define RTU_PMC_P19_AO_WIDTH                     (1U)
#define RTU_PMC_P19_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P19_AO_SHIFT)) & RTU_PMC_P19_AO_MASK)
/*! @} */

/*! @name P20 - Program Register 20 */
/*! @{ */

#define RTU_PMC_P20_OP_MASK                      (0x3U)
#define RTU_PMC_P20_OP_SHIFT                     (0U)
#define RTU_PMC_P20_OP_WIDTH                     (2U)
#define RTU_PMC_P20_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P20_OP_SHIFT)) & RTU_PMC_P20_OP_MASK)

#define RTU_PMC_P20_TRANS_MASK                   (0x30U)
#define RTU_PMC_P20_TRANS_SHIFT                  (4U)
#define RTU_PMC_P20_TRANS_WIDTH                  (2U)
#define RTU_PMC_P20_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P20_TRANS_SHIFT)) & RTU_PMC_P20_TRANS_MASK)

#define RTU_PMC_P20_DREG_MASK                    (0x40U)
#define RTU_PMC_P20_DREG_SHIFT                   (6U)
#define RTU_PMC_P20_DREG_WIDTH                   (1U)
#define RTU_PMC_P20_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P20_DREG_SHIFT)) & RTU_PMC_P20_DREG_MASK)

#define RTU_PMC_P20_DPOL_MASK                    (0x80U)
#define RTU_PMC_P20_DPOL_SHIFT                   (7U)
#define RTU_PMC_P20_DPOL_WIDTH                   (1U)
#define RTU_PMC_P20_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P20_DPOL_SHIFT)) & RTU_PMC_P20_DPOL_MASK)

#define RTU_PMC_P20_UA_MASK                      (0x100U)
#define RTU_PMC_P20_UA_SHIFT                     (8U)
#define RTU_PMC_P20_UA_WIDTH                     (1U)
#define RTU_PMC_P20_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P20_UA_SHIFT)) & RTU_PMC_P20_UA_MASK)

#define RTU_PMC_P20_AO_MASK                      (0x200U)
#define RTU_PMC_P20_AO_SHIFT                     (9U)
#define RTU_PMC_P20_AO_WIDTH                     (1U)
#define RTU_PMC_P20_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P20_AO_SHIFT)) & RTU_PMC_P20_AO_MASK)
/*! @} */

/*! @name P21 - Program Register 21 */
/*! @{ */

#define RTU_PMC_P21_OP_MASK                      (0x3U)
#define RTU_PMC_P21_OP_SHIFT                     (0U)
#define RTU_PMC_P21_OP_WIDTH                     (2U)
#define RTU_PMC_P21_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P21_OP_SHIFT)) & RTU_PMC_P21_OP_MASK)

#define RTU_PMC_P21_TRANS_MASK                   (0x30U)
#define RTU_PMC_P21_TRANS_SHIFT                  (4U)
#define RTU_PMC_P21_TRANS_WIDTH                  (2U)
#define RTU_PMC_P21_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P21_TRANS_SHIFT)) & RTU_PMC_P21_TRANS_MASK)

#define RTU_PMC_P21_DREG_MASK                    (0x40U)
#define RTU_PMC_P21_DREG_SHIFT                   (6U)
#define RTU_PMC_P21_DREG_WIDTH                   (1U)
#define RTU_PMC_P21_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P21_DREG_SHIFT)) & RTU_PMC_P21_DREG_MASK)

#define RTU_PMC_P21_DPOL_MASK                    (0x80U)
#define RTU_PMC_P21_DPOL_SHIFT                   (7U)
#define RTU_PMC_P21_DPOL_WIDTH                   (1U)
#define RTU_PMC_P21_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P21_DPOL_SHIFT)) & RTU_PMC_P21_DPOL_MASK)

#define RTU_PMC_P21_UA_MASK                      (0x100U)
#define RTU_PMC_P21_UA_SHIFT                     (8U)
#define RTU_PMC_P21_UA_WIDTH                     (1U)
#define RTU_PMC_P21_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P21_UA_SHIFT)) & RTU_PMC_P21_UA_MASK)

#define RTU_PMC_P21_AO_MASK                      (0x200U)
#define RTU_PMC_P21_AO_SHIFT                     (9U)
#define RTU_PMC_P21_AO_WIDTH                     (1U)
#define RTU_PMC_P21_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P21_AO_SHIFT)) & RTU_PMC_P21_AO_MASK)
/*! @} */

/*! @name P22 - Program Register 22 */
/*! @{ */

#define RTU_PMC_P22_OP_MASK                      (0x3U)
#define RTU_PMC_P22_OP_SHIFT                     (0U)
#define RTU_PMC_P22_OP_WIDTH                     (2U)
#define RTU_PMC_P22_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P22_OP_SHIFT)) & RTU_PMC_P22_OP_MASK)

#define RTU_PMC_P22_TRANS_MASK                   (0x30U)
#define RTU_PMC_P22_TRANS_SHIFT                  (4U)
#define RTU_PMC_P22_TRANS_WIDTH                  (2U)
#define RTU_PMC_P22_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P22_TRANS_SHIFT)) & RTU_PMC_P22_TRANS_MASK)

#define RTU_PMC_P22_DREG_MASK                    (0x40U)
#define RTU_PMC_P22_DREG_SHIFT                   (6U)
#define RTU_PMC_P22_DREG_WIDTH                   (1U)
#define RTU_PMC_P22_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P22_DREG_SHIFT)) & RTU_PMC_P22_DREG_MASK)

#define RTU_PMC_P22_DPOL_MASK                    (0x80U)
#define RTU_PMC_P22_DPOL_SHIFT                   (7U)
#define RTU_PMC_P22_DPOL_WIDTH                   (1U)
#define RTU_PMC_P22_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P22_DPOL_SHIFT)) & RTU_PMC_P22_DPOL_MASK)

#define RTU_PMC_P22_UA_MASK                      (0x100U)
#define RTU_PMC_P22_UA_SHIFT                     (8U)
#define RTU_PMC_P22_UA_WIDTH                     (1U)
#define RTU_PMC_P22_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P22_UA_SHIFT)) & RTU_PMC_P22_UA_MASK)

#define RTU_PMC_P22_AO_MASK                      (0x200U)
#define RTU_PMC_P22_AO_SHIFT                     (9U)
#define RTU_PMC_P22_AO_WIDTH                     (1U)
#define RTU_PMC_P22_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P22_AO_SHIFT)) & RTU_PMC_P22_AO_MASK)
/*! @} */

/*! @name P23 - Program Register 23 */
/*! @{ */

#define RTU_PMC_P23_OP_MASK                      (0x3U)
#define RTU_PMC_P23_OP_SHIFT                     (0U)
#define RTU_PMC_P23_OP_WIDTH                     (2U)
#define RTU_PMC_P23_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P23_OP_SHIFT)) & RTU_PMC_P23_OP_MASK)

#define RTU_PMC_P23_TRANS_MASK                   (0x30U)
#define RTU_PMC_P23_TRANS_SHIFT                  (4U)
#define RTU_PMC_P23_TRANS_WIDTH                  (2U)
#define RTU_PMC_P23_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P23_TRANS_SHIFT)) & RTU_PMC_P23_TRANS_MASK)

#define RTU_PMC_P23_DREG_MASK                    (0x40U)
#define RTU_PMC_P23_DREG_SHIFT                   (6U)
#define RTU_PMC_P23_DREG_WIDTH                   (1U)
#define RTU_PMC_P23_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P23_DREG_SHIFT)) & RTU_PMC_P23_DREG_MASK)

#define RTU_PMC_P23_DPOL_MASK                    (0x80U)
#define RTU_PMC_P23_DPOL_SHIFT                   (7U)
#define RTU_PMC_P23_DPOL_WIDTH                   (1U)
#define RTU_PMC_P23_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P23_DPOL_SHIFT)) & RTU_PMC_P23_DPOL_MASK)

#define RTU_PMC_P23_UA_MASK                      (0x100U)
#define RTU_PMC_P23_UA_SHIFT                     (8U)
#define RTU_PMC_P23_UA_WIDTH                     (1U)
#define RTU_PMC_P23_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P23_UA_SHIFT)) & RTU_PMC_P23_UA_MASK)

#define RTU_PMC_P23_AO_MASK                      (0x200U)
#define RTU_PMC_P23_AO_SHIFT                     (9U)
#define RTU_PMC_P23_AO_WIDTH                     (1U)
#define RTU_PMC_P23_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P23_AO_SHIFT)) & RTU_PMC_P23_AO_MASK)
/*! @} */

/*! @name P24 - Program Register 24 */
/*! @{ */

#define RTU_PMC_P24_OP_MASK                      (0x3U)
#define RTU_PMC_P24_OP_SHIFT                     (0U)
#define RTU_PMC_P24_OP_WIDTH                     (2U)
#define RTU_PMC_P24_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P24_OP_SHIFT)) & RTU_PMC_P24_OP_MASK)

#define RTU_PMC_P24_TRANS_MASK                   (0x30U)
#define RTU_PMC_P24_TRANS_SHIFT                  (4U)
#define RTU_PMC_P24_TRANS_WIDTH                  (2U)
#define RTU_PMC_P24_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P24_TRANS_SHIFT)) & RTU_PMC_P24_TRANS_MASK)

#define RTU_PMC_P24_DREG_MASK                    (0x40U)
#define RTU_PMC_P24_DREG_SHIFT                   (6U)
#define RTU_PMC_P24_DREG_WIDTH                   (1U)
#define RTU_PMC_P24_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P24_DREG_SHIFT)) & RTU_PMC_P24_DREG_MASK)

#define RTU_PMC_P24_DPOL_MASK                    (0x80U)
#define RTU_PMC_P24_DPOL_SHIFT                   (7U)
#define RTU_PMC_P24_DPOL_WIDTH                   (1U)
#define RTU_PMC_P24_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P24_DPOL_SHIFT)) & RTU_PMC_P24_DPOL_MASK)

#define RTU_PMC_P24_UA_MASK                      (0x100U)
#define RTU_PMC_P24_UA_SHIFT                     (8U)
#define RTU_PMC_P24_UA_WIDTH                     (1U)
#define RTU_PMC_P24_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P24_UA_SHIFT)) & RTU_PMC_P24_UA_MASK)

#define RTU_PMC_P24_AO_MASK                      (0x200U)
#define RTU_PMC_P24_AO_SHIFT                     (9U)
#define RTU_PMC_P24_AO_WIDTH                     (1U)
#define RTU_PMC_P24_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P24_AO_SHIFT)) & RTU_PMC_P24_AO_MASK)
/*! @} */

/*! @name P25 - Program Register 25 */
/*! @{ */

#define RTU_PMC_P25_OP_MASK                      (0x3U)
#define RTU_PMC_P25_OP_SHIFT                     (0U)
#define RTU_PMC_P25_OP_WIDTH                     (2U)
#define RTU_PMC_P25_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P25_OP_SHIFT)) & RTU_PMC_P25_OP_MASK)

#define RTU_PMC_P25_TRANS_MASK                   (0x30U)
#define RTU_PMC_P25_TRANS_SHIFT                  (4U)
#define RTU_PMC_P25_TRANS_WIDTH                  (2U)
#define RTU_PMC_P25_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P25_TRANS_SHIFT)) & RTU_PMC_P25_TRANS_MASK)

#define RTU_PMC_P25_DREG_MASK                    (0x40U)
#define RTU_PMC_P25_DREG_SHIFT                   (6U)
#define RTU_PMC_P25_DREG_WIDTH                   (1U)
#define RTU_PMC_P25_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P25_DREG_SHIFT)) & RTU_PMC_P25_DREG_MASK)

#define RTU_PMC_P25_DPOL_MASK                    (0x80U)
#define RTU_PMC_P25_DPOL_SHIFT                   (7U)
#define RTU_PMC_P25_DPOL_WIDTH                   (1U)
#define RTU_PMC_P25_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P25_DPOL_SHIFT)) & RTU_PMC_P25_DPOL_MASK)

#define RTU_PMC_P25_UA_MASK                      (0x100U)
#define RTU_PMC_P25_UA_SHIFT                     (8U)
#define RTU_PMC_P25_UA_WIDTH                     (1U)
#define RTU_PMC_P25_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P25_UA_SHIFT)) & RTU_PMC_P25_UA_MASK)

#define RTU_PMC_P25_AO_MASK                      (0x200U)
#define RTU_PMC_P25_AO_SHIFT                     (9U)
#define RTU_PMC_P25_AO_WIDTH                     (1U)
#define RTU_PMC_P25_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P25_AO_SHIFT)) & RTU_PMC_P25_AO_MASK)
/*! @} */

/*! @name P26 - Program Register 26 */
/*! @{ */

#define RTU_PMC_P26_OP_MASK                      (0x3U)
#define RTU_PMC_P26_OP_SHIFT                     (0U)
#define RTU_PMC_P26_OP_WIDTH                     (2U)
#define RTU_PMC_P26_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P26_OP_SHIFT)) & RTU_PMC_P26_OP_MASK)

#define RTU_PMC_P26_TRANS_MASK                   (0x30U)
#define RTU_PMC_P26_TRANS_SHIFT                  (4U)
#define RTU_PMC_P26_TRANS_WIDTH                  (2U)
#define RTU_PMC_P26_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P26_TRANS_SHIFT)) & RTU_PMC_P26_TRANS_MASK)

#define RTU_PMC_P26_DREG_MASK                    (0x40U)
#define RTU_PMC_P26_DREG_SHIFT                   (6U)
#define RTU_PMC_P26_DREG_WIDTH                   (1U)
#define RTU_PMC_P26_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P26_DREG_SHIFT)) & RTU_PMC_P26_DREG_MASK)

#define RTU_PMC_P26_DPOL_MASK                    (0x80U)
#define RTU_PMC_P26_DPOL_SHIFT                   (7U)
#define RTU_PMC_P26_DPOL_WIDTH                   (1U)
#define RTU_PMC_P26_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P26_DPOL_SHIFT)) & RTU_PMC_P26_DPOL_MASK)

#define RTU_PMC_P26_UA_MASK                      (0x100U)
#define RTU_PMC_P26_UA_SHIFT                     (8U)
#define RTU_PMC_P26_UA_WIDTH                     (1U)
#define RTU_PMC_P26_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P26_UA_SHIFT)) & RTU_PMC_P26_UA_MASK)

#define RTU_PMC_P26_AO_MASK                      (0x200U)
#define RTU_PMC_P26_AO_SHIFT                     (9U)
#define RTU_PMC_P26_AO_WIDTH                     (1U)
#define RTU_PMC_P26_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P26_AO_SHIFT)) & RTU_PMC_P26_AO_MASK)
/*! @} */

/*! @name P27 - Program Register 27 */
/*! @{ */

#define RTU_PMC_P27_OP_MASK                      (0x3U)
#define RTU_PMC_P27_OP_SHIFT                     (0U)
#define RTU_PMC_P27_OP_WIDTH                     (2U)
#define RTU_PMC_P27_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P27_OP_SHIFT)) & RTU_PMC_P27_OP_MASK)

#define RTU_PMC_P27_TRANS_MASK                   (0x30U)
#define RTU_PMC_P27_TRANS_SHIFT                  (4U)
#define RTU_PMC_P27_TRANS_WIDTH                  (2U)
#define RTU_PMC_P27_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P27_TRANS_SHIFT)) & RTU_PMC_P27_TRANS_MASK)

#define RTU_PMC_P27_DREG_MASK                    (0x40U)
#define RTU_PMC_P27_DREG_SHIFT                   (6U)
#define RTU_PMC_P27_DREG_WIDTH                   (1U)
#define RTU_PMC_P27_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P27_DREG_SHIFT)) & RTU_PMC_P27_DREG_MASK)

#define RTU_PMC_P27_DPOL_MASK                    (0x80U)
#define RTU_PMC_P27_DPOL_SHIFT                   (7U)
#define RTU_PMC_P27_DPOL_WIDTH                   (1U)
#define RTU_PMC_P27_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P27_DPOL_SHIFT)) & RTU_PMC_P27_DPOL_MASK)

#define RTU_PMC_P27_UA_MASK                      (0x100U)
#define RTU_PMC_P27_UA_SHIFT                     (8U)
#define RTU_PMC_P27_UA_WIDTH                     (1U)
#define RTU_PMC_P27_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P27_UA_SHIFT)) & RTU_PMC_P27_UA_MASK)

#define RTU_PMC_P27_AO_MASK                      (0x200U)
#define RTU_PMC_P27_AO_SHIFT                     (9U)
#define RTU_PMC_P27_AO_WIDTH                     (1U)
#define RTU_PMC_P27_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P27_AO_SHIFT)) & RTU_PMC_P27_AO_MASK)
/*! @} */

/*! @name P28 - Program Register 28 */
/*! @{ */

#define RTU_PMC_P28_OP_MASK                      (0x3U)
#define RTU_PMC_P28_OP_SHIFT                     (0U)
#define RTU_PMC_P28_OP_WIDTH                     (2U)
#define RTU_PMC_P28_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P28_OP_SHIFT)) & RTU_PMC_P28_OP_MASK)

#define RTU_PMC_P28_TRANS_MASK                   (0x30U)
#define RTU_PMC_P28_TRANS_SHIFT                  (4U)
#define RTU_PMC_P28_TRANS_WIDTH                  (2U)
#define RTU_PMC_P28_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P28_TRANS_SHIFT)) & RTU_PMC_P28_TRANS_MASK)

#define RTU_PMC_P28_DREG_MASK                    (0x40U)
#define RTU_PMC_P28_DREG_SHIFT                   (6U)
#define RTU_PMC_P28_DREG_WIDTH                   (1U)
#define RTU_PMC_P28_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P28_DREG_SHIFT)) & RTU_PMC_P28_DREG_MASK)

#define RTU_PMC_P28_DPOL_MASK                    (0x80U)
#define RTU_PMC_P28_DPOL_SHIFT                   (7U)
#define RTU_PMC_P28_DPOL_WIDTH                   (1U)
#define RTU_PMC_P28_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P28_DPOL_SHIFT)) & RTU_PMC_P28_DPOL_MASK)

#define RTU_PMC_P28_UA_MASK                      (0x100U)
#define RTU_PMC_P28_UA_SHIFT                     (8U)
#define RTU_PMC_P28_UA_WIDTH                     (1U)
#define RTU_PMC_P28_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P28_UA_SHIFT)) & RTU_PMC_P28_UA_MASK)

#define RTU_PMC_P28_AO_MASK                      (0x200U)
#define RTU_PMC_P28_AO_SHIFT                     (9U)
#define RTU_PMC_P28_AO_WIDTH                     (1U)
#define RTU_PMC_P28_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P28_AO_SHIFT)) & RTU_PMC_P28_AO_MASK)
/*! @} */

/*! @name P29 - Program Register 29 */
/*! @{ */

#define RTU_PMC_P29_OP_MASK                      (0x3U)
#define RTU_PMC_P29_OP_SHIFT                     (0U)
#define RTU_PMC_P29_OP_WIDTH                     (2U)
#define RTU_PMC_P29_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P29_OP_SHIFT)) & RTU_PMC_P29_OP_MASK)

#define RTU_PMC_P29_TRANS_MASK                   (0x30U)
#define RTU_PMC_P29_TRANS_SHIFT                  (4U)
#define RTU_PMC_P29_TRANS_WIDTH                  (2U)
#define RTU_PMC_P29_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P29_TRANS_SHIFT)) & RTU_PMC_P29_TRANS_MASK)

#define RTU_PMC_P29_DREG_MASK                    (0x40U)
#define RTU_PMC_P29_DREG_SHIFT                   (6U)
#define RTU_PMC_P29_DREG_WIDTH                   (1U)
#define RTU_PMC_P29_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P29_DREG_SHIFT)) & RTU_PMC_P29_DREG_MASK)

#define RTU_PMC_P29_DPOL_MASK                    (0x80U)
#define RTU_PMC_P29_DPOL_SHIFT                   (7U)
#define RTU_PMC_P29_DPOL_WIDTH                   (1U)
#define RTU_PMC_P29_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P29_DPOL_SHIFT)) & RTU_PMC_P29_DPOL_MASK)

#define RTU_PMC_P29_UA_MASK                      (0x100U)
#define RTU_PMC_P29_UA_SHIFT                     (8U)
#define RTU_PMC_P29_UA_WIDTH                     (1U)
#define RTU_PMC_P29_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P29_UA_SHIFT)) & RTU_PMC_P29_UA_MASK)

#define RTU_PMC_P29_AO_MASK                      (0x200U)
#define RTU_PMC_P29_AO_SHIFT                     (9U)
#define RTU_PMC_P29_AO_WIDTH                     (1U)
#define RTU_PMC_P29_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P29_AO_SHIFT)) & RTU_PMC_P29_AO_MASK)
/*! @} */

/*! @name P30 - Program Register 30 */
/*! @{ */

#define RTU_PMC_P30_OP_MASK                      (0x3U)
#define RTU_PMC_P30_OP_SHIFT                     (0U)
#define RTU_PMC_P30_OP_WIDTH                     (2U)
#define RTU_PMC_P30_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P30_OP_SHIFT)) & RTU_PMC_P30_OP_MASK)

#define RTU_PMC_P30_TRANS_MASK                   (0x30U)
#define RTU_PMC_P30_TRANS_SHIFT                  (4U)
#define RTU_PMC_P30_TRANS_WIDTH                  (2U)
#define RTU_PMC_P30_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P30_TRANS_SHIFT)) & RTU_PMC_P30_TRANS_MASK)

#define RTU_PMC_P30_DREG_MASK                    (0x40U)
#define RTU_PMC_P30_DREG_SHIFT                   (6U)
#define RTU_PMC_P30_DREG_WIDTH                   (1U)
#define RTU_PMC_P30_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P30_DREG_SHIFT)) & RTU_PMC_P30_DREG_MASK)

#define RTU_PMC_P30_DPOL_MASK                    (0x80U)
#define RTU_PMC_P30_DPOL_SHIFT                   (7U)
#define RTU_PMC_P30_DPOL_WIDTH                   (1U)
#define RTU_PMC_P30_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P30_DPOL_SHIFT)) & RTU_PMC_P30_DPOL_MASK)

#define RTU_PMC_P30_UA_MASK                      (0x100U)
#define RTU_PMC_P30_UA_SHIFT                     (8U)
#define RTU_PMC_P30_UA_WIDTH                     (1U)
#define RTU_PMC_P30_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P30_UA_SHIFT)) & RTU_PMC_P30_UA_MASK)

#define RTU_PMC_P30_AO_MASK                      (0x200U)
#define RTU_PMC_P30_AO_SHIFT                     (9U)
#define RTU_PMC_P30_AO_WIDTH                     (1U)
#define RTU_PMC_P30_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P30_AO_SHIFT)) & RTU_PMC_P30_AO_MASK)
/*! @} */

/*! @name P31 - Program Register 31 */
/*! @{ */

#define RTU_PMC_P31_OP_MASK                      (0x3U)
#define RTU_PMC_P31_OP_SHIFT                     (0U)
#define RTU_PMC_P31_OP_WIDTH                     (2U)
#define RTU_PMC_P31_OP(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P31_OP_SHIFT)) & RTU_PMC_P31_OP_MASK)

#define RTU_PMC_P31_TRANS_MASK                   (0x30U)
#define RTU_PMC_P31_TRANS_SHIFT                  (4U)
#define RTU_PMC_P31_TRANS_WIDTH                  (2U)
#define RTU_PMC_P31_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P31_TRANS_SHIFT)) & RTU_PMC_P31_TRANS_MASK)

#define RTU_PMC_P31_DREG_MASK                    (0x40U)
#define RTU_PMC_P31_DREG_SHIFT                   (6U)
#define RTU_PMC_P31_DREG_WIDTH                   (1U)
#define RTU_PMC_P31_DREG(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P31_DREG_SHIFT)) & RTU_PMC_P31_DREG_MASK)

#define RTU_PMC_P31_DPOL_MASK                    (0x80U)
#define RTU_PMC_P31_DPOL_SHIFT                   (7U)
#define RTU_PMC_P31_DPOL_WIDTH                   (1U)
#define RTU_PMC_P31_DPOL(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P31_DPOL_SHIFT)) & RTU_PMC_P31_DPOL_MASK)

#define RTU_PMC_P31_UA_MASK                      (0x100U)
#define RTU_PMC_P31_UA_SHIFT                     (8U)
#define RTU_PMC_P31_UA_WIDTH                     (1U)
#define RTU_PMC_P31_UA(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P31_UA_SHIFT)) & RTU_PMC_P31_UA_MASK)

#define RTU_PMC_P31_AO_MASK                      (0x200U)
#define RTU_PMC_P31_AO_SHIFT                     (9U)
#define RTU_PMC_P31_AO_WIDTH                     (1U)
#define RTU_PMC_P31_AO(x)                        (((uint32_t)(((uint32_t)(x)) << RTU_PMC_P31_AO_SHIFT)) & RTU_PMC_P31_AO_MASK)
/*! @} */

/*! @name ITCTRL - Integration Mode Control Register */
/*! @{ */

#define RTU_PMC_ITCTRL_IME_MASK                  (0x1U)
#define RTU_PMC_ITCTRL_IME_SHIFT                 (0U)
#define RTU_PMC_ITCTRL_IME_WIDTH                 (1U)
#define RTU_PMC_ITCTRL_IME(x)                    (((uint32_t)(((uint32_t)(x)) << RTU_PMC_ITCTRL_IME_SHIFT)) & RTU_PMC_ITCTRL_IME_MASK)
/*! @} */

/*! @name CLAIMSET - Claim Tag Set Register */
/*! @{ */

#define RTU_PMC_CLAIMSET_SET_MASK                (0xFU)
#define RTU_PMC_CLAIMSET_SET_SHIFT               (0U)
#define RTU_PMC_CLAIMSET_SET_WIDTH               (4U)
#define RTU_PMC_CLAIMSET_SET(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CLAIMSET_SET_SHIFT)) & RTU_PMC_CLAIMSET_SET_MASK)
/*! @} */

/*! @name CLAIMCLR - Claim Tag Clear Register */
/*! @{ */

#define RTU_PMC_CLAIMCLR_CLR_MASK                (0xFU)
#define RTU_PMC_CLAIMCLR_CLR_SHIFT               (0U)
#define RTU_PMC_CLAIMCLR_CLR_WIDTH               (4U)
#define RTU_PMC_CLAIMCLR_CLR(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CLAIMCLR_CLR_SHIFT)) & RTU_PMC_CLAIMCLR_CLR_MASK)
/*! @} */

/*! @name DEVAFF0 - Device Affinity 0 Register */
/*! @{ */

#define RTU_PMC_DEVAFF0_Aff0_MASK                (0xFFU)
#define RTU_PMC_DEVAFF0_Aff0_SHIFT               (0U)
#define RTU_PMC_DEVAFF0_Aff0_WIDTH               (8U)
#define RTU_PMC_DEVAFF0_Aff0(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVAFF0_Aff0_SHIFT)) & RTU_PMC_DEVAFF0_Aff0_MASK)

#define RTU_PMC_DEVAFF0_Aff1_MASK                (0xFF00U)
#define RTU_PMC_DEVAFF0_Aff1_SHIFT               (8U)
#define RTU_PMC_DEVAFF0_Aff1_WIDTH               (8U)
#define RTU_PMC_DEVAFF0_Aff1(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVAFF0_Aff1_SHIFT)) & RTU_PMC_DEVAFF0_Aff1_MASK)

#define RTU_PMC_DEVAFF0_Aff2_MASK                (0xFF0000U)
#define RTU_PMC_DEVAFF0_Aff2_SHIFT               (16U)
#define RTU_PMC_DEVAFF0_Aff2_WIDTH               (8U)
#define RTU_PMC_DEVAFF0_Aff2(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVAFF0_Aff2_SHIFT)) & RTU_PMC_DEVAFF0_Aff2_MASK)

#define RTU_PMC_DEVAFF0_MT_MASK                  (0x1000000U)
#define RTU_PMC_DEVAFF0_MT_SHIFT                 (24U)
#define RTU_PMC_DEVAFF0_MT_WIDTH                 (1U)
#define RTU_PMC_DEVAFF0_MT(x)                    (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVAFF0_MT_SHIFT)) & RTU_PMC_DEVAFF0_MT_MASK)

#define RTU_PMC_DEVAFF0_U_MASK                   (0x40000000U)
#define RTU_PMC_DEVAFF0_U_SHIFT                  (30U)
#define RTU_PMC_DEVAFF0_U_WIDTH                  (1U)
#define RTU_PMC_DEVAFF0_U(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVAFF0_U_SHIFT)) & RTU_PMC_DEVAFF0_U_MASK)

#define RTU_PMC_DEVAFF0_M_MASK                   (0x80000000U)
#define RTU_PMC_DEVAFF0_M_SHIFT                  (31U)
#define RTU_PMC_DEVAFF0_M_WIDTH                  (1U)
#define RTU_PMC_DEVAFF0_M(x)                     (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVAFF0_M_SHIFT)) & RTU_PMC_DEVAFF0_M_MASK)
/*! @} */

/*! @name DEVAFF1 - Device Affinity 1 Register */
/*! @{ */

#define RTU_PMC_DEVAFF1_DEVAFF1_MASK             (0xFFFFFFFFU)
#define RTU_PMC_DEVAFF1_DEVAFF1_SHIFT            (0U)
#define RTU_PMC_DEVAFF1_DEVAFF1_WIDTH            (32U)
#define RTU_PMC_DEVAFF1_DEVAFF1(x)               (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVAFF1_DEVAFF1_SHIFT)) & RTU_PMC_DEVAFF1_DEVAFF1_MASK)
/*! @} */

/*! @name DEVARCH - Device Architecture Register */
/*! @{ */

#define RTU_PMC_DEVARCH_ARCHID_MASK              (0xFFFFU)
#define RTU_PMC_DEVARCH_ARCHID_SHIFT             (0U)
#define RTU_PMC_DEVARCH_ARCHID_WIDTH             (16U)
#define RTU_PMC_DEVARCH_ARCHID(x)                (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVARCH_ARCHID_SHIFT)) & RTU_PMC_DEVARCH_ARCHID_MASK)

#define RTU_PMC_DEVARCH_REVISION_MASK            (0xF0000U)
#define RTU_PMC_DEVARCH_REVISION_SHIFT           (16U)
#define RTU_PMC_DEVARCH_REVISION_WIDTH           (4U)
#define RTU_PMC_DEVARCH_REVISION(x)              (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVARCH_REVISION_SHIFT)) & RTU_PMC_DEVARCH_REVISION_MASK)

#define RTU_PMC_DEVARCH_PRESENT_MASK             (0x100000U)
#define RTU_PMC_DEVARCH_PRESENT_SHIFT            (20U)
#define RTU_PMC_DEVARCH_PRESENT_WIDTH            (1U)
#define RTU_PMC_DEVARCH_PRESENT(x)               (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVARCH_PRESENT_SHIFT)) & RTU_PMC_DEVARCH_PRESENT_MASK)

#define RTU_PMC_DEVARCH_ARCHITECT_MASK           (0xFFE00000U)
#define RTU_PMC_DEVARCH_ARCHITECT_SHIFT          (21U)
#define RTU_PMC_DEVARCH_ARCHITECT_WIDTH          (11U)
#define RTU_PMC_DEVARCH_ARCHITECT(x)             (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVARCH_ARCHITECT_SHIFT)) & RTU_PMC_DEVARCH_ARCHITECT_MASK)
/*! @} */

/*! @name DEVTYPE - Device Type Identifier Register */
/*! @{ */

#define RTU_PMC_DEVTYPE_MAJOR_MASK               (0xFU)
#define RTU_PMC_DEVTYPE_MAJOR_SHIFT              (0U)
#define RTU_PMC_DEVTYPE_MAJOR_WIDTH              (4U)
#define RTU_PMC_DEVTYPE_MAJOR(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVTYPE_MAJOR_SHIFT)) & RTU_PMC_DEVTYPE_MAJOR_MASK)

#define RTU_PMC_DEVTYPE_SUB_MASK                 (0xF0U)
#define RTU_PMC_DEVTYPE_SUB_SHIFT                (4U)
#define RTU_PMC_DEVTYPE_SUB_WIDTH                (4U)
#define RTU_PMC_DEVTYPE_SUB(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_PMC_DEVTYPE_SUB_SHIFT)) & RTU_PMC_DEVTYPE_SUB_MASK)
/*! @} */

/*! @name PIDR4 - Peripheral Identification Register 4 */
/*! @{ */

#define RTU_PMC_PIDR4_DES_2_MASK                 (0xFU)
#define RTU_PMC_PIDR4_DES_2_SHIFT                (0U)
#define RTU_PMC_PIDR4_DES_2_WIDTH                (4U)
#define RTU_PMC_PIDR4_DES_2(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_PMC_PIDR4_DES_2_SHIFT)) & RTU_PMC_PIDR4_DES_2_MASK)

#define RTU_PMC_PIDR4_SIZE_MASK                  (0xF0U)
#define RTU_PMC_PIDR4_SIZE_SHIFT                 (4U)
#define RTU_PMC_PIDR4_SIZE_WIDTH                 (4U)
#define RTU_PMC_PIDR4_SIZE(x)                    (((uint32_t)(((uint32_t)(x)) << RTU_PMC_PIDR4_SIZE_SHIFT)) & RTU_PMC_PIDR4_SIZE_MASK)
/*! @} */

/*! @name PIDR0 - Peripheral Identification Register 0 */
/*! @{ */

#define RTU_PMC_PIDR0_PART_0_MASK                (0xFFU)
#define RTU_PMC_PIDR0_PART_0_SHIFT               (0U)
#define RTU_PMC_PIDR0_PART_0_WIDTH               (8U)
#define RTU_PMC_PIDR0_PART_0(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_PMC_PIDR0_PART_0_SHIFT)) & RTU_PMC_PIDR0_PART_0_MASK)
/*! @} */

/*! @name PIDR1 - Peripheral Identification Register 1 */
/*! @{ */

#define RTU_PMC_PIDR1_PART_1_MASK                (0xFU)
#define RTU_PMC_PIDR1_PART_1_SHIFT               (0U)
#define RTU_PMC_PIDR1_PART_1_WIDTH               (4U)
#define RTU_PMC_PIDR1_PART_1(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_PMC_PIDR1_PART_1_SHIFT)) & RTU_PMC_PIDR1_PART_1_MASK)

#define RTU_PMC_PIDR1_DES_0_MASK                 (0xF0U)
#define RTU_PMC_PIDR1_DES_0_SHIFT                (4U)
#define RTU_PMC_PIDR1_DES_0_WIDTH                (4U)
#define RTU_PMC_PIDR1_DES_0(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_PMC_PIDR1_DES_0_SHIFT)) & RTU_PMC_PIDR1_DES_0_MASK)
/*! @} */

/*! @name PIDR2 - Peripheral Identification Register 2 */
/*! @{ */

#define RTU_PMC_PIDR2_DES_1_MASK                 (0x7U)
#define RTU_PMC_PIDR2_DES_1_SHIFT                (0U)
#define RTU_PMC_PIDR2_DES_1_WIDTH                (3U)
#define RTU_PMC_PIDR2_DES_1(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_PMC_PIDR2_DES_1_SHIFT)) & RTU_PMC_PIDR2_DES_1_MASK)

#define RTU_PMC_PIDR2_JEDEC_MASK                 (0x8U)
#define RTU_PMC_PIDR2_JEDEC_SHIFT                (3U)
#define RTU_PMC_PIDR2_JEDEC_WIDTH                (1U)
#define RTU_PMC_PIDR2_JEDEC(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_PMC_PIDR2_JEDEC_SHIFT)) & RTU_PMC_PIDR2_JEDEC_MASK)

#define RTU_PMC_PIDR2_REVISION_MASK              (0xF0U)
#define RTU_PMC_PIDR2_REVISION_SHIFT             (4U)
#define RTU_PMC_PIDR2_REVISION_WIDTH             (4U)
#define RTU_PMC_PIDR2_REVISION(x)                (((uint32_t)(((uint32_t)(x)) << RTU_PMC_PIDR2_REVISION_SHIFT)) & RTU_PMC_PIDR2_REVISION_MASK)
/*! @} */

/*! @name PIDR3 - Peripheral Identification Register 3 */
/*! @{ */

#define RTU_PMC_PIDR3_CMOD_MASK                  (0xFU)
#define RTU_PMC_PIDR3_CMOD_SHIFT                 (0U)
#define RTU_PMC_PIDR3_CMOD_WIDTH                 (4U)
#define RTU_PMC_PIDR3_CMOD(x)                    (((uint32_t)(((uint32_t)(x)) << RTU_PMC_PIDR3_CMOD_SHIFT)) & RTU_PMC_PIDR3_CMOD_MASK)

#define RTU_PMC_PIDR3_REVAND_MASK                (0xF0U)
#define RTU_PMC_PIDR3_REVAND_SHIFT               (4U)
#define RTU_PMC_PIDR3_REVAND_WIDTH               (4U)
#define RTU_PMC_PIDR3_REVAND(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_PMC_PIDR3_REVAND_SHIFT)) & RTU_PMC_PIDR3_REVAND_MASK)
/*! @} */

/*! @name CIDR0 - Component Identification Register 0 */
/*! @{ */

#define RTU_PMC_CIDR0_PRMBL_0_MASK               (0xFFU)
#define RTU_PMC_CIDR0_PRMBL_0_SHIFT              (0U)
#define RTU_PMC_CIDR0_PRMBL_0_WIDTH              (8U)
#define RTU_PMC_CIDR0_PRMBL_0(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CIDR0_PRMBL_0_SHIFT)) & RTU_PMC_CIDR0_PRMBL_0_MASK)
/*! @} */

/*! @name CIDR1 - Component Identification Register 1 */
/*! @{ */

#define RTU_PMC_CIDR1_PRMBL_1_MASK               (0xFU)
#define RTU_PMC_CIDR1_PRMBL_1_SHIFT              (0U)
#define RTU_PMC_CIDR1_PRMBL_1_WIDTH              (4U)
#define RTU_PMC_CIDR1_PRMBL_1(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CIDR1_PRMBL_1_SHIFT)) & RTU_PMC_CIDR1_PRMBL_1_MASK)

#define RTU_PMC_CIDR1_CLASS_MASK                 (0xF0U)
#define RTU_PMC_CIDR1_CLASS_SHIFT                (4U)
#define RTU_PMC_CIDR1_CLASS_WIDTH                (4U)
#define RTU_PMC_CIDR1_CLASS(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CIDR1_CLASS_SHIFT)) & RTU_PMC_CIDR1_CLASS_MASK)
/*! @} */

/*! @name CIDR2 - Component Identification Register 2 */
/*! @{ */

#define RTU_PMC_CIDR2_PRMBL_2_MASK               (0xFFU)
#define RTU_PMC_CIDR2_PRMBL_2_SHIFT              (0U)
#define RTU_PMC_CIDR2_PRMBL_2_WIDTH              (8U)
#define RTU_PMC_CIDR2_PRMBL_2(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CIDR2_PRMBL_2_SHIFT)) & RTU_PMC_CIDR2_PRMBL_2_MASK)
/*! @} */

/*! @name CIDR3 - Component Identification Register 3 */
/*! @{ */

#define RTU_PMC_CIDR3_PRMBL_3_MASK               (0xFFU)
#define RTU_PMC_CIDR3_PRMBL_3_SHIFT              (0U)
#define RTU_PMC_CIDR3_PRMBL_3_WIDTH              (8U)
#define RTU_PMC_CIDR3_PRMBL_3(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_PMC_CIDR3_PRMBL_3_SHIFT)) & RTU_PMC_CIDR3_PRMBL_3_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group RTU_PMC_Register_Masks */

/*!
 * @}
 */ /* end of group RTU_PMC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_RTU_PMC_H_) */
