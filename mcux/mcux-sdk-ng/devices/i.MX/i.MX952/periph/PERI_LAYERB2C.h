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
**         CMSIS Peripheral Access Layer for layerb2c
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
 * @file PERI_layerb2c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for layerb2c
 *
 * CMSIS Peripheral Access Layer for layerb2c
 */

#if !defined(PERI_LAYERB2C_H_)
#define PERI_LAYERB2C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- layerb2c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup layerb2c_Peripheral_Access_Layer layerb2c Peripheral Access Layer
 * @{
 */

/** layerb2c - Register Layout Typedef */
typedef struct {
  __O  uint32_t LAYBL2LU;                          /**< layerblend2_LockUnlock, offset: 0x0 */
  __I  uint32_t LAYBL2LS;                          /**< layerblend2_LockStatus, offset: 0x4 */
  __IO uint32_t LAYBL2D;                           /**< layerblend2_Dynamic, offset: 0x8 */
  __I  uint32_t LAYBL2S;                           /**< layerblend2_Status, offset: 0xC */
} layerb2c_Type;

/* ----------------------------------------------------------------------------
   -- layerb2c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup layerb2c_Register_Masks layerb2c Register Masks
 * @{
 */

/*! @name LAYBL2LU - layerblend2_LockUnlock */
/*! @{ */

#define layerb2c_LAYBL2LU_layb2LU_MASK           (0xFFFFFFFFU)
#define layerb2c_LAYBL2LU_layb2LU_SHIFT          (0U)
/*! layb2LU - layerblend2_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define layerb2c_LAYBL2LU_layb2LU(x)             (((uint32_t)(((uint32_t)(x)) << layerb2c_LAYBL2LU_layb2LU_SHIFT)) & layerb2c_LAYBL2LU_layb2LU_MASK)
/*! @} */

/*! @name LAYBL2LS - layerblend2_LockStatus */
/*! @{ */

#define layerb2c_LAYBL2LS_layb2LS_MASK           (0x1U)
#define layerb2c_LAYBL2LS_layb2LS_SHIFT          (0U)
/*! layb2LS - layerblend2_LockStatus */
#define layerb2c_LAYBL2LS_layb2LS(x)             (((uint32_t)(((uint32_t)(x)) << layerb2c_LAYBL2LS_layb2LS_SHIFT)) & layerb2c_LAYBL2LS_layb2LS_MASK)

#define layerb2c_LAYBL2LS_layb2PS_MASK           (0x10U)
#define layerb2c_LAYBL2LS_layb2PS_SHIFT          (4U)
/*! layb2PS - layerblend2_PrivilegeStatus */
#define layerb2c_LAYBL2LS_layb2PS(x)             (((uint32_t)(((uint32_t)(x)) << layerb2c_LAYBL2LS_layb2PS_SHIFT)) & layerb2c_LAYBL2LS_layb2PS_MASK)

#define layerb2c_LAYBL2LS_layb2FS_MASK           (0x100U)
#define layerb2c_LAYBL2LS_layb2FS_SHIFT          (8U)
/*! layb2FS - layerblend2_FreezeStatus */
#define layerb2c_LAYBL2LS_layb2FS(x)             (((uint32_t)(((uint32_t)(x)) << layerb2c_LAYBL2LS_layb2FS_SHIFT)) & layerb2c_LAYBL2LS_layb2FS_MASK)
/*! @} */

/*! @name LAYBL2D - layerblend2_Dynamic */
/*! @{ */

#define layerb2c_LAYBL2D_layb2pr_MASK            (0x3FU)
#define layerb2c_LAYBL2D_layb2pr_SHIFT           (0U)
/*! layb2pr - layerblend2_prim_sel
 *  0b000000..Unit layerblend2 input port prim is disabled
 *  0b001100..Unit layerblend2 input port prim is connected to output of unit constframe0
 *  0b001101..Unit layerblend2 input port prim is connected to output of unit constframe4
 *  0b010000..Unit layerblend2 input port prim is connected to output of unit constframe1
 *  0b010001..Unit layerblend2 input port prim is connected to output of unit constframe5
 *  0b010100..Unit layerblend2 input port prim is connected to output of unit layerblend1
 */
#define layerb2c_LAYBL2D_layb2pr(x)              (((uint32_t)(((uint32_t)(x)) << layerb2c_LAYBL2D_layb2pr_SHIFT)) & layerb2c_LAYBL2D_layb2pr_MASK)

#define layerb2c_LAYBL2D_layb2ss_MASK            (0x3F00U)
#define layerb2c_LAYBL2D_layb2ss_SHIFT           (8U)
/*! layb2ss - layerblend2_sec_sel
 *  0b000000..Unit layerblend2 input port sec is disabled
 *  0b000101..Unit layerblend2 input port sec is connected to output of unit fetchrot9
 *  0b011001..Unit layerblend2 input port sec is connected to output of unit fetchlayer0
 *  0b011010..Unit layerblend2 input port sec is connected to output of unit fetchlayer1
 *  0b011011..Unit layerblend2 input port sec is connected to output of unit fetchyuv3
 *  0b011100..Unit layerblend2 input port sec is connected to output of unit fetchyuv0
 *  0b011110..Unit layerblend2 input port sec is connected to output of unit fetchyuv1
 *  0b100000..Unit layerblend2 input port sec is connected to output of unit matrix4
 *  0b100001..Unit layerblend2 input port sec is connected to output of unit hscaler4
 *  0b100010..Unit layerblend2 input port sec is connected to output of unit vscaler4
 */
#define layerb2c_LAYBL2D_layb2ss(x)              (((uint32_t)(((uint32_t)(x)) << layerb2c_LAYBL2D_layb2ss_SHIFT)) & layerb2c_LAYBL2D_layb2ss_MASK)

#define layerb2c_LAYBL2D_layblce_MASK            (0x3000000U)
#define layerb2c_LAYBL2D_layblce_SHIFT           (24U)
/*! layblce - layerblend2_clken
 *  0b00..Clock for layerblend2 is disabled
 *  0b01..Clock is enabled if unit is used, frequency is defined by the register setting for this pipeline (see [endpoint_name]_Static register)
 *  0b11..Clock for layerblend2 is without gating
 */
#define layerb2c_LAYBL2D_layblce(x)              (((uint32_t)(((uint32_t)(x)) << layerb2c_LAYBL2D_layblce_SHIFT)) & layerb2c_LAYBL2D_layblce_MASK)
/*! @} */

/*! @name LAYBL2S - layerblend2_Status */
/*! @{ */

#define layerb2c_LAYBL2S_layb2se_MASK            (0x70000U)
#define layerb2c_LAYBL2S_layb2se_SHIFT           (16U)
/*! layb2se - layerblend2_sel
 *  0b000..layerblend2 module is not used
 *  0b001..layerblend2 module is used from store9 processing path
 *  0b010..layerblend2 module is used from extdst0 processing path
 *  0b011..layerblend2 module is used from extdst4 processing path
 *  0b100..layerblend2 module is used from extdst1 processing path
 *  0b101..layerblend2 module is used from extdst5 processing path
 */
#define layerb2c_LAYBL2S_layb2se(x)              (((uint32_t)(((uint32_t)(x)) << layerb2c_LAYBL2S_layb2se_SHIFT)) & layerb2c_LAYBL2S_layb2se_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group layerb2c_Register_Masks */


/*!
 * @}
 */ /* end of group layerb2c_Peripheral_Access_Layer */


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


#endif  /* PERI_LAYERB2C_H_ */

