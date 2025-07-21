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
**         CMSIS Peripheral Access Layer for HDCP
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
 * @file PERI_HDCP.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HDCP
 *
 * CMSIS Peripheral Access Layer for HDCP
 */

#if !defined(PERI_HDCP_H_)
#define PERI_HDCP_H_                             /**< Symbol preventing repeated inclusion */

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
   -- HDCP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDCP_Peripheral_Access_Layer HDCP Peripheral Access Layer
 * @{
 */

/** HDCP - Register Layout Typedef */
typedef struct {
  __IO uint8_t A_HDCPCFG0;                         /**< HDCP Enable and Functional Control Configuration Register 0, offset: 0x0 */
  __IO uint8_t A_HDCPCFG1;                         /**< HDCP Software Reset and Functional Control Configuration Register 1, offset: 0x1 */
  __I  uint8_t A_HDCPOBS0;                         /**< HDCP Observation Register 0, offset: 0x2 */
  __I  uint8_t A_HDCPOBS1;                         /**< HDCP Observation Register 1, offset: 0x3 */
  __I  uint8_t A_HDCPOBS2;                         /**< HDCP Observation Register 2, offset: 0x4 */
  __I  uint8_t A_HDCPOBS3;                         /**< HDCP Observation Register 3, offset: 0x5 */
  __O  uint8_t A_APIINTCLR;                        /**< HDCP Interrupt Clear Register Write only register, active high and auto cleared, cleans the respective interruption in the interrupt status register., offset: 0x6 */
  __I  uint8_t A_APIINTSTAT;                       /**< HDCP Interrupt Status Register Read only register, reports the interruption which caused the activation of the interruption output pin., offset: 0x7 */
  __IO uint8_t A_APIINTMSK;                        /**< HDCP Interrupt Mask Register The configuration of this register mask a given setup of interruption, disabling them from generating interruption pulses in the interruption output pin., offset: 0x8 */
  __IO uint8_t A_VIDPOLCFG;                        /**< HDCP Video Polarity Configuration Register, offset: 0x9 */
  __IO uint8_t A_OESSWCFG;                         /**< HDCP OESS WOO Configuration Register Pulse width of the encryption enable (CTL3) signal in the HDCP OESS mode., offset: 0xA */
       uint8_t RESERVED_0[9];
  __I  uint8_t A_COREVERLSB;                       /**< HDCP Controller Version Register LSB Design ID number., offset: 0x14 */
  __I  uint8_t A_COREVERMSB;                       /**< HDCP Controller Version Register MSB Revision ID number., offset: 0x15 */
  __IO uint8_t A_KSVMEMCTRL;                       /**< HDCP KSV Memory Control Register The KSVCTRLupd bit is a notification flag., offset: 0x16 */
       uint8_t RESERVED_1[674];
  __IO uint8_t HDCP_REVOC_SIZE_0;                  /**< HDCP Revocation KSV List Size Register 0, offset: 0x2B9 */
  __IO uint8_t HDCP_REVOC_SIZE_1;                  /**< HDCP Revocation KSV List Size Register 1, offset: 0x2BA */
       uint8_t RESERVED_2[9541];
  __I  uint8_t HDCPREG_BKSV0;                      /**< HDCP KSV Status Register 0, offset: 0x2800 */
  __I  uint8_t HDCPREG_BKSV1;                      /**< HDCP KSV Status Register 1, offset: 0x2801 */
  __I  uint8_t HDCPREG_BKSV2;                      /**< HDCP KSV Status Register 2, offset: 0x2802 */
  __I  uint8_t HDCPREG_BKSV3;                      /**< HDCP KSV Status Register 3, offset: 0x2803 */
  __I  uint8_t HDCPREG_BKSV4;                      /**< HDCP KSV Status Register 4, offset: 0x2804 */
  __IO uint8_t HDCPREG_ANCONF;                     /**< HDCP AN Bypass Control Register, offset: 0x2805 */
  __IO uint8_t HDCPREG_AN0;                        /**< HDCP Forced AN Register 0, offset: 0x2806 */
  __IO uint8_t HDCPREG_AN1;                        /**< HDCP Forced AN Register 1, offset: 0x2807 */
  __IO uint8_t HDCPREG_AN2;                        /**< HDCP forced AN Register 2, offset: 0x2808 */
  __IO uint8_t HDCPREG_AN3;                        /**< HDCP Forced AN Register 3, offset: 0x2809 */
  __IO uint8_t HDCPREG_AN4;                        /**< HDCP Forced AN Register 4, offset: 0x280A */
  __IO uint8_t HDCPREG_AN5;                        /**< HDCP Forced AN Register 5, offset: 0x280B */
  __IO uint8_t HDCPREG_AN6;                        /**< HDCP Forced AN Register 6, offset: 0x280C */
  __IO uint8_t HDCPREG_AN7;                        /**< HDCP Forced AN Register 7, offset: 0x280D */
  __IO uint8_t HDCPREG_RMLCTL;                     /**< HDCP Encrypted Device Private Keys Control Register This register is the control register for the software programmable encrypted DPK embedded storage feature., offset: 0x280E */
  __I  uint8_t HDCPREG_RMLSTS;                     /**< HDCP Encrypted DPK Status Register The required software configuration sequence is documented in the DesignWare Cores HDMI Transmitter User Guide in the "Programming" chapter, Section 3., offset: 0x280F */
  __O  uint8_t HDCPREG_SEED0;                      /**< HDCP Encrypted DPK Seed Register 0 This register contains a byte of the HDCP Encrypted DPK seed value used to encrypt the Device Private Keys., offset: 0x2810 */
  __O  uint8_t HDCPREG_SEED1;                      /**< HDCP Encrypted DPK Seed Register 1 This register contains a byte of the HDCP Encrypted DPK seed value used to encrypt the Device Private Keys., offset: 0x2811 */
  __O  uint8_t HDCPREG_DPK0;                       /**< HDCP Encrypted DPK Data Register 0 This register contains an HDCP DPK byte., offset: 0x2812 */
  __O  uint8_t HDCPREG_DPK1;                       /**< HDCP Encrypted DPK Data Register 1 This register contains an HDCP DPK byte., offset: 0x2813 */
  __O  uint8_t HDCPREG_DPK2;                       /**< HDCP Encrypted DPK Data Register 2 This register contains an HDCP DPK byte., offset: 0x2814 */
  __O  uint8_t HDCPREG_DPK3;                       /**< HDCP Encrypted DPK Data Register 3 This register contains an HDCP DPK byte., offset: 0x2815 */
  __O  uint8_t HDCPREG_DPK4;                       /**< HDCP Encrypted DPK Data Register 4 This register contains an HDCP DPK byte., offset: 0x2816 */
  __O  uint8_t HDCPREG_DPK5;                       /**< HDCP Encrypted DPK Data Register 5 This register contains an HDCP DPK byte., offset: 0x2817 */
  __O  uint8_t HDCPREG_DPK6;                       /**< HDCP Encrypted DPK Data Register 6 This register contains an HDCP DPK byte., offset: 0x2818 */
} HDCP_Type;

/* ----------------------------------------------------------------------------
   -- HDCP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDCP_Register_Masks HDCP Register Masks
 * @{
 */

/*! @name A_HDCPCFG0 - HDCP Enable and Functional Control Configuration Register 0 */
/*! @{ */

#define HDCP_A_HDCPCFG0_HDMIDVI_MASK             (0x1U)
#define HDCP_A_HDCPCFG0_HDMIDVI_SHIFT            (0U)
/*! hdmidvi - Configures the transmitter to operate with a HDMI capable device or with a DVI device. */
#define HDCP_A_HDCPCFG0_HDMIDVI(x)               (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG0_HDMIDVI_SHIFT)) & HDCP_A_HDCPCFG0_HDMIDVI_MASK)

#define HDCP_A_HDCPCFG0_EN11FEATURE_MASK         (0x2U)
#define HDCP_A_HDCPCFG0_EN11FEATURE_SHIFT        (1U)
/*! en11feature - Enable the use of features 1. */
#define HDCP_A_HDCPCFG0_EN11FEATURE(x)           (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG0_EN11FEATURE_SHIFT)) & HDCP_A_HDCPCFG0_EN11FEATURE_MASK)

#define HDCP_A_HDCPCFG0_RXDETECT_MASK            (0x4U)
#define HDCP_A_HDCPCFG0_RXDETECT_SHIFT           (2U)
/*! rxdetect - Information that a sink device was detected connected to the HDMI port */
#define HDCP_A_HDCPCFG0_RXDETECT(x)              (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG0_RXDETECT_SHIFT)) & HDCP_A_HDCPCFG0_RXDETECT_MASK)

#define HDCP_A_HDCPCFG0_AVMUTE_MASK              (0x8U)
#define HDCP_A_HDCPCFG0_AVMUTE_SHIFT             (3U)
/*! avmute - This register holds the current AVMUTE state of the DWC_hdmi_tx controller, as expected
 *    to be perceived by the connected HDMI/HDCP sink device.
 */
#define HDCP_A_HDCPCFG0_AVMUTE(x)                (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG0_AVMUTE_SHIFT)) & HDCP_A_HDCPCFG0_AVMUTE_MASK)

#define HDCP_A_HDCPCFG0_SYNCRICHECK_MASK         (0x10U)
#define HDCP_A_HDCPCFG0_SYNCRICHECK_SHIFT        (4U)
/*! syncricheck - Configures if the Ri check should be done at every 2s even or synchronously to every 128 encrypted frame. */
#define HDCP_A_HDCPCFG0_SYNCRICHECK(x)           (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG0_SYNCRICHECK_SHIFT)) & HDCP_A_HDCPCFG0_SYNCRICHECK_MASK)

#define HDCP_A_HDCPCFG0_BYPENCRYPTION_MASK       (0x20U)
#define HDCP_A_HDCPCFG0_BYPENCRYPTION_SHIFT      (5U)
/*! bypencryption - Bypasses all the data encryption stages */
#define HDCP_A_HDCPCFG0_BYPENCRYPTION(x)         (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG0_BYPENCRYPTION_SHIFT)) & HDCP_A_HDCPCFG0_BYPENCRYPTION_MASK)

#define HDCP_A_HDCPCFG0_I2CFASTMODE_MASK         (0x40U)
#define HDCP_A_HDCPCFG0_I2CFASTMODE_SHIFT        (6U)
/*! I2Cfastmode - Enable the I2C fast mode option from the transmitter's side. */
#define HDCP_A_HDCPCFG0_I2CFASTMODE(x)           (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG0_I2CFASTMODE_SHIFT)) & HDCP_A_HDCPCFG0_I2CFASTMODE_MASK)

#define HDCP_A_HDCPCFG0_ELVENA_MASK              (0x80U)
#define HDCP_A_HDCPCFG0_ELVENA_SHIFT             (7U)
/*! ELVena - Enables the Enhanced Link Verification from the transmitter's side */
#define HDCP_A_HDCPCFG0_ELVENA(x)                (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG0_ELVENA_SHIFT)) & HDCP_A_HDCPCFG0_ELVENA_MASK)
/*! @} */

/*! @name A_HDCPCFG1 - HDCP Software Reset and Functional Control Configuration Register 1 */
/*! @{ */

#define HDCP_A_HDCPCFG1_SWRESET_MASK             (0x1U)
#define HDCP_A_HDCPCFG1_SWRESET_SHIFT            (0U)
/*! swreset - Software reset signal, active by writing a zero and auto cleared to 1 in the following cycle. */
#define HDCP_A_HDCPCFG1_SWRESET(x)               (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG1_SWRESET_SHIFT)) & HDCP_A_HDCPCFG1_SWRESET_MASK)

#define HDCP_A_HDCPCFG1_ENCRYPTIONDISABLE_MASK   (0x2U)
#define HDCP_A_HDCPCFG1_ENCRYPTIONDISABLE_SHIFT  (1U)
/*! encryptiondisable - Disable encryption without losing authentication */
#define HDCP_A_HDCPCFG1_ENCRYPTIONDISABLE(x)     (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG1_ENCRYPTIONDISABLE_SHIFT)) & HDCP_A_HDCPCFG1_ENCRYPTIONDISABLE_MASK)

#define HDCP_A_HDCPCFG1_PH2UPSHFTENC_MASK        (0x4U)
#define HDCP_A_HDCPCFG1_PH2UPSHFTENC_SHIFT       (2U)
/*! ph2upshftenc - Enables the encoding of packet header in the tmdsch0 bit[0] with cipher[2]
 *    instead of the tmdsch0 bit[2] Note: This bit must always be set to 1 for all PHYs (PHY GEN1, PHY
 *    GEN2, and non-Synopsys PHY).
 */
#define HDCP_A_HDCPCFG1_PH2UPSHFTENC(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG1_PH2UPSHFTENC_SHIFT)) & HDCP_A_HDCPCFG1_PH2UPSHFTENC_MASK)

#define HDCP_A_HDCPCFG1_DISSHA1CHECK_MASK        (0x8U)
#define HDCP_A_HDCPCFG1_DISSHA1CHECK_SHIFT       (3U)
/*! dissha1check - Disables the request to the API processor to verify the SHA1 message digest of a received KSV List */
#define HDCP_A_HDCPCFG1_DISSHA1CHECK(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG1_DISSHA1CHECK_SHIFT)) & HDCP_A_HDCPCFG1_DISSHA1CHECK_MASK)

#define HDCP_A_HDCPCFG1_HDCP_LOCK_MASK           (0x10U)
#define HDCP_A_HDCPCFG1_HDCP_LOCK_SHIFT          (4U)
/*! hdcp_lock - Lock the HDCP bypass and encryption disable mechanisms: - 1'b0: The default 1'b0
 *    value enables you to bypass HDCP through bit 5 (bypencryption) of the A_HDCPCFG0 register or to
 *    disable the encryption through bit 1 (encryptiondisable) of A_HDCPCFG1.
 */
#define HDCP_A_HDCPCFG1_HDCP_LOCK(x)             (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG1_HDCP_LOCK_SHIFT)) & HDCP_A_HDCPCFG1_HDCP_LOCK_MASK)

#define HDCP_A_HDCPCFG1_SPARE_MASK               (0xE0U)
#define HDCP_A_HDCPCFG1_SPARE_SHIFT              (5U)
/*! spare - Reserved as "spare" register with no associated functionality. */
#define HDCP_A_HDCPCFG1_SPARE(x)                 (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPCFG1_SPARE_SHIFT)) & HDCP_A_HDCPCFG1_SPARE_MASK)
/*! @} */

/*! @name A_HDCPOBS0 - HDCP Observation Register 0 */
/*! @{ */

#define HDCP_A_HDCPOBS0_HDCPENGAGED_MASK         (0x1U)
#define HDCP_A_HDCPOBS0_HDCPENGAGED_SHIFT        (0U)
/*! hdcpengaged - Informs that the current HDMI link has the HDCP protocol fully engaged. */
#define HDCP_A_HDCPOBS0_HDCPENGAGED(x)           (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS0_HDCPENGAGED_SHIFT)) & HDCP_A_HDCPOBS0_HDCPENGAGED_MASK)

#define HDCP_A_HDCPOBS0_SUBSTATEA_MASK           (0xEU)
#define HDCP_A_HDCPOBS0_SUBSTATEA_SHIFT          (1U)
/*! SUBSTATEA - Observability register informs in which sub-state the authentication is on. */
#define HDCP_A_HDCPOBS0_SUBSTATEA(x)             (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS0_SUBSTATEA_SHIFT)) & HDCP_A_HDCPOBS0_SUBSTATEA_MASK)

#define HDCP_A_HDCPOBS0_STATEA_MASK              (0xF0U)
#define HDCP_A_HDCPOBS0_STATEA_SHIFT             (4U)
/*! STATEA - Observability register informs in which state the authentication machine is on. */
#define HDCP_A_HDCPOBS0_STATEA(x)                (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS0_STATEA_SHIFT)) & HDCP_A_HDCPOBS0_STATEA_MASK)
/*! @} */

/*! @name A_HDCPOBS1 - HDCP Observation Register 1 */
/*! @{ */

#define HDCP_A_HDCPOBS1_STATER_MASK              (0xFU)
#define HDCP_A_HDCPOBS1_STATER_SHIFT             (0U)
/*! STATER - Observability register informs in which state the revocation machine is on. */
#define HDCP_A_HDCPOBS1_STATER(x)                (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS1_STATER_SHIFT)) & HDCP_A_HDCPOBS1_STATER_MASK)

#define HDCP_A_HDCPOBS1_STATEOEG_MASK            (0x70U)
#define HDCP_A_HDCPOBS1_STATEOEG_SHIFT           (4U)
/*! STATEOEG - Observability register informs in which state the OESS machine is on. */
#define HDCP_A_HDCPOBS1_STATEOEG(x)              (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS1_STATEOEG_SHIFT)) & HDCP_A_HDCPOBS1_STATEOEG_MASK)
/*! @} */

/*! @name A_HDCPOBS2 - HDCP Observation Register 2 */
/*! @{ */

#define HDCP_A_HDCPOBS2_STATEEEG_MASK            (0x7U)
#define HDCP_A_HDCPOBS2_STATEEEG_SHIFT           (0U)
/*! STATEEEG - Observability register informs in which state the EESS machine is on. */
#define HDCP_A_HDCPOBS2_STATEEEG(x)              (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS2_STATEEEG_SHIFT)) & HDCP_A_HDCPOBS2_STATEEEG_MASK)

#define HDCP_A_HDCPOBS2_STATEE_MASK              (0x38U)
#define HDCP_A_HDCPOBS2_STATEE_SHIFT             (3U)
/*! STATEE - Observability register informs in which state the cipher machine is on. */
#define HDCP_A_HDCPOBS2_STATEE(x)                (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS2_STATEE_SHIFT)) & HDCP_A_HDCPOBS2_STATEE_MASK)
/*! @} */

/*! @name A_HDCPOBS3 - HDCP Observation Register 3 */
/*! @{ */

#define HDCP_A_HDCPOBS3_FAST_REAUTHENTICATION_MASK (0x1U)
#define HDCP_A_HDCPOBS3_FAST_REAUTHENTICATION_SHIFT (0U)
/*! FAST_REAUTHENTICATION - Register read from attached sink device: Bcap(0x40) bit 0. */
#define HDCP_A_HDCPOBS3_FAST_REAUTHENTICATION(x) (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS3_FAST_REAUTHENTICATION_SHIFT)) & HDCP_A_HDCPOBS3_FAST_REAUTHENTICATION_MASK)

#define HDCP_A_HDCPOBS3_FEATURES_1_1_MASK        (0x2U)
#define HDCP_A_HDCPOBS3_FEATURES_1_1_SHIFT       (1U)
/*! FEATURES_1_1 - Register read from attached sink device: Bcap(0x40) bit 1. */
#define HDCP_A_HDCPOBS3_FEATURES_1_1(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS3_FEATURES_1_1_SHIFT)) & HDCP_A_HDCPOBS3_FEATURES_1_1_MASK)

#define HDCP_A_HDCPOBS3_HDMI_MODE_MASK           (0x4U)
#define HDCP_A_HDCPOBS3_HDMI_MODE_SHIFT          (2U)
/*! HDMI_MODE - Register read from attached sink device: Bstatus(0x41) bit 12. */
#define HDCP_A_HDCPOBS3_HDMI_MODE(x)             (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS3_HDMI_MODE_SHIFT)) & HDCP_A_HDCPOBS3_HDMI_MODE_MASK)

#define HDCP_A_HDCPOBS3_HDMI_RESERVED_2_MASK     (0x8U)
#define HDCP_A_HDCPOBS3_HDMI_RESERVED_2_SHIFT    (3U)
/*! HDMI_RESERVED_2 - Register read from attached sink device: Bstatus(0x41) bit 13. */
#define HDCP_A_HDCPOBS3_HDMI_RESERVED_2(x)       (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS3_HDMI_RESERVED_2_SHIFT)) & HDCP_A_HDCPOBS3_HDMI_RESERVED_2_MASK)

#define HDCP_A_HDCPOBS3_FAST_I2C_MASK            (0x10U)
#define HDCP_A_HDCPOBS3_FAST_I2C_SHIFT           (4U)
/*! FAST_I2C - Register read from attached sink device: Bcap(0x40) bit 4. */
#define HDCP_A_HDCPOBS3_FAST_I2C(x)              (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS3_FAST_I2C_SHIFT)) & HDCP_A_HDCPOBS3_FAST_I2C_MASK)

#define HDCP_A_HDCPOBS3_KSV_FIFO_READY_MASK      (0x20U)
#define HDCP_A_HDCPOBS3_KSV_FIFO_READY_SHIFT     (5U)
/*! KSV_FIFO_READY - Register read from attached sink device: Bcap(0x40) bit 5. */
#define HDCP_A_HDCPOBS3_KSV_FIFO_READY(x)        (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS3_KSV_FIFO_READY_SHIFT)) & HDCP_A_HDCPOBS3_KSV_FIFO_READY_MASK)

#define HDCP_A_HDCPOBS3_REPEATER_MASK            (0x40U)
#define HDCP_A_HDCPOBS3_REPEATER_SHIFT           (6U)
/*! REPEATER - Register read from attached sink device: Bcap(0x40) bit 6. */
#define HDCP_A_HDCPOBS3_REPEATER(x)              (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS3_REPEATER_SHIFT)) & HDCP_A_HDCPOBS3_REPEATER_MASK)

#define HDCP_A_HDCPOBS3_HDMI_RESERVED_1_MASK     (0x80U)
#define HDCP_A_HDCPOBS3_HDMI_RESERVED_1_SHIFT    (7U)
/*! HDMI_RESERVED_1 - Register read from attached sink device: Bcap(0x40) bit 7. */
#define HDCP_A_HDCPOBS3_HDMI_RESERVED_1(x)       (((uint8_t)(((uint8_t)(x)) << HDCP_A_HDCPOBS3_HDMI_RESERVED_1_SHIFT)) & HDCP_A_HDCPOBS3_HDMI_RESERVED_1_MASK)
/*! @} */

/*! @name A_APIINTCLR - HDCP Interrupt Clear Register Write only register, active high and auto cleared, cleans the respective interruption in the interrupt status register. */
/*! @{ */

#define HDCP_A_APIINTCLR_KSVACCESSINT_MASK       (0x1U)
#define HDCP_A_APIINTCLR_KSVACCESSINT_SHIFT      (0U)
/*! KSVaccessint - Clears the interruption related to KSV memory access grant for Read-Write access. */
#define HDCP_A_APIINTCLR_KSVACCESSINT(x)         (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTCLR_KSVACCESSINT_SHIFT)) & HDCP_A_APIINTCLR_KSVACCESSINT_MASK)

#define HDCP_A_APIINTCLR_KEEPOUTERRORINT_MASK    (0x4U)
#define HDCP_A_APIINTCLR_KEEPOUTERRORINT_SHIFT   (2U)
/*! Keepouterrorint - Clears the interruption related to keep out window error. */
#define HDCP_A_APIINTCLR_KEEPOUTERRORINT(x)      (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTCLR_KEEPOUTERRORINT_SHIFT)) & HDCP_A_APIINTCLR_KEEPOUTERRORINT_MASK)

#define HDCP_A_APIINTCLR_LOSTARBITRATION_MASK    (0x8U)
#define HDCP_A_APIINTCLR_LOSTARBITRATION_SHIFT   (3U)
/*! Lostarbitration - Clears the interruption related to I2C arbitration lost. */
#define HDCP_A_APIINTCLR_LOSTARBITRATION(x)      (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTCLR_LOSTARBITRATION_SHIFT)) & HDCP_A_APIINTCLR_LOSTARBITRATION_MASK)

#define HDCP_A_APIINTCLR_I2CNACK_MASK            (0x10U)
#define HDCP_A_APIINTCLR_I2CNACK_SHIFT           (4U)
/*! I2Cnack - Clears the interruption related to I2C NACK reception. */
#define HDCP_A_APIINTCLR_I2CNACK(x)              (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTCLR_I2CNACK_SHIFT)) & HDCP_A_APIINTCLR_I2CNACK_MASK)

#define HDCP_A_APIINTCLR_KSVSHA1CALCDONEINT_MASK (0x20U)
#define HDCP_A_APIINTCLR_KSVSHA1CALCDONEINT_SHIFT (5U)
/*! KSVsha1calcdoneint - Clears the interruption related to SHA1 verification has been done */
#define HDCP_A_APIINTCLR_KSVSHA1CALCDONEINT(x)   (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTCLR_KSVSHA1CALCDONEINT_SHIFT)) & HDCP_A_APIINTCLR_KSVSHA1CALCDONEINT_MASK)

#define HDCP_A_APIINTCLR_HDCP_FAILED_MASK        (0x40U)
#define HDCP_A_APIINTCLR_HDCP_FAILED_SHIFT       (6U)
/*! HDCP_failed - Clears the interruption related to HDCP authentication process failed. */
#define HDCP_A_APIINTCLR_HDCP_FAILED(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTCLR_HDCP_FAILED_SHIFT)) & HDCP_A_APIINTCLR_HDCP_FAILED_MASK)

#define HDCP_A_APIINTCLR_HDCP_ENGAGED_MASK       (0x80U)
#define HDCP_A_APIINTCLR_HDCP_ENGAGED_SHIFT      (7U)
/*! HDCP_engaged - Clears the interruption related to HDCP authentication process successful. */
#define HDCP_A_APIINTCLR_HDCP_ENGAGED(x)         (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTCLR_HDCP_ENGAGED_SHIFT)) & HDCP_A_APIINTCLR_HDCP_ENGAGED_MASK)
/*! @} */

/*! @name A_APIINTSTAT - HDCP Interrupt Status Register Read only register, reports the interruption which caused the activation of the interruption output pin. */
/*! @{ */

#define HDCP_A_APIINTSTAT_KSVACCESSINT_MASK      (0x1U)
#define HDCP_A_APIINTSTAT_KSVACCESSINT_SHIFT     (0U)
/*! KSVaccessint - Notifies that the KSV memory access as been guaranteed for Read-Write access. */
#define HDCP_A_APIINTSTAT_KSVACCESSINT(x)        (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTSTAT_KSVACCESSINT_SHIFT)) & HDCP_A_APIINTSTAT_KSVACCESSINT_MASK)

#define HDCP_A_APIINTSTAT_KEEPOUTERRORINT_MASK   (0x4U)
#define HDCP_A_APIINTSTAT_KEEPOUTERRORINT_SHIFT  (2U)
/*! Keepouterrorint - Notifies that during the keep out window, the ctlout[3:0] bus was used besides control period. */
#define HDCP_A_APIINTSTAT_KEEPOUTERRORINT(x)     (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTSTAT_KEEPOUTERRORINT_SHIFT)) & HDCP_A_APIINTSTAT_KEEPOUTERRORINT_MASK)

#define HDCP_A_APIINTSTAT_LOSTARBITRATION_MASK   (0x8U)
#define HDCP_A_APIINTSTAT_LOSTARBITRATION_SHIFT  (3U)
/*! Lostarbitration - Notifies that the I2C lost the arbitration to communicate. */
#define HDCP_A_APIINTSTAT_LOSTARBITRATION(x)     (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTSTAT_LOSTARBITRATION_SHIFT)) & HDCP_A_APIINTSTAT_LOSTARBITRATION_MASK)

#define HDCP_A_APIINTSTAT_I2CNACK_MASK           (0x10U)
#define HDCP_A_APIINTSTAT_I2CNACK_SHIFT          (4U)
/*! I2Cnack - Notifies that the I2C received a NACK from slave device. */
#define HDCP_A_APIINTSTAT_I2CNACK(x)             (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTSTAT_I2CNACK_SHIFT)) & HDCP_A_APIINTSTAT_I2CNACK_MASK)

#define HDCP_A_APIINTSTAT_KSVSHA1CALCDONEINT_MASK (0x20U)
#define HDCP_A_APIINTSTAT_KSVSHA1CALCDONEINT_SHIFT (5U)
/*! KSVsha1calcdoneint - Notifies that the HDCP13TCTRL block SHA1 verification has been done. */
#define HDCP_A_APIINTSTAT_KSVSHA1CALCDONEINT(x)  (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTSTAT_KSVSHA1CALCDONEINT_SHIFT)) & HDCP_A_APIINTSTAT_KSVSHA1CALCDONEINT_MASK)

#define HDCP_A_APIINTSTAT_HDCP_FAILED_MASK       (0x40U)
#define HDCP_A_APIINTSTAT_HDCP_FAILED_SHIFT      (6U)
/*! HDCP_failed - Notifies that the HDCP authentication process was failed. */
#define HDCP_A_APIINTSTAT_HDCP_FAILED(x)         (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTSTAT_HDCP_FAILED_SHIFT)) & HDCP_A_APIINTSTAT_HDCP_FAILED_MASK)

#define HDCP_A_APIINTSTAT_HDCP_ENGAGED_MASK      (0x80U)
#define HDCP_A_APIINTSTAT_HDCP_ENGAGED_SHIFT     (7U)
/*! HDCP_engaged - Notifies that the HDCP authentication process was successful */
#define HDCP_A_APIINTSTAT_HDCP_ENGAGED(x)        (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTSTAT_HDCP_ENGAGED_SHIFT)) & HDCP_A_APIINTSTAT_HDCP_ENGAGED_MASK)
/*! @} */

/*! @name A_APIINTMSK - HDCP Interrupt Mask Register The configuration of this register mask a given setup of interruption, disabling them from generating interruption pulses in the interruption output pin. */
/*! @{ */

#define HDCP_A_APIINTMSK_KSVACCESSINT_MASK       (0x1U)
#define HDCP_A_APIINTMSK_KSVACCESSINT_SHIFT      (0U)
/*! KSVaccessint - Masks the interruption related to KSV memory access grant for Read-Write access. */
#define HDCP_A_APIINTMSK_KSVACCESSINT(x)         (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTMSK_KSVACCESSINT_SHIFT)) & HDCP_A_APIINTMSK_KSVACCESSINT_MASK)

#define HDCP_A_APIINTMSK_SPARE_MASK              (0x2U)
#define HDCP_A_APIINTMSK_SPARE_SHIFT             (1U)
/*! spare - Reserved as "spare" register with no associated functionality. */
#define HDCP_A_APIINTMSK_SPARE(x)                (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTMSK_SPARE_SHIFT)) & HDCP_A_APIINTMSK_SPARE_MASK)

#define HDCP_A_APIINTMSK_KEEPOUTERRORINT_MASK    (0x4U)
#define HDCP_A_APIINTMSK_KEEPOUTERRORINT_SHIFT   (2U)
/*! Keepouterrorint - Masks the interruption related to keep out window error. */
#define HDCP_A_APIINTMSK_KEEPOUTERRORINT(x)      (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTMSK_KEEPOUTERRORINT_SHIFT)) & HDCP_A_APIINTMSK_KEEPOUTERRORINT_MASK)

#define HDCP_A_APIINTMSK_LOSTARBITRATION_MASK    (0x8U)
#define HDCP_A_APIINTMSK_LOSTARBITRATION_SHIFT   (3U)
/*! Lostarbitration - Masks the interruption related to I2C arbitration lost. */
#define HDCP_A_APIINTMSK_LOSTARBITRATION(x)      (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTMSK_LOSTARBITRATION_SHIFT)) & HDCP_A_APIINTMSK_LOSTARBITRATION_MASK)

#define HDCP_A_APIINTMSK_I2CNACK_MASK            (0x10U)
#define HDCP_A_APIINTMSK_I2CNACK_SHIFT           (4U)
/*! I2Cnack - Masks the interruption related to I2C NACK reception. */
#define HDCP_A_APIINTMSK_I2CNACK(x)              (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTMSK_I2CNACK_SHIFT)) & HDCP_A_APIINTMSK_I2CNACK_MASK)

#define HDCP_A_APIINTMSK_KSVSHA1CALCDONEINT_MASK (0x20U)
#define HDCP_A_APIINTMSK_KSVSHA1CALCDONEINT_SHIFT (5U)
/*! KSVsha1calcdoneint - Masks the interruption related to SHA1 verification has been done */
#define HDCP_A_APIINTMSK_KSVSHA1CALCDONEINT(x)   (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTMSK_KSVSHA1CALCDONEINT_SHIFT)) & HDCP_A_APIINTMSK_KSVSHA1CALCDONEINT_MASK)

#define HDCP_A_APIINTMSK_HDCP_FAILED_MASK        (0x40U)
#define HDCP_A_APIINTMSK_HDCP_FAILED_SHIFT       (6U)
/*! HDCP_failed - Masks the interruption related to HDCP authentication process failed. */
#define HDCP_A_APIINTMSK_HDCP_FAILED(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTMSK_HDCP_FAILED_SHIFT)) & HDCP_A_APIINTMSK_HDCP_FAILED_MASK)

#define HDCP_A_APIINTMSK_HDCP_ENGAGED_MASK       (0x80U)
#define HDCP_A_APIINTMSK_HDCP_ENGAGED_SHIFT      (7U)
/*! HDCP_engaged - Masks the interruption related to HDCP authentication process successful. */
#define HDCP_A_APIINTMSK_HDCP_ENGAGED(x)         (((uint8_t)(((uint8_t)(x)) << HDCP_A_APIINTMSK_HDCP_ENGAGED_SHIFT)) & HDCP_A_APIINTMSK_HDCP_ENGAGED_MASK)
/*! @} */

/*! @name A_VIDPOLCFG - HDCP Video Polarity Configuration Register */
/*! @{ */

#define HDCP_A_VIDPOLCFG_SPARE_1_MASK            (0x1U)
#define HDCP_A_VIDPOLCFG_SPARE_1_SHIFT           (0U)
/*! spare_1 - Reserved as "spare" bit with no associated functionality. */
#define HDCP_A_VIDPOLCFG_SPARE_1(x)              (((uint8_t)(((uint8_t)(x)) << HDCP_A_VIDPOLCFG_SPARE_1_SHIFT)) & HDCP_A_VIDPOLCFG_SPARE_1_MASK)

#define HDCP_A_VIDPOLCFG_HSYNCPOL_MASK           (0x2U)
#define HDCP_A_VIDPOLCFG_HSYNCPOL_SHIFT          (1U)
/*! hsyncpol - Configuration of the video Horizontal synchronism polarity. */
#define HDCP_A_VIDPOLCFG_HSYNCPOL(x)             (((uint8_t)(((uint8_t)(x)) << HDCP_A_VIDPOLCFG_HSYNCPOL_SHIFT)) & HDCP_A_VIDPOLCFG_HSYNCPOL_MASK)

#define HDCP_A_VIDPOLCFG_SPARE_2_MASK            (0x4U)
#define HDCP_A_VIDPOLCFG_SPARE_2_SHIFT           (2U)
/*! spare_2 - Reserved as "spare" bit with no associated functionality. */
#define HDCP_A_VIDPOLCFG_SPARE_2(x)              (((uint8_t)(((uint8_t)(x)) << HDCP_A_VIDPOLCFG_SPARE_2_SHIFT)) & HDCP_A_VIDPOLCFG_SPARE_2_MASK)

#define HDCP_A_VIDPOLCFG_VSYNCPOL_MASK           (0x8U)
#define HDCP_A_VIDPOLCFG_VSYNCPOL_SHIFT          (3U)
/*! vsyncpol - Configuration of the video Vertical synchronism polarity */
#define HDCP_A_VIDPOLCFG_VSYNCPOL(x)             (((uint8_t)(((uint8_t)(x)) << HDCP_A_VIDPOLCFG_VSYNCPOL_SHIFT)) & HDCP_A_VIDPOLCFG_VSYNCPOL_MASK)

#define HDCP_A_VIDPOLCFG_DATAENPOL_MASK          (0x10U)
#define HDCP_A_VIDPOLCFG_DATAENPOL_SHIFT         (4U)
/*! dataenpol - Configuration of the video data enable polarity */
#define HDCP_A_VIDPOLCFG_DATAENPOL(x)            (((uint8_t)(((uint8_t)(x)) << HDCP_A_VIDPOLCFG_DATAENPOL_SHIFT)) & HDCP_A_VIDPOLCFG_DATAENPOL_MASK)

#define HDCP_A_VIDPOLCFG_UNENCRYPTCONF_MASK      (0x60U)
#define HDCP_A_VIDPOLCFG_UNENCRYPTCONF_SHIFT     (5U)
/*! unencryptconf - Configuration of the color sent when sending unencrypted video data For a
 *    complete table showing the color results (RGB), refer to the "Color Configuration When Sending
 *    Unencrypted Video Data" figure in Chapter 2, "Functional Description.
 */
#define HDCP_A_VIDPOLCFG_UNENCRYPTCONF(x)        (((uint8_t)(((uint8_t)(x)) << HDCP_A_VIDPOLCFG_UNENCRYPTCONF_SHIFT)) & HDCP_A_VIDPOLCFG_UNENCRYPTCONF_MASK)
/*! @} */

/*! @name A_OESSWCFG - HDCP OESS WOO Configuration Register Pulse width of the encryption enable (CTL3) signal in the HDCP OESS mode. */
/*! @{ */

#define HDCP_A_OESSWCFG_A_OESSWCFG_MASK          (0xFFU)
#define HDCP_A_OESSWCFG_A_OESSWCFG_SHIFT         (0U)
/*! a_oesswcfg - HDCP OESS WOO Configuration Register */
#define HDCP_A_OESSWCFG_A_OESSWCFG(x)            (((uint8_t)(((uint8_t)(x)) << HDCP_A_OESSWCFG_A_OESSWCFG_SHIFT)) & HDCP_A_OESSWCFG_A_OESSWCFG_MASK)
/*! @} */

/*! @name A_COREVERLSB - HDCP Controller Version Register LSB Design ID number. */
/*! @{ */

#define HDCP_A_COREVERLSB_A_COREVERLSB_MASK      (0xFFU)
#define HDCP_A_COREVERLSB_A_COREVERLSB_SHIFT     (0U)
/*! a_coreverlsb - HDCP Controller Version Register LSB */
#define HDCP_A_COREVERLSB_A_COREVERLSB(x)        (((uint8_t)(((uint8_t)(x)) << HDCP_A_COREVERLSB_A_COREVERLSB_SHIFT)) & HDCP_A_COREVERLSB_A_COREVERLSB_MASK)
/*! @} */

/*! @name A_COREVERMSB - HDCP Controller Version Register MSB Revision ID number. */
/*! @{ */

#define HDCP_A_COREVERMSB_A_COREVERMSB_MASK      (0xFFU)
#define HDCP_A_COREVERMSB_A_COREVERMSB_SHIFT     (0U)
/*! a_corevermsb - HDCP Controller Version Register MSB */
#define HDCP_A_COREVERMSB_A_COREVERMSB(x)        (((uint8_t)(((uint8_t)(x)) << HDCP_A_COREVERMSB_A_COREVERMSB_SHIFT)) & HDCP_A_COREVERMSB_A_COREVERMSB_MASK)
/*! @} */

/*! @name A_KSVMEMCTRL - HDCP KSV Memory Control Register The KSVCTRLupd bit is a notification flag. */
/*! @{ */

#define HDCP_A_KSVMEMCTRL_KSVMEMREQUEST_MASK     (0x1U)
#define HDCP_A_KSVMEMCTRL_KSVMEMREQUEST_SHIFT    (0U)
/*! KSVMEMrequest - Request access to the KSV memory; must be de-asserted after the access is completed by the system. */
#define HDCP_A_KSVMEMCTRL_KSVMEMREQUEST(x)       (((uint8_t)(((uint8_t)(x)) << HDCP_A_KSVMEMCTRL_KSVMEMREQUEST_SHIFT)) & HDCP_A_KSVMEMCTRL_KSVMEMREQUEST_MASK)

#define HDCP_A_KSVMEMCTRL_KSVMEMACCESS_MASK      (0x2U)
#define HDCP_A_KSVMEMCTRL_KSVMEMACCESS_SHIFT     (1U)
/*! KSVMEMaccess - Notification that the KSV memory access as been guaranteed. */
#define HDCP_A_KSVMEMCTRL_KSVMEMACCESS(x)        (((uint8_t)(((uint8_t)(x)) << HDCP_A_KSVMEMCTRL_KSVMEMACCESS_SHIFT)) & HDCP_A_KSVMEMCTRL_KSVMEMACCESS_MASK)

#define HDCP_A_KSVMEMCTRL_KSVCTRLUPD_MASK        (0x4U)
#define HDCP_A_KSVMEMCTRL_KSVCTRLUPD_SHIFT       (2U)
/*! KSVCTRLupd - Set to inform that the KSV list in memory has been analyzed and the response to the
 *    Message Digest has been updated if on configurations on software SHA-1 calculation.
 */
#define HDCP_A_KSVMEMCTRL_KSVCTRLUPD(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_A_KSVMEMCTRL_KSVCTRLUPD_SHIFT)) & HDCP_A_KSVMEMCTRL_KSVCTRLUPD_MASK)

#define HDCP_A_KSVMEMCTRL_KSVSHA1STATUS_MASK     (0x10U)
#define HDCP_A_KSVMEMCTRL_KSVSHA1STATUS_SHIFT    (4U)
/*! KSVsha1status - Notification whether the KSV list message digest is correct from the controller:
 *    1'b1 if digest message verification failed 1'b0 if digest message verification succeeded
 */
#define HDCP_A_KSVMEMCTRL_KSVSHA1STATUS(x)       (((uint8_t)(((uint8_t)(x)) << HDCP_A_KSVMEMCTRL_KSVSHA1STATUS_SHIFT)) & HDCP_A_KSVMEMCTRL_KSVSHA1STATUS_MASK)
/*! @} */

/*! @name HDCP_REVOC_SIZE_0 - HDCP Revocation KSV List Size Register 0 */
/*! @{ */

#define HDCP_HDCP_REVOC_SIZE_0_HDCP_REVOC_SIZE_0_MASK (0xFFU)
#define HDCP_HDCP_REVOC_SIZE_0_HDCP_REVOC_SIZE_0_SHIFT (0U)
/*! hdcp_revoc_size_0 - Register containing the LSB of KSV list size (ksv_list_size[7:0]). */
#define HDCP_HDCP_REVOC_SIZE_0_HDCP_REVOC_SIZE_0(x) (((uint8_t)(((uint8_t)(x)) << HDCP_HDCP_REVOC_SIZE_0_HDCP_REVOC_SIZE_0_SHIFT)) & HDCP_HDCP_REVOC_SIZE_0_HDCP_REVOC_SIZE_0_MASK)
/*! @} */

/*! @name HDCP_REVOC_SIZE_1 - HDCP Revocation KSV List Size Register 1 */
/*! @{ */

#define HDCP_HDCP_REVOC_SIZE_1_HDCP_REVOC_SIZE_1_MASK (0xFFU)
#define HDCP_HDCP_REVOC_SIZE_1_HDCP_REVOC_SIZE_1_SHIFT (0U)
/*! hdcp_revoc_size_1 - Register containing the MSB of KSV list size (ksv_list_size[15:8]). */
#define HDCP_HDCP_REVOC_SIZE_1_HDCP_REVOC_SIZE_1(x) (((uint8_t)(((uint8_t)(x)) << HDCP_HDCP_REVOC_SIZE_1_HDCP_REVOC_SIZE_1_SHIFT)) & HDCP_HDCP_REVOC_SIZE_1_HDCP_REVOC_SIZE_1_MASK)
/*! @} */

/*! @name HDCPREG_BKSV0 - HDCP KSV Status Register 0 */
/*! @{ */

#define HDCP_HDCPREG_BKSV0_HDCPREG_BKSV0_MASK    (0xFFU)
#define HDCP_HDCPREG_BKSV0_HDCPREG_BKSV0_SHIFT   (0U)
/*! hdcpreg_bksv0 - Contains the value of BKSV[7:0]. */
#define HDCP_HDCPREG_BKSV0_HDCPREG_BKSV0(x)      (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_BKSV0_HDCPREG_BKSV0_SHIFT)) & HDCP_HDCPREG_BKSV0_HDCPREG_BKSV0_MASK)
/*! @} */

/*! @name HDCPREG_BKSV1 - HDCP KSV Status Register 1 */
/*! @{ */

#define HDCP_HDCPREG_BKSV1_HDCPREG_BKSV1_MASK    (0xFFU)
#define HDCP_HDCPREG_BKSV1_HDCPREG_BKSV1_SHIFT   (0U)
/*! hdcpreg_bksv1 - Contains the value of BKSV[15:8]. */
#define HDCP_HDCPREG_BKSV1_HDCPREG_BKSV1(x)      (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_BKSV1_HDCPREG_BKSV1_SHIFT)) & HDCP_HDCPREG_BKSV1_HDCPREG_BKSV1_MASK)
/*! @} */

/*! @name HDCPREG_BKSV2 - HDCP KSV Status Register 2 */
/*! @{ */

#define HDCP_HDCPREG_BKSV2_HDCPREG_BKSV2_MASK    (0xFFU)
#define HDCP_HDCPREG_BKSV2_HDCPREG_BKSV2_SHIFT   (0U)
/*! hdcpreg_bksv2 - Contains the value of BKSV[23:16]. */
#define HDCP_HDCPREG_BKSV2_HDCPREG_BKSV2(x)      (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_BKSV2_HDCPREG_BKSV2_SHIFT)) & HDCP_HDCPREG_BKSV2_HDCPREG_BKSV2_MASK)
/*! @} */

/*! @name HDCPREG_BKSV3 - HDCP KSV Status Register 3 */
/*! @{ */

#define HDCP_HDCPREG_BKSV3_HDCPREG_BKSV3_MASK    (0xFFU)
#define HDCP_HDCPREG_BKSV3_HDCPREG_BKSV3_SHIFT   (0U)
/*! hdcpreg_bksv3 - Contains the value of BKSV[31:24]. */
#define HDCP_HDCPREG_BKSV3_HDCPREG_BKSV3(x)      (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_BKSV3_HDCPREG_BKSV3_SHIFT)) & HDCP_HDCPREG_BKSV3_HDCPREG_BKSV3_MASK)
/*! @} */

/*! @name HDCPREG_BKSV4 - HDCP KSV Status Register 4 */
/*! @{ */

#define HDCP_HDCPREG_BKSV4_HDCPREG_BKSV4_MASK    (0xFFU)
#define HDCP_HDCPREG_BKSV4_HDCPREG_BKSV4_SHIFT   (0U)
/*! hdcpreg_bksv4 - Contains the value of BKSV[39:32]. */
#define HDCP_HDCPREG_BKSV4_HDCPREG_BKSV4(x)      (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_BKSV4_HDCPREG_BKSV4_SHIFT)) & HDCP_HDCPREG_BKSV4_HDCPREG_BKSV4_MASK)
/*! @} */

/*! @name HDCPREG_ANCONF - HDCP AN Bypass Control Register */
/*! @{ */

#define HDCP_HDCPREG_ANCONF_OANBYPASS_MASK       (0x1U)
#define HDCP_HDCPREG_ANCONF_OANBYPASS_SHIFT      (0U)
/*! oanbypass - - When oanbypass=1, the value of AN used in the HDCP engine comes from the hdcpreg_an0 to hdcpreg_an7 registers. */
#define HDCP_HDCPREG_ANCONF_OANBYPASS(x)         (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_ANCONF_OANBYPASS_SHIFT)) & HDCP_HDCPREG_ANCONF_OANBYPASS_MASK)
/*! @} */

/*! @name HDCPREG_AN0 - HDCP Forced AN Register 0 */
/*! @{ */

#define HDCP_HDCPREG_AN0_HDCPREG_AN0_MASK        (0xFFU)
#define HDCP_HDCPREG_AN0_HDCPREG_AN0_SHIFT       (0U)
/*! hdcpreg_an0 - Contains the value of AN[7:0] */
#define HDCP_HDCPREG_AN0_HDCPREG_AN0(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_AN0_HDCPREG_AN0_SHIFT)) & HDCP_HDCPREG_AN0_HDCPREG_AN0_MASK)
/*! @} */

/*! @name HDCPREG_AN1 - HDCP Forced AN Register 1 */
/*! @{ */

#define HDCP_HDCPREG_AN1_HDCPREG_AN1_MASK        (0xFFU)
#define HDCP_HDCPREG_AN1_HDCPREG_AN1_SHIFT       (0U)
/*! hdcpreg_an1 - Contains the value of AN[15:8] */
#define HDCP_HDCPREG_AN1_HDCPREG_AN1(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_AN1_HDCPREG_AN1_SHIFT)) & HDCP_HDCPREG_AN1_HDCPREG_AN1_MASK)
/*! @} */

/*! @name HDCPREG_AN2 - HDCP forced AN Register 2 */
/*! @{ */

#define HDCP_HDCPREG_AN2_HDCPREG_AN2_MASK        (0xFFU)
#define HDCP_HDCPREG_AN2_HDCPREG_AN2_SHIFT       (0U)
/*! hdcpreg_an2 - Contains the value of AN[23:16] */
#define HDCP_HDCPREG_AN2_HDCPREG_AN2(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_AN2_HDCPREG_AN2_SHIFT)) & HDCP_HDCPREG_AN2_HDCPREG_AN2_MASK)
/*! @} */

/*! @name HDCPREG_AN3 - HDCP Forced AN Register 3 */
/*! @{ */

#define HDCP_HDCPREG_AN3_HDCPREG_AN3_MASK        (0xFFU)
#define HDCP_HDCPREG_AN3_HDCPREG_AN3_SHIFT       (0U)
/*! hdcpreg_an3 - Contains the value of AN[31:24] */
#define HDCP_HDCPREG_AN3_HDCPREG_AN3(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_AN3_HDCPREG_AN3_SHIFT)) & HDCP_HDCPREG_AN3_HDCPREG_AN3_MASK)
/*! @} */

/*! @name HDCPREG_AN4 - HDCP Forced AN Register 4 */
/*! @{ */

#define HDCP_HDCPREG_AN4_HDCPREG_AN4_MASK        (0xFFU)
#define HDCP_HDCPREG_AN4_HDCPREG_AN4_SHIFT       (0U)
/*! hdcpreg_an4 - Contains the value of AN[39:32] */
#define HDCP_HDCPREG_AN4_HDCPREG_AN4(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_AN4_HDCPREG_AN4_SHIFT)) & HDCP_HDCPREG_AN4_HDCPREG_AN4_MASK)
/*! @} */

/*! @name HDCPREG_AN5 - HDCP Forced AN Register 5 */
/*! @{ */

#define HDCP_HDCPREG_AN5_HDCPREG_AN5_MASK        (0xFFU)
#define HDCP_HDCPREG_AN5_HDCPREG_AN5_SHIFT       (0U)
/*! hdcpreg_an5 - Contains the value of AN[47:40] */
#define HDCP_HDCPREG_AN5_HDCPREG_AN5(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_AN5_HDCPREG_AN5_SHIFT)) & HDCP_HDCPREG_AN5_HDCPREG_AN5_MASK)
/*! @} */

/*! @name HDCPREG_AN6 - HDCP Forced AN Register 6 */
/*! @{ */

#define HDCP_HDCPREG_AN6_HDCPREG_AN6_MASK        (0xFFU)
#define HDCP_HDCPREG_AN6_HDCPREG_AN6_SHIFT       (0U)
/*! hdcpreg_an6 - Contains the value of AN[55:48] */
#define HDCP_HDCPREG_AN6_HDCPREG_AN6(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_AN6_HDCPREG_AN6_SHIFT)) & HDCP_HDCPREG_AN6_HDCPREG_AN6_MASK)
/*! @} */

/*! @name HDCPREG_AN7 - HDCP Forced AN Register 7 */
/*! @{ */

#define HDCP_HDCPREG_AN7_HDCPREG_AN7_MASK        (0xFFU)
#define HDCP_HDCPREG_AN7_HDCPREG_AN7_SHIFT       (0U)
/*! hdcpreg_an7 - Contains the value of BKSV[63:56] */
#define HDCP_HDCPREG_AN7_HDCPREG_AN7(x)          (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_AN7_HDCPREG_AN7_SHIFT)) & HDCP_HDCPREG_AN7_HDCPREG_AN7_MASK)
/*! @} */

/*! @name HDCPREG_RMLCTL - HDCP Encrypted Device Private Keys Control Register This register is the control register for the software programmable encrypted DPK embedded storage feature. */
/*! @{ */

#define HDCP_HDCPREG_RMLCTL_ODPK_DECRYPT_ENABLE_MASK (0x1U)
#define HDCP_HDCPREG_RMLCTL_ODPK_DECRYPT_ENABLE_SHIFT (0U)
/*! odpk_decrypt_enable - When set (1'b1), this bit activates the decryption of the Device Private keys. */
#define HDCP_HDCPREG_RMLCTL_ODPK_DECRYPT_ENABLE(x) (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_RMLCTL_ODPK_DECRYPT_ENABLE_SHIFT)) & HDCP_HDCPREG_RMLCTL_ODPK_DECRYPT_ENABLE_MASK)
/*! @} */

/*! @name HDCPREG_RMLSTS - HDCP Encrypted DPK Status Register The required software configuration sequence is documented in the DesignWare Cores HDMI Transmitter User Guide in the "Programming" chapter, Section 3. */
/*! @{ */

#define HDCP_HDCPREG_RMLSTS_IDPK_DATA_INDEX_MASK (0x3FU)
#define HDCP_HDCPREG_RMLSTS_IDPK_DATA_INDEX_SHIFT (0U)
/*! idpk_data_index - Current Device Private Key being written plus one. */
#define HDCP_HDCPREG_RMLSTS_IDPK_DATA_INDEX(x)   (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_RMLSTS_IDPK_DATA_INDEX_SHIFT)) & HDCP_HDCPREG_RMLSTS_IDPK_DATA_INDEX_MASK)

#define HDCP_HDCPREG_RMLSTS_IDPK_WR_OK_STS_MASK  (0x40U)
#define HDCP_HDCPREG_RMLSTS_IDPK_WR_OK_STS_SHIFT (6U)
/*! idpk_wr_ok_sts - When high (1'b1), it indicates that a DPK write is allowed. */
#define HDCP_HDCPREG_RMLSTS_IDPK_WR_OK_STS(x)    (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_RMLSTS_IDPK_WR_OK_STS_SHIFT)) & HDCP_HDCPREG_RMLSTS_IDPK_WR_OK_STS_MASK)
/*! @} */

/*! @name HDCPREG_SEED0 - HDCP Encrypted DPK Seed Register 0 This register contains a byte of the HDCP Encrypted DPK seed value used to encrypt the Device Private Keys. */
/*! @{ */

#define HDCP_HDCPREG_SEED0_HDCPREG_SEED0_MASK    (0xFFU)
#define HDCP_HDCPREG_SEED0_HDCPREG_SEED0_SHIFT   (0U)
/*! hdcpreg_seed0 - Least significant byte of the decryption seed value (dpk_decrypt_seed[7:0]). */
#define HDCP_HDCPREG_SEED0_HDCPREG_SEED0(x)      (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_SEED0_HDCPREG_SEED0_SHIFT)) & HDCP_HDCPREG_SEED0_HDCPREG_SEED0_MASK)
/*! @} */

/*! @name HDCPREG_SEED1 - HDCP Encrypted DPK Seed Register 1 This register contains a byte of the HDCP Encrypted DPK seed value used to encrypt the Device Private Keys. */
/*! @{ */

#define HDCP_HDCPREG_SEED1_HDCPREG_SEED1_MASK    (0xFFU)
#define HDCP_HDCPREG_SEED1_HDCPREG_SEED1_SHIFT   (0U)
/*! hdcpreg_seed1 - Most significant byte of the decryption seed value (dpk_decrypt_seed[15:8]). */
#define HDCP_HDCPREG_SEED1_HDCPREG_SEED1(x)      (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_SEED1_HDCPREG_SEED1_SHIFT)) & HDCP_HDCPREG_SEED1_HDCPREG_SEED1_MASK)
/*! @} */

/*! @name HDCPREG_DPK0 - HDCP Encrypted DPK Data Register 0 This register contains an HDCP DPK byte. */
/*! @{ */

#define HDCP_HDCPREG_DPK0_DPK_DATA_MASK          (0xFFU)
#define HDCP_HDCPREG_DPK0_DPK_DATA_SHIFT         (0U)
/*! dpk_data - Byte of the encrypted DPK value. */
#define HDCP_HDCPREG_DPK0_DPK_DATA(x)            (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_DPK0_DPK_DATA_SHIFT)) & HDCP_HDCPREG_DPK0_DPK_DATA_MASK)
/*! @} */

/*! @name HDCPREG_DPK1 - HDCP Encrypted DPK Data Register 1 This register contains an HDCP DPK byte. */
/*! @{ */

#define HDCP_HDCPREG_DPK1_DPK_DATA_MASK          (0xFFU)
#define HDCP_HDCPREG_DPK1_DPK_DATA_SHIFT         (0U)
/*! dpk_data - Byte of the encrypted DPK value. */
#define HDCP_HDCPREG_DPK1_DPK_DATA(x)            (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_DPK1_DPK_DATA_SHIFT)) & HDCP_HDCPREG_DPK1_DPK_DATA_MASK)
/*! @} */

/*! @name HDCPREG_DPK2 - HDCP Encrypted DPK Data Register 2 This register contains an HDCP DPK byte. */
/*! @{ */

#define HDCP_HDCPREG_DPK2_DPK_DATA_MASK          (0xFFU)
#define HDCP_HDCPREG_DPK2_DPK_DATA_SHIFT         (0U)
/*! dpk_data - Byte of the encrypted DPK value. */
#define HDCP_HDCPREG_DPK2_DPK_DATA(x)            (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_DPK2_DPK_DATA_SHIFT)) & HDCP_HDCPREG_DPK2_DPK_DATA_MASK)
/*! @} */

/*! @name HDCPREG_DPK3 - HDCP Encrypted DPK Data Register 3 This register contains an HDCP DPK byte. */
/*! @{ */

#define HDCP_HDCPREG_DPK3_DPK_DATA_MASK          (0xFFU)
#define HDCP_HDCPREG_DPK3_DPK_DATA_SHIFT         (0U)
/*! dpk_data - Byte of the encrypted DPK value. */
#define HDCP_HDCPREG_DPK3_DPK_DATA(x)            (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_DPK3_DPK_DATA_SHIFT)) & HDCP_HDCPREG_DPK3_DPK_DATA_MASK)
/*! @} */

/*! @name HDCPREG_DPK4 - HDCP Encrypted DPK Data Register 4 This register contains an HDCP DPK byte. */
/*! @{ */

#define HDCP_HDCPREG_DPK4_DPK_DATA_MASK          (0xFFU)
#define HDCP_HDCPREG_DPK4_DPK_DATA_SHIFT         (0U)
/*! dpk_data - Byte of the encrypted DPK value. */
#define HDCP_HDCPREG_DPK4_DPK_DATA(x)            (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_DPK4_DPK_DATA_SHIFT)) & HDCP_HDCPREG_DPK4_DPK_DATA_MASK)
/*! @} */

/*! @name HDCPREG_DPK5 - HDCP Encrypted DPK Data Register 5 This register contains an HDCP DPK byte. */
/*! @{ */

#define HDCP_HDCPREG_DPK5_DPK_DATA_MASK          (0xFFU)
#define HDCP_HDCPREG_DPK5_DPK_DATA_SHIFT         (0U)
/*! dpk_data - Contains the value of DPK[x][47:40] */
#define HDCP_HDCPREG_DPK5_DPK_DATA(x)            (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_DPK5_DPK_DATA_SHIFT)) & HDCP_HDCPREG_DPK5_DPK_DATA_MASK)
/*! @} */

/*! @name HDCPREG_DPK6 - HDCP Encrypted DPK Data Register 6 This register contains an HDCP DPK byte. */
/*! @{ */

#define HDCP_HDCPREG_DPK6_DPK_DATA_MASK          (0xFFU)
#define HDCP_HDCPREG_DPK6_DPK_DATA_SHIFT         (0U)
/*! dpk_data - Contains the value of DPK[x][55:48] */
#define HDCP_HDCPREG_DPK6_DPK_DATA(x)            (((uint8_t)(((uint8_t)(x)) << HDCP_HDCPREG_DPK6_DPK_DATA_SHIFT)) & HDCP_HDCPREG_DPK6_DPK_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HDCP_Register_Masks */


/*!
 * @}
 */ /* end of group HDCP_Peripheral_Access_Layer */


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


#endif  /* PERI_HDCP_H_ */

