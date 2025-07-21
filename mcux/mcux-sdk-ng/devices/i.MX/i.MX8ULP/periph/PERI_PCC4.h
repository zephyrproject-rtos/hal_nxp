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
**         CMSIS Peripheral Access Layer for PCC4
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
 * @file PERI_PCC4.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC4
 *
 * CMSIS Peripheral Access Layer for PCC4
 */

#if !defined(PERI_PCC4_H_)
#define PERI_PCC4_H_                             /**< Symbol preventing repeated inclusion */

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
   -- PCC4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC4_Peripheral_Access_Layer PCC4 Peripheral Access Layer
 * @{
 */

/** PCC4 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t PCC_FLEXSPI2;                      /**< PCC FlexSPI2 Register, offset: 0x4 */
  __IO uint32_t PCC_TPM6;                          /**< PCC TPM6 Register, offset: 0x8 */
  __IO uint32_t PCC_TPM7;                          /**< PCC TPM7 Register, offset: 0xC */
  __IO uint32_t PCC_LPI2C6;                        /**< PCC LPI2C6 Register, offset: 0x10 */
  __IO uint32_t PCC_LPI2C7;                        /**< PCC LPI2C7 Register, offset: 0x14 */
  __IO uint32_t PCC_LPUART6;                       /**< PCC LPUART6 Register, offset: 0x18 */
  __IO uint32_t PCC_LPUART7;                       /**< PCC LPUART7 Register, offset: 0x1C */
  __IO uint32_t PCC_SAI4;                          /**< PCC SAI4 Register, offset: 0x20 */
  __IO uint32_t PCC_SAI5;                          /**< PCC SAI5 Register, offset: 0x24 */
  __IO uint32_t PCC_DIGITAL_FILTER_E;              /**< PCC DIGITAL_FILTER_E Register, offset: 0x28 */
  __IO uint32_t PCC_DIGITAL_FILTER_F;              /**< PCC DIGITAL_FILTER_F Register, offset: 0x2C */
       uint8_t RESERVED_1[4];
  __IO uint32_t PCC_USDHC0;                        /**< PCC uSDHC0 Register, offset: 0x34 */
  __IO uint32_t PCC_USDHC1;                        /**< PCC uSDHC1 Register, offset: 0x38 */
  __IO uint32_t PCC_USDHC2;                        /**< PCC uSDHC2 Register, offset: 0x3C */
  __IO uint32_t PCC_USB0;                          /**< PCC USB0 Register, offset: 0x40 */
  __IO uint32_t PCC_USB0_PHY;                      /**< PCC USB0_PHY Register, offset: 0x44 */
  __IO uint32_t PCC_USB1;                          /**< PCC USB1 Register, offset: 0x48 */
  __IO uint32_t PCC_USB1_PHY;                      /**< PCC USB1_PHY Register, offset: 0x4C */
  __IO uint32_t PCC_USB_XBAR;                      /**< PCC USB_XBAR Register, offset: 0x50 */
  __IO uint32_t PCC_ENET;                          /**< PCC ENET Register, offset: 0x54 */
       uint8_t RESERVED_2[32];
  __IO uint32_t PCC_RGPIOE;                        /**< PCC RGPIOE Register, offset: 0x78 */
  __IO uint32_t PCC_RGPIOF;                        /**< PCC RGPIOF Register, offset: 0x7C */
} PCC4_Type;

/* ----------------------------------------------------------------------------
   -- PCC4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC4_Register_Masks PCC4 Register Masks
 * @{
 */

/*! @name PCC_FLEXSPI2 - PCC FlexSPI2 Register */
/*! @{ */

#define PCC4_PCC_FLEXSPI2_PCD_MASK               (0x7U)
#define PCC4_PCC_FLEXSPI2_PCD_SHIFT              (0U)
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
#define PCC4_PCC_FLEXSPI2_PCD(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_FLEXSPI2_PCD_SHIFT)) & PCC4_PCC_FLEXSPI2_PCD_MASK)

#define PCC4_PCC_FLEXSPI2_FRAC_MASK              (0x8U)
#define PCC4_PCC_FLEXSPI2_FRAC_SHIFT             (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC4_PCC_FLEXSPI2_FRAC(x)                (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_FLEXSPI2_FRAC_SHIFT)) & PCC4_PCC_FLEXSPI2_FRAC_MASK)

#define PCC4_PCC_FLEXSPI2_SSADO_MASK             (0xC00000U)
#define PCC4_PCC_FLEXSPI2_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_FLEXSPI2_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_FLEXSPI2_SSADO_SHIFT)) & PCC4_PCC_FLEXSPI2_SSADO_MASK)

#define PCC4_PCC_FLEXSPI2_PCS_MASK               (0x7000000U)
#define PCC4_PCC_FLEXSPI2_PCS_SHIFT              (24U)
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
#define PCC4_PCC_FLEXSPI2_PCS(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_FLEXSPI2_PCS_SHIFT)) & PCC4_PCC_FLEXSPI2_PCS_MASK)

#define PCC4_PCC_FLEXSPI2_SWRST_MASK             (0x10000000U)
#define PCC4_PCC_FLEXSPI2_SWRST_SHIFT            (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_FLEXSPI2_SWRST(x)               (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_FLEXSPI2_SWRST_SHIFT)) & PCC4_PCC_FLEXSPI2_SWRST_MASK)

#define PCC4_PCC_FLEXSPI2_CGC_MASK               (0x40000000U)
#define PCC4_PCC_FLEXSPI2_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_FLEXSPI2_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_FLEXSPI2_CGC_SHIFT)) & PCC4_PCC_FLEXSPI2_CGC_MASK)

#define PCC4_PCC_FLEXSPI2_PR_MASK                (0x80000000U)
#define PCC4_PCC_FLEXSPI2_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_FLEXSPI2_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_FLEXSPI2_PR_SHIFT)) & PCC4_PCC_FLEXSPI2_PR_MASK)
/*! @} */

/*! @name PCC_TPM6 - PCC TPM6 Register */
/*! @{ */

#define PCC4_PCC_TPM6_PCD_MASK                   (0x7U)
#define PCC4_PCC_TPM6_PCD_SHIFT                  (0U)
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
#define PCC4_PCC_TPM6_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM6_PCD_SHIFT)) & PCC4_PCC_TPM6_PCD_MASK)

#define PCC4_PCC_TPM6_FRAC_MASK                  (0x8U)
#define PCC4_PCC_TPM6_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC4_PCC_TPM6_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM6_FRAC_SHIFT)) & PCC4_PCC_TPM6_FRAC_MASK)

#define PCC4_PCC_TPM6_SSADO_MASK                 (0xC00000U)
#define PCC4_PCC_TPM6_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_TPM6_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM6_SSADO_SHIFT)) & PCC4_PCC_TPM6_SSADO_MASK)

#define PCC4_PCC_TPM6_PCS_MASK                   (0x7000000U)
#define PCC4_PCC_TPM6_PCS_SHIFT                  (24U)
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
#define PCC4_PCC_TPM6_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM6_PCS_SHIFT)) & PCC4_PCC_TPM6_PCS_MASK)

#define PCC4_PCC_TPM6_SWRST_MASK                 (0x10000000U)
#define PCC4_PCC_TPM6_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_TPM6_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM6_SWRST_SHIFT)) & PCC4_PCC_TPM6_SWRST_MASK)

#define PCC4_PCC_TPM6_CGC_MASK                   (0x40000000U)
#define PCC4_PCC_TPM6_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_TPM6_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM6_CGC_SHIFT)) & PCC4_PCC_TPM6_CGC_MASK)

#define PCC4_PCC_TPM6_PR_MASK                    (0x80000000U)
#define PCC4_PCC_TPM6_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_TPM6_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM6_PR_SHIFT)) & PCC4_PCC_TPM6_PR_MASK)
/*! @} */

/*! @name PCC_TPM7 - PCC TPM7 Register */
/*! @{ */

#define PCC4_PCC_TPM7_PCD_MASK                   (0x7U)
#define PCC4_PCC_TPM7_PCD_SHIFT                  (0U)
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
#define PCC4_PCC_TPM7_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM7_PCD_SHIFT)) & PCC4_PCC_TPM7_PCD_MASK)

#define PCC4_PCC_TPM7_FRAC_MASK                  (0x8U)
#define PCC4_PCC_TPM7_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC4_PCC_TPM7_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM7_FRAC_SHIFT)) & PCC4_PCC_TPM7_FRAC_MASK)

#define PCC4_PCC_TPM7_SSADO_MASK                 (0xC00000U)
#define PCC4_PCC_TPM7_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_TPM7_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM7_SSADO_SHIFT)) & PCC4_PCC_TPM7_SSADO_MASK)

#define PCC4_PCC_TPM7_PCS_MASK                   (0x7000000U)
#define PCC4_PCC_TPM7_PCS_SHIFT                  (24U)
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
#define PCC4_PCC_TPM7_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM7_PCS_SHIFT)) & PCC4_PCC_TPM7_PCS_MASK)

#define PCC4_PCC_TPM7_SWRST_MASK                 (0x10000000U)
#define PCC4_PCC_TPM7_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_TPM7_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM7_SWRST_SHIFT)) & PCC4_PCC_TPM7_SWRST_MASK)

#define PCC4_PCC_TPM7_CGC_MASK                   (0x40000000U)
#define PCC4_PCC_TPM7_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_TPM7_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM7_CGC_SHIFT)) & PCC4_PCC_TPM7_CGC_MASK)

#define PCC4_PCC_TPM7_PR_MASK                    (0x80000000U)
#define PCC4_PCC_TPM7_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_TPM7_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_TPM7_PR_SHIFT)) & PCC4_PCC_TPM7_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C6 - PCC LPI2C6 Register */
/*! @{ */

#define PCC4_PCC_LPI2C6_PCD_MASK                 (0x7U)
#define PCC4_PCC_LPI2C6_PCD_SHIFT                (0U)
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
#define PCC4_PCC_LPI2C6_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C6_PCD_SHIFT)) & PCC4_PCC_LPI2C6_PCD_MASK)

#define PCC4_PCC_LPI2C6_FRAC_MASK                (0x8U)
#define PCC4_PCC_LPI2C6_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC4_PCC_LPI2C6_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C6_FRAC_SHIFT)) & PCC4_PCC_LPI2C6_FRAC_MASK)

#define PCC4_PCC_LPI2C6_SSADO_MASK               (0xC00000U)
#define PCC4_PCC_LPI2C6_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_LPI2C6_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C6_SSADO_SHIFT)) & PCC4_PCC_LPI2C6_SSADO_MASK)

#define PCC4_PCC_LPI2C6_PCS_MASK                 (0x7000000U)
#define PCC4_PCC_LPI2C6_PCS_SHIFT                (24U)
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
#define PCC4_PCC_LPI2C6_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C6_PCS_SHIFT)) & PCC4_PCC_LPI2C6_PCS_MASK)

#define PCC4_PCC_LPI2C6_SWRST_MASK               (0x10000000U)
#define PCC4_PCC_LPI2C6_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_LPI2C6_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C6_SWRST_SHIFT)) & PCC4_PCC_LPI2C6_SWRST_MASK)

#define PCC4_PCC_LPI2C6_CGC_MASK                 (0x40000000U)
#define PCC4_PCC_LPI2C6_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_LPI2C6_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C6_CGC_SHIFT)) & PCC4_PCC_LPI2C6_CGC_MASK)

#define PCC4_PCC_LPI2C6_PR_MASK                  (0x80000000U)
#define PCC4_PCC_LPI2C6_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_LPI2C6_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C6_PR_SHIFT)) & PCC4_PCC_LPI2C6_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C7 - PCC LPI2C7 Register */
/*! @{ */

#define PCC4_PCC_LPI2C7_PCD_MASK                 (0x7U)
#define PCC4_PCC_LPI2C7_PCD_SHIFT                (0U)
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
#define PCC4_PCC_LPI2C7_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C7_PCD_SHIFT)) & PCC4_PCC_LPI2C7_PCD_MASK)

#define PCC4_PCC_LPI2C7_FRAC_MASK                (0x8U)
#define PCC4_PCC_LPI2C7_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC4_PCC_LPI2C7_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C7_FRAC_SHIFT)) & PCC4_PCC_LPI2C7_FRAC_MASK)

#define PCC4_PCC_LPI2C7_SSADO_MASK               (0xC00000U)
#define PCC4_PCC_LPI2C7_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_LPI2C7_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C7_SSADO_SHIFT)) & PCC4_PCC_LPI2C7_SSADO_MASK)

#define PCC4_PCC_LPI2C7_PCS_MASK                 (0x7000000U)
#define PCC4_PCC_LPI2C7_PCS_SHIFT                (24U)
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
#define PCC4_PCC_LPI2C7_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C7_PCS_SHIFT)) & PCC4_PCC_LPI2C7_PCS_MASK)

#define PCC4_PCC_LPI2C7_SWRST_MASK               (0x10000000U)
#define PCC4_PCC_LPI2C7_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_LPI2C7_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C7_SWRST_SHIFT)) & PCC4_PCC_LPI2C7_SWRST_MASK)

#define PCC4_PCC_LPI2C7_CGC_MASK                 (0x40000000U)
#define PCC4_PCC_LPI2C7_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_LPI2C7_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C7_CGC_SHIFT)) & PCC4_PCC_LPI2C7_CGC_MASK)

#define PCC4_PCC_LPI2C7_PR_MASK                  (0x80000000U)
#define PCC4_PCC_LPI2C7_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_LPI2C7_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPI2C7_PR_SHIFT)) & PCC4_PCC_LPI2C7_PR_MASK)
/*! @} */

/*! @name PCC_LPUART6 - PCC LPUART6 Register */
/*! @{ */

#define PCC4_PCC_LPUART6_PCD_MASK                (0x7U)
#define PCC4_PCC_LPUART6_PCD_SHIFT               (0U)
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
#define PCC4_PCC_LPUART6_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART6_PCD_SHIFT)) & PCC4_PCC_LPUART6_PCD_MASK)

#define PCC4_PCC_LPUART6_FRAC_MASK               (0x8U)
#define PCC4_PCC_LPUART6_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC4_PCC_LPUART6_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART6_FRAC_SHIFT)) & PCC4_PCC_LPUART6_FRAC_MASK)

#define PCC4_PCC_LPUART6_SSADO_MASK              (0xC00000U)
#define PCC4_PCC_LPUART6_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_LPUART6_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART6_SSADO_SHIFT)) & PCC4_PCC_LPUART6_SSADO_MASK)

#define PCC4_PCC_LPUART6_PCS_MASK                (0x7000000U)
#define PCC4_PCC_LPUART6_PCS_SHIFT               (24U)
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
#define PCC4_PCC_LPUART6_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART6_PCS_SHIFT)) & PCC4_PCC_LPUART6_PCS_MASK)

#define PCC4_PCC_LPUART6_SWRST_MASK              (0x10000000U)
#define PCC4_PCC_LPUART6_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_LPUART6_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART6_SWRST_SHIFT)) & PCC4_PCC_LPUART6_SWRST_MASK)

#define PCC4_PCC_LPUART6_CGC_MASK                (0x40000000U)
#define PCC4_PCC_LPUART6_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_LPUART6_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART6_CGC_SHIFT)) & PCC4_PCC_LPUART6_CGC_MASK)

#define PCC4_PCC_LPUART6_PR_MASK                 (0x80000000U)
#define PCC4_PCC_LPUART6_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_LPUART6_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART6_PR_SHIFT)) & PCC4_PCC_LPUART6_PR_MASK)
/*! @} */

/*! @name PCC_LPUART7 - PCC LPUART7 Register */
/*! @{ */

#define PCC4_PCC_LPUART7_PCD_MASK                (0x7U)
#define PCC4_PCC_LPUART7_PCD_SHIFT               (0U)
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
#define PCC4_PCC_LPUART7_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART7_PCD_SHIFT)) & PCC4_PCC_LPUART7_PCD_MASK)

#define PCC4_PCC_LPUART7_FRAC_MASK               (0x8U)
#define PCC4_PCC_LPUART7_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC4_PCC_LPUART7_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART7_FRAC_SHIFT)) & PCC4_PCC_LPUART7_FRAC_MASK)

#define PCC4_PCC_LPUART7_SSADO_MASK              (0xC00000U)
#define PCC4_PCC_LPUART7_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_LPUART7_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART7_SSADO_SHIFT)) & PCC4_PCC_LPUART7_SSADO_MASK)

#define PCC4_PCC_LPUART7_PCS_MASK                (0x7000000U)
#define PCC4_PCC_LPUART7_PCS_SHIFT               (24U)
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
#define PCC4_PCC_LPUART7_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART7_PCS_SHIFT)) & PCC4_PCC_LPUART7_PCS_MASK)

#define PCC4_PCC_LPUART7_SWRST_MASK              (0x10000000U)
#define PCC4_PCC_LPUART7_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_LPUART7_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART7_SWRST_SHIFT)) & PCC4_PCC_LPUART7_SWRST_MASK)

#define PCC4_PCC_LPUART7_CGC_MASK                (0x40000000U)
#define PCC4_PCC_LPUART7_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_LPUART7_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART7_CGC_SHIFT)) & PCC4_PCC_LPUART7_CGC_MASK)

#define PCC4_PCC_LPUART7_PR_MASK                 (0x80000000U)
#define PCC4_PCC_LPUART7_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_LPUART7_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_LPUART7_PR_SHIFT)) & PCC4_PCC_LPUART7_PR_MASK)
/*! @} */

/*! @name PCC_SAI4 - PCC SAI4 Register */
/*! @{ */

#define PCC4_PCC_SAI4_SSADO_MASK                 (0xC00000U)
#define PCC4_PCC_SAI4_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_SAI4_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_SAI4_SSADO_SHIFT)) & PCC4_PCC_SAI4_SSADO_MASK)

#define PCC4_PCC_SAI4_SWRST_MASK                 (0x10000000U)
#define PCC4_PCC_SAI4_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_SAI4_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_SAI4_SWRST_SHIFT)) & PCC4_PCC_SAI4_SWRST_MASK)

#define PCC4_PCC_SAI4_CGC_MASK                   (0x40000000U)
#define PCC4_PCC_SAI4_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_SAI4_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_SAI4_CGC_SHIFT)) & PCC4_PCC_SAI4_CGC_MASK)

#define PCC4_PCC_SAI4_PR_MASK                    (0x80000000U)
#define PCC4_PCC_SAI4_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_SAI4_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_SAI4_PR_SHIFT)) & PCC4_PCC_SAI4_PR_MASK)
/*! @} */

/*! @name PCC_SAI5 - PCC SAI5 Register */
/*! @{ */

#define PCC4_PCC_SAI5_SSADO_MASK                 (0xC00000U)
#define PCC4_PCC_SAI5_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_SAI5_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_SAI5_SSADO_SHIFT)) & PCC4_PCC_SAI5_SSADO_MASK)

#define PCC4_PCC_SAI5_SWRST_MASK                 (0x10000000U)
#define PCC4_PCC_SAI5_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_SAI5_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_SAI5_SWRST_SHIFT)) & PCC4_PCC_SAI5_SWRST_MASK)

#define PCC4_PCC_SAI5_CGC_MASK                   (0x40000000U)
#define PCC4_PCC_SAI5_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_SAI5_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_SAI5_CGC_SHIFT)) & PCC4_PCC_SAI5_CGC_MASK)

#define PCC4_PCC_SAI5_PR_MASK                    (0x80000000U)
#define PCC4_PCC_SAI5_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_SAI5_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_SAI5_PR_SHIFT)) & PCC4_PCC_SAI5_PR_MASK)
/*! @} */

/*! @name PCC_DIGITAL_FILTER_E - PCC DIGITAL_FILTER_E Register */
/*! @{ */

#define PCC4_PCC_DIGITAL_FILTER_E_SSADO_MASK     (0xC00000U)
#define PCC4_PCC_DIGITAL_FILTER_E_SSADO_SHIFT    (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_DIGITAL_FILTER_E_SSADO(x)       (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_DIGITAL_FILTER_E_SSADO_SHIFT)) & PCC4_PCC_DIGITAL_FILTER_E_SSADO_MASK)

#define PCC4_PCC_DIGITAL_FILTER_E_CGC_MASK       (0x40000000U)
#define PCC4_PCC_DIGITAL_FILTER_E_CGC_SHIFT      (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_DIGITAL_FILTER_E_CGC(x)         (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_DIGITAL_FILTER_E_CGC_SHIFT)) & PCC4_PCC_DIGITAL_FILTER_E_CGC_MASK)

#define PCC4_PCC_DIGITAL_FILTER_E_PR_MASK        (0x80000000U)
#define PCC4_PCC_DIGITAL_FILTER_E_PR_SHIFT       (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_DIGITAL_FILTER_E_PR(x)          (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_DIGITAL_FILTER_E_PR_SHIFT)) & PCC4_PCC_DIGITAL_FILTER_E_PR_MASK)
/*! @} */

/*! @name PCC_DIGITAL_FILTER_F - PCC DIGITAL_FILTER_F Register */
/*! @{ */

#define PCC4_PCC_DIGITAL_FILTER_F_SSADO_MASK     (0xC00000U)
#define PCC4_PCC_DIGITAL_FILTER_F_SSADO_SHIFT    (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_DIGITAL_FILTER_F_SSADO(x)       (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_DIGITAL_FILTER_F_SSADO_SHIFT)) & PCC4_PCC_DIGITAL_FILTER_F_SSADO_MASK)

#define PCC4_PCC_DIGITAL_FILTER_F_CGC_MASK       (0x40000000U)
#define PCC4_PCC_DIGITAL_FILTER_F_CGC_SHIFT      (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_DIGITAL_FILTER_F_CGC(x)         (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_DIGITAL_FILTER_F_CGC_SHIFT)) & PCC4_PCC_DIGITAL_FILTER_F_CGC_MASK)

#define PCC4_PCC_DIGITAL_FILTER_F_PR_MASK        (0x80000000U)
#define PCC4_PCC_DIGITAL_FILTER_F_PR_SHIFT       (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_DIGITAL_FILTER_F_PR(x)          (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_DIGITAL_FILTER_F_PR_SHIFT)) & PCC4_PCC_DIGITAL_FILTER_F_PR_MASK)
/*! @} */

/*! @name PCC_USDHC0 - PCC uSDHC0 Register */
/*! @{ */

#define PCC4_PCC_USDHC0_SSADO_MASK               (0xC00000U)
#define PCC4_PCC_USDHC0_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_USDHC0_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC0_SSADO_SHIFT)) & PCC4_PCC_USDHC0_SSADO_MASK)

#define PCC4_PCC_USDHC0_PCS_MASK                 (0x7000000U)
#define PCC4_PCC_USDHC0_PCS_SHIFT                (24U)
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
#define PCC4_PCC_USDHC0_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC0_PCS_SHIFT)) & PCC4_PCC_USDHC0_PCS_MASK)

#define PCC4_PCC_USDHC0_SWRST_MASK               (0x10000000U)
#define PCC4_PCC_USDHC0_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_USDHC0_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC0_SWRST_SHIFT)) & PCC4_PCC_USDHC0_SWRST_MASK)

#define PCC4_PCC_USDHC0_CGC_MASK                 (0x40000000U)
#define PCC4_PCC_USDHC0_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_USDHC0_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC0_CGC_SHIFT)) & PCC4_PCC_USDHC0_CGC_MASK)

#define PCC4_PCC_USDHC0_PR_MASK                  (0x80000000U)
#define PCC4_PCC_USDHC0_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_USDHC0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC0_PR_SHIFT)) & PCC4_PCC_USDHC0_PR_MASK)
/*! @} */

/*! @name PCC_USDHC1 - PCC uSDHC1 Register */
/*! @{ */

#define PCC4_PCC_USDHC1_SSADO_MASK               (0xC00000U)
#define PCC4_PCC_USDHC1_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_USDHC1_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC1_SSADO_SHIFT)) & PCC4_PCC_USDHC1_SSADO_MASK)

#define PCC4_PCC_USDHC1_PCS_MASK                 (0x7000000U)
#define PCC4_PCC_USDHC1_PCS_SHIFT                (24U)
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
#define PCC4_PCC_USDHC1_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC1_PCS_SHIFT)) & PCC4_PCC_USDHC1_PCS_MASK)

#define PCC4_PCC_USDHC1_SWRST_MASK               (0x10000000U)
#define PCC4_PCC_USDHC1_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_USDHC1_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC1_SWRST_SHIFT)) & PCC4_PCC_USDHC1_SWRST_MASK)

#define PCC4_PCC_USDHC1_CGC_MASK                 (0x40000000U)
#define PCC4_PCC_USDHC1_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_USDHC1_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC1_CGC_SHIFT)) & PCC4_PCC_USDHC1_CGC_MASK)

#define PCC4_PCC_USDHC1_PR_MASK                  (0x80000000U)
#define PCC4_PCC_USDHC1_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_USDHC1_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC1_PR_SHIFT)) & PCC4_PCC_USDHC1_PR_MASK)
/*! @} */

/*! @name PCC_USDHC2 - PCC uSDHC2 Register */
/*! @{ */

#define PCC4_PCC_USDHC2_SSADO_MASK               (0xC00000U)
#define PCC4_PCC_USDHC2_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_USDHC2_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC2_SSADO_SHIFT)) & PCC4_PCC_USDHC2_SSADO_MASK)

#define PCC4_PCC_USDHC2_PCS_MASK                 (0x7000000U)
#define PCC4_PCC_USDHC2_PCS_SHIFT                (24U)
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
#define PCC4_PCC_USDHC2_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC2_PCS_SHIFT)) & PCC4_PCC_USDHC2_PCS_MASK)

#define PCC4_PCC_USDHC2_SWRST_MASK               (0x10000000U)
#define PCC4_PCC_USDHC2_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_USDHC2_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC2_SWRST_SHIFT)) & PCC4_PCC_USDHC2_SWRST_MASK)

#define PCC4_PCC_USDHC2_CGC_MASK                 (0x40000000U)
#define PCC4_PCC_USDHC2_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_USDHC2_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC2_CGC_SHIFT)) & PCC4_PCC_USDHC2_CGC_MASK)

#define PCC4_PCC_USDHC2_PR_MASK                  (0x80000000U)
#define PCC4_PCC_USDHC2_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_USDHC2_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USDHC2_PR_SHIFT)) & PCC4_PCC_USDHC2_PR_MASK)
/*! @} */

/*! @name PCC_USB0 - PCC USB0 Register */
/*! @{ */

#define PCC4_PCC_USB0_SSADO_MASK                 (0xC00000U)
#define PCC4_PCC_USB0_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_USB0_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB0_SSADO_SHIFT)) & PCC4_PCC_USB0_SSADO_MASK)

#define PCC4_PCC_USB0_SWRST_MASK                 (0x10000000U)
#define PCC4_PCC_USB0_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_USB0_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB0_SWRST_SHIFT)) & PCC4_PCC_USB0_SWRST_MASK)

#define PCC4_PCC_USB0_CGC_MASK                   (0x40000000U)
#define PCC4_PCC_USB0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_USB0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB0_CGC_SHIFT)) & PCC4_PCC_USB0_CGC_MASK)

#define PCC4_PCC_USB0_PR_MASK                    (0x80000000U)
#define PCC4_PCC_USB0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_USB0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB0_PR_SHIFT)) & PCC4_PCC_USB0_PR_MASK)
/*! @} */

/*! @name PCC_USB0_PHY - PCC USB0_PHY Register */
/*! @{ */

#define PCC4_PCC_USB0_PHY_SSADO_MASK             (0xC00000U)
#define PCC4_PCC_USB0_PHY_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_USB0_PHY_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB0_PHY_SSADO_SHIFT)) & PCC4_PCC_USB0_PHY_SSADO_MASK)

#define PCC4_PCC_USB0_PHY_SWRST_MASK             (0x10000000U)
#define PCC4_PCC_USB0_PHY_SWRST_SHIFT            (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_USB0_PHY_SWRST(x)               (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB0_PHY_SWRST_SHIFT)) & PCC4_PCC_USB0_PHY_SWRST_MASK)

#define PCC4_PCC_USB0_PHY_CGC_MASK               (0x40000000U)
#define PCC4_PCC_USB0_PHY_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_USB0_PHY_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB0_PHY_CGC_SHIFT)) & PCC4_PCC_USB0_PHY_CGC_MASK)

#define PCC4_PCC_USB0_PHY_PR_MASK                (0x80000000U)
#define PCC4_PCC_USB0_PHY_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_USB0_PHY_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB0_PHY_PR_SHIFT)) & PCC4_PCC_USB0_PHY_PR_MASK)
/*! @} */

/*! @name PCC_USB1 - PCC USB1 Register */
/*! @{ */

#define PCC4_PCC_USB1_SSADO_MASK                 (0xC00000U)
#define PCC4_PCC_USB1_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_USB1_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB1_SSADO_SHIFT)) & PCC4_PCC_USB1_SSADO_MASK)

#define PCC4_PCC_USB1_SWRST_MASK                 (0x10000000U)
#define PCC4_PCC_USB1_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_USB1_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB1_SWRST_SHIFT)) & PCC4_PCC_USB1_SWRST_MASK)

#define PCC4_PCC_USB1_CGC_MASK                   (0x40000000U)
#define PCC4_PCC_USB1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_USB1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB1_CGC_SHIFT)) & PCC4_PCC_USB1_CGC_MASK)

#define PCC4_PCC_USB1_PR_MASK                    (0x80000000U)
#define PCC4_PCC_USB1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_USB1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB1_PR_SHIFT)) & PCC4_PCC_USB1_PR_MASK)
/*! @} */

/*! @name PCC_USB1_PHY - PCC USB1_PHY Register */
/*! @{ */

#define PCC4_PCC_USB1_PHY_SSADO_MASK             (0xC00000U)
#define PCC4_PCC_USB1_PHY_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_USB1_PHY_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB1_PHY_SSADO_SHIFT)) & PCC4_PCC_USB1_PHY_SSADO_MASK)

#define PCC4_PCC_USB1_PHY_SWRST_MASK             (0x10000000U)
#define PCC4_PCC_USB1_PHY_SWRST_SHIFT            (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_USB1_PHY_SWRST(x)               (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB1_PHY_SWRST_SHIFT)) & PCC4_PCC_USB1_PHY_SWRST_MASK)

#define PCC4_PCC_USB1_PHY_CGC_MASK               (0x40000000U)
#define PCC4_PCC_USB1_PHY_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_USB1_PHY_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB1_PHY_CGC_SHIFT)) & PCC4_PCC_USB1_PHY_CGC_MASK)

#define PCC4_PCC_USB1_PHY_PR_MASK                (0x80000000U)
#define PCC4_PCC_USB1_PHY_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_USB1_PHY_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB1_PHY_PR_SHIFT)) & PCC4_PCC_USB1_PHY_PR_MASK)
/*! @} */

/*! @name PCC_USB_XBAR - PCC USB_XBAR Register */
/*! @{ */

#define PCC4_PCC_USB_XBAR_SSADO_MASK             (0xC00000U)
#define PCC4_PCC_USB_XBAR_SSADO_SHIFT            (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_USB_XBAR_SSADO(x)               (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB_XBAR_SSADO_SHIFT)) & PCC4_PCC_USB_XBAR_SSADO_MASK)

#define PCC4_PCC_USB_XBAR_CGC_MASK               (0x40000000U)
#define PCC4_PCC_USB_XBAR_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_USB_XBAR_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB_XBAR_CGC_SHIFT)) & PCC4_PCC_USB_XBAR_CGC_MASK)

#define PCC4_PCC_USB_XBAR_PR_MASK                (0x80000000U)
#define PCC4_PCC_USB_XBAR_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_USB_XBAR_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_USB_XBAR_PR_SHIFT)) & PCC4_PCC_USB_XBAR_PR_MASK)
/*! @} */

/*! @name PCC_ENET - PCC ENET Register */
/*! @{ */

#define PCC4_PCC_ENET_SSADO_MASK                 (0xC00000U)
#define PCC4_PCC_ENET_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_ENET_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_ENET_SSADO_SHIFT)) & PCC4_PCC_ENET_SSADO_MASK)

#define PCC4_PCC_ENET_SWRST_MASK                 (0x10000000U)
#define PCC4_PCC_ENET_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC4_PCC_ENET_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_ENET_SWRST_SHIFT)) & PCC4_PCC_ENET_SWRST_MASK)

#define PCC4_PCC_ENET_CGC_MASK                   (0x40000000U)
#define PCC4_PCC_ENET_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_ENET_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_ENET_CGC_SHIFT)) & PCC4_PCC_ENET_CGC_MASK)

#define PCC4_PCC_ENET_PR_MASK                    (0x80000000U)
#define PCC4_PCC_ENET_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_ENET_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_ENET_PR_SHIFT)) & PCC4_PCC_ENET_PR_MASK)
/*! @} */

/*! @name PCC_RGPIOE - PCC RGPIOE Register */
/*! @{ */

#define PCC4_PCC_RGPIOE_SSADO_MASK               (0xC00000U)
#define PCC4_PCC_RGPIOE_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_RGPIOE_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_RGPIOE_SSADO_SHIFT)) & PCC4_PCC_RGPIOE_SSADO_MASK)

#define PCC4_PCC_RGPIOE_CGC_MASK                 (0x40000000U)
#define PCC4_PCC_RGPIOE_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_RGPIOE_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_RGPIOE_CGC_SHIFT)) & PCC4_PCC_RGPIOE_CGC_MASK)

#define PCC4_PCC_RGPIOE_PR_MASK                  (0x80000000U)
#define PCC4_PCC_RGPIOE_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_RGPIOE_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_RGPIOE_PR_SHIFT)) & PCC4_PCC_RGPIOE_PR_MASK)
/*! @} */

/*! @name PCC_RGPIOF - PCC RGPIOF Register */
/*! @{ */

#define PCC4_PCC_RGPIOF_SSADO_MASK               (0xC00000U)
#define PCC4_PCC_RGPIOF_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC4_PCC_RGPIOF_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_RGPIOF_SSADO_SHIFT)) & PCC4_PCC_RGPIOF_SSADO_MASK)

#define PCC4_PCC_RGPIOF_CGC_MASK                 (0x40000000U)
#define PCC4_PCC_RGPIOF_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC4_PCC_RGPIOF_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_RGPIOF_CGC_SHIFT)) & PCC4_PCC_RGPIOF_CGC_MASK)

#define PCC4_PCC_RGPIOF_PR_MASK                  (0x80000000U)
#define PCC4_PCC_RGPIOF_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC4_PCC_RGPIOF_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC4_PCC_RGPIOF_PR_SHIFT)) & PCC4_PCC_RGPIOF_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCC4_Register_Masks */


/*!
 * @}
 */ /* end of group PCC4_Peripheral_Access_Layer */


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


#endif  /* PERI_PCC4_H_ */

