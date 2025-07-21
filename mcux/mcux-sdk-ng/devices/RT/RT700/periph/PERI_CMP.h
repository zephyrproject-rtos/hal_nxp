/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
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
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
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

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
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
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t C0;                                /**< CMP Control 0, offset: 0x8 */
  __IO uint32_t C1;                                /**< CMP Control 1, offset: 0xC */
       uint8_t RESERVED_0[4];
  __IO uint32_t C3;                                /**< CMP Control 3, offset: 0x14 */
} CMP_Type;

/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Register_Masks CMP Register Masks
 * @{
 */

/*! @name VERID - Version ID */
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

/*! @name PARAM - Parameter */
/*! @{ */

#define CMP_PARAM_PARAM_MASK                     (0xFFFFFFFFU)
#define CMP_PARAM_PARAM_SHIFT                    (0U)
/*! PARAM - Parameters */
#define CMP_PARAM_PARAM(x)                       (((uint32_t)(((uint32_t)(x)) << CMP_PARAM_PARAM_SHIFT)) & CMP_PARAM_PARAM_MASK)
/*! @} */

/*! @name C0 - CMP Control 0 */
/*! @{ */

#define CMP_C0_HYSTCTR_MASK                      (0x3U)
#define CMP_C0_HYSTCTR_SHIFT                     (0U)
/*! HYSTCTR - Comparator Hard Block Hysteresis Control
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define CMP_C0_HYSTCTR(x)                        (((uint32_t)(((uint32_t)(x)) << CMP_C0_HYSTCTR_SHIFT)) & CMP_C0_HYSTCTR_MASK)

#define CMP_C0_FILTER_CNT_MASK                   (0x70U)
#define CMP_C0_FILTER_CNT_SHIFT                  (4U)
/*! FILTER_CNT - Filter Sample Count
 *  0b000..Filter is disabled
 *  0b001..One consecutive sample
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

#define CMP_C1_MSEL_MASK                         (0x7000000U)
#define CMP_C1_MSEL_SHIFT                        (24U)
/*! MSEL - Minus Input MUX Control
 *  0b000..Internal negative input 0 for minus channel (internal minus input)
 *  0b001..External input 1 for minus channel (INA_1P8[1])
 *  0b010..External input 2 for minus channel (INA_1P8[2])
 *  0b011..External input 3 for minus channel (INA_1P8[3])
 *  0b100..External input 4 for minus channel (INA_1P8[4])
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Internal 8-bit DAC output
 */
#define CMP_C1_MSEL(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C1_MSEL_SHIFT)) & CMP_C1_MSEL_MASK)

#define CMP_C1_PSEL_MASK                         (0x70000000U)
#define CMP_C1_PSEL_SHIFT                        (28U)
/*! PSEL - Plus Input MUX Control
 *  0b000..Internal positive input 0 for plus channel (internal plus input)
 *  0b001..External input 1 for plus channel (INA_1P8[1])
 *  0b010..External input 2 for plus channel (INA_1P8[2])
 *  0b011..External input 3 for plus channel (INA_1P8[3])
 *  0b100..External input 4 for plus channel (INA_1P8[4])
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Internal 8-bit DAC output
 */
#define CMP_C1_PSEL(x)                           (((uint32_t)(((uint32_t)(x)) << CMP_C1_PSEL_SHIFT)) & CMP_C1_PSEL_MASK)
/*! @} */

/*! @name C3 - CMP Control 3 */
/*! @{ */

#define CMP_C3_NCHCTEN_MASK                      (0x1000000U)
#define CMP_C3_NCHCTEN_SHIFT                     (24U)
/*! NCHCTEN - Negative Channel Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CMP_C3_NCHCTEN(x)                        (((uint32_t)(((uint32_t)(x)) << CMP_C3_NCHCTEN_SHIFT)) & CMP_C3_NCHCTEN_MASK)

#define CMP_C3_PCHCTEN_MASK                      (0x10000000U)
#define CMP_C3_PCHCTEN_SHIFT                     (28U)
/*! PCHCTEN - Positive Channel Enable
 *  0b0..Disable
 *  0b1..Enable
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_CMP_H_ */

