/*
** ###################################################################
**     Processors:          MKM35Z256VLL7
**                          MKM35Z256VLL7R
**                          MKM35Z256VLQ7
**                          MKM35Z256VLQ7R
**                          MKM35Z512VLL7
**                          MKM35Z512VLL7R
**                          MKM35Z512VLQ7
**                          MKM35Z512VLQ7R
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MMAU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-08-01)
**         Initial version.
**     - rev. 2.0 (2019-12-20)
**         Based on RM Rev.1.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MMAU.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MMAU
 *
 * CMSIS Peripheral Access Layer for MMAU
 */

#if !defined(PERI_MMAU_H_)
#define PERI_MMAU_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKM35Z256VLL7) || defined(CPU_MKM35Z256VLL7R) || defined(CPU_MKM35Z256VLQ7) || defined(CPU_MKM35Z256VLQ7R) || defined(CPU_MKM35Z512VLL7) || defined(CPU_MKM35Z512VLL7R) || defined(CPU_MKM35Z512VLQ7) || defined(CPU_MKM35Z512VLQ7R))
#include "MKM35Z7_COMMON.h"
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
   -- MMAU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMAU_Peripheral_Access_Layer MMAU Peripheral Access Layer
 * @{
 */

/** MMAU - Register Layout Typedef */
typedef struct {
  __IO uint32_t X0;                                /**< Operand Register X0, offset: 0x0 */
  __IO uint32_t X1;                                /**< Operand Register X1, offset: 0x4 */
  __IO uint32_t X2;                                /**< Operand Register X2, offset: 0x8 */
  __IO uint32_t X3;                                /**< Operand Register X3, offset: 0xC */
  __IO uint32_t A0;                                /**< Accumulator Register A0, offset: 0x10 */
  __IO uint32_t A1;                                /**< Accumulator Register A1, offset: 0x14 */
  __IO uint32_t CSR;                               /**< Control/Status Register, offset: 0x18 */
  __O  uint32_t CSR_IF_CLR;                        /**< CSR Interrupt Flags Clearance Register, offset: 0x1C */
} MMAU_Type;

/* ----------------------------------------------------------------------------
   -- MMAU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMAU_Register_Masks MMAU Register Masks
 * @{
 */

/*! @name X0 - Operand Register X0 */
/*! @{ */

#define MMAU_X0_X0_MASK                          (0xFFFFFFFFU)
#define MMAU_X0_X0_SHIFT                         (0U)
/*! X0 - Operand Register X0 */
#define MMAU_X0_X0(x)                            (((uint32_t)(((uint32_t)(x)) << MMAU_X0_X0_SHIFT)) & MMAU_X0_X0_MASK)
/*! @} */

/*! @name X1 - Operand Register X1 */
/*! @{ */

#define MMAU_X1_X1_MASK                          (0xFFFFFFFFU)
#define MMAU_X1_X1_SHIFT                         (0U)
/*! X1 - Operand Register X1 */
#define MMAU_X1_X1(x)                            (((uint32_t)(((uint32_t)(x)) << MMAU_X1_X1_SHIFT)) & MMAU_X1_X1_MASK)
/*! @} */

/*! @name X2 - Operand Register X2 */
/*! @{ */

#define MMAU_X2_X2_MASK                          (0xFFFFFFFFU)
#define MMAU_X2_X2_SHIFT                         (0U)
/*! X2 - Operand Register X2 */
#define MMAU_X2_X2(x)                            (((uint32_t)(((uint32_t)(x)) << MMAU_X2_X2_SHIFT)) & MMAU_X2_X2_MASK)
/*! @} */

/*! @name X3 - Operand Register X3 */
/*! @{ */

#define MMAU_X3_X3_MASK                          (0xFFFFFFFFU)
#define MMAU_X3_X3_SHIFT                         (0U)
/*! X3 - Operand Register X3 */
#define MMAU_X3_X3(x)                            (((uint32_t)(((uint32_t)(x)) << MMAU_X3_X3_SHIFT)) & MMAU_X3_X3_MASK)
/*! @} */

/*! @name A0 - Accumulator Register A0 */
/*! @{ */

#define MMAU_A0_A0_MASK                          (0xFFFFFFFFU)
#define MMAU_A0_A0_SHIFT                         (0U)
/*! A0 - Accumulator Register A0 */
#define MMAU_A0_A0(x)                            (((uint32_t)(((uint32_t)(x)) << MMAU_A0_A0_SHIFT)) & MMAU_A0_A0_MASK)
/*! @} */

/*! @name A1 - Accumulator Register A1 */
/*! @{ */

#define MMAU_A1_A1_MASK                          (0xFFFFFFFFU)
#define MMAU_A1_A1_SHIFT                         (0U)
/*! A1 - Accumulator Register A1 */
#define MMAU_A1_A1(x)                            (((uint32_t)(((uint32_t)(x)) << MMAU_A1_A1_SHIFT)) & MMAU_A1_A1_MASK)
/*! @} */

/*! @name CSR - Control/Status Register */
/*! @{ */

#define MMAU_CSR_Q_MASK                          (0x1U)
#define MMAU_CSR_Q_SHIFT                         (0U)
/*! Q - Q flag: Accumulation Overflow
 *  0b0..No accumulation operation or accumulation operation does not overflow
 *  0b1..Accumulation overflows during a MAC instruction
 */
#define MMAU_CSR_Q(x)                            (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_Q_SHIFT)) & MMAU_CSR_Q_MASK)

#define MMAU_CSR_V_MASK                          (0x2U)
#define MMAU_CSR_V_SHIFT                         (1U)
/*! V - V flag: Multiply or Divide overflow
 *  0b0..Calculation is not include divider or multiply, or the product/quotient does not overflow
 *  0b1..Product in multiply or multiply with accumulation, or quotient of a divide overflows
 */
#define MMAU_CSR_V(x)                            (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_V_SHIFT)) & MMAU_CSR_V_MASK)

#define MMAU_CSR_DZ_MASK                         (0x4U)
#define MMAU_CSR_DZ_SHIFT                        (2U)
/*! DZ - DZ flag: Divide by Zero
 *  0b0..For divide, the divisor is not zero, or the calculation is not divide
 *  0b1..For divide, the divisor is zero, which is a divide-by-zero error
 */
#define MMAU_CSR_DZ(x)                           (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_DZ_SHIFT)) & MMAU_CSR_DZ_MASK)

#define MMAU_CSR_N_MASK                          (0x8U)
#define MMAU_CSR_N_SHIFT                         (3U)
/*! N - N flag: Signed calculation result is negative
 *  0b0..Calculation raw result is zero or positive, or unsigned number
 *  0b1..Calculation raw result is negative
 */
#define MMAU_CSR_N(x)                            (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_N_SHIFT)) & MMAU_CSR_N_MASK)

#define MMAU_CSR_QIF_MASK                        (0x10U)
#define MMAU_CSR_QIF_SHIFT                       (4U)
/*! QIF - Q Interrupt Flag: Accumulation Overflow Interrupt Status
 *  0b0..No accumulation operation or accumulation operation does not overflow
 *  0b1..Accumulation overflows during a MAC instruction
 */
#define MMAU_CSR_QIF(x)                          (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_QIF_SHIFT)) & MMAU_CSR_QIF_MASK)

#define MMAU_CSR_VIF_MASK                        (0x20U)
#define MMAU_CSR_VIF_SHIFT                       (5U)
/*! VIF - V Interrupt Flag: Multiply or Divide overflow
 *  0b0..Calculation is not include divider or multiply, or the product/quotient does not overflow
 *  0b1..Product in multiply or multiply with accumulation, or quotient of a divide overflows
 */
#define MMAU_CSR_VIF(x)                          (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_VIF_SHIFT)) & MMAU_CSR_VIF_MASK)

#define MMAU_CSR_DZIF_MASK                       (0x40U)
#define MMAU_CSR_DZIF_SHIFT                      (6U)
/*! DZIF - DZ Interrupt Flag: Divide by Zero
 *  0b0..For divide, the divisor is not zero, or the calculation is not divide
 *  0b1..For divide, the divisor is zero, which is a divide-by-zero error
 */
#define MMAU_CSR_DZIF(x)                         (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_DZIF_SHIFT)) & MMAU_CSR_DZIF_MASK)

#define MMAU_CSR_QIE_MASK                        (0x1000U)
#define MMAU_CSR_QIE_SHIFT                       (12U)
/*! QIE - Accumulation Overflow (Q flag) Interrupt Enable
 *  0b0..Q flag (CSR[QIF]) set will not generate interrupt.
 *  0b1..Q flag (CSR[QIF]) set will generate interrupt to inform an accumulation overflow
 */
#define MMAU_CSR_QIE(x)                          (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_QIE_SHIFT)) & MMAU_CSR_QIE_MASK)

#define MMAU_CSR_VIE_MASK                        (0x2000U)
#define MMAU_CSR_VIE_SHIFT                       (13U)
/*! VIE - Divide/Multiply Overflow (V flag) Interrupt Enable
 *  0b0..V flag (CSR[VIF]) set will not generate interrupt.
 *  0b1..V flag (CSR[VIF]) set will generate interrupt to inform a divide or multiply overflow
 */
#define MMAU_CSR_VIE(x)                          (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_VIE_SHIFT)) & MMAU_CSR_VIE_MASK)

#define MMAU_CSR_DZIE_MASK                       (0x4000U)
#define MMAU_CSR_DZIE_SHIFT                      (14U)
/*! DZIE - Divide-by-Zero Interrupt Enable
 *  0b0..MMAU will not generate interrupt even CSR[DZIF]=1
 *  0b1..If CSR[DZIF] = 1, MMAU will generate an interrupt to signal a divide-by-zero.
 */
#define MMAU_CSR_DZIE(x)                         (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_DZIE_SHIFT)) & MMAU_CSR_DZIE_MASK)

#define MMAU_CSR_DRE_MASK                        (0x10000U)
#define MMAU_CSR_DRE_SHIFT                       (16U)
/*! DRE - DMA Request Enable
 *  0b0..MMAU will not generate DMA request when in IDLE (not busy) state
 *  0b1..MMAU will generate DMA request when in IDLE (not busy) state
 */
#define MMAU_CSR_DRE(x)                          (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_DRE_SHIFT)) & MMAU_CSR_DRE_MASK)

#define MMAU_CSR_SO_MASK                         (0x20000U)
#define MMAU_CSR_SO_SHIFT                        (17U)
/*! SO - Supervisor-Only
 *  0b0..MMAU registers can be access in both User Mode or Supervisor Mode
 *  0b1..MMAU registers can only be access in Supervisor Mode
 */
#define MMAU_CSR_SO(x)                           (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_SO_SHIFT)) & MMAU_CSR_SO_MASK)

#define MMAU_CSR_HDR_MASK                        (0xF00000U)
#define MMAU_CSR_HDR_SHIFT                       (20U)
/*! HDR - Hardware Revision Level
 *  0b0000..Current Hardware Revision Level is 0000
 */
#define MMAU_CSR_HDR(x)                          (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_HDR_SHIFT)) & MMAU_CSR_HDR_MASK)

#define MMAU_CSR_BUSY_MASK                       (0x80000000U)
#define MMAU_CSR_BUSY_SHIFT                      (31U)
/*! BUSY - BUSY
 *  0b0..MMAU is idle
 *  0b1..MMAU is busy performing a divide or square root calculation
 */
#define MMAU_CSR_BUSY(x)                         (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_BUSY_SHIFT)) & MMAU_CSR_BUSY_MASK)
/*! @} */

/*! @name CSR_IF_CLR - CSR Interrupt Flags Clearance Register */
/*! @{ */

#define MMAU_CSR_IF_CLR_Q_MASK                   (0x1U)
#define MMAU_CSR_IF_CLR_Q_SHIFT                  (0U)
/*! Q - Q flag: Accumulation Overflow
 *  0b0..Write "0" will clear CSR[Q]
 *  0b1..Write "1" will set CSR[Q]
 */
#define MMAU_CSR_IF_CLR_Q(x)                     (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_IF_CLR_Q_SHIFT)) & MMAU_CSR_IF_CLR_Q_MASK)

#define MMAU_CSR_IF_CLR_V_MASK                   (0x2U)
#define MMAU_CSR_IF_CLR_V_SHIFT                  (1U)
/*! V - V flag: Multiply or Divide overflow
 *  0b0..Write "0" will clear CSR[V]
 *  0b1..Write "1" will set CSR[V]
 */
#define MMAU_CSR_IF_CLR_V(x)                     (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_IF_CLR_V_SHIFT)) & MMAU_CSR_IF_CLR_V_MASK)

#define MMAU_CSR_IF_CLR_DZ_MASK                  (0x4U)
#define MMAU_CSR_IF_CLR_DZ_SHIFT                 (2U)
/*! DZ - DZ flag: Divide by Zero
 *  0b0..Write "0" will clear CSR[DZ]
 *  0b1..Write "1" will set CSR[DZ]
 */
#define MMAU_CSR_IF_CLR_DZ(x)                    (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_IF_CLR_DZ_SHIFT)) & MMAU_CSR_IF_CLR_DZ_MASK)

#define MMAU_CSR_IF_CLR_N_MASK                   (0x8U)
#define MMAU_CSR_IF_CLR_N_SHIFT                  (3U)
/*! N - N flag: Signed calculation result is negative
 *  0b0..Write "0" to clear CSR[N]
 *  0b1..Write "1" to set CSR[N]
 */
#define MMAU_CSR_IF_CLR_N(x)                     (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_IF_CLR_N_SHIFT)) & MMAU_CSR_IF_CLR_N_MASK)

#define MMAU_CSR_IF_CLR_QIF_MASK                 (0x10U)
#define MMAU_CSR_IF_CLR_QIF_SHIFT                (4U)
/*! QIF - Q Interrupt Flag: Accumulation Overflow Interrupt Status
 *  0b0..Write "0" is ignored
 *  0b1..Write "1" to clear CSR[QIF]
 */
#define MMAU_CSR_IF_CLR_QIF(x)                   (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_IF_CLR_QIF_SHIFT)) & MMAU_CSR_IF_CLR_QIF_MASK)

#define MMAU_CSR_IF_CLR_VIF_MASK                 (0x20U)
#define MMAU_CSR_IF_CLR_VIF_SHIFT                (5U)
/*! VIF - V Interrupt Flag: Multiply or Divide overflow
 *  0b0..Write "0" is ignored
 *  0b1..Write "1" to clear CSR[VIF]
 */
#define MMAU_CSR_IF_CLR_VIF(x)                   (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_IF_CLR_VIF_SHIFT)) & MMAU_CSR_IF_CLR_VIF_MASK)

#define MMAU_CSR_IF_CLR_DZIF_MASK                (0x40U)
#define MMAU_CSR_IF_CLR_DZIF_SHIFT               (6U)
/*! DZIF - DZ Interrupt Flag: Divide by Zero
 *  0b0..Write "0" is ignored
 *  0b1..Write "1" to clear CSR[DZIF]
 */
#define MMAU_CSR_IF_CLR_DZIF(x)                  (((uint32_t)(((uint32_t)(x)) << MMAU_CSR_IF_CLR_DZIF_SHIFT)) & MMAU_CSR_IF_CLR_DZIF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MMAU_Register_Masks */


/*!
 * @}
 */ /* end of group MMAU_Peripheral_Access_Layer */


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


#endif  /* PERI_MMAU_H_ */

