/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
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
**     - rev. 1.0 (2014-10-17)
**         Initial version.
**     - rev. 1.1 (2015-01-27)
**         Update according to reference manual rev. 1, RC.
**     - rev. 1.2 (2015-03-06)
**         Update according to reference manual rev. 1.
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

#if (defined(CPU_MKM34Z256VLL7) || defined(CPU_MKM34Z256VLQ7))
#include "MKM34Z7_COMMON.h"
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
  __IO uint32_t SOPT1;                             /**< System Options Register 1, offset: 0x0 */
  __IO uint32_t SOPT1_CFG;                         /**< SOPT1 Configuration Register, offset: 0x4 */
       uint8_t RESERVED_0[4092];
  __IO uint32_t CTRL_REG;                          /**< System Control Register, offset: 0x1004 */
       uint8_t RESERVED_1[28];
  __I  uint32_t SDID;                              /**< System Device Identification Register, offset: 0x1024 */
       uint8_t RESERVED_2[12];
  __IO uint32_t SCGC4;                             /**< System Clock Gating Control Register 4, offset: 0x1034 */
  __IO uint32_t SCGC5;                             /**< System Clock Gating Control Register 5, offset: 0x1038 */
  __IO uint32_t SCGC6;                             /**< System Clock Gating Control Register 6, offset: 0x103C */
  __IO uint32_t SCGC7;                             /**< System Clock Gating Control Register 7, offset: 0x1040 */
  __IO uint32_t CLKDIV1;                           /**< System Clock Divider Register 1, offset: 0x1044 */
       uint8_t RESERVED_3[4];
  __IO uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x104C */
  __I  uint32_t FCFG2;                             /**< Flash Configuration Register 2, offset: 0x1050 */
  __I  uint32_t UIDH;                              /**< Unique Identification Register High, offset: 0x1054 */
  __I  uint32_t UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x1058 */
  __I  uint32_t UIDML;                             /**< Unique Identification Register Mid-Low, offset: 0x105C */
  __I  uint32_t UIDL;                              /**< Unique Identification Register Low, offset: 0x1060 */
       uint8_t RESERVED_4[8];
  __IO uint32_t MISC_CTL;                          /**< Miscellaneous Control Register, offset: 0x106C */
       uint8_t RESERVED_5[88];
  __I  uint32_t ADC_COMP0;                         /**< ADC Compensation Register 0, offset: 0x10C8 */
  __I  uint32_t ADC_COMP1;                         /**< ADC Compensation Register 1, offset: 0x10CC */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/*! @name SOPT1 - System Options Register 1 */
/*! @{ */

#define SIM_SOPT1_SRAMSIZE_MASK                  (0xF000U)
#define SIM_SOPT1_SRAMSIZE_SHIFT                 (12U)
/*! SRAMSIZE - Returns the size of the system RAM
 *  0b0110..32 KB System RAM
 */
#define SIM_SOPT1_SRAMSIZE(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_SRAMSIZE_SHIFT)) & SIM_SOPT1_SRAMSIZE_MASK)

#define SIM_SOPT1_OSC32KSEL_MASK                 (0xC0000U)
#define SIM_SOPT1_OSC32KSEL_SHIFT                (18U)
/*! OSC32KSEL - 32K oscillator clock select
 *  0b00..OSC32KCLK (RTC Oscillator output)
 *  0b01..ERCLK32K
 *  0b10..MCGIRCLK
 *  0b11..LPO
 */
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_OSC32KSEL_SHIFT)) & SIM_SOPT1_OSC32KSEL_MASK)
/*! @} */

/*! @name SOPT1_CFG - SOPT1 Configuration Register */
/*! @{ */

#define SIM_SOPT1_CFG_LPTMR0SEL_MASK             (0x3U)
#define SIM_SOPT1_CFG_LPTMR0SEL_SHIFT            (0U)
/*! LPTMR0SEL - LP Timer Channel0 Select
 *  0b00..CMP[0] output
 *  0b01..CMP[1] output
 *  0b10..CMP[2] output
 *  0b11..Reserved
 */
#define SIM_SOPT1_CFG_LPTMR0SEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_CFG_LPTMR0SEL_SHIFT)) & SIM_SOPT1_CFG_LPTMR0SEL_MASK)

#define SIM_SOPT1_CFG_LPTMR1SEL_MASK             (0xCU)
#define SIM_SOPT1_CFG_LPTMR1SEL_SHIFT            (2U)
/*! LPTMR1SEL - LP Timer Channel1 Select
 *  0b00..Pad PTE4
 *  0b01..Pad PTF4
 *  0b10..Pad PTG1
 *  0b11..Reserved
 */
#define SIM_SOPT1_CFG_LPTMR1SEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_CFG_LPTMR1SEL_SHIFT)) & SIM_SOPT1_CFG_LPTMR1SEL_MASK)

#define SIM_SOPT1_CFG_LPTMR2SEL_MASK             (0x30U)
#define SIM_SOPT1_CFG_LPTMR2SEL_SHIFT            (4U)
/*! LPTMR2SEL - LP Timer Channel2 Select
 *  0b00..Pad PTD6
 *  0b01..Pad PTF3
 *  0b10..Pad PTG5
 *  0b11..Reserved
 */
#define SIM_SOPT1_CFG_LPTMR2SEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_CFG_LPTMR2SEL_SHIFT)) & SIM_SOPT1_CFG_LPTMR2SEL_MASK)

#define SIM_SOPT1_CFG_LPTMR3SEL_MASK             (0xC0U)
#define SIM_SOPT1_CFG_LPTMR3SEL_SHIFT            (6U)
/*! LPTMR3SEL - LP Timer Channel3 Select
 *  0b00..Pad PTD5
 *  0b01..Pad PTG0
 *  0b10..Pad PTG6
 *  0b11..Reserved
 */
#define SIM_SOPT1_CFG_LPTMR3SEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_CFG_LPTMR3SEL_SHIFT)) & SIM_SOPT1_CFG_LPTMR3SEL_MASK)

#define SIM_SOPT1_CFG_RAMSBDIS_MASK              (0x100U)
#define SIM_SOPT1_CFG_RAMSBDIS_SHIFT             (8U)
/*! RAMSBDIS
 *  0b0..Source bias of System SRAM enabled during VLPR and VLPW modes.
 *  0b1..Source bias of System SRAM disabled during VLPR and VLPW modes.
 */
#define SIM_SOPT1_CFG_RAMSBDIS(x)                (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_CFG_RAMSBDIS_SHIFT)) & SIM_SOPT1_CFG_RAMSBDIS_MASK)

#define SIM_SOPT1_CFG_RAMBPEN_MASK               (0x200U)
#define SIM_SOPT1_CFG_RAMBPEN_SHIFT              (9U)
/*! RAMBPEN - RAM Bitline Precharge Enable
 *  0b0..Bitline precharge of system SRAM disabled during VLPR and VLPW modes.
 *  0b1..Bitline precharge of system SRAM enabled during VLPR and VLPW modes.
 */
#define SIM_SOPT1_CFG_RAMBPEN(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_CFG_RAMBPEN_SHIFT)) & SIM_SOPT1_CFG_RAMBPEN_MASK)
/*! @} */

/*! @name CTRL_REG - System Control Register */
/*! @{ */

#define SIM_CTRL_REG_NMIDIS_MASK                 (0x1U)
#define SIM_CTRL_REG_NMIDIS_SHIFT                (0U)
/*! NMIDIS - NMI Disable
 *  0b0..NMI enabled
 *  0b1..NMI disabled
 */
#define SIM_CTRL_REG_NMIDIS(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_NMIDIS_SHIFT)) & SIM_CTRL_REG_NMIDIS_MASK)

#define SIM_CTRL_REG_PLLVLPEN_MASK               (0x2U)
#define SIM_CTRL_REG_PLLVLPEN_SHIFT              (1U)
/*! PLLVLPEN - PLL VLP Enable */
#define SIM_CTRL_REG_PLLVLPEN(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_PLLVLPEN_SHIFT)) & SIM_CTRL_REG_PLLVLPEN_MASK)

#define SIM_CTRL_REG_ADCTRGSEL_MASK              (0x18U)
#define SIM_CTRL_REG_ADCTRGSEL_SHIFT             (3U)
/*! ADCTRGSEL - SAR ADC Trigger Clock Select
 *  0b00..Bus ClockDuring Low Power Modes such as stop, the Bus clock is not available for conversion and should
 *        not be selected in case a conversion needs to be performed while in stop.
 *  0b01..ADC asynchronous Clock
 *  0b10..ERCLK32K
 *  0b11..OSCCLK
 */
#define SIM_CTRL_REG_ADCTRGSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_ADCTRGSEL_SHIFT)) & SIM_CTRL_REG_ADCTRGSEL_MASK)

#define SIM_CTRL_REG_CLKOUT_MASK                 (0xE0U)
#define SIM_CTRL_REG_CLKOUT_SHIFT                (5U)
/*! CLKOUT - Clock out Select
 *  0b000..Disabled
 *  0b001..Gated Core Clk
 *  0b010..Bus Clk
 *  0b011..LPO clock from PMC
 *  0b100..IRC clock from MCG
 *  0b101..Muxed 32Khz source (please refer to SOPT1[19:18] for possible options)
 *  0b110..MHz Oscillator external reference clock
 *  0b111..PLL clock output from MCG
 */
#define SIM_CTRL_REG_CLKOUT(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_CLKOUT_SHIFT)) & SIM_CTRL_REG_CLKOUT_MASK)

#define SIM_CTRL_REG_SPI0_INV0_MASK              (0x100U)
#define SIM_CTRL_REG_SPI0_INV0_SHIFT             (8U)
/*! SPI0_INV0
 *  0b0..not inverted
 *  0b1..inverts SS
 */
#define SIM_CTRL_REG_SPI0_INV0(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_SPI0_INV0_SHIFT)) & SIM_CTRL_REG_SPI0_INV0_MASK)

#define SIM_CTRL_REG_SPI0_INV1_MASK              (0x200U)
#define SIM_CTRL_REG_SPI0_INV1_SHIFT             (9U)
/*! SPI0_INV1
 *  0b0..not inverted
 *  0b1..inverts SCK
 */
#define SIM_CTRL_REG_SPI0_INV1(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_SPI0_INV1_SHIFT)) & SIM_CTRL_REG_SPI0_INV1_MASK)

#define SIM_CTRL_REG_SPI0_INV2_MASK              (0x400U)
#define SIM_CTRL_REG_SPI0_INV2_SHIFT             (10U)
/*! SPI0_INV2
 *  0b0..not inverted
 *  0b1..inverts MOSI
 */
#define SIM_CTRL_REG_SPI0_INV2(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_SPI0_INV2_SHIFT)) & SIM_CTRL_REG_SPI0_INV2_MASK)

#define SIM_CTRL_REG_SPI0_INV3_MASK              (0x800U)
#define SIM_CTRL_REG_SPI0_INV3_SHIFT             (11U)
/*! SPI0_INV3
 *  0b0..not inverted
 *  0b1..inverts MISO
 */
#define SIM_CTRL_REG_SPI0_INV3(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_SPI0_INV3_SHIFT)) & SIM_CTRL_REG_SPI0_INV3_MASK)

#define SIM_CTRL_REG_SPI1_INV0_MASK              (0x1000U)
#define SIM_CTRL_REG_SPI1_INV0_SHIFT             (12U)
/*! SPI1_INV0
 *  0b0..not inverted
 *  0b1..inverts SS
 */
#define SIM_CTRL_REG_SPI1_INV0(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_SPI1_INV0_SHIFT)) & SIM_CTRL_REG_SPI1_INV0_MASK)

#define SIM_CTRL_REG_SPI1_INV1_MASK              (0x2000U)
#define SIM_CTRL_REG_SPI1_INV1_SHIFT             (13U)
/*! SPI1_INV1
 *  0b0..not inverted
 *  0b1..inverts SCK
 */
#define SIM_CTRL_REG_SPI1_INV1(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_SPI1_INV1_SHIFT)) & SIM_CTRL_REG_SPI1_INV1_MASK)

#define SIM_CTRL_REG_SPI1_INV2_MASK              (0x4000U)
#define SIM_CTRL_REG_SPI1_INV2_SHIFT             (14U)
/*! SPI1_INV2
 *  0b0..not inverted
 *  0b1..inverts MOSI
 */
#define SIM_CTRL_REG_SPI1_INV2(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_SPI1_INV2_SHIFT)) & SIM_CTRL_REG_SPI1_INV2_MASK)

#define SIM_CTRL_REG_SPI1_INV3_MASK              (0x8000U)
#define SIM_CTRL_REG_SPI1_INV3_SHIFT             (15U)
/*! SPI1_INV3
 *  0b0..not inverted
 *  0b1..inverts MISO
 */
#define SIM_CTRL_REG_SPI1_INV3(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_SPI1_INV3_SHIFT)) & SIM_CTRL_REG_SPI1_INV3_MASK)

#define SIM_CTRL_REG_PLLFLLSEL_MASK              (0x30000U)
#define SIM_CTRL_REG_PLLFLLSEL_SHIFT             (16U)
/*! PLLFLLSEL - PLL/FLL selection
 *  0b00..MCGFLLCLK
 *  0b01..MCGPLLCLK
 *  0b10..BUSCLK
 *  0b11..OSC32KCLK (RTC Oscillator output)
 */
#define SIM_CTRL_REG_PLLFLLSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_PLLFLLSEL_SHIFT)) & SIM_CTRL_REG_PLLFLLSEL_MASK)

#define SIM_CTRL_REG_XBARCLKOUT_MASK             (0xE00000U)
#define SIM_CTRL_REG_XBARCLKOUT_SHIFT            (21U)
/*! XBARCLKOUT - XBAR clock out selection
 *  0b000..Disabled
 *  0b001..Gated Core Clk
 *  0b010..Bus Clk
 *  0b011..LPO clock from PMC
 *  0b100..IRC clock from MCG
 *  0b101..MUXed 32 kHz source (please refer to SOPT1[19:18] for possible options)
 *  0b110..MHz Oscillator external reference clock
 *  0b111..PLL clock output from MCG
 */
#define SIM_CTRL_REG_XBARCLKOUT(x)               (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_XBARCLKOUT_SHIFT)) & SIM_CTRL_REG_XBARCLKOUT_MASK)

#define SIM_CTRL_REG_AFEOUTCLKSEL_MASK           (0x1000000U)
#define SIM_CTRL_REG_AFEOUTCLKSEL_SHIFT          (24U)
/*! AFEOUTCLKSEL - AFE clock output select
 *  0b0..AFE output clock is divided by AFE clock prescaler.
 *  0b1..AFE output clock is NOT divided by AFE clock prescaler.
 */
#define SIM_CTRL_REG_AFEOUTCLKSEL(x)             (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_AFEOUTCLKSEL_SHIFT)) & SIM_CTRL_REG_AFEOUTCLKSEL_MASK)

#define SIM_CTRL_REG_LPUARTSRC_MASK              (0xC000000U)
#define SIM_CTRL_REG_LPUARTSRC_SHIFT             (26U)
/*! LPUARTSRC - LPUART clock Source configuration
 *  0b00..Clock disabled
 *  0b01..MCGPLLCLK/MCGFLLCLK
 *  0b10..OSCERCLK
 *  0b11..MCGIRCLK
 */
#define SIM_CTRL_REG_LPUARTSRC(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_LPUARTSRC_SHIFT)) & SIM_CTRL_REG_LPUARTSRC_MASK)

#define SIM_CTRL_REG_TMRFREEZE_MASK              (0x80000000U)
#define SIM_CTRL_REG_TMRFREEZE_SHIFT             (31U)
/*! TMRFREEZE - QTMR counters Freeze control
 *  0b0..QTMR counters operate normally.
 *  0b1..QTMR counters and OFLAGs are reset. Clearing this bit will resume QTMR operation.
 */
#define SIM_CTRL_REG_TMRFREEZE(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_TMRFREEZE_SHIFT)) & SIM_CTRL_REG_TMRFREEZE_MASK)
/*! @} */

/*! @name SDID - System Device Identification Register */
/*! @{ */

#define SIM_SDID_PINID_MASK                      (0xFU)
#define SIM_SDID_PINID_SHIFT                     (0U)
/*! PINID - Pincount identification
 *  0b0000-0b0010..Reserved
 *  0b0011..Reserved
 *  0b0100..Reserved
 *  0b0101..64-pin
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..100-pin
 *  0b1001..128-pin
 *  0b1010..144-pin
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_PINID_SHIFT)) & SIM_SDID_PINID_MASK)

#define SIM_SDID_DIEID_MASK                      (0xF0U)
#define SIM_SDID_DIEID_SHIFT                     (4U)
/*! DIEID - Die ID
 *  0b0000..First cut
 */
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_DIEID_SHIFT)) & SIM_SDID_DIEID_MASK)

#define SIM_SDID_REVID_MASK                      (0xF00U)
#define SIM_SDID_REVID_SHIFT                     (8U)
/*! REVID - Revision ID
 *  0b0000..First cut
 */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_REVID_SHIFT)) & SIM_SDID_REVID_MASK)

#define SIM_SDID_SRAMSIZE_MASK                   (0xF000U)
#define SIM_SDID_SRAMSIZE_SHIFT                  (12U)
/*! SRAMSIZE - SRAM Size
 *  0b0110..32 KB SRAM
 */
#define SIM_SDID_SRAMSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SRAMSIZE_SHIFT)) & SIM_SDID_SRAMSIZE_MASK)

#define SIM_SDID_ATTR_MASK                       (0xF0000U)
#define SIM_SDID_ATTR_SHIFT                      (16U)
/*! ATTR - Attribute ID
 *  0b0000..M0+ core
 */
#define SIM_SDID_ATTR(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SDID_ATTR_SHIFT)) & SIM_SDID_ATTR_MASK)

#define SIM_SDID_SERIESID_MASK                   (0xF00000U)
#define SIM_SDID_SERIESID_SHIFT                  (20U)
/*! SERIESID - Series ID
 *  0b0011..Metering Series
 */
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SERIESID_SHIFT)) & SIM_SDID_SERIESID_MASK)

#define SIM_SDID_SUBFAMID_MASK                   (0xF000000U)
#define SIM_SDID_SUBFAMID_SHIFT                  (24U)
/*! SUBFAMID - Sub-Family ID
 *  0b0000..Device derivatives with NO AFE enabled
 *  0b0001..Device derivatives with 1 AFE enabled
 *  0b0010..Device derivatives with 2 AFE enabled
 *  0b0011..Device derivatives with 3 AFE enabled
 *  0b0100..Device derivatives with 4 AFE enabled
 */
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SUBFAMID_SHIFT)) & SIM_SDID_SUBFAMID_MASK)

#define SIM_SDID_FAMID_MASK                      (0xF0000000U)
#define SIM_SDID_FAMID_SHIFT                     (28U)
/*! FAMID - Metering family ID
 *  0b0001..Device derivatives without LCD
 *  0b0011..Device derivatives with LCD
 */
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_FAMID_SHIFT)) & SIM_SDID_FAMID_MASK)
/*! @} */

/*! @name SCGC4 - System Clock Gating Control Register 4 */
/*! @{ */

#define SIM_SCGC4_EWM_MASK                       (0x2U)
#define SIM_SCGC4_EWM_SHIFT                      (1U)
/*! EWM - External Watchdog Monitor Clock gate control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_EWM(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_EWM_SHIFT)) & SIM_SCGC4_EWM_MASK)

#define SIM_SCGC4_I2C0_MASK                      (0x80U)
#define SIM_SCGC4_I2C0_SHIFT                     (7U)
/*! I2C0 - I2C0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_I2C0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_I2C0_SHIFT)) & SIM_SCGC4_I2C0_MASK)

#define SIM_SCGC4_I2C1_MASK                      (0x100U)
#define SIM_SCGC4_I2C1_SHIFT                     (8U)
/*! I2C1 - I2C1 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_I2C1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_I2C1_SHIFT)) & SIM_SCGC4_I2C1_MASK)

#define SIM_SCGC4_UART0_MASK                     (0x400U)
#define SIM_SCGC4_UART0_SHIFT                    (10U)
/*! UART0 - UART0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_UART0(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART0_SHIFT)) & SIM_SCGC4_UART0_MASK)

#define SIM_SCGC4_UART1_MASK                     (0x800U)
#define SIM_SCGC4_UART1_SHIFT                    (11U)
/*! UART1 - UART1 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_UART1(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART1_SHIFT)) & SIM_SCGC4_UART1_MASK)

#define SIM_SCGC4_UART2_MASK                     (0x1000U)
#define SIM_SCGC4_UART2_SHIFT                    (12U)
/*! UART2 - UART2 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_UART2(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART2_SHIFT)) & SIM_SCGC4_UART2_MASK)

#define SIM_SCGC4_UART3_MASK                     (0x2000U)
#define SIM_SCGC4_UART3_SHIFT                    (13U)
/*! UART3 - UART3 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_UART3(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART3_SHIFT)) & SIM_SCGC4_UART3_MASK)

#define SIM_SCGC4_VREF_MASK                      (0x8000U)
#define SIM_SCGC4_VREF_SHIFT                     (15U)
/*! VREF - VREF Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_VREF(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_VREF_SHIFT)) & SIM_SCGC4_VREF_MASK)

#define SIM_SCGC4_CMP_MASK                       (0x40000U)
#define SIM_SCGC4_CMP_SHIFT                      (18U)
/*! CMP - High Speed Comparator Clock Gate Control.
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_CMP(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_CMP_SHIFT)) & SIM_SCGC4_CMP_MASK)

#define SIM_SCGC4_SPI0_MASK                      (0x200000U)
#define SIM_SCGC4_SPI0_SHIFT                     (21U)
/*! SPI0 - SPI0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_SPI0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_SPI0_SHIFT)) & SIM_SCGC4_SPI0_MASK)

#define SIM_SCGC4_SPI1_MASK                      (0x400000U)
#define SIM_SCGC4_SPI1_SHIFT                     (22U)
/*! SPI1 - SPI1 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_SPI1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_SPI1_SHIFT)) & SIM_SCGC4_SPI1_MASK)
/*! @} */

/*! @name SCGC5 - System Clock Gating Control Register 5 */
/*! @{ */

#define SIM_SCGC5_SLCD_MASK                      (0x8U)
#define SIM_SCGC5_SLCD_SHIFT                     (3U)
/*! SLCD - Segmented LCD Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_SLCD(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_SLCD_SHIFT)) & SIM_SCGC5_SLCD_MASK)

#define SIM_SCGC5_PORTA_MASK                     (0x40U)
#define SIM_SCGC5_PORTA_SHIFT                    (6U)
/*! PORTA - PCTLA Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTA_SHIFT)) & SIM_SCGC5_PORTA_MASK)

#define SIM_SCGC5_PORTB_MASK                     (0x80U)
#define SIM_SCGC5_PORTB_SHIFT                    (7U)
/*! PORTB - PCTLB Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTB_SHIFT)) & SIM_SCGC5_PORTB_MASK)

#define SIM_SCGC5_PORTC_MASK                     (0x100U)
#define SIM_SCGC5_PORTC_SHIFT                    (8U)
/*! PORTC - PCTLC Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTC_SHIFT)) & SIM_SCGC5_PORTC_MASK)

#define SIM_SCGC5_PORTD_MASK                     (0x200U)
#define SIM_SCGC5_PORTD_SHIFT                    (9U)
/*! PORTD - PCTLD Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTD_SHIFT)) & SIM_SCGC5_PORTD_MASK)

#define SIM_SCGC5_PORTE_MASK                     (0x400U)
#define SIM_SCGC5_PORTE_SHIFT                    (10U)
/*! PORTE - PCTLE Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTE_SHIFT)) & SIM_SCGC5_PORTE_MASK)

#define SIM_SCGC5_PORTF_MASK                     (0x800U)
#define SIM_SCGC5_PORTF_SHIFT                    (11U)
/*! PORTF - PCTLF Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTF(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTF_SHIFT)) & SIM_SCGC5_PORTF_MASK)

#define SIM_SCGC5_PORTG_MASK                     (0x1000U)
#define SIM_SCGC5_PORTG_SHIFT                    (12U)
/*! PORTG - PCTLG Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTG(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTG_SHIFT)) & SIM_SCGC5_PORTG_MASK)

#define SIM_SCGC5_PORTH_MASK                     (0x2000U)
#define SIM_SCGC5_PORTH_SHIFT                    (13U)
/*! PORTH - PCTLH Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTH(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTH_SHIFT)) & SIM_SCGC5_PORTH_MASK)

#define SIM_SCGC5_PORTI_MASK                     (0x4000U)
#define SIM_SCGC5_PORTI_SHIFT                    (14U)
/*! PORTI - PCTLI Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTI(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTI_SHIFT)) & SIM_SCGC5_PORTI_MASK)

#define SIM_SCGC5_RTC_MASK                       (0x10000U)
#define SIM_SCGC5_RTC_SHIFT                      (16U)
/*! RTC - iRTC Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_RTC(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_RTC_SHIFT)) & SIM_SCGC5_RTC_MASK)

#define SIM_SCGC5_RTCREG_MASK                    (0x20000U)
#define SIM_SCGC5_RTCREG_SHIFT                   (17U)
/*! RTCREG - iRTC_REG_FILE Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_RTCREG(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_RTCREG_SHIFT)) & SIM_SCGC5_RTCREG_MASK)

#define SIM_SCGC5_XBAR_MASK                      (0x200000U)
#define SIM_SCGC5_XBAR_SHIFT                     (21U)
/*! XBAR - Peripheral Crossbar Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_XBAR(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_XBAR_SHIFT)) & SIM_SCGC5_XBAR_MASK)

#define SIM_SCGC5_TMR0_MASK                      (0x800000U)
#define SIM_SCGC5_TMR0_SHIFT                     (23U)
/*! TMR0 - QaudTimer channel 0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_TMR0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_TMR0_SHIFT)) & SIM_SCGC5_TMR0_MASK)

#define SIM_SCGC5_TMR1_MASK                      (0x1000000U)
#define SIM_SCGC5_TMR1_SHIFT                     (24U)
/*! TMR1 - QaudTimer channel 1 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_TMR1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_TMR1_SHIFT)) & SIM_SCGC5_TMR1_MASK)

#define SIM_SCGC5_TMR2_MASK                      (0x2000000U)
#define SIM_SCGC5_TMR2_SHIFT                     (25U)
/*! TMR2 - QaudTimer channel 2 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_TMR2(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_TMR2_SHIFT)) & SIM_SCGC5_TMR2_MASK)

#define SIM_SCGC5_TMR3_MASK                      (0x4000000U)
#define SIM_SCGC5_TMR3_SHIFT                     (26U)
/*! TMR3 - QaudTimer channel 3 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_TMR3(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_TMR3_SHIFT)) & SIM_SCGC5_TMR3_MASK)
/*! @} */

/*! @name SCGC6 - System Clock Gating Control Register 6 */
/*! @{ */

#define SIM_SCGC6_FTFA_MASK                      (0x1U)
#define SIM_SCGC6_FTFA_SHIFT                     (0U)
/*! FTFA - FTFA Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_FTFA(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_FTFA_SHIFT)) & SIM_SCGC6_FTFA_MASK)

#define SIM_SCGC6_DMACHMUX_MASK                  (0x2U)
#define SIM_SCGC6_DMACHMUX_SHIFT                 (1U)
/*! DMACHMUX - DMA Channel MUX Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_DMACHMUX(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DMACHMUX_SHIFT)) & SIM_SCGC6_DMACHMUX_MASK)

#define SIM_SCGC6_RNGA_MASK                      (0x200U)
#define SIM_SCGC6_RNGA_SHIFT                     (9U)
/*! RNGA - RNGA Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_RNGA(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_RNGA_SHIFT)) & SIM_SCGC6_RNGA_MASK)

#define SIM_SCGC6_LPUART_MASK                    (0x400U)
#define SIM_SCGC6_LPUART_SHIFT                   (10U)
/*! LPUART - LPUART Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_LPUART(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_LPUART_SHIFT)) & SIM_SCGC6_LPUART_MASK)

#define SIM_SCGC6_ADC_MASK                       (0x800U)
#define SIM_SCGC6_ADC_SHIFT                      (11U)
/*! ADC - SAR ADC Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_ADC(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_ADC_SHIFT)) & SIM_SCGC6_ADC_MASK)

#define SIM_SCGC6_PIT0_MASK                      (0x2000U)
#define SIM_SCGC6_PIT0_SHIFT                     (13U)
/*! PIT0 - PIT0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_PIT0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PIT0_SHIFT)) & SIM_SCGC6_PIT0_MASK)

#define SIM_SCGC6_PIT1_MASK                      (0x4000U)
#define SIM_SCGC6_PIT1_SHIFT                     (14U)
/*! PIT1 - PIT1 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_PIT1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PIT1_SHIFT)) & SIM_SCGC6_PIT1_MASK)

#define SIM_SCGC6_AFE_MASK                       (0x10000U)
#define SIM_SCGC6_AFE_SHIFT                      (16U)
/*! AFE - AFE Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_AFE(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_AFE_SHIFT)) & SIM_SCGC6_AFE_MASK)

#define SIM_SCGC6_CRC_MASK                       (0x100000U)
#define SIM_SCGC6_CRC_SHIFT                      (20U)
/*! CRC - Programmable CRC Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_CRC(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_CRC_SHIFT)) & SIM_SCGC6_CRC_MASK)

#define SIM_SCGC6_PDB_MASK                       (0x400000U)
#define SIM_SCGC6_PDB_SHIFT                      (22U)
/*! PDB - PDB Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_PDB(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PDB_SHIFT)) & SIM_SCGC6_PDB_MASK)

#define SIM_SCGC6_PORTJ_MASK                     (0x800000U)
#define SIM_SCGC6_PORTJ_SHIFT                    (23U)
/*! PORTJ - PCTLJ Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_PORTJ(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PORTJ_SHIFT)) & SIM_SCGC6_PORTJ_MASK)

#define SIM_SCGC6_PORTK_MASK                     (0x1000000U)
#define SIM_SCGC6_PORTK_SHIFT                    (24U)
/*! PORTK - PCTLK Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_PORTK(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PORTK_SHIFT)) & SIM_SCGC6_PORTK_MASK)

#define SIM_SCGC6_PORTL_MASK                     (0x2000000U)
#define SIM_SCGC6_PORTL_SHIFT                    (25U)
/*! PORTL - PCTLL Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_PORTL(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PORTL_SHIFT)) & SIM_SCGC6_PORTL_MASK)

#define SIM_SCGC6_PORTM_MASK                     (0x4000000U)
#define SIM_SCGC6_PORTM_SHIFT                    (26U)
/*! PORTM - PCTLM Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_PORTM(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PORTM_SHIFT)) & SIM_SCGC6_PORTM_MASK)

#define SIM_SCGC6_LPTMR_MASK                     (0x10000000U)
#define SIM_SCGC6_LPTMR_SHIFT                    (28U)
/*! LPTMR - LPTMR Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_LPTMR(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_LPTMR_SHIFT)) & SIM_SCGC6_LPTMR_MASK)
/*! @} */

/*! @name SCGC7 - System Clock Gating Control Register 7 */
/*! @{ */

#define SIM_SCGC7_MPU_MASK                       (0x1U)
#define SIM_SCGC7_MPU_SHIFT                      (0U)
/*! MPU - MPU Clock Gate control.
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC7_MPU(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC7_MPU_SHIFT)) & SIM_SCGC7_MPU_MASK)

#define SIM_SCGC7_DMA_MASK                       (0x2U)
#define SIM_SCGC7_DMA_SHIFT                      (1U)
/*! DMA - DMA Clock Gate control.
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC7_DMA(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC7_DMA_SHIFT)) & SIM_SCGC7_DMA_MASK)

#define SIM_SCGC7_CAU_MASK                       (0x4U)
#define SIM_SCGC7_CAU_SHIFT                      (2U)
/*! CAU - CAU Clock Gate control.
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC7_CAU(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC7_CAU_SHIFT)) & SIM_SCGC7_CAU_MASK)
/*! @} */

/*! @name CLKDIV1 - System Clock Divider Register 1 */
/*! @{ */

#define SIM_CLKDIV1_FLASHCLKMODE_MASK            (0x10000U)
#define SIM_CLKDIV1_FLASHCLKMODE_SHIFT           (16U)
/*! FLASHCLKMODE - Flash Clock Mode
 *  0b0..Flash Clock is the same as BUS clock.
 *  0b1..Flash Clock is a half of BUS clock.
 */
#define SIM_CLKDIV1_FLASHCLKMODE(x)              (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_FLASHCLKMODE_SHIFT)) & SIM_CLKDIV1_FLASHCLKMODE_MASK)

#define SIM_CLKDIV1_CLKDIVBUS_MASK               (0x3000000U)
#define SIM_CLKDIV1_CLKDIVBUS_SHIFT              (24U)
/*! CLKDIVBUS - Bus Clock divider
 *  0b00..SYSCLK:BUSCLK = 1:1
 *  0b01..SYSCLK:BUSCLK = 2:1
 *  0b10..SYSCLK:BUSCLK = 3:1
 *  0b11..SYSCLK:BUSCLK = 4:1
 */
#define SIM_CLKDIV1_CLKDIVBUS(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_CLKDIVBUS_SHIFT)) & SIM_CLKDIV1_CLKDIVBUS_MASK)

#define SIM_CLKDIV1_CLKDIVSYS_MASK               (0xF0000000U)
#define SIM_CLKDIV1_CLKDIVSYS_SHIFT              (28U)
/*! CLKDIVSYS - System Clock divider
 *  0b0000..Divide by 1
 *  0b0001..Divide by 2
 *  0b0010..Divide by 3
 *  0b0011..Divide by 4 and so on... If FOPT[0] is 0, the divider is set to div-by-8 after system reset is
 *          deasserted (after completion of system initialization sequence).
 */
#define SIM_CLKDIV1_CLKDIVSYS(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_CLKDIVSYS_SHIFT)) & SIM_CLKDIV1_CLKDIVSYS_MASK)
/*! @} */

/*! @name FCFG1 - Flash Configuration Register 1 */
/*! @{ */

#define SIM_FCFG1_FLASHDIS_MASK                  (0x1U)
#define SIM_FCFG1_FLASHDIS_SHIFT                 (0U)
/*! FLASHDIS - Flash Disable
 *  0b0..Flash is enabled
 *  0b1..Flash is disabled
 */
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDIS_SHIFT)) & SIM_FCFG1_FLASHDIS_MASK)

#define SIM_FCFG1_FLASHDOZE_MASK                 (0x2U)
#define SIM_FCFG1_FLASHDOZE_SHIFT                (1U)
/*! FLASHDOZE - Flash Doze
 *  0b0..Flash remains enabled during Wait mode
 *  0b1..Flash is disabled for the duration of Wait mode
 */
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDOZE_SHIFT)) & SIM_FCFG1_FLASHDOZE_MASK)

#define SIM_FCFG1_PFSIZE_MASK                    (0xF000000U)
#define SIM_FCFG1_PFSIZE_SHIFT                   (24U)
/*! PFSIZE - Program flash size
 *  0b0000..Reserved
 *  0b0001..Reserved
 *  0b0011..Reserved
 *  0b0100..Reserved
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..128 KB of program flash memory
 *  0b1000..Reserved
 *  0b1001..256 KB of program flash memory
 *  0b1111..(Default)
 */
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_PFSIZE_SHIFT)) & SIM_FCFG1_PFSIZE_MASK)
/*! @} */

/*! @name FCFG2 - Flash Configuration Register 2 */
/*! @{ */

#define SIM_FCFG2_MAXADDR_MASK                   (0x7F000000U)
#define SIM_FCFG2_MAXADDR_SHIFT                  (24U)
/*! MAXADDR - Max address */
#define SIM_FCFG2_MAXADDR(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_MAXADDR_SHIFT)) & SIM_FCFG2_MAXADDR_MASK)
/*! @} */

/*! @name UIDH - Unique Identification Register High */
/*! @{ */

#define SIM_UIDH_UID127_96_MASK                  (0xFFFFFFFFU)
#define SIM_UIDH_UID127_96_SHIFT                 (0U)
/*! UID127_96 - Unique Identification UID[127:96] */
#define SIM_UIDH_UID127_96(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_UIDH_UID127_96_SHIFT)) & SIM_UIDH_UID127_96_MASK)
/*! @} */

/*! @name UIDMH - Unique Identification Register Mid-High */
/*! @{ */

#define SIM_UIDMH_UID95_64_MASK                  (0xFFFFFFFFU)
#define SIM_UIDMH_UID95_64_SHIFT                 (0U)
/*! UID95_64 - Unique Identification UID[95:64] */
#define SIM_UIDMH_UID95_64(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_UIDMH_UID95_64_SHIFT)) & SIM_UIDMH_UID95_64_MASK)
/*! @} */

/*! @name UIDML - Unique Identification Register Mid-Low */
/*! @{ */

#define SIM_UIDML_UID63_32_MASK                  (0xFFFFFFFFU)
#define SIM_UIDML_UID63_32_SHIFT                 (0U)
/*! UID63_32 - Unique Identification UID[63:32] */
#define SIM_UIDML_UID63_32(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_UIDML_UID63_32_SHIFT)) & SIM_UIDML_UID63_32_MASK)
/*! @} */

/*! @name UIDL - Unique Identification Register Low */
/*! @{ */

#define SIM_UIDL_UID31_0_MASK                    (0xFFFFFFFFU)
#define SIM_UIDL_UID31_0_SHIFT                   (0U)
/*! UID31_0 - Unique Identification UID[31:0] */
#define SIM_UIDL_UID31_0(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_UIDL_UID31_0_SHIFT)) & SIM_UIDL_UID31_0_MASK)
/*! @} */

/*! @name MISC_CTL - Miscellaneous Control Register */
/*! @{ */

#define SIM_MISC_CTL_OSCON_MASK                  (0x1U)
#define SIM_MISC_CTL_OSCON_SHIFT                 (0U)
/*! OSCON - RTC oscillator status
 *  0b0..RTC oscillator is disabled.
 *  0b1..RTC oscillator is enabled.
 */
#define SIM_MISC_CTL_OSCON(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_OSCON_SHIFT)) & SIM_MISC_CTL_OSCON_MASK)

#define SIM_MISC_CTL_PDBADCTRG_MASK              (0x2U)
#define SIM_MISC_CTL_PDBADCTRG_SHIFT             (1U)
/*! PDBADCTRG - PDB bypass XBAR as ADC trigger
 *  0b0..XBAR to trigger ADC
 *  0b1..PDB output to trigger ADC
 */
#define SIM_MISC_CTL_PDBADCTRG(x)                (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_PDBADCTRG_SHIFT)) & SIM_MISC_CTL_PDBADCTRG_MASK)

#define SIM_MISC_CTL_DMADONESEL_MASK             (0xCU)
#define SIM_MISC_CTL_DMADONESEL_SHIFT            (2U)
/*! DMADONESEL - DMA Done select
 *  0b00..DMA0
 *  0b01..DMA1
 *  0b10..DMA2
 *  0b11..DMA3
 */
#define SIM_MISC_CTL_DMADONESEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_DMADONESEL_SHIFT)) & SIM_MISC_CTL_DMADONESEL_MASK)

#define SIM_MISC_CTL_AFECLKSEL_MASK              (0x30U)
#define SIM_MISC_CTL_AFECLKSEL_SHIFT             (4U)
/*! AFECLKSEL - AFE Clock Source Select (SIMAFECLK selection)
 *  0b00..MCG PLL Clock selected
 *  0b01..MCG FLL Clock selected
 *  0b10..OSC Clock selected
 *  0b11..Disabled
 */
#define SIM_MISC_CTL_AFECLKSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_AFECLKSEL_SHIFT)) & SIM_MISC_CTL_AFECLKSEL_MASK)

#define SIM_MISC_CTL_AFECLKPADDIR_MASK           (0x40U)
#define SIM_MISC_CTL_AFECLKPADDIR_SHIFT          (6U)
/*! AFECLKPADDIR - AFE Clock Pad Direction
 *  0b0..AFE CLK PAD is input
 *  0b1..AFE CLK PAD is output
 */
#define SIM_MISC_CTL_AFECLKPADDIR(x)             (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_AFECLKPADDIR_SHIFT)) & SIM_MISC_CTL_AFECLKPADDIR_MASK)

#define SIM_MISC_CTL_UARTMODTYPE_MASK            (0x80U)
#define SIM_MISC_CTL_UARTMODTYPE_SHIFT           (7U)
/*! UARTMODTYPE - UART Modulation Type
 *  0b0..TypeA (OR'ed) Modulation selected for IrDA
 *  0b1..TypeB (AND'ed) Modulation selected for IrDA
 */
#define SIM_MISC_CTL_UARTMODTYPE(x)              (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_UARTMODTYPE_SHIFT)) & SIM_MISC_CTL_UARTMODTYPE_MASK)

#define SIM_MISC_CTL_UART0IRSEL_MASK             (0x100U)
#define SIM_MISC_CTL_UART0IRSEL_SHIFT            (8U)
/*! UART0IRSEL - UART0 IrDA Select
 *  0b0..Pad RX input (PTD[0], PTF[3] or PTK[3], as selected in Pinmux control) selected for RX input of UART0 and
 *       UART0 TX signal is not used for modulation
 *  0b1..UART0 selected for IrDA modulation. UART0 TX modulated by XBAR_OUT[14] and UART0 RX input connected to
 *       XBAR_OUT[13]. UARTxIRSEL cannot configure XBAR_OUT[14] and XBAR_OUT[13] automatically, and they need extra
 *       configuration in XBAR. User should configure XBAR[14:13] accordingly.
 */
#define SIM_MISC_CTL_UART0IRSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_UART0IRSEL_SHIFT)) & SIM_MISC_CTL_UART0IRSEL_MASK)

#define SIM_MISC_CTL_UART1IRSEL_MASK             (0x200U)
#define SIM_MISC_CTL_UART1IRSEL_SHIFT            (9U)
/*! UART1IRSEL - UART1 IrDA Select
 *  0b0..Pad RX input (PTD[2], PTI[0] or PTK[5], as selected in Pinmux control) selected for RX input of UART1 and
 *       UART1 TX signal is not used for modulation
 *  0b1..UART1 selected for IrDA modulation. UART1 TX modulated by XBAR_OUT[14] and UART1 RX input connected to
 *       XBAR_OUT[13].UARTxIRSEL cannot configure XBAR_OUT[14] and XBAR_OUT[13] automatically, and they need extra
 *       configuration in XBAR. User should configure XBAR[14:13] accordingly.
 */
#define SIM_MISC_CTL_UART1IRSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_UART1IRSEL_SHIFT)) & SIM_MISC_CTL_UART1IRSEL_MASK)

#define SIM_MISC_CTL_UART2IRSEL_MASK             (0x400U)
#define SIM_MISC_CTL_UART2IRSEL_SHIFT            (10U)
/*! UART2IRSEL - UART2 IrDA Select
 *  0b0..Pad RX input PTI[6] or PTE[6] selected for RX input of UART2 and UART2 TX signal is not used for modulation
 *  0b1..UART2 selected for IrDA modulation. UART2 TX modulated by XBAR_OUT[14] and UART2 RX input connected to
 *       XBAR_OUT[13].UARTxIRSEL cannot configure XBAR_OUT[14] and XBAR_OUT[13] automatically, and they need extra
 *       configuration in XBAR. User should configure XBAR[14:13] accordingly.
 */
#define SIM_MISC_CTL_UART2IRSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_UART2IRSEL_SHIFT)) & SIM_MISC_CTL_UART2IRSEL_MASK)

#define SIM_MISC_CTL_UART3IRSEL_MASK             (0x800U)
#define SIM_MISC_CTL_UART3IRSEL_SHIFT            (11U)
/*! UART3IRSEL - UART3 IrDA Select
 *  0b0..Pad RX input (PTC[3] or PTD[7], as selected in Pinmux control) selected for RX input of UART3 and UART3 TX signal is not used for modulation
 *  0b1..UART3 selected for IrDA modulation. UART3 TX modulated by XBAR_OUT[14] and UART3 RX input connected to
 *       XBAR_OUT[13]. UARTxIRSEL cannot configure XBAR_OUT[14] and XBAR_OUT[13] automatically, and they need extra
 *       configuration in XBAR. User should configure XBAR[14:13] accordingly.
 */
#define SIM_MISC_CTL_UART3IRSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_UART3IRSEL_SHIFT)) & SIM_MISC_CTL_UART3IRSEL_MASK)

#define SIM_MISC_CTL_EWMINSEL_MASK               (0x4000U)
#define SIM_MISC_CTL_EWMINSEL_SHIFT              (14U)
/*! EWMINSEL - External Watchdog Monitor Input Select
 *  0b0..Input from PAD (PTL[3], PTE[2] or PTE[3] as selected from Pinmux control )
 *  0b1..Peripheral Crossbar (XBAR) Output[32]
 */
#define SIM_MISC_CTL_EWMINSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_EWMINSEL_SHIFT)) & SIM_MISC_CTL_EWMINSEL_MASK)

#define SIM_MISC_CTL_TMR0PLLSEL_MASK             (0x8000U)
#define SIM_MISC_CTL_TMR0PLLSEL_SHIFT            (15U)
/*! TMR0PLLSEL - Timer CH0 PLL clock Select
 *  0b0..Selects Bus Clock as source for the Timer CH0
 *  0b1..Selects the PLL_AFE clock as the source for Timer CH0. The PLL_AFE clock source is itself selected using the MISC_CTL[5:4]
 */
#define SIM_MISC_CTL_TMR0PLLSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR0PLLSEL_SHIFT)) & SIM_MISC_CTL_TMR0PLLSEL_MASK)

#define SIM_MISC_CTL_TMR0SCSEL_MASK              (0x10000U)
#define SIM_MISC_CTL_TMR0SCSEL_SHIFT             (16U)
/*! TMR0SCSEL - Quadtimer Channel0 Secondary Count source Select
 *  0b0..Pad PTF1 or PTD5, depending upon PCTL configuration.
 *  0b1..Peripheral Crossbar (XBAR) Output[5]
 */
#define SIM_MISC_CTL_TMR0SCSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR0SCSEL_SHIFT)) & SIM_MISC_CTL_TMR0SCSEL_MASK)

#define SIM_MISC_CTL_TMR1SCSEL_MASK              (0x20000U)
#define SIM_MISC_CTL_TMR1SCSEL_SHIFT             (17U)
/*! TMR1SCSEL - Quadtimer Channel1 Secondary Count source Select
 *  0b0..Pad PTG0 or PTC6, depending upon PCTL configuration.
 *  0b1..Peripheral Crossbar (XBAR) Output[6]
 */
#define SIM_MISC_CTL_TMR1SCSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR1SCSEL_SHIFT)) & SIM_MISC_CTL_TMR1SCSEL_MASK)

#define SIM_MISC_CTL_TMR2SCSEL_MASK              (0x40000U)
#define SIM_MISC_CTL_TMR2SCSEL_SHIFT             (18U)
/*! TMR2SCSEL - Quadtimer Channel2 Secondary Count source Select
 *  0b0..Pad PTF7 or PTF0, depending upon PCTL configuration.
 *  0b1..Peripheral Crossbar (XBAR) Output[7]
 */
#define SIM_MISC_CTL_TMR2SCSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR2SCSEL_SHIFT)) & SIM_MISC_CTL_TMR2SCSEL_MASK)

#define SIM_MISC_CTL_TMR3SCSEL_MASK              (0x80000U)
#define SIM_MISC_CTL_TMR3SCSEL_SHIFT             (19U)
/*! TMR3SCSEL - Quadtimer Channel3 Secondary Count source Select
 *  0b0..Pad PTE5 or PTD1, depending upon PCTL configuration.
 *  0b1..Peripheral Crossbar (XBAR) Output[8]
 */
#define SIM_MISC_CTL_TMR3SCSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR3SCSEL_SHIFT)) & SIM_MISC_CTL_TMR3SCSEL_MASK)

#define SIM_MISC_CTL_TMR0PCSSEL_MASK             (0x300000U)
#define SIM_MISC_CTL_TMR0PCSSEL_SHIFT            (20U)
/*! TMR0PCSSEL - Quadtimer Channel0 Primary Count Source Select
 *  0b00..Bus Clock
 *  0b01..Peripheral Crossbar Output [9]
 *  0b10..Peripheral Crossbar Output [10]
 *  0b11..Disabled
 */
#define SIM_MISC_CTL_TMR0PCSSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR0PCSSEL_SHIFT)) & SIM_MISC_CTL_TMR0PCSSEL_MASK)

#define SIM_MISC_CTL_TMR1PCSSEL_MASK             (0xC00000U)
#define SIM_MISC_CTL_TMR1PCSSEL_SHIFT            (22U)
/*! TMR1PCSSEL - Quadtimer Channel1 Primary Count Source Select
 *  0b00..Bus Clock
 *  0b01..Peripheral Crossbar Output [9]
 *  0b10..Peripheral Crossbar Output [10]
 *  0b11..Disabled
 */
#define SIM_MISC_CTL_TMR1PCSSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR1PCSSEL_SHIFT)) & SIM_MISC_CTL_TMR1PCSSEL_MASK)

#define SIM_MISC_CTL_TMR2PCSSEL_MASK             (0x3000000U)
#define SIM_MISC_CTL_TMR2PCSSEL_SHIFT            (24U)
/*! TMR2PCSSEL - Quadtimer Channel2 Primary Count Source Select
 *  0b00..Bus Clock
 *  0b01..Peripheral Crossbar Output [9]
 *  0b10..Peripheral Crossbar Output [10]
 *  0b11..Disabled
 */
#define SIM_MISC_CTL_TMR2PCSSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR2PCSSEL_SHIFT)) & SIM_MISC_CTL_TMR2PCSSEL_MASK)

#define SIM_MISC_CTL_TMR3PCSSEL_MASK             (0xC000000U)
#define SIM_MISC_CTL_TMR3PCSSEL_SHIFT            (26U)
/*! TMR3PCSSEL - Quadtimer Channel3 Primary Count Source Select
 *  0b00..Bus Clock
 *  0b01..Peripheral Crossbar Output [9]
 *  0b10..Peripheral Crossbar Output [10]
 *  0b11..Disabled
 */
#define SIM_MISC_CTL_TMR3PCSSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR3PCSSEL_SHIFT)) & SIM_MISC_CTL_TMR3PCSSEL_MASK)

#define SIM_MISC_CTL_RTCCLKSEL_MASK              (0x10000000U)
#define SIM_MISC_CTL_RTCCLKSEL_SHIFT             (28U)
/*! RTCCLKSEL - RTC Clock select
 *  0b0..RTC OSC_32K clock selected
 *  0b1..MCGIRCLK selected
 */
#define SIM_MISC_CTL_RTCCLKSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_RTCCLKSEL_SHIFT)) & SIM_MISC_CTL_RTCCLKSEL_MASK)

#define SIM_MISC_CTL_VREFBUFOUTEN_MASK           (0x20000000U)
#define SIM_MISC_CTL_VREFBUFOUTEN_SHIFT          (29U)
/*! VREFBUFOUTEN - VrefBuffer Output Enable
 *  0b0..Buffer does not drive PAD
 *  0b1..Buffer drives selected voltage (selected by vref_buffer_sel) on pad
 */
#define SIM_MISC_CTL_VREFBUFOUTEN(x)             (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_VREFBUFOUTEN_SHIFT)) & SIM_MISC_CTL_VREFBUFOUTEN_MASK)

#define SIM_MISC_CTL_VREFBUFINSEL_MASK           (0x40000000U)
#define SIM_MISC_CTL_VREFBUFINSEL_SHIFT          (30U)
/*! VREFBUFINSEL - VrefBuffer Input Select
 *  0b0..Internal Reference selected as Buffer Input
 *  0b1..External Reference selected as Buffer Input
 */
#define SIM_MISC_CTL_VREFBUFINSEL(x)             (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_VREFBUFINSEL_SHIFT)) & SIM_MISC_CTL_VREFBUFINSEL_MASK)

#define SIM_MISC_CTL_VREFBUFPD_MASK              (0x80000000U)
#define SIM_MISC_CTL_VREFBUFPD_SHIFT             (31U)
/*! VREFBUFPD - VrefBuffer Power Down
 *  0b0..Buffer Enabled
 *  0b1..Buffer Powered Down
 */
#define SIM_MISC_CTL_VREFBUFPD(x)                (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_VREFBUFPD_SHIFT)) & SIM_MISC_CTL_VREFBUFPD_MASK)
/*! @} */

/*! @name ADC_COMP0 - ADC Compensation Register 0 */
/*! @{ */

#define SIM_ADC_COMP0_ADCCOMPVAL0_MASK           (0xFFFFU)
#define SIM_ADC_COMP0_ADCCOMPVAL0_SHIFT          (0U)
/*! ADCCOMPVAL0 - ADC Temperature Compensation Value 0 */
#define SIM_ADC_COMP0_ADCCOMPVAL0(x)             (((uint32_t)(((uint32_t)(x)) << SIM_ADC_COMP0_ADCCOMPVAL0_SHIFT)) & SIM_ADC_COMP0_ADCCOMPVAL0_MASK)

#define SIM_ADC_COMP0_ADCCOMPVAL1_MASK           (0xFFFF0000U)
#define SIM_ADC_COMP0_ADCCOMPVAL1_SHIFT          (16U)
/*! ADCCOMPVAL1 - ADC Temperature Compensation Value 1 */
#define SIM_ADC_COMP0_ADCCOMPVAL1(x)             (((uint32_t)(((uint32_t)(x)) << SIM_ADC_COMP0_ADCCOMPVAL1_SHIFT)) & SIM_ADC_COMP0_ADCCOMPVAL1_MASK)
/*! @} */

/*! @name ADC_COMP1 - ADC Compensation Register 1 */
/*! @{ */

#define SIM_ADC_COMP1_ADCCOMPVAL2_MASK           (0xFFFFU)
#define SIM_ADC_COMP1_ADCCOMPVAL2_SHIFT          (0U)
/*! ADCCOMPVAL2 - ADC Temperature Compensation Value 2 */
#define SIM_ADC_COMP1_ADCCOMPVAL2(x)             (((uint32_t)(((uint32_t)(x)) << SIM_ADC_COMP1_ADCCOMPVAL2_SHIFT)) & SIM_ADC_COMP1_ADCCOMPVAL2_MASK)
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

