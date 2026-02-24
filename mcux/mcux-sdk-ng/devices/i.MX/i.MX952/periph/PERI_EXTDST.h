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
**         CMSIS Peripheral Access Layer for extdst
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
 * @file PERI_extdst.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for extdst
 *
 * CMSIS Peripheral Access Layer for extdst
 */

#if !defined(PERI_EXTDST_H_)
#define PERI_EXTDST_H_                           /**< Symbol preventing repeated inclusion */

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
   -- extdst Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup extdst_Peripheral_Access_Layer extdst Peripheral Access Layer
 * @{
 */

/** extdst - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0xC */
  __O  uint32_t SOFTKICK;                          /**< SoftwareKick, offset: 0x10 */
  __IO uint32_t STATUS;                            /**< Status, offset: 0x14 */
  __I  uint32_t CONTWO;                            /**< ControlWord, offset: 0x18 */
  __I  uint32_t CURPXCNT;                          /**< CurPixelCnt, offset: 0x1C */
  __I  uint32_t LASTPXCN;                          /**< LastPixelCnt, offset: 0x20 */
  __I  uint32_t PERCOUNT;                          /**< PerfCounter, offset: 0x24 */
} extdst_Type;

/* ----------------------------------------------------------------------------
   -- extdst Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup extdst_Register_Masks extdst Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define extdst_LU_LkUn_MASK                      (0xFFFFFFFFU)
#define extdst_LU_LkUn_SHIFT                     (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define extdst_LU_LkUn(x)                        (((uint32_t)(((uint32_t)(x)) << extdst_LU_LkUn_SHIFT)) & extdst_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define extdst_LOCKS_LkSus_MASK                  (0x1U)
#define extdst_LOCKS_LkSus_SHIFT                 (0U)
/*! LkSus - LockStatus */
#define extdst_LOCKS_LkSus(x)                    (((uint32_t)(((uint32_t)(x)) << extdst_LOCKS_LkSus_SHIFT)) & extdst_LOCKS_LkSus_MASK)

#define extdst_LOCKS_PriSt_MASK                  (0x10U)
#define extdst_LOCKS_PriSt_SHIFT                 (4U)
/*! PriSt - PrivilegeStatus */
#define extdst_LOCKS_PriSt(x)                    (((uint32_t)(((uint32_t)(x)) << extdst_LOCKS_PriSt_SHIFT)) & extdst_LOCKS_PriSt_MASK)

#define extdst_LOCKS_FreezeS_MASK                (0x100U)
#define extdst_LOCKS_FreezeS_SHIFT               (8U)
/*! FreezeS - FreezeStatus */
#define extdst_LOCKS_FreezeS(x)                  (((uint32_t)(((uint32_t)(x)) << extdst_LOCKS_FreezeS_SHIFT)) & extdst_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define extdst_STATCON_ShdEn_MASK                (0x1U)
#define extdst_STATCON_ShdEn_SHIFT               (0U)
/*! ShdEn - ShdEn */
#define extdst_STATCON_ShdEn(x)                  (((uint32_t)(((uint32_t)(x)) << extdst_STATCON_ShdEn_SHIFT)) & extdst_STATCON_ShdEn_MASK)

#define extdst_STATCON_KICKMODE_MASK             (0x100U)
#define extdst_STATCON_KICKMODE_SHIFT            (8U)
/*! KICKMODE - KICK_MODE
 *  0b0..kick generation by KICK field only
 *  0b1..kick signal from external allowed
 */
#define extdst_STATCON_KICKMODE(x)               (((uint32_t)(((uint32_t)(x)) << extdst_STATCON_KICKMODE_SHIFT)) & extdst_STATCON_KICKMODE_MASK)

#define extdst_STATCON_PerfCntM_MASK             (0x1000U)
#define extdst_STATCON_PerfCntM_SHIFT            (12U)
/*! PerfCntM - PerfCountMode */
#define extdst_STATCON_PerfCntM(x)               (((uint32_t)(((uint32_t)(x)) << extdst_STATCON_PerfCntM_SHIFT)) & extdst_STATCON_PerfCntM_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define extdst_CONTR_GamAplEn_MASK               (0x1U)
#define extdst_CONTR_GamAplEn_SHIFT              (0U)
/*! GamAplEn - GammaApplyEnable */
#define extdst_CONTR_GamAplEn(x)                 (((uint32_t)(((uint32_t)(x)) << extdst_CONTR_GamAplEn_SHIFT)) & extdst_CONTR_GamAplEn_MASK)
/*! @} */

/*! @name SOFTKICK - SoftwareKick */
/*! @{ */

#define extdst_SOFTKICK_KICK0_MASK               (0x1U)
#define extdst_SOFTKICK_KICK0_SHIFT              (0U)
/*! KICK0 - KICK */
#define extdst_SOFTKICK_KICK0(x)                 (((uint32_t)(((uint32_t)(x)) << extdst_SOFTKICK_KICK0_SHIFT)) & extdst_SOFTKICK_KICK0_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define extdst_STATUS_CNTERRST_MASK              (0x1U)
#define extdst_STATUS_CNTERRST_SHIFT             (0U)
/*! CNTERRST - CNT_ERR_STS */
#define extdst_STATUS_CNTERRST(x)                (((uint32_t)(((uint32_t)(x)) << extdst_STATUS_CNTERRST_SHIFT)) & extdst_STATUS_CNTERRST_MASK)
/*! @} */

/*! @name CONTWO - ControlWord */
/*! @{ */

#define extdst_CONTWO_CWVAL_MASK                 (0xFFFFFFFFU)
#define extdst_CONTWO_CWVAL_SHIFT                (0U)
/*! CWVAL - CW_VAL */
#define extdst_CONTWO_CWVAL(x)                   (((uint32_t)(((uint32_t)(x)) << extdst_CONTWO_CWVAL_SHIFT)) & extdst_CONTWO_CWVAL_MASK)
/*! @} */

/*! @name CURPXCNT - CurPixelCnt */
/*! @{ */

#define extdst_CURPXCNT_CXVAL_MASK               (0xFFFFU)
#define extdst_CURPXCNT_CXVAL_SHIFT              (0U)
/*! CXVAL - C_XVAL */
#define extdst_CURPXCNT_CXVAL(x)                 (((uint32_t)(((uint32_t)(x)) << extdst_CURPXCNT_CXVAL_SHIFT)) & extdst_CURPXCNT_CXVAL_MASK)

#define extdst_CURPXCNT_CYVAL_MASK               (0xFFFF0000U)
#define extdst_CURPXCNT_CYVAL_SHIFT              (16U)
/*! CYVAL - C_YVAL */
#define extdst_CURPXCNT_CYVAL(x)                 (((uint32_t)(((uint32_t)(x)) << extdst_CURPXCNT_CYVAL_SHIFT)) & extdst_CURPXCNT_CYVAL_MASK)
/*! @} */

/*! @name LASTPXCN - LastPixelCnt */
/*! @{ */

#define extdst_LASTPXCN_LXVAL_MASK               (0xFFFFU)
#define extdst_LASTPXCN_LXVAL_SHIFT              (0U)
/*! LXVAL - L_XVAL */
#define extdst_LASTPXCN_LXVAL(x)                 (((uint32_t)(((uint32_t)(x)) << extdst_LASTPXCN_LXVAL_SHIFT)) & extdst_LASTPXCN_LXVAL_MASK)

#define extdst_LASTPXCN_LYVAL_MASK               (0xFFFF0000U)
#define extdst_LASTPXCN_LYVAL_SHIFT              (16U)
/*! LYVAL - L_YVAL */
#define extdst_LASTPXCN_LYVAL(x)                 (((uint32_t)(((uint32_t)(x)) << extdst_LASTPXCN_LYVAL_SHIFT)) & extdst_LASTPXCN_LYVAL_MASK)
/*! @} */

/*! @name PERCOUNT - PerfCounter */
/*! @{ */

#define extdst_PERCOUNT_PerfRes_MASK             (0xFFFFFFFFU)
#define extdst_PERCOUNT_PerfRes_SHIFT            (0U)
/*! PerfRes - PerfResult */
#define extdst_PERCOUNT_PerfRes(x)               (((uint32_t)(((uint32_t)(x)) << extdst_PERCOUNT_PerfRes_SHIFT)) & extdst_PERCOUNT_PerfRes_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group extdst_Register_Masks */


/*!
 * @}
 */ /* end of group extdst_Peripheral_Access_Layer */


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


#endif  /* PERI_EXTDST_H_ */

