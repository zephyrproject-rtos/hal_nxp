/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for EMIOS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_EMIOS.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for EMIOS
 *
 * CMSIS Peripheral Access Layer for EMIOS
 */

#if !defined(PERI_EMIOS_H_)
#define PERI_EMIOS_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- EMIOS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EMIOS_Peripheral_Access_Layer EMIOS Peripheral Access Layer
 * @{
 */

/** EMIOS - Size of Registers Arrays */
#define EMIOS_CH_UC_UC_COUNT                      24u

/** EMIOS - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration, offset: 0x0 */
  __I  uint32_t GFLAG;                             /**< Global Flag, offset: 0x4 */
  __IO uint32_t OUDIS;                             /**< Output Update Disable, offset: 0x8 */
  __IO uint32_t UCDIS;                             /**< Disable Channel, offset: 0xC */
       uint8_t RESERVED_0[16];
  struct {                                         /* offset: 0x20, array step: 0x20 */
    __IO uint32_t A;                                 /**< UC A 0..UC A 23, array offset: 0x20, array step: 0x20 */
    __IO uint32_t B;                                 /**< UC B 0..UC B 23, array offset: 0x24, array step: 0x20 */
    __IO uint32_t CNT;                               /**< UC Counter 0..UC Counter 23, array offset: 0x28, array step: 0x20, irregular array, not all indices are valid */
    __IO uint32_t C;                                 /**< UC Control 0..UC Control 23, array offset: 0x2C, array step: 0x20 */
    __IO uint32_t S;                                 /**< UC Status 0..UC Status 23, array offset: 0x30, array step: 0x20 */
    __IO uint32_t ALTA;                              /**< Alternate Address 0..Alternate Address 23, array offset: 0x34, array step: 0x20 */
    __IO uint32_t C2;                                /**< UC Control 2 0..UC Control 2 23, array offset: 0x38, array step: 0x20 */
         uint8_t RESERVED_0[4];
  } UC[EMIOS_CH_UC_UC_COUNT];
} EMIOS_Type;

/* ----------------------------------------------------------------------------
   -- EMIOS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EMIOS_Register_Masks EMIOS Register Masks
 * @{
 */

/*! @name MCR - Module Configuration */
/*! @{ */

#define EMIOS_MCR_GPRE_MASK                      (0xFF00U)
#define EMIOS_MCR_GPRE_SHIFT                     (8U)
/*! GPRE - Global Prescaler */
#define EMIOS_MCR_GPRE(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_MCR_GPRE_SHIFT)) & EMIOS_MCR_GPRE_MASK)

#define EMIOS_MCR_GPREN_MASK                     (0x4000000U)
#define EMIOS_MCR_GPREN_SHIFT                    (26U)
/*! GPREN - Global Prescaler Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMIOS_MCR_GPREN(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_MCR_GPREN_SHIFT)) & EMIOS_MCR_GPREN_MASK)

#define EMIOS_MCR_GTBE_MASK                      (0x10000000U)
#define EMIOS_MCR_GTBE_SHIFT                     (28U)
/*! GTBE - Global Timebase Enable
 *  0b0..Deassert GTBE_OUT
 *  0b1..Assert GTBE_OUT
 */
#define EMIOS_MCR_GTBE(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_MCR_GTBE_SHIFT)) & EMIOS_MCR_GTBE_MASK)

#define EMIOS_MCR_FRZ_MASK                       (0x20000000U)
#define EMIOS_MCR_FRZ_SHIFT                      (29U)
/*! FRZ - Freeze
 *  0b0..Exit Freeze state
 *  0b1..Enter Freeze state
 */
#define EMIOS_MCR_FRZ(x)                         (((uint32_t)(((uint32_t)(x)) << EMIOS_MCR_FRZ_SHIFT)) & EMIOS_MCR_FRZ_MASK)

#define EMIOS_MCR_MDIS_MASK                      (0x40000000U)
#define EMIOS_MCR_MDIS_SHIFT                     (30U)
/*! MDIS - Module Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_MCR_MDIS(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_MCR_MDIS_SHIFT)) & EMIOS_MCR_MDIS_MASK)
/*! @} */

/*! @name GFLAG - Global Flag */
/*! @{ */

#define EMIOS_GFLAG_F0_MASK                      (0x1U)
#define EMIOS_GFLAG_F0_SHIFT                     (0U)
/*! F0 - Mirror of UC 0 FLAG */
#define EMIOS_GFLAG_F0(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F0_SHIFT)) & EMIOS_GFLAG_F0_MASK)

#define EMIOS_GFLAG_F1_MASK                      (0x2U)
#define EMIOS_GFLAG_F1_SHIFT                     (1U)
/*! F1 - Mirror of UC 1 FLAG */
#define EMIOS_GFLAG_F1(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F1_SHIFT)) & EMIOS_GFLAG_F1_MASK)

#define EMIOS_GFLAG_F2_MASK                      (0x4U)
#define EMIOS_GFLAG_F2_SHIFT                     (2U)
/*! F2 - Mirror of UC 2 FLAG */
#define EMIOS_GFLAG_F2(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F2_SHIFT)) & EMIOS_GFLAG_F2_MASK)

#define EMIOS_GFLAG_F3_MASK                      (0x8U)
#define EMIOS_GFLAG_F3_SHIFT                     (3U)
/*! F3 - Mirror of UC 3 FLAG */
#define EMIOS_GFLAG_F3(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F3_SHIFT)) & EMIOS_GFLAG_F3_MASK)

#define EMIOS_GFLAG_F4_MASK                      (0x10U)
#define EMIOS_GFLAG_F4_SHIFT                     (4U)
/*! F4 - Mirror of UC 4 FLAG */
#define EMIOS_GFLAG_F4(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F4_SHIFT)) & EMIOS_GFLAG_F4_MASK)

#define EMIOS_GFLAG_F5_MASK                      (0x20U)
#define EMIOS_GFLAG_F5_SHIFT                     (5U)
/*! F5 - Mirror of UC 5 FLAG */
#define EMIOS_GFLAG_F5(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F5_SHIFT)) & EMIOS_GFLAG_F5_MASK)

#define EMIOS_GFLAG_F6_MASK                      (0x40U)
#define EMIOS_GFLAG_F6_SHIFT                     (6U)
/*! F6 - Mirror of UC 6 FLAG */
#define EMIOS_GFLAG_F6(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F6_SHIFT)) & EMIOS_GFLAG_F6_MASK)

#define EMIOS_GFLAG_F7_MASK                      (0x80U)
#define EMIOS_GFLAG_F7_SHIFT                     (7U)
/*! F7 - Mirror of UC 7 FLAG */
#define EMIOS_GFLAG_F7(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F7_SHIFT)) & EMIOS_GFLAG_F7_MASK)

#define EMIOS_GFLAG_F8_MASK                      (0x100U)
#define EMIOS_GFLAG_F8_SHIFT                     (8U)
/*! F8 - Mirror of UC 8 FLAG */
#define EMIOS_GFLAG_F8(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F8_SHIFT)) & EMIOS_GFLAG_F8_MASK)

#define EMIOS_GFLAG_F9_MASK                      (0x200U)
#define EMIOS_GFLAG_F9_SHIFT                     (9U)
/*! F9 - Mirror of UC 9 FLAG */
#define EMIOS_GFLAG_F9(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F9_SHIFT)) & EMIOS_GFLAG_F9_MASK)

#define EMIOS_GFLAG_F10_MASK                     (0x400U)
#define EMIOS_GFLAG_F10_SHIFT                    (10U)
/*! F10 - Mirror of UC 10 FLAG */
#define EMIOS_GFLAG_F10(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F10_SHIFT)) & EMIOS_GFLAG_F10_MASK)

#define EMIOS_GFLAG_F11_MASK                     (0x800U)
#define EMIOS_GFLAG_F11_SHIFT                    (11U)
/*! F11 - Mirror of UC 11 FLAG */
#define EMIOS_GFLAG_F11(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F11_SHIFT)) & EMIOS_GFLAG_F11_MASK)

#define EMIOS_GFLAG_F12_MASK                     (0x1000U)
#define EMIOS_GFLAG_F12_SHIFT                    (12U)
/*! F12 - Mirror of UC 12 FLAG */
#define EMIOS_GFLAG_F12(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F12_SHIFT)) & EMIOS_GFLAG_F12_MASK)

#define EMIOS_GFLAG_F13_MASK                     (0x2000U)
#define EMIOS_GFLAG_F13_SHIFT                    (13U)
/*! F13 - Mirror of UC 13 FLAG */
#define EMIOS_GFLAG_F13(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F13_SHIFT)) & EMIOS_GFLAG_F13_MASK)

#define EMIOS_GFLAG_F14_MASK                     (0x4000U)
#define EMIOS_GFLAG_F14_SHIFT                    (14U)
/*! F14 - Mirror of UC 14 FLAG */
#define EMIOS_GFLAG_F14(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F14_SHIFT)) & EMIOS_GFLAG_F14_MASK)

#define EMIOS_GFLAG_F15_MASK                     (0x8000U)
#define EMIOS_GFLAG_F15_SHIFT                    (15U)
/*! F15 - Mirror of UC 15 FLAG */
#define EMIOS_GFLAG_F15(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F15_SHIFT)) & EMIOS_GFLAG_F15_MASK)

#define EMIOS_GFLAG_F16_MASK                     (0x10000U)
#define EMIOS_GFLAG_F16_SHIFT                    (16U)
/*! F16 - Mirror of UC 16 FLAG */
#define EMIOS_GFLAG_F16(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F16_SHIFT)) & EMIOS_GFLAG_F16_MASK)

#define EMIOS_GFLAG_F17_MASK                     (0x20000U)
#define EMIOS_GFLAG_F17_SHIFT                    (17U)
/*! F17 - Mirror of UC 17 FLAG */
#define EMIOS_GFLAG_F17(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F17_SHIFT)) & EMIOS_GFLAG_F17_MASK)

#define EMIOS_GFLAG_F18_MASK                     (0x40000U)
#define EMIOS_GFLAG_F18_SHIFT                    (18U)
/*! F18 - Mirror of UC 18 FLAG */
#define EMIOS_GFLAG_F18(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F18_SHIFT)) & EMIOS_GFLAG_F18_MASK)

#define EMIOS_GFLAG_F19_MASK                     (0x80000U)
#define EMIOS_GFLAG_F19_SHIFT                    (19U)
/*! F19 - Mirror of UC 19 FLAG */
#define EMIOS_GFLAG_F19(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F19_SHIFT)) & EMIOS_GFLAG_F19_MASK)

#define EMIOS_GFLAG_F20_MASK                     (0x100000U)
#define EMIOS_GFLAG_F20_SHIFT                    (20U)
/*! F20 - Mirror of UC 20 FLAG */
#define EMIOS_GFLAG_F20(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F20_SHIFT)) & EMIOS_GFLAG_F20_MASK)

#define EMIOS_GFLAG_F21_MASK                     (0x200000U)
#define EMIOS_GFLAG_F21_SHIFT                    (21U)
/*! F21 - Mirror of UC 21 FLAG */
#define EMIOS_GFLAG_F21(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F21_SHIFT)) & EMIOS_GFLAG_F21_MASK)

#define EMIOS_GFLAG_F22_MASK                     (0x400000U)
#define EMIOS_GFLAG_F22_SHIFT                    (22U)
/*! F22 - Mirror of UC 22 FLAG */
#define EMIOS_GFLAG_F22(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F22_SHIFT)) & EMIOS_GFLAG_F22_MASK)

#define EMIOS_GFLAG_F23_MASK                     (0x800000U)
#define EMIOS_GFLAG_F23_SHIFT                    (23U)
/*! F23 - Mirror of UC 23 FLAG */
#define EMIOS_GFLAG_F23(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_GFLAG_F23_SHIFT)) & EMIOS_GFLAG_F23_MASK)
/*! @} */

/*! @name OUDIS - Output Update Disable */
/*! @{ */

#define EMIOS_OUDIS_OU0_MASK                     (0x1U)
#define EMIOS_OUDIS_OU0_SHIFT                    (0U)
/*! OU0 - Channel 0 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU0(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU0_SHIFT)) & EMIOS_OUDIS_OU0_MASK)

#define EMIOS_OUDIS_OU1_MASK                     (0x2U)
#define EMIOS_OUDIS_OU1_SHIFT                    (1U)
/*! OU1 - Channel 1 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU1(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU1_SHIFT)) & EMIOS_OUDIS_OU1_MASK)

#define EMIOS_OUDIS_OU2_MASK                     (0x4U)
#define EMIOS_OUDIS_OU2_SHIFT                    (2U)
/*! OU2 - Channel 2 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU2(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU2_SHIFT)) & EMIOS_OUDIS_OU2_MASK)

#define EMIOS_OUDIS_OU3_MASK                     (0x8U)
#define EMIOS_OUDIS_OU3_SHIFT                    (3U)
/*! OU3 - Channel 3 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU3(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU3_SHIFT)) & EMIOS_OUDIS_OU3_MASK)

#define EMIOS_OUDIS_OU4_MASK                     (0x10U)
#define EMIOS_OUDIS_OU4_SHIFT                    (4U)
/*! OU4 - Channel 4 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU4(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU4_SHIFT)) & EMIOS_OUDIS_OU4_MASK)

#define EMIOS_OUDIS_OU5_MASK                     (0x20U)
#define EMIOS_OUDIS_OU5_SHIFT                    (5U)
/*! OU5 - Channel 5 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU5(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU5_SHIFT)) & EMIOS_OUDIS_OU5_MASK)

#define EMIOS_OUDIS_OU6_MASK                     (0x40U)
#define EMIOS_OUDIS_OU6_SHIFT                    (6U)
/*! OU6 - Channel 6 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU6(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU6_SHIFT)) & EMIOS_OUDIS_OU6_MASK)

#define EMIOS_OUDIS_OU7_MASK                     (0x80U)
#define EMIOS_OUDIS_OU7_SHIFT                    (7U)
/*! OU7 - Channel 7 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU7(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU7_SHIFT)) & EMIOS_OUDIS_OU7_MASK)

#define EMIOS_OUDIS_OU8_MASK                     (0x100U)
#define EMIOS_OUDIS_OU8_SHIFT                    (8U)
/*! OU8 - Channel 8 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU8(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU8_SHIFT)) & EMIOS_OUDIS_OU8_MASK)

#define EMIOS_OUDIS_OU9_MASK                     (0x200U)
#define EMIOS_OUDIS_OU9_SHIFT                    (9U)
/*! OU9 - Channel 9 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU9(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU9_SHIFT)) & EMIOS_OUDIS_OU9_MASK)

#define EMIOS_OUDIS_OU10_MASK                    (0x400U)
#define EMIOS_OUDIS_OU10_SHIFT                   (10U)
/*! OU10 - Channel 10 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU10(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU10_SHIFT)) & EMIOS_OUDIS_OU10_MASK)

#define EMIOS_OUDIS_OU11_MASK                    (0x800U)
#define EMIOS_OUDIS_OU11_SHIFT                   (11U)
/*! OU11 - Channel 11 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU11(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU11_SHIFT)) & EMIOS_OUDIS_OU11_MASK)

#define EMIOS_OUDIS_OU12_MASK                    (0x1000U)
#define EMIOS_OUDIS_OU12_SHIFT                   (12U)
/*! OU12 - Channel 12 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU12(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU12_SHIFT)) & EMIOS_OUDIS_OU12_MASK)

#define EMIOS_OUDIS_OU13_MASK                    (0x2000U)
#define EMIOS_OUDIS_OU13_SHIFT                   (13U)
/*! OU13 - Channel 13 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU13(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU13_SHIFT)) & EMIOS_OUDIS_OU13_MASK)

#define EMIOS_OUDIS_OU14_MASK                    (0x4000U)
#define EMIOS_OUDIS_OU14_SHIFT                   (14U)
/*! OU14 - Channel 14 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU14(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU14_SHIFT)) & EMIOS_OUDIS_OU14_MASK)

#define EMIOS_OUDIS_OU15_MASK                    (0x8000U)
#define EMIOS_OUDIS_OU15_SHIFT                   (15U)
/*! OU15 - Channel 15 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU15(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU15_SHIFT)) & EMIOS_OUDIS_OU15_MASK)

#define EMIOS_OUDIS_OU16_MASK                    (0x10000U)
#define EMIOS_OUDIS_OU16_SHIFT                   (16U)
/*! OU16 - Channel 16 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU16(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU16_SHIFT)) & EMIOS_OUDIS_OU16_MASK)

#define EMIOS_OUDIS_OU17_MASK                    (0x20000U)
#define EMIOS_OUDIS_OU17_SHIFT                   (17U)
/*! OU17 - Channel 17 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU17(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU17_SHIFT)) & EMIOS_OUDIS_OU17_MASK)

#define EMIOS_OUDIS_OU18_MASK                    (0x40000U)
#define EMIOS_OUDIS_OU18_SHIFT                   (18U)
/*! OU18 - Channel 18 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU18(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU18_SHIFT)) & EMIOS_OUDIS_OU18_MASK)

#define EMIOS_OUDIS_OU19_MASK                    (0x80000U)
#define EMIOS_OUDIS_OU19_SHIFT                   (19U)
/*! OU19 - Channel 19 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU19(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU19_SHIFT)) & EMIOS_OUDIS_OU19_MASK)

#define EMIOS_OUDIS_OU20_MASK                    (0x100000U)
#define EMIOS_OUDIS_OU20_SHIFT                   (20U)
/*! OU20 - Channel 20 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU20(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU20_SHIFT)) & EMIOS_OUDIS_OU20_MASK)

#define EMIOS_OUDIS_OU21_MASK                    (0x200000U)
#define EMIOS_OUDIS_OU21_SHIFT                   (21U)
/*! OU21 - Channel 21 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU21(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU21_SHIFT)) & EMIOS_OUDIS_OU21_MASK)

#define EMIOS_OUDIS_OU22_MASK                    (0x400000U)
#define EMIOS_OUDIS_OU22_SHIFT                   (22U)
/*! OU22 - Channel 22 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU22(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU22_SHIFT)) & EMIOS_OUDIS_OU22_MASK)

#define EMIOS_OUDIS_OU23_MASK                    (0x800000U)
#define EMIOS_OUDIS_OU23_SHIFT                   (23U)
/*! OU23 - Channel 23 Output Update Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_OUDIS_OU23(x)                      (((uint32_t)(((uint32_t)(x)) << EMIOS_OUDIS_OU23_SHIFT)) & EMIOS_OUDIS_OU23_MASK)
/*! @} */

/*! @name UCDIS - Disable Channel */
/*! @{ */

#define EMIOS_UCDIS_UCDIS0_MASK                  (0x1U)
#define EMIOS_UCDIS_UCDIS0_SHIFT                 (0U)
/*! UCDIS0 - Disable UC 0
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS0(x)                    (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS0_SHIFT)) & EMIOS_UCDIS_UCDIS0_MASK)

#define EMIOS_UCDIS_UCDIS1_MASK                  (0x2U)
#define EMIOS_UCDIS_UCDIS1_SHIFT                 (1U)
/*! UCDIS1 - Disable UC 1
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS1(x)                    (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS1_SHIFT)) & EMIOS_UCDIS_UCDIS1_MASK)

#define EMIOS_UCDIS_UCDIS2_MASK                  (0x4U)
#define EMIOS_UCDIS_UCDIS2_SHIFT                 (2U)
/*! UCDIS2 - Disable UC 2
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS2(x)                    (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS2_SHIFT)) & EMIOS_UCDIS_UCDIS2_MASK)

#define EMIOS_UCDIS_UCDIS3_MASK                  (0x8U)
#define EMIOS_UCDIS_UCDIS3_SHIFT                 (3U)
/*! UCDIS3 - Disable UC 3
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS3(x)                    (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS3_SHIFT)) & EMIOS_UCDIS_UCDIS3_MASK)

#define EMIOS_UCDIS_UCDIS4_MASK                  (0x10U)
#define EMIOS_UCDIS_UCDIS4_SHIFT                 (4U)
/*! UCDIS4 - Disable UC 4
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS4(x)                    (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS4_SHIFT)) & EMIOS_UCDIS_UCDIS4_MASK)

#define EMIOS_UCDIS_UCDIS5_MASK                  (0x20U)
#define EMIOS_UCDIS_UCDIS5_SHIFT                 (5U)
/*! UCDIS5 - Disable UC 5
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS5(x)                    (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS5_SHIFT)) & EMIOS_UCDIS_UCDIS5_MASK)

#define EMIOS_UCDIS_UCDIS6_MASK                  (0x40U)
#define EMIOS_UCDIS_UCDIS6_SHIFT                 (6U)
/*! UCDIS6 - Disable UC 6
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS6(x)                    (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS6_SHIFT)) & EMIOS_UCDIS_UCDIS6_MASK)

#define EMIOS_UCDIS_UCDIS7_MASK                  (0x80U)
#define EMIOS_UCDIS_UCDIS7_SHIFT                 (7U)
/*! UCDIS7 - Disable UC 7
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS7(x)                    (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS7_SHIFT)) & EMIOS_UCDIS_UCDIS7_MASK)

#define EMIOS_UCDIS_UCDIS8_MASK                  (0x100U)
#define EMIOS_UCDIS_UCDIS8_SHIFT                 (8U)
/*! UCDIS8 - Disable UC 8
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS8(x)                    (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS8_SHIFT)) & EMIOS_UCDIS_UCDIS8_MASK)

#define EMIOS_UCDIS_UCDIS9_MASK                  (0x200U)
#define EMIOS_UCDIS_UCDIS9_SHIFT                 (9U)
/*! UCDIS9 - Disable UC 9
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS9(x)                    (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS9_SHIFT)) & EMIOS_UCDIS_UCDIS9_MASK)

#define EMIOS_UCDIS_UCDIS10_MASK                 (0x400U)
#define EMIOS_UCDIS_UCDIS10_SHIFT                (10U)
/*! UCDIS10 - Disable UC 10
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS10(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS10_SHIFT)) & EMIOS_UCDIS_UCDIS10_MASK)

#define EMIOS_UCDIS_UCDIS11_MASK                 (0x800U)
#define EMIOS_UCDIS_UCDIS11_SHIFT                (11U)
/*! UCDIS11 - Disable UC 11
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS11(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS11_SHIFT)) & EMIOS_UCDIS_UCDIS11_MASK)

#define EMIOS_UCDIS_UCDIS12_MASK                 (0x1000U)
#define EMIOS_UCDIS_UCDIS12_SHIFT                (12U)
/*! UCDIS12 - Disable UC 12
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS12(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS12_SHIFT)) & EMIOS_UCDIS_UCDIS12_MASK)

#define EMIOS_UCDIS_UCDIS13_MASK                 (0x2000U)
#define EMIOS_UCDIS_UCDIS13_SHIFT                (13U)
/*! UCDIS13 - Disable UC 13
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS13(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS13_SHIFT)) & EMIOS_UCDIS_UCDIS13_MASK)

#define EMIOS_UCDIS_UCDIS14_MASK                 (0x4000U)
#define EMIOS_UCDIS_UCDIS14_SHIFT                (14U)
/*! UCDIS14 - Disable UC 14
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS14(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS14_SHIFT)) & EMIOS_UCDIS_UCDIS14_MASK)

#define EMIOS_UCDIS_UCDIS15_MASK                 (0x8000U)
#define EMIOS_UCDIS_UCDIS15_SHIFT                (15U)
/*! UCDIS15 - Disable UC 15
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS15(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS15_SHIFT)) & EMIOS_UCDIS_UCDIS15_MASK)

#define EMIOS_UCDIS_UCDIS16_MASK                 (0x10000U)
#define EMIOS_UCDIS_UCDIS16_SHIFT                (16U)
/*! UCDIS16 - Disable UC 16
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS16(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS16_SHIFT)) & EMIOS_UCDIS_UCDIS16_MASK)

#define EMIOS_UCDIS_UCDIS17_MASK                 (0x20000U)
#define EMIOS_UCDIS_UCDIS17_SHIFT                (17U)
/*! UCDIS17 - Disable UC 17
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS17(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS17_SHIFT)) & EMIOS_UCDIS_UCDIS17_MASK)

#define EMIOS_UCDIS_UCDIS18_MASK                 (0x40000U)
#define EMIOS_UCDIS_UCDIS18_SHIFT                (18U)
/*! UCDIS18 - Disable UC 18
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS18(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS18_SHIFT)) & EMIOS_UCDIS_UCDIS18_MASK)

#define EMIOS_UCDIS_UCDIS19_MASK                 (0x80000U)
#define EMIOS_UCDIS_UCDIS19_SHIFT                (19U)
/*! UCDIS19 - Disable UC 19
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS19(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS19_SHIFT)) & EMIOS_UCDIS_UCDIS19_MASK)

#define EMIOS_UCDIS_UCDIS20_MASK                 (0x100000U)
#define EMIOS_UCDIS_UCDIS20_SHIFT                (20U)
/*! UCDIS20 - Disable UC 20
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS20(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS20_SHIFT)) & EMIOS_UCDIS_UCDIS20_MASK)

#define EMIOS_UCDIS_UCDIS21_MASK                 (0x200000U)
#define EMIOS_UCDIS_UCDIS21_SHIFT                (21U)
/*! UCDIS21 - Disable UC 21
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS21(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS21_SHIFT)) & EMIOS_UCDIS_UCDIS21_MASK)

#define EMIOS_UCDIS_UCDIS22_MASK                 (0x400000U)
#define EMIOS_UCDIS_UCDIS22_SHIFT                (22U)
/*! UCDIS22 - Disable UC 22
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS22(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS22_SHIFT)) & EMIOS_UCDIS_UCDIS22_MASK)

#define EMIOS_UCDIS_UCDIS23_MASK                 (0x800000U)
#define EMIOS_UCDIS_UCDIS23_SHIFT                (23U)
/*! UCDIS23 - Disable UC 23
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMIOS_UCDIS_UCDIS23(x)                   (((uint32_t)(((uint32_t)(x)) << EMIOS_UCDIS_UCDIS23_SHIFT)) & EMIOS_UCDIS_UCDIS23_MASK)
/*! @} */

/*! @name A - UC A 0..UC A 23 */
/*! @{ */

#define EMIOS_A_A_MASK                           (0xFFFFU)
#define EMIOS_A_A_SHIFT                          (0U)
/*! A - A */
#define EMIOS_A_A(x)                             (((uint32_t)(((uint32_t)(x)) << EMIOS_A_A_SHIFT)) & EMIOS_A_A_MASK)
/*! @} */

/* The count of EMIOS_A */
#define EMIOS_A_COUNT                            (24U)

/*! @name B - UC B 0..UC B 23 */
/*! @{ */

#define EMIOS_B_B_MASK                           (0xFFFFU)
#define EMIOS_B_B_SHIFT                          (0U)
/*! B - B */
#define EMIOS_B_B(x)                             (((uint32_t)(((uint32_t)(x)) << EMIOS_B_B_SHIFT)) & EMIOS_B_B_MASK)
/*! @} */

/* The count of EMIOS_B */
#define EMIOS_B_COUNT                            (24U)

/*! @name CNT - UC Counter 0..UC Counter 23 */
/*! @{ */

#define EMIOS_CNT_C_MASK                         (0xFFFFU)
#define EMIOS_CNT_C_SHIFT                        (0U)
/*! C - Internal Counter Value */
#define EMIOS_CNT_C(x)                           (((uint32_t)(((uint32_t)(x)) << EMIOS_CNT_C_SHIFT)) & EMIOS_CNT_C_MASK)
/*! @} */

/* The count of EMIOS_CNT */
#define EMIOS_CNT_COUNT                          (24U)

/*! @name C - UC Control 0..UC Control 23 */
/*! @{ */

#define EMIOS_C_MODE_MASK                        (0x7FU)
#define EMIOS_C_MODE_SHIFT                       (0U)
/*! MODE - Mode Selection */
#define EMIOS_C_MODE(x)                          (((uint32_t)(((uint32_t)(x)) << EMIOS_C_MODE_SHIFT)) & EMIOS_C_MODE_MASK)

#define EMIOS_C_EDPOL_MASK                       (0x80U)
#define EMIOS_C_EDPOL_SHIFT                      (7U)
/*! EDPOL - Edge Polarity */
#define EMIOS_C_EDPOL(x)                         (((uint32_t)(((uint32_t)(x)) << EMIOS_C_EDPOL_SHIFT)) & EMIOS_C_EDPOL_MASK)

#define EMIOS_C_EDSEL_MASK                       (0x100U)
#define EMIOS_C_EDSEL_SHIFT                      (8U)
/*! EDSEL - Edge Selection */
#define EMIOS_C_EDSEL(x)                         (((uint32_t)(((uint32_t)(x)) << EMIOS_C_EDSEL_SHIFT)) & EMIOS_C_EDSEL_MASK)

#define EMIOS_C_BSL_MASK                         (0x600U)
#define EMIOS_C_BSL_SHIFT                        (9U)
/*! BSL - Bus Select */
#define EMIOS_C_BSL(x)                           (((uint32_t)(((uint32_t)(x)) << EMIOS_C_BSL_SHIFT)) & EMIOS_C_BSL_MASK)

#define EMIOS_C_FORCMB_MASK                      (0x1000U)
#define EMIOS_C_FORCMB_SHIFT                     (12U)
/*! FORCMB - Force Match B
 *  0b0..No effect
 *  0b1..Force a match at comparator B
 */
#define EMIOS_C_FORCMB(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_C_FORCMB_SHIFT)) & EMIOS_C_FORCMB_MASK)

#define EMIOS_C_FORCMA_MASK                      (0x2000U)
#define EMIOS_C_FORCMA_SHIFT                     (13U)
/*! FORCMA - Force Match A
 *  0b0..No effect
 *  0b1..Force a match at comparator A
 */
#define EMIOS_C_FORCMA(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_C_FORCMA_SHIFT)) & EMIOS_C_FORCMA_MASK)

#define EMIOS_C_FEN_MASK                         (0x20000U)
#define EMIOS_C_FEN_SHIFT                        (17U)
/*! FEN - Flag Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMIOS_C_FEN(x)                           (((uint32_t)(((uint32_t)(x)) << EMIOS_C_FEN_SHIFT)) & EMIOS_C_FEN_MASK)

#define EMIOS_C_FCK_MASK                         (0x40000U)
#define EMIOS_C_FCK_SHIFT                        (18U)
/*! FCK - Filter Clock Select
 *  0b0..Prescaled clock
 *  0b1..eMIOS module clock
 */
#define EMIOS_C_FCK(x)                           (((uint32_t)(((uint32_t)(x)) << EMIOS_C_FCK_SHIFT)) & EMIOS_C_FCK_MASK)

#define EMIOS_C_IF_MASK                          (0x780000U)
#define EMIOS_C_IF_SHIFT                         (19U)
/*! IF - Input Filter
 *  0b0000..Bypassed; the input signal is synchronized before arriving at the digital filter
 *  0b0001..2 cycles
 *  0b0010..4 cycles
 *  0b0100..8 cycles
 *  0b1000..16 cycles
 */
#define EMIOS_C_IF(x)                            (((uint32_t)(((uint32_t)(x)) << EMIOS_C_IF_SHIFT)) & EMIOS_C_IF_MASK)

#define EMIOS_C_DMA_MASK                         (0x1000000U)
#define EMIOS_C_DMA_SHIFT                        (24U)
/*! DMA - Direct Memory Access
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define EMIOS_C_DMA(x)                           (((uint32_t)(((uint32_t)(x)) << EMIOS_C_DMA_SHIFT)) & EMIOS_C_DMA_MASK)

#define EMIOS_C_UCPREN_MASK                      (0x2000000U)
#define EMIOS_C_UCPREN_SHIFT                     (25U)
/*! UCPREN - Prescaler Enable
 *  0b0..Disable (no clock)
 *  0b1..Enable
 */
#define EMIOS_C_UCPREN(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_C_UCPREN_SHIFT)) & EMIOS_C_UCPREN_MASK)

#define EMIOS_C_UCPRE_MASK                       (0xC000000U)
#define EMIOS_C_UCPRE_SHIFT                      (26U)
/*! UCPRE - Prescaler
 *  0b00..1
 *  0b01..2
 *  0b10..3
 *  0b11..4
 */
#define EMIOS_C_UCPRE(x)                         (((uint32_t)(((uint32_t)(x)) << EMIOS_C_UCPRE_SHIFT)) & EMIOS_C_UCPRE_MASK)

#define EMIOS_C_ODISSL_MASK                      (0x30000000U)
#define EMIOS_C_ODISSL_SHIFT                     (28U)
/*! ODISSL - Output Disable Select
 *  0b00..0
 *  0b01..1
 *  0b10..2
 *  0b11..3
 */
#define EMIOS_C_ODISSL(x)                        (((uint32_t)(((uint32_t)(x)) << EMIOS_C_ODISSL_SHIFT)) & EMIOS_C_ODISSL_MASK)

#define EMIOS_C_ODIS_MASK                        (0x40000000U)
#define EMIOS_C_ODIS_SHIFT                       (30U)
/*! ODIS - Output Disable
 *  0b0..Enables output pin (the output pin operates normally)
 *  0b1..Disables output pin
 */
#define EMIOS_C_ODIS(x)                          (((uint32_t)(((uint32_t)(x)) << EMIOS_C_ODIS_SHIFT)) & EMIOS_C_ODIS_MASK)

#define EMIOS_C_FREN_MASK                        (0x80000000U)
#define EMIOS_C_FREN_SHIFT                       (31U)
/*! FREN - Freeze Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMIOS_C_FREN(x)                          (((uint32_t)(((uint32_t)(x)) << EMIOS_C_FREN_SHIFT)) & EMIOS_C_FREN_MASK)
/*! @} */

/* The count of EMIOS_C */
#define EMIOS_C_COUNT                            (24U)

/*! @name S - UC Status 0..UC Status 23 */
/*! @{ */

#define EMIOS_S_FLAG_MASK                        (0x1U)
#define EMIOS_S_FLAG_SHIFT                       (0U)
/*! FLAG - Flag
 *  0b0..No event
 *  0b1..Clear the flag (FLAG returns to 0)
 *  0b1..Event has occurred
 */
#define EMIOS_S_FLAG(x)                          (((uint32_t)(((uint32_t)(x)) << EMIOS_S_FLAG_SHIFT)) & EMIOS_S_FLAG_MASK)

#define EMIOS_S_UCOUT_MASK                       (0x2U)
#define EMIOS_S_UCOUT_SHIFT                      (1U)
/*! UCOUT - UC Output Pin
 *  0b0..Negated
 *  0b1..Asserted
 */
#define EMIOS_S_UCOUT(x)                         (((uint32_t)(((uint32_t)(x)) << EMIOS_S_UCOUT_SHIFT)) & EMIOS_S_UCOUT_MASK)

#define EMIOS_S_UCIN_MASK                        (0x4U)
#define EMIOS_S_UCIN_SHIFT                       (2U)
/*! UCIN - UC Input Pin
 *  0b0..Negated
 *  0b1..Asserted
 */
#define EMIOS_S_UCIN(x)                          (((uint32_t)(((uint32_t)(x)) << EMIOS_S_UCIN_SHIFT)) & EMIOS_S_UCIN_MASK)

#define EMIOS_S_OVFL_MASK                        (0x8000U)
#define EMIOS_S_OVFL_SHIFT                       (15U)
/*! OVFL - Overflow
 *  0b0..No overflow
 *  0b1..Overflow
 *  0b1..Return OVFL to 0
 */
#define EMIOS_S_OVFL(x)                          (((uint32_t)(((uint32_t)(x)) << EMIOS_S_OVFL_SHIFT)) & EMIOS_S_OVFL_MASK)

#define EMIOS_S_OVR_MASK                         (0x80000000U)
#define EMIOS_S_OVR_SHIFT                        (31U)
/*! OVR - Overrun
 *  0b0..No overrun
 *  0b1..Overrun
 *  0b1..Return OVR to 0
 */
#define EMIOS_S_OVR(x)                           (((uint32_t)(((uint32_t)(x)) << EMIOS_S_OVR_SHIFT)) & EMIOS_S_OVR_MASK)
/*! @} */

/* The count of EMIOS_S */
#define EMIOS_S_COUNT                            (24U)

/*! @name ALTA - Alternate Address 0..Alternate Address 23 */
/*! @{ */

#define EMIOS_ALTA_ALTA_MASK                     (0xFFFFU)
#define EMIOS_ALTA_ALTA_SHIFT                    (0U)
/*! ALTA - Alternate Address */
#define EMIOS_ALTA_ALTA(x)                       (((uint32_t)(((uint32_t)(x)) << EMIOS_ALTA_ALTA_SHIFT)) & EMIOS_ALTA_ALTA_MASK)
/*! @} */

/* The count of EMIOS_ALTA */
#define EMIOS_ALTA_COUNT                         (24U)

/*! @name C2 - UC Control 2 0..UC Control 2 23 */
/*! @{ */

#define EMIOS_C2_UCRELDEL_INT_MASK               (0x1FU)
#define EMIOS_C2_UCRELDEL_INT_SHIFT              (0U)
/*! UCRELDEL_INT - Reload Signal Output Delay Interval */
#define EMIOS_C2_UCRELDEL_INT(x)                 (((uint32_t)(((uint32_t)(x)) << EMIOS_C2_UCRELDEL_INT_SHIFT)) & EMIOS_C2_UCRELDEL_INT_MASK)

#define EMIOS_C2_UCPRECLK_MASK                   (0x4000U)
#define EMIOS_C2_UCPRECLK_SHIFT                  (14U)
/*! UCPRECLK - Prescaler Clock Source
 *  0b0..Prescaled clock
 *  0b1..eMIOS module clock
 */
#define EMIOS_C2_UCPRECLK(x)                     (((uint32_t)(((uint32_t)(x)) << EMIOS_C2_UCPRECLK_SHIFT)) & EMIOS_C2_UCPRECLK_MASK)

#define EMIOS_C2_UCEXTPRE_MASK                   (0xF0000U)
#define EMIOS_C2_UCEXTPRE_SHIFT                  (16U)
/*! UCEXTPRE - Extended Prescaler */
#define EMIOS_C2_UCEXTPRE(x)                     (((uint32_t)(((uint32_t)(x)) << EMIOS_C2_UCEXTPRE_SHIFT)) & EMIOS_C2_UCEXTPRE_MASK)
/*! @} */

/* The count of EMIOS_C2 */
#define EMIOS_C2_COUNT                           (24U)


/*!
 * @}
 */ /* end of group EMIOS_Register_Masks */


/*!
 * @}
 */ /* end of group EMIOS_Peripheral_Access_Layer */


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


#endif  /* PERI_EMIOS_H_ */

