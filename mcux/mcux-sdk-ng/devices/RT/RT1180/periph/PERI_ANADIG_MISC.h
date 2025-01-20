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
**         CMSIS Peripheral Access Layer for ANADIG_MISC
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
 * @file ANADIG_MISC.h
 * @version 2.0
 * @date 2024-01-18
 * @brief CMSIS Peripheral Access Layer for ANADIG_MISC
 *
 * CMSIS Peripheral Access Layer for ANADIG_MISC
 */

#if !defined(ANADIG_MISC_H_)
#define ANADIG_MISC_H_                           /**< Symbol preventing repeated inclusion */

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
   -- ANADIG_MISC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_MISC_Peripheral_Access_Layer ANADIG_MISC Peripheral Access Layer
 * @{
 */

/** ANADIG_MISC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[18432];
  __I  uint32_t MISC_DIFPROG;                      /**< Chip Silicon Version Register, offset: 0x4800 */
} ANADIG_MISC_Type;

/* ----------------------------------------------------------------------------
   -- ANADIG_MISC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_MISC_Register_Masks ANADIG_MISC Register Masks
 * @{
 */

/*! @name MISC_DIFPROG - Chip Silicon Version Register */
/*! @{ */

#define ANADIG_MISC_MISC_DIFPROG_CHIPID_MASK     (0xFFFFFFFFU)
#define ANADIG_MISC_MISC_DIFPROG_CHIPID_SHIFT    (0U)
/*! CHIPID - Chip ID */
#define ANADIG_MISC_MISC_DIFPROG_CHIPID(x)       (((uint32_t)(((uint32_t)(x)) << ANADIG_MISC_MISC_DIFPROG_CHIPID_SHIFT)) & ANADIG_MISC_MISC_DIFPROG_CHIPID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANADIG_MISC_Register_Masks */


/*!
 * @}
 */ /* end of group ANADIG_MISC_Peripheral_Access_Layer */


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


#endif  /* ANADIG_MISC_H_ */

