/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DSI2_HOST_DBI_IF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DSI2_HOST_DBI_IF.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for DSI2_HOST_DBI_IF
 *
 * CMSIS Peripheral Access Layer for DSI2_HOST_DBI_IF
 */

#if !defined(PERI_DSI2_HOST_DBI_IF_H_)
#define PERI_DSI2_HOST_DBI_IF_H_                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- DSI2_HOST_DBI_IF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI2_HOST_DBI_IF_Peripheral_Access_Layer DSI2_HOST_DBI_IF Peripheral Access Layer
 * @{
 */

/** DSI2_HOST_DBI_IF - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG_DBI_ENABLE;                    /**< Display Bus Interface (DBI) Enable, offset: 0x0 */
  __IO uint32_t CFG_DBI_HOST_VC;                   /**< DBI Host Virtual Channel, offset: 0x4 */
  __IO uint32_t CFG_DBI_PIXEL_FORMAT;              /**< DBI Pixel Format, offset: 0x8 */
  __IO uint32_t CFG_DBI_PIXEL_PAYLOAD_SIZE;        /**< DBI Pixel Payload Size, offset: 0xC */
  __IO uint32_t CFG_DBI_PIXEL_FIFO_SEND_LEVEL;     /**< DBI Pixel FIFO Send Level, offset: 0x10 */
  __I  uint32_t DBI_HOST_STATUS;                   /**< DBI Host Status, offset: 0x14 */
} DSI2_HOST_DBI_IF_Type;

/* ----------------------------------------------------------------------------
   -- DSI2_HOST_DBI_IF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI2_HOST_DBI_IF_Register_Masks DSI2_HOST_DBI_IF Register Masks
 * @{
 */

/*! @name CFG_DBI_ENABLE - Display Bus Interface (DBI) Enable */
/*! @{ */

#define DSI2_HOST_DBI_IF_CFG_DBI_ENABLE_CFG_DBI_ENABLE_MASK (0x1U)
#define DSI2_HOST_DBI_IF_CFG_DBI_ENABLE_CFG_DBI_ENABLE_SHIFT (0U)
/*! cfg_dbi_enable
 *  0b0..dbi interface off
 *  0b1..dbi interface on
 */
#define DSI2_HOST_DBI_IF_CFG_DBI_ENABLE_CFG_DBI_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_DBI_IF_CFG_DBI_ENABLE_CFG_DBI_ENABLE_SHIFT)) & DSI2_HOST_DBI_IF_CFG_DBI_ENABLE_CFG_DBI_ENABLE_MASK)
/*! @} */

/*! @name CFG_DBI_HOST_VC - DBI Host Virtual Channel */
/*! @{ */

#define DSI2_HOST_DBI_IF_CFG_DBI_HOST_VC_CFG_DBI_HOST_VC_MASK (0x3U)
#define DSI2_HOST_DBI_IF_CFG_DBI_HOST_VC_CFG_DBI_HOST_VC_SHIFT (0U)
#define DSI2_HOST_DBI_IF_CFG_DBI_HOST_VC_CFG_DBI_HOST_VC(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_DBI_IF_CFG_DBI_HOST_VC_CFG_DBI_HOST_VC_SHIFT)) & DSI2_HOST_DBI_IF_CFG_DBI_HOST_VC_CFG_DBI_HOST_VC_MASK)
/*! @} */

/*! @name CFG_DBI_PIXEL_FORMAT - DBI Pixel Format */
/*! @{ */

#define DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_FORMAT_CFG_DBI_PIXEL_FORMAT_MASK (0x7U)
#define DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_FORMAT_CFG_DBI_PIXEL_FORMAT_SHIFT (0U)
#define DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_FORMAT_CFG_DBI_PIXEL_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_FORMAT_CFG_DBI_PIXEL_FORMAT_SHIFT)) & DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_FORMAT_CFG_DBI_PIXEL_FORMAT_MASK)
/*! @} */

/*! @name CFG_DBI_PIXEL_PAYLOAD_SIZE - DBI Pixel Payload Size */
/*! @{ */

#define DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_MASK (0xFFFFU)
#define DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_SHIFT (0U)
#define DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_SHIFT)) & DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_PAYLOAD_SIZE_CFG_DBI_PIXEL_PAYLOAD_SIZE_MASK)
/*! @} */

/*! @name CFG_DBI_PIXEL_FIFO_SEND_LEVEL - DBI Pixel FIFO Send Level */
/*! @{ */

#define DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_MASK (0xFFFFU)
#define DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_SHIFT (0U)
#define DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_SHIFT)) & DSI2_HOST_DBI_IF_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_CFG_DBI_PIXEL_FIFO_SEND_LEVEL_MASK)
/*! @} */

/*! @name DBI_HOST_STATUS - DBI Host Status */
/*! @{ */

#define DSI2_HOST_DBI_IF_DBI_HOST_STATUS_DBI_HOST_UNDERRUN_ERR_MASK (0x1U)
#define DSI2_HOST_DBI_IF_DBI_HOST_STATUS_DBI_HOST_UNDERRUN_ERR_SHIFT (0U)
/*! dbi_host_underrun_err - DBI Host FIFO Underrun Error */
#define DSI2_HOST_DBI_IF_DBI_HOST_STATUS_DBI_HOST_UNDERRUN_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_DBI_IF_DBI_HOST_STATUS_DBI_HOST_UNDERRUN_ERR_SHIFT)) & DSI2_HOST_DBI_IF_DBI_HOST_STATUS_DBI_HOST_UNDERRUN_ERR_MASK)

#define DSI2_HOST_DBI_IF_DBI_HOST_STATUS_DBI_HOST_OVERFLOW_ERR_MASK (0x2U)
#define DSI2_HOST_DBI_IF_DBI_HOST_STATUS_DBI_HOST_OVERFLOW_ERR_SHIFT (1U)
/*! dbi_host_overflow_err - DBI Host FIFO Overflow Error */
#define DSI2_HOST_DBI_IF_DBI_HOST_STATUS_DBI_HOST_OVERFLOW_ERR(x) (((uint32_t)(((uint32_t)(x)) << DSI2_HOST_DBI_IF_DBI_HOST_STATUS_DBI_HOST_OVERFLOW_ERR_SHIFT)) & DSI2_HOST_DBI_IF_DBI_HOST_STATUS_DBI_HOST_OVERFLOW_ERR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI2_HOST_DBI_IF_Register_Masks */


/*!
 * @}
 */ /* end of group DSI2_HOST_DBI_IF_Peripheral_Access_Layer */


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


#endif  /* PERI_DSI2_HOST_DBI_IF_H_ */

