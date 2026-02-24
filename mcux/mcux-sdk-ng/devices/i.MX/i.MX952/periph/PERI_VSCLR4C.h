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
**         CMSIS Peripheral Access Layer for vsclr4c
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
 * @file PERI_vsclr4c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for vsclr4c
 *
 * CMSIS Peripheral Access Layer for vsclr4c
 */

#if !defined(PERI_VSCLR4C_H_)
#define PERI_VSCLR4C_H_                          /**< Symbol preventing repeated inclusion */

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
   -- vsclr4c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup vsclr4c_Peripheral_Access_Layer vsclr4c Peripheral Access Layer
 * @{
 */

/** vsclr4c - Register Layout Typedef */
typedef struct {
  __O  uint32_t VSCA9LU;                           /**< vscaler9_LockUnlock, offset: 0x0 */
  __I  uint32_t VSCA9LS;                           /**< vscaler9_LockStatus, offset: 0x4 */
  __IO uint32_t VSCA9D;                            /**< vscaler9_Dynamic, offset: 0x8 */
  __I  uint32_t VSCA9S;                            /**< vscaler9_Status, offset: 0xC */
} vsclr4c_Type;

/* ----------------------------------------------------------------------------
   -- vsclr4c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup vsclr4c_Register_Masks vsclr4c Register Masks
 * @{
 */

/*! @name VSCA9LU - vscaler9_LockUnlock */
/*! @{ */

#define vsclr4c_VSCA9LU_vsc9LUnl_MASK            (0xFFFFFFFFU)
#define vsclr4c_VSCA9LU_vsc9LUnl_SHIFT           (0U)
/*! vsc9LUnl - vscaler9_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define vsclr4c_VSCA9LU_vsc9LUnl(x)              (((uint32_t)(((uint32_t)(x)) << vsclr4c_VSCA9LU_vsc9LUnl_SHIFT)) & vsclr4c_VSCA9LU_vsc9LUnl_MASK)
/*! @} */

/*! @name VSCA9LS - vscaler9_LockStatus */
/*! @{ */

#define vsclr4c_VSCA9LS_vsc9LS_MASK              (0x1U)
#define vsclr4c_VSCA9LS_vsc9LS_SHIFT             (0U)
/*! vsc9LS - vscaler9_LockStatus */
#define vsclr4c_VSCA9LS_vsc9LS(x)                (((uint32_t)(((uint32_t)(x)) << vsclr4c_VSCA9LS_vsc9LS_SHIFT)) & vsclr4c_VSCA9LS_vsc9LS_MASK)

#define vsclr4c_VSCA9LS_vsc9PS_MASK              (0x10U)
#define vsclr4c_VSCA9LS_vsc9PS_SHIFT             (4U)
/*! vsc9PS - vscaler9_PrivilegeStatus */
#define vsclr4c_VSCA9LS_vsc9PS(x)                (((uint32_t)(((uint32_t)(x)) << vsclr4c_VSCA9LS_vsc9PS_SHIFT)) & vsclr4c_VSCA9LS_vsc9PS_MASK)

#define vsclr4c_VSCA9LS_vsc9FS_MASK              (0x100U)
#define vsclr4c_VSCA9LS_vsc9FS_SHIFT             (8U)
/*! vsc9FS - vscaler9_FreezeStatus */
#define vsclr4c_VSCA9LS_vsc9FS(x)                (((uint32_t)(((uint32_t)(x)) << vsclr4c_VSCA9LS_vsc9FS_SHIFT)) & vsclr4c_VSCA9LS_vsc9FS_MASK)
/*! @} */

/*! @name VSCA9D - vscaler9_Dynamic */
/*! @{ */

#define vsclr4c_VSCA9D_vsc9ssel_MASK             (0x3FU)
#define vsclr4c_VSCA9D_vsc9ssel_SHIFT            (0U)
/*! vsc9ssel - vscaler9_src_sel
 *  0b000000..Unit vscaler9 input port src is disabled
 *  0b000001..Unit vscaler9 input port src is connected to output of unit rop9
 *  0b000010..Unit vscaler9 input port src is connected to output of unit clut9
 *  0b000011..Unit vscaler9 input port src is connected to output of unit matrix9
 *  0b000100..Unit vscaler9 input port src is connected to output of unit blitblend9
 *  0b001000..Unit vscaler9 input port src is connected to output of unit hscaler9
 */
#define vsclr4c_VSCA9D_vsc9ssel(x)               (((uint32_t)(((uint32_t)(x)) << vsclr4c_VSCA9D_vsc9ssel_SHIFT)) & vsclr4c_VSCA9D_vsc9ssel_MASK)

#define vsclr4c_VSCA9D_vsc9cen_MASK              (0x3000000U)
#define vsclr4c_VSCA9D_vsc9cen_SHIFT             (24U)
/*! vsc9cen - vscaler9_clken
 *  0b00..Clock for vscaler9 is disabled
 *  0b01..Clock is enabled if unit is used, frequency is defined by the register setting for this pipeline (see [endpoint_name]_Static register)
 *  0b11..Clock for vscaler9 is without gating
 */
#define vsclr4c_VSCA9D_vsc9cen(x)                (((uint32_t)(((uint32_t)(x)) << vsclr4c_VSCA9D_vsc9cen_SHIFT)) & vsclr4c_VSCA9D_vsc9cen_MASK)
/*! @} */

/*! @name VSCA9S - vscaler9_Status */
/*! @{ */

#define vsclr4c_VSCA9S_vsc9sel_MASK              (0x70000U)
#define vsclr4c_VSCA9S_vsc9sel_SHIFT             (16U)
/*! vsc9sel - vscaler9_sel
 *  0b000..vscaler9 module is not used
 *  0b001..vscaler9 module is used from store9 processing path
 *  0b010..vscaler9 module is used from extdst0 processing path
 *  0b011..vscaler9 module is used from extdst4 processing path
 *  0b100..vscaler9 module is used from extdst1 processing path
 *  0b101..vscaler9 module is used from extdst5 processing path
 */
#define vsclr4c_VSCA9S_vsc9sel(x)                (((uint32_t)(((uint32_t)(x)) << vsclr4c_VSCA9S_vsc9sel_SHIFT)) & vsclr4c_VSCA9S_vsc9sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group vsclr4c_Register_Masks */


/*!
 * @}
 */ /* end of group vsclr4c_Peripheral_Access_Layer */


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


#endif  /* PERI_VSCLR4C_H_ */

