/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MU_AP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MU_AP.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MU_AP
 *
 * CMSIS Peripheral Access Layer for MU_AP
 */

#if !defined(PERI_MU_AP_H_)
#define PERI_MU_AP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- MU_AP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MU_AP_Peripheral_Access_Layer MU_AP Peripheral Access Layer
 * @{
 */

/** MU_AP - Size of Registers Arrays */
#define MU_AP_TR_COUNT                            8u
#define MU_AP_RR_COUNT                            8u

/** MU_AP - Register Layout Typedef */
typedef struct {
  __I  uint32_t VER;                               /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PAR;                               /**< Parameter Register, offset: 0x4 */
       uint32_t UNUSED0;                           /**< Unused Register 0, offset: 0x8 */
  __I  uint32_t SR;                                /**< Status Register, offset: 0xC */
       uint8_t RESERVED_0[272];
  __IO uint32_t TCR;                               /**< Transmit Control Register, offset: 0x120 */
  __I  uint32_t TSR;                               /**< Transmit Status Register, offset: 0x124 */
  __IO uint32_t RCR;                               /**< Receive Control Register, offset: 0x128 */
  __I  uint32_t RSR;                               /**< Receive Status Register, offset: 0x12C */
       uint8_t RESERVED_1[204];
  __IO uint32_t UNUSED1;                           /**< Unused Register 1, offset: 0x1FC */
  __IO uint32_t TR[MU_AP_TR_COUNT];                /**< Transmit Register, array offset: 0x200, array step: 0x4, irregular array, not all indices are valid */
       uint8_t RESERVED_2[96];
  __I  uint32_t RR[MU_AP_RR_COUNT];                /**< Receive Register, array offset: 0x280, array step: 0x4, irregular array, not all indices are valid */
       uint8_t RESERVED_3[32];
  __I  uint32_t MUAPA_ATTR;                        /**< MUAPA Host Attributes Register, offset: 0x2C0, available only on: INCL_MU_APPS.MUAPB/SENTINEL__MUB_AP (missing on INCL_MU_APPS.MUAPA/SENTINEL__MUA_AP) */
} MU_AP_Type;

/* ----------------------------------------------------------------------------
   -- MU_AP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MU_AP_Register_Masks MU_AP Register Masks
 * @{
 */

/*! @name VER - Version ID Register */
/*! @{ */

#define MU_AP_VER_FEATURE_MASK                   (0xFFFFU)
#define MU_AP_VER_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Set Number
 *  0b0000000000000000..Standard features are implemented.
 */
#define MU_AP_VER_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << MU_AP_VER_FEATURE_SHIFT)) & MU_AP_VER_FEATURE_MASK)

#define MU_AP_VER_MINOR_MASK                     (0xFF0000U)
#define MU_AP_VER_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number (0x00 ) */
#define MU_AP_VER_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << MU_AP_VER_MINOR_SHIFT)) & MU_AP_VER_MINOR_MASK)

#define MU_AP_VER_MAJOR_MASK                     (0xFF000000U)
#define MU_AP_VER_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number (0x01 ) */
#define MU_AP_VER_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << MU_AP_VER_MAJOR_SHIFT)) & MU_AP_VER_MAJOR_MASK)
/*! @} */

/*! @name PAR - Parameter Register */
/*! @{ */

#define MU_AP_PAR_TR_NUM_MASK                    (0xFFU)
#define MU_AP_PAR_TR_NUM_SHIFT                   (0U)
/*! TR_NUM - Number of Transmit (TRn) registers (8) */
#define MU_AP_PAR_TR_NUM(x)                      (((uint32_t)(((uint32_t)(x)) << MU_AP_PAR_TR_NUM_SHIFT)) & MU_AP_PAR_TR_NUM_MASK)

#define MU_AP_PAR_RR_NUM_MASK                    (0xFF00U)
#define MU_AP_PAR_RR_NUM_SHIFT                   (8U)
/*! RR_NUM - Number of Receive (RRn) registers (8) */
#define MU_AP_PAR_RR_NUM(x)                      (((uint32_t)(((uint32_t)(x)) << MU_AP_PAR_RR_NUM_SHIFT)) & MU_AP_PAR_RR_NUM_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define MU_AP_SR_TEP_MASK                        (0x20U)
#define MU_AP_SR_TEP_SHIFT                       (5U)
/*! TEP - Transmit Empty Pending */
#define MU_AP_SR_TEP(x)                          (((uint32_t)(((uint32_t)(x)) << MU_AP_SR_TEP_SHIFT)) & MU_AP_SR_TEP_MASK)

#define MU_AP_SR_RFP_MASK                        (0x40U)
#define MU_AP_SR_RFP_SHIFT                       (6U)
/*! RFP - Receive Full Pending Flag
 *  0b0..No data is ready to be read. All RSR[RFn] bits are clear.
 *  0b1..Data is ready to be read. One or more RSR[RFn] bits are set.
 */
#define MU_AP_SR_RFP(x)                          (((uint32_t)(((uint32_t)(x)) << MU_AP_SR_RFP_SHIFT)) & MU_AP_SR_RFP_MASK)
/*! @} */

/*! @name TCR - Transmit Control Register */
/*! @{ */

#define MU_AP_TCR_TEIEn_MASK                     (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define MU_AP_TCR_TEIEn_SHIFT                    (0U)
/*! TEIEn - Transmit Register n Empty Interrupt Enable */
#define MU_AP_TCR_TEIEn(x)                       (((uint32_t)(((uint32_t)(x)) << MU_AP_TCR_TEIEn_SHIFT)) & MU_AP_TCR_TEIEn_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name TSR - Transmit Status Register */
/*! @{ */

#define MU_AP_TSR_TEn_MASK                       (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define MU_AP_TSR_TEn_SHIFT                      (0U)
/*! TEn - Transmit Register n Empty */
#define MU_AP_TSR_TEn(x)                         (((uint32_t)(((uint32_t)(x)) << MU_AP_TSR_TEn_SHIFT)) & MU_AP_TSR_TEn_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name RCR - Receive Control Register */
/*! @{ */

#define MU_AP_RCR_RFIEn_MASK                     (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define MU_AP_RCR_RFIEn_SHIFT                    (0U)
/*! RFIEn - Receive Register n Full Interrupt Enable */
#define MU_AP_RCR_RFIEn(x)                       (((uint32_t)(((uint32_t)(x)) << MU_AP_RCR_RFIEn_SHIFT)) & MU_AP_RCR_RFIEn_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name RSR - Receive Status Register */
/*! @{ */

#define MU_AP_RSR_RFn_MASK                       (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define MU_AP_RSR_RFn_SHIFT                      (0U)
/*! RFn - Receive Register n Full */
#define MU_AP_RSR_RFn(x)                         (((uint32_t)(((uint32_t)(x)) << MU_AP_RSR_RFn_SHIFT)) & MU_AP_RSR_RFn_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name UNUSED1 - Unused Register 1 */
/*! @{ */

#define MU_AP_UNUSED1_DATA16_MASK                (0xFFFFU)
#define MU_AP_UNUSED1_DATA16_SHIFT               (0U)
/*! DATA16 - Unused 16-bit Register */
#define MU_AP_UNUSED1_DATA16(x)                  (((uint32_t)(((uint32_t)(x)) << MU_AP_UNUSED1_DATA16_SHIFT)) & MU_AP_UNUSED1_DATA16_MASK)
/*! @} */

/*! @name TR - Transmit Register */
/*! @{ */

#define MU_AP_TR_TR_DATA_MASK                    (0xFFFFFFFFU)
#define MU_AP_TR_TR_DATA_SHIFT                   (0U)
/*! TR_DATA - Transmit Data */
#define MU_AP_TR_TR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << MU_AP_TR_TR_DATA_SHIFT)) & MU_AP_TR_TR_DATA_MASK)
/*! @} */

/*! @name RR - Receive Register */
/*! @{ */

#define MU_AP_RR_RR_DATA_MASK                    (0xFFFFFFFFU)
#define MU_AP_RR_RR_DATA_SHIFT                   (0U)
/*! RR_DATA - Receive Data */
#define MU_AP_RR_RR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << MU_AP_RR_RR_DATA_SHIFT)) & MU_AP_RR_RR_DATA_MASK)
/*! @} */

/*! @name MUAPA_ATTR - MUAPA Host Attributes Register */
/*! @{ */

#define MU_AP_MUAPA_ATTR_DID_MASK                (0xFU)
#define MU_AP_MUAPA_ATTR_DID_SHIFT               (0U)
/*! DID - MUAPA Host Domain ID */
#define MU_AP_MUAPA_ATTR_DID(x)                  (((uint32_t)(((uint32_t)(x)) << MU_AP_MUAPA_ATTR_DID_SHIFT)) & MU_AP_MUAPA_ATTR_DID_MASK)

#define MU_AP_MUAPA_ATTR_PRIV_MASK               (0x40U)
#define MU_AP_MUAPA_ATTR_PRIV_SHIFT              (6U)
/*! PRIV - MUAPA Host Privilege Level
 *  0b0..MUAPA Host access level is user
 *  0b1..MUAPA Host access level is privileged
 */
#define MU_AP_MUAPA_ATTR_PRIV(x)                 (((uint32_t)(((uint32_t)(x)) << MU_AP_MUAPA_ATTR_PRIV_SHIFT)) & MU_AP_MUAPA_ATTR_PRIV_MASK)

#define MU_AP_MUAPA_ATTR_SEC_MASK                (0x80U)
#define MU_AP_MUAPA_ATTR_SEC_SHIFT               (7U)
/*! SEC - MUAPA Host Security Level
 *  0b0..MUAPA Host access level is non-secure
 *  0b1..MUAPA Host access level is secure
 */
#define MU_AP_MUAPA_ATTR_SEC(x)                  (((uint32_t)(((uint32_t)(x)) << MU_AP_MUAPA_ATTR_SEC_SHIFT)) & MU_AP_MUAPA_ATTR_SEC_MASK)

#define MU_AP_MUAPA_ATTR_HOSTNUM_MASK            (0x3F0000U)
#define MU_AP_MUAPA_ATTR_HOSTNUM_SHIFT           (16U)
/*! HOSTNUM - Host Number */
#define MU_AP_MUAPA_ATTR_HOSTNUM(x)              (((uint32_t)(((uint32_t)(x)) << MU_AP_MUAPA_ATTR_HOSTNUM_SHIFT)) & MU_AP_MUAPA_ATTR_HOSTNUM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MU_AP_Register_Masks */


/*!
 * @}
 */ /* end of group MU_AP_Peripheral_Access_Layer */


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


#endif  /* PERI_MU_AP_H_ */

