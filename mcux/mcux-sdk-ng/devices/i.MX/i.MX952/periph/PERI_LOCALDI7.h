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
**         CMSIS Peripheral Access Layer for localdi7
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
 * @file PERI_localdi7.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for localdi7
 *
 * CMSIS Peripheral Access Layer for localdi7
 */

#if !defined(PERI_LOCALDI7_H_)
#define PERI_LOCALDI7_H_                         /**< Symbol preventing repeated inclusion */

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
   -- localdi7 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi7_Peripheral_Access_Layer localdi7 Peripheral Access Layer
 * @{
 */

/** localdi7 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDFRG018;                          /**< ldhifreg018, offset: 0x0 */
  __IO uint32_t LDFRG019;                          /**< ldhifreg019, offset: 0x4 */
  __IO uint32_t LDFRG01A;                          /**< ldhifreg01a, offset: 0x8 */
  __IO uint32_t LDFRG01B;                          /**< ldhifreg01b, offset: 0xC */
  __IO uint32_t LDFRG01C;                          /**< ldhifreg01c, offset: 0x10 */
  __IO uint32_t LDFRG01D;                          /**< ldhifreg01d, offset: 0x14 */
} localdi7_Type;

/* ----------------------------------------------------------------------------
   -- localdi7 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi7_Register_Masks localdi7 Register Masks
 * @{
 */

/*! @name LDFRG018 - ldhifreg018 */
/*! @{ */

#define localdi7_LDFRG018_pipe2on_MASK           (0x10U)
#define localdi7_LDFRG018_pipe2on_SHIFT          (4U)
/*! pipe2on - pipe2on */
#define localdi7_LDFRG018_pipe2on(x)             (((uint32_t)(((uint32_t)(x)) << localdi7_LDFRG018_pipe2on_SHIFT)) & localdi7_LDFRG018_pipe2on_MASK)
/*! @} */

/*! @name LDFRG019 - ldhifreg019 */
/*! @{ */

#define localdi7_LDFRG019_hwidth_MASK            (0x3FFFU)
#define localdi7_LDFRG019_hwidth_SHIFT           (0U)
/*! hwidth - hwidth */
#define localdi7_LDFRG019_hwidth(x)              (((uint32_t)(((uint32_t)(x)) << localdi7_LDFRG019_hwidth_SHIFT)) & localdi7_LDFRG019_hwidth_MASK)

#define localdi7_LDFRG019_vwidth_MASK            (0x3FFF0000U)
#define localdi7_LDFRG019_vwidth_SHIFT           (16U)
/*! vwidth - vwidth */
#define localdi7_LDFRG019_vwidth(x)              (((uint32_t)(((uint32_t)(x)) << localdi7_LDFRG019_vwidth_SHIFT)) & localdi7_LDFRG019_vwidth_MASK)
/*! @} */

/*! @name LDFRG01A - ldhifreg01a */
/*! @{ */

#define localdi7_LDFRG01A_vled_MASK              (0x3FU)
#define localdi7_LDFRG01A_vled_SHIFT             (0U)
/*! vled - vled */
#define localdi7_LDFRG01A_vled(x)                (((uint32_t)(((uint32_t)(x)) << localdi7_LDFRG01A_vled_SHIFT)) & localdi7_LDFRG01A_vled_MASK)

#define localdi7_LDFRG01A_hled_MASK              (0x7F0000U)
#define localdi7_LDFRG01A_hled_SHIFT             (16U)
/*! hled - hled */
#define localdi7_LDFRG01A_hled(x)                (((uint32_t)(((uint32_t)(x)) << localdi7_LDFRG01A_hled_SHIFT)) & localdi7_LDFRG01A_hled_MASK)
/*! @} */

/*! @name LDFRG01B - ldhifreg01b */
/*! @{ */

#define localdi7_LDFRG01B_vpsf_MASK              (0x1FFU)
#define localdi7_LDFRG01B_vpsf_SHIFT             (0U)
/*! vpsf - vpsf */
#define localdi7_LDFRG01B_vpsf(x)                (((uint32_t)(((uint32_t)(x)) << localdi7_LDFRG01B_vpsf_SHIFT)) & localdi7_LDFRG01B_vpsf_MASK)

#define localdi7_LDFRG01B_hpsf_MASK              (0x3FF0000U)
#define localdi7_LDFRG01B_hpsf_SHIFT             (16U)
/*! hpsf - hpsf */
#define localdi7_LDFRG01B_hpsf(x)                (((uint32_t)(((uint32_t)(x)) << localdi7_LDFRG01B_hpsf_SHIFT)) & localdi7_LDFRG01B_hpsf_MASK)
/*! @} */

/*! @name LDFRG01C - ldhifreg01c */
/*! @{ */

#define localdi7_LDFRG01C_hrate_MASK             (0x7U)
#define localdi7_LDFRG01C_hrate_SHIFT            (0U)
/*! hrate - hrate */
#define localdi7_LDFRG01C_hrate(x)               (((uint32_t)(((uint32_t)(x)) << localdi7_LDFRG01C_hrate_SHIFT)) & localdi7_LDFRG01C_hrate_MASK)

#define localdi7_LDFRG01C_vrate_MASK             (0x70U)
#define localdi7_LDFRG01C_vrate_SHIFT            (4U)
/*! vrate - vrate */
#define localdi7_LDFRG01C_vrate(x)               (((uint32_t)(((uint32_t)(x)) << localdi7_LDFRG01C_vrate_SHIFT)) & localdi7_LDFRG01C_vrate_MASK)
/*! @} */

/*! @name LDFRG01D - ldhifreg01d */
/*! @{ */

#define localdi7_LDFRG01D_hlpfsel_MASK           (0x3U)
#define localdi7_LDFRG01D_hlpfsel_SHIFT          (0U)
/*! hlpfsel - hlpfsel */
#define localdi7_LDFRG01D_hlpfsel(x)             (((uint32_t)(((uint32_t)(x)) << localdi7_LDFRG01D_hlpfsel_SHIFT)) & localdi7_LDFRG01D_hlpfsel_MASK)

#define localdi7_LDFRG01D_lpftermo_MASK          (0x40U)
#define localdi7_LDFRG01D_lpftermo_SHIFT         (6U)
/*! lpftermo - lpftermoff */
#define localdi7_LDFRG01D_lpftermo(x)            (((uint32_t)(((uint32_t)(x)) << localdi7_LDFRG01D_lpftermo_SHIFT)) & localdi7_LDFRG01D_lpftermo_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group localdi7_Register_Masks */


/*!
 * @}
 */ /* end of group localdi7_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALDI7_H_ */

