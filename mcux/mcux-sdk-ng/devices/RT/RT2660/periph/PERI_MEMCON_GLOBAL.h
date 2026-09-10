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
**         CMSIS Peripheral Access Layer for MEMCON_GLOBAL
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
 * @file PERI_MEMCON_GLOBAL.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for MEMCON_GLOBAL
 *
 * CMSIS Peripheral Access Layer for MEMCON_GLOBAL
 */

#if !defined(PERI_MEMCON_GLOBAL_H_)
#define PERI_MEMCON_GLOBAL_H_                    /**< Symbol preventing repeated inclusion */

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
   -- MEMCON_GLOBAL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEMCON_GLOBAL_Peripheral_Access_Layer MEMCON_GLOBAL Peripheral Access Layer
 * @{
 */

/** MEMCON_GLOBAL - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __IO uint32_t ACCCTRL;                           /**< Access Control, offset: 0x4 */
  __IO uint32_t FCEN;                              /**< FCLK EN, offset: 0x8 */
} MEMCON_GLOBAL_Type;

/* ----------------------------------------------------------------------------
   -- MEMCON_GLOBAL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEMCON_GLOBAL_Register_Masks MEMCON_GLOBAL Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define MEMCON_GLOBAL_VERID_VERSION_MASK         (0xFFFFFFFFU)
#define MEMCON_GLOBAL_VERID_VERSION_SHIFT        (0U)
/*! VERSION - Version ID */
#define MEMCON_GLOBAL_VERID_VERSION(x)           (((uint32_t)(((uint32_t)(x)) << MEMCON_GLOBAL_VERID_VERSION_SHIFT)) & MEMCON_GLOBAL_VERID_VERSION_MASK)
/*! @} */

/*! @name ACCCTRL - Access Control */
/*! @{ */

#define MEMCON_GLOBAL_ACCCTRL_DID_MASK           (0xFFFFU)
#define MEMCON_GLOBAL_ACCCTRL_DID_SHIFT          (0U)
/*! DID - Domain ID
 *  0b0xxxxxxxxxxxxxxx..Disables access for Domain ID 15
 *  0b1xxxxxxxxxxxxxxx..Enables access for Domain ID 15
 *  0bx0xxxxxxxxxxxxxx..Disables access for Domain ID 14
 *  0bx1xxxxxxxxxxxxxx..Enables access for Domain ID 14
 *  0bxx0xxxxxxxxxxxxx.....
 *  0bxxxxxxxxxxxxxx0x..Disables access for Domain ID 1
 *  0bxxxxxxxxxxxxxx1x..Enables access for Domain ID 1
 *  0bxxxxxxxxxxxxxxx0..Disables access for Domain ID 0
 *  0bxxxxxxxxxxxxxxx1..Enables access for Domain ID 0
 */
#define MEMCON_GLOBAL_ACCCTRL_DID(x)             (((uint32_t)(((uint32_t)(x)) << MEMCON_GLOBAL_ACCCTRL_DID_SHIFT)) & MEMCON_GLOBAL_ACCCTRL_DID_MASK)

#define MEMCON_GLOBAL_ACCCTRL_UM_MASK            (0x10000U)
#define MEMCON_GLOBAL_ACCCTRL_UM_SHIFT           (16U)
/*! UM - User Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define MEMCON_GLOBAL_ACCCTRL_UM(x)              (((uint32_t)(((uint32_t)(x)) << MEMCON_GLOBAL_ACCCTRL_UM_SHIFT)) & MEMCON_GLOBAL_ACCCTRL_UM_MASK)

#define MEMCON_GLOBAL_ACCCTRL_NSM_MASK           (0x20000U)
#define MEMCON_GLOBAL_ACCCTRL_NSM_SHIFT          (17U)
/*! NSM - Non-Secure Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define MEMCON_GLOBAL_ACCCTRL_NSM(x)             (((uint32_t)(((uint32_t)(x)) << MEMCON_GLOBAL_ACCCTRL_NSM_SHIFT)) & MEMCON_GLOBAL_ACCCTRL_NSM_MASK)

#define MEMCON_GLOBAL_ACCCTRL_LOCK_MASK          (0x80000000U)
#define MEMCON_GLOBAL_ACCCTRL_LOCK_SHIFT         (31U)
/*! LOCK - Access Control Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define MEMCON_GLOBAL_ACCCTRL_LOCK(x)            (((uint32_t)(((uint32_t)(x)) << MEMCON_GLOBAL_ACCCTRL_LOCK_SHIFT)) & MEMCON_GLOBAL_ACCCTRL_LOCK_MASK)
/*! @} */

/*! @name FCEN - FCLK EN */
/*! @{ */

#define MEMCON_GLOBAL_FCEN_FCEN_MASK             (0x1U)
#define MEMCON_GLOBAL_FCEN_FCEN_SHIFT            (0U)
/*! FCEN - FCLK EN
 *  0b0..Disable Function clock gate cell. SW could only configure it to DISABLE when no active work in PDCON and MEMCON.
 *  0b1..Enable Function clock gate cell. Warm reset will set it to ENABLE.
 */
#define MEMCON_GLOBAL_FCEN_FCEN(x)               (((uint32_t)(((uint32_t)(x)) << MEMCON_GLOBAL_FCEN_FCEN_SHIFT)) & MEMCON_GLOBAL_FCEN_FCEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MEMCON_GLOBAL_Register_Masks */


/*!
 * @}
 */ /* end of group MEMCON_GLOBAL_Peripheral_Access_Layer */


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


#endif  /* PERI_MEMCON_GLOBAL_H_ */

