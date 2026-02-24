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
**         CMSIS Peripheral Access Layer for locald38
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
 * @file PERI_locald38.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald38
 *
 * CMSIS Peripheral Access Layer for locald38
 */

#if !defined(PERI_LOCALD38_H_)
#define PERI_LOCALD38_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald38 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald38_Peripheral_Access_Layer locald38 Peripheral Access Layer
 * @{
 */

/** locald38 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR160;                          /**< ldprofilereg160, offset: 0x0 */
  __IO uint32_t LDPRR161;                          /**< ldprofilereg161, offset: 0x4 */
  __IO uint32_t LDPRR162;                          /**< ldprofilereg162, offset: 0x8 */
  __IO uint32_t LDPRR163;                          /**< ldprofilereg163, offset: 0xC */
  __IO uint32_t LDPRR164;                          /**< ldprofilereg164, offset: 0x10 */
  __IO uint32_t LDPRR165;                          /**< ldprofilereg165, offset: 0x14 */
  __IO uint32_t LDPRR166;                          /**< ldprofilereg166, offset: 0x18 */
  __IO uint32_t LDPRR167;                          /**< ldprofilereg167, offset: 0x1C */
  __IO uint32_t LDPRR168;                          /**< ldprofilereg168, offset: 0x20 */
  __IO uint32_t LDPRR169;                          /**< ldprofilereg169, offset: 0x24 */
  __IO uint32_t LDPRR16A;                          /**< ldprofilereg16a, offset: 0x28 */
  __IO uint32_t LDPRR16B;                          /**< ldprofilereg16b, offset: 0x2C */
  __IO uint32_t LDPRR16C;                          /**< ldprofilereg16c, offset: 0x30 */
  __IO uint32_t LDPRR16D;                          /**< ldprofilereg16d, offset: 0x34 */
  __IO uint32_t LDPRR16E;                          /**< ldprofilereg16e, offset: 0x38 */
  __IO uint32_t LDPRR16F;                          /**< ldprofilereg16f, offset: 0x3C */
  __IO uint32_t LDPRR170;                          /**< ldprofilereg170, offset: 0x40 */
  __IO uint32_t LDPRR171;                          /**< ldprofilereg171, offset: 0x44 */
  __IO uint32_t LDPRR172;                          /**< ldprofilereg172, offset: 0x48 */
  __IO uint32_t LDPRR173;                          /**< ldprofilereg173, offset: 0x4C */
  __IO uint32_t LDPRR174;                          /**< ldprofilereg174, offset: 0x50 */
  __IO uint32_t LDPRR175;                          /**< ldprofilereg175, offset: 0x54 */
  __IO uint32_t LDPRR176;                          /**< ldprofilereg176, offset: 0x58 */
  __IO uint32_t LDPRR177;                          /**< ldprofilereg177, offset: 0x5C */
} locald38_Type;

/* ----------------------------------------------------------------------------
   -- locald38 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald38_Register_Masks locald38 Register Masks
 * @{
 */

/*! @name LDPRR160 - ldprofilereg160 */
/*! @{ */

#define locald38_LDPRR160_lumd529_MASK           (0x3FFU)
#define locald38_LDPRR160_lumd529_SHIFT          (0U)
/*! lumd529 - lumdat_529 */
#define locald38_LDPRR160_lumd529(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR160_lumd529_SHIFT)) & locald38_LDPRR160_lumd529_MASK)

#define locald38_LDPRR160_lumd528_MASK           (0x3FF0000U)
#define locald38_LDPRR160_lumd528_SHIFT          (16U)
/*! lumd528 - lumdat_528 */
#define locald38_LDPRR160_lumd528(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR160_lumd528_SHIFT)) & locald38_LDPRR160_lumd528_MASK)
/*! @} */

/*! @name LDPRR161 - ldprofilereg161 */
/*! @{ */

#define locald38_LDPRR161_lumd531_MASK           (0x3FFU)
#define locald38_LDPRR161_lumd531_SHIFT          (0U)
/*! lumd531 - lumdat_531 */
#define locald38_LDPRR161_lumd531(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR161_lumd531_SHIFT)) & locald38_LDPRR161_lumd531_MASK)

#define locald38_LDPRR161_lumd530_MASK           (0x3FF0000U)
#define locald38_LDPRR161_lumd530_SHIFT          (16U)
/*! lumd530 - lumdat_530 */
#define locald38_LDPRR161_lumd530(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR161_lumd530_SHIFT)) & locald38_LDPRR161_lumd530_MASK)
/*! @} */

/*! @name LDPRR162 - ldprofilereg162 */
/*! @{ */

#define locald38_LDPRR162_lumd533_MASK           (0x3FFU)
#define locald38_LDPRR162_lumd533_SHIFT          (0U)
/*! lumd533 - lumdat_533 */
#define locald38_LDPRR162_lumd533(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR162_lumd533_SHIFT)) & locald38_LDPRR162_lumd533_MASK)

#define locald38_LDPRR162_lumd532_MASK           (0x3FF0000U)
#define locald38_LDPRR162_lumd532_SHIFT          (16U)
/*! lumd532 - lumdat_532 */
#define locald38_LDPRR162_lumd532(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR162_lumd532_SHIFT)) & locald38_LDPRR162_lumd532_MASK)
/*! @} */

/*! @name LDPRR163 - ldprofilereg163 */
/*! @{ */

#define locald38_LDPRR163_lumd535_MASK           (0x3FFU)
#define locald38_LDPRR163_lumd535_SHIFT          (0U)
/*! lumd535 - lumdat_535 */
#define locald38_LDPRR163_lumd535(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR163_lumd535_SHIFT)) & locald38_LDPRR163_lumd535_MASK)

#define locald38_LDPRR163_lumd534_MASK           (0x3FF0000U)
#define locald38_LDPRR163_lumd534_SHIFT          (16U)
/*! lumd534 - lumdat_534 */
#define locald38_LDPRR163_lumd534(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR163_lumd534_SHIFT)) & locald38_LDPRR163_lumd534_MASK)
/*! @} */

/*! @name LDPRR164 - ldprofilereg164 */
/*! @{ */

#define locald38_LDPRR164_lumd537_MASK           (0x3FFU)
#define locald38_LDPRR164_lumd537_SHIFT          (0U)
/*! lumd537 - lumdat_537 */
#define locald38_LDPRR164_lumd537(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR164_lumd537_SHIFT)) & locald38_LDPRR164_lumd537_MASK)

#define locald38_LDPRR164_lumd536_MASK           (0x3FF0000U)
#define locald38_LDPRR164_lumd536_SHIFT          (16U)
/*! lumd536 - lumdat_536 */
#define locald38_LDPRR164_lumd536(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR164_lumd536_SHIFT)) & locald38_LDPRR164_lumd536_MASK)
/*! @} */

/*! @name LDPRR165 - ldprofilereg165 */
/*! @{ */

#define locald38_LDPRR165_lumd539_MASK           (0x3FFU)
#define locald38_LDPRR165_lumd539_SHIFT          (0U)
/*! lumd539 - lumdat_539 */
#define locald38_LDPRR165_lumd539(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR165_lumd539_SHIFT)) & locald38_LDPRR165_lumd539_MASK)

#define locald38_LDPRR165_lumd538_MASK           (0x3FF0000U)
#define locald38_LDPRR165_lumd538_SHIFT          (16U)
/*! lumd538 - lumdat_538 */
#define locald38_LDPRR165_lumd538(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR165_lumd538_SHIFT)) & locald38_LDPRR165_lumd538_MASK)
/*! @} */

/*! @name LDPRR166 - ldprofilereg166 */
/*! @{ */

#define locald38_LDPRR166_lumd541_MASK           (0x3FFU)
#define locald38_LDPRR166_lumd541_SHIFT          (0U)
/*! lumd541 - lumdat_541 */
#define locald38_LDPRR166_lumd541(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR166_lumd541_SHIFT)) & locald38_LDPRR166_lumd541_MASK)

#define locald38_LDPRR166_lumd540_MASK           (0x3FF0000U)
#define locald38_LDPRR166_lumd540_SHIFT          (16U)
/*! lumd540 - lumdat_540 */
#define locald38_LDPRR166_lumd540(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR166_lumd540_SHIFT)) & locald38_LDPRR166_lumd540_MASK)
/*! @} */

/*! @name LDPRR167 - ldprofilereg167 */
/*! @{ */

#define locald38_LDPRR167_lumd543_MASK           (0x3FFU)
#define locald38_LDPRR167_lumd543_SHIFT          (0U)
/*! lumd543 - lumdat_543 */
#define locald38_LDPRR167_lumd543(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR167_lumd543_SHIFT)) & locald38_LDPRR167_lumd543_MASK)

#define locald38_LDPRR167_lumd542_MASK           (0x3FF0000U)
#define locald38_LDPRR167_lumd542_SHIFT          (16U)
/*! lumd542 - lumdat_542 */
#define locald38_LDPRR167_lumd542(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR167_lumd542_SHIFT)) & locald38_LDPRR167_lumd542_MASK)
/*! @} */

/*! @name LDPRR168 - ldprofilereg168 */
/*! @{ */

#define locald38_LDPRR168_lumd545_MASK           (0x3FFU)
#define locald38_LDPRR168_lumd545_SHIFT          (0U)
/*! lumd545 - lumdat_545 */
#define locald38_LDPRR168_lumd545(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR168_lumd545_SHIFT)) & locald38_LDPRR168_lumd545_MASK)

#define locald38_LDPRR168_lumd544_MASK           (0x3FF0000U)
#define locald38_LDPRR168_lumd544_SHIFT          (16U)
/*! lumd544 - lumdat_544 */
#define locald38_LDPRR168_lumd544(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR168_lumd544_SHIFT)) & locald38_LDPRR168_lumd544_MASK)
/*! @} */

/*! @name LDPRR169 - ldprofilereg169 */
/*! @{ */

#define locald38_LDPRR169_lumd547_MASK           (0x3FFU)
#define locald38_LDPRR169_lumd547_SHIFT          (0U)
/*! lumd547 - lumdat_547 */
#define locald38_LDPRR169_lumd547(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR169_lumd547_SHIFT)) & locald38_LDPRR169_lumd547_MASK)

#define locald38_LDPRR169_lumd546_MASK           (0x3FF0000U)
#define locald38_LDPRR169_lumd546_SHIFT          (16U)
/*! lumd546 - lumdat_546 */
#define locald38_LDPRR169_lumd546(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR169_lumd546_SHIFT)) & locald38_LDPRR169_lumd546_MASK)
/*! @} */

/*! @name LDPRR16A - ldprofilereg16a */
/*! @{ */

#define locald38_LDPRR16A_lumd549_MASK           (0x3FFU)
#define locald38_LDPRR16A_lumd549_SHIFT          (0U)
/*! lumd549 - lumdat_549 */
#define locald38_LDPRR16A_lumd549(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16A_lumd549_SHIFT)) & locald38_LDPRR16A_lumd549_MASK)

#define locald38_LDPRR16A_lumd548_MASK           (0x3FF0000U)
#define locald38_LDPRR16A_lumd548_SHIFT          (16U)
/*! lumd548 - lumdat_548 */
#define locald38_LDPRR16A_lumd548(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16A_lumd548_SHIFT)) & locald38_LDPRR16A_lumd548_MASK)
/*! @} */

/*! @name LDPRR16B - ldprofilereg16b */
/*! @{ */

#define locald38_LDPRR16B_lumd551_MASK           (0x3FFU)
#define locald38_LDPRR16B_lumd551_SHIFT          (0U)
/*! lumd551 - lumdat_551 */
#define locald38_LDPRR16B_lumd551(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16B_lumd551_SHIFT)) & locald38_LDPRR16B_lumd551_MASK)

#define locald38_LDPRR16B_lumd550_MASK           (0x3FF0000U)
#define locald38_LDPRR16B_lumd550_SHIFT          (16U)
/*! lumd550 - lumdat_550 */
#define locald38_LDPRR16B_lumd550(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16B_lumd550_SHIFT)) & locald38_LDPRR16B_lumd550_MASK)
/*! @} */

/*! @name LDPRR16C - ldprofilereg16c */
/*! @{ */

#define locald38_LDPRR16C_lumd553_MASK           (0x3FFU)
#define locald38_LDPRR16C_lumd553_SHIFT          (0U)
/*! lumd553 - lumdat_553 */
#define locald38_LDPRR16C_lumd553(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16C_lumd553_SHIFT)) & locald38_LDPRR16C_lumd553_MASK)

#define locald38_LDPRR16C_lumd552_MASK           (0x3FF0000U)
#define locald38_LDPRR16C_lumd552_SHIFT          (16U)
/*! lumd552 - lumdat_552 */
#define locald38_LDPRR16C_lumd552(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16C_lumd552_SHIFT)) & locald38_LDPRR16C_lumd552_MASK)
/*! @} */

/*! @name LDPRR16D - ldprofilereg16d */
/*! @{ */

#define locald38_LDPRR16D_lumd555_MASK           (0x3FFU)
#define locald38_LDPRR16D_lumd555_SHIFT          (0U)
/*! lumd555 - lumdat_555 */
#define locald38_LDPRR16D_lumd555(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16D_lumd555_SHIFT)) & locald38_LDPRR16D_lumd555_MASK)

#define locald38_LDPRR16D_lumd554_MASK           (0x3FF0000U)
#define locald38_LDPRR16D_lumd554_SHIFT          (16U)
/*! lumd554 - lumdat_554 */
#define locald38_LDPRR16D_lumd554(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16D_lumd554_SHIFT)) & locald38_LDPRR16D_lumd554_MASK)
/*! @} */

/*! @name LDPRR16E - ldprofilereg16e */
/*! @{ */

#define locald38_LDPRR16E_lumd557_MASK           (0x3FFU)
#define locald38_LDPRR16E_lumd557_SHIFT          (0U)
/*! lumd557 - lumdat_557 */
#define locald38_LDPRR16E_lumd557(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16E_lumd557_SHIFT)) & locald38_LDPRR16E_lumd557_MASK)

#define locald38_LDPRR16E_lumd556_MASK           (0x3FF0000U)
#define locald38_LDPRR16E_lumd556_SHIFT          (16U)
/*! lumd556 - lumdat_556 */
#define locald38_LDPRR16E_lumd556(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16E_lumd556_SHIFT)) & locald38_LDPRR16E_lumd556_MASK)
/*! @} */

/*! @name LDPRR16F - ldprofilereg16f */
/*! @{ */

#define locald38_LDPRR16F_lumd559_MASK           (0x3FFU)
#define locald38_LDPRR16F_lumd559_SHIFT          (0U)
/*! lumd559 - lumdat_559 */
#define locald38_LDPRR16F_lumd559(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16F_lumd559_SHIFT)) & locald38_LDPRR16F_lumd559_MASK)

#define locald38_LDPRR16F_lumd558_MASK           (0x3FF0000U)
#define locald38_LDPRR16F_lumd558_SHIFT          (16U)
/*! lumd558 - lumdat_558 */
#define locald38_LDPRR16F_lumd558(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR16F_lumd558_SHIFT)) & locald38_LDPRR16F_lumd558_MASK)
/*! @} */

/*! @name LDPRR170 - ldprofilereg170 */
/*! @{ */

#define locald38_LDPRR170_lumd561_MASK           (0x3FFU)
#define locald38_LDPRR170_lumd561_SHIFT          (0U)
/*! lumd561 - lumdat_561 */
#define locald38_LDPRR170_lumd561(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR170_lumd561_SHIFT)) & locald38_LDPRR170_lumd561_MASK)

#define locald38_LDPRR170_lumd560_MASK           (0x3FF0000U)
#define locald38_LDPRR170_lumd560_SHIFT          (16U)
/*! lumd560 - lumdat_560 */
#define locald38_LDPRR170_lumd560(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR170_lumd560_SHIFT)) & locald38_LDPRR170_lumd560_MASK)
/*! @} */

/*! @name LDPRR171 - ldprofilereg171 */
/*! @{ */

#define locald38_LDPRR171_lumd563_MASK           (0x3FFU)
#define locald38_LDPRR171_lumd563_SHIFT          (0U)
/*! lumd563 - lumdat_563 */
#define locald38_LDPRR171_lumd563(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR171_lumd563_SHIFT)) & locald38_LDPRR171_lumd563_MASK)

#define locald38_LDPRR171_lumd562_MASK           (0x3FF0000U)
#define locald38_LDPRR171_lumd562_SHIFT          (16U)
/*! lumd562 - lumdat_562 */
#define locald38_LDPRR171_lumd562(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR171_lumd562_SHIFT)) & locald38_LDPRR171_lumd562_MASK)
/*! @} */

/*! @name LDPRR172 - ldprofilereg172 */
/*! @{ */

#define locald38_LDPRR172_lumd565_MASK           (0x3FFU)
#define locald38_LDPRR172_lumd565_SHIFT          (0U)
/*! lumd565 - lumdat_565 */
#define locald38_LDPRR172_lumd565(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR172_lumd565_SHIFT)) & locald38_LDPRR172_lumd565_MASK)

#define locald38_LDPRR172_lumd564_MASK           (0x3FF0000U)
#define locald38_LDPRR172_lumd564_SHIFT          (16U)
/*! lumd564 - lumdat_564 */
#define locald38_LDPRR172_lumd564(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR172_lumd564_SHIFT)) & locald38_LDPRR172_lumd564_MASK)
/*! @} */

/*! @name LDPRR173 - ldprofilereg173 */
/*! @{ */

#define locald38_LDPRR173_lumd567_MASK           (0x3FFU)
#define locald38_LDPRR173_lumd567_SHIFT          (0U)
/*! lumd567 - lumdat_567 */
#define locald38_LDPRR173_lumd567(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR173_lumd567_SHIFT)) & locald38_LDPRR173_lumd567_MASK)

#define locald38_LDPRR173_lumd566_MASK           (0x3FF0000U)
#define locald38_LDPRR173_lumd566_SHIFT          (16U)
/*! lumd566 - lumdat_566 */
#define locald38_LDPRR173_lumd566(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR173_lumd566_SHIFT)) & locald38_LDPRR173_lumd566_MASK)
/*! @} */

/*! @name LDPRR174 - ldprofilereg174 */
/*! @{ */

#define locald38_LDPRR174_lumd569_MASK           (0x3FFU)
#define locald38_LDPRR174_lumd569_SHIFT          (0U)
/*! lumd569 - lumdat_569 */
#define locald38_LDPRR174_lumd569(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR174_lumd569_SHIFT)) & locald38_LDPRR174_lumd569_MASK)

#define locald38_LDPRR174_lumd568_MASK           (0x3FF0000U)
#define locald38_LDPRR174_lumd568_SHIFT          (16U)
/*! lumd568 - lumdat_568 */
#define locald38_LDPRR174_lumd568(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR174_lumd568_SHIFT)) & locald38_LDPRR174_lumd568_MASK)
/*! @} */

/*! @name LDPRR175 - ldprofilereg175 */
/*! @{ */

#define locald38_LDPRR175_lumd571_MASK           (0x3FFU)
#define locald38_LDPRR175_lumd571_SHIFT          (0U)
/*! lumd571 - lumdat_571 */
#define locald38_LDPRR175_lumd571(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR175_lumd571_SHIFT)) & locald38_LDPRR175_lumd571_MASK)

#define locald38_LDPRR175_lumd570_MASK           (0x3FF0000U)
#define locald38_LDPRR175_lumd570_SHIFT          (16U)
/*! lumd570 - lumdat_570 */
#define locald38_LDPRR175_lumd570(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR175_lumd570_SHIFT)) & locald38_LDPRR175_lumd570_MASK)
/*! @} */

/*! @name LDPRR176 - ldprofilereg176 */
/*! @{ */

#define locald38_LDPRR176_lumd573_MASK           (0x3FFU)
#define locald38_LDPRR176_lumd573_SHIFT          (0U)
/*! lumd573 - lumdat_573 */
#define locald38_LDPRR176_lumd573(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR176_lumd573_SHIFT)) & locald38_LDPRR176_lumd573_MASK)

#define locald38_LDPRR176_lumd572_MASK           (0x3FF0000U)
#define locald38_LDPRR176_lumd572_SHIFT          (16U)
/*! lumd572 - lumdat_572 */
#define locald38_LDPRR176_lumd572(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR176_lumd572_SHIFT)) & locald38_LDPRR176_lumd572_MASK)
/*! @} */

/*! @name LDPRR177 - ldprofilereg177 */
/*! @{ */

#define locald38_LDPRR177_lumd575_MASK           (0x3FFU)
#define locald38_LDPRR177_lumd575_SHIFT          (0U)
/*! lumd575 - lumdat_575 */
#define locald38_LDPRR177_lumd575(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR177_lumd575_SHIFT)) & locald38_LDPRR177_lumd575_MASK)

#define locald38_LDPRR177_lumd574_MASK           (0x3FF0000U)
#define locald38_LDPRR177_lumd574_SHIFT          (16U)
/*! lumd574 - lumdat_574 */
#define locald38_LDPRR177_lumd574(x)             (((uint32_t)(((uint32_t)(x)) << locald38_LDPRR177_lumd574_SHIFT)) & locald38_LDPRR177_lumd574_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald38_Register_Masks */


/*!
 * @}
 */ /* end of group locald38_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD38_H_ */

