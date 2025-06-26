/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XCACHE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file XCACHE.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for XCACHE
 *
 * CMSIS Peripheral Access Layer for XCACHE
 */

#if !defined(XCACHE_H_)
#define XCACHE_H_                                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- XCACHE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCACHE_Peripheral_Access_Layer XCACHE Peripheral Access Layer
 * @{
 */

/** XCACHE - Register Layout Typedef */
typedef struct {
  __IO uint32_t CCR;                               /**< Cache Control, offset: 0x0 */
  __IO uint32_t CLCR;                              /**< Cache Line Control, offset: 0x4 */
  __IO uint32_t CSAR;                              /**< Cache Search Address, offset: 0x8 */
  __IO uint32_t CCVR;                              /**< Cache Read/Write Value, offset: 0xC */
} XCACHE_Type;

/* ----------------------------------------------------------------------------
   -- XCACHE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCACHE_Register_Masks XCACHE Register Masks
 * @{
 */

/*! @name CCR - Cache Control */
/*! @{ */

#define XCACHE_CCR_ENCACHE_MASK                  (0x1U)
#define XCACHE_CCR_ENCACHE_SHIFT                 (0U)
/*! ENCACHE - Cache Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define XCACHE_CCR_ENCACHE(x)                    (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_ENCACHE_SHIFT)) & XCACHE_CCR_ENCACHE_MASK)

#define XCACHE_CCR_FRCWT_MASK                    (0x4U)
#define XCACHE_CCR_FRCWT_SHIFT                   (2U)
/*! FRCWT - Force Write Through Mode
 *  0b0..Not force
 *  0b1..Force
 */
#define XCACHE_CCR_FRCWT(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_FRCWT_SHIFT)) & XCACHE_CCR_FRCWT_MASK)

#define XCACHE_CCR_FRCNOALLC_MASK                (0x8U)
#define XCACHE_CCR_FRCNOALLC_SHIFT               (3U)
/*! FRCNOALLC - Force No Allocation on Cache Misses
 *  0b0..Allocate on cache misses
 *  0b1..Force no allocation on cache misses
 */
#define XCACHE_CCR_FRCNOALLC(x)                  (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_FRCNOALLC_SHIFT)) & XCACHE_CCR_FRCNOALLC_MASK)

#define XCACHE_CCR_INVW0_MASK                    (0x1000000U)
#define XCACHE_CCR_INVW0_SHIFT                   (24U)
/*! INVW0 - Invalidate Way 0
 *  0b0..No operation
 *  0b1..Invalidate all lines in way 0
 */
#define XCACHE_CCR_INVW0(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_INVW0_SHIFT)) & XCACHE_CCR_INVW0_MASK)

#define XCACHE_CCR_PUSHW0_MASK                   (0x2000000U)
#define XCACHE_CCR_PUSHW0_SHIFT                  (25U)
/*! PUSHW0 - Push Way 0
 *  0b0..No operation
 *  0b1..Pushes all modified lines in way 0
 */
#define XCACHE_CCR_PUSHW0(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_PUSHW0_SHIFT)) & XCACHE_CCR_PUSHW0_MASK)

#define XCACHE_CCR_INVW1_MASK                    (0x4000000U)
#define XCACHE_CCR_INVW1_SHIFT                   (26U)
/*! INVW1 - Invalidate Way 1
 *  0b0..No operation
 *  0b1..Invalidate all lines in way 1
 */
#define XCACHE_CCR_INVW1(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_INVW1_SHIFT)) & XCACHE_CCR_INVW1_MASK)

#define XCACHE_CCR_PUSHW1_MASK                   (0x8000000U)
#define XCACHE_CCR_PUSHW1_SHIFT                  (27U)
/*! PUSHW1 - Push Way 1
 *  0b0..No operation
 *  0b1..Push all modified lines in way 1
 */
#define XCACHE_CCR_PUSHW1(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_PUSHW1_SHIFT)) & XCACHE_CCR_PUSHW1_MASK)

#define XCACHE_CCR_GO_MASK                       (0x80000000U)
#define XCACHE_CCR_GO_SHIFT                      (31U)
/*! GO - Initiate Cache Command
 *  0b0..Write: no effect; Read: no cache command active
 *  0b1..Write: initiate command; Read: cache command active
 */
#define XCACHE_CCR_GO(x)                         (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_GO_SHIFT)) & XCACHE_CCR_GO_MASK)
/*! @} */

/*! @name CLCR - Cache Line Control */
/*! @{ */

#define XCACHE_CLCR_LGO_MASK                     (0x1U)
#define XCACHE_CLCR_LGO_SHIFT                    (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect; Read: no line command active
 *  0b1..Write: initiate line command; Read: line command active
 */
#define XCACHE_CLCR_LGO(x)                       (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LGO_SHIFT)) & XCACHE_CLCR_LGO_MASK)

#define XCACHE_CLCR_CACHEADDR_MASK               (0x3FFCU)
#define XCACHE_CLCR_CACHEADDR_SHIFT              (2U)
/*! CACHEADDR - Cache Address */
#define XCACHE_CLCR_CACHEADDR(x)                 (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_CACHEADDR_SHIFT)) & XCACHE_CLCR_CACHEADDR_MASK)

#define XCACHE_CLCR_WSEL_MASK                    (0x4000U)
#define XCACHE_CLCR_WSEL_SHIFT                   (14U)
/*! WSEL - Way Select
 *  0b0..Way 0
 *  0b1..Way 1
 */
#define XCACHE_CLCR_WSEL(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_WSEL_SHIFT)) & XCACHE_CLCR_WSEL_MASK)

#define XCACHE_CLCR_TDSEL_MASK                   (0x10000U)
#define XCACHE_CLCR_TDSEL_SHIFT                  (16U)
/*! TDSEL - Tag or Data Select
 *  0b0..Data
 *  0b1..Tag
 */
#define XCACHE_CLCR_TDSEL(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_TDSEL_SHIFT)) & XCACHE_CLCR_TDSEL_MASK)

#define XCACHE_CLCR_LCIVB_MASK                   (0x100000U)
#define XCACHE_CLCR_LCIVB_SHIFT                  (20U)
/*! LCIVB - Line Command Initial Valid */
#define XCACHE_CLCR_LCIVB(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCIVB_SHIFT)) & XCACHE_CLCR_LCIVB_MASK)

#define XCACHE_CLCR_LCIMB_MASK                   (0x200000U)
#define XCACHE_CLCR_LCIMB_SHIFT                  (21U)
/*! LCIMB - Line Command Initial Modified */
#define XCACHE_CLCR_LCIMB(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCIMB_SHIFT)) & XCACHE_CLCR_LCIMB_MASK)

#define XCACHE_CLCR_LCWAY_MASK                   (0x400000U)
#define XCACHE_CLCR_LCWAY_SHIFT                  (22U)
/*! LCWAY - Line Command Way */
#define XCACHE_CLCR_LCWAY(x)                     (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCWAY_SHIFT)) & XCACHE_CLCR_LCWAY_MASK)

#define XCACHE_CLCR_LCMD_MASK                    (0x3000000U)
#define XCACHE_CLCR_LCMD_SHIFT                   (24U)
/*! LCMD - Line Command
 *  0b00..Search and read or write
 *  0b01..Invalidate
 *  0b10..Push
 *  0b11..Clear
 */
#define XCACHE_CLCR_LCMD(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCMD_SHIFT)) & XCACHE_CLCR_LCMD_MASK)

#define XCACHE_CLCR_LADSEL_MASK                  (0x4000000U)
#define XCACHE_CLCR_LADSEL_SHIFT                 (26U)
/*! LADSEL - Line Address Select
 *  0b0..Cache address
 *  0b1..Physical address
 */
#define XCACHE_CLCR_LADSEL(x)                    (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LADSEL_SHIFT)) & XCACHE_CLCR_LADSEL_MASK)

#define XCACHE_CLCR_LACC_MASK                    (0x8000000U)
#define XCACHE_CLCR_LACC_SHIFT                   (27U)
/*! LACC - Line Access Type
 *  0b0..Read
 *  0b1..Write
 */
#define XCACHE_CLCR_LACC(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LACC_SHIFT)) & XCACHE_CLCR_LACC_MASK)
/*! @} */

/*! @name CSAR - Cache Search Address */
/*! @{ */

#define XCACHE_CSAR_LGO_MASK                     (0x1U)
#define XCACHE_CSAR_LGO_SHIFT                    (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect; Read: no line command active
 *  0b1..Write: initiate line command; Read: line command active
 */
#define XCACHE_CSAR_LGO(x)                       (((uint32_t)(((uint32_t)(x)) << XCACHE_CSAR_LGO_SHIFT)) & XCACHE_CSAR_LGO_MASK)

#define XCACHE_CSAR_PHYADDR_MASK                 (0xFFFFFFFCU)
#define XCACHE_CSAR_PHYADDR_SHIFT                (2U)
/*! PHYADDR - Physical Address */
#define XCACHE_CSAR_PHYADDR(x)                   (((uint32_t)(((uint32_t)(x)) << XCACHE_CSAR_PHYADDR_SHIFT)) & XCACHE_CSAR_PHYADDR_MASK)
/*! @} */

/*! @name CCVR - Cache Read/Write Value */
/*! @{ */

#define XCACHE_CCVR_DATA_MASK                    (0xFFFFFFFFU)
#define XCACHE_CCVR_DATA_SHIFT                   (0U)
/*! DATA - Cache Read/Write Data */
#define XCACHE_CCVR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << XCACHE_CCVR_DATA_SHIFT)) & XCACHE_CCVR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCACHE_Register_Masks */


/*!
 * @}
 */ /* end of group XCACHE_Peripheral_Access_Layer */


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


#endif  /* XCACHE_H_ */

