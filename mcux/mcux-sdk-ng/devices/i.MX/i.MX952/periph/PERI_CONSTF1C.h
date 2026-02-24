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
**         CMSIS Peripheral Access Layer for constf1c
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
 * @file PERI_constf1c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for constf1c
 *
 * CMSIS Peripheral Access Layer for constf1c
 */

#if !defined(PERI_CONSTF1C_H_)
#define PERI_CONSTF1C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- constf1c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf1c_Peripheral_Access_Layer constf1c Peripheral Access Layer
 * @{
 */

/** constf1c - Register Layout Typedef */
typedef struct {
  __O  uint32_t CONSF1LU;                          /**< constframe1_LockUnlock, offset: 0x0 */
  __I  uint32_t CONSF1LS;                          /**< constframe1_LockStatus, offset: 0x4 */
  __I  uint32_t CONSF1S;                           /**< constframe1_Status, offset: 0x8 */
} constf1c_Type;

/* ----------------------------------------------------------------------------
   -- constf1c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup constf1c_Register_Masks constf1c Register Masks
 * @{
 */

/*! @name CONSF1LU - constframe1_LockUnlock */
/*! @{ */

#define constf1c_CONSF1LU_consf1LU_MASK          (0xFFFFFFFFU)
#define constf1c_CONSF1LU_consf1LU_SHIFT         (0U)
/*! consf1LU - constframe1_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define constf1c_CONSF1LU_consf1LU(x)            (((uint32_t)(((uint32_t)(x)) << constf1c_CONSF1LU_consf1LU_SHIFT)) & constf1c_CONSF1LU_consf1LU_MASK)
/*! @} */

/*! @name CONSF1LS - constframe1_LockStatus */
/*! @{ */

#define constf1c_CONSF1LS_consf1LS_MASK          (0x1U)
#define constf1c_CONSF1LS_consf1LS_SHIFT         (0U)
/*! consf1LS - constframe1_LockStatus */
#define constf1c_CONSF1LS_consf1LS(x)            (((uint32_t)(((uint32_t)(x)) << constf1c_CONSF1LS_consf1LS_SHIFT)) & constf1c_CONSF1LS_consf1LS_MASK)

#define constf1c_CONSF1LS_consf1PS_MASK          (0x10U)
#define constf1c_CONSF1LS_consf1PS_SHIFT         (4U)
/*! consf1PS - constframe1_PrivilegeStatus */
#define constf1c_CONSF1LS_consf1PS(x)            (((uint32_t)(((uint32_t)(x)) << constf1c_CONSF1LS_consf1PS_SHIFT)) & constf1c_CONSF1LS_consf1PS_MASK)

#define constf1c_CONSF1LS_consf1FS_MASK          (0x100U)
#define constf1c_CONSF1LS_consf1FS_SHIFT         (8U)
/*! consf1FS - constframe1_FreezeStatus */
#define constf1c_CONSF1LS_consf1FS(x)            (((uint32_t)(((uint32_t)(x)) << constf1c_CONSF1LS_consf1FS_SHIFT)) & constf1c_CONSF1LS_consf1FS_MASK)
/*! @} */

/*! @name CONSF1S - constframe1_Status */
/*! @{ */

#define constf1c_CONSF1S_consf1se_MASK           (0x70000U)
#define constf1c_CONSF1S_consf1se_SHIFT          (16U)
/*! consf1se - constframe1_sel
 *  0b000..constframe1 module is not used
 *  0b001..constframe1 module is used from store9 processing path
 *  0b010..constframe1 module is used from extdst0 processing path
 *  0b011..constframe1 module is used from extdst4 processing path
 *  0b100..constframe1 module is used from extdst1 processing path
 *  0b101..constframe1 module is used from extdst5 processing path
 */
#define constf1c_CONSF1S_consf1se(x)             (((uint32_t)(((uint32_t)(x)) << constf1c_CONSF1S_consf1se_SHIFT)) & constf1c_CONSF1S_consf1se_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group constf1c_Register_Masks */


/*!
 * @}
 */ /* end of group constf1c_Peripheral_Access_Layer */


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


#endif  /* PERI_CONSTF1C_H_ */

