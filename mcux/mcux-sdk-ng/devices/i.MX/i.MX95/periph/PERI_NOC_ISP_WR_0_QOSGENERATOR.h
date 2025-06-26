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
**         CMSIS Peripheral Access Layer for NOC_ISP_WR_0_QOSGENERATOR
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
 * @file NOC_ISP_WR_0_QOSGENERATOR.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for NOC_ISP_WR_0_QOSGENERATOR
 *
 * CMSIS Peripheral Access Layer for NOC_ISP_WR_0_QOSGENERATOR
 */

#if !defined(NOC_ISP_WR_0_QOSGENERATOR_H_)
#define NOC_ISP_WR_0_QOSGENERATOR_H_             /**< Symbol preventing repeated inclusion */

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
   -- NOC_ISP_WR_0_QOSGENERATOR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_ISP_WR_0_QOSGENERATOR_Peripheral_Access_Layer NOC_ISP_WR_0_QOSGENERATOR Peripheral Access Layer
 * @{
 */

/** NOC_ISP_WR_0_QOSGENERATOR - Register Layout Typedef */
typedef struct {
  __I  uint32_t ID_COREID;                         /**< Core ID, offset: 0x0 */
  __I  uint32_t ID_REVISIONID;                     /**< Revision ID, offset: 0x4 */
  __IO uint32_t PRIORITY;                          /**< Priority, offset: 0x8 */
  __IO uint32_t MODE;                              /**< Mode, offset: 0xC */
  __IO uint32_t BANDWIDTH;                         /**< Bandwidth, offset: 0x10 */
  __IO uint32_t SATURATION;                        /**< Saturation, offset: 0x14 */
  __IO uint32_t EXTCONTROL;                        /**< External Inputs Control, offset: 0x18 */
} NOC_ISP_WR_0_QOSGENERATOR_Type;

/* ----------------------------------------------------------------------------
   -- NOC_ISP_WR_0_QOSGENERATOR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_ISP_WR_0_QOSGENERATOR_Register_Masks NOC_ISP_WR_0_QOSGENERATOR Register Masks
 * @{
 */

/*! @name ID_COREID - Core ID */
/*! @{ */

#define NOC_ISP_WR_0_QOSGENERATOR_ID_COREID_CORETYPEID_MASK (0xFFU)
#define NOC_ISP_WR_0_QOSGENERATOR_ID_COREID_CORETYPEID_SHIFT (0U)
#define NOC_ISP_WR_0_QOSGENERATOR_ID_COREID_CORETYPEID(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_ID_COREID_CORETYPEID_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_ID_COREID_CORETYPEID_MASK)

#define NOC_ISP_WR_0_QOSGENERATOR_ID_COREID_CORECHECKSUM_MASK (0xFFFFFF00U)
#define NOC_ISP_WR_0_QOSGENERATOR_ID_COREID_CORECHECKSUM_SHIFT (8U)
#define NOC_ISP_WR_0_QOSGENERATOR_ID_COREID_CORECHECKSUM(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_ID_COREID_CORECHECKSUM_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_ID_COREID_CORECHECKSUM_MASK)
/*! @} */

/*! @name ID_REVISIONID - Revision ID */
/*! @{ */

#define NOC_ISP_WR_0_QOSGENERATOR_ID_REVISIONID_USERID_MASK (0xFFU)
#define NOC_ISP_WR_0_QOSGENERATOR_ID_REVISIONID_USERID_SHIFT (0U)
#define NOC_ISP_WR_0_QOSGENERATOR_ID_REVISIONID_USERID(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_ID_REVISIONID_USERID_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_ID_REVISIONID_USERID_MASK)

#define NOC_ISP_WR_0_QOSGENERATOR_ID_REVISIONID_NOCID_MASK (0xFFFFFF00U)
#define NOC_ISP_WR_0_QOSGENERATOR_ID_REVISIONID_NOCID_SHIFT (8U)
#define NOC_ISP_WR_0_QOSGENERATOR_ID_REVISIONID_NOCID(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_ID_REVISIONID_NOCID_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_ID_REVISIONID_NOCID_MASK)
/*! @} */

/*! @name PRIORITY - Priority */
/*! @{ */

#define NOC_ISP_WR_0_QOSGENERATOR_PRIORITY_P0_MASK (0x3U)
#define NOC_ISP_WR_0_QOSGENERATOR_PRIORITY_P0_SHIFT (0U)
#define NOC_ISP_WR_0_QOSGENERATOR_PRIORITY_P0(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_PRIORITY_P0_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_PRIORITY_P0_MASK)

#define NOC_ISP_WR_0_QOSGENERATOR_PRIORITY_P1_MASK (0x300U)
#define NOC_ISP_WR_0_QOSGENERATOR_PRIORITY_P1_SHIFT (8U)
#define NOC_ISP_WR_0_QOSGENERATOR_PRIORITY_P1(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_PRIORITY_P1_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_PRIORITY_P1_MASK)
/*! @} */

/*! @name MODE - Mode */
/*! @{ */

#define NOC_ISP_WR_0_QOSGENERATOR_MODE_MODE_MASK (0x3U)
#define NOC_ISP_WR_0_QOSGENERATOR_MODE_MODE_SHIFT (0U)
#define NOC_ISP_WR_0_QOSGENERATOR_MODE_MODE(x)   (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_MODE_MODE_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_MODE_MODE_MASK)
/*! @} */

/*! @name BANDWIDTH - Bandwidth */
/*! @{ */

#define NOC_ISP_WR_0_QOSGENERATOR_BANDWIDTH_BANDWIDTH_MASK (0x1FFFU)
#define NOC_ISP_WR_0_QOSGENERATOR_BANDWIDTH_BANDWIDTH_SHIFT (0U)
#define NOC_ISP_WR_0_QOSGENERATOR_BANDWIDTH_BANDWIDTH(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_BANDWIDTH_BANDWIDTH_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_BANDWIDTH_BANDWIDTH_MASK)
/*! @} */

/*! @name SATURATION - Saturation */
/*! @{ */

#define NOC_ISP_WR_0_QOSGENERATOR_SATURATION_SATURATION_MASK (0x3FFU)
#define NOC_ISP_WR_0_QOSGENERATOR_SATURATION_SATURATION_SHIFT (0U)
#define NOC_ISP_WR_0_QOSGENERATOR_SATURATION_SATURATION(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_SATURATION_SATURATION_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_SATURATION_SATURATION_MASK)
/*! @} */

/*! @name EXTCONTROL - External Inputs Control */
/*! @{ */

#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_SOCKETQOSEN_MASK (0x1U)
#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_SOCKETQOSEN_SHIFT (0U)
#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_SOCKETQOSEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_SOCKETQOSEN_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_SOCKETQOSEN_MASK)

#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_EXTTHREN_MASK (0x2U)
#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_EXTTHREN_SHIFT (1U)
#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_EXTTHREN(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_EXTTHREN_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_EXTTHREN_MASK)

#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_INTCLKEN_MASK (0x4U)
#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_INTCLKEN_SHIFT (2U)
#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_INTCLKEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_INTCLKEN_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_INTCLKEN_MASK)

#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_EXTLIMITEN_MASK (0x8U)
#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_EXTLIMITEN_SHIFT (3U)
#define NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_EXTLIMITEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_EXTLIMITEN_SHIFT)) & NOC_ISP_WR_0_QOSGENERATOR_EXTCONTROL_EXTLIMITEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NOC_ISP_WR_0_QOSGENERATOR_Register_Masks */


/*!
 * @}
 */ /* end of group NOC_ISP_WR_0_QOSGENERATOR_Peripheral_Access_Layer */


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


#endif  /* NOC_ISP_WR_0_QOSGENERATOR_H_ */

