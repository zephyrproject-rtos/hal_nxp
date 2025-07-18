/*
** ###################################################################
**     Processors:          MCXC141VFM
**                          MCXC141VLH
**                          MCXC142VFM
**                          MCXC242VFM
**                          MCXC242VLH
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PORT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2014-05-12)
**         Initial version.
**     - rev. 1.1 (2014-07-10)
**         UART0 - UART0 module renamed to UART2.
**     - rev. 1.2 (2014-08-12)
**         CRC - CRC register renamed to DATA.
**     - rev. 1.3 (2014-09-02)
**         USB - USB0_CTL0 was renamed to USB0_OTGCTL register.
**         USB - USB0_CTL1 was renamed to USB0_CTL register.
**         USB - Two new bitfields (STOP_ACK_DLY_EN, AHB_DLY_EN) was added to the USB0_KEEP_ALIVE_CTRL register.
**     - rev. 1.4 (2014-09-22)
**         FLEXIO - Offsets of the SHIFTBUFBIS registers were interchanged with offsets of the SHIFTBUFBBS registers.
**         SIM - Changed bitfield value MCGIRCLK to LIRC_CLK of bitfield CLKOUTSEL in SOPT2 register.
**         SIM - Removed bitfield DIEID in SDID register.
**         UART2 - Removed ED register.
**         UART2 - Removed MODEM register.
**         UART2 - Removed IR register.
**         UART2 - Removed PFIFO register.
**         UART2 - Removed CFIFO register.
**         UART2 - Removed SFIFO register.
**         UART2 - Removed TWFIFO register.
**         UART2 - Removed TCFIFO register.
**         UART2 - Removed RWFIFO register.
**         UART2 - Removed RCFIFO register.
**         USB - Removed bitfield REG_EN in CLK_RECOVER_IRC_EN register.
**         USB - Renamed USBEN bitfield of USB0_CTL was renamed to USBENSOFEN.
**     - rev. 1.5 (2016-02-02)
**         FGPIO - Add FGPIO registers.
**     - rev. 1.6 (2016-06-24)
**         USB - OTGCTL register was removed.
**         USB - Bit RESUME was added in CTL register.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PORT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PORT
 *
 * CMSIS Peripheral Access Layer for PORT
 */

#if !defined(PERI_PORT_H_)
#define PERI_PORT_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC141VFM) || defined(CPU_MCXC141VLH))
#include "MCXC141_COMMON.h"
#elif (defined(CPU_MCXC142VFM))
#include "MCXC142_COMMON.h"
#elif (defined(CPU_MCXC242VFM) || defined(CPU_MCXC242VLH))
#include "MCXC242_COMMON.h"
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
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */

/** PORT - Size of Registers Arrays */
#define PORT_PCR_COUNT                            32u

/** PORT - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCR[PORT_PCR_COUNT];               /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  __IO uint32_t GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
  __IO uint32_t GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
       uint8_t RESERVED_0[24];
  __IO uint32_t ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
} PORT_Type;

/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/*! @name PCR - Pin Control Register n */
/*! @{ */

#define PORT_PCR_PS_MASK                         (0x1U)
#define PORT_PCR_PS_SHIFT                        (0U)
/*! PS - Pull Select
 *  0b0..Internal pulldown resistor is enabled on the corresponding pin, if the corresponding PE field is set.
 *  0b1..Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set.
 */
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PS_SHIFT)) & PORT_PCR_PS_MASK)

#define PORT_PCR_PE_MASK                         (0x2U)
#define PORT_PCR_PE_SHIFT                        (1U)
/*! PE - Pull Enable
 *  0b0..Internal pullup or pulldown resistor is not enabled on the corresponding pin.
 *  0b1..Internal pullup or pulldown resistor is enabled on the corresponding pin, if the pin is configured as a digital input.
 */
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PE_SHIFT)) & PORT_PCR_PE_MASK)

#define PORT_PCR_SRE_MASK                        (0x4U)
#define PORT_PCR_SRE_SHIFT                       (2U)
/*! SRE - Slew Rate Enable
 *  0b0..Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output.
 *  0b1..Slow slew rate is configured on the corresponding pin, if the pin is configured as a digital output.
 */
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_SRE_SHIFT)) & PORT_PCR_SRE_MASK)

#define PORT_PCR_PFE_MASK                        (0x10U)
#define PORT_PCR_PFE_SHIFT                       (4U)
/*! PFE - Passive Filter Enable
 *  0b0..Passive input filter is disabled on the corresponding pin.
 *  0b1..Passive input filter is enabled on the corresponding pin, if the pin is configured as a digital input.
 *       Refer to the device data sheet for filter characteristics.
 */
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PFE_SHIFT)) & PORT_PCR_PFE_MASK)

#define PORT_PCR_DSE_MASK                        (0x40U)
#define PORT_PCR_DSE_SHIFT                       (6U)
/*! DSE - Drive Strength Enable
 *  0b0..Low drive strength is configured on the corresponding pin, if pin is configured as a digital output.
 *  0b1..High drive strength is configured on the corresponding pin, if pin is configured as a digital output.
 */
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_DSE_SHIFT)) & PORT_PCR_DSE_MASK)

#define PORT_PCR_MUX_MASK                        (0x700U)
#define PORT_PCR_MUX_SHIFT                       (8U)
/*! MUX - Pin Mux Control
 *  0b000..Pin disabled (analog).
 *  0b001..Alternative 1 (GPIO).
 *  0b010..Alternative 2 (chip-specific).
 *  0b011..Alternative 3 (chip-specific).
 *  0b100..Alternative 4 (chip-specific).
 *  0b101..Alternative 5 (chip-specific).
 *  0b110..Alternative 6 (chip-specific).
 *  0b111..Alternative 7 (chip-specific).
 */
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_MUX_SHIFT)) & PORT_PCR_MUX_MASK)

#define PORT_PCR_IRQC_MASK                       (0xF0000U)
#define PORT_PCR_IRQC_SHIFT                      (16U)
/*! IRQC - Interrupt Configuration
 *  0b0000..Flag is disabled.
 *  0b0001..Flag and DMA request on rising edge.
 *  0b0010..Flag and DMA request on falling edge.
 *  0b0011..Flag and DMA request on either edge.
 *  0b0100..Reserved.
 *  0b0101..Reserved.
 *  0b0110..Reserved.
 *  0b0111..Reserved.
 *  0b1000..Flag and Interrupt when logic 0.
 *  0b1001..Flag and Interrupt on rising-edge.
 *  0b1010..Flag and Interrupt on falling-edge.
 *  0b1011..Flag and Interrupt on either edge.
 *  0b1100..Flag and Interrupt when logic 1.
 *  0b1101..Reserved.
 *  0b1110..Reserved.
 *  0b1111..Reserved.
 */
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_PCR_IRQC_SHIFT)) & PORT_PCR_IRQC_MASK)

#define PORT_PCR_ISF_MASK                        (0x1000000U)
#define PORT_PCR_ISF_SHIFT                       (24U)
/*! ISF - Interrupt Status Flag
 *  0b0..Configured interrupt is not detected.
 *  0b1..Configured interrupt is detected. If the pin is configured to generate a DMA request, then the
 *       corresponding flag will be cleared automatically at the completion of the requested DMA transfer. Otherwise, the
 *       flag remains set until a logic 1 is written to the flag. If the pin is configured for a level sensitive
 *       interrupt and the pin remains asserted, then the flag is set again immediately after it is cleared.
 */
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_ISF_SHIFT)) & PORT_PCR_ISF_MASK)
/*! @} */

/*! @name GPCLR - Global Pin Control Low Register */
/*! @{ */

#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCLR_GPWD_SHIFT                    (0U)
/*! GPWD - Global Pin Write Data */
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWD_SHIFT)) & PORT_GPCLR_GPWD_MASK)

#define PORT_GPCLR_GPWE_MASK                     (0xFFFF0000U)
#define PORT_GPCLR_GPWE_SHIFT                    (16U)
/*! GPWE - Global Pin Write Enable
 *  0b0000000000000000..Corresponding Pin Control Register is not updated with the value in GPWD.
 *  0b0000000000000001..Corresponding Pin Control Register is updated with the value in GPWD.
 */
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE_SHIFT)) & PORT_GPCLR_GPWE_MASK)
/*! @} */

/*! @name GPCHR - Global Pin Control High Register */
/*! @{ */

#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCHR_GPWD_SHIFT                    (0U)
/*! GPWD - Global Pin Write Data */
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWD_SHIFT)) & PORT_GPCHR_GPWD_MASK)

#define PORT_GPCHR_GPWE_MASK                     (0xFFFF0000U)
#define PORT_GPCHR_GPWE_SHIFT                    (16U)
/*! GPWE - Global Pin Write Enable
 *  0b0000000000000000..Corresponding Pin Control Register is not updated with the value in GPWD.
 *  0b0000000000000001..Corresponding Pin Control Register is updated with the value in GPWD.
 */
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE_SHIFT)) & PORT_GPCHR_GPWE_MASK)
/*! @} */

/*! @name ISFR - Interrupt Status Flag Register */
/*! @{ */

#define PORT_ISFR_ISF_MASK                       (0xFFFFFFFFU)
#define PORT_ISFR_ISF_SHIFT                      (0U)
/*! ISF - Interrupt Status Flag
 *  0b00000000000000000000000000000000..Configured interrupt is not detected.
 *  0b00000000000000000000000000000001..Configured interrupt is detected. If the pin is configured to generate a
 *                                      DMA request, then the corresponding flag will be cleared automatically at
 *                                      the completion of the requested DMA transfer. Otherwise, the flag remains set
 *                                      until a logic 1 is written to the flag. If the pin is configured for a
 *                                      level sensitive interrupt and the pin remains asserted, then the flag is set
 *                                      again immediately after it is cleared.
 */
#define PORT_ISFR_ISF(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_ISFR_ISF_SHIFT)) & PORT_ISFR_ISF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */


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


#endif  /* PERI_PORT_H_ */

