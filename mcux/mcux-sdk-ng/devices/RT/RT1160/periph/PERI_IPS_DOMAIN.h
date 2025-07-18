/*
** ###################################################################
**     Processors:          MIMXRT1165CVM5A_cm4
**                          MIMXRT1165CVM5A_cm7
**                          MIMXRT1165DVM6A_cm4
**                          MIMXRT1165DVM6A_cm7
**                          MIMXRT1165XVM5A_cm4
**                          MIMXRT1165XVM5A_cm7
**                          MIMXRT1166CVM5A_cm4
**                          MIMXRT1166CVM5A_cm7
**                          MIMXRT1166DVM6A_cm4
**                          MIMXRT1166DVM6A_cm7
**                          MIMXRT1166XVM5A_cm4
**                          MIMXRT1166XVM5A_cm7
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IPS_DOMAIN
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-29)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IPS_DOMAIN.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IPS_DOMAIN
 *
 * CMSIS Peripheral Access Layer for IPS_DOMAIN
 */

#if !defined(PERI_IPS_DOMAIN_H_)
#define PERI_IPS_DOMAIN_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1165CVM5A_cm4) || defined(CPU_MIMXRT1165DVM6A_cm4) || defined(CPU_MIMXRT1165XVM5A_cm4))
#include "MIMXRT1165_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1165CVM5A_cm7) || defined(CPU_MIMXRT1165DVM6A_cm7) || defined(CPU_MIMXRT1165XVM5A_cm7))
#include "MIMXRT1165_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm4) || defined(CPU_MIMXRT1166DVM6A_cm4) || defined(CPU_MIMXRT1166XVM5A_cm4))
#include "MIMXRT1166_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm7) || defined(CPU_MIMXRT1166DVM6A_cm7) || defined(CPU_MIMXRT1166XVM5A_cm7))
#include "MIMXRT1166_cm7_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- IPS_DOMAIN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IPS_DOMAIN_Peripheral_Access_Layer IPS_DOMAIN Peripheral Access Layer
 * @{
 */

/** IPS_DOMAIN - Size of Registers Arrays */
#define IPS_DOMAIN_SLOT_CTRL_COUNT                38u

/** IPS_DOMAIN - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10 */
    __IO uint32_t SLOT_CTRL;                         /**< Slot Control Register, array offset: 0x0, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } SLOT_CTRL[IPS_DOMAIN_SLOT_CTRL_COUNT];
} IPS_DOMAIN_Type;

/* ----------------------------------------------------------------------------
   -- IPS_DOMAIN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IPS_DOMAIN_Register_Masks IPS_DOMAIN Register Masks
 * @{
 */

/*! @name SLOT_CTRL - Slot Control Register */
/*! @{ */

#define IPS_DOMAIN_SLOT_CTRL_LOCKED_DOMAIN_ID_MASK (0xFU)
#define IPS_DOMAIN_SLOT_CTRL_LOCKED_DOMAIN_ID_SHIFT (0U)
/*! LOCKED_DOMAIN_ID - Domain ID of the slot to be locked */
#define IPS_DOMAIN_SLOT_CTRL_LOCKED_DOMAIN_ID(x) (((uint32_t)(((uint32_t)(x)) << IPS_DOMAIN_SLOT_CTRL_LOCKED_DOMAIN_ID_SHIFT)) & IPS_DOMAIN_SLOT_CTRL_LOCKED_DOMAIN_ID_MASK)

#define IPS_DOMAIN_SLOT_CTRL_DOMAIN_LOCK_MASK    (0x8000U)
#define IPS_DOMAIN_SLOT_CTRL_DOMAIN_LOCK_SHIFT   (15U)
/*! DOMAIN_LOCK - Lock domain ID of this slot
 *  0b0..Do not lock the domain ID
 *  0b1..Lock the domain ID
 */
#define IPS_DOMAIN_SLOT_CTRL_DOMAIN_LOCK(x)      (((uint32_t)(((uint32_t)(x)) << IPS_DOMAIN_SLOT_CTRL_DOMAIN_LOCK_SHIFT)) & IPS_DOMAIN_SLOT_CTRL_DOMAIN_LOCK_MASK)

#define IPS_DOMAIN_SLOT_CTRL_ALLOW_NONSECURE_MASK (0x10000U)
#define IPS_DOMAIN_SLOT_CTRL_ALLOW_NONSECURE_SHIFT (16U)
/*! ALLOW_NONSECURE - Allow non-secure write access to this domain control register or domain register
 *  0b0..Do not allow non-secure write access
 *  0b1..Allow non-secure write access
 */
#define IPS_DOMAIN_SLOT_CTRL_ALLOW_NONSECURE(x)  (((uint32_t)(((uint32_t)(x)) << IPS_DOMAIN_SLOT_CTRL_ALLOW_NONSECURE_SHIFT)) & IPS_DOMAIN_SLOT_CTRL_ALLOW_NONSECURE_MASK)

#define IPS_DOMAIN_SLOT_CTRL_ALLOW_USER_MASK     (0x20000U)
#define IPS_DOMAIN_SLOT_CTRL_ALLOW_USER_SHIFT    (17U)
/*! ALLOW_USER - Allow user write access to this domain control register or domain register
 *  0b0..Do not allow user write access
 *  0b1..Allow user write access
 */
#define IPS_DOMAIN_SLOT_CTRL_ALLOW_USER(x)       (((uint32_t)(((uint32_t)(x)) << IPS_DOMAIN_SLOT_CTRL_ALLOW_USER_SHIFT)) & IPS_DOMAIN_SLOT_CTRL_ALLOW_USER_MASK)

#define IPS_DOMAIN_SLOT_CTRL_LOCK_CONTROL_MASK   (0x80000000U)
#define IPS_DOMAIN_SLOT_CTRL_LOCK_CONTROL_SHIFT  (31U)
/*! LOCK_CONTROL - Lock control of this slot
 *  0b0..Do not lock the control register of this slot
 *  0b1..Lock the control register of this slot
 */
#define IPS_DOMAIN_SLOT_CTRL_LOCK_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << IPS_DOMAIN_SLOT_CTRL_LOCK_CONTROL_SHIFT)) & IPS_DOMAIN_SLOT_CTRL_LOCK_CONTROL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IPS_DOMAIN_Register_Masks */


/*!
 * @}
 */ /* end of group IPS_DOMAIN_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_IPS_DOMAIN_H_ */

