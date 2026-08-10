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
**         CMSIS Peripheral Access Layer for USER
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
 * @file PERI_USER.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for USER
 *
 * CMSIS Peripheral Access Layer for USER
 */

#if !defined(PERI_USER_H_)
#define PERI_USER_H_                             /**< Symbol preventing repeated inclusion */

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
   -- USER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USER_Peripheral_Access_Layer USER Peripheral Access Layer
 * @{
 */

/** USER - Register Layout Typedef */
typedef struct {
  __I  uint32_t LATEST_FLUSH;                      /**< LATEST_FLUSH, offset: 0x0 */
} USER_Type;

/* ----------------------------------------------------------------------------
   -- USER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USER_Register_Masks USER Register Masks
 * @{
 */

/*! @name LATEST_FLUSH - LATEST_FLUSH */
/*! @{ */

#define USER_LATEST_FLUSH_flush_id_MASK          (0xFFFFFFU)
#define USER_LATEST_FLUSH_flush_id_SHIFT         (0U)
/*! flush_id - flush_id */
#define USER_LATEST_FLUSH_flush_id(x)            (((uint32_t)(((uint32_t)(x)) << USER_LATEST_FLUSH_flush_id_SHIFT)) & USER_LATEST_FLUSH_flush_id_MASK)

#define USER_LATEST_FLUSH_reserved_word0_bit24_width7_MASK (0x7F000000U)
#define USER_LATEST_FLUSH_reserved_word0_bit24_width7_SHIFT (24U)
/*! reserved_word0_bit24_width7 - reserved_word0_bit24_width7 */
#define USER_LATEST_FLUSH_reserved_word0_bit24_width7(x) (((uint32_t)(((uint32_t)(x)) << USER_LATEST_FLUSH_reserved_word0_bit24_width7_SHIFT)) & USER_LATEST_FLUSH_reserved_word0_bit24_width7_MASK)

#define USER_LATEST_FLUSH_ACTIVE_MASK            (0x80000000U)
#define USER_LATEST_FLUSH_ACTIVE_SHIFT           (31U)
/*! ACTIVE - ACTIVE */
#define USER_LATEST_FLUSH_ACTIVE(x)              (((uint32_t)(((uint32_t)(x)) << USER_LATEST_FLUSH_ACTIVE_SHIFT)) & USER_LATEST_FLUSH_ACTIVE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USER_Register_Masks */


/*!
 * @}
 */ /* end of group USER_Peripheral_Access_Layer */


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


#endif  /* PERI_USER_H_ */

