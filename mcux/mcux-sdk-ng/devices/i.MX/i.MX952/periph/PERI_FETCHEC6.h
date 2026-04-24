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
**         CMSIS Peripheral Access Layer for fetchec6
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
 * @file PERI_fetchec6.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchec6
 *
 * CMSIS Peripheral Access Layer for fetchec6
 */

#if !defined(PERI_FETCHEC6_H_)
#define PERI_FETCHEC6_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchec6 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchec6_Peripheral_Access_Layer fetchec6 Peripheral Access Layer
 * @{
 */

/** fetchec6 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASEA0;                            /**< BaseAddress0, offset: 0x0 */
  __IO uint32_t BASAMSB0;                          /**< BaseAddressMSB0, offset: 0x4 */
  __IO uint32_t AUTOUBA0;                          /**< AutoUpdateBaseAddress0, offset: 0x8 */
  __IO uint32_t AUTUBAM0;                          /**< AutoUpdateBaseAddressMSB0, offset: 0xC */
  __IO uint32_t SOUBUAT0;                          /**< SourceBufferAttributes0, offset: 0x10 */
  __IO uint32_t SOUBUDI0;                          /**< SourceBufferDimension0, offset: 0x14 */
  __IO uint32_t COLCOMB0;                          /**< ColorComponentBits0, offset: 0x18 */
  __IO uint32_t COLCOMS0;                          /**< ColorComponentShift0, offset: 0x1C */
  __IO uint32_t LAYOFF0;                           /**< LayerOffset0, offset: 0x20 */
  __IO uint32_t CLIPWO0;                           /**< ClipWindowOffset0, offset: 0x24 */
  __IO uint32_t CLIPWID0;                          /**< ClipWindowDimensions0, offset: 0x28 */
  __IO uint32_t CONSTC0;                           /**< ConstantColor0, offset: 0x2C */
  __IO uint32_t LAYPRO0;                           /**< LayerProperty0, offset: 0x30 */
} fetchec6_Type;

/* ----------------------------------------------------------------------------
   -- fetchec6 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchec6_Register_Masks fetchec6 Register Masks
 * @{
 */

/*! @name BASEA0 - BaseAddress0 */
/*! @{ */

#define fetchec6_BASEA0_BaseAdd0_MASK            (0xFFFFFFFFU)
#define fetchec6_BASEA0_BaseAdd0_SHIFT           (0U)
/*! BaseAdd0 - BaseAddress0 */
#define fetchec6_BASEA0_BaseAdd0(x)              (((uint32_t)(((uint32_t)(x)) << fetchec6_BASEA0_BaseAdd0_SHIFT)) & fetchec6_BASEA0_BaseAdd0_MASK)
/*! @} */

/*! @name BASAMSB0 - BaseAddressMSB0 */
/*! @{ */

#define fetchec6_BASAMSB0_BaAdMB0_MASK           (0xFFU)
#define fetchec6_BASAMSB0_BaAdMB0_SHIFT          (0U)
/*! BaAdMB0 - BaseAddressMSB0 */
#define fetchec6_BASAMSB0_BaAdMB0(x)             (((uint32_t)(((uint32_t)(x)) << fetchec6_BASAMSB0_BaAdMB0_SHIFT)) & fetchec6_BASAMSB0_BaAdMB0_MASK)
/*! @} */

/*! @name AUTOUBA0 - AutoUpdateBaseAddress0 */
/*! @{ */

#define fetchec6_AUTOUBA0_AutoUBA0_MASK          (0xFFFFFFFFU)
#define fetchec6_AUTOUBA0_AutoUBA0_SHIFT         (0U)
/*! AutoUBA0 - AutoUpdateBaseAddress0 */
#define fetchec6_AUTOUBA0_AutoUBA0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec6_AUTOUBA0_AutoUBA0_SHIFT)) & fetchec6_AUTOUBA0_AutoUBA0_MASK)
/*! @} */

/*! @name AUTUBAM0 - AutoUpdateBaseAddressMSB0 */
/*! @{ */

#define fetchec6_AUTUBAM0_AutoUBM0_MASK          (0xFFU)
#define fetchec6_AUTUBAM0_AutoUBM0_SHIFT         (0U)
/*! AutoUBM0 - AutoUpdateBaseAddressMSB0 */
#define fetchec6_AUTUBAM0_AutoUBM0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec6_AUTUBAM0_AutoUBM0_SHIFT)) & fetchec6_AUTUBAM0_AutoUBM0_MASK)
/*! @} */

/*! @name SOUBUAT0 - SourceBufferAttributes0 */
/*! @{ */

#define fetchec6_SOUBUAT0_Stride0_MASK           (0xFFFFU)
#define fetchec6_SOUBUAT0_Stride0_SHIFT          (0U)
/*! Stride0 - Stride0 */
#define fetchec6_SOUBUAT0_Stride0(x)             (((uint32_t)(((uint32_t)(x)) << fetchec6_SOUBUAT0_Stride0_SHIFT)) & fetchec6_SOUBUAT0_Stride0_MASK)

#define fetchec6_SOUBUAT0_BitsPP0_MASK           (0x3F0000U)
#define fetchec6_SOUBUAT0_BitsPP0_SHIFT          (16U)
/*! BitsPP0 - BitsPerPixel0 */
#define fetchec6_SOUBUAT0_BitsPP0(x)             (((uint32_t)(((uint32_t)(x)) << fetchec6_SOUBUAT0_BitsPP0_SHIFT)) & fetchec6_SOUBUAT0_BitsPP0_MASK)

#define fetchec6_SOUBUAT0_BaAdAU0_MASK           (0x40000000U)
#define fetchec6_SOUBUAT0_BaAdAU0_SHIFT          (30U)
/*! BaAdAU0 - BaseAddressAutoUpdate0 */
#define fetchec6_SOUBUAT0_BaAdAU0(x)             (((uint32_t)(((uint32_t)(x)) << fetchec6_SOUBUAT0_BaAdAU0_SHIFT)) & fetchec6_SOUBUAT0_BaAdAU0_MASK)

#define fetchec6_SOUBUAT0_DWBS0_MASK             (0x80000000U)
#define fetchec6_SOUBUAT0_DWBS0_SHIFT            (31U)
/*! DWBS0 - DWordByteSwap0 */
#define fetchec6_SOUBUAT0_DWBS0(x)               (((uint32_t)(((uint32_t)(x)) << fetchec6_SOUBUAT0_DWBS0_SHIFT)) & fetchec6_SOUBUAT0_DWBS0_MASK)
/*! @} */

/*! @name SOUBUDI0 - SourceBufferDimension0 */
/*! @{ */

#define fetchec6_SOUBUDI0_LineW0_MASK            (0x3FFFU)
#define fetchec6_SOUBUDI0_LineW0_SHIFT           (0U)
/*! LineW0 - LineWidth0 */
#define fetchec6_SOUBUDI0_LineW0(x)              (((uint32_t)(((uint32_t)(x)) << fetchec6_SOUBUDI0_LineW0_SHIFT)) & fetchec6_SOUBUDI0_LineW0_MASK)

#define fetchec6_SOUBUDI0_LineC0_MASK            (0x3FFF0000U)
#define fetchec6_SOUBUDI0_LineC0_SHIFT           (16U)
/*! LineC0 - LineCount0 */
#define fetchec6_SOUBUDI0_LineC0(x)              (((uint32_t)(((uint32_t)(x)) << fetchec6_SOUBUDI0_LineC0_SHIFT)) & fetchec6_SOUBUDI0_LineC0_MASK)
/*! @} */

/*! @name COLCOMB0 - ColorComponentBits0 */
/*! @{ */

#define fetchec6_COLCOMB0_CompBiA0_MASK          (0xFU)
#define fetchec6_COLCOMB0_CompBiA0_SHIFT         (0U)
/*! CompBiA0 - ComponentBitsAlpha0 */
#define fetchec6_COLCOMB0_CompBiA0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec6_COLCOMB0_CompBiA0_SHIFT)) & fetchec6_COLCOMB0_CompBiA0_MASK)

#define fetchec6_COLCOMB0_CompBiB0_MASK          (0xF00U)
#define fetchec6_COLCOMB0_CompBiB0_SHIFT         (8U)
/*! CompBiB0 - ComponentBitsBlue0 */
#define fetchec6_COLCOMB0_CompBiB0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec6_COLCOMB0_CompBiB0_SHIFT)) & fetchec6_COLCOMB0_CompBiB0_MASK)

#define fetchec6_COLCOMB0_CompBiG0_MASK          (0xF0000U)
#define fetchec6_COLCOMB0_CompBiG0_SHIFT         (16U)
/*! CompBiG0 - ComponentBitsGreen0 */
#define fetchec6_COLCOMB0_CompBiG0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec6_COLCOMB0_CompBiG0_SHIFT)) & fetchec6_COLCOMB0_CompBiG0_MASK)

#define fetchec6_COLCOMB0_CompBiR0_MASK          (0xF000000U)
#define fetchec6_COLCOMB0_CompBiR0_SHIFT         (24U)
/*! CompBiR0 - ComponentBitsRed0 */
#define fetchec6_COLCOMB0_CompBiR0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec6_COLCOMB0_CompBiR0_SHIFT)) & fetchec6_COLCOMB0_CompBiR0_MASK)

#define fetchec6_COLCOMB0_ITUForm0_MASK          (0x80000000U)
#define fetchec6_COLCOMB0_ITUForm0_SHIFT         (31U)
/*! ITUForm0 - ITUFormat0 */
#define fetchec6_COLCOMB0_ITUForm0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec6_COLCOMB0_ITUForm0_SHIFT)) & fetchec6_COLCOMB0_ITUForm0_MASK)
/*! @} */

/*! @name COLCOMS0 - ColorComponentShift0 */
/*! @{ */

#define fetchec6_COLCOMS0_CompShA0_MASK          (0x1FU)
#define fetchec6_COLCOMS0_CompShA0_SHIFT         (0U)
/*! CompShA0 - ComponentShiftAlpha0 */
#define fetchec6_COLCOMS0_CompShA0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec6_COLCOMS0_CompShA0_SHIFT)) & fetchec6_COLCOMS0_CompShA0_MASK)

#define fetchec6_COLCOMS0_CompShB0_MASK          (0x1F00U)
#define fetchec6_COLCOMS0_CompShB0_SHIFT         (8U)
/*! CompShB0 - ComponentShiftBlue0 */
#define fetchec6_COLCOMS0_CompShB0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec6_COLCOMS0_CompShB0_SHIFT)) & fetchec6_COLCOMS0_CompShB0_MASK)

#define fetchec6_COLCOMS0_CompShG0_MASK          (0x1F0000U)
#define fetchec6_COLCOMS0_CompShG0_SHIFT         (16U)
/*! CompShG0 - ComponentShiftGreen0 */
#define fetchec6_COLCOMS0_CompShG0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec6_COLCOMS0_CompShG0_SHIFT)) & fetchec6_COLCOMS0_CompShG0_MASK)

#define fetchec6_COLCOMS0_CompShR0_MASK          (0x1F000000U)
#define fetchec6_COLCOMS0_CompShR0_SHIFT         (24U)
/*! CompShR0 - ComponentShiftRed0 */
#define fetchec6_COLCOMS0_CompShR0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec6_COLCOMS0_CompShR0_SHIFT)) & fetchec6_COLCOMS0_CompShR0_MASK)
/*! @} */

/*! @name LAYOFF0 - LayerOffset0 */
/*! @{ */

#define fetchec6_LAYOFF0_LayXOs0_MASK            (0x7FFFU)
#define fetchec6_LAYOFF0_LayXOs0_SHIFT           (0U)
/*! LayXOs0 - LayerXOffset0 */
#define fetchec6_LAYOFF0_LayXOs0(x)              (((uint32_t)(((uint32_t)(x)) << fetchec6_LAYOFF0_LayXOs0_SHIFT)) & fetchec6_LAYOFF0_LayXOs0_MASK)

#define fetchec6_LAYOFF0_LayYOs0_MASK            (0x7FFF0000U)
#define fetchec6_LAYOFF0_LayYOs0_SHIFT           (16U)
/*! LayYOs0 - LayerYOffset0 */
#define fetchec6_LAYOFF0_LayYOs0(x)              (((uint32_t)(((uint32_t)(x)) << fetchec6_LAYOFF0_LayYOs0_SHIFT)) & fetchec6_LAYOFF0_LayYOs0_MASK)
/*! @} */

/*! @name CLIPWO0 - ClipWindowOffset0 */
/*! @{ */

#define fetchec6_CLIPWO0_ClipWXO0_MASK           (0x7FFFU)
#define fetchec6_CLIPWO0_ClipWXO0_SHIFT          (0U)
/*! ClipWXO0 - ClipWindowXOffset0 */
#define fetchec6_CLIPWO0_ClipWXO0(x)             (((uint32_t)(((uint32_t)(x)) << fetchec6_CLIPWO0_ClipWXO0_SHIFT)) & fetchec6_CLIPWO0_ClipWXO0_MASK)

#define fetchec6_CLIPWO0_ClipWYO0_MASK           (0x7FFF0000U)
#define fetchec6_CLIPWO0_ClipWYO0_SHIFT          (16U)
/*! ClipWYO0 - ClipWindowYOffset0 */
#define fetchec6_CLIPWO0_ClipWYO0(x)             (((uint32_t)(((uint32_t)(x)) << fetchec6_CLIPWO0_ClipWYO0_SHIFT)) & fetchec6_CLIPWO0_ClipWYO0_MASK)
/*! @} */

/*! @name CLIPWID0 - ClipWindowDimensions0 */
/*! @{ */

#define fetchec6_CLIPWID0_ClipWW0_MASK           (0x3FFFU)
#define fetchec6_CLIPWID0_ClipWW0_SHIFT          (0U)
/*! ClipWW0 - ClipWindowWidth0 */
#define fetchec6_CLIPWID0_ClipWW0(x)             (((uint32_t)(((uint32_t)(x)) << fetchec6_CLIPWID0_ClipWW0_SHIFT)) & fetchec6_CLIPWID0_ClipWW0_MASK)

#define fetchec6_CLIPWID0_ClipWH0_MASK           (0x3FFF0000U)
#define fetchec6_CLIPWID0_ClipWH0_SHIFT          (16U)
/*! ClipWH0 - ClipWindowHeight0 */
#define fetchec6_CLIPWID0_ClipWH0(x)             (((uint32_t)(((uint32_t)(x)) << fetchec6_CLIPWID0_ClipWH0_SHIFT)) & fetchec6_CLIPWID0_ClipWH0_MASK)
/*! @} */

/*! @name CONSTC0 - ConstantColor0 */
/*! @{ */

#define fetchec6_CONSTC0_ConstA0_MASK            (0xFFU)
#define fetchec6_CONSTC0_ConstA0_SHIFT           (0U)
/*! ConstA0 - ConstantAlpha0 */
#define fetchec6_CONSTC0_ConstA0(x)              (((uint32_t)(((uint32_t)(x)) << fetchec6_CONSTC0_ConstA0_SHIFT)) & fetchec6_CONSTC0_ConstA0_MASK)

#define fetchec6_CONSTC0_ConstB0_MASK            (0xFF00U)
#define fetchec6_CONSTC0_ConstB0_SHIFT           (8U)
/*! ConstB0 - ConstantBlue0 */
#define fetchec6_CONSTC0_ConstB0(x)              (((uint32_t)(((uint32_t)(x)) << fetchec6_CONSTC0_ConstB0_SHIFT)) & fetchec6_CONSTC0_ConstB0_MASK)

#define fetchec6_CONSTC0_ConstG0_MASK            (0xFF0000U)
#define fetchec6_CONSTC0_ConstG0_SHIFT           (16U)
/*! ConstG0 - ConstantGreen0 */
#define fetchec6_CONSTC0_ConstG0(x)              (((uint32_t)(((uint32_t)(x)) << fetchec6_CONSTC0_ConstG0_SHIFT)) & fetchec6_CONSTC0_ConstG0_MASK)

#define fetchec6_CONSTC0_ConstR0_MASK            (0xFF000000U)
#define fetchec6_CONSTC0_ConstR0_SHIFT           (24U)
/*! ConstR0 - ConstantRed0 */
#define fetchec6_CONSTC0_ConstR0(x)              (((uint32_t)(((uint32_t)(x)) << fetchec6_CONSTC0_ConstR0_SHIFT)) & fetchec6_CONSTC0_ConstR0_MASK)
/*! @} */

/*! @name LAYPRO0 - LayerProperty0 */
/*! @{ */

#define fetchec6_LAYPRO0_TileMod0_MASK           (0x30U)
#define fetchec6_LAYPRO0_TileMod0_SHIFT          (4U)
/*! TileMod0 - TileMode0
 *  0b00..Use zero value
 *  0b01..Use constant color register value
 *  0b10..Use closest pixel from source buffer. Must not be used for DECODE or YUV422 operations or when SourceBufferEnable is 0.
 *  0b11..Use closest pixel from source buffer but zero for alpha component. Must not be used for DECODE or YUV422
 *        operations or when SourceBufferEnable is 0.
 */
#define fetchec6_LAYPRO0_TileMod0(x)             (((uint32_t)(((uint32_t)(x)) << fetchec6_LAYPRO0_TileMod0_SHIFT)) & fetchec6_LAYPRO0_TileMod0_MASK)

#define fetchec6_LAYPRO0_ClipWE0_MASK            (0x40000000U)
#define fetchec6_LAYPRO0_ClipWE0_SHIFT           (30U)
/*! ClipWE0 - ClipWindowEnable0 */
#define fetchec6_LAYPRO0_ClipWE0(x)              (((uint32_t)(((uint32_t)(x)) << fetchec6_LAYPRO0_ClipWE0_SHIFT)) & fetchec6_LAYPRO0_ClipWE0_MASK)

#define fetchec6_LAYPRO0_SrcBuEn0_MASK           (0x80000000U)
#define fetchec6_LAYPRO0_SrcBuEn0_SHIFT          (31U)
/*! SrcBuEn0 - SourceBufferEnable0 */
#define fetchec6_LAYPRO0_SrcBuEn0(x)             (((uint32_t)(((uint32_t)(x)) << fetchec6_LAYPRO0_SrcBuEn0_SHIFT)) & fetchec6_LAYPRO0_SrcBuEn0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchec6_Register_Masks */


/*!
 * @}
 */ /* end of group fetchec6_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHEC6_H_ */

