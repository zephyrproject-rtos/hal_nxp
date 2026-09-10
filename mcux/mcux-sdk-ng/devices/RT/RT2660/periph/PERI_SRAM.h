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
**         CMSIS Peripheral Access Layer for SRAM
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
 * @file PERI_SRAM.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for SRAM
 *
 * CMSIS Peripheral Access Layer for SRAM
 */

#if !defined(PERI_SRAM_H_)
#define PERI_SRAM_H_                             /**< Symbol preventing repeated inclusion */

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
   -- SRAM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRAM_Peripheral_Access_Layer SRAM Peripheral Access Layer
 * @{
 */

/** SRAM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[12288];
  __IO uint32_t CTRL;                              /**< Control, offset: 0x3000 */
} SRAM_Type;

/* ----------------------------------------------------------------------------
   -- SRAM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRAM_Register_Masks SRAM Register Masks
 * @{
 */

/*! @name CTRL - Control */
/*! @{ */

#define SRAM_CTRL_RAM_RD_EN_MASK                 (0x1U)
#define SRAM_CTRL_RAM_RD_EN_SHIFT                (0U)
/*! RAM_RD_EN - RAM Read Enable (with lock)
 *  0b0..Disables read access
 *  0b1..Enables read access
 */
#define SRAM_CTRL_RAM_RD_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_RAM_RD_EN_SHIFT)) & SRAM_CTRL_RAM_RD_EN_MASK)

#define SRAM_CTRL_RAM_WR_EN_MASK                 (0x2U)
#define SRAM_CTRL_RAM_WR_EN_SHIFT                (1U)
/*! RAM_WR_EN - RAM Write Enable (with lock)
 *  0b0..Disables write access
 *  0b1..Enables write access
 */
#define SRAM_CTRL_RAM_WR_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_RAM_WR_EN_SHIFT)) & SRAM_CTRL_RAM_WR_EN_MASK)

#define SRAM_CTRL_PWR_MODE_MASK                  (0x3CU)
#define SRAM_CTRL_PWR_MODE_SHIFT                 (2U)
/*! PWR_MODE - Memory Power Mode Setting (with lock)
 *  0b0000..SHUTDOWN (SD) Mode
 *  0b0010..INTERMEDIATE (INT) Mode
 *  0b0100..SHUTDOWN_POWER_UP (SD PU) Mode
 *  0b0110..ACTIVE (ACT) Mode
 *  0b1010..DEEPSLEEP (DS) Mode
 *  0b1110..DEEPSLEEP_POWER_UP (DS PU) Mode
 */
#define SRAM_CTRL_PWR_MODE(x)                    (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_PWR_MODE_SHIFT)) & SRAM_CTRL_PWR_MODE_MASK)

#define SRAM_CTRL_TAMPER_BLOCK_EN_MASK           (0x40U)
#define SRAM_CTRL_TAMPER_BLOCK_EN_SHIFT          (6U)
/*! TAMPER_BLOCK_EN - Tamper Block Enable (with lock)
 *  0b0..Allows R/W access to secure RAM when tamper is detected
 *  0b1..Blocks R/W access to secure RAM when tamper is detected
 */
#define SRAM_CTRL_TAMPER_BLOCK_EN(x)             (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_TAMPER_BLOCK_EN_SHIFT)) & SRAM_CTRL_TAMPER_BLOCK_EN_MASK)

#define SRAM_CTRL_TAMPER_PWR_OFF_EN_MASK         (0x80U)
#define SRAM_CTRL_TAMPER_PWR_OFF_EN_SHIFT        (7U)
/*! TAMPER_PWR_OFF_EN - Turn off power on tamper event (with lock)
 *  0b0..Disable the turn-off function when tamper is detected
 *  0b1..Turns off power for all secure RAM banks when tamper is detected
 */
#define SRAM_CTRL_TAMPER_PWR_OFF_EN(x)           (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_TAMPER_PWR_OFF_EN_SHIFT)) & SRAM_CTRL_TAMPER_PWR_OFF_EN_MASK)

#define SRAM_CTRL_SM_MASK                        (0x700U)
#define SRAM_CTRL_SM_SHIFT                       (8U)
/*! SM - Memories Source Bias Setting */
#define SRAM_CTRL_SM(x)                          (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_SM_SHIFT)) & SRAM_CTRL_SM_MASK)

#define SRAM_CTRL_LOCK_BIT_MASK                  (0x7FF0000U)
#define SRAM_CTRL_LOCK_BIT_SHIFT                 (16U)
/*! LOCK_BIT - Lock bits
 *  0b00000000000..The corresponding function bit is not locked
 *  0b00000000001..The corresponding function bit is locked
 */
#define SRAM_CTRL_LOCK_BIT(x)                    (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_LOCK_BIT_SHIFT)) & SRAM_CTRL_LOCK_BIT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRAM_Register_Masks */


/*!
 * @}
 */ /* end of group SRAM_Peripheral_Access_Layer */


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


#endif  /* PERI_SRAM_H_ */

