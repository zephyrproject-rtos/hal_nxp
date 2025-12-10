/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_ENETC_BASE.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_ENETC_BASE
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
#if !defined(S32K566_ENETC_BASE_H_)  /* Check if memory map has not been already included */
#define S32K566_ENETC_BASE_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ENETC_BASE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_BASE_Peripheral_Access_Layer ENETC_BASE Peripheral Access Layer
 * @{
 */

/** ENETC_BASE - Size of Registers Arrays */
#define ENETC_BASE_PARCEACR_COUNT                 4u
#define ENETC_BASE_PICDRADCR_COUNT                4u
#define ENETC_BASE_TC_TBS_NUM_COUNT               8u
#define ENETC_BASE_NUM_SMHRBDRMR_COUNT            15u
#define ENETC_BASE_NUM_SI_COUNT                   6u

/** ENETC_BASE - Register Layout Typedef */
typedef struct ENETC_BASE_Struct {
  __I  uint32_t ECAPR0;                            /**< ENETC capability register 0, offset: 0x0 */
  __I  uint32_t ECAPR1;                            /**< ENETC capability register 1, offset: 0x4 */
  __I  uint32_t ECAPR2;                            /**< ENETC capability register 2, offset: 0x8 */
  uint8_t RESERVED_0[4];
  __IO uint32_t PMR;                               /**< Port mode register, offset: 0x10 */
  uint8_t RESERVED_1[108];
  __IO uint32_t PONVLANR;                          /**< Port outer native VLAN register, offset: 0x80 */
  __IO uint32_t PINVLANR;                          /**< Port inner native VLAN register, offset: 0x84 */
  __IO uint32_t PVCLCTR;                           /**< Port VLAN classification control register, offset: 0x88 */
  uint8_t RESERVED_2[16];
  __IO uint32_t PARCSCR;                           /**< Parser checksum configuration register, offset: 0x9C */
  __IO uint32_t PARCECR[ENETC_BASE_PARCEACR_COUNT]; /**< Parser custom EtherType 0 configuration register..Parser custom EtherType 3 configuration register, array offset: 0xA0, array step: 0x4 */
  uint8_t RESERVED_3[88];
  __IO uint32_t PPAUONTR;                          /**< Port pause ON threshold register, offset: 0x108 */
  __IO uint32_t PPAUOFFTR;                         /**< Port pause OFF threshold register, offset: 0x10C */
  uint8_t RESERVED_4[16];
  __I  uint32_t PRXMBER;                           /**< Port receive memory buffer entitlement register, offset: 0x120 */
  __I  uint32_t PRXMBLR;                           /**< Port receive memory buffer limit register, offset: 0x124 */
  __I  uint32_t PRXBCR;                            /**< Port receive buffer count register, offset: 0x128 */
  __I  uint32_t PRXBCHWMR;                         /**< Port receive buffer count high watermark register, offset: 0x12C */
  uint8_t RESERVED_5[16];
  struct ENETC_BASE_PICDRADCR {                    /* offset: 0x140, array step: 0x10 */
    __I  uint32_t PICDRDCR;                          /**< Port ingress congestion DR0 discard count register..Port ingress congestion DR3 discard count register, array offset: 0x140, array step: 0x10 */
    uint8_t RESERVED_0[4];
    __I  uint32_t PICDRDCRRR;                        /**< Port ingress congestion DR0 discard count read-reset register..Port ingress congestion DR3 discard count read-reset register, array offset: 0x148, array step: 0x10 */
    uint8_t RESERVED_1[4];
  } PICDRADCR[ENETC_BASE_PICDRADCR_COUNT];
  __IO uint32_t PICPDSR;                           /**< Port ingress congestion priority discard status register, offset: 0x180 */
  uint8_t RESERVED_6[124];
  __IO uint32_t PSIPMMR;                           /**< Port station interface promiscuous MAC mode register, offset: 0x200 */
  __IO uint32_t PSIPVMR;                           /**< Port station interface promiscuous VLAN mode register, offset: 0x204 */
  __I  uint32_t PBFDSIR;                           /**< Port broadcast frames dropped due to MAC filtering register, offset: 0x208 */
  __I  uint32_t PFDMSAPR;                          /**< Port frame drop MAC source address pruning register, offset: 0x20C */
  uint8_t RESERVED_7[112];
  __I  uint32_t PSIMAFCAPR;                        /**< Port station interface MAC address filtering capability register, offset: 0x280 */
  __I  uint32_t PUFDMFR;                           /**< Port unicast frames dropped due to MAC filtering register, offset: 0x284 */
  __I  uint32_t PMFDMFR;                           /**< Port multicast frames dropped due to MAC filtering register, offset: 0x288 */
  uint8_t RESERVED_8[52];
  __I  uint32_t PSIVLANFCAPR;                      /**< Port station interface VLAN filtering capability register, offset: 0x2C0 */
  __IO uint32_t PSIVLANFMR;                        /**< Port station interface VLAN filtering mode register, offset: 0x2C4 */
  uint8_t RESERVED_9[8];
  __I  uint32_t PUFDVFR;                           /**< Port unicast frames dropped VLAN filtering register, offset: 0x2D0 */
  __I  uint32_t PMFDVFR;                           /**< Port multicast frames dropped VLAN filtering register, offset: 0x2D4 */
  __I  uint32_t PBFDVFR;                           /**< Port broadcast frames dropped VLAN filtering register, offset: 0x2D8 */
  uint8_t RESERVED_10[36];
  __I  uint32_t PRFSCAPR;                          /**< Port RFS capability register, offset: 0x300 */
  uint8_t RESERVED_11[12];
  __IO uint32_t PRFSMR;                            /**< Port RFS mode register, offset: 0x310 */
  uint8_t RESERVED_12[92];
  __IO uint32_t IPV2ICMPMR0;                       /**< Receive IPV to ICM priority mapping register 0, offset: 0x370 */
  uint8_t RESERVED_13[12];
  __IO uint32_t PRIO2TCMR0;                        /**< Transmit priority to traffic class mapping register 0, offset: 0x380 */
  uint8_t RESERVED_14[4];
  __IO uint32_t TGSLR;                             /**< Time gate scheduling lookahead register, offset: 0x388 */
  uint8_t RESERVED_15[4];
  __IO uint32_t PTCTSDR[ENETC_BASE_TC_TBS_NUM_COUNT]; /**< Port traffic class a time specific departure register, array offset: 0x390, array step: 0x4 */
  uint8_t RESERVED_16[1104];
  __I  uint32_t SMCAPR;                            /**< Switch management capability register, offset: 0x800 */
  uint8_t RESERVED_17[124];
  __IO uint32_t SMHRBDRMR[ENETC_BASE_NUM_SMHRBDRMR_COUNT]; /**< Switch management host reason 1 receive BD ring mapping register..Switch management host reason 15 receive BD ring mapping register, array offset: 0x880, array step: 0x4 */
  uint8_t RESERVED_18[5956];
  struct ENETC_BASE_NUM_SI {                       /* offset: 0x2000, array step: 0x80 */
    __IO uint32_t PSIPMAR0;                          /**< Port station interface 0 primary MAC address register 0..Port station interface 5 primary MAC address register 0, array offset: 0x2000, array step: 0x80 */
    __IO uint32_t PSIPMAR1;                          /**< Port station interface 0 primary MAC address register 1..Port station interface 5 primary MAC address register 1, array offset: 0x2004, array step: 0x80 */
    __IO uint32_t PSIVLANR;                          /**< Port station interface 0 VLAN register..Port station interface 5 VLAN register, array offset: 0x2008, array step: 0x80 */
    uint8_t RESERVED_0[4];
    __IO uint32_t PSICFGR0;                          /**< Port station interface 0 configuration register 0..Port station interface 5 configuration register 0, array offset: 0x2010, array step: 0x80 */
    __IO uint32_t PSICFGR1;                          /**< Port station interface 1 configuration register 1..Port station interface 5 configuration register 1, array offset: 0x2014, array step: 0x80, valid indices: [1-5] */
    __IO uint32_t PSICFGR2;                          /**< Port station interface 0 configuration register 2..Port station interface 5 configuration register 2, array offset: 0x2018, array step: 0x80 */
    uint8_t RESERVED_1[20];
    __IO uint32_t PSIVMAFCFGR;                       /**< Port station interface 0 VSI MAC address filtering configuration register..Port station interface 5 VSI MAC address filtering configuration register, array offset: 0x2030, array step: 0x80 */
    __IO uint32_t PSIVLANFCFGR;                      /**< Port station interface 0 VLAN filtering configuration register..Port station interface 5 VLAN filtering configuration register, array offset: 0x2034, array step: 0x80 */
    uint8_t RESERVED_2[8];
    __I  uint32_t PSIRFSCFGR;                        /**< Port station interface 0 RFS configuration register..Port station interface 5 RFS configuration register, array offset: 0x2040, array step: 0x80 */
    uint8_t RESERVED_3[12];
    __IO uint32_t PSIUMHFR0;                         /**< Port station interface 0 unicast MAC hash filter register 0..Port station interface 5 unicast MAC hash filter register 0, array offset: 0x2050, array step: 0x80 */
    __IO uint32_t PSIUMHFR1;                         /**< Port station interface 0 unicast MAC hash filter register 1..Port station interface 5 unicast MAC hash filter register 1, array offset: 0x2054, array step: 0x80 */
    __IO uint32_t PSIMMHFR0;                         /**< Port station interface 0 multicast MAC hash filter register 0..Port station interface 5 multicast MAC hash filter register 0, array offset: 0x2058, array step: 0x80 */
    __IO uint32_t PSIMMHFR1;                         /**< Port station interface 0 multicast MAC hash filter register 1..Port station interface 5 multicast MAC hash filter register 1, array offset: 0x205C, array step: 0x80 */
    __IO uint32_t PSIVHFR0;                          /**< Port station interface 0 VLAN hash filter register 0..Port station interface 5 VLAN hash filter register 0, array offset: 0x2060, array step: 0x80 */
    __IO uint32_t PSIVHFR1;                          /**< Port station interface 0 VLAN hash filter register 1..Port station interface 5 VLAN hash filter register 1, array offset: 0x2064, array step: 0x80 */
    uint8_t RESERVED_4[24];
  } NUM_SI[ENETC_BASE_NUM_SI_COUNT];
} ENETC_BASE_Type, *ENETC_BASE_MemMapPtr;

/** Number of instances of the ENETC_BASE module. */
#define ENETC_BASE_INSTANCE_COUNT                (1u)

/* ENETC_BASE - Peripheral instance base addresses */
/** Peripheral NETC__ENETC0_BASE base address */
#define IP_NETC__ENETC0_BASE_BASE                (0x6D090000u)
/** Peripheral NETC__ENETC0_BASE base pointer */
#define IP_NETC__ENETC0_BASE                     ((ENETC_BASE_Type *)IP_NETC__ENETC0_BASE_BASE)
/** Array initializer of ENETC_BASE peripheral base addresses */
#define IP_ENETC_BASE_BASE_ADDRS                 { IP_NETC__ENETC0_BASE_BASE }
/** Array initializer of ENETC_BASE peripheral base pointers */
#define IP_ENETC_BASE_BASE_PTRS                  { IP_NETC__ENETC0_BASE }

/* ----------------------------------------------------------------------------
   -- ENETC_BASE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_BASE_Register_Masks ENETC_BASE Register Masks
 * @{
 */

/*! @name ECAPR0 - ENETC capability register 0 */
/*! @{ */

#define ENETC_BASE_ECAPR0_RFS_MASK               (0x4U)
#define ENETC_BASE_ECAPR0_RFS_SHIFT              (2U)
#define ENETC_BASE_ECAPR0_RFS_WIDTH              (1U)
#define ENETC_BASE_ECAPR0_RFS(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR0_RFS_SHIFT)) & ENETC_BASE_ECAPR0_RFS_MASK)

#define ENETC_BASE_ECAPR0_ET_MASK                (0x10U)
#define ENETC_BASE_ECAPR0_ET_SHIFT               (4U)
#define ENETC_BASE_ECAPR0_ET_WIDTH               (1U)
#define ENETC_BASE_ECAPR0_ET(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR0_ET_SHIFT)) & ENETC_BASE_ECAPR0_ET_MASK)

#define ENETC_BASE_ECAPR0_TSD_MASK               (0x20U)
#define ENETC_BASE_ECAPR0_TSD_SHIFT              (5U)
#define ENETC_BASE_ECAPR0_TSD_WIDTH              (1U)
#define ENETC_BASE_ECAPR0_TSD(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR0_TSD_SHIFT)) & ENETC_BASE_ECAPR0_TSD_MASK)

#define ENETC_BASE_ECAPR0_RSS_MASK               (0x100U)
#define ENETC_BASE_ECAPR0_RSS_SHIFT              (8U)
#define ENETC_BASE_ECAPR0_RSS_WIDTH              (1U)
#define ENETC_BASE_ECAPR0_RSS(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR0_RSS_SHIFT)) & ENETC_BASE_ECAPR0_RSS_MASK)

#define ENETC_BASE_ECAPR0_RSC_MASK               (0x200U)
#define ENETC_BASE_ECAPR0_RSC_SHIFT              (9U)
#define ENETC_BASE_ECAPR0_RSC_WIDTH              (1U)
#define ENETC_BASE_ECAPR0_RSC(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR0_RSC_SHIFT)) & ENETC_BASE_ECAPR0_RSC_MASK)

#define ENETC_BASE_ECAPR0_LSO_MASK               (0x400U)
#define ENETC_BASE_ECAPR0_LSO_SHIFT              (10U)
#define ENETC_BASE_ECAPR0_LSO_WIDTH              (1U)
#define ENETC_BASE_ECAPR0_LSO(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR0_LSO_SHIFT)) & ENETC_BASE_ECAPR0_LSO_MASK)

#define ENETC_BASE_ECAPR0_WO_MASK                (0x2000U)
#define ENETC_BASE_ECAPR0_WO_SHIFT               (13U)
#define ENETC_BASE_ECAPR0_WO_WIDTH               (1U)
#define ENETC_BASE_ECAPR0_WO(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR0_WO_SHIFT)) & ENETC_BASE_ECAPR0_WO_MASK)

#define ENETC_BASE_ECAPR0_FS_MASK                (0x10000U)
#define ENETC_BASE_ECAPR0_FS_SHIFT               (16U)
#define ENETC_BASE_ECAPR0_FS_WIDTH               (1U)
#define ENETC_BASE_ECAPR0_FS(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR0_FS_SHIFT)) & ENETC_BASE_ECAPR0_FS_MASK)

#define ENETC_BASE_ECAPR0_FCSU_MASK              (0x100000U)
#define ENETC_BASE_ECAPR0_FCSU_SHIFT             (20U)
#define ENETC_BASE_ECAPR0_FCSU_WIDTH             (1U)
#define ENETC_BASE_ECAPR0_FCSU(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR0_FCSU_SHIFT)) & ENETC_BASE_ECAPR0_FCSU_MASK)
/*! @} */

/*! @name ECAPR1 - ENETC capability register 1 */
/*! @{ */

#define ENETC_BASE_ECAPR1_NUM_TCS_MASK           (0x70U)
#define ENETC_BASE_ECAPR1_NUM_TCS_SHIFT          (4U)
#define ENETC_BASE_ECAPR1_NUM_TCS_WIDTH          (3U)
#define ENETC_BASE_ECAPR1_NUM_TCS(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR1_NUM_TCS_SHIFT)) & ENETC_BASE_ECAPR1_NUM_TCS_MASK)

#define ENETC_BASE_ECAPR1_NUM_MCH_MASK           (0x300U)
#define ENETC_BASE_ECAPR1_NUM_MCH_SHIFT          (8U)
#define ENETC_BASE_ECAPR1_NUM_MCH_WIDTH          (2U)
#define ENETC_BASE_ECAPR1_NUM_MCH(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR1_NUM_MCH_SHIFT)) & ENETC_BASE_ECAPR1_NUM_MCH_MASK)

#define ENETC_BASE_ECAPR1_NUM_UCH_MASK           (0xC00U)
#define ENETC_BASE_ECAPR1_NUM_UCH_SHIFT          (10U)
#define ENETC_BASE_ECAPR1_NUM_UCH_WIDTH          (2U)
#define ENETC_BASE_ECAPR1_NUM_UCH(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR1_NUM_UCH_SHIFT)) & ENETC_BASE_ECAPR1_NUM_UCH_MASK)

#define ENETC_BASE_ECAPR1_NUM_MSIX_MASK          (0x7FF000U)
#define ENETC_BASE_ECAPR1_NUM_MSIX_SHIFT         (12U)
#define ENETC_BASE_ECAPR1_NUM_MSIX_WIDTH         (11U)
#define ENETC_BASE_ECAPR1_NUM_MSIX(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR1_NUM_MSIX_SHIFT)) & ENETC_BASE_ECAPR1_NUM_MSIX_MASK)

#define ENETC_BASE_ECAPR1_NUM_VSI_MASK           (0xF000000U)
#define ENETC_BASE_ECAPR1_NUM_VSI_SHIFT          (24U)
#define ENETC_BASE_ECAPR1_NUM_VSI_WIDTH          (4U)
#define ENETC_BASE_ECAPR1_NUM_VSI(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR1_NUM_VSI_SHIFT)) & ENETC_BASE_ECAPR1_NUM_VSI_MASK)

#define ENETC_BASE_ECAPR1_NUM_IPV_MASK           (0x80000000U)
#define ENETC_BASE_ECAPR1_NUM_IPV_SHIFT          (31U)
#define ENETC_BASE_ECAPR1_NUM_IPV_WIDTH          (1U)
#define ENETC_BASE_ECAPR1_NUM_IPV(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR1_NUM_IPV_SHIFT)) & ENETC_BASE_ECAPR1_NUM_IPV_MASK)
/*! @} */

/*! @name ECAPR2 - ENETC capability register 2 */
/*! @{ */

#define ENETC_BASE_ECAPR2_NUM_TX_BDR_MASK        (0x3FFU)
#define ENETC_BASE_ECAPR2_NUM_TX_BDR_SHIFT       (0U)
#define ENETC_BASE_ECAPR2_NUM_TX_BDR_WIDTH       (10U)
#define ENETC_BASE_ECAPR2_NUM_TX_BDR(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR2_NUM_TX_BDR_SHIFT)) & ENETC_BASE_ECAPR2_NUM_TX_BDR_MASK)

#define ENETC_BASE_ECAPR2_NUM_RX_BDR_MASK        (0x3FF0000U)
#define ENETC_BASE_ECAPR2_NUM_RX_BDR_SHIFT       (16U)
#define ENETC_BASE_ECAPR2_NUM_RX_BDR_WIDTH       (10U)
#define ENETC_BASE_ECAPR2_NUM_RX_BDR(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_ECAPR2_NUM_RX_BDR_SHIFT)) & ENETC_BASE_ECAPR2_NUM_RX_BDR_MASK)
/*! @} */

/*! @name PMR - Port mode register */
/*! @{ */

#define ENETC_BASE_PMR_SI0EN_MASK                (0x10000U)
#define ENETC_BASE_PMR_SI0EN_SHIFT               (16U)
#define ENETC_BASE_PMR_SI0EN_WIDTH               (1U)
#define ENETC_BASE_PMR_SI0EN(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PMR_SI0EN_SHIFT)) & ENETC_BASE_PMR_SI0EN_MASK)

#define ENETC_BASE_PMR_SI1EN_MASK                (0x20000U)
#define ENETC_BASE_PMR_SI1EN_SHIFT               (17U)
#define ENETC_BASE_PMR_SI1EN_WIDTH               (1U)
#define ENETC_BASE_PMR_SI1EN(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PMR_SI1EN_SHIFT)) & ENETC_BASE_PMR_SI1EN_MASK)

#define ENETC_BASE_PMR_SI2EN_MASK                (0x40000U)
#define ENETC_BASE_PMR_SI2EN_SHIFT               (18U)
#define ENETC_BASE_PMR_SI2EN_WIDTH               (1U)
#define ENETC_BASE_PMR_SI2EN(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PMR_SI2EN_SHIFT)) & ENETC_BASE_PMR_SI2EN_MASK)

#define ENETC_BASE_PMR_SI3EN_MASK                (0x80000U)
#define ENETC_BASE_PMR_SI3EN_SHIFT               (19U)
#define ENETC_BASE_PMR_SI3EN_WIDTH               (1U)
#define ENETC_BASE_PMR_SI3EN(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PMR_SI3EN_SHIFT)) & ENETC_BASE_PMR_SI3EN_MASK)

#define ENETC_BASE_PMR_SI4EN_MASK                (0x100000U)
#define ENETC_BASE_PMR_SI4EN_SHIFT               (20U)
#define ENETC_BASE_PMR_SI4EN_WIDTH               (1U)
#define ENETC_BASE_PMR_SI4EN(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PMR_SI4EN_SHIFT)) & ENETC_BASE_PMR_SI4EN_MASK)

#define ENETC_BASE_PMR_SI5EN_MASK                (0x200000U)
#define ENETC_BASE_PMR_SI5EN_SHIFT               (21U)
#define ENETC_BASE_PMR_SI5EN_WIDTH               (1U)
#define ENETC_BASE_PMR_SI5EN(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PMR_SI5EN_SHIFT)) & ENETC_BASE_PMR_SI5EN_MASK)
/*! @} */

/*! @name PONVLANR - Port outer native VLAN register */
/*! @{ */

#define ENETC_BASE_PONVLANR_VID_MASK             (0xFFFU)
#define ENETC_BASE_PONVLANR_VID_SHIFT            (0U)
#define ENETC_BASE_PONVLANR_VID_WIDTH            (12U)
#define ENETC_BASE_PONVLANR_VID(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PONVLANR_VID_SHIFT)) & ENETC_BASE_PONVLANR_VID_MASK)

#define ENETC_BASE_PONVLANR_DEI_MASK             (0x1000U)
#define ENETC_BASE_PONVLANR_DEI_SHIFT            (12U)
#define ENETC_BASE_PONVLANR_DEI_WIDTH            (1U)
#define ENETC_BASE_PONVLANR_DEI(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PONVLANR_DEI_SHIFT)) & ENETC_BASE_PONVLANR_DEI_MASK)

#define ENETC_BASE_PONVLANR_PCP_MASK             (0xE000U)
#define ENETC_BASE_PONVLANR_PCP_SHIFT            (13U)
#define ENETC_BASE_PONVLANR_PCP_WIDTH            (3U)
#define ENETC_BASE_PONVLANR_PCP(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PONVLANR_PCP_SHIFT)) & ENETC_BASE_PONVLANR_PCP_MASK)

#define ENETC_BASE_PONVLANR_TPID_MASK            (0x30000U)
#define ENETC_BASE_PONVLANR_TPID_SHIFT           (16U)
#define ENETC_BASE_PONVLANR_TPID_WIDTH           (2U)
#define ENETC_BASE_PONVLANR_TPID(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PONVLANR_TPID_SHIFT)) & ENETC_BASE_PONVLANR_TPID_MASK)

#define ENETC_BASE_PONVLANR_PNE_MASK             (0x40000U)
#define ENETC_BASE_PONVLANR_PNE_SHIFT            (18U)
#define ENETC_BASE_PONVLANR_PNE_WIDTH            (1U)
#define ENETC_BASE_PONVLANR_PNE(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PONVLANR_PNE_SHIFT)) & ENETC_BASE_PONVLANR_PNE_MASK)

#define ENETC_BASE_PONVLANR_VZE_MASK             (0x80000U)
#define ENETC_BASE_PONVLANR_VZE_SHIFT            (19U)
#define ENETC_BASE_PONVLANR_VZE_WIDTH            (1U)
#define ENETC_BASE_PONVLANR_VZE(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PONVLANR_VZE_SHIFT)) & ENETC_BASE_PONVLANR_VZE_MASK)
/*! @} */

/*! @name PINVLANR - Port inner native VLAN register */
/*! @{ */

#define ENETC_BASE_PINVLANR_VID_MASK             (0xFFFU)
#define ENETC_BASE_PINVLANR_VID_SHIFT            (0U)
#define ENETC_BASE_PINVLANR_VID_WIDTH            (12U)
#define ENETC_BASE_PINVLANR_VID(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PINVLANR_VID_SHIFT)) & ENETC_BASE_PINVLANR_VID_MASK)

#define ENETC_BASE_PINVLANR_DEI_MASK             (0x1000U)
#define ENETC_BASE_PINVLANR_DEI_SHIFT            (12U)
#define ENETC_BASE_PINVLANR_DEI_WIDTH            (1U)
#define ENETC_BASE_PINVLANR_DEI(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PINVLANR_DEI_SHIFT)) & ENETC_BASE_PINVLANR_DEI_MASK)

#define ENETC_BASE_PINVLANR_PCP_MASK             (0xE000U)
#define ENETC_BASE_PINVLANR_PCP_SHIFT            (13U)
#define ENETC_BASE_PINVLANR_PCP_WIDTH            (3U)
#define ENETC_BASE_PINVLANR_PCP(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PINVLANR_PCP_SHIFT)) & ENETC_BASE_PINVLANR_PCP_MASK)

#define ENETC_BASE_PINVLANR_TPID_MASK            (0x30000U)
#define ENETC_BASE_PINVLANR_TPID_SHIFT           (16U)
#define ENETC_BASE_PINVLANR_TPID_WIDTH           (2U)
#define ENETC_BASE_PINVLANR_TPID(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PINVLANR_TPID_SHIFT)) & ENETC_BASE_PINVLANR_TPID_MASK)

#define ENETC_BASE_PINVLANR_PNE_MASK             (0x40000U)
#define ENETC_BASE_PINVLANR_PNE_SHIFT            (18U)
#define ENETC_BASE_PINVLANR_PNE_WIDTH            (1U)
#define ENETC_BASE_PINVLANR_PNE(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PINVLANR_PNE_SHIFT)) & ENETC_BASE_PINVLANR_PNE_MASK)

#define ENETC_BASE_PINVLANR_VZE_MASK             (0x80000U)
#define ENETC_BASE_PINVLANR_VZE_SHIFT            (19U)
#define ENETC_BASE_PINVLANR_VZE_WIDTH            (1U)
#define ENETC_BASE_PINVLANR_VZE(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PINVLANR_VZE_SHIFT)) & ENETC_BASE_PINVLANR_VZE_MASK)
/*! @} */

/*! @name PVCLCTR - Port VLAN classification control register */
/*! @{ */

#define ENETC_BASE_PVCLCTR_OAI_MASK              (0x200U)
#define ENETC_BASE_PVCLCTR_OAI_SHIFT             (9U)
#define ENETC_BASE_PVCLCTR_OAI_WIDTH             (1U)
#define ENETC_BASE_PVCLCTR_OAI(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PVCLCTR_OAI_SHIFT)) & ENETC_BASE_PVCLCTR_OAI_MASK)
/*! @} */

/*! @name PARCSCR - Parser checksum configuration register */
/*! @{ */

#define ENETC_BASE_PARCSCR_L4CD_MASK             (0x1U)
#define ENETC_BASE_PARCSCR_L4CD_SHIFT            (0U)
#define ENETC_BASE_PARCSCR_L4CD_WIDTH            (1U)
#define ENETC_BASE_PARCSCR_L4CD(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PARCSCR_L4CD_SHIFT)) & ENETC_BASE_PARCSCR_L4CD_MASK)

#define ENETC_BASE_PARCSCR_L3CD_MASK             (0x2U)
#define ENETC_BASE_PARCSCR_L3CD_SHIFT            (1U)
#define ENETC_BASE_PARCSCR_L3CD_WIDTH            (1U)
#define ENETC_BASE_PARCSCR_L3CD(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PARCSCR_L3CD_SHIFT)) & ENETC_BASE_PARCSCR_L3CD_MASK)
/*! @} */

/*! @name PARCECR - Parser custom EtherType 0 configuration register..Parser custom EtherType 3 configuration register */
/*! @{ */

#define ENETC_BASE_PARCECR_CP_MASK               (0xFU)
#define ENETC_BASE_PARCECR_CP_SHIFT              (0U)
#define ENETC_BASE_PARCECR_CP_WIDTH              (4U)
#define ENETC_BASE_PARCECR_CP(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PARCECR_CP_SHIFT)) & ENETC_BASE_PARCECR_CP_MASK)

#define ENETC_BASE_PARCECR_EN_MASK               (0x20U)
#define ENETC_BASE_PARCECR_EN_SHIFT              (5U)
#define ENETC_BASE_PARCECR_EN_WIDTH              (1U)
#define ENETC_BASE_PARCECR_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PARCECR_EN_SHIFT)) & ENETC_BASE_PARCECR_EN_MASK)

#define ENETC_BASE_PARCECR_ETYPE_MASK            (0xFFFF0000U)
#define ENETC_BASE_PARCECR_ETYPE_SHIFT           (16U)
#define ENETC_BASE_PARCECR_ETYPE_WIDTH           (16U)
#define ENETC_BASE_PARCECR_ETYPE(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PARCECR_ETYPE_SHIFT)) & ENETC_BASE_PARCECR_ETYPE_MASK)
/*! @} */

/*! @name PPAUONTR - Port pause ON threshold register */
/*! @{ */

#define ENETC_BASE_PPAUONTR_THRESH_MASK          (0xFFFFFFU)
#define ENETC_BASE_PPAUONTR_THRESH_SHIFT         (0U)
#define ENETC_BASE_PPAUONTR_THRESH_WIDTH         (24U)
#define ENETC_BASE_PPAUONTR_THRESH(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PPAUONTR_THRESH_SHIFT)) & ENETC_BASE_PPAUONTR_THRESH_MASK)
/*! @} */

/*! @name PPAUOFFTR - Port pause OFF threshold register */
/*! @{ */

#define ENETC_BASE_PPAUOFFTR_THRESH_MASK         (0xFFFFFFU)
#define ENETC_BASE_PPAUOFFTR_THRESH_SHIFT        (0U)
#define ENETC_BASE_PPAUOFFTR_THRESH_WIDTH        (24U)
#define ENETC_BASE_PPAUOFFTR_THRESH(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PPAUOFFTR_THRESH_SHIFT)) & ENETC_BASE_PPAUOFFTR_THRESH_MASK)
/*! @} */

/*! @name PRXMBER - Port receive memory buffer entitlement register */
/*! @{ */

#define ENETC_BASE_PRXMBER_AMOUNT_MASK           (0xFFFFFFU)
#define ENETC_BASE_PRXMBER_AMOUNT_SHIFT          (0U)
#define ENETC_BASE_PRXMBER_AMOUNT_WIDTH          (24U)
#define ENETC_BASE_PRXMBER_AMOUNT(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRXMBER_AMOUNT_SHIFT)) & ENETC_BASE_PRXMBER_AMOUNT_MASK)
/*! @} */

/*! @name PRXMBLR - Port receive memory buffer limit register */
/*! @{ */

#define ENETC_BASE_PRXMBLR_LIMIT_MASK            (0xFFFFFFU)
#define ENETC_BASE_PRXMBLR_LIMIT_SHIFT           (0U)
#define ENETC_BASE_PRXMBLR_LIMIT_WIDTH           (24U)
#define ENETC_BASE_PRXMBLR_LIMIT(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRXMBLR_LIMIT_SHIFT)) & ENETC_BASE_PRXMBLR_LIMIT_MASK)
/*! @} */

/*! @name PRXBCR - Port receive buffer count register */
/*! @{ */

#define ENETC_BASE_PRXBCR_COUNT_MASK             (0xFFFFFFU)
#define ENETC_BASE_PRXBCR_COUNT_SHIFT            (0U)
#define ENETC_BASE_PRXBCR_COUNT_WIDTH            (24U)
#define ENETC_BASE_PRXBCR_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRXBCR_COUNT_SHIFT)) & ENETC_BASE_PRXBCR_COUNT_MASK)
/*! @} */

/*! @name PRXBCHWMR - Port receive buffer count high watermark register */
/*! @{ */

#define ENETC_BASE_PRXBCHWMR_WATERMARK_MASK      (0xFFFFFFU)
#define ENETC_BASE_PRXBCHWMR_WATERMARK_SHIFT     (0U)
#define ENETC_BASE_PRXBCHWMR_WATERMARK_WIDTH     (24U)
#define ENETC_BASE_PRXBCHWMR_WATERMARK(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRXBCHWMR_WATERMARK_SHIFT)) & ENETC_BASE_PRXBCHWMR_WATERMARK_MASK)
/*! @} */

/*! @name PICDRDCR - Port ingress congestion DR0 discard count register..Port ingress congestion DR3 discard count register */
/*! @{ */

#define ENETC_BASE_PICDRDCR_COUNT_MASK           (0xFFFFFFFFU)
#define ENETC_BASE_PICDRDCR_COUNT_SHIFT          (0U)
#define ENETC_BASE_PICDRDCR_COUNT_WIDTH          (32U)
#define ENETC_BASE_PICDRDCR_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PICDRDCR_COUNT_SHIFT)) & ENETC_BASE_PICDRDCR_COUNT_MASK)
/*! @} */

/*! @name PICDRDCRRR - Port ingress congestion DR0 discard count read-reset register..Port ingress congestion DR3 discard count read-reset register */
/*! @{ */

#define ENETC_BASE_PICDRDCRRR_COUNT_MASK         (0xFFFFFFFFU)
#define ENETC_BASE_PICDRDCRRR_COUNT_SHIFT        (0U)
#define ENETC_BASE_PICDRDCRRR_COUNT_WIDTH        (32U)
#define ENETC_BASE_PICDRDCRRR_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PICDRDCRRR_COUNT_SHIFT)) & ENETC_BASE_PICDRDCRRR_COUNT_MASK)
/*! @} */

/*! @name PICPDSR - Port ingress congestion priority discard status register */
/*! @{ */

#define ENETC_BASE_PICPDSR_DR0_P0DS_MASK         (0x1U)
#define ENETC_BASE_PICPDSR_DR0_P0DS_SHIFT        (0U)
#define ENETC_BASE_PICPDSR_DR0_P0DS_WIDTH        (1U)
#define ENETC_BASE_PICPDSR_DR0_P0DS(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PICPDSR_DR0_P0DS_SHIFT)) & ENETC_BASE_PICPDSR_DR0_P0DS_MASK)

#define ENETC_BASE_PICPDSR_DR0_P1DS_MASK         (0x10U)
#define ENETC_BASE_PICPDSR_DR0_P1DS_SHIFT        (4U)
#define ENETC_BASE_PICPDSR_DR0_P1DS_WIDTH        (1U)
#define ENETC_BASE_PICPDSR_DR0_P1DS(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PICPDSR_DR0_P1DS_SHIFT)) & ENETC_BASE_PICPDSR_DR0_P1DS_MASK)

#define ENETC_BASE_PICPDSR_DR1_P0DS_MASK         (0x100U)
#define ENETC_BASE_PICPDSR_DR1_P0DS_SHIFT        (8U)
#define ENETC_BASE_PICPDSR_DR1_P0DS_WIDTH        (1U)
#define ENETC_BASE_PICPDSR_DR1_P0DS(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PICPDSR_DR1_P0DS_SHIFT)) & ENETC_BASE_PICPDSR_DR1_P0DS_MASK)

#define ENETC_BASE_PICPDSR_DR1_P1DS_MASK         (0x1000U)
#define ENETC_BASE_PICPDSR_DR1_P1DS_SHIFT        (12U)
#define ENETC_BASE_PICPDSR_DR1_P1DS_WIDTH        (1U)
#define ENETC_BASE_PICPDSR_DR1_P1DS(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PICPDSR_DR1_P1DS_SHIFT)) & ENETC_BASE_PICPDSR_DR1_P1DS_MASK)

#define ENETC_BASE_PICPDSR_DR2_P0DS_MASK         (0x10000U)
#define ENETC_BASE_PICPDSR_DR2_P0DS_SHIFT        (16U)
#define ENETC_BASE_PICPDSR_DR2_P0DS_WIDTH        (1U)
#define ENETC_BASE_PICPDSR_DR2_P0DS(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PICPDSR_DR2_P0DS_SHIFT)) & ENETC_BASE_PICPDSR_DR2_P0DS_MASK)

#define ENETC_BASE_PICPDSR_DR2_P1DS_MASK         (0x100000U)
#define ENETC_BASE_PICPDSR_DR2_P1DS_SHIFT        (20U)
#define ENETC_BASE_PICPDSR_DR2_P1DS_WIDTH        (1U)
#define ENETC_BASE_PICPDSR_DR2_P1DS(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PICPDSR_DR2_P1DS_SHIFT)) & ENETC_BASE_PICPDSR_DR2_P1DS_MASK)

#define ENETC_BASE_PICPDSR_DR3_P0DS_MASK         (0x1000000U)
#define ENETC_BASE_PICPDSR_DR3_P0DS_SHIFT        (24U)
#define ENETC_BASE_PICPDSR_DR3_P0DS_WIDTH        (1U)
#define ENETC_BASE_PICPDSR_DR3_P0DS(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PICPDSR_DR3_P0DS_SHIFT)) & ENETC_BASE_PICPDSR_DR3_P0DS_MASK)

#define ENETC_BASE_PICPDSR_DR3_P1DS_MASK         (0x10000000U)
#define ENETC_BASE_PICPDSR_DR3_P1DS_SHIFT        (28U)
#define ENETC_BASE_PICPDSR_DR3_P1DS_WIDTH        (1U)
#define ENETC_BASE_PICPDSR_DR3_P1DS(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PICPDSR_DR3_P1DS_SHIFT)) & ENETC_BASE_PICPDSR_DR3_P1DS_MASK)
/*! @} */

/*! @name PSIPMMR - Port station interface promiscuous MAC mode register */
/*! @{ */

#define ENETC_BASE_PSIPMMR_SI0_MAC_UP_MASK       (0x1U)
#define ENETC_BASE_PSIPMMR_SI0_MAC_UP_SHIFT      (0U)
#define ENETC_BASE_PSIPMMR_SI0_MAC_UP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI0_MAC_UP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI0_MAC_UP_SHIFT)) & ENETC_BASE_PSIPMMR_SI0_MAC_UP_MASK)

#define ENETC_BASE_PSIPMMR_SI1_MAC_UP_MASK       (0x2U)
#define ENETC_BASE_PSIPMMR_SI1_MAC_UP_SHIFT      (1U)
#define ENETC_BASE_PSIPMMR_SI1_MAC_UP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI1_MAC_UP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI1_MAC_UP_SHIFT)) & ENETC_BASE_PSIPMMR_SI1_MAC_UP_MASK)

#define ENETC_BASE_PSIPMMR_SI2_MAC_UP_MASK       (0x4U)
#define ENETC_BASE_PSIPMMR_SI2_MAC_UP_SHIFT      (2U)
#define ENETC_BASE_PSIPMMR_SI2_MAC_UP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI2_MAC_UP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI2_MAC_UP_SHIFT)) & ENETC_BASE_PSIPMMR_SI2_MAC_UP_MASK)

#define ENETC_BASE_PSIPMMR_SI3_MAC_UP_MASK       (0x8U)
#define ENETC_BASE_PSIPMMR_SI3_MAC_UP_SHIFT      (3U)
#define ENETC_BASE_PSIPMMR_SI3_MAC_UP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI3_MAC_UP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI3_MAC_UP_SHIFT)) & ENETC_BASE_PSIPMMR_SI3_MAC_UP_MASK)

#define ENETC_BASE_PSIPMMR_SI4_MAC_UP_MASK       (0x10U)
#define ENETC_BASE_PSIPMMR_SI4_MAC_UP_SHIFT      (4U)
#define ENETC_BASE_PSIPMMR_SI4_MAC_UP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI4_MAC_UP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI4_MAC_UP_SHIFT)) & ENETC_BASE_PSIPMMR_SI4_MAC_UP_MASK)

#define ENETC_BASE_PSIPMMR_SI5_MAC_UP_MASK       (0x20U)
#define ENETC_BASE_PSIPMMR_SI5_MAC_UP_SHIFT      (5U)
#define ENETC_BASE_PSIPMMR_SI5_MAC_UP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI5_MAC_UP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI5_MAC_UP_SHIFT)) & ENETC_BASE_PSIPMMR_SI5_MAC_UP_MASK)

#define ENETC_BASE_PSIPMMR_SI0_MAC_MP_MASK       (0x10000U)
#define ENETC_BASE_PSIPMMR_SI0_MAC_MP_SHIFT      (16U)
#define ENETC_BASE_PSIPMMR_SI0_MAC_MP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI0_MAC_MP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI0_MAC_MP_SHIFT)) & ENETC_BASE_PSIPMMR_SI0_MAC_MP_MASK)

#define ENETC_BASE_PSIPMMR_SI1_MAC_MP_MASK       (0x20000U)
#define ENETC_BASE_PSIPMMR_SI1_MAC_MP_SHIFT      (17U)
#define ENETC_BASE_PSIPMMR_SI1_MAC_MP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI1_MAC_MP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI1_MAC_MP_SHIFT)) & ENETC_BASE_PSIPMMR_SI1_MAC_MP_MASK)

#define ENETC_BASE_PSIPMMR_SI2_MAC_MP_MASK       (0x40000U)
#define ENETC_BASE_PSIPMMR_SI2_MAC_MP_SHIFT      (18U)
#define ENETC_BASE_PSIPMMR_SI2_MAC_MP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI2_MAC_MP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI2_MAC_MP_SHIFT)) & ENETC_BASE_PSIPMMR_SI2_MAC_MP_MASK)

#define ENETC_BASE_PSIPMMR_SI3_MAC_MP_MASK       (0x80000U)
#define ENETC_BASE_PSIPMMR_SI3_MAC_MP_SHIFT      (19U)
#define ENETC_BASE_PSIPMMR_SI3_MAC_MP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI3_MAC_MP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI3_MAC_MP_SHIFT)) & ENETC_BASE_PSIPMMR_SI3_MAC_MP_MASK)

#define ENETC_BASE_PSIPMMR_SI4_MAC_MP_MASK       (0x100000U)
#define ENETC_BASE_PSIPMMR_SI4_MAC_MP_SHIFT      (20U)
#define ENETC_BASE_PSIPMMR_SI4_MAC_MP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI4_MAC_MP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI4_MAC_MP_SHIFT)) & ENETC_BASE_PSIPMMR_SI4_MAC_MP_MASK)

#define ENETC_BASE_PSIPMMR_SI5_MAC_MP_MASK       (0x200000U)
#define ENETC_BASE_PSIPMMR_SI5_MAC_MP_SHIFT      (21U)
#define ENETC_BASE_PSIPMMR_SI5_MAC_MP_WIDTH      (1U)
#define ENETC_BASE_PSIPMMR_SI5_MAC_MP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMMR_SI5_MAC_MP_SHIFT)) & ENETC_BASE_PSIPMMR_SI5_MAC_MP_MASK)
/*! @} */

/*! @name PSIPVMR - Port station interface promiscuous VLAN mode register */
/*! @{ */

#define ENETC_BASE_PSIPVMR_SI0_VLAN_P_MASK       (0x1U)
#define ENETC_BASE_PSIPVMR_SI0_VLAN_P_SHIFT      (0U)
#define ENETC_BASE_PSIPVMR_SI0_VLAN_P_WIDTH      (1U)
#define ENETC_BASE_PSIPVMR_SI0_VLAN_P(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI0_VLAN_P_SHIFT)) & ENETC_BASE_PSIPVMR_SI0_VLAN_P_MASK)

#define ENETC_BASE_PSIPVMR_SI1_VLAN_P_MASK       (0x2U)
#define ENETC_BASE_PSIPVMR_SI1_VLAN_P_SHIFT      (1U)
#define ENETC_BASE_PSIPVMR_SI1_VLAN_P_WIDTH      (1U)
#define ENETC_BASE_PSIPVMR_SI1_VLAN_P(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI1_VLAN_P_SHIFT)) & ENETC_BASE_PSIPVMR_SI1_VLAN_P_MASK)

#define ENETC_BASE_PSIPVMR_SI2_VLAN_P_MASK       (0x4U)
#define ENETC_BASE_PSIPVMR_SI2_VLAN_P_SHIFT      (2U)
#define ENETC_BASE_PSIPVMR_SI2_VLAN_P_WIDTH      (1U)
#define ENETC_BASE_PSIPVMR_SI2_VLAN_P(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI2_VLAN_P_SHIFT)) & ENETC_BASE_PSIPVMR_SI2_VLAN_P_MASK)

#define ENETC_BASE_PSIPVMR_SI3_VLAN_P_MASK       (0x8U)
#define ENETC_BASE_PSIPVMR_SI3_VLAN_P_SHIFT      (3U)
#define ENETC_BASE_PSIPVMR_SI3_VLAN_P_WIDTH      (1U)
#define ENETC_BASE_PSIPVMR_SI3_VLAN_P(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI3_VLAN_P_SHIFT)) & ENETC_BASE_PSIPVMR_SI3_VLAN_P_MASK)

#define ENETC_BASE_PSIPVMR_SI4_VLAN_P_MASK       (0x10U)
#define ENETC_BASE_PSIPVMR_SI4_VLAN_P_SHIFT      (4U)
#define ENETC_BASE_PSIPVMR_SI4_VLAN_P_WIDTH      (1U)
#define ENETC_BASE_PSIPVMR_SI4_VLAN_P(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI4_VLAN_P_SHIFT)) & ENETC_BASE_PSIPVMR_SI4_VLAN_P_MASK)

#define ENETC_BASE_PSIPVMR_SI5_VLAN_P_MASK       (0x20U)
#define ENETC_BASE_PSIPVMR_SI5_VLAN_P_SHIFT      (5U)
#define ENETC_BASE_PSIPVMR_SI5_VLAN_P_WIDTH      (1U)
#define ENETC_BASE_PSIPVMR_SI5_VLAN_P(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI5_VLAN_P_SHIFT)) & ENETC_BASE_PSIPVMR_SI5_VLAN_P_MASK)

#define ENETC_BASE_PSIPVMR_SI0_VLAN_UTA_MASK     (0x10000U)
#define ENETC_BASE_PSIPVMR_SI0_VLAN_UTA_SHIFT    (16U)
#define ENETC_BASE_PSIPVMR_SI0_VLAN_UTA_WIDTH    (1U)
#define ENETC_BASE_PSIPVMR_SI0_VLAN_UTA(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI0_VLAN_UTA_SHIFT)) & ENETC_BASE_PSIPVMR_SI0_VLAN_UTA_MASK)

#define ENETC_BASE_PSIPVMR_SI1_VLAN_UTA_MASK     (0x20000U)
#define ENETC_BASE_PSIPVMR_SI1_VLAN_UTA_SHIFT    (17U)
#define ENETC_BASE_PSIPVMR_SI1_VLAN_UTA_WIDTH    (1U)
#define ENETC_BASE_PSIPVMR_SI1_VLAN_UTA(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI1_VLAN_UTA_SHIFT)) & ENETC_BASE_PSIPVMR_SI1_VLAN_UTA_MASK)

#define ENETC_BASE_PSIPVMR_SI2_VLAN_UTA_MASK     (0x40000U)
#define ENETC_BASE_PSIPVMR_SI2_VLAN_UTA_SHIFT    (18U)
#define ENETC_BASE_PSIPVMR_SI2_VLAN_UTA_WIDTH    (1U)
#define ENETC_BASE_PSIPVMR_SI2_VLAN_UTA(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI2_VLAN_UTA_SHIFT)) & ENETC_BASE_PSIPVMR_SI2_VLAN_UTA_MASK)

#define ENETC_BASE_PSIPVMR_SI3_VLAN_UTA_MASK     (0x80000U)
#define ENETC_BASE_PSIPVMR_SI3_VLAN_UTA_SHIFT    (19U)
#define ENETC_BASE_PSIPVMR_SI3_VLAN_UTA_WIDTH    (1U)
#define ENETC_BASE_PSIPVMR_SI3_VLAN_UTA(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI3_VLAN_UTA_SHIFT)) & ENETC_BASE_PSIPVMR_SI3_VLAN_UTA_MASK)

#define ENETC_BASE_PSIPVMR_SI4_VLAN_UTA_MASK     (0x100000U)
#define ENETC_BASE_PSIPVMR_SI4_VLAN_UTA_SHIFT    (20U)
#define ENETC_BASE_PSIPVMR_SI4_VLAN_UTA_WIDTH    (1U)
#define ENETC_BASE_PSIPVMR_SI4_VLAN_UTA(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI4_VLAN_UTA_SHIFT)) & ENETC_BASE_PSIPVMR_SI4_VLAN_UTA_MASK)

#define ENETC_BASE_PSIPVMR_SI5_VLAN_UTA_MASK     (0x200000U)
#define ENETC_BASE_PSIPVMR_SI5_VLAN_UTA_SHIFT    (21U)
#define ENETC_BASE_PSIPVMR_SI5_VLAN_UTA_WIDTH    (1U)
#define ENETC_BASE_PSIPVMR_SI5_VLAN_UTA(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPVMR_SI5_VLAN_UTA_SHIFT)) & ENETC_BASE_PSIPVMR_SI5_VLAN_UTA_MASK)
/*! @} */

/*! @name PBFDSIR - Port broadcast frames dropped due to MAC filtering register */
/*! @{ */

#define ENETC_BASE_PBFDSIR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define ENETC_BASE_PBFDSIR_FRAME_DROP_SHIFT      (0U)
#define ENETC_BASE_PBFDSIR_FRAME_DROP_WIDTH      (32U)
#define ENETC_BASE_PBFDSIR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PBFDSIR_FRAME_DROP_SHIFT)) & ENETC_BASE_PBFDSIR_FRAME_DROP_MASK)
/*! @} */

/*! @name PFDMSAPR - Port frame drop MAC source address pruning register */
/*! @{ */

#define ENETC_BASE_PFDMSAPR_FRAME_DROP_MASK      (0xFFFFFFFFU)
#define ENETC_BASE_PFDMSAPR_FRAME_DROP_SHIFT     (0U)
#define ENETC_BASE_PFDMSAPR_FRAME_DROP_WIDTH     (32U)
#define ENETC_BASE_PFDMSAPR_FRAME_DROP(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PFDMSAPR_FRAME_DROP_SHIFT)) & ENETC_BASE_PFDMSAPR_FRAME_DROP_MASK)
/*! @} */

/*! @name PSIMAFCAPR - Port station interface MAC address filtering capability register */
/*! @{ */

#define ENETC_BASE_PSIMAFCAPR_NUM_MAC_AFTE_MASK  (0xFFFU)
#define ENETC_BASE_PSIMAFCAPR_NUM_MAC_AFTE_SHIFT (0U)
#define ENETC_BASE_PSIMAFCAPR_NUM_MAC_AFTE_WIDTH (12U)
#define ENETC_BASE_PSIMAFCAPR_NUM_MAC_AFTE(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIMAFCAPR_NUM_MAC_AFTE_SHIFT)) & ENETC_BASE_PSIMAFCAPR_NUM_MAC_AFTE_MASK)
/*! @} */

/*! @name PUFDMFR - Port unicast frames dropped due to MAC filtering register */
/*! @{ */

#define ENETC_BASE_PUFDMFR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define ENETC_BASE_PUFDMFR_FRAME_DROP_SHIFT      (0U)
#define ENETC_BASE_PUFDMFR_FRAME_DROP_WIDTH      (32U)
#define ENETC_BASE_PUFDMFR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PUFDMFR_FRAME_DROP_SHIFT)) & ENETC_BASE_PUFDMFR_FRAME_DROP_MASK)
/*! @} */

/*! @name PMFDMFR - Port multicast frames dropped due to MAC filtering register */
/*! @{ */

#define ENETC_BASE_PMFDMFR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define ENETC_BASE_PMFDMFR_FRAME_DROP_SHIFT      (0U)
#define ENETC_BASE_PMFDMFR_FRAME_DROP_WIDTH      (32U)
#define ENETC_BASE_PMFDMFR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PMFDMFR_FRAME_DROP_SHIFT)) & ENETC_BASE_PMFDMFR_FRAME_DROP_MASK)
/*! @} */

/*! @name PSIVLANFCAPR - Port station interface VLAN filtering capability register */
/*! @{ */

#define ENETC_BASE_PSIVLANFCAPR_NUM_VLAN_FTE_MASK (0xFFFU)
#define ENETC_BASE_PSIVLANFCAPR_NUM_VLAN_FTE_SHIFT (0U)
#define ENETC_BASE_PSIVLANFCAPR_NUM_VLAN_FTE_WIDTH (12U)
#define ENETC_BASE_PSIVLANFCAPR_NUM_VLAN_FTE(x)  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVLANFCAPR_NUM_VLAN_FTE_SHIFT)) & ENETC_BASE_PSIVLANFCAPR_NUM_VLAN_FTE_MASK)
/*! @} */

/*! @name PSIVLANFMR - Port station interface VLAN filtering mode register */
/*! @{ */

#define ENETC_BASE_PSIVLANFMR_VS_MASK            (0x1U)
#define ENETC_BASE_PSIVLANFMR_VS_SHIFT           (0U)
#define ENETC_BASE_PSIVLANFMR_VS_WIDTH           (1U)
#define ENETC_BASE_PSIVLANFMR_VS(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVLANFMR_VS_SHIFT)) & ENETC_BASE_PSIVLANFMR_VS_MASK)
/*! @} */

/*! @name PUFDVFR - Port unicast frames dropped VLAN filtering register */
/*! @{ */

#define ENETC_BASE_PUFDVFR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define ENETC_BASE_PUFDVFR_FRAME_DROP_SHIFT      (0U)
#define ENETC_BASE_PUFDVFR_FRAME_DROP_WIDTH      (32U)
#define ENETC_BASE_PUFDVFR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PUFDVFR_FRAME_DROP_SHIFT)) & ENETC_BASE_PUFDVFR_FRAME_DROP_MASK)
/*! @} */

/*! @name PMFDVFR - Port multicast frames dropped VLAN filtering register */
/*! @{ */

#define ENETC_BASE_PMFDVFR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define ENETC_BASE_PMFDVFR_FRAME_DROP_SHIFT      (0U)
#define ENETC_BASE_PMFDVFR_FRAME_DROP_WIDTH      (32U)
#define ENETC_BASE_PMFDVFR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PMFDVFR_FRAME_DROP_SHIFT)) & ENETC_BASE_PMFDVFR_FRAME_DROP_MASK)
/*! @} */

/*! @name PBFDVFR - Port broadcast frames dropped VLAN filtering register */
/*! @{ */

#define ENETC_BASE_PBFDVFR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define ENETC_BASE_PBFDVFR_FRAME_DROP_SHIFT      (0U)
#define ENETC_BASE_PBFDVFR_FRAME_DROP_WIDTH      (32U)
#define ENETC_BASE_PBFDVFR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PBFDVFR_FRAME_DROP_SHIFT)) & ENETC_BASE_PBFDVFR_FRAME_DROP_MASK)
/*! @} */

/*! @name PRFSCAPR - Port RFS capability register */
/*! @{ */

#define ENETC_BASE_PRFSCAPR_NUM_RFS_MASK         (0xFFU)
#define ENETC_BASE_PRFSCAPR_NUM_RFS_SHIFT        (0U)
#define ENETC_BASE_PRFSCAPR_NUM_RFS_WIDTH        (8U)
#define ENETC_BASE_PRFSCAPR_NUM_RFS(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRFSCAPR_NUM_RFS_SHIFT)) & ENETC_BASE_PRFSCAPR_NUM_RFS_MASK)
/*! @} */

/*! @name PRFSMR - Port RFS mode register */
/*! @{ */

#define ENETC_BASE_PRFSMR_RFSE_MASK              (0x80000000U)
#define ENETC_BASE_PRFSMR_RFSE_SHIFT             (31U)
#define ENETC_BASE_PRFSMR_RFSE_WIDTH             (1U)
#define ENETC_BASE_PRFSMR_RFSE(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRFSMR_RFSE_SHIFT)) & ENETC_BASE_PRFSMR_RFSE_MASK)
/*! @} */

/*! @name IPV2ICMPMR0 - Receive IPV to ICM priority mapping register 0 */
/*! @{ */

#define ENETC_BASE_IPV2ICMPMR0_IPV0ICM_MASK      (0x1U)
#define ENETC_BASE_IPV2ICMPMR0_IPV0ICM_SHIFT     (0U)
#define ENETC_BASE_IPV2ICMPMR0_IPV0ICM_WIDTH     (1U)
#define ENETC_BASE_IPV2ICMPMR0_IPV0ICM(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_IPV2ICMPMR0_IPV0ICM_SHIFT)) & ENETC_BASE_IPV2ICMPMR0_IPV0ICM_MASK)

#define ENETC_BASE_IPV2ICMPMR0_IPV1ICM_MASK      (0x10U)
#define ENETC_BASE_IPV2ICMPMR0_IPV1ICM_SHIFT     (4U)
#define ENETC_BASE_IPV2ICMPMR0_IPV1ICM_WIDTH     (1U)
#define ENETC_BASE_IPV2ICMPMR0_IPV1ICM(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_IPV2ICMPMR0_IPV1ICM_SHIFT)) & ENETC_BASE_IPV2ICMPMR0_IPV1ICM_MASK)

#define ENETC_BASE_IPV2ICMPMR0_IPV2ICM_MASK      (0x100U)
#define ENETC_BASE_IPV2ICMPMR0_IPV2ICM_SHIFT     (8U)
#define ENETC_BASE_IPV2ICMPMR0_IPV2ICM_WIDTH     (1U)
#define ENETC_BASE_IPV2ICMPMR0_IPV2ICM(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_IPV2ICMPMR0_IPV2ICM_SHIFT)) & ENETC_BASE_IPV2ICMPMR0_IPV2ICM_MASK)

#define ENETC_BASE_IPV2ICMPMR0_IPV3ICM_MASK      (0x1000U)
#define ENETC_BASE_IPV2ICMPMR0_IPV3ICM_SHIFT     (12U)
#define ENETC_BASE_IPV2ICMPMR0_IPV3ICM_WIDTH     (1U)
#define ENETC_BASE_IPV2ICMPMR0_IPV3ICM(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_IPV2ICMPMR0_IPV3ICM_SHIFT)) & ENETC_BASE_IPV2ICMPMR0_IPV3ICM_MASK)

#define ENETC_BASE_IPV2ICMPMR0_IPV4ICM_MASK      (0x10000U)
#define ENETC_BASE_IPV2ICMPMR0_IPV4ICM_SHIFT     (16U)
#define ENETC_BASE_IPV2ICMPMR0_IPV4ICM_WIDTH     (1U)
#define ENETC_BASE_IPV2ICMPMR0_IPV4ICM(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_IPV2ICMPMR0_IPV4ICM_SHIFT)) & ENETC_BASE_IPV2ICMPMR0_IPV4ICM_MASK)

#define ENETC_BASE_IPV2ICMPMR0_IPV5ICM_MASK      (0x100000U)
#define ENETC_BASE_IPV2ICMPMR0_IPV5ICM_SHIFT     (20U)
#define ENETC_BASE_IPV2ICMPMR0_IPV5ICM_WIDTH     (1U)
#define ENETC_BASE_IPV2ICMPMR0_IPV5ICM(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_IPV2ICMPMR0_IPV5ICM_SHIFT)) & ENETC_BASE_IPV2ICMPMR0_IPV5ICM_MASK)

#define ENETC_BASE_IPV2ICMPMR0_IPV6ICM_MASK      (0x1000000U)
#define ENETC_BASE_IPV2ICMPMR0_IPV6ICM_SHIFT     (24U)
#define ENETC_BASE_IPV2ICMPMR0_IPV6ICM_WIDTH     (1U)
#define ENETC_BASE_IPV2ICMPMR0_IPV6ICM(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_IPV2ICMPMR0_IPV6ICM_SHIFT)) & ENETC_BASE_IPV2ICMPMR0_IPV6ICM_MASK)

#define ENETC_BASE_IPV2ICMPMR0_IPV7ICM_MASK      (0x10000000U)
#define ENETC_BASE_IPV2ICMPMR0_IPV7ICM_SHIFT     (28U)
#define ENETC_BASE_IPV2ICMPMR0_IPV7ICM_WIDTH     (1U)
#define ENETC_BASE_IPV2ICMPMR0_IPV7ICM(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_IPV2ICMPMR0_IPV7ICM_SHIFT)) & ENETC_BASE_IPV2ICMPMR0_IPV7ICM_MASK)
/*! @} */

/*! @name PRIO2TCMR0 - Transmit priority to traffic class mapping register 0 */
/*! @{ */

#define ENETC_BASE_PRIO2TCMR0_PRIO0TC_MASK       (0x7U)
#define ENETC_BASE_PRIO2TCMR0_PRIO0TC_SHIFT      (0U)
#define ENETC_BASE_PRIO2TCMR0_PRIO0TC_WIDTH      (3U)
#define ENETC_BASE_PRIO2TCMR0_PRIO0TC(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRIO2TCMR0_PRIO0TC_SHIFT)) & ENETC_BASE_PRIO2TCMR0_PRIO0TC_MASK)

#define ENETC_BASE_PRIO2TCMR0_PRIO1TC_MASK       (0x70U)
#define ENETC_BASE_PRIO2TCMR0_PRIO1TC_SHIFT      (4U)
#define ENETC_BASE_PRIO2TCMR0_PRIO1TC_WIDTH      (3U)
#define ENETC_BASE_PRIO2TCMR0_PRIO1TC(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRIO2TCMR0_PRIO1TC_SHIFT)) & ENETC_BASE_PRIO2TCMR0_PRIO1TC_MASK)

#define ENETC_BASE_PRIO2TCMR0_PRIO2TC_MASK       (0x700U)
#define ENETC_BASE_PRIO2TCMR0_PRIO2TC_SHIFT      (8U)
#define ENETC_BASE_PRIO2TCMR0_PRIO2TC_WIDTH      (3U)
#define ENETC_BASE_PRIO2TCMR0_PRIO2TC(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRIO2TCMR0_PRIO2TC_SHIFT)) & ENETC_BASE_PRIO2TCMR0_PRIO2TC_MASK)

#define ENETC_BASE_PRIO2TCMR0_PRIO3TC_MASK       (0x7000U)
#define ENETC_BASE_PRIO2TCMR0_PRIO3TC_SHIFT      (12U)
#define ENETC_BASE_PRIO2TCMR0_PRIO3TC_WIDTH      (3U)
#define ENETC_BASE_PRIO2TCMR0_PRIO3TC(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRIO2TCMR0_PRIO3TC_SHIFT)) & ENETC_BASE_PRIO2TCMR0_PRIO3TC_MASK)

#define ENETC_BASE_PRIO2TCMR0_PRIO4TC_MASK       (0x70000U)
#define ENETC_BASE_PRIO2TCMR0_PRIO4TC_SHIFT      (16U)
#define ENETC_BASE_PRIO2TCMR0_PRIO4TC_WIDTH      (3U)
#define ENETC_BASE_PRIO2TCMR0_PRIO4TC(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRIO2TCMR0_PRIO4TC_SHIFT)) & ENETC_BASE_PRIO2TCMR0_PRIO4TC_MASK)

#define ENETC_BASE_PRIO2TCMR0_PRIO5TC_MASK       (0x700000U)
#define ENETC_BASE_PRIO2TCMR0_PRIO5TC_SHIFT      (20U)
#define ENETC_BASE_PRIO2TCMR0_PRIO5TC_WIDTH      (3U)
#define ENETC_BASE_PRIO2TCMR0_PRIO5TC(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRIO2TCMR0_PRIO5TC_SHIFT)) & ENETC_BASE_PRIO2TCMR0_PRIO5TC_MASK)

#define ENETC_BASE_PRIO2TCMR0_PRIO6TC_MASK       (0x7000000U)
#define ENETC_BASE_PRIO2TCMR0_PRIO6TC_SHIFT      (24U)
#define ENETC_BASE_PRIO2TCMR0_PRIO6TC_WIDTH      (3U)
#define ENETC_BASE_PRIO2TCMR0_PRIO6TC(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRIO2TCMR0_PRIO6TC_SHIFT)) & ENETC_BASE_PRIO2TCMR0_PRIO6TC_MASK)

#define ENETC_BASE_PRIO2TCMR0_PRIO7TC_MASK       (0x70000000U)
#define ENETC_BASE_PRIO2TCMR0_PRIO7TC_SHIFT      (28U)
#define ENETC_BASE_PRIO2TCMR0_PRIO7TC_WIDTH      (3U)
#define ENETC_BASE_PRIO2TCMR0_PRIO7TC(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PRIO2TCMR0_PRIO7TC_SHIFT)) & ENETC_BASE_PRIO2TCMR0_PRIO7TC_MASK)
/*! @} */

/*! @name TGSLR - Time gate scheduling lookahead register */
/*! @{ */

#define ENETC_BASE_TGSLR_MIN_LOOKAHEAD_MASK      (0xFFFFFU)
#define ENETC_BASE_TGSLR_MIN_LOOKAHEAD_SHIFT     (0U)
#define ENETC_BASE_TGSLR_MIN_LOOKAHEAD_WIDTH     (20U)
#define ENETC_BASE_TGSLR_MIN_LOOKAHEAD(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_TGSLR_MIN_LOOKAHEAD_SHIFT)) & ENETC_BASE_TGSLR_MIN_LOOKAHEAD_MASK)
/*! @} */

/*! @name PTCTSDR - Port traffic class a time specific departure register */
/*! @{ */

#define ENETC_BASE_PTCTSDR_TSDE_MASK             (0x80000000U)
#define ENETC_BASE_PTCTSDR_TSDE_SHIFT            (31U)
#define ENETC_BASE_PTCTSDR_TSDE_WIDTH            (1U)
#define ENETC_BASE_PTCTSDR_TSDE(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PTCTSDR_TSDE_SHIFT)) & ENETC_BASE_PTCTSDR_TSDE_MASK)
/*! @} */

/*! @name SMCAPR - Switch management capability register */
/*! @{ */

#define ENETC_BASE_SMCAPR_SM_MASK                (0x1U)
#define ENETC_BASE_SMCAPR_SM_SHIFT               (0U)
#define ENETC_BASE_SMCAPR_SM_WIDTH               (1U)
#define ENETC_BASE_SMCAPR_SM(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_SMCAPR_SM_SHIFT)) & ENETC_BASE_SMCAPR_SM_MASK)
/*! @} */

/*! @name SMHRBDRMR - Switch management host reason 1 receive BD ring mapping register..Switch management host reason 15 receive BD ring mapping register */
/*! @{ */

#define ENETC_BASE_SMHRBDRMR_RXBDR_MASK          (0xFFU)
#define ENETC_BASE_SMHRBDRMR_RXBDR_SHIFT         (0U)
#define ENETC_BASE_SMHRBDRMR_RXBDR_WIDTH         (8U)
#define ENETC_BASE_SMHRBDRMR_RXBDR(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_SMHRBDRMR_RXBDR_SHIFT)) & ENETC_BASE_SMHRBDRMR_RXBDR_MASK)

#define ENETC_BASE_SMHRBDRMR_EN_MASK             (0x80000000U)
#define ENETC_BASE_SMHRBDRMR_EN_SHIFT            (31U)
#define ENETC_BASE_SMHRBDRMR_EN_WIDTH            (1U)
#define ENETC_BASE_SMHRBDRMR_EN(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_SMHRBDRMR_EN_SHIFT)) & ENETC_BASE_SMHRBDRMR_EN_MASK)
/*! @} */

/*! @name PSIPMAR0 - Port station interface 0 primary MAC address register 0..Port station interface 5 primary MAC address register 0 */
/*! @{ */

#define ENETC_BASE_PSIPMAR0_PRIM_MAC_ADDR_MASK   (0xFFFFFFFFU)
#define ENETC_BASE_PSIPMAR0_PRIM_MAC_ADDR_SHIFT  (0U)
#define ENETC_BASE_PSIPMAR0_PRIM_MAC_ADDR_WIDTH  (32U)
#define ENETC_BASE_PSIPMAR0_PRIM_MAC_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMAR0_PRIM_MAC_ADDR_SHIFT)) & ENETC_BASE_PSIPMAR0_PRIM_MAC_ADDR_MASK)
/*! @} */

/*! @name PSIPMAR1 - Port station interface 0 primary MAC address register 1..Port station interface 5 primary MAC address register 1 */
/*! @{ */

#define ENETC_BASE_PSIPMAR1_PRIM_MAC_ADDR_MASK   (0xFFFFU)
#define ENETC_BASE_PSIPMAR1_PRIM_MAC_ADDR_SHIFT  (0U)
#define ENETC_BASE_PSIPMAR1_PRIM_MAC_ADDR_WIDTH  (16U)
#define ENETC_BASE_PSIPMAR1_PRIM_MAC_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIPMAR1_PRIM_MAC_ADDR_SHIFT)) & ENETC_BASE_PSIPMAR1_PRIM_MAC_ADDR_MASK)
/*! @} */

/*! @name PSIVLANR - Port station interface 0 VLAN register..Port station interface 5 VLAN register */
/*! @{ */

#define ENETC_BASE_PSIVLANR_VID_MASK             (0xFFFU)
#define ENETC_BASE_PSIVLANR_VID_SHIFT            (0U)
#define ENETC_BASE_PSIVLANR_VID_WIDTH            (12U)
#define ENETC_BASE_PSIVLANR_VID(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVLANR_VID_SHIFT)) & ENETC_BASE_PSIVLANR_VID_MASK)

#define ENETC_BASE_PSIVLANR_DEI_MASK             (0x1000U)
#define ENETC_BASE_PSIVLANR_DEI_SHIFT            (12U)
#define ENETC_BASE_PSIVLANR_DEI_WIDTH            (1U)
#define ENETC_BASE_PSIVLANR_DEI(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVLANR_DEI_SHIFT)) & ENETC_BASE_PSIVLANR_DEI_MASK)

#define ENETC_BASE_PSIVLANR_PCP_MASK             (0xE000U)
#define ENETC_BASE_PSIVLANR_PCP_SHIFT            (13U)
#define ENETC_BASE_PSIVLANR_PCP_WIDTH            (3U)
#define ENETC_BASE_PSIVLANR_PCP(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVLANR_PCP_SHIFT)) & ENETC_BASE_PSIVLANR_PCP_MASK)

#define ENETC_BASE_PSIVLANR_TPID_MASK            (0x30000U)
#define ENETC_BASE_PSIVLANR_TPID_SHIFT           (16U)
#define ENETC_BASE_PSIVLANR_TPID_WIDTH           (2U)
#define ENETC_BASE_PSIVLANR_TPID(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVLANR_TPID_SHIFT)) & ENETC_BASE_PSIVLANR_TPID_MASK)

#define ENETC_BASE_PSIVLANR_TXTAGR_MASK          (0xF00000U)
#define ENETC_BASE_PSIVLANR_TXTAGR_SHIFT         (20U)
#define ENETC_BASE_PSIVLANR_TXTAGR_WIDTH         (4U)
#define ENETC_BASE_PSIVLANR_TXTAGR(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVLANR_TXTAGR_SHIFT)) & ENETC_BASE_PSIVLANR_TXTAGR_MASK)

#define ENETC_BASE_PSIVLANR_VTEA_MASK            (0x40000000U)
#define ENETC_BASE_PSIVLANR_VTEA_SHIFT           (30U)
#define ENETC_BASE_PSIVLANR_VTEA_WIDTH           (1U)
#define ENETC_BASE_PSIVLANR_VTEA(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVLANR_VTEA_SHIFT)) & ENETC_BASE_PSIVLANR_VTEA_MASK)

#define ENETC_BASE_PSIVLANR_E_MASK               (0x80000000U)
#define ENETC_BASE_PSIVLANR_E_SHIFT              (31U)
#define ENETC_BASE_PSIVLANR_E_WIDTH              (1U)
#define ENETC_BASE_PSIVLANR_E(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVLANR_E_SHIFT)) & ENETC_BASE_PSIVLANR_E_MASK)
/*! @} */

/*! @name PSICFGR0 - Port station interface 0 configuration register 0..Port station interface 5 configuration register 0 */
/*! @{ */

#define ENETC_BASE_PSICFGR0_NUM_TX_BDR_MASK      (0x7FU)
#define ENETC_BASE_PSICFGR0_NUM_TX_BDR_SHIFT     (0U)
#define ENETC_BASE_PSICFGR0_NUM_TX_BDR_WIDTH     (7U)
#define ENETC_BASE_PSICFGR0_NUM_TX_BDR(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR0_NUM_TX_BDR_SHIFT)) & ENETC_BASE_PSICFGR0_NUM_TX_BDR_MASK)

#define ENETC_BASE_PSICFGR0_VTIA_MASK            (0x400U)
#define ENETC_BASE_PSICFGR0_VTIA_SHIFT           (10U)
#define ENETC_BASE_PSICFGR0_VTIA_WIDTH           (1U)
#define ENETC_BASE_PSICFGR0_VTIA(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR0_VTIA_SHIFT)) & ENETC_BASE_PSICFGR0_VTIA_MASK)

#define ENETC_BASE_PSICFGR0_SPE_MASK             (0x800U)
#define ENETC_BASE_PSICFGR0_SPE_SHIFT            (11U)
#define ENETC_BASE_PSICFGR0_SPE_WIDTH            (1U)
#define ENETC_BASE_PSICFGR0_SPE(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR0_SPE_SHIFT)) & ENETC_BASE_PSICFGR0_SPE_MASK)

#define ENETC_BASE_PSICFGR0_VTE_MASK             (0x1000U)
#define ENETC_BASE_PSICFGR0_VTE_SHIFT            (12U)
#define ENETC_BASE_PSICFGR0_VTE_WIDTH            (1U)
#define ENETC_BASE_PSICFGR0_VTE(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR0_VTE_SHIFT)) & ENETC_BASE_PSICFGR0_VTE_MASK)

#define ENETC_BASE_PSICFGR0_VASE_MASK            (0x2000U)
#define ENETC_BASE_PSICFGR0_VASE_SHIFT           (13U)
#define ENETC_BASE_PSICFGR0_VASE_WIDTH           (1U)
#define ENETC_BASE_PSICFGR0_VASE(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR0_VASE_SHIFT)) & ENETC_BASE_PSICFGR0_VASE_MASK)

#define ENETC_BASE_PSICFGR0_SIVIE_MASK           (0x4000U)
#define ENETC_BASE_PSICFGR0_SIVIE_SHIFT          (14U)
#define ENETC_BASE_PSICFGR0_SIVIE_WIDTH          (1U)
#define ENETC_BASE_PSICFGR0_SIVIE(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR0_SIVIE_SHIFT)) & ENETC_BASE_PSICFGR0_SIVIE_MASK)

#define ENETC_BASE_PSICFGR0_ASE_MASK             (0x8000U)
#define ENETC_BASE_PSICFGR0_ASE_SHIFT            (15U)
#define ENETC_BASE_PSICFGR0_ASE_WIDTH            (1U)
#define ENETC_BASE_PSICFGR0_ASE(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR0_ASE_SHIFT)) & ENETC_BASE_PSICFGR0_ASE_MASK)

#define ENETC_BASE_PSICFGR0_NUM_RX_BDR_MASK      (0x7F0000U)
#define ENETC_BASE_PSICFGR0_NUM_RX_BDR_SHIFT     (16U)
#define ENETC_BASE_PSICFGR0_NUM_RX_BDR_WIDTH     (7U)
#define ENETC_BASE_PSICFGR0_NUM_RX_BDR(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR0_NUM_RX_BDR_SHIFT)) & ENETC_BASE_PSICFGR0_NUM_RX_BDR_MASK)

#define ENETC_BASE_PSICFGR0_SIVC_MASK            (0xF000000U)
#define ENETC_BASE_PSICFGR0_SIVC_SHIFT           (24U)
#define ENETC_BASE_PSICFGR0_SIVC_WIDTH           (4U)
#define ENETC_BASE_PSICFGR0_SIVC(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR0_SIVC_SHIFT)) & ENETC_BASE_PSICFGR0_SIVC_MASK)

#define ENETC_BASE_PSICFGR0_SIBW_MASK            (0xF0000000U)
#define ENETC_BASE_PSICFGR0_SIBW_SHIFT           (28U)
#define ENETC_BASE_PSICFGR0_SIBW_WIDTH           (4U)
#define ENETC_BASE_PSICFGR0_SIBW(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR0_SIBW_SHIFT)) & ENETC_BASE_PSICFGR0_SIBW_MASK)
/*! @} */

/*! @name PSICFGR1 - Port station interface 1 configuration register 1..Port station interface 5 configuration register 1 */
/*! @{ */

#define ENETC_BASE_PSICFGR1_TC0_MAP_MASK         (0x7U)
#define ENETC_BASE_PSICFGR1_TC0_MAP_SHIFT        (0U)
#define ENETC_BASE_PSICFGR1_TC0_MAP_WIDTH        (3U)
#define ENETC_BASE_PSICFGR1_TC0_MAP(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR1_TC0_MAP_SHIFT)) & ENETC_BASE_PSICFGR1_TC0_MAP_MASK)

#define ENETC_BASE_PSICFGR1_TC1_MAP_MASK         (0x70U)
#define ENETC_BASE_PSICFGR1_TC1_MAP_SHIFT        (4U)
#define ENETC_BASE_PSICFGR1_TC1_MAP_WIDTH        (3U)
#define ENETC_BASE_PSICFGR1_TC1_MAP(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR1_TC1_MAP_SHIFT)) & ENETC_BASE_PSICFGR1_TC1_MAP_MASK)

#define ENETC_BASE_PSICFGR1_TC2_MAP_MASK         (0x700U)
#define ENETC_BASE_PSICFGR1_TC2_MAP_SHIFT        (8U)
#define ENETC_BASE_PSICFGR1_TC2_MAP_WIDTH        (3U)
#define ENETC_BASE_PSICFGR1_TC2_MAP(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR1_TC2_MAP_SHIFT)) & ENETC_BASE_PSICFGR1_TC2_MAP_MASK)

#define ENETC_BASE_PSICFGR1_TC3_MAP_MASK         (0x7000U)
#define ENETC_BASE_PSICFGR1_TC3_MAP_SHIFT        (12U)
#define ENETC_BASE_PSICFGR1_TC3_MAP_WIDTH        (3U)
#define ENETC_BASE_PSICFGR1_TC3_MAP(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR1_TC3_MAP_SHIFT)) & ENETC_BASE_PSICFGR1_TC3_MAP_MASK)

#define ENETC_BASE_PSICFGR1_TC4_MAP_MASK         (0x70000U)
#define ENETC_BASE_PSICFGR1_TC4_MAP_SHIFT        (16U)
#define ENETC_BASE_PSICFGR1_TC4_MAP_WIDTH        (3U)
#define ENETC_BASE_PSICFGR1_TC4_MAP(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR1_TC4_MAP_SHIFT)) & ENETC_BASE_PSICFGR1_TC4_MAP_MASK)

#define ENETC_BASE_PSICFGR1_TC5_MAP_MASK         (0x700000U)
#define ENETC_BASE_PSICFGR1_TC5_MAP_SHIFT        (20U)
#define ENETC_BASE_PSICFGR1_TC5_MAP_WIDTH        (3U)
#define ENETC_BASE_PSICFGR1_TC5_MAP(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR1_TC5_MAP_SHIFT)) & ENETC_BASE_PSICFGR1_TC5_MAP_MASK)

#define ENETC_BASE_PSICFGR1_TC6_MAP_MASK         (0x7000000U)
#define ENETC_BASE_PSICFGR1_TC6_MAP_SHIFT        (24U)
#define ENETC_BASE_PSICFGR1_TC6_MAP_WIDTH        (3U)
#define ENETC_BASE_PSICFGR1_TC6_MAP(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR1_TC6_MAP_SHIFT)) & ENETC_BASE_PSICFGR1_TC6_MAP_MASK)

#define ENETC_BASE_PSICFGR1_TC7_MAP_MASK         (0x70000000U)
#define ENETC_BASE_PSICFGR1_TC7_MAP_SHIFT        (28U)
#define ENETC_BASE_PSICFGR1_TC7_MAP_WIDTH        (3U)
#define ENETC_BASE_PSICFGR1_TC7_MAP(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR1_TC7_MAP_SHIFT)) & ENETC_BASE_PSICFGR1_TC7_MAP_MASK)
/*! @} */

/*! @name PSICFGR2 - Port station interface 0 configuration register 2..Port station interface 5 configuration register 2 */
/*! @{ */

#define ENETC_BASE_PSICFGR2_NUM_MSIX_MASK        (0x3FU)
#define ENETC_BASE_PSICFGR2_NUM_MSIX_SHIFT       (0U)
#define ENETC_BASE_PSICFGR2_NUM_MSIX_WIDTH       (6U)
#define ENETC_BASE_PSICFGR2_NUM_MSIX(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSICFGR2_NUM_MSIX_SHIFT)) & ENETC_BASE_PSICFGR2_NUM_MSIX_MASK)
/*! @} */

/*! @name PSIVMAFCFGR - Port station interface 0 VSI MAC address filtering configuration register..Port station interface 5 VSI MAC address filtering configuration register */
/*! @{ */

#define ENETC_BASE_PSIVMAFCFGR_NUM_MAC_AFTE_MASK (0xFFU)
#define ENETC_BASE_PSIVMAFCFGR_NUM_MAC_AFTE_SHIFT (0U)
#define ENETC_BASE_PSIVMAFCFGR_NUM_MAC_AFTE_WIDTH (8U)
#define ENETC_BASE_PSIVMAFCFGR_NUM_MAC_AFTE(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVMAFCFGR_NUM_MAC_AFTE_SHIFT)) & ENETC_BASE_PSIVMAFCFGR_NUM_MAC_AFTE_MASK)
/*! @} */

/*! @name PSIVLANFCFGR - Port station interface 0 VLAN filtering configuration register..Port station interface 5 VLAN filtering configuration register */
/*! @{ */

#define ENETC_BASE_PSIVLANFCFGR_NUM_VLAN_FTE_MASK (0xFFU)
#define ENETC_BASE_PSIVLANFCFGR_NUM_VLAN_FTE_SHIFT (0U)
#define ENETC_BASE_PSIVLANFCFGR_NUM_VLAN_FTE_WIDTH (8U)
#define ENETC_BASE_PSIVLANFCFGR_NUM_VLAN_FTE(x)  (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVLANFCFGR_NUM_VLAN_FTE_SHIFT)) & ENETC_BASE_PSIVLANFCFGR_NUM_VLAN_FTE_MASK)
/*! @} */

/*! @name PSIRFSCFGR - Port station interface 0 RFS configuration register..Port station interface 5 RFS configuration register */
/*! @{ */

#define ENETC_BASE_PSIRFSCFGR_NUM_RFS_MASK       (0x1FFU)
#define ENETC_BASE_PSIRFSCFGR_NUM_RFS_SHIFT      (0U)
#define ENETC_BASE_PSIRFSCFGR_NUM_RFS_WIDTH      (9U)
#define ENETC_BASE_PSIRFSCFGR_NUM_RFS(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIRFSCFGR_NUM_RFS_SHIFT)) & ENETC_BASE_PSIRFSCFGR_NUM_RFS_MASK)
/*! @} */

/*! @name PSIUMHFR0 - Port station interface 0 unicast MAC hash filter register 0..Port station interface 5 unicast MAC hash filter register 0 */
/*! @{ */

#define ENETC_BASE_PSIUMHFR0_MAC_HASH_FLT_LOW_MASK (0xFFFFFFFFU)
#define ENETC_BASE_PSIUMHFR0_MAC_HASH_FLT_LOW_SHIFT (0U)
#define ENETC_BASE_PSIUMHFR0_MAC_HASH_FLT_LOW_WIDTH (32U)
#define ENETC_BASE_PSIUMHFR0_MAC_HASH_FLT_LOW(x) (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIUMHFR0_MAC_HASH_FLT_LOW_SHIFT)) & ENETC_BASE_PSIUMHFR0_MAC_HASH_FLT_LOW_MASK)
/*! @} */

/*! @name PSIUMHFR1 - Port station interface 0 unicast MAC hash filter register 1..Port station interface 5 unicast MAC hash filter register 1 */
/*! @{ */

#define ENETC_BASE_PSIUMHFR1_MAC_HASH_FLT_HIGH_MASK (0xFFFFFFFFU)
#define ENETC_BASE_PSIUMHFR1_MAC_HASH_FLT_HIGH_SHIFT (0U)
#define ENETC_BASE_PSIUMHFR1_MAC_HASH_FLT_HIGH_WIDTH (32U)
#define ENETC_BASE_PSIUMHFR1_MAC_HASH_FLT_HIGH(x) (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIUMHFR1_MAC_HASH_FLT_HIGH_SHIFT)) & ENETC_BASE_PSIUMHFR1_MAC_HASH_FLT_HIGH_MASK)
/*! @} */

/*! @name PSIMMHFR0 - Port station interface 0 multicast MAC hash filter register 0..Port station interface 5 multicast MAC hash filter register 0 */
/*! @{ */

#define ENETC_BASE_PSIMMHFR0_MAC_HASH_FLT_LOW_MASK (0xFFFFFFFFU)
#define ENETC_BASE_PSIMMHFR0_MAC_HASH_FLT_LOW_SHIFT (0U)
#define ENETC_BASE_PSIMMHFR0_MAC_HASH_FLT_LOW_WIDTH (32U)
#define ENETC_BASE_PSIMMHFR0_MAC_HASH_FLT_LOW(x) (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIMMHFR0_MAC_HASH_FLT_LOW_SHIFT)) & ENETC_BASE_PSIMMHFR0_MAC_HASH_FLT_LOW_MASK)
/*! @} */

/*! @name PSIMMHFR1 - Port station interface 0 multicast MAC hash filter register 1..Port station interface 5 multicast MAC hash filter register 1 */
/*! @{ */

#define ENETC_BASE_PSIMMHFR1_MAC_HASH_FLT_HIGH_MASK (0xFFFFFFFFU)
#define ENETC_BASE_PSIMMHFR1_MAC_HASH_FLT_HIGH_SHIFT (0U)
#define ENETC_BASE_PSIMMHFR1_MAC_HASH_FLT_HIGH_WIDTH (32U)
#define ENETC_BASE_PSIMMHFR1_MAC_HASH_FLT_HIGH(x) (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIMMHFR1_MAC_HASH_FLT_HIGH_SHIFT)) & ENETC_BASE_PSIMMHFR1_MAC_HASH_FLT_HIGH_MASK)
/*! @} */

/*! @name PSIVHFR0 - Port station interface 0 VLAN hash filter register 0..Port station interface 5 VLAN hash filter register 0 */
/*! @{ */

#define ENETC_BASE_PSIVHFR0_VLAN_HASH_FLT_LOW_MASK (0xFFFFFFFFU)
#define ENETC_BASE_PSIVHFR0_VLAN_HASH_FLT_LOW_SHIFT (0U)
#define ENETC_BASE_PSIVHFR0_VLAN_HASH_FLT_LOW_WIDTH (32U)
#define ENETC_BASE_PSIVHFR0_VLAN_HASH_FLT_LOW(x) (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVHFR0_VLAN_HASH_FLT_LOW_SHIFT)) & ENETC_BASE_PSIVHFR0_VLAN_HASH_FLT_LOW_MASK)
/*! @} */

/*! @name PSIVHFR1 - Port station interface 0 VLAN hash filter register 1..Port station interface 5 VLAN hash filter register 1 */
/*! @{ */

#define ENETC_BASE_PSIVHFR1_VLAN_HASH_FLT_HIGH_MASK (0xFFFFFFFFU)
#define ENETC_BASE_PSIVHFR1_VLAN_HASH_FLT_HIGH_SHIFT (0U)
#define ENETC_BASE_PSIVHFR1_VLAN_HASH_FLT_HIGH_WIDTH (32U)
#define ENETC_BASE_PSIVHFR1_VLAN_HASH_FLT_HIGH(x) (((uint32_t)(((uint32_t)(x)) << ENETC_BASE_PSIVHFR1_VLAN_HASH_FLT_HIGH_SHIFT)) & ENETC_BASE_PSIVHFR1_VLAN_HASH_FLT_HIGH_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ENETC_BASE_Register_Masks */

/*!
 * @}
 */ /* end of group ENETC_BASE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_ENETC_BASE_H_) */
