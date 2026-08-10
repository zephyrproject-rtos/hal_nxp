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
**         CMSIS Peripheral Access Layer for DOORBELLS
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
 * @file PERI_DOORBELLS.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for DOORBELLS
 *
 * CMSIS Peripheral Access Layer for DOORBELLS
 */

#if !defined(PERI_DOORBELLS_H_)
#define PERI_DOORBELLS_H_                        /**< Symbol preventing repeated inclusion */

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
   -- DOORBELLS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DOORBELLS_Peripheral_Access_Layer DOORBELLS Peripheral Access Layer
 * @{
 */

/** DOORBELLS - Size of Registers Arrays */
#define DOORBELLS_DOORBELL_COUNT                  64u

/** DOORBELLS - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10000 */
    __O  uint32_t DOORBELL;                          /**< DOORBELL, array offset: 0x0, array step: 0x10000 */
         uint8_t RESERVED_0[65532];
  } DOORBELL[DOORBELLS_DOORBELL_COUNT];
} DOORBELLS_Type;

/* ----------------------------------------------------------------------------
   -- DOORBELLS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DOORBELLS_Register_Masks DOORBELLS Register Masks
 * @{
 */

/*! @name DOORBELL - DOORBELL */
/*! @{ */

#define DOORBELLS_DOORBELL_MASK_MASK             (0xFFFFFFFFU)
#define DOORBELLS_DOORBELL_MASK_SHIFT            (0U)
/*! MASK - MASK */
#define DOORBELLS_DOORBELL_MASK(x)               (((uint32_t)(((uint32_t)(x)) << DOORBELLS_DOORBELL_MASK_SHIFT)) & DOORBELLS_DOORBELL_MASK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DOORBELLS_Register_Masks */


/*!
 * @}
 */ /* end of group DOORBELLS_Peripheral_Access_Layer */


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


#endif  /* PERI_DOORBELLS_H_ */

