/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for irq3
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_irq3.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for irq3
 *
 * CMSIS Peripheral Access Layer for irq3
 */

#if !defined(PERI_IRQ3_H_)
#define PERI_IRQ3_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- irq3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup irq3_Peripheral_Access_Layer irq3 Peripheral Access Layer
 * @{
 */

/** irq3 - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t INTERE0;                           /**< InterruptEnable0, offset: 0x8 */
  __IO uint32_t INTERE1;                           /**< InterruptEnable1, offset: 0xC */
  __IO uint32_t INTERE2;                           /**< InterruptEnable2, offset: 0x10 */
  __O  uint32_t INTERP0;                           /**< InterruptPreset0, offset: 0x14 */
  __O  uint32_t INTERP1;                           /**< InterruptPreset1, offset: 0x18 */
  __O  uint32_t INTERP2;                           /**< InterruptPreset2, offset: 0x1C */
  __O  uint32_t INTERC0;                           /**< InterruptClear0, offset: 0x20 */
  __O  uint32_t INTERC1;                           /**< InterruptClear1, offset: 0x24 */
  __O  uint32_t INTERC2;                           /**< InterruptClear2, offset: 0x28 */
  __I  uint32_t INTERS0;                           /**< InterruptStatus0, offset: 0x2C */
  __I  uint32_t INTERS1;                           /**< InterruptStatus1, offset: 0x30 */
  __I  uint32_t INTERS2;                           /**< InterruptStatus2, offset: 0x34 */
} irq3_Type;

/* ----------------------------------------------------------------------------
   -- irq3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup irq3_Register_Masks irq3 Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define irq3_LU_LkUn_MASK                        (0xFFFFFFFFU)
#define irq3_LU_LkUn_SHIFT                       (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define irq3_LU_LkUn(x)                          (((uint32_t)(((uint32_t)(x)) << irq3_LU_LkUn_SHIFT)) & irq3_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define irq3_LOCKS_LkSus_MASK                    (0x1U)
#define irq3_LOCKS_LkSus_SHIFT                   (0U)
/*! LkSus - LockStatus */
#define irq3_LOCKS_LkSus(x)                      (((uint32_t)(((uint32_t)(x)) << irq3_LOCKS_LkSus_SHIFT)) & irq3_LOCKS_LkSus_MASK)

#define irq3_LOCKS_PriSt_MASK                    (0x10U)
#define irq3_LOCKS_PriSt_SHIFT                   (4U)
/*! PriSt - PrivilegeStatus */
#define irq3_LOCKS_PriSt(x)                      (((uint32_t)(((uint32_t)(x)) << irq3_LOCKS_PriSt_SHIFT)) & irq3_LOCKS_PriSt_MASK)

#define irq3_LOCKS_FreezeS_MASK                  (0x100U)
#define irq3_LOCKS_FreezeS_SHIFT                 (8U)
/*! FreezeS - FreezeStatus */
#define irq3_LOCKS_FreezeS(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_LOCKS_FreezeS_SHIFT)) & irq3_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name INTERE0 - InterruptEnable0 */
/*! @{ */

#define irq3_INTERE0_IntE0_MASK                  (0xFFFFFFFFU)
#define irq3_INTERE0_IntE0_SHIFT                 (0U)
/*! IntE0 - InterruptEnable0 */
#define irq3_INTERE0_IntE0(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERE0_IntE0_SHIFT)) & irq3_INTERE0_IntE0_MASK)
/*! @} */

/*! @name INTERE1 - InterruptEnable1 */
/*! @{ */

#define irq3_INTERE1_IntE1_MASK                  (0xFFFFFFFFU)
#define irq3_INTERE1_IntE1_SHIFT                 (0U)
/*! IntE1 - InterruptEnable1 */
#define irq3_INTERE1_IntE1(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERE1_IntE1_SHIFT)) & irq3_INTERE1_IntE1_MASK)
/*! @} */

/*! @name INTERE2 - InterruptEnable2 */
/*! @{ */

#define irq3_INTERE2_IntE2_MASK                  (0x1FFFFFU)
#define irq3_INTERE2_IntE2_SHIFT                 (0U)
/*! IntE2 - InterruptEnable2 */
#define irq3_INTERE2_IntE2(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERE2_IntE2_SHIFT)) & irq3_INTERE2_IntE2_MASK)
/*! @} */

/*! @name INTERP0 - InterruptPreset0 */
/*! @{ */

#define irq3_INTERP0_IntP0_MASK                  (0xFFFFFFFFU)
#define irq3_INTERP0_IntP0_SHIFT                 (0U)
/*! IntP0 - InterruptPreset0 */
#define irq3_INTERP0_IntP0(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERP0_IntP0_SHIFT)) & irq3_INTERP0_IntP0_MASK)
/*! @} */

/*! @name INTERP1 - InterruptPreset1 */
/*! @{ */

#define irq3_INTERP1_IntP1_MASK                  (0xFFFFFFFFU)
#define irq3_INTERP1_IntP1_SHIFT                 (0U)
/*! IntP1 - InterruptPreset1 */
#define irq3_INTERP1_IntP1(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERP1_IntP1_SHIFT)) & irq3_INTERP1_IntP1_MASK)
/*! @} */

/*! @name INTERP2 - InterruptPreset2 */
/*! @{ */

#define irq3_INTERP2_IntP2_MASK                  (0x1FFFFFU)
#define irq3_INTERP2_IntP2_SHIFT                 (0U)
/*! IntP2 - InterruptPreset2 */
#define irq3_INTERP2_IntP2(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERP2_IntP2_SHIFT)) & irq3_INTERP2_IntP2_MASK)
/*! @} */

/*! @name INTERC0 - InterruptClear0 */
/*! @{ */

#define irq3_INTERC0_IntC0_MASK                  (0xFFFFFFFFU)
#define irq3_INTERC0_IntC0_SHIFT                 (0U)
/*! IntC0 - InterruptClear0 */
#define irq3_INTERC0_IntC0(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERC0_IntC0_SHIFT)) & irq3_INTERC0_IntC0_MASK)
/*! @} */

/*! @name INTERC1 - InterruptClear1 */
/*! @{ */

#define irq3_INTERC1_IntC1_MASK                  (0xFFFFFFFFU)
#define irq3_INTERC1_IntC1_SHIFT                 (0U)
/*! IntC1 - InterruptClear1 */
#define irq3_INTERC1_IntC1(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERC1_IntC1_SHIFT)) & irq3_INTERC1_IntC1_MASK)
/*! @} */

/*! @name INTERC2 - InterruptClear2 */
/*! @{ */

#define irq3_INTERC2_IntC2_MASK                  (0x1FFFFFU)
#define irq3_INTERC2_IntC2_SHIFT                 (0U)
/*! IntC2 - InterruptClear2 */
#define irq3_INTERC2_IntC2(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERC2_IntC2_SHIFT)) & irq3_INTERC2_IntC2_MASK)
/*! @} */

/*! @name INTERS0 - InterruptStatus0 */
/*! @{ */

#define irq3_INTERS0_IntS0_MASK                  (0xFFFFFFFFU)
#define irq3_INTERS0_IntS0_SHIFT                 (0U)
/*! IntS0 - InterruptStatus0 */
#define irq3_INTERS0_IntS0(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERS0_IntS0_SHIFT)) & irq3_INTERS0_IntS0_MASK)
/*! @} */

/*! @name INTERS1 - InterruptStatus1 */
/*! @{ */

#define irq3_INTERS1_IntS1_MASK                  (0xFFFFFFFFU)
#define irq3_INTERS1_IntS1_SHIFT                 (0U)
/*! IntS1 - InterruptStatus1 */
#define irq3_INTERS1_IntS1(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERS1_IntS1_SHIFT)) & irq3_INTERS1_IntS1_MASK)
/*! @} */

/*! @name INTERS2 - InterruptStatus2 */
/*! @{ */

#define irq3_INTERS2_IntS2_MASK                  (0x1FFFFFU)
#define irq3_INTERS2_IntS2_SHIFT                 (0U)
/*! IntS2 - InterruptStatus2 */
#define irq3_INTERS2_IntS2(x)                    (((uint32_t)(((uint32_t)(x)) << irq3_INTERS2_IntS2_SHIFT)) & irq3_INTERS2_IntS2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group irq3_Register_Masks */


/*!
 * @}
 */ /* end of group irq3_Peripheral_Access_Layer */


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


#endif  /* PERI_IRQ3_H_ */

