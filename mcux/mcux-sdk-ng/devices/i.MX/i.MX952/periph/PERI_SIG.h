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
**         CMSIS Peripheral Access Layer for sig
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
 * @file PERI_sig.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for sig
 *
 * CMSIS Peripheral Access Layer for sig
 */

#if !defined(PERI_SIG_H_)
#define PERI_SIG_H_                              /**< Symbol preventing repeated inclusion */

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
   -- sig Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup sig_Peripheral_Access_Layer sig Peripheral Access Layer
 * @{
 */

/** sig - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t ERTHRES;                           /**< ErrorThreshold, offset: 0xC */
  __IO uint32_t MATCHTHR;                          /**< MatchThreshold, offset: 0x10 */
  __IO uint32_t PANICCOL;                          /**< PanicColor, offset: 0x14 */
  __IO uint32_t SHADOWLD;                          /**< ShadowLoad, offset: 0x18 */
  __IO uint32_t CONTIMO;                           /**< ContinuousMode, offset: 0x1C */
  __O  uint32_t SOFTKICK;                          /**< SoftwareKick, offset: 0x20 */
  __IO uint32_t SKIPWIND;                          /**< SkipWindow, offset: 0x24 */
  __I  uint32_t STATUS;                            /**< Status, offset: 0x28 */
  __IO uint32_t CONTW0;                            /**< Control_Window0, offset: 0x2C */
  __IO uint32_t UPPERLW0;                          /**< UpperLeft_Window0, offset: 0x30 */
  __IO uint32_t LOWRIW0;                           /**< LowerRight_Window0, offset: 0x34 */
  __IO uint32_t REFRW0;                            /**< Ref_R_Window0, offset: 0x38 */
  __IO uint32_t REFGW0;                            /**< Ref_G_Window0, offset: 0x3C */
  __IO uint32_t REFBW0;                            /**< Ref_B_Window0, offset: 0x40 */
  __IO uint32_t STATS0W0;                          /**< Stats0_Window0, offset: 0x44 */
  __IO uint32_t STATS1W0;                          /**< Stats1_Window0, offset: 0x48 */
  __IO uint32_t MINRSUW0;                          /**< Min_RedSum_Window0, offset: 0x4C */
  __IO uint32_t MINGSUW0;                          /**< Min_GreenSum_Window0, offset: 0x50 */
  __IO uint32_t MINBSUW0;                          /**< Min_BlueSum_Window0, offset: 0x54 */
  __IO uint32_t MINLUSW0;                          /**< Min_LumSum_Window0, offset: 0x58 */
  __IO uint32_t MAXRSUW0;                          /**< Max_RedSum_Window0, offset: 0x5C */
  __IO uint32_t MAXGSUW0;                          /**< Max_GreenSum_Window0, offset: 0x60 */
  __IO uint32_t MAXBSUW0;                          /**< Max_BlueSum_Window0, offset: 0x64 */
  __IO uint32_t MAXLUSW0;                          /**< Max_LumSum_Window0, offset: 0x68 */
  __IO uint32_t CONTW1;                            /**< Control_Window1, offset: 0x6C */
  __IO uint32_t UPPERLW1;                          /**< UpperLeft_Window1, offset: 0x70 */
  __IO uint32_t LOWRIW1;                           /**< LowerRight_Window1, offset: 0x74 */
  __IO uint32_t REFRW1;                            /**< Ref_R_Window1, offset: 0x78 */
  __IO uint32_t REFGW1;                            /**< Ref_G_Window1, offset: 0x7C */
  __IO uint32_t REFBW1;                            /**< Ref_B_Window1, offset: 0x80 */
  __IO uint32_t STATS0W1;                          /**< Stats0_Window1, offset: 0x84 */
  __IO uint32_t STATS1W1;                          /**< Stats1_Window1, offset: 0x88 */
  __IO uint32_t MINRSUW1;                          /**< Min_RedSum_Window1, offset: 0x8C */
  __IO uint32_t MINGSUW1;                          /**< Min_GreenSum_Window1, offset: 0x90 */
  __IO uint32_t MINBSUW1;                          /**< Min_BlueSum_Window1, offset: 0x94 */
  __IO uint32_t MINLUSW1;                          /**< Min_LumSum_Window1, offset: 0x98 */
  __IO uint32_t MAXRSUW1;                          /**< Max_RedSum_Window1, offset: 0x9C */
  __IO uint32_t MAXGSUW1;                          /**< Max_GreenSum_Window1, offset: 0xA0 */
  __IO uint32_t MAXBSUW1;                          /**< Max_BlueSum_Window1, offset: 0xA4 */
  __IO uint32_t MAXLUSW1;                          /**< Max_LumSum_Window1, offset: 0xA8 */
  __IO uint32_t CONTW2;                            /**< Control_Window2, offset: 0xAC */
  __IO uint32_t UPPERLW2;                          /**< UpperLeft_Window2, offset: 0xB0 */
  __IO uint32_t LOWRIW2;                           /**< LowerRight_Window2, offset: 0xB4 */
  __IO uint32_t REFRW2;                            /**< Ref_R_Window2, offset: 0xB8 */
  __IO uint32_t REFGW2;                            /**< Ref_G_Window2, offset: 0xBC */
  __IO uint32_t REFBW2;                            /**< Ref_B_Window2, offset: 0xC0 */
  __IO uint32_t STATS0W2;                          /**< Stats0_Window2, offset: 0xC4 */
  __IO uint32_t STATS1W2;                          /**< Stats1_Window2, offset: 0xC8 */
  __IO uint32_t MINRSUW2;                          /**< Min_RedSum_Window2, offset: 0xCC */
  __IO uint32_t MINGSUW2;                          /**< Min_GreenSum_Window2, offset: 0xD0 */
  __IO uint32_t MINBSUW2;                          /**< Min_BlueSum_Window2, offset: 0xD4 */
  __IO uint32_t MINLUSW2;                          /**< Min_LumSum_Window2, offset: 0xD8 */
  __IO uint32_t MAXRSUW2;                          /**< Max_RedSum_Window2, offset: 0xDC */
  __IO uint32_t MAXGSUW2;                          /**< Max_GreenSum_Window2, offset: 0xE0 */
  __IO uint32_t MAXBSUW2;                          /**< Max_BlueSum_Window2, offset: 0xE4 */
  __IO uint32_t MAXLUSW2;                          /**< Max_LumSum_Window2, offset: 0xE8 */
  __IO uint32_t CONTW3;                            /**< Control_Window3, offset: 0xEC */
  __IO uint32_t UPPERLW3;                          /**< UpperLeft_Window3, offset: 0xF0 */
  __IO uint32_t LOWRIW3;                           /**< LowerRight_Window3, offset: 0xF4 */
  __IO uint32_t REFRW3;                            /**< Ref_R_Window3, offset: 0xF8 */
  __IO uint32_t REFGW3;                            /**< Ref_G_Window3, offset: 0xFC */
  __IO uint32_t REFBW3;                            /**< Ref_B_Window3, offset: 0x100 */
  __IO uint32_t STATS0W3;                          /**< Stats0_Window3, offset: 0x104 */
  __IO uint32_t STATS1W3;                          /**< Stats1_Window3, offset: 0x108 */
  __IO uint32_t MINRSUW3;                          /**< Min_RedSum_Window3, offset: 0x10C */
  __IO uint32_t MINGSUW3;                          /**< Min_GreenSum_Window3, offset: 0x110 */
  __IO uint32_t MINBSUW3;                          /**< Min_BlueSum_Window3, offset: 0x114 */
  __IO uint32_t MINLUSW3;                          /**< Min_LumSum_Window3, offset: 0x118 */
  __IO uint32_t MAXRSUW3;                          /**< Max_RedSum_Window3, offset: 0x11C */
  __IO uint32_t MAXGSUW3;                          /**< Max_GreenSum_Window3, offset: 0x120 */
  __IO uint32_t MAXBSUW3;                          /**< Max_BlueSum_Window3, offset: 0x124 */
  __IO uint32_t MAXLUSW3;                          /**< Max_LumSum_Window3, offset: 0x128 */
  __IO uint32_t CONTW4;                            /**< Control_Window4, offset: 0x12C */
  __IO uint32_t UPPERLW4;                          /**< UpperLeft_Window4, offset: 0x130 */
  __IO uint32_t LOWRIW4;                           /**< LowerRight_Window4, offset: 0x134 */
  __IO uint32_t REFRW4;                            /**< Ref_R_Window4, offset: 0x138 */
  __IO uint32_t REFGW4;                            /**< Ref_G_Window4, offset: 0x13C */
  __IO uint32_t REFBW4;                            /**< Ref_B_Window4, offset: 0x140 */
  __IO uint32_t CONTW5;                            /**< Control_Window5, offset: 0x144 */
  __IO uint32_t UPPERLW5;                          /**< UpperLeft_Window5, offset: 0x148 */
  __IO uint32_t LOWRIW5;                           /**< LowerRight_Window5, offset: 0x14C */
  __IO uint32_t REFRW5;                            /**< Ref_R_Window5, offset: 0x150 */
  __IO uint32_t REFGW5;                            /**< Ref_G_Window5, offset: 0x154 */
  __IO uint32_t REFBW5;                            /**< Ref_B_Window5, offset: 0x158 */
  __IO uint32_t CONTW6;                            /**< Control_Window6, offset: 0x15C */
  __IO uint32_t UPPERLW6;                          /**< UpperLeft_Window6, offset: 0x160 */
  __IO uint32_t LOWRIW6;                           /**< LowerRight_Window6, offset: 0x164 */
  __IO uint32_t REFRW6;                            /**< Ref_R_Window6, offset: 0x168 */
  __IO uint32_t REFGW6;                            /**< Ref_G_Window6, offset: 0x16C */
  __IO uint32_t REFBW6;                            /**< Ref_B_Window6, offset: 0x170 */
  __IO uint32_t CONTW7;                            /**< Control_Window7, offset: 0x174 */
  __IO uint32_t UPPERLW7;                          /**< UpperLeft_Window7, offset: 0x178 */
  __IO uint32_t LOWRIW7;                           /**< LowerRight_Window7, offset: 0x17C */
  __IO uint32_t REFRW7;                            /**< Ref_R_Window7, offset: 0x180 */
  __IO uint32_t REFGW7;                            /**< Ref_G_Window7, offset: 0x184 */
  __IO uint32_t REFBW7;                            /**< Ref_B_Window7, offset: 0x188 */
  __IO uint32_t CONTRC0;                           /**< Control_Cluster0, offset: 0x18C */
  __IO uint32_t PIX0C0;                            /**< Pix0_Cluster0, offset: 0x190 */
  __IO uint32_t PIX1C0;                            /**< Pix1_Cluster0, offset: 0x194 */
  __IO uint32_t PIX2C0;                            /**< Pix2_Cluster0, offset: 0x198 */
  __IO uint32_t PIX3C0;                            /**< Pix3_Cluster0, offset: 0x19C */
  __IO uint32_t REF0CLU0;                          /**< Ref0_Cluster0, offset: 0x1A0 */
  __IO uint32_t REF1CLU0;                          /**< Ref1_Cluster0, offset: 0x1A4 */
  __IO uint32_t CONTRC1;                           /**< Control_Cluster1, offset: 0x1A8 */
  __IO uint32_t PIX0C1;                            /**< Pix0_Cluster1, offset: 0x1AC */
  __IO uint32_t PIX1C1;                            /**< Pix1_Cluster1, offset: 0x1B0 */
  __IO uint32_t PIX2C1;                            /**< Pix2_Cluster1, offset: 0x1B4 */
  __IO uint32_t PIX3C1;                            /**< Pix3_Cluster1, offset: 0x1B8 */
  __IO uint32_t REF0CLU1;                          /**< Ref0_Cluster1, offset: 0x1BC */
  __IO uint32_t REF1CLU1;                          /**< Ref1_Cluster1, offset: 0x1C0 */
  __IO uint32_t CONTRC2;                           /**< Control_Cluster2, offset: 0x1C4 */
  __IO uint32_t PIX0C2;                            /**< Pix0_Cluster2, offset: 0x1C8 */
  __IO uint32_t PIX1C2;                            /**< Pix1_Cluster2, offset: 0x1CC */
  __IO uint32_t PIX2C2;                            /**< Pix2_Cluster2, offset: 0x1D0 */
  __IO uint32_t PIX3C2;                            /**< Pix3_Cluster2, offset: 0x1D4 */
  __IO uint32_t REF0CLU2;                          /**< Ref0_Cluster2, offset: 0x1D8 */
  __IO uint32_t REF1CLU2;                          /**< Ref1_Cluster2, offset: 0x1DC */
  __IO uint32_t CONTRC3;                           /**< Control_Cluster3, offset: 0x1E0 */
  __IO uint32_t PIX0C3;                            /**< Pix0_Cluster3, offset: 0x1E4 */
  __IO uint32_t PIX1C3;                            /**< Pix1_Cluster3, offset: 0x1E8 */
  __IO uint32_t PIX2C3;                            /**< Pix2_Cluster3, offset: 0x1EC */
  __IO uint32_t PIX3C3;                            /**< Pix3_Cluster3, offset: 0x1F0 */
  __IO uint32_t REF0CLU3;                          /**< Ref0_Cluster3, offset: 0x1F4 */
  __IO uint32_t REF1CLU3;                          /**< Ref1_Cluster3, offset: 0x1F8 */
} sig_Type;

/* ----------------------------------------------------------------------------
   -- sig Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup sig_Register_Masks sig Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define sig_LU_LkUn_MASK                         (0xFFFFFFFFU)
#define sig_LU_LkUn_SHIFT                        (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define sig_LU_LkUn(x)                           (((uint32_t)(((uint32_t)(x)) << sig_LU_LkUn_SHIFT)) & sig_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define sig_LOCKS_LkSus_MASK                     (0x1U)
#define sig_LOCKS_LkSus_SHIFT                    (0U)
/*! LkSus - LockStatus */
#define sig_LOCKS_LkSus(x)                       (((uint32_t)(((uint32_t)(x)) << sig_LOCKS_LkSus_SHIFT)) & sig_LOCKS_LkSus_MASK)

#define sig_LOCKS_PriSt_MASK                     (0x10U)
#define sig_LOCKS_PriSt_SHIFT                    (4U)
/*! PriSt - PrivilegeStatus */
#define sig_LOCKS_PriSt(x)                       (((uint32_t)(((uint32_t)(x)) << sig_LOCKS_PriSt_SHIFT)) & sig_LOCKS_PriSt_MASK)

#define sig_LOCKS_FreezeS_MASK                   (0x100U)
#define sig_LOCKS_FreezeS_SHIFT                  (8U)
/*! FreezeS - FreezeStatus */
#define sig_LOCKS_FreezeS(x)                     (((uint32_t)(((uint32_t)(x)) << sig_LOCKS_FreezeS_SHIFT)) & sig_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define sig_STATCON_ShdEn_MASK                   (0x1U)
#define sig_STATCON_ShdEn_SHIFT                  (0U)
/*! ShdEn - ShdEn */
#define sig_STATCON_ShdEn(x)                     (((uint32_t)(((uint32_t)(x)) << sig_STATCON_ShdEn_SHIFT)) & sig_STATCON_ShdEn_MASK)

#define sig_STATCON_SdLdSel_MASK                 (0x10U)
#define sig_STATCON_SdLdSel_SHIFT                (4U)
/*! SdLdSel - ShdLdSel
 *  0b0..Shadows are loaded at start of frame for each evaluation window for which ShdLdReq has been set.
 *  0b1..Shadows of all evaluation windows are loaded synchronous to the display stream (shadow load token received on frame input port).
 */
#define sig_STATCON_SdLdSel(x)                   (((uint32_t)(((uint32_t)(x)) << sig_STATCON_SdLdSel_SHIFT)) & sig_STATCON_SdLdSel_MASK)
/*! @} */

/*! @name ERTHRES - ErrorThreshold */
/*! @{ */

#define sig_ERTHRES_ErrThres_MASK                (0xFFU)
#define sig_ERTHRES_ErrThres_SHIFT               (0U)
/*! ErrThres - ErrThres */
#define sig_ERTHRES_ErrThres(x)                  (((uint32_t)(((uint32_t)(x)) << sig_ERTHRES_ErrThres_SHIFT)) & sig_ERTHRES_ErrThres_MASK)

#define sig_ERTHRES_ErrThreR_MASK                (0xFF0000U)
#define sig_ERTHRES_ErrThreR_SHIFT               (16U)
/*! ErrThreR - ErrThresReset */
#define sig_ERTHRES_ErrThreR(x)                  (((uint32_t)(((uint32_t)(x)) << sig_ERTHRES_ErrThreR_SHIFT)) & sig_ERTHRES_ErrThreR_MASK)
/*! @} */

/*! @name MATCHTHR - MatchThreshold */
/*! @{ */

#define sig_MATCHTHR_MatchTh_MASK                (0xFFU)
#define sig_MATCHTHR_MatchTh_SHIFT               (0U)
/*! MatchTh - MatchThres */
#define sig_MATCHTHR_MatchTh(x)                  (((uint32_t)(((uint32_t)(x)) << sig_MATCHTHR_MatchTh_SHIFT)) & sig_MATCHTHR_MatchTh_MASK)

#define sig_MATCHTHR_MatchThR_MASK               (0xFF0000U)
#define sig_MATCHTHR_MatchThR_SHIFT              (16U)
/*! MatchThR - MatchThresReset */
#define sig_MATCHTHR_MatchThR(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MATCHTHR_MatchThR_SHIFT)) & sig_MATCHTHR_MatchThR_MASK)
/*! @} */

/*! @name PANICCOL - PanicColor */
/*! @{ */

#define sig_PANICCOL_PanA_MASK                   (0xFFU)
#define sig_PANICCOL_PanA_SHIFT                  (0U)
/*! PanA - PanicAlpha */
#define sig_PANICCOL_PanA(x)                     (((uint32_t)(((uint32_t)(x)) << sig_PANICCOL_PanA_SHIFT)) & sig_PANICCOL_PanA_MASK)

#define sig_PANICCOL_PanB_MASK                   (0xFF00U)
#define sig_PANICCOL_PanB_SHIFT                  (8U)
/*! PanB - PanicBlue */
#define sig_PANICCOL_PanB(x)                     (((uint32_t)(((uint32_t)(x)) << sig_PANICCOL_PanB_SHIFT)) & sig_PANICCOL_PanB_MASK)

#define sig_PANICCOL_PanG_MASK                   (0xFF0000U)
#define sig_PANICCOL_PanG_SHIFT                  (16U)
/*! PanG - PanicGreen */
#define sig_PANICCOL_PanG(x)                     (((uint32_t)(((uint32_t)(x)) << sig_PANICCOL_PanG_SHIFT)) & sig_PANICCOL_PanG_MASK)

#define sig_PANICCOL_PanR_MASK                   (0xFF000000U)
#define sig_PANICCOL_PanR_SHIFT                  (24U)
/*! PanR - PanicRed */
#define sig_PANICCOL_PanR(x)                     (((uint32_t)(((uint32_t)(x)) << sig_PANICCOL_PanR_SHIFT)) & sig_PANICCOL_PanR_MASK)
/*! @} */

/*! @name SHADOWLD - ShadowLoad */
/*! @{ */

#define sig_SHADOWLD_ShdLdRq_MASK                (0xFFU)
#define sig_SHADOWLD_ShdLdRq_SHIFT               (0U)
/*! ShdLdRq - ShdLdReq */
#define sig_SHADOWLD_ShdLdRq(x)                  (((uint32_t)(((uint32_t)(x)) << sig_SHADOWLD_ShdLdRq_SHIFT)) & sig_SHADOWLD_ShdLdRq_MASK)
/*! @} */

/*! @name CONTIMO - ContinuousMode */
/*! @{ */

#define sig_CONTIMO_EnCont_MASK                  (0x1U)
#define sig_CONTIMO_EnCont_SHIFT                 (0U)
/*! EnCont - EnCont */
#define sig_CONTIMO_EnCont(x)                    (((uint32_t)(((uint32_t)(x)) << sig_CONTIMO_EnCont_SHIFT)) & sig_CONTIMO_EnCont_MASK)
/*! @} */

/*! @name SOFTKICK - SoftwareKick */
/*! @{ */

#define sig_SOFTKICK_Kick_MASK                   (0x1U)
#define sig_SOFTKICK_Kick_SHIFT                  (0U)
/*! Kick - Kick */
#define sig_SOFTKICK_Kick(x)                     (((uint32_t)(((uint32_t)(x)) << sig_SOFTKICK_Kick_SHIFT)) & sig_SOFTKICK_Kick_MASK)
/*! @} */

/*! @name SKIPWIND - SkipWindow */
/*! @{ */

#define sig_SKIPWIND_SkipWiEn_MASK               (0x1U)
#define sig_SKIPWIND_SkipWiEn_SHIFT              (0U)
/*! SkipWiEn - SkipWinEn */
#define sig_SKIPWIND_SkipWiEn(x)                 (((uint32_t)(((uint32_t)(x)) << sig_SKIPWIND_SkipWiEn_SHIFT)) & sig_SKIPWIND_SkipWiEn_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define sig_STATUS_SigState_MASK                 (0x1U)
#define sig_STATUS_SigState_SHIFT                (0U)
/*! SigState - SigState
 *  0b0..Signature is in idle state
 *  0b1..Signature is in run state
 */
#define sig_STATUS_SigState(x)                   (((uint32_t)(((uint32_t)(x)) << sig_STATUS_SigState_SHIFT)) & sig_STATUS_SigState_MASK)

#define sig_STATUS_SigValid_MASK                 (0x2U)
#define sig_STATUS_SigValid_SHIFT                (1U)
/*! SigValid - SigValid
 *  0b0..Signature results are not valid
 *  0b1..Signature results are valid
 */
#define sig_STATUS_SigValid(x)                   (((uint32_t)(((uint32_t)(x)) << sig_STATUS_SigValid_SHIFT)) & sig_STATUS_SigValid_MASK)

#define sig_STATUS_WindowEr_MASK                 (0xFF00U)
#define sig_STATUS_WindowEr_SHIFT                (8U)
/*! WindowEr - Window_Error */
#define sig_STATUS_WindowEr(x)                   (((uint32_t)(((uint32_t)(x)) << sig_STATUS_WindowEr_SHIFT)) & sig_STATUS_WindowEr_MASK)

#define sig_STATUS_ClusterE_MASK                 (0xF0000U)
#define sig_STATUS_ClusterE_SHIFT                (16U)
/*! ClusterE - Cluster_Error */
#define sig_STATUS_ClusterE(x)                   (((uint32_t)(((uint32_t)(x)) << sig_STATUS_ClusterE_SHIFT)) & sig_STATUS_ClusterE_MASK)

#define sig_STATUS_ClusterM_MASK                 (0xF00000U)
#define sig_STATUS_ClusterM_SHIFT                (20U)
/*! ClusterM - Cluster_Match */
#define sig_STATUS_ClusterM(x)                   (((uint32_t)(((uint32_t)(x)) << sig_STATUS_ClusterM_SHIFT)) & sig_STATUS_ClusterM_MASK)
/*! @} */

/*! @name CONTW0 - Control_Window0 */
/*! @{ */

#define sig_CONTW0_EnWin0_MASK                   (0x1U)
#define sig_CONTW0_EnWin0_SHIFT                  (0U)
/*! EnWin0 - En_Window0 */
#define sig_CONTW0_EnWin0(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW0_EnWin0_SHIFT)) & sig_CONTW0_EnWin0_MASK)

#define sig_CONTW0_CRCW0_MASK                    (0x2U)
#define sig_CONTW0_CRCW0_SHIFT                   (1U)
/*! CRCW0 - CRC_Window0 */
#define sig_CONTW0_CRCW0(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW0_CRCW0_SHIFT)) & sig_CONTW0_CRCW0_MASK)

#define sig_CONTW0_AlpMaWi0_MASK                 (0x100U)
#define sig_CONTW0_AlpMaWi0_SHIFT                (8U)
/*! AlpMaWi0 - AlphaMask_Window0 */
#define sig_CONTW0_AlpMaWi0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW0_AlpMaWi0_SHIFT)) & sig_CONTW0_AlpMaWi0_MASK)

#define sig_CONTW0_AlpIWin0_MASK                 (0x200U)
#define sig_CONTW0_AlpIWin0_SHIFT                (9U)
/*! AlpIWin0 - AlphaInv_Window0 */
#define sig_CONTW0_AlpIWin0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW0_AlpIWin0_SHIFT)) & sig_CONTW0_AlpIWin0_MASK)

#define sig_CONTW0_AlpSW0_MASK                   (0x400U)
#define sig_CONTW0_AlpSW0_SHIFT                  (10U)
/*! AlpSW0 - AlphaSel_Window0 */
#define sig_CONTW0_AlpSW0(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW0_AlpSW0_SHIFT)) & sig_CONTW0_AlpSW0_MASK)

#define sig_CONTW0_LocPcW0_MASK                  (0x10000U)
#define sig_CONTW0_LocPcW0_SHIFT                 (16U)
/*! LocPcW0 - LocalPanic_Window0 */
#define sig_CONTW0_LocPcW0(x)                    (((uint32_t)(((uint32_t)(x)) << sig_CONTW0_LocPcW0_SHIFT)) & sig_CONTW0_LocPcW0_MASK)

#define sig_CONTW0_GlobPcW0_MASK                 (0x20000U)
#define sig_CONTW0_GlobPcW0_SHIFT                (17U)
/*! GlobPcW0 - GlobalPanic_Window0 */
#define sig_CONTW0_GlobPcW0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW0_GlobPcW0_SHIFT)) & sig_CONTW0_GlobPcW0_MASK)

#define sig_CONTW0_SumW0_MASK                    (0x1000000U)
#define sig_CONTW0_SumW0_SHIFT                   (24U)
/*! SumW0 - Sum_Window0 */
#define sig_CONTW0_SumW0(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW0_SumW0_SHIFT)) & sig_CONTW0_SumW0_MASK)
/*! @} */

/*! @name UPPERLW0 - UpperLeft_Window0 */
/*! @{ */

#define sig_UPPERLW0_UpLftXW0_MASK               (0x3FFFU)
#define sig_UPPERLW0_UpLftXW0_SHIFT              (0U)
/*! UpLftXW0 - UpperLeft_X_Window0 */
#define sig_UPPERLW0_UpLftXW0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW0_UpLftXW0_SHIFT)) & sig_UPPERLW0_UpLftXW0_MASK)

#define sig_UPPERLW0_UpLftYW0_MASK               (0x3FFF0000U)
#define sig_UPPERLW0_UpLftYW0_SHIFT              (16U)
/*! UpLftYW0 - UpperLeft_Y_Window0 */
#define sig_UPPERLW0_UpLftYW0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW0_UpLftYW0_SHIFT)) & sig_UPPERLW0_UpLftYW0_MASK)
/*! @} */

/*! @name LOWRIW0 - LowerRight_Window0 */
/*! @{ */

#define sig_LOWRIW0_LowRXW0_MASK                 (0x3FFFU)
#define sig_LOWRIW0_LowRXW0_SHIFT                (0U)
/*! LowRXW0 - LowerRight_X_Window0 */
#define sig_LOWRIW0_LowRXW0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW0_LowRXW0_SHIFT)) & sig_LOWRIW0_LowRXW0_MASK)

#define sig_LOWRIW0_LowRYW0_MASK                 (0x3FFF0000U)
#define sig_LOWRIW0_LowRYW0_SHIFT                (16U)
/*! LowRYW0 - LowerRight_Y_Window0 */
#define sig_LOWRIW0_LowRYW0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW0_LowRYW0_SHIFT)) & sig_LOWRIW0_LowRYW0_MASK)
/*! @} */

/*! @name REFRW0 - Ref_R_Window0 */
/*! @{ */

#define sig_REFRW0_RefRW0_MASK                   (0xFFFFFFFFU)
#define sig_REFRW0_RefRW0_SHIFT                  (0U)
/*! RefRW0 - Ref_R_Window0 */
#define sig_REFRW0_RefRW0(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFRW0_RefRW0_SHIFT)) & sig_REFRW0_RefRW0_MASK)
/*! @} */

/*! @name REFGW0 - Ref_G_Window0 */
/*! @{ */

#define sig_REFGW0_RefGW0_MASK                   (0xFFFFFFFFU)
#define sig_REFGW0_RefGW0_SHIFT                  (0U)
/*! RefGW0 - Ref_G_Window0 */
#define sig_REFGW0_RefGW0(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFGW0_RefGW0_SHIFT)) & sig_REFGW0_RefGW0_MASK)
/*! @} */

/*! @name REFBW0 - Ref_B_Window0 */
/*! @{ */

#define sig_REFBW0_RefBW0_MASK                   (0xFFFFFFFFU)
#define sig_REFBW0_RefBW0_SHIFT                  (0U)
/*! RefBW0 - Ref_B_Window0 */
#define sig_REFBW0_RefBW0(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFBW0_RefBW0_SHIFT)) & sig_REFBW0_RefBW0_MASK)
/*! @} */

/*! @name STATS0W0 - Stats0_Window0 */
/*! @{ */

#define sig_STATS0W0_AlpMS0W0_MASK               (0x1U)
#define sig_STATS0W0_AlpMS0W0_SHIFT              (0U)
/*! AlpMS0W0 - AlphaMask_S0_Win0 */
#define sig_STATS0W0_AlpMS0W0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W0_AlpMS0W0_SHIFT)) & sig_STATS0W0_AlpMS0W0_MASK)

#define sig_STATS0W0_AlpIS0W0_MASK               (0x2U)
#define sig_STATS0W0_AlpIS0W0_SHIFT              (1U)
/*! AlpIS0W0 - AlphaInv_S0_Win0 */
#define sig_STATS0W0_AlpIS0W0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W0_AlpIS0W0_SHIFT)) & sig_STATS0W0_AlpIS0W0_MASK)

#define sig_STATS0W0_AlpSS0W0_MASK               (0x4U)
#define sig_STATS0W0_AlpSS0W0_SHIFT              (2U)
/*! AlpSS0W0 - AlphaSel_S0_Win0 */
#define sig_STATS0W0_AlpSS0W0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W0_AlpSS0W0_SHIFT)) & sig_STATS0W0_AlpSS0W0_MASK)
/*! @} */

/*! @name STATS1W0 - Stats1_Window0 */
/*! @{ */

#define sig_STATS1W0_AlpMS1W0_MASK               (0x1U)
#define sig_STATS1W0_AlpMS1W0_SHIFT              (0U)
/*! AlpMS1W0 - AlphaMask_S1_Win0 */
#define sig_STATS1W0_AlpMS1W0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W0_AlpMS1W0_SHIFT)) & sig_STATS1W0_AlpMS1W0_MASK)

#define sig_STATS1W0_AlpIS1W0_MASK               (0x2U)
#define sig_STATS1W0_AlpIS1W0_SHIFT              (1U)
/*! AlpIS1W0 - AlphaInv_S1_Win0 */
#define sig_STATS1W0_AlpIS1W0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W0_AlpIS1W0_SHIFT)) & sig_STATS1W0_AlpIS1W0_MASK)

#define sig_STATS1W0_AlpSS1W0_MASK               (0x4U)
#define sig_STATS1W0_AlpSS1W0_SHIFT              (2U)
/*! AlpSS1W0 - AlphaSel_S1_Win0 */
#define sig_STATS1W0_AlpSS1W0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W0_AlpSS1W0_SHIFT)) & sig_STATS1W0_AlpSS1W0_MASK)
/*! @} */

/*! @name MINRSUW0 - Min_RedSum_Window0 */
/*! @{ */

#define sig_MINRSUW0_MinRSuW0_MASK               (0xFFFFFFFFU)
#define sig_MINRSUW0_MinRSuW0_SHIFT              (0U)
/*! MinRSuW0 - Min_RSum_Win0 */
#define sig_MINRSUW0_MinRSuW0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINRSUW0_MinRSuW0_SHIFT)) & sig_MINRSUW0_MinRSuW0_MASK)
/*! @} */

/*! @name MINGSUW0 - Min_GreenSum_Window0 */
/*! @{ */

#define sig_MINGSUW0_MinGSuW0_MASK               (0xFFFFFFFFU)
#define sig_MINGSUW0_MinGSuW0_SHIFT              (0U)
/*! MinGSuW0 - Min_GSum_Win0 */
#define sig_MINGSUW0_MinGSuW0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINGSUW0_MinGSuW0_SHIFT)) & sig_MINGSUW0_MinGSuW0_MASK)
/*! @} */

/*! @name MINBSUW0 - Min_BlueSum_Window0 */
/*! @{ */

#define sig_MINBSUW0_MinBSuW0_MASK               (0xFFFFFFFFU)
#define sig_MINBSUW0_MinBSuW0_SHIFT              (0U)
/*! MinBSuW0 - Min_BSum_Win0 */
#define sig_MINBSUW0_MinBSuW0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINBSUW0_MinBSuW0_SHIFT)) & sig_MINBSUW0_MinBSuW0_MASK)
/*! @} */

/*! @name MINLUSW0 - Min_LumSum_Window0 */
/*! @{ */

#define sig_MINLUSW0_MinLSuW0_MASK               (0xFFFFFFFFU)
#define sig_MINLUSW0_MinLSuW0_SHIFT              (0U)
/*! MinLSuW0 - Min_LSum_Win0 */
#define sig_MINLUSW0_MinLSuW0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINLUSW0_MinLSuW0_SHIFT)) & sig_MINLUSW0_MinLSuW0_MASK)
/*! @} */

/*! @name MAXRSUW0 - Max_RedSum_Window0 */
/*! @{ */

#define sig_MAXRSUW0_MaxRSuW0_MASK               (0xFFFFFFFFU)
#define sig_MAXRSUW0_MaxRSuW0_SHIFT              (0U)
/*! MaxRSuW0 - Max_RSum_Win0 */
#define sig_MAXRSUW0_MaxRSuW0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXRSUW0_MaxRSuW0_SHIFT)) & sig_MAXRSUW0_MaxRSuW0_MASK)
/*! @} */

/*! @name MAXGSUW0 - Max_GreenSum_Window0 */
/*! @{ */

#define sig_MAXGSUW0_MaxGSuW0_MASK               (0xFFFFFFFFU)
#define sig_MAXGSUW0_MaxGSuW0_SHIFT              (0U)
/*! MaxGSuW0 - Max_GSum_Win0 */
#define sig_MAXGSUW0_MaxGSuW0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXGSUW0_MaxGSuW0_SHIFT)) & sig_MAXGSUW0_MaxGSuW0_MASK)
/*! @} */

/*! @name MAXBSUW0 - Max_BlueSum_Window0 */
/*! @{ */

#define sig_MAXBSUW0_MaxBSuW0_MASK               (0xFFFFFFFFU)
#define sig_MAXBSUW0_MaxBSuW0_SHIFT              (0U)
/*! MaxBSuW0 - Max_BSum_Win0 */
#define sig_MAXBSUW0_MaxBSuW0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXBSUW0_MaxBSuW0_SHIFT)) & sig_MAXBSUW0_MaxBSuW0_MASK)
/*! @} */

/*! @name MAXLUSW0 - Max_LumSum_Window0 */
/*! @{ */

#define sig_MAXLUSW0_MaxLSuW0_MASK               (0xFFFFFFFFU)
#define sig_MAXLUSW0_MaxLSuW0_SHIFT              (0U)
/*! MaxLSuW0 - Max_LSum_Win0 */
#define sig_MAXLUSW0_MaxLSuW0(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXLUSW0_MaxLSuW0_SHIFT)) & sig_MAXLUSW0_MaxLSuW0_MASK)
/*! @} */

/*! @name CONTW1 - Control_Window1 */
/*! @{ */

#define sig_CONTW1_EnWin1_MASK                   (0x1U)
#define sig_CONTW1_EnWin1_SHIFT                  (0U)
/*! EnWin1 - En_Window1 */
#define sig_CONTW1_EnWin1(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW1_EnWin1_SHIFT)) & sig_CONTW1_EnWin1_MASK)

#define sig_CONTW1_CRCW1_MASK                    (0x2U)
#define sig_CONTW1_CRCW1_SHIFT                   (1U)
/*! CRCW1 - CRC_Window1 */
#define sig_CONTW1_CRCW1(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW1_CRCW1_SHIFT)) & sig_CONTW1_CRCW1_MASK)

#define sig_CONTW1_AlpMaWi1_MASK                 (0x100U)
#define sig_CONTW1_AlpMaWi1_SHIFT                (8U)
/*! AlpMaWi1 - AlphaMask_Window1 */
#define sig_CONTW1_AlpMaWi1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW1_AlpMaWi1_SHIFT)) & sig_CONTW1_AlpMaWi1_MASK)

#define sig_CONTW1_AlpIWin1_MASK                 (0x200U)
#define sig_CONTW1_AlpIWin1_SHIFT                (9U)
/*! AlpIWin1 - AlphaInv_Window1 */
#define sig_CONTW1_AlpIWin1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW1_AlpIWin1_SHIFT)) & sig_CONTW1_AlpIWin1_MASK)

#define sig_CONTW1_AlpSW1_MASK                   (0x400U)
#define sig_CONTW1_AlpSW1_SHIFT                  (10U)
/*! AlpSW1 - AlphaSel_Window1 */
#define sig_CONTW1_AlpSW1(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW1_AlpSW1_SHIFT)) & sig_CONTW1_AlpSW1_MASK)

#define sig_CONTW1_LocPcW1_MASK                  (0x10000U)
#define sig_CONTW1_LocPcW1_SHIFT                 (16U)
/*! LocPcW1 - LocalPanic_Window1 */
#define sig_CONTW1_LocPcW1(x)                    (((uint32_t)(((uint32_t)(x)) << sig_CONTW1_LocPcW1_SHIFT)) & sig_CONTW1_LocPcW1_MASK)

#define sig_CONTW1_GlobPcW1_MASK                 (0x20000U)
#define sig_CONTW1_GlobPcW1_SHIFT                (17U)
/*! GlobPcW1 - GlobalPanic_Window1 */
#define sig_CONTW1_GlobPcW1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW1_GlobPcW1_SHIFT)) & sig_CONTW1_GlobPcW1_MASK)

#define sig_CONTW1_SumW1_MASK                    (0x1000000U)
#define sig_CONTW1_SumW1_SHIFT                   (24U)
/*! SumW1 - Sum_Window1 */
#define sig_CONTW1_SumW1(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW1_SumW1_SHIFT)) & sig_CONTW1_SumW1_MASK)
/*! @} */

/*! @name UPPERLW1 - UpperLeft_Window1 */
/*! @{ */

#define sig_UPPERLW1_UpLftXW1_MASK               (0x3FFFU)
#define sig_UPPERLW1_UpLftXW1_SHIFT              (0U)
/*! UpLftXW1 - UpperLeft_X_Window1 */
#define sig_UPPERLW1_UpLftXW1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW1_UpLftXW1_SHIFT)) & sig_UPPERLW1_UpLftXW1_MASK)

#define sig_UPPERLW1_UpLftYW1_MASK               (0x3FFF0000U)
#define sig_UPPERLW1_UpLftYW1_SHIFT              (16U)
/*! UpLftYW1 - UpperLeft_Y_Window1 */
#define sig_UPPERLW1_UpLftYW1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW1_UpLftYW1_SHIFT)) & sig_UPPERLW1_UpLftYW1_MASK)
/*! @} */

/*! @name LOWRIW1 - LowerRight_Window1 */
/*! @{ */

#define sig_LOWRIW1_LowRXW1_MASK                 (0x3FFFU)
#define sig_LOWRIW1_LowRXW1_SHIFT                (0U)
/*! LowRXW1 - LowerRight_X_Window1 */
#define sig_LOWRIW1_LowRXW1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW1_LowRXW1_SHIFT)) & sig_LOWRIW1_LowRXW1_MASK)

#define sig_LOWRIW1_LowRYW1_MASK                 (0x3FFF0000U)
#define sig_LOWRIW1_LowRYW1_SHIFT                (16U)
/*! LowRYW1 - LowerRight_Y_Window1 */
#define sig_LOWRIW1_LowRYW1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW1_LowRYW1_SHIFT)) & sig_LOWRIW1_LowRYW1_MASK)
/*! @} */

/*! @name REFRW1 - Ref_R_Window1 */
/*! @{ */

#define sig_REFRW1_RefRW1_MASK                   (0xFFFFFFFFU)
#define sig_REFRW1_RefRW1_SHIFT                  (0U)
/*! RefRW1 - Ref_R_Window1 */
#define sig_REFRW1_RefRW1(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFRW1_RefRW1_SHIFT)) & sig_REFRW1_RefRW1_MASK)
/*! @} */

/*! @name REFGW1 - Ref_G_Window1 */
/*! @{ */

#define sig_REFGW1_RefGW1_MASK                   (0xFFFFFFFFU)
#define sig_REFGW1_RefGW1_SHIFT                  (0U)
/*! RefGW1 - Ref_G_Window1 */
#define sig_REFGW1_RefGW1(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFGW1_RefGW1_SHIFT)) & sig_REFGW1_RefGW1_MASK)
/*! @} */

/*! @name REFBW1 - Ref_B_Window1 */
/*! @{ */

#define sig_REFBW1_RefBW1_MASK                   (0xFFFFFFFFU)
#define sig_REFBW1_RefBW1_SHIFT                  (0U)
/*! RefBW1 - Ref_B_Window1 */
#define sig_REFBW1_RefBW1(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFBW1_RefBW1_SHIFT)) & sig_REFBW1_RefBW1_MASK)
/*! @} */

/*! @name STATS0W1 - Stats0_Window1 */
/*! @{ */

#define sig_STATS0W1_AlpMS0W1_MASK               (0x1U)
#define sig_STATS0W1_AlpMS0W1_SHIFT              (0U)
/*! AlpMS0W1 - AlphaMask_S0_Win1 */
#define sig_STATS0W1_AlpMS0W1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W1_AlpMS0W1_SHIFT)) & sig_STATS0W1_AlpMS0W1_MASK)

#define sig_STATS0W1_AlpIS0W1_MASK               (0x2U)
#define sig_STATS0W1_AlpIS0W1_SHIFT              (1U)
/*! AlpIS0W1 - AlphaInv_S0_Win1 */
#define sig_STATS0W1_AlpIS0W1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W1_AlpIS0W1_SHIFT)) & sig_STATS0W1_AlpIS0W1_MASK)

#define sig_STATS0W1_AlpSS0W1_MASK               (0x4U)
#define sig_STATS0W1_AlpSS0W1_SHIFT              (2U)
/*! AlpSS0W1 - AlphaSel_S0_Win1 */
#define sig_STATS0W1_AlpSS0W1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W1_AlpSS0W1_SHIFT)) & sig_STATS0W1_AlpSS0W1_MASK)
/*! @} */

/*! @name STATS1W1 - Stats1_Window1 */
/*! @{ */

#define sig_STATS1W1_AlpMS1W1_MASK               (0x1U)
#define sig_STATS1W1_AlpMS1W1_SHIFT              (0U)
/*! AlpMS1W1 - AlphaMask_S1_Win1 */
#define sig_STATS1W1_AlpMS1W1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W1_AlpMS1W1_SHIFT)) & sig_STATS1W1_AlpMS1W1_MASK)

#define sig_STATS1W1_AlpIS1W1_MASK               (0x2U)
#define sig_STATS1W1_AlpIS1W1_SHIFT              (1U)
/*! AlpIS1W1 - AlphaInv_S1_Win1 */
#define sig_STATS1W1_AlpIS1W1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W1_AlpIS1W1_SHIFT)) & sig_STATS1W1_AlpIS1W1_MASK)

#define sig_STATS1W1_AlpSS1W1_MASK               (0x4U)
#define sig_STATS1W1_AlpSS1W1_SHIFT              (2U)
/*! AlpSS1W1 - AlphaSel_S1_Win1 */
#define sig_STATS1W1_AlpSS1W1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W1_AlpSS1W1_SHIFT)) & sig_STATS1W1_AlpSS1W1_MASK)
/*! @} */

/*! @name MINRSUW1 - Min_RedSum_Window1 */
/*! @{ */

#define sig_MINRSUW1_MinRSuW1_MASK               (0xFFFFFFFFU)
#define sig_MINRSUW1_MinRSuW1_SHIFT              (0U)
/*! MinRSuW1 - Min_RSum_Win1 */
#define sig_MINRSUW1_MinRSuW1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINRSUW1_MinRSuW1_SHIFT)) & sig_MINRSUW1_MinRSuW1_MASK)
/*! @} */

/*! @name MINGSUW1 - Min_GreenSum_Window1 */
/*! @{ */

#define sig_MINGSUW1_MinGSuW1_MASK               (0xFFFFFFFFU)
#define sig_MINGSUW1_MinGSuW1_SHIFT              (0U)
/*! MinGSuW1 - Min_GSum_Win1 */
#define sig_MINGSUW1_MinGSuW1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINGSUW1_MinGSuW1_SHIFT)) & sig_MINGSUW1_MinGSuW1_MASK)
/*! @} */

/*! @name MINBSUW1 - Min_BlueSum_Window1 */
/*! @{ */

#define sig_MINBSUW1_MinBSuW1_MASK               (0xFFFFFFFFU)
#define sig_MINBSUW1_MinBSuW1_SHIFT              (0U)
/*! MinBSuW1 - Min_BSum_Win1 */
#define sig_MINBSUW1_MinBSuW1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINBSUW1_MinBSuW1_SHIFT)) & sig_MINBSUW1_MinBSuW1_MASK)
/*! @} */

/*! @name MINLUSW1 - Min_LumSum_Window1 */
/*! @{ */

#define sig_MINLUSW1_MinLSuW1_MASK               (0xFFFFFFFFU)
#define sig_MINLUSW1_MinLSuW1_SHIFT              (0U)
/*! MinLSuW1 - Min_LSum_Win1 */
#define sig_MINLUSW1_MinLSuW1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINLUSW1_MinLSuW1_SHIFT)) & sig_MINLUSW1_MinLSuW1_MASK)
/*! @} */

/*! @name MAXRSUW1 - Max_RedSum_Window1 */
/*! @{ */

#define sig_MAXRSUW1_MaxRSuW1_MASK               (0xFFFFFFFFU)
#define sig_MAXRSUW1_MaxRSuW1_SHIFT              (0U)
/*! MaxRSuW1 - Max_RSum_Win1 */
#define sig_MAXRSUW1_MaxRSuW1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXRSUW1_MaxRSuW1_SHIFT)) & sig_MAXRSUW1_MaxRSuW1_MASK)
/*! @} */

/*! @name MAXGSUW1 - Max_GreenSum_Window1 */
/*! @{ */

#define sig_MAXGSUW1_MaxGSuW1_MASK               (0xFFFFFFFFU)
#define sig_MAXGSUW1_MaxGSuW1_SHIFT              (0U)
/*! MaxGSuW1 - Max_GSum_Win1 */
#define sig_MAXGSUW1_MaxGSuW1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXGSUW1_MaxGSuW1_SHIFT)) & sig_MAXGSUW1_MaxGSuW1_MASK)
/*! @} */

/*! @name MAXBSUW1 - Max_BlueSum_Window1 */
/*! @{ */

#define sig_MAXBSUW1_MaxBSuW1_MASK               (0xFFFFFFFFU)
#define sig_MAXBSUW1_MaxBSuW1_SHIFT              (0U)
/*! MaxBSuW1 - Max_BSum_Win1 */
#define sig_MAXBSUW1_MaxBSuW1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXBSUW1_MaxBSuW1_SHIFT)) & sig_MAXBSUW1_MaxBSuW1_MASK)
/*! @} */

/*! @name MAXLUSW1 - Max_LumSum_Window1 */
/*! @{ */

#define sig_MAXLUSW1_MaxLSuW1_MASK               (0xFFFFFFFFU)
#define sig_MAXLUSW1_MaxLSuW1_SHIFT              (0U)
/*! MaxLSuW1 - Max_LSum_Win1 */
#define sig_MAXLUSW1_MaxLSuW1(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXLUSW1_MaxLSuW1_SHIFT)) & sig_MAXLUSW1_MaxLSuW1_MASK)
/*! @} */

/*! @name CONTW2 - Control_Window2 */
/*! @{ */

#define sig_CONTW2_EnWin2_MASK                   (0x1U)
#define sig_CONTW2_EnWin2_SHIFT                  (0U)
/*! EnWin2 - En_Window2 */
#define sig_CONTW2_EnWin2(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW2_EnWin2_SHIFT)) & sig_CONTW2_EnWin2_MASK)

#define sig_CONTW2_CRCW2_MASK                    (0x2U)
#define sig_CONTW2_CRCW2_SHIFT                   (1U)
/*! CRCW2 - CRC_Window2 */
#define sig_CONTW2_CRCW2(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW2_CRCW2_SHIFT)) & sig_CONTW2_CRCW2_MASK)

#define sig_CONTW2_AlpMaWi2_MASK                 (0x100U)
#define sig_CONTW2_AlpMaWi2_SHIFT                (8U)
/*! AlpMaWi2 - AlphaMask_Window2 */
#define sig_CONTW2_AlpMaWi2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW2_AlpMaWi2_SHIFT)) & sig_CONTW2_AlpMaWi2_MASK)

#define sig_CONTW2_AlpIWin2_MASK                 (0x200U)
#define sig_CONTW2_AlpIWin2_SHIFT                (9U)
/*! AlpIWin2 - AlphaInv_Window2 */
#define sig_CONTW2_AlpIWin2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW2_AlpIWin2_SHIFT)) & sig_CONTW2_AlpIWin2_MASK)

#define sig_CONTW2_AlpSW2_MASK                   (0x400U)
#define sig_CONTW2_AlpSW2_SHIFT                  (10U)
/*! AlpSW2 - AlphaSel_Window2 */
#define sig_CONTW2_AlpSW2(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW2_AlpSW2_SHIFT)) & sig_CONTW2_AlpSW2_MASK)

#define sig_CONTW2_LocPcW2_MASK                  (0x10000U)
#define sig_CONTW2_LocPcW2_SHIFT                 (16U)
/*! LocPcW2 - LocalPanic_Window2 */
#define sig_CONTW2_LocPcW2(x)                    (((uint32_t)(((uint32_t)(x)) << sig_CONTW2_LocPcW2_SHIFT)) & sig_CONTW2_LocPcW2_MASK)

#define sig_CONTW2_GlobPcW2_MASK                 (0x20000U)
#define sig_CONTW2_GlobPcW2_SHIFT                (17U)
/*! GlobPcW2 - GlobalPanic_Window2 */
#define sig_CONTW2_GlobPcW2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW2_GlobPcW2_SHIFT)) & sig_CONTW2_GlobPcW2_MASK)

#define sig_CONTW2_SumW2_MASK                    (0x1000000U)
#define sig_CONTW2_SumW2_SHIFT                   (24U)
/*! SumW2 - Sum_Window2 */
#define sig_CONTW2_SumW2(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW2_SumW2_SHIFT)) & sig_CONTW2_SumW2_MASK)
/*! @} */

/*! @name UPPERLW2 - UpperLeft_Window2 */
/*! @{ */

#define sig_UPPERLW2_UpLftXW2_MASK               (0x3FFFU)
#define sig_UPPERLW2_UpLftXW2_SHIFT              (0U)
/*! UpLftXW2 - UpperLeft_X_Window2 */
#define sig_UPPERLW2_UpLftXW2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW2_UpLftXW2_SHIFT)) & sig_UPPERLW2_UpLftXW2_MASK)

#define sig_UPPERLW2_UpLftYW2_MASK               (0x3FFF0000U)
#define sig_UPPERLW2_UpLftYW2_SHIFT              (16U)
/*! UpLftYW2 - UpperLeft_Y_Window2 */
#define sig_UPPERLW2_UpLftYW2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW2_UpLftYW2_SHIFT)) & sig_UPPERLW2_UpLftYW2_MASK)
/*! @} */

/*! @name LOWRIW2 - LowerRight_Window2 */
/*! @{ */

#define sig_LOWRIW2_LowRXW2_MASK                 (0x3FFFU)
#define sig_LOWRIW2_LowRXW2_SHIFT                (0U)
/*! LowRXW2 - LowerRight_X_Window2 */
#define sig_LOWRIW2_LowRXW2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW2_LowRXW2_SHIFT)) & sig_LOWRIW2_LowRXW2_MASK)

#define sig_LOWRIW2_LowRYW2_MASK                 (0x3FFF0000U)
#define sig_LOWRIW2_LowRYW2_SHIFT                (16U)
/*! LowRYW2 - LowerRight_Y_Window2 */
#define sig_LOWRIW2_LowRYW2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW2_LowRYW2_SHIFT)) & sig_LOWRIW2_LowRYW2_MASK)
/*! @} */

/*! @name REFRW2 - Ref_R_Window2 */
/*! @{ */

#define sig_REFRW2_RefRW2_MASK                   (0xFFFFFFFFU)
#define sig_REFRW2_RefRW2_SHIFT                  (0U)
/*! RefRW2 - Ref_R_Window2 */
#define sig_REFRW2_RefRW2(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFRW2_RefRW2_SHIFT)) & sig_REFRW2_RefRW2_MASK)
/*! @} */

/*! @name REFGW2 - Ref_G_Window2 */
/*! @{ */

#define sig_REFGW2_RefGW2_MASK                   (0xFFFFFFFFU)
#define sig_REFGW2_RefGW2_SHIFT                  (0U)
/*! RefGW2 - Ref_G_Window2 */
#define sig_REFGW2_RefGW2(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFGW2_RefGW2_SHIFT)) & sig_REFGW2_RefGW2_MASK)
/*! @} */

/*! @name REFBW2 - Ref_B_Window2 */
/*! @{ */

#define sig_REFBW2_RefBW2_MASK                   (0xFFFFFFFFU)
#define sig_REFBW2_RefBW2_SHIFT                  (0U)
/*! RefBW2 - Ref_B_Window2 */
#define sig_REFBW2_RefBW2(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFBW2_RefBW2_SHIFT)) & sig_REFBW2_RefBW2_MASK)
/*! @} */

/*! @name STATS0W2 - Stats0_Window2 */
/*! @{ */

#define sig_STATS0W2_AlpMS0W2_MASK               (0x1U)
#define sig_STATS0W2_AlpMS0W2_SHIFT              (0U)
/*! AlpMS0W2 - AlphaMask_S0_Win2 */
#define sig_STATS0W2_AlpMS0W2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W2_AlpMS0W2_SHIFT)) & sig_STATS0W2_AlpMS0W2_MASK)

#define sig_STATS0W2_AlpIS0W2_MASK               (0x2U)
#define sig_STATS0W2_AlpIS0W2_SHIFT              (1U)
/*! AlpIS0W2 - AlphaInv_S0_Win2 */
#define sig_STATS0W2_AlpIS0W2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W2_AlpIS0W2_SHIFT)) & sig_STATS0W2_AlpIS0W2_MASK)

#define sig_STATS0W2_AlpSS0W2_MASK               (0x4U)
#define sig_STATS0W2_AlpSS0W2_SHIFT              (2U)
/*! AlpSS0W2 - AlphaSel_S0_Win2 */
#define sig_STATS0W2_AlpSS0W2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W2_AlpSS0W2_SHIFT)) & sig_STATS0W2_AlpSS0W2_MASK)
/*! @} */

/*! @name STATS1W2 - Stats1_Window2 */
/*! @{ */

#define sig_STATS1W2_AlpMS1W2_MASK               (0x1U)
#define sig_STATS1W2_AlpMS1W2_SHIFT              (0U)
/*! AlpMS1W2 - AlphaMask_S1_Win2 */
#define sig_STATS1W2_AlpMS1W2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W2_AlpMS1W2_SHIFT)) & sig_STATS1W2_AlpMS1W2_MASK)

#define sig_STATS1W2_AlpIS1W2_MASK               (0x2U)
#define sig_STATS1W2_AlpIS1W2_SHIFT              (1U)
/*! AlpIS1W2 - AlphaInv_S1_Win2 */
#define sig_STATS1W2_AlpIS1W2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W2_AlpIS1W2_SHIFT)) & sig_STATS1W2_AlpIS1W2_MASK)

#define sig_STATS1W2_AlpSS1W2_MASK               (0x4U)
#define sig_STATS1W2_AlpSS1W2_SHIFT              (2U)
/*! AlpSS1W2 - AlphaSel_S1_Win2 */
#define sig_STATS1W2_AlpSS1W2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W2_AlpSS1W2_SHIFT)) & sig_STATS1W2_AlpSS1W2_MASK)
/*! @} */

/*! @name MINRSUW2 - Min_RedSum_Window2 */
/*! @{ */

#define sig_MINRSUW2_MinRSuW2_MASK               (0xFFFFFFFFU)
#define sig_MINRSUW2_MinRSuW2_SHIFT              (0U)
/*! MinRSuW2 - Min_RSum_Win2 */
#define sig_MINRSUW2_MinRSuW2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINRSUW2_MinRSuW2_SHIFT)) & sig_MINRSUW2_MinRSuW2_MASK)
/*! @} */

/*! @name MINGSUW2 - Min_GreenSum_Window2 */
/*! @{ */

#define sig_MINGSUW2_MinGSuW2_MASK               (0xFFFFFFFFU)
#define sig_MINGSUW2_MinGSuW2_SHIFT              (0U)
/*! MinGSuW2 - Min_GSum_Win2 */
#define sig_MINGSUW2_MinGSuW2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINGSUW2_MinGSuW2_SHIFT)) & sig_MINGSUW2_MinGSuW2_MASK)
/*! @} */

/*! @name MINBSUW2 - Min_BlueSum_Window2 */
/*! @{ */

#define sig_MINBSUW2_MinBSuW2_MASK               (0xFFFFFFFFU)
#define sig_MINBSUW2_MinBSuW2_SHIFT              (0U)
/*! MinBSuW2 - Min_BSum_Win2 */
#define sig_MINBSUW2_MinBSuW2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINBSUW2_MinBSuW2_SHIFT)) & sig_MINBSUW2_MinBSuW2_MASK)
/*! @} */

/*! @name MINLUSW2 - Min_LumSum_Window2 */
/*! @{ */

#define sig_MINLUSW2_MinLSuW2_MASK               (0xFFFFFFFFU)
#define sig_MINLUSW2_MinLSuW2_SHIFT              (0U)
/*! MinLSuW2 - Min_LSum_Win2 */
#define sig_MINLUSW2_MinLSuW2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINLUSW2_MinLSuW2_SHIFT)) & sig_MINLUSW2_MinLSuW2_MASK)
/*! @} */

/*! @name MAXRSUW2 - Max_RedSum_Window2 */
/*! @{ */

#define sig_MAXRSUW2_MaxRSuW2_MASK               (0xFFFFFFFFU)
#define sig_MAXRSUW2_MaxRSuW2_SHIFT              (0U)
/*! MaxRSuW2 - Max_RSum_Win2 */
#define sig_MAXRSUW2_MaxRSuW2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXRSUW2_MaxRSuW2_SHIFT)) & sig_MAXRSUW2_MaxRSuW2_MASK)
/*! @} */

/*! @name MAXGSUW2 - Max_GreenSum_Window2 */
/*! @{ */

#define sig_MAXGSUW2_MaxGSuW2_MASK               (0xFFFFFFFFU)
#define sig_MAXGSUW2_MaxGSuW2_SHIFT              (0U)
/*! MaxGSuW2 - Max_GSum_Win2 */
#define sig_MAXGSUW2_MaxGSuW2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXGSUW2_MaxGSuW2_SHIFT)) & sig_MAXGSUW2_MaxGSuW2_MASK)
/*! @} */

/*! @name MAXBSUW2 - Max_BlueSum_Window2 */
/*! @{ */

#define sig_MAXBSUW2_MaxBSuW2_MASK               (0xFFFFFFFFU)
#define sig_MAXBSUW2_MaxBSuW2_SHIFT              (0U)
/*! MaxBSuW2 - Max_BSum_Win2 */
#define sig_MAXBSUW2_MaxBSuW2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXBSUW2_MaxBSuW2_SHIFT)) & sig_MAXBSUW2_MaxBSuW2_MASK)
/*! @} */

/*! @name MAXLUSW2 - Max_LumSum_Window2 */
/*! @{ */

#define sig_MAXLUSW2_MaxLSuW2_MASK               (0xFFFFFFFFU)
#define sig_MAXLUSW2_MaxLSuW2_SHIFT              (0U)
/*! MaxLSuW2 - Max_LSum_Win2 */
#define sig_MAXLUSW2_MaxLSuW2(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXLUSW2_MaxLSuW2_SHIFT)) & sig_MAXLUSW2_MaxLSuW2_MASK)
/*! @} */

/*! @name CONTW3 - Control_Window3 */
/*! @{ */

#define sig_CONTW3_EnWin3_MASK                   (0x1U)
#define sig_CONTW3_EnWin3_SHIFT                  (0U)
/*! EnWin3 - En_Window3 */
#define sig_CONTW3_EnWin3(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW3_EnWin3_SHIFT)) & sig_CONTW3_EnWin3_MASK)

#define sig_CONTW3_CRCW3_MASK                    (0x2U)
#define sig_CONTW3_CRCW3_SHIFT                   (1U)
/*! CRCW3 - CRC_Window3 */
#define sig_CONTW3_CRCW3(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW3_CRCW3_SHIFT)) & sig_CONTW3_CRCW3_MASK)

#define sig_CONTW3_AlpMaWi3_MASK                 (0x100U)
#define sig_CONTW3_AlpMaWi3_SHIFT                (8U)
/*! AlpMaWi3 - AlphaMask_Window3 */
#define sig_CONTW3_AlpMaWi3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW3_AlpMaWi3_SHIFT)) & sig_CONTW3_AlpMaWi3_MASK)

#define sig_CONTW3_AlpIWin3_MASK                 (0x200U)
#define sig_CONTW3_AlpIWin3_SHIFT                (9U)
/*! AlpIWin3 - AlphaInv_Window3 */
#define sig_CONTW3_AlpIWin3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW3_AlpIWin3_SHIFT)) & sig_CONTW3_AlpIWin3_MASK)

#define sig_CONTW3_AlpSW3_MASK                   (0x400U)
#define sig_CONTW3_AlpSW3_SHIFT                  (10U)
/*! AlpSW3 - AlphaSel_Window3 */
#define sig_CONTW3_AlpSW3(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW3_AlpSW3_SHIFT)) & sig_CONTW3_AlpSW3_MASK)

#define sig_CONTW3_LocPcW3_MASK                  (0x10000U)
#define sig_CONTW3_LocPcW3_SHIFT                 (16U)
/*! LocPcW3 - LocalPanic_Window3 */
#define sig_CONTW3_LocPcW3(x)                    (((uint32_t)(((uint32_t)(x)) << sig_CONTW3_LocPcW3_SHIFT)) & sig_CONTW3_LocPcW3_MASK)

#define sig_CONTW3_GlobPcW3_MASK                 (0x20000U)
#define sig_CONTW3_GlobPcW3_SHIFT                (17U)
/*! GlobPcW3 - GlobalPanic_Window3 */
#define sig_CONTW3_GlobPcW3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW3_GlobPcW3_SHIFT)) & sig_CONTW3_GlobPcW3_MASK)

#define sig_CONTW3_SumW3_MASK                    (0x1000000U)
#define sig_CONTW3_SumW3_SHIFT                   (24U)
/*! SumW3 - Sum_Window3 */
#define sig_CONTW3_SumW3(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW3_SumW3_SHIFT)) & sig_CONTW3_SumW3_MASK)
/*! @} */

/*! @name UPPERLW3 - UpperLeft_Window3 */
/*! @{ */

#define sig_UPPERLW3_UpLftXW3_MASK               (0x3FFFU)
#define sig_UPPERLW3_UpLftXW3_SHIFT              (0U)
/*! UpLftXW3 - UpperLeft_X_Window3 */
#define sig_UPPERLW3_UpLftXW3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW3_UpLftXW3_SHIFT)) & sig_UPPERLW3_UpLftXW3_MASK)

#define sig_UPPERLW3_UpLftYW3_MASK               (0x3FFF0000U)
#define sig_UPPERLW3_UpLftYW3_SHIFT              (16U)
/*! UpLftYW3 - UpperLeft_Y_Window3 */
#define sig_UPPERLW3_UpLftYW3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW3_UpLftYW3_SHIFT)) & sig_UPPERLW3_UpLftYW3_MASK)
/*! @} */

/*! @name LOWRIW3 - LowerRight_Window3 */
/*! @{ */

#define sig_LOWRIW3_LowRXW3_MASK                 (0x3FFFU)
#define sig_LOWRIW3_LowRXW3_SHIFT                (0U)
/*! LowRXW3 - LowerRight_X_Window3 */
#define sig_LOWRIW3_LowRXW3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW3_LowRXW3_SHIFT)) & sig_LOWRIW3_LowRXW3_MASK)

#define sig_LOWRIW3_LowRYW3_MASK                 (0x3FFF0000U)
#define sig_LOWRIW3_LowRYW3_SHIFT                (16U)
/*! LowRYW3 - LowerRight_Y_Window3 */
#define sig_LOWRIW3_LowRYW3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW3_LowRYW3_SHIFT)) & sig_LOWRIW3_LowRYW3_MASK)
/*! @} */

/*! @name REFRW3 - Ref_R_Window3 */
/*! @{ */

#define sig_REFRW3_RefRW3_MASK                   (0xFFFFFFFFU)
#define sig_REFRW3_RefRW3_SHIFT                  (0U)
/*! RefRW3 - Ref_R_Window3 */
#define sig_REFRW3_RefRW3(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFRW3_RefRW3_SHIFT)) & sig_REFRW3_RefRW3_MASK)
/*! @} */

/*! @name REFGW3 - Ref_G_Window3 */
/*! @{ */

#define sig_REFGW3_RefGW3_MASK                   (0xFFFFFFFFU)
#define sig_REFGW3_RefGW3_SHIFT                  (0U)
/*! RefGW3 - Ref_G_Window3 */
#define sig_REFGW3_RefGW3(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFGW3_RefGW3_SHIFT)) & sig_REFGW3_RefGW3_MASK)
/*! @} */

/*! @name REFBW3 - Ref_B_Window3 */
/*! @{ */

#define sig_REFBW3_RefBW3_MASK                   (0xFFFFFFFFU)
#define sig_REFBW3_RefBW3_SHIFT                  (0U)
/*! RefBW3 - Ref_B_Window3 */
#define sig_REFBW3_RefBW3(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFBW3_RefBW3_SHIFT)) & sig_REFBW3_RefBW3_MASK)
/*! @} */

/*! @name STATS0W3 - Stats0_Window3 */
/*! @{ */

#define sig_STATS0W3_AlpMS0W3_MASK               (0x1U)
#define sig_STATS0W3_AlpMS0W3_SHIFT              (0U)
/*! AlpMS0W3 - AlphaMask_S0_Win3 */
#define sig_STATS0W3_AlpMS0W3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W3_AlpMS0W3_SHIFT)) & sig_STATS0W3_AlpMS0W3_MASK)

#define sig_STATS0W3_AlpIS0W3_MASK               (0x2U)
#define sig_STATS0W3_AlpIS0W3_SHIFT              (1U)
/*! AlpIS0W3 - AlphaInv_S0_Win3 */
#define sig_STATS0W3_AlpIS0W3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W3_AlpIS0W3_SHIFT)) & sig_STATS0W3_AlpIS0W3_MASK)

#define sig_STATS0W3_AlpSS0W3_MASK               (0x4U)
#define sig_STATS0W3_AlpSS0W3_SHIFT              (2U)
/*! AlpSS0W3 - AlphaSel_S0_Win3 */
#define sig_STATS0W3_AlpSS0W3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS0W3_AlpSS0W3_SHIFT)) & sig_STATS0W3_AlpSS0W3_MASK)
/*! @} */

/*! @name STATS1W3 - Stats1_Window3 */
/*! @{ */

#define sig_STATS1W3_AlpMS1W3_MASK               (0x1U)
#define sig_STATS1W3_AlpMS1W3_SHIFT              (0U)
/*! AlpMS1W3 - AlphaMask_S1_Win3 */
#define sig_STATS1W3_AlpMS1W3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W3_AlpMS1W3_SHIFT)) & sig_STATS1W3_AlpMS1W3_MASK)

#define sig_STATS1W3_AlpIS1W3_MASK               (0x2U)
#define sig_STATS1W3_AlpIS1W3_SHIFT              (1U)
/*! AlpIS1W3 - AlphaInv_S1_Win3 */
#define sig_STATS1W3_AlpIS1W3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W3_AlpIS1W3_SHIFT)) & sig_STATS1W3_AlpIS1W3_MASK)

#define sig_STATS1W3_AlpSS1W3_MASK               (0x4U)
#define sig_STATS1W3_AlpSS1W3_SHIFT              (2U)
/*! AlpSS1W3 - AlphaSel_S1_Win3 */
#define sig_STATS1W3_AlpSS1W3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_STATS1W3_AlpSS1W3_SHIFT)) & sig_STATS1W3_AlpSS1W3_MASK)
/*! @} */

/*! @name MINRSUW3 - Min_RedSum_Window3 */
/*! @{ */

#define sig_MINRSUW3_MinRSuW3_MASK               (0xFFFFFFFFU)
#define sig_MINRSUW3_MinRSuW3_SHIFT              (0U)
/*! MinRSuW3 - Min_RSum_Win3 */
#define sig_MINRSUW3_MinRSuW3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINRSUW3_MinRSuW3_SHIFT)) & sig_MINRSUW3_MinRSuW3_MASK)
/*! @} */

/*! @name MINGSUW3 - Min_GreenSum_Window3 */
/*! @{ */

#define sig_MINGSUW3_MinGSuW3_MASK               (0xFFFFFFFFU)
#define sig_MINGSUW3_MinGSuW3_SHIFT              (0U)
/*! MinGSuW3 - Min_GSum_Win3 */
#define sig_MINGSUW3_MinGSuW3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINGSUW3_MinGSuW3_SHIFT)) & sig_MINGSUW3_MinGSuW3_MASK)
/*! @} */

/*! @name MINBSUW3 - Min_BlueSum_Window3 */
/*! @{ */

#define sig_MINBSUW3_MinBSuW3_MASK               (0xFFFFFFFFU)
#define sig_MINBSUW3_MinBSuW3_SHIFT              (0U)
/*! MinBSuW3 - Min_BSum_Win3 */
#define sig_MINBSUW3_MinBSuW3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINBSUW3_MinBSuW3_SHIFT)) & sig_MINBSUW3_MinBSuW3_MASK)
/*! @} */

/*! @name MINLUSW3 - Min_LumSum_Window3 */
/*! @{ */

#define sig_MINLUSW3_MinLSuW3_MASK               (0xFFFFFFFFU)
#define sig_MINLUSW3_MinLSuW3_SHIFT              (0U)
/*! MinLSuW3 - Min_LSum_Win3 */
#define sig_MINLUSW3_MinLSuW3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MINLUSW3_MinLSuW3_SHIFT)) & sig_MINLUSW3_MinLSuW3_MASK)
/*! @} */

/*! @name MAXRSUW3 - Max_RedSum_Window3 */
/*! @{ */

#define sig_MAXRSUW3_MaxRSuW3_MASK               (0xFFFFFFFFU)
#define sig_MAXRSUW3_MaxRSuW3_SHIFT              (0U)
/*! MaxRSuW3 - Max_RSum_Win3 */
#define sig_MAXRSUW3_MaxRSuW3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXRSUW3_MaxRSuW3_SHIFT)) & sig_MAXRSUW3_MaxRSuW3_MASK)
/*! @} */

/*! @name MAXGSUW3 - Max_GreenSum_Window3 */
/*! @{ */

#define sig_MAXGSUW3_MaxGSuW3_MASK               (0xFFFFFFFFU)
#define sig_MAXGSUW3_MaxGSuW3_SHIFT              (0U)
/*! MaxGSuW3 - Max_GSum_Win3 */
#define sig_MAXGSUW3_MaxGSuW3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXGSUW3_MaxGSuW3_SHIFT)) & sig_MAXGSUW3_MaxGSuW3_MASK)
/*! @} */

/*! @name MAXBSUW3 - Max_BlueSum_Window3 */
/*! @{ */

#define sig_MAXBSUW3_MaxBSuW3_MASK               (0xFFFFFFFFU)
#define sig_MAXBSUW3_MaxBSuW3_SHIFT              (0U)
/*! MaxBSuW3 - Max_BSum_Win3 */
#define sig_MAXBSUW3_MaxBSuW3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXBSUW3_MaxBSuW3_SHIFT)) & sig_MAXBSUW3_MaxBSuW3_MASK)
/*! @} */

/*! @name MAXLUSW3 - Max_LumSum_Window3 */
/*! @{ */

#define sig_MAXLUSW3_MaxLSuW3_MASK               (0xFFFFFFFFU)
#define sig_MAXLUSW3_MaxLSuW3_SHIFT              (0U)
/*! MaxLSuW3 - Max_LSum_Win3 */
#define sig_MAXLUSW3_MaxLSuW3(x)                 (((uint32_t)(((uint32_t)(x)) << sig_MAXLUSW3_MaxLSuW3_SHIFT)) & sig_MAXLUSW3_MaxLSuW3_MASK)
/*! @} */

/*! @name CONTW4 - Control_Window4 */
/*! @{ */

#define sig_CONTW4_EnWin4_MASK                   (0x1U)
#define sig_CONTW4_EnWin4_SHIFT                  (0U)
/*! EnWin4 - En_Window4 */
#define sig_CONTW4_EnWin4(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW4_EnWin4_SHIFT)) & sig_CONTW4_EnWin4_MASK)

#define sig_CONTW4_CRCW4_MASK                    (0x2U)
#define sig_CONTW4_CRCW4_SHIFT                   (1U)
/*! CRCW4 - CRC_Window4 */
#define sig_CONTW4_CRCW4(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW4_CRCW4_SHIFT)) & sig_CONTW4_CRCW4_MASK)

#define sig_CONTW4_AlpMaWi4_MASK                 (0x100U)
#define sig_CONTW4_AlpMaWi4_SHIFT                (8U)
/*! AlpMaWi4 - AlphaMask_Window4 */
#define sig_CONTW4_AlpMaWi4(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW4_AlpMaWi4_SHIFT)) & sig_CONTW4_AlpMaWi4_MASK)

#define sig_CONTW4_AlpIWin4_MASK                 (0x200U)
#define sig_CONTW4_AlpIWin4_SHIFT                (9U)
/*! AlpIWin4 - AlphaInv_Window4 */
#define sig_CONTW4_AlpIWin4(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW4_AlpIWin4_SHIFT)) & sig_CONTW4_AlpIWin4_MASK)

#define sig_CONTW4_AlpSW4_MASK                   (0x400U)
#define sig_CONTW4_AlpSW4_SHIFT                  (10U)
/*! AlpSW4 - AlphaSel_Window4 */
#define sig_CONTW4_AlpSW4(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW4_AlpSW4_SHIFT)) & sig_CONTW4_AlpSW4_MASK)

#define sig_CONTW4_LocPcW4_MASK                  (0x10000U)
#define sig_CONTW4_LocPcW4_SHIFT                 (16U)
/*! LocPcW4 - LocalPanic_Window4 */
#define sig_CONTW4_LocPcW4(x)                    (((uint32_t)(((uint32_t)(x)) << sig_CONTW4_LocPcW4_SHIFT)) & sig_CONTW4_LocPcW4_MASK)

#define sig_CONTW4_GlobPcW4_MASK                 (0x20000U)
#define sig_CONTW4_GlobPcW4_SHIFT                (17U)
/*! GlobPcW4 - GlobalPanic_Window4 */
#define sig_CONTW4_GlobPcW4(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW4_GlobPcW4_SHIFT)) & sig_CONTW4_GlobPcW4_MASK)
/*! @} */

/*! @name UPPERLW4 - UpperLeft_Window4 */
/*! @{ */

#define sig_UPPERLW4_UpLftXW4_MASK               (0x3FFFU)
#define sig_UPPERLW4_UpLftXW4_SHIFT              (0U)
/*! UpLftXW4 - UpperLeft_X_Window4 */
#define sig_UPPERLW4_UpLftXW4(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW4_UpLftXW4_SHIFT)) & sig_UPPERLW4_UpLftXW4_MASK)

#define sig_UPPERLW4_UpLftYW4_MASK               (0x3FFF0000U)
#define sig_UPPERLW4_UpLftYW4_SHIFT              (16U)
/*! UpLftYW4 - UpperLeft_Y_Window4 */
#define sig_UPPERLW4_UpLftYW4(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW4_UpLftYW4_SHIFT)) & sig_UPPERLW4_UpLftYW4_MASK)
/*! @} */

/*! @name LOWRIW4 - LowerRight_Window4 */
/*! @{ */

#define sig_LOWRIW4_LowRXW4_MASK                 (0x3FFFU)
#define sig_LOWRIW4_LowRXW4_SHIFT                (0U)
/*! LowRXW4 - LowerRight_X_Window4 */
#define sig_LOWRIW4_LowRXW4(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW4_LowRXW4_SHIFT)) & sig_LOWRIW4_LowRXW4_MASK)

#define sig_LOWRIW4_LowRYW4_MASK                 (0x3FFF0000U)
#define sig_LOWRIW4_LowRYW4_SHIFT                (16U)
/*! LowRYW4 - LowerRight_Y_Window4 */
#define sig_LOWRIW4_LowRYW4(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW4_LowRYW4_SHIFT)) & sig_LOWRIW4_LowRYW4_MASK)
/*! @} */

/*! @name REFRW4 - Ref_R_Window4 */
/*! @{ */

#define sig_REFRW4_RefRW4_MASK                   (0xFFFFFFFFU)
#define sig_REFRW4_RefRW4_SHIFT                  (0U)
/*! RefRW4 - Ref_R_Window4 */
#define sig_REFRW4_RefRW4(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFRW4_RefRW4_SHIFT)) & sig_REFRW4_RefRW4_MASK)
/*! @} */

/*! @name REFGW4 - Ref_G_Window4 */
/*! @{ */

#define sig_REFGW4_RefGW4_MASK                   (0xFFFFFFFFU)
#define sig_REFGW4_RefGW4_SHIFT                  (0U)
/*! RefGW4 - Ref_G_Window4 */
#define sig_REFGW4_RefGW4(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFGW4_RefGW4_SHIFT)) & sig_REFGW4_RefGW4_MASK)
/*! @} */

/*! @name REFBW4 - Ref_B_Window4 */
/*! @{ */

#define sig_REFBW4_RefBW4_MASK                   (0xFFFFFFFFU)
#define sig_REFBW4_RefBW4_SHIFT                  (0U)
/*! RefBW4 - Ref_B_Window4 */
#define sig_REFBW4_RefBW4(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFBW4_RefBW4_SHIFT)) & sig_REFBW4_RefBW4_MASK)
/*! @} */

/*! @name CONTW5 - Control_Window5 */
/*! @{ */

#define sig_CONTW5_EnWin5_MASK                   (0x1U)
#define sig_CONTW5_EnWin5_SHIFT                  (0U)
/*! EnWin5 - En_Window5 */
#define sig_CONTW5_EnWin5(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW5_EnWin5_SHIFT)) & sig_CONTW5_EnWin5_MASK)

#define sig_CONTW5_CRCW5_MASK                    (0x2U)
#define sig_CONTW5_CRCW5_SHIFT                   (1U)
/*! CRCW5 - CRC_Window5 */
#define sig_CONTW5_CRCW5(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW5_CRCW5_SHIFT)) & sig_CONTW5_CRCW5_MASK)

#define sig_CONTW5_AlpMaWi5_MASK                 (0x100U)
#define sig_CONTW5_AlpMaWi5_SHIFT                (8U)
/*! AlpMaWi5 - AlphaMask_Window5 */
#define sig_CONTW5_AlpMaWi5(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW5_AlpMaWi5_SHIFT)) & sig_CONTW5_AlpMaWi5_MASK)

#define sig_CONTW5_AlpIWin5_MASK                 (0x200U)
#define sig_CONTW5_AlpIWin5_SHIFT                (9U)
/*! AlpIWin5 - AlphaInv_Window5 */
#define sig_CONTW5_AlpIWin5(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW5_AlpIWin5_SHIFT)) & sig_CONTW5_AlpIWin5_MASK)

#define sig_CONTW5_AlpSW5_MASK                   (0x400U)
#define sig_CONTW5_AlpSW5_SHIFT                  (10U)
/*! AlpSW5 - AlphaSel_Window5 */
#define sig_CONTW5_AlpSW5(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW5_AlpSW5_SHIFT)) & sig_CONTW5_AlpSW5_MASK)

#define sig_CONTW5_LocPcW5_MASK                  (0x10000U)
#define sig_CONTW5_LocPcW5_SHIFT                 (16U)
/*! LocPcW5 - LocalPanic_Window5 */
#define sig_CONTW5_LocPcW5(x)                    (((uint32_t)(((uint32_t)(x)) << sig_CONTW5_LocPcW5_SHIFT)) & sig_CONTW5_LocPcW5_MASK)

#define sig_CONTW5_GlobPcW5_MASK                 (0x20000U)
#define sig_CONTW5_GlobPcW5_SHIFT                (17U)
/*! GlobPcW5 - GlobalPanic_Window5 */
#define sig_CONTW5_GlobPcW5(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW5_GlobPcW5_SHIFT)) & sig_CONTW5_GlobPcW5_MASK)
/*! @} */

/*! @name UPPERLW5 - UpperLeft_Window5 */
/*! @{ */

#define sig_UPPERLW5_UpLftXW5_MASK               (0x3FFFU)
#define sig_UPPERLW5_UpLftXW5_SHIFT              (0U)
/*! UpLftXW5 - UpperLeft_X_Window5 */
#define sig_UPPERLW5_UpLftXW5(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW5_UpLftXW5_SHIFT)) & sig_UPPERLW5_UpLftXW5_MASK)

#define sig_UPPERLW5_UpLftYW5_MASK               (0x3FFF0000U)
#define sig_UPPERLW5_UpLftYW5_SHIFT              (16U)
/*! UpLftYW5 - UpperLeft_Y_Window5 */
#define sig_UPPERLW5_UpLftYW5(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW5_UpLftYW5_SHIFT)) & sig_UPPERLW5_UpLftYW5_MASK)
/*! @} */

/*! @name LOWRIW5 - LowerRight_Window5 */
/*! @{ */

#define sig_LOWRIW5_LowRXW5_MASK                 (0x3FFFU)
#define sig_LOWRIW5_LowRXW5_SHIFT                (0U)
/*! LowRXW5 - LowerRight_X_Window5 */
#define sig_LOWRIW5_LowRXW5(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW5_LowRXW5_SHIFT)) & sig_LOWRIW5_LowRXW5_MASK)

#define sig_LOWRIW5_LowRYW5_MASK                 (0x3FFF0000U)
#define sig_LOWRIW5_LowRYW5_SHIFT                (16U)
/*! LowRYW5 - LowerRight_Y_Window5 */
#define sig_LOWRIW5_LowRYW5(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW5_LowRYW5_SHIFT)) & sig_LOWRIW5_LowRYW5_MASK)
/*! @} */

/*! @name REFRW5 - Ref_R_Window5 */
/*! @{ */

#define sig_REFRW5_RefRW5_MASK                   (0xFFFFFFFFU)
#define sig_REFRW5_RefRW5_SHIFT                  (0U)
/*! RefRW5 - Ref_R_Window5 */
#define sig_REFRW5_RefRW5(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFRW5_RefRW5_SHIFT)) & sig_REFRW5_RefRW5_MASK)
/*! @} */

/*! @name REFGW5 - Ref_G_Window5 */
/*! @{ */

#define sig_REFGW5_RefGW5_MASK                   (0xFFFFFFFFU)
#define sig_REFGW5_RefGW5_SHIFT                  (0U)
/*! RefGW5 - Ref_G_Window5 */
#define sig_REFGW5_RefGW5(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFGW5_RefGW5_SHIFT)) & sig_REFGW5_RefGW5_MASK)
/*! @} */

/*! @name REFBW5 - Ref_B_Window5 */
/*! @{ */

#define sig_REFBW5_RefBW5_MASK                   (0xFFFFFFFFU)
#define sig_REFBW5_RefBW5_SHIFT                  (0U)
/*! RefBW5 - Ref_B_Window5 */
#define sig_REFBW5_RefBW5(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFBW5_RefBW5_SHIFT)) & sig_REFBW5_RefBW5_MASK)
/*! @} */

/*! @name CONTW6 - Control_Window6 */
/*! @{ */

#define sig_CONTW6_EnWin6_MASK                   (0x1U)
#define sig_CONTW6_EnWin6_SHIFT                  (0U)
/*! EnWin6 - En_Window6 */
#define sig_CONTW6_EnWin6(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW6_EnWin6_SHIFT)) & sig_CONTW6_EnWin6_MASK)

#define sig_CONTW6_CRCW6_MASK                    (0x2U)
#define sig_CONTW6_CRCW6_SHIFT                   (1U)
/*! CRCW6 - CRC_Window6 */
#define sig_CONTW6_CRCW6(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW6_CRCW6_SHIFT)) & sig_CONTW6_CRCW6_MASK)

#define sig_CONTW6_AlpMaWi6_MASK                 (0x100U)
#define sig_CONTW6_AlpMaWi6_SHIFT                (8U)
/*! AlpMaWi6 - AlphaMask_Window6 */
#define sig_CONTW6_AlpMaWi6(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW6_AlpMaWi6_SHIFT)) & sig_CONTW6_AlpMaWi6_MASK)

#define sig_CONTW6_AlpIWin6_MASK                 (0x200U)
#define sig_CONTW6_AlpIWin6_SHIFT                (9U)
/*! AlpIWin6 - AlphaInv_Window6 */
#define sig_CONTW6_AlpIWin6(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW6_AlpIWin6_SHIFT)) & sig_CONTW6_AlpIWin6_MASK)

#define sig_CONTW6_AlpSW6_MASK                   (0x400U)
#define sig_CONTW6_AlpSW6_SHIFT                  (10U)
/*! AlpSW6 - AlphaSel_Window6 */
#define sig_CONTW6_AlpSW6(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW6_AlpSW6_SHIFT)) & sig_CONTW6_AlpSW6_MASK)

#define sig_CONTW6_LocPcW6_MASK                  (0x10000U)
#define sig_CONTW6_LocPcW6_SHIFT                 (16U)
/*! LocPcW6 - LocalPanic_Window6 */
#define sig_CONTW6_LocPcW6(x)                    (((uint32_t)(((uint32_t)(x)) << sig_CONTW6_LocPcW6_SHIFT)) & sig_CONTW6_LocPcW6_MASK)

#define sig_CONTW6_GlobPcW6_MASK                 (0x20000U)
#define sig_CONTW6_GlobPcW6_SHIFT                (17U)
/*! GlobPcW6 - GlobalPanic_Window6 */
#define sig_CONTW6_GlobPcW6(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW6_GlobPcW6_SHIFT)) & sig_CONTW6_GlobPcW6_MASK)
/*! @} */

/*! @name UPPERLW6 - UpperLeft_Window6 */
/*! @{ */

#define sig_UPPERLW6_UpLftXW6_MASK               (0x3FFFU)
#define sig_UPPERLW6_UpLftXW6_SHIFT              (0U)
/*! UpLftXW6 - UpperLeft_X_Window6 */
#define sig_UPPERLW6_UpLftXW6(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW6_UpLftXW6_SHIFT)) & sig_UPPERLW6_UpLftXW6_MASK)

#define sig_UPPERLW6_UpLftYW6_MASK               (0x3FFF0000U)
#define sig_UPPERLW6_UpLftYW6_SHIFT              (16U)
/*! UpLftYW6 - UpperLeft_Y_Window6 */
#define sig_UPPERLW6_UpLftYW6(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW6_UpLftYW6_SHIFT)) & sig_UPPERLW6_UpLftYW6_MASK)
/*! @} */

/*! @name LOWRIW6 - LowerRight_Window6 */
/*! @{ */

#define sig_LOWRIW6_LowRXW6_MASK                 (0x3FFFU)
#define sig_LOWRIW6_LowRXW6_SHIFT                (0U)
/*! LowRXW6 - LowerRight_X_Window6 */
#define sig_LOWRIW6_LowRXW6(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW6_LowRXW6_SHIFT)) & sig_LOWRIW6_LowRXW6_MASK)

#define sig_LOWRIW6_LowRYW6_MASK                 (0x3FFF0000U)
#define sig_LOWRIW6_LowRYW6_SHIFT                (16U)
/*! LowRYW6 - LowerRight_Y_Window6 */
#define sig_LOWRIW6_LowRYW6(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW6_LowRYW6_SHIFT)) & sig_LOWRIW6_LowRYW6_MASK)
/*! @} */

/*! @name REFRW6 - Ref_R_Window6 */
/*! @{ */

#define sig_REFRW6_RefRW6_MASK                   (0xFFFFFFFFU)
#define sig_REFRW6_RefRW6_SHIFT                  (0U)
/*! RefRW6 - Ref_R_Window6 */
#define sig_REFRW6_RefRW6(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFRW6_RefRW6_SHIFT)) & sig_REFRW6_RefRW6_MASK)
/*! @} */

/*! @name REFGW6 - Ref_G_Window6 */
/*! @{ */

#define sig_REFGW6_RefGW6_MASK                   (0xFFFFFFFFU)
#define sig_REFGW6_RefGW6_SHIFT                  (0U)
/*! RefGW6 - Ref_G_Window6 */
#define sig_REFGW6_RefGW6(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFGW6_RefGW6_SHIFT)) & sig_REFGW6_RefGW6_MASK)
/*! @} */

/*! @name REFBW6 - Ref_B_Window6 */
/*! @{ */

#define sig_REFBW6_RefBW6_MASK                   (0xFFFFFFFFU)
#define sig_REFBW6_RefBW6_SHIFT                  (0U)
/*! RefBW6 - Ref_B_Window6 */
#define sig_REFBW6_RefBW6(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFBW6_RefBW6_SHIFT)) & sig_REFBW6_RefBW6_MASK)
/*! @} */

/*! @name CONTW7 - Control_Window7 */
/*! @{ */

#define sig_CONTW7_EnWin7_MASK                   (0x1U)
#define sig_CONTW7_EnWin7_SHIFT                  (0U)
/*! EnWin7 - En_Window7 */
#define sig_CONTW7_EnWin7(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW7_EnWin7_SHIFT)) & sig_CONTW7_EnWin7_MASK)

#define sig_CONTW7_CRCW7_MASK                    (0x2U)
#define sig_CONTW7_CRCW7_SHIFT                   (1U)
/*! CRCW7 - CRC_Window7 */
#define sig_CONTW7_CRCW7(x)                      (((uint32_t)(((uint32_t)(x)) << sig_CONTW7_CRCW7_SHIFT)) & sig_CONTW7_CRCW7_MASK)

#define sig_CONTW7_AlpMaWi7_MASK                 (0x100U)
#define sig_CONTW7_AlpMaWi7_SHIFT                (8U)
/*! AlpMaWi7 - AlphaMask_Window7 */
#define sig_CONTW7_AlpMaWi7(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW7_AlpMaWi7_SHIFT)) & sig_CONTW7_AlpMaWi7_MASK)

#define sig_CONTW7_AlpIWin7_MASK                 (0x200U)
#define sig_CONTW7_AlpIWin7_SHIFT                (9U)
/*! AlpIWin7 - AlphaInv_Window7 */
#define sig_CONTW7_AlpIWin7(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW7_AlpIWin7_SHIFT)) & sig_CONTW7_AlpIWin7_MASK)

#define sig_CONTW7_AlpSW7_MASK                   (0x400U)
#define sig_CONTW7_AlpSW7_SHIFT                  (10U)
/*! AlpSW7 - AlphaSel_Window7 */
#define sig_CONTW7_AlpSW7(x)                     (((uint32_t)(((uint32_t)(x)) << sig_CONTW7_AlpSW7_SHIFT)) & sig_CONTW7_AlpSW7_MASK)

#define sig_CONTW7_LocPcW7_MASK                  (0x10000U)
#define sig_CONTW7_LocPcW7_SHIFT                 (16U)
/*! LocPcW7 - LocalPanic_Window7 */
#define sig_CONTW7_LocPcW7(x)                    (((uint32_t)(((uint32_t)(x)) << sig_CONTW7_LocPcW7_SHIFT)) & sig_CONTW7_LocPcW7_MASK)

#define sig_CONTW7_GlobPcW7_MASK                 (0x20000U)
#define sig_CONTW7_GlobPcW7_SHIFT                (17U)
/*! GlobPcW7 - GlobalPanic_Window7 */
#define sig_CONTW7_GlobPcW7(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTW7_GlobPcW7_SHIFT)) & sig_CONTW7_GlobPcW7_MASK)
/*! @} */

/*! @name UPPERLW7 - UpperLeft_Window7 */
/*! @{ */

#define sig_UPPERLW7_UpLftXW7_MASK               (0x3FFFU)
#define sig_UPPERLW7_UpLftXW7_SHIFT              (0U)
/*! UpLftXW7 - UpperLeft_X_Window7 */
#define sig_UPPERLW7_UpLftXW7(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW7_UpLftXW7_SHIFT)) & sig_UPPERLW7_UpLftXW7_MASK)

#define sig_UPPERLW7_UpLftYW7_MASK               (0x3FFF0000U)
#define sig_UPPERLW7_UpLftYW7_SHIFT              (16U)
/*! UpLftYW7 - UpperLeft_Y_Window7 */
#define sig_UPPERLW7_UpLftYW7(x)                 (((uint32_t)(((uint32_t)(x)) << sig_UPPERLW7_UpLftYW7_SHIFT)) & sig_UPPERLW7_UpLftYW7_MASK)
/*! @} */

/*! @name LOWRIW7 - LowerRight_Window7 */
/*! @{ */

#define sig_LOWRIW7_LowRXW7_MASK                 (0x3FFFU)
#define sig_LOWRIW7_LowRXW7_SHIFT                (0U)
/*! LowRXW7 - LowerRight_X_Window7 */
#define sig_LOWRIW7_LowRXW7(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW7_LowRXW7_SHIFT)) & sig_LOWRIW7_LowRXW7_MASK)

#define sig_LOWRIW7_LowRYW7_MASK                 (0x3FFF0000U)
#define sig_LOWRIW7_LowRYW7_SHIFT                (16U)
/*! LowRYW7 - LowerRight_Y_Window7 */
#define sig_LOWRIW7_LowRYW7(x)                   (((uint32_t)(((uint32_t)(x)) << sig_LOWRIW7_LowRYW7_SHIFT)) & sig_LOWRIW7_LowRYW7_MASK)
/*! @} */

/*! @name REFRW7 - Ref_R_Window7 */
/*! @{ */

#define sig_REFRW7_RefRW7_MASK                   (0xFFFFFFFFU)
#define sig_REFRW7_RefRW7_SHIFT                  (0U)
/*! RefRW7 - Ref_R_Window7 */
#define sig_REFRW7_RefRW7(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFRW7_RefRW7_SHIFT)) & sig_REFRW7_RefRW7_MASK)
/*! @} */

/*! @name REFGW7 - Ref_G_Window7 */
/*! @{ */

#define sig_REFGW7_RefGW7_MASK                   (0xFFFFFFFFU)
#define sig_REFGW7_RefGW7_SHIFT                  (0U)
/*! RefGW7 - Ref_G_Window7 */
#define sig_REFGW7_RefGW7(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFGW7_RefGW7_SHIFT)) & sig_REFGW7_RefGW7_MASK)
/*! @} */

/*! @name REFBW7 - Ref_B_Window7 */
/*! @{ */

#define sig_REFBW7_RefBW7_MASK                   (0xFFFFFFFFU)
#define sig_REFBW7_RefBW7_SHIFT                  (0U)
/*! RefBW7 - Ref_B_Window7 */
#define sig_REFBW7_RefBW7(x)                     (((uint32_t)(((uint32_t)(x)) << sig_REFBW7_RefBW7_SHIFT)) & sig_REFBW7_RefBW7_MASK)
/*! @} */

/*! @name CONTRC0 - Control_Cluster0 */
/*! @{ */

#define sig_CONTRC0_EnClust0_MASK                (0x1U)
#define sig_CONTRC0_EnClust0_SHIFT               (0U)
/*! EnClust0 - En_Cluster0
 *  0b0..Cluster is disabled and all Status flags are cleared
 *  0b1..Cluster is enabled and reference checking is executed
 */
#define sig_CONTRC0_EnClust0(x)                  (((uint32_t)(((uint32_t)(x)) << sig_CONTRC0_EnClust0_SHIFT)) & sig_CONTRC0_EnClust0_MASK)

#define sig_CONTRC0_Px0EnC0_MASK                 (0x10U)
#define sig_CONTRC0_Px0EnC0_SHIFT                (4U)
/*! Px0EnC0 - Pix0_En_Cluster0
 *  0b0..Pixel 0 will not be evaluated
 *  0b1..Pixel 0 will be evaluated
 */
#define sig_CONTRC0_Px0EnC0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC0_Px0EnC0_SHIFT)) & sig_CONTRC0_Px0EnC0_MASK)

#define sig_CONTRC0_Px1EnC0_MASK                 (0x20U)
#define sig_CONTRC0_Px1EnC0_SHIFT                (5U)
/*! Px1EnC0 - Pix1_En_Cluster0
 *  0b0..Pixel 1 will not be evaluated
 *  0b1..Pixel 1 will be evaluated
 */
#define sig_CONTRC0_Px1EnC0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC0_Px1EnC0_SHIFT)) & sig_CONTRC0_Px1EnC0_MASK)

#define sig_CONTRC0_Px2EnC0_MASK                 (0x40U)
#define sig_CONTRC0_Px2EnC0_SHIFT                (6U)
/*! Px2EnC0 - Pix2_En_Cluster0
 *  0b0..Pixel 2 will not be evaluated
 *  0b1..Pixel 2 will be evaluated
 */
#define sig_CONTRC0_Px2EnC0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC0_Px2EnC0_SHIFT)) & sig_CONTRC0_Px2EnC0_MASK)

#define sig_CONTRC0_Px3EnC0_MASK                 (0x80U)
#define sig_CONTRC0_Px3EnC0_SHIFT                (7U)
/*! Px3EnC0 - Pix3_En_Cluster0
 *  0b0..Pixel 3 will not be evaluated
 *  0b1..Pixel 3 will be evaluated
 */
#define sig_CONTRC0_Px3EnC0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC0_Px3EnC0_SHIFT)) & sig_CONTRC0_Px3EnC0_MASK)

#define sig_CONTRC0_MakBlC0_MASK                 (0xFF00U)
#define sig_CONTRC0_MakBlC0_SHIFT                (8U)
/*! MakBlC0 - MaskBlue_Cluster0 */
#define sig_CONTRC0_MakBlC0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC0_MakBlC0_SHIFT)) & sig_CONTRC0_MakBlC0_MASK)

#define sig_CONTRC0_MakGrC0_MASK                 (0xFF0000U)
#define sig_CONTRC0_MakGrC0_SHIFT                (16U)
/*! MakGrC0 - MaskGreen_Cluster0 */
#define sig_CONTRC0_MakGrC0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC0_MakGrC0_SHIFT)) & sig_CONTRC0_MakGrC0_MASK)

#define sig_CONTRC0_MakRedC0_MASK                (0xFF000000U)
#define sig_CONTRC0_MakRedC0_SHIFT               (24U)
/*! MakRedC0 - MaskRed_Cluster0 */
#define sig_CONTRC0_MakRedC0(x)                  (((uint32_t)(((uint32_t)(x)) << sig_CONTRC0_MakRedC0_SHIFT)) & sig_CONTRC0_MakRedC0_MASK)
/*! @} */

/*! @name PIX0C0 - Pix0_Cluster0 */
/*! @{ */

#define sig_PIX0C0_X0Clust0_MASK                 (0x3FFFU)
#define sig_PIX0C0_X0Clust0_SHIFT                (0U)
/*! X0Clust0 - X0_Cluster0 */
#define sig_PIX0C0_X0Clust0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX0C0_X0Clust0_SHIFT)) & sig_PIX0C0_X0Clust0_MASK)

#define sig_PIX0C0_Y0Clust0_MASK                 (0x3FFF0000U)
#define sig_PIX0C0_Y0Clust0_SHIFT                (16U)
/*! Y0Clust0 - Y0_Cluster0 */
#define sig_PIX0C0_Y0Clust0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX0C0_Y0Clust0_SHIFT)) & sig_PIX0C0_Y0Clust0_MASK)
/*! @} */

/*! @name PIX1C0 - Pix1_Cluster0 */
/*! @{ */

#define sig_PIX1C0_X1Clust0_MASK                 (0x3FFFU)
#define sig_PIX1C0_X1Clust0_SHIFT                (0U)
/*! X1Clust0 - X1_Cluster0 */
#define sig_PIX1C0_X1Clust0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX1C0_X1Clust0_SHIFT)) & sig_PIX1C0_X1Clust0_MASK)

#define sig_PIX1C0_Y1Clust0_MASK                 (0x3FFF0000U)
#define sig_PIX1C0_Y1Clust0_SHIFT                (16U)
/*! Y1Clust0 - Y1_Cluster0 */
#define sig_PIX1C0_Y1Clust0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX1C0_Y1Clust0_SHIFT)) & sig_PIX1C0_Y1Clust0_MASK)
/*! @} */

/*! @name PIX2C0 - Pix2_Cluster0 */
/*! @{ */

#define sig_PIX2C0_X2Clust0_MASK                 (0x3FFFU)
#define sig_PIX2C0_X2Clust0_SHIFT                (0U)
/*! X2Clust0 - X2_Cluster0 */
#define sig_PIX2C0_X2Clust0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX2C0_X2Clust0_SHIFT)) & sig_PIX2C0_X2Clust0_MASK)

#define sig_PIX2C0_Y2Clust0_MASK                 (0x3FFF0000U)
#define sig_PIX2C0_Y2Clust0_SHIFT                (16U)
/*! Y2Clust0 - Y2_Cluster0 */
#define sig_PIX2C0_Y2Clust0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX2C0_Y2Clust0_SHIFT)) & sig_PIX2C0_Y2Clust0_MASK)
/*! @} */

/*! @name PIX3C0 - Pix3_Cluster0 */
/*! @{ */

#define sig_PIX3C0_X3Clust0_MASK                 (0x3FFFU)
#define sig_PIX3C0_X3Clust0_SHIFT                (0U)
/*! X3Clust0 - X3_Cluster0 */
#define sig_PIX3C0_X3Clust0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX3C0_X3Clust0_SHIFT)) & sig_PIX3C0_X3Clust0_MASK)

#define sig_PIX3C0_Y3Clust0_MASK                 (0x3FFF0000U)
#define sig_PIX3C0_Y3Clust0_SHIFT                (16U)
/*! Y3Clust0 - Y3_Cluster0 */
#define sig_PIX3C0_Y3Clust0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX3C0_Y3Clust0_SHIFT)) & sig_PIX3C0_Y3Clust0_MASK)
/*! @} */

/*! @name REF0CLU0 - Ref0_Cluster0 */
/*! @{ */

#define sig_REF0CLU0_Ref0C0_MASK                 (0xFFFFFFU)
#define sig_REF0CLU0_Ref0C0_SHIFT                (0U)
/*! Ref0C0 - Ref0_Cluster0 */
#define sig_REF0CLU0_Ref0C0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_REF0CLU0_Ref0C0_SHIFT)) & sig_REF0CLU0_Ref0C0_MASK)
/*! @} */

/*! @name REF1CLU0 - Ref1_Cluster0 */
/*! @{ */

#define sig_REF1CLU0_Ref1C0_MASK                 (0xFFFFFFU)
#define sig_REF1CLU0_Ref1C0_SHIFT                (0U)
/*! Ref1C0 - Ref1_Cluster0 */
#define sig_REF1CLU0_Ref1C0(x)                   (((uint32_t)(((uint32_t)(x)) << sig_REF1CLU0_Ref1C0_SHIFT)) & sig_REF1CLU0_Ref1C0_MASK)
/*! @} */

/*! @name CONTRC1 - Control_Cluster1 */
/*! @{ */

#define sig_CONTRC1_EnClust1_MASK                (0x1U)
#define sig_CONTRC1_EnClust1_SHIFT               (0U)
/*! EnClust1 - En_Cluster1
 *  0b0..Cluster is disabled and all Status flags are cleared
 *  0b1..Cluster is enabled and reference checking is executed
 */
#define sig_CONTRC1_EnClust1(x)                  (((uint32_t)(((uint32_t)(x)) << sig_CONTRC1_EnClust1_SHIFT)) & sig_CONTRC1_EnClust1_MASK)

#define sig_CONTRC1_Px0EnC1_MASK                 (0x10U)
#define sig_CONTRC1_Px0EnC1_SHIFT                (4U)
/*! Px0EnC1 - Pix0_En_Cluster1
 *  0b0..Pixel 0 will not be evaluated
 *  0b1..Pixel 0 will be evaluated
 */
#define sig_CONTRC1_Px0EnC1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC1_Px0EnC1_SHIFT)) & sig_CONTRC1_Px0EnC1_MASK)

#define sig_CONTRC1_Px1EnC1_MASK                 (0x20U)
#define sig_CONTRC1_Px1EnC1_SHIFT                (5U)
/*! Px1EnC1 - Pix1_En_Cluster1
 *  0b0..Pixel 1 will not be evaluated
 *  0b1..Pixel 1 will be evaluated
 */
#define sig_CONTRC1_Px1EnC1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC1_Px1EnC1_SHIFT)) & sig_CONTRC1_Px1EnC1_MASK)

#define sig_CONTRC1_Px2EnC1_MASK                 (0x40U)
#define sig_CONTRC1_Px2EnC1_SHIFT                (6U)
/*! Px2EnC1 - Pix2_En_Cluster1
 *  0b0..Pixel 2 will not be evaluated
 *  0b1..Pixel 2 will be evaluated
 */
#define sig_CONTRC1_Px2EnC1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC1_Px2EnC1_SHIFT)) & sig_CONTRC1_Px2EnC1_MASK)

#define sig_CONTRC1_Px3EnC1_MASK                 (0x80U)
#define sig_CONTRC1_Px3EnC1_SHIFT                (7U)
/*! Px3EnC1 - Pix3_En_Cluster1
 *  0b0..Pixel 3 will not be evaluated
 *  0b1..Pixel 3 will be evaluated
 */
#define sig_CONTRC1_Px3EnC1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC1_Px3EnC1_SHIFT)) & sig_CONTRC1_Px3EnC1_MASK)

#define sig_CONTRC1_MakBlCl_MASK                 (0xFF00U)
#define sig_CONTRC1_MakBlCl_SHIFT                (8U)
/*! MakBlCl - MaskBlue_Cluster1 */
#define sig_CONTRC1_MakBlCl(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC1_MakBlCl_SHIFT)) & sig_CONTRC1_MakBlCl_MASK)

#define sig_CONTRC1_MakGrC1_MASK                 (0xFF0000U)
#define sig_CONTRC1_MakGrC1_SHIFT                (16U)
/*! MakGrC1 - MaskGreen_Cluster1 */
#define sig_CONTRC1_MakGrC1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC1_MakGrC1_SHIFT)) & sig_CONTRC1_MakGrC1_MASK)

#define sig_CONTRC1_MakRedC1_MASK                (0xFF000000U)
#define sig_CONTRC1_MakRedC1_SHIFT               (24U)
/*! MakRedC1 - MaskRed_Cluster1 */
#define sig_CONTRC1_MakRedC1(x)                  (((uint32_t)(((uint32_t)(x)) << sig_CONTRC1_MakRedC1_SHIFT)) & sig_CONTRC1_MakRedC1_MASK)
/*! @} */

/*! @name PIX0C1 - Pix0_Cluster1 */
/*! @{ */

#define sig_PIX0C1_X0Clust1_MASK                 (0x3FFFU)
#define sig_PIX0C1_X0Clust1_SHIFT                (0U)
/*! X0Clust1 - X0_Cluster1 */
#define sig_PIX0C1_X0Clust1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX0C1_X0Clust1_SHIFT)) & sig_PIX0C1_X0Clust1_MASK)

#define sig_PIX0C1_Y0Clust1_MASK                 (0x3FFF0000U)
#define sig_PIX0C1_Y0Clust1_SHIFT                (16U)
/*! Y0Clust1 - Y0_Cluster1 */
#define sig_PIX0C1_Y0Clust1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX0C1_Y0Clust1_SHIFT)) & sig_PIX0C1_Y0Clust1_MASK)
/*! @} */

/*! @name PIX1C1 - Pix1_Cluster1 */
/*! @{ */

#define sig_PIX1C1_X1Clust1_MASK                 (0x3FFFU)
#define sig_PIX1C1_X1Clust1_SHIFT                (0U)
/*! X1Clust1 - X1_Cluster1 */
#define sig_PIX1C1_X1Clust1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX1C1_X1Clust1_SHIFT)) & sig_PIX1C1_X1Clust1_MASK)

#define sig_PIX1C1_Y1Clust1_MASK                 (0x3FFF0000U)
#define sig_PIX1C1_Y1Clust1_SHIFT                (16U)
/*! Y1Clust1 - Y1_Cluster1 */
#define sig_PIX1C1_Y1Clust1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX1C1_Y1Clust1_SHIFT)) & sig_PIX1C1_Y1Clust1_MASK)
/*! @} */

/*! @name PIX2C1 - Pix2_Cluster1 */
/*! @{ */

#define sig_PIX2C1_X2Clust1_MASK                 (0x3FFFU)
#define sig_PIX2C1_X2Clust1_SHIFT                (0U)
/*! X2Clust1 - X2_Cluster1 */
#define sig_PIX2C1_X2Clust1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX2C1_X2Clust1_SHIFT)) & sig_PIX2C1_X2Clust1_MASK)

#define sig_PIX2C1_Y2Clust1_MASK                 (0x3FFF0000U)
#define sig_PIX2C1_Y2Clust1_SHIFT                (16U)
/*! Y2Clust1 - Y2_Cluster1 */
#define sig_PIX2C1_Y2Clust1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX2C1_Y2Clust1_SHIFT)) & sig_PIX2C1_Y2Clust1_MASK)
/*! @} */

/*! @name PIX3C1 - Pix3_Cluster1 */
/*! @{ */

#define sig_PIX3C1_X3Clust1_MASK                 (0x3FFFU)
#define sig_PIX3C1_X3Clust1_SHIFT                (0U)
/*! X3Clust1 - X3_Cluster1 */
#define sig_PIX3C1_X3Clust1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX3C1_X3Clust1_SHIFT)) & sig_PIX3C1_X3Clust1_MASK)

#define sig_PIX3C1_Y3Clust1_MASK                 (0x3FFF0000U)
#define sig_PIX3C1_Y3Clust1_SHIFT                (16U)
/*! Y3Clust1 - Y3_Cluster1 */
#define sig_PIX3C1_Y3Clust1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX3C1_Y3Clust1_SHIFT)) & sig_PIX3C1_Y3Clust1_MASK)
/*! @} */

/*! @name REF0CLU1 - Ref0_Cluster1 */
/*! @{ */

#define sig_REF0CLU1_Ref0C1_MASK                 (0xFFFFFFU)
#define sig_REF0CLU1_Ref0C1_SHIFT                (0U)
/*! Ref0C1 - Ref0_Cluster1 */
#define sig_REF0CLU1_Ref0C1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_REF0CLU1_Ref0C1_SHIFT)) & sig_REF0CLU1_Ref0C1_MASK)
/*! @} */

/*! @name REF1CLU1 - Ref1_Cluster1 */
/*! @{ */

#define sig_REF1CLU1_Ref1C1_MASK                 (0xFFFFFFU)
#define sig_REF1CLU1_Ref1C1_SHIFT                (0U)
/*! Ref1C1 - Ref1_Cluster1 */
#define sig_REF1CLU1_Ref1C1(x)                   (((uint32_t)(((uint32_t)(x)) << sig_REF1CLU1_Ref1C1_SHIFT)) & sig_REF1CLU1_Ref1C1_MASK)
/*! @} */

/*! @name CONTRC2 - Control_Cluster2 */
/*! @{ */

#define sig_CONTRC2_EnClust2_MASK                (0x1U)
#define sig_CONTRC2_EnClust2_SHIFT               (0U)
/*! EnClust2 - En_Cluster2
 *  0b0..Cluster is disabled and all Status flags are cleared
 *  0b1..Cluster is enabled and reference checking is executed
 */
#define sig_CONTRC2_EnClust2(x)                  (((uint32_t)(((uint32_t)(x)) << sig_CONTRC2_EnClust2_SHIFT)) & sig_CONTRC2_EnClust2_MASK)

#define sig_CONTRC2_Px0EnC2_MASK                 (0x10U)
#define sig_CONTRC2_Px0EnC2_SHIFT                (4U)
/*! Px0EnC2 - Pix0_En_Cluster2
 *  0b0..Pixel 0 will not be evaluated
 *  0b1..Pixel 0 will be evaluated
 */
#define sig_CONTRC2_Px0EnC2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC2_Px0EnC2_SHIFT)) & sig_CONTRC2_Px0EnC2_MASK)

#define sig_CONTRC2_Px1EnC2_MASK                 (0x20U)
#define sig_CONTRC2_Px1EnC2_SHIFT                (5U)
/*! Px1EnC2 - Pix1_En_Cluster2
 *  0b0..Pixel 1 will not be evaluated
 *  0b1..Pixel 1 will be evaluated
 */
#define sig_CONTRC2_Px1EnC2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC2_Px1EnC2_SHIFT)) & sig_CONTRC2_Px1EnC2_MASK)

#define sig_CONTRC2_Px2EnC2_MASK                 (0x40U)
#define sig_CONTRC2_Px2EnC2_SHIFT                (6U)
/*! Px2EnC2 - Pix2_En_Cluster2
 *  0b0..Pixel 2 will not be evaluated
 *  0b1..Pixel 2 will be evaluated
 */
#define sig_CONTRC2_Px2EnC2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC2_Px2EnC2_SHIFT)) & sig_CONTRC2_Px2EnC2_MASK)

#define sig_CONTRC2_Px3EnC2_MASK                 (0x80U)
#define sig_CONTRC2_Px3EnC2_SHIFT                (7U)
/*! Px3EnC2 - Pix3_En_Cluster2
 *  0b0..Pixel 3 will not be evaluated
 *  0b1..Pixel 3 will be evaluated
 */
#define sig_CONTRC2_Px3EnC2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC2_Px3EnC2_SHIFT)) & sig_CONTRC2_Px3EnC2_MASK)

#define sig_CONTRC2_MakBlC2_MASK                 (0xFF00U)
#define sig_CONTRC2_MakBlC2_SHIFT                (8U)
/*! MakBlC2 - MaskBlue_Cluster2 */
#define sig_CONTRC2_MakBlC2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC2_MakBlC2_SHIFT)) & sig_CONTRC2_MakBlC2_MASK)

#define sig_CONTRC2_MakGrC2_MASK                 (0xFF0000U)
#define sig_CONTRC2_MakGrC2_SHIFT                (16U)
/*! MakGrC2 - MaskGreen_Cluster2 */
#define sig_CONTRC2_MakGrC2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC2_MakGrC2_SHIFT)) & sig_CONTRC2_MakGrC2_MASK)

#define sig_CONTRC2_MakRedC2_MASK                (0xFF000000U)
#define sig_CONTRC2_MakRedC2_SHIFT               (24U)
/*! MakRedC2 - MaskRed_Cluster2 */
#define sig_CONTRC2_MakRedC2(x)                  (((uint32_t)(((uint32_t)(x)) << sig_CONTRC2_MakRedC2_SHIFT)) & sig_CONTRC2_MakRedC2_MASK)
/*! @} */

/*! @name PIX0C2 - Pix0_Cluster2 */
/*! @{ */

#define sig_PIX0C2_X0Clust2_MASK                 (0x3FFFU)
#define sig_PIX0C2_X0Clust2_SHIFT                (0U)
/*! X0Clust2 - X0_Cluster2 */
#define sig_PIX0C2_X0Clust2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX0C2_X0Clust2_SHIFT)) & sig_PIX0C2_X0Clust2_MASK)

#define sig_PIX0C2_Y0Clust2_MASK                 (0x3FFF0000U)
#define sig_PIX0C2_Y0Clust2_SHIFT                (16U)
/*! Y0Clust2 - Y0_Cluster2 */
#define sig_PIX0C2_Y0Clust2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX0C2_Y0Clust2_SHIFT)) & sig_PIX0C2_Y0Clust2_MASK)
/*! @} */

/*! @name PIX1C2 - Pix1_Cluster2 */
/*! @{ */

#define sig_PIX1C2_X1Clust2_MASK                 (0x3FFFU)
#define sig_PIX1C2_X1Clust2_SHIFT                (0U)
/*! X1Clust2 - X1_Cluster2 */
#define sig_PIX1C2_X1Clust2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX1C2_X1Clust2_SHIFT)) & sig_PIX1C2_X1Clust2_MASK)

#define sig_PIX1C2_Y1Clust2_MASK                 (0x3FFF0000U)
#define sig_PIX1C2_Y1Clust2_SHIFT                (16U)
/*! Y1Clust2 - Y1_Cluster2 */
#define sig_PIX1C2_Y1Clust2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX1C2_Y1Clust2_SHIFT)) & sig_PIX1C2_Y1Clust2_MASK)
/*! @} */

/*! @name PIX2C2 - Pix2_Cluster2 */
/*! @{ */

#define sig_PIX2C2_X2Clust2_MASK                 (0x3FFFU)
#define sig_PIX2C2_X2Clust2_SHIFT                (0U)
/*! X2Clust2 - X2_Cluster2 */
#define sig_PIX2C2_X2Clust2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX2C2_X2Clust2_SHIFT)) & sig_PIX2C2_X2Clust2_MASK)

#define sig_PIX2C2_Y2Clust2_MASK                 (0x3FFF0000U)
#define sig_PIX2C2_Y2Clust2_SHIFT                (16U)
/*! Y2Clust2 - Y2_Cluster2 */
#define sig_PIX2C2_Y2Clust2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX2C2_Y2Clust2_SHIFT)) & sig_PIX2C2_Y2Clust2_MASK)
/*! @} */

/*! @name PIX3C2 - Pix3_Cluster2 */
/*! @{ */

#define sig_PIX3C2_X3Clust2_MASK                 (0x3FFFU)
#define sig_PIX3C2_X3Clust2_SHIFT                (0U)
/*! X3Clust2 - X3_Cluster2 */
#define sig_PIX3C2_X3Clust2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX3C2_X3Clust2_SHIFT)) & sig_PIX3C2_X3Clust2_MASK)

#define sig_PIX3C2_Y3Clust2_MASK                 (0x3FFF0000U)
#define sig_PIX3C2_Y3Clust2_SHIFT                (16U)
/*! Y3Clust2 - Y3_Cluster2 */
#define sig_PIX3C2_Y3Clust2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX3C2_Y3Clust2_SHIFT)) & sig_PIX3C2_Y3Clust2_MASK)
/*! @} */

/*! @name REF0CLU2 - Ref0_Cluster2 */
/*! @{ */

#define sig_REF0CLU2_Ref0C2_MASK                 (0xFFFFFFU)
#define sig_REF0CLU2_Ref0C2_SHIFT                (0U)
/*! Ref0C2 - Ref0_Cluster2 */
#define sig_REF0CLU2_Ref0C2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_REF0CLU2_Ref0C2_SHIFT)) & sig_REF0CLU2_Ref0C2_MASK)
/*! @} */

/*! @name REF1CLU2 - Ref1_Cluster2 */
/*! @{ */

#define sig_REF1CLU2_Ref1C2_MASK                 (0xFFFFFFU)
#define sig_REF1CLU2_Ref1C2_SHIFT                (0U)
/*! Ref1C2 - Ref1_Cluster2 */
#define sig_REF1CLU2_Ref1C2(x)                   (((uint32_t)(((uint32_t)(x)) << sig_REF1CLU2_Ref1C2_SHIFT)) & sig_REF1CLU2_Ref1C2_MASK)
/*! @} */

/*! @name CONTRC3 - Control_Cluster3 */
/*! @{ */

#define sig_CONTRC3_EnClust3_MASK                (0x1U)
#define sig_CONTRC3_EnClust3_SHIFT               (0U)
/*! EnClust3 - En_Cluster3
 *  0b0..Cluster is disabled and all Status flags are cleared
 *  0b1..Cluster is enabled and reference checking is executed
 */
#define sig_CONTRC3_EnClust3(x)                  (((uint32_t)(((uint32_t)(x)) << sig_CONTRC3_EnClust3_SHIFT)) & sig_CONTRC3_EnClust3_MASK)

#define sig_CONTRC3_Px0EnC3_MASK                 (0x10U)
#define sig_CONTRC3_Px0EnC3_SHIFT                (4U)
/*! Px0EnC3 - Pix0_En_Cluster3
 *  0b0..Pixel 0 will not be evaluated
 *  0b1..Pixel 0 will be evaluated
 */
#define sig_CONTRC3_Px0EnC3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC3_Px0EnC3_SHIFT)) & sig_CONTRC3_Px0EnC3_MASK)

#define sig_CONTRC3_Px1EnC3_MASK                 (0x20U)
#define sig_CONTRC3_Px1EnC3_SHIFT                (5U)
/*! Px1EnC3 - Pix1_En_Cluster3
 *  0b0..Pixel 1 will not be evaluated
 *  0b1..Pixel 1 will be evaluated
 */
#define sig_CONTRC3_Px1EnC3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC3_Px1EnC3_SHIFT)) & sig_CONTRC3_Px1EnC3_MASK)

#define sig_CONTRC3_Px2EnC3_MASK                 (0x40U)
#define sig_CONTRC3_Px2EnC3_SHIFT                (6U)
/*! Px2EnC3 - Pix2_En_Cluster3
 *  0b0..Pixel 2 will not be evaluated
 *  0b1..Pixel 2 will be evaluated
 */
#define sig_CONTRC3_Px2EnC3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC3_Px2EnC3_SHIFT)) & sig_CONTRC3_Px2EnC3_MASK)

#define sig_CONTRC3_Px3EnC3_MASK                 (0x80U)
#define sig_CONTRC3_Px3EnC3_SHIFT                (7U)
/*! Px3EnC3 - Pix3_En_Cluster3
 *  0b0..Pixel 3 will not be evaluated
 *  0b1..Pixel 3 will be evaluated
 */
#define sig_CONTRC3_Px3EnC3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC3_Px3EnC3_SHIFT)) & sig_CONTRC3_Px3EnC3_MASK)

#define sig_CONTRC3_MakBlC3_MASK                 (0xFF00U)
#define sig_CONTRC3_MakBlC3_SHIFT                (8U)
/*! MakBlC3 - MaskBlue_Cluster3 */
#define sig_CONTRC3_MakBlC3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC3_MakBlC3_SHIFT)) & sig_CONTRC3_MakBlC3_MASK)

#define sig_CONTRC3_MakGrC3_MASK                 (0xFF0000U)
#define sig_CONTRC3_MakGrC3_SHIFT                (16U)
/*! MakGrC3 - MaskGreen_Cluster3 */
#define sig_CONTRC3_MakGrC3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_CONTRC3_MakGrC3_SHIFT)) & sig_CONTRC3_MakGrC3_MASK)

#define sig_CONTRC3_MakRedC3_MASK                (0xFF000000U)
#define sig_CONTRC3_MakRedC3_SHIFT               (24U)
/*! MakRedC3 - MaskRed_Cluster3 */
#define sig_CONTRC3_MakRedC3(x)                  (((uint32_t)(((uint32_t)(x)) << sig_CONTRC3_MakRedC3_SHIFT)) & sig_CONTRC3_MakRedC3_MASK)
/*! @} */

/*! @name PIX0C3 - Pix0_Cluster3 */
/*! @{ */

#define sig_PIX0C3_X0Clust3_MASK                 (0x3FFFU)
#define sig_PIX0C3_X0Clust3_SHIFT                (0U)
/*! X0Clust3 - X0_Cluster3 */
#define sig_PIX0C3_X0Clust3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX0C3_X0Clust3_SHIFT)) & sig_PIX0C3_X0Clust3_MASK)

#define sig_PIX0C3_Y0Clust3_MASK                 (0x3FFF0000U)
#define sig_PIX0C3_Y0Clust3_SHIFT                (16U)
/*! Y0Clust3 - Y0_Cluster3 */
#define sig_PIX0C3_Y0Clust3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX0C3_Y0Clust3_SHIFT)) & sig_PIX0C3_Y0Clust3_MASK)
/*! @} */

/*! @name PIX1C3 - Pix1_Cluster3 */
/*! @{ */

#define sig_PIX1C3_X1Clust3_MASK                 (0x3FFFU)
#define sig_PIX1C3_X1Clust3_SHIFT                (0U)
/*! X1Clust3 - X1_Cluster3 */
#define sig_PIX1C3_X1Clust3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX1C3_X1Clust3_SHIFT)) & sig_PIX1C3_X1Clust3_MASK)

#define sig_PIX1C3_Y1Clust3_MASK                 (0x3FFF0000U)
#define sig_PIX1C3_Y1Clust3_SHIFT                (16U)
/*! Y1Clust3 - Y1_Cluster3 */
#define sig_PIX1C3_Y1Clust3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX1C3_Y1Clust3_SHIFT)) & sig_PIX1C3_Y1Clust3_MASK)
/*! @} */

/*! @name PIX2C3 - Pix2_Cluster3 */
/*! @{ */

#define sig_PIX2C3_X2Clust3_MASK                 (0x3FFFU)
#define sig_PIX2C3_X2Clust3_SHIFT                (0U)
/*! X2Clust3 - X2_Cluster3 */
#define sig_PIX2C3_X2Clust3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX2C3_X2Clust3_SHIFT)) & sig_PIX2C3_X2Clust3_MASK)

#define sig_PIX2C3_Y2Clust3_MASK                 (0x3FFF0000U)
#define sig_PIX2C3_Y2Clust3_SHIFT                (16U)
/*! Y2Clust3 - Y2_Cluster3 */
#define sig_PIX2C3_Y2Clust3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX2C3_Y2Clust3_SHIFT)) & sig_PIX2C3_Y2Clust3_MASK)
/*! @} */

/*! @name PIX3C3 - Pix3_Cluster3 */
/*! @{ */

#define sig_PIX3C3_X3Clust3_MASK                 (0x3FFFU)
#define sig_PIX3C3_X3Clust3_SHIFT                (0U)
/*! X3Clust3 - X3_Cluster3 */
#define sig_PIX3C3_X3Clust3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX3C3_X3Clust3_SHIFT)) & sig_PIX3C3_X3Clust3_MASK)

#define sig_PIX3C3_Y3Clust3_MASK                 (0x3FFF0000U)
#define sig_PIX3C3_Y3Clust3_SHIFT                (16U)
/*! Y3Clust3 - Y3_Cluster3 */
#define sig_PIX3C3_Y3Clust3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_PIX3C3_Y3Clust3_SHIFT)) & sig_PIX3C3_Y3Clust3_MASK)
/*! @} */

/*! @name REF0CLU3 - Ref0_Cluster3 */
/*! @{ */

#define sig_REF0CLU3_Ref0C3_MASK                 (0xFFFFFFU)
#define sig_REF0CLU3_Ref0C3_SHIFT                (0U)
/*! Ref0C3 - Ref0_Cluster3 */
#define sig_REF0CLU3_Ref0C3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_REF0CLU3_Ref0C3_SHIFT)) & sig_REF0CLU3_Ref0C3_MASK)
/*! @} */

/*! @name REF1CLU3 - Ref1_Cluster3 */
/*! @{ */

#define sig_REF1CLU3_Ref1C3_MASK                 (0xFFFFFFU)
#define sig_REF1CLU3_Ref1C3_SHIFT                (0U)
/*! Ref1C3 - Ref1_Cluster3 */
#define sig_REF1CLU3_Ref1C3(x)                   (((uint32_t)(((uint32_t)(x)) << sig_REF1CLU3_Ref1C3_SHIFT)) & sig_REF1CLU3_Ref1C3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group sig_Register_Masks */


/*!
 * @}
 */ /* end of group sig_Peripheral_Access_Layer */


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


#endif  /* PERI_SIG_H_ */

