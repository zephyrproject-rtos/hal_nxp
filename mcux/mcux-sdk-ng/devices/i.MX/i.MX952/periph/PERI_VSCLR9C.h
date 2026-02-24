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
**         CMSIS Peripheral Access Layer for vsclr9c
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
 * @file PERI_vsclr9c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for vsclr9c
 *
 * CMSIS Peripheral Access Layer for vsclr9c
 */

#if !defined(PERI_VSCLR9C_H_)
#define PERI_VSCLR9C_H_                          /**< Symbol preventing repeated inclusion */

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
   -- vsclr9c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup vsclr9c_Peripheral_Access_Layer vsclr9c Peripheral Access Layer
 * @{
 */

/** vsclr9c - Register Layout Typedef */
typedef struct {
  __O  uint32_t VSCA4LU;                           /**< vscaler4_LockUnlock, offset: 0x0 */
  __I  uint32_t VSCA4LS;                           /**< vscaler4_LockStatus, offset: 0x4 */
  __IO uint32_t VSCA4D;                            /**< vscaler4_Dynamic, offset: 0x8 */
  __I  uint32_t VSCA4S;                            /**< vscaler4_Status, offset: 0xC */
} vsclr9c_Type;

/* ----------------------------------------------------------------------------
   -- vsclr9c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup vsclr9c_Register_Masks vsclr9c Register Masks
 * @{
 */

/*! @name VSCA4LU - vscaler4_LockUnlock */
/*! @{ */

#define vsclr9c_VSCA4LU_vsc4LUnl_MASK            (0xFFFFFFFFU)
#define vsclr9c_VSCA4LU_vsc4LUnl_SHIFT           (0U)
/*! vsc4LUnl - vscaler4_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define vsclr9c_VSCA4LU_vsc4LUnl(x)              (((uint32_t)(((uint32_t)(x)) << vsclr9c_VSCA4LU_vsc4LUnl_SHIFT)) & vsclr9c_VSCA4LU_vsc4LUnl_MASK)
/*! @} */

/*! @name VSCA4LS - vscaler4_LockStatus */
/*! @{ */

#define vsclr9c_VSCA4LS_vsc4LS_MASK              (0x1U)
#define vsclr9c_VSCA4LS_vsc4LS_SHIFT             (0U)
/*! vsc4LS - vscaler4_LockStatus */
#define vsclr9c_VSCA4LS_vsc4LS(x)                (((uint32_t)(((uint32_t)(x)) << vsclr9c_VSCA4LS_vsc4LS_SHIFT)) & vsclr9c_VSCA4LS_vsc4LS_MASK)

#define vsclr9c_VSCA4LS_vsc4PS_MASK              (0x10U)
#define vsclr9c_VSCA4LS_vsc4PS_SHIFT             (4U)
/*! vsc4PS - vscaler4_PrivilegeStatus */
#define vsclr9c_VSCA4LS_vsc4PS(x)                (((uint32_t)(((uint32_t)(x)) << vsclr9c_VSCA4LS_vsc4PS_SHIFT)) & vsclr9c_VSCA4LS_vsc4PS_MASK)

#define vsclr9c_VSCA4LS_vsc4FS_MASK              (0x100U)
#define vsclr9c_VSCA4LS_vsc4FS_SHIFT             (8U)
/*! vsc4FS - vscaler4_FreezeStatus */
#define vsclr9c_VSCA4LS_vsc4FS(x)                (((uint32_t)(((uint32_t)(x)) << vsclr9c_VSCA4LS_vsc4FS_SHIFT)) & vsclr9c_VSCA4LS_vsc4FS_MASK)
/*! @} */

/*! @name VSCA4D - vscaler4_Dynamic */
/*! @{ */

#define vsclr9c_VSCA4D_vsc4ssel_MASK             (0x3FU)
#define vsclr9c_VSCA4D_vsc4ssel_SHIFT            (0U)
/*! vsc4ssel - vscaler4_src_sel
 *  0b000000..Unit vscaler4 input port src is disabled
 *  0b011011..Unit vscaler4 input port src is connected to output of unit fetchyuv3
 *  0b011100..Unit vscaler4 input port src is connected to output of unit fetchyuv0
 *  0b011110..Unit vscaler4 input port src is connected to output of unit fetchyuv1
 *  0b100000..Unit vscaler4 input port src is connected to output of unit matrix4
 *  0b100001..Unit vscaler4 input port src is connected to output of unit hscaler4
 */
#define vsclr9c_VSCA4D_vsc4ssel(x)               (((uint32_t)(((uint32_t)(x)) << vsclr9c_VSCA4D_vsc4ssel_SHIFT)) & vsclr9c_VSCA4D_vsc4ssel_MASK)

#define vsclr9c_VSCA4D_vsc4cen_MASK              (0x3000000U)
#define vsclr9c_VSCA4D_vsc4cen_SHIFT             (24U)
/*! vsc4cen - vscaler4_clken
 *  0b00..Clock for vscaler4 is disabled
 *  0b01..Clock is enabled if unit is used, frequency is defined by the register setting for this pipeline (see [endpoint_name]_Static register)
 *  0b11..Clock for vscaler4 is without gating
 */
#define vsclr9c_VSCA4D_vsc4cen(x)                (((uint32_t)(((uint32_t)(x)) << vsclr9c_VSCA4D_vsc4cen_SHIFT)) & vsclr9c_VSCA4D_vsc4cen_MASK)
/*! @} */

/*! @name VSCA4S - vscaler4_Status */
/*! @{ */

#define vsclr9c_VSCA4S_vsc4sel_MASK              (0x70000U)
#define vsclr9c_VSCA4S_vsc4sel_SHIFT             (16U)
/*! vsc4sel - vscaler4_sel
 *  0b000..vscaler4 module is not used
 *  0b001..vscaler4 module is used from store9 processing path
 *  0b010..vscaler4 module is used from extdst0 processing path
 *  0b011..vscaler4 module is used from extdst4 processing path
 *  0b100..vscaler4 module is used from extdst1 processing path
 *  0b101..vscaler4 module is used from extdst5 processing path
 */
#define vsclr9c_VSCA4S_vsc4sel(x)                (((uint32_t)(((uint32_t)(x)) << vsclr9c_VSCA4S_vsc4sel_SHIFT)) & vsclr9c_VSCA4S_vsc4sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group vsclr9c_Register_Masks */


/*!
 * @}
 */ /* end of group vsclr9c_Peripheral_Access_Layer */


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


#endif  /* PERI_VSCLR9C_H_ */

