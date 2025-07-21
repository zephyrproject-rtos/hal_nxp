/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FGPIO
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2014-10-17)
**         Initial version.
**     - rev. 1.1 (2015-01-27)
**         Update according to reference manual rev. 1, RC.
**     - rev. 1.2 (2015-03-06)
**         Update according to reference manual rev. 1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FGPIO.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FGPIO
 *
 * CMSIS Peripheral Access Layer for FGPIO
 */

#if !defined(PERI_FGPIO_H_)
#define PERI_FGPIO_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKM34Z256VLL7) || defined(CPU_MKM34Z256VLQ7))
#include "MKM34Z7_COMMON.h"
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
   -- FGPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Peripheral_Access_Layer FGPIO Peripheral Access Layer
 * @{
 */

/** FGPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t PDOR;                              /**< Port Data Output Register, offset: 0x0 */
  __IO uint32_t PSOR;                              /**< Port Set Output Register, offset: 0x4 */
  __IO uint32_t PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
  __IO uint32_t PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
  __I  uint32_t PDIR;                              /**< Port Data Input Register, offset: 0x10 */
  __IO uint32_t PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
  __IO uint32_t GACR;                              /**< GPIO Attribute Checker Register, offset: 0x18 */
} FGPIO_Type;

/* ----------------------------------------------------------------------------
   -- FGPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Register_Masks FGPIO Register Masks
 * @{
 */

/*! @name PDOR - Port Data Output Register */
/*! @{ */

#define FGPIO_PDOR_PDO_MASK                      (0xFFFFFFFFU)
#define FGPIO_PDOR_PDO_SHIFT                     (0U)
/*! PDO - Port Data Output
 *  0b00000000000000000000000000000000..Logic level 0 is driven on pin, provided pin is configured for general-purpose output.
 *  0b00000000000000000000000000000001..Logic level 1 is driven on pin, provided pin is configured for general-purpose output.
 */
#define FGPIO_PDOR_PDO(x)                        (((uint32_t)(((uint32_t)(x)) << FGPIO_PDOR_PDO_SHIFT)) & FGPIO_PDOR_PDO_MASK)
/*! @} */

/*! @name PSOR - Port Set Output Register */
/*! @{ */

#define FGPIO_PSOR_PTSO_MASK                     (0xFFFFFFFFU)
#define FGPIO_PSOR_PTSO_SHIFT                    (0U)
/*! PTSO - Port Set Output
 *  0b00000000000000000000000000000000..Corresponding bit in PDORn does not change.
 *  0b00000000000000000000000000000001..Corresponding bit in PDORn is set to logic 1.
 */
#define FGPIO_PSOR_PTSO(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_PSOR_PTSO_SHIFT)) & FGPIO_PSOR_PTSO_MASK)
/*! @} */

/*! @name PCOR - Port Clear Output Register */
/*! @{ */

#define FGPIO_PCOR_PTCO_MASK                     (0xFFFFFFFFU)
#define FGPIO_PCOR_PTCO_SHIFT                    (0U)
/*! PTCO - Port Clear Output
 *  0b00000000000000000000000000000000..Corresponding bit in PDORn does not change.
 *  0b00000000000000000000000000000001..Corresponding bit in PDORn is cleared to logic 0.
 */
#define FGPIO_PCOR_PTCO(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_PCOR_PTCO_SHIFT)) & FGPIO_PCOR_PTCO_MASK)
/*! @} */

/*! @name PTOR - Port Toggle Output Register */
/*! @{ */

#define FGPIO_PTOR_PTTO_MASK                     (0xFFFFFFFFU)
#define FGPIO_PTOR_PTTO_SHIFT                    (0U)
/*! PTTO - Port Toggle Output
 *  0b00000000000000000000000000000000..Corresponding bit in PDORn does not change.
 *  0b00000000000000000000000000000001..Corresponding bit in PDORn is set to the inverse of its existing logic state.
 */
#define FGPIO_PTOR_PTTO(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_PTOR_PTTO_SHIFT)) & FGPIO_PTOR_PTTO_MASK)
/*! @} */

/*! @name PDIR - Port Data Input Register */
/*! @{ */

#define FGPIO_PDIR_PDI_MASK                      (0xFFFFFFFFU)
#define FGPIO_PDIR_PDI_SHIFT                     (0U)
/*! PDI - Port Data Input
 *  0b00000000000000000000000000000000..Pin logic level is logic 0, or is not configured for use by digital function.
 *  0b00000000000000000000000000000001..Pin logic level is logic 1.
 */
#define FGPIO_PDIR_PDI(x)                        (((uint32_t)(((uint32_t)(x)) << FGPIO_PDIR_PDI_SHIFT)) & FGPIO_PDIR_PDI_MASK)
/*! @} */

/*! @name PDDR - Port Data Direction Register */
/*! @{ */

#define FGPIO_PDDR_PDD_MASK                      (0xFFFFFFFFU)
#define FGPIO_PDDR_PDD_SHIFT                     (0U)
/*! PDD - Port Data Direction
 *  0b00000000000000000000000000000000..Pin is configured as general-purpose input, for the GPIO function.
 *  0b00000000000000000000000000000001..Pin is configured as general-purpose output, for the GPIO function.
 */
#define FGPIO_PDDR_PDD(x)                        (((uint32_t)(((uint32_t)(x)) << FGPIO_PDDR_PDD_SHIFT)) & FGPIO_PDDR_PDD_MASK)
/*! @} */

/*! @name GACR - GPIO Attribute Checker Register */
/*! @{ */

#define FGPIO_GACR_ACB0_MASK                     (0x7U)
#define FGPIO_GACR_ACB0_SHIFT                    (0U)
/*! ACB0 - Attribute Check Byte 0
 *  0b000..User nonsecure: Read + Write; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b001..User nonsecure: Read; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b010..User nonsecure: None; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b011..User nonsecure: Read; User Secure: Read; Privileged Secure: Read + Write
 *  0b100..User nonsecure: None; User Secure: Read; Privileged Secure: Read + Write
 *  0b101..User nonsecure: None; User Secure: None; Privileged Secure: Read + Write
 *  0b110..User nonsecure: None; User Secure: None; Privileged Secure: Read
 *  0b111..User nonsecure: None; User Secure: None; Privileged Secure: None
 */
#define FGPIO_GACR_ACB0(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_GACR_ACB0_SHIFT)) & FGPIO_GACR_ACB0_MASK)

#define FGPIO_GACR_ROB0_MASK                     (0x80U)
#define FGPIO_GACR_ROB0_SHIFT                    (7U)
/*! ROB0 - Read-Only Byte 0
 *  0b0..Writes to the GPIOn_GACR are allowed.
 *  0b1..Writes to the GPIOn_GACR are ignored.
 */
#define FGPIO_GACR_ROB0(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_GACR_ROB0_SHIFT)) & FGPIO_GACR_ROB0_MASK)

#define FGPIO_GACR_ACB1_MASK                     (0x700U)
#define FGPIO_GACR_ACB1_SHIFT                    (8U)
/*! ACB1 - Attribute Check Byte 1
 *  0b000..User nonsecure: Read + Write; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b001..User nonsecure: Read; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b010..User nonsecure: None; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b011..User nonsecure: Read; User Secure: Read; Privileged Secure: Read + Write
 *  0b100..User nonsecure: None; User Secure: Read; Privileged Secure: Read + Write
 *  0b101..User nonsecure: None; User Secure: None; Privileged Secure: Read + Write
 *  0b110..User nonsecure: None; User Secure: None; Privileged Secure: Read
 *  0b111..User nonsecure: None; User Secure: None; Privileged Secure: None
 */
#define FGPIO_GACR_ACB1(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_GACR_ACB1_SHIFT)) & FGPIO_GACR_ACB1_MASK)

#define FGPIO_GACR_ROB1_MASK                     (0x8000U)
#define FGPIO_GACR_ROB1_SHIFT                    (15U)
/*! ROB1 - Read-Only Byte 1
 *  0b0..Writes to the GPIOn_GACR are allowed.
 *  0b1..Writes to the GPIOn_GACR are ignored.
 */
#define FGPIO_GACR_ROB1(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_GACR_ROB1_SHIFT)) & FGPIO_GACR_ROB1_MASK)

#define FGPIO_GACR_ACB2_MASK                     (0x70000U)
#define FGPIO_GACR_ACB2_SHIFT                    (16U)
/*! ACB2 - Attribute Check Byte 2
 *  0b000..User nonsecure: Read + Write; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b001..User nonsecure: Read; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b010..User nonsecure: None; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b011..User nonsecure: Read; User Secure: Read; Privileged Secure: Read + Write
 *  0b100..User nonsecure: None; User Secure: Read; Privileged Secure: Read + Write
 *  0b101..User nonsecure: None; User Secure: None; Privileged Secure: Read + Write
 *  0b110..User nonsecure: None; User Secure: None; Privileged Secure: Read
 *  0b111..User nonsecure: None; User Secure: None; Privileged Secure: None
 */
#define FGPIO_GACR_ACB2(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_GACR_ACB2_SHIFT)) & FGPIO_GACR_ACB2_MASK)

#define FGPIO_GACR_ROB2_MASK                     (0x800000U)
#define FGPIO_GACR_ROB2_SHIFT                    (23U)
/*! ROB2 - Read-Only Byte 2
 *  0b0..Writes to the GPIOn_GACR are allowed.
 *  0b1..Writes to the GPIOn_GACR are ignored.
 */
#define FGPIO_GACR_ROB2(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_GACR_ROB2_SHIFT)) & FGPIO_GACR_ROB2_MASK)

#define FGPIO_GACR_ACB3_MASK                     (0x7000000U)
#define FGPIO_GACR_ACB3_SHIFT                    (24U)
/*! ACB3 - Attribute Check Byte 3
 *  0b000..User nonsecure: Read + Write; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b001..User nonsecure: Read; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b010..User nonsecure: None; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b011..User nonsecure: Read; User Secure: Read; Privileged Secure: Read + Write
 *  0b100..User nonsecure: None; User Secure: Read; Privileged Secure: Read + Write
 *  0b101..User nonsecure: None; User Secure: None; Privileged Secure: Read + Write
 *  0b110..User nonsecure: None; User Secure: None; Privileged Secure: Read
 *  0b111..User nonsecure: None; User Secure: None; Privileged Secure: None
 */
#define FGPIO_GACR_ACB3(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_GACR_ACB3_SHIFT)) & FGPIO_GACR_ACB3_MASK)

#define FGPIO_GACR_ROB3_MASK                     (0x80000000U)
#define FGPIO_GACR_ROB3_SHIFT                    (31U)
/*! ROB3 - Read-Only Byte 3
 *  0b0..Writes to the GPIOn_GACR are allowed.
 *  0b1..Writes to the GPIOn_GACR are ignored.
 */
#define FGPIO_GACR_ROB3(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_GACR_ROB3_SHIFT)) & FGPIO_GACR_ROB3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FGPIO_Register_Masks */


/*!
 * @}
 */ /* end of group FGPIO_Peripheral_Access_Layer */


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


#endif  /* PERI_FGPIO_H_ */

