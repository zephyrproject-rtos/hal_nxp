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
**         CMSIS Peripheral Access Layer for constf4c
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
 * @file PERI_constf4c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for constf4c
 *
 * CMSIS Peripheral Access Layer for constf4c
 */

#if !defined(PERI_CONSTF4C_H_)
#define PERI_CONSTF4C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- constf4c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf4c_Peripheral_Access_Layer constf4c Peripheral Access Layer
 * @{
 */

/** constf4c - Register Layout Typedef */
typedef struct {
  __O  uint32_t CONSF4LU;                          /**< constframe4_LockUnlock, offset: 0x0 */
  __I  uint32_t CONSF4LS;                          /**< constframe4_LockStatus, offset: 0x4 */
  __I  uint32_t CONSF4S;                           /**< constframe4_Status, offset: 0x8 */
} constf4c_Type;

/* ----------------------------------------------------------------------------
   -- constf4c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf4c_Register_Masks constf4c Register Masks
 * @{
 */

/*! @name CONSF4LU - constframe4_LockUnlock */
/*! @{ */

#define constf4c_CONSF4LU_consf4LU_MASK          (0xFFFFFFFFU)
#define constf4c_CONSF4LU_consf4LU_SHIFT         (0U)
/*! consf4LU - constframe4_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define constf4c_CONSF4LU_consf4LU(x)            (((uint32_t)(((uint32_t)(x)) << constf4c_CONSF4LU_consf4LU_SHIFT)) & constf4c_CONSF4LU_consf4LU_MASK)
/*! @} */

/*! @name CONSF4LS - constframe4_LockStatus */
/*! @{ */

#define constf4c_CONSF4LS_consf4LS_MASK          (0x1U)
#define constf4c_CONSF4LS_consf4LS_SHIFT         (0U)
/*! consf4LS - constframe4_LockStatus */
#define constf4c_CONSF4LS_consf4LS(x)            (((uint32_t)(((uint32_t)(x)) << constf4c_CONSF4LS_consf4LS_SHIFT)) & constf4c_CONSF4LS_consf4LS_MASK)

#define constf4c_CONSF4LS_consf4PS_MASK          (0x10U)
#define constf4c_CONSF4LS_consf4PS_SHIFT         (4U)
/*! consf4PS - constframe4_PrivilegeStatus */
#define constf4c_CONSF4LS_consf4PS(x)            (((uint32_t)(((uint32_t)(x)) << constf4c_CONSF4LS_consf4PS_SHIFT)) & constf4c_CONSF4LS_consf4PS_MASK)

#define constf4c_CONSF4LS_consf4FS_MASK          (0x100U)
#define constf4c_CONSF4LS_consf4FS_SHIFT         (8U)
/*! consf4FS - constframe4_FreezeStatus */
#define constf4c_CONSF4LS_consf4FS(x)            (((uint32_t)(((uint32_t)(x)) << constf4c_CONSF4LS_consf4FS_SHIFT)) & constf4c_CONSF4LS_consf4FS_MASK)
/*! @} */

/*! @name CONSF4S - constframe4_Status */
/*! @{ */

#define constf4c_CONSF4S_consf4se_MASK           (0x70000U)
#define constf4c_CONSF4S_consf4se_SHIFT          (16U)
/*! consf4se - constframe4_sel
 *  0b000..constframe4 module is not used
 *  0b001..constframe4 module is used from store9 processing path
 *  0b010..constframe4 module is used from extdst0 processing path
 *  0b011..constframe4 module is used from extdst4 processing path
 *  0b100..constframe4 module is used from extdst1 processing path
 *  0b101..constframe4 module is used from extdst5 processing path
 */
#define constf4c_CONSF4S_consf4se(x)             (((uint32_t)(((uint32_t)(x)) << constf4c_CONSF4S_consf4se_SHIFT)) & constf4c_CONSF4S_consf4se_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group constf4c_Register_Masks */


/*!
 * @}
 */ /* end of group constf4c_Peripheral_Access_Layer */


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


#endif  /* PERI_CONSTF4C_H_ */

