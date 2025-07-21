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
**         CMSIS Peripheral Access Layer for VIDEOSAMPLER
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
 * @file PERI_VIDEOSAMPLER.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VIDEOSAMPLER
 *
 * CMSIS Peripheral Access Layer for VIDEOSAMPLER
 */

#if !defined(PERI_VIDEOSAMPLER_H_)
#define PERI_VIDEOSAMPLER_H_                     /**< Symbol preventing repeated inclusion */

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
   -- VIDEOSAMPLER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIDEOSAMPLER_Peripheral_Access_Layer VIDEOSAMPLER Peripheral Access Layer
 * @{
 */

/** VIDEOSAMPLER - Register Layout Typedef */
typedef struct {
  __IO uint8_t TX_INVID0;                          /**< Video Input Mapping and Internal Data Enable Configuration Register, offset: 0x0 */
  __IO uint8_t TX_INSTUFFING;                      /**< Video Input Stuffing Enable Register, offset: 0x1 */
  __IO uint8_t TX_GYDATA0;                         /**< Video Input gy Data Channel Stuffing Register 0, offset: 0x2 */
  __IO uint8_t TX_GYDATA1;                         /**< Video Input gy Data Channel Stuffing Register 1, offset: 0x3 */
  __IO uint8_t TX_RCRDATA0;                        /**< Video Input rcr Data Channel Stuffing Register 0, offset: 0x4 */
  __IO uint8_t TX_RCRDATA1;                        /**< Video Input rcr Data Channel Stuffing Register 1, offset: 0x5 */
  __IO uint8_t TX_BCBDATA0;                        /**< Video Input bcb Data Channel Stuffing Register 0, offset: 0x6 */
  __IO uint8_t TX_BCBDATA1;                        /**< Video Input bcb Data Channel Stuffing Register 1, offset: 0x7 */
} VIDEOSAMPLER_Type;

/* ----------------------------------------------------------------------------
   -- VIDEOSAMPLER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIDEOSAMPLER_Register_Masks VIDEOSAMPLER Register Masks
 * @{
 */

/*! @name TX_INVID0 - Video Input Mapping and Internal Data Enable Configuration Register */
/*! @{ */

#define VIDEOSAMPLER_TX_INVID0_VIDEO_MAPPING_MASK (0x1FU)
#define VIDEOSAMPLER_TX_INVID0_VIDEO_MAPPING_SHIFT (0U)
/*! video_mapping - Video Input mapping (color space/color depth): 0x01: RGB 4:4:4/8 bits 0x03: RGB
 *    4:4:4/10 bits 0x05: RGB 4:4:4/12 bits 0x07: RGB 4:4:4/16 bits 0x09: YCbCr 4:4:4 or 4:2:0/8
 *    bits 0x0B: YCbCr 4:4:4 or 4:2:0/10 bits 0x0D: YCbCr 4:4:4 or 4:2:0/12 bits 0x0F: YCbCr 4:4:4 or
 *    4:2:0/16 bits 0x16: YCbCr 4:2:2/8 bits 0x14: YCbCr 4:2:2/10 bits 0x12: YCbCr 4:2:2/12 bits
 *    0x17: YCbCr 4:4:4 (IPI)/8 bits 0x18: YCbCr 4:4:4 (IPI)/10 bits 0x19: YCbCr 4:4:4 (IPI)/12 bits
 *    0x1A: YCbCr 4:4:4 (IPI)/16 bits 0x1B: YCbCr 4:2:2 (IPI)/12 bits 0x1C: YCbCr 4:2:0 (IPI)/8 bits
 *    0x1D: YCbCr 4:2:0 (IPI)/10 bits 0x1E: YCbCr 4:2:0 (IPI)/12 bits 0x1F: YCbCr 4:2:0 (IPI)/16 bits
 *    Note: IPI means Image Pixel Interface and it is a proprietary interface used on SNPS MIPI
 *    Controllers.
 */
#define VIDEOSAMPLER_TX_INVID0_VIDEO_MAPPING(x)  (((uint8_t)(((uint8_t)(x)) << VIDEOSAMPLER_TX_INVID0_VIDEO_MAPPING_SHIFT)) & VIDEOSAMPLER_TX_INVID0_VIDEO_MAPPING_MASK)

#define VIDEOSAMPLER_TX_INVID0_INTERNAL_DE_GENERATOR_MASK (0x80U)
#define VIDEOSAMPLER_TX_INVID0_INTERNAL_DE_GENERATOR_SHIFT (7U)
/*! internal_de_generator - Internal data enable (DE) generator enable. */
#define VIDEOSAMPLER_TX_INVID0_INTERNAL_DE_GENERATOR(x) (((uint8_t)(((uint8_t)(x)) << VIDEOSAMPLER_TX_INVID0_INTERNAL_DE_GENERATOR_SHIFT)) & VIDEOSAMPLER_TX_INVID0_INTERNAL_DE_GENERATOR_MASK)
/*! @} */

/*! @name TX_INSTUFFING - Video Input Stuffing Enable Register */
/*! @{ */

#define VIDEOSAMPLER_TX_INSTUFFING_GYDATA_STUFFING_MASK (0x1U)
#define VIDEOSAMPLER_TX_INSTUFFING_GYDATA_STUFFING_SHIFT (0U)
/*! gydata_stuffing - - 0b: When the dataen signal is low, the value in the gydata[15:0] output is
 *    the one sampled from the corresponding input data.
 */
#define VIDEOSAMPLER_TX_INSTUFFING_GYDATA_STUFFING(x) (((uint8_t)(((uint8_t)(x)) << VIDEOSAMPLER_TX_INSTUFFING_GYDATA_STUFFING_SHIFT)) & VIDEOSAMPLER_TX_INSTUFFING_GYDATA_STUFFING_MASK)

#define VIDEOSAMPLER_TX_INSTUFFING_RCRDATA_STUFFING_MASK (0x2U)
#define VIDEOSAMPLER_TX_INSTUFFING_RCRDATA_STUFFING_SHIFT (1U)
/*! rcrdata_stuffing - - 0b: When the dataen signal is low, the value in the rcrdata[15:0] output is
 *    the one sampled from the corresponding input data.
 */
#define VIDEOSAMPLER_TX_INSTUFFING_RCRDATA_STUFFING(x) (((uint8_t)(((uint8_t)(x)) << VIDEOSAMPLER_TX_INSTUFFING_RCRDATA_STUFFING_SHIFT)) & VIDEOSAMPLER_TX_INSTUFFING_RCRDATA_STUFFING_MASK)

#define VIDEOSAMPLER_TX_INSTUFFING_BCBDATA_STUFFING_MASK (0x4U)
#define VIDEOSAMPLER_TX_INSTUFFING_BCBDATA_STUFFING_SHIFT (2U)
/*! bcbdata_stuffing - - 0b: When the dataen signal is low, the value in the bcbdata[15:0] output is
 *    the one sampled from the corresponding input data.
 */
#define VIDEOSAMPLER_TX_INSTUFFING_BCBDATA_STUFFING(x) (((uint8_t)(((uint8_t)(x)) << VIDEOSAMPLER_TX_INSTUFFING_BCBDATA_STUFFING_SHIFT)) & VIDEOSAMPLER_TX_INSTUFFING_BCBDATA_STUFFING_MASK)
/*! @} */

/*! @name TX_GYDATA0 - Video Input gy Data Channel Stuffing Register 0 */
/*! @{ */

#define VIDEOSAMPLER_TX_GYDATA0_GYDATA_MASK      (0xFFU)
#define VIDEOSAMPLER_TX_GYDATA0_GYDATA_SHIFT     (0U)
/*! gydata - This register defines the value of gydata[7:0] when TX_INSTUFFING[0] (gydata_stuffing) is set to 1b. */
#define VIDEOSAMPLER_TX_GYDATA0_GYDATA(x)        (((uint8_t)(((uint8_t)(x)) << VIDEOSAMPLER_TX_GYDATA0_GYDATA_SHIFT)) & VIDEOSAMPLER_TX_GYDATA0_GYDATA_MASK)
/*! @} */

/*! @name TX_GYDATA1 - Video Input gy Data Channel Stuffing Register 1 */
/*! @{ */

#define VIDEOSAMPLER_TX_GYDATA1_GYDATA_MASK      (0xFFU)
#define VIDEOSAMPLER_TX_GYDATA1_GYDATA_SHIFT     (0U)
/*! gydata - This register defines the value of gydata[15:8] when TX_INSTUFFING[0] (gydata_stuffing) is set to 1b. */
#define VIDEOSAMPLER_TX_GYDATA1_GYDATA(x)        (((uint8_t)(((uint8_t)(x)) << VIDEOSAMPLER_TX_GYDATA1_GYDATA_SHIFT)) & VIDEOSAMPLER_TX_GYDATA1_GYDATA_MASK)
/*! @} */

/*! @name TX_RCRDATA0 - Video Input rcr Data Channel Stuffing Register 0 */
/*! @{ */

#define VIDEOSAMPLER_TX_RCRDATA0_RCRDATA_MASK    (0xFFU)
#define VIDEOSAMPLER_TX_RCRDATA0_RCRDATA_SHIFT   (0U)
/*! rcrdata - This register defines the value of rcrydata[7:0] when TX_INSTUFFING[1] (rcrdata_stuffing) is set to 1b. */
#define VIDEOSAMPLER_TX_RCRDATA0_RCRDATA(x)      (((uint8_t)(((uint8_t)(x)) << VIDEOSAMPLER_TX_RCRDATA0_RCRDATA_SHIFT)) & VIDEOSAMPLER_TX_RCRDATA0_RCRDATA_MASK)
/*! @} */

/*! @name TX_RCRDATA1 - Video Input rcr Data Channel Stuffing Register 1 */
/*! @{ */

#define VIDEOSAMPLER_TX_RCRDATA1_RCRDATA_MASK    (0xFFU)
#define VIDEOSAMPLER_TX_RCRDATA1_RCRDATA_SHIFT   (0U)
/*! rcrdata - This register defines the value of rcrydata[15:8] when TX_INSTUFFING[1] (rcrdata_stuffing) is set to 1b. */
#define VIDEOSAMPLER_TX_RCRDATA1_RCRDATA(x)      (((uint8_t)(((uint8_t)(x)) << VIDEOSAMPLER_TX_RCRDATA1_RCRDATA_SHIFT)) & VIDEOSAMPLER_TX_RCRDATA1_RCRDATA_MASK)
/*! @} */

/*! @name TX_BCBDATA0 - Video Input bcb Data Channel Stuffing Register 0 */
/*! @{ */

#define VIDEOSAMPLER_TX_BCBDATA0_BCBDATA_MASK    (0xFFU)
#define VIDEOSAMPLER_TX_BCBDATA0_BCBDATA_SHIFT   (0U)
/*! bcbdata - This register defines the value of bcbdata[7:0] when TX_INSTUFFING[2] (bcbdata_stuffing) is set to 1b. */
#define VIDEOSAMPLER_TX_BCBDATA0_BCBDATA(x)      (((uint8_t)(((uint8_t)(x)) << VIDEOSAMPLER_TX_BCBDATA0_BCBDATA_SHIFT)) & VIDEOSAMPLER_TX_BCBDATA0_BCBDATA_MASK)
/*! @} */

/*! @name TX_BCBDATA1 - Video Input bcb Data Channel Stuffing Register 1 */
/*! @{ */

#define VIDEOSAMPLER_TX_BCBDATA1_BCBDATA_MASK    (0xFFU)
#define VIDEOSAMPLER_TX_BCBDATA1_BCBDATA_SHIFT   (0U)
/*! bcbdata - This register defines the value of bcbdata[15:8] when TX_INSTUFFING[2] (bcbdata_stuffing) is set to 1b. */
#define VIDEOSAMPLER_TX_BCBDATA1_BCBDATA(x)      (((uint8_t)(((uint8_t)(x)) << VIDEOSAMPLER_TX_BCBDATA1_BCBDATA_SHIFT)) & VIDEOSAMPLER_TX_BCBDATA1_BCBDATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VIDEOSAMPLER_Register_Masks */


/*!
 * @}
 */ /* end of group VIDEOSAMPLER_Peripheral_Access_Layer */


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


#endif  /* PERI_VIDEOSAMPLER_H_ */

