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
**         CMSIS Peripheral Access Layer for fetchr10
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
 * @file PERI_fetchr10.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchr10
 *
 * CMSIS Peripheral Access Layer for fetchr10
 */

#if !defined(PERI_FETCHR10_H_)
#define PERI_FETCHR10_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchr10 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchr10_Peripheral_Access_Layer fetchr10 Peripheral Access Layer
 * @{
 */

/** fetchr10 - Size of Registers Arrays */
#define fetchr10_WARREPT1_COUNT                   2048u

/** fetchr10 - Register Layout Typedef */
typedef struct {
  __IO uint32_t WARREPT1[fetchr10_WARREPT1_COUNT]; /**< WarpReferencePointsTable1, array offset: 0x0, array step: 0x4 */
} fetchr10_Type;

/* ----------------------------------------------------------------------------
   -- fetchr10 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchr10_Register_Masks fetchr10 Register Masks
 * @{
 */

/*! @name WARREPT1 - WarpReferencePointsTable1 */
/*! @{ */

#define fetchr10_WARREPT1_WRP1delY_MASK          (0xFFFFU)
#define fetchr10_WARREPT1_WRP1delY_SHIFT         (0U)
/*! WRP1delY - WRPT1_deltaY */
#define fetchr10_WARREPT1_WRP1delY(x)            (((uint32_t)(((uint32_t)(x)) << fetchr10_WARREPT1_WRP1delY_SHIFT)) & fetchr10_WARREPT1_WRP1delY_MASK)

#define fetchr10_WARREPT1_WRP1delX_MASK          (0xFFFF0000U)
#define fetchr10_WARREPT1_WRP1delX_SHIFT         (16U)
/*! WRP1delX - WRPT1_deltaX */
#define fetchr10_WARREPT1_WRP1delX(x)            (((uint32_t)(((uint32_t)(x)) << fetchr10_WARREPT1_WRP1delX_SHIFT)) & fetchr10_WARREPT1_WRP1delX_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchr10_Register_Masks */


/*!
 * @}
 */ /* end of group fetchr10_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHR10_H_ */

