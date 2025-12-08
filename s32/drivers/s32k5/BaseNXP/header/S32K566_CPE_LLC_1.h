/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_CPE_LLC_1.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_CPE_LLC_1
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
#if !defined(S32K566_CPE_LLC_1_H_)  /* Check if memory map has not been already included */
#define S32K566_CPE_LLC_1_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CPE_LLC_1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPE_LLC_1_Peripheral_Access_Layer CPE_LLC_1 Peripheral Access Layer
 * @{
 */

/** CPE_LLC_1 - Register Layout Typedef */
typedef struct CPE_LLC_1_Struct {
  __IO uint32_t CCUTCR;                            /**< Transaction Control, offset: 0x0 */
  __I  uint32_t CCUTAR;                            /**< Transaction Activity, offset: 0x4 */
  uint8_t RESERVED_0[8];
  __IO uint32_t CCUCTCR;                           /**< Cache Transaction Control, offset: 0x10 */
  __I  uint32_t CCUCTAR;                           /**< Cache Transaction Activity, offset: 0x14 */
  __IO uint32_t CCUCAOR;                           /**< Allocation Override, offset: 0x18 */
  uint8_t RESERVED_1[4];
  __IO uint32_t CCUSPCR0;                          /**< Scratchpad Configuration 0, offset: 0x20 */
  __IO uint32_t CCUSPCR1;                          /**< Scratchpad Configuration 1, offset: 0x24 */
  __IO uint32_t CCUSPBR0;                          /**< Scratchpad Base Address 0, offset: 0x28 */
  uint8_t RESERVED_2[20];
  __IO uint32_t CCUWPCR00;                         /**< Way Partitioning Control, offset: 0x40 */
  __IO uint32_t CCUWPCR10;                         /**< Way Partitioning Control, offset: 0x44 */
  __IO uint32_t CCUWPCR01;                         /**< Way Partitioning Control, offset: 0x48 */
  __IO uint32_t CCUWPCR11;                         /**< Way Partitioning Control, offset: 0x4C */
  __IO uint32_t CCUWPCR02;                         /**< Way Partitioning Control, offset: 0x50 */
  __IO uint32_t CCUWPCR12;                         /**< Way Partitioning Control, offset: 0x54 */
  __IO uint32_t CCUWPCR03;                         /**< Way Partitioning Control, offset: 0x58 */
  __IO uint32_t CCUWPCR13;                         /**< Way Partitioning Control, offset: 0x5C */
  __IO uint32_t CCUWPCR04;                         /**< Way Partitioning Control, offset: 0x60 */
  __IO uint32_t CCUWPCR14;                         /**< Way Partitioning Control, offset: 0x64 */
  __IO uint32_t CCUWPCR05;                         /**< Way Partitioning Control, offset: 0x68 */
  __IO uint32_t CCUWPCR15;                         /**< Way Partitioning Control, offset: 0x6C */
  __IO uint32_t CCUWPCR06;                         /**< Way Partitioning Control, offset: 0x70 */
  __IO uint32_t CCUWPCR16;                         /**< Way Partitioning Control, offset: 0x74 */
  __IO uint32_t CCUWPCR07;                         /**< Way Partitioning Control, offset: 0x78 */
  __IO uint32_t CCUWPCR17;                         /**< Way Partitioning Control, offset: 0x7C */
  uint8_t RESERVED_3[128];
  __IO uint32_t CCUCMCR;                           /**< Maintenance Control, offset: 0x100 */
  __I  uint32_t CCUCMAR;                           /**< Maintenance Activity, offset: 0x104 */
  __IO uint32_t CCUCMLR0;                          /**< Maintenance Location 0, offset: 0x108 */
  __IO uint32_t CCUCMLR1;                          /**< Maintenance Location 1, offset: 0x10C */
  __IO uint32_t CCUCMLR2;                          /**< Maintenance Location 2, offset: 0x110 */
  __IO uint32_t CCUCMDR;                           /**< Maintenance Data, offset: 0x114 */
  __IO uint32_t CCUCMWVR;                          /**< Maintenance Way Valid, offset: 0x118 */
  uint8_t RESERVED_4[36];
  __IO uint32_t CCUCECR;                           /**< Correctable Error Control, offset: 0x140 */
  __IO uint32_t CCUCESR;                           /**< Correctable Error Status, offset: 0x144 */
  __IO uint32_t CCUCESAR;                          /**< Correctable Error Status Alias, offset: 0x148 */
  __I  uint32_t CCUCELR0;                          /**< Correctable Error Location 0, offset: 0x14C */
  __I  uint32_t CCUCELR1;                          /**< Correctable Error Location 1, offset: 0x150 */
  __IO uint32_t CCUUEDR;                           /**< Uncorrectable Error Detect, offset: 0x154 */
  __IO uint32_t CCUUEIR;                           /**< Uncorrectable Error Interrupt, offset: 0x158 */
  __IO uint32_t CCUUESR;                           /**< Uncorrectable Error Status, offset: 0x15C */
  __IO uint32_t CCUUESAR;                          /**< Uncorrectable Error Status Alias, offset: 0x160 */
  __I  uint32_t CCUUELR0;                          /**< Uncorrectable Error Location 0, offset: 0x164 */
  __I  uint32_t CCUUELR1;                          /**< Uncorrectable Error Location 1, offset: 0x168 */
  uint8_t RESERVED_5[80];
  __I  uint32_t CCUIIDR;                           /**< Instance Identification, offset: 0x1BC */
  __I  uint32_t CCUIDR;                            /**< Version Identification, offset: 0x1C0 */
  __IO uint32_t CCUCRTR;                           /**< Correctable Resiliency Threshold, offset: 0x1C4 */
  __IO uint32_t CCUESR;                            /**< Event Status, offset: 0x1C8 */
  __IO uint32_t CCUEMR;                            /**< Event Mask, offset: 0x1CC */
  __IO uint32_t CCUEAR;                            /**< Event Alias, offset: 0x1D0 */
  uint8_t RESERVED_6[556];
  __I  uint32_t CCUHI;                             /**< Hardware Information, offset: 0x400 */
  uint8_t RESERVED_7[60];
  __I  uint32_t CCUPMHI;                           /**< Performance Monitor Hardware Information, offset: 0x440 */
  uint8_t RESERVED_8[60];
  __IO uint32_t CCUPMCTL;                          /**< Performance Monitor Control, offset: 0x480 */
  __IO uint32_t CCUPMSC;                           /**< Performance Monitor Slot Configuration, offset: 0x484 */
  __IO uint32_t CCUPMOTC;                          /**< Performance Monitor OTT Threshold Configuration, offset: 0x488 */
  uint8_t RESERVED_9[116];
  __I  uint32_t CCUPMCYCO;                         /**< Performance Monitor Cycle Counter, offset: 0x500 */
  uint8_t RESERVED_10[60];
  __I  uint32_t CCUPMCYCA;                         /**< Performance Monitor Cycle Counter Capture, offset: 0x540 */
  uint8_t RESERVED_11[188];
  __I  uint32_t CCUPMRRCO;                         /**< Performance Monitor Read Request Counter, offset: 0x600 */
  __I  uint32_t CCUPMWRCO;                         /**< Performance Monitor Write Request Counter, offset: 0x604 */
  __I  uint32_t CCUPMCRRCO;                        /**< Performance Monitor Cacheable Read Request Counter, offset: 0x608 */
  __I  uint32_t CCUPMCWRCO;                        /**< Performance Monitor Cacheable Write Request Counter, offset: 0x60C */
  __I  uint32_t CCUPMRHCO;                         /**< Performance Monitor Read Hit Counter, offset: 0x610 */
  __I  uint32_t CCUPMWHCO;                         /**< Performance Monitor Write Hit Counter, offset: 0x614 */
  __I  uint32_t CCUPMECO;                          /**< Performance Monitor Eviction Counter, offset: 0x618 */
  __I  uint32_t CCUPMRBCO;                         /**< Performance Monitor Read Beat Counter, offset: 0x61C */
  __I  uint32_t CCUPMWBCO;                         /**< Performance Monitor Write Beat Counter, offset: 0x620 */
  __I  uint32_t CCUPMRATCO;                        /**< Performance Monitor RTT Above Threshold Counter, offset: 0x624 */
  __I  uint32_t CCUPMWATCO;                        /**< Performance Monitor WTT Above Threshold Counter, offset: 0x628 */
  uint8_t RESERVED_12[20];
  __I  uint32_t CCUPMRRCA;                         /**< Performance Monitor Read Request Counter Capture, offset: 0x640 */
  __I  uint32_t CCUPMWRCA;                         /**< Performance Monitor Write Request Counter Capture, offset: 0x644 */
  __I  uint32_t CCUPMCRRCA;                        /**< Performance Monitor Cacheable Read Request Counter Capture, offset: 0x648 */
  __I  uint32_t CCUPMCWRCA;                        /**< Performance Monitor Cacheable Write Request Counter Capture, offset: 0x64C */
  __I  uint32_t CCUPMRHCA;                         /**< Performance Monitor Read Hit Counter Capture, offset: 0x650 */
  __I  uint32_t CCUPMWHCA;                         /**< Performance Monitor Write Hit Counter Capture, offset: 0x654 */
  __I  uint32_t CCUPMECA;                          /**< Performance Monitor Eviction Counter Capture, offset: 0x658 */
  __I  uint32_t CCUPMRBCA;                         /**< Performance Monitor Read Beat Counter Capture, offset: 0x65C */
  __I  uint32_t CCUPMWBCA;                         /**< Performance Monitor Write Beat Counter Capture, offset: 0x660 */
  __I  uint32_t CCUPMRATCA;                        /**< Performance Monitor RTT Above Threshold Counter Capture, offset: 0x664 */
  __I  uint32_t CCUPMWATCA;                        /**< Performance Monitor WTT Above Threshold Counter Capture, offset: 0x668 */
} CPE_LLC_1_Type, *CPE_LLC_1_MemMapPtr;

/** Number of instances of the CPE_LLC_1 module. */
#define CPE_LLC_1_INSTANCE_COUNT                 (1u)

/* CPE_LLC_1 - Peripheral instance base addresses */
/** Peripheral CPE_LLC_1 base address */
#define IP_CPE_LLC_1_BASE                        (0x41008000u)
/** Peripheral CPE_LLC_1 base pointer */
#define IP_CPE_LLC_1                             ((CPE_LLC_1_Type *)IP_CPE_LLC_1_BASE)
/** Array initializer of CPE_LLC_1 peripheral base addresses */
#define IP_CPE_LLC_1_BASE_ADDRS                  { IP_CPE_LLC_1_BASE }
/** Array initializer of CPE_LLC_1 peripheral base pointers */
#define IP_CPE_LLC_1_BASE_PTRS                   { IP_CPE_LLC_1 }

/* ----------------------------------------------------------------------------
   -- CPE_LLC_1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPE_LLC_1_Register_Masks CPE_LLC_1 Register Masks
 * @{
 */

/*! @name CCUTCR - Transaction Control */
/*! @{ */

#define CPE_LLC_1_CCUTCR_TRANSEN_MASK            (0x1U)
#define CPE_LLC_1_CCUTCR_TRANSEN_SHIFT           (0U)
#define CPE_LLC_1_CCUTCR_TRANSEN_WIDTH           (1U)
#define CPE_LLC_1_CCUTCR_TRANSEN(x)              (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUTCR_TRANSEN_SHIFT)) & CPE_LLC_1_CCUTCR_TRANSEN_MASK)
/*! @} */

/*! @name CCUTAR - Transaction Activity */
/*! @{ */

#define CPE_LLC_1_CCUTAR_TRANSACTV_MASK          (0x1U)
#define CPE_LLC_1_CCUTAR_TRANSACTV_SHIFT         (0U)
#define CPE_LLC_1_CCUTAR_TRANSACTV_WIDTH         (1U)
#define CPE_LLC_1_CCUTAR_TRANSACTV(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUTAR_TRANSACTV_SHIFT)) & CPE_LLC_1_CCUTAR_TRANSACTV_MASK)
/*! @} */

/*! @name CCUCTCR - Cache Transaction Control */
/*! @{ */

#define CPE_LLC_1_CCUCTCR_LOOKUPEN_MASK          (0x1U)
#define CPE_LLC_1_CCUCTCR_LOOKUPEN_SHIFT         (0U)
#define CPE_LLC_1_CCUCTCR_LOOKUPEN_WIDTH         (1U)
#define CPE_LLC_1_CCUCTCR_LOOKUPEN(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCTCR_LOOKUPEN_SHIFT)) & CPE_LLC_1_CCUCTCR_LOOKUPEN_MASK)

#define CPE_LLC_1_CCUCTCR_FILLEN_MASK            (0x2U)
#define CPE_LLC_1_CCUCTCR_FILLEN_SHIFT           (1U)
#define CPE_LLC_1_CCUCTCR_FILLEN_WIDTH           (1U)
#define CPE_LLC_1_CCUCTCR_FILLEN(x)              (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCTCR_FILLEN_SHIFT)) & CPE_LLC_1_CCUCTCR_FILLEN_MASK)
/*! @} */

/*! @name CCUCTAR - Cache Transaction Activity */
/*! @{ */

#define CPE_LLC_1_CCUCTAR_EVICTACTV_MASK         (0x1U)
#define CPE_LLC_1_CCUCTAR_EVICTACTV_SHIFT        (0U)
#define CPE_LLC_1_CCUCTAR_EVICTACTV_WIDTH        (1U)
#define CPE_LLC_1_CCUCTAR_EVICTACTV(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCTAR_EVICTACTV_SHIFT)) & CPE_LLC_1_CCUCTAR_EVICTACTV_MASK)

#define CPE_LLC_1_CCUCTAR_FILLACTV_MASK          (0x2U)
#define CPE_LLC_1_CCUCTAR_FILLACTV_SHIFT         (1U)
#define CPE_LLC_1_CCUCTAR_FILLACTV_WIDTH         (1U)
#define CPE_LLC_1_CCUCTAR_FILLACTV(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCTAR_FILLACTV_SHIFT)) & CPE_LLC_1_CCUCTAR_FILLACTV_MASK)

#define CPE_LLC_1_CCUCTAR_FLUSHACTV_MASK         (0x4U)
#define CPE_LLC_1_CCUCTAR_FLUSHACTV_SHIFT        (2U)
#define CPE_LLC_1_CCUCTAR_FLUSHACTV_WIDTH        (1U)
#define CPE_LLC_1_CCUCTAR_FLUSHACTV(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCTAR_FLUSHACTV_SHIFT)) & CPE_LLC_1_CCUCTAR_FLUSHACTV_MASK)
/*! @} */

/*! @name CCUCAOR - Allocation Override */
/*! @{ */

#define CPE_LLC_1_CCUCAOR_AWALLOCEN_MASK         (0x1U)
#define CPE_LLC_1_CCUCAOR_AWALLOCEN_SHIFT        (0U)
#define CPE_LLC_1_CCUCAOR_AWALLOCEN_WIDTH        (1U)
#define CPE_LLC_1_CCUCAOR_AWALLOCEN(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCAOR_AWALLOCEN_SHIFT)) & CPE_LLC_1_CCUCAOR_AWALLOCEN_MASK)

#define CPE_LLC_1_CCUCAOR_ARALLOCEN_MASK         (0x2U)
#define CPE_LLC_1_CCUCAOR_ARALLOCEN_SHIFT        (1U)
#define CPE_LLC_1_CCUCAOR_ARALLOCEN_WIDTH        (1U)
#define CPE_LLC_1_CCUCAOR_ARALLOCEN(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCAOR_ARALLOCEN_SHIFT)) & CPE_LLC_1_CCUCAOR_ARALLOCEN_MASK)

#define CPE_LLC_1_CCUCAOR_WRALLOCPARTIALEN_MASK  (0x4U)
#define CPE_LLC_1_CCUCAOR_WRALLOCPARTIALEN_SHIFT (2U)
#define CPE_LLC_1_CCUCAOR_WRALLOCPARTIALEN_WIDTH (1U)
#define CPE_LLC_1_CCUCAOR_WRALLOCPARTIALEN(x)    (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCAOR_WRALLOCPARTIALEN_SHIFT)) & CPE_LLC_1_CCUCAOR_WRALLOCPARTIALEN_MASK)

#define CPE_LLC_1_CCUCAOR_AWALLOCVALUE_MASK      (0xF0000U)
#define CPE_LLC_1_CCUCAOR_AWALLOCVALUE_SHIFT     (16U)
#define CPE_LLC_1_CCUCAOR_AWALLOCVALUE_WIDTH     (4U)
#define CPE_LLC_1_CCUCAOR_AWALLOCVALUE(x)        (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCAOR_AWALLOCVALUE_SHIFT)) & CPE_LLC_1_CCUCAOR_AWALLOCVALUE_MASK)

#define CPE_LLC_1_CCUCAOR_ARALLOCVALUE_MASK      (0xF00000U)
#define CPE_LLC_1_CCUCAOR_ARALLOCVALUE_SHIFT     (20U)
#define CPE_LLC_1_CCUCAOR_ARALLOCVALUE_WIDTH     (4U)
#define CPE_LLC_1_CCUCAOR_ARALLOCVALUE(x)        (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCAOR_ARALLOCVALUE_SHIFT)) & CPE_LLC_1_CCUCAOR_ARALLOCVALUE_MASK)
/*! @} */

/*! @name CCUSPCR0 - Scratchpad Configuration 0 */
/*! @{ */

#define CPE_LLC_1_CCUSPCR0_SCPADEN_MASK          (0x1U)
#define CPE_LLC_1_CCUSPCR0_SCPADEN_SHIFT         (0U)
#define CPE_LLC_1_CCUSPCR0_SCPADEN_WIDTH         (1U)
#define CPE_LLC_1_CCUSPCR0_SCPADEN(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUSPCR0_SCPADEN_SHIFT)) & CPE_LLC_1_CCUSPCR0_SCPADEN_MASK)

#define CPE_LLC_1_CCUSPCR0_NUMSCPADWAYS_MASK     (0x70000U)
#define CPE_LLC_1_CCUSPCR0_NUMSCPADWAYS_SHIFT    (16U)
#define CPE_LLC_1_CCUSPCR0_NUMSCPADWAYS_WIDTH    (3U)
#define CPE_LLC_1_CCUSPCR0_NUMSCPADWAYS(x)       (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUSPCR0_NUMSCPADWAYS_SHIFT)) & CPE_LLC_1_CCUSPCR0_NUMSCPADWAYS_MASK)
/*! @} */

/*! @name CCUSPCR1 - Scratchpad Configuration 1 */
/*! @{ */

#define CPE_LLC_1_CCUSPCR1_SCPADSIZE_MASK        (0xFFFFFFFFU)
#define CPE_LLC_1_CCUSPCR1_SCPADSIZE_SHIFT       (0U)
#define CPE_LLC_1_CCUSPCR1_SCPADSIZE_WIDTH       (32U)
#define CPE_LLC_1_CCUSPCR1_SCPADSIZE(x)          (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUSPCR1_SCPADSIZE_SHIFT)) & CPE_LLC_1_CCUSPCR1_SCPADSIZE_MASK)
/*! @} */

/*! @name CCUSPBR0 - Scratchpad Base Address 0 */
/*! @{ */

#define CPE_LLC_1_CCUSPBR0_SCPADBASEADDR_MASK    (0xFFFFFFFFU)
#define CPE_LLC_1_CCUSPBR0_SCPADBASEADDR_SHIFT   (0U)
#define CPE_LLC_1_CCUSPBR0_SCPADBASEADDR_WIDTH   (32U)
#define CPE_LLC_1_CCUSPBR0_SCPADBASEADDR(x)      (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUSPBR0_SCPADBASEADDR_SHIFT)) & CPE_LLC_1_CCUSPBR0_SCPADBASEADDR_MASK)
/*! @} */

/*! @name CCUWPCR00 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR00_WPAGENTID_MASK       (0xFU)
#define CPE_LLC_1_CCUWPCR00_WPAGENTID_SHIFT      (0U)
#define CPE_LLC_1_CCUWPCR00_WPAGENTID_WIDTH      (4U)
#define CPE_LLC_1_CCUWPCR00_WPAGENTID(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR00_WPAGENTID_SHIFT)) & CPE_LLC_1_CCUWPCR00_WPAGENTID_MASK)

#define CPE_LLC_1_CCUWPCR00_WPAGENTIDVALID_MASK  (0x80000000U)
#define CPE_LLC_1_CCUWPCR00_WPAGENTIDVALID_SHIFT (31U)
#define CPE_LLC_1_CCUWPCR00_WPAGENTIDVALID_WIDTH (1U)
#define CPE_LLC_1_CCUWPCR00_WPAGENTIDVALID(x)    (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR00_WPAGENTIDVALID_SHIFT)) & CPE_LLC_1_CCUWPCR00_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR10 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR10_WPWAYVECTOR_MASK     (0xFFU)
#define CPE_LLC_1_CCUWPCR10_WPWAYVECTOR_SHIFT    (0U)
#define CPE_LLC_1_CCUWPCR10_WPWAYVECTOR_WIDTH    (8U)
#define CPE_LLC_1_CCUWPCR10_WPWAYVECTOR(x)       (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR10_WPWAYVECTOR_SHIFT)) & CPE_LLC_1_CCUWPCR10_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR01 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR01_WPAGENTID_MASK       (0xFU)
#define CPE_LLC_1_CCUWPCR01_WPAGENTID_SHIFT      (0U)
#define CPE_LLC_1_CCUWPCR01_WPAGENTID_WIDTH      (4U)
#define CPE_LLC_1_CCUWPCR01_WPAGENTID(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR01_WPAGENTID_SHIFT)) & CPE_LLC_1_CCUWPCR01_WPAGENTID_MASK)

#define CPE_LLC_1_CCUWPCR01_WPAGENTIDVALID_MASK  (0x80000000U)
#define CPE_LLC_1_CCUWPCR01_WPAGENTIDVALID_SHIFT (31U)
#define CPE_LLC_1_CCUWPCR01_WPAGENTIDVALID_WIDTH (1U)
#define CPE_LLC_1_CCUWPCR01_WPAGENTIDVALID(x)    (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR01_WPAGENTIDVALID_SHIFT)) & CPE_LLC_1_CCUWPCR01_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR11 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR11_WPWAYVECTOR_MASK     (0xFFU)
#define CPE_LLC_1_CCUWPCR11_WPWAYVECTOR_SHIFT    (0U)
#define CPE_LLC_1_CCUWPCR11_WPWAYVECTOR_WIDTH    (8U)
#define CPE_LLC_1_CCUWPCR11_WPWAYVECTOR(x)       (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR11_WPWAYVECTOR_SHIFT)) & CPE_LLC_1_CCUWPCR11_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR02 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR02_WPAGENTID_MASK       (0xFU)
#define CPE_LLC_1_CCUWPCR02_WPAGENTID_SHIFT      (0U)
#define CPE_LLC_1_CCUWPCR02_WPAGENTID_WIDTH      (4U)
#define CPE_LLC_1_CCUWPCR02_WPAGENTID(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR02_WPAGENTID_SHIFT)) & CPE_LLC_1_CCUWPCR02_WPAGENTID_MASK)

#define CPE_LLC_1_CCUWPCR02_WPAGENTIDVALID_MASK  (0x80000000U)
#define CPE_LLC_1_CCUWPCR02_WPAGENTIDVALID_SHIFT (31U)
#define CPE_LLC_1_CCUWPCR02_WPAGENTIDVALID_WIDTH (1U)
#define CPE_LLC_1_CCUWPCR02_WPAGENTIDVALID(x)    (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR02_WPAGENTIDVALID_SHIFT)) & CPE_LLC_1_CCUWPCR02_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR12 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR12_WPWAYVECTOR_MASK     (0xFFU)
#define CPE_LLC_1_CCUWPCR12_WPWAYVECTOR_SHIFT    (0U)
#define CPE_LLC_1_CCUWPCR12_WPWAYVECTOR_WIDTH    (8U)
#define CPE_LLC_1_CCUWPCR12_WPWAYVECTOR(x)       (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR12_WPWAYVECTOR_SHIFT)) & CPE_LLC_1_CCUWPCR12_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR03 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR03_WPAGENTID_MASK       (0xFU)
#define CPE_LLC_1_CCUWPCR03_WPAGENTID_SHIFT      (0U)
#define CPE_LLC_1_CCUWPCR03_WPAGENTID_WIDTH      (4U)
#define CPE_LLC_1_CCUWPCR03_WPAGENTID(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR03_WPAGENTID_SHIFT)) & CPE_LLC_1_CCUWPCR03_WPAGENTID_MASK)

#define CPE_LLC_1_CCUWPCR03_WPAGENTIDVALID_MASK  (0x80000000U)
#define CPE_LLC_1_CCUWPCR03_WPAGENTIDVALID_SHIFT (31U)
#define CPE_LLC_1_CCUWPCR03_WPAGENTIDVALID_WIDTH (1U)
#define CPE_LLC_1_CCUWPCR03_WPAGENTIDVALID(x)    (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR03_WPAGENTIDVALID_SHIFT)) & CPE_LLC_1_CCUWPCR03_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR13 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR13_WPWAYVECTOR_MASK     (0xFFU)
#define CPE_LLC_1_CCUWPCR13_WPWAYVECTOR_SHIFT    (0U)
#define CPE_LLC_1_CCUWPCR13_WPWAYVECTOR_WIDTH    (8U)
#define CPE_LLC_1_CCUWPCR13_WPWAYVECTOR(x)       (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR13_WPWAYVECTOR_SHIFT)) & CPE_LLC_1_CCUWPCR13_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR04 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR04_WPAGENTID_MASK       (0xFU)
#define CPE_LLC_1_CCUWPCR04_WPAGENTID_SHIFT      (0U)
#define CPE_LLC_1_CCUWPCR04_WPAGENTID_WIDTH      (4U)
#define CPE_LLC_1_CCUWPCR04_WPAGENTID(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR04_WPAGENTID_SHIFT)) & CPE_LLC_1_CCUWPCR04_WPAGENTID_MASK)

#define CPE_LLC_1_CCUWPCR04_WPAGENTIDVALID_MASK  (0x80000000U)
#define CPE_LLC_1_CCUWPCR04_WPAGENTIDVALID_SHIFT (31U)
#define CPE_LLC_1_CCUWPCR04_WPAGENTIDVALID_WIDTH (1U)
#define CPE_LLC_1_CCUWPCR04_WPAGENTIDVALID(x)    (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR04_WPAGENTIDVALID_SHIFT)) & CPE_LLC_1_CCUWPCR04_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR14 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR14_WPWAYVECTOR_MASK     (0xFFU)
#define CPE_LLC_1_CCUWPCR14_WPWAYVECTOR_SHIFT    (0U)
#define CPE_LLC_1_CCUWPCR14_WPWAYVECTOR_WIDTH    (8U)
#define CPE_LLC_1_CCUWPCR14_WPWAYVECTOR(x)       (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR14_WPWAYVECTOR_SHIFT)) & CPE_LLC_1_CCUWPCR14_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR05 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR05_WPAGENTID_MASK       (0xFU)
#define CPE_LLC_1_CCUWPCR05_WPAGENTID_SHIFT      (0U)
#define CPE_LLC_1_CCUWPCR05_WPAGENTID_WIDTH      (4U)
#define CPE_LLC_1_CCUWPCR05_WPAGENTID(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR05_WPAGENTID_SHIFT)) & CPE_LLC_1_CCUWPCR05_WPAGENTID_MASK)

#define CPE_LLC_1_CCUWPCR05_WPAGENTIDVALID_MASK  (0x80000000U)
#define CPE_LLC_1_CCUWPCR05_WPAGENTIDVALID_SHIFT (31U)
#define CPE_LLC_1_CCUWPCR05_WPAGENTIDVALID_WIDTH (1U)
#define CPE_LLC_1_CCUWPCR05_WPAGENTIDVALID(x)    (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR05_WPAGENTIDVALID_SHIFT)) & CPE_LLC_1_CCUWPCR05_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR15 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR15_WPWAYVECTOR_MASK     (0xFFU)
#define CPE_LLC_1_CCUWPCR15_WPWAYVECTOR_SHIFT    (0U)
#define CPE_LLC_1_CCUWPCR15_WPWAYVECTOR_WIDTH    (8U)
#define CPE_LLC_1_CCUWPCR15_WPWAYVECTOR(x)       (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR15_WPWAYVECTOR_SHIFT)) & CPE_LLC_1_CCUWPCR15_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR06 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR06_WPAGENTID_MASK       (0xFU)
#define CPE_LLC_1_CCUWPCR06_WPAGENTID_SHIFT      (0U)
#define CPE_LLC_1_CCUWPCR06_WPAGENTID_WIDTH      (4U)
#define CPE_LLC_1_CCUWPCR06_WPAGENTID(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR06_WPAGENTID_SHIFT)) & CPE_LLC_1_CCUWPCR06_WPAGENTID_MASK)

#define CPE_LLC_1_CCUWPCR06_WPAGENTIDVALID_MASK  (0x80000000U)
#define CPE_LLC_1_CCUWPCR06_WPAGENTIDVALID_SHIFT (31U)
#define CPE_LLC_1_CCUWPCR06_WPAGENTIDVALID_WIDTH (1U)
#define CPE_LLC_1_CCUWPCR06_WPAGENTIDVALID(x)    (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR06_WPAGENTIDVALID_SHIFT)) & CPE_LLC_1_CCUWPCR06_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR16 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR16_WPWAYVECTOR_MASK     (0xFFU)
#define CPE_LLC_1_CCUWPCR16_WPWAYVECTOR_SHIFT    (0U)
#define CPE_LLC_1_CCUWPCR16_WPWAYVECTOR_WIDTH    (8U)
#define CPE_LLC_1_CCUWPCR16_WPWAYVECTOR(x)       (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR16_WPWAYVECTOR_SHIFT)) & CPE_LLC_1_CCUWPCR16_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR07 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR07_WPAGENTID_MASK       (0xFU)
#define CPE_LLC_1_CCUWPCR07_WPAGENTID_SHIFT      (0U)
#define CPE_LLC_1_CCUWPCR07_WPAGENTID_WIDTH      (4U)
#define CPE_LLC_1_CCUWPCR07_WPAGENTID(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR07_WPAGENTID_SHIFT)) & CPE_LLC_1_CCUWPCR07_WPAGENTID_MASK)

#define CPE_LLC_1_CCUWPCR07_WPAGENTIDVALID_MASK  (0x80000000U)
#define CPE_LLC_1_CCUWPCR07_WPAGENTIDVALID_SHIFT (31U)
#define CPE_LLC_1_CCUWPCR07_WPAGENTIDVALID_WIDTH (1U)
#define CPE_LLC_1_CCUWPCR07_WPAGENTIDVALID(x)    (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR07_WPAGENTIDVALID_SHIFT)) & CPE_LLC_1_CCUWPCR07_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR17 - Way Partitioning Control */
/*! @{ */

#define CPE_LLC_1_CCUWPCR17_WPWAYVECTOR_MASK     (0xFFU)
#define CPE_LLC_1_CCUWPCR17_WPWAYVECTOR_SHIFT    (0U)
#define CPE_LLC_1_CCUWPCR17_WPWAYVECTOR_WIDTH    (8U)
#define CPE_LLC_1_CCUWPCR17_WPWAYVECTOR(x)       (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUWPCR17_WPWAYVECTOR_SHIFT)) & CPE_LLC_1_CCUWPCR17_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUCMCR - Maintenance Control */
/*! @{ */

#define CPE_LLC_1_CCUCMCR_MNTOP_MASK             (0xFU)
#define CPE_LLC_1_CCUCMCR_MNTOP_SHIFT            (0U)
#define CPE_LLC_1_CCUCMCR_MNTOP_WIDTH            (4U)
#define CPE_LLC_1_CCUCMCR_MNTOP(x)               (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCMCR_MNTOP_SHIFT)) & CPE_LLC_1_CCUCMCR_MNTOP_MASK)

#define CPE_LLC_1_CCUCMCR_ARRAYID_MASK           (0x3F0000U)
#define CPE_LLC_1_CCUCMCR_ARRAYID_SHIFT          (16U)
#define CPE_LLC_1_CCUCMCR_ARRAYID_WIDTH          (6U)
#define CPE_LLC_1_CCUCMCR_ARRAYID(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCMCR_ARRAYID_SHIFT)) & CPE_LLC_1_CCUCMCR_ARRAYID_MASK)

#define CPE_LLC_1_CCUCMCR_SECATTR_MASK           (0x400000U)
#define CPE_LLC_1_CCUCMCR_SECATTR_SHIFT          (22U)
#define CPE_LLC_1_CCUCMCR_SECATTR_WIDTH          (1U)
#define CPE_LLC_1_CCUCMCR_SECATTR(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCMCR_SECATTR_SHIFT)) & CPE_LLC_1_CCUCMCR_SECATTR_MASK)
/*! @} */

/*! @name CCUCMAR - Maintenance Activity */
/*! @{ */

#define CPE_LLC_1_CCUCMAR_MNTOPACTV_MASK         (0x1U)
#define CPE_LLC_1_CCUCMAR_MNTOPACTV_SHIFT        (0U)
#define CPE_LLC_1_CCUCMAR_MNTOPACTV_WIDTH        (1U)
#define CPE_LLC_1_CCUCMAR_MNTOPACTV(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCMAR_MNTOPACTV_SHIFT)) & CPE_LLC_1_CCUCMAR_MNTOPACTV_MASK)
/*! @} */

/*! @name CCUCMLR0 - Maintenance Location 0 */
/*! @{ */

#define CPE_LLC_1_CCUCMLR0_MNTSET_MASK           (0x7FFFU)
#define CPE_LLC_1_CCUCMLR0_MNTSET_SHIFT          (0U)
#define CPE_LLC_1_CCUCMLR0_MNTSET_WIDTH          (15U)
#define CPE_LLC_1_CCUCMLR0_MNTSET(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCMLR0_MNTSET_SHIFT)) & CPE_LLC_1_CCUCMLR0_MNTSET_MASK)

#define CPE_LLC_1_CCUCMLR0_MNTWAY_MASK           (0x1F8000U)
#define CPE_LLC_1_CCUCMLR0_MNTWAY_SHIFT          (15U)
#define CPE_LLC_1_CCUCMLR0_MNTWAY_WIDTH          (6U)
#define CPE_LLC_1_CCUCMLR0_MNTWAY(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCMLR0_MNTWAY_SHIFT)) & CPE_LLC_1_CCUCMLR0_MNTWAY_MASK)

#define CPE_LLC_1_CCUCMLR0_MNTWORD_MASK          (0xFFE00000U)
#define CPE_LLC_1_CCUCMLR0_MNTWORD_SHIFT         (21U)
#define CPE_LLC_1_CCUCMLR0_MNTWORD_WIDTH         (11U)
#define CPE_LLC_1_CCUCMLR0_MNTWORD(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCMLR0_MNTWORD_SHIFT)) & CPE_LLC_1_CCUCMLR0_MNTWORD_MASK)
/*! @} */

/*! @name CCUCMLR1 - Maintenance Location 1 */
/*! @{ */

#define CPE_LLC_1_CCUCMLR1_MNTADDR_MASK          (0xFFFFU)
#define CPE_LLC_1_CCUCMLR1_MNTADDR_SHIFT         (0U)
#define CPE_LLC_1_CCUCMLR1_MNTADDR_WIDTH         (16U)
#define CPE_LLC_1_CCUCMLR1_MNTADDR(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCMLR1_MNTADDR_SHIFT)) & CPE_LLC_1_CCUCMLR1_MNTADDR_MASK)
/*! @} */

/*! @name CCUCMLR2 - Maintenance Location 2 */
/*! @{ */

#define CPE_LLC_1_CCUCMLR2_MNTRANGE_MASK         (0xFFFFU)
#define CPE_LLC_1_CCUCMLR2_MNTRANGE_SHIFT        (0U)
#define CPE_LLC_1_CCUCMLR2_MNTRANGE_WIDTH        (16U)
#define CPE_LLC_1_CCUCMLR2_MNTRANGE(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCMLR2_MNTRANGE_SHIFT)) & CPE_LLC_1_CCUCMLR2_MNTRANGE_MASK)
/*! @} */

/*! @name CCUCMDR - Maintenance Data */
/*! @{ */

#define CPE_LLC_1_CCUCMDR_MNTDATA_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUCMDR_MNTDATA_SHIFT          (0U)
#define CPE_LLC_1_CCUCMDR_MNTDATA_WIDTH          (32U)
#define CPE_LLC_1_CCUCMDR_MNTDATA(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCMDR_MNTDATA_SHIFT)) & CPE_LLC_1_CCUCMDR_MNTDATA_MASK)
/*! @} */

/*! @name CCUCMWVR - Maintenance Way Valid */
/*! @{ */

#define CPE_LLC_1_CCUCMWVR_WAYVALID_MASK         (0xFFU)
#define CPE_LLC_1_CCUCMWVR_WAYVALID_SHIFT        (0U)
#define CPE_LLC_1_CCUCMWVR_WAYVALID_WIDTH        (8U)
#define CPE_LLC_1_CCUCMWVR_WAYVALID(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCMWVR_WAYVALID_SHIFT)) & CPE_LLC_1_CCUCMWVR_WAYVALID_MASK)
/*! @} */

/*! @name CCUCECR - Correctable Error Control */
/*! @{ */

#define CPE_LLC_1_CCUCECR_ERRDETEN_MASK          (0x1U)
#define CPE_LLC_1_CCUCECR_ERRDETEN_SHIFT         (0U)
#define CPE_LLC_1_CCUCECR_ERRDETEN_WIDTH         (1U)
#define CPE_LLC_1_CCUCECR_ERRDETEN(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCECR_ERRDETEN_SHIFT)) & CPE_LLC_1_CCUCECR_ERRDETEN_MASK)

#define CPE_LLC_1_CCUCECR_ERRINTEN_MASK          (0x2U)
#define CPE_LLC_1_CCUCECR_ERRINTEN_SHIFT         (1U)
#define CPE_LLC_1_CCUCECR_ERRINTEN_WIDTH         (1U)
#define CPE_LLC_1_CCUCECR_ERRINTEN(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCECR_ERRINTEN_SHIFT)) & CPE_LLC_1_CCUCECR_ERRINTEN_MASK)

#define CPE_LLC_1_CCUCECR_ERRTHRESHOLD_MASK      (0xFF0U)
#define CPE_LLC_1_CCUCECR_ERRTHRESHOLD_SHIFT     (4U)
#define CPE_LLC_1_CCUCECR_ERRTHRESHOLD_WIDTH     (8U)
#define CPE_LLC_1_CCUCECR_ERRTHRESHOLD(x)        (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCECR_ERRTHRESHOLD_SHIFT)) & CPE_LLC_1_CCUCECR_ERRTHRESHOLD_MASK)
/*! @} */

/*! @name CCUCESR - Correctable Error Status */
/*! @{ */

#define CPE_LLC_1_CCUCESR_CERRVLD_MASK           (0x1U)
#define CPE_LLC_1_CCUCESR_CERRVLD_SHIFT          (0U)
#define CPE_LLC_1_CCUCESR_CERRVLD_WIDTH          (1U)
#define CPE_LLC_1_CCUCESR_CERRVLD(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCESR_CERRVLD_SHIFT)) & CPE_LLC_1_CCUCESR_CERRVLD_MASK)

#define CPE_LLC_1_CCUCESR_CERRCOUNTOVERFLOW_MASK (0x2U)
#define CPE_LLC_1_CCUCESR_CERRCOUNTOVERFLOW_SHIFT (1U)
#define CPE_LLC_1_CCUCESR_CERRCOUNTOVERFLOW_WIDTH (1U)
#define CPE_LLC_1_CCUCESR_CERRCOUNTOVERFLOW(x)   (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCESR_CERRCOUNTOVERFLOW_SHIFT)) & CPE_LLC_1_CCUCESR_CERRCOUNTOVERFLOW_MASK)

#define CPE_LLC_1_CCUCESR_CERRCOUNT_MASK         (0x3FCU)
#define CPE_LLC_1_CCUCESR_CERRCOUNT_SHIFT        (2U)
#define CPE_LLC_1_CCUCESR_CERRCOUNT_WIDTH        (8U)
#define CPE_LLC_1_CCUCESR_CERRCOUNT(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCESR_CERRCOUNT_SHIFT)) & CPE_LLC_1_CCUCESR_CERRCOUNT_MASK)

#define CPE_LLC_1_CCUCESR_CERRTYPE_MASK          (0xF800U)
#define CPE_LLC_1_CCUCESR_CERRTYPE_SHIFT         (11U)
#define CPE_LLC_1_CCUCESR_CERRTYPE_WIDTH         (5U)
#define CPE_LLC_1_CCUCESR_CERRTYPE(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCESR_CERRTYPE_SHIFT)) & CPE_LLC_1_CCUCESR_CERRTYPE_MASK)

#define CPE_LLC_1_CCUCESR_CERRINFO_MASK          (0xFFFF0000U)
#define CPE_LLC_1_CCUCESR_CERRINFO_SHIFT         (16U)
#define CPE_LLC_1_CCUCESR_CERRINFO_WIDTH         (16U)
#define CPE_LLC_1_CCUCESR_CERRINFO(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCESR_CERRINFO_SHIFT)) & CPE_LLC_1_CCUCESR_CERRINFO_MASK)
/*! @} */

/*! @name CCUCESAR - Correctable Error Status Alias */
/*! @{ */

#define CPE_LLC_1_CCUCESAR_CERRVLD_MASK          (0x1U)
#define CPE_LLC_1_CCUCESAR_CERRVLD_SHIFT         (0U)
#define CPE_LLC_1_CCUCESAR_CERRVLD_WIDTH         (1U)
#define CPE_LLC_1_CCUCESAR_CERRVLD(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCESAR_CERRVLD_SHIFT)) & CPE_LLC_1_CCUCESAR_CERRVLD_MASK)

#define CPE_LLC_1_CCUCESAR_CERRCOUNTOVERFLOW_MASK (0x2U)
#define CPE_LLC_1_CCUCESAR_CERRCOUNTOVERFLOW_SHIFT (1U)
#define CPE_LLC_1_CCUCESAR_CERRCOUNTOVERFLOW_WIDTH (1U)
#define CPE_LLC_1_CCUCESAR_CERRCOUNTOVERFLOW(x)  (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCESAR_CERRCOUNTOVERFLOW_SHIFT)) & CPE_LLC_1_CCUCESAR_CERRCOUNTOVERFLOW_MASK)

#define CPE_LLC_1_CCUCESAR_CERRCOUNT_MASK        (0x3FCU)
#define CPE_LLC_1_CCUCESAR_CERRCOUNT_SHIFT       (2U)
#define CPE_LLC_1_CCUCESAR_CERRCOUNT_WIDTH       (8U)
#define CPE_LLC_1_CCUCESAR_CERRCOUNT(x)          (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCESAR_CERRCOUNT_SHIFT)) & CPE_LLC_1_CCUCESAR_CERRCOUNT_MASK)

#define CPE_LLC_1_CCUCESAR_CERRTYPE_MASK         (0xF800U)
#define CPE_LLC_1_CCUCESAR_CERRTYPE_SHIFT        (11U)
#define CPE_LLC_1_CCUCESAR_CERRTYPE_WIDTH        (5U)
#define CPE_LLC_1_CCUCESAR_CERRTYPE(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCESAR_CERRTYPE_SHIFT)) & CPE_LLC_1_CCUCESAR_CERRTYPE_MASK)

#define CPE_LLC_1_CCUCESAR_CERRINFO_MASK         (0xFFFF0000U)
#define CPE_LLC_1_CCUCESAR_CERRINFO_SHIFT        (16U)
#define CPE_LLC_1_CCUCESAR_CERRINFO_WIDTH        (16U)
#define CPE_LLC_1_CCUCESAR_CERRINFO(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCESAR_CERRINFO_SHIFT)) & CPE_LLC_1_CCUCESAR_CERRINFO_MASK)
/*! @} */

/*! @name CCUCELR0 - Correctable Error Location 0 */
/*! @{ */

#define CPE_LLC_1_CCUCELR0_ERRENTRY_MASK         (0x7FFFU)
#define CPE_LLC_1_CCUCELR0_ERRENTRY_SHIFT        (0U)
#define CPE_LLC_1_CCUCELR0_ERRENTRY_WIDTH        (15U)
#define CPE_LLC_1_CCUCELR0_ERRENTRY(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCELR0_ERRENTRY_SHIFT)) & CPE_LLC_1_CCUCELR0_ERRENTRY_MASK)

#define CPE_LLC_1_CCUCELR0_ERRWAY_MASK           (0x1F8000U)
#define CPE_LLC_1_CCUCELR0_ERRWAY_SHIFT          (15U)
#define CPE_LLC_1_CCUCELR0_ERRWAY_WIDTH          (6U)
#define CPE_LLC_1_CCUCELR0_ERRWAY(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCELR0_ERRWAY_SHIFT)) & CPE_LLC_1_CCUCELR0_ERRWAY_MASK)

#define CPE_LLC_1_CCUCELR0_ERRWORD_MASK          (0xFFE00000U)
#define CPE_LLC_1_CCUCELR0_ERRWORD_SHIFT         (21U)
#define CPE_LLC_1_CCUCELR0_ERRWORD_WIDTH         (11U)
#define CPE_LLC_1_CCUCELR0_ERRWORD(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCELR0_ERRWORD_SHIFT)) & CPE_LLC_1_CCUCELR0_ERRWORD_MASK)
/*! @} */

/*! @name CCUCELR1 - Correctable Error Location 1 */
/*! @{ */

#define CPE_LLC_1_CCUCELR1_ERRADDR_MASK          (0x7FFFFFFFU)
#define CPE_LLC_1_CCUCELR1_ERRADDR_SHIFT         (0U)
#define CPE_LLC_1_CCUCELR1_ERRADDR_WIDTH         (31U)
#define CPE_LLC_1_CCUCELR1_ERRADDR(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCELR1_ERRADDR_SHIFT)) & CPE_LLC_1_CCUCELR1_ERRADDR_MASK)
/*! @} */

/*! @name CCUUEDR - Uncorrectable Error Detect */
/*! @{ */

#define CPE_LLC_1_CCUUEDR_PROTERRDETEN_MASK      (0x1U)
#define CPE_LLC_1_CCUUEDR_PROTERRDETEN_SHIFT     (0U)
#define CPE_LLC_1_CCUUEDR_PROTERRDETEN_WIDTH     (1U)
#define CPE_LLC_1_CCUUEDR_PROTERRDETEN(x)        (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUEDR_PROTERRDETEN_SHIFT)) & CPE_LLC_1_CCUUEDR_PROTERRDETEN_MASK)

#define CPE_LLC_1_CCUUEDR_MEMERRDETEN_MASK       (0x2U)
#define CPE_LLC_1_CCUUEDR_MEMERRDETEN_SHIFT      (1U)
#define CPE_LLC_1_CCUUEDR_MEMERRDETEN_WIDTH      (1U)
#define CPE_LLC_1_CCUUEDR_MEMERRDETEN(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUEDR_MEMERRDETEN_SHIFT)) & CPE_LLC_1_CCUUEDR_MEMERRDETEN_MASK)
/*! @} */

/*! @name CCUUEIR - Uncorrectable Error Interrupt */
/*! @{ */

#define CPE_LLC_1_CCUUEIR_MEMERRINTEN_MASK       (0x2U)
#define CPE_LLC_1_CCUUEIR_MEMERRINTEN_SHIFT      (1U)
#define CPE_LLC_1_CCUUEIR_MEMERRINTEN_WIDTH      (1U)
#define CPE_LLC_1_CCUUEIR_MEMERRINTEN(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUEIR_MEMERRINTEN_SHIFT)) & CPE_LLC_1_CCUUEIR_MEMERRINTEN_MASK)
/*! @} */

/*! @name CCUUESR - Uncorrectable Error Status */
/*! @{ */

#define CPE_LLC_1_CCUUESR_UERRVLD_MASK           (0x1U)
#define CPE_LLC_1_CCUUESR_UERRVLD_SHIFT          (0U)
#define CPE_LLC_1_CCUUESR_UERRVLD_WIDTH          (1U)
#define CPE_LLC_1_CCUUESR_UERRVLD(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUESR_UERRVLD_SHIFT)) & CPE_LLC_1_CCUUESR_UERRVLD_MASK)

#define CPE_LLC_1_CCUUESR_UERRTYPE_MASK          (0x1F0U)
#define CPE_LLC_1_CCUUESR_UERRTYPE_SHIFT         (4U)
#define CPE_LLC_1_CCUUESR_UERRTYPE_WIDTH         (5U)
#define CPE_LLC_1_CCUUESR_UERRTYPE(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUESR_UERRTYPE_SHIFT)) & CPE_LLC_1_CCUUESR_UERRTYPE_MASK)

#define CPE_LLC_1_CCUUESR_UERRINFO_MASK          (0xFFFF0000U)
#define CPE_LLC_1_CCUUESR_UERRINFO_SHIFT         (16U)
#define CPE_LLC_1_CCUUESR_UERRINFO_WIDTH         (16U)
#define CPE_LLC_1_CCUUESR_UERRINFO(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUESR_UERRINFO_SHIFT)) & CPE_LLC_1_CCUUESR_UERRINFO_MASK)
/*! @} */

/*! @name CCUUESAR - Uncorrectable Error Status Alias */
/*! @{ */

#define CPE_LLC_1_CCUUESAR_UERRVLD_MASK          (0x1U)
#define CPE_LLC_1_CCUUESAR_UERRVLD_SHIFT         (0U)
#define CPE_LLC_1_CCUUESAR_UERRVLD_WIDTH         (1U)
#define CPE_LLC_1_CCUUESAR_UERRVLD(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUESAR_UERRVLD_SHIFT)) & CPE_LLC_1_CCUUESAR_UERRVLD_MASK)

#define CPE_LLC_1_CCUUESAR_UERRTYPE_MASK         (0x1F0U)
#define CPE_LLC_1_CCUUESAR_UERRTYPE_SHIFT        (4U)
#define CPE_LLC_1_CCUUESAR_UERRTYPE_WIDTH        (5U)
#define CPE_LLC_1_CCUUESAR_UERRTYPE(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUESAR_UERRTYPE_SHIFT)) & CPE_LLC_1_CCUUESAR_UERRTYPE_MASK)

#define CPE_LLC_1_CCUUESAR_UERRINFO_MASK         (0xFFFF0000U)
#define CPE_LLC_1_CCUUESAR_UERRINFO_SHIFT        (16U)
#define CPE_LLC_1_CCUUESAR_UERRINFO_WIDTH        (16U)
#define CPE_LLC_1_CCUUESAR_UERRINFO(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUESAR_UERRINFO_SHIFT)) & CPE_LLC_1_CCUUESAR_UERRINFO_MASK)
/*! @} */

/*! @name CCUUELR0 - Uncorrectable Error Location 0 */
/*! @{ */

#define CPE_LLC_1_CCUUELR0_ERRENTRY_MASK         (0x7FFFU)
#define CPE_LLC_1_CCUUELR0_ERRENTRY_SHIFT        (0U)
#define CPE_LLC_1_CCUUELR0_ERRENTRY_WIDTH        (15U)
#define CPE_LLC_1_CCUUELR0_ERRENTRY(x)           (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUELR0_ERRENTRY_SHIFT)) & CPE_LLC_1_CCUUELR0_ERRENTRY_MASK)

#define CPE_LLC_1_CCUUELR0_ERRWAY_MASK           (0x1F8000U)
#define CPE_LLC_1_CCUUELR0_ERRWAY_SHIFT          (15U)
#define CPE_LLC_1_CCUUELR0_ERRWAY_WIDTH          (6U)
#define CPE_LLC_1_CCUUELR0_ERRWAY(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUELR0_ERRWAY_SHIFT)) & CPE_LLC_1_CCUUELR0_ERRWAY_MASK)

#define CPE_LLC_1_CCUUELR0_ERRWORD_MASK          (0xFFE00000U)
#define CPE_LLC_1_CCUUELR0_ERRWORD_SHIFT         (21U)
#define CPE_LLC_1_CCUUELR0_ERRWORD_WIDTH         (11U)
#define CPE_LLC_1_CCUUELR0_ERRWORD(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUELR0_ERRWORD_SHIFT)) & CPE_LLC_1_CCUUELR0_ERRWORD_MASK)
/*! @} */

/*! @name CCUUELR1 - Uncorrectable Error Location 1 */
/*! @{ */

#define CPE_LLC_1_CCUUELR1_ERRADDR_MASK          (0x7FFFFFFFU)
#define CPE_LLC_1_CCUUELR1_ERRADDR_SHIFT         (0U)
#define CPE_LLC_1_CCUUELR1_ERRADDR_WIDTH         (31U)
#define CPE_LLC_1_CCUUELR1_ERRADDR(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUUELR1_ERRADDR_SHIFT)) & CPE_LLC_1_CCUUELR1_ERRADDR_MASK)
/*! @} */

/*! @name CCUIIDR - Instance Identification */
/*! @{ */

#define CPE_LLC_1_CCUIIDR_INSTANCE_ID_MASK       (0xFFFFFFFFU)
#define CPE_LLC_1_CCUIIDR_INSTANCE_ID_SHIFT      (0U)
#define CPE_LLC_1_CCUIIDR_INSTANCE_ID_WIDTH      (32U)
#define CPE_LLC_1_CCUIIDR_INSTANCE_ID(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUIIDR_INSTANCE_ID_SHIFT)) & CPE_LLC_1_CCUIIDR_INSTANCE_ID_MASK)
/*! @} */

/*! @name CCUIDR - Version Identification */
/*! @{ */

#define CPE_LLC_1_CCUIDR_PATCHRELVER_MASK        (0xFU)
#define CPE_LLC_1_CCUIDR_PATCHRELVER_SHIFT       (0U)
#define CPE_LLC_1_CCUIDR_PATCHRELVER_WIDTH       (4U)
#define CPE_LLC_1_CCUIDR_PATCHRELVER(x)          (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUIDR_PATCHRELVER_SHIFT)) & CPE_LLC_1_CCUIDR_PATCHRELVER_MASK)

#define CPE_LLC_1_CCUIDR_MINRELVER_MASK          (0xF0U)
#define CPE_LLC_1_CCUIDR_MINRELVER_SHIFT         (4U)
#define CPE_LLC_1_CCUIDR_MINRELVER_WIDTH         (4U)
#define CPE_LLC_1_CCUIDR_MINRELVER(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUIDR_MINRELVER_SHIFT)) & CPE_LLC_1_CCUIDR_MINRELVER_MASK)

#define CPE_LLC_1_CCUIDR_MAJRELVER_MASK          (0xF00U)
#define CPE_LLC_1_CCUIDR_MAJRELVER_SHIFT         (8U)
#define CPE_LLC_1_CCUIDR_MAJRELVER_WIDTH         (4U)
#define CPE_LLC_1_CCUIDR_MAJRELVER(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUIDR_MAJRELVER_SHIFT)) & CPE_LLC_1_CCUIDR_MAJRELVER_MASK)
/*! @} */

/*! @name CCUCRTR - Correctable Resiliency Threshold */
/*! @{ */

#define CPE_LLC_1_CCUCRTR_RESTHRESHOLD_MASK      (0xFFU)
#define CPE_LLC_1_CCUCRTR_RESTHRESHOLD_SHIFT     (0U)
#define CPE_LLC_1_CCUCRTR_RESTHRESHOLD_WIDTH     (8U)
#define CPE_LLC_1_CCUCRTR_RESTHRESHOLD(x)        (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUCRTR_RESTHRESHOLD_SHIFT)) & CPE_LLC_1_CCUCRTR_RESTHRESHOLD_MASK)
/*! @} */

/*! @name CCUESR - Event Status */
/*! @{ */

#define CPE_LLC_1_CCUESR_STATUS_MASK             (0x3U)
#define CPE_LLC_1_CCUESR_STATUS_SHIFT            (0U)
#define CPE_LLC_1_CCUESR_STATUS_WIDTH            (2U)
#define CPE_LLC_1_CCUESR_STATUS(x)               (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUESR_STATUS_SHIFT)) & CPE_LLC_1_CCUESR_STATUS_MASK)
/*! @} */

/*! @name CCUEMR - Event Mask */
/*! @{ */

#define CPE_LLC_1_CCUEMR_MASK_MASK               (0x3U)
#define CPE_LLC_1_CCUEMR_MASK_SHIFT              (0U)
#define CPE_LLC_1_CCUEMR_MASK_WIDTH              (2U)
#define CPE_LLC_1_CCUEMR_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUEMR_MASK_SHIFT)) & CPE_LLC_1_CCUEMR_MASK_MASK)
/*! @} */

/*! @name CCUEAR - Event Alias */
/*! @{ */

#define CPE_LLC_1_CCUEAR_ALIAS_MASK              (0x3U)
#define CPE_LLC_1_CCUEAR_ALIAS_SHIFT             (0U)
#define CPE_LLC_1_CCUEAR_ALIAS_WIDTH             (2U)
#define CPE_LLC_1_CCUEAR_ALIAS(x)                (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUEAR_ALIAS_SHIFT)) & CPE_LLC_1_CCUEAR_ALIAS_MASK)
/*! @} */

/*! @name CCUHI - Hardware Information */
/*! @{ */

#define CPE_LLC_1_CCUHI_AXIDATAWIDTH_MASK        (0x7U)
#define CPE_LLC_1_CCUHI_AXIDATAWIDTH_SHIFT       (0U)
#define CPE_LLC_1_CCUHI_AXIDATAWIDTH_WIDTH       (3U)
#define CPE_LLC_1_CCUHI_AXIDATAWIDTH(x)          (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUHI_AXIDATAWIDTH_SHIFT)) & CPE_LLC_1_CCUHI_AXIDATAWIDTH_MASK)

#define CPE_LLC_1_CCUHI_CACHELINESIZE_MASK       (0x30000U)
#define CPE_LLC_1_CCUHI_CACHELINESIZE_SHIFT      (16U)
#define CPE_LLC_1_CCUHI_CACHELINESIZE_WIDTH      (2U)
#define CPE_LLC_1_CCUHI_CACHELINESIZE(x)         (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUHI_CACHELINESIZE_SHIFT)) & CPE_LLC_1_CCUHI_CACHELINESIZE_MASK)
/*! @} */

/*! @name CCUPMHI - Performance Monitor Hardware Information */
/*! @{ */

#define CPE_LLC_1_CCUPMHI_COUNTERWIDTH_MASK      (0xFFU)
#define CPE_LLC_1_CCUPMHI_COUNTERWIDTH_SHIFT     (0U)
#define CPE_LLC_1_CCUPMHI_COUNTERWIDTH_WIDTH     (8U)
#define CPE_LLC_1_CCUPMHI_COUNTERWIDTH(x)        (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMHI_COUNTERWIDTH_SHIFT)) & CPE_LLC_1_CCUPMHI_COUNTERWIDTH_MASK)

#define CPE_LLC_1_CCUPMHI_FREERUN_MASK           (0x100U)
#define CPE_LLC_1_CCUPMHI_FREERUN_SHIFT          (8U)
#define CPE_LLC_1_CCUPMHI_FREERUN_WIDTH          (1U)
#define CPE_LLC_1_CCUPMHI_FREERUN(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMHI_FREERUN_SHIFT)) & CPE_LLC_1_CCUPMHI_FREERUN_MASK)
/*! @} */

/*! @name CCUPMCTL - Performance Monitor Control */
/*! @{ */

#define CPE_LLC_1_CCUPMCTL_SWRESET_MASK          (0x1U)
#define CPE_LLC_1_CCUPMCTL_SWRESET_SHIFT         (0U)
#define CPE_LLC_1_CCUPMCTL_SWRESET_WIDTH         (1U)
#define CPE_LLC_1_CCUPMCTL_SWRESET(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMCTL_SWRESET_SHIFT)) & CPE_LLC_1_CCUPMCTL_SWRESET_MASK)

#define CPE_LLC_1_CCUPMCTL_ENABLE_MASK           (0x2U)
#define CPE_LLC_1_CCUPMCTL_ENABLE_SHIFT          (1U)
#define CPE_LLC_1_CCUPMCTL_ENABLE_WIDTH          (1U)
#define CPE_LLC_1_CCUPMCTL_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMCTL_ENABLE_SHIFT)) & CPE_LLC_1_CCUPMCTL_ENABLE_MASK)

#define CPE_LLC_1_CCUPMCTL_FREERUN_MASK          (0x4U)
#define CPE_LLC_1_CCUPMCTL_FREERUN_SHIFT         (2U)
#define CPE_LLC_1_CCUPMCTL_FREERUN_WIDTH         (1U)
#define CPE_LLC_1_CCUPMCTL_FREERUN(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMCTL_FREERUN_SHIFT)) & CPE_LLC_1_CCUPMCTL_FREERUN_MASK)

#define CPE_LLC_1_CCUPMCTL_HARDWARE_TRIGGER_MASK (0x100U)
#define CPE_LLC_1_CCUPMCTL_HARDWARE_TRIGGER_SHIFT (8U)
#define CPE_LLC_1_CCUPMCTL_HARDWARE_TRIGGER_WIDTH (1U)
#define CPE_LLC_1_CCUPMCTL_HARDWARE_TRIGGER(x)   (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMCTL_HARDWARE_TRIGGER_SHIFT)) & CPE_LLC_1_CCUPMCTL_HARDWARE_TRIGGER_MASK)
/*! @} */

/*! @name CCUPMSC - Performance Monitor Slot Configuration */
/*! @{ */

#define CPE_LLC_1_CCUPMSC_DURATION_MASK          (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMSC_DURATION_SHIFT         (0U)
#define CPE_LLC_1_CCUPMSC_DURATION_WIDTH         (32U)
#define CPE_LLC_1_CCUPMSC_DURATION(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMSC_DURATION_SHIFT)) & CPE_LLC_1_CCUPMSC_DURATION_MASK)
/*! @} */

/*! @name CCUPMOTC - Performance Monitor OTT Threshold Configuration */
/*! @{ */

#define CPE_LLC_1_CCUPMOTC_RTT_MASK              (0x1FU)
#define CPE_LLC_1_CCUPMOTC_RTT_SHIFT             (0U)
#define CPE_LLC_1_CCUPMOTC_RTT_WIDTH             (5U)
#define CPE_LLC_1_CCUPMOTC_RTT(x)                (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMOTC_RTT_SHIFT)) & CPE_LLC_1_CCUPMOTC_RTT_MASK)

#define CPE_LLC_1_CCUPMOTC_WTT_MASK              (0x1F0000U)
#define CPE_LLC_1_CCUPMOTC_WTT_SHIFT             (16U)
#define CPE_LLC_1_CCUPMOTC_WTT_WIDTH             (5U)
#define CPE_LLC_1_CCUPMOTC_WTT(x)                (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMOTC_WTT_SHIFT)) & CPE_LLC_1_CCUPMOTC_WTT_MASK)
/*! @} */

/*! @name CCUPMCYCO - Performance Monitor Cycle Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMCYCO_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMCYCO_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMCYCO_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMCYCO_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMCYCO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMCYCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMCYCA - Performance Monitor Cycle Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMCYCA_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMCYCA_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMCYCA_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMCYCA_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMCYCA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMCYCA_COUNT_MASK)
/*! @} */

/*! @name CCUPMRRCO - Performance Monitor Read Request Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMRRCO_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMRRCO_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMRRCO_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMRRCO_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMRRCO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMRRCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMWRCO - Performance Monitor Write Request Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMWRCO_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMWRCO_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMWRCO_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMWRCO_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMWRCO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMWRCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMCRRCO - Performance Monitor Cacheable Read Request Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMCRRCO_COUNT_MASK          (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMCRRCO_COUNT_SHIFT         (0U)
#define CPE_LLC_1_CCUPMCRRCO_COUNT_WIDTH         (32U)
#define CPE_LLC_1_CCUPMCRRCO_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMCRRCO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMCRRCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMCWRCO - Performance Monitor Cacheable Write Request Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMCWRCO_COUNT_MASK          (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMCWRCO_COUNT_SHIFT         (0U)
#define CPE_LLC_1_CCUPMCWRCO_COUNT_WIDTH         (32U)
#define CPE_LLC_1_CCUPMCWRCO_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMCWRCO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMCWRCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMRHCO - Performance Monitor Read Hit Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMRHCO_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMRHCO_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMRHCO_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMRHCO_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMRHCO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMRHCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMWHCO - Performance Monitor Write Hit Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMWHCO_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMWHCO_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMWHCO_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMWHCO_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMWHCO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMWHCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMECO - Performance Monitor Eviction Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMECO_COUNT_MASK            (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMECO_COUNT_SHIFT           (0U)
#define CPE_LLC_1_CCUPMECO_COUNT_WIDTH           (32U)
#define CPE_LLC_1_CCUPMECO_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMECO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMECO_COUNT_MASK)
/*! @} */

/*! @name CCUPMRBCO - Performance Monitor Read Beat Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMRBCO_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMRBCO_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMRBCO_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMRBCO_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMRBCO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMRBCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMWBCO - Performance Monitor Write Beat Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMWBCO_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMWBCO_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMWBCO_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMWBCO_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMWBCO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMWBCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMRATCO - Performance Monitor RTT Above Threshold Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMRATCO_COUNT_MASK          (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMRATCO_COUNT_SHIFT         (0U)
#define CPE_LLC_1_CCUPMRATCO_COUNT_WIDTH         (32U)
#define CPE_LLC_1_CCUPMRATCO_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMRATCO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMRATCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMWATCO - Performance Monitor WTT Above Threshold Counter */
/*! @{ */

#define CPE_LLC_1_CCUPMWATCO_COUNT_MASK          (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMWATCO_COUNT_SHIFT         (0U)
#define CPE_LLC_1_CCUPMWATCO_COUNT_WIDTH         (32U)
#define CPE_LLC_1_CCUPMWATCO_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMWATCO_COUNT_SHIFT)) & CPE_LLC_1_CCUPMWATCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMRRCA - Performance Monitor Read Request Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMRRCA_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMRRCA_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMRRCA_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMRRCA_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMRRCA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMRRCA_COUNT_MASK)
/*! @} */

/*! @name CCUPMWRCA - Performance Monitor Write Request Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMWRCA_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMWRCA_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMWRCA_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMWRCA_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMWRCA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMWRCA_COUNT_MASK)
/*! @} */

/*! @name CCUPMCRRCA - Performance Monitor Cacheable Read Request Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMCRRCA_COUNT_MASK          (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMCRRCA_COUNT_SHIFT         (0U)
#define CPE_LLC_1_CCUPMCRRCA_COUNT_WIDTH         (32U)
#define CPE_LLC_1_CCUPMCRRCA_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMCRRCA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMCRRCA_COUNT_MASK)
/*! @} */

/*! @name CCUPMCWRCA - Performance Monitor Cacheable Write Request Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMCWRCA_COUNT_MASK          (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMCWRCA_COUNT_SHIFT         (0U)
#define CPE_LLC_1_CCUPMCWRCA_COUNT_WIDTH         (32U)
#define CPE_LLC_1_CCUPMCWRCA_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMCWRCA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMCWRCA_COUNT_MASK)
/*! @} */

/*! @name CCUPMRHCA - Performance Monitor Read Hit Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMRHCA_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMRHCA_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMRHCA_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMRHCA_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMRHCA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMRHCA_COUNT_MASK)
/*! @} */

/*! @name CCUPMWHCA - Performance Monitor Write Hit Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMWHCA_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMWHCA_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMWHCA_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMWHCA_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMWHCA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMWHCA_COUNT_MASK)
/*! @} */

/*! @name CCUPMECA - Performance Monitor Eviction Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMECA_COUNT_MASK            (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMECA_COUNT_SHIFT           (0U)
#define CPE_LLC_1_CCUPMECA_COUNT_WIDTH           (32U)
#define CPE_LLC_1_CCUPMECA_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMECA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMECA_COUNT_MASK)
/*! @} */

/*! @name CCUPMRBCA - Performance Monitor Read Beat Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMRBCA_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMRBCA_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMRBCA_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMRBCA_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMRBCA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMRBCA_COUNT_MASK)
/*! @} */

/*! @name CCUPMWBCA - Performance Monitor Write Beat Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMWBCA_COUNT_MASK           (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMWBCA_COUNT_SHIFT          (0U)
#define CPE_LLC_1_CCUPMWBCA_COUNT_WIDTH          (32U)
#define CPE_LLC_1_CCUPMWBCA_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMWBCA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMWBCA_COUNT_MASK)
/*! @} */

/*! @name CCUPMRATCA - Performance Monitor RTT Above Threshold Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMRATCA_COUNT_MASK          (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMRATCA_COUNT_SHIFT         (0U)
#define CPE_LLC_1_CCUPMRATCA_COUNT_WIDTH         (32U)
#define CPE_LLC_1_CCUPMRATCA_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMRATCA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMRATCA_COUNT_MASK)
/*! @} */

/*! @name CCUPMWATCA - Performance Monitor WTT Above Threshold Counter Capture */
/*! @{ */

#define CPE_LLC_1_CCUPMWATCA_COUNT_MASK          (0xFFFFFFFFU)
#define CPE_LLC_1_CCUPMWATCA_COUNT_SHIFT         (0U)
#define CPE_LLC_1_CCUPMWATCA_COUNT_WIDTH         (32U)
#define CPE_LLC_1_CCUPMWATCA_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << CPE_LLC_1_CCUPMWATCA_COUNT_SHIFT)) & CPE_LLC_1_CCUPMWATCA_COUNT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CPE_LLC_1_Register_Masks */

/*!
 * @}
 */ /* end of group CPE_LLC_1_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_CPE_LLC_1_H_) */
