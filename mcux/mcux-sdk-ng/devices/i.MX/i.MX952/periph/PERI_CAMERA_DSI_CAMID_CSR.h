/*
** ###################################################################
**     Processors:          MIMX9522xxVTx_ca55
**                          MIMX9522xxVTx_cm33
**                          MIMX9522xxVTx_cm7
**                          MIMX9522xxVZx_ca55
**                          MIMX9522xxVZx_cm33
**                          MIMX9522xxVZx_cm7
**                          MIMX9523xxVTx_ca55
**                          MIMX9523xxVTx_cm33
**                          MIMX9523xxVTx_cm7
**                          MIMX9523xxVZx_ca55
**                          MIMX9523xxVZx_cm33
**                          MIMX9523xxVZx_cm7
**                          MIMX9524xxVTx_ca55
**                          MIMX9524xxVTx_cm33
**                          MIMX9524xxVTx_cm7
**                          MIMX9524xxVZx_ca55
**                          MIMX9524xxVZx_cm33
**                          MIMX9524xxVZx_cm7
**                          MIMX9525xxVTx_ca55
**                          MIMX9525xxVTx_cm33
**                          MIMX9525xxVTx_cm7
**                          MIMX9525xxVZx_ca55
**                          MIMX9525xxVZx_cm33
**                          MIMX9525xxVZx_cm7
**                          MIMX9528xxVTx_ca55
**                          MIMX9528xxVTx_cm33
**                          MIMX9528xxVTx_cm7
**                          MIMX9528xxVZx_ca55
**                          MIMX9528xxVZx_cm33
**                          MIMX9528xxVZx_cm7
**                          MIMX9529xxVTx_ca55
**                          MIMX9529xxVTx_cm33
**                          MIMX9529xxVTx_cm7
**                          MIMX9529xxVZx_ca55
**                          MIMX9529xxVZx_cm33
**                          MIMX9529xxVZx_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260324
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CAMERA_DSI_CAMID_CSR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CAMERA_DSI_CAMID_CSR.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CAMERA_DSI_CAMID_CSR
 *
 * CMSIS Peripheral Access Layer for CAMERA_DSI_CAMID_CSR
 */

#if !defined(PERI_CAMERA_DSI_CAMID_CSR_H_)
#define PERI_CAMERA_DSI_CAMID_CSR_H_             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9522xxVTx_ca55) || defined(CPU_MIMX9522xxVZx_ca55))
#include "MIMX9522_ca55_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm33) || defined(CPU_MIMX9522xxVZx_cm33))
#include "MIMX9522_cm33_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm7) || defined(CPU_MIMX9522xxVZx_cm7))
#include "MIMX9522_cm7_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_ca55) || defined(CPU_MIMX9523xxVZx_ca55))
#include "MIMX9523_ca55_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm33) || defined(CPU_MIMX9523xxVZx_cm33))
#include "MIMX9523_cm33_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm7) || defined(CPU_MIMX9523xxVZx_cm7))
#include "MIMX9523_cm7_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_ca55) || defined(CPU_MIMX9524xxVZx_ca55))
#include "MIMX9524_ca55_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm33) || defined(CPU_MIMX9524xxVZx_cm33))
#include "MIMX9524_cm33_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm7) || defined(CPU_MIMX9524xxVZx_cm7))
#include "MIMX9524_cm7_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_ca55) || defined(CPU_MIMX9525xxVZx_ca55))
#include "MIMX9525_ca55_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm33) || defined(CPU_MIMX9525xxVZx_cm33))
#include "MIMX9525_cm33_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm7) || defined(CPU_MIMX9525xxVZx_cm7))
#include "MIMX9525_cm7_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_ca55) || defined(CPU_MIMX9528xxVZx_ca55))
#include "MIMX9528_ca55_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm33) || defined(CPU_MIMX9528xxVZx_cm33))
#include "MIMX9528_cm33_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm7) || defined(CPU_MIMX9528xxVZx_cm7))
#include "MIMX9528_cm7_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_ca55) || defined(CPU_MIMX9529xxVZx_ca55))
#include "MIMX9529_ca55_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm33) || defined(CPU_MIMX9529xxVZx_cm33))
#include "MIMX9529_cm33_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm7) || defined(CPU_MIMX9529xxVZx_cm7))
#include "MIMX9529_cm7_COMMON.h"
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
   -- CAMERA_DSI_CAMID_CSR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_DSI_CAMID_CSR_Peripheral_Access_Layer CAMERA_DSI_CAMID_CSR Peripheral Access Layer
 * @{
 */

/** CAMERA_DSI_CAMID_CSR - Register Layout Typedef */
typedef struct {
  __IO uint32_t ISP_CAMID;                         /**< ISP CAMID, offset: 0x0 */
} CAMERA_DSI_CAMID_CSR_Type;

/* ----------------------------------------------------------------------------
   -- CAMERA_DSI_CAMID_CSR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_DSI_CAMID_CSR_Register_Masks CAMERA_DSI_CAMID_CSR Register Masks
 * @{
 */

/*! @name ISP_CAMID - ISP CAMID */
/*! @{ */

#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_AWUSER0_MASK (0x7U)
#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_AWUSER0_SHIFT (0U)
/*! AWUSER0 - AXI USER setting - WRITE bus 0 */
#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_AWUSER0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_CAMID_CSR_ISP_CAMID_AWUSER0_SHIFT)) & CAMERA_DSI_CAMID_CSR_ISP_CAMID_AWUSER0_MASK)

#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_AWUSER1_MASK (0x70U)
#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_AWUSER1_SHIFT (4U)
/*! AWUSER1 - AXI USER setting - WRITE bus 1 */
#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_AWUSER1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_CAMID_CSR_ISP_CAMID_AWUSER1_SHIFT)) & CAMERA_DSI_CAMID_CSR_ISP_CAMID_AWUSER1_MASK)

#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_ARUSER0_MASK (0x700U)
#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_ARUSER0_SHIFT (8U)
/*! ARUSER0 - AXI USER setting - READ bus 0 */
#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_ARUSER0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_CAMID_CSR_ISP_CAMID_ARUSER0_SHIFT)) & CAMERA_DSI_CAMID_CSR_ISP_CAMID_ARUSER0_MASK)

#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_ARUSER1_MASK (0x7000U)
#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_ARUSER1_SHIFT (12U)
/*! ARUSER1 - AXI USER setting - READ bus 1 */
#define CAMERA_DSI_CAMID_CSR_ISP_CAMID_ARUSER1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_CAMID_CSR_ISP_CAMID_ARUSER1_SHIFT)) & CAMERA_DSI_CAMID_CSR_ISP_CAMID_ARUSER1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAMERA_DSI_CAMID_CSR_Register_Masks */


/*!
 * @}
 */ /* end of group CAMERA_DSI_CAMID_CSR_Peripheral_Access_Layer */


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


#endif  /* PERI_CAMERA_DSI_CAMID_CSR_H_ */

