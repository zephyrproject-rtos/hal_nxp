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
**         CMSIS Peripheral Access Layer for IRQ
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
 * @file PERI_IRQ.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IRQ
 *
 * CMSIS Peripheral Access Layer for IRQ
 */

#if !defined(PERI_IRQ_H_)
#define PERI_IRQ_H_                              /**< Symbol preventing repeated inclusion */

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
   -- IRQ Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_Peripheral_Access_Layer IRQ Peripheral Access Layer
 * @{
 */

/** IRQ - Register Layout Typedef */
typedef struct {
  __IO uint8_t SC;                                 /**< Interrupt Pin Request Status and Control Register, offset: 0x0 */
} IRQ_Type;

/* ----------------------------------------------------------------------------
   -- IRQ Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_Register_Masks IRQ Register Masks
 * @{
 */

/*! @name SC - Interrupt Pin Request Status and Control Register */
/*! @{ */

#define IRQ_SC_IRQMOD_MASK                       (0x1U)
#define IRQ_SC_IRQMOD_SHIFT                      (0U)
/*! IRQMOD - IRQ Detection Mode
 *  0b0..IRQ event is detected only on falling/rising edges.
 *  0b1..IRQ event is detected on falling/rising edges and low/high levels.
 */
#define IRQ_SC_IRQMOD(x)                         (((uint8_t)(((uint8_t)(x)) << IRQ_SC_IRQMOD_SHIFT)) & IRQ_SC_IRQMOD_MASK)

#define IRQ_SC_IRQIE_MASK                        (0x2U)
#define IRQ_SC_IRQIE_SHIFT                       (1U)
/*! IRQIE - IRQ Interrupt Enable
 *  0b0..Interrupt request when IRQF set is disabled (use polling).
 *  0b1..Interrupt requested whenever IRQF = 1.
 */
#define IRQ_SC_IRQIE(x)                          (((uint8_t)(((uint8_t)(x)) << IRQ_SC_IRQIE_SHIFT)) & IRQ_SC_IRQIE_MASK)

#define IRQ_SC_IRQACK_MASK                       (0x4U)
#define IRQ_SC_IRQACK_SHIFT                      (2U)
/*! IRQACK - IRQ Acknowledge */
#define IRQ_SC_IRQACK(x)                         (((uint8_t)(((uint8_t)(x)) << IRQ_SC_IRQACK_SHIFT)) & IRQ_SC_IRQACK_MASK)

#define IRQ_SC_IRQF_MASK                         (0x8U)
#define IRQ_SC_IRQF_SHIFT                        (3U)
/*! IRQF - IRQ Flag
 *  0b0..No IRQ request
 *  0b1..IRQ event is detected.
 */
#define IRQ_SC_IRQF(x)                           (((uint8_t)(((uint8_t)(x)) << IRQ_SC_IRQF_SHIFT)) & IRQ_SC_IRQF_MASK)

#define IRQ_SC_IRQPE_MASK                        (0x10U)
#define IRQ_SC_IRQPE_SHIFT                       (4U)
/*! IRQPE - IRQ Pin Enable
 *  0b0..IRQ pin function is disabled.
 *  0b1..IRQ pin function is enabled.
 */
#define IRQ_SC_IRQPE(x)                          (((uint8_t)(((uint8_t)(x)) << IRQ_SC_IRQPE_SHIFT)) & IRQ_SC_IRQPE_MASK)

#define IRQ_SC_IRQEDG_MASK                       (0x20U)
#define IRQ_SC_IRQEDG_SHIFT                      (5U)
/*! IRQEDG - Interrupt Request (IRQ) Edge Select
 *  0b0..IRQ is falling-edge or falling-edge/low-level sensitive.
 *  0b1..IRQ is rising-edge or rising-edge/high-level sensitive.
 */
#define IRQ_SC_IRQEDG(x)                         (((uint8_t)(((uint8_t)(x)) << IRQ_SC_IRQEDG_SHIFT)) & IRQ_SC_IRQEDG_MASK)

#define IRQ_SC_IRQPDD_MASK                       (0x40U)
#define IRQ_SC_IRQPDD_SHIFT                      (6U)
/*! IRQPDD - Interrupt Request (IRQ) Pull Device Disable
 *  0b0..IRQ pull device enabled if IRQPE = 1.
 *  0b1..IRQ pull device disabled if IRQPE = 1.
 */
#define IRQ_SC_IRQPDD(x)                         (((uint8_t)(((uint8_t)(x)) << IRQ_SC_IRQPDD_SHIFT)) & IRQ_SC_IRQPDD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IRQ_Register_Masks */


/*!
 * @}
 */ /* end of group IRQ_Peripheral_Access_Layer */


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


#endif  /* PERI_IRQ_H_ */

