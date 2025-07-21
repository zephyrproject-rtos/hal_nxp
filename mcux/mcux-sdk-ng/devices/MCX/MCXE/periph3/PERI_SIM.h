/*
** ###################################################################
**     Processors:          MCXE245VLF
**                          MCXE245VLH
**                          MCXE245VLL
**
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250610
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
**     - rev. 1.0 (2025-02-21)
**         Generated based on Rev1 Draft RM..
**
** ###################################################################
*/

/*!
 * @file PERI_SIM.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for SIM
 *
 * CMSIS Peripheral Access Layer for SIM
 */

#if !defined(PERI_SIM_H_)
#define PERI_SIM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE245VLF) || defined(CPU_MCXE245VLH) || defined(CPU_MCXE245VLL))
#include "MCXE245_COMMON.h"
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
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t CHIPCTL;                           /**< Chip Control register, offset: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t FTMOPT0;                           /**< FTM Option Register 0, offset: 0xC */
  __IO uint32_t LPOCLKS;                           /**< LPO Clock Select Register, offset: 0x10 */
       uint8_t RESERVED_2[4];
  __IO uint32_t ADCOPT;                            /**< ADC Options Register, offset: 0x18 */
  __IO uint32_t FTMOPT1;                           /**< FTM Option Register 1, offset: 0x1C */
  __IO uint32_t MISCTRL0;                          /**< Miscellaneous control register 0, offset: 0x20 */
  __I  uint32_t SDID;                              /**< System Device Identification Register, offset: 0x24 */
       uint8_t RESERVED_3[24];
  __IO uint32_t PLATCGC;                           /**< Platform Clock Gating Control Register, offset: 0x40 */
       uint8_t RESERVED_4[8];
  __I  uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x4C */
       uint8_t RESERVED_5[4];
  __I  uint32_t UIDH;                              /**< Unique Identification Register High, offset: 0x54 */
  __I  uint32_t UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x58 */
  __I  uint32_t UIDML;                             /**< Unique Identification Register Mid Low, offset: 0x5C */
  __I  uint32_t UIDL;                              /**< Unique Identification Register Low, offset: 0x60 */
       uint8_t RESERVED_6[4];
  __IO uint32_t CLKDIV4;                           /**< System Clock Divider Register 4, offset: 0x68 */
  __IO uint32_t MISCTRL1;                          /**< Miscellaneous Control register 1, offset: 0x6C */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/*! @name CHIPCTL - Chip Control register */
/*! @{ */

#define SIM_CHIPCTL_ADC_INTERLEAVE_EN_MASK       (0xFU)
#define SIM_CHIPCTL_ADC_INTERLEAVE_EN_SHIFT      (0U)
/*! ADC_INTERLEAVE_EN - ADC interleave channel enable
 *  0b0000..Interleaving disabled. No channel pair interleaved. Interleaved channels are individually connected to
 *          pins. PTC0 is connected to ADC0_SE8. PTC1 is connected to ADC0_SE9. PTB15 is connected to ADC1_SE14.
 *          PTB16 is connected to ADC1_SE15. PTB0 is connected to ADC0_SE4. PTB1 is connected to ADC0_SE5. PTB13 is
 *          connected to ADC1_SE8. PTB14 is connected to ADC1_SE9.
 *  0b1xxx..PTB14 to ADC1_SE9 and ADC0_SE9
 *  0bx1xx..PTB13 to ADC1_SE8 and ADC0_SE8
 *  0bxx1x..PTB1 to ADC0_SE5 and ADC1_SE15
 *  0bxxx1..PTB0 to ADC0_SE4 and ADC1_SE14
 */
#define SIM_CHIPCTL_ADC_INTERLEAVE_EN(x)         (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_ADC_INTERLEAVE_EN_SHIFT)) & SIM_CHIPCTL_ADC_INTERLEAVE_EN_MASK)

#define SIM_CHIPCTL_CLKOUTSEL_MASK               (0xF0U)
#define SIM_CHIPCTL_CLKOUTSEL_SHIFT              (4U)
/*! CLKOUTSEL - CLKOUT Select
 *  0b0000..SCG_CLKOUT
 *  0b0001..Reserved
 *  0b0010..SOSCDIV2_CLK
 *  0b0011..Reserved
 *  0b0100..SIRCDIV2_CLK
 *  0b0101..For MCXE247: QSPI_SFIF_CLK_HYP_PREMUX: Divide by 2 clock (configured through SCLKCONFIG[5]) for
 *          HyperRAM going to sfif clock to QSPI; For others: Reserved
 *  0b0110..FIRCDIV2_CLK
 *  0b0111..HCLK
 *  0b1000..For MCXE24x: SPLLDIV2_CLK
 *  0b1001..BUS_CLK
 *  0b1010..LPO128K_CLK
 *  0b1011..For MCXE247: QSPI_Module clock; For others: Reserved
 *  0b1100..LPO_CLK as selected by LPOCLKS[LPOCLKSEL]
 *  0b1101..For MCXE247: QSPI_SFIF_CLK; For others: Reserved
 *  0b1110..RTC_CLK as selected by LPOCLKS[RTCCLKSEL]
 *  0b1111..For MCXE247: QSPI_2xSFIF_CLK; For others: Reserved
 */
#define SIM_CHIPCTL_CLKOUTSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_CLKOUTSEL_SHIFT)) & SIM_CHIPCTL_CLKOUTSEL_MASK)

#define SIM_CHIPCTL_CLKOUTDIV_MASK               (0x700U)
#define SIM_CHIPCTL_CLKOUTDIV_SHIFT              (8U)
/*! CLKOUTDIV - CLKOUT Divide Ratio
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define SIM_CHIPCTL_CLKOUTDIV(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_CLKOUTDIV_SHIFT)) & SIM_CHIPCTL_CLKOUTDIV_MASK)

#define SIM_CHIPCTL_CLKOUTEN_MASK                (0x800U)
#define SIM_CHIPCTL_CLKOUTEN_SHIFT               (11U)
/*! CLKOUTEN - CLKOUT enable
 *  0b0..Clockout disable
 *  0b1..Clockout enable
 */
#define SIM_CHIPCTL_CLKOUTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_CLKOUTEN_SHIFT)) & SIM_CHIPCTL_CLKOUTEN_MASK)

#define SIM_CHIPCTL_TRACECLK_SEL_MASK            (0x1000U)
#define SIM_CHIPCTL_TRACECLK_SEL_SHIFT           (12U)
/*! TRACECLK_SEL - Debug trace clock select
 *  0b0..Core clock
 *  0b1..Reserved
 */
#define SIM_CHIPCTL_TRACECLK_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_TRACECLK_SEL_SHIFT)) & SIM_CHIPCTL_TRACECLK_SEL_MASK)

#define SIM_CHIPCTL_PDB_BB_SEL_MASK              (0x2000U)
#define SIM_CHIPCTL_PDB_BB_SEL_SHIFT             (13U)
/*! PDB_BB_SEL - PDB back-to-back select
 *  0b0..PDB0 channel 0 back-to-back operation with ADC0 COCO[7:0] and PDB1 channel 0 back-to-back operation with ADC1 COCO[7:0]
 *  0b1..Channel 0 of PDB0 and PDB1 back-to-back operation with COCO[7:0] of ADC0 and ADC1.
 */
#define SIM_CHIPCTL_PDB_BB_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_PDB_BB_SEL_SHIFT)) & SIM_CHIPCTL_PDB_BB_SEL_MASK)

#define SIM_CHIPCTL_ADC_SUPPLY_MASK              (0x70000U)
#define SIM_CHIPCTL_ADC_SUPPLY_SHIFT             (16U)
/*! ADC_SUPPLY - ADC_SUPPLY
 *  0b000..5 V input VDD supply (VDD)
 *  0b001..5 V input analog supply (VDDA)
 *  0b010..ADC Reference Supply (VREFH)
 *  0b011..3.3 V Oscillator Regulator Output (VDD_3V)
 *  0b100..3.3 V flash regulator output (VDD_flash_3V)
 *  0b101..1.2 V core regulator output (VDD_LV)
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define SIM_CHIPCTL_ADC_SUPPLY(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_ADC_SUPPLY_SHIFT)) & SIM_CHIPCTL_ADC_SUPPLY_MASK)

#define SIM_CHIPCTL_ADC_SUPPLYEN_MASK            (0x80000U)
#define SIM_CHIPCTL_ADC_SUPPLYEN_SHIFT           (19U)
/*! ADC_SUPPLYEN - ADC_SUPPLYEN
 *  0b0..Disable internal supply monitoring
 *  0b1..Enable internal supply monitoring
 */
#define SIM_CHIPCTL_ADC_SUPPLYEN(x)              (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_ADC_SUPPLYEN_SHIFT)) & SIM_CHIPCTL_ADC_SUPPLYEN_MASK)

#define SIM_CHIPCTL_SRAMU_RETEN_MASK             (0x100000U)
#define SIM_CHIPCTL_SRAMU_RETEN_SHIFT            (20U)
/*! SRAMU_RETEN - SRAMU_RETEN
 *  0b0..SRAMU contents are retained across resets
 *  0b1..No SRAMU retention
 */
#define SIM_CHIPCTL_SRAMU_RETEN(x)               (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_SRAMU_RETEN_SHIFT)) & SIM_CHIPCTL_SRAMU_RETEN_MASK)

#define SIM_CHIPCTL_SRAML_RETEN_MASK             (0x200000U)
#define SIM_CHIPCTL_SRAML_RETEN_SHIFT            (21U)
/*! SRAML_RETEN - SRAML_RETEN
 *  0b0..SRAML contents are retained across resets
 *  0b1..No SRAML retention
 */
#define SIM_CHIPCTL_SRAML_RETEN(x)               (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_SRAML_RETEN_SHIFT)) & SIM_CHIPCTL_SRAML_RETEN_MASK)
/*! @} */

/*! @name FTMOPT0 - FTM Option Register 0 */
/*! @{ */

#define SIM_FTMOPT0_FTM0FLTXSEL_MASK             (0x7U)
#define SIM_FTMOPT0_FTM0FLTXSEL_SHIFT            (0U)
/*! FTM0FLTxSEL - FTM0 Fault X Select
 *  0b000..FTM0_FLTx pin
 *  0b001..TRGMUX_FTM0 out
 */
#define SIM_FTMOPT0_FTM0FLTXSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT0_FTM0FLTXSEL_SHIFT)) & SIM_FTMOPT0_FTM0FLTXSEL_MASK)

#define SIM_FTMOPT0_FTM1FLTXSEL_MASK             (0x70U)
#define SIM_FTMOPT0_FTM1FLTXSEL_SHIFT            (4U)
/*! FTM1FLTxSEL - FTM1 Fault X Select
 *  0b000..FTM1_FLTx pin
 *  0b001..TRGMUX_FTM1 out
 */
#define SIM_FTMOPT0_FTM1FLTXSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT0_FTM1FLTXSEL_SHIFT)) & SIM_FTMOPT0_FTM1FLTXSEL_MASK)

#define SIM_FTMOPT0_FTM2FLTXSEL_MASK             (0x700U)
#define SIM_FTMOPT0_FTM2FLTXSEL_SHIFT            (8U)
/*! FTM2FLTxSEL - FTM2 Fault X Select
 *  0b000..FTM2_FLTx pin
 *  0b001..TRGMUX_FTM2 out
 */
#define SIM_FTMOPT0_FTM2FLTXSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT0_FTM2FLTXSEL_SHIFT)) & SIM_FTMOPT0_FTM2FLTXSEL_MASK)

#define SIM_FTMOPT0_FTM3FLTXSEL_MASK             (0x7000U)
#define SIM_FTMOPT0_FTM3FLTXSEL_SHIFT            (12U)
/*! FTM3FLTxSEL - FTM3 Fault X Select
 *  0b000..FTM3_FLTx pin
 *  0b001..TRGMUX_FTM3 out
 */
#define SIM_FTMOPT0_FTM3FLTXSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT0_FTM3FLTXSEL_SHIFT)) & SIM_FTMOPT0_FTM3FLTXSEL_MASK)

#define SIM_FTMOPT0_FTM0CLKSEL_MASK              (0x3000000U)
#define SIM_FTMOPT0_FTM0CLKSEL_SHIFT             (24U)
/*! FTM0CLKSEL - FTM0 External Clock Pin Select
 *  0b00..FTM0 external clock driven by TCLK0 pin.
 *  0b01..FTM0 external clock driven by TCLK1 pin.
 *  0b10..FTM0 external clock driven by TCLK2 pin.
 *  0b11..No clock input
 */
#define SIM_FTMOPT0_FTM0CLKSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT0_FTM0CLKSEL_SHIFT)) & SIM_FTMOPT0_FTM0CLKSEL_MASK)

#define SIM_FTMOPT0_FTM1CLKSEL_MASK              (0xC000000U)
#define SIM_FTMOPT0_FTM1CLKSEL_SHIFT             (26U)
/*! FTM1CLKSEL - FTM1 External Clock Pin Select
 *  0b00..FTM1 external clock driven by TCLK0 pin.
 *  0b01..FTM1 external clock driven by TCLK1 pin.
 *  0b10..FTM1 external clock driven by TCLK2 pin.
 *  0b11..No clock input
 */
#define SIM_FTMOPT0_FTM1CLKSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT0_FTM1CLKSEL_SHIFT)) & SIM_FTMOPT0_FTM1CLKSEL_MASK)

#define SIM_FTMOPT0_FTM2CLKSEL_MASK              (0x30000000U)
#define SIM_FTMOPT0_FTM2CLKSEL_SHIFT             (28U)
/*! FTM2CLKSEL - FTM2 External Clock Pin Select
 *  0b00..FTM2 external clock driven by TCLK0 pin.
 *  0b01..FTM2 external clock driven by TCLK1 pin.
 *  0b10..FTM2 external clock driven by TCLK2 pin.
 *  0b11..No clock input
 */
#define SIM_FTMOPT0_FTM2CLKSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT0_FTM2CLKSEL_SHIFT)) & SIM_FTMOPT0_FTM2CLKSEL_MASK)

#define SIM_FTMOPT0_FTM3CLKSEL_MASK              (0xC0000000U)
#define SIM_FTMOPT0_FTM3CLKSEL_SHIFT             (30U)
/*! FTM3CLKSEL - FTM3 External Clock Pin Select
 *  0b00..FTM3 external clock driven by TCLK0 pin.
 *  0b01..FTM3 external clock driven by TCLK1 pin.
 *  0b10..FTM3 external clock driven by TCLK2 pin.
 *  0b11..No clock input
 */
#define SIM_FTMOPT0_FTM3CLKSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT0_FTM3CLKSEL_SHIFT)) & SIM_FTMOPT0_FTM3CLKSEL_MASK)
/*! @} */

/*! @name LPOCLKS - LPO Clock Select Register */
/*! @{ */

#define SIM_LPOCLKS_LPO1KCLKEN_MASK              (0x1U)
#define SIM_LPOCLKS_LPO1KCLKEN_SHIFT             (0U)
/*! LPO1KCLKEN - LPO1K_CLK enable
 *  0b0..Disable LPO1K_CLK output
 *  0b1..Enable LPO1K_CLK output
 */
#define SIM_LPOCLKS_LPO1KCLKEN(x)                (((uint32_t)(((uint32_t)(x)) << SIM_LPOCLKS_LPO1KCLKEN_SHIFT)) & SIM_LPOCLKS_LPO1KCLKEN_MASK)

#define SIM_LPOCLKS_LPO32KCLKEN_MASK             (0x2U)
#define SIM_LPOCLKS_LPO32KCLKEN_SHIFT            (1U)
/*! LPO32KCLKEN - LPO32K_CLK enable
 *  0b0..Disable LPO32K_CLK output
 *  0b1..Enable LPO32K_CLK output
 */
#define SIM_LPOCLKS_LPO32KCLKEN(x)               (((uint32_t)(((uint32_t)(x)) << SIM_LPOCLKS_LPO32KCLKEN_SHIFT)) & SIM_LPOCLKS_LPO32KCLKEN_MASK)

#define SIM_LPOCLKS_LPOCLKSEL_MASK               (0xCU)
#define SIM_LPOCLKS_LPOCLKSEL_SHIFT              (2U)
/*! LPOCLKSEL - LPO clock source select
 *  0b00..LPO128K_CLK
 *  0b01..No clock
 *  0b10..LPO32K_CLK which is derived from the LPO128K_CLK
 *  0b11..LPO1K_CLK which is derived from the LPO128K_CLK
 */
#define SIM_LPOCLKS_LPOCLKSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_LPOCLKS_LPOCLKSEL_SHIFT)) & SIM_LPOCLKS_LPOCLKSEL_MASK)

#define SIM_LPOCLKS_RTCCLKSEL_MASK               (0x30U)
#define SIM_LPOCLKS_RTCCLKSEL_SHIFT              (4U)
/*! RTCCLKSEL - 32 kHz clock source select
 *  0b00..SOSCDIV1_CLK
 *  0b01..LPO32K_CLK
 *  0b10..32 kHz RTC_CLKIN clock
 *  0b11..FIRCDIV1_CLK
 */
#define SIM_LPOCLKS_RTCCLKSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_LPOCLKS_RTCCLKSEL_SHIFT)) & SIM_LPOCLKS_RTCCLKSEL_MASK)
/*! @} */

/*! @name ADCOPT - ADC Options Register */
/*! @{ */

#define SIM_ADCOPT_ADC0TRGSEL_MASK               (0x1U)
#define SIM_ADCOPT_ADC0TRGSEL_SHIFT              (0U)
/*! ADC0TRGSEL - ADC0 trigger source select
 *  0b0..PDB output
 *  0b1..TRGMUX output
 */
#define SIM_ADCOPT_ADC0TRGSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_ADCOPT_ADC0TRGSEL_SHIFT)) & SIM_ADCOPT_ADC0TRGSEL_MASK)

#define SIM_ADCOPT_ADC0SWPRETRG_MASK             (0xEU)
#define SIM_ADCOPT_ADC0SWPRETRG_SHIFT            (1U)
/*! ADC0SWPRETRG - ADC0 software pretrigger sources
 *  0b000..Software pretrigger disabled
 *  0b001..Reserved (do not use)
 *  0b010..Reserved (do not use)
 *  0b011..Reserved (do not use)
 *  0b100..Software pretrigger 0
 *  0b101..Software pretrigger 1
 *  0b110..Software pretrigger 2
 *  0b111..Software pretrigger 3
 */
#define SIM_ADCOPT_ADC0SWPRETRG(x)               (((uint32_t)(((uint32_t)(x)) << SIM_ADCOPT_ADC0SWPRETRG_SHIFT)) & SIM_ADCOPT_ADC0SWPRETRG_MASK)

#define SIM_ADCOPT_ADC0PRETRGSEL_MASK            (0x30U)
#define SIM_ADCOPT_ADC0PRETRGSEL_SHIFT           (4U)
/*! ADC0PRETRGSEL - ADC0 pretrigger source select
 *  0b00..PDB pretrigger (default)
 *  0b01..TRGMUX pretrigger
 *  0b10..Software pretrigger
 *  0b11..Reserved
 */
#define SIM_ADCOPT_ADC0PRETRGSEL(x)              (((uint32_t)(((uint32_t)(x)) << SIM_ADCOPT_ADC0PRETRGSEL_SHIFT)) & SIM_ADCOPT_ADC0PRETRGSEL_MASK)

#define SIM_ADCOPT_ADC1TRGSEL_MASK               (0x100U)
#define SIM_ADCOPT_ADC1TRGSEL_SHIFT              (8U)
/*! ADC1TRGSEL - ADC1 trigger source select
 *  0b0..PDB output
 *  0b1..TRGMUX output
 */
#define SIM_ADCOPT_ADC1TRGSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_ADCOPT_ADC1TRGSEL_SHIFT)) & SIM_ADCOPT_ADC1TRGSEL_MASK)

#define SIM_ADCOPT_ADC1SWPRETRG_MASK             (0xE00U)
#define SIM_ADCOPT_ADC1SWPRETRG_SHIFT            (9U)
/*! ADC1SWPRETRG - ADC1 software pretrigger sources
 *  0b000..Software pretrigger disabled
 *  0b001..Reserved (do not use)
 *  0b010..Reserved (do not use)
 *  0b011..Reserved (do not use)
 *  0b100..Software pretrigger 0
 *  0b101..Software pretrigger 1
 *  0b110..Software pretrigger 2
 *  0b111..Software pretrigger 3
 */
#define SIM_ADCOPT_ADC1SWPRETRG(x)               (((uint32_t)(((uint32_t)(x)) << SIM_ADCOPT_ADC1SWPRETRG_SHIFT)) & SIM_ADCOPT_ADC1SWPRETRG_MASK)

#define SIM_ADCOPT_ADC1PRETRGSEL_MASK            (0x3000U)
#define SIM_ADCOPT_ADC1PRETRGSEL_SHIFT           (12U)
/*! ADC1PRETRGSEL - ADC1 pretrigger source select
 *  0b00..PDB pretrigger (default)
 *  0b01..TRGMUX pretrigger
 *  0b10..Software pretrigger
 *  0b11..Reserved
 */
#define SIM_ADCOPT_ADC1PRETRGSEL(x)              (((uint32_t)(((uint32_t)(x)) << SIM_ADCOPT_ADC1PRETRGSEL_SHIFT)) & SIM_ADCOPT_ADC1PRETRGSEL_MASK)
/*! @} */

/*! @name FTMOPT1 - FTM Option Register 1 */
/*! @{ */

#define SIM_FTMOPT1_FTM0SYNCBIT_MASK             (0x1U)
#define SIM_FTMOPT1_FTM0SYNCBIT_SHIFT            (0U)
/*! FTM0SYNCBIT - FTM0 Sync Bit */
#define SIM_FTMOPT1_FTM0SYNCBIT(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM0SYNCBIT_SHIFT)) & SIM_FTMOPT1_FTM0SYNCBIT_MASK)

#define SIM_FTMOPT1_FTM1SYNCBIT_MASK             (0x2U)
#define SIM_FTMOPT1_FTM1SYNCBIT_SHIFT            (1U)
/*! FTM1SYNCBIT - FTM1 Sync Bit */
#define SIM_FTMOPT1_FTM1SYNCBIT(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM1SYNCBIT_SHIFT)) & SIM_FTMOPT1_FTM1SYNCBIT_MASK)

#define SIM_FTMOPT1_FTM2SYNCBIT_MASK             (0x4U)
#define SIM_FTMOPT1_FTM2SYNCBIT_SHIFT            (2U)
/*! FTM2SYNCBIT - FTM2 Sync Bit */
#define SIM_FTMOPT1_FTM2SYNCBIT(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM2SYNCBIT_SHIFT)) & SIM_FTMOPT1_FTM2SYNCBIT_MASK)

#define SIM_FTMOPT1_FTM3SYNCBIT_MASK             (0x8U)
#define SIM_FTMOPT1_FTM3SYNCBIT_SHIFT            (3U)
/*! FTM3SYNCBIT - FTM3 Sync Bit */
#define SIM_FTMOPT1_FTM3SYNCBIT(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM3SYNCBIT_SHIFT)) & SIM_FTMOPT1_FTM3SYNCBIT_MASK)

#define SIM_FTMOPT1_FTM1CH0SEL_MASK              (0x30U)
#define SIM_FTMOPT1_FTM1CH0SEL_SHIFT             (4U)
/*! FTM1CH0SEL - FTM1 CH0 Select
 *  0b00..FTM1_CH0 input
 *  0b01..CMP0 output
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define SIM_FTMOPT1_FTM1CH0SEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM1CH0SEL_SHIFT)) & SIM_FTMOPT1_FTM1CH0SEL_MASK)

#define SIM_FTMOPT1_FTM2CH0SEL_MASK              (0xC0U)
#define SIM_FTMOPT1_FTM2CH0SEL_SHIFT             (6U)
/*! FTM2CH0SEL - FTM2 CH0 Select
 *  0b00..FTM2_CH0 input
 *  0b01..CMP0 output
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define SIM_FTMOPT1_FTM2CH0SEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM2CH0SEL_SHIFT)) & SIM_FTMOPT1_FTM2CH0SEL_MASK)

#define SIM_FTMOPT1_FTM2CH1SEL_MASK              (0x100U)
#define SIM_FTMOPT1_FTM2CH1SEL_SHIFT             (8U)
/*! FTM2CH1SEL - FTM2 CH1 Select
 *  0b0..FTM2_CH1 input
 *  0b1..exclusive OR of FTM2_CH0,FTM2_CH1,and FTM1_CH1
 */
#define SIM_FTMOPT1_FTM2CH1SEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM2CH1SEL_SHIFT)) & SIM_FTMOPT1_FTM2CH1SEL_MASK)

#define SIM_FTMOPT1_FTMGLDOK_MASK                (0x8000U)
#define SIM_FTMOPT1_FTMGLDOK_SHIFT               (15U)
/*! FTMGLDOK - FTM global load enable
 *  0b0..FTM Global load mechanism disabled.
 *  0b1..FTM Global load mechanism enabled
 */
#define SIM_FTMOPT1_FTMGLDOK(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTMGLDOK_SHIFT)) & SIM_FTMOPT1_FTMGLDOK_MASK)

#define SIM_FTMOPT1_FTM0_OUTSEL_MASK             (0xFF0000U)
#define SIM_FTMOPT1_FTM0_OUTSEL_SHIFT            (16U)
/*! FTM0_OUTSEL - FTM0 channel modulation select with FTM1_CH1
 *  0b00000000..No modulation with FTM1_CH1
 *  0b00000001..Modulation with FTM1_CH1
 */
#define SIM_FTMOPT1_FTM0_OUTSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM0_OUTSEL_SHIFT)) & SIM_FTMOPT1_FTM0_OUTSEL_MASK)

#define SIM_FTMOPT1_FTM3_OUTSEL_MASK             (0xFF000000U)
#define SIM_FTMOPT1_FTM3_OUTSEL_SHIFT            (24U)
/*! FTM3_OUTSEL - FTM3 channel modulation select with FTM2_CH1
 *  0b00000000..No modulation with FTM2_CH1
 *  0b00000001..Modulation with FTM2_CH1
 */
#define SIM_FTMOPT1_FTM3_OUTSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM3_OUTSEL_SHIFT)) & SIM_FTMOPT1_FTM3_OUTSEL_MASK)
/*! @} */

/*! @name MISCTRL0 - Miscellaneous control register 0 */
/*! @{ */

#define SIM_MISCTRL0_STOP1_MONITOR_MASK          (0x200U)
#define SIM_MISCTRL0_STOP1_MONITOR_SHIFT         (9U)
/*! STOP1_MONITOR - STOP1 monitor bit
 *  0b0..Bus clock enabled or STOP1 entry aborted
 *  0b1..STOP1 entry successful
 */
#define SIM_MISCTRL0_STOP1_MONITOR(x)            (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL0_STOP1_MONITOR_SHIFT)) & SIM_MISCTRL0_STOP1_MONITOR_MASK)

#define SIM_MISCTRL0_STOP2_MONITOR_MASK          (0x400U)
#define SIM_MISCTRL0_STOP2_MONITOR_SHIFT         (10U)
/*! STOP2_MONITOR - STOP2 monitor bit
 *  0b0..System clock enabled or STOP2 entry aborted
 *  0b1..STOP2 entry successful
 */
#define SIM_MISCTRL0_STOP2_MONITOR(x)            (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL0_STOP2_MONITOR_SHIFT)) & SIM_MISCTRL0_STOP2_MONITOR_MASK)

#define SIM_MISCTRL0_FTM0_OBE_CTRL_MASK          (0x10000U)
#define SIM_MISCTRL0_FTM0_OBE_CTRL_SHIFT         (16U)
/*! FTM0_OBE_CTRL - FTM0 OBE CTRL bit
 *  0b0..The FTM channel output is put to safe state when the FTM counter is enabled and the FTM channel output is
 *       enabled by Fault Control (FTM.MODE[FAULTM]!=2'b00 and FTM.FLTCTRL[FSTATE]=1'b0) and PWM is enabled
 *       (FTM.SC[PWMENn] = 1'b1). Otherwise the channel output is tristated.
 *  0b1..The FTM channel output state is retained when the channel is in output mode. The output channel is
 *       tristated when the channel is in input capture [DECAPEN=1'b0, COMBINE=1'b0, MSnB:MSnA=2'b00] or dual edge
 *       capture mode [DECAPEN=1'b1].
 */
#define SIM_MISCTRL0_FTM0_OBE_CTRL(x)            (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL0_FTM0_OBE_CTRL_SHIFT)) & SIM_MISCTRL0_FTM0_OBE_CTRL_MASK)

#define SIM_MISCTRL0_FTM1_OBE_CTRL_MASK          (0x20000U)
#define SIM_MISCTRL0_FTM1_OBE_CTRL_SHIFT         (17U)
/*! FTM1_OBE_CTRL - FTM1 OBE CTRL bit
 *  0b0..The FTM channel output is put to safe state when the FTM counter is enabled and the FTM channel output is
 *       enabled by Fault Control (FTM.MODE[FAULTM]!=2'b00 and FTM.FLTCTRL[FSTATE]=1'b0) and PWM is enabled
 *       (FTM.SC[PWMENn] = 1'b1). Otherwise the channel output is tristated.
 *  0b1..The FTM channel output state is retained when the channel is in output mode. The output channel is
 *       tristated when the channel is in input capture [DECAPEN=1'b0, COMBINE=1'b0, MSnB:MSnA=2'b00] or dual edge
 *       capture mode [DECAPEN=1'b1].
 */
#define SIM_MISCTRL0_FTM1_OBE_CTRL(x)            (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL0_FTM1_OBE_CTRL_SHIFT)) & SIM_MISCTRL0_FTM1_OBE_CTRL_MASK)

#define SIM_MISCTRL0_FTM2_OBE_CTRL_MASK          (0x40000U)
#define SIM_MISCTRL0_FTM2_OBE_CTRL_SHIFT         (18U)
/*! FTM2_OBE_CTRL - FTM2 OBE CTRL bit
 *  0b0..The FTM channel output is put to safe state when the FTM counter is enabled and the FTM channel output is
 *       enabled by Fault Control (FTM.MODE[FAULTM]!=2'b00 and FTM.FLTCTRL[FSTATE]=1'b0) and PWM is enabled
 *       (FTM.SC[PWMENn] = 1'b1). Otherwise the channel output is tristated.
 *  0b1..The FTM channel output state is retained when the channel is in output mode. The output channel is
 *       tristated when the channel is in input capture [DECAPEN=1'b0, COMBINE=1'b0, MSnB:MSnA=2'b00] or dual edge
 *       capture mode [DECAPEN=1'b1].
 */
#define SIM_MISCTRL0_FTM2_OBE_CTRL(x)            (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL0_FTM2_OBE_CTRL_SHIFT)) & SIM_MISCTRL0_FTM2_OBE_CTRL_MASK)

#define SIM_MISCTRL0_FTM3_OBE_CTRL_MASK          (0x80000U)
#define SIM_MISCTRL0_FTM3_OBE_CTRL_SHIFT         (19U)
/*! FTM3_OBE_CTRL - FTM3 OBE CTRL bit
 *  0b0..The FTM channel output is put to safe state when the FTM counter is enabled and the FTM channel output is
 *       enabled by Fault Control (FTM.MODE[FAULTM]!=2'b00 and FTM.FLTCTRL[FSTATE]=1'b0) and PWM is enabled
 *       (FTM.SC[PWMENn] = 1'b1). Otherwise the channel output is tristated.
 *  0b1..The FTM channel output state is retained when the channel is in output mode. The output channel is
 *       tristated when the channel is in input capture [DECAPEN=1'b0, COMBINE=1'b0, MSnB:MSnA=2'b00] or dual edge
 *       capture mode [DECAPEN=1'b1].
 */
#define SIM_MISCTRL0_FTM3_OBE_CTRL(x)            (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL0_FTM3_OBE_CTRL_SHIFT)) & SIM_MISCTRL0_FTM3_OBE_CTRL_MASK)
/*! @} */

/*! @name SDID - System Device Identification Register */
/*! @{ */

#define SIM_SDID_FEATURES_MASK                   (0xFFU)
#define SIM_SDID_FEATURES_SHIFT                  (0U)
/*! FEATURES - Features */
#define SIM_SDID_FEATURES(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_FEATURES_SHIFT)) & SIM_SDID_FEATURES_MASK)

#define SIM_SDID_PACKAGE_MASK                    (0xF00U)
#define SIM_SDID_PACKAGE_SHIFT                   (8U)
/*! PACKAGE - Package
 *  0b0000..Reserved
 *  0b0001..Reserved
 *  0b0010..48 LQFP
 *  0b0011..64 LQFP
 *  0b0100..100 LQFP
 *  0b0101..Reserved
 *  0b0110..144 LQFP
 *  0b0111..176 LQFP
 *  0b1000..100 MAP BGA
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define SIM_SDID_PACKAGE(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SDID_PACKAGE_SHIFT)) & SIM_SDID_PACKAGE_MASK)

#define SIM_SDID_REVID_MASK                      (0xF000U)
#define SIM_SDID_REVID_SHIFT                     (12U)
/*! REVID - Device revision number */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_REVID_SHIFT)) & SIM_SDID_REVID_MASK)

#define SIM_SDID_RAMSIZE_MASK                    (0xF0000U)
#define SIM_SDID_RAMSIZE_SHIFT                   (16U)
/*! RAMSIZE - RAM size */
#define SIM_SDID_RAMSIZE(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SDID_RAMSIZE_SHIFT)) & SIM_SDID_RAMSIZE_MASK)

#define SIM_SDID_DERIVATE_MASK                   (0xF00000U)
#define SIM_SDID_DERIVATE_SHIFT                  (20U)
/*! DERIVATE - Derivate */
#define SIM_SDID_DERIVATE(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_DERIVATE_SHIFT)) & SIM_SDID_DERIVATE_MASK)

#define SIM_SDID_SUBSERIES_MASK                  (0xF000000U)
#define SIM_SDID_SUBSERIES_SHIFT                 (24U)
/*! SUBSERIES - Subseries */
#define SIM_SDID_SUBSERIES(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SUBSERIES_SHIFT)) & SIM_SDID_SUBSERIES_MASK)

#define SIM_SDID_GENERATION_MASK                 (0xF0000000U)
#define SIM_SDID_GENERATION_SHIFT                (28U)
/*! GENERATION - MCXE24x product series generation */
#define SIM_SDID_GENERATION(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SDID_GENERATION_SHIFT)) & SIM_SDID_GENERATION_MASK)
/*! @} */

/*! @name PLATCGC - Platform Clock Gating Control Register */
/*! @{ */

#define SIM_PLATCGC_CGCMSCM_MASK                 (0x1U)
#define SIM_PLATCGC_CGCMSCM_SHIFT                (0U)
/*! CGCMSCM - MSCM Clock Gating Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_PLATCGC_CGCMSCM(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_PLATCGC_CGCMSCM_SHIFT)) & SIM_PLATCGC_CGCMSCM_MASK)

#define SIM_PLATCGC_CGCMPU_MASK                  (0x2U)
#define SIM_PLATCGC_CGCMPU_SHIFT                 (1U)
/*! CGCMPU - MPU Clock Gating Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_PLATCGC_CGCMPU(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PLATCGC_CGCMPU_SHIFT)) & SIM_PLATCGC_CGCMPU_MASK)

#define SIM_PLATCGC_CGCDMA_MASK                  (0x4U)
#define SIM_PLATCGC_CGCDMA_SHIFT                 (2U)
/*! CGCDMA - DMA Clock Gating Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_PLATCGC_CGCDMA(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PLATCGC_CGCDMA_SHIFT)) & SIM_PLATCGC_CGCDMA_MASK)

#define SIM_PLATCGC_CGCERM_MASK                  (0x8U)
#define SIM_PLATCGC_CGCERM_SHIFT                 (3U)
/*! CGCERM - ERM Clock Gating Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_PLATCGC_CGCERM(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PLATCGC_CGCERM_SHIFT)) & SIM_PLATCGC_CGCERM_MASK)

#define SIM_PLATCGC_CGCEIM_MASK                  (0x10U)
#define SIM_PLATCGC_CGCEIM_SHIFT                 (4U)
/*! CGCEIM - EIM Clock Gating Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_PLATCGC_CGCEIM(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_PLATCGC_CGCEIM_SHIFT)) & SIM_PLATCGC_CGCEIM_MASK)
/*! @} */

/*! @name FCFG1 - Flash Configuration Register 1 */
/*! @{ */

#define SIM_FCFG1_DEPART_MASK                    (0xF000U)
#define SIM_FCFG1_DEPART_SHIFT                   (12U)
/*! DEPART - FlexNVM partition */
#define SIM_FCFG1_DEPART(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_DEPART_SHIFT)) & SIM_FCFG1_DEPART_MASK)

#define SIM_FCFG1_EEERAMSIZE_MASK                (0xF0000U)
#define SIM_FCFG1_EEERAMSIZE_SHIFT               (16U)
/*! EEERAMSIZE - EEE SRAM SIZE
 *  0b0000..Reserved
 *  0b0001..Reserved
 *  0b0010..4 KB
 *  0b0011..2 KB
 *  0b0100..1 KB
 *  0b0101..512 Bytes
 *  0b0110..256 Bytes
 *  0b0111..128 Bytes
 *  0b1000..64 Bytes
 *  0b1001..32 Bytes
 *  0b1111..0 Bytes
 */
#define SIM_FCFG1_EEERAMSIZE(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_EEERAMSIZE_SHIFT)) & SIM_FCFG1_EEERAMSIZE_MASK)
/*! @} */

/*! @name UIDH - Unique Identification Register High */
/*! @{ */

#define SIM_UIDH_UID127_96_MASK                  (0xFFFFFFFFU)
#define SIM_UIDH_UID127_96_SHIFT                 (0U)
/*! UID127_96 - Unique Identification */
#define SIM_UIDH_UID127_96(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_UIDH_UID127_96_SHIFT)) & SIM_UIDH_UID127_96_MASK)
/*! @} */

/*! @name UIDMH - Unique Identification Register Mid-High */
/*! @{ */

#define SIM_UIDMH_UID95_64_MASK                  (0xFFFFFFFFU)
#define SIM_UIDMH_UID95_64_SHIFT                 (0U)
/*! UID95_64 - Unique Identification */
#define SIM_UIDMH_UID95_64(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_UIDMH_UID95_64_SHIFT)) & SIM_UIDMH_UID95_64_MASK)
/*! @} */

/*! @name UIDML - Unique Identification Register Mid Low */
/*! @{ */

#define SIM_UIDML_UID63_32_MASK                  (0xFFFFFFFFU)
#define SIM_UIDML_UID63_32_SHIFT                 (0U)
/*! UID63_32 - Unique Identification */
#define SIM_UIDML_UID63_32(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_UIDML_UID63_32_SHIFT)) & SIM_UIDML_UID63_32_MASK)
/*! @} */

/*! @name UIDL - Unique Identification Register Low */
/*! @{ */

#define SIM_UIDL_UID31_0_MASK                    (0xFFFFFFFFU)
#define SIM_UIDL_UID31_0_SHIFT                   (0U)
/*! UID31_0 - Unique Identification */
#define SIM_UIDL_UID31_0(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_UIDL_UID31_0_SHIFT)) & SIM_UIDL_UID31_0_MASK)
/*! @} */

/*! @name CLKDIV4 - System Clock Divider Register 4 */
/*! @{ */

#define SIM_CLKDIV4_TRACEFRAC_MASK               (0x1U)
#define SIM_CLKDIV4_TRACEFRAC_SHIFT              (0U)
/*! TRACEFRAC - Trace Clock Divider fraction To configure TRACEDIV and TRACEFRAC, you must first
 *    clear TRACEDIVEN to disable the trace clock divide function.
 */
#define SIM_CLKDIV4_TRACEFRAC(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV4_TRACEFRAC_SHIFT)) & SIM_CLKDIV4_TRACEFRAC_MASK)

#define SIM_CLKDIV4_TRACEDIV_MASK                (0xEU)
#define SIM_CLKDIV4_TRACEDIV_SHIFT               (1U)
/*! TRACEDIV - Trace Clock Divider value To configure TRACEDIV, you must first disable TRACEDIVEN,
 *    then enable it after setting TRACEDIV.
 */
#define SIM_CLKDIV4_TRACEDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV4_TRACEDIV_SHIFT)) & SIM_CLKDIV4_TRACEDIV_MASK)

#define SIM_CLKDIV4_TRACEDIVEN_MASK              (0x10000000U)
#define SIM_CLKDIV4_TRACEDIVEN_SHIFT             (28U)
/*! TRACEDIVEN - Debug Trace Divider control
 *  0b0..Debug trace divider disabled
 *  0b1..Debug trace divider enabled
 */
#define SIM_CLKDIV4_TRACEDIVEN(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV4_TRACEDIVEN_SHIFT)) & SIM_CLKDIV4_TRACEDIVEN_MASK)
/*! @} */

/*! @name MISCTRL1 - Miscellaneous Control register 1 */
/*! @{ */

#define SIM_MISCTRL1_SW_TRG_MASK                 (0x1U)
#define SIM_MISCTRL1_SW_TRG_SHIFT                (0U)
/*! SW_TRG - Software trigger to TRGMUX. Writing to this bit generates software trigger to
 *    peripherals through TRGMUX (Refer to Figure: Trigger interconnectivity).
 */
#define SIM_MISCTRL1_SW_TRG(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL1_SW_TRG_SHIFT)) & SIM_MISCTRL1_SW_TRG_MASK)
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

