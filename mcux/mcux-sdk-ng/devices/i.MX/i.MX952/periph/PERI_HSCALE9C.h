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
**         CMSIS Peripheral Access Layer for hscale9c
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
 * @file PERI_hscale9c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for hscale9c
 *
 * CMSIS Peripheral Access Layer for hscale9c
 */

#if !defined(PERI_HSCALE9C_H_)
#define PERI_HSCALE9C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- hscale9c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup hscale9c_Peripheral_Access_Layer hscale9c Peripheral Access Layer
 * @{
 */

/** hscale9c - Register Layout Typedef */
typedef struct {
  __O  uint32_t HSCAL9LU;                          /**< hscaler9_LockUnlock, offset: 0x0 */
  __I  uint32_t HSCAL9LS;                          /**< hscaler9_LockStatus, offset: 0x4 */
  __IO uint32_t HSCAL9D;                           /**< hscaler9_Dynamic, offset: 0x8 */
  __I  uint32_t HSCAL9S;                           /**< hscaler9_Status, offset: 0xC */
} hscale9c_Type;

/* ----------------------------------------------------------------------------
   -- hscale9c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup hscale9c_Register_Masks hscale9c Register Masks
 * @{
 */

/*! @name HSCAL9LU - hscaler9_LockUnlock */
/*! @{ */

#define hscale9c_HSCAL9LU_hsc9LUnl_MASK          (0xFFFFFFFFU)
#define hscale9c_HSCAL9LU_hsc9LUnl_SHIFT         (0U)
/*! hsc9LUnl - hscaler9_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define hscale9c_HSCAL9LU_hsc9LUnl(x)            (((uint32_t)(((uint32_t)(x)) << hscale9c_HSCAL9LU_hsc9LUnl_SHIFT)) & hscale9c_HSCAL9LU_hsc9LUnl_MASK)
/*! @} */

/*! @name HSCAL9LS - hscaler9_LockStatus */
/*! @{ */

#define hscale9c_HSCAL9LS_hsc9LS_MASK            (0x1U)
#define hscale9c_HSCAL9LS_hsc9LS_SHIFT           (0U)
/*! hsc9LS - hscaler9_LockStatus */
#define hscale9c_HSCAL9LS_hsc9LS(x)              (((uint32_t)(((uint32_t)(x)) << hscale9c_HSCAL9LS_hsc9LS_SHIFT)) & hscale9c_HSCAL9LS_hsc9LS_MASK)

#define hscale9c_HSCAL9LS_hsc9PS_MASK            (0x10U)
#define hscale9c_HSCAL9LS_hsc9PS_SHIFT           (4U)
/*! hsc9PS - hscaler9_PrivilegeStatus */
#define hscale9c_HSCAL9LS_hsc9PS(x)              (((uint32_t)(((uint32_t)(x)) << hscale9c_HSCAL9LS_hsc9PS_SHIFT)) & hscale9c_HSCAL9LS_hsc9PS_MASK)

#define hscale9c_HSCAL9LS_hsc9FS_MASK            (0x100U)
#define hscale9c_HSCAL9LS_hsc9FS_SHIFT           (8U)
/*! hsc9FS - hscaler9_FreezeStatus */
#define hscale9c_HSCAL9LS_hsc9FS(x)              (((uint32_t)(((uint32_t)(x)) << hscale9c_HSCAL9LS_hsc9FS_SHIFT)) & hscale9c_HSCAL9LS_hsc9FS_MASK)
/*! @} */

/*! @name HSCAL9D - hscaler9_Dynamic */
/*! @{ */

#define hscale9c_HSCAL9D_hsc9ssel_MASK           (0x3FU)
#define hscale9c_HSCAL9D_hsc9ssel_SHIFT          (0U)
/*! hsc9ssel - hscaler9_src_sel
 *  0b000000..Unit hscaler9 input port src is disabled
 *  0b000001..Unit hscaler9 input port src is connected to output of unit rop9
 *  0b000010..Unit hscaler9 input port src is connected to output of unit clut9
 *  0b000011..Unit hscaler9 input port src is connected to output of unit matrix9
 *  0b000100..Unit hscaler9 input port src is connected to output of unit blitblend9
 *  0b001001..Unit hscaler9 input port src is connected to output of unit vscaler9
 *  0b001010..Unit hscaler9 input port src is connected to output of unit filter9
 */
#define hscale9c_HSCAL9D_hsc9ssel(x)             (((uint32_t)(((uint32_t)(x)) << hscale9c_HSCAL9D_hsc9ssel_SHIFT)) & hscale9c_HSCAL9D_hsc9ssel_MASK)

#define hscale9c_HSCAL9D_hsc9cen_MASK            (0x3000000U)
#define hscale9c_HSCAL9D_hsc9cen_SHIFT           (24U)
/*! hsc9cen - hscaler9_clken
 *  0b00..Clock for hscaler9 is disabled
 *  0b01..Clock is enabled if unit is used, frequency is defined by the register setting for this pipeline (see [endpoint_name]_Static register)
 *  0b11..Clock for hscaler9 is without gating
 */
#define hscale9c_HSCAL9D_hsc9cen(x)              (((uint32_t)(((uint32_t)(x)) << hscale9c_HSCAL9D_hsc9cen_SHIFT)) & hscale9c_HSCAL9D_hsc9cen_MASK)
/*! @} */

/*! @name HSCAL9S - hscaler9_Status */
/*! @{ */

#define hscale9c_HSCAL9S_hsc9sel_MASK            (0x70000U)
#define hscale9c_HSCAL9S_hsc9sel_SHIFT           (16U)
/*! hsc9sel - hscaler9_sel
 *  0b000..hscaler9 module is not used
 *  0b001..hscaler9 module is used from store9 processing path
 *  0b010..hscaler9 module is used from extdst0 processing path
 *  0b011..hscaler9 module is used from extdst4 processing path
 *  0b100..hscaler9 module is used from extdst1 processing path
 *  0b101..hscaler9 module is used from extdst5 processing path
 */
#define hscale9c_HSCAL9S_hsc9sel(x)              (((uint32_t)(((uint32_t)(x)) << hscale9c_HSCAL9S_hsc9sel_SHIFT)) & hscale9c_HSCAL9S_hsc9sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group hscale9c_Register_Masks */


/*!
 * @}
 */ /* end of group hscale9c_Peripheral_Access_Layer */


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


#endif  /* PERI_HSCALE9C_H_ */

