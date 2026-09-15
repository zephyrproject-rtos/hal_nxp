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
**         CMSIS Peripheral Access Layer for XBAR4
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
 * @file PERI_XBAR4.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for XBAR4
 *
 * CMSIS Peripheral Access Layer for XBAR4
 */

#if !defined(PERI_XBAR4_H_)
#define PERI_XBAR4_H_                            /**< Symbol preventing repeated inclusion */

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
   -- XBAR4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR4_Peripheral_Access_Layer XBAR4 Peripheral Access Layer
 * @{
 */

/** XBAR4 - Size of Registers Arrays */
#define XBAR4_SEL_COUNT                           35u
#define XBAR4_CTRL_COUNT                          2u

/** XBAR4 - Register Layout Typedef */
typedef struct {
  __IO uint32_t SEL[XBAR4_SEL_COUNT];              /**< Crossbar Select Register, array offset: 0x0, array step: 0x4 */
  __IO uint32_t CTRL[XBAR4_CTRL_COUNT];            /**< Crossbar Control Register, array offset: 0x8C, array step: 0x4 */
} XBAR4_Type;

/* ----------------------------------------------------------------------------
   -- XBAR4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR4_Register_Masks XBAR4 Register Masks
 * @{
 */

/*! @name SEL - Crossbar Select Register */
/*! @{ */

#define XBAR4_SEL_SEL_MASK                       (0x7FU)
#define XBAR4_SEL_SEL_SHIFT                      (0U)
/*! SEL - SEL */
#define XBAR4_SEL_SEL(x)                         (((uint32_t)(((uint32_t)(x)) << XBAR4_SEL_SEL_SHIFT)) & XBAR4_SEL_SEL_MASK)

#define XBAR4_SEL_WP_MASK                        (0x80000000U)
#define XBAR4_SEL_WP_SHIFT                       (31U)
/*! WP - Write Protect
 *  0b0..Writing to this register is allowed.
 *  0b1..No further writing to this register is allowed.
 */
#define XBAR4_SEL_WP(x)                          (((uint32_t)(((uint32_t)(x)) << XBAR4_SEL_WP_SHIFT)) & XBAR4_SEL_WP_MASK)
/*! @} */

/*! @name CTRL - Crossbar Control Register */
/*! @{ */

#define XBAR4_CTRL_DEN_MASK                      (0x1U)
#define XBAR4_CTRL_DEN_SHIFT                     (0U)
/*! DEN - DMA Enable for XBAR_OUTn
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR4_CTRL_DEN(x)                        (((uint32_t)(((uint32_t)(x)) << XBAR4_CTRL_DEN_SHIFT)) & XBAR4_CTRL_DEN_MASK)

#define XBAR4_CTRL_IEN_MASK                      (0x2U)
#define XBAR4_CTRL_IEN_SHIFT                     (1U)
/*! IEN - Interrupt Enable for XBAR_OUTn
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR4_CTRL_IEN(x)                        (((uint32_t)(((uint32_t)(x)) << XBAR4_CTRL_IEN_SHIFT)) & XBAR4_CTRL_IEN_MASK)

#define XBAR4_CTRL_EDGE_MASK                     (0xCU)
#define XBAR4_CTRL_EDGE_SHIFT                    (2U)
/*! EDGE - Active edge for edge detection on XBAR_OUTn
 *  0b00..STSn never asserts
 *  0b01..STSn asserts on rising edges of XBAR_OUTn
 *  0b10..STSn asserts on falling edges of XBAR_OUTn
 *  0b11..STSn asserts on rising and falling edges of XBAR_OUTn
 */
#define XBAR4_CTRL_EDGE(x)                       (((uint32_t)(((uint32_t)(x)) << XBAR4_CTRL_EDGE_SHIFT)) & XBAR4_CTRL_EDGE_MASK)

#define XBAR4_CTRL_STS_MASK                      (0x10U)
#define XBAR4_CTRL_STS_SHIFT                     (4U)
/*! STS - Edge detection status for XBAR_OUTn
 *  0b0..Active edge not yet detected on XBAR_OUTn
 *  0b1..Active edge detected on XBAR_OUTn
 */
#define XBAR4_CTRL_STS(x)                        (((uint32_t)(((uint32_t)(x)) << XBAR4_CTRL_STS_SHIFT)) & XBAR4_CTRL_STS_MASK)

#define XBAR4_CTRL_WP_MASK                       (0x80000000U)
#define XBAR4_CTRL_WP_SHIFT                      (31U)
/*! WP - Write Protect
 *  0b0..Writing to this register is allowed.
 *  0b1..No further writing to this register is allowed.
 */
#define XBAR4_CTRL_WP(x)                         (((uint32_t)(((uint32_t)(x)) << XBAR4_CTRL_WP_SHIFT)) & XBAR4_CTRL_WP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XBAR4_Register_Masks */


/*!
 * @}
 */ /* end of group XBAR4_Peripheral_Access_Layer */


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


#endif  /* PERI_XBAR4_H_ */

