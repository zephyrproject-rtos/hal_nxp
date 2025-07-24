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
**         CMSIS Peripheral Access Layer for HDCP22
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
 * @file PERI_HDCP22.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HDCP22
 *
 * CMSIS Peripheral Access Layer for HDCP22
 */

#if !defined(PERI_HDCP22_H_)
#define PERI_HDCP22_H_                           /**< Symbol preventing repeated inclusion */

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
   -- HDCP22 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDCP22_Peripheral_Access_Layer HDCP22 Peripheral Access Layer
 * @{
 */

/** HDCP22 - Register Layout Typedef */
typedef struct {
  __I  uint8_t HDCP22REG_ID;                       /**< HDCP 2., offset: 0x0 */
       uint8_t RESERVED_0[3];
  __IO uint8_t HDCP22REG_CTRL;                     /**< HDCP 2., offset: 0x4 */
  __IO uint8_t HDCP22REG_CTRL1;                    /**< HDCP 2., offset: 0x5 */
       uint8_t RESERVED_1[2];
  __I  uint8_t HDCP22REG_STS;                      /**< HDCP 2., offset: 0x8 */
       uint8_t RESERVED_2[3];
  __IO uint8_t HDCP22REG_MASK;                     /**< HDCP 2., offset: 0xC */
       uint8_t RESERVED_3[2];
  __IO uint8_t HDCP22REG_STAT;                     /**< HDCP 2., offset: 0xF */
       uint8_t RESERVED_4[2];
  __IO uint8_t HDCP22REG_MUTE;                     /**< HDCP 2., offset: 0x12 */
} HDCP22_Type;

/* ----------------------------------------------------------------------------
   -- HDCP22 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDCP22_Register_Masks HDCP22 Register Masks
 * @{
 */

/*! @name HDCP22REG_ID - HDCP 2. */
/*! @{ */

#define HDCP22_HDCP22REG_ID_HDCP22_EXTERNALIF_MASK (0x2U)
#define HDCP22_HDCP22REG_ID_HDCP22_EXTERNALIF_SHIFT (1U)
/*! hdcp22_externalif - Indicates that External HDCP 2. */
#define HDCP22_HDCP22REG_ID_HDCP22_EXTERNALIF(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_ID_HDCP22_EXTERNALIF_SHIFT)) & HDCP22_HDCP22REG_ID_HDCP22_EXTERNALIF_MASK)

#define HDCP22_HDCP22REG_ID_HDCP22_3RDPARTY_MASK (0x4U)
#define HDCP22_HDCP22REG_ID_HDCP22_3RDPARTY_SHIFT (2U)
/*! hdcp22_3rdparty - Indicates that External HDCP 2. */
#define HDCP22_HDCP22REG_ID_HDCP22_3RDPARTY(x)   (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_ID_HDCP22_3RDPARTY_SHIFT)) & HDCP22_HDCP22REG_ID_HDCP22_3RDPARTY_MASK)
/*! @} */

/*! @name HDCP22REG_CTRL - HDCP 2. */
/*! @{ */

#define HDCP22_HDCP22REG_CTRL_HDCP22_SWITCH_LCK_MASK (0x1U)
#define HDCP22_HDCP22REG_CTRL_HDCP22_SWITCH_LCK_SHIFT (0U)
/*! hdcp22_switch_lck - HDCP 2. */
#define HDCP22_HDCP22REG_CTRL_HDCP22_SWITCH_LCK(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_CTRL_HDCP22_SWITCH_LCK_SHIFT)) & HDCP22_HDCP22REG_CTRL_HDCP22_SWITCH_LCK_MASK)

#define HDCP22_HDCP22REG_CTRL_HDCP22_OVR_EN_MASK (0x2U)
#define HDCP22_HDCP22REG_CTRL_HDCP22_OVR_EN_SHIFT (1U)
/*! hdcp22_ovr_en - HDCP 2. */
#define HDCP22_HDCP22REG_CTRL_HDCP22_OVR_EN(x)   (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_CTRL_HDCP22_OVR_EN_SHIFT)) & HDCP22_HDCP22REG_CTRL_HDCP22_OVR_EN_MASK)

#define HDCP22_HDCP22REG_CTRL_HDCP22_OVR_VAL_MASK (0x4U)
#define HDCP22_HDCP22REG_CTRL_HDCP22_OVR_VAL_SHIFT (2U)
/*! hdcp22_ovr_val - HDCP 2. */
#define HDCP22_HDCP22REG_CTRL_HDCP22_OVR_VAL(x)  (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_CTRL_HDCP22_OVR_VAL_SHIFT)) & HDCP22_HDCP22REG_CTRL_HDCP22_OVR_VAL_MASK)

#define HDCP22_HDCP22REG_CTRL_HPD_OVR_EN_MASK    (0x10U)
#define HDCP22_HDCP22REG_CTRL_HPD_OVR_EN_SHIFT   (4U)
/*! hpd_ovr_en - HPD Override enable - 1'b0: The HPD value to the HDCP 2. */
#define HDCP22_HDCP22REG_CTRL_HPD_OVR_EN(x)      (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_CTRL_HPD_OVR_EN_SHIFT)) & HDCP22_HDCP22REG_CTRL_HPD_OVR_EN_MASK)

#define HDCP22_HDCP22REG_CTRL_HPD_OVR_VAL_MASK   (0x20U)
#define HDCP22_HDCP22REG_CTRL_HPD_OVR_VAL_SHIFT  (5U)
/*! hpd_ovr_val - HPD Override Value - 1'b0: If hpd_ovr_en is 1'b1 the HPD value to the HDCP 2. */
#define HDCP22_HDCP22REG_CTRL_HPD_OVR_VAL(x)     (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_CTRL_HPD_OVR_VAL_SHIFT)) & HDCP22_HDCP22REG_CTRL_HPD_OVR_VAL_MASK)
/*! @} */

/*! @name HDCP22REG_CTRL1 - HDCP 2. */
/*! @{ */

#define HDCP22_HDCP22REG_CTRL1_HDCP22_AVMUTE_OVR_EN_MASK (0x1U)
#define HDCP22_HDCP22REG_CTRL1_HDCP22_AVMUTE_OVR_EN_SHIFT (0U)
/*! hdcp22_avmute_ovr_en - HDCP 2. */
#define HDCP22_HDCP22REG_CTRL1_HDCP22_AVMUTE_OVR_EN(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_CTRL1_HDCP22_AVMUTE_OVR_EN_SHIFT)) & HDCP22_HDCP22REG_CTRL1_HDCP22_AVMUTE_OVR_EN_MASK)

#define HDCP22_HDCP22REG_CTRL1_HDCP22_AVMUTE_OVR_VAL_MASK (0x2U)
#define HDCP22_HDCP22REG_CTRL1_HDCP22_AVMUTE_OVR_VAL_SHIFT (1U)
/*! hdcp22_avmute_ovr_val - HDCP AV_MUTE override value, which is sent through the HDCP 2. */
#define HDCP22_HDCP22REG_CTRL1_HDCP22_AVMUTE_OVR_VAL(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_CTRL1_HDCP22_AVMUTE_OVR_VAL_SHIFT)) & HDCP22_HDCP22REG_CTRL1_HDCP22_AVMUTE_OVR_VAL_MASK)

#define HDCP22_HDCP22REG_CTRL1_HDCP22_CD_OVR_EN_MASK (0x8U)
#define HDCP22_HDCP22REG_CTRL1_HDCP22_CD_OVR_EN_SHIFT (3U)
/*! hdcp22_cd_ovr_en - HDCP 2. */
#define HDCP22_HDCP22REG_CTRL1_HDCP22_CD_OVR_EN(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_CTRL1_HDCP22_CD_OVR_EN_SHIFT)) & HDCP22_HDCP22REG_CTRL1_HDCP22_CD_OVR_EN_MASK)

#define HDCP22_HDCP22REG_CTRL1_HDCP22_CD_OVR_VAL_MASK (0xF0U)
#define HDCP22_HDCP22REG_CTRL1_HDCP22_CD_OVR_VAL_SHIFT (4U)
/*! hdcp22_cd_ovr_val - HDCP color depth override value, which is sent through the HDCP 2. */
#define HDCP22_HDCP22REG_CTRL1_HDCP22_CD_OVR_VAL(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_CTRL1_HDCP22_CD_OVR_VAL_SHIFT)) & HDCP22_HDCP22REG_CTRL1_HDCP22_CD_OVR_VAL_MASK)
/*! @} */

/*! @name HDCP22REG_STS - HDCP 2. */
/*! @{ */

#define HDCP22_HDCP22REG_STS_HDMI_HPD_STS_MASK   (0x1U)
#define HDCP22_HDCP22REG_STS_HDMI_HPD_STS_SHIFT  (0U)
/*! hdmi_hpd_sts - HDCP 2. */
#define HDCP22_HDCP22REG_STS_HDMI_HPD_STS(x)     (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_STS_HDMI_HPD_STS_SHIFT)) & HDCP22_HDCP22REG_STS_HDMI_HPD_STS_MASK)

#define HDCP22_HDCP22REG_STS_HDCP_AVMUTE_STS_MASK (0x2U)
#define HDCP22_HDCP22REG_STS_HDCP_AVMUTE_STS_SHIFT (1U)
/*! hdcp_avmute_sts - HDCP 2. */
#define HDCP22_HDCP22REG_STS_HDCP_AVMUTE_STS(x)  (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_STS_HDCP_AVMUTE_STS_SHIFT)) & HDCP22_HDCP22REG_STS_HDCP_AVMUTE_STS_MASK)

#define HDCP22_HDCP22REG_STS_HDCP22_SWITCH_STS_MASK (0x4U)
#define HDCP22_HDCP22REG_STS_HDCP22_SWITCH_STS_SHIFT (2U)
/*! hdcp22_switch_sts - HDCP 2. */
#define HDCP22_HDCP22REG_STS_HDCP22_SWITCH_STS(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_STS_HDCP22_SWITCH_STS_SHIFT)) & HDCP22_HDCP22REG_STS_HDCP22_SWITCH_STS_MASK)

#define HDCP22_HDCP22REG_STS_HDCP_DECRYPTED_STS_MASK (0x8U)
#define HDCP22_HDCP22REG_STS_HDCP_DECRYPTED_STS_SHIFT (3U)
/*! hdcp_decrypted_sts - Value of HDCP 2. */
#define HDCP22_HDCP22REG_STS_HDCP_DECRYPTED_STS(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_STS_HDCP_DECRYPTED_STS_SHIFT)) & HDCP22_HDCP22REG_STS_HDCP_DECRYPTED_STS_MASK)
/*! @} */

/*! @name HDCP22REG_MASK - HDCP 2. */
/*! @{ */

#define HDCP22_HDCP22REG_MASK_MASK_HDCP2_CAPABLE_MASK (0x1U)
#define HDCP22_HDCP22REG_MASK_MASK_HDCP2_CAPABLE_SHIFT (0U)
/*! mask_hdcp2_capable - Active high interrupt mask to HDCP 2. */
#define HDCP22_HDCP22REG_MASK_MASK_HDCP2_CAPABLE(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MASK_MASK_HDCP2_CAPABLE_SHIFT)) & HDCP22_HDCP22REG_MASK_MASK_HDCP2_CAPABLE_MASK)

#define HDCP22_HDCP22REG_MASK_MASK_HDCP2_NOT_CAPABLE_MASK (0x2U)
#define HDCP22_HDCP22REG_MASK_MASK_HDCP2_NOT_CAPABLE_SHIFT (1U)
/*! mask_hdcp2_not_capable - Active high interrupt mask to HDCP 2. */
#define HDCP22_HDCP22REG_MASK_MASK_HDCP2_NOT_CAPABLE(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MASK_MASK_HDCP2_NOT_CAPABLE_SHIFT)) & HDCP22_HDCP22REG_MASK_MASK_HDCP2_NOT_CAPABLE_MASK)

#define HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATION_LOST_MASK (0x4U)
#define HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATION_LOST_SHIFT (2U)
/*! mask_hdcp_authentication_lost - Active high interrupt mask to HDCP 2. */
#define HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATION_LOST(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATION_LOST_SHIFT)) & HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATION_LOST_MASK)

#define HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATED_MASK (0x8U)
#define HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATED_SHIFT (3U)
/*! mask_hdcp_authenticated - Active high interrupt mask to HDCP 2. */
#define HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATED(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATED_SHIFT)) & HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATED_MASK)

#define HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATION_FAIL_MASK (0x10U)
#define HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATION_FAIL_SHIFT (4U)
/*! mask_hdcp_authentication_fail - Active high interrupt mask to HDCP 2. */
#define HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATION_FAIL(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATION_FAIL_SHIFT)) & HDCP22_HDCP22REG_MASK_MASK_HDCP_AUTHENTICATION_FAIL_MASK)

#define HDCP22_HDCP22REG_MASK_MASK_HDCP_DECRYPTED_CHG_MASK (0x20U)
#define HDCP22_HDCP22REG_MASK_MASK_HDCP_DECRYPTED_CHG_SHIFT (5U)
/*! mask_hdcp_decrypted_chg - Active high interrupt mask to HDCP 2. */
#define HDCP22_HDCP22REG_MASK_MASK_HDCP_DECRYPTED_CHG(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MASK_MASK_HDCP_DECRYPTED_CHG_SHIFT)) & HDCP22_HDCP22REG_MASK_MASK_HDCP_DECRYPTED_CHG_MASK)
/*! @} */

/*! @name HDCP22REG_STAT - HDCP 2. */
/*! @{ */

#define HDCP22_HDCP22REG_STAT_ST_HDCP2_CAPABLE_MASK (0x1U)
#define HDCP22_HDCP22REG_STAT_ST_HDCP2_CAPABLE_SHIFT (0U)
/*! st_hdcp2_capable - HDCP 2. */
#define HDCP22_HDCP22REG_STAT_ST_HDCP2_CAPABLE(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_STAT_ST_HDCP2_CAPABLE_SHIFT)) & HDCP22_HDCP22REG_STAT_ST_HDCP2_CAPABLE_MASK)

#define HDCP22_HDCP22REG_STAT_ST_HDCP2_NOT_CAPABLE_MASK (0x2U)
#define HDCP22_HDCP22REG_STAT_ST_HDCP2_NOT_CAPABLE_SHIFT (1U)
/*! st_hdcp2_not_capable - HDCP 2. */
#define HDCP22_HDCP22REG_STAT_ST_HDCP2_NOT_CAPABLE(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_STAT_ST_HDCP2_NOT_CAPABLE_SHIFT)) & HDCP22_HDCP22REG_STAT_ST_HDCP2_NOT_CAPABLE_MASK)

#define HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATION_LOST_MASK (0x4U)
#define HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATION_LOST_SHIFT (2U)
/*! st_hdcp_authentication_lost - HDCP 2. */
#define HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATION_LOST(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATION_LOST_SHIFT)) & HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATION_LOST_MASK)

#define HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATED_MASK (0x8U)
#define HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATED_SHIFT (3U)
/*! st_hdcp_authenticated - HDCP 2. */
#define HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATED(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATED_SHIFT)) & HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATED_MASK)

#define HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATION_FAIL_MASK (0x10U)
#define HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATION_FAIL_SHIFT (4U)
/*! st_hdcp_authentication_fail - HDCP 2. */
#define HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATION_FAIL(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATION_FAIL_SHIFT)) & HDCP22_HDCP22REG_STAT_ST_HDCP_AUTHENTICATION_FAIL_MASK)

#define HDCP22_HDCP22REG_STAT_ST_HDCP_DECRYPTED_CHG_MASK (0x20U)
#define HDCP22_HDCP22REG_STAT_ST_HDCP_DECRYPTED_CHG_SHIFT (5U)
/*! st_hdcp_decrypted_chg - HDCP 2. */
#define HDCP22_HDCP22REG_STAT_ST_HDCP_DECRYPTED_CHG(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_STAT_ST_HDCP_DECRYPTED_CHG_SHIFT)) & HDCP22_HDCP22REG_STAT_ST_HDCP_DECRYPTED_CHG_MASK)
/*! @} */

/*! @name HDCP22REG_MUTE - HDCP 2. */
/*! @{ */

#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP2_CAPABLE_MASK (0x1U)
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP2_CAPABLE_SHIFT (0U)
/*! mute_hdcp2_capable - Active high interrupt mute to HDCP 2. */
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP2_CAPABLE(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MUTE_MUTE_HDCP2_CAPABLE_SHIFT)) & HDCP22_HDCP22REG_MUTE_MUTE_HDCP2_CAPABLE_MASK)

#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP2_NOT_CAPABLE_MASK (0x2U)
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP2_NOT_CAPABLE_SHIFT (1U)
/*! mute_hdcp2_not_capable - Active high interrupt mute to HDCP 2. */
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP2_NOT_CAPABLE(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MUTE_MUTE_HDCP2_NOT_CAPABLE_SHIFT)) & HDCP22_HDCP22REG_MUTE_MUTE_HDCP2_NOT_CAPABLE_MASK)

#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATION_LOST_MASK (0x4U)
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATION_LOST_SHIFT (2U)
/*! mute_hdcp_authentication_lost - Active high interrupt mute to HDCP 2. */
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATION_LOST(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATION_LOST_SHIFT)) & HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATION_LOST_MASK)

#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATED_MASK (0x8U)
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATED_SHIFT (3U)
/*! mute_hdcp_authenticated - Active high interrupt mute to HDCP 2. */
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATED(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATED_SHIFT)) & HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATED_MASK)

#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATION_FAIL_MASK (0x10U)
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATION_FAIL_SHIFT (4U)
/*! mute_hdcp_authentication_fail - Active high interrupt mute to HDCP 2. */
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATION_FAIL(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATION_FAIL_SHIFT)) & HDCP22_HDCP22REG_MUTE_MUTE_HDCP_AUTHENTICATION_FAIL_MASK)

#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_DECRYPTED_CHG_MASK (0x20U)
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_DECRYPTED_CHG_SHIFT (5U)
/*! mute_hdcp_decrypted_chg - Active high interrupt mute to HDCP 2. */
#define HDCP22_HDCP22REG_MUTE_MUTE_HDCP_DECRYPTED_CHG(x) (((uint8_t)(((uint8_t)(x)) << HDCP22_HDCP22REG_MUTE_MUTE_HDCP_DECRYPTED_CHG_SHIFT)) & HDCP22_HDCP22REG_MUTE_MUTE_HDCP_DECRYPTED_CHG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HDCP22_Register_Masks */


/*!
 * @}
 */ /* end of group HDCP22_Peripheral_Access_Layer */


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


#endif  /* PERI_HDCP22_H_ */

