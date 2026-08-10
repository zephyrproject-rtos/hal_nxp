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
**         CMSIS Peripheral Access Layer for fetche9c
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
 * @file PERI_fetche9c.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for fetche9c
 *
 * CMSIS Peripheral Access Layer for fetche9c
 */

#if !defined(PERI_FETCHE9C_H_)
#define PERI_FETCHE9C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetche9c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetche9c_Peripheral_Access_Layer fetche9c Peripheral Access Layer
 * @{
 */

/** fetche9c - Register Layout Typedef */
typedef struct {
  __O  uint32_t FETE9LU;                           /**< fetcheco9_LockUnlock, offset: 0x0 */
  __I  uint32_t FETE9LS;                           /**< fetcheco9_LockStatus, offset: 0x4 */
  __I  uint32_t FETE9S;                            /**< fetcheco9_Status, offset: 0x8 */
} fetche9c_Type;

/* ----------------------------------------------------------------------------
   -- fetche9c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetche9c_Register_Masks fetche9c Register Masks
 * @{
 */

/*! @name FETE9LU - fetcheco9_LockUnlock */
/*! @{ */

#define fetche9c_FETE9LU_fete9LUn_MASK           (0xFFFFFFFFU)
#define fetche9c_FETE9LU_fete9LUn_SHIFT          (0U)
/*! fete9LUn - fetcheco9_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define fetche9c_FETE9LU_fete9LUn(x)             (((uint32_t)(((uint32_t)(x)) << fetche9c_FETE9LU_fete9LUn_SHIFT)) & fetche9c_FETE9LU_fete9LUn_MASK)
/*! @} */

/*! @name FETE9LS - fetcheco9_LockStatus */
/*! @{ */

#define fetche9c_FETE9LS_fete9LS_MASK            (0x1U)
#define fetche9c_FETE9LS_fete9LS_SHIFT           (0U)
/*! fete9LS - fetcheco9_LockStatus */
#define fetche9c_FETE9LS_fete9LS(x)              (((uint32_t)(((uint32_t)(x)) << fetche9c_FETE9LS_fete9LS_SHIFT)) & fetche9c_FETE9LS_fete9LS_MASK)

#define fetche9c_FETE9LS_fete9PS_MASK            (0x10U)
#define fetche9c_FETE9LS_fete9PS_SHIFT           (4U)
/*! fete9PS - fetcheco9_PrivilegeStatus */
#define fetche9c_FETE9LS_fete9PS(x)              (((uint32_t)(((uint32_t)(x)) << fetche9c_FETE9LS_fete9PS_SHIFT)) & fetche9c_FETE9LS_fete9PS_MASK)

#define fetche9c_FETE9LS_fete9FS_MASK            (0x100U)
#define fetche9c_FETE9LS_fete9FS_SHIFT           (8U)
/*! fete9FS - fetcheco9_FreezeStatus */
#define fetche9c_FETE9LS_fete9FS(x)              (((uint32_t)(((uint32_t)(x)) << fetche9c_FETE9LS_fete9FS_SHIFT)) & fetche9c_FETE9LS_fete9FS_MASK)
/*! @} */

/*! @name FETE9S - fetcheco9_Status */
/*! @{ */

#define fetche9c_FETE9S_fete9sel_MASK            (0x70000U)
#define fetche9c_FETE9S_fete9sel_SHIFT           (16U)
/*! fete9sel - fetcheco9_sel
 *  0b000..fetcheco9 module is not used
 *  0b001..fetcheco9 module is used from store9 processing path
 *  0b010..fetcheco9 module is used from extdst0 processing path
 *  0b011..fetcheco9 module is used from extdst4 processing path
 *  0b100..fetcheco9 module is used from extdst1 processing path
 *  0b101..fetcheco9 module is used from extdst5 processing path
 */
#define fetche9c_FETE9S_fete9sel(x)              (((uint32_t)(((uint32_t)(x)) << fetche9c_FETE9S_fete9sel_SHIFT)) & fetche9c_FETE9S_fete9sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetche9c_Register_Masks */


/*!
 * @}
 */ /* end of group fetche9c_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHE9C_H_ */

