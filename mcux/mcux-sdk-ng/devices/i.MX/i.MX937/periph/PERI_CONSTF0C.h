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
**         CMSIS Peripheral Access Layer for constf0c
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
 * @file PERI_constf0c.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for constf0c
 *
 * CMSIS Peripheral Access Layer for constf0c
 */

#if !defined(PERI_CONSTF0C_H_)
#define PERI_CONSTF0C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- constf0c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf0c_Peripheral_Access_Layer constf0c Peripheral Access Layer
 * @{
 */

/** constf0c - Register Layout Typedef */
typedef struct {
  __O  uint32_t CONSF0LU;                          /**< constframe0_LockUnlock, offset: 0x0 */
  __I  uint32_t CONSF0LS;                          /**< constframe0_LockStatus, offset: 0x4 */
  __I  uint32_t CONSF0S;                           /**< constframe0_Status, offset: 0x8 */
} constf0c_Type;

/* ----------------------------------------------------------------------------
   -- constf0c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf0c_Register_Masks constf0c Register Masks
 * @{
 */

/*! @name CONSF0LU - constframe0_LockUnlock */
/*! @{ */

#define constf0c_CONSF0LU_consf0LU_MASK          (0xFFFFFFFFU)
#define constf0c_CONSF0LU_consf0LU_SHIFT         (0U)
/*! consf0LU - constframe0_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define constf0c_CONSF0LU_consf0LU(x)            (((uint32_t)(((uint32_t)(x)) << constf0c_CONSF0LU_consf0LU_SHIFT)) & constf0c_CONSF0LU_consf0LU_MASK)
/*! @} */

/*! @name CONSF0LS - constframe0_LockStatus */
/*! @{ */

#define constf0c_CONSF0LS_consf0LS_MASK          (0x1U)
#define constf0c_CONSF0LS_consf0LS_SHIFT         (0U)
/*! consf0LS - constframe0_LockStatus */
#define constf0c_CONSF0LS_consf0LS(x)            (((uint32_t)(((uint32_t)(x)) << constf0c_CONSF0LS_consf0LS_SHIFT)) & constf0c_CONSF0LS_consf0LS_MASK)

#define constf0c_CONSF0LS_consf0PS_MASK          (0x10U)
#define constf0c_CONSF0LS_consf0PS_SHIFT         (4U)
/*! consf0PS - constframe0_PrivilegeStatus */
#define constf0c_CONSF0LS_consf0PS(x)            (((uint32_t)(((uint32_t)(x)) << constf0c_CONSF0LS_consf0PS_SHIFT)) & constf0c_CONSF0LS_consf0PS_MASK)

#define constf0c_CONSF0LS_consf0FS_MASK          (0x100U)
#define constf0c_CONSF0LS_consf0FS_SHIFT         (8U)
/*! consf0FS - constframe0_FreezeStatus */
#define constf0c_CONSF0LS_consf0FS(x)            (((uint32_t)(((uint32_t)(x)) << constf0c_CONSF0LS_consf0FS_SHIFT)) & constf0c_CONSF0LS_consf0FS_MASK)
/*! @} */

/*! @name CONSF0S - constframe0_Status */
/*! @{ */

#define constf0c_CONSF0S_consf0se_MASK           (0x70000U)
#define constf0c_CONSF0S_consf0se_SHIFT          (16U)
/*! consf0se - constframe0_sel
 *  0b000..constframe0 module is not used
 *  0b001..constframe0 module is used from store9 processing path
 *  0b010..constframe0 module is used from extdst0 processing path
 *  0b011..constframe0 module is used from extdst4 processing path
 *  0b100..constframe0 module is used from extdst1 processing path
 *  0b101..constframe0 module is used from extdst5 processing path
 */
#define constf0c_CONSF0S_consf0se(x)             (((uint32_t)(((uint32_t)(x)) << constf0c_CONSF0S_consf0se_SHIFT)) & constf0c_CONSF0S_consf0se_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group constf0c_Register_Masks */


/*!
 * @}
 */ /* end of group constf0c_Peripheral_Access_Layer */


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


#endif  /* PERI_CONSTF0C_H_ */

