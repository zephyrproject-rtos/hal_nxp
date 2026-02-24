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
**         CMSIS Peripheral Access Layer for idhash1c
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
 * @file PERI_idhash1c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for idhash1c
 *
 * CMSIS Peripheral Access Layer for idhash1c
 */

#if !defined(PERI_IDHASH1C_H_)
#define PERI_IDHASH1C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- idhash1c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup idhash1c_Peripheral_Access_Layer idhash1c Peripheral Access Layer
 * @{
 */

/** idhash1c - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t SRCSELEC;                          /**< SrcSelect, offset: 0x8 */
} idhash1c_Type;

/* ----------------------------------------------------------------------------
   -- idhash1c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup idhash1c_Register_Masks idhash1c Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define idhash1c_LU_LkUn_MASK                    (0xFFFFFFFFU)
#define idhash1c_LU_LkUn_SHIFT                   (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define idhash1c_LU_LkUn(x)                      (((uint32_t)(((uint32_t)(x)) << idhash1c_LU_LkUn_SHIFT)) & idhash1c_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define idhash1c_LOCKS_LkSus_MASK                (0x1U)
#define idhash1c_LOCKS_LkSus_SHIFT               (0U)
/*! LkSus - LockStatus */
#define idhash1c_LOCKS_LkSus(x)                  (((uint32_t)(((uint32_t)(x)) << idhash1c_LOCKS_LkSus_SHIFT)) & idhash1c_LOCKS_LkSus_MASK)

#define idhash1c_LOCKS_PriSt_MASK                (0x10U)
#define idhash1c_LOCKS_PriSt_SHIFT               (4U)
/*! PriSt - PrivilegeStatus */
#define idhash1c_LOCKS_PriSt(x)                  (((uint32_t)(((uint32_t)(x)) << idhash1c_LOCKS_PriSt_SHIFT)) & idhash1c_LOCKS_PriSt_MASK)

#define idhash1c_LOCKS_FreezeS_MASK              (0x100U)
#define idhash1c_LOCKS_FreezeS_SHIFT             (8U)
/*! FreezeS - FreezeStatus */
#define idhash1c_LOCKS_FreezeS(x)                (((uint32_t)(((uint32_t)(x)) << idhash1c_LOCKS_FreezeS_SHIFT)) & idhash1c_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name SRCSELEC - SrcSelect */
/*! @{ */

#define idhash1c_SRCSELEC_idhash1s_MASK          (0x7U)
#define idhash1c_SRCSELEC_idhash1s_SHIFT         (0U)
/*! idhash1s - idhash1_select
 *  0b000..Source is FrameGen#1 output.
 *  0b001..Source is Matrix#1 output.
 *  0b010..Source is LuT3D#1 output.
 *  0b100..Source is GammaCor#1 output.
 *  0b101..Source is Dither#1 output.
 */
#define idhash1c_SRCSELEC_idhash1s(x)            (((uint32_t)(((uint32_t)(x)) << idhash1c_SRCSELEC_idhash1s_SHIFT)) & idhash1c_SRCSELEC_idhash1s_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group idhash1c_Register_Masks */


/*!
 * @}
 */ /* end of group idhash1c_Peripheral_Access_Layer */


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


#endif  /* PERI_IDHASH1C_H_ */

