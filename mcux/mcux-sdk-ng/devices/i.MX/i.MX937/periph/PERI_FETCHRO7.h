/*
** ###################################################################
**     Processors:          MIMX9371xxVTx_ca55
**                          MIMX9371xxVTx_cm33
**                          MIMX9371xxVTx_cm7
**                          MIMX9373xxVTx_ca55
**                          MIMX9373xxVTx_cm33
**                          MIMX9373xxVTx_cm7
**                          MIMX9373xxVZx_ca55
**                          MIMX9373xxVZx_cm33
**                          MIMX9373xxVZx_cm7
**                          MIMX9375xxVTx_ca55
**                          MIMX9375xxVTx_cm33
**                          MIMX9375xxVTx_cm7
**                          MIMX9375xxVZx_ca55
**                          MIMX9375xxVZx_cm33
**                          MIMX9375xxVZx_cm7
**
**     Version:             rev. 1.0, 2026-04-09
**     Build:               b260624
**
**     Abstract:
**         CMSIS Peripheral Access Layer for fetchro7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026-04-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_fetchro7.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for fetchro7
 *
 * CMSIS Peripheral Access Layer for fetchro7
 */

#if !defined(PERI_FETCHRO7_H_)
#define PERI_FETCHRO7_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9371xxVTx_ca55))
#include "MIMX9371_ca55_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm33))
#include "MIMX9371_cm33_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm7))
#include "MIMX9371_cm7_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_ca55) || defined(CPU_MIMX9373xxVZx_ca55))
#include "MIMX9373_ca55_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm33) || defined(CPU_MIMX9373xxVZx_cm33))
#include "MIMX9373_cm33_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm7) || defined(CPU_MIMX9373xxVZx_cm7))
#include "MIMX9373_cm7_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_ca55) || defined(CPU_MIMX9375xxVZx_ca55))
#include "MIMX9375_ca55_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm33) || defined(CPU_MIMX9375xxVZx_cm33))
#include "MIMX9375_cm33_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm7) || defined(CPU_MIMX9375xxVZx_cm7))
#include "MIMX9375_cm7_COMMON.h"
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
   -- fetchro7 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchro7_Peripheral_Access_Layer fetchro7 Peripheral Access Layer
 * @{
 */

/** fetchro7 - Size of Registers Arrays */
#define fetchro7_WARIYFT0_COUNT                   65u

/** fetchro7 - Register Layout Typedef */
typedef struct {
  __IO uint32_t WARIYFT0[fetchro7_WARIYFT0_COUNT]; /**< WarpInterpolater_Y_FilterTable0, array offset: 0x0, array step: 0x4 */
} fetchro7_Type;

/* ----------------------------------------------------------------------------
   -- fetchro7 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchro7_Register_Masks fetchro7 Register Masks
 * @{
 */

/*! @name WARIYFT0 - WarpInterpolater_Y_FilterTable0 */
/*! @{ */

#define fetchro7_WARIYFT0_WIPYblm1_MASK          (0x1FFFU)
#define fetchro7_WARIYFT0_WIPYblm1_SHIFT         (0U)
/*! WIPYblm1 - WINTP_Y_Tblm1 */
#define fetchro7_WARIYFT0_WIPYblm1(x)            (((uint32_t)(((uint32_t)(x)) << fetchro7_WARIYFT0_WIPYblm1_SHIFT)) & fetchro7_WARIYFT0_WIPYblm1_MASK)

#define fetchro7_WARIYFT0_WIPYbl00_MASK          (0x7FFFC000U)
#define fetchro7_WARIYFT0_WIPYbl00_SHIFT         (14U)
/*! WIPYbl00 - WINTP_Y_Tbl00 */
#define fetchro7_WARIYFT0_WIPYbl00(x)            (((uint32_t)(((uint32_t)(x)) << fetchro7_WARIYFT0_WIPYbl00_SHIFT)) & fetchro7_WARIYFT0_WIPYbl00_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchro7_Register_Masks */


/*!
 * @}
 */ /* end of group fetchro7_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHRO7_H_ */

