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
**         CMSIS Peripheral Access Layer for fetchro8
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
 * @file PERI_fetchro8.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for fetchro8
 *
 * CMSIS Peripheral Access Layer for fetchro8
 */

#if !defined(PERI_FETCHRO8_H_)
#define PERI_FETCHRO8_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchro8 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchro8_Peripheral_Access_Layer fetchro8 Peripheral Access Layer
 * @{
 */

/** fetchro8 - Register Layout Typedef */
typedef struct {
  __IO uint32_t WRPTTBLC;                          /**< WRPT_TBL_Control, offset: 0x0 */
} fetchro8_Type;

/* ----------------------------------------------------------------------------
   -- fetchro8 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchro8_Register_Masks fetchro8 Register Masks
 * @{
 */

/*! @name WRPTTBLC - WRPT_TBL_Control */
/*! @{ */

#define fetchro8_WRPTTBLC_WRPcfgS_MASK           (0x1U)
#define fetchro8_WRPTTBLC_WRPcfgS_SHIFT          (0U)
/*! WRPcfgS - WRPT_cfg_Select
 *  0b0..Use WarpReferencePointsTable 0.
 *  0b1..Use WarpReferencePointsTable 1.
 */
#define fetchro8_WRPTTBLC_WRPcfgS(x)             (((uint32_t)(((uint32_t)(x)) << fetchro8_WRPTTBLC_WRPcfgS_SHIFT)) & fetchro8_WRPTTBLC_WRPcfgS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchro8_Register_Masks */


/*!
 * @}
 */ /* end of group fetchro8_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHRO8_H_ */

