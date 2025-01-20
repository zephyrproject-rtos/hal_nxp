/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181XVP2B
**                          MIMXRT1182CVP2B
**                          MIMXRT1182XVP2B
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**
**     Version:             rev. 2.0, 2024-01-18
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ANADIG_TEMPSENSOR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**
** ###################################################################
*/

/*!
 * @file ANADIG_TEMPSENSOR.h
 * @version 2.0
 * @date 2024-01-18
 * @brief CMSIS Peripheral Access Layer for ANADIG_TEMPSENSOR
 *
 * CMSIS Peripheral Access Layer for ANADIG_TEMPSENSOR
 */

#if !defined(ANADIG_TEMPSENSOR_H_)
#define ANADIG_TEMPSENSOR_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181XVP2B))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182XVP2B))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- ANADIG_TEMPSENSOR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_TEMPSENSOR_Peripheral_Access_Layer ANADIG_TEMPSENSOR Peripheral Access Layer
 * @{
 */

/** ANADIG_TEMPSENSOR - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[17712];
  __I  uint32_t TEMPSNS_OTP_TRIM_VALUE;            /**< TEMPSNS_OTP_TRIM_VALUE_REGISTER, offset: 0x4530 */
} ANADIG_TEMPSENSOR_Type;

/* ----------------------------------------------------------------------------
   -- ANADIG_TEMPSENSOR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_TEMPSENSOR_Register_Masks ANADIG_TEMPSENSOR Register Masks
 * @{
 */

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


#endif  /* ANADIG_TEMPSENSOR_H_ */

