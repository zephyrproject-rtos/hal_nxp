/*
** ###################################################################
**     Processors:          MKM14Z128ACHH5
**                          MKM14Z64ACHH5
**                          MKM33Z128ACLH5
**                          MKM33Z128ACLL5
**                          MKM33Z64ACLH5
**                          MKM33Z64ACLL5
**                          MKM34Z128ACLL5
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
**     - rev. 1.0 (2014-07-22)
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

#if (defined(CPU_MKM14Z128ACHH5) || defined(CPU_MKM14Z64ACHH5))
#include "MKM14ZA5_COMMON.h"
#elif (defined(CPU_MKM33Z128ACLH5) || defined(CPU_MKM33Z128ACLL5) || defined(CPU_MKM33Z64ACLH5) || defined(CPU_MKM33Z64ACLL5))
#include "MKM33ZA5_COMMON.h"
#elif (defined(CPU_MKM34Z128ACLL5))
#include "MKM34ZA5_COMMON.h"
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
 *  0b0101..16kB System RAM
 */
#define SIM_SOPT1_SRAMSIZE(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_SRAMSIZE_SHIFT)) & SIM_SOPT1_SRAMSIZE_MASK)

#define SIM_SOPT1_OSC32KSEL_MASK                 (0xC0000U)
#define SIM_SOPT1_OSC32KSEL_SHIFT                (18U)
/*! OSC32KSEL - 32K oscillator clock select
 *  0b00..OSC32KCLK
 *  0b01..ERCLK32K
 *  0b10..MCGIRCLK
 *  0b11..LPO
 */
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_OSC32KSEL_SHIFT)) & SIM_SOPT1_OSC32KSEL_MASK)
/*! @} */

/*! @name SOPT1_CFG - SOPT1 Configuration Register */
/*! @{ */

#define SIM_SOPT1_CFG_LPTMR1SEL_MASK             (0x3U)
#define SIM_SOPT1_CFG_LPTMR1SEL_SHIFT            (0U)
/*! LPTMR1SEL - LP timer Channel1 Select
 *  0b00..Pad PTE4
 *  0b01..Pad PTF4
 *  0b10..Pad PTG1
 *  0b11..Reserved
 */
#define SIM_SOPT1_CFG_LPTMR1SEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_CFG_LPTMR1SEL_SHIFT)) & SIM_SOPT1_CFG_LPTMR1SEL_MASK)

#define SIM_SOPT1_CFG_LPTMR2SEL_MASK             (0xCU)
#define SIM_SOPT1_CFG_LPTMR2SEL_SHIFT            (2U)
/*! LPTMR2SEL - LP timer Channel2 Select
 *  0b00..Pad PTD6
 *  0b01..Pad PTF3
 *  0b10..Pad PTG5
 *  0b11..Reserved
 */
#define SIM_SOPT1_CFG_LPTMR2SEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_CFG_LPTMR2SEL_SHIFT)) & SIM_SOPT1_CFG_LPTMR2SEL_MASK)

#define SIM_SOPT1_CFG_LPTMR3SEL_MASK             (0x30U)
#define SIM_SOPT1_CFG_LPTMR3SEL_SHIFT            (4U)
/*! LPTMR3SEL - LP timer Channel3 Select
 *  0b00..Pad PTD5
 *  0b01..Pad PTG0
 *  0b10..Pad PTG6
 *  0b11..Reserved
 */
#define SIM_SOPT1_CFG_LPTMR3SEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_CFG_LPTMR3SEL_SHIFT)) & SIM_SOPT1_CFG_LPTMR3SEL_MASK)

#define SIM_SOPT1_CFG_CMPOLPTMR0SEL_MASK         (0x40U)
#define SIM_SOPT1_CFG_CMPOLPTMR0SEL_SHIFT        (6U)
/*! CMPOLPTMR0SEL - Comparator output selection for LPTMR channel0
 *  0b0..CMP[1] output selected as LPTMR input[0]
 *  0b1..CMP[0] output selected as LPTMR input[0]
 */
#define SIM_SOPT1_CFG_CMPOLPTMR0SEL(x)           (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_CFG_CMPOLPTMR0SEL_SHIFT)) & SIM_SOPT1_CFG_CMPOLPTMR0SEL_MASK)

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

#define SIM_CTRL_REG_PLL_VLP_EN_MASK             (0x2U)
#define SIM_CTRL_REG_PLL_VLP_EN_SHIFT            (1U)
/*! PLL_VLP_EN - PLL VLP Enable */
#define SIM_CTRL_REG_PLL_VLP_EN(x)               (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_PLL_VLP_EN_SHIFT)) & SIM_CTRL_REG_PLL_VLP_EN_MASK)

#define SIM_CTRL_REG_PTC2_HD_EN_MASK             (0x4U)
#define SIM_CTRL_REG_PTC2_HD_EN_SHIFT            (2U)
/*! PTC2_HD_EN - PTC2 HighDrive Enable */
#define SIM_CTRL_REG_PTC2_HD_EN(x)               (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_PTC2_HD_EN_SHIFT)) & SIM_CTRL_REG_PTC2_HD_EN_MASK)

#define SIM_CTRL_REG_SAR_TRG_CLK_SEL_MASK        (0x18U)
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL_SHIFT       (3U)
/*! SAR_TRG_CLK_SEL - SAR ADC Trigger Clk Select
 *  0b00..Bus Clock (During Low Power Modes such as stop, the Bus clock is not available for conversion and should
 *        not be selected in case a conversion needs to be performed while in stop)
 *  0b01..ADC asynchronous Clock
 *  0b10..ERCLK32K
 *  0b11..OSCCLK
 */
#define SIM_CTRL_REG_SAR_TRG_CLK_SEL(x)          (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_SAR_TRG_CLK_SEL_SHIFT)) & SIM_CTRL_REG_SAR_TRG_CLK_SEL_MASK)

#define SIM_CTRL_REG_CLKOUTSEL_MASK              (0xE0U)
#define SIM_CTRL_REG_CLKOUTSEL_SHIFT             (5U)
/*! CLKOUTSEL - Clock out Select
 *  0b000..Disabled
 *  0b001..Gated Core Clk
 *  0b010..Bus/Flash Clk
 *  0b011..LPO clock from PMC
 *  0b100..IRC clock from MCG
 *  0b101..Muxed 32Khz source (please refer SOPT1[19:18] for possible options)
 *  0b110..MHz Oscillator external reference clock
 *  0b111..PLL clock output from MCG
 */
#define SIM_CTRL_REG_CLKOUTSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CTRL_REG_CLKOUTSEL_SHIFT)) & SIM_CTRL_REG_CLKOUTSEL_MASK)
/*! @} */

/*! @name SDID - System Device Identification Register */
/*! @{ */

#define SIM_SDID_PINID_MASK                      (0xFU)
#define SIM_SDID_PINID_SHIFT                     (0U)
/*! PINID - Pincount identification
 *  0b0000-0b0010..Reserved
 *  0b0011..44-pin
 *  0b0100..Reserved
 *  0b0101..64-pin
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..100-pin
 *  0b1001..Reserved
 *  0b1010..Reserved
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
 *  0b0010..Third Cut
 */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_REVID_SHIFT)) & SIM_SDID_REVID_MASK)

#define SIM_SDID_SRAMSIZE_MASK                   (0xF000U)
#define SIM_SDID_SRAMSIZE_SHIFT                  (12U)
/*! SRAMSIZE - SRAM Size
 *  0b0101..16kB SRAM
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
 *  0b0010..Device derivatives with 2 AFE enabled (AFE Channels 0 and 2 are enabled)
 *  0b0011..Device derivatives with 3 AFE enabled (AFE Channels 0, 1, and 2 are enabled)
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

#define SIM_SCGC4_MCG_MASK                       (0x10U)
#define SIM_SCGC4_MCG_SHIFT                      (4U)
/*! MCG - MCG clock gate control.
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_MCG(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_MCG_SHIFT)) & SIM_SCGC4_MCG_MASK)

#define SIM_SCGC4_OSC_MASK                       (0x40U)
#define SIM_SCGC4_OSC_SHIFT                      (6U)
/*! OSC - Oscillator (Mhz) Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_OSC(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_OSC_SHIFT)) & SIM_SCGC4_OSC_MASK)

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

#define SIM_SCGC4_CMP0_MASK                      (0x40000U)
#define SIM_SCGC4_CMP0_SHIFT                     (18U)
/*! CMP0 - High Speed Comparator0 Clock Gate Control.
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_CMP0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_CMP0_SHIFT)) & SIM_SCGC4_CMP0_MASK)

#define SIM_SCGC4_CMP1_MASK                      (0x80000U)
#define SIM_SCGC4_CMP1_SHIFT                     (19U)
/*! CMP1 - High Speed Comparator1 Clock Gate Control.
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_CMP1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_CMP1_SHIFT)) & SIM_SCGC4_CMP1_MASK)

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

#define SIM_SCGC5_IRTC_MASK                      (0x10000U)
#define SIM_SCGC5_IRTC_SHIFT                     (16U)
/*! IRTC - IRTC Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_IRTC(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_IRTC_SHIFT)) & SIM_SCGC5_IRTC_MASK)

#define SIM_SCGC5_IRTCREGFILE_MASK               (0x20000U)
#define SIM_SCGC5_IRTCREGFILE_SHIFT              (17U)
/*! IRTCREGFILE - IRTC_REG_FILE Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_IRTCREGFILE(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_IRTCREGFILE_SHIFT)) & SIM_SCGC5_IRTCREGFILE_MASK)

#define SIM_SCGC5_WDOG_MASK                      (0x80000U)
#define SIM_SCGC5_WDOG_SHIFT                     (19U)
/*! WDOG - Watchdog Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_WDOG(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_WDOG_SHIFT)) & SIM_SCGC5_WDOG_MASK)

#define SIM_SCGC5_XBAR_MASK                      (0x200000U)
#define SIM_SCGC5_XBAR_SHIFT                     (21U)
/*! XBAR - Peripheral Crossbar Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_XBAR(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_XBAR_SHIFT)) & SIM_SCGC5_XBAR_MASK)

#define SIM_SCGC5_TMR0_MASK                      (0x800000U)
#define SIM_SCGC5_TMR0_SHIFT                     (23U)
/*! TMR0 - Quadtimer0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_TMR0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_TMR0_SHIFT)) & SIM_SCGC5_TMR0_MASK)

#define SIM_SCGC5_TMR1_MASK                      (0x1000000U)
#define SIM_SCGC5_TMR1_SHIFT                     (24U)
/*! TMR1 - Quadtimer1 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_TMR1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_TMR1_SHIFT)) & SIM_SCGC5_TMR1_MASK)

#define SIM_SCGC5_TMR2_MASK                      (0x2000000U)
#define SIM_SCGC5_TMR2_SHIFT                     (25U)
/*! TMR2 - Quadtimer2 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_TMR2(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_TMR2_SHIFT)) & SIM_SCGC5_TMR2_MASK)

#define SIM_SCGC5_TMR3_MASK                      (0x4000000U)
#define SIM_SCGC5_TMR3_SHIFT                     (26U)
/*! TMR3 - Quadtimer3 Clock Gate Control
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

#define SIM_SCGC6_DMAMUX0_MASK                   (0x2U)
#define SIM_SCGC6_DMAMUX0_SHIFT                  (1U)
/*! DMAMUX0 - DMA MUX0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_DMAMUX0(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DMAMUX0_SHIFT)) & SIM_SCGC6_DMAMUX0_MASK)

#define SIM_SCGC6_DMAMUX1_MASK                   (0x4U)
#define SIM_SCGC6_DMAMUX1_SHIFT                  (2U)
/*! DMAMUX1 - DMA MUX1 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_DMAMUX1(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DMAMUX1_SHIFT)) & SIM_SCGC6_DMAMUX1_MASK)

#define SIM_SCGC6_DMAMUX2_MASK                   (0x8U)
#define SIM_SCGC6_DMAMUX2_SHIFT                  (3U)
/*! DMAMUX2 - DMA MUX2 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_DMAMUX2(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DMAMUX2_SHIFT)) & SIM_SCGC6_DMAMUX2_MASK)

#define SIM_SCGC6_DMAMUX3_MASK                   (0x10U)
#define SIM_SCGC6_DMAMUX3_SHIFT                  (4U)
/*! DMAMUX3 - DMA MUX3 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_DMAMUX3(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DMAMUX3_SHIFT)) & SIM_SCGC6_DMAMUX3_MASK)

#define SIM_SCGC6_RNGA_MASK                      (0x200U)
#define SIM_SCGC6_RNGA_SHIFT                     (9U)
/*! RNGA - RNGA Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_RNGA(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_RNGA_SHIFT)) & SIM_SCGC6_RNGA_MASK)

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

#define SIM_SCGC6_LPTMR_MASK                     (0x10000000U)
#define SIM_SCGC6_LPTMR_SHIFT                    (28U)
/*! LPTMR - LPTMR Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_LPTMR(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_LPTMR_SHIFT)) & SIM_SCGC6_LPTMR_MASK)

#define SIM_SCGC6_SIM_LP_MASK                    (0x40000000U)
#define SIM_SCGC6_SIM_LP_SHIFT                   (30U)
/*! SIM_LP - SIM_LP Clock Gate Control
 *  0b0..Clock is disabled
 *  0b1..Clock is enabled
 */
#define SIM_SCGC6_SIM_LP(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_SIM_LP_SHIFT)) & SIM_SCGC6_SIM_LP_MASK)

#define SIM_SCGC6_SIM_HP_MASK                    (0x80000000U)
#define SIM_SCGC6_SIM_HP_SHIFT                   (31U)
/*! SIM_HP - SIM_HP Clock Gate Control
 *  0b1..Clock is always enabled to SIM
 */
#define SIM_SCGC6_SIM_HP(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_SIM_HP_SHIFT)) & SIM_SCGC6_SIM_HP_MASK)
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
/*! @} */

/*! @name CLKDIV1 - System Clock Divider Register 1 */
/*! @{ */

#define SIM_CLKDIV1_SYSCLKMODE_MASK              (0x8000000U)
#define SIM_CLKDIV1_SYSCLKMODE_SHIFT             (27U)
/*! SYSCLKMODE - System Clock Mode
 *  0b0..1:1:1
 *  0b1..2:1:1
 */
#define SIM_CLKDIV1_SYSCLKMODE(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_SYSCLKMODE_SHIFT)) & SIM_CLKDIV1_SYSCLKMODE_MASK)

#define SIM_CLKDIV1_SYSDIV_MASK                  (0xF0000000U)
#define SIM_CLKDIV1_SYSDIV_SHIFT                 (28U)
/*! SYSDIV - System Clock divider
 *  0b0000..Divide by 1
 *  0b0001..Divide by 2
 *  0b0010..Divide by 3
 *  0b0011..Divide by 4 and so on..... If FOPT[0] is 0, the divider is set to div-by-8 after system reset is
 *          deasserted (after completion of system initialization sequence)
 */
#define SIM_CLKDIV1_SYSDIV(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_SYSDIV_SHIFT)) & SIM_CLKDIV1_SYSDIV_MASK)
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
 *  0b0101..64 KB of program flash memory, 2 KB protection region
 *  0b0110..Reserved
 *  0b0111..128 KB of program flash memory, 4 KB protection region
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1111..(Default)
 */
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_PFSIZE_SHIFT)) & SIM_FCFG1_PFSIZE_MASK)
/*! @} */

/*! @name FCFG2 - Flash Configuration Register 2 */
/*! @{ */

#define SIM_FCFG2_MAXADDR_MASK                   (0x7F000000U)
#define SIM_FCFG2_MAXADDR_SHIFT                  (24U)
/*! MAXADDR - Max address block */
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

#define SIM_MISC_CTL_XBARAFEMODOUTSEL_MASK       (0x3U)
#define SIM_MISC_CTL_XBARAFEMODOUTSEL_SHIFT      (0U)
/*! XBARAFEMODOUTSEL - XBAR AFE Modulator Output Select
 *  0b00..Sigma Delta Modulator 0 data output
 *  0b01..Sigma Delta Modulator 1 data output
 *  0b10..Sigma Delta Modulator 2 data output
 *  0b11..Sigma Delta Modulator 3 data output
 */
#define SIM_MISC_CTL_XBARAFEMODOUTSEL(x)         (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_XBARAFEMODOUTSEL_SHIFT)) & SIM_MISC_CTL_XBARAFEMODOUTSEL_MASK)

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
/*! AFECLKSEL - AFE Clock Source Select
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
 *  0b0..TypeA (ORed) Modulation selected for IRDA
 *  0b1..TypeB (ANDed) Modulation selected for IRDA
 */
#define SIM_MISC_CTL_UARTMODTYPE(x)              (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_UARTMODTYPE_SHIFT)) & SIM_MISC_CTL_UARTMODTYPE_MASK)

#define SIM_MISC_CTL_UART0IRSEL_MASK             (0x100U)
#define SIM_MISC_CTL_UART0IRSEL_SHIFT            (8U)
/*! UART0IRSEL - UART0 IRDA Select
 *  0b0..Pad RX input (PTD[0] or PTF[3], as selected in Pinmux control) selected for RX input of UART0 and UART0 TX signal is not used for modulation
 *  0b1..UART0 selected for IRDA modulation. UART0 TX modulated by XBAR_OUT[14] and UART0 RX input connected to XBAR_OUT[13]
 */
#define SIM_MISC_CTL_UART0IRSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_UART0IRSEL_SHIFT)) & SIM_MISC_CTL_UART0IRSEL_MASK)

#define SIM_MISC_CTL_UART1IRSEL_MASK             (0x200U)
#define SIM_MISC_CTL_UART1IRSEL_SHIFT            (9U)
/*! UART1IRSEL - UART1 IRDA Select
 *  0b0..Pad RX input (PTD[2] or PTI[0], as selected in Pinmux control) selected for RX input of UART1 and UART1 TX signal is not used for modulation
 *  0b1..UART1 selected for IRDA modulation. UART1 TX modulated by XBAR_OUT[14] and UART1 RX input connected to XBAR_OUT[13]
 */
#define SIM_MISC_CTL_UART1IRSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_UART1IRSEL_SHIFT)) & SIM_MISC_CTL_UART1IRSEL_MASK)

#define SIM_MISC_CTL_UART2IRSEL_MASK             (0x400U)
#define SIM_MISC_CTL_UART2IRSEL_SHIFT            (10U)
/*! UART2IRSEL - UART2 IRDA Select
 *  0b0..Pad RX input PTE[6] selected for RX input of UART2 and UART2 TX signal is not used for modulation
 *  0b1..UART2 selected for IRDA modulation. UART2 TX modulated by XBAR_OUT[14] and UART2 RX input connected to XBAR_OUT[13].
 */
#define SIM_MISC_CTL_UART2IRSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_UART2IRSEL_SHIFT)) & SIM_MISC_CTL_UART2IRSEL_MASK)

#define SIM_MISC_CTL_UART3IRSEL_MASK             (0x800U)
#define SIM_MISC_CTL_UART3IRSEL_SHIFT            (11U)
/*! UART3IRSEL - UART3 IRDA Select
 *  0b0..Pad RX input (PTC[3] or PTD[7], as selected in Pinmux control) selected for RX input of UART3 and UART3 TX signal is not used for modulation
 *  0b1..UART3 selected for IRDA modulation. UART3 TX modulated by XBAR_OUT[14] and UART3 RX input connected to XBAR_OUT[13].
 */
#define SIM_MISC_CTL_UART3IRSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_UART3IRSEL_SHIFT)) & SIM_MISC_CTL_UART3IRSEL_MASK)

#define SIM_MISC_CTL_XBARPITOUTSEL_MASK          (0x3000U)
#define SIM_MISC_CTL_XBARPITOUTSEL_SHIFT         (12U)
/*! XBARPITOUTSEL - XBAR PIT Output select
 *  0b00..PIT0[0] (default)
 *  0b01..PIT0[1]
 *  0b10..PIT1[0]
 *  0b11..PIT1[1]
 */
#define SIM_MISC_CTL_XBARPITOUTSEL(x)            (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_XBARPITOUTSEL_SHIFT)) & SIM_MISC_CTL_XBARPITOUTSEL_MASK)

#define SIM_MISC_CTL_EWMINSEL_MASK               (0x4000U)
#define SIM_MISC_CTL_EWMINSEL_SHIFT              (14U)
/*! EWMINSEL - External Watchdog Monitor Input Select
 *  0b0..Input from PAD (PTE[2] or PTE[4] as selected from Pinmux control )
 *  0b1..Peripheral Crossbar (XBAR) Output[32]
 */
#define SIM_MISC_CTL_EWMINSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_EWMINSEL_SHIFT)) & SIM_MISC_CTL_EWMINSEL_MASK)

#define SIM_MISC_CTL_TMR0PLLCLKSEL_MASK          (0x8000U)
#define SIM_MISC_CTL_TMR0PLLCLKSEL_SHIFT         (15U)
/*! TMR0PLLCLKSEL - Timer CH0 PLL clock select
 *  0b0..Selects Bus Clock as source for the Timer CH0
 *  0b1..Selects the PLL_AFE clock as the source for Timer CH0. The PLL_AFE clock source is itself selected using the MISC_CTL[5:4]
 */
#define SIM_MISC_CTL_TMR0PLLCLKSEL(x)            (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR0PLLCLKSEL_SHIFT)) & SIM_MISC_CTL_TMR0PLLCLKSEL_MASK)

#define SIM_MISC_CTL_TMR0SCSSEL_MASK             (0x10000U)
#define SIM_MISC_CTL_TMR0SCSSEL_SHIFT            (16U)
/*! TMR0SCSSEL - Quadtimer Channel0 Secondary Count Source Select
 *  0b0..Pad PTF1 or PTD5, depending upon PCTL configuration.
 *  0b1..Peripheral Crossbar (XBAR) Output[5]
 */
#define SIM_MISC_CTL_TMR0SCSSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR0SCSSEL_SHIFT)) & SIM_MISC_CTL_TMR0SCSSEL_MASK)

#define SIM_MISC_CTL_TMR1SCSSEL_MASK             (0x20000U)
#define SIM_MISC_CTL_TMR1SCSSEL_SHIFT            (17U)
/*! TMR1SCSSEL - Quadtimer Channel1 Secondary Count Source Select
 *  0b0..Pad PTG0 or PTC6, depending upon PCTL configuration.
 *  0b1..Peripheral Crossbar (XBAR) Output[6]
 */
#define SIM_MISC_CTL_TMR1SCSSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR1SCSSEL_SHIFT)) & SIM_MISC_CTL_TMR1SCSSEL_MASK)

#define SIM_MISC_CTL_TMR2SCSSEL_MASK             (0x40000U)
#define SIM_MISC_CTL_TMR2SCSSEL_SHIFT            (18U)
/*! TMR2SCSSEL - Quadtimer Channel2 Secondary Count Source Select
 *  0b0..Pad PTF7 or PTF0, depending upon PCTL configuration.
 *  0b1..Peripheral Crossbar (XBAR) Output[7]
 */
#define SIM_MISC_CTL_TMR2SCSSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR2SCSSEL_SHIFT)) & SIM_MISC_CTL_TMR2SCSSEL_MASK)

#define SIM_MISC_CTL_TMR3SCSSEL_MASK             (0x80000U)
#define SIM_MISC_CTL_TMR3SCSSEL_SHIFT            (19U)
/*! TMR3SCSSEL - Quadtimer Channel3 Secondary Count Source Select
 *  0b0..Pad PTE5 or PTD1, depending upon PCTL configuration.
 *  0b1..Peripheral Crossbar (XBAR) Output[8]
 */
#define SIM_MISC_CTL_TMR3SCSSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISC_CTL_TMR3SCSSEL_SHIFT)) & SIM_MISC_CTL_TMR3SCSSEL_MASK)

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
 *  0b1..32K IRC Clock selected
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

