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
**         CMSIS Peripheral Access Layer for fetchy0c
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
 * @file PERI_fetchy0c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchy0c
 *
 * CMSIS Peripheral Access Layer for fetchy0c
 */

#if !defined(PERI_FETCHY0C_H_)
#define PERI_FETCHY0C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchy0c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchy0c_Peripheral_Access_Layer fetchy0c Peripheral Access Layer
 * @{
 */

/** fetchy0c - Register Layout Typedef */
typedef struct {
  __O  uint32_t FEYUV0LU;                          /**< fetchyuv0_LockUnlock, offset: 0x0 */
  __I  uint32_t FEYUV0LS;                          /**< fetchyuv0_LockStatus, offset: 0x4 */
  __IO uint32_t FEYUV0D;                           /**< fetchyuv0_Dynamic, offset: 0x8 */
  __I  uint32_t FEYUV0S;                           /**< fetchyuv0_Status, offset: 0xC */
} fetchy0c_Type;

/* ----------------------------------------------------------------------------
   -- fetchy0c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchy0c_Register_Masks fetchy0c Register Masks
 * @{
 */

/*! @name FEYUV0LU - fetchyuv0_LockUnlock */
/*! @{ */

#define fetchy0c_FEYUV0LU_fety0LU_MASK           (0xFFFFFFFFU)
#define fetchy0c_FEYUV0LU_fety0LU_SHIFT          (0U)
/*! fety0LU - fetchyuv0_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define fetchy0c_FEYUV0LU_fety0LU(x)             (((uint32_t)(((uint32_t)(x)) << fetchy0c_FEYUV0LU_fety0LU_SHIFT)) & fetchy0c_FEYUV0LU_fety0LU_MASK)
/*! @} */

/*! @name FEYUV0LS - fetchyuv0_LockStatus */
/*! @{ */

#define fetchy0c_FEYUV0LS_fety0LS_MASK           (0x1U)
#define fetchy0c_FEYUV0LS_fety0LS_SHIFT          (0U)
/*! fety0LS - fetchyuv0_LockStatus */
#define fetchy0c_FEYUV0LS_fety0LS(x)             (((uint32_t)(((uint32_t)(x)) << fetchy0c_FEYUV0LS_fety0LS_SHIFT)) & fetchy0c_FEYUV0LS_fety0LS_MASK)

#define fetchy0c_FEYUV0LS_fety0PS_MASK           (0x10U)
#define fetchy0c_FEYUV0LS_fety0PS_SHIFT          (4U)
/*! fety0PS - fetchyuv0_PrivilegeStatus */
#define fetchy0c_FEYUV0LS_fety0PS(x)             (((uint32_t)(((uint32_t)(x)) << fetchy0c_FEYUV0LS_fety0PS_SHIFT)) & fetchy0c_FEYUV0LS_fety0PS_MASK)

#define fetchy0c_FEYUV0LS_fety0FS_MASK           (0x100U)
#define fetchy0c_FEYUV0LS_fety0FS_SHIFT          (8U)
/*! fety0FS - fetchyuv0_FreezeStatus */
#define fetchy0c_FEYUV0LS_fety0FS(x)             (((uint32_t)(((uint32_t)(x)) << fetchy0c_FEYUV0LS_fety0FS_SHIFT)) & fetchy0c_FEYUV0LS_fety0FS_MASK)
/*! @} */

/*! @name FEYUV0D - fetchyuv0_Dynamic */
/*! @{ */

#define fetchy0c_FEYUV0D_fety0scl_MASK           (0x3FU)
#define fetchy0c_FEYUV0D_fety0scl_SHIFT          (0U)
/*! fety0scl - fetchyuv0_src_sel
 *  0b000000..Unit fetchyuv0 input port src is disabled
 *  0b011101..Unit fetchyuv0 input port src is connected to output of unit fetcheco0
 */
#define fetchy0c_FEYUV0D_fety0scl(x)             (((uint32_t)(((uint32_t)(x)) << fetchy0c_FEYUV0D_fety0scl_SHIFT)) & fetchy0c_FEYUV0D_fety0scl_MASK)

#define fetchy0c_FEYUV0D_fety0ssl_MASK           (0x3F00U)
#define fetchy0c_FEYUV0D_fety0ssl_SHIFT          (8U)
/*! fety0ssl - fetchyuv0_sec_sel
 *  0b000000..Unit fetchyuv0 input port sec is disabled
 *  0b011011..Unit fetchyuv0 input port sec is connected to output of unit fetchyuv3
 */
#define fetchy0c_FEYUV0D_fety0ssl(x)             (((uint32_t)(((uint32_t)(x)) << fetchy0c_FEYUV0D_fety0ssl_SHIFT)) & fetchy0c_FEYUV0D_fety0ssl_MASK)
/*! @} */

/*! @name FEYUV0S - fetchyuv0_Status */
/*! @{ */

#define fetchy0c_FEYUV0S_fety0sel_MASK           (0x70000U)
#define fetchy0c_FEYUV0S_fety0sel_SHIFT          (16U)
/*! fety0sel - fetchyuv0_sel
 *  0b000..fetchyuv0 module is not used
 *  0b001..fetchyuv0 module is used from store9 processing path
 *  0b010..fetchyuv0 module is used from extdst0 processing path
 *  0b011..fetchyuv0 module is used from extdst4 processing path
 *  0b100..fetchyuv0 module is used from extdst1 processing path
 *  0b101..fetchyuv0 module is used from extdst5 processing path
 */
#define fetchy0c_FEYUV0S_fety0sel(x)             (((uint32_t)(((uint32_t)(x)) << fetchy0c_FEYUV0S_fety0sel_SHIFT)) & fetchy0c_FEYUV0S_fety0sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchy0c_Register_Masks */


/*!
 * @}
 */ /* end of group fetchy0c_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHY0C_H_ */

