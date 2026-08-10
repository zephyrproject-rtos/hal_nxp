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
**         CMSIS Peripheral Access Layer for fetchl1c
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
 * @file PERI_fetchl1c.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for fetchl1c
 *
 * CMSIS Peripheral Access Layer for fetchl1c
 */

#if !defined(PERI_FETCHL1C_H_)
#define PERI_FETCHL1C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchl1c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl1c_Peripheral_Access_Layer fetchl1c Peripheral Access Layer
 * @{
 */

/** fetchl1c - Register Layout Typedef */
typedef struct {
  __O  uint32_t FETLA1LU;                          /**< fetchlayer1_LockUnlock, offset: 0x0 */
  __I  uint32_t FETLA1LS;                          /**< fetchlayer1_LockStatus, offset: 0x4 */
  __I  uint32_t FETLA1S;                           /**< fetchlayer1_Status, offset: 0x8 */
} fetchl1c_Type;

/* ----------------------------------------------------------------------------
   -- fetchl1c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl1c_Register_Masks fetchl1c Register Masks
 * @{
 */

/*! @name FETLA1LU - fetchlayer1_LockUnlock */
/*! @{ */

#define fetchl1c_FETLA1LU_fetlayLU_MASK          (0xFFFFFFFFU)
#define fetchl1c_FETLA1LU_fetlayLU_SHIFT         (0U)
/*! fetlayLU - fetchlayer1_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define fetchl1c_FETLA1LU_fetlayLU(x)            (((uint32_t)(((uint32_t)(x)) << fetchl1c_FETLA1LU_fetlayLU_SHIFT)) & fetchl1c_FETLA1LU_fetlayLU_MASK)
/*! @} */

/*! @name FETLA1LS - fetchlayer1_LockStatus */
/*! @{ */

#define fetchl1c_FETLA1LS_fetlayLS_MASK          (0x1U)
#define fetchl1c_FETLA1LS_fetlayLS_SHIFT         (0U)
/*! fetlayLS - fetchlayer1_LockStatus */
#define fetchl1c_FETLA1LS_fetlayLS(x)            (((uint32_t)(((uint32_t)(x)) << fetchl1c_FETLA1LS_fetlayLS_SHIFT)) & fetchl1c_FETLA1LS_fetlayLS_MASK)

#define fetchl1c_FETLA1LS_fetlayPS_MASK          (0x10U)
#define fetchl1c_FETLA1LS_fetlayPS_SHIFT         (4U)
/*! fetlayPS - fetchlayer1_PrivilegeStatus */
#define fetchl1c_FETLA1LS_fetlayPS(x)            (((uint32_t)(((uint32_t)(x)) << fetchl1c_FETLA1LS_fetlayPS_SHIFT)) & fetchl1c_FETLA1LS_fetlayPS_MASK)

#define fetchl1c_FETLA1LS_fetlayFS_MASK          (0x100U)
#define fetchl1c_FETLA1LS_fetlayFS_SHIFT         (8U)
/*! fetlayFS - fetchlayer1_FreezeStatus */
#define fetchl1c_FETLA1LS_fetlayFS(x)            (((uint32_t)(((uint32_t)(x)) << fetchl1c_FETLA1LS_fetlayFS_SHIFT)) & fetchl1c_FETLA1LS_fetlayFS_MASK)
/*! @} */

/*! @name FETLA1S - fetchlayer1_Status */
/*! @{ */

#define fetchl1c_FETLA1S_fetlaysl_MASK           (0x70000U)
#define fetchl1c_FETLA1S_fetlaysl_SHIFT          (16U)
/*! fetlaysl - fetchlayer1_sel
 *  0b000..fetchlayer1 module is not used
 *  0b001..fetchlayer1 module is used from store9 processing path
 *  0b010..fetchlayer1 module is used from extdst0 processing path
 *  0b011..fetchlayer1 module is used from extdst4 processing path
 *  0b100..fetchlayer1 module is used from extdst1 processing path
 *  0b101..fetchlayer1 module is used from extdst5 processing path
 */
#define fetchl1c_FETLA1S_fetlaysl(x)             (((uint32_t)(((uint32_t)(x)) << fetchl1c_FETLA1S_fetlaysl_SHIFT)) & fetchl1c_FETLA1S_fetlaysl_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchl1c_Register_Masks */


/*!
 * @}
 */ /* end of group fetchl1c_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHL1C_H_ */

