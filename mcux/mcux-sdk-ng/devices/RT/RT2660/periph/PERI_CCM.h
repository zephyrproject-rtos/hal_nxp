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
**         CMSIS Peripheral Access Layer for CCM
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
 * @file PERI_CCM.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for CCM
 *
 * CMSIS Peripheral Access Layer for CCM
 */

#if !defined(PERI_CCM_H_)
#define PERI_CCM_H_                              /**< Symbol preventing repeated inclusion */

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
   -- CCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Peripheral_Access_Layer CCM Peripheral Access Layer
 * @{
 */

/** CCM - Size of Registers Arrays */
#define CCM_CLOCK_ROOT_COUNT                      49u
#define CCM_CGC_ROOT_COUNT                        75u

/** CCM - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10 */
    __IO uint32_t ACCESS_CTRL;                       /**< Clock Root Access Control, array offset: 0x0, array step: 0x10, irregular array, not all indices are valid */
    __IO uint32_t SLICE_CONTROL;                     /**< Clock Root Control, array offset: 0x4, array step: 0x10, irregular array, not all indices are valid */
    __I  uint32_t STATUS0;                           /**< Clock Root Working Status, array offset: 0x8, array step: 0x10, irregular array, not all indices are valid */
    __I  uint32_t STATUS1;                           /**< Clock Root Hardware Status, array offset: 0xC, array step: 0x10, irregular array, not all indices are valid */
  } CLOCK_ROOT[CCM_CLOCK_ROOT_COUNT];
       uint8_t RESERVED_0[3312];
  struct {                                         /* offset: 0x1000, array step: 0x10 */
    __IO uint32_t ACCESS_CTRL;                       /**< Clock Gating Root Access Control, array offset: 0x1000, array step: 0x10, irregular array, not all indices are valid */
    __IO uint32_t SLICE_CONTROL;                     /**< Clock Gating Root Control, array offset: 0x1004, array step: 0x10, irregular array, not all indices are valid */
    __I  uint32_t STATUS;                            /**< Clock Gating Root Working Status, array offset: 0x1008, array step: 0x10, irregular array, not all indices are valid */
         uint8_t RESERVED_0[4];
  } CGC_ROOT[CCM_CGC_ROOT_COUNT];
} CCM_Type;

/* ----------------------------------------------------------------------------
   -- CCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Register_Masks CCM Register Masks
 * @{
 */

/*! @name ACCESS_CTRL - Clock Root Access Control */
/*! @{ */

#define CCM_ACCESS_CTRL_DMN_ACC_CTRL_MASK        (0xFU)
#define CCM_ACCESS_CTRL_DMN_ACC_CTRL_SHIFT       (0U)
/*! DMN_ACC_CTRL - Domain access control settings */
#define CCM_ACCESS_CTRL_DMN_ACC_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DMN_ACC_CTRL_SHIFT)) & CCM_ACCESS_CTRL_DMN_ACC_CTRL_MASK)

#define CCM_ACCESS_CTRL_ALLOW_USER_MASK          (0x10000U)
#define CCM_ACCESS_CTRL_ALLOW_USER_SHIFT         (16U)
/*! ALLOW_USER - User access permission
 *  0b0..Clock Root settings cannot be changed in the user mode.
 *  0b1..Clock Root settings can be changed in the user mode.
 */
#define CCM_ACCESS_CTRL_ALLOW_USER(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ALLOW_USER_SHIFT)) & CCM_ACCESS_CTRL_ALLOW_USER_MASK)

#define CCM_ACCESS_CTRL_ALLOW_NS_MASK            (0x20000U)
#define CCM_ACCESS_CTRL_ALLOW_NS_SHIFT           (17U)
/*! ALLOW_NS - Non-secure access permission
 *  0b0..Cannot be changed in the non-secure mode.
 *  0b1..Can be changed in the non-secure mode.
 */
#define CCM_ACCESS_CTRL_ALLOW_NS(x)              (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ALLOW_NS_SHIFT)) & CCM_ACCESS_CTRL_ALLOW_NS_MASK)

#define CCM_ACCESS_CTRL_LOCK_CTRL_MASK           (0x80000000U)
#define CCM_ACCESS_CTRL_LOCK_CTRL_SHIFT          (31U)
/*! LOCK_CTRL - Lock access permission settings
 *  0b0..Access permission settings not locked.
 *  0b1..Access permission settings locked.
 */
#define CCM_ACCESS_CTRL_LOCK_CTRL(x)             (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_LOCK_CTRL_SHIFT)) & CCM_ACCESS_CTRL_LOCK_CTRL_MASK)
/*! @} */

/* The count of CCM_ACCESS_CTRL */
#define CCM_ACCESS_CTRL_COUNT                    (49U)

/*! @name SLICE_CONTROL - Clock Root Control */
/*! @{ */

#define CCM_SLICE_CONTROL_DIV_MASK               (0xFFU)
#define CCM_SLICE_CONTROL_DIV_SHIFT              (0U)
/*! DIV - Clock division fraction. */
#define CCM_SLICE_CONTROL_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_SLICE_CONTROL_DIV_SHIFT)) & CCM_SLICE_CONTROL_DIV_MASK)

#define CCM_SLICE_CONTROL_MUX_MASK               (0x300U)
#define CCM_SLICE_CONTROL_MUX_SHIFT              (8U)
/*! MUX - Clock multiplexer.
 *  0b00..Selects clock source 0
 *  0b01..Selects clock source 1
 *  0b10..Selects clock source 2
 *  0b11..Selects clock source 3
 */
#define CCM_SLICE_CONTROL_MUX(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_SLICE_CONTROL_MUX_SHIFT)) & CCM_SLICE_CONTROL_MUX_MASK)

#define CCM_SLICE_CONTROL_SHUTDOWN_MASK          (0x1000U)
#define CCM_SLICE_CONTROL_SHUTDOWN_SHIFT         (12U)
/*! SHUTDOWN - Shutdown clock root.
 *  0b0..Clock is running.
 *  0b1..Turns off the clock.
 */
#define CCM_SLICE_CONTROL_SHUTDOWN(x)            (((uint32_t)(((uint32_t)(x)) << CCM_SLICE_CONTROL_SHUTDOWN_SHIFT)) & CCM_SLICE_CONTROL_SHUTDOWN_MASK)

#define CCM_SLICE_CONTROL_SND_DIV_MASK           (0xFF0000U)
#define CCM_SLICE_CONTROL_SND_DIV_SHIFT          (16U)
/*! SND_DIV - Second clock division fraction. */
#define CCM_SLICE_CONTROL_SND_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CCM_SLICE_CONTROL_SND_DIV_SHIFT)) & CCM_SLICE_CONTROL_SND_DIV_MASK)
/*! @} */

/* The count of CCM_SLICE_CONTROL */
#define CCM_SLICE_CONTROL_COUNT                  (49U)

/*! @name STATUS0 - Clock Root Working Status */
/*! @{ */

#define CCM_STATUS0_DIV_MASK                     (0xFFU)
#define CCM_STATUS0_DIV_SHIFT                    (0U)
/*! DIV - Current clock root DIV setting */
#define CCM_STATUS0_DIV(x)                       (((uint32_t)(((uint32_t)(x)) << CCM_STATUS0_DIV_SHIFT)) & CCM_STATUS0_DIV_MASK)

#define CCM_STATUS0_MUX_MASK                     (0x300U)
#define CCM_STATUS0_MUX_SHIFT                    (8U)
/*! MUX - Current clock root MUX setting */
#define CCM_STATUS0_MUX(x)                       (((uint32_t)(((uint32_t)(x)) << CCM_STATUS0_MUX_SHIFT)) & CCM_STATUS0_MUX_MASK)

#define CCM_STATUS0_OFF_MASK                     (0x1000U)
#define CCM_STATUS0_OFF_SHIFT                    (12U)
/*! OFF - Current clock root OFF setting
 *  0b0..Clock is running.
 *  0b1..Clock is turned off.
 */
#define CCM_STATUS0_OFF(x)                       (((uint32_t)(((uint32_t)(x)) << CCM_STATUS0_OFF_SHIFT)) & CCM_STATUS0_OFF_MASK)

#define CCM_STATUS0_SND_DIV_MASK                 (0xFF0000U)
#define CCM_STATUS0_SND_DIV_SHIFT                (16U)
/*! SND_DIV - Current clock root the second DIV setting */
#define CCM_STATUS0_SND_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_STATUS0_SND_DIV_SHIFT)) & CCM_STATUS0_SND_DIV_MASK)

#define CCM_STATUS0_CLKSRC0_in_use_MASK          (0x1000000U)
#define CCM_STATUS0_CLKSRC0_in_use_SHIFT         (24U)
/*! CLKSRC0_in_use - Clock source0 in_use status */
#define CCM_STATUS0_CLKSRC0_in_use(x)            (((uint32_t)(((uint32_t)(x)) << CCM_STATUS0_CLKSRC0_in_use_SHIFT)) & CCM_STATUS0_CLKSRC0_in_use_MASK)

#define CCM_STATUS0_CLKSRC1_in_use_MASK          (0x2000000U)
#define CCM_STATUS0_CLKSRC1_in_use_SHIFT         (25U)
/*! CLKSRC1_in_use - Clock source1 in_use status */
#define CCM_STATUS0_CLKSRC1_in_use(x)            (((uint32_t)(((uint32_t)(x)) << CCM_STATUS0_CLKSRC1_in_use_SHIFT)) & CCM_STATUS0_CLKSRC1_in_use_MASK)

#define CCM_STATUS0_CLKSRC2_in_use_MASK          (0x4000000U)
#define CCM_STATUS0_CLKSRC2_in_use_SHIFT         (26U)
/*! CLKSRC2_in_use - Clock source2 in_use status */
#define CCM_STATUS0_CLKSRC2_in_use(x)            (((uint32_t)(((uint32_t)(x)) << CCM_STATUS0_CLKSRC2_in_use_SHIFT)) & CCM_STATUS0_CLKSRC2_in_use_MASK)

#define CCM_STATUS0_CLKSRC3_in_use_MASK          (0x8000000U)
#define CCM_STATUS0_CLKSRC3_in_use_SHIFT         (27U)
/*! CLKSRC3_in_use - Clock source3 in_use status */
#define CCM_STATUS0_CLKSRC3_in_use(x)            (((uint32_t)(((uint32_t)(x)) << CCM_STATUS0_CLKSRC3_in_use_SHIFT)) & CCM_STATUS0_CLKSRC3_in_use_MASK)
/*! @} */

/* The count of CCM_STATUS0 */
#define CCM_STATUS0_COUNT                        (49U)

/*! @name STATUS1 - Clock Root Hardware Status */
/*! @{ */

#define CCM_STATUS1_MUX_NUM_MASK                 (0xFU)
#define CCM_STATUS1_MUX_NUM_SHIFT                (0U)
/*! MUX_NUM - Current clock root MUX_NUM */
#define CCM_STATUS1_MUX_NUM(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_STATUS1_MUX_NUM_SHIFT)) & CCM_STATUS1_MUX_NUM_MASK)

#define CCM_STATUS1_GLITCH_FREE_MASK             (0x10U)
#define CCM_STATUS1_GLITCH_FREE_SHIFT            (4U)
/*! GLITCH_FREE - Current clock root MUX type
 *  0b0..Normal MUX.
 *  0b1..Glitchless MUX.
 */
#define CCM_STATUS1_GLITCH_FREE(x)               (((uint32_t)(((uint32_t)(x)) << CCM_STATUS1_GLITCH_FREE_SHIFT)) & CCM_STATUS1_GLITCH_FREE_MASK)

#define CCM_STATUS1_DIVIDER_PRESENT_MASK         (0x100U)
#define CCM_STATUS1_DIVIDER_PRESENT_SHIFT        (8U)
/*! DIVIDER_PRESENT - Current clock root the the first divider present
 *  0b0..No first divider in slice.
 *  0b1..The first divider is present in slice.
 */
#define CCM_STATUS1_DIVIDER_PRESENT(x)           (((uint32_t)(((uint32_t)(x)) << CCM_STATUS1_DIVIDER_PRESENT_SHIFT)) & CCM_STATUS1_DIVIDER_PRESENT_MASK)

#define CCM_STATUS1_DIV_WIDTH_MASK               (0xF000U)
#define CCM_STATUS1_DIV_WIDTH_SHIFT              (12U)
/*! DIV_WIDTH - Current clock root the first DIV width */
#define CCM_STATUS1_DIV_WIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_STATUS1_DIV_WIDTH_SHIFT)) & CCM_STATUS1_DIV_WIDTH_MASK)

#define CCM_STATUS1_SECOND_DIVIDER_PRESENT_MASK  (0x10000U)
#define CCM_STATUS1_SECOND_DIVIDER_PRESENT_SHIFT (16U)
/*! SECOND_DIVIDER_PRESENT - Current clock root the second divider present
 *  0b0..No second divider in slice.
 *  0b1..The second divider is present in slice.
 */
#define CCM_STATUS1_SECOND_DIVIDER_PRESENT(x)    (((uint32_t)(((uint32_t)(x)) << CCM_STATUS1_SECOND_DIVIDER_PRESENT_SHIFT)) & CCM_STATUS1_SECOND_DIVIDER_PRESENT_MASK)

#define CCM_STATUS1_SECOND_DIV_HSK_PRESENT_MASK  (0x20000U)
#define CCM_STATUS1_SECOND_DIV_HSK_PRESENT_SHIFT (17U)
/*! SECOND_DIV_HSK_PRESENT - Current clock root the second divider halt handshake present
 *  0b0..No second divider halt handshake in slice.
 *  0b1..The second divider halt handshake is present in slice.
 */
#define CCM_STATUS1_SECOND_DIV_HSK_PRESENT(x)    (((uint32_t)(((uint32_t)(x)) << CCM_STATUS1_SECOND_DIV_HSK_PRESENT_SHIFT)) & CCM_STATUS1_SECOND_DIV_HSK_PRESENT_MASK)

#define CCM_STATUS1_SECOND_DIVIDER_CONFIG_MASK   (0x40000U)
#define CCM_STATUS1_SECOND_DIVIDER_CONFIG_SHIFT  (18U)
/*! SECOND_DIVIDER_CONFIG - Current clock root the second divider value setting
 *  0b0..The second divider value is fixed: the fixed value is field SECOND_DIVIDER_VALUE of this register.
 *  0b1..The second divider value is configurable, by writing SND_DIV of SLICE_CTRL register.
 */
#define CCM_STATUS1_SECOND_DIVIDER_CONFIG(x)     (((uint32_t)(((uint32_t)(x)) << CCM_STATUS1_SECOND_DIVIDER_CONFIG_SHIFT)) & CCM_STATUS1_SECOND_DIVIDER_CONFIG_MASK)

#define CCM_STATUS1_SECOND_DIV_WIDTH_MASK        (0xF00000U)
#define CCM_STATUS1_SECOND_DIV_WIDTH_SHIFT       (20U)
/*! SECOND_DIV_WIDTH - Current clock root the second DIV width */
#define CCM_STATUS1_SECOND_DIV_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << CCM_STATUS1_SECOND_DIV_WIDTH_SHIFT)) & CCM_STATUS1_SECOND_DIV_WIDTH_MASK)

#define CCM_STATUS1_SECOND_DIVIDER_VALUE_MASK    (0xFF000000U)
#define CCM_STATUS1_SECOND_DIVIDER_VALUE_SHIFT   (24U)
/*! SECOND_DIVIDER_VALUE - Current clock root the second DIV value */
#define CCM_STATUS1_SECOND_DIVIDER_VALUE(x)      (((uint32_t)(((uint32_t)(x)) << CCM_STATUS1_SECOND_DIVIDER_VALUE_SHIFT)) & CCM_STATUS1_SECOND_DIVIDER_VALUE_MASK)
/*! @} */

/* The count of CCM_STATUS1 */
#define CCM_STATUS1_COUNT                        (49U)

/*! @name ACCESS_CTRL - Clock Gating Root Access Control */
/*! @{ */

#define CCM_ACCESS_CTRL_DMN_ACC_CTRL_MASK        (0xFU)
#define CCM_ACCESS_CTRL_DMN_ACC_CTRL_SHIFT       (0U)
/*! DMN_ACC_CTRL - Domain access control settings */
#define CCM_ACCESS_CTRL_DMN_ACC_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DMN_ACC_CTRL_SHIFT)) & CCM_ACCESS_CTRL_DMN_ACC_CTRL_MASK)

#define CCM_ACCESS_CTRL_ALLOW_USER_MASK          (0x10000U)
#define CCM_ACCESS_CTRL_ALLOW_USER_SHIFT         (16U)
/*! ALLOW_USER - User access permission
 *  0b0..Clock Gating Root settings cannot be changed in the user mode.
 *  0b1..Clock Gating Root settings can be changed in the user mode.
 */
#define CCM_ACCESS_CTRL_ALLOW_USER(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ALLOW_USER_SHIFT)) & CCM_ACCESS_CTRL_ALLOW_USER_MASK)

#define CCM_ACCESS_CTRL_ALLOW_NS_MASK            (0x20000U)
#define CCM_ACCESS_CTRL_ALLOW_NS_SHIFT           (17U)
/*! ALLOW_NS - Non-secure access permission
 *  0b0..Cannot be changed in the non-secure mode.
 *  0b1..Can be changed in the non-secure mode.
 */
#define CCM_ACCESS_CTRL_ALLOW_NS(x)              (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ALLOW_NS_SHIFT)) & CCM_ACCESS_CTRL_ALLOW_NS_MASK)

#define CCM_ACCESS_CTRL_LOCK_CTRL_MASK           (0x80000000U)
#define CCM_ACCESS_CTRL_LOCK_CTRL_SHIFT          (31U)
/*! LOCK_CTRL - Lock access permission settings
 *  0b0..Access permission settings are not locked.
 *  0b1..Access permission settings are locked.
 */
#define CCM_ACCESS_CTRL_LOCK_CTRL(x)             (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_LOCK_CTRL_SHIFT)) & CCM_ACCESS_CTRL_LOCK_CTRL_MASK)
/*! @} */

/* The count of CCM_ACCESS_CTRL */
#define CCM_CGC_ROOT_ACCESS_CTRL_COUNT           (75U)

/*! @name SLICE_CONTROL - Clock Gating Root Control */
/*! @{ */

#define CCM_SLICE_CONTROL_LPCG_CFG_MASK          (0x3U)
#define CCM_SLICE_CONTROL_LPCG_CFG_SHIFT         (0U)
/*! LPCG_CFG - LPCG configuration. */
#define CCM_SLICE_CONTROL_LPCG_CFG(x)            (((uint32_t)(((uint32_t)(x)) << CCM_SLICE_CONTROL_LPCG_CFG_SHIFT)) & CCM_SLICE_CONTROL_LPCG_CFG_MASK)

#define CCM_SLICE_CONTROL_HSK_BYPASS_MASK        (0x100U)
#define CCM_SLICE_CONTROL_HSK_BYPASS_SHIFT       (8U)
/*! HSK_BYPASS - Bypass handshake.
 *  0b0..Handshake is not bypassed.
 *  0b1..Handshake is bypassed.
 */
#define CCM_SLICE_CONTROL_HSK_BYPASS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_SLICE_CONTROL_HSK_BYPASS_SHIFT)) & CCM_SLICE_CONTROL_HSK_BYPASS_MASK)

#define CCM_SLICE_CONTROL_FORCE_HSK_MASK         (0x200U)
#define CCM_SLICE_CONTROL_FORCE_HSK_SHIFT        (9U)
/*! FORCE_HSK - Force handshake.
 *  0b0..Does not force the low power handshake.
 *  0b1..Forces the low power handshake.
 */
#define CCM_SLICE_CONTROL_FORCE_HSK(x)           (((uint32_t)(((uint32_t)(x)) << CCM_SLICE_CONTROL_FORCE_HSK_SHIFT)) & CCM_SLICE_CONTROL_FORCE_HSK_MASK)

#define CCM_SLICE_CONTROL_HSK_SEL_MASK           (0x70000U)
#define CCM_SLICE_CONTROL_HSK_SEL_SHIFT          (16U)
/*! HSK_SEL - Handshake select. */
#define CCM_SLICE_CONTROL_HSK_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CCM_SLICE_CONTROL_HSK_SEL_SHIFT)) & CCM_SLICE_CONTROL_HSK_SEL_MASK)
/*! @} */

/* The count of CCM_SLICE_CONTROL */
#define CCM_CGC_ROOT_SLICE_CONTROL_COUNT         (75U)

/*! @name STATUS - Clock Gating Root Working Status */
/*! @{ */

#define CCM_STATUS_FUN_CLK_ENABLE_MASK           (0x1U)
#define CCM_STATUS_FUN_CLK_ENABLE_SHIFT          (0U)
/*! FUN_CLK_ENABLE - Functional clock enable
 *  0b0..Functional clock is disabled.
 *  0b1..Functional clock is enabled.
 */
#define CCM_STATUS_FUN_CLK_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_STATUS_FUN_CLK_ENABLE_SHIFT)) & CCM_STATUS_FUN_CLK_ENABLE_MASK)

#define CCM_STATUS_BUS_CLK_ENABLE_MASK           (0x2U)
#define CCM_STATUS_BUS_CLK_ENABLE_SHIFT          (1U)
/*! BUS_CLK_ENABLE - Bus clock enable
 *  0b0..Bus clock is disabled.
 *  0b1..Bus clock is enabled.
 */
#define CCM_STATUS_BUS_CLK_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_STATUS_BUS_CLK_ENABLE_SHIFT)) & CCM_STATUS_BUS_CLK_ENABLE_MASK)

#define CCM_STATUS_DEFAULT_CLKON_MASK            (0x10000U)
#define CCM_STATUS_DEFAULT_CLKON_SHIFT           (16U)
/*! DEFAULT_CLKON - DEFAULT_CLKON status */
#define CCM_STATUS_DEFAULT_CLKON(x)              (((uint32_t)(((uint32_t)(x)) << CCM_STATUS_DEFAULT_CLKON_SHIFT)) & CCM_STATUS_DEFAULT_CLKON_MASK)

#define CCM_STATUS_HSK_TYPE_MASK                 (0x300000U)
#define CCM_STATUS_HSK_TYPE_SHIFT                (20U)
/*! HSK_TYPE - HSK_TYPE status
 *  0b00..no handshake
 *  0b01..QCH
 *  0b10..stop req/ack
 *  0b11..stop req only (no ack)
 */
#define CCM_STATUS_HSK_TYPE(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_STATUS_HSK_TYPE_SHIFT)) & CCM_STATUS_HSK_TYPE_MASK)

#define CCM_STATUS_HSK_NUM_MASK                  (0xF000000U)
#define CCM_STATUS_HSK_NUM_SHIFT                 (24U)
/*! HSK_NUM - HSK_NUM status */
#define CCM_STATUS_HSK_NUM(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_STATUS_HSK_NUM_SHIFT)) & CCM_STATUS_HSK_NUM_MASK)
/*! @} */

/* The count of CCM_STATUS */
#define CCM_STATUS_COUNT                         (75U)


/*!
 * @}
 */ /* end of group CCM_Register_Masks */


/*!
 * @}
 */ /* end of group CCM_Peripheral_Access_Layer */


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


#endif  /* PERI_CCM_H_ */

