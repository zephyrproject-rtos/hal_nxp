/*
** ###################################################################
**     Processors:          MIMX9371xxVTx_ca55
**                          MIMX9371xxVTx_cm33
**                          MIMX9371xxVTx_cm7
**                          MIMX9373xxVTx_ca55
**                          MIMX9373xxVTx_cm33
**                          MIMX9373xxVTx_cm7
**                          MIMX9373xxVZx_ca55
**                          MIMX9373xxVZx_cm33
**                          MIMX9373xxVZx_cm7
**                          MIMX9375xxVTx_ca55
**                          MIMX9375xxVTx_cm33
**                          MIMX9375xxVTx_cm7
**                          MIMX9375xxVZx_ca55
**                          MIMX9375xxVZx_cm33
**                          MIMX9375xxVZx_cm7
**
**     Version:             rev. 1.0, 2026-04-09
**     Build:               b260624
**
**     Abstract:
**         CMSIS Peripheral Access Layer for matrixl3
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026-04-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_matrixl3.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for matrixl3
 *
 * CMSIS Peripheral Access Layer for matrixl3
 */

#if !defined(PERI_MATRIXL3_H_)
#define PERI_MATRIXL3_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9371xxVTx_ca55))
#include "MIMX9371_ca55_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm33))
#include "MIMX9371_cm33_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm7))
#include "MIMX9371_cm7_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_ca55) || defined(CPU_MIMX9373xxVZx_ca55))
#include "MIMX9373_ca55_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm33) || defined(CPU_MIMX9373xxVZx_cm33))
#include "MIMX9373_cm33_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm7) || defined(CPU_MIMX9373xxVZx_cm7))
#include "MIMX9373_cm7_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_ca55) || defined(CPU_MIMX9375xxVZx_ca55))
#include "MIMX9375_ca55_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm33) || defined(CPU_MIMX9375xxVZx_cm33))
#include "MIMX9375_cm33_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm7) || defined(CPU_MIMX9375xxVZx_cm7))
#include "MIMX9375_cm7_COMMON.h"
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
   -- matrixl3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup matrixl3_Peripheral_Access_Layer matrixl3 Peripheral Access Layer
 * @{
 */

/** matrixl3 - Register Layout Typedef */
typedef struct {
  __IO uint32_t OFFSVEC0;                          /**< OffsetVector0, offset: 0x0 */
  __IO uint32_t OFFSVEC1;                          /**< OffsetVector1, offset: 0x4 */
  __IO uint32_t MASKSTAR;                          /**< MaskStart, offset: 0x8 */
  __IO uint32_t MASKSIZE;                          /**< MaskSize, offset: 0xC */
  __I  uint32_t MATTYPE;                           /**< MatrixType, offset: 0x10 */
} matrixl3_Type;

/* ----------------------------------------------------------------------------
   -- matrixl3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup matrixl3_Register_Masks matrixl3 Register Masks
 * @{
 */

/*! @name OFFSVEC0 - OffsetVector0 */
/*! @{ */

#define matrixl3_OFFSVEC0_C1_MASK                (0x1FFFU)
#define matrixl3_OFFSVEC0_C1_SHIFT               (0U)
/*! C1 - C1 */
#define matrixl3_OFFSVEC0_C1(x)                  (((uint32_t)(((uint32_t)(x)) << matrixl3_OFFSVEC0_C1_SHIFT)) & matrixl3_OFFSVEC0_C1_MASK)

#define matrixl3_OFFSVEC0_C2_MASK                (0x1FFF0000U)
#define matrixl3_OFFSVEC0_C2_SHIFT               (16U)
/*! C2 - C2 */
#define matrixl3_OFFSVEC0_C2(x)                  (((uint32_t)(((uint32_t)(x)) << matrixl3_OFFSVEC0_C2_SHIFT)) & matrixl3_OFFSVEC0_C2_MASK)
/*! @} */

/*! @name OFFSVEC1 - OffsetVector1 */
/*! @{ */

#define matrixl3_OFFSVEC1_C3_MASK                (0x1FFFU)
#define matrixl3_OFFSVEC1_C3_SHIFT               (0U)
/*! C3 - C3 */
#define matrixl3_OFFSVEC1_C3(x)                  (((uint32_t)(((uint32_t)(x)) << matrixl3_OFFSVEC1_C3_SHIFT)) & matrixl3_OFFSVEC1_C3_MASK)
/*! @} */

/*! @name MASKSTAR - MaskStart */
/*! @{ */

#define matrixl3_MASKSTAR_passvst_MASK           (0x3FFFU)
#define matrixl3_MASKSTAR_passvst_SHIFT          (0U)
/*! passvst - pass_vstart */
#define matrixl3_MASKSTAR_passvst(x)             (((uint32_t)(((uint32_t)(x)) << matrixl3_MASKSTAR_passvst_SHIFT)) & matrixl3_MASKSTAR_passvst_MASK)

#define matrixl3_MASKSTAR_passhst_MASK           (0x3FFF0000U)
#define matrixl3_MASKSTAR_passhst_SHIFT          (16U)
/*! passhst - pass_hstart */
#define matrixl3_MASKSTAR_passhst(x)             (((uint32_t)(((uint32_t)(x)) << matrixl3_MASKSTAR_passhst_SHIFT)) & matrixl3_MASKSTAR_passhst_MASK)
/*! @} */

/*! @name MASKSIZE - MaskSize */
/*! @{ */

#define matrixl3_MASKSIZE_passvsi_MASK           (0x3FFFU)
#define matrixl3_MASKSIZE_passvsi_SHIFT          (0U)
/*! passvsi - pass_vsize */
#define matrixl3_MASKSIZE_passvsi(x)             (((uint32_t)(((uint32_t)(x)) << matrixl3_MASKSIZE_passvsi_SHIFT)) & matrixl3_MASKSIZE_passvsi_MASK)

#define matrixl3_MASKSIZE_passhsi_MASK           (0x3FFF0000U)
#define matrixl3_MASKSIZE_passhsi_SHIFT          (16U)
/*! passhsi - pass_hsize */
#define matrixl3_MASKSIZE_passhsi(x)             (((uint32_t)(((uint32_t)(x)) << matrixl3_MASKSIZE_passhsi_SHIFT)) & matrixl3_MASKSIZE_passhsi_MASK)
/*! @} */

/*! @name MATTYPE - MatrixType */
/*! @{ */

#define matrixl3_MATTYPE_MatType_MASK            (0xFU)
#define matrixl3_MATTYPE_MatType_SHIFT           (0U)
/*! MatType - MatrixType
 *  0b0000..Full matrix for pixel engine.
 *  0b0001..Reduced matrix for pixel engine.
 *  0b0010..Full matrix for display engine.
 *  0b0011..Reduced matrix for display engine.
 */
#define matrixl3_MATTYPE_MatType(x)              (((uint32_t)(((uint32_t)(x)) << matrixl3_MATTYPE_MatType_SHIFT)) & matrixl3_MATTYPE_MatType_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group matrixl3_Register_Masks */


/*!
 * @}
 */ /* end of group matrixl3_Peripheral_Access_Layer */


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


#endif  /* PERI_MATRIXL3_H_ */

