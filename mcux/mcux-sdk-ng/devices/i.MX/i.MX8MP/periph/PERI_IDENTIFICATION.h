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
**         CMSIS Peripheral Access Layer for IDENTIFICATION
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
 * @file PERI_IDENTIFICATION.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IDENTIFICATION
 *
 * CMSIS Peripheral Access Layer for IDENTIFICATION
 */

#if !defined(PERI_IDENTIFICATION_H_)
#define PERI_IDENTIFICATION_H_                   /**< Symbol preventing repeated inclusion */

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
   -- IDENTIFICATION Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IDENTIFICATION_Peripheral_Access_Layer IDENTIFICATION Peripheral Access Layer
 * @{
 */

/** IDENTIFICATION - Register Layout Typedef */
typedef struct {
  __I  uint8_t DESIGN_ID;                          /**< Design Identification Register, offset: 0x0 */
  __I  uint8_t REVISION_ID;                        /**< Revision Identification Register, offset: 0x1 */
  __I  uint8_t PRODUCT_ID0;                        /**< Product Identification Register 0, offset: 0x2 */
  __I  uint8_t PRODUCT_ID1;                        /**< Product Identification Register 1, offset: 0x3 */
  __I  uint8_t CONFIG0_ID;                         /**< Configuration Identification Register 0, offset: 0x4 */
  __I  uint8_t CONFIG1_ID;                         /**< Configuration Identification Register 1, offset: 0x5 */
  __I  uint8_t CONFIG2_ID;                         /**< Configuration Identification Register 2, offset: 0x6 */
  __I  uint8_t CONFIG3_ID;                         /**< Configuration Identification Register 3, offset: 0x7 */
} IDENTIFICATION_Type;

/* ----------------------------------------------------------------------------
   -- IDENTIFICATION Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IDENTIFICATION_Register_Masks IDENTIFICATION Register Masks
 * @{
 */

/*! @name DESIGN_ID - Design Identification Register */
/*! @{ */

#define IDENTIFICATION_DESIGN_ID_design_id_MASK  (0xFFU)
#define IDENTIFICATION_DESIGN_ID_design_id_SHIFT (0U)
/*! design_id - Design ID code fixed by Synopsys that Identifies the instantiated DWC_hdmi_tx controller. */
#define IDENTIFICATION_DESIGN_ID_design_id(x)    (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_DESIGN_ID_design_id_SHIFT)) & IDENTIFICATION_DESIGN_ID_design_id_MASK)
/*! @} */

/*! @name REVISION_ID - Revision Identification Register */
/*! @{ */

#define IDENTIFICATION_REVISION_ID_revision_id_MASK (0xFFU)
#define IDENTIFICATION_REVISION_ID_revision_id_SHIFT (0U)
/*! revision_id - Revision ID code fixed by Synopsys that Identifies the instantiated DWC_hdmi_tx controller. */
#define IDENTIFICATION_REVISION_ID_revision_id(x) (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_REVISION_ID_revision_id_SHIFT)) & IDENTIFICATION_REVISION_ID_revision_id_MASK)
/*! @} */

/*! @name PRODUCT_ID0 - Product Identification Register 0 */
/*! @{ */

#define IDENTIFICATION_PRODUCT_ID0_product_id0_MASK (0xFFU)
#define IDENTIFICATION_PRODUCT_ID0_product_id0_SHIFT (0U)
/*! product_id0 - This one byte fixed code Identifies Synopsys's product line ("A0h" for DWC_hdmi_tx products). */
#define IDENTIFICATION_PRODUCT_ID0_product_id0(x) (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_PRODUCT_ID0_product_id0_SHIFT)) & IDENTIFICATION_PRODUCT_ID0_product_id0_MASK)
/*! @} */

/*! @name PRODUCT_ID1 - Product Identification Register 1 */
/*! @{ */

#define IDENTIFICATION_PRODUCT_ID1_product_id1_tx_MASK (0x1U)
#define IDENTIFICATION_PRODUCT_ID1_product_id1_tx_SHIFT (0U)
/*! product_id1_tx - This bit Identifies Synopsys's DWC_hdmi_tx Controller according to Synopsys product line. */
#define IDENTIFICATION_PRODUCT_ID1_product_id1_tx(x) (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_PRODUCT_ID1_product_id1_tx_SHIFT)) & IDENTIFICATION_PRODUCT_ID1_product_id1_tx_MASK)

#define IDENTIFICATION_PRODUCT_ID1_product_id1_rx_MASK (0x2U)
#define IDENTIFICATION_PRODUCT_ID1_product_id1_rx_SHIFT (1U)
/*! product_id1_rx - This bit Identifies Synopsys's DWC_hdmi_rx Controller according to Synopsys product line. */
#define IDENTIFICATION_PRODUCT_ID1_product_id1_rx(x) (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_PRODUCT_ID1_product_id1_rx_SHIFT)) & IDENTIFICATION_PRODUCT_ID1_product_id1_rx_MASK)

#define IDENTIFICATION_PRODUCT_ID1_product_id1_hdcp_MASK (0xC0U)
#define IDENTIFICATION_PRODUCT_ID1_product_id1_hdcp_SHIFT (6U)
/*! product_id1_hdcp - These bits identify a Synopsys's HDMI Controller with HDCP encryption according to Synopsys product line. */
#define IDENTIFICATION_PRODUCT_ID1_product_id1_hdcp(x) (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_PRODUCT_ID1_product_id1_hdcp_SHIFT)) & IDENTIFICATION_PRODUCT_ID1_product_id1_hdcp_MASK)
/*! @} */

/*! @name CONFIG0_ID - Configuration Identification Register 0 */
/*! @{ */

#define IDENTIFICATION_CONFIG0_ID_hdcp_MASK      (0x1U)
#define IDENTIFICATION_CONFIG0_ID_hdcp_SHIFT     (0U)
/*! hdcp - Indicates if HDCP is present */
#define IDENTIFICATION_CONFIG0_ID_hdcp(x)        (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG0_ID_hdcp_SHIFT)) & IDENTIFICATION_CONFIG0_ID_hdcp_MASK)

#define IDENTIFICATION_CONFIG0_ID_cec_MASK       (0x2U)
#define IDENTIFICATION_CONFIG0_ID_cec_SHIFT      (1U)
/*! cec - Indicates if CEC is present */
#define IDENTIFICATION_CONFIG0_ID_cec(x)         (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG0_ID_cec_SHIFT)) & IDENTIFICATION_CONFIG0_ID_cec_MASK)

#define IDENTIFICATION_CONFIG0_ID_csc_MASK       (0x4U)
#define IDENTIFICATION_CONFIG0_ID_csc_SHIFT      (2U)
/*! csc - Indicates if Color Space Conversion block is present */
#define IDENTIFICATION_CONFIG0_ID_csc(x)         (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG0_ID_csc_SHIFT)) & IDENTIFICATION_CONFIG0_ID_csc_MASK)

#define IDENTIFICATION_CONFIG0_ID_hdmi14_MASK    (0x8U)
#define IDENTIFICATION_CONFIG0_ID_hdmi14_SHIFT   (3U)
/*! hdmi14 - Indicates if HDMI 1. */
#define IDENTIFICATION_CONFIG0_ID_hdmi14(x)      (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG0_ID_hdmi14_SHIFT)) & IDENTIFICATION_CONFIG0_ID_hdmi14_MASK)

#define IDENTIFICATION_CONFIG0_ID_audi2s_MASK    (0x10U)
#define IDENTIFICATION_CONFIG0_ID_audi2s_SHIFT   (4U)
/*! audi2s - Indicates if I2S interface is present */
#define IDENTIFICATION_CONFIG0_ID_audi2s(x)      (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG0_ID_audi2s_SHIFT)) & IDENTIFICATION_CONFIG0_ID_audi2s_MASK)

#define IDENTIFICATION_CONFIG0_ID_audspdif_MASK  (0x20U)
#define IDENTIFICATION_CONFIG0_ID_audspdif_SHIFT (5U)
/*! audspdif - Indicates if the SPDIF audio interface is present */
#define IDENTIFICATION_CONFIG0_ID_audspdif(x)    (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG0_ID_audspdif_SHIFT)) & IDENTIFICATION_CONFIG0_ID_audspdif_MASK)

#define IDENTIFICATION_CONFIG0_ID_prepen_MASK    (0x80U)
#define IDENTIFICATION_CONFIG0_ID_prepen_SHIFT   (7U)
/*! prepen - Indicates if it is possible to use internal pixel repetition */
#define IDENTIFICATION_CONFIG0_ID_prepen(x)      (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG0_ID_prepen_SHIFT)) & IDENTIFICATION_CONFIG0_ID_prepen_MASK)
/*! @} */

/*! @name CONFIG1_ID - Configuration Identification Register 1 */
/*! @{ */

#define IDENTIFICATION_CONFIG1_ID_confapb_MASK   (0x2U)
#define IDENTIFICATION_CONFIG1_ID_confapb_SHIFT  (1U)
/*! confapb - Indicates that configuration interface is APB interface */
#define IDENTIFICATION_CONFIG1_ID_confapb(x)     (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG1_ID_confapb_SHIFT)) & IDENTIFICATION_CONFIG1_ID_confapb_MASK)

#define IDENTIFICATION_CONFIG1_ID_hdmi20_MASK    (0x20U)
#define IDENTIFICATION_CONFIG1_ID_hdmi20_SHIFT   (5U)
/*! hdmi20 - Indicates if HDMI 2. */
#define IDENTIFICATION_CONFIG1_ID_hdmi20(x)      (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG1_ID_hdmi20_SHIFT)) & IDENTIFICATION_CONFIG1_ID_hdmi20_MASK)

#define IDENTIFICATION_CONFIG1_ID_hdcp22_ext_MASK (0x40U)
#define IDENTIFICATION_CONFIG1_ID_hdcp22_ext_SHIFT (6U)
/*! hdcp22_ext - Indicates if external HDCP 2. */
#define IDENTIFICATION_CONFIG1_ID_hdcp22_ext(x)  (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG1_ID_hdcp22_ext_SHIFT)) & IDENTIFICATION_CONFIG1_ID_hdcp22_ext_MASK)
/*! @} */

/*! @name CONFIG2_ID - Configuration Identification Register 2 */
/*! @{ */

#define IDENTIFICATION_CONFIG2_ID_phytype_MASK   (0xFFU)
#define IDENTIFICATION_CONFIG2_ID_phytype_SHIFT  (0U)
/*! phytype - Indicates the type of PHY interface selected: 0x00: Legacy PHY (HDMI TX PHY) 0xF2: PHY
 *    GEN2 (HDMI 3D TX PHY) 0xE2: PHY GEN2 (HDMI 3D TX PHY) + HEAC PHY 0xC2: PHY MHL COMBO
 *    (MHL+HDMI 2.
 */
#define IDENTIFICATION_CONFIG2_ID_phytype(x)     (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG2_ID_phytype_SHIFT)) & IDENTIFICATION_CONFIG2_ID_phytype_MASK)
/*! @} */

/*! @name CONFIG3_ID - Configuration Identification Register 3 */
/*! @{ */

#define IDENTIFICATION_CONFIG3_ID_confgpaud_MASK (0x1U)
#define IDENTIFICATION_CONFIG3_ID_confgpaud_SHIFT (0U)
/*! confgpaud - Indicates that the audio interface is Generic Parallel Audio (GPAUD) */
#define IDENTIFICATION_CONFIG3_ID_confgpaud(x)   (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG3_ID_confgpaud_SHIFT)) & IDENTIFICATION_CONFIG3_ID_confgpaud_MASK)

#define IDENTIFICATION_CONFIG3_ID_confahbauddma_MASK (0x2U)
#define IDENTIFICATION_CONFIG3_ID_confahbauddma_SHIFT (1U)
/*! confahbauddma - Indicates that the audio interface is AHB AUD DMA */
#define IDENTIFICATION_CONFIG3_ID_confahbauddma(x) (((uint8_t)(((uint8_t)(x)) << IDENTIFICATION_CONFIG3_ID_confahbauddma_SHIFT)) & IDENTIFICATION_CONFIG3_ID_confahbauddma_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IDENTIFICATION_Register_Masks */


/*!
 * @}
 */ /* end of group IDENTIFICATION_Peripheral_Access_Layer */


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


#endif  /* PERI_IDENTIFICATION_H_ */

