/*
** ###################################################################
**     Processors:          MIMXRT1165CVM5A_cm4
**                          MIMXRT1165CVM5A_cm7
**                          MIMXRT1165DVM6A_cm4
**                          MIMXRT1165DVM6A_cm7
**                          MIMXRT1165XVM5A_cm4
**                          MIMXRT1165XVM5A_cm7
**                          MIMXRT1166CVM5A_cm4
**                          MIMXRT1166CVM5A_cm7
**                          MIMXRT1166DVM6A_cm4
**                          MIMXRT1166DVM6A_cm7
**                          MIMXRT1166XVM5A_cm4
**                          MIMXRT1166XVM5A_cm7
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ANADIG_TEMPSENSOR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-29)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ANADIG_TEMPSENSOR.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ANADIG_TEMPSENSOR
 *
 * CMSIS Peripheral Access Layer for ANADIG_TEMPSENSOR
 */

#if !defined(PERI_ANADIG_TEMPSENSOR_H_)
#define PERI_ANADIG_TEMPSENSOR_H_                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1165CVM5A_cm4) || defined(CPU_MIMXRT1165DVM6A_cm4) || defined(CPU_MIMXRT1165XVM5A_cm4))
#include "MIMXRT1165_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1165CVM5A_cm7) || defined(CPU_MIMXRT1165DVM6A_cm7) || defined(CPU_MIMXRT1165XVM5A_cm7))
#include "MIMXRT1165_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm4) || defined(CPU_MIMXRT1166DVM6A_cm4) || defined(CPU_MIMXRT1166XVM5A_cm4))
#include "MIMXRT1166_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm7) || defined(CPU_MIMXRT1166DVM6A_cm7) || defined(CPU_MIMXRT1166XVM5A_cm7))
#include "MIMXRT1166_cm7_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ANADIG_TEMPSENSOR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_TEMPSENSOR_Peripheral_Access_Layer ANADIG_TEMPSENSOR Peripheral Access Layer
 * @{
 */

/** ANADIG_TEMPSENSOR - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1024];
  __IO uint32_t TEMPSENSOR;                        /**< Tempsensor Register, offset: 0x400 */
       uint8_t RESERVED_1[44];
  __I  uint32_t TEMPSNS_OTP_TRIM_VALUE;            /**< TEMPSNS_OTP_TRIM_VALUE_REGISTER, offset: 0x430 */
} ANADIG_TEMPSENSOR_Type;

/* ----------------------------------------------------------------------------
   -- ANADIG_TEMPSENSOR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_TEMPSENSOR_Register_Masks ANADIG_TEMPSENSOR Register Masks
 * @{
 */

/*! @name TEMPSENSOR - Tempsensor Register */
/*! @{ */

#define ANADIG_TEMPSENSOR_TEMPSENSOR_TEMPSNS_AI_TOGGLE_MASK (0x8000U)
#define ANADIG_TEMPSENSOR_TEMPSENSOR_TEMPSNS_AI_TOGGLE_SHIFT (15U)
/*! TEMPSNS_AI_TOGGLE - AI toggle */
#define ANADIG_TEMPSENSOR_TEMPSENSOR_TEMPSNS_AI_TOGGLE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_TEMPSENSOR_TEMPSENSOR_TEMPSNS_AI_TOGGLE_SHIFT)) & ANADIG_TEMPSENSOR_TEMPSENSOR_TEMPSNS_AI_TOGGLE_MASK)

#define ANADIG_TEMPSENSOR_TEMPSENSOR_TEMPSNS_AI_BUSY_MASK (0x10000U)
#define ANADIG_TEMPSENSOR_TEMPSENSOR_TEMPSNS_AI_BUSY_SHIFT (16U)
/*! TEMPSNS_AI_BUSY - AI Busy monitor */
#define ANADIG_TEMPSENSOR_TEMPSENSOR_TEMPSNS_AI_BUSY(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_TEMPSENSOR_TEMPSENSOR_TEMPSNS_AI_BUSY_SHIFT)) & ANADIG_TEMPSENSOR_TEMPSENSOR_TEMPSNS_AI_BUSY_MASK)
/*! @} */

/*! @name TEMPSNS_OTP_TRIM_VALUE - TEMPSNS_OTP_TRIM_VALUE_REGISTER */
/*! @{ */

#define ANADIG_TEMPSENSOR_TEMPSNS_OTP_TRIM_VALUE_TEMPSNS_TEMP_VAL_MASK (0x3FFC00U)
#define ANADIG_TEMPSENSOR_TEMPSNS_OTP_TRIM_VALUE_TEMPSNS_TEMP_VAL_SHIFT (10U)
/*! TEMPSNS_TEMP_VAL - Temperature Value at 25C */
#define ANADIG_TEMPSENSOR_TEMPSNS_OTP_TRIM_VALUE_TEMPSNS_TEMP_VAL(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_TEMPSENSOR_TEMPSNS_OTP_TRIM_VALUE_TEMPSNS_TEMP_VAL_SHIFT)) & ANADIG_TEMPSENSOR_TEMPSNS_OTP_TRIM_VALUE_TEMPSNS_TEMP_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANADIG_TEMPSENSOR_Register_Masks */


/*!
 * @}
 */ /* end of group ANADIG_TEMPSENSOR_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_ANADIG_TEMPSENSOR_H_ */

