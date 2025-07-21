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
**         CMSIS Peripheral Access Layer for PCC2
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
 * @file PERI_PCC2.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC2
 *
 * CMSIS Peripheral Access Layer for PCC2
 */

#if !defined(PERI_PCC2_H_)
#define PERI_PCC2_H_                             /**< Symbol preventing repeated inclusion */

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
   -- PCC2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC2_Peripheral_Access_Layer PCC2 Peripheral Access Layer
 * @{
 */

/** PCC2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCC_MU1_B;                         /**< PCC MU1_B Register, offset: 0x0 */
  __IO uint32_t PCC_WDOG2;                         /**< PCC WDOG2 Register, offset: 0x4 */
       uint8_t RESERVED_0[12];
  __IO uint32_t PCC_TPM2;                          /**< PCC TPM2 Register, offset: 0x14 */
  __IO uint32_t PCC_TPM3;                          /**< PCC TPM3 Register, offset: 0x18 */
  __IO uint32_t PCC_MRT;                           /**< PCC MRT Register, offset: 0x1C */
  __IO uint32_t PCC_LPI2C2;                        /**< PCC LPI2C2 Register, offset: 0x20 */
  __IO uint32_t PCC_LPI2C3;                        /**< PCC LPI2C3 Register, offset: 0x24 */
  __IO uint32_t PCC_I3C1;                          /**< PCC I3C1 Register, offset: 0x28 */
  __IO uint32_t PCC_LPUART2;                       /**< PCC LPUART2 Register, offset: 0x2C */
  __IO uint32_t PCC_LPUART3;                       /**< PCC LPUART3 Register, offset: 0x30 */
  __IO uint32_t PCC_LPSPI2;                        /**< PCC LPSPI2 Register, offset: 0x34 */
  __IO uint32_t PCC_LPSPI3;                        /**< PCC LPSPI3 Register, offset: 0x38 */
  __IO uint32_t PCC_SAI2;                          /**< PCC SAI2 Register, offset: 0x3C */
  __IO uint32_t PCC_SAI3;                          /**< PCC SAI3 Register, offset: 0x40 */
  __IO uint32_t PCC_MICFIL;                        /**< PCC MICFIL Register, offset: 0x44 */
} PCC2_Type;

/* ----------------------------------------------------------------------------
   -- PCC2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC2_Register_Masks PCC2 Register Masks
 * @{
 */

/*! @name PCC_MU1_B - PCC MU1_B Register */
/*! @{ */

#define PCC2_PCC_MU1_B_SSADO_MASK                (0xC00000U)
#define PCC2_PCC_MU1_B_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_MU1_B_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_MU1_B_SSADO_SHIFT)) & PCC2_PCC_MU1_B_SSADO_MASK)

#define PCC2_PCC_MU1_B_CGC_MASK                  (0x40000000U)
#define PCC2_PCC_MU1_B_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_MU1_B_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_MU1_B_CGC_SHIFT)) & PCC2_PCC_MU1_B_CGC_MASK)

#define PCC2_PCC_MU1_B_PR_MASK                   (0x80000000U)
#define PCC2_PCC_MU1_B_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_MU1_B_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_MU1_B_PR_SHIFT)) & PCC2_PCC_MU1_B_PR_MASK)
/*! @} */

/*! @name PCC_WDOG2 - PCC WDOG2 Register */
/*! @{ */

#define PCC2_PCC_WDOG2_PCD_MASK                  (0x7U)
#define PCC2_PCC_WDOG2_PCD_SHIFT                 (0U)
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
#define PCC2_PCC_WDOG2_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG2_PCD_SHIFT)) & PCC2_PCC_WDOG2_PCD_MASK)

#define PCC2_PCC_WDOG2_FRAC_MASK                 (0x8U)
#define PCC2_PCC_WDOG2_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_WDOG2_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG2_FRAC_SHIFT)) & PCC2_PCC_WDOG2_FRAC_MASK)

#define PCC2_PCC_WDOG2_SSADO_MASK                (0xC00000U)
#define PCC2_PCC_WDOG2_SSADO_SHIFT               (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_WDOG2_SSADO(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG2_SSADO_SHIFT)) & PCC2_PCC_WDOG2_SSADO_MASK)

#define PCC2_PCC_WDOG2_PCS_MASK                  (0x7000000U)
#define PCC2_PCC_WDOG2_PCS_SHIFT                 (24U)
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
#define PCC2_PCC_WDOG2_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG2_PCS_SHIFT)) & PCC2_PCC_WDOG2_PCS_MASK)

#define PCC2_PCC_WDOG2_SWRST_MASK                (0x10000000U)
#define PCC2_PCC_WDOG2_SWRST_SHIFT               (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_WDOG2_SWRST(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG2_SWRST_SHIFT)) & PCC2_PCC_WDOG2_SWRST_MASK)

#define PCC2_PCC_WDOG2_CGC_MASK                  (0x40000000U)
#define PCC2_PCC_WDOG2_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_WDOG2_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG2_CGC_SHIFT)) & PCC2_PCC_WDOG2_CGC_MASK)

#define PCC2_PCC_WDOG2_PR_MASK                   (0x80000000U)
#define PCC2_PCC_WDOG2_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_WDOG2_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG2_PR_SHIFT)) & PCC2_PCC_WDOG2_PR_MASK)
/*! @} */

/*! @name PCC_TPM2 - PCC TPM2 Register */
/*! @{ */

#define PCC2_PCC_TPM2_PCD_MASK                   (0x7U)
#define PCC2_PCC_TPM2_PCD_SHIFT                  (0U)
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
#define PCC2_PCC_TPM2_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM2_PCD_SHIFT)) & PCC2_PCC_TPM2_PCD_MASK)

#define PCC2_PCC_TPM2_FRAC_MASK                  (0x8U)
#define PCC2_PCC_TPM2_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_TPM2_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM2_FRAC_SHIFT)) & PCC2_PCC_TPM2_FRAC_MASK)

#define PCC2_PCC_TPM2_SSADO_MASK                 (0xC00000U)
#define PCC2_PCC_TPM2_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_TPM2_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM2_SSADO_SHIFT)) & PCC2_PCC_TPM2_SSADO_MASK)

#define PCC2_PCC_TPM2_PCS_MASK                   (0x7000000U)
#define PCC2_PCC_TPM2_PCS_SHIFT                  (24U)
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
#define PCC2_PCC_TPM2_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM2_PCS_SHIFT)) & PCC2_PCC_TPM2_PCS_MASK)

#define PCC2_PCC_TPM2_SWRST_MASK                 (0x10000000U)
#define PCC2_PCC_TPM2_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_TPM2_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM2_SWRST_SHIFT)) & PCC2_PCC_TPM2_SWRST_MASK)

#define PCC2_PCC_TPM2_CGC_MASK                   (0x40000000U)
#define PCC2_PCC_TPM2_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_TPM2_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM2_CGC_SHIFT)) & PCC2_PCC_TPM2_CGC_MASK)

#define PCC2_PCC_TPM2_PR_MASK                    (0x80000000U)
#define PCC2_PCC_TPM2_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_TPM2_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM2_PR_SHIFT)) & PCC2_PCC_TPM2_PR_MASK)
/*! @} */

/*! @name PCC_TPM3 - PCC TPM3 Register */
/*! @{ */

#define PCC2_PCC_TPM3_PCD_MASK                   (0x7U)
#define PCC2_PCC_TPM3_PCD_SHIFT                  (0U)
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
#define PCC2_PCC_TPM3_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM3_PCD_SHIFT)) & PCC2_PCC_TPM3_PCD_MASK)

#define PCC2_PCC_TPM3_FRAC_MASK                  (0x8U)
#define PCC2_PCC_TPM3_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_TPM3_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM3_FRAC_SHIFT)) & PCC2_PCC_TPM3_FRAC_MASK)

#define PCC2_PCC_TPM3_SSADO_MASK                 (0xC00000U)
#define PCC2_PCC_TPM3_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_TPM3_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM3_SSADO_SHIFT)) & PCC2_PCC_TPM3_SSADO_MASK)

#define PCC2_PCC_TPM3_PCS_MASK                   (0x7000000U)
#define PCC2_PCC_TPM3_PCS_SHIFT                  (24U)
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
#define PCC2_PCC_TPM3_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM3_PCS_SHIFT)) & PCC2_PCC_TPM3_PCS_MASK)

#define PCC2_PCC_TPM3_SWRST_MASK                 (0x10000000U)
#define PCC2_PCC_TPM3_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_TPM3_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM3_SWRST_SHIFT)) & PCC2_PCC_TPM3_SWRST_MASK)

#define PCC2_PCC_TPM3_CGC_MASK                   (0x40000000U)
#define PCC2_PCC_TPM3_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_TPM3_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM3_CGC_SHIFT)) & PCC2_PCC_TPM3_CGC_MASK)

#define PCC2_PCC_TPM3_PR_MASK                    (0x80000000U)
#define PCC2_PCC_TPM3_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_TPM3_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM3_PR_SHIFT)) & PCC2_PCC_TPM3_PR_MASK)
/*! @} */

/*! @name PCC_MRT - PCC MRT Register */
/*! @{ */

#define PCC2_PCC_MRT_SSADO_MASK                  (0xC00000U)
#define PCC2_PCC_MRT_SSADO_SHIFT                 (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_MRT_SSADO(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_MRT_SSADO_SHIFT)) & PCC2_PCC_MRT_SSADO_MASK)

#define PCC2_PCC_MRT_SWRST_MASK                  (0x10000000U)
#define PCC2_PCC_MRT_SWRST_SHIFT                 (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_MRT_SWRST(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_MRT_SWRST_SHIFT)) & PCC2_PCC_MRT_SWRST_MASK)

#define PCC2_PCC_MRT_CGC_MASK                    (0x40000000U)
#define PCC2_PCC_MRT_CGC_SHIFT                   (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_MRT_CGC(x)                      (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_MRT_CGC_SHIFT)) & PCC2_PCC_MRT_CGC_MASK)

#define PCC2_PCC_MRT_PR_MASK                     (0x80000000U)
#define PCC2_PCC_MRT_PR_SHIFT                    (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_MRT_PR(x)                       (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_MRT_PR_SHIFT)) & PCC2_PCC_MRT_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C2 - PCC LPI2C2 Register */
/*! @{ */

#define PCC2_PCC_LPI2C2_PCD_MASK                 (0x7U)
#define PCC2_PCC_LPI2C2_PCD_SHIFT                (0U)
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
#define PCC2_PCC_LPI2C2_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C2_PCD_SHIFT)) & PCC2_PCC_LPI2C2_PCD_MASK)

#define PCC2_PCC_LPI2C2_FRAC_MASK                (0x8U)
#define PCC2_PCC_LPI2C2_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_LPI2C2_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C2_FRAC_SHIFT)) & PCC2_PCC_LPI2C2_FRAC_MASK)

#define PCC2_PCC_LPI2C2_SSADO_MASK               (0xC00000U)
#define PCC2_PCC_LPI2C2_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_LPI2C2_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C2_SSADO_SHIFT)) & PCC2_PCC_LPI2C2_SSADO_MASK)

#define PCC2_PCC_LPI2C2_PCS_MASK                 (0x7000000U)
#define PCC2_PCC_LPI2C2_PCS_SHIFT                (24U)
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
#define PCC2_PCC_LPI2C2_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C2_PCS_SHIFT)) & PCC2_PCC_LPI2C2_PCS_MASK)

#define PCC2_PCC_LPI2C2_SWRST_MASK               (0x10000000U)
#define PCC2_PCC_LPI2C2_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_LPI2C2_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C2_SWRST_SHIFT)) & PCC2_PCC_LPI2C2_SWRST_MASK)

#define PCC2_PCC_LPI2C2_CGC_MASK                 (0x40000000U)
#define PCC2_PCC_LPI2C2_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_LPI2C2_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C2_CGC_SHIFT)) & PCC2_PCC_LPI2C2_CGC_MASK)

#define PCC2_PCC_LPI2C2_PR_MASK                  (0x80000000U)
#define PCC2_PCC_LPI2C2_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_LPI2C2_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C2_PR_SHIFT)) & PCC2_PCC_LPI2C2_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C3 - PCC LPI2C3 Register */
/*! @{ */

#define PCC2_PCC_LPI2C3_PCD_MASK                 (0x7U)
#define PCC2_PCC_LPI2C3_PCD_SHIFT                (0U)
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
#define PCC2_PCC_LPI2C3_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C3_PCD_SHIFT)) & PCC2_PCC_LPI2C3_PCD_MASK)

#define PCC2_PCC_LPI2C3_FRAC_MASK                (0x8U)
#define PCC2_PCC_LPI2C3_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_LPI2C3_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C3_FRAC_SHIFT)) & PCC2_PCC_LPI2C3_FRAC_MASK)

#define PCC2_PCC_LPI2C3_SSADO_MASK               (0xC00000U)
#define PCC2_PCC_LPI2C3_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_LPI2C3_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C3_SSADO_SHIFT)) & PCC2_PCC_LPI2C3_SSADO_MASK)

#define PCC2_PCC_LPI2C3_PCS_MASK                 (0x7000000U)
#define PCC2_PCC_LPI2C3_PCS_SHIFT                (24U)
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
#define PCC2_PCC_LPI2C3_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C3_PCS_SHIFT)) & PCC2_PCC_LPI2C3_PCS_MASK)

#define PCC2_PCC_LPI2C3_SWRST_MASK               (0x10000000U)
#define PCC2_PCC_LPI2C3_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_LPI2C3_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C3_SWRST_SHIFT)) & PCC2_PCC_LPI2C3_SWRST_MASK)

#define PCC2_PCC_LPI2C3_CGC_MASK                 (0x40000000U)
#define PCC2_PCC_LPI2C3_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_LPI2C3_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C3_CGC_SHIFT)) & PCC2_PCC_LPI2C3_CGC_MASK)

#define PCC2_PCC_LPI2C3_PR_MASK                  (0x80000000U)
#define PCC2_PCC_LPI2C3_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_LPI2C3_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C3_PR_SHIFT)) & PCC2_PCC_LPI2C3_PR_MASK)
/*! @} */

/*! @name PCC_I3C1 - PCC I3C1 Register */
/*! @{ */

#define PCC2_PCC_I3C1_PCD_MASK                   (0x7U)
#define PCC2_PCC_I3C1_PCD_SHIFT                  (0U)
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
#define PCC2_PCC_I3C1_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_I3C1_PCD_SHIFT)) & PCC2_PCC_I3C1_PCD_MASK)

#define PCC2_PCC_I3C1_FRAC_MASK                  (0x8U)
#define PCC2_PCC_I3C1_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_I3C1_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_I3C1_FRAC_SHIFT)) & PCC2_PCC_I3C1_FRAC_MASK)

#define PCC2_PCC_I3C1_SSADO_MASK                 (0xC00000U)
#define PCC2_PCC_I3C1_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_I3C1_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_I3C1_SSADO_SHIFT)) & PCC2_PCC_I3C1_SSADO_MASK)

#define PCC2_PCC_I3C1_PCS_MASK                   (0x7000000U)
#define PCC2_PCC_I3C1_PCS_SHIFT                  (24U)
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
#define PCC2_PCC_I3C1_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_I3C1_PCS_SHIFT)) & PCC2_PCC_I3C1_PCS_MASK)

#define PCC2_PCC_I3C1_SWRST_MASK                 (0x10000000U)
#define PCC2_PCC_I3C1_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_I3C1_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_I3C1_SWRST_SHIFT)) & PCC2_PCC_I3C1_SWRST_MASK)

#define PCC2_PCC_I3C1_CGC_MASK                   (0x40000000U)
#define PCC2_PCC_I3C1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_I3C1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_I3C1_CGC_SHIFT)) & PCC2_PCC_I3C1_CGC_MASK)

#define PCC2_PCC_I3C1_PR_MASK                    (0x80000000U)
#define PCC2_PCC_I3C1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_I3C1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_I3C1_PR_SHIFT)) & PCC2_PCC_I3C1_PR_MASK)
/*! @} */

/*! @name PCC_LPUART2 - PCC LPUART2 Register */
/*! @{ */

#define PCC2_PCC_LPUART2_PCD_MASK                (0x7U)
#define PCC2_PCC_LPUART2_PCD_SHIFT               (0U)
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
#define PCC2_PCC_LPUART2_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART2_PCD_SHIFT)) & PCC2_PCC_LPUART2_PCD_MASK)

#define PCC2_PCC_LPUART2_FRAC_MASK               (0x8U)
#define PCC2_PCC_LPUART2_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_LPUART2_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART2_FRAC_SHIFT)) & PCC2_PCC_LPUART2_FRAC_MASK)

#define PCC2_PCC_LPUART2_SSADO_MASK              (0xC00000U)
#define PCC2_PCC_LPUART2_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_LPUART2_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART2_SSADO_SHIFT)) & PCC2_PCC_LPUART2_SSADO_MASK)

#define PCC2_PCC_LPUART2_PCS_MASK                (0x7000000U)
#define PCC2_PCC_LPUART2_PCS_SHIFT               (24U)
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
#define PCC2_PCC_LPUART2_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART2_PCS_SHIFT)) & PCC2_PCC_LPUART2_PCS_MASK)

#define PCC2_PCC_LPUART2_SWRST_MASK              (0x10000000U)
#define PCC2_PCC_LPUART2_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_LPUART2_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART2_SWRST_SHIFT)) & PCC2_PCC_LPUART2_SWRST_MASK)

#define PCC2_PCC_LPUART2_CGC_MASK                (0x40000000U)
#define PCC2_PCC_LPUART2_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_LPUART2_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART2_CGC_SHIFT)) & PCC2_PCC_LPUART2_CGC_MASK)

#define PCC2_PCC_LPUART2_PR_MASK                 (0x80000000U)
#define PCC2_PCC_LPUART2_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_LPUART2_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART2_PR_SHIFT)) & PCC2_PCC_LPUART2_PR_MASK)
/*! @} */

/*! @name PCC_LPUART3 - PCC LPUART3 Register */
/*! @{ */

#define PCC2_PCC_LPUART3_PCD_MASK                (0x7U)
#define PCC2_PCC_LPUART3_PCD_SHIFT               (0U)
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
#define PCC2_PCC_LPUART3_PCD(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART3_PCD_SHIFT)) & PCC2_PCC_LPUART3_PCD_MASK)

#define PCC2_PCC_LPUART3_FRAC_MASK               (0x8U)
#define PCC2_PCC_LPUART3_FRAC_SHIFT              (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_LPUART3_FRAC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART3_FRAC_SHIFT)) & PCC2_PCC_LPUART3_FRAC_MASK)

#define PCC2_PCC_LPUART3_SSADO_MASK              (0xC00000U)
#define PCC2_PCC_LPUART3_SSADO_SHIFT             (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_LPUART3_SSADO(x)                (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART3_SSADO_SHIFT)) & PCC2_PCC_LPUART3_SSADO_MASK)

#define PCC2_PCC_LPUART3_PCS_MASK                (0x7000000U)
#define PCC2_PCC_LPUART3_PCS_SHIFT               (24U)
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
#define PCC2_PCC_LPUART3_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART3_PCS_SHIFT)) & PCC2_PCC_LPUART3_PCS_MASK)

#define PCC2_PCC_LPUART3_SWRST_MASK              (0x10000000U)
#define PCC2_PCC_LPUART3_SWRST_SHIFT             (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_LPUART3_SWRST(x)                (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART3_SWRST_SHIFT)) & PCC2_PCC_LPUART3_SWRST_MASK)

#define PCC2_PCC_LPUART3_CGC_MASK                (0x40000000U)
#define PCC2_PCC_LPUART3_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_LPUART3_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART3_CGC_SHIFT)) & PCC2_PCC_LPUART3_CGC_MASK)

#define PCC2_PCC_LPUART3_PR_MASK                 (0x80000000U)
#define PCC2_PCC_LPUART3_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_LPUART3_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART3_PR_SHIFT)) & PCC2_PCC_LPUART3_PR_MASK)
/*! @} */

/*! @name PCC_LPSPI2 - PCC LPSPI2 Register */
/*! @{ */

#define PCC2_PCC_LPSPI2_PCD_MASK                 (0x7U)
#define PCC2_PCC_LPSPI2_PCD_SHIFT                (0U)
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
#define PCC2_PCC_LPSPI2_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI2_PCD_SHIFT)) & PCC2_PCC_LPSPI2_PCD_MASK)

#define PCC2_PCC_LPSPI2_FRAC_MASK                (0x8U)
#define PCC2_PCC_LPSPI2_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_LPSPI2_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI2_FRAC_SHIFT)) & PCC2_PCC_LPSPI2_FRAC_MASK)

#define PCC2_PCC_LPSPI2_SSADO_MASK               (0xC00000U)
#define PCC2_PCC_LPSPI2_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_LPSPI2_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI2_SSADO_SHIFT)) & PCC2_PCC_LPSPI2_SSADO_MASK)

#define PCC2_PCC_LPSPI2_PCS_MASK                 (0x7000000U)
#define PCC2_PCC_LPSPI2_PCS_SHIFT                (24U)
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
#define PCC2_PCC_LPSPI2_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI2_PCS_SHIFT)) & PCC2_PCC_LPSPI2_PCS_MASK)

#define PCC2_PCC_LPSPI2_SWRST_MASK               (0x10000000U)
#define PCC2_PCC_LPSPI2_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_LPSPI2_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI2_SWRST_SHIFT)) & PCC2_PCC_LPSPI2_SWRST_MASK)

#define PCC2_PCC_LPSPI2_CGC_MASK                 (0x40000000U)
#define PCC2_PCC_LPSPI2_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_LPSPI2_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI2_CGC_SHIFT)) & PCC2_PCC_LPSPI2_CGC_MASK)

#define PCC2_PCC_LPSPI2_PR_MASK                  (0x80000000U)
#define PCC2_PCC_LPSPI2_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_LPSPI2_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI2_PR_SHIFT)) & PCC2_PCC_LPSPI2_PR_MASK)
/*! @} */

/*! @name PCC_LPSPI3 - PCC LPSPI3 Register */
/*! @{ */

#define PCC2_PCC_LPSPI3_PCD_MASK                 (0x7U)
#define PCC2_PCC_LPSPI3_PCD_SHIFT                (0U)
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
#define PCC2_PCC_LPSPI3_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI3_PCD_SHIFT)) & PCC2_PCC_LPSPI3_PCD_MASK)

#define PCC2_PCC_LPSPI3_FRAC_MASK                (0x8U)
#define PCC2_PCC_LPSPI3_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_LPSPI3_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI3_FRAC_SHIFT)) & PCC2_PCC_LPSPI3_FRAC_MASK)

#define PCC2_PCC_LPSPI3_SSADO_MASK               (0xC00000U)
#define PCC2_PCC_LPSPI3_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_LPSPI3_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI3_SSADO_SHIFT)) & PCC2_PCC_LPSPI3_SSADO_MASK)

#define PCC2_PCC_LPSPI3_PCS_MASK                 (0x7000000U)
#define PCC2_PCC_LPSPI3_PCS_SHIFT                (24U)
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
#define PCC2_PCC_LPSPI3_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI3_PCS_SHIFT)) & PCC2_PCC_LPSPI3_PCS_MASK)

#define PCC2_PCC_LPSPI3_SWRST_MASK               (0x10000000U)
#define PCC2_PCC_LPSPI3_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_LPSPI3_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI3_SWRST_SHIFT)) & PCC2_PCC_LPSPI3_SWRST_MASK)

#define PCC2_PCC_LPSPI3_CGC_MASK                 (0x40000000U)
#define PCC2_PCC_LPSPI3_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_LPSPI3_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI3_CGC_SHIFT)) & PCC2_PCC_LPSPI3_CGC_MASK)

#define PCC2_PCC_LPSPI3_PR_MASK                  (0x80000000U)
#define PCC2_PCC_LPSPI3_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_LPSPI3_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI3_PR_SHIFT)) & PCC2_PCC_LPSPI3_PR_MASK)
/*! @} */

/*! @name PCC_SAI2 - PCC SAI2 Register */
/*! @{ */

#define PCC2_PCC_SAI2_SSADO_MASK                 (0xC00000U)
#define PCC2_PCC_SAI2_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_SAI2_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_SAI2_SSADO_SHIFT)) & PCC2_PCC_SAI2_SSADO_MASK)

#define PCC2_PCC_SAI2_SWRST_MASK                 (0x10000000U)
#define PCC2_PCC_SAI2_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_SAI2_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_SAI2_SWRST_SHIFT)) & PCC2_PCC_SAI2_SWRST_MASK)

#define PCC2_PCC_SAI2_CGC_MASK                   (0x40000000U)
#define PCC2_PCC_SAI2_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_SAI2_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_SAI2_CGC_SHIFT)) & PCC2_PCC_SAI2_CGC_MASK)

#define PCC2_PCC_SAI2_PR_MASK                    (0x80000000U)
#define PCC2_PCC_SAI2_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_SAI2_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_SAI2_PR_SHIFT)) & PCC2_PCC_SAI2_PR_MASK)
/*! @} */

/*! @name PCC_SAI3 - PCC SAI3 Register */
/*! @{ */

#define PCC2_PCC_SAI3_SSADO_MASK                 (0xC00000U)
#define PCC2_PCC_SAI3_SSADO_SHIFT                (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_SAI3_SSADO(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_SAI3_SSADO_SHIFT)) & PCC2_PCC_SAI3_SSADO_MASK)

#define PCC2_PCC_SAI3_SWRST_MASK                 (0x10000000U)
#define PCC2_PCC_SAI3_SWRST_SHIFT                (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_SAI3_SWRST(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_SAI3_SWRST_SHIFT)) & PCC2_PCC_SAI3_SWRST_MASK)

#define PCC2_PCC_SAI3_CGC_MASK                   (0x40000000U)
#define PCC2_PCC_SAI3_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_SAI3_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_SAI3_CGC_SHIFT)) & PCC2_PCC_SAI3_CGC_MASK)

#define PCC2_PCC_SAI3_PR_MASK                    (0x80000000U)
#define PCC2_PCC_SAI3_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_SAI3_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_SAI3_PR_SHIFT)) & PCC2_PCC_SAI3_PR_MASK)
/*! @} */

/*! @name PCC_MICFIL - PCC MICFIL Register */
/*! @{ */

#define PCC2_PCC_MICFIL_SSADO_MASK               (0xC00000U)
#define PCC2_PCC_MICFIL_SSADO_SHIFT              (22U)
/*! SSADO - Stop and "Stop ACK" Domain Owner
 *  0b00..PCC ack to both domains' stop are always 0.
 *  0b01..PCC handles ACK from PERI for domain 0 stop, and ack to domain 1 stop is always 0.
 *  0b10..PCC handles ACK from PERI for domain 1 stop, and ack to domain 0 stop is always 0.
 *  0b11..PCC handles ACK from PERI for domain 0 stop Domain 1 stop.
 */
#define PCC2_PCC_MICFIL_SSADO(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_MICFIL_SSADO_SHIFT)) & PCC2_PCC_MICFIL_SSADO_MASK)

#define PCC2_PCC_MICFIL_SWRST_MASK               (0x10000000U)
#define PCC2_PCC_MICFIL_SWRST_SHIFT              (28U)
/*! SWRST - Software Reset Control
 *  0b0..Software Reset.
 *  0b1..No SoftWare Reset.
 */
#define PCC2_PCC_MICFIL_SWRST(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_MICFIL_SWRST_SHIFT)) & PCC2_PCC_MICFIL_SWRST_MASK)

#define PCC2_PCC_MICFIL_CGC_MASK                 (0x40000000U)
#define PCC2_PCC_MICFIL_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_MICFIL_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_MICFIL_CGC_SHIFT)) & PCC2_PCC_MICFIL_CGC_MASK)

#define PCC2_PCC_MICFIL_PR_MASK                  (0x80000000U)
#define PCC2_PCC_MICFIL_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_MICFIL_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_MICFIL_PR_SHIFT)) & PCC2_PCC_MICFIL_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCC2_Register_Masks */


/*!
 * @}
 */ /* end of group PCC2_Peripheral_Access_Layer */


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


#endif  /* PERI_PCC2_H_ */

