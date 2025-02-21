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
**         CMSIS Peripheral Access Layer for CAMERA_DSI_CAMID_CSR
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
 * @file CAMERA_DSI_CAMID_CSR.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for CAMERA_DSI_CAMID_CSR
 *
 * CMSIS Peripheral Access Layer for CAMERA_DSI_CAMID_CSR
 */

#if !defined(CAMERA_DSI_CAMID_CSR_H_)
#define CAMERA_DSI_CAMID_CSR_H_                  /**< Symbol preventing repeated inclusion */

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


#endif  /* CAMERA_DSI_CAMID_CSR_H_ */

