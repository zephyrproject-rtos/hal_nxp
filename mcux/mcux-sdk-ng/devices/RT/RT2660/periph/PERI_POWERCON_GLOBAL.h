/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for POWERCON_GLOBAL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_POWERCON_GLOBAL.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for POWERCON_GLOBAL
 *
 * CMSIS Peripheral Access Layer for POWERCON_GLOBAL
 */

#if !defined(PERI_POWERCON_GLOBAL_H_)
#define PERI_POWERCON_GLOBAL_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- POWERCON_GLOBAL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POWERCON_GLOBAL_Peripheral_Access_Layer POWERCON_GLOBAL Peripheral Access Layer
 * @{
 */

/** POWERCON_GLOBAL - Register Layout Typedef */
typedef struct {
  __IO uint32_t ACCESS_CTRL;                       /**< Global Access Control, offset: 0x0 */
  __IO uint32_t POWERCON_GLOBAL_CTRL;              /**< Global Control, offset: 0x4 */
} POWERCON_GLOBAL_Type;

/* ----------------------------------------------------------------------------
   -- POWERCON_GLOBAL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POWERCON_GLOBAL_Register_Masks POWERCON_GLOBAL Register Masks
 * @{
 */

/*! @name ACCESS_CTRL - Global Access Control */
/*! @{ */

#define POWERCON_GLOBAL_ACCESS_CTRL_ALLOW_ACCESS_MASK (0xFU)
#define POWERCON_GLOBAL_ACCESS_CTRL_ALLOW_ACCESS_SHIFT (0U)
/*! ALLOW_ACCESS - Configuration Lock */
#define POWERCON_GLOBAL_ACCESS_CTRL_ALLOW_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_GLOBAL_ACCESS_CTRL_ALLOW_ACCESS_SHIFT)) & POWERCON_GLOBAL_ACCESS_CTRL_ALLOW_ACCESS_MASK)

#define POWERCON_GLOBAL_ACCESS_CTRL_USER_MASK    (0x10000U)
#define POWERCON_GLOBAL_ACCESS_CTRL_USER_SHIFT   (16U)
/*! USER - User Mode Access
 *  0b0..Disables
 *  0b1..Enables
 */
#define POWERCON_GLOBAL_ACCESS_CTRL_USER(x)      (((uint32_t)(((uint32_t)(x)) << POWERCON_GLOBAL_ACCESS_CTRL_USER_SHIFT)) & POWERCON_GLOBAL_ACCESS_CTRL_USER_MASK)

#define POWERCON_GLOBAL_ACCESS_CTRL_NONSECURE_MASK (0x20000U)
#define POWERCON_GLOBAL_ACCESS_CTRL_NONSECURE_SHIFT (17U)
/*! NONSECURE - Non-Secure Mode Access
 *  0b0..Disables
 *  0b1..Enables
 */
#define POWERCON_GLOBAL_ACCESS_CTRL_NONSECURE(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_GLOBAL_ACCESS_CTRL_NONSECURE_SHIFT)) & POWERCON_GLOBAL_ACCESS_CTRL_NONSECURE_MASK)

#define POWERCON_GLOBAL_ACCESS_CTRL_LOCK_MASK    (0x80000000U)
#define POWERCON_GLOBAL_ACCESS_CTRL_LOCK_SHIFT   (31U)
/*! LOCK - White List Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define POWERCON_GLOBAL_ACCESS_CTRL_LOCK(x)      (((uint32_t)(((uint32_t)(x)) << POWERCON_GLOBAL_ACCESS_CTRL_LOCK_SHIFT)) & POWERCON_GLOBAL_ACCESS_CTRL_LOCK_MASK)
/*! @} */

/*! @name POWERCON_GLOBAL_CTRL - Global Control */
/*! @{ */

#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_FCLK_OFF_MASK (0x1U)
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_FCLK_OFF_SHIFT (0U)
/*! FCLK_OFF - System Free-Running Clock Off
 *  0b0..Enables clock gating after low-power entry is done
 *  0b1..Disables clock gating after low-power entry is done
 */
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_FCLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_FCLK_OFF_SHIFT)) & POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_FCLK_OFF_MASK)

#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK0_MASK (0x2U)
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK0_SHIFT (1U)
/*! XMC_STBY_MASK0 - CMC and DMC Standby Mask 0
 *  0b0..Enables Standby entry
 *  0b1..Disables Standby entry
 */
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK0(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK0_SHIFT)) & POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK0_MASK)

#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK1_MASK (0x4U)
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK1_SHIFT (2U)
/*! XMC_STBY_MASK1 - CMC and DMC Standby Mask 1
 *  0b0..Enables Standby entry
 *  0b1..Disables Standby entry
 */
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK1(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK1_SHIFT)) & POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK1_MASK)

#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK2_MASK (0x8U)
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK2_SHIFT (3U)
/*! XMC_STBY_MASK2 - CMC and DMC Standby Mask 2
 *  0b0..Enables Standby entry
 *  0b1..Disables Standby entry
 */
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK2(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK2_SHIFT)) & POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK2_MASK)

#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_OBS_CTRL_MASK (0x300U)
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_OBS_CTRL_SHIFT (8U)
/*! OBS_CTRL - Observation Control
 *  0b00..CMC0
 *  0b01..DMC0 (CMC1)
 *  0b10..DMC1 (CMC2)
 *  0b11..
 */
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_OBS_CTRL(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_OBS_CTRL_SHIFT)) & POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_OBS_CTRL_MASK)

#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_DBGWK_SWITCH_MASK (0x10000U)
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_DBGWK_SWITCH_SHIFT (16U)
/*! DBGWK_SWITCH - Debug Wake-Up Switch
 *  0b0..Style 0
 *  0b1..Style 1
 */
#define POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_DBGWK_SWITCH(x) (((uint32_t)(((uint32_t)(x)) << POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_DBGWK_SWITCH_SHIFT)) & POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_DBGWK_SWITCH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group POWERCON_GLOBAL_Register_Masks */


/*!
 * @}
 */ /* end of group POWERCON_GLOBAL_Peripheral_Access_Layer */


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


#endif  /* PERI_POWERCON_GLOBAL_H_ */

