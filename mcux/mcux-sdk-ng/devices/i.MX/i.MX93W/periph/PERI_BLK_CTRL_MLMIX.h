/*
** ###################################################################
**     Processors:          MIMX93W32610GCM_ca55
**                          MIMX93W32610GCM_cm33
**                          MIMX93W52610GCM_ca55
**                          MIMX93W52610GCM_cm33
**
**     Version:             rev. 1.0, 2025-12-13
**     Build:               b260114
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_MLMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-12-13)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTRL_MLMIX.h
 * @version 1.0
 * @date 2025-12-13
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_MLMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_MLMIX
 */

#if !defined(PERI_BLK_CTRL_MLMIX_H_)
#define PERI_BLK_CTRL_MLMIX_H_                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX93W32610GCM_ca55))
#include "MIMX93W32_ca55_COMMON.h"
#elif (defined(CPU_MIMX93W32610GCM_cm33))
#include "MIMX93W32_cm33_COMMON.h"
#elif (defined(CPU_MIMX93W52610GCM_ca55))
#include "MIMX93W52_ca55_COMMON.h"
#elif (defined(CPU_MIMX93W52610GCM_cm33))
#include "MIMX93W52_cm33_COMMON.h"
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

#if defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_MLMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_MLMIX_Peripheral_Access_Layer BLK_CTRL_MLMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_MLMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t HS_EN;                             /**< Enable Q handshake module, offset: 0x0 */
} BLK_CTRL_MLMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_MLMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_MLMIX_Register_Masks BLK_CTRL_MLMIX Register Masks
 * @{
 */

/*! @name HS_EN - Enable Q handshake module */
/*! @{ */

#define BLK_CTRL_MLMIX_HS_EN_HS_EN_MASK          (0x1U)
#define BLK_CTRL_MLMIX_HS_EN_HS_EN_SHIFT         (0U)
/*! HS_EN - Enable Q handshake module.
 *  0b0..Q handshake module is disabled. Q channel signals from NPU will not be handled and the clock gate will not be controlled by NPU.
 *  0b1..Q handshake module is enabled. Clock is able to be gated by NPU through Q channel signals
 */
#define BLK_CTRL_MLMIX_HS_EN_HS_EN(x)            (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MLMIX_HS_EN_HS_EN_SHIFT)) & BLK_CTRL_MLMIX_HS_EN_HS_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_MLMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_MLMIX_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_BLK_CTRL_MLMIX_H_ */

