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
**         CMSIS Peripheral Access Layer for SIM
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
 * @file PERI_SIM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SIM
 *
 * CMSIS Peripheral Access Layer for SIM
 */

#if !defined(PERI_SIM_H_)
#define PERI_SIM_H_                              /**< Symbol preventing repeated inclusion */

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
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
  __I  uint32_t SRSID;                             /**< System Reset Status and ID Register, offset: 0x0 */
  __IO uint32_t SOPT;                              /**< System Options Register, offset: 0x4 */
  __IO uint32_t PINSEL;                            /**< Pin Selection Register, offset: 0x8 */
  __IO uint32_t SCGC;                              /**< System Clock Gating Control Register, offset: 0xC */
  __I  uint32_t UUIDL;                             /**< Universally Unique Identifier Low Register, offset: 0x10 */
  __I  uint32_t UUIDH;                             /**< Universally Unique Identifier High Register, offset: 0x14 */
  __IO uint32_t BUSDIV;                            /**< BUS Clock Divider Register, offset: 0x18 */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/*! @name SRSID - System Reset Status and ID Register */
/*! @{ */

#define SIM_SRSID_LVD_MASK                       (0x2U)
#define SIM_SRSID_LVD_SHIFT                      (1U)
/*! LVD - Low Voltage Detect
 *  0b0..Reset is not caused by LVD trip or POR.
 *  0b1..Reset is caused by LVD trip or POR.
 */
#define SIM_SRSID_LVD(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_LVD_SHIFT)) & SIM_SRSID_LVD_MASK)

#define SIM_SRSID_LOC_MASK                       (0x4U)
#define SIM_SRSID_LOC_SHIFT                      (2U)
/*! LOC - Internal Clock Source Module Reset
 *  0b0..Reset is not caused by the ICS module.
 *  0b1..Reset is caused by the ICS module.
 */
#define SIM_SRSID_LOC(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_LOC_SHIFT)) & SIM_SRSID_LOC_MASK)

#define SIM_SRSID_WDOG_MASK                      (0x20U)
#define SIM_SRSID_WDOG_SHIFT                     (5U)
/*! WDOG - Watchdog (WDOG)
 *  0b0..Reset is not caused by WDOG timeout.
 *  0b1..Reset is caused by WDOG timeout.
 */
#define SIM_SRSID_WDOG(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_WDOG_SHIFT)) & SIM_SRSID_WDOG_MASK)

#define SIM_SRSID_PIN_MASK                       (0x40U)
#define SIM_SRSID_PIN_SHIFT                      (6U)
/*! PIN - External Reset Pin
 *  0b0..Reset is not caused by external reset pin.
 *  0b1..Reset came from external reset pin.
 */
#define SIM_SRSID_PIN(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_PIN_SHIFT)) & SIM_SRSID_PIN_MASK)

#define SIM_SRSID_POR_MASK                       (0x80U)
#define SIM_SRSID_POR_SHIFT                      (7U)
/*! POR - Power-On Reset
 *  0b0..Reset not caused by POR.
 *  0b1..POR caused reset.
 */
#define SIM_SRSID_POR(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_POR_SHIFT)) & SIM_SRSID_POR_MASK)

#define SIM_SRSID_LOCKUP_MASK                    (0x200U)
#define SIM_SRSID_LOCKUP_SHIFT                   (9U)
/*! LOCKUP - Core Lockup
 *  0b0..Reset is not caused by core LOCKUP event.
 *  0b1..Reset is caused by core LOCKUP event.
 */
#define SIM_SRSID_LOCKUP(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_LOCKUP_SHIFT)) & SIM_SRSID_LOCKUP_MASK)

#define SIM_SRSID_SW_MASK                        (0x400U)
#define SIM_SRSID_SW_SHIFT                       (10U)
/*! SW - Software
 *  0b0..Reset is not caused by software setting of SYSRESETREQ bit.
 *  0b1..Reset caused by software setting of SYSRESETREQ bit
 */
#define SIM_SRSID_SW(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_SW_SHIFT)) & SIM_SRSID_SW_MASK)

#define SIM_SRSID_MDMAP_MASK                     (0x800U)
#define SIM_SRSID_MDMAP_SHIFT                    (11U)
/*! MDMAP - MDM-AP System Reset Request
 *  0b0..Reset is not caused by host debugger system setting of the System Reset Request bit.
 *  0b1..Reset is caused by host debugger system setting of the System Reset Request bit.
 */
#define SIM_SRSID_MDMAP(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_MDMAP_SHIFT)) & SIM_SRSID_MDMAP_MASK)

#define SIM_SRSID_SACKERR_MASK                   (0x2000U)
#define SIM_SRSID_SACKERR_SHIFT                  (13U)
/*! SACKERR - Stop Mode Acknowledge Error Reset
 *  0b0..Reset is not caused by peripheral failure to acknowledge attempt to enter Stop mode.
 *  0b1..Reset is caused by peripheral failure to acknowledge attempt to enter Stop mode.
 */
#define SIM_SRSID_SACKERR(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_SACKERR_SHIFT)) & SIM_SRSID_SACKERR_MASK)

#define SIM_SRSID_PINID_MASK                     (0xF0000U)
#define SIM_SRSID_PINID_SHIFT                    (16U)
/*! PINID - Device Pin ID
 *  0b0000..8-pin
 *  0b0001..16-pin
 *  0b0010..20-pin
 *  0b0011..24-pin
 *  0b0100..32-pin
 *  0b0101..44-pin
 *  0b0110..48-pin
 *  0b0111..64-pin
 *  0b1000..80-pin
 *  0b1010..100-pin
 */
#define SIM_SRSID_PINID(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_PINID_SHIFT)) & SIM_SRSID_PINID_MASK)

#define SIM_SRSID_RevID_MASK                     (0xF00000U)
#define SIM_SRSID_RevID_SHIFT                    (20U)
/*! RevID - Device Revision Number */
#define SIM_SRSID_RevID(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_RevID_SHIFT)) & SIM_SRSID_RevID_MASK)

#define SIM_SRSID_SUBFAMID_MASK                  (0xF000000U)
#define SIM_SRSID_SUBFAMID_SHIFT                 (24U)
/*! SUBFAMID - Kinetis sub-family ID
 *  0b0010..KEx2 sub-family
 */
#define SIM_SRSID_SUBFAMID(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_SUBFAMID_SHIFT)) & SIM_SRSID_SUBFAMID_MASK)

#define SIM_SRSID_FAMID_MASK                     (0xF0000000U)
#define SIM_SRSID_FAMID_SHIFT                    (28U)
/*! FAMID - Kinetis family ID
 *  0b0000..KE0x family.
 */
#define SIM_SRSID_FAMID(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SRSID_FAMID_SHIFT)) & SIM_SRSID_FAMID_MASK)
/*! @} */

/*! @name SOPT - System Options Register */
/*! @{ */

#define SIM_SOPT_NMIE_MASK                       (0x2U)
#define SIM_SOPT_NMIE_SHIFT                      (1U)
/*! NMIE - NMI Pin Enable
 *  0b0..PTB4/FTM2_CH4/SPI0_MISO/NMI/ACMP1_IN2 pin functions as PTB4, FTM2_CH4, SPI0_MISO, or ACMP1_IN2.
 *  0b1..PTB4/FTM2_CH4/SPI0_MISO/NMI/ACMP1_IN2 pin functions as NMI.
 */
#define SIM_SOPT_NMIE(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_NMIE_SHIFT)) & SIM_SOPT_NMIE_MASK)

#define SIM_SOPT_RSTPE_MASK                      (0x4U)
#define SIM_SOPT_RSTPE_SHIFT                     (2U)
/*! RSTPE - RESET Pin Enable
 *  0b0..PTA5/IRQ/FTM0_CLK/RESET pin functions as PTA5, IRQ, or FTM0_CLK.
 *  0b1..PTA5/IRQ/FTM0_CLK/RESET pin functions as RESET.
 */
#define SIM_SOPT_RSTPE(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_RSTPE_SHIFT)) & SIM_SOPT_RSTPE_MASK)

#define SIM_SOPT_SWDE_MASK                       (0x8U)
#define SIM_SOPT_SWDE_SHIFT                      (3U)
/*! SWDE - Single Wire Debug Port Pin Enable
 *  0b0..PTA4/ACMP0_OUT/SWD_DIO as PTA4 or ACMP0_OUT function, PTC4/RTCO/FTM1_CH0/ACMP0_IN2/SWD_CLK as PTC4, RTCO, FTM1_CH0, or ACMP0_IN2 function.
 *  0b1..PTA4/ACMP0_OUT/SWD_DIO as SWD_DIO function, PTC4/RTCO/FTM1CH0/ACMP0_IN2/SWD_CLK as SWD_CLK function.
 */
#define SIM_SOPT_SWDE(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_SWDE_SHIFT)) & SIM_SOPT_SWDE_MASK)

#define SIM_SOPT_ADHWT_MASK                      (0x300U)
#define SIM_SOPT_ADHWT_SHIFT                     (8U)
/*! ADHWT - ADC Hardware Trigger Source
 *  0b00..RTC overflow as the ADC hardware trigger
 *  0b01..PIT overflow as the ADC hardware trigger
 *  0b10..FTM2 init trigger with 8-bit programmable delay
 *  0b11..FTM2 match trigger with 8-bit programmable delay
 */
#define SIM_SOPT_ADHWT(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_ADHWT_SHIFT)) & SIM_SOPT_ADHWT_MASK)

#define SIM_SOPT_RTCC_MASK                       (0x400U)
#define SIM_SOPT_RTCC_SHIFT                      (10U)
/*! RTCC - Real-Time Counter Capture
 *  0b0..RTC overflow is not connected to FTM1 input channel 1.
 *  0b1..RTC overflow is connected to FTM1 input channel 1.
 */
#define SIM_SOPT_RTCC(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_RTCC_SHIFT)) & SIM_SOPT_RTCC_MASK)

#define SIM_SOPT_ACIC_MASK                       (0x800U)
#define SIM_SOPT_ACIC_SHIFT                      (11U)
/*! ACIC - Analog Comparator to Input Capture Enable
 *  0b0..ACMP0 output is not connected to FTM1 input channel 0.
 *  0b1..ACMP0 output is connected to FTM1 input channel 0.
 */
#define SIM_SOPT_ACIC(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_ACIC_SHIFT)) & SIM_SOPT_ACIC_MASK)

#define SIM_SOPT_RXDCE_MASK                      (0x1000U)
#define SIM_SOPT_RXDCE_SHIFT                     (12U)
/*! RXDCE - UART0_RX Capture Select
 *  0b0..UART0_RX input signal is connected to the UART0 module only.
 *  0b1..UART0_RX input signal is connected to the UART0 module and FTM0 channel 1.
 */
#define SIM_SOPT_RXDCE(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_RXDCE_SHIFT)) & SIM_SOPT_RXDCE_MASK)

#define SIM_SOPT_RXDFE_MASK                      (0x2000U)
#define SIM_SOPT_RXDFE_SHIFT                     (13U)
/*! RXDFE - UART0_RX Filter Select
 *  0b0..UART0_RX input signal is connected to UART0 module directly.
 *  0b1..UART0_RX input signal is filtered by ACMP, then injected to UART0.
 */
#define SIM_SOPT_RXDFE(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_RXDFE_SHIFT)) & SIM_SOPT_RXDFE_MASK)

#define SIM_SOPT_FTMSYNC_MASK                    (0x4000U)
#define SIM_SOPT_FTMSYNC_SHIFT                   (14U)
/*! FTMSYNC - FTM2 Synchronization Select
 *  0b0..No synchronization triggered.
 *  0b1..Generates a PWM synchronization trigger to the FTM2 modules.
 */
#define SIM_SOPT_FTMSYNC(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_FTMSYNC_SHIFT)) & SIM_SOPT_FTMSYNC_MASK)

#define SIM_SOPT_TXDME_MASK                      (0x8000U)
#define SIM_SOPT_TXDME_SHIFT                     (15U)
/*! TXDME - UART0_TX Modulation Select
 *  0b0..UART0_TX output is connected to pinout directly.
 *  0b1..UART0_TX output is modulated by FTM0 channel 0 before mapped to pinout.
 */
#define SIM_SOPT_TXDME(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_TXDME_SHIFT)) & SIM_SOPT_TXDME_MASK)

#define SIM_SOPT_BUSREF_MASK                     (0x70000U)
#define SIM_SOPT_BUSREF_SHIFT                    (16U)
/*! BUSREF - BUS Clock Output select
 *  0b000..Bus
 *  0b001..Bus divided by 2
 *  0b010..Bus divided by 4
 *  0b011..Bus divided by 8
 *  0b100..Bus divided by 16
 *  0b101..Bus divided by 32
 *  0b110..Bus divided by 64
 *  0b111..Bus divided by 128
 */
#define SIM_SOPT_BUSREF(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_BUSREF_SHIFT)) & SIM_SOPT_BUSREF_MASK)

#define SIM_SOPT_CLKOE_MASK                      (0x80000U)
#define SIM_SOPT_CLKOE_SHIFT                     (19U)
/*! CLKOE - Bus Clock Output Enable
 *  0b0..Bus clock output is disabled on PTH2.
 *  0b1..Bus clock output is enabled on PTH2.
 */
#define SIM_SOPT_CLKOE(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_CLKOE_SHIFT)) & SIM_SOPT_CLKOE_MASK)

#define SIM_SOPT_DLYACT_MASK                     (0x800000U)
#define SIM_SOPT_DLYACT_SHIFT                    (23U)
/*! DLYACT - FTM2 Trigger Delay Active
 *  0b0..The delay is inactive.
 *  0b1..The delay is active.
 */
#define SIM_SOPT_DLYACT(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_DLYACT_SHIFT)) & SIM_SOPT_DLYACT_MASK)

#define SIM_SOPT_DELAY_MASK                      (0xFF000000U)
#define SIM_SOPT_DELAY_SHIFT                     (24U)
/*! DELAY - FTM2 Trigger Delay */
#define SIM_SOPT_DELAY(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SOPT_DELAY_SHIFT)) & SIM_SOPT_DELAY_MASK)
/*! @} */

/*! @name PINSEL - Pin Selection Register */
/*! @{ */

#define SIM_PINSEL_RTCPS_MASK                    (0x10U)
#define SIM_PINSEL_RTCPS_SHIFT                   (4U)
/*! RTCPS - RTCO Pin Select
 *  0b0..RTCO is mapped on PTC4.
 *  0b1..RTCO is mapped on PTC5.
 */
#define SIM_PINSEL_RTCPS(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_RTCPS_SHIFT)) & SIM_PINSEL_RTCPS_MASK)

#define SIM_PINSEL_I2C0PS_MASK                   (0x20U)
#define SIM_PINSEL_I2C0PS_SHIFT                  (5U)
/*! I2C0PS - I2C0 Port Pin Select
 *  0b0..I2C0_SCL and I2C0_SDA are mapped on PTA3 and PTA2, respectively.
 *  0b1..I2C0_SCL and I2C0_SDA are mapped on PTB7 and PTB6, respectively.
 */
#define SIM_PINSEL_I2C0PS(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_I2C0PS_SHIFT)) & SIM_PINSEL_I2C0PS_MASK)

#define SIM_PINSEL_SPI0PS_MASK                   (0x40U)
#define SIM_PINSEL_SPI0PS_SHIFT                  (6U)
/*! SPI0PS - SPI0 Pin Select
 *  0b0..SPI0_SCK, SPI0_MOSI, SPI0_MISO, and SPI0_PCS0 are mapped on PTB2, PTB3, PTB4, and PTB5.
 *  0b1..SPI0_SCK, SPI0_MOSI, SPI0_MISO, and SPI0_PCS0 are mapped on PTE0, PTE1, PTE2, and PTE3.
 */
#define SIM_PINSEL_SPI0PS(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_SPI0PS_SHIFT)) & SIM_PINSEL_SPI0PS_MASK)

#define SIM_PINSEL_UART0PS_MASK                  (0x80U)
#define SIM_PINSEL_UART0PS_SHIFT                 (7U)
/*! UART0PS - UART0 Pin Select
 *  0b0..UART0_RX and UART0_TX are mapped on PTB0 and PTB1.
 *  0b1..UART0_RX and UART0_TX are mapped on PTA2 and PTA3.
 */
#define SIM_PINSEL_UART0PS(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_UART0PS_SHIFT)) & SIM_PINSEL_UART0PS_MASK)

#define SIM_PINSEL_FTM0PS0_MASK                  (0x100U)
#define SIM_PINSEL_FTM0PS0_SHIFT                 (8U)
/*! FTM0PS0 - FTM0_CH0 Port Pin Select
 *  0b0..FTM0_CH0 channels are mapped on PTA0.
 *  0b1..FTM0_CH0 channels are mapped on PTB2.
 */
#define SIM_PINSEL_FTM0PS0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_FTM0PS0_SHIFT)) & SIM_PINSEL_FTM0PS0_MASK)

#define SIM_PINSEL_FTM0PS1_MASK                  (0x200U)
#define SIM_PINSEL_FTM0PS1_SHIFT                 (9U)
/*! FTM0PS1 - FTM0_CH1 Port Pin Select
 *  0b0..FTM0_CH1 channels are mapped on PTA1.
 *  0b1..FTM0_CH1 channels are mapped on PTB3.
 */
#define SIM_PINSEL_FTM0PS1(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_FTM0PS1_SHIFT)) & SIM_PINSEL_FTM0PS1_MASK)

#define SIM_PINSEL_FTM1PS0_MASK                  (0x400U)
#define SIM_PINSEL_FTM1PS0_SHIFT                 (10U)
/*! FTM1PS0 - FTM1_CH0 Port Pin Select
 *  0b0..FTM1_CH0 channels are mapped on PTC4.
 *  0b1..FTM1_CH0 channels are mapped on PTH2.
 */
#define SIM_PINSEL_FTM1PS0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_FTM1PS0_SHIFT)) & SIM_PINSEL_FTM1PS0_MASK)

#define SIM_PINSEL_FTM1PS1_MASK                  (0x800U)
#define SIM_PINSEL_FTM1PS1_SHIFT                 (11U)
/*! FTM1PS1 - FTM1_CH1 Port Pin Select
 *  0b0..FTM1_CH1 channels are mapped on PTC5.
 *  0b1..FTM1_CH1 channels are mapped on PTE7.
 */
#define SIM_PINSEL_FTM1PS1(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_FTM1PS1_SHIFT)) & SIM_PINSEL_FTM1PS1_MASK)

#define SIM_PINSEL_FTM2PS0_MASK                  (0x1000U)
#define SIM_PINSEL_FTM2PS0_SHIFT                 (12U)
/*! FTM2PS0 - FTM2_CH0 Port Pin Select
 *  0b0..FTM2_CH0 channels are mapped on PTC0.
 *  0b1..FTM2_CH0 channels are mapped on PTH0.
 */
#define SIM_PINSEL_FTM2PS0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_FTM2PS0_SHIFT)) & SIM_PINSEL_FTM2PS0_MASK)

#define SIM_PINSEL_FTM2PS1_MASK                  (0x2000U)
#define SIM_PINSEL_FTM2PS1_SHIFT                 (13U)
/*! FTM2PS1 - FTM2_CH1 Port Pin Select
 *  0b0..FTM2_CH1 channels are mapped on PTC1.
 *  0b1..FTM2_CH1 channels are mapped on PTH1.
 */
#define SIM_PINSEL_FTM2PS1(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_FTM2PS1_SHIFT)) & SIM_PINSEL_FTM2PS1_MASK)

#define SIM_PINSEL_FTM2PS2_MASK                  (0x4000U)
#define SIM_PINSEL_FTM2PS2_SHIFT                 (14U)
/*! FTM2PS2 - FTM2_CH2 Port Pin Select
 *  0b0..FTM2_CH2 channels are mapped on PTC2.
 *  0b1..FTM2_CH2 channels are mapped on PTD0.
 */
#define SIM_PINSEL_FTM2PS2(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_FTM2PS2_SHIFT)) & SIM_PINSEL_FTM2PS2_MASK)

#define SIM_PINSEL_FTM2PS3_MASK                  (0x8000U)
#define SIM_PINSEL_FTM2PS3_SHIFT                 (15U)
/*! FTM2PS3 - FTM2_CH3 Port Pin Select
 *  0b0..FTM2_CH3 channels are mapped on PTC3.
 *  0b1..FTM2_CH3 channels are mapped on PTD1.
 */
#define SIM_PINSEL_FTM2PS3(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PINSEL_FTM2PS3_SHIFT)) & SIM_PINSEL_FTM2PS3_MASK)
/*! @} */

/*! @name SCGC - System Clock Gating Control Register */
/*! @{ */

#define SIM_SCGC_RTC_MASK                        (0x1U)
#define SIM_SCGC_RTC_SHIFT                       (0U)
/*! RTC - RTC Clock Gate Control
 *  0b0..Bus clock to the RTC module is disabled.
 *  0b1..Bus clock to the RTC module is enabled.
 */
#define SIM_SCGC_RTC(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_RTC_SHIFT)) & SIM_SCGC_RTC_MASK)

#define SIM_SCGC_PIT_MASK                        (0x2U)
#define SIM_SCGC_PIT_SHIFT                       (1U)
/*! PIT - PIT Clock Gate Control
 *  0b0..Bus clock to the PIT module is disabled.
 *  0b1..Bus clock to the PIT module is enabled.
 */
#define SIM_SCGC_PIT(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_PIT_SHIFT)) & SIM_SCGC_PIT_MASK)

#define SIM_SCGC_FTM0_MASK                       (0x20U)
#define SIM_SCGC_FTM0_SHIFT                      (5U)
/*! FTM0 - FTM0 Clock Gate Control
 *  0b0..Bus clock to the FTM0 module is disabled.
 *  0b1..Bus clock to the FTM0 module is enabled.
 */
#define SIM_SCGC_FTM0(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_FTM0_SHIFT)) & SIM_SCGC_FTM0_MASK)

#define SIM_SCGC_FTM1_MASK                       (0x40U)
#define SIM_SCGC_FTM1_SHIFT                      (6U)
/*! FTM1 - FTM1 Clock Gate Control
 *  0b0..Bus clock to the FTM1 module is disabled.
 *  0b1..Bus clock to the FTM1 module is enabled.
 */
#define SIM_SCGC_FTM1(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_FTM1_SHIFT)) & SIM_SCGC_FTM1_MASK)

#define SIM_SCGC_FTM2_MASK                       (0x80U)
#define SIM_SCGC_FTM2_SHIFT                      (7U)
/*! FTM2 - FTM2 Clock Gate Control
 *  0b0..Bus clock to the FTM2 module is disabled.
 *  0b1..Bus clock to the FTM2 module is enabled.
 */
#define SIM_SCGC_FTM2(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_FTM2_SHIFT)) & SIM_SCGC_FTM2_MASK)

#define SIM_SCGC_CRC_MASK                        (0x400U)
#define SIM_SCGC_CRC_SHIFT                       (10U)
/*! CRC - CRC Clock Gate Control
 *  0b0..Bus clock to the CRC module is disabled.
 *  0b1..Bus clock to the CRC module is enabled.
 */
#define SIM_SCGC_CRC(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_CRC_SHIFT)) & SIM_SCGC_CRC_MASK)

#define SIM_SCGC_FLASH_MASK                      (0x1000U)
#define SIM_SCGC_FLASH_SHIFT                     (12U)
/*! FLASH - Flash Clock Gate Control
 *  0b0..Bus clock to the flash module is disabled.
 *  0b1..Bus clock to the flash module is enabled.
 */
#define SIM_SCGC_FLASH(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_FLASH_SHIFT)) & SIM_SCGC_FLASH_MASK)

#define SIM_SCGC_SWD_MASK                        (0x2000U)
#define SIM_SCGC_SWD_SHIFT                       (13U)
/*! SWD - SWD (single wire debugger) Clock Gate Control
 *  0b0..Bus clock to the SWD module is disabled.
 *  0b1..Bus clock to the SWD module is enabled.
 */
#define SIM_SCGC_SWD(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_SWD_SHIFT)) & SIM_SCGC_SWD_MASK)

#define SIM_SCGC_I2C_MASK                        (0x20000U)
#define SIM_SCGC_I2C_SHIFT                       (17U)
/*! I2C - I2C Clock Gate Control
 *  0b0..Bus clock to the IIC module is disabled.
 *  0b1..Bus clock to the IIC module is enabled.
 */
#define SIM_SCGC_I2C(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_I2C_SHIFT)) & SIM_SCGC_I2C_MASK)

#define SIM_SCGC_SPI0_MASK                       (0x40000U)
#define SIM_SCGC_SPI0_SHIFT                      (18U)
/*! SPI0 - SPI0 Clock Gate Control
 *  0b0..Bus clock to the SPI0 module is disabled.
 *  0b1..Bus clock to the SPI0 module is enabled.
 */
#define SIM_SCGC_SPI0(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_SPI0_SHIFT)) & SIM_SCGC_SPI0_MASK)

#define SIM_SCGC_SPI1_MASK                       (0x80000U)
#define SIM_SCGC_SPI1_SHIFT                      (19U)
/*! SPI1 - SPI1 Clock Gate Control
 *  0b0..Bus clock to the SPI1 module is disabled.
 *  0b1..Bus clock to the SPI1 module is enabled.
 */
#define SIM_SCGC_SPI1(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_SPI1_SHIFT)) & SIM_SCGC_SPI1_MASK)

#define SIM_SCGC_UART0_MASK                      (0x100000U)
#define SIM_SCGC_UART0_SHIFT                     (20U)
/*! UART0 - UART0 Clock Gate Control
 *  0b0..Bus clock to the UART0 module is disabled.
 *  0b1..Bus clock to the UART0 module is enabled.
 */
#define SIM_SCGC_UART0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_UART0_SHIFT)) & SIM_SCGC_UART0_MASK)

#define SIM_SCGC_UART1_MASK                      (0x200000U)
#define SIM_SCGC_UART1_SHIFT                     (21U)
/*! UART1 - UART1 Clock Gate Control
 *  0b0..Bus clock to the UART1 module is disabled.
 *  0b1..Bus clock to the UART1 module is enabled.
 */
#define SIM_SCGC_UART1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_UART1_SHIFT)) & SIM_SCGC_UART1_MASK)

#define SIM_SCGC_UART2_MASK                      (0x400000U)
#define SIM_SCGC_UART2_SHIFT                     (22U)
/*! UART2 - UART2 Clock Gate Control
 *  0b0..Bus clock to the UART2 module is disabled.
 *  0b1..Bus clock to the UART2 module is enabled.
 */
#define SIM_SCGC_UART2(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_UART2_SHIFT)) & SIM_SCGC_UART2_MASK)

#define SIM_SCGC_KBI0_MASK                       (0x1000000U)
#define SIM_SCGC_KBI0_SHIFT                      (24U)
/*! KBI0 - KBI0 Clock Gate Control
 *  0b0..Bus clock to the KBI0 module is disabled.
 *  0b1..Bus clock to the KBI0 module is enabled.
 */
#define SIM_SCGC_KBI0(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_KBI0_SHIFT)) & SIM_SCGC_KBI0_MASK)

#define SIM_SCGC_KBI1_MASK                       (0x2000000U)
#define SIM_SCGC_KBI1_SHIFT                      (25U)
/*! KBI1 - KBI1 Clock Gate Control
 *  0b0..Bus clock to the KBI1 module is disabled.
 *  0b1..Bus clock to the KBI1 module is enabled.
 */
#define SIM_SCGC_KBI1(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_KBI1_SHIFT)) & SIM_SCGC_KBI1_MASK)

#define SIM_SCGC_IRQ_MASK                        (0x8000000U)
#define SIM_SCGC_IRQ_SHIFT                       (27U)
/*! IRQ - IRQ Clock Gate Control
 *  0b0..Bus clock to the IRQ module is disabled.
 *  0b1..Bus clock to the IRQ module is enabled.
 */
#define SIM_SCGC_IRQ(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_IRQ_SHIFT)) & SIM_SCGC_IRQ_MASK)

#define SIM_SCGC_ADC_MASK                        (0x20000000U)
#define SIM_SCGC_ADC_SHIFT                       (29U)
/*! ADC - ADC Clock Gate Control
 *  0b0..Bus clock to the ADC module is disabled.
 *  0b1..Bus clock to the ADC module is enabled.
 */
#define SIM_SCGC_ADC(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_ADC_SHIFT)) & SIM_SCGC_ADC_MASK)

#define SIM_SCGC_ACMP0_MASK                      (0x40000000U)
#define SIM_SCGC_ACMP0_SHIFT                     (30U)
/*! ACMP0 - ACMP0 Clock Gate Control
 *  0b0..Bus clock to the ACMP0 module is disabled.
 *  0b1..Bus clock to the ACMP0 module is enabled.
 */
#define SIM_SCGC_ACMP0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_ACMP0_SHIFT)) & SIM_SCGC_ACMP0_MASK)

#define SIM_SCGC_ACMP1_MASK                      (0x80000000U)
#define SIM_SCGC_ACMP1_SHIFT                     (31U)
/*! ACMP1 - ACMP1 Clock Gate Control
 *  0b0..Bus clock to the ACMP1 module is disabled.
 *  0b1..Bus clock to the ACMP1 module is enabled.
 */
#define SIM_SCGC_ACMP1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC_ACMP1_SHIFT)) & SIM_SCGC_ACMP1_MASK)
/*! @} */

/*! @name UUIDL - Universally Unique Identifier Low Register */
/*! @{ */

#define SIM_UUIDL_ID_MASK                        (0xFFFFFFFFU)
#define SIM_UUIDL_ID_SHIFT                       (0U)
/*! ID - Universally Unique Identifier */
#define SIM_UUIDL_ID(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_UUIDL_ID_SHIFT)) & SIM_UUIDL_ID_MASK)
/*! @} */

/*! @name UUIDH - Universally Unique Identifier High Register */
/*! @{ */

#define SIM_UUIDH_ID_MASK                        (0xFFFFFFFFU)
#define SIM_UUIDH_ID_SHIFT                       (0U)
/*! ID - Universally Unique Identifier */
#define SIM_UUIDH_ID(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_UUIDH_ID_SHIFT)) & SIM_UUIDH_ID_MASK)
/*! @} */

/*! @name BUSDIV - BUS Clock Divider Register */
/*! @{ */

#define SIM_BUSDIV_BUSDIV_MASK                   (0x1U)
#define SIM_BUSDIV_BUSDIV_SHIFT                  (0U)
/*! BUSDIV - BUS Clock Divider
 *  0b0..Bus clock is same as ICSOUTCLK.
 *  0b1..Bus clock is ICSOUTCLK divided by 2.
 */
#define SIM_BUSDIV_BUSDIV(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_BUSDIV_BUSDIV_SHIFT)) & SIM_BUSDIV_BUSDIV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


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


#endif  /* PERI_SIM_H_ */

