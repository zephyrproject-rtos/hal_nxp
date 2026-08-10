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
**         CMSIS Peripheral Access Layer for fetchro5
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
 * @file PERI_fetchro5.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for fetchro5
 *
 * CMSIS Peripheral Access Layer for fetchro5
 */

#if !defined(PERI_FETCHRO5_H_)
#define PERI_FETCHRO5_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchro5 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchro5_Peripheral_Access_Layer fetchro5 Peripheral Access Layer
 * @{
 */

/** fetchro5 - Size of Registers Arrays */
#define fetchro5_WARIXFT0_COUNT                   64u

/** fetchro5 - Register Layout Typedef */
typedef struct {
  __IO uint32_t WARIXFT0[fetchro5_WARIXFT0_COUNT]; /**< WarpInterpolater_X_FilterTable0, array offset: 0x0, array step: 0x4 */
} fetchro5_Type;

/* ----------------------------------------------------------------------------
   -- fetchro5 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchro5_Register_Masks fetchro5 Register Masks
 * @{
 */

/*! @name WARIXFT0 - WarpInterpolater_X_FilterTable0 */
/*! @{ */

#define fetchro5_WARIXFT0_WIPXblm1_MASK          (0x1FFFU)
#define fetchro5_WARIXFT0_WIPXblm1_SHIFT         (0U)
/*! WIPXblm1 - WINTP_X_Tblm1 */
#define fetchro5_WARIXFT0_WIPXblm1(x)            (((uint32_t)(((uint32_t)(x)) << fetchro5_WARIXFT0_WIPXblm1_SHIFT)) & fetchro5_WARIXFT0_WIPXblm1_MASK)

#define fetchro5_WARIXFT0_WIPXbl00_MASK          (0x7FFFC000U)
#define fetchro5_WARIXFT0_WIPXbl00_SHIFT         (14U)
/*! WIPXbl00 - WINTP_X_Tbl00 */
#define fetchro5_WARIXFT0_WIPXbl00(x)            (((uint32_t)(((uint32_t)(x)) << fetchro5_WARIXFT0_WIPXbl00_SHIFT)) & fetchro5_WARIXFT0_WIPXbl00_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchro5_Register_Masks */


/*!
 * @}
 */ /* end of group fetchro5_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHRO5_H_ */

