/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_ENETC_PORT.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_ENETC_PORT
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
#if !defined(S32Z2_ENETC_PORT_H_)  /* Check if memory map has not been already included */
#define S32Z2_ENETC_PORT_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ENETC_PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_PORT_Peripheral_Access_Layer ENETC_PORT Peripheral Access Layer
 * @{
 */

/** ENETC_PORT - Size of Registers Arrays */
#define ENETC_PORT_TCT_NUM_COUNT                  8u

/** ENETC_PORT - Register Layout Typedef */
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
  uint8_t RESERVED_3[40];
  __IO uint32_t PPCR;                              /**< Port parser configuration register, offset: 0x80 */
  __IO uint32_t PIPFCR;                            /**< Port ingress port filter configuration register, offset: 0x84 */
  uint8_t RESERVED_4[24];
  __IO uint32_t PSGCR;                             /**< Port stream gate configuration register, offset: 0xA0 */
  uint8_t RESERVED_5[92];
  __IO uint32_t POR;                               /**< Port operational register, offset: 0x100 */
  __I  uint32_t PSR;                               /**< Port status register, offset: 0x104 */
  __IO uint32_t PRXSDUOR;                          /**< Port receive SDU overhead register, offset: 0x108 */
  __IO uint32_t PTXSDUOR;                          /**< Port transmit SDU overhead register, offset: 0x10C */
  __IO uint32_t PTGSCR;                            /**< Port time gate scheduling control register, offset: 0x110 */
  __I  uint32_t PTGAGLSR;                          /**< Port time gate scheduling admin gate list status register, offset: 0x114 */
  __I  uint32_t PTGAGLLR;                          /**< Port time gate scheduling admin gate list length register, offset: 0x118 */
  __I  uint32_t PTGOGLLR;                          /**< Port time gating operational gate list length register, offset: 0x11C */
  __IO uint32_t PTGSATOR;                          /**< Port time gate scheduling advance time offset register, offset: 0x120 */
  uint8_t RESERVED_6[156];
  __I  uint32_t PRXDCR;                            /**< Port Rx discard count register, offset: 0x1C0 */
  uint8_t RESERVED_7[4];
  __IO uint32_t PRXDCRR0;                          /**< Port Rx discard count reason register 0, offset: 0x1C8 */
  __IO uint32_t PRXDCRR1;                          /**< Port Rx discard count reason register 1, offset: 0x1CC */
  uint8_t RESERVED_8[48];
  struct ENETC_PORT_TCT_NUM {                      /* offset: 0x200, array step: 0x20 */
    __I  uint32_t PTGSTCSR;                          /**< Port time gate scheduling traffic class 0 status register..Port time gate scheduling traffic class 7 status register, array offset: 0x200, array step: 0x20 */
    uint8_t RESERVED_0[4];
    __IO uint32_t PTCTMSDUR;                         /**< Port traffic class 0 transmit maximum SDU register..Port traffic class 7 transmit maximum SDU register, array offset: 0x208, array step: 0x20 */
    uint8_t RESERVED_1[4];
    __IO uint32_t PTCCBSR0;                          /**< Port transmit traffic class 0 credit based shaper register 0..Port transmit traffic class 7 credit based shaper register 0, array offset: 0x210, array step: 0x20 */
    __IO uint32_t PTCCBSR1;                          /**< Port traffic class 0 credit based shaper register 1..Port traffic class 7 credit based shaper register 1, array offset: 0x214, array step: 0x20 */
    uint8_t RESERVED_2[8];
  } TCT_NUM[ENETC_PORT_TCT_NUM_COUNT];
  uint8_t RESERVED_9[312];
  __IO uint32_t PPCPDEIMR;                         /**< Port PCP DEI mapping register, offset: 0x438 */
  uint8_t RESERVED_10[36];
  __IO uint32_t PISIDCR;                           /**< Port ingress stream identification configuration register, offset: 0x460 */
} ENETC_PORT_Type, *ENETC_PORT_MemMapPtr;

/** Number of instances of the ENETC_PORT module. */
#define ENETC_PORT_INSTANCE_COUNT                (1u)

/* ENETC_PORT - Peripheral instance base addresses */
/** Peripheral NETC__ENETC0_PORT base address */
#define IP_NETC__ENETC0_PORT_BASE                (0x74B14000u)
/** Peripheral NETC__ENETC0_PORT base pointer */
#define IP_NETC__ENETC0_PORT                     ((ENETC_PORT_Type *)IP_NETC__ENETC0_PORT_BASE)
/** Array initializer of ENETC_PORT peripheral base addresses */
#define IP_ENETC_PORT_BASE_ADDRS                 { IP_NETC__ENETC0_PORT_BASE }
/** Array initializer of ENETC_PORT peripheral base pointers */
#define IP_ENETC_PORT_BASE_PTRS                  { IP_NETC__ENETC0_PORT }

/* ----------------------------------------------------------------------------
   -- ENETC_PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_PORT_Register_Masks ENETC_PORT Register Masks
 * @{
 */

/*! @name PCAPR - Port capability register */
/*! @{ */

#define ENETC_PORT_PCAPR_LINK_TYPE_MASK          (0x10U)
#define ENETC_PORT_PCAPR_LINK_TYPE_SHIFT         (4U)
#define ENETC_PORT_PCAPR_LINK_TYPE_WIDTH         (1U)
#define ENETC_PORT_PCAPR_LINK_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PCAPR_LINK_TYPE_SHIFT)) & ENETC_PORT_PCAPR_LINK_TYPE_MASK)

#define ENETC_PORT_PCAPR_NUM_TC_MASK             (0xF000U)
#define ENETC_PORT_PCAPR_NUM_TC_SHIFT            (12U)
#define ENETC_PORT_PCAPR_NUM_TC_WIDTH            (4U)
#define ENETC_PORT_PCAPR_NUM_TC(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PCAPR_NUM_TC_SHIFT)) & ENETC_PORT_PCAPR_NUM_TC_MASK)

#define ENETC_PORT_PCAPR_NUM_Q_MASK              (0xF0000U)
#define ENETC_PORT_PCAPR_NUM_Q_SHIFT             (16U)
#define ENETC_PORT_PCAPR_NUM_Q_WIDTH             (4U)
#define ENETC_PORT_PCAPR_NUM_Q(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PCAPR_NUM_Q_SHIFT)) & ENETC_PORT_PCAPR_NUM_Q_MASK)

#define ENETC_PORT_PCAPR_NUM_CG_MASK             (0xF000000U)
#define ENETC_PORT_PCAPR_NUM_CG_SHIFT            (24U)
#define ENETC_PORT_PCAPR_NUM_CG_WIDTH            (4U)
#define ENETC_PORT_PCAPR_NUM_CG(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PCAPR_NUM_CG_SHIFT)) & ENETC_PORT_PCAPR_NUM_CG_MASK)

#define ENETC_PORT_PCAPR_TGS_MASK                (0x10000000U)
#define ENETC_PORT_PCAPR_TGS_SHIFT               (28U)
#define ENETC_PORT_PCAPR_TGS_WIDTH               (1U)
#define ENETC_PORT_PCAPR_TGS(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PCAPR_TGS_SHIFT)) & ENETC_PORT_PCAPR_TGS_MASK)

#define ENETC_PORT_PCAPR_CBS_MASK                (0x20000000U)
#define ENETC_PORT_PCAPR_CBS_SHIFT               (29U)
#define ENETC_PORT_PCAPR_CBS_WIDTH               (1U)
#define ENETC_PORT_PCAPR_CBS(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PCAPR_CBS_SHIFT)) & ENETC_PORT_PCAPR_CBS_MASK)
/*! @} */

/*! @name PMCAPR - Port MAC capability register */
/*! @{ */

#define ENETC_PORT_PMCAPR_MAC_VAR_MASK           (0x7U)
#define ENETC_PORT_PMCAPR_MAC_VAR_SHIFT          (0U)
#define ENETC_PORT_PMCAPR_MAC_VAR_WIDTH          (3U)
#define ENETC_PORT_PMCAPR_MAC_VAR(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PMCAPR_MAC_VAR_SHIFT)) & ENETC_PORT_PMCAPR_MAC_VAR_MASK)

#define ENETC_PORT_PMCAPR_EFPAD_MASK             (0x30U)
#define ENETC_PORT_PMCAPR_EFPAD_SHIFT            (4U)
#define ENETC_PORT_PMCAPR_EFPAD_WIDTH            (2U)
#define ENETC_PORT_PMCAPR_EFPAD(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PMCAPR_EFPAD_SHIFT)) & ENETC_PORT_PMCAPR_EFPAD_MASK)

#define ENETC_PORT_PMCAPR_HD_MASK                (0x100U)
#define ENETC_PORT_PMCAPR_HD_SHIFT               (8U)
#define ENETC_PORT_PMCAPR_HD_WIDTH               (1U)
#define ENETC_PORT_PMCAPR_HD(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PMCAPR_HD_SHIFT)) & ENETC_PORT_PMCAPR_HD_MASK)

#define ENETC_PORT_PMCAPR_FP_MASK                (0x600U)
#define ENETC_PORT_PMCAPR_FP_SHIFT               (9U)
#define ENETC_PORT_PMCAPR_FP_WIDTH               (2U)
#define ENETC_PORT_PMCAPR_FP(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PMCAPR_FP_SHIFT)) & ENETC_PORT_PMCAPR_FP_MASK)

#define ENETC_PORT_PMCAPR_MII_PROT_MASK          (0xF000000U)
#define ENETC_PORT_PMCAPR_MII_PROT_SHIFT         (24U)
#define ENETC_PORT_PMCAPR_MII_PROT_WIDTH         (4U)
#define ENETC_PORT_PMCAPR_MII_PROT(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PMCAPR_MII_PROT_SHIFT)) & ENETC_PORT_PMCAPR_MII_PROT_MASK)
/*! @} */

/*! @name PIOCAPR - Port I/O capability register */
/*! @{ */

#define ENETC_PORT_PIOCAPR_PCS_PROT_MASK         (0xFFFFU)
#define ENETC_PORT_PIOCAPR_PCS_PROT_SHIFT        (0U)
#define ENETC_PORT_PIOCAPR_PCS_PROT_WIDTH        (16U)
#define ENETC_PORT_PIOCAPR_PCS_PROT(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PIOCAPR_PCS_PROT_SHIFT)) & ENETC_PORT_PIOCAPR_PCS_PROT_MASK)

#define ENETC_PORT_PIOCAPR_IO_VAR_MASK           (0xF000000U)
#define ENETC_PORT_PIOCAPR_IO_VAR_SHIFT          (24U)
#define ENETC_PORT_PIOCAPR_IO_VAR_WIDTH          (4U)
#define ENETC_PORT_PIOCAPR_IO_VAR(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PIOCAPR_IO_VAR_SHIFT)) & ENETC_PORT_PIOCAPR_IO_VAR_MASK)

#define ENETC_PORT_PIOCAPR_EMDIO_MASK            (0x10000000U)
#define ENETC_PORT_PIOCAPR_EMDIO_SHIFT           (28U)
#define ENETC_PORT_PIOCAPR_EMDIO_WIDTH           (1U)
#define ENETC_PORT_PIOCAPR_EMDIO(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PIOCAPR_EMDIO_SHIFT)) & ENETC_PORT_PIOCAPR_EMDIO_MASK)

#define ENETC_PORT_PIOCAPR_REVMII_RATE_MASK      (0x40000000U)
#define ENETC_PORT_PIOCAPR_REVMII_RATE_SHIFT     (30U)
#define ENETC_PORT_PIOCAPR_REVMII_RATE_WIDTH     (1U)
#define ENETC_PORT_PIOCAPR_REVMII_RATE(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PIOCAPR_REVMII_RATE_SHIFT)) & ENETC_PORT_PIOCAPR_REVMII_RATE_MASK)

#define ENETC_PORT_PIOCAPR_REVMII_MASK           (0x80000000U)
#define ENETC_PORT_PIOCAPR_REVMII_SHIFT          (31U)
#define ENETC_PORT_PIOCAPR_REVMII_WIDTH          (1U)
#define ENETC_PORT_PIOCAPR_REVMII(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PIOCAPR_REVMII_SHIFT)) & ENETC_PORT_PIOCAPR_REVMII_MASK)
/*! @} */

/*! @name PCR - Port configuration register */
/*! @{ */

#define ENETC_PORT_PCR_HDR_FMT_MASK              (0x1U)
#define ENETC_PORT_PCR_HDR_FMT_SHIFT             (0U)
#define ENETC_PORT_PCR_HDR_FMT_WIDTH             (1U)
#define ENETC_PORT_PCR_HDR_FMT(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PCR_HDR_FMT_SHIFT)) & ENETC_PORT_PCR_HDR_FMT_MASK)

#define ENETC_PORT_PCR_L2DOSE_MASK               (0x10U)
#define ENETC_PORT_PCR_L2DOSE_SHIFT              (4U)
#define ENETC_PORT_PCR_L2DOSE_WIDTH              (1U)
#define ENETC_PORT_PCR_L2DOSE(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PCR_L2DOSE_SHIFT)) & ENETC_PORT_PCR_L2DOSE_MASK)

#define ENETC_PORT_PCR_TIMER_CS_MASK             (0x100U)
#define ENETC_PORT_PCR_TIMER_CS_SHIFT            (8U)
#define ENETC_PORT_PCR_TIMER_CS_WIDTH            (1U)
#define ENETC_PORT_PCR_TIMER_CS(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PCR_TIMER_CS_SHIFT)) & ENETC_PORT_PCR_TIMER_CS_MASK)

#define ENETC_PORT_PCR_FCSEA_MASK                (0x1000U)
#define ENETC_PORT_PCR_FCSEA_SHIFT               (12U)
#define ENETC_PORT_PCR_FCSEA_WIDTH               (1U)
#define ENETC_PORT_PCR_FCSEA(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PCR_FCSEA_SHIFT)) & ENETC_PORT_PCR_FCSEA_MASK)

#define ENETC_PORT_PCR_PSPEED_MASK               (0x3FFF0000U)
#define ENETC_PORT_PCR_PSPEED_SHIFT              (16U)
#define ENETC_PORT_PCR_PSPEED_WIDTH              (14U)
#define ENETC_PORT_PCR_PSPEED(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PCR_PSPEED_SHIFT)) & ENETC_PORT_PCR_PSPEED_MASK)
/*! @} */

/*! @name PMAR0 - Port MAC address register 0 */
/*! @{ */

#define ENETC_PORT_PMAR0_PRIM_MAC_ADDR_MASK      (0xFFFFFFFFU)
#define ENETC_PORT_PMAR0_PRIM_MAC_ADDR_SHIFT     (0U)
#define ENETC_PORT_PMAR0_PRIM_MAC_ADDR_WIDTH     (32U)
#define ENETC_PORT_PMAR0_PRIM_MAC_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PMAR0_PRIM_MAC_ADDR_SHIFT)) & ENETC_PORT_PMAR0_PRIM_MAC_ADDR_MASK)
/*! @} */

/*! @name PMAR1 - Port MAC address register 1 */
/*! @{ */

#define ENETC_PORT_PMAR1_PRIM_MAC_ADDR_MASK      (0xFFFFU)
#define ENETC_PORT_PMAR1_PRIM_MAC_ADDR_SHIFT     (0U)
#define ENETC_PORT_PMAR1_PRIM_MAC_ADDR_WIDTH     (16U)
#define ENETC_PORT_PMAR1_PRIM_MAC_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PMAR1_PRIM_MAC_ADDR_SHIFT)) & ENETC_PORT_PMAR1_PRIM_MAC_ADDR_MASK)
/*! @} */

/*! @name PTAR - Port TPID acceptance register */
/*! @{ */

#define ENETC_PORT_PTAR_OVTPIDL_MASK             (0xFU)
#define ENETC_PORT_PTAR_OVTPIDL_SHIFT            (0U)
#define ENETC_PORT_PTAR_OVTPIDL_WIDTH            (4U)
#define ENETC_PORT_PTAR_OVTPIDL(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTAR_OVTPIDL_SHIFT)) & ENETC_PORT_PTAR_OVTPIDL_MASK)

#define ENETC_PORT_PTAR_IVTPIDL_MASK             (0xF0U)
#define ENETC_PORT_PTAR_IVTPIDL_SHIFT            (4U)
#define ENETC_PORT_PTAR_IVTPIDL_WIDTH            (4U)
#define ENETC_PORT_PTAR_IVTPIDL(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTAR_IVTPIDL_SHIFT)) & ENETC_PORT_PTAR_IVTPIDL_MASK)
/*! @} */

/*! @name PQOSMR - Port QoS mode register */
/*! @{ */

#define ENETC_PORT_PQOSMR_VS_MASK                (0x1U)
#define ENETC_PORT_PQOSMR_VS_SHIFT               (0U)
#define ENETC_PORT_PQOSMR_VS_WIDTH               (1U)
#define ENETC_PORT_PQOSMR_VS(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PQOSMR_VS_SHIFT)) & ENETC_PORT_PQOSMR_VS_MASK)

#define ENETC_PORT_PQOSMR_VE_MASK                (0x2U)
#define ENETC_PORT_PQOSMR_VE_SHIFT               (1U)
#define ENETC_PORT_PQOSMR_VE_WIDTH               (1U)
#define ENETC_PORT_PQOSMR_VE(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PQOSMR_VE_SHIFT)) & ENETC_PORT_PQOSMR_VE_MASK)

#define ENETC_PORT_PQOSMR_DDR_MASK               (0xCU)
#define ENETC_PORT_PQOSMR_DDR_SHIFT              (2U)
#define ENETC_PORT_PQOSMR_DDR_WIDTH              (2U)
#define ENETC_PORT_PQOSMR_DDR(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PQOSMR_DDR_SHIFT)) & ENETC_PORT_PQOSMR_DDR_MASK)

#define ENETC_PORT_PQOSMR_DIPV_MASK              (0x70U)
#define ENETC_PORT_PQOSMR_DIPV_SHIFT             (4U)
#define ENETC_PORT_PQOSMR_DIPV_WIDTH             (3U)
#define ENETC_PORT_PQOSMR_DIPV(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PQOSMR_DIPV_SHIFT)) & ENETC_PORT_PQOSMR_DIPV_MASK)

#define ENETC_PORT_PQOSMR_VQMP_MASK              (0xF0000U)
#define ENETC_PORT_PQOSMR_VQMP_SHIFT             (16U)
#define ENETC_PORT_PQOSMR_VQMP_WIDTH             (4U)
#define ENETC_PORT_PQOSMR_VQMP(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PQOSMR_VQMP_SHIFT)) & ENETC_PORT_PQOSMR_VQMP_MASK)
/*! @} */

/*! @name PPCR - Port parser configuration register */
/*! @{ */

#define ENETC_PORT_PPCR_L1PFS_MASK               (0x3EU)
#define ENETC_PORT_PPCR_L1PFS_SHIFT              (1U)
#define ENETC_PORT_PPCR_L1PFS_WIDTH              (5U)
#define ENETC_PORT_PPCR_L1PFS(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCR_L1PFS_SHIFT)) & ENETC_PORT_PPCR_L1PFS_MASK)

#define ENETC_PORT_PPCR_L2PFS_MASK               (0x3E00U)
#define ENETC_PORT_PPCR_L2PFS_SHIFT              (9U)
#define ENETC_PORT_PPCR_L2PFS_WIDTH              (5U)
#define ENETC_PORT_PPCR_L2PFS(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCR_L2PFS_SHIFT)) & ENETC_PORT_PPCR_L2PFS_MASK)

#define ENETC_PORT_PPCR_L3HFP_MASK               (0x10000U)
#define ENETC_PORT_PPCR_L3HFP_SHIFT              (16U)
#define ENETC_PORT_PPCR_L3HFP_WIDTH              (1U)
#define ENETC_PORT_PPCR_L3HFP(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCR_L3HFP_SHIFT)) & ENETC_PORT_PPCR_L3HFP_MASK)

#define ENETC_PORT_PPCR_L3PFS_MASK               (0x3E0000U)
#define ENETC_PORT_PPCR_L3PFS_SHIFT              (17U)
#define ENETC_PORT_PPCR_L3PFS_WIDTH              (5U)
#define ENETC_PORT_PPCR_L3PFS(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCR_L3PFS_SHIFT)) & ENETC_PORT_PPCR_L3PFS_MASK)

#define ENETC_PORT_PPCR_L4HFP_MASK               (0x1000000U)
#define ENETC_PORT_PPCR_L4HFP_SHIFT              (24U)
#define ENETC_PORT_PPCR_L4HFP_WIDTH              (1U)
#define ENETC_PORT_PPCR_L4HFP(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCR_L4HFP_SHIFT)) & ENETC_PORT_PPCR_L4HFP_MASK)

#define ENETC_PORT_PPCR_L4PFS_MASK               (0x3E000000U)
#define ENETC_PORT_PPCR_L4PFS_SHIFT              (25U)
#define ENETC_PORT_PPCR_L4PFS_WIDTH              (5U)
#define ENETC_PORT_PPCR_L4PFS(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCR_L4PFS_SHIFT)) & ENETC_PORT_PPCR_L4PFS_MASK)
/*! @} */

/*! @name PIPFCR - Port ingress port filter configuration register */
/*! @{ */

#define ENETC_PORT_PIPFCR_EN_MASK                (0x1U)
#define ENETC_PORT_PIPFCR_EN_SHIFT               (0U)
#define ENETC_PORT_PIPFCR_EN_WIDTH               (1U)
#define ENETC_PORT_PIPFCR_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PIPFCR_EN_SHIFT)) & ENETC_PORT_PIPFCR_EN_MASK)
/*! @} */

/*! @name PSGCR - Port stream gate configuration register */
/*! @{ */

#define ENETC_PORT_PSGCR_PDELAY_MASK             (0xFFFFFFU)
#define ENETC_PORT_PSGCR_PDELAY_SHIFT            (0U)
#define ENETC_PORT_PSGCR_PDELAY_WIDTH            (24U)
#define ENETC_PORT_PSGCR_PDELAY(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PSGCR_PDELAY_SHIFT)) & ENETC_PORT_PSGCR_PDELAY_MASK)

#define ENETC_PORT_PSGCR_OGC_MASK                (0x80000000U)
#define ENETC_PORT_PSGCR_OGC_SHIFT               (31U)
#define ENETC_PORT_PSGCR_OGC_WIDTH               (1U)
#define ENETC_PORT_PSGCR_OGC(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PSGCR_OGC_SHIFT)) & ENETC_PORT_PSGCR_OGC_MASK)
/*! @} */

/*! @name POR - Port operational register */
/*! @{ */

#define ENETC_PORT_POR_TXDIS_MASK                (0x1U)
#define ENETC_PORT_POR_TXDIS_SHIFT               (0U)
#define ENETC_PORT_POR_TXDIS_WIDTH               (1U)
#define ENETC_PORT_POR_TXDIS(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_POR_TXDIS_SHIFT)) & ENETC_PORT_POR_TXDIS_MASK)

#define ENETC_PORT_POR_RXDIS_MASK                (0x2U)
#define ENETC_PORT_POR_RXDIS_SHIFT               (1U)
#define ENETC_PORT_POR_RXDIS_WIDTH               (1U)
#define ENETC_PORT_POR_RXDIS(x)                  (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_POR_RXDIS_SHIFT)) & ENETC_PORT_POR_RXDIS_MASK)
/*! @} */

/*! @name PSR - Port status register */
/*! @{ */

#define ENETC_PORT_PSR_TX_BUSY_MASK              (0x1U)
#define ENETC_PORT_PSR_TX_BUSY_SHIFT             (0U)
#define ENETC_PORT_PSR_TX_BUSY_WIDTH             (1U)
#define ENETC_PORT_PSR_TX_BUSY(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PSR_TX_BUSY_SHIFT)) & ENETC_PORT_PSR_TX_BUSY_MASK)

#define ENETC_PORT_PSR_RX_BUSY_MASK              (0x2U)
#define ENETC_PORT_PSR_RX_BUSY_SHIFT             (1U)
#define ENETC_PORT_PSR_RX_BUSY_WIDTH             (1U)
#define ENETC_PORT_PSR_RX_BUSY(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PSR_RX_BUSY_SHIFT)) & ENETC_PORT_PSR_RX_BUSY_MASK)
/*! @} */

/*! @name PRXSDUOR - Port receive SDU overhead register */
/*! @{ */

#define ENETC_PORT_PRXSDUOR_PPDU_BCO_MASK        (0x1FU)
#define ENETC_PORT_PRXSDUOR_PPDU_BCO_SHIFT       (0U)
#define ENETC_PORT_PRXSDUOR_PPDU_BCO_WIDTH       (5U)
#define ENETC_PORT_PRXSDUOR_PPDU_BCO(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXSDUOR_PPDU_BCO_SHIFT)) & ENETC_PORT_PRXSDUOR_PPDU_BCO_MASK)

#define ENETC_PORT_PRXSDUOR_MACSEC_BCO_MASK      (0x1F00U)
#define ENETC_PORT_PRXSDUOR_MACSEC_BCO_SHIFT     (8U)
#define ENETC_PORT_PRXSDUOR_MACSEC_BCO_WIDTH     (5U)
#define ENETC_PORT_PRXSDUOR_MACSEC_BCO(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXSDUOR_MACSEC_BCO_SHIFT)) & ENETC_PORT_PRXSDUOR_MACSEC_BCO_MASK)
/*! @} */

/*! @name PTXSDUOR - Port transmit SDU overhead register */
/*! @{ */

#define ENETC_PORT_PTXSDUOR_PPDU_BCO_MASK        (0x1FU)
#define ENETC_PORT_PTXSDUOR_PPDU_BCO_SHIFT       (0U)
#define ENETC_PORT_PTXSDUOR_PPDU_BCO_WIDTH       (5U)
#define ENETC_PORT_PTXSDUOR_PPDU_BCO(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTXSDUOR_PPDU_BCO_SHIFT)) & ENETC_PORT_PTXSDUOR_PPDU_BCO_MASK)

#define ENETC_PORT_PTXSDUOR_MACSEC_BCO_MASK      (0x1F00U)
#define ENETC_PORT_PTXSDUOR_MACSEC_BCO_SHIFT     (8U)
#define ENETC_PORT_PTXSDUOR_MACSEC_BCO_WIDTH     (5U)
#define ENETC_PORT_PTXSDUOR_MACSEC_BCO(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTXSDUOR_MACSEC_BCO_SHIFT)) & ENETC_PORT_PTXSDUOR_MACSEC_BCO_MASK)
/*! @} */

/*! @name PTGSCR - Port time gate scheduling control register */
/*! @{ */

#define ENETC_PORT_PTGSCR_TGE_MASK               (0x80000000U)
#define ENETC_PORT_PTGSCR_TGE_SHIFT              (31U)
#define ENETC_PORT_PTGSCR_TGE_WIDTH              (1U)
#define ENETC_PORT_PTGSCR_TGE(x)                 (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTGSCR_TGE_SHIFT)) & ENETC_PORT_PTGSCR_TGE_MASK)
/*! @} */

/*! @name PTGAGLSR - Port time gate scheduling admin gate list status register */
/*! @{ */

#define ENETC_PORT_PTGAGLSR_TG_MASK              (0x1U)
#define ENETC_PORT_PTGAGLSR_TG_SHIFT             (0U)
#define ENETC_PORT_PTGAGLSR_TG_WIDTH             (1U)
#define ENETC_PORT_PTGAGLSR_TG(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTGAGLSR_TG_SHIFT)) & ENETC_PORT_PTGAGLSR_TG_MASK)

#define ENETC_PORT_PTGAGLSR_CFG_PEND_MASK        (0x2U)
#define ENETC_PORT_PTGAGLSR_CFG_PEND_SHIFT       (1U)
#define ENETC_PORT_PTGAGLSR_CFG_PEND_WIDTH       (1U)
#define ENETC_PORT_PTGAGLSR_CFG_PEND(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTGAGLSR_CFG_PEND_SHIFT)) & ENETC_PORT_PTGAGLSR_CFG_PEND_MASK)
/*! @} */

/*! @name PTGAGLLR - Port time gate scheduling admin gate list length register */
/*! @{ */

#define ENETC_PORT_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_MASK (0xFFFFU)
#define ENETC_PORT_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_SHIFT (0U)
#define ENETC_PORT_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_WIDTH (16U)
#define ENETC_PORT_PTGAGLLR_ADMIN_GATE_LIST_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_SHIFT)) & ENETC_PORT_PTGAGLLR_ADMIN_GATE_LIST_LENGTH_MASK)
/*! @} */

/*! @name PTGOGLLR - Port time gating operational gate list length register */
/*! @{ */

#define ENETC_PORT_PTGOGLLR_OPER_GATE_LIST_LENGTH_MASK (0xFFFFU)
#define ENETC_PORT_PTGOGLLR_OPER_GATE_LIST_LENGTH_SHIFT (0U)
#define ENETC_PORT_PTGOGLLR_OPER_GATE_LIST_LENGTH_WIDTH (16U)
#define ENETC_PORT_PTGOGLLR_OPER_GATE_LIST_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTGOGLLR_OPER_GATE_LIST_LENGTH_SHIFT)) & ENETC_PORT_PTGOGLLR_OPER_GATE_LIST_LENGTH_MASK)
/*! @} */

/*! @name PTGSATOR - Port time gate scheduling advance time offset register */
/*! @{ */

#define ENETC_PORT_PTGSATOR_ADV_TIME_OFFSET_MASK (0xFFFFU)
#define ENETC_PORT_PTGSATOR_ADV_TIME_OFFSET_SHIFT (0U)
#define ENETC_PORT_PTGSATOR_ADV_TIME_OFFSET_WIDTH (16U)
#define ENETC_PORT_PTGSATOR_ADV_TIME_OFFSET(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTGSATOR_ADV_TIME_OFFSET_SHIFT)) & ENETC_PORT_PTGSATOR_ADV_TIME_OFFSET_MASK)
/*! @} */

/*! @name PRXDCR - Port Rx discard count register */
/*! @{ */

#define ENETC_PORT_PRXDCR_COUNT_MASK             (0xFFFFFFFFU)
#define ENETC_PORT_PRXDCR_COUNT_SHIFT            (0U)
#define ENETC_PORT_PRXDCR_COUNT_WIDTH            (32U)
#define ENETC_PORT_PRXDCR_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCR_COUNT_SHIFT)) & ENETC_PORT_PRXDCR_COUNT_MASK)
/*! @} */

/*! @name PRXDCRR0 - Port Rx discard count reason register 0 */
/*! @{ */

#define ENETC_PORT_PRXDCRR0_PCDR_MASK            (0x1U)
#define ENETC_PORT_PRXDCRR0_PCDR_SHIFT           (0U)
#define ENETC_PORT_PRXDCRR0_PCDR_WIDTH           (1U)
#define ENETC_PORT_PRXDCRR0_PCDR(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_PCDR_SHIFT)) & ENETC_PORT_PRXDCRR0_PCDR_MASK)

#define ENETC_PORT_PRXDCRR0_SMREDR_MASK          (0x2U)
#define ENETC_PORT_PRXDCRR0_SMREDR_SHIFT         (1U)
#define ENETC_PORT_PRXDCRR0_SMREDR_WIDTH         (1U)
#define ENETC_PORT_PRXDCRR0_SMREDR(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_SMREDR_SHIFT)) & ENETC_PORT_PRXDCRR0_SMREDR_MASK)

#define ENETC_PORT_PRXDCRR0_RXDISDR_MASK         (0x4U)
#define ENETC_PORT_PRXDCRR0_RXDISDR_SHIFT        (2U)
#define ENETC_PORT_PRXDCRR0_RXDISDR_WIDTH        (1U)
#define ENETC_PORT_PRXDCRR0_RXDISDR(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_RXDISDR_SHIFT)) & ENETC_PORT_PRXDCRR0_RXDISDR_MASK)

#define ENETC_PORT_PRXDCRR0_IPFDR_MASK           (0x8U)
#define ENETC_PORT_PRXDCRR0_IPFDR_SHIFT          (3U)
#define ENETC_PORT_PRXDCRR0_IPFDR_WIDTH          (1U)
#define ENETC_PORT_PRXDCRR0_IPFDR(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_IPFDR_SHIFT)) & ENETC_PORT_PRXDCRR0_IPFDR_MASK)

#define ENETC_PORT_PRXDCRR0_RPDR_MASK            (0x10U)
#define ENETC_PORT_PRXDCRR0_RPDR_SHIFT           (4U)
#define ENETC_PORT_PRXDCRR0_RPDR_WIDTH           (1U)
#define ENETC_PORT_PRXDCRR0_RPDR(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_RPDR_SHIFT)) & ENETC_PORT_PRXDCRR0_RPDR_MASK)

#define ENETC_PORT_PRXDCRR0_ISFDR_MASK           (0x20U)
#define ENETC_PORT_PRXDCRR0_ISFDR_SHIFT          (5U)
#define ENETC_PORT_PRXDCRR0_ISFDR_WIDTH          (1U)
#define ENETC_PORT_PRXDCRR0_ISFDR(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_ISFDR_SHIFT)) & ENETC_PORT_PRXDCRR0_ISFDR_MASK)

#define ENETC_PORT_PRXDCRR0_SGCDR_MASK           (0x40U)
#define ENETC_PORT_PRXDCRR0_SGCDR_SHIFT          (6U)
#define ENETC_PORT_PRXDCRR0_SGCDR_WIDTH          (1U)
#define ENETC_PORT_PRXDCRR0_SGCDR(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_SGCDR_SHIFT)) & ENETC_PORT_PRXDCRR0_SGCDR_MASK)

#define ENETC_PORT_PRXDCRR0_SGOEDR_MASK          (0x80U)
#define ENETC_PORT_PRXDCRR0_SGOEDR_SHIFT         (7U)
#define ENETC_PORT_PRXDCRR0_SGOEDR_WIDTH         (1U)
#define ENETC_PORT_PRXDCRR0_SGOEDR(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_SGOEDR_SHIFT)) & ENETC_PORT_PRXDCRR0_SGOEDR_MASK)

#define ENETC_PORT_PRXDCRR0_MSDUEDR_MASK         (0x100U)
#define ENETC_PORT_PRXDCRR0_MSDUEDR_SHIFT        (8U)
#define ENETC_PORT_PRXDCRR0_MSDUEDR_WIDTH        (1U)
#define ENETC_PORT_PRXDCRR0_MSDUEDR(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_MSDUEDR_SHIFT)) & ENETC_PORT_PRXDCRR0_MSDUEDR_MASK)

#define ENETC_PORT_PRXDCRR0_ITEDR_MASK           (0x800U)
#define ENETC_PORT_PRXDCRR0_ITEDR_SHIFT          (11U)
#define ENETC_PORT_PRXDCRR0_ITEDR_WIDTH          (1U)
#define ENETC_PORT_PRXDCRR0_ITEDR(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_ITEDR_SHIFT)) & ENETC_PORT_PRXDCRR0_ITEDR_MASK)

#define ENETC_PORT_PRXDCRR0_ECCEDR_MASK          (0x1000U)
#define ENETC_PORT_PRXDCRR0_ECCEDR_SHIFT         (12U)
#define ENETC_PORT_PRXDCRR0_ECCEDR_WIDTH         (1U)
#define ENETC_PORT_PRXDCRR0_ECCEDR(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_ECCEDR_SHIFT)) & ENETC_PORT_PRXDCRR0_ECCEDR_MASK)

#define ENETC_PORT_PRXDCRR0_SIFDR_MASK           (0x2000U)
#define ENETC_PORT_PRXDCRR0_SIFDR_SHIFT          (13U)
#define ENETC_PORT_PRXDCRR0_SIFDR_WIDTH          (1U)
#define ENETC_PORT_PRXDCRR0_SIFDR(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_SIFDR_SHIFT)) & ENETC_PORT_PRXDCRR0_SIFDR_MASK)

#define ENETC_PORT_PRXDCRR0_L2DOSDR_MASK         (0x4000U)
#define ENETC_PORT_PRXDCRR0_L2DOSDR_SHIFT        (14U)
#define ENETC_PORT_PRXDCRR0_L2DOSDR_WIDTH        (1U)
#define ENETC_PORT_PRXDCRR0_L2DOSDR(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_L2DOSDR_SHIFT)) & ENETC_PORT_PRXDCRR0_L2DOSDR_MASK)

#define ENETC_PORT_PRXDCRR0_PEDR_MASK            (0x10000U)
#define ENETC_PORT_PRXDCRR0_PEDR_SHIFT           (16U)
#define ENETC_PORT_PRXDCRR0_PEDR_WIDTH           (1U)
#define ENETC_PORT_PRXDCRR0_PEDR(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_PEDR_SHIFT)) & ENETC_PORT_PRXDCRR0_PEDR_MASK)

#define ENETC_PORT_PRXDCRR0_NODESTDR_MASK        (0x20000U)
#define ENETC_PORT_PRXDCRR0_NODESTDR_SHIFT       (17U)
#define ENETC_PORT_PRXDCRR0_NODESTDR_WIDTH       (1U)
#define ENETC_PORT_PRXDCRR0_NODESTDR(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR0_NODESTDR_SHIFT)) & ENETC_PORT_PRXDCRR0_NODESTDR_MASK)
/*! @} */

/*! @name PRXDCRR1 - Port Rx discard count reason register 1 */
/*! @{ */

#define ENETC_PORT_PRXDCRR1_ENTRYID_MASK         (0xFFFFU)
#define ENETC_PORT_PRXDCRR1_ENTRYID_SHIFT        (0U)
#define ENETC_PORT_PRXDCRR1_ENTRYID_WIDTH        (16U)
#define ENETC_PORT_PRXDCRR1_ENTRYID(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR1_ENTRYID_SHIFT)) & ENETC_PORT_PRXDCRR1_ENTRYID_MASK)

#define ENETC_PORT_PRXDCRR1_TT_MASK              (0xF0000000U)
#define ENETC_PORT_PRXDCRR1_TT_SHIFT             (28U)
#define ENETC_PORT_PRXDCRR1_TT_WIDTH             (4U)
#define ENETC_PORT_PRXDCRR1_TT(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PRXDCRR1_TT_SHIFT)) & ENETC_PORT_PRXDCRR1_TT_MASK)
/*! @} */

/*! @name PTGSTCSR - Port time gate scheduling traffic class 0 status register..Port time gate scheduling traffic class 7 status register */
/*! @{ */

#define ENETC_PORT_PTGSTCSR_LH_STATE_MASK        (0x10000U)
#define ENETC_PORT_PTGSTCSR_LH_STATE_SHIFT       (16U)
#define ENETC_PORT_PTGSTCSR_LH_STATE_WIDTH       (1U)
#define ENETC_PORT_PTGSTCSR_LH_STATE(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTGSTCSR_LH_STATE_SHIFT)) & ENETC_PORT_PTGSTCSR_LH_STATE_MASK)
/*! @} */

/*! @name PTCTMSDUR - Port traffic class 0 transmit maximum SDU register..Port traffic class 7 transmit maximum SDU register */
/*! @{ */

#define ENETC_PORT_PTCTMSDUR_MAXSDU_MASK         (0xFFFFU)
#define ENETC_PORT_PTCTMSDUR_MAXSDU_SHIFT        (0U)
#define ENETC_PORT_PTCTMSDUR_MAXSDU_WIDTH        (16U)
#define ENETC_PORT_PTCTMSDUR_MAXSDU(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTCTMSDUR_MAXSDU_SHIFT)) & ENETC_PORT_PTCTMSDUR_MAXSDU_MASK)

#define ENETC_PORT_PTCTMSDUR_SDU_TYPE_MASK       (0x30000U)
#define ENETC_PORT_PTCTMSDUR_SDU_TYPE_SHIFT      (16U)
#define ENETC_PORT_PTCTMSDUR_SDU_TYPE_WIDTH      (2U)
#define ENETC_PORT_PTCTMSDUR_SDU_TYPE(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTCTMSDUR_SDU_TYPE_SHIFT)) & ENETC_PORT_PTCTMSDUR_SDU_TYPE_MASK)

#define ENETC_PORT_PTCTMSDUR_SF_MAXSDU_DIS_MASK  (0x1000000U)
#define ENETC_PORT_PTCTMSDUR_SF_MAXSDU_DIS_SHIFT (24U)
#define ENETC_PORT_PTCTMSDUR_SF_MAXSDU_DIS_WIDTH (1U)
#define ENETC_PORT_PTCTMSDUR_SF_MAXSDU_DIS(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTCTMSDUR_SF_MAXSDU_DIS_SHIFT)) & ENETC_PORT_PTCTMSDUR_SF_MAXSDU_DIS_MASK)
/*! @} */

/*! @name PTCCBSR0 - Port transmit traffic class 0 credit based shaper register 0..Port transmit traffic class 7 credit based shaper register 0 */
/*! @{ */

#define ENETC_PORT_PTCCBSR0_BW_MASK              (0x7FU)
#define ENETC_PORT_PTCCBSR0_BW_SHIFT             (0U)
#define ENETC_PORT_PTCCBSR0_BW_WIDTH             (7U)
#define ENETC_PORT_PTCCBSR0_BW(x)                (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTCCBSR0_BW_SHIFT)) & ENETC_PORT_PTCCBSR0_BW_MASK)

#define ENETC_PORT_PTCCBSR0_CBSE_MASK            (0x80000000U)
#define ENETC_PORT_PTCCBSR0_CBSE_SHIFT           (31U)
#define ENETC_PORT_PTCCBSR0_CBSE_WIDTH           (1U)
#define ENETC_PORT_PTCCBSR0_CBSE(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTCCBSR0_CBSE_SHIFT)) & ENETC_PORT_PTCCBSR0_CBSE_MASK)
/*! @} */

/*! @name PTCCBSR1 - Port traffic class 0 credit based shaper register 1..Port traffic class 7 credit based shaper register 1 */
/*! @{ */

#define ENETC_PORT_PTCCBSR1_HI_CREDIT_MASK       (0xFFFFFFFFU)
#define ENETC_PORT_PTCCBSR1_HI_CREDIT_SHIFT      (0U)
#define ENETC_PORT_PTCCBSR1_HI_CREDIT_WIDTH      (32U)
#define ENETC_PORT_PTCCBSR1_HI_CREDIT(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PTCCBSR1_HI_CREDIT_SHIFT)) & ENETC_PORT_PTCCBSR1_HI_CREDIT_MASK)
/*! @} */

/*! @name PPCPDEIMR - Port PCP DEI mapping register */
/*! @{ */

#define ENETC_PORT_PPCPDEIMR_IPCPMP_MASK         (0xFU)
#define ENETC_PORT_PPCPDEIMR_IPCPMP_SHIFT        (0U)
#define ENETC_PORT_PPCPDEIMR_IPCPMP_WIDTH        (4U)
#define ENETC_PORT_PPCPDEIMR_IPCPMP(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCPDEIMR_IPCPMP_SHIFT)) & ENETC_PORT_PPCPDEIMR_IPCPMP_MASK)

#define ENETC_PORT_PPCPDEIMR_IPCPMPV_MASK        (0x80U)
#define ENETC_PORT_PPCPDEIMR_IPCPMPV_SHIFT       (7U)
#define ENETC_PORT_PPCPDEIMR_IPCPMPV_WIDTH       (1U)
#define ENETC_PORT_PPCPDEIMR_IPCPMPV(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCPDEIMR_IPCPMPV_SHIFT)) & ENETC_PORT_PPCPDEIMR_IPCPMPV_MASK)

#define ENETC_PORT_PPCPDEIMR_EPCPMP_MASK         (0xF00U)
#define ENETC_PORT_PPCPDEIMR_EPCPMP_SHIFT        (8U)
#define ENETC_PORT_PPCPDEIMR_EPCPMP_WIDTH        (4U)
#define ENETC_PORT_PPCPDEIMR_EPCPMP(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCPDEIMR_EPCPMP_SHIFT)) & ENETC_PORT_PPCPDEIMR_EPCPMP_MASK)

#define ENETC_PORT_PPCPDEIMR_EPCPMPV_MASK        (0x8000U)
#define ENETC_PORT_PPCPDEIMR_EPCPMPV_SHIFT       (15U)
#define ENETC_PORT_PPCPDEIMR_EPCPMPV_WIDTH       (1U)
#define ENETC_PORT_PPCPDEIMR_EPCPMPV(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCPDEIMR_EPCPMPV_SHIFT)) & ENETC_PORT_PPCPDEIMR_EPCPMPV_MASK)

#define ENETC_PORT_PPCPDEIMR_DR0DEI_MASK         (0x10000U)
#define ENETC_PORT_PPCPDEIMR_DR0DEI_SHIFT        (16U)
#define ENETC_PORT_PPCPDEIMR_DR0DEI_WIDTH        (1U)
#define ENETC_PORT_PPCPDEIMR_DR0DEI(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCPDEIMR_DR0DEI_SHIFT)) & ENETC_PORT_PPCPDEIMR_DR0DEI_MASK)

#define ENETC_PORT_PPCPDEIMR_DR1DEI_MASK         (0x20000U)
#define ENETC_PORT_PPCPDEIMR_DR1DEI_SHIFT        (17U)
#define ENETC_PORT_PPCPDEIMR_DR1DEI_WIDTH        (1U)
#define ENETC_PORT_PPCPDEIMR_DR1DEI(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCPDEIMR_DR1DEI_SHIFT)) & ENETC_PORT_PPCPDEIMR_DR1DEI_MASK)

#define ENETC_PORT_PPCPDEIMR_DR2DEI_MASK         (0x40000U)
#define ENETC_PORT_PPCPDEIMR_DR2DEI_SHIFT        (18U)
#define ENETC_PORT_PPCPDEIMR_DR2DEI_WIDTH        (1U)
#define ENETC_PORT_PPCPDEIMR_DR2DEI(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCPDEIMR_DR2DEI_SHIFT)) & ENETC_PORT_PPCPDEIMR_DR2DEI_MASK)

#define ENETC_PORT_PPCPDEIMR_DR3DEI_MASK         (0x80000U)
#define ENETC_PORT_PPCPDEIMR_DR3DEI_SHIFT        (19U)
#define ENETC_PORT_PPCPDEIMR_DR3DEI_WIDTH        (1U)
#define ENETC_PORT_PPCPDEIMR_DR3DEI(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCPDEIMR_DR3DEI_SHIFT)) & ENETC_PORT_PPCPDEIMR_DR3DEI_MASK)

#define ENETC_PORT_PPCPDEIMR_DRME_MASK           (0x100000U)
#define ENETC_PORT_PPCPDEIMR_DRME_SHIFT          (20U)
#define ENETC_PORT_PPCPDEIMR_DRME_WIDTH          (1U)
#define ENETC_PORT_PPCPDEIMR_DRME(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PPCPDEIMR_DRME_SHIFT)) & ENETC_PORT_PPCPDEIMR_DRME_MASK)
/*! @} */

/*! @name PISIDCR - Port ingress stream identification configuration register */
/*! @{ */

#define ENETC_PORT_PISIDCR_KCPAIR_MASK           (0x1U)
#define ENETC_PORT_PISIDCR_KCPAIR_SHIFT          (0U)
#define ENETC_PORT_PISIDCR_KCPAIR_WIDTH          (1U)
#define ENETC_PORT_PISIDCR_KCPAIR(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PISIDCR_KCPAIR_SHIFT)) & ENETC_PORT_PISIDCR_KCPAIR_MASK)

#define ENETC_PORT_PISIDCR_KC0EN_MASK            (0x2U)
#define ENETC_PORT_PISIDCR_KC0EN_SHIFT           (1U)
#define ENETC_PORT_PISIDCR_KC0EN_WIDTH           (1U)
#define ENETC_PORT_PISIDCR_KC0EN(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PISIDCR_KC0EN_SHIFT)) & ENETC_PORT_PISIDCR_KC0EN_MASK)

#define ENETC_PORT_PISIDCR_KC1EN_MASK            (0x4U)
#define ENETC_PORT_PISIDCR_KC1EN_SHIFT           (2U)
#define ENETC_PORT_PISIDCR_KC1EN_WIDTH           (1U)
#define ENETC_PORT_PISIDCR_KC1EN(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PISIDCR_KC1EN_SHIFT)) & ENETC_PORT_PISIDCR_KC1EN_MASK)

#define ENETC_PORT_PISIDCR_ISEID_MASK            (0xFFFF0000U)
#define ENETC_PORT_PISIDCR_ISEID_SHIFT           (16U)
#define ENETC_PORT_PISIDCR_ISEID_WIDTH           (16U)
#define ENETC_PORT_PISIDCR_ISEID(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_PORT_PISIDCR_ISEID_SHIFT)) & ENETC_PORT_PISIDCR_ISEID_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ENETC_PORT_Register_Masks */

/*!
 * @}
 */ /* end of group ENETC_PORT_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_ENETC_PORT_H_) */
