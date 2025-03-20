/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
**
**     Version:             rev. 1.2, 2015-03-06
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GPIO
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
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
**
** ###################################################################
*/

/*!
 * @file GPIO.h
 * @version 1.2
 * @date 2015-03-06
 * @brief CMSIS Peripheral Access Layer for GPIO
 *
 * CMSIS Peripheral Access Layer for GPIO
 */

#if !defined(GPIO_H_)
#define GPIO_H_                                  /**< Symbol preventing repeated inclusion */

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
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint8_t PDOR;                               /**< Port Data Output Register, offset: 0x0 */
       uint8_t RESERVED_0[3];
  __O  uint8_t PSOR;                               /**< Port Set Output Register, offset: 0x4 */
       uint8_t RESERVED_1[3];
  __O  uint8_t PCOR;                               /**< Port Clear Output Register, offset: 0x8 */
       uint8_t RESERVED_2[3];
  __O  uint8_t PTOR;                               /**< Port Toggle Output Register, offset: 0xC */
       uint8_t RESERVED_3[3];
  __I  uint8_t PDIR;                               /**< Port Data Input Register, offset: 0x10 */
       uint8_t RESERVED_4[3];
  __IO uint8_t PDDR;                               /**< Port Data Direction Register, offset: 0x14 */
       uint8_t RESERVED_5[7];
  __IO uint8_t GACR;                               /**< GPIO Attribute Checker Register, offset: 0x1C */
} GPIO_Type;

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/*! @name PDOR - Port Data Output Register */
/*! @{ */

#define GPIO_PDOR_PDO_MASK                       (0xFFU)
#define GPIO_PDOR_PDO_SHIFT                      (0U)
/*! PDO - Port Data Output
 *  0b00000000..Logic level 0 is driven on pin, provided pin is configured for general-purpose output.
 *  0b00000001..Logic level 1 is driven on pin, provided pin is configured for general-purpose output.
 */
#define GPIO_PDOR_PDO(x)                         (((uint8_t)(((uint8_t)(x)) << GPIO_PDOR_PDO_SHIFT)) & GPIO_PDOR_PDO_MASK)
/*! @} */

/*! @name PSOR - Port Set Output Register */
/*! @{ */

#define GPIO_PSOR_PTSO_MASK                      (0xFFU)
#define GPIO_PSOR_PTSO_SHIFT                     (0U)
/*! PTSO - Port Set Output
 *  0b00000000..Corresponding bit in PDORn does not change.
 *  0b00000001..Corresponding bit in PDORn is set to logic 1.
 */
#define GPIO_PSOR_PTSO(x)                        (((uint8_t)(((uint8_t)(x)) << GPIO_PSOR_PTSO_SHIFT)) & GPIO_PSOR_PTSO_MASK)
/*! @} */

/*! @name PCOR - Port Clear Output Register */
/*! @{ */

#define GPIO_PCOR_PTCO_MASK                      (0xFFU)
#define GPIO_PCOR_PTCO_SHIFT                     (0U)
/*! PTCO - Port Clear Output
 *  0b00000000..Corresponding bit in PDORn does not change.
 *  0b00000001..Corresponding bit in PDORn is cleared to logic 0.
 */
#define GPIO_PCOR_PTCO(x)                        (((uint8_t)(((uint8_t)(x)) << GPIO_PCOR_PTCO_SHIFT)) & GPIO_PCOR_PTCO_MASK)
/*! @} */

/*! @name PTOR - Port Toggle Output Register */
/*! @{ */

#define GPIO_PTOR_PTTO_MASK                      (0xFFU)
#define GPIO_PTOR_PTTO_SHIFT                     (0U)
/*! PTTO - Port Toggle Output
 *  0b00000000..Corresponding bit in PDORn does not change.
 *  0b00000001..Corresponding bit in PDORn is set to the inverse of its existing logic state.
 */
#define GPIO_PTOR_PTTO(x)                        (((uint8_t)(((uint8_t)(x)) << GPIO_PTOR_PTTO_SHIFT)) & GPIO_PTOR_PTTO_MASK)
/*! @} */

/*! @name PDIR - Port Data Input Register */
/*! @{ */

#define GPIO_PDIR_PDI_MASK                       (0xFFU)
#define GPIO_PDIR_PDI_SHIFT                      (0U)
/*! PDI - Port Data Input
 *  0b00000000..Pin logic level is logic 0, or is not configured for use by digital function.
 *  0b00000001..Pin logic level is logic 1.
 */
#define GPIO_PDIR_PDI(x)                         (((uint8_t)(((uint8_t)(x)) << GPIO_PDIR_PDI_SHIFT)) & GPIO_PDIR_PDI_MASK)
/*! @} */

/*! @name PDDR - Port Data Direction Register */
/*! @{ */

#define GPIO_PDDR_PDD_MASK                       (0xFFU)
#define GPIO_PDDR_PDD_SHIFT                      (0U)
/*! PDD - Port Data Direction
 *  0b00000000..Pin is configured as general-purpose input, for the GPIO function.
 *  0b00000001..Pin is configured as general-purpose output, for the GPIO function.
 */
#define GPIO_PDDR_PDD(x)                         (((uint8_t)(((uint8_t)(x)) << GPIO_PDDR_PDD_SHIFT)) & GPIO_PDDR_PDD_MASK)
/*! @} */

/*! @name GACR - GPIO Attribute Checker Register */
/*! @{ */

#define GPIO_GACR_ACB_MASK                       (0x7U)
#define GPIO_GACR_ACB_SHIFT                      (0U)
/*! ACB - Attribute Check Byte
 *  0b000..User nonsecure: Read + Write; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b001..User nonsecure: Read; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b010..User nonsecure: None; User Secure: Read + Write; Privileged Secure: Read + Write
 *  0b011..User nonsecure: Read; User Secure: Read; Privileged Secure: Read + Write
 *  0b100..User nonsecure: None; User Secure: Read; Privileged Secure: Read + Write
 *  0b101..User nonsecure: None; User Secure: None; Privileged Secure: Read + Write
 *  0b110..User nonsecure: None; User Secure: None; Privileged Secure: Read
 *  0b111..User nonsecure: None; User Secure: None; Privileged Secure: None
 */
#define GPIO_GACR_ACB(x)                         (((uint8_t)(((uint8_t)(x)) << GPIO_GACR_ACB_SHIFT)) & GPIO_GACR_ACB_MASK)

#define GPIO_GACR_ROB_MASK                       (0x80U)
#define GPIO_GACR_ROB_SHIFT                      (7U)
/*! ROB - Read-Only Byte
 *  0b0..Writes to the ACB are allowed.
 *  0b1..Writes to the ACB are ignored.
 */
#define GPIO_GACR_ROB(x)                         (((uint8_t)(((uint8_t)(x)) << GPIO_GACR_ROB_SHIFT)) & GPIO_GACR_ROB_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


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


#endif  /* GPIO_H_ */

