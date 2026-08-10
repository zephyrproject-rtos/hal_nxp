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
**         CMSIS Peripheral Access Layer for constf5c
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
 * @file PERI_constf5c.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for constf5c
 *
 * CMSIS Peripheral Access Layer for constf5c
 */

#if !defined(PERI_CONSTF5C_H_)
#define PERI_CONSTF5C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- constf5c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf5c_Peripheral_Access_Layer constf5c Peripheral Access Layer
 * @{
 */

/** constf5c - Register Layout Typedef */
typedef struct {
  __O  uint32_t CONSF5LU;                          /**< constframe5_LockUnlock, offset: 0x0 */
  __I  uint32_t CONSF5LS;                          /**< constframe5_LockStatus, offset: 0x4 */
  __I  uint32_t CONSF5S;                           /**< constframe5_Status, offset: 0x8 */
} constf5c_Type;

/* ----------------------------------------------------------------------------
   -- constf5c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf5c_Register_Masks constf5c Register Masks
 * @{
 */

/*! @name CONSF5LU - constframe5_LockUnlock */
/*! @{ */

#define constf5c_CONSF5LU_consf5LU_MASK          (0xFFFFFFFFU)
#define constf5c_CONSF5LU_consf5LU_SHIFT         (0U)
/*! consf5LU - constframe5_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define constf5c_CONSF5LU_consf5LU(x)            (((uint32_t)(((uint32_t)(x)) << constf5c_CONSF5LU_consf5LU_SHIFT)) & constf5c_CONSF5LU_consf5LU_MASK)
/*! @} */

/*! @name CONSF5LS - constframe5_LockStatus */
/*! @{ */

#define constf5c_CONSF5LS_consf5LS_MASK          (0x1U)
#define constf5c_CONSF5LS_consf5LS_SHIFT         (0U)
/*! consf5LS - constframe5_LockStatus */
#define constf5c_CONSF5LS_consf5LS(x)            (((uint32_t)(((uint32_t)(x)) << constf5c_CONSF5LS_consf5LS_SHIFT)) & constf5c_CONSF5LS_consf5LS_MASK)

#define constf5c_CONSF5LS_consf5PS_MASK          (0x10U)
#define constf5c_CONSF5LS_consf5PS_SHIFT         (4U)
/*! consf5PS - constframe5_PrivilegeStatus */
#define constf5c_CONSF5LS_consf5PS(x)            (((uint32_t)(((uint32_t)(x)) << constf5c_CONSF5LS_consf5PS_SHIFT)) & constf5c_CONSF5LS_consf5PS_MASK)

#define constf5c_CONSF5LS_consf5FS_MASK          (0x100U)
#define constf5c_CONSF5LS_consf5FS_SHIFT         (8U)
/*! consf5FS - constframe5_FreezeStatus */
#define constf5c_CONSF5LS_consf5FS(x)            (((uint32_t)(((uint32_t)(x)) << constf5c_CONSF5LS_consf5FS_SHIFT)) & constf5c_CONSF5LS_consf5FS_MASK)
/*! @} */

/*! @name CONSF5S - constframe5_Status */
/*! @{ */

#define constf5c_CONSF5S_consf5se_MASK           (0x70000U)
#define constf5c_CONSF5S_consf5se_SHIFT          (16U)
/*! consf5se - constframe5_sel
 *  0b000..constframe5 module is not used
 *  0b001..constframe5 module is used from store9 processing path
 *  0b010..constframe5 module is used from extdst0 processing path
 *  0b011..constframe5 module is used from extdst4 processing path
 *  0b100..constframe5 module is used from extdst1 processing path
 *  0b101..constframe5 module is used from extdst5 processing path
 */
#define constf5c_CONSF5S_consf5se(x)             (((uint32_t)(((uint32_t)(x)) << constf5c_CONSF5S_consf5se_SHIFT)) & constf5c_CONSF5S_consf5se_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group constf5c_Register_Masks */


/*!
 * @}
 */ /* end of group constf5c_Peripheral_Access_Layer */


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


#endif  /* PERI_CONSTF5C_H_ */

