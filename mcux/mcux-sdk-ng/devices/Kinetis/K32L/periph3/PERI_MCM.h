/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MCM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCM
 *
 * CMSIS Peripheral Access Layer for MCM
 */

#if !defined(PERI_MCM_H_)
#define PERI_MCM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __I  uint16_t PLASC;                             /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  __I  uint16_t PLAMC;                             /**< Crossbar Switch (AXBS) Master Configuration, offset: 0xA */
  __IO uint32_t CPCR;                              /**< Core Platform Control Register, offset: 0xC */
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control Register, offset: 0x10, available only on: MCM0 (missing on MCM1) */
       uint8_t RESERVED_1[32];
  __IO uint32_t CPCR2;                             /**< Core Platform Control Register 2, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __IO uint32_t CPO;                               /**< Compute Operation Control Register, offset: 0x40 */
} MCM_Type;

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/*! @name PLASC - Crossbar Switch (AXBS) Slave Configuration */
/*! @{ */

#define MCM_PLASC_ASC_MASK                       (0xFFU)
#define MCM_PLASC_ASC_SHIFT                      (0U)
/*! ASC - Each bit in the ASC field indicates whether there is a corresponding connection to the
 *    crossbar switch's slave input port.
 *  0b00000000..A bus slave connection to AXBS input port n is absent
 *  0b00000001..A bus slave connection to AXBS input port n is present
 */
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC_SHIFT)) & MCM_PLASC_ASC_MASK)
/*! @} */

/*! @name PLAMC - Crossbar Switch (AXBS) Master Configuration */
/*! @{ */

#define MCM_PLAMC_AMC_MASK                       (0xFFU)
#define MCM_PLAMC_AMC_SHIFT                      (0U)
/*! AMC - Each bit in the AMC field indicates whether there is a corresponding connection to the AXBS master input port.
 *  0b00000000..A bus master connection to AXBS input port n is absent
 *  0b00000001..A bus master connection to AXBS input port n is present
 */
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC_SHIFT)) & MCM_PLAMC_AMC_MASK)
/*! @} */

/*! @name CPCR - Core Platform Control Register */
/*! @{ */

#define MCM_CPCR_ARB_MASK                        (0x200U)
#define MCM_CPCR_ARB_SHIFT                       (9U)
/*! ARB - Arbitration select
 *  0b0..Fixed-priority arbitration for the crossbar masters
 *  0b1..Round-robin arbitration for the crossbar masters
 */
#define MCM_CPCR_ARB(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_ARB_SHIFT)) & MCM_CPCR_ARB_MASK)

#define MCM_CPCR_CBRR_MASK                       (0x200U)
#define MCM_CPCR_CBRR_SHIFT                      (9U)
/*! CBRR - Crossbar round-robin arbitration enable
 *  0b0..Fixed-priority arbitration
 *  0b1..Round-robin arbitration
 */
#define MCM_CPCR_CBRR(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_CBRR_SHIFT)) & MCM_CPCR_CBRR_MASK)
/*! @} */

/*! @name ISCR - Interrupt Status and Control Register */
/*! @{ */

#define MCM_ISCR_FIOC_MASK                       (0x100U)
#define MCM_ISCR_FIOC_SHIFT                      (8U)
/*! FIOC - FPU invalid operation interrupt status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIOC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOC_SHIFT)) & MCM_ISCR_FIOC_MASK)

#define MCM_ISCR_FDZC_MASK                       (0x200U)
#define MCM_ISCR_FDZC_SHIFT                      (9U)
/*! FDZC - FPU divide-by-zero interrupt status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FDZC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZC_SHIFT)) & MCM_ISCR_FDZC_MASK)

#define MCM_ISCR_FOFC_MASK                       (0x400U)
#define MCM_ISCR_FOFC_SHIFT                      (10U)
/*! FOFC - FPU overflow interrupt status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FOFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFC_SHIFT)) & MCM_ISCR_FOFC_MASK)

#define MCM_ISCR_FUFC_MASK                       (0x800U)
#define MCM_ISCR_FUFC_SHIFT                      (11U)
/*! FUFC - FPU underflow interrupt status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FUFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFC_SHIFT)) & MCM_ISCR_FUFC_MASK)

#define MCM_ISCR_FIXC_MASK                       (0x1000U)
#define MCM_ISCR_FIXC_SHIFT                      (12U)
/*! FIXC - FPU inexact interrupt status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIXC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXC_SHIFT)) & MCM_ISCR_FIXC_MASK)

#define MCM_ISCR_FIDC_MASK                       (0x8000U)
#define MCM_ISCR_FIDC_SHIFT                      (15U)
/*! FIDC - FPU input denormal interrupt status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIDC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDC_SHIFT)) & MCM_ISCR_FIDC_MASK)

#define MCM_ISCR_FIOCE_MASK                      (0x1000000U)
#define MCM_ISCR_FIOCE_SHIFT                     (24U)
/*! FIOCE - FPU invalid operation interrupt enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIOCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOCE_SHIFT)) & MCM_ISCR_FIOCE_MASK)

#define MCM_ISCR_FDZCE_MASK                      (0x2000000U)
#define MCM_ISCR_FDZCE_SHIFT                     (25U)
/*! FDZCE - FPU divide-by-zero interrupt enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FDZCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZCE_SHIFT)) & MCM_ISCR_FDZCE_MASK)

#define MCM_ISCR_FOFCE_MASK                      (0x4000000U)
#define MCM_ISCR_FOFCE_SHIFT                     (26U)
/*! FOFCE - FPU overflow interrupt enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FOFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFCE_SHIFT)) & MCM_ISCR_FOFCE_MASK)

#define MCM_ISCR_FUFCE_MASK                      (0x8000000U)
#define MCM_ISCR_FUFCE_SHIFT                     (27U)
/*! FUFCE - FPU underflow interrupt enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FUFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFCE_SHIFT)) & MCM_ISCR_FUFCE_MASK)

#define MCM_ISCR_FIXCE_MASK                      (0x10000000U)
#define MCM_ISCR_FIXCE_SHIFT                     (28U)
/*! FIXCE - FPU inexact interrupt enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIXCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXCE_SHIFT)) & MCM_ISCR_FIXCE_MASK)

#define MCM_ISCR_FIDCE_MASK                      (0x80000000U)
#define MCM_ISCR_FIDCE_SHIFT                     (31U)
/*! FIDCE - FPU input denormal interrupt enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIDCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDCE_SHIFT)) & MCM_ISCR_FIDCE_MASK)
/*! @} */

/*! @name CPCR2 - Core Platform Control Register 2 */
/*! @{ */

#define MCM_CPCR2_CCBC_MASK                      (0x1U)
#define MCM_CPCR2_CCBC_SHIFT                     (0U)
/*! CCBC - Clear code bus cache, this field always reads as 0.
 *  0b0..No effect
 *  0b1..Clear code bus cache
 */
#define MCM_CPCR2_CCBC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_CCBC_SHIFT)) & MCM_CPCR2_CCBC_MASK)

#define MCM_CPCR2_DCBC_MASK                      (0x8U)
#define MCM_CPCR2_DCBC_SHIFT                     (3U)
/*! DCBC - Disable code bus cache
 *  0b0..Enable code bus cache
 *  0b1..Disable code bus cache
 */
#define MCM_CPCR2_DCBC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_DCBC_SHIFT)) & MCM_CPCR2_DCBC_MASK)

#define MCM_CPCR2_DCC_MASK                       (0x8U)
#define MCM_CPCR2_DCC_SHIFT                      (3U)
/*! DCC - Disable the code cache */
#define MCM_CPCR2_DCC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_DCC_SHIFT)) & MCM_CPCR2_DCC_MASK)

#define MCM_CPCR2_CBCS_MASK                      (0xF0U)
#define MCM_CPCR2_CBCS_SHIFT                     (4U)
/*! CBCS - Code Bus Cache Size
 *  0b0000..0 KB
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 */
#define MCM_CPCR2_CBCS(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_CBCS_SHIFT)) & MCM_CPCR2_CBCS_MASK)

#define MCM_CPCR2_CCSIZ_MASK                     (0xF0U)
#define MCM_CPCR2_CCSIZ_SHIFT                    (4U)
/*! CCSIZ - Code cache size
 *  0b0000..No cache
 *  0b0010..2KB
 *  0b0011..4KB
 *  0b0100..8KB
 */
#define MCM_CPCR2_CCSIZ(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_CCSIZ_SHIFT)) & MCM_CPCR2_CCSIZ_MASK)

#define MCM_CPCR2_PCCMCTRL_MASK                  (0x10000U)
#define MCM_CPCR2_PCCMCTRL_SHIFT                 (16U)
/*! PCCMCTRL - Bypass fixed code cache map
 *  0b0..The fixed code cache map is not bypassed
 *  0b1..The fixed code cache map is bypassed
 */
#define MCM_CPCR2_PCCMCTRL(x)                    (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_PCCMCTRL_SHIFT)) & MCM_CPCR2_PCCMCTRL_MASK)

#define MCM_CPCR2_LCCPWB_MASK                    (0x20000U)
#define MCM_CPCR2_LCCPWB_SHIFT                   (17U)
/*! LCCPWB - Limit code cache peripheral write buffering
 *  0b0..Code cache peripheral write buffering is not limited
 *  0b1..Code cache peripheral write buffering is limited
 */
#define MCM_CPCR2_LCCPWB(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_LCCPWB_SHIFT)) & MCM_CPCR2_LCCPWB_MASK)
/*! @} */

/*! @name CPO - Compute Operation Control Register */
/*! @{ */

#define MCM_CPO_CPOREQ_MASK                      (0x1U)
#define MCM_CPO_CPOREQ_SHIFT                     (0U)
/*! CPOREQ - Compute Operation request
 *  0b0..Request is cleared.
 *  0b1..Request Compute Operation.
 */
#define MCM_CPO_CPOREQ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOREQ_SHIFT)) & MCM_CPO_CPOREQ_MASK)

#define MCM_CPO_CPOACK_MASK                      (0x2U)
#define MCM_CPO_CPOACK_SHIFT                     (1U)
/*! CPOACK - Compute Operation acknowledge
 *  0b0..Compute operation entry has not completed or compute operation exit has completed.
 *  0b1..Compute operation entry has completed or compute operation exit has not completed.
 */
#define MCM_CPO_CPOACK(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOACK_SHIFT)) & MCM_CPO_CPOACK_MASK)

#define MCM_CPO_CPOWOI_MASK                      (0x4U)
#define MCM_CPO_CPOWOI_SHIFT                     (2U)
/*! CPOWOI - Compute Operation wakeup on interrupt
 *  0b0..No effect.
 *  0b1..When set, the CPOREQ is cleared on any interrupt or exception vector fetch.
 */
#define MCM_CPO_CPOWOI(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOWOI_SHIFT)) & MCM_CPO_CPOWOI_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


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


#endif  /* PERI_MCM_H_ */

