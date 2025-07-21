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
**         CMSIS Peripheral Access Layer for SRAM
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
 * @file PERI_SRAM.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SRAM
 *
 * CMSIS Peripheral Access Layer for SRAM
 */

#if !defined(PERI_SRAM_H_)
#define PERI_SRAM_H_                             /**< Symbol preventing repeated inclusion */

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
   -- SRAM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRAM_Peripheral_Access_Layer SRAM Peripheral Access Layer
 * @{
 */

/** SRAM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[12288];
  __IO uint32_t CTRL;                              /**< Control Register, offset: 0x3000 */
} SRAM_Type;

/* ----------------------------------------------------------------------------
   -- SRAM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRAM_Register_Masks SRAM Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
/*! @{ */

#define SRAM_CTRL_RAM_RD_EN_MASK                 (0x1U)
#define SRAM_CTRL_RAM_RD_EN_SHIFT                (0U)
/*! RAM_RD_EN - RAM Read Enable (with lock)
 *  0b0..Disable read access
 *  0b1..Enable read access
 */
#define SRAM_CTRL_RAM_RD_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_RAM_RD_EN_SHIFT)) & SRAM_CTRL_RAM_RD_EN_MASK)

#define SRAM_CTRL_RAM_WR_EN_MASK                 (0x2U)
#define SRAM_CTRL_RAM_WR_EN_SHIFT                (1U)
/*! RAM_WR_EN - RAM Write Enable (with lock)
 *  0b0..Disable write access
 *  0b1..Enable write access
 */
#define SRAM_CTRL_RAM_WR_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_RAM_WR_EN_SHIFT)) & SRAM_CTRL_RAM_WR_EN_MASK)

#define SRAM_CTRL_PWR_EN_MASK                    (0x3CU)
#define SRAM_CTRL_PWR_EN_SHIFT                   (2U)
/*! PWR_EN - Power Enable (with lock) */
#define SRAM_CTRL_PWR_EN(x)                      (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_PWR_EN_SHIFT)) & SRAM_CTRL_PWR_EN_MASK)

#define SRAM_CTRL_TAMPER_BLOCK_EN_MASK           (0x40U)
#define SRAM_CTRL_TAMPER_BLOCK_EN_SHIFT          (6U)
/*! TAMPER_BLOCK_EN - Tamper Block Enable (with lock)
 *  0b0..Allow R/W access to secure RAM when tamper is detected
 *  0b1..Block R/W access to secure RAM when tamper is detected
 */
#define SRAM_CTRL_TAMPER_BLOCK_EN(x)             (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_TAMPER_BLOCK_EN_SHIFT)) & SRAM_CTRL_TAMPER_BLOCK_EN_MASK)

#define SRAM_CTRL_TAMPER_PWR_OFF_EN_MASK         (0x80U)
#define SRAM_CTRL_TAMPER_PWR_OFF_EN_SHIFT        (7U)
/*! TAMPER_PWR_OFF_EN - Turn off power on tamper event (with lock)
 *  0b0..Disable the turn off function when tamper is detected
 *  0b1..Turn off power for all secure RAM banks when tamper is detected
 */
#define SRAM_CTRL_TAMPER_PWR_OFF_EN(x)           (((uint32_t)(((uint32_t)(x)) << SRAM_CTRL_TAMPER_PWR_OFF_EN_SHIFT)) & SRAM_CTRL_TAMPER_PWR_OFF_EN_MASK)

#define SRAM_CTRL_LOCK_BIT_MASK                  (0xFF0000U)
#define SRAM_CTRL_LOCK_BIT_SHIFT                 (16U)
/*! LOCK_BIT - Lock bits */
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


#endif  /* PERI_SRAM_H_ */

