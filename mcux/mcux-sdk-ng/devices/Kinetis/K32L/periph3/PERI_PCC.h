/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PCC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PCC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC
 *
 * CMSIS Peripheral Access Layer for PCC
 */

#if !defined(PERI_PCC_H_)
#define PERI_PCC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
   -- PCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Peripheral_Access_Layer PCC Peripheral Access Layer
 * @{
 */

/** PCC - Size of Registers Arrays */
#define PCC_CLKCFG_COUNT                          130u

/** PCC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CLKCFG[PCC_CLKCFG_COUNT];          /**< PCC MSCM Register..PCC EXT_CLK Register, array offset: 0x0, array step: 0x4, irregular array, not all indices are valid */
} PCC_Type;

/* ----------------------------------------------------------------------------
   -- PCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Register_Masks PCC Register Masks
 * @{
 */

/*! @name CLKCFG - PCC MSCM Register..PCC EXT_CLK Register */
/*! @{ */

#define PCC_CLKCFG_PCD_MASK                      (0x7U)
#define PCC_CLKCFG_PCD_SHIFT                     (0U)
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
#define PCC_CLKCFG_PCD(x)                        (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_PCD_SHIFT)) & PCC_CLKCFG_PCD_MASK)

#define PCC_CLKCFG_FRAC_MASK                     (0x8U)
#define PCC_CLKCFG_FRAC_SHIFT                    (3U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC_CLKCFG_FRAC(x)                       (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_FRAC_SHIFT)) & PCC_CLKCFG_FRAC_MASK)

#define PCC_CLKCFG_PCS_MASK                      (0x7000000U)
#define PCC_CLKCFG_PCS_SHIFT                     (24U)
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
#define PCC_CLKCFG_PCS(x)                        (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_PCS_SHIFT)) & PCC_CLKCFG_PCS_MASK)

#define PCC_CLKCFG_INUSE_MASK                    (0x20000000U)
#define PCC_CLKCFG_INUSE_SHIFT                   (29U)
/*! INUSE - In use flag
 *  0b0..Peripheral is not being used.
 *  0b1..Peripheral is being used. Software cannot modify the existing clocking configuration.
 */
#define PCC_CLKCFG_INUSE(x)                      (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_INUSE_SHIFT)) & PCC_CLKCFG_INUSE_MASK)

#define PCC_CLKCFG_CGC_MASK                      (0x40000000U)
#define PCC_CLKCFG_CGC_SHIFT                     (30U)
/*! CGC - Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled. The current clock selection and divider options are locked.
 */
#define PCC_CLKCFG_CGC(x)                        (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_CGC_SHIFT)) & PCC_CLKCFG_CGC_MASK)

#define PCC_CLKCFG_PR_MASK                       (0x80000000U)
#define PCC_CLKCFG_PR_SHIFT                      (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC_CLKCFG_PR(x)                         (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_PR_SHIFT)) & PCC_CLKCFG_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCC_Register_Masks */


/*!
 * @}
 */ /* end of group PCC_Peripheral_Access_Layer */


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


#endif  /* PERI_PCC_H_ */

