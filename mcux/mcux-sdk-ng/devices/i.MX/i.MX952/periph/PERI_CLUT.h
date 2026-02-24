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
**         CMSIS Peripheral Access Layer for clut
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
 * @file PERI_clut.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for clut
 *
 * CMSIS Peripheral Access Layer for clut
 */

#if !defined(PERI_CLUT_H_)
#define PERI_CLUT_H_                             /**< Symbol preventing repeated inclusion */

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
   -- clut Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup clut_Peripheral_Access_Layer clut Peripheral Access Layer
 * @{
 */

/** clut - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t UNSHCO;                            /**< UnshadowedControl, offset: 0xC */
  __IO uint32_t CONTR;                             /**< Control, offset: 0x10 */
  __IO uint32_t STATUS;                            /**< Status, offset: 0x14 */
  __I  uint32_t LASTCOW;                           /**< LastControlWord, offset: 0x18 */
} clut_Type;

/* ----------------------------------------------------------------------------
   -- clut Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup clut_Register_Masks clut Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define clut_LU_LkUn_MASK                        (0xFFFFFFFFU)
#define clut_LU_LkUn_SHIFT                       (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define clut_LU_LkUn(x)                          (((uint32_t)(((uint32_t)(x)) << clut_LU_LkUn_SHIFT)) & clut_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define clut_LOCKS_LkSus_MASK                    (0x1U)
#define clut_LOCKS_LkSus_SHIFT                   (0U)
/*! LkSus - LockStatus */
#define clut_LOCKS_LkSus(x)                      (((uint32_t)(((uint32_t)(x)) << clut_LOCKS_LkSus_SHIFT)) & clut_LOCKS_LkSus_MASK)

#define clut_LOCKS_PriSt_MASK                    (0x10U)
#define clut_LOCKS_PriSt_SHIFT                   (4U)
/*! PriSt - PrivilegeStatus */
#define clut_LOCKS_PriSt(x)                      (((uint32_t)(((uint32_t)(x)) << clut_LOCKS_PriSt_SHIFT)) & clut_LOCKS_PriSt_MASK)

#define clut_LOCKS_FreezeS_MASK                  (0x100U)
#define clut_LOCKS_FreezeS_SHIFT                 (8U)
/*! FreezeS - FreezeStatus */
#define clut_LOCKS_FreezeS(x)                    (((uint32_t)(((uint32_t)(x)) << clut_LOCKS_FreezeS_SHIFT)) & clut_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define clut_STATCON_ShdEn_MASK                  (0x1U)
#define clut_STATCON_ShdEn_SHIFT                 (0U)
/*! ShdEn - ShdEn */
#define clut_STATCON_ShdEn(x)                    (((uint32_t)(((uint32_t)(x)) << clut_STATCON_ShdEn_SHIFT)) & clut_STATCON_ShdEn_MASK)
/*! @} */

/*! @name UNSHCO - UnshadowedControl */
/*! @{ */

#define clut_UNSHCO_BEN_MASK                     (0x1U)
#define clut_UNSHCO_BEN_SHIFT                    (0U)
/*! BEN - B_EN
 *  0b0..disable
 *  0b1..enable
 */
#define clut_UNSHCO_BEN(x)                       (((uint32_t)(((uint32_t)(x)) << clut_UNSHCO_BEN_SHIFT)) & clut_UNSHCO_BEN_MASK)

#define clut_UNSHCO_GEN_MASK                     (0x2U)
#define clut_UNSHCO_GEN_SHIFT                    (1U)
/*! GEN - G_EN
 *  0b0..disable
 *  0b1..enable
 */
#define clut_UNSHCO_GEN(x)                       (((uint32_t)(((uint32_t)(x)) << clut_UNSHCO_GEN_SHIFT)) & clut_UNSHCO_GEN_MASK)

#define clut_UNSHCO_REN_MASK                     (0x4U)
#define clut_UNSHCO_REN_SHIFT                    (2U)
/*! REN - R_EN
 *  0b0..disable
 *  0b1..enable
 */
#define clut_UNSHCO_REN(x)                       (((uint32_t)(((uint32_t)(x)) << clut_UNSHCO_REN_SHIFT)) & clut_UNSHCO_REN_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define clut_CONTR_MODE2_MASK                    (0x3U)
#define clut_CONTR_MODE2_SHIFT                   (0U)
/*! MODE2 - MODE
 *  0b00..Module in neutral mode, RGBA input data are bypassed to the output.
 *  0b01..Each RGB input is used as individual index into the respective LUT. Alpha channel is bypassed to output.
 *  0b10..Red input is used as common index into every RGB LUT. Alpha channel is bypassed to output.
 *  0b11..Red input is used as common index into every RGB LUT. The result is remapped and upconverted to RGBA.
 */
#define clut_CONTR_MODE2(x)                      (((uint32_t)(((uint32_t)(x)) << clut_CONTR_MODE2_SHIFT)) & clut_CONTR_MODE2_MASK)

#define clut_CONTR_COL8BIT_MASK                  (0x10U)
#define clut_CONTR_COL8BIT_SHIFT                 (4U)
/*! COL8BIT - COL_8BIT
 *  0b0..color is 10bit output
 *  0b1..color is 8bit output (dithering of internal 10bit value)
 */
#define clut_CONTR_COL8BIT(x)                    (((uint32_t)(((uint32_t)(x)) << clut_CONTR_COL8BIT_SHIFT)) & clut_CONTR_COL8BIT_MASK)

#define clut_CONTR_AlpMk_MASK                    (0x20U)
#define clut_CONTR_AlpMk_SHIFT                   (5U)
/*! AlpMk - AlphaMask
 *  0b0..Alpha mask mode disabled
 *  0b1..Alpha mask mode enabled
 */
#define clut_CONTR_AlpMk(x)                      (((uint32_t)(((uint32_t)(x)) << clut_CONTR_AlpMk_SHIFT)) & clut_CONTR_AlpMk_MASK)

#define clut_CONTR_AlphaInv_MASK                 (0x40U)
#define clut_CONTR_AlphaInv_SHIFT                (6U)
/*! AlphaInv - AlphaInvert
 *  0b0..Disable computation for alpha smaller than 128
 *  0b1..Disable computation for alpha greater than or equal to 128
 */
#define clut_CONTR_AlphaInv(x)                   (((uint32_t)(((uint32_t)(x)) << clut_CONTR_AlphaInv_SHIFT)) & clut_CONTR_AlphaInv_MASK)

#define clut_CONTR_IDXBITS_MASK                  (0xF00U)
#define clut_CONTR_IDXBITS_SHIFT                 (8U)
/*! IDXBITS - IDX_BITS */
#define clut_CONTR_IDXBITS(x)                    (((uint32_t)(((uint32_t)(x)) << clut_CONTR_IDXBITS_SHIFT)) & clut_CONTR_IDXBITS_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define clut_STATUS_WRTTOUT1_MASK                (0x1U)
#define clut_STATUS_WRTTOUT1_SHIFT               (0U)
/*! WRTTOUT1 - WRITE_TIMEOUT */
#define clut_STATUS_WRTTOUT1(x)                  (((uint32_t)(((uint32_t)(x)) << clut_STATUS_WRTTOUT1_SHIFT)) & clut_STATUS_WRTTOUT1_MASK)

#define clut_STATUS_ReadTmt_MASK                 (0x10U)
#define clut_STATUS_ReadTmt_SHIFT                (4U)
/*! ReadTmt - READ_TIMEOUT */
#define clut_STATUS_ReadTmt(x)                   (((uint32_t)(((uint32_t)(x)) << clut_STATUS_ReadTmt_SHIFT)) & clut_STATUS_ReadTmt_MASK)
/*! @} */

/*! @name LASTCOW - LastControlWord */
/*! @{ */

#define clut_LASTCOW_LVAL_MASK                   (0xFFFFFFFFU)
#define clut_LASTCOW_LVAL_SHIFT                  (0U)
/*! LVAL - L_VAL */
#define clut_LASTCOW_LVAL(x)                     (((uint32_t)(((uint32_t)(x)) << clut_LASTCOW_LVAL_SHIFT)) & clut_LASTCOW_LVAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group clut_Register_Masks */


/*!
 * @}
 */ /* end of group clut_Peripheral_Access_Layer */


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


#endif  /* PERI_CLUT_H_ */

