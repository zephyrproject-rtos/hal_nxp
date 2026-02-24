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
**         CMSIS Peripheral Access Layer for locald35
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
 * @file PERI_locald35.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald35
 *
 * CMSIS Peripheral Access Layer for locald35
 */

#if !defined(PERI_LOCALD35_H_)
#define PERI_LOCALD35_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald35 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald35_Peripheral_Access_Layer locald35 Peripheral Access Layer
 * @{
 */

/** locald35 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR100;                          /**< ldprofilereg100, offset: 0x0 */
  __IO uint32_t LDPRR101;                          /**< ldprofilereg101, offset: 0x4 */
  __IO uint32_t LDPRR102;                          /**< ldprofilereg102, offset: 0x8 */
  __IO uint32_t LDPRR103;                          /**< ldprofilereg103, offset: 0xC */
  __IO uint32_t LDPRR104;                          /**< ldprofilereg104, offset: 0x10 */
  __IO uint32_t LDPRR105;                          /**< ldprofilereg105, offset: 0x14 */
  __IO uint32_t LDPRR106;                          /**< ldprofilereg106, offset: 0x18 */
  __IO uint32_t LDPRR107;                          /**< ldprofilereg107, offset: 0x1C */
  __IO uint32_t LDPRR108;                          /**< ldprofilereg108, offset: 0x20 */
  __IO uint32_t LDPRR109;                          /**< ldprofilereg109, offset: 0x24 */
  __IO uint32_t LDPRR10A;                          /**< ldprofilereg10a, offset: 0x28 */
  __IO uint32_t LDPRR10B;                          /**< ldprofilereg10b, offset: 0x2C */
  __IO uint32_t LDPRR10C;                          /**< ldprofilereg10c, offset: 0x30 */
  __IO uint32_t LDPRR10D;                          /**< ldprofilereg10d, offset: 0x34 */
  __IO uint32_t LDPRR10E;                          /**< ldprofilereg10e, offset: 0x38 */
  __IO uint32_t LDPRR10F;                          /**< ldprofilereg10f, offset: 0x3C */
  __IO uint32_t LDPRR110;                          /**< ldprofilereg110, offset: 0x40 */
  __IO uint32_t LDPRR111;                          /**< ldprofilereg111, offset: 0x44 */
  __IO uint32_t LDPRR112;                          /**< ldprofilereg112, offset: 0x48 */
  __IO uint32_t LDPRR113;                          /**< ldprofilereg113, offset: 0x4C */
  __IO uint32_t LDPRR114;                          /**< ldprofilereg114, offset: 0x50 */
  __IO uint32_t LDPRR115;                          /**< ldprofilereg115, offset: 0x54 */
  __IO uint32_t LDPRR116;                          /**< ldprofilereg116, offset: 0x58 */
  __IO uint32_t LDPRR117;                          /**< ldprofilereg117, offset: 0x5C */
} locald35_Type;

/* ----------------------------------------------------------------------------
   -- locald35 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald35_Register_Masks locald35 Register Masks
 * @{
 */

/*! @name LDPRR100 - ldprofilereg100 */
/*! @{ */

#define locald35_LDPRR100_lumd385_MASK           (0x3FFU)
#define locald35_LDPRR100_lumd385_SHIFT          (0U)
/*! lumd385 - lumdat_385 */
#define locald35_LDPRR100_lumd385(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR100_lumd385_SHIFT)) & locald35_LDPRR100_lumd385_MASK)

#define locald35_LDPRR100_lumd384_MASK           (0x3FF0000U)
#define locald35_LDPRR100_lumd384_SHIFT          (16U)
/*! lumd384 - lumdat_384 */
#define locald35_LDPRR100_lumd384(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR100_lumd384_SHIFT)) & locald35_LDPRR100_lumd384_MASK)
/*! @} */

/*! @name LDPRR101 - ldprofilereg101 */
/*! @{ */

#define locald35_LDPRR101_lumd387_MASK           (0x3FFU)
#define locald35_LDPRR101_lumd387_SHIFT          (0U)
/*! lumd387 - lumdat_387 */
#define locald35_LDPRR101_lumd387(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR101_lumd387_SHIFT)) & locald35_LDPRR101_lumd387_MASK)

#define locald35_LDPRR101_lumd386_MASK           (0x3FF0000U)
#define locald35_LDPRR101_lumd386_SHIFT          (16U)
/*! lumd386 - lumdat_386 */
#define locald35_LDPRR101_lumd386(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR101_lumd386_SHIFT)) & locald35_LDPRR101_lumd386_MASK)
/*! @} */

/*! @name LDPRR102 - ldprofilereg102 */
/*! @{ */

#define locald35_LDPRR102_lumd389_MASK           (0x3FFU)
#define locald35_LDPRR102_lumd389_SHIFT          (0U)
/*! lumd389 - lumdat_389 */
#define locald35_LDPRR102_lumd389(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR102_lumd389_SHIFT)) & locald35_LDPRR102_lumd389_MASK)

#define locald35_LDPRR102_lumd388_MASK           (0x3FF0000U)
#define locald35_LDPRR102_lumd388_SHIFT          (16U)
/*! lumd388 - lumdat_388 */
#define locald35_LDPRR102_lumd388(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR102_lumd388_SHIFT)) & locald35_LDPRR102_lumd388_MASK)
/*! @} */

/*! @name LDPRR103 - ldprofilereg103 */
/*! @{ */

#define locald35_LDPRR103_lumd391_MASK           (0x3FFU)
#define locald35_LDPRR103_lumd391_SHIFT          (0U)
/*! lumd391 - lumdat_391 */
#define locald35_LDPRR103_lumd391(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR103_lumd391_SHIFT)) & locald35_LDPRR103_lumd391_MASK)

#define locald35_LDPRR103_lumd390_MASK           (0x3FF0000U)
#define locald35_LDPRR103_lumd390_SHIFT          (16U)
/*! lumd390 - lumdat_390 */
#define locald35_LDPRR103_lumd390(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR103_lumd390_SHIFT)) & locald35_LDPRR103_lumd390_MASK)
/*! @} */

/*! @name LDPRR104 - ldprofilereg104 */
/*! @{ */

#define locald35_LDPRR104_lumd393_MASK           (0x3FFU)
#define locald35_LDPRR104_lumd393_SHIFT          (0U)
/*! lumd393 - lumdat_393 */
#define locald35_LDPRR104_lumd393(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR104_lumd393_SHIFT)) & locald35_LDPRR104_lumd393_MASK)

#define locald35_LDPRR104_lumd392_MASK           (0x3FF0000U)
#define locald35_LDPRR104_lumd392_SHIFT          (16U)
/*! lumd392 - lumdat_392 */
#define locald35_LDPRR104_lumd392(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR104_lumd392_SHIFT)) & locald35_LDPRR104_lumd392_MASK)
/*! @} */

/*! @name LDPRR105 - ldprofilereg105 */
/*! @{ */

#define locald35_LDPRR105_lumd395_MASK           (0x3FFU)
#define locald35_LDPRR105_lumd395_SHIFT          (0U)
/*! lumd395 - lumdat_395 */
#define locald35_LDPRR105_lumd395(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR105_lumd395_SHIFT)) & locald35_LDPRR105_lumd395_MASK)

#define locald35_LDPRR105_lumd394_MASK           (0x3FF0000U)
#define locald35_LDPRR105_lumd394_SHIFT          (16U)
/*! lumd394 - lumdat_394 */
#define locald35_LDPRR105_lumd394(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR105_lumd394_SHIFT)) & locald35_LDPRR105_lumd394_MASK)
/*! @} */

/*! @name LDPRR106 - ldprofilereg106 */
/*! @{ */

#define locald35_LDPRR106_lumd397_MASK           (0x3FFU)
#define locald35_LDPRR106_lumd397_SHIFT          (0U)
/*! lumd397 - lumdat_397 */
#define locald35_LDPRR106_lumd397(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR106_lumd397_SHIFT)) & locald35_LDPRR106_lumd397_MASK)

#define locald35_LDPRR106_lumd396_MASK           (0x3FF0000U)
#define locald35_LDPRR106_lumd396_SHIFT          (16U)
/*! lumd396 - lumdat_396 */
#define locald35_LDPRR106_lumd396(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR106_lumd396_SHIFT)) & locald35_LDPRR106_lumd396_MASK)
/*! @} */

/*! @name LDPRR107 - ldprofilereg107 */
/*! @{ */

#define locald35_LDPRR107_lumd399_MASK           (0x3FFU)
#define locald35_LDPRR107_lumd399_SHIFT          (0U)
/*! lumd399 - lumdat_399 */
#define locald35_LDPRR107_lumd399(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR107_lumd399_SHIFT)) & locald35_LDPRR107_lumd399_MASK)

#define locald35_LDPRR107_lumd398_MASK           (0x3FF0000U)
#define locald35_LDPRR107_lumd398_SHIFT          (16U)
/*! lumd398 - lumdat_398 */
#define locald35_LDPRR107_lumd398(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR107_lumd398_SHIFT)) & locald35_LDPRR107_lumd398_MASK)
/*! @} */

/*! @name LDPRR108 - ldprofilereg108 */
/*! @{ */

#define locald35_LDPRR108_lumd401_MASK           (0x3FFU)
#define locald35_LDPRR108_lumd401_SHIFT          (0U)
/*! lumd401 - lumdat_401 */
#define locald35_LDPRR108_lumd401(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR108_lumd401_SHIFT)) & locald35_LDPRR108_lumd401_MASK)

#define locald35_LDPRR108_lumd400_MASK           (0x3FF0000U)
#define locald35_LDPRR108_lumd400_SHIFT          (16U)
/*! lumd400 - lumdat_400 */
#define locald35_LDPRR108_lumd400(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR108_lumd400_SHIFT)) & locald35_LDPRR108_lumd400_MASK)
/*! @} */

/*! @name LDPRR109 - ldprofilereg109 */
/*! @{ */

#define locald35_LDPRR109_lumd403_MASK           (0x3FFU)
#define locald35_LDPRR109_lumd403_SHIFT          (0U)
/*! lumd403 - lumdat_403 */
#define locald35_LDPRR109_lumd403(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR109_lumd403_SHIFT)) & locald35_LDPRR109_lumd403_MASK)

#define locald35_LDPRR109_lumd402_MASK           (0x3FF0000U)
#define locald35_LDPRR109_lumd402_SHIFT          (16U)
/*! lumd402 - lumdat_402 */
#define locald35_LDPRR109_lumd402(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR109_lumd402_SHIFT)) & locald35_LDPRR109_lumd402_MASK)
/*! @} */

/*! @name LDPRR10A - ldprofilereg10a */
/*! @{ */

#define locald35_LDPRR10A_lumd405_MASK           (0x3FFU)
#define locald35_LDPRR10A_lumd405_SHIFT          (0U)
/*! lumd405 - lumdat_405 */
#define locald35_LDPRR10A_lumd405(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10A_lumd405_SHIFT)) & locald35_LDPRR10A_lumd405_MASK)

#define locald35_LDPRR10A_lumd404_MASK           (0x3FF0000U)
#define locald35_LDPRR10A_lumd404_SHIFT          (16U)
/*! lumd404 - lumdat_404 */
#define locald35_LDPRR10A_lumd404(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10A_lumd404_SHIFT)) & locald35_LDPRR10A_lumd404_MASK)
/*! @} */

/*! @name LDPRR10B - ldprofilereg10b */
/*! @{ */

#define locald35_LDPRR10B_lumd407_MASK           (0x3FFU)
#define locald35_LDPRR10B_lumd407_SHIFT          (0U)
/*! lumd407 - lumdat_407 */
#define locald35_LDPRR10B_lumd407(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10B_lumd407_SHIFT)) & locald35_LDPRR10B_lumd407_MASK)

#define locald35_LDPRR10B_lumd406_MASK           (0x3FF0000U)
#define locald35_LDPRR10B_lumd406_SHIFT          (16U)
/*! lumd406 - lumdat_406 */
#define locald35_LDPRR10B_lumd406(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10B_lumd406_SHIFT)) & locald35_LDPRR10B_lumd406_MASK)
/*! @} */

/*! @name LDPRR10C - ldprofilereg10c */
/*! @{ */

#define locald35_LDPRR10C_lumd409_MASK           (0x3FFU)
#define locald35_LDPRR10C_lumd409_SHIFT          (0U)
/*! lumd409 - lumdat_409 */
#define locald35_LDPRR10C_lumd409(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10C_lumd409_SHIFT)) & locald35_LDPRR10C_lumd409_MASK)

#define locald35_LDPRR10C_lumd408_MASK           (0x3FF0000U)
#define locald35_LDPRR10C_lumd408_SHIFT          (16U)
/*! lumd408 - lumdat_408 */
#define locald35_LDPRR10C_lumd408(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10C_lumd408_SHIFT)) & locald35_LDPRR10C_lumd408_MASK)
/*! @} */

/*! @name LDPRR10D - ldprofilereg10d */
/*! @{ */

#define locald35_LDPRR10D_lumd411_MASK           (0x3FFU)
#define locald35_LDPRR10D_lumd411_SHIFT          (0U)
/*! lumd411 - lumdat_411 */
#define locald35_LDPRR10D_lumd411(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10D_lumd411_SHIFT)) & locald35_LDPRR10D_lumd411_MASK)

#define locald35_LDPRR10D_lumd410_MASK           (0x3FF0000U)
#define locald35_LDPRR10D_lumd410_SHIFT          (16U)
/*! lumd410 - lumdat_410 */
#define locald35_LDPRR10D_lumd410(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10D_lumd410_SHIFT)) & locald35_LDPRR10D_lumd410_MASK)
/*! @} */

/*! @name LDPRR10E - ldprofilereg10e */
/*! @{ */

#define locald35_LDPRR10E_lumd413_MASK           (0x3FFU)
#define locald35_LDPRR10E_lumd413_SHIFT          (0U)
/*! lumd413 - lumdat_413 */
#define locald35_LDPRR10E_lumd413(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10E_lumd413_SHIFT)) & locald35_LDPRR10E_lumd413_MASK)

#define locald35_LDPRR10E_lumd412_MASK           (0x3FF0000U)
#define locald35_LDPRR10E_lumd412_SHIFT          (16U)
/*! lumd412 - lumdat_412 */
#define locald35_LDPRR10E_lumd412(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10E_lumd412_SHIFT)) & locald35_LDPRR10E_lumd412_MASK)
/*! @} */

/*! @name LDPRR10F - ldprofilereg10f */
/*! @{ */

#define locald35_LDPRR10F_lumd415_MASK           (0x3FFU)
#define locald35_LDPRR10F_lumd415_SHIFT          (0U)
/*! lumd415 - lumdat_415 */
#define locald35_LDPRR10F_lumd415(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10F_lumd415_SHIFT)) & locald35_LDPRR10F_lumd415_MASK)

#define locald35_LDPRR10F_lumd414_MASK           (0x3FF0000U)
#define locald35_LDPRR10F_lumd414_SHIFT          (16U)
/*! lumd414 - lumdat_414 */
#define locald35_LDPRR10F_lumd414(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR10F_lumd414_SHIFT)) & locald35_LDPRR10F_lumd414_MASK)
/*! @} */

/*! @name LDPRR110 - ldprofilereg110 */
/*! @{ */

#define locald35_LDPRR110_lumd417_MASK           (0x3FFU)
#define locald35_LDPRR110_lumd417_SHIFT          (0U)
/*! lumd417 - lumdat_417 */
#define locald35_LDPRR110_lumd417(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR110_lumd417_SHIFT)) & locald35_LDPRR110_lumd417_MASK)

#define locald35_LDPRR110_lumd416_MASK           (0x3FF0000U)
#define locald35_LDPRR110_lumd416_SHIFT          (16U)
/*! lumd416 - lumdat_416 */
#define locald35_LDPRR110_lumd416(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR110_lumd416_SHIFT)) & locald35_LDPRR110_lumd416_MASK)
/*! @} */

/*! @name LDPRR111 - ldprofilereg111 */
/*! @{ */

#define locald35_LDPRR111_lumd419_MASK           (0x3FFU)
#define locald35_LDPRR111_lumd419_SHIFT          (0U)
/*! lumd419 - lumdat_419 */
#define locald35_LDPRR111_lumd419(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR111_lumd419_SHIFT)) & locald35_LDPRR111_lumd419_MASK)

#define locald35_LDPRR111_lumd418_MASK           (0x3FF0000U)
#define locald35_LDPRR111_lumd418_SHIFT          (16U)
/*! lumd418 - lumdat_418 */
#define locald35_LDPRR111_lumd418(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR111_lumd418_SHIFT)) & locald35_LDPRR111_lumd418_MASK)
/*! @} */

/*! @name LDPRR112 - ldprofilereg112 */
/*! @{ */

#define locald35_LDPRR112_lumd421_MASK           (0x3FFU)
#define locald35_LDPRR112_lumd421_SHIFT          (0U)
/*! lumd421 - lumdat_421 */
#define locald35_LDPRR112_lumd421(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR112_lumd421_SHIFT)) & locald35_LDPRR112_lumd421_MASK)

#define locald35_LDPRR112_lumd420_MASK           (0x3FF0000U)
#define locald35_LDPRR112_lumd420_SHIFT          (16U)
/*! lumd420 - lumdat_420 */
#define locald35_LDPRR112_lumd420(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR112_lumd420_SHIFT)) & locald35_LDPRR112_lumd420_MASK)
/*! @} */

/*! @name LDPRR113 - ldprofilereg113 */
/*! @{ */

#define locald35_LDPRR113_lumd423_MASK           (0x3FFU)
#define locald35_LDPRR113_lumd423_SHIFT          (0U)
/*! lumd423 - lumdat_423 */
#define locald35_LDPRR113_lumd423(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR113_lumd423_SHIFT)) & locald35_LDPRR113_lumd423_MASK)

#define locald35_LDPRR113_lumd422_MASK           (0x3FF0000U)
#define locald35_LDPRR113_lumd422_SHIFT          (16U)
/*! lumd422 - lumdat_422 */
#define locald35_LDPRR113_lumd422(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR113_lumd422_SHIFT)) & locald35_LDPRR113_lumd422_MASK)
/*! @} */

/*! @name LDPRR114 - ldprofilereg114 */
/*! @{ */

#define locald35_LDPRR114_lumd425_MASK           (0x3FFU)
#define locald35_LDPRR114_lumd425_SHIFT          (0U)
/*! lumd425 - lumdat_425 */
#define locald35_LDPRR114_lumd425(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR114_lumd425_SHIFT)) & locald35_LDPRR114_lumd425_MASK)

#define locald35_LDPRR114_lumd424_MASK           (0x3FF0000U)
#define locald35_LDPRR114_lumd424_SHIFT          (16U)
/*! lumd424 - lumdat_424 */
#define locald35_LDPRR114_lumd424(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR114_lumd424_SHIFT)) & locald35_LDPRR114_lumd424_MASK)
/*! @} */

/*! @name LDPRR115 - ldprofilereg115 */
/*! @{ */

#define locald35_LDPRR115_lumd427_MASK           (0x3FFU)
#define locald35_LDPRR115_lumd427_SHIFT          (0U)
/*! lumd427 - lumdat_427 */
#define locald35_LDPRR115_lumd427(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR115_lumd427_SHIFT)) & locald35_LDPRR115_lumd427_MASK)

#define locald35_LDPRR115_lumd426_MASK           (0x3FF0000U)
#define locald35_LDPRR115_lumd426_SHIFT          (16U)
/*! lumd426 - lumdat_426 */
#define locald35_LDPRR115_lumd426(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR115_lumd426_SHIFT)) & locald35_LDPRR115_lumd426_MASK)
/*! @} */

/*! @name LDPRR116 - ldprofilereg116 */
/*! @{ */

#define locald35_LDPRR116_lumd429_MASK           (0x3FFU)
#define locald35_LDPRR116_lumd429_SHIFT          (0U)
/*! lumd429 - lumdat_429 */
#define locald35_LDPRR116_lumd429(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR116_lumd429_SHIFT)) & locald35_LDPRR116_lumd429_MASK)

#define locald35_LDPRR116_lumd428_MASK           (0x3FF0000U)
#define locald35_LDPRR116_lumd428_SHIFT          (16U)
/*! lumd428 - lumdat_428 */
#define locald35_LDPRR116_lumd428(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR116_lumd428_SHIFT)) & locald35_LDPRR116_lumd428_MASK)
/*! @} */

/*! @name LDPRR117 - ldprofilereg117 */
/*! @{ */

#define locald35_LDPRR117_lumd431_MASK           (0x3FFU)
#define locald35_LDPRR117_lumd431_SHIFT          (0U)
/*! lumd431 - lumdat_431 */
#define locald35_LDPRR117_lumd431(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR117_lumd431_SHIFT)) & locald35_LDPRR117_lumd431_MASK)

#define locald35_LDPRR117_lumd430_MASK           (0x3FF0000U)
#define locald35_LDPRR117_lumd430_SHIFT          (16U)
/*! lumd430 - lumdat_430 */
#define locald35_LDPRR117_lumd430(x)             (((uint32_t)(((uint32_t)(x)) << locald35_LDPRR117_lumd430_SHIFT)) & locald35_LDPRR117_lumd430_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald35_Register_Masks */


/*!
 * @}
 */ /* end of group locald35_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD35_H_ */

