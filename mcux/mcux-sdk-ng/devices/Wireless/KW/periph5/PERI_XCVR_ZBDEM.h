/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XCVR_ZBDEM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file XCVR_ZBDEM.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for XCVR_ZBDEM
 *
 * CMSIS Peripheral Access Layer for XCVR_ZBDEM
 */

#if !defined(XCVR_ZBDEM_H_)
#define XCVR_ZBDEM_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
   -- XCVR_ZBDEM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_ZBDEM_Peripheral_Access_Layer XCVR_ZBDEM Peripheral Access Layer
 * @{
 */

/** XCVR_ZBDEM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CORR_CTRL;                         /**< 802.15.4 DEMOD CORRELLATOR CONTROL, offset: 0x0 */
  __IO uint32_t PN_TYPE;                           /**< 802.15.4 DEMOD PN TYPE, offset: 0x4 */
  __IO uint32_t PN_CODE;                           /**< 802.15.4 DEMOD PN CODE, offset: 0x8 */
  __IO uint32_t SYNC_CTRL;                         /**< 802.15.4 DEMOD SYMBOL SYNC CONTROL, offset: 0xC */
  __IO uint32_t CCA_LQI_SRC;                       /**< 802.15.4 CCA/LQI SOURCE, offset: 0x10 */
  __IO uint32_t FAD_THR;                           /**< FAD CORRELATOR THRESHOLD, offset: 0x14 */
  __IO uint32_t ZBDEM_AFC;                         /**< 802.15.4 AFC STATUS, offset: 0x18 */
} XCVR_ZBDEM_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_ZBDEM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_ZBDEM_Register_Masks XCVR_ZBDEM Register Masks
 * @{
 */

/*! @name CORR_CTRL - 802.15.4 DEMOD CORRELLATOR CONTROL */
/*! @{ */

#define XCVR_ZBDEM_CORR_CTRL_CORR_VT_MASK        (0xFFU)
#define XCVR_ZBDEM_CORR_CTRL_CORR_VT_SHIFT       (0U)
/*! CORR_VT - CORR_VT */
#define XCVR_ZBDEM_CORR_CTRL_CORR_VT(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_CORR_CTRL_CORR_VT_SHIFT)) & XCVR_ZBDEM_CORR_CTRL_CORR_VT_MASK)

#define XCVR_ZBDEM_CORR_CTRL_CORR_NVAL_MASK      (0x700U)
#define XCVR_ZBDEM_CORR_CTRL_CORR_NVAL_SHIFT     (8U)
/*! CORR_NVAL - CORR_NVAL */
#define XCVR_ZBDEM_CORR_CTRL_CORR_NVAL(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_CORR_CTRL_CORR_NVAL_SHIFT)) & XCVR_ZBDEM_CORR_CTRL_CORR_NVAL_MASK)

#define XCVR_ZBDEM_CORR_CTRL_MAX_CORR_EN_MASK    (0x800U)
#define XCVR_ZBDEM_CORR_CTRL_MAX_CORR_EN_SHIFT   (11U)
/*! MAX_CORR_EN - MAX_CORR_EN */
#define XCVR_ZBDEM_CORR_CTRL_MAX_CORR_EN(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_CORR_CTRL_MAX_CORR_EN_SHIFT)) & XCVR_ZBDEM_CORR_CTRL_MAX_CORR_EN_MASK)

#define XCVR_ZBDEM_CORR_CTRL_ZBDEM_CLK_ON_MASK   (0x8000U)
#define XCVR_ZBDEM_CORR_CTRL_ZBDEM_CLK_ON_SHIFT  (15U)
/*! ZBDEM_CLK_ON - Force 802.15.4 Demodulator Clock On
 *  0b0..Normal Operation
 *  0b1..Force 802.15.4 Demodulator Clock On (debug purposes only)
 */
#define XCVR_ZBDEM_CORR_CTRL_ZBDEM_CLK_ON(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_CORR_CTRL_ZBDEM_CLK_ON_SHIFT)) & XCVR_ZBDEM_CORR_CTRL_ZBDEM_CLK_ON_MASK)

#define XCVR_ZBDEM_CORR_CTRL_RX_MAX_CORR_MASK    (0xFF0000U)
#define XCVR_ZBDEM_CORR_CTRL_RX_MAX_CORR_SHIFT   (16U)
/*! RX_MAX_CORR - RX_MAX_CORR */
#define XCVR_ZBDEM_CORR_CTRL_RX_MAX_CORR(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_CORR_CTRL_RX_MAX_CORR_SHIFT)) & XCVR_ZBDEM_CORR_CTRL_RX_MAX_CORR_MASK)

#define XCVR_ZBDEM_CORR_CTRL_RX_MAX_PREAMBLE_MASK (0xFF000000U)
#define XCVR_ZBDEM_CORR_CTRL_RX_MAX_PREAMBLE_SHIFT (24U)
/*! RX_MAX_PREAMBLE - RX_MAX_PREAMBLE */
#define XCVR_ZBDEM_CORR_CTRL_RX_MAX_PREAMBLE(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_CORR_CTRL_RX_MAX_PREAMBLE_SHIFT)) & XCVR_ZBDEM_CORR_CTRL_RX_MAX_PREAMBLE_MASK)
/*! @} */

/*! @name PN_TYPE - 802.15.4 DEMOD PN TYPE */
/*! @{ */

#define XCVR_ZBDEM_PN_TYPE_PN_TYPE_MASK          (0x1U)
#define XCVR_ZBDEM_PN_TYPE_PN_TYPE_SHIFT         (0U)
/*! PN_TYPE - PN_TYPE */
#define XCVR_ZBDEM_PN_TYPE_PN_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_PN_TYPE_PN_TYPE_SHIFT)) & XCVR_ZBDEM_PN_TYPE_PN_TYPE_MASK)

#define XCVR_ZBDEM_PN_TYPE_TX_INV_MASK           (0x2U)
#define XCVR_ZBDEM_PN_TYPE_TX_INV_SHIFT          (1U)
/*! TX_INV - TX_INV */
#define XCVR_ZBDEM_PN_TYPE_TX_INV(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_PN_TYPE_TX_INV_SHIFT)) & XCVR_ZBDEM_PN_TYPE_TX_INV_MASK)
/*! @} */

/*! @name PN_CODE - 802.15.4 DEMOD PN CODE */
/*! @{ */

#define XCVR_ZBDEM_PN_CODE_PN_LSB_MASK           (0xFFFFU)
#define XCVR_ZBDEM_PN_CODE_PN_LSB_SHIFT          (0U)
/*! PN_LSB - PN_LSB */
#define XCVR_ZBDEM_PN_CODE_PN_LSB(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_PN_CODE_PN_LSB_SHIFT)) & XCVR_ZBDEM_PN_CODE_PN_LSB_MASK)

#define XCVR_ZBDEM_PN_CODE_PN_MSB_MASK           (0xFFFF0000U)
#define XCVR_ZBDEM_PN_CODE_PN_MSB_SHIFT          (16U)
/*! PN_MSB - PN_MSB */
#define XCVR_ZBDEM_PN_CODE_PN_MSB(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_PN_CODE_PN_MSB_SHIFT)) & XCVR_ZBDEM_PN_CODE_PN_MSB_MASK)
/*! @} */

/*! @name SYNC_CTRL - 802.15.4 DEMOD SYMBOL SYNC CONTROL */
/*! @{ */

#define XCVR_ZBDEM_SYNC_CTRL_SYNC_PER_MASK       (0x7U)
#define XCVR_ZBDEM_SYNC_CTRL_SYNC_PER_SHIFT      (0U)
/*! SYNC_PER - Symbol Sync Tracking Period */
#define XCVR_ZBDEM_SYNC_CTRL_SYNC_PER(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_SYNC_CTRL_SYNC_PER_SHIFT)) & XCVR_ZBDEM_SYNC_CTRL_SYNC_PER_MASK)

#define XCVR_ZBDEM_SYNC_CTRL_TRACK_ENABLE_MASK   (0x8U)
#define XCVR_ZBDEM_SYNC_CTRL_TRACK_ENABLE_SHIFT  (3U)
/*! TRACK_ENABLE - TRACK_ENABLE
 *  0b0..symbol timing synchronization tracking disabled in Rx frontend
 *  0b1..symbol timing synchronization tracking enabled in Rx frontend (default)
 */
#define XCVR_ZBDEM_SYNC_CTRL_TRACK_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_SYNC_CTRL_TRACK_ENABLE_SHIFT)) & XCVR_ZBDEM_SYNC_CTRL_TRACK_ENABLE_MASK)
/*! @} */

/*! @name CCA_LQI_SRC - 802.15.4 CCA/LQI SOURCE */
/*! @{ */

#define XCVR_ZBDEM_CCA_LQI_SRC_CCA1_FROM_RX_DIG_MASK (0x1U)
#define XCVR_ZBDEM_CCA_LQI_SRC_CCA1_FROM_RX_DIG_SHIFT (0U)
/*! CCA1_FROM_RX_DIG - Selects the Source of CCA1 (Clear Channel Assessment Mode 1) Information Provided to the 802.15.4 Link Layer
 *  0b0..Use the CCA1 information computed internally in the 802.15.4 Demod
 *  0b1..Use the CCA1 information computed by the RX Digital
 */
#define XCVR_ZBDEM_CCA_LQI_SRC_CCA1_FROM_RX_DIG(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_CCA_LQI_SRC_CCA1_FROM_RX_DIG_SHIFT)) & XCVR_ZBDEM_CCA_LQI_SRC_CCA1_FROM_RX_DIG_MASK)

#define XCVR_ZBDEM_CCA_LQI_SRC_LQI_FROM_RX_DIG_MASK (0x2U)
#define XCVR_ZBDEM_CCA_LQI_SRC_LQI_FROM_RX_DIG_SHIFT (1U)
/*! LQI_FROM_RX_DIG - Selects the Source of LQI (Link Quality Indicator) Information Provided to the 802.15.4 Link Layer
 *  0b0..Use the LQI information computed internally in the 802.15.4 Demod
 *  0b1..Use the LQI information computed by the RX Digital
 */
#define XCVR_ZBDEM_CCA_LQI_SRC_LQI_FROM_RX_DIG(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_CCA_LQI_SRC_LQI_FROM_RX_DIG_SHIFT)) & XCVR_ZBDEM_CCA_LQI_SRC_LQI_FROM_RX_DIG_MASK)

#define XCVR_ZBDEM_CCA_LQI_SRC_LQI_START_AT_SFD_MASK (0x4U)
#define XCVR_ZBDEM_CCA_LQI_SRC_LQI_START_AT_SFD_SHIFT (2U)
/*! LQI_START_AT_SFD - Select Start Point for LQI Computation
 *  0b0..Start LQI computation at Preamble Detection (similar to previous Freescale 802.15.4 products)
 *  0b1..Start LQI computation at SFD (Start of Frame Delimiter) Detection
 */
#define XCVR_ZBDEM_CCA_LQI_SRC_LQI_START_AT_SFD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_CCA_LQI_SRC_LQI_START_AT_SFD_SHIFT)) & XCVR_ZBDEM_CCA_LQI_SRC_LQI_START_AT_SFD_MASK)
/*! @} */

/*! @name FAD_THR - FAD CORRELATOR THRESHOLD */
/*! @{ */

#define XCVR_ZBDEM_FAD_THR_FAD_THR_MASK          (0xFFU)
#define XCVR_ZBDEM_FAD_THR_FAD_THR_SHIFT         (0U)
/*! FAD_THR - FAD_THR */
#define XCVR_ZBDEM_FAD_THR_FAD_THR(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_FAD_THR_FAD_THR_SHIFT)) & XCVR_ZBDEM_FAD_THR_FAD_THR_MASK)
/*! @} */

/*! @name ZBDEM_AFC - 802.15.4 AFC STATUS */
/*! @{ */

#define XCVR_ZBDEM_ZBDEM_AFC_AFC_EN_MASK         (0x1U)
#define XCVR_ZBDEM_ZBDEM_AFC_AFC_EN_SHIFT        (0U)
/*! AFC_EN - AFC_EN
 *  0b0..AFC is disabled
 *  0b1..AFC is enabled
 */
#define XCVR_ZBDEM_ZBDEM_AFC_AFC_EN(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_ZBDEM_AFC_AFC_EN_SHIFT)) & XCVR_ZBDEM_ZBDEM_AFC_AFC_EN_MASK)

#define XCVR_ZBDEM_ZBDEM_AFC_DCD_EN_MASK         (0x2U)
#define XCVR_ZBDEM_ZBDEM_AFC_DCD_EN_SHIFT        (1U)
/*! DCD_EN - DCD_EN
 *  0b0..NCD Mode (default)
 *  0b1..DCD Mode
 */
#define XCVR_ZBDEM_ZBDEM_AFC_DCD_EN(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_ZBDEM_AFC_DCD_EN_SHIFT)) & XCVR_ZBDEM_ZBDEM_AFC_DCD_EN_MASK)

#define XCVR_ZBDEM_ZBDEM_AFC_AFC_OUT_MASK        (0x1F00U)
#define XCVR_ZBDEM_ZBDEM_AFC_AFC_OUT_SHIFT       (8U)
/*! AFC_OUT - AFC_OUT */
#define XCVR_ZBDEM_ZBDEM_AFC_AFC_OUT(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_ZBDEM_ZBDEM_AFC_AFC_OUT_SHIFT)) & XCVR_ZBDEM_ZBDEM_AFC_AFC_OUT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_ZBDEM_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_ZBDEM_Peripheral_Access_Layer */


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


#endif  /* XCVR_ZBDEM_H_ */

