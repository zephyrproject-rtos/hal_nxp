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
**         CMSIS Peripheral Access Layer for AON_ROMCP
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
 * @file AON_ROMCP.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for AON_ROMCP
 *
 * CMSIS Peripheral Access Layer for AON_ROMCP
 */

#if !defined(AON_ROMCP_H_)
#define AON_ROMCP_H_                             /**< Symbol preventing repeated inclusion */

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
   -- AON_ROMCP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_ROMCP_Peripheral_Access_Layer AON_ROMCP Peripheral Access Layer
 * @{
 */

/** AON_ROMCP - Size of Registers Arrays */
#define AON_ROMCP_ROMPATCHD_COUNT                 16u
#define AON_ROMCP_ROMPATCHA_COUNT                 32u

/** AON_ROMCP - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[180];
  __IO uint32_t ROMPATCHD[AON_ROMCP_ROMPATCHD_COUNT]; /**< Data Registers, array offset: 0xB4, array step: 0x4 */
  __IO uint32_t ROMPATCHCNTL;                      /**< Control Register, offset: 0xF4 */
       uint32_t ROMPATCHENH;                       /**< Enable Register High, offset: 0xF8 */
  __IO uint32_t ROMPATCHENL;                       /**< Enable Register Low, offset: 0xFC */
  __IO uint32_t ROMPATCHA[AON_ROMCP_ROMPATCHA_COUNT]; /**< Address Registers, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[136];
  __IO uint32_t ROMPATCHSR;                        /**< Status Register, offset: 0x208 */
} AON_ROMCP_Type;

/* ----------------------------------------------------------------------------
   -- AON_ROMCP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_ROMCP_Register_Masks AON_ROMCP Register Masks
 * @{
 */

/*! @name ROMPATCHD - Data Registers */
/*! @{ */

#define AON_ROMCP_ROMPATCHD_DATAX_MASK           (0xFFFFFFFFU)
#define AON_ROMCP_ROMPATCHD_DATAX_SHIFT          (0U)
/*! DATAX - Data Fix Registers */
#define AON_ROMCP_ROMPATCHD_DATAX(x)             (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHD_DATAX_SHIFT)) & AON_ROMCP_ROMPATCHD_DATAX_MASK)
/*! @} */

/*! @name ROMPATCHCNTL - Control Register */
/*! @{ */

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX0_MASK     (0x1U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX0_SHIFT    (0U)
/*! DATAFIX0 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX0(x)       (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX0_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX0_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX1_MASK     (0x2U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX1_SHIFT    (1U)
/*! DATAFIX1 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX1(x)       (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX1_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX1_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX2_MASK     (0x4U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX2_SHIFT    (2U)
/*! DATAFIX2 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX2(x)       (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX2_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX2_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX3_MASK     (0x8U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX3_SHIFT    (3U)
/*! DATAFIX3 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX3(x)       (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX3_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX3_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX4_MASK     (0x10U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX4_SHIFT    (4U)
/*! DATAFIX4 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX4(x)       (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX4_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX4_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX5_MASK     (0x20U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX5_SHIFT    (5U)
/*! DATAFIX5 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX5(x)       (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX5_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX5_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX6_MASK     (0x40U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX6_SHIFT    (6U)
/*! DATAFIX6 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX6(x)       (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX6_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX6_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX7_MASK     (0x80U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX7_SHIFT    (7U)
/*! DATAFIX7 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX7(x)       (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX7_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX7_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX8_MASK     (0x100U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX8_SHIFT    (8U)
/*! DATAFIX8 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX8(x)       (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX8_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX8_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX9_MASK     (0x200U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX9_SHIFT    (9U)
/*! DATAFIX9 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX9(x)       (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX9_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX9_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX10_MASK    (0x400U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX10_SHIFT   (10U)
/*! DATAFIX10 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX10(x)      (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX10_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX10_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX11_MASK    (0x800U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX11_SHIFT   (11U)
/*! DATAFIX11 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX11(x)      (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX11_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX11_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX12_MASK    (0x1000U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX12_SHIFT   (12U)
/*! DATAFIX12 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX12(x)      (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX12_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX12_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX13_MASK    (0x2000U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX13_SHIFT   (13U)
/*! DATAFIX13 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX13(x)      (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX13_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX13_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX14_MASK    (0x4000U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX14_SHIFT   (14U)
/*! DATAFIX14 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX14(x)      (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX14_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX14_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DATAFIX15_MASK    (0x8000U)
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX15_SHIFT   (15U)
/*! DATAFIX15 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define AON_ROMCP_ROMPATCHCNTL_DATAFIX15(x)      (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DATAFIX15_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DATAFIX15_MASK)

#define AON_ROMCP_ROMPATCHCNTL_DIS_MASK          (0x20000000U)
#define AON_ROMCP_ROMPATCHCNTL_DIS_SHIFT         (29U)
/*! DIS - Patch Disable
 *  0b0..Does not affect any Patch operations (default)
 *  0b1..Disables all Patch operations: data fixing and opcode patching
 */
#define AON_ROMCP_ROMPATCHCNTL_DIS(x)            (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHCNTL_DIS_SHIFT)) & AON_ROMCP_ROMPATCHCNTL_DIS_MASK)
/*! @} */

/*! @name ROMPATCHENL - Enable Register Low */
/*! @{ */

#define AON_ROMCP_ROMPATCHENL_ENABLE_MASK        (0xFFFFFFFFU)
#define AON_ROMCP_ROMPATCHENL_ENABLE_SHIFT       (0U)
/*! ENABLE - Enable Address Comparator
 *  0b00000000000000000000000000000000..Address comparator is disabled
 *  0b00000000000000000000000000000001..Address comparator is enabled; after the associated address is matched, the ROMC will trigger a opcode patch or data fix event.
 */
#define AON_ROMCP_ROMPATCHENL_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHENL_ENABLE_SHIFT)) & AON_ROMCP_ROMPATCHENL_ENABLE_MASK)
/*! @} */

/*! @name ROMPATCHA - Address Registers */
/*! @{ */

#define AON_ROMCP_ROMPATCHA_THUMBX_MASK          (0x1U)
#define AON_ROMCP_ROMPATCHA_THUMBX_SHIFT         (0U)
/*! THUMBX - THUMB Comparator Select
 *  0b0..ARM patch
 *  0b1..THUMB patch (ignore if a data fix)
 */
#define AON_ROMCP_ROMPATCHA_THUMBX(x)            (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHA_THUMBX_SHIFT)) & AON_ROMCP_ROMPATCHA_THUMBX_MASK)

#define AON_ROMCP_ROMPATCHA_ADDRX_MASK           (0x7FFFFEU)
#define AON_ROMCP_ROMPATCHA_ADDRX_SHIFT          (1U)
/*! ADDRX - Address Comparator Registers */
#define AON_ROMCP_ROMPATCHA_ADDRX(x)             (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHA_ADDRX_SHIFT)) & AON_ROMCP_ROMPATCHA_ADDRX_MASK)
/*! @} */

/*! @name ROMPATCHSR - Status Register */
/*! @{ */

#define AON_ROMCP_ROMPATCHSR_SOURCE_MASK         (0x3FU)
#define AON_ROMCP_ROMPATCHSR_SOURCE_SHIFT        (0U)
/*! SOURCE - ROMCP Source Number
 *  0b000000..Address Comparator 0 matched
 *  0b000001..Address Comparator 1 matched
 *  0b001111..Address Comparator 15 matched
 */
#define AON_ROMCP_ROMPATCHSR_SOURCE(x)           (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHSR_SOURCE_SHIFT)) & AON_ROMCP_ROMPATCHSR_SOURCE_MASK)

#define AON_ROMCP_ROMPATCHSR_SW_MASK             (0x20000U)
#define AON_ROMCP_ROMPATCHSR_SW_SHIFT            (17U)
/*! SW - ROMCP AHB Multiple Address Comparator Match Indicator
 *  0b0..No event or comparator collisions have occurred
 *  0b1..A collision has occurred
 */
#define AON_ROMCP_ROMPATCHSR_SW(x)               (((uint32_t)(((uint32_t)(x)) << AON_ROMCP_ROMPATCHSR_SW_SHIFT)) & AON_ROMCP_ROMPATCHSR_SW_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AON_ROMCP_Register_Masks */


/*!
 * @}
 */ /* end of group AON_ROMCP_Peripheral_Access_Layer */


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


#endif  /* AON_ROMCP_H_ */

