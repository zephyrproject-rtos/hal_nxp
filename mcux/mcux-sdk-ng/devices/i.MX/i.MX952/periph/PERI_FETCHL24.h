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
**         CMSIS Peripheral Access Layer for fetchl24
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
 * @file PERI_fetchl24.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchl24
 *
 * CMSIS Peripheral Access Layer for fetchl24
 */

#if !defined(PERI_FETCHL24_H_)
#define PERI_FETCHL24_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchl24 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl24_Peripheral_Access_Layer fetchl24 Peripheral Access Layer
 * @{
 */

/** fetchl24 - Register Layout Typedef */
typedef struct {
  __I  uint32_t CURBA0;                            /**< CurBaseAddress0, offset: 0x0 */
  __I  uint32_t CURBAMS0;                          /**< CurBaseAddressMSB0, offset: 0x4 */
  __I  uint32_t CURBA1;                            /**< CurBaseAddress1, offset: 0x8 */
  __I  uint32_t CURBAMS1;                          /**< CurBaseAddressMSB1, offset: 0xC */
  __I  uint32_t CURBA2;                            /**< CurBaseAddress2, offset: 0x10 */
  __I  uint32_t CURBAMS2;                          /**< CurBaseAddressMSB2, offset: 0x14 */
  __I  uint32_t CURBA3;                            /**< CurBaseAddress3, offset: 0x18 */
  __I  uint32_t CURBAMS3;                          /**< CurBaseAddressMSB3, offset: 0x1C */
  __I  uint32_t CURBA4;                            /**< CurBaseAddress4, offset: 0x20 */
  __I  uint32_t CURBAMS4;                          /**< CurBaseAddressMSB4, offset: 0x24 */
  __I  uint32_t CURBA5;                            /**< CurBaseAddress5, offset: 0x28 */
  __I  uint32_t CURBAMS5;                          /**< CurBaseAddressMSB5, offset: 0x2C */
  __I  uint32_t CURBA6;                            /**< CurBaseAddress6, offset: 0x30 */
  __I  uint32_t CURBAMS6;                          /**< CurBaseAddressMSB6, offset: 0x34 */
  __I  uint32_t CURBA7;                            /**< CurBaseAddress7, offset: 0x38 */
  __I  uint32_t CURBAMS7;                          /**< CurBaseAddressMSB7, offset: 0x3C */
  __I  uint32_t HIDSTA;                            /**< HiddenStatus, offset: 0x40 */
} fetchl24_Type;

/* ----------------------------------------------------------------------------
   -- fetchl24 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl24_Register_Masks fetchl24 Register Masks
 * @{
 */

/*! @name CURBA0 - CurBaseAddress0 */
/*! @{ */

#define fetchl24_CURBA0_CurBA0_MASK              (0xFFFFFFFFU)
#define fetchl24_CURBA0_CurBA0_SHIFT             (0U)
/*! CurBA0 - CurBaseAddress0 */
#define fetchl24_CURBA0_CurBA0(x)                (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBA0_CurBA0_SHIFT)) & fetchl24_CURBA0_CurBA0_MASK)
/*! @} */

/*! @name CURBAMS0 - CurBaseAddressMSB0 */
/*! @{ */

#define fetchl24_CURBAMS0_CurBAMS0_MASK          (0xFFU)
#define fetchl24_CURBAMS0_CurBAMS0_SHIFT         (0U)
/*! CurBAMS0 - CurBaseAddressMSB0 */
#define fetchl24_CURBAMS0_CurBAMS0(x)            (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBAMS0_CurBAMS0_SHIFT)) & fetchl24_CURBAMS0_CurBAMS0_MASK)
/*! @} */

/*! @name CURBA1 - CurBaseAddress1 */
/*! @{ */

#define fetchl24_CURBA1_CurBA1_MASK              (0xFFFFFFFFU)
#define fetchl24_CURBA1_CurBA1_SHIFT             (0U)
/*! CurBA1 - CurBaseAddress1 */
#define fetchl24_CURBA1_CurBA1(x)                (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBA1_CurBA1_SHIFT)) & fetchl24_CURBA1_CurBA1_MASK)
/*! @} */

/*! @name CURBAMS1 - CurBaseAddressMSB1 */
/*! @{ */

#define fetchl24_CURBAMS1_CurBAMS1_MASK          (0xFFU)
#define fetchl24_CURBAMS1_CurBAMS1_SHIFT         (0U)
/*! CurBAMS1 - CurBaseAddressMSB1 */
#define fetchl24_CURBAMS1_CurBAMS1(x)            (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBAMS1_CurBAMS1_SHIFT)) & fetchl24_CURBAMS1_CurBAMS1_MASK)
/*! @} */

/*! @name CURBA2 - CurBaseAddress2 */
/*! @{ */

#define fetchl24_CURBA2_CurBA2_MASK              (0xFFFFFFFFU)
#define fetchl24_CURBA2_CurBA2_SHIFT             (0U)
/*! CurBA2 - CurBaseAddress2 */
#define fetchl24_CURBA2_CurBA2(x)                (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBA2_CurBA2_SHIFT)) & fetchl24_CURBA2_CurBA2_MASK)
/*! @} */

/*! @name CURBAMS2 - CurBaseAddressMSB2 */
/*! @{ */

#define fetchl24_CURBAMS2_CurBAMS2_MASK          (0xFFU)
#define fetchl24_CURBAMS2_CurBAMS2_SHIFT         (0U)
/*! CurBAMS2 - CurBaseAddressMSB2 */
#define fetchl24_CURBAMS2_CurBAMS2(x)            (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBAMS2_CurBAMS2_SHIFT)) & fetchl24_CURBAMS2_CurBAMS2_MASK)
/*! @} */

/*! @name CURBA3 - CurBaseAddress3 */
/*! @{ */

#define fetchl24_CURBA3_CurBA3_MASK              (0xFFFFFFFFU)
#define fetchl24_CURBA3_CurBA3_SHIFT             (0U)
/*! CurBA3 - CurBaseAddress3 */
#define fetchl24_CURBA3_CurBA3(x)                (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBA3_CurBA3_SHIFT)) & fetchl24_CURBA3_CurBA3_MASK)
/*! @} */

/*! @name CURBAMS3 - CurBaseAddressMSB3 */
/*! @{ */

#define fetchl24_CURBAMS3_CurBAMS3_MASK          (0xFFU)
#define fetchl24_CURBAMS3_CurBAMS3_SHIFT         (0U)
/*! CurBAMS3 - CurBaseAddressMSB3 */
#define fetchl24_CURBAMS3_CurBAMS3(x)            (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBAMS3_CurBAMS3_SHIFT)) & fetchl24_CURBAMS3_CurBAMS3_MASK)
/*! @} */

/*! @name CURBA4 - CurBaseAddress4 */
/*! @{ */

#define fetchl24_CURBA4_CurBA4_MASK              (0xFFFFFFFFU)
#define fetchl24_CURBA4_CurBA4_SHIFT             (0U)
/*! CurBA4 - CurBaseAddress4 */
#define fetchl24_CURBA4_CurBA4(x)                (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBA4_CurBA4_SHIFT)) & fetchl24_CURBA4_CurBA4_MASK)
/*! @} */

/*! @name CURBAMS4 - CurBaseAddressMSB4 */
/*! @{ */

#define fetchl24_CURBAMS4_CurBAMS4_MASK          (0xFFU)
#define fetchl24_CURBAMS4_CurBAMS4_SHIFT         (0U)
/*! CurBAMS4 - CurBaseAddressMSB4 */
#define fetchl24_CURBAMS4_CurBAMS4(x)            (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBAMS4_CurBAMS4_SHIFT)) & fetchl24_CURBAMS4_CurBAMS4_MASK)
/*! @} */

/*! @name CURBA5 - CurBaseAddress5 */
/*! @{ */

#define fetchl24_CURBA5_CurBA5_MASK              (0xFFFFFFFFU)
#define fetchl24_CURBA5_CurBA5_SHIFT             (0U)
/*! CurBA5 - CurBaseAddress5 */
#define fetchl24_CURBA5_CurBA5(x)                (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBA5_CurBA5_SHIFT)) & fetchl24_CURBA5_CurBA5_MASK)
/*! @} */

/*! @name CURBAMS5 - CurBaseAddressMSB5 */
/*! @{ */

#define fetchl24_CURBAMS5_CurBAMS5_MASK          (0xFFU)
#define fetchl24_CURBAMS5_CurBAMS5_SHIFT         (0U)
/*! CurBAMS5 - CurBaseAddressMSB5 */
#define fetchl24_CURBAMS5_CurBAMS5(x)            (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBAMS5_CurBAMS5_SHIFT)) & fetchl24_CURBAMS5_CurBAMS5_MASK)
/*! @} */

/*! @name CURBA6 - CurBaseAddress6 */
/*! @{ */

#define fetchl24_CURBA6_CurBA6_MASK              (0xFFFFFFFFU)
#define fetchl24_CURBA6_CurBA6_SHIFT             (0U)
/*! CurBA6 - CurBaseAddress6 */
#define fetchl24_CURBA6_CurBA6(x)                (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBA6_CurBA6_SHIFT)) & fetchl24_CURBA6_CurBA6_MASK)
/*! @} */

/*! @name CURBAMS6 - CurBaseAddressMSB6 */
/*! @{ */

#define fetchl24_CURBAMS6_CurBAMS6_MASK          (0xFFU)
#define fetchl24_CURBAMS6_CurBAMS6_SHIFT         (0U)
/*! CurBAMS6 - CurBaseAddressMSB6 */
#define fetchl24_CURBAMS6_CurBAMS6(x)            (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBAMS6_CurBAMS6_SHIFT)) & fetchl24_CURBAMS6_CurBAMS6_MASK)
/*! @} */

/*! @name CURBA7 - CurBaseAddress7 */
/*! @{ */

#define fetchl24_CURBA7_CurBA7_MASK              (0xFFFFFFFFU)
#define fetchl24_CURBA7_CurBA7_SHIFT             (0U)
/*! CurBA7 - CurBaseAddress7 */
#define fetchl24_CURBA7_CurBA7(x)                (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBA7_CurBA7_SHIFT)) & fetchl24_CURBA7_CurBA7_MASK)
/*! @} */

/*! @name CURBAMS7 - CurBaseAddressMSB7 */
/*! @{ */

#define fetchl24_CURBAMS7_CurBAMS7_MASK          (0xFFU)
#define fetchl24_CURBAMS7_CurBAMS7_SHIFT         (0U)
/*! CurBAMS7 - CurBaseAddressMSB7 */
#define fetchl24_CURBAMS7_CurBAMS7(x)            (((uint32_t)(((uint32_t)(x)) << fetchl24_CURBAMS7_CurBAMS7_SHIFT)) & fetchl24_CURBAMS7_CurBAMS7_MASK)
/*! @} */

/*! @name HIDSTA - HiddenStatus */
/*! @{ */

#define fetchl24_HIDSTA_StBusy_MASK              (0x1U)
#define fetchl24_HIDSTA_StBusy_SHIFT             (0U)
/*! StBusy - StatusBusy */
#define fetchl24_HIDSTA_StBusy(x)                (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_StBusy_SHIFT)) & fetchl24_HIDSTA_StBusy_MASK)

#define fetchl24_HIDSTA_StBuIdle_MASK            (0x10U)
#define fetchl24_HIDSTA_StBuIdle_SHIFT           (4U)
/*! StBuIdle - StatusBuffersIdle */
#define fetchl24_HIDSTA_StBuIdle(x)              (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_StBuIdle_SHIFT)) & fetchl24_HIDSTA_StBuIdle_MASK)

#define fetchl24_HIDSTA_StReq_MASK               (0x20U)
#define fetchl24_HIDSTA_StReq_SHIFT              (5U)
/*! StReq - StatusRequest */
#define fetchl24_HIDSTA_StReq(x)                 (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_StReq_SHIFT)) & fetchl24_HIDSTA_StReq_MASK)

#define fetchl24_HIDSTA_StCom_MASK               (0x40U)
#define fetchl24_HIDSTA_StCom_SHIFT              (6U)
/*! StCom - StatusComplete */
#define fetchl24_HIDSTA_StCom(x)                 (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_StCom_SHIFT)) & fetchl24_HIDSTA_StCom_MASK)

#define fetchl24_HIDSTA_ShadowS0_MASK            (0x100U)
#define fetchl24_HIDSTA_ShadowS0_SHIFT           (8U)
/*! ShadowS0 - ShadowStatus0 */
#define fetchl24_HIDSTA_ShadowS0(x)              (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_ShadowS0_SHIFT)) & fetchl24_HIDSTA_ShadowS0_MASK)

#define fetchl24_HIDSTA_ShadowS1_MASK            (0x200U)
#define fetchl24_HIDSTA_ShadowS1_SHIFT           (9U)
/*! ShadowS1 - ShadowStatus1 */
#define fetchl24_HIDSTA_ShadowS1(x)              (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_ShadowS1_SHIFT)) & fetchl24_HIDSTA_ShadowS1_MASK)

#define fetchl24_HIDSTA_ShadowS2_MASK            (0x400U)
#define fetchl24_HIDSTA_ShadowS2_SHIFT           (10U)
/*! ShadowS2 - ShadowStatus2 */
#define fetchl24_HIDSTA_ShadowS2(x)              (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_ShadowS2_SHIFT)) & fetchl24_HIDSTA_ShadowS2_MASK)

#define fetchl24_HIDSTA_ShadowS3_MASK            (0x800U)
#define fetchl24_HIDSTA_ShadowS3_SHIFT           (11U)
/*! ShadowS3 - ShadowStatus3 */
#define fetchl24_HIDSTA_ShadowS3(x)              (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_ShadowS3_SHIFT)) & fetchl24_HIDSTA_ShadowS3_MASK)

#define fetchl24_HIDSTA_ShadowS4_MASK            (0x1000U)
#define fetchl24_HIDSTA_ShadowS4_SHIFT           (12U)
/*! ShadowS4 - ShadowStatus4 */
#define fetchl24_HIDSTA_ShadowS4(x)              (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_ShadowS4_SHIFT)) & fetchl24_HIDSTA_ShadowS4_MASK)

#define fetchl24_HIDSTA_ShadowS5_MASK            (0x2000U)
#define fetchl24_HIDSTA_ShadowS5_SHIFT           (13U)
/*! ShadowS5 - ShadowStatus5 */
#define fetchl24_HIDSTA_ShadowS5(x)              (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_ShadowS5_SHIFT)) & fetchl24_HIDSTA_ShadowS5_MASK)

#define fetchl24_HIDSTA_ShadowS6_MASK            (0x4000U)
#define fetchl24_HIDSTA_ShadowS6_SHIFT           (14U)
/*! ShadowS6 - ShadowStatus6 */
#define fetchl24_HIDSTA_ShadowS6(x)              (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_ShadowS6_SHIFT)) & fetchl24_HIDSTA_ShadowS6_MASK)

#define fetchl24_HIDSTA_ShadowS7_MASK            (0x8000U)
#define fetchl24_HIDSTA_ShadowS7_SHIFT           (15U)
/*! ShadowS7 - ShadowStatus7 */
#define fetchl24_HIDSTA_ShadowS7(x)              (((uint32_t)(((uint32_t)(x)) << fetchl24_HIDSTA_ShadowS7_SHIFT)) & fetchl24_HIDSTA_ShadowS7_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchl24_Register_Masks */


/*!
 * @}
 */ /* end of group fetchl24_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHL24_H_ */

