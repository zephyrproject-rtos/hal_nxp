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
**         CMSIS Peripheral Access Layer for IERC_IERB
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
 * @file PERI_IERC_IERB.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IERC_IERB
 *
 * CMSIS Peripheral Access Layer for IERC_IERB
 */

#if !defined(PERI_IERC_IERB_H_)
#define PERI_IERC_IERB_H_                        /**< Symbol preventing repeated inclusion */

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
   -- IERC_IERB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IERC_IERB_Peripheral_Access_Layer IERC_IERB Peripheral Access Layer
 * @{
 */

/** IERC_IERB - Register Layout Typedef */
typedef struct {
  __IO uint32_t F0_EC_CFH_DIDVID;                  /**< Function 0 EC config header device ID and vendor ID register, offset: 0x0 */
  __IO uint32_t F0_EC_CFH_SIDSVID;                 /**< Function 0 EC config header subsystem ID and subsystem vendor ID register, offset: 0x4 */
} IERC_IERB_Type;

/* ----------------------------------------------------------------------------
   -- IERC_IERB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IERC_IERB_Register_Masks IERC_IERB Register Masks
 * @{
 */

/*! @name F0_EC_CFH_DIDVID - Function 0 EC config header device ID and vendor ID register */
/*! @{ */

#define IERC_IERB_F0_EC_CFH_DIDVID_VENDOR_ID_MASK (0xFFFFU)
#define IERC_IERB_F0_EC_CFH_DIDVID_VENDOR_ID_SHIFT (0U)
#define IERC_IERB_F0_EC_CFH_DIDVID_VENDOR_ID(x)  (((uint32_t)(((uint32_t)(x)) << IERC_IERB_F0_EC_CFH_DIDVID_VENDOR_ID_SHIFT)) & IERC_IERB_F0_EC_CFH_DIDVID_VENDOR_ID_MASK)

#define IERC_IERB_F0_EC_CFH_DIDVID_DEVICE_ID_MASK (0xFFFF0000U)
#define IERC_IERB_F0_EC_CFH_DIDVID_DEVICE_ID_SHIFT (16U)
#define IERC_IERB_F0_EC_CFH_DIDVID_DEVICE_ID(x)  (((uint32_t)(((uint32_t)(x)) << IERC_IERB_F0_EC_CFH_DIDVID_DEVICE_ID_SHIFT)) & IERC_IERB_F0_EC_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/*! @name F0_EC_CFH_SIDSVID - Function 0 EC config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define IERC_IERB_F0_EC_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define IERC_IERB_F0_EC_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define IERC_IERB_F0_EC_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << IERC_IERB_F0_EC_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & IERC_IERB_F0_EC_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define IERC_IERB_F0_EC_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define IERC_IERB_F0_EC_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define IERC_IERB_F0_EC_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << IERC_IERB_F0_EC_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & IERC_IERB_F0_EC_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IERC_IERB_Register_Masks */


/*!
 * @}
 */ /* end of group IERC_IERB_Peripheral_Access_Layer */


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


#endif  /* PERI_IERC_IERB_H_ */

