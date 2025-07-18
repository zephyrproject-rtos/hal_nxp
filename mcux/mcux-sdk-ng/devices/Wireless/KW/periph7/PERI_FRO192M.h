/*
** ###################################################################
**     Processors:          KW45B41Z52AFPA
**                          KW45B41Z52AFTA
**                          KW45B41Z53AFPA
**                          KW45B41Z53AFTA
**                          KW45B41Z82AFPA
**                          KW45B41Z82AFTA
**                          KW45B41Z83AFPA
**                          KW45B41Z83AFPA_NBU
**                          KW45B41Z83AFTA
**                          KW45B41Z83AFTA_NBU
**                          KW45Z41052AFPA
**                          KW45Z41052AFTA
**                          KW45Z41053AFPA
**                          KW45Z41053AFTA
**                          KW45Z41082AFPA
**                          KW45Z41082AFTA
**                          KW45Z41083AFPA
**                          KW45Z41083AFTA
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FRO192M
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FRO192M.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FRO192M
 *
 * CMSIS Peripheral Access Layer for FRO192M
 */

#if !defined(PERI_FRO192M_H_)
#define PERI_FRO192M_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW45B41Z52AFPA) || defined(CPU_KW45B41Z52AFTA))
#include "KW45B41Z52_COMMON.h"
#elif (defined(CPU_KW45B41Z53AFPA) || defined(CPU_KW45B41Z53AFTA))
#include "KW45B41Z53_COMMON.h"
#elif (defined(CPU_KW45B41Z82AFPA) || defined(CPU_KW45B41Z82AFTA))
#include "KW45B41Z82_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA) || defined(CPU_KW45B41Z83AFTA))
#include "KW45B41Z83_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA_NBU) || defined(CPU_KW45B41Z83AFTA_NBU))
#include "KW45B41Z83_NBU_COMMON.h"
#elif (defined(CPU_KW45Z41052AFPA) || defined(CPU_KW45Z41052AFTA))
#include "KW45Z41052_COMMON.h"
#elif (defined(CPU_KW45Z41053AFPA) || defined(CPU_KW45Z41053AFTA))
#include "KW45Z41053_COMMON.h"
#elif (defined(CPU_KW45Z41082AFPA) || defined(CPU_KW45Z41082AFTA))
#include "KW45Z41082_COMMON.h"
#elif (defined(CPU_KW45Z41083AFPA) || defined(CPU_KW45Z41083AFTA))
#include "KW45Z41083_COMMON.h"
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
   -- FRO192M Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRO192M_Peripheral_Access_Layer FRO192M Peripheral Access Layer
 * @{
 */

/** FRO192M - Register Layout Typedef */
typedef struct {
  __IO uint32_t FROCCSR;                           /**< FRO192 Clock Control Status Register, offset: 0x0 */
  __IO uint32_t FRODIV;                            /**< FRO192 Divide Register, offset: 0x4 */
} FRO192M_Type;

/* ----------------------------------------------------------------------------
   -- FRO192M Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRO192M_Register_Masks FRO192M Register Masks
 * @{
 */

/*! @name FROCCSR - FRO192 Clock Control Status Register */
/*! @{ */

#define FRO192M_FROCCSR_FRODIV_MASK              (0x3U)
#define FRO192M_FROCCSR_FRODIV_SHIFT             (0U)
/*! FRODIV - FRO Clock Divide
 *  0b00..Divide by 1
 *  0b01..Divide by 2
 *  0b10..Divide by 3
 *  0b11..Divide by 4
 */
#define FRO192M_FROCCSR_FRODIV(x)                (((uint32_t)(((uint32_t)(x)) << FRO192M_FROCCSR_FRODIV_SHIFT)) & FRO192M_FROCCSR_FRODIV_MASK)

#define FRO192M_FROCCSR_POSTDIV_SEL_MASK         (0x7000U)
#define FRO192M_FROCCSR_POSTDIV_SEL_SHIFT        (12U)
/*! POSTDIV_SEL - Post Divider Clock Select
 *  0b000..FRO 16MHz Range selected.
 *  0b001..FRO 24MHz Range selected
 *  0b010..FRO 32MHz Range selected
 *  0b011..FRO 48MHz Range selected
 *  0b100..FRO 64MHz Range selected
 *  0b101..RESERVED. Not Supported
 *  0b110..RESERVED. Not Supported
 *  0b111..RESERVED. Not Supported
 */
#define FRO192M_FROCCSR_POSTDIV_SEL(x)           (((uint32_t)(((uint32_t)(x)) << FRO192M_FROCCSR_POSTDIV_SEL_SHIFT)) & FRO192M_FROCCSR_POSTDIV_SEL_MASK)

#define FRO192M_FROCCSR_VALID_MASK               (0x1000000U)
#define FRO192M_FROCCSR_VALID_SHIFT              (24U)
/*! VALID - Clock Valid Flag
 *  0b0..FRO192 is not enabled or clock is not valid.
 *  0b1..FRO192 is enabled and output clock is valid.
 */
#define FRO192M_FROCCSR_VALID(x)                 (((uint32_t)(((uint32_t)(x)) << FRO192M_FROCCSR_VALID_SHIFT)) & FRO192M_FROCCSR_VALID_MASK)
/*! @} */

/*! @name FRODIV - FRO192 Divide Register */
/*! @{ */

#define FRO192M_FRODIV_FRODIV_MASK               (0x3U)
#define FRO192M_FRODIV_FRODIV_SHIFT              (0U)
/*! FRODIV - FRO Clock Divide
 *  0b00..Divide by 1
 *  0b01..Divide by 2
 *  0b10..Divide by 3
 *  0b11..Divide by 4
 */
#define FRO192M_FRODIV_FRODIV(x)                 (((uint32_t)(((uint32_t)(x)) << FRO192M_FRODIV_FRODIV_SHIFT)) & FRO192M_FRODIV_FRODIV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FRO192M_Register_Masks */


/*!
 * @}
 */ /* end of group FRO192M_Peripheral_Access_Layer */


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


#endif  /* PERI_FRO192M_H_ */

