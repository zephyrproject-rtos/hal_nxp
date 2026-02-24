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
**         CMSIS Peripheral Access Layer for fetchyu3
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
 * @file PERI_fetchyu3.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchyu3
 *
 * CMSIS Peripheral Access Layer for fetchyu3
 */

#if !defined(PERI_FETCHYU3_H_)
#define PERI_FETCHYU3_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchyu3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchyu3_Peripheral_Access_Layer fetchyu3 Peripheral Access Layer
 * @{
 */

/** fetchyu3 - Register Layout Typedef */
typedef struct {
  __I  uint32_t READAD0;                           /**< ReadAddress0, offset: 0x0 */
  __I  uint32_t READADM0;                          /**< ReadAddressMSB0, offset: 0x4 */
  __I  uint32_t BURBUFPR;                          /**< BurstBufferProperties, offset: 0x8 */
  __IO uint32_t STATUS;                            /**< Status, offset: 0xC */
} fetchyu3_Type;

/* ----------------------------------------------------------------------------
   -- fetchyu3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchyu3_Register_Masks fetchyu3 Register Masks
 * @{
 */

/*! @name READAD0 - ReadAddress0 */
/*! @{ */

#define fetchyu3_READAD0_RdAddr0_MASK            (0xFFFFFFFFU)
#define fetchyu3_READAD0_RdAddr0_SHIFT           (0U)
/*! RdAddr0 - ReadAddress0 */
#define fetchyu3_READAD0_RdAddr0(x)              (((uint32_t)(((uint32_t)(x)) << fetchyu3_READAD0_RdAddr0_SHIFT)) & fetchyu3_READAD0_RdAddr0_MASK)
/*! @} */

/*! @name READADM0 - ReadAddressMSB0 */
/*! @{ */

#define fetchyu3_READADM0_RdAddrM0_MASK          (0xFFU)
#define fetchyu3_READADM0_RdAddrM0_SHIFT         (0U)
/*! RdAddrM0 - ReadAddressMSB0 */
#define fetchyu3_READADM0_RdAddrM0(x)            (((uint32_t)(((uint32_t)(x)) << fetchyu3_READADM0_RdAddrM0_SHIFT)) & fetchyu3_READADM0_RdAddrM0_MASK)
/*! @} */

/*! @name BURBUFPR - BurstBufferProperties */
/*! @{ */

#define fetchyu3_BURBUFPR_MndBstBf_MASK          (0xFFU)
#define fetchyu3_BURBUFPR_MndBstBf_SHIFT         (0U)
/*! MndBstBf - ManagedBurstBuffers */
#define fetchyu3_BURBUFPR_MndBstBf(x)            (((uint32_t)(((uint32_t)(x)) << fetchyu3_BURBUFPR_MndBstBf_SHIFT)) & fetchyu3_BURBUFPR_MndBstBf_MASK)

#define fetchyu3_BURBUFPR_BurLFMBu_MASK          (0x1F00U)
#define fetchyu3_BURBUFPR_BurLFMBu_SHIFT         (8U)
/*! BurLFMBu - BurstLengthForMaxBuffers */
#define fetchyu3_BURBUFPR_BurLFMBu(x)            (((uint32_t)(((uint32_t)(x)) << fetchyu3_BURBUFPR_BurLFMBu_SHIFT)) & fetchyu3_BURBUFPR_BurLFMBu_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define fetchyu3_STATUS_WrtTout_MASK             (0x1U)
#define fetchyu3_STATUS_WrtTout_SHIFT            (0U)
/*! WrtTout - WriteTimeout */
#define fetchyu3_STATUS_WrtTout(x)               (((uint32_t)(((uint32_t)(x)) << fetchyu3_STATUS_WrtTout_SHIFT)) & fetchyu3_STATUS_WrtTout_MASK)

#define fetchyu3_STATUS_ReadTiou_MASK            (0x10U)
#define fetchyu3_STATUS_ReadTiou_SHIFT           (4U)
/*! ReadTiou - ReadTimeout */
#define fetchyu3_STATUS_ReadTiou(x)              (((uint32_t)(((uint32_t)(x)) << fetchyu3_STATUS_ReadTiou_SHIFT)) & fetchyu3_STATUS_ReadTiou_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchyu3_Register_Masks */


/*!
 * @}
 */ /* end of group fetchyu3_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHYU3_H_ */

