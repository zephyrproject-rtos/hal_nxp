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
**         CMSIS Peripheral Access Layer for VDET
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
 * @file PERI_VDET.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for VDET
 *
 * CMSIS Peripheral Access Layer for VDET
 */

#if !defined(PERI_VDET_H_)
#define PERI_VDET_H_                             /**< Symbol preventing repeated inclusion */

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
   -- VDET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VDET_Peripheral_Access_Layer VDET Peripheral Access Layer
 * @{
 */

/** VDET - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[528];
  __I  uint32_t TRIM;                              /**< Trim Control, offset: 0x210 */
} VDET_Type;

/* ----------------------------------------------------------------------------
   -- VDET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VDET_Register_Masks VDET Register Masks
 * @{
 */

/*! @name TRIM - Trim Control */
/*! @{ */

#define VDET_TRIM_CORE_HVD_TRIM_CTRL_LV_MASK     (0x1FU)
#define VDET_TRIM_CORE_HVD_TRIM_CTRL_LV_SHIFT    (0U)
/*! CORE_HVD_TRIM_CTRL_LV - Core HVD Threshold Value */
#define VDET_TRIM_CORE_HVD_TRIM_CTRL_LV(x)       (((uint32_t)(((uint32_t)(x)) << VDET_TRIM_CORE_HVD_TRIM_CTRL_LV_SHIFT)) & VDET_TRIM_CORE_HVD_TRIM_CTRL_LV_MASK)

#define VDET_TRIM_CORE_LVD_TRIM_CTRL_LV_MASK     (0x1F00U)
#define VDET_TRIM_CORE_LVD_TRIM_CTRL_LV_SHIFT    (8U)
/*! CORE_LVD_TRIM_CTRL_LV - Core LVD Threshold Value */
#define VDET_TRIM_CORE_LVD_TRIM_CTRL_LV(x)       (((uint32_t)(((uint32_t)(x)) << VDET_TRIM_CORE_LVD_TRIM_CTRL_LV_SHIFT)) & VDET_TRIM_CORE_LVD_TRIM_CTRL_LV_MASK)

#define VDET_TRIM_HV_LVD_TRIM_CTRL_LV_MASK       (0x1F0000U)
#define VDET_TRIM_HV_LVD_TRIM_CTRL_LV_SHIFT      (16U)
/*! HV_LVD_TRIM_CTRL_LV - Core HV LVD Threshold Value */
#define VDET_TRIM_HV_LVD_TRIM_CTRL_LV(x)         (((uint32_t)(((uint32_t)(x)) << VDET_TRIM_HV_LVD_TRIM_CTRL_LV_SHIFT)) & VDET_TRIM_HV_LVD_TRIM_CTRL_LV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VDET_Register_Masks */


/*!
 * @}
 */ /* end of group VDET_Peripheral_Access_Layer */


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


#endif  /* PERI_VDET_H_ */

