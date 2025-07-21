/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**                          MIMXRT685SFAWBR_cm33
**                          MIMXRT685SFAWBR_dsp
**                          MIMXRT685SFFOB_cm33
**                          MIMXRT685SFFOB_dsp
**                          MIMXRT685SFVKB_cm33
**                          MIMXRT685SFVKB_dsp
**                          MIMXRT685SVFVKB_cm33
**                          MIMXRT685SVFVKB_dsp
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MU.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MU
 *
 * CMSIS Peripheral Access Layer for MU
 */

#if !defined(PERI_MU_H_)
#define PERI_MU_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT633SFAWBR) || defined(CPU_MIMXRT633SFFOB) || defined(CPU_MIMXRT633SFVKB))
#include "MIMXRT633S_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_cm33) || defined(CPU_MIMXRT685SFFOB_cm33) || defined(CPU_MIMXRT685SFVKB_cm33) || defined(CPU_MIMXRT685SVFVKB_cm33))
#include "MIMXRT685S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_dsp) || defined(CPU_MIMXRT685SFFOB_dsp) || defined(CPU_MIMXRT685SFVKB_dsp) || defined(CPU_MIMXRT685SVFVKB_dsp))
#include "MIMXRT685S_dsp_COMMON.h"
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
/*!
 * @brief Power mode definition.
 */
typedef enum _mu_power_mode
{
    kMU_PowerModeRun = 0x00U,   /*!< Run mode.           */
    kMU_PowerModeWait  = 0x01U, /*!< WAIT mode.          */
    kMU_PowerModeStop  = 0x02U, /*!< STOP/VLPS mode.     */
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
  __I  uint32_t VER;                               /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PAR;                               /**< Use Parameter register to determine the parameter settings of MUA., offset: 0x4 */
       uint8_t RESERVED_0[24];
  __IO uint32_t TR[MU_TR_COUNT];                   /**< Transmit Register, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[16];
  __IO uint32_t RR[MU_RR_COUNT];                   /**< Receive Register., array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_2[16];
  __IO uint32_t SR;                                /**< Status Register, offset: 0x60 */
  __IO uint32_t CR;                                /**< Control Register, offset: 0x64 */
} MU_Type;

/* ----------------------------------------------------------------------------
   -- MU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MU_Register_Masks MU Register Masks
 * @{
 */

/*! @name VER - Version ID Register */
/*! @{ */

#define MU_VER_FEATURE_MASK                      (0xFFFFU)
#define MU_VER_FEATURE_SHIFT                     (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Standard features implemented
 *  0b0000000000000001..RAIP and RAIE register bits implemented on MUA side
 *  0b0000000000000010..MUA and MUB implemented with the same function. some bits in CR register are moved to CCR register.
 *  0b0000000000000100..some sync logic are deleted for synchronized MUA and MUB. RAIP and RDIP monitor Core reset
 *                      instead of MU reset. Add HRIP and MURIP and their interrupt enable bits on both sides.
 *                      Delete RS bit. Add COO mode in PM state.
 */
#define MU_VER_FEATURE(x)                        (((uint32_t)(((uint32_t)(x)) << MU_VER_FEATURE_SHIFT)) & MU_VER_FEATURE_MASK)

#define MU_VER_MINOR_MASK                        (0xFF0000U)
#define MU_VER_MINOR_SHIFT                       (16U)
/*! MINOR - Minor Version Number */
#define MU_VER_MINOR(x)                          (((uint32_t)(((uint32_t)(x)) << MU_VER_MINOR_SHIFT)) & MU_VER_MINOR_MASK)

#define MU_VER_MAJOR_MASK                        (0xFF000000U)
#define MU_VER_MAJOR_SHIFT                       (24U)
/*! MAJOR - Major Version Number */
#define MU_VER_MAJOR(x)                          (((uint32_t)(((uint32_t)(x)) << MU_VER_MAJOR_SHIFT)) & MU_VER_MAJOR_MASK)
/*! @} */

/*! @name PAR - Use Parameter register to determine the parameter settings of MUA. */
/*! @{ */

#define MU_PAR_PARAMETER_MASK                    (0xFFFFFFFFU)
#define MU_PAR_PARAMETER_SHIFT                   (0U)
#define MU_PAR_PARAMETER(x)                      (((uint32_t)(((uint32_t)(x)) << MU_PAR_PARAMETER_SHIFT)) & MU_PAR_PARAMETER_MASK)
/*! @} */

/*! @name TR - Transmit Register */
/*! @{ */

#define MU_TR_DATA_MASK                          (0xFFFFFFFFU)
#define MU_TR_DATA_SHIFT                         (0U)
/*! DATA - DATA */
#define MU_TR_DATA(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TR_DATA_SHIFT)) & MU_TR_DATA_MASK)
/*! @} */

/*! @name RR - Receive Register. */
/*! @{ */

#define MU_RR_DATA_MASK                          (0xFFFFFFFFU)
#define MU_RR_DATA_SHIFT                         (0U)
/*! DATA - DATA */
#define MU_RR_DATA(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RR_DATA_SHIFT)) & MU_RR_DATA_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define MU_SR_Fn_MASK                            (0x7U)
#define MU_SR_Fn_SHIFT                           (0U)
/*! Fn - Fn
 *  0b000..MUA Fn bit in the CR register is written 0 (default).
 *  0b001..MUA Fn bit in the CR register is written 1.
 */
#define MU_SR_Fn(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_Fn_SHIFT)) & MU_SR_Fn_MASK)

#define MU_SR_EP_MASK                            (0x10U)
#define MU_SR_EP_SHIFT                           (4U)
/*! EP - EP
 *  0b0..The MUA side event is not pending (default).
 *  0b1..The MUA side event is pending.
 */
#define MU_SR_EP(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_EP_SHIFT)) & MU_SR_EP_MASK)

#define MU_SR_PM_MASK                            (0x60U)
#define MU_SR_PM_SHIFT                           (5U)
/*! PM - PM
 *  0b00..The MUA processor is in Run Mode.
 *  0b01..The MUA processor is in WAIT Mode.
 */
#define MU_SR_PM(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_PM_SHIFT)) & MU_SR_PM_MASK)

#define MU_SR_RS_MASK                            (0x80U)
#define MU_SR_RS_SHIFT                           (7U)
/*! RS - RS
 *  0b0..The MUA side of the MU is not in reset.
 *  0b1..The MUA side of the MU is in reset.
 */
#define MU_SR_RS(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_RS_SHIFT)) & MU_SR_RS_MASK)

#define MU_SR_FUP_MASK                           (0x100U)
#define MU_SR_FUP_SHIFT                          (8U)
/*! FUP - FUP
 *  0b0..No flags updated, initiated by the MUA, in progress (default)
 *  0b1..MUA initiated flags update, processing
 */
#define MU_SR_FUP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_FUP_SHIFT)) & MU_SR_FUP_MASK)

#define MU_SR_RDIP_MASK                          (0x200U)
#define MU_SR_RDIP_SHIFT                         (9U)
/*! RDIP - BRDIP
 *  0b0..Processor B-side did not exit reset
 *  0b1..Processor B-side exited from reset
 */
#define MU_SR_RDIP(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_RDIP_SHIFT)) & MU_SR_RDIP_MASK)

#define MU_SR_RAIP_MASK                          (0x400U)
#define MU_SR_RAIP_SHIFT                         (10U)
/*! RAIP - RAIP
 *  0b0..Processor B-side did not enter reset
 *  0b1..Processor B-side entered reset
 */
#define MU_SR_RAIP(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_RAIP_SHIFT)) & MU_SR_RAIP_MASK)

#define MU_SR_TEn_MASK                           (0xF00000U)
#define MU_SR_TEn_SHIFT                          (20U)
/*! TEn - TEn
 *  0b0000..MUA TRn register is not empty.
 *  0b0001..MUA TRn register is empty (default).
 */
#define MU_SR_TEn(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_TEn_SHIFT)) & MU_SR_TEn_MASK)

#define MU_SR_RFn_MASK                           (0xF000000U)
#define MU_SR_RFn_SHIFT                          (24U)
/*! RFn - RFn
 *  0b0000..MUA RRn register is not full (default).
 *  0b0001..MUA RRn register has received data from MUB TRn register and is ready to be read by the MUA.
 */
#define MU_SR_RFn(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_RFn_SHIFT)) & MU_SR_RFn_MASK)

#define MU_SR_GIPn_MASK                          (0xF0000000U)
#define MU_SR_GIPn_SHIFT                         (28U)
/*! GIPn - GIPn
 *  0b0000..MUA general purpose interrupt n is not pending. (default)
 *  0b0001..MUA general purpose interrupt n is pending.
 */
#define MU_SR_GIPn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_GIPn_SHIFT)) & MU_SR_GIPn_MASK)
/*! @} */

/*! @name CR - Control Register */
/*! @{ */

#define MU_CR_Fn_MASK                            (0x7U)
#define MU_CR_Fn_SHIFT                           (0U)
/*! Fn - Fn
 *  0b000..Clears the Fn bit in the SR register.
 *  0b001..Sets the Fn bit in the SR register.
 */
#define MU_CR_Fn(x)                              (((uint32_t)(((uint32_t)(x)) << MU_CR_Fn_SHIFT)) & MU_CR_Fn_MASK)

#define MU_CR_MUR_MASK                           (0x20U)
#define MU_CR_MUR_SHIFT                          (5U)
/*! MUR - MUR
 *  0b0..N/A. Self clearing bit (default).
 *  0b1..Asserts the MU reset.
 */
#define MU_CR_MUR(x)                             (((uint32_t)(((uint32_t)(x)) << MU_CR_MUR_SHIFT)) & MU_CR_MUR_MASK)

#define MU_CR_RDIE_MASK                          (0x40U)
#define MU_CR_RDIE_SHIFT                         (6U)
/*! RDIE - BRDIE
 *  0b0..Disables Processor A General Purpose Interrupt 3 request due to Processor B reset de-assertion.
 *  0b1..Enables Processor A General Purpose Interrupt 3 request due to Processor B reset de-assertion.
 */
#define MU_CR_RDIE(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_RDIE_SHIFT)) & MU_CR_RDIE_MASK)

#define MU_CR_RAIE_MASK                          (0x1000U)
#define MU_CR_RAIE_SHIFT                         (12U)
/*! RAIE - RAIE
 *  0b0..Disables Processor A General Purpose Interrupt 3 request due to Processor B reset assertion.
 *  0b1..Enables Processor A General Purpose Interrupt 3 request due to Processor B reset assertion.
 */
#define MU_CR_RAIE(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_RAIE_SHIFT)) & MU_CR_RAIE_MASK)

#define MU_CR_GIRn_MASK                          (0xF0000U)
#define MU_CR_GIRn_SHIFT                         (16U)
/*! GIRn - GIRn
 *  0b0000..MUA General Interrupt n is not requested to the MUB (default).
 *  0b0001..MUA General Interrupt n is requested to the MUB.
 */
#define MU_CR_GIRn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_GIRn_SHIFT)) & MU_CR_GIRn_MASK)

#define MU_CR_TIEn_MASK                          (0xF00000U)
#define MU_CR_TIEn_SHIFT                         (20U)
/*! TIEn - TIEn
 *  0b0000..Disables MUA Transmit Interrupt n. (default)
 *  0b0001..Enables MUA Transmit Interrupt n.
 */
#define MU_CR_TIEn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_TIEn_SHIFT)) & MU_CR_TIEn_MASK)

#define MU_CR_RIEn_MASK                          (0xF000000U)
#define MU_CR_RIEn_SHIFT                         (24U)
/*! RIEn - RIEn
 *  0b0000..Disables MUA Receive Interrupt n. (default)
 *  0b0001..Enables MUA Receive Interrupt n.
 */
#define MU_CR_RIEn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_RIEn_SHIFT)) & MU_CR_RIEn_MASK)

#define MU_CR_GIEn_MASK                          (0xF0000000U)
#define MU_CR_GIEn_SHIFT                         (28U)
/*! GIEn - GIEn
 *  0b0000..Disables MUA General Interrupt n. (default)
 *  0b0001..Enables MUA General Interrupt n.
 */
#define MU_CR_GIEn(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_GIEn_SHIFT)) & MU_CR_GIEn_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MU_Register_Masks */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_MU_H_ */

