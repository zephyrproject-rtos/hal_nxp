/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SWT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_SWT.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for SWT
 *
 * CMSIS Peripheral Access Layer for SWT
 */

#if !defined(PERI_SWT_H_)
#define PERI_SWT_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- SWT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SWT_Peripheral_Access_Layer SWT Peripheral Access Layer
 * @{
 */

/** SWT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  __IO uint32_t IR;                                /**< Interrupt, offset: 0x4 */
  __IO uint32_t TO;                                /**< Timeout, offset: 0x8 */
  __IO uint32_t WN;                                /**< Window, offset: 0xC */
  __IO uint32_t SR;                                /**< Service, offset: 0x10 */
  __I  uint32_t CO;                                /**< Counter Output, offset: 0x14 */
  __IO uint32_t SK;                                /**< Service Key, offset: 0x18 */
  __IO uint32_t RRR;                               /**< Event Request, offset: 0x1C */
} SWT_Type;

/* ----------------------------------------------------------------------------
   -- SWT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SWT_Register_Masks SWT Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define SWT_CR_WEN_MASK                          (0x1U)
#define SWT_CR_WEN_SHIFT                         (0U)
/*! WEN - Watchdog Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SWT_CR_WEN(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_CR_WEN_SHIFT)) & SWT_CR_WEN_MASK)

#define SWT_CR_FRZ_MASK                          (0x2U)
#define SWT_CR_FRZ_SHIFT                         (1U)
/*! FRZ - Debug Mode Control
 *  0b0..Timer continues
 *  0b1..Timer stops
 */
#define SWT_CR_FRZ(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_CR_FRZ_SHIFT)) & SWT_CR_FRZ_MASK)

#define SWT_CR_STP_MASK                          (0x4U)
#define SWT_CR_STP_SHIFT                         (2U)
/*! STP - Stop Mode Control
 *  0b0..Timer continues
 *  0b1..Timer stops
 */
#define SWT_CR_STP(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_CR_STP_SHIFT)) & SWT_CR_STP_MASK)

#define SWT_CR_SLK_MASK                          (0x10U)
#define SWT_CR_SLK_SHIFT                         (4U)
/*! SLK - Soft Lock
 *  0b0..CR, TO, WN, and SK are read/write registers if HLK is also 0
 *  0b1..CR, TO, WN, and SK are read-only registers
 */
#define SWT_CR_SLK(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_CR_SLK_SHIFT)) & SWT_CR_SLK_MASK)

#define SWT_CR_HLK_MASK                          (0x20U)
#define SWT_CR_HLK_SHIFT                         (5U)
/*! HLK - Hard Lock
 *  0b0..CR, TO, WN, and SK are read/write registers if SLK is also 0
 *  0b1..CR, TO, WN, and SK are read-only registers
 */
#define SWT_CR_HLK(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_CR_HLK_SHIFT)) & SWT_CR_HLK_MASK)

#define SWT_CR_ITR_MASK                          (0x40U)
#define SWT_CR_ITR_SHIFT                         (6U)
/*! ITR - Interrupt Then Reset Request
 *  0b0..Generate a reset request on a timeout
 *  0b1..Generate an interrupt on an initial timeout; generate a reset request on a second consecutive timeout
 */
#define SWT_CR_ITR(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_CR_ITR_SHIFT)) & SWT_CR_ITR_MASK)

#define SWT_CR_WND_MASK                          (0x80U)
#define SWT_CR_WND_SHIFT                         (7U)
/*! WND - Window Mode
 *  0b0..Regular mode
 *  0b1..Window mode
 */
#define SWT_CR_WND(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_CR_WND_SHIFT)) & SWT_CR_WND_MASK)

#define SWT_CR_RIA_MASK                          (0x100U)
#define SWT_CR_RIA_SHIFT                         (8U)
/*! RIA - Reset on Invalid Access
 *  0b0..Generate a bus error
 *  0b1..Generate a bus error and reset request
 */
#define SWT_CR_RIA(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_CR_RIA_SHIFT)) & SWT_CR_RIA_MASK)

#define SWT_CR_SMD_MASK                          (0x600U)
#define SWT_CR_SMD_SHIFT                         (9U)
/*! SMD - Service Mode
 *  0b00..Fixed Service Sequence
 *  0b01..Keyed Service Sequence
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define SWT_CR_SMD(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_CR_SMD_SHIFT)) & SWT_CR_SMD_MASK)

#define SWT_CR_MAP7_MASK                         (0x1000000U)
#define SWT_CR_MAP7_SHIFT                        (24U)
/*! MAP7 - Master Access Protection 7
 *  0b0..Access disabled
 *  0b1..Access enabled
 */
#define SWT_CR_MAP7(x)                           (((uint32_t)(((uint32_t)(x)) << SWT_CR_MAP7_SHIFT)) & SWT_CR_MAP7_MASK)

#define SWT_CR_MAP6_MASK                         (0x2000000U)
#define SWT_CR_MAP6_SHIFT                        (25U)
/*! MAP6 - Master Access Protection 6
 *  0b0..Access disabled
 *  0b1..Access enabled
 */
#define SWT_CR_MAP6(x)                           (((uint32_t)(((uint32_t)(x)) << SWT_CR_MAP6_SHIFT)) & SWT_CR_MAP6_MASK)

#define SWT_CR_MAP5_MASK                         (0x4000000U)
#define SWT_CR_MAP5_SHIFT                        (26U)
/*! MAP5 - Master Access Protection 5
 *  0b0..Access disabled
 *  0b1..Access enabled
 */
#define SWT_CR_MAP5(x)                           (((uint32_t)(((uint32_t)(x)) << SWT_CR_MAP5_SHIFT)) & SWT_CR_MAP5_MASK)

#define SWT_CR_MAP4_MASK                         (0x8000000U)
#define SWT_CR_MAP4_SHIFT                        (27U)
/*! MAP4 - Master Access Protection 4
 *  0b0..Access disabled
 *  0b1..Access enabled
 */
#define SWT_CR_MAP4(x)                           (((uint32_t)(((uint32_t)(x)) << SWT_CR_MAP4_SHIFT)) & SWT_CR_MAP4_MASK)

#define SWT_CR_MAP3_MASK                         (0x10000000U)
#define SWT_CR_MAP3_SHIFT                        (28U)
/*! MAP3 - Master Access Protection 3
 *  0b0..Access disabled
 *  0b1..Access enabled
 */
#define SWT_CR_MAP3(x)                           (((uint32_t)(((uint32_t)(x)) << SWT_CR_MAP3_SHIFT)) & SWT_CR_MAP3_MASK)

#define SWT_CR_MAP2_MASK                         (0x20000000U)
#define SWT_CR_MAP2_SHIFT                        (29U)
/*! MAP2 - Master Access Protection 2
 *  0b0..Access disabled
 *  0b1..Access enabled
 */
#define SWT_CR_MAP2(x)                           (((uint32_t)(((uint32_t)(x)) << SWT_CR_MAP2_SHIFT)) & SWT_CR_MAP2_MASK)

#define SWT_CR_MAP1_MASK                         (0x40000000U)
#define SWT_CR_MAP1_SHIFT                        (30U)
/*! MAP1 - Master Access Protection 1
 *  0b0..Access disabled
 *  0b1..Access enabled
 */
#define SWT_CR_MAP1(x)                           (((uint32_t)(((uint32_t)(x)) << SWT_CR_MAP1_SHIFT)) & SWT_CR_MAP1_MASK)

#define SWT_CR_MAP0_MASK                         (0x80000000U)
#define SWT_CR_MAP0_SHIFT                        (31U)
/*! MAP0 - Master Access Protection 0
 *  0b0..Access disabled
 *  0b1..Access enabled
 */
#define SWT_CR_MAP0(x)                           (((uint32_t)(((uint32_t)(x)) << SWT_CR_MAP0_SHIFT)) & SWT_CR_MAP0_MASK)
/*! @} */

/*! @name IR - Interrupt */
/*! @{ */

#define SWT_IR_TIF_MASK                          (0x1U)
#define SWT_IR_TIF_SHIFT                         (0U)
/*! TIF - Timeout Interrupt Flag
 *  0b0..No interrupt request
 *  0b1..Interrupt request due to an initial timeout
 */
#define SWT_IR_TIF(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_IR_TIF_SHIFT)) & SWT_IR_TIF_MASK)
/*! @} */

/*! @name TO - Timeout */
/*! @{ */

#define SWT_TO_WTO_MASK                          (0xFFFFFFFFU)
#define SWT_TO_WTO_SHIFT                         (0U)
/*! WTO - Watchdog Timeout */
#define SWT_TO_WTO(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_TO_WTO_SHIFT)) & SWT_TO_WTO_MASK)
/*! @} */

/*! @name WN - Window */
/*! @{ */

#define SWT_WN_WST_MASK                          (0xFFFFFFFFU)
#define SWT_WN_WST_SHIFT                         (0U)
/*! WST - Window Start Value */
#define SWT_WN_WST(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_WN_WST_SHIFT)) & SWT_WN_WST_MASK)
/*! @} */

/*! @name SR - Service */
/*! @{ */

#define SWT_SR_WSC_MASK                          (0xFFFFU)
#define SWT_SR_WSC_SHIFT                         (0U)
/*! WSC - Watchdog Service Code */
#define SWT_SR_WSC(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_SR_WSC_SHIFT)) & SWT_SR_WSC_MASK)
/*! @} */

/*! @name CO - Counter Output */
/*! @{ */

#define SWT_CO_CNT_MASK                          (0xFFFFFFFFU)
#define SWT_CO_CNT_SHIFT                         (0U)
/*! CNT - Watchdog Count */
#define SWT_CO_CNT(x)                            (((uint32_t)(((uint32_t)(x)) << SWT_CO_CNT_SHIFT)) & SWT_CO_CNT_MASK)
/*! @} */

/*! @name SK - Service Key */
/*! @{ */

#define SWT_SK_SK_MASK                           (0xFFFFU)
#define SWT_SK_SK_SHIFT                          (0U)
/*! SK - Service Key */
#define SWT_SK_SK(x)                             (((uint32_t)(((uint32_t)(x)) << SWT_SK_SK_SHIFT)) & SWT_SK_SK_MASK)
/*! @} */

/*! @name RRR - Event Request */
/*! @{ */

#define SWT_RRR_RRF_MASK                         (0x1U)
#define SWT_RRR_RRF_SHIFT                        (0U)
/*! RRF - Reset Request Flag
 *  0b0..No reset request
 *  0b1..Any reset request initiated
 */
#define SWT_RRR_RRF(x)                           (((uint32_t)(((uint32_t)(x)) << SWT_RRR_RRF_SHIFT)) & SWT_RRR_RRF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SWT_Register_Masks */


/*!
 * @}
 */ /* end of group SWT_Peripheral_Access_Layer */


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


#endif  /* PERI_SWT_H_ */

