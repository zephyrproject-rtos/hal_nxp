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
**         CMSIS Peripheral Access Layer for splanar3
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
 * @file PERI_splanar3.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for splanar3
 *
 * CMSIS Peripheral Access Layer for splanar3
 */

#if !defined(PERI_SPLANAR3_H_)
#define PERI_SPLANAR3_H_                         /**< Symbol preventing repeated inclusion */

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
   -- splanar3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup splanar3_Peripheral_Access_Layer splanar3 Peripheral Access Layer
 * @{
 */

/** splanar3 - Register Layout Typedef */
typedef struct {
  __I  uint32_t WRIADDR;                           /**< WriteAddress, offset: 0x0 */
  __I  uint32_t WRIADMSB;                          /**< WriteAddressMSB, offset: 0x4 */
  __I  uint32_t FRAP;                              /**< FrameProperties, offset: 0x8 */
  __I  uint32_t BURBUFPR;                          /**< BurstBufferProperties, offset: 0xC */
  __I  uint32_t LASTCOW;                           /**< LastControlWord, offset: 0x10 */
  __I  uint32_t PERCOUNT;                          /**< PerfCounter, offset: 0x14 */
  __IO uint32_t STATUS;                            /**< Status, offset: 0x18 */
} splanar3_Type;

/* ----------------------------------------------------------------------------
   -- splanar3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup splanar3_Register_Masks splanar3 Register Masks
 * @{
 */

/*! @name WRIADDR - WriteAddress */
/*! @{ */

#define splanar3_WRIADDR_WrtAdd_MASK             (0xFFFFFFFFU)
#define splanar3_WRIADDR_WrtAdd_SHIFT            (0U)
/*! WrtAdd - WriteAddress */
#define splanar3_WRIADDR_WrtAdd(x)               (((uint32_t)(((uint32_t)(x)) << splanar3_WRIADDR_WrtAdd_SHIFT)) & splanar3_WRIADDR_WrtAdd_MASK)
/*! @} */

/*! @name WRIADMSB - WriteAddressMSB */
/*! @{ */

#define splanar3_WRIADMSB_WrtAdMSB_MASK          (0xFFU)
#define splanar3_WRIADMSB_WrtAdMSB_SHIFT         (0U)
/*! WrtAdMSB - WriteAddressMSB */
#define splanar3_WRIADMSB_WrtAdMSB(x)            (((uint32_t)(((uint32_t)(x)) << splanar3_WRIADMSB_WrtAdMSB_SHIFT)) & splanar3_WRIADMSB_WrtAdMSB_MASK)
/*! @} */

/*! @name FRAP - FrameProperties */
/*! @{ */

#define splanar3_FRAP_FieldId_MASK               (0x1U)
#define splanar3_FRAP_FieldId_SHIFT              (0U)
/*! FieldId - FieldId */
#define splanar3_FRAP_FieldId(x)                 (((uint32_t)(((uint32_t)(x)) << splanar3_FRAP_FieldId_SHIFT)) & splanar3_FRAP_FieldId_MASK)
/*! @} */

/*! @name BURBUFPR - BurstBufferProperties */
/*! @{ */

#define splanar3_BURBUFPR_MaxBuL_MASK            (0x1F00U)
#define splanar3_BURBUFPR_MaxBuL_SHIFT           (8U)
/*! MaxBuL - MaxBurstLength */
#define splanar3_BURBUFPR_MaxBuL(x)              (((uint32_t)(((uint32_t)(x)) << splanar3_BURBUFPR_MaxBuL_SHIFT)) & splanar3_BURBUFPR_MaxBuL_MASK)
/*! @} */

/*! @name LASTCOW - LastControlWord */
/*! @{ */

#define splanar3_LASTCOW_LVAL_MASK               (0xFFFFFFFFU)
#define splanar3_LASTCOW_LVAL_SHIFT              (0U)
/*! LVAL - L_VAL */
#define splanar3_LASTCOW_LVAL(x)                 (((uint32_t)(((uint32_t)(x)) << splanar3_LASTCOW_LVAL_SHIFT)) & splanar3_LASTCOW_LVAL_MASK)
/*! @} */

/*! @name PERCOUNT - PerfCounter */
/*! @{ */

#define splanar3_PERCOUNT_PerfRes_MASK           (0xFFFFFFFFU)
#define splanar3_PERCOUNT_PerfRes_SHIFT          (0U)
/*! PerfRes - PerfResult */
#define splanar3_PERCOUNT_PerfRes(x)             (((uint32_t)(((uint32_t)(x)) << splanar3_PERCOUNT_PerfRes_SHIFT)) & splanar3_PERCOUNT_PerfRes_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define splanar3_STATUS_StBusy_MASK              (0x1U)
#define splanar3_STATUS_StBusy_SHIFT             (0U)
/*! StBusy - StatusBusy */
#define splanar3_STATUS_StBusy(x)                (((uint32_t)(((uint32_t)(x)) << splanar3_STATUS_StBusy_SHIFT)) & splanar3_STATUS_StBusy_MASK)

#define splanar3_STATUS_StBuIdle_MASK            (0x10U)
#define splanar3_STATUS_StBuIdle_SHIFT           (4U)
/*! StBuIdle - StatusBuffersIdle */
#define splanar3_STATUS_StBuIdle(x)              (((uint32_t)(((uint32_t)(x)) << splanar3_STATUS_StBuIdle_SHIFT)) & splanar3_STATUS_StBuIdle_MASK)

#define splanar3_STATUS_StReq_MASK               (0x20U)
#define splanar3_STATUS_StReq_SHIFT              (5U)
/*! StReq - StatusRequest */
#define splanar3_STATUS_StReq(x)                 (((uint32_t)(((uint32_t)(x)) << splanar3_STATUS_StReq_SHIFT)) & splanar3_STATUS_StReq_MASK)

#define splanar3_STATUS_StCom_MASK               (0x40U)
#define splanar3_STATUS_StCom_SHIFT              (6U)
/*! StCom - StatusComplete */
#define splanar3_STATUS_StCom(x)                 (((uint32_t)(((uint32_t)(x)) << splanar3_STATUS_StCom_SHIFT)) & splanar3_STATUS_StCom_MASK)

#define splanar3_STATUS_PxbusErr_MASK            (0x100U)
#define splanar3_STATUS_PxbusErr_SHIFT           (8U)
/*! PxbusErr - PixelbusError */
#define splanar3_STATUS_PxbusErr(x)              (((uint32_t)(((uint32_t)(x)) << splanar3_STATUS_PxbusErr_SHIFT)) & splanar3_STATUS_PxbusErr_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group splanar3_Register_Masks */


/*!
 * @}
 */ /* end of group splanar3_Peripheral_Access_Layer */


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


#endif  /* PERI_SPLANAR3_H_ */

