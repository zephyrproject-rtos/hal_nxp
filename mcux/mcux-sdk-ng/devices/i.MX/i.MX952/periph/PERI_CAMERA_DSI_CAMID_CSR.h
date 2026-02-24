/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CAMERA_DSI_CAMID_CSR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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

