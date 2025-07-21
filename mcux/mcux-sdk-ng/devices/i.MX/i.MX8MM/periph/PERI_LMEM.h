/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LMEM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LMEM.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LMEM
 *
 * CMSIS Peripheral Access Layer for LMEM
 */

#if !defined(PERI_LMEM_H_)
#define PERI_LMEM_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- LMEM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LMEM_Peripheral_Access_Layer LMEM Peripheral Access Layer
 * @{
 */

/** LMEM - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCCCR;                             /**< Cache control register, offset: 0x0 */
  __IO uint32_t PCCLCR;                            /**< Cache line control register, offset: 0x4 */
  __IO uint32_t PCCSAR;                            /**< Cache search address register, offset: 0x8 */
  __IO uint32_t PCCCVR;                            /**< Cache read/write value register, offset: 0xC */
       uint8_t RESERVED_0[2032];
  __IO uint32_t PSCCR;                             /**< Cache control register, offset: 0x800 */
  __IO uint32_t PSCLCR;                            /**< Cache line control register, offset: 0x804 */
  __IO uint32_t PSCSAR;                            /**< Cache search address register, offset: 0x808 */
  __IO uint32_t PSCCVR;                            /**< Cache read/write value register, offset: 0x80C */
} LMEM_Type;

/* ----------------------------------------------------------------------------
   -- LMEM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LMEM_Register_Masks LMEM Register Masks
 * @{
 */

/*! @name PCCCR - Cache control register */
/*! @{ */

#define LMEM_PCCCR_ENCACHE_MASK                  (0x1U)
#define LMEM_PCCCR_ENCACHE_SHIFT                 (0U)
/*! ENCACHE - Cache enable
 *  0b0..Cache disabled
 *  0b1..Cache enabled
 */
#define LMEM_PCCCR_ENCACHE(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_ENCACHE_SHIFT)) & LMEM_PCCCR_ENCACHE_MASK)

#define LMEM_PCCCR_ENWRBUF_MASK                  (0x2U)
#define LMEM_PCCCR_ENWRBUF_SHIFT                 (1U)
/*! ENWRBUF - Enable Write Buffer
 *  0b0..Write buffer disabled
 *  0b1..Write buffer enabled
 */
#define LMEM_PCCCR_ENWRBUF(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_ENWRBUF_SHIFT)) & LMEM_PCCCR_ENWRBUF_MASK)

#define LMEM_PCCCR_PCCR2_MASK                    (0x4U)
#define LMEM_PCCCR_PCCR2_SHIFT                   (2U)
/*! PCCR2 - Forces all cacheable spaces to write through */
#define LMEM_PCCCR_PCCR2(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_PCCR2_SHIFT)) & LMEM_PCCCR_PCCR2_MASK)

#define LMEM_PCCCR_PCCR3_MASK                    (0x8U)
#define LMEM_PCCCR_PCCR3_SHIFT                   (3U)
/*! PCCR3 - Forces no allocation on cache misses (must also have ACCR2 asserted) */
#define LMEM_PCCCR_PCCR3(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_PCCR3_SHIFT)) & LMEM_PCCCR_PCCR3_MASK)

#define LMEM_PCCCR_INVW0_MASK                    (0x1000000U)
#define LMEM_PCCCR_INVW0_SHIFT                   (24U)
/*! INVW0 - Invalidate Way 0
 *  0b0..No operation
 *  0b1..When setting the GO bit, invalidate all lines in way 0.
 */
#define LMEM_PCCCR_INVW0(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_INVW0_SHIFT)) & LMEM_PCCCR_INVW0_MASK)

#define LMEM_PCCCR_PUSHW0_MASK                   (0x2000000U)
#define LMEM_PCCCR_PUSHW0_SHIFT                  (25U)
/*! PUSHW0 - Push Way 0
 *  0b0..No operation
 *  0b1..When setting the GO bit, push all modified lines in way 0
 */
#define LMEM_PCCCR_PUSHW0(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_PUSHW0_SHIFT)) & LMEM_PCCCR_PUSHW0_MASK)

#define LMEM_PCCCR_INVW1_MASK                    (0x4000000U)
#define LMEM_PCCCR_INVW1_SHIFT                   (26U)
/*! INVW1 - Invalidate Way 1
 *  0b0..No operation
 *  0b1..When setting the GO bit, invalidate all lines in way 1
 */
#define LMEM_PCCCR_INVW1(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_INVW1_SHIFT)) & LMEM_PCCCR_INVW1_MASK)

#define LMEM_PCCCR_PUSHW1_MASK                   (0x8000000U)
#define LMEM_PCCCR_PUSHW1_SHIFT                  (27U)
/*! PUSHW1 - Push Way 1
 *  0b0..No operation
 *  0b1..When setting the GO bit, push all modified lines in way 1
 */
#define LMEM_PCCCR_PUSHW1(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_PUSHW1_SHIFT)) & LMEM_PCCCR_PUSHW1_MASK)

#define LMEM_PCCCR_GO_MASK                       (0x80000000U)
#define LMEM_PCCCR_GO_SHIFT                      (31U)
/*! GO - Initiate Cache Command
 *  0b0..Write: no effect. Read: no cache command active.
 *  0b1..Write: initiate command indicated by bits 27-24. Read: cache command active.
 */
#define LMEM_PCCCR_GO(x)                         (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_GO_SHIFT)) & LMEM_PCCCR_GO_MASK)
/*! @} */

/*! @name PCCLCR - Cache line control register */
/*! @{ */

#define LMEM_PCCLCR_LGO_MASK                     (0x1U)
#define LMEM_PCCLCR_LGO_SHIFT                    (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command indicated by bits 27-24. Read: line command active.
 */
#define LMEM_PCCLCR_LGO(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LGO_SHIFT)) & LMEM_PCCLCR_LGO_MASK)

#define LMEM_PCCLCR_CACHEADDR_MASK               (0x1FFCU)
#define LMEM_PCCLCR_CACHEADDR_SHIFT              (2U)
/*! CACHEADDR - Cache address */
#define LMEM_PCCLCR_CACHEADDR(x)                 (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_CACHEADDR_SHIFT)) & LMEM_PCCLCR_CACHEADDR_MASK)

#define LMEM_PCCLCR_WSEL_MASK                    (0x4000U)
#define LMEM_PCCLCR_WSEL_SHIFT                   (14U)
/*! WSEL - Way select
 *  0b0..Way 0
 *  0b1..Way 1
 */
#define LMEM_PCCLCR_WSEL(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_WSEL_SHIFT)) & LMEM_PCCLCR_WSEL_MASK)

#define LMEM_PCCLCR_TDSEL_MASK                   (0x10000U)
#define LMEM_PCCLCR_TDSEL_SHIFT                  (16U)
/*! TDSEL - Tag/Data Select
 *  0b0..Data
 *  0b1..Tag
 */
#define LMEM_PCCLCR_TDSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_TDSEL_SHIFT)) & LMEM_PCCLCR_TDSEL_MASK)

#define LMEM_PCCLCR_LCIVB_MASK                   (0x100000U)
#define LMEM_PCCLCR_LCIVB_SHIFT                  (20U)
/*! LCIVB - Line Command Initial Valid Bit */
#define LMEM_PCCLCR_LCIVB(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LCIVB_SHIFT)) & LMEM_PCCLCR_LCIVB_MASK)

#define LMEM_PCCLCR_LCIMB_MASK                   (0x200000U)
#define LMEM_PCCLCR_LCIMB_SHIFT                  (21U)
/*! LCIMB - Line Command Initial Modified Bit */
#define LMEM_PCCLCR_LCIMB(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LCIMB_SHIFT)) & LMEM_PCCLCR_LCIMB_MASK)

#define LMEM_PCCLCR_LCWAY_MASK                   (0x400000U)
#define LMEM_PCCLCR_LCWAY_SHIFT                  (22U)
/*! LCWAY - Line Command Way */
#define LMEM_PCCLCR_LCWAY(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LCWAY_SHIFT)) & LMEM_PCCLCR_LCWAY_MASK)

#define LMEM_PCCLCR_LCMD_MASK                    (0x3000000U)
#define LMEM_PCCLCR_LCMD_SHIFT                   (24U)
/*! LCMD - Line Command
 *  0b00..Search and read or write
 *  0b01..Invalidate
 *  0b10..Push
 *  0b11..Clear
 */
#define LMEM_PCCLCR_LCMD(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LCMD_SHIFT)) & LMEM_PCCLCR_LCMD_MASK)

#define LMEM_PCCLCR_LADSEL_MASK                  (0x4000000U)
#define LMEM_PCCLCR_LADSEL_SHIFT                 (26U)
/*! LADSEL - Line Address Select
 *  0b0..Cache address
 *  0b1..Physical address
 */
#define LMEM_PCCLCR_LADSEL(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LADSEL_SHIFT)) & LMEM_PCCLCR_LADSEL_MASK)

#define LMEM_PCCLCR_LACC_MASK                    (0x8000000U)
#define LMEM_PCCLCR_LACC_SHIFT                   (27U)
/*! LACC - Line access type
 *  0b0..Read
 *  0b1..Write
 */
#define LMEM_PCCLCR_LACC(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LACC_SHIFT)) & LMEM_PCCLCR_LACC_MASK)
/*! @} */

/*! @name PCCSAR - Cache search address register */
/*! @{ */

#define LMEM_PCCSAR_LGO_MASK                     (0x1U)
#define LMEM_PCCSAR_LGO_SHIFT                    (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command indicated by bits CLCR[27:24]. Read: line command active.
 */
#define LMEM_PCCSAR_LGO(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PCCSAR_LGO_SHIFT)) & LMEM_PCCSAR_LGO_MASK)

#define LMEM_PCCSAR_PHYADDR_MASK                 (0xFFFFFFFCU)
#define LMEM_PCCSAR_PHYADDR_SHIFT                (2U)
/*! PHYADDR - Physical Address */
#define LMEM_PCCSAR_PHYADDR(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM_PCCSAR_PHYADDR_SHIFT)) & LMEM_PCCSAR_PHYADDR_MASK)
/*! @} */

/*! @name PCCCVR - Cache read/write value register */
/*! @{ */

#define LMEM_PCCCVR_DATA_MASK                    (0xFFFFFFFFU)
#define LMEM_PCCCVR_DATA_SHIFT                   (0U)
/*! DATA - Cache read/write Data */
#define LMEM_PCCCVR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCVR_DATA_SHIFT)) & LMEM_PCCCVR_DATA_MASK)
/*! @} */

/*! @name PSCCR - Cache control register */
/*! @{ */

#define LMEM_PSCCR_ENCACHE_MASK                  (0x1U)
#define LMEM_PSCCR_ENCACHE_SHIFT                 (0U)
/*! ENCACHE - Cache enable
 *  0b0..Cache disabled
 *  0b1..Cache enabled
 */
#define LMEM_PSCCR_ENCACHE(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM_PSCCR_ENCACHE_SHIFT)) & LMEM_PSCCR_ENCACHE_MASK)

#define LMEM_PSCCR_ENWRBUF_MASK                  (0x2U)
#define LMEM_PSCCR_ENWRBUF_SHIFT                 (1U)
/*! ENWRBUF - Enable Write Buffer
 *  0b0..Write buffer disabled
 *  0b1..Write buffer enabled
 */
#define LMEM_PSCCR_ENWRBUF(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM_PSCCR_ENWRBUF_SHIFT)) & LMEM_PSCCR_ENWRBUF_MASK)

#define LMEM_PSCCR_INVW0_MASK                    (0x1000000U)
#define LMEM_PSCCR_INVW0_SHIFT                   (24U)
/*! INVW0 - Invalidate Way 0
 *  0b0..No operation
 *  0b1..When setting the GO bit, invalidate all lines in way 0.
 */
#define LMEM_PSCCR_INVW0(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PSCCR_INVW0_SHIFT)) & LMEM_PSCCR_INVW0_MASK)

#define LMEM_PSCCR_PUSHW0_MASK                   (0x2000000U)
#define LMEM_PSCCR_PUSHW0_SHIFT                  (25U)
/*! PUSHW0 - Push Way 0
 *  0b0..No operation
 *  0b1..When setting the GO bit, push all modified lines in way 0
 */
#define LMEM_PSCCR_PUSHW0(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PSCCR_PUSHW0_SHIFT)) & LMEM_PSCCR_PUSHW0_MASK)

#define LMEM_PSCCR_INVW1_MASK                    (0x4000000U)
#define LMEM_PSCCR_INVW1_SHIFT                   (26U)
/*! INVW1 - Invalidate Way 1
 *  0b0..No operation
 *  0b1..When setting the GO bit, invalidate all lines in way 1
 */
#define LMEM_PSCCR_INVW1(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PSCCR_INVW1_SHIFT)) & LMEM_PSCCR_INVW1_MASK)

#define LMEM_PSCCR_PUSHW1_MASK                   (0x8000000U)
#define LMEM_PSCCR_PUSHW1_SHIFT                  (27U)
/*! PUSHW1 - Push Way 1
 *  0b0..No operation
 *  0b1..When setting the GO bit, push all modified lines in way 1
 */
#define LMEM_PSCCR_PUSHW1(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PSCCR_PUSHW1_SHIFT)) & LMEM_PSCCR_PUSHW1_MASK)

#define LMEM_PSCCR_GO_MASK                       (0x80000000U)
#define LMEM_PSCCR_GO_SHIFT                      (31U)
/*! GO - Initiate Cache Command
 *  0b0..Write: no effect. Read: no cache command active.
 *  0b1..Write: initiate command indicated by bits 27-24. Read: cache command active.
 */
#define LMEM_PSCCR_GO(x)                         (((uint32_t)(((uint32_t)(x)) << LMEM_PSCCR_GO_SHIFT)) & LMEM_PSCCR_GO_MASK)
/*! @} */

/*! @name PSCLCR - Cache line control register */
/*! @{ */

#define LMEM_PSCLCR_LGO_MASK                     (0x1U)
#define LMEM_PSCLCR_LGO_SHIFT                    (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command indicated by bits 27-24. Read: line command active.
 */
#define LMEM_PSCLCR_LGO(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PSCLCR_LGO_SHIFT)) & LMEM_PSCLCR_LGO_MASK)

#define LMEM_PSCLCR_CACHEADDR_MASK               (0x1FFCU)
#define LMEM_PSCLCR_CACHEADDR_SHIFT              (2U)
/*! CACHEADDR - Cache address */
#define LMEM_PSCLCR_CACHEADDR(x)                 (((uint32_t)(((uint32_t)(x)) << LMEM_PSCLCR_CACHEADDR_SHIFT)) & LMEM_PSCLCR_CACHEADDR_MASK)

#define LMEM_PSCLCR_WSEL_MASK                    (0x4000U)
#define LMEM_PSCLCR_WSEL_SHIFT                   (14U)
/*! WSEL - Way select
 *  0b0..Way 0
 *  0b1..Way 1
 */
#define LMEM_PSCLCR_WSEL(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PSCLCR_WSEL_SHIFT)) & LMEM_PSCLCR_WSEL_MASK)

#define LMEM_PSCLCR_TDSEL_MASK                   (0x10000U)
#define LMEM_PSCLCR_TDSEL_SHIFT                  (16U)
/*! TDSEL - Tag/Data Select
 *  0b0..Data
 *  0b1..Tag
 */
#define LMEM_PSCLCR_TDSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PSCLCR_TDSEL_SHIFT)) & LMEM_PSCLCR_TDSEL_MASK)

#define LMEM_PSCLCR_LCIVB_MASK                   (0x100000U)
#define LMEM_PSCLCR_LCIVB_SHIFT                  (20U)
/*! LCIVB - Line Command Initial Valid Bit */
#define LMEM_PSCLCR_LCIVB(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PSCLCR_LCIVB_SHIFT)) & LMEM_PSCLCR_LCIVB_MASK)

#define LMEM_PSCLCR_LCIMB_MASK                   (0x200000U)
#define LMEM_PSCLCR_LCIMB_SHIFT                  (21U)
/*! LCIMB - Line Command Initial Modified Bit */
#define LMEM_PSCLCR_LCIMB(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PSCLCR_LCIMB_SHIFT)) & LMEM_PSCLCR_LCIMB_MASK)

#define LMEM_PSCLCR_LCWAY_MASK                   (0x400000U)
#define LMEM_PSCLCR_LCWAY_SHIFT                  (22U)
/*! LCWAY - Line Command Way */
#define LMEM_PSCLCR_LCWAY(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PSCLCR_LCWAY_SHIFT)) & LMEM_PSCLCR_LCWAY_MASK)

#define LMEM_PSCLCR_LCMD_MASK                    (0x3000000U)
#define LMEM_PSCLCR_LCMD_SHIFT                   (24U)
/*! LCMD - Line Command
 *  0b00..Search and read or write
 *  0b01..Invalidate
 *  0b10..Push
 *  0b11..Clear
 */
#define LMEM_PSCLCR_LCMD(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PSCLCR_LCMD_SHIFT)) & LMEM_PSCLCR_LCMD_MASK)

#define LMEM_PSCLCR_LADSEL_MASK                  (0x4000000U)
#define LMEM_PSCLCR_LADSEL_SHIFT                 (26U)
/*! LADSEL - Line Address Select
 *  0b0..Cache address
 *  0b1..Physical address
 */
#define LMEM_PSCLCR_LADSEL(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM_PSCLCR_LADSEL_SHIFT)) & LMEM_PSCLCR_LADSEL_MASK)

#define LMEM_PSCLCR_LACC_MASK                    (0x8000000U)
#define LMEM_PSCLCR_LACC_SHIFT                   (27U)
/*! LACC - Line access type
 *  0b0..Read
 *  0b1..Write
 */
#define LMEM_PSCLCR_LACC(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PSCLCR_LACC_SHIFT)) & LMEM_PSCLCR_LACC_MASK)
/*! @} */

/*! @name PSCSAR - Cache search address register */
/*! @{ */

#define LMEM_PSCSAR_LGO_MASK                     (0x1U)
#define LMEM_PSCSAR_LGO_SHIFT                    (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command indicated by bits CLCR[27:24]. Read: line command active.
 */
#define LMEM_PSCSAR_LGO(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PSCSAR_LGO_SHIFT)) & LMEM_PSCSAR_LGO_MASK)

#define LMEM_PSCSAR_PHYADDR_MASK                 (0xFFFFFFFCU)
#define LMEM_PSCSAR_PHYADDR_SHIFT                (2U)
/*! PHYADDR - Physical Address */
#define LMEM_PSCSAR_PHYADDR(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM_PSCSAR_PHYADDR_SHIFT)) & LMEM_PSCSAR_PHYADDR_MASK)
/*! @} */

/*! @name PSCCVR - Cache read/write value register */
/*! @{ */

#define LMEM_PSCCVR_DATA_MASK                    (0xFFFFFFFFU)
#define LMEM_PSCCVR_DATA_SHIFT                   (0U)
/*! DATA - Cache read/write Data */
#define LMEM_PSCCVR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PSCCVR_DATA_SHIFT)) & LMEM_PSCCVR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LMEM_Register_Masks */


/*!
 * @}
 */ /* end of group LMEM_Peripheral_Access_Layer */


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


#endif  /* PERI_LMEM_H_ */

