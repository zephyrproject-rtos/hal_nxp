/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for NETC_ENETC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_NETC_ENETC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NETC_ENETC
 *
 * CMSIS Peripheral Access Layer for NETC_ENETC
 */

#if !defined(PERI_NETC_ENETC_H_)
#define PERI_NETC_ENETC_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- NETC_ENETC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_ENETC_Peripheral_Access_Layer NETC_ENETC Peripheral Access Layer
 * @{
 */

/** NETC_ENETC - Size of Registers Arrays */
#define NETC_ENETC_PARCEACR_COUNT                 4u
#define NETC_ENETC_PICDRADCR_COUNT                4u
#define NETC_ENETC_TC_TBS_NUM_COUNT               8u
#define NETC_ENETC_NUM_SMHRBDRMR_COUNT            15u
#define NETC_ENETC_NUM_SI_COUNT                   2u

/** NETC_ENETC - Register Layout Typedef */
typedef struct {
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
  __IO uint32_t PARCECR[NETC_ENETC_PARCEACR_COUNT]; /**< Parser custom Ethertype 0 configuration register..Parser custom Ethertype 3 configuration register, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_3[88];
  __IO uint32_t PPAUONTR;                          /**< Port pause ON threshold register, offset: 0x108 */
  __IO uint32_t PPAUOFFTR;                         /**< Port pause OFF threshold register, offset: 0x10C */
       uint8_t RESERVED_4[16];
  __I  uint32_t PRXMBER;                           /**< Port receive memory buffer entitlement register, offset: 0x120 */
  __I  uint32_t PRXMBLR;                           /**< Port receive memory buffer limit register, offset: 0x124 */
  __I  uint32_t PRXBCR;                            /**< Port receive buffer count register, offset: 0x128 */
  __I  uint32_t PRXBCHWMR;                         /**< Port receive buffer count high watermark register, offset: 0x12C */
       uint8_t RESERVED_5[16];
  struct {                                         /* offset: 0x140, array step: 0x10 */
    __I  uint32_t PICDRDCR;                          /**< Port ingress congestion DR0 discard count register..Port ingress congestion DR3 discard count register, array offset: 0x140, array step: 0x10 */
         uint8_t RESERVED_0[4];
    __I  uint32_t PICDRDCRRR;                        /**< Port ingress congestion DR0 discard count read-reset register..Port ingress congestion DR3 discard count read-reset register, array offset: 0x148, array step: 0x10 */
         uint8_t RESERVED_1[4];
  } PICDRADCR[NETC_ENETC_PICDRADCR_COUNT];
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
       uint8_t RESERVED_10[100];
  __IO uint32_t PLPMR;                             /**< Port low power mode register, offset: 0x340, available only on: ENETC0_BASE (missing on ENETC1_BASE) */
  __I  uint32_t PWOSR;                             /**< Port wake-on status register, offset: 0x344, available only on: ENETC0_BASE (missing on ENETC1_BASE) */
       uint8_t RESERVED_11[40];
  __IO uint32_t IPV2ICMPMR0;                       /**< Receive IPV to ICM priority mapping register 0, offset: 0x370 */
       uint8_t RESERVED_12[12];
  __IO uint32_t PRIO2TCMR0;                        /**< Transmit priority to traffic class mapping register 0, offset: 0x380 */
       uint8_t RESERVED_13[12];
  __IO uint32_t PTCTSDR[NETC_ENETC_TC_TBS_NUM_COUNT]; /**< Port traffic class 0 time specific departure register..Port traffic class 7 time specific departure register, array offset: 0x390, array step: 0x4 */
       uint8_t RESERVED_14[1104];
  __I  uint32_t SMCAPR;                            /**< Switch management capability register, offset: 0x800 */
       uint8_t RESERVED_15[124];
  __IO uint32_t SMHRBDRMR[NETC_ENETC_NUM_SMHRBDRMR_COUNT]; /**< Switch management host reason 1 receive BD ring mapping register..Switch management host reason 15 receive BD ring mapping register, array offset: 0x880, array step: 0x4, available only on: ENETC1_BASE (missing on ENETC0_BASE) */
       uint8_t RESERVED_16[5956];
  struct {                                         /* offset: 0x2000, array step: 0x80 */
    __IO uint32_t PSIPMAR0;                          /**< Port station interface 0 primary MAC address register 0..Port station interface 1 primary MAC address register 0, array offset: 0x2000, array step: 0x80, irregular array, not all indices are valid */
    __IO uint32_t PSIPMAR1;                          /**< Port station interface 0 primary MAC address register 1..Port station interface 1 primary MAC address register 1, array offset: 0x2004, array step: 0x80, irregular array, not all indices are valid */
    __IO uint32_t PSIVLANR;                          /**< Port station interface 0 VLAN register..Port station interface 1 VLAN register, array offset: 0x2008, array step: 0x80, irregular array, not all indices are valid */
         uint8_t RESERVED_0[4];
    __IO uint32_t PSICFGR0;                          /**< Port station interface 0 configuration register 0..Port station interface 1 configuration register 0, array offset: 0x2010, array step: 0x80, irregular array, not all indices are valid */
    __IO uint32_t PSICFGR1;                          /**< Port station interface 1 configuration register 1, array offset: 0x2014, array step: 0x80, available only on: ENETC1_BASE (missing on ENETC0_BASE), valid indices: [1] */
    __IO uint32_t PSICFGR2;                          /**< Port station interface 0 configuration register 2..Port station interface 1 configuration register 2, array offset: 0x2018, array step: 0x80, irregular array, not all indices are valid */
         uint8_t RESERVED_1[20];
    __IO uint32_t PSIVMAFCFGR;                       /**< Port station interface 0 VSI MAC address filtering configuration register..Port station interface 1 VSI MAC address filtering configuration register, array offset: 0x2030, array step: 0x80, irregular array, not all indices are valid */
    __IO uint32_t PSIVLANFCFGR;                      /**< Port station interface 0 VLAN filtering configuration register..Port station interface 1 VLAN filtering configuration register, array offset: 0x2034, array step: 0x80, irregular array, not all indices are valid */
         uint8_t RESERVED_2[24];
    __IO uint32_t PSIUMHFR0;                         /**< Port station interface 0 unicast MAC hash filter register 0..Port station interface 1 unicast MAC hash filter register 0, array offset: 0x2050, array step: 0x80, irregular array, not all indices are valid */
    __IO uint32_t PSIUMHFR1;                         /**< Port station interface 0 unicast MAC hash filter register 1..Port station interface 1 unicast MAC hash filter register 1, array offset: 0x2054, array step: 0x80, irregular array, not all indices are valid */
    __IO uint32_t PSIMMHFR0;                         /**< Port station interface 0 multicast MAC hash filter register 0..Port station interface 1 multicast MAC hash filter register 0, array offset: 0x2058, array step: 0x80, irregular array, not all indices are valid */
    __IO uint32_t PSIMMHFR1;                         /**< Port station interface 0 multicast MAC hash filter register 1..Port station interface 1 multicast MAC hash filter register 1, array offset: 0x205C, array step: 0x80, irregular array, not all indices are valid */
    __IO uint32_t PSIVHFR0;                          /**< Port station interface 0 VLAN hash filter register 0..Port station interface 1 VLAN hash filter register 0, array offset: 0x2060, array step: 0x80, irregular array, not all indices are valid */
    __IO uint32_t PSIVHFR1;                          /**< Port station interface 0 VLAN hash filter register 1..Port station interface 1 VLAN hash filter register 1, array offset: 0x2064, array step: 0x80, irregular array, not all indices are valid */
         uint8_t RESERVED_3[24];
  } NUM_SI[NETC_ENETC_NUM_SI_COUNT];
} NETC_ENETC_Type;

/* ----------------------------------------------------------------------------
   -- NETC_ENETC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_ENETC_Register_Masks NETC_ENETC Register Masks
 * @{
 */

/*! @name ECAPR0 - ENETC capability register 0 */
/*! @{ */

#define NETC_ENETC_ECAPR0_RFS_MASK               (0x4U)
#define NETC_ENETC_ECAPR0_RFS_SHIFT              (2U)
#define NETC_ENETC_ECAPR0_RFS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR0_RFS_SHIFT)) & NETC_ENETC_ECAPR0_RFS_MASK)

#define NETC_ENETC_ECAPR0_TSD_MASK               (0x20U)
#define NETC_ENETC_ECAPR0_TSD_SHIFT              (5U)
#define NETC_ENETC_ECAPR0_TSD(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR0_TSD_SHIFT)) & NETC_ENETC_ECAPR0_TSD_MASK)

#define NETC_ENETC_ECAPR0_RSS_MASK               (0x100U)
#define NETC_ENETC_ECAPR0_RSS_SHIFT              (8U)
#define NETC_ENETC_ECAPR0_RSS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR0_RSS_SHIFT)) & NETC_ENETC_ECAPR0_RSS_MASK)

#define NETC_ENETC_ECAPR0_WO_MASK                (0x2000U)
#define NETC_ENETC_ECAPR0_WO_SHIFT               (13U)
#define NETC_ENETC_ECAPR0_WO(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR0_WO_SHIFT)) & NETC_ENETC_ECAPR0_WO_MASK)

#define NETC_ENETC_ECAPR0_FS_MASK                (0x10000U)
#define NETC_ENETC_ECAPR0_FS_SHIFT               (16U)
/*! FS - Functional safety capability supported. */
#define NETC_ENETC_ECAPR0_FS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR0_FS_SHIFT)) & NETC_ENETC_ECAPR0_FS_MASK)
/*! @} */

/*! @name ECAPR1 - ENETC capability register 1 */
/*! @{ */

#define NETC_ENETC_ECAPR1_NUM_TCS_MASK           (0x70U)
#define NETC_ENETC_ECAPR1_NUM_TCS_SHIFT          (4U)
#define NETC_ENETC_ECAPR1_NUM_TCS(x)             (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR1_NUM_TCS_SHIFT)) & NETC_ENETC_ECAPR1_NUM_TCS_MASK)

#define NETC_ENETC_ECAPR1_NUM_MCH_MASK           (0x300U)
#define NETC_ENETC_ECAPR1_NUM_MCH_SHIFT          (8U)
#define NETC_ENETC_ECAPR1_NUM_MCH(x)             (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR1_NUM_MCH_SHIFT)) & NETC_ENETC_ECAPR1_NUM_MCH_MASK)

#define NETC_ENETC_ECAPR1_NUM_UCH_MASK           (0xC00U)
#define NETC_ENETC_ECAPR1_NUM_UCH_SHIFT          (10U)
#define NETC_ENETC_ECAPR1_NUM_UCH(x)             (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR1_NUM_UCH_SHIFT)) & NETC_ENETC_ECAPR1_NUM_UCH_MASK)

#define NETC_ENETC_ECAPR1_NUM_MSIX_MASK          (0x7FF000U)
#define NETC_ENETC_ECAPR1_NUM_MSIX_SHIFT         (12U)
/*! NUM_MSIX - Number of MSI-X */
#define NETC_ENETC_ECAPR1_NUM_MSIX(x)            (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR1_NUM_MSIX_SHIFT)) & NETC_ENETC_ECAPR1_NUM_MSIX_MASK)

#define NETC_ENETC_ECAPR1_NUM_VSI_MASK           (0xF000000U)
#define NETC_ENETC_ECAPR1_NUM_VSI_SHIFT          (24U)
#define NETC_ENETC_ECAPR1_NUM_VSI(x)             (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR1_NUM_VSI_SHIFT)) & NETC_ENETC_ECAPR1_NUM_VSI_MASK)

#define NETC_ENETC_ECAPR1_NUM_IPV_MASK           (0x80000000U)
#define NETC_ENETC_ECAPR1_NUM_IPV_SHIFT          (31U)
#define NETC_ENETC_ECAPR1_NUM_IPV(x)             (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR1_NUM_IPV_SHIFT)) & NETC_ENETC_ECAPR1_NUM_IPV_MASK)
/*! @} */

/*! @name ECAPR2 - ENETC capability register 2 */
/*! @{ */

#define NETC_ENETC_ECAPR2_NUM_TX_BDR_MASK        (0x3FFU)
#define NETC_ENETC_ECAPR2_NUM_TX_BDR_SHIFT       (0U)
#define NETC_ENETC_ECAPR2_NUM_TX_BDR(x)          (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR2_NUM_TX_BDR_SHIFT)) & NETC_ENETC_ECAPR2_NUM_TX_BDR_MASK)

#define NETC_ENETC_ECAPR2_NUM_RX_BDR_MASK        (0x3FF0000U)
#define NETC_ENETC_ECAPR2_NUM_RX_BDR_SHIFT       (16U)
#define NETC_ENETC_ECAPR2_NUM_RX_BDR(x)          (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_ECAPR2_NUM_RX_BDR_SHIFT)) & NETC_ENETC_ECAPR2_NUM_RX_BDR_MASK)
/*! @} */

/*! @name PMR - Port mode register */
/*! @{ */

#define NETC_ENETC_PMR_SI0EN_MASK                (0x10000U)
#define NETC_ENETC_PMR_SI0EN_SHIFT               (16U)
/*! SI0EN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PMR_SI0EN(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PMR_SI0EN_SHIFT)) & NETC_ENETC_PMR_SI0EN_MASK)

#define NETC_ENETC_PMR_SI1EN_MASK                (0x20000U)
#define NETC_ENETC_PMR_SI1EN_SHIFT               (17U)
/*! SI1EN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PMR_SI1EN(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PMR_SI1EN_SHIFT)) & NETC_ENETC_PMR_SI1EN_MASK)
/*! @} */

/*! @name PONVLANR - Port outer native VLAN register */
/*! @{ */

#define NETC_ENETC_PONVLANR_VID_MASK             (0xFFFU)
#define NETC_ENETC_PONVLANR_VID_SHIFT            (0U)
#define NETC_ENETC_PONVLANR_VID(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PONVLANR_VID_SHIFT)) & NETC_ENETC_PONVLANR_VID_MASK)

#define NETC_ENETC_PONVLANR_DEI_MASK             (0x1000U)
#define NETC_ENETC_PONVLANR_DEI_SHIFT            (12U)
#define NETC_ENETC_PONVLANR_DEI(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PONVLANR_DEI_SHIFT)) & NETC_ENETC_PONVLANR_DEI_MASK)

#define NETC_ENETC_PONVLANR_PCP_MASK             (0xE000U)
#define NETC_ENETC_PONVLANR_PCP_SHIFT            (13U)
#define NETC_ENETC_PONVLANR_PCP(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PONVLANR_PCP_SHIFT)) & NETC_ENETC_PONVLANR_PCP_MASK)

#define NETC_ENETC_PONVLANR_TPID_MASK            (0x30000U)
#define NETC_ENETC_PONVLANR_TPID_SHIFT           (16U)
/*! TPID
 *  0b00..Standard C-VLAN 0x8100
 *  0b01..Standard S-VLAN 0x88A8
 *  0b10..Custom VLAN as defined by CVLANR1[ETYPE]
 *  0b11..Custom VLAN as defined by CVLANR2[ETYPE]
 */
#define NETC_ENETC_PONVLANR_TPID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PONVLANR_TPID_SHIFT)) & NETC_ENETC_PONVLANR_TPID_MASK)

#define NETC_ENETC_PONVLANR_PNE_MASK             (0x40000U)
#define NETC_ENETC_PONVLANR_PNE_SHIFT            (18U)
/*! PNE - Port Native VLAN Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PONVLANR_PNE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PONVLANR_PNE_SHIFT)) & NETC_ENETC_PONVLANR_PNE_MASK)

#define NETC_ENETC_PONVLANR_VZE_MASK             (0x80000U)
#define NETC_ENETC_PONVLANR_VZE_SHIFT            (19U)
/*! VZE - VID 0 Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PONVLANR_VZE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PONVLANR_VZE_SHIFT)) & NETC_ENETC_PONVLANR_VZE_MASK)
/*! @} */

/*! @name PINVLANR - Port inner native VLAN register */
/*! @{ */

#define NETC_ENETC_PINVLANR_VID_MASK             (0xFFFU)
#define NETC_ENETC_PINVLANR_VID_SHIFT            (0U)
#define NETC_ENETC_PINVLANR_VID(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PINVLANR_VID_SHIFT)) & NETC_ENETC_PINVLANR_VID_MASK)

#define NETC_ENETC_PINVLANR_DEI_MASK             (0x1000U)
#define NETC_ENETC_PINVLANR_DEI_SHIFT            (12U)
#define NETC_ENETC_PINVLANR_DEI(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PINVLANR_DEI_SHIFT)) & NETC_ENETC_PINVLANR_DEI_MASK)

#define NETC_ENETC_PINVLANR_PCP_MASK             (0xE000U)
#define NETC_ENETC_PINVLANR_PCP_SHIFT            (13U)
#define NETC_ENETC_PINVLANR_PCP(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PINVLANR_PCP_SHIFT)) & NETC_ENETC_PINVLANR_PCP_MASK)

#define NETC_ENETC_PINVLANR_TPID_MASK            (0x30000U)
#define NETC_ENETC_PINVLANR_TPID_SHIFT           (16U)
/*! TPID
 *  0b00..Standard C-VLAN 0x8100
 *  0b01..Standard S-VLAN 0x88A8
 *  0b10..Custom VLAN as defined by CVLANR1[ETYPE]
 *  0b11..Custom VLAN as defined by CVLANR2[ETYPE]
 */
#define NETC_ENETC_PINVLANR_TPID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PINVLANR_TPID_SHIFT)) & NETC_ENETC_PINVLANR_TPID_MASK)

#define NETC_ENETC_PINVLANR_PNE_MASK             (0x40000U)
#define NETC_ENETC_PINVLANR_PNE_SHIFT            (18U)
/*! PNE - Port Native VLAN Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PINVLANR_PNE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PINVLANR_PNE_SHIFT)) & NETC_ENETC_PINVLANR_PNE_MASK)

#define NETC_ENETC_PINVLANR_VZE_MASK             (0x80000U)
#define NETC_ENETC_PINVLANR_VZE_SHIFT            (19U)
/*! VZE - VID 0 Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PINVLANR_VZE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PINVLANR_VZE_SHIFT)) & NETC_ENETC_PINVLANR_VZE_MASK)
/*! @} */

/*! @name PVCLCTR - Port VLAN classification control register */
/*! @{ */

#define NETC_ENETC_PVCLCTR_OAI_MASK              (0x200U)
#define NETC_ENETC_PVCLCTR_OAI_SHIFT             (9U)
/*! OAI - Outer as Inner
 *  0b0..Indicates that the Inner is not valid if only one tag is found
 *  0b1..Indicates that the outer should be used as the Inner if only one tag is found
 */
#define NETC_ENETC_PVCLCTR_OAI(x)                (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PVCLCTR_OAI_SHIFT)) & NETC_ENETC_PVCLCTR_OAI_MASK)
/*! @} */

/*! @name PARCSCR - Parser checksum configuration register */
/*! @{ */

#define NETC_ENETC_PARCSCR_L4CD_MASK             (0x1U)
#define NETC_ENETC_PARCSCR_L4CD_SHIFT            (0U)
/*! L4CD
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define NETC_ENETC_PARCSCR_L4CD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PARCSCR_L4CD_SHIFT)) & NETC_ENETC_PARCSCR_L4CD_MASK)

#define NETC_ENETC_PARCSCR_L3CD_MASK             (0x2U)
#define NETC_ENETC_PARCSCR_L3CD_SHIFT            (1U)
/*! L3CD
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define NETC_ENETC_PARCSCR_L3CD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PARCSCR_L3CD_SHIFT)) & NETC_ENETC_PARCSCR_L3CD_MASK)
/*! @} */

/*! @name PARCECR - Parser custom Ethertype 0 configuration register..Parser custom Ethertype 3 configuration register */
/*! @{ */

#define NETC_ENETC_PARCECR_CP_MASK               (0xFU)
#define NETC_ENETC_PARCECR_CP_SHIFT              (0U)
/*! CP - Code Point */
#define NETC_ENETC_PARCECR_CP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PARCECR_CP_SHIFT)) & NETC_ENETC_PARCECR_CP_MASK)

#define NETC_ENETC_PARCECR_EN_MASK               (0x20U)
#define NETC_ENETC_PARCECR_EN_SHIFT              (5U)
/*! EN - Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PARCECR_EN(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PARCECR_EN_SHIFT)) & NETC_ENETC_PARCECR_EN_MASK)

#define NETC_ENETC_PARCECR_ETYPE_MASK            (0xFFFF0000U)
#define NETC_ENETC_PARCECR_ETYPE_SHIFT           (16U)
/*! ETYPE - ETYPE */
#define NETC_ENETC_PARCECR_ETYPE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PARCECR_ETYPE_SHIFT)) & NETC_ENETC_PARCECR_ETYPE_MASK)
/*! @} */

/* The count of NETC_ENETC_PARCECR */
#define NETC_ENETC_PARCECR_COUNT                 (4U)

/*! @name PPAUONTR - Port pause ON threshold register */
/*! @{ */

#define NETC_ENETC_PPAUONTR_THRESH_MASK          (0xFFFFFFU)
#define NETC_ENETC_PPAUONTR_THRESH_SHIFT         (0U)
#define NETC_ENETC_PPAUONTR_THRESH(x)            (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PPAUONTR_THRESH_SHIFT)) & NETC_ENETC_PPAUONTR_THRESH_MASK)
/*! @} */

/*! @name PPAUOFFTR - Port pause OFF threshold register */
/*! @{ */

#define NETC_ENETC_PPAUOFFTR_THRESH_MASK         (0xFFFFFFU)
#define NETC_ENETC_PPAUOFFTR_THRESH_SHIFT        (0U)
#define NETC_ENETC_PPAUOFFTR_THRESH(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PPAUOFFTR_THRESH_SHIFT)) & NETC_ENETC_PPAUOFFTR_THRESH_MASK)
/*! @} */

/*! @name PRXMBER - Port receive memory buffer entitlement register */
/*! @{ */

#define NETC_ENETC_PRXMBER_AMOUNT_MASK           (0xFFFFFFU)
#define NETC_ENETC_PRXMBER_AMOUNT_SHIFT          (0U)
#define NETC_ENETC_PRXMBER_AMOUNT(x)             (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRXMBER_AMOUNT_SHIFT)) & NETC_ENETC_PRXMBER_AMOUNT_MASK)
/*! @} */

/*! @name PRXMBLR - Port receive memory buffer limit register */
/*! @{ */

#define NETC_ENETC_PRXMBLR_LIMIT_MASK            (0xFFFFFFU)
#define NETC_ENETC_PRXMBLR_LIMIT_SHIFT           (0U)
#define NETC_ENETC_PRXMBLR_LIMIT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRXMBLR_LIMIT_SHIFT)) & NETC_ENETC_PRXMBLR_LIMIT_MASK)
/*! @} */

/*! @name PRXBCR - Port receive buffer count register */
/*! @{ */

#define NETC_ENETC_PRXBCR_COUNT_MASK             (0xFFFFFFU)
#define NETC_ENETC_PRXBCR_COUNT_SHIFT            (0U)
#define NETC_ENETC_PRXBCR_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRXBCR_COUNT_SHIFT)) & NETC_ENETC_PRXBCR_COUNT_MASK)
/*! @} */

/*! @name PRXBCHWMR - Port receive buffer count high watermark register */
/*! @{ */

#define NETC_ENETC_PRXBCHWMR_WATERMARK_MASK      (0xFFFFFFU)
#define NETC_ENETC_PRXBCHWMR_WATERMARK_SHIFT     (0U)
#define NETC_ENETC_PRXBCHWMR_WATERMARK(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRXBCHWMR_WATERMARK_SHIFT)) & NETC_ENETC_PRXBCHWMR_WATERMARK_MASK)
/*! @} */

/*! @name PICDRDCR - Port ingress congestion DR0 discard count register..Port ingress congestion DR3 discard count register */
/*! @{ */

#define NETC_ENETC_PICDRDCR_COUNT_MASK           (0xFFFFFFFFU)
#define NETC_ENETC_PICDRDCR_COUNT_SHIFT          (0U)
#define NETC_ENETC_PICDRDCR_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PICDRDCR_COUNT_SHIFT)) & NETC_ENETC_PICDRDCR_COUNT_MASK)
/*! @} */

/* The count of NETC_ENETC_PICDRDCR */
#define NETC_ENETC_PICDRADCR_PICDRDCR_COUNT      (4U)

/*! @name PICDRDCRRR - Port ingress congestion DR0 discard count read-reset register..Port ingress congestion DR3 discard count read-reset register */
/*! @{ */

#define NETC_ENETC_PICDRDCRRR_COUNT_MASK         (0xFFFFFFFFU)
#define NETC_ENETC_PICDRDCRRR_COUNT_SHIFT        (0U)
#define NETC_ENETC_PICDRDCRRR_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PICDRDCRRR_COUNT_SHIFT)) & NETC_ENETC_PICDRDCRRR_COUNT_MASK)
/*! @} */

/* The count of NETC_ENETC_PICDRDCRRR */
#define NETC_ENETC_PICDRADCR_PICDRDCRRR_COUNT    (4U)

/*! @name PICPDSR - Port ingress congestion priority discard status register */
/*! @{ */

#define NETC_ENETC_PICPDSR_DR0_P0DS_MASK         (0x1U)
#define NETC_ENETC_PICPDSR_DR0_P0DS_SHIFT        (0U)
#define NETC_ENETC_PICPDSR_DR0_P0DS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PICPDSR_DR0_P0DS_SHIFT)) & NETC_ENETC_PICPDSR_DR0_P0DS_MASK)

#define NETC_ENETC_PICPDSR_DR0_P1DS_MASK         (0x10U)
#define NETC_ENETC_PICPDSR_DR0_P1DS_SHIFT        (4U)
#define NETC_ENETC_PICPDSR_DR0_P1DS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PICPDSR_DR0_P1DS_SHIFT)) & NETC_ENETC_PICPDSR_DR0_P1DS_MASK)

#define NETC_ENETC_PICPDSR_DR1_P0DS_MASK         (0x100U)
#define NETC_ENETC_PICPDSR_DR1_P0DS_SHIFT        (8U)
#define NETC_ENETC_PICPDSR_DR1_P0DS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PICPDSR_DR1_P0DS_SHIFT)) & NETC_ENETC_PICPDSR_DR1_P0DS_MASK)

#define NETC_ENETC_PICPDSR_DR1_P1DS_MASK         (0x1000U)
#define NETC_ENETC_PICPDSR_DR1_P1DS_SHIFT        (12U)
#define NETC_ENETC_PICPDSR_DR1_P1DS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PICPDSR_DR1_P1DS_SHIFT)) & NETC_ENETC_PICPDSR_DR1_P1DS_MASK)

#define NETC_ENETC_PICPDSR_DR2_P0DS_MASK         (0x10000U)
#define NETC_ENETC_PICPDSR_DR2_P0DS_SHIFT        (16U)
#define NETC_ENETC_PICPDSR_DR2_P0DS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PICPDSR_DR2_P0DS_SHIFT)) & NETC_ENETC_PICPDSR_DR2_P0DS_MASK)

#define NETC_ENETC_PICPDSR_DR2_P1DS_MASK         (0x100000U)
#define NETC_ENETC_PICPDSR_DR2_P1DS_SHIFT        (20U)
#define NETC_ENETC_PICPDSR_DR2_P1DS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PICPDSR_DR2_P1DS_SHIFT)) & NETC_ENETC_PICPDSR_DR2_P1DS_MASK)

#define NETC_ENETC_PICPDSR_DR3_P0DS_MASK         (0x1000000U)
#define NETC_ENETC_PICPDSR_DR3_P0DS_SHIFT        (24U)
#define NETC_ENETC_PICPDSR_DR3_P0DS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PICPDSR_DR3_P0DS_SHIFT)) & NETC_ENETC_PICPDSR_DR3_P0DS_MASK)

#define NETC_ENETC_PICPDSR_DR3_P1DS_MASK         (0x10000000U)
#define NETC_ENETC_PICPDSR_DR3_P1DS_SHIFT        (28U)
#define NETC_ENETC_PICPDSR_DR3_P1DS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PICPDSR_DR3_P1DS_SHIFT)) & NETC_ENETC_PICPDSR_DR3_P1DS_MASK)
/*! @} */

/*! @name PSIPMMR - Port station interface promiscuous MAC mode register */
/*! @{ */

#define NETC_ENETC_PSIPMMR_SI0_MAC_UP_MASK       (0x1U)
#define NETC_ENETC_PSIPMMR_SI0_MAC_UP_SHIFT      (0U)
/*! SI0_MAC_UP
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PSIPMMR_SI0_MAC_UP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIPMMR_SI0_MAC_UP_SHIFT)) & NETC_ENETC_PSIPMMR_SI0_MAC_UP_MASK)

#define NETC_ENETC_PSIPMMR_SI1_MAC_UP_MASK       (0x2U)
#define NETC_ENETC_PSIPMMR_SI1_MAC_UP_SHIFT      (1U)
/*! SI1_MAC_UP
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PSIPMMR_SI1_MAC_UP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIPMMR_SI1_MAC_UP_SHIFT)) & NETC_ENETC_PSIPMMR_SI1_MAC_UP_MASK)

#define NETC_ENETC_PSIPMMR_SI0_MAC_MP_MASK       (0x10000U)
#define NETC_ENETC_PSIPMMR_SI0_MAC_MP_SHIFT      (16U)
/*! SI0_MAC_MP
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PSIPMMR_SI0_MAC_MP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIPMMR_SI0_MAC_MP_SHIFT)) & NETC_ENETC_PSIPMMR_SI0_MAC_MP_MASK)

#define NETC_ENETC_PSIPMMR_SI1_MAC_MP_MASK       (0x20000U)
#define NETC_ENETC_PSIPMMR_SI1_MAC_MP_SHIFT      (17U)
/*! SI1_MAC_MP
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PSIPMMR_SI1_MAC_MP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIPMMR_SI1_MAC_MP_SHIFT)) & NETC_ENETC_PSIPMMR_SI1_MAC_MP_MASK)
/*! @} */

/*! @name PSIPVMR - Port station interface promiscuous VLAN mode register */
/*! @{ */

#define NETC_ENETC_PSIPVMR_SI0_VLAN_P_MASK       (0x1U)
#define NETC_ENETC_PSIPVMR_SI0_VLAN_P_SHIFT      (0U)
/*! SI0_VLAN_P
 *  0b0..SI 0 does not qualify for the reception of all VLAN tags
 *  0b1..SI 0 does qualify for the reception of all VLAN tags
 */
#define NETC_ENETC_PSIPVMR_SI0_VLAN_P(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIPVMR_SI0_VLAN_P_SHIFT)) & NETC_ENETC_PSIPVMR_SI0_VLAN_P_MASK)

#define NETC_ENETC_PSIPVMR_SI1_VLAN_P_MASK       (0x2U)
#define NETC_ENETC_PSIPVMR_SI1_VLAN_P_SHIFT      (1U)
/*! SI1_VLAN_P
 *  0b0..SI 1 does not qualify for the reception of all VLAN tags
 *  0b1..SI 1 does qualify for the reception of all VLAN tags
 */
#define NETC_ENETC_PSIPVMR_SI1_VLAN_P(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIPVMR_SI1_VLAN_P_SHIFT)) & NETC_ENETC_PSIPVMR_SI1_VLAN_P_MASK)

#define NETC_ENETC_PSIPVMR_SI0_VLAN_UTA_MASK     (0x10000U)
#define NETC_ENETC_PSIPVMR_SI0_VLAN_UTA_SHIFT    (16U)
/*! SI0_VLAN_UTA
 *  0b0..SI 0 does not qualify for reception of untagged frames
 *  0b1..SI 0 does qualify for reception of untagged frames
 */
#define NETC_ENETC_PSIPVMR_SI0_VLAN_UTA(x)       (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIPVMR_SI0_VLAN_UTA_SHIFT)) & NETC_ENETC_PSIPVMR_SI0_VLAN_UTA_MASK)

#define NETC_ENETC_PSIPVMR_SI1_VLAN_UTA_MASK     (0x20000U)
#define NETC_ENETC_PSIPVMR_SI1_VLAN_UTA_SHIFT    (17U)
/*! SI1_VLAN_UTA
 *  0b0..SI 1 does not qualify for reception of untagged frames
 *  0b1..SI 1 does qualify for reception of untagged frames
 */
#define NETC_ENETC_PSIPVMR_SI1_VLAN_UTA(x)       (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIPVMR_SI1_VLAN_UTA_SHIFT)) & NETC_ENETC_PSIPVMR_SI1_VLAN_UTA_MASK)
/*! @} */

/*! @name PBFDSIR - Port broadcast frames dropped due to MAC filtering register */
/*! @{ */

#define NETC_ENETC_PBFDSIR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define NETC_ENETC_PBFDSIR_FRAME_DROP_SHIFT      (0U)
#define NETC_ENETC_PBFDSIR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PBFDSIR_FRAME_DROP_SHIFT)) & NETC_ENETC_PBFDSIR_FRAME_DROP_MASK)
/*! @} */

/*! @name PFDMSAPR - Port frame drop MAC source address pruning register */
/*! @{ */

#define NETC_ENETC_PFDMSAPR_FRAME_DROP_MASK      (0xFFFFFFFFU)
#define NETC_ENETC_PFDMSAPR_FRAME_DROP_SHIFT     (0U)
#define NETC_ENETC_PFDMSAPR_FRAME_DROP(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PFDMSAPR_FRAME_DROP_SHIFT)) & NETC_ENETC_PFDMSAPR_FRAME_DROP_MASK)
/*! @} */

/*! @name PSIMAFCAPR - Port station interface MAC address filtering capability register */
/*! @{ */

#define NETC_ENETC_PSIMAFCAPR_NUM_MAC_AFTE_MASK  (0xFFFU)
#define NETC_ENETC_PSIMAFCAPR_NUM_MAC_AFTE_SHIFT (0U)
#define NETC_ENETC_PSIMAFCAPR_NUM_MAC_AFTE(x)    (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIMAFCAPR_NUM_MAC_AFTE_SHIFT)) & NETC_ENETC_PSIMAFCAPR_NUM_MAC_AFTE_MASK)
/*! @} */

/*! @name PUFDMFR - Port unicast frames dropped due to MAC filtering register */
/*! @{ */

#define NETC_ENETC_PUFDMFR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define NETC_ENETC_PUFDMFR_FRAME_DROP_SHIFT      (0U)
#define NETC_ENETC_PUFDMFR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PUFDMFR_FRAME_DROP_SHIFT)) & NETC_ENETC_PUFDMFR_FRAME_DROP_MASK)
/*! @} */

/*! @name PMFDMFR - Port multicast frames dropped due to MAC filtering register */
/*! @{ */

#define NETC_ENETC_PMFDMFR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define NETC_ENETC_PMFDMFR_FRAME_DROP_SHIFT      (0U)
#define NETC_ENETC_PMFDMFR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PMFDMFR_FRAME_DROP_SHIFT)) & NETC_ENETC_PMFDMFR_FRAME_DROP_MASK)
/*! @} */

/*! @name PSIVLANFCAPR - Port station interface VLAN filtering capability register */
/*! @{ */

#define NETC_ENETC_PSIVLANFCAPR_NUM_VLAN_FTE_MASK (0xFFFU)
#define NETC_ENETC_PSIVLANFCAPR_NUM_VLAN_FTE_SHIFT (0U)
#define NETC_ENETC_PSIVLANFCAPR_NUM_VLAN_FTE(x)  (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIVLANFCAPR_NUM_VLAN_FTE_SHIFT)) & NETC_ENETC_PSIVLANFCAPR_NUM_VLAN_FTE_MASK)
/*! @} */

/*! @name PSIVLANFMR - Port station interface VLAN filtering mode register */
/*! @{ */

#define NETC_ENETC_PSIVLANFMR_VS_MASK            (0x1U)
#define NETC_ENETC_PSIVLANFMR_VS_SHIFT           (0U)
/*! VS
 *  0b0..Inner VLAN tag will be used for VLAN filtering
 *  0b1..Outer VLAN tag will be used for VLAN filtering
 */
#define NETC_ENETC_PSIVLANFMR_VS(x)              (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIVLANFMR_VS_SHIFT)) & NETC_ENETC_PSIVLANFMR_VS_MASK)
/*! @} */

/*! @name PUFDVFR - Port unicast frames dropped VLAN filtering register */
/*! @{ */

#define NETC_ENETC_PUFDVFR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define NETC_ENETC_PUFDVFR_FRAME_DROP_SHIFT      (0U)
#define NETC_ENETC_PUFDVFR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PUFDVFR_FRAME_DROP_SHIFT)) & NETC_ENETC_PUFDVFR_FRAME_DROP_MASK)
/*! @} */

/*! @name PMFDVFR - Port multicast frames dropped VLAN filtering register */
/*! @{ */

#define NETC_ENETC_PMFDVFR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define NETC_ENETC_PMFDVFR_FRAME_DROP_SHIFT      (0U)
#define NETC_ENETC_PMFDVFR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PMFDVFR_FRAME_DROP_SHIFT)) & NETC_ENETC_PMFDVFR_FRAME_DROP_MASK)
/*! @} */

/*! @name PBFDVFR - Port broadcast frames dropped VLAN filtering register */
/*! @{ */

#define NETC_ENETC_PBFDVFR_FRAME_DROP_MASK       (0xFFFFFFFFU)
#define NETC_ENETC_PBFDVFR_FRAME_DROP_SHIFT      (0U)
#define NETC_ENETC_PBFDVFR_FRAME_DROP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PBFDVFR_FRAME_DROP_SHIFT)) & NETC_ENETC_PBFDVFR_FRAME_DROP_MASK)
/*! @} */

/*! @name PLPMR - Port low power mode register */
/*! @{ */

#define NETC_ENETC_PLPMR_WME_MASK                (0x1U)
#define NETC_ENETC_PLPMR_WME_SHIFT               (0U)
/*! WME
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PLPMR_WME(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PLPMR_WME_SHIFT)) & NETC_ENETC_PLPMR_WME_MASK)
/*! @} */

/*! @name PWOSR - Port wake-on status register */
/*! @{ */

#define NETC_ENETC_PWOSR_WOLA_MASK               (0x1U)
#define NETC_ENETC_PWOSR_WOLA_SHIFT              (0U)
/*! WOLA
 *  0b0..Inactive
 *  0b1..Active. ENETC is actively searching for frames matching the Wake-on-LAN event criteria.
 */
#define NETC_ENETC_PWOSR_WOLA(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PWOSR_WOLA_SHIFT)) & NETC_ENETC_PWOSR_WOLA_MASK)

#define NETC_ENETC_PWOSR_ICMB_MASK               (0x2U)
#define NETC_ENETC_PWOSR_ICMB_SHIFT              (1U)
/*! ICMB
 *  0b0..Not blocked
 *  0b1..Blocked.
 */
#define NETC_ENETC_PWOSR_ICMB(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PWOSR_ICMB_SHIFT)) & NETC_ENETC_PWOSR_ICMB_MASK)
/*! @} */

/*! @name IPV2ICMPMR0 - Receive IPV to ICM priority mapping register 0 */
/*! @{ */

#define NETC_ENETC_IPV2ICMPMR0_IPV0ICM_MASK      (0x1U)
#define NETC_ENETC_IPV2ICMPMR0_IPV0ICM_SHIFT     (0U)
#define NETC_ENETC_IPV2ICMPMR0_IPV0ICM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_IPV2ICMPMR0_IPV0ICM_SHIFT)) & NETC_ENETC_IPV2ICMPMR0_IPV0ICM_MASK)

#define NETC_ENETC_IPV2ICMPMR0_IPV1ICM_MASK      (0x10U)
#define NETC_ENETC_IPV2ICMPMR0_IPV1ICM_SHIFT     (4U)
#define NETC_ENETC_IPV2ICMPMR0_IPV1ICM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_IPV2ICMPMR0_IPV1ICM_SHIFT)) & NETC_ENETC_IPV2ICMPMR0_IPV1ICM_MASK)

#define NETC_ENETC_IPV2ICMPMR0_IPV2ICM_MASK      (0x100U)
#define NETC_ENETC_IPV2ICMPMR0_IPV2ICM_SHIFT     (8U)
#define NETC_ENETC_IPV2ICMPMR0_IPV2ICM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_IPV2ICMPMR0_IPV2ICM_SHIFT)) & NETC_ENETC_IPV2ICMPMR0_IPV2ICM_MASK)

#define NETC_ENETC_IPV2ICMPMR0_IPV3ICM_MASK      (0x1000U)
#define NETC_ENETC_IPV2ICMPMR0_IPV3ICM_SHIFT     (12U)
#define NETC_ENETC_IPV2ICMPMR0_IPV3ICM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_IPV2ICMPMR0_IPV3ICM_SHIFT)) & NETC_ENETC_IPV2ICMPMR0_IPV3ICM_MASK)

#define NETC_ENETC_IPV2ICMPMR0_IPV4ICM_MASK      (0x10000U)
#define NETC_ENETC_IPV2ICMPMR0_IPV4ICM_SHIFT     (16U)
#define NETC_ENETC_IPV2ICMPMR0_IPV4ICM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_IPV2ICMPMR0_IPV4ICM_SHIFT)) & NETC_ENETC_IPV2ICMPMR0_IPV4ICM_MASK)

#define NETC_ENETC_IPV2ICMPMR0_IPV5ICM_MASK      (0x100000U)
#define NETC_ENETC_IPV2ICMPMR0_IPV5ICM_SHIFT     (20U)
#define NETC_ENETC_IPV2ICMPMR0_IPV5ICM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_IPV2ICMPMR0_IPV5ICM_SHIFT)) & NETC_ENETC_IPV2ICMPMR0_IPV5ICM_MASK)

#define NETC_ENETC_IPV2ICMPMR0_IPV6ICM_MASK      (0x1000000U)
#define NETC_ENETC_IPV2ICMPMR0_IPV6ICM_SHIFT     (24U)
#define NETC_ENETC_IPV2ICMPMR0_IPV6ICM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_IPV2ICMPMR0_IPV6ICM_SHIFT)) & NETC_ENETC_IPV2ICMPMR0_IPV6ICM_MASK)

#define NETC_ENETC_IPV2ICMPMR0_IPV7ICM_MASK      (0x10000000U)
#define NETC_ENETC_IPV2ICMPMR0_IPV7ICM_SHIFT     (28U)
#define NETC_ENETC_IPV2ICMPMR0_IPV7ICM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_IPV2ICMPMR0_IPV7ICM_SHIFT)) & NETC_ENETC_IPV2ICMPMR0_IPV7ICM_MASK)
/*! @} */

/*! @name PRIO2TCMR0 - Transmit priority to traffic class mapping register 0 */
/*! @{ */

#define NETC_ENETC_PRIO2TCMR0_PRIO0TC_MASK       (0x7U)
#define NETC_ENETC_PRIO2TCMR0_PRIO0TC_SHIFT      (0U)
#define NETC_ENETC_PRIO2TCMR0_PRIO0TC(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRIO2TCMR0_PRIO0TC_SHIFT)) & NETC_ENETC_PRIO2TCMR0_PRIO0TC_MASK)

#define NETC_ENETC_PRIO2TCMR0_PRIO1TC_MASK       (0x70U)
#define NETC_ENETC_PRIO2TCMR0_PRIO1TC_SHIFT      (4U)
#define NETC_ENETC_PRIO2TCMR0_PRIO1TC(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRIO2TCMR0_PRIO1TC_SHIFT)) & NETC_ENETC_PRIO2TCMR0_PRIO1TC_MASK)

#define NETC_ENETC_PRIO2TCMR0_PRIO2TC_MASK       (0x700U)
#define NETC_ENETC_PRIO2TCMR0_PRIO2TC_SHIFT      (8U)
#define NETC_ENETC_PRIO2TCMR0_PRIO2TC(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRIO2TCMR0_PRIO2TC_SHIFT)) & NETC_ENETC_PRIO2TCMR0_PRIO2TC_MASK)

#define NETC_ENETC_PRIO2TCMR0_PRIO3TC_MASK       (0x7000U)
#define NETC_ENETC_PRIO2TCMR0_PRIO3TC_SHIFT      (12U)
#define NETC_ENETC_PRIO2TCMR0_PRIO3TC(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRIO2TCMR0_PRIO3TC_SHIFT)) & NETC_ENETC_PRIO2TCMR0_PRIO3TC_MASK)

#define NETC_ENETC_PRIO2TCMR0_PRIO4TC_MASK       (0x70000U)
#define NETC_ENETC_PRIO2TCMR0_PRIO4TC_SHIFT      (16U)
#define NETC_ENETC_PRIO2TCMR0_PRIO4TC(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRIO2TCMR0_PRIO4TC_SHIFT)) & NETC_ENETC_PRIO2TCMR0_PRIO4TC_MASK)

#define NETC_ENETC_PRIO2TCMR0_PRIO5TC_MASK       (0x700000U)
#define NETC_ENETC_PRIO2TCMR0_PRIO5TC_SHIFT      (20U)
#define NETC_ENETC_PRIO2TCMR0_PRIO5TC(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRIO2TCMR0_PRIO5TC_SHIFT)) & NETC_ENETC_PRIO2TCMR0_PRIO5TC_MASK)

#define NETC_ENETC_PRIO2TCMR0_PRIO6TC_MASK       (0x7000000U)
#define NETC_ENETC_PRIO2TCMR0_PRIO6TC_SHIFT      (24U)
#define NETC_ENETC_PRIO2TCMR0_PRIO6TC(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRIO2TCMR0_PRIO6TC_SHIFT)) & NETC_ENETC_PRIO2TCMR0_PRIO6TC_MASK)

#define NETC_ENETC_PRIO2TCMR0_PRIO7TC_MASK       (0x70000000U)
#define NETC_ENETC_PRIO2TCMR0_PRIO7TC_SHIFT      (28U)
#define NETC_ENETC_PRIO2TCMR0_PRIO7TC(x)         (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PRIO2TCMR0_PRIO7TC_SHIFT)) & NETC_ENETC_PRIO2TCMR0_PRIO7TC_MASK)
/*! @} */

/*! @name PTCTSDR - Port traffic class 0 time specific departure register..Port traffic class 7 time specific departure register */
/*! @{ */

#define NETC_ENETC_PTCTSDR_TSDE_MASK             (0x80000000U)
#define NETC_ENETC_PTCTSDR_TSDE_SHIFT            (31U)
/*! TSDE
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PTCTSDR_TSDE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PTCTSDR_TSDE_SHIFT)) & NETC_ENETC_PTCTSDR_TSDE_MASK)
/*! @} */

/* The count of NETC_ENETC_PTCTSDR */
#define NETC_ENETC_PTCTSDR_COUNT                 (8U)

/*! @name SMCAPR - Switch management capability register */
/*! @{ */

#define NETC_ENETC_SMCAPR_SM_MASK                (0x1U)
#define NETC_ENETC_SMCAPR_SM_SHIFT               (0U)
/*! SM - Switch Management
 *  0b0..ENETC instance has no switch management capability
 *  0b1..ENETC instance has switch management capability
 */
#define NETC_ENETC_SMCAPR_SM(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_SMCAPR_SM_SHIFT)) & NETC_ENETC_SMCAPR_SM_MASK)
/*! @} */

/*! @name SMHRBDRMR - Switch management host reason 1 receive BD ring mapping register..Switch management host reason 15 receive BD ring mapping register */
/*! @{ */

#define NETC_ENETC_SMHRBDRMR_RXBDR_MASK          (0xFFU)
#define NETC_ENETC_SMHRBDRMR_RXBDR_SHIFT         (0U)
#define NETC_ENETC_SMHRBDRMR_RXBDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_SMHRBDRMR_RXBDR_SHIFT)) & NETC_ENETC_SMHRBDRMR_RXBDR_MASK)
/*! @} */

/* The count of NETC_ENETC_SMHRBDRMR */
#define NETC_ENETC_SMHRBDRMR_COUNT               (15U)

/*! @name PSIPMAR0 - Port station interface 0 primary MAC address register 0..Port station interface 1 primary MAC address register 0 */
/*! @{ */

#define NETC_ENETC_PSIPMAR0_PRIM_MAC_ADDR_MASK   (0xFFFFFFFFU)
#define NETC_ENETC_PSIPMAR0_PRIM_MAC_ADDR_SHIFT  (0U)
#define NETC_ENETC_PSIPMAR0_PRIM_MAC_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIPMAR0_PRIM_MAC_ADDR_SHIFT)) & NETC_ENETC_PSIPMAR0_PRIM_MAC_ADDR_MASK)
/*! @} */

/* The count of NETC_ENETC_PSIPMAR0 */
#define NETC_ENETC_PSIPMAR0_COUNT                (2U)

/*! @name PSIPMAR1 - Port station interface 0 primary MAC address register 1..Port station interface 1 primary MAC address register 1 */
/*! @{ */

#define NETC_ENETC_PSIPMAR1_PRIM_MAC_ADDR_MASK   (0xFFFFU)
#define NETC_ENETC_PSIPMAR1_PRIM_MAC_ADDR_SHIFT  (0U)
#define NETC_ENETC_PSIPMAR1_PRIM_MAC_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIPMAR1_PRIM_MAC_ADDR_SHIFT)) & NETC_ENETC_PSIPMAR1_PRIM_MAC_ADDR_MASK)
/*! @} */

/* The count of NETC_ENETC_PSIPMAR1 */
#define NETC_ENETC_PSIPMAR1_COUNT                (2U)

/*! @name PSIVLANR - Port station interface 0 VLAN register..Port station interface 1 VLAN register */
/*! @{ */

#define NETC_ENETC_PSIVLANR_VID_MASK             (0xFFFU)
#define NETC_ENETC_PSIVLANR_VID_SHIFT            (0U)
#define NETC_ENETC_PSIVLANR_VID(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIVLANR_VID_SHIFT)) & NETC_ENETC_PSIVLANR_VID_MASK)

#define NETC_ENETC_PSIVLANR_DEI_MASK             (0x1000U)
#define NETC_ENETC_PSIVLANR_DEI_SHIFT            (12U)
#define NETC_ENETC_PSIVLANR_DEI(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIVLANR_DEI_SHIFT)) & NETC_ENETC_PSIVLANR_DEI_MASK)

#define NETC_ENETC_PSIVLANR_PCP_MASK             (0xE000U)
#define NETC_ENETC_PSIVLANR_PCP_SHIFT            (13U)
#define NETC_ENETC_PSIVLANR_PCP(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIVLANR_PCP_SHIFT)) & NETC_ENETC_PSIVLANR_PCP_MASK)

#define NETC_ENETC_PSIVLANR_TPID_MASK            (0x30000U)
#define NETC_ENETC_PSIVLANR_TPID_SHIFT           (16U)
/*! TPID
 *  0b00..Standard C-VLAN 0x8100
 *  0b01..Standard S-VLAN 0x88A8
 *  0b10..Custom VLAN as defined by CVLANR1[ETYPE]. Note that CVLANR1[V] is not checked for SI-based VLAN
 *        insertion; TPID value specified in CVLANR1[ETYPE] will be used to construct the VLAN header regardless of the
 *        value specified in CVLANR1[V].
 *  0b11..Custom VLAN as defined by CVLANR2[ETYPE]. Note that CVLANR2[V] is not checked for SI-based VLAN
 *        insertion; TPID value specified in CVLANR2[ETYPE] will be used to construct the VLAN header regardless of the
 *        value specified in CVLANR2[V].
 */
#define NETC_ENETC_PSIVLANR_TPID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIVLANR_TPID_SHIFT)) & NETC_ENETC_PSIVLANR_TPID_MASK)

#define NETC_ENETC_PSIVLANR_E_MASK               (0x80000000U)
#define NETC_ENETC_PSIVLANR_E_SHIFT              (31U)
/*! E - Enable
 *  0b0..Disabled
 *  0b1..Enabled; SI-based VLAN information is added on transmit and removed on receive.
 */
#define NETC_ENETC_PSIVLANR_E(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIVLANR_E_SHIFT)) & NETC_ENETC_PSIVLANR_E_MASK)
/*! @} */

/* The count of NETC_ENETC_PSIVLANR */
#define NETC_ENETC_PSIVLANR_COUNT                (2U)

/*! @name PSICFGR0 - Port station interface 0 configuration register 0..Port station interface 1 configuration register 0 */
/*! @{ */

#define NETC_ENETC_PSICFGR0_NUM_TX_BDR_MASK      (0x7FU)
#define NETC_ENETC_PSICFGR0_NUM_TX_BDR_SHIFT     (0U)
#define NETC_ENETC_PSICFGR0_NUM_TX_BDR(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR0_NUM_TX_BDR_SHIFT)) & NETC_ENETC_PSICFGR0_NUM_TX_BDR_MASK)

#define NETC_ENETC_PSICFGR0_SPE_MASK             (0x800U)
#define NETC_ENETC_PSICFGR0_SPE_SHIFT            (11U)
/*! SPE - Source Pruning Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_ENETC_PSICFGR0_SPE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR0_SPE_SHIFT)) & NETC_ENETC_PSICFGR0_SPE_MASK)

#define NETC_ENETC_PSICFGR0_VTE_MASK             (0x1000U)
#define NETC_ENETC_PSICFGR0_VTE_SHIFT            (12U)
/*! VTE - VLAN Tag Extract
 *  0b0..SI-based VLAN removal disabled
 *  0b1..SI-based VLAN removal enabled
 */
#define NETC_ENETC_PSICFGR0_VTE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR0_VTE_SHIFT)) & NETC_ENETC_PSICFGR0_VTE_MASK)

#define NETC_ENETC_PSICFGR0_SIVIE_MASK           (0x4000U)
#define NETC_ENETC_PSICFGR0_SIVIE_SHIFT          (14U)
/*! SIVIE - SI-based VLAN Insertion Enable
 *  0b0..SI-based VLAN insertion disabled
 *  0b1..SI-based VLAN insertion enabled
 */
#define NETC_ENETC_PSICFGR0_SIVIE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR0_SIVIE_SHIFT)) & NETC_ENETC_PSICFGR0_SIVIE_MASK)

#define NETC_ENETC_PSICFGR0_ASE_MASK             (0x8000U)
#define NETC_ENETC_PSICFGR0_ASE_SHIFT            (15U)
/*! ASE - Anti-spoofing enable */
#define NETC_ENETC_PSICFGR0_ASE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR0_ASE_SHIFT)) & NETC_ENETC_PSICFGR0_ASE_MASK)

#define NETC_ENETC_PSICFGR0_NUM_RX_BDR_MASK      (0x7F0000U)
#define NETC_ENETC_PSICFGR0_NUM_RX_BDR_SHIFT     (16U)
#define NETC_ENETC_PSICFGR0_NUM_RX_BDR(x)        (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR0_NUM_RX_BDR_SHIFT)) & NETC_ENETC_PSICFGR0_NUM_RX_BDR_MASK)

#define NETC_ENETC_PSICFGR0_SIVC_MASK            (0xF000000U)
#define NETC_ENETC_PSICFGR0_SIVC_SHIFT           (24U)
#define NETC_ENETC_PSICFGR0_SIVC(x)              (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR0_SIVC_SHIFT)) & NETC_ENETC_PSICFGR0_SIVC_MASK)

#define NETC_ENETC_PSICFGR0_SIBW_MASK            (0xF0000000U)
#define NETC_ENETC_PSICFGR0_SIBW_SHIFT           (28U)
#define NETC_ENETC_PSICFGR0_SIBW(x)              (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR0_SIBW_SHIFT)) & NETC_ENETC_PSICFGR0_SIBW_MASK)
/*! @} */

/* The count of NETC_ENETC_PSICFGR0 */
#define NETC_ENETC_PSICFGR0_COUNT                (2U)

/*! @name PSICFGR1 - Port station interface 1 configuration register 1 */
/*! @{ */

#define NETC_ENETC_PSICFGR1_TC0_MAP_MASK         (0x7U)
#define NETC_ENETC_PSICFGR1_TC0_MAP_SHIFT        (0U)
#define NETC_ENETC_PSICFGR1_TC0_MAP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR1_TC0_MAP_SHIFT)) & NETC_ENETC_PSICFGR1_TC0_MAP_MASK)

#define NETC_ENETC_PSICFGR1_TC1_MAP_MASK         (0x70U)
#define NETC_ENETC_PSICFGR1_TC1_MAP_SHIFT        (4U)
#define NETC_ENETC_PSICFGR1_TC1_MAP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR1_TC1_MAP_SHIFT)) & NETC_ENETC_PSICFGR1_TC1_MAP_MASK)

#define NETC_ENETC_PSICFGR1_TC2_MAP_MASK         (0x700U)
#define NETC_ENETC_PSICFGR1_TC2_MAP_SHIFT        (8U)
#define NETC_ENETC_PSICFGR1_TC2_MAP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR1_TC2_MAP_SHIFT)) & NETC_ENETC_PSICFGR1_TC2_MAP_MASK)

#define NETC_ENETC_PSICFGR1_TC3_MAP_MASK         (0x7000U)
#define NETC_ENETC_PSICFGR1_TC3_MAP_SHIFT        (12U)
#define NETC_ENETC_PSICFGR1_TC3_MAP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR1_TC3_MAP_SHIFT)) & NETC_ENETC_PSICFGR1_TC3_MAP_MASK)

#define NETC_ENETC_PSICFGR1_TC4_MAP_MASK         (0x70000U)
#define NETC_ENETC_PSICFGR1_TC4_MAP_SHIFT        (16U)
#define NETC_ENETC_PSICFGR1_TC4_MAP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR1_TC4_MAP_SHIFT)) & NETC_ENETC_PSICFGR1_TC4_MAP_MASK)

#define NETC_ENETC_PSICFGR1_TC5_MAP_MASK         (0x700000U)
#define NETC_ENETC_PSICFGR1_TC5_MAP_SHIFT        (20U)
#define NETC_ENETC_PSICFGR1_TC5_MAP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR1_TC5_MAP_SHIFT)) & NETC_ENETC_PSICFGR1_TC5_MAP_MASK)

#define NETC_ENETC_PSICFGR1_TC6_MAP_MASK         (0x7000000U)
#define NETC_ENETC_PSICFGR1_TC6_MAP_SHIFT        (24U)
#define NETC_ENETC_PSICFGR1_TC6_MAP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR1_TC6_MAP_SHIFT)) & NETC_ENETC_PSICFGR1_TC6_MAP_MASK)

#define NETC_ENETC_PSICFGR1_TC7_MAP_MASK         (0x70000000U)
#define NETC_ENETC_PSICFGR1_TC7_MAP_SHIFT        (28U)
#define NETC_ENETC_PSICFGR1_TC7_MAP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR1_TC7_MAP_SHIFT)) & NETC_ENETC_PSICFGR1_TC7_MAP_MASK)
/*! @} */

/* The count of NETC_ENETC_PSICFGR1 */
#define NETC_ENETC_PSICFGR1_COUNT                (2U)

/*! @name PSICFGR2 - Port station interface 0 configuration register 2..Port station interface 1 configuration register 2 */
/*! @{ */

#define NETC_ENETC_PSICFGR2_NUM_MSIX_MASK        (0x3FU)
#define NETC_ENETC_PSICFGR2_NUM_MSIX_SHIFT       (0U)
/*! NUM_MSIX - Number of MSI-X */
#define NETC_ENETC_PSICFGR2_NUM_MSIX(x)          (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSICFGR2_NUM_MSIX_SHIFT)) & NETC_ENETC_PSICFGR2_NUM_MSIX_MASK)
/*! @} */

/* The count of NETC_ENETC_PSICFGR2 */
#define NETC_ENETC_PSICFGR2_COUNT                (2U)

/*! @name PSIVMAFCFGR - Port station interface 0 VSI MAC address filtering configuration register..Port station interface 1 VSI MAC address filtering configuration register */
/*! @{ */

#define NETC_ENETC_PSIVMAFCFGR_NUM_MAC_AFTE_MASK (0xFFU)
#define NETC_ENETC_PSIVMAFCFGR_NUM_MAC_AFTE_SHIFT (0U)
#define NETC_ENETC_PSIVMAFCFGR_NUM_MAC_AFTE(x)   (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIVMAFCFGR_NUM_MAC_AFTE_SHIFT)) & NETC_ENETC_PSIVMAFCFGR_NUM_MAC_AFTE_MASK)
/*! @} */

/* The count of NETC_ENETC_PSIVMAFCFGR */
#define NETC_ENETC_PSIVMAFCFGR_COUNT             (2U)

/*! @name PSIVLANFCFGR - Port station interface 0 VLAN filtering configuration register..Port station interface 1 VLAN filtering configuration register */
/*! @{ */

#define NETC_ENETC_PSIVLANFCFGR_NUM_VLAN_FTE_MASK (0xFFU)
#define NETC_ENETC_PSIVLANFCFGR_NUM_VLAN_FTE_SHIFT (0U)
#define NETC_ENETC_PSIVLANFCFGR_NUM_VLAN_FTE(x)  (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIVLANFCFGR_NUM_VLAN_FTE_SHIFT)) & NETC_ENETC_PSIVLANFCFGR_NUM_VLAN_FTE_MASK)
/*! @} */

/* The count of NETC_ENETC_PSIVLANFCFGR */
#define NETC_ENETC_PSIVLANFCFGR_COUNT            (2U)

/*! @name PSIUMHFR0 - Port station interface 0 unicast MAC hash filter register 0..Port station interface 1 unicast MAC hash filter register 0 */
/*! @{ */

#define NETC_ENETC_PSIUMHFR0_MAC_HASH_FLT_LOW_MASK (0xFFFFFFFFU)
#define NETC_ENETC_PSIUMHFR0_MAC_HASH_FLT_LOW_SHIFT (0U)
#define NETC_ENETC_PSIUMHFR0_MAC_HASH_FLT_LOW(x) (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIUMHFR0_MAC_HASH_FLT_LOW_SHIFT)) & NETC_ENETC_PSIUMHFR0_MAC_HASH_FLT_LOW_MASK)
/*! @} */

/* The count of NETC_ENETC_PSIUMHFR0 */
#define NETC_ENETC_PSIUMHFR0_COUNT               (2U)

/*! @name PSIUMHFR1 - Port station interface 0 unicast MAC hash filter register 1..Port station interface 1 unicast MAC hash filter register 1 */
/*! @{ */

#define NETC_ENETC_PSIUMHFR1_MAC_HASH_FLT_HIGH_MASK (0xFFFFFFFFU)
#define NETC_ENETC_PSIUMHFR1_MAC_HASH_FLT_HIGH_SHIFT (0U)
#define NETC_ENETC_PSIUMHFR1_MAC_HASH_FLT_HIGH(x) (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIUMHFR1_MAC_HASH_FLT_HIGH_SHIFT)) & NETC_ENETC_PSIUMHFR1_MAC_HASH_FLT_HIGH_MASK)
/*! @} */

/* The count of NETC_ENETC_PSIUMHFR1 */
#define NETC_ENETC_PSIUMHFR1_COUNT               (2U)

/*! @name PSIMMHFR0 - Port station interface 0 multicast MAC hash filter register 0..Port station interface 1 multicast MAC hash filter register 0 */
/*! @{ */

#define NETC_ENETC_PSIMMHFR0_MAC_HASH_FLT_LOW_MASK (0xFFFFFFFFU)
#define NETC_ENETC_PSIMMHFR0_MAC_HASH_FLT_LOW_SHIFT (0U)
#define NETC_ENETC_PSIMMHFR0_MAC_HASH_FLT_LOW(x) (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIMMHFR0_MAC_HASH_FLT_LOW_SHIFT)) & NETC_ENETC_PSIMMHFR0_MAC_HASH_FLT_LOW_MASK)
/*! @} */

/* The count of NETC_ENETC_PSIMMHFR0 */
#define NETC_ENETC_PSIMMHFR0_COUNT               (2U)

/*! @name PSIMMHFR1 - Port station interface 0 multicast MAC hash filter register 1..Port station interface 1 multicast MAC hash filter register 1 */
/*! @{ */

#define NETC_ENETC_PSIMMHFR1_MAC_HASH_FLT_HIGH_MASK (0xFFFFFFFFU)
#define NETC_ENETC_PSIMMHFR1_MAC_HASH_FLT_HIGH_SHIFT (0U)
#define NETC_ENETC_PSIMMHFR1_MAC_HASH_FLT_HIGH(x) (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIMMHFR1_MAC_HASH_FLT_HIGH_SHIFT)) & NETC_ENETC_PSIMMHFR1_MAC_HASH_FLT_HIGH_MASK)
/*! @} */

/* The count of NETC_ENETC_PSIMMHFR1 */
#define NETC_ENETC_PSIMMHFR1_COUNT               (2U)

/*! @name PSIVHFR0 - Port station interface 0 VLAN hash filter register 0..Port station interface 1 VLAN hash filter register 0 */
/*! @{ */

#define NETC_ENETC_PSIVHFR0_VLAN_HASH_FLT_LOW_MASK (0xFFFFFFFFU)
#define NETC_ENETC_PSIVHFR0_VLAN_HASH_FLT_LOW_SHIFT (0U)
#define NETC_ENETC_PSIVHFR0_VLAN_HASH_FLT_LOW(x) (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIVHFR0_VLAN_HASH_FLT_LOW_SHIFT)) & NETC_ENETC_PSIVHFR0_VLAN_HASH_FLT_LOW_MASK)
/*! @} */

/* The count of NETC_ENETC_PSIVHFR0 */
#define NETC_ENETC_PSIVHFR0_COUNT                (2U)

/*! @name PSIVHFR1 - Port station interface 0 VLAN hash filter register 1..Port station interface 1 VLAN hash filter register 1 */
/*! @{ */

#define NETC_ENETC_PSIVHFR1_VLAN_HASH_FLT_HIGH_MASK (0xFFFFFFFFU)
#define NETC_ENETC_PSIVHFR1_VLAN_HASH_FLT_HIGH_SHIFT (0U)
#define NETC_ENETC_PSIVHFR1_VLAN_HASH_FLT_HIGH(x) (((uint32_t)(((uint32_t)(x)) << NETC_ENETC_PSIVHFR1_VLAN_HASH_FLT_HIGH_SHIFT)) & NETC_ENETC_PSIVHFR1_VLAN_HASH_FLT_HIGH_MASK)
/*! @} */

/* The count of NETC_ENETC_PSIVHFR1 */
#define NETC_ENETC_PSIVHFR1_COUNT                (2U)


/*!
 * @}
 */ /* end of group NETC_ENETC_Register_Masks */


/*!
 * @}
 */ /* end of group NETC_ENETC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_NETC_ENETC_H_ */

