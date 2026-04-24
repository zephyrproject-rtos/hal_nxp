/*
** ###################################################################
**     Processors:          MIMX9522xxVTx_ca55
**                          MIMX9522xxVTx_cm33
**                          MIMX9522xxVTx_cm7
**                          MIMX9522xxVZx_ca55
**                          MIMX9522xxVZx_cm33
**                          MIMX9522xxVZx_cm7
**                          MIMX9523xxVTx_ca55
**                          MIMX9523xxVTx_cm33
**                          MIMX9523xxVTx_cm7
**                          MIMX9523xxVZx_ca55
**                          MIMX9523xxVZx_cm33
**                          MIMX9523xxVZx_cm7
**                          MIMX9524xxVTx_ca55
**                          MIMX9524xxVTx_cm33
**                          MIMX9524xxVTx_cm7
**                          MIMX9524xxVZx_ca55
**                          MIMX9524xxVZx_cm33
**                          MIMX9524xxVZx_cm7
**                          MIMX9525xxVTx_ca55
**                          MIMX9525xxVTx_cm33
**                          MIMX9525xxVTx_cm7
**                          MIMX9525xxVZx_ca55
**                          MIMX9525xxVZx_cm33
**                          MIMX9525xxVZx_cm7
**                          MIMX9528xxVTx_ca55
**                          MIMX9528xxVTx_cm33
**                          MIMX9528xxVTx_cm7
**                          MIMX9528xxVZx_ca55
**                          MIMX9528xxVZx_cm33
**                          MIMX9528xxVZx_cm7
**                          MIMX9529xxVTx_ca55
**                          MIMX9529xxVTx_cm33
**                          MIMX9529xxVTx_cm7
**                          MIMX9529xxVZx_ca55
**                          MIMX9529xxVZx_cm33
**                          MIMX9529xxVZx_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260324
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OSC24M
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
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
 * @file PERI_OSC24M.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OSC24M
 *
 * CMSIS Peripheral Access Layer for OSC24M
 */

#if !defined(PERI_OSC24M_H_)
#define PERI_OSC24M_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9522xxVTx_ca55) || defined(CPU_MIMX9522xxVZx_ca55))
#include "MIMX9522_ca55_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm33) || defined(CPU_MIMX9522xxVZx_cm33))
#include "MIMX9522_cm33_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm7) || defined(CPU_MIMX9522xxVZx_cm7))
#include "MIMX9522_cm7_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_ca55) || defined(CPU_MIMX9523xxVZx_ca55))
#include "MIMX9523_ca55_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm33) || defined(CPU_MIMX9523xxVZx_cm33))
#include "MIMX9523_cm33_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm7) || defined(CPU_MIMX9523xxVZx_cm7))
#include "MIMX9523_cm7_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_ca55) || defined(CPU_MIMX9524xxVZx_ca55))
#include "MIMX9524_ca55_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm33) || defined(CPU_MIMX9524xxVZx_cm33))
#include "MIMX9524_cm33_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm7) || defined(CPU_MIMX9524xxVZx_cm7))
#include "MIMX9524_cm7_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_ca55) || defined(CPU_MIMX9525xxVZx_ca55))
#include "MIMX9525_ca55_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm33) || defined(CPU_MIMX9525xxVZx_cm33))
#include "MIMX9525_cm33_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm7) || defined(CPU_MIMX9525xxVZx_cm7))
#include "MIMX9525_cm7_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_ca55) || defined(CPU_MIMX9528xxVZx_ca55))
#include "MIMX9528_ca55_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm33) || defined(CPU_MIMX9528xxVZx_cm33))
#include "MIMX9528_cm33_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm7) || defined(CPU_MIMX9528xxVZx_cm7))
#include "MIMX9528_cm7_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_ca55) || defined(CPU_MIMX9529xxVZx_ca55))
#include "MIMX9529_ca55_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm33) || defined(CPU_MIMX9529xxVZx_cm33))
#include "MIMX9529_cm33_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm7) || defined(CPU_MIMX9529xxVZx_cm7))
#include "MIMX9529_cm7_COMMON.h"
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
   -- OSC24M Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC24M_Peripheral_Access_Layer OSC24M Peripheral Access Layer
 * @{
 */

/** OSC24M - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __IO uint32_t OSC_OK_DLY;                        /**< Crystal Oscillator OK Delay, offset: 0x8 */
       uint8_t RESERVED_1[2036];
  __I  uint32_t DIGPROG_DEVICE_ID;                 /**< Device ID, offset: 0x800 */
} OSC24M_Type;

/* ----------------------------------------------------------------------------
   -- OSC24M Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC24M_Register_Masks OSC24M Register Masks
 * @{
 */

/*! @name OSC_OK_DLY - Crystal Oscillator OK Delay */
/*! @{ */

#define OSC24M_OSC_OK_DLY_OSC_OK_DLY_MASK        (0xFFU)
#define OSC24M_OSC_OK_DLY_OSC_OK_DLY_SHIFT       (0U)
/*! OSC_OK_DLY - Oscillator Startup Delay Count */
#define OSC24M_OSC_OK_DLY_OSC_OK_DLY(x)          (((uint32_t)(((uint32_t)(x)) << OSC24M_OSC_OK_DLY_OSC_OK_DLY_SHIFT)) & OSC24M_OSC_OK_DLY_OSC_OK_DLY_MASK)
/*! @} */

/*! @name DIGPROG_DEVICE_ID - Device ID */
/*! @{ */

#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR_MASK (0xFFU)
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR_SHIFT (0U)
/*! DIGPROG_MINOR - DIGPROG Minor Device ID */
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR(x) (((uint32_t)(((uint32_t)(x)) << OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR_SHIFT)) & OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR_MASK)

#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_MASK (0xFF00U)
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_SHIFT (8U)
/*! DIGPROG_MAJOR_LOWER - DIGPROG Major-Lower Device ID */
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER(x) (((uint32_t)(((uint32_t)(x)) << OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_SHIFT)) & OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_MASK)

#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_MASK (0xFF0000U)
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_SHIFT (16U)
/*! DIGPROG_MAJOR_UPPER - DIGPROG Major-Upper Device ID */
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER(x) (((uint32_t)(((uint32_t)(x)) << OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_SHIFT)) & OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OSC24M_Register_Masks */


/*!
 * @}
 */ /* end of group OSC24M_Peripheral_Access_Layer */


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


#endif  /* PERI_OSC24M_H_ */

