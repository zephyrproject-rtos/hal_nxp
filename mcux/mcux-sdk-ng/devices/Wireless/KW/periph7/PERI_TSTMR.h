/*
** ###################################################################
**     Processors:          KW45B41Z52AFPA
**                          KW45B41Z52AFTA
**                          KW45B41Z53AFPA
**                          KW45B41Z53AFTA
**                          KW45B41Z82AFPA
**                          KW45B41Z82AFTA
**                          KW45B41Z83AFPA
**                          KW45B41Z83AFPA_NBU
**                          KW45B41Z83AFTA
**                          KW45B41Z83AFTA_NBU
**                          KW45Z41052AFPA
**                          KW45Z41052AFTA
**                          KW45Z41053AFPA
**                          KW45Z41053AFTA
**                          KW45Z41082AFPA
**                          KW45Z41082AFTA
**                          KW45Z41083AFPA
**                          KW45Z41083AFTA
**
**     Version:             rev. 1.0, 2020-05-12
**     Build:               b240715
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TSTMR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file TSTMR.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for TSTMR
 *
 * CMSIS Peripheral Access Layer for TSTMR
 */

#if !defined(TSTMR_H_)
#define TSTMR_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW45B41Z52AFPA) || defined(CPU_KW45B41Z52AFTA))
#include "KW45B41Z52_COMMON.h"
#elif (defined(CPU_KW45B41Z53AFPA) || defined(CPU_KW45B41Z53AFTA))
#include "KW45B41Z53_COMMON.h"
#elif (defined(CPU_KW45B41Z82AFPA) || defined(CPU_KW45B41Z82AFTA))
#include "KW45B41Z82_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA) || defined(CPU_KW45B41Z83AFTA))
#include "KW45B41Z83_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA_NBU) || defined(CPU_KW45B41Z83AFTA_NBU))
#include "KW45B41Z83_NBU_COMMON.h"
#elif (defined(CPU_KW45Z41052AFPA) || defined(CPU_KW45Z41052AFTA))
#include "KW45Z41052_COMMON.h"
#elif (defined(CPU_KW45Z41053AFPA) || defined(CPU_KW45Z41053AFTA))
#include "KW45Z41053_COMMON.h"
#elif (defined(CPU_KW45Z41082AFPA) || defined(CPU_KW45Z41082AFTA))
#include "KW45Z41082_COMMON.h"
#elif (defined(CPU_KW45Z41083AFPA) || defined(CPU_KW45Z41083AFTA))
#include "KW45Z41083_COMMON.h"
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
   -- TSTMR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSTMR_Peripheral_Access_Layer TSTMR Peripheral Access Layer
 * @{
 */

/** TSTMR - Register Layout Typedef */
typedef struct {
  __I  uint32_t L;                                 /**< Time Stamp Timer Register Low, offset: 0x0 */
  __I  uint32_t H;                                 /**< Time Stamp Timer Register High, offset: 0x4 */
} TSTMR_Type;

/* ----------------------------------------------------------------------------
   -- TSTMR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSTMR_Register_Masks TSTMR Register Masks
 * @{
 */

/*! @name L - Time Stamp Timer Register Low */
/*! @{ */

#define TSTMR_L_VALUE_MASK                       (0xFFFFFFFFU)
#define TSTMR_L_VALUE_SHIFT                      (0U)
/*! VALUE - Time Stamp Timer Low */
#define TSTMR_L_VALUE(x)                         (((uint32_t)(((uint32_t)(x)) << TSTMR_L_VALUE_SHIFT)) & TSTMR_L_VALUE_MASK)
/*! @} */

/*! @name H - Time Stamp Timer Register High */
/*! @{ */

#define TSTMR_H_VALUE_MASK                       (0xFFFFFFU)
#define TSTMR_H_VALUE_SHIFT                      (0U)
/*! VALUE - Time Stamp Timer High */
#define TSTMR_H_VALUE(x)                         (((uint32_t)(((uint32_t)(x)) << TSTMR_H_VALUE_SHIFT)) & TSTMR_H_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TSTMR_Register_Masks */

/* Extra definition */
#define TSTMR_CLOCK_FREQUENCY_MHZ                (1U)


/*!
 * @}
 */ /* end of group TSTMR_Peripheral_Access_Layer */


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


#endif  /* TSTMR_H_ */

