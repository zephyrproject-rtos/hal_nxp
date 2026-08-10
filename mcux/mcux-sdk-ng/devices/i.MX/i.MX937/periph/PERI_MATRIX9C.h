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
**         CMSIS Peripheral Access Layer for matrix9c
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
 * @file PERI_matrix9c.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for matrix9c
 *
 * CMSIS Peripheral Access Layer for matrix9c
 */

#if !defined(PERI_MATRIX9C_H_)
#define PERI_MATRIX9C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- matrix9c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup matrix9c_Peripheral_Access_Layer matrix9c Peripheral Access Layer
 * @{
 */

/** matrix9c - Register Layout Typedef */
typedef struct {
  __O  uint32_t MAT9LU;                            /**< matrix9_LockUnlock, offset: 0x0 */
  __I  uint32_t MAT9LST;                           /**< matrix9_LockStatus, offset: 0x4 */
  __IO uint32_t MAT9D;                             /**< matrix9_Dynamic, offset: 0x8 */
  __I  uint32_t MAT9S;                             /**< matrix9_Status, offset: 0xC */
} matrix9c_Type;

/* ----------------------------------------------------------------------------
   -- matrix9c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup matrix9c_Register_Masks matrix9c Register Masks
 * @{
 */

/*! @name MAT9LU - matrix9_LockUnlock */
/*! @{ */

#define matrix9c_MAT9LU_mat9LUnl_MASK            (0xFFFFFFFFU)
#define matrix9c_MAT9LU_mat9LUnl_SHIFT           (0U)
/*! mat9LUnl - matrix9_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define matrix9c_MAT9LU_mat9LUnl(x)              (((uint32_t)(((uint32_t)(x)) << matrix9c_MAT9LU_mat9LUnl_SHIFT)) & matrix9c_MAT9LU_mat9LUnl_MASK)
/*! @} */

/*! @name MAT9LST - matrix9_LockStatus */
/*! @{ */

#define matrix9c_MAT9LST_mat9LS_MASK             (0x1U)
#define matrix9c_MAT9LST_mat9LS_SHIFT            (0U)
/*! mat9LS - matrix9_LockStatus */
#define matrix9c_MAT9LST_mat9LS(x)               (((uint32_t)(((uint32_t)(x)) << matrix9c_MAT9LST_mat9LS_SHIFT)) & matrix9c_MAT9LST_mat9LS_MASK)

#define matrix9c_MAT9LST_mat9PS_MASK             (0x10U)
#define matrix9c_MAT9LST_mat9PS_SHIFT            (4U)
/*! mat9PS - matrix9_PrivilegeStatus */
#define matrix9c_MAT9LST_mat9PS(x)               (((uint32_t)(((uint32_t)(x)) << matrix9c_MAT9LST_mat9PS_SHIFT)) & matrix9c_MAT9LST_mat9PS_MASK)

#define matrix9c_MAT9LST_mat9FS_MASK             (0x100U)
#define matrix9c_MAT9LST_mat9FS_SHIFT            (8U)
/*! mat9FS - matrix9_FreezeStatus */
#define matrix9c_MAT9LST_mat9FS(x)               (((uint32_t)(((uint32_t)(x)) << matrix9c_MAT9LST_mat9FS_SHIFT)) & matrix9c_MAT9LST_mat9FS_MASK)
/*! @} */

/*! @name MAT9D - matrix9_Dynamic */
/*! @{ */

#define matrix9c_MAT9D_mat9ssel_MASK             (0x3FU)
#define matrix9c_MAT9D_mat9ssel_SHIFT            (0U)
/*! mat9ssel - matrix9_src_sel
 *  0b000000..Unit matrix9 input port src is disabled
 *  0b000001..Unit matrix9 input port src is connected to output of unit rop9
 *  0b000010..Unit matrix9 input port src is connected to output of unit clut9
 *  0b000100..Unit matrix9 input port src is connected to output of unit blitblend9
 */
#define matrix9c_MAT9D_mat9ssel(x)               (((uint32_t)(((uint32_t)(x)) << matrix9c_MAT9D_mat9ssel_SHIFT)) & matrix9c_MAT9D_mat9ssel_MASK)

#define matrix9c_MAT9D_mat9cen_MASK              (0x3000000U)
#define matrix9c_MAT9D_mat9cen_SHIFT             (24U)
/*! mat9cen - matrix9_clken
 *  0b00..Clock for matrix9 is disabled
 *  0b01..Clock is enabled if unit is used, frequency is defined by the register setting for this pipeline (see [endpoint_name]_Static register)
 *  0b11..Clock for matrix9 is without gating
 */
#define matrix9c_MAT9D_mat9cen(x)                (((uint32_t)(((uint32_t)(x)) << matrix9c_MAT9D_mat9cen_SHIFT)) & matrix9c_MAT9D_mat9cen_MASK)
/*! @} */

/*! @name MAT9S - matrix9_Status */
/*! @{ */

#define matrix9c_MAT9S_mat9sel_MASK              (0x70000U)
#define matrix9c_MAT9S_mat9sel_SHIFT             (16U)
/*! mat9sel - matrix9_sel
 *  0b000..matrix9 module is not used
 *  0b001..matrix9 module is used from store9 processing path
 *  0b010..matrix9 module is used from extdst0 processing path
 *  0b011..matrix9 module is used from extdst4 processing path
 *  0b100..matrix9 module is used from extdst1 processing path
 *  0b101..matrix9 module is used from extdst5 processing path
 */
#define matrix9c_MAT9S_mat9sel(x)                (((uint32_t)(((uint32_t)(x)) << matrix9c_MAT9S_mat9sel_SHIFT)) & matrix9c_MAT9S_mat9sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group matrix9c_Register_Masks */


/*!
 * @}
 */ /* end of group matrix9c_Peripheral_Access_Layer */


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


#endif  /* PERI_MATRIX9C_H_ */

