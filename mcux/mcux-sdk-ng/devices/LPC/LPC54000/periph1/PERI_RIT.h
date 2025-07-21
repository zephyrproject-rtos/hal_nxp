/*
** ###################################################################
**     Processors:          LPC54005JBD100
**                          LPC54005JET100
**                          LPC54016JBD100
**                          LPC54016JBD208
**                          LPC54016JET100
**                          LPC54016JET180
**                          LPC54018JBD208
**                          LPC54018JET180
**                          LPC54S005JBD100
**                          LPC54S005JET100
**                          LPC54S016JBD100
**                          LPC54S016JBD208
**                          LPC54S016JET100
**                          LPC54S016JET180
**                          LPC54S018JBD208
**                          LPC54S018JET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RIT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RIT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RIT
 *
 * CMSIS Peripheral Access Layer for RIT
 */

#if !defined(PERI_RIT_H_)
#define PERI_RIT_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54005JBD100) || defined(CPU_LPC54005JET100))
#include "LPC54005_COMMON.h"
#elif (defined(CPU_LPC54016JBD100) || defined(CPU_LPC54016JBD208) || defined(CPU_LPC54016JET100) || defined(CPU_LPC54016JET180))
#include "LPC54016_COMMON.h"
#elif (defined(CPU_LPC54018JBD208) || defined(CPU_LPC54018JET180))
#include "LPC54018_COMMON.h"
#elif (defined(CPU_LPC54S005JBD100) || defined(CPU_LPC54S005JET100))
#include "LPC54S005_COMMON.h"
#elif (defined(CPU_LPC54S016JBD100) || defined(CPU_LPC54S016JBD208) || defined(CPU_LPC54S016JET100) || defined(CPU_LPC54S016JET180))
#include "LPC54S016_COMMON.h"
#elif (defined(CPU_LPC54S018JBD208) || defined(CPU_LPC54S018JET180))
#include "LPC54S018_COMMON.h"
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
   -- RIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RIT_Peripheral_Access_Layer RIT Peripheral Access Layer
 * @{
 */

/** RIT - Register Layout Typedef */
typedef struct {
  __IO uint32_t COMPVAL;                           /**< Compare value LSB register, offset: 0x0 */
  __IO uint32_t MASK;                              /**< Mask LSB register, offset: 0x4 */
  __IO uint32_t CTRL;                              /**< Control register, offset: 0x8 */
  __IO uint32_t COUNTER;                           /**< Counter LSB register, offset: 0xC */
  __IO uint32_t COMPVAL_H;                         /**< Compare value MSB register, offset: 0x10 */
  __IO uint32_t MASK_H;                            /**< Mask MSB register, offset: 0x14 */
       uint8_t RESERVED_0[4];
  __IO uint32_t COUNTER_H;                         /**< Counter MSB register, offset: 0x1C */
} RIT_Type;

/* ----------------------------------------------------------------------------
   -- RIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RIT_Register_Masks RIT Register Masks
 * @{
 */

/*! @name COMPVAL - Compare value LSB register */
/*! @{ */

#define RIT_COMPVAL_RICOMP_MASK                  (0xFFFFFFFFU)
#define RIT_COMPVAL_RICOMP_SHIFT                 (0U)
/*! RICOMP - . */
#define RIT_COMPVAL_RICOMP(x)                    (((uint32_t)(((uint32_t)(x)) << RIT_COMPVAL_RICOMP_SHIFT)) & RIT_COMPVAL_RICOMP_MASK)
/*! @} */

/*! @name MASK - Mask LSB register */
/*! @{ */

#define RIT_MASK_RIMASK_MASK                     (0xFFFFFFFFU)
#define RIT_MASK_RIMASK_SHIFT                    (0U)
/*! RIMASK - Mask register. */
#define RIT_MASK_RIMASK(x)                       (((uint32_t)(((uint32_t)(x)) << RIT_MASK_RIMASK_SHIFT)) & RIT_MASK_RIMASK_MASK)
/*! @} */

/*! @name CTRL - Control register */
/*! @{ */

#define RIT_CTRL_RITINT_MASK                     (0x1U)
#define RIT_CTRL_RITINT_SHIFT                    (0U)
/*! RITINT - Interrupt flag. */
#define RIT_CTRL_RITINT(x)                       (((uint32_t)(((uint32_t)(x)) << RIT_CTRL_RITINT_SHIFT)) & RIT_CTRL_RITINT_MASK)

#define RIT_CTRL_RITENCLR_MASK                   (0x2U)
#define RIT_CTRL_RITENCLR_SHIFT                  (1U)
/*! RITENCLR - Timer enable clear. */
#define RIT_CTRL_RITENCLR(x)                     (((uint32_t)(((uint32_t)(x)) << RIT_CTRL_RITENCLR_SHIFT)) & RIT_CTRL_RITENCLR_MASK)

#define RIT_CTRL_RITENBR_MASK                    (0x4U)
#define RIT_CTRL_RITENBR_SHIFT                   (2U)
/*! RITENBR - Timer enable for debug. */
#define RIT_CTRL_RITENBR(x)                      (((uint32_t)(((uint32_t)(x)) << RIT_CTRL_RITENBR_SHIFT)) & RIT_CTRL_RITENBR_MASK)

#define RIT_CTRL_RITEN_MASK                      (0x8U)
#define RIT_CTRL_RITEN_SHIFT                     (3U)
/*! RITEN - Timer enable. */
#define RIT_CTRL_RITEN(x)                        (((uint32_t)(((uint32_t)(x)) << RIT_CTRL_RITEN_SHIFT)) & RIT_CTRL_RITEN_MASK)
/*! @} */

/*! @name COUNTER - Counter LSB register */
/*! @{ */

#define RIT_COUNTER_RICOUNTER_MASK               (0xFFFFFFFFU)
#define RIT_COUNTER_RICOUNTER_SHIFT              (0U)
/*! RICOUNTER - 32 LSBs of the up counter. */
#define RIT_COUNTER_RICOUNTER(x)                 (((uint32_t)(((uint32_t)(x)) << RIT_COUNTER_RICOUNTER_SHIFT)) & RIT_COUNTER_RICOUNTER_MASK)
/*! @} */

/*! @name COMPVAL_H - Compare value MSB register */
/*! @{ */

#define RIT_COMPVAL_H_RICOMP_MASK                (0xFFFFU)
#define RIT_COMPVAL_H_RICOMP_SHIFT               (0U)
/*! RICOMP - Compare value MSB register. */
#define RIT_COMPVAL_H_RICOMP(x)                  (((uint32_t)(((uint32_t)(x)) << RIT_COMPVAL_H_RICOMP_SHIFT)) & RIT_COMPVAL_H_RICOMP_MASK)
/*! @} */

/*! @name MASK_H - Mask MSB register */
/*! @{ */

#define RIT_MASK_H_RIMASK_MASK                   (0xFFFFU)
#define RIT_MASK_H_RIMASK_SHIFT                  (0U)
/*! RIMASK - Mask register. */
#define RIT_MASK_H_RIMASK(x)                     (((uint32_t)(((uint32_t)(x)) << RIT_MASK_H_RIMASK_SHIFT)) & RIT_MASK_H_RIMASK_MASK)
/*! @} */

/*! @name COUNTER_H - Counter MSB register */
/*! @{ */

#define RIT_COUNTER_H_RICOUNTER_MASK             (0xFFFFU)
#define RIT_COUNTER_H_RICOUNTER_SHIFT            (0U)
/*! RICOUNTER - 16 LSBs of the up counter. */
#define RIT_COUNTER_H_RICOUNTER(x)               (((uint32_t)(((uint32_t)(x)) << RIT_COUNTER_H_RICOUNTER_SHIFT)) & RIT_COUNTER_H_RICOUNTER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RIT_Register_Masks */


/*!
 * @}
 */ /* end of group RIT_Peripheral_Access_Layer */


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


#endif  /* PERI_RIT_H_ */

