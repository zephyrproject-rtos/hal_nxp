/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CAMERA_DSI_PIXEL_FORMATTING
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file CAMERA_DSI_PIXEL_FORMATTING.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for CAMERA_DSI_PIXEL_FORMATTING
 *
 * CMSIS Peripheral Access Layer for CAMERA_DSI_PIXEL_FORMATTING
 */

#if !defined(CAMERA_DSI_PIXEL_FORMATTING_H_)
#define CAMERA_DSI_PIXEL_FORMATTING_H_           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- CAMERA_DSI_PIXEL_FORMATTING Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_DSI_PIXEL_FORMATTING_Peripheral_Access_Layer CAMERA_DSI_PIXEL_FORMATTING Peripheral Access Layer
 * @{
 */

/** CAMERA_DSI_PIXEL_FORMATTING - Register Layout Typedef */
typedef struct {
  __IO uint32_t DSI_HOST_CONFIGURATION;            /**< DSI Host Configuration, offset: 0x0 */
  __IO uint32_t DSI_PARITY_ERROR_STATUS;           /**< DSI Parity Error Status, offset: 0x4 */
  __IO uint32_t DSI_PARITY_ERR_THRESH;             /**< DSI Parity Error Threshold, offset: 0x8 */
} CAMERA_DSI_PIXEL_FORMATTING_Type;

/* ----------------------------------------------------------------------------
   -- CAMERA_DSI_PIXEL_FORMATTING Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_DSI_PIXEL_FORMATTING_Register_Masks CAMERA_DSI_PIXEL_FORMATTING Register Masks
 * @{
 */

/*! @name DSI_HOST_CONFIGURATION - DSI Host Configuration */
/*! @{ */

#define CAMERA_DSI_PIXEL_FORMATTING_DSI_HOST_CONFIGURATION_PIXEL_LINK_FORMAT_MASK (0x7U)
#define CAMERA_DSI_PIXEL_FORMATTING_DSI_HOST_CONFIGURATION_PIXEL_LINK_FORMAT_SHIFT (0U)
/*! PIXEL_LINK_FORMAT - Defines the pixel format transported on the pixel link
 *  0b000..RGB 24-bit
 *  0b001..RGB 20-bit
 *  0b010..RGB 18-bit
 *  0b011..RGB 16-bit
 *  0b100..20-bit YCbCr, 4:2:2 format
 *  0b101..16-bit YCbCr, 4:2:2 format
 */
#define CAMERA_DSI_PIXEL_FORMATTING_DSI_HOST_CONFIGURATION_PIXEL_LINK_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_PIXEL_FORMATTING_DSI_HOST_CONFIGURATION_PIXEL_LINK_FORMAT_SHIFT)) & CAMERA_DSI_PIXEL_FORMATTING_DSI_HOST_CONFIGURATION_PIXEL_LINK_FORMAT_MASK)
/*! @} */

/*! @name DSI_PARITY_ERROR_STATUS - DSI Parity Error Status */
/*! @{ */

#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERROR_STATUS_PARITY0_ERROR_MASK (0x1U)
#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERROR_STATUS_PARITY0_ERROR_SHIFT (0U)
/*! PARITY0_ERROR - Detected parity[0] error has reached the PARITY0_ERROR_MAX
 *  0b0..Number of detected error on parity[0] is below PARITY0_ERR_MAX
 *  0b1..Number of detected error on parity[0] is above or equal to PARITY0_ERR_MAX
 */
#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERROR_STATUS_PARITY0_ERROR(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERROR_STATUS_PARITY0_ERROR_SHIFT)) & CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERROR_STATUS_PARITY0_ERROR_MASK)

#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERROR_STATUS_PARITY123_ERROR_MASK (0x2U)
#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERROR_STATUS_PARITY123_ERROR_SHIFT (1U)
/*! PARITY123_ERROR - Detected parity[3:1] error has reached the PARITY123_ERROR_MAX
 *  0b0..Number of detected error on parity[3:1] is below PARITY123_ERROR_MAX
 *  0b1..Number of detected error on parity[3:1] is above or equal to PARITY123_ERROR_MAX
 */
#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERROR_STATUS_PARITY123_ERROR(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERROR_STATUS_PARITY123_ERROR_SHIFT)) & CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERROR_STATUS_PARITY123_ERROR_MASK)
/*! @} */

/*! @name DSI_PARITY_ERR_THRESH - DSI Parity Error Threshold */
/*! @{ */

#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERR_THRESH_PARITY0_ERR_MAX_MASK (0x3FFU)
#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERR_THRESH_PARITY0_ERR_MAX_SHIFT (0U)
/*! PARITY0_ERR_MAX - Parity0_error max threshold
 *  0b0000000000-0b0000111111..Max parity error threshold
 */
#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERR_THRESH_PARITY0_ERR_MAX(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERR_THRESH_PARITY0_ERR_MAX_SHIFT)) & CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERR_THRESH_PARITY0_ERR_MAX_MASK)

#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERR_THRESH_PARITY123_ERR_MAX_MASK (0x3FF0000U)
#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERR_THRESH_PARITY123_ERR_MAX_SHIFT (16U)
/*! PARITY123_ERR_MAX - Parity123_error max threshold
 *  0b0000000000-0b0000111111..Max parity error threshold
 */
#define CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERR_THRESH_PARITY123_ERR_MAX(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERR_THRESH_PARITY123_ERR_MAX_SHIFT)) & CAMERA_DSI_PIXEL_FORMATTING_DSI_PARITY_ERR_THRESH_PARITY123_ERR_MAX_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAMERA_DSI_PIXEL_FORMATTING_Register_Masks */


/*!
 * @}
 */ /* end of group CAMERA_DSI_PIXEL_FORMATTING_Peripheral_Access_Layer */


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


#endif  /* CAMERA_DSI_PIXEL_FORMATTING_H_ */

