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
**         CMSIS Peripheral Access Layer for PCC3
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
 * @file PERI_PCC3.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC3
 *
 * CMSIS Peripheral Access Layer for PCC3
 */

#if !defined(PERI_PCC3_H_)
#define PERI_PCC3_H_                             /**< Symbol preventing repeated inclusion */

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
   -- PCC3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC3_Peripheral_Access_Layer PCC3 Peripheral Access Layer
 * @{
 */

/** PCC3 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[132];
  __IO uint32_t PCC_TPM6;                          /**< PCC TPM6 Register, offset: 0x84 */
  __IO uint32_t PCC_TPM7;                          /**< PCC TPM7 Register, offset: 0x88 */
       uint8_t RESERVED_1[4];
  __IO uint32_t PCC_LPI2C6;                        /**< PCC LPI2C6 Register, offset: 0x90 */
  __IO uint32_t PCC_LPI2C7;                        /**< PCC LPI2C7 Register, offset: 0x94 */
  __IO uint32_t PCC_LPUART6;                       /**< PCC LPUART6 Register, offset: 0x98 */
  __IO uint32_t PCC_LPUART7;                       /**< PCC LPUART7 Register, offset: 0x9C */
  __IO uint32_t PCC_VIU;                           /**< PCC VIU Register, offset: 0xA0 */
  __IO uint32_t PCC_DSI;                           /**< PCC DSI Register, offset: 0xA4 */
  __IO uint32_t PCC_LCDIF;                         /**< PCC LCDIF Register, offset: 0xA8 */
  __IO uint32_t PCC_MMDC;                          /**< PCC MMDC Register, offset: 0xAC */
       uint8_t RESERVED_2[8];
  __IO uint32_t PCC_PCTLC;                         /**< PCC PCTLC Register, offset: 0xB8 */
  __IO uint32_t PCC_PCTLD;                         /**< PCC PCTLD Register, offset: 0xBC */
  __IO uint32_t PCC_PCTLE;                         /**< PCC PCTLE Register, offset: 0xC0 */
  __IO uint32_t PCC_PCTLF;                         /**< PCC PCTLF Register, offset: 0xC4 */
       uint8_t RESERVED_3[120];
  __IO uint32_t PCC_GPU3D;                         /**< PCC GPU3D Register, offset: 0x140 */
  __IO uint32_t PCC_GPU2D;                         /**< PCC GPU2D Register, offset: 0x144 */
} PCC3_Type;

/* ----------------------------------------------------------------------------
   -- PCC3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC3_Register_Masks PCC3 Register Masks
 * @{
 */

/*! @name PCC_TPM6 - PCC TPM6 Register */
/*! @{ */

#define PCC3_PCC_TPM6_PCS_MASK                   (0x7000000U)
#define PCC3_PCC_TPM6_PCS_SHIFT                  (24U)
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
#define PCC3_PCC_TPM6_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM6_PCS_SHIFT)) & PCC3_PCC_TPM6_PCS_MASK)

#define PCC3_PCC_TPM6_INUSE_MASK                 (0x20000000U)
#define PCC3_PCC_TPM6_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_TPM6_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM6_INUSE_SHIFT)) & PCC3_PCC_TPM6_INUSE_MASK)

#define PCC3_PCC_TPM6_CGC_MASK                   (0x40000000U)
#define PCC3_PCC_TPM6_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_TPM6_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM6_CGC_SHIFT)) & PCC3_PCC_TPM6_CGC_MASK)

#define PCC3_PCC_TPM6_PR_MASK                    (0x80000000U)
#define PCC3_PCC_TPM6_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_TPM6_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM6_PR_SHIFT)) & PCC3_PCC_TPM6_PR_MASK)
/*! @} */

/*! @name PCC_TPM7 - PCC TPM7 Register */
/*! @{ */

#define PCC3_PCC_TPM7_PCS_MASK                   (0x7000000U)
#define PCC3_PCC_TPM7_PCS_SHIFT                  (24U)
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
#define PCC3_PCC_TPM7_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM7_PCS_SHIFT)) & PCC3_PCC_TPM7_PCS_MASK)

#define PCC3_PCC_TPM7_INUSE_MASK                 (0x20000000U)
#define PCC3_PCC_TPM7_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_TPM7_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM7_INUSE_SHIFT)) & PCC3_PCC_TPM7_INUSE_MASK)

#define PCC3_PCC_TPM7_CGC_MASK                   (0x40000000U)
#define PCC3_PCC_TPM7_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_TPM7_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM7_CGC_SHIFT)) & PCC3_PCC_TPM7_CGC_MASK)

#define PCC3_PCC_TPM7_PR_MASK                    (0x80000000U)
#define PCC3_PCC_TPM7_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_TPM7_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_TPM7_PR_SHIFT)) & PCC3_PCC_TPM7_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C6 - PCC LPI2C6 Register */
/*! @{ */

#define PCC3_PCC_LPI2C6_PCS_MASK                 (0x7000000U)
#define PCC3_PCC_LPI2C6_PCS_SHIFT                (24U)
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
#define PCC3_PCC_LPI2C6_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C6_PCS_SHIFT)) & PCC3_PCC_LPI2C6_PCS_MASK)

#define PCC3_PCC_LPI2C6_INUSE_MASK               (0x20000000U)
#define PCC3_PCC_LPI2C6_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_LPI2C6_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C6_INUSE_SHIFT)) & PCC3_PCC_LPI2C6_INUSE_MASK)

#define PCC3_PCC_LPI2C6_CGC_MASK                 (0x40000000U)
#define PCC3_PCC_LPI2C6_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LPI2C6_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C6_CGC_SHIFT)) & PCC3_PCC_LPI2C6_CGC_MASK)

#define PCC3_PCC_LPI2C6_PR_MASK                  (0x80000000U)
#define PCC3_PCC_LPI2C6_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LPI2C6_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C6_PR_SHIFT)) & PCC3_PCC_LPI2C6_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C7 - PCC LPI2C7 Register */
/*! @{ */

#define PCC3_PCC_LPI2C7_PCS_MASK                 (0x7000000U)
#define PCC3_PCC_LPI2C7_PCS_SHIFT                (24U)
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
#define PCC3_PCC_LPI2C7_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C7_PCS_SHIFT)) & PCC3_PCC_LPI2C7_PCS_MASK)

#define PCC3_PCC_LPI2C7_INUSE_MASK               (0x20000000U)
#define PCC3_PCC_LPI2C7_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_LPI2C7_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C7_INUSE_SHIFT)) & PCC3_PCC_LPI2C7_INUSE_MASK)

#define PCC3_PCC_LPI2C7_CGC_MASK                 (0x40000000U)
#define PCC3_PCC_LPI2C7_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LPI2C7_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C7_CGC_SHIFT)) & PCC3_PCC_LPI2C7_CGC_MASK)

#define PCC3_PCC_LPI2C7_PR_MASK                  (0x80000000U)
#define PCC3_PCC_LPI2C7_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LPI2C7_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPI2C7_PR_SHIFT)) & PCC3_PCC_LPI2C7_PR_MASK)
/*! @} */

/*! @name PCC_LPUART6 - PCC LPUART6 Register */
/*! @{ */

#define PCC3_PCC_LPUART6_PCS_MASK                (0x7000000U)
#define PCC3_PCC_LPUART6_PCS_SHIFT               (24U)
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
#define PCC3_PCC_LPUART6_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART6_PCS_SHIFT)) & PCC3_PCC_LPUART6_PCS_MASK)

#define PCC3_PCC_LPUART6_INUSE_MASK              (0x20000000U)
#define PCC3_PCC_LPUART6_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_LPUART6_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART6_INUSE_SHIFT)) & PCC3_PCC_LPUART6_INUSE_MASK)

#define PCC3_PCC_LPUART6_CGC_MASK                (0x40000000U)
#define PCC3_PCC_LPUART6_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LPUART6_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART6_CGC_SHIFT)) & PCC3_PCC_LPUART6_CGC_MASK)

#define PCC3_PCC_LPUART6_PR_MASK                 (0x80000000U)
#define PCC3_PCC_LPUART6_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LPUART6_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART6_PR_SHIFT)) & PCC3_PCC_LPUART6_PR_MASK)
/*! @} */

/*! @name PCC_LPUART7 - PCC LPUART7 Register */
/*! @{ */

#define PCC3_PCC_LPUART7_PCS_MASK                (0x7000000U)
#define PCC3_PCC_LPUART7_PCS_SHIFT               (24U)
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
#define PCC3_PCC_LPUART7_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART7_PCS_SHIFT)) & PCC3_PCC_LPUART7_PCS_MASK)

#define PCC3_PCC_LPUART7_INUSE_MASK              (0x20000000U)
#define PCC3_PCC_LPUART7_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_LPUART7_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART7_INUSE_SHIFT)) & PCC3_PCC_LPUART7_INUSE_MASK)

#define PCC3_PCC_LPUART7_CGC_MASK                (0x40000000U)
#define PCC3_PCC_LPUART7_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LPUART7_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART7_CGC_SHIFT)) & PCC3_PCC_LPUART7_CGC_MASK)

#define PCC3_PCC_LPUART7_PR_MASK                 (0x80000000U)
#define PCC3_PCC_LPUART7_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LPUART7_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LPUART7_PR_SHIFT)) & PCC3_PCC_LPUART7_PR_MASK)
/*! @} */

/*! @name PCC_VIU - PCC VIU Register */
/*! @{ */

#define PCC3_PCC_VIU_INUSE_MASK                  (0x20000000U)
#define PCC3_PCC_VIU_INUSE_SHIFT                 (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_VIU_INUSE(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_VIU_INUSE_SHIFT)) & PCC3_PCC_VIU_INUSE_MASK)

#define PCC3_PCC_VIU_CGC_MASK                    (0x40000000U)
#define PCC3_PCC_VIU_CGC_SHIFT                   (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_VIU_CGC(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_VIU_CGC_SHIFT)) & PCC3_PCC_VIU_CGC_MASK)

#define PCC3_PCC_VIU_PR_MASK                     (0x80000000U)
#define PCC3_PCC_VIU_PR_SHIFT                    (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_VIU_PR(x)                       (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_VIU_PR_SHIFT)) & PCC3_PCC_VIU_PR_MASK)
/*! @} */

/*! @name PCC_DSI - PCC DSI Register */
/*! @{ */

#define PCC3_PCC_DSI_PCD_MASK                    (0x7U)
#define PCC3_PCC_DSI_PCD_SHIFT                   (0U)
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
#define PCC3_PCC_DSI_PCD(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DSI_PCD_SHIFT)) & PCC3_PCC_DSI_PCD_MASK)

#define PCC3_PCC_DSI_FRAC_MASK                   (0x8U)
#define PCC3_PCC_DSI_FRAC_SHIFT                  (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_DSI_FRAC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DSI_FRAC_SHIFT)) & PCC3_PCC_DSI_FRAC_MASK)

#define PCC3_PCC_DSI_PCS_MASK                    (0x7000000U)
#define PCC3_PCC_DSI_PCS_SHIFT                   (24U)
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
#define PCC3_PCC_DSI_PCS(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DSI_PCS_SHIFT)) & PCC3_PCC_DSI_PCS_MASK)

#define PCC3_PCC_DSI_INUSE_MASK                  (0x20000000U)
#define PCC3_PCC_DSI_INUSE_SHIFT                 (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_DSI_INUSE(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DSI_INUSE_SHIFT)) & PCC3_PCC_DSI_INUSE_MASK)

#define PCC3_PCC_DSI_CGC_MASK                    (0x40000000U)
#define PCC3_PCC_DSI_CGC_SHIFT                   (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_DSI_CGC(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DSI_CGC_SHIFT)) & PCC3_PCC_DSI_CGC_MASK)

#define PCC3_PCC_DSI_PR_MASK                     (0x80000000U)
#define PCC3_PCC_DSI_PR_SHIFT                    (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_DSI_PR(x)                       (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_DSI_PR_SHIFT)) & PCC3_PCC_DSI_PR_MASK)
/*! @} */

/*! @name PCC_LCDIF - PCC LCDIF Register */
/*! @{ */

#define PCC3_PCC_LCDIF_PCD_MASK                  (0x7U)
#define PCC3_PCC_LCDIF_PCD_SHIFT                 (0U)
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
#define PCC3_PCC_LCDIF_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LCDIF_PCD_SHIFT)) & PCC3_PCC_LCDIF_PCD_MASK)

#define PCC3_PCC_LCDIF_FRAC_MASK                 (0x8U)
#define PCC3_PCC_LCDIF_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC3_PCC_LCDIF_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LCDIF_FRAC_SHIFT)) & PCC3_PCC_LCDIF_FRAC_MASK)

#define PCC3_PCC_LCDIF_PCS_MASK                  (0x7000000U)
#define PCC3_PCC_LCDIF_PCS_SHIFT                 (24U)
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
#define PCC3_PCC_LCDIF_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LCDIF_PCS_SHIFT)) & PCC3_PCC_LCDIF_PCS_MASK)

#define PCC3_PCC_LCDIF_INUSE_MASK                (0x20000000U)
#define PCC3_PCC_LCDIF_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_LCDIF_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LCDIF_INUSE_SHIFT)) & PCC3_PCC_LCDIF_INUSE_MASK)

#define PCC3_PCC_LCDIF_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_LCDIF_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_LCDIF_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LCDIF_CGC_SHIFT)) & PCC3_PCC_LCDIF_CGC_MASK)

#define PCC3_PCC_LCDIF_PR_MASK                   (0x80000000U)
#define PCC3_PCC_LCDIF_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_LCDIF_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_LCDIF_PR_SHIFT)) & PCC3_PCC_LCDIF_PR_MASK)
/*! @} */

/*! @name PCC_MMDC - PCC MMDC Register */
/*! @{ */

#define PCC3_PCC_MMDC_INUSE_MASK                 (0x20000000U)
#define PCC3_PCC_MMDC_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_MMDC_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_MMDC_INUSE_SHIFT)) & PCC3_PCC_MMDC_INUSE_MASK)

#define PCC3_PCC_MMDC_CGC_MASK                   (0x40000000U)
#define PCC3_PCC_MMDC_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_MMDC_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_MMDC_CGC_SHIFT)) & PCC3_PCC_MMDC_CGC_MASK)

#define PCC3_PCC_MMDC_PR_MASK                    (0x80000000U)
#define PCC3_PCC_MMDC_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_MMDC_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_MMDC_PR_SHIFT)) & PCC3_PCC_MMDC_PR_MASK)
/*! @} */

/*! @name PCC_PCTLC - PCC PCTLC Register */
/*! @{ */

#define PCC3_PCC_PCTLC_INUSE_MASK                (0x20000000U)
#define PCC3_PCC_PCTLC_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_PCTLC_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLC_INUSE_SHIFT)) & PCC3_PCC_PCTLC_INUSE_MASK)

#define PCC3_PCC_PCTLC_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_PCTLC_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_PCTLC_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLC_CGC_SHIFT)) & PCC3_PCC_PCTLC_CGC_MASK)

#define PCC3_PCC_PCTLC_PR_MASK                   (0x80000000U)
#define PCC3_PCC_PCTLC_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_PCTLC_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLC_PR_SHIFT)) & PCC3_PCC_PCTLC_PR_MASK)
/*! @} */

/*! @name PCC_PCTLD - PCC PCTLD Register */
/*! @{ */

#define PCC3_PCC_PCTLD_INUSE_MASK                (0x20000000U)
#define PCC3_PCC_PCTLD_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_PCTLD_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLD_INUSE_SHIFT)) & PCC3_PCC_PCTLD_INUSE_MASK)

#define PCC3_PCC_PCTLD_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_PCTLD_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_PCTLD_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLD_CGC_SHIFT)) & PCC3_PCC_PCTLD_CGC_MASK)

#define PCC3_PCC_PCTLD_PR_MASK                   (0x80000000U)
#define PCC3_PCC_PCTLD_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_PCTLD_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLD_PR_SHIFT)) & PCC3_PCC_PCTLD_PR_MASK)
/*! @} */

/*! @name PCC_PCTLE - PCC PCTLE Register */
/*! @{ */

#define PCC3_PCC_PCTLE_INUSE_MASK                (0x20000000U)
#define PCC3_PCC_PCTLE_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_PCTLE_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLE_INUSE_SHIFT)) & PCC3_PCC_PCTLE_INUSE_MASK)

#define PCC3_PCC_PCTLE_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_PCTLE_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_PCTLE_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLE_CGC_SHIFT)) & PCC3_PCC_PCTLE_CGC_MASK)

#define PCC3_PCC_PCTLE_PR_MASK                   (0x80000000U)
#define PCC3_PCC_PCTLE_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_PCTLE_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLE_PR_SHIFT)) & PCC3_PCC_PCTLE_PR_MASK)
/*! @} */

/*! @name PCC_PCTLF - PCC PCTLF Register */
/*! @{ */

#define PCC3_PCC_PCTLF_INUSE_MASK                (0x20000000U)
#define PCC3_PCC_PCTLF_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_PCTLF_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLF_INUSE_SHIFT)) & PCC3_PCC_PCTLF_INUSE_MASK)

#define PCC3_PCC_PCTLF_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_PCTLF_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_PCTLF_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLF_CGC_SHIFT)) & PCC3_PCC_PCTLF_CGC_MASK)

#define PCC3_PCC_PCTLF_PR_MASK                   (0x80000000U)
#define PCC3_PCC_PCTLF_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_PCTLF_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_PCTLF_PR_SHIFT)) & PCC3_PCC_PCTLF_PR_MASK)
/*! @} */

/*! @name PCC_GPU3D - PCC GPU3D Register */
/*! @{ */

#define PCC3_PCC_GPU3D_PCS_MASK                  (0x7000000U)
#define PCC3_PCC_GPU3D_PCS_SHIFT                 (24U)
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
#define PCC3_PCC_GPU3D_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_GPU3D_PCS_SHIFT)) & PCC3_PCC_GPU3D_PCS_MASK)

#define PCC3_PCC_GPU3D_INUSE_MASK                (0x20000000U)
#define PCC3_PCC_GPU3D_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_GPU3D_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_GPU3D_INUSE_SHIFT)) & PCC3_PCC_GPU3D_INUSE_MASK)

#define PCC3_PCC_GPU3D_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_GPU3D_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_GPU3D_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_GPU3D_CGC_SHIFT)) & PCC3_PCC_GPU3D_CGC_MASK)

#define PCC3_PCC_GPU3D_PR_MASK                   (0x80000000U)
#define PCC3_PCC_GPU3D_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_GPU3D_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_GPU3D_PR_SHIFT)) & PCC3_PCC_GPU3D_PR_MASK)
/*! @} */

/*! @name PCC_GPU2D - PCC GPU2D Register */
/*! @{ */

#define PCC3_PCC_GPU2D_PCS_MASK                  (0x7000000U)
#define PCC3_PCC_GPU2D_PCS_SHIFT                 (24U)
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
#define PCC3_PCC_GPU2D_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_GPU2D_PCS_SHIFT)) & PCC3_PCC_GPU2D_PCS_MASK)

#define PCC3_PCC_GPU2D_INUSE_MASK                (0x20000000U)
#define PCC3_PCC_GPU2D_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC3_PCC_GPU2D_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_GPU2D_INUSE_SHIFT)) & PCC3_PCC_GPU2D_INUSE_MASK)

#define PCC3_PCC_GPU2D_CGC_MASK                  (0x40000000U)
#define PCC3_PCC_GPU2D_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC3_PCC_GPU2D_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_GPU2D_CGC_SHIFT)) & PCC3_PCC_GPU2D_CGC_MASK)

#define PCC3_PCC_GPU2D_PR_MASK                   (0x80000000U)
#define PCC3_PCC_GPU2D_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC3_PCC_GPU2D_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC3_PCC_GPU2D_PR_SHIFT)) & PCC3_PCC_GPU2D_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCC3_Register_Masks */


/*!
 * @}
 */ /* end of group PCC3_Peripheral_Access_Layer */


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


#endif  /* PERI_PCC3_H_ */

