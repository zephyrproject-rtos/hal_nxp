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
**         CMSIS Peripheral Access Layer for splanar1
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
 * @file PERI_splanar1.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for splanar1
 *
 * CMSIS Peripheral Access Layer for splanar1
 */

#if !defined(PERI_SPLANAR1_H_)
#define PERI_SPLANAR1_H_                         /**< Symbol preventing repeated inclusion */

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
   -- splanar1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup splanar1_Peripheral_Access_Layer splanar1 Peripheral Access Layer
 * @{
 */

/** splanar1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t BASEA1;                            /**< BaseAddress1, offset: 0x0 */
  __IO uint32_t BASAMSB1;                          /**< BaseAddressMSB1, offset: 0x4 */
  __IO uint32_t DESBUFA1;                          /**< DestinationBufferAttributes1, offset: 0x8 */
} splanar1_Type;

/* ----------------------------------------------------------------------------
   -- splanar1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup splanar1_Register_Masks splanar1 Register Masks
 * @{
 */

/*! @name BASEA1 - BaseAddress1 */
/*! @{ */

#define splanar1_BASEA1_BaseAdd1_MASK            (0xFFFFFFFFU)
#define splanar1_BASEA1_BaseAdd1_SHIFT           (0U)
/*! BaseAdd1 - BaseAddress1 */
#define splanar1_BASEA1_BaseAdd1(x)              (((uint32_t)(((uint32_t)(x)) << splanar1_BASEA1_BaseAdd1_SHIFT)) & splanar1_BASEA1_BaseAdd1_MASK)
/*! @} */

/*! @name BASAMSB1 - BaseAddressMSB1 */
/*! @{ */

#define splanar1_BASAMSB1_BaAdMB1_MASK           (0xFFU)
#define splanar1_BASAMSB1_BaAdMB1_SHIFT          (0U)
/*! BaAdMB1 - BaseAddressMSB1 */
#define splanar1_BASAMSB1_BaAdMB1(x)             (((uint32_t)(((uint32_t)(x)) << splanar1_BASAMSB1_BaAdMB1_SHIFT)) & splanar1_BASAMSB1_BaAdMB1_MASK)
/*! @} */

/*! @name DESBUFA1 - DestinationBufferAttributes1 */
/*! @{ */

#define splanar1_DESBUFA1_Stride1_MASK           (0x1FFFFU)
#define splanar1_DESBUFA1_Stride1_SHIFT          (0U)
/*! Stride1 - Stride1 */
#define splanar1_DESBUFA1_Stride1(x)             (((uint32_t)(((uint32_t)(x)) << splanar1_DESBUFA1_Stride1_SHIFT)) & splanar1_DESBUFA1_Stride1_MASK)

#define splanar1_DESBUFA1_XDownsc1_MASK          (0x20000U)
#define splanar1_DESBUFA1_XDownsc1_SHIFT         (17U)
/*! XDownsc1 - XDownscale1
 *  0b0..write every pixel to buffer.
 *  0b1..write every second pixel to buffer. Enables YUV422Downsampling. Only for Rastermode = NORMAL. All
 *       correlated widths and horizontal offsets must be even.
 */
#define splanar1_DESBUFA1_XDownsc1(x)            (((uint32_t)(((uint32_t)(x)) << splanar1_DESBUFA1_XDownsc1_SHIFT)) & splanar1_DESBUFA1_XDownsc1_MASK)

#define splanar1_DESBUFA1_YDownsc1_MASK          (0x40000U)
#define splanar1_DESBUFA1_YDownsc1_SHIFT         (18U)
/*! YDownsc1 - YDownscale1
 *  0b0..write every line to buffer.
 *  0b1..write every second line to buffer. Enables YUV420Downsampling. All correlated heights and vertical offsets must be even.
 */
#define splanar1_DESBUFA1_YDownsc1(x)            (((uint32_t)(((uint32_t)(x)) << splanar1_DESBUFA1_YDownsc1_SHIFT)) & splanar1_DESBUFA1_YDownsc1_MASK)

#define splanar1_DESBUFA1_AlphaE1_MASK           (0x100000U)
#define splanar1_DESBUFA1_AlphaE1_SHIFT          (20U)
/*! AlphaE1 - AlphaEnable1 */
#define splanar1_DESBUFA1_AlphaE1(x)             (((uint32_t)(((uint32_t)(x)) << splanar1_DESBUFA1_AlphaE1_SHIFT)) & splanar1_DESBUFA1_AlphaE1_MASK)

#define splanar1_DESBUFA1_RedEn1_MASK            (0x200000U)
#define splanar1_DESBUFA1_RedEn1_SHIFT           (21U)
/*! RedEn1 - RedEnable1 */
#define splanar1_DESBUFA1_RedEn1(x)              (((uint32_t)(((uint32_t)(x)) << splanar1_DESBUFA1_RedEn1_SHIFT)) & splanar1_DESBUFA1_RedEn1_MASK)

#define splanar1_DESBUFA1_GreenEn1_MASK          (0x400000U)
#define splanar1_DESBUFA1_GreenEn1_SHIFT         (22U)
/*! GreenEn1 - GreenEnable1 */
#define splanar1_DESBUFA1_GreenEn1(x)            (((uint32_t)(((uint32_t)(x)) << splanar1_DESBUFA1_GreenEn1_SHIFT)) & splanar1_DESBUFA1_GreenEn1_MASK)

#define splanar1_DESBUFA1_BlueE1_MASK            (0x800000U)
#define splanar1_DESBUFA1_BlueE1_SHIFT           (23U)
/*! BlueE1 - BlueEnable1 */
#define splanar1_DESBUFA1_BlueE1(x)              (((uint32_t)(((uint32_t)(x)) << splanar1_DESBUFA1_BlueE1_SHIFT)) & splanar1_DESBUFA1_BlueE1_MASK)

#define splanar1_DESBUFA1_BitsPP1_MASK           (0x3F000000U)
#define splanar1_DESBUFA1_BitsPP1_SHIFT          (24U)
/*! BitsPP1 - BitsPerPixel1 */
#define splanar1_DESBUFA1_BitsPP1(x)             (((uint32_t)(((uint32_t)(x)) << splanar1_DESBUFA1_BitsPP1_SHIFT)) & splanar1_DESBUFA1_BitsPP1_MASK)

#define splanar1_DESBUFA1_DWBS1_MASK             (0x80000000U)
#define splanar1_DESBUFA1_DWBS1_SHIFT            (31U)
/*! DWBS1 - DWordByteSwap1 */
#define splanar1_DESBUFA1_DWBS1(x)               (((uint32_t)(((uint32_t)(x)) << splanar1_DESBUFA1_DWBS1_SHIFT)) & splanar1_DESBUFA1_DWBS1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group splanar1_Register_Masks */


/*!
 * @}
 */ /* end of group splanar1_Peripheral_Access_Layer */


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


#endif  /* PERI_SPLANAR1_H_ */

