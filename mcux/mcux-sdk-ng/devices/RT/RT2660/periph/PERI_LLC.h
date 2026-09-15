/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LLC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_LLC.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for LLC
 *
 * CMSIS Peripheral Access Layer for LLC
 */

#if !defined(PERI_LLC_H_)
#define PERI_LLC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- LLC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLC_Peripheral_Access_Layer LLC Peripheral Access Layer
 * @{
 */

/** LLC - Register Layout Typedef */
typedef struct {
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
  __IO uint32_t CCUWPCR00;                         /**< Way Partitioning Control 00, offset: 0x40 */
  __IO uint32_t CCUWPCR10;                         /**< Way Partitioning Control 10, offset: 0x44 */
  __IO uint32_t CCUWPCR01;                         /**< Way Partitioning Control 01, offset: 0x48 */
  __IO uint32_t CCUWPCR11;                         /**< Way Partitioning Control 11, offset: 0x4C */
  __IO uint32_t CCUWPCR02;                         /**< Way Partitioning Control 02, offset: 0x50 */
  __IO uint32_t CCUWPCR12;                         /**< Way Partitioning Control 12, offset: 0x54 */
  __IO uint32_t CCUWPCR03;                         /**< Way Partitioning Control 03, offset: 0x58 */
  __IO uint32_t CCUWPCR13;                         /**< Way Partitioning Control 13, offset: 0x5C */
  __IO uint32_t CCUWPCR04;                         /**< Way Partitioning Control 04, offset: 0x60 */
  __IO uint32_t CCUWPCR14;                         /**< Way Partitioning Control 14, offset: 0x64 */
  __IO uint32_t CCUWPCR05;                         /**< Way Partitioning Control 05, offset: 0x68 */
  __IO uint32_t CCUWPCR15;                         /**< Way Partitioning Control 15, offset: 0x6C */
  __IO uint32_t CCUWPCR06;                         /**< Way Partitioning Control 06, offset: 0x70 */
  __IO uint32_t CCUWPCR16;                         /**< Way Partitioning Control 16, offset: 0x74 */
  __IO uint32_t CCUWPCR07;                         /**< Way Partitioning Control 07, offset: 0x78 */
  __IO uint32_t CCUWPCR17;                         /**< Way Partitioning Control 17, offset: 0x7C */
       uint8_t RESERVED_3[128];
  __IO uint32_t CCUCMCR;                           /**< Maintenance Control, offset: 0x100 */
  __I  uint32_t CCUCMAR;                           /**< Maintenance Activity, offset: 0x104 */
  __IO uint32_t CCUCMLR0;                          /**< Maintenance Location 0, offset: 0x108 */
  __IO uint32_t CCUCMLR1;                          /**< Maintenance Location 1, offset: 0x10C */
  __IO uint32_t CCUCMLR2;                          /**< Maintenance Location 2, offset: 0x110 */
       uint8_t RESERVED_4[4];
  __IO uint32_t CCUCMWVR;                          /**< Maintenance Way Valid, offset: 0x118 */
       uint8_t RESERVED_5[36];
  __IO uint32_t CCUCECR;                           /**< Correctable Error Control, offset: 0x140 */
  __IO uint32_t CCUCESR;                           /**< Correctable Error Status, offset: 0x144 */
       uint8_t RESERVED_6[4];
  __I  uint32_t CCUCELR0;                          /**< Correctable Error Location 0, offset: 0x14C */
  __I  uint32_t CCUCELR1;                          /**< Correctable Error Location 1, offset: 0x150 */
  __IO uint32_t CCUUEDR;                           /**< Uncorrectable Error Detect, offset: 0x154 */
  __IO uint32_t CCUUEIR;                           /**< Uncorrectable Error Interrupt, offset: 0x158 */
  __IO uint32_t CCUUESR;                           /**< Uncorrectable Error Status, offset: 0x15C */
       uint8_t RESERVED_7[4];
  __I  uint32_t CCUUELR0;                          /**< Uncorrectable Error Location 0, offset: 0x164 */
  __I  uint32_t CCUUELR1;                          /**< Uncorrectable Error Location 1, offset: 0x168 */
       uint8_t RESERVED_8[80];
  __I  uint32_t CCUIIDR;                           /**< Instance Identification, offset: 0x1BC */
  __I  uint32_t CCUIDR;                            /**< Version Identification, offset: 0x1C0 */
       uint8_t RESERVED_9[4];
  __IO uint32_t CCUESR;                            /**< Event Status, offset: 0x1C8 */
  __IO uint32_t CCUEMR;                            /**< Event Mask, offset: 0x1CC */
  __IO uint32_t CCUEAR;                            /**< Event Alias, offset: 0x1D0 */
       uint8_t RESERVED_10[556];
  __I  uint32_t CCUHI;                             /**< Hardware Information, offset: 0x400 */
       uint8_t RESERVED_11[60];
  __I  uint32_t CCUPMHI;                           /**< Performance Monitor Hardware Information, offset: 0x440 */
       uint8_t RESERVED_12[60];
  __IO uint32_t CCUPMCTL;                          /**< Performance Monitor Control, offset: 0x480 */
  __IO uint32_t CCUPMSC;                           /**< Performance Monitor Slot Configuration, offset: 0x484 */
  __IO uint32_t CCUPMOTC;                          /**< Performance Monitor OTT Threshold Configuration, offset: 0x488 */
       uint8_t RESERVED_13[116];
  __I  uint32_t CCUPMCYCO;                         /**< Performance Monitor Cycle Counter, offset: 0x500 */
       uint8_t RESERVED_14[252];
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
} LLC_Type;

/* ----------------------------------------------------------------------------
   -- LLC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLC_Register_Masks LLC Register Masks
 * @{
 */

/*! @name CCUTCR - Transaction Control */
/*! @{ */

#define LLC_CCUTCR_TRANSEN_MASK                  (0x1U)
#define LLC_CCUTCR_TRANSEN_SHIFT                 (0U)
/*! TRANSEN - Transaction Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUTCR_TRANSEN(x)                    (((uint32_t)(((uint32_t)(x)) << LLC_CCUTCR_TRANSEN_SHIFT)) & LLC_CCUTCR_TRANSEN_MASK)
/*! @} */

/*! @name CCUTAR - Transaction Activity */
/*! @{ */

#define LLC_CCUTAR_TRANSACTV_MASK                (0x1U)
#define LLC_CCUTAR_TRANSACTV_SHIFT               (0U)
/*! TRANSACTV - Transaction Active
 *  0b0..Inactive
 *  0b1..Active
 */
#define LLC_CCUTAR_TRANSACTV(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUTAR_TRANSACTV_SHIFT)) & LLC_CCUTAR_TRANSACTV_MASK)
/*! @} */

/*! @name CCUCTCR - Cache Transaction Control */
/*! @{ */

#define LLC_CCUCTCR_LOOKUPEN_MASK                (0x1U)
#define LLC_CCUCTCR_LOOKUPEN_SHIFT               (0U)
/*! LOOKUPEN - Lookup Enable
 *  0b0..Cache is bypassed
 *  0b1..Cache is accessed
 */
#define LLC_CCUCTCR_LOOKUPEN(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUCTCR_LOOKUPEN_SHIFT)) & LLC_CCUCTCR_LOOKUPEN_MASK)

#define LLC_CCUCTCR_FILLEN_MASK                  (0x2U)
#define LLC_CCUCTCR_FILLEN_SHIFT                 (1U)
/*! FILLEN - Fill Enable
 *  0b0..Cache allocate on miss is disabled
 *  0b1..Cache allocate on miss is enabled
 */
#define LLC_CCUCTCR_FILLEN(x)                    (((uint32_t)(((uint32_t)(x)) << LLC_CCUCTCR_FILLEN_SHIFT)) & LLC_CCUCTCR_FILLEN_MASK)
/*! @} */

/*! @name CCUCTAR - Cache Transaction Activity */
/*! @{ */

#define LLC_CCUCTAR_EVICTACTV_MASK               (0x1U)
#define LLC_CCUCTAR_EVICTACTV_SHIFT              (0U)
/*! EVICTACTV - Evict Active
 *  0b0..No pending
 *  0b1..Pending
 */
#define LLC_CCUCTAR_EVICTACTV(x)                 (((uint32_t)(((uint32_t)(x)) << LLC_CCUCTAR_EVICTACTV_SHIFT)) & LLC_CCUCTAR_EVICTACTV_MASK)

#define LLC_CCUCTAR_FILLACTV_MASK                (0x2U)
#define LLC_CCUCTAR_FILLACTV_SHIFT               (1U)
/*! FILLACTV - Fill Active
 *  0b0..No pending
 *  0b1..Pending
 */
#define LLC_CCUCTAR_FILLACTV(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUCTAR_FILLACTV_SHIFT)) & LLC_CCUCTAR_FILLACTV_MASK)

#define LLC_CCUCTAR_FLUSHACTV_MASK               (0x4U)
#define LLC_CCUCTAR_FLUSHACTV_SHIFT              (2U)
/*! FLUSHACTV - Flush Active
 *  0b0..No pending
 *  0b1..Pending
 */
#define LLC_CCUCTAR_FLUSHACTV(x)                 (((uint32_t)(((uint32_t)(x)) << LLC_CCUCTAR_FLUSHACTV_SHIFT)) & LLC_CCUCTAR_FLUSHACTV_MASK)
/*! @} */

/*! @name CCUCAOR - Allocation Override */
/*! @{ */

#define LLC_CCUCAOR_AWALLOCEN_MASK               (0x1U)
#define LLC_CCUCAOR_AWALLOCEN_SHIFT              (0U)
/*! AWALLOCEN - Enable AwCache Override
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUCAOR_AWALLOCEN(x)                 (((uint32_t)(((uint32_t)(x)) << LLC_CCUCAOR_AWALLOCEN_SHIFT)) & LLC_CCUCAOR_AWALLOCEN_MASK)

#define LLC_CCUCAOR_ARALLOCEN_MASK               (0x2U)
#define LLC_CCUCAOR_ARALLOCEN_SHIFT              (1U)
/*! ARALLOCEN - Enable ArCache Override
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUCAOR_ARALLOCEN(x)                 (((uint32_t)(((uint32_t)(x)) << LLC_CCUCAOR_ARALLOCEN_SHIFT)) & LLC_CCUCAOR_ARALLOCEN_MASK)

#define LLC_CCUCAOR_WRALLOCPARTIALEN_MASK        (0x4U)
#define LLC_CCUCAOR_WRALLOCPARTIALEN_SHIFT       (2U)
/*! WRALLOCPARTIALEN - Enable Write Allocate Partial
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUCAOR_WRALLOCPARTIALEN(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CCUCAOR_WRALLOCPARTIALEN_SHIFT)) & LLC_CCUCAOR_WRALLOCPARTIALEN_MASK)

#define LLC_CCUCAOR_AWALLOCVALUE_MASK            (0xF0000U)
#define LLC_CCUCAOR_AWALLOCVALUE_SHIFT           (16U)
/*! AWALLOCVALUE - AXI Write Cache (AwCache) Override Value */
#define LLC_CCUCAOR_AWALLOCVALUE(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CCUCAOR_AWALLOCVALUE_SHIFT)) & LLC_CCUCAOR_AWALLOCVALUE_MASK)

#define LLC_CCUCAOR_ARALLOCVALUE_MASK            (0xF00000U)
#define LLC_CCUCAOR_ARALLOCVALUE_SHIFT           (20U)
/*! ARALLOCVALUE - AXI Read Cache (ArCache) Override Value */
#define LLC_CCUCAOR_ARALLOCVALUE(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CCUCAOR_ARALLOCVALUE_SHIFT)) & LLC_CCUCAOR_ARALLOCVALUE_MASK)
/*! @} */

/*! @name CCUSPCR0 - Scratchpad Configuration 0 */
/*! @{ */

#define LLC_CCUSPCR0_SCPADEN_MASK                (0x1U)
#define LLC_CCUSPCR0_SCPADEN_SHIFT               (0U)
/*! SCPADEN - Scratchpad RAM Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUSPCR0_SCPADEN(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUSPCR0_SCPADEN_SHIFT)) & LLC_CCUSPCR0_SCPADEN_MASK)

#define LLC_CCUSPCR0_NUMSCPADWAYS_MASK           (0x70000U)
#define LLC_CCUSPCR0_NUMSCPADWAYS_SHIFT          (16U)
/*! NUMSCPADWAYS - Number of Scratchpad Ways */
#define LLC_CCUSPCR0_NUMSCPADWAYS(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CCUSPCR0_NUMSCPADWAYS_SHIFT)) & LLC_CCUSPCR0_NUMSCPADWAYS_MASK)
/*! @} */

/*! @name CCUSPCR1 - Scratchpad Configuration 1 */
/*! @{ */

#define LLC_CCUSPCR1_SCPADSIZE_MASK              (0xFFFFFFFFU)
#define LLC_CCUSPCR1_SCPADSIZE_SHIFT             (0U)
/*! SCPADSIZE - Scratchpad Size */
#define LLC_CCUSPCR1_SCPADSIZE(x)                (((uint32_t)(((uint32_t)(x)) << LLC_CCUSPCR1_SCPADSIZE_SHIFT)) & LLC_CCUSPCR1_SCPADSIZE_MASK)
/*! @} */

/*! @name CCUSPBR0 - Scratchpad Base Address 0 */
/*! @{ */

#define LLC_CCUSPBR0_SCPADBASEADDR_MASK          (0xFFFFFFFFU)
#define LLC_CCUSPBR0_SCPADBASEADDR_SHIFT         (0U)
/*! SCPADBASEADDR - Scratchpad Base Address */
#define LLC_CCUSPBR0_SCPADBASEADDR(x)            (((uint32_t)(((uint32_t)(x)) << LLC_CCUSPBR0_SCPADBASEADDR_SHIFT)) & LLC_CCUSPBR0_SCPADBASEADDR_MASK)
/*! @} */

/*! @name CCUWPCR00 - Way Partitioning Control 00 */
/*! @{ */

#define LLC_CCUWPCR00_WPAGENTID_MASK             (0x3FU)
#define LLC_CCUWPCR00_WPAGENTID_SHIFT            (0U)
/*! WPAGENTID - Way Partitioning Agent ID */
#define LLC_CCUWPCR00_WPAGENTID(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR00_WPAGENTID_SHIFT)) & LLC_CCUWPCR00_WPAGENTID_MASK)

#define LLC_CCUWPCR00_WPAGENTIDVALID_MASK        (0x80000000U)
#define LLC_CCUWPCR00_WPAGENTIDVALID_SHIFT       (31U)
/*! WPAGENTIDVALID - Way Partitioning Agent ID Valid
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUWPCR00_WPAGENTIDVALID(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR00_WPAGENTIDVALID_SHIFT)) & LLC_CCUWPCR00_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR10 - Way Partitioning Control 10 */
/*! @{ */

#define LLC_CCUWPCR10_WPWAYVECTOR_MASK           (0xFFU)
#define LLC_CCUWPCR10_WPWAYVECTOR_SHIFT          (0U)
/*! WPWAYVECTOR - Way Partitioning Way Enable Vector
 *  0b0xxxxxxx..Way 7 disabled
 *  0b1xxxxxxx..Way 7 enabled
 *  0bxxxxxxx0..Way 0 disabled
 *  0bxxxxxxx1..Way 0 enabled
 */
#define LLC_CCUWPCR10_WPWAYVECTOR(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR10_WPWAYVECTOR_SHIFT)) & LLC_CCUWPCR10_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR01 - Way Partitioning Control 01 */
/*! @{ */

#define LLC_CCUWPCR01_WPAGENTID_MASK             (0x3FU)
#define LLC_CCUWPCR01_WPAGENTID_SHIFT            (0U)
/*! WPAGENTID - Way Partitioning Agent ID */
#define LLC_CCUWPCR01_WPAGENTID(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR01_WPAGENTID_SHIFT)) & LLC_CCUWPCR01_WPAGENTID_MASK)

#define LLC_CCUWPCR01_WPAGENTIDVALID_MASK        (0x80000000U)
#define LLC_CCUWPCR01_WPAGENTIDVALID_SHIFT       (31U)
/*! WPAGENTIDVALID - Way Partitioning Agent ID Valid
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUWPCR01_WPAGENTIDVALID(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR01_WPAGENTIDVALID_SHIFT)) & LLC_CCUWPCR01_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR11 - Way Partitioning Control 11 */
/*! @{ */

#define LLC_CCUWPCR11_WPWAYVECTOR_MASK           (0xFFU)
#define LLC_CCUWPCR11_WPWAYVECTOR_SHIFT          (0U)
/*! WPWAYVECTOR - Way Partitioning Way Enable Vector
 *  0b0xxxxxxx..Way 7 disabled
 *  0b1xxxxxxx..Way 7 enabled
 *  0bxxxxxxx0..Way 0 disabled
 *  0bxxxxxxx1..Way 0 enabled
 */
#define LLC_CCUWPCR11_WPWAYVECTOR(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR11_WPWAYVECTOR_SHIFT)) & LLC_CCUWPCR11_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR02 - Way Partitioning Control 02 */
/*! @{ */

#define LLC_CCUWPCR02_WPAGENTID_MASK             (0x3FU)
#define LLC_CCUWPCR02_WPAGENTID_SHIFT            (0U)
/*! WPAGENTID - Way Partitioning Agent ID */
#define LLC_CCUWPCR02_WPAGENTID(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR02_WPAGENTID_SHIFT)) & LLC_CCUWPCR02_WPAGENTID_MASK)

#define LLC_CCUWPCR02_WPAGENTIDVALID_MASK        (0x80000000U)
#define LLC_CCUWPCR02_WPAGENTIDVALID_SHIFT       (31U)
/*! WPAGENTIDVALID - Way Partitioning Agent ID Valid
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUWPCR02_WPAGENTIDVALID(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR02_WPAGENTIDVALID_SHIFT)) & LLC_CCUWPCR02_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR12 - Way Partitioning Control 12 */
/*! @{ */

#define LLC_CCUWPCR12_WPWAYVECTOR_MASK           (0xFFU)
#define LLC_CCUWPCR12_WPWAYVECTOR_SHIFT          (0U)
/*! WPWAYVECTOR - Way Partitioning Way Enable Vector
 *  0b0xxxxxxx..Way 7 disabled
 *  0b1xxxxxxx..Way 7 enabled
 *  0bxxxxxxx0..Way 0 disabled
 *  0bxxxxxxx1..Way 0 enabled
 */
#define LLC_CCUWPCR12_WPWAYVECTOR(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR12_WPWAYVECTOR_SHIFT)) & LLC_CCUWPCR12_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR03 - Way Partitioning Control 03 */
/*! @{ */

#define LLC_CCUWPCR03_WPAGENTID_MASK             (0x3FU)
#define LLC_CCUWPCR03_WPAGENTID_SHIFT            (0U)
/*! WPAGENTID - Way Partitioning Agent ID */
#define LLC_CCUWPCR03_WPAGENTID(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR03_WPAGENTID_SHIFT)) & LLC_CCUWPCR03_WPAGENTID_MASK)

#define LLC_CCUWPCR03_WPAGENTIDVALID_MASK        (0x80000000U)
#define LLC_CCUWPCR03_WPAGENTIDVALID_SHIFT       (31U)
/*! WPAGENTIDVALID - Way Partitioning Agent ID Valid
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUWPCR03_WPAGENTIDVALID(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR03_WPAGENTIDVALID_SHIFT)) & LLC_CCUWPCR03_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR13 - Way Partitioning Control 13 */
/*! @{ */

#define LLC_CCUWPCR13_WPWAYVECTOR_MASK           (0xFFU)
#define LLC_CCUWPCR13_WPWAYVECTOR_SHIFT          (0U)
/*! WPWAYVECTOR - Way Partitioning Way Enable Vector
 *  0b0xxxxxxx..Way 7 disabled
 *  0b1xxxxxxx..Way 7 enabled
 *  0bxxxxxxx0..Way 0 disabled
 *  0bxxxxxxx1..Way 0 enabled
 */
#define LLC_CCUWPCR13_WPWAYVECTOR(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR13_WPWAYVECTOR_SHIFT)) & LLC_CCUWPCR13_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR04 - Way Partitioning Control 04 */
/*! @{ */

#define LLC_CCUWPCR04_WPAGENTID_MASK             (0x3FU)
#define LLC_CCUWPCR04_WPAGENTID_SHIFT            (0U)
/*! WPAGENTID - Way Partitioning Agent ID */
#define LLC_CCUWPCR04_WPAGENTID(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR04_WPAGENTID_SHIFT)) & LLC_CCUWPCR04_WPAGENTID_MASK)

#define LLC_CCUWPCR04_WPAGENTIDVALID_MASK        (0x80000000U)
#define LLC_CCUWPCR04_WPAGENTIDVALID_SHIFT       (31U)
/*! WPAGENTIDVALID - Way Partitioning Agent ID Valid
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUWPCR04_WPAGENTIDVALID(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR04_WPAGENTIDVALID_SHIFT)) & LLC_CCUWPCR04_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR14 - Way Partitioning Control 14 */
/*! @{ */

#define LLC_CCUWPCR14_WPWAYVECTOR_MASK           (0xFFU)
#define LLC_CCUWPCR14_WPWAYVECTOR_SHIFT          (0U)
/*! WPWAYVECTOR - Way Partitioning Way Enable Vector
 *  0b0xxxxxxx..Way 7 disabled
 *  0b1xxxxxxx..Way 7 enabled
 *  0bxxxxxxx0..Way 0 disabled
 *  0bxxxxxxx1..Way 0 enabled
 */
#define LLC_CCUWPCR14_WPWAYVECTOR(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR14_WPWAYVECTOR_SHIFT)) & LLC_CCUWPCR14_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR05 - Way Partitioning Control 05 */
/*! @{ */

#define LLC_CCUWPCR05_WPAGENTID_MASK             (0x3FU)
#define LLC_CCUWPCR05_WPAGENTID_SHIFT            (0U)
/*! WPAGENTID - Way Partitioning Agent ID */
#define LLC_CCUWPCR05_WPAGENTID(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR05_WPAGENTID_SHIFT)) & LLC_CCUWPCR05_WPAGENTID_MASK)

#define LLC_CCUWPCR05_WPAGENTIDVALID_MASK        (0x80000000U)
#define LLC_CCUWPCR05_WPAGENTIDVALID_SHIFT       (31U)
/*! WPAGENTIDVALID - Way Partitioning Agent ID Valid
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUWPCR05_WPAGENTIDVALID(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR05_WPAGENTIDVALID_SHIFT)) & LLC_CCUWPCR05_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR15 - Way Partitioning Control 15 */
/*! @{ */

#define LLC_CCUWPCR15_WPWAYVECTOR_MASK           (0xFFU)
#define LLC_CCUWPCR15_WPWAYVECTOR_SHIFT          (0U)
/*! WPWAYVECTOR - Way Partitioning Way Enable Vector
 *  0b0xxxxxxx..Way 7 disabled
 *  0b1xxxxxxx..Way 7 enabled
 *  0bxxxxxxx0..Way 0 disabled
 *  0bxxxxxxx1..Way 0 enabled
 */
#define LLC_CCUWPCR15_WPWAYVECTOR(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR15_WPWAYVECTOR_SHIFT)) & LLC_CCUWPCR15_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR06 - Way Partitioning Control 06 */
/*! @{ */

#define LLC_CCUWPCR06_WPAGENTID_MASK             (0x3FU)
#define LLC_CCUWPCR06_WPAGENTID_SHIFT            (0U)
/*! WPAGENTID - Way Partitioning Agent ID */
#define LLC_CCUWPCR06_WPAGENTID(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR06_WPAGENTID_SHIFT)) & LLC_CCUWPCR06_WPAGENTID_MASK)

#define LLC_CCUWPCR06_WPAGENTIDVALID_MASK        (0x80000000U)
#define LLC_CCUWPCR06_WPAGENTIDVALID_SHIFT       (31U)
/*! WPAGENTIDVALID - Way Partitioning Agent ID Valid
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUWPCR06_WPAGENTIDVALID(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR06_WPAGENTIDVALID_SHIFT)) & LLC_CCUWPCR06_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR16 - Way Partitioning Control 16 */
/*! @{ */

#define LLC_CCUWPCR16_WPWAYVECTOR_MASK           (0xFFU)
#define LLC_CCUWPCR16_WPWAYVECTOR_SHIFT          (0U)
/*! WPWAYVECTOR - Way Partitioning Way Enable Vector
 *  0b0xxxxxxx..Way 7 disabled
 *  0b1xxxxxxx..Way 7 enabled
 *  0bxxxxxxx0..Way 0 disabled
 *  0bxxxxxxx1..Way 0 enabled
 */
#define LLC_CCUWPCR16_WPWAYVECTOR(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR16_WPWAYVECTOR_SHIFT)) & LLC_CCUWPCR16_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUWPCR07 - Way Partitioning Control 07 */
/*! @{ */

#define LLC_CCUWPCR07_WPAGENTID_MASK             (0x3FU)
#define LLC_CCUWPCR07_WPAGENTID_SHIFT            (0U)
/*! WPAGENTID - Way Partitioning Agent ID */
#define LLC_CCUWPCR07_WPAGENTID(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR07_WPAGENTID_SHIFT)) & LLC_CCUWPCR07_WPAGENTID_MASK)

#define LLC_CCUWPCR07_WPAGENTIDVALID_MASK        (0x80000000U)
#define LLC_CCUWPCR07_WPAGENTIDVALID_SHIFT       (31U)
/*! WPAGENTIDVALID - Way Partitioning Agent ID Valid
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUWPCR07_WPAGENTIDVALID(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR07_WPAGENTIDVALID_SHIFT)) & LLC_CCUWPCR07_WPAGENTIDVALID_MASK)
/*! @} */

/*! @name CCUWPCR17 - Way Partitioning Control 17 */
/*! @{ */

#define LLC_CCUWPCR17_WPWAYVECTOR_MASK           (0xFFU)
#define LLC_CCUWPCR17_WPWAYVECTOR_SHIFT          (0U)
/*! WPWAYVECTOR - Way Partitioning Way Enable Vector
 *  0b0xxxxxxx..Way 7 disabled
 *  0b1xxxxxxx..Way 7 enabled
 *  0bxxxxxxx0..Way 0 disabled
 *  0bxxxxxxx1..Way 0 enabled
 */
#define LLC_CCUWPCR17_WPWAYVECTOR(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CCUWPCR17_WPWAYVECTOR_SHIFT)) & LLC_CCUWPCR17_WPWAYVECTOR_MASK)
/*! @} */

/*! @name CCUCMCR - Maintenance Control */
/*! @{ */

#define LLC_CCUCMCR_MNTOP_MASK                   (0xFU)
#define LLC_CCUCMCR_MNTOP_SHIFT                  (0U)
/*! MNTOP - Maintenance Operation
 *  0b0000..Initialize valid entries
 *  0b0001-0b0011..Reserved
 *  0b0100..Flush valid entries (enabled by CCUCMWVR register)
 *  0b0101..Flush Entry at Set and Way
 *  0b0110..Flush Entry at Address
 *  0b0111..Flush Address Range
 *  0b1000..Flush Set Way Range
 *  0b1001-0b1111..Reserved
 */
#define LLC_CCUCMCR_MNTOP(x)                     (((uint32_t)(((uint32_t)(x)) << LLC_CCUCMCR_MNTOP_SHIFT)) & LLC_CCUCMCR_MNTOP_MASK)

#define LLC_CCUCMCR_ARRAYID_MASK                 (0x3F0000U)
#define LLC_CCUCMCR_ARRAYID_SHIFT                (16U)
/*! ARRAYID - Array ID
 *  0b000000..Tag Array
 *  0b000001..Data Array
 *  0b000010-0b111111..Reserved
 */
#define LLC_CCUCMCR_ARRAYID(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUCMCR_ARRAYID_SHIFT)) & LLC_CCUCMCR_ARRAYID_MASK)

#define LLC_CCUCMCR_SECATTR_MASK                 (0x400000U)
#define LLC_CCUCMCR_SECATTR_SHIFT                (22U)
/*! SECATTR - Security Attribute */
#define LLC_CCUCMCR_SECATTR(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUCMCR_SECATTR_SHIFT)) & LLC_CCUCMCR_SECATTR_MASK)
/*! @} */

/*! @name CCUCMAR - Maintenance Activity */
/*! @{ */

#define LLC_CCUCMAR_MNTOPACTV_MASK               (0x1U)
#define LLC_CCUCMAR_MNTOPACTV_SHIFT              (0U)
/*! MNTOPACTV - Maintenance Operation Active
 *  0b0..No cache maintenance operation
 *  0b1..Cache maintenance operation in progress
 */
#define LLC_CCUCMAR_MNTOPACTV(x)                 (((uint32_t)(((uint32_t)(x)) << LLC_CCUCMAR_MNTOPACTV_SHIFT)) & LLC_CCUCMAR_MNTOPACTV_MASK)
/*! @} */

/*! @name CCUCMLR0 - Maintenance Location 0 */
/*! @{ */

#define LLC_CCUCMLR0_MNTSET_MASK                 (0x7FFFU)
#define LLC_CCUCMLR0_MNTSET_SHIFT                (0U)
/*! MNTSET - Maintenance Set */
#define LLC_CCUCMLR0_MNTSET(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUCMLR0_MNTSET_SHIFT)) & LLC_CCUCMLR0_MNTSET_MASK)

#define LLC_CCUCMLR0_MNTWAY_MASK                 (0x1F8000U)
#define LLC_CCUCMLR0_MNTWAY_SHIFT                (15U)
/*! MNTWAY - Maintenance Way */
#define LLC_CCUCMLR0_MNTWAY(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUCMLR0_MNTWAY_SHIFT)) & LLC_CCUCMLR0_MNTWAY_MASK)

#define LLC_CCUCMLR0_MNTWORD_MASK                (0xFFE00000U)
#define LLC_CCUCMLR0_MNTWORD_SHIFT               (21U)
/*! MNTWORD - Maintenance Word */
#define LLC_CCUCMLR0_MNTWORD(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUCMLR0_MNTWORD_SHIFT)) & LLC_CCUCMLR0_MNTWORD_MASK)
/*! @} */

/*! @name CCUCMLR1 - Maintenance Location 1 */
/*! @{ */

#define LLC_CCUCMLR1_MNTADDR_MASK                (0xFFFFFFFFU)
#define LLC_CCUCMLR1_MNTADDR_SHIFT               (0U)
/*! MNTADDR - Maintenance Address */
#define LLC_CCUCMLR1_MNTADDR(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUCMLR1_MNTADDR_SHIFT)) & LLC_CCUCMLR1_MNTADDR_MASK)
/*! @} */

/*! @name CCUCMLR2 - Maintenance Location 2 */
/*! @{ */

#define LLC_CCUCMLR2_MNTRANGE_MASK               (0xFFFFU)
#define LLC_CCUCMLR2_MNTRANGE_SHIFT              (0U)
/*! MNTRANGE - Maintenance Range */
#define LLC_CCUCMLR2_MNTRANGE(x)                 (((uint32_t)(((uint32_t)(x)) << LLC_CCUCMLR2_MNTRANGE_SHIFT)) & LLC_CCUCMLR2_MNTRANGE_MASK)
/*! @} */

/*! @name CCUCMWVR - Maintenance Way Valid */
/*! @{ */

#define LLC_CCUCMWVR_WAYVALID_MASK               (0xFFU)
#define LLC_CCUCMWVR_WAYVALID_SHIFT              (0U)
/*! WAYVALID - Way Valid */
#define LLC_CCUCMWVR_WAYVALID(x)                 (((uint32_t)(((uint32_t)(x)) << LLC_CCUCMWVR_WAYVALID_SHIFT)) & LLC_CCUCMWVR_WAYVALID_MASK)
/*! @} */

/*! @name CCUCECR - Correctable Error Control */
/*! @{ */

#define LLC_CCUCECR_ERRDETEN_MASK                (0x1U)
#define LLC_CCUCECR_ERRDETEN_SHIFT               (0U)
/*! ERRDETEN - Correctable Error Detection Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUCECR_ERRDETEN(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUCECR_ERRDETEN_SHIFT)) & LLC_CCUCECR_ERRDETEN_MASK)

#define LLC_CCUCECR_ERRINTEN_MASK                (0x2U)
#define LLC_CCUCECR_ERRINTEN_SHIFT               (1U)
/*! ERRINTEN - Correctable Error Interrupt Enable
 *  0b0..IRQ_C_LEVEL is never asserted
 *  0b1..IRQ_C_LEVEL is asserted
 */
#define LLC_CCUCECR_ERRINTEN(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUCECR_ERRINTEN_SHIFT)) & LLC_CCUCECR_ERRINTEN_MASK)

#define LLC_CCUCECR_ERRTHRESHOLD_MASK            (0xFF0U)
#define LLC_CCUCECR_ERRTHRESHOLD_SHIFT           (4U)
/*! ERRTHRESHOLD - Error Threshold */
#define LLC_CCUCECR_ERRTHRESHOLD(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CCUCECR_ERRTHRESHOLD_SHIFT)) & LLC_CCUCECR_ERRTHRESHOLD_MASK)
/*! @} */

/*! @name CCUCESR - Correctable Error Status */
/*! @{ */

#define LLC_CCUCESR_CERRVLD_MASK                 (0x1U)
#define LLC_CCUCESR_CERRVLD_SHIFT                (0U)
/*! CERRVLD - Correctable Error Valid
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define LLC_CCUCESR_CERRVLD(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUCESR_CERRVLD_SHIFT)) & LLC_CCUCESR_CERRVLD_MASK)

#define LLC_CCUCESR_CERRCOUNTOVERFLOW_MASK       (0x2U)
#define LLC_CCUCESR_CERRCOUNTOVERFLOW_SHIFT      (1U)
/*! CERRCOUNTOVERFLOW - Correctable Error Count Overflow */
#define LLC_CCUCESR_CERRCOUNTOVERFLOW(x)         (((uint32_t)(((uint32_t)(x)) << LLC_CCUCESR_CERRCOUNTOVERFLOW_SHIFT)) & LLC_CCUCESR_CERRCOUNTOVERFLOW_MASK)

#define LLC_CCUCESR_CERRCOUNT_MASK               (0x3FCU)
#define LLC_CCUCESR_CERRCOUNT_SHIFT              (2U)
/*! CERRCOUNT - Correctable Error Count */
#define LLC_CCUCESR_CERRCOUNT(x)                 (((uint32_t)(((uint32_t)(x)) << LLC_CCUCESR_CERRCOUNT_SHIFT)) & LLC_CCUCESR_CERRCOUNT_MASK)

#define LLC_CCUCESR_CERRTYPE_MASK                (0xF800U)
#define LLC_CCUCESR_CERRTYPE_SHIFT               (11U)
/*! CERRTYPE - Correctable Error Type
 *  0b00001..Cache memory correctable error
 *  0b00100..Read data buffer memory correctable error
 */
#define LLC_CCUCESR_CERRTYPE(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUCESR_CERRTYPE_SHIFT)) & LLC_CCUCESR_CERRTYPE_MASK)

#define LLC_CCUCESR_CERRINFO_MASK                (0xFFFF0000U)
#define LLC_CCUCESR_CERRINFO_SHIFT               (16U)
/*! CERRINFO - Correctable Error Array
 *  0b0000000000000000..Cache memory tag array
 *  0b0000000000000001..Cache memory data array
 */
#define LLC_CCUCESR_CERRINFO(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUCESR_CERRINFO_SHIFT)) & LLC_CCUCESR_CERRINFO_MASK)
/*! @} */

/*! @name CCUCELR0 - Correctable Error Location 0 */
/*! @{ */

#define LLC_CCUCELR0_ERRENTRY_MASK               (0x7FFFU)
#define LLC_CCUCELR0_ERRENTRY_SHIFT              (0U)
/*! ERRENTRY - Error Entry */
#define LLC_CCUCELR0_ERRENTRY(x)                 (((uint32_t)(((uint32_t)(x)) << LLC_CCUCELR0_ERRENTRY_SHIFT)) & LLC_CCUCELR0_ERRENTRY_MASK)

#define LLC_CCUCELR0_ERRWAY_MASK                 (0x1F8000U)
#define LLC_CCUCELR0_ERRWAY_SHIFT                (15U)
/*! ERRWAY - Error Way */
#define LLC_CCUCELR0_ERRWAY(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUCELR0_ERRWAY_SHIFT)) & LLC_CCUCELR0_ERRWAY_MASK)

#define LLC_CCUCELR0_ERRWORD_MASK                (0xFFE00000U)
#define LLC_CCUCELR0_ERRWORD_SHIFT               (21U)
/*! ERRWORD - Error Word */
#define LLC_CCUCELR0_ERRWORD(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUCELR0_ERRWORD_SHIFT)) & LLC_CCUCELR0_ERRWORD_MASK)
/*! @} */

/*! @name CCUCELR1 - Correctable Error Location 1 */
/*! @{ */

#define LLC_CCUCELR1_ERRADDR_MASK                (0x7FFFFFFFU)
#define LLC_CCUCELR1_ERRADDR_SHIFT               (0U)
/*! ERRADDR - Error Address */
#define LLC_CCUCELR1_ERRADDR(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUCELR1_ERRADDR_SHIFT)) & LLC_CCUCELR1_ERRADDR_MASK)
/*! @} */

/*! @name CCUUEDR - Uncorrectable Error Detect */
/*! @{ */

#define LLC_CCUUEDR_PROTERRDETEN_MASK            (0x1U)
#define LLC_CCUUEDR_PROTERRDETEN_SHIFT           (0U)
/*! PROTERRDETEN - AXI Downstream Protocol Error Detect Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUUEDR_PROTERRDETEN(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CCUUEDR_PROTERRDETEN_SHIFT)) & LLC_CCUUEDR_PROTERRDETEN_MASK)

#define LLC_CCUUEDR_MEMERRDETEN_MASK             (0x2U)
#define LLC_CCUUEDR_MEMERRDETEN_SHIFT            (1U)
/*! MEMERRDETEN - Memory Protection Error Detect Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUUEDR_MEMERRDETEN(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUUEDR_MEMERRDETEN_SHIFT)) & LLC_CCUUEDR_MEMERRDETEN_MASK)
/*! @} */

/*! @name CCUUEIR - Uncorrectable Error Interrupt */
/*! @{ */

#define LLC_CCUUEIR_PROTERRINTEN_MASK            (0x1U)
#define LLC_CCUUEIR_PROTERRINTEN_SHIFT           (0U)
/*! PROTERRINTEN - AXI Downstream Protocol Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUUEIR_PROTERRINTEN(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CCUUEIR_PROTERRINTEN_SHIFT)) & LLC_CCUUEIR_PROTERRINTEN_MASK)

#define LLC_CCUUEIR_MEMERRINTEN_MASK             (0x2U)
#define LLC_CCUUEIR_MEMERRINTEN_SHIFT            (1U)
/*! MEMERRINTEN - Memory Protection Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUUEIR_MEMERRINTEN(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUUEIR_MEMERRINTEN_SHIFT)) & LLC_CCUUEIR_MEMERRINTEN_MASK)
/*! @} */

/*! @name CCUUESR - Uncorrectable Error Status */
/*! @{ */

#define LLC_CCUUESR_UERRVLD_MASK                 (0x1U)
#define LLC_CCUUESR_UERRVLD_SHIFT                (0U)
/*! UERRVLD - Uncorrectable Error Valid
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define LLC_CCUUESR_UERRVLD(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUUESR_UERRVLD_SHIFT)) & LLC_CCUUESR_UERRVLD_MASK)

#define LLC_CCUUESR_UERRTYPE_MASK                (0x1F0U)
#define LLC_CCUUESR_UERRTYPE_SHIFT               (4U)
/*! UERRTYPE - Uncorrectable Error Type
 *  0b00001..Cache memory uncorrectable error
 *  0b00010..Downstream AXI write response error
 *  0b00011..Downstream AXI read repose error
 *  0b00100..Read data buffer memory uncorrectable error
 */
#define LLC_CCUUESR_UERRTYPE(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUUESR_UERRTYPE_SHIFT)) & LLC_CCUUESR_UERRTYPE_MASK)

#define LLC_CCUUESR_UERRINFO_MASK                (0xFFFF0000U)
#define LLC_CCUUESR_UERRINFO_SHIFT               (16U)
/*! UERRINFO - Uncorrectable Error Info
 *  0b000000000000000x..For cache memory uncorrectable errors ([UERRVLD] = 1), see above
 *  0b00000000000000xx..For AXI errors ([UERRVLD] = 2h or 3h), see above
 */
#define LLC_CCUUESR_UERRINFO(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUUESR_UERRINFO_SHIFT)) & LLC_CCUUESR_UERRINFO_MASK)
/*! @} */

/*! @name CCUUELR0 - Uncorrectable Error Location 0 */
/*! @{ */

#define LLC_CCUUELR0_ERRENTRY_MASK               (0x7FFFU)
#define LLC_CCUUELR0_ERRENTRY_SHIFT              (0U)
/*! ERRENTRY - Error Entry */
#define LLC_CCUUELR0_ERRENTRY(x)                 (((uint32_t)(((uint32_t)(x)) << LLC_CCUUELR0_ERRENTRY_SHIFT)) & LLC_CCUUELR0_ERRENTRY_MASK)

#define LLC_CCUUELR0_ERRWAY_MASK                 (0x1F8000U)
#define LLC_CCUUELR0_ERRWAY_SHIFT                (15U)
/*! ERRWAY - Error Way */
#define LLC_CCUUELR0_ERRWAY(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUUELR0_ERRWAY_SHIFT)) & LLC_CCUUELR0_ERRWAY_MASK)

#define LLC_CCUUELR0_ERRWORD_MASK                (0xFFE00000U)
#define LLC_CCUUELR0_ERRWORD_SHIFT               (21U)
/*! ERRWORD - Error Word */
#define LLC_CCUUELR0_ERRWORD(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUUELR0_ERRWORD_SHIFT)) & LLC_CCUUELR0_ERRWORD_MASK)
/*! @} */

/*! @name CCUUELR1 - Uncorrectable Error Location 1 */
/*! @{ */

#define LLC_CCUUELR1_ERRADDR_MASK                (0x7FFFFFFFU)
#define LLC_CCUUELR1_ERRADDR_SHIFT               (0U)
/*! ERRADDR - Error Address */
#define LLC_CCUUELR1_ERRADDR(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUUELR1_ERRADDR_SHIFT)) & LLC_CCUUELR1_ERRADDR_MASK)
/*! @} */

/*! @name CCUIIDR - Instance Identification */
/*! @{ */

#define LLC_CCUIIDR_INSTANCE_ID_MASK             (0xFFFFFFFFU)
#define LLC_CCUIIDR_INSTANCE_ID_SHIFT            (0U)
/*! INSTANCE_ID - Instance ID */
#define LLC_CCUIIDR_INSTANCE_ID(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUIIDR_INSTANCE_ID_SHIFT)) & LLC_CCUIIDR_INSTANCE_ID_MASK)
/*! @} */

/*! @name CCUIDR - Version Identification */
/*! @{ */

#define LLC_CCUIDR_PATCHRELVER_MASK              (0xFU)
#define LLC_CCUIDR_PATCHRELVER_SHIFT             (0U)
/*! PATCHRELVER - Patch Release Version */
#define LLC_CCUIDR_PATCHRELVER(x)                (((uint32_t)(((uint32_t)(x)) << LLC_CCUIDR_PATCHRELVER_SHIFT)) & LLC_CCUIDR_PATCHRELVER_MASK)

#define LLC_CCUIDR_MINRELVER_MASK                (0xF0U)
#define LLC_CCUIDR_MINRELVER_SHIFT               (4U)
/*! MINRELVER - Minor Release Version */
#define LLC_CCUIDR_MINRELVER(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUIDR_MINRELVER_SHIFT)) & LLC_CCUIDR_MINRELVER_MASK)

#define LLC_CCUIDR_MAIRELVER_MASK                (0xF00U)
#define LLC_CCUIDR_MAIRELVER_SHIFT               (8U)
/*! MAIRELVER - Major Release Version */
#define LLC_CCUIDR_MAIRELVER(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUIDR_MAIRELVER_SHIFT)) & LLC_CCUIDR_MAIRELVER_MASK)
/*! @} */

/*! @name CCUESR - Event Status */
/*! @{ */

#define LLC_CCUESR_STATUS_MASK                   (0x3U)
#define LLC_CCUESR_STATUS_SHIFT                  (0U)
/*! STATUS - Status Flags
 *  0b0x..No performance monitor event
 *  0b1x..Performance monitor event (reserved if not implemented)
 *  0bx0..No cache maintenance completion event
 *  0bx0, 0b0x..No effect
 *  0bx1..Cache maintenance completion event
 *  0bx1, 0b1x..Clear the flag
 */
#define LLC_CCUESR_STATUS(x)                     (((uint32_t)(((uint32_t)(x)) << LLC_CCUESR_STATUS_SHIFT)) & LLC_CCUESR_STATUS_MASK)
/*! @} */

/*! @name CCUEMR - Event Mask */
/*! @{ */

#define LLC_CCUEMR_MASK_MASK                     (0x3U)
#define LLC_CCUEMR_MASK_SHIFT                    (0U)
/*! MASK - Mask
 *  0b0x..Ignores a performance monitor event
 *  0b1x..Enables a performance monitor event
 *  0bx0..Ignores a cache maintenance completion event
 *  0bx1..Enables a cache maintenance completion event
 */
#define LLC_CCUEMR_MASK(x)                       (((uint32_t)(((uint32_t)(x)) << LLC_CCUEMR_MASK_SHIFT)) & LLC_CCUEMR_MASK_MASK)
/*! @} */

/*! @name CCUEAR - Event Alias */
/*! @{ */

#define LLC_CCUEAR_ALIAS_MASK                    (0x3U)
#define LLC_CCUEAR_ALIAS_SHIFT                   (0U)
/*! ALIAS - Alias
 *  0b0x..Ignores a performance monitor event
 *  0b1x..Forces a performance monitor event
 *  0bx0..Ignores a cache maintenance completion event
 *  0bx1..Forces a cache maintenance completion event
 */
#define LLC_CCUEAR_ALIAS(x)                      (((uint32_t)(((uint32_t)(x)) << LLC_CCUEAR_ALIAS_SHIFT)) & LLC_CCUEAR_ALIAS_MASK)
/*! @} */

/*! @name CCUHI - Hardware Information */
/*! @{ */

#define LLC_CCUHI_AXIDATAWIDTH_MASK              (0x7U)
#define LLC_CCUHI_AXIDATAWIDTH_SHIFT             (0U)
/*! AXIDATAWIDTH - AXI Interface Data Width
 *  0b010..128 bits
 *  0b011..256 bits
 *  0b100..512 bits
 *  0b101..1024 bits
 */
#define LLC_CCUHI_AXIDATAWIDTH(x)                (((uint32_t)(((uint32_t)(x)) << LLC_CCUHI_AXIDATAWIDTH_SHIFT)) & LLC_CCUHI_AXIDATAWIDTH_MASK)

#define LLC_CCUHI_CACHELINESIZE_MASK             (0x30000U)
#define LLC_CCUHI_CACHELINESIZE_SHIFT            (16U)
/*! CACHELINESIZE - Cache Line Size
 *  0b01..128 bytes
 */
#define LLC_CCUHI_CACHELINESIZE(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CCUHI_CACHELINESIZE_SHIFT)) & LLC_CCUHI_CACHELINESIZE_MASK)
/*! @} */

/*! @name CCUPMHI - Performance Monitor Hardware Information */
/*! @{ */

#define LLC_CCUPMHI_COUNTERWIDTH_MASK            (0xFFU)
#define LLC_CCUPMHI_COUNTERWIDTH_SHIFT           (0U)
/*! COUNTERWIDTH - Counter Width */
#define LLC_CCUPMHI_COUNTERWIDTH(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMHI_COUNTERWIDTH_SHIFT)) & LLC_CCUPMHI_COUNTERWIDTH_MASK)
/*! @} */

/*! @name CCUPMCTL - Performance Monitor Control */
/*! @{ */

#define LLC_CCUPMCTL_SWRESET_MASK                (0x1U)
#define LLC_CCUPMCTL_SWRESET_SHIFT               (0U)
/*! SWRESET - Software Reset */
#define LLC_CCUPMCTL_SWRESET(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMCTL_SWRESET_SHIFT)) & LLC_CCUPMCTL_SWRESET_MASK)

#define LLC_CCUPMCTL_ENABLE_MASK                 (0x2U)
#define LLC_CCUPMCTL_ENABLE_SHIFT                (1U)
/*! ENABLE - Monitor Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LLC_CCUPMCTL_ENABLE(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMCTL_ENABLE_SHIFT)) & LLC_CCUPMCTL_ENABLE_MASK)

#define LLC_CCUPMCTL_HARDWARE_TRIGGER_MASK       (0x100U)
#define LLC_CCUPMCTL_HARDWARE_TRIGGER_SHIFT      (8U)
/*! HARDWARE_TRIGGER - Hardware Trigger
 *  0b0..Hardware trigger disabled
 *  0b1..Hardware trigger enabled
 */
#define LLC_CCUPMCTL_HARDWARE_TRIGGER(x)         (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMCTL_HARDWARE_TRIGGER_SHIFT)) & LLC_CCUPMCTL_HARDWARE_TRIGGER_MASK)
/*! @} */

/*! @name CCUPMSC - Performance Monitor Slot Configuration */
/*! @{ */

#define LLC_CCUPMSC_DURATION_MASK                (0xFFFFFFFFU)
#define LLC_CCUPMSC_DURATION_SHIFT               (0U)
/*! DURATION - Duration */
#define LLC_CCUPMSC_DURATION(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMSC_DURATION_SHIFT)) & LLC_CCUPMSC_DURATION_MASK)
/*! @} */

/*! @name CCUPMOTC - Performance Monitor OTT Threshold Configuration */
/*! @{ */

#define LLC_CCUPMOTC_RTT_MASK                    (0x7U)
#define LLC_CCUPMOTC_RTT_SHIFT                   (0U)
/*! RTT - Read Transaction Table */
#define LLC_CCUPMOTC_RTT(x)                      (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMOTC_RTT_SHIFT)) & LLC_CCUPMOTC_RTT_MASK)

#define LLC_CCUPMOTC_WTT_MASK                    (0x70000U)
#define LLC_CCUPMOTC_WTT_SHIFT                   (16U)
/*! WTT - Write Transaction Table */
#define LLC_CCUPMOTC_WTT(x)                      (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMOTC_WTT_SHIFT)) & LLC_CCUPMOTC_WTT_MASK)
/*! @} */

/*! @name CCUPMCYCO - Performance Monitor Cycle Counter */
/*! @{ */

#define LLC_CCUPMCYCO_COUNT_MASK                 (0xFFFFFFFFU)
#define LLC_CCUPMCYCO_COUNT_SHIFT                (0U)
/*! COUNT - Counter */
#define LLC_CCUPMCYCO_COUNT(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMCYCO_COUNT_SHIFT)) & LLC_CCUPMCYCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMRRCO - Performance Monitor Read Request Counter */
/*! @{ */

#define LLC_CCUPMRRCO_COUNT_MASK                 (0xFFFFFFFFU)
#define LLC_CCUPMRRCO_COUNT_SHIFT                (0U)
/*! COUNT - Counter */
#define LLC_CCUPMRRCO_COUNT(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMRRCO_COUNT_SHIFT)) & LLC_CCUPMRRCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMWRCO - Performance Monitor Write Request Counter */
/*! @{ */

#define LLC_CCUPMWRCO_COUNT_MASK                 (0xFFFFFFFFU)
#define LLC_CCUPMWRCO_COUNT_SHIFT                (0U)
/*! COUNT - Counter */
#define LLC_CCUPMWRCO_COUNT(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMWRCO_COUNT_SHIFT)) & LLC_CCUPMWRCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMCRRCO - Performance Monitor Cacheable Read Request Counter */
/*! @{ */

#define LLC_CCUPMCRRCO_COUNT_MASK                (0xFFFFFFFFU)
#define LLC_CCUPMCRRCO_COUNT_SHIFT               (0U)
/*! COUNT - Counter */
#define LLC_CCUPMCRRCO_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMCRRCO_COUNT_SHIFT)) & LLC_CCUPMCRRCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMCWRCO - Performance Monitor Cacheable Write Request Counter */
/*! @{ */

#define LLC_CCUPMCWRCO_COUNT_MASK                (0xFFFFFFFFU)
#define LLC_CCUPMCWRCO_COUNT_SHIFT               (0U)
/*! COUNT - Counter */
#define LLC_CCUPMCWRCO_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMCWRCO_COUNT_SHIFT)) & LLC_CCUPMCWRCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMRHCO - Performance Monitor Read Hit Counter */
/*! @{ */

#define LLC_CCUPMRHCO_COUNT_MASK                 (0xFFFFFFFFU)
#define LLC_CCUPMRHCO_COUNT_SHIFT                (0U)
/*! COUNT - Counter */
#define LLC_CCUPMRHCO_COUNT(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMRHCO_COUNT_SHIFT)) & LLC_CCUPMRHCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMWHCO - Performance Monitor Write Hit Counter */
/*! @{ */

#define LLC_CCUPMWHCO_COUNT_MASK                 (0xFFFFFFFFU)
#define LLC_CCUPMWHCO_COUNT_SHIFT                (0U)
/*! COUNT - Counter */
#define LLC_CCUPMWHCO_COUNT(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMWHCO_COUNT_SHIFT)) & LLC_CCUPMWHCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMECO - Performance Monitor Eviction Counter */
/*! @{ */

#define LLC_CCUPMECO_COUNT_MASK                  (0xFFFFFFFFU)
#define LLC_CCUPMECO_COUNT_SHIFT                 (0U)
/*! COUNT - Counter */
#define LLC_CCUPMECO_COUNT(x)                    (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMECO_COUNT_SHIFT)) & LLC_CCUPMECO_COUNT_MASK)
/*! @} */

/*! @name CCUPMRBCO - Performance Monitor Read Beat Counter */
/*! @{ */

#define LLC_CCUPMRBCO_COUNT_MASK                 (0xFFFFFFFFU)
#define LLC_CCUPMRBCO_COUNT_SHIFT                (0U)
/*! COUNT - Counter */
#define LLC_CCUPMRBCO_COUNT(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMRBCO_COUNT_SHIFT)) & LLC_CCUPMRBCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMWBCO - Performance Monitor Write Beat Counter */
/*! @{ */

#define LLC_CCUPMWBCO_COUNT_MASK                 (0xFFFFFFFFU)
#define LLC_CCUPMWBCO_COUNT_SHIFT                (0U)
/*! COUNT - Counter */
#define LLC_CCUPMWBCO_COUNT(x)                   (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMWBCO_COUNT_SHIFT)) & LLC_CCUPMWBCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMRATCO - Performance Monitor RTT Above Threshold Counter */
/*! @{ */

#define LLC_CCUPMRATCO_COUNT_MASK                (0xFFFFFFFFU)
#define LLC_CCUPMRATCO_COUNT_SHIFT               (0U)
/*! COUNT - Counter */
#define LLC_CCUPMRATCO_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMRATCO_COUNT_SHIFT)) & LLC_CCUPMRATCO_COUNT_MASK)
/*! @} */

/*! @name CCUPMWATCO - Performance Monitor WTT Above Threshold Counter */
/*! @{ */

#define LLC_CCUPMWATCO_COUNT_MASK                (0xFFFFFFFFU)
#define LLC_CCUPMWATCO_COUNT_SHIFT               (0U)
/*! COUNT - Counter */
#define LLC_CCUPMWATCO_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << LLC_CCUPMWATCO_COUNT_SHIFT)) & LLC_CCUPMWATCO_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LLC_Register_Masks */


/*!
 * @}
 */ /* end of group LLC_Peripheral_Access_Layer */


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


#endif  /* PERI_LLC_H_ */

