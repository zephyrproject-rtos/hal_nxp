/*
** ###################################################################
**     Processors:          MIMX9371xxVTx_ca55
**                          MIMX9371xxVTx_cm33
**                          MIMX9371xxVTx_cm7
**                          MIMX9373xxVTx_ca55
**                          MIMX9373xxVTx_cm33
**                          MIMX9373xxVTx_cm7
**                          MIMX9373xxVZx_ca55
**                          MIMX9373xxVZx_cm33
**                          MIMX9373xxVZx_cm7
**                          MIMX9375xxVTx_ca55
**                          MIMX9375xxVTx_cm33
**                          MIMX9375xxVTx_cm7
**                          MIMX9375xxVZx_ca55
**                          MIMX9375xxVZx_cm33
**                          MIMX9375xxVZx_cm7
**
**     Version:             rev. 1.0, 2026-04-09
**     Build:               b260624
**
**     Abstract:
**         CMSIS Peripheral Access Layer for cmdseqir
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026-04-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_cmdseqir.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for cmdseqir
 *
 * CMSIS Peripheral Access Layer for cmdseqir
 */

#if !defined(PERI_CMDSEQIR_H_)
#define PERI_CMDSEQIR_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9371xxVTx_ca55))
#include "MIMX9371_ca55_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm33))
#include "MIMX9371_cm33_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm7))
#include "MIMX9371_cm7_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_ca55) || defined(CPU_MIMX9373xxVZx_ca55))
#include "MIMX9373_ca55_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm33) || defined(CPU_MIMX9373xxVZx_cm33))
#include "MIMX9373_cm33_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm7) || defined(CPU_MIMX9373xxVZx_cm7))
#include "MIMX9373_cm7_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_ca55) || defined(CPU_MIMX9375xxVZx_ca55))
#include "MIMX9375_ca55_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm33) || defined(CPU_MIMX9375xxVZx_cm33))
#include "MIMX9375_cm33_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm7) || defined(CPU_MIMX9375xxVZx_cm7))
#include "MIMX9375_cm7_COMMON.h"
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
   -- cmdseqir Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup cmdseqir_Peripheral_Access_Layer cmdseqir Peripheral Access Layer
 * @{
 */

/** cmdseqir - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __O  uint32_t INTERP0;                           /**< InterruptPreset0, offset: 0x8 */
  __O  uint32_t INTERP1;                           /**< InterruptPreset1, offset: 0xC */
  __O  uint32_t INTERP2;                           /**< InterruptPreset2, offset: 0x10 */
  __O  uint32_t INTERC0;                           /**< InterruptClear0, offset: 0x14 */
  __O  uint32_t INTERC1;                           /**< InterruptClear1, offset: 0x18 */
  __O  uint32_t INTERC2;                           /**< InterruptClear2, offset: 0x1C */
  __I  uint32_t INTERS0;                           /**< InterruptStatus0, offset: 0x20 */
  __I  uint32_t INTERS1;                           /**< InterruptStatus1, offset: 0x24 */
  __I  uint32_t INTERS2;                           /**< InterruptStatus2, offset: 0x28 */
} cmdseqir_Type;

/* ----------------------------------------------------------------------------
   -- cmdseqir Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup cmdseqir_Register_Masks cmdseqir Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define cmdseqir_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define cmdseqir_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define cmdseqir_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << cmdseqir_LU_LkUn_SHIFT)) & cmdseqir_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define cmdseqir_LOCKS_LkSus_MASK                (0x1U)
#define cmdseqir_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define cmdseqir_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << cmdseqir_LOCKS_LkSus_SHIFT)) & cmdseqir_LOCKS_LkSus_MASK)

#define cmdseqir_LOCKS_PriSt_MASK                (0x10U)
#define cmdseqir_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define cmdseqir_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << cmdseqir_LOCKS_PriSt_SHIFT)) & cmdseqir_LOCKS_PriSt_MASK)

#define cmdseqir_LOCKS_FreezeS_MASK              (0x100U)
#define cmdseqir_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define cmdseqir_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << cmdseqir_LOCKS_FreezeS_SHIFT)) & cmdseqir_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name INTERP0 - InterruptPreset0 */
/*! @{ */

#define cmdseqir_INTERP0_IntP0_MASK              (0xFFFFFFFFU)
#define cmdseqir_INTERP0_IntP0_SHIFT             (0U)
/*! IntP0 - InterruptPreset0 */
#define cmdseqir_INTERP0_IntP0(x)                (((uint32_t)(((uint32_t)(x)) << cmdseqir_INTERP0_IntP0_SHIFT)) & cmdseqir_INTERP0_IntP0_MASK)
/*! @} */

/*! @name INTERP1 - InterruptPreset1 */
/*! @{ */

#define cmdseqir_INTERP1_IntP1_MASK              (0xFFFFFFFFU)
#define cmdseqir_INTERP1_IntP1_SHIFT             (0U)
/*! IntP1 - InterruptPreset1 */
#define cmdseqir_INTERP1_IntP1(x)                (((uint32_t)(((uint32_t)(x)) << cmdseqir_INTERP1_IntP1_SHIFT)) & cmdseqir_INTERP1_IntP1_MASK)
/*! @} */

/*! @name INTERP2 - InterruptPreset2 */
/*! @{ */

#define cmdseqir_INTERP2_IntP2_MASK              (0x1FFFFFU)
#define cmdseqir_INTERP2_IntP2_SHIFT             (0U)
/*! IntP2 - InterruptPreset2 */
#define cmdseqir_INTERP2_IntP2(x)                (((uint32_t)(((uint32_t)(x)) << cmdseqir_INTERP2_IntP2_SHIFT)) & cmdseqir_INTERP2_IntP2_MASK)
/*! @} */

/*! @name INTERC0 - InterruptClear0 */
/*! @{ */

#define cmdseqir_INTERC0_IntC0_MASK              (0xFFFFFFFFU)
#define cmdseqir_INTERC0_IntC0_SHIFT             (0U)
/*! IntC0 - InterruptClear0 */
#define cmdseqir_INTERC0_IntC0(x)                (((uint32_t)(((uint32_t)(x)) << cmdseqir_INTERC0_IntC0_SHIFT)) & cmdseqir_INTERC0_IntC0_MASK)
/*! @} */

/*! @name INTERC1 - InterruptClear1 */
/*! @{ */

#define cmdseqir_INTERC1_IntC1_MASK              (0xFFFFFFFFU)
#define cmdseqir_INTERC1_IntC1_SHIFT             (0U)
/*! IntC1 - InterruptClear1 */
#define cmdseqir_INTERC1_IntC1(x)                (((uint32_t)(((uint32_t)(x)) << cmdseqir_INTERC1_IntC1_SHIFT)) & cmdseqir_INTERC1_IntC1_MASK)
/*! @} */

/*! @name INTERC2 - InterruptClear2 */
/*! @{ */

#define cmdseqir_INTERC2_IntC2_MASK              (0x1FFFFFU)
#define cmdseqir_INTERC2_IntC2_SHIFT             (0U)
/*! IntC2 - InterruptClear2 */
#define cmdseqir_INTERC2_IntC2(x)                (((uint32_t)(((uint32_t)(x)) << cmdseqir_INTERC2_IntC2_SHIFT)) & cmdseqir_INTERC2_IntC2_MASK)
/*! @} */

/*! @name INTERS0 - InterruptStatus0 */
/*! @{ */

#define cmdseqir_INTERS0_IntS0_MASK              (0xFFFFFFFFU)
#define cmdseqir_INTERS0_IntS0_SHIFT             (0U)
/*! IntS0 - InterruptStatus0 */
#define cmdseqir_INTERS0_IntS0(x)                (((uint32_t)(((uint32_t)(x)) << cmdseqir_INTERS0_IntS0_SHIFT)) & cmdseqir_INTERS0_IntS0_MASK)
/*! @} */

/*! @name INTERS1 - InterruptStatus1 */
/*! @{ */

#define cmdseqir_INTERS1_IntS1_MASK              (0xFFFFFFFFU)
#define cmdseqir_INTERS1_IntS1_SHIFT             (0U)
/*! IntS1 - InterruptStatus1 */
#define cmdseqir_INTERS1_IntS1(x)                (((uint32_t)(((uint32_t)(x)) << cmdseqir_INTERS1_IntS1_SHIFT)) & cmdseqir_INTERS1_IntS1_MASK)
/*! @} */

/*! @name INTERS2 - InterruptStatus2 */
/*! @{ */

#define cmdseqir_INTERS2_IntS2_MASK              (0x1FFFFFU)
#define cmdseqir_INTERS2_IntS2_SHIFT             (0U)
/*! IntS2 - InterruptStatus2 */
#define cmdseqir_INTERS2_IntS2(x)                (((uint32_t)(((uint32_t)(x)) << cmdseqir_INTERS2_IntS2_SHIFT)) & cmdseqir_INTERS2_IntS2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group cmdseqir_Register_Masks */


/*!
 * @}
 */ /* end of group cmdseqir_Peripheral_Access_Layer */


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


#endif  /* PERI_CMDSEQIR_H_ */

