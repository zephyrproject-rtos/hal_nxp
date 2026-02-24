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
**         CMSIS Peripheral Access Layer for fetche0c
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
 * @file PERI_fetche0c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetche0c
 *
 * CMSIS Peripheral Access Layer for fetche0c
 */

#if !defined(PERI_FETCHE0C_H_)
#define PERI_FETCHE0C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetche0c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetche0c_Peripheral_Access_Layer fetche0c Peripheral Access Layer
 * @{
 */

/** fetche0c - Register Layout Typedef */
typedef struct {
  __O  uint32_t FETE0LU;                           /**< fetcheco0_LockUnlock, offset: 0x0 */
  __I  uint32_t FETE0LS;                           /**< fetcheco0_LockStatus, offset: 0x4 */
  __I  uint32_t FETE0S;                            /**< fetcheco0_Status, offset: 0x8 */
} fetche0c_Type;

/* ----------------------------------------------------------------------------
   -- fetche0c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetche0c_Register_Masks fetche0c Register Masks
 * @{
 */

/*! @name FETE0LU - fetcheco0_LockUnlock */
/*! @{ */

#define fetche0c_FETE0LU_fete0LUl_MASK           (0xFFFFFFFFU)
#define fetche0c_FETE0LU_fete0LUl_SHIFT          (0U)
/*! fete0LUl - fetcheco0_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define fetche0c_FETE0LU_fete0LUl(x)             (((uint32_t)(((uint32_t)(x)) << fetche0c_FETE0LU_fete0LUl_SHIFT)) & fetche0c_FETE0LU_fete0LUl_MASK)
/*! @} */

/*! @name FETE0LS - fetcheco0_LockStatus */
/*! @{ */

#define fetche0c_FETE0LS_fete0LS_MASK            (0x1U)
#define fetche0c_FETE0LS_fete0LS_SHIFT           (0U)
/*! fete0LS - fetcheco0_LockStatus */
#define fetche0c_FETE0LS_fete0LS(x)              (((uint32_t)(((uint32_t)(x)) << fetche0c_FETE0LS_fete0LS_SHIFT)) & fetche0c_FETE0LS_fete0LS_MASK)

#define fetche0c_FETE0LS_fete0PS_MASK            (0x10U)
#define fetche0c_FETE0LS_fete0PS_SHIFT           (4U)
/*! fete0PS - fetcheco0_PrivilegeStatus */
#define fetche0c_FETE0LS_fete0PS(x)              (((uint32_t)(((uint32_t)(x)) << fetche0c_FETE0LS_fete0PS_SHIFT)) & fetche0c_FETE0LS_fete0PS_MASK)

#define fetche0c_FETE0LS_fete0FS_MASK            (0x100U)
#define fetche0c_FETE0LS_fete0FS_SHIFT           (8U)
/*! fete0FS - fetcheco0_FreezeStatus */
#define fetche0c_FETE0LS_fete0FS(x)              (((uint32_t)(((uint32_t)(x)) << fetche0c_FETE0LS_fete0FS_SHIFT)) & fetche0c_FETE0LS_fete0FS_MASK)
/*! @} */

/*! @name FETE0S - fetcheco0_Status */
/*! @{ */

#define fetche0c_FETE0S_fete0sel_MASK            (0x70000U)
#define fetche0c_FETE0S_fete0sel_SHIFT           (16U)
/*! fete0sel - fetcheco0_sel
 *  0b000..fetcheco0 module is not used
 *  0b001..fetcheco0 module is used from store9 processing path
 *  0b010..fetcheco0 module is used from extdst0 processing path
 *  0b011..fetcheco0 module is used from extdst4 processing path
 *  0b100..fetcheco0 module is used from extdst1 processing path
 *  0b101..fetcheco0 module is used from extdst5 processing path
 */
#define fetche0c_FETE0S_fete0sel(x)              (((uint32_t)(((uint32_t)(x)) << fetche0c_FETE0S_fete0sel_SHIFT)) & fetche0c_FETE0S_fete0sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetche0c_Register_Masks */


/*!
 * @}
 */ /* end of group fetche0c_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHE0C_H_ */

