/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
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

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
       uint8_t RESERVED_0[2048];
  __IO uint32_t CCR;                               /**< Cache Control, offset: 0x800 */
  __IO uint32_t CLCR;                              /**< Cache Line Control, offset: 0x804 */
  __IO uint32_t CSAR;                              /**< Cache Search Address, offset: 0x808 */
  __IO uint32_t CCVR;                              /**< Cache Read/Write Value, offset: 0x80C */
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
 *  0b0..Disables
 *  0b1..Enables
 */
#define CACHE64_CTRL_CCR_ENCACHE(x)              (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_ENCACHE_SHIFT)) & CACHE64_CTRL_CCR_ENCACHE_MASK)

#define CACHE64_CTRL_CCR_ENWRBUF_MASK            (0x2U)
#define CACHE64_CTRL_CCR_ENWRBUF_SHIFT           (1U)
/*! ENWRBUF - Enable Write Buffer
 *  0b0..Disables
 *  0b1..Enables
 */
#define CACHE64_CTRL_CCR_ENWRBUF(x)              (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_ENWRBUF_SHIFT)) & CACHE64_CTRL_CCR_ENWRBUF_MASK)

#define CACHE64_CTRL_CCR_INVW0_MASK              (0x1000000U)
#define CACHE64_CTRL_CCR_INVW0_SHIFT             (24U)
/*! INVW0 - Invalidate Way 0
 *  0b0..No operation
 *  0b1..Invalidates all lines in way 0
 */
#define CACHE64_CTRL_CCR_INVW0(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_INVW0_SHIFT)) & CACHE64_CTRL_CCR_INVW0_MASK)

#define CACHE64_CTRL_CCR_PUSHW0_MASK             (0x2000000U)
#define CACHE64_CTRL_CCR_PUSHW0_SHIFT            (25U)
/*! PUSHW0 - Push Way 0
 *  0b0..No operation
 *  0b1..Push all modified lines in way 0
 */
#define CACHE64_CTRL_CCR_PUSHW0(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_PUSHW0_SHIFT)) & CACHE64_CTRL_CCR_PUSHW0_MASK)

#define CACHE64_CTRL_CCR_INVW1_MASK              (0x4000000U)
#define CACHE64_CTRL_CCR_INVW1_SHIFT             (26U)
/*! INVW1 - Invalidate Way 1
 *  0b0..No operation
 *  0b1..Invalidates all lines in way 1
 */
#define CACHE64_CTRL_CCR_INVW1(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_INVW1_SHIFT)) & CACHE64_CTRL_CCR_INVW1_MASK)

#define CACHE64_CTRL_CCR_PUSHW1_MASK             (0x8000000U)
#define CACHE64_CTRL_CCR_PUSHW1_SHIFT            (27U)
/*! PUSHW1 - Push Way 1
 *  0b0..No operation
 *  0b1..Push all modified lines in way 1
 */
#define CACHE64_CTRL_CCR_PUSHW1(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_PUSHW1_SHIFT)) & CACHE64_CTRL_CCR_PUSHW1_MASK)

#define CACHE64_CTRL_CCR_GO_MASK                 (0x80000000U)
#define CACHE64_CTRL_CCR_GO_SHIFT                (31U)
/*! GO - Initiate Cache Command
 *  0b0..Write: no effect; Read: no cache command active
 *  0b1..Write: initiates cache command; Read: cache command active
 */
#define CACHE64_CTRL_CCR_GO(x)                   (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_GO_SHIFT)) & CACHE64_CTRL_CCR_GO_MASK)
/*! @} */

/*! @name CLCR - Cache Line Control */
/*! @{ */

#define CACHE64_CTRL_CLCR_LGO_MASK               (0x1U)
#define CACHE64_CTRL_CLCR_LGO_SHIFT              (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect; Read: no line command active
 *  0b1..Write: initiate line command; Read: line command active
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
/*! TDSEL - Tag Or Data Select
 *  0b0..Data
 *  0b1..Tag
 */
#define CACHE64_CTRL_CLCR_TDSEL(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_TDSEL_SHIFT)) & CACHE64_CTRL_CLCR_TDSEL_MASK)

#define CACHE64_CTRL_CLCR_LCIVB_MASK             (0x100000U)
#define CACHE64_CTRL_CLCR_LCIVB_SHIFT            (20U)
/*! LCIVB - Line Command Initial Valid Bit
 *  0b0..Initial state 0
 *  0b1..Initial state 1
 */
#define CACHE64_CTRL_CLCR_LCIVB(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LCIVB_SHIFT)) & CACHE64_CTRL_CLCR_LCIVB_MASK)

#define CACHE64_CTRL_CLCR_LCIMB_MASK             (0x200000U)
#define CACHE64_CTRL_CLCR_LCIMB_SHIFT            (21U)
/*! LCIMB - Line Command Initial Modified Bit
 *  0b0..Initial state 0
 *  0b1..Initial state 1
 */
#define CACHE64_CTRL_CLCR_LCIMB(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LCIMB_SHIFT)) & CACHE64_CTRL_CLCR_LCIMB_MASK)

#define CACHE64_CTRL_CLCR_LCWAY_MASK             (0x400000U)
#define CACHE64_CTRL_CLCR_LCWAY_SHIFT            (22U)
/*! LCWAY - Line Command Way
 *  0b0..Way 0
 *  0b1..Way 1
 */
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
 *  0b0..Cache
 *  0b1..Physical
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
 *  0b0..Write: no effect; Read: no line command active
 *  0b1..Write: initiate line command; Read: line command active
 */
#define CACHE64_CTRL_CSAR_LGO(x)                 (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CSAR_LGO_SHIFT)) & CACHE64_CTRL_CSAR_LGO_MASK)

#define CACHE64_CTRL_CSAR_PHYADDR27_1_MASK       (0xFFFFFFEU)
#define CACHE64_CTRL_CSAR_PHYADDR27_1_SHIFT      (1U)
/*! PHYADDR27_1 - Physical Address */
#define CACHE64_CTRL_CSAR_PHYADDR27_1(x)         (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CSAR_PHYADDR27_1_SHIFT)) & CACHE64_CTRL_CSAR_PHYADDR27_1_MASK)

#define CACHE64_CTRL_CSAR_PHYADDR31_29_MASK      (0xE0000000U)
#define CACHE64_CTRL_CSAR_PHYADDR31_29_SHIFT     (29U)
/*! PHYADDR31_29 - Physical Address */
#define CACHE64_CTRL_CSAR_PHYADDR31_29(x)        (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CSAR_PHYADDR31_29_SHIFT)) & CACHE64_CTRL_CSAR_PHYADDR31_29_MASK)
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

