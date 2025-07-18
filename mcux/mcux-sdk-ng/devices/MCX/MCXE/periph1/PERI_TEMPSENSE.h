/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TEMPSENSE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_TEMPSENSE.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for TEMPSENSE
 *
 * CMSIS Peripheral Access Layer for TEMPSENSE
 */

#if !defined(PERI_TEMPSENSE_H_)
#define PERI_TEMPSENSE_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- TEMPSENSE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TEMPSENSE_Peripheral_Access_Layer TEMPSENSE Peripheral Access Layer
 * @{
 */

/** TEMPSENSE - Register Layout Typedef */
typedef struct {
  __IO uint32_t ETSCTL;                            /**< ETS Control, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __I  uint32_t TCA0;                              /**< Temperature Coefficient, offset: 0x8 */
  __I  uint32_t TCA1;                              /**< Temperature Coefficient, offset: 0xC */
  __I  uint32_t TCA2;                              /**< Temperature Coefficient, offset: 0x10 */
} TEMPSENSE_Type;

/* ----------------------------------------------------------------------------
   -- TEMPSENSE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TEMPSENSE_Register_Masks TEMPSENSE Register Masks
 * @{
 */

/*! @name ETSCTL - ETS Control */
/*! @{ */

#define TEMPSENSE_ETSCTL_ETS_EN_MASK             (0x1U)
#define TEMPSENSE_ETSCTL_ETS_EN_SHIFT            (0U)
/*! ETS_EN - Temperature Sensor enable
 *  0b0..Power down
 *  0b1..Functional mode
 */
#define TEMPSENSE_ETSCTL_ETS_EN(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_ETSCTL_ETS_EN_SHIFT)) & TEMPSENSE_ETSCTL_ETS_EN_MASK)

#define TEMPSENSE_ETSCTL_GNDSEL_MASK             (0x2U)
#define TEMPSENSE_ETSCTL_GNDSEL_SHIFT            (1U)
/*! GNDSEL - Ground selection
 *  0b0..No exposure of the ground
 *  0b1..Expose ground on the ADC output if ETS_EN=1
 */
#define TEMPSENSE_ETSCTL_GNDSEL(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_ETSCTL_GNDSEL_SHIFT)) & TEMPSENSE_ETSCTL_GNDSEL_MASK)
/*! @} */

/*! @name TCA0 - Temperature Coefficient */
/*! @{ */

#define TEMPSENSE_TCA0_TCA0_MASK                 (0xFFFFU)
#define TEMPSENSE_TCA0_TCA0_SHIFT                (0U)
/*! TCA0 - Temperature coefficient A0 */
#define TEMPSENSE_TCA0_TCA0(x)                   (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_TCA0_TCA0_SHIFT)) & TEMPSENSE_TCA0_TCA0_MASK)
/*! @} */

/*! @name TCA1 - Temperature Coefficient */
/*! @{ */

#define TEMPSENSE_TCA1_TCA1_MASK                 (0xFFFFU)
#define TEMPSENSE_TCA1_TCA1_SHIFT                (0U)
/*! TCA1 - Temperature coefficient A1 */
#define TEMPSENSE_TCA1_TCA1(x)                   (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_TCA1_TCA1_SHIFT)) & TEMPSENSE_TCA1_TCA1_MASK)
/*! @} */

/*! @name TCA2 - Temperature Coefficient */
/*! @{ */

#define TEMPSENSE_TCA2_TCA2_MASK                 (0xFFFFU)
#define TEMPSENSE_TCA2_TCA2_SHIFT                (0U)
/*! TCA2 - Temperature coefficient A2 */
#define TEMPSENSE_TCA2_TCA2(x)                   (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_TCA2_TCA2_SHIFT)) & TEMPSENSE_TCA2_TCA2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TEMPSENSE_Register_Masks */


/*!
 * @}
 */ /* end of group TEMPSENSE_Peripheral_Access_Layer */


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


#endif  /* PERI_TEMPSENSE_H_ */

