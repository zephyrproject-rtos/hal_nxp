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
**         CMSIS Peripheral Access Layer for clut1
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
 * @file PERI_clut1.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for clut1
 *
 * CMSIS Peripheral Access Layer for clut1
 */

#if !defined(PERI_CLUT1_H_)
#define PERI_CLUT1_H_                            /**< Symbol preventing repeated inclusion */

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
   -- clut1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup clut1_Peripheral_Access_Layer clut1 Peripheral Access Layer
 * @{
 */

/** clut1 - Size of Registers Arrays */
#define clut1_LUT_COUNT                           256u

/** clut1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LUT[clut1_LUT_COUNT];              /**< LUT, array offset: 0x0, array step: 0x4 */
} clut1_Type;

/* ----------------------------------------------------------------------------
   -- clut1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup clut1_Register_Masks clut1 Register Masks
 * @{
 */

/*! @name LUT - LUT */
/*! @{ */

#define clut1_LUT_BLUE_MASK                      (0x3FFU)
#define clut1_LUT_BLUE_SHIFT                     (0U)
/*! BLUE - BLUE */
#define clut1_LUT_BLUE(x)                        (((uint32_t)(((uint32_t)(x)) << clut1_LUT_BLUE_SHIFT)) & clut1_LUT_BLUE_MASK)

#define clut1_LUT_GREEN_MASK                     (0xFFC00U)
#define clut1_LUT_GREEN_SHIFT                    (10U)
/*! GREEN - GREEN */
#define clut1_LUT_GREEN(x)                       (((uint32_t)(((uint32_t)(x)) << clut1_LUT_GREEN_SHIFT)) & clut1_LUT_GREEN_MASK)

#define clut1_LUT_RED_MASK                       (0x3FF00000U)
#define clut1_LUT_RED_SHIFT                      (20U)
/*! RED - RED */
#define clut1_LUT_RED(x)                         (((uint32_t)(((uint32_t)(x)) << clut1_LUT_RED_SHIFT)) & clut1_LUT_RED_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group clut1_Register_Masks */


/*!
 * @}
 */ /* end of group clut1_Peripheral_Access_Layer */


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


#endif  /* PERI_CLUT1_H_ */

