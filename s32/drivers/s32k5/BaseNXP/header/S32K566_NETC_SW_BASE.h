/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_NETC_SW_BASE.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_NETC_SW_BASE
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
#if !defined(S32K566_NETC_SW_BASE_H_)  /* Check if memory map has not been already included */
#define S32K566_NETC_SW_BASE_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- NETC_SW_BASE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_SW_BASE_Peripheral_Access_Layer NETC_SW_BASE Peripheral Access Layer
 * @{
 */

/** NETC_SW_BASE - Size of Registers Arrays */
#define NETC_SW_BASE_NUM_PORT_GRP_COUNT           1u
#define NETC_SW_BASE_NUM_CBDR_COUNT               2u
#define NETC_SW_BASE_NUM_CBDR_INT_COUNT           2u
#define NETC_SW_BASE_MAP_PCP_MAP_IPV_COUNT        4u
#define NETC_SW_BASE_MAP_PCP_COUNT                2u
#define NETC_SW_BASE_NUM_PCP2PCPMPR_COUNT         2u

/** NETC_SW_BASE - Register Layout Typedef */
typedef struct NETC_SW_BASE_Struct {
  __I  uint32_t SCAPR0;                            /**< Switch capability register 0, offset: 0x0 */
  __I  uint32_t SCAPR1;                            /**< Switch capability register 1, offset: 0x4 */
  __I  uint32_t BPCAPR;                            /**< Buffer pool capability register, offset: 0x8 */
  uint8_t RESERVED_0[12];
  __I  uint32_t FCAPR;                             /**< Forwarding capability register, offset: 0x18 */
  uint8_t RESERVED_1[36];
  __I  uint32_t SMBCAPR;                           /**< Shared memory buffer capability register, offset: 0x40 */
  __I  uint32_t SMBOR0;                            /**< Shared memory buffer operational register 0, offset: 0x44 */
  __I  uint32_t SMBOR1;                            /**< Shared memory buffer operational register 1, offset: 0x48 */
  uint8_t RESERVED_2[52];
  __IO uint32_t CCAR;                              /**< Command cache attribute register, offset: 0x80 */
  uint8_t RESERVED_3[124];
  __I  uint32_t BPTCAPR;                           /**< Buffer pool table capability register, offset: 0x100 */
  __I  uint32_t SBPTCAPR;                          /**< Shared buffer pool table capability register, offset: 0x104 */
  uint8_t RESERVED_4[8];
  __I  uint32_t ETMCGTCAPR;                        /**< ETM congestion group table capability register, offset: 0x110 */
  __I  uint32_t ETMCQTCAPR;                        /**< ETM class queue table capability register, offset: 0x114 */
  __I  uint32_t ETMCSTCAPR;                        /**< ETM class scheduler table capability register, offset: 0x118 */
  uint8_t RESERVED_5[4];
  __I  uint32_t ATSQSCAPR;                         /**< ATS queue set capability register, offset: 0x120 */
  __I  uint32_t ATSQSOR;                           /**< ATS queue set operational register, offset: 0x124 */
  __IO uint32_t ATSCR;                             /**< ATS configuration register, offset: 0x128 */
  uint8_t RESERVED_6[596];
  __I  uint32_t SWID0PMR;                          /**< Switch ID 0 to port mapping register, offset: 0x380 */
  uint8_t RESERVED_7[124];
  __I  uint32_t PGCAPR;                            /**< Port group capability register, offset: 0x400 */
  __I  uint32_t PGOR[NETC_SW_BASE_NUM_PORT_GRP_COUNT]; /**< Port group 1 operational register, array offset: 0x404, array step: 0x4 */
  uint8_t RESERVED_8[24];
  __IO uint32_t IMDCR0;                            /**< Ingress mirror destination configuration register 0, offset: 0x420 */
  __IO uint32_t IMDCR1;                            /**< Ingress mirror destination configuration register 1, offset: 0x424 */
  uint8_t RESERVED_9[24];
  __IO uint32_t CTFCR;                             /**< Cut-through forwarding count register, offset: 0x440 */
  uint8_t RESERVED_10[956];
  struct NETC_SW_BASE_NUM_CBDR {                   /* offset: 0x800, array step: 0x30 */
    __IO uint32_t CBDRMR;                            /**< Command BDR 0 mode register..Command BDR 1 mode register, array offset: 0x800, array step: 0x30 */
    __I  uint32_t CBDRSR;                            /**< Command BDR 0 status register..Command BDR 1 status register, array offset: 0x804, array step: 0x30 */
    uint8_t RESERVED_0[8];
    __IO uint32_t CBDRBAR0;                          /**< Command BDR base address register 0, array offset: 0x810, array step: 0x30 */
    __IO uint32_t CBDRBAR1;                          /**< Command BDR 0 base address register 1..Command BDR 1 base address register 1, array offset: 0x814, array step: 0x30 */
    __IO uint32_t CBDRPIR;                           /**< Command BDR 0 producer index register..Command BDR 1 producer index register, array offset: 0x818, array step: 0x30 */
    __IO uint32_t CBDRCIR;                           /**< Command BDR 0 consumer index register..Command BDR 1 consumer index register, array offset: 0x81C, array step: 0x30 */
    __IO uint32_t CBDRLENR;                          /**< Command BDR 0 length register..Command BDR 1 length register, array offset: 0x820, array step: 0x30 */
    uint8_t RESERVED_1[12];
  } NUM_CBDR[NETC_SW_BASE_NUM_CBDR_COUNT];
  uint8_t RESERVED_11[64];
  struct NETC_SW_BASE_NUM_CBDR_INT {               /* offset: 0x8A0, array step: 0x10 */
    __IO uint32_t CBDRIER;                           /**< Command BDR 0 interrupt enable register..Command BDR 1 interrupt enable register, array offset: 0x8A0, array step: 0x10 */
    __IO uint32_t CBDRIDR;                           /**< Command BDR 0 interrupt detect register..Command BDR 1 interrupt detect register, array offset: 0x8A4, array step: 0x10 */
    __IO uint32_t CBDRMSIVR;                         /**< Command BDR 0 MSI-X vector register..Command BDR 1 MSI-X vector register, array offset: 0x8A8, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } NUM_CBDR_INT[NETC_SW_BASE_NUM_CBDR_INT_COUNT];
  uint8_t RESERVED_12[64];
  struct NETC_SW_BASE_MAP_PCP {                    /* offset: 0x900, array step: 0x20 */
    __IO uint32_t QOSVLANMPR[NETC_SW_BASE_MAP_PCP_MAP_IPV_COUNT];   /**< QoS to VLAN mapping profile 0 register 0..QoS to VLAN mapping profile 1 register 3, array offset: 0x900, array step: index*0x20, index2*0x4 */
    uint8_t RESERVED_0[16];
  } MAP_PCP[NETC_SW_BASE_MAP_PCP_COUNT];
  uint8_t RESERVED_13[448];
  __IO uint32_t PCP2PCPMPR[NETC_SW_BASE_NUM_PCP2PCPMPR_COUNT]; /**< PCP to PCP mapping profile 0 register..PCP to PCP mapping profile 1 register, array offset: 0xB00, array step: 0x4 */
  uint8_t RESERVED_14[5368];
  __I  uint32_t BRCAPR;                            /**< Bridge capability register, offset: 0x2000 */
  uint8_t RESERVED_15[4];
  __I  uint32_t VFHTCAPR;                          /**< VLAN filter hash table capability register, offset: 0x2008 */
  __I  uint32_t VFHTOR;                            /**< VLAN filter hash table operational register, offset: 0x200C */
  __IO uint32_t VFHTDECR0;                         /**< VLAN Filter (hash) table default entry configuration registers 0, offset: 0x2010 */
  __IO uint32_t VFHTDECR1;                         /**< VLAN filter hash table default entry configuration registers 1, offset: 0x2014 */
  __IO uint32_t VFHTDECR2;                         /**< VLAN filter hash table default entry configuration registers 2, offset: 0x2018 */
  uint8_t RESERVED_16[4];
  __I  uint32_t FDBHTCAPR;                         /**< FDB hash table capability register, offset: 0x2020 */
  __IO uint32_t FDBHTMCR;                          /**< FDB hash table memory configuration register, offset: 0x2024 */
  __I  uint32_t FDBHTOR0;                          /**< FDB hash table operational register 0, offset: 0x2028 */
  __I  uint32_t FDBHTOR1;                          /**< FDB hash table operational register 1, offset: 0x202C */
  uint8_t RESERVED_17[16];
  __I  uint32_t IPMFHTCAPR;                        /**< IP multicast filter hash table capability register, offset: 0x2040 */
  __I  uint32_t IPV4MFHTOR;                        /**< IPv4 multicast filter hash table operation register, offset: 0x2044 */
} NETC_SW_BASE_Type, *NETC_SW_BASE_MemMapPtr;

/** Number of instances of the NETC_SW_BASE module. */
#define NETC_SW_BASE_INSTANCE_COUNT              (1u)

/* NETC_SW_BASE - Peripheral instance base addresses */
/** Peripheral NETC__SW0_BASE base address */
#define IP_NETC__SW0_BASE_BASE                   (0x6D000000u)
/** Peripheral NETC__SW0_BASE base pointer */
#define IP_NETC__SW0_BASE                        ((NETC_SW_BASE_Type *)IP_NETC__SW0_BASE_BASE)
/** Array initializer of NETC_SW_BASE peripheral base addresses */
#define IP_NETC_SW_BASE_BASE_ADDRS               { IP_NETC__SW0_BASE_BASE }
/** Array initializer of NETC_SW_BASE peripheral base pointers */
#define IP_NETC_SW_BASE_BASE_PTRS                { IP_NETC__SW0_BASE }

/* ----------------------------------------------------------------------------
   -- NETC_SW_BASE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_SW_BASE_Register_Masks NETC_SW_BASE Register Masks
 * @{
 */

/*! @name SCAPR0 - Switch capability register 0 */
/*! @{ */

#define NETC_SW_BASE_SCAPR0_NUM_PORT_MASK        (0x1FU)
#define NETC_SW_BASE_SCAPR0_NUM_PORT_SHIFT       (0U)
#define NETC_SW_BASE_SCAPR0_NUM_PORT_WIDTH       (5U)
#define NETC_SW_BASE_SCAPR0_NUM_PORT(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR0_NUM_PORT_SHIFT)) & NETC_SW_BASE_SCAPR0_NUM_PORT_MASK)

#define NETC_SW_BASE_SCAPR0_NUM_IPV_MASK         (0x100U)
#define NETC_SW_BASE_SCAPR0_NUM_IPV_SHIFT        (8U)
#define NETC_SW_BASE_SCAPR0_NUM_IPV_WIDTH        (1U)
#define NETC_SW_BASE_SCAPR0_NUM_IPV(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR0_NUM_IPV_SHIFT)) & NETC_SW_BASE_SCAPR0_NUM_IPV_MASK)

#define NETC_SW_BASE_SCAPR0_NUM_MSIX_MASK        (0xF0000U)
#define NETC_SW_BASE_SCAPR0_NUM_MSIX_SHIFT       (16U)
#define NETC_SW_BASE_SCAPR0_NUM_MSIX_WIDTH       (4U)
#define NETC_SW_BASE_SCAPR0_NUM_MSIX(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR0_NUM_MSIX_SHIFT)) & NETC_SW_BASE_SCAPR0_NUM_MSIX_MASK)

#define NETC_SW_BASE_SCAPR0_NUM_PCPMP_MASK       (0xF00000U)
#define NETC_SW_BASE_SCAPR0_NUM_PCPMP_SHIFT      (20U)
#define NETC_SW_BASE_SCAPR0_NUM_PCPMP_WIDTH      (4U)
#define NETC_SW_BASE_SCAPR0_NUM_PCPMP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR0_NUM_PCPMP_SHIFT)) & NETC_SW_BASE_SCAPR0_NUM_PCPMP_MASK)

#define NETC_SW_BASE_SCAPR0_NUM_QVMP_MASK        (0xF000000U)
#define NETC_SW_BASE_SCAPR0_NUM_QVMP_SHIFT       (24U)
#define NETC_SW_BASE_SCAPR0_NUM_QVMP_WIDTH       (4U)
#define NETC_SW_BASE_SCAPR0_NUM_QVMP(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR0_NUM_QVMP_SHIFT)) & NETC_SW_BASE_SCAPR0_NUM_QVMP_MASK)
/*! @} */

/*! @name SCAPR1 - Switch capability register 1 */
/*! @{ */

#define NETC_SW_BASE_SCAPR1_FS_MASK              (0x1U)
#define NETC_SW_BASE_SCAPR1_FS_SHIFT             (0U)
#define NETC_SW_BASE_SCAPR1_FS_WIDTH             (1U)
#define NETC_SW_BASE_SCAPR1_FS(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR1_FS_SHIFT)) & NETC_SW_BASE_SCAPR1_FS_MASK)

#define NETC_SW_BASE_SCAPR1_CTF_MASK             (0x4U)
#define NETC_SW_BASE_SCAPR1_CTF_SHIFT            (2U)
#define NETC_SW_BASE_SCAPR1_CTF_WIDTH            (1U)
#define NETC_SW_BASE_SCAPR1_CTF(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR1_CTF_SHIFT)) & NETC_SW_BASE_SCAPR1_CTF_MASK)

#define NETC_SW_BASE_SCAPR1_TIMCAP_MASK          (0x8U)
#define NETC_SW_BASE_SCAPR1_TIMCAP_SHIFT         (3U)
#define NETC_SW_BASE_SCAPR1_TIMCAP_WIDTH         (1U)
#define NETC_SW_BASE_SCAPR1_TIMCAP(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR1_TIMCAP_SHIFT)) & NETC_SW_BASE_SCAPR1_TIMCAP_MASK)

#define NETC_SW_BASE_SCAPR1_IMIR_MASK            (0x10U)
#define NETC_SW_BASE_SCAPR1_IMIR_SHIFT           (4U)
#define NETC_SW_BASE_SCAPR1_IMIR_WIDTH           (1U)
#define NETC_SW_BASE_SCAPR1_IMIR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR1_IMIR_SHIFT)) & NETC_SW_BASE_SCAPR1_IMIR_MASK)

#define NETC_SW_BASE_SCAPR1_PG_MASK              (0x40U)
#define NETC_SW_BASE_SCAPR1_PG_SHIFT             (6U)
#define NETC_SW_BASE_SCAPR1_PG_WIDTH             (1U)
#define NETC_SW_BASE_SCAPR1_PG(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR1_PG_SHIFT)) & NETC_SW_BASE_SCAPR1_PG_MASK)

#define NETC_SW_BASE_SCAPR1_SDF_MASK             (0x80U)
#define NETC_SW_BASE_SCAPR1_SDF_SHIFT            (7U)
#define NETC_SW_BASE_SCAPR1_SDF_WIDTH            (1U)
#define NETC_SW_BASE_SCAPR1_SDF(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR1_SDF_SHIFT)) & NETC_SW_BASE_SCAPR1_SDF_MASK)

#define NETC_SW_BASE_SCAPR1_SWA_MASK             (0x300U)
#define NETC_SW_BASE_SCAPR1_SWA_SHIFT            (8U)
#define NETC_SW_BASE_SCAPR1_SWA_WIDTH            (2U)
#define NETC_SW_BASE_SCAPR1_SWA(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR1_SWA_SHIFT)) & NETC_SW_BASE_SCAPR1_SWA_MASK)

#define NETC_SW_BASE_SCAPR1_ATS_MASK             (0x400U)
#define NETC_SW_BASE_SCAPR1_ATS_SHIFT            (10U)
#define NETC_SW_BASE_SCAPR1_ATS_WIDTH            (1U)
#define NETC_SW_BASE_SCAPR1_ATS(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR1_ATS_SHIFT)) & NETC_SW_BASE_SCAPR1_ATS_MASK)

#define NETC_SW_BASE_SCAPR1_SQ_TAGS_MASK         (0x1F0000U)
#define NETC_SW_BASE_SCAPR1_SQ_TAGS_SHIFT        (16U)
#define NETC_SW_BASE_SCAPR1_SQ_TAGS_WIDTH        (5U)
#define NETC_SW_BASE_SCAPR1_SQ_TAGS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SCAPR1_SQ_TAGS_SHIFT)) & NETC_SW_BASE_SCAPR1_SQ_TAGS_MASK)
/*! @} */

/*! @name BPCAPR - Buffer pool capability register */
/*! @{ */

#define NETC_SW_BASE_BPCAPR_NUM_BP_MASK          (0xFFU)
#define NETC_SW_BASE_BPCAPR_NUM_BP_SHIFT         (0U)
#define NETC_SW_BASE_BPCAPR_NUM_BP_WIDTH         (8U)
#define NETC_SW_BASE_BPCAPR_NUM_BP(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_BPCAPR_NUM_BP_SHIFT)) & NETC_SW_BASE_BPCAPR_NUM_BP_MASK)

#define NETC_SW_BASE_BPCAPR_NUM_SBP_MASK         (0x1F0000U)
#define NETC_SW_BASE_BPCAPR_NUM_SBP_SHIFT        (16U)
#define NETC_SW_BASE_BPCAPR_NUM_SBP_WIDTH        (5U)
#define NETC_SW_BASE_BPCAPR_NUM_SBP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_BPCAPR_NUM_SBP_SHIFT)) & NETC_SW_BASE_BPCAPR_NUM_SBP_MASK)
/*! @} */

/*! @name FCAPR - Forwarding capability register */
/*! @{ */

#define NETC_SW_BASE_FCAPR_BR_MASK               (0x1U)
#define NETC_SW_BASE_FCAPR_BR_SHIFT              (0U)
#define NETC_SW_BASE_FCAPR_BR_WIDTH              (1U)
#define NETC_SW_BASE_FCAPR_BR(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_FCAPR_BR_SHIFT)) & NETC_SW_BASE_FCAPR_BR_MASK)

#define NETC_SW_BASE_FCAPR_SF_MASK               (0x2U)
#define NETC_SW_BASE_FCAPR_SF_SHIFT              (1U)
#define NETC_SW_BASE_FCAPR_SF_WIDTH              (1U)
#define NETC_SW_BASE_FCAPR_SF(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_FCAPR_SF_SHIFT)) & NETC_SW_BASE_FCAPR_SF_MASK)
/*! @} */

/*! @name SMBCAPR - Shared memory buffer capability register */
/*! @{ */

#define NETC_SW_BASE_SMBCAPR_NUM_WORDS_MASK      (0xFFFFFFU)
#define NETC_SW_BASE_SMBCAPR_NUM_WORDS_SHIFT     (0U)
#define NETC_SW_BASE_SMBCAPR_NUM_WORDS_WIDTH     (24U)
#define NETC_SW_BASE_SMBCAPR_NUM_WORDS(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SMBCAPR_NUM_WORDS_SHIFT)) & NETC_SW_BASE_SMBCAPR_NUM_WORDS_MASK)

#define NETC_SW_BASE_SMBCAPR_WORD_SIZE_MASK      (0x30000000U)
#define NETC_SW_BASE_SMBCAPR_WORD_SIZE_SHIFT     (28U)
#define NETC_SW_BASE_SMBCAPR_WORD_SIZE_WIDTH     (2U)
#define NETC_SW_BASE_SMBCAPR_WORD_SIZE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SMBCAPR_WORD_SIZE_SHIFT)) & NETC_SW_BASE_SMBCAPR_WORD_SIZE_MASK)

#define NETC_SW_BASE_SMBCAPR_MLOC_MASK           (0xC0000000U)
#define NETC_SW_BASE_SMBCAPR_MLOC_SHIFT          (30U)
#define NETC_SW_BASE_SMBCAPR_MLOC_WIDTH          (2U)
#define NETC_SW_BASE_SMBCAPR_MLOC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SMBCAPR_MLOC_SHIFT)) & NETC_SW_BASE_SMBCAPR_MLOC_MASK)
/*! @} */

/*! @name SMBOR0 - Shared memory buffer operational register 0 */
/*! @{ */

#define NETC_SW_BASE_SMBOR0_COUNT_MASK           (0xFFFFFFU)
#define NETC_SW_BASE_SMBOR0_COUNT_SHIFT          (0U)
#define NETC_SW_BASE_SMBOR0_COUNT_WIDTH          (24U)
#define NETC_SW_BASE_SMBOR0_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SMBOR0_COUNT_SHIFT)) & NETC_SW_BASE_SMBOR0_COUNT_MASK)
/*! @} */

/*! @name SMBOR1 - Shared memory buffer operational register 1 */
/*! @{ */

#define NETC_SW_BASE_SMBOR1_WATERMARK_MASK       (0xFFFFFFU)
#define NETC_SW_BASE_SMBOR1_WATERMARK_SHIFT      (0U)
#define NETC_SW_BASE_SMBOR1_WATERMARK_WIDTH      (24U)
#define NETC_SW_BASE_SMBOR1_WATERMARK(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SMBOR1_WATERMARK_SHIFT)) & NETC_SW_BASE_SMBOR1_WATERMARK_MASK)
/*! @} */

/*! @name CCAR - Command cache attribute register */
/*! @{ */

#define NETC_SW_BASE_CCAR_CBD_WRCACHE_MASK       (0xFU)
#define NETC_SW_BASE_CCAR_CBD_WRCACHE_SHIFT      (0U)
#define NETC_SW_BASE_CCAR_CBD_WRCACHE_WIDTH      (4U)
#define NETC_SW_BASE_CCAR_CBD_WRCACHE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CBD_WRCACHE_SHIFT)) & NETC_SW_BASE_CCAR_CBD_WRCACHE_MASK)

#define NETC_SW_BASE_CCAR_CBD_WRDOMAIN_MASK      (0x30U)
#define NETC_SW_BASE_CCAR_CBD_WRDOMAIN_SHIFT     (4U)
#define NETC_SW_BASE_CCAR_CBD_WRDOMAIN_WIDTH     (2U)
#define NETC_SW_BASE_CCAR_CBD_WRDOMAIN(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CBD_WRDOMAIN_SHIFT)) & NETC_SW_BASE_CCAR_CBD_WRDOMAIN_MASK)

#define NETC_SW_BASE_CCAR_CBD_WRSNP_MASK         (0xC0U)
#define NETC_SW_BASE_CCAR_CBD_WRSNP_SHIFT        (6U)
#define NETC_SW_BASE_CCAR_CBD_WRSNP_WIDTH        (2U)
#define NETC_SW_BASE_CCAR_CBD_WRSNP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CBD_WRSNP_SHIFT)) & NETC_SW_BASE_CCAR_CBD_WRSNP_MASK)

#define NETC_SW_BASE_CCAR_CWRCACHE_MASK          (0xF00U)
#define NETC_SW_BASE_CCAR_CWRCACHE_SHIFT         (8U)
#define NETC_SW_BASE_CCAR_CWRCACHE_WIDTH         (4U)
#define NETC_SW_BASE_CCAR_CWRCACHE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CWRCACHE_SHIFT)) & NETC_SW_BASE_CCAR_CWRCACHE_MASK)

#define NETC_SW_BASE_CCAR_CWRDOMAIN_MASK         (0x3000U)
#define NETC_SW_BASE_CCAR_CWRDOMAIN_SHIFT        (12U)
#define NETC_SW_BASE_CCAR_CWRDOMAIN_WIDTH        (2U)
#define NETC_SW_BASE_CCAR_CWRDOMAIN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CWRDOMAIN_SHIFT)) & NETC_SW_BASE_CCAR_CWRDOMAIN_MASK)

#define NETC_SW_BASE_CCAR_CWRSNP_MASK            (0xC000U)
#define NETC_SW_BASE_CCAR_CWRSNP_SHIFT           (14U)
#define NETC_SW_BASE_CCAR_CWRSNP_WIDTH           (2U)
#define NETC_SW_BASE_CCAR_CWRSNP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CWRSNP_SHIFT)) & NETC_SW_BASE_CCAR_CWRSNP_MASK)

#define NETC_SW_BASE_CCAR_CBD_RDCACHE_MASK       (0xF0000U)
#define NETC_SW_BASE_CCAR_CBD_RDCACHE_SHIFT      (16U)
#define NETC_SW_BASE_CCAR_CBD_RDCACHE_WIDTH      (4U)
#define NETC_SW_BASE_CCAR_CBD_RDCACHE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CBD_RDCACHE_SHIFT)) & NETC_SW_BASE_CCAR_CBD_RDCACHE_MASK)

#define NETC_SW_BASE_CCAR_CBD_RDDOMAIN_MASK      (0x300000U)
#define NETC_SW_BASE_CCAR_CBD_RDDOMAIN_SHIFT     (20U)
#define NETC_SW_BASE_CCAR_CBD_RDDOMAIN_WIDTH     (2U)
#define NETC_SW_BASE_CCAR_CBD_RDDOMAIN(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CBD_RDDOMAIN_SHIFT)) & NETC_SW_BASE_CCAR_CBD_RDDOMAIN_MASK)

#define NETC_SW_BASE_CCAR_CBD_RDSNP_MASK         (0xC00000U)
#define NETC_SW_BASE_CCAR_CBD_RDSNP_SHIFT        (22U)
#define NETC_SW_BASE_CCAR_CBD_RDSNP_WIDTH        (2U)
#define NETC_SW_BASE_CCAR_CBD_RDSNP(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CBD_RDSNP_SHIFT)) & NETC_SW_BASE_CCAR_CBD_RDSNP_MASK)

#define NETC_SW_BASE_CCAR_CRDCACHE_MASK          (0xF000000U)
#define NETC_SW_BASE_CCAR_CRDCACHE_SHIFT         (24U)
#define NETC_SW_BASE_CCAR_CRDCACHE_WIDTH         (4U)
#define NETC_SW_BASE_CCAR_CRDCACHE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CRDCACHE_SHIFT)) & NETC_SW_BASE_CCAR_CRDCACHE_MASK)

#define NETC_SW_BASE_CCAR_CRDDOMAIN_MASK         (0x30000000U)
#define NETC_SW_BASE_CCAR_CRDDOMAIN_SHIFT        (28U)
#define NETC_SW_BASE_CCAR_CRDDOMAIN_WIDTH        (2U)
#define NETC_SW_BASE_CCAR_CRDDOMAIN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CRDDOMAIN_SHIFT)) & NETC_SW_BASE_CCAR_CRDDOMAIN_MASK)

#define NETC_SW_BASE_CCAR_CRDSNP_MASK            (0xC0000000U)
#define NETC_SW_BASE_CCAR_CRDSNP_SHIFT           (30U)
#define NETC_SW_BASE_CCAR_CRDSNP_WIDTH           (2U)
#define NETC_SW_BASE_CCAR_CRDSNP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CCAR_CRDSNP_SHIFT)) & NETC_SW_BASE_CCAR_CRDSNP_MASK)
/*! @} */

/*! @name BPTCAPR - Buffer pool table capability register */
/*! @{ */

#define NETC_SW_BASE_BPTCAPR_VERSIONS_MASK       (0xFFFF0000U)
#define NETC_SW_BASE_BPTCAPR_VERSIONS_SHIFT      (16U)
#define NETC_SW_BASE_BPTCAPR_VERSIONS_WIDTH      (16U)
#define NETC_SW_BASE_BPTCAPR_VERSIONS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_BPTCAPR_VERSIONS_SHIFT)) & NETC_SW_BASE_BPTCAPR_VERSIONS_MASK)
/*! @} */

/*! @name SBPTCAPR - Shared buffer pool table capability register */
/*! @{ */

#define NETC_SW_BASE_SBPTCAPR_VERSIONS_MASK      (0xFFFF0000U)
#define NETC_SW_BASE_SBPTCAPR_VERSIONS_SHIFT     (16U)
#define NETC_SW_BASE_SBPTCAPR_VERSIONS_WIDTH     (16U)
#define NETC_SW_BASE_SBPTCAPR_VERSIONS(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SBPTCAPR_VERSIONS_SHIFT)) & NETC_SW_BASE_SBPTCAPR_VERSIONS_MASK)
/*! @} */

/*! @name ETMCGTCAPR - ETM congestion group table capability register */
/*! @{ */

#define NETC_SW_BASE_ETMCGTCAPR_VERSIONS_MASK    (0xFFFF0000U)
#define NETC_SW_BASE_ETMCGTCAPR_VERSIONS_SHIFT   (16U)
#define NETC_SW_BASE_ETMCGTCAPR_VERSIONS_WIDTH   (16U)
#define NETC_SW_BASE_ETMCGTCAPR_VERSIONS(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_ETMCGTCAPR_VERSIONS_SHIFT)) & NETC_SW_BASE_ETMCGTCAPR_VERSIONS_MASK)
/*! @} */

/*! @name ETMCQTCAPR - ETM class queue table capability register */
/*! @{ */

#define NETC_SW_BASE_ETMCQTCAPR_VERSIONS_MASK    (0xFFFF0000U)
#define NETC_SW_BASE_ETMCQTCAPR_VERSIONS_SHIFT   (16U)
#define NETC_SW_BASE_ETMCQTCAPR_VERSIONS_WIDTH   (16U)
#define NETC_SW_BASE_ETMCQTCAPR_VERSIONS(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_ETMCQTCAPR_VERSIONS_SHIFT)) & NETC_SW_BASE_ETMCQTCAPR_VERSIONS_MASK)
/*! @} */

/*! @name ETMCSTCAPR - ETM class scheduler table capability register */
/*! @{ */

#define NETC_SW_BASE_ETMCSTCAPR_VERSIONS_MASK    (0xFFFF0000U)
#define NETC_SW_BASE_ETMCSTCAPR_VERSIONS_SHIFT   (16U)
#define NETC_SW_BASE_ETMCSTCAPR_VERSIONS_WIDTH   (16U)
#define NETC_SW_BASE_ETMCSTCAPR_VERSIONS(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_ETMCSTCAPR_VERSIONS_SHIFT)) & NETC_SW_BASE_ETMCSTCAPR_VERSIONS_MASK)
/*! @} */

/*! @name ATSQSCAPR - ATS queue set capability register */
/*! @{ */

#define NETC_SW_BASE_ATSQSCAPR_NUM_ATS_QUEUE_SETS_MASK (0x3FU)
#define NETC_SW_BASE_ATSQSCAPR_NUM_ATS_QUEUE_SETS_SHIFT (0U)
#define NETC_SW_BASE_ATSQSCAPR_NUM_ATS_QUEUE_SETS_WIDTH (6U)
#define NETC_SW_BASE_ATSQSCAPR_NUM_ATS_QUEUE_SETS(x) (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_ATSQSCAPR_NUM_ATS_QUEUE_SETS_SHIFT)) & NETC_SW_BASE_ATSQSCAPR_NUM_ATS_QUEUE_SETS_MASK)

#define NETC_SW_BASE_ATSQSCAPR_NUM_ATSQ_MASK     (0x1F00U)
#define NETC_SW_BASE_ATSQSCAPR_NUM_ATSQ_SHIFT    (8U)
#define NETC_SW_BASE_ATSQSCAPR_NUM_ATSQ_WIDTH    (5U)
#define NETC_SW_BASE_ATSQSCAPR_NUM_ATSQ(x)       (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_ATSQSCAPR_NUM_ATSQ_SHIFT)) & NETC_SW_BASE_ATSQSCAPR_NUM_ATSQ_MASK)
/*! @} */

/*! @name ATSQSOR - ATS queue set operational register */
/*! @{ */

#define NETC_SW_BASE_ATSQSOR_NUM_ATSQS_BOUND_MASK (0x3FU)
#define NETC_SW_BASE_ATSQSOR_NUM_ATSQS_BOUND_SHIFT (0U)
#define NETC_SW_BASE_ATSQSOR_NUM_ATSQS_BOUND_WIDTH (6U)
#define NETC_SW_BASE_ATSQSOR_NUM_ATSQS_BOUND(x)  (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_ATSQSOR_NUM_ATSQS_BOUND_SHIFT)) & NETC_SW_BASE_ATSQSOR_NUM_ATSQS_BOUND_MASK)
/*! @} */

/*! @name ATSCR - ATS configuration register */
/*! @{ */

#define NETC_SW_BASE_ATSCR_PDELAY_MASK           (0x3FFU)
#define NETC_SW_BASE_ATSCR_PDELAY_SHIFT          (0U)
#define NETC_SW_BASE_ATSCR_PDELAY_WIDTH          (10U)
#define NETC_SW_BASE_ATSCR_PDELAY(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_ATSCR_PDELAY_SHIFT)) & NETC_SW_BASE_ATSCR_PDELAY_MASK)
/*! @} */

/*! @name SWID0PMR - Switch ID 0 to port mapping register */
/*! @{ */

#define NETC_SW_BASE_SWID0PMR_PORT_MASK          (0x1FU)
#define NETC_SW_BASE_SWID0PMR_PORT_SHIFT         (0U)
#define NETC_SW_BASE_SWID0PMR_PORT_WIDTH         (5U)
#define NETC_SW_BASE_SWID0PMR_PORT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SWID0PMR_PORT_SHIFT)) & NETC_SW_BASE_SWID0PMR_PORT_MASK)

#define NETC_SW_BASE_SWID0PMR_VALID_MASK         (0x80000000U)
#define NETC_SW_BASE_SWID0PMR_VALID_SHIFT        (31U)
#define NETC_SW_BASE_SWID0PMR_VALID_WIDTH        (1U)
#define NETC_SW_BASE_SWID0PMR_VALID(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_SWID0PMR_VALID_SHIFT)) & NETC_SW_BASE_SWID0PMR_VALID_MASK)
/*! @} */

/*! @name PGCAPR - Port group capability register */
/*! @{ */

#define NETC_SW_BASE_PGCAPR_NUM_PG_MASK          (0x7U)
#define NETC_SW_BASE_PGCAPR_NUM_PG_SHIFT         (0U)
#define NETC_SW_BASE_PGCAPR_NUM_PG_WIDTH         (3U)
#define NETC_SW_BASE_PGCAPR_NUM_PG(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_PGCAPR_NUM_PG_SHIFT)) & NETC_SW_BASE_PGCAPR_NUM_PG_MASK)
/*! @} */

/*! @name PGOR - Port group 1 operational register */
/*! @{ */

#define NETC_SW_BASE_PGOR_PORT_BITMAP_MASK       (0xFFFFFFU)
#define NETC_SW_BASE_PGOR_PORT_BITMAP_SHIFT      (0U)
#define NETC_SW_BASE_PGOR_PORT_BITMAP_WIDTH      (24U)
#define NETC_SW_BASE_PGOR_PORT_BITMAP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_PGOR_PORT_BITMAP_SHIFT)) & NETC_SW_BASE_PGOR_PORT_BITMAP_MASK)
/*! @} */

/*! @name IMDCR0 - Ingress mirror destination configuration register 0 */
/*! @{ */

#define NETC_SW_BASE_IMDCR0_MIREN_MASK           (0x1U)
#define NETC_SW_BASE_IMDCR0_MIREN_SHIFT          (0U)
#define NETC_SW_BASE_IMDCR0_MIREN_WIDTH          (1U)
#define NETC_SW_BASE_IMDCR0_MIREN(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_IMDCR0_MIREN_SHIFT)) & NETC_SW_BASE_IMDCR0_MIREN_MASK)

#define NETC_SW_BASE_IMDCR0_MIRDEST_MASK         (0x2U)
#define NETC_SW_BASE_IMDCR0_MIRDEST_SHIFT        (1U)
#define NETC_SW_BASE_IMDCR0_MIRDEST_WIDTH        (1U)
#define NETC_SW_BASE_IMDCR0_MIRDEST(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_IMDCR0_MIRDEST_SHIFT)) & NETC_SW_BASE_IMDCR0_MIRDEST_MASK)

#define NETC_SW_BASE_IMDCR0_IPV_MASK             (0x1CU)
#define NETC_SW_BASE_IMDCR0_IPV_SHIFT            (2U)
#define NETC_SW_BASE_IMDCR0_IPV_WIDTH            (3U)
#define NETC_SW_BASE_IMDCR0_IPV(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_IMDCR0_IPV_SHIFT)) & NETC_SW_BASE_IMDCR0_IPV_MASK)

#define NETC_SW_BASE_IMDCR0_DR_MASK              (0xC0U)
#define NETC_SW_BASE_IMDCR0_DR_SHIFT             (6U)
#define NETC_SW_BASE_IMDCR0_DR_WIDTH             (2U)
#define NETC_SW_BASE_IMDCR0_DR(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_IMDCR0_DR_SHIFT)) & NETC_SW_BASE_IMDCR0_DR_MASK)

#define NETC_SW_BASE_IMDCR0_PORT_MASK            (0x1F00U)
#define NETC_SW_BASE_IMDCR0_PORT_SHIFT           (8U)
#define NETC_SW_BASE_IMDCR0_PORT_WIDTH           (5U)
#define NETC_SW_BASE_IMDCR0_PORT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_IMDCR0_PORT_SHIFT)) & NETC_SW_BASE_IMDCR0_PORT_MASK)

#define NETC_SW_BASE_IMDCR0_SWID_MASK            (0xE000U)
#define NETC_SW_BASE_IMDCR0_SWID_SHIFT           (13U)
#define NETC_SW_BASE_IMDCR0_SWID_WIDTH           (3U)
#define NETC_SW_BASE_IMDCR0_SWID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_IMDCR0_SWID_SHIFT)) & NETC_SW_BASE_IMDCR0_SWID_MASK)
/*! @} */

/*! @name IMDCR1 - Ingress mirror destination configuration register 1 */
/*! @{ */

#define NETC_SW_BASE_IMDCR1_EFMEID_MASK          (0xFFFFU)
#define NETC_SW_BASE_IMDCR1_EFMEID_SHIFT         (0U)
#define NETC_SW_BASE_IMDCR1_EFMEID_WIDTH         (16U)
#define NETC_SW_BASE_IMDCR1_EFMEID(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_IMDCR1_EFMEID_SHIFT)) & NETC_SW_BASE_IMDCR1_EFMEID_MASK)

#define NETC_SW_BASE_IMDCR1_EFM_LEN_CHANGE_MASK  (0x7F0000U)
#define NETC_SW_BASE_IMDCR1_EFM_LEN_CHANGE_SHIFT (16U)
#define NETC_SW_BASE_IMDCR1_EFM_LEN_CHANGE_WIDTH (7U)
#define NETC_SW_BASE_IMDCR1_EFM_LEN_CHANGE(x)    (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_IMDCR1_EFM_LEN_CHANGE_SHIFT)) & NETC_SW_BASE_IMDCR1_EFM_LEN_CHANGE_MASK)
/*! @} */

/*! @name CTFCR - Cut-through forwarding count register */
/*! @{ */

#define NETC_SW_BASE_CTFCR_COUNT_MASK            (0xFFFFFFFFU)
#define NETC_SW_BASE_CTFCR_COUNT_SHIFT           (0U)
#define NETC_SW_BASE_CTFCR_COUNT_WIDTH           (32U)
#define NETC_SW_BASE_CTFCR_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CTFCR_COUNT_SHIFT)) & NETC_SW_BASE_CTFCR_COUNT_MASK)
/*! @} */

/*! @name CBDRMR - Command BDR 0 mode register..Command BDR 1 mode register */
/*! @{ */

#define NETC_SW_BASE_CBDRMR_EN_MASK              (0x80000000U)
#define NETC_SW_BASE_CBDRMR_EN_SHIFT             (31U)
#define NETC_SW_BASE_CBDRMR_EN_WIDTH             (1U)
#define NETC_SW_BASE_CBDRMR_EN(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CBDRMR_EN_SHIFT)) & NETC_SW_BASE_CBDRMR_EN_MASK)
/*! @} */

/*! @name CBDRSR - Command BDR 0 status register..Command BDR 1 status register */
/*! @{ */

#define NETC_SW_BASE_CBDRSR_BUSY_MASK            (0x1U)
#define NETC_SW_BASE_CBDRSR_BUSY_SHIFT           (0U)
#define NETC_SW_BASE_CBDRSR_BUSY_WIDTH           (1U)
#define NETC_SW_BASE_CBDRSR_BUSY(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CBDRSR_BUSY_SHIFT)) & NETC_SW_BASE_CBDRSR_BUSY_MASK)
/*! @} */

/*! @name CBDRBAR0 - Command BDR base address register 0 */
/*! @{ */

#define NETC_SW_BASE_CBDRBAR0_ADDRL_MASK         (0xFFFFFF80U)
#define NETC_SW_BASE_CBDRBAR0_ADDRL_SHIFT        (7U)
#define NETC_SW_BASE_CBDRBAR0_ADDRL_WIDTH        (25U)
#define NETC_SW_BASE_CBDRBAR0_ADDRL(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CBDRBAR0_ADDRL_SHIFT)) & NETC_SW_BASE_CBDRBAR0_ADDRL_MASK)
/*! @} */

/*! @name CBDRBAR1 - Command BDR 0 base address register 1..Command BDR 1 base address register 1 */
/*! @{ */

#define NETC_SW_BASE_CBDRBAR1_ADDRH_MASK         (0xFFFFFFFFU)
#define NETC_SW_BASE_CBDRBAR1_ADDRH_SHIFT        (0U)
#define NETC_SW_BASE_CBDRBAR1_ADDRH_WIDTH        (32U)
#define NETC_SW_BASE_CBDRBAR1_ADDRH(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CBDRBAR1_ADDRH_SHIFT)) & NETC_SW_BASE_CBDRBAR1_ADDRH_MASK)
/*! @} */

/*! @name CBDRPIR - Command BDR 0 producer index register..Command BDR 1 producer index register */
/*! @{ */

#define NETC_SW_BASE_CBDRPIR_BDR_INDEX_MASK      (0x3FFU)
#define NETC_SW_BASE_CBDRPIR_BDR_INDEX_SHIFT     (0U)
#define NETC_SW_BASE_CBDRPIR_BDR_INDEX_WIDTH     (10U)
#define NETC_SW_BASE_CBDRPIR_BDR_INDEX(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CBDRPIR_BDR_INDEX_SHIFT)) & NETC_SW_BASE_CBDRPIR_BDR_INDEX_MASK)
/*! @} */

/*! @name CBDRCIR - Command BDR 0 consumer index register..Command BDR 1 consumer index register */
/*! @{ */

#define NETC_SW_BASE_CBDRCIR_BDR_INDEX_MASK      (0x3FFU)
#define NETC_SW_BASE_CBDRCIR_BDR_INDEX_SHIFT     (0U)
#define NETC_SW_BASE_CBDRCIR_BDR_INDEX_WIDTH     (10U)
#define NETC_SW_BASE_CBDRCIR_BDR_INDEX(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CBDRCIR_BDR_INDEX_SHIFT)) & NETC_SW_BASE_CBDRCIR_BDR_INDEX_MASK)

#define NETC_SW_BASE_CBDRCIR_SBE_MASK            (0x80000000U)
#define NETC_SW_BASE_CBDRCIR_SBE_SHIFT           (31U)
#define NETC_SW_BASE_CBDRCIR_SBE_WIDTH           (1U)
#define NETC_SW_BASE_CBDRCIR_SBE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CBDRCIR_SBE_SHIFT)) & NETC_SW_BASE_CBDRCIR_SBE_MASK)
/*! @} */

/*! @name CBDRLENR - Command BDR 0 length register..Command BDR 1 length register */
/*! @{ */

#define NETC_SW_BASE_CBDRLENR_LENGTH_MASK        (0x7F8U)
#define NETC_SW_BASE_CBDRLENR_LENGTH_SHIFT       (3U)
#define NETC_SW_BASE_CBDRLENR_LENGTH_WIDTH       (8U)
#define NETC_SW_BASE_CBDRLENR_LENGTH(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CBDRLENR_LENGTH_SHIFT)) & NETC_SW_BASE_CBDRLENR_LENGTH_MASK)
/*! @} */

/*! @name CBDRIER - Command BDR 0 interrupt enable register..Command BDR 1 interrupt enable register */
/*! @{ */

#define NETC_SW_BASE_CBDRIER_CBDCIE_MASK         (0x1U)
#define NETC_SW_BASE_CBDRIER_CBDCIE_SHIFT        (0U)
#define NETC_SW_BASE_CBDRIER_CBDCIE_WIDTH        (1U)
#define NETC_SW_BASE_CBDRIER_CBDCIE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CBDRIER_CBDCIE_SHIFT)) & NETC_SW_BASE_CBDRIER_CBDCIE_MASK)
/*! @} */

/*! @name CBDRIDR - Command BDR 0 interrupt detect register..Command BDR 1 interrupt detect register */
/*! @{ */

#define NETC_SW_BASE_CBDRIDR_CBDC_MASK           (0x1U)
#define NETC_SW_BASE_CBDRIDR_CBDC_SHIFT          (0U)
#define NETC_SW_BASE_CBDRIDR_CBDC_WIDTH          (1U)
#define NETC_SW_BASE_CBDRIDR_CBDC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CBDRIDR_CBDC_SHIFT)) & NETC_SW_BASE_CBDRIDR_CBDC_MASK)
/*! @} */

/*! @name CBDRMSIVR - Command BDR 0 MSI-X vector register..Command BDR 1 MSI-X vector register */
/*! @{ */

#define NETC_SW_BASE_CBDRMSIVR_VECTOR_MASK       (0xFU)
#define NETC_SW_BASE_CBDRMSIVR_VECTOR_SHIFT      (0U)
#define NETC_SW_BASE_CBDRMSIVR_VECTOR_WIDTH      (4U)
#define NETC_SW_BASE_CBDRMSIVR_VECTOR(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_CBDRMSIVR_VECTOR_SHIFT)) & NETC_SW_BASE_CBDRMSIVR_VECTOR_MASK)
/*! @} */

/*! @name QOSVLANMPR - QoS to VLAN mapping profile 0 register 0..QoS to VLAN mapping profile 1 register 3 */
/*! @{ */

#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR0_MASK    (0xFU)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR0_SHIFT   (0U)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR0_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR0(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV0_DR0_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV0_DR0_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR0_MASK    (0xFU)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR0_SHIFT   (0U)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR0_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR0(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV2_DR0_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV2_DR0_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR0_MASK    (0xFU)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR0_SHIFT   (0U)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR0_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR0(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV4_DR0_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV4_DR0_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR0_MASK    (0xFU)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR0_SHIFT   (0U)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR0_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR0(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV6_DR0_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV6_DR0_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR1_MASK    (0xF0U)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR1_SHIFT   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR1_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR1(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV0_DR1_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV0_DR1_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR1_MASK    (0xF0U)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR1_SHIFT   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR1_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR1(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV2_DR1_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV2_DR1_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR1_MASK    (0xF0U)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR1_SHIFT   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR1_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR1(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV4_DR1_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV4_DR1_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR1_MASK    (0xF0U)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR1_SHIFT   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR1_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR1(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV6_DR1_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV6_DR1_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR2_MASK    (0xF00U)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR2_SHIFT   (8U)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR2_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR2(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV0_DR2_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV0_DR2_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR2_MASK    (0xF00U)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR2_SHIFT   (8U)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR2_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR2(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV2_DR2_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV2_DR2_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR2_MASK    (0xF00U)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR2_SHIFT   (8U)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR2_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR2(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV4_DR2_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV4_DR2_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR2_MASK    (0xF00U)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR2_SHIFT   (8U)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR2_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR2(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV6_DR2_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV6_DR2_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR3_MASK    (0xF000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR3_SHIFT   (12U)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR3_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV0_DR3(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV0_DR3_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV0_DR3_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR3_MASK    (0xF000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR3_SHIFT   (12U)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR3_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV2_DR3(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV2_DR3_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV2_DR3_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR3_MASK    (0xF000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR3_SHIFT   (12U)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR3_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV4_DR3(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV4_DR3_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV4_DR3_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR3_MASK    (0xF000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR3_SHIFT   (12U)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR3_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV6_DR3(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV6_DR3_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV6_DR3_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR0_MASK    (0xF0000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR0_SHIFT   (16U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR0_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR0(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV1_DR0_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV1_DR0_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR0_MASK    (0xF0000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR0_SHIFT   (16U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR0_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR0(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV3_DR0_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV3_DR0_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR0_MASK    (0xF0000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR0_SHIFT   (16U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR0_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR0(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV5_DR0_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV5_DR0_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR0_MASK    (0xF0000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR0_SHIFT   (16U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR0_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR0(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV7_DR0_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV7_DR0_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR1_MASK    (0xF00000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR1_SHIFT   (20U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR1_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR1(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV1_DR1_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV1_DR1_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR1_MASK    (0xF00000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR1_SHIFT   (20U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR1_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR1(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV3_DR1_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV3_DR1_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR1_MASK    (0xF00000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR1_SHIFT   (20U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR1_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR1(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV5_DR1_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV5_DR1_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR1_MASK    (0xF00000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR1_SHIFT   (20U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR1_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR1(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV7_DR1_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV7_DR1_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR2_MASK    (0xF000000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR2_SHIFT   (24U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR2_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR2(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV1_DR2_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV1_DR2_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR2_MASK    (0xF000000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR2_SHIFT   (24U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR2_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR2(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV3_DR2_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV3_DR2_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR2_MASK    (0xF000000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR2_SHIFT   (24U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR2_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR2(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV5_DR2_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV5_DR2_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR2_MASK    (0xF000000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR2_SHIFT   (24U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR2_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR2(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV7_DR2_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV7_DR2_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR3_MASK    (0xF0000000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR3_SHIFT   (28U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR3_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV1_DR3(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV1_DR3_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV1_DR3_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR3_MASK    (0xF0000000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR3_SHIFT   (28U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR3_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV3_DR3(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV3_DR3_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV3_DR3_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR3_MASK    (0xF0000000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR3_SHIFT   (28U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR3_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV5_DR3(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV5_DR3_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV5_DR3_MASK)

#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR3_MASK    (0xF0000000U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR3_SHIFT   (28U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR3_WIDTH   (4U)
#define NETC_SW_BASE_QOSVLANMPR_IPV7_DR3(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_QOSVLANMPR_IPV7_DR3_SHIFT)) & NETC_SW_BASE_QOSVLANMPR_IPV7_DR3_MASK)
/*! @} */

/*! @name PCP2PCPMPR - PCP to PCP mapping profile 0 register..PCP to PCP mapping profile 1 register */
/*! @{ */

#define NETC_SW_BASE_PCP2PCPMPR_PCP0_MASK        (0x7U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP0_SHIFT       (0U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP0_WIDTH       (3U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP0(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_PCP2PCPMPR_PCP0_SHIFT)) & NETC_SW_BASE_PCP2PCPMPR_PCP0_MASK)

#define NETC_SW_BASE_PCP2PCPMPR_PCP1_MASK        (0x70U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP1_SHIFT       (4U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP1_WIDTH       (3U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP1(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_PCP2PCPMPR_PCP1_SHIFT)) & NETC_SW_BASE_PCP2PCPMPR_PCP1_MASK)

#define NETC_SW_BASE_PCP2PCPMPR_PCP2_MASK        (0x700U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP2_SHIFT       (8U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP2_WIDTH       (3U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP2(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_PCP2PCPMPR_PCP2_SHIFT)) & NETC_SW_BASE_PCP2PCPMPR_PCP2_MASK)

#define NETC_SW_BASE_PCP2PCPMPR_PCP3_MASK        (0x7000U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP3_SHIFT       (12U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP3_WIDTH       (3U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP3(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_PCP2PCPMPR_PCP3_SHIFT)) & NETC_SW_BASE_PCP2PCPMPR_PCP3_MASK)

#define NETC_SW_BASE_PCP2PCPMPR_PCP4_MASK        (0x70000U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP4_SHIFT       (16U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP4_WIDTH       (3U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP4(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_PCP2PCPMPR_PCP4_SHIFT)) & NETC_SW_BASE_PCP2PCPMPR_PCP4_MASK)

#define NETC_SW_BASE_PCP2PCPMPR_PCP5_MASK        (0x700000U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP5_SHIFT       (20U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP5_WIDTH       (3U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP5(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_PCP2PCPMPR_PCP5_SHIFT)) & NETC_SW_BASE_PCP2PCPMPR_PCP5_MASK)

#define NETC_SW_BASE_PCP2PCPMPR_PCP6_MASK        (0x7000000U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP6_SHIFT       (24U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP6_WIDTH       (3U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP6(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_PCP2PCPMPR_PCP6_SHIFT)) & NETC_SW_BASE_PCP2PCPMPR_PCP6_MASK)

#define NETC_SW_BASE_PCP2PCPMPR_PCP7_MASK        (0x70000000U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP7_SHIFT       (28U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP7_WIDTH       (3U)
#define NETC_SW_BASE_PCP2PCPMPR_PCP7(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_PCP2PCPMPR_PCP7_SHIFT)) & NETC_SW_BASE_PCP2PCPMPR_PCP7_MASK)
/*! @} */

/*! @name BRCAPR - Bridge capability register */
/*! @{ */

#define NETC_SW_BASE_BRCAPR_IPV4MFLT_MASK        (0x1U)
#define NETC_SW_BASE_BRCAPR_IPV4MFLT_SHIFT       (0U)
#define NETC_SW_BASE_BRCAPR_IPV4MFLT_WIDTH       (1U)
#define NETC_SW_BASE_BRCAPR_IPV4MFLT(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_BRCAPR_IPV4MFLT_SHIFT)) & NETC_SW_BASE_BRCAPR_IPV4MFLT_MASK)

#define NETC_SW_BASE_BRCAPR_STAMVD_MASK          (0x4U)
#define NETC_SW_BASE_BRCAPR_STAMVD_SHIFT         (2U)
#define NETC_SW_BASE_BRCAPR_STAMVD_WIDTH         (1U)
#define NETC_SW_BASE_BRCAPR_STAMVD(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_BRCAPR_STAMVD_SHIFT)) & NETC_SW_BASE_BRCAPR_STAMVD_MASK)

#define NETC_SW_BASE_BRCAPR_STRMCTRL_MASK        (0x8U)
#define NETC_SW_BASE_BRCAPR_STRMCTRL_SHIFT       (3U)
#define NETC_SW_BASE_BRCAPR_STRMCTRL_WIDTH       (1U)
#define NETC_SW_BASE_BRCAPR_STRMCTRL(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_BRCAPR_STRMCTRL_SHIFT)) & NETC_SW_BASE_BRCAPR_STRMCTRL_MASK)

#define NETC_SW_BASE_BRCAPR_SRCPPRND_MASK        (0x10U)
#define NETC_SW_BASE_BRCAPR_SRCPPRND_SHIFT       (4U)
#define NETC_SW_BASE_BRCAPR_SRCPPRND_WIDTH       (1U)
#define NETC_SW_BASE_BRCAPR_SRCPPRND(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_BRCAPR_SRCPPRND_SHIFT)) & NETC_SW_BASE_BRCAPR_SRCPPRND_MASK)

#define NETC_SW_BASE_BRCAPR_EVLANXLATE_MASK      (0x20U)
#define NETC_SW_BASE_BRCAPR_EVLANXLATE_SHIFT     (5U)
#define NETC_SW_BASE_BRCAPR_EVLANXLATE_WIDTH     (1U)
#define NETC_SW_BASE_BRCAPR_EVLANXLATE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_BRCAPR_EVLANXLATE_SHIFT)) & NETC_SW_BASE_BRCAPR_EVLANXLATE_MASK)

#define NETC_SW_BASE_BRCAPR_NUM_STG_MASK         (0x3000U)
#define NETC_SW_BASE_BRCAPR_NUM_STG_SHIFT        (12U)
#define NETC_SW_BASE_BRCAPR_NUM_STG_WIDTH        (2U)
#define NETC_SW_BASE_BRCAPR_NUM_STG(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_BRCAPR_NUM_STG_SHIFT)) & NETC_SW_BASE_BRCAPR_NUM_STG_MASK)
/*! @} */

/*! @name VFHTCAPR - VLAN filter hash table capability register */
/*! @{ */

#define NETC_SW_BASE_VFHTCAPR_VERSIONS_MASK      (0xFFFF0000U)
#define NETC_SW_BASE_VFHTCAPR_VERSIONS_SHIFT     (16U)
#define NETC_SW_BASE_VFHTCAPR_VERSIONS_WIDTH     (16U)
#define NETC_SW_BASE_VFHTCAPR_VERSIONS(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTCAPR_VERSIONS_SHIFT)) & NETC_SW_BASE_VFHTCAPR_VERSIONS_MASK)
/*! @} */

/*! @name VFHTOR - VLAN filter hash table operational register */
/*! @{ */

#define NETC_SW_BASE_VFHTOR_NUM_ENTRIES_MASK     (0xFFFU)
#define NETC_SW_BASE_VFHTOR_NUM_ENTRIES_SHIFT    (0U)
#define NETC_SW_BASE_VFHTOR_NUM_ENTRIES_WIDTH    (12U)
#define NETC_SW_BASE_VFHTOR_NUM_ENTRIES(x)       (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTOR_NUM_ENTRIES_SHIFT)) & NETC_SW_BASE_VFHTOR_NUM_ENTRIES_MASK)
/*! @} */

/*! @name VFHTDECR0 - VLAN Filter (hash) table default entry configuration registers 0 */
/*! @{ */

#define NETC_SW_BASE_VFHTDECR0_PORT0_MASK        (0x1U)
#define NETC_SW_BASE_VFHTDECR0_PORT0_SHIFT       (0U)
#define NETC_SW_BASE_VFHTDECR0_PORT0_WIDTH       (1U)
#define NETC_SW_BASE_VFHTDECR0_PORT0(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR0_PORT0_SHIFT)) & NETC_SW_BASE_VFHTDECR0_PORT0_MASK)

#define NETC_SW_BASE_VFHTDECR0_PORT1_MASK        (0x2U)
#define NETC_SW_BASE_VFHTDECR0_PORT1_SHIFT       (1U)
#define NETC_SW_BASE_VFHTDECR0_PORT1_WIDTH       (1U)
#define NETC_SW_BASE_VFHTDECR0_PORT1(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR0_PORT1_SHIFT)) & NETC_SW_BASE_VFHTDECR0_PORT1_MASK)

#define NETC_SW_BASE_VFHTDECR0_PORT2_MASK        (0x4U)
#define NETC_SW_BASE_VFHTDECR0_PORT2_SHIFT       (2U)
#define NETC_SW_BASE_VFHTDECR0_PORT2_WIDTH       (1U)
#define NETC_SW_BASE_VFHTDECR0_PORT2(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR0_PORT2_SHIFT)) & NETC_SW_BASE_VFHTDECR0_PORT2_MASK)

#define NETC_SW_BASE_VFHTDECR0_PORT3_MASK        (0x8U)
#define NETC_SW_BASE_VFHTDECR0_PORT3_SHIFT       (3U)
#define NETC_SW_BASE_VFHTDECR0_PORT3_WIDTH       (1U)
#define NETC_SW_BASE_VFHTDECR0_PORT3(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR0_PORT3_SHIFT)) & NETC_SW_BASE_VFHTDECR0_PORT3_MASK)

#define NETC_SW_BASE_VFHTDECR0_PORT4_MASK        (0x10U)
#define NETC_SW_BASE_VFHTDECR0_PORT4_SHIFT       (4U)
#define NETC_SW_BASE_VFHTDECR0_PORT4_WIDTH       (1U)
#define NETC_SW_BASE_VFHTDECR0_PORT4(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR0_PORT4_SHIFT)) & NETC_SW_BASE_VFHTDECR0_PORT4_MASK)

#define NETC_SW_BASE_VFHTDECR0_PORT5_MASK        (0x20U)
#define NETC_SW_BASE_VFHTDECR0_PORT5_SHIFT       (5U)
#define NETC_SW_BASE_VFHTDECR0_PORT5_WIDTH       (1U)
#define NETC_SW_BASE_VFHTDECR0_PORT5(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR0_PORT5_SHIFT)) & NETC_SW_BASE_VFHTDECR0_PORT5_MASK)

#define NETC_SW_BASE_VFHTDECR0_STG_ID_MASK       (0xF000000U)
#define NETC_SW_BASE_VFHTDECR0_STG_ID_SHIFT      (24U)
#define NETC_SW_BASE_VFHTDECR0_STG_ID_WIDTH      (4U)
#define NETC_SW_BASE_VFHTDECR0_STG_ID(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR0_STG_ID_SHIFT)) & NETC_SW_BASE_VFHTDECR0_STG_ID_MASK)

#define NETC_SW_BASE_VFHTDECR0_IPMFE_MASK        (0x20000000U)
#define NETC_SW_BASE_VFHTDECR0_IPMFE_SHIFT       (29U)
#define NETC_SW_BASE_VFHTDECR0_IPMFE_WIDTH       (1U)
#define NETC_SW_BASE_VFHTDECR0_IPMFE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR0_IPMFE_SHIFT)) & NETC_SW_BASE_VFHTDECR0_IPMFE_MASK)

#define NETC_SW_BASE_VFHTDECR0_IPMFLE_MASK       (0x40000000U)
#define NETC_SW_BASE_VFHTDECR0_IPMFLE_SHIFT      (30U)
#define NETC_SW_BASE_VFHTDECR0_IPMFLE_WIDTH      (1U)
#define NETC_SW_BASE_VFHTDECR0_IPMFLE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR0_IPMFLE_SHIFT)) & NETC_SW_BASE_VFHTDECR0_IPMFLE_MASK)
/*! @} */

/*! @name VFHTDECR1 - VLAN filter hash table default entry configuration registers 1 */
/*! @{ */

#define NETC_SW_BASE_VFHTDECR1_FID_MASK          (0xFFFU)
#define NETC_SW_BASE_VFHTDECR1_FID_SHIFT         (0U)
#define NETC_SW_BASE_VFHTDECR1_FID_WIDTH         (12U)
#define NETC_SW_BASE_VFHTDECR1_FID(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR1_FID_SHIFT)) & NETC_SW_BASE_VFHTDECR1_FID_MASK)

#define NETC_SW_BASE_VFHTDECR1_VL_MODE_MASK      (0x1000U)
#define NETC_SW_BASE_VFHTDECR1_VL_MODE_SHIFT     (12U)
#define NETC_SW_BASE_VFHTDECR1_VL_MODE_WIDTH     (1U)
#define NETC_SW_BASE_VFHTDECR1_VL_MODE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR1_VL_MODE_SHIFT)) & NETC_SW_BASE_VFHTDECR1_VL_MODE_MASK)

#define NETC_SW_BASE_VFHTDECR1_PGA_MASK          (0x2000U)
#define NETC_SW_BASE_VFHTDECR1_PGA_SHIFT         (13U)
#define NETC_SW_BASE_VFHTDECR1_PGA_WIDTH         (1U)
#define NETC_SW_BASE_VFHTDECR1_PGA(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR1_PGA_SHIFT)) & NETC_SW_BASE_VFHTDECR1_PGA_MASK)

#define NETC_SW_BASE_VFHTDECR1_ET_EID_MASK       (0xFFFF0000U)
#define NETC_SW_BASE_VFHTDECR1_ET_EID_SHIFT      (16U)
#define NETC_SW_BASE_VFHTDECR1_ET_EID_WIDTH      (16U)
#define NETC_SW_BASE_VFHTDECR1_ET_EID(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR1_ET_EID_SHIFT)) & NETC_SW_BASE_VFHTDECR1_ET_EID_MASK)
/*! @} */

/*! @name VFHTDECR2 - VLAN filter hash table default entry configuration registers 2 */
/*! @{ */

#define NETC_SW_BASE_VFHTDECR2_ETA_PORT0_MASK    (0x1U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT0_SHIFT   (0U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT0_WIDTH   (1U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT0(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR2_ETA_PORT0_SHIFT)) & NETC_SW_BASE_VFHTDECR2_ETA_PORT0_MASK)

#define NETC_SW_BASE_VFHTDECR2_ETA_PORT1_MASK    (0x2U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT1_SHIFT   (1U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT1_WIDTH   (1U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT1(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR2_ETA_PORT1_SHIFT)) & NETC_SW_BASE_VFHTDECR2_ETA_PORT1_MASK)

#define NETC_SW_BASE_VFHTDECR2_ETA_PORT2_MASK    (0x4U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT2_SHIFT   (2U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT2_WIDTH   (1U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT2(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR2_ETA_PORT2_SHIFT)) & NETC_SW_BASE_VFHTDECR2_ETA_PORT2_MASK)

#define NETC_SW_BASE_VFHTDECR2_ETA_PORT3_MASK    (0x8U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT3_SHIFT   (3U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT3_WIDTH   (1U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT3(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR2_ETA_PORT3_SHIFT)) & NETC_SW_BASE_VFHTDECR2_ETA_PORT3_MASK)

#define NETC_SW_BASE_VFHTDECR2_ETA_PORT4_MASK    (0x10U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT4_SHIFT   (4U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT4_WIDTH   (1U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT4(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR2_ETA_PORT4_SHIFT)) & NETC_SW_BASE_VFHTDECR2_ETA_PORT4_MASK)

#define NETC_SW_BASE_VFHTDECR2_ETA_PORT5_MASK    (0x20U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT5_SHIFT   (5U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT5_WIDTH   (1U)
#define NETC_SW_BASE_VFHTDECR2_ETA_PORT5(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR2_ETA_PORT5_SHIFT)) & NETC_SW_BASE_VFHTDECR2_ETA_PORT5_MASK)

#define NETC_SW_BASE_VFHTDECR2_MLO_MASK          (0x7000000U)
#define NETC_SW_BASE_VFHTDECR2_MLO_SHIFT         (24U)
#define NETC_SW_BASE_VFHTDECR2_MLO_WIDTH         (3U)
#define NETC_SW_BASE_VFHTDECR2_MLO(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR2_MLO_SHIFT)) & NETC_SW_BASE_VFHTDECR2_MLO_MASK)

#define NETC_SW_BASE_VFHTDECR2_MFO_MASK          (0x18000000U)
#define NETC_SW_BASE_VFHTDECR2_MFO_SHIFT         (27U)
#define NETC_SW_BASE_VFHTDECR2_MFO_WIDTH         (2U)
#define NETC_SW_BASE_VFHTDECR2_MFO(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR2_MFO_SHIFT)) & NETC_SW_BASE_VFHTDECR2_MFO_MASK)

#define NETC_SW_BASE_VFHTDECR2_FDBAFSS_MASK      (0x20000000U)
#define NETC_SW_BASE_VFHTDECR2_FDBAFSS_SHIFT     (29U)
#define NETC_SW_BASE_VFHTDECR2_FDBAFSS_WIDTH     (1U)
#define NETC_SW_BASE_VFHTDECR2_FDBAFSS(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_VFHTDECR2_FDBAFSS_SHIFT)) & NETC_SW_BASE_VFHTDECR2_FDBAFSS_MASK)
/*! @} */

/*! @name FDBHTCAPR - FDB hash table capability register */
/*! @{ */

#define NETC_SW_BASE_FDBHTCAPR_NUM_GMAC_MASK     (0x1FFU)
#define NETC_SW_BASE_FDBHTCAPR_NUM_GMAC_SHIFT    (0U)
#define NETC_SW_BASE_FDBHTCAPR_NUM_GMAC_WIDTH    (9U)
#define NETC_SW_BASE_FDBHTCAPR_NUM_GMAC(x)       (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_FDBHTCAPR_NUM_GMAC_SHIFT)) & NETC_SW_BASE_FDBHTCAPR_NUM_GMAC_MASK)

#define NETC_SW_BASE_FDBHTCAPR_VERSIONS_MASK     (0xFFFF0000U)
#define NETC_SW_BASE_FDBHTCAPR_VERSIONS_SHIFT    (16U)
#define NETC_SW_BASE_FDBHTCAPR_VERSIONS_WIDTH    (16U)
#define NETC_SW_BASE_FDBHTCAPR_VERSIONS(x)       (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_FDBHTCAPR_VERSIONS_SHIFT)) & NETC_SW_BASE_FDBHTCAPR_VERSIONS_MASK)
/*! @} */

/*! @name FDBHTMCR - FDB hash table memory configuration register */
/*! @{ */

#define NETC_SW_BASE_FDBHTMCR_DYN_LIMIT_MASK     (0xFFFFU)
#define NETC_SW_BASE_FDBHTMCR_DYN_LIMIT_SHIFT    (0U)
#define NETC_SW_BASE_FDBHTMCR_DYN_LIMIT_WIDTH    (16U)
#define NETC_SW_BASE_FDBHTMCR_DYN_LIMIT(x)       (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_FDBHTMCR_DYN_LIMIT_SHIFT)) & NETC_SW_BASE_FDBHTMCR_DYN_LIMIT_MASK)
/*! @} */

/*! @name FDBHTOR0 - FDB hash table operational register 0 */
/*! @{ */

#define NETC_SW_BASE_FDBHTOR0_STATIC_ENTRIES_MASK (0xFFFFU)
#define NETC_SW_BASE_FDBHTOR0_STATIC_ENTRIES_SHIFT (0U)
#define NETC_SW_BASE_FDBHTOR0_STATIC_ENTRIES_WIDTH (16U)
#define NETC_SW_BASE_FDBHTOR0_STATIC_ENTRIES(x)  (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_FDBHTOR0_STATIC_ENTRIES_SHIFT)) & NETC_SW_BASE_FDBHTOR0_STATIC_ENTRIES_MASK)

#define NETC_SW_BASE_FDBHTOR0_NUM_GENTRIES_MASK  (0x1FF0000U)
#define NETC_SW_BASE_FDBHTOR0_NUM_GENTRIES_SHIFT (16U)
#define NETC_SW_BASE_FDBHTOR0_NUM_GENTRIES_WIDTH (9U)
#define NETC_SW_BASE_FDBHTOR0_NUM_GENTRIES(x)    (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_FDBHTOR0_NUM_GENTRIES_SHIFT)) & NETC_SW_BASE_FDBHTOR0_NUM_GENTRIES_MASK)
/*! @} */

/*! @name FDBHTOR1 - FDB hash table operational register 1 */
/*! @{ */

#define NETC_SW_BASE_FDBHTOR1_DYN_ENTRIES_MASK   (0xFFFFU)
#define NETC_SW_BASE_FDBHTOR1_DYN_ENTRIES_SHIFT  (0U)
#define NETC_SW_BASE_FDBHTOR1_DYN_ENTRIES_WIDTH  (16U)
#define NETC_SW_BASE_FDBHTOR1_DYN_ENTRIES(x)     (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_FDBHTOR1_DYN_ENTRIES_SHIFT)) & NETC_SW_BASE_FDBHTOR1_DYN_ENTRIES_MASK)

#define NETC_SW_BASE_FDBHTOR1_HWM_DYN_ENTRIES_MASK (0xFFFF0000U)
#define NETC_SW_BASE_FDBHTOR1_HWM_DYN_ENTRIES_SHIFT (16U)
#define NETC_SW_BASE_FDBHTOR1_HWM_DYN_ENTRIES_WIDTH (16U)
#define NETC_SW_BASE_FDBHTOR1_HWM_DYN_ENTRIES(x) (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_FDBHTOR1_HWM_DYN_ENTRIES_SHIFT)) & NETC_SW_BASE_FDBHTOR1_HWM_DYN_ENTRIES_MASK)
/*! @} */

/*! @name IPMFHTCAPR - IP multicast filter hash table capability register */
/*! @{ */

#define NETC_SW_BASE_IPMFHTCAPR_VERSIONS_MASK    (0xFFFF0000U)
#define NETC_SW_BASE_IPMFHTCAPR_VERSIONS_SHIFT   (16U)
#define NETC_SW_BASE_IPMFHTCAPR_VERSIONS_WIDTH   (16U)
#define NETC_SW_BASE_IPMFHTCAPR_VERSIONS(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_IPMFHTCAPR_VERSIONS_SHIFT)) & NETC_SW_BASE_IPMFHTCAPR_VERSIONS_MASK)
/*! @} */

/*! @name IPV4MFHTOR - IPv4 multicast filter hash table operation register */
/*! @{ */

#define NETC_SW_BASE_IPV4MFHTOR_ASM_ENTRIES_MASK (0xFFFFU)
#define NETC_SW_BASE_IPV4MFHTOR_ASM_ENTRIES_SHIFT (0U)
#define NETC_SW_BASE_IPV4MFHTOR_ASM_ENTRIES_WIDTH (16U)
#define NETC_SW_BASE_IPV4MFHTOR_ASM_ENTRIES(x)   (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_IPV4MFHTOR_ASM_ENTRIES_SHIFT)) & NETC_SW_BASE_IPV4MFHTOR_ASM_ENTRIES_MASK)

#define NETC_SW_BASE_IPV4MFHTOR_SSM_ENTRIES_MASK (0xFFFF0000U)
#define NETC_SW_BASE_IPV4MFHTOR_SSM_ENTRIES_SHIFT (16U)
#define NETC_SW_BASE_IPV4MFHTOR_SSM_ENTRIES_WIDTH (16U)
#define NETC_SW_BASE_IPV4MFHTOR_SSM_ENTRIES(x)   (((uint32_t)(((uint32_t)(x)) << NETC_SW_BASE_IPV4MFHTOR_SSM_ENTRIES_SHIFT)) & NETC_SW_BASE_IPV4MFHTOR_SSM_ENTRIES_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group NETC_SW_BASE_Register_Masks */

/*!
 * @}
 */ /* end of group NETC_SW_BASE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_NETC_SW_BASE_H_) */
