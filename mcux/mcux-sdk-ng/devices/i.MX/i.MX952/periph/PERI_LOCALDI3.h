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
**         CMSIS Peripheral Access Layer for localdi3
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
 * @file PERI_localdi3.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for localdi3
 *
 * CMSIS Peripheral Access Layer for localdi3
 */

#if !defined(PERI_LOCALDI3_H_)
#define PERI_LOCALDI3_H_                         /**< Symbol preventing repeated inclusion */

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
   -- localdi3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi3_Peripheral_Access_Layer localdi3 Peripheral Access Layer
 * @{
 */

/** localdi3 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDFRG008;                          /**< ldhifreg008, offset: 0x0 */
  __IO uint32_t LDFRG009;                          /**< ldhifreg009, offset: 0x4 */
  __IO uint32_t LDFRG00A;                          /**< ldhifreg00a, offset: 0x8 */
} localdi3_Type;

/* ----------------------------------------------------------------------------
   -- localdi3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi3_Register_Masks localdi3 Register Masks
 * @{
 */

/*! @name LDFRG008 - ldhifreg008 */
/*! @{ */

#define localdi3_LDFRG008_vupoff_MASK            (0x1U)
#define localdi3_LDFRG008_vupoff_SHIFT           (0U)
/*! vupoff - vupoff */
#define localdi3_LDFRG008_vupoff(x)              (((uint32_t)(((uint32_t)(x)) << localdi3_LDFRG008_vupoff_SHIFT)) & localdi3_LDFRG008_vupoff_MASK)

#define localdi3_LDFRG008_vupsel_MASK            (0x2U)
#define localdi3_LDFRG008_vupsel_SHIFT           (1U)
/*! vupsel - vupsel */
#define localdi3_LDFRG008_vupsel(x)              (((uint32_t)(((uint32_t)(x)) << localdi3_LDFRG008_vupsel_SHIFT)) & localdi3_LDFRG008_vupsel_MASK)
/*! @} */

/*! @name LDFRG009 - ldhifreg009 */
/*! @{ */

#define localdi3_LDFRG009_ldupdly_MASK           (0x1FFFU)
#define localdi3_LDFRG009_ldupdly_SHIFT          (0U)
/*! ldupdly - ldupdly */
#define localdi3_LDFRG009_ldupdly(x)             (((uint32_t)(((uint32_t)(x)) << localdi3_LDFRG009_ldupdly_SHIFT)) & localdi3_LDFRG009_ldupdly_MASK)
/*! @} */

/*! @name LDFRG00A - ldhifreg00a */
/*! @{ */

#define localdi3_LDFRG00A_ldvintd_MASK           (0x1FFFU)
#define localdi3_LDFRG00A_ldvintd_SHIFT          (0U)
/*! ldvintd - ldvintdly */
#define localdi3_LDFRG00A_ldvintd(x)             (((uint32_t)(((uint32_t)(x)) << localdi3_LDFRG00A_ldvintd_SHIFT)) & localdi3_LDFRG00A_ldvintd_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group localdi3_Register_Masks */


/*!
 * @}
 */ /* end of group localdi3_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALDI3_H_ */

