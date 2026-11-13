/*
** ###################################################################
**     Processors:          MCXC352GAMFM
**                          MCXC352GAMFT
**                          MCXC352MLF
**                          MCXC353GAMFM
**                          MCXC353GAMFT
**                          MCXC353MLF
**
**     Version:             rev. 1.0, 2025-11-26
**     Build:               b260826
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XBAR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-11-26)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_XBAR.h
 * @version 1.0
 * @date 2025-11-26
 * @brief CMSIS Peripheral Access Layer for XBAR
 *
 * CMSIS Peripheral Access Layer for XBAR
 */

#if !defined(PERI_XBAR_H_)
#define PERI_XBAR_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC352GAMFM) || defined(CPU_MCXC352GAMFT) || defined(CPU_MCXC352MLF))
#include "MCXC352_COMMON.h"
#elif (defined(CPU_MCXC353GAMFM) || defined(CPU_MCXC353GAMFT) || defined(CPU_MCXC353MLF))
#include "MCXC353_COMMON.h"
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
   -- XBAR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_Peripheral_Access_Layer XBAR Peripheral Access Layer
 * @{
 */

/** XBAR - Size of Registers Arrays */
#define XBAR_SEL_COUNT                            65u
#define XBAR_CTRL_COUNT                           4u

/** XBAR - Register Layout Typedef */
typedef struct {
  __IO uint32_t SEL[XBAR_SEL_COUNT];               /**< Crossbar Select Register, array offset: 0x0, array step: 0x4 */
  __IO uint32_t CTRL[XBAR_CTRL_COUNT];             /**< Crossbar Control Register, array offset: 0x104, array step: 0x4 */
} XBAR_Type;

/* ----------------------------------------------------------------------------
   -- XBAR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_Register_Masks XBAR Register Masks
 * @{
 */

/*! @name SEL - Crossbar Select Register */
/*! @{ */

#define XBAR_SEL_SEL_MASK                        (0x3FU)
#define XBAR_SEL_SEL_SHIFT                       (0U)
/*! SEL - SEL */
#define XBAR_SEL_SEL(x)                          (((uint32_t)(((uint32_t)(x)) << XBAR_SEL_SEL_SHIFT)) & XBAR_SEL_SEL_MASK)

#define XBAR_SEL_WP_MASK                         (0x80000000U)
#define XBAR_SEL_WP_SHIFT                        (31U)
/*! WP - Write Protect
 *  0b0..Writing to this register is allowed.
 *  0b1..No further writing to this register is allowed.
 */
#define XBAR_SEL_WP(x)                           (((uint32_t)(((uint32_t)(x)) << XBAR_SEL_WP_SHIFT)) & XBAR_SEL_WP_MASK)
/*! @} */

/*! @name CTRL - Crossbar Control Register */
/*! @{ */

#define XBAR_CTRL_DEN_MASK                       (0x1U)
#define XBAR_CTRL_DEN_SHIFT                      (0U)
/*! DEN - DMA Enable for XBAR_OUTn
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_CTRL_DEN(x)                         (((uint32_t)(((uint32_t)(x)) << XBAR_CTRL_DEN_SHIFT)) & XBAR_CTRL_DEN_MASK)

#define XBAR_CTRL_IEN_MASK                       (0x2U)
#define XBAR_CTRL_IEN_SHIFT                      (1U)
/*! IEN - Interrupt Enable for XBAR_OUTn
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_CTRL_IEN(x)                         (((uint32_t)(((uint32_t)(x)) << XBAR_CTRL_IEN_SHIFT)) & XBAR_CTRL_IEN_MASK)

#define XBAR_CTRL_EDGE_MASK                      (0xCU)
#define XBAR_CTRL_EDGE_SHIFT                     (2U)
/*! EDGE - Active edge for edge detection on XBAR_OUTn
 *  0b00..STSn never asserts
 *  0b01..STSn asserts on rising edges of XBAR_OUTn
 *  0b10..STSn asserts on falling edges of XBAR_OUTn
 *  0b11..STSn asserts on rising and falling edges of XBAR_OUTn
 */
#define XBAR_CTRL_EDGE(x)                        (((uint32_t)(((uint32_t)(x)) << XBAR_CTRL_EDGE_SHIFT)) & XBAR_CTRL_EDGE_MASK)

#define XBAR_CTRL_STS_MASK                       (0x10U)
#define XBAR_CTRL_STS_SHIFT                      (4U)
/*! STS - Edge detection status for XBAR_OUTn
 *  0b0..Active edge not yet detected on XBAR_OUTn
 *  0b1..Active edge detected on XBAR_OUTn
 */
#define XBAR_CTRL_STS(x)                         (((uint32_t)(((uint32_t)(x)) << XBAR_CTRL_STS_SHIFT)) & XBAR_CTRL_STS_MASK)

#define XBAR_CTRL_WP_MASK                        (0x80000000U)
#define XBAR_CTRL_WP_SHIFT                       (31U)
/*! WP - Write Protect
 *  0b0..Writing to this register is allowed.
 *  0b1..No further writing to this register is allowed.
 */
#define XBAR_CTRL_WP(x)                          (((uint32_t)(((uint32_t)(x)) << XBAR_CTRL_WP_SHIFT)) & XBAR_CTRL_WP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XBAR_Register_Masks */


/*!
 * @}
 */ /* end of group XBAR_Peripheral_Access_Layer */


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


#endif  /* PERI_XBAR_H_ */

