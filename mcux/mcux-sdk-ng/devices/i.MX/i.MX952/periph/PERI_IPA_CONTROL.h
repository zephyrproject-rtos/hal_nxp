/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IPA_CONTROL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IPA_CONTROL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IPA_CONTROL
 *
 * CMSIS Peripheral Access Layer for IPA_CONTROL
 */

#if !defined(PERI_IPA_CONTROL_H_)
#define PERI_IPA_CONTROL_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- IPA_CONTROL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IPA_CONTROL_Peripheral_Access_Layer IPA_CONTROL Peripheral Access Layer
 * @{
 */

/** IPA_CONTROL - Register Layout Typedef */
typedef struct {
  __IO uint32_t COMMAND;                           /**< COMMAND, offset: 0x0 */
  __I  uint32_t STATUS;                            /**< STATUS, offset: 0x4 */
  __IO uint32_t TIMER;                             /**< TIMER, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SELECT_CSHW_LO;                    /**< SELECT_CSHW_LO, offset: 0x10 */
  __IO uint32_t SELECT_CSHW_HI;                    /**< SELECT_CSHW_HI, offset: 0x14 */
  __IO uint32_t SELECT_MEMSYS_LO;                  /**< SELECT_MEMSYS_LO, offset: 0x18 */
  __IO uint32_t SELECT_MEMSYS_HI;                  /**< SELECT_MEMSYS_HI, offset: 0x1C */
  __IO uint32_t SELECT_TILER_LO;                   /**< SELECT_TILER_LO, offset: 0x20 */
  __IO uint32_t SELECT_TILER_HI;                   /**< SELECT_TILER_HI, offset: 0x24 */
  __IO uint32_t SELECT_SHADER_LO;                  /**< SELECT_SHADER_LO, offset: 0x28 */
  __IO uint32_t SELECT_SHADER_HI;                  /**< SELECT_SHADER_HI, offset: 0x2C */
       uint8_t RESERVED_1[208];
  __I  uint32_t VALUE_CSHW_N_LO_0;                 /**< VALUE_CSHW_N_LO_0, offset: 0x100 */
  __I  uint32_t VALUE_CSHW_N_HI_0;                 /**< VALUE_CSHW_N_HI_0, offset: 0x104 */
  __I  uint32_t VALUE_CSHW_N_LO_1;                 /**< VALUE_CSHW_N_LO_1, offset: 0x108 */
  __I  uint32_t VALUE_CSHW_N_HI_1;                 /**< VALUE_CSHW_N_HI_1, offset: 0x10C */
  __I  uint32_t VALUE_CSHW_N_LO_2;                 /**< VALUE_CSHW_N_LO_2, offset: 0x110 */
  __I  uint32_t VALUE_CSHW_N_HI_2;                 /**< VALUE_CSHW_N_HI_2, offset: 0x114 */
  __I  uint32_t VALUE_CSHW_N_LO_3;                 /**< VALUE_CSHW_N_LO_3, offset: 0x118 */
  __I  uint32_t VALUE_CSHW_N_HI_3;                 /**< VALUE_CSHW_N_HI_3, offset: 0x11C */
  __I  uint32_t VALUE_CSHW_N_LO_4;                 /**< VALUE_CSHW_N_LO_4, offset: 0x120 */
  __I  uint32_t VALUE_CSHW_N_HI_4;                 /**< VALUE_CSHW_N_HI_4, offset: 0x124 */
  __I  uint32_t VALUE_CSHW_N_LO_5;                 /**< VALUE_CSHW_N_LO_5, offset: 0x128 */
  __I  uint32_t VALUE_CSHW_N_HI_5;                 /**< VALUE_CSHW_N_HI_5, offset: 0x12C */
  __I  uint32_t VALUE_CSHW_N_LO_6;                 /**< VALUE_CSHW_N_LO_6, offset: 0x130 */
  __I  uint32_t VALUE_CSHW_N_HI_6;                 /**< VALUE_CSHW_N_HI_6, offset: 0x134 */
  __I  uint32_t VALUE_CSHW_N_LO_7;                 /**< VALUE_CSHW_N_LO_7, offset: 0x138 */
  __I  uint32_t VALUE_CSHW_N_HI_7;                 /**< VALUE_CSHW_N_HI_7, offset: 0x13C */
  __I  uint32_t VALUE_MEMSYS_N_LO_0;               /**< VALUE_MEMSYS_N_LO_0, offset: 0x140 */
  __I  uint32_t VALUE_MEMSYS_N_HI_0;               /**< VALUE_MEMSYS_N_HI_0, offset: 0x144 */
  __I  uint32_t VALUE_MEMSYS_N_LO_1;               /**< VALUE_MEMSYS_N_LO_1, offset: 0x148 */
  __I  uint32_t VALUE_MEMSYS_N_HI_1;               /**< VALUE_MEMSYS_N_HI_1, offset: 0x14C */
  __I  uint32_t VALUE_MEMSYS_N_LO_2;               /**< VALUE_MEMSYS_N_LO_2, offset: 0x150 */
  __I  uint32_t VALUE_MEMSYS_N_HI_2;               /**< VALUE_MEMSYS_N_HI_2, offset: 0x154 */
  __I  uint32_t VALUE_MEMSYS_N_LO_3;               /**< VALUE_MEMSYS_N_LO_3, offset: 0x158 */
  __I  uint32_t VALUE_MEMSYS_N_HI_3;               /**< VALUE_MEMSYS_N_HI_3, offset: 0x15C */
  __I  uint32_t VALUE_MEMSYS_N_LO_4;               /**< VALUE_MEMSYS_N_LO_4, offset: 0x160 */
  __I  uint32_t VALUE_MEMSYS_N_HI_4;               /**< VALUE_MEMSYS_N_HI_4, offset: 0x164 */
  __I  uint32_t VALUE_MEMSYS_N_LO_5;               /**< VALUE_MEMSYS_N_LO_5, offset: 0x168 */
  __I  uint32_t VALUE_MEMSYS_N_HI_5;               /**< VALUE_MEMSYS_N_HI_5, offset: 0x16C */
  __I  uint32_t VALUE_MEMSYS_N_LO_6;               /**< VALUE_MEMSYS_N_LO_6, offset: 0x170 */
  __I  uint32_t VALUE_MEMSYS_N_HI_6;               /**< VALUE_MEMSYS_N_HI_6, offset: 0x174 */
  __I  uint32_t VALUE_MEMSYS_N_LO_7;               /**< VALUE_MEMSYS_N_LO_7, offset: 0x178 */
  __I  uint32_t VALUE_MEMSYS_N_HI_7;               /**< VALUE_MEMSYS_N_HI_7, offset: 0x17C */
  __I  uint32_t VALUE_TILER_N_LO_0;                /**< VALUE_TILER_N_LO_0, offset: 0x180 */
  __I  uint32_t VALUE_TILER_N_HI_0;                /**< VALUE_TILER_N_HI_0, offset: 0x184 */
  __I  uint32_t VALUE_TILER_N_LO_1;                /**< VALUE_TILER_N_LO_1, offset: 0x188 */
  __I  uint32_t VALUE_TILER_N_HI_1;                /**< VALUE_TILER_N_HI_1, offset: 0x18C */
  __I  uint32_t VALUE_TILER_N_LO_2;                /**< VALUE_TILER_N_LO_2, offset: 0x190 */
  __I  uint32_t VALUE_TILER_N_HI_2;                /**< VALUE_TILER_N_HI_2, offset: 0x194 */
  __I  uint32_t VALUE_TILER_N_LO_3;                /**< VALUE_TILER_N_LO_3, offset: 0x198 */
  __I  uint32_t VALUE_TILER_N_HI_3;                /**< VALUE_TILER_N_HI_3, offset: 0x19C */
  __I  uint32_t VALUE_TILER_N_LO_4;                /**< VALUE_TILER_N_LO_4, offset: 0x1A0 */
  __I  uint32_t VALUE_TILER_N_HI_4;                /**< VALUE_TILER_N_HI_4, offset: 0x1A4 */
  __I  uint32_t VALUE_TILER_N_LO_5;                /**< VALUE_TILER_N_LO_5, offset: 0x1A8 */
  __I  uint32_t VALUE_TILER_N_HI_5;                /**< VALUE_TILER_N_HI_5, offset: 0x1AC */
  __I  uint32_t VALUE_TILER_N_LO_6;                /**< VALUE_TILER_N_LO_6, offset: 0x1B0 */
  __I  uint32_t VALUE_TILER_N_HI_6;                /**< VALUE_TILER_N_HI_6, offset: 0x1B4 */
  __I  uint32_t VALUE_TILER_N_LO_7;                /**< VALUE_TILER_N_LO_7, offset: 0x1B8 */
  __I  uint32_t VALUE_TILER_N_HI_7;                /**< VALUE_TILER_N_HI_7, offset: 0x1BC */
  __I  uint32_t VALUE_SHADER_N_LO_0;               /**< VALUE_SHADER_N_LO_0, offset: 0x1C0 */
  __I  uint32_t VALUE_SHADER_N_HI_0;               /**< VALUE_SHADER_N_HI_0, offset: 0x1C4 */
  __I  uint32_t VALUE_SHADER_N_LO_1;               /**< VALUE_SHADER_N_LO_1, offset: 0x1C8 */
  __I  uint32_t VALUE_SHADER_N_HI_1;               /**< VALUE_SHADER_N_HI_1, offset: 0x1CC */
  __I  uint32_t VALUE_SHADER_N_LO_2;               /**< VALUE_SHADER_N_LO_2, offset: 0x1D0 */
  __I  uint32_t VALUE_SHADER_N_HI_2;               /**< VALUE_SHADER_N_HI_2, offset: 0x1D4 */
  __I  uint32_t VALUE_SHADER_N_LO_3;               /**< VALUE_SHADER_N_LO_3, offset: 0x1D8 */
  __I  uint32_t VALUE_SHADER_N_HI_3;               /**< VALUE_SHADER_N_HI_3, offset: 0x1DC */
  __I  uint32_t VALUE_SHADER_N_LO_4;               /**< VALUE_SHADER_N_LO_4, offset: 0x1E0 */
  __I  uint32_t VALUE_SHADER_N_HI_4;               /**< VALUE_SHADER_N_HI_4, offset: 0x1E4 */
  __I  uint32_t VALUE_SHADER_N_LO_5;               /**< VALUE_SHADER_N_LO_5, offset: 0x1E8 */
  __I  uint32_t VALUE_SHADER_N_HI_5;               /**< VALUE_SHADER_N_HI_5, offset: 0x1EC */
  __I  uint32_t VALUE_SHADER_N_LO_6;               /**< VALUE_SHADER_N_LO_6, offset: 0x1F0 */
  __I  uint32_t VALUE_SHADER_N_HI_6;               /**< VALUE_SHADER_N_HI_6, offset: 0x1F4 */
  __I  uint32_t VALUE_SHADER_N_LO_7;               /**< VALUE_SHADER_N_LO_7, offset: 0x1F8 */
  __I  uint32_t VALUE_SHADER_N_HI_7;               /**< VALUE_SHADER_N_HI_7, offset: 0x1FC */
} IPA_CONTROL_Type;

/* ----------------------------------------------------------------------------
   -- IPA_CONTROL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IPA_CONTROL_Register_Masks IPA_CONTROL Register Masks
 * @{
 */

/*! @name COMMAND - COMMAND */
/*! @{ */

#define IPA_CONTROL_COMMAND_command_MASK         (0xFFU)
#define IPA_CONTROL_COMMAND_command_SHIFT        (0U)
/*! command - command
 *  0b00000000..
 *  0b00000001..
 *  0b00000010..
 *  0b00000011..
 *  0b00000100..
 *  0b00000101..
 */
#define IPA_CONTROL_COMMAND_command(x)           (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_COMMAND_command_SHIFT)) & IPA_CONTROL_COMMAND_command_MASK)

#define IPA_CONTROL_COMMAND_reserved_word0_bit8_width24_MASK (0xFFFFFF00U)
#define IPA_CONTROL_COMMAND_reserved_word0_bit8_width24_SHIFT (8U)
/*! reserved_word0_bit8_width24 - reserved_word0_bit8_width24 */
#define IPA_CONTROL_COMMAND_reserved_word0_bit8_width24(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_COMMAND_reserved_word0_bit8_width24_SHIFT)) & IPA_CONTROL_COMMAND_reserved_word0_bit8_width24_MASK)
/*! @} */

/*! @name STATUS - STATUS */
/*! @{ */

#define IPA_CONTROL_STATUS_command_active_MASK   (0x1U)
#define IPA_CONTROL_STATUS_command_active_SHIFT  (0U)
/*! command_active - command_active */
#define IPA_CONTROL_STATUS_command_active(x)     (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_STATUS_command_active_SHIFT)) & IPA_CONTROL_STATUS_command_active_MASK)

#define IPA_CONTROL_STATUS_timer_active_MASK     (0x2U)
#define IPA_CONTROL_STATUS_timer_active_SHIFT    (1U)
/*! timer_active - timer_active */
#define IPA_CONTROL_STATUS_timer_active(x)       (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_STATUS_timer_active_SHIFT)) & IPA_CONTROL_STATUS_timer_active_MASK)

#define IPA_CONTROL_STATUS_auto_active_MASK      (0x4U)
#define IPA_CONTROL_STATUS_auto_active_SHIFT     (2U)
/*! auto_active - auto_active */
#define IPA_CONTROL_STATUS_auto_active(x)        (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_STATUS_auto_active_SHIFT)) & IPA_CONTROL_STATUS_auto_active_MASK)

#define IPA_CONTROL_STATUS_reserved_word0_bit3_width5_MASK (0xF8U)
#define IPA_CONTROL_STATUS_reserved_word0_bit3_width5_SHIFT (3U)
/*! reserved_word0_bit3_width5 - reserved_word0_bit3_width5 */
#define IPA_CONTROL_STATUS_reserved_word0_bit3_width5(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_STATUS_reserved_word0_bit3_width5_SHIFT)) & IPA_CONTROL_STATUS_reserved_word0_bit3_width5_MASK)

#define IPA_CONTROL_STATUS_protected_mode_MASK   (0x100U)
#define IPA_CONTROL_STATUS_protected_mode_SHIFT  (8U)
/*! protected_mode - protected_mode */
#define IPA_CONTROL_STATUS_protected_mode(x)     (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_STATUS_protected_mode_SHIFT)) & IPA_CONTROL_STATUS_protected_mode_MASK)

#define IPA_CONTROL_STATUS_reset_MASK            (0x200U)
#define IPA_CONTROL_STATUS_reset_SHIFT           (9U)
/*! reset - reset */
#define IPA_CONTROL_STATUS_reset(x)              (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_STATUS_reset_SHIFT)) & IPA_CONTROL_STATUS_reset_MASK)

#define IPA_CONTROL_STATUS_reserved_word0_bit10_width21_MASK (0x7FFFFC00U)
#define IPA_CONTROL_STATUS_reserved_word0_bit10_width21_SHIFT (10U)
/*! reserved_word0_bit10_width21 - reserved_word0_bit10_width21 */
#define IPA_CONTROL_STATUS_reserved_word0_bit10_width21(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_STATUS_reserved_word0_bit10_width21_SHIFT)) & IPA_CONTROL_STATUS_reserved_word0_bit10_width21_MASK)

#define IPA_CONTROL_STATUS_timer_enabled_MASK    (0x80000000U)
#define IPA_CONTROL_STATUS_timer_enabled_SHIFT   (31U)
/*! timer_enabled - timer_enabled */
#define IPA_CONTROL_STATUS_timer_enabled(x)      (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_STATUS_timer_enabled_SHIFT)) & IPA_CONTROL_STATUS_timer_enabled_MASK)
/*! @} */

/*! @name TIMER - TIMER */
/*! @{ */

#define IPA_CONTROL_TIMER_timeout_MASK           (0xFFFFFFFFU)
#define IPA_CONTROL_TIMER_timeout_SHIFT          (0U)
/*! timeout - timeout */
#define IPA_CONTROL_TIMER_timeout(x)             (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_TIMER_timeout_SHIFT)) & IPA_CONTROL_TIMER_timeout_MASK)
/*! @} */

/*! @name SELECT_CSHW_LO - SELECT_CSHW_LO */
/*! @{ */

#define IPA_CONTROL_SELECT_CSHW_LO_select0_MASK  (0xFFU)
#define IPA_CONTROL_SELECT_CSHW_LO_select0_SHIFT (0U)
/*! select0 - select0 */
#define IPA_CONTROL_SELECT_CSHW_LO_select0(x)    (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_CSHW_LO_select0_SHIFT)) & IPA_CONTROL_SELECT_CSHW_LO_select0_MASK)

#define IPA_CONTROL_SELECT_CSHW_LO_select1_MASK  (0xFF00U)
#define IPA_CONTROL_SELECT_CSHW_LO_select1_SHIFT (8U)
/*! select1 - select1 */
#define IPA_CONTROL_SELECT_CSHW_LO_select1(x)    (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_CSHW_LO_select1_SHIFT)) & IPA_CONTROL_SELECT_CSHW_LO_select1_MASK)

#define IPA_CONTROL_SELECT_CSHW_LO_select2_MASK  (0xFF0000U)
#define IPA_CONTROL_SELECT_CSHW_LO_select2_SHIFT (16U)
/*! select2 - select2 */
#define IPA_CONTROL_SELECT_CSHW_LO_select2(x)    (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_CSHW_LO_select2_SHIFT)) & IPA_CONTROL_SELECT_CSHW_LO_select2_MASK)

#define IPA_CONTROL_SELECT_CSHW_LO_select3_MASK  (0xFF000000U)
#define IPA_CONTROL_SELECT_CSHW_LO_select3_SHIFT (24U)
/*! select3 - select3 */
#define IPA_CONTROL_SELECT_CSHW_LO_select3(x)    (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_CSHW_LO_select3_SHIFT)) & IPA_CONTROL_SELECT_CSHW_LO_select3_MASK)
/*! @} */

/*! @name SELECT_CSHW_HI - SELECT_CSHW_HI */
/*! @{ */

#define IPA_CONTROL_SELECT_CSHW_HI_select4_MASK  (0xFFU)
#define IPA_CONTROL_SELECT_CSHW_HI_select4_SHIFT (0U)
/*! select4 - select4 */
#define IPA_CONTROL_SELECT_CSHW_HI_select4(x)    (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_CSHW_HI_select4_SHIFT)) & IPA_CONTROL_SELECT_CSHW_HI_select4_MASK)

#define IPA_CONTROL_SELECT_CSHW_HI_select5_MASK  (0xFF00U)
#define IPA_CONTROL_SELECT_CSHW_HI_select5_SHIFT (8U)
/*! select5 - select5 */
#define IPA_CONTROL_SELECT_CSHW_HI_select5(x)    (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_CSHW_HI_select5_SHIFT)) & IPA_CONTROL_SELECT_CSHW_HI_select5_MASK)

#define IPA_CONTROL_SELECT_CSHW_HI_select6_MASK  (0xFF0000U)
#define IPA_CONTROL_SELECT_CSHW_HI_select6_SHIFT (16U)
/*! select6 - select6 */
#define IPA_CONTROL_SELECT_CSHW_HI_select6(x)    (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_CSHW_HI_select6_SHIFT)) & IPA_CONTROL_SELECT_CSHW_HI_select6_MASK)

#define IPA_CONTROL_SELECT_CSHW_HI_select7_MASK  (0xFF000000U)
#define IPA_CONTROL_SELECT_CSHW_HI_select7_SHIFT (24U)
/*! select7 - select7 */
#define IPA_CONTROL_SELECT_CSHW_HI_select7(x)    (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_CSHW_HI_select7_SHIFT)) & IPA_CONTROL_SELECT_CSHW_HI_select7_MASK)
/*! @} */

/*! @name SELECT_MEMSYS_LO - SELECT_MEMSYS_LO */
/*! @{ */

#define IPA_CONTROL_SELECT_MEMSYS_LO_select0_MASK (0xFFU)
#define IPA_CONTROL_SELECT_MEMSYS_LO_select0_SHIFT (0U)
/*! select0 - select0 */
#define IPA_CONTROL_SELECT_MEMSYS_LO_select0(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_MEMSYS_LO_select0_SHIFT)) & IPA_CONTROL_SELECT_MEMSYS_LO_select0_MASK)

#define IPA_CONTROL_SELECT_MEMSYS_LO_select1_MASK (0xFF00U)
#define IPA_CONTROL_SELECT_MEMSYS_LO_select1_SHIFT (8U)
/*! select1 - select1 */
#define IPA_CONTROL_SELECT_MEMSYS_LO_select1(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_MEMSYS_LO_select1_SHIFT)) & IPA_CONTROL_SELECT_MEMSYS_LO_select1_MASK)

#define IPA_CONTROL_SELECT_MEMSYS_LO_select2_MASK (0xFF0000U)
#define IPA_CONTROL_SELECT_MEMSYS_LO_select2_SHIFT (16U)
/*! select2 - select2 */
#define IPA_CONTROL_SELECT_MEMSYS_LO_select2(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_MEMSYS_LO_select2_SHIFT)) & IPA_CONTROL_SELECT_MEMSYS_LO_select2_MASK)

#define IPA_CONTROL_SELECT_MEMSYS_LO_select3_MASK (0xFF000000U)
#define IPA_CONTROL_SELECT_MEMSYS_LO_select3_SHIFT (24U)
/*! select3 - select3 */
#define IPA_CONTROL_SELECT_MEMSYS_LO_select3(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_MEMSYS_LO_select3_SHIFT)) & IPA_CONTROL_SELECT_MEMSYS_LO_select3_MASK)
/*! @} */

/*! @name SELECT_MEMSYS_HI - SELECT_MEMSYS_HI */
/*! @{ */

#define IPA_CONTROL_SELECT_MEMSYS_HI_select4_MASK (0xFFU)
#define IPA_CONTROL_SELECT_MEMSYS_HI_select4_SHIFT (0U)
/*! select4 - select4 */
#define IPA_CONTROL_SELECT_MEMSYS_HI_select4(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_MEMSYS_HI_select4_SHIFT)) & IPA_CONTROL_SELECT_MEMSYS_HI_select4_MASK)

#define IPA_CONTROL_SELECT_MEMSYS_HI_select5_MASK (0xFF00U)
#define IPA_CONTROL_SELECT_MEMSYS_HI_select5_SHIFT (8U)
/*! select5 - select5 */
#define IPA_CONTROL_SELECT_MEMSYS_HI_select5(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_MEMSYS_HI_select5_SHIFT)) & IPA_CONTROL_SELECT_MEMSYS_HI_select5_MASK)

#define IPA_CONTROL_SELECT_MEMSYS_HI_select6_MASK (0xFF0000U)
#define IPA_CONTROL_SELECT_MEMSYS_HI_select6_SHIFT (16U)
/*! select6 - select6 */
#define IPA_CONTROL_SELECT_MEMSYS_HI_select6(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_MEMSYS_HI_select6_SHIFT)) & IPA_CONTROL_SELECT_MEMSYS_HI_select6_MASK)

#define IPA_CONTROL_SELECT_MEMSYS_HI_select7_MASK (0xFF000000U)
#define IPA_CONTROL_SELECT_MEMSYS_HI_select7_SHIFT (24U)
/*! select7 - select7 */
#define IPA_CONTROL_SELECT_MEMSYS_HI_select7(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_MEMSYS_HI_select7_SHIFT)) & IPA_CONTROL_SELECT_MEMSYS_HI_select7_MASK)
/*! @} */

/*! @name SELECT_TILER_LO - SELECT_TILER_LO */
/*! @{ */

#define IPA_CONTROL_SELECT_TILER_LO_select0_MASK (0xFFU)
#define IPA_CONTROL_SELECT_TILER_LO_select0_SHIFT (0U)
/*! select0 - select0 */
#define IPA_CONTROL_SELECT_TILER_LO_select0(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_TILER_LO_select0_SHIFT)) & IPA_CONTROL_SELECT_TILER_LO_select0_MASK)

#define IPA_CONTROL_SELECT_TILER_LO_select1_MASK (0xFF00U)
#define IPA_CONTROL_SELECT_TILER_LO_select1_SHIFT (8U)
/*! select1 - select1 */
#define IPA_CONTROL_SELECT_TILER_LO_select1(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_TILER_LO_select1_SHIFT)) & IPA_CONTROL_SELECT_TILER_LO_select1_MASK)

#define IPA_CONTROL_SELECT_TILER_LO_select2_MASK (0xFF0000U)
#define IPA_CONTROL_SELECT_TILER_LO_select2_SHIFT (16U)
/*! select2 - select2 */
#define IPA_CONTROL_SELECT_TILER_LO_select2(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_TILER_LO_select2_SHIFT)) & IPA_CONTROL_SELECT_TILER_LO_select2_MASK)

#define IPA_CONTROL_SELECT_TILER_LO_select3_MASK (0xFF000000U)
#define IPA_CONTROL_SELECT_TILER_LO_select3_SHIFT (24U)
/*! select3 - select3 */
#define IPA_CONTROL_SELECT_TILER_LO_select3(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_TILER_LO_select3_SHIFT)) & IPA_CONTROL_SELECT_TILER_LO_select3_MASK)
/*! @} */

/*! @name SELECT_TILER_HI - SELECT_TILER_HI */
/*! @{ */

#define IPA_CONTROL_SELECT_TILER_HI_select4_MASK (0xFFU)
#define IPA_CONTROL_SELECT_TILER_HI_select4_SHIFT (0U)
/*! select4 - select4 */
#define IPA_CONTROL_SELECT_TILER_HI_select4(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_TILER_HI_select4_SHIFT)) & IPA_CONTROL_SELECT_TILER_HI_select4_MASK)

#define IPA_CONTROL_SELECT_TILER_HI_select5_MASK (0xFF00U)
#define IPA_CONTROL_SELECT_TILER_HI_select5_SHIFT (8U)
/*! select5 - select5 */
#define IPA_CONTROL_SELECT_TILER_HI_select5(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_TILER_HI_select5_SHIFT)) & IPA_CONTROL_SELECT_TILER_HI_select5_MASK)

#define IPA_CONTROL_SELECT_TILER_HI_select6_MASK (0xFF0000U)
#define IPA_CONTROL_SELECT_TILER_HI_select6_SHIFT (16U)
/*! select6 - select6 */
#define IPA_CONTROL_SELECT_TILER_HI_select6(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_TILER_HI_select6_SHIFT)) & IPA_CONTROL_SELECT_TILER_HI_select6_MASK)

#define IPA_CONTROL_SELECT_TILER_HI_select7_MASK (0xFF000000U)
#define IPA_CONTROL_SELECT_TILER_HI_select7_SHIFT (24U)
/*! select7 - select7 */
#define IPA_CONTROL_SELECT_TILER_HI_select7(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_TILER_HI_select7_SHIFT)) & IPA_CONTROL_SELECT_TILER_HI_select7_MASK)
/*! @} */

/*! @name SELECT_SHADER_LO - SELECT_SHADER_LO */
/*! @{ */

#define IPA_CONTROL_SELECT_SHADER_LO_select0_MASK (0xFFU)
#define IPA_CONTROL_SELECT_SHADER_LO_select0_SHIFT (0U)
/*! select0 - select0 */
#define IPA_CONTROL_SELECT_SHADER_LO_select0(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_SHADER_LO_select0_SHIFT)) & IPA_CONTROL_SELECT_SHADER_LO_select0_MASK)

#define IPA_CONTROL_SELECT_SHADER_LO_select1_MASK (0xFF00U)
#define IPA_CONTROL_SELECT_SHADER_LO_select1_SHIFT (8U)
/*! select1 - select1 */
#define IPA_CONTROL_SELECT_SHADER_LO_select1(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_SHADER_LO_select1_SHIFT)) & IPA_CONTROL_SELECT_SHADER_LO_select1_MASK)

#define IPA_CONTROL_SELECT_SHADER_LO_select2_MASK (0xFF0000U)
#define IPA_CONTROL_SELECT_SHADER_LO_select2_SHIFT (16U)
/*! select2 - select2 */
#define IPA_CONTROL_SELECT_SHADER_LO_select2(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_SHADER_LO_select2_SHIFT)) & IPA_CONTROL_SELECT_SHADER_LO_select2_MASK)

#define IPA_CONTROL_SELECT_SHADER_LO_select3_MASK (0xFF000000U)
#define IPA_CONTROL_SELECT_SHADER_LO_select3_SHIFT (24U)
/*! select3 - select3 */
#define IPA_CONTROL_SELECT_SHADER_LO_select3(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_SHADER_LO_select3_SHIFT)) & IPA_CONTROL_SELECT_SHADER_LO_select3_MASK)
/*! @} */

/*! @name SELECT_SHADER_HI - SELECT_SHADER_HI */
/*! @{ */

#define IPA_CONTROL_SELECT_SHADER_HI_select4_MASK (0xFFU)
#define IPA_CONTROL_SELECT_SHADER_HI_select4_SHIFT (0U)
/*! select4 - select4 */
#define IPA_CONTROL_SELECT_SHADER_HI_select4(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_SHADER_HI_select4_SHIFT)) & IPA_CONTROL_SELECT_SHADER_HI_select4_MASK)

#define IPA_CONTROL_SELECT_SHADER_HI_select5_MASK (0xFF00U)
#define IPA_CONTROL_SELECT_SHADER_HI_select5_SHIFT (8U)
/*! select5 - select5 */
#define IPA_CONTROL_SELECT_SHADER_HI_select5(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_SHADER_HI_select5_SHIFT)) & IPA_CONTROL_SELECT_SHADER_HI_select5_MASK)

#define IPA_CONTROL_SELECT_SHADER_HI_select6_MASK (0xFF0000U)
#define IPA_CONTROL_SELECT_SHADER_HI_select6_SHIFT (16U)
/*! select6 - select6 */
#define IPA_CONTROL_SELECT_SHADER_HI_select6(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_SHADER_HI_select6_SHIFT)) & IPA_CONTROL_SELECT_SHADER_HI_select6_MASK)

#define IPA_CONTROL_SELECT_SHADER_HI_select7_MASK (0xFF000000U)
#define IPA_CONTROL_SELECT_SHADER_HI_select7_SHIFT (24U)
/*! select7 - select7 */
#define IPA_CONTROL_SELECT_SHADER_HI_select7(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_SELECT_SHADER_HI_select7_SHIFT)) & IPA_CONTROL_SELECT_SHADER_HI_select7_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_LO_0 - VALUE_CSHW_N_LO_0 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_LO_0_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_LO_0_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_LO_0_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_LO_0_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_LO_0_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_HI_0 - VALUE_CSHW_N_HI_0 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_HI_0_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_HI_0_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_HI_0_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_HI_0_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_HI_0_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_LO_1 - VALUE_CSHW_N_LO_1 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_LO_1_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_LO_1_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_LO_1_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_LO_1_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_LO_1_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_HI_1 - VALUE_CSHW_N_HI_1 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_HI_1_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_HI_1_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_HI_1_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_HI_1_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_HI_1_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_LO_2 - VALUE_CSHW_N_LO_2 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_LO_2_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_LO_2_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_LO_2_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_LO_2_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_LO_2_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_HI_2 - VALUE_CSHW_N_HI_2 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_HI_2_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_HI_2_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_HI_2_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_HI_2_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_HI_2_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_LO_3 - VALUE_CSHW_N_LO_3 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_LO_3_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_LO_3_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_LO_3_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_LO_3_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_LO_3_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_HI_3 - VALUE_CSHW_N_HI_3 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_HI_3_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_HI_3_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_HI_3_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_HI_3_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_HI_3_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_LO_4 - VALUE_CSHW_N_LO_4 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_LO_4_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_LO_4_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_LO_4_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_LO_4_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_LO_4_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_HI_4 - VALUE_CSHW_N_HI_4 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_HI_4_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_HI_4_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_HI_4_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_HI_4_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_HI_4_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_LO_5 - VALUE_CSHW_N_LO_5 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_LO_5_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_LO_5_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_LO_5_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_LO_5_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_LO_5_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_HI_5 - VALUE_CSHW_N_HI_5 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_HI_5_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_HI_5_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_HI_5_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_HI_5_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_HI_5_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_LO_6 - VALUE_CSHW_N_LO_6 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_LO_6_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_LO_6_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_LO_6_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_LO_6_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_LO_6_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_HI_6 - VALUE_CSHW_N_HI_6 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_HI_6_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_HI_6_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_HI_6_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_HI_6_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_HI_6_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_LO_7 - VALUE_CSHW_N_LO_7 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_LO_7_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_LO_7_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_LO_7_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_LO_7_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_LO_7_value_MASK)
/*! @} */

/*! @name VALUE_CSHW_N_HI_7 - VALUE_CSHW_N_HI_7 */
/*! @{ */

#define IPA_CONTROL_VALUE_CSHW_N_HI_7_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_CSHW_N_HI_7_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_CSHW_N_HI_7_value(x)   (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_CSHW_N_HI_7_value_SHIFT)) & IPA_CONTROL_VALUE_CSHW_N_HI_7_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_LO_0 - VALUE_MEMSYS_N_LO_0 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_LO_0_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_0_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_0_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_LO_0_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_LO_0_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_HI_0 - VALUE_MEMSYS_N_HI_0 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_HI_0_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_0_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_0_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_HI_0_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_HI_0_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_LO_1 - VALUE_MEMSYS_N_LO_1 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_LO_1_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_1_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_1_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_LO_1_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_LO_1_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_HI_1 - VALUE_MEMSYS_N_HI_1 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_HI_1_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_1_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_1_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_HI_1_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_HI_1_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_LO_2 - VALUE_MEMSYS_N_LO_2 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_LO_2_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_2_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_2_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_LO_2_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_LO_2_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_HI_2 - VALUE_MEMSYS_N_HI_2 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_HI_2_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_2_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_2_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_HI_2_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_HI_2_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_LO_3 - VALUE_MEMSYS_N_LO_3 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_LO_3_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_3_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_3_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_LO_3_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_LO_3_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_HI_3 - VALUE_MEMSYS_N_HI_3 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_HI_3_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_3_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_3_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_HI_3_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_HI_3_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_LO_4 - VALUE_MEMSYS_N_LO_4 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_LO_4_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_4_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_4_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_LO_4_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_LO_4_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_HI_4 - VALUE_MEMSYS_N_HI_4 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_HI_4_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_4_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_4_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_HI_4_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_HI_4_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_LO_5 - VALUE_MEMSYS_N_LO_5 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_LO_5_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_5_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_5_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_LO_5_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_LO_5_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_HI_5 - VALUE_MEMSYS_N_HI_5 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_HI_5_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_5_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_5_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_HI_5_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_HI_5_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_LO_6 - VALUE_MEMSYS_N_LO_6 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_LO_6_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_6_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_6_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_LO_6_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_LO_6_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_HI_6 - VALUE_MEMSYS_N_HI_6 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_HI_6_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_6_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_6_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_HI_6_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_HI_6_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_LO_7 - VALUE_MEMSYS_N_LO_7 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_LO_7_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_7_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_LO_7_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_LO_7_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_LO_7_value_MASK)
/*! @} */

/*! @name VALUE_MEMSYS_N_HI_7 - VALUE_MEMSYS_N_HI_7 */
/*! @{ */

#define IPA_CONTROL_VALUE_MEMSYS_N_HI_7_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_7_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_MEMSYS_N_HI_7_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_MEMSYS_N_HI_7_value_SHIFT)) & IPA_CONTROL_VALUE_MEMSYS_N_HI_7_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_LO_0 - VALUE_TILER_N_LO_0 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_LO_0_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_LO_0_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_LO_0_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_LO_0_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_LO_0_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_HI_0 - VALUE_TILER_N_HI_0 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_HI_0_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_HI_0_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_HI_0_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_HI_0_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_HI_0_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_LO_1 - VALUE_TILER_N_LO_1 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_LO_1_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_LO_1_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_LO_1_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_LO_1_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_LO_1_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_HI_1 - VALUE_TILER_N_HI_1 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_HI_1_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_HI_1_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_HI_1_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_HI_1_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_HI_1_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_LO_2 - VALUE_TILER_N_LO_2 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_LO_2_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_LO_2_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_LO_2_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_LO_2_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_LO_2_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_HI_2 - VALUE_TILER_N_HI_2 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_HI_2_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_HI_2_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_HI_2_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_HI_2_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_HI_2_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_LO_3 - VALUE_TILER_N_LO_3 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_LO_3_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_LO_3_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_LO_3_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_LO_3_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_LO_3_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_HI_3 - VALUE_TILER_N_HI_3 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_HI_3_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_HI_3_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_HI_3_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_HI_3_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_HI_3_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_LO_4 - VALUE_TILER_N_LO_4 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_LO_4_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_LO_4_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_LO_4_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_LO_4_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_LO_4_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_HI_4 - VALUE_TILER_N_HI_4 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_HI_4_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_HI_4_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_HI_4_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_HI_4_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_HI_4_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_LO_5 - VALUE_TILER_N_LO_5 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_LO_5_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_LO_5_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_LO_5_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_LO_5_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_LO_5_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_HI_5 - VALUE_TILER_N_HI_5 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_HI_5_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_HI_5_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_HI_5_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_HI_5_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_HI_5_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_LO_6 - VALUE_TILER_N_LO_6 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_LO_6_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_LO_6_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_LO_6_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_LO_6_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_LO_6_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_HI_6 - VALUE_TILER_N_HI_6 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_HI_6_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_HI_6_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_HI_6_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_HI_6_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_HI_6_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_LO_7 - VALUE_TILER_N_LO_7 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_LO_7_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_LO_7_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_LO_7_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_LO_7_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_LO_7_value_MASK)
/*! @} */

/*! @name VALUE_TILER_N_HI_7 - VALUE_TILER_N_HI_7 */
/*! @{ */

#define IPA_CONTROL_VALUE_TILER_N_HI_7_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_TILER_N_HI_7_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_TILER_N_HI_7_value(x)  (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_TILER_N_HI_7_value_SHIFT)) & IPA_CONTROL_VALUE_TILER_N_HI_7_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_LO_0 - VALUE_SHADER_N_LO_0 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_LO_0_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_LO_0_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_LO_0_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_LO_0_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_LO_0_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_HI_0 - VALUE_SHADER_N_HI_0 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_HI_0_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_HI_0_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_HI_0_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_HI_0_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_HI_0_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_LO_1 - VALUE_SHADER_N_LO_1 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_LO_1_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_LO_1_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_LO_1_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_LO_1_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_LO_1_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_HI_1 - VALUE_SHADER_N_HI_1 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_HI_1_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_HI_1_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_HI_1_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_HI_1_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_HI_1_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_LO_2 - VALUE_SHADER_N_LO_2 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_LO_2_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_LO_2_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_LO_2_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_LO_2_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_LO_2_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_HI_2 - VALUE_SHADER_N_HI_2 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_HI_2_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_HI_2_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_HI_2_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_HI_2_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_HI_2_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_LO_3 - VALUE_SHADER_N_LO_3 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_LO_3_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_LO_3_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_LO_3_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_LO_3_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_LO_3_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_HI_3 - VALUE_SHADER_N_HI_3 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_HI_3_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_HI_3_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_HI_3_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_HI_3_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_HI_3_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_LO_4 - VALUE_SHADER_N_LO_4 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_LO_4_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_LO_4_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_LO_4_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_LO_4_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_LO_4_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_HI_4 - VALUE_SHADER_N_HI_4 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_HI_4_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_HI_4_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_HI_4_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_HI_4_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_HI_4_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_LO_5 - VALUE_SHADER_N_LO_5 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_LO_5_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_LO_5_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_LO_5_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_LO_5_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_LO_5_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_HI_5 - VALUE_SHADER_N_HI_5 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_HI_5_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_HI_5_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_HI_5_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_HI_5_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_HI_5_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_LO_6 - VALUE_SHADER_N_LO_6 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_LO_6_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_LO_6_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_LO_6_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_LO_6_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_LO_6_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_HI_6 - VALUE_SHADER_N_HI_6 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_HI_6_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_HI_6_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_HI_6_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_HI_6_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_HI_6_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_LO_7 - VALUE_SHADER_N_LO_7 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_LO_7_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_LO_7_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_LO_7_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_LO_7_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_LO_7_value_MASK)
/*! @} */

/*! @name VALUE_SHADER_N_HI_7 - VALUE_SHADER_N_HI_7 */
/*! @{ */

#define IPA_CONTROL_VALUE_SHADER_N_HI_7_value_MASK (0xFFFFFFFFU)
#define IPA_CONTROL_VALUE_SHADER_N_HI_7_value_SHIFT (0U)
/*! value - value */
#define IPA_CONTROL_VALUE_SHADER_N_HI_7_value(x) (((uint32_t)(((uint32_t)(x)) << IPA_CONTROL_VALUE_SHADER_N_HI_7_value_SHIFT)) & IPA_CONTROL_VALUE_SHADER_N_HI_7_value_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IPA_CONTROL_Register_Masks */


/*!
 * @}
 */ /* end of group IPA_CONTROL_Peripheral_Access_Layer */


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


#endif  /* PERI_IPA_CONTROL_H_ */

