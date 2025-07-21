/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
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
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MU.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MU
 *
 * CMSIS Peripheral Access Layer for MU
 */

#if !defined(PERI_MU_H_)
#define PERI_MU_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
 * @brief Core boot mode.
 */
typedef enum _mu_core_boot_mode
{
    kMU_CoreBootFromAddr0 = 0x00U, /*!< Boot from 0x00.      */
    kMU_CoreBootFromFlash = 0x01U, /*!< Boot from Flash base. */
    kMU_CoreBootFromItcm  = 0x02U, /*!< Boot from ITCM base. */
} mu_core_boot_mode_t;

/*!
 * @brief Power mode on the other side definition.
 */
typedef enum _mu_power_mode
{
    kMU_PowerModeRun   = 0x00U, /*!< Run mode.      */
    kMU_PowerModeWait  = 0x01U, /*!< WAIT mode. */
    kMU_PowerModeStop  = 0x02U, /*!< STOP/VLPS mode. */
    kMU_PowerModeDsm   = 0x03U, /*!< DSM: LLS/VLLS mode. */
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
  __I  uint32_t PAR;                               /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[24];
  __IO uint32_t TR[MU_TR_COUNT];                   /**< Transmit Register, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[16];
  __I  uint32_t RR[MU_RR_COUNT];                   /**< Receive Register, array offset: 0x40, array step: 0x4 */
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
 *  0b000000000000x1xx..Core Control and Status Registers are implemented in both MUA and MUB.
 *  0b000000000000xx1x..RAIP/RAIE register bits are implemented.
 *  0b000000000000xxx0..Standard features implemented
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

/*! @name PAR - Parameter Register */
/*! @{ */

#define MU_PAR_PARAMETER_MASK                    (0xFFFFFFFFU)
#define MU_PAR_PARAMETER_SHIFT                   (0U)
/*! PARAMETER - This bitfield contains the parameter settings of MUA. */
#define MU_PAR_PARAMETER(x)                      (((uint32_t)(((uint32_t)(x)) << MU_PAR_PARAMETER_SHIFT)) & MU_PAR_PARAMETER_MASK)
/*! @} */

/*! @name TR - Transmit Register */
/*! @{ */

#define MU_TR_DATA_MASK                          (0xFFFFFFFFU)
#define MU_TR_DATA_SHIFT                         (0U)
/*! DATA - DATA */
#define MU_TR_DATA(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TR_DATA_SHIFT)) & MU_TR_DATA_MASK)
/*! @} */

/*! @name RR - Receive Register */
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
 *  0b000..Fn bit in the MUB CR register is written 0 (default).
 *  0b001..Fn bit in the MUB CR register is written 1.
 */
#define MU_SR_Fn(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_Fn_SHIFT)) & MU_SR_Fn_MASK)

#define MU_SR_NMIC_MASK                          (0x8U)
#define MU_SR_NMIC_SHIFT                         (3U)
/*! NMIC - NMIC
 *  0b0..Default
 *  0b1..Writing "1" clears the NMI bit in the MUB CR register.
 */
#define MU_SR_NMIC(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_NMIC_SHIFT)) & MU_SR_NMIC_MASK)

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
 *  0b00..The MUB processor is in Run Mode.
 *  0b01..The MUB processor is in WAIT Mode.
 *  0b10..The MUB processor is in STOP/VLPS Mode.
 *  0b11..The MUB processor is in LLS/VLLS Mode.
 */
#define MU_SR_PM(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_PM_SHIFT)) & MU_SR_PM_MASK)

#define MU_SR_RS_MASK                            (0x80U)
#define MU_SR_RS_SHIFT                           (7U)
/*! RS - RS
 *  0b0..The MUB side of the MU is not in reset.
 *  0b1..The MUB side of the MU is in reset.
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
/*! RDIP - RDIP
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

#define MU_CR_NMI_MASK                           (0x8U)
#define MU_CR_NMI_SHIFT                          (3U)
/*! NMI - NMI
 *  0b0..Non-maskable interrupt is not issued to the Processor B by the Processor A (default).
 *  0b1..Non-maskable interrupt is issued to the Processor B by the Processor A.
 */
#define MU_CR_NMI(x)                             (((uint32_t)(((uint32_t)(x)) << MU_CR_NMI_SHIFT)) & MU_CR_NMI_MASK)

#define MU_CR_BHR_MASK                           (0x10U)
#define MU_CR_BHR_SHIFT                          (4U)
/*! BHR - BHR
 *  0b0..De-assert Hardware reset to the Processor B. (default)
 *  0b1..Assert Hardware reset to the Processor B.
 */
#define MU_CR_BHR(x)                             (((uint32_t)(((uint32_t)(x)) << MU_CR_BHR_SHIFT)) & MU_CR_BHR_MASK)

#define MU_CR_MUR_MASK                           (0x20U)
#define MU_CR_MUR_SHIFT                          (5U)
/*! MUR - MUR
 *  0b0..N/A. Self clearing bit (default).
 *  0b1..Asserts the MU reset.
 */
#define MU_CR_MUR(x)                             (((uint32_t)(((uint32_t)(x)) << MU_CR_MUR_SHIFT)) & MU_CR_MUR_MASK)

#define MU_CR_RDIE_MASK                          (0x40U)
#define MU_CR_RDIE_SHIFT                         (6U)
/*! RDIE - RDIE
 *  0b0..Disables Processor A General Purpose Interrupt 3 request due to Processor B reset de-assertion.
 *  0b1..Enables Processor A General Purpose Interrupt 3 request due to Processor B reset de-assertion.
 */
#define MU_CR_RDIE(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_RDIE_SHIFT)) & MU_CR_RDIE_MASK)

#define MU_CR_RSTH_MASK                          (0x80U)
#define MU_CR_RSTH_SHIFT                         (7U)
/*! RSTH - Processor B Reset Hold
 *  0b0..Release Processor B from reset
 *  0b1..Hold Processor B in reset
 */
#define MU_CR_RSTH(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_RSTH_SHIFT)) & MU_CR_RSTH_MASK)

#define MU_CR_CLKE_MASK                          (0x100U)
#define MU_CR_CLKE_SHIFT                         (8U)
/*! CLKE - MUB clock enable
 *  0b0..MUB platform clock gated when MUB enters a stop mode.
 *  0b1..MUB platform clock kept running after MUB enters a stop mode, until MUA also enters a stop mode.
 */
#define MU_CR_CLKE(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CR_CLKE_SHIFT)) & MU_CR_CLKE_MASK)

#define MU_CR_BBOOT_MASK                         (0x600U)
#define MU_CR_BBOOT_SHIFT                        (9U)
/*! BBOOT - Processor B Boot Config.
 *  0b00..Boot from 0x0
 *  0b01..Boot from DMEM Base
 *  0b10..Boot from IMEM Base
 *  0b11..Reserved
 */
#define MU_CR_BBOOT(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CR_BBOOT_SHIFT)) & MU_CR_BBOOT_MASK)

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

/* Backward compatibility */
#define MU_CR_HR_MASK                          MU_CR_BHR_MASK
#define MU_CR_HR(x)                            MU_CR_BHR(x)
#define MU_CR_HR_SHIFT                         MU_CR_BHR_SHIFT
#define MU_CR_BOOT_MASK                        MU_CR_BBOOT_MASK
#define MU_CR_BOOT(x)                          MU_CR_BBOOT(x)
#define MU_CR_BOOT_SHIFT                       MU_CR_BBOOT_SHIFT


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

