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
**         CMSIS Peripheral Access Layer for fetchd9c
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
 * @file PERI_fetchd9c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchd9c
 *
 * CMSIS Peripheral Access Layer for fetchd9c
 */

#if !defined(PERI_FETCHD9C_H_)
#define PERI_FETCHD9C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchd9c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchd9c_Peripheral_Access_Layer fetchd9c Peripheral Access Layer
 * @{
 */

/** fetchd9c - Register Layout Typedef */
typedef struct {
  __O  uint32_t FETD9LU;                           /**< fetchdecode9_LockUnlock, offset: 0x0 */
  __I  uint32_t FETD9LS;                           /**< fetchdecode9_LockStatus, offset: 0x4 */
  __IO uint32_t FETD9D;                            /**< fetchdecode9_Dynamic, offset: 0x8 */
  __I  uint32_t FETD9S;                            /**< fetchdecode9_Status, offset: 0xC */
} fetchd9c_Type;

/* ----------------------------------------------------------------------------
   -- fetchd9c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchd9c_Register_Masks fetchd9c Register Masks
 * @{
 */

/*! @name FETD9LU - fetchdecode9_LockUnlock */
/*! @{ */

#define fetchd9c_FETD9LU_fetd9LUl_MASK           (0xFFFFFFFFU)
#define fetchd9c_FETD9LU_fetd9LUl_SHIFT          (0U)
/*! fetd9LUl - fetchdecode9_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define fetchd9c_FETD9LU_fetd9LUl(x)             (((uint32_t)(((uint32_t)(x)) << fetchd9c_FETD9LU_fetd9LUl_SHIFT)) & fetchd9c_FETD9LU_fetd9LUl_MASK)
/*! @} */

/*! @name FETD9LS - fetchdecode9_LockStatus */
/*! @{ */

#define fetchd9c_FETD9LS_fetd9LS_MASK            (0x1U)
#define fetchd9c_FETD9LS_fetd9LS_SHIFT           (0U)
/*! fetd9LS - fetchdecode9_LockStatus */
#define fetchd9c_FETD9LS_fetd9LS(x)              (((uint32_t)(((uint32_t)(x)) << fetchd9c_FETD9LS_fetd9LS_SHIFT)) & fetchd9c_FETD9LS_fetd9LS_MASK)

#define fetchd9c_FETD9LS_fetd9PS_MASK            (0x10U)
#define fetchd9c_FETD9LS_fetd9PS_SHIFT           (4U)
/*! fetd9PS - fetchdecode9_PrivilegeStatus */
#define fetchd9c_FETD9LS_fetd9PS(x)              (((uint32_t)(((uint32_t)(x)) << fetchd9c_FETD9LS_fetd9PS_SHIFT)) & fetchd9c_FETD9LS_fetd9PS_MASK)

#define fetchd9c_FETD9LS_fetd9FS_MASK            (0x100U)
#define fetchd9c_FETD9LS_fetd9FS_SHIFT           (8U)
/*! fetd9FS - fetchdecode9_FreezeStatus */
#define fetchd9c_FETD9LS_fetd9FS(x)              (((uint32_t)(((uint32_t)(x)) << fetchd9c_FETD9LS_fetd9FS_SHIFT)) & fetchd9c_FETD9LS_fetd9FS_MASK)
/*! @} */

/*! @name FETD9D - fetchdecode9_Dynamic */
/*! @{ */

#define fetchd9c_FETD9D_fetd9ssl_MASK            (0x3FU)
#define fetchd9c_FETD9D_fetd9ssl_SHIFT           (0U)
/*! fetd9ssl - fetchdecode9_src_sel
 *  0b000000..Unit fetchdecode9 input port src is disabled
 *  0b000101..Unit fetchdecode9 input port src is connected to output of unit fetchrot9
 *  0b000111..Unit fetchdecode9 input port src is connected to output of unit fetcheco9
 */
#define fetchd9c_FETD9D_fetd9ssl(x)              (((uint32_t)(((uint32_t)(x)) << fetchd9c_FETD9D_fetd9ssl_SHIFT)) & fetchd9c_FETD9D_fetd9ssl_MASK)
/*! @} */

/*! @name FETD9S - fetchdecode9_Status */
/*! @{ */

#define fetchd9c_FETD9S_fetd9sel_MASK            (0x70000U)
#define fetchd9c_FETD9S_fetd9sel_SHIFT           (16U)
/*! fetd9sel - fetchdecode9_sel
 *  0b000..fetchdecode9 module is not used
 *  0b001..fetchdecode9 module is used from store9 processing path
 *  0b010..fetchdecode9 module is used from extdst0 processing path
 *  0b011..fetchdecode9 module is used from extdst4 processing path
 *  0b100..fetchdecode9 module is used from extdst1 processing path
 *  0b101..fetchdecode9 module is used from extdst5 processing path
 */
#define fetchd9c_FETD9S_fetd9sel(x)              (((uint32_t)(((uint32_t)(x)) << fetchd9c_FETD9S_fetd9sel_SHIFT)) & fetchd9c_FETD9S_fetd9sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchd9c_Register_Masks */


/*!
 * @}
 */ /* end of group fetchd9c_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHD9C_H_ */

