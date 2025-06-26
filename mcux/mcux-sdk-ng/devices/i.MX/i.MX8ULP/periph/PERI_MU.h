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
**     Version:             rev. 5.0, 2023-04-27
**     Build:               b240823
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
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
**
** ###################################################################
*/

/*!
 * @file MU.h
 * @version 5.0
 * @date 2023-04-27
 * @brief CMSIS Peripheral Access Layer for MU
 *
 * CMSIS Peripheral Access Layer for MU
 */

#if !defined(MU_H_)
#define MU_H_                                    /**< Symbol preventing repeated inclusion */

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
/*!
 * @brief Core boot mode.
 */
typedef enum _mu_core_boot_mode
{
    kMU_CoreBootFromAddr0 = 0x00U, /*!< Boot from 0x00.      */
    kMU_CoreBootFromFlash = 0x01U, /*!< Boot from Flash base. */
    kMU_CoreBootFromItcm  = 0x02U, /*!< Boot from ITCM base. */
} mu_core_boot_mode_t;


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
  __IO uint32_t CR;                                /**< Control Register, offset: 0x8 */
  __IO uint32_t SR;                                /**< Status Register, offset: 0xC */
  __IO uint32_t CCR0;                              /**< Core Control Register 0, offset: 0x10 */
  __IO uint32_t CIER0;                             /**< Core Interrupt Enable Register 0, offset: 0x14 */
  __IO uint32_t CSSR0;                             /**< Core Sticky Status Register 0, offset: 0x18 */
  __I  uint32_t CSR0;                              /**< Core Status Register 0, offset: 0x1C */
       uint8_t RESERVED_0[224];
  __IO uint32_t FCR;                               /**< Flag Control Register, offset: 0x100 */
  __I  uint32_t FSR;                               /**< Flag Status Register, offset: 0x104 */
       uint8_t RESERVED_1[8];
  __IO uint32_t GIER;                              /**< General Interrupt Enable Register, offset: 0x110 */
  __IO uint32_t GCR;                               /**< General Control Register, offset: 0x114 */
  __IO uint32_t GSR;                               /**< General Status Register, offset: 0x118 */
       uint8_t RESERVED_2[4];
  __IO uint32_t TCR;                               /**< Transmit Control Register, offset: 0x120 */
  __I  uint32_t TSR;                               /**< Transmit Status Register, offset: 0x124 */
  __IO uint32_t RCR;                               /**< Receive Control Register, offset: 0x128 */
  __I  uint32_t RSR;                               /**< Receive Status Register, offset: 0x12C */
       uint8_t RESERVED_3[208];
  __IO uint32_t TR[MU_TR_COUNT];                   /**< Transmit Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_4[112];
  __I  uint32_t RR[MU_RR_COUNT];                   /**< Receive Register, array offset: 0x280, array step: 0x4 */
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
/*! FEATURE - Feature Set Number */
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

#define MU_PAR_TR_NUM_MASK                       (0xFFU)
#define MU_PAR_TR_NUM_SHIFT                      (0U)
/*! TR_NUM - Transmit Register Number */
#define MU_PAR_TR_NUM(x)                         (((uint32_t)(((uint32_t)(x)) << MU_PAR_TR_NUM_SHIFT)) & MU_PAR_TR_NUM_MASK)

#define MU_PAR_RR_NUM_MASK                       (0xFF00U)
#define MU_PAR_RR_NUM_SHIFT                      (8U)
/*! RR_NUM - RR Number */
#define MU_PAR_RR_NUM(x)                         (((uint32_t)(((uint32_t)(x)) << MU_PAR_RR_NUM_SHIFT)) & MU_PAR_RR_NUM_MASK)

#define MU_PAR_GIR_NUM_MASK                      (0xFF0000U)
#define MU_PAR_GIR_NUM_SHIFT                     (16U)
/*! GIR_NUM - General Interrupt Request Number */
#define MU_PAR_GIR_NUM(x)                        (((uint32_t)(((uint32_t)(x)) << MU_PAR_GIR_NUM_SHIFT)) & MU_PAR_GIR_NUM_MASK)

#define MU_PAR_FLAG_WIDTH_MASK                   (0xFF000000U)
#define MU_PAR_FLAG_WIDTH_SHIFT                  (24U)
/*! FLAG_WIDTH - Flag Width */
#define MU_PAR_FLAG_WIDTH(x)                     (((uint32_t)(((uint32_t)(x)) << MU_PAR_FLAG_WIDTH_SHIFT)) & MU_PAR_FLAG_WIDTH_MASK)
/*! @} */

/*! @name CR - Control Register */
/*! @{ */

#define MU_CR_MUR_MASK                           (0x1U)
#define MU_CR_MUR_SHIFT                          (0U)
/*! MUR - MU Reset
 *  0b0..Self clearing bit.
 *  0b1..Asserts the MU reset.
 */
#define MU_CR_MUR(x)                             (((uint32_t)(((uint32_t)(x)) << MU_CR_MUR_SHIFT)) & MU_CR_MUR_MASK)

#define MU_CR_MURIE_MASK                         (0x2U)
#define MU_CR_MURIE_SHIFT                        (1U)
/*! MURIE - MUB Reset Interrupt Enable
 *  0b0..Disables Processor A-side MU Reset Interrupt request due to MU reset issued by MUB.
 *  0b1..Enables Processor A-side MU Reset Interrupt request due to MU reset issued by MUB.
 */
#define MU_CR_MURIE(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CR_MURIE_SHIFT)) & MU_CR_MURIE_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define MU_SR_MURS_MASK                          (0x1U)
#define MU_SR_MURS_SHIFT                         (0U)
/*! MURS - MUA and MUB Reset State
 *  0b0..MUA and MUB are out of reset.
 *  0b1..MUA or MUB is in reset state.
 */
#define MU_SR_MURS(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_MURS_SHIFT)) & MU_SR_MURS_MASK)

#define MU_SR_MURIP_MASK                         (0x2U)
#define MU_SR_MURIP_SHIFT                        (1U)
/*! MURIP - MU Reset Interrupt Pending
 *  0b0..Processor A did not issue MU reset.
 *  0b1..Processor A issued MU reset.
 */
#define MU_SR_MURIP(x)                           (((uint32_t)(((uint32_t)(x)) << MU_SR_MURIP_SHIFT)) & MU_SR_MURIP_MASK)

#define MU_SR_EP_MASK                            (0x4U)
#define MU_SR_EP_SHIFT                           (2U)
/*! EP - MUB Side Event Pending
 *  0b0..The MUA side event is not pending.
 *  0b1..The MUA side event is pending.
 */
#define MU_SR_EP(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_EP_SHIFT)) & MU_SR_EP_MASK)

#define MU_SR_FUP_MASK                           (0x8U)
#define MU_SR_FUP_SHIFT                          (3U)
/*! FUP - MUB Flags Update Pending
 *  0b0..No pending update flags(initiated by MUA) are in process
 *  0b1..Pending update flags(initiated by MUA) are in process
 */
#define MU_SR_FUP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_FUP_SHIFT)) & MU_SR_FUP_MASK)

#define MU_SR_GIRP_MASK                          (0x10U)
#define MU_SR_GIRP_SHIFT                         (4U)
/*! GIRP - MUB General Interrupt Pending
 *  0b0..No general interrupt request is sent from MUA.
 *  0b1..Any general interrupt request is sent from MUA.
 */
#define MU_SR_GIRP(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_GIRP_SHIFT)) & MU_SR_GIRP_MASK)

#define MU_SR_TEP_MASK                           (0x20U)
#define MU_SR_TEP_SHIFT                          (5U)
/*! TEP - MUB Transmit Empty Pending
 *  0b0..RRn register is not read by MUA.
 *  0b1..Any RRn register is read by MUA.
 */
#define MU_SR_TEP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_TEP_SHIFT)) & MU_SR_TEP_MASK)

#define MU_SR_RFP_MASK                           (0x40U)
#define MU_SR_RFP_SHIFT                          (6U)
/*! RFP - MUB Receive Full Pending Flag
 *  0b0..No TRn register is written by MUA.
 *  0b1..Any TRn register is written by MUA.
 */
#define MU_SR_RFP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_RFP_SHIFT)) & MU_SR_RFP_MASK)

#define MU_SR_CEP_MASK                           (0x80U)
#define MU_SR_CEP_SHIFT                          (7U)
/*! CEP - Processor B Event Pending Flag
 *  0b0..No core operation mode entry event pending.
 *  0b1..Any core operation mode entry event pending.
 */
#define MU_SR_CEP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_CEP_SHIFT)) & MU_SR_CEP_MASK)
/*! @} */

/*! @name CCR0 - Core Control Register 0 */
/*! @{ */

#define MU_CCR0_NMI_MASK                         (0x1U)
#define MU_CCR0_NMI_SHIFT                        (0U)
/*! NMI - MUB Non-maskable Interrupt Request
 *  0b0..Non-maskable interrupt is not issued to the Processor A by the Processor B.
 *  0b1..Non-maskable interrupt is issued to the Processor A by the Processor B.
 */
#define MU_CCR0_NMI(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CCR0_NMI_SHIFT)) & MU_CCR0_NMI_MASK)

#define MU_CCR0_HR_MASK                          (0x2U)
#define MU_CCR0_HR_SHIFT                         (1U)
/*! HR - Processor B Hardware Reset
 *  0b0..De-assert Hardware reset to the Processor A.
 *  0b1..Assert Hardware reset to the Processor A.
 */
#define MU_CCR0_HR(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CCR0_HR_SHIFT)) & MU_CCR0_HR_MASK)

#define MU_CCR0_HRM_MASK                         (0x4U)
#define MU_CCR0_HRM_SHIFT                        (2U)
/*! HRM - Processor B Hardware Reset Mask
 *  0b0..The MUA_CCR0[HR] bit is not masked, and the hardware reset to the Processor B is enabled.
 *  0b1..The MUA_CCR0[HR] bit is masked, and the hardware reset request to the Processor B is disabled.
 */
#define MU_CCR0_HRM(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CCR0_HRM_SHIFT)) & MU_CCR0_HRM_MASK)

#define MU_CCR0_CLKE_MASK                        (0x8U)
#define MU_CCR0_CLKE_SHIFT                       (3U)
/*! CLKE - Processor B clock enable
 *  0b0..Processor A platform clock is gated when Processor A enters a stop mode.
 *  0b1..Processor A platform clock is kept running after Processor A enters a stop mode, until Processor B also enters a stop mode.
 */
#define MU_CCR0_CLKE(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CCR0_CLKE_SHIFT)) & MU_CCR0_CLKE_MASK)

#define MU_CCR0_RSTH_MASK                        (0x10U)
#define MU_CCR0_RSTH_SHIFT                       (4U)
/*! RSTH - Processor B Reset Hold
 *  0b0..Release Processor A from reset
 *  0b1..Hold Processor A in reset
 */
#define MU_CCR0_RSTH(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CCR0_RSTH_SHIFT)) & MU_CCR0_RSTH_MASK)

#define MU_CCR0_BOOT_MASK                        (0x60U)
#define MU_CCR0_BOOT_SHIFT                       (5U)
/*! BOOT - Slave Processor B Boot Config.
 *  0b00..Processor Boot option 0
 *  0b01..Processor Boot option 1
 *  0b10..Processor Boot option 2
 *  0b11..Processor Boot option 3
 */
#define MU_CCR0_BOOT(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CCR0_BOOT_SHIFT)) & MU_CCR0_BOOT_MASK)
/*! @} */

/*! @name CIER0 - Core Interrupt Enable Register 0 */
/*! @{ */

#define MU_CIER0_HRIE_MASK                       (0x2U)
#define MU_CIER0_HRIE_SHIFT                      (1U)
/*! HRIE - Processor B Hardware Reset Interrupt Enable
 *  0b0..Disables Processor A Hardware Reset Interrupt request due to Processor B issues HR to Processor A.
 *  0b1..Enables Processor A Hardware Reset Interrupt request due to Processor B issues HR to Processor A.
 */
#define MU_CIER0_HRIE(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CIER0_HRIE_SHIFT)) & MU_CIER0_HRIE_MASK)

#define MU_CIER0_RUNIE_MASK                      (0x4U)
#define MU_CIER0_RUNIE_SHIFT                     (2U)
/*! RUNIE - Processor B Run Mode Entry Interrupt Enable
 *  0b0..Disables Processor A Run Mode Entry Interrupt request due to Processor B Run Mode Entry.
 *  0b1..Enables Processor A Run Mode Entry Interrupt request due to Processor B Run Mode Entry.
 */
#define MU_CIER0_RUNIE(x)                        (((uint32_t)(((uint32_t)(x)) << MU_CIER0_RUNIE_SHIFT)) & MU_CIER0_RUNIE_MASK)

#define MU_CIER0_RAIE_MASK                       (0x8U)
#define MU_CIER0_RAIE_SHIFT                      (3U)
/*! RAIE - Processor B Reset Assertion Interrupt Enable
 *  0b0..Disables Processor A Reset Assertion Interrupt request due to Processor B reset assertion.
 *  0b1..Enables Processor A Reset Assertion Interrupt request due to Processor B reset assertion.
 */
#define MU_CIER0_RAIE(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CIER0_RAIE_SHIFT)) & MU_CIER0_RAIE_MASK)

#define MU_CIER0_HALTIE_MASK                     (0x10U)
#define MU_CIER0_HALTIE_SHIFT                    (4U)
/*! HALTIE - Processor B Halt Mode Entry Interrupt Enable
 *  0b0..Disables Processor A Halt Mode Entry Interrupt request due to Processor B Halt Mode Entry.
 *  0b1..Enables Processor A Halt Mode Entry Interrupt request due to Processor B Halt Mode Entry.
 */
#define MU_CIER0_HALTIE(x)                       (((uint32_t)(((uint32_t)(x)) << MU_CIER0_HALTIE_SHIFT)) & MU_CIER0_HALTIE_MASK)

#define MU_CIER0_WAITIE_MASK                     (0x20U)
#define MU_CIER0_WAITIE_SHIFT                    (5U)
/*! WAITIE - Processor B Wait Mode Entry Interrupt Enable
 *  0b0..Disables Processor A Wait Mode Entry Interrupt request due to Processor B Wait Mode Entry.
 *  0b1..Enables Processor A Wait Mode Entry Interrupt request due to Processor B Wait Mode Entry.
 */
#define MU_CIER0_WAITIE(x)                       (((uint32_t)(((uint32_t)(x)) << MU_CIER0_WAITIE_SHIFT)) & MU_CIER0_WAITIE_MASK)

#define MU_CIER0_STOPIE_MASK                     (0x40U)
#define MU_CIER0_STOPIE_SHIFT                    (6U)
/*! STOPIE - Processor B Stop Mode Entry Interrupt Enable
 *  0b0..Disables Processor A Stop Mode Entry Interrupt request due to Processor B Stop Mode Entry.
 *  0b1..Enables Processor A Stop Mode Entry Interrupt request due to Processor B Stop Mode Entry.
 */
#define MU_CIER0_STOPIE(x)                       (((uint32_t)(((uint32_t)(x)) << MU_CIER0_STOPIE_SHIFT)) & MU_CIER0_STOPIE_MASK)

#define MU_CIER0_PDIE_MASK                       (0x80U)
#define MU_CIER0_PDIE_SHIFT                      (7U)
/*! PDIE - Processor B Power-Down Mode Entry Interrupt Enable
 *  0b0..Disables Processor A Power-Down Mode Entry Interrupt request due to Processor B Power-Down Mode Entry.
 *  0b1..Enables Processor A Power-Down Mode Entry Interrupt request due to Processor B Power-Down Mode Entry.
 */
#define MU_CIER0_PDIE(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CIER0_PDIE_SHIFT)) & MU_CIER0_PDIE_MASK)
/*! @} */

/*! @name CSSR0 - Core Sticky Status Register 0 */
/*! @{ */

#define MU_CSSR0_NMIC_MASK                       (0x1U)
#define MU_CSSR0_NMIC_SHIFT                      (0U)
/*! NMIC - Processor B Non-Maskable-Interrupt Clear
 *  0b0..Default
 *  0b1..Writing "1" clears the MUA_CCR0[NMI] bit.
 */
#define MU_CSSR0_NMIC(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_NMIC_SHIFT)) & MU_CSSR0_NMIC_MASK)

#define MU_CSSR0_HRIP_MASK                       (0x2U)
#define MU_CSSR0_HRIP_SHIFT                      (1U)
/*! HRIP - Processor B Hardware Reset Interrupt Pending
 *  0b0..MUA didn't issue hardware reset to Processor B
 *  0b1..MUA had initiated a hardware reset to Processor B through HR bit.
 */
#define MU_CSSR0_HRIP(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_HRIP_SHIFT)) & MU_CSSR0_HRIP_MASK)

#define MU_CSSR0_RUN_MASK                        (0x4U)
#define MU_CSSR0_RUN_SHIFT                       (2U)
/*! RUN - Processor B Run Mode Entry Interrupt Pending
 *  0b0..Processor A did not enter Run Mode.
 *  0b1..Processor A entered Run Mode
 */
#define MU_CSSR0_RUN(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_RUN_SHIFT)) & MU_CSSR0_RUN_MASK)

#define MU_CSSR0_RAIP_MASK                       (0x8U)
#define MU_CSSR0_RAIP_SHIFT                      (3U)
/*! RAIP - Processor B Reset Asserted Interrupt Pending
 *  0b0..Processor A did not enter reset
 *  0b1..Processor A entered reset
 */
#define MU_CSSR0_RAIP(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_RAIP_SHIFT)) & MU_CSSR0_RAIP_MASK)

#define MU_CSSR0_HALT_MASK                       (0x10U)
#define MU_CSSR0_HALT_SHIFT                      (4U)
/*! HALT - Processor B Halt Mode Entry Interrupt Pending
 *  0b0..Processor A did not enter Halt Mode.
 *  0b1..Processor A entered Halt Mode
 */
#define MU_CSSR0_HALT(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_HALT_SHIFT)) & MU_CSSR0_HALT_MASK)

#define MU_CSSR0_WAIT_MASK                       (0x20U)
#define MU_CSSR0_WAIT_SHIFT                      (5U)
/*! WAIT - Processor B Wait Mode Entry Interrupt Pending
 *  0b0..Processor A did not enter Wait Mode.
 *  0b1..Processor A entered Wait Mode
 */
#define MU_CSSR0_WAIT(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_WAIT_SHIFT)) & MU_CSSR0_WAIT_MASK)

#define MU_CSSR0_STOP_MASK                       (0x40U)
#define MU_CSSR0_STOP_SHIFT                      (6U)
/*! STOP - Processor B Stop Mode Entry Interrupt Pending
 *  0b0..Processor A did not enter Stop Mode.
 *  0b1..Processor A entered Stop Mode
 */
#define MU_CSSR0_STOP(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_STOP_SHIFT)) & MU_CSSR0_STOP_MASK)

#define MU_CSSR0_PD_MASK                         (0x80U)
#define MU_CSSR0_PD_SHIFT                        (7U)
/*! PD - Processor B Power-Down Mode Entry Interrupt Pending
 *  0b0..Processor A did not enter Power-Down Mode.
 *  0b1..Processor A entered Power-Down Mode
 */
#define MU_CSSR0_PD(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_PD_SHIFT)) & MU_CSSR0_PD_MASK)
/*! @} */

/*! @name CSR0 - Core Status Register 0 */
/*! @{ */

#define MU_CSR0_HRIP_MASK                        (0x2U)
#define MU_CSR0_HRIP_SHIFT                       (1U)
/*! HRIP - Processor B Hardware Reset Interrupt Pending
 *  0b0..MUA didn't issue hardware reset to Processor B.
 *  0b1..MUA had initiated a hardware reset to Processor B through HR bit.
 */
#define MU_CSR0_HRIP(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CSR0_HRIP_SHIFT)) & MU_CSR0_HRIP_MASK)

#define MU_CSR0_RUN_MASK                         (0x4U)
#define MU_CSR0_RUN_SHIFT                        (2U)
/*! RUN - Processor B Run Mode Entry
 *  0b0..Processor A did not enter Run Mode.
 *  0b1..Processor A entered Run Mode.
 */
#define MU_CSR0_RUN(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CSR0_RUN_SHIFT)) & MU_CSR0_RUN_MASK)

#define MU_CSR0_RAIP_MASK                        (0x8U)
#define MU_CSR0_RAIP_SHIFT                       (3U)
/*! RAIP - Processor B Reset Asserted Interrupt Pending
 *  0b0..Processor A did not enter reset.
 *  0b1..Processor A entered reset.
 */
#define MU_CSR0_RAIP(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CSR0_RAIP_SHIFT)) & MU_CSR0_RAIP_MASK)

#define MU_CSR0_HALT_MASK                        (0x10U)
#define MU_CSR0_HALT_SHIFT                       (4U)
/*! HALT - Processor B Halt Mode Entry
 *  0b0..Processor A did not enter Halt Mode.
 *  0b1..Processor A entered Halt Mode.
 */
#define MU_CSR0_HALT(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CSR0_HALT_SHIFT)) & MU_CSR0_HALT_MASK)

#define MU_CSR0_WAIT_MASK                        (0x20U)
#define MU_CSR0_WAIT_SHIFT                       (5U)
/*! WAIT - Processor B Wait Mode Entry
 *  0b0..Processor A did not enter Wait Mode.
 *  0b1..Processor A entered Wait Mode.
 */
#define MU_CSR0_WAIT(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CSR0_WAIT_SHIFT)) & MU_CSR0_WAIT_MASK)

#define MU_CSR0_STOP_MASK                        (0x40U)
#define MU_CSR0_STOP_SHIFT                       (6U)
/*! STOP - Processor B Stop Mode Entry
 *  0b0..Processor A did not enter Stop Mode.
 *  0b1..Processor A entered Stop Mode.
 */
#define MU_CSR0_STOP(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CSR0_STOP_SHIFT)) & MU_CSR0_STOP_MASK)

#define MU_CSR0_PD_MASK                          (0x80U)
#define MU_CSR0_PD_SHIFT                         (7U)
/*! PD - Processor B Power-Down Mode Entry
 *  0b0..Processor A did not enter Power-Down Mode.
 *  0b1..Processor A entered Power-Down Mode.
 */
#define MU_CSR0_PD(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CSR0_PD_SHIFT)) & MU_CSR0_PD_MASK)
/*! @} */

/*! @name FCR - Flag Control Register */
/*! @{ */

#define MU_FCR_F0_MASK                           (0x1U)
#define MU_FCR_F0_SHIFT                          (0U)
/*! F0 - MUB to MUA Flag n
 *  0b0..Clears the Fn bit in the FSR register.
 *  0b1..Sets the Fn bit in the FSR register.
 */
#define MU_FCR_F0(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F0_SHIFT)) & MU_FCR_F0_MASK)

#define MU_FCR_F1_MASK                           (0x2U)
#define MU_FCR_F1_SHIFT                          (1U)
/*! F1 - MUB to MUA Flag n
 *  0b0..Clears the Fn bit in the FSR register.
 *  0b1..Sets the Fn bit in the FSR register.
 */
#define MU_FCR_F1(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F1_SHIFT)) & MU_FCR_F1_MASK)

#define MU_FCR_F2_MASK                           (0x4U)
#define MU_FCR_F2_SHIFT                          (2U)
/*! F2 - MUB to MUA Flag n
 *  0b0..Clears the Fn bit in the FSR register.
 *  0b1..Sets the Fn bit in the FSR register.
 */
#define MU_FCR_F2(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F2_SHIFT)) & MU_FCR_F2_MASK)
/*! @} */

/*! @name FSR - Flag Status Register */
/*! @{ */

#define MU_FSR_F0_MASK                           (0x1U)
#define MU_FSR_F0_SHIFT                          (0U)
/*! F0 - MUB to MUA Side Flag n
 *  0b0..Fn bit in the MUA FCR register is written 0.
 *  0b1..Fn bit in the MUA FCR register is written 1.
 */
#define MU_FSR_F0(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F0_SHIFT)) & MU_FSR_F0_MASK)

#define MU_FSR_F1_MASK                           (0x2U)
#define MU_FSR_F1_SHIFT                          (1U)
/*! F1 - MUB to MUA Side Flag n
 *  0b0..Fn bit in the MUA FCR register is written 0.
 *  0b1..Fn bit in the MUA FCR register is written 1.
 */
#define MU_FSR_F1(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F1_SHIFT)) & MU_FSR_F1_MASK)

#define MU_FSR_F2_MASK                           (0x4U)
#define MU_FSR_F2_SHIFT                          (2U)
/*! F2 - MUB to MUA Side Flag n
 *  0b0..Fn bit in the MUA FCR register is written 0.
 *  0b1..Fn bit in the MUA FCR register is written 1.
 */
#define MU_FSR_F2(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F2_SHIFT)) & MU_FSR_F2_MASK)
/*! @} */

/*! @name GIER - General Interrupt Enable Register */
/*! @{ */

#define MU_GIER_GIE0_MASK                        (0x1U)
#define MU_GIER_GIE0_SHIFT                       (0U)
/*! GIE0 - MUB General Purpose Interrupt Enable n
 *  0b0..Disables MUA General Interrupt n.
 *  0b1..Enables MUA General Interrupt n.
 */
#define MU_GIER_GIE0(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE0_SHIFT)) & MU_GIER_GIE0_MASK)

#define MU_GIER_GIE1_MASK                        (0x2U)
#define MU_GIER_GIE1_SHIFT                       (1U)
/*! GIE1 - MUB General Purpose Interrupt Enable n
 *  0b0..Disables MUA General Interrupt n.
 *  0b1..Enables MUA General Interrupt n.
 */
#define MU_GIER_GIE1(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE1_SHIFT)) & MU_GIER_GIE1_MASK)

#define MU_GIER_GIE2_MASK                        (0x4U)
#define MU_GIER_GIE2_SHIFT                       (2U)
/*! GIE2 - MUB General Purpose Interrupt Enable n
 *  0b0..Disables MUA General Interrupt n.
 *  0b1..Enables MUA General Interrupt n.
 */
#define MU_GIER_GIE2(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE2_SHIFT)) & MU_GIER_GIE2_MASK)

#define MU_GIER_GIE3_MASK                        (0x8U)
#define MU_GIER_GIE3_SHIFT                       (3U)
/*! GIE3 - MUB General Purpose Interrupt Enable n
 *  0b0..Disables MUA General Interrupt n.
 *  0b1..Enables MUA General Interrupt n.
 */
#define MU_GIER_GIE3(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE3_SHIFT)) & MU_GIER_GIE3_MASK)
/*! @} */

/*! @name GCR - General Control Register */
/*! @{ */

#define MU_GCR_GIR0_MASK                         (0x1U)
#define MU_GCR_GIR0_SHIFT                        (0U)
/*! GIR0 - MUB General Purpose Interrupt Request n
 *  0b0..MUA General Interrupt n is not requested to the MUB.
 *  0b1..MUA General Interrupt n is requested to the MUB.
 */
#define MU_GCR_GIR0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR0_SHIFT)) & MU_GCR_GIR0_MASK)

#define MU_GCR_GIR1_MASK                         (0x2U)
#define MU_GCR_GIR1_SHIFT                        (1U)
/*! GIR1 - MUB General Purpose Interrupt Request n
 *  0b0..MUA General Interrupt n is not requested to the MUB.
 *  0b1..MUA General Interrupt n is requested to the MUB.
 */
#define MU_GCR_GIR1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR1_SHIFT)) & MU_GCR_GIR1_MASK)

#define MU_GCR_GIR2_MASK                         (0x4U)
#define MU_GCR_GIR2_SHIFT                        (2U)
/*! GIR2 - MUB General Purpose Interrupt Request n
 *  0b0..MUA General Interrupt n is not requested to the MUB.
 *  0b1..MUA General Interrupt n is requested to the MUB.
 */
#define MU_GCR_GIR2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR2_SHIFT)) & MU_GCR_GIR2_MASK)

#define MU_GCR_GIR3_MASK                         (0x8U)
#define MU_GCR_GIR3_SHIFT                        (3U)
/*! GIR3 - MUB General Purpose Interrupt Request n
 *  0b0..MUA General Interrupt n is not requested to the MUB.
 *  0b1..MUA General Interrupt n is requested to the MUB.
 */
#define MU_GCR_GIR3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR3_SHIFT)) & MU_GCR_GIR3_MASK)
/*! @} */

/*! @name GSR - General Status Register */
/*! @{ */

#define MU_GSR_GIP0_MASK                         (0x1U)
#define MU_GSR_GIP0_SHIFT                        (0U)
/*! GIP0 - MUB General Interrupt Request Pending n
 *  0b0..MUA general purpose interrupt n is not pending.
 *  0b1..MUA general purpose interrupt n is pending.
 */
#define MU_GSR_GIP0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP0_SHIFT)) & MU_GSR_GIP0_MASK)

#define MU_GSR_GIP1_MASK                         (0x2U)
#define MU_GSR_GIP1_SHIFT                        (1U)
/*! GIP1 - MUB General Interrupt Request Pending n
 *  0b0..MUA general purpose interrupt n is not pending.
 *  0b1..MUA general purpose interrupt n is pending.
 */
#define MU_GSR_GIP1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP1_SHIFT)) & MU_GSR_GIP1_MASK)

#define MU_GSR_GIP2_MASK                         (0x4U)
#define MU_GSR_GIP2_SHIFT                        (2U)
/*! GIP2 - MUB General Interrupt Request Pending n
 *  0b0..MUA general purpose interrupt n is not pending.
 *  0b1..MUA general purpose interrupt n is pending.
 */
#define MU_GSR_GIP2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP2_SHIFT)) & MU_GSR_GIP2_MASK)

#define MU_GSR_GIP3_MASK                         (0x8U)
#define MU_GSR_GIP3_SHIFT                        (3U)
/*! GIP3 - MUB General Interrupt Request Pending n
 *  0b0..MUA general purpose interrupt n is not pending.
 *  0b1..MUA general purpose interrupt n is pending.
 */
#define MU_GSR_GIP3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP3_SHIFT)) & MU_GSR_GIP3_MASK)
/*! @} */

/*! @name TCR - Transmit Control Register */
/*! @{ */

#define MU_TCR_TIE0_MASK                         (0x1U)
#define MU_TCR_TIE0_SHIFT                        (0U)
/*! TIE0 - MUB Transmit Interrupt Enable n
 *  0b0..Disables MUA Transmit Interrupt n. (default)
 *  0b1..Enables MUA Transmit Interrupt n.
 */
#define MU_TCR_TIE0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE0_SHIFT)) & MU_TCR_TIE0_MASK)

#define MU_TCR_TIE1_MASK                         (0x2U)
#define MU_TCR_TIE1_SHIFT                        (1U)
/*! TIE1 - MUB Transmit Interrupt Enable n
 *  0b0..Disables MUA Transmit Interrupt n. (default)
 *  0b1..Enables MUA Transmit Interrupt n.
 */
#define MU_TCR_TIE1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE1_SHIFT)) & MU_TCR_TIE1_MASK)

#define MU_TCR_TIE2_MASK                         (0x4U)
#define MU_TCR_TIE2_SHIFT                        (2U)
/*! TIE2 - MUB Transmit Interrupt Enable n
 *  0b0..Disables MUA Transmit Interrupt n. (default)
 *  0b1..Enables MUA Transmit Interrupt n.
 */
#define MU_TCR_TIE2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE2_SHIFT)) & MU_TCR_TIE2_MASK)

#define MU_TCR_TIE3_MASK                         (0x8U)
#define MU_TCR_TIE3_SHIFT                        (3U)
/*! TIE3 - MUB Transmit Interrupt Enable n
 *  0b0..Disables MUA Transmit Interrupt n. (default)
 *  0b1..Enables MUA Transmit Interrupt n.
 */
#define MU_TCR_TIE3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE3_SHIFT)) & MU_TCR_TIE3_MASK)
/*! @} */

/*! @name TSR - Transmit Status Register */
/*! @{ */

#define MU_TSR_TE0_MASK                          (0x1U)
#define MU_TSR_TE0_SHIFT                         (0U)
/*! TE0 - MUB Transmit Register n Empty
 *  0b0..MUA TRn register is not empty.
 *  0b1..MUA TRn register is empty.
 */
#define MU_TSR_TE0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE0_SHIFT)) & MU_TSR_TE0_MASK)

#define MU_TSR_TE1_MASK                          (0x2U)
#define MU_TSR_TE1_SHIFT                         (1U)
/*! TE1 - MUB Transmit Register n Empty
 *  0b0..MUA TRn register is not empty.
 *  0b1..MUA TRn register is empty.
 */
#define MU_TSR_TE1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE1_SHIFT)) & MU_TSR_TE1_MASK)

#define MU_TSR_TE2_MASK                          (0x4U)
#define MU_TSR_TE2_SHIFT                         (2U)
/*! TE2 - MUB Transmit Register n Empty
 *  0b0..MUA TRn register is not empty.
 *  0b1..MUA TRn register is empty.
 */
#define MU_TSR_TE2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE2_SHIFT)) & MU_TSR_TE2_MASK)

#define MU_TSR_TE3_MASK                          (0x8U)
#define MU_TSR_TE3_SHIFT                         (3U)
/*! TE3 - MUB Transmit Register n Empty
 *  0b0..MUA TRn register is not empty.
 *  0b1..MUA TRn register is empty.
 */
#define MU_TSR_TE3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE3_SHIFT)) & MU_TSR_TE3_MASK)
/*! @} */

/*! @name RCR - Receive Control Register */
/*! @{ */

#define MU_RCR_RIE0_MASK                         (0x1U)
#define MU_RCR_RIE0_SHIFT                        (0U)
/*! RIE0 - MUB Receive Interrupt Enable n
 *  0b0..Disables MUA Receive Interrupt n.
 *  0b1..Enables MUA Receive Interrupt n.
 */
#define MU_RCR_RIE0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE0_SHIFT)) & MU_RCR_RIE0_MASK)

#define MU_RCR_RIE1_MASK                         (0x2U)
#define MU_RCR_RIE1_SHIFT                        (1U)
/*! RIE1 - MUB Receive Interrupt Enable n
 *  0b0..Disables MUA Receive Interrupt n.
 *  0b1..Enables MUA Receive Interrupt n.
 */
#define MU_RCR_RIE1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE1_SHIFT)) & MU_RCR_RIE1_MASK)

#define MU_RCR_RIE2_MASK                         (0x4U)
#define MU_RCR_RIE2_SHIFT                        (2U)
/*! RIE2 - MUB Receive Interrupt Enable n
 *  0b0..Disables MUA Receive Interrupt n.
 *  0b1..Enables MUA Receive Interrupt n.
 */
#define MU_RCR_RIE2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE2_SHIFT)) & MU_RCR_RIE2_MASK)

#define MU_RCR_RIE3_MASK                         (0x8U)
#define MU_RCR_RIE3_SHIFT                        (3U)
/*! RIE3 - MUB Receive Interrupt Enable n
 *  0b0..Disables MUA Receive Interrupt n.
 *  0b1..Enables MUA Receive Interrupt n.
 */
#define MU_RCR_RIE3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE3_SHIFT)) & MU_RCR_RIE3_MASK)
/*! @} */

/*! @name RSR - Receive Status Register */
/*! @{ */

#define MU_RSR_RF0_MASK                          (0x1U)
#define MU_RSR_RF0_SHIFT                         (0U)
/*! RF0 - MUB Receive Register n Full
 *  0b0..MUA RRn register is not full.
 *  0b1..MUA RRn register has received data from MUB TRn register and is ready to be read by the MUA.
 */
#define MU_RSR_RF0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF0_SHIFT)) & MU_RSR_RF0_MASK)

#define MU_RSR_RF1_MASK                          (0x2U)
#define MU_RSR_RF1_SHIFT                         (1U)
/*! RF1 - MUB Receive Register n Full
 *  0b0..MUA RRn register is not full.
 *  0b1..MUA RRn register has received data from MUB TRn register and is ready to be read by the MUA.
 */
#define MU_RSR_RF1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF1_SHIFT)) & MU_RSR_RF1_MASK)

#define MU_RSR_RF2_MASK                          (0x4U)
#define MU_RSR_RF2_SHIFT                         (2U)
/*! RF2 - MUB Receive Register n Full
 *  0b0..MUA RRn register is not full.
 *  0b1..MUA RRn register has received data from MUB TRn register and is ready to be read by the MUA.
 */
#define MU_RSR_RF2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF2_SHIFT)) & MU_RSR_RF2_MASK)

#define MU_RSR_RF3_MASK                          (0x8U)
#define MU_RSR_RF3_SHIFT                         (3U)
/*! RF3 - MUB Receive Register n Full
 *  0b0..MUA RRn register is not full.
 *  0b1..MUA RRn register has received data from MUB TRn register and is ready to be read by the MUA.
 */
#define MU_RSR_RF3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF3_SHIFT)) & MU_RSR_RF3_MASK)
/*! @} */

/*! @name TR - Transmit Register */
/*! @{ */

#define MU_TR_TR_DATA_MASK                       (0xFFFFFFFFU)
#define MU_TR_TR_DATA_SHIFT                      (0U)
/*! TR_DATA - MUB Transmit Data */
#define MU_TR_TR_DATA(x)                         (((uint32_t)(((uint32_t)(x)) << MU_TR_TR_DATA_SHIFT)) & MU_TR_TR_DATA_MASK)
/*! @} */

/*! @name RR - Receive Register */
/*! @{ */

#define MU_RR_RR_DATA_MASK                       (0xFFFFFFFFU)
#define MU_RR_RR_DATA_SHIFT                      (0U)
/*! RR_DATA - MUB Receive Data */
#define MU_RR_RR_DATA(x)                         (((uint32_t)(((uint32_t)(x)) << MU_RR_RR_DATA_SHIFT)) & MU_RR_RR_DATA_MASK)
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


#endif  /* MU_H_ */

