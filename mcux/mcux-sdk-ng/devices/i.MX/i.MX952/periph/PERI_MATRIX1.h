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
**         CMSIS Peripheral Access Layer for matrix1
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
 * @file PERI_matrix1.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for matrix1
 *
 * CMSIS Peripheral Access Layer for matrix1
 */

#if !defined(PERI_MATRIX1_H_)
#define PERI_MATRIX1_H_                          /**< Symbol preventing repeated inclusion */

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
   -- matrix1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup matrix1_Peripheral_Access_Layer matrix1 Peripheral Access Layer
 * @{
 */

/** matrix1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t OFFSVEC0;                          /**< OffsetVector0, offset: 0x0 */
  __IO uint32_t OFFSVEC1;                          /**< OffsetVector1, offset: 0x4 */
  __I  uint32_t LASTCOW;                           /**< LastControlWord, offset: 0x8 */
  __I  uint32_t MATTYPE;                           /**< MatrixType, offset: 0xC */
} matrix1_Type;

/* ----------------------------------------------------------------------------
   -- matrix1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup matrix1_Register_Masks matrix1 Register Masks
 * @{
 */

/*! @name OFFSVEC0 - OffsetVector0 */
/*! @{ */

#define matrix1_OFFSVEC0_C1_MASK                 (0x1FFFU)
#define matrix1_OFFSVEC0_C1_SHIFT                (0U)
/*! C1 - C1 */
#define matrix1_OFFSVEC0_C1(x)                   (((uint32_t)(((uint32_t)(x)) << matrix1_OFFSVEC0_C1_SHIFT)) & matrix1_OFFSVEC0_C1_MASK)

#define matrix1_OFFSVEC0_C2_MASK                 (0x1FFF0000U)
#define matrix1_OFFSVEC0_C2_SHIFT                (16U)
/*! C2 - C2 */
#define matrix1_OFFSVEC0_C2(x)                   (((uint32_t)(((uint32_t)(x)) << matrix1_OFFSVEC0_C2_SHIFT)) & matrix1_OFFSVEC0_C2_MASK)
/*! @} */

/*! @name OFFSVEC1 - OffsetVector1 */
/*! @{ */

#define matrix1_OFFSVEC1_C3_MASK                 (0x1FFFU)
#define matrix1_OFFSVEC1_C3_SHIFT                (0U)
/*! C3 - C3 */
#define matrix1_OFFSVEC1_C3(x)                   (((uint32_t)(((uint32_t)(x)) << matrix1_OFFSVEC1_C3_SHIFT)) & matrix1_OFFSVEC1_C3_MASK)

#define matrix1_OFFSVEC1_C4_MASK                 (0x1FFF0000U)
#define matrix1_OFFSVEC1_C4_SHIFT                (16U)
/*! C4 - C4 */
#define matrix1_OFFSVEC1_C4(x)                   (((uint32_t)(((uint32_t)(x)) << matrix1_OFFSVEC1_C4_SHIFT)) & matrix1_OFFSVEC1_C4_MASK)
/*! @} */

/*! @name LASTCOW - LastControlWord */
/*! @{ */

#define matrix1_LASTCOW_LVAL_MASK                (0xFFFFFFFFU)
#define matrix1_LASTCOW_LVAL_SHIFT               (0U)
/*! LVAL - L_VAL */
#define matrix1_LASTCOW_LVAL(x)                  (((uint32_t)(((uint32_t)(x)) << matrix1_LASTCOW_LVAL_SHIFT)) & matrix1_LASTCOW_LVAL_MASK)
/*! @} */

/*! @name MATTYPE - MatrixType */
/*! @{ */

#define matrix1_MATTYPE_MatType_MASK             (0xFU)
#define matrix1_MATTYPE_MatType_SHIFT            (0U)
/*! MatType - MatrixType
 *  0b0000..Full matrix for pixel engine.
 *  0b0001..Reduced matrix for pixel engine.
 *  0b0010..Full matrix for display engine.
 *  0b0011..Reduced matrix for display engine.
 */
#define matrix1_MATTYPE_MatType(x)               (((uint32_t)(((uint32_t)(x)) << matrix1_MATTYPE_MatType_SHIFT)) & matrix1_MATTYPE_MatType_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group matrix1_Register_Masks */


/*!
 * @}
 */ /* end of group matrix1_Peripheral_Access_Layer */


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


#endif  /* PERI_MATRIX1_H_ */

