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
**         CMSIS Peripheral Access Layer for CAS
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
 * @file CAS.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for CAS
 *
 * CMSIS Peripheral Access Layer for CAS
 */

#if !defined(CAS_H_)
#define CAS_H_                                   /**< Symbol preventing repeated inclusion */

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
   -- CAS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAS_Peripheral_Access_Layer CAS Peripheral Access Layer
 * @{
 */

/** CAS - Size of Registers Arrays */
#define CAS_NEO_PIPE2_CAS_CONF_COUNT              1u

/** CAS - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10 */
         uint8_t RESERVED_0[4];
    __IO uint32_t GAIN_CAM;                          /**< Camera 0 CAS Gain Register, array offset: 0x4, array step: 0x10 */
    __IO uint32_t CORR_CAM;                          /**< Camera 0 CAS Correction Register, array offset: 0x8, array step: 0x10 */
    __IO uint32_t OFFSET_CAM;                        /**< Camera 0 CAS Offset Register, array offset: 0xC, array step: 0x10 */
  } NEO_PIPE2_CAS_CONF[CAS_NEO_PIPE2_CAS_CONF_COUNT];
} CAS_Type;

/* ----------------------------------------------------------------------------
   -- CAS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAS_Register_Masks CAS Register Masks
 * @{
 */

/*! @name GAIN_CAM - Camera 0 CAS Gain Register */
/*! @{ */

#define CAS_GAIN_CAM_SCALE_MASK                  (0xFFFFU)
#define CAS_GAIN_CAM_SCALE_SHIFT                 (0U)
#define CAS_GAIN_CAM_SCALE(x)                    (((uint32_t)(((uint32_t)(x)) << CAS_GAIN_CAM_SCALE_SHIFT)) & CAS_GAIN_CAM_SCALE_MASK)

#define CAS_GAIN_CAM_SHIFT_MASK                  (0xFF0000U)
#define CAS_GAIN_CAM_SHIFT_SHIFT                 (16U)
#define CAS_GAIN_CAM_SHIFT(x)                    (((uint32_t)(((uint32_t)(x)) << CAS_GAIN_CAM_SHIFT_SHIFT)) & CAS_GAIN_CAM_SHIFT_MASK)
/*! @} */

/* The count of CAS_GAIN_CAM */
#define CAS_GAIN_CAM_COUNT                       (1U)

/*! @name CORR_CAM - Camera 0 CAS Correction Register */
/*! @{ */

#define CAS_CORR_CAM_CORR_MASK                   (0xFFFFU)
#define CAS_CORR_CAM_CORR_SHIFT                  (0U)
#define CAS_CORR_CAM_CORR(x)                     (((uint32_t)(((uint32_t)(x)) << CAS_CORR_CAM_CORR_SHIFT)) & CAS_CORR_CAM_CORR_MASK)
/*! @} */

/* The count of CAS_CORR_CAM */
#define CAS_CORR_CAM_COUNT                       (1U)

/*! @name OFFSET_CAM - Camera 0 CAS Offset Register */
/*! @{ */

#define CAS_OFFSET_CAM_OFFSET_MASK               (0xFFFFU)
#define CAS_OFFSET_CAM_OFFSET_SHIFT              (0U)
#define CAS_OFFSET_CAM_OFFSET(x)                 (((uint32_t)(((uint32_t)(x)) << CAS_OFFSET_CAM_OFFSET_SHIFT)) & CAS_OFFSET_CAM_OFFSET_MASK)
/*! @} */

/* The count of CAS_OFFSET_CAM */
#define CAS_OFFSET_CAM_COUNT                     (1U)


/*!
 * @}
 */ /* end of group CAS_Register_Masks */


/*!
 * @}
 */ /* end of group CAS_Peripheral_Access_Layer */


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


#endif  /* CAS_H_ */

