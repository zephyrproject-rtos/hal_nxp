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
**         CMSIS Peripheral Access Layer for VIDEOPACKETIZER
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
 * @file PERI_VIDEOPACKETIZER.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VIDEOPACKETIZER
 *
 * CMSIS Peripheral Access Layer for VIDEOPACKETIZER
 */

#if !defined(PERI_VIDEOPACKETIZER_H_)
#define PERI_VIDEOPACKETIZER_H_                  /**< Symbol preventing repeated inclusion */

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
   -- VIDEOPACKETIZER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIDEOPACKETIZER_Peripheral_Access_Layer VIDEOPACKETIZER Peripheral Access Layer
 * @{
 */

/** VIDEOPACKETIZER - Register Layout Typedef */
typedef struct {
  __I  uint8_t VP_STATUS;                          /**< Video Packetizer Packing Phase Status Register, offset: 0x0 */
  __IO uint8_t VP_PR_CD;                           /**< Video Packetizer Pixel Repetition and Color Depth Register, offset: 0x1 */
  __IO uint8_t VP_STUFF;                           /**< Video Packetizer Stuffing and Default Packing Phase Register, offset: 0x2 */
  __IO uint8_t VP_REMAP;                           /**< Video Packetizer YCbCr 422 Remapping Register, offset: 0x3 */
  __IO uint8_t VP_CONF;                            /**< Video Packetizer Output and Enable Configuration Register, offset: 0x4 */
       uint8_t RESERVED_0[2];
  __IO uint8_t VP_MASK;                            /**< Video Packetizer Interrupt Mask Register, offset: 0x7 */
} VIDEOPACKETIZER_Type;

/* ----------------------------------------------------------------------------
   -- VIDEOPACKETIZER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIDEOPACKETIZER_Register_Masks VIDEOPACKETIZER Register Masks
 * @{
 */

/*! @name VP_STATUS - Video Packetizer Packing Phase Status Register */
/*! @{ */

#define VIDEOPACKETIZER_VP_STATUS_packing_phase_MASK (0xFU)
#define VIDEOPACKETIZER_VP_STATUS_packing_phase_SHIFT (0U)
/*! packing_phase - Read only register that holds the "packing phase" output of the Video Packetizer block. */
#define VIDEOPACKETIZER_VP_STATUS_packing_phase(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_STATUS_packing_phase_SHIFT)) & VIDEOPACKETIZER_VP_STATUS_packing_phase_MASK)
/*! @} */

/*! @name VP_PR_CD - Video Packetizer Pixel Repetition and Color Depth Register */
/*! @{ */

#define VIDEOPACKETIZER_VP_PR_CD_desired_pr_factor_MASK (0xFU)
#define VIDEOPACKETIZER_VP_PR_CD_desired_pr_factor_SHIFT (0U)
/*! desired_pr_factor - Desired pixel repetition factor configuration. */
#define VIDEOPACKETIZER_VP_PR_CD_desired_pr_factor(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_PR_CD_desired_pr_factor_SHIFT)) & VIDEOPACKETIZER_VP_PR_CD_desired_pr_factor_MASK)

#define VIDEOPACKETIZER_VP_PR_CD_color_depth_MASK (0xF0U)
#define VIDEOPACKETIZER_VP_PR_CD_color_depth_SHIFT (4U)
/*! color_depth - The Color depth configuration is described as the following, with the action
 *    stated corresponding to color_depth[3:0]: - 0000b: 24 bits per pixel video (8 bits per component).
 */
#define VIDEOPACKETIZER_VP_PR_CD_color_depth(x)  (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_PR_CD_color_depth_SHIFT)) & VIDEOPACKETIZER_VP_PR_CD_color_depth_MASK)
/*! @} */

/*! @name VP_STUFF - Video Packetizer Stuffing and Default Packing Phase Register */
/*! @{ */

#define VIDEOPACKETIZER_VP_STUFF_pr_stuffing_MASK (0x1U)
#define VIDEOPACKETIZER_VP_STUFF_pr_stuffing_SHIFT (0U)
/*! pr_stuffing - Pixel repeater stuffing control. */
#define VIDEOPACKETIZER_VP_STUFF_pr_stuffing(x)  (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_STUFF_pr_stuffing_SHIFT)) & VIDEOPACKETIZER_VP_STUFF_pr_stuffing_MASK)

#define VIDEOPACKETIZER_VP_STUFF_pp_stuffing_MASK (0x2U)
#define VIDEOPACKETIZER_VP_STUFF_pp_stuffing_SHIFT (1U)
/*! pp_stuffing - Pixel packing stuffing control. */
#define VIDEOPACKETIZER_VP_STUFF_pp_stuffing(x)  (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_STUFF_pp_stuffing_SHIFT)) & VIDEOPACKETIZER_VP_STUFF_pp_stuffing_MASK)

#define VIDEOPACKETIZER_VP_STUFF_ycc422_stuffing_MASK (0x4U)
#define VIDEOPACKETIZER_VP_STUFF_ycc422_stuffing_SHIFT (2U)
/*! ycc422_stuffing - YCbCr 422 remap stuffing control. */
#define VIDEOPACKETIZER_VP_STUFF_ycc422_stuffing(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_STUFF_ycc422_stuffing_SHIFT)) & VIDEOPACKETIZER_VP_STUFF_ycc422_stuffing_MASK)

#define VIDEOPACKETIZER_VP_STUFF_icx_goto_p0_st_MASK (0x8U)
#define VIDEOPACKETIZER_VP_STUFF_icx_goto_p0_st_SHIFT (3U)
/*! icx_goto_p0_st - Reserved. */
#define VIDEOPACKETIZER_VP_STUFF_icx_goto_p0_st(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_STUFF_icx_goto_p0_st_SHIFT)) & VIDEOPACKETIZER_VP_STUFF_icx_goto_p0_st_MASK)

#define VIDEOPACKETIZER_VP_STUFF_ifix_pp_to_last_MASK (0x10U)
#define VIDEOPACKETIZER_VP_STUFF_ifix_pp_to_last_SHIFT (4U)
/*! ifix_pp_to_last - Reserved. */
#define VIDEOPACKETIZER_VP_STUFF_ifix_pp_to_last(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_STUFF_ifix_pp_to_last_SHIFT)) & VIDEOPACKETIZER_VP_STUFF_ifix_pp_to_last_MASK)

#define VIDEOPACKETIZER_VP_STUFF_idefault_phase_MASK (0x20U)
#define VIDEOPACKETIZER_VP_STUFF_idefault_phase_SHIFT (5U)
/*! idefault_phase - Controls the default phase packing machine used according to HDMI 1. */
#define VIDEOPACKETIZER_VP_STUFF_idefault_phase(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_STUFF_idefault_phase_SHIFT)) & VIDEOPACKETIZER_VP_STUFF_idefault_phase_MASK)
/*! @} */

/*! @name VP_REMAP - Video Packetizer YCbCr 422 Remapping Register */
/*! @{ */

#define VIDEOPACKETIZER_VP_REMAP_ycc422_size_MASK (0x3U)
#define VIDEOPACKETIZER_VP_REMAP_ycc422_size_SHIFT (0U)
/*! ycc422_size - YCbCr 422 remap input video size ycc422_size[1:0] 00b: YCbCr 422 16-bit input
 *    video (8 bits per component) 01b: YCbCr 422 20-bit input video (10 bits per component) 10b: YCbCr
 *    422 24-bit input video (12 bits per component) 11b: Reserved.
 */
#define VIDEOPACKETIZER_VP_REMAP_ycc422_size(x)  (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_REMAP_ycc422_size_SHIFT)) & VIDEOPACKETIZER_VP_REMAP_ycc422_size_MASK)
/*! @} */

/*! @name VP_CONF - Video Packetizer Output and Enable Configuration Register */
/*! @{ */

#define VIDEOPACKETIZER_VP_CONF_output_selector_0_MASK (0x1U)
#define VIDEOPACKETIZER_VP_CONF_output_selector_0_SHIFT (0U)
/*! output_selector_0 - Video Packetizer output selection 0b: Data from pixel packing block 1b: Data from YCbCr 422 remap block */
#define VIDEOPACKETIZER_VP_CONF_output_selector_0(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_CONF_output_selector_0_SHIFT)) & VIDEOPACKETIZER_VP_CONF_output_selector_0_MASK)

#define VIDEOPACKETIZER_VP_CONF_output_selector_1_MASK (0x2U)
#define VIDEOPACKETIZER_VP_CONF_output_selector_1_SHIFT (1U)
/*! output_selector_1 - When set to 1'b1, Data from pixel packing block Note: the use of this field is deprecated */
#define VIDEOPACKETIZER_VP_CONF_output_selector_1(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_CONF_output_selector_1_SHIFT)) & VIDEOPACKETIZER_VP_CONF_output_selector_1_MASK)

#define VIDEOPACKETIZER_VP_CONF_bypass_select_MASK (0x4U)
#define VIDEOPACKETIZER_VP_CONF_bypass_select_SHIFT (2U)
/*! bypass_select - bypass_select 0b: Data from pixel repeater block 1b: Data from input of Video Packetizer block */
#define VIDEOPACKETIZER_VP_CONF_bypass_select(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_CONF_bypass_select_SHIFT)) & VIDEOPACKETIZER_VP_CONF_bypass_select_MASK)

#define VIDEOPACKETIZER_VP_CONF_ycc422_en_MASK   (0x8U)
#define VIDEOPACKETIZER_VP_CONF_ycc422_en_SHIFT  (3U)
/*! ycc422_en - YCbCr 422 select enable. */
#define VIDEOPACKETIZER_VP_CONF_ycc422_en(x)     (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_CONF_ycc422_en_SHIFT)) & VIDEOPACKETIZER_VP_CONF_ycc422_en_MASK)

#define VIDEOPACKETIZER_VP_CONF_pr_en_MASK       (0x10U)
#define VIDEOPACKETIZER_VP_CONF_pr_en_SHIFT      (4U)
/*! pr_en - Pixel repeater enable. */
#define VIDEOPACKETIZER_VP_CONF_pr_en(x)         (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_CONF_pr_en_SHIFT)) & VIDEOPACKETIZER_VP_CONF_pr_en_MASK)

#define VIDEOPACKETIZER_VP_CONF_pp_en_MASK       (0x20U)
#define VIDEOPACKETIZER_VP_CONF_pp_en_SHIFT      (5U)
/*! pp_en - Pixel packing enable. */
#define VIDEOPACKETIZER_VP_CONF_pp_en(x)         (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_CONF_pp_en_SHIFT)) & VIDEOPACKETIZER_VP_CONF_pp_en_MASK)

#define VIDEOPACKETIZER_VP_CONF_bypass_en_MASK   (0x40U)
#define VIDEOPACKETIZER_VP_CONF_bypass_en_SHIFT  (6U)
/*! bypass_en - When set to 1'b1, Pixel packing enable. */
#define VIDEOPACKETIZER_VP_CONF_bypass_en(x)     (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_CONF_bypass_en_SHIFT)) & VIDEOPACKETIZER_VP_CONF_bypass_en_MASK)
/*! @} */

/*! @name VP_MASK - Video Packetizer Interrupt Mask Register */
/*! @{ */

#define VIDEOPACKETIZER_VP_MASK_spare_1_MASK     (0x1U)
#define VIDEOPACKETIZER_VP_MASK_spare_1_SHIFT    (0U)
/*! spare_1 - Reserved as "spare" bit with no associated functionality. */
#define VIDEOPACKETIZER_VP_MASK_spare_1(x)       (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_MASK_spare_1_SHIFT)) & VIDEOPACKETIZER_VP_MASK_spare_1_MASK)

#define VIDEOPACKETIZER_VP_MASK_spare_2_MASK     (0x2U)
#define VIDEOPACKETIZER_VP_MASK_spare_2_SHIFT    (1U)
/*! spare_2 - Reserved as "spare" bit with no associated functionality. */
#define VIDEOPACKETIZER_VP_MASK_spare_2(x)       (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_MASK_spare_2_SHIFT)) & VIDEOPACKETIZER_VP_MASK_spare_2_MASK)

#define VIDEOPACKETIZER_VP_MASK_ointemptyremap_MASK (0x4U)
#define VIDEOPACKETIZER_VP_MASK_ointemptyremap_SHIFT (2U)
/*! ointemptyremap - Mask bit for Video Packetizer pixel YCbCr 422 re-mapper FIFO empty */
#define VIDEOPACKETIZER_VP_MASK_ointemptyremap(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_MASK_ointemptyremap_SHIFT)) & VIDEOPACKETIZER_VP_MASK_ointemptyremap_MASK)

#define VIDEOPACKETIZER_VP_MASK_ointfullremap_MASK (0x8U)
#define VIDEOPACKETIZER_VP_MASK_ointfullremap_SHIFT (3U)
/*! ointfullremap - Mask bit for Video Packetizer pixel YCbCr 422 re-mapper FIFO full */
#define VIDEOPACKETIZER_VP_MASK_ointfullremap(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_MASK_ointfullremap_SHIFT)) & VIDEOPACKETIZER_VP_MASK_ointfullremap_MASK)

#define VIDEOPACKETIZER_VP_MASK_ointemptypp_MASK (0x10U)
#define VIDEOPACKETIZER_VP_MASK_ointemptypp_SHIFT (4U)
/*! ointemptypp - Mask bit for Video Packetizer pixel packing FIFO empty */
#define VIDEOPACKETIZER_VP_MASK_ointemptypp(x)   (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_MASK_ointemptypp_SHIFT)) & VIDEOPACKETIZER_VP_MASK_ointemptypp_MASK)

#define VIDEOPACKETIZER_VP_MASK_ointfullpp_MASK  (0x20U)
#define VIDEOPACKETIZER_VP_MASK_ointfullpp_SHIFT (5U)
/*! ointfullpp - Mask bit for Video Packetizer pixel packing FIFO full */
#define VIDEOPACKETIZER_VP_MASK_ointfullpp(x)    (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_MASK_ointfullpp_SHIFT)) & VIDEOPACKETIZER_VP_MASK_ointfullpp_MASK)

#define VIDEOPACKETIZER_VP_MASK_ointemptyrepet_MASK (0x40U)
#define VIDEOPACKETIZER_VP_MASK_ointemptyrepet_SHIFT (6U)
/*! ointemptyrepet - Mask bit for Video Packetizer pixel repeater FIFO empty */
#define VIDEOPACKETIZER_VP_MASK_ointemptyrepet(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_MASK_ointemptyrepet_SHIFT)) & VIDEOPACKETIZER_VP_MASK_ointemptyrepet_MASK)

#define VIDEOPACKETIZER_VP_MASK_ointfullrepet_MASK (0x80U)
#define VIDEOPACKETIZER_VP_MASK_ointfullrepet_SHIFT (7U)
/*! ointfullrepet - Mask bit for Video Packetizer pixel repeater FIFO full */
#define VIDEOPACKETIZER_VP_MASK_ointfullrepet(x) (((uint8_t)(((uint8_t)(x)) << VIDEOPACKETIZER_VP_MASK_ointfullrepet_SHIFT)) & VIDEOPACKETIZER_VP_MASK_ointfullrepet_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VIDEOPACKETIZER_Register_Masks */


/*!
 * @}
 */ /* end of group VIDEOPACKETIZER_Peripheral_Access_Layer */


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


#endif  /* PERI_VIDEOPACKETIZER_H_ */

