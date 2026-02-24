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
**         CMSIS Peripheral Access Layer for idhash2
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
 * @file PERI_idhash2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for idhash2
 *
 * CMSIS Peripheral Access Layer for idhash2
 */

#if !defined(PERI_IDHASH2_H_)
#define PERI_IDHASH2_H_                          /**< Symbol preventing repeated inclusion */

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
   -- idhash2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup idhash2_Peripheral_Access_Layer idhash2 Peripheral Access Layer
 * @{
 */

/** idhash2 - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t PANICTHR;                          /**< PanicThreshold, offset: 0xC */
  __IO uint32_t PANICCOL;                          /**< PanicColor, offset: 0x10 */
  __IO uint32_t SHADOWLD;                          /**< ShadowLoad, offset: 0x14 */
  __IO uint32_t CONTIMO;                           /**< ContinuousMode, offset: 0x18 */
  __I  uint32_t IDHASHS;                           /**< Idhash_Status, offset: 0x1C */
  __IO uint32_t RUNST;                             /**< Run_Status, offset: 0x20 */
  __IO uint32_t CONTW0;                            /**< Control_Window0, offset: 0x24 */
  __IO uint32_t UPPERLW0;                          /**< UpperLeft_Window0, offset: 0x28 */
  __IO uint32_t LOWRIW0;                           /**< LowerRight_Window0, offset: 0x2C */
  __IO uint32_t TILEW0;                            /**< Tile_Window0, offset: 0x30 */
  __IO uint32_t ADDRESW0;                          /**< Address_Window0, offset: 0x34 */
  __IO uint32_t CONFIGW0;                          /**< Config_Window0, offset: 0x38 */
  __IO uint32_t LIMITSW0;                          /**< Limits_Window0, offset: 0x3C */
  __IO uint32_t FOG0W0;                            /**< Foreground0_Window0, offset: 0x40 */
  __IO uint32_t FOG0LIW0;                          /**< Foreground0_Limits_Window0, offset: 0x44 */
  __IO uint32_t FOG1W0;                            /**< Foreground1_Window0, offset: 0x48 */
  __IO uint32_t FOG1LIW0;                          /**< Foreground1_Limits_Window0, offset: 0x4C */
  __IO uint32_t FOG2W0;                            /**< Foreground2_Window0, offset: 0x50 */
  __IO uint32_t FOG2LIW0;                          /**< Foreground2_Limits_Window0, offset: 0x54 */
  __IO uint32_t IDXTBLW0;                          /**< Idx_Table_Window0, offset: 0x58 */
  __IO uint32_t CONTW1;                            /**< Control_Window1, offset: 0x5C */
  __IO uint32_t UPPERLW1;                          /**< UpperLeft_Window1, offset: 0x60 */
  __IO uint32_t LOWRIW1;                           /**< LowerRight_Window1, offset: 0x64 */
  __IO uint32_t TILEW1;                            /**< Tile_Window1, offset: 0x68 */
  __IO uint32_t ADDRESW1;                          /**< Address_Window1, offset: 0x6C */
  __IO uint32_t CONFIGW1;                          /**< Config_Window1, offset: 0x70 */
  __IO uint32_t LIMITSW1;                          /**< Limits_Window1, offset: 0x74 */
  __IO uint32_t FOG0W1;                            /**< Foreground0_Window1, offset: 0x78 */
  __IO uint32_t FO0LIW1;                           /**< Foreground0_Limits_Window1, offset: 0x7C */
  __IO uint32_t FOG1W1;                            /**< Foreground1_Window1, offset: 0x80 */
  __IO uint32_t FOG1LIW1;                          /**< Foreground1_Limits_Window1, offset: 0x84 */
  __IO uint32_t FOG2W1;                            /**< Foreground2_Window1, offset: 0x88 */
  __IO uint32_t FOG2LIW1;                          /**< Foreground2_Limits_Window1, offset: 0x8C */
  __IO uint32_t IDXTBLW1;                          /**< Idx_Table_Window1, offset: 0x90 */
  __IO uint32_t CONTW2;                            /**< Control_Window2, offset: 0x94 */
  __IO uint32_t UPPERLW2;                          /**< UpperLeft_Window2, offset: 0x98 */
  __IO uint32_t LOWRIW2;                           /**< LowerRight_Window2, offset: 0x9C */
  __IO uint32_t TILEW2;                            /**< Tile_Window2, offset: 0xA0 */
  __IO uint32_t ADDRESW2;                          /**< Address_Window2, offset: 0xA4 */
  __IO uint32_t CONFIGW2;                          /**< Config_Window2, offset: 0xA8 */
  __IO uint32_t LIMITSW2;                          /**< Limits_Window2, offset: 0xAC */
  __IO uint32_t FOG0W2;                            /**< Foreground0_Window2, offset: 0xB0 */
  __IO uint32_t FOG0LIW2;                          /**< Foreground0_Limits_Window2, offset: 0xB4 */
  __IO uint32_t FOG1W2;                            /**< Foreground1_Window2, offset: 0xB8 */
  __IO uint32_t FOG1LIW2;                          /**< Foreground1_Limits_Window2, offset: 0xBC */
  __IO uint32_t FOG2W2;                            /**< Foreground2_Window2, offset: 0xC0 */
  __IO uint32_t FOG2LIW2;                          /**< Foreground2_Limits_Window2, offset: 0xC4 */
  __IO uint32_t IDXTBLW2;                          /**< Idx_Table_Window2, offset: 0xC8 */
  __IO uint32_t CONTW3;                            /**< Control_Window3, offset: 0xCC */
  __IO uint32_t UPPERLW3;                          /**< UpperLeft_Window3, offset: 0xD0 */
  __IO uint32_t LOWRIW3;                           /**< LowerRight_Window3, offset: 0xD4 */
  __IO uint32_t TILEW3;                            /**< Tile_Window3, offset: 0xD8 */
  __IO uint32_t ADDRESW3;                          /**< Address_Window3, offset: 0xDC */
  __IO uint32_t CONFIGW3;                          /**< Config_Window3, offset: 0xE0 */
  __IO uint32_t LIMITSW3;                          /**< Limits_Window3, offset: 0xE4 */
  __IO uint32_t FOG0W3;                            /**< Foreground0_Window3, offset: 0xE8 */
  __IO uint32_t FOG0LIW3;                          /**< Foreground0_Limits_Window3, offset: 0xEC */
  __IO uint32_t FOG1W3;                            /**< Foreground1_Window3, offset: 0xF0 */
  __IO uint32_t FOG1LIW3;                          /**< Foreground1_Limits_Window3, offset: 0xF4 */
  __IO uint32_t FOG2W3;                            /**< Foreground2_Window3, offset: 0xF8 */
  __IO uint32_t FOG2LIW3;                          /**< Foreground2_Limits_Window3, offset: 0xFC */
  __IO uint32_t IDXTBLW3;                          /**< Idx_Table_Window3, offset: 0x100 */
} idhash2_Type;

/* ----------------------------------------------------------------------------
   -- idhash2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup idhash2_Register_Masks idhash2 Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define idhash2_LU_LkUn_MASK                     (0xFFFFFFFFU)
#define idhash2_LU_LkUn_SHIFT                    (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define idhash2_LU_LkUn(x)                       (((uint32_t)(((uint32_t)(x)) << idhash2_LU_LkUn_SHIFT)) & idhash2_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define idhash2_LOCKS_LkSus_MASK                 (0x1U)
#define idhash2_LOCKS_LkSus_SHIFT                (0U)
/*! LkSus - LockStatus */
#define idhash2_LOCKS_LkSus(x)                   (((uint32_t)(((uint32_t)(x)) << idhash2_LOCKS_LkSus_SHIFT)) & idhash2_LOCKS_LkSus_MASK)

#define idhash2_LOCKS_PriSt_MASK                 (0x10U)
#define idhash2_LOCKS_PriSt_SHIFT                (4U)
/*! PriSt - PrivilegeStatus */
#define idhash2_LOCKS_PriSt(x)                   (((uint32_t)(((uint32_t)(x)) << idhash2_LOCKS_PriSt_SHIFT)) & idhash2_LOCKS_PriSt_MASK)

#define idhash2_LOCKS_FreezeS_MASK               (0x100U)
#define idhash2_LOCKS_FreezeS_SHIFT              (8U)
/*! FreezeS - FreezeStatus */
#define idhash2_LOCKS_FreezeS(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_LOCKS_FreezeS_SHIFT)) & idhash2_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define idhash2_STATCON_EnCalc_MASK              (0x1U)
#define idhash2_STATCON_EnCalc_SHIFT             (0U)
/*! EnCalc - EnCalc
 *  0b0..bypass mode. the idhash calculation mode will be skipped and avoided.
 *  0b1..idhash perform the calculationmode/idhash extension mode.
 */
#define idhash2_STATCON_EnCalc(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_STATCON_EnCalc_SHIFT)) & idhash2_STATCON_EnCalc_MASK)

#define idhash2_STATCON_SdLdSel_MASK             (0x10U)
#define idhash2_STATCON_SdLdSel_SHIFT            (4U)
/*! SdLdSel - ShdLdSel
 *  0b0..Shadows are loaded at start of frame for each evaluation window for which ShdLdReq has been set.
 *  0b1..Shadows of all evaluation windows are loaded synchronous to the display stream (shadow load token received on frame input port).
 */
#define idhash2_STATCON_SdLdSel(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_STATCON_SdLdSel_SHIFT)) & idhash2_STATCON_SdLdSel_MASK)
/*! @} */

/*! @name PANICTHR - PanicThreshold */
/*! @{ */

#define idhash2_PANICTHR_PanThrs_MASK            (0xFFU)
#define idhash2_PANICTHR_PanThrs_SHIFT           (0U)
/*! PanThrs - PanicThres */
#define idhash2_PANICTHR_PanThrs(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_PANICTHR_PanThrs_SHIFT)) & idhash2_PANICTHR_PanThrs_MASK)

#define idhash2_PANICTHR_PanThrR_MASK            (0xFF0000U)
#define idhash2_PANICTHR_PanThrR_SHIFT           (16U)
/*! PanThrR - PanicThresReset */
#define idhash2_PANICTHR_PanThrR(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_PANICTHR_PanThrR_SHIFT)) & idhash2_PANICTHR_PanThrR_MASK)
/*! @} */

/*! @name PANICCOL - PanicColor */
/*! @{ */

#define idhash2_PANICCOL_PanB_MASK               (0x3FCU)
#define idhash2_PANICCOL_PanB_SHIFT              (2U)
/*! PanB - PanicBlue */
#define idhash2_PANICCOL_PanB(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_PANICCOL_PanB_SHIFT)) & idhash2_PANICCOL_PanB_MASK)

#define idhash2_PANICCOL_PanG_MASK               (0xFF000U)
#define idhash2_PANICCOL_PanG_SHIFT              (12U)
/*! PanG - PanicGreen */
#define idhash2_PANICCOL_PanG(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_PANICCOL_PanG_SHIFT)) & idhash2_PANICCOL_PanG_MASK)

#define idhash2_PANICCOL_PanR_MASK               (0x3FC00000U)
#define idhash2_PANICCOL_PanR_SHIFT              (22U)
/*! PanR - PanicRed */
#define idhash2_PANICCOL_PanR(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_PANICCOL_PanR_SHIFT)) & idhash2_PANICCOL_PanR_MASK)

#define idhash2_PANICCOL_PanA_MASK               (0xC0000000U)
#define idhash2_PANICCOL_PanA_SHIFT              (30U)
/*! PanA - PanicAlpha */
#define idhash2_PANICCOL_PanA(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_PANICCOL_PanA_SHIFT)) & idhash2_PANICCOL_PanA_MASK)
/*! @} */

/*! @name SHADOWLD - ShadowLoad */
/*! @{ */

#define idhash2_SHADOWLD_ShdLdRq_MASK            (0xFU)
#define idhash2_SHADOWLD_ShdLdRq_SHIFT           (0U)
/*! ShdLdRq - ShdLdReq */
#define idhash2_SHADOWLD_ShdLdRq(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_SHADOWLD_ShdLdRq_SHIFT)) & idhash2_SHADOWLD_ShdLdRq_MASK)

#define idhash2_SHADOWLD_SetupID_MASK            (0xFF000000U)
#define idhash2_SHADOWLD_SetupID_SHIFT           (24U)
/*! SetupID - SetupID */
#define idhash2_SHADOWLD_SetupID(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_SHADOWLD_SetupID_SHIFT)) & idhash2_SHADOWLD_SetupID_MASK)
/*! @} */

/*! @name CONTIMO - ContinuousMode */
/*! @{ */

#define idhash2_CONTIMO_EnCont_MASK              (0x1U)
#define idhash2_CONTIMO_EnCont_SHIFT             (0U)
/*! EnCont - EnCont */
#define idhash2_CONTIMO_EnCont(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_CONTIMO_EnCont_SHIFT)) & idhash2_CONTIMO_EnCont_MASK)
/*! @} */

/*! @name IDHASHS - Idhash_Status */
/*! @{ */

#define idhash2_IDHASHS_IdhashS_MASK             (0x1U)
#define idhash2_IDHASHS_IdhashS_SHIFT            (0U)
/*! IdhashS - IdhashState
 *  0b0..Idhash is in idle state
 *  0b1..Idhash is in run state
 */
#define idhash2_IDHASHS_IdhashS(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_IDHASHS_IdhashS_SHIFT)) & idhash2_IDHASHS_IdhashS_MASK)
/*! @} */

/*! @name RUNST - Run_Status */
/*! @{ */

#define idhash2_RUNST_WindowEr_MASK              (0xFU)
#define idhash2_RUNST_WindowEr_SHIFT             (0U)
/*! WindowEr - Window_Error */
#define idhash2_RUNST_WindowEr(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_RUNST_WindowEr_SHIFT)) & idhash2_RUNST_WindowEr_MASK)

#define idhash2_RUNST_WindowPa_MASK              (0xF00U)
#define idhash2_RUNST_WindowPa_SHIFT             (8U)
/*! WindowPa - Window_Panic */
#define idhash2_RUNST_WindowPa(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_RUNST_WindowPa_SHIFT)) & idhash2_RUNST_WindowPa_MASK)

#define idhash2_RUNST_IdhashV_MASK               (0x10000U)
#define idhash2_RUNST_IdhashV_SHIFT              (16U)
/*! IdhashV - IdhashValid
 *  0b0..Idhash results are not valid
 *  0b1..Idhash results are valid
 */
#define idhash2_RUNST_IdhashV(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_RUNST_IdhashV_SHIFT)) & idhash2_RUNST_IdhashV_MASK)

#define idhash2_RUNST_LostSync_MASK              (0x20000U)
#define idhash2_RUNST_LostSync_SHIFT             (17U)
/*! LostSync - Lost_Sync */
#define idhash2_RUNST_LostSync(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_RUNST_LostSync_SHIFT)) & idhash2_RUNST_LostSync_MASK)

#define idhash2_RUNST_ResSetID_MASK              (0xFF000000U)
#define idhash2_RUNST_ResSetID_SHIFT             (24U)
/*! ResSetID - ResultSetupID */
#define idhash2_RUNST_ResSetID(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_RUNST_ResSetID_SHIFT)) & idhash2_RUNST_ResSetID_MASK)
/*! @} */

/*! @name CONTW0 - Control_Window0 */
/*! @{ */

#define idhash2_CONTW0_ModeW0_MASK               (0x7U)
#define idhash2_CONTW0_ModeW0_SHIFT              (0U)
/*! ModeW0 - Mode_Window0
 *  0b000..Window is disabled. The internal status for this window is reset (Error bit and frame counters).
 *  0b001..Window operates in Telltale mode.
 *  0b010..Window operates in Icon mode.
 *  0b011..Window operates in RGB mode.
 *  0b100..1bit Alpha is inserted.
 *  0b101..2bit Alpha is inserted.
 */
#define idhash2_CONTW0_ModeW0(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW0_ModeW0_SHIFT)) & idhash2_CONTW0_ModeW0_MASK)

#define idhash2_CONTW0_AlpMaWi0_MASK             (0x100U)
#define idhash2_CONTW0_AlpMaWi0_SHIFT            (8U)
/*! AlpMaWi0 - AlphaMask_Window0 */
#define idhash2_CONTW0_AlpMaWi0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW0_AlpMaWi0_SHIFT)) & idhash2_CONTW0_AlpMaWi0_MASK)

#define idhash2_CONTW0_AlpIWin0_MASK             (0x200U)
#define idhash2_CONTW0_AlpIWin0_SHIFT            (9U)
/*! AlpIWin0 - AlphaInv_Window0 */
#define idhash2_CONTW0_AlpIWin0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW0_AlpIWin0_SHIFT)) & idhash2_CONTW0_AlpIWin0_MASK)

#define idhash2_CONTW0_AlpSW0_MASK               (0x400U)
#define idhash2_CONTW0_AlpSW0_SHIFT              (10U)
/*! AlpSW0 - AlphaSel_Window0 */
#define idhash2_CONTW0_AlpSW0(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW0_AlpSW0_SHIFT)) & idhash2_CONTW0_AlpSW0_MASK)

#define idhash2_CONTW0_LocPcW0_MASK              (0xF0000U)
#define idhash2_CONTW0_LocPcW0_SHIFT             (16U)
/*! LocPcW0 - LocalPanic_Window0 */
#define idhash2_CONTW0_LocPcW0(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW0_LocPcW0_SHIFT)) & idhash2_CONTW0_LocPcW0_MASK)

#define idhash2_CONTW0_GlobPcW0_MASK             (0x1000000U)
#define idhash2_CONTW0_GlobPcW0_SHIFT            (24U)
/*! GlobPcW0 - GlobalPanic_Window0 */
#define idhash2_CONTW0_GlobPcW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW0_GlobPcW0_SHIFT)) & idhash2_CONTW0_GlobPcW0_MASK)
/*! @} */

/*! @name UPPERLW0 - UpperLeft_Window0 */
/*! @{ */

#define idhash2_UPPERLW0_UpLftXW0_MASK           (0x3FFFU)
#define idhash2_UPPERLW0_UpLftXW0_SHIFT          (0U)
/*! UpLftXW0 - UpperLeft_X_Window0 */
#define idhash2_UPPERLW0_UpLftXW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_UPPERLW0_UpLftXW0_SHIFT)) & idhash2_UPPERLW0_UpLftXW0_MASK)

#define idhash2_UPPERLW0_UpLftYW0_MASK           (0x3FFF0000U)
#define idhash2_UPPERLW0_UpLftYW0_SHIFT          (16U)
/*! UpLftYW0 - UpperLeft_Y_Window0 */
#define idhash2_UPPERLW0_UpLftYW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_UPPERLW0_UpLftYW0_SHIFT)) & idhash2_UPPERLW0_UpLftYW0_MASK)
/*! @} */

/*! @name LOWRIW0 - LowerRight_Window0 */
/*! @{ */

#define idhash2_LOWRIW0_LowRXW0_MASK             (0x3FFFU)
#define idhash2_LOWRIW0_LowRXW0_SHIFT            (0U)
/*! LowRXW0 - LowerRight_X_Window0 */
#define idhash2_LOWRIW0_LowRXW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_LOWRIW0_LowRXW0_SHIFT)) & idhash2_LOWRIW0_LowRXW0_MASK)

#define idhash2_LOWRIW0_LowRYW0_MASK             (0x3FFF0000U)
#define idhash2_LOWRIW0_LowRYW0_SHIFT            (16U)
/*! LowRYW0 - LowerRight_Y_Window0 */
#define idhash2_LOWRIW0_LowRYW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_LOWRIW0_LowRYW0_SHIFT)) & idhash2_LOWRIW0_LowRYW0_MASK)
/*! @} */

/*! @name TILEW0 - Tile_Window0 */
/*! @{ */

#define idhash2_TILEW0_TileXW0_MASK              (0xFU)
#define idhash2_TILEW0_TileXW0_SHIFT             (0U)
/*! TileXW0 - Tile_X_Window0 */
#define idhash2_TILEW0_TileXW0(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_TILEW0_TileXW0_SHIFT)) & idhash2_TILEW0_TileXW0_MASK)

#define idhash2_TILEW0_TileYW0_MASK              (0xF0U)
#define idhash2_TILEW0_TileYW0_SHIFT             (4U)
/*! TileYW0 - Tile_Y_Window0 */
#define idhash2_TILEW0_TileYW0(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_TILEW0_TileYW0_SHIFT)) & idhash2_TILEW0_TileYW0_MASK)
/*! @} */

/*! @name ADDRESW0 - Address_Window0 */
/*! @{ */

#define idhash2_ADDRESW0_AddresW0_MASK           (0xFFCU)
#define idhash2_ADDRESW0_AddresW0_SHIFT          (2U)
/*! AddresW0 - Address_Window0 */
#define idhash2_ADDRESW0_AddresW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_ADDRESW0_AddresW0_SHIFT)) & idhash2_ADDRESW0_AddresW0_MASK)
/*! @} */

/*! @name CONFIGW0 - Config_Window0 */
/*! @{ */

#define idhash2_CONFIGW0_ThFGW0_MASK             (0xFFU)
#define idhash2_CONFIGW0_ThFGW0_SHIFT            (0U)
/*! ThFGW0 - Th_FG_Window0 */
#define idhash2_CONFIGW0_ThFGW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW0_ThFGW0_SHIFT)) & idhash2_CONFIGW0_ThFGW0_MASK)

#define idhash2_CONFIGW0_ThBGW0_MASK             (0xFF00U)
#define idhash2_CONFIGW0_ThBGW0_SHIFT            (8U)
/*! ThBGW0 - Th_BG_Window0 */
#define idhash2_CONFIGW0_ThBGW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW0_ThBGW0_SHIFT)) & idhash2_CONFIGW0_ThBGW0_MASK)

#define idhash2_CONFIGW0_TolerW0_MASK            (0xFF0000U)
#define idhash2_CONFIGW0_TolerW0_SHIFT           (16U)
/*! TolerW0 - Tolerance_Window0 */
#define idhash2_CONFIGW0_TolerW0(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW0_TolerW0_SHIFT)) & idhash2_CONFIGW0_TolerW0_MASK)

#define idhash2_CONFIGW0_RGBThW0_MASK            (0xFF000000U)
#define idhash2_CONFIGW0_RGBThW0_SHIFT           (24U)
/*! RGBThW0 - RGB_Th_Window0 */
#define idhash2_CONFIGW0_RGBThW0(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW0_RGBThW0_SHIFT)) & idhash2_CONFIGW0_RGBThW0_MASK)
/*! @} */

/*! @name LIMITSW0 - Limits_Window0 */
/*! @{ */

#define idhash2_LIMITSW0_FGcSLW0_MASK            (0x3FFFU)
#define idhash2_LIMITSW0_FGcSLW0_SHIFT           (0U)
/*! FGcSLW0 - FG_cnt_SumLimit_Window0 */
#define idhash2_LIMITSW0_FGcSLW0(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_LIMITSW0_FGcSLW0_SHIFT)) & idhash2_LIMITSW0_FGcSLW0_MASK)

#define idhash2_LIMITSW0_DrcSLLW0_MASK           (0x3FFF0000U)
#define idhash2_LIMITSW0_DrcSLLW0_SHIFT          (16U)
/*! DrcSLLW0 - Drop_cnt_SumLimit_Window0 */
#define idhash2_LIMITSW0_DrcSLLW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_LIMITSW0_DrcSLLW0_SHIFT)) & idhash2_LIMITSW0_DrcSLLW0_MASK)
/*! @} */

/*! @name FOG0W0 - Foreground0_Window0 */
/*! @{ */

#define idhash2_FOG0W0_Fore0BW0_MASK             (0xFF00U)
#define idhash2_FOG0W0_Fore0BW0_SHIFT            (8U)
/*! Fore0BW0 - Foreground0_Blue_Window0 */
#define idhash2_FOG0W0_Fore0BW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W0_Fore0BW0_SHIFT)) & idhash2_FOG0W0_Fore0BW0_MASK)

#define idhash2_FOG0W0_Fore0GW0_MASK             (0xFF0000U)
#define idhash2_FOG0W0_Fore0GW0_SHIFT            (16U)
/*! Fore0GW0 - Foreground0_Green_Window0 */
#define idhash2_FOG0W0_Fore0GW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W0_Fore0GW0_SHIFT)) & idhash2_FOG0W0_Fore0GW0_MASK)

#define idhash2_FOG0W0_Fore0RW0_MASK             (0xFF000000U)
#define idhash2_FOG0W0_Fore0RW0_SHIFT            (24U)
/*! Fore0RW0 - Foreground0_Red_Window0 */
#define idhash2_FOG0W0_Fore0RW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W0_Fore0RW0_SHIFT)) & idhash2_FOG0W0_Fore0RW0_MASK)
/*! @} */

/*! @name FOG0LIW0 - Foreground0_Limits_Window0 */
/*! @{ */

#define idhash2_FOG0LIW0_FGcF0LW0_MASK           (0xFFFU)
#define idhash2_FOG0LIW0_FGcF0LW0_SHIFT          (0U)
/*! FGcF0LW0 - FG_cnt_Fg0Limit_Window0 */
#define idhash2_FOG0LIW0_FGcF0LW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0LIW0_FGcF0LW0_SHIFT)) & idhash2_FOG0LIW0_FGcF0LW0_MASK)

#define idhash2_FOG0LIW0_DrcF0LW0_MASK           (0xFFF0000U)
#define idhash2_FOG0LIW0_DrcF0LW0_SHIFT          (16U)
/*! DrcF0LW0 - Drop_cnt_Fg0Limit_Window0 */
#define idhash2_FOG0LIW0_DrcF0LW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0LIW0_DrcF0LW0_SHIFT)) & idhash2_FOG0LIW0_DrcF0LW0_MASK)
/*! @} */

/*! @name FOG1W0 - Foreground1_Window0 */
/*! @{ */

#define idhash2_FOG1W0_Fore1BW0_MASK             (0xFF00U)
#define idhash2_FOG1W0_Fore1BW0_SHIFT            (8U)
/*! Fore1BW0 - Foreground1_Blue_Window0 */
#define idhash2_FOG1W0_Fore1BW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W0_Fore1BW0_SHIFT)) & idhash2_FOG1W0_Fore1BW0_MASK)

#define idhash2_FOG1W0_Fore1GW0_MASK             (0xFF0000U)
#define idhash2_FOG1W0_Fore1GW0_SHIFT            (16U)
/*! Fore1GW0 - Foreground1_Green_Window0 */
#define idhash2_FOG1W0_Fore1GW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W0_Fore1GW0_SHIFT)) & idhash2_FOG1W0_Fore1GW0_MASK)

#define idhash2_FOG1W0_Fore1RW0_MASK             (0xFF000000U)
#define idhash2_FOG1W0_Fore1RW0_SHIFT            (24U)
/*! Fore1RW0 - Foreground1_Red_Window0 */
#define idhash2_FOG1W0_Fore1RW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W0_Fore1RW0_SHIFT)) & idhash2_FOG1W0_Fore1RW0_MASK)
/*! @} */

/*! @name FOG1LIW0 - Foreground1_Limits_Window0 */
/*! @{ */

#define idhash2_FOG1LIW0_FGcF1LW0_MASK           (0xFFFU)
#define idhash2_FOG1LIW0_FGcF1LW0_SHIFT          (0U)
/*! FGcF1LW0 - FG_cnt_Fg1Limit_Window0 */
#define idhash2_FOG1LIW0_FGcF1LW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1LIW0_FGcF1LW0_SHIFT)) & idhash2_FOG1LIW0_FGcF1LW0_MASK)

#define idhash2_FOG1LIW0_DrcF1LW0_MASK           (0xFFF0000U)
#define idhash2_FOG1LIW0_DrcF1LW0_SHIFT          (16U)
/*! DrcF1LW0 - Drop_cnt_Fg1Limit_Window0 */
#define idhash2_FOG1LIW0_DrcF1LW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1LIW0_DrcF1LW0_SHIFT)) & idhash2_FOG1LIW0_DrcF1LW0_MASK)
/*! @} */

/*! @name FOG2W0 - Foreground2_Window0 */
/*! @{ */

#define idhash2_FOG2W0_Fore2BW0_MASK             (0xFF00U)
#define idhash2_FOG2W0_Fore2BW0_SHIFT            (8U)
/*! Fore2BW0 - Foreground2_Blue_Window0 */
#define idhash2_FOG2W0_Fore2BW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W0_Fore2BW0_SHIFT)) & idhash2_FOG2W0_Fore2BW0_MASK)

#define idhash2_FOG2W0_Fore2GW0_MASK             (0xFF0000U)
#define idhash2_FOG2W0_Fore2GW0_SHIFT            (16U)
/*! Fore2GW0 - Foreground2_Green_Window0 */
#define idhash2_FOG2W0_Fore2GW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W0_Fore2GW0_SHIFT)) & idhash2_FOG2W0_Fore2GW0_MASK)

#define idhash2_FOG2W0_Fore2RW0_MASK             (0xFF000000U)
#define idhash2_FOG2W0_Fore2RW0_SHIFT            (24U)
/*! Fore2RW0 - Foreground2_Red_Window0 */
#define idhash2_FOG2W0_Fore2RW0(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W0_Fore2RW0_SHIFT)) & idhash2_FOG2W0_Fore2RW0_MASK)
/*! @} */

/*! @name FOG2LIW0 - Foreground2_Limits_Window0 */
/*! @{ */

#define idhash2_FOG2LIW0_FGcF2LW0_MASK           (0xFFFU)
#define idhash2_FOG2LIW0_FGcF2LW0_SHIFT          (0U)
/*! FGcF2LW0 - FG_cnt_Fg2Limit_Window0 */
#define idhash2_FOG2LIW0_FGcF2LW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2LIW0_FGcF2LW0_SHIFT)) & idhash2_FOG2LIW0_FGcF2LW0_MASK)

#define idhash2_FOG2LIW0_DrcF2LW0_MASK           (0xFFF0000U)
#define idhash2_FOG2LIW0_DrcF2LW0_SHIFT          (16U)
/*! DrcF2LW0 - Drop_cnt_Fg2Limit_Window0 */
#define idhash2_FOG2LIW0_DrcF2LW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2LIW0_DrcF2LW0_SHIFT)) & idhash2_FOG2LIW0_DrcF2LW0_MASK)
/*! @} */

/*! @name IDXTBLW0 - Idx_Table_Window0 */
/*! @{ */

#define idhash2_IDXTBLW0_id0f0EW0_MASK           (0x1U)
#define idhash2_IDXTBLW0_id0f0EW0_SHIFT          (0U)
/*! id0f0EW0 - idx0_fg0_EN_Window0 */
#define idhash2_IDXTBLW0_id0f0EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id0f0EW0_SHIFT)) & idhash2_IDXTBLW0_id0f0EW0_MASK)

#define idhash2_IDXTBLW0_id0f0FW0_MASK           (0x2U)
#define idhash2_IDXTBLW0_id0f0FW0_SHIFT          (1U)
/*! id0f0FW0 - idx0_fg0_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id0f0FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id0f0FW0_SHIFT)) & idhash2_IDXTBLW0_id0f0FW0_MASK)

#define idhash2_IDXTBLW0_id0f1EW0_MASK           (0x4U)
#define idhash2_IDXTBLW0_id0f1EW0_SHIFT          (2U)
/*! id0f1EW0 - idx0_fg1_EN_Window0 */
#define idhash2_IDXTBLW0_id0f1EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id0f1EW0_SHIFT)) & idhash2_IDXTBLW0_id0f1EW0_MASK)

#define idhash2_IDXTBLW0_id0f1FW0_MASK           (0x8U)
#define idhash2_IDXTBLW0_id0f1FW0_SHIFT          (3U)
/*! id0f1FW0 - idx0_fg1_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id0f1FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id0f1FW0_SHIFT)) & idhash2_IDXTBLW0_id0f1FW0_MASK)

#define idhash2_IDXTBLW0_id0f2EW0_MASK           (0x10U)
#define idhash2_IDXTBLW0_id0f2EW0_SHIFT          (4U)
/*! id0f2EW0 - idx0_fg2_EN_Window0 */
#define idhash2_IDXTBLW0_id0f2EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id0f2EW0_SHIFT)) & idhash2_IDXTBLW0_id0f2EW0_MASK)

#define idhash2_IDXTBLW0_id0f2FW0_MASK           (0x20U)
#define idhash2_IDXTBLW0_id0f2FW0_SHIFT          (5U)
/*! id0f2FW0 - idx0_fg2_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id0f2FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id0f2FW0_SHIFT)) & idhash2_IDXTBLW0_id0f2FW0_MASK)

#define idhash2_IDXTBLW0_id1f0EW0_MASK           (0x100U)
#define idhash2_IDXTBLW0_id1f0EW0_SHIFT          (8U)
/*! id1f0EW0 - idx1_fg0_EN_Window0 */
#define idhash2_IDXTBLW0_id1f0EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id1f0EW0_SHIFT)) & idhash2_IDXTBLW0_id1f0EW0_MASK)

#define idhash2_IDXTBLW0_id1f0FW0_MASK           (0x200U)
#define idhash2_IDXTBLW0_id1f0FW0_SHIFT          (9U)
/*! id1f0FW0 - idx1_fg0_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id1f0FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id1f0FW0_SHIFT)) & idhash2_IDXTBLW0_id1f0FW0_MASK)

#define idhash2_IDXTBLW0_id1f1EW0_MASK           (0x400U)
#define idhash2_IDXTBLW0_id1f1EW0_SHIFT          (10U)
/*! id1f1EW0 - idx1_fg1_EN_Window0 */
#define idhash2_IDXTBLW0_id1f1EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id1f1EW0_SHIFT)) & idhash2_IDXTBLW0_id1f1EW0_MASK)

#define idhash2_IDXTBLW0_id1f1FW0_MASK           (0x800U)
#define idhash2_IDXTBLW0_id1f1FW0_SHIFT          (11U)
/*! id1f1FW0 - idx1_fg1_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id1f1FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id1f1FW0_SHIFT)) & idhash2_IDXTBLW0_id1f1FW0_MASK)

#define idhash2_IDXTBLW0_id1f2EW0_MASK           (0x1000U)
#define idhash2_IDXTBLW0_id1f2EW0_SHIFT          (12U)
/*! id1f2EW0 - idx1_fg2_EN_Window0 */
#define idhash2_IDXTBLW0_id1f2EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id1f2EW0_SHIFT)) & idhash2_IDXTBLW0_id1f2EW0_MASK)

#define idhash2_IDXTBLW0_id1f2FW0_MASK           (0x2000U)
#define idhash2_IDXTBLW0_id1f2FW0_SHIFT          (13U)
/*! id1f2FW0 - idx1_fg2_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id1f2FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id1f2FW0_SHIFT)) & idhash2_IDXTBLW0_id1f2FW0_MASK)

#define idhash2_IDXTBLW0_id2f0EW0_MASK           (0x10000U)
#define idhash2_IDXTBLW0_id2f0EW0_SHIFT          (16U)
/*! id2f0EW0 - idx2_fg0_EN_Window0 */
#define idhash2_IDXTBLW0_id2f0EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id2f0EW0_SHIFT)) & idhash2_IDXTBLW0_id2f0EW0_MASK)

#define idhash2_IDXTBLW0_id2f0FW0_MASK           (0x20000U)
#define idhash2_IDXTBLW0_id2f0FW0_SHIFT          (17U)
/*! id2f0FW0 - idx2_fg0_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id2f0FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id2f0FW0_SHIFT)) & idhash2_IDXTBLW0_id2f0FW0_MASK)

#define idhash2_IDXTBLW0_id2f1EW0_MASK           (0x40000U)
#define idhash2_IDXTBLW0_id2f1EW0_SHIFT          (18U)
/*! id2f1EW0 - idx2_fg1_EN_Window0 */
#define idhash2_IDXTBLW0_id2f1EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id2f1EW0_SHIFT)) & idhash2_IDXTBLW0_id2f1EW0_MASK)

#define idhash2_IDXTBLW0_id2f1FW0_MASK           (0x80000U)
#define idhash2_IDXTBLW0_id2f1FW0_SHIFT          (19U)
/*! id2f1FW0 - idx2_fg1_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id2f1FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id2f1FW0_SHIFT)) & idhash2_IDXTBLW0_id2f1FW0_MASK)

#define idhash2_IDXTBLW0_id2f2EW0_MASK           (0x100000U)
#define idhash2_IDXTBLW0_id2f2EW0_SHIFT          (20U)
/*! id2f2EW0 - idx2_fg2_EN_Window0 */
#define idhash2_IDXTBLW0_id2f2EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id2f2EW0_SHIFT)) & idhash2_IDXTBLW0_id2f2EW0_MASK)

#define idhash2_IDXTBLW0_id2f2FW0_MASK           (0x200000U)
#define idhash2_IDXTBLW0_id2f2FW0_SHIFT          (21U)
/*! id2f2FW0 - idx2_fg2_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id2f2FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id2f2FW0_SHIFT)) & idhash2_IDXTBLW0_id2f2FW0_MASK)

#define idhash2_IDXTBLW0_id3f0EW0_MASK           (0x1000000U)
#define idhash2_IDXTBLW0_id3f0EW0_SHIFT          (24U)
/*! id3f0EW0 - idx3_fg0_EN_Window0 */
#define idhash2_IDXTBLW0_id3f0EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id3f0EW0_SHIFT)) & idhash2_IDXTBLW0_id3f0EW0_MASK)

#define idhash2_IDXTBLW0_id3f0FW0_MASK           (0x2000000U)
#define idhash2_IDXTBLW0_id3f0FW0_SHIFT          (25U)
/*! id3f0FW0 - idx3_fg0_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id3f0FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id3f0FW0_SHIFT)) & idhash2_IDXTBLW0_id3f0FW0_MASK)

#define idhash2_IDXTBLW0_id3f1EW0_MASK           (0x4000000U)
#define idhash2_IDXTBLW0_id3f1EW0_SHIFT          (26U)
/*! id3f1EW0 - idx3_fg1_EN_Window0 */
#define idhash2_IDXTBLW0_id3f1EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id3f1EW0_SHIFT)) & idhash2_IDXTBLW0_id3f1EW0_MASK)

#define idhash2_IDXTBLW0_id3f1FW0_MASK           (0x8000000U)
#define idhash2_IDXTBLW0_id3f1FW0_SHIFT          (27U)
/*! id3f1FW0 - idx3_fg1_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id3f1FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id3f1FW0_SHIFT)) & idhash2_IDXTBLW0_id3f1FW0_MASK)

#define idhash2_IDXTBLW0_id3f2EW0_MASK           (0x10000000U)
#define idhash2_IDXTBLW0_id3f2EW0_SHIFT          (28U)
/*! id3f2EW0 - idx3_fg2_EN_Window0 */
#define idhash2_IDXTBLW0_id3f2EW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id3f2EW0_SHIFT)) & idhash2_IDXTBLW0_id3f2EW0_MASK)

#define idhash2_IDXTBLW0_id3f2FW0_MASK           (0x20000000U)
#define idhash2_IDXTBLW0_id3f2FW0_SHIFT          (29U)
/*! id3f2FW0 - idx3_fg2_FG_BGn_Window0 */
#define idhash2_IDXTBLW0_id3f2FW0(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW0_id3f2FW0_SHIFT)) & idhash2_IDXTBLW0_id3f2FW0_MASK)
/*! @} */

/*! @name CONTW1 - Control_Window1 */
/*! @{ */

#define idhash2_CONTW1_ModeW1_MASK               (0x7U)
#define idhash2_CONTW1_ModeW1_SHIFT              (0U)
/*! ModeW1 - Mode_Window1
 *  0b000..Window is disabled. The internal status for this window is reset (Error bit and frame counters).
 *  0b001..Window operates in Telltale mode.
 *  0b010..Window operates in Icon mode.
 *  0b011..Window operates in RGB mode.
 *  0b100..1bit Alpha is inserted.
 *  0b101..2bit Alpha is inserted.
 */
#define idhash2_CONTW1_ModeW1(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW1_ModeW1_SHIFT)) & idhash2_CONTW1_ModeW1_MASK)

#define idhash2_CONTW1_AlpMaWi1_MASK             (0x100U)
#define idhash2_CONTW1_AlpMaWi1_SHIFT            (8U)
/*! AlpMaWi1 - AlphaMask_Window1 */
#define idhash2_CONTW1_AlpMaWi1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW1_AlpMaWi1_SHIFT)) & idhash2_CONTW1_AlpMaWi1_MASK)

#define idhash2_CONTW1_AlpIWin1_MASK             (0x200U)
#define idhash2_CONTW1_AlpIWin1_SHIFT            (9U)
/*! AlpIWin1 - AlphaInv_Window1 */
#define idhash2_CONTW1_AlpIWin1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW1_AlpIWin1_SHIFT)) & idhash2_CONTW1_AlpIWin1_MASK)

#define idhash2_CONTW1_AlpSW1_MASK               (0x400U)
#define idhash2_CONTW1_AlpSW1_SHIFT              (10U)
/*! AlpSW1 - AlphaSel_Window1 */
#define idhash2_CONTW1_AlpSW1(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW1_AlpSW1_SHIFT)) & idhash2_CONTW1_AlpSW1_MASK)

#define idhash2_CONTW1_LocPcW1_MASK              (0xF0000U)
#define idhash2_CONTW1_LocPcW1_SHIFT             (16U)
/*! LocPcW1 - LocalPanic_Window1 */
#define idhash2_CONTW1_LocPcW1(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW1_LocPcW1_SHIFT)) & idhash2_CONTW1_LocPcW1_MASK)

#define idhash2_CONTW1_GlobPcW1_MASK             (0x1000000U)
#define idhash2_CONTW1_GlobPcW1_SHIFT            (24U)
/*! GlobPcW1 - GlobalPanic_Window1 */
#define idhash2_CONTW1_GlobPcW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW1_GlobPcW1_SHIFT)) & idhash2_CONTW1_GlobPcW1_MASK)
/*! @} */

/*! @name UPPERLW1 - UpperLeft_Window1 */
/*! @{ */

#define idhash2_UPPERLW1_UpLftXW1_MASK           (0x3FFFU)
#define idhash2_UPPERLW1_UpLftXW1_SHIFT          (0U)
/*! UpLftXW1 - UpperLeft_X_Window1 */
#define idhash2_UPPERLW1_UpLftXW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_UPPERLW1_UpLftXW1_SHIFT)) & idhash2_UPPERLW1_UpLftXW1_MASK)

#define idhash2_UPPERLW1_UpLftYW1_MASK           (0x3FFF0000U)
#define idhash2_UPPERLW1_UpLftYW1_SHIFT          (16U)
/*! UpLftYW1 - UpperLeft_Y_Window1 */
#define idhash2_UPPERLW1_UpLftYW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_UPPERLW1_UpLftYW1_SHIFT)) & idhash2_UPPERLW1_UpLftYW1_MASK)
/*! @} */

/*! @name LOWRIW1 - LowerRight_Window1 */
/*! @{ */

#define idhash2_LOWRIW1_LowRXW1_MASK             (0x3FFFU)
#define idhash2_LOWRIW1_LowRXW1_SHIFT            (0U)
/*! LowRXW1 - LowerRight_X_Window1 */
#define idhash2_LOWRIW1_LowRXW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_LOWRIW1_LowRXW1_SHIFT)) & idhash2_LOWRIW1_LowRXW1_MASK)

#define idhash2_LOWRIW1_LowRYW1_MASK             (0x3FFF0000U)
#define idhash2_LOWRIW1_LowRYW1_SHIFT            (16U)
/*! LowRYW1 - LowerRight_Y_Window1 */
#define idhash2_LOWRIW1_LowRYW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_LOWRIW1_LowRYW1_SHIFT)) & idhash2_LOWRIW1_LowRYW1_MASK)
/*! @} */

/*! @name TILEW1 - Tile_Window1 */
/*! @{ */

#define idhash2_TILEW1_TileXW1_MASK              (0xFU)
#define idhash2_TILEW1_TileXW1_SHIFT             (0U)
/*! TileXW1 - Tile_X_Window1 */
#define idhash2_TILEW1_TileXW1(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_TILEW1_TileXW1_SHIFT)) & idhash2_TILEW1_TileXW1_MASK)

#define idhash2_TILEW1_TileYW1_MASK              (0xF0U)
#define idhash2_TILEW1_TileYW1_SHIFT             (4U)
/*! TileYW1 - Tile_Y_Window1 */
#define idhash2_TILEW1_TileYW1(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_TILEW1_TileYW1_SHIFT)) & idhash2_TILEW1_TileYW1_MASK)
/*! @} */

/*! @name ADDRESW1 - Address_Window1 */
/*! @{ */

#define idhash2_ADDRESW1_AddresW1_MASK           (0xFFCU)
#define idhash2_ADDRESW1_AddresW1_SHIFT          (2U)
/*! AddresW1 - Address_Window1 */
#define idhash2_ADDRESW1_AddresW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_ADDRESW1_AddresW1_SHIFT)) & idhash2_ADDRESW1_AddresW1_MASK)
/*! @} */

/*! @name CONFIGW1 - Config_Window1 */
/*! @{ */

#define idhash2_CONFIGW1_ThFGW1_MASK             (0xFFU)
#define idhash2_CONFIGW1_ThFGW1_SHIFT            (0U)
/*! ThFGW1 - Th_FG_Window1 */
#define idhash2_CONFIGW1_ThFGW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW1_ThFGW1_SHIFT)) & idhash2_CONFIGW1_ThFGW1_MASK)

#define idhash2_CONFIGW1_ThBGW1_MASK             (0xFF00U)
#define idhash2_CONFIGW1_ThBGW1_SHIFT            (8U)
/*! ThBGW1 - Th_BG_Window1 */
#define idhash2_CONFIGW1_ThBGW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW1_ThBGW1_SHIFT)) & idhash2_CONFIGW1_ThBGW1_MASK)

#define idhash2_CONFIGW1_TolerW1_MASK            (0xFF0000U)
#define idhash2_CONFIGW1_TolerW1_SHIFT           (16U)
/*! TolerW1 - Tolerance_Window1 */
#define idhash2_CONFIGW1_TolerW1(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW1_TolerW1_SHIFT)) & idhash2_CONFIGW1_TolerW1_MASK)

#define idhash2_CONFIGW1_RGBThW1_MASK            (0xFF000000U)
#define idhash2_CONFIGW1_RGBThW1_SHIFT           (24U)
/*! RGBThW1 - RGB_Th_Window1 */
#define idhash2_CONFIGW1_RGBThW1(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW1_RGBThW1_SHIFT)) & idhash2_CONFIGW1_RGBThW1_MASK)
/*! @} */

/*! @name LIMITSW1 - Limits_Window1 */
/*! @{ */

#define idhash2_LIMITSW1_FGcSLW1_MASK            (0x3FFFU)
#define idhash2_LIMITSW1_FGcSLW1_SHIFT           (0U)
/*! FGcSLW1 - FG_cnt_SumLimit_Window1 */
#define idhash2_LIMITSW1_FGcSLW1(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_LIMITSW1_FGcSLW1_SHIFT)) & idhash2_LIMITSW1_FGcSLW1_MASK)

#define idhash2_LIMITSW1_DrcSLLW1_MASK           (0x3FFF0000U)
#define idhash2_LIMITSW1_DrcSLLW1_SHIFT          (16U)
/*! DrcSLLW1 - Drop_cnt_SumLimit_Window1 */
#define idhash2_LIMITSW1_DrcSLLW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_LIMITSW1_DrcSLLW1_SHIFT)) & idhash2_LIMITSW1_DrcSLLW1_MASK)
/*! @} */

/*! @name FOG0W1 - Foreground0_Window1 */
/*! @{ */

#define idhash2_FOG0W1_Fore0BW1_MASK             (0xFF00U)
#define idhash2_FOG0W1_Fore0BW1_SHIFT            (8U)
/*! Fore0BW1 - Foreground0_Blue_Window1 */
#define idhash2_FOG0W1_Fore0BW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W1_Fore0BW1_SHIFT)) & idhash2_FOG0W1_Fore0BW1_MASK)

#define idhash2_FOG0W1_Fore0GW1_MASK             (0xFF0000U)
#define idhash2_FOG0W1_Fore0GW1_SHIFT            (16U)
/*! Fore0GW1 - Foreground0_Green_Window1 */
#define idhash2_FOG0W1_Fore0GW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W1_Fore0GW1_SHIFT)) & idhash2_FOG0W1_Fore0GW1_MASK)

#define idhash2_FOG0W1_Fore0RW1_MASK             (0xFF000000U)
#define idhash2_FOG0W1_Fore0RW1_SHIFT            (24U)
/*! Fore0RW1 - Foreground0_Red_Window1 */
#define idhash2_FOG0W1_Fore0RW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W1_Fore0RW1_SHIFT)) & idhash2_FOG0W1_Fore0RW1_MASK)
/*! @} */

/*! @name FO0LIW1 - Foreground0_Limits_Window1 */
/*! @{ */

#define idhash2_FO0LIW1_FGcF0LW1_MASK            (0xFFFU)
#define idhash2_FO0LIW1_FGcF0LW1_SHIFT           (0U)
/*! FGcF0LW1 - FG_cnt_Fg0Limit_Window1 */
#define idhash2_FO0LIW1_FGcF0LW1(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_FO0LIW1_FGcF0LW1_SHIFT)) & idhash2_FO0LIW1_FGcF0LW1_MASK)

#define idhash2_FO0LIW1_DrcF0LW1_MASK            (0xFFF0000U)
#define idhash2_FO0LIW1_DrcF0LW1_SHIFT           (16U)
/*! DrcF0LW1 - Drop_cnt_Fg0Limit_Window1 */
#define idhash2_FO0LIW1_DrcF0LW1(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_FO0LIW1_DrcF0LW1_SHIFT)) & idhash2_FO0LIW1_DrcF0LW1_MASK)
/*! @} */

/*! @name FOG1W1 - Foreground1_Window1 */
/*! @{ */

#define idhash2_FOG1W1_Fore1BW1_MASK             (0xFF00U)
#define idhash2_FOG1W1_Fore1BW1_SHIFT            (8U)
/*! Fore1BW1 - Foreground1_Blue_Window1 */
#define idhash2_FOG1W1_Fore1BW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W1_Fore1BW1_SHIFT)) & idhash2_FOG1W1_Fore1BW1_MASK)

#define idhash2_FOG1W1_Fore1GW1_MASK             (0xFF0000U)
#define idhash2_FOG1W1_Fore1GW1_SHIFT            (16U)
/*! Fore1GW1 - Foreground1_Green_Window1 */
#define idhash2_FOG1W1_Fore1GW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W1_Fore1GW1_SHIFT)) & idhash2_FOG1W1_Fore1GW1_MASK)

#define idhash2_FOG1W1_Fore1RW1_MASK             (0xFF000000U)
#define idhash2_FOG1W1_Fore1RW1_SHIFT            (24U)
/*! Fore1RW1 - Foreground1_Red_Window1 */
#define idhash2_FOG1W1_Fore1RW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W1_Fore1RW1_SHIFT)) & idhash2_FOG1W1_Fore1RW1_MASK)
/*! @} */

/*! @name FOG1LIW1 - Foreground1_Limits_Window1 */
/*! @{ */

#define idhash2_FOG1LIW1_FGcF1LW1_MASK           (0xFFFU)
#define idhash2_FOG1LIW1_FGcF1LW1_SHIFT          (0U)
/*! FGcF1LW1 - FG_cnt_Fg1Limit_Window1 */
#define idhash2_FOG1LIW1_FGcF1LW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1LIW1_FGcF1LW1_SHIFT)) & idhash2_FOG1LIW1_FGcF1LW1_MASK)

#define idhash2_FOG1LIW1_DrcF1LW1_MASK           (0xFFF0000U)
#define idhash2_FOG1LIW1_DrcF1LW1_SHIFT          (16U)
/*! DrcF1LW1 - Drop_cnt_Fg1Limit_Window1 */
#define idhash2_FOG1LIW1_DrcF1LW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1LIW1_DrcF1LW1_SHIFT)) & idhash2_FOG1LIW1_DrcF1LW1_MASK)
/*! @} */

/*! @name FOG2W1 - Foreground2_Window1 */
/*! @{ */

#define idhash2_FOG2W1_Fore2BW1_MASK             (0xFF00U)
#define idhash2_FOG2W1_Fore2BW1_SHIFT            (8U)
/*! Fore2BW1 - Foreground2_Blue_Window1 */
#define idhash2_FOG2W1_Fore2BW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W1_Fore2BW1_SHIFT)) & idhash2_FOG2W1_Fore2BW1_MASK)

#define idhash2_FOG2W1_Fore2GW1_MASK             (0xFF0000U)
#define idhash2_FOG2W1_Fore2GW1_SHIFT            (16U)
/*! Fore2GW1 - Foreground2_Green_Window1 */
#define idhash2_FOG2W1_Fore2GW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W1_Fore2GW1_SHIFT)) & idhash2_FOG2W1_Fore2GW1_MASK)

#define idhash2_FOG2W1_Fore2RW1_MASK             (0xFF000000U)
#define idhash2_FOG2W1_Fore2RW1_SHIFT            (24U)
/*! Fore2RW1 - Foreground2_Red_Window1 */
#define idhash2_FOG2W1_Fore2RW1(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W1_Fore2RW1_SHIFT)) & idhash2_FOG2W1_Fore2RW1_MASK)
/*! @} */

/*! @name FOG2LIW1 - Foreground2_Limits_Window1 */
/*! @{ */

#define idhash2_FOG2LIW1_FGcF2LW1_MASK           (0xFFFU)
#define idhash2_FOG2LIW1_FGcF2LW1_SHIFT          (0U)
/*! FGcF2LW1 - FG_cnt_Fg2Limit_Window1 */
#define idhash2_FOG2LIW1_FGcF2LW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2LIW1_FGcF2LW1_SHIFT)) & idhash2_FOG2LIW1_FGcF2LW1_MASK)

#define idhash2_FOG2LIW1_DrcF2LW1_MASK           (0xFFF0000U)
#define idhash2_FOG2LIW1_DrcF2LW1_SHIFT          (16U)
/*! DrcF2LW1 - Drop_cnt_Fg2Limit_Window1 */
#define idhash2_FOG2LIW1_DrcF2LW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2LIW1_DrcF2LW1_SHIFT)) & idhash2_FOG2LIW1_DrcF2LW1_MASK)
/*! @} */

/*! @name IDXTBLW1 - Idx_Table_Window1 */
/*! @{ */

#define idhash2_IDXTBLW1_id0f0EW1_MASK           (0x1U)
#define idhash2_IDXTBLW1_id0f0EW1_SHIFT          (0U)
/*! id0f0EW1 - idx0_fg0_EN_Window1 */
#define idhash2_IDXTBLW1_id0f0EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id0f0EW1_SHIFT)) & idhash2_IDXTBLW1_id0f0EW1_MASK)

#define idhash2_IDXTBLW1_id0f0FW1_MASK           (0x2U)
#define idhash2_IDXTBLW1_id0f0FW1_SHIFT          (1U)
/*! id0f0FW1 - idx0_fg0_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id0f0FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id0f0FW1_SHIFT)) & idhash2_IDXTBLW1_id0f0FW1_MASK)

#define idhash2_IDXTBLW1_id0f1EW1_MASK           (0x4U)
#define idhash2_IDXTBLW1_id0f1EW1_SHIFT          (2U)
/*! id0f1EW1 - idx0_fg1_EN_Window1 */
#define idhash2_IDXTBLW1_id0f1EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id0f1EW1_SHIFT)) & idhash2_IDXTBLW1_id0f1EW1_MASK)

#define idhash2_IDXTBLW1_id0f1FW1_MASK           (0x8U)
#define idhash2_IDXTBLW1_id0f1FW1_SHIFT          (3U)
/*! id0f1FW1 - idx0_fg1_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id0f1FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id0f1FW1_SHIFT)) & idhash2_IDXTBLW1_id0f1FW1_MASK)

#define idhash2_IDXTBLW1_id0f2EW1_MASK           (0x10U)
#define idhash2_IDXTBLW1_id0f2EW1_SHIFT          (4U)
/*! id0f2EW1 - idx0_fg2_EN_Window1 */
#define idhash2_IDXTBLW1_id0f2EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id0f2EW1_SHIFT)) & idhash2_IDXTBLW1_id0f2EW1_MASK)

#define idhash2_IDXTBLW1_id0f2FW1_MASK           (0x20U)
#define idhash2_IDXTBLW1_id0f2FW1_SHIFT          (5U)
/*! id0f2FW1 - idx0_fg2_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id0f2FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id0f2FW1_SHIFT)) & idhash2_IDXTBLW1_id0f2FW1_MASK)

#define idhash2_IDXTBLW1_id1f0EW1_MASK           (0x100U)
#define idhash2_IDXTBLW1_id1f0EW1_SHIFT          (8U)
/*! id1f0EW1 - idx1_fg0_EN_Window1 */
#define idhash2_IDXTBLW1_id1f0EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id1f0EW1_SHIFT)) & idhash2_IDXTBLW1_id1f0EW1_MASK)

#define idhash2_IDXTBLW1_id1f0FW1_MASK           (0x200U)
#define idhash2_IDXTBLW1_id1f0FW1_SHIFT          (9U)
/*! id1f0FW1 - idx1_fg0_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id1f0FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id1f0FW1_SHIFT)) & idhash2_IDXTBLW1_id1f0FW1_MASK)

#define idhash2_IDXTBLW1_id1f1EW1_MASK           (0x400U)
#define idhash2_IDXTBLW1_id1f1EW1_SHIFT          (10U)
/*! id1f1EW1 - idx1_fg1_EN_Window1 */
#define idhash2_IDXTBLW1_id1f1EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id1f1EW1_SHIFT)) & idhash2_IDXTBLW1_id1f1EW1_MASK)

#define idhash2_IDXTBLW1_id1f1FW1_MASK           (0x800U)
#define idhash2_IDXTBLW1_id1f1FW1_SHIFT          (11U)
/*! id1f1FW1 - idx1_fg1_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id1f1FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id1f1FW1_SHIFT)) & idhash2_IDXTBLW1_id1f1FW1_MASK)

#define idhash2_IDXTBLW1_id1f2EW1_MASK           (0x1000U)
#define idhash2_IDXTBLW1_id1f2EW1_SHIFT          (12U)
/*! id1f2EW1 - idx1_fg2_EN_Window1 */
#define idhash2_IDXTBLW1_id1f2EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id1f2EW1_SHIFT)) & idhash2_IDXTBLW1_id1f2EW1_MASK)

#define idhash2_IDXTBLW1_id1f2FW1_MASK           (0x2000U)
#define idhash2_IDXTBLW1_id1f2FW1_SHIFT          (13U)
/*! id1f2FW1 - idx1_fg2_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id1f2FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id1f2FW1_SHIFT)) & idhash2_IDXTBLW1_id1f2FW1_MASK)

#define idhash2_IDXTBLW1_id2f0EW1_MASK           (0x10000U)
#define idhash2_IDXTBLW1_id2f0EW1_SHIFT          (16U)
/*! id2f0EW1 - idx2_fg0_EN_Window1 */
#define idhash2_IDXTBLW1_id2f0EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id2f0EW1_SHIFT)) & idhash2_IDXTBLW1_id2f0EW1_MASK)

#define idhash2_IDXTBLW1_id2f0FW1_MASK           (0x20000U)
#define idhash2_IDXTBLW1_id2f0FW1_SHIFT          (17U)
/*! id2f0FW1 - idx2_fg0_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id2f0FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id2f0FW1_SHIFT)) & idhash2_IDXTBLW1_id2f0FW1_MASK)

#define idhash2_IDXTBLW1_id2f1EW1_MASK           (0x40000U)
#define idhash2_IDXTBLW1_id2f1EW1_SHIFT          (18U)
/*! id2f1EW1 - idx2_fg1_EN_Window1 */
#define idhash2_IDXTBLW1_id2f1EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id2f1EW1_SHIFT)) & idhash2_IDXTBLW1_id2f1EW1_MASK)

#define idhash2_IDXTBLW1_id2f1FW1_MASK           (0x80000U)
#define idhash2_IDXTBLW1_id2f1FW1_SHIFT          (19U)
/*! id2f1FW1 - idx2_fg1_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id2f1FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id2f1FW1_SHIFT)) & idhash2_IDXTBLW1_id2f1FW1_MASK)

#define idhash2_IDXTBLW1_id2f2EW1_MASK           (0x100000U)
#define idhash2_IDXTBLW1_id2f2EW1_SHIFT          (20U)
/*! id2f2EW1 - idx2_fg2_EN_Window1 */
#define idhash2_IDXTBLW1_id2f2EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id2f2EW1_SHIFT)) & idhash2_IDXTBLW1_id2f2EW1_MASK)

#define idhash2_IDXTBLW1_id2f2FW1_MASK           (0x200000U)
#define idhash2_IDXTBLW1_id2f2FW1_SHIFT          (21U)
/*! id2f2FW1 - idx2_fg2_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id2f2FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id2f2FW1_SHIFT)) & idhash2_IDXTBLW1_id2f2FW1_MASK)

#define idhash2_IDXTBLW1_id3f0EW1_MASK           (0x1000000U)
#define idhash2_IDXTBLW1_id3f0EW1_SHIFT          (24U)
/*! id3f0EW1 - idx3_fg0_EN_Window1 */
#define idhash2_IDXTBLW1_id3f0EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id3f0EW1_SHIFT)) & idhash2_IDXTBLW1_id3f0EW1_MASK)

#define idhash2_IDXTBLW1_id3f0FW1_MASK           (0x2000000U)
#define idhash2_IDXTBLW1_id3f0FW1_SHIFT          (25U)
/*! id3f0FW1 - idx3_fg0_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id3f0FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id3f0FW1_SHIFT)) & idhash2_IDXTBLW1_id3f0FW1_MASK)

#define idhash2_IDXTBLW1_id3f1EW1_MASK           (0x4000000U)
#define idhash2_IDXTBLW1_id3f1EW1_SHIFT          (26U)
/*! id3f1EW1 - idx3_fg1_EN_Window1 */
#define idhash2_IDXTBLW1_id3f1EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id3f1EW1_SHIFT)) & idhash2_IDXTBLW1_id3f1EW1_MASK)

#define idhash2_IDXTBLW1_id3f1FW1_MASK           (0x8000000U)
#define idhash2_IDXTBLW1_id3f1FW1_SHIFT          (27U)
/*! id3f1FW1 - idx3_fg1_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id3f1FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id3f1FW1_SHIFT)) & idhash2_IDXTBLW1_id3f1FW1_MASK)

#define idhash2_IDXTBLW1_id3f2EW1_MASK           (0x10000000U)
#define idhash2_IDXTBLW1_id3f2EW1_SHIFT          (28U)
/*! id3f2EW1 - idx3_fg2_EN_Window1 */
#define idhash2_IDXTBLW1_id3f2EW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id3f2EW1_SHIFT)) & idhash2_IDXTBLW1_id3f2EW1_MASK)

#define idhash2_IDXTBLW1_id3f2FW1_MASK           (0x20000000U)
#define idhash2_IDXTBLW1_id3f2FW1_SHIFT          (29U)
/*! id3f2FW1 - idx3_fg2_FG_BGn_Window1 */
#define idhash2_IDXTBLW1_id3f2FW1(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW1_id3f2FW1_SHIFT)) & idhash2_IDXTBLW1_id3f2FW1_MASK)
/*! @} */

/*! @name CONTW2 - Control_Window2 */
/*! @{ */

#define idhash2_CONTW2_ModeW2_MASK               (0x7U)
#define idhash2_CONTW2_ModeW2_SHIFT              (0U)
/*! ModeW2 - Mode_Window2
 *  0b000..Window is disabled. The internal status for this window is reset (Error bit and frame counters).
 *  0b001..Window operates in Telltale mode.
 *  0b010..Window operates in Icon mode.
 *  0b011..Window operates in RGB mode.
 *  0b100..1bit Alpha is inserted.
 *  0b101..2bit Alpha is inserted.
 */
#define idhash2_CONTW2_ModeW2(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW2_ModeW2_SHIFT)) & idhash2_CONTW2_ModeW2_MASK)

#define idhash2_CONTW2_AlpMaWi2_MASK             (0x100U)
#define idhash2_CONTW2_AlpMaWi2_SHIFT            (8U)
/*! AlpMaWi2 - AlphaMask_Window2 */
#define idhash2_CONTW2_AlpMaWi2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW2_AlpMaWi2_SHIFT)) & idhash2_CONTW2_AlpMaWi2_MASK)

#define idhash2_CONTW2_AlpIWin2_MASK             (0x200U)
#define idhash2_CONTW2_AlpIWin2_SHIFT            (9U)
/*! AlpIWin2 - AlphaInv_Window2 */
#define idhash2_CONTW2_AlpIWin2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW2_AlpIWin2_SHIFT)) & idhash2_CONTW2_AlpIWin2_MASK)

#define idhash2_CONTW2_AlpSW2_MASK               (0x400U)
#define idhash2_CONTW2_AlpSW2_SHIFT              (10U)
/*! AlpSW2 - AlphaSel_Window2 */
#define idhash2_CONTW2_AlpSW2(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW2_AlpSW2_SHIFT)) & idhash2_CONTW2_AlpSW2_MASK)

#define idhash2_CONTW2_LocPcW2_MASK              (0xF0000U)
#define idhash2_CONTW2_LocPcW2_SHIFT             (16U)
/*! LocPcW2 - LocalPanic_Window2 */
#define idhash2_CONTW2_LocPcW2(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW2_LocPcW2_SHIFT)) & idhash2_CONTW2_LocPcW2_MASK)

#define idhash2_CONTW2_GlobPcW2_MASK             (0x1000000U)
#define idhash2_CONTW2_GlobPcW2_SHIFT            (24U)
/*! GlobPcW2 - GlobalPanic_Window2 */
#define idhash2_CONTW2_GlobPcW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW2_GlobPcW2_SHIFT)) & idhash2_CONTW2_GlobPcW2_MASK)
/*! @} */

/*! @name UPPERLW2 - UpperLeft_Window2 */
/*! @{ */

#define idhash2_UPPERLW2_UpLftXW2_MASK           (0x3FFFU)
#define idhash2_UPPERLW2_UpLftXW2_SHIFT          (0U)
/*! UpLftXW2 - UpperLeft_X_Window2 */
#define idhash2_UPPERLW2_UpLftXW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_UPPERLW2_UpLftXW2_SHIFT)) & idhash2_UPPERLW2_UpLftXW2_MASK)

#define idhash2_UPPERLW2_UpLftYW2_MASK           (0x3FFF0000U)
#define idhash2_UPPERLW2_UpLftYW2_SHIFT          (16U)
/*! UpLftYW2 - UpperLeft_Y_Window2 */
#define idhash2_UPPERLW2_UpLftYW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_UPPERLW2_UpLftYW2_SHIFT)) & idhash2_UPPERLW2_UpLftYW2_MASK)
/*! @} */

/*! @name LOWRIW2 - LowerRight_Window2 */
/*! @{ */

#define idhash2_LOWRIW2_LowRXW2_MASK             (0x3FFFU)
#define idhash2_LOWRIW2_LowRXW2_SHIFT            (0U)
/*! LowRXW2 - LowerRight_X_Window2 */
#define idhash2_LOWRIW2_LowRXW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_LOWRIW2_LowRXW2_SHIFT)) & idhash2_LOWRIW2_LowRXW2_MASK)

#define idhash2_LOWRIW2_LowRYW2_MASK             (0x3FFF0000U)
#define idhash2_LOWRIW2_LowRYW2_SHIFT            (16U)
/*! LowRYW2 - LowerRight_Y_Window2 */
#define idhash2_LOWRIW2_LowRYW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_LOWRIW2_LowRYW2_SHIFT)) & idhash2_LOWRIW2_LowRYW2_MASK)
/*! @} */

/*! @name TILEW2 - Tile_Window2 */
/*! @{ */

#define idhash2_TILEW2_TileXW2_MASK              (0xFU)
#define idhash2_TILEW2_TileXW2_SHIFT             (0U)
/*! TileXW2 - Tile_X_Window2 */
#define idhash2_TILEW2_TileXW2(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_TILEW2_TileXW2_SHIFT)) & idhash2_TILEW2_TileXW2_MASK)

#define idhash2_TILEW2_TileYW2_MASK              (0xF0U)
#define idhash2_TILEW2_TileYW2_SHIFT             (4U)
/*! TileYW2 - Tile_Y_Window2 */
#define idhash2_TILEW2_TileYW2(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_TILEW2_TileYW2_SHIFT)) & idhash2_TILEW2_TileYW2_MASK)
/*! @} */

/*! @name ADDRESW2 - Address_Window2 */
/*! @{ */

#define idhash2_ADDRESW2_AddresW2_MASK           (0xFFCU)
#define idhash2_ADDRESW2_AddresW2_SHIFT          (2U)
/*! AddresW2 - Address_Window2 */
#define idhash2_ADDRESW2_AddresW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_ADDRESW2_AddresW2_SHIFT)) & idhash2_ADDRESW2_AddresW2_MASK)
/*! @} */

/*! @name CONFIGW2 - Config_Window2 */
/*! @{ */

#define idhash2_CONFIGW2_ThFGW2_MASK             (0xFFU)
#define idhash2_CONFIGW2_ThFGW2_SHIFT            (0U)
/*! ThFGW2 - Th_FG_Window2 */
#define idhash2_CONFIGW2_ThFGW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW2_ThFGW2_SHIFT)) & idhash2_CONFIGW2_ThFGW2_MASK)

#define idhash2_CONFIGW2_ThBGW2_MASK             (0xFF00U)
#define idhash2_CONFIGW2_ThBGW2_SHIFT            (8U)
/*! ThBGW2 - Th_BG_Window2 */
#define idhash2_CONFIGW2_ThBGW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW2_ThBGW2_SHIFT)) & idhash2_CONFIGW2_ThBGW2_MASK)

#define idhash2_CONFIGW2_TolerW2_MASK            (0xFF0000U)
#define idhash2_CONFIGW2_TolerW2_SHIFT           (16U)
/*! TolerW2 - Tolerance_Window2 */
#define idhash2_CONFIGW2_TolerW2(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW2_TolerW2_SHIFT)) & idhash2_CONFIGW2_TolerW2_MASK)

#define idhash2_CONFIGW2_RGBThW2_MASK            (0xFF000000U)
#define idhash2_CONFIGW2_RGBThW2_SHIFT           (24U)
/*! RGBThW2 - RGB_Th_Window2 */
#define idhash2_CONFIGW2_RGBThW2(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW2_RGBThW2_SHIFT)) & idhash2_CONFIGW2_RGBThW2_MASK)
/*! @} */

/*! @name LIMITSW2 - Limits_Window2 */
/*! @{ */

#define idhash2_LIMITSW2_FGcSLW2_MASK            (0x3FFFU)
#define idhash2_LIMITSW2_FGcSLW2_SHIFT           (0U)
/*! FGcSLW2 - FG_cnt_SumLimit_Window2 */
#define idhash2_LIMITSW2_FGcSLW2(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_LIMITSW2_FGcSLW2_SHIFT)) & idhash2_LIMITSW2_FGcSLW2_MASK)

#define idhash2_LIMITSW2_DrcSLLW2_MASK           (0x3FFF0000U)
#define idhash2_LIMITSW2_DrcSLLW2_SHIFT          (16U)
/*! DrcSLLW2 - Drop_cnt_SumLimit_Window2 */
#define idhash2_LIMITSW2_DrcSLLW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_LIMITSW2_DrcSLLW2_SHIFT)) & idhash2_LIMITSW2_DrcSLLW2_MASK)
/*! @} */

/*! @name FOG0W2 - Foreground0_Window2 */
/*! @{ */

#define idhash2_FOG0W2_Fore0BW2_MASK             (0xFF00U)
#define idhash2_FOG0W2_Fore0BW2_SHIFT            (8U)
/*! Fore0BW2 - Foreground0_Blue_Window2 */
#define idhash2_FOG0W2_Fore0BW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W2_Fore0BW2_SHIFT)) & idhash2_FOG0W2_Fore0BW2_MASK)

#define idhash2_FOG0W2_Fore0GW2_MASK             (0xFF0000U)
#define idhash2_FOG0W2_Fore0GW2_SHIFT            (16U)
/*! Fore0GW2 - Foreground0_Green_Window2 */
#define idhash2_FOG0W2_Fore0GW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W2_Fore0GW2_SHIFT)) & idhash2_FOG0W2_Fore0GW2_MASK)

#define idhash2_FOG0W2_Fore0RW2_MASK             (0xFF000000U)
#define idhash2_FOG0W2_Fore0RW2_SHIFT            (24U)
/*! Fore0RW2 - Foreground0_Red_Window2 */
#define idhash2_FOG0W2_Fore0RW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W2_Fore0RW2_SHIFT)) & idhash2_FOG0W2_Fore0RW2_MASK)
/*! @} */

/*! @name FOG0LIW2 - Foreground0_Limits_Window2 */
/*! @{ */

#define idhash2_FOG0LIW2_FGcF0LW2_MASK           (0xFFFU)
#define idhash2_FOG0LIW2_FGcF0LW2_SHIFT          (0U)
/*! FGcF0LW2 - FG_cnt_Fg0Limit_Window2 */
#define idhash2_FOG0LIW2_FGcF0LW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0LIW2_FGcF0LW2_SHIFT)) & idhash2_FOG0LIW2_FGcF0LW2_MASK)

#define idhash2_FOG0LIW2_DrcF0LW2_MASK           (0xFFF0000U)
#define idhash2_FOG0LIW2_DrcF0LW2_SHIFT          (16U)
/*! DrcF0LW2 - Drop_cnt_Fg0Limit_Window2 */
#define idhash2_FOG0LIW2_DrcF0LW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0LIW2_DrcF0LW2_SHIFT)) & idhash2_FOG0LIW2_DrcF0LW2_MASK)
/*! @} */

/*! @name FOG1W2 - Foreground1_Window2 */
/*! @{ */

#define idhash2_FOG1W2_Fore1BW2_MASK             (0xFF00U)
#define idhash2_FOG1W2_Fore1BW2_SHIFT            (8U)
/*! Fore1BW2 - Foreground1_Blue_Window2 */
#define idhash2_FOG1W2_Fore1BW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W2_Fore1BW2_SHIFT)) & idhash2_FOG1W2_Fore1BW2_MASK)

#define idhash2_FOG1W2_Fore1GW2_MASK             (0xFF0000U)
#define idhash2_FOG1W2_Fore1GW2_SHIFT            (16U)
/*! Fore1GW2 - Foreground1_Green_Window2 */
#define idhash2_FOG1W2_Fore1GW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W2_Fore1GW2_SHIFT)) & idhash2_FOG1W2_Fore1GW2_MASK)

#define idhash2_FOG1W2_Fore1RW2_MASK             (0xFF000000U)
#define idhash2_FOG1W2_Fore1RW2_SHIFT            (24U)
/*! Fore1RW2 - Foreground1_Red_Window2 */
#define idhash2_FOG1W2_Fore1RW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W2_Fore1RW2_SHIFT)) & idhash2_FOG1W2_Fore1RW2_MASK)
/*! @} */

/*! @name FOG1LIW2 - Foreground1_Limits_Window2 */
/*! @{ */

#define idhash2_FOG1LIW2_FGcF1LW2_MASK           (0xFFFU)
#define idhash2_FOG1LIW2_FGcF1LW2_SHIFT          (0U)
/*! FGcF1LW2 - FG_cnt_Fg1Limit_Window2 */
#define idhash2_FOG1LIW2_FGcF1LW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1LIW2_FGcF1LW2_SHIFT)) & idhash2_FOG1LIW2_FGcF1LW2_MASK)

#define idhash2_FOG1LIW2_DrcF1LW2_MASK           (0xFFF0000U)
#define idhash2_FOG1LIW2_DrcF1LW2_SHIFT          (16U)
/*! DrcF1LW2 - Drop_cnt_Fg1Limit_Window2 */
#define idhash2_FOG1LIW2_DrcF1LW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1LIW2_DrcF1LW2_SHIFT)) & idhash2_FOG1LIW2_DrcF1LW2_MASK)
/*! @} */

/*! @name FOG2W2 - Foreground2_Window2 */
/*! @{ */

#define idhash2_FOG2W2_Fore2BW2_MASK             (0xFF00U)
#define idhash2_FOG2W2_Fore2BW2_SHIFT            (8U)
/*! Fore2BW2 - Foreground2_Blue_Window2 */
#define idhash2_FOG2W2_Fore2BW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W2_Fore2BW2_SHIFT)) & idhash2_FOG2W2_Fore2BW2_MASK)

#define idhash2_FOG2W2_Fore2GW2_MASK             (0xFF0000U)
#define idhash2_FOG2W2_Fore2GW2_SHIFT            (16U)
/*! Fore2GW2 - Foreground2_Green_Window2 */
#define idhash2_FOG2W2_Fore2GW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W2_Fore2GW2_SHIFT)) & idhash2_FOG2W2_Fore2GW2_MASK)

#define idhash2_FOG2W2_Fore2RW2_MASK             (0xFF000000U)
#define idhash2_FOG2W2_Fore2RW2_SHIFT            (24U)
/*! Fore2RW2 - Foreground2_Red_Window2 */
#define idhash2_FOG2W2_Fore2RW2(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W2_Fore2RW2_SHIFT)) & idhash2_FOG2W2_Fore2RW2_MASK)
/*! @} */

/*! @name FOG2LIW2 - Foreground2_Limits_Window2 */
/*! @{ */

#define idhash2_FOG2LIW2_FGcF2LW2_MASK           (0xFFFU)
#define idhash2_FOG2LIW2_FGcF2LW2_SHIFT          (0U)
/*! FGcF2LW2 - FG_cnt_Fg2Limit_Window2 */
#define idhash2_FOG2LIW2_FGcF2LW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2LIW2_FGcF2LW2_SHIFT)) & idhash2_FOG2LIW2_FGcF2LW2_MASK)

#define idhash2_FOG2LIW2_DrcF2LW2_MASK           (0xFFF0000U)
#define idhash2_FOG2LIW2_DrcF2LW2_SHIFT          (16U)
/*! DrcF2LW2 - Drop_cnt_Fg2Limit_Window2 */
#define idhash2_FOG2LIW2_DrcF2LW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2LIW2_DrcF2LW2_SHIFT)) & idhash2_FOG2LIW2_DrcF2LW2_MASK)
/*! @} */

/*! @name IDXTBLW2 - Idx_Table_Window2 */
/*! @{ */

#define idhash2_IDXTBLW2_id0f0EW2_MASK           (0x1U)
#define idhash2_IDXTBLW2_id0f0EW2_SHIFT          (0U)
/*! id0f0EW2 - idx0_fg0_EN_Window2 */
#define idhash2_IDXTBLW2_id0f0EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id0f0EW2_SHIFT)) & idhash2_IDXTBLW2_id0f0EW2_MASK)

#define idhash2_IDXTBLW2_id0f0FW2_MASK           (0x2U)
#define idhash2_IDXTBLW2_id0f0FW2_SHIFT          (1U)
/*! id0f0FW2 - idx0_fg0_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id0f0FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id0f0FW2_SHIFT)) & idhash2_IDXTBLW2_id0f0FW2_MASK)

#define idhash2_IDXTBLW2_id0f1EW2_MASK           (0x4U)
#define idhash2_IDXTBLW2_id0f1EW2_SHIFT          (2U)
/*! id0f1EW2 - idx0_fg1_EN_Window2 */
#define idhash2_IDXTBLW2_id0f1EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id0f1EW2_SHIFT)) & idhash2_IDXTBLW2_id0f1EW2_MASK)

#define idhash2_IDXTBLW2_id0f1FW2_MASK           (0x8U)
#define idhash2_IDXTBLW2_id0f1FW2_SHIFT          (3U)
/*! id0f1FW2 - idx0_fg1_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id0f1FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id0f1FW2_SHIFT)) & idhash2_IDXTBLW2_id0f1FW2_MASK)

#define idhash2_IDXTBLW2_id0f2EW2_MASK           (0x10U)
#define idhash2_IDXTBLW2_id0f2EW2_SHIFT          (4U)
/*! id0f2EW2 - idx0_fg2_EN_Window2 */
#define idhash2_IDXTBLW2_id0f2EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id0f2EW2_SHIFT)) & idhash2_IDXTBLW2_id0f2EW2_MASK)

#define idhash2_IDXTBLW2_id0f2FW2_MASK           (0x20U)
#define idhash2_IDXTBLW2_id0f2FW2_SHIFT          (5U)
/*! id0f2FW2 - idx0_fg2_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id0f2FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id0f2FW2_SHIFT)) & idhash2_IDXTBLW2_id0f2FW2_MASK)

#define idhash2_IDXTBLW2_id1f0EW2_MASK           (0x100U)
#define idhash2_IDXTBLW2_id1f0EW2_SHIFT          (8U)
/*! id1f0EW2 - idx1_fg0_EN_Window2 */
#define idhash2_IDXTBLW2_id1f0EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id1f0EW2_SHIFT)) & idhash2_IDXTBLW2_id1f0EW2_MASK)

#define idhash2_IDXTBLW2_id1f0FW2_MASK           (0x200U)
#define idhash2_IDXTBLW2_id1f0FW2_SHIFT          (9U)
/*! id1f0FW2 - idx1_fg0_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id1f0FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id1f0FW2_SHIFT)) & idhash2_IDXTBLW2_id1f0FW2_MASK)

#define idhash2_IDXTBLW2_id1f1EW2_MASK           (0x400U)
#define idhash2_IDXTBLW2_id1f1EW2_SHIFT          (10U)
/*! id1f1EW2 - idx1_fg1_EN_Window2 */
#define idhash2_IDXTBLW2_id1f1EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id1f1EW2_SHIFT)) & idhash2_IDXTBLW2_id1f1EW2_MASK)

#define idhash2_IDXTBLW2_id1f1FW2_MASK           (0x800U)
#define idhash2_IDXTBLW2_id1f1FW2_SHIFT          (11U)
/*! id1f1FW2 - idx1_fg1_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id1f1FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id1f1FW2_SHIFT)) & idhash2_IDXTBLW2_id1f1FW2_MASK)

#define idhash2_IDXTBLW2_id1f2EW2_MASK           (0x1000U)
#define idhash2_IDXTBLW2_id1f2EW2_SHIFT          (12U)
/*! id1f2EW2 - idx1_fg2_EN_Window2 */
#define idhash2_IDXTBLW2_id1f2EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id1f2EW2_SHIFT)) & idhash2_IDXTBLW2_id1f2EW2_MASK)

#define idhash2_IDXTBLW2_id1f2FW2_MASK           (0x2000U)
#define idhash2_IDXTBLW2_id1f2FW2_SHIFT          (13U)
/*! id1f2FW2 - idx1_fg2_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id1f2FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id1f2FW2_SHIFT)) & idhash2_IDXTBLW2_id1f2FW2_MASK)

#define idhash2_IDXTBLW2_id2f0EW2_MASK           (0x10000U)
#define idhash2_IDXTBLW2_id2f0EW2_SHIFT          (16U)
/*! id2f0EW2 - idx2_fg0_EN_Window2 */
#define idhash2_IDXTBLW2_id2f0EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id2f0EW2_SHIFT)) & idhash2_IDXTBLW2_id2f0EW2_MASK)

#define idhash2_IDXTBLW2_id2f0FW2_MASK           (0x20000U)
#define idhash2_IDXTBLW2_id2f0FW2_SHIFT          (17U)
/*! id2f0FW2 - idx2_fg0_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id2f0FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id2f0FW2_SHIFT)) & idhash2_IDXTBLW2_id2f0FW2_MASK)

#define idhash2_IDXTBLW2_id2f1EW2_MASK           (0x40000U)
#define idhash2_IDXTBLW2_id2f1EW2_SHIFT          (18U)
/*! id2f1EW2 - idx2_fg1_EN_Window2 */
#define idhash2_IDXTBLW2_id2f1EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id2f1EW2_SHIFT)) & idhash2_IDXTBLW2_id2f1EW2_MASK)

#define idhash2_IDXTBLW2_id2f1FW2_MASK           (0x80000U)
#define idhash2_IDXTBLW2_id2f1FW2_SHIFT          (19U)
/*! id2f1FW2 - idx2_fg1_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id2f1FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id2f1FW2_SHIFT)) & idhash2_IDXTBLW2_id2f1FW2_MASK)

#define idhash2_IDXTBLW2_id2f2EW2_MASK           (0x100000U)
#define idhash2_IDXTBLW2_id2f2EW2_SHIFT          (20U)
/*! id2f2EW2 - idx2_fg2_EN_Window2 */
#define idhash2_IDXTBLW2_id2f2EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id2f2EW2_SHIFT)) & idhash2_IDXTBLW2_id2f2EW2_MASK)

#define idhash2_IDXTBLW2_id2f2FW2_MASK           (0x200000U)
#define idhash2_IDXTBLW2_id2f2FW2_SHIFT          (21U)
/*! id2f2FW2 - idx2_fg2_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id2f2FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id2f2FW2_SHIFT)) & idhash2_IDXTBLW2_id2f2FW2_MASK)

#define idhash2_IDXTBLW2_id3f0EW2_MASK           (0x1000000U)
#define idhash2_IDXTBLW2_id3f0EW2_SHIFT          (24U)
/*! id3f0EW2 - idx3_fg0_EN_Window2 */
#define idhash2_IDXTBLW2_id3f0EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id3f0EW2_SHIFT)) & idhash2_IDXTBLW2_id3f0EW2_MASK)

#define idhash2_IDXTBLW2_id3f0FW2_MASK           (0x2000000U)
#define idhash2_IDXTBLW2_id3f0FW2_SHIFT          (25U)
/*! id3f0FW2 - idx3_fg0_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id3f0FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id3f0FW2_SHIFT)) & idhash2_IDXTBLW2_id3f0FW2_MASK)

#define idhash2_IDXTBLW2_id3f1EW2_MASK           (0x4000000U)
#define idhash2_IDXTBLW2_id3f1EW2_SHIFT          (26U)
/*! id3f1EW2 - idx3_fg1_EN_Window2 */
#define idhash2_IDXTBLW2_id3f1EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id3f1EW2_SHIFT)) & idhash2_IDXTBLW2_id3f1EW2_MASK)

#define idhash2_IDXTBLW2_id3f1FW2_MASK           (0x8000000U)
#define idhash2_IDXTBLW2_id3f1FW2_SHIFT          (27U)
/*! id3f1FW2 - idx3_fg1_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id3f1FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id3f1FW2_SHIFT)) & idhash2_IDXTBLW2_id3f1FW2_MASK)

#define idhash2_IDXTBLW2_id3f2EW2_MASK           (0x10000000U)
#define idhash2_IDXTBLW2_id3f2EW2_SHIFT          (28U)
/*! id3f2EW2 - idx3_fg2_EN_Window2 */
#define idhash2_IDXTBLW2_id3f2EW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id3f2EW2_SHIFT)) & idhash2_IDXTBLW2_id3f2EW2_MASK)

#define idhash2_IDXTBLW2_id3f2FW2_MASK           (0x20000000U)
#define idhash2_IDXTBLW2_id3f2FW2_SHIFT          (29U)
/*! id3f2FW2 - idx3_fg2_FG_BGn_Window2 */
#define idhash2_IDXTBLW2_id3f2FW2(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW2_id3f2FW2_SHIFT)) & idhash2_IDXTBLW2_id3f2FW2_MASK)
/*! @} */

/*! @name CONTW3 - Control_Window3 */
/*! @{ */

#define idhash2_CONTW3_ModeW3_MASK               (0x7U)
#define idhash2_CONTW3_ModeW3_SHIFT              (0U)
/*! ModeW3 - Mode_Window3
 *  0b000..Window is disabled. The internal status for this window is reset (Error bit and frame counters).
 *  0b001..Window operates in Telltale mode.
 *  0b010..Window operates in Icon mode.
 *  0b011..Window operates in RGB mode.
 *  0b100..1bit Alpha is inserted.
 *  0b101..2bit Alpha is inserted.
 */
#define idhash2_CONTW3_ModeW3(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW3_ModeW3_SHIFT)) & idhash2_CONTW3_ModeW3_MASK)

#define idhash2_CONTW3_AlpMaWi3_MASK             (0x100U)
#define idhash2_CONTW3_AlpMaWi3_SHIFT            (8U)
/*! AlpMaWi3 - AlphaMask_Window3 */
#define idhash2_CONTW3_AlpMaWi3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW3_AlpMaWi3_SHIFT)) & idhash2_CONTW3_AlpMaWi3_MASK)

#define idhash2_CONTW3_AlpIWin3_MASK             (0x200U)
#define idhash2_CONTW3_AlpIWin3_SHIFT            (9U)
/*! AlpIWin3 - AlphaInv_Window3 */
#define idhash2_CONTW3_AlpIWin3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW3_AlpIWin3_SHIFT)) & idhash2_CONTW3_AlpIWin3_MASK)

#define idhash2_CONTW3_AlpSW3_MASK               (0x400U)
#define idhash2_CONTW3_AlpSW3_SHIFT              (10U)
/*! AlpSW3 - AlphaSel_Window3 */
#define idhash2_CONTW3_AlpSW3(x)                 (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW3_AlpSW3_SHIFT)) & idhash2_CONTW3_AlpSW3_MASK)

#define idhash2_CONTW3_LocPcW3_MASK              (0xF0000U)
#define idhash2_CONTW3_LocPcW3_SHIFT             (16U)
/*! LocPcW3 - LocalPanic_Window3 */
#define idhash2_CONTW3_LocPcW3(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW3_LocPcW3_SHIFT)) & idhash2_CONTW3_LocPcW3_MASK)

#define idhash2_CONTW3_GlobPcW3_MASK             (0x1000000U)
#define idhash2_CONTW3_GlobPcW3_SHIFT            (24U)
/*! GlobPcW3 - GlobalPanic_Window3 */
#define idhash2_CONTW3_GlobPcW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONTW3_GlobPcW3_SHIFT)) & idhash2_CONTW3_GlobPcW3_MASK)
/*! @} */

/*! @name UPPERLW3 - UpperLeft_Window3 */
/*! @{ */

#define idhash2_UPPERLW3_UpLftXW3_MASK           (0x3FFFU)
#define idhash2_UPPERLW3_UpLftXW3_SHIFT          (0U)
/*! UpLftXW3 - UpperLeft_X_Window3 */
#define idhash2_UPPERLW3_UpLftXW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_UPPERLW3_UpLftXW3_SHIFT)) & idhash2_UPPERLW3_UpLftXW3_MASK)

#define idhash2_UPPERLW3_UpLftYW3_MASK           (0x3FFF0000U)
#define idhash2_UPPERLW3_UpLftYW3_SHIFT          (16U)
/*! UpLftYW3 - UpperLeft_Y_Window3 */
#define idhash2_UPPERLW3_UpLftYW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_UPPERLW3_UpLftYW3_SHIFT)) & idhash2_UPPERLW3_UpLftYW3_MASK)
/*! @} */

/*! @name LOWRIW3 - LowerRight_Window3 */
/*! @{ */

#define idhash2_LOWRIW3_LowRXW3_MASK             (0x3FFFU)
#define idhash2_LOWRIW3_LowRXW3_SHIFT            (0U)
/*! LowRXW3 - LowerRight_X_Window3 */
#define idhash2_LOWRIW3_LowRXW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_LOWRIW3_LowRXW3_SHIFT)) & idhash2_LOWRIW3_LowRXW3_MASK)

#define idhash2_LOWRIW3_LowRYW3_MASK             (0x3FFF0000U)
#define idhash2_LOWRIW3_LowRYW3_SHIFT            (16U)
/*! LowRYW3 - LowerRight_Y_Window3 */
#define idhash2_LOWRIW3_LowRYW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_LOWRIW3_LowRYW3_SHIFT)) & idhash2_LOWRIW3_LowRYW3_MASK)
/*! @} */

/*! @name TILEW3 - Tile_Window3 */
/*! @{ */

#define idhash2_TILEW3_TileXW3_MASK              (0xFU)
#define idhash2_TILEW3_TileXW3_SHIFT             (0U)
/*! TileXW3 - Tile_X_Window3 */
#define idhash2_TILEW3_TileXW3(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_TILEW3_TileXW3_SHIFT)) & idhash2_TILEW3_TileXW3_MASK)

#define idhash2_TILEW3_TileYW3_MASK              (0xF0U)
#define idhash2_TILEW3_TileYW3_SHIFT             (4U)
/*! TileYW3 - Tile_Y_Window3 */
#define idhash2_TILEW3_TileYW3(x)                (((uint32_t)(((uint32_t)(x)) << idhash2_TILEW3_TileYW3_SHIFT)) & idhash2_TILEW3_TileYW3_MASK)
/*! @} */

/*! @name ADDRESW3 - Address_Window3 */
/*! @{ */

#define idhash2_ADDRESW3_AddresW3_MASK           (0xFFCU)
#define idhash2_ADDRESW3_AddresW3_SHIFT          (2U)
/*! AddresW3 - Address_Window3 */
#define idhash2_ADDRESW3_AddresW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_ADDRESW3_AddresW3_SHIFT)) & idhash2_ADDRESW3_AddresW3_MASK)
/*! @} */

/*! @name CONFIGW3 - Config_Window3 */
/*! @{ */

#define idhash2_CONFIGW3_ThFGW3_MASK             (0xFFU)
#define idhash2_CONFIGW3_ThFGW3_SHIFT            (0U)
/*! ThFGW3 - Th_FG_Window3 */
#define idhash2_CONFIGW3_ThFGW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW3_ThFGW3_SHIFT)) & idhash2_CONFIGW3_ThFGW3_MASK)

#define idhash2_CONFIGW3_ThBGW3_MASK             (0xFF00U)
#define idhash2_CONFIGW3_ThBGW3_SHIFT            (8U)
/*! ThBGW3 - Th_BG_Window3 */
#define idhash2_CONFIGW3_ThBGW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW3_ThBGW3_SHIFT)) & idhash2_CONFIGW3_ThBGW3_MASK)

#define idhash2_CONFIGW3_TolerW3_MASK            (0xFF0000U)
#define idhash2_CONFIGW3_TolerW3_SHIFT           (16U)
/*! TolerW3 - Tolerance_Window3 */
#define idhash2_CONFIGW3_TolerW3(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW3_TolerW3_SHIFT)) & idhash2_CONFIGW3_TolerW3_MASK)

#define idhash2_CONFIGW3_RGBThW3_MASK            (0xFF000000U)
#define idhash2_CONFIGW3_RGBThW3_SHIFT           (24U)
/*! RGBThW3 - RGB_Th_Window3 */
#define idhash2_CONFIGW3_RGBThW3(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_CONFIGW3_RGBThW3_SHIFT)) & idhash2_CONFIGW3_RGBThW3_MASK)
/*! @} */

/*! @name LIMITSW3 - Limits_Window3 */
/*! @{ */

#define idhash2_LIMITSW3_FGcSLW3_MASK            (0x3FFFU)
#define idhash2_LIMITSW3_FGcSLW3_SHIFT           (0U)
/*! FGcSLW3 - FG_cnt_SumLimit_Window3 */
#define idhash2_LIMITSW3_FGcSLW3(x)              (((uint32_t)(((uint32_t)(x)) << idhash2_LIMITSW3_FGcSLW3_SHIFT)) & idhash2_LIMITSW3_FGcSLW3_MASK)

#define idhash2_LIMITSW3_DrcSLLW3_MASK           (0x3FFF0000U)
#define idhash2_LIMITSW3_DrcSLLW3_SHIFT          (16U)
/*! DrcSLLW3 - Drop_cnt_SumLimit_Window3 */
#define idhash2_LIMITSW3_DrcSLLW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_LIMITSW3_DrcSLLW3_SHIFT)) & idhash2_LIMITSW3_DrcSLLW3_MASK)
/*! @} */

/*! @name FOG0W3 - Foreground0_Window3 */
/*! @{ */

#define idhash2_FOG0W3_Fore0BW3_MASK             (0xFF00U)
#define idhash2_FOG0W3_Fore0BW3_SHIFT            (8U)
/*! Fore0BW3 - Foreground0_Blue_Window3 */
#define idhash2_FOG0W3_Fore0BW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W3_Fore0BW3_SHIFT)) & idhash2_FOG0W3_Fore0BW3_MASK)

#define idhash2_FOG0W3_Fore0GW3_MASK             (0xFF0000U)
#define idhash2_FOG0W3_Fore0GW3_SHIFT            (16U)
/*! Fore0GW3 - Foreground0_Green_Window3 */
#define idhash2_FOG0W3_Fore0GW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W3_Fore0GW3_SHIFT)) & idhash2_FOG0W3_Fore0GW3_MASK)

#define idhash2_FOG0W3_Fore0RW3_MASK             (0xFF000000U)
#define idhash2_FOG0W3_Fore0RW3_SHIFT            (24U)
/*! Fore0RW3 - Foreground0_Red_Window3 */
#define idhash2_FOG0W3_Fore0RW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0W3_Fore0RW3_SHIFT)) & idhash2_FOG0W3_Fore0RW3_MASK)
/*! @} */

/*! @name FOG0LIW3 - Foreground0_Limits_Window3 */
/*! @{ */

#define idhash2_FOG0LIW3_FGcF0LW3_MASK           (0xFFFU)
#define idhash2_FOG0LIW3_FGcF0LW3_SHIFT          (0U)
/*! FGcF0LW3 - FG_cnt_Fg0Limit_Window3 */
#define idhash2_FOG0LIW3_FGcF0LW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0LIW3_FGcF0LW3_SHIFT)) & idhash2_FOG0LIW3_FGcF0LW3_MASK)

#define idhash2_FOG0LIW3_DrcF0LW3_MASK           (0xFFF0000U)
#define idhash2_FOG0LIW3_DrcF0LW3_SHIFT          (16U)
/*! DrcF0LW3 - Drop_cnt_Fg0Limit_Window3 */
#define idhash2_FOG0LIW3_DrcF0LW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG0LIW3_DrcF0LW3_SHIFT)) & idhash2_FOG0LIW3_DrcF0LW3_MASK)
/*! @} */

/*! @name FOG1W3 - Foreground1_Window3 */
/*! @{ */

#define idhash2_FOG1W3_Fore1BW3_MASK             (0xFF00U)
#define idhash2_FOG1W3_Fore1BW3_SHIFT            (8U)
/*! Fore1BW3 - Foreground1_Blue_Window3 */
#define idhash2_FOG1W3_Fore1BW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W3_Fore1BW3_SHIFT)) & idhash2_FOG1W3_Fore1BW3_MASK)

#define idhash2_FOG1W3_Fore1GW3_MASK             (0xFF0000U)
#define idhash2_FOG1W3_Fore1GW3_SHIFT            (16U)
/*! Fore1GW3 - Foreground1_Green_Window3 */
#define idhash2_FOG1W3_Fore1GW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W3_Fore1GW3_SHIFT)) & idhash2_FOG1W3_Fore1GW3_MASK)

#define idhash2_FOG1W3_Fore1RW3_MASK             (0xFF000000U)
#define idhash2_FOG1W3_Fore1RW3_SHIFT            (24U)
/*! Fore1RW3 - Foreground1_Red_Window3 */
#define idhash2_FOG1W3_Fore1RW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1W3_Fore1RW3_SHIFT)) & idhash2_FOG1W3_Fore1RW3_MASK)
/*! @} */

/*! @name FOG1LIW3 - Foreground1_Limits_Window3 */
/*! @{ */

#define idhash2_FOG1LIW3_FGcF1LW3_MASK           (0xFFFU)
#define idhash2_FOG1LIW3_FGcF1LW3_SHIFT          (0U)
/*! FGcF1LW3 - FG_cnt_Fg1Limit_Window3 */
#define idhash2_FOG1LIW3_FGcF1LW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1LIW3_FGcF1LW3_SHIFT)) & idhash2_FOG1LIW3_FGcF1LW3_MASK)

#define idhash2_FOG1LIW3_DrcF1LW3_MASK           (0xFFF0000U)
#define idhash2_FOG1LIW3_DrcF1LW3_SHIFT          (16U)
/*! DrcF1LW3 - Drop_cnt_Fg1Limit_Window3 */
#define idhash2_FOG1LIW3_DrcF1LW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG1LIW3_DrcF1LW3_SHIFT)) & idhash2_FOG1LIW3_DrcF1LW3_MASK)
/*! @} */

/*! @name FOG2W3 - Foreground2_Window3 */
/*! @{ */

#define idhash2_FOG2W3_Fore2BW3_MASK             (0xFF00U)
#define idhash2_FOG2W3_Fore2BW3_SHIFT            (8U)
/*! Fore2BW3 - Foreground2_Blue_Window3 */
#define idhash2_FOG2W3_Fore2BW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W3_Fore2BW3_SHIFT)) & idhash2_FOG2W3_Fore2BW3_MASK)

#define idhash2_FOG2W3_Fore2GW3_MASK             (0xFF0000U)
#define idhash2_FOG2W3_Fore2GW3_SHIFT            (16U)
/*! Fore2GW3 - Foreground2_Green_Window3 */
#define idhash2_FOG2W3_Fore2GW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W3_Fore2GW3_SHIFT)) & idhash2_FOG2W3_Fore2GW3_MASK)

#define idhash2_FOG2W3_Fore2RW3_MASK             (0xFF000000U)
#define idhash2_FOG2W3_Fore2RW3_SHIFT            (24U)
/*! Fore2RW3 - Foreground2_Red_Window3 */
#define idhash2_FOG2W3_Fore2RW3(x)               (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2W3_Fore2RW3_SHIFT)) & idhash2_FOG2W3_Fore2RW3_MASK)
/*! @} */

/*! @name FOG2LIW3 - Foreground2_Limits_Window3 */
/*! @{ */

#define idhash2_FOG2LIW3_FGcF2LW3_MASK           (0xFFFU)
#define idhash2_FOG2LIW3_FGcF2LW3_SHIFT          (0U)
/*! FGcF2LW3 - FG_cnt_Fg2Limit_Window3 */
#define idhash2_FOG2LIW3_FGcF2LW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2LIW3_FGcF2LW3_SHIFT)) & idhash2_FOG2LIW3_FGcF2LW3_MASK)

#define idhash2_FOG2LIW3_DrcF2LW3_MASK           (0xFFF0000U)
#define idhash2_FOG2LIW3_DrcF2LW3_SHIFT          (16U)
/*! DrcF2LW3 - Drop_cnt_Fg2Limit_Window3 */
#define idhash2_FOG2LIW3_DrcF2LW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_FOG2LIW3_DrcF2LW3_SHIFT)) & idhash2_FOG2LIW3_DrcF2LW3_MASK)
/*! @} */

/*! @name IDXTBLW3 - Idx_Table_Window3 */
/*! @{ */

#define idhash2_IDXTBLW3_id0f0EW3_MASK           (0x1U)
#define idhash2_IDXTBLW3_id0f0EW3_SHIFT          (0U)
/*! id0f0EW3 - idx0_fg0_EN_Window3 */
#define idhash2_IDXTBLW3_id0f0EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id0f0EW3_SHIFT)) & idhash2_IDXTBLW3_id0f0EW3_MASK)

#define idhash2_IDXTBLW3_id0f0FW3_MASK           (0x2U)
#define idhash2_IDXTBLW3_id0f0FW3_SHIFT          (1U)
/*! id0f0FW3 - idx0_fg0_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id0f0FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id0f0FW3_SHIFT)) & idhash2_IDXTBLW3_id0f0FW3_MASK)

#define idhash2_IDXTBLW3_id0f1EW3_MASK           (0x4U)
#define idhash2_IDXTBLW3_id0f1EW3_SHIFT          (2U)
/*! id0f1EW3 - idx0_fg1_EN_Window3 */
#define idhash2_IDXTBLW3_id0f1EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id0f1EW3_SHIFT)) & idhash2_IDXTBLW3_id0f1EW3_MASK)

#define idhash2_IDXTBLW3_id0f1FW3_MASK           (0x8U)
#define idhash2_IDXTBLW3_id0f1FW3_SHIFT          (3U)
/*! id0f1FW3 - idx0_fg1_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id0f1FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id0f1FW3_SHIFT)) & idhash2_IDXTBLW3_id0f1FW3_MASK)

#define idhash2_IDXTBLW3_id0f2EW3_MASK           (0x10U)
#define idhash2_IDXTBLW3_id0f2EW3_SHIFT          (4U)
/*! id0f2EW3 - idx0_fg2_EN_Window3 */
#define idhash2_IDXTBLW3_id0f2EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id0f2EW3_SHIFT)) & idhash2_IDXTBLW3_id0f2EW3_MASK)

#define idhash2_IDXTBLW3_id0f2FW3_MASK           (0x20U)
#define idhash2_IDXTBLW3_id0f2FW3_SHIFT          (5U)
/*! id0f2FW3 - idx0_fg2_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id0f2FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id0f2FW3_SHIFT)) & idhash2_IDXTBLW3_id0f2FW3_MASK)

#define idhash2_IDXTBLW3_id1f0EW3_MASK           (0x100U)
#define idhash2_IDXTBLW3_id1f0EW3_SHIFT          (8U)
/*! id1f0EW3 - idx1_fg0_EN_Window3 */
#define idhash2_IDXTBLW3_id1f0EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id1f0EW3_SHIFT)) & idhash2_IDXTBLW3_id1f0EW3_MASK)

#define idhash2_IDXTBLW3_id1f0FW3_MASK           (0x200U)
#define idhash2_IDXTBLW3_id1f0FW3_SHIFT          (9U)
/*! id1f0FW3 - idx1_fg0_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id1f0FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id1f0FW3_SHIFT)) & idhash2_IDXTBLW3_id1f0FW3_MASK)

#define idhash2_IDXTBLW3_id1f1EW3_MASK           (0x400U)
#define idhash2_IDXTBLW3_id1f1EW3_SHIFT          (10U)
/*! id1f1EW3 - idx1_fg1_EN_Window3 */
#define idhash2_IDXTBLW3_id1f1EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id1f1EW3_SHIFT)) & idhash2_IDXTBLW3_id1f1EW3_MASK)

#define idhash2_IDXTBLW3_id1f1FW3_MASK           (0x800U)
#define idhash2_IDXTBLW3_id1f1FW3_SHIFT          (11U)
/*! id1f1FW3 - idx1_fg1_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id1f1FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id1f1FW3_SHIFT)) & idhash2_IDXTBLW3_id1f1FW3_MASK)

#define idhash2_IDXTBLW3_id1f2EW3_MASK           (0x1000U)
#define idhash2_IDXTBLW3_id1f2EW3_SHIFT          (12U)
/*! id1f2EW3 - idx1_fg2_EN_Window3 */
#define idhash2_IDXTBLW3_id1f2EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id1f2EW3_SHIFT)) & idhash2_IDXTBLW3_id1f2EW3_MASK)

#define idhash2_IDXTBLW3_id1f2FW3_MASK           (0x2000U)
#define idhash2_IDXTBLW3_id1f2FW3_SHIFT          (13U)
/*! id1f2FW3 - idx1_fg2_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id1f2FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id1f2FW3_SHIFT)) & idhash2_IDXTBLW3_id1f2FW3_MASK)

#define idhash2_IDXTBLW3_id2f0EW3_MASK           (0x10000U)
#define idhash2_IDXTBLW3_id2f0EW3_SHIFT          (16U)
/*! id2f0EW3 - idx2_fg0_EN_Window3 */
#define idhash2_IDXTBLW3_id2f0EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id2f0EW3_SHIFT)) & idhash2_IDXTBLW3_id2f0EW3_MASK)

#define idhash2_IDXTBLW3_id2f0FW3_MASK           (0x20000U)
#define idhash2_IDXTBLW3_id2f0FW3_SHIFT          (17U)
/*! id2f0FW3 - idx2_fg0_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id2f0FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id2f0FW3_SHIFT)) & idhash2_IDXTBLW3_id2f0FW3_MASK)

#define idhash2_IDXTBLW3_id2f1EW3_MASK           (0x40000U)
#define idhash2_IDXTBLW3_id2f1EW3_SHIFT          (18U)
/*! id2f1EW3 - idx2_fg1_EN_Window3 */
#define idhash2_IDXTBLW3_id2f1EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id2f1EW3_SHIFT)) & idhash2_IDXTBLW3_id2f1EW3_MASK)

#define idhash2_IDXTBLW3_id2f1FW3_MASK           (0x80000U)
#define idhash2_IDXTBLW3_id2f1FW3_SHIFT          (19U)
/*! id2f1FW3 - idx2_fg1_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id2f1FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id2f1FW3_SHIFT)) & idhash2_IDXTBLW3_id2f1FW3_MASK)

#define idhash2_IDXTBLW3_id2f2EW3_MASK           (0x100000U)
#define idhash2_IDXTBLW3_id2f2EW3_SHIFT          (20U)
/*! id2f2EW3 - idx2_fg2_EN_Window3 */
#define idhash2_IDXTBLW3_id2f2EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id2f2EW3_SHIFT)) & idhash2_IDXTBLW3_id2f2EW3_MASK)

#define idhash2_IDXTBLW3_id2f2FW3_MASK           (0x200000U)
#define idhash2_IDXTBLW3_id2f2FW3_SHIFT          (21U)
/*! id2f2FW3 - idx2_fg2_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id2f2FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id2f2FW3_SHIFT)) & idhash2_IDXTBLW3_id2f2FW3_MASK)

#define idhash2_IDXTBLW3_id3f0EW3_MASK           (0x1000000U)
#define idhash2_IDXTBLW3_id3f0EW3_SHIFT          (24U)
/*! id3f0EW3 - idx3_fg0_EN_Window3 */
#define idhash2_IDXTBLW3_id3f0EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id3f0EW3_SHIFT)) & idhash2_IDXTBLW3_id3f0EW3_MASK)

#define idhash2_IDXTBLW3_id3f0FW3_MASK           (0x2000000U)
#define idhash2_IDXTBLW3_id3f0FW3_SHIFT          (25U)
/*! id3f0FW3 - idx3_fg0_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id3f0FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id3f0FW3_SHIFT)) & idhash2_IDXTBLW3_id3f0FW3_MASK)

#define idhash2_IDXTBLW3_id3f1EW3_MASK           (0x4000000U)
#define idhash2_IDXTBLW3_id3f1EW3_SHIFT          (26U)
/*! id3f1EW3 - idx3_fg1_EN_Window3 */
#define idhash2_IDXTBLW3_id3f1EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id3f1EW3_SHIFT)) & idhash2_IDXTBLW3_id3f1EW3_MASK)

#define idhash2_IDXTBLW3_id3f1FW3_MASK           (0x8000000U)
#define idhash2_IDXTBLW3_id3f1FW3_SHIFT          (27U)
/*! id3f1FW3 - idx3_fg1_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id3f1FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id3f1FW3_SHIFT)) & idhash2_IDXTBLW3_id3f1FW3_MASK)

#define idhash2_IDXTBLW3_id3f2EW3_MASK           (0x10000000U)
#define idhash2_IDXTBLW3_id3f2EW3_SHIFT          (28U)
/*! id3f2EW3 - idx3_fg2_EN_Window3 */
#define idhash2_IDXTBLW3_id3f2EW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id3f2EW3_SHIFT)) & idhash2_IDXTBLW3_id3f2EW3_MASK)

#define idhash2_IDXTBLW3_id3f2FW3_MASK           (0x20000000U)
#define idhash2_IDXTBLW3_id3f2FW3_SHIFT          (29U)
/*! id3f2FW3 - idx3_fg2_FG_BGn_Window3 */
#define idhash2_IDXTBLW3_id3f2FW3(x)             (((uint32_t)(((uint32_t)(x)) << idhash2_IDXTBLW3_id3f2FW3_SHIFT)) & idhash2_IDXTBLW3_id3f2FW3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group idhash2_Register_Masks */


/*!
 * @}
 */ /* end of group idhash2_Peripheral_Access_Layer */


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


#endif  /* PERI_IDHASH2_H_ */

