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
**         CMSIS Peripheral Access Layer for CAMERA_DSI_STREAM_CSR
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
 * @file CAMERA_DSI_STREAM_CSR.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for CAMERA_DSI_STREAM_CSR
 *
 * CMSIS Peripheral Access Layer for CAMERA_DSI_STREAM_CSR
 */

#if !defined(CAMERA_DSI_STREAM_CSR_H_)
#define CAMERA_DSI_STREAM_CSR_H_                 /**< Symbol preventing repeated inclusion */

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
   -- CAMERA_DSI_STREAM_CSR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_DSI_STREAM_CSR_Peripheral_Access_Layer CAMERA_DSI_STREAM_CSR Peripheral Access Layer
 * @{
 */

/** CAMERA_DSI_STREAM_CSR - Register Layout Typedef */
typedef struct {
  __IO uint32_t DSI_HOST_CONFIGURATION;            /**< DSI Host Configuration, offset: 0x0 */
  __IO uint32_t DSI_PARITY_ERROR_STATUS;           /**< DSI Parity Error Status, offset: 0x4 */
  __IO uint32_t DSI_PARITY_ERROR_THRESHOLD;        /**< DSI Parity Error Threshold, offset: 0x8 */
} CAMERA_DSI_STREAM_CSR_Type;

/* ----------------------------------------------------------------------------
   -- CAMERA_DSI_STREAM_CSR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_DSI_STREAM_CSR_Register_Masks CAMERA_DSI_STREAM_CSR Register Masks
 * @{
 */

/*! @name DSI_HOST_CONFIGURATION - DSI Host Configuration */
/*! @{ */

#define CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format_MASK (0x7U)
#define CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format_SHIFT (0U)
/*! Pixel_link_format - Configures the pixel link format transported on the pixel link
 *  0b000..RGB 24-bit
 *  0b001..RGB 30-bit
 *  0b010..RGB 18-bit
 *  0b011..RGB 16-bit
 *  0b100..20-bit YCbCr, 4:2:2 format
 *  0b101..16-bit YCbCr, 4:2:2 format
 */
#define CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format_SHIFT)) & CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_Pixel_link_format_MASK)

#define CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_shutdown_MASK (0x10U)
#define CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_shutdown_SHIFT (4U)
/*! shutdown - That bit is directly connected to the dpishutdn input of the CSI2 host controller.
 *    It's used to shutdown the distant DSI peripheral.
 *  0b0..'1' to '0': send a turn on peripheral command (short packet - 0x32)
 *  0b1..'0' to '1': send a shut down peripheral command (short packet - 0x22)
 */
#define CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_shutdown(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_shutdown_SHIFT)) & CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_shutdown_MASK)

#define CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_colormode_MASK (0x20U)
#define CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_colormode_SHIFT (5U)
/*! colormode - That bit is directly connected to the dpicolorm input of the CSI2 host controller.
 *    It's used to switch between normal color and reduced color mode.
 *  0b0..'1' to '0': Send a Color Mode Off Command (Short packet - 0x02) switches a Video Mode display module from
 *       low-color mode to normal display operation.
 *  0b1..'0' to '1': Send a Color Mode On Command (Short packet - 0x12)switches a Video Mode display module to a low-color mode for power saving.
 */
#define CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_colormode(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_colormode_SHIFT)) & CAMERA_DSI_STREAM_CSR_DSI_HOST_CONFIGURATION_colormode_MASK)
/*! @} */

/*! @name DSI_PARITY_ERROR_STATUS - DSI Parity Error Status */
/*! @{ */

#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_STATUS_Parity0_error_MASK (0x1U)
#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_STATUS_Parity0_error_SHIFT (0U)
/*! Parity0_error - Parity 0 error status
 *  0b1..The number of detected errors on parity 0 is equal to or above the DSI_PARITY_ERROR_THRESHOLD[parity0_error_max]
 *  0b0..The number of detected errors on parity 0 is below the DSI_PARITY_ERROR_THRESHOLD[parity0_error_max]
 */
#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_STATUS_Parity0_error(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_STATUS_Parity0_error_SHIFT)) & CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_STATUS_Parity0_error_MASK)

#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_STATUS_Parity123_error_MASK (0x2U)
#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_STATUS_Parity123_error_SHIFT (1U)
/*! Parity123_error - Parity 123 error status
 *  0b0..The number of detected errors on parity 123 is below the DSI_PARITY_ERROR_THRESHOLD[parity123_error_max]
 *  0b1..The number of detected errors on parity 123 has reached the DSI_PARITY_ERROR_THRESHOLD[parity123_error_max]
 */
#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_STATUS_Parity123_error(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_STATUS_Parity123_error_SHIFT)) & CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_STATUS_Parity123_error_MASK)
/*! @} */

/*! @name DSI_PARITY_ERROR_THRESHOLD - DSI Parity Error Threshold */
/*! @{ */

#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_THRESHOLD_parity0_error_max_MASK (0x3FFU)
#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_THRESHOLD_parity0_error_max_SHIFT (0U)
/*! parity0_error_max - Max parity 0 threshold
 *  0b0000000000..The error check for parity 0 is disabled.
 *  0b0000000001-0b1111111111..Maximum number of parity 0 errors.
 */
#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_THRESHOLD_parity0_error_max(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_THRESHOLD_parity0_error_max_SHIFT)) & CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_THRESHOLD_parity0_error_max_MASK)

#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_THRESHOLD_parity123_error_max_MASK (0x3FF0000U)
#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_THRESHOLD_parity123_error_max_SHIFT (16U)
/*! parity123_error_max - Max parity 123 threshold
 *  0b0000000001-0b1111111111..Maximum number of parity 123 errors.
 *  0b0000000000..The error check for parity 123 is disabled.
 */
#define CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_THRESHOLD_parity123_error_max(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_THRESHOLD_parity123_error_max_SHIFT)) & CAMERA_DSI_STREAM_CSR_DSI_PARITY_ERROR_THRESHOLD_parity123_error_max_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAMERA_DSI_STREAM_CSR_Register_Masks */


/*!
 * @}
 */ /* end of group CAMERA_DSI_STREAM_CSR_Peripheral_Access_Layer */


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


#endif  /* CAMERA_DSI_STREAM_CSR_H_ */

