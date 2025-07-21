/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ANADIG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ANADIG.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ANADIG
 *
 * CMSIS Peripheral Access Layer for ANADIG
 */

#if !defined(PERI_ANADIG_H_)
#define PERI_ANADIG_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- ANADIG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_Peripheral_Access_Layer ANADIG Peripheral Access Layer
 * @{
 */

/** ANADIG - Size of Registers Arrays */
#define ANADIG_SLOT_CTRL_COUNT                    35u

/** ANADIG - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[19456];
  __IO uint32_t SLOT_CTRL[ANADIG_SLOT_CTRL_COUNT]; /**< Slot Control Register, array offset: 0x4C00, array step: 0x4 */
} ANADIG_Type;

/* ----------------------------------------------------------------------------
   -- ANADIG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_Register_Masks ANADIG Register Masks
 * @{
 */

/*! @name SLOT_CTRL - Slot Control Register */
/*! @{ */

#define ANADIG_SLOT_CTRL_LOCKED_DOMAIN_ID_MASK   (0xFU)
#define ANADIG_SLOT_CTRL_LOCKED_DOMAIN_ID_SHIFT  (0U)
/*! LOCKED_DOMAIN_ID - Domain ID of the slot to be locked */
#define ANADIG_SLOT_CTRL_LOCKED_DOMAIN_ID(x)     (((uint32_t)(((uint32_t)(x)) << ANADIG_SLOT_CTRL_LOCKED_DOMAIN_ID_SHIFT)) & ANADIG_SLOT_CTRL_LOCKED_DOMAIN_ID_MASK)

#define ANADIG_SLOT_CTRL_DOMAIN_LOCK_MASK        (0x8000U)
#define ANADIG_SLOT_CTRL_DOMAIN_LOCK_SHIFT       (15U)
/*! DOMAIN_LOCK - Lock domain ID of this slot
 *  0b0..Do not lock the domain ID
 *  0b1..Lock the domain ID
 */
#define ANADIG_SLOT_CTRL_DOMAIN_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << ANADIG_SLOT_CTRL_DOMAIN_LOCK_SHIFT)) & ANADIG_SLOT_CTRL_DOMAIN_LOCK_MASK)

#define ANADIG_SLOT_CTRL_ALLOW_NONSECURE_MASK    (0x10000U)
#define ANADIG_SLOT_CTRL_ALLOW_NONSECURE_SHIFT   (16U)
/*! ALLOW_NONSECURE - Allow non-secure write access to this domain control register or domain register
 *  0b0..Do not allow non-secure write access
 *  0b1..Allow non-secure write access
 */
#define ANADIG_SLOT_CTRL_ALLOW_NONSECURE(x)      (((uint32_t)(((uint32_t)(x)) << ANADIG_SLOT_CTRL_ALLOW_NONSECURE_SHIFT)) & ANADIG_SLOT_CTRL_ALLOW_NONSECURE_MASK)

#define ANADIG_SLOT_CTRL_ALLOW_USER_MASK         (0x20000U)
#define ANADIG_SLOT_CTRL_ALLOW_USER_SHIFT        (17U)
/*! ALLOW_USER - Allow user write access to this domain control register or domain register
 *  0b0..Do not allow user write access
 *  0b1..Allow user write access
 */
#define ANADIG_SLOT_CTRL_ALLOW_USER(x)           (((uint32_t)(((uint32_t)(x)) << ANADIG_SLOT_CTRL_ALLOW_USER_SHIFT)) & ANADIG_SLOT_CTRL_ALLOW_USER_MASK)

#define ANADIG_SLOT_CTRL_LOCK_CONTROL_MASK       (0x80000000U)
#define ANADIG_SLOT_CTRL_LOCK_CONTROL_SHIFT      (31U)
/*! LOCK_CONTROL - Lock control of this slot
 *  0b0..Do not lock the control register of this slot
 *  0b1..Lock the control register of this slot
 */
#define ANADIG_SLOT_CTRL_LOCK_CONTROL(x)         (((uint32_t)(((uint32_t)(x)) << ANADIG_SLOT_CTRL_LOCK_CONTROL_SHIFT)) & ANADIG_SLOT_CTRL_LOCK_CONTROL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANADIG_Register_Masks */


/*!
 * @}
 */ /* end of group ANADIG_Peripheral_Access_Layer */


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


#endif  /* PERI_ANADIG_H_ */

