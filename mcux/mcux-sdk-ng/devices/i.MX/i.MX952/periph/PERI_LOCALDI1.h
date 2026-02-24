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
**         CMSIS Peripheral Access Layer for localdi1
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
 * @file PERI_localdi1.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for localdi1
 *
 * CMSIS Peripheral Access Layer for localdi1
 */

#if !defined(PERI_LOCALDI1_H_)
#define PERI_LOCALDI1_H_                         /**< Symbol preventing repeated inclusion */

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
   -- localdi1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi1_Peripheral_Access_Layer localdi1 Peripheral Access Layer
 * @{
 */

/** localdi1 - Register Layout Typedef */
typedef struct {
  __O  uint32_t LULD;                              /**< LockUnlockLD, offset: 0x0 */
  __I  uint32_t LOCKSLD;                           /**< LockStatusLD, offset: 0x4 */
} localdi1_Type;

/* ----------------------------------------------------------------------------
   -- localdi1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi1_Register_Masks localdi1 Register Masks
 * @{
 */

/*! @name LULD - LockUnlockLD */
/*! @{ */

#define localdi1_LULD_LkUnLD_MASK                (0xFFFFFFFFU)
#define localdi1_LULD_LkUnLD_SHIFT               (0U)
/*! LkUnLD - LockUnlockLD
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10010010001100110101000010000001..Disable error response for local dimming sub module address space.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11011111011101101101111111001110..Enable error response for local dimming sub module address space.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define localdi1_LULD_LkUnLD(x)                  (((uint32_t)(((uint32_t)(x)) << localdi1_LULD_LkUnLD_SHIFT)) & localdi1_LULD_LkUnLD_MASK)
/*! @} */

/*! @name LOCKSLD - LockStatusLD */
/*! @{ */

#define localdi1_LOCKSLD_LkSLD_MASK              (0x1U)
#define localdi1_LOCKSLD_LkSLD_SHIFT             (0U)
/*! LkSLD - LockStatusLD */
#define localdi1_LOCKSLD_LkSLD(x)                (((uint32_t)(((uint32_t)(x)) << localdi1_LOCKSLD_LkSLD_SHIFT)) & localdi1_LOCKSLD_LkSLD_MASK)

#define localdi1_LOCKSLD_PriStLD_MASK            (0x10U)
#define localdi1_LOCKSLD_PriStLD_SHIFT           (4U)
/*! PriStLD - PrivilegeStatusLD */
#define localdi1_LOCKSLD_PriStLD(x)              (((uint32_t)(((uint32_t)(x)) << localdi1_LOCKSLD_PriStLD_SHIFT)) & localdi1_LOCKSLD_PriStLD_MASK)

#define localdi1_LOCKSLD_FreezeSL_MASK           (0x100U)
#define localdi1_LOCKSLD_FreezeSL_SHIFT          (8U)
/*! FreezeSL - FreezeStatusLD */
#define localdi1_LOCKSLD_FreezeSL(x)             (((uint32_t)(((uint32_t)(x)) << localdi1_LOCKSLD_FreezeSL_SHIFT)) & localdi1_LOCKSLD_FreezeSL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group localdi1_Register_Masks */


/*!
 * @}
 */ /* end of group localdi1_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALDI1_H_ */

