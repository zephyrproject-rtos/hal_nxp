/*
** ###################################################################
**     Processors:          LPC822M101JDH20
**                          LPC822M101JHI33
**                          LPC824M201JDH20
**                          LPC824M201JHI33
**                          LPC832M101FDH20
**                          LPC834M101FHI33
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ACOMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-02-09)
**         Initial version.
**     - rev. 1.1 (2018-02-25)
**         Update some registers according to UM rev 1.2
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ACOMP.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ACOMP
 *
 * CMSIS Peripheral Access Layer for ACOMP
 */

#if !defined(PERI_ACOMP_H_)
#define PERI_ACOMP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC822M101JDH20) || defined(CPU_LPC822M101JHI33))
#include "LPC822_COMMON.h"
#elif (defined(CPU_LPC824M201JDH20) || defined(CPU_LPC824M201JHI33))
#include "LPC824_COMMON.h"
#elif (defined(CPU_LPC832M101FDH20))
#include "LPC832_COMMON.h"
#elif (defined(CPU_LPC834M101FHI33))
#include "LPC834_COMMON.h"
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
   -- ACOMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACOMP_Peripheral_Access_Layer ACOMP Peripheral Access Layer
 * @{
 */

/** ACOMP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Comparator control register, offset: 0x0 */
  __IO uint32_t LAD;                               /**< Voltage ladder register, offset: 0x4 */
} ACOMP_Type;

/* ----------------------------------------------------------------------------
   -- ACOMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACOMP_Register_Masks ACOMP Register Masks
 * @{
 */

/*! @name CTRL - Comparator control register */
/*! @{ */

#define ACOMP_CTRL_EDGESEL_MASK                  (0x18U)
#define ACOMP_CTRL_EDGESEL_SHIFT                 (3U)
/*! EDGESEL - This field controls which edges on the comparator output set the COMPEDGE bit (bit 23 below):
 *  0b00..Falling edges
 *  0b01..Rising edges
 *  0b10..Both edges
 *  0b11..Both edges
 */
#define ACOMP_CTRL_EDGESEL(x)                    (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_EDGESEL_SHIFT)) & ACOMP_CTRL_EDGESEL_MASK)

#define ACOMP_CTRL_COMPSA_MASK                   (0x40U)
#define ACOMP_CTRL_COMPSA_SHIFT                  (6U)
/*! COMPSA - Comparator output control
 *  0b0..Comparator output is used directly.
 *  0b1..Comparator output is synchronized to the bus clock for output to other modules.
 */
#define ACOMP_CTRL_COMPSA(x)                     (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_COMPSA_SHIFT)) & ACOMP_CTRL_COMPSA_MASK)

#define ACOMP_CTRL_COMP_VP_SEL_MASK              (0x700U)
#define ACOMP_CTRL_COMP_VP_SEL_SHIFT             (8U)
/*! COMP_VP_SEL - Selects positive voltage input
 *  0b000..VOLTAGE_LADDER_OUTPUT
 *  0b001..ACMP_I1
 *  0b010..ACMP_I2
 *  0b011..ACMP_I3
 *  0b100..ACMP_I4
 *  0b101..Band gap. Internal reference voltage.
 *  0b110..ADC channel 0 input
 *  0b111..Reserved
 */
#define ACOMP_CTRL_COMP_VP_SEL(x)                (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_COMP_VP_SEL_SHIFT)) & ACOMP_CTRL_COMP_VP_SEL_MASK)

#define ACOMP_CTRL_COMP_VM_SEL_MASK              (0x3800U)
#define ACOMP_CTRL_COMP_VM_SEL_SHIFT             (11U)
/*! COMP_VM_SEL - Selects negative voltage input
 *  0b000..VOLTAGE_LADDER_OUTPUT
 *  0b001..ACMP_I1
 *  0b010..ACMP_I2
 *  0b011..ACMP_I3
 *  0b100..ACMP_I4
 *  0b101..Band gap. Internal reference voltage.
 *  0b110..ADC channel 0 input
 *  0b111..Reserved
 */
#define ACOMP_CTRL_COMP_VM_SEL(x)                (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_COMP_VM_SEL_SHIFT)) & ACOMP_CTRL_COMP_VM_SEL_MASK)

#define ACOMP_CTRL_EDGECLR_MASK                  (0x100000U)
#define ACOMP_CTRL_EDGECLR_SHIFT                 (20U)
/*! EDGECLR - Interrupt clear bit. To clear the COMPEDGE bit and thus negate the interrupt request,
 *    toggle the EDGECLR bit by first writing a 1 and then a 0.
 */
#define ACOMP_CTRL_EDGECLR(x)                    (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_EDGECLR_SHIFT)) & ACOMP_CTRL_EDGECLR_MASK)

#define ACOMP_CTRL_COMPSTAT_MASK                 (0x200000U)
#define ACOMP_CTRL_COMPSTAT_SHIFT                (21U)
/*! COMPSTAT - Comparator status. This bit reflects the state of the comparator output. */
#define ACOMP_CTRL_COMPSTAT(x)                   (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_COMPSTAT_SHIFT)) & ACOMP_CTRL_COMPSTAT_MASK)

#define ACOMP_CTRL_COMPEDGE_MASK                 (0x800000U)
#define ACOMP_CTRL_COMPEDGE_SHIFT                (23U)
/*! COMPEDGE - Comparator edge-detect status. */
#define ACOMP_CTRL_COMPEDGE(x)                   (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_COMPEDGE_SHIFT)) & ACOMP_CTRL_COMPEDGE_MASK)

#define ACOMP_CTRL_HYS_MASK                      (0x6000000U)
#define ACOMP_CTRL_HYS_SHIFT                     (25U)
/*! HYS - Controls the hysteresis of the comparator. When the comparator is outputting a certain
 *    state, this is the difference between the selected signals, in the opposite direction from the
 *    state being output, that will switch the output.
 *  0b00..None (the output will switch as the voltages cross)
 *  0b01..5 mv
 *  0b10..10 mv
 *  0b11..20 mv
 */
#define ACOMP_CTRL_HYS(x)                        (((uint32_t)(((uint32_t)(x)) << ACOMP_CTRL_HYS_SHIFT)) & ACOMP_CTRL_HYS_MASK)
/*! @} */

/*! @name LAD - Voltage ladder register */
/*! @{ */

#define ACOMP_LAD_LADEN_MASK                     (0x1U)
#define ACOMP_LAD_LADEN_SHIFT                    (0U)
/*! LADEN - Voltage ladder enable */
#define ACOMP_LAD_LADEN(x)                       (((uint32_t)(((uint32_t)(x)) << ACOMP_LAD_LADEN_SHIFT)) & ACOMP_LAD_LADEN_MASK)

#define ACOMP_LAD_LADSEL_MASK                    (0x3EU)
#define ACOMP_LAD_LADSEL_SHIFT                   (1U)
/*! LADSEL - Voltage ladder value. The reference voltage Vref depends on the LADREF bit below. 00000
 *    = VSS 00001 = 1 x Vref/31 00010 = 2 x Vref/31 ... 11111 = Vref
 */
#define ACOMP_LAD_LADSEL(x)                      (((uint32_t)(((uint32_t)(x)) << ACOMP_LAD_LADSEL_SHIFT)) & ACOMP_LAD_LADSEL_MASK)

#define ACOMP_LAD_LADREF_MASK                    (0x40U)
#define ACOMP_LAD_LADREF_SHIFT                   (6U)
/*! LADREF - Selects the reference voltage Vref for the voltage ladder.
 *  0b0..Supply pin VDD
 *  0b1..VDDCMP pin
 */
#define ACOMP_LAD_LADREF(x)                      (((uint32_t)(((uint32_t)(x)) << ACOMP_LAD_LADREF_SHIFT)) & ACOMP_LAD_LADREF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ACOMP_Register_Masks */


/*!
 * @}
 */ /* end of group ACOMP_Peripheral_Access_Layer */


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


#endif  /* PERI_ACOMP_H_ */

