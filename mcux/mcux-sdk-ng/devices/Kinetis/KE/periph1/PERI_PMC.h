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
**         CMSIS Peripheral Access Layer for PMC
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
 * @file PERI_PMC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PMC
 *
 * CMSIS Peripheral Access Layer for PMC
 */

#if !defined(PERI_PMC_H_)
#define PERI_PMC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __IO uint8_t SPMSC1;                             /**< System Power Management Status and Control 1 Register, offset: 0x0 */
  __IO uint8_t SPMSC2;                             /**< System Power Management Status and Control 2 Register, offset: 0x1 */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name SPMSC1 - System Power Management Status and Control 1 Register */
/*! @{ */

#define PMC_SPMSC1_BGBE_MASK                     (0x1U)
#define PMC_SPMSC1_BGBE_SHIFT                    (0U)
/*! BGBE - Bandgap Buffer Enable
 *  0b0..Bandgap buffer is disabled.
 *  0b1..Bandgap buffer is enabled.
 */
#define PMC_SPMSC1_BGBE(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_SPMSC1_BGBE_SHIFT)) & PMC_SPMSC1_BGBE_MASK)

#define PMC_SPMSC1_LVDE_MASK                     (0x4U)
#define PMC_SPMSC1_LVDE_SHIFT                    (2U)
/*! LVDE - Low-Voltage Detect Enable
 *  0b0..LVD logic is disabled.
 *  0b1..LVD logic is enabled.
 */
#define PMC_SPMSC1_LVDE(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_SPMSC1_LVDE_SHIFT)) & PMC_SPMSC1_LVDE_MASK)

#define PMC_SPMSC1_LVDSE_MASK                    (0x8U)
#define PMC_SPMSC1_LVDSE_SHIFT                   (3U)
/*! LVDSE - Low-Voltage Detect Stop Enable
 *  0b0..Low-voltage detect is disabled during Stop mode.
 *  0b1..Low-voltage detect is enabled during Stop mode.
 */
#define PMC_SPMSC1_LVDSE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_SPMSC1_LVDSE_SHIFT)) & PMC_SPMSC1_LVDSE_MASK)

#define PMC_SPMSC1_LVDRE_MASK                    (0x10U)
#define PMC_SPMSC1_LVDRE_SHIFT                   (4U)
/*! LVDRE - Low-Voltage Detect Reset Enable
 *  0b0..LVD events do not generate hardware resets.
 *  0b1..Forces an MCU reset when an enabled low-voltage detect event occurs.
 */
#define PMC_SPMSC1_LVDRE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_SPMSC1_LVDRE_SHIFT)) & PMC_SPMSC1_LVDRE_MASK)

#define PMC_SPMSC1_LVWIE_MASK                    (0x20U)
#define PMC_SPMSC1_LVWIE_SHIFT                   (5U)
/*! LVWIE - Low-Voltage Warning Interrupt Enable
 *  0b0..Hardware interrupt is disabled (use polling).
 *  0b1..Requests a hardware interrupt when LVWF = 1.
 */
#define PMC_SPMSC1_LVWIE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_SPMSC1_LVWIE_SHIFT)) & PMC_SPMSC1_LVWIE_MASK)

#define PMC_SPMSC1_LVWACK_MASK                   (0x40U)
#define PMC_SPMSC1_LVWACK_SHIFT                  (6U)
/*! LVWACK - Low-Voltage Warning Acknowledge */
#define PMC_SPMSC1_LVWACK(x)                     (((uint8_t)(((uint8_t)(x)) << PMC_SPMSC1_LVWACK_SHIFT)) & PMC_SPMSC1_LVWACK_MASK)

#define PMC_SPMSC1_LVWF_MASK                     (0x80U)
#define PMC_SPMSC1_LVWF_SHIFT                    (7U)
/*! LVWF - Low-Voltage Warning Flag
 *  0b0..Low-voltage warning is not present.
 *  0b1..Low-voltage warning is present or was present.
 */
#define PMC_SPMSC1_LVWF(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_SPMSC1_LVWF_SHIFT)) & PMC_SPMSC1_LVWF_MASK)
/*! @} */

/*! @name SPMSC2 - System Power Management Status and Control 2 Register */
/*! @{ */

#define PMC_SPMSC2_LVWV_MASK                     (0x30U)
#define PMC_SPMSC2_LVWV_SHIFT                    (4U)
/*! LVWV - Low-Voltage Warning Voltage Select
 *  0b00..Low trip point is selected (VLVW = VLVW1).
 *  0b01..Middle 1 trip point is selected (VLVW = VLVW2).
 *  0b10..Middle 2 trip point is selected (VLVW = VLVW3).
 *  0b11..High trip point is selected (VLVW = VLVW4).
 */
#define PMC_SPMSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_SPMSC2_LVWV_SHIFT)) & PMC_SPMSC2_LVWV_MASK)

#define PMC_SPMSC2_LVDV_MASK                     (0x40U)
#define PMC_SPMSC2_LVDV_SHIFT                    (6U)
/*! LVDV - Low-Voltage Detect Voltage Select
 *  0b0..Low trip point is selected (VLVD = VLVDL).
 *  0b1..High trip point is selected (VLVD = VLVDH).
 */
#define PMC_SPMSC2_LVDV(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_SPMSC2_LVDV_SHIFT)) & PMC_SPMSC2_LVDV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */


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


#endif  /* PERI_PMC_H_ */

