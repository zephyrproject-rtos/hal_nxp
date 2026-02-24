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
**         CMSIS Peripheral Access Layer for rop
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
 * @file PERI_rop.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for rop
 *
 * CMSIS Peripheral Access Layer for rop
 */

#if !defined(PERI_ROP_H_)
#define PERI_ROP_H_                              /**< Symbol preventing repeated inclusion */

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
   -- rop Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup rop_Peripheral_Access_Layer rop Peripheral Access Layer
 * @{
 */

/** rop - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0xC */
  __IO uint32_t RASTOPIN;                          /**< RasterOperationIndices, offset: 0x10 */
  __I  uint32_t PRIMCOWO;                          /**< PrimControlWord, offset: 0x14 */
  __I  uint32_t SECCONTW;                          /**< SecControlWord, offset: 0x18 */
  __I  uint32_t TERTCOW;                           /**< TertControlWord, offset: 0x1C */
} rop_Type;

/* ----------------------------------------------------------------------------
   -- rop Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup rop_Register_Masks rop Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define rop_LU_LkUn_MASK                         (0xFFFFFFFFU)
#define rop_LU_LkUn_SHIFT                        (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define rop_LU_LkUn(x)                           (((uint32_t)(((uint32_t)(x)) << rop_LU_LkUn_SHIFT)) & rop_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define rop_LOCKS_LkSus_MASK                     (0x1U)
#define rop_LOCKS_LkSus_SHIFT                    (0U)
/*! LkSus - LockStatus */
#define rop_LOCKS_LkSus(x)                       (((uint32_t)(((uint32_t)(x)) << rop_LOCKS_LkSus_SHIFT)) & rop_LOCKS_LkSus_MASK)

#define rop_LOCKS_PriSt_MASK                     (0x10U)
#define rop_LOCKS_PriSt_SHIFT                    (4U)
/*! PriSt - PrivilegeStatus */
#define rop_LOCKS_PriSt(x)                       (((uint32_t)(((uint32_t)(x)) << rop_LOCKS_PriSt_SHIFT)) & rop_LOCKS_PriSt_MASK)

#define rop_LOCKS_FreezeS_MASK                   (0x100U)
#define rop_LOCKS_FreezeS_SHIFT                  (8U)
/*! FreezeS - FreezeStatus */
#define rop_LOCKS_FreezeS(x)                     (((uint32_t)(((uint32_t)(x)) << rop_LOCKS_FreezeS_SHIFT)) & rop_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define rop_STATCON_ShdEn_MASK                   (0x1U)
#define rop_STATCON_ShdEn_SHIFT                  (0U)
/*! ShdEn - ShdEn */
#define rop_STATCON_ShdEn(x)                     (((uint32_t)(((uint32_t)(x)) << rop_STATCON_ShdEn_SHIFT)) & rop_STATCON_ShdEn_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define rop_CONTR_Mode1_MASK                     (0x1U)
#define rop_CONTR_Mode1_SHIFT                    (0U)
/*! Mode1 - Mode
 *  0b0..Neutral mode
 *  0b1..Normal Operation
 */
#define rop_CONTR_Mode1(x)                       (((uint32_t)(((uint32_t)(x)) << rop_CONTR_Mode1_SHIFT)) & rop_CONTR_Mode1_MASK)

#define rop_CONTR_AlpMode_MASK                   (0x10U)
#define rop_CONTR_AlpMode_SHIFT                  (4U)
/*! AlpMode - AlphaMode
 *  0b0..Normal raster operation mode, using the operation index
 *  0b1..Add mode, adds this component from all enabled inputs, clamps to 1
 */
#define rop_CONTR_AlpMode(x)                     (((uint32_t)(((uint32_t)(x)) << rop_CONTR_AlpMode_SHIFT)) & rop_CONTR_AlpMode_MASK)

#define rop_CONTR_BlueMode_MASK                  (0x20U)
#define rop_CONTR_BlueMode_SHIFT                 (5U)
/*! BlueMode - BlueMode
 *  0b0..Normal raster operation mode, using the operation index
 *  0b1..Add mode, adds this component from all enabled inputs, clamps to 1
 */
#define rop_CONTR_BlueMode(x)                    (((uint32_t)(((uint32_t)(x)) << rop_CONTR_BlueMode_SHIFT)) & rop_CONTR_BlueMode_MASK)

#define rop_CONTR_GreenMod_MASK                  (0x40U)
#define rop_CONTR_GreenMod_SHIFT                 (6U)
/*! GreenMod - GreenMode
 *  0b0..Normal raster operation mode, using the operation index
 *  0b1..Add mode, adds this component from all enabled inputs, clamps to 1
 */
#define rop_CONTR_GreenMod(x)                    (((uint32_t)(((uint32_t)(x)) << rop_CONTR_GreenMod_SHIFT)) & rop_CONTR_GreenMod_MASK)

#define rop_CONTR_RedMode_MASK                   (0x80U)
#define rop_CONTR_RedMode_SHIFT                  (7U)
/*! RedMode - RedMode
 *  0b0..Normal raster operation mode, using the operation index
 *  0b1..Add mode, adds this component from all enabled inputs, clamps to 1
 */
#define rop_CONTR_RedMode(x)                     (((uint32_t)(((uint32_t)(x)) << rop_CONTR_RedMode_SHIFT)) & rop_CONTR_RedMode_MASK)

#define rop_CONTR_PrimDiv2_MASK                  (0x100U)
#define rop_CONTR_PrimDiv2_SHIFT                 (8U)
/*! PrimDiv2 - PrimDiv2
 *  0b0..No change to input
 *  0b1..Input is divided by two/shift to the right by one
 */
#define rop_CONTR_PrimDiv2(x)                    (((uint32_t)(((uint32_t)(x)) << rop_CONTR_PrimDiv2_SHIFT)) & rop_CONTR_PrimDiv2_MASK)

#define rop_CONTR_ScDiv2_MASK                    (0x200U)
#define rop_CONTR_ScDiv2_SHIFT                   (9U)
/*! ScDiv2 - SecDiv2
 *  0b0..No change to input
 *  0b1..Input is divided by two/shift to the right by one
 */
#define rop_CONTR_ScDiv2(x)                      (((uint32_t)(((uint32_t)(x)) << rop_CONTR_ScDiv2_SHIFT)) & rop_CONTR_ScDiv2_MASK)

#define rop_CONTR_TertDiv2_MASK                  (0x400U)
#define rop_CONTR_TertDiv2_SHIFT                 (10U)
/*! TertDiv2 - TertDiv2
 *  0b0..No change to input
 *  0b1..Input is divided by two/shift to the right by one
 */
#define rop_CONTR_TertDiv2(x)                    (((uint32_t)(((uint32_t)(x)) << rop_CONTR_TertDiv2_SHIFT)) & rop_CONTR_TertDiv2_MASK)
/*! @} */

/*! @name RASTOPIN - RasterOperationIndices */
/*! @{ */

#define rop_RASTOPIN_OpIdxA_MASK                 (0xFFU)
#define rop_RASTOPIN_OpIdxA_SHIFT                (0U)
/*! OpIdxA - OpIndexAlpha */
#define rop_RASTOPIN_OpIdxA(x)                   (((uint32_t)(((uint32_t)(x)) << rop_RASTOPIN_OpIdxA_SHIFT)) & rop_RASTOPIN_OpIdxA_MASK)

#define rop_RASTOPIN_OpIdxB_MASK                 (0xFF00U)
#define rop_RASTOPIN_OpIdxB_SHIFT                (8U)
/*! OpIdxB - OpIndexBlue */
#define rop_RASTOPIN_OpIdxB(x)                   (((uint32_t)(((uint32_t)(x)) << rop_RASTOPIN_OpIdxB_SHIFT)) & rop_RASTOPIN_OpIdxB_MASK)

#define rop_RASTOPIN_OpIdxG_MASK                 (0xFF0000U)
#define rop_RASTOPIN_OpIdxG_SHIFT                (16U)
/*! OpIdxG - OpIndexGreen */
#define rop_RASTOPIN_OpIdxG(x)                   (((uint32_t)(((uint32_t)(x)) << rop_RASTOPIN_OpIdxG_SHIFT)) & rop_RASTOPIN_OpIdxG_MASK)

#define rop_RASTOPIN_OpIdxR_MASK                 (0xFF000000U)
#define rop_RASTOPIN_OpIdxR_SHIFT                (24U)
/*! OpIdxR - OpIndexRed */
#define rop_RASTOPIN_OpIdxR(x)                   (((uint32_t)(((uint32_t)(x)) << rop_RASTOPIN_OpIdxR_SHIFT)) & rop_RASTOPIN_OpIdxR_MASK)
/*! @} */

/*! @name PRIMCOWO - PrimControlWord */
/*! @{ */

#define rop_PRIMCOWO_PVAL_MASK                   (0xFFFFFFFFU)
#define rop_PRIMCOWO_PVAL_SHIFT                  (0U)
/*! PVAL - P_VAL */
#define rop_PRIMCOWO_PVAL(x)                     (((uint32_t)(((uint32_t)(x)) << rop_PRIMCOWO_PVAL_SHIFT)) & rop_PRIMCOWO_PVAL_MASK)
/*! @} */

/*! @name SECCONTW - SecControlWord */
/*! @{ */

#define rop_SECCONTW_SVAL_MASK                   (0xFFFFFFFFU)
#define rop_SECCONTW_SVAL_SHIFT                  (0U)
/*! SVAL - S_VAL */
#define rop_SECCONTW_SVAL(x)                     (((uint32_t)(((uint32_t)(x)) << rop_SECCONTW_SVAL_SHIFT)) & rop_SECCONTW_SVAL_MASK)
/*! @} */

/*! @name TERTCOW - TertControlWord */
/*! @{ */

#define rop_TERTCOW_TVAL_MASK                    (0xFFFFFFFFU)
#define rop_TERTCOW_TVAL_SHIFT                   (0U)
/*! TVAL - T_VAL */
#define rop_TERTCOW_TVAL(x)                      (((uint32_t)(((uint32_t)(x)) << rop_TERTCOW_TVAL_SHIFT)) & rop_TERTCOW_TVAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group rop_Register_Masks */


/*!
 * @}
 */ /* end of group rop_Peripheral_Access_Layer */


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


#endif  /* PERI_ROP_H_ */

