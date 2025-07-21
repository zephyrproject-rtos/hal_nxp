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
**         CMSIS Peripheral Access Layer for AUDIOSAMPLEGP
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
 * @file PERI_AUDIOSAMPLEGP.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AUDIOSAMPLEGP
 *
 * CMSIS Peripheral Access Layer for AUDIOSAMPLEGP
 */

#if !defined(PERI_AUDIOSAMPLEGP_H_)
#define PERI_AUDIOSAMPLEGP_H_                    /**< Symbol preventing repeated inclusion */

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
   -- AUDIOSAMPLEGP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AUDIOSAMPLEGP_Peripheral_Access_Layer AUDIOSAMPLEGP Peripheral Access Layer
 * @{
 */

/** AUDIOSAMPLEGP - Register Layout Typedef */
typedef struct {
  __IO uint8_t GP_CONF0;                           /**< Audio GPA Software FIFO Reset Control Register 0, offset: 0x0 */
  __IO uint8_t GP_CONF1;                           /**< Audio GPA Channel Enable Configuration Register 1, offset: 0x1 */
  __IO uint8_t GP_CONF2;                           /**< Audio GPA HBR Enable Register 2, offset: 0x2 */
       uint8_t RESERVED_0[3];
  __IO uint8_t GP_MASK;                            /**< Audio GPA FIFO Full and Empty Mask Interrupt Register, offset: 0x6 */
} AUDIOSAMPLEGP_Type;

/* ----------------------------------------------------------------------------
   -- AUDIOSAMPLEGP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AUDIOSAMPLEGP_Register_Masks AUDIOSAMPLEGP Register Masks
 * @{
 */

/*! @name GP_CONF0 - Audio GPA Software FIFO Reset Control Register 0 */
/*! @{ */

#define AUDIOSAMPLEGP_GP_CONF0_SW_AUDIO_FIFO_RST_MASK (0x1U)
#define AUDIOSAMPLEGP_GP_CONF0_SW_AUDIO_FIFO_RST_SHIFT (0U)
/*! sw_audio_fifo_rst - Audio FIFOs software reset - Writing 0b: no action taken - Writing 1b:
 *    Resets all audio FIFOs Reading from this register always returns 0b.
 */
#define AUDIOSAMPLEGP_GP_CONF0_SW_AUDIO_FIFO_RST(x) (((uint8_t)(((uint8_t)(x)) << AUDIOSAMPLEGP_GP_CONF0_SW_AUDIO_FIFO_RST_SHIFT)) & AUDIOSAMPLEGP_GP_CONF0_SW_AUDIO_FIFO_RST_MASK)
/*! @} */

/*! @name GP_CONF1 - Audio GPA Channel Enable Configuration Register 1 */
/*! @{ */

#define AUDIOSAMPLEGP_GP_CONF1_CH_IN_EN_MASK     (0xFFU)
#define AUDIOSAMPLEGP_GP_CONF1_CH_IN_EN_SHIFT    (0U)
/*! ch_in_en - Each bit controls the enabling of the respective audio channel. */
#define AUDIOSAMPLEGP_GP_CONF1_CH_IN_EN(x)       (((uint8_t)(((uint8_t)(x)) << AUDIOSAMPLEGP_GP_CONF1_CH_IN_EN_SHIFT)) & AUDIOSAMPLEGP_GP_CONF1_CH_IN_EN_MASK)
/*! @} */

/*! @name GP_CONF2 - Audio GPA HBR Enable Register 2 */
/*! @{ */

#define AUDIOSAMPLEGP_GP_CONF2_HBR_MASK          (0x1U)
#define AUDIOSAMPLEGP_GP_CONF2_HBR_SHIFT         (0U)
/*! HBR - HBR packets enable. */
#define AUDIOSAMPLEGP_GP_CONF2_HBR(x)            (((uint8_t)(((uint8_t)(x)) << AUDIOSAMPLEGP_GP_CONF2_HBR_SHIFT)) & AUDIOSAMPLEGP_GP_CONF2_HBR_MASK)

#define AUDIOSAMPLEGP_GP_CONF2_INSERT_PCUV_MASK  (0x2U)
#define AUDIOSAMPLEGP_GP_CONF2_INSERT_PCUV_SHIFT (1U)
/*! insert_pcuv - When set (1'b1), this bit enables the insertion of the PCUV (Parity, Channel
 *    Status, User bit and Validity) bits on the incoming audio stream (support limited to Linear PCM
 *    audio).
 */
#define AUDIOSAMPLEGP_GP_CONF2_INSERT_PCUV(x)    (((uint8_t)(((uint8_t)(x)) << AUDIOSAMPLEGP_GP_CONF2_INSERT_PCUV_SHIFT)) & AUDIOSAMPLEGP_GP_CONF2_INSERT_PCUV_MASK)
/*! @} */

/*! @name GP_MASK - Audio GPA FIFO Full and Empty Mask Interrupt Register */
/*! @{ */

#define AUDIOSAMPLEGP_GP_MASK_FIFO_FULL_MASK_MASK (0x1U)
#define AUDIOSAMPLEGP_GP_MASK_FIFO_FULL_MASK_SHIFT (0U)
/*! fifo_full_mask - FIFO full flag mask */
#define AUDIOSAMPLEGP_GP_MASK_FIFO_FULL_MASK(x)  (((uint8_t)(((uint8_t)(x)) << AUDIOSAMPLEGP_GP_MASK_FIFO_FULL_MASK_SHIFT)) & AUDIOSAMPLEGP_GP_MASK_FIFO_FULL_MASK_MASK)

#define AUDIOSAMPLEGP_GP_MASK_FIFO_EMPTY_MASK_MASK (0x2U)
#define AUDIOSAMPLEGP_GP_MASK_FIFO_EMPTY_MASK_SHIFT (1U)
/*! fifo_empty_mask - FIFO empty flag mask */
#define AUDIOSAMPLEGP_GP_MASK_FIFO_EMPTY_MASK(x) (((uint8_t)(((uint8_t)(x)) << AUDIOSAMPLEGP_GP_MASK_FIFO_EMPTY_MASK_SHIFT)) & AUDIOSAMPLEGP_GP_MASK_FIFO_EMPTY_MASK_MASK)

#define AUDIOSAMPLEGP_GP_MASK_FIFO_OVERRUN_MASK_MASK (0x10U)
#define AUDIOSAMPLEGP_GP_MASK_FIFO_OVERRUN_MASK_SHIFT (4U)
/*! fifo_overrun_mask - FIFO overrun mask */
#define AUDIOSAMPLEGP_GP_MASK_FIFO_OVERRUN_MASK(x) (((uint8_t)(((uint8_t)(x)) << AUDIOSAMPLEGP_GP_MASK_FIFO_OVERRUN_MASK_SHIFT)) & AUDIOSAMPLEGP_GP_MASK_FIFO_OVERRUN_MASK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AUDIOSAMPLEGP_Register_Masks */


/*!
 * @}
 */ /* end of group AUDIOSAMPLEGP_Peripheral_Access_Layer */


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


#endif  /* PERI_AUDIOSAMPLEGP_H_ */

