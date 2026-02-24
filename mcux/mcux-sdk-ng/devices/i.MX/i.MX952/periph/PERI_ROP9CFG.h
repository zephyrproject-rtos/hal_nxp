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
**         CMSIS Peripheral Access Layer for rop9cfg
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
 * @file PERI_rop9cfg.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for rop9cfg
 *
 * CMSIS Peripheral Access Layer for rop9cfg
 */

#if !defined(PERI_ROP9CFG_H_)
#define PERI_ROP9CFG_H_                          /**< Symbol preventing repeated inclusion */

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
   -- rop9cfg Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup rop9cfg_Peripheral_Access_Layer rop9cfg Peripheral Access Layer
 * @{
 */

/** rop9cfg - Register Layout Typedef */
typedef struct {
  __O  uint32_t ROP9LU;                            /**< rop9_LockUnlock, offset: 0x0 */
  __I  uint32_t ROP9LS;                            /**< rop9_LockStatus, offset: 0x4 */
  __IO uint32_t ROP9D;                             /**< rop9_Dynamic, offset: 0x8 */
  __I  uint32_t ROP9S;                             /**< rop9_Status, offset: 0xC */
} rop9cfg_Type;

/* ----------------------------------------------------------------------------
   -- rop9cfg Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup rop9cfg_Register_Masks rop9cfg Register Masks
 * @{
 */

/*! @name ROP9LU - rop9_LockUnlock */
/*! @{ */

#define rop9cfg_ROP9LU_rop9LUnl_MASK             (0xFFFFFFFFU)
#define rop9cfg_ROP9LU_rop9LUnl_SHIFT            (0U)
/*! rop9LUnl - rop9_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define rop9cfg_ROP9LU_rop9LUnl(x)               (((uint32_t)(((uint32_t)(x)) << rop9cfg_ROP9LU_rop9LUnl_SHIFT)) & rop9cfg_ROP9LU_rop9LUnl_MASK)
/*! @} */

/*! @name ROP9LS - rop9_LockStatus */
/*! @{ */

#define rop9cfg_ROP9LS_rop9LS_MASK               (0x1U)
#define rop9cfg_ROP9LS_rop9LS_SHIFT              (0U)
/*! rop9LS - rop9_LockStatus */
#define rop9cfg_ROP9LS_rop9LS(x)                 (((uint32_t)(((uint32_t)(x)) << rop9cfg_ROP9LS_rop9LS_SHIFT)) & rop9cfg_ROP9LS_rop9LS_MASK)

#define rop9cfg_ROP9LS_rop9PS_MASK               (0x10U)
#define rop9cfg_ROP9LS_rop9PS_SHIFT              (4U)
/*! rop9PS - rop9_PrivilegeStatus */
#define rop9cfg_ROP9LS_rop9PS(x)                 (((uint32_t)(((uint32_t)(x)) << rop9cfg_ROP9LS_rop9PS_SHIFT)) & rop9cfg_ROP9LS_rop9PS_MASK)

#define rop9cfg_ROP9LS_rop9FS_MASK               (0x100U)
#define rop9cfg_ROP9LS_rop9FS_SHIFT              (8U)
/*! rop9FS - rop9_FreezeStatus */
#define rop9cfg_ROP9LS_rop9FS(x)                 (((uint32_t)(((uint32_t)(x)) << rop9cfg_ROP9LS_rop9FS_SHIFT)) & rop9cfg_ROP9LS_rop9FS_MASK)
/*! @} */

/*! @name ROP9D - rop9_Dynamic */
/*! @{ */

#define rop9cfg_ROP9D_rop9pri_MASK               (0x3FU)
#define rop9cfg_ROP9D_rop9pri_SHIFT              (0U)
/*! rop9pri - rop9_prim_sel
 *  0b000000..Unit rop9 input port prim is disabled
 *  0b000101..Unit rop9 input port prim is connected to output of unit fetchrot9
 *  0b000110..Unit rop9 input port prim is connected to output of unit fetchdecode9
 */
#define rop9cfg_ROP9D_rop9pri(x)                 (((uint32_t)(((uint32_t)(x)) << rop9cfg_ROP9D_rop9pri_SHIFT)) & rop9cfg_ROP9D_rop9pri_MASK)

#define rop9cfg_ROP9D_rop9ssel_MASK              (0x3F00U)
#define rop9cfg_ROP9D_rop9ssel_SHIFT             (8U)
/*! rop9ssel - rop9_sec_sel
 *  0b000000..Unit rop9 input port sec is disabled
 *  0b000111..Unit rop9 input port sec is connected to output of unit fetcheco9
 */
#define rop9cfg_ROP9D_rop9ssel(x)                (((uint32_t)(((uint32_t)(x)) << rop9cfg_ROP9D_rop9ssel_SHIFT)) & rop9cfg_ROP9D_rop9ssel_MASK)

#define rop9cfg_ROP9D_rop9tsel_MASK              (0x3F0000U)
#define rop9cfg_ROP9D_rop9tsel_SHIFT             (16U)
/*! rop9tsel - rop9_tert_sel
 *  0b000000..Unit rop9 input port tert is disabled
 *  0b000101..Unit rop9 input port tert is connected to output of unit fetchrot9
 *  0b000110..Unit rop9 input port tert is connected to output of unit fetchdecode9
 */
#define rop9cfg_ROP9D_rop9tsel(x)                (((uint32_t)(((uint32_t)(x)) << rop9cfg_ROP9D_rop9tsel_SHIFT)) & rop9cfg_ROP9D_rop9tsel_MASK)

#define rop9cfg_ROP9D_rop9cen_MASK               (0x3000000U)
#define rop9cfg_ROP9D_rop9cen_SHIFT              (24U)
/*! rop9cen - rop9_clken
 *  0b00..Clock for rop9 is disabled
 *  0b01..Clock is enabled if unit is used, frequency is defined by the register setting for this pipeline (see [endpoint_name]_Static register)
 *  0b11..Clock for rop9 is without gating
 */
#define rop9cfg_ROP9D_rop9cen(x)                 (((uint32_t)(((uint32_t)(x)) << rop9cfg_ROP9D_rop9cen_SHIFT)) & rop9cfg_ROP9D_rop9cen_MASK)
/*! @} */

/*! @name ROP9S - rop9_Status */
/*! @{ */

#define rop9cfg_ROP9S_rop9sel_MASK               (0x70000U)
#define rop9cfg_ROP9S_rop9sel_SHIFT              (16U)
/*! rop9sel - rop9_sel
 *  0b000..rop9 module is not used
 *  0b001..rop9 module is used from store9 processing path
 *  0b010..rop9 module is used from extdst0 processing path
 *  0b011..rop9 module is used from extdst4 processing path
 *  0b100..rop9 module is used from extdst1 processing path
 *  0b101..rop9 module is used from extdst5 processing path
 */
#define rop9cfg_ROP9S_rop9sel(x)                 (((uint32_t)(((uint32_t)(x)) << rop9cfg_ROP9S_rop9sel_SHIFT)) & rop9cfg_ROP9S_rop9sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group rop9cfg_Register_Masks */


/*!
 * @}
 */ /* end of group rop9cfg_Peripheral_Access_Layer */


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


#endif  /* PERI_ROP9CFG_H_ */

