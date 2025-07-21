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
**         CMSIS Peripheral Access Layer for PCC1
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
 * @file PERI_PCC1.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC1
 *
 * CMSIS Peripheral Access Layer for PCC1
 */

#if !defined(PERI_PCC1_H_)
#define PERI_PCC1_H_                             /**< Symbol preventing repeated inclusion */

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
   -- PCC1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC1_Peripheral_Access_Layer PCC1 Peripheral Access Layer
 * @{
 */

/** PCC1 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[80];
  __IO uint32_t PCC_TPIU;                          /**< PCC TPIU Register, offset: 0x50 */
       uint8_t RESERVED_1[64];
  __IO uint32_t PCC_QSPI_OTFAD;                    /**< PCC QSPI_OTFAD Register, offset: 0x94 */
       uint8_t RESERVED_2[8];
  __IO uint32_t PCC_TPM2;                          /**< PCC TPM2 Register, offset: 0xA0 */
  __IO uint32_t PCC_TPM3;                          /**< PCC TPM3 Register, offset: 0xA4 */
  __IO uint32_t PCC_SAI1;                          /**< PCC SAI1 Register, offset: 0xA8 */
  __IO uint32_t PCC_LPUART2;                       /**< PCC LPUART2 Register, offset: 0xAC */
  __IO uint32_t PCC_LPUART3;                       /**< PCC LPUART3 Register, offset: 0xB0 */
  __IO uint32_t PCC_ADC1;                          /**< PCC ADC1 Register, offset: 0xB4 */
} PCC1_Type;

/* ----------------------------------------------------------------------------
   -- PCC1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC1_Register_Masks PCC1 Register Masks
 * @{
 */

/*! @name PCC_TPIU - PCC TPIU Register */
/*! @{ */

#define PCC1_PCC_TPIU_PCD_MASK                   (0x7U)
#define PCC1_PCC_TPIU_PCD_SHIFT                  (0U)
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
#define PCC1_PCC_TPIU_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPIU_PCD_SHIFT)) & PCC1_PCC_TPIU_PCD_MASK)

#define PCC1_PCC_TPIU_FRAC_MASK                  (0x8U)
#define PCC1_PCC_TPIU_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_TPIU_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPIU_FRAC_SHIFT)) & PCC1_PCC_TPIU_FRAC_MASK)

#define PCC1_PCC_TPIU_PCS_MASK                   (0x7000000U)
#define PCC1_PCC_TPIU_PCS_SHIFT                  (24U)
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
#define PCC1_PCC_TPIU_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPIU_PCS_SHIFT)) & PCC1_PCC_TPIU_PCS_MASK)

#define PCC1_PCC_TPIU_INUSE_MASK                 (0x20000000U)
#define PCC1_PCC_TPIU_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC1_PCC_TPIU_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPIU_INUSE_SHIFT)) & PCC1_PCC_TPIU_INUSE_MASK)

#define PCC1_PCC_TPIU_CGC_MASK                   (0x40000000U)
#define PCC1_PCC_TPIU_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_TPIU_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPIU_CGC_SHIFT)) & PCC1_PCC_TPIU_CGC_MASK)

#define PCC1_PCC_TPIU_PR_MASK                    (0x80000000U)
#define PCC1_PCC_TPIU_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_TPIU_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPIU_PR_SHIFT)) & PCC1_PCC_TPIU_PR_MASK)
/*! @} */

/*! @name PCC_QSPI_OTFAD - PCC QSPI_OTFAD Register */
/*! @{ */

#define PCC1_PCC_QSPI_OTFAD_PCD_MASK             (0x7U)
#define PCC1_PCC_QSPI_OTFAD_PCD_SHIFT            (0U)
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
#define PCC1_PCC_QSPI_OTFAD_PCD(x)               (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_QSPI_OTFAD_PCD_SHIFT)) & PCC1_PCC_QSPI_OTFAD_PCD_MASK)

#define PCC1_PCC_QSPI_OTFAD_FRAC_MASK            (0x8U)
#define PCC1_PCC_QSPI_OTFAD_FRAC_SHIFT           (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_QSPI_OTFAD_FRAC(x)              (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_QSPI_OTFAD_FRAC_SHIFT)) & PCC1_PCC_QSPI_OTFAD_FRAC_MASK)

#define PCC1_PCC_QSPI_OTFAD_PCS_MASK             (0x7000000U)
#define PCC1_PCC_QSPI_OTFAD_PCS_SHIFT            (24U)
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
#define PCC1_PCC_QSPI_OTFAD_PCS(x)               (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_QSPI_OTFAD_PCS_SHIFT)) & PCC1_PCC_QSPI_OTFAD_PCS_MASK)

#define PCC1_PCC_QSPI_OTFAD_INUSE_MASK           (0x20000000U)
#define PCC1_PCC_QSPI_OTFAD_INUSE_SHIFT          (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC1_PCC_QSPI_OTFAD_INUSE(x)             (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_QSPI_OTFAD_INUSE_SHIFT)) & PCC1_PCC_QSPI_OTFAD_INUSE_MASK)

#define PCC1_PCC_QSPI_OTFAD_CGC_MASK             (0x40000000U)
#define PCC1_PCC_QSPI_OTFAD_CGC_SHIFT            (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_QSPI_OTFAD_CGC(x)               (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_QSPI_OTFAD_CGC_SHIFT)) & PCC1_PCC_QSPI_OTFAD_CGC_MASK)

#define PCC1_PCC_QSPI_OTFAD_PR_MASK              (0x80000000U)
#define PCC1_PCC_QSPI_OTFAD_PR_SHIFT             (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_QSPI_OTFAD_PR(x)                (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_QSPI_OTFAD_PR_SHIFT)) & PCC1_PCC_QSPI_OTFAD_PR_MASK)
/*! @} */

/*! @name PCC_TPM2 - PCC TPM2 Register */
/*! @{ */

#define PCC1_PCC_TPM2_PCS_MASK                   (0x7000000U)
#define PCC1_PCC_TPM2_PCS_SHIFT                  (24U)
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
#define PCC1_PCC_TPM2_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM2_PCS_SHIFT)) & PCC1_PCC_TPM2_PCS_MASK)

#define PCC1_PCC_TPM2_INUSE_MASK                 (0x20000000U)
#define PCC1_PCC_TPM2_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC1_PCC_TPM2_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM2_INUSE_SHIFT)) & PCC1_PCC_TPM2_INUSE_MASK)

#define PCC1_PCC_TPM2_CGC_MASK                   (0x40000000U)
#define PCC1_PCC_TPM2_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_TPM2_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM2_CGC_SHIFT)) & PCC1_PCC_TPM2_CGC_MASK)

#define PCC1_PCC_TPM2_PR_MASK                    (0x80000000U)
#define PCC1_PCC_TPM2_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_TPM2_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM2_PR_SHIFT)) & PCC1_PCC_TPM2_PR_MASK)
/*! @} */

/*! @name PCC_TPM3 - PCC TPM3 Register */
/*! @{ */

#define PCC1_PCC_TPM3_PCS_MASK                   (0x7000000U)
#define PCC1_PCC_TPM3_PCS_SHIFT                  (24U)
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
#define PCC1_PCC_TPM3_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM3_PCS_SHIFT)) & PCC1_PCC_TPM3_PCS_MASK)

#define PCC1_PCC_TPM3_INUSE_MASK                 (0x20000000U)
#define PCC1_PCC_TPM3_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC1_PCC_TPM3_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM3_INUSE_SHIFT)) & PCC1_PCC_TPM3_INUSE_MASK)

#define PCC1_PCC_TPM3_CGC_MASK                   (0x40000000U)
#define PCC1_PCC_TPM3_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_TPM3_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM3_CGC_SHIFT)) & PCC1_PCC_TPM3_CGC_MASK)

#define PCC1_PCC_TPM3_PR_MASK                    (0x80000000U)
#define PCC1_PCC_TPM3_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_TPM3_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM3_PR_SHIFT)) & PCC1_PCC_TPM3_PR_MASK)
/*! @} */

/*! @name PCC_SAI1 - PCC SAI1 Register */
/*! @{ */

#define PCC1_PCC_SAI1_PCD_MASK                   (0xFFFFU)
#define PCC1_PCC_SAI1_PCD_SHIFT                  (0U)
/*! PCD - Peripheral Clock Divider Select */
#define PCC1_PCC_SAI1_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI1_PCD_SHIFT)) & PCC1_PCC_SAI1_PCD_MASK)

#define PCC1_PCC_SAI1_FRAC_MASK                  (0xFF0000U)
#define PCC1_PCC_SAI1_FRAC_SHIFT                 (16U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b00000000..Fractional value is 0.
 *  0b00000001..Fractional value is 1.
 */
#define PCC1_PCC_SAI1_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI1_FRAC_SHIFT)) & PCC1_PCC_SAI1_FRAC_MASK)

#define PCC1_PCC_SAI1_PCS_MASK                   (0x7000000U)
#define PCC1_PCC_SAI1_PCS_SHIFT                  (24U)
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
#define PCC1_PCC_SAI1_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI1_PCS_SHIFT)) & PCC1_PCC_SAI1_PCS_MASK)

#define PCC1_PCC_SAI1_INUSE_MASK                 (0x20000000U)
#define PCC1_PCC_SAI1_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC1_PCC_SAI1_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI1_INUSE_SHIFT)) & PCC1_PCC_SAI1_INUSE_MASK)

#define PCC1_PCC_SAI1_CGC_MASK                   (0x40000000U)
#define PCC1_PCC_SAI1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_SAI1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI1_CGC_SHIFT)) & PCC1_PCC_SAI1_CGC_MASK)

#define PCC1_PCC_SAI1_PR_MASK                    (0x80000000U)
#define PCC1_PCC_SAI1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_SAI1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI1_PR_SHIFT)) & PCC1_PCC_SAI1_PR_MASK)
/*! @} */

/*! @name PCC_LPUART2 - PCC LPUART2 Register */
/*! @{ */

#define PCC1_PCC_LPUART2_PCS_MASK                (0x7000000U)
#define PCC1_PCC_LPUART2_PCS_SHIFT               (24U)
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
#define PCC1_PCC_LPUART2_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART2_PCS_SHIFT)) & PCC1_PCC_LPUART2_PCS_MASK)

#define PCC1_PCC_LPUART2_INUSE_MASK              (0x20000000U)
#define PCC1_PCC_LPUART2_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC1_PCC_LPUART2_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART2_INUSE_SHIFT)) & PCC1_PCC_LPUART2_INUSE_MASK)

#define PCC1_PCC_LPUART2_CGC_MASK                (0x40000000U)
#define PCC1_PCC_LPUART2_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_LPUART2_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART2_CGC_SHIFT)) & PCC1_PCC_LPUART2_CGC_MASK)

#define PCC1_PCC_LPUART2_PR_MASK                 (0x80000000U)
#define PCC1_PCC_LPUART2_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_LPUART2_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART2_PR_SHIFT)) & PCC1_PCC_LPUART2_PR_MASK)
/*! @} */

/*! @name PCC_LPUART3 - PCC LPUART3 Register */
/*! @{ */

#define PCC1_PCC_LPUART3_PCS_MASK                (0x7000000U)
#define PCC1_PCC_LPUART3_PCS_SHIFT               (24U)
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
#define PCC1_PCC_LPUART3_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART3_PCS_SHIFT)) & PCC1_PCC_LPUART3_PCS_MASK)

#define PCC1_PCC_LPUART3_INUSE_MASK              (0x20000000U)
#define PCC1_PCC_LPUART3_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC1_PCC_LPUART3_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART3_INUSE_SHIFT)) & PCC1_PCC_LPUART3_INUSE_MASK)

#define PCC1_PCC_LPUART3_CGC_MASK                (0x40000000U)
#define PCC1_PCC_LPUART3_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_LPUART3_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART3_CGC_SHIFT)) & PCC1_PCC_LPUART3_CGC_MASK)

#define PCC1_PCC_LPUART3_PR_MASK                 (0x80000000U)
#define PCC1_PCC_LPUART3_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_LPUART3_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART3_PR_SHIFT)) & PCC1_PCC_LPUART3_PR_MASK)
/*! @} */

/*! @name PCC_ADC1 - PCC ADC1 Register */
/*! @{ */

#define PCC1_PCC_ADC1_PCS_MASK                   (0x7000000U)
#define PCC1_PCC_ADC1_PCS_SHIFT                  (24U)
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
#define PCC1_PCC_ADC1_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_ADC1_PCS_SHIFT)) & PCC1_PCC_ADC1_PCS_MASK)

#define PCC1_PCC_ADC1_INUSE_MASK                 (0x20000000U)
#define PCC1_PCC_ADC1_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC1_PCC_ADC1_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_ADC1_INUSE_SHIFT)) & PCC1_PCC_ADC1_INUSE_MASK)

#define PCC1_PCC_ADC1_CGC_MASK                   (0x40000000U)
#define PCC1_PCC_ADC1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_ADC1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_ADC1_CGC_SHIFT)) & PCC1_PCC_ADC1_CGC_MASK)

#define PCC1_PCC_ADC1_PR_MASK                    (0x80000000U)
#define PCC1_PCC_ADC1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_ADC1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_ADC1_PR_SHIFT)) & PCC1_PCC_ADC1_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCC1_Register_Masks */


/*!
 * @}
 */ /* end of group PCC1_Peripheral_Access_Layer */


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


#endif  /* PERI_PCC1_H_ */

