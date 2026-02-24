/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for S3MU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_S3MU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for S3MU
 *
 * CMSIS Peripheral Access Layer for S3MU
 */

#if !defined(PERI_S3MU_H_)
#define PERI_S3MU_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- S3MU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S3MU_Peripheral_Access_Layer S3MU Peripheral Access Layer
 * @{
 */

/** S3MU - Size of Registers Arrays */
#define S3MU_TR_COUNT                             8u
#define S3MU_RR_COUNT                             8u

/** S3MU - Register Layout Typedef */
typedef struct {
  __I  uint32_t VER;                               /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PAR;                               /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __I  uint32_t SR;                                /**< Status Register, offset: 0xC */
       uint8_t RESERVED_1[240];
  __IO uint32_t FCR;                               /**< Flag Control Register, offset: 0x100 */
  __I  uint32_t FSR;                               /**< Flag Status Register, offset: 0x104 */
       uint8_t RESERVED_2[8];
  __IO uint32_t GIER;                              /**< General Purpose Interrupt Enable Register, offset: 0x110 */
  __IO uint32_t GCR;                               /**< General Purpose Interrupt Control Register, offset: 0x114 */
  __I  uint32_t GSR;                               /**< General Purpose Interrupt Status Register, offset: 0x118 */
       uint8_t RESERVED_3[4];
  __IO uint32_t TCR;                               /**< Transmit Control Register, offset: 0x120 */
  __I  uint32_t TSR;                               /**< Transmit Status Register, offset: 0x124 */
  __IO uint32_t RCR;                               /**< Receive Control Register, offset: 0x128 */
  __I  uint32_t RSR;                               /**< Receive Status Register, offset: 0x12C */
       uint8_t RESERVED_4[208];
  __IO uint32_t TR[S3MU_TR_COUNT];                 /**< Transmit Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_5[96];
  __I  uint32_t RR[S3MU_RR_COUNT];                 /**< Receive Register, array offset: 0x280, array step: 0x4 */
} S3MU_Type;

/* ----------------------------------------------------------------------------
   -- S3MU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S3MU_Register_Masks S3MU Register Masks
 * @{
 */

/*! @name VER - Version ID Register */
/*! @{ */

#define S3MU_VER_FEATURE_MASK                    (0xFFFFU)
#define S3MU_VER_FEATURE_SHIFT                   (0U)
/*! FEATURE - Feature Set Number
 *  0b0000000000000000..Standard features are implemented.
 */
#define S3MU_VER_FEATURE(x)                      (((uint32_t)(((uint32_t)(x)) << S3MU_VER_FEATURE_SHIFT)) & S3MU_VER_FEATURE_MASK)

#define S3MU_VER_MINOR_MASK                      (0xFF0000U)
#define S3MU_VER_MINOR_SHIFT                     (16U)
/*! MINOR - Minor Version Number */
#define S3MU_VER_MINOR(x)                        (((uint32_t)(((uint32_t)(x)) << S3MU_VER_MINOR_SHIFT)) & S3MU_VER_MINOR_MASK)

#define S3MU_VER_MAJOR_MASK                      (0xFF000000U)
#define S3MU_VER_MAJOR_SHIFT                     (24U)
/*! MAJOR - Major Version Number */
#define S3MU_VER_MAJOR(x)                        (((uint32_t)(((uint32_t)(x)) << S3MU_VER_MAJOR_SHIFT)) & S3MU_VER_MAJOR_MASK)
/*! @} */

/*! @name PAR - Parameter Register */
/*! @{ */

#define S3MU_PAR_TR_NUM_MASK                     (0xFFU)
#define S3MU_PAR_TR_NUM_SHIFT                    (0U)
/*! TR_NUM - Number of TRn registers */
#define S3MU_PAR_TR_NUM(x)                       (((uint32_t)(((uint32_t)(x)) << S3MU_PAR_TR_NUM_SHIFT)) & S3MU_PAR_TR_NUM_MASK)

#define S3MU_PAR_RR_NUM_MASK                     (0xFF00U)
#define S3MU_PAR_RR_NUM_SHIFT                    (8U)
/*! RR_NUM - Number of RRn registers */
#define S3MU_PAR_RR_NUM(x)                       (((uint32_t)(((uint32_t)(x)) << S3MU_PAR_RR_NUM_SHIFT)) & S3MU_PAR_RR_NUM_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define S3MU_SR_TEP_MASK                         (0x20U)
#define S3MU_SR_TEP_SHIFT                        (5U)
/*! TEP - Transmit Empty Pending */
#define S3MU_SR_TEP(x)                           (((uint32_t)(((uint32_t)(x)) << S3MU_SR_TEP_SHIFT)) & S3MU_SR_TEP_MASK)

#define S3MU_SR_RFP_MASK                         (0x40U)
#define S3MU_SR_RFP_SHIFT                        (6U)
/*! RFP - Receive Full Pending Flag */
#define S3MU_SR_RFP(x)                           (((uint32_t)(((uint32_t)(x)) << S3MU_SR_RFP_SHIFT)) & S3MU_SR_RFP_MASK)
/*! @} */

/*! @name FCR - Flag Control Register */
/*! @{ */

#define S3MU_FCR_Fn_MASK                         (0xFFFFFFFFU)
#define S3MU_FCR_Fn_SHIFT                        (0U)
/*! Fn - SENTMUA to SENTMUB Flag n */
#define S3MU_FCR_Fn(x)                           (((uint32_t)(((uint32_t)(x)) << S3MU_FCR_Fn_SHIFT)) & S3MU_FCR_Fn_MASK)
/*! @} */

/*! @name FSR - Flag Status Register */
/*! @{ */

#define S3MU_FSR_Fn_MASK                         (0xFFFFFFFFU)
#define S3MU_FSR_Fn_SHIFT                        (0U)
/*! Fn - SENTMUB to SENTMUA Side Flag n */
#define S3MU_FSR_Fn(x)                           (((uint32_t)(((uint32_t)(x)) << S3MU_FSR_Fn_SHIFT)) & S3MU_FSR_Fn_MASK)
/*! @} */

/*! @name GIER - General Purpose Interrupt Enable Register */
/*! @{ */

#define S3MU_GIER_GIEn_MASK                      (0xFFFFFFFFU)
#define S3MU_GIER_GIEn_SHIFT                     (0U)
/*! GIEn - SENTMUA General Purpose Interrupt Enable n */
#define S3MU_GIER_GIEn(x)                        (((uint32_t)(((uint32_t)(x)) << S3MU_GIER_GIEn_SHIFT)) & S3MU_GIER_GIEn_MASK)
/*! @} */

/*! @name GCR - General Purpose Interrupt Control Register */
/*! @{ */

#define S3MU_GCR_GIRn_MASK                       (0xFFFFFFFFU)
#define S3MU_GCR_GIRn_SHIFT                      (0U)
/*! GIRn - SENTMUA General Purpose Interrupt Request n */
#define S3MU_GCR_GIRn(x)                         (((uint32_t)(((uint32_t)(x)) << S3MU_GCR_GIRn_SHIFT)) & S3MU_GCR_GIRn_MASK)
/*! @} */

/*! @name GSR - General Purpose Interrupt Status Register */
/*! @{ */

#define S3MU_GSR_GIPn_MASK                       (0xFFFFFFFFU)
#define S3MU_GSR_GIPn_SHIFT                      (0U)
/*! GIPn - SENTMUA General Interrupt Request Pending n */
#define S3MU_GSR_GIPn(x)                         (((uint32_t)(((uint32_t)(x)) << S3MU_GSR_GIPn_SHIFT)) & S3MU_GSR_GIPn_MASK)
/*! @} */

/*! @name TCR - Transmit Control Register */
/*! @{ */

#define S3MU_TCR_TEIEn_MASK                      (0xFFU)
#define S3MU_TCR_TEIEn_SHIFT                     (0U)
/*! TEIEn - Transmit Register n Empty Interrupt Enable */
#define S3MU_TCR_TEIEn(x)                        (((uint32_t)(((uint32_t)(x)) << S3MU_TCR_TEIEn_SHIFT)) & S3MU_TCR_TEIEn_MASK)
/*! @} */

/*! @name TSR - Transmit Status Register */
/*! @{ */

#define S3MU_TSR_TEn_MASK                        (0xFFU)
#define S3MU_TSR_TEn_SHIFT                       (0U)
/*! TEn - Transmit Register n Empty */
#define S3MU_TSR_TEn(x)                          (((uint32_t)(((uint32_t)(x)) << S3MU_TSR_TEn_SHIFT)) & S3MU_TSR_TEn_MASK)
/*! @} */

/*! @name RCR - Receive Control Register */
/*! @{ */

#define S3MU_RCR_RFIEn_MASK                      (0xFFU)
#define S3MU_RCR_RFIEn_SHIFT                     (0U)
/*! RFIEn - Receive Register n Full Interrupt Enable */
#define S3MU_RCR_RFIEn(x)                        (((uint32_t)(((uint32_t)(x)) << S3MU_RCR_RFIEn_SHIFT)) & S3MU_RCR_RFIEn_MASK)
/*! @} */

/*! @name RSR - Receive Status Register */
/*! @{ */

#define S3MU_RSR_RFn_MASK                        (0xFFU)
#define S3MU_RSR_RFn_SHIFT                       (0U)
/*! RFn - Receive Register n Full */
#define S3MU_RSR_RFn(x)                          (((uint32_t)(((uint32_t)(x)) << S3MU_RSR_RFn_SHIFT)) & S3MU_RSR_RFn_MASK)
/*! @} */

/*! @name TR - Transmit Register */
/*! @{ */

#define S3MU_TR_TR_DATA_MASK                     (0xFFFFFFFFU)
#define S3MU_TR_TR_DATA_SHIFT                    (0U)
/*! TR_DATA - Transmit Data */
#define S3MU_TR_TR_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << S3MU_TR_TR_DATA_SHIFT)) & S3MU_TR_TR_DATA_MASK)
/*! @} */

/*! @name RR - Receive Register */
/*! @{ */

#define S3MU_RR_RR_DATA_MASK                     (0xFFFFFFFFU)
#define S3MU_RR_RR_DATA_SHIFT                    (0U)
/*! RR_DATA - Receive Data */
#define S3MU_RR_RR_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << S3MU_RR_RR_DATA_SHIFT)) & S3MU_RR_RR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group S3MU_Register_Masks */


/*!
 * @}
 */ /* end of group S3MU_Peripheral_Access_Layer */


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


#endif  /* PERI_S3MU_H_ */

