/*
** ###################################################################
**     Processors:          MKE14Z128VLH7
**                          MKE14Z128VLL7
**                          MKE14Z256VLH7
**                          MKE14Z256VLL7
**                          MKE15Z128VLH7
**                          MKE15Z128VLL7
**                          MKE15Z256VLH7
**                          MKE15Z256VLL7
**
**     Version:             rev. 6.0, 2016-09-20
**     Build:               b240715
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-08-19)
**         Initial version.
**     - rev. 2.0 (2015-09-22)
**         Based on rev0final RDP, add PCC/TRGMUX.
**     - rev. 3.0 (2015-12-29)
**         Align LPFLL register names.
**     - rev. 4.0 (2016-02-19)
**         Based on rev1final RDP.
**     - rev. 5.0 (2016-08-02)
**         Based on rev1.x RDP.
**     - rev. 6.0 (2016-09-20)
**         Based on rev2 RDP.
**
** ###################################################################
*/

/*!
 * @file SIM.h
 * @version 6.0
 * @date 2016-09-20
 * @brief CMSIS Peripheral Access Layer for SIM
 *
 * CMSIS Peripheral Access Layer for SIM
 */

#if !defined(SIM_H_)
#define SIM_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE14Z128VLH7) || defined(CPU_MKE14Z128VLL7) || defined(CPU_MKE14Z256VLH7) || defined(CPU_MKE14Z256VLL7))
#include "MKE14Z7_COMMON.h"
#elif (defined(CPU_MKE15Z128VLH7) || defined(CPU_MKE15Z128VLL7) || defined(CPU_MKE15Z256VLH7) || defined(CPU_MKE15Z256VLL7))
#include "MKE15Z7_COMMON.h"
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
       uint8_t RESERVED_0[4];
  __IO uint32_t CHIPCTL;                           /**< Chip Control register, offset: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t FTMOPT0;                           /**< FTM Option Register 0, offset: 0xC */
       uint8_t RESERVED_2[8];
  __IO uint32_t ADCOPT;                            /**< ADC Options Register, offset: 0x18 */
  __IO uint32_t FTMOPT1;                           /**< FTM Option Register 1, offset: 0x1C */
       uint8_t RESERVED_3[4];
  __I  uint32_t SDID;                              /**< System Device Identification Register, offset: 0x24 */
       uint8_t RESERVED_4[36];
  __IO uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x4C */
  __I  uint32_t FCFG2;                             /**< Flash Configuration Register 2, offset: 0x50 */
  __I  uint32_t UIDH;                              /**< Unique Identification Register High, offset: 0x54 */
  __I  uint32_t UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x58 */
  __I  uint32_t UIDML;                             /**< Unique Identification Register Mid Low, offset: 0x5C */
  __I  uint32_t UIDL;                              /**< Unique Identification Register Low, offset: 0x60 */
       uint8_t RESERVED_5[8];
  __IO uint32_t MISCTRL;                           /**< Miscellaneous Control register, offset: 0x6C */
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

#define SIM_CHIPCTL_ADC_INTERLEAVE_EN_MASK       (0x3U)
#define SIM_CHIPCTL_ADC_INTERLEAVE_EN_SHIFT      (0U)
/*! ADC_INTERLEAVE_EN - ADC interleave channel enable
 *  0b00..No interleave channel
 */
#define SIM_CHIPCTL_ADC_INTERLEAVE_EN(x)         (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_ADC_INTERLEAVE_EN_SHIFT)) & SIM_CHIPCTL_ADC_INTERLEAVE_EN_MASK)

#define SIM_CHIPCTL_CLKOUTDIV_MASK               (0x30U)
#define SIM_CHIPCTL_CLKOUTDIV_SHIFT              (4U)
/*! CLKOUTDIV - CLKOUT divider ratio
 *  0b00..Divided by 1
 *  0b01..Divided by 2
 *  0b10..Divided by 4
 *  0b11..Divided by 8
 */
#define SIM_CHIPCTL_CLKOUTDIV(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_CLKOUTDIV_SHIFT)) & SIM_CHIPCTL_CLKOUTDIV_MASK)

#define SIM_CHIPCTL_CLKOUTSEL_MASK               (0xC0U)
#define SIM_CHIPCTL_CLKOUTSEL_SHIFT              (6U)
/*! CLKOUTSEL - CLKOUT Select
 *  0b00..Reseved
 *  0b01..SCGCLKOUT(SIRC/FIRC/SOSC/LPFLL), see SCG_CLKOUTCNFG register.
 *  0b10..RTC oscillator (OSC32) clock (32 kHz)
 *  0b11..LPO clock (128 kHz)
 */
#define SIM_CHIPCTL_CLKOUTSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_CLKOUTSEL_SHIFT)) & SIM_CHIPCTL_CLKOUTSEL_MASK)

#define SIM_CHIPCTL_PDB_BB_SEL_MASK              (0x2000U)
#define SIM_CHIPCTL_PDB_BB_SEL_SHIFT             (13U)
/*! PDB_BB_SEL - PDB back-to-back select
 *  0b0..PDB0 channel 0 back-to-back operation with ADC0 COCO[1:0] and PDB0 channel 1 back-to-back operation with ADC1 COCO[1:0]
 *  0b1..PDB0 Channel 0 back-to-back operation with COCO[0] of ADC0 and COCO[1] of ADC1 ; PDB0 Channel 1
 *       back-to-back operation with COCO[0] of ADC1 and COCO[1] of ADC0
 */
#define SIM_CHIPCTL_PDB_BB_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_PDB_BB_SEL_SHIFT)) & SIM_CHIPCTL_PDB_BB_SEL_MASK)

#define SIM_CHIPCTL_PWTCLKSEL_MASK               (0x30000U)
#define SIM_CHIPCTL_PWTCLKSEL_SHIFT              (16U)
/*! PWTCLKSEL - PWT clock source select
 *  0b00..PWT alternative clock is from the TCLK0 pin.
 *  0b01..PWT alternative clock is from the TCLK1 pin.
 *  0b10..PWT alternative clock is from the TCLK2 pin.
 *  0b11..Reserved
 */
#define SIM_CHIPCTL_PWTCLKSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_PWTCLKSEL_SHIFT)) & SIM_CHIPCTL_PWTCLKSEL_MASK)

#define SIM_CHIPCTL_RTC32KCLKSEL_MASK            (0xC0000U)
#define SIM_CHIPCTL_RTC32KCLKSEL_SHIFT           (18U)
/*! RTC32KCLKSEL - RTC 32K clock input select
 *  0b00..OSC32 clock output
 *  0b01..RTC_CLKIN
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define SIM_CHIPCTL_RTC32KCLKSEL(x)              (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTL_RTC32KCLKSEL_SHIFT)) & SIM_CHIPCTL_RTC32KCLKSEL_MASK)
/*! @} */

/*! @name FTMOPT0 - FTM Option Register 0 */
/*! @{ */

#define SIM_FTMOPT0_FTM0FLTxSEL_MASK             (0x7U)
#define SIM_FTMOPT0_FTM0FLTxSEL_SHIFT            (0U)
/*! FTM0FLTxSEL - FTM0 Fault x Select */
#define SIM_FTMOPT0_FTM0FLTxSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT0_FTM0FLTxSEL_SHIFT)) & SIM_FTMOPT0_FTM0FLTxSEL_MASK)

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

#define SIM_ADCOPT_ADC0SWPRETRG_MASK             (0x6U)
#define SIM_ADCOPT_ADC0SWPRETRG_SHIFT            (1U)
/*! ADC0SWPRETRG - ADC0 software pre-trigger sources
 *  0b00..disabled
 *  0b01..software pre-trigger 0
 *  0b10..software pre-trigger 1
 *  0b11..disabled
 */
#define SIM_ADCOPT_ADC0SWPRETRG(x)               (((uint32_t)(((uint32_t)(x)) << SIM_ADCOPT_ADC0SWPRETRG_SHIFT)) & SIM_ADCOPT_ADC0SWPRETRG_MASK)

#define SIM_ADCOPT_ADC0PRETRGSEL_MASK            (0x30U)
#define SIM_ADCOPT_ADC0PRETRGSEL_SHIFT           (4U)
/*! ADC0PRETRGSEL - ADC0 pre-trigger source select
 *  0b00..PDB output
 *  0b01..TRGMUX output
 *  0b10..ADC0 software pre-trigger
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

#define SIM_ADCOPT_ADC1SWPRETRG_MASK             (0x600U)
#define SIM_ADCOPT_ADC1SWPRETRG_SHIFT            (9U)
/*! ADC1SWPRETRG - ADC1 software pre-trigger sources
 *  0b00..disabled
 *  0b01..software pre-trigger 0
 *  0b10..software pre-trigger 1
 *  0b11..disabled
 */
#define SIM_ADCOPT_ADC1SWPRETRG(x)               (((uint32_t)(((uint32_t)(x)) << SIM_ADCOPT_ADC1SWPRETRG_SHIFT)) & SIM_ADCOPT_ADC1SWPRETRG_MASK)

#define SIM_ADCOPT_ADC1PRETRGSEL_MASK            (0x3000U)
#define SIM_ADCOPT_ADC1PRETRGSEL_SHIFT           (12U)
/*! ADC1PRETRGSEL - ADC1 pre-trigger source select
 *  0b00..PDB output
 *  0b01..TRGMUX output
 *  0b10..ADC1 software pre-trigger
 *  0b11..Reserved
 */
#define SIM_ADCOPT_ADC1PRETRGSEL(x)              (((uint32_t)(((uint32_t)(x)) << SIM_ADCOPT_ADC1PRETRGSEL_SHIFT)) & SIM_ADCOPT_ADC1PRETRGSEL_MASK)
/*! @} */

/*! @name FTMOPT1 - FTM Option Register 1 */
/*! @{ */

#define SIM_FTMOPT1_FTM0SYNCBIT_MASK             (0x1U)
#define SIM_FTMOPT1_FTM0SYNCBIT_SHIFT            (0U)
/*! FTM0SYNCBIT - FTM0 Sync Bit
 *  0b0..No effect.
 *  0b1..Write 1 to assert the TRIG1 input to FTM0. Software must clear this bit to allow other trigger sources to assert.
 */
#define SIM_FTMOPT1_FTM0SYNCBIT(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM0SYNCBIT_SHIFT)) & SIM_FTMOPT1_FTM0SYNCBIT_MASK)

#define SIM_FTMOPT1_FTM1SYNCBIT_MASK             (0x2U)
#define SIM_FTMOPT1_FTM1SYNCBIT_SHIFT            (1U)
/*! FTM1SYNCBIT - FTM1 Sync Bit
 *  0b0..No effect.
 *  0b1..Write 1 to assert the TRIG1 input to FTM1. Software must clear this bit to allow other trigger sources to assert.
 */
#define SIM_FTMOPT1_FTM1SYNCBIT(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM1SYNCBIT_SHIFT)) & SIM_FTMOPT1_FTM1SYNCBIT_MASK)

#define SIM_FTMOPT1_FTM2SYNCBIT_MASK             (0x4U)
#define SIM_FTMOPT1_FTM2SYNCBIT_SHIFT            (2U)
/*! FTM2SYNCBIT - FTM2 Sync Bit
 *  0b0..No effect.
 *  0b1..Write 1 to assert the TRIG1 input to FTM2. Software must clear this bit to allow other trigger sources to assert.
 */
#define SIM_FTMOPT1_FTM2SYNCBIT(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM2SYNCBIT_SHIFT)) & SIM_FTMOPT1_FTM2SYNCBIT_MASK)

#define SIM_FTMOPT1_FTM1CH0SEL_MASK              (0x30U)
#define SIM_FTMOPT1_FTM1CH0SEL_SHIFT             (4U)
/*! FTM1CH0SEL - FTM1 CH0 Select
 *  0b00..FTM1_CH0 input
 *  0b01..CMP0 output
 *  0b10..CMP1 output
 *  0b11..Reserved
 */
#define SIM_FTMOPT1_FTM1CH0SEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM1CH0SEL_SHIFT)) & SIM_FTMOPT1_FTM1CH0SEL_MASK)

#define SIM_FTMOPT1_FTM2CH0SEL_MASK              (0xC0U)
#define SIM_FTMOPT1_FTM2CH0SEL_SHIFT             (6U)
/*! FTM2CH0SEL - FTM2 CH0 Select
 *  0b00..FTM2_CH0 input
 *  0b01..CMP0 output
 *  0b10..CMP1 output
 *  0b11..Reserved
 */
#define SIM_FTMOPT1_FTM2CH0SEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM2CH0SEL_SHIFT)) & SIM_FTMOPT1_FTM2CH0SEL_MASK)

#define SIM_FTMOPT1_FTM2CH1SEL_MASK              (0x100U)
#define SIM_FTMOPT1_FTM2CH1SEL_SHIFT             (8U)
/*! FTM2CH1SEL - FTM2 CH1 Select
 *  0b0..FTM2_CH1 input
 *  0b1..exclusive OR of FTM2_CH0, FTM2_CH1, and FTM1_CH1
 */
#define SIM_FTMOPT1_FTM2CH1SEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM2CH1SEL_SHIFT)) & SIM_FTMOPT1_FTM2CH1SEL_MASK)

#define SIM_FTMOPT1_FTM0_OUTSEL_MASK             (0xFF0000U)
#define SIM_FTMOPT1_FTM0_OUTSEL_SHIFT            (16U)
/*! FTM0_OUTSEL - FTM0 channel modulation select with FTM1_CH1
 *  0b00000000..No modulation with FTM1_CH1
 *  0b00000001..Modulation with FTM1_CH1
 */
#define SIM_FTMOPT1_FTM0_OUTSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_FTMOPT1_FTM0_OUTSEL_SHIFT)) & SIM_FTMOPT1_FTM0_OUTSEL_MASK)
/*! @} */

/*! @name SDID - System Device Identification Register */
/*! @{ */

#define SIM_SDID_PINID_MASK                      (0x7FU)
#define SIM_SDID_PINID_SHIFT                     (0U)
/*! PINID - Pin identification
 *  0b0000111..64-pin
 *  0b0001010..100-pin
 */
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_PINID_SHIFT)) & SIM_SDID_PINID_MASK)

#define SIM_SDID_PROJECTID_MASK                  (0xF80U)
#define SIM_SDID_PROJECTID_SHIFT                 (7U)
/*! PROJECTID - Project ID */
#define SIM_SDID_PROJECTID(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SDID_PROJECTID_SHIFT)) & SIM_SDID_PROJECTID_MASK)

#define SIM_SDID_REVID_MASK                      (0xF000U)
#define SIM_SDID_REVID_SHIFT                     (12U)
/*! REVID - Device revision number */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_REVID_SHIFT)) & SIM_SDID_REVID_MASK)

#define SIM_SDID_RAMSIZE_MASK                    (0xF0000U)
#define SIM_SDID_RAMSIZE_SHIFT                   (16U)
/*! RAMSIZE - RAM size
 *  0b0101..16 KB
 *  0b0110..32 KB
 */
#define SIM_SDID_RAMSIZE(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SDID_RAMSIZE_SHIFT)) & SIM_SDID_RAMSIZE_MASK)

#define SIM_SDID_SERIESID_MASK                   (0xF00000U)
#define SIM_SDID_SERIESID_SHIFT                  (20U)
/*! SERIESID - Kinetis Series ID
 *  0b0010..Kinetis E+ series
 */
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SERIESID_SHIFT)) & SIM_SDID_SERIESID_MASK)

#define SIM_SDID_SUBFAMID_MASK                   (0xF000000U)
#define SIM_SDID_SUBFAMID_SHIFT                  (24U)
/*! SUBFAMID - Kinetis E-series Sub-Family ID */
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SUBFAMID_SHIFT)) & SIM_SDID_SUBFAMID_MASK)

#define SIM_SDID_FAMILYID_MASK                   (0xF0000000U)
#define SIM_SDID_FAMILYID_SHIFT                  (28U)
/*! FAMILYID - Kinetis E-series Family ID
 *  0b0001..KE1x Family (Enhanced features)
 */
#define SIM_SDID_FAMILYID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_FAMILYID_SHIFT)) & SIM_SDID_FAMILYID_MASK)
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
 *  0b0..Flash remains enabled during Doze mode
 *  0b1..Flash is disabled for the duration of Doze mode
 */
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDOZE_SHIFT)) & SIM_FCFG1_FLASHDOZE_MASK)

#define SIM_FCFG1_DEPART_MASK                    (0xF000U)
#define SIM_FCFG1_DEPART_SHIFT                   (12U)
/*! DEPART - FlexNVM partition */
#define SIM_FCFG1_DEPART(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_DEPART_SHIFT)) & SIM_FCFG1_DEPART_MASK)

#define SIM_FCFG1_EEERAMSIZE_MASK                (0xF0000U)
#define SIM_FCFG1_EEERAMSIZE_SHIFT               (16U)
/*! EEERAMSIZE - EEE SRAM SIZE
 *  0b0011..2 KB
 *  0b0100..1 KB
 *  0b0101..512 Bytes
 *  0b0110..256 Bytes
 *  0b0111..128 Bytes
 *  0b1000..64 Bytes
 *  0b1001..32 Bytes
 */
#define SIM_FCFG1_EEERAMSIZE(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_EEERAMSIZE_SHIFT)) & SIM_FCFG1_EEERAMSIZE_MASK)

#define SIM_FCFG1_PFSIZE_MASK                    (0xF000000U)
#define SIM_FCFG1_PFSIZE_SHIFT                   (24U)
/*! PFSIZE - Program flash size
 *  0b0111..128 KB of program flash memory, 4 KB protection region
 *  0b1001..256 KB of program flash memory, 8 KB protection region
 */
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_PFSIZE_SHIFT)) & SIM_FCFG1_PFSIZE_MASK)

#define SIM_FCFG1_NVMSIZE_MASK                   (0xF0000000U)
#define SIM_FCFG1_NVMSIZE_SHIFT                  (28U)
/*! NVMSIZE - FlexNVM size
 *  0b0000..0 KB of FlexNVM
 *  0b0011..32 KB of FlexNVM
 */
#define SIM_FCFG1_NVMSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_NVMSIZE_SHIFT)) & SIM_FCFG1_NVMSIZE_MASK)
/*! @} */

/*! @name FCFG2 - Flash Configuration Register 2 */
/*! @{ */

#define SIM_FCFG2_MAXADDR1_MASK                  (0x7F0000U)
#define SIM_FCFG2_MAXADDR1_SHIFT                 (16U)
/*! MAXADDR1 - Max address block 1 */
#define SIM_FCFG2_MAXADDR1(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_MAXADDR1_SHIFT)) & SIM_FCFG2_MAXADDR1_MASK)

#define SIM_FCFG2_MAXADDR0_MASK                  (0x7F000000U)
#define SIM_FCFG2_MAXADDR0_SHIFT                 (24U)
/*! MAXADDR0 - Max address block 0 */
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_MAXADDR0_SHIFT)) & SIM_FCFG2_MAXADDR0_MASK)
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

/*! @name MISCTRL - Miscellaneous Control register */
/*! @{ */

#define SIM_MISCTRL_SW_TRG_MASK                  (0x1U)
#define SIM_MISCTRL_SW_TRG_SHIFT                 (0U)
/*! SW_TRG - Software Trigger bit to TRGMUX */
#define SIM_MISCTRL_SW_TRG(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL_SW_TRG_SHIFT)) & SIM_MISCTRL_SW_TRG_MASK)

#define SIM_MISCTRL_DMA_INT_SEL_MASK             (0xF0U)
#define SIM_MISCTRL_DMA_INT_SEL_SHIFT            (4U)
/*! DMA_INT_SEL - DMA channel interrupt OR select */
#define SIM_MISCTRL_DMA_INT_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL_DMA_INT_SEL_SHIFT)) & SIM_MISCTRL_DMA_INT_SEL_MASK)

#define SIM_MISCTRL_UART0ODE_MASK                (0x10000U)
#define SIM_MISCTRL_UART0ODE_SHIFT               (16U)
/*! UART0ODE - UART0 Open Drain Enable
 *  0b0..Open drain is disabled on UART0
 *  0b1..Open drain is enabled on UART0
 */
#define SIM_MISCTRL_UART0ODE(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL_UART0ODE_SHIFT)) & SIM_MISCTRL_UART0ODE_MASK)

#define SIM_MISCTRL_UART1ODE_MASK                (0x20000U)
#define SIM_MISCTRL_UART1ODE_SHIFT               (17U)
/*! UART1ODE - UART1 Open Drain Enable
 *  0b0..Open drain is disabled on UART1
 *  0b1..Open drain is enabled on UART1
 */
#define SIM_MISCTRL_UART1ODE(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL_UART1ODE_SHIFT)) & SIM_MISCTRL_UART1ODE_MASK)

#define SIM_MISCTRL_UART2ODE_MASK                (0x40000U)
#define SIM_MISCTRL_UART2ODE_SHIFT               (18U)
/*! UART2ODE - UART2 Open Drain Enable
 *  0b0..Open drain is disabled on UART2
 *  0b1..Open drain is enabled on UART2
 */
#define SIM_MISCTRL_UART2ODE(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_MISCTRL_UART2ODE_SHIFT)) & SIM_MISCTRL_UART2ODE_MASK)
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


#endif  /* SIM_H_ */

