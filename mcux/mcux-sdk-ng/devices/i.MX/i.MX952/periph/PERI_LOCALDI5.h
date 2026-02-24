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
**         CMSIS Peripheral Access Layer for localdi5
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
 * @file PERI_localdi5.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for localdi5
 *
 * CMSIS Peripheral Access Layer for localdi5
 */

#if !defined(PERI_LOCALDI5_H_)
#define PERI_LOCALDI5_H_                         /**< Symbol preventing repeated inclusion */

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
   -- localdi5 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi5_Peripheral_Access_Layer localdi5 Peripheral Access Layer
 * @{
 */

/** localdi5 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDFRG010;                          /**< ldhifreg010, offset: 0x0 */
  __IO uint32_t LDFRG011;                          /**< ldhifreg011, offset: 0x4 */
  __IO uint32_t LDFRG012;                          /**< ldhifreg012, offset: 0x8 */
} localdi5_Type;

/* ----------------------------------------------------------------------------
   -- localdi5 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi5_Register_Masks localdi5 Register Masks
 * @{
 */

/*! @name LDFRG010 - ldhifreg010 */
/*! @{ */

#define localdi5_LDFRG010_ledsw_MASK             (0x1U)
#define localdi5_LDFRG010_ledsw_SHIFT            (0U)
/*! ledsw - ledsw */
#define localdi5_LDFRG010_ledsw(x)               (((uint32_t)(((uint32_t)(x)) << localdi5_LDFRG010_ledsw_SHIFT)) & localdi5_LDFRG010_ledsw_MASK)
/*! @} */

/*! @name LDFRG011 - ldhifreg011 */
/*! @{ */

#define localdi5_LDFRG011_rgbdbg_MASK            (0xF0U)
#define localdi5_LDFRG011_rgbdbg_SHIFT           (4U)
/*! rgbdbg - rgbdbg */
#define localdi5_LDFRG011_rgbdbg(x)              (((uint32_t)(((uint32_t)(x)) << localdi5_LDFRG011_rgbdbg_SHIFT)) & localdi5_LDFRG011_rgbdbg_MASK)

#define localdi5_LDFRG011_rlv_MASK               (0xFFF0000U)
#define localdi5_LDFRG011_rlv_SHIFT              (16U)
/*! rlv - rlv */
#define localdi5_LDFRG011_rlv(x)                 (((uint32_t)(((uint32_t)(x)) << localdi5_LDFRG011_rlv_SHIFT)) & localdi5_LDFRG011_rlv_MASK)
/*! @} */

/*! @name LDFRG012 - ldhifreg012 */
/*! @{ */

#define localdi5_LDFRG012_blv_MASK               (0xFFFU)
#define localdi5_LDFRG012_blv_SHIFT              (0U)
/*! blv - blv */
#define localdi5_LDFRG012_blv(x)                 (((uint32_t)(((uint32_t)(x)) << localdi5_LDFRG012_blv_SHIFT)) & localdi5_LDFRG012_blv_MASK)

#define localdi5_LDFRG012_glv_MASK               (0xFFF0000U)
#define localdi5_LDFRG012_glv_SHIFT              (16U)
/*! glv - glv */
#define localdi5_LDFRG012_glv(x)                 (((uint32_t)(((uint32_t)(x)) << localdi5_LDFRG012_glv_SHIFT)) & localdi5_LDFRG012_glv_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group localdi5_Register_Masks */


/*!
 * @}
 */ /* end of group localdi5_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALDI5_H_ */

