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
**         CMSIS Peripheral Access Layer for locald36
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
 * @file PERI_locald36.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald36
 *
 * CMSIS Peripheral Access Layer for locald36
 */

#if !defined(PERI_LOCALD36_H_)
#define PERI_LOCALD36_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald36 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald36_Peripheral_Access_Layer locald36 Peripheral Access Layer
 * @{
 */

/** locald36 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR120;                          /**< ldprofilereg120, offset: 0x0 */
  __IO uint32_t LDPRR121;                          /**< ldprofilereg121, offset: 0x4 */
  __IO uint32_t LDPRR122;                          /**< ldprofilereg122, offset: 0x8 */
  __IO uint32_t LDPRR123;                          /**< ldprofilereg123, offset: 0xC */
  __IO uint32_t LDPRR124;                          /**< ldprofilereg124, offset: 0x10 */
  __IO uint32_t LDPRR125;                          /**< ldprofilereg125, offset: 0x14 */
  __IO uint32_t LDPRR126;                          /**< ldprofilereg126, offset: 0x18 */
  __IO uint32_t LDPRR127;                          /**< ldprofilereg127, offset: 0x1C */
  __IO uint32_t LDPRR128;                          /**< ldprofilereg128, offset: 0x20 */
  __IO uint32_t LDPRR129;                          /**< ldprofilereg129, offset: 0x24 */
  __IO uint32_t LDPRR12A;                          /**< ldprofilereg12a, offset: 0x28 */
  __IO uint32_t LDPRR12B;                          /**< ldprofilereg12b, offset: 0x2C */
  __IO uint32_t LDPRR12C;                          /**< ldprofilereg12c, offset: 0x30 */
  __IO uint32_t LDPRR12D;                          /**< ldprofilereg12d, offset: 0x34 */
  __IO uint32_t LDPRR12E;                          /**< ldprofilereg12e, offset: 0x38 */
  __IO uint32_t LDPRR12F;                          /**< ldprofilereg12f, offset: 0x3C */
  __IO uint32_t LDPRR130;                          /**< ldprofilereg130, offset: 0x40 */
  __IO uint32_t LDPRR131;                          /**< ldprofilereg131, offset: 0x44 */
  __IO uint32_t LDPRR132;                          /**< ldprofilereg132, offset: 0x48 */
  __IO uint32_t LDPRR133;                          /**< ldprofilereg133, offset: 0x4C */
  __IO uint32_t LDPRR134;                          /**< ldprofilereg134, offset: 0x50 */
  __IO uint32_t LDPRR135;                          /**< ldprofilereg135, offset: 0x54 */
  __IO uint32_t LDPRR136;                          /**< ldprofilereg136, offset: 0x58 */
  __IO uint32_t LDPRR137;                          /**< ldprofilereg137, offset: 0x5C */
} locald36_Type;

/* ----------------------------------------------------------------------------
   -- locald36 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald36_Register_Masks locald36 Register Masks
 * @{
 */

/*! @name LDPRR120 - ldprofilereg120 */
/*! @{ */

#define locald36_LDPRR120_lumd433_MASK           (0x3FFU)
#define locald36_LDPRR120_lumd433_SHIFT          (0U)
/*! lumd433 - lumdat_433 */
#define locald36_LDPRR120_lumd433(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR120_lumd433_SHIFT)) & locald36_LDPRR120_lumd433_MASK)

#define locald36_LDPRR120_lumd432_MASK           (0x3FF0000U)
#define locald36_LDPRR120_lumd432_SHIFT          (16U)
/*! lumd432 - lumdat_432 */
#define locald36_LDPRR120_lumd432(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR120_lumd432_SHIFT)) & locald36_LDPRR120_lumd432_MASK)
/*! @} */

/*! @name LDPRR121 - ldprofilereg121 */
/*! @{ */

#define locald36_LDPRR121_lumd435_MASK           (0x3FFU)
#define locald36_LDPRR121_lumd435_SHIFT          (0U)
/*! lumd435 - lumdat_435 */
#define locald36_LDPRR121_lumd435(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR121_lumd435_SHIFT)) & locald36_LDPRR121_lumd435_MASK)

#define locald36_LDPRR121_lumd434_MASK           (0x3FF0000U)
#define locald36_LDPRR121_lumd434_SHIFT          (16U)
/*! lumd434 - lumdat_434 */
#define locald36_LDPRR121_lumd434(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR121_lumd434_SHIFT)) & locald36_LDPRR121_lumd434_MASK)
/*! @} */

/*! @name LDPRR122 - ldprofilereg122 */
/*! @{ */

#define locald36_LDPRR122_lumd437_MASK           (0x3FFU)
#define locald36_LDPRR122_lumd437_SHIFT          (0U)
/*! lumd437 - lumdat_437 */
#define locald36_LDPRR122_lumd437(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR122_lumd437_SHIFT)) & locald36_LDPRR122_lumd437_MASK)

#define locald36_LDPRR122_lumd436_MASK           (0x3FF0000U)
#define locald36_LDPRR122_lumd436_SHIFT          (16U)
/*! lumd436 - lumdat_436 */
#define locald36_LDPRR122_lumd436(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR122_lumd436_SHIFT)) & locald36_LDPRR122_lumd436_MASK)
/*! @} */

/*! @name LDPRR123 - ldprofilereg123 */
/*! @{ */

#define locald36_LDPRR123_lumd439_MASK           (0x3FFU)
#define locald36_LDPRR123_lumd439_SHIFT          (0U)
/*! lumd439 - lumdat_439 */
#define locald36_LDPRR123_lumd439(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR123_lumd439_SHIFT)) & locald36_LDPRR123_lumd439_MASK)

#define locald36_LDPRR123_lumd438_MASK           (0x3FF0000U)
#define locald36_LDPRR123_lumd438_SHIFT          (16U)
/*! lumd438 - lumdat_438 */
#define locald36_LDPRR123_lumd438(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR123_lumd438_SHIFT)) & locald36_LDPRR123_lumd438_MASK)
/*! @} */

/*! @name LDPRR124 - ldprofilereg124 */
/*! @{ */

#define locald36_LDPRR124_lumd441_MASK           (0x3FFU)
#define locald36_LDPRR124_lumd441_SHIFT          (0U)
/*! lumd441 - lumdat_441 */
#define locald36_LDPRR124_lumd441(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR124_lumd441_SHIFT)) & locald36_LDPRR124_lumd441_MASK)

#define locald36_LDPRR124_lumd440_MASK           (0x3FF0000U)
#define locald36_LDPRR124_lumd440_SHIFT          (16U)
/*! lumd440 - lumdat_440 */
#define locald36_LDPRR124_lumd440(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR124_lumd440_SHIFT)) & locald36_LDPRR124_lumd440_MASK)
/*! @} */

/*! @name LDPRR125 - ldprofilereg125 */
/*! @{ */

#define locald36_LDPRR125_lumd443_MASK           (0x3FFU)
#define locald36_LDPRR125_lumd443_SHIFT          (0U)
/*! lumd443 - lumdat_443 */
#define locald36_LDPRR125_lumd443(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR125_lumd443_SHIFT)) & locald36_LDPRR125_lumd443_MASK)

#define locald36_LDPRR125_lumd442_MASK           (0x3FF0000U)
#define locald36_LDPRR125_lumd442_SHIFT          (16U)
/*! lumd442 - lumdat_442 */
#define locald36_LDPRR125_lumd442(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR125_lumd442_SHIFT)) & locald36_LDPRR125_lumd442_MASK)
/*! @} */

/*! @name LDPRR126 - ldprofilereg126 */
/*! @{ */

#define locald36_LDPRR126_lumd445_MASK           (0x3FFU)
#define locald36_LDPRR126_lumd445_SHIFT          (0U)
/*! lumd445 - lumdat_445 */
#define locald36_LDPRR126_lumd445(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR126_lumd445_SHIFT)) & locald36_LDPRR126_lumd445_MASK)

#define locald36_LDPRR126_lumd444_MASK           (0x3FF0000U)
#define locald36_LDPRR126_lumd444_SHIFT          (16U)
/*! lumd444 - lumdat_444 */
#define locald36_LDPRR126_lumd444(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR126_lumd444_SHIFT)) & locald36_LDPRR126_lumd444_MASK)
/*! @} */

/*! @name LDPRR127 - ldprofilereg127 */
/*! @{ */

#define locald36_LDPRR127_lumd447_MASK           (0x3FFU)
#define locald36_LDPRR127_lumd447_SHIFT          (0U)
/*! lumd447 - lumdat_447 */
#define locald36_LDPRR127_lumd447(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR127_lumd447_SHIFT)) & locald36_LDPRR127_lumd447_MASK)

#define locald36_LDPRR127_lumd446_MASK           (0x3FF0000U)
#define locald36_LDPRR127_lumd446_SHIFT          (16U)
/*! lumd446 - lumdat_446 */
#define locald36_LDPRR127_lumd446(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR127_lumd446_SHIFT)) & locald36_LDPRR127_lumd446_MASK)
/*! @} */

/*! @name LDPRR128 - ldprofilereg128 */
/*! @{ */

#define locald36_LDPRR128_lumd449_MASK           (0x3FFU)
#define locald36_LDPRR128_lumd449_SHIFT          (0U)
/*! lumd449 - lumdat_449 */
#define locald36_LDPRR128_lumd449(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR128_lumd449_SHIFT)) & locald36_LDPRR128_lumd449_MASK)

#define locald36_LDPRR128_lumd448_MASK           (0x3FF0000U)
#define locald36_LDPRR128_lumd448_SHIFT          (16U)
/*! lumd448 - lumdat_448 */
#define locald36_LDPRR128_lumd448(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR128_lumd448_SHIFT)) & locald36_LDPRR128_lumd448_MASK)
/*! @} */

/*! @name LDPRR129 - ldprofilereg129 */
/*! @{ */

#define locald36_LDPRR129_lumd451_MASK           (0x3FFU)
#define locald36_LDPRR129_lumd451_SHIFT          (0U)
/*! lumd451 - lumdat_451 */
#define locald36_LDPRR129_lumd451(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR129_lumd451_SHIFT)) & locald36_LDPRR129_lumd451_MASK)

#define locald36_LDPRR129_lumd450_MASK           (0x3FF0000U)
#define locald36_LDPRR129_lumd450_SHIFT          (16U)
/*! lumd450 - lumdat_450 */
#define locald36_LDPRR129_lumd450(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR129_lumd450_SHIFT)) & locald36_LDPRR129_lumd450_MASK)
/*! @} */

/*! @name LDPRR12A - ldprofilereg12a */
/*! @{ */

#define locald36_LDPRR12A_lumd453_MASK           (0x3FFU)
#define locald36_LDPRR12A_lumd453_SHIFT          (0U)
/*! lumd453 - lumdat_453 */
#define locald36_LDPRR12A_lumd453(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12A_lumd453_SHIFT)) & locald36_LDPRR12A_lumd453_MASK)

#define locald36_LDPRR12A_lumd452_MASK           (0x3FF0000U)
#define locald36_LDPRR12A_lumd452_SHIFT          (16U)
/*! lumd452 - lumdat_452 */
#define locald36_LDPRR12A_lumd452(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12A_lumd452_SHIFT)) & locald36_LDPRR12A_lumd452_MASK)
/*! @} */

/*! @name LDPRR12B - ldprofilereg12b */
/*! @{ */

#define locald36_LDPRR12B_lumd455_MASK           (0x3FFU)
#define locald36_LDPRR12B_lumd455_SHIFT          (0U)
/*! lumd455 - lumdat_455 */
#define locald36_LDPRR12B_lumd455(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12B_lumd455_SHIFT)) & locald36_LDPRR12B_lumd455_MASK)

#define locald36_LDPRR12B_lumd454_MASK           (0x3FF0000U)
#define locald36_LDPRR12B_lumd454_SHIFT          (16U)
/*! lumd454 - lumdat_454 */
#define locald36_LDPRR12B_lumd454(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12B_lumd454_SHIFT)) & locald36_LDPRR12B_lumd454_MASK)
/*! @} */

/*! @name LDPRR12C - ldprofilereg12c */
/*! @{ */

#define locald36_LDPRR12C_lumd457_MASK           (0x3FFU)
#define locald36_LDPRR12C_lumd457_SHIFT          (0U)
/*! lumd457 - lumdat_457 */
#define locald36_LDPRR12C_lumd457(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12C_lumd457_SHIFT)) & locald36_LDPRR12C_lumd457_MASK)

#define locald36_LDPRR12C_lumd456_MASK           (0x3FF0000U)
#define locald36_LDPRR12C_lumd456_SHIFT          (16U)
/*! lumd456 - lumdat_456 */
#define locald36_LDPRR12C_lumd456(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12C_lumd456_SHIFT)) & locald36_LDPRR12C_lumd456_MASK)
/*! @} */

/*! @name LDPRR12D - ldprofilereg12d */
/*! @{ */

#define locald36_LDPRR12D_lumd459_MASK           (0x3FFU)
#define locald36_LDPRR12D_lumd459_SHIFT          (0U)
/*! lumd459 - lumdat_459 */
#define locald36_LDPRR12D_lumd459(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12D_lumd459_SHIFT)) & locald36_LDPRR12D_lumd459_MASK)

#define locald36_LDPRR12D_lumd458_MASK           (0x3FF0000U)
#define locald36_LDPRR12D_lumd458_SHIFT          (16U)
/*! lumd458 - lumdat_458 */
#define locald36_LDPRR12D_lumd458(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12D_lumd458_SHIFT)) & locald36_LDPRR12D_lumd458_MASK)
/*! @} */

/*! @name LDPRR12E - ldprofilereg12e */
/*! @{ */

#define locald36_LDPRR12E_lumd461_MASK           (0x3FFU)
#define locald36_LDPRR12E_lumd461_SHIFT          (0U)
/*! lumd461 - lumdat_461 */
#define locald36_LDPRR12E_lumd461(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12E_lumd461_SHIFT)) & locald36_LDPRR12E_lumd461_MASK)

#define locald36_LDPRR12E_lumd460_MASK           (0x3FF0000U)
#define locald36_LDPRR12E_lumd460_SHIFT          (16U)
/*! lumd460 - lumdat_460 */
#define locald36_LDPRR12E_lumd460(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12E_lumd460_SHIFT)) & locald36_LDPRR12E_lumd460_MASK)
/*! @} */

/*! @name LDPRR12F - ldprofilereg12f */
/*! @{ */

#define locald36_LDPRR12F_lumd463_MASK           (0x3FFU)
#define locald36_LDPRR12F_lumd463_SHIFT          (0U)
/*! lumd463 - lumdat_463 */
#define locald36_LDPRR12F_lumd463(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12F_lumd463_SHIFT)) & locald36_LDPRR12F_lumd463_MASK)

#define locald36_LDPRR12F_lumd462_MASK           (0x3FF0000U)
#define locald36_LDPRR12F_lumd462_SHIFT          (16U)
/*! lumd462 - lumdat_462 */
#define locald36_LDPRR12F_lumd462(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR12F_lumd462_SHIFT)) & locald36_LDPRR12F_lumd462_MASK)
/*! @} */

/*! @name LDPRR130 - ldprofilereg130 */
/*! @{ */

#define locald36_LDPRR130_lumd465_MASK           (0x3FFU)
#define locald36_LDPRR130_lumd465_SHIFT          (0U)
/*! lumd465 - lumdat_465 */
#define locald36_LDPRR130_lumd465(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR130_lumd465_SHIFT)) & locald36_LDPRR130_lumd465_MASK)

#define locald36_LDPRR130_lumd464_MASK           (0x3FF0000U)
#define locald36_LDPRR130_lumd464_SHIFT          (16U)
/*! lumd464 - lumdat_464 */
#define locald36_LDPRR130_lumd464(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR130_lumd464_SHIFT)) & locald36_LDPRR130_lumd464_MASK)
/*! @} */

/*! @name LDPRR131 - ldprofilereg131 */
/*! @{ */

#define locald36_LDPRR131_lumd467_MASK           (0x3FFU)
#define locald36_LDPRR131_lumd467_SHIFT          (0U)
/*! lumd467 - lumdat_467 */
#define locald36_LDPRR131_lumd467(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR131_lumd467_SHIFT)) & locald36_LDPRR131_lumd467_MASK)

#define locald36_LDPRR131_lumd466_MASK           (0x3FF0000U)
#define locald36_LDPRR131_lumd466_SHIFT          (16U)
/*! lumd466 - lumdat_466 */
#define locald36_LDPRR131_lumd466(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR131_lumd466_SHIFT)) & locald36_LDPRR131_lumd466_MASK)
/*! @} */

/*! @name LDPRR132 - ldprofilereg132 */
/*! @{ */

#define locald36_LDPRR132_lumd469_MASK           (0x3FFU)
#define locald36_LDPRR132_lumd469_SHIFT          (0U)
/*! lumd469 - lumdat_469 */
#define locald36_LDPRR132_lumd469(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR132_lumd469_SHIFT)) & locald36_LDPRR132_lumd469_MASK)

#define locald36_LDPRR132_lumd468_MASK           (0x3FF0000U)
#define locald36_LDPRR132_lumd468_SHIFT          (16U)
/*! lumd468 - lumdat_468 */
#define locald36_LDPRR132_lumd468(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR132_lumd468_SHIFT)) & locald36_LDPRR132_lumd468_MASK)
/*! @} */

/*! @name LDPRR133 - ldprofilereg133 */
/*! @{ */

#define locald36_LDPRR133_lumd471_MASK           (0x3FFU)
#define locald36_LDPRR133_lumd471_SHIFT          (0U)
/*! lumd471 - lumdat_471 */
#define locald36_LDPRR133_lumd471(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR133_lumd471_SHIFT)) & locald36_LDPRR133_lumd471_MASK)

#define locald36_LDPRR133_lumd470_MASK           (0x3FF0000U)
#define locald36_LDPRR133_lumd470_SHIFT          (16U)
/*! lumd470 - lumdat_470 */
#define locald36_LDPRR133_lumd470(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR133_lumd470_SHIFT)) & locald36_LDPRR133_lumd470_MASK)
/*! @} */

/*! @name LDPRR134 - ldprofilereg134 */
/*! @{ */

#define locald36_LDPRR134_lumd473_MASK           (0x3FFU)
#define locald36_LDPRR134_lumd473_SHIFT          (0U)
/*! lumd473 - lumdat_473 */
#define locald36_LDPRR134_lumd473(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR134_lumd473_SHIFT)) & locald36_LDPRR134_lumd473_MASK)

#define locald36_LDPRR134_lumd472_MASK           (0x3FF0000U)
#define locald36_LDPRR134_lumd472_SHIFT          (16U)
/*! lumd472 - lumdat_472 */
#define locald36_LDPRR134_lumd472(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR134_lumd472_SHIFT)) & locald36_LDPRR134_lumd472_MASK)
/*! @} */

/*! @name LDPRR135 - ldprofilereg135 */
/*! @{ */

#define locald36_LDPRR135_lumd475_MASK           (0x3FFU)
#define locald36_LDPRR135_lumd475_SHIFT          (0U)
/*! lumd475 - lumdat_475 */
#define locald36_LDPRR135_lumd475(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR135_lumd475_SHIFT)) & locald36_LDPRR135_lumd475_MASK)

#define locald36_LDPRR135_lumd474_MASK           (0x3FF0000U)
#define locald36_LDPRR135_lumd474_SHIFT          (16U)
/*! lumd474 - lumdat_474 */
#define locald36_LDPRR135_lumd474(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR135_lumd474_SHIFT)) & locald36_LDPRR135_lumd474_MASK)
/*! @} */

/*! @name LDPRR136 - ldprofilereg136 */
/*! @{ */

#define locald36_LDPRR136_lumd477_MASK           (0x3FFU)
#define locald36_LDPRR136_lumd477_SHIFT          (0U)
/*! lumd477 - lumdat_477 */
#define locald36_LDPRR136_lumd477(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR136_lumd477_SHIFT)) & locald36_LDPRR136_lumd477_MASK)

#define locald36_LDPRR136_lumd476_MASK           (0x3FF0000U)
#define locald36_LDPRR136_lumd476_SHIFT          (16U)
/*! lumd476 - lumdat_476 */
#define locald36_LDPRR136_lumd476(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR136_lumd476_SHIFT)) & locald36_LDPRR136_lumd476_MASK)
/*! @} */

/*! @name LDPRR137 - ldprofilereg137 */
/*! @{ */

#define locald36_LDPRR137_lumd479_MASK           (0x3FFU)
#define locald36_LDPRR137_lumd479_SHIFT          (0U)
/*! lumd479 - lumdat_479 */
#define locald36_LDPRR137_lumd479(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR137_lumd479_SHIFT)) & locald36_LDPRR137_lumd479_MASK)

#define locald36_LDPRR137_lumd478_MASK           (0x3FF0000U)
#define locald36_LDPRR137_lumd478_SHIFT          (16U)
/*! lumd478 - lumdat_478 */
#define locald36_LDPRR137_lumd478(x)             (((uint32_t)(((uint32_t)(x)) << locald36_LDPRR137_lumd478_SHIFT)) & locald36_LDPRR137_lumd478_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald36_Register_Masks */


/*!
 * @}
 */ /* end of group locald36_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD36_H_ */

