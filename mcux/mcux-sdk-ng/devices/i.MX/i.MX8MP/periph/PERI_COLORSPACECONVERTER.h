/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for COLORSPACECONVERTER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_COLORSPACECONVERTER.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for COLORSPACECONVERTER
 *
 * CMSIS Peripheral Access Layer for COLORSPACECONVERTER
 */

#if !defined(PERI_COLORSPACECONVERTER_H_)
#define PERI_COLORSPACECONVERTER_H_              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- COLORSPACECONVERTER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COLORSPACECONVERTER_Peripheral_Access_Layer COLORSPACECONVERTER Peripheral Access Layer
 * @{
 */

/** COLORSPACECONVERTER - Register Layout Typedef */
typedef struct {
  __IO uint8_t CSC_CFG;                            /**< Color Space Converter Interpolation and Decimation Configuration Register, offset: 0x0 */
  __IO uint8_t CSC_SCALE;                          /**< Color Space Converter Scale and Deep Color Configuration Register, offset: 0x1 */
  __IO uint8_t CSC_COEF_A1_MSB;                    /**< Color Space Converter Matrix A1 Coefficient Register MSB Notes: - The coefficients used in the CSC matrix use only 15 bits for the internal computations., offset: 0x2 */
  __IO uint8_t CSC_COEF_A1_LSB;                    /**< Color Space Converter Matrix A1 Coefficient Register LSB Notes: - The coefficients used in the CSC matrix use only 15 bits for the internal computations., offset: 0x3 */
  __IO uint8_t CSC_COEF_A2_MSB;                    /**< Color Space Converter Matrix A2 Coefficient Register MSB Color Space Conversion A2 coefficient., offset: 0x4 */
  __IO uint8_t CSC_COEF_A2_LSB;                    /**< Color Space Converter Matrix A2 Coefficient Register LSB Color Space Conversion A2 coefficient., offset: 0x5 */
  __IO uint8_t CSC_COEF_A3_MSB;                    /**< Color Space Converter Matrix A3 Coefficient Register MSB Color Space Conversion A3 coefficient., offset: 0x6 */
  __IO uint8_t CSC_COEF_A3_LSB;                    /**< Color Space Converter Matrix A3 Coefficient Register LSB Color Space Conversion A3 coefficient., offset: 0x7 */
  __IO uint8_t CSC_COEF_A4_MSB;                    /**< Color Space Converter Matrix A4 Coefficient Register MSB Color Space Conversion A4 coefficient., offset: 0x8 */
  __IO uint8_t CSC_COEF_A4_LSB;                    /**< Color Space Converter Matrix A4 Coefficient Register LSB Color Space Conversion A4 coefficient., offset: 0x9 */
  __IO uint8_t CSC_COEF_B1_MSB;                    /**< Color Space Converter Matrix B1 Coefficient Register MSB Color Space Conversion B1 coefficient., offset: 0xA */
  __IO uint8_t CSC_COEF_B1_LSB;                    /**< Color Space Converter Matrix B1 Coefficient Register LSB Color Space Conversion B1 coefficient., offset: 0xB */
  __IO uint8_t CSC_COEF_B2_MSB;                    /**< Color Space Converter Matrix B2 Coefficient Register MSB Color Space Conversion B2 coefficient., offset: 0xC */
  __IO uint8_t CSC_COEF_B2_LSB;                    /**< Color Space Converter Matrix B2 Coefficient Register LSB Color Space Conversion B2 coefficient., offset: 0xD */
  __IO uint8_t CSC_COEF_B3_MSB;                    /**< Color Space Converter Matrix B3 Coefficient Register MSB Color Space Conversion B3 coefficient., offset: 0xE */
  __IO uint8_t CSC_COEF_B3_LSB;                    /**< Color Space Converter Matrix B3 Coefficient Register LSB Color Space Conversion B3 coefficient., offset: 0xF */
  __IO uint8_t CSC_COEF_B4_MSB;                    /**< Color Space Converter Matrix B4 Coefficient Register MSB Color Space Conversion B4 coefficient., offset: 0x10 */
  __IO uint8_t CSC_COEF_B4_LSB;                    /**< Color Space Converter Matrix B4 Coefficient Register LSB Color Space Conversion B4 coefficient., offset: 0x11 */
  __IO uint8_t CSC_COEF_C1_MSB;                    /**< Color Space Converter Matrix C1 Coefficient Register MSB Color Space Conversion C1 coefficient., offset: 0x12 */
  __IO uint8_t CSC_COEF_C1_LSB;                    /**< Color Space Converter Matrix C1 Coefficient Register LSB Color Space Conversion C1 coefficient., offset: 0x13 */
  __IO uint8_t CSC_COEF_C2_MSB;                    /**< Color Space Converter Matrix C2 Coefficient Register MSB Color Space Conversion C2 coefficient., offset: 0x14 */
  __IO uint8_t CSC_COEF_C2_LSB;                    /**< Color Space Converter Matrix C2 Coefficient Register LSB Color Space Conversion C2 coefficient., offset: 0x15 */
  __IO uint8_t CSC_COEF_C3_MSB;                    /**< Color Space Converter Matrix C3 Coefficient Register MSB Color Space Conversion C3 coefficient., offset: 0x16 */
  __IO uint8_t CSC_COEF_C3_LSB;                    /**< Color Space Converter Matrix C3 Coefficient Register LSB Color Space Conversion C3 coefficient., offset: 0x17 */
  __IO uint8_t CSC_COEF_C4_MSB;                    /**< Color Space Converter Matrix C4 Coefficient Register MSB Color Space Conversion C4 coefficient., offset: 0x18 */
  __IO uint8_t CSC_COEF_C4_LSB;                    /**< Color Space Converter Matrix C4 Coefficient Register LSB Color Space Conversion C4 coefficient., offset: 0x19 */
  __IO uint8_t CSC_LIMIT_UP_MSB;                   /**< Color Space Converter Matrix Output Up Limit Register MSB For more details, refer to the HDMI 1., offset: 0x1A */
  __IO uint8_t CSC_LIMIT_UP_LSB;                   /**< Color Space Converter Matrix output Up Limit Register LSB For more details, refer to the HDMI 1., offset: 0x1B */
  __IO uint8_t CSC_LIMIT_DN_MSB;                   /**< Color Space Converter Matrix output Down Limit Register MSB For more details, refer to the HDMI 1., offset: 0x1C */
  __IO uint8_t CSC_LIMIT_DN_LSB;                   /**< Color Space Converter Matrix output Down Limit Register LSB For more details, refer to the HDMI 1., offset: 0x1D */
} COLORSPACECONVERTER_Type;

/* ----------------------------------------------------------------------------
   -- COLORSPACECONVERTER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COLORSPACECONVERTER_Register_Masks COLORSPACECONVERTER Register Masks
 * @{
 */

/*! @name CSC_CFG - Color Space Converter Interpolation and Decimation Configuration Register */
/*! @{ */

#define COLORSPACECONVERTER_CSC_CFG_DECMODE_MASK (0x3U)
#define COLORSPACECONVERTER_CSC_CFG_DECMODE_SHIFT (0U)
/*! decmode - Chroma decimation configuration: decmode[1:0] | Chroma Decimation 00 | decimation
 *    disabled 01 | Hd (z) =1 10 | Hd(z)=1/ 4 + 1/2z^(-1 )+1/4 z^(-2) 11 | Hd(z)x2^(11)= -5+12z^(-2) -
 *    22z^(-4)+39z^(-8) +109z^(-10) -204z^(-12)+648z^(-14) + 1024z^(-15) +648z^(-16) -204z^(-18)
 *    +109z^(-20)- 65z^(-22) +39z^(-24) -22z^(-26) +12z^(-28)-5z^(-30)
 */
#define COLORSPACECONVERTER_CSC_CFG_DECMODE(x)   (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_CFG_DECMODE_SHIFT)) & COLORSPACECONVERTER_CSC_CFG_DECMODE_MASK)

#define COLORSPACECONVERTER_CSC_CFG_SPARE_1_MASK (0xCU)
#define COLORSPACECONVERTER_CSC_CFG_SPARE_1_SHIFT (2U)
/*! spare_1 - Reserved as "spare" register with no associated functionality. */
#define COLORSPACECONVERTER_CSC_CFG_SPARE_1(x)   (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_CFG_SPARE_1_SHIFT)) & COLORSPACECONVERTER_CSC_CFG_SPARE_1_MASK)

#define COLORSPACECONVERTER_CSC_CFG_INTMODE_MASK (0x30U)
#define COLORSPACECONVERTER_CSC_CFG_INTMODE_SHIFT (4U)
/*! intmode - Chroma interpolation configuration: intmode[1:0] | Chroma Interpolation 00 |
 *    interpolation disabled 01 | Hu (z) =1 + z^(-1) 10 | Hu(z)=1/ 2 + z^(-11)+1/2 z^(-2) 11 | interpolation
 *    disabled
 */
#define COLORSPACECONVERTER_CSC_CFG_INTMODE(x)   (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_CFG_INTMODE_SHIFT)) & COLORSPACECONVERTER_CSC_CFG_INTMODE_MASK)

#define COLORSPACECONVERTER_CSC_CFG_SPARE_2_MASK (0x40U)
#define COLORSPACECONVERTER_CSC_CFG_SPARE_2_SHIFT (6U)
/*! spare_2 - Reserved as "spare" register with no associated functionality. */
#define COLORSPACECONVERTER_CSC_CFG_SPARE_2(x)   (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_CFG_SPARE_2_SHIFT)) & COLORSPACECONVERTER_CSC_CFG_SPARE_2_MASK)

#define COLORSPACECONVERTER_CSC_CFG_CSC_LIMIT_MASK (0x80U)
#define COLORSPACECONVERTER_CSC_CFG_CSC_LIMIT_SHIFT (7U)
/*! csc_limit - When set (1'b1), the range limitation values defined in registers csc_mat_uplim and
 *    csc_mat_dnlim are applied to the output of the Color Space Conversion matrix.
 */
#define COLORSPACECONVERTER_CSC_CFG_CSC_LIMIT(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_CFG_CSC_LIMIT_SHIFT)) & COLORSPACECONVERTER_CSC_CFG_CSC_LIMIT_MASK)
/*! @} */

/*! @name CSC_SCALE - Color Space Converter Scale and Deep Color Configuration Register */
/*! @{ */

#define COLORSPACECONVERTER_CSC_SCALE_CSCSCALE_MASK (0x3U)
#define COLORSPACECONVERTER_CSC_SCALE_CSCSCALE_SHIFT (0U)
/*! cscscale - Defines the cscscale[1:0] scale factor to apply to all coefficients in Color Space Conversion. */
#define COLORSPACECONVERTER_CSC_SCALE_CSCSCALE(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_SCALE_CSCSCALE_SHIFT)) & COLORSPACECONVERTER_CSC_SCALE_CSCSCALE_MASK)

#define COLORSPACECONVERTER_CSC_SCALE_SPARE_MASK (0xCU)
#define COLORSPACECONVERTER_CSC_SCALE_SPARE_SHIFT (2U)
/*! spare - The is a Reserved as "spare" register with no associated functionality. */
#define COLORSPACECONVERTER_CSC_SCALE_SPARE(x)   (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_SCALE_SPARE_SHIFT)) & COLORSPACECONVERTER_CSC_SCALE_SPARE_MASK)

#define COLORSPACECONVERTER_CSC_SCALE_CSC_COLOR_DEPTH_MASK (0xF0U)
#define COLORSPACECONVERTER_CSC_SCALE_CSC_COLOR_DEPTH_SHIFT (4U)
/*! csc_color_depth - Color space converter color depth configuration: csc_colordepth[3:0] | Action
 *    0000 | 24 bit per pixel video (8 bit per component).
 */
#define COLORSPACECONVERTER_CSC_SCALE_CSC_COLOR_DEPTH(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_SCALE_CSC_COLOR_DEPTH_SHIFT)) & COLORSPACECONVERTER_CSC_SCALE_CSC_COLOR_DEPTH_MASK)
/*! @} */

/*! @name CSC_COEF_A1_MSB - Color Space Converter Matrix A1 Coefficient Register MSB Notes: - The coefficients used in the CSC matrix use only 15 bits for the internal computations. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB_SHIFT (0U)
/*! csc_coef_a1_msb - Color Space Converter Matrix A1 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_A1_MSB_CSC_COEF_A1_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_A1_LSB - Color Space Converter Matrix A1 Coefficient Register LSB Notes: - The coefficients used in the CSC matrix use only 15 bits for the internal computations. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB_SHIFT (0U)
/*! csc_coef_a1_lsb - Color Space Converter Matrix A1 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_A1_LSB_CSC_COEF_A1_LSB_MASK)
/*! @} */

/*! @name CSC_COEF_A2_MSB - Color Space Converter Matrix A2 Coefficient Register MSB Color Space Conversion A2 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB_SHIFT (0U)
/*! csc_coef_a2_msb - Color Space Converter Matrix A2 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_A2_MSB_CSC_COEF_A2_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_A2_LSB - Color Space Converter Matrix A2 Coefficient Register LSB Color Space Conversion A2 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB_SHIFT (0U)
/*! csc_coef_a2_lsb - Color Space Converter Matrix A2 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_A2_LSB_CSC_COEF_A2_LSB_MASK)
/*! @} */

/*! @name CSC_COEF_A3_MSB - Color Space Converter Matrix A3 Coefficient Register MSB Color Space Conversion A3 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB_SHIFT (0U)
/*! csc_coef_a3_msb - Color Space Converter Matrix A3 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_A3_MSB_CSC_COEF_A3_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_A3_LSB - Color Space Converter Matrix A3 Coefficient Register LSB Color Space Conversion A3 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB_SHIFT (0U)
/*! csc_coef_a3_lsb - Color Space Converter Matrix A3 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_A3_LSB_CSC_COEF_A3_LSB_MASK)
/*! @} */

/*! @name CSC_COEF_A4_MSB - Color Space Converter Matrix A4 Coefficient Register MSB Color Space Conversion A4 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB_SHIFT (0U)
/*! csc_coef_a4_msb - Color Space Converter Matrix A4 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_A4_MSB_CSC_COEF_A4_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_A4_LSB - Color Space Converter Matrix A4 Coefficient Register LSB Color Space Conversion A4 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB_SHIFT (0U)
/*! csc_coef_a4_lsb - Color Space Converter Matrix A4 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_A4_LSB_CSC_COEF_A4_LSB_MASK)
/*! @} */

/*! @name CSC_COEF_B1_MSB - Color Space Converter Matrix B1 Coefficient Register MSB Color Space Conversion B1 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB_SHIFT (0U)
/*! csc_coef_b1_msb - Color Space Converter Matrix B1 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_B1_MSB_CSC_COEF_B1_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_B1_LSB - Color Space Converter Matrix B1 Coefficient Register LSB Color Space Conversion B1 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB_SHIFT (0U)
/*! csc_coef_b1_lsb - Color Space Converter Matrix B1 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_B1_LSB_CSC_COEF_B1_LSB_MASK)
/*! @} */

/*! @name CSC_COEF_B2_MSB - Color Space Converter Matrix B2 Coefficient Register MSB Color Space Conversion B2 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB_SHIFT (0U)
/*! csc_coef_b2_msb - Color Space Converter Matrix B2 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_B2_MSB_CSC_COEF_B2_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_B2_LSB - Color Space Converter Matrix B2 Coefficient Register LSB Color Space Conversion B2 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB_SHIFT (0U)
/*! csc_coef_b2_lsb - Color Space Converter Matrix B2 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_B2_LSB_CSC_COEF_B2_LSB_MASK)
/*! @} */

/*! @name CSC_COEF_B3_MSB - Color Space Converter Matrix B3 Coefficient Register MSB Color Space Conversion B3 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB_SHIFT (0U)
/*! csc_coef_b3_msb - Color Space Converter Matrix B3 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_B3_MSB_CSC_COEF_B3_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_B3_LSB - Color Space Converter Matrix B3 Coefficient Register LSB Color Space Conversion B3 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB_SHIFT (0U)
/*! csc_coef_b3_lsb - Color Space Converter Matrix B3 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_B3_LSB_CSC_COEF_B3_LSB_MASK)
/*! @} */

/*! @name CSC_COEF_B4_MSB - Color Space Converter Matrix B4 Coefficient Register MSB Color Space Conversion B4 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB_SHIFT (0U)
/*! csc_coef_b4_msb - Color Space Converter Matrix B4 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_B4_MSB_CSC_COEF_B4_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_B4_LSB - Color Space Converter Matrix B4 Coefficient Register LSB Color Space Conversion B4 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB_SHIFT (0U)
/*! csc_coef_b4_lsb - Color Space Converter Matrix B4 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_B4_LSB_CSC_COEF_B4_LSB_MASK)
/*! @} */

/*! @name CSC_COEF_C1_MSB - Color Space Converter Matrix C1 Coefficient Register MSB Color Space Conversion C1 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB_SHIFT (0U)
/*! csc_coef_c1_msb - Color Space Converter Matrix C1 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_C1_MSB_CSC_COEF_C1_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_C1_LSB - Color Space Converter Matrix C1 Coefficient Register LSB Color Space Conversion C1 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB_SHIFT (0U)
/*! csc_coef_c1_lsb - Color Space Converter Matrix C1 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_C1_LSB_CSC_COEF_C1_LSB_MASK)
/*! @} */

/*! @name CSC_COEF_C2_MSB - Color Space Converter Matrix C2 Coefficient Register MSB Color Space Conversion C2 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB_SHIFT (0U)
/*! csc_coef_c2_msb - Color Space Converter Matrix C2 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_C2_MSB_CSC_COEF_C2_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_C2_LSB - Color Space Converter Matrix C2 Coefficient Register LSB Color Space Conversion C2 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB_SHIFT (0U)
/*! csc_coef_c2_lsb - Color Space Converter Matrix C2 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_C2_LSB_CSC_COEF_C2_LSB_MASK)
/*! @} */

/*! @name CSC_COEF_C3_MSB - Color Space Converter Matrix C3 Coefficient Register MSB Color Space Conversion C3 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB_SHIFT (0U)
/*! csc_coef_c3_msb - Color Space Converter Matrix C3 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_C3_MSB_CSC_COEF_C3_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_C3_LSB - Color Space Converter Matrix C3 Coefficient Register LSB Color Space Conversion C3 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB_SHIFT (0U)
/*! csc_coef_c3_lsb - Color Space Converter Matrix C3 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_C3_LSB_CSC_COEF_C3_LSB_MASK)
/*! @} */

/*! @name CSC_COEF_C4_MSB - Color Space Converter Matrix C4 Coefficient Register MSB Color Space Conversion C4 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_C4_MSB_CSC_COEF_C4_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_C4_MSB_CSC_COEF_C4_MSB_SHIFT (0U)
/*! csc_coef_c4_msb - Color Space Converter Matrix C4 Coefficient Register MSB */
#define COLORSPACECONVERTER_CSC_COEF_C4_MSB_CSC_COEF_C4_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_C4_MSB_CSC_COEF_C4_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_C4_MSB_CSC_COEF_C4_MSB_MASK)
/*! @} */

/*! @name CSC_COEF_C4_LSB - Color Space Converter Matrix C4 Coefficient Register LSB Color Space Conversion C4 coefficient. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_COEF_C4_LSB_CSC_COEF_C4_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_COEF_C4_LSB_CSC_COEF_C4_LSB_SHIFT (0U)
/*! csc_coef_c4_lsb - Color Space Converter Matrix C4 Coefficient Register LSB */
#define COLORSPACECONVERTER_CSC_COEF_C4_LSB_CSC_COEF_C4_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_COEF_C4_LSB_CSC_COEF_C4_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_COEF_C4_LSB_CSC_COEF_C4_LSB_MASK)
/*! @} */

/*! @name CSC_LIMIT_UP_MSB - Color Space Converter Matrix Output Up Limit Register MSB For more details, refer to the HDMI 1. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_LIMIT_UP_MSB_CSC_LIMIT_UP_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_LIMIT_UP_MSB_CSC_LIMIT_UP_MSB_SHIFT (0U)
/*! csc_limit_up_msb - Color Space Converter Matrix Output Upper Limit Register MSB */
#define COLORSPACECONVERTER_CSC_LIMIT_UP_MSB_CSC_LIMIT_UP_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_LIMIT_UP_MSB_CSC_LIMIT_UP_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_LIMIT_UP_MSB_CSC_LIMIT_UP_MSB_MASK)
/*! @} */

/*! @name CSC_LIMIT_UP_LSB - Color Space Converter Matrix output Up Limit Register LSB For more details, refer to the HDMI 1. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_LIMIT_UP_LSB_CSC_LIMIT_UP_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_LIMIT_UP_LSB_CSC_LIMIT_UP_LSB_SHIFT (0U)
/*! csc_limit_up_lsb - Color Space Converter Matrix Output Upper Limit Register LSB */
#define COLORSPACECONVERTER_CSC_LIMIT_UP_LSB_CSC_LIMIT_UP_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_LIMIT_UP_LSB_CSC_LIMIT_UP_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_LIMIT_UP_LSB_CSC_LIMIT_UP_LSB_MASK)
/*! @} */

/*! @name CSC_LIMIT_DN_MSB - Color Space Converter Matrix output Down Limit Register MSB For more details, refer to the HDMI 1. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_LIMIT_DN_MSB_CSC_LIMIT_DN_MSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_LIMIT_DN_MSB_CSC_LIMIT_DN_MSB_SHIFT (0U)
/*! csc_limit_dn_msb - Color Space Converter Matrix output Down Limit Register MSB */
#define COLORSPACECONVERTER_CSC_LIMIT_DN_MSB_CSC_LIMIT_DN_MSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_LIMIT_DN_MSB_CSC_LIMIT_DN_MSB_SHIFT)) & COLORSPACECONVERTER_CSC_LIMIT_DN_MSB_CSC_LIMIT_DN_MSB_MASK)
/*! @} */

/*! @name CSC_LIMIT_DN_LSB - Color Space Converter Matrix output Down Limit Register LSB For more details, refer to the HDMI 1. */
/*! @{ */

#define COLORSPACECONVERTER_CSC_LIMIT_DN_LSB_CSC_LIMIT_DN_LSB_MASK (0xFFU)
#define COLORSPACECONVERTER_CSC_LIMIT_DN_LSB_CSC_LIMIT_DN_LSB_SHIFT (0U)
/*! csc_limit_dn_lsb - Color Space Converter Matrix Output Down Limit Register LSB */
#define COLORSPACECONVERTER_CSC_LIMIT_DN_LSB_CSC_LIMIT_DN_LSB(x) (((uint8_t)(((uint8_t)(x)) << COLORSPACECONVERTER_CSC_LIMIT_DN_LSB_CSC_LIMIT_DN_LSB_SHIFT)) & COLORSPACECONVERTER_CSC_LIMIT_DN_LSB_CSC_LIMIT_DN_LSB_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group COLORSPACECONVERTER_Register_Masks */


/*!
 * @}
 */ /* end of group COLORSPACECONVERTER_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_COLORSPACECONVERTER_H_ */

