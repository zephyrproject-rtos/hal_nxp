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
**         CMSIS Peripheral Access Layer for constf1c
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
 * @file PERI_constf1c.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for constf1c
 *
 * CMSIS Peripheral Access Layer for constf1c
 */

#if !defined(PERI_CONSTF1C_H_)
#define PERI_CONSTF1C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- constf1c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf1c_Peripheral_Access_Layer constf1c Peripheral Access Layer
 * @{
 */

/** constf1c - Register Layout Typedef */
typedef struct {
  __O  uint32_t CONSF1LU;                          /**< constframe1_LockUnlock, offset: 0x0 */
  __I  uint32_t CONSF1LS;                          /**< constframe1_LockStatus, offset: 0x4 */
  __I  uint32_t CONSF1S;                           /**< constframe1_Status, offset: 0x8 */
} constf1c_Type;

/* ----------------------------------------------------------------------------
   -- constf1c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf1c_Register_Masks constf1c Register Masks
 * @{
 */

/*! @name CONSF1LU - constframe1_LockUnlock */
/*! @{ */

#define constf1c_CONSF1LU_consf1LU_MASK          (0xFFFFFFFFU)
#define constf1c_CONSF1LU_consf1LU_SHIFT         (0U)
/*! consf1LU - constframe1_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define constf1c_CONSF1LU_consf1LU(x)            (((uint32_t)(((uint32_t)(x)) << constf1c_CONSF1LU_consf1LU_SHIFT)) & constf1c_CONSF1LU_consf1LU_MASK)
/*! @} */

/*! @name CONSF1LS - constframe1_LockStatus */
/*! @{ */

#define constf1c_CONSF1LS_consf1LS_MASK          (0x1U)
#define constf1c_CONSF1LS_consf1LS_SHIFT         (0U)
/*! consf1LS - constframe1_LockStatus */
#define constf1c_CONSF1LS_consf1LS(x)            (((uint32_t)(((uint32_t)(x)) << constf1c_CONSF1LS_consf1LS_SHIFT)) & constf1c_CONSF1LS_consf1LS_MASK)

#define constf1c_CONSF1LS_consf1PS_MASK          (0x10U)
#define constf1c_CONSF1LS_consf1PS_SHIFT         (4U)
/*! consf1PS - constframe1_PrivilegeStatus */
#define constf1c_CONSF1LS_consf1PS(x)            (((uint32_t)(((uint32_t)(x)) << constf1c_CONSF1LS_consf1PS_SHIFT)) & constf1c_CONSF1LS_consf1PS_MASK)

#define constf1c_CONSF1LS_consf1FS_MASK          (0x100U)
#define constf1c_CONSF1LS_consf1FS_SHIFT         (8U)
/*! consf1FS - constframe1_FreezeStatus */
#define constf1c_CONSF1LS_consf1FS(x)            (((uint32_t)(((uint32_t)(x)) << constf1c_CONSF1LS_consf1FS_SHIFT)) & constf1c_CONSF1LS_consf1FS_MASK)
/*! @} */

/*! @name CONSF1S - constframe1_Status */
/*! @{ */

#define constf1c_CONSF1S_consf1se_MASK           (0x70000U)
#define constf1c_CONSF1S_consf1se_SHIFT          (16U)
/*! consf1se - constframe1_sel
 *  0b000..constframe1 module is not used
 *  0b001..constframe1 module is used from store9 processing path
 *  0b010..constframe1 module is used from extdst0 processing path
 *  0b011..constframe1 module is used from extdst4 processing path
 *  0b100..constframe1 module is used from extdst1 processing path
 *  0b101..constframe1 module is used from extdst5 processing path
 */
#define constf1c_CONSF1S_consf1se(x)             (((uint32_t)(((uint32_t)(x)) << constf1c_CONSF1S_consf1se_SHIFT)) & constf1c_CONSF1S_consf1se_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group constf1c_Register_Masks */


/*!
 * @}
 */ /* end of group constf1c_Peripheral_Access_Layer */


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


#endif  /* PERI_CONSTF1C_H_ */

