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
**         CMSIS Peripheral Access Layer for matrix9c
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
 * @file PERI_matrix9c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for matrix9c
 *
 * CMSIS Peripheral Access Layer for matrix9c
 */

#if !defined(PERI_MATRIX9C_H_)
#define PERI_MATRIX9C_H_                         /**< Symbol preventing repeated inclusion */

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

