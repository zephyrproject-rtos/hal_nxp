/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_ENETC_VSI.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_ENETC_VSI
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
#if !defined(S32K566_ENETC_VSI_H_)  /* Check if memory map has not been already included */
#define S32K566_ENETC_VSI_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ENETC_VSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_VSI_Peripheral_Access_Layer ENETC_VSI Peripheral Access Layer
 * @{
 */

/** ENETC_VSI - Size of Registers Arrays */
#define ENETC_VSI_SI_BOOT_LOAD_COUNT              2u
#define ENETC_VSI_TX_MSI_COUNT                    14u
#define ENETC_VSI_RX_GRP_COUNT                    14u
#define ENETC_VSI_BDR_NUM_COUNT                   14u

/** ENETC_VSI - Register Layout Typedef */
typedef struct ENETC_VSI_Struct {
  __IO uint32_t SIMR;                              /**< Station interface mode register, offset: 0x0 */
  __I  uint32_t SISR;                              /**< Station interface status register, offset: 0x4 */
  uint8_t RESERVED_0[16];
  __I  uint32_t SICTR0;                            /**< Station interface current time register 0, offset: 0x18 */
  __I  uint32_t SICTR1;                            /**< Station interface current time register 1, offset: 0x1C */
  __I  uint32_t SIPCAPR0;                          /**< Station interface port capability register 0, offset: 0x20 */
  __I  uint32_t SIPCAPR1;                          /**< Station interface port capability register 1, offset: 0x24 */
  uint8_t RESERVED_1[8];
  __I  uint32_t SITSR;                             /**< Station interface timer status register, offset: 0x30 */
  uint8_t RESERVED_2[4];
  __IO uint32_t SIRBGCR;                           /**< Station interface receive BDR group control register, offset: 0x38 */
  uint8_t RESERVED_3[4];
  __IO uint32_t SIBCAR;                            /**< Station interface buffer cache attribute register, offset: 0x40 */
  uint8_t RESERVED_4[4];
  __IO uint32_t SICCAR;                            /**< Station interface command cache attribute register, offset: 0x48 */
  uint8_t RESERVED_5[52];
  __I  uint32_t SIPMAR0;                           /**< Station interface primary MAC address register 0, offset: 0x80 */
  __I  uint32_t SIPMAR1;                           /**< Station interface primary MAC address register 1, offset: 0x84 */
  uint8_t RESERVED_6[8];
  __I  uint32_t SICVLANR1;                         /**< Station interface custom VLAN register 1, offset: 0x90 */
  __I  uint32_t SICVLANR2;                         /**< Station interface custom VLAN register 2, offset: 0x94 */
  uint8_t RESERVED_7[104];
  __IO uint32_t SIVLANIPVMR0;                      /**< Station interface VLAN to IPV mapping register 0, offset: 0x100 */
  __IO uint32_t SIVLANIPVMR1;                      /**< Station interface VLAN to IPV mapping register 1, offset: 0x104 */
  uint8_t RESERVED_8[72];
  __IO uint32_t SIIPVBDRMR0;                       /**< Station interface IPV to ring mapping register, offset: 0x150 */
  uint8_t RESERVED_9[176];
  union {                                          /* offset: 0x204 */
    struct ENETC_VSI_MSGSR_VSI_A {                   /* offset: 0x204 */
      __I  uint32_t VSIMSGSR;                          /**< Virtual station interface message send register, offset: 0x204 */
      __I  uint32_t VSIMSGRR;                          /**< Virtual station interface message receive register, offset: 0x208 */
      uint8_t RESERVED_0[4];
      __IO uint32_t VSIMSGSNDAR0;                      /**< Virtual station interface message address send register 0, offset: 0x210 */
      __IO uint32_t VSIMSGSNDAR1;                      /**< Virtual station interface message send address register 1, offset: 0x214 */
    } VSI_A;
  } MSGSR;
  uint8_t RESERVED_10[232];
  __I  uint32_t SIROCT0;                           /**< Station interface receive octets counter (ifInOctets) 0, offset: 0x300 */
  __I  uint32_t SIROCT1;                           /**< Station interface receive octets counter (ifInOctets) 1, offset: 0x304 */
  __I  uint32_t SIRFRM0;                           /**< Station interface receive frame counter (aFrameReceivedOK) 0, offset: 0x308 */
  __I  uint32_t SIRFRM1;                           /**< Station interface receive frame counter (aFrameReceivedOK) 1, offset: 0x30C */
  __I  uint32_t SIRUCA0;                           /**< Station interface receive unicast frame counter (ifInUcastPkts) 0, offset: 0x310 */
  __I  uint32_t SIRUCA1;                           /**< Station interface receive unicast frame counter (ifInUcastPkts) 1, offset: 0x314 */
  __I  uint32_t SIRMCA0;                           /**< Station interface receive multicast frame counter (ifInMulticastPkts) 0, offset: 0x318 */
  __I  uint32_t SIRMCA1;                           /**< Station interface receive multicast frame counter (ifInMulticastPkts) 1, offset: 0x31C */
  __I  uint32_t SITOCT0;                           /**< Station interface transmit octets counter (ifOutOctets) 0, offset: 0x320 */
  __I  uint32_t SITOCT1;                           /**< Station interface transmit octets counter (ifOutOctets) 1, offset: 0x324 */
  __I  uint32_t SITFRM0;                           /**< Station interface transmit frame counter (aFrameTransmittedOK) 0, offset: 0x328 */
  __I  uint32_t SITFRM1;                           /**< Station interface transmit frame counter (aFrameTransmittedOK) 1, offset: 0x32C */
  __I  uint32_t SITUCA0;                           /**< Station interface transmit unicast frame counter (ifOutUcastPkts) 0, offset: 0x330 */
  __I  uint32_t SITUCA1;                           /**< Station interface transmit unicast frame counter (ifOutUcastPkts) 1, offset: 0x334 */
  __I  uint32_t SITMCA0;                           /**< Station interface transmit multicast frame counter (ifOutMulticastPkts) 0, offset: 0x338 */
  __I  uint32_t SITMCA1;                           /**< Station interface transmit multicast frame counter (ifOutMulticastPkts) 1, offset: 0x33C */
  __I  uint32_t SITDFCR;                           /**< Station interface transmit discard frame counter, offset: 0x340 */
  uint8_t RESERVED_11[172];
  __I  uint32_t SIBLPR[ENETC_VSI_SI_BOOT_LOAD_COUNT]; /**< Station interface boot loader parameter register 0..Station interface boot loader parameter register 1, array offset: 0x3F0, array step: 0x4 */
  uint8_t RESERVED_12[1032];
  __IO uint32_t SICBDRMR;                          /**< Station interface command BDR mode register, offset: 0x800 */
  __I  uint32_t SICBDRSR;                          /**< Station interface command BDR status register, offset: 0x804 */
  uint8_t RESERVED_13[8];
  __IO uint32_t SICBDRBAR0;                        /**< Station interface command BDR base address register 0, offset: 0x810 */
  __IO uint32_t SICBDRBAR1;                        /**< Station interface command BDR base address register 1, offset: 0x814 */
  __IO uint32_t SICBDRPIR;                         /**< Station interface command BDR producer index register, offset: 0x818 */
  __IO uint32_t SICBDRCIR;                         /**< Station interface command BDR consumer index register, offset: 0x81C */
  __IO uint32_t SICBDRLENR;                        /**< Station interface command BDR length register, offset: 0x820 */
  uint8_t RESERVED_14[124];
  __IO uint32_t SICBDRIER;                         /**< Station interface command BDR interrupt enable register, offset: 0x8A0 */
  __IO uint32_t SICBDRIDR;                         /**< Station interface command BDR interrupt detect register, offset: 0x8A4 */
  uint8_t RESERVED_15[88];
  __I  uint32_t SICAPR0;                           /**< Station interface capability register 0, offset: 0x900 */
  __I  uint32_t SICAPR1;                           /**< Station interface capability register 1, offset: 0x904 */
  __I  uint32_t SICAPR2;                           /**< Station interface capability register 2, offset: 0x908 */
  uint8_t RESERVED_16[244];
  union {                                          /* offset: 0xA00 */
    struct ENETC_VSI_INTERRUPT_VSI {                 /* offset: 0xA00 */
      __IO uint32_t VSIIER;                            /**< Virtual station interface interrupt enable register, offset: 0xA00 */
      uint8_t RESERVED_0[4];
      __IO uint32_t VSIIDR;                            /**< Virtual station interface interrupt detect register, offset: 0xA08 */
    } VSI;
  } INTERRUPT;
  uint8_t RESERVED_17[12];
  __IO uint32_t SITXIDR0;                          /**< Station interface transmit interrupt detect register 0, offset: 0xA18 */
  uint8_t RESERVED_18[12];
  __IO uint32_t SIRXIDR0;                          /**< Station interface receive interrupt detect register 0, offset: 0xA28 */
  uint8_t RESERVED_19[4];
  __IO uint32_t SIMSIVR;                           /**< Station interface MSI-X vector register, offset: 0xA30 */
  __IO uint32_t SICMSIVR;                          /**< Station interface command MSI-X vector register, offset: 0xA34 */
  uint8_t RESERVED_20[8];
  __IO uint32_t SITMRIER;                          /**< Station interface timer interrupt enable register, offset: 0xA40 */
  __IO uint32_t SITMRIDR;                          /**< Station interface timer interrupt detect register, offset: 0xA44 */
  uint8_t RESERVED_21[4];
  __IO uint32_t SITMRMSIVR;                        /**< Station interface timer MSI-X vector register, offset: 0xA4C */
  uint8_t RESERVED_22[176];
  __IO uint32_t SIMSITRVR[ENETC_VSI_TX_MSI_COUNT]; /**< Station interface MSI-X transmit ring 0 vector register..Station interface MSI-X transmit ring 13 vector register, array offset: 0xB00, array step: 0x4 */
  uint8_t RESERVED_23[72];
  __IO uint32_t SIMSIRRVR[ENETC_VSI_RX_GRP_COUNT]; /**< Station interface MSI-X receive ring 0 vector register..Station interface MSI-X receive ring 13 vector register, array offset: 0xB80, array step: 0x4 */
  uint8_t RESERVED_24[584];
  __IO uint32_t SICMECR;                           /**< Station interface correctable memory error configuration register, offset: 0xE00 */
  __IO uint32_t SICMESR;                           /**< Station interface correctable memory error status register, offset: 0xE04 */
  uint8_t RESERVED_25[4];
  __I  uint32_t SICMECTR;                          /**< Station interface correctable memory error count register, offset: 0xE0C */
  __IO uint32_t SIUPECR;                           /**< Station interface uncorrectable programming error configuration register, offset: 0xE10 */
  __IO uint32_t SIUPESR;                           /**< Station interface uncorrectable programming error status register, offset: 0xE14 */
  uint8_t RESERVED_26[4];
  __I  uint32_t SIUPECTR;                          /**< Station interface uncorrectable programming error count register, offset: 0xE1C */
  __IO uint32_t SIUNSBECR;                         /**< Station interface uncorrectable non-fatal system bus error configuration register, offset: 0xE20 */
  __IO uint32_t SIUNSBESR;                         /**< Station interface uncorrectable non-fatal system bus error status register, offset: 0xE24 */
  uint8_t RESERVED_27[4];
  __I  uint32_t SIUNSBECTR;                        /**< Station interface uncorrectable non-fatal system bus error count register, offset: 0xE2C */
  __IO uint32_t SIUFSBECR;                         /**< Station interface uncorrectable fatal system bus error configuration register, offset: 0xE30 */
  __IO uint32_t SIUFSBESR;                         /**< Station interface uncorrectable fatal system bus error status register, offset: 0xE34 */
  uint8_t RESERVED_28[8];
  __IO uint32_t SIUNMECR;                          /**< Station interface uncorrectable non-fatal memory error configuration register, offset: 0xE40 */
  __IO uint32_t SIUNMESR0;                         /**< Station interface uncorrectable non-fatal memory error status register 0, offset: 0xE44 */
  __I  uint32_t SIUNMESR1;                         /**< Station interface uncorrectable non-fatal memory error status register 1, offset: 0xE48 */
  __I  uint32_t SIUNMECTR;                         /**< Station interface uncorrectable non-fatal memory error count register, offset: 0xE4C */
  __IO uint32_t SIUFMECR;                          /**< Station interface uncorrectable fatal memory error configuration register, offset: 0xE50 */
  __IO uint32_t SIUFMESR0;                         /**< Station interface uncorrectable fatal memory error status register 0, offset: 0xE54 */
  __I  uint32_t SIUFMESR1;                         /**< Station interface uncorrectable fatal memory error status register 1, offset: 0xE58 */
  uint8_t RESERVED_29[4];
  __IO uint32_t SIUNIECR;                          /**< Station interface uncorrectable non-fatal integrity error configuration register, offset: 0xE60 */
  __IO uint32_t SIUNIESR;                          /**< Station interface uncorrectable non-fatal integrity error status register, offset: 0xE64 */
  uint8_t RESERVED_30[4];
  __I  uint32_t SIUNIECTR;                         /**< Station interface uncorrectable non-fatal integrity error count register, offset: 0xE6C */
  __IO uint32_t SIUFIECR;                          /**< Station interface uncorrectable fatal integrity error configuration register, offset: 0xE70 */
  __IO uint32_t SIUFIESR;                          /**< Station interface uncorrectable fatal integrity error status register, offset: 0xE74 */
  uint8_t RESERVED_31[392];
  __I  uint32_t SIMAFTCAPR;                        /**< Station interface MAC address filter table capability register, offset: 0x1000 */
  uint8_t RESERVED_32[252];
  __I  uint32_t SIVFTCAPR;                         /**< Station interface VLAN filter table capability register, offset: 0x1100 */
  uint8_t RESERVED_33[252];
  __I  uint32_t SIRFSCAPR;                         /**< Station interface RFS capability register, offset: 0x1200 */
  uint8_t RESERVED_34[28156];
  struct ENETC_VSI_BDR_NUM {                       /* offset: 0x8000, array step: 0x200 */
    __IO uint32_t TBMR;                              /**< Tx BDR 0 mode register..Tx BDR 13 mode register, array offset: 0x8000, array step: 0x200 */
    __IO uint32_t TBSR;                              /**< Tx BDR 0 status register..Tx BDR 13 status register, array offset: 0x8004, array step: 0x200 */
    uint8_t RESERVED_0[8];
    __IO uint32_t TBBAR0;                            /**< Tx BDR 0 base address register 0..Tx BDR 13 base address register 0, array offset: 0x8010, array step: 0x200 */
    __IO uint32_t TBBAR1;                            /**< Tx BDR 0 base address register 1..Tx BDR 13 base address register 1, array offset: 0x8014, array step: 0x200 */
    __IO uint32_t TBPIR;                             /**< Tx BDR 0 producer index register..Tx BDR 13 producer index register, array offset: 0x8018, array step: 0x200 */
    __IO uint32_t TBCIR;                             /**< Tx BDR 0 consumer index register..Tx BDR 13 consumer index register, array offset: 0x801C, array step: 0x200 */
    __IO uint32_t TBLENR;                            /**< Tx BDR 0 length register..Tx BDR 13 length register, array offset: 0x8020, array step: 0x200 */
    uint8_t RESERVED_1[124];
    __IO uint32_t TBIER;                             /**< Tx BDR 0 interrupt enable register..Tx BDR 13 interrupt enable register, array offset: 0x80A0, array step: 0x200 */
    __I  uint32_t TBIDR;                             /**< Tx BDR 0 interrupt detect register..Tx BDR 13 interrupt detect register, array offset: 0x80A4, array step: 0x200 */
    __IO uint32_t TBICR0;                            /**< Tx BDR 0 interrupt coalescing register 0..Tx BDR 13 interrupt coalescing register 0, array offset: 0x80A8, array step: 0x200 */
    __IO uint32_t TBICR1;                            /**< Tx BDR 0 interrupt coalescing register 1..Tx BDR 13 interrupt coalescing register 1, array offset: 0x80AC, array step: 0x200 */
    uint8_t RESERVED_2[80];
    __IO uint32_t RBMR;                              /**< Rx BDR 0 mode register..Rx BDR 13 mode register, array offset: 0x8100, array step: 0x200 */
    __IO uint32_t RBSR;                              /**< Rx BDR 0 status register..Rx BDR 13 status register, array offset: 0x8104, array step: 0x200 */
    __IO uint32_t RBBSR;                             /**< Rx BDR 0 buffer size register..Rx BDR 13 buffer size register, array offset: 0x8108, array step: 0x200 */
    __IO uint32_t RBCIR;                             /**< Rx BDR 0 consumer index register..Rx BDR 13 consumer index register, array offset: 0x810C, array step: 0x200 */
    __IO uint32_t RBBAR0;                            /**< Rx BDR 0 base address register 0..Rx BDR 13 base address register 0, array offset: 0x8110, array step: 0x200 */
    __IO uint32_t RBBAR1;                            /**< Rx BDR 0 base address register 1..Rx BDR 13 base address register 1, array offset: 0x8114, array step: 0x200 */
    __IO uint32_t RBPIR;                             /**< Rx BDR 0 producer index register..Rx BDR 13 producer index register, array offset: 0x8118, array step: 0x200 */
    uint8_t RESERVED_3[4];
    __IO uint32_t RBLENR;                            /**< Rx BDR 0 length register..Rx BDR 13 length register, array offset: 0x8120, array step: 0x200 */
    uint8_t RESERVED_4[92];
    __I  uint32_t RBDCR;                             /**< Rx BDR 0 drop count register..Rx BDR 13 drop count register, array offset: 0x8180, array step: 0x200 */
    uint8_t RESERVED_5[28];
    __IO uint32_t RBIER;                             /**< Rx BDR 0 interrupt enable register..Rx BDR 13 interrupt enable register, array offset: 0x81A0, array step: 0x200 */
    __I  uint32_t RBIDR;                             /**< Rx BDR 0 interrupt detect register..Rx BDR 13 interrupt detect register, array offset: 0x81A4, array step: 0x200 */
    __IO uint32_t RBICR0;                            /**< Rx BDR 0 interrupt coalescing register 0..Rx BDR 13 interrupt coalescing register 0, array offset: 0x81A8, array step: 0x200 */
    __IO uint32_t RBICR1;                            /**< Rx BDR 0 interrupt coalescing register 1..Rx BDR 13 interrupt coalescing register 1, array offset: 0x81AC, array step: 0x200 */
    uint8_t RESERVED_6[80];
  } BDR_NUM[ENETC_VSI_BDR_NUM_COUNT];
} ENETC_VSI_Type, *ENETC_VSI_MemMapPtr;

/** Number of instances of the ENETC_VSI module. */
#define ENETC_VSI_INSTANCE_COUNT                 (5u)

/* ENETC_VSI - Peripheral instance base addresses */
/** Peripheral NETC__ENETC_VSI0 base address */
#define IP_NETC__ENETC_VSI0_BASE                 (0x6D160000u)
/** Peripheral NETC__ENETC_VSI0 base pointer */
#define IP_NETC__ENETC_VSI0                      ((ENETC_VSI_Type *)IP_NETC__ENETC_VSI0_BASE)
/** Peripheral NETC__ENETC_VSI1 base address */
#define IP_NETC__ENETC_VSI1_BASE                 (0x6D170000u)
/** Peripheral NETC__ENETC_VSI1 base pointer */
#define IP_NETC__ENETC_VSI1                      ((ENETC_VSI_Type *)IP_NETC__ENETC_VSI1_BASE)
/** Peripheral NETC__ENETC_VSI2 base address */
#define IP_NETC__ENETC_VSI2_BASE                 (0x6D180000u)
/** Peripheral NETC__ENETC_VSI2 base pointer */
#define IP_NETC__ENETC_VSI2                      ((ENETC_VSI_Type *)IP_NETC__ENETC_VSI2_BASE)
/** Peripheral NETC__ENETC_VSI3 base address */
#define IP_NETC__ENETC_VSI3_BASE                 (0x6D190000u)
/** Peripheral NETC__ENETC_VSI3 base pointer */
#define IP_NETC__ENETC_VSI3                      ((ENETC_VSI_Type *)IP_NETC__ENETC_VSI3_BASE)
/** Peripheral NETC__ENETC_VSI4 base address */
#define IP_NETC__ENETC_VSI4_BASE                 (0x6D1A0000u)
/** Peripheral NETC__ENETC_VSI4 base pointer */
#define IP_NETC__ENETC_VSI4                      ((ENETC_VSI_Type *)IP_NETC__ENETC_VSI4_BASE)
/** Array initializer of ENETC_VSI peripheral base addresses */
#define IP_ENETC_VSI_BASE_ADDRS                  { IP_NETC__ENETC_VSI0_BASE, IP_NETC__ENETC_VSI1_BASE, IP_NETC__ENETC_VSI2_BASE, IP_NETC__ENETC_VSI3_BASE, IP_NETC__ENETC_VSI4_BASE }
/** Array initializer of ENETC_VSI peripheral base pointers */
#define IP_ENETC_VSI_BASE_PTRS                   { IP_NETC__ENETC_VSI0, IP_NETC__ENETC_VSI1, IP_NETC__ENETC_VSI2, IP_NETC__ENETC_VSI3, IP_NETC__ENETC_VSI4 }

/* ----------------------------------------------------------------------------
   -- ENETC_VSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_VSI_Register_Masks ENETC_VSI Register Masks
 * @{
 */

/*! @name SIMR - Station interface mode register */
/*! @{ */

#define ENETC_VSI_SIMR_RSSE_MASK                 (0x1U)
#define ENETC_VSI_SIMR_RSSE_SHIFT                (0U)
#define ENETC_VSI_SIMR_RSSE_WIDTH                (1U)
#define ENETC_VSI_SIMR_RSSE(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMR_RSSE_SHIFT)) & ENETC_VSI_SIMR_RSSE_MASK)

#define ENETC_VSI_SIMR_RNUM_MASK                 (0x2U)
#define ENETC_VSI_SIMR_RNUM_SHIFT                (1U)
#define ENETC_VSI_SIMR_RNUM_WIDTH                (1U)
#define ENETC_VSI_SIMR_RNUM(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMR_RNUM_SHIFT)) & ENETC_VSI_SIMR_RNUM_MASK)

#define ENETC_VSI_SIMR_RNMM_MASK                 (0x4U)
#define ENETC_VSI_SIMR_RNMM_SHIFT                (2U)
#define ENETC_VSI_SIMR_RNMM_WIDTH                (1U)
#define ENETC_VSI_SIMR_RNMM(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMR_RNMM_SHIFT)) & ENETC_VSI_SIMR_RNMM_MASK)

#define ENETC_VSI_SIMR_RNBM_MASK                 (0x8U)
#define ENETC_VSI_SIMR_RNBM_SHIFT                (3U)
#define ENETC_VSI_SIMR_RNBM_WIDTH                (1U)
#define ENETC_VSI_SIMR_RNBM(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMR_RNBM_SHIFT)) & ENETC_VSI_SIMR_RNBM_MASK)

#define ENETC_VSI_SIMR_V2IPVE_MASK               (0x10U)
#define ENETC_VSI_SIMR_V2IPVE_SHIFT              (4U)
#define ENETC_VSI_SIMR_V2IPVE_WIDTH              (1U)
#define ENETC_VSI_SIMR_V2IPVE(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMR_V2IPVE_SHIFT)) & ENETC_VSI_SIMR_V2IPVE_MASK)

#define ENETC_VSI_SIMR_DEFAULT_RX_GROUP_MASK     (0x10000U)
#define ENETC_VSI_SIMR_DEFAULT_RX_GROUP_SHIFT    (16U)
#define ENETC_VSI_SIMR_DEFAULT_RX_GROUP_WIDTH    (1U)
#define ENETC_VSI_SIMR_DEFAULT_RX_GROUP(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMR_DEFAULT_RX_GROUP_SHIFT)) & ENETC_VSI_SIMR_DEFAULT_RX_GROUP_MASK)

#define ENETC_VSI_SIMR_EN_MASK                   (0x80000000U)
#define ENETC_VSI_SIMR_EN_SHIFT                  (31U)
#define ENETC_VSI_SIMR_EN_WIDTH                  (1U)
#define ENETC_VSI_SIMR_EN(x)                     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMR_EN_SHIFT)) & ENETC_VSI_SIMR_EN_MASK)
/*! @} */

/*! @name SISR - Station interface status register */
/*! @{ */

#define ENETC_VSI_SISR_TX_BUSY_MASK              (0x1U)
#define ENETC_VSI_SISR_TX_BUSY_SHIFT             (0U)
#define ENETC_VSI_SISR_TX_BUSY_WIDTH             (1U)
#define ENETC_VSI_SISR_TX_BUSY(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SISR_TX_BUSY_SHIFT)) & ENETC_VSI_SISR_TX_BUSY_MASK)

#define ENETC_VSI_SISR_MAC_UP_MASK               (0x2U)
#define ENETC_VSI_SISR_MAC_UP_SHIFT              (1U)
#define ENETC_VSI_SISR_MAC_UP_WIDTH              (1U)
#define ENETC_VSI_SISR_MAC_UP(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SISR_MAC_UP_SHIFT)) & ENETC_VSI_SISR_MAC_UP_MASK)

#define ENETC_VSI_SISR_MAC_MP_MASK               (0x4U)
#define ENETC_VSI_SISR_MAC_MP_SHIFT              (2U)
#define ENETC_VSI_SISR_MAC_MP_WIDTH              (1U)
#define ENETC_VSI_SISR_MAC_MP(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SISR_MAC_MP_SHIFT)) & ENETC_VSI_SISR_MAC_MP_MASK)

#define ENETC_VSI_SISR_VLAN_P_MASK               (0x8U)
#define ENETC_VSI_SISR_VLAN_P_SHIFT              (3U)
#define ENETC_VSI_SISR_VLAN_P_WIDTH              (1U)
#define ENETC_VSI_SISR_VLAN_P(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SISR_VLAN_P_SHIFT)) & ENETC_VSI_SISR_VLAN_P_MASK)

#define ENETC_VSI_SISR_VLAN_UTA_MASK             (0x10U)
#define ENETC_VSI_SISR_VLAN_UTA_SHIFT            (4U)
#define ENETC_VSI_SISR_VLAN_UTA_WIDTH            (1U)
#define ENETC_VSI_SISR_VLAN_UTA(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SISR_VLAN_UTA_SHIFT)) & ENETC_VSI_SISR_VLAN_UTA_MASK)
/*! @} */

/*! @name SICTR0 - Station interface current time register 0 */
/*! @{ */

#define ENETC_VSI_SICTR0_CURR_TIME_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SICTR0_CURR_TIME_SHIFT         (0U)
#define ENETC_VSI_SICTR0_CURR_TIME_WIDTH         (32U)
#define ENETC_VSI_SICTR0_CURR_TIME(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICTR0_CURR_TIME_SHIFT)) & ENETC_VSI_SICTR0_CURR_TIME_MASK)
/*! @} */

/*! @name SICTR1 - Station interface current time register 1 */
/*! @{ */

#define ENETC_VSI_SICTR1_CURR_TIME_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SICTR1_CURR_TIME_SHIFT         (0U)
#define ENETC_VSI_SICTR1_CURR_TIME_WIDTH         (32U)
#define ENETC_VSI_SICTR1_CURR_TIME(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICTR1_CURR_TIME_SHIFT)) & ENETC_VSI_SICTR1_CURR_TIME_MASK)
/*! @} */

/*! @name SIPCAPR0 - Station interface port capability register 0 */
/*! @{ */

#define ENETC_VSI_SIPCAPR0_RSC_MASK              (0x1U)
#define ENETC_VSI_SIPCAPR0_RSC_SHIFT             (0U)
#define ENETC_VSI_SIPCAPR0_RSC_WIDTH             (1U)
#define ENETC_VSI_SIPCAPR0_RSC(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_RSC_SHIFT)) & ENETC_VSI_SIPCAPR0_RSC_MASK)

#define ENETC_VSI_SIPCAPR0_LSO_MASK              (0x2U)
#define ENETC_VSI_SIPCAPR0_LSO_SHIFT             (1U)
#define ENETC_VSI_SIPCAPR0_LSO_WIDTH             (1U)
#define ENETC_VSI_SIPCAPR0_LSO(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_LSO_SHIFT)) & ENETC_VSI_SIPCAPR0_LSO_MASK)

#define ENETC_VSI_SIPCAPR0_RFS_MASK              (0x4U)
#define ENETC_VSI_SIPCAPR0_RFS_SHIFT             (2U)
#define ENETC_VSI_SIPCAPR0_RFS_WIDTH             (1U)
#define ENETC_VSI_SIPCAPR0_RFS(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_RFS_SHIFT)) & ENETC_VSI_SIPCAPR0_RFS_MASK)

#define ENETC_VSI_SIPCAPR0_FP_MASK               (0x8U)
#define ENETC_VSI_SIPCAPR0_FP_SHIFT              (3U)
#define ENETC_VSI_SIPCAPR0_FP_WIDTH              (1U)
#define ENETC_VSI_SIPCAPR0_FP(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_FP_SHIFT)) & ENETC_VSI_SIPCAPR0_FP_MASK)

#define ENETC_VSI_SIPCAPR0_TGS_MASK              (0x10U)
#define ENETC_VSI_SIPCAPR0_TGS_SHIFT             (4U)
#define ENETC_VSI_SIPCAPR0_TGS_WIDTH             (1U)
#define ENETC_VSI_SIPCAPR0_TGS(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_TGS_SHIFT)) & ENETC_VSI_SIPCAPR0_TGS_MASK)

#define ENETC_VSI_SIPCAPR0_TSD_MASK              (0x20U)
#define ENETC_VSI_SIPCAPR0_TSD_SHIFT             (5U)
#define ENETC_VSI_SIPCAPR0_TSD_WIDTH             (1U)
#define ENETC_VSI_SIPCAPR0_TSD(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_TSD_SHIFT)) & ENETC_VSI_SIPCAPR0_TSD_MASK)

#define ENETC_VSI_SIPCAPR0_CBS_MASK              (0x40U)
#define ENETC_VSI_SIPCAPR0_CBS_SHIFT             (6U)
#define ENETC_VSI_SIPCAPR0_CBS_WIDTH             (1U)
#define ENETC_VSI_SIPCAPR0_CBS(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_CBS_SHIFT)) & ENETC_VSI_SIPCAPR0_CBS_MASK)

#define ENETC_VSI_SIPCAPR0_RSS_MASK              (0x100U)
#define ENETC_VSI_SIPCAPR0_RSS_SHIFT             (8U)
#define ENETC_VSI_SIPCAPR0_RSS_WIDTH             (1U)
#define ENETC_VSI_SIPCAPR0_RSS(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_RSS_SHIFT)) & ENETC_VSI_SIPCAPR0_RSS_MASK)

#define ENETC_VSI_SIPCAPR0_PSFP_MASK             (0x200U)
#define ENETC_VSI_SIPCAPR0_PSFP_SHIFT            (9U)
#define ENETC_VSI_SIPCAPR0_PSFP_WIDTH            (1U)
#define ENETC_VSI_SIPCAPR0_PSFP(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_PSFP_SHIFT)) & ENETC_VSI_SIPCAPR0_PSFP_MASK)

#define ENETC_VSI_SIPCAPR0_IPFLT_MASK            (0x400U)
#define ENETC_VSI_SIPCAPR0_IPFLT_SHIFT           (10U)
#define ENETC_VSI_SIPCAPR0_IPFLT_WIDTH           (1U)
#define ENETC_VSI_SIPCAPR0_IPFLT(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_IPFLT_SHIFT)) & ENETC_VSI_SIPCAPR0_IPFLT_MASK)

#define ENETC_VSI_SIPCAPR0_RP_MASK               (0x800U)
#define ENETC_VSI_SIPCAPR0_RP_SHIFT              (11U)
#define ENETC_VSI_SIPCAPR0_RP_WIDTH              (1U)
#define ENETC_VSI_SIPCAPR0_RP(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_RP_SHIFT)) & ENETC_VSI_SIPCAPR0_RP_MASK)

#define ENETC_VSI_SIPCAPR0_FS_MASK               (0x10000U)
#define ENETC_VSI_SIPCAPR0_FS_SHIFT              (16U)
#define ENETC_VSI_SIPCAPR0_FS_WIDTH              (1U)
#define ENETC_VSI_SIPCAPR0_FS(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR0_FS_SHIFT)) & ENETC_VSI_SIPCAPR0_FS_MASK)
/*! @} */

/*! @name SIPCAPR1 - Station interface port capability register 1 */
/*! @{ */

#define ENETC_VSI_SIPCAPR1_NUM_TCS_MASK          (0x70U)
#define ENETC_VSI_SIPCAPR1_NUM_TCS_SHIFT         (4U)
#define ENETC_VSI_SIPCAPR1_NUM_TCS_WIDTH         (3U)
#define ENETC_VSI_SIPCAPR1_NUM_TCS(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR1_NUM_TCS_SHIFT)) & ENETC_VSI_SIPCAPR1_NUM_TCS_MASK)

#define ENETC_VSI_SIPCAPR1_NUM_MCH_MASK          (0x300U)
#define ENETC_VSI_SIPCAPR1_NUM_MCH_SHIFT         (8U)
#define ENETC_VSI_SIPCAPR1_NUM_MCH_WIDTH         (2U)
#define ENETC_VSI_SIPCAPR1_NUM_MCH(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR1_NUM_MCH_SHIFT)) & ENETC_VSI_SIPCAPR1_NUM_MCH_MASK)

#define ENETC_VSI_SIPCAPR1_NUM_UCH_MASK          (0xC00U)
#define ENETC_VSI_SIPCAPR1_NUM_UCH_SHIFT         (10U)
#define ENETC_VSI_SIPCAPR1_NUM_UCH_WIDTH         (2U)
#define ENETC_VSI_SIPCAPR1_NUM_UCH(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR1_NUM_UCH_SHIFT)) & ENETC_VSI_SIPCAPR1_NUM_UCH_MASK)

#define ENETC_VSI_SIPCAPR1_NUM_MSIX_MASK         (0x3F000U)
#define ENETC_VSI_SIPCAPR1_NUM_MSIX_SHIFT        (12U)
#define ENETC_VSI_SIPCAPR1_NUM_MSIX_WIDTH        (6U)
#define ENETC_VSI_SIPCAPR1_NUM_MSIX(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR1_NUM_MSIX_SHIFT)) & ENETC_VSI_SIPCAPR1_NUM_MSIX_MASK)

#define ENETC_VSI_SIPCAPR1_NUM_IPV_MASK          (0x80000000U)
#define ENETC_VSI_SIPCAPR1_NUM_IPV_SHIFT         (31U)
#define ENETC_VSI_SIPCAPR1_NUM_IPV_WIDTH         (1U)
#define ENETC_VSI_SIPCAPR1_NUM_IPV(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPCAPR1_NUM_IPV_SHIFT)) & ENETC_VSI_SIPCAPR1_NUM_IPV_MASK)
/*! @} */

/*! @name SITSR - Station interface timer status register */
/*! @{ */

#define ENETC_VSI_SITSR_SYNC_MASK                (0x1U)
#define ENETC_VSI_SITSR_SYNC_SHIFT               (0U)
#define ENETC_VSI_SITSR_SYNC_WIDTH               (1U)
#define ENETC_VSI_SITSR_SYNC(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITSR_SYNC_SHIFT)) & ENETC_VSI_SITSR_SYNC_MASK)

#define ENETC_VSI_SITSR_PARAM_VAL_MASK           (0xFFFFFFFEU)
#define ENETC_VSI_SITSR_PARAM_VAL_SHIFT          (1U)
#define ENETC_VSI_SITSR_PARAM_VAL_WIDTH          (31U)
#define ENETC_VSI_SITSR_PARAM_VAL(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITSR_PARAM_VAL_SHIFT)) & ENETC_VSI_SITSR_PARAM_VAL_MASK)
/*! @} */

/*! @name SIRBGCR - Station interface receive BDR group control register */
/*! @{ */

#define ENETC_VSI_SIRBGCR_NUM_GROUPS_MASK        (0x3U)
#define ENETC_VSI_SIRBGCR_NUM_GROUPS_SHIFT       (0U)
#define ENETC_VSI_SIRBGCR_NUM_GROUPS_WIDTH       (2U)
#define ENETC_VSI_SIRBGCR_NUM_GROUPS(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRBGCR_NUM_GROUPS_SHIFT)) & ENETC_VSI_SIRBGCR_NUM_GROUPS_MASK)

#define ENETC_VSI_SIRBGCR_RINGS_PER_GROUP_MASK   (0x70000U)
#define ENETC_VSI_SIRBGCR_RINGS_PER_GROUP_SHIFT  (16U)
#define ENETC_VSI_SIRBGCR_RINGS_PER_GROUP_WIDTH  (3U)
#define ENETC_VSI_SIRBGCR_RINGS_PER_GROUP(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRBGCR_RINGS_PER_GROUP_SHIFT)) & ENETC_VSI_SIRBGCR_RINGS_PER_GROUP_MASK)
/*! @} */

/*! @name SIBCAR - Station interface buffer cache attribute register */
/*! @{ */

#define ENETC_VSI_SIBCAR_BD_WRCACHE_MASK         (0xFU)
#define ENETC_VSI_SIBCAR_BD_WRCACHE_SHIFT        (0U)
#define ENETC_VSI_SIBCAR_BD_WRCACHE_WIDTH        (4U)
#define ENETC_VSI_SIBCAR_BD_WRCACHE(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_BD_WRCACHE_SHIFT)) & ENETC_VSI_SIBCAR_BD_WRCACHE_MASK)

#define ENETC_VSI_SIBCAR_BD_WRDOMAIN_MASK        (0x30U)
#define ENETC_VSI_SIBCAR_BD_WRDOMAIN_SHIFT       (4U)
#define ENETC_VSI_SIBCAR_BD_WRDOMAIN_WIDTH       (2U)
#define ENETC_VSI_SIBCAR_BD_WRDOMAIN(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_BD_WRDOMAIN_SHIFT)) & ENETC_VSI_SIBCAR_BD_WRDOMAIN_MASK)

#define ENETC_VSI_SIBCAR_BD_WRSNP_MASK           (0xC0U)
#define ENETC_VSI_SIBCAR_BD_WRSNP_SHIFT          (6U)
#define ENETC_VSI_SIBCAR_BD_WRSNP_WIDTH          (2U)
#define ENETC_VSI_SIBCAR_BD_WRSNP(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_BD_WRSNP_SHIFT)) & ENETC_VSI_SIBCAR_BD_WRSNP_MASK)

#define ENETC_VSI_SIBCAR_WRCACHE_MASK            (0xF00U)
#define ENETC_VSI_SIBCAR_WRCACHE_SHIFT           (8U)
#define ENETC_VSI_SIBCAR_WRCACHE_WIDTH           (4U)
#define ENETC_VSI_SIBCAR_WRCACHE(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_WRCACHE_SHIFT)) & ENETC_VSI_SIBCAR_WRCACHE_MASK)

#define ENETC_VSI_SIBCAR_WRDOMAIN_MASK           (0x3000U)
#define ENETC_VSI_SIBCAR_WRDOMAIN_SHIFT          (12U)
#define ENETC_VSI_SIBCAR_WRDOMAIN_WIDTH          (2U)
#define ENETC_VSI_SIBCAR_WRDOMAIN(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_WRDOMAIN_SHIFT)) & ENETC_VSI_SIBCAR_WRDOMAIN_MASK)

#define ENETC_VSI_SIBCAR_WRSNP_MASK              (0xC000U)
#define ENETC_VSI_SIBCAR_WRSNP_SHIFT             (14U)
#define ENETC_VSI_SIBCAR_WRSNP_WIDTH             (2U)
#define ENETC_VSI_SIBCAR_WRSNP(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_WRSNP_SHIFT)) & ENETC_VSI_SIBCAR_WRSNP_MASK)

#define ENETC_VSI_SIBCAR_BD_RDCACHE_MASK         (0xF0000U)
#define ENETC_VSI_SIBCAR_BD_RDCACHE_SHIFT        (16U)
#define ENETC_VSI_SIBCAR_BD_RDCACHE_WIDTH        (4U)
#define ENETC_VSI_SIBCAR_BD_RDCACHE(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_BD_RDCACHE_SHIFT)) & ENETC_VSI_SIBCAR_BD_RDCACHE_MASK)

#define ENETC_VSI_SIBCAR_BD_RDDOMAIN_MASK        (0x300000U)
#define ENETC_VSI_SIBCAR_BD_RDDOMAIN_SHIFT       (20U)
#define ENETC_VSI_SIBCAR_BD_RDDOMAIN_WIDTH       (2U)
#define ENETC_VSI_SIBCAR_BD_RDDOMAIN(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_BD_RDDOMAIN_SHIFT)) & ENETC_VSI_SIBCAR_BD_RDDOMAIN_MASK)

#define ENETC_VSI_SIBCAR_BD_RDSNP_MASK           (0xC00000U)
#define ENETC_VSI_SIBCAR_BD_RDSNP_SHIFT          (22U)
#define ENETC_VSI_SIBCAR_BD_RDSNP_WIDTH          (2U)
#define ENETC_VSI_SIBCAR_BD_RDSNP(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_BD_RDSNP_SHIFT)) & ENETC_VSI_SIBCAR_BD_RDSNP_MASK)

#define ENETC_VSI_SIBCAR_RDCACHE_MASK            (0xF000000U)
#define ENETC_VSI_SIBCAR_RDCACHE_SHIFT           (24U)
#define ENETC_VSI_SIBCAR_RDCACHE_WIDTH           (4U)
#define ENETC_VSI_SIBCAR_RDCACHE(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_RDCACHE_SHIFT)) & ENETC_VSI_SIBCAR_RDCACHE_MASK)

#define ENETC_VSI_SIBCAR_RDDOMAIN_MASK           (0x30000000U)
#define ENETC_VSI_SIBCAR_RDDOMAIN_SHIFT          (28U)
#define ENETC_VSI_SIBCAR_RDDOMAIN_WIDTH          (2U)
#define ENETC_VSI_SIBCAR_RDDOMAIN(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_RDDOMAIN_SHIFT)) & ENETC_VSI_SIBCAR_RDDOMAIN_MASK)

#define ENETC_VSI_SIBCAR_RDSNP_MASK              (0xC0000000U)
#define ENETC_VSI_SIBCAR_RDSNP_SHIFT             (30U)
#define ENETC_VSI_SIBCAR_RDSNP_WIDTH             (2U)
#define ENETC_VSI_SIBCAR_RDSNP(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBCAR_RDSNP_SHIFT)) & ENETC_VSI_SIBCAR_RDSNP_MASK)
/*! @} */

/*! @name SICCAR - Station interface command cache attribute register */
/*! @{ */

#define ENETC_VSI_SICCAR_CBD_WRCACHE_MASK        (0xFU)
#define ENETC_VSI_SICCAR_CBD_WRCACHE_SHIFT       (0U)
#define ENETC_VSI_SICCAR_CBD_WRCACHE_WIDTH       (4U)
#define ENETC_VSI_SICCAR_CBD_WRCACHE(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CBD_WRCACHE_SHIFT)) & ENETC_VSI_SICCAR_CBD_WRCACHE_MASK)

#define ENETC_VSI_SICCAR_CBD_WRDOMAIN_MASK       (0x30U)
#define ENETC_VSI_SICCAR_CBD_WRDOMAIN_SHIFT      (4U)
#define ENETC_VSI_SICCAR_CBD_WRDOMAIN_WIDTH      (2U)
#define ENETC_VSI_SICCAR_CBD_WRDOMAIN(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CBD_WRDOMAIN_SHIFT)) & ENETC_VSI_SICCAR_CBD_WRDOMAIN_MASK)

#define ENETC_VSI_SICCAR_CBD_WRSNP_MASK          (0xC0U)
#define ENETC_VSI_SICCAR_CBD_WRSNP_SHIFT         (6U)
#define ENETC_VSI_SICCAR_CBD_WRSNP_WIDTH         (2U)
#define ENETC_VSI_SICCAR_CBD_WRSNP(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CBD_WRSNP_SHIFT)) & ENETC_VSI_SICCAR_CBD_WRSNP_MASK)

#define ENETC_VSI_SICCAR_CWRCACHE_MASK           (0xF00U)
#define ENETC_VSI_SICCAR_CWRCACHE_SHIFT          (8U)
#define ENETC_VSI_SICCAR_CWRCACHE_WIDTH          (4U)
#define ENETC_VSI_SICCAR_CWRCACHE(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CWRCACHE_SHIFT)) & ENETC_VSI_SICCAR_CWRCACHE_MASK)

#define ENETC_VSI_SICCAR_CWRDOMAIN_MASK          (0x3000U)
#define ENETC_VSI_SICCAR_CWRDOMAIN_SHIFT         (12U)
#define ENETC_VSI_SICCAR_CWRDOMAIN_WIDTH         (2U)
#define ENETC_VSI_SICCAR_CWRDOMAIN(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CWRDOMAIN_SHIFT)) & ENETC_VSI_SICCAR_CWRDOMAIN_MASK)

#define ENETC_VSI_SICCAR_CWRSNP_MASK             (0xC000U)
#define ENETC_VSI_SICCAR_CWRSNP_SHIFT            (14U)
#define ENETC_VSI_SICCAR_CWRSNP_WIDTH            (2U)
#define ENETC_VSI_SICCAR_CWRSNP(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CWRSNP_SHIFT)) & ENETC_VSI_SICCAR_CWRSNP_MASK)

#define ENETC_VSI_SICCAR_CBD_RDCACHE_MASK        (0xF0000U)
#define ENETC_VSI_SICCAR_CBD_RDCACHE_SHIFT       (16U)
#define ENETC_VSI_SICCAR_CBD_RDCACHE_WIDTH       (4U)
#define ENETC_VSI_SICCAR_CBD_RDCACHE(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CBD_RDCACHE_SHIFT)) & ENETC_VSI_SICCAR_CBD_RDCACHE_MASK)

#define ENETC_VSI_SICCAR_CBD_RDDOMAIN_MASK       (0x300000U)
#define ENETC_VSI_SICCAR_CBD_RDDOMAIN_SHIFT      (20U)
#define ENETC_VSI_SICCAR_CBD_RDDOMAIN_WIDTH      (2U)
#define ENETC_VSI_SICCAR_CBD_RDDOMAIN(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CBD_RDDOMAIN_SHIFT)) & ENETC_VSI_SICCAR_CBD_RDDOMAIN_MASK)

#define ENETC_VSI_SICCAR_CBD_RDSNP_MASK          (0xC00000U)
#define ENETC_VSI_SICCAR_CBD_RDSNP_SHIFT         (22U)
#define ENETC_VSI_SICCAR_CBD_RDSNP_WIDTH         (2U)
#define ENETC_VSI_SICCAR_CBD_RDSNP(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CBD_RDSNP_SHIFT)) & ENETC_VSI_SICCAR_CBD_RDSNP_MASK)

#define ENETC_VSI_SICCAR_CRDCACHE_MASK           (0xF000000U)
#define ENETC_VSI_SICCAR_CRDCACHE_SHIFT          (24U)
#define ENETC_VSI_SICCAR_CRDCACHE_WIDTH          (4U)
#define ENETC_VSI_SICCAR_CRDCACHE(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CRDCACHE_SHIFT)) & ENETC_VSI_SICCAR_CRDCACHE_MASK)

#define ENETC_VSI_SICCAR_CRDDOMAIN_MASK          (0x30000000U)
#define ENETC_VSI_SICCAR_CRDDOMAIN_SHIFT         (28U)
#define ENETC_VSI_SICCAR_CRDDOMAIN_WIDTH         (2U)
#define ENETC_VSI_SICCAR_CRDDOMAIN(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CRDDOMAIN_SHIFT)) & ENETC_VSI_SICCAR_CRDDOMAIN_MASK)

#define ENETC_VSI_SICCAR_CRDSNP_MASK             (0xC0000000U)
#define ENETC_VSI_SICCAR_CRDSNP_SHIFT            (30U)
#define ENETC_VSI_SICCAR_CRDSNP_WIDTH            (2U)
#define ENETC_VSI_SICCAR_CRDSNP(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICCAR_CRDSNP_SHIFT)) & ENETC_VSI_SICCAR_CRDSNP_MASK)
/*! @} */

/*! @name SIPMAR0 - Station interface primary MAC address register 0 */
/*! @{ */

#define ENETC_VSI_SIPMAR0_PRIM_MAC_ADDR_MASK     (0xFFFFFFFFU)
#define ENETC_VSI_SIPMAR0_PRIM_MAC_ADDR_SHIFT    (0U)
#define ENETC_VSI_SIPMAR0_PRIM_MAC_ADDR_WIDTH    (32U)
#define ENETC_VSI_SIPMAR0_PRIM_MAC_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPMAR0_PRIM_MAC_ADDR_SHIFT)) & ENETC_VSI_SIPMAR0_PRIM_MAC_ADDR_MASK)
/*! @} */

/*! @name SIPMAR1 - Station interface primary MAC address register 1 */
/*! @{ */

#define ENETC_VSI_SIPMAR1_PRIM_MAC_ADDR_MASK     (0xFFFFU)
#define ENETC_VSI_SIPMAR1_PRIM_MAC_ADDR_SHIFT    (0U)
#define ENETC_VSI_SIPMAR1_PRIM_MAC_ADDR_WIDTH    (16U)
#define ENETC_VSI_SIPMAR1_PRIM_MAC_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIPMAR1_PRIM_MAC_ADDR_SHIFT)) & ENETC_VSI_SIPMAR1_PRIM_MAC_ADDR_MASK)
/*! @} */

/*! @name SICVLANR1 - Station interface custom VLAN register 1 */
/*! @{ */

#define ENETC_VSI_SICVLANR1_ETYPE_MASK           (0xFFFFU)
#define ENETC_VSI_SICVLANR1_ETYPE_SHIFT          (0U)
#define ENETC_VSI_SICVLANR1_ETYPE_WIDTH          (16U)
#define ENETC_VSI_SICVLANR1_ETYPE(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICVLANR1_ETYPE_SHIFT)) & ENETC_VSI_SICVLANR1_ETYPE_MASK)

#define ENETC_VSI_SICVLANR1_V_MASK               (0x80000000U)
#define ENETC_VSI_SICVLANR1_V_SHIFT              (31U)
#define ENETC_VSI_SICVLANR1_V_WIDTH              (1U)
#define ENETC_VSI_SICVLANR1_V(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICVLANR1_V_SHIFT)) & ENETC_VSI_SICVLANR1_V_MASK)
/*! @} */

/*! @name SICVLANR2 - Station interface custom VLAN register 2 */
/*! @{ */

#define ENETC_VSI_SICVLANR2_ETYPE_MASK           (0xFFFFU)
#define ENETC_VSI_SICVLANR2_ETYPE_SHIFT          (0U)
#define ENETC_VSI_SICVLANR2_ETYPE_WIDTH          (16U)
#define ENETC_VSI_SICVLANR2_ETYPE(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICVLANR2_ETYPE_SHIFT)) & ENETC_VSI_SICVLANR2_ETYPE_MASK)

#define ENETC_VSI_SICVLANR2_V_MASK               (0x80000000U)
#define ENETC_VSI_SICVLANR2_V_SHIFT              (31U)
#define ENETC_VSI_SICVLANR2_V_WIDTH              (1U)
#define ENETC_VSI_SICVLANR2_V(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICVLANR2_V_SHIFT)) & ENETC_VSI_SICVLANR2_V_MASK)
/*! @} */

/*! @name SIVLANIPVMR0 - Station interface VLAN to IPV mapping register 0 */
/*! @{ */

#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_0_MASK    (0xFU)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_0_SHIFT   (0U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_0_WIDTH   (4U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_0(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR0_PCP_DEI_0_SHIFT)) & ENETC_VSI_SIVLANIPVMR0_PCP_DEI_0_MASK)

#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_1_MASK    (0xF0U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_1_SHIFT   (4U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_1_WIDTH   (4U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_1(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR0_PCP_DEI_1_SHIFT)) & ENETC_VSI_SIVLANIPVMR0_PCP_DEI_1_MASK)

#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_2_MASK    (0xF00U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_2_SHIFT   (8U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_2_WIDTH   (4U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_2(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR0_PCP_DEI_2_SHIFT)) & ENETC_VSI_SIVLANIPVMR0_PCP_DEI_2_MASK)

#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_3_MASK    (0xF000U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_3_SHIFT   (12U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_3_WIDTH   (4U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_3(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR0_PCP_DEI_3_SHIFT)) & ENETC_VSI_SIVLANIPVMR0_PCP_DEI_3_MASK)

#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_4_MASK    (0xF0000U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_4_SHIFT   (16U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_4_WIDTH   (4U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_4(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR0_PCP_DEI_4_SHIFT)) & ENETC_VSI_SIVLANIPVMR0_PCP_DEI_4_MASK)

#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_5_MASK    (0xF00000U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_5_SHIFT   (20U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_5_WIDTH   (4U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_5(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR0_PCP_DEI_5_SHIFT)) & ENETC_VSI_SIVLANIPVMR0_PCP_DEI_5_MASK)

#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_6_MASK    (0xF000000U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_6_SHIFT   (24U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_6_WIDTH   (4U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_6(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR0_PCP_DEI_6_SHIFT)) & ENETC_VSI_SIVLANIPVMR0_PCP_DEI_6_MASK)

#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_7_MASK    (0xF0000000U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_7_SHIFT   (28U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_7_WIDTH   (4U)
#define ENETC_VSI_SIVLANIPVMR0_PCP_DEI_7(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR0_PCP_DEI_7_SHIFT)) & ENETC_VSI_SIVLANIPVMR0_PCP_DEI_7_MASK)
/*! @} */

/*! @name SIVLANIPVMR1 - Station interface VLAN to IPV mapping register 1 */
/*! @{ */

#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_8_MASK    (0xFU)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_8_SHIFT   (0U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_8_WIDTH   (4U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_8(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR1_PCP_DEI_8_SHIFT)) & ENETC_VSI_SIVLANIPVMR1_PCP_DEI_8_MASK)

#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_9_MASK    (0xF0U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_9_SHIFT   (4U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_9_WIDTH   (4U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_9(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR1_PCP_DEI_9_SHIFT)) & ENETC_VSI_SIVLANIPVMR1_PCP_DEI_9_MASK)

#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_10_MASK   (0xF00U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_10_SHIFT  (8U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_10_WIDTH  (4U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_10(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR1_PCP_DEI_10_SHIFT)) & ENETC_VSI_SIVLANIPVMR1_PCP_DEI_10_MASK)

#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_11_MASK   (0xF000U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_11_SHIFT  (12U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_11_WIDTH  (4U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_11(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR1_PCP_DEI_11_SHIFT)) & ENETC_VSI_SIVLANIPVMR1_PCP_DEI_11_MASK)

#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_12_MASK   (0xF0000U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_12_SHIFT  (16U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_12_WIDTH  (4U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_12(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR1_PCP_DEI_12_SHIFT)) & ENETC_VSI_SIVLANIPVMR1_PCP_DEI_12_MASK)

#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_13_MASK   (0xF00000U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_13_SHIFT  (20U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_13_WIDTH  (4U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_13(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR1_PCP_DEI_13_SHIFT)) & ENETC_VSI_SIVLANIPVMR1_PCP_DEI_13_MASK)

#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_14_MASK   (0xF000000U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_14_SHIFT  (24U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_14_WIDTH  (4U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_14(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR1_PCP_DEI_14_SHIFT)) & ENETC_VSI_SIVLANIPVMR1_PCP_DEI_14_MASK)

#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_15_MASK   (0xF0000000U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_15_SHIFT  (28U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_15_WIDTH  (4U)
#define ENETC_VSI_SIVLANIPVMR1_PCP_DEI_15(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVLANIPVMR1_PCP_DEI_15_SHIFT)) & ENETC_VSI_SIVLANIPVMR1_PCP_DEI_15_MASK)
/*! @} */

/*! @name SIIPVBDRMR0 - Station interface IPV to ring mapping register */
/*! @{ */

#define ENETC_VSI_SIIPVBDRMR0_IPV0BDR_MASK       (0x7U)
#define ENETC_VSI_SIIPVBDRMR0_IPV0BDR_SHIFT      (0U)
#define ENETC_VSI_SIIPVBDRMR0_IPV0BDR_WIDTH      (3U)
#define ENETC_VSI_SIIPVBDRMR0_IPV0BDR(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIIPVBDRMR0_IPV0BDR_SHIFT)) & ENETC_VSI_SIIPVBDRMR0_IPV0BDR_MASK)

#define ENETC_VSI_SIIPVBDRMR0_IPV1BDR_MASK       (0x70U)
#define ENETC_VSI_SIIPVBDRMR0_IPV1BDR_SHIFT      (4U)
#define ENETC_VSI_SIIPVBDRMR0_IPV1BDR_WIDTH      (3U)
#define ENETC_VSI_SIIPVBDRMR0_IPV1BDR(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIIPVBDRMR0_IPV1BDR_SHIFT)) & ENETC_VSI_SIIPVBDRMR0_IPV1BDR_MASK)

#define ENETC_VSI_SIIPVBDRMR0_IPV2BDR_MASK       (0x700U)
#define ENETC_VSI_SIIPVBDRMR0_IPV2BDR_SHIFT      (8U)
#define ENETC_VSI_SIIPVBDRMR0_IPV2BDR_WIDTH      (3U)
#define ENETC_VSI_SIIPVBDRMR0_IPV2BDR(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIIPVBDRMR0_IPV2BDR_SHIFT)) & ENETC_VSI_SIIPVBDRMR0_IPV2BDR_MASK)

#define ENETC_VSI_SIIPVBDRMR0_IPV3BDR_MASK       (0x7000U)
#define ENETC_VSI_SIIPVBDRMR0_IPV3BDR_SHIFT      (12U)
#define ENETC_VSI_SIIPVBDRMR0_IPV3BDR_WIDTH      (3U)
#define ENETC_VSI_SIIPVBDRMR0_IPV3BDR(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIIPVBDRMR0_IPV3BDR_SHIFT)) & ENETC_VSI_SIIPVBDRMR0_IPV3BDR_MASK)

#define ENETC_VSI_SIIPVBDRMR0_IPV4BDR_MASK       (0x70000U)
#define ENETC_VSI_SIIPVBDRMR0_IPV4BDR_SHIFT      (16U)
#define ENETC_VSI_SIIPVBDRMR0_IPV4BDR_WIDTH      (3U)
#define ENETC_VSI_SIIPVBDRMR0_IPV4BDR(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIIPVBDRMR0_IPV4BDR_SHIFT)) & ENETC_VSI_SIIPVBDRMR0_IPV4BDR_MASK)

#define ENETC_VSI_SIIPVBDRMR0_IPV5BDR_MASK       (0x700000U)
#define ENETC_VSI_SIIPVBDRMR0_IPV5BDR_SHIFT      (20U)
#define ENETC_VSI_SIIPVBDRMR0_IPV5BDR_WIDTH      (3U)
#define ENETC_VSI_SIIPVBDRMR0_IPV5BDR(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIIPVBDRMR0_IPV5BDR_SHIFT)) & ENETC_VSI_SIIPVBDRMR0_IPV5BDR_MASK)

#define ENETC_VSI_SIIPVBDRMR0_IPV6BDR_MASK       (0x7000000U)
#define ENETC_VSI_SIIPVBDRMR0_IPV6BDR_SHIFT      (24U)
#define ENETC_VSI_SIIPVBDRMR0_IPV6BDR_WIDTH      (3U)
#define ENETC_VSI_SIIPVBDRMR0_IPV6BDR(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIIPVBDRMR0_IPV6BDR_SHIFT)) & ENETC_VSI_SIIPVBDRMR0_IPV6BDR_MASK)

#define ENETC_VSI_SIIPVBDRMR0_IPV7BDR_MASK       (0x70000000U)
#define ENETC_VSI_SIIPVBDRMR0_IPV7BDR_SHIFT      (28U)
#define ENETC_VSI_SIIPVBDRMR0_IPV7BDR_WIDTH      (3U)
#define ENETC_VSI_SIIPVBDRMR0_IPV7BDR(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIIPVBDRMR0_IPV7BDR_SHIFT)) & ENETC_VSI_SIIPVBDRMR0_IPV7BDR_MASK)
/*! @} */

/*! @name VSIMSGSR - Virtual station interface message send register */
/*! @{ */

#define ENETC_VSI_VSIMSGSR_MB_MASK               (0x1U)
#define ENETC_VSI_VSIMSGSR_MB_SHIFT              (0U)
#define ENETC_VSI_VSIMSGSR_MB_WIDTH              (1U)
#define ENETC_VSI_VSIMSGSR_MB(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIMSGSR_MB_SHIFT)) & ENETC_VSI_VSIMSGSR_MB_MASK)

#define ENETC_VSI_VSIMSGSR_MS_MASK               (0x2U)
#define ENETC_VSI_VSIMSGSR_MS_SHIFT              (1U)
#define ENETC_VSI_VSIMSGSR_MS_WIDTH              (1U)
#define ENETC_VSI_VSIMSGSR_MS(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIMSGSR_MS_SHIFT)) & ENETC_VSI_VSIMSGSR_MS_MASK)

#define ENETC_VSI_VSIMSGSR_MC_MASK               (0xFFFF0000U)
#define ENETC_VSI_VSIMSGSR_MC_SHIFT              (16U)
#define ENETC_VSI_VSIMSGSR_MC_WIDTH              (16U)
#define ENETC_VSI_VSIMSGSR_MC(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIMSGSR_MC_SHIFT)) & ENETC_VSI_VSIMSGSR_MC_MASK)
/*! @} */

/*! @name VSIMSGRR - Virtual station interface message receive register */
/*! @{ */

#define ENETC_VSI_VSIMSGRR_MR_MASK               (0x1U)
#define ENETC_VSI_VSIMSGRR_MR_SHIFT              (0U)
#define ENETC_VSI_VSIMSGRR_MR_WIDTH              (1U)
#define ENETC_VSI_VSIMSGRR_MR(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIMSGRR_MR_SHIFT)) & ENETC_VSI_VSIMSGRR_MR_MASK)

#define ENETC_VSI_VSIMSGRR_MC_MASK               (0xFFFF0000U)
#define ENETC_VSI_VSIMSGRR_MC_SHIFT              (16U)
#define ENETC_VSI_VSIMSGRR_MC_WIDTH              (16U)
#define ENETC_VSI_VSIMSGRR_MC(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIMSGRR_MC_SHIFT)) & ENETC_VSI_VSIMSGRR_MC_MASK)
/*! @} */

/*! @name VSIMSGSNDAR0 - Virtual station interface message address send register 0 */
/*! @{ */

#define ENETC_VSI_VSIMSGSNDAR0_MSIZE_MASK        (0x1FU)
#define ENETC_VSI_VSIMSGSNDAR0_MSIZE_SHIFT       (0U)
#define ENETC_VSI_VSIMSGSNDAR0_MSIZE_WIDTH       (5U)
#define ENETC_VSI_VSIMSGSNDAR0_MSIZE(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIMSGSNDAR0_MSIZE_SHIFT)) & ENETC_VSI_VSIMSGSNDAR0_MSIZE_MASK)

#define ENETC_VSI_VSIMSGSNDAR0_ADDRL_MASK        (0xFFFFFFC0U)
#define ENETC_VSI_VSIMSGSNDAR0_ADDRL_SHIFT       (6U)
#define ENETC_VSI_VSIMSGSNDAR0_ADDRL_WIDTH       (26U)
#define ENETC_VSI_VSIMSGSNDAR0_ADDRL(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIMSGSNDAR0_ADDRL_SHIFT)) & ENETC_VSI_VSIMSGSNDAR0_ADDRL_MASK)
/*! @} */

/*! @name VSIMSGSNDAR1 - Virtual station interface message send address register 1 */
/*! @{ */

#define ENETC_VSI_VSIMSGSNDAR1_ADDRH_MASK        (0xFFFFFFFFU)
#define ENETC_VSI_VSIMSGSNDAR1_ADDRH_SHIFT       (0U)
#define ENETC_VSI_VSIMSGSNDAR1_ADDRH_WIDTH       (32U)
#define ENETC_VSI_VSIMSGSNDAR1_ADDRH(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIMSGSNDAR1_ADDRH_SHIFT)) & ENETC_VSI_VSIMSGSNDAR1_ADDRH_MASK)
/*! @} */

/*! @name SIROCT0 - Station interface receive octets counter (ifInOctets) 0 */
/*! @{ */

#define ENETC_VSI_SIROCT0_ROCT_LOW_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SIROCT0_ROCT_LOW_SHIFT         (0U)
#define ENETC_VSI_SIROCT0_ROCT_LOW_WIDTH         (32U)
#define ENETC_VSI_SIROCT0_ROCT_LOW(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIROCT0_ROCT_LOW_SHIFT)) & ENETC_VSI_SIROCT0_ROCT_LOW_MASK)
/*! @} */

/*! @name SIROCT1 - Station interface receive octets counter (ifInOctets) 1 */
/*! @{ */

#define ENETC_VSI_SIROCT1_ROCT_HIGH_MASK         (0xFFFFFFFFU)
#define ENETC_VSI_SIROCT1_ROCT_HIGH_SHIFT        (0U)
#define ENETC_VSI_SIROCT1_ROCT_HIGH_WIDTH        (32U)
#define ENETC_VSI_SIROCT1_ROCT_HIGH(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIROCT1_ROCT_HIGH_SHIFT)) & ENETC_VSI_SIROCT1_ROCT_HIGH_MASK)
/*! @} */

/*! @name SIRFRM0 - Station interface receive frame counter (aFrameReceivedOK) 0 */
/*! @{ */

#define ENETC_VSI_SIRFRM0_RFRM_LOW_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SIRFRM0_RFRM_LOW_SHIFT         (0U)
#define ENETC_VSI_SIRFRM0_RFRM_LOW_WIDTH         (32U)
#define ENETC_VSI_SIRFRM0_RFRM_LOW(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRFRM0_RFRM_LOW_SHIFT)) & ENETC_VSI_SIRFRM0_RFRM_LOW_MASK)
/*! @} */

/*! @name SIRFRM1 - Station interface receive frame counter (aFrameReceivedOK) 1 */
/*! @{ */

#define ENETC_VSI_SIRFRM1_RFRM_HIGH_MASK         (0xFFFFFFFFU)
#define ENETC_VSI_SIRFRM1_RFRM_HIGH_SHIFT        (0U)
#define ENETC_VSI_SIRFRM1_RFRM_HIGH_WIDTH        (32U)
#define ENETC_VSI_SIRFRM1_RFRM_HIGH(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRFRM1_RFRM_HIGH_SHIFT)) & ENETC_VSI_SIRFRM1_RFRM_HIGH_MASK)
/*! @} */

/*! @name SIRUCA0 - Station interface receive unicast frame counter (ifInUcastPkts) 0 */
/*! @{ */

#define ENETC_VSI_SIRUCA0_RUCA_LOW_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SIRUCA0_RUCA_LOW_SHIFT         (0U)
#define ENETC_VSI_SIRUCA0_RUCA_LOW_WIDTH         (32U)
#define ENETC_VSI_SIRUCA0_RUCA_LOW(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRUCA0_RUCA_LOW_SHIFT)) & ENETC_VSI_SIRUCA0_RUCA_LOW_MASK)
/*! @} */

/*! @name SIRUCA1 - Station interface receive unicast frame counter (ifInUcastPkts) 1 */
/*! @{ */

#define ENETC_VSI_SIRUCA1_RUCA_HIGH_MASK         (0xFFFFFFFFU)
#define ENETC_VSI_SIRUCA1_RUCA_HIGH_SHIFT        (0U)
#define ENETC_VSI_SIRUCA1_RUCA_HIGH_WIDTH        (32U)
#define ENETC_VSI_SIRUCA1_RUCA_HIGH(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRUCA1_RUCA_HIGH_SHIFT)) & ENETC_VSI_SIRUCA1_RUCA_HIGH_MASK)
/*! @} */

/*! @name SIRMCA0 - Station interface receive multicast frame counter (ifInMulticastPkts) 0 */
/*! @{ */

#define ENETC_VSI_SIRMCA0_RMCA_LOW_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SIRMCA0_RMCA_LOW_SHIFT         (0U)
#define ENETC_VSI_SIRMCA0_RMCA_LOW_WIDTH         (32U)
#define ENETC_VSI_SIRMCA0_RMCA_LOW(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRMCA0_RMCA_LOW_SHIFT)) & ENETC_VSI_SIRMCA0_RMCA_LOW_MASK)
/*! @} */

/*! @name SIRMCA1 - Station interface receive multicast frame counter (ifInMulticastPkts) 1 */
/*! @{ */

#define ENETC_VSI_SIRMCA1_RMCA_HIGH_MASK         (0xFFFFFFFFU)
#define ENETC_VSI_SIRMCA1_RMCA_HIGH_SHIFT        (0U)
#define ENETC_VSI_SIRMCA1_RMCA_HIGH_WIDTH        (32U)
#define ENETC_VSI_SIRMCA1_RMCA_HIGH(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRMCA1_RMCA_HIGH_SHIFT)) & ENETC_VSI_SIRMCA1_RMCA_HIGH_MASK)
/*! @} */

/*! @name SITOCT0 - Station interface transmit octets counter (ifOutOctets) 0 */
/*! @{ */

#define ENETC_VSI_SITOCT0_TOCT_LOW_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SITOCT0_TOCT_LOW_SHIFT         (0U)
#define ENETC_VSI_SITOCT0_TOCT_LOW_WIDTH         (32U)
#define ENETC_VSI_SITOCT0_TOCT_LOW(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITOCT0_TOCT_LOW_SHIFT)) & ENETC_VSI_SITOCT0_TOCT_LOW_MASK)
/*! @} */

/*! @name SITOCT1 - Station interface transmit octets counter (ifOutOctets) 1 */
/*! @{ */

#define ENETC_VSI_SITOCT1_TOCT_HIGH_MASK         (0xFFFFFFFFU)
#define ENETC_VSI_SITOCT1_TOCT_HIGH_SHIFT        (0U)
#define ENETC_VSI_SITOCT1_TOCT_HIGH_WIDTH        (32U)
#define ENETC_VSI_SITOCT1_TOCT_HIGH(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITOCT1_TOCT_HIGH_SHIFT)) & ENETC_VSI_SITOCT1_TOCT_HIGH_MASK)
/*! @} */

/*! @name SITFRM0 - Station interface transmit frame counter (aFrameTransmittedOK) 0 */
/*! @{ */

#define ENETC_VSI_SITFRM0_TFRM_LOW_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SITFRM0_TFRM_LOW_SHIFT         (0U)
#define ENETC_VSI_SITFRM0_TFRM_LOW_WIDTH         (32U)
#define ENETC_VSI_SITFRM0_TFRM_LOW(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITFRM0_TFRM_LOW_SHIFT)) & ENETC_VSI_SITFRM0_TFRM_LOW_MASK)
/*! @} */

/*! @name SITFRM1 - Station interface transmit frame counter (aFrameTransmittedOK) 1 */
/*! @{ */

#define ENETC_VSI_SITFRM1_TFRM_HIGH_MASK         (0xFFFFFFFFU)
#define ENETC_VSI_SITFRM1_TFRM_HIGH_SHIFT        (0U)
#define ENETC_VSI_SITFRM1_TFRM_HIGH_WIDTH        (32U)
#define ENETC_VSI_SITFRM1_TFRM_HIGH(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITFRM1_TFRM_HIGH_SHIFT)) & ENETC_VSI_SITFRM1_TFRM_HIGH_MASK)
/*! @} */

/*! @name SITUCA0 - Station interface transmit unicast frame counter (ifOutUcastPkts) 0 */
/*! @{ */

#define ENETC_VSI_SITUCA0_TUCA_LOW_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SITUCA0_TUCA_LOW_SHIFT         (0U)
#define ENETC_VSI_SITUCA0_TUCA_LOW_WIDTH         (32U)
#define ENETC_VSI_SITUCA0_TUCA_LOW(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITUCA0_TUCA_LOW_SHIFT)) & ENETC_VSI_SITUCA0_TUCA_LOW_MASK)
/*! @} */

/*! @name SITUCA1 - Station interface transmit unicast frame counter (ifOutUcastPkts) 1 */
/*! @{ */

#define ENETC_VSI_SITUCA1_TUCA_HIGH_MASK         (0xFFFFFFFFU)
#define ENETC_VSI_SITUCA1_TUCA_HIGH_SHIFT        (0U)
#define ENETC_VSI_SITUCA1_TUCA_HIGH_WIDTH        (32U)
#define ENETC_VSI_SITUCA1_TUCA_HIGH(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITUCA1_TUCA_HIGH_SHIFT)) & ENETC_VSI_SITUCA1_TUCA_HIGH_MASK)
/*! @} */

/*! @name SITMCA0 - Station interface transmit multicast frame counter (ifOutMulticastPkts) 0 */
/*! @{ */

#define ENETC_VSI_SITMCA0_TMCA_LOW_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SITMCA0_TMCA_LOW_SHIFT         (0U)
#define ENETC_VSI_SITMCA0_TMCA_LOW_WIDTH         (32U)
#define ENETC_VSI_SITMCA0_TMCA_LOW(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITMCA0_TMCA_LOW_SHIFT)) & ENETC_VSI_SITMCA0_TMCA_LOW_MASK)
/*! @} */

/*! @name SITMCA1 - Station interface transmit multicast frame counter (ifOutMulticastPkts) 1 */
/*! @{ */

#define ENETC_VSI_SITMCA1_TMCA_HIGH_MASK         (0xFFFFFFFFU)
#define ENETC_VSI_SITMCA1_TMCA_HIGH_SHIFT        (0U)
#define ENETC_VSI_SITMCA1_TMCA_HIGH_WIDTH        (32U)
#define ENETC_VSI_SITMCA1_TMCA_HIGH(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITMCA1_TMCA_HIGH_SHIFT)) & ENETC_VSI_SITMCA1_TMCA_HIGH_MASK)
/*! @} */

/*! @name SITDFCR - Station interface transmit discard frame counter */
/*! @{ */

#define ENETC_VSI_SITDFCR_COUNT_MASK             (0xFFFFFFFFU)
#define ENETC_VSI_SITDFCR_COUNT_SHIFT            (0U)
#define ENETC_VSI_SITDFCR_COUNT_WIDTH            (32U)
#define ENETC_VSI_SITDFCR_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITDFCR_COUNT_SHIFT)) & ENETC_VSI_SITDFCR_COUNT_MASK)
/*! @} */

/*! @name SIBLPR - Station interface boot loader parameter register 0..Station interface boot loader parameter register 1 */
/*! @{ */

#define ENETC_VSI_SIBLPR_PARAM_VAL_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SIBLPR_PARAM_VAL_SHIFT         (0U)
#define ENETC_VSI_SIBLPR_PARAM_VAL_WIDTH         (32U)
#define ENETC_VSI_SIBLPR_PARAM_VAL(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIBLPR_PARAM_VAL_SHIFT)) & ENETC_VSI_SIBLPR_PARAM_VAL_MASK)
/*! @} */

/*! @name SICBDRMR - Station interface command BDR mode register */
/*! @{ */

#define ENETC_VSI_SICBDRMR_EN_MASK               (0x80000000U)
#define ENETC_VSI_SICBDRMR_EN_SHIFT              (31U)
#define ENETC_VSI_SICBDRMR_EN_WIDTH              (1U)
#define ENETC_VSI_SICBDRMR_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICBDRMR_EN_SHIFT)) & ENETC_VSI_SICBDRMR_EN_MASK)
/*! @} */

/*! @name SICBDRSR - Station interface command BDR status register */
/*! @{ */

#define ENETC_VSI_SICBDRSR_BUSY_MASK             (0x1U)
#define ENETC_VSI_SICBDRSR_BUSY_SHIFT            (0U)
#define ENETC_VSI_SICBDRSR_BUSY_WIDTH            (1U)
#define ENETC_VSI_SICBDRSR_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICBDRSR_BUSY_SHIFT)) & ENETC_VSI_SICBDRSR_BUSY_MASK)
/*! @} */

/*! @name SICBDRBAR0 - Station interface command BDR base address register 0 */
/*! @{ */

#define ENETC_VSI_SICBDRBAR0_ADDRL_MASK          (0xFFFFFF80U)
#define ENETC_VSI_SICBDRBAR0_ADDRL_SHIFT         (7U)
#define ENETC_VSI_SICBDRBAR0_ADDRL_WIDTH         (25U)
#define ENETC_VSI_SICBDRBAR0_ADDRL(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICBDRBAR0_ADDRL_SHIFT)) & ENETC_VSI_SICBDRBAR0_ADDRL_MASK)
/*! @} */

/*! @name SICBDRBAR1 - Station interface command BDR base address register 1 */
/*! @{ */

#define ENETC_VSI_SICBDRBAR1_ADDRH_MASK          (0xFFFFFFFFU)
#define ENETC_VSI_SICBDRBAR1_ADDRH_SHIFT         (0U)
#define ENETC_VSI_SICBDRBAR1_ADDRH_WIDTH         (32U)
#define ENETC_VSI_SICBDRBAR1_ADDRH(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICBDRBAR1_ADDRH_SHIFT)) & ENETC_VSI_SICBDRBAR1_ADDRH_MASK)
/*! @} */

/*! @name SICBDRPIR - Station interface command BDR producer index register */
/*! @{ */

#define ENETC_VSI_SICBDRPIR_BDR_INDEX_MASK       (0x3FFU)
#define ENETC_VSI_SICBDRPIR_BDR_INDEX_SHIFT      (0U)
#define ENETC_VSI_SICBDRPIR_BDR_INDEX_WIDTH      (10U)
#define ENETC_VSI_SICBDRPIR_BDR_INDEX(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICBDRPIR_BDR_INDEX_SHIFT)) & ENETC_VSI_SICBDRPIR_BDR_INDEX_MASK)
/*! @} */

/*! @name SICBDRCIR - Station interface command BDR consumer index register */
/*! @{ */

#define ENETC_VSI_SICBDRCIR_BDR_INDEX_MASK       (0x3FFU)
#define ENETC_VSI_SICBDRCIR_BDR_INDEX_SHIFT      (0U)
#define ENETC_VSI_SICBDRCIR_BDR_INDEX_WIDTH      (10U)
#define ENETC_VSI_SICBDRCIR_BDR_INDEX(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICBDRCIR_BDR_INDEX_SHIFT)) & ENETC_VSI_SICBDRCIR_BDR_INDEX_MASK)

#define ENETC_VSI_SICBDRCIR_SBE_MASK             (0x80000000U)
#define ENETC_VSI_SICBDRCIR_SBE_SHIFT            (31U)
#define ENETC_VSI_SICBDRCIR_SBE_WIDTH            (1U)
#define ENETC_VSI_SICBDRCIR_SBE(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICBDRCIR_SBE_SHIFT)) & ENETC_VSI_SICBDRCIR_SBE_MASK)
/*! @} */

/*! @name SICBDRLENR - Station interface command BDR length register */
/*! @{ */

#define ENETC_VSI_SICBDRLENR_LENGTH_MASK         (0x7F8U)
#define ENETC_VSI_SICBDRLENR_LENGTH_SHIFT        (3U)
#define ENETC_VSI_SICBDRLENR_LENGTH_WIDTH        (8U)
#define ENETC_VSI_SICBDRLENR_LENGTH(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICBDRLENR_LENGTH_SHIFT)) & ENETC_VSI_SICBDRLENR_LENGTH_MASK)
/*! @} */

/*! @name SICBDRIER - Station interface command BDR interrupt enable register */
/*! @{ */

#define ENETC_VSI_SICBDRIER_CBDCIE_MASK          (0x1U)
#define ENETC_VSI_SICBDRIER_CBDCIE_SHIFT         (0U)
#define ENETC_VSI_SICBDRIER_CBDCIE_WIDTH         (1U)
#define ENETC_VSI_SICBDRIER_CBDCIE(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICBDRIER_CBDCIE_SHIFT)) & ENETC_VSI_SICBDRIER_CBDCIE_MASK)
/*! @} */

/*! @name SICBDRIDR - Station interface command BDR interrupt detect register */
/*! @{ */

#define ENETC_VSI_SICBDRIDR_CBDC_MASK            (0x1U)
#define ENETC_VSI_SICBDRIDR_CBDC_SHIFT           (0U)
#define ENETC_VSI_SICBDRIDR_CBDC_WIDTH           (1U)
#define ENETC_VSI_SICBDRIDR_CBDC(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICBDRIDR_CBDC_SHIFT)) & ENETC_VSI_SICBDRIDR_CBDC_MASK)
/*! @} */

/*! @name SICAPR0 - Station interface capability register 0 */
/*! @{ */

#define ENETC_VSI_SICAPR0_NUM_TX_BDR_MASK        (0xFFU)
#define ENETC_VSI_SICAPR0_NUM_TX_BDR_SHIFT       (0U)
#define ENETC_VSI_SICAPR0_NUM_TX_BDR_WIDTH       (8U)
#define ENETC_VSI_SICAPR0_NUM_TX_BDR(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICAPR0_NUM_TX_BDR_SHIFT)) & ENETC_VSI_SICAPR0_NUM_TX_BDR_MASK)

#define ENETC_VSI_SICAPR0_NUM_RX_BDR_MASK        (0xFF0000U)
#define ENETC_VSI_SICAPR0_NUM_RX_BDR_SHIFT       (16U)
#define ENETC_VSI_SICAPR0_NUM_RX_BDR_WIDTH       (8U)
#define ENETC_VSI_SICAPR0_NUM_RX_BDR(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICAPR0_NUM_RX_BDR_SHIFT)) & ENETC_VSI_SICAPR0_NUM_RX_BDR_MASK)
/*! @} */

/*! @name SICAPR1 - Station interface capability register 1 */
/*! @{ */

#define ENETC_VSI_SICAPR1_NUM_RX_GRP_MASK        (0xFF0000U)
#define ENETC_VSI_SICAPR1_NUM_RX_GRP_SHIFT       (16U)
#define ENETC_VSI_SICAPR1_NUM_RX_GRP_WIDTH       (8U)
#define ENETC_VSI_SICAPR1_NUM_RX_GRP(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICAPR1_NUM_RX_GRP_SHIFT)) & ENETC_VSI_SICAPR1_NUM_RX_GRP_MASK)
/*! @} */

/*! @name SICAPR2 - Station interface capability register 2 */
/*! @{ */

#define ENETC_VSI_SICAPR2_VTP_MASK               (0xFU)
#define ENETC_VSI_SICAPR2_VTP_SHIFT              (0U)
#define ENETC_VSI_SICAPR2_VTP_WIDTH              (4U)
#define ENETC_VSI_SICAPR2_VTP(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICAPR2_VTP_SHIFT)) & ENETC_VSI_SICAPR2_VTP_MASK)
/*! @} */

/*! @name VSIIER - Virtual station interface interrupt enable register */
/*! @{ */

#define ENETC_VSI_VSIIER_MSIE_MASK               (0x100U)
#define ENETC_VSI_VSIIER_MSIE_SHIFT              (8U)
#define ENETC_VSI_VSIIER_MSIE_WIDTH              (1U)
#define ENETC_VSI_VSIIER_MSIE(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIIER_MSIE_SHIFT)) & ENETC_VSI_VSIIER_MSIE_MASK)

#define ENETC_VSI_VSIIER_MRIE_MASK               (0x200U)
#define ENETC_VSI_VSIIER_MRIE_SHIFT              (9U)
#define ENETC_VSI_VSIIER_MRIE_WIDTH              (1U)
#define ENETC_VSI_VSIIER_MRIE(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIIER_MRIE_SHIFT)) & ENETC_VSI_VSIIER_MRIE_MASK)
/*! @} */

/*! @name VSIIDR - Virtual station interface interrupt detect register */
/*! @{ */

#define ENETC_VSI_VSIIDR_TXR_MASK                (0x1U)
#define ENETC_VSI_VSIIDR_TXR_SHIFT               (0U)
#define ENETC_VSI_VSIIDR_TXR_WIDTH               (1U)
#define ENETC_VSI_VSIIDR_TXR(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIIDR_TXR_SHIFT)) & ENETC_VSI_VSIIDR_TXR_MASK)

#define ENETC_VSI_VSIIDR_MS_MASK                 (0x100U)
#define ENETC_VSI_VSIIDR_MS_SHIFT                (8U)
#define ENETC_VSI_VSIIDR_MS_WIDTH                (1U)
#define ENETC_VSI_VSIIDR_MS(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIIDR_MS_SHIFT)) & ENETC_VSI_VSIIDR_MS_MASK)

#define ENETC_VSI_VSIIDR_MR_MASK                 (0x200U)
#define ENETC_VSI_VSIIDR_MR_SHIFT                (9U)
#define ENETC_VSI_VSIIDR_MR_WIDTH                (1U)
#define ENETC_VSI_VSIIDR_MR(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIIDR_MR_SHIFT)) & ENETC_VSI_VSIIDR_MR_MASK)

#define ENETC_VSI_VSIIDR_RXR_MASK                (0x10000U)
#define ENETC_VSI_VSIIDR_RXR_SHIFT               (16U)
#define ENETC_VSI_VSIIDR_RXR_WIDTH               (1U)
#define ENETC_VSI_VSIIDR_RXR(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_VSIIDR_RXR_SHIFT)) & ENETC_VSI_VSIIDR_RXR_MASK)
/*! @} */

/*! @name SITXIDR0 - Station interface transmit interrupt detect register 0 */
/*! @{ */

#define ENETC_VSI_SITXIDR0_TXT0_MASK             (0x1U)
#define ENETC_VSI_SITXIDR0_TXT0_SHIFT            (0U)
#define ENETC_VSI_SITXIDR0_TXT0_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXT0(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT0_SHIFT)) & ENETC_VSI_SITXIDR0_TXT0_MASK)

#define ENETC_VSI_SITXIDR0_TXT1_MASK             (0x2U)
#define ENETC_VSI_SITXIDR0_TXT1_SHIFT            (1U)
#define ENETC_VSI_SITXIDR0_TXT1_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXT1(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT1_SHIFT)) & ENETC_VSI_SITXIDR0_TXT1_MASK)

#define ENETC_VSI_SITXIDR0_TXT2_MASK             (0x4U)
#define ENETC_VSI_SITXIDR0_TXT2_SHIFT            (2U)
#define ENETC_VSI_SITXIDR0_TXT2_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXT2(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT2_SHIFT)) & ENETC_VSI_SITXIDR0_TXT2_MASK)

#define ENETC_VSI_SITXIDR0_TXT3_MASK             (0x8U)
#define ENETC_VSI_SITXIDR0_TXT3_SHIFT            (3U)
#define ENETC_VSI_SITXIDR0_TXT3_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXT3(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT3_SHIFT)) & ENETC_VSI_SITXIDR0_TXT3_MASK)

#define ENETC_VSI_SITXIDR0_TXT4_MASK             (0x10U)
#define ENETC_VSI_SITXIDR0_TXT4_SHIFT            (4U)
#define ENETC_VSI_SITXIDR0_TXT4_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXT4(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT4_SHIFT)) & ENETC_VSI_SITXIDR0_TXT4_MASK)

#define ENETC_VSI_SITXIDR0_TXT5_MASK             (0x20U)
#define ENETC_VSI_SITXIDR0_TXT5_SHIFT            (5U)
#define ENETC_VSI_SITXIDR0_TXT5_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXT5(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT5_SHIFT)) & ENETC_VSI_SITXIDR0_TXT5_MASK)

#define ENETC_VSI_SITXIDR0_TXT6_MASK             (0x40U)
#define ENETC_VSI_SITXIDR0_TXT6_SHIFT            (6U)
#define ENETC_VSI_SITXIDR0_TXT6_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXT6(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT6_SHIFT)) & ENETC_VSI_SITXIDR0_TXT6_MASK)

#define ENETC_VSI_SITXIDR0_TXT7_MASK             (0x80U)
#define ENETC_VSI_SITXIDR0_TXT7_SHIFT            (7U)
#define ENETC_VSI_SITXIDR0_TXT7_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXT7(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT7_SHIFT)) & ENETC_VSI_SITXIDR0_TXT7_MASK)

#define ENETC_VSI_SITXIDR0_TXT8_MASK             (0x100U)
#define ENETC_VSI_SITXIDR0_TXT8_SHIFT            (8U)
#define ENETC_VSI_SITXIDR0_TXT8_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXT8(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT8_SHIFT)) & ENETC_VSI_SITXIDR0_TXT8_MASK)

#define ENETC_VSI_SITXIDR0_TXT9_MASK             (0x200U)
#define ENETC_VSI_SITXIDR0_TXT9_SHIFT            (9U)
#define ENETC_VSI_SITXIDR0_TXT9_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXT9(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT9_SHIFT)) & ENETC_VSI_SITXIDR0_TXT9_MASK)

#define ENETC_VSI_SITXIDR0_TXT10_MASK            (0x400U)
#define ENETC_VSI_SITXIDR0_TXT10_SHIFT           (10U)
#define ENETC_VSI_SITXIDR0_TXT10_WIDTH           (1U)
#define ENETC_VSI_SITXIDR0_TXT10(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT10_SHIFT)) & ENETC_VSI_SITXIDR0_TXT10_MASK)

#define ENETC_VSI_SITXIDR0_TXT11_MASK            (0x800U)
#define ENETC_VSI_SITXIDR0_TXT11_SHIFT           (11U)
#define ENETC_VSI_SITXIDR0_TXT11_WIDTH           (1U)
#define ENETC_VSI_SITXIDR0_TXT11(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT11_SHIFT)) & ENETC_VSI_SITXIDR0_TXT11_MASK)

#define ENETC_VSI_SITXIDR0_TXT12_MASK            (0x1000U)
#define ENETC_VSI_SITXIDR0_TXT12_SHIFT           (12U)
#define ENETC_VSI_SITXIDR0_TXT12_WIDTH           (1U)
#define ENETC_VSI_SITXIDR0_TXT12(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT12_SHIFT)) & ENETC_VSI_SITXIDR0_TXT12_MASK)

#define ENETC_VSI_SITXIDR0_TXT13_MASK            (0x2000U)
#define ENETC_VSI_SITXIDR0_TXT13_SHIFT           (13U)
#define ENETC_VSI_SITXIDR0_TXT13_WIDTH           (1U)
#define ENETC_VSI_SITXIDR0_TXT13(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXT13_SHIFT)) & ENETC_VSI_SITXIDR0_TXT13_MASK)

#define ENETC_VSI_SITXIDR0_TXF0_MASK             (0x10000U)
#define ENETC_VSI_SITXIDR0_TXF0_SHIFT            (16U)
#define ENETC_VSI_SITXIDR0_TXF0_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXF0(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF0_SHIFT)) & ENETC_VSI_SITXIDR0_TXF0_MASK)

#define ENETC_VSI_SITXIDR0_TXF1_MASK             (0x20000U)
#define ENETC_VSI_SITXIDR0_TXF1_SHIFT            (17U)
#define ENETC_VSI_SITXIDR0_TXF1_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXF1(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF1_SHIFT)) & ENETC_VSI_SITXIDR0_TXF1_MASK)

#define ENETC_VSI_SITXIDR0_TXF2_MASK             (0x40000U)
#define ENETC_VSI_SITXIDR0_TXF2_SHIFT            (18U)
#define ENETC_VSI_SITXIDR0_TXF2_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXF2(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF2_SHIFT)) & ENETC_VSI_SITXIDR0_TXF2_MASK)

#define ENETC_VSI_SITXIDR0_TXF3_MASK             (0x80000U)
#define ENETC_VSI_SITXIDR0_TXF3_SHIFT            (19U)
#define ENETC_VSI_SITXIDR0_TXF3_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXF3(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF3_SHIFT)) & ENETC_VSI_SITXIDR0_TXF3_MASK)

#define ENETC_VSI_SITXIDR0_TXF4_MASK             (0x100000U)
#define ENETC_VSI_SITXIDR0_TXF4_SHIFT            (20U)
#define ENETC_VSI_SITXIDR0_TXF4_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXF4(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF4_SHIFT)) & ENETC_VSI_SITXIDR0_TXF4_MASK)

#define ENETC_VSI_SITXIDR0_TXF5_MASK             (0x200000U)
#define ENETC_VSI_SITXIDR0_TXF5_SHIFT            (21U)
#define ENETC_VSI_SITXIDR0_TXF5_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXF5(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF5_SHIFT)) & ENETC_VSI_SITXIDR0_TXF5_MASK)

#define ENETC_VSI_SITXIDR0_TXF6_MASK             (0x400000U)
#define ENETC_VSI_SITXIDR0_TXF6_SHIFT            (22U)
#define ENETC_VSI_SITXIDR0_TXF6_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXF6(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF6_SHIFT)) & ENETC_VSI_SITXIDR0_TXF6_MASK)

#define ENETC_VSI_SITXIDR0_TXF7_MASK             (0x800000U)
#define ENETC_VSI_SITXIDR0_TXF7_SHIFT            (23U)
#define ENETC_VSI_SITXIDR0_TXF7_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXF7(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF7_SHIFT)) & ENETC_VSI_SITXIDR0_TXF7_MASK)

#define ENETC_VSI_SITXIDR0_TXF8_MASK             (0x1000000U)
#define ENETC_VSI_SITXIDR0_TXF8_SHIFT            (24U)
#define ENETC_VSI_SITXIDR0_TXF8_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXF8(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF8_SHIFT)) & ENETC_VSI_SITXIDR0_TXF8_MASK)

#define ENETC_VSI_SITXIDR0_TXF9_MASK             (0x2000000U)
#define ENETC_VSI_SITXIDR0_TXF9_SHIFT            (25U)
#define ENETC_VSI_SITXIDR0_TXF9_WIDTH            (1U)
#define ENETC_VSI_SITXIDR0_TXF9(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF9_SHIFT)) & ENETC_VSI_SITXIDR0_TXF9_MASK)

#define ENETC_VSI_SITXIDR0_TXF10_MASK            (0x4000000U)
#define ENETC_VSI_SITXIDR0_TXF10_SHIFT           (26U)
#define ENETC_VSI_SITXIDR0_TXF10_WIDTH           (1U)
#define ENETC_VSI_SITXIDR0_TXF10(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF10_SHIFT)) & ENETC_VSI_SITXIDR0_TXF10_MASK)

#define ENETC_VSI_SITXIDR0_TXF11_MASK            (0x8000000U)
#define ENETC_VSI_SITXIDR0_TXF11_SHIFT           (27U)
#define ENETC_VSI_SITXIDR0_TXF11_WIDTH           (1U)
#define ENETC_VSI_SITXIDR0_TXF11(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF11_SHIFT)) & ENETC_VSI_SITXIDR0_TXF11_MASK)

#define ENETC_VSI_SITXIDR0_TXF12_MASK            (0x10000000U)
#define ENETC_VSI_SITXIDR0_TXF12_SHIFT           (28U)
#define ENETC_VSI_SITXIDR0_TXF12_WIDTH           (1U)
#define ENETC_VSI_SITXIDR0_TXF12(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF12_SHIFT)) & ENETC_VSI_SITXIDR0_TXF12_MASK)

#define ENETC_VSI_SITXIDR0_TXF13_MASK            (0x20000000U)
#define ENETC_VSI_SITXIDR0_TXF13_SHIFT           (29U)
#define ENETC_VSI_SITXIDR0_TXF13_WIDTH           (1U)
#define ENETC_VSI_SITXIDR0_TXF13(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITXIDR0_TXF13_SHIFT)) & ENETC_VSI_SITXIDR0_TXF13_MASK)
/*! @} */

/*! @name SIRXIDR0 - Station interface receive interrupt detect register 0 */
/*! @{ */

#define ENETC_VSI_SIRXIDR0_RX0_MASK              (0x1U)
#define ENETC_VSI_SIRXIDR0_RX0_SHIFT             (0U)
#define ENETC_VSI_SIRXIDR0_RX0_WIDTH             (1U)
#define ENETC_VSI_SIRXIDR0_RX0(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX0_SHIFT)) & ENETC_VSI_SIRXIDR0_RX0_MASK)

#define ENETC_VSI_SIRXIDR0_RX1_MASK              (0x2U)
#define ENETC_VSI_SIRXIDR0_RX1_SHIFT             (1U)
#define ENETC_VSI_SIRXIDR0_RX1_WIDTH             (1U)
#define ENETC_VSI_SIRXIDR0_RX1(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX1_SHIFT)) & ENETC_VSI_SIRXIDR0_RX1_MASK)

#define ENETC_VSI_SIRXIDR0_RX2_MASK              (0x4U)
#define ENETC_VSI_SIRXIDR0_RX2_SHIFT             (2U)
#define ENETC_VSI_SIRXIDR0_RX2_WIDTH             (1U)
#define ENETC_VSI_SIRXIDR0_RX2(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX2_SHIFT)) & ENETC_VSI_SIRXIDR0_RX2_MASK)

#define ENETC_VSI_SIRXIDR0_RX3_MASK              (0x8U)
#define ENETC_VSI_SIRXIDR0_RX3_SHIFT             (3U)
#define ENETC_VSI_SIRXIDR0_RX3_WIDTH             (1U)
#define ENETC_VSI_SIRXIDR0_RX3(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX3_SHIFT)) & ENETC_VSI_SIRXIDR0_RX3_MASK)

#define ENETC_VSI_SIRXIDR0_RX4_MASK              (0x10U)
#define ENETC_VSI_SIRXIDR0_RX4_SHIFT             (4U)
#define ENETC_VSI_SIRXIDR0_RX4_WIDTH             (1U)
#define ENETC_VSI_SIRXIDR0_RX4(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX4_SHIFT)) & ENETC_VSI_SIRXIDR0_RX4_MASK)

#define ENETC_VSI_SIRXIDR0_RX5_MASK              (0x20U)
#define ENETC_VSI_SIRXIDR0_RX5_SHIFT             (5U)
#define ENETC_VSI_SIRXIDR0_RX5_WIDTH             (1U)
#define ENETC_VSI_SIRXIDR0_RX5(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX5_SHIFT)) & ENETC_VSI_SIRXIDR0_RX5_MASK)

#define ENETC_VSI_SIRXIDR0_RX6_MASK              (0x40U)
#define ENETC_VSI_SIRXIDR0_RX6_SHIFT             (6U)
#define ENETC_VSI_SIRXIDR0_RX6_WIDTH             (1U)
#define ENETC_VSI_SIRXIDR0_RX6(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX6_SHIFT)) & ENETC_VSI_SIRXIDR0_RX6_MASK)

#define ENETC_VSI_SIRXIDR0_RX7_MASK              (0x80U)
#define ENETC_VSI_SIRXIDR0_RX7_SHIFT             (7U)
#define ENETC_VSI_SIRXIDR0_RX7_WIDTH             (1U)
#define ENETC_VSI_SIRXIDR0_RX7(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX7_SHIFT)) & ENETC_VSI_SIRXIDR0_RX7_MASK)

#define ENETC_VSI_SIRXIDR0_RX8_MASK              (0x100U)
#define ENETC_VSI_SIRXIDR0_RX8_SHIFT             (8U)
#define ENETC_VSI_SIRXIDR0_RX8_WIDTH             (1U)
#define ENETC_VSI_SIRXIDR0_RX8(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX8_SHIFT)) & ENETC_VSI_SIRXIDR0_RX8_MASK)

#define ENETC_VSI_SIRXIDR0_RX9_MASK              (0x200U)
#define ENETC_VSI_SIRXIDR0_RX9_SHIFT             (9U)
#define ENETC_VSI_SIRXIDR0_RX9_WIDTH             (1U)
#define ENETC_VSI_SIRXIDR0_RX9(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX9_SHIFT)) & ENETC_VSI_SIRXIDR0_RX9_MASK)

#define ENETC_VSI_SIRXIDR0_RX10_MASK             (0x400U)
#define ENETC_VSI_SIRXIDR0_RX10_SHIFT            (10U)
#define ENETC_VSI_SIRXIDR0_RX10_WIDTH            (1U)
#define ENETC_VSI_SIRXIDR0_RX10(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX10_SHIFT)) & ENETC_VSI_SIRXIDR0_RX10_MASK)

#define ENETC_VSI_SIRXIDR0_RX11_MASK             (0x800U)
#define ENETC_VSI_SIRXIDR0_RX11_SHIFT            (11U)
#define ENETC_VSI_SIRXIDR0_RX11_WIDTH            (1U)
#define ENETC_VSI_SIRXIDR0_RX11(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX11_SHIFT)) & ENETC_VSI_SIRXIDR0_RX11_MASK)

#define ENETC_VSI_SIRXIDR0_RX12_MASK             (0x1000U)
#define ENETC_VSI_SIRXIDR0_RX12_SHIFT            (12U)
#define ENETC_VSI_SIRXIDR0_RX12_WIDTH            (1U)
#define ENETC_VSI_SIRXIDR0_RX12(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX12_SHIFT)) & ENETC_VSI_SIRXIDR0_RX12_MASK)

#define ENETC_VSI_SIRXIDR0_RX13_MASK             (0x2000U)
#define ENETC_VSI_SIRXIDR0_RX13_SHIFT            (13U)
#define ENETC_VSI_SIRXIDR0_RX13_WIDTH            (1U)
#define ENETC_VSI_SIRXIDR0_RX13(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRXIDR0_RX13_SHIFT)) & ENETC_VSI_SIRXIDR0_RX13_MASK)
/*! @} */

/*! @name SIMSIVR - Station interface MSI-X vector register */
/*! @{ */

#define ENETC_VSI_SIMSIVR_VECTOR_MASK            (0x3FU)
#define ENETC_VSI_SIMSIVR_VECTOR_SHIFT           (0U)
#define ENETC_VSI_SIMSIVR_VECTOR_WIDTH           (6U)
#define ENETC_VSI_SIMSIVR_VECTOR(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMSIVR_VECTOR_SHIFT)) & ENETC_VSI_SIMSIVR_VECTOR_MASK)
/*! @} */

/*! @name SICMSIVR - Station interface command MSI-X vector register */
/*! @{ */

#define ENETC_VSI_SICMSIVR_VECTOR_MASK           (0x3FU)
#define ENETC_VSI_SICMSIVR_VECTOR_SHIFT          (0U)
#define ENETC_VSI_SICMSIVR_VECTOR_WIDTH          (6U)
#define ENETC_VSI_SICMSIVR_VECTOR(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICMSIVR_VECTOR_SHIFT)) & ENETC_VSI_SICMSIVR_VECTOR_MASK)
/*! @} */

/*! @name SITMRIER - Station interface timer interrupt enable register */
/*! @{ */

#define ENETC_VSI_SITMRIER_SYNCE_MASK            (0x1U)
#define ENETC_VSI_SITMRIER_SYNCE_SHIFT           (0U)
#define ENETC_VSI_SITMRIER_SYNCE_WIDTH           (1U)
#define ENETC_VSI_SITMRIER_SYNCE(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITMRIER_SYNCE_SHIFT)) & ENETC_VSI_SITMRIER_SYNCE_MASK)
/*! @} */

/*! @name SITMRIDR - Station interface timer interrupt detect register */
/*! @{ */

#define ENETC_VSI_SITMRIDR_SYNC_MASK             (0x1U)
#define ENETC_VSI_SITMRIDR_SYNC_SHIFT            (0U)
#define ENETC_VSI_SITMRIDR_SYNC_WIDTH            (1U)
#define ENETC_VSI_SITMRIDR_SYNC(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITMRIDR_SYNC_SHIFT)) & ENETC_VSI_SITMRIDR_SYNC_MASK)
/*! @} */

/*! @name SITMRMSIVR - Station interface timer MSI-X vector register */
/*! @{ */

#define ENETC_VSI_SITMRMSIVR_VECTOR_MASK         (0x3FU)
#define ENETC_VSI_SITMRMSIVR_VECTOR_SHIFT        (0U)
#define ENETC_VSI_SITMRMSIVR_VECTOR_WIDTH        (6U)
#define ENETC_VSI_SITMRMSIVR_VECTOR(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SITMRMSIVR_VECTOR_SHIFT)) & ENETC_VSI_SITMRMSIVR_VECTOR_MASK)
/*! @} */

/*! @name SIMSITRVR - Station interface MSI-X transmit ring 0 vector register..Station interface MSI-X transmit ring 13 vector register */
/*! @{ */

#define ENETC_VSI_SIMSITRVR_VECTOR_MASK          (0x3FU)
#define ENETC_VSI_SIMSITRVR_VECTOR_SHIFT         (0U)
#define ENETC_VSI_SIMSITRVR_VECTOR_WIDTH         (6U)
#define ENETC_VSI_SIMSITRVR_VECTOR(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMSITRVR_VECTOR_SHIFT)) & ENETC_VSI_SIMSITRVR_VECTOR_MASK)
/*! @} */

/*! @name SIMSIRRVR - Station interface MSI-X receive ring 0 vector register..Station interface MSI-X receive ring 13 vector register */
/*! @{ */

#define ENETC_VSI_SIMSIRRVR_VECTOR_MASK          (0x3FU)
#define ENETC_VSI_SIMSIRRVR_VECTOR_SHIFT         (0U)
#define ENETC_VSI_SIMSIRRVR_VECTOR_WIDTH         (6U)
#define ENETC_VSI_SIMSIRRVR_VECTOR(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMSIRRVR_VECTOR_SHIFT)) & ENETC_VSI_SIMSIRRVR_VECTOR_MASK)
/*! @} */

/*! @name SICMECR - Station interface correctable memory error configuration register */
/*! @{ */

#define ENETC_VSI_SICMECR_THRESHOLD_MASK         (0xFFU)
#define ENETC_VSI_SICMECR_THRESHOLD_SHIFT        (0U)
#define ENETC_VSI_SICMECR_THRESHOLD_WIDTH        (8U)
#define ENETC_VSI_SICMECR_THRESHOLD(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICMECR_THRESHOLD_SHIFT)) & ENETC_VSI_SICMECR_THRESHOLD_MASK)
/*! @} */

/*! @name SICMESR - Station interface correctable memory error status register */
/*! @{ */

#define ENETC_VSI_SICMESR_LINK_SLICE_ID_MASK     (0x1FU)
#define ENETC_VSI_SICMESR_LINK_SLICE_ID_SHIFT    (0U)
#define ENETC_VSI_SICMESR_LINK_SLICE_ID_WIDTH    (5U)
#define ENETC_VSI_SICMESR_LINK_SLICE_ID(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICMESR_LINK_SLICE_ID_SHIFT)) & ENETC_VSI_SICMESR_LINK_SLICE_ID_MASK)

#define ENETC_VSI_SICMESR_MEM_ID_MASK            (0x1F00U)
#define ENETC_VSI_SICMESR_MEM_ID_SHIFT           (8U)
#define ENETC_VSI_SICMESR_MEM_ID_WIDTH           (5U)
#define ENETC_VSI_SICMESR_MEM_ID(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICMESR_MEM_ID_SHIFT)) & ENETC_VSI_SICMESR_MEM_ID_MASK)

#define ENETC_VSI_SICMESR_SBEE_MASK              (0x80000000U)
#define ENETC_VSI_SICMESR_SBEE_SHIFT             (31U)
#define ENETC_VSI_SICMESR_SBEE_WIDTH             (1U)
#define ENETC_VSI_SICMESR_SBEE(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICMESR_SBEE_SHIFT)) & ENETC_VSI_SICMESR_SBEE_MASK)
/*! @} */

/*! @name SICMECTR - Station interface correctable memory error count register */
/*! @{ */

#define ENETC_VSI_SICMECTR_COUNT_MASK            (0xFFU)
#define ENETC_VSI_SICMECTR_COUNT_SHIFT           (0U)
#define ENETC_VSI_SICMECTR_COUNT_WIDTH           (8U)
#define ENETC_VSI_SICMECTR_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SICMECTR_COUNT_SHIFT)) & ENETC_VSI_SICMECTR_COUNT_MASK)
/*! @} */

/*! @name SIUPECR - Station interface uncorrectable programming error configuration register */
/*! @{ */

#define ENETC_VSI_SIUPECR_RD_MASK                (0x80000000U)
#define ENETC_VSI_SIUPECR_RD_SHIFT               (31U)
#define ENETC_VSI_SIUPECR_RD_WIDTH               (1U)
#define ENETC_VSI_SIUPECR_RD(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUPECR_RD_SHIFT)) & ENETC_VSI_SIUPECR_RD_MASK)
/*! @} */

/*! @name SIUPESR - Station interface uncorrectable programming error status register */
/*! @{ */

#define ENETC_VSI_SIUPESR_DROP_SI_EN_MASK        (0x1U)
#define ENETC_VSI_SIUPESR_DROP_SI_EN_SHIFT       (0U)
#define ENETC_VSI_SIUPESR_DROP_SI_EN_WIDTH       (1U)
#define ENETC_VSI_SIUPESR_DROP_SI_EN(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUPESR_DROP_SI_EN_SHIFT)) & ENETC_VSI_SIUPESR_DROP_SI_EN_MASK)

#define ENETC_VSI_SIUPESR_DROP_RING_EN_MASK      (0x2U)
#define ENETC_VSI_SIUPESR_DROP_RING_EN_SHIFT     (1U)
#define ENETC_VSI_SIUPESR_DROP_RING_EN_WIDTH     (1U)
#define ENETC_VSI_SIUPESR_DROP_RING_EN(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUPESR_DROP_RING_EN_SHIFT)) & ENETC_VSI_SIUPESR_DROP_RING_EN_MASK)

#define ENETC_VSI_SIUPESR_DROP_GRP_SEL_MASK      (0x4U)
#define ENETC_VSI_SIUPESR_DROP_GRP_SEL_SHIFT     (2U)
#define ENETC_VSI_SIUPESR_DROP_GRP_SEL_WIDTH     (1U)
#define ENETC_VSI_SIUPESR_DROP_GRP_SEL(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUPESR_DROP_GRP_SEL_SHIFT)) & ENETC_VSI_SIUPESR_DROP_GRP_SEL_MASK)

#define ENETC_VSI_SIUPESR_DROP_RING_SEL_MASK     (0x8U)
#define ENETC_VSI_SIUPESR_DROP_RING_SEL_SHIFT    (3U)
#define ENETC_VSI_SIUPESR_DROP_RING_SEL_WIDTH    (1U)
#define ENETC_VSI_SIUPESR_DROP_RING_SEL(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUPESR_DROP_RING_SEL_SHIFT)) & ENETC_VSI_SIUPESR_DROP_RING_SEL_MASK)

#define ENETC_VSI_SIUPESR_M_MASK                 (0x40000000U)
#define ENETC_VSI_SIUPESR_M_SHIFT                (30U)
#define ENETC_VSI_SIUPESR_M_WIDTH                (1U)
#define ENETC_VSI_SIUPESR_M(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUPESR_M_SHIFT)) & ENETC_VSI_SIUPESR_M_MASK)

#define ENETC_VSI_SIUPESR_PE_MASK                (0x80000000U)
#define ENETC_VSI_SIUPESR_PE_SHIFT               (31U)
#define ENETC_VSI_SIUPESR_PE_WIDTH               (1U)
#define ENETC_VSI_SIUPESR_PE(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUPESR_PE_SHIFT)) & ENETC_VSI_SIUPESR_PE_MASK)
/*! @} */

/*! @name SIUPECTR - Station interface uncorrectable programming error count register */
/*! @{ */

#define ENETC_VSI_SIUPECTR_COUNT_MASK            (0xFFFFFFFFU)
#define ENETC_VSI_SIUPECTR_COUNT_SHIFT           (0U)
#define ENETC_VSI_SIUPECTR_COUNT_WIDTH           (32U)
#define ENETC_VSI_SIUPECTR_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUPECTR_COUNT_SHIFT)) & ENETC_VSI_SIUPECTR_COUNT_MASK)
/*! @} */

/*! @name SIUNSBECR - Station interface uncorrectable non-fatal system bus error configuration register */
/*! @{ */

#define ENETC_VSI_SIUNSBECR_THRESHOLD_MASK       (0xFFU)
#define ENETC_VSI_SIUNSBECR_THRESHOLD_SHIFT      (0U)
#define ENETC_VSI_SIUNSBECR_THRESHOLD_WIDTH      (8U)
#define ENETC_VSI_SIUNSBECR_THRESHOLD(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNSBECR_THRESHOLD_SHIFT)) & ENETC_VSI_SIUNSBECR_THRESHOLD_MASK)
/*! @} */

/*! @name SIUNSBESR - Station interface uncorrectable non-fatal system bus error status register */
/*! @{ */

#define ENETC_VSI_SIUNSBESR_SB_ID_MASK           (0xF00U)
#define ENETC_VSI_SIUNSBESR_SB_ID_SHIFT          (8U)
#define ENETC_VSI_SIUNSBESR_SB_ID_WIDTH          (4U)
#define ENETC_VSI_SIUNSBESR_SB_ID(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNSBESR_SB_ID_SHIFT)) & ENETC_VSI_SIUNSBESR_SB_ID_MASK)

#define ENETC_VSI_SIUNSBESR_SBE_MASK             (0x80000000U)
#define ENETC_VSI_SIUNSBESR_SBE_SHIFT            (31U)
#define ENETC_VSI_SIUNSBESR_SBE_WIDTH            (1U)
#define ENETC_VSI_SIUNSBESR_SBE(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNSBESR_SBE_SHIFT)) & ENETC_VSI_SIUNSBESR_SBE_MASK)
/*! @} */

/*! @name SIUNSBECTR - Station interface uncorrectable non-fatal system bus error count register */
/*! @{ */

#define ENETC_VSI_SIUNSBECTR_COUNT_MASK          (0xFFU)
#define ENETC_VSI_SIUNSBECTR_COUNT_SHIFT         (0U)
#define ENETC_VSI_SIUNSBECTR_COUNT_WIDTH         (8U)
#define ENETC_VSI_SIUNSBECTR_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNSBECTR_COUNT_SHIFT)) & ENETC_VSI_SIUNSBECTR_COUNT_MASK)
/*! @} */

/*! @name SIUFSBECR - Station interface uncorrectable fatal system bus error configuration register */
/*! @{ */

#define ENETC_VSI_SIUFSBECR_RD_MASK              (0x80000000U)
#define ENETC_VSI_SIUFSBECR_RD_SHIFT             (31U)
#define ENETC_VSI_SIUFSBECR_RD_WIDTH             (1U)
#define ENETC_VSI_SIUFSBECR_RD(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFSBECR_RD_SHIFT)) & ENETC_VSI_SIUFSBECR_RD_MASK)
/*! @} */

/*! @name SIUFSBESR - Station interface uncorrectable fatal system bus error status register */
/*! @{ */

#define ENETC_VSI_SIUFSBESR_SB_ID_MASK           (0xF00U)
#define ENETC_VSI_SIUFSBESR_SB_ID_SHIFT          (8U)
#define ENETC_VSI_SIUFSBESR_SB_ID_WIDTH          (4U)
#define ENETC_VSI_SIUFSBESR_SB_ID(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFSBESR_SB_ID_SHIFT)) & ENETC_VSI_SIUFSBESR_SB_ID_MASK)

#define ENETC_VSI_SIUFSBESR_M_MASK               (0x40000000U)
#define ENETC_VSI_SIUFSBESR_M_SHIFT              (30U)
#define ENETC_VSI_SIUFSBESR_M_WIDTH              (1U)
#define ENETC_VSI_SIUFSBESR_M(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFSBESR_M_SHIFT)) & ENETC_VSI_SIUFSBESR_M_MASK)

#define ENETC_VSI_SIUFSBESR_SBE_MASK             (0x80000000U)
#define ENETC_VSI_SIUFSBESR_SBE_SHIFT            (31U)
#define ENETC_VSI_SIUFSBESR_SBE_WIDTH            (1U)
#define ENETC_VSI_SIUFSBESR_SBE(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFSBESR_SBE_SHIFT)) & ENETC_VSI_SIUFSBESR_SBE_MASK)
/*! @} */

/*! @name SIUNMECR - Station interface uncorrectable non-fatal memory error configuration register */
/*! @{ */

#define ENETC_VSI_SIUNMECR_THRESHOLD_MASK        (0xFFU)
#define ENETC_VSI_SIUNMECR_THRESHOLD_SHIFT       (0U)
#define ENETC_VSI_SIUNMECR_THRESHOLD_WIDTH       (8U)
#define ENETC_VSI_SIUNMECR_THRESHOLD(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNMECR_THRESHOLD_SHIFT)) & ENETC_VSI_SIUNMECR_THRESHOLD_MASK)

#define ENETC_VSI_SIUNMECR_RD_MASK               (0x80000000U)
#define ENETC_VSI_SIUNMECR_RD_SHIFT              (31U)
#define ENETC_VSI_SIUNMECR_RD_WIDTH              (1U)
#define ENETC_VSI_SIUNMECR_RD(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNMECR_RD_SHIFT)) & ENETC_VSI_SIUNMECR_RD_MASK)
/*! @} */

/*! @name SIUNMESR0 - Station interface uncorrectable non-fatal memory error status register 0 */
/*! @{ */

#define ENETC_VSI_SIUNMESR0_MEM_ID_MASK          (0x1F00U)
#define ENETC_VSI_SIUNMESR0_MEM_ID_SHIFT         (8U)
#define ENETC_VSI_SIUNMESR0_MEM_ID_WIDTH         (5U)
#define ENETC_VSI_SIUNMESR0_MEM_ID(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNMESR0_MEM_ID_SHIFT)) & ENETC_VSI_SIUNMESR0_MEM_ID_MASK)

#define ENETC_VSI_SIUNMESR0_SYNDROME_MASK        (0x7FF0000U)
#define ENETC_VSI_SIUNMESR0_SYNDROME_SHIFT       (16U)
#define ENETC_VSI_SIUNMESR0_SYNDROME_WIDTH       (11U)
#define ENETC_VSI_SIUNMESR0_SYNDROME(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNMESR0_SYNDROME_SHIFT)) & ENETC_VSI_SIUNMESR0_SYNDROME_MASK)

#define ENETC_VSI_SIUNMESR0_MBEE_MASK            (0x80000000U)
#define ENETC_VSI_SIUNMESR0_MBEE_SHIFT           (31U)
#define ENETC_VSI_SIUNMESR0_MBEE_WIDTH           (1U)
#define ENETC_VSI_SIUNMESR0_MBEE(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNMESR0_MBEE_SHIFT)) & ENETC_VSI_SIUNMESR0_MBEE_MASK)
/*! @} */

/*! @name SIUNMESR1 - Station interface uncorrectable non-fatal memory error status register 1 */
/*! @{ */

#define ENETC_VSI_SIUNMESR1_ADDR_MASK            (0xFFFFFFFFU)
#define ENETC_VSI_SIUNMESR1_ADDR_SHIFT           (0U)
#define ENETC_VSI_SIUNMESR1_ADDR_WIDTH           (32U)
#define ENETC_VSI_SIUNMESR1_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNMESR1_ADDR_SHIFT)) & ENETC_VSI_SIUNMESR1_ADDR_MASK)
/*! @} */

/*! @name SIUNMECTR - Station interface uncorrectable non-fatal memory error count register */
/*! @{ */

#define ENETC_VSI_SIUNMECTR_COUNT_MASK           (0xFFU)
#define ENETC_VSI_SIUNMECTR_COUNT_SHIFT          (0U)
#define ENETC_VSI_SIUNMECTR_COUNT_WIDTH          (8U)
#define ENETC_VSI_SIUNMECTR_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNMECTR_COUNT_SHIFT)) & ENETC_VSI_SIUNMECTR_COUNT_MASK)
/*! @} */

/*! @name SIUFMECR - Station interface uncorrectable fatal memory error configuration register */
/*! @{ */

#define ENETC_VSI_SIUFMECR_RD_MASK               (0x80000000U)
#define ENETC_VSI_SIUFMECR_RD_SHIFT              (31U)
#define ENETC_VSI_SIUFMECR_RD_WIDTH              (1U)
#define ENETC_VSI_SIUFMECR_RD(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFMECR_RD_SHIFT)) & ENETC_VSI_SIUFMECR_RD_MASK)
/*! @} */

/*! @name SIUFMESR0 - Station interface uncorrectable fatal memory error status register 0 */
/*! @{ */

#define ENETC_VSI_SIUFMESR0_LINK_SLICE_ID_MASK   (0x1FU)
#define ENETC_VSI_SIUFMESR0_LINK_SLICE_ID_SHIFT  (0U)
#define ENETC_VSI_SIUFMESR0_LINK_SLICE_ID_WIDTH  (5U)
#define ENETC_VSI_SIUFMESR0_LINK_SLICE_ID(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFMESR0_LINK_SLICE_ID_SHIFT)) & ENETC_VSI_SIUFMESR0_LINK_SLICE_ID_MASK)

#define ENETC_VSI_SIUFMESR0_MEM_ID_MASK          (0x1F00U)
#define ENETC_VSI_SIUFMESR0_MEM_ID_SHIFT         (8U)
#define ENETC_VSI_SIUFMESR0_MEM_ID_WIDTH         (5U)
#define ENETC_VSI_SIUFMESR0_MEM_ID(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFMESR0_MEM_ID_SHIFT)) & ENETC_VSI_SIUFMESR0_MEM_ID_MASK)

#define ENETC_VSI_SIUFMESR0_EDCE_MASK            (0x8000U)
#define ENETC_VSI_SIUFMESR0_EDCE_SHIFT           (15U)
#define ENETC_VSI_SIUFMESR0_EDCE_WIDTH           (1U)
#define ENETC_VSI_SIUFMESR0_EDCE(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFMESR0_EDCE_SHIFT)) & ENETC_VSI_SIUFMESR0_EDCE_MASK)

#define ENETC_VSI_SIUFMESR0_SYNDROME_MASK        (0x7FF0000U)
#define ENETC_VSI_SIUFMESR0_SYNDROME_SHIFT       (16U)
#define ENETC_VSI_SIUFMESR0_SYNDROME_WIDTH       (11U)
#define ENETC_VSI_SIUFMESR0_SYNDROME(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFMESR0_SYNDROME_SHIFT)) & ENETC_VSI_SIUFMESR0_SYNDROME_MASK)

#define ENETC_VSI_SIUFMESR0_M_MASK               (0x40000000U)
#define ENETC_VSI_SIUFMESR0_M_SHIFT              (30U)
#define ENETC_VSI_SIUFMESR0_M_WIDTH              (1U)
#define ENETC_VSI_SIUFMESR0_M(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFMESR0_M_SHIFT)) & ENETC_VSI_SIUFMESR0_M_MASK)

#define ENETC_VSI_SIUFMESR0_MBEE_MASK            (0x80000000U)
#define ENETC_VSI_SIUFMESR0_MBEE_SHIFT           (31U)
#define ENETC_VSI_SIUFMESR0_MBEE_WIDTH           (1U)
#define ENETC_VSI_SIUFMESR0_MBEE(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFMESR0_MBEE_SHIFT)) & ENETC_VSI_SIUFMESR0_MBEE_MASK)
/*! @} */

/*! @name SIUFMESR1 - Station interface uncorrectable fatal memory error status register 1 */
/*! @{ */

#define ENETC_VSI_SIUFMESR1_ADDR_MASK            (0xFFFFFFFFU)
#define ENETC_VSI_SIUFMESR1_ADDR_SHIFT           (0U)
#define ENETC_VSI_SIUFMESR1_ADDR_WIDTH           (32U)
#define ENETC_VSI_SIUFMESR1_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFMESR1_ADDR_SHIFT)) & ENETC_VSI_SIUFMESR1_ADDR_MASK)
/*! @} */

/*! @name SIUNIECR - Station interface uncorrectable non-fatal integrity error configuration register */
/*! @{ */

#define ENETC_VSI_SIUNIECR_THRESHOLD_MASK        (0xFFU)
#define ENETC_VSI_SIUNIECR_THRESHOLD_SHIFT       (0U)
#define ENETC_VSI_SIUNIECR_THRESHOLD_WIDTH       (8U)
#define ENETC_VSI_SIUNIECR_THRESHOLD(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNIECR_THRESHOLD_SHIFT)) & ENETC_VSI_SIUNIECR_THRESHOLD_MASK)

#define ENETC_VSI_SIUNIECR_RD_MASK               (0x80000000U)
#define ENETC_VSI_SIUNIECR_RD_SHIFT              (31U)
#define ENETC_VSI_SIUNIECR_RD_WIDTH              (1U)
#define ENETC_VSI_SIUNIECR_RD(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNIECR_RD_SHIFT)) & ENETC_VSI_SIUNIECR_RD_MASK)
/*! @} */

/*! @name SIUNIESR - Station interface uncorrectable non-fatal integrity error status register */
/*! @{ */

#define ENETC_VSI_SIUNIESR_BLOCK_ID_MASK         (0x1F00U)
#define ENETC_VSI_SIUNIESR_BLOCK_ID_SHIFT        (8U)
#define ENETC_VSI_SIUNIESR_BLOCK_ID_WIDTH        (5U)
#define ENETC_VSI_SIUNIESR_BLOCK_ID(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNIESR_BLOCK_ID_SHIFT)) & ENETC_VSI_SIUNIESR_BLOCK_ID_MASK)

#define ENETC_VSI_SIUNIESR_SM_ID_MASK            (0x3F0000U)
#define ENETC_VSI_SIUNIESR_SM_ID_SHIFT           (16U)
#define ENETC_VSI_SIUNIESR_SM_ID_WIDTH           (6U)
#define ENETC_VSI_SIUNIESR_SM_ID(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNIESR_SM_ID_SHIFT)) & ENETC_VSI_SIUNIESR_SM_ID_MASK)

#define ENETC_VSI_SIUNIESR_INTERR_MASK           (0x80000000U)
#define ENETC_VSI_SIUNIESR_INTERR_SHIFT          (31U)
#define ENETC_VSI_SIUNIESR_INTERR_WIDTH          (1U)
#define ENETC_VSI_SIUNIESR_INTERR(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNIESR_INTERR_SHIFT)) & ENETC_VSI_SIUNIESR_INTERR_MASK)
/*! @} */

/*! @name SIUNIECTR - Station interface uncorrectable non-fatal integrity error count register */
/*! @{ */

#define ENETC_VSI_SIUNIECTR_COUNT_MASK           (0xFFU)
#define ENETC_VSI_SIUNIECTR_COUNT_SHIFT          (0U)
#define ENETC_VSI_SIUNIECTR_COUNT_WIDTH          (8U)
#define ENETC_VSI_SIUNIECTR_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUNIECTR_COUNT_SHIFT)) & ENETC_VSI_SIUNIECTR_COUNT_MASK)
/*! @} */

/*! @name SIUFIECR - Station interface uncorrectable fatal integrity error configuration register */
/*! @{ */

#define ENETC_VSI_SIUFIECR_RD_MASK               (0x80000000U)
#define ENETC_VSI_SIUFIECR_RD_SHIFT              (31U)
#define ENETC_VSI_SIUFIECR_RD_WIDTH              (1U)
#define ENETC_VSI_SIUFIECR_RD(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFIECR_RD_SHIFT)) & ENETC_VSI_SIUFIECR_RD_MASK)
/*! @} */

/*! @name SIUFIESR - Station interface uncorrectable fatal integrity error status register */
/*! @{ */

#define ENETC_VSI_SIUFIESR_BLOCK_ID_MASK         (0x1F00U)
#define ENETC_VSI_SIUFIESR_BLOCK_ID_SHIFT        (8U)
#define ENETC_VSI_SIUFIESR_BLOCK_ID_WIDTH        (5U)
#define ENETC_VSI_SIUFIESR_BLOCK_ID(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFIESR_BLOCK_ID_SHIFT)) & ENETC_VSI_SIUFIESR_BLOCK_ID_MASK)

#define ENETC_VSI_SIUFIESR_SM_ID_MASK            (0x3F0000U)
#define ENETC_VSI_SIUFIESR_SM_ID_SHIFT           (16U)
#define ENETC_VSI_SIUFIESR_SM_ID_WIDTH           (6U)
#define ENETC_VSI_SIUFIESR_SM_ID(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFIESR_SM_ID_SHIFT)) & ENETC_VSI_SIUFIESR_SM_ID_MASK)

#define ENETC_VSI_SIUFIESR_M_MASK                (0x40000000U)
#define ENETC_VSI_SIUFIESR_M_SHIFT               (30U)
#define ENETC_VSI_SIUFIESR_M_WIDTH               (1U)
#define ENETC_VSI_SIUFIESR_M(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFIESR_M_SHIFT)) & ENETC_VSI_SIUFIESR_M_MASK)

#define ENETC_VSI_SIUFIESR_INTERR_MASK           (0x80000000U)
#define ENETC_VSI_SIUFIESR_INTERR_SHIFT          (31U)
#define ENETC_VSI_SIUFIESR_INTERR_WIDTH          (1U)
#define ENETC_VSI_SIUFIESR_INTERR(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIUFIESR_INTERR_SHIFT)) & ENETC_VSI_SIUFIESR_INTERR_MASK)
/*! @} */

/*! @name SIMAFTCAPR - Station interface MAC address filter table capability register */
/*! @{ */

#define ENETC_VSI_SIMAFTCAPR_NUM_MAC_AFTE_MASK   (0xFFU)
#define ENETC_VSI_SIMAFTCAPR_NUM_MAC_AFTE_SHIFT  (0U)
#define ENETC_VSI_SIMAFTCAPR_NUM_MAC_AFTE_WIDTH  (8U)
#define ENETC_VSI_SIMAFTCAPR_NUM_MAC_AFTE(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMAFTCAPR_NUM_MAC_AFTE_SHIFT)) & ENETC_VSI_SIMAFTCAPR_NUM_MAC_AFTE_MASK)

#define ENETC_VSI_SIMAFTCAPR_VERSIONS_MASK       (0xFFFF0000U)
#define ENETC_VSI_SIMAFTCAPR_VERSIONS_SHIFT      (16U)
#define ENETC_VSI_SIMAFTCAPR_VERSIONS_WIDTH      (16U)
#define ENETC_VSI_SIMAFTCAPR_VERSIONS(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIMAFTCAPR_VERSIONS_SHIFT)) & ENETC_VSI_SIMAFTCAPR_VERSIONS_MASK)
/*! @} */

/*! @name SIVFTCAPR - Station interface VLAN filter table capability register */
/*! @{ */

#define ENETC_VSI_SIVFTCAPR_NUM_VLAN_FTE_MASK    (0xFFU)
#define ENETC_VSI_SIVFTCAPR_NUM_VLAN_FTE_SHIFT   (0U)
#define ENETC_VSI_SIVFTCAPR_NUM_VLAN_FTE_WIDTH   (8U)
#define ENETC_VSI_SIVFTCAPR_NUM_VLAN_FTE(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVFTCAPR_NUM_VLAN_FTE_SHIFT)) & ENETC_VSI_SIVFTCAPR_NUM_VLAN_FTE_MASK)

#define ENETC_VSI_SIVFTCAPR_VERSIONS_MASK        (0xFFFF0000U)
#define ENETC_VSI_SIVFTCAPR_VERSIONS_SHIFT       (16U)
#define ENETC_VSI_SIVFTCAPR_VERSIONS_WIDTH       (16U)
#define ENETC_VSI_SIVFTCAPR_VERSIONS(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIVFTCAPR_VERSIONS_SHIFT)) & ENETC_VSI_SIVFTCAPR_VERSIONS_MASK)
/*! @} */

/*! @name SIRFSCAPR - Station interface RFS capability register */
/*! @{ */

#define ENETC_VSI_SIRFSCAPR_NUM_RFS_MASK         (0x1FFU)
#define ENETC_VSI_SIRFSCAPR_NUM_RFS_SHIFT        (0U)
#define ENETC_VSI_SIRFSCAPR_NUM_RFS_WIDTH        (9U)
#define ENETC_VSI_SIRFSCAPR_NUM_RFS(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRFSCAPR_NUM_RFS_SHIFT)) & ENETC_VSI_SIRFSCAPR_NUM_RFS_MASK)

#define ENETC_VSI_SIRFSCAPR_VERSIONS_MASK        (0xFFFF0000U)
#define ENETC_VSI_SIRFSCAPR_VERSIONS_SHIFT       (16U)
#define ENETC_VSI_SIRFSCAPR_VERSIONS_WIDTH       (16U)
#define ENETC_VSI_SIRFSCAPR_VERSIONS(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_SIRFSCAPR_VERSIONS_SHIFT)) & ENETC_VSI_SIRFSCAPR_VERSIONS_MASK)
/*! @} */

/*! @name TBMR - Tx BDR 0 mode register..Tx BDR 13 mode register */
/*! @{ */

#define ENETC_VSI_TBMR_PRIO_MASK                 (0x7U)
#define ENETC_VSI_TBMR_PRIO_SHIFT                (0U)
#define ENETC_VSI_TBMR_PRIO_WIDTH                (3U)
#define ENETC_VSI_TBMR_PRIO(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBMR_PRIO_SHIFT)) & ENETC_VSI_TBMR_PRIO_MASK)

#define ENETC_VSI_TBMR_WRR_MASK                  (0x70U)
#define ENETC_VSI_TBMR_WRR_SHIFT                 (4U)
#define ENETC_VSI_TBMR_WRR_WIDTH                 (3U)
#define ENETC_VSI_TBMR_WRR(x)                    (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBMR_WRR_SHIFT)) & ENETC_VSI_TBMR_WRR_MASK)

#define ENETC_VSI_TBMR_CRC_MASK                  (0x100U)
#define ENETC_VSI_TBMR_CRC_SHIFT                 (8U)
#define ENETC_VSI_TBMR_CRC_WIDTH                 (1U)
#define ENETC_VSI_TBMR_CRC(x)                    (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBMR_CRC_SHIFT)) & ENETC_VSI_TBMR_CRC_MASK)

#define ENETC_VSI_TBMR_VIH_MASK                  (0x200U)
#define ENETC_VSI_TBMR_VIH_SHIFT                 (9U)
#define ENETC_VSI_TBMR_VIH_WIDTH                 (1U)
#define ENETC_VSI_TBMR_VIH(x)                    (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBMR_VIH_SHIFT)) & ENETC_VSI_TBMR_VIH_MASK)

#define ENETC_VSI_TBMR_FWB_MASK                  (0x1000000U)
#define ENETC_VSI_TBMR_FWB_SHIFT                 (24U)
#define ENETC_VSI_TBMR_FWB_WIDTH                 (1U)
#define ENETC_VSI_TBMR_FWB(x)                    (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBMR_FWB_SHIFT)) & ENETC_VSI_TBMR_FWB_MASK)

#define ENETC_VSI_TBMR_EN_MASK                   (0x80000000U)
#define ENETC_VSI_TBMR_EN_SHIFT                  (31U)
#define ENETC_VSI_TBMR_EN_WIDTH                  (1U)
#define ENETC_VSI_TBMR_EN(x)                     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBMR_EN_SHIFT)) & ENETC_VSI_TBMR_EN_MASK)
/*! @} */

/*! @name TBSR - Tx BDR 0 status register..Tx BDR 13 status register */
/*! @{ */

#define ENETC_VSI_TBSR_BUSY_MASK                 (0x1U)
#define ENETC_VSI_TBSR_BUSY_SHIFT                (0U)
#define ENETC_VSI_TBSR_BUSY_WIDTH                (1U)
#define ENETC_VSI_TBSR_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBSR_BUSY_SHIFT)) & ENETC_VSI_TBSR_BUSY_MASK)

#define ENETC_VSI_TBSR_SBE_MASK                  (0x10000U)
#define ENETC_VSI_TBSR_SBE_SHIFT                 (16U)
#define ENETC_VSI_TBSR_SBE_WIDTH                 (1U)
#define ENETC_VSI_TBSR_SBE(x)                    (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBSR_SBE_SHIFT)) & ENETC_VSI_TBSR_SBE_MASK)
/*! @} */

/*! @name TBBAR0 - Tx BDR 0 base address register 0..Tx BDR 13 base address register 0 */
/*! @{ */

#define ENETC_VSI_TBBAR0_ADDRL_MASK              (0xFFFFFF80U)
#define ENETC_VSI_TBBAR0_ADDRL_SHIFT             (7U)
#define ENETC_VSI_TBBAR0_ADDRL_WIDTH             (25U)
#define ENETC_VSI_TBBAR0_ADDRL(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBBAR0_ADDRL_SHIFT)) & ENETC_VSI_TBBAR0_ADDRL_MASK)
/*! @} */

/*! @name TBBAR1 - Tx BDR 0 base address register 1..Tx BDR 13 base address register 1 */
/*! @{ */

#define ENETC_VSI_TBBAR1_ADDRH_MASK              (0xFFFFFFFFU)
#define ENETC_VSI_TBBAR1_ADDRH_SHIFT             (0U)
#define ENETC_VSI_TBBAR1_ADDRH_WIDTH             (32U)
#define ENETC_VSI_TBBAR1_ADDRH(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBBAR1_ADDRH_SHIFT)) & ENETC_VSI_TBBAR1_ADDRH_MASK)
/*! @} */

/*! @name TBPIR - Tx BDR 0 producer index register..Tx BDR 13 producer index register */
/*! @{ */

#define ENETC_VSI_TBPIR_BDR_INDEX_MASK           (0xFFFFU)
#define ENETC_VSI_TBPIR_BDR_INDEX_SHIFT          (0U)
#define ENETC_VSI_TBPIR_BDR_INDEX_WIDTH          (16U)
#define ENETC_VSI_TBPIR_BDR_INDEX(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBPIR_BDR_INDEX_SHIFT)) & ENETC_VSI_TBPIR_BDR_INDEX_MASK)
/*! @} */

/*! @name TBCIR - Tx BDR 0 consumer index register..Tx BDR 13 consumer index register */
/*! @{ */

#define ENETC_VSI_TBCIR_BDR_INDEX_MASK           (0xFFFFU)
#define ENETC_VSI_TBCIR_BDR_INDEX_SHIFT          (0U)
#define ENETC_VSI_TBCIR_BDR_INDEX_WIDTH          (16U)
#define ENETC_VSI_TBCIR_BDR_INDEX(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBCIR_BDR_INDEX_SHIFT)) & ENETC_VSI_TBCIR_BDR_INDEX_MASK)

#define ENETC_VSI_TBCIR_STAT_ID_MASK             (0x7FFF0000U)
#define ENETC_VSI_TBCIR_STAT_ID_SHIFT            (16U)
#define ENETC_VSI_TBCIR_STAT_ID_WIDTH            (15U)
#define ENETC_VSI_TBCIR_STAT_ID(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBCIR_STAT_ID_SHIFT)) & ENETC_VSI_TBCIR_STAT_ID_MASK)

#define ENETC_VSI_TBCIR_SBE_MASK                 (0x80000000U)
#define ENETC_VSI_TBCIR_SBE_SHIFT                (31U)
#define ENETC_VSI_TBCIR_SBE_WIDTH                (1U)
#define ENETC_VSI_TBCIR_SBE(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBCIR_SBE_SHIFT)) & ENETC_VSI_TBCIR_SBE_MASK)
/*! @} */

/*! @name TBLENR - Tx BDR 0 length register..Tx BDR 13 length register */
/*! @{ */

#define ENETC_VSI_TBLENR_LENGTH_MASK             (0x1FFF8U)
#define ENETC_VSI_TBLENR_LENGTH_SHIFT            (3U)
#define ENETC_VSI_TBLENR_LENGTH_WIDTH            (14U)
#define ENETC_VSI_TBLENR_LENGTH(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBLENR_LENGTH_SHIFT)) & ENETC_VSI_TBLENR_LENGTH_MASK)
/*! @} */

/*! @name TBIER - Tx BDR 0 interrupt enable register..Tx BDR 13 interrupt enable register */
/*! @{ */

#define ENETC_VSI_TBIER_TXTIE_MASK               (0x1U)
#define ENETC_VSI_TBIER_TXTIE_SHIFT              (0U)
#define ENETC_VSI_TBIER_TXTIE_WIDTH              (1U)
#define ENETC_VSI_TBIER_TXTIE(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBIER_TXTIE_SHIFT)) & ENETC_VSI_TBIER_TXTIE_MASK)

#define ENETC_VSI_TBIER_TXFIE_MASK               (0x2U)
#define ENETC_VSI_TBIER_TXFIE_SHIFT              (1U)
#define ENETC_VSI_TBIER_TXFIE_WIDTH              (1U)
#define ENETC_VSI_TBIER_TXFIE(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBIER_TXFIE_SHIFT)) & ENETC_VSI_TBIER_TXFIE_MASK)
/*! @} */

/*! @name TBIDR - Tx BDR 0 interrupt detect register..Tx BDR 13 interrupt detect register */
/*! @{ */

#define ENETC_VSI_TBIDR_TXT_MASK                 (0x1U)
#define ENETC_VSI_TBIDR_TXT_SHIFT                (0U)
#define ENETC_VSI_TBIDR_TXT_WIDTH                (1U)
#define ENETC_VSI_TBIDR_TXT(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBIDR_TXT_SHIFT)) & ENETC_VSI_TBIDR_TXT_MASK)

#define ENETC_VSI_TBIDR_TXF_MASK                 (0x2U)
#define ENETC_VSI_TBIDR_TXF_SHIFT                (1U)
#define ENETC_VSI_TBIDR_TXF_WIDTH                (1U)
#define ENETC_VSI_TBIDR_TXF(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBIDR_TXF_SHIFT)) & ENETC_VSI_TBIDR_TXF_MASK)
/*! @} */

/*! @name TBICR0 - Tx BDR 0 interrupt coalescing register 0..Tx BDR 13 interrupt coalescing register 0 */
/*! @{ */

#define ENETC_VSI_TBICR0_ICPT_MASK               (0xFU)
#define ENETC_VSI_TBICR0_ICPT_SHIFT              (0U)
#define ENETC_VSI_TBICR0_ICPT_WIDTH              (4U)
#define ENETC_VSI_TBICR0_ICPT(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBICR0_ICPT_SHIFT)) & ENETC_VSI_TBICR0_ICPT_MASK)

#define ENETC_VSI_TBICR0_ICEN_MASK               (0x80000000U)
#define ENETC_VSI_TBICR0_ICEN_SHIFT              (31U)
#define ENETC_VSI_TBICR0_ICEN_WIDTH              (1U)
#define ENETC_VSI_TBICR0_ICEN(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBICR0_ICEN_SHIFT)) & ENETC_VSI_TBICR0_ICEN_MASK)
/*! @} */

/*! @name TBICR1 - Tx BDR 0 interrupt coalescing register 1..Tx BDR 13 interrupt coalescing register 1 */
/*! @{ */

#define ENETC_VSI_TBICR1_ICTT_MASK               (0xFFFFFFFFU)
#define ENETC_VSI_TBICR1_ICTT_SHIFT              (0U)
#define ENETC_VSI_TBICR1_ICTT_WIDTH              (32U)
#define ENETC_VSI_TBICR1_ICTT(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_TBICR1_ICTT_SHIFT)) & ENETC_VSI_TBICR1_ICTT_MASK)
/*! @} */

/*! @name RBMR - Rx BDR 0 mode register..Rx BDR 13 mode register */
/*! @{ */

#define ENETC_VSI_RBMR_AL_MASK                   (0x1U)
#define ENETC_VSI_RBMR_AL_SHIFT                  (0U)
#define ENETC_VSI_RBMR_AL_WIDTH                  (1U)
#define ENETC_VSI_RBMR_AL(x)                     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBMR_AL_SHIFT)) & ENETC_VSI_RBMR_AL_MASK)

#define ENETC_VSI_RBMR_BDS_MASK                  (0x4U)
#define ENETC_VSI_RBMR_BDS_SHIFT                 (2U)
#define ENETC_VSI_RBMR_BDS_WIDTH                 (1U)
#define ENETC_VSI_RBMR_BDS(x)                    (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBMR_BDS_SHIFT)) & ENETC_VSI_RBMR_BDS_MASK)

#define ENETC_VSI_RBMR_CM_MASK                   (0x10U)
#define ENETC_VSI_RBMR_CM_SHIFT                  (4U)
#define ENETC_VSI_RBMR_CM_WIDTH                  (1U)
#define ENETC_VSI_RBMR_CM(x)                     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBMR_CM_SHIFT)) & ENETC_VSI_RBMR_CM_MASK)

#define ENETC_VSI_RBMR_VTE_MASK                  (0x20U)
#define ENETC_VSI_RBMR_VTE_SHIFT                 (5U)
#define ENETC_VSI_RBMR_VTE_WIDTH                 (1U)
#define ENETC_VSI_RBMR_VTE(x)                    (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBMR_VTE_SHIFT)) & ENETC_VSI_RBMR_VTE_MASK)

#define ENETC_VSI_RBMR_VTPD_MASK                 (0x40U)
#define ENETC_VSI_RBMR_VTPD_SHIFT                (6U)
#define ENETC_VSI_RBMR_VTPD_WIDTH                (1U)
#define ENETC_VSI_RBMR_VTPD(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBMR_VTPD_SHIFT)) & ENETC_VSI_RBMR_VTPD_MASK)

#define ENETC_VSI_RBMR_CRC_MASK                  (0x100U)
#define ENETC_VSI_RBMR_CRC_SHIFT                 (8U)
#define ENETC_VSI_RBMR_CRC_WIDTH                 (1U)
#define ENETC_VSI_RBMR_CRC(x)                    (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBMR_CRC_SHIFT)) & ENETC_VSI_RBMR_CRC_MASK)

#define ENETC_VSI_RBMR_EN_MASK                   (0x80000000U)
#define ENETC_VSI_RBMR_EN_SHIFT                  (31U)
#define ENETC_VSI_RBMR_EN_WIDTH                  (1U)
#define ENETC_VSI_RBMR_EN(x)                     (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBMR_EN_SHIFT)) & ENETC_VSI_RBMR_EN_MASK)
/*! @} */

/*! @name RBSR - Rx BDR 0 status register..Rx BDR 13 status register */
/*! @{ */

#define ENETC_VSI_RBSR_EMPTY_MASK                (0x1U)
#define ENETC_VSI_RBSR_EMPTY_SHIFT               (0U)
#define ENETC_VSI_RBSR_EMPTY_WIDTH               (1U)
#define ENETC_VSI_RBSR_EMPTY(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBSR_EMPTY_SHIFT)) & ENETC_VSI_RBSR_EMPTY_MASK)

#define ENETC_VSI_RBSR_SBE_MASK                  (0x10000U)
#define ENETC_VSI_RBSR_SBE_SHIFT                 (16U)
#define ENETC_VSI_RBSR_SBE_WIDTH                 (1U)
#define ENETC_VSI_RBSR_SBE(x)                    (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBSR_SBE_SHIFT)) & ENETC_VSI_RBSR_SBE_MASK)
/*! @} */

/*! @name RBBSR - Rx BDR 0 buffer size register..Rx BDR 13 buffer size register */
/*! @{ */

#define ENETC_VSI_RBBSR_BSIZE_MASK               (0xFFFFU)
#define ENETC_VSI_RBBSR_BSIZE_SHIFT              (0U)
#define ENETC_VSI_RBBSR_BSIZE_WIDTH              (16U)
#define ENETC_VSI_RBBSR_BSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBBSR_BSIZE_SHIFT)) & ENETC_VSI_RBBSR_BSIZE_MASK)
/*! @} */

/*! @name RBCIR - Rx BDR 0 consumer index register..Rx BDR 13 consumer index register */
/*! @{ */

#define ENETC_VSI_RBCIR_BDR_INDEX_MASK           (0xFFFFU)
#define ENETC_VSI_RBCIR_BDR_INDEX_SHIFT          (0U)
#define ENETC_VSI_RBCIR_BDR_INDEX_WIDTH          (16U)
#define ENETC_VSI_RBCIR_BDR_INDEX(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBCIR_BDR_INDEX_SHIFT)) & ENETC_VSI_RBCIR_BDR_INDEX_MASK)
/*! @} */

/*! @name RBBAR0 - Rx BDR 0 base address register 0..Rx BDR 13 base address register 0 */
/*! @{ */

#define ENETC_VSI_RBBAR0_ADDRL_MASK              (0xFFFFFF80U)
#define ENETC_VSI_RBBAR0_ADDRL_SHIFT             (7U)
#define ENETC_VSI_RBBAR0_ADDRL_WIDTH             (25U)
#define ENETC_VSI_RBBAR0_ADDRL(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBBAR0_ADDRL_SHIFT)) & ENETC_VSI_RBBAR0_ADDRL_MASK)
/*! @} */

/*! @name RBBAR1 - Rx BDR 0 base address register 1..Rx BDR 13 base address register 1 */
/*! @{ */

#define ENETC_VSI_RBBAR1_ADDRH_MASK              (0xFFFFFFFFU)
#define ENETC_VSI_RBBAR1_ADDRH_SHIFT             (0U)
#define ENETC_VSI_RBBAR1_ADDRH_WIDTH             (32U)
#define ENETC_VSI_RBBAR1_ADDRH(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBBAR1_ADDRH_SHIFT)) & ENETC_VSI_RBBAR1_ADDRH_MASK)
/*! @} */

/*! @name RBPIR - Rx BDR 0 producer index register..Rx BDR 13 producer index register */
/*! @{ */

#define ENETC_VSI_RBPIR_BDR_INDEX_MASK           (0xFFFFU)
#define ENETC_VSI_RBPIR_BDR_INDEX_SHIFT          (0U)
#define ENETC_VSI_RBPIR_BDR_INDEX_WIDTH          (16U)
#define ENETC_VSI_RBPIR_BDR_INDEX(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBPIR_BDR_INDEX_SHIFT)) & ENETC_VSI_RBPIR_BDR_INDEX_MASK)

#define ENETC_VSI_RBPIR_SBE_MASK                 (0x80000000U)
#define ENETC_VSI_RBPIR_SBE_SHIFT                (31U)
#define ENETC_VSI_RBPIR_SBE_WIDTH                (1U)
#define ENETC_VSI_RBPIR_SBE(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBPIR_SBE_SHIFT)) & ENETC_VSI_RBPIR_SBE_MASK)
/*! @} */

/*! @name RBLENR - Rx BDR 0 length register..Rx BDR 13 length register */
/*! @{ */

#define ENETC_VSI_RBLENR_LENGTH_MASK             (0x1FFF8U)
#define ENETC_VSI_RBLENR_LENGTH_SHIFT            (3U)
#define ENETC_VSI_RBLENR_LENGTH_WIDTH            (14U)
#define ENETC_VSI_RBLENR_LENGTH(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBLENR_LENGTH_SHIFT)) & ENETC_VSI_RBLENR_LENGTH_MASK)
/*! @} */

/*! @name RBDCR - Rx BDR 0 drop count register..Rx BDR 13 drop count register */
/*! @{ */

#define ENETC_VSI_RBDCR_COUNT_MASK               (0xFFFFFFFFU)
#define ENETC_VSI_RBDCR_COUNT_SHIFT              (0U)
#define ENETC_VSI_RBDCR_COUNT_WIDTH              (32U)
#define ENETC_VSI_RBDCR_COUNT(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBDCR_COUNT_SHIFT)) & ENETC_VSI_RBDCR_COUNT_MASK)
/*! @} */

/*! @name RBIER - Rx BDR 0 interrupt enable register..Rx BDR 13 interrupt enable register */
/*! @{ */

#define ENETC_VSI_RBIER_RXTIE_MASK               (0x1U)
#define ENETC_VSI_RBIER_RXTIE_SHIFT              (0U)
#define ENETC_VSI_RBIER_RXTIE_WIDTH              (1U)
#define ENETC_VSI_RBIER_RXTIE(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBIER_RXTIE_SHIFT)) & ENETC_VSI_RBIER_RXTIE_MASK)
/*! @} */

/*! @name RBIDR - Rx BDR 0 interrupt detect register..Rx BDR 13 interrupt detect register */
/*! @{ */

#define ENETC_VSI_RBIDR_RXT_MASK                 (0x1U)
#define ENETC_VSI_RBIDR_RXT_SHIFT                (0U)
#define ENETC_VSI_RBIDR_RXT_WIDTH                (1U)
#define ENETC_VSI_RBIDR_RXT(x)                   (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBIDR_RXT_SHIFT)) & ENETC_VSI_RBIDR_RXT_MASK)
/*! @} */

/*! @name RBICR0 - Rx BDR 0 interrupt coalescing register 0..Rx BDR 13 interrupt coalescing register 0 */
/*! @{ */

#define ENETC_VSI_RBICR0_ICPT_MASK               (0x1FFU)
#define ENETC_VSI_RBICR0_ICPT_SHIFT              (0U)
#define ENETC_VSI_RBICR0_ICPT_WIDTH              (9U)
#define ENETC_VSI_RBICR0_ICPT(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBICR0_ICPT_SHIFT)) & ENETC_VSI_RBICR0_ICPT_MASK)

#define ENETC_VSI_RBICR0_ICEN_MASK               (0x80000000U)
#define ENETC_VSI_RBICR0_ICEN_SHIFT              (31U)
#define ENETC_VSI_RBICR0_ICEN_WIDTH              (1U)
#define ENETC_VSI_RBICR0_ICEN(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBICR0_ICEN_SHIFT)) & ENETC_VSI_RBICR0_ICEN_MASK)
/*! @} */

/*! @name RBICR1 - Rx BDR 0 interrupt coalescing register 1..Rx BDR 13 interrupt coalescing register 1 */
/*! @{ */

#define ENETC_VSI_RBICR1_ICTT_MASK               (0xFFFFFFFFU)
#define ENETC_VSI_RBICR1_ICTT_SHIFT              (0U)
#define ENETC_VSI_RBICR1_ICTT_WIDTH              (32U)
#define ENETC_VSI_RBICR1_ICTT(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_VSI_RBICR1_ICTT_SHIFT)) & ENETC_VSI_RBICR1_ICTT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ENETC_VSI_Register_Masks */

/*!
 * @}
 */ /* end of group ENETC_VSI_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_ENETC_VSI_H_) */
