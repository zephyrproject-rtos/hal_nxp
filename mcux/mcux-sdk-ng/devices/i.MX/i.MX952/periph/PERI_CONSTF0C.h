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
**         CMSIS Peripheral Access Layer for constf0c
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
 * @file PERI_constf0c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for constf0c
 *
 * CMSIS Peripheral Access Layer for constf0c
 */

#if !defined(PERI_CONSTF0C_H_)
#define PERI_CONSTF0C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- constf0c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf0c_Peripheral_Access_Layer constf0c Peripheral Access Layer
 * @{
 */

/** constf0c - Register Layout Typedef */
typedef struct {
  __O  uint32_t CONSF0LU;                          /**< constframe0_LockUnlock, offset: 0x0 */
  __I  uint32_t CONSF0LS;                          /**< constframe0_LockStatus, offset: 0x4 */
  __I  uint32_t CONSF0S;                           /**< constframe0_Status, offset: 0x8 */
} constf0c_Type;

/* ----------------------------------------------------------------------------
   -- constf0c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf0c_Register_Masks constf0c Register Masks
 * @{
 */

/*! @name CONSF0LU - constframe0_LockUnlock */
/*! @{ */

#define constf0c_CONSF0LU_consf0LU_MASK          (0xFFFFFFFFU)
#define constf0c_CONSF0LU_consf0LU_SHIFT         (0U)
/*! consf0LU - constframe0_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define constf0c_CONSF0LU_consf0LU(x)            (((uint32_t)(((uint32_t)(x)) << constf0c_CONSF0LU_consf0LU_SHIFT)) & constf0c_CONSF0LU_consf0LU_MASK)
/*! @} */

/*! @name CONSF0LS - constframe0_LockStatus */
/*! @{ */

#define constf0c_CONSF0LS_consf0LS_MASK          (0x1U)
#define constf0c_CONSF0LS_consf0LS_SHIFT         (0U)
/*! consf0LS - constframe0_LockStatus */
#define constf0c_CONSF0LS_consf0LS(x)            (((uint32_t)(((uint32_t)(x)) << constf0c_CONSF0LS_consf0LS_SHIFT)) & constf0c_CONSF0LS_consf0LS_MASK)

#define constf0c_CONSF0LS_consf0PS_MASK          (0x10U)
#define constf0c_CONSF0LS_consf0PS_SHIFT         (4U)
/*! consf0PS - constframe0_PrivilegeStatus */
#define constf0c_CONSF0LS_consf0PS(x)            (((uint32_t)(((uint32_t)(x)) << constf0c_CONSF0LS_consf0PS_SHIFT)) & constf0c_CONSF0LS_consf0PS_MASK)

#define constf0c_CONSF0LS_consf0FS_MASK          (0x100U)
#define constf0c_CONSF0LS_consf0FS_SHIFT         (8U)
/*! consf0FS - constframe0_FreezeStatus */
#define constf0c_CONSF0LS_consf0FS(x)            (((uint32_t)(((uint32_t)(x)) << constf0c_CONSF0LS_consf0FS_SHIFT)) & constf0c_CONSF0LS_consf0FS_MASK)
/*! @} */

/*! @name CONSF0S - constframe0_Status */
/*! @{ */

#define constf0c_CONSF0S_consf0se_MASK           (0x70000U)
#define constf0c_CONSF0S_consf0se_SHIFT          (16U)
/*! consf0se - constframe0_sel
 *  0b000..constframe0 module is not used
 *  0b001..constframe0 module is used from store9 processing path
 *  0b010..constframe0 module is used from extdst0 processing path
 *  0b011..constframe0 module is used from extdst4 processing path
 *  0b100..constframe0 module is used from extdst1 processing path
 *  0b101..constframe0 module is used from extdst5 processing path
 */
#define constf0c_CONSF0S_consf0se(x)             (((uint32_t)(((uint32_t)(x)) << constf0c_CONSF0S_consf0se_SHIFT)) & constf0c_CONSF0S_consf0se_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group constf0c_Register_Masks */


/*!
 * @}
 */ /* end of group constf0c_Peripheral_Access_Layer */


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


#endif  /* PERI_CONSTF0C_H_ */

