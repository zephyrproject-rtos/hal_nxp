/*
** ###################################################################
**     Processors:          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 5.0, 2021-03-01
**     Build:               b240708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WDOG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**
** ###################################################################
*/

/*!
 * @file WDOG.h
 * @version 5.0
 * @date 2021-03-01
 * @brief CMSIS Peripheral Access Layer for WDOG
 *
 * CMSIS Peripheral Access Layer for WDOG
 */

#if !defined(WDOG_H_)
#define WDOG_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */

/** WDOG - Register Layout Typedef */
typedef struct {
  __IO uint16_t WCR;                               /**< Watchdog Control Register, offset: 0x0 */
  __IO uint16_t WSR;                               /**< Watchdog Service Register, offset: 0x2 */
  __I  uint16_t WRSR;                              /**< Watchdog Reset Status Register, offset: 0x4 */
  __IO uint16_t WICR;                              /**< Watchdog Interrupt Control Register, offset: 0x6 */
  __IO uint16_t WMCR;                              /**< Watchdog Miscellaneous Control Register, offset: 0x8 */
} WDOG_Type;

/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/*! @name WCR - Watchdog Control Register */
/*! @{ */

#define WDOG_WCR_WDZST_MASK                      (0x1U)
#define WDOG_WCR_WDZST_SHIFT                     (0U)
/*! WDZST
 *  0b0..Continue timer operation (Default).
 *  0b1..Suspend the watchdog timer.
 */
#define WDOG_WCR_WDZST(x)                        (((uint16_t)(((uint16_t)(x)) << WDOG_WCR_WDZST_SHIFT)) & WDOG_WCR_WDZST_MASK)

#define WDOG_WCR_WDBG_MASK                       (0x2U)
#define WDOG_WCR_WDBG_SHIFT                      (1U)
/*! WDBG
 *  0b0..Continue WDOG timer operation (Default).
 *  0b1..Suspend the watchdog timer.
 */
#define WDOG_WCR_WDBG(x)                         (((uint16_t)(((uint16_t)(x)) << WDOG_WCR_WDBG_SHIFT)) & WDOG_WCR_WDBG_MASK)

#define WDOG_WCR_WDE_MASK                        (0x4U)
#define WDOG_WCR_WDE_SHIFT                       (2U)
/*! WDE
 *  0b0..Disable the Watchdog (Default).
 *  0b1..Enable the Watchdog.
 */
#define WDOG_WCR_WDE(x)                          (((uint16_t)(((uint16_t)(x)) << WDOG_WCR_WDE_SHIFT)) & WDOG_WCR_WDE_MASK)

#define WDOG_WCR_WDT_MASK                        (0x8U)
#define WDOG_WCR_WDT_SHIFT                       (3U)
/*! WDT
 *  0b0..No effect on WDOG_B (Default).
 *  0b1..Assert WDOG_B upon a Watchdog Time-out event.
 */
#define WDOG_WCR_WDT(x)                          (((uint16_t)(((uint16_t)(x)) << WDOG_WCR_WDT_SHIFT)) & WDOG_WCR_WDT_MASK)

#define WDOG_WCR_SRS_MASK                        (0x10U)
#define WDOG_WCR_SRS_SHIFT                       (4U)
/*! SRS
 *  0b0..Assert system reset signal.
 *  0b1..No effect on the system (Default).
 */
#define WDOG_WCR_SRS(x)                          (((uint16_t)(((uint16_t)(x)) << WDOG_WCR_SRS_SHIFT)) & WDOG_WCR_SRS_MASK)

#define WDOG_WCR_WDA_MASK                        (0x20U)
#define WDOG_WCR_WDA_SHIFT                       (5U)
/*! WDA
 *  0b0..Assert WDOG_B output.
 *  0b1..No effect on system (Default).
 */
#define WDOG_WCR_WDA(x)                          (((uint16_t)(((uint16_t)(x)) << WDOG_WCR_WDA_SHIFT)) & WDOG_WCR_WDA_MASK)

#define WDOG_WCR_SRE_MASK                        (0x40U)
#define WDOG_WCR_SRE_SHIFT                       (6U)
/*! SRE - Software Reset Extension. Required to be set to 1 when used in conjunction with the Software Reset Signal (SRS).
 *  0b0..Reserved
 *  0b1..This bit must be set to 1.
 */
#define WDOG_WCR_SRE(x)                          (((uint16_t)(((uint16_t)(x)) << WDOG_WCR_SRE_SHIFT)) & WDOG_WCR_SRE_MASK)

#define WDOG_WCR_WDW_MASK                        (0x80U)
#define WDOG_WCR_WDW_SHIFT                       (7U)
/*! WDW
 *  0b0..Continue WDOG timer operation (Default).
 *  0b1..Suspend WDOG timer operation.
 */
#define WDOG_WCR_WDW(x)                          (((uint16_t)(((uint16_t)(x)) << WDOG_WCR_WDW_SHIFT)) & WDOG_WCR_WDW_MASK)

#define WDOG_WCR_WT_MASK                         (0xFF00U)
#define WDOG_WCR_WT_SHIFT                        (8U)
/*! WT
 *  0b00000000..- 0.5 Seconds (Default).
 *  0b00000001..- 1.0 Seconds.
 *  0b00000010..- 1.5 Seconds.
 *  0b00000011..- 2.0 Seconds.
 *  0b11111111..- 128 Seconds.
 */
#define WDOG_WCR_WT(x)                           (((uint16_t)(((uint16_t)(x)) << WDOG_WCR_WT_SHIFT)) & WDOG_WCR_WT_MASK)
/*! @} */

/*! @name WSR - Watchdog Service Register */
/*! @{ */

#define WDOG_WSR_WSR_MASK                        (0xFFFFU)
#define WDOG_WSR_WSR_SHIFT                       (0U)
/*! WSR
 *  0b0101010101010101..Write to the Watchdog Service Register (WDOG_WSR).
 *  0b1010101010101010..Write to the Watchdog Service Register (WDOG_WSR).
 */
#define WDOG_WSR_WSR(x)                          (((uint16_t)(((uint16_t)(x)) << WDOG_WSR_WSR_SHIFT)) & WDOG_WSR_WSR_MASK)
/*! @} */

/*! @name WRSR - Watchdog Reset Status Register */
/*! @{ */

#define WDOG_WRSR_SFTW_MASK                      (0x1U)
#define WDOG_WRSR_SFTW_SHIFT                     (0U)
/*! SFTW
 *  0b0..Reset is not the result of a software reset.
 *  0b1..Reset is the result of a software reset.
 */
#define WDOG_WRSR_SFTW(x)                        (((uint16_t)(((uint16_t)(x)) << WDOG_WRSR_SFTW_SHIFT)) & WDOG_WRSR_SFTW_MASK)

#define WDOG_WRSR_TOUT_MASK                      (0x2U)
#define WDOG_WRSR_TOUT_SHIFT                     (1U)
/*! TOUT
 *  0b0..Reset is not the result of a WDOG timeout.
 *  0b1..Reset is the result of a WDOG timeout.
 */
#define WDOG_WRSR_TOUT(x)                        (((uint16_t)(((uint16_t)(x)) << WDOG_WRSR_TOUT_SHIFT)) & WDOG_WRSR_TOUT_MASK)

#define WDOG_WRSR_POR_MASK                       (0x10U)
#define WDOG_WRSR_POR_SHIFT                      (4U)
/*! POR
 *  0b0..Reset is not the result of a power on reset.
 *  0b1..Reset is the result of a power on reset.
 */
#define WDOG_WRSR_POR(x)                         (((uint16_t)(((uint16_t)(x)) << WDOG_WRSR_POR_SHIFT)) & WDOG_WRSR_POR_MASK)
/*! @} */

/*! @name WICR - Watchdog Interrupt Control Register */
/*! @{ */

#define WDOG_WICR_WICT_MASK                      (0xFFU)
#define WDOG_WICR_WICT_SHIFT                     (0U)
/*! WICT
 *  0b00000000..WICT[7:0] = Time duration between interrupt and time-out is 0 seconds.
 *  0b00000001..WICT[7:0] = Time duration between interrupt and time-out is 0.5 seconds.
 *  0b00000100..WICT[7:0] = Time duration between interrupt and time-out is 2 seconds (Default).
 *  0b11111111..WICT[7:0] = Time duration between interrupt and time-out is 127.5 seconds.
 */
#define WDOG_WICR_WICT(x)                        (((uint16_t)(((uint16_t)(x)) << WDOG_WICR_WICT_SHIFT)) & WDOG_WICR_WICT_MASK)

#define WDOG_WICR_WTIS_MASK                      (0x4000U)
#define WDOG_WICR_WTIS_SHIFT                     (14U)
/*! WTIS
 *  0b0..No interrupt has occurred (Default).
 *  0b1..Interrupt has occurred
 */
#define WDOG_WICR_WTIS(x)                        (((uint16_t)(((uint16_t)(x)) << WDOG_WICR_WTIS_SHIFT)) & WDOG_WICR_WTIS_MASK)

#define WDOG_WICR_WIE_MASK                       (0x8000U)
#define WDOG_WICR_WIE_SHIFT                      (15U)
/*! WIE
 *  0b0..Disable Interrupt (Default).
 *  0b1..Enable Interrupt.
 */
#define WDOG_WICR_WIE(x)                         (((uint16_t)(((uint16_t)(x)) << WDOG_WICR_WIE_SHIFT)) & WDOG_WICR_WIE_MASK)
/*! @} */

/*! @name WMCR - Watchdog Miscellaneous Control Register */
/*! @{ */

#define WDOG_WMCR_PDE_MASK                       (0x1U)
#define WDOG_WMCR_PDE_SHIFT                      (0U)
/*! PDE
 *  0b0..Power Down Counter of WDOG is disabled.
 *  0b1..Power Down Counter of WDOG is enabled (Default).
 */
#define WDOG_WMCR_PDE(x)                         (((uint16_t)(((uint16_t)(x)) << WDOG_WMCR_PDE_SHIFT)) & WDOG_WMCR_PDE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WDOG_Register_Masks */


/*!
 * @}
 */ /* end of group WDOG_Peripheral_Access_Layer */


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


#endif  /* WDOG_H_ */

