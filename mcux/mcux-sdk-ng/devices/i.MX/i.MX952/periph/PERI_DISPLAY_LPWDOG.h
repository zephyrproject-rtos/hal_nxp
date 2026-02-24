/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DISPLAY_LPWDOG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DISPLAY_LPWDOG.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DISPLAY_LPWDOG
 *
 * CMSIS Peripheral Access Layer for DISPLAY_LPWDOG
 */

#if !defined(PERI_DISPLAY_LPWDOG_H_)
#define PERI_DISPLAY_LPWDOG_H_                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- DISPLAY_LPWDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_LPWDOG_Peripheral_Access_Layer DISPLAY_LPWDOG Peripheral Access Layer
 * @{
 */

/** DISPLAY_LPWDOG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CS;                                /**< WDOG Control and Status, offset: 0x0 */
  __IO uint32_t CNT;                               /**< WDOG Counter, offset: 0x4 */
  __IO uint32_t TOVAL;                             /**< WDOG Timeout Value, offset: 0x8 */
  __IO uint32_t WIN;                               /**< Watchdog Window, offset: 0xC */
} DISPLAY_LPWDOG_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_LPWDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_LPWDOG_Register_Masks DISPLAY_LPWDOG Register Masks
 * @{
 */

/*! @name CS - WDOG Control and Status */
/*! @{ */

#define DISPLAY_LPWDOG_CS_STOP_MASK              (0x1U)
#define DISPLAY_LPWDOG_CS_STOP_SHIFT             (0U)
/*! STOP - Stop Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DISPLAY_LPWDOG_CS_STOP(x)                (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_STOP_SHIFT)) & DISPLAY_LPWDOG_CS_STOP_MASK)

#define DISPLAY_LPWDOG_CS_WAIT_MASK              (0x2U)
#define DISPLAY_LPWDOG_CS_WAIT_SHIFT             (1U)
/*! WAIT - Wait Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DISPLAY_LPWDOG_CS_WAIT(x)                (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_WAIT_SHIFT)) & DISPLAY_LPWDOG_CS_WAIT_MASK)

#define DISPLAY_LPWDOG_CS_DBG_MASK               (0x4U)
#define DISPLAY_LPWDOG_CS_DBG_SHIFT              (2U)
/*! DBG - Debug Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DISPLAY_LPWDOG_CS_DBG(x)                 (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_DBG_SHIFT)) & DISPLAY_LPWDOG_CS_DBG_MASK)

#define DISPLAY_LPWDOG_CS_TST_MASK               (0x18U)
#define DISPLAY_LPWDOG_CS_TST_SHIFT              (3U)
/*! TST - WDOG Test
 *  0b00..Disable WDOG Test mode
 *  0b01..Enable WDOG User mode
 *  0b10-0b11..Enable WDOG Test mode
 */
#define DISPLAY_LPWDOG_CS_TST(x)                 (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_TST_SHIFT)) & DISPLAY_LPWDOG_CS_TST_MASK)

#define DISPLAY_LPWDOG_CS_UPDATE_MASK            (0x20U)
#define DISPLAY_LPWDOG_CS_UPDATE_SHIFT           (5U)
/*! UPDATE - Updates Allowed
 *  0b0..Updates not allowed
 *  0b1..Updates allowed
 */
#define DISPLAY_LPWDOG_CS_UPDATE(x)              (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_UPDATE_SHIFT)) & DISPLAY_LPWDOG_CS_UPDATE_MASK)

#define DISPLAY_LPWDOG_CS_INT_MASK               (0x40U)
#define DISPLAY_LPWDOG_CS_INT_SHIFT              (6U)
/*! INT - WDOG Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DISPLAY_LPWDOG_CS_INT(x)                 (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_INT_SHIFT)) & DISPLAY_LPWDOG_CS_INT_MASK)

#define DISPLAY_LPWDOG_CS_EN_MASK                (0x80U)
#define DISPLAY_LPWDOG_CS_EN_SHIFT               (7U)
/*! EN - WDOG Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DISPLAY_LPWDOG_CS_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_EN_SHIFT)) & DISPLAY_LPWDOG_CS_EN_MASK)

#define DISPLAY_LPWDOG_CS_CLK_MASK               (0x300U)
#define DISPLAY_LPWDOG_CS_CLK_SHIFT              (8U)
/*! CLK - WDOG Clock
 *  0b00..IPG
 *  0b01..LPO
 *  0b10..INT
 *  0b11..EXT
 */
#define DISPLAY_LPWDOG_CS_CLK(x)                 (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_CLK_SHIFT)) & DISPLAY_LPWDOG_CS_CLK_MASK)

#define DISPLAY_LPWDOG_CS_PRES_MASK              (0x1000U)
#define DISPLAY_LPWDOG_CS_PRES_SHIFT             (12U)
/*! PRES - WDOG Prescaler
 *  0b0..Disable
 *  0b1..Enable
 */
#define DISPLAY_LPWDOG_CS_PRES(x)                (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_PRES_SHIFT)) & DISPLAY_LPWDOG_CS_PRES_MASK)

#define DISPLAY_LPWDOG_CS_CMD32EN_MASK           (0x2000U)
#define DISPLAY_LPWDOG_CS_CMD32EN_SHIFT          (13U)
/*! CMD32EN - Command 32 Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DISPLAY_LPWDOG_CS_CMD32EN(x)             (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_CMD32EN_SHIFT)) & DISPLAY_LPWDOG_CS_CMD32EN_MASK)

#define DISPLAY_LPWDOG_CS_FLG_MASK               (0x4000U)
#define DISPLAY_LPWDOG_CS_FLG_SHIFT              (14U)
/*! FLG - WDOG Interrupt Flag
 *  0b0..No interrupt occurred
 *  0b1..An interrupt occurred
 */
#define DISPLAY_LPWDOG_CS_FLG(x)                 (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_FLG_SHIFT)) & DISPLAY_LPWDOG_CS_FLG_MASK)

#define DISPLAY_LPWDOG_CS_WIN_MASK               (0x8000U)
#define DISPLAY_LPWDOG_CS_WIN_SHIFT              (15U)
/*! WIN - WDOG Window
 *  0b0..Disable
 *  0b1..Enable
 */
#define DISPLAY_LPWDOG_CS_WIN(x)                 (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_WIN_SHIFT)) & DISPLAY_LPWDOG_CS_WIN_MASK)

#define DISPLAY_LPWDOG_CS_CLEAR_MASK             (0x10000U)
#define DISPLAY_LPWDOG_CS_CLEAR_SHIFT            (16U)
/*! CLEAR - WDOG Reset Clear
 *  0b0..No effect
 *  0b1..Clears WDOG reset.
 */
#define DISPLAY_LPWDOG_CS_CLEAR(x)               (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CS_CLEAR_SHIFT)) & DISPLAY_LPWDOG_CS_CLEAR_MASK)
/*! @} */

/*! @name CNT - WDOG Counter */
/*! @{ */

#define DISPLAY_LPWDOG_CNT_CNTLOW_MASK           (0xFFU)
#define DISPLAY_LPWDOG_CNT_CNTLOW_SHIFT          (0U)
/*! CNTLOW - Counter Low Byte */
#define DISPLAY_LPWDOG_CNT_CNTLOW(x)             (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CNT_CNTLOW_SHIFT)) & DISPLAY_LPWDOG_CNT_CNTLOW_MASK)

#define DISPLAY_LPWDOG_CNT_CNTHIGH_MASK          (0xFF00U)
#define DISPLAY_LPWDOG_CNT_CNTHIGH_SHIFT         (8U)
/*! CNTHIGH - Counter High Byte */
#define DISPLAY_LPWDOG_CNT_CNTHIGH(x)            (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_CNT_CNTHIGH_SHIFT)) & DISPLAY_LPWDOG_CNT_CNTHIGH_MASK)
/*! @} */

/*! @name TOVAL - WDOG Timeout Value */
/*! @{ */

#define DISPLAY_LPWDOG_TOVAL_TOVALLOW_MASK       (0xFFU)
#define DISPLAY_LPWDOG_TOVAL_TOVALLOW_SHIFT      (0U)
/*! TOVALLOW - Timeout Value Low */
#define DISPLAY_LPWDOG_TOVAL_TOVALLOW(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_TOVAL_TOVALLOW_SHIFT)) & DISPLAY_LPWDOG_TOVAL_TOVALLOW_MASK)

#define DISPLAY_LPWDOG_TOVAL_TOVALHIGH_MASK      (0xFF00U)
#define DISPLAY_LPWDOG_TOVAL_TOVALHIGH_SHIFT     (8U)
/*! TOVALHIGH - Timeout Value High */
#define DISPLAY_LPWDOG_TOVAL_TOVALHIGH(x)        (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_TOVAL_TOVALHIGH_SHIFT)) & DISPLAY_LPWDOG_TOVAL_TOVALHIGH_MASK)
/*! @} */

/*! @name WIN - Watchdog Window */
/*! @{ */

#define DISPLAY_LPWDOG_WIN_WINLOW_MASK           (0xFFU)
#define DISPLAY_LPWDOG_WIN_WINLOW_SHIFT          (0U)
/*! WINLOW - Low Byte */
#define DISPLAY_LPWDOG_WIN_WINLOW(x)             (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_WIN_WINLOW_SHIFT)) & DISPLAY_LPWDOG_WIN_WINLOW_MASK)

#define DISPLAY_LPWDOG_WIN_WINHIGH_MASK          (0xFF00U)
#define DISPLAY_LPWDOG_WIN_WINHIGH_SHIFT         (8U)
/*! WINHIGH - High Byte */
#define DISPLAY_LPWDOG_WIN_WINHIGH(x)            (((uint32_t)(((uint32_t)(x)) << DISPLAY_LPWDOG_WIN_WINHIGH_SHIFT)) & DISPLAY_LPWDOG_WIN_WINHIGH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DISPLAY_LPWDOG_Register_Masks */


/*!
 * @}
 */ /* end of group DISPLAY_LPWDOG_Peripheral_Access_Layer */


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


#endif  /* PERI_DISPLAY_LPWDOG_H_ */

