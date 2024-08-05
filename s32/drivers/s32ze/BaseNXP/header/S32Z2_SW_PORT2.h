/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SW_PORT2.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SW_PORT2
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
#if !defined(S32Z2_SW_PORT2_H_)  /* Check if memory map has not been already included */
#define S32Z2_SW_PORT2_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SW_PORT2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SW_PORT2_Peripheral_Access_Layer SW_PORT2 Peripheral Access Layer
 * @{
 */

/** SW_PORT2 - Size of Registers Arrays */
#define SW_PORT2_TCT_NUM_COUNT                    8u

/** SW_PORT2 - Register Layout Typedef */
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
  __I  uint32_t PQOR;                              /**< Port Queue Operational register, offset: 0x60 */
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
  uint8_t RESERVED_7[160];
  __I  uint32_t PRXDCR;                            /**< Port Rx discard count register, offset: 0x1C0 */
  uint8_t RESERVED_8[4];
  __IO uint32_t PRXDCRR0;                          /**< Port Rx discard count reason register 0, offset: 0x1C8 */
  __IO uint32_t PRXDCRR1;                          /**< Port Rx discard count reason register 1, offset: 0x1CC */
  uint8_t RESERVED_9[16];
  __I  uint32_t PTXDCR;                            /**< Port Tx discard count register, offset: 0x1E0 */
  uint8_t RESERVED_10[4];
  __IO uint32_t PTXDCRR0;                          /**< Port Tx discard count reason register 0, offset: 0x1E8 */
  __IO uint32_t PTXDCRR1;                          /**< Port Tx discard count reason register 1, offset: 0x1EC */
  uint8_t RESERVED_11[16];
  struct SW_PORT2_TCT_NUM {                        /* offset: 0x200, array step: 0x20 */
    __I  uint32_t PTGSTCSR;                          /**< Port time gate scheduling traffic class 0 status register..Port time gate scheduling traffic class 7 status register, array offset: 0x200, array step: 0x20 */
    uint8_t RESERVED_0[4];
    __IO uint32_t PTCTMSDUR;                         /**< Port traffic class 0 transmit maximum SDU register..Port traffic class 7 transmit maximum SDU register, array offset: 0x208, array step: 0x20 */
    uint8_t RESERVED_1[4];
    __IO uint32_t PTCCBSR0;                          /**< Port transmit traffic class 0 credit based shaper register 0..Port transmit traffic class 7 credit based shaper register 0, array offset: 0x210, array step: 0x20 */
    __IO uint32_t PTCCBSR1;                          /**< Port traffic class 0 credit based shaper register 1..Port traffic class 7 credit based shaper register 1, array offset: 0x214, array step: 0x20 */
    uint8_t RESERVED_2[8];
  } TCT_NUM[SW_PORT2_TCT_NUM_COUNT];
  uint8_t RESERVED_12[256];
  __IO uint32_t PBPMCR0;                           /**< Port buffer pool mapping configuration register 0, offset: 0x400 */
  __IO uint32_t PBPMCR1;                           /**< Port buffer pool mapping configuration register 1, offset: 0x404 */
  uint8_t RESERVED_13[48];
  __IO uint32_t PPCPDEIMR;                         /**< Port PCP DEI mapping register, offset: 0x438 */
  uint8_t RESERVED_14[4];
  __IO uint32_t PMCR;                              /**< Port mirror configuration register, offset: 0x440 */
  uint8_t RESERVED_15[20];
  __IO uint32_t PLANIDCR;                          /**< Port LANID configuration register, offset: 0x458 */
  uint8_t RESERVED_16[4];
  __IO uint32_t PISIDCR;                           /**< Port ingress stream identification configuration register, offset: 0x460 */
  __IO uint32_t PFMCR;                             /**< Port frame modification configuration register, offset: 0x464 */
  uint8_t RESERVED_17[8];
  __IO uint32_t PIPV2QMR0;                         /**< Port IPV to queue mapping register 0, offset: 0x470 */
  uint8_t RESERVED_18[60];
  __I  uint32_t PTCMINLR;                          /**< Port time capture minimum latency register, offset: 0x4B0 */
  __I  uint32_t PTCMAXLR;                          /**< Port time capture maximum latency register, offset: 0x4B4 */
  uint8_t RESERVED_19[72];
  __IO uint32_t BPCR;                              /**< Bridge port configuration register, offset: 0x500 */
  uint8_t RESERVED_20[12];
  __IO uint32_t BPDVR;                             /**< Bridge port default VLAN register, offset: 0x510 */
  uint8_t RESERVED_21[12];
  __IO uint32_t BPSTGSR;                           /**< Bridge port spanning tree group state register, offset: 0x520 */
  uint8_t RESERVED_22[4];
  __IO uint32_t BPSCR0;                            /**< Bridge port storm control register 0, offset: 0x528 */
  __IO uint32_t BPSCR1;                            /**< Bridge port storm control register 1, offset: 0x52C */
  __I  uint32_t BPOR;                              /**< Bridge port operational register, offset: 0x530 */
  uint8_t RESERVED_23[76];
  __I  uint32_t BPDCR;                             /**< Bridge port discard count register, offset: 0x580 */
  uint8_t RESERVED_24[4];
  __IO uint32_t BPDCRR0;                           /**< Bridge port discard count reason register 0, offset: 0x588 */
  __IO uint32_t BPDCRR1;                           /**< Bridge port discard count reason register 1, offset: 0x58C */
  __IO uint32_t BPMLFSR;                           /**< Bridge port MAC learning failure status register, offset: 0x590 */
} SW_PORT2_Type, *SW_PORT2_MemMapPtr;

/** Number of instances of the SW_PORT2 module. */
#define SW_PORT2_INSTANCE_COUNT                  (1u)

/* SW_PORT2 - Peripheral instance base addresses */
/** Peripheral NETC__SW0_PORT2 base address */
#define IP_NETC__SW0_PORT2_BASE                  (0x74A0C000u)
/** Peripheral NETC__SW0_PORT2 base pointer */
#define IP_NETC__SW0_PORT2                       ((SW_PORT2_Type *)IP_NETC__SW0_PORT2_BASE)
/** Array initializer of SW_PORT2 peripheral base addresses */
#define IP_SW_PORT2_BASE_ADDRS                   { IP_NETC__SW0_PORT2_BASE }
/** Array initializer of SW_PORT2 peripheral base pointers */
#define IP_SW_PORT2_BASE_PTRS                    { IP_NETC__SW0_PORT2 }

/* ----------------------------------------------------------------------------
   -- SW_PORT2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SW_PORT2_Register_Masks SW_PORT2 Register Masks
 * @{
 */

/*! @name PCAPR - Port capability register */
/*! @{ */

#define SW_PORT2_PCAPR_LINK_TYPE_MASK            (0x10U)
#define SW_PORT2_PCAPR_LINK_TYPE_SHIFT           (4U)
#define SW_PORT2_PCAPR_LINK_TYPE_WIDTH           (1U)
#define SW_PORT2_PCAPR_LINK_TYPE(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PCAPR_LINK_TYPE_SHIFT)) & SW_PORT2_PCAPR_LINK_TYPE_MASK)

#define SW_PORT2_PCAPR_NUM_TC_MASK               (0xF000U)
#define SW_PORT2_PCAPR_NUM_TC_SHIFT              (12U)
#define SW_PORT2_PCAPR_NUM_TC_WIDTH              (4U)
#define SW_PORT2_PCAPR_NUM_TC(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PCAPR_NUM_TC_SHIFT)) & SW_PORT2_PCAPR_NUM_TC_MASK)

#define SW_PORT2_PCAPR_NUM_Q_MASK                (0xF0000U)
#define SW_PORT2_PCAPR_NUM_Q_SHIFT               (16U)
#define SW_PORT2_PCAPR_NUM_Q_WIDTH               (4U)
#define SW_PORT2_PCAPR_NUM_Q(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PCAPR_NUM_Q_SHIFT)) & SW_PORT2_PCAPR_NUM_Q_MASK)

#define SW_PORT2_PCAPR_NUM_CG_MASK               (0xF000000U)
#define SW_PORT2_PCAPR_NUM_CG_SHIFT              (24U)
#define SW_PORT2_PCAPR_NUM_CG_WIDTH              (4U)
#define SW_PORT2_PCAPR_NUM_CG(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PCAPR_NUM_CG_SHIFT)) & SW_PORT2_PCAPR_NUM_CG_MASK)

#define SW_PORT2_PCAPR_TGS_MASK                  (0x10000000U)
#define SW_PORT2_PCAPR_TGS_SHIFT                 (28U)
#define SW_PORT2_PCAPR_TGS_WIDTH                 (1U)
#define SW_PORT2_PCAPR_TGS(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PCAPR_TGS_SHIFT)) & SW_PORT2_PCAPR_TGS_MASK)

#define SW_PORT2_PCAPR_CBS_MASK                  (0x20000000U)
#define SW_PORT2_PCAPR_CBS_SHIFT                 (29U)
#define SW_PORT2_PCAPR_CBS_WIDTH                 (1U)
#define SW_PORT2_PCAPR_CBS(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PCAPR_CBS_SHIFT)) & SW_PORT2_PCAPR_CBS_MASK)
/*! @} */

/*! @name PMCAPR - Port MAC capability register */
/*! @{ */

#define SW_PORT2_PMCAPR_MAC_VAR_MASK             (0x7U)
#define SW_PORT2_PMCAPR_MAC_VAR_SHIFT            (0U)
#define SW_PORT2_PMCAPR_MAC_VAR_WIDTH            (3U)
#define SW_PORT2_PMCAPR_MAC_VAR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PMCAPR_MAC_VAR_SHIFT)) & SW_PORT2_PMCAPR_MAC_VAR_MASK)

#define SW_PORT2_PMCAPR_EFPAD_MASK               (0x30U)
#define SW_PORT2_PMCAPR_EFPAD_SHIFT              (4U)
#define SW_PORT2_PMCAPR_EFPAD_WIDTH              (2U)
#define SW_PORT2_PMCAPR_EFPAD(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PMCAPR_EFPAD_SHIFT)) & SW_PORT2_PMCAPR_EFPAD_MASK)

#define SW_PORT2_PMCAPR_HD_MASK                  (0x100U)
#define SW_PORT2_PMCAPR_HD_SHIFT                 (8U)
#define SW_PORT2_PMCAPR_HD_WIDTH                 (1U)
#define SW_PORT2_PMCAPR_HD(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PMCAPR_HD_SHIFT)) & SW_PORT2_PMCAPR_HD_MASK)

#define SW_PORT2_PMCAPR_FP_MASK                  (0x600U)
#define SW_PORT2_PMCAPR_FP_SHIFT                 (9U)
#define SW_PORT2_PMCAPR_FP_WIDTH                 (2U)
#define SW_PORT2_PMCAPR_FP(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PMCAPR_FP_SHIFT)) & SW_PORT2_PMCAPR_FP_MASK)

#define SW_PORT2_PMCAPR_MII_PROT_MASK            (0xF000000U)
#define SW_PORT2_PMCAPR_MII_PROT_SHIFT           (24U)
#define SW_PORT2_PMCAPR_MII_PROT_WIDTH           (4U)
#define SW_PORT2_PMCAPR_MII_PROT(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PMCAPR_MII_PROT_SHIFT)) & SW_PORT2_PMCAPR_MII_PROT_MASK)
/*! @} */

/*! @name PIOCAPR - Port I/O capability register */
/*! @{ */

#define SW_PORT2_PIOCAPR_PCS_PROT_MASK           (0xFFFFU)
#define SW_PORT2_PIOCAPR_PCS_PROT_SHIFT          (0U)
#define SW_PORT2_PIOCAPR_PCS_PROT_WIDTH          (16U)
#define SW_PORT2_PIOCAPR_PCS_PROT(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIOCAPR_PCS_PROT_SHIFT)) & SW_PORT2_PIOCAPR_PCS_PROT_MASK)

#define SW_PORT2_PIOCAPR_IO_VAR_MASK             (0xF000000U)
#define SW_PORT2_PIOCAPR_IO_VAR_SHIFT            (24U)
#define SW_PORT2_PIOCAPR_IO_VAR_WIDTH            (4U)
#define SW_PORT2_PIOCAPR_IO_VAR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIOCAPR_IO_VAR_SHIFT)) & SW_PORT2_PIOCAPR_IO_VAR_MASK)

#define SW_PORT2_PIOCAPR_EMDIO_MASK              (0x10000000U)
#define SW_PORT2_PIOCAPR_EMDIO_SHIFT             (28U)
#define SW_PORT2_PIOCAPR_EMDIO_WIDTH             (1U)
#define SW_PORT2_PIOCAPR_EMDIO(x)                (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIOCAPR_EMDIO_SHIFT)) & SW_PORT2_PIOCAPR_EMDIO_MASK)

#define SW_PORT2_PIOCAPR_REVMII_RATE_MASK        (0x40000000U)
#define SW_PORT2_PIOCAPR_REVMII_RATE_SHIFT       (30U)
#define SW_PORT2_PIOCAPR_REVMII_RATE_WIDTH       (1U)
#define SW_PORT2_PIOCAPR_REVMII_RATE(x)          (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIOCAPR_REVMII_RATE_SHIFT)) & SW_PORT2_PIOCAPR_REVMII_RATE_MASK)

#define SW_PORT2_PIOCAPR_REVMII_MASK             (0x80000000U)
#define SW_PORT2_PIOCAPR_REVMII_SHIFT            (31U)
#define SW_PORT2_PIOCAPR_REVMII_WIDTH            (1U)
#define SW_PORT2_PIOCAPR_REVMII(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIOCAPR_REVMII_SHIFT)) & SW_PORT2_PIOCAPR_REVMII_MASK)
/*! @} */

/*! @name PCR - Port configuration register */
/*! @{ */

#define SW_PORT2_PCR_HDR_FMT_MASK                (0x1U)
#define SW_PORT2_PCR_HDR_FMT_SHIFT               (0U)
#define SW_PORT2_PCR_HDR_FMT_WIDTH               (1U)
#define SW_PORT2_PCR_HDR_FMT(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PCR_HDR_FMT_SHIFT)) & SW_PORT2_PCR_HDR_FMT_MASK)

#define SW_PORT2_PCR_L2DOSE_MASK                 (0x10U)
#define SW_PORT2_PCR_L2DOSE_SHIFT                (4U)
#define SW_PORT2_PCR_L2DOSE_WIDTH                (1U)
#define SW_PORT2_PCR_L2DOSE(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PCR_L2DOSE_SHIFT)) & SW_PORT2_PCR_L2DOSE_MASK)

#define SW_PORT2_PCR_TIMER_CS_MASK               (0x100U)
#define SW_PORT2_PCR_TIMER_CS_SHIFT              (8U)
#define SW_PORT2_PCR_TIMER_CS_WIDTH              (1U)
#define SW_PORT2_PCR_TIMER_CS(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PCR_TIMER_CS_SHIFT)) & SW_PORT2_PCR_TIMER_CS_MASK)

#define SW_PORT2_PCR_FCSEA_MASK                  (0x1000U)
#define SW_PORT2_PCR_FCSEA_SHIFT                 (12U)
#define SW_PORT2_PCR_FCSEA_WIDTH                 (1U)
#define SW_PORT2_PCR_FCSEA(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PCR_FCSEA_SHIFT)) & SW_PORT2_PCR_FCSEA_MASK)

#define SW_PORT2_PCR_PSPEED_MASK                 (0x3FFF0000U)
#define SW_PORT2_PCR_PSPEED_SHIFT                (16U)
#define SW_PORT2_PCR_PSPEED_WIDTH                (14U)
#define SW_PORT2_PCR_PSPEED(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PCR_PSPEED_SHIFT)) & SW_PORT2_PCR_PSPEED_MASK)
/*! @} */

/*! @name PMAR0 - Port MAC address register 0 */
/*! @{ */

#define SW_PORT2_PMAR0_PRIM_MAC_ADDR_MASK        (0xFFFFFFFFU)
#define SW_PORT2_PMAR0_PRIM_MAC_ADDR_SHIFT       (0U)
#define SW_PORT2_PMAR0_PRIM_MAC_ADDR_WIDTH       (32U)
#define SW_PORT2_PMAR0_PRIM_MAC_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PMAR0_PRIM_MAC_ADDR_SHIFT)) & SW_PORT2_PMAR0_PRIM_MAC_ADDR_MASK)
/*! @} */

/*! @name PMAR1 - Port MAC address register 1 */
/*! @{ */

#define SW_PORT2_PMAR1_PRIM_MAC_ADDR_MASK        (0xFFFFU)
#define SW_PORT2_PMAR1_PRIM_MAC_ADDR_SHIFT       (0U)
#define SW_PORT2_PMAR1_PRIM_MAC_ADDR_WIDTH       (16U)
#define SW_PORT2_PMAR1_PRIM_MAC_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PMAR1_PRIM_MAC_ADDR_SHIFT)) & SW_PORT2_PMAR1_PRIM_MAC_ADDR_MASK)
/*! @} */

/*! @name PTAR - Port TPID acceptance register */
/*! @{ */

#define SW_PORT2_PTAR_OVTPIDL_MASK               (0xFU)
#define SW_PORT2_PTAR_OVTPIDL_SHIFT              (0U)
#define SW_PORT2_PTAR_OVTPIDL_WIDTH              (4U)
#define SW_PORT2_PTAR_OVTPIDL(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTAR_OVTPIDL_SHIFT)) & SW_PORT2_PTAR_OVTPIDL_MASK)

#define SW_PORT2_PTAR_IVTPIDL_MASK               (0xF0U)
#define SW_PORT2_PTAR_IVTPIDL_SHIFT              (4U)
#define SW_PORT2_PTAR_IVTPIDL_WIDTH              (4U)
#define SW_PORT2_PTAR_IVTPIDL(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTAR_IVTPIDL_SHIFT)) & SW_PORT2_PTAR_IVTPIDL_MASK)
/*! @} */

/*! @name PQOSMR - Port QoS mode register */
/*! @{ */

#define SW_PORT2_PQOSMR_VS_MASK                  (0x1U)
#define SW_PORT2_PQOSMR_VS_SHIFT                 (0U)
#define SW_PORT2_PQOSMR_VS_WIDTH                 (1U)
#define SW_PORT2_PQOSMR_VS(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOSMR_VS_SHIFT)) & SW_PORT2_PQOSMR_VS_MASK)

#define SW_PORT2_PQOSMR_VE_MASK                  (0x2U)
#define SW_PORT2_PQOSMR_VE_SHIFT                 (1U)
#define SW_PORT2_PQOSMR_VE_WIDTH                 (1U)
#define SW_PORT2_PQOSMR_VE(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOSMR_VE_SHIFT)) & SW_PORT2_PQOSMR_VE_MASK)

#define SW_PORT2_PQOSMR_DDR_MASK                 (0xCU)
#define SW_PORT2_PQOSMR_DDR_SHIFT                (2U)
#define SW_PORT2_PQOSMR_DDR_WIDTH                (2U)
#define SW_PORT2_PQOSMR_DDR(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOSMR_DDR_SHIFT)) & SW_PORT2_PQOSMR_DDR_MASK)

#define SW_PORT2_PQOSMR_DIPV_MASK                (0x70U)
#define SW_PORT2_PQOSMR_DIPV_SHIFT               (4U)
#define SW_PORT2_PQOSMR_DIPV_WIDTH               (3U)
#define SW_PORT2_PQOSMR_DIPV(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOSMR_DIPV_SHIFT)) & SW_PORT2_PQOSMR_DIPV_MASK)

#define SW_PORT2_PQOSMR_VQMP_MASK                (0xF0000U)
#define SW_PORT2_PQOSMR_VQMP_SHIFT               (16U)
#define SW_PORT2_PQOSMR_VQMP_WIDTH               (4U)
#define SW_PORT2_PQOSMR_VQMP(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOSMR_VQMP_SHIFT)) & SW_PORT2_PQOSMR_VQMP_MASK)

#define SW_PORT2_PQOSMR_QVMP_MASK                (0xF00000U)
#define SW_PORT2_PQOSMR_QVMP_SHIFT               (20U)
#define SW_PORT2_PQOSMR_QVMP_WIDTH               (4U)
#define SW_PORT2_PQOSMR_QVMP(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOSMR_QVMP_SHIFT)) & SW_PORT2_PQOSMR_QVMP_MASK)
/*! @} */

/*! @name PQOR - Port Queue Operational register */
/*! @{ */

#define SW_PORT2_PQOR_Q0S_MASK                   (0x1U)
#define SW_PORT2_PQOR_Q0S_SHIFT                  (0U)
#define SW_PORT2_PQOR_Q0S_WIDTH                  (1U)
#define SW_PORT2_PQOR_Q0S(x)                     (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOR_Q0S_SHIFT)) & SW_PORT2_PQOR_Q0S_MASK)

#define SW_PORT2_PQOR_Q1S_MASK                   (0x2U)
#define SW_PORT2_PQOR_Q1S_SHIFT                  (1U)
#define SW_PORT2_PQOR_Q1S_WIDTH                  (1U)
#define SW_PORT2_PQOR_Q1S(x)                     (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOR_Q1S_SHIFT)) & SW_PORT2_PQOR_Q1S_MASK)

#define SW_PORT2_PQOR_Q2S_MASK                   (0x4U)
#define SW_PORT2_PQOR_Q2S_SHIFT                  (2U)
#define SW_PORT2_PQOR_Q2S_WIDTH                  (1U)
#define SW_PORT2_PQOR_Q2S(x)                     (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOR_Q2S_SHIFT)) & SW_PORT2_PQOR_Q2S_MASK)

#define SW_PORT2_PQOR_Q3S_MASK                   (0x8U)
#define SW_PORT2_PQOR_Q3S_SHIFT                  (3U)
#define SW_PORT2_PQOR_Q3S_WIDTH                  (1U)
#define SW_PORT2_PQOR_Q3S(x)                     (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOR_Q3S_SHIFT)) & SW_PORT2_PQOR_Q3S_MASK)

#define SW_PORT2_PQOR_Q4S_MASK                   (0x10U)
#define SW_PORT2_PQOR_Q4S_SHIFT                  (4U)
#define SW_PORT2_PQOR_Q4S_WIDTH                  (1U)
#define SW_PORT2_PQOR_Q4S(x)                     (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOR_Q4S_SHIFT)) & SW_PORT2_PQOR_Q4S_MASK)

#define SW_PORT2_PQOR_Q5S_MASK                   (0x20U)
#define SW_PORT2_PQOR_Q5S_SHIFT                  (5U)
#define SW_PORT2_PQOR_Q5S_WIDTH                  (1U)
#define SW_PORT2_PQOR_Q5S(x)                     (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOR_Q5S_SHIFT)) & SW_PORT2_PQOR_Q5S_MASK)

#define SW_PORT2_PQOR_Q6S_MASK                   (0x40U)
#define SW_PORT2_PQOR_Q6S_SHIFT                  (6U)
#define SW_PORT2_PQOR_Q6S_WIDTH                  (1U)
#define SW_PORT2_PQOR_Q6S(x)                     (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOR_Q6S_SHIFT)) & SW_PORT2_PQOR_Q6S_MASK)

#define SW_PORT2_PQOR_Q7S_MASK                   (0x80U)
#define SW_PORT2_PQOR_Q7S_SHIFT                  (7U)
#define SW_PORT2_PQOR_Q7S_WIDTH                  (1U)
#define SW_PORT2_PQOR_Q7S(x)                     (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PQOR_Q7S_SHIFT)) & SW_PORT2_PQOR_Q7S_MASK)
/*! @} */

/*! @name PPCR - Port parser configuration register */
/*! @{ */

#define SW_PORT2_PPCR_L1PFS_MASK                 (0x3EU)
#define SW_PORT2_PPCR_L1PFS_SHIFT                (1U)
#define SW_PORT2_PPCR_L1PFS_WIDTH                (5U)
#define SW_PORT2_PPCR_L1PFS(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCR_L1PFS_SHIFT)) & SW_PORT2_PPCR_L1PFS_MASK)

#define SW_PORT2_PPCR_L2PFS_MASK                 (0x3E00U)
#define SW_PORT2_PPCR_L2PFS_SHIFT                (9U)
#define SW_PORT2_PPCR_L2PFS_WIDTH                (5U)
#define SW_PORT2_PPCR_L2PFS(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCR_L2PFS_SHIFT)) & SW_PORT2_PPCR_L2PFS_MASK)

#define SW_PORT2_PPCR_L3HFP_MASK                 (0x10000U)
#define SW_PORT2_PPCR_L3HFP_SHIFT                (16U)
#define SW_PORT2_PPCR_L3HFP_WIDTH                (1U)
#define SW_PORT2_PPCR_L3HFP(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCR_L3HFP_SHIFT)) & SW_PORT2_PPCR_L3HFP_MASK)

#define SW_PORT2_PPCR_L3PFS_MASK                 (0x3E0000U)
#define SW_PORT2_PPCR_L3PFS_SHIFT                (17U)
#define SW_PORT2_PPCR_L3PFS_WIDTH                (5U)
#define SW_PORT2_PPCR_L3PFS(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCR_L3PFS_SHIFT)) & SW_PORT2_PPCR_L3PFS_MASK)

#define SW_PORT2_PPCR_L4HFP_MASK                 (0x1000000U)
#define SW_PORT2_PPCR_L4HFP_SHIFT                (24U)
#define SW_PORT2_PPCR_L4HFP_WIDTH                (1U)
#define SW_PORT2_PPCR_L4HFP(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCR_L4HFP_SHIFT)) & SW_PORT2_PPCR_L4HFP_MASK)

#define SW_PORT2_PPCR_L4PFS_MASK                 (0x3E000000U)
#define SW_PORT2_PPCR_L4PFS_SHIFT                (25U)
#define SW_PORT2_PPCR_L4PFS_WIDTH                (5U)
#define SW_PORT2_PPCR_L4PFS(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCR_L4PFS_SHIFT)) & SW_PORT2_PPCR_L4PFS_MASK)
/*! @} */

/*! @name PIPFCR - Port ingress port filter configuration register */
/*! @{ */

#define SW_PORT2_PIPFCR_EN_MASK                  (0x1U)
#define SW_PORT2_PIPFCR_EN_SHIFT                 (0U)
#define SW_PORT2_PIPFCR_EN_WIDTH                 (1U)
#define SW_PORT2_PIPFCR_EN(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIPFCR_EN_SHIFT)) & SW_PORT2_PIPFCR_EN_MASK)
/*! @} */

/*! @name PSGCR - Port stream gate configuration register */
/*! @{ */

#define SW_PORT2_PSGCR_PDELAY_MASK               (0xFFFFFFU)
#define SW_PORT2_PSGCR_PDELAY_SHIFT              (0U)
#define SW_PORT2_PSGCR_PDELAY_WIDTH              (24U)
#define SW_PORT2_PSGCR_PDELAY(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PSGCR_PDELAY_SHIFT)) & SW_PORT2_PSGCR_PDELAY_MASK)

#define SW_PORT2_PSGCR_OGC_MASK                  (0x80000000U)
#define SW_PORT2_PSGCR_OGC_SHIFT                 (31U)
#define SW_PORT2_PSGCR_OGC_WIDTH                 (1U)
#define SW_PORT2_PSGCR_OGC(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PSGCR_OGC_SHIFT)) & SW_PORT2_PSGCR_OGC_MASK)
/*! @} */

/*! @name POR - Port operational register */
/*! @{ */

#define SW_PORT2_POR_TXDIS_MASK                  (0x1U)
#define SW_PORT2_POR_TXDIS_SHIFT                 (0U)
#define SW_PORT2_POR_TXDIS_WIDTH                 (1U)
#define SW_PORT2_POR_TXDIS(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_POR_TXDIS_SHIFT)) & SW_PORT2_POR_TXDIS_MASK)

#define SW_PORT2_POR_RXDIS_MASK                  (0x2U)
#define SW_PORT2_POR_RXDIS_SHIFT                 (1U)
#define SW_PORT2_POR_RXDIS_WIDTH                 (1U)
#define SW_PORT2_POR_RXDIS(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_POR_RXDIS_SHIFT)) & SW_PORT2_POR_RXDIS_MASK)
/*! @} */

/*! @name PSR - Port status register */
/*! @{ */

#define SW_PORT2_PSR_TX_BUSY_MASK                (0x1U)
#define SW_PORT2_PSR_TX_BUSY_SHIFT               (0U)
#define SW_PORT2_PSR_TX_BUSY_WIDTH               (1U)
#define SW_PORT2_PSR_TX_BUSY(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PSR_TX_BUSY_SHIFT)) & SW_PORT2_PSR_TX_BUSY_MASK)

#define SW_PORT2_PSR_RX_BUSY_MASK                (0x2U)
#define SW_PORT2_PSR_RX_BUSY_SHIFT               (1U)
#define SW_PORT2_PSR_RX_BUSY_WIDTH               (1U)
#define SW_PORT2_PSR_RX_BUSY(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PSR_RX_BUSY_SHIFT)) & SW_PORT2_PSR_RX_BUSY_MASK)
/*! @} */

/*! @name PRXSDUOR - Port receive SDU overhead register */
/*! @{ */

#define SW_PORT2_PRXSDUOR_PPDU_BCO_MASK          (0x1FU)
#define SW_PORT2_PRXSDUOR_PPDU_BCO_SHIFT         (0U)
#define SW_PORT2_PRXSDUOR_PPDU_BCO_WIDTH         (5U)
#define SW_PORT2_PRXSDUOR_PPDU_BCO(x)            (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXSDUOR_PPDU_BCO_SHIFT)) & SW_PORT2_PRXSDUOR_PPDU_BCO_MASK)

#define SW_PORT2_PRXSDUOR_MACSEC_BCO_MASK        (0x1F00U)
#define SW_PORT2_PRXSDUOR_MACSEC_BCO_SHIFT       (8U)
#define SW_PORT2_PRXSDUOR_MACSEC_BCO_WIDTH       (5U)
#define SW_PORT2_PRXSDUOR_MACSEC_BCO(x)          (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXSDUOR_MACSEC_BCO_SHIFT)) & SW_PORT2_PRXSDUOR_MACSEC_BCO_MASK)
/*! @} */

/*! @name PTXSDUOR - Port transmit SDU overhead register */
/*! @{ */

#define SW_PORT2_PTXSDUOR_PPDU_BCO_MASK          (0x1FU)
#define SW_PORT2_PTXSDUOR_PPDU_BCO_SHIFT         (0U)
#define SW_PORT2_PTXSDUOR_PPDU_BCO_WIDTH         (5U)
#define SW_PORT2_PTXSDUOR_PPDU_BCO(x)            (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXSDUOR_PPDU_BCO_SHIFT)) & SW_PORT2_PTXSDUOR_PPDU_BCO_MASK)

#define SW_PORT2_PTXSDUOR_MACSEC_BCO_MASK        (0x1F00U)
#define SW_PORT2_PTXSDUOR_MACSEC_BCO_SHIFT       (8U)
#define SW_PORT2_PTXSDUOR_MACSEC_BCO_WIDTH       (5U)
#define SW_PORT2_PTXSDUOR_MACSEC_BCO(x)          (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXSDUOR_MACSEC_BCO_SHIFT)) & SW_PORT2_PTXSDUOR_MACSEC_BCO_MASK)
/*! @} */

/*! @name PTGSCR - Port time gate scheduling control register */
/*! @{ */

#define SW_PORT2_PTGSCR_TGE_MASK                 (0x80000000U)
#define SW_PORT2_PTGSCR_TGE_SHIFT                (31U)
#define SW_PORT2_PTGSCR_TGE_WIDTH                (1U)
#define SW_PORT2_PTGSCR_TGE(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTGSCR_TGE_SHIFT)) & SW_PORT2_PTGSCR_TGE_MASK)
/*! @} */

/*! @name PTGAGLSR - Port time gate scheduling admin gate list status register */
/*! @{ */

#define SW_PORT2_PTGAGLSR_TG_MASK                (0x1U)
#define SW_PORT2_PTGAGLSR_TG_SHIFT               (0U)
#define SW_PORT2_PTGAGLSR_TG_WIDTH               (1U)
#define SW_PORT2_PTGAGLSR_TG(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTGAGLSR_TG_SHIFT)) & SW_PORT2_PTGAGLSR_TG_MASK)

#define SW_PORT2_PTGAGLSR_CFG_PEND_MASK          (0x2U)
#define SW_PORT2_PTGAGLSR_CFG_PEND_SHIFT         (1U)
#define SW_PORT2_PTGAGLSR_CFG_PEND_WIDTH         (1U)
#define SW_PORT2_PTGAGLSR_CFG_PEND(x)            (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTGAGLSR_CFG_PEND_SHIFT)) & SW_PORT2_PTGAGLSR_CFG_PEND_MASK)
/*! @} */

/*! @name PTGAGLLR - Port time gate scheduling admin gate list length register */
/*! @{ */

#define SW_PORT2_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_MASK (0xFFFFU)
#define SW_PORT2_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_SHIFT (0U)
#define SW_PORT2_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_WIDTH (16U)
#define SW_PORT2_PTGAGLLR_ADMIN_GATE_LIST_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_SHIFT)) & SW_PORT2_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_MASK)
/*! @} */

/*! @name PTGOGLLR - Port time gating operational gate list length register */
/*! @{ */

#define SW_PORT2_PTGOGLLR_OPER_GATE_LIST_LENGTH_MASK (0xFFFFU)
#define SW_PORT2_PTGOGLLR_OPER_GATE_LIST_LENGTH_SHIFT (0U)
#define SW_PORT2_PTGOGLLR_OPER_GATE_LIST_LENGTH_WIDTH (16U)
#define SW_PORT2_PTGOGLLR_OPER_GATE_LIST_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTGOGLLR_OPER_GATE_LIST_LENGTH_SHIFT)) & SW_PORT2_PTGOGLLR_OPER_GATE_LIST_LENGTH_MASK)
/*! @} */

/*! @name PRXDCR - Port Rx discard count register */
/*! @{ */

#define SW_PORT2_PRXDCR_COUNT_MASK               (0xFFFFFFFFU)
#define SW_PORT2_PRXDCR_COUNT_SHIFT              (0U)
#define SW_PORT2_PRXDCR_COUNT_WIDTH              (32U)
#define SW_PORT2_PRXDCR_COUNT(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCR_COUNT_SHIFT)) & SW_PORT2_PRXDCR_COUNT_MASK)
/*! @} */

/*! @name PRXDCRR0 - Port Rx discard count reason register 0 */
/*! @{ */

#define SW_PORT2_PRXDCRR0_PCDR_MASK              (0x1U)
#define SW_PORT2_PRXDCRR0_PCDR_SHIFT             (0U)
#define SW_PORT2_PRXDCRR0_PCDR_WIDTH             (1U)
#define SW_PORT2_PRXDCRR0_PCDR(x)                (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_PCDR_SHIFT)) & SW_PORT2_PRXDCRR0_PCDR_MASK)

#define SW_PORT2_PRXDCRR0_SMREDR_MASK            (0x2U)
#define SW_PORT2_PRXDCRR0_SMREDR_SHIFT           (1U)
#define SW_PORT2_PRXDCRR0_SMREDR_WIDTH           (1U)
#define SW_PORT2_PRXDCRR0_SMREDR(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_SMREDR_SHIFT)) & SW_PORT2_PRXDCRR0_SMREDR_MASK)

#define SW_PORT2_PRXDCRR0_RXDISDR_MASK           (0x4U)
#define SW_PORT2_PRXDCRR0_RXDISDR_SHIFT          (2U)
#define SW_PORT2_PRXDCRR0_RXDISDR_WIDTH          (1U)
#define SW_PORT2_PRXDCRR0_RXDISDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_RXDISDR_SHIFT)) & SW_PORT2_PRXDCRR0_RXDISDR_MASK)

#define SW_PORT2_PRXDCRR0_IPFDR_MASK             (0x8U)
#define SW_PORT2_PRXDCRR0_IPFDR_SHIFT            (3U)
#define SW_PORT2_PRXDCRR0_IPFDR_WIDTH            (1U)
#define SW_PORT2_PRXDCRR0_IPFDR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_IPFDR_SHIFT)) & SW_PORT2_PRXDCRR0_IPFDR_MASK)

#define SW_PORT2_PRXDCRR0_RPDR_MASK              (0x10U)
#define SW_PORT2_PRXDCRR0_RPDR_SHIFT             (4U)
#define SW_PORT2_PRXDCRR0_RPDR_WIDTH             (1U)
#define SW_PORT2_PRXDCRR0_RPDR(x)                (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_RPDR_SHIFT)) & SW_PORT2_PRXDCRR0_RPDR_MASK)

#define SW_PORT2_PRXDCRR0_ISFDR_MASK             (0x20U)
#define SW_PORT2_PRXDCRR0_ISFDR_SHIFT            (5U)
#define SW_PORT2_PRXDCRR0_ISFDR_WIDTH            (1U)
#define SW_PORT2_PRXDCRR0_ISFDR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_ISFDR_SHIFT)) & SW_PORT2_PRXDCRR0_ISFDR_MASK)

#define SW_PORT2_PRXDCRR0_SGCDR_MASK             (0x40U)
#define SW_PORT2_PRXDCRR0_SGCDR_SHIFT            (6U)
#define SW_PORT2_PRXDCRR0_SGCDR_WIDTH            (1U)
#define SW_PORT2_PRXDCRR0_SGCDR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_SGCDR_SHIFT)) & SW_PORT2_PRXDCRR0_SGCDR_MASK)

#define SW_PORT2_PRXDCRR0_SGOEDR_MASK            (0x80U)
#define SW_PORT2_PRXDCRR0_SGOEDR_SHIFT           (7U)
#define SW_PORT2_PRXDCRR0_SGOEDR_WIDTH           (1U)
#define SW_PORT2_PRXDCRR0_SGOEDR(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_SGOEDR_SHIFT)) & SW_PORT2_PRXDCRR0_SGOEDR_MASK)

#define SW_PORT2_PRXDCRR0_MSDUEDR_MASK           (0x100U)
#define SW_PORT2_PRXDCRR0_MSDUEDR_SHIFT          (8U)
#define SW_PORT2_PRXDCRR0_MSDUEDR_WIDTH          (1U)
#define SW_PORT2_PRXDCRR0_MSDUEDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_MSDUEDR_SHIFT)) & SW_PORT2_PRXDCRR0_MSDUEDR_MASK)

#define SW_PORT2_PRXDCRR0_FMMEDR_MASK            (0x200U)
#define SW_PORT2_PRXDCRR0_FMMEDR_SHIFT           (9U)
#define SW_PORT2_PRXDCRR0_FMMEDR_WIDTH           (1U)
#define SW_PORT2_PRXDCRR0_FMMEDR(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_FMMEDR_SHIFT)) & SW_PORT2_PRXDCRR0_FMMEDR_MASK)

#define SW_PORT2_PRXDCRR0_CMDR_MASK              (0x400U)
#define SW_PORT2_PRXDCRR0_CMDR_SHIFT             (10U)
#define SW_PORT2_PRXDCRR0_CMDR_WIDTH             (1U)
#define SW_PORT2_PRXDCRR0_CMDR(x)                (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_CMDR_SHIFT)) & SW_PORT2_PRXDCRR0_CMDR_MASK)

#define SW_PORT2_PRXDCRR0_ITEDR_MASK             (0x800U)
#define SW_PORT2_PRXDCRR0_ITEDR_SHIFT            (11U)
#define SW_PORT2_PRXDCRR0_ITEDR_WIDTH            (1U)
#define SW_PORT2_PRXDCRR0_ITEDR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_ITEDR_SHIFT)) & SW_PORT2_PRXDCRR0_ITEDR_MASK)

#define SW_PORT2_PRXDCRR0_ECCEDR_MASK            (0x1000U)
#define SW_PORT2_PRXDCRR0_ECCEDR_SHIFT           (12U)
#define SW_PORT2_PRXDCRR0_ECCEDR_WIDTH           (1U)
#define SW_PORT2_PRXDCRR0_ECCEDR(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_ECCEDR_SHIFT)) & SW_PORT2_PRXDCRR0_ECCEDR_MASK)

#define SW_PORT2_PRXDCRR0_L2DOSDR_MASK           (0x4000U)
#define SW_PORT2_PRXDCRR0_L2DOSDR_SHIFT          (14U)
#define SW_PORT2_PRXDCRR0_L2DOSDR_WIDTH          (1U)
#define SW_PORT2_PRXDCRR0_L2DOSDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_L2DOSDR_SHIFT)) & SW_PORT2_PRXDCRR0_L2DOSDR_MASK)

#define SW_PORT2_PRXDCRR0_PEDR_MASK              (0x10000U)
#define SW_PORT2_PRXDCRR0_PEDR_SHIFT             (16U)
#define SW_PORT2_PRXDCRR0_PEDR_WIDTH             (1U)
#define SW_PORT2_PRXDCRR0_PEDR(x)                (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_PEDR_SHIFT)) & SW_PORT2_PRXDCRR0_PEDR_MASK)

#define SW_PORT2_PRXDCRR0_NODESTDR_MASK          (0x20000U)
#define SW_PORT2_PRXDCRR0_NODESTDR_SHIFT         (17U)
#define SW_PORT2_PRXDCRR0_NODESTDR_WIDTH         (1U)
#define SW_PORT2_PRXDCRR0_NODESTDR(x)            (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR0_NODESTDR_SHIFT)) & SW_PORT2_PRXDCRR0_NODESTDR_MASK)
/*! @} */

/*! @name PRXDCRR1 - Port Rx discard count reason register 1 */
/*! @{ */

#define SW_PORT2_PRXDCRR1_ENTRYID_MASK           (0xFFFFU)
#define SW_PORT2_PRXDCRR1_ENTRYID_SHIFT          (0U)
#define SW_PORT2_PRXDCRR1_ENTRYID_WIDTH          (16U)
#define SW_PORT2_PRXDCRR1_ENTRYID(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR1_ENTRYID_SHIFT)) & SW_PORT2_PRXDCRR1_ENTRYID_MASK)

#define SW_PORT2_PRXDCRR1_TT_MASK                (0xF0000000U)
#define SW_PORT2_PRXDCRR1_TT_SHIFT               (28U)
#define SW_PORT2_PRXDCRR1_TT_WIDTH               (4U)
#define SW_PORT2_PRXDCRR1_TT(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PRXDCRR1_TT_SHIFT)) & SW_PORT2_PRXDCRR1_TT_MASK)
/*! @} */

/*! @name PTXDCR - Port Tx discard count register */
/*! @{ */

#define SW_PORT2_PTXDCR_COUNT_MASK               (0xFFFFFFFFU)
#define SW_PORT2_PTXDCR_COUNT_SHIFT              (0U)
#define SW_PORT2_PTXDCR_COUNT_WIDTH              (32U)
#define SW_PORT2_PTXDCR_COUNT(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCR_COUNT_SHIFT)) & SW_PORT2_PTXDCR_COUNT_MASK)
/*! @} */

/*! @name PTXDCRR0 - Port Tx discard count reason register 0 */
/*! @{ */

#define SW_PORT2_PTXDCRR0_TXDISDR_MASK           (0x1U)
#define SW_PORT2_PTXDCRR0_TXDISDR_SHIFT          (0U)
#define SW_PORT2_PTXDCRR0_TXDISDR_WIDTH          (1U)
#define SW_PORT2_PTXDCRR0_TXDISDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_TXDISDR_SHIFT)) & SW_PORT2_PTXDCRR0_TXDISDR_MASK)

#define SW_PORT2_PTXDCRR0_ECCEDR_MASK            (0x2U)
#define SW_PORT2_PTXDCRR0_ECCEDR_SHIFT           (1U)
#define SW_PORT2_PTXDCRR0_ECCEDR_WIDTH           (1U)
#define SW_PORT2_PTXDCRR0_ECCEDR(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_ECCEDR_SHIFT)) & SW_PORT2_PTXDCRR0_ECCEDR_MASK)

#define SW_PORT2_PTXDCRR0_PEDR_MASK              (0x4U)
#define SW_PORT2_PTXDCRR0_PEDR_SHIFT             (2U)
#define SW_PORT2_PTXDCRR0_PEDR_WIDTH             (1U)
#define SW_PORT2_PTXDCRR0_PEDR(x)                (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_PEDR_SHIFT)) & SW_PORT2_PTXDCRR0_PEDR_MASK)

#define SW_PORT2_PTXDCRR0_TGSFTLDR_MASK          (0x10U)
#define SW_PORT2_PTXDCRR0_TGSFTLDR_SHIFT         (4U)
#define SW_PORT2_PTXDCRR0_TGSFTLDR_WIDTH         (1U)
#define SW_PORT2_PTXDCRR0_TGSFTLDR(x)            (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_TGSFTLDR_SHIFT)) & SW_PORT2_PTXDCRR0_TGSFTLDR_MASK)

#define SW_PORT2_PTXDCRR0_FMMDR_MASK             (0x20U)
#define SW_PORT2_PTXDCRR0_FMMDR_SHIFT            (5U)
#define SW_PORT2_PTXDCRR0_FMMDR_WIDTH            (1U)
#define SW_PORT2_PTXDCRR0_FMMDR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_FMMDR_SHIFT)) & SW_PORT2_PTXDCRR0_FMMDR_MASK)

#define SW_PORT2_PTXDCRR0_TXDISEDR_MASK          (0x40U)
#define SW_PORT2_PTXDCRR0_TXDISEDR_SHIFT         (6U)
#define SW_PORT2_PTXDCRR0_TXDISEDR_WIDTH         (1U)
#define SW_PORT2_PTXDCRR0_TXDISEDR(x)            (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_TXDISEDR_SHIFT)) & SW_PORT2_PTXDCRR0_TXDISEDR_MASK)

#define SW_PORT2_PTXDCRR0_MSDUEDR_MASK           (0x80U)
#define SW_PORT2_PTXDCRR0_MSDUEDR_SHIFT          (7U)
#define SW_PORT2_PTXDCRR0_MSDUEDR_WIDTH          (1U)
#define SW_PORT2_PTXDCRR0_MSDUEDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_MSDUEDR_SHIFT)) & SW_PORT2_PTXDCRR0_MSDUEDR_MASK)

#define SW_PORT2_PTXDCRR0_QCONGDR_MASK           (0x100U)
#define SW_PORT2_PTXDCRR0_QCONGDR_SHIFT          (8U)
#define SW_PORT2_PTXDCRR0_QCONGDR_WIDTH          (1U)
#define SW_PORT2_PTXDCRR0_QCONGDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_QCONGDR_SHIFT)) & SW_PORT2_PTXDCRR0_QCONGDR_MASK)

#define SW_PORT2_PTXDCRR0_ITEDR_MASK             (0x200U)
#define SW_PORT2_PTXDCRR0_ITEDR_SHIFT            (9U)
#define SW_PORT2_PTXDCRR0_ITEDR_WIDTH            (1U)
#define SW_PORT2_PTXDCRR0_ITEDR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_ITEDR_SHIFT)) & SW_PORT2_PTXDCRR0_ITEDR_MASK)

#define SW_PORT2_PTXDCRR0_INVEQDR_MASK           (0x400U)
#define SW_PORT2_PTXDCRR0_INVEQDR_SHIFT          (10U)
#define SW_PORT2_PTXDCRR0_INVEQDR_WIDTH          (1U)
#define SW_PORT2_PTXDCRR0_INVEQDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_INVEQDR_SHIFT)) & SW_PORT2_PTXDCRR0_INVEQDR_MASK)

#define SW_PORT2_PTXDCRR0_SQRTNSQDR_MASK         (0x800U)
#define SW_PORT2_PTXDCRR0_SQRTNSQDR_SHIFT        (11U)
#define SW_PORT2_PTXDCRR0_SQRTNSQDR_WIDTH        (1U)
#define SW_PORT2_PTXDCRR0_SQRTNSQDR(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_SQRTNSQDR_SHIFT)) & SW_PORT2_PTXDCRR0_SQRTNSQDR_MASK)

#define SW_PORT2_PTXDCRR0_SQRRDR_MASK            (0x2000U)
#define SW_PORT2_PTXDCRR0_SQRRDR_SHIFT           (13U)
#define SW_PORT2_PTXDCRR0_SQRRDR_WIDTH           (1U)
#define SW_PORT2_PTXDCRR0_SQRRDR(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_SQRRDR_SHIFT)) & SW_PORT2_PTXDCRR0_SQRRDR_MASK)

#define SW_PORT2_PTXDCRR0_SQRDDR_MASK            (0x4000U)
#define SW_PORT2_PTXDCRR0_SQRDDR_SHIFT           (14U)
#define SW_PORT2_PTXDCRR0_SQRDDR_WIDTH           (1U)
#define SW_PORT2_PTXDCRR0_SQRDDR(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_SQRDDR_SHIFT)) & SW_PORT2_PTXDCRR0_SQRDDR_MASK)

#define SW_PORT2_PTXDCRR0_SMREDR_MASK            (0x8000U)
#define SW_PORT2_PTXDCRR0_SMREDR_SHIFT           (15U)
#define SW_PORT2_PTXDCRR0_SMREDR_WIDTH           (1U)
#define SW_PORT2_PTXDCRR0_SMREDR(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR0_SMREDR_SHIFT)) & SW_PORT2_PTXDCRR0_SMREDR_MASK)
/*! @} */

/*! @name PTXDCRR1 - Port Tx discard count reason register 1 */
/*! @{ */

#define SW_PORT2_PTXDCRR1_ENTRYID_MASK           (0xFFFFU)
#define SW_PORT2_PTXDCRR1_ENTRYID_SHIFT          (0U)
#define SW_PORT2_PTXDCRR1_ENTRYID_WIDTH          (16U)
#define SW_PORT2_PTXDCRR1_ENTRYID(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR1_ENTRYID_SHIFT)) & SW_PORT2_PTXDCRR1_ENTRYID_MASK)

#define SW_PORT2_PTXDCRR1_TT_MASK                (0xF0000000U)
#define SW_PORT2_PTXDCRR1_TT_SHIFT               (28U)
#define SW_PORT2_PTXDCRR1_TT_WIDTH               (4U)
#define SW_PORT2_PTXDCRR1_TT(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTXDCRR1_TT_SHIFT)) & SW_PORT2_PTXDCRR1_TT_MASK)
/*! @} */

/*! @name PTGSTCSR - Port time gate scheduling traffic class 0 status register..Port time gate scheduling traffic class 7 status register */
/*! @{ */

#define SW_PORT2_PTGSTCSR_LH_STATE_MASK          (0x10000U)
#define SW_PORT2_PTGSTCSR_LH_STATE_SHIFT         (16U)
#define SW_PORT2_PTGSTCSR_LH_STATE_WIDTH         (1U)
#define SW_PORT2_PTGSTCSR_LH_STATE(x)            (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTGSTCSR_LH_STATE_SHIFT)) & SW_PORT2_PTGSTCSR_LH_STATE_MASK)
/*! @} */

/*! @name PTCTMSDUR - Port traffic class 0 transmit maximum SDU register..Port traffic class 7 transmit maximum SDU register */
/*! @{ */

#define SW_PORT2_PTCTMSDUR_MAXSDU_MASK           (0xFFFFU)
#define SW_PORT2_PTCTMSDUR_MAXSDU_SHIFT          (0U)
#define SW_PORT2_PTCTMSDUR_MAXSDU_WIDTH          (16U)
#define SW_PORT2_PTCTMSDUR_MAXSDU(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTCTMSDUR_MAXSDU_SHIFT)) & SW_PORT2_PTCTMSDUR_MAXSDU_MASK)

#define SW_PORT2_PTCTMSDUR_SDU_TYPE_MASK         (0x30000U)
#define SW_PORT2_PTCTMSDUR_SDU_TYPE_SHIFT        (16U)
#define SW_PORT2_PTCTMSDUR_SDU_TYPE_WIDTH        (2U)
#define SW_PORT2_PTCTMSDUR_SDU_TYPE(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTCTMSDUR_SDU_TYPE_SHIFT)) & SW_PORT2_PTCTMSDUR_SDU_TYPE_MASK)

#define SW_PORT2_PTCTMSDUR_SF_MAXSDU_DIS_MASK    (0x1000000U)
#define SW_PORT2_PTCTMSDUR_SF_MAXSDU_DIS_SHIFT   (24U)
#define SW_PORT2_PTCTMSDUR_SF_MAXSDU_DIS_WIDTH   (1U)
#define SW_PORT2_PTCTMSDUR_SF_MAXSDU_DIS(x)      (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTCTMSDUR_SF_MAXSDU_DIS_SHIFT)) & SW_PORT2_PTCTMSDUR_SF_MAXSDU_DIS_MASK)
/*! @} */

/*! @name PTCCBSR0 - Port transmit traffic class 0 credit based shaper register 0..Port transmit traffic class 7 credit based shaper register 0 */
/*! @{ */

#define SW_PORT2_PTCCBSR0_BW_MASK                (0x7FU)
#define SW_PORT2_PTCCBSR0_BW_SHIFT               (0U)
#define SW_PORT2_PTCCBSR0_BW_WIDTH               (7U)
#define SW_PORT2_PTCCBSR0_BW(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTCCBSR0_BW_SHIFT)) & SW_PORT2_PTCCBSR0_BW_MASK)

#define SW_PORT2_PTCCBSR0_CBSE_MASK              (0x80000000U)
#define SW_PORT2_PTCCBSR0_CBSE_SHIFT             (31U)
#define SW_PORT2_PTCCBSR0_CBSE_WIDTH             (1U)
#define SW_PORT2_PTCCBSR0_CBSE(x)                (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTCCBSR0_CBSE_SHIFT)) & SW_PORT2_PTCCBSR0_CBSE_MASK)
/*! @} */

/*! @name PTCCBSR1 - Port traffic class 0 credit based shaper register 1..Port traffic class 7 credit based shaper register 1 */
/*! @{ */

#define SW_PORT2_PTCCBSR1_HI_CREDIT_MASK         (0xFFFFFFFFU)
#define SW_PORT2_PTCCBSR1_HI_CREDIT_SHIFT        (0U)
#define SW_PORT2_PTCCBSR1_HI_CREDIT_WIDTH        (32U)
#define SW_PORT2_PTCCBSR1_HI_CREDIT(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTCCBSR1_HI_CREDIT_SHIFT)) & SW_PORT2_PTCCBSR1_HI_CREDIT_MASK)
/*! @} */

/*! @name PBPMCR0 - Port buffer pool mapping configuration register 0 */
/*! @{ */

#define SW_PORT2_PBPMCR0_IPV0_INDEX_MASK         (0xFFU)
#define SW_PORT2_PBPMCR0_IPV0_INDEX_SHIFT        (0U)
#define SW_PORT2_PBPMCR0_IPV0_INDEX_WIDTH        (8U)
#define SW_PORT2_PBPMCR0_IPV0_INDEX(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PBPMCR0_IPV0_INDEX_SHIFT)) & SW_PORT2_PBPMCR0_IPV0_INDEX_MASK)

#define SW_PORT2_PBPMCR0_IPV1_INDEX_MASK         (0xFF00U)
#define SW_PORT2_PBPMCR0_IPV1_INDEX_SHIFT        (8U)
#define SW_PORT2_PBPMCR0_IPV1_INDEX_WIDTH        (8U)
#define SW_PORT2_PBPMCR0_IPV1_INDEX(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PBPMCR0_IPV1_INDEX_SHIFT)) & SW_PORT2_PBPMCR0_IPV1_INDEX_MASK)

#define SW_PORT2_PBPMCR0_IPV2_INDEX_MASK         (0xFF0000U)
#define SW_PORT2_PBPMCR0_IPV2_INDEX_SHIFT        (16U)
#define SW_PORT2_PBPMCR0_IPV2_INDEX_WIDTH        (8U)
#define SW_PORT2_PBPMCR0_IPV2_INDEX(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PBPMCR0_IPV2_INDEX_SHIFT)) & SW_PORT2_PBPMCR0_IPV2_INDEX_MASK)

#define SW_PORT2_PBPMCR0_IPV3_INDEX_MASK         (0xFF000000U)
#define SW_PORT2_PBPMCR0_IPV3_INDEX_SHIFT        (24U)
#define SW_PORT2_PBPMCR0_IPV3_INDEX_WIDTH        (8U)
#define SW_PORT2_PBPMCR0_IPV3_INDEX(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PBPMCR0_IPV3_INDEX_SHIFT)) & SW_PORT2_PBPMCR0_IPV3_INDEX_MASK)
/*! @} */

/*! @name PBPMCR1 - Port buffer pool mapping configuration register 1 */
/*! @{ */

#define SW_PORT2_PBPMCR1_IPV4_INDEX_MASK         (0xFFU)
#define SW_PORT2_PBPMCR1_IPV4_INDEX_SHIFT        (0U)
#define SW_PORT2_PBPMCR1_IPV4_INDEX_WIDTH        (8U)
#define SW_PORT2_PBPMCR1_IPV4_INDEX(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PBPMCR1_IPV4_INDEX_SHIFT)) & SW_PORT2_PBPMCR1_IPV4_INDEX_MASK)

#define SW_PORT2_PBPMCR1_IPV5_INDEX_MASK         (0xFF00U)
#define SW_PORT2_PBPMCR1_IPV5_INDEX_SHIFT        (8U)
#define SW_PORT2_PBPMCR1_IPV5_INDEX_WIDTH        (8U)
#define SW_PORT2_PBPMCR1_IPV5_INDEX(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PBPMCR1_IPV5_INDEX_SHIFT)) & SW_PORT2_PBPMCR1_IPV5_INDEX_MASK)

#define SW_PORT2_PBPMCR1_IPV6_INDEX_MASK         (0xFF0000U)
#define SW_PORT2_PBPMCR1_IPV6_INDEX_SHIFT        (16U)
#define SW_PORT2_PBPMCR1_IPV6_INDEX_WIDTH        (8U)
#define SW_PORT2_PBPMCR1_IPV6_INDEX(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PBPMCR1_IPV6_INDEX_SHIFT)) & SW_PORT2_PBPMCR1_IPV6_INDEX_MASK)

#define SW_PORT2_PBPMCR1_IPV7_INDEX_MASK         (0xFF000000U)
#define SW_PORT2_PBPMCR1_IPV7_INDEX_SHIFT        (24U)
#define SW_PORT2_PBPMCR1_IPV7_INDEX_WIDTH        (8U)
#define SW_PORT2_PBPMCR1_IPV7_INDEX(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PBPMCR1_IPV7_INDEX_SHIFT)) & SW_PORT2_PBPMCR1_IPV7_INDEX_MASK)
/*! @} */

/*! @name PPCPDEIMR - Port PCP DEI mapping register */
/*! @{ */

#define SW_PORT2_PPCPDEIMR_IPCPMP_MASK           (0xFU)
#define SW_PORT2_PPCPDEIMR_IPCPMP_SHIFT          (0U)
#define SW_PORT2_PPCPDEIMR_IPCPMP_WIDTH          (4U)
#define SW_PORT2_PPCPDEIMR_IPCPMP(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCPDEIMR_IPCPMP_SHIFT)) & SW_PORT2_PPCPDEIMR_IPCPMP_MASK)

#define SW_PORT2_PPCPDEIMR_IPCPMPV_MASK          (0x80U)
#define SW_PORT2_PPCPDEIMR_IPCPMPV_SHIFT         (7U)
#define SW_PORT2_PPCPDEIMR_IPCPMPV_WIDTH         (1U)
#define SW_PORT2_PPCPDEIMR_IPCPMPV(x)            (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCPDEIMR_IPCPMPV_SHIFT)) & SW_PORT2_PPCPDEIMR_IPCPMPV_MASK)

#define SW_PORT2_PPCPDEIMR_EPCPMP_MASK           (0xF00U)
#define SW_PORT2_PPCPDEIMR_EPCPMP_SHIFT          (8U)
#define SW_PORT2_PPCPDEIMR_EPCPMP_WIDTH          (4U)
#define SW_PORT2_PPCPDEIMR_EPCPMP(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCPDEIMR_EPCPMP_SHIFT)) & SW_PORT2_PPCPDEIMR_EPCPMP_MASK)

#define SW_PORT2_PPCPDEIMR_EPCPMPV_MASK          (0x8000U)
#define SW_PORT2_PPCPDEIMR_EPCPMPV_SHIFT         (15U)
#define SW_PORT2_PPCPDEIMR_EPCPMPV_WIDTH         (1U)
#define SW_PORT2_PPCPDEIMR_EPCPMPV(x)            (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCPDEIMR_EPCPMPV_SHIFT)) & SW_PORT2_PPCPDEIMR_EPCPMPV_MASK)

#define SW_PORT2_PPCPDEIMR_DR0DEI_MASK           (0x10000U)
#define SW_PORT2_PPCPDEIMR_DR0DEI_SHIFT          (16U)
#define SW_PORT2_PPCPDEIMR_DR0DEI_WIDTH          (1U)
#define SW_PORT2_PPCPDEIMR_DR0DEI(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCPDEIMR_DR0DEI_SHIFT)) & SW_PORT2_PPCPDEIMR_DR0DEI_MASK)

#define SW_PORT2_PPCPDEIMR_DR1DEI_MASK           (0x20000U)
#define SW_PORT2_PPCPDEIMR_DR1DEI_SHIFT          (17U)
#define SW_PORT2_PPCPDEIMR_DR1DEI_WIDTH          (1U)
#define SW_PORT2_PPCPDEIMR_DR1DEI(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCPDEIMR_DR1DEI_SHIFT)) & SW_PORT2_PPCPDEIMR_DR1DEI_MASK)

#define SW_PORT2_PPCPDEIMR_DR2DEI_MASK           (0x40000U)
#define SW_PORT2_PPCPDEIMR_DR2DEI_SHIFT          (18U)
#define SW_PORT2_PPCPDEIMR_DR2DEI_WIDTH          (1U)
#define SW_PORT2_PPCPDEIMR_DR2DEI(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCPDEIMR_DR2DEI_SHIFT)) & SW_PORT2_PPCPDEIMR_DR2DEI_MASK)

#define SW_PORT2_PPCPDEIMR_DR3DEI_MASK           (0x80000U)
#define SW_PORT2_PPCPDEIMR_DR3DEI_SHIFT          (19U)
#define SW_PORT2_PPCPDEIMR_DR3DEI_WIDTH          (1U)
#define SW_PORT2_PPCPDEIMR_DR3DEI(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCPDEIMR_DR3DEI_SHIFT)) & SW_PORT2_PPCPDEIMR_DR3DEI_MASK)

#define SW_PORT2_PPCPDEIMR_DRME_MASK             (0x100000U)
#define SW_PORT2_PPCPDEIMR_DRME_SHIFT            (20U)
#define SW_PORT2_PPCPDEIMR_DRME_WIDTH            (1U)
#define SW_PORT2_PPCPDEIMR_DRME(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PPCPDEIMR_DRME_SHIFT)) & SW_PORT2_PPCPDEIMR_DRME_MASK)
/*! @} */

/*! @name PMCR - Port mirror configuration register */
/*! @{ */

#define SW_PORT2_PMCR_IMIRE_MASK                 (0x1U)
#define SW_PORT2_PMCR_IMIRE_SHIFT                (0U)
#define SW_PORT2_PMCR_IMIRE_WIDTH                (1U)
#define SW_PORT2_PMCR_IMIRE(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PMCR_IMIRE_SHIFT)) & SW_PORT2_PMCR_IMIRE_MASK)
/*! @} */

/*! @name PLANIDCR - Port LANID configuration register */
/*! @{ */

#define SW_PORT2_PLANIDCR_LANID_MASK             (0xFU)
#define SW_PORT2_PLANIDCR_LANID_SHIFT            (0U)
#define SW_PORT2_PLANIDCR_LANID_WIDTH            (4U)
#define SW_PORT2_PLANIDCR_LANID(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PLANIDCR_LANID_SHIFT)) & SW_PORT2_PLANIDCR_LANID_MASK)
/*! @} */

/*! @name PISIDCR - Port ingress stream identification configuration register */
/*! @{ */

#define SW_PORT2_PISIDCR_KCPAIR_MASK             (0x1U)
#define SW_PORT2_PISIDCR_KCPAIR_SHIFT            (0U)
#define SW_PORT2_PISIDCR_KCPAIR_WIDTH            (1U)
#define SW_PORT2_PISIDCR_KCPAIR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PISIDCR_KCPAIR_SHIFT)) & SW_PORT2_PISIDCR_KCPAIR_MASK)

#define SW_PORT2_PISIDCR_KC0EN_MASK              (0x2U)
#define SW_PORT2_PISIDCR_KC0EN_SHIFT             (1U)
#define SW_PORT2_PISIDCR_KC0EN_WIDTH             (1U)
#define SW_PORT2_PISIDCR_KC0EN(x)                (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PISIDCR_KC0EN_SHIFT)) & SW_PORT2_PISIDCR_KC0EN_MASK)

#define SW_PORT2_PISIDCR_KC1EN_MASK              (0x4U)
#define SW_PORT2_PISIDCR_KC1EN_SHIFT             (2U)
#define SW_PORT2_PISIDCR_KC1EN_WIDTH             (1U)
#define SW_PORT2_PISIDCR_KC1EN(x)                (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PISIDCR_KC1EN_SHIFT)) & SW_PORT2_PISIDCR_KC1EN_MASK)

#define SW_PORT2_PISIDCR_ISEID_MASK              (0xFFFF0000U)
#define SW_PORT2_PISIDCR_ISEID_SHIFT             (16U)
#define SW_PORT2_PISIDCR_ISEID_WIDTH             (16U)
#define SW_PORT2_PISIDCR_ISEID(x)                (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PISIDCR_ISEID_SHIFT)) & SW_PORT2_PISIDCR_ISEID_MASK)
/*! @} */

/*! @name PFMCR - Port frame modification configuration register */
/*! @{ */

#define SW_PORT2_PFMCR_FMMA_MASK                 (0x1U)
#define SW_PORT2_PFMCR_FMMA_SHIFT                (0U)
#define SW_PORT2_PFMCR_FMMA_WIDTH                (1U)
#define SW_PORT2_PFMCR_FMMA(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PFMCR_FMMA_SHIFT)) & SW_PORT2_PFMCR_FMMA_MASK)
/*! @} */

/*! @name PIPV2QMR0 - Port IPV to queue mapping register 0 */
/*! @{ */

#define SW_PORT2_PIPV2QMR0_IPV0_Q_MASK           (0xFU)
#define SW_PORT2_PIPV2QMR0_IPV0_Q_SHIFT          (0U)
#define SW_PORT2_PIPV2QMR0_IPV0_Q_WIDTH          (4U)
#define SW_PORT2_PIPV2QMR0_IPV0_Q(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIPV2QMR0_IPV0_Q_SHIFT)) & SW_PORT2_PIPV2QMR0_IPV0_Q_MASK)

#define SW_PORT2_PIPV2QMR0_IPV1_Q_MASK           (0xF0U)
#define SW_PORT2_PIPV2QMR0_IPV1_Q_SHIFT          (4U)
#define SW_PORT2_PIPV2QMR0_IPV1_Q_WIDTH          (4U)
#define SW_PORT2_PIPV2QMR0_IPV1_Q(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIPV2QMR0_IPV1_Q_SHIFT)) & SW_PORT2_PIPV2QMR0_IPV1_Q_MASK)

#define SW_PORT2_PIPV2QMR0_IPV2_Q_MASK           (0xF00U)
#define SW_PORT2_PIPV2QMR0_IPV2_Q_SHIFT          (8U)
#define SW_PORT2_PIPV2QMR0_IPV2_Q_WIDTH          (4U)
#define SW_PORT2_PIPV2QMR0_IPV2_Q(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIPV2QMR0_IPV2_Q_SHIFT)) & SW_PORT2_PIPV2QMR0_IPV2_Q_MASK)

#define SW_PORT2_PIPV2QMR0_IPV3_Q_MASK           (0xF000U)
#define SW_PORT2_PIPV2QMR0_IPV3_Q_SHIFT          (12U)
#define SW_PORT2_PIPV2QMR0_IPV3_Q_WIDTH          (4U)
#define SW_PORT2_PIPV2QMR0_IPV3_Q(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIPV2QMR0_IPV3_Q_SHIFT)) & SW_PORT2_PIPV2QMR0_IPV3_Q_MASK)

#define SW_PORT2_PIPV2QMR0_IPV4_Q_MASK           (0xF0000U)
#define SW_PORT2_PIPV2QMR0_IPV4_Q_SHIFT          (16U)
#define SW_PORT2_PIPV2QMR0_IPV4_Q_WIDTH          (4U)
#define SW_PORT2_PIPV2QMR0_IPV4_Q(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIPV2QMR0_IPV4_Q_SHIFT)) & SW_PORT2_PIPV2QMR0_IPV4_Q_MASK)

#define SW_PORT2_PIPV2QMR0_IPV5_Q_MASK           (0xF00000U)
#define SW_PORT2_PIPV2QMR0_IPV5_Q_SHIFT          (20U)
#define SW_PORT2_PIPV2QMR0_IPV5_Q_WIDTH          (4U)
#define SW_PORT2_PIPV2QMR0_IPV5_Q(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIPV2QMR0_IPV5_Q_SHIFT)) & SW_PORT2_PIPV2QMR0_IPV5_Q_MASK)

#define SW_PORT2_PIPV2QMR0_IPV6_Q_MASK           (0xF000000U)
#define SW_PORT2_PIPV2QMR0_IPV6_Q_SHIFT          (24U)
#define SW_PORT2_PIPV2QMR0_IPV6_Q_WIDTH          (4U)
#define SW_PORT2_PIPV2QMR0_IPV6_Q(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIPV2QMR0_IPV6_Q_SHIFT)) & SW_PORT2_PIPV2QMR0_IPV6_Q_MASK)

#define SW_PORT2_PIPV2QMR0_IPV7_Q_MASK           (0xF0000000U)
#define SW_PORT2_PIPV2QMR0_IPV7_Q_SHIFT          (28U)
#define SW_PORT2_PIPV2QMR0_IPV7_Q_WIDTH          (4U)
#define SW_PORT2_PIPV2QMR0_IPV7_Q(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PIPV2QMR0_IPV7_Q_SHIFT)) & SW_PORT2_PIPV2QMR0_IPV7_Q_MASK)
/*! @} */

/*! @name PTCMINLR - Port time capture minimum latency register */
/*! @{ */

#define SW_PORT2_PTCMINLR_LATENCY_MASK           (0x3FFFFFFFU)
#define SW_PORT2_PTCMINLR_LATENCY_SHIFT          (0U)
#define SW_PORT2_PTCMINLR_LATENCY_WIDTH          (30U)
#define SW_PORT2_PTCMINLR_LATENCY(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTCMINLR_LATENCY_SHIFT)) & SW_PORT2_PTCMINLR_LATENCY_MASK)

#define SW_PORT2_PTCMINLR_COUNT_MASK             (0xC0000000U)
#define SW_PORT2_PTCMINLR_COUNT_SHIFT            (30U)
#define SW_PORT2_PTCMINLR_COUNT_WIDTH            (2U)
#define SW_PORT2_PTCMINLR_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTCMINLR_COUNT_SHIFT)) & SW_PORT2_PTCMINLR_COUNT_MASK)
/*! @} */

/*! @name PTCMAXLR - Port time capture maximum latency register */
/*! @{ */

#define SW_PORT2_PTCMAXLR_LATENCY_MASK           (0x3FFFFFFFU)
#define SW_PORT2_PTCMAXLR_LATENCY_SHIFT          (0U)
#define SW_PORT2_PTCMAXLR_LATENCY_WIDTH          (30U)
#define SW_PORT2_PTCMAXLR_LATENCY(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_PTCMAXLR_LATENCY_SHIFT)) & SW_PORT2_PTCMAXLR_LATENCY_MASK)
/*! @} */

/*! @name BPCR - Bridge port configuration register */
/*! @{ */

#define SW_PORT2_BPCR_DYN_LIMIT_MASK             (0xFFFFU)
#define SW_PORT2_BPCR_DYN_LIMIT_SHIFT            (0U)
#define SW_PORT2_BPCR_DYN_LIMIT_WIDTH            (16U)
#define SW_PORT2_BPCR_DYN_LIMIT(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPCR_DYN_LIMIT_SHIFT)) & SW_PORT2_BPCR_DYN_LIMIT_MASK)

#define SW_PORT2_BPCR_UUCASTE_MASK               (0x1000000U)
#define SW_PORT2_BPCR_UUCASTE_SHIFT              (24U)
#define SW_PORT2_BPCR_UUCASTE_WIDTH              (1U)
#define SW_PORT2_BPCR_UUCASTE(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPCR_UUCASTE_SHIFT)) & SW_PORT2_BPCR_UUCASTE_MASK)

#define SW_PORT2_BPCR_UMCASTE_MASK               (0x2000000U)
#define SW_PORT2_BPCR_UMCASTE_SHIFT              (25U)
#define SW_PORT2_BPCR_UMCASTE_WIDTH              (1U)
#define SW_PORT2_BPCR_UMCASTE(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPCR_UMCASTE_SHIFT)) & SW_PORT2_BPCR_UMCASTE_MASK)

#define SW_PORT2_BPCR_MCASTE_MASK                (0x4000000U)
#define SW_PORT2_BPCR_MCASTE_SHIFT               (26U)
#define SW_PORT2_BPCR_MCASTE_WIDTH               (1U)
#define SW_PORT2_BPCR_MCASTE(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPCR_MCASTE_SHIFT)) & SW_PORT2_BPCR_MCASTE_MASK)

#define SW_PORT2_BPCR_BCASTE_MASK                (0x8000000U)
#define SW_PORT2_BPCR_BCASTE_SHIFT               (27U)
#define SW_PORT2_BPCR_BCASTE_WIDTH               (1U)
#define SW_PORT2_BPCR_BCASTE(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPCR_BCASTE_SHIFT)) & SW_PORT2_BPCR_BCASTE_MASK)

#define SW_PORT2_BPCR_STAMVD_MASK                (0x10000000U)
#define SW_PORT2_BPCR_STAMVD_SHIFT               (28U)
#define SW_PORT2_BPCR_STAMVD_WIDTH               (1U)
#define SW_PORT2_BPCR_STAMVD(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPCR_STAMVD_SHIFT)) & SW_PORT2_BPCR_STAMVD_MASK)

#define SW_PORT2_BPCR_SRCPRND_MASK               (0x20000000U)
#define SW_PORT2_BPCR_SRCPRND_SHIFT              (29U)
#define SW_PORT2_BPCR_SRCPRND_WIDTH              (1U)
#define SW_PORT2_BPCR_SRCPRND(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPCR_SRCPRND_SHIFT)) & SW_PORT2_BPCR_SRCPRND_MASK)
/*! @} */

/*! @name BPDVR - Bridge port default VLAN register */
/*! @{ */

#define SW_PORT2_BPDVR_VID_MASK                  (0xFFFU)
#define SW_PORT2_BPDVR_VID_SHIFT                 (0U)
#define SW_PORT2_BPDVR_VID_WIDTH                 (12U)
#define SW_PORT2_BPDVR_VID(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDVR_VID_SHIFT)) & SW_PORT2_BPDVR_VID_MASK)

#define SW_PORT2_BPDVR_DEI_MASK                  (0x1000U)
#define SW_PORT2_BPDVR_DEI_SHIFT                 (12U)
#define SW_PORT2_BPDVR_DEI_WIDTH                 (1U)
#define SW_PORT2_BPDVR_DEI(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDVR_DEI_SHIFT)) & SW_PORT2_BPDVR_DEI_MASK)

#define SW_PORT2_BPDVR_PCP_MASK                  (0xE000U)
#define SW_PORT2_BPDVR_PCP_SHIFT                 (13U)
#define SW_PORT2_BPDVR_PCP_WIDTH                 (3U)
#define SW_PORT2_BPDVR_PCP(x)                    (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDVR_PCP_SHIFT)) & SW_PORT2_BPDVR_PCP_MASK)

#define SW_PORT2_BPDVR_TPID_MASK                 (0x10000U)
#define SW_PORT2_BPDVR_TPID_SHIFT                (16U)
#define SW_PORT2_BPDVR_TPID_WIDTH                (1U)
#define SW_PORT2_BPDVR_TPID(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDVR_TPID_SHIFT)) & SW_PORT2_BPDVR_TPID_MASK)

#define SW_PORT2_BPDVR_RXTAGA_MASK               (0xF00000U)
#define SW_PORT2_BPDVR_RXTAGA_SHIFT              (20U)
#define SW_PORT2_BPDVR_RXTAGA_WIDTH              (4U)
#define SW_PORT2_BPDVR_RXTAGA(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDVR_RXTAGA_SHIFT)) & SW_PORT2_BPDVR_RXTAGA_MASK)

#define SW_PORT2_BPDVR_RXVAM_MASK                (0x1000000U)
#define SW_PORT2_BPDVR_RXVAM_SHIFT               (24U)
#define SW_PORT2_BPDVR_RXVAM_WIDTH               (1U)
#define SW_PORT2_BPDVR_RXVAM(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDVR_RXVAM_SHIFT)) & SW_PORT2_BPDVR_RXVAM_MASK)

#define SW_PORT2_BPDVR_TXTAGA_MASK               (0x6000000U)
#define SW_PORT2_BPDVR_TXTAGA_SHIFT              (25U)
#define SW_PORT2_BPDVR_TXTAGA_WIDTH              (2U)
#define SW_PORT2_BPDVR_TXTAGA(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDVR_TXTAGA_SHIFT)) & SW_PORT2_BPDVR_TXTAGA_MASK)
/*! @} */

/*! @name BPSTGSR - Bridge port spanning tree group state register */
/*! @{ */

#define SW_PORT2_BPSTGSR_STG_STATE0_MASK         (0x3U)
#define SW_PORT2_BPSTGSR_STG_STATE0_SHIFT        (0U)
#define SW_PORT2_BPSTGSR_STG_STATE0_WIDTH        (2U)
#define SW_PORT2_BPSTGSR_STG_STATE0(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE0_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE0_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE1_MASK         (0xCU)
#define SW_PORT2_BPSTGSR_STG_STATE1_SHIFT        (2U)
#define SW_PORT2_BPSTGSR_STG_STATE1_WIDTH        (2U)
#define SW_PORT2_BPSTGSR_STG_STATE1(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE1_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE1_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE2_MASK         (0x30U)
#define SW_PORT2_BPSTGSR_STG_STATE2_SHIFT        (4U)
#define SW_PORT2_BPSTGSR_STG_STATE2_WIDTH        (2U)
#define SW_PORT2_BPSTGSR_STG_STATE2(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE2_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE2_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE3_MASK         (0xC0U)
#define SW_PORT2_BPSTGSR_STG_STATE3_SHIFT        (6U)
#define SW_PORT2_BPSTGSR_STG_STATE3_WIDTH        (2U)
#define SW_PORT2_BPSTGSR_STG_STATE3(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE3_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE3_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE4_MASK         (0x300U)
#define SW_PORT2_BPSTGSR_STG_STATE4_SHIFT        (8U)
#define SW_PORT2_BPSTGSR_STG_STATE4_WIDTH        (2U)
#define SW_PORT2_BPSTGSR_STG_STATE4(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE4_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE4_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE5_MASK         (0xC00U)
#define SW_PORT2_BPSTGSR_STG_STATE5_SHIFT        (10U)
#define SW_PORT2_BPSTGSR_STG_STATE5_WIDTH        (2U)
#define SW_PORT2_BPSTGSR_STG_STATE5(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE5_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE5_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE6_MASK         (0x3000U)
#define SW_PORT2_BPSTGSR_STG_STATE6_SHIFT        (12U)
#define SW_PORT2_BPSTGSR_STG_STATE6_WIDTH        (2U)
#define SW_PORT2_BPSTGSR_STG_STATE6(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE6_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE6_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE7_MASK         (0xC000U)
#define SW_PORT2_BPSTGSR_STG_STATE7_SHIFT        (14U)
#define SW_PORT2_BPSTGSR_STG_STATE7_WIDTH        (2U)
#define SW_PORT2_BPSTGSR_STG_STATE7(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE7_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE7_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE8_MASK         (0x30000U)
#define SW_PORT2_BPSTGSR_STG_STATE8_SHIFT        (16U)
#define SW_PORT2_BPSTGSR_STG_STATE8_WIDTH        (2U)
#define SW_PORT2_BPSTGSR_STG_STATE8(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE8_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE8_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE9_MASK         (0xC0000U)
#define SW_PORT2_BPSTGSR_STG_STATE9_SHIFT        (18U)
#define SW_PORT2_BPSTGSR_STG_STATE9_WIDTH        (2U)
#define SW_PORT2_BPSTGSR_STG_STATE9(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE9_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE9_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE10_MASK        (0x300000U)
#define SW_PORT2_BPSTGSR_STG_STATE10_SHIFT       (20U)
#define SW_PORT2_BPSTGSR_STG_STATE10_WIDTH       (2U)
#define SW_PORT2_BPSTGSR_STG_STATE10(x)          (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE10_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE10_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE11_MASK        (0xC00000U)
#define SW_PORT2_BPSTGSR_STG_STATE11_SHIFT       (22U)
#define SW_PORT2_BPSTGSR_STG_STATE11_WIDTH       (2U)
#define SW_PORT2_BPSTGSR_STG_STATE11(x)          (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE11_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE11_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE12_MASK        (0x3000000U)
#define SW_PORT2_BPSTGSR_STG_STATE12_SHIFT       (24U)
#define SW_PORT2_BPSTGSR_STG_STATE12_WIDTH       (2U)
#define SW_PORT2_BPSTGSR_STG_STATE12(x)          (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE12_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE12_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE13_MASK        (0xC000000U)
#define SW_PORT2_BPSTGSR_STG_STATE13_SHIFT       (26U)
#define SW_PORT2_BPSTGSR_STG_STATE13_WIDTH       (2U)
#define SW_PORT2_BPSTGSR_STG_STATE13(x)          (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE13_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE13_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE14_MASK        (0x30000000U)
#define SW_PORT2_BPSTGSR_STG_STATE14_SHIFT       (28U)
#define SW_PORT2_BPSTGSR_STG_STATE14_WIDTH       (2U)
#define SW_PORT2_BPSTGSR_STG_STATE14(x)          (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE14_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE14_MASK)

#define SW_PORT2_BPSTGSR_STG_STATE15_MASK        (0xC0000000U)
#define SW_PORT2_BPSTGSR_STG_STATE15_SHIFT       (30U)
#define SW_PORT2_BPSTGSR_STG_STATE15_WIDTH       (2U)
#define SW_PORT2_BPSTGSR_STG_STATE15(x)          (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSTGSR_STG_STATE15_SHIFT)) & SW_PORT2_BPSTGSR_STG_STATE15_MASK)
/*! @} */

/*! @name BPSCR0 - Bridge port storm control register 0 */
/*! @{ */

#define SW_PORT2_BPSCR0_UUCASTRPEID_MASK         (0xFFFU)
#define SW_PORT2_BPSCR0_UUCASTRPEID_SHIFT        (0U)
#define SW_PORT2_BPSCR0_UUCASTRPEID_WIDTH        (12U)
#define SW_PORT2_BPSCR0_UUCASTRPEID(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSCR0_UUCASTRPEID_SHIFT)) & SW_PORT2_BPSCR0_UUCASTRPEID_MASK)

#define SW_PORT2_BPSCR0_BCASTRPEID_MASK          (0xFFF0000U)
#define SW_PORT2_BPSCR0_BCASTRPEID_SHIFT         (16U)
#define SW_PORT2_BPSCR0_BCASTRPEID_WIDTH         (12U)
#define SW_PORT2_BPSCR0_BCASTRPEID(x)            (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSCR0_BCASTRPEID_SHIFT)) & SW_PORT2_BPSCR0_BCASTRPEID_MASK)
/*! @} */

/*! @name BPSCR1 - Bridge port storm control register 1 */
/*! @{ */

#define SW_PORT2_BPSCR1_MCASTRPEID_MASK          (0xFFFU)
#define SW_PORT2_BPSCR1_MCASTRPEID_SHIFT         (0U)
#define SW_PORT2_BPSCR1_MCASTRPEID_WIDTH         (12U)
#define SW_PORT2_BPSCR1_MCASTRPEID(x)            (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSCR1_MCASTRPEID_SHIFT)) & SW_PORT2_BPSCR1_MCASTRPEID_MASK)

#define SW_PORT2_BPSCR1_UMCASTRPEID_MASK         (0xFFF0000U)
#define SW_PORT2_BPSCR1_UMCASTRPEID_SHIFT        (16U)
#define SW_PORT2_BPSCR1_UMCASTRPEID_WIDTH        (12U)
#define SW_PORT2_BPSCR1_UMCASTRPEID(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPSCR1_UMCASTRPEID_SHIFT)) & SW_PORT2_BPSCR1_UMCASTRPEID_MASK)
/*! @} */

/*! @name BPOR - Bridge port operational register */
/*! @{ */

#define SW_PORT2_BPOR_NUM_DYN_MASK               (0xFFFFU)
#define SW_PORT2_BPOR_NUM_DYN_SHIFT              (0U)
#define SW_PORT2_BPOR_NUM_DYN_WIDTH              (16U)
#define SW_PORT2_BPOR_NUM_DYN(x)                 (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPOR_NUM_DYN_SHIFT)) & SW_PORT2_BPOR_NUM_DYN_MASK)
/*! @} */

/*! @name BPDCR - Bridge port discard count register */
/*! @{ */

#define SW_PORT2_BPDCR_COUNT_MASK                (0xFFFFFFFFU)
#define SW_PORT2_BPDCR_COUNT_SHIFT               (0U)
#define SW_PORT2_BPDCR_COUNT_WIDTH               (32U)
#define SW_PORT2_BPDCR_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCR_COUNT_SHIFT)) & SW_PORT2_BPDCR_COUNT_MASK)
/*! @} */

/*! @name BPDCRR0 - Bridge port discard count reason register 0 */
/*! @{ */

#define SW_PORT2_BPDCRR0_BPACDR_MASK             (0x1U)
#define SW_PORT2_BPDCRR0_BPACDR_SHIFT            (0U)
#define SW_PORT2_BPDCRR0_BPACDR_WIDTH            (1U)
#define SW_PORT2_BPDCRR0_BPACDR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR0_BPACDR_SHIFT)) & SW_PORT2_BPDCRR0_BPACDR_MASK)

#define SW_PORT2_BPDCRR0_ISTGSDR_MASK            (0x2U)
#define SW_PORT2_BPDCRR0_ISTGSDR_SHIFT           (1U)
#define SW_PORT2_BPDCRR0_ISTGSDR_WIDTH           (1U)
#define SW_PORT2_BPDCRR0_ISTGSDR(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR0_ISTGSDR_SHIFT)) & SW_PORT2_BPDCRR0_ISTGSDR_MASK)

#define SW_PORT2_BPDCRR0_BPVFLTDR_MASK           (0x4U)
#define SW_PORT2_BPDCRR0_BPVFLTDR_SHIFT          (2U)
#define SW_PORT2_BPDCRR0_BPVFLTDR_WIDTH          (1U)
#define SW_PORT2_BPDCRR0_BPVFLTDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR0_BPVFLTDR_SHIFT)) & SW_PORT2_BPDCRR0_BPVFLTDR_MASK)

#define SW_PORT2_BPDCRR0_MACLNFDR_MASK           (0x8U)
#define SW_PORT2_BPDCRR0_MACLNFDR_SHIFT          (3U)
#define SW_PORT2_BPDCRR0_MACLNFDR_WIDTH          (1U)
#define SW_PORT2_BPDCRR0_MACLNFDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR0_MACLNFDR_SHIFT)) & SW_PORT2_BPDCRR0_MACLNFDR_MASK)

#define SW_PORT2_BPDCRR0_STAMVDDR_MASK           (0x80U)
#define SW_PORT2_BPDCRR0_STAMVDDR_SHIFT          (7U)
#define SW_PORT2_BPDCRR0_STAMVDDR_WIDTH          (1U)
#define SW_PORT2_BPDCRR0_STAMVDDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR0_STAMVDDR_SHIFT)) & SW_PORT2_BPDCRR0_STAMVDDR_MASK)

#define SW_PORT2_BPDCRR0_MACFDDDR_MASK           (0x100U)
#define SW_PORT2_BPDCRR0_MACFDDDR_SHIFT          (8U)
#define SW_PORT2_BPDCRR0_MACFDDDR_WIDTH          (1U)
#define SW_PORT2_BPDCRR0_MACFDDDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR0_MACFDDDR_SHIFT)) & SW_PORT2_BPDCRR0_MACFDDDR_MASK)

#define SW_PORT2_BPDCRR0_NODESTDR_MASK           (0x200U)
#define SW_PORT2_BPDCRR0_NODESTDR_SHIFT          (9U)
#define SW_PORT2_BPDCRR0_NODESTDR_WIDTH          (1U)
#define SW_PORT2_BPDCRR0_NODESTDR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR0_NODESTDR_SHIFT)) & SW_PORT2_BPDCRR0_NODESTDR_MASK)

#define SW_PORT2_BPDCRR0_IPMFDR_MASK             (0x400U)
#define SW_PORT2_BPDCRR0_IPMFDR_SHIFT            (10U)
#define SW_PORT2_BPDCRR0_IPMFDR_WIDTH            (1U)
#define SW_PORT2_BPDCRR0_IPMFDR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR0_IPMFDR_SHIFT)) & SW_PORT2_BPDCRR0_IPMFDR_MASK)

#define SW_PORT2_BPDCRR0_UFMMDR_MASK             (0x800U)
#define SW_PORT2_BPDCRR0_UFMMDR_SHIFT            (11U)
#define SW_PORT2_BPDCRR0_UFMMDR_WIDTH            (1U)
#define SW_PORT2_BPDCRR0_UFMMDR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR0_UFMMDR_SHIFT)) & SW_PORT2_BPDCRR0_UFMMDR_MASK)

#define SW_PORT2_BPDCRR0_MISCDR_MASK             (0x1000U)
#define SW_PORT2_BPDCRR0_MISCDR_SHIFT            (12U)
#define SW_PORT2_BPDCRR0_MISCDR_WIDTH            (1U)
#define SW_PORT2_BPDCRR0_MISCDR(x)               (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR0_MISCDR_SHIFT)) & SW_PORT2_BPDCRR0_MISCDR_MASK)

#define SW_PORT2_BPDCRR0_STRMCTRLDR_MASK         (0x2000U)
#define SW_PORT2_BPDCRR0_STRMCTRLDR_SHIFT        (13U)
#define SW_PORT2_BPDCRR0_STRMCTRLDR_WIDTH        (1U)
#define SW_PORT2_BPDCRR0_STRMCTRLDR(x)           (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR0_STRMCTRLDR_SHIFT)) & SW_PORT2_BPDCRR0_STRMCTRLDR_MASK)
/*! @} */

/*! @name BPDCRR1 - Bridge port discard count reason register 1 */
/*! @{ */

#define SW_PORT2_BPDCRR1_ENTRYID_MASK            (0x7FFFFFFU)
#define SW_PORT2_BPDCRR1_ENTRYID_SHIFT           (0U)
#define SW_PORT2_BPDCRR1_ENTRYID_WIDTH           (27U)
#define SW_PORT2_BPDCRR1_ENTRYID(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR1_ENTRYID_SHIFT)) & SW_PORT2_BPDCRR1_ENTRYID_MASK)

#define SW_PORT2_BPDCRR1_TT_MASK                 (0xF0000000U)
#define SW_PORT2_BPDCRR1_TT_SHIFT                (28U)
#define SW_PORT2_BPDCRR1_TT_WIDTH                (4U)
#define SW_PORT2_BPDCRR1_TT(x)                   (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPDCRR1_TT_SHIFT)) & SW_PORT2_BPDCRR1_TT_MASK)
/*! @} */

/*! @name BPMLFSR - Bridge port MAC learning failure status register */
/*! @{ */

#define SW_PORT2_BPMLFSR_BPMLLRFR_MASK           (0x1U)
#define SW_PORT2_BPMLFSR_BPMLLRFR_SHIFT          (0U)
#define SW_PORT2_BPMLFSR_BPMLLRFR_WIDTH          (1U)
#define SW_PORT2_BPMLFSR_BPMLLRFR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPMLFSR_BPMLLRFR_SHIFT)) & SW_PORT2_BPMLFSR_BPMLLRFR_MASK)

#define SW_PORT2_BPMLFSR_FFDBTRFR_MASK           (0x2U)
#define SW_PORT2_BPMLFSR_FFDBTRFR_SHIFT          (1U)
#define SW_PORT2_BPMLFSR_FFDBTRFR_WIDTH          (1U)
#define SW_PORT2_BPMLFSR_FFDBTRFR(x)             (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPMLFSR_FFDBTRFR_SHIFT)) & SW_PORT2_BPMLFSR_FFDBTRFR_MASK)

#define SW_PORT2_BPMLFSR_HCCLRFR_MASK            (0x4U)
#define SW_PORT2_BPMLFSR_HCCLRFR_SHIFT           (2U)
#define SW_PORT2_BPMLFSR_HCCLRFR_WIDTH           (1U)
#define SW_PORT2_BPMLFSR_HCCLRFR(x)              (((uint32_t)(((uint32_t)(x)) << SW_PORT2_BPMLFSR_HCCLRFR_SHIFT)) & SW_PORT2_BPMLFSR_HCCLRFR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SW_PORT2_Register_Masks */

/*!
 * @}
 */ /* end of group SW_PORT2_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SW_PORT2_H_) */
