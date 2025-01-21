/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181XVP2B
**                          MIMXRT1182CVP2B
**                          MIMXRT1182XVP2B
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**
**     Version:             rev. 2.0, 2024-01-18
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for NETC_PORT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
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
**
** ###################################################################
*/

/*!
 * @file NETC_PORT.h
 * @version 2.0
 * @date 2024-01-18
 * @brief CMSIS Peripheral Access Layer for NETC_PORT
 *
 * CMSIS Peripheral Access Layer for NETC_PORT
 */

#if !defined(NETC_PORT_H_)
#define NETC_PORT_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181XVP2B))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182XVP2B))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7))
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
   -- NETC_PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_PORT_Peripheral_Access_Layer NETC_PORT Peripheral Access Layer
 * @{
 */

/** NETC_PORT - Size of Registers Arrays */
#define NETC_PORT_TCT_NUM_COUNT                   8u

/** NETC_PORT - Register Layout Typedef */
typedef struct {
  __I  uint32_t PCAPR;                             /**< Port capability register, offset: 0x0 */
  __I  uint32_t PMCAPR;                            /**< Port MAC capability register, offset: 0x4 */
  __I  uint32_t PIOCAPR;                           /**< Port I/O capability register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t PCR;                               /**< Port configuration register, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t PMAR0;                             /**< Port MAC address register 0, offset: 0x20 */
  __IO uint32_t PMAR1;                             /**< Port MAC address register 1, offset: 0x24 */
       uint8_t RESERVED_2[40];
  __IO uint32_t PTAR;                              /**< Port TPID acceptance register, offset: 0x50 */
  __IO uint32_t PQOSMR;                            /**< Port QoS mode register, offset: 0x54 */
       uint8_t RESERVED_3[8];
  __I  uint32_t PQOR;                              /**< Port Queue Operational register, offset: 0x60, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_4[28];
  __IO uint32_t PPCR;                              /**< Port parser configuration register, offset: 0x80 */
  __IO uint32_t PIPFCR;                            /**< Port ingress port filter configuration register, offset: 0x84 */
       uint8_t RESERVED_5[24];
  __IO uint32_t PSGCR;                             /**< Port stream gate configuration register, offset: 0xA0 */
       uint8_t RESERVED_6[92];
  __IO uint32_t POR;                               /**< Port operational register, offset: 0x100 */
  __I  uint32_t PSR;                               /**< Port status register, offset: 0x104 */
  __IO uint32_t PRXSDUOR;                          /**< Port receive SDU overhead register, offset: 0x108 */
  __IO uint32_t PTXSDUOR;                          /**< Port transmit SDU overhead register, offset: 0x10C */
  __IO uint32_t PTGSCR;                            /**< Port time gate scheduling control register, offset: 0x110 */
  __I  uint32_t PTGAGLSR;                          /**< Port time gate scheduling admin gate list status register, offset: 0x114 */
  __I  uint32_t PTGAGLLR;                          /**< Port time gate scheduling admin gate list length register, offset: 0x118 */
  __I  uint32_t PTGOGLLR;                          /**< Port time gating operational gate list length register, offset: 0x11C */
  __IO uint32_t PTGSATOR;                          /**< Port time gate scheduling advance time offset register, offset: 0x120, available only on: ENETC0_PORT, ENETC1_PORT (missing on SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4) */
  __I  uint32_t PTGSHAR;                           /**< Port time gate scheduling hold advance register, offset: 0x124, available only on: ENETC0_PORT, SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3 (missing on ENETC1_PORT, SW0_PORT4) */
  __I  uint32_t PTGSRAR;                           /**< Port time gate scheduling release advance register, offset: 0x128, available only on: ENETC0_PORT, SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3 (missing on ENETC1_PORT, SW0_PORT4) */
  __IO uint32_t PTGSHCR;                           /**< Port time gate scheduling hold configuration register, offset: 0x12C, available only on: ENETC0_PORT, SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3 (missing on ENETC1_PORT, SW0_PORT4) */
       uint8_t RESERVED_7[4];
  __IO uint32_t PFPCR;                             /**< Port frame preemption configuration register, offset: 0x134, available only on: ENETC0_PORT, SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3 (missing on ENETC1_PORT, SW0_PORT4) */
  __IO uint32_t PDGSR;                             /**< Port default gate state register, offset: 0x138 */
       uint8_t RESERVED_8[132];
  __I  uint32_t PRXDCR;                            /**< Port Rx discard count register, offset: 0x1C0 */
       uint8_t RESERVED_9[4];
  __IO uint32_t PRXDCRR0;                          /**< Port Rx discard count reason register 0, offset: 0x1C8 */
  __IO uint32_t PRXDCRR1;                          /**< Port Rx discard count reason register 1, offset: 0x1CC */
       uint8_t RESERVED_10[16];
  __I  uint32_t PTXDCR;                            /**< Port Tx discard count register, offset: 0x1E0, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_11[4];
  __IO uint32_t PTXDCRR0;                          /**< Port Tx discard count reason register 0, offset: 0x1E8, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
  __IO uint32_t PTXDCRR1;                          /**< Port Tx discard count reason register 1, offset: 0x1EC, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_12[16];
  struct {                                         /* offset: 0x200, array step: 0x20 */
    __I  uint32_t PTGSTCSR;                          /**< Port time gate scheduling traffic class 0 status register..Port time gate scheduling traffic class 7 status register, array offset: 0x200, array step: 0x20 */
         uint8_t RESERVED_0[4];
    __IO uint32_t PTCTMSDUR;                         /**< Port traffic class 0 transmit maximum SDU register..Port traffic class 7 transmit maximum SDU register, array offset: 0x208, array step: 0x20 */
         uint8_t RESERVED_1[4];
    __IO uint32_t PTCCBSR0;                          /**< Port transmit traffic class 0 credit based shaper register 0..Port transmit traffic class 7 credit based shaper register 0, array offset: 0x210, array step: 0x20 */
    __IO uint32_t PTCCBSR1;                          /**< Port traffic class 0 credit based shaper register 1..Port traffic class 7 credit based shaper register 1, array offset: 0x214, array step: 0x20 */
         uint8_t RESERVED_2[8];
  } TCT_NUM[NETC_PORT_TCT_NUM_COUNT];
       uint8_t RESERVED_13[256];
  __IO uint32_t PBPMCR0;                           /**< Port buffer pool mapping configuration register 0, offset: 0x400, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
  __IO uint32_t PBPMCR1;                           /**< Port buffer pool mapping configuration register 1, offset: 0x404, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_14[48];
  __IO uint32_t PPCPDEIMR;                         /**< Port PCP DEI mapping register, offset: 0x438 */
       uint8_t RESERVED_15[4];
  __IO uint32_t PMCR;                              /**< Port mirror configuration register, offset: 0x440, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_16[12];
  __IO uint32_t PCTFCR;                            /**< Port cut through forwarding configuration register, offset: 0x450, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3 (missing on ENETC0_PORT, ENETC1_PORT, SW0_PORT4) */
       uint8_t RESERVED_17[4];
  __IO uint32_t PLANIDCR;                          /**< Port LANID configuration register, offset: 0x458, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_18[4];
  __IO uint32_t PISIDCR;                           /**< Port ingress stream identification configuration register, offset: 0x460 */
  __IO uint32_t PFMCR;                             /**< Port frame modification configuration register, offset: 0x464, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_19[8];
  __IO uint32_t PIPV2QMR0;                         /**< Port IPV to queue mapping register 0, offset: 0x470, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_20[60];
  __I  uint32_t PTCMINLR;                          /**< Port time capture minimum latency register, offset: 0x4B0, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
  __I  uint32_t PTCMAXLR;                          /**< Port time capture maximum latency register, offset: 0x4B4, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_21[72];
  __IO uint32_t BPCR;                              /**< Bridge port configuration register, offset: 0x500, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_22[12];
  __IO uint32_t BPDVR;                             /**< Bridge port default VLAN register, offset: 0x510, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_23[12];
  __IO uint32_t BPSTGSR;                           /**< Bridge port spanning tree group state register, offset: 0x520, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_24[4];
  __IO uint32_t BPSCR0;                            /**< Bridge port storm control register 0, offset: 0x528, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
  __IO uint32_t BPSCR1;                            /**< Bridge port storm control register 1, offset: 0x52C, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
  __I  uint32_t BPOR;                              /**< Bridge port operational register, offset: 0x530, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_25[76];
  __I  uint32_t BPDCR;                             /**< Bridge port discard count register, offset: 0x580, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
       uint8_t RESERVED_26[4];
  __IO uint32_t BPDCRR0;                           /**< Bridge port discard count reason register 0, offset: 0x588, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
  __IO uint32_t BPDCRR1;                           /**< Bridge port discard count reason register 1, offset: 0x58C, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
  __IO uint32_t BPMLFSR;                           /**< Bridge port MAC learning failure status register, offset: 0x590, available only on: SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 (missing on ENETC0_PORT, ENETC1_PORT) */
} NETC_PORT_Type;

/* ----------------------------------------------------------------------------
   -- NETC_PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_PORT_Register_Masks NETC_PORT Register Masks
 * @{
 */

/*! @name PCAPR - Port capability register */
/*! @{ */

#define NETC_PORT_PCAPR_LINK_TYPE_MASK           (0x10U)
#define NETC_PORT_PCAPR_LINK_TYPE_SHIFT          (4U)
#define NETC_PORT_PCAPR_LINK_TYPE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCAPR_LINK_TYPE_SHIFT)) & NETC_PORT_PCAPR_LINK_TYPE_MASK)

#define NETC_PORT_PCAPR_NUM_TC_MASK              (0xF000U)
#define NETC_PORT_PCAPR_NUM_TC_SHIFT             (12U)
#define NETC_PORT_PCAPR_NUM_TC(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCAPR_NUM_TC_SHIFT)) & NETC_PORT_PCAPR_NUM_TC_MASK)

#define NETC_PORT_PCAPR_NUM_Q_MASK               (0xF0000U)
#define NETC_PORT_PCAPR_NUM_Q_SHIFT              (16U)
#define NETC_PORT_PCAPR_NUM_Q(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCAPR_NUM_Q_SHIFT)) & NETC_PORT_PCAPR_NUM_Q_MASK)

#define NETC_PORT_PCAPR_NUM_CG_MASK              (0xF000000U)
#define NETC_PORT_PCAPR_NUM_CG_SHIFT             (24U)
#define NETC_PORT_PCAPR_NUM_CG(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCAPR_NUM_CG_SHIFT)) & NETC_PORT_PCAPR_NUM_CG_MASK)

#define NETC_PORT_PCAPR_TGS_MASK                 (0x10000000U)
#define NETC_PORT_PCAPR_TGS_SHIFT                (28U)
/*! TGS - Time Gate Scheduling */
#define NETC_PORT_PCAPR_TGS(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCAPR_TGS_SHIFT)) & NETC_PORT_PCAPR_TGS_MASK)

#define NETC_PORT_PCAPR_CBS_MASK                 (0x20000000U)
#define NETC_PORT_PCAPR_CBS_SHIFT                (29U)
/*! CBS - Credit Based Shaping */
#define NETC_PORT_PCAPR_CBS(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCAPR_CBS_SHIFT)) & NETC_PORT_PCAPR_CBS_MASK)
/*! @} */

/*! @name PMCAPR - Port MAC capability register */
/*! @{ */

#define NETC_PORT_PMCAPR_MAC_VAR_MASK            (0x7U)
#define NETC_PORT_PMCAPR_MAC_VAR_SHIFT           (0U)
/*! MAC_VAR - MAC Variant */
#define NETC_PORT_PMCAPR_MAC_VAR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PMCAPR_MAC_VAR_SHIFT)) & NETC_PORT_PMCAPR_MAC_VAR_MASK)

#define NETC_PORT_PMCAPR_EFPAD_MASK              (0x30U)
#define NETC_PORT_PMCAPR_EFPAD_SHIFT             (4U)
#define NETC_PORT_PMCAPR_EFPAD(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PMCAPR_EFPAD_SHIFT)) & NETC_PORT_PMCAPR_EFPAD_MASK)

#define NETC_PORT_PMCAPR_PIPG_MASK               (0x40U)
#define NETC_PORT_PMCAPR_PIPG_SHIFT              (6U)
#define NETC_PORT_PMCAPR_PIPG(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PMCAPR_PIPG_SHIFT)) & NETC_PORT_PMCAPR_PIPG_MASK)

#define NETC_PORT_PMCAPR_HD_MASK                 (0x100U)
#define NETC_PORT_PMCAPR_HD_SHIFT                (8U)
#define NETC_PORT_PMCAPR_HD(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PMCAPR_HD_SHIFT)) & NETC_PORT_PMCAPR_HD_MASK)

#define NETC_PORT_PMCAPR_FP_MASK                 (0x600U)
#define NETC_PORT_PMCAPR_FP_SHIFT                (9U)
/*! FP - Indicates if frame preemption is supported */
#define NETC_PORT_PMCAPR_FP(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PMCAPR_FP_SHIFT)) & NETC_PORT_PMCAPR_FP_MASK)

#define NETC_PORT_PMCAPR_MIN_MPDU_MASK           (0x1000U)
#define NETC_PORT_PMCAPR_MIN_MPDU_SHIFT          (12U)
/*! MIN_MPDU - Minimum MAC Protocol Data Unit (PDU) size check */
#define NETC_PORT_PMCAPR_MIN_MPDU(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PMCAPR_MIN_MPDU_SHIFT)) & NETC_PORT_PMCAPR_MIN_MPDU_MASK)

#define NETC_PORT_PMCAPR_MII_PROT_MASK           (0xF000000U)
#define NETC_PORT_PMCAPR_MII_PROT_SHIFT          (24U)
/*! MII_PROT - Indicates the MII protocol supported */
#define NETC_PORT_PMCAPR_MII_PROT(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PMCAPR_MII_PROT_SHIFT)) & NETC_PORT_PMCAPR_MII_PROT_MASK)
/*! @} */

/*! @name PIOCAPR - Port I/O capability register */
/*! @{ */

#define NETC_PORT_PIOCAPR_PCS_PROT_MASK          (0xFFFFU)
#define NETC_PORT_PIOCAPR_PCS_PROT_SHIFT         (0U)
/*! PCS_PROT - PCS protocols supported */
#define NETC_PORT_PIOCAPR_PCS_PROT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIOCAPR_PCS_PROT_SHIFT)) & NETC_PORT_PIOCAPR_PCS_PROT_MASK)

#define NETC_PORT_PIOCAPR_IO_VAR_MASK            (0xF000000U)
#define NETC_PORT_PIOCAPR_IO_VAR_SHIFT           (24U)
/*! IO_VAR - IO Variants supported */
#define NETC_PORT_PIOCAPR_IO_VAR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIOCAPR_IO_VAR_SHIFT)) & NETC_PORT_PIOCAPR_IO_VAR_MASK)

#define NETC_PORT_PIOCAPR_EMDIO_MASK             (0x10000000U)
#define NETC_PORT_PIOCAPR_EMDIO_SHIFT            (28U)
#define NETC_PORT_PIOCAPR_EMDIO(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIOCAPR_EMDIO_SHIFT)) & NETC_PORT_PIOCAPR_EMDIO_MASK)

#define NETC_PORT_PIOCAPR_REVMII_RATE_MASK       (0x40000000U)
#define NETC_PORT_PIOCAPR_REVMII_RATE_SHIFT      (30U)
/*! REVMII_RATE - RevMII MII rate */
#define NETC_PORT_PIOCAPR_REVMII_RATE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIOCAPR_REVMII_RATE_SHIFT)) & NETC_PORT_PIOCAPR_REVMII_RATE_MASK)

#define NETC_PORT_PIOCAPR_REVMII_MASK            (0x80000000U)
#define NETC_PORT_PIOCAPR_REVMII_SHIFT           (31U)
/*! REVMII - Reverse Mode Device Configuration */
#define NETC_PORT_PIOCAPR_REVMII(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIOCAPR_REVMII_SHIFT)) & NETC_PORT_PIOCAPR_REVMII_MASK)
/*! @} */

/*! @name PCR - Port configuration register */
/*! @{ */

#define NETC_PORT_PCR_HDR_FMT_MASK               (0x1U)
#define NETC_PORT_PCR_HDR_FMT_SHIFT              (0U)
#define NETC_PORT_PCR_HDR_FMT(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCR_HDR_FMT_SHIFT)) & NETC_PORT_PCR_HDR_FMT_MASK)

#define NETC_PORT_PCR_L2DOSE_MASK                (0x10U)
#define NETC_PORT_PCR_L2DOSE_SHIFT               (4U)
#define NETC_PORT_PCR_L2DOSE(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCR_L2DOSE_SHIFT)) & NETC_PORT_PCR_L2DOSE_MASK)

#define NETC_PORT_PCR_TIMER_CS_MASK              (0x100U)
#define NETC_PORT_PCR_TIMER_CS_SHIFT             (8U)
#define NETC_PORT_PCR_TIMER_CS(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCR_TIMER_CS_SHIFT)) & NETC_PORT_PCR_TIMER_CS_MASK)

#define NETC_PORT_PCR_PSPEED_MASK                (0x3FFF0000U)
#define NETC_PORT_PCR_PSPEED_SHIFT               (16U)
#define NETC_PORT_PCR_PSPEED(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCR_PSPEED_SHIFT)) & NETC_PORT_PCR_PSPEED_MASK)
/*! @} */

/*! @name PMAR0 - Port MAC address register 0 */
/*! @{ */

#define NETC_PORT_PMAR0_PRIM_MAC_ADDR_MASK       (0xFFFFFFFFU)
#define NETC_PORT_PMAR0_PRIM_MAC_ADDR_SHIFT      (0U)
#define NETC_PORT_PMAR0_PRIM_MAC_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PMAR0_PRIM_MAC_ADDR_SHIFT)) & NETC_PORT_PMAR0_PRIM_MAC_ADDR_MASK)
/*! @} */

/*! @name PMAR1 - Port MAC address register 1 */
/*! @{ */

#define NETC_PORT_PMAR1_PRIM_MAC_ADDR_MASK       (0xFFFFU)
#define NETC_PORT_PMAR1_PRIM_MAC_ADDR_SHIFT      (0U)
#define NETC_PORT_PMAR1_PRIM_MAC_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PMAR1_PRIM_MAC_ADDR_SHIFT)) & NETC_PORT_PMAR1_PRIM_MAC_ADDR_MASK)
/*! @} */

/*! @name PTAR - Port TPID acceptance register */
/*! @{ */

#define NETC_PORT_PTAR_OVTPIDL_MASK              (0xFU)
#define NETC_PORT_PTAR_OVTPIDL_SHIFT             (0U)
#define NETC_PORT_PTAR_OVTPIDL(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTAR_OVTPIDL_SHIFT)) & NETC_PORT_PTAR_OVTPIDL_MASK)

#define NETC_PORT_PTAR_IVTPIDL_MASK              (0xF0U)
#define NETC_PORT_PTAR_IVTPIDL_SHIFT             (4U)
#define NETC_PORT_PTAR_IVTPIDL(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTAR_IVTPIDL_SHIFT)) & NETC_PORT_PTAR_IVTPIDL_MASK)
/*! @} */

/*! @name PQOSMR - Port QoS mode register */
/*! @{ */

#define NETC_PORT_PQOSMR_VS_MASK                 (0x1U)
#define NETC_PORT_PQOSMR_VS_SHIFT                (0U)
#define NETC_PORT_PQOSMR_VS(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOSMR_VS_SHIFT)) & NETC_PORT_PQOSMR_VS_MASK)

#define NETC_PORT_PQOSMR_VE_MASK                 (0x2U)
#define NETC_PORT_PQOSMR_VE_SHIFT                (1U)
#define NETC_PORT_PQOSMR_VE(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOSMR_VE_SHIFT)) & NETC_PORT_PQOSMR_VE_MASK)

#define NETC_PORT_PQOSMR_DDR_MASK                (0xCU)
#define NETC_PORT_PQOSMR_DDR_SHIFT               (2U)
#define NETC_PORT_PQOSMR_DDR(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOSMR_DDR_SHIFT)) & NETC_PORT_PQOSMR_DDR_MASK)

#define NETC_PORT_PQOSMR_DIPV_MASK               (0x70U)
#define NETC_PORT_PQOSMR_DIPV_SHIFT              (4U)
#define NETC_PORT_PQOSMR_DIPV(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOSMR_DIPV_SHIFT)) & NETC_PORT_PQOSMR_DIPV_MASK)

#define NETC_PORT_PQOSMR_VQMP_MASK               (0xF0000U)
#define NETC_PORT_PQOSMR_VQMP_SHIFT              (16U)
/*! VQMP - Mapping profile index */
#define NETC_PORT_PQOSMR_VQMP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOSMR_VQMP_SHIFT)) & NETC_PORT_PQOSMR_VQMP_MASK)

#define NETC_PORT_PQOSMR_QVMP_MASK               (0xF00000U)
#define NETC_PORT_PQOSMR_QVMP_SHIFT              (20U)
/*! QVMP - Mapping profile index */
#define NETC_PORT_PQOSMR_QVMP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOSMR_QVMP_SHIFT)) & NETC_PORT_PQOSMR_QVMP_MASK)
/*! @} */

/*! @name PQOR - Port Queue Operational register */
/*! @{ */

#define NETC_PORT_PQOR_Q0S_MASK                  (0x1U)
#define NETC_PORT_PQOR_Q0S_SHIFT                 (0U)
#define NETC_PORT_PQOR_Q0S(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOR_Q0S_SHIFT)) & NETC_PORT_PQOR_Q0S_MASK)

#define NETC_PORT_PQOR_Q1S_MASK                  (0x2U)
#define NETC_PORT_PQOR_Q1S_SHIFT                 (1U)
#define NETC_PORT_PQOR_Q1S(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOR_Q1S_SHIFT)) & NETC_PORT_PQOR_Q1S_MASK)

#define NETC_PORT_PQOR_Q2S_MASK                  (0x4U)
#define NETC_PORT_PQOR_Q2S_SHIFT                 (2U)
#define NETC_PORT_PQOR_Q2S(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOR_Q2S_SHIFT)) & NETC_PORT_PQOR_Q2S_MASK)

#define NETC_PORT_PQOR_Q3S_MASK                  (0x8U)
#define NETC_PORT_PQOR_Q3S_SHIFT                 (3U)
#define NETC_PORT_PQOR_Q3S(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOR_Q3S_SHIFT)) & NETC_PORT_PQOR_Q3S_MASK)

#define NETC_PORT_PQOR_Q4S_MASK                  (0x10U)
#define NETC_PORT_PQOR_Q4S_SHIFT                 (4U)
#define NETC_PORT_PQOR_Q4S(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOR_Q4S_SHIFT)) & NETC_PORT_PQOR_Q4S_MASK)

#define NETC_PORT_PQOR_Q5S_MASK                  (0x20U)
#define NETC_PORT_PQOR_Q5S_SHIFT                 (5U)
#define NETC_PORT_PQOR_Q5S(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOR_Q5S_SHIFT)) & NETC_PORT_PQOR_Q5S_MASK)

#define NETC_PORT_PQOR_Q6S_MASK                  (0x40U)
#define NETC_PORT_PQOR_Q6S_SHIFT                 (6U)
#define NETC_PORT_PQOR_Q6S(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOR_Q6S_SHIFT)) & NETC_PORT_PQOR_Q6S_MASK)

#define NETC_PORT_PQOR_Q7S_MASK                  (0x80U)
#define NETC_PORT_PQOR_Q7S_SHIFT                 (7U)
#define NETC_PORT_PQOR_Q7S(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PQOR_Q7S_SHIFT)) & NETC_PORT_PQOR_Q7S_MASK)
/*! @} */

/*! @name PPCR - Port parser configuration register */
/*! @{ */

#define NETC_PORT_PPCR_L1PFS_MASK                (0x3EU)
#define NETC_PORT_PPCR_L1PFS_SHIFT               (1U)
#define NETC_PORT_PPCR_L1PFS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCR_L1PFS_SHIFT)) & NETC_PORT_PPCR_L1PFS_MASK)

#define NETC_PORT_PPCR_L2PFS_MASK                (0x3E00U)
#define NETC_PORT_PPCR_L2PFS_SHIFT               (9U)
#define NETC_PORT_PPCR_L2PFS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCR_L2PFS_SHIFT)) & NETC_PORT_PPCR_L2PFS_MASK)

#define NETC_PORT_PPCR_L3HFP_MASK                (0x10000U)
#define NETC_PORT_PPCR_L3HFP_SHIFT               (16U)
/*! L3HFP - L3 header fields present
 *  0b0..No L3 header present. Indicates to the parser of not parsing the L3 header. Parsing in this case would go
 *       as far as the L2 header regardless of whether or not there is an L3 header in the frame. This option
 *       should not be used if there are any table lookup entries that contain L3/L4 key fields that could be matched
 *       against a frame.
 *  0b1..Parse L3 header if present in the frame.
 */
#define NETC_PORT_PPCR_L3HFP(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCR_L3HFP_SHIFT)) & NETC_PORT_PPCR_L3HFP_MASK)

#define NETC_PORT_PPCR_L3PFS_MASK                (0x3E0000U)
#define NETC_PORT_PPCR_L3PFS_SHIFT               (17U)
/*! L3PFS - L3 payload fields size in bytes */
#define NETC_PORT_PPCR_L3PFS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCR_L3PFS_SHIFT)) & NETC_PORT_PPCR_L3PFS_MASK)

#define NETC_PORT_PPCR_L4HFP_MASK                (0x1000000U)
#define NETC_PORT_PPCR_L4HFP_SHIFT               (24U)
/*! L4HFP - L4 Header fields present
 *  0b0..No L4 header present. Indicates to the parser of not parsing the L4 header. Parsing in this case would go
 *       as far as the L3 header if configured to parse it (L3HFP=1) regardless of whether or not there is an L4
 *       header in the frame. This option should not be used if there are any table lookup entries that contain L4
 *       key fields that could be matched against a frame.
 *  0b1..Parse L4 header if present in the frame
 */
#define NETC_PORT_PPCR_L4HFP(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCR_L4HFP_SHIFT)) & NETC_PORT_PPCR_L4HFP_MASK)

#define NETC_PORT_PPCR_L4PFS_MASK                (0x3E000000U)
#define NETC_PORT_PPCR_L4PFS_SHIFT               (25U)
/*! L4PFS - L4 payload fields size in bytes */
#define NETC_PORT_PPCR_L4PFS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCR_L4PFS_SHIFT)) & NETC_PORT_PPCR_L4PFS_MASK)
/*! @} */

/*! @name PIPFCR - Port ingress port filter configuration register */
/*! @{ */

#define NETC_PORT_PIPFCR_EN_MASK                 (0x1U)
#define NETC_PORT_PIPFCR_EN_SHIFT                (0U)
#define NETC_PORT_PIPFCR_EN(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIPFCR_EN_SHIFT)) & NETC_PORT_PIPFCR_EN_MASK)
/*! @} */

/*! @name PSGCR - Port stream gate configuration register */
/*! @{ */

#define NETC_PORT_PSGCR_PDELAY_MASK              (0xFFFFFFU)
#define NETC_PORT_PSGCR_PDELAY_SHIFT             (0U)
#define NETC_PORT_PSGCR_PDELAY(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PSGCR_PDELAY_SHIFT)) & NETC_PORT_PSGCR_PDELAY_MASK)

#define NETC_PORT_PSGCR_OGC_MASK                 (0x80000000U)
#define NETC_PORT_PSGCR_OGC_SHIFT                (31U)
/*! OGC - Stream Gate Open Gate Check mode */
#define NETC_PORT_PSGCR_OGC(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PSGCR_OGC_SHIFT)) & NETC_PORT_PSGCR_OGC_MASK)
/*! @} */

/*! @name POR - Port operational register */
/*! @{ */

#define NETC_PORT_POR_TXDIS_MASK                 (0x1U)
#define NETC_PORT_POR_TXDIS_SHIFT                (0U)
/*! TXDIS - Tx Disable.
 *  0b0..Tx path is enabled
 *  0b1..Tx path is disabled.
 */
#define NETC_PORT_POR_TXDIS(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_POR_TXDIS_SHIFT)) & NETC_PORT_POR_TXDIS_MASK)

#define NETC_PORT_POR_RXDIS_MASK                 (0x2U)
#define NETC_PORT_POR_RXDIS_SHIFT                (1U)
/*! RXDIS - Rx Disable.
 *  0b0..Rx path is enabled.
 *  0b1..Rx path is disabled.
 */
#define NETC_PORT_POR_RXDIS(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_POR_RXDIS_SHIFT)) & NETC_PORT_POR_RXDIS_MASK)
/*! @} */

/*! @name PSR - Port status register */
/*! @{ */

#define NETC_PORT_PSR_TX_BUSY_MASK               (0x1U)
#define NETC_PORT_PSR_TX_BUSY_SHIFT              (0U)
/*! TX_BUSY - Transmit busy.
 *  0b0..Idle
 *  0b1..Busy
 */
#define NETC_PORT_PSR_TX_BUSY(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PSR_TX_BUSY_SHIFT)) & NETC_PORT_PSR_TX_BUSY_MASK)

#define NETC_PORT_PSR_RX_BUSY_MASK               (0x2U)
#define NETC_PORT_PSR_RX_BUSY_SHIFT              (1U)
/*! RX_BUSY - Receive busy.
 *  0b0..Idle
 *  0b1..Busy
 */
#define NETC_PORT_PSR_RX_BUSY(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PSR_RX_BUSY_SHIFT)) & NETC_PORT_PSR_RX_BUSY_MASK)
/*! @} */

/*! @name PRXSDUOR - Port receive SDU overhead register */
/*! @{ */

#define NETC_PORT_PRXSDUOR_PPDU_BCO_MASK         (0x1FU)
#define NETC_PORT_PRXSDUOR_PPDU_BCO_SHIFT        (0U)
/*! PPDU_BCO - PPDU Byte count overhead */
#define NETC_PORT_PRXSDUOR_PPDU_BCO(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXSDUOR_PPDU_BCO_SHIFT)) & NETC_PORT_PRXSDUOR_PPDU_BCO_MASK)

#define NETC_PORT_PRXSDUOR_MACSEC_BCO_MASK       (0x1F00U)
#define NETC_PORT_PRXSDUOR_MACSEC_BCO_SHIFT      (8U)
/*! MACSEC_BCO - MACSec byte count overhead */
#define NETC_PORT_PRXSDUOR_MACSEC_BCO(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXSDUOR_MACSEC_BCO_SHIFT)) & NETC_PORT_PRXSDUOR_MACSEC_BCO_MASK)
/*! @} */

/*! @name PTXSDUOR - Port transmit SDU overhead register */
/*! @{ */

#define NETC_PORT_PTXSDUOR_PPDU_BCO_MASK         (0x1FU)
#define NETC_PORT_PTXSDUOR_PPDU_BCO_SHIFT        (0U)
/*! PPDU_BCO - PPDU Byte count overhead */
#define NETC_PORT_PTXSDUOR_PPDU_BCO(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXSDUOR_PPDU_BCO_SHIFT)) & NETC_PORT_PTXSDUOR_PPDU_BCO_MASK)

#define NETC_PORT_PTXSDUOR_MACSEC_BCO_MASK       (0x1F00U)
#define NETC_PORT_PTXSDUOR_MACSEC_BCO_SHIFT      (8U)
/*! MACSEC_BCO - MACSec byte count overhead */
#define NETC_PORT_PTXSDUOR_MACSEC_BCO(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXSDUOR_MACSEC_BCO_SHIFT)) & NETC_PORT_PTXSDUOR_MACSEC_BCO_MASK)
/*! @} */

/*! @name PTGSCR - Port time gate scheduling control register */
/*! @{ */

#define NETC_PORT_PTGSCR_TGE_MASK                (0x80000000U)
#define NETC_PORT_PTGSCR_TGE_SHIFT               (31U)
/*! TGE - Time Gating Enable
 *  0b0..Time gating disabled.
 *  0b1..Time gating enabled.
 */
#define NETC_PORT_PTGSCR_TGE(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTGSCR_TGE_SHIFT)) & NETC_PORT_PTGSCR_TGE_MASK)
/*! @} */

/*! @name PTGAGLSR - Port time gate scheduling admin gate list status register */
/*! @{ */

#define NETC_PORT_PTGAGLSR_TG_MASK               (0x1U)
#define NETC_PORT_PTGAGLSR_TG_SHIFT              (0U)
#define NETC_PORT_PTGAGLSR_TG(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTGAGLSR_TG_SHIFT)) & NETC_PORT_PTGAGLSR_TG_MASK)

#define NETC_PORT_PTGAGLSR_CFG_PEND_MASK         (0x2U)
#define NETC_PORT_PTGAGLSR_CFG_PEND_SHIFT        (1U)
#define NETC_PORT_PTGAGLSR_CFG_PEND(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTGAGLSR_CFG_PEND_SHIFT)) & NETC_PORT_PTGAGLSR_CFG_PEND_MASK)
/*! @} */

/*! @name PTGAGLLR - Port time gate scheduling admin gate list length register */
/*! @{ */

#define NETC_PORT_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_MASK (0xFFFFU)
#define NETC_PORT_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_SHIFT (0U)
#define NETC_PORT_PTGAGLLR_ADMIN_GATE_LIST_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_SHIFT)) & NETC_PORT_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_MASK)
/*! @} */

/*! @name PTGOGLLR - Port time gating operational gate list length register */
/*! @{ */

#define NETC_PORT_PTGOGLLR_OPER_GATE_LIST_LENGTH_MASK (0xFFFFU)
#define NETC_PORT_PTGOGLLR_OPER_GATE_LIST_LENGTH_SHIFT (0U)
#define NETC_PORT_PTGOGLLR_OPER_GATE_LIST_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTGOGLLR_OPER_GATE_LIST_LENGTH_SHIFT)) & NETC_PORT_PTGOGLLR_OPER_GATE_LIST_LENGTH_MASK)
/*! @} */

/*! @name PTGSATOR - Port time gate scheduling advance time offset register */
/*! @{ */

#define NETC_PORT_PTGSATOR_ADV_TIME_OFFSET_MASK  (0xFFFFU)
#define NETC_PORT_PTGSATOR_ADV_TIME_OFFSET_SHIFT (0U)
#define NETC_PORT_PTGSATOR_ADV_TIME_OFFSET(x)    (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTGSATOR_ADV_TIME_OFFSET_SHIFT)) & NETC_PORT_PTGSATOR_ADV_TIME_OFFSET_MASK)
/*! @} */

/*! @name PTGSHAR - Port time gate scheduling hold advance register */
/*! @{ */

#define NETC_PORT_PTGSHAR_HOLDADVANCE_MASK       (0xFFFFU)
#define NETC_PORT_PTGSHAR_HOLDADVANCE_SHIFT      (0U)
#define NETC_PORT_PTGSHAR_HOLDADVANCE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTGSHAR_HOLDADVANCE_SHIFT)) & NETC_PORT_PTGSHAR_HOLDADVANCE_MASK)
/*! @} */

/*! @name PTGSRAR - Port time gate scheduling release advance register */
/*! @{ */

#define NETC_PORT_PTGSRAR_RELEASEADVANCE_MASK    (0xFFFFU)
#define NETC_PORT_PTGSRAR_RELEASEADVANCE_SHIFT   (0U)
#define NETC_PORT_PTGSRAR_RELEASEADVANCE(x)      (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTGSRAR_RELEASEADVANCE_SHIFT)) & NETC_PORT_PTGSRAR_RELEASEADVANCE_MASK)
/*! @} */

/*! @name PTGSHCR - Port time gate scheduling hold configuration register */
/*! @{ */

#define NETC_PORT_PTGSHCR_HOLD_SKEW_MASK         (0xFFFFFU)
#define NETC_PORT_PTGSHCR_HOLD_SKEW_SHIFT        (0U)
#define NETC_PORT_PTGSHCR_HOLD_SKEW(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTGSHCR_HOLD_SKEW_SHIFT)) & NETC_PORT_PTGSHCR_HOLD_SKEW_MASK)
/*! @} */

/*! @name PFPCR - Port frame preemption configuration register */
/*! @{ */

#define NETC_PORT_PFPCR_FPE_TC0_MASK             (0x1U)
#define NETC_PORT_PFPCR_FPE_TC0_SHIFT            (0U)
#define NETC_PORT_PFPCR_FPE_TC0(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PFPCR_FPE_TC0_SHIFT)) & NETC_PORT_PFPCR_FPE_TC0_MASK)

#define NETC_PORT_PFPCR_FPE_TC1_MASK             (0x2U)
#define NETC_PORT_PFPCR_FPE_TC1_SHIFT            (1U)
#define NETC_PORT_PFPCR_FPE_TC1(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PFPCR_FPE_TC1_SHIFT)) & NETC_PORT_PFPCR_FPE_TC1_MASK)

#define NETC_PORT_PFPCR_FPE_TC2_MASK             (0x4U)
#define NETC_PORT_PFPCR_FPE_TC2_SHIFT            (2U)
#define NETC_PORT_PFPCR_FPE_TC2(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PFPCR_FPE_TC2_SHIFT)) & NETC_PORT_PFPCR_FPE_TC2_MASK)

#define NETC_PORT_PFPCR_FPE_TC3_MASK             (0x8U)
#define NETC_PORT_PFPCR_FPE_TC3_SHIFT            (3U)
#define NETC_PORT_PFPCR_FPE_TC3(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PFPCR_FPE_TC3_SHIFT)) & NETC_PORT_PFPCR_FPE_TC3_MASK)

#define NETC_PORT_PFPCR_FPE_TC4_MASK             (0x10U)
#define NETC_PORT_PFPCR_FPE_TC4_SHIFT            (4U)
#define NETC_PORT_PFPCR_FPE_TC4(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PFPCR_FPE_TC4_SHIFT)) & NETC_PORT_PFPCR_FPE_TC4_MASK)

#define NETC_PORT_PFPCR_FPE_TC5_MASK             (0x20U)
#define NETC_PORT_PFPCR_FPE_TC5_SHIFT            (5U)
#define NETC_PORT_PFPCR_FPE_TC5(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PFPCR_FPE_TC5_SHIFT)) & NETC_PORT_PFPCR_FPE_TC5_MASK)

#define NETC_PORT_PFPCR_FPE_TC6_MASK             (0x40U)
#define NETC_PORT_PFPCR_FPE_TC6_SHIFT            (6U)
#define NETC_PORT_PFPCR_FPE_TC6(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PFPCR_FPE_TC6_SHIFT)) & NETC_PORT_PFPCR_FPE_TC6_MASK)

#define NETC_PORT_PFPCR_FPE_TC7_MASK             (0x80U)
#define NETC_PORT_PFPCR_FPE_TC7_SHIFT            (7U)
#define NETC_PORT_PFPCR_FPE_TC7(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PFPCR_FPE_TC7_SHIFT)) & NETC_PORT_PFPCR_FPE_TC7_MASK)
/*! @} */

/*! @name PDGSR - Port default gate state register */
/*! @{ */

#define NETC_PORT_PDGSR_DGS_TC0_MASK             (0x1U)
#define NETC_PORT_PDGSR_DGS_TC0_SHIFT            (0U)
/*! DGS_TC0
 *  0b0..Closed
 *  0b1..Open
 */
#define NETC_PORT_PDGSR_DGS_TC0(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PDGSR_DGS_TC0_SHIFT)) & NETC_PORT_PDGSR_DGS_TC0_MASK)

#define NETC_PORT_PDGSR_DGS_TC1_MASK             (0x2U)
#define NETC_PORT_PDGSR_DGS_TC1_SHIFT            (1U)
/*! DGS_TC1
 *  0b0..Closed
 *  0b1..Open
 */
#define NETC_PORT_PDGSR_DGS_TC1(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PDGSR_DGS_TC1_SHIFT)) & NETC_PORT_PDGSR_DGS_TC1_MASK)

#define NETC_PORT_PDGSR_DGS_TC2_MASK             (0x4U)
#define NETC_PORT_PDGSR_DGS_TC2_SHIFT            (2U)
/*! DGS_TC2
 *  0b0..Closed
 *  0b1..Open
 */
#define NETC_PORT_PDGSR_DGS_TC2(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PDGSR_DGS_TC2_SHIFT)) & NETC_PORT_PDGSR_DGS_TC2_MASK)

#define NETC_PORT_PDGSR_DGS_TC3_MASK             (0x8U)
#define NETC_PORT_PDGSR_DGS_TC3_SHIFT            (3U)
/*! DGS_TC3
 *  0b0..Closed
 *  0b1..Open
 */
#define NETC_PORT_PDGSR_DGS_TC3(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PDGSR_DGS_TC3_SHIFT)) & NETC_PORT_PDGSR_DGS_TC3_MASK)

#define NETC_PORT_PDGSR_DGS_TC4_MASK             (0x10U)
#define NETC_PORT_PDGSR_DGS_TC4_SHIFT            (4U)
/*! DGS_TC4
 *  0b0..Closed
 *  0b1..Open
 */
#define NETC_PORT_PDGSR_DGS_TC4(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PDGSR_DGS_TC4_SHIFT)) & NETC_PORT_PDGSR_DGS_TC4_MASK)

#define NETC_PORT_PDGSR_DGS_TC5_MASK             (0x20U)
#define NETC_PORT_PDGSR_DGS_TC5_SHIFT            (5U)
/*! DGS_TC5
 *  0b0..Closed
 *  0b1..Open
 */
#define NETC_PORT_PDGSR_DGS_TC5(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PDGSR_DGS_TC5_SHIFT)) & NETC_PORT_PDGSR_DGS_TC5_MASK)

#define NETC_PORT_PDGSR_DGS_TC6_MASK             (0x40U)
#define NETC_PORT_PDGSR_DGS_TC6_SHIFT            (6U)
/*! DGS_TC6
 *  0b0..Closed
 *  0b1..Open
 */
#define NETC_PORT_PDGSR_DGS_TC6(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PDGSR_DGS_TC6_SHIFT)) & NETC_PORT_PDGSR_DGS_TC6_MASK)

#define NETC_PORT_PDGSR_DGS_TC7_MASK             (0x80U)
#define NETC_PORT_PDGSR_DGS_TC7_SHIFT            (7U)
/*! DGS_TC7
 *  0b0..Closed
 *  0b1..Open
 */
#define NETC_PORT_PDGSR_DGS_TC7(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PDGSR_DGS_TC7_SHIFT)) & NETC_PORT_PDGSR_DGS_TC7_MASK)
/*! @} */

/*! @name PRXDCR - Port Rx discard count register */
/*! @{ */

#define NETC_PORT_PRXDCR_COUNT_MASK              (0xFFFFFFFFU)
#define NETC_PORT_PRXDCR_COUNT_SHIFT             (0U)
#define NETC_PORT_PRXDCR_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCR_COUNT_SHIFT)) & NETC_PORT_PRXDCR_COUNT_MASK)
/*! @} */

/*! @name PRXDCRR0 - Port Rx discard count reason register 0 */
/*! @{ */

#define NETC_PORT_PRXDCRR0_PCDR_MASK             (0x1U)
#define NETC_PORT_PRXDCRR0_PCDR_SHIFT            (0U)
#define NETC_PORT_PRXDCRR0_PCDR(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_PCDR_SHIFT)) & NETC_PORT_PRXDCRR0_PCDR_MASK)

#define NETC_PORT_PRXDCRR0_SMREDR_MASK           (0x2U)
#define NETC_PORT_PRXDCRR0_SMREDR_SHIFT          (1U)
#define NETC_PORT_PRXDCRR0_SMREDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_SMREDR_SHIFT)) & NETC_PORT_PRXDCRR0_SMREDR_MASK)

#define NETC_PORT_PRXDCRR0_RXDISDR_MASK          (0x4U)
#define NETC_PORT_PRXDCRR0_RXDISDR_SHIFT         (2U)
#define NETC_PORT_PRXDCRR0_RXDISDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_RXDISDR_SHIFT)) & NETC_PORT_PRXDCRR0_RXDISDR_MASK)

#define NETC_PORT_PRXDCRR0_IPFDR_MASK            (0x8U)
#define NETC_PORT_PRXDCRR0_IPFDR_SHIFT           (3U)
#define NETC_PORT_PRXDCRR0_IPFDR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_IPFDR_SHIFT)) & NETC_PORT_PRXDCRR0_IPFDR_MASK)

#define NETC_PORT_PRXDCRR0_RPDR_MASK             (0x10U)
#define NETC_PORT_PRXDCRR0_RPDR_SHIFT            (4U)
#define NETC_PORT_PRXDCRR0_RPDR(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_RPDR_SHIFT)) & NETC_PORT_PRXDCRR0_RPDR_MASK)

#define NETC_PORT_PRXDCRR0_ISFDR_MASK            (0x20U)
#define NETC_PORT_PRXDCRR0_ISFDR_SHIFT           (5U)
#define NETC_PORT_PRXDCRR0_ISFDR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_ISFDR_SHIFT)) & NETC_PORT_PRXDCRR0_ISFDR_MASK)

#define NETC_PORT_PRXDCRR0_SGCDR_MASK            (0x40U)
#define NETC_PORT_PRXDCRR0_SGCDR_SHIFT           (6U)
#define NETC_PORT_PRXDCRR0_SGCDR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_SGCDR_SHIFT)) & NETC_PORT_PRXDCRR0_SGCDR_MASK)

#define NETC_PORT_PRXDCRR0_SGOEDR_MASK           (0x80U)
#define NETC_PORT_PRXDCRR0_SGOEDR_SHIFT          (7U)
#define NETC_PORT_PRXDCRR0_SGOEDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_SGOEDR_SHIFT)) & NETC_PORT_PRXDCRR0_SGOEDR_MASK)

#define NETC_PORT_PRXDCRR0_MSDUEDR_MASK          (0x100U)
#define NETC_PORT_PRXDCRR0_MSDUEDR_SHIFT         (8U)
#define NETC_PORT_PRXDCRR0_MSDUEDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_MSDUEDR_SHIFT)) & NETC_PORT_PRXDCRR0_MSDUEDR_MASK)

#define NETC_PORT_PRXDCRR0_FMMEDR_MASK           (0x200U)
#define NETC_PORT_PRXDCRR0_FMMEDR_SHIFT          (9U)
#define NETC_PORT_PRXDCRR0_FMMEDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_FMMEDR_SHIFT)) & NETC_PORT_PRXDCRR0_FMMEDR_MASK)

#define NETC_PORT_PRXDCRR0_CMDR_MASK             (0x400U)
#define NETC_PORT_PRXDCRR0_CMDR_SHIFT            (10U)
#define NETC_PORT_PRXDCRR0_CMDR(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_CMDR_SHIFT)) & NETC_PORT_PRXDCRR0_CMDR_MASK)

#define NETC_PORT_PRXDCRR0_ITEDR_MASK            (0x800U)
#define NETC_PORT_PRXDCRR0_ITEDR_SHIFT           (11U)
#define NETC_PORT_PRXDCRR0_ITEDR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_ITEDR_SHIFT)) & NETC_PORT_PRXDCRR0_ITEDR_MASK)

#define NETC_PORT_PRXDCRR0_ECCEDR_MASK           (0x1000U)
#define NETC_PORT_PRXDCRR0_ECCEDR_SHIFT          (12U)
#define NETC_PORT_PRXDCRR0_ECCEDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_ECCEDR_SHIFT)) & NETC_PORT_PRXDCRR0_ECCEDR_MASK)

#define NETC_PORT_PRXDCRR0_SIFDR_MASK            (0x2000U)
#define NETC_PORT_PRXDCRR0_SIFDR_SHIFT           (13U)
#define NETC_PORT_PRXDCRR0_SIFDR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_SIFDR_SHIFT)) & NETC_PORT_PRXDCRR0_SIFDR_MASK)

#define NETC_PORT_PRXDCRR0_L2DOSDR_MASK          (0x4000U)
#define NETC_PORT_PRXDCRR0_L2DOSDR_SHIFT         (14U)
#define NETC_PORT_PRXDCRR0_L2DOSDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_L2DOSDR_SHIFT)) & NETC_PORT_PRXDCRR0_L2DOSDR_MASK)

#define NETC_PORT_PRXDCRR0_NODESTDR_MASK         (0x20000U)
#define NETC_PORT_PRXDCRR0_NODESTDR_SHIFT        (17U)
/*! NODESTDR - No Destination Discard Reason */
#define NETC_PORT_PRXDCRR0_NODESTDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR0_NODESTDR_SHIFT)) & NETC_PORT_PRXDCRR0_NODESTDR_MASK)
/*! @} */

/*! @name PRXDCRR1 - Port Rx discard count reason register 1 */
/*! @{ */

#define NETC_PORT_PRXDCRR1_ENTRYID_MASK          (0xFFFFU)
#define NETC_PORT_PRXDCRR1_ENTRYID_SHIFT         (0U)
#define NETC_PORT_PRXDCRR1_ENTRYID(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR1_ENTRYID_SHIFT)) & NETC_PORT_PRXDCRR1_ENTRYID_MASK)

#define NETC_PORT_PRXDCRR1_TT_MASK               (0xF0000000U)
#define NETC_PORT_PRXDCRR1_TT_SHIFT              (28U)
#define NETC_PORT_PRXDCRR1_TT(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PRXDCRR1_TT_SHIFT)) & NETC_PORT_PRXDCRR1_TT_MASK)
/*! @} */

/*! @name PTXDCR - Port Tx discard count register */
/*! @{ */

#define NETC_PORT_PTXDCR_COUNT_MASK              (0xFFFFFFFFU)
#define NETC_PORT_PTXDCR_COUNT_SHIFT             (0U)
#define NETC_PORT_PTXDCR_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCR_COUNT_SHIFT)) & NETC_PORT_PTXDCR_COUNT_MASK)
/*! @} */

/*! @name PTXDCRR0 - Port Tx discard count reason register 0 */
/*! @{ */

#define NETC_PORT_PTXDCRR0_TXDISDR_MASK          (0x1U)
#define NETC_PORT_PTXDCRR0_TXDISDR_SHIFT         (0U)
#define NETC_PORT_PTXDCRR0_TXDISDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_TXDISDR_SHIFT)) & NETC_PORT_PTXDCRR0_TXDISDR_MASK)

#define NETC_PORT_PTXDCRR0_ECCEDR_MASK           (0x2U)
#define NETC_PORT_PTXDCRR0_ECCEDR_SHIFT          (1U)
/*! ECCEDR - ECC Error Discard Reason */
#define NETC_PORT_PTXDCRR0_ECCEDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_ECCEDR_SHIFT)) & NETC_PORT_PTXDCRR0_ECCEDR_MASK)

#define NETC_PORT_PTXDCRR0_PEDR_MASK             (0x4U)
#define NETC_PORT_PTXDCRR0_PEDR_SHIFT            (2U)
/*! PEDR - Parity Error Discard Reason */
#define NETC_PORT_PTXDCRR0_PEDR(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_PEDR_SHIFT)) & NETC_PORT_PTXDCRR0_PEDR_MASK)

#define NETC_PORT_PTXDCRR0_TGSFTLDR_MASK         (0x10U)
#define NETC_PORT_PTXDCRR0_TGSFTLDR_SHIFT        (4U)
#define NETC_PORT_PTXDCRR0_TGSFTLDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_TGSFTLDR_SHIFT)) & NETC_PORT_PTXDCRR0_TGSFTLDR_MASK)

#define NETC_PORT_PTXDCRR0_FMMDR_MASK            (0x20U)
#define NETC_PORT_PTXDCRR0_FMMDR_SHIFT           (5U)
#define NETC_PORT_PTXDCRR0_FMMDR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_FMMDR_SHIFT)) & NETC_PORT_PTXDCRR0_FMMDR_MASK)

#define NETC_PORT_PTXDCRR0_TXDISEDR_MASK         (0x40U)
#define NETC_PORT_PTXDCRR0_TXDISEDR_SHIFT        (6U)
#define NETC_PORT_PTXDCRR0_TXDISEDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_TXDISEDR_SHIFT)) & NETC_PORT_PTXDCRR0_TXDISEDR_MASK)

#define NETC_PORT_PTXDCRR0_MSDUEDR_MASK          (0x80U)
#define NETC_PORT_PTXDCRR0_MSDUEDR_SHIFT         (7U)
#define NETC_PORT_PTXDCRR0_MSDUEDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_MSDUEDR_SHIFT)) & NETC_PORT_PTXDCRR0_MSDUEDR_MASK)

#define NETC_PORT_PTXDCRR0_QCONGDR_MASK          (0x100U)
#define NETC_PORT_PTXDCRR0_QCONGDR_SHIFT         (8U)
#define NETC_PORT_PTXDCRR0_QCONGDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_QCONGDR_SHIFT)) & NETC_PORT_PTXDCRR0_QCONGDR_MASK)

#define NETC_PORT_PTXDCRR0_ITEDR_MASK            (0x200U)
#define NETC_PORT_PTXDCRR0_ITEDR_SHIFT           (9U)
#define NETC_PORT_PTXDCRR0_ITEDR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_ITEDR_SHIFT)) & NETC_PORT_PTXDCRR0_ITEDR_MASK)

#define NETC_PORT_PTXDCRR0_INVEQDR_MASK          (0x400U)
#define NETC_PORT_PTXDCRR0_INVEQDR_SHIFT         (10U)
#define NETC_PORT_PTXDCRR0_INVEQDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_INVEQDR_SHIFT)) & NETC_PORT_PTXDCRR0_INVEQDR_MASK)

#define NETC_PORT_PTXDCRR0_SQRTNSQDR_MASK        (0x800U)
#define NETC_PORT_PTXDCRR0_SQRTNSQDR_SHIFT       (11U)
#define NETC_PORT_PTXDCRR0_SQRTNSQDR(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_SQRTNSQDR_SHIFT)) & NETC_PORT_PTXDCRR0_SQRTNSQDR_MASK)

#define NETC_PORT_PTXDCRR0_SQRRDR_MASK           (0x2000U)
#define NETC_PORT_PTXDCRR0_SQRRDR_SHIFT          (13U)
#define NETC_PORT_PTXDCRR0_SQRRDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_SQRRDR_SHIFT)) & NETC_PORT_PTXDCRR0_SQRRDR_MASK)

#define NETC_PORT_PTXDCRR0_SQRDDR_MASK           (0x4000U)
#define NETC_PORT_PTXDCRR0_SQRDDR_SHIFT          (14U)
#define NETC_PORT_PTXDCRR0_SQRDDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_SQRDDR_SHIFT)) & NETC_PORT_PTXDCRR0_SQRDDR_MASK)

#define NETC_PORT_PTXDCRR0_SMREDR_MASK           (0x8000U)
#define NETC_PORT_PTXDCRR0_SMREDR_SHIFT          (15U)
#define NETC_PORT_PTXDCRR0_SMREDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR0_SMREDR_SHIFT)) & NETC_PORT_PTXDCRR0_SMREDR_MASK)
/*! @} */

/*! @name PTXDCRR1 - Port Tx discard count reason register 1 */
/*! @{ */

#define NETC_PORT_PTXDCRR1_ENTRYID_MASK          (0xFFFFU)
#define NETC_PORT_PTXDCRR1_ENTRYID_SHIFT         (0U)
#define NETC_PORT_PTXDCRR1_ENTRYID(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR1_ENTRYID_SHIFT)) & NETC_PORT_PTXDCRR1_ENTRYID_MASK)

#define NETC_PORT_PTXDCRR1_TT_MASK               (0xF0000000U)
#define NETC_PORT_PTXDCRR1_TT_SHIFT              (28U)
#define NETC_PORT_PTXDCRR1_TT(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTXDCRR1_TT_SHIFT)) & NETC_PORT_PTXDCRR1_TT_MASK)
/*! @} */

/*! @name PTGSTCSR - Port time gate scheduling traffic class 0 status register..Port time gate scheduling traffic class 7 status register */
/*! @{ */

#define NETC_PORT_PTGSTCSR_LH_STATE_MASK         (0x10000U)
#define NETC_PORT_PTGSTCSR_LH_STATE_SHIFT        (16U)
#define NETC_PORT_PTGSTCSR_LH_STATE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTGSTCSR_LH_STATE_SHIFT)) & NETC_PORT_PTGSTCSR_LH_STATE_MASK)
/*! @} */

/* The count of NETC_PORT_PTGSTCSR */
#define NETC_PORT_PTGSTCSR_COUNT                 (8U)

/*! @name PTCTMSDUR - Port traffic class 0 transmit maximum SDU register..Port traffic class 7 transmit maximum SDU register */
/*! @{ */

#define NETC_PORT_PTCTMSDUR_MAXSDU_MASK          (0xFFFFU)
#define NETC_PORT_PTCTMSDUR_MAXSDU_SHIFT         (0U)
#define NETC_PORT_PTCTMSDUR_MAXSDU(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTCTMSDUR_MAXSDU_SHIFT)) & NETC_PORT_PTCTMSDUR_MAXSDU_MASK)

#define NETC_PORT_PTCTMSDUR_SDU_TYPE_MASK        (0x30000U)
#define NETC_PORT_PTCTMSDUR_SDU_TYPE_SHIFT       (16U)
#define NETC_PORT_PTCTMSDUR_SDU_TYPE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTCTMSDUR_SDU_TYPE_SHIFT)) & NETC_PORT_PTCTMSDUR_SDU_TYPE_MASK)

#define NETC_PORT_PTCTMSDUR_SF_MAXSDU_DIS_MASK   (0x1000000U)
#define NETC_PORT_PTCTMSDUR_SF_MAXSDU_DIS_SHIFT  (24U)
#define NETC_PORT_PTCTMSDUR_SF_MAXSDU_DIS(x)     (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTCTMSDUR_SF_MAXSDU_DIS_SHIFT)) & NETC_PORT_PTCTMSDUR_SF_MAXSDU_DIS_MASK)
/*! @} */

/* The count of NETC_PORT_PTCTMSDUR */
#define NETC_PORT_PTCTMSDUR_COUNT                (8U)

/*! @name PTCCBSR0 - Port transmit traffic class 0 credit based shaper register 0..Port transmit traffic class 7 credit based shaper register 0 */
/*! @{ */

#define NETC_PORT_PTCCBSR0_BW_MASK               (0x7FU)
#define NETC_PORT_PTCCBSR0_BW_SHIFT              (0U)
/*! BW - Bandwidth */
#define NETC_PORT_PTCCBSR0_BW(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTCCBSR0_BW_SHIFT)) & NETC_PORT_PTCCBSR0_BW_MASK)

#define NETC_PORT_PTCCBSR0_CBSE_MASK             (0x80000000U)
#define NETC_PORT_PTCCBSR0_CBSE_SHIFT            (31U)
/*! CBSE - Credit Based Shaper Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_PORT_PTCCBSR0_CBSE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTCCBSR0_CBSE_SHIFT)) & NETC_PORT_PTCCBSR0_CBSE_MASK)
/*! @} */

/* The count of NETC_PORT_PTCCBSR0 */
#define NETC_PORT_PTCCBSR0_COUNT                 (8U)

/*! @name PTCCBSR1 - Port traffic class 0 credit based shaper register 1..Port traffic class 7 credit based shaper register 1 */
/*! @{ */

#define NETC_PORT_PTCCBSR1_HI_CREDIT_MASK        (0xFFFFFFFFU)
#define NETC_PORT_PTCCBSR1_HI_CREDIT_SHIFT       (0U)
/*! HI_CREDIT - hicredit (in credit units) */
#define NETC_PORT_PTCCBSR1_HI_CREDIT(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTCCBSR1_HI_CREDIT_SHIFT)) & NETC_PORT_PTCCBSR1_HI_CREDIT_MASK)
/*! @} */

/* The count of NETC_PORT_PTCCBSR1 */
#define NETC_PORT_PTCCBSR1_COUNT                 (8U)

/*! @name PBPMCR0 - Port buffer pool mapping configuration register 0 */
/*! @{ */

#define NETC_PORT_PBPMCR0_IPV0_INDEX_MASK        (0xFFU)
#define NETC_PORT_PBPMCR0_IPV0_INDEX_SHIFT       (0U)
#define NETC_PORT_PBPMCR0_IPV0_INDEX(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PBPMCR0_IPV0_INDEX_SHIFT)) & NETC_PORT_PBPMCR0_IPV0_INDEX_MASK)

#define NETC_PORT_PBPMCR0_IPV1_INDEX_MASK        (0xFF00U)
#define NETC_PORT_PBPMCR0_IPV1_INDEX_SHIFT       (8U)
#define NETC_PORT_PBPMCR0_IPV1_INDEX(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PBPMCR0_IPV1_INDEX_SHIFT)) & NETC_PORT_PBPMCR0_IPV1_INDEX_MASK)

#define NETC_PORT_PBPMCR0_IPV2_INDEX_MASK        (0xFF0000U)
#define NETC_PORT_PBPMCR0_IPV2_INDEX_SHIFT       (16U)
#define NETC_PORT_PBPMCR0_IPV2_INDEX(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PBPMCR0_IPV2_INDEX_SHIFT)) & NETC_PORT_PBPMCR0_IPV2_INDEX_MASK)

#define NETC_PORT_PBPMCR0_IPV3_INDEX_MASK        (0xFF000000U)
#define NETC_PORT_PBPMCR0_IPV3_INDEX_SHIFT       (24U)
#define NETC_PORT_PBPMCR0_IPV3_INDEX(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PBPMCR0_IPV3_INDEX_SHIFT)) & NETC_PORT_PBPMCR0_IPV3_INDEX_MASK)
/*! @} */

/*! @name PBPMCR1 - Port buffer pool mapping configuration register 1 */
/*! @{ */

#define NETC_PORT_PBPMCR1_IPV4_INDEX_MASK        (0xFFU)
#define NETC_PORT_PBPMCR1_IPV4_INDEX_SHIFT       (0U)
#define NETC_PORT_PBPMCR1_IPV4_INDEX(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PBPMCR1_IPV4_INDEX_SHIFT)) & NETC_PORT_PBPMCR1_IPV4_INDEX_MASK)

#define NETC_PORT_PBPMCR1_IPV5_INDEX_MASK        (0xFF00U)
#define NETC_PORT_PBPMCR1_IPV5_INDEX_SHIFT       (8U)
#define NETC_PORT_PBPMCR1_IPV5_INDEX(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PBPMCR1_IPV5_INDEX_SHIFT)) & NETC_PORT_PBPMCR1_IPV5_INDEX_MASK)

#define NETC_PORT_PBPMCR1_IPV6_INDEX_MASK        (0xFF0000U)
#define NETC_PORT_PBPMCR1_IPV6_INDEX_SHIFT       (16U)
#define NETC_PORT_PBPMCR1_IPV6_INDEX(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PBPMCR1_IPV6_INDEX_SHIFT)) & NETC_PORT_PBPMCR1_IPV6_INDEX_MASK)

#define NETC_PORT_PBPMCR1_IPV7_INDEX_MASK        (0xFF000000U)
#define NETC_PORT_PBPMCR1_IPV7_INDEX_SHIFT       (24U)
#define NETC_PORT_PBPMCR1_IPV7_INDEX(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PBPMCR1_IPV7_INDEX_SHIFT)) & NETC_PORT_PBPMCR1_IPV7_INDEX_MASK)
/*! @} */

/*! @name PPCPDEIMR - Port PCP DEI mapping register */
/*! @{ */

#define NETC_PORT_PPCPDEIMR_IPCPMP_MASK          (0xFU)
#define NETC_PORT_PPCPDEIMR_IPCPMP_SHIFT         (0U)
#define NETC_PORT_PPCPDEIMR_IPCPMP(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCPDEIMR_IPCPMP_SHIFT)) & NETC_PORT_PPCPDEIMR_IPCPMP_MASK)

#define NETC_PORT_PPCPDEIMR_IPCPMPV_MASK         (0x80U)
#define NETC_PORT_PPCPDEIMR_IPCPMPV_SHIFT        (7U)
/*! IPCPMPV
 *  0b0..Ingress PCP to PCP Mapping Profile is not valid.
 *  0b1..Ingress frame modification of outer VLAN tag's PCP value is mapped to a new value based on IPCPMP instance
 */
#define NETC_PORT_PPCPDEIMR_IPCPMPV(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCPDEIMR_IPCPMPV_SHIFT)) & NETC_PORT_PPCPDEIMR_IPCPMPV_MASK)

#define NETC_PORT_PPCPDEIMR_EPCPMP_MASK          (0xF00U)
#define NETC_PORT_PPCPDEIMR_EPCPMP_SHIFT         (8U)
#define NETC_PORT_PPCPDEIMR_EPCPMP(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCPDEIMR_EPCPMP_SHIFT)) & NETC_PORT_PPCPDEIMR_EPCPMP_MASK)

#define NETC_PORT_PPCPDEIMR_EPCPMPV_MASK         (0x8000U)
#define NETC_PORT_PPCPDEIMR_EPCPMPV_SHIFT        (15U)
/*! EPCPMPV
 *  0b0..Egress PCP to PCP Mapping Profile is not valid.
 *  0b1..Egress frame modification of outer VLAN tag's PCP value is mapped to a new value based on EPCPMP instance.
 */
#define NETC_PORT_PPCPDEIMR_EPCPMPV(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCPDEIMR_EPCPMPV_SHIFT)) & NETC_PORT_PPCPDEIMR_EPCPMPV_MASK)

#define NETC_PORT_PPCPDEIMR_DR0DEI_MASK          (0x10000U)
#define NETC_PORT_PPCPDEIMR_DR0DEI_SHIFT         (16U)
#define NETC_PORT_PPCPDEIMR_DR0DEI(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCPDEIMR_DR0DEI_SHIFT)) & NETC_PORT_PPCPDEIMR_DR0DEI_MASK)

#define NETC_PORT_PPCPDEIMR_DR1DEI_MASK          (0x20000U)
#define NETC_PORT_PPCPDEIMR_DR1DEI_SHIFT         (17U)
#define NETC_PORT_PPCPDEIMR_DR1DEI(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCPDEIMR_DR1DEI_SHIFT)) & NETC_PORT_PPCPDEIMR_DR1DEI_MASK)

#define NETC_PORT_PPCPDEIMR_DR2DEI_MASK          (0x40000U)
#define NETC_PORT_PPCPDEIMR_DR2DEI_SHIFT         (18U)
#define NETC_PORT_PPCPDEIMR_DR2DEI(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCPDEIMR_DR2DEI_SHIFT)) & NETC_PORT_PPCPDEIMR_DR2DEI_MASK)

#define NETC_PORT_PPCPDEIMR_DR3DEI_MASK          (0x80000U)
#define NETC_PORT_PPCPDEIMR_DR3DEI_SHIFT         (19U)
#define NETC_PORT_PPCPDEIMR_DR3DEI(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCPDEIMR_DR3DEI_SHIFT)) & NETC_PORT_PPCPDEIMR_DR3DEI_MASK)

#define NETC_PORT_PPCPDEIMR_DRME_MASK            (0x100000U)
#define NETC_PORT_PPCPDEIMR_DRME_SHIFT           (20U)
/*! DRME
 *  0b0..Preserve the DR value in the outer VLAN.
 *  0b1..Update DR value in the outer VLAN based on DEnDEI field.
 */
#define NETC_PORT_PPCPDEIMR_DRME(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PPCPDEIMR_DRME_SHIFT)) & NETC_PORT_PPCPDEIMR_DRME_MASK)
/*! @} */

/*! @name PMCR - Port mirror configuration register */
/*! @{ */

#define NETC_PORT_PMCR_IMIRE_MASK                (0x1U)
#define NETC_PORT_PMCR_IMIRE_SHIFT               (0U)
#define NETC_PORT_PMCR_IMIRE(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PMCR_IMIRE_SHIFT)) & NETC_PORT_PMCR_IMIRE_MASK)
/*! @} */

/*! @name PCTFCR - Port cut through forwarding configuration register */
/*! @{ */

#define NETC_PORT_PCTFCR_ICTS_MASK               (0x1U)
#define NETC_PORT_PCTFCR_ICTS_SHIFT              (0U)
#define NETC_PORT_PCTFCR_ICTS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCTFCR_ICTS_SHIFT)) & NETC_PORT_PCTFCR_ICTS_MASK)

#define NETC_PORT_PCTFCR_ECTS_MASK               (0x2U)
#define NETC_PORT_PCTFCR_ECTS_SHIFT              (1U)
#define NETC_PORT_PCTFCR_ECTS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PCTFCR_ECTS_SHIFT)) & NETC_PORT_PCTFCR_ECTS_MASK)
/*! @} */

/*! @name PLANIDCR - Port LANID configuration register */
/*! @{ */

#define NETC_PORT_PLANIDCR_LANID_MASK            (0xFU)
#define NETC_PORT_PLANIDCR_LANID_SHIFT           (0U)
/*! LANID - LAN Identifier */
#define NETC_PORT_PLANIDCR_LANID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PLANIDCR_LANID_SHIFT)) & NETC_PORT_PLANIDCR_LANID_MASK)
/*! @} */

/*! @name PISIDCR - Port ingress stream identification configuration register */
/*! @{ */

#define NETC_PORT_PISIDCR_KCPAIR_MASK            (0x1U)
#define NETC_PORT_PISIDCR_KCPAIR_SHIFT           (0U)
#define NETC_PORT_PISIDCR_KCPAIR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PISIDCR_KCPAIR_SHIFT)) & NETC_PORT_PISIDCR_KCPAIR_MASK)

#define NETC_PORT_PISIDCR_KC0EN_MASK             (0x2U)
#define NETC_PORT_PISIDCR_KC0EN_SHIFT            (1U)
/*! KC0EN - Key Construction 0 Enable */
#define NETC_PORT_PISIDCR_KC0EN(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PISIDCR_KC0EN_SHIFT)) & NETC_PORT_PISIDCR_KC0EN_MASK)

#define NETC_PORT_PISIDCR_KC1EN_MASK             (0x4U)
#define NETC_PORT_PISIDCR_KC1EN_SHIFT            (2U)
/*! KC1EN - Key Construction 1 Enable */
#define NETC_PORT_PISIDCR_KC1EN(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PISIDCR_KC1EN_SHIFT)) & NETC_PORT_PISIDCR_KC1EN_MASK)

#define NETC_PORT_PISIDCR_ISEID_MASK             (0xFFFF0000U)
#define NETC_PORT_PISIDCR_ISEID_SHIFT            (16U)
#define NETC_PORT_PISIDCR_ISEID(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PISIDCR_ISEID_SHIFT)) & NETC_PORT_PISIDCR_ISEID_MASK)
/*! @} */

/*! @name PFMCR - Port frame modification configuration register */
/*! @{ */

#define NETC_PORT_PFMCR_FMMA_MASK                (0x1U)
#define NETC_PORT_PFMCR_FMMA_SHIFT               (0U)
/*! FMMA - Frame Modification Misconfiguration Action
 *  0b0..Discard the frame and counted against the port's Tx discard count register (PTXDCR) along with the
 *       setting of the Frame Modification Misconfiguration Discard Reason (FMMDR) flag to 1 in the port's Tx discard
 *       count reason register 0 (PTXDCRR0).
 *  0b1..Transmit the frame without performing any of the ingress and egress frame modification actions specified.
 */
#define NETC_PORT_PFMCR_FMMA(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PFMCR_FMMA_SHIFT)) & NETC_PORT_PFMCR_FMMA_MASK)
/*! @} */

/*! @name PIPV2QMR0 - Port IPV to queue mapping register 0 */
/*! @{ */

#define NETC_PORT_PIPV2QMR0_IPV0_Q_MASK          (0xFU)
#define NETC_PORT_PIPV2QMR0_IPV0_Q_SHIFT         (0U)
#define NETC_PORT_PIPV2QMR0_IPV0_Q(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIPV2QMR0_IPV0_Q_SHIFT)) & NETC_PORT_PIPV2QMR0_IPV0_Q_MASK)

#define NETC_PORT_PIPV2QMR0_IPV1_Q_MASK          (0xF0U)
#define NETC_PORT_PIPV2QMR0_IPV1_Q_SHIFT         (4U)
#define NETC_PORT_PIPV2QMR0_IPV1_Q(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIPV2QMR0_IPV1_Q_SHIFT)) & NETC_PORT_PIPV2QMR0_IPV1_Q_MASK)

#define NETC_PORT_PIPV2QMR0_IPV2_Q_MASK          (0xF00U)
#define NETC_PORT_PIPV2QMR0_IPV2_Q_SHIFT         (8U)
#define NETC_PORT_PIPV2QMR0_IPV2_Q(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIPV2QMR0_IPV2_Q_SHIFT)) & NETC_PORT_PIPV2QMR0_IPV2_Q_MASK)

#define NETC_PORT_PIPV2QMR0_IPV3_Q_MASK          (0xF000U)
#define NETC_PORT_PIPV2QMR0_IPV3_Q_SHIFT         (12U)
#define NETC_PORT_PIPV2QMR0_IPV3_Q(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIPV2QMR0_IPV3_Q_SHIFT)) & NETC_PORT_PIPV2QMR0_IPV3_Q_MASK)

#define NETC_PORT_PIPV2QMR0_IPV4_Q_MASK          (0xF0000U)
#define NETC_PORT_PIPV2QMR0_IPV4_Q_SHIFT         (16U)
#define NETC_PORT_PIPV2QMR0_IPV4_Q(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIPV2QMR0_IPV4_Q_SHIFT)) & NETC_PORT_PIPV2QMR0_IPV4_Q_MASK)

#define NETC_PORT_PIPV2QMR0_IPV5_Q_MASK          (0xF00000U)
#define NETC_PORT_PIPV2QMR0_IPV5_Q_SHIFT         (20U)
#define NETC_PORT_PIPV2QMR0_IPV5_Q(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIPV2QMR0_IPV5_Q_SHIFT)) & NETC_PORT_PIPV2QMR0_IPV5_Q_MASK)

#define NETC_PORT_PIPV2QMR0_IPV6_Q_MASK          (0xF000000U)
#define NETC_PORT_PIPV2QMR0_IPV6_Q_SHIFT         (24U)
#define NETC_PORT_PIPV2QMR0_IPV6_Q(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIPV2QMR0_IPV6_Q_SHIFT)) & NETC_PORT_PIPV2QMR0_IPV6_Q_MASK)

#define NETC_PORT_PIPV2QMR0_IPV7_Q_MASK          (0xF0000000U)
#define NETC_PORT_PIPV2QMR0_IPV7_Q_SHIFT         (28U)
#define NETC_PORT_PIPV2QMR0_IPV7_Q(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PIPV2QMR0_IPV7_Q_SHIFT)) & NETC_PORT_PIPV2QMR0_IPV7_Q_MASK)
/*! @} */

/*! @name PTCMINLR - Port time capture minimum latency register */
/*! @{ */

#define NETC_PORT_PTCMINLR_LATENCY_MASK          (0x3FFFFFFFU)
#define NETC_PORT_PTCMINLR_LATENCY_SHIFT         (0U)
#define NETC_PORT_PTCMINLR_LATENCY(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTCMINLR_LATENCY_SHIFT)) & NETC_PORT_PTCMINLR_LATENCY_MASK)

#define NETC_PORT_PTCMINLR_COUNT_MASK            (0xC0000000U)
#define NETC_PORT_PTCMINLR_COUNT_SHIFT           (30U)
#define NETC_PORT_PTCMINLR_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTCMINLR_COUNT_SHIFT)) & NETC_PORT_PTCMINLR_COUNT_MASK)
/*! @} */

/*! @name PTCMAXLR - Port time capture maximum latency register */
/*! @{ */

#define NETC_PORT_PTCMAXLR_LATENCY_MASK          (0x3FFFFFFFU)
#define NETC_PORT_PTCMAXLR_LATENCY_SHIFT         (0U)
#define NETC_PORT_PTCMAXLR_LATENCY(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_PTCMAXLR_LATENCY_SHIFT)) & NETC_PORT_PTCMAXLR_LATENCY_MASK)
/*! @} */

/*! @name BPCR - Bridge port configuration register */
/*! @{ */

#define NETC_PORT_BPCR_DYN_LIMIT_MASK            (0xFFFFU)
#define NETC_PORT_BPCR_DYN_LIMIT_SHIFT           (0U)
/*! DYN_LIMIT - Dynamic Limit */
#define NETC_PORT_BPCR_DYN_LIMIT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPCR_DYN_LIMIT_SHIFT)) & NETC_PORT_BPCR_DYN_LIMIT_MASK)

#define NETC_PORT_BPCR_UUCASTE_MASK              (0x1000000U)
#define NETC_PORT_BPCR_UUCASTE_SHIFT             (24U)
/*! UUCASTE - Unknown Unicast Storm Control Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_PORT_BPCR_UUCASTE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPCR_UUCASTE_SHIFT)) & NETC_PORT_BPCR_UUCASTE_MASK)

#define NETC_PORT_BPCR_UMCASTE_MASK              (0x2000000U)
#define NETC_PORT_BPCR_UMCASTE_SHIFT             (25U)
/*! UMCASTE - Unknown Multicast Storm Control Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_PORT_BPCR_UMCASTE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPCR_UMCASTE_SHIFT)) & NETC_PORT_BPCR_UMCASTE_MASK)

#define NETC_PORT_BPCR_MCASTE_MASK               (0x4000000U)
#define NETC_PORT_BPCR_MCASTE_SHIFT              (26U)
/*! MCASTE - Multicast Storm Control Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_PORT_BPCR_MCASTE(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPCR_MCASTE_SHIFT)) & NETC_PORT_BPCR_MCASTE_MASK)

#define NETC_PORT_BPCR_BCASTE_MASK               (0x8000000U)
#define NETC_PORT_BPCR_BCASTE_SHIFT              (27U)
/*! BCASTE - Broadcast Storm Control Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NETC_PORT_BPCR_BCASTE(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPCR_BCASTE_SHIFT)) & NETC_PORT_BPCR_BCASTE_MASK)

#define NETC_PORT_BPCR_STAMVD_MASK               (0x10000000U)
#define NETC_PORT_BPCR_STAMVD_SHIFT              (28U)
/*! STAMVD - Station Move Disallow
 *  0b0..Allowed
 *  0b1..Disallowed. A received frame for which a MAC station move is detected, will be discarded.
 */
#define NETC_PORT_BPCR_STAMVD(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPCR_STAMVD_SHIFT)) & NETC_PORT_BPCR_STAMVD_MASK)

#define NETC_PORT_BPCR_SRCPRND_MASK              (0x20000000U)
#define NETC_PORT_BPCR_SRCPRND_SHIFT             (29U)
/*! SRCPRND - Source Port Pruning Disable
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define NETC_PORT_BPCR_SRCPRND(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPCR_SRCPRND_SHIFT)) & NETC_PORT_BPCR_SRCPRND_MASK)
/*! @} */

/*! @name BPDVR - Bridge port default VLAN register */
/*! @{ */

#define NETC_PORT_BPDVR_VID_MASK                 (0xFFFU)
#define NETC_PORT_BPDVR_VID_SHIFT                (0U)
#define NETC_PORT_BPDVR_VID(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDVR_VID_SHIFT)) & NETC_PORT_BPDVR_VID_MASK)

#define NETC_PORT_BPDVR_DEI_MASK                 (0x1000U)
#define NETC_PORT_BPDVR_DEI_SHIFT                (12U)
#define NETC_PORT_BPDVR_DEI(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDVR_DEI_SHIFT)) & NETC_PORT_BPDVR_DEI_MASK)

#define NETC_PORT_BPDVR_PCP_MASK                 (0xE000U)
#define NETC_PORT_BPDVR_PCP_SHIFT                (13U)
#define NETC_PORT_BPDVR_PCP(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDVR_PCP_SHIFT)) & NETC_PORT_BPDVR_PCP_MASK)

#define NETC_PORT_BPDVR_TPID_MASK                (0x10000U)
#define NETC_PORT_BPDVR_TPID_SHIFT               (16U)
#define NETC_PORT_BPDVR_TPID(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDVR_TPID_SHIFT)) & NETC_PORT_BPDVR_TPID_MASK)

#define NETC_PORT_BPDVR_RXTAGA_MASK              (0xF00000U)
#define NETC_PORT_BPDVR_RXTAGA_SHIFT             (20U)
#define NETC_PORT_BPDVR_RXTAGA(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDVR_RXTAGA_SHIFT)) & NETC_PORT_BPDVR_RXTAGA_MASK)

#define NETC_PORT_BPDVR_RXVAM_MASK               (0x1000000U)
#define NETC_PORT_BPDVR_RXVAM_SHIFT              (24U)
#define NETC_PORT_BPDVR_RXVAM(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDVR_RXVAM_SHIFT)) & NETC_PORT_BPDVR_RXVAM_MASK)

#define NETC_PORT_BPDVR_TXTAGA_MASK              (0x6000000U)
#define NETC_PORT_BPDVR_TXTAGA_SHIFT             (25U)
#define NETC_PORT_BPDVR_TXTAGA(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDVR_TXTAGA_SHIFT)) & NETC_PORT_BPDVR_TXTAGA_MASK)
/*! @} */

/*! @name BPSTGSR - Bridge port spanning tree group state register */
/*! @{ */

#define NETC_PORT_BPSTGSR_STG_STATE0_MASK        (0x3U)
#define NETC_PORT_BPSTGSR_STG_STATE0_SHIFT       (0U)
#define NETC_PORT_BPSTGSR_STG_STATE0(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE0_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE0_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE1_MASK        (0xCU)
#define NETC_PORT_BPSTGSR_STG_STATE1_SHIFT       (2U)
#define NETC_PORT_BPSTGSR_STG_STATE1(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE1_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE1_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE2_MASK        (0x30U)
#define NETC_PORT_BPSTGSR_STG_STATE2_SHIFT       (4U)
#define NETC_PORT_BPSTGSR_STG_STATE2(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE2_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE2_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE3_MASK        (0xC0U)
#define NETC_PORT_BPSTGSR_STG_STATE3_SHIFT       (6U)
#define NETC_PORT_BPSTGSR_STG_STATE3(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE3_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE3_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE4_MASK        (0x300U)
#define NETC_PORT_BPSTGSR_STG_STATE4_SHIFT       (8U)
#define NETC_PORT_BPSTGSR_STG_STATE4(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE4_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE4_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE5_MASK        (0xC00U)
#define NETC_PORT_BPSTGSR_STG_STATE5_SHIFT       (10U)
#define NETC_PORT_BPSTGSR_STG_STATE5(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE5_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE5_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE6_MASK        (0x3000U)
#define NETC_PORT_BPSTGSR_STG_STATE6_SHIFT       (12U)
#define NETC_PORT_BPSTGSR_STG_STATE6(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE6_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE6_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE7_MASK        (0xC000U)
#define NETC_PORT_BPSTGSR_STG_STATE7_SHIFT       (14U)
#define NETC_PORT_BPSTGSR_STG_STATE7(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE7_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE7_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE8_MASK        (0x30000U)
#define NETC_PORT_BPSTGSR_STG_STATE8_SHIFT       (16U)
#define NETC_PORT_BPSTGSR_STG_STATE8(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE8_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE8_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE9_MASK        (0xC0000U)
#define NETC_PORT_BPSTGSR_STG_STATE9_SHIFT       (18U)
#define NETC_PORT_BPSTGSR_STG_STATE9(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE9_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE9_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE10_MASK       (0x300000U)
#define NETC_PORT_BPSTGSR_STG_STATE10_SHIFT      (20U)
#define NETC_PORT_BPSTGSR_STG_STATE10(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE10_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE10_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE11_MASK       (0xC00000U)
#define NETC_PORT_BPSTGSR_STG_STATE11_SHIFT      (22U)
#define NETC_PORT_BPSTGSR_STG_STATE11(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE11_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE11_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE12_MASK       (0x3000000U)
#define NETC_PORT_BPSTGSR_STG_STATE12_SHIFT      (24U)
#define NETC_PORT_BPSTGSR_STG_STATE12(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE12_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE12_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE13_MASK       (0xC000000U)
#define NETC_PORT_BPSTGSR_STG_STATE13_SHIFT      (26U)
#define NETC_PORT_BPSTGSR_STG_STATE13(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE13_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE13_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE14_MASK       (0x30000000U)
#define NETC_PORT_BPSTGSR_STG_STATE14_SHIFT      (28U)
#define NETC_PORT_BPSTGSR_STG_STATE14(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE14_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE14_MASK)

#define NETC_PORT_BPSTGSR_STG_STATE15_MASK       (0xC0000000U)
#define NETC_PORT_BPSTGSR_STG_STATE15_SHIFT      (30U)
#define NETC_PORT_BPSTGSR_STG_STATE15(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSTGSR_STG_STATE15_SHIFT)) & NETC_PORT_BPSTGSR_STG_STATE15_MASK)
/*! @} */

/*! @name BPSCR0 - Bridge port storm control register 0 */
/*! @{ */

#define NETC_PORT_BPSCR0_UUCASTRPEID_MASK        (0xFFFU)
#define NETC_PORT_BPSCR0_UUCASTRPEID_SHIFT       (0U)
#define NETC_PORT_BPSCR0_UUCASTRPEID(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSCR0_UUCASTRPEID_SHIFT)) & NETC_PORT_BPSCR0_UUCASTRPEID_MASK)

#define NETC_PORT_BPSCR0_BCASTRPEID_MASK         (0xFFF0000U)
#define NETC_PORT_BPSCR0_BCASTRPEID_SHIFT        (16U)
#define NETC_PORT_BPSCR0_BCASTRPEID(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSCR0_BCASTRPEID_SHIFT)) & NETC_PORT_BPSCR0_BCASTRPEID_MASK)
/*! @} */

/*! @name BPSCR1 - Bridge port storm control register 1 */
/*! @{ */

#define NETC_PORT_BPSCR1_MCASTRPEID_MASK         (0xFFFU)
#define NETC_PORT_BPSCR1_MCASTRPEID_SHIFT        (0U)
#define NETC_PORT_BPSCR1_MCASTRPEID(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSCR1_MCASTRPEID_SHIFT)) & NETC_PORT_BPSCR1_MCASTRPEID_MASK)

#define NETC_PORT_BPSCR1_UMCASTRPEID_MASK        (0xFFF0000U)
#define NETC_PORT_BPSCR1_UMCASTRPEID_SHIFT       (16U)
#define NETC_PORT_BPSCR1_UMCASTRPEID(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPSCR1_UMCASTRPEID_SHIFT)) & NETC_PORT_BPSCR1_UMCASTRPEID_MASK)
/*! @} */

/*! @name BPOR - Bridge port operational register */
/*! @{ */

#define NETC_PORT_BPOR_NUM_DYN_MASK              (0xFFFFU)
#define NETC_PORT_BPOR_NUM_DYN_SHIFT             (0U)
#define NETC_PORT_BPOR_NUM_DYN(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPOR_NUM_DYN_SHIFT)) & NETC_PORT_BPOR_NUM_DYN_MASK)
/*! @} */

/*! @name BPDCR - Bridge port discard count register */
/*! @{ */

#define NETC_PORT_BPDCR_COUNT_MASK               (0xFFFFFFFFU)
#define NETC_PORT_BPDCR_COUNT_SHIFT              (0U)
#define NETC_PORT_BPDCR_COUNT(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCR_COUNT_SHIFT)) & NETC_PORT_BPDCR_COUNT_MASK)
/*! @} */

/*! @name BPDCRR0 - Bridge port discard count reason register 0 */
/*! @{ */

#define NETC_PORT_BPDCRR0_BPACDR_MASK            (0x1U)
#define NETC_PORT_BPDCRR0_BPACDR_SHIFT           (0U)
#define NETC_PORT_BPDCRR0_BPACDR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR0_BPACDR_SHIFT)) & NETC_PORT_BPDCRR0_BPACDR_MASK)

#define NETC_PORT_BPDCRR0_ISTGSDR_MASK           (0x2U)
#define NETC_PORT_BPDCRR0_ISTGSDR_SHIFT          (1U)
#define NETC_PORT_BPDCRR0_ISTGSDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR0_ISTGSDR_SHIFT)) & NETC_PORT_BPDCRR0_ISTGSDR_MASK)

#define NETC_PORT_BPDCRR0_BPVFLTDR_MASK          (0x4U)
#define NETC_PORT_BPDCRR0_BPVFLTDR_SHIFT         (2U)
#define NETC_PORT_BPDCRR0_BPVFLTDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR0_BPVFLTDR_SHIFT)) & NETC_PORT_BPDCRR0_BPVFLTDR_MASK)

#define NETC_PORT_BPDCRR0_MACLNFDR_MASK          (0x8U)
#define NETC_PORT_BPDCRR0_MACLNFDR_SHIFT         (3U)
#define NETC_PORT_BPDCRR0_MACLNFDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR0_MACLNFDR_SHIFT)) & NETC_PORT_BPDCRR0_MACLNFDR_MASK)

#define NETC_PORT_BPDCRR0_STAMVDDR_MASK          (0x80U)
#define NETC_PORT_BPDCRR0_STAMVDDR_SHIFT         (7U)
#define NETC_PORT_BPDCRR0_STAMVDDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR0_STAMVDDR_SHIFT)) & NETC_PORT_BPDCRR0_STAMVDDR_MASK)

#define NETC_PORT_BPDCRR0_MACFDDDR_MASK          (0x100U)
#define NETC_PORT_BPDCRR0_MACFDDDR_SHIFT         (8U)
#define NETC_PORT_BPDCRR0_MACFDDDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR0_MACFDDDR_SHIFT)) & NETC_PORT_BPDCRR0_MACFDDDR_MASK)

#define NETC_PORT_BPDCRR0_NODESTDR_MASK          (0x200U)
#define NETC_PORT_BPDCRR0_NODESTDR_SHIFT         (9U)
#define NETC_PORT_BPDCRR0_NODESTDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR0_NODESTDR_SHIFT)) & NETC_PORT_BPDCRR0_NODESTDR_MASK)

#define NETC_PORT_BPDCRR0_IPMFDR_MASK            (0x400U)
#define NETC_PORT_BPDCRR0_IPMFDR_SHIFT           (10U)
#define NETC_PORT_BPDCRR0_IPMFDR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR0_IPMFDR_SHIFT)) & NETC_PORT_BPDCRR0_IPMFDR_MASK)

#define NETC_PORT_BPDCRR0_UFMMDR_MASK            (0x800U)
#define NETC_PORT_BPDCRR0_UFMMDR_SHIFT           (11U)
#define NETC_PORT_BPDCRR0_UFMMDR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR0_UFMMDR_SHIFT)) & NETC_PORT_BPDCRR0_UFMMDR_MASK)

#define NETC_PORT_BPDCRR0_MISCDR_MASK            (0x1000U)
#define NETC_PORT_BPDCRR0_MISCDR_SHIFT           (12U)
#define NETC_PORT_BPDCRR0_MISCDR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR0_MISCDR_SHIFT)) & NETC_PORT_BPDCRR0_MISCDR_MASK)

#define NETC_PORT_BPDCRR0_STRMCTRLDR_MASK        (0x2000U)
#define NETC_PORT_BPDCRR0_STRMCTRLDR_SHIFT       (13U)
/*! STRMCTRLDR - Discard due to Storm Control Policer Discard Reason */
#define NETC_PORT_BPDCRR0_STRMCTRLDR(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR0_STRMCTRLDR_SHIFT)) & NETC_PORT_BPDCRR0_STRMCTRLDR_MASK)
/*! @} */

/*! @name BPDCRR1 - Bridge port discard count reason register 1 */
/*! @{ */

#define NETC_PORT_BPDCRR1_ENTRYID_MASK           (0x7FFFFFFU)
#define NETC_PORT_BPDCRR1_ENTRYID_SHIFT          (0U)
#define NETC_PORT_BPDCRR1_ENTRYID(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR1_ENTRYID_SHIFT)) & NETC_PORT_BPDCRR1_ENTRYID_MASK)

#define NETC_PORT_BPDCRR1_TT_MASK                (0xF0000000U)
#define NETC_PORT_BPDCRR1_TT_SHIFT               (28U)
#define NETC_PORT_BPDCRR1_TT(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPDCRR1_TT_SHIFT)) & NETC_PORT_BPDCRR1_TT_MASK)
/*! @} */

/*! @name BPMLFSR - Bridge port MAC learning failure status register */
/*! @{ */

#define NETC_PORT_BPMLFSR_BPMLLRFR_MASK          (0x1U)
#define NETC_PORT_BPMLFSR_BPMLLRFR_SHIFT         (0U)
/*! BPMLLRFR - Bridge Port MAC Learn Limit Reached Failure Reason */
#define NETC_PORT_BPMLFSR_BPMLLRFR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPMLFSR_BPMLLRFR_SHIFT)) & NETC_PORT_BPMLFSR_BPMLLRFR_MASK)

#define NETC_PORT_BPMLFSR_FFDBTRFR_MASK          (0x2U)
#define NETC_PORT_BPMLFSR_FFDBTRFR_SHIFT         (1U)
/*! FFDBTRFR - Full FDB Table Reached Failure Reason */
#define NETC_PORT_BPMLFSR_FFDBTRFR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPMLFSR_FFDBTRFR_SHIFT)) & NETC_PORT_BPMLFSR_FFDBTRFR_MASK)

#define NETC_PORT_BPMLFSR_HCCLRFR_MASK           (0x4U)
#define NETC_PORT_BPMLFSR_HCCLRFR_SHIFT          (2U)
/*! HCCLRFR - Hash Collision chain limit Reached Failure Reason */
#define NETC_PORT_BPMLFSR_HCCLRFR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PORT_BPMLFSR_HCCLRFR_SHIFT)) & NETC_PORT_BPMLFSR_HCCLRFR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NETC_PORT_Register_Masks */


/*!
 * @}
 */ /* end of group NETC_PORT_Peripheral_Access_Layer */


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


#endif  /* NETC_PORT_H_ */

