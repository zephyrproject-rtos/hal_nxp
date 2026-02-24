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
**         CMSIS Peripheral Access Layer for localdi4
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
 * @file PERI_localdi4.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for localdi4
 *
 * CMSIS Peripheral Access Layer for localdi4
 */

#if !defined(PERI_LOCALDI4_H_)
#define PERI_LOCALDI4_H_                         /**< Symbol preventing repeated inclusion */

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
   -- localdi4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi4_Peripheral_Access_Layer localdi4 Peripheral Access Layer
 * @{
 */

/** localdi4 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDFRG00B;                          /**< ldhifreg00b, offset: 0x0 */
  __IO uint32_t LDFRG00C;                          /**< ldhifreg00c, offset: 0x4 */
  __IO uint32_t LDFRG00D;                          /**< ldhifreg00d, offset: 0x8 */
  __IO uint32_t LDFRG00E;                          /**< ldhifreg00e, offset: 0xC */
} localdi4_Type;

/* ----------------------------------------------------------------------------
   -- localdi4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi4_Register_Masks localdi4 Register Masks
 * @{
 */

/*! @name LDFRG00B - ldhifreg00b */
/*! @{ */

#define localdi4_LDFRG00B_blinton_MASK           (0x1U)
#define localdi4_LDFRG00B_blinton_SHIFT          (0U)
/*! blinton - blinton */
#define localdi4_LDFRG00B_blinton(x)             (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00B_blinton_SHIFT)) & localdi4_LDFRG00B_blinton_MASK)

#define localdi4_LDFRG00B_ledinton_MASK          (0x2U)
#define localdi4_LDFRG00B_ledinton_SHIFT         (1U)
/*! ledinton - ledinton */
#define localdi4_LDFRG00B_ledinton(x)            (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00B_ledinton_SHIFT)) & localdi4_LDFRG00B_ledinton_MASK)

#define localdi4_LDFRG00B_vinton_MASK            (0x4U)
#define localdi4_LDFRG00B_vinton_SHIFT           (2U)
/*! vinton - vinton */
#define localdi4_LDFRG00B_vinton(x)              (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00B_vinton_SHIFT)) & localdi4_LDFRG00B_vinton_MASK)

#define localdi4_LDFRG00B_smblvon_MASK           (0x100U)
#define localdi4_LDFRG00B_smblvon_SHIFT          (8U)
/*! smblvon - smblvon */
#define localdi4_LDFRG00B_smblvon(x)             (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00B_smblvon_SHIFT)) & localdi4_LDFRG00B_smblvon_MASK)

#define localdi4_LDFRG00B_smvlvon_MASK           (0x200U)
#define localdi4_LDFRG00B_smvlvon_SHIFT          (9U)
/*! smvlvon - smvlvon */
#define localdi4_LDFRG00B_smvlvon(x)             (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00B_smvlvon_SHIFT)) & localdi4_LDFRG00B_smvlvon_MASK)

#define localdi4_LDFRG00B_smslvon_MASK           (0x400U)
#define localdi4_LDFRG00B_smslvon_SHIFT          (10U)
/*! smslvon - smslvon */
#define localdi4_LDFRG00B_smslvon(x)             (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00B_smslvon_SHIFT)) & localdi4_LDFRG00B_smslvon_MASK)
/*! @} */

/*! @name LDFRG00C - ldhifreg00c */
/*! @{ */

#define localdi4_LDFRG00C_detwioff_MASK          (0x1U)
#define localdi4_LDFRG00C_detwioff_SHIFT         (0U)
/*! detwioff - detwinautooff */
#define localdi4_LDFRG00C_detwioff(x)            (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00C_detwioff_SHIFT)) & localdi4_LDFRG00C_detwioff_MASK)

#define localdi4_LDFRG00C_sdetwaof_MASK          (0x10U)
#define localdi4_LDFRG00C_sdetwaof_SHIFT         (4U)
/*! sdetwaof - sdetwinautooff */
#define localdi4_LDFRG00C_sdetwaof(x)            (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00C_sdetwaof_SHIFT)) & localdi4_LDFRG00C_sdetwaof_MASK)

#define localdi4_LDFRG00C_pxwinon0_MASK          (0x10000U)
#define localdi4_LDFRG00C_pxwinon0_SHIFT         (16U)
/*! pxwinon0 - pixwinon */
#define localdi4_LDFRG00C_pxwinon0(x)            (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00C_pxwinon0_SHIFT)) & localdi4_LDFRG00C_pxwinon0_MASK)
/*! @} */

/*! @name LDFRG00D - ldhifreg00d */
/*! @{ */

#define localdi4_LDFRG00D_dethw_MASK             (0x3FFFU)
#define localdi4_LDFRG00D_dethw_SHIFT            (0U)
/*! dethw - dethw */
#define localdi4_LDFRG00D_dethw(x)               (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00D_dethw_SHIFT)) & localdi4_LDFRG00D_dethw_MASK)

#define localdi4_LDFRG00D_deths_MASK             (0x3FFF0000U)
#define localdi4_LDFRG00D_deths_SHIFT            (16U)
/*! deths - deths */
#define localdi4_LDFRG00D_deths(x)               (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00D_deths_SHIFT)) & localdi4_LDFRG00D_deths_MASK)
/*! @} */

/*! @name LDFRG00E - ldhifreg00e */
/*! @{ */

#define localdi4_LDFRG00E_detvw_MASK             (0x3FFFU)
#define localdi4_LDFRG00E_detvw_SHIFT            (0U)
/*! detvw - detvw */
#define localdi4_LDFRG00E_detvw(x)               (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00E_detvw_SHIFT)) & localdi4_LDFRG00E_detvw_MASK)

#define localdi4_LDFRG00E_detvs_MASK             (0x3FFF0000U)
#define localdi4_LDFRG00E_detvs_SHIFT            (16U)
/*! detvs - detvs */
#define localdi4_LDFRG00E_detvs(x)               (((uint32_t)(((uint32_t)(x)) << localdi4_LDFRG00E_detvs_SHIFT)) & localdi4_LDFRG00E_detvs_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group localdi4_Register_Masks */


/*!
 * @}
 */ /* end of group localdi4_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALDI4_H_ */

