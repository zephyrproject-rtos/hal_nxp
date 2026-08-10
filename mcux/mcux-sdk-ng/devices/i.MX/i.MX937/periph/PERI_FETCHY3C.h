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
**         CMSIS Peripheral Access Layer for fetchy3c
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
 * @file PERI_fetchy3c.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for fetchy3c
 *
 * CMSIS Peripheral Access Layer for fetchy3c
 */

#if !defined(PERI_FETCHY3C_H_)
#define PERI_FETCHY3C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchy3c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchy3c_Peripheral_Access_Layer fetchy3c Peripheral Access Layer
 * @{
 */

/** fetchy3c - Register Layout Typedef */
typedef struct {
  __O  uint32_t FEYUV3LU;                          /**< fetchyuv3_LockUnlock, offset: 0x0 */
  __I  uint32_t FEYUV3LS;                          /**< fetchyuv3_LockStatus, offset: 0x4 */
  __IO uint32_t FEYUV3D;                           /**< fetchyuv3_Dynamic, offset: 0x8 */
  __I  uint32_t FEYUV3S;                           /**< fetchyuv3_Status, offset: 0xC */
} fetchy3c_Type;

/* ----------------------------------------------------------------------------
   -- fetchy3c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchy3c_Register_Masks fetchy3c Register Masks
 * @{
 */

/*! @name FEYUV3LU - fetchyuv3_LockUnlock */
/*! @{ */

#define fetchy3c_FEYUV3LU_fety3LU_MASK           (0xFFFFFFFFU)
#define fetchy3c_FEYUV3LU_fety3LU_SHIFT          (0U)
/*! fety3LU - fetchyuv3_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define fetchy3c_FEYUV3LU_fety3LU(x)             (((uint32_t)(((uint32_t)(x)) << fetchy3c_FEYUV3LU_fety3LU_SHIFT)) & fetchy3c_FEYUV3LU_fety3LU_MASK)
/*! @} */

/*! @name FEYUV3LS - fetchyuv3_LockStatus */
/*! @{ */

#define fetchy3c_FEYUV3LS_fety3LS_MASK           (0x1U)
#define fetchy3c_FEYUV3LS_fety3LS_SHIFT          (0U)
/*! fety3LS - fetchyuv3_LockStatus */
#define fetchy3c_FEYUV3LS_fety3LS(x)             (((uint32_t)(((uint32_t)(x)) << fetchy3c_FEYUV3LS_fety3LS_SHIFT)) & fetchy3c_FEYUV3LS_fety3LS_MASK)

#define fetchy3c_FEYUV3LS_fety3PS_MASK           (0x10U)
#define fetchy3c_FEYUV3LS_fety3PS_SHIFT          (4U)
/*! fety3PS - fetchyuv3_PrivilegeStatus */
#define fetchy3c_FEYUV3LS_fety3PS(x)             (((uint32_t)(((uint32_t)(x)) << fetchy3c_FEYUV3LS_fety3PS_SHIFT)) & fetchy3c_FEYUV3LS_fety3PS_MASK)

#define fetchy3c_FEYUV3LS_fety3FS_MASK           (0x100U)
#define fetchy3c_FEYUV3LS_fety3FS_SHIFT          (8U)
/*! fety3FS - fetchyuv3_FreezeStatus */
#define fetchy3c_FEYUV3LS_fety3FS(x)             (((uint32_t)(((uint32_t)(x)) << fetchy3c_FEYUV3LS_fety3FS_SHIFT)) & fetchy3c_FEYUV3LS_fety3FS_MASK)
/*! @} */

/*! @name FEYUV3D - fetchyuv3_Dynamic */
/*! @{ */

#define fetchy3c_FEYUV3D_fety3scl_MASK           (0x3FU)
#define fetchy3c_FEYUV3D_fety3scl_SHIFT          (0U)
/*! fety3scl - fetchyuv3_src_sel
 *  0b000000..Unit fetchyuv3 input port src is disabled
 *  0b000111..Unit fetchyuv3 input port src is connected to output of unit fetcheco9
 */
#define fetchy3c_FEYUV3D_fety3scl(x)             (((uint32_t)(((uint32_t)(x)) << fetchy3c_FEYUV3D_fety3scl_SHIFT)) & fetchy3c_FEYUV3D_fety3scl_MASK)

#define fetchy3c_FEYUV3D_fety3ssl_MASK           (0x3F00U)
#define fetchy3c_FEYUV3D_fety3ssl_SHIFT          (8U)
/*! fety3ssl - fetchyuv3_sec_sel
 *  0b000000..Unit fetchyuv3 input port sec is disabled
 *  0b011110..Unit fetchyuv3 input port sec is connected to output of unit fetchyuv1
 */
#define fetchy3c_FEYUV3D_fety3ssl(x)             (((uint32_t)(((uint32_t)(x)) << fetchy3c_FEYUV3D_fety3ssl_SHIFT)) & fetchy3c_FEYUV3D_fety3ssl_MASK)
/*! @} */

/*! @name FEYUV3S - fetchyuv3_Status */
/*! @{ */

#define fetchy3c_FEYUV3S_fety3sel_MASK           (0x70000U)
#define fetchy3c_FEYUV3S_fety3sel_SHIFT          (16U)
/*! fety3sel - fetchyuv3_sel
 *  0b000..fetchyuv3 module is not used
 *  0b001..fetchyuv3 module is used from store9 processing path
 *  0b010..fetchyuv3 module is used from extdst0 processing path
 *  0b011..fetchyuv3 module is used from extdst4 processing path
 *  0b100..fetchyuv3 module is used from extdst1 processing path
 *  0b101..fetchyuv3 module is used from extdst5 processing path
 */
#define fetchy3c_FEYUV3S_fety3sel(x)             (((uint32_t)(((uint32_t)(x)) << fetchy3c_FEYUV3S_fety3sel_SHIFT)) & fetchy3c_FEYUV3S_fety3sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchy3c_Register_Masks */


/*!
 * @}
 */ /* end of group fetchy3c_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHY3C_H_ */

