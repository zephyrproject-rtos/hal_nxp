/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RTWDOG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RTWDOG.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RTWDOG
 *
 * CMSIS Peripheral Access Layer for RTWDOG
 */

#if !defined(PERI_RTWDOG_H_)
#define PERI_RTWDOG_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- RTWDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTWDOG_Peripheral_Access_Layer RTWDOG Peripheral Access Layer
 * @{
 */

/** RTWDOG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CS;                                /**< WDOG Control and Status, offset: 0x0 */
  __IO uint32_t CNT;                               /**< WDOG Counter, offset: 0x4 */
  __IO uint32_t TOVAL;                             /**< WDOG Timeout Value, offset: 0x8 */
  __IO uint32_t WIN;                               /**< Watchdog Window, offset: 0xC */
} RTWDOG_Type;

/* ----------------------------------------------------------------------------
   -- RTWDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTWDOG_Register_Masks RTWDOG Register Masks
 * @{
 */

/*! @name CS - WDOG Control and Status */
/*! @{ */

#define RTWDOG_CS_STOP_MASK                      (0x1U)
#define RTWDOG_CS_STOP_SHIFT                     (0U)
/*! STOP - Stop Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTWDOG_CS_STOP(x)                        (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_STOP_SHIFT)) & RTWDOG_CS_STOP_MASK)

#define RTWDOG_CS_WAIT_MASK                      (0x2U)
#define RTWDOG_CS_WAIT_SHIFT                     (1U)
/*! WAIT - Wait Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTWDOG_CS_WAIT(x)                        (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_WAIT_SHIFT)) & RTWDOG_CS_WAIT_MASK)

#define RTWDOG_CS_DBG_MASK                       (0x4U)
#define RTWDOG_CS_DBG_SHIFT                      (2U)
/*! DBG - Debug Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTWDOG_CS_DBG(x)                         (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_DBG_SHIFT)) & RTWDOG_CS_DBG_MASK)

#define RTWDOG_CS_TST_MASK                       (0x18U)
#define RTWDOG_CS_TST_SHIFT                      (3U)
/*! TST - WDOG Test
 *  0b00..Disable WDOG Test mode
 *  0b01..Enable WDOG User mode
 *  0b10-0b11..Enable WDOG Test mode
 */
#define RTWDOG_CS_TST(x)                         (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_TST_SHIFT)) & RTWDOG_CS_TST_MASK)

#define RTWDOG_CS_UPDATE_MASK                    (0x20U)
#define RTWDOG_CS_UPDATE_SHIFT                   (5U)
/*! UPDATE - Updates Allowed
 *  0b0..Updates not allowed
 *  0b1..Updates allowed
 */
#define RTWDOG_CS_UPDATE(x)                      (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_UPDATE_SHIFT)) & RTWDOG_CS_UPDATE_MASK)

#define RTWDOG_CS_INT_MASK                       (0x40U)
#define RTWDOG_CS_INT_SHIFT                      (6U)
/*! INT - WDOG Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTWDOG_CS_INT(x)                         (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_INT_SHIFT)) & RTWDOG_CS_INT_MASK)

#define RTWDOG_CS_EN_MASK                        (0x80U)
#define RTWDOG_CS_EN_SHIFT                       (7U)
/*! EN - WDOG Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTWDOG_CS_EN(x)                          (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_EN_SHIFT)) & RTWDOG_CS_EN_MASK)

#define RTWDOG_CS_CLK_MASK                       (0x300U)
#define RTWDOG_CS_CLK_SHIFT                      (8U)
/*! CLK - WDOG Clock */
#define RTWDOG_CS_CLK(x)                         (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_CLK_SHIFT)) & RTWDOG_CS_CLK_MASK)

#define RTWDOG_CS_RCS_MASK                       (0x400U)
#define RTWDOG_CS_RCS_SHIFT                      (10U)
/*! RCS - Reconfiguration Success
 *  0b0..Unsuccessful
 *  0b1..Successful
 */
#define RTWDOG_CS_RCS(x)                         (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_RCS_SHIFT)) & RTWDOG_CS_RCS_MASK)

#define RTWDOG_CS_ULK_MASK                       (0x800U)
#define RTWDOG_CS_ULK_SHIFT                      (11U)
/*! ULK - Unlock Status
 *  0b0..Locked
 *  0b1..Unlocked
 */
#define RTWDOG_CS_ULK(x)                         (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_ULK_SHIFT)) & RTWDOG_CS_ULK_MASK)

#define RTWDOG_CS_PRES_MASK                      (0x1000U)
#define RTWDOG_CS_PRES_SHIFT                     (12U)
/*! PRES - WDOG Prescaler
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTWDOG_CS_PRES(x)                        (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_PRES_SHIFT)) & RTWDOG_CS_PRES_MASK)

#define RTWDOG_CS_CMD32EN_MASK                   (0x2000U)
#define RTWDOG_CS_CMD32EN_SHIFT                  (13U)
/*! CMD32EN - Command 32 Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTWDOG_CS_CMD32EN(x)                     (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_CMD32EN_SHIFT)) & RTWDOG_CS_CMD32EN_MASK)

#define RTWDOG_CS_FLG_MASK                       (0x4000U)
#define RTWDOG_CS_FLG_SHIFT                      (14U)
/*! FLG - WDOG Interrupt Flag
 *  0b0..No interrupt occurred
 *  0b1..An interrupt occurred
 */
#define RTWDOG_CS_FLG(x)                         (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_FLG_SHIFT)) & RTWDOG_CS_FLG_MASK)

#define RTWDOG_CS_WIN_MASK                       (0x8000U)
#define RTWDOG_CS_WIN_SHIFT                      (15U)
/*! WIN - WDOG Window
 *  0b0..Disable
 *  0b1..Enable
 */
#define RTWDOG_CS_WIN(x)                         (((uint32_t)(((uint32_t)(x)) << RTWDOG_CS_WIN_SHIFT)) & RTWDOG_CS_WIN_MASK)
/*! @} */

/*! @name CNT - WDOG Counter */
/*! @{ */

#define RTWDOG_CNT_CNTLOW_MASK                   (0xFFU)
#define RTWDOG_CNT_CNTLOW_SHIFT                  (0U)
/*! CNTLOW - Counter High Byte */
#define RTWDOG_CNT_CNTLOW(x)                     (((uint32_t)(((uint32_t)(x)) << RTWDOG_CNT_CNTLOW_SHIFT)) & RTWDOG_CNT_CNTLOW_MASK)

#define RTWDOG_CNT_CNTHIGH_MASK                  (0xFF00U)
#define RTWDOG_CNT_CNTHIGH_SHIFT                 (8U)
/*! CNTHIGH - Counter Low Byte */
#define RTWDOG_CNT_CNTHIGH(x)                    (((uint32_t)(((uint32_t)(x)) << RTWDOG_CNT_CNTHIGH_SHIFT)) & RTWDOG_CNT_CNTHIGH_MASK)
/*! @} */

/*! @name TOVAL - WDOG Timeout Value */
/*! @{ */

#define RTWDOG_TOVAL_TOVALLOW_MASK               (0xFFU)
#define RTWDOG_TOVAL_TOVALLOW_SHIFT              (0U)
/*! TOVALLOW - Timeout Value Low */
#define RTWDOG_TOVAL_TOVALLOW(x)                 (((uint32_t)(((uint32_t)(x)) << RTWDOG_TOVAL_TOVALLOW_SHIFT)) & RTWDOG_TOVAL_TOVALLOW_MASK)

#define RTWDOG_TOVAL_TOVALHIGH_MASK              (0xFF00U)
#define RTWDOG_TOVAL_TOVALHIGH_SHIFT             (8U)
/*! TOVALHIGH - Timeout Value High */
#define RTWDOG_TOVAL_TOVALHIGH(x)                (((uint32_t)(((uint32_t)(x)) << RTWDOG_TOVAL_TOVALHIGH_SHIFT)) & RTWDOG_TOVAL_TOVALHIGH_MASK)
/*! @} */

/*! @name WIN - Watchdog Window */
/*! @{ */

#define RTWDOG_WIN_WINLOW_MASK                   (0xFFU)
#define RTWDOG_WIN_WINLOW_SHIFT                  (0U)
/*! WINLOW - Low Byte */
#define RTWDOG_WIN_WINLOW(x)                     (((uint32_t)(((uint32_t)(x)) << RTWDOG_WIN_WINLOW_SHIFT)) & RTWDOG_WIN_WINLOW_MASK)

#define RTWDOG_WIN_WINHIGH_MASK                  (0xFF00U)
#define RTWDOG_WIN_WINHIGH_SHIFT                 (8U)
/*! WINHIGH - High Byte */
#define RTWDOG_WIN_WINHIGH(x)                    (((uint32_t)(((uint32_t)(x)) << RTWDOG_WIN_WINHIGH_SHIFT)) & RTWDOG_WIN_WINHIGH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RTWDOG_Register_Masks */


/*!
 * @}
 */ /* end of group RTWDOG_Peripheral_Access_Layer */


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


#endif  /* PERI_RTWDOG_H_ */

