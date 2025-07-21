/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AFE
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
 * @file PERI_AFE.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AFE
 *
 * CMSIS Peripheral Access Layer for AFE
 */

#if !defined(PERI_AFE_H_)
#define PERI_AFE_H_                              /**< Symbol preventing repeated inclusion */

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
   -- AFE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AFE_Peripheral_Access_Layer AFE Peripheral Access Layer
 * @{
 */

/** AFE - Size of Registers Arrays */
#define AFE_CFR_COUNT                             4u
#define AFE_DR_COUNT                              4u
#define AFE_RR_COUNT                              4u

/** AFE - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFR[AFE_CFR_COUNT];                /**< Channel0 Configuration Register..Channel3 Configuration Register, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t CR;                                /**< Control Register, offset: 0x18 */
  __IO uint32_t CKR;                               /**< Clock Configuration Register, offset: 0x1C */
  __IO uint32_t DI;                                /**< DMA and Interrupt Register, offset: 0x20 */
       uint8_t RESERVED_1[8];
  __IO uint32_t DR[AFE_DR_COUNT];                  /**< Channel0 Delay Register..Channel3 Delay Register, array offset: 0x2C, array step: 0x4 */
       uint8_t RESERVED_2[8];
  __I  uint32_t RR[AFE_RR_COUNT];                  /**< Channel0 Result Register..Channel3 Result Register, array offset: 0x44, array step: 0x4 */
       uint8_t RESERVED_3[8];
  __I  uint32_t SR;                                /**< Status Register, offset: 0x5C */
} AFE_Type;

/* ----------------------------------------------------------------------------
   -- AFE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AFE_Register_Masks AFE Register Masks
 * @{
 */

/*! @name CFR - Channel0 Configuration Register..Channel3 Configuration Register */
/*! @{ */

#define AFE_CFR_HW_TRG_MASK                      (0x200U)
#define AFE_CFR_HW_TRG_SHIFT                     (9U)
/*! HW_TRG - Hardware Trigger Select
 *  0b0..Software trigger select
 *  0b1..Hardware trigger select
 */
#define AFE_CFR_HW_TRG(x)                        (((uint32_t)(((uint32_t)(x)) << AFE_CFR_HW_TRG_SHIFT)) & AFE_CFR_HW_TRG_MASK)

#define AFE_CFR_DEC_CLK_INP_SEL_MASK             (0x400U)
#define AFE_CFR_DEC_CLK_INP_SEL_SHIFT            (10U)
/*! DEC_CLK_INP_SEL - Decimator Clock Input Select
 *  0b0..On the chip modulator clock will be used.
 *  0b1..External clock will be used.
 */
#define AFE_CFR_DEC_CLK_INP_SEL(x)               (((uint32_t)(((uint32_t)(x)) << AFE_CFR_DEC_CLK_INP_SEL_SHIFT)) & AFE_CFR_DEC_CLK_INP_SEL_MASK)

#define AFE_CFR_DEC_CLK_EDGE_SEL_MASK            (0x800U)
#define AFE_CFR_DEC_CLK_EDGE_SEL_SHIFT           (11U)
/*! DEC_CLK_EDGE_SEL - Decimator Clock Edge Select
 *  0b0..Posedge will be used.
 *  0b1..Negedge will be used.
 */
#define AFE_CFR_DEC_CLK_EDGE_SEL(x)              (((uint32_t)(((uint32_t)(x)) << AFE_CFR_DEC_CLK_EDGE_SEL_SHIFT)) & AFE_CFR_DEC_CLK_EDGE_SEL_MASK)

#define AFE_CFR_CC_MASK                          (0x1000U)
#define AFE_CFR_CC_SHIFT                         (12U)
/*! CC - Continuous Conversion/Single Conversion Mode Select
 *  0b0..One conversion following a triggering event
 *  0b1..Continuous conversions following a triggering event.
 */
#define AFE_CFR_CC(x)                            (((uint32_t)(((uint32_t)(x)) << AFE_CFR_CC_SHIFT)) & AFE_CFR_CC_MASK)

#define AFE_CFR_DEC_EN_MASK                      (0x2000U)
#define AFE_CFR_DEC_EN_SHIFT                     (13U)
/*! DEC_EN - Decimation Filter enable
 *  0b0..Decimation filter is disabled.
 *  0b1..Decimation filter is enabled.
 */
#define AFE_CFR_DEC_EN(x)                        (((uint32_t)(((uint32_t)(x)) << AFE_CFR_DEC_EN_SHIFT)) & AFE_CFR_DEC_EN_MASK)

#define AFE_CFR_SD_MOD_EN_MASK                   (0x4000U)
#define AFE_CFR_SD_MOD_EN_SHIFT                  (14U)
/*! SD_MOD_EN - Sigma Delta Modulator enable
 *  0b0..SD ADC0 is disabled
 *  0b1..SD ADC0 is enabled
 */
#define AFE_CFR_SD_MOD_EN(x)                     (((uint32_t)(((uint32_t)(x)) << AFE_CFR_SD_MOD_EN_SHIFT)) & AFE_CFR_SD_MOD_EN_MASK)

#define AFE_CFR_BYP_MODE_MASK                    (0x20000U)
#define AFE_CFR_BYP_MODE_SHIFT                   (17U)
/*! BYP_MODE - AFE Channel3 bypass mode
 *  0b0..Normal mode
 *  0b1..Bypass mode where ADC and PGA of channel0 are disabled.
 */
#define AFE_CFR_BYP_MODE(x)                      (((uint32_t)(((uint32_t)(x)) << AFE_CFR_BYP_MODE_SHIFT)) & AFE_CFR_BYP_MODE_MASK)

#define AFE_CFR_PGA_GAIN_SEL_MASK                (0x380000U)
#define AFE_CFR_PGA_GAIN_SEL_SHIFT               (19U)
/*! PGA_GAIN_SEL - PGA Gain Select
 *  0b000..reserved
 *  0b001..1x (default)
 *  0b010..2x
 *  0b011..4x
 *  0b100..8x
 *  0b101..16x
 *  0b110..32x
 *  0b111..reserved
 */
#define AFE_CFR_PGA_GAIN_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << AFE_CFR_PGA_GAIN_SEL_SHIFT)) & AFE_CFR_PGA_GAIN_SEL_MASK)

#define AFE_CFR_PGA_EN_MASK                      (0x1000000U)
#define AFE_CFR_PGA_EN_SHIFT                     (24U)
/*! PGA_EN - PGA enable
 *  0b0..PGA disabled
 *  0b1..PGA enabled
 */
#define AFE_CFR_PGA_EN(x)                        (((uint32_t)(((uint32_t)(x)) << AFE_CFR_PGA_EN_SHIFT)) & AFE_CFR_PGA_EN_MASK)

#define AFE_CFR_DEC_OSR_MASK                     (0xE0000000U)
#define AFE_CFR_DEC_OSR_SHIFT                    (29U)
/*! DEC_OSR - Decimator OverSampling Ratio select
 *  0b000..64
 *  0b001..128
 *  0b010..256
 *  0b011..512
 *  0b100..1024
 *  0b101..2048
 *  0b110-0b111..reserved
 */
#define AFE_CFR_DEC_OSR(x)                       (((uint32_t)(((uint32_t)(x)) << AFE_CFR_DEC_OSR_SHIFT)) & AFE_CFR_DEC_OSR_MASK)
/*! @} */

/*! @name CR - Control Register */
/*! @{ */

#define AFE_CR_STRTUP_CNT_MASK                   (0xFE00U)
#define AFE_CR_STRTUP_CNT_SHIFT                  (9U)
/*! STRTUP_CNT - Start up count */
#define AFE_CR_STRTUP_CNT(x)                     (((uint32_t)(((uint32_t)(x)) << AFE_CR_STRTUP_CNT_SHIFT)) & AFE_CR_STRTUP_CNT_MASK)

#define AFE_CR_RESULT_FORMAT_MASK                (0x40000U)
#define AFE_CR_RESULT_FORMAT_SHIFT               (18U)
/*! RESULT_FORMAT - Result Format
 *  0b0..Left justified 2's complement 32-bit : SVVVVVVVVVVVVVVVVVVVVVVV00000000 where (S= sign bit , V=valid result value, 0=zero)
 *  0b1..Right justified 2's complement 32-bit : SSSSSSSSSVVVVVVVVVVVVVVVVVVVVVVV where (S= sign bit , V= valid result value, 0= zero)
 */
#define AFE_CR_RESULT_FORMAT(x)                  (((uint32_t)(((uint32_t)(x)) << AFE_CR_RESULT_FORMAT_SHIFT)) & AFE_CR_RESULT_FORMAT_MASK)

#define AFE_CR_DLY_OK_MASK                       (0x200000U)
#define AFE_CR_DLY_OK_SHIFT                      (21U)
/*! DLY_OK - Delay OK */
#define AFE_CR_DLY_OK(x)                         (((uint32_t)(((uint32_t)(x)) << AFE_CR_DLY_OK_SHIFT)) & AFE_CR_DLY_OK_MASK)

#define AFE_CR_RST_B_MASK                        (0x400000U)
#define AFE_CR_RST_B_SHIFT                       (22U)
/*! RST_B - Software Reset
 *  0b0..All ADCs, PGAs and Decimation filters are disabled. Clock Configuration bits will be reset.
 *  0b1...= All ADCs, PGAs and Decimation filters are enabled.
 */
#define AFE_CR_RST_B(x)                          (((uint32_t)(((uint32_t)(x)) << AFE_CR_RST_B_SHIFT)) & AFE_CR_RST_B_MASK)

#define AFE_CR_LPM_EN_MASK                       (0x2000000U)
#define AFE_CR_LPM_EN_SHIFT                      (25U)
/*! LPM_EN - Low power Mode enable
 *  0b0..AFE will be in normal mode
 *  0b1..AFE will be in low power mode. Setting this bit reduce the current consumption of ADC and Buffer
 *       Amplifier , the max modulator clock frequency is below 1Mhz.
 */
#define AFE_CR_LPM_EN(x)                         (((uint32_t)(((uint32_t)(x)) << AFE_CR_LPM_EN_SHIFT)) & AFE_CR_LPM_EN_MASK)

#define AFE_CR_SOFT_TRG3_MASK                    (0x8000000U)
#define AFE_CR_SOFT_TRG3_SHIFT                   (27U)
/*! SOFT_TRG3 - Software Trigger3 */
#define AFE_CR_SOFT_TRG3(x)                      (((uint32_t)(((uint32_t)(x)) << AFE_CR_SOFT_TRG3_SHIFT)) & AFE_CR_SOFT_TRG3_MASK)

#define AFE_CR_SOFT_TRG2_MASK                    (0x10000000U)
#define AFE_CR_SOFT_TRG2_SHIFT                   (28U)
/*! SOFT_TRG2 - Software Trigger2 */
#define AFE_CR_SOFT_TRG2(x)                      (((uint32_t)(((uint32_t)(x)) << AFE_CR_SOFT_TRG2_SHIFT)) & AFE_CR_SOFT_TRG2_MASK)

#define AFE_CR_SOFT_TRG1_MASK                    (0x20000000U)
#define AFE_CR_SOFT_TRG1_SHIFT                   (29U)
/*! SOFT_TRG1 - Software Trigger1 */
#define AFE_CR_SOFT_TRG1(x)                      (((uint32_t)(((uint32_t)(x)) << AFE_CR_SOFT_TRG1_SHIFT)) & AFE_CR_SOFT_TRG1_MASK)

#define AFE_CR_SOFT_TRG0_MASK                    (0x40000000U)
#define AFE_CR_SOFT_TRG0_SHIFT                   (30U)
/*! SOFT_TRG0 - Software Trigger0 */
#define AFE_CR_SOFT_TRG0(x)                      (((uint32_t)(((uint32_t)(x)) << AFE_CR_SOFT_TRG0_SHIFT)) & AFE_CR_SOFT_TRG0_MASK)

#define AFE_CR_MSTR_EN_MASK                      (0x80000000U)
#define AFE_CR_MSTR_EN_SHIFT                     (31U)
/*! MSTR_EN - AFE Master Enable
 *  0b0..All ADCs are disabled.
 *  0b1..All ADCs and filters will get simultaneously enabled .
 */
#define AFE_CR_MSTR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << AFE_CR_MSTR_EN_SHIFT)) & AFE_CR_MSTR_EN_MASK)
/*! @} */

/*! @name CKR - Clock Configuration Register */
/*! @{ */

#define AFE_CKR_CLS_MASK                         (0x600000U)
#define AFE_CKR_CLS_SHIFT                        (21U)
/*! CLS - Clock Source Select
 *  0b00..mod_clk0
 *  0b01..mod_clk1
 *  0b10..mod_clk2
 *  0b11..mod_clk3
 */
#define AFE_CKR_CLS(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_CKR_CLS_SHIFT)) & AFE_CKR_CLS_MASK)

#define AFE_CKR_DIV_MASK                         (0xF0000000U)
#define AFE_CKR_DIV_SHIFT                        (28U)
/*! DIV - Clock Divider Select
 *  0b0000..divide by 1
 *  0b0001..divide by 2 (default)
 *  0b0010..divide by 4
 *  0b0011..divide by 8
 *  0b0100..divide by 16
 *  0b0101..divide by 32
 *  0b0110..divide by 64
 *  0b0111..divide by 128
 *  0b1xxx..divide by 256
 */
#define AFE_CKR_DIV(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_CKR_DIV_SHIFT)) & AFE_CKR_DIV_MASK)
/*! @} */

/*! @name DI - DMA and Interrupt Register */
/*! @{ */

#define AFE_DI_INTEN3_MASK                       (0x800000U)
#define AFE_DI_INTEN3_SHIFT                      (23U)
/*! INTEN3 - Interrupt Enable 3 */
#define AFE_DI_INTEN3(x)                         (((uint32_t)(((uint32_t)(x)) << AFE_DI_INTEN3_SHIFT)) & AFE_DI_INTEN3_MASK)

#define AFE_DI_INTEN2_MASK                       (0x1000000U)
#define AFE_DI_INTEN2_SHIFT                      (24U)
/*! INTEN2 - Interrupt Enable 2 */
#define AFE_DI_INTEN2(x)                         (((uint32_t)(((uint32_t)(x)) << AFE_DI_INTEN2_SHIFT)) & AFE_DI_INTEN2_MASK)

#define AFE_DI_INTEN1_MASK                       (0x2000000U)
#define AFE_DI_INTEN1_SHIFT                      (25U)
/*! INTEN1 - Interrupt Enable 1 */
#define AFE_DI_INTEN1(x)                         (((uint32_t)(((uint32_t)(x)) << AFE_DI_INTEN1_SHIFT)) & AFE_DI_INTEN1_MASK)

#define AFE_DI_INTEN0_MASK                       (0x4000000U)
#define AFE_DI_INTEN0_SHIFT                      (26U)
/*! INTEN0 - Interrupt Enable 0 */
#define AFE_DI_INTEN0(x)                         (((uint32_t)(((uint32_t)(x)) << AFE_DI_INTEN0_SHIFT)) & AFE_DI_INTEN0_MASK)

#define AFE_DI_DMAEN3_MASK                       (0x10000000U)
#define AFE_DI_DMAEN3_SHIFT                      (28U)
/*! DMAEN3 - DMA Enable3 */
#define AFE_DI_DMAEN3(x)                         (((uint32_t)(((uint32_t)(x)) << AFE_DI_DMAEN3_SHIFT)) & AFE_DI_DMAEN3_MASK)

#define AFE_DI_DMAEN2_MASK                       (0x20000000U)
#define AFE_DI_DMAEN2_SHIFT                      (29U)
/*! DMAEN2 - DMA Enable2 */
#define AFE_DI_DMAEN2(x)                         (((uint32_t)(((uint32_t)(x)) << AFE_DI_DMAEN2_SHIFT)) & AFE_DI_DMAEN2_MASK)

#define AFE_DI_DMAEN1_MASK                       (0x40000000U)
#define AFE_DI_DMAEN1_SHIFT                      (30U)
/*! DMAEN1 - DMA Enable1 */
#define AFE_DI_DMAEN1(x)                         (((uint32_t)(((uint32_t)(x)) << AFE_DI_DMAEN1_SHIFT)) & AFE_DI_DMAEN1_MASK)

#define AFE_DI_DMAEN0_MASK                       (0x80000000U)
#define AFE_DI_DMAEN0_SHIFT                      (31U)
/*! DMAEN0 - DMA Enable0 */
#define AFE_DI_DMAEN0(x)                         (((uint32_t)(((uint32_t)(x)) << AFE_DI_DMAEN0_SHIFT)) & AFE_DI_DMAEN0_MASK)
/*! @} */

/*! @name DR - Channel0 Delay Register..Channel3 Delay Register */
/*! @{ */

#define AFE_DR_DLY_MASK                          (0x7FFU)
#define AFE_DR_DLY_SHIFT                         (0U)
/*! DLY - Delay */
#define AFE_DR_DLY(x)                            (((uint32_t)(((uint32_t)(x)) << AFE_DR_DLY_SHIFT)) & AFE_DR_DLY_MASK)
/*! @} */

/*! @name RR - Channel0 Result Register..Channel3 Result Register */
/*! @{ */

#define AFE_RR_SDR_MASK                          (0x7FFFFFU)
#define AFE_RR_SDR_SHIFT                         (0U)
/*! SDR - Sample Data result */
#define AFE_RR_SDR(x)                            (((uint32_t)(((uint32_t)(x)) << AFE_RR_SDR_SHIFT)) & AFE_RR_SDR_MASK)

#define AFE_RR_SIGN_BITS_MASK                    (0xFF800000U)
#define AFE_RR_SIGN_BITS_SHIFT                   (23U)
/*! SIGN_BITS - Sign Bits */
#define AFE_RR_SIGN_BITS(x)                      (((uint32_t)(((uint32_t)(x)) << AFE_RR_SIGN_BITS_SHIFT)) & AFE_RR_SIGN_BITS_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define AFE_SR_RDY3_MASK                         (0x10000U)
#define AFE_SR_RDY3_SHIFT                        (16U)
/*! RDY3 - AFE Ready3
 *  0b0..AFE Channel3 is disabled or has not completed its start up period
 *  0b1..AFE Channel3 is ready to initiate conversions.
 */
#define AFE_SR_RDY3(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_RDY3_SHIFT)) & AFE_SR_RDY3_MASK)

#define AFE_SR_RDY2_MASK                         (0x20000U)
#define AFE_SR_RDY2_SHIFT                        (17U)
/*! RDY2 - AFE Ready2
 *  0b0..AFE Channel2 is disabled or has not completed its start up period
 *  0b1..AFE Channel2 is ready to initiate conversions.
 */
#define AFE_SR_RDY2(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_RDY2_SHIFT)) & AFE_SR_RDY2_MASK)

#define AFE_SR_RDY1_MASK                         (0x40000U)
#define AFE_SR_RDY1_SHIFT                        (18U)
/*! RDY1 - AFE Ready1
 *  0b0..AFE Channel1 is disabled or has not completed its start up period
 *  0b1..AFE Channel1 is ready to initiate conversions.
 */
#define AFE_SR_RDY1(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_RDY1_SHIFT)) & AFE_SR_RDY1_MASK)

#define AFE_SR_RDY0_MASK                         (0x80000U)
#define AFE_SR_RDY0_SHIFT                        (19U)
/*! RDY0 - AFE Ready0
 *  0b0..AFE Channel0 is disabled or has not completed its start up period
 *  0b1..AFE Channel0 is ready to initiate conversions.
 */
#define AFE_SR_RDY0(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_RDY0_SHIFT)) & AFE_SR_RDY0_MASK)

#define AFE_SR_OVR3_MASK                         (0x200000U)
#define AFE_SR_OVR3_SHIFT                        (21U)
/*! OVR3 - Overflow Flag */
#define AFE_SR_OVR3(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_OVR3_SHIFT)) & AFE_SR_OVR3_MASK)

#define AFE_SR_OVR2_MASK                         (0x400000U)
#define AFE_SR_OVR2_SHIFT                        (22U)
/*! OVR2 - Overflow Flag */
#define AFE_SR_OVR2(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_OVR2_SHIFT)) & AFE_SR_OVR2_MASK)

#define AFE_SR_OVR1_MASK                         (0x800000U)
#define AFE_SR_OVR1_SHIFT                        (23U)
/*! OVR1 - Overflow Flag */
#define AFE_SR_OVR1(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_OVR1_SHIFT)) & AFE_SR_OVR1_MASK)

#define AFE_SR_OVR0_MASK                         (0x1000000U)
#define AFE_SR_OVR0_SHIFT                        (24U)
/*! OVR0 - Overflow Flag */
#define AFE_SR_OVR0(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_OVR0_SHIFT)) & AFE_SR_OVR0_MASK)

#define AFE_SR_COC3_MASK                         (0x10000000U)
#define AFE_SR_COC3_SHIFT                        (28U)
/*! COC3 - Conversion Complete */
#define AFE_SR_COC3(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_COC3_SHIFT)) & AFE_SR_COC3_MASK)

#define AFE_SR_COC2_MASK                         (0x20000000U)
#define AFE_SR_COC2_SHIFT                        (29U)
/*! COC2 - Conversion Complete */
#define AFE_SR_COC2(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_COC2_SHIFT)) & AFE_SR_COC2_MASK)

#define AFE_SR_COC1_MASK                         (0x40000000U)
#define AFE_SR_COC1_SHIFT                        (30U)
/*! COC1 - Conversion Complete */
#define AFE_SR_COC1(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_COC1_SHIFT)) & AFE_SR_COC1_MASK)

#define AFE_SR_COC0_MASK                         (0x80000000U)
#define AFE_SR_COC0_SHIFT                        (31U)
/*! COC0 - Conversion Complete */
#define AFE_SR_COC0(x)                           (((uint32_t)(((uint32_t)(x)) << AFE_SR_COC0_SHIFT)) & AFE_SR_COC0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AFE_Register_Masks */


/*!
 * @}
 */ /* end of group AFE_Peripheral_Access_Layer */


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


#endif  /* PERI_AFE_H_ */

