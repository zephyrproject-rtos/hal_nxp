/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MU.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MU
 *
 * CMSIS Peripheral Access Layer for MU
 */

#if !defined(PERI_MU_H_)
#define PERI_MU_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
/*!
 * @brief Power mode on the other side definition.
 */
typedef enum _mu_power_mode
{
    kMU_PowerModeRun  = 0x00U, /*!< Run mode.       */
    kMU_PowerModeWait = 0x01U, /*!< WAIT mode.      */
    kMU_PowerModeStop = 0x03U, /*!< STOP mode.      */
} mu_power_mode_t;


/* ----------------------------------------------------------------------------
   -- MU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MU_Peripheral_Access_Layer MU Peripheral Access Layer
 * @{
 */

/** MU - Size of Registers Arrays */
#define MU_TR_COUNT                               4u
#define MU_RR_COUNT                               4u

/** MU - Register Layout Typedef */
typedef struct {
  __IO uint32_t TR[MU_TR_COUNT];                   /**< Processor A Transmit Register 0..Processor A Transmit Register 3, array offset: 0x0, array step: 0x4 */
  __I  uint32_t RR[MU_RR_COUNT];                   /**< Processor A Receive Register 0..Processor A Receive Register 3, array offset: 0x10, array step: 0x4 */
  __IO uint32_t SR;                                /**< Processor A Status Register, offset: 0x20 */
  __IO uint32_t CR;                                /**< Processor A Control Register, offset: 0x24 */
} MU_Type;

/* ----------------------------------------------------------------------------
   -- MU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MU_Register_Masks MU Register Masks
 * @{
 */

/*! @name TR - Processor A Transmit Register 0..Processor A Transmit Register 3 */
/*! @{ */

#define MU_TR_ATR0_MASK                          (0xFFFFFFFFU)
#define MU_TR_ATR0_SHIFT                         (0U)
#define MU_TR_ATR0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TR_ATR0_SHIFT)) & MU_TR_ATR0_MASK)

#define MU_TR_ATR1_MASK                          (0xFFFFFFFFU)
#define MU_TR_ATR1_SHIFT                         (0U)
#define MU_TR_ATR1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TR_ATR1_SHIFT)) & MU_TR_ATR1_MASK)

#define MU_TR_ATR2_MASK                          (0xFFFFFFFFU)
#define MU_TR_ATR2_SHIFT                         (0U)
#define MU_TR_ATR2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TR_ATR2_SHIFT)) & MU_TR_ATR2_MASK)

#define MU_TR_ATR3_MASK                          (0xFFFFFFFFU)
#define MU_TR_ATR3_SHIFT                         (0U)
#define MU_TR_ATR3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TR_ATR3_SHIFT)) & MU_TR_ATR3_MASK)

#define MU_TR_BTR0_MASK                          (0xFFFFFFFFU)
#define MU_TR_BTR0_SHIFT                         (0U)
#define MU_TR_BTR0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TR_BTR0_SHIFT)) & MU_TR_BTR0_MASK)

#define MU_TR_BTR1_MASK                          (0xFFFFFFFFU)
#define MU_TR_BTR1_SHIFT                         (0U)
#define MU_TR_BTR1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TR_BTR1_SHIFT)) & MU_TR_BTR1_MASK)

#define MU_TR_BTR2_MASK                          (0xFFFFFFFFU)
#define MU_TR_BTR2_SHIFT                         (0U)
#define MU_TR_BTR2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TR_BTR2_SHIFT)) & MU_TR_BTR2_MASK)

#define MU_TR_BTR3_MASK                          (0xFFFFFFFFU)
#define MU_TR_BTR3_SHIFT                         (0U)
#define MU_TR_BTR3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TR_BTR3_SHIFT)) & MU_TR_BTR3_MASK)
/*! @} */

/*! @name RR - Processor A Receive Register 0..Processor A Receive Register 3 */
/*! @{ */

#define MU_RR_ARR0_MASK                          (0xFFFFFFFFU)
#define MU_RR_ARR0_SHIFT                         (0U)
#define MU_RR_ARR0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RR_ARR0_SHIFT)) & MU_RR_ARR0_MASK)

#define MU_RR_ARR1_MASK                          (0xFFFFFFFFU)
#define MU_RR_ARR1_SHIFT                         (0U)
#define MU_RR_ARR1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RR_ARR1_SHIFT)) & MU_RR_ARR1_MASK)

#define MU_RR_ARR2_MASK                          (0xFFFFFFFFU)
#define MU_RR_ARR2_SHIFT                         (0U)
#define MU_RR_ARR2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RR_ARR2_SHIFT)) & MU_RR_ARR2_MASK)

#define MU_RR_ARR3_MASK                          (0xFFFFFFFFU)
#define MU_RR_ARR3_SHIFT                         (0U)
#define MU_RR_ARR3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RR_ARR3_SHIFT)) & MU_RR_ARR3_MASK)

#define MU_RR_BRR0_MASK                          (0xFFFFFFFFU)
#define MU_RR_BRR0_SHIFT                         (0U)
#define MU_RR_BRR0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RR_BRR0_SHIFT)) & MU_RR_BRR0_MASK)

#define MU_RR_BRR1_MASK                          (0xFFFFFFFFU)
#define MU_RR_BRR1_SHIFT                         (0U)
#define MU_RR_BRR1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RR_BRR1_SHIFT)) & MU_RR_BRR1_MASK)

#define MU_RR_BRR2_MASK                          (0xFFFFFFFFU)
#define MU_RR_BRR2_SHIFT                         (0U)
#define MU_RR_BRR2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RR_BRR2_SHIFT)) & MU_RR_BRR2_MASK)

#define MU_RR_BRR3_MASK                          (0xFFFFFFFFU)
#define MU_RR_BRR3_SHIFT                         (0U)
#define MU_RR_BRR3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RR_BRR3_SHIFT)) & MU_RR_BRR3_MASK)
/*! @} */

/*! @name SR - Processor A Status Register */
/*! @{ */

#define MU_SR_Fn_MASK                            (0x7U)
#define MU_SR_Fn_SHIFT                           (0U)
/*! Fn
 *  0b000..ABFn bit in ACR register is written 0 (default).
 *  0b001..ABFn bit in ACR register is written 1.
 */
#define MU_SR_Fn(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_Fn_SHIFT)) & MU_SR_Fn_MASK)

#define MU_SR_EP_MASK                            (0x10U)
#define MU_SR_EP_SHIFT                           (4U)
/*! EP
 *  0b0..The Processor A-side event is not pending (default).
 *  0b1..The Processor A-side event is pending.
 */
#define MU_SR_EP(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_EP_SHIFT)) & MU_SR_EP_MASK)

#define MU_SR_APM_MASK                           (0x60U)
#define MU_SR_APM_SHIFT                          (5U)
/*! APM
 *  0b00..The System is in Run Mode.
 *  0b01..The System is in WAIT Mode.
 *  0b10..Reserved.
 *  0b11..The System is in STOP Mode.
 */
#define MU_SR_APM(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_APM_SHIFT)) & MU_SR_APM_MASK)

#define MU_SR_ARS_MASK                           (0x80U)
#define MU_SR_ARS_SHIFT                          (7U)
/*! ARS
 *  0b0..The Processor A or the Processor A-side of the MU is not in reset.
 *  0b1..The Processor A or the Processor A-side of the MU is in reset.
 */
#define MU_SR_ARS(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_ARS_SHIFT)) & MU_SR_ARS_MASK)

#define MU_SR_BRS_MASK                           (0x80U)
#define MU_SR_BRS_SHIFT                          (7U)
/*! BRS
 *  0b0..The Processor B-side of the MU is not in reset.
 *  0b1..The Processor B-side of the MU is in reset.
 */
#define MU_SR_BRS(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_BRS_SHIFT)) & MU_SR_BRS_MASK)

#define MU_SR_FUP_MASK                           (0x100U)
#define MU_SR_FUP_SHIFT                          (8U)
/*! FUP
 *  0b0..No flags updated, initiated by the Processor A, in progress (default)
 *  0b1..Processor A initiated flags update, processing
 */
#define MU_SR_FUP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_FUP_SHIFT)) & MU_SR_FUP_MASK)

#define MU_SR_BRDIP_MASK                         (0x200U)
#define MU_SR_BRDIP_SHIFT                        (9U)
/*! BRDIP
 *  0b0..The Processor A general purpose interrupt 3, because of a Processor B-side reset de-assertion, is cleared (default).
 *  0b1..The Processor B-side is out of reset.
 */
#define MU_SR_BRDIP(x)                           (((uint32_t)(((uint32_t)(x)) << MU_SR_BRDIP_SHIFT)) & MU_SR_BRDIP_MASK)

#define MU_SR_TEn_MASK                           (0xF00000U)
#define MU_SR_TEn_SHIFT                          (20U)
/*! TEn
 *  0b0000..ATRn register is not empty.
 *  0b0001..ATRn register is empty (default).
 */
#define MU_SR_TEn(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_TEn_SHIFT)) & MU_SR_TEn_MASK)

#define MU_SR_RFn_MASK                           (0xF000000U)
#define MU_SR_RFn_SHIFT                          (24U)
/*! RFn
 *  0b0000..ARRn register is not full (default).
 *  0b0001..ARRn register has received data from BTRn register and is ready to be read by the Processor A.
 */
#define MU_SR_RFn(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_RFn_SHIFT)) & MU_SR_RFn_MASK)

#define MU_SR_GIPn_MASK                          (0xF0000000U)
#define MU_SR_GIPn_SHIFT                         (28U)
/*! GIPn
 *  0b0000..Processor A general purpose interrupt n is not pending. (default)
 *  0b0001..Processor A general purpose interrupt n is pending.
 */
#define MU_SR_GIPn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_GIPn_SHIFT)) & MU_SR_GIPn_MASK)
/*! @} */

/*! @name CR - Processor A Control Register */
/*! @{ */

#define MU_CR_ABFn_MASK                          (0x7U)
#define MU_CR_ABFn_SHIFT                         (0U)
/*! ABFn
 *  0b000..N/A. Self clearing bit (default).
 *  0b001..Asserts the Processor A MU reset.
 */
#define MU_CR_ABFn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_ABFn_SHIFT)) & MU_CR_ABFn_MASK)

#define MU_CR_BAFn_MASK                          (0x7U)
#define MU_CR_BAFn_SHIFT                         (0U)
/*! BAFn
 *  0b000..Clears the Fn bit in the ASR register.
 *  0b001..Sets the Fn bit in the ASR register.
 */
#define MU_CR_BAFn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_BAFn_SHIFT)) & MU_CR_BAFn_MASK)

#define MU_CR_BHR_MASK                           (0x10U)
#define MU_CR_BHR_SHIFT                          (4U)
/*! BHR
 *  0b0..De-assert Hardware reset to the Processor B. (default)
 *  0b1..Assert Hardware reset to the Processor B.
 */
#define MU_CR_BHR(x)                             (((uint32_t)(((uint32_t)(x)) << MU_CR_BHR_SHIFT)) & MU_CR_BHR_MASK)

#define MU_CR_HRM_MASK                           (0x10U)
#define MU_CR_HRM_SHIFT                          (4U)
/*! HRM
 *  0b0..BHR bit in ACR is not masked, enables the hardware reset to the Processor B (default after hardware reset).
 *  0b1..BHR bit in ACR is masked, disables the hardware reset request to the Processor B.
 */
#define MU_CR_HRM(x)                             (((uint32_t)(((uint32_t)(x)) << MU_CR_HRM_SHIFT)) & MU_CR_HRM_MASK)

#define MU_CR_MUR_MASK                           (0x20U)
#define MU_CR_MUR_SHIFT                          (5U)
/*! MUR
 *  0b0..N/A. Self clearing bit (default).
 *  0b1..Asserts the Processor A MU reset.
 */
#define MU_CR_MUR(x)                             (((uint32_t)(((uint32_t)(x)) << MU_CR_MUR_SHIFT)) & MU_CR_MUR_MASK)

#define MU_CR_BRDIE_MASK                         (0x40U)
#define MU_CR_BRDIE_SHIFT                        (6U)
/*! BRDIE
 *  0b0..Disables the Processor A General Purpose Interrupt 3 request due to the Processor B reset de-assertion to
 *       the Processor A. Processor B reset deassertion causes Processor B and MU-Processor B side to come out of
 *       reset thus setting BRDIP bit to "1".
 *  0b1..Enables Processor A General Purpose Interrupt 3 request due to the Processor B reset de-assertion to the Processor A.
 */
#define MU_CR_BRDIE(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CR_BRDIE_SHIFT)) & MU_CR_BRDIE_MASK)

#define MU_CR_GIRn_MASK                          (0xF0000U)
#define MU_CR_GIRn_SHIFT                         (16U)
/*! GIRn
 *  0b0000..Processor A General Interrupt n is not requested to the Processor B (default).
 *  0b0001..Processor A General Interrupt n is requested to the Processor B.
 */
#define MU_CR_GIRn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_GIRn_SHIFT)) & MU_CR_GIRn_MASK)

#define MU_CR_TIEn_MASK                          (0xF00000U)
#define MU_CR_TIEn_SHIFT                         (20U)
/*! TIEn
 *  0b0000..Disables Processor A Transmit Interrupt n. (default)
 *  0b0001..Enables Processor A Transmit Interrupt n.
 */
#define MU_CR_TIEn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_TIEn_SHIFT)) & MU_CR_TIEn_MASK)

#define MU_CR_RIEn_MASK                          (0xF000000U)
#define MU_CR_RIEn_SHIFT                         (24U)
/*! RIEn
 *  0b0000..Disables Processor A Receive Interrupt n. (default)
 *  0b0001..Enables Processor A Receive Interrupt n.
 */
#define MU_CR_RIEn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_RIEn_SHIFT)) & MU_CR_RIEn_MASK)

#define MU_CR_GIEn_MASK                          (0xF0000000U)
#define MU_CR_GIEn_SHIFT                         (28U)
/*! GIEn
 *  0b0000..Disables Processor A General Interrupt n. (default)
 *  0b0001..Enables Processor A General Interrupt n.
 */
#define MU_CR_GIEn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_GIEn_SHIFT)) & MU_CR_GIEn_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MU_Register_Masks */

/* Backward compatibility */
#define MU_SR_PM_MASK                             MU_SR_APM_MASK
#define MU_SR_PM_SHIFT                            MU_SR_APM_SHIFT
#define MU_SR_PM(x)                               MU_SR_APM(x)
#define MU_SR_RS_MASK                             MU_SR_ARS_MASK
#define MU_SR_RS_SHIFT                            MU_SR_ARS_SHIFT
#define MU_SR_RS(x)                               MU_SR_ARS(x)
#define MU_CR_Fn_MASK                             MU_CR_BAFn_MASK
#define MU_CR_Fn_SHIFT                            MU_CR_BAFn_SHIFT
#define MU_CR_Fn(x)                               MU_CR_BAFn(x)


/*!
 * @}
 */ /* end of group MU_Peripheral_Access_Layer */


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


#endif  /* PERI_MU_H_ */

