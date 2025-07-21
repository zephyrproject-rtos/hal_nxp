/*
** ###################################################################
**     Processors:          MKE02Z16VFM4
**                          MKE02Z16VLC4
**                          MKE02Z16VLD4
**                          MKE02Z32VFM4
**                          MKE02Z32VLC4
**                          MKE02Z32VLD4
**                          MKE02Z32VLH4
**                          MKE02Z32VQH4
**                          MKE02Z64VFM4
**                          MKE02Z64VLC4
**                          MKE02Z64VLD4
**                          MKE02Z64VLH4
**                          MKE02Z64VQH4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ICS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-05-19)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ICS.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ICS
 *
 * CMSIS Peripheral Access Layer for ICS
 */

#if !defined(PERI_ICS_H_)
#define PERI_ICS_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE02Z16VFM4) || defined(CPU_MKE02Z16VLC4) || defined(CPU_MKE02Z16VLD4) || defined(CPU_MKE02Z32VFM4) || defined(CPU_MKE02Z32VLC4) || defined(CPU_MKE02Z32VLD4) || defined(CPU_MKE02Z32VLH4) || defined(CPU_MKE02Z32VQH4) || defined(CPU_MKE02Z64VFM4) || defined(CPU_MKE02Z64VLC4) || defined(CPU_MKE02Z64VLD4) || defined(CPU_MKE02Z64VLH4) || defined(CPU_MKE02Z64VQH4))
#include "MKE02Z4_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ICS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ICS_Peripheral_Access_Layer ICS Peripheral Access Layer
 * @{
 */

/** ICS - Register Layout Typedef */
typedef struct {
  __IO uint8_t C1;                                 /**< ICS Control Register 1, offset: 0x0 */
  __IO uint8_t C2;                                 /**< ICS Control Register 2, offset: 0x1 */
  __IO uint8_t C3;                                 /**< ICS Control Register 3, offset: 0x2 */
  __IO uint8_t C4;                                 /**< ICS Control Register 4, offset: 0x3 */
  __IO uint8_t S;                                  /**< ICS Status Register, offset: 0x4 */
} ICS_Type;

/* ----------------------------------------------------------------------------
   -- ICS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ICS_Register_Masks ICS Register Masks
 * @{
 */

/*! @name C1 - ICS Control Register 1 */
/*! @{ */

#define ICS_C1_IREFSTEN_MASK                     (0x1U)
#define ICS_C1_IREFSTEN_SHIFT                    (0U)
/*! IREFSTEN - Internal Reference Stop Enable
 *  0b0..Internal reference clock is disabled in Stop mode.
 *  0b1..Internal reference clock stays enabled in Stop mode if IRCLKEN is set, or if ICS is in FEI, FBI, or FBILP mode before entering Stop.
 */
#define ICS_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x)) << ICS_C1_IREFSTEN_SHIFT)) & ICS_C1_IREFSTEN_MASK)

#define ICS_C1_IRCLKEN_MASK                      (0x2U)
#define ICS_C1_IRCLKEN_SHIFT                     (1U)
/*! IRCLKEN - Internal Reference Clock Enable
 *  0b0..ICSIRCLK is inactive.
 *  0b1..ICSIRCLK is active.
 */
#define ICS_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x)) << ICS_C1_IRCLKEN_SHIFT)) & ICS_C1_IRCLKEN_MASK)

#define ICS_C1_IREFS_MASK                        (0x4U)
#define ICS_C1_IREFS_SHIFT                       (2U)
/*! IREFS - Internal Reference Select
 *  0b0..External reference clock is selected.
 *  0b1..Internal reference clock is selected.
 */
#define ICS_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x)) << ICS_C1_IREFS_SHIFT)) & ICS_C1_IREFS_MASK)

#define ICS_C1_RDIV_MASK                         (0x38U)
#define ICS_C1_RDIV_SHIFT                        (3U)
/*! RDIV - Reference Divider */
#define ICS_C1_RDIV(x)                           (((uint8_t)(((uint8_t)(x)) << ICS_C1_RDIV_SHIFT)) & ICS_C1_RDIV_MASK)

#define ICS_C1_CLKS_MASK                         (0xC0U)
#define ICS_C1_CLKS_SHIFT                        (6U)
/*! CLKS - Clock Source Select
 *  0b00..Output of FLL is selected.
 *  0b01..Internal reference clock is selected.
 *  0b10..External reference clock is selected.
 *  0b11..Reserved, defaults to 00.
 */
#define ICS_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x)) << ICS_C1_CLKS_SHIFT)) & ICS_C1_CLKS_MASK)
/*! @} */

/*! @name C2 - ICS Control Register 2 */
/*! @{ */

#define ICS_C2_LP_MASK                           (0x10U)
#define ICS_C2_LP_SHIFT                          (4U)
/*! LP - Low Power Select
 *  0b0..FLL is not disabled in bypass mode.
 *  0b1..FLL is disabled in bypass modes unless debug is active.
 */
#define ICS_C2_LP(x)                             (((uint8_t)(((uint8_t)(x)) << ICS_C2_LP_SHIFT)) & ICS_C2_LP_MASK)

#define ICS_C2_BDIV_MASK                         (0xE0U)
#define ICS_C2_BDIV_SHIFT                        (5U)
/*! BDIV - Bus Frequency Divider
 *  0b000..Encoding 0-Divides the selected clock by 1.
 *  0b001..Encoding 1-Divides the selected clock by 2 (reset default).
 *  0b010..Encoding 2-Divides the selected clock by 4.
 *  0b011..Encoding 3-Divides the selected clock by 8.
 *  0b100..Encoding 4-Divides the selected clock by 16.
 *  0b101..Encoding 5-Divides the selected clock by 32.
 *  0b110..Encoding 6-Divides the selected clock by 64.
 *  0b111..Encoding 7-Divides the selected clock by 128.
 */
#define ICS_C2_BDIV(x)                           (((uint8_t)(((uint8_t)(x)) << ICS_C2_BDIV_SHIFT)) & ICS_C2_BDIV_MASK)
/*! @} */

/*! @name C3 - ICS Control Register 3 */
/*! @{ */

#define ICS_C3_SCTRIM_MASK                       (0xFFU)
#define ICS_C3_SCTRIM_SHIFT                      (0U)
/*! SCTRIM - Slow Internal Reference Clock Trim Setting */
#define ICS_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x)) << ICS_C3_SCTRIM_SHIFT)) & ICS_C3_SCTRIM_MASK)
/*! @} */

/*! @name C4 - ICS Control Register 4 */
/*! @{ */

#define ICS_C4_SCFTRIM_MASK                      (0x1U)
#define ICS_C4_SCFTRIM_SHIFT                     (0U)
/*! SCFTRIM - Slow Internal Reference Clock Fine Trim */
#define ICS_C4_SCFTRIM(x)                        (((uint8_t)(((uint8_t)(x)) << ICS_C4_SCFTRIM_SHIFT)) & ICS_C4_SCFTRIM_MASK)

#define ICS_C4_CME_MASK                          (0x20U)
#define ICS_C4_CME_SHIFT                         (5U)
/*! CME - Clock Monitor Enable
 *  0b0..Clock monitor is disabled.
 *  0b1..Generates a reset request on loss of external clock.
 */
#define ICS_C4_CME(x)                            (((uint8_t)(((uint8_t)(x)) << ICS_C4_CME_SHIFT)) & ICS_C4_CME_MASK)

#define ICS_C4_LOLIE_MASK                        (0x80U)
#define ICS_C4_LOLIE_SHIFT                       (7U)
/*! LOLIE - Loss of Lock Interrupt
 *  0b0..No request on loss of lock.
 *  0b1..Generates an interrupt request on loss of lock.
 */
#define ICS_C4_LOLIE(x)                          (((uint8_t)(((uint8_t)(x)) << ICS_C4_LOLIE_SHIFT)) & ICS_C4_LOLIE_MASK)
/*! @} */

/*! @name S - ICS Status Register */
/*! @{ */

#define ICS_S_CLKST_MASK                         (0xCU)
#define ICS_S_CLKST_SHIFT                        (2U)
/*! CLKST - Clock Mode Status
 *  0b00..Output of FLL is selected.
 *  0b01..FLL Bypassed, internal reference clock is selected.
 *  0b10..FLL Bypassed, external reference clock is selected.
 *  0b11..Reserved.
 */
#define ICS_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x)) << ICS_S_CLKST_SHIFT)) & ICS_S_CLKST_MASK)

#define ICS_S_IREFST_MASK                        (0x10U)
#define ICS_S_IREFST_SHIFT                       (4U)
/*! IREFST - Internal Reference Status
 *  0b0..Source of reference clock is external clock.
 *  0b1..Source of reference clock is internal clock.
 */
#define ICS_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x)) << ICS_S_IREFST_SHIFT)) & ICS_S_IREFST_MASK)

#define ICS_S_LOCK_MASK                          (0x40U)
#define ICS_S_LOCK_SHIFT                         (6U)
/*! LOCK - Lock Status
 *  0b0..FLL is currently unlocked.
 *  0b1..FLL is currently locked.
 */
#define ICS_S_LOCK(x)                            (((uint8_t)(((uint8_t)(x)) << ICS_S_LOCK_SHIFT)) & ICS_S_LOCK_MASK)

#define ICS_S_LOLS_MASK                          (0x80U)
#define ICS_S_LOLS_SHIFT                         (7U)
/*! LOLS - Loss of Lock Status
 *  0b0..FLL has not lost lock since LOLS was last cleared.
 *  0b1..FLL has lost lock since LOLS was last cleared.
 */
#define ICS_S_LOLS(x)                            (((uint8_t)(((uint8_t)(x)) << ICS_S_LOLS_SHIFT)) & ICS_S_LOLS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ICS_Register_Masks */


/*!
 * @}
 */ /* end of group ICS_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_ICS_H_ */

