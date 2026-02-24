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
**         CMSIS Peripheral Access Layer for fetchl1c
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
 * @file PERI_fetchl1c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchl1c
 *
 * CMSIS Peripheral Access Layer for fetchl1c
 */

#if !defined(PERI_FETCHL1C_H_)
#define PERI_FETCHL1C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchl1c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl1c_Peripheral_Access_Layer fetchl1c Peripheral Access Layer
 * @{
 */

/** fetchl1c - Register Layout Typedef */
typedef struct {
  __O  uint32_t FETLA1LU;                          /**< fetchlayer1_LockUnlock, offset: 0x0 */
  __I  uint32_t FETLA1LS;                          /**< fetchlayer1_LockStatus, offset: 0x4 */
  __I  uint32_t FETLA1S;                           /**< fetchlayer1_Status, offset: 0x8 */
} fetchl1c_Type;

/* ----------------------------------------------------------------------------
   -- fetchl1c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl1c_Register_Masks fetchl1c Register Masks
 * @{
 */

/*! @name FETLA1LU - fetchlayer1_LockUnlock */
/*! @{ */

#define fetchl1c_FETLA1LU_fetlayLU_MASK          (0xFFFFFFFFU)
#define fetchl1c_FETLA1LU_fetlayLU_SHIFT         (0U)
/*! fetlayLU - fetchlayer1_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define fetchl1c_FETLA1LU_fetlayLU(x)            (((uint32_t)(((uint32_t)(x)) << fetchl1c_FETLA1LU_fetlayLU_SHIFT)) & fetchl1c_FETLA1LU_fetlayLU_MASK)
/*! @} */

/*! @name FETLA1LS - fetchlayer1_LockStatus */
/*! @{ */

#define fetchl1c_FETLA1LS_fetlayLS_MASK          (0x1U)
#define fetchl1c_FETLA1LS_fetlayLS_SHIFT         (0U)
/*! fetlayLS - fetchlayer1_LockStatus */
#define fetchl1c_FETLA1LS_fetlayLS(x)            (((uint32_t)(((uint32_t)(x)) << fetchl1c_FETLA1LS_fetlayLS_SHIFT)) & fetchl1c_FETLA1LS_fetlayLS_MASK)

#define fetchl1c_FETLA1LS_fetlayPS_MASK          (0x10U)
#define fetchl1c_FETLA1LS_fetlayPS_SHIFT         (4U)
/*! fetlayPS - fetchlayer1_PrivilegeStatus */
#define fetchl1c_FETLA1LS_fetlayPS(x)            (((uint32_t)(((uint32_t)(x)) << fetchl1c_FETLA1LS_fetlayPS_SHIFT)) & fetchl1c_FETLA1LS_fetlayPS_MASK)

#define fetchl1c_FETLA1LS_fetlayFS_MASK          (0x100U)
#define fetchl1c_FETLA1LS_fetlayFS_SHIFT         (8U)
/*! fetlayFS - fetchlayer1_FreezeStatus */
#define fetchl1c_FETLA1LS_fetlayFS(x)            (((uint32_t)(((uint32_t)(x)) << fetchl1c_FETLA1LS_fetlayFS_SHIFT)) & fetchl1c_FETLA1LS_fetlayFS_MASK)
/*! @} */

/*! @name FETLA1S - fetchlayer1_Status */
/*! @{ */

#define fetchl1c_FETLA1S_fetlaysl_MASK           (0x70000U)
#define fetchl1c_FETLA1S_fetlaysl_SHIFT          (16U)
/*! fetlaysl - fetchlayer1_sel
 *  0b000..fetchlayer1 module is not used
 *  0b001..fetchlayer1 module is used from store9 processing path
 *  0b010..fetchlayer1 module is used from extdst0 processing path
 *  0b011..fetchlayer1 module is used from extdst4 processing path
 *  0b100..fetchlayer1 module is used from extdst1 processing path
 *  0b101..fetchlayer1 module is used from extdst5 processing path
 */
#define fetchl1c_FETLA1S_fetlaysl(x)             (((uint32_t)(((uint32_t)(x)) << fetchl1c_FETLA1S_fetlaysl_SHIFT)) & fetchl1c_FETLA1S_fetlaysl_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchl1c_Register_Masks */


/*!
 * @}
 */ /* end of group fetchl1c_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHL1C_H_ */

