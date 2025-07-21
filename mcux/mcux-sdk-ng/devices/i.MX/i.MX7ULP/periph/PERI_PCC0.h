/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PCC0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PCC0.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC0
 *
 * CMSIS Peripheral Access Layer for PCC0
 */

#if !defined(PERI_PCC0_H_)
#define PERI_PCC0_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- PCC0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC0_Peripheral_Access_Layer PCC0 Peripheral Access Layer
 * @{
 */

/** PCC0 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t PCC_DMA0;                          /**< PCC DMA0 Register, offset: 0x20 */
       uint8_t RESERVED_1[24];
  __IO uint32_t PCC_RGPIO2P0;                      /**< PCC RGPIO2P0 Register, offset: 0x3C */
       uint8_t RESERVED_2[16];
  __IO uint32_t PCC_XRDC;                          /**< PCC XRDC Register, offset: 0x50 */
       uint8_t RESERVED_3[24];
  __IO uint32_t PCC_SEMA42_0;                      /**< PCC SEMA42_0 Register, offset: 0x6C */
       uint8_t RESERVED_4[16];
  __IO uint32_t PCC_DMA_MUX0;                      /**< PCC DMA_MUX0 Register, offset: 0x80 */
       uint8_t RESERVED_5[4];
  __IO uint32_t PCC_MU_A;                          /**< PCC MU_A Register, offset: 0x88 */
       uint8_t RESERVED_6[8];
  __IO uint32_t PCC_WDOG0;                         /**< PCC WDOG0 Register, offset: 0x94 */
       uint8_t RESERVED_7[12];
  __IO uint32_t PCC_CRC;                           /**< PCC CRC Register, offset: 0xA4 */
  __IO uint32_t PCC_LTC;                           /**< PCC LTC Register, offset: 0xA8 */
       uint8_t RESERVED_8[4];
  __IO uint32_t PCC_TRNG;                          /**< PCC TRNG Register, offset: 0xB0 */
  __IO uint32_t PCC_LPIT0;                         /**< PCC LPIT0 Register, offset: 0xB4 */
  __IO uint32_t PCC_LPTIMER0;                      /**< PCC LPTIMER0 Register, offset: 0xB8 */
  __IO uint32_t PCC_LPTIMER1;                      /**< PCC LPTIMER1 Register, offset: 0xBC */
  __IO uint32_t PCC_TPM0;                          /**< PCC TPM0 Register, offset: 0xC0 */
  __IO uint32_t PCC_TPM1;                          /**< PCC TPM1 Register, offset: 0xC4 */
  __IO uint32_t PCC_FLEXIO0;                       /**< PCC FLEXIO0 Register, offset: 0xC8 */
  __IO uint32_t PCC_LPI2C0;                        /**< PCC LPI2C0 Register, offset: 0xCC */
  __IO uint32_t PCC_LPI2C1;                        /**< PCC LPI2C1 Register, offset: 0xD0 */
  __IO uint32_t PCC_LPI2C2;                        /**< PCC LPI2C2 Register, offset: 0xD4 */
  __IO uint32_t PCC_LPI2C3;                        /**< PCC LPI2C3 Register, offset: 0xD8 */
  __IO uint32_t PCC_SAI0;                          /**< PCC SAI0 Register, offset: 0xDC */
  __IO uint32_t PCC_LPSPI0;                        /**< PCC LPSPI0 Register, offset: 0xE0 */
  __IO uint32_t PCC_LPSPI1;                        /**< PCC LPSPI1 Register, offset: 0xE4 */
  __IO uint32_t PCC_LPUART0;                       /**< PCC LPUART0 Register, offset: 0xE8 */
  __IO uint32_t PCC_LPUART1;                       /**< PCC LPUART1 Register, offset: 0xEC */
       uint8_t RESERVED_9[12];
  __IO uint32_t PCC_PCTLA;                         /**< PCC PCTLA Register, offset: 0xFC */
  __IO uint32_t PCC_PCTLB;                         /**< PCC PCTLB Register, offset: 0x100 */
  __IO uint32_t PCC_ADC0;                          /**< PCC ADC0 Register, offset: 0x104 */
  __IO uint32_t PCC_CMP0;                          /**< PCC CMP0 Register, offset: 0x108 */
  __IO uint32_t PCC_CMP1;                          /**< PCC CMP1 Register, offset: 0x10C */
  __IO uint32_t PCC_DAC0;                          /**< PCC DAC0 Register, offset: 0x110 */
  __IO uint32_t PCC_DAC1;                          /**< PCC DAC1 Register, offset: 0x114 */
       uint8_t RESERVED_10[168];
  __IO uint32_t PCC_SNVS;                          /**< PCC SNVS Register, offset: 0x1C0 */
} PCC0_Type;

/* ----------------------------------------------------------------------------
   -- PCC0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC0_Register_Masks PCC0 Register Masks
 * @{
 */

/*! @name PCC_DMA0 - PCC DMA0 Register */
/*! @{ */

#define PCC0_PCC_DMA0_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_DMA0_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_DMA0_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_INUSE_SHIFT)) & PCC0_PCC_DMA0_INUSE_MASK)

#define PCC0_PCC_DMA0_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_DMA0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_CGC_SHIFT)) & PCC0_PCC_DMA0_CGC_MASK)

#define PCC0_PCC_DMA0_PR_MASK                    (0x80000000U)
#define PCC0_PCC_DMA0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA0_PR_SHIFT)) & PCC0_PCC_DMA0_PR_MASK)
/*! @} */

/*! @name PCC_RGPIO2P0 - PCC RGPIO2P0 Register */
/*! @{ */

#define PCC0_PCC_RGPIO2P0_INUSE_MASK             (0x20000000U)
#define PCC0_PCC_RGPIO2P0_INUSE_SHIFT            (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_RGPIO2P0_INUSE(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_RGPIO2P0_INUSE_SHIFT)) & PCC0_PCC_RGPIO2P0_INUSE_MASK)

#define PCC0_PCC_RGPIO2P0_CGC_MASK               (0x40000000U)
#define PCC0_PCC_RGPIO2P0_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_RGPIO2P0_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_RGPIO2P0_CGC_SHIFT)) & PCC0_PCC_RGPIO2P0_CGC_MASK)

#define PCC0_PCC_RGPIO2P0_PR_MASK                (0x80000000U)
#define PCC0_PCC_RGPIO2P0_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_RGPIO2P0_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_RGPIO2P0_PR_SHIFT)) & PCC0_PCC_RGPIO2P0_PR_MASK)
/*! @} */

/*! @name PCC_XRDC - PCC XRDC Register */
/*! @{ */

#define PCC0_PCC_XRDC_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_XRDC_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_XRDC_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_XRDC_INUSE_SHIFT)) & PCC0_PCC_XRDC_INUSE_MASK)

#define PCC0_PCC_XRDC_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_XRDC_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_XRDC_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_XRDC_CGC_SHIFT)) & PCC0_PCC_XRDC_CGC_MASK)

#define PCC0_PCC_XRDC_PR_MASK                    (0x80000000U)
#define PCC0_PCC_XRDC_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_XRDC_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_XRDC_PR_SHIFT)) & PCC0_PCC_XRDC_PR_MASK)
/*! @} */

/*! @name PCC_SEMA42_0 - PCC SEMA42_0 Register */
/*! @{ */

#define PCC0_PCC_SEMA42_0_INUSE_MASK             (0x20000000U)
#define PCC0_PCC_SEMA42_0_INUSE_SHIFT            (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_SEMA42_0_INUSE(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SEMA42_0_INUSE_SHIFT)) & PCC0_PCC_SEMA42_0_INUSE_MASK)

#define PCC0_PCC_SEMA42_0_CGC_MASK               (0x40000000U)
#define PCC0_PCC_SEMA42_0_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_SEMA42_0_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SEMA42_0_CGC_SHIFT)) & PCC0_PCC_SEMA42_0_CGC_MASK)

#define PCC0_PCC_SEMA42_0_PR_MASK                (0x80000000U)
#define PCC0_PCC_SEMA42_0_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_SEMA42_0_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SEMA42_0_PR_SHIFT)) & PCC0_PCC_SEMA42_0_PR_MASK)
/*! @} */

/*! @name PCC_DMA_MUX0 - PCC DMA_MUX0 Register */
/*! @{ */

#define PCC0_PCC_DMA_MUX0_INUSE_MASK             (0x20000000U)
#define PCC0_PCC_DMA_MUX0_INUSE_SHIFT            (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_DMA_MUX0_INUSE(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA_MUX0_INUSE_SHIFT)) & PCC0_PCC_DMA_MUX0_INUSE_MASK)

#define PCC0_PCC_DMA_MUX0_CGC_MASK               (0x40000000U)
#define PCC0_PCC_DMA_MUX0_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DMA_MUX0_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA_MUX0_CGC_SHIFT)) & PCC0_PCC_DMA_MUX0_CGC_MASK)

#define PCC0_PCC_DMA_MUX0_PR_MASK                (0x80000000U)
#define PCC0_PCC_DMA_MUX0_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DMA_MUX0_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DMA_MUX0_PR_SHIFT)) & PCC0_PCC_DMA_MUX0_PR_MASK)
/*! @} */

/*! @name PCC_MU_A - PCC MU_A Register */
/*! @{ */

#define PCC0_PCC_MU_A_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_MU_A_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_MU_A_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU_A_INUSE_SHIFT)) & PCC0_PCC_MU_A_INUSE_MASK)

#define PCC0_PCC_MU_A_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_MU_A_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_MU_A_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU_A_CGC_SHIFT)) & PCC0_PCC_MU_A_CGC_MASK)

#define PCC0_PCC_MU_A_PR_MASK                    (0x80000000U)
#define PCC0_PCC_MU_A_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_MU_A_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_MU_A_PR_SHIFT)) & PCC0_PCC_MU_A_PR_MASK)
/*! @} */

/*! @name PCC_WDOG0 - PCC WDOG0 Register */
/*! @{ */

#define PCC0_PCC_WDOG0_PCD_MASK                  (0x7U)
#define PCC0_PCC_WDOG0_PCD_SHIFT                 (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC0_PCC_WDOG0_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_PCD_SHIFT)) & PCC0_PCC_WDOG0_PCD_MASK)

#define PCC0_PCC_WDOG0_FRAC_MASK                 (0x8U)
#define PCC0_PCC_WDOG0_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_WDOG0_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_FRAC_SHIFT)) & PCC0_PCC_WDOG0_FRAC_MASK)

#define PCC0_PCC_WDOG0_PCS_MASK                  (0x7000000U)
#define PCC0_PCC_WDOG0_PCS_SHIFT                 (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_WDOG0_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_PCS_SHIFT)) & PCC0_PCC_WDOG0_PCS_MASK)

#define PCC0_PCC_WDOG0_INUSE_MASK                (0x20000000U)
#define PCC0_PCC_WDOG0_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_WDOG0_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_INUSE_SHIFT)) & PCC0_PCC_WDOG0_INUSE_MASK)

#define PCC0_PCC_WDOG0_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_WDOG0_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_WDOG0_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_CGC_SHIFT)) & PCC0_PCC_WDOG0_CGC_MASK)

#define PCC0_PCC_WDOG0_PR_MASK                   (0x80000000U)
#define PCC0_PCC_WDOG0_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_WDOG0_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_WDOG0_PR_SHIFT)) & PCC0_PCC_WDOG0_PR_MASK)
/*! @} */

/*! @name PCC_CRC - PCC CRC Register */
/*! @{ */

#define PCC0_PCC_CRC_INUSE_MASK                  (0x20000000U)
#define PCC0_PCC_CRC_INUSE_SHIFT                 (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_CRC_INUSE(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CRC_INUSE_SHIFT)) & PCC0_PCC_CRC_INUSE_MASK)

#define PCC0_PCC_CRC_CGC_MASK                    (0x40000000U)
#define PCC0_PCC_CRC_CGC_SHIFT                   (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_CRC_CGC(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CRC_CGC_SHIFT)) & PCC0_PCC_CRC_CGC_MASK)

#define PCC0_PCC_CRC_PR_MASK                     (0x80000000U)
#define PCC0_PCC_CRC_PR_SHIFT                    (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_CRC_PR(x)                       (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CRC_PR_SHIFT)) & PCC0_PCC_CRC_PR_MASK)
/*! @} */

/*! @name PCC_LTC - PCC LTC Register */
/*! @{ */

#define PCC0_PCC_LTC_INUSE_MASK                  (0x20000000U)
#define PCC0_PCC_LTC_INUSE_SHIFT                 (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LTC_INUSE(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LTC_INUSE_SHIFT)) & PCC0_PCC_LTC_INUSE_MASK)

#define PCC0_PCC_LTC_CGC_MASK                    (0x40000000U)
#define PCC0_PCC_LTC_CGC_SHIFT                   (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LTC_CGC(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LTC_CGC_SHIFT)) & PCC0_PCC_LTC_CGC_MASK)

#define PCC0_PCC_LTC_PR_MASK                     (0x80000000U)
#define PCC0_PCC_LTC_PR_SHIFT                    (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LTC_PR(x)                       (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LTC_PR_SHIFT)) & PCC0_PCC_LTC_PR_MASK)
/*! @} */

/*! @name PCC_TRNG - PCC TRNG Register */
/*! @{ */

#define PCC0_PCC_TRNG_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_TRNG_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_TRNG_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRNG_INUSE_SHIFT)) & PCC0_PCC_TRNG_INUSE_MASK)

#define PCC0_PCC_TRNG_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_TRNG_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_TRNG_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRNG_CGC_SHIFT)) & PCC0_PCC_TRNG_CGC_MASK)

#define PCC0_PCC_TRNG_PR_MASK                    (0x80000000U)
#define PCC0_PCC_TRNG_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_TRNG_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TRNG_PR_SHIFT)) & PCC0_PCC_TRNG_PR_MASK)
/*! @} */

/*! @name PCC_LPIT0 - PCC LPIT0 Register */
/*! @{ */

#define PCC0_PCC_LPIT0_PCS_MASK                  (0x7000000U)
#define PCC0_PCC_LPIT0_PCS_SHIFT                 (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_LPIT0_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPIT0_PCS_SHIFT)) & PCC0_PCC_LPIT0_PCS_MASK)

#define PCC0_PCC_LPIT0_INUSE_MASK                (0x20000000U)
#define PCC0_PCC_LPIT0_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LPIT0_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPIT0_INUSE_SHIFT)) & PCC0_PCC_LPIT0_INUSE_MASK)

#define PCC0_PCC_LPIT0_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_LPIT0_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPIT0_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPIT0_CGC_SHIFT)) & PCC0_PCC_LPIT0_CGC_MASK)

#define PCC0_PCC_LPIT0_PR_MASK                   (0x80000000U)
#define PCC0_PCC_LPIT0_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPIT0_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPIT0_PR_SHIFT)) & PCC0_PCC_LPIT0_PR_MASK)
/*! @} */

/*! @name PCC_LPTIMER0 - PCC LPTIMER0 Register */
/*! @{ */

#define PCC0_PCC_LPTIMER0_INUSE_MASK             (0x20000000U)
#define PCC0_PCC_LPTIMER0_INUSE_SHIFT            (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LPTIMER0_INUSE(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPTIMER0_INUSE_SHIFT)) & PCC0_PCC_LPTIMER0_INUSE_MASK)

#define PCC0_PCC_LPTIMER0_CGC_MASK               (0x40000000U)
#define PCC0_PCC_LPTIMER0_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPTIMER0_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPTIMER0_CGC_SHIFT)) & PCC0_PCC_LPTIMER0_CGC_MASK)

#define PCC0_PCC_LPTIMER0_PR_MASK                (0x80000000U)
#define PCC0_PCC_LPTIMER0_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPTIMER0_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPTIMER0_PR_SHIFT)) & PCC0_PCC_LPTIMER0_PR_MASK)
/*! @} */

/*! @name PCC_LPTIMER1 - PCC LPTIMER1 Register */
/*! @{ */

#define PCC0_PCC_LPTIMER1_INUSE_MASK             (0x20000000U)
#define PCC0_PCC_LPTIMER1_INUSE_SHIFT            (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LPTIMER1_INUSE(x)               (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPTIMER1_INUSE_SHIFT)) & PCC0_PCC_LPTIMER1_INUSE_MASK)

#define PCC0_PCC_LPTIMER1_CGC_MASK               (0x40000000U)
#define PCC0_PCC_LPTIMER1_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPTIMER1_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPTIMER1_CGC_SHIFT)) & PCC0_PCC_LPTIMER1_CGC_MASK)

#define PCC0_PCC_LPTIMER1_PR_MASK                (0x80000000U)
#define PCC0_PCC_LPTIMER1_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPTIMER1_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPTIMER1_PR_SHIFT)) & PCC0_PCC_LPTIMER1_PR_MASK)
/*! @} */

/*! @name PCC_TPM0 - PCC TPM0 Register */
/*! @{ */

#define PCC0_PCC_TPM0_PCS_MASK                   (0x7000000U)
#define PCC0_PCC_TPM0_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_TPM0_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TPM0_PCS_SHIFT)) & PCC0_PCC_TPM0_PCS_MASK)

#define PCC0_PCC_TPM0_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_TPM0_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_TPM0_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TPM0_INUSE_SHIFT)) & PCC0_PCC_TPM0_INUSE_MASK)

#define PCC0_PCC_TPM0_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_TPM0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_TPM0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TPM0_CGC_SHIFT)) & PCC0_PCC_TPM0_CGC_MASK)

#define PCC0_PCC_TPM0_PR_MASK                    (0x80000000U)
#define PCC0_PCC_TPM0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_TPM0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TPM0_PR_SHIFT)) & PCC0_PCC_TPM0_PR_MASK)
/*! @} */

/*! @name PCC_TPM1 - PCC TPM1 Register */
/*! @{ */

#define PCC0_PCC_TPM1_PCS_MASK                   (0x7000000U)
#define PCC0_PCC_TPM1_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_TPM1_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TPM1_PCS_SHIFT)) & PCC0_PCC_TPM1_PCS_MASK)

#define PCC0_PCC_TPM1_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_TPM1_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_TPM1_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TPM1_INUSE_SHIFT)) & PCC0_PCC_TPM1_INUSE_MASK)

#define PCC0_PCC_TPM1_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_TPM1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_TPM1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TPM1_CGC_SHIFT)) & PCC0_PCC_TPM1_CGC_MASK)

#define PCC0_PCC_TPM1_PR_MASK                    (0x80000000U)
#define PCC0_PCC_TPM1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_TPM1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_TPM1_PR_SHIFT)) & PCC0_PCC_TPM1_PR_MASK)
/*! @} */

/*! @name PCC_FLEXIO0 - PCC FLEXIO0 Register */
/*! @{ */

#define PCC0_PCC_FLEXIO0_PCS_MASK                (0x7000000U)
#define PCC0_PCC_FLEXIO0_PCS_SHIFT               (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_FLEXIO0_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXIO0_PCS_SHIFT)) & PCC0_PCC_FLEXIO0_PCS_MASK)

#define PCC0_PCC_FLEXIO0_INUSE_MASK              (0x20000000U)
#define PCC0_PCC_FLEXIO0_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_FLEXIO0_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXIO0_INUSE_SHIFT)) & PCC0_PCC_FLEXIO0_INUSE_MASK)

#define PCC0_PCC_FLEXIO0_CGC_MASK                (0x40000000U)
#define PCC0_PCC_FLEXIO0_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_FLEXIO0_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXIO0_CGC_SHIFT)) & PCC0_PCC_FLEXIO0_CGC_MASK)

#define PCC0_PCC_FLEXIO0_PR_MASK                 (0x80000000U)
#define PCC0_PCC_FLEXIO0_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_FLEXIO0_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_FLEXIO0_PR_SHIFT)) & PCC0_PCC_FLEXIO0_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C0 - PCC LPI2C0 Register */
/*! @{ */

#define PCC0_PCC_LPI2C0_PCS_MASK                 (0x7000000U)
#define PCC0_PCC_LPI2C0_PCS_SHIFT                (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_LPI2C0_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C0_PCS_SHIFT)) & PCC0_PCC_LPI2C0_PCS_MASK)

#define PCC0_PCC_LPI2C0_INUSE_MASK               (0x20000000U)
#define PCC0_PCC_LPI2C0_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LPI2C0_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C0_INUSE_SHIFT)) & PCC0_PCC_LPI2C0_INUSE_MASK)

#define PCC0_PCC_LPI2C0_CGC_MASK                 (0x40000000U)
#define PCC0_PCC_LPI2C0_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPI2C0_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C0_CGC_SHIFT)) & PCC0_PCC_LPI2C0_CGC_MASK)

#define PCC0_PCC_LPI2C0_PR_MASK                  (0x80000000U)
#define PCC0_PCC_LPI2C0_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPI2C0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C0_PR_SHIFT)) & PCC0_PCC_LPI2C0_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C1 - PCC LPI2C1 Register */
/*! @{ */

#define PCC0_PCC_LPI2C1_PCS_MASK                 (0x7000000U)
#define PCC0_PCC_LPI2C1_PCS_SHIFT                (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_LPI2C1_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C1_PCS_SHIFT)) & PCC0_PCC_LPI2C1_PCS_MASK)

#define PCC0_PCC_LPI2C1_INUSE_MASK               (0x20000000U)
#define PCC0_PCC_LPI2C1_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LPI2C1_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C1_INUSE_SHIFT)) & PCC0_PCC_LPI2C1_INUSE_MASK)

#define PCC0_PCC_LPI2C1_CGC_MASK                 (0x40000000U)
#define PCC0_PCC_LPI2C1_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPI2C1_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C1_CGC_SHIFT)) & PCC0_PCC_LPI2C1_CGC_MASK)

#define PCC0_PCC_LPI2C1_PR_MASK                  (0x80000000U)
#define PCC0_PCC_LPI2C1_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPI2C1_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C1_PR_SHIFT)) & PCC0_PCC_LPI2C1_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C2 - PCC LPI2C2 Register */
/*! @{ */

#define PCC0_PCC_LPI2C2_PCS_MASK                 (0x7000000U)
#define PCC0_PCC_LPI2C2_PCS_SHIFT                (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_LPI2C2_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C2_PCS_SHIFT)) & PCC0_PCC_LPI2C2_PCS_MASK)

#define PCC0_PCC_LPI2C2_INUSE_MASK               (0x20000000U)
#define PCC0_PCC_LPI2C2_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LPI2C2_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C2_INUSE_SHIFT)) & PCC0_PCC_LPI2C2_INUSE_MASK)

#define PCC0_PCC_LPI2C2_CGC_MASK                 (0x40000000U)
#define PCC0_PCC_LPI2C2_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPI2C2_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C2_CGC_SHIFT)) & PCC0_PCC_LPI2C2_CGC_MASK)

#define PCC0_PCC_LPI2C2_PR_MASK                  (0x80000000U)
#define PCC0_PCC_LPI2C2_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPI2C2_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C2_PR_SHIFT)) & PCC0_PCC_LPI2C2_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C3 - PCC LPI2C3 Register */
/*! @{ */

#define PCC0_PCC_LPI2C3_PCS_MASK                 (0x7000000U)
#define PCC0_PCC_LPI2C3_PCS_SHIFT                (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_LPI2C3_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C3_PCS_SHIFT)) & PCC0_PCC_LPI2C3_PCS_MASK)

#define PCC0_PCC_LPI2C3_INUSE_MASK               (0x20000000U)
#define PCC0_PCC_LPI2C3_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LPI2C3_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C3_INUSE_SHIFT)) & PCC0_PCC_LPI2C3_INUSE_MASK)

#define PCC0_PCC_LPI2C3_CGC_MASK                 (0x40000000U)
#define PCC0_PCC_LPI2C3_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPI2C3_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C3_CGC_SHIFT)) & PCC0_PCC_LPI2C3_CGC_MASK)

#define PCC0_PCC_LPI2C3_PR_MASK                  (0x80000000U)
#define PCC0_PCC_LPI2C3_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPI2C3_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPI2C3_PR_SHIFT)) & PCC0_PCC_LPI2C3_PR_MASK)
/*! @} */

/*! @name PCC_SAI0 - PCC SAI0 Register */
/*! @{ */

#define PCC0_PCC_SAI0_PCD_MASK                   (0xFFFFU)
#define PCC0_PCC_SAI0_PCD_SHIFT                  (0U)
/*! PCD - Peripheral Clock Divider Select */
#define PCC0_PCC_SAI0_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SAI0_PCD_SHIFT)) & PCC0_PCC_SAI0_PCD_MASK)

#define PCC0_PCC_SAI0_FRAC_MASK                  (0xFF0000U)
#define PCC0_PCC_SAI0_FRAC_SHIFT                 (16U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b00000000..Fractional value is 0.
 *  0b00000001..Fractional value is 1.
 */
#define PCC0_PCC_SAI0_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SAI0_FRAC_SHIFT)) & PCC0_PCC_SAI0_FRAC_MASK)

#define PCC0_PCC_SAI0_PCS_MASK                   (0x7000000U)
#define PCC0_PCC_SAI0_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off. An external clock can be enabled for this peripheral.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_SAI0_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SAI0_PCS_SHIFT)) & PCC0_PCC_SAI0_PCS_MASK)

#define PCC0_PCC_SAI0_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_SAI0_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_SAI0_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SAI0_INUSE_SHIFT)) & PCC0_PCC_SAI0_INUSE_MASK)

#define PCC0_PCC_SAI0_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_SAI0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_SAI0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SAI0_CGC_SHIFT)) & PCC0_PCC_SAI0_CGC_MASK)

#define PCC0_PCC_SAI0_PR_MASK                    (0x80000000U)
#define PCC0_PCC_SAI0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_SAI0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SAI0_PR_SHIFT)) & PCC0_PCC_SAI0_PR_MASK)
/*! @} */

/*! @name PCC_LPSPI0 - PCC LPSPI0 Register */
/*! @{ */

#define PCC0_PCC_LPSPI0_PCS_MASK                 (0x7000000U)
#define PCC0_PCC_LPSPI0_PCS_SHIFT                (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_LPSPI0_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI0_PCS_SHIFT)) & PCC0_PCC_LPSPI0_PCS_MASK)

#define PCC0_PCC_LPSPI0_INUSE_MASK               (0x20000000U)
#define PCC0_PCC_LPSPI0_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LPSPI0_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI0_INUSE_SHIFT)) & PCC0_PCC_LPSPI0_INUSE_MASK)

#define PCC0_PCC_LPSPI0_CGC_MASK                 (0x40000000U)
#define PCC0_PCC_LPSPI0_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPSPI0_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI0_CGC_SHIFT)) & PCC0_PCC_LPSPI0_CGC_MASK)

#define PCC0_PCC_LPSPI0_PR_MASK                  (0x80000000U)
#define PCC0_PCC_LPSPI0_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPSPI0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI0_PR_SHIFT)) & PCC0_PCC_LPSPI0_PR_MASK)
/*! @} */

/*! @name PCC_LPSPI1 - PCC LPSPI1 Register */
/*! @{ */

#define PCC0_PCC_LPSPI1_PCS_MASK                 (0x7000000U)
#define PCC0_PCC_LPSPI1_PCS_SHIFT                (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_LPSPI1_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI1_PCS_SHIFT)) & PCC0_PCC_LPSPI1_PCS_MASK)

#define PCC0_PCC_LPSPI1_INUSE_MASK               (0x20000000U)
#define PCC0_PCC_LPSPI1_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LPSPI1_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI1_INUSE_SHIFT)) & PCC0_PCC_LPSPI1_INUSE_MASK)

#define PCC0_PCC_LPSPI1_CGC_MASK                 (0x40000000U)
#define PCC0_PCC_LPSPI1_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPSPI1_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI1_CGC_SHIFT)) & PCC0_PCC_LPSPI1_CGC_MASK)

#define PCC0_PCC_LPSPI1_PR_MASK                  (0x80000000U)
#define PCC0_PCC_LPSPI1_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPSPI1_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPSPI1_PR_SHIFT)) & PCC0_PCC_LPSPI1_PR_MASK)
/*! @} */

/*! @name PCC_LPUART0 - PCC LPUART0 Register */
/*! @{ */

#define PCC0_PCC_LPUART0_PCS_MASK                (0x7000000U)
#define PCC0_PCC_LPUART0_PCS_SHIFT               (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_LPUART0_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPUART0_PCS_SHIFT)) & PCC0_PCC_LPUART0_PCS_MASK)

#define PCC0_PCC_LPUART0_INUSE_MASK              (0x20000000U)
#define PCC0_PCC_LPUART0_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LPUART0_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPUART0_INUSE_SHIFT)) & PCC0_PCC_LPUART0_INUSE_MASK)

#define PCC0_PCC_LPUART0_CGC_MASK                (0x40000000U)
#define PCC0_PCC_LPUART0_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPUART0_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPUART0_CGC_SHIFT)) & PCC0_PCC_LPUART0_CGC_MASK)

#define PCC0_PCC_LPUART0_PR_MASK                 (0x80000000U)
#define PCC0_PCC_LPUART0_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPUART0_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPUART0_PR_SHIFT)) & PCC0_PCC_LPUART0_PR_MASK)
/*! @} */

/*! @name PCC_LPUART1 - PCC LPUART1 Register */
/*! @{ */

#define PCC0_PCC_LPUART1_PCS_MASK                (0x7000000U)
#define PCC0_PCC_LPUART1_PCS_SHIFT               (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_LPUART1_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPUART1_PCS_SHIFT)) & PCC0_PCC_LPUART1_PCS_MASK)

#define PCC0_PCC_LPUART1_INUSE_MASK              (0x20000000U)
#define PCC0_PCC_LPUART1_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_LPUART1_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPUART1_INUSE_SHIFT)) & PCC0_PCC_LPUART1_INUSE_MASK)

#define PCC0_PCC_LPUART1_CGC_MASK                (0x40000000U)
#define PCC0_PCC_LPUART1_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_LPUART1_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPUART1_CGC_SHIFT)) & PCC0_PCC_LPUART1_CGC_MASK)

#define PCC0_PCC_LPUART1_PR_MASK                 (0x80000000U)
#define PCC0_PCC_LPUART1_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_LPUART1_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_LPUART1_PR_SHIFT)) & PCC0_PCC_LPUART1_PR_MASK)
/*! @} */

/*! @name PCC_PCTLA - PCC PCTLA Register */
/*! @{ */

#define PCC0_PCC_PCTLA_INUSE_MASK                (0x20000000U)
#define PCC0_PCC_PCTLA_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_PCTLA_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_PCTLA_INUSE_SHIFT)) & PCC0_PCC_PCTLA_INUSE_MASK)

#define PCC0_PCC_PCTLA_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_PCTLA_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_PCTLA_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_PCTLA_CGC_SHIFT)) & PCC0_PCC_PCTLA_CGC_MASK)

#define PCC0_PCC_PCTLA_PR_MASK                   (0x80000000U)
#define PCC0_PCC_PCTLA_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_PCTLA_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_PCTLA_PR_SHIFT)) & PCC0_PCC_PCTLA_PR_MASK)
/*! @} */

/*! @name PCC_PCTLB - PCC PCTLB Register */
/*! @{ */

#define PCC0_PCC_PCTLB_INUSE_MASK                (0x20000000U)
#define PCC0_PCC_PCTLB_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_PCTLB_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_PCTLB_INUSE_SHIFT)) & PCC0_PCC_PCTLB_INUSE_MASK)

#define PCC0_PCC_PCTLB_CGC_MASK                  (0x40000000U)
#define PCC0_PCC_PCTLB_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_PCTLB_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_PCTLB_CGC_SHIFT)) & PCC0_PCC_PCTLB_CGC_MASK)

#define PCC0_PCC_PCTLB_PR_MASK                   (0x80000000U)
#define PCC0_PCC_PCTLB_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_PCTLB_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_PCTLB_PR_SHIFT)) & PCC0_PCC_PCTLB_PR_MASK)
/*! @} */

/*! @name PCC_ADC0 - PCC ADC0 Register */
/*! @{ */

#define PCC0_PCC_ADC0_PCS_MASK                   (0x7000000U)
#define PCC0_PCC_ADC0_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_ADC0_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ADC0_PCS_SHIFT)) & PCC0_PCC_ADC0_PCS_MASK)

#define PCC0_PCC_ADC0_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_ADC0_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_ADC0_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ADC0_INUSE_SHIFT)) & PCC0_PCC_ADC0_INUSE_MASK)

#define PCC0_PCC_ADC0_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_ADC0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_ADC0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ADC0_CGC_SHIFT)) & PCC0_PCC_ADC0_CGC_MASK)

#define PCC0_PCC_ADC0_PR_MASK                    (0x80000000U)
#define PCC0_PCC_ADC0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_ADC0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_ADC0_PR_SHIFT)) & PCC0_PCC_ADC0_PR_MASK)
/*! @} */

/*! @name PCC_CMP0 - PCC CMP0 Register */
/*! @{ */

#define PCC0_PCC_CMP0_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_CMP0_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_CMP0_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP0_INUSE_SHIFT)) & PCC0_PCC_CMP0_INUSE_MASK)

#define PCC0_PCC_CMP0_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_CMP0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_CMP0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP0_CGC_SHIFT)) & PCC0_PCC_CMP0_CGC_MASK)

#define PCC0_PCC_CMP0_PR_MASK                    (0x80000000U)
#define PCC0_PCC_CMP0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_CMP0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP0_PR_SHIFT)) & PCC0_PCC_CMP0_PR_MASK)
/*! @} */

/*! @name PCC_CMP1 - PCC CMP1 Register */
/*! @{ */

#define PCC0_PCC_CMP1_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_CMP1_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_CMP1_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP1_INUSE_SHIFT)) & PCC0_PCC_CMP1_INUSE_MASK)

#define PCC0_PCC_CMP1_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_CMP1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_CMP1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP1_CGC_SHIFT)) & PCC0_PCC_CMP1_CGC_MASK)

#define PCC0_PCC_CMP1_PR_MASK                    (0x80000000U)
#define PCC0_PCC_CMP1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_CMP1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_CMP1_PR_SHIFT)) & PCC0_PCC_CMP1_PR_MASK)
/*! @} */

/*! @name PCC_DAC0 - PCC DAC0 Register */
/*! @{ */

#define PCC0_PCC_DAC0_PCD_MASK                   (0x7U)
#define PCC0_PCC_DAC0_PCD_SHIFT                  (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC0_PCC_DAC0_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_PCD_SHIFT)) & PCC0_PCC_DAC0_PCD_MASK)

#define PCC0_PCC_DAC0_FRAC_MASK                  (0x8U)
#define PCC0_PCC_DAC0_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_DAC0_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_FRAC_SHIFT)) & PCC0_PCC_DAC0_FRAC_MASK)

#define PCC0_PCC_DAC0_PCS_MASK                   (0x7000000U)
#define PCC0_PCC_DAC0_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_DAC0_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_PCS_SHIFT)) & PCC0_PCC_DAC0_PCS_MASK)

#define PCC0_PCC_DAC0_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_DAC0_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_DAC0_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_INUSE_SHIFT)) & PCC0_PCC_DAC0_INUSE_MASK)

#define PCC0_PCC_DAC0_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_DAC0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DAC0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_CGC_SHIFT)) & PCC0_PCC_DAC0_CGC_MASK)

#define PCC0_PCC_DAC0_PR_MASK                    (0x80000000U)
#define PCC0_PCC_DAC0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DAC0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC0_PR_SHIFT)) & PCC0_PCC_DAC0_PR_MASK)
/*! @} */

/*! @name PCC_DAC1 - PCC DAC1 Register */
/*! @{ */

#define PCC0_PCC_DAC1_PCD_MASK                   (0x7U)
#define PCC0_PCC_DAC1_PCD_SHIFT                  (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b000..Divide by 1.
 *  0b001..Divide by 2.
 *  0b010..Divide by 3.
 *  0b011..Divide by 4.
 *  0b100..Divide by 5.
 *  0b101..Divide by 6.
 *  0b110..Divide by 7.
 *  0b111..Divide by 8.
 */
#define PCC0_PCC_DAC1_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_PCD_SHIFT)) & PCC0_PCC_DAC1_PCD_MASK)

#define PCC0_PCC_DAC1_FRAC_MASK                  (0x8U)
#define PCC0_PCC_DAC1_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC0_PCC_DAC1_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_FRAC_SHIFT)) & PCC0_PCC_DAC1_FRAC_MASK)

#define PCC0_PCC_DAC1_PCS_MASK                   (0x7000000U)
#define PCC0_PCC_DAC1_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC0_PCC_DAC1_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_PCS_SHIFT)) & PCC0_PCC_DAC1_PCS_MASK)

#define PCC0_PCC_DAC1_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_DAC1_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_DAC1_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_INUSE_SHIFT)) & PCC0_PCC_DAC1_INUSE_MASK)

#define PCC0_PCC_DAC1_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_DAC1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_DAC1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_CGC_SHIFT)) & PCC0_PCC_DAC1_CGC_MASK)

#define PCC0_PCC_DAC1_PR_MASK                    (0x80000000U)
#define PCC0_PCC_DAC1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_DAC1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_DAC1_PR_SHIFT)) & PCC0_PCC_DAC1_PR_MASK)
/*! @} */

/*! @name PCC_SNVS - PCC SNVS Register */
/*! @{ */

#define PCC0_PCC_SNVS_INUSE_MASK                 (0x20000000U)
#define PCC0_PCC_SNVS_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC0_PCC_SNVS_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SNVS_INUSE_SHIFT)) & PCC0_PCC_SNVS_INUSE_MASK)

#define PCC0_PCC_SNVS_CGC_MASK                   (0x40000000U)
#define PCC0_PCC_SNVS_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC0_PCC_SNVS_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SNVS_CGC_SHIFT)) & PCC0_PCC_SNVS_CGC_MASK)

#define PCC0_PCC_SNVS_PR_MASK                    (0x80000000U)
#define PCC0_PCC_SNVS_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC0_PCC_SNVS_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC0_PCC_SNVS_PR_SHIFT)) & PCC0_PCC_SNVS_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCC0_Register_Masks */


/*!
 * @}
 */ /* end of group PCC0_Peripheral_Access_Layer */


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


#endif  /* PERI_PCC0_H_ */

