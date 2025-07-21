/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
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
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PCC1.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC1
 *
 * CMSIS Peripheral Access Layer for PCC1
 */

#if !defined(PERI_PCC1_H_)
#define PERI_PCC1_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- PCC1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC1_Peripheral_Access_Layer PCC1 Peripheral Access Layer
 * @{
 */

/** PCC1 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[12];
  __IO uint32_t PCC_TPIU;                          /**< PCC TPIU Register, offset: 0xC */
       uint8_t RESERVED_1[8];
  __IO uint32_t PCC_SWO;                           /**< PCC SWO Register, offset: 0x18 */
       uint8_t RESERVED_2[44];
  __IO uint32_t PCC_FLEXSPI1;                      /**< PCC FlexSPI1 Register, offset: 0x48 */
  __IO uint32_t PCC_LPTMR0;                        /**< PCC LPTMR0 Register, offset: 0x4C */
  __IO uint32_t PCC_LPTMR1;                        /**< PCC LPTMR1 Register, offset: 0x50 */
  __IO uint32_t PCC_TPM0;                          /**< PCC TPM0 Register, offset: 0x54 */
  __IO uint32_t PCC_TPM1;                          /**< PCC TPM1 Register, offset: 0x58 */
       uint8_t RESERVED_3[4];
  __IO uint32_t PCC_LPI2C0;                        /**< PCC LPI2C0 Register, offset: 0x60 */
  __IO uint32_t PCC_LPI2C1;                        /**< PCC LPI2C1 Register, offset: 0x64 */
  __IO uint32_t PCC_LPUART0;                       /**< PCC LPUART0 Register, offset: 0x68 */
  __IO uint32_t PCC_LPUART1;                       /**< PCC LPUART1 Register, offset: 0x6C */
  __IO uint32_t PCC_SAI0;                          /**< PCC SAI0 Register, offset: 0x70 */
  __IO uint32_t PCC_SAI1;                          /**< PCC SAI1 Register, offset: 0x74 */
  __IO uint32_t PCC_DIGITAL_FILTER_A;              /**< PCC DIGITAL_FILTER_A Register, offset: 0x78 */
  __IO uint32_t PCC_DIGITAL_FILTER_B;              /**< PCC DIGITAL_FILTER_B Register, offset: 0x7C */
       uint8_t RESERVED_4[8];
  __IO uint32_t PCC_ADC1;                          /**< PCC ADC1 Register, offset: 0x88 */
       uint8_t RESERVED_5[20];
  __IO uint32_t PCC_FLEXCAN;                       /**< PCC Flexcan Register, offset: 0xA0 */
       uint8_t RESERVED_6[16];
  __IO uint32_t PCC_RGPIOA;                        /**< PCC RGPIOA Register, offset: 0xB4 */
  __IO uint32_t PCC_RGPIOB;                        /**< PCC RGPIOB Register, offset: 0xB8 */
  __IO uint32_t PCC_RGPIOC;                        /**< PCC RGPIOC Register, offset: 0xBC */
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

#define PCC1_PCC_TPIU_SSADO_MASK                 (0xC00000U)
#define PCC1_PCC_TPIU_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_TPIU_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPIU_SSADO_SHIFT)) & PCC1_PCC_TPIU_SSADO_MASK)

#define PCC1_PCC_TPIU_PCS_MASK                   (0x7000000U)
#define PCC1_PCC_TPIU_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC1_PCC_TPIU_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPIU_PCS_SHIFT)) & PCC1_PCC_TPIU_PCS_MASK)

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

/*! @name PCC_SWO - PCC SWO Register */
/*! @{ */

#define PCC1_PCC_SWO_PCD_MASK                    (0x7U)
#define PCC1_PCC_SWO_PCD_SHIFT                   (0U)
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
#define PCC1_PCC_SWO_PCD(x)                      (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SWO_PCD_SHIFT)) & PCC1_PCC_SWO_PCD_MASK)

#define PCC1_PCC_SWO_FRAC_MASK                   (0x8U)
#define PCC1_PCC_SWO_FRAC_SHIFT                  (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_SWO_FRAC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SWO_FRAC_SHIFT)) & PCC1_PCC_SWO_FRAC_MASK)

#define PCC1_PCC_SWO_SSADO_MASK                  (0xC00000U)
#define PCC1_PCC_SWO_SSADO_SHIFT                 (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_SWO_SSADO(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SWO_SSADO_SHIFT)) & PCC1_PCC_SWO_SSADO_MASK)

#define PCC1_PCC_SWO_PCS_MASK                    (0x7000000U)
#define PCC1_PCC_SWO_PCS_SHIFT                   (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC1_PCC_SWO_PCS(x)                      (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SWO_PCS_SHIFT)) & PCC1_PCC_SWO_PCS_MASK)

#define PCC1_PCC_SWO_CGC_MASK                    (0x40000000U)
#define PCC1_PCC_SWO_CGC_SHIFT                   (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_SWO_CGC(x)                      (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SWO_CGC_SHIFT)) & PCC1_PCC_SWO_CGC_MASK)

#define PCC1_PCC_SWO_PR_MASK                     (0x80000000U)
#define PCC1_PCC_SWO_PR_SHIFT                    (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_SWO_PR(x)                       (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SWO_PR_SHIFT)) & PCC1_PCC_SWO_PR_MASK)
/*! @} */

/*! @name PCC_FLEXSPI1 - PCC FlexSPI1 Register */
/*! @{ */

#define PCC1_PCC_FLEXSPI1_PCD_MASK               (0x7U)
#define PCC1_PCC_FLEXSPI1_PCD_SHIFT              (0U)
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
#define PCC1_PCC_FLEXSPI1_PCD(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXSPI1_PCD_SHIFT)) & PCC1_PCC_FLEXSPI1_PCD_MASK)

#define PCC1_PCC_FLEXSPI1_FRAC_MASK              (0x8U)
#define PCC1_PCC_FLEXSPI1_FRAC_SHIFT             (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_FLEXSPI1_FRAC(x)                (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXSPI1_FRAC_SHIFT)) & PCC1_PCC_FLEXSPI1_FRAC_MASK)

#define PCC1_PCC_FLEXSPI1_SSADO_MASK             (0xC00000U)
#define PCC1_PCC_FLEXSPI1_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_FLEXSPI1_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXSPI1_SSADO_SHIFT)) & PCC1_PCC_FLEXSPI1_SSADO_MASK)

#define PCC1_PCC_FLEXSPI1_PCS_MASK               (0x7000000U)
#define PCC1_PCC_FLEXSPI1_PCS_SHIFT              (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC1_PCC_FLEXSPI1_PCS(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXSPI1_PCS_SHIFT)) & PCC1_PCC_FLEXSPI1_PCS_MASK)

#define PCC1_PCC_FLEXSPI1_SWRST_MASK             (0x10000000U)
#define PCC1_PCC_FLEXSPI1_SWRST_SHIFT            (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC1_PCC_FLEXSPI1_SWRST(x)               (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXSPI1_SWRST_SHIFT)) & PCC1_PCC_FLEXSPI1_SWRST_MASK)

#define PCC1_PCC_FLEXSPI1_CGC_MASK               (0x40000000U)
#define PCC1_PCC_FLEXSPI1_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_FLEXSPI1_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXSPI1_CGC_SHIFT)) & PCC1_PCC_FLEXSPI1_CGC_MASK)

#define PCC1_PCC_FLEXSPI1_PR_MASK                (0x80000000U)
#define PCC1_PCC_FLEXSPI1_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_FLEXSPI1_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXSPI1_PR_SHIFT)) & PCC1_PCC_FLEXSPI1_PR_MASK)
/*! @} */

/*! @name PCC_LPTMR0 - PCC LPTMR0 Register */
/*! @{ */

#define PCC1_PCC_LPTMR0_SSADO_MASK               (0xC00000U)
#define PCC1_PCC_LPTMR0_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_LPTMR0_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPTMR0_SSADO_SHIFT)) & PCC1_PCC_LPTMR0_SSADO_MASK)

#define PCC1_PCC_LPTMR0_CGC_MASK                 (0x40000000U)
#define PCC1_PCC_LPTMR0_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_LPTMR0_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPTMR0_CGC_SHIFT)) & PCC1_PCC_LPTMR0_CGC_MASK)

#define PCC1_PCC_LPTMR0_PR_MASK                  (0x80000000U)
#define PCC1_PCC_LPTMR0_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_LPTMR0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPTMR0_PR_SHIFT)) & PCC1_PCC_LPTMR0_PR_MASK)
/*! @} */

/*! @name PCC_LPTMR1 - PCC LPTMR1 Register */
/*! @{ */

#define PCC1_PCC_LPTMR1_SSADO_MASK               (0xC00000U)
#define PCC1_PCC_LPTMR1_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_LPTMR1_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPTMR1_SSADO_SHIFT)) & PCC1_PCC_LPTMR1_SSADO_MASK)

#define PCC1_PCC_LPTMR1_CGC_MASK                 (0x40000000U)
#define PCC1_PCC_LPTMR1_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_LPTMR1_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPTMR1_CGC_SHIFT)) & PCC1_PCC_LPTMR1_CGC_MASK)

#define PCC1_PCC_LPTMR1_PR_MASK                  (0x80000000U)
#define PCC1_PCC_LPTMR1_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_LPTMR1_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPTMR1_PR_SHIFT)) & PCC1_PCC_LPTMR1_PR_MASK)
/*! @} */

/*! @name PCC_TPM0 - PCC TPM0 Register */
/*! @{ */

#define PCC1_PCC_TPM0_PCD_MASK                   (0x7U)
#define PCC1_PCC_TPM0_PCD_SHIFT                  (0U)
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
#define PCC1_PCC_TPM0_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM0_PCD_SHIFT)) & PCC1_PCC_TPM0_PCD_MASK)

#define PCC1_PCC_TPM0_FRAC_MASK                  (0x8U)
#define PCC1_PCC_TPM0_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_TPM0_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM0_FRAC_SHIFT)) & PCC1_PCC_TPM0_FRAC_MASK)

#define PCC1_PCC_TPM0_SSADO_MASK                 (0xC00000U)
#define PCC1_PCC_TPM0_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_TPM0_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM0_SSADO_SHIFT)) & PCC1_PCC_TPM0_SSADO_MASK)

#define PCC1_PCC_TPM0_PCS_MASK                   (0x7000000U)
#define PCC1_PCC_TPM0_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC1_PCC_TPM0_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM0_PCS_SHIFT)) & PCC1_PCC_TPM0_PCS_MASK)

#define PCC1_PCC_TPM0_SWRST_MASK                 (0x10000000U)
#define PCC1_PCC_TPM0_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC1_PCC_TPM0_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM0_SWRST_SHIFT)) & PCC1_PCC_TPM0_SWRST_MASK)

#define PCC1_PCC_TPM0_CGC_MASK                   (0x40000000U)
#define PCC1_PCC_TPM0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_TPM0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM0_CGC_SHIFT)) & PCC1_PCC_TPM0_CGC_MASK)

#define PCC1_PCC_TPM0_PR_MASK                    (0x80000000U)
#define PCC1_PCC_TPM0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_TPM0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM0_PR_SHIFT)) & PCC1_PCC_TPM0_PR_MASK)
/*! @} */

/*! @name PCC_TPM1 - PCC TPM1 Register */
/*! @{ */

#define PCC1_PCC_TPM1_PCD_MASK                   (0x7U)
#define PCC1_PCC_TPM1_PCD_SHIFT                  (0U)
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
#define PCC1_PCC_TPM1_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM1_PCD_SHIFT)) & PCC1_PCC_TPM1_PCD_MASK)

#define PCC1_PCC_TPM1_FRAC_MASK                  (0x8U)
#define PCC1_PCC_TPM1_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_TPM1_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM1_FRAC_SHIFT)) & PCC1_PCC_TPM1_FRAC_MASK)

#define PCC1_PCC_TPM1_SSADO_MASK                 (0xC00000U)
#define PCC1_PCC_TPM1_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_TPM1_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM1_SSADO_SHIFT)) & PCC1_PCC_TPM1_SSADO_MASK)

#define PCC1_PCC_TPM1_PCS_MASK                   (0x7000000U)
#define PCC1_PCC_TPM1_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC1_PCC_TPM1_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM1_PCS_SHIFT)) & PCC1_PCC_TPM1_PCS_MASK)

#define PCC1_PCC_TPM1_SWRST_MASK                 (0x10000000U)
#define PCC1_PCC_TPM1_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC1_PCC_TPM1_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM1_SWRST_SHIFT)) & PCC1_PCC_TPM1_SWRST_MASK)

#define PCC1_PCC_TPM1_CGC_MASK                   (0x40000000U)
#define PCC1_PCC_TPM1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_TPM1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM1_CGC_SHIFT)) & PCC1_PCC_TPM1_CGC_MASK)

#define PCC1_PCC_TPM1_PR_MASK                    (0x80000000U)
#define PCC1_PCC_TPM1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_TPM1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_TPM1_PR_SHIFT)) & PCC1_PCC_TPM1_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C0 - PCC LPI2C0 Register */
/*! @{ */

#define PCC1_PCC_LPI2C0_PCD_MASK                 (0x7U)
#define PCC1_PCC_LPI2C0_PCD_SHIFT                (0U)
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
#define PCC1_PCC_LPI2C0_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C0_PCD_SHIFT)) & PCC1_PCC_LPI2C0_PCD_MASK)

#define PCC1_PCC_LPI2C0_FRAC_MASK                (0x8U)
#define PCC1_PCC_LPI2C0_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_LPI2C0_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C0_FRAC_SHIFT)) & PCC1_PCC_LPI2C0_FRAC_MASK)

#define PCC1_PCC_LPI2C0_SSADO_MASK               (0xC00000U)
#define PCC1_PCC_LPI2C0_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_LPI2C0_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C0_SSADO_SHIFT)) & PCC1_PCC_LPI2C0_SSADO_MASK)

#define PCC1_PCC_LPI2C0_PCS_MASK                 (0x7000000U)
#define PCC1_PCC_LPI2C0_PCS_SHIFT                (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC1_PCC_LPI2C0_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C0_PCS_SHIFT)) & PCC1_PCC_LPI2C0_PCS_MASK)

#define PCC1_PCC_LPI2C0_SWRST_MASK               (0x10000000U)
#define PCC1_PCC_LPI2C0_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC1_PCC_LPI2C0_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C0_SWRST_SHIFT)) & PCC1_PCC_LPI2C0_SWRST_MASK)

#define PCC1_PCC_LPI2C0_CGC_MASK                 (0x40000000U)
#define PCC1_PCC_LPI2C0_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_LPI2C0_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C0_CGC_SHIFT)) & PCC1_PCC_LPI2C0_CGC_MASK)

#define PCC1_PCC_LPI2C0_PR_MASK                  (0x80000000U)
#define PCC1_PCC_LPI2C0_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_LPI2C0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C0_PR_SHIFT)) & PCC1_PCC_LPI2C0_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C1 - PCC LPI2C1 Register */
/*! @{ */

#define PCC1_PCC_LPI2C1_PCD_MASK                 (0x7U)
#define PCC1_PCC_LPI2C1_PCD_SHIFT                (0U)
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
#define PCC1_PCC_LPI2C1_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C1_PCD_SHIFT)) & PCC1_PCC_LPI2C1_PCD_MASK)

#define PCC1_PCC_LPI2C1_FRAC_MASK                (0x8U)
#define PCC1_PCC_LPI2C1_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_LPI2C1_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C1_FRAC_SHIFT)) & PCC1_PCC_LPI2C1_FRAC_MASK)

#define PCC1_PCC_LPI2C1_SSADO_MASK               (0xC00000U)
#define PCC1_PCC_LPI2C1_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_LPI2C1_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C1_SSADO_SHIFT)) & PCC1_PCC_LPI2C1_SSADO_MASK)

#define PCC1_PCC_LPI2C1_PCS_MASK                 (0x7000000U)
#define PCC1_PCC_LPI2C1_PCS_SHIFT                (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC1_PCC_LPI2C1_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C1_PCS_SHIFT)) & PCC1_PCC_LPI2C1_PCS_MASK)

#define PCC1_PCC_LPI2C1_SWRST_MASK               (0x10000000U)
#define PCC1_PCC_LPI2C1_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC1_PCC_LPI2C1_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C1_SWRST_SHIFT)) & PCC1_PCC_LPI2C1_SWRST_MASK)

#define PCC1_PCC_LPI2C1_CGC_MASK                 (0x40000000U)
#define PCC1_PCC_LPI2C1_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_LPI2C1_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C1_CGC_SHIFT)) & PCC1_PCC_LPI2C1_CGC_MASK)

#define PCC1_PCC_LPI2C1_PR_MASK                  (0x80000000U)
#define PCC1_PCC_LPI2C1_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_LPI2C1_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPI2C1_PR_SHIFT)) & PCC1_PCC_LPI2C1_PR_MASK)
/*! @} */

/*! @name PCC_LPUART0 - PCC LPUART0 Register */
/*! @{ */

#define PCC1_PCC_LPUART0_PCD_MASK                (0x7U)
#define PCC1_PCC_LPUART0_PCD_SHIFT               (0U)
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
#define PCC1_PCC_LPUART0_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART0_PCD_SHIFT)) & PCC1_PCC_LPUART0_PCD_MASK)

#define PCC1_PCC_LPUART0_FRAC_MASK               (0x8U)
#define PCC1_PCC_LPUART0_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_LPUART0_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART0_FRAC_SHIFT)) & PCC1_PCC_LPUART0_FRAC_MASK)

#define PCC1_PCC_LPUART0_SSADO_MASK              (0xC00000U)
#define PCC1_PCC_LPUART0_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_LPUART0_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART0_SSADO_SHIFT)) & PCC1_PCC_LPUART0_SSADO_MASK)

#define PCC1_PCC_LPUART0_PCS_MASK                (0x7000000U)
#define PCC1_PCC_LPUART0_PCS_SHIFT               (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC1_PCC_LPUART0_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART0_PCS_SHIFT)) & PCC1_PCC_LPUART0_PCS_MASK)

#define PCC1_PCC_LPUART0_SWRST_MASK              (0x10000000U)
#define PCC1_PCC_LPUART0_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC1_PCC_LPUART0_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART0_SWRST_SHIFT)) & PCC1_PCC_LPUART0_SWRST_MASK)

#define PCC1_PCC_LPUART0_CGC_MASK                (0x40000000U)
#define PCC1_PCC_LPUART0_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_LPUART0_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART0_CGC_SHIFT)) & PCC1_PCC_LPUART0_CGC_MASK)

#define PCC1_PCC_LPUART0_PR_MASK                 (0x80000000U)
#define PCC1_PCC_LPUART0_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_LPUART0_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART0_PR_SHIFT)) & PCC1_PCC_LPUART0_PR_MASK)
/*! @} */

/*! @name PCC_LPUART1 - PCC LPUART1 Register */
/*! @{ */

#define PCC1_PCC_LPUART1_PCD_MASK                (0x7U)
#define PCC1_PCC_LPUART1_PCD_SHIFT               (0U)
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
#define PCC1_PCC_LPUART1_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART1_PCD_SHIFT)) & PCC1_PCC_LPUART1_PCD_MASK)

#define PCC1_PCC_LPUART1_FRAC_MASK               (0x8U)
#define PCC1_PCC_LPUART1_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_LPUART1_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART1_FRAC_SHIFT)) & PCC1_PCC_LPUART1_FRAC_MASK)

#define PCC1_PCC_LPUART1_SSADO_MASK              (0xC00000U)
#define PCC1_PCC_LPUART1_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_LPUART1_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART1_SSADO_SHIFT)) & PCC1_PCC_LPUART1_SSADO_MASK)

#define PCC1_PCC_LPUART1_PCS_MASK                (0x7000000U)
#define PCC1_PCC_LPUART1_PCS_SHIFT               (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC1_PCC_LPUART1_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART1_PCS_SHIFT)) & PCC1_PCC_LPUART1_PCS_MASK)

#define PCC1_PCC_LPUART1_SWRST_MASK              (0x10000000U)
#define PCC1_PCC_LPUART1_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC1_PCC_LPUART1_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART1_SWRST_SHIFT)) & PCC1_PCC_LPUART1_SWRST_MASK)

#define PCC1_PCC_LPUART1_CGC_MASK                (0x40000000U)
#define PCC1_PCC_LPUART1_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_LPUART1_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART1_CGC_SHIFT)) & PCC1_PCC_LPUART1_CGC_MASK)

#define PCC1_PCC_LPUART1_PR_MASK                 (0x80000000U)
#define PCC1_PCC_LPUART1_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_LPUART1_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_LPUART1_PR_SHIFT)) & PCC1_PCC_LPUART1_PR_MASK)
/*! @} */

/*! @name PCC_SAI0 - PCC SAI0 Register */
/*! @{ */

#define PCC1_PCC_SAI0_SSADO_MASK                 (0xC00000U)
#define PCC1_PCC_SAI0_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_SAI0_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI0_SSADO_SHIFT)) & PCC1_PCC_SAI0_SSADO_MASK)

#define PCC1_PCC_SAI0_SWRST_MASK                 (0x10000000U)
#define PCC1_PCC_SAI0_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC1_PCC_SAI0_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI0_SWRST_SHIFT)) & PCC1_PCC_SAI0_SWRST_MASK)

#define PCC1_PCC_SAI0_CGC_MASK                   (0x40000000U)
#define PCC1_PCC_SAI0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_SAI0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI0_CGC_SHIFT)) & PCC1_PCC_SAI0_CGC_MASK)

#define PCC1_PCC_SAI0_PR_MASK                    (0x80000000U)
#define PCC1_PCC_SAI0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_SAI0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI0_PR_SHIFT)) & PCC1_PCC_SAI0_PR_MASK)
/*! @} */

/*! @name PCC_SAI1 - PCC SAI1 Register */
/*! @{ */

#define PCC1_PCC_SAI1_SSADO_MASK                 (0xC00000U)
#define PCC1_PCC_SAI1_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_SAI1_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI1_SSADO_SHIFT)) & PCC1_PCC_SAI1_SSADO_MASK)

#define PCC1_PCC_SAI1_SWRST_MASK                 (0x10000000U)
#define PCC1_PCC_SAI1_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC1_PCC_SAI1_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_SAI1_SWRST_SHIFT)) & PCC1_PCC_SAI1_SWRST_MASK)

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

/*! @name PCC_DIGITAL_FILTER_A - PCC DIGITAL_FILTER_A Register */
/*! @{ */

#define PCC1_PCC_DIGITAL_FILTER_A_SSADO_MASK     (0xC00000U)
#define PCC1_PCC_DIGITAL_FILTER_A_SSADO_SHIFT    (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_DIGITAL_FILTER_A_SSADO(x)       (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_DIGITAL_FILTER_A_SSADO_SHIFT)) & PCC1_PCC_DIGITAL_FILTER_A_SSADO_MASK)

#define PCC1_PCC_DIGITAL_FILTER_A_CGC_MASK       (0x40000000U)
#define PCC1_PCC_DIGITAL_FILTER_A_CGC_SHIFT      (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_DIGITAL_FILTER_A_CGC(x)         (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_DIGITAL_FILTER_A_CGC_SHIFT)) & PCC1_PCC_DIGITAL_FILTER_A_CGC_MASK)

#define PCC1_PCC_DIGITAL_FILTER_A_PR_MASK        (0x80000000U)
#define PCC1_PCC_DIGITAL_FILTER_A_PR_SHIFT       (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_DIGITAL_FILTER_A_PR(x)          (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_DIGITAL_FILTER_A_PR_SHIFT)) & PCC1_PCC_DIGITAL_FILTER_A_PR_MASK)
/*! @} */

/*! @name PCC_DIGITAL_FILTER_B - PCC DIGITAL_FILTER_B Register */
/*! @{ */

#define PCC1_PCC_DIGITAL_FILTER_B_SSADO_MASK     (0xC00000U)
#define PCC1_PCC_DIGITAL_FILTER_B_SSADO_SHIFT    (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_DIGITAL_FILTER_B_SSADO(x)       (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_DIGITAL_FILTER_B_SSADO_SHIFT)) & PCC1_PCC_DIGITAL_FILTER_B_SSADO_MASK)

#define PCC1_PCC_DIGITAL_FILTER_B_CGC_MASK       (0x40000000U)
#define PCC1_PCC_DIGITAL_FILTER_B_CGC_SHIFT      (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_DIGITAL_FILTER_B_CGC(x)         (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_DIGITAL_FILTER_B_CGC_SHIFT)) & PCC1_PCC_DIGITAL_FILTER_B_CGC_MASK)

#define PCC1_PCC_DIGITAL_FILTER_B_PR_MASK        (0x80000000U)
#define PCC1_PCC_DIGITAL_FILTER_B_PR_SHIFT       (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_DIGITAL_FILTER_B_PR(x)          (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_DIGITAL_FILTER_B_PR_SHIFT)) & PCC1_PCC_DIGITAL_FILTER_B_PR_MASK)
/*! @} */

/*! @name PCC_ADC1 - PCC ADC1 Register */
/*! @{ */

#define PCC1_PCC_ADC1_PCD_MASK                   (0x7U)
#define PCC1_PCC_ADC1_PCD_SHIFT                  (0U)
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
#define PCC1_PCC_ADC1_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_ADC1_PCD_SHIFT)) & PCC1_PCC_ADC1_PCD_MASK)

#define PCC1_PCC_ADC1_FRAC_MASK                  (0x8U)
#define PCC1_PCC_ADC1_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_ADC1_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_ADC1_FRAC_SHIFT)) & PCC1_PCC_ADC1_FRAC_MASK)

#define PCC1_PCC_ADC1_SSADO_MASK                 (0xC00000U)
#define PCC1_PCC_ADC1_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_ADC1_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_ADC1_SSADO_SHIFT)) & PCC1_PCC_ADC1_SSADO_MASK)

#define PCC1_PCC_ADC1_PCS_MASK                   (0x7000000U)
#define PCC1_PCC_ADC1_PCS_SHIFT                  (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC1_PCC_ADC1_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_ADC1_PCS_SHIFT)) & PCC1_PCC_ADC1_PCS_MASK)

#define PCC1_PCC_ADC1_SWRST_MASK                 (0x10000000U)
#define PCC1_PCC_ADC1_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC1_PCC_ADC1_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_ADC1_SWRST_SHIFT)) & PCC1_PCC_ADC1_SWRST_MASK)

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

/*! @name PCC_FLEXCAN - PCC Flexcan Register */
/*! @{ */

#define PCC1_PCC_FLEXCAN_PCD_MASK                (0x7U)
#define PCC1_PCC_FLEXCAN_PCD_SHIFT               (0U)
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
#define PCC1_PCC_FLEXCAN_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXCAN_PCD_SHIFT)) & PCC1_PCC_FLEXCAN_PCD_MASK)

#define PCC1_PCC_FLEXCAN_FRAC_MASK               (0x8U)
#define PCC1_PCC_FLEXCAN_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC1_PCC_FLEXCAN_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXCAN_FRAC_SHIFT)) & PCC1_PCC_FLEXCAN_FRAC_MASK)

#define PCC1_PCC_FLEXCAN_SSADO_MASK              (0xC00000U)
#define PCC1_PCC_FLEXCAN_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_FLEXCAN_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXCAN_SSADO_SHIFT)) & PCC1_PCC_FLEXCAN_SSADO_MASK)

#define PCC1_PCC_FLEXCAN_PCS_MASK                (0x7000000U)
#define PCC1_PCC_FLEXCAN_PCS_SHIFT               (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off (or test clock is enabled).
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC1_PCC_FLEXCAN_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXCAN_PCS_SHIFT)) & PCC1_PCC_FLEXCAN_PCS_MASK)

#define PCC1_PCC_FLEXCAN_SWRST_MASK              (0x10000000U)
#define PCC1_PCC_FLEXCAN_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC1_PCC_FLEXCAN_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXCAN_SWRST_SHIFT)) & PCC1_PCC_FLEXCAN_SWRST_MASK)

#define PCC1_PCC_FLEXCAN_CGC_MASK                (0x40000000U)
#define PCC1_PCC_FLEXCAN_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_FLEXCAN_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXCAN_CGC_SHIFT)) & PCC1_PCC_FLEXCAN_CGC_MASK)

#define PCC1_PCC_FLEXCAN_PR_MASK                 (0x80000000U)
#define PCC1_PCC_FLEXCAN_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_FLEXCAN_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_FLEXCAN_PR_SHIFT)) & PCC1_PCC_FLEXCAN_PR_MASK)
/*! @} */

/*! @name PCC_RGPIOA - PCC RGPIOA Register */
/*! @{ */

#define PCC1_PCC_RGPIOA_SSADO_MASK               (0xC00000U)
#define PCC1_PCC_RGPIOA_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_RGPIOA_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_RGPIOA_SSADO_SHIFT)) & PCC1_PCC_RGPIOA_SSADO_MASK)

#define PCC1_PCC_RGPIOA_CGC_MASK                 (0x40000000U)
#define PCC1_PCC_RGPIOA_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_RGPIOA_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_RGPIOA_CGC_SHIFT)) & PCC1_PCC_RGPIOA_CGC_MASK)

#define PCC1_PCC_RGPIOA_PR_MASK                  (0x80000000U)
#define PCC1_PCC_RGPIOA_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_RGPIOA_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_RGPIOA_PR_SHIFT)) & PCC1_PCC_RGPIOA_PR_MASK)
/*! @} */

/*! @name PCC_RGPIOB - PCC RGPIOB Register */
/*! @{ */

#define PCC1_PCC_RGPIOB_SSADO_MASK               (0xC00000U)
#define PCC1_PCC_RGPIOB_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_RGPIOB_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_RGPIOB_SSADO_SHIFT)) & PCC1_PCC_RGPIOB_SSADO_MASK)

#define PCC1_PCC_RGPIOB_CGC_MASK                 (0x40000000U)
#define PCC1_PCC_RGPIOB_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_RGPIOB_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_RGPIOB_CGC_SHIFT)) & PCC1_PCC_RGPIOB_CGC_MASK)

#define PCC1_PCC_RGPIOB_PR_MASK                  (0x80000000U)
#define PCC1_PCC_RGPIOB_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_RGPIOB_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_RGPIOB_PR_SHIFT)) & PCC1_PCC_RGPIOB_PR_MASK)
/*! @} */

/*! @name PCC_RGPIOC - PCC RGPIOC Register */
/*! @{ */

#define PCC1_PCC_RGPIOC_SSADO_MASK               (0xC00000U)
#define PCC1_PCC_RGPIOC_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC1_PCC_RGPIOC_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_RGPIOC_SSADO_SHIFT)) & PCC1_PCC_RGPIOC_SSADO_MASK)

#define PCC1_PCC_RGPIOC_CGC_MASK                 (0x40000000U)
#define PCC1_PCC_RGPIOC_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC1_PCC_RGPIOC_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_RGPIOC_CGC_SHIFT)) & PCC1_PCC_RGPIOC_CGC_MASK)

#define PCC1_PCC_RGPIOC_PR_MASK                  (0x80000000U)
#define PCC1_PCC_RGPIOC_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC1_PCC_RGPIOC_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC1_PCC_RGPIOC_PR_SHIFT)) & PCC1_PCC_RGPIOC_PR_MASK)
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_PCC1_H_ */

