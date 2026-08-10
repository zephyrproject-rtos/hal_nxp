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
**         CMSIS Peripheral Access Layer for sig0cfg
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
 * @file PERI_sig0cfg.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for sig0cfg
 *
 * CMSIS Peripheral Access Layer for sig0cfg
 */

#if !defined(PERI_SIG0CFG_H_)
#define PERI_SIG0CFG_H_                          /**< Symbol preventing repeated inclusion */

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
   -- sig0cfg Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup sig0cfg_Peripheral_Access_Layer sig0cfg Peripheral Access Layer
 * @{
 */

/** sig0cfg - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t SRCSELEC;                          /**< SrcSelect, offset: 0x8 */
} sig0cfg_Type;

/* ----------------------------------------------------------------------------
   -- sig0cfg Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup sig0cfg_Register_Masks sig0cfg Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define sig0cfg_LU_LkUn_MASK                     (0xFFFFFFFFU)
#define sig0cfg_LU_LkUn_SHIFT                    (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define sig0cfg_LU_LkUn(x)                       (((uint32_t)(((uint32_t)(x)) << sig0cfg_LU_LkUn_SHIFT)) & sig0cfg_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define sig0cfg_LOCKS_LkSus_MASK                 (0x1U)
#define sig0cfg_LOCKS_LkSus_SHIFT                (0U)
/*! LkSus - LockStatus */
#define sig0cfg_LOCKS_LkSus(x)                   (((uint32_t)(((uint32_t)(x)) << sig0cfg_LOCKS_LkSus_SHIFT)) & sig0cfg_LOCKS_LkSus_MASK)

#define sig0cfg_LOCKS_PriSt_MASK                 (0x10U)
#define sig0cfg_LOCKS_PriSt_SHIFT                (4U)
/*! PriSt - PrivilegeStatus */
#define sig0cfg_LOCKS_PriSt(x)                   (((uint32_t)(((uint32_t)(x)) << sig0cfg_LOCKS_PriSt_SHIFT)) & sig0cfg_LOCKS_PriSt_MASK)

#define sig0cfg_LOCKS_FreezeS_MASK               (0x100U)
#define sig0cfg_LOCKS_FreezeS_SHIFT              (8U)
/*! FreezeS - FreezeStatus */
#define sig0cfg_LOCKS_FreezeS(x)                 (((uint32_t)(((uint32_t)(x)) << sig0cfg_LOCKS_FreezeS_SHIFT)) & sig0cfg_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name SRCSELEC - SrcSelect */
/*! @{ */

#define sig0cfg_SRCSELEC_sig0sel_MASK            (0x7U)
#define sig0cfg_SRCSELEC_sig0sel_SHIFT           (0U)
/*! sig0sel - sig0_select
 *  0b000..Source is FrameGen#0 output.
 *  0b001..Source is Matrix#0 output.
 *  0b010..Source is LuT3D#0 output.
 *  0b011..Reserved
 *  0b100..Source is GammaCor#0 output.
 *  0b101..Source is Dither#0 output.
 */
#define sig0cfg_SRCSELEC_sig0sel(x)              (((uint32_t)(((uint32_t)(x)) << sig0cfg_SRCSELEC_sig0sel_SHIFT)) & sig0cfg_SRCSELEC_sig0sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group sig0cfg_Register_Masks */


/*!
 * @}
 */ /* end of group sig0cfg_Peripheral_Access_Layer */


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


#endif  /* PERI_SIG0CFG_H_ */

