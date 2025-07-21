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
**         CMSIS Peripheral Access Layer for AUDIOPACKETIZER
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
 * @file PERI_AUDIOPACKETIZER.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AUDIOPACKETIZER
 *
 * CMSIS Peripheral Access Layer for AUDIOPACKETIZER
 */

#if !defined(PERI_AUDIOPACKETIZER_H_)
#define PERI_AUDIOPACKETIZER_H_                  /**< Symbol preventing repeated inclusion */

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
   -- AUDIOPACKETIZER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AUDIOPACKETIZER_Peripheral_Access_Layer AUDIOPACKETIZER Peripheral Access Layer
 * @{
 */

/** AUDIOPACKETIZER - Register Layout Typedef */
typedef struct {
  __IO uint8_t AUD_N1;                             /**< Audio Clock Regenerator N Value Register 1 For N expected values, refer to the HDMI 1., offset: 0x0 */
  __IO uint8_t AUD_N2;                             /**< Audio Clock Regenerator N Value Register 2 For N expected values, refer to the HDMI 1., offset: 0x1 */
  __IO uint8_t AUD_N3;                             /**< Audio Clock Regenerator N Value Register 3 For N expected values, refer to the HDMI 1., offset: 0x2 */
  __IO uint8_t AUD_CTS1;                           /**< Audio Clock Regenerator CTS Value Register 1 For CTS expected values, refer to the HDMI 1., offset: 0x3 */
  __IO uint8_t AUD_CTS2;                           /**< Audio Clock Regenerator CTS Register 2 For CTS expected values, refer to the HDMI 1., offset: 0x4 */
  __IO uint8_t AUD_CTS3;                           /**< Audio Clock Regenerator CTS value Register 3., offset: 0x5 */
       uint8_t AUD_INPUTCLKFS;                     /**< Audio Input Clock FS Factor Register, offset: 0x6 */
  __IO uint8_t AUD_CTS_DITHER;                     /**< Audio CTS Dither Register, offset: 0x7 */
} AUDIOPACKETIZER_Type;

/* ----------------------------------------------------------------------------
   -- AUDIOPACKETIZER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AUDIOPACKETIZER_Register_Masks AUDIOPACKETIZER Register Masks
 * @{
 */

/*! @name AUD_N1 - Audio Clock Regenerator N Value Register 1 For N expected values, refer to the HDMI 1. */
/*! @{ */

#define AUDIOPACKETIZER_AUD_N1_AUDN_MASK         (0xFFU)
#define AUDIOPACKETIZER_AUD_N1_AUDN_SHIFT        (0U)
/*! AudN - HDMI Audio Clock Regenerator N value */
#define AUDIOPACKETIZER_AUD_N1_AUDN(x)           (((uint8_t)(((uint8_t)(x)) << AUDIOPACKETIZER_AUD_N1_AUDN_SHIFT)) & AUDIOPACKETIZER_AUD_N1_AUDN_MASK)
/*! @} */

/*! @name AUD_N2 - Audio Clock Regenerator N Value Register 2 For N expected values, refer to the HDMI 1. */
/*! @{ */

#define AUDIOPACKETIZER_AUD_N2_AUDN_MASK         (0xFFU)
#define AUDIOPACKETIZER_AUD_N2_AUDN_SHIFT        (0U)
/*! AudN - HDMI Audio Clock Regenerator N value */
#define AUDIOPACKETIZER_AUD_N2_AUDN(x)           (((uint8_t)(((uint8_t)(x)) << AUDIOPACKETIZER_AUD_N2_AUDN_SHIFT)) & AUDIOPACKETIZER_AUD_N2_AUDN_MASK)
/*! @} */

/*! @name AUD_N3 - Audio Clock Regenerator N Value Register 3 For N expected values, refer to the HDMI 1. */
/*! @{ */

#define AUDIOPACKETIZER_AUD_N3_AUDN_MASK         (0xFU)
#define AUDIOPACKETIZER_AUD_N3_AUDN_SHIFT        (0U)
/*! AudN - HDMI Audio Clock Regenerator N value */
#define AUDIOPACKETIZER_AUD_N3_AUDN(x)           (((uint8_t)(((uint8_t)(x)) << AUDIOPACKETIZER_AUD_N3_AUDN_SHIFT)) & AUDIOPACKETIZER_AUD_N3_AUDN_MASK)

#define AUDIOPACKETIZER_AUD_N3_NCTS_ATOMIC_WRITE_MASK (0x80U)
#define AUDIOPACKETIZER_AUD_N3_NCTS_ATOMIC_WRITE_SHIFT (7U)
/*! ncts_atomic_write - When set, the new N and CTS values are only used when aud_n1 register is written. */
#define AUDIOPACKETIZER_AUD_N3_NCTS_ATOMIC_WRITE(x) (((uint8_t)(((uint8_t)(x)) << AUDIOPACKETIZER_AUD_N3_NCTS_ATOMIC_WRITE_SHIFT)) & AUDIOPACKETIZER_AUD_N3_NCTS_ATOMIC_WRITE_MASK)
/*! @} */

/*! @name AUD_CTS1 - Audio Clock Regenerator CTS Value Register 1 For CTS expected values, refer to the HDMI 1. */
/*! @{ */

#define AUDIOPACKETIZER_AUD_CTS1_AUDCTS_MASK     (0xFFU)
#define AUDIOPACKETIZER_AUD_CTS1_AUDCTS_SHIFT    (0U)
/*! AudCTS - HDMI Audio Clock Regenerator CTS calculated value. */
#define AUDIOPACKETIZER_AUD_CTS1_AUDCTS(x)       (((uint8_t)(((uint8_t)(x)) << AUDIOPACKETIZER_AUD_CTS1_AUDCTS_SHIFT)) & AUDIOPACKETIZER_AUD_CTS1_AUDCTS_MASK)
/*! @} */

/*! @name AUD_CTS2 - Audio Clock Regenerator CTS Register 2 For CTS expected values, refer to the HDMI 1. */
/*! @{ */

#define AUDIOPACKETIZER_AUD_CTS2_AUDCTS_MASK     (0xFFU)
#define AUDIOPACKETIZER_AUD_CTS2_AUDCTS_SHIFT    (0U)
/*! AudCTS - HDMI Audio Clock Regenerator CTS calculated value. */
#define AUDIOPACKETIZER_AUD_CTS2_AUDCTS(x)       (((uint8_t)(((uint8_t)(x)) << AUDIOPACKETIZER_AUD_CTS2_AUDCTS_SHIFT)) & AUDIOPACKETIZER_AUD_CTS2_AUDCTS_MASK)
/*! @} */

/*! @name AUD_CTS3 - Audio Clock Regenerator CTS value Register 3. */
/*! @{ */

#define AUDIOPACKETIZER_AUD_CTS3_AUDCTS_MASK     (0xFU)
#define AUDIOPACKETIZER_AUD_CTS3_AUDCTS_SHIFT    (0U)
/*! AudCTS - HDMI Audio Clock Regenerator CTS calculated value. */
#define AUDIOPACKETIZER_AUD_CTS3_AUDCTS(x)       (((uint8_t)(((uint8_t)(x)) << AUDIOPACKETIZER_AUD_CTS3_AUDCTS_SHIFT)) & AUDIOPACKETIZER_AUD_CTS3_AUDCTS_MASK)

#define AUDIOPACKETIZER_AUD_CTS3_CTS_MANUAL_MASK (0x10U)
#define AUDIOPACKETIZER_AUD_CTS3_CTS_MANUAL_SHIFT (4U)
/*! CTS_manual - If the CTS_manual bit equals 0b, this registers contains audCTS[19:0] generated by
 *    the Cycle time counter according to the specified timing.
 */
#define AUDIOPACKETIZER_AUD_CTS3_CTS_MANUAL(x)   (((uint8_t)(((uint8_t)(x)) << AUDIOPACKETIZER_AUD_CTS3_CTS_MANUAL_SHIFT)) & AUDIOPACKETIZER_AUD_CTS3_CTS_MANUAL_MASK)

#define AUDIOPACKETIZER_AUD_CTS3_SPARE_MASK      (0xE0U)
#define AUDIOPACKETIZER_AUD_CTS3_SPARE_SHIFT     (5U)
/*! spare - Reserved as "spare" bit with no associated functionality. */
#define AUDIOPACKETIZER_AUD_CTS3_SPARE(x)        (((uint8_t)(((uint8_t)(x)) << AUDIOPACKETIZER_AUD_CTS3_SPARE_SHIFT)) & AUDIOPACKETIZER_AUD_CTS3_SPARE_MASK)
/*! @} */

/*! @name AUD_CTS_DITHER - Audio CTS Dither Register */
/*! @{ */

#define AUDIOPACKETIZER_AUD_CTS_DITHER_DIVISOR_MASK (0xFU)
#define AUDIOPACKETIZER_AUD_CTS_DITHER_DIVISOR_SHIFT (0U)
/*! divisor - Dither divisor (4'd1 if no CTS Dither) This field should be configured with the value
 *    of divisor from the HDMI specification.
 */
#define AUDIOPACKETIZER_AUD_CTS_DITHER_DIVISOR(x) (((uint8_t)(((uint8_t)(x)) << AUDIOPACKETIZER_AUD_CTS_DITHER_DIVISOR_SHIFT)) & AUDIOPACKETIZER_AUD_CTS_DITHER_DIVISOR_MASK)

#define AUDIOPACKETIZER_AUD_CTS_DITHER_DIVIDEND_MASK (0xF0U)
#define AUDIOPACKETIZER_AUD_CTS_DITHER_DIVIDEND_SHIFT (4U)
/*! dividend - Dither dividend (4'd1 if no CTS Dither) This field should be configured with the
 *    value of dividend from the HDMI specification.
 */
#define AUDIOPACKETIZER_AUD_CTS_DITHER_DIVIDEND(x) (((uint8_t)(((uint8_t)(x)) << AUDIOPACKETIZER_AUD_CTS_DITHER_DIVIDEND_SHIFT)) & AUDIOPACKETIZER_AUD_CTS_DITHER_DIVIDEND_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AUDIOPACKETIZER_Register_Masks */


/*!
 * @}
 */ /* end of group AUDIOPACKETIZER_Peripheral_Access_Layer */


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


#endif  /* PERI_AUDIOPACKETIZER_H_ */

