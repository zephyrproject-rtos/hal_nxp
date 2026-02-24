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
**         CMSIS Peripheral Access Layer for layerb5c
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
 * @file PERI_layerb5c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for layerb5c
 *
 * CMSIS Peripheral Access Layer for layerb5c
 */

#if !defined(PERI_LAYERB5C_H_)
#define PERI_LAYERB5C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- layerb5c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup layerb5c_Peripheral_Access_Layer layerb5c Peripheral Access Layer
 * @{
 */

/** layerb5c - Register Layout Typedef */
typedef struct {
  __O  uint32_t LAYBL5LU;                          /**< layerblend5_LockUnlock, offset: 0x0 */
  __I  uint32_t LAYBL5LS;                          /**< layerblend5_LockStatus, offset: 0x4 */
  __IO uint32_t LAYBL5D;                           /**< layerblend5_Dynamic, offset: 0x8 */
  __I  uint32_t LAYBL5S;                           /**< layerblend5_Status, offset: 0xC */
} layerb5c_Type;

/* ----------------------------------------------------------------------------
   -- layerb5c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup layerb5c_Register_Masks layerb5c Register Masks
 * @{
 */

/*! @name LAYBL5LU - layerblend5_LockUnlock */
/*! @{ */

#define layerb5c_LAYBL5LU_layb5LUn_MASK          (0xFFFFFFFFU)
#define layerb5c_LAYBL5LU_layb5LUn_SHIFT         (0U)
/*! layb5LUn - layerblend5_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define layerb5c_LAYBL5LU_layb5LUn(x)            (((uint32_t)(((uint32_t)(x)) << layerb5c_LAYBL5LU_layb5LUn_SHIFT)) & layerb5c_LAYBL5LU_layb5LUn_MASK)
/*! @} */

/*! @name LAYBL5LS - layerblend5_LockStatus */
/*! @{ */

#define layerb5c_LAYBL5LS_layb5LS_MASK           (0x1U)
#define layerb5c_LAYBL5LS_layb5LS_SHIFT          (0U)
/*! layb5LS - layerblend5_LockStatus */
#define layerb5c_LAYBL5LS_layb5LS(x)             (((uint32_t)(((uint32_t)(x)) << layerb5c_LAYBL5LS_layb5LS_SHIFT)) & layerb5c_LAYBL5LS_layb5LS_MASK)

#define layerb5c_LAYBL5LS_layb5PS_MASK           (0x10U)
#define layerb5c_LAYBL5LS_layb5PS_SHIFT          (4U)
/*! layb5PS - layerblend5_PrivilegeStatus */
#define layerb5c_LAYBL5LS_layb5PS(x)             (((uint32_t)(((uint32_t)(x)) << layerb5c_LAYBL5LS_layb5PS_SHIFT)) & layerb5c_LAYBL5LS_layb5PS_MASK)

#define layerb5c_LAYBL5LS_layb5FS_MASK           (0x100U)
#define layerb5c_LAYBL5LS_layb5FS_SHIFT          (8U)
/*! layb5FS - layerblend5_FreezeStatus */
#define layerb5c_LAYBL5LS_layb5FS(x)             (((uint32_t)(((uint32_t)(x)) << layerb5c_LAYBL5LS_layb5FS_SHIFT)) & layerb5c_LAYBL5LS_layb5FS_MASK)
/*! @} */

/*! @name LAYBL5D - layerblend5_Dynamic */
/*! @{ */

#define layerb5c_LAYBL5D_layb5pr_MASK            (0x3FU)
#define layerb5c_LAYBL5D_layb5pr_SHIFT           (0U)
/*! layb5pr - layerblend5_prim_sel
 *  0b000000..Unit layerblend5 input port prim is disabled
 *  0b001100..Unit layerblend5 input port prim is connected to output of unit constframe0
 *  0b001101..Unit layerblend5 input port prim is connected to output of unit constframe4
 *  0b010000..Unit layerblend5 input port prim is connected to output of unit constframe1
 *  0b010001..Unit layerblend5 input port prim is connected to output of unit constframe5
 *  0b010100..Unit layerblend5 input port prim is connected to output of unit layerblend1
 *  0b010101..Unit layerblend5 input port prim is connected to output of unit layerblend2
 *  0b010110..Unit layerblend5 input port prim is connected to output of unit layerblend3
 *  0b010111..Unit layerblend5 input port prim is connected to output of unit layerblend4
 */
#define layerb5c_LAYBL5D_layb5pr(x)              (((uint32_t)(((uint32_t)(x)) << layerb5c_LAYBL5D_layb5pr_SHIFT)) & layerb5c_LAYBL5D_layb5pr_MASK)

#define layerb5c_LAYBL5D_layb5sse_MASK           (0x3F00U)
#define layerb5c_LAYBL5D_layb5sse_SHIFT          (8U)
/*! layb5sse - layerblend5_sec_sel
 *  0b000000..Unit layerblend5 input port sec is disabled
 *  0b000101..Unit layerblend5 input port sec is connected to output of unit fetchrot9
 *  0b011001..Unit layerblend5 input port sec is connected to output of unit fetchlayer0
 *  0b011010..Unit layerblend5 input port sec is connected to output of unit fetchlayer1
 *  0b011011..Unit layerblend5 input port sec is connected to output of unit fetchyuv3
 *  0b011100..Unit layerblend5 input port sec is connected to output of unit fetchyuv0
 *  0b011110..Unit layerblend5 input port sec is connected to output of unit fetchyuv1
 *  0b100000..Unit layerblend5 input port sec is connected to output of unit matrix4
 *  0b100001..Unit layerblend5 input port sec is connected to output of unit hscaler4
 *  0b100010..Unit layerblend5 input port sec is connected to output of unit vscaler4
 */
#define layerb5c_LAYBL5D_layb5sse(x)             (((uint32_t)(((uint32_t)(x)) << layerb5c_LAYBL5D_layb5sse_SHIFT)) & layerb5c_LAYBL5D_layb5sse_MASK)

#define layerb5c_LAYBL5D_layb5en_MASK            (0x3000000U)
#define layerb5c_LAYBL5D_layb5en_SHIFT           (24U)
/*! layb5en - layerblend5_clken
 *  0b00..Clock for layerblend5 is disabled
 *  0b01..Clock is enabled if unit is used, frequency is defined by the register setting for this pipeline (see [endpoint_name]_Static register)
 *  0b11..Clock for layerblend5 is without gating
 */
#define layerb5c_LAYBL5D_layb5en(x)              (((uint32_t)(((uint32_t)(x)) << layerb5c_LAYBL5D_layb5en_SHIFT)) & layerb5c_LAYBL5D_layb5en_MASK)
/*! @} */

/*! @name LAYBL5S - layerblend5_Status */
/*! @{ */

#define layerb5c_LAYBL5S_layb5sel_MASK           (0x70000U)
#define layerb5c_LAYBL5S_layb5sel_SHIFT          (16U)
/*! layb5sel - layerblend5_sel
 *  0b000..layerblend5 module is not used
 *  0b001..layerblend5 module is used from store9 processing path
 *  0b010..layerblend5 module is used from extdst0 processing path
 *  0b011..layerblend5 module is used from extdst4 processing path
 *  0b100..layerblend5 module is used from extdst1 processing path
 *  0b101..layerblend5 module is used from extdst5 processing path
 */
#define layerb5c_LAYBL5S_layb5sel(x)             (((uint32_t)(((uint32_t)(x)) << layerb5c_LAYBL5S_layb5sel_SHIFT)) & layerb5c_LAYBL5S_layb5sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group layerb5c_Register_Masks */


/*!
 * @}
 */ /* end of group layerb5c_Peripheral_Access_Layer */


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


#endif  /* PERI_LAYERB5C_H_ */

