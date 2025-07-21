/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
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
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ROMCP.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ROMCP
 *
 * CMSIS Peripheral Access Layer for ROMCP
 */

#if !defined(PERI_ROMCP_H_)
#define PERI_ROMCP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
#define ROMCP_ROMPATCHD_COUNT                     16u
#define ROMCP_ROMPATCHA_COUNT                     32u

/** ROMCP - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[180];
  __IO uint32_t ROMPATCHD[ROMCP_ROMPATCHD_COUNT];  /**< Data Registers, array offset: 0xB4, array step: 0x4 */
  __IO uint32_t ROMPATCHCNTL;                      /**< Control Register, offset: 0xF4 */
       uint32_t ROMPATCHENH;                       /**< Enable Register High, offset: 0xF8 */
  __IO uint32_t ROMPATCHENL;                       /**< Enable Register Low, offset: 0xFC */
  __IO uint32_t ROMPATCHA[ROMCP_ROMPATCHA_COUNT];  /**< Address Registers, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[136];
  __IO uint32_t ROMPATCHSR;                        /**< Status Register, offset: 0x208 */
} ROMCP_Type;

/* ----------------------------------------------------------------------------
   -- ROMCP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROMCP_Register_Masks ROMCP Register Masks
 * @{
 */

/*! @name ROMPATCHD - Data Registers */
/*! @{ */

#define ROMCP_ROMPATCHD_DATAX_MASK               (0xFFFFFFFFU)
#define ROMCP_ROMPATCHD_DATAX_SHIFT              (0U)
/*! DATAX - Data Fix Registers */
#define ROMCP_ROMPATCHD_DATAX(x)                 (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHD_DATAX_SHIFT)) & ROMCP_ROMPATCHD_DATAX_MASK)
/*! @} */

/*! @name ROMPATCHCNTL - Control Register */
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

#define ROMCP_ROMPATCHCNTL_DATAFIX8_MASK         (0x100U)
#define ROMCP_ROMPATCHCNTL_DATAFIX8_SHIFT        (8U)
/*! DATAFIX8 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX8(x)           (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX8_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX8_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX9_MASK         (0x200U)
#define ROMCP_ROMPATCHCNTL_DATAFIX9_SHIFT        (9U)
/*! DATAFIX9 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX9(x)           (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX9_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX9_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX10_MASK        (0x400U)
#define ROMCP_ROMPATCHCNTL_DATAFIX10_SHIFT       (10U)
/*! DATAFIX10 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX10(x)          (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX10_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX10_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX11_MASK        (0x800U)
#define ROMCP_ROMPATCHCNTL_DATAFIX11_SHIFT       (11U)
/*! DATAFIX11 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX11(x)          (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX11_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX11_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX12_MASK        (0x1000U)
#define ROMCP_ROMPATCHCNTL_DATAFIX12_SHIFT       (12U)
/*! DATAFIX12 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX12(x)          (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX12_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX12_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX13_MASK        (0x2000U)
#define ROMCP_ROMPATCHCNTL_DATAFIX13_SHIFT       (13U)
/*! DATAFIX13 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX13(x)          (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX13_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX13_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX14_MASK        (0x4000U)
#define ROMCP_ROMPATCHCNTL_DATAFIX14_SHIFT       (14U)
/*! DATAFIX14 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX14(x)          (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX14_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX14_MASK)

#define ROMCP_ROMPATCHCNTL_DATAFIX15_MASK        (0x8000U)
#define ROMCP_ROMPATCHCNTL_DATAFIX15_SHIFT       (15U)
/*! DATAFIX15 - Data Fix Enable
 *  0b0..Trigger an opcode patch
 *  0b1..Trigger a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX15(x)          (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX15_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX15_MASK)

#define ROMCP_ROMPATCHCNTL_DIS_MASK              (0x20000000U)
#define ROMCP_ROMPATCHCNTL_DIS_SHIFT             (29U)
/*! DIS - Patch Disable
 *  0b0..Does not affect any Patch operations (default)
 *  0b1..Disables all Patch operations: data fixing and opcode patching
 */
#define ROMCP_ROMPATCHCNTL_DIS(x)                (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DIS_SHIFT)) & ROMCP_ROMPATCHCNTL_DIS_MASK)

#define ROMCP_ROMPATCHCNTL_LK_MASK               (0x80000000U)
#define ROMCP_ROMPATCHCNTL_LK_SHIFT              (31U)
/*! LK - Register Lock
 *  0b0..All registers remain accessible (unlocked).
 *  0b1..Lock access to all registers. All ROMCP register accesses are treated as read-as-zero, except for this LK
 *       bit which reads as set. All writes are ignored.
 */
#define ROMCP_ROMPATCHCNTL_LK(x)                 (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_LK_SHIFT)) & ROMCP_ROMPATCHCNTL_LK_MASK)
/*! @} */

/*! @name ROMPATCHENL - Enable Register Low */
/*! @{ */

#define ROMCP_ROMPATCHENL_ENABLE_MASK            (0xFFFFFFFFU)
#define ROMCP_ROMPATCHENL_ENABLE_SHIFT           (0U)
/*! ENABLE - Enable Address Comparator
 *  0b00000000000000000000000000000000..Address comparator is disabled
 *  0b00000000000000000000000000000001..Address comparator is enabled; after the associated address is matched, the ROMC will trigger a opcode patch or data fix event.
 */
#define ROMCP_ROMPATCHENL_ENABLE(x)              (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE_MASK)
/*! @} */

/*! @name ROMPATCHA - Address Registers */
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

/*! @name ROMPATCHSR - Status Register */
/*! @{ */

#define ROMCP_ROMPATCHSR_SOURCE_MASK             (0x3FU)
#define ROMCP_ROMPATCHSR_SOURCE_SHIFT            (0U)
/*! SOURCE - ROMCP Source Number
 *  0b000000..Address Comparator 0 matched
 *  0b000001..Address Comparator 1 matched
 *  0b001111..Address Comparator 15 matched
 */
#define ROMCP_ROMPATCHSR_SOURCE(x)               (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHSR_SOURCE_SHIFT)) & ROMCP_ROMPATCHSR_SOURCE_MASK)

#define ROMCP_ROMPATCHSR_SW_MASK                 (0x20000U)
#define ROMCP_ROMPATCHSR_SW_SHIFT                (17U)
/*! SW - ROMCP AHB Multiple Address Comparator Match Indicator
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

