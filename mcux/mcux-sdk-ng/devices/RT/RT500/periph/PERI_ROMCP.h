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
**         CMSIS Peripheral Access Layer for ROMCP
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
 * @file PERI_ROMCP.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ROMCP
 *
 * CMSIS Peripheral Access Layer for ROMCP
 */

#if !defined(PERI_ROMCP_H_)
#define PERI_ROMCP_H_                            /**< Symbol preventing repeated inclusion */

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
   -- ROMCP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROMCP_Peripheral_Access_Layer ROMCP Peripheral Access Layer
 * @{
 */

/** ROMCP - Size of Registers Arrays */
#define ROMCP_ROMPATCHD_COUNT                     8u
#define ROMCP_ROMPATCHA_COUNT                     16u

/** ROMCP - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[212];
  __IO uint32_t ROMPATCHD[ROMCP_ROMPATCHD_COUNT];  /**< ROMC Data Registers, array offset: 0xD4, array step: 0x4 */
  __IO uint32_t ROMPATCHCNTL;                      /**< ROMC Control Register, offset: 0xF4 */
       uint32_t ROMPATCHENH;                       /**< ROMC Enable Register High, offset: 0xF8 */
  __IO uint32_t ROMPATCHENL;                       /**< ROMC Enable Register Low, offset: 0xFC */
  __IO uint32_t ROMPATCHA[ROMCP_ROMPATCHA_COUNT];  /**< ROMC Address Registers, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[200];
  __IO uint32_t ROMPATCHSR;                        /**< ROMC Status Register, offset: 0x208 */
} ROMCP_Type;

/* ----------------------------------------------------------------------------
   -- ROMCP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROMCP_Register_Masks ROMCP Register Masks
 * @{
 */

/*! @name ROMPATCHD - ROMC Data Registers */
/*! @{ */

#define ROMCP_ROMPATCHD_DATAX_MASK               (0xFFFFFFFFU)
#define ROMCP_ROMPATCHD_DATAX_SHIFT              (0U)
/*! DATAX - Data Fix Registers */
#define ROMCP_ROMPATCHD_DATAX(x)                 (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHD_DATAX_SHIFT)) & ROMCP_ROMPATCHD_DATAX_MASK)
/*! @} */

/*! @name ROMPATCHCNTL - ROMC Control Register */
/*! @{ */

#define ROMCP_ROMPATCHCNTL_DATAFIX0_MASK         (0x1U)
#define ROMCP_ROMPATCHCNTL_DATAFIX0_SHIFT        (0U)
/*! DATAFIX0 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX0(x)           (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX0_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX0_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX1_MASK         (0x2U)
#define ROMCP_ROMPATCHCNTL_DATAFIX1_SHIFT        (1U)
/*! DATAFIX1 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX1(x)           (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX1_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX1_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX2_MASK         (0x4U)
#define ROMCP_ROMPATCHCNTL_DATAFIX2_SHIFT        (2U)
/*! DATAFIX2 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX2(x)           (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX2_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX2_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX3_MASK         (0x8U)
#define ROMCP_ROMPATCHCNTL_DATAFIX3_SHIFT        (3U)
/*! DATAFIX3 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX3(x)           (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX3_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX3_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX4_MASK         (0x10U)
#define ROMCP_ROMPATCHCNTL_DATAFIX4_SHIFT        (4U)
/*! DATAFIX4 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX4(x)           (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX4_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX4_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX5_MASK         (0x20U)
#define ROMCP_ROMPATCHCNTL_DATAFIX5_SHIFT        (5U)
/*! DATAFIX5 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX5(x)           (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX5_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX5_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX6_MASK         (0x40U)
#define ROMCP_ROMPATCHCNTL_DATAFIX6_SHIFT        (6U)
/*! DATAFIX6 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX6(x)           (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX6_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX6_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX7_MASK         (0x80U)
#define ROMCP_ROMPATCHCNTL_DATAFIX7_SHIFT        (7U)
/*! DATAFIX7 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX7(x)           (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX7_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX7_MASK)

#define ROMCP_ROMPATCHCNTL_DIS_MASK              (0x20000000U)
#define ROMCP_ROMPATCHCNTL_DIS_SHIFT             (29U)
/*! DIS - ROMC Disable
 *  0b0..Does not affect any ROMC functions (default)
 *  0b1..Disables all ROMC functions: data fixing and opcode patching
 */
#define ROMCP_ROMPATCHCNTL_DIS(x)                (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DIS_SHIFT)) & ROMCP_ROMPATCHCNTL_DIS_MASK)
/*! @} */

/*! @name ROMPATCHENL - ROMC Enable Register Low */
/*! @{ */

#define ROMCP_ROMPATCHENL_ENABLE0_MASK           (0x1U)
#define ROMCP_ROMPATCHENL_ENABLE0_SHIFT          (0U)
/*! ENABLE0 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE0(x)             (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE0_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE0_MASK)

#define ROMCP_ROMPATCHENL_ENABLE1_MASK           (0x2U)
#define ROMCP_ROMPATCHENL_ENABLE1_SHIFT          (1U)
/*! ENABLE1 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE1(x)             (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE1_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE1_MASK)

#define ROMCP_ROMPATCHENL_ENABLE2_MASK           (0x4U)
#define ROMCP_ROMPATCHENL_ENABLE2_SHIFT          (2U)
/*! ENABLE2 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE2(x)             (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE2_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE2_MASK)

#define ROMCP_ROMPATCHENL_ENABLE3_MASK           (0x8U)
#define ROMCP_ROMPATCHENL_ENABLE3_SHIFT          (3U)
/*! ENABLE3 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE3(x)             (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE3_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE3_MASK)

#define ROMCP_ROMPATCHENL_ENABLE4_MASK           (0x10U)
#define ROMCP_ROMPATCHENL_ENABLE4_SHIFT          (4U)
/*! ENABLE4 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE4(x)             (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE4_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE4_MASK)

#define ROMCP_ROMPATCHENL_ENABLE5_MASK           (0x20U)
#define ROMCP_ROMPATCHENL_ENABLE5_SHIFT          (5U)
/*! ENABLE5 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE5(x)             (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE5_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE5_MASK)

#define ROMCP_ROMPATCHENL_ENABLE6_MASK           (0x40U)
#define ROMCP_ROMPATCHENL_ENABLE6_SHIFT          (6U)
/*! ENABLE6 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE6(x)             (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE6_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE6_MASK)

#define ROMCP_ROMPATCHENL_ENABLE7_MASK           (0x80U)
#define ROMCP_ROMPATCHENL_ENABLE7_SHIFT          (7U)
/*! ENABLE7 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE7(x)             (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE7_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE7_MASK)

#define ROMCP_ROMPATCHENL_ENABLE8_MASK           (0x100U)
#define ROMCP_ROMPATCHENL_ENABLE8_SHIFT          (8U)
/*! ENABLE8 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE8(x)             (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE8_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE8_MASK)

#define ROMCP_ROMPATCHENL_ENABLE9_MASK           (0x200U)
#define ROMCP_ROMPATCHENL_ENABLE9_SHIFT          (9U)
/*! ENABLE9 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE9(x)             (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE9_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE9_MASK)

#define ROMCP_ROMPATCHENL_ENABLE10_MASK          (0x400U)
#define ROMCP_ROMPATCHENL_ENABLE10_SHIFT         (10U)
/*! ENABLE10 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE10(x)            (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE10_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE10_MASK)

#define ROMCP_ROMPATCHENL_ENABLE11_MASK          (0x800U)
#define ROMCP_ROMPATCHENL_ENABLE11_SHIFT         (11U)
/*! ENABLE11 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE11(x)            (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE11_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE11_MASK)

#define ROMCP_ROMPATCHENL_ENABLE12_MASK          (0x1000U)
#define ROMCP_ROMPATCHENL_ENABLE12_SHIFT         (12U)
/*! ENABLE12 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE12(x)            (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE12_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE12_MASK)

#define ROMCP_ROMPATCHENL_ENABLE13_MASK          (0x2000U)
#define ROMCP_ROMPATCHENL_ENABLE13_SHIFT         (13U)
/*! ENABLE13 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE13(x)            (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE13_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE13_MASK)

#define ROMCP_ROMPATCHENL_ENABLE14_MASK          (0x4000U)
#define ROMCP_ROMPATCHENL_ENABLE14_SHIFT         (14U)
/*! ENABLE14 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE14(x)            (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE14_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE14_MASK)

#define ROMCP_ROMPATCHENL_ENABLE15_MASK          (0x8000U)
#define ROMCP_ROMPATCHENL_ENABLE15_SHIFT         (15U)
/*! ENABLE15 - Enable Address Comparator n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ROMCP_ROMPATCHENL_ENABLE15(x)            (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE15_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE15_MASK)
/*! @} */

/*! @name ROMPATCHA - ROMC Address Registers */
/*! @{ */

#define ROMCP_ROMPATCHA_THUMBX_MASK              (0x1U)
#define ROMCP_ROMPATCHA_THUMBX_SHIFT             (0U)
/*! THUMBX - THUMB Comparator Select
 *  0b0..ARM patch
 *  0b1..THUMB patch (ignore if a data fix)
 */
#define ROMCP_ROMPATCHA_THUMBX(x)                (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHA_THUMBX_SHIFT)) & ROMCP_ROMPATCHA_THUMBX_MASK)

#define ROMCP_ROMPATCHA_ADDRX_MASK               (0x7FFFFEU)
#define ROMCP_ROMPATCHA_ADDRX_SHIFT              (1U)
/*! ADDRX - Address Comparator Registers */
#define ROMCP_ROMPATCHA_ADDRX(x)                 (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHA_ADDRX_SHIFT)) & ROMCP_ROMPATCHA_ADDRX_MASK)
/*! @} */

/*! @name ROMPATCHSR - ROMC Status Register */
/*! @{ */

#define ROMCP_ROMPATCHSR_SOURCE_MASK             (0x3FU)
#define ROMCP_ROMPATCHSR_SOURCE_SHIFT            (0U)
/*! SOURCE - ROMC Source Number
 *  0b000000..Address Comparator 0 matched
 *  0b000001..Address Comparator 1 matched
 *  0b001111..Address Comparator 15 matched
 */
#define ROMCP_ROMPATCHSR_SOURCE(x)               (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHSR_SOURCE_SHIFT)) & ROMCP_ROMPATCHSR_SOURCE_MASK)

#define ROMCP_ROMPATCHSR_SW_MASK                 (0x20000U)
#define ROMCP_ROMPATCHSR_SW_SHIFT                (17U)
/*! SW - ROMC AHB Multiple Address Comparator Match Indicator
 *  0b0..No event or comparator collisions have occurred
 *  0b1..A collision has occurred
 */
#define ROMCP_ROMPATCHSR_SW(x)                   (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHSR_SW_SHIFT)) & ROMCP_ROMPATCHSR_SW_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ROMCP_Register_Masks */


/*!
 * @}
 */ /* end of group ROMCP_Peripheral_Access_Layer */


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


#endif  /* PERI_ROMCP_H_ */

