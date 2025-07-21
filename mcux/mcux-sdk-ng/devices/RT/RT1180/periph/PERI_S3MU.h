/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_S3MU.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for S3MU
 *
 * CMSIS Peripheral Access Layer for S3MU
 */

#if !defined(PERI_S3MU_H_)
#define PERI_S3MU_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
#define S3MU_RR_COUNT                             4u

/** S3MU - Register Layout Typedef */
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
  __IO uint32_t TR[S3MU_TR_COUNT];                 /**< Transmit Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_2[96];
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
/*! MINOR - Minor Version Number (0x00 ) */
#define S3MU_VER_MINOR(x)                        (((uint32_t)(((uint32_t)(x)) << S3MU_VER_MINOR_SHIFT)) & S3MU_VER_MINOR_MASK)

#define S3MU_VER_MAJOR_MASK                      (0xFF000000U)
#define S3MU_VER_MAJOR_SHIFT                     (24U)
/*! MAJOR - Major Version Number (0x01 ) */
#define S3MU_VER_MAJOR(x)                        (((uint32_t)(((uint32_t)(x)) << S3MU_VER_MAJOR_SHIFT)) & S3MU_VER_MAJOR_MASK)
/*! @} */

/*! @name PAR - Parameter Register */
/*! @{ */

#define S3MU_PAR_TR_NUM_MASK                     (0xFFU)
#define S3MU_PAR_TR_NUM_SHIFT                    (0U)
/*! TR_NUM - Number of Transmit (TRn) registers (8) */
#define S3MU_PAR_TR_NUM(x)                       (((uint32_t)(((uint32_t)(x)) << S3MU_PAR_TR_NUM_SHIFT)) & S3MU_PAR_TR_NUM_MASK)

#define S3MU_PAR_RR_NUM_MASK                     (0xFF00U)
#define S3MU_PAR_RR_NUM_SHIFT                    (8U)
/*! RR_NUM - Number of Receive (RRn) registers (4) */
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
/*! RFP - Receive Full Pending Flag
 *  0b0..No data is ready to be read. All RSR[RFn] bits are clear.
 *  0b1..Data is ready to be read. One or more RSR[RFn] bits are set.
 */
#define S3MU_SR_RFP(x)                           (((uint32_t)(((uint32_t)(x)) << S3MU_SR_RFP_SHIFT)) & S3MU_SR_RFP_MASK)
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

#define S3MU_RCR_RFIEn_MASK                      (0xFU)
#define S3MU_RCR_RFIEn_SHIFT                     (0U)
/*! RFIEn - Receive Register n Full Interrupt Enable */
#define S3MU_RCR_RFIEn(x)                        (((uint32_t)(((uint32_t)(x)) << S3MU_RCR_RFIEn_SHIFT)) & S3MU_RCR_RFIEn_MASK)
/*! @} */

/*! @name RSR - Receive Status Register */
/*! @{ */

#define S3MU_RSR_RFn_MASK                        (0xFU)
#define S3MU_RSR_RFn_SHIFT                       (0U)
/*! RFn - Receive Register n Full */
#define S3MU_RSR_RFn(x)                          (((uint32_t)(((uint32_t)(x)) << S3MU_RSR_RFn_SHIFT)) & S3MU_RSR_RFn_MASK)
/*! @} */

/*! @name UNUSED1 - Unused Register 1 */
/*! @{ */

#define S3MU_UNUSED1_DATA16_MASK                 (0xFFFFU)
#define S3MU_UNUSED1_DATA16_SHIFT                (0U)
/*! DATA16 - Unused 16-bit Register */
#define S3MU_UNUSED1_DATA16(x)                   (((uint32_t)(((uint32_t)(x)) << S3MU_UNUSED1_DATA16_SHIFT)) & S3MU_UNUSED1_DATA16_MASK)
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

