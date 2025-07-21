/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CACHE64_POLSEL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CACHE64_POLSEL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CACHE64_POLSEL
 *
 * CMSIS Peripheral Access Layer for CACHE64_POLSEL
 */

#if !defined(PERI_CACHE64_POLSEL_H_)
#define PERI_CACHE64_POLSEL_H_                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
   -- CACHE64_POLSEL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CACHE64_POLSEL_Peripheral_Access_Layer CACHE64_POLSEL Peripheral Access Layer
 * @{
 */

/** CACHE64_POLSEL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[20];
  __IO uint32_t REG0_TOP;                          /**< Region 0 Top Boundary, offset: 0x14 */
  __IO uint32_t REG1_TOP;                          /**< Region 1 Top Boundary, offset: 0x18 */
  __IO uint32_t POLSEL;                            /**< Policy Select, offset: 0x1C */
} CACHE64_POLSEL_Type;

/* ----------------------------------------------------------------------------
   -- CACHE64_POLSEL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CACHE64_POLSEL_Register_Masks CACHE64_POLSEL Register Masks
 * @{
 */

/*! @name REG0_TOP - Region 0 Top Boundary */
/*! @{ */

#define CACHE64_POLSEL_REG0_TOP_REG0_TOP_MASK    (0x7FFFC00U)
#define CACHE64_POLSEL_REG0_TOP_REG0_TOP_SHIFT   (10U)
/*! REG0_TOP - Upper Limit Of Region 0 */
#define CACHE64_POLSEL_REG0_TOP_REG0_TOP(x)      (((uint32_t)(((uint32_t)(x)) << CACHE64_POLSEL_REG0_TOP_REG0_TOP_SHIFT)) & CACHE64_POLSEL_REG0_TOP_REG0_TOP_MASK)
/*! @} */

/*! @name REG1_TOP - Region 1 Top Boundary */
/*! @{ */

#define CACHE64_POLSEL_REG1_TOP_REG1_TOP_MASK    (0x7FFFC00U)
#define CACHE64_POLSEL_REG1_TOP_REG1_TOP_SHIFT   (10U)
/*! REG1_TOP - Upper Limit Of Region 1 */
#define CACHE64_POLSEL_REG1_TOP_REG1_TOP(x)      (((uint32_t)(((uint32_t)(x)) << CACHE64_POLSEL_REG1_TOP_REG1_TOP_SHIFT)) & CACHE64_POLSEL_REG1_TOP_REG1_TOP_MASK)
/*! @} */

/*! @name POLSEL - Policy Select */
/*! @{ */

#define CACHE64_POLSEL_POLSEL_REG0_POLICY_MASK   (0x3U)
#define CACHE64_POLSEL_POLSEL_REG0_POLICY_SHIFT  (0U)
/*! REG0_POLICY - Policy Select For Region 0
 *  0b00..Noncacheable
 *  0b01..Write-through
 *  0b10..Write-back
 *  0b11..Invalid
 */
#define CACHE64_POLSEL_POLSEL_REG0_POLICY(x)     (((uint32_t)(((uint32_t)(x)) << CACHE64_POLSEL_POLSEL_REG0_POLICY_SHIFT)) & CACHE64_POLSEL_POLSEL_REG0_POLICY_MASK)

#define CACHE64_POLSEL_POLSEL_REG1_POLICY_MASK   (0xCU)
#define CACHE64_POLSEL_POLSEL_REG1_POLICY_SHIFT  (2U)
/*! REG1_POLICY - Policy Select For Region 1
 *  0b00..Noncacheable
 *  0b01..Write-through
 *  0b10..Write-back
 *  0b11..Invalid
 */
#define CACHE64_POLSEL_POLSEL_REG1_POLICY(x)     (((uint32_t)(((uint32_t)(x)) << CACHE64_POLSEL_POLSEL_REG1_POLICY_SHIFT)) & CACHE64_POLSEL_POLSEL_REG1_POLICY_MASK)

#define CACHE64_POLSEL_POLSEL_REG2_POLICY_MASK   (0x30U)
#define CACHE64_POLSEL_POLSEL_REG2_POLICY_SHIFT  (4U)
/*! REG2_POLICY - Policy Select For Region 2
 *  0b00..Noncacheable
 *  0b01..Write-through
 *  0b10..Write-back
 *  0b11..Invalid
 */
#define CACHE64_POLSEL_POLSEL_REG2_POLICY(x)     (((uint32_t)(((uint32_t)(x)) << CACHE64_POLSEL_POLSEL_REG2_POLICY_SHIFT)) & CACHE64_POLSEL_POLSEL_REG2_POLICY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CACHE64_POLSEL_Register_Masks */


/*!
 * @}
 */ /* end of group CACHE64_POLSEL_Peripheral_Access_Layer */


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


#endif  /* PERI_CACHE64_POLSEL_H_ */

