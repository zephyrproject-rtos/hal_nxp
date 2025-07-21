/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CACHE64_CTRL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CACHE64_CTRL.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CACHE64_CTRL
 *
 * CMSIS Peripheral Access Layer for CACHE64_CTRL
 */

#if !defined(PERI_CACHE64_CTRL_H_)
#define PERI_CACHE64_CTRL_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- CACHE64_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CACHE64_CTRL_Peripheral_Access_Layer CACHE64_CTRL Peripheral Access Layer
 * @{
 */

/** CACHE64_CTRL - Register Layout Typedef */
typedef struct {
  __IO uint32_t CCR;                               /**< Cache Control, offset: 0x0 */
  __IO uint32_t CLCR;                              /**< Cache Line Control, offset: 0x4 */
  __IO uint32_t CSAR;                              /**< Cache Search Address, offset: 0x8 */
  __IO uint32_t CCVR;                              /**< Cache Read/Write Value, offset: 0xC */
} CACHE64_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- CACHE64_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CACHE64_CTRL_Register_Masks CACHE64_CTRL Register Masks
 * @{
 */

/*! @name CCR - Cache Control */
/*! @{ */

#define CACHE64_CTRL_CCR_ENCACHE_MASK            (0x1U)
#define CACHE64_CTRL_CCR_ENCACHE_SHIFT           (0U)
/*! ENCACHE - Cache Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CACHE64_CTRL_CCR_ENCACHE(x)              (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_ENCACHE_SHIFT)) & CACHE64_CTRL_CCR_ENCACHE_MASK)

#define CACHE64_CTRL_CCR_FRCWT_MASK              (0x4U)
#define CACHE64_CTRL_CCR_FRCWT_SHIFT             (2U)
/*! FRCWT - Force Write Through Mode
 *  0b0..Does not force
 *  0b1..Force
 */
#define CACHE64_CTRL_CCR_FRCWT(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_FRCWT_SHIFT)) & CACHE64_CTRL_CCR_FRCWT_MASK)

#define CACHE64_CTRL_CCR_FRCNOALLC_MASK          (0x8U)
#define CACHE64_CTRL_CCR_FRCNOALLC_SHIFT         (3U)
/*! FRCNOALLC - Forces No Allocation on Cache Misses
 *  0b0..Allocation on cache misses
 *  0b1..Forces no allocation on cache misses (must also have FRCWT asserted)
 */
#define CACHE64_CTRL_CCR_FRCNOALLC(x)            (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_FRCNOALLC_SHIFT)) & CACHE64_CTRL_CCR_FRCNOALLC_MASK)

#define CACHE64_CTRL_CCR_INVW0_MASK              (0x1000000U)
#define CACHE64_CTRL_CCR_INVW0_SHIFT             (24U)
/*! INVW0 - Invalidate Way 0
 *  0b0..No operation
 *  0b1..When you write 1 to GO, invalidates all lines in way 0.
 */
#define CACHE64_CTRL_CCR_INVW0(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_INVW0_SHIFT)) & CACHE64_CTRL_CCR_INVW0_MASK)

#define CACHE64_CTRL_CCR_PUSHW0_MASK             (0x2000000U)
#define CACHE64_CTRL_CCR_PUSHW0_SHIFT            (25U)
/*! PUSHW0 - Push Way 0
 *  0b0..No operation
 *  0b1..When you write 1 to GO, push all modified lines in way 0
 */
#define CACHE64_CTRL_CCR_PUSHW0(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_PUSHW0_SHIFT)) & CACHE64_CTRL_CCR_PUSHW0_MASK)

#define CACHE64_CTRL_CCR_INVW1_MASK              (0x4000000U)
#define CACHE64_CTRL_CCR_INVW1_SHIFT             (26U)
/*! INVW1 - Invalidate Way 1
 *  0b0..No operation
 *  0b1..When you write 1 to GO, invalidates all lines in way 1
 */
#define CACHE64_CTRL_CCR_INVW1(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_INVW1_SHIFT)) & CACHE64_CTRL_CCR_INVW1_MASK)

#define CACHE64_CTRL_CCR_PUSHW1_MASK             (0x8000000U)
#define CACHE64_CTRL_CCR_PUSHW1_SHIFT            (27U)
/*! PUSHW1 - Push Way 1
 *  0b0..No operation
 *  0b1..When you write 1 to GO, push all modified lines in way 1
 */
#define CACHE64_CTRL_CCR_PUSHW1(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_PUSHW1_SHIFT)) & CACHE64_CTRL_CCR_PUSHW1_MASK)

#define CACHE64_CTRL_CCR_GO_MASK                 (0x80000000U)
#define CACHE64_CTRL_CCR_GO_SHIFT                (31U)
/*! GO - Initiate Cache Command
 *  0b0..Write: no effect. Read: no cache command active
 *  0b1..Write: initiates command; Read: cache command active
 */
#define CACHE64_CTRL_CCR_GO(x)                   (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_GO_SHIFT)) & CACHE64_CTRL_CCR_GO_MASK)
/*! @} */

/*! @name CLCR - Cache Line Control */
/*! @{ */

#define CACHE64_CTRL_CLCR_LGO_MASK               (0x1U)
#define CACHE64_CTRL_CLCR_LGO_SHIFT              (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command. Read: line command active.
 */
#define CACHE64_CTRL_CLCR_LGO(x)                 (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LGO_SHIFT)) & CACHE64_CTRL_CLCR_LGO_MASK)

#define CACHE64_CTRL_CLCR_CACHEADDR_MASK         (0x3FFCU)
#define CACHE64_CTRL_CLCR_CACHEADDR_SHIFT        (2U)
/*! CACHEADDR - Cache Address */
#define CACHE64_CTRL_CLCR_CACHEADDR(x)           (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_CACHEADDR_SHIFT)) & CACHE64_CTRL_CLCR_CACHEADDR_MASK)

#define CACHE64_CTRL_CLCR_WSEL_MASK              (0x4000U)
#define CACHE64_CTRL_CLCR_WSEL_SHIFT             (14U)
/*! WSEL - Way Select
 *  0b0..Way 0
 *  0b1..Way 1
 */
#define CACHE64_CTRL_CLCR_WSEL(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_WSEL_SHIFT)) & CACHE64_CTRL_CLCR_WSEL_MASK)

#define CACHE64_CTRL_CLCR_TDSEL_MASK             (0x10000U)
#define CACHE64_CTRL_CLCR_TDSEL_SHIFT            (16U)
/*! TDSEL - Tag or Data Select
 *  0b0..Data
 *  0b1..Tag
 */
#define CACHE64_CTRL_CLCR_TDSEL(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_TDSEL_SHIFT)) & CACHE64_CTRL_CLCR_TDSEL_MASK)

#define CACHE64_CTRL_CLCR_LCIVB_MASK             (0x100000U)
#define CACHE64_CTRL_CLCR_LCIVB_SHIFT            (20U)
/*! LCIVB - Line Command Initial Valid */
#define CACHE64_CTRL_CLCR_LCIVB(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LCIVB_SHIFT)) & CACHE64_CTRL_CLCR_LCIVB_MASK)

#define CACHE64_CTRL_CLCR_LCIMB_MASK             (0x200000U)
#define CACHE64_CTRL_CLCR_LCIMB_SHIFT            (21U)
/*! LCIMB - Line Command Initial Modified */
#define CACHE64_CTRL_CLCR_LCIMB(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LCIMB_SHIFT)) & CACHE64_CTRL_CLCR_LCIMB_MASK)

#define CACHE64_CTRL_CLCR_LCWAY_MASK             (0x400000U)
#define CACHE64_CTRL_CLCR_LCWAY_SHIFT            (22U)
/*! LCWAY - Line Command Way */
#define CACHE64_CTRL_CLCR_LCWAY(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LCWAY_SHIFT)) & CACHE64_CTRL_CLCR_LCWAY_MASK)

#define CACHE64_CTRL_CLCR_LCMD_MASK              (0x3000000U)
#define CACHE64_CTRL_CLCR_LCMD_SHIFT             (24U)
/*! LCMD - Line Command
 *  0b00..Search and read or write
 *  0b01..Invalidate
 *  0b10..Push
 *  0b11..Clear
 */
#define CACHE64_CTRL_CLCR_LCMD(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LCMD_SHIFT)) & CACHE64_CTRL_CLCR_LCMD_MASK)

#define CACHE64_CTRL_CLCR_LADSEL_MASK            (0x4000000U)
#define CACHE64_CTRL_CLCR_LADSEL_SHIFT           (26U)
/*! LADSEL - Line Address Select
 *  0b0..Cache address
 *  0b1..Physical address
 */
#define CACHE64_CTRL_CLCR_LADSEL(x)              (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LADSEL_SHIFT)) & CACHE64_CTRL_CLCR_LADSEL_MASK)

#define CACHE64_CTRL_CLCR_LACC_MASK              (0x8000000U)
#define CACHE64_CTRL_CLCR_LACC_SHIFT             (27U)
/*! LACC - Line Access Type
 *  0b0..Read
 *  0b1..Write
 */
#define CACHE64_CTRL_CLCR_LACC(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LACC_SHIFT)) & CACHE64_CTRL_CLCR_LACC_MASK)
/*! @} */

/*! @name CSAR - Cache Search Address */
/*! @{ */

#define CACHE64_CTRL_CSAR_LGO_MASK               (0x1U)
#define CACHE64_CTRL_CSAR_LGO_SHIFT              (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command. Read: line command active.
 */
#define CACHE64_CTRL_CSAR_LGO(x)                 (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CSAR_LGO_SHIFT)) & CACHE64_CTRL_CSAR_LGO_MASK)

#define CACHE64_CTRL_CSAR_PHYADDR_MASK           (0xFFFFFFFCU)
#define CACHE64_CTRL_CSAR_PHYADDR_SHIFT          (2U)
/*! PHYADDR - Physical Address */
#define CACHE64_CTRL_CSAR_PHYADDR(x)             (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CSAR_PHYADDR_SHIFT)) & CACHE64_CTRL_CSAR_PHYADDR_MASK)
/*! @} */

/*! @name CCVR - Cache Read/Write Value */
/*! @{ */

#define CACHE64_CTRL_CCVR_DATA_MASK              (0xFFFFFFFFU)
#define CACHE64_CTRL_CCVR_DATA_SHIFT             (0U)
/*! DATA - Cache Read/Write Data */
#define CACHE64_CTRL_CCVR_DATA(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCVR_DATA_SHIFT)) & CACHE64_CTRL_CCVR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CACHE64_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group CACHE64_CTRL_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_CACHE64_CTRL_H_ */

