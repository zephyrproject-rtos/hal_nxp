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
**         CMSIS Peripheral Access Layer for blitb9cf
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
 * @file PERI_blitb9cf.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for blitb9cf
 *
 * CMSIS Peripheral Access Layer for blitb9cf
 */

#if !defined(PERI_BLITB9CF_H_)
#define PERI_BLITB9CF_H_                         /**< Symbol preventing repeated inclusion */

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
   -- blitb9cf Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup blitb9cf_Peripheral_Access_Layer blitb9cf Peripheral Access Layer
 * @{
 */

/** blitb9cf - Register Layout Typedef */
typedef struct {
  __O  uint32_t BLIBL9LU;                          /**< blitblend9_LockUnlock, offset: 0x0 */
  __I  uint32_t BLIBL9LS;                          /**< blitblend9_LockStatus, offset: 0x4 */
  __IO uint32_t BLIB9DY;                           /**< blitblend9_Dynamic, offset: 0x8 */
  __I  uint32_t BLIBL9ST;                          /**< blitblend9_Status, offset: 0xC */
} blitb9cf_Type;

/* ----------------------------------------------------------------------------
   -- blitb9cf Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup blitb9cf_Register_Masks blitb9cf Register Masks
 * @{
 */

/*! @name BLIBL9LU - blitblend9_LockUnlock */
/*! @{ */

#define blitb9cf_BLIBL9LU_bli9LUnl_MASK          (0xFFFFFFFFU)
#define blitb9cf_BLIBL9LU_bli9LUnl_SHIFT         (0U)
/*! bli9LUnl - blitblend9_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define blitb9cf_BLIBL9LU_bli9LUnl(x)            (((uint32_t)(((uint32_t)(x)) << blitb9cf_BLIBL9LU_bli9LUnl_SHIFT)) & blitb9cf_BLIBL9LU_bli9LUnl_MASK)
/*! @} */

/*! @name BLIBL9LS - blitblend9_LockStatus */
/*! @{ */

#define blitb9cf_BLIBL9LS_bli9LS_MASK            (0x1U)
#define blitb9cf_BLIBL9LS_bli9LS_SHIFT           (0U)
/*! bli9LS - blitblend9_LockStatus */
#define blitb9cf_BLIBL9LS_bli9LS(x)              (((uint32_t)(((uint32_t)(x)) << blitb9cf_BLIBL9LS_bli9LS_SHIFT)) & blitb9cf_BLIBL9LS_bli9LS_MASK)

#define blitb9cf_BLIBL9LS_bli9PS_MASK            (0x10U)
#define blitb9cf_BLIBL9LS_bli9PS_SHIFT           (4U)
/*! bli9PS - blitblend9_PrivilegeStatus */
#define blitb9cf_BLIBL9LS_bli9PS(x)              (((uint32_t)(((uint32_t)(x)) << blitb9cf_BLIBL9LS_bli9PS_SHIFT)) & blitb9cf_BLIBL9LS_bli9PS_MASK)

#define blitb9cf_BLIBL9LS_bli9FS_MASK            (0x100U)
#define blitb9cf_BLIBL9LS_bli9FS_SHIFT           (8U)
/*! bli9FS - blitblend9_FreezeStatus */
#define blitb9cf_BLIBL9LS_bli9FS(x)              (((uint32_t)(((uint32_t)(x)) << blitb9cf_BLIBL9LS_bli9FS_SHIFT)) & blitb9cf_BLIBL9LS_bli9FS_MASK)
/*! @} */

/*! @name BLIB9DY - blitblend9_Dynamic */
/*! @{ */

#define blitb9cf_BLIB9DY_bli9psel_MASK           (0x3FU)
#define blitb9cf_BLIB9DY_bli9psel_SHIFT          (0U)
/*! bli9psel - blitblend9_prim_sel
 *  0b000000..Unit blitblend9 input port prim is disabled
 *  0b000001..Unit blitblend9 input port prim is connected to output of unit rop9
 *  0b001000..Unit blitblend9 input port prim is connected to output of unit hscaler9
 *  0b001001..Unit blitblend9 input port prim is connected to output of unit vscaler9
 *  0b001010..Unit blitblend9 input port prim is connected to output of unit filter9
 */
#define blitb9cf_BLIB9DY_bli9psel(x)             (((uint32_t)(((uint32_t)(x)) << blitb9cf_BLIB9DY_bli9psel_SHIFT)) & blitb9cf_BLIB9DY_bli9psel_MASK)

#define blitb9cf_BLIB9DY_bli9ssel_MASK           (0x3F00U)
#define blitb9cf_BLIB9DY_bli9ssel_SHIFT          (8U)
/*! bli9ssel - blitblend9_sec_sel
 *  0b000000..Unit blitblend9 input port sec is disabled
 *  0b000101..Unit blitblend9 input port sec is connected to output of unit fetchrot9
 *  0b000110..Unit blitblend9 input port sec is connected to output of unit fetchdecode9
 */
#define blitb9cf_BLIB9DY_bli9ssel(x)             (((uint32_t)(((uint32_t)(x)) << blitb9cf_BLIB9DY_bli9ssel_SHIFT)) & blitb9cf_BLIB9DY_bli9ssel_MASK)

#define blitb9cf_BLIB9DY_bli9cen_MASK            (0x3000000U)
#define blitb9cf_BLIB9DY_bli9cen_SHIFT           (24U)
/*! bli9cen - blitblend9_clken
 *  0b00..Clock for blitblend9 is disabled
 *  0b01..Clock is enabled if unit is used, frequency is defined by the register setting for this pipeline (see [endpoint_name]_Static register)
 *  0b11..Clock for blitblend9 is without gating
 */
#define blitb9cf_BLIB9DY_bli9cen(x)              (((uint32_t)(((uint32_t)(x)) << blitb9cf_BLIB9DY_bli9cen_SHIFT)) & blitb9cf_BLIB9DY_bli9cen_MASK)
/*! @} */

/*! @name BLIBL9ST - blitblend9_Status */
/*! @{ */

#define blitb9cf_BLIBL9ST_bli9sel_MASK           (0x70000U)
#define blitb9cf_BLIBL9ST_bli9sel_SHIFT          (16U)
/*! bli9sel - blitblend9_sel
 *  0b000..blitblend9 module is not used
 *  0b001..blitblend9 module is used from store9 processing path
 *  0b010..blitblend9 module is used from extdst0 processing path
 *  0b011..blitblend9 module is used from extdst4 processing path
 *  0b100..blitblend9 module is used from extdst1 processing path
 *  0b101..blitblend9 module is used from extdst5 processing path
 */
#define blitb9cf_BLIBL9ST_bli9sel(x)             (((uint32_t)(((uint32_t)(x)) << blitb9cf_BLIBL9ST_bli9sel_SHIFT)) & blitb9cf_BLIBL9ST_bli9sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group blitb9cf_Register_Masks */


/*!
 * @}
 */ /* end of group blitb9cf_Peripheral_Access_Layer */


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


#endif  /* PERI_BLITB9CF_H_ */

