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
**         CMSIS Peripheral Access Layer for MCM
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
 * @file PERI_MCM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCM
 *
 * CMSIS Peripheral Access Layer for MCM
 */

#if !defined(PERI_MCM_H_)
#define PERI_MCM_H_                              /**< Symbol preventing repeated inclusion */

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
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Size of Registers Arrays */
#define MCM_MATCR_COUNT                           1u

/** MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __I  uint16_t PLASC;                             /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  __I  uint16_t PLAMC;                             /**< Crossbar Switch (AXBS) Master Configuration, offset: 0xA */
  __IO uint32_t PLACR;                             /**< Platform Control Register, offset: 0xC */
       uint8_t RESERVED_1[32];
  __IO uint32_t PID;                               /**< Process ID register, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t CPO;                               /**< Compute Operation Control Register, offset: 0x40 */
       uint8_t RESERVED_3[60];
  __IO uint32_t MATCR[MCM_MATCR_COUNT];            /**< Master Attribute Configuration Register, array offset: 0x80, array step: 0x4 */
} MCM_Type;

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/*! @name PLASC - Crossbar Switch (AXBS) Slave Configuration */
/*! @{ */

#define MCM_PLASC_ASC_MASK                       (0xFFU)
#define MCM_PLASC_ASC_SHIFT                      (0U)
/*! ASC - Each bit in the ASC field indicates whether there is a corresponding connection to the
 *    crossbar switch's slave input port.
 *  0b00000000..A bus slave connection to AXBS input port n is absent.
 *  0b00000001..A bus slave connection to AXBS input port n is present.
 */
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC_SHIFT)) & MCM_PLASC_ASC_MASK)
/*! @} */

/*! @name PLAMC - Crossbar Switch (AXBS) Master Configuration */
/*! @{ */

#define MCM_PLAMC_AMC_MASK                       (0xFFU)
#define MCM_PLAMC_AMC_SHIFT                      (0U)
/*! AMC - Each bit in the AMC field indicates whether there is a corresponding connection to the AXBS master input port.
 *  0b00000000..A bus master connection to AXBS input port n is absent
 *  0b00000001..A bus master connection to AXBS input port n is present
 */
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC_SHIFT)) & MCM_PLAMC_AMC_MASK)
/*! @} */

/*! @name PLACR - Platform Control Register */
/*! @{ */

#define MCM_PLACR_ARB_MASK                       (0x200U)
#define MCM_PLACR_ARB_SHIFT                      (9U)
/*! ARB - Arbitration select
 *  0b0..Fixed-priority arbitration for the crossbar masters
 *  0b1..Round-robin arbitration for the crossbar masters
 */
#define MCM_PLACR_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_PLACR_ARB_SHIFT)) & MCM_PLACR_ARB_MASK)

#define MCM_PLACR_CFCC_MASK                      (0x400U)
#define MCM_PLACR_CFCC_SHIFT                     (10U)
/*! CFCC - Clear Flash Controller Cache */
#define MCM_PLACR_CFCC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_PLACR_CFCC_SHIFT)) & MCM_PLACR_CFCC_MASK)

#define MCM_PLACR_DFCDA_MASK                     (0x800U)
#define MCM_PLACR_DFCDA_SHIFT                    (11U)
/*! DFCDA - Disable Flash Controller Data Caching
 *  0b0..Enable flash controller data caching
 *  0b1..Disable flash controller data caching.
 */
#define MCM_PLACR_DFCDA(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_PLACR_DFCDA_SHIFT)) & MCM_PLACR_DFCDA_MASK)

#define MCM_PLACR_DFCIC_MASK                     (0x1000U)
#define MCM_PLACR_DFCIC_SHIFT                    (12U)
/*! DFCIC - Disable Flash Controller Instruction Caching
 *  0b0..Enable flash controller instruction caching.
 *  0b1..Disable flash controller instruction caching.
 */
#define MCM_PLACR_DFCIC(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_PLACR_DFCIC_SHIFT)) & MCM_PLACR_DFCIC_MASK)

#define MCM_PLACR_DFCC_MASK                      (0x2000U)
#define MCM_PLACR_DFCC_SHIFT                     (13U)
/*! DFCC - Disable Flash Controller Cache
 *  0b0..Enable flash controller cache.
 *  0b1..Disable flash controller cache.
 */
#define MCM_PLACR_DFCC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_PLACR_DFCC_SHIFT)) & MCM_PLACR_DFCC_MASK)

#define MCM_PLACR_EFDS_MASK                      (0x4000U)
#define MCM_PLACR_EFDS_SHIFT                     (14U)
/*! EFDS - Enable Flash Data Speculation
 *  0b0..Disable flash data speculation.
 *  0b1..Enable flash data speculation.
 */
#define MCM_PLACR_EFDS(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_PLACR_EFDS_SHIFT)) & MCM_PLACR_EFDS_MASK)

#define MCM_PLACR_DFCS_MASK                      (0x8000U)
#define MCM_PLACR_DFCS_SHIFT                     (15U)
/*! DFCS - Disable Flash Controller Speculation
 *  0b0..Enable flash controller speculation.
 *  0b1..Disable flash controller speculation.
 */
#define MCM_PLACR_DFCS(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_PLACR_DFCS_SHIFT)) & MCM_PLACR_DFCS_MASK)

#define MCM_PLACR_ESFC_MASK                      (0x10000U)
#define MCM_PLACR_ESFC_SHIFT                     (16U)
/*! ESFC - Enable Stalling Flash Controller
 *  0b0..Disable stalling flash controller when flash is busy.
 *  0b1..Enable stalling flash controller when flash is busy.
 */
#define MCM_PLACR_ESFC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_PLACR_ESFC_SHIFT)) & MCM_PLACR_ESFC_MASK)
/*! @} */

/*! @name PID - Process ID register */
/*! @{ */

#define MCM_PID_PID_MASK                         (0xFFU)
#define MCM_PID_PID_SHIFT                        (0U)
/*! PID - M0_PID For MPU
 *  0b00000000..Reserved for privileged secure tasks
 *  0b00000001-0b01111111..Allocated for user secure tasks
 *  0b10000000-0b11111111..Allocated for user nonsecure tasks
 */
#define MCM_PID_PID(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_PID_PID_SHIFT)) & MCM_PID_PID_MASK)
/*! @} */

/*! @name CPO - Compute Operation Control Register */
/*! @{ */

#define MCM_CPO_CPOREQ_MASK                      (0x1U)
#define MCM_CPO_CPOREQ_SHIFT                     (0U)
/*! CPOREQ - Compute Operation Request
 *  0b0..Request is cleared.
 *  0b1..Request Compute Operation.
 */
#define MCM_CPO_CPOREQ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOREQ_SHIFT)) & MCM_CPO_CPOREQ_MASK)

#define MCM_CPO_CPOACK_MASK                      (0x2U)
#define MCM_CPO_CPOACK_SHIFT                     (1U)
/*! CPOACK - Compute Operation Acknowledge
 *  0b0..Compute operation entry has not completed or compute operation exit has completed.
 *  0b1..Compute operation entry has completed or compute operation exit has not completed.
 */
#define MCM_CPO_CPOACK(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOACK_SHIFT)) & MCM_CPO_CPOACK_MASK)

#define MCM_CPO_CPOWOI_MASK                      (0x4U)
#define MCM_CPO_CPOWOI_SHIFT                     (2U)
/*! CPOWOI - Compute Operation Wake-up on Interrupt
 *  0b0..No effect.
 *  0b1..When set, the CPOREQ is cleared on any interrupt or exception vector fetch.
 */
#define MCM_CPO_CPOWOI(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOWOI_SHIFT)) & MCM_CPO_CPOWOI_MASK)
/*! @} */

/*! @name MATCR - Master Attribute Configuration Register */
/*! @{ */

#define MCM_MATCR_ATC0_MASK                      (0x7U)
#define MCM_MATCR_ATC0_SHIFT                     (0U)
/*! ATC0 - Attribute Configuration Master n
 *  0b00x..Master attributes are statically forced to {privileged, secure}.
 *  0b010..Master attributes are statically forced to {user, secure}.
 *  0b011..Master attributes are statically forced to {user, nonsecure}.
 *  0b100..Enable master attribute {privileged or user} and statically force {secure}.
 *  0b101..Enable master attribute {privileged or user} and statically force {nonsecure}.
 *  0b11x..Enable master attribute {privileged or user, secure or nonsecure}
 */
#define MCM_MATCR_ATC0(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_MATCR_ATC0_SHIFT)) & MCM_MATCR_ATC0_MASK)

#define MCM_MATCR_RO0_MASK                       (0x80U)
#define MCM_MATCR_RO0_SHIFT                      (7U)
/*! RO0 - Read-Only Master n
 *  0b0..Writes to the ATCn are allowed.
 *  0b1..Writes to the ATCn are ignored.
 */
#define MCM_MATCR_RO0(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_MATCR_RO0_SHIFT)) & MCM_MATCR_RO0_MASK)

#define MCM_MATCR_ATC2_MASK                      (0x70000U)
#define MCM_MATCR_ATC2_SHIFT                     (16U)
/*! ATC2 - Attribute Configuration Master n
 *  0b00x..Master attributes are statically forced to {privileged, secure}.
 *  0b010..Master attributes are statically forced to {user, secure}.
 *  0b011..Master attributes are statically forced to {user, nonsecure}.
 *  0b100..Enable master attribute {privileged or user} and statically force {secure}.
 *  0b101..Enable master attribute {privileged or user} and statically force {nonsecure}.
 *  0b11x..Enable master attribute {privileged or user, secure or nonsecure}
 */
#define MCM_MATCR_ATC2(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_MATCR_ATC2_SHIFT)) & MCM_MATCR_ATC2_MASK)

#define MCM_MATCR_RO2_MASK                       (0x800000U)
#define MCM_MATCR_RO2_SHIFT                      (23U)
/*! RO2 - Read-Only Master n
 *  0b0..Writes to the ATCn are allowed.
 *  0b1..Writes to the ATCn are ignored.
 */
#define MCM_MATCR_RO2(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_MATCR_RO2_SHIFT)) & MCM_MATCR_RO2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


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


#endif  /* PERI_MCM_H_ */

