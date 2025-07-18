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
 * @file PERI_PCC2.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC2
 *
 * CMSIS Peripheral Access Layer for PCC2
 */

#if !defined(PERI_PCC2_H_)
#define PERI_PCC2_H_                             /**< Symbol preventing repeated inclusion */

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
   -- PCC2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC2_Peripheral_Access_Layer PCC2 Peripheral Access Layer
 * @{
 */

/** PCC2 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t PCC_DMA1;                          /**< PCC DMA1 Register, offset: 0x20 */
       uint8_t RESERVED_1[24];
  __IO uint32_t PCC_RGPIO2P1;                      /**< PCC RGPIO2P1 Register, offset: 0x3C */
  __IO uint32_t PCC_FLEXBUS;                       /**< PCC FLEXBUS Register, offset: 0x40 */
       uint8_t RESERVED_2[40];
  __IO uint32_t PCC_SEMA42_1;                      /**< PCC SEMA42_1 Register, offset: 0x6C */
       uint8_t RESERVED_3[20];
  __IO uint32_t PCC_DMA_MUX1;                      /**< PCC DMA_MUX1 Register, offset: 0x84 */
       uint8_t RESERVED_4[8];
  __IO uint32_t PCC_CAAM;                          /**< PCC CAAM Register, offset: 0x90 */
  __IO uint32_t PCC_TPM4;                          /**< PCC TPM4 Register, offset: 0x94 */
  __IO uint32_t PCC_TPM5;                          /**< PCC TPM5 Register, offset: 0x98 */
  __IO uint32_t PCC_LPIT1;                         /**< PCC LPIT1 Register, offset: 0x9C */
       uint8_t RESERVED_5[4];
  __IO uint32_t PCC_LPSPI2;                        /**< PCC LPSPI2 Register, offset: 0xA4 */
  __IO uint32_t PCC_LPSPI3;                        /**< PCC LPSPI3 Register, offset: 0xA8 */
  __IO uint32_t PCC_LPI2C4;                        /**< PCC LPI2C4 Register, offset: 0xAC */
  __IO uint32_t PCC_LPI2C5;                        /**< PCC LPI2C5 Register, offset: 0xB0 */
  __IO uint32_t PCC_LPUART4;                       /**< PCC LPUART4 Register, offset: 0xB4 */
  __IO uint32_t PCC_LPUART5;                       /**< PCC LPUART5 Register, offset: 0xB8 */
       uint8_t RESERVED_6[8];
  __IO uint32_t PCC_FLEXIO1;                       /**< PCC FLEXIO1 Register, offset: 0xC4 */
       uint8_t RESERVED_7[4];
  __IO uint32_t PCC_USB0;                          /**< PCC USB0 Register, offset: 0xCC */
       uint32_t PCC_USB1;                          /**< PCC USB1 Register, offset: 0xD0 */
  __IO uint32_t PCC_USB_PHY;                       /**< PCC USB_PHY Register, offset: 0xD4 */
       uint32_t PCC_USB_PL301;                     /**< PCC USB_PL301 Register, offset: 0xD8 */
  __IO uint32_t PCC_USDHC0;                        /**< PCC USDHC0 Register, offset: 0xDC */
  __IO uint32_t PCC_USDHC1;                        /**< PCC USDHC1 Register, offset: 0xE0 */
       uint8_t RESERVED_8[16];
  __IO uint32_t PCC_WDOG1;                         /**< PCC WDOG1 Register, offset: 0xF4 */
       uint8_t RESERVED_9[20];
  __IO uint32_t PCC_WDOG2;                         /**< PCC WDOG2 Register, offset: 0x10C */
} PCC2_Type;

/* ----------------------------------------------------------------------------
   -- PCC2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC2_Register_Masks PCC2 Register Masks
 * @{
 */

/*! @name PCC_DMA1 - PCC DMA1 Register */
/*! @{ */

#define PCC2_PCC_DMA1_INUSE_MASK                 (0x20000000U)
#define PCC2_PCC_DMA1_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_DMA1_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_DMA1_INUSE_SHIFT)) & PCC2_PCC_DMA1_INUSE_MASK)

#define PCC2_PCC_DMA1_CGC_MASK                   (0x40000000U)
#define PCC2_PCC_DMA1_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_DMA1_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_DMA1_CGC_SHIFT)) & PCC2_PCC_DMA1_CGC_MASK)

#define PCC2_PCC_DMA1_PR_MASK                    (0x80000000U)
#define PCC2_PCC_DMA1_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_DMA1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_DMA1_PR_SHIFT)) & PCC2_PCC_DMA1_PR_MASK)
/*! @} */

/*! @name PCC_RGPIO2P1 - PCC RGPIO2P1 Register */
/*! @{ */

#define PCC2_PCC_RGPIO2P1_INUSE_MASK             (0x20000000U)
#define PCC2_PCC_RGPIO2P1_INUSE_SHIFT            (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_RGPIO2P1_INUSE(x)               (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_RGPIO2P1_INUSE_SHIFT)) & PCC2_PCC_RGPIO2P1_INUSE_MASK)

#define PCC2_PCC_RGPIO2P1_CGC_MASK               (0x40000000U)
#define PCC2_PCC_RGPIO2P1_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_RGPIO2P1_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_RGPIO2P1_CGC_SHIFT)) & PCC2_PCC_RGPIO2P1_CGC_MASK)

#define PCC2_PCC_RGPIO2P1_PR_MASK                (0x80000000U)
#define PCC2_PCC_RGPIO2P1_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_RGPIO2P1_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_RGPIO2P1_PR_SHIFT)) & PCC2_PCC_RGPIO2P1_PR_MASK)
/*! @} */

/*! @name PCC_FLEXBUS - PCC FLEXBUS Register */
/*! @{ */

#define PCC2_PCC_FLEXBUS_INUSE_MASK              (0x20000000U)
#define PCC2_PCC_FLEXBUS_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_FLEXBUS_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_FLEXBUS_INUSE_SHIFT)) & PCC2_PCC_FLEXBUS_INUSE_MASK)

#define PCC2_PCC_FLEXBUS_CGC_MASK                (0x40000000U)
#define PCC2_PCC_FLEXBUS_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_FLEXBUS_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_FLEXBUS_CGC_SHIFT)) & PCC2_PCC_FLEXBUS_CGC_MASK)

#define PCC2_PCC_FLEXBUS_PR_MASK                 (0x80000000U)
#define PCC2_PCC_FLEXBUS_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_FLEXBUS_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_FLEXBUS_PR_SHIFT)) & PCC2_PCC_FLEXBUS_PR_MASK)
/*! @} */

/*! @name PCC_SEMA42_1 - PCC SEMA42_1 Register */
/*! @{ */

#define PCC2_PCC_SEMA42_1_INUSE_MASK             (0x20000000U)
#define PCC2_PCC_SEMA42_1_INUSE_SHIFT            (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_SEMA42_1_INUSE(x)               (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_SEMA42_1_INUSE_SHIFT)) & PCC2_PCC_SEMA42_1_INUSE_MASK)

#define PCC2_PCC_SEMA42_1_CGC_MASK               (0x40000000U)
#define PCC2_PCC_SEMA42_1_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_SEMA42_1_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_SEMA42_1_CGC_SHIFT)) & PCC2_PCC_SEMA42_1_CGC_MASK)

#define PCC2_PCC_SEMA42_1_PR_MASK                (0x80000000U)
#define PCC2_PCC_SEMA42_1_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_SEMA42_1_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_SEMA42_1_PR_SHIFT)) & PCC2_PCC_SEMA42_1_PR_MASK)
/*! @} */

/*! @name PCC_DMA_MUX1 - PCC DMA_MUX1 Register */
/*! @{ */

#define PCC2_PCC_DMA_MUX1_INUSE_MASK             (0x20000000U)
#define PCC2_PCC_DMA_MUX1_INUSE_SHIFT            (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_DMA_MUX1_INUSE(x)               (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_DMA_MUX1_INUSE_SHIFT)) & PCC2_PCC_DMA_MUX1_INUSE_MASK)

#define PCC2_PCC_DMA_MUX1_CGC_MASK               (0x40000000U)
#define PCC2_PCC_DMA_MUX1_CGC_SHIFT              (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_DMA_MUX1_CGC(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_DMA_MUX1_CGC_SHIFT)) & PCC2_PCC_DMA_MUX1_CGC_MASK)

#define PCC2_PCC_DMA_MUX1_PR_MASK                (0x80000000U)
#define PCC2_PCC_DMA_MUX1_PR_SHIFT               (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_DMA_MUX1_PR(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_DMA_MUX1_PR_SHIFT)) & PCC2_PCC_DMA_MUX1_PR_MASK)
/*! @} */

/*! @name PCC_CAAM - PCC CAAM Register */
/*! @{ */

#define PCC2_PCC_CAAM_INUSE_MASK                 (0x20000000U)
#define PCC2_PCC_CAAM_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_CAAM_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_CAAM_INUSE_SHIFT)) & PCC2_PCC_CAAM_INUSE_MASK)

#define PCC2_PCC_CAAM_CGC_MASK                   (0x40000000U)
#define PCC2_PCC_CAAM_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_CAAM_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_CAAM_CGC_SHIFT)) & PCC2_PCC_CAAM_CGC_MASK)

#define PCC2_PCC_CAAM_PR_MASK                    (0x80000000U)
#define PCC2_PCC_CAAM_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_CAAM_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_CAAM_PR_SHIFT)) & PCC2_PCC_CAAM_PR_MASK)
/*! @} */

/*! @name PCC_TPM4 - PCC TPM4 Register */
/*! @{ */

#define PCC2_PCC_TPM4_PCS_MASK                   (0x7000000U)
#define PCC2_PCC_TPM4_PCS_SHIFT                  (24U)
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
#define PCC2_PCC_TPM4_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM4_PCS_SHIFT)) & PCC2_PCC_TPM4_PCS_MASK)

#define PCC2_PCC_TPM4_INUSE_MASK                 (0x20000000U)
#define PCC2_PCC_TPM4_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_TPM4_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM4_INUSE_SHIFT)) & PCC2_PCC_TPM4_INUSE_MASK)

#define PCC2_PCC_TPM4_CGC_MASK                   (0x40000000U)
#define PCC2_PCC_TPM4_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_TPM4_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM4_CGC_SHIFT)) & PCC2_PCC_TPM4_CGC_MASK)

#define PCC2_PCC_TPM4_PR_MASK                    (0x80000000U)
#define PCC2_PCC_TPM4_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_TPM4_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM4_PR_SHIFT)) & PCC2_PCC_TPM4_PR_MASK)
/*! @} */

/*! @name PCC_TPM5 - PCC TPM5 Register */
/*! @{ */

#define PCC2_PCC_TPM5_PCS_MASK                   (0x7000000U)
#define PCC2_PCC_TPM5_PCS_SHIFT                  (24U)
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
#define PCC2_PCC_TPM5_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM5_PCS_SHIFT)) & PCC2_PCC_TPM5_PCS_MASK)

#define PCC2_PCC_TPM5_INUSE_MASK                 (0x20000000U)
#define PCC2_PCC_TPM5_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_TPM5_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM5_INUSE_SHIFT)) & PCC2_PCC_TPM5_INUSE_MASK)

#define PCC2_PCC_TPM5_CGC_MASK                   (0x40000000U)
#define PCC2_PCC_TPM5_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_TPM5_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM5_CGC_SHIFT)) & PCC2_PCC_TPM5_CGC_MASK)

#define PCC2_PCC_TPM5_PR_MASK                    (0x80000000U)
#define PCC2_PCC_TPM5_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_TPM5_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_TPM5_PR_SHIFT)) & PCC2_PCC_TPM5_PR_MASK)
/*! @} */

/*! @name PCC_LPIT1 - PCC LPIT1 Register */
/*! @{ */

#define PCC2_PCC_LPIT1_PCS_MASK                  (0x7000000U)
#define PCC2_PCC_LPIT1_PCS_SHIFT                 (24U)
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
#define PCC2_PCC_LPIT1_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPIT1_PCS_SHIFT)) & PCC2_PCC_LPIT1_PCS_MASK)

#define PCC2_PCC_LPIT1_INUSE_MASK                (0x20000000U)
#define PCC2_PCC_LPIT1_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_LPIT1_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPIT1_INUSE_SHIFT)) & PCC2_PCC_LPIT1_INUSE_MASK)

#define PCC2_PCC_LPIT1_CGC_MASK                  (0x40000000U)
#define PCC2_PCC_LPIT1_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_LPIT1_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPIT1_CGC_SHIFT)) & PCC2_PCC_LPIT1_CGC_MASK)

#define PCC2_PCC_LPIT1_PR_MASK                   (0x80000000U)
#define PCC2_PCC_LPIT1_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_LPIT1_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPIT1_PR_SHIFT)) & PCC2_PCC_LPIT1_PR_MASK)
/*! @} */

/*! @name PCC_LPSPI2 - PCC LPSPI2 Register */
/*! @{ */

#define PCC2_PCC_LPSPI2_PCS_MASK                 (0x7000000U)
#define PCC2_PCC_LPSPI2_PCS_SHIFT                (24U)
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
#define PCC2_PCC_LPSPI2_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI2_PCS_SHIFT)) & PCC2_PCC_LPSPI2_PCS_MASK)

#define PCC2_PCC_LPSPI2_INUSE_MASK               (0x20000000U)
#define PCC2_PCC_LPSPI2_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_LPSPI2_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI2_INUSE_SHIFT)) & PCC2_PCC_LPSPI2_INUSE_MASK)

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

#define PCC2_PCC_LPSPI3_PCS_MASK                 (0x7000000U)
#define PCC2_PCC_LPSPI3_PCS_SHIFT                (24U)
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
#define PCC2_PCC_LPSPI3_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI3_PCS_SHIFT)) & PCC2_PCC_LPSPI3_PCS_MASK)

#define PCC2_PCC_LPSPI3_INUSE_MASK               (0x20000000U)
#define PCC2_PCC_LPSPI3_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_LPSPI3_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPSPI3_INUSE_SHIFT)) & PCC2_PCC_LPSPI3_INUSE_MASK)

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

/*! @name PCC_LPI2C4 - PCC LPI2C4 Register */
/*! @{ */

#define PCC2_PCC_LPI2C4_PCS_MASK                 (0x7000000U)
#define PCC2_PCC_LPI2C4_PCS_SHIFT                (24U)
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
#define PCC2_PCC_LPI2C4_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C4_PCS_SHIFT)) & PCC2_PCC_LPI2C4_PCS_MASK)

#define PCC2_PCC_LPI2C4_INUSE_MASK               (0x20000000U)
#define PCC2_PCC_LPI2C4_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_LPI2C4_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C4_INUSE_SHIFT)) & PCC2_PCC_LPI2C4_INUSE_MASK)

#define PCC2_PCC_LPI2C4_CGC_MASK                 (0x40000000U)
#define PCC2_PCC_LPI2C4_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_LPI2C4_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C4_CGC_SHIFT)) & PCC2_PCC_LPI2C4_CGC_MASK)

#define PCC2_PCC_LPI2C4_PR_MASK                  (0x80000000U)
#define PCC2_PCC_LPI2C4_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_LPI2C4_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C4_PR_SHIFT)) & PCC2_PCC_LPI2C4_PR_MASK)
/*! @} */

/*! @name PCC_LPI2C5 - PCC LPI2C5 Register */
/*! @{ */

#define PCC2_PCC_LPI2C5_PCS_MASK                 (0x7000000U)
#define PCC2_PCC_LPI2C5_PCS_SHIFT                (24U)
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
#define PCC2_PCC_LPI2C5_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C5_PCS_SHIFT)) & PCC2_PCC_LPI2C5_PCS_MASK)

#define PCC2_PCC_LPI2C5_INUSE_MASK               (0x20000000U)
#define PCC2_PCC_LPI2C5_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_LPI2C5_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C5_INUSE_SHIFT)) & PCC2_PCC_LPI2C5_INUSE_MASK)

#define PCC2_PCC_LPI2C5_CGC_MASK                 (0x40000000U)
#define PCC2_PCC_LPI2C5_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_LPI2C5_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C5_CGC_SHIFT)) & PCC2_PCC_LPI2C5_CGC_MASK)

#define PCC2_PCC_LPI2C5_PR_MASK                  (0x80000000U)
#define PCC2_PCC_LPI2C5_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_LPI2C5_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPI2C5_PR_SHIFT)) & PCC2_PCC_LPI2C5_PR_MASK)
/*! @} */

/*! @name PCC_LPUART4 - PCC LPUART4 Register */
/*! @{ */

#define PCC2_PCC_LPUART4_PCS_MASK                (0x7000000U)
#define PCC2_PCC_LPUART4_PCS_SHIFT               (24U)
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
#define PCC2_PCC_LPUART4_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART4_PCS_SHIFT)) & PCC2_PCC_LPUART4_PCS_MASK)

#define PCC2_PCC_LPUART4_INUSE_MASK              (0x20000000U)
#define PCC2_PCC_LPUART4_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_LPUART4_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART4_INUSE_SHIFT)) & PCC2_PCC_LPUART4_INUSE_MASK)

#define PCC2_PCC_LPUART4_CGC_MASK                (0x40000000U)
#define PCC2_PCC_LPUART4_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_LPUART4_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART4_CGC_SHIFT)) & PCC2_PCC_LPUART4_CGC_MASK)

#define PCC2_PCC_LPUART4_PR_MASK                 (0x80000000U)
#define PCC2_PCC_LPUART4_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_LPUART4_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART4_PR_SHIFT)) & PCC2_PCC_LPUART4_PR_MASK)
/*! @} */

/*! @name PCC_LPUART5 - PCC LPUART5 Register */
/*! @{ */

#define PCC2_PCC_LPUART5_PCS_MASK                (0x7000000U)
#define PCC2_PCC_LPUART5_PCS_SHIFT               (24U)
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
#define PCC2_PCC_LPUART5_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART5_PCS_SHIFT)) & PCC2_PCC_LPUART5_PCS_MASK)

#define PCC2_PCC_LPUART5_INUSE_MASK              (0x20000000U)
#define PCC2_PCC_LPUART5_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_LPUART5_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART5_INUSE_SHIFT)) & PCC2_PCC_LPUART5_INUSE_MASK)

#define PCC2_PCC_LPUART5_CGC_MASK                (0x40000000U)
#define PCC2_PCC_LPUART5_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_LPUART5_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART5_CGC_SHIFT)) & PCC2_PCC_LPUART5_CGC_MASK)

#define PCC2_PCC_LPUART5_PR_MASK                 (0x80000000U)
#define PCC2_PCC_LPUART5_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_LPUART5_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_LPUART5_PR_SHIFT)) & PCC2_PCC_LPUART5_PR_MASK)
/*! @} */

/*! @name PCC_FLEXIO1 - PCC FLEXIO1 Register */
/*! @{ */

#define PCC2_PCC_FLEXIO1_PCS_MASK                (0x7000000U)
#define PCC2_PCC_FLEXIO1_PCS_SHIFT               (24U)
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
#define PCC2_PCC_FLEXIO1_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_FLEXIO1_PCS_SHIFT)) & PCC2_PCC_FLEXIO1_PCS_MASK)

#define PCC2_PCC_FLEXIO1_INUSE_MASK              (0x20000000U)
#define PCC2_PCC_FLEXIO1_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_FLEXIO1_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_FLEXIO1_INUSE_SHIFT)) & PCC2_PCC_FLEXIO1_INUSE_MASK)

#define PCC2_PCC_FLEXIO1_CGC_MASK                (0x40000000U)
#define PCC2_PCC_FLEXIO1_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_FLEXIO1_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_FLEXIO1_CGC_SHIFT)) & PCC2_PCC_FLEXIO1_CGC_MASK)

#define PCC2_PCC_FLEXIO1_PR_MASK                 (0x80000000U)
#define PCC2_PCC_FLEXIO1_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_FLEXIO1_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_FLEXIO1_PR_SHIFT)) & PCC2_PCC_FLEXIO1_PR_MASK)
/*! @} */

/*! @name PCC_USB0 - PCC USB0 Register */
/*! @{ */

#define PCC2_PCC_USB0_PCD_MASK                   (0x7U)
#define PCC2_PCC_USB0_PCD_SHIFT                  (0U)
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
#define PCC2_PCC_USB0_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USB0_PCD_SHIFT)) & PCC2_PCC_USB0_PCD_MASK)

#define PCC2_PCC_USB0_FRAC_MASK                  (0x8U)
#define PCC2_PCC_USB0_FRAC_SHIFT                 (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_USB0_FRAC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USB0_FRAC_SHIFT)) & PCC2_PCC_USB0_FRAC_MASK)

#define PCC2_PCC_USB0_PCS_MASK                   (0x7000000U)
#define PCC2_PCC_USB0_PCS_SHIFT                  (24U)
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
#define PCC2_PCC_USB0_PCS(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USB0_PCS_SHIFT)) & PCC2_PCC_USB0_PCS_MASK)

#define PCC2_PCC_USB0_INUSE_MASK                 (0x20000000U)
#define PCC2_PCC_USB0_INUSE_SHIFT                (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_USB0_INUSE(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USB0_INUSE_SHIFT)) & PCC2_PCC_USB0_INUSE_MASK)

#define PCC2_PCC_USB0_CGC_MASK                   (0x40000000U)
#define PCC2_PCC_USB0_CGC_SHIFT                  (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_USB0_CGC(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USB0_CGC_SHIFT)) & PCC2_PCC_USB0_CGC_MASK)

#define PCC2_PCC_USB0_PR_MASK                    (0x80000000U)
#define PCC2_PCC_USB0_PR_SHIFT                   (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_USB0_PR(x)                      (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USB0_PR_SHIFT)) & PCC2_PCC_USB0_PR_MASK)
/*! @} */

/*! @name PCC_USB_PHY - PCC USB_PHY Register */
/*! @{ */

#define PCC2_PCC_USB_PHY_INUSE_MASK              (0x20000000U)
#define PCC2_PCC_USB_PHY_INUSE_SHIFT             (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_USB_PHY_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USB_PHY_INUSE_SHIFT)) & PCC2_PCC_USB_PHY_INUSE_MASK)

#define PCC2_PCC_USB_PHY_CGC_MASK                (0x40000000U)
#define PCC2_PCC_USB_PHY_CGC_SHIFT               (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_USB_PHY_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USB_PHY_CGC_SHIFT)) & PCC2_PCC_USB_PHY_CGC_MASK)

#define PCC2_PCC_USB_PHY_PR_MASK                 (0x80000000U)
#define PCC2_PCC_USB_PHY_PR_SHIFT                (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_USB_PHY_PR(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USB_PHY_PR_SHIFT)) & PCC2_PCC_USB_PHY_PR_MASK)
/*! @} */

/*! @name PCC_USDHC0 - PCC USDHC0 Register */
/*! @{ */

#define PCC2_PCC_USDHC0_PCD_MASK                 (0x7U)
#define PCC2_PCC_USDHC0_PCD_SHIFT                (0U)
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
#define PCC2_PCC_USDHC0_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC0_PCD_SHIFT)) & PCC2_PCC_USDHC0_PCD_MASK)

#define PCC2_PCC_USDHC0_FRAC_MASK                (0x8U)
#define PCC2_PCC_USDHC0_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_USDHC0_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC0_FRAC_SHIFT)) & PCC2_PCC_USDHC0_FRAC_MASK)

#define PCC2_PCC_USDHC0_PCS_MASK                 (0x7000000U)
#define PCC2_PCC_USDHC0_PCS_SHIFT                (24U)
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
#define PCC2_PCC_USDHC0_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC0_PCS_SHIFT)) & PCC2_PCC_USDHC0_PCS_MASK)

#define PCC2_PCC_USDHC0_INUSE_MASK               (0x20000000U)
#define PCC2_PCC_USDHC0_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_USDHC0_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC0_INUSE_SHIFT)) & PCC2_PCC_USDHC0_INUSE_MASK)

#define PCC2_PCC_USDHC0_CGC_MASK                 (0x40000000U)
#define PCC2_PCC_USDHC0_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_USDHC0_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC0_CGC_SHIFT)) & PCC2_PCC_USDHC0_CGC_MASK)

#define PCC2_PCC_USDHC0_PR_MASK                  (0x80000000U)
#define PCC2_PCC_USDHC0_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_USDHC0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC0_PR_SHIFT)) & PCC2_PCC_USDHC0_PR_MASK)
/*! @} */

/*! @name PCC_USDHC1 - PCC USDHC1 Register */
/*! @{ */

#define PCC2_PCC_USDHC1_PCD_MASK                 (0x7U)
#define PCC2_PCC_USDHC1_PCD_SHIFT                (0U)
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
#define PCC2_PCC_USDHC1_PCD(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC1_PCD_SHIFT)) & PCC2_PCC_USDHC1_PCD_MASK)

#define PCC2_PCC_USDHC1_FRAC_MASK                (0x8U)
#define PCC2_PCC_USDHC1_FRAC_SHIFT               (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_USDHC1_FRAC(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC1_FRAC_SHIFT)) & PCC2_PCC_USDHC1_FRAC_MASK)

#define PCC2_PCC_USDHC1_PCS_MASK                 (0x7000000U)
#define PCC2_PCC_USDHC1_PCS_SHIFT                (24U)
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
#define PCC2_PCC_USDHC1_PCS(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC1_PCS_SHIFT)) & PCC2_PCC_USDHC1_PCS_MASK)

#define PCC2_PCC_USDHC1_INUSE_MASK               (0x20000000U)
#define PCC2_PCC_USDHC1_INUSE_SHIFT              (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_USDHC1_INUSE(x)                 (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC1_INUSE_SHIFT)) & PCC2_PCC_USDHC1_INUSE_MASK)

#define PCC2_PCC_USDHC1_CGC_MASK                 (0x40000000U)
#define PCC2_PCC_USDHC1_CGC_SHIFT                (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_USDHC1_CGC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC1_CGC_SHIFT)) & PCC2_PCC_USDHC1_CGC_MASK)

#define PCC2_PCC_USDHC1_PR_MASK                  (0x80000000U)
#define PCC2_PCC_USDHC1_PR_SHIFT                 (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_USDHC1_PR(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_USDHC1_PR_SHIFT)) & PCC2_PCC_USDHC1_PR_MASK)
/*! @} */

/*! @name PCC_WDOG1 - PCC WDOG1 Register */
/*! @{ */

#define PCC2_PCC_WDOG1_PCD_MASK                  (0x7U)
#define PCC2_PCC_WDOG1_PCD_SHIFT                 (0U)
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
#define PCC2_PCC_WDOG1_PCD(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG1_PCD_SHIFT)) & PCC2_PCC_WDOG1_PCD_MASK)

#define PCC2_PCC_WDOG1_FRAC_MASK                 (0x8U)
#define PCC2_PCC_WDOG1_FRAC_SHIFT                (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC2_PCC_WDOG1_FRAC(x)                   (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG1_FRAC_SHIFT)) & PCC2_PCC_WDOG1_FRAC_MASK)

#define PCC2_PCC_WDOG1_PCS_MASK                  (0x7000000U)
#define PCC2_PCC_WDOG1_PCS_SHIFT                 (24U)
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
#define PCC2_PCC_WDOG1_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG1_PCS_SHIFT)) & PCC2_PCC_WDOG1_PCS_MASK)

#define PCC2_PCC_WDOG1_INUSE_MASK                (0x20000000U)
#define PCC2_PCC_WDOG1_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_WDOG1_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG1_INUSE_SHIFT)) & PCC2_PCC_WDOG1_INUSE_MASK)

#define PCC2_PCC_WDOG1_CGC_MASK                  (0x40000000U)
#define PCC2_PCC_WDOG1_CGC_SHIFT                 (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Clock enabled. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC2_PCC_WDOG1_CGC(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG1_CGC_SHIFT)) & PCC2_PCC_WDOG1_CGC_MASK)

#define PCC2_PCC_WDOG1_PR_MASK                   (0x80000000U)
#define PCC2_PCC_WDOG1_PR_SHIFT                  (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC2_PCC_WDOG1_PR(x)                     (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG1_PR_SHIFT)) & PCC2_PCC_WDOG1_PR_MASK)
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

#define PCC2_PCC_WDOG2_PCS_MASK                  (0x7000000U)
#define PCC2_PCC_WDOG2_PCS_SHIFT                 (24U)
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
#define PCC2_PCC_WDOG2_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG2_PCS_SHIFT)) & PCC2_PCC_WDOG2_PCS_MASK)

#define PCC2_PCC_WDOG2_INUSE_MASK                (0x20000000U)
#define PCC2_PCC_WDOG2_INUSE_SHIFT               (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC2_PCC_WDOG2_INUSE(x)                  (((uint32_t)(((uint32_t)(x)) << PCC2_PCC_WDOG2_INUSE_SHIFT)) & PCC2_PCC_WDOG2_INUSE_MASK)

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
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_PCC2_H_ */

