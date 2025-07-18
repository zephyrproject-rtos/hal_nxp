/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OCOTP_FSB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OCOTP_FSB.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OCOTP_FSB
 *
 * CMSIS Peripheral Access Layer for OCOTP_FSB
 */

#if !defined(PERI_OCOTP_FSB_H_)
#define PERI_OCOTP_FSB_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
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
   -- OCOTP_FSB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_FSB_Peripheral_Access_Layer OCOTP_FSB Peripheral Access Layer
 * @{
 */

/** OCOTP_FSB - Size of Registers Arrays */
#define OCOTP_FSB_OTP_SHADOW_PARTA_COUNT          52u
#define OCOTP_FSB_OTP_SHADOW_PARTB_COUNT          200u

/** OCOTP_FSB - Register Layout Typedef */
typedef struct {
  __IO uint32_t OTP_SHADOW_PARTA[OCOTP_FSB_OTP_SHADOW_PARTA_COUNT]; /**< OTP shadow register, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[1040];
  __IO uint32_t OTP_SHADOW_PARTB[OCOTP_FSB_OTP_SHADOW_PARTB_COUNT]; /**< OTP shadow register, array offset: 0x4E0, array step: 0x4 */
} OCOTP_FSB_Type;

/* ----------------------------------------------------------------------------
   -- OCOTP_FSB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_FSB_Register_Masks OCOTP_FSB Register Masks
 * @{
 */

/*! @name OTP_SHADOW_PARTA - OTP shadow register */
/*! @{ */

#define OCOTP_FSB_OTP_SHADOW_PARTA_SHADOW_MASK   (0xFFFFFFFFU)
#define OCOTP_FSB_OTP_SHADOW_PARTA_SHADOW_SHIFT  (0U)
/*! SHADOW - OTP shadow register, fsb have read access of shadow 0-51 (offset should be 0*4-51*4) */
#define OCOTP_FSB_OTP_SHADOW_PARTA_SHADOW(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_FSB_OTP_SHADOW_PARTA_SHADOW_SHIFT)) & OCOTP_FSB_OTP_SHADOW_PARTA_SHADOW_MASK)
/*! @} */

/*! @name OTP_SHADOW_PARTB - OTP shadow register */
/*! @{ */

#define OCOTP_FSB_OTP_SHADOW_PARTB_SHADOW_MASK   (0xFFFFFFFFU)
#define OCOTP_FSB_OTP_SHADOW_PARTB_SHADOW_SHIFT  (0U)
/*! SHADOW - OTP shadow register, fsb have read access of shadow 312-511 (offset should be 312*4-511*4) */
#define OCOTP_FSB_OTP_SHADOW_PARTB_SHADOW(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_FSB_OTP_SHADOW_PARTB_SHADOW_SHIFT)) & OCOTP_FSB_OTP_SHADOW_PARTB_SHADOW_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OCOTP_FSB_Register_Masks */


/*!
 * @}
 */ /* end of group OCOTP_FSB_Peripheral_Access_Layer */


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


#endif  /* PERI_OCOTP_FSB_H_ */

