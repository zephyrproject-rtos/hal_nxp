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
**         CMSIS Peripheral Access Layer for hscale4c
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
 * @file PERI_hscale4c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for hscale4c
 *
 * CMSIS Peripheral Access Layer for hscale4c
 */

#if !defined(PERI_HSCALE4C_H_)
#define PERI_HSCALE4C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- hscale4c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup hscale4c_Peripheral_Access_Layer hscale4c Peripheral Access Layer
 * @{
 */

/** hscale4c - Register Layout Typedef */
typedef struct {
  __O  uint32_t HSCAL4LU;                          /**< hscaler4_LockUnlock, offset: 0x0 */
  __I  uint32_t HSCAL4LS;                          /**< hscaler4_LockStatus, offset: 0x4 */
  __IO uint32_t HSCAL4D;                           /**< hscaler4_Dynamic, offset: 0x8 */
  __I  uint32_t HSCAL4S;                           /**< hscaler4_Status, offset: 0xC */
} hscale4c_Type;

/* ----------------------------------------------------------------------------
   -- hscale4c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup hscale4c_Register_Masks hscale4c Register Masks
 * @{
 */

/*! @name HSCAL4LU - hscaler4_LockUnlock */
/*! @{ */

#define hscale4c_HSCAL4LU_hsc4LUnl_MASK          (0xFFFFFFFFU)
#define hscale4c_HSCAL4LU_hsc4LUnl_SHIFT         (0U)
/*! hsc4LUnl - hscaler4_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define hscale4c_HSCAL4LU_hsc4LUnl(x)            (((uint32_t)(((uint32_t)(x)) << hscale4c_HSCAL4LU_hsc4LUnl_SHIFT)) & hscale4c_HSCAL4LU_hsc4LUnl_MASK)
/*! @} */

/*! @name HSCAL4LS - hscaler4_LockStatus */
/*! @{ */

#define hscale4c_HSCAL4LS_hsc4LS_MASK            (0x1U)
#define hscale4c_HSCAL4LS_hsc4LS_SHIFT           (0U)
/*! hsc4LS - hscaler4_LockStatus */
#define hscale4c_HSCAL4LS_hsc4LS(x)              (((uint32_t)(((uint32_t)(x)) << hscale4c_HSCAL4LS_hsc4LS_SHIFT)) & hscale4c_HSCAL4LS_hsc4LS_MASK)

#define hscale4c_HSCAL4LS_hsc4PS_MASK            (0x10U)
#define hscale4c_HSCAL4LS_hsc4PS_SHIFT           (4U)
/*! hsc4PS - hscaler4_PrivilegeStatus */
#define hscale4c_HSCAL4LS_hsc4PS(x)              (((uint32_t)(((uint32_t)(x)) << hscale4c_HSCAL4LS_hsc4PS_SHIFT)) & hscale4c_HSCAL4LS_hsc4PS_MASK)

#define hscale4c_HSCAL4LS_hsc4FS_MASK            (0x100U)
#define hscale4c_HSCAL4LS_hsc4FS_SHIFT           (8U)
/*! hsc4FS - hscaler4_FreezeStatus */
#define hscale4c_HSCAL4LS_hsc4FS(x)              (((uint32_t)(((uint32_t)(x)) << hscale4c_HSCAL4LS_hsc4FS_SHIFT)) & hscale4c_HSCAL4LS_hsc4FS_MASK)
/*! @} */

/*! @name HSCAL4D - hscaler4_Dynamic */
/*! @{ */

#define hscale4c_HSCAL4D_hsc4ssel_MASK           (0x3FU)
#define hscale4c_HSCAL4D_hsc4ssel_SHIFT          (0U)
/*! hsc4ssel - hscaler4_src_sel
 *  0b000000..Unit hscaler4 input port src is disabled
 *  0b011011..Unit hscaler4 input port src is connected to output of unit fetchyuv3
 *  0b011100..Unit hscaler4 input port src is connected to output of unit fetchyuv0
 *  0b011110..Unit hscaler4 input port src is connected to output of unit fetchyuv1
 *  0b100000..Unit hscaler4 input port src is connected to output of unit matrix4
 *  0b100010..Unit hscaler4 input port src is connected to output of unit vscaler4
 */
#define hscale4c_HSCAL4D_hsc4ssel(x)             (((uint32_t)(((uint32_t)(x)) << hscale4c_HSCAL4D_hsc4ssel_SHIFT)) & hscale4c_HSCAL4D_hsc4ssel_MASK)

#define hscale4c_HSCAL4D_hsc4cen_MASK            (0x3000000U)
#define hscale4c_HSCAL4D_hsc4cen_SHIFT           (24U)
/*! hsc4cen - hscaler4_clken
 *  0b00..Clock for hscaler4 is disabled
 *  0b01..Clock is enabled if unit is used, frequency is defined by the register setting for this pipeline (see [endpoint_name]_Static register)
 *  0b11..Clock for hscaler4 is without gating
 */
#define hscale4c_HSCAL4D_hsc4cen(x)              (((uint32_t)(((uint32_t)(x)) << hscale4c_HSCAL4D_hsc4cen_SHIFT)) & hscale4c_HSCAL4D_hsc4cen_MASK)
/*! @} */

/*! @name HSCAL4S - hscaler4_Status */
/*! @{ */

#define hscale4c_HSCAL4S_hsc4sel_MASK            (0x70000U)
#define hscale4c_HSCAL4S_hsc4sel_SHIFT           (16U)
/*! hsc4sel - hscaler4_sel
 *  0b000..hscaler4 module is not used
 *  0b001..hscaler4 module is used from store9 processing path
 *  0b010..hscaler4 module is used from extdst0 processing path
 *  0b011..hscaler4 module is used from extdst4 processing path
 *  0b100..hscaler4 module is used from extdst1 processing path
 *  0b101..hscaler4 module is used from extdst5 processing path
 */
#define hscale4c_HSCAL4S_hsc4sel(x)              (((uint32_t)(((uint32_t)(x)) << hscale4c_HSCAL4S_hsc4sel_SHIFT)) & hscale4c_HSCAL4S_hsc4sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group hscale4c_Register_Masks */


/*!
 * @}
 */ /* end of group hscale4c_Peripheral_Access_Layer */


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


#endif  /* PERI_HSCALE4C_H_ */

