/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CMP.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CMP
 *
 * CMSIS Peripheral Access Layer for CMP
 */

#if !defined(PERI_CMP_H_)
#define PERI_CMP_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- CMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Peripheral_Access_Layer CMP Peripheral Access Layer
 * @{
 */

/** CMP - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t C0;                                /**< CMP Control 0, offset: 0x8 */
  __IO uint32_t C1;                                /**< CMP Control 1, offset: 0xC */
  __IO uint32_t C2;                                /**< CMP Control 2, offset: 0x10 */
  __IO uint32_t C3;                                /**< CMP Control 3, offset: 0x14 */
} CMP_Type;

/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Register_Masks CMP Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define CMP_VERID_FEATURE_MASK                   (0xFFFFU)
#define CMP_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number */
#define CMP_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << CMP_VERID_FEATURE_SHIFT)) & CMP_VERID_FEATURE_MASK)

#define CMP_VERID_MINOR_MASK                     (0xFF0000U)
#define CMP_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define CMP_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << CMP_VERID_MINOR_SHIFT)) & CMP_VERID_MINOR_MASK)

#define CMP_VERID_MAJOR_MASK                     (0xFF000000U)
#define CMP_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define CMP_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << CMP_VERID_MAJOR_SHIFT)) & CMP_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define CMP_PARAM_PARAM_MASK                     (0xFFFFFFFFU)
#define CMP_PARAM_PARAM_SHIFT                    (0U)
/*! PARAM - Parameters */
#define CMP_PARAM_PARAM(x)                       (((uint32_t)(((uint32_t)(x)) << CMP_PARAM_PARAM_SHIFT)) & CMP_PARAM_PARAM_MASK)
/*! @} */

/*! @name C0 - CMP Control 0 */
/*! @{ */

#define CMP_C0_FILTER_CNT_MASK                   (0x70U)
#define CMP_C0_FILTER_CNT_SHIFT                  (4U)
/*! FILTER_CNT - Filter Sample Count
 *  0b000..Filter is disabled (if C0[SE] = 1, then COUT is a logic zero (this is not a legal state, and is not
 *         recommended); if C0[SE] = 0, COUT = COUTA)
 *  0b001..One consecutive sample (comparator output is simply sampled)
 *  0b010..Two consecutive samples
 *  0b011..Three consecutive samples
 *  0b100..Four consecutive samples
 *  0b101..Five consecutive samples
 *  0b110..Six consecutive samples
 *  0b111..Seven consecutive samples
 */
#define CMP_C0_FILTER_CNT(x)                     (((uint32_t)(((uint32_t)(x)) << CMP_C0_FILTER_CNT_SHIFT)) & CMP_C0_FILTER_CNT_MASK)

#define CMP_C0_EN_MASK                           (0x100U)
#define CMP_C0_EN_SHIFT                          (8U)
/*! EN - Analog Comparator Module Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C0_EN(x)                             (((uint32_t)(((uint32_t)(x)) << CMP_C0_EN_SHIFT)) & CMP_C0_EN_MASK)

#define CMP_C0_OPE_MASK                          (0x200U)
#define CMP_C0_OPE_SHIFT                         (9U)
/*! OPE - Comparator Output Pin Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C0_OPE(x)                            (((uint32_t)(((uint32_t)(x)) << CMP_C0_OPE_SHIFT)) & CMP_C0_OPE_MASK)

#define CMP_C0_COS_MASK                          (0x400U)
#define CMP_C0_COS_SHIFT                         (10U)
/*! COS - Comparator Output Select
 *  0b0..COUT
 *  0b1..COUTA
 */
#define CMP_C0_COS(x)                            (((uint32_t)(((uint32_t)(x)) << CMP_C0_COS_SHIFT)) & CMP_C0_COS_MASK)

#define CMP_C0_INVT_MASK                         (0x800U)
#define CMP_C0_INVT_SHIFT                        (11U)
/*! INVT - Comparator Invert
 *  0b0..Do not invert
 *  0b1..Invert
 */
#define CMP_C0_INVT(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C0_INVT_SHIFT)) & CMP_C0_INVT_MASK)

#define CMP_C0_PMODE_MASK                        (0x1000U)
#define CMP_C0_PMODE_SHIFT                       (12U)
/*! PMODE - Power Mode Select
 *  0b0..Low-speed (LS)
 *  0b1..High-speed (HS)
 */
#define CMP_C0_PMODE(x)                          (((uint32_t)(((uint32_t)(x)) << CMP_C0_PMODE_SHIFT)) & CMP_C0_PMODE_MASK)

#define CMP_C0_WE_MASK                           (0x4000U)
#define CMP_C0_WE_SHIFT                          (14U)
/*! WE - Windowing Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C0_WE(x)                             (((uint32_t)(((uint32_t)(x)) << CMP_C0_WE_SHIFT)) & CMP_C0_WE_MASK)

#define CMP_C0_SE_MASK                           (0x8000U)
#define CMP_C0_SE_SHIFT                          (15U)
/*! SE - Sample Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C0_SE(x)                             (((uint32_t)(((uint32_t)(x)) << CMP_C0_SE_SHIFT)) & CMP_C0_SE_MASK)

#define CMP_C0_FPR_MASK                          (0xFF0000U)
#define CMP_C0_FPR_SHIFT                         (16U)
/*! FPR - Filter Sample Period */
#define CMP_C0_FPR(x)                            (((uint32_t)(((uint32_t)(x)) << CMP_C0_FPR_SHIFT)) & CMP_C0_FPR_MASK)

#define CMP_C0_COUT_MASK                         (0x1000000U)
#define CMP_C0_COUT_SHIFT                        (24U)
/*! COUT - Analog Comparator Output */
#define CMP_C0_COUT(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C0_COUT_SHIFT)) & CMP_C0_COUT_MASK)

#define CMP_C0_CFF_MASK                          (0x2000000U)
#define CMP_C0_CFF_SHIFT                         (25U)
/*! CFF - Analog Comparator Flag Falling
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define CMP_C0_CFF(x)                            (((uint32_t)(((uint32_t)(x)) << CMP_C0_CFF_SHIFT)) & CMP_C0_CFF_MASK)

#define CMP_C0_CFR_MASK                          (0x4000000U)
#define CMP_C0_CFR_SHIFT                         (26U)
/*! CFR - Analog Comparator Flag Rising
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define CMP_C0_CFR(x)                            (((uint32_t)(((uint32_t)(x)) << CMP_C0_CFR_SHIFT)) & CMP_C0_CFR_MASK)

#define CMP_C0_IEF_MASK                          (0x8000000U)
#define CMP_C0_IEF_SHIFT                         (27U)
/*! IEF - Comparator Interrupt Enable Falling
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C0_IEF(x)                            (((uint32_t)(((uint32_t)(x)) << CMP_C0_IEF_SHIFT)) & CMP_C0_IEF_MASK)

#define CMP_C0_IER_MASK                          (0x10000000U)
#define CMP_C0_IER_SHIFT                         (28U)
/*! IER - Comparator Interrupt Enable Rising
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C0_IER(x)                            (((uint32_t)(((uint32_t)(x)) << CMP_C0_IER_SHIFT)) & CMP_C0_IER_MASK)

#define CMP_C0_DMAEN_MASK                        (0x40000000U)
#define CMP_C0_DMAEN_SHIFT                       (30U)
/*! DMAEN - DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C0_DMAEN(x)                          (((uint32_t)(((uint32_t)(x)) << CMP_C0_DMAEN_SHIFT)) & CMP_C0_DMAEN_MASK)

#define CMP_C0_LINKEN_MASK                       (0x80000000U)
#define CMP_C0_LINKEN_SHIFT                      (31U)
/*! LINKEN - CMP to DAC Link Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C0_LINKEN(x)                         (((uint32_t)(((uint32_t)(x)) << CMP_C0_LINKEN_SHIFT)) & CMP_C0_LINKEN_MASK)
/*! @} */

/*! @name C1 - CMP Control 1 */
/*! @{ */

#define CMP_C1_VOSEL_MASK                        (0xFFU)
#define CMP_C1_VOSEL_SHIFT                       (0U)
/*! VOSEL - DAC Output Voltage Select */
#define CMP_C1_VOSEL(x)                          (((uint32_t)(((uint32_t)(x)) << CMP_C1_VOSEL_SHIFT)) & CMP_C1_VOSEL_MASK)

#define CMP_C1_DMODE_MASK                        (0x100U)
#define CMP_C1_DMODE_SHIFT                       (8U)
/*! DMODE - DAC Mode Select
 *  0b0..Low-Speed and Low-Power mode
 *  0b1..High-Speed and High-Power mode
 */
#define CMP_C1_DMODE(x)                          (((uint32_t)(((uint32_t)(x)) << CMP_C1_DMODE_SHIFT)) & CMP_C1_DMODE_MASK)

#define CMP_C1_VRSEL_MASK                        (0x200U)
#define CMP_C1_VRSEL_SHIFT                       (9U)
/*! VRSEL - Supply Voltage Reference Source Select
 *  0b0..Vin1
 *  0b1..Vin2
 */
#define CMP_C1_VRSEL(x)                          (((uint32_t)(((uint32_t)(x)) << CMP_C1_VRSEL_SHIFT)) & CMP_C1_VRSEL_MASK)

#define CMP_C1_DACEN_MASK                        (0x400U)
#define CMP_C1_DACEN_SHIFT                       (10U)
/*! DACEN - DAC Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C1_DACEN(x)                          (((uint32_t)(((uint32_t)(x)) << CMP_C1_DACEN_SHIFT)) & CMP_C1_DACEN_MASK)

#define CMP_C1_CHN0_MASK                         (0x10000U)
#define CMP_C1_CHN0_SHIFT                        (16U)
/*! CHN0 - Channel 0 Input Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C1_CHN0(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C1_CHN0_SHIFT)) & CMP_C1_CHN0_MASK)

#define CMP_C1_CHN1_MASK                         (0x20000U)
#define CMP_C1_CHN1_SHIFT                        (17U)
/*! CHN1 - Channel 1 Input Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C1_CHN1(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C1_CHN1_SHIFT)) & CMP_C1_CHN1_MASK)

#define CMP_C1_CHN2_MASK                         (0x40000U)
#define CMP_C1_CHN2_SHIFT                        (18U)
/*! CHN2 - Channel 2 Input Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C1_CHN2(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C1_CHN2_SHIFT)) & CMP_C1_CHN2_MASK)

#define CMP_C1_CHN3_MASK                         (0x80000U)
#define CMP_C1_CHN3_SHIFT                        (19U)
/*! CHN3 - Channel 3 Input Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C1_CHN3(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C1_CHN3_SHIFT)) & CMP_C1_CHN3_MASK)

#define CMP_C1_CHN4_MASK                         (0x100000U)
#define CMP_C1_CHN4_SHIFT                        (20U)
/*! CHN4 - Channel 4 Input Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C1_CHN4(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C1_CHN4_SHIFT)) & CMP_C1_CHN4_MASK)

#define CMP_C1_CHN5_MASK                         (0x200000U)
#define CMP_C1_CHN5_SHIFT                        (21U)
/*! CHN5 - Channel 5 Input Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C1_CHN5(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C1_CHN5_SHIFT)) & CMP_C1_CHN5_MASK)

#define CMP_C1_MSEL_MASK                         (0x7000000U)
#define CMP_C1_MSEL_SHIFT                        (24U)
/*! MSEL - Minus Input MUX Control
 *  0b000..Internal negative input 0 for minus channel (internal minus input)
 *  0b001..External input 1 for minus channel (reference input 0)
 *  0b010..External input 2 for minus channel (reference input 1)
 *  0b011..External input 3 for minus channel (reference input 2)
 *  0b100..External input 4 for minus channel (reference input 3)
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Internal 8-bit DAC output
 */
#define CMP_C1_MSEL(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C1_MSEL_SHIFT)) & CMP_C1_MSEL_MASK)

#define CMP_C1_PSEL_MASK                         (0x70000000U)
#define CMP_C1_PSEL_SHIFT                        (28U)
/*! PSEL - Plus Input MUX Control
 *  0b000..Internal positive input 0 for plus channel (internal plus input)
 *  0b001..External input 1 for plus Channel (reference input 0)
 *  0b010..External input 2 for plus channel (reference input 1)
 *  0b011..External input 3 for plus channel (reference input 2)
 *  0b100..External input 4 for plus channel (reference input 3)
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Internal 8-bit DAC output
 */
#define CMP_C1_PSEL(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C1_PSEL_SHIFT)) & CMP_C1_PSEL_MASK)
/*! @} */

/*! @name C2 - CMP Control 2 */
/*! @{ */

#define CMP_C2_ACOn_MASK                         (0x3FU)
#define CMP_C2_ACOn_SHIFT                        (0U)
/*! ACOn - ACOn */
#define CMP_C2_ACOn(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C2_ACOn_SHIFT)) & CMP_C2_ACOn_MASK)

#define CMP_C2_INITMOD_MASK                      (0x3F00U)
#define CMP_C2_INITMOD_SHIFT                     (8U)
/*! INITMOD - Comparator and DAC Initialization Delay Modulus */
#define CMP_C2_INITMOD(x)                        (((uint32_t)(((uint32_t)(x)) << CMP_C2_INITMOD_SHIFT)) & CMP_C2_INITMOD_MASK)

#define CMP_C2_NSAM_MASK                         (0xC000U)
#define CMP_C2_NSAM_SHIFT                        (14U)
/*! NSAM - Number of Sample Clocks
 *  0b00..As soon as the active channel is scanned in one round-robin clock
 *  0b01..After one round-robin clock cycle
 *  0b10..After two round-robin clock cycles
 *  0b11..After three round-robin clock cycles
 */
#define CMP_C2_NSAM(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C2_NSAM_SHIFT)) & CMP_C2_NSAM_MASK)

#define CMP_C2_CH0F_MASK                         (0x10000U)
#define CMP_C2_CH0F_SHIFT                        (16U)
/*! CH0F - External Channel 0 Input Changed Flag */
#define CMP_C2_CH0F(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C2_CH0F_SHIFT)) & CMP_C2_CH0F_MASK)

#define CMP_C2_CH1F_MASK                         (0x20000U)
#define CMP_C2_CH1F_SHIFT                        (17U)
/*! CH1F - External Channel 1 Input Changed Flag */
#define CMP_C2_CH1F(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C2_CH1F_SHIFT)) & CMP_C2_CH1F_MASK)

#define CMP_C2_CH2F_MASK                         (0x40000U)
#define CMP_C2_CH2F_SHIFT                        (18U)
/*! CH2F - External Channel 2 Input Changed Flag */
#define CMP_C2_CH2F(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C2_CH2F_SHIFT)) & CMP_C2_CH2F_MASK)

#define CMP_C2_CH3F_MASK                         (0x80000U)
#define CMP_C2_CH3F_SHIFT                        (19U)
/*! CH3F - External Channel 3 Input Changed Flag */
#define CMP_C2_CH3F(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C2_CH3F_SHIFT)) & CMP_C2_CH3F_MASK)

#define CMP_C2_CH4F_MASK                         (0x100000U)
#define CMP_C2_CH4F_SHIFT                        (20U)
/*! CH4F - External Channel 4 Input Changed Flag */
#define CMP_C2_CH4F(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C2_CH4F_SHIFT)) & CMP_C2_CH4F_MASK)

#define CMP_C2_CH5F_MASK                         (0x200000U)
#define CMP_C2_CH5F_SHIFT                        (21U)
/*! CH5F - External Channel 5 Input Changed Flag */
#define CMP_C2_CH5F(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C2_CH5F_SHIFT)) & CMP_C2_CH5F_MASK)

#define CMP_C2_FXMXCH_MASK                       (0xE000000U)
#define CMP_C2_FXMXCH_SHIFT                      (25U)
/*! FXMXCH - Fixed Channel Select
 *  0b000..External reference input 0
 *  0b001..External reference input 1
 *  0b010..External reference input 2
 *  0b011..External reference input 3
 *  0b100..External reference input 4
 *  0b101..External reference input 5
 *  0b110..Reserved
 *  0b111..8-bit DAC
 */
#define CMP_C2_FXMXCH(x)                         (((uint32_t)(((uint32_t)(x)) << CMP_C2_FXMXCH_SHIFT)) & CMP_C2_FXMXCH_MASK)

#define CMP_C2_FXMP_MASK                         (0x20000000U)
#define CMP_C2_FXMP_SHIFT                        (29U)
/*! FXMP - Fixed MUX Port
 *  0b0..Fix plus port
 *  0b1..Fix minus port
 */
#define CMP_C2_FXMP(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C2_FXMP_SHIFT)) & CMP_C2_FXMP_MASK)

#define CMP_C2_RRIE_MASK                         (0x40000000U)
#define CMP_C2_RRIE_SHIFT                        (30U)
/*! RRIE - Round-Robin Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C2_RRIE(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C2_RRIE_SHIFT)) & CMP_C2_RRIE_MASK)
/*! @} */

/*! @name C3 - CMP Control 3 */
/*! @{ */

#define CMP_C3_ACPH2TC_MASK                      (0x70U)
#define CMP_C3_ACPH2TC_SHIFT                     (4U)
/*! ACPH2TC - Analog Comparator Phase 2 Timing Control
 *  0b000..Phase 2 active time in one sampling period equals to T
 *  0b001..Phase 2 active time in one sampling period equals to 2 * T
 *  0b010..Phase 2 active time in one sampling period equals to 4 * T
 *  0b011..Phase 2 active time in one sampling period equals to 8 * T
 *  0b100..Phase 2 active time in one sampling period equals to 16 * T
 *  0b101..Phase 2 active time in one sampling period equals to 32 * T
 *  0b110..Phase 2 active time in one sampling period equals to 64 * T
 *  0b111..Phase 2 active time in one sampling period equals to 16 * T
 */
#define CMP_C3_ACPH2TC(x)                        (((uint32_t)(((uint32_t)(x)) << CMP_C3_ACPH2TC_SHIFT)) & CMP_C3_ACPH2TC_MASK)

#define CMP_C3_ACPH1TC_MASK                      (0x700U)
#define CMP_C3_ACPH1TC_SHIFT                     (8U)
/*! ACPH1TC - Analog Comparator Phase 1 Timing Control
 *  0b000..Phase 1 active time in one sampling period equals to T
 *  0b001..Phase 1 active time in one sampling period equals to 2 * T
 *  0b010..Phase 1 active time in one sampling period equals to 4 * T
 *  0b011..Phase 1 active time in one sampling period equals to 8 * T
 *  0b100..Phase 1 active time in one sampling period equals to T
 *  0b101..Phase 1 active time in one sampling period equals to T
 *  0b110..Phase 1 active time in one sampling period equals to T
 *  0b111..Phase 1 active time in one sampling period equals to 0
 */
#define CMP_C3_ACPH1TC(x)                        (((uint32_t)(((uint32_t)(x)) << CMP_C3_ACPH1TC_SHIFT)) & CMP_C3_ACPH1TC_MASK)

#define CMP_C3_ACSAT_MASK                        (0x7000U)
#define CMP_C3_ACSAT_SHIFT                       (12U)
/*! ACSAT - Analog Comparator Sampling Time Control
 *  0b000..The sampling time equals to T
 *  0b001..The sampling time equals to 2 * T
 *  0b010..The sampling time equals to 4 * T
 *  0b011..The sampling time equals to 8 * T
 *  0b100..The sampling time equals to 16 * T
 *  0b101..The sampling time equals to 32 * T
 *  0b110..The sampling time equals to 64 * T
 *  0b111..The sampling time equals to 256 * T
 */
#define CMP_C3_ACSAT(x)                          (((uint32_t)(((uint32_t)(x)) << CMP_C3_ACSAT_SHIFT)) & CMP_C3_ACSAT_MASK)

#define CMP_C3_DMCS_MASK                         (0x10000U)
#define CMP_C3_DMCS_SHIFT                        (16U)
/*! DMCS - Discrete Mode Clock Select
 *  0b0..Slow clock is selected for the timing generation.
 *  0b1..Fast clock is selected for the timing generation.
 */
#define CMP_C3_DMCS(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C3_DMCS_SHIFT)) & CMP_C3_DMCS_MASK)

#define CMP_C3_RDIVE_MASK                        (0x100000U)
#define CMP_C3_RDIVE_SHIFT                       (20U)
/*! RDIVE - Resistor Divider Enable
 *  0b0..Disable even when either NCHEN or PCHEN is set to1 but the actual input is in the range of 0 to 1.8v.
 *  0b1..Enable because the inputs are above 1.8v.
 */
#define CMP_C3_RDIVE(x)                          (((uint32_t)(((uint32_t)(x)) << CMP_C3_RDIVE_SHIFT)) & CMP_C3_RDIVE_MASK)

#define CMP_C3_NCHCTEN_MASK                      (0x1000000U)
#define CMP_C3_NCHCTEN_SHIFT                     (24U)
/*! NCHCTEN - Negative Channel Continuous Mode Enable
 *  0b0..in Discrete Mode and special timing needs to be configured.
 *  0b1..in Continuous Mode and no special timing is required.
 */
#define CMP_C3_NCHCTEN(x)                        (((uint32_t)(((uint32_t)(x)) << CMP_C3_NCHCTEN_SHIFT)) & CMP_C3_NCHCTEN_MASK)

#define CMP_C3_PCHCTEN_MASK                      (0x10000000U)
#define CMP_C3_PCHCTEN_SHIFT                     (28U)
/*! PCHCTEN - Positive Channel Continuous Mode Enable
 *  0b0..in Discrete Mode and special timing needs to be configured
 *  0b1..in Continuous Mode and no special timing is required
 */
#define CMP_C3_PCHCTEN(x)                        (((uint32_t)(((uint32_t)(x)) << CMP_C3_PCHCTEN_SHIFT)) & CMP_C3_PCHCTEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CMP_Register_Masks */


/*!
 * @}
 */ /* end of group CMP_Peripheral_Access_Layer */


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


#endif  /* PERI_CMP_H_ */

