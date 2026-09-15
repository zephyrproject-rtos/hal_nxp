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
**         CMSIS Peripheral Access Layer for MEMCON_SLICE
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
 * @file PERI_MEMCON_SLICE.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for MEMCON_SLICE
 *
 * CMSIS Peripheral Access Layer for MEMCON_SLICE
 */

#if !defined(PERI_MEMCON_SLICE_H_)
#define PERI_MEMCON_SLICE_H_                     /**< Symbol preventing repeated inclusion */

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
   -- MEMCON_SLICE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEMCON_SLICE_Peripheral_Access_Layer MEMCON_SLICE Peripheral Access Layer
 * @{
 */

/** MEMCON_SLICE - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __IO uint32_t ACCCTRL;                           /**< Access Control, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t MDCTRL;                            /**< Mode Control, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t MEM_SLPCFG0;                       /**< Memory Power Control Under Low-Power 0, offset: 0x20 */
  __IO uint32_t MEM_SLPCFG1;                       /**< Memory Power Control Under Low-Power 1, offset: 0x24, not available in all instances (available on 30 out of 360) */
       uint8_t RESERVED_2[24];
  __IO uint32_t MEM_RUNCFG0;                       /**< Memory Power Control Under Active 0, offset: 0x40 */
  __IO uint32_t MEM_RUNCFG1;                       /**< Memory Power Control Under Active 1, offset: 0x44, not available in all instances (available on 30 out of 360) */
} MEMCON_SLICE_Type;

/* ----------------------------------------------------------------------------
   -- MEMCON_SLICE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEMCON_SLICE_Register_Masks MEMCON_SLICE Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define MEMCON_SLICE_VERID_VERSION_MASK          (0xFFFFFFFFU)
#define MEMCON_SLICE_VERID_VERSION_SHIFT         (0U)
/*! VERSION - Version ID */
#define MEMCON_SLICE_VERID_VERSION(x)            (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_VERID_VERSION_SHIFT)) & MEMCON_SLICE_VERID_VERSION_MASK)
/*! @} */

/*! @name ACCCTRL - Access Control */
/*! @{ */

#define MEMCON_SLICE_ACCCTRL_DID_MASK            (0xFU)
#define MEMCON_SLICE_ACCCTRL_DID_SHIFT           (0U)
/*! DID - Domain ID
 *  0b0xxx..Disables access for Domain ID 3
 *  0b1xxx..Enables access for Domain ID 3
 *  0bx0xx..Disables access for Domain ID 2
 *  0bx1xx..Enables access for Domain ID 2
 *  0bxx0x..Disables access for Domain ID 1
 *  0bxx1x..Enables access for Domain ID 1
 *  0bxxx0..Disables access for Domain ID 0
 *  0bxxx1..Enables access for Domain ID 0
 */
#define MEMCON_SLICE_ACCCTRL_DID(x)              (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_ACCCTRL_DID_SHIFT)) & MEMCON_SLICE_ACCCTRL_DID_MASK)

#define MEMCON_SLICE_ACCCTRL_UM_MASK             (0x10000U)
#define MEMCON_SLICE_ACCCTRL_UM_SHIFT            (16U)
/*! UM - User Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define MEMCON_SLICE_ACCCTRL_UM(x)               (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_ACCCTRL_UM_SHIFT)) & MEMCON_SLICE_ACCCTRL_UM_MASK)

#define MEMCON_SLICE_ACCCTRL_NSM_MASK            (0x20000U)
#define MEMCON_SLICE_ACCCTRL_NSM_SHIFT           (17U)
/*! NSM - Non-Secure Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define MEMCON_SLICE_ACCCTRL_NSM(x)              (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_ACCCTRL_NSM_SHIFT)) & MEMCON_SLICE_ACCCTRL_NSM_MASK)

#define MEMCON_SLICE_ACCCTRL_LOCK_MASK           (0x80000000U)
#define MEMCON_SLICE_ACCCTRL_LOCK_SHIFT          (31U)
/*! LOCK - Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define MEMCON_SLICE_ACCCTRL_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_ACCCTRL_LOCK_SHIFT)) & MEMCON_SLICE_ACCCTRL_LOCK_MASK)
/*! @} */

/*! @name MDCTRL - Mode Control */
/*! @{ */

#define MEMCON_SLICE_MDCTRL_TRGMODE_MASK         (0x3U)
#define MEMCON_SLICE_MDCTRL_TRGMODE_SHIFT        (0U)
/*! TRGMODE - Trigger Mode
 *  0b00..
 *  0b01..Hardware mode
 *  0b10..Software mode
 *  0b11..Hardware + software mode
 */
#define MEMCON_SLICE_MDCTRL_TRGMODE(x)           (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MDCTRL_TRGMODE_SHIFT)) & MEMCON_SLICE_MDCTRL_TRGMODE_MASK)

#define MEMCON_SLICE_MDCTRL_SWTRG_MASK           (0x4U)
#define MEMCON_SLICE_MDCTRL_SWTRG_SHIFT          (2U)
/*! SWTRG - Software Trigger Start
 *  0b0..Disables
 *  0b1..Enables
 */
#define MEMCON_SLICE_MDCTRL_SWTRG(x)             (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MDCTRL_SWTRG_SHIFT)) & MEMCON_SLICE_MDCTRL_SWTRG_MASK)
/*! @} */

/*! @name MEM_SLPCFG0 - Memory Power Control Under Low-Power 0 */
/*! @{ */

#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B0_MASK     (0x3U)
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B0_SHIFT    (0U)
/*! LPC_B0 - Power Control of Block 0
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B0(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG0_LPC_B0_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG0_LPC_B0_MASK)

#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B1_MASK     (0x30U)
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B1_SHIFT    (4U)
/*! LPC_B1 - Power Control of Block 1
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B1(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG0_LPC_B1_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG0_LPC_B1_MASK)

#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B2_MASK     (0x300U)
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B2_SHIFT    (8U)
/*! LPC_B2 - Power Control of Block 2
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B2(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG0_LPC_B2_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG0_LPC_B2_MASK)

#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B3_MASK     (0x3000U)
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B3_SHIFT    (12U)
/*! LPC_B3 - Power Control of Block 3
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B3(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG0_LPC_B3_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG0_LPC_B3_MASK)

#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B4_MASK     (0x30000U)
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B4_SHIFT    (16U)
/*! LPC_B4 - Power Control of Block 4
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B4(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG0_LPC_B4_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG0_LPC_B4_MASK)

#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B5_MASK     (0x300000U)
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B5_SHIFT    (20U)
/*! LPC_B5 - Power Control of Block 5
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B5(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG0_LPC_B5_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG0_LPC_B5_MASK)

#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B6_MASK     (0x3000000U)
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B6_SHIFT    (24U)
/*! LPC_B6 - Power Control of Block 6
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B6(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG0_LPC_B6_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG0_LPC_B6_MASK)

#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B7_MASK     (0x30000000U)
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B7_SHIFT    (28U)
/*! LPC_B7 - Power Control of Block 7
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG0_LPC_B7(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG0_LPC_B7_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG0_LPC_B7_MASK)
/*! @} */

/*! @name MEM_SLPCFG1 - Memory Power Control Under Low-Power 1 */
/*! @{ */

#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B8_MASK     (0x3U)
#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B8_SHIFT    (0U)
/*! LPC_B8 - Power Control of Block 8
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B8(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG1_LPC_B8_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG1_LPC_B8_MASK)

#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B9_MASK     (0x30U)
#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B9_SHIFT    (4U)
/*! LPC_B9 - Power Control of Block 9
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B9(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG1_LPC_B9_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG1_LPC_B9_MASK)

#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B10_MASK    (0x300U)
#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B10_SHIFT   (8U)
/*! LPC_B10 - Power Control of Block 10
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B10(x)      (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG1_LPC_B10_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG1_LPC_B10_MASK)

#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B11_MASK    (0x3000U)
#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B11_SHIFT   (12U)
/*! LPC_B11 - Power Control of Block 11
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_SLPCFG1_LPC_B11(x)      (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_SLPCFG1_LPC_B11_SHIFT)) & MEMCON_SLICE_MEM_SLPCFG1_LPC_B11_MASK)
/*! @} */

/*! @name MEM_RUNCFG0 - Memory Power Control Under Active 0 */
/*! @{ */

#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B0_MASK     (0x3U)
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B0_SHIFT    (0U)
/*! HPC_B0 - Power Control of Block 0
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B0(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG0_HPC_B0_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG0_HPC_B0_MASK)

#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B1_MASK     (0x30U)
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B1_SHIFT    (4U)
/*! HPC_B1 - Power Control of Block 1
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B1(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG0_HPC_B1_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG0_HPC_B1_MASK)

#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B2_MASK     (0x300U)
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B2_SHIFT    (8U)
/*! HPC_B2 - Power Control of Block 2
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B2(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG0_HPC_B2_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG0_HPC_B2_MASK)

#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B3_MASK     (0x3000U)
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B3_SHIFT    (12U)
/*! HPC_B3 - Power Control of Block 3
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B3(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG0_HPC_B3_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG0_HPC_B3_MASK)

#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B4_MASK     (0x30000U)
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B4_SHIFT    (16U)
/*! HPC_B4 - Power Control of Block 4
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B4(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG0_HPC_B4_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG0_HPC_B4_MASK)

#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B5_MASK     (0x300000U)
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B5_SHIFT    (20U)
/*! HPC_B5 - Power Control of Block 6
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B5(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG0_HPC_B5_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG0_HPC_B5_MASK)

#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B6_MASK     (0x3000000U)
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B6_SHIFT    (24U)
/*! HPC_B6 - Power Control of Block 6
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B6(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG0_HPC_B6_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG0_HPC_B6_MASK)

#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B7_MASK     (0x30000000U)
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B7_SHIFT    (28U)
/*! HPC_B7 - Power Control of Block 7
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG0_HPC_B7(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG0_HPC_B7_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG0_HPC_B7_MASK)
/*! @} */

/*! @name MEM_RUNCFG1 - Memory Power Control Under Active 1 */
/*! @{ */

#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B8_MASK     (0x3U)
#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B8_SHIFT    (0U)
/*! HPC_B8 - Power Control of Block 8
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B8(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG1_HPC_B8_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG1_HPC_B8_MASK)

#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B9_MASK     (0x30U)
#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B9_SHIFT    (4U)
/*! HPC_B9 - Power Control of Block 9
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B9(x)       (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG1_HPC_B9_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG1_HPC_B9_MASK)

#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B10_MASK    (0x300U)
#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B10_SHIFT   (8U)
/*! HPC_B10 - Power Control of Block 10
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B10(x)      (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG1_HPC_B10_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG1_HPC_B10_MASK)

#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B11_MASK    (0x3000U)
#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B11_SHIFT   (12U)
/*! HPC_B11 - Power Control of Block 11
 *  0b00..Active mode
 *  0b01..Retention mode
 *  0b10..Power-down mode
 *  0b11..
 */
#define MEMCON_SLICE_MEM_RUNCFG1_HPC_B11(x)      (((uint32_t)(((uint32_t)(x)) << MEMCON_SLICE_MEM_RUNCFG1_HPC_B11_SHIFT)) & MEMCON_SLICE_MEM_RUNCFG1_HPC_B11_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MEMCON_SLICE_Register_Masks */


/*!
 * @}
 */ /* end of group MEMCON_SLICE_Peripheral_Access_Layer */


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


#endif  /* PERI_MEMCON_SLICE_H_ */

