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
**         CMSIS Peripheral Access Layer for layerb3c
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
 * @file PERI_layerb3c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for layerb3c
 *
 * CMSIS Peripheral Access Layer for layerb3c
 */

#if !defined(PERI_LAYERB3C_H_)
#define PERI_LAYERB3C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- layerb3c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup layerb3c_Peripheral_Access_Layer layerb3c Peripheral Access Layer
 * @{
 */

/** layerb3c - Register Layout Typedef */
typedef struct {
  __O  uint32_t LAYBL3LU;                          /**< layerblend3_LockUnlock, offset: 0x0 */
  __I  uint32_t LAYBL3LS;                          /**< layerblend3_LockStatus, offset: 0x4 */
  __IO uint32_t LAYBL3D;                           /**< layerblend3_Dynamic, offset: 0x8 */
  __I  uint32_t LAYBL3S;                           /**< layerblend3_Status, offset: 0xC */
} layerb3c_Type;

/* ----------------------------------------------------------------------------
   -- layerb3c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup layerb3c_Register_Masks layerb3c Register Masks
 * @{
 */

/*! @name LAYBL3LU - layerblend3_LockUnlock */
/*! @{ */

#define layerb3c_LAYBL3LU_layb3LUn_MASK          (0xFFFFFFFFU)
#define layerb3c_LAYBL3LU_layb3LUn_SHIFT         (0U)
/*! layb3LUn - layerblend3_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define layerb3c_LAYBL3LU_layb3LUn(x)            (((uint32_t)(((uint32_t)(x)) << layerb3c_LAYBL3LU_layb3LUn_SHIFT)) & layerb3c_LAYBL3LU_layb3LUn_MASK)
/*! @} */

/*! @name LAYBL3LS - layerblend3_LockStatus */
/*! @{ */

#define layerb3c_LAYBL3LS_layb3LS_MASK           (0x1U)
#define layerb3c_LAYBL3LS_layb3LS_SHIFT          (0U)
/*! layb3LS - layerblend3_LockStatus */
#define layerb3c_LAYBL3LS_layb3LS(x)             (((uint32_t)(((uint32_t)(x)) << layerb3c_LAYBL3LS_layb3LS_SHIFT)) & layerb3c_LAYBL3LS_layb3LS_MASK)

#define layerb3c_LAYBL3LS_layb3PS_MASK           (0x10U)
#define layerb3c_LAYBL3LS_layb3PS_SHIFT          (4U)
/*! layb3PS - layerblend3_PrivilegeStatus */
#define layerb3c_LAYBL3LS_layb3PS(x)             (((uint32_t)(((uint32_t)(x)) << layerb3c_LAYBL3LS_layb3PS_SHIFT)) & layerb3c_LAYBL3LS_layb3PS_MASK)

#define layerb3c_LAYBL3LS_layb3FS_MASK           (0x100U)
#define layerb3c_LAYBL3LS_layb3FS_SHIFT          (8U)
/*! layb3FS - layerblend3_FreezeStatus */
#define layerb3c_LAYBL3LS_layb3FS(x)             (((uint32_t)(((uint32_t)(x)) << layerb3c_LAYBL3LS_layb3FS_SHIFT)) & layerb3c_LAYBL3LS_layb3FS_MASK)
/*! @} */

/*! @name LAYBL3D - layerblend3_Dynamic */
/*! @{ */

#define layerb3c_LAYBL3D_layb3pr_MASK            (0x3FU)
#define layerb3c_LAYBL3D_layb3pr_SHIFT           (0U)
/*! layb3pr - layerblend3_prim_sel
 *  0b000000..Unit layerblend3 input port prim is disabled
 *  0b001100..Unit layerblend3 input port prim is connected to output of unit constframe0
 *  0b001101..Unit layerblend3 input port prim is connected to output of unit constframe4
 *  0b010000..Unit layerblend3 input port prim is connected to output of unit constframe1
 *  0b010001..Unit layerblend3 input port prim is connected to output of unit constframe5
 *  0b010100..Unit layerblend3 input port prim is connected to output of unit layerblend1
 *  0b010101..Unit layerblend3 input port prim is connected to output of unit layerblend2
 */
#define layerb3c_LAYBL3D_layb3pr(x)              (((uint32_t)(((uint32_t)(x)) << layerb3c_LAYBL3D_layb3pr_SHIFT)) & layerb3c_LAYBL3D_layb3pr_MASK)

#define layerb3c_LAYBL3D_layb3sse_MASK           (0x3F00U)
#define layerb3c_LAYBL3D_layb3sse_SHIFT          (8U)
/*! layb3sse - layerblend3_sec_sel
 *  0b000000..Unit layerblend3 input port sec is disabled
 *  0b000101..Unit layerblend3 input port sec is connected to output of unit fetchrot9
 *  0b011001..Unit layerblend3 input port sec is connected to output of unit fetchlayer0
 *  0b011010..Unit layerblend3 input port sec is connected to output of unit fetchlayer1
 *  0b011011..Unit layerblend3 input port sec is connected to output of unit fetchyuv3
 *  0b011100..Unit layerblend3 input port sec is connected to output of unit fetchyuv0
 *  0b011110..Unit layerblend3 input port sec is connected to output of unit fetchyuv1
 *  0b100000..Unit layerblend3 input port sec is connected to output of unit matrix4
 *  0b100001..Unit layerblend3 input port sec is connected to output of unit hscaler4
 *  0b100010..Unit layerblend3 input port sec is connected to output of unit vscaler4
 */
#define layerb3c_LAYBL3D_layb3sse(x)             (((uint32_t)(((uint32_t)(x)) << layerb3c_LAYBL3D_layb3sse_SHIFT)) & layerb3c_LAYBL3D_layb3sse_MASK)

#define layerb3c_LAYBL3D_layb3cen_MASK           (0x3000000U)
#define layerb3c_LAYBL3D_layb3cen_SHIFT          (24U)
/*! layb3cen - layerblend3_clken
 *  0b00..Clock for layerblend3 is disabled
 *  0b01..Clock is enabled if unit is used, frequency is defined by the register setting for this pipeline (see [endpoint_name]_Static register)
 *  0b11..Clock for layerblend3 is without gating
 */
#define layerb3c_LAYBL3D_layb3cen(x)             (((uint32_t)(((uint32_t)(x)) << layerb3c_LAYBL3D_layb3cen_SHIFT)) & layerb3c_LAYBL3D_layb3cen_MASK)
/*! @} */

/*! @name LAYBL3S - layerblend3_Status */
/*! @{ */

#define layerb3c_LAYBL3S_layb3sel_MASK           (0x70000U)
#define layerb3c_LAYBL3S_layb3sel_SHIFT          (16U)
/*! layb3sel - layerblend3_sel
 *  0b000..layerblend3 module is not used
 *  0b001..layerblend3 module is used from store9 processing path
 *  0b010..layerblend3 module is used from extdst0 processing path
 *  0b011..layerblend3 module is used from extdst4 processing path
 *  0b100..layerblend3 module is used from extdst1 processing path
 *  0b101..layerblend3 module is used from extdst5 processing path
 */
#define layerb3c_LAYBL3S_layb3sel(x)             (((uint32_t)(((uint32_t)(x)) << layerb3c_LAYBL3S_layb3sel_SHIFT)) & layerb3c_LAYBL3S_layb3sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group layerb3c_Register_Masks */


/*!
 * @}
 */ /* end of group layerb3c_Peripheral_Access_Layer */


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


#endif  /* PERI_LAYERB3C_H_ */

