/*
** ###################################################################
**     Processors:          MIMXRT1061CVJ5A
**                          MIMXRT1061CVJ5B
**                          MIMXRT1061CVL5A
**                          MIMXRT1061CVL5B
**                          MIMXRT1061DVJ6A
**                          MIMXRT1061DVJ6B
**                          MIMXRT1061DVL6A
**                          MIMXRT1061DVL6B
**                          MIMXRT1061XVN5B
**                          MIMXRT1062CVJ5A
**                          MIMXRT1062CVJ5B
**                          MIMXRT1062CVL5A
**                          MIMXRT1062CVL5B
**                          MIMXRT1062DVJ6A
**                          MIMXRT1062DVJ6B
**                          MIMXRT1062DVL6A
**                          MIMXRT1062DVL6B
**                          MIMXRT1062DVN6B
**                          MIMXRT1062XVN5B
**                          MIMXRT106ADVL6A
**                          MIMXRT106CDVL6A
**                          MIMXRT106FDVL6A
**                          MIMXRT106LDVL6A
**                          MIMXRT106SDVL6A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CCM_ANALOG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1060RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1060RM Rev.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1060RM Rev.3.
**     - rev. 1.4 (2022-03-25)
**         Add RT1060X device
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CCM_ANALOG.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CCM_ANALOG
 *
 * CMSIS Peripheral Access Layer for CCM_ANALOG
 */

#if !defined(PERI_CCM_ANALOG_H_)
#define PERI_CCM_ANALOG_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1061CVJ5A) || defined(CPU_MIMXRT1061CVJ5B) || defined(CPU_MIMXRT1061CVL5A) || defined(CPU_MIMXRT1061CVL5B) || defined(CPU_MIMXRT1061DVJ6A) || defined(CPU_MIMXRT1061DVJ6B) || defined(CPU_MIMXRT1061DVL6A) || defined(CPU_MIMXRT1061DVL6B) || defined(CPU_MIMXRT1061XVN5B))
#include "MIMXRT1061_COMMON.h"
#elif (defined(CPU_MIMXRT1062CVJ5A) || defined(CPU_MIMXRT1062CVJ5B) || defined(CPU_MIMXRT1062CVL5A) || defined(CPU_MIMXRT1062CVL5B) || defined(CPU_MIMXRT1062DVJ6A) || defined(CPU_MIMXRT1062DVJ6B) || defined(CPU_MIMXRT1062DVL6A) || defined(CPU_MIMXRT1062DVL6B) || defined(CPU_MIMXRT1062DVN6B) || defined(CPU_MIMXRT1062XVN5B))
#include "MIMXRT1062_COMMON.h"
#elif (defined(CPU_MIMXRT106ADVL6A))
#include "MIMXRT106A_COMMON.h"
#elif (defined(CPU_MIMXRT106CDVL6A))
#include "MIMXRT106C_COMMON.h"
#elif (defined(CPU_MIMXRT106FDVL6A))
#include "MIMXRT106F_COMMON.h"
#elif (defined(CPU_MIMXRT106LDVL6A))
#include "MIMXRT106L_COMMON.h"
#elif (defined(CPU_MIMXRT106SDVL6A))
#include "MIMXRT106S_COMMON.h"
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
   -- CCM_ANALOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_ANALOG_Peripheral_Access_Layer CCM_ANALOG Peripheral Access Layer
 * @{
 */

/** CCM_ANALOG - Register Layout Typedef */
typedef struct {
  __IO uint32_t PLL_ARM;                           /**< Analog ARM PLL control Register, offset: 0x0 */
  __IO uint32_t PLL_ARM_SET;                       /**< Analog ARM PLL control Register, offset: 0x4 */
  __IO uint32_t PLL_ARM_CLR;                       /**< Analog ARM PLL control Register, offset: 0x8 */
  __IO uint32_t PLL_ARM_TOG;                       /**< Analog ARM PLL control Register, offset: 0xC */
  __IO uint32_t PLL_USB1;                          /**< Analog USB1 480MHz PLL Control Register, offset: 0x10 */
  __IO uint32_t PLL_USB1_SET;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x14 */
  __IO uint32_t PLL_USB1_CLR;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x18 */
  __IO uint32_t PLL_USB1_TOG;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x1C */
  __IO uint32_t PLL_USB2;                          /**< Analog USB2 480MHz PLL Control Register, offset: 0x20 */
  __IO uint32_t PLL_USB2_SET;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x24 */
  __IO uint32_t PLL_USB2_CLR;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x28 */
  __IO uint32_t PLL_USB2_TOG;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x2C */
  __IO uint32_t PLL_SYS;                           /**< Analog System PLL Control Register, offset: 0x30 */
  __IO uint32_t PLL_SYS_SET;                       /**< Analog System PLL Control Register, offset: 0x34 */
  __IO uint32_t PLL_SYS_CLR;                       /**< Analog System PLL Control Register, offset: 0x38 */
  __IO uint32_t PLL_SYS_TOG;                       /**< Analog System PLL Control Register, offset: 0x3C */
  __IO uint32_t PLL_SYS_SS;                        /**< 528MHz System PLL Spread Spectrum Register, offset: 0x40 */
       uint8_t RESERVED_0[12];
  __IO uint32_t PLL_SYS_NUM;                       /**< Numerator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x50 */
       uint8_t RESERVED_1[12];
  __IO uint32_t PLL_SYS_DENOM;                     /**< Denominator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x60 */
       uint8_t RESERVED_2[12];
  __IO uint32_t PLL_AUDIO;                         /**< Analog Audio PLL control Register, offset: 0x70 */
  __IO uint32_t PLL_AUDIO_SET;                     /**< Analog Audio PLL control Register, offset: 0x74 */
  __IO uint32_t PLL_AUDIO_CLR;                     /**< Analog Audio PLL control Register, offset: 0x78 */
  __IO uint32_t PLL_AUDIO_TOG;                     /**< Analog Audio PLL control Register, offset: 0x7C */
  __IO uint32_t PLL_AUDIO_NUM;                     /**< Numerator of Audio PLL Fractional Loop Divider Register, offset: 0x80 */
       uint8_t RESERVED_3[12];
  __IO uint32_t PLL_AUDIO_DENOM;                   /**< Denominator of Audio PLL Fractional Loop Divider Register, offset: 0x90 */
       uint8_t RESERVED_4[12];
  __IO uint32_t PLL_VIDEO;                         /**< Analog Video PLL control Register, offset: 0xA0 */
  __IO uint32_t PLL_VIDEO_SET;                     /**< Analog Video PLL control Register, offset: 0xA4 */
  __IO uint32_t PLL_VIDEO_CLR;                     /**< Analog Video PLL control Register, offset: 0xA8 */
  __IO uint32_t PLL_VIDEO_TOG;                     /**< Analog Video PLL control Register, offset: 0xAC */
  __IO uint32_t PLL_VIDEO_NUM;                     /**< Numerator of Video PLL Fractional Loop Divider Register, offset: 0xB0 */
       uint8_t RESERVED_5[12];
  __IO uint32_t PLL_VIDEO_DENOM;                   /**< Denominator of Video PLL Fractional Loop Divider Register, offset: 0xC0 */
       uint8_t RESERVED_6[28];
  __IO uint32_t PLL_ENET;                          /**< Analog ENET PLL Control Register, offset: 0xE0 */
  __IO uint32_t PLL_ENET_SET;                      /**< Analog ENET PLL Control Register, offset: 0xE4 */
  __IO uint32_t PLL_ENET_CLR;                      /**< Analog ENET PLL Control Register, offset: 0xE8 */
  __IO uint32_t PLL_ENET_TOG;                      /**< Analog ENET PLL Control Register, offset: 0xEC */
  __IO uint32_t PFD_480;                           /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF0 */
  __IO uint32_t PFD_480_SET;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF4 */
  __IO uint32_t PFD_480_CLR;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF8 */
  __IO uint32_t PFD_480_TOG;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xFC */
  __IO uint32_t PFD_528;                           /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x100 */
  __IO uint32_t PFD_528_SET;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x104 */
  __IO uint32_t PFD_528_CLR;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x108 */
  __IO uint32_t PFD_528_TOG;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x10C */
       uint8_t RESERVED_7[64];
  __IO uint32_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x150 */
  __IO uint32_t MISC0_SET;                         /**< Miscellaneous Register 0, offset: 0x154 */
  __IO uint32_t MISC0_CLR;                         /**< Miscellaneous Register 0, offset: 0x158 */
  __IO uint32_t MISC0_TOG;                         /**< Miscellaneous Register 0, offset: 0x15C */
  __IO uint32_t MISC1;                             /**< Miscellaneous Register 1, offset: 0x160 */
  __IO uint32_t MISC1_SET;                         /**< Miscellaneous Register 1, offset: 0x164 */
  __IO uint32_t MISC1_CLR;                         /**< Miscellaneous Register 1, offset: 0x168 */
  __IO uint32_t MISC1_TOG;                         /**< Miscellaneous Register 1, offset: 0x16C */
  __IO uint32_t MISC2;                             /**< Miscellaneous Register 2, offset: 0x170 */
  __IO uint32_t MISC2_SET;                         /**< Miscellaneous Register 2, offset: 0x174 */
  __IO uint32_t MISC2_CLR;                         /**< Miscellaneous Register 2, offset: 0x178 */
  __IO uint32_t MISC2_TOG;                         /**< Miscellaneous Register 2, offset: 0x17C */
} CCM_ANALOG_Type;

/* ----------------------------------------------------------------------------
   -- CCM_ANALOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_ANALOG_Register_Masks CCM_ANALOG Register Masks
 * @{
 */

/*! @name PLL_ARM - Analog ARM PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_ARM_DIV_SELECT_MASK       (0x7FU)
#define CCM_ANALOG_PLL_ARM_DIV_SELECT_SHIFT      (0U)
#define CCM_ANALOG_PLL_ARM_DIV_SELECT(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ARM_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ARM_POWERDOWN_MASK        (0x1000U)
#define CCM_ANALOG_PLL_ARM_POWERDOWN_SHIFT       (12U)
#define CCM_ANALOG_PLL_ARM_POWERDOWN(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_ARM_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_ARM_ENABLE_MASK           (0x2000U)
#define CCM_ANALOG_PLL_ARM_ENABLE_SHIFT          (13U)
#define CCM_ANALOG_PLL_ARM_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_ENABLE_SHIFT)) & CCM_ANALOG_PLL_ARM_ENABLE_MASK)

#define CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC_MASK   (0xC000U)
#define CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC_SHIFT  (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_ARM_BYPASS_MASK           (0x10000U)
#define CCM_ANALOG_PLL_ARM_BYPASS_SHIFT          (16U)
#define CCM_ANALOG_PLL_ARM_BYPASS(x)             (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_BYPASS_SHIFT)) & CCM_ANALOG_PLL_ARM_BYPASS_MASK)

#define CCM_ANALOG_PLL_ARM_PLL_SEL_MASK          (0x80000U)
#define CCM_ANALOG_PLL_ARM_PLL_SEL_SHIFT         (19U)
#define CCM_ANALOG_PLL_ARM_PLL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_PLL_SEL_SHIFT)) & CCM_ANALOG_PLL_ARM_PLL_SEL_MASK)

#define CCM_ANALOG_PLL_ARM_LOCK_MASK             (0x80000000U)
#define CCM_ANALOG_PLL_ARM_LOCK_SHIFT            (31U)
#define CCM_ANALOG_PLL_ARM_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_LOCK_SHIFT)) & CCM_ANALOG_PLL_ARM_LOCK_MASK)
/*! @} */

/*! @name PLL_ARM_SET - Analog ARM PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_ARM_SET_DIV_SELECT_MASK   (0x7FU)
#define CCM_ANALOG_PLL_ARM_SET_DIV_SELECT_SHIFT  (0U)
#define CCM_ANALOG_PLL_ARM_SET_DIV_SELECT(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_SET_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ARM_SET_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ARM_SET_POWERDOWN_MASK    (0x1000U)
#define CCM_ANALOG_PLL_ARM_SET_POWERDOWN_SHIFT   (12U)
#define CCM_ANALOG_PLL_ARM_SET_POWERDOWN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_SET_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_ARM_SET_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_ARM_SET_ENABLE_MASK       (0x2000U)
#define CCM_ANALOG_PLL_ARM_SET_ENABLE_SHIFT      (13U)
#define CCM_ANALOG_PLL_ARM_SET_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_SET_ENABLE_SHIFT)) & CCM_ANALOG_PLL_ARM_SET_ENABLE_MASK)

#define CCM_ANALOG_PLL_ARM_SET_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_ARM_SET_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_ARM_SET_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_SET_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_ARM_SET_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_ARM_SET_BYPASS_MASK       (0x10000U)
#define CCM_ANALOG_PLL_ARM_SET_BYPASS_SHIFT      (16U)
#define CCM_ANALOG_PLL_ARM_SET_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_SET_BYPASS_SHIFT)) & CCM_ANALOG_PLL_ARM_SET_BYPASS_MASK)

#define CCM_ANALOG_PLL_ARM_SET_PLL_SEL_MASK      (0x80000U)
#define CCM_ANALOG_PLL_ARM_SET_PLL_SEL_SHIFT     (19U)
#define CCM_ANALOG_PLL_ARM_SET_PLL_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_SET_PLL_SEL_SHIFT)) & CCM_ANALOG_PLL_ARM_SET_PLL_SEL_MASK)

#define CCM_ANALOG_PLL_ARM_SET_LOCK_MASK         (0x80000000U)
#define CCM_ANALOG_PLL_ARM_SET_LOCK_SHIFT        (31U)
#define CCM_ANALOG_PLL_ARM_SET_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_SET_LOCK_SHIFT)) & CCM_ANALOG_PLL_ARM_SET_LOCK_MASK)
/*! @} */

/*! @name PLL_ARM_CLR - Analog ARM PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_ARM_CLR_DIV_SELECT_MASK   (0x7FU)
#define CCM_ANALOG_PLL_ARM_CLR_DIV_SELECT_SHIFT  (0U)
#define CCM_ANALOG_PLL_ARM_CLR_DIV_SELECT(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_CLR_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ARM_CLR_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ARM_CLR_POWERDOWN_MASK    (0x1000U)
#define CCM_ANALOG_PLL_ARM_CLR_POWERDOWN_SHIFT   (12U)
#define CCM_ANALOG_PLL_ARM_CLR_POWERDOWN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_CLR_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_ARM_CLR_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_ARM_CLR_ENABLE_MASK       (0x2000U)
#define CCM_ANALOG_PLL_ARM_CLR_ENABLE_SHIFT      (13U)
#define CCM_ANALOG_PLL_ARM_CLR_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_CLR_ENABLE_SHIFT)) & CCM_ANALOG_PLL_ARM_CLR_ENABLE_MASK)

#define CCM_ANALOG_PLL_ARM_CLR_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_ARM_CLR_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_ARM_CLR_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_CLR_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_ARM_CLR_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_ARM_CLR_BYPASS_MASK       (0x10000U)
#define CCM_ANALOG_PLL_ARM_CLR_BYPASS_SHIFT      (16U)
#define CCM_ANALOG_PLL_ARM_CLR_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_CLR_BYPASS_SHIFT)) & CCM_ANALOG_PLL_ARM_CLR_BYPASS_MASK)

#define CCM_ANALOG_PLL_ARM_CLR_PLL_SEL_MASK      (0x80000U)
#define CCM_ANALOG_PLL_ARM_CLR_PLL_SEL_SHIFT     (19U)
#define CCM_ANALOG_PLL_ARM_CLR_PLL_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_CLR_PLL_SEL_SHIFT)) & CCM_ANALOG_PLL_ARM_CLR_PLL_SEL_MASK)

#define CCM_ANALOG_PLL_ARM_CLR_LOCK_MASK         (0x80000000U)
#define CCM_ANALOG_PLL_ARM_CLR_LOCK_SHIFT        (31U)
#define CCM_ANALOG_PLL_ARM_CLR_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_CLR_LOCK_SHIFT)) & CCM_ANALOG_PLL_ARM_CLR_LOCK_MASK)
/*! @} */

/*! @name PLL_ARM_TOG - Analog ARM PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_ARM_TOG_DIV_SELECT_MASK   (0x7FU)
#define CCM_ANALOG_PLL_ARM_TOG_DIV_SELECT_SHIFT  (0U)
#define CCM_ANALOG_PLL_ARM_TOG_DIV_SELECT(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_TOG_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ARM_TOG_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ARM_TOG_POWERDOWN_MASK    (0x1000U)
#define CCM_ANALOG_PLL_ARM_TOG_POWERDOWN_SHIFT   (12U)
#define CCM_ANALOG_PLL_ARM_TOG_POWERDOWN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_TOG_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_ARM_TOG_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_ARM_TOG_ENABLE_MASK       (0x2000U)
#define CCM_ANALOG_PLL_ARM_TOG_ENABLE_SHIFT      (13U)
#define CCM_ANALOG_PLL_ARM_TOG_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_TOG_ENABLE_SHIFT)) & CCM_ANALOG_PLL_ARM_TOG_ENABLE_MASK)

#define CCM_ANALOG_PLL_ARM_TOG_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_ARM_TOG_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_ARM_TOG_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_TOG_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_ARM_TOG_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_ARM_TOG_BYPASS_MASK       (0x10000U)
#define CCM_ANALOG_PLL_ARM_TOG_BYPASS_SHIFT      (16U)
#define CCM_ANALOG_PLL_ARM_TOG_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_TOG_BYPASS_SHIFT)) & CCM_ANALOG_PLL_ARM_TOG_BYPASS_MASK)

#define CCM_ANALOG_PLL_ARM_TOG_PLL_SEL_MASK      (0x80000U)
#define CCM_ANALOG_PLL_ARM_TOG_PLL_SEL_SHIFT     (19U)
#define CCM_ANALOG_PLL_ARM_TOG_PLL_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_TOG_PLL_SEL_SHIFT)) & CCM_ANALOG_PLL_ARM_TOG_PLL_SEL_MASK)

#define CCM_ANALOG_PLL_ARM_TOG_LOCK_MASK         (0x80000000U)
#define CCM_ANALOG_PLL_ARM_TOG_LOCK_SHIFT        (31U)
#define CCM_ANALOG_PLL_ARM_TOG_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ARM_TOG_LOCK_SHIFT)) & CCM_ANALOG_PLL_ARM_TOG_LOCK_MASK)
/*! @} */

/*! @name PLL_USB1 - Analog USB1 480MHz PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_USB1_DIV_SELECT_MASK      (0x2U)
#define CCM_ANALOG_PLL_USB1_DIV_SELECT_SHIFT     (1U)
#define CCM_ANALOG_PLL_USB1_DIV_SELECT(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_USB1_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_USB1_EN_USB_CLKS_MASK     (0x40U)
#define CCM_ANALOG_PLL_USB1_EN_USB_CLKS_SHIFT    (6U)
/*! EN_USB_CLKS
 *  0b0..PLL outputs for USBPHYn off.
 *  0b1..PLL outputs for USBPHYn on.
 */
#define CCM_ANALOG_PLL_USB1_EN_USB_CLKS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_EN_USB_CLKS_SHIFT)) & CCM_ANALOG_PLL_USB1_EN_USB_CLKS_MASK)

#define CCM_ANALOG_PLL_USB1_POWER_MASK           (0x1000U)
#define CCM_ANALOG_PLL_USB1_POWER_SHIFT          (12U)
#define CCM_ANALOG_PLL_USB1_POWER(x)             (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_POWER_SHIFT)) & CCM_ANALOG_PLL_USB1_POWER_MASK)

#define CCM_ANALOG_PLL_USB1_ENABLE_MASK          (0x2000U)
#define CCM_ANALOG_PLL_USB1_ENABLE_SHIFT         (13U)
#define CCM_ANALOG_PLL_USB1_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_ENABLE_SHIFT)) & CCM_ANALOG_PLL_USB1_ENABLE_MASK)

#define CCM_ANALOG_PLL_USB1_BYPASS_CLK_SRC_MASK  (0xC000U)
#define CCM_ANALOG_PLL_USB1_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 */
#define CCM_ANALOG_PLL_USB1_BYPASS_CLK_SRC(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_USB1_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_USB1_BYPASS_MASK          (0x10000U)
#define CCM_ANALOG_PLL_USB1_BYPASS_SHIFT         (16U)
#define CCM_ANALOG_PLL_USB1_BYPASS(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_BYPASS_SHIFT)) & CCM_ANALOG_PLL_USB1_BYPASS_MASK)

#define CCM_ANALOG_PLL_USB1_LOCK_MASK            (0x80000000U)
#define CCM_ANALOG_PLL_USB1_LOCK_SHIFT           (31U)
#define CCM_ANALOG_PLL_USB1_LOCK(x)              (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_LOCK_SHIFT)) & CCM_ANALOG_PLL_USB1_LOCK_MASK)
/*! @} */

/*! @name PLL_USB1_SET - Analog USB1 480MHz PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_USB1_SET_DIV_SELECT_MASK  (0x2U)
#define CCM_ANALOG_PLL_USB1_SET_DIV_SELECT_SHIFT (1U)
#define CCM_ANALOG_PLL_USB1_SET_DIV_SELECT(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_SET_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_USB1_SET_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_USB1_SET_EN_USB_CLKS_MASK (0x40U)
#define CCM_ANALOG_PLL_USB1_SET_EN_USB_CLKS_SHIFT (6U)
/*! EN_USB_CLKS
 *  0b0..PLL outputs for USBPHYn off.
 *  0b1..PLL outputs for USBPHYn on.
 */
#define CCM_ANALOG_PLL_USB1_SET_EN_USB_CLKS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_SET_EN_USB_CLKS_SHIFT)) & CCM_ANALOG_PLL_USB1_SET_EN_USB_CLKS_MASK)

#define CCM_ANALOG_PLL_USB1_SET_POWER_MASK       (0x1000U)
#define CCM_ANALOG_PLL_USB1_SET_POWER_SHIFT      (12U)
#define CCM_ANALOG_PLL_USB1_SET_POWER(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_SET_POWER_SHIFT)) & CCM_ANALOG_PLL_USB1_SET_POWER_MASK)

#define CCM_ANALOG_PLL_USB1_SET_ENABLE_MASK      (0x2000U)
#define CCM_ANALOG_PLL_USB1_SET_ENABLE_SHIFT     (13U)
#define CCM_ANALOG_PLL_USB1_SET_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_SET_ENABLE_SHIFT)) & CCM_ANALOG_PLL_USB1_SET_ENABLE_MASK)

#define CCM_ANALOG_PLL_USB1_SET_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_USB1_SET_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 */
#define CCM_ANALOG_PLL_USB1_SET_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_SET_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_USB1_SET_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_USB1_SET_BYPASS_MASK      (0x10000U)
#define CCM_ANALOG_PLL_USB1_SET_BYPASS_SHIFT     (16U)
#define CCM_ANALOG_PLL_USB1_SET_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_SET_BYPASS_SHIFT)) & CCM_ANALOG_PLL_USB1_SET_BYPASS_MASK)

#define CCM_ANALOG_PLL_USB1_SET_LOCK_MASK        (0x80000000U)
#define CCM_ANALOG_PLL_USB1_SET_LOCK_SHIFT       (31U)
#define CCM_ANALOG_PLL_USB1_SET_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_SET_LOCK_SHIFT)) & CCM_ANALOG_PLL_USB1_SET_LOCK_MASK)
/*! @} */

/*! @name PLL_USB1_CLR - Analog USB1 480MHz PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_USB1_CLR_DIV_SELECT_MASK  (0x2U)
#define CCM_ANALOG_PLL_USB1_CLR_DIV_SELECT_SHIFT (1U)
#define CCM_ANALOG_PLL_USB1_CLR_DIV_SELECT(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_CLR_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_USB1_CLR_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_USB1_CLR_EN_USB_CLKS_MASK (0x40U)
#define CCM_ANALOG_PLL_USB1_CLR_EN_USB_CLKS_SHIFT (6U)
/*! EN_USB_CLKS
 *  0b0..PLL outputs for USBPHYn off.
 *  0b1..PLL outputs for USBPHYn on.
 */
#define CCM_ANALOG_PLL_USB1_CLR_EN_USB_CLKS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_CLR_EN_USB_CLKS_SHIFT)) & CCM_ANALOG_PLL_USB1_CLR_EN_USB_CLKS_MASK)

#define CCM_ANALOG_PLL_USB1_CLR_POWER_MASK       (0x1000U)
#define CCM_ANALOG_PLL_USB1_CLR_POWER_SHIFT      (12U)
#define CCM_ANALOG_PLL_USB1_CLR_POWER(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_CLR_POWER_SHIFT)) & CCM_ANALOG_PLL_USB1_CLR_POWER_MASK)

#define CCM_ANALOG_PLL_USB1_CLR_ENABLE_MASK      (0x2000U)
#define CCM_ANALOG_PLL_USB1_CLR_ENABLE_SHIFT     (13U)
#define CCM_ANALOG_PLL_USB1_CLR_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_CLR_ENABLE_SHIFT)) & CCM_ANALOG_PLL_USB1_CLR_ENABLE_MASK)

#define CCM_ANALOG_PLL_USB1_CLR_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_USB1_CLR_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 */
#define CCM_ANALOG_PLL_USB1_CLR_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_CLR_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_USB1_CLR_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_USB1_CLR_BYPASS_MASK      (0x10000U)
#define CCM_ANALOG_PLL_USB1_CLR_BYPASS_SHIFT     (16U)
#define CCM_ANALOG_PLL_USB1_CLR_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_CLR_BYPASS_SHIFT)) & CCM_ANALOG_PLL_USB1_CLR_BYPASS_MASK)

#define CCM_ANALOG_PLL_USB1_CLR_LOCK_MASK        (0x80000000U)
#define CCM_ANALOG_PLL_USB1_CLR_LOCK_SHIFT       (31U)
#define CCM_ANALOG_PLL_USB1_CLR_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_CLR_LOCK_SHIFT)) & CCM_ANALOG_PLL_USB1_CLR_LOCK_MASK)
/*! @} */

/*! @name PLL_USB1_TOG - Analog USB1 480MHz PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_USB1_TOG_DIV_SELECT_MASK  (0x2U)
#define CCM_ANALOG_PLL_USB1_TOG_DIV_SELECT_SHIFT (1U)
#define CCM_ANALOG_PLL_USB1_TOG_DIV_SELECT(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_TOG_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_USB1_TOG_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_USB1_TOG_EN_USB_CLKS_MASK (0x40U)
#define CCM_ANALOG_PLL_USB1_TOG_EN_USB_CLKS_SHIFT (6U)
/*! EN_USB_CLKS
 *  0b0..PLL outputs for USBPHYn off.
 *  0b1..PLL outputs for USBPHYn on.
 */
#define CCM_ANALOG_PLL_USB1_TOG_EN_USB_CLKS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_TOG_EN_USB_CLKS_SHIFT)) & CCM_ANALOG_PLL_USB1_TOG_EN_USB_CLKS_MASK)

#define CCM_ANALOG_PLL_USB1_TOG_POWER_MASK       (0x1000U)
#define CCM_ANALOG_PLL_USB1_TOG_POWER_SHIFT      (12U)
#define CCM_ANALOG_PLL_USB1_TOG_POWER(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_TOG_POWER_SHIFT)) & CCM_ANALOG_PLL_USB1_TOG_POWER_MASK)

#define CCM_ANALOG_PLL_USB1_TOG_ENABLE_MASK      (0x2000U)
#define CCM_ANALOG_PLL_USB1_TOG_ENABLE_SHIFT     (13U)
#define CCM_ANALOG_PLL_USB1_TOG_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_TOG_ENABLE_SHIFT)) & CCM_ANALOG_PLL_USB1_TOG_ENABLE_MASK)

#define CCM_ANALOG_PLL_USB1_TOG_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_USB1_TOG_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 */
#define CCM_ANALOG_PLL_USB1_TOG_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_TOG_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_USB1_TOG_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_USB1_TOG_BYPASS_MASK      (0x10000U)
#define CCM_ANALOG_PLL_USB1_TOG_BYPASS_SHIFT     (16U)
#define CCM_ANALOG_PLL_USB1_TOG_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_TOG_BYPASS_SHIFT)) & CCM_ANALOG_PLL_USB1_TOG_BYPASS_MASK)

#define CCM_ANALOG_PLL_USB1_TOG_LOCK_MASK        (0x80000000U)
#define CCM_ANALOG_PLL_USB1_TOG_LOCK_SHIFT       (31U)
#define CCM_ANALOG_PLL_USB1_TOG_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB1_TOG_LOCK_SHIFT)) & CCM_ANALOG_PLL_USB1_TOG_LOCK_MASK)
/*! @} */

/*! @name PLL_USB2 - Analog USB2 480MHz PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_USB2_DIV_SELECT_MASK      (0x2U)
#define CCM_ANALOG_PLL_USB2_DIV_SELECT_SHIFT     (1U)
#define CCM_ANALOG_PLL_USB2_DIV_SELECT(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_USB2_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_USB2_EN_USB_CLKS_MASK     (0x40U)
#define CCM_ANALOG_PLL_USB2_EN_USB_CLKS_SHIFT    (6U)
#define CCM_ANALOG_PLL_USB2_EN_USB_CLKS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_EN_USB_CLKS_SHIFT)) & CCM_ANALOG_PLL_USB2_EN_USB_CLKS_MASK)

#define CCM_ANALOG_PLL_USB2_POWER_MASK           (0x1000U)
#define CCM_ANALOG_PLL_USB2_POWER_SHIFT          (12U)
#define CCM_ANALOG_PLL_USB2_POWER(x)             (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_POWER_SHIFT)) & CCM_ANALOG_PLL_USB2_POWER_MASK)

#define CCM_ANALOG_PLL_USB2_ENABLE_MASK          (0x2000U)
#define CCM_ANALOG_PLL_USB2_ENABLE_SHIFT         (13U)
#define CCM_ANALOG_PLL_USB2_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_ENABLE_SHIFT)) & CCM_ANALOG_PLL_USB2_ENABLE_MASK)

#define CCM_ANALOG_PLL_USB2_BYPASS_CLK_SRC_MASK  (0xC000U)
#define CCM_ANALOG_PLL_USB2_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_USB2_BYPASS_CLK_SRC(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_USB2_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_USB2_BYPASS_MASK          (0x10000U)
#define CCM_ANALOG_PLL_USB2_BYPASS_SHIFT         (16U)
#define CCM_ANALOG_PLL_USB2_BYPASS(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_BYPASS_SHIFT)) & CCM_ANALOG_PLL_USB2_BYPASS_MASK)

#define CCM_ANALOG_PLL_USB2_LOCK_MASK            (0x80000000U)
#define CCM_ANALOG_PLL_USB2_LOCK_SHIFT           (31U)
#define CCM_ANALOG_PLL_USB2_LOCK(x)              (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_LOCK_SHIFT)) & CCM_ANALOG_PLL_USB2_LOCK_MASK)
/*! @} */

/*! @name PLL_USB2_SET - Analog USB2 480MHz PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_USB2_SET_DIV_SELECT_MASK  (0x2U)
#define CCM_ANALOG_PLL_USB2_SET_DIV_SELECT_SHIFT (1U)
#define CCM_ANALOG_PLL_USB2_SET_DIV_SELECT(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_SET_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_USB2_SET_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_USB2_SET_EN_USB_CLKS_MASK (0x40U)
#define CCM_ANALOG_PLL_USB2_SET_EN_USB_CLKS_SHIFT (6U)
#define CCM_ANALOG_PLL_USB2_SET_EN_USB_CLKS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_SET_EN_USB_CLKS_SHIFT)) & CCM_ANALOG_PLL_USB2_SET_EN_USB_CLKS_MASK)

#define CCM_ANALOG_PLL_USB2_SET_POWER_MASK       (0x1000U)
#define CCM_ANALOG_PLL_USB2_SET_POWER_SHIFT      (12U)
#define CCM_ANALOG_PLL_USB2_SET_POWER(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_SET_POWER_SHIFT)) & CCM_ANALOG_PLL_USB2_SET_POWER_MASK)

#define CCM_ANALOG_PLL_USB2_SET_ENABLE_MASK      (0x2000U)
#define CCM_ANALOG_PLL_USB2_SET_ENABLE_SHIFT     (13U)
#define CCM_ANALOG_PLL_USB2_SET_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_SET_ENABLE_SHIFT)) & CCM_ANALOG_PLL_USB2_SET_ENABLE_MASK)

#define CCM_ANALOG_PLL_USB2_SET_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_USB2_SET_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_USB2_SET_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_SET_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_USB2_SET_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_USB2_SET_BYPASS_MASK      (0x10000U)
#define CCM_ANALOG_PLL_USB2_SET_BYPASS_SHIFT     (16U)
#define CCM_ANALOG_PLL_USB2_SET_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_SET_BYPASS_SHIFT)) & CCM_ANALOG_PLL_USB2_SET_BYPASS_MASK)

#define CCM_ANALOG_PLL_USB2_SET_LOCK_MASK        (0x80000000U)
#define CCM_ANALOG_PLL_USB2_SET_LOCK_SHIFT       (31U)
#define CCM_ANALOG_PLL_USB2_SET_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_SET_LOCK_SHIFT)) & CCM_ANALOG_PLL_USB2_SET_LOCK_MASK)
/*! @} */

/*! @name PLL_USB2_CLR - Analog USB2 480MHz PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_USB2_CLR_DIV_SELECT_MASK  (0x2U)
#define CCM_ANALOG_PLL_USB2_CLR_DIV_SELECT_SHIFT (1U)
#define CCM_ANALOG_PLL_USB2_CLR_DIV_SELECT(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_CLR_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_USB2_CLR_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_USB2_CLR_EN_USB_CLKS_MASK (0x40U)
#define CCM_ANALOG_PLL_USB2_CLR_EN_USB_CLKS_SHIFT (6U)
#define CCM_ANALOG_PLL_USB2_CLR_EN_USB_CLKS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_CLR_EN_USB_CLKS_SHIFT)) & CCM_ANALOG_PLL_USB2_CLR_EN_USB_CLKS_MASK)

#define CCM_ANALOG_PLL_USB2_CLR_POWER_MASK       (0x1000U)
#define CCM_ANALOG_PLL_USB2_CLR_POWER_SHIFT      (12U)
#define CCM_ANALOG_PLL_USB2_CLR_POWER(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_CLR_POWER_SHIFT)) & CCM_ANALOG_PLL_USB2_CLR_POWER_MASK)

#define CCM_ANALOG_PLL_USB2_CLR_ENABLE_MASK      (0x2000U)
#define CCM_ANALOG_PLL_USB2_CLR_ENABLE_SHIFT     (13U)
#define CCM_ANALOG_PLL_USB2_CLR_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_CLR_ENABLE_SHIFT)) & CCM_ANALOG_PLL_USB2_CLR_ENABLE_MASK)

#define CCM_ANALOG_PLL_USB2_CLR_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_USB2_CLR_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_USB2_CLR_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_CLR_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_USB2_CLR_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_USB2_CLR_BYPASS_MASK      (0x10000U)
#define CCM_ANALOG_PLL_USB2_CLR_BYPASS_SHIFT     (16U)
#define CCM_ANALOG_PLL_USB2_CLR_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_CLR_BYPASS_SHIFT)) & CCM_ANALOG_PLL_USB2_CLR_BYPASS_MASK)

#define CCM_ANALOG_PLL_USB2_CLR_LOCK_MASK        (0x80000000U)
#define CCM_ANALOG_PLL_USB2_CLR_LOCK_SHIFT       (31U)
#define CCM_ANALOG_PLL_USB2_CLR_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_CLR_LOCK_SHIFT)) & CCM_ANALOG_PLL_USB2_CLR_LOCK_MASK)
/*! @} */

/*! @name PLL_USB2_TOG - Analog USB2 480MHz PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_USB2_TOG_DIV_SELECT_MASK  (0x2U)
#define CCM_ANALOG_PLL_USB2_TOG_DIV_SELECT_SHIFT (1U)
#define CCM_ANALOG_PLL_USB2_TOG_DIV_SELECT(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_TOG_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_USB2_TOG_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_USB2_TOG_EN_USB_CLKS_MASK (0x40U)
#define CCM_ANALOG_PLL_USB2_TOG_EN_USB_CLKS_SHIFT (6U)
#define CCM_ANALOG_PLL_USB2_TOG_EN_USB_CLKS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_TOG_EN_USB_CLKS_SHIFT)) & CCM_ANALOG_PLL_USB2_TOG_EN_USB_CLKS_MASK)

#define CCM_ANALOG_PLL_USB2_TOG_POWER_MASK       (0x1000U)
#define CCM_ANALOG_PLL_USB2_TOG_POWER_SHIFT      (12U)
#define CCM_ANALOG_PLL_USB2_TOG_POWER(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_TOG_POWER_SHIFT)) & CCM_ANALOG_PLL_USB2_TOG_POWER_MASK)

#define CCM_ANALOG_PLL_USB2_TOG_ENABLE_MASK      (0x2000U)
#define CCM_ANALOG_PLL_USB2_TOG_ENABLE_SHIFT     (13U)
#define CCM_ANALOG_PLL_USB2_TOG_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_TOG_ENABLE_SHIFT)) & CCM_ANALOG_PLL_USB2_TOG_ENABLE_MASK)

#define CCM_ANALOG_PLL_USB2_TOG_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_USB2_TOG_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_USB2_TOG_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_TOG_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_USB2_TOG_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_USB2_TOG_BYPASS_MASK      (0x10000U)
#define CCM_ANALOG_PLL_USB2_TOG_BYPASS_SHIFT     (16U)
#define CCM_ANALOG_PLL_USB2_TOG_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_TOG_BYPASS_SHIFT)) & CCM_ANALOG_PLL_USB2_TOG_BYPASS_MASK)

#define CCM_ANALOG_PLL_USB2_TOG_LOCK_MASK        (0x80000000U)
#define CCM_ANALOG_PLL_USB2_TOG_LOCK_SHIFT       (31U)
#define CCM_ANALOG_PLL_USB2_TOG_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_USB2_TOG_LOCK_SHIFT)) & CCM_ANALOG_PLL_USB2_TOG_LOCK_MASK)
/*! @} */

/*! @name PLL_SYS - Analog System PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_SYS_DIV_SELECT_MASK       (0x1U)
#define CCM_ANALOG_PLL_SYS_DIV_SELECT_SHIFT      (0U)
#define CCM_ANALOG_PLL_SYS_DIV_SELECT(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_SYS_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_SYS_POWERDOWN_MASK        (0x1000U)
#define CCM_ANALOG_PLL_SYS_POWERDOWN_SHIFT       (12U)
#define CCM_ANALOG_PLL_SYS_POWERDOWN(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_SYS_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_SYS_ENABLE_MASK           (0x2000U)
#define CCM_ANALOG_PLL_SYS_ENABLE_SHIFT          (13U)
#define CCM_ANALOG_PLL_SYS_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_ENABLE_SHIFT)) & CCM_ANALOG_PLL_SYS_ENABLE_MASK)

#define CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC_MASK   (0xC000U)
#define CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC_SHIFT  (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 */
#define CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_SYS_BYPASS_MASK           (0x10000U)
#define CCM_ANALOG_PLL_SYS_BYPASS_SHIFT          (16U)
#define CCM_ANALOG_PLL_SYS_BYPASS(x)             (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_BYPASS_SHIFT)) & CCM_ANALOG_PLL_SYS_BYPASS_MASK)

#define CCM_ANALOG_PLL_SYS_LOCK_MASK             (0x80000000U)
#define CCM_ANALOG_PLL_SYS_LOCK_SHIFT            (31U)
#define CCM_ANALOG_PLL_SYS_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_LOCK_SHIFT)) & CCM_ANALOG_PLL_SYS_LOCK_MASK)
/*! @} */

/*! @name PLL_SYS_SET - Analog System PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_SYS_SET_DIV_SELECT_MASK   (0x1U)
#define CCM_ANALOG_PLL_SYS_SET_DIV_SELECT_SHIFT  (0U)
#define CCM_ANALOG_PLL_SYS_SET_DIV_SELECT(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_SET_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_SYS_SET_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_SYS_SET_POWERDOWN_MASK    (0x1000U)
#define CCM_ANALOG_PLL_SYS_SET_POWERDOWN_SHIFT   (12U)
#define CCM_ANALOG_PLL_SYS_SET_POWERDOWN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_SET_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_SYS_SET_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_SYS_SET_ENABLE_MASK       (0x2000U)
#define CCM_ANALOG_PLL_SYS_SET_ENABLE_SHIFT      (13U)
#define CCM_ANALOG_PLL_SYS_SET_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_SET_ENABLE_SHIFT)) & CCM_ANALOG_PLL_SYS_SET_ENABLE_MASK)

#define CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 */
#define CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_SYS_SET_BYPASS_MASK       (0x10000U)
#define CCM_ANALOG_PLL_SYS_SET_BYPASS_SHIFT      (16U)
#define CCM_ANALOG_PLL_SYS_SET_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_SET_BYPASS_SHIFT)) & CCM_ANALOG_PLL_SYS_SET_BYPASS_MASK)

#define CCM_ANALOG_PLL_SYS_SET_LOCK_MASK         (0x80000000U)
#define CCM_ANALOG_PLL_SYS_SET_LOCK_SHIFT        (31U)
#define CCM_ANALOG_PLL_SYS_SET_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_SET_LOCK_SHIFT)) & CCM_ANALOG_PLL_SYS_SET_LOCK_MASK)
/*! @} */

/*! @name PLL_SYS_CLR - Analog System PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT_MASK   (0x1U)
#define CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT_SHIFT  (0U)
#define CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_SYS_CLR_POWERDOWN_MASK    (0x1000U)
#define CCM_ANALOG_PLL_SYS_CLR_POWERDOWN_SHIFT   (12U)
#define CCM_ANALOG_PLL_SYS_CLR_POWERDOWN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_CLR_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_SYS_CLR_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_SYS_CLR_ENABLE_MASK       (0x2000U)
#define CCM_ANALOG_PLL_SYS_CLR_ENABLE_SHIFT      (13U)
#define CCM_ANALOG_PLL_SYS_CLR_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_CLR_ENABLE_SHIFT)) & CCM_ANALOG_PLL_SYS_CLR_ENABLE_MASK)

#define CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 */
#define CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_SYS_CLR_BYPASS_MASK       (0x10000U)
#define CCM_ANALOG_PLL_SYS_CLR_BYPASS_SHIFT      (16U)
#define CCM_ANALOG_PLL_SYS_CLR_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_CLR_BYPASS_SHIFT)) & CCM_ANALOG_PLL_SYS_CLR_BYPASS_MASK)

#define CCM_ANALOG_PLL_SYS_CLR_LOCK_MASK         (0x80000000U)
#define CCM_ANALOG_PLL_SYS_CLR_LOCK_SHIFT        (31U)
#define CCM_ANALOG_PLL_SYS_CLR_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_CLR_LOCK_SHIFT)) & CCM_ANALOG_PLL_SYS_CLR_LOCK_MASK)
/*! @} */

/*! @name PLL_SYS_TOG - Analog System PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT_MASK   (0x1U)
#define CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT_SHIFT  (0U)
#define CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_SYS_TOG_POWERDOWN_MASK    (0x1000U)
#define CCM_ANALOG_PLL_SYS_TOG_POWERDOWN_SHIFT   (12U)
#define CCM_ANALOG_PLL_SYS_TOG_POWERDOWN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_TOG_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_SYS_TOG_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_SYS_TOG_ENABLE_MASK       (0x2000U)
#define CCM_ANALOG_PLL_SYS_TOG_ENABLE_SHIFT      (13U)
#define CCM_ANALOG_PLL_SYS_TOG_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_TOG_ENABLE_SHIFT)) & CCM_ANALOG_PLL_SYS_TOG_ENABLE_MASK)

#define CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 */
#define CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_SYS_TOG_BYPASS_MASK       (0x10000U)
#define CCM_ANALOG_PLL_SYS_TOG_BYPASS_SHIFT      (16U)
#define CCM_ANALOG_PLL_SYS_TOG_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_TOG_BYPASS_SHIFT)) & CCM_ANALOG_PLL_SYS_TOG_BYPASS_MASK)

#define CCM_ANALOG_PLL_SYS_TOG_LOCK_MASK         (0x80000000U)
#define CCM_ANALOG_PLL_SYS_TOG_LOCK_SHIFT        (31U)
#define CCM_ANALOG_PLL_SYS_TOG_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_TOG_LOCK_SHIFT)) & CCM_ANALOG_PLL_SYS_TOG_LOCK_MASK)
/*! @} */

/*! @name PLL_SYS_SS - 528MHz System PLL Spread Spectrum Register */
/*! @{ */

#define CCM_ANALOG_PLL_SYS_SS_STEP_MASK          (0x7FFFU)
#define CCM_ANALOG_PLL_SYS_SS_STEP_SHIFT         (0U)
#define CCM_ANALOG_PLL_SYS_SS_STEP(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_SS_STEP_SHIFT)) & CCM_ANALOG_PLL_SYS_SS_STEP_MASK)

#define CCM_ANALOG_PLL_SYS_SS_ENABLE_MASK        (0x8000U)
#define CCM_ANALOG_PLL_SYS_SS_ENABLE_SHIFT       (15U)
/*! ENABLE - Enable bit
 *  0b0..Spread spectrum modulation disabled
 *  0b1..Spread spectrum modulation enabled
 */
#define CCM_ANALOG_PLL_SYS_SS_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_SS_ENABLE_SHIFT)) & CCM_ANALOG_PLL_SYS_SS_ENABLE_MASK)

#define CCM_ANALOG_PLL_SYS_SS_STOP_MASK          (0xFFFF0000U)
#define CCM_ANALOG_PLL_SYS_SS_STOP_SHIFT         (16U)
#define CCM_ANALOG_PLL_SYS_SS_STOP(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_SS_STOP_SHIFT)) & CCM_ANALOG_PLL_SYS_SS_STOP_MASK)
/*! @} */

/*! @name PLL_SYS_NUM - Numerator of 528MHz System PLL Fractional Loop Divider Register */
/*! @{ */

#define CCM_ANALOG_PLL_SYS_NUM_A_MASK            (0x3FFFFFFFU)
#define CCM_ANALOG_PLL_SYS_NUM_A_SHIFT           (0U)
#define CCM_ANALOG_PLL_SYS_NUM_A(x)              (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_NUM_A_SHIFT)) & CCM_ANALOG_PLL_SYS_NUM_A_MASK)
/*! @} */

/*! @name PLL_SYS_DENOM - Denominator of 528MHz System PLL Fractional Loop Divider Register */
/*! @{ */

#define CCM_ANALOG_PLL_SYS_DENOM_B_MASK          (0x3FFFFFFFU)
#define CCM_ANALOG_PLL_SYS_DENOM_B_SHIFT         (0U)
#define CCM_ANALOG_PLL_SYS_DENOM_B(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_SYS_DENOM_B_SHIFT)) & CCM_ANALOG_PLL_SYS_DENOM_B_MASK)
/*! @} */

/*! @name PLL_AUDIO - Analog Audio PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_AUDIO_DIV_SELECT_MASK     (0x7FU)
#define CCM_ANALOG_PLL_AUDIO_DIV_SELECT_SHIFT    (0U)
#define CCM_ANALOG_PLL_AUDIO_DIV_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_AUDIO_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_AUDIO_POWERDOWN_MASK      (0x1000U)
#define CCM_ANALOG_PLL_AUDIO_POWERDOWN_SHIFT     (12U)
#define CCM_ANALOG_PLL_AUDIO_POWERDOWN(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_AUDIO_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_AUDIO_ENABLE_MASK         (0x2000U)
#define CCM_ANALOG_PLL_AUDIO_ENABLE_SHIFT        (13U)
#define CCM_ANALOG_PLL_AUDIO_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_ENABLE_SHIFT)) & CCM_ANALOG_PLL_AUDIO_ENABLE_MASK)

#define CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_AUDIO_BYPASS_MASK         (0x10000U)
#define CCM_ANALOG_PLL_AUDIO_BYPASS_SHIFT        (16U)
#define CCM_ANALOG_PLL_AUDIO_BYPASS(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_BYPASS_SHIFT)) & CCM_ANALOG_PLL_AUDIO_BYPASS_MASK)

#define CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT_MASK (0x180000U)
#define CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT_SHIFT (19U)
/*! POST_DIV_SELECT
 *  0b00..Divide by 4.
 *  0b01..Divide by 2.
 *  0b10..Divide by 1.
 *  0b11..Reserved
 */
#define CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_AUDIO_LOCK_MASK           (0x80000000U)
#define CCM_ANALOG_PLL_AUDIO_LOCK_SHIFT          (31U)
#define CCM_ANALOG_PLL_AUDIO_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_LOCK_SHIFT)) & CCM_ANALOG_PLL_AUDIO_LOCK_MASK)
/*! @} */

/*! @name PLL_AUDIO_SET - Analog Audio PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT_MASK (0x7FU)
#define CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT_SHIFT (0U)
#define CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN_MASK  (0x1000U)
#define CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN_SHIFT (12U)
#define CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_AUDIO_SET_ENABLE_MASK     (0x2000U)
#define CCM_ANALOG_PLL_AUDIO_SET_ENABLE_SHIFT    (13U)
#define CCM_ANALOG_PLL_AUDIO_SET_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_SET_ENABLE_SHIFT)) & CCM_ANALOG_PLL_AUDIO_SET_ENABLE_MASK)

#define CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_AUDIO_SET_BYPASS_MASK     (0x10000U)
#define CCM_ANALOG_PLL_AUDIO_SET_BYPASS_SHIFT    (16U)
#define CCM_ANALOG_PLL_AUDIO_SET_BYPASS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_SET_BYPASS_SHIFT)) & CCM_ANALOG_PLL_AUDIO_SET_BYPASS_MASK)

#define CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT_MASK (0x180000U)
#define CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT_SHIFT (19U)
/*! POST_DIV_SELECT
 *  0b00..Divide by 4.
 *  0b01..Divide by 2.
 *  0b10..Divide by 1.
 *  0b11..Reserved
 */
#define CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_AUDIO_SET_LOCK_MASK       (0x80000000U)
#define CCM_ANALOG_PLL_AUDIO_SET_LOCK_SHIFT      (31U)
#define CCM_ANALOG_PLL_AUDIO_SET_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_SET_LOCK_SHIFT)) & CCM_ANALOG_PLL_AUDIO_SET_LOCK_MASK)
/*! @} */

/*! @name PLL_AUDIO_CLR - Analog Audio PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT_MASK (0x7FU)
#define CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT_SHIFT (0U)
#define CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN_MASK  (0x1000U)
#define CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN_SHIFT (12U)
#define CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_AUDIO_CLR_ENABLE_MASK     (0x2000U)
#define CCM_ANALOG_PLL_AUDIO_CLR_ENABLE_SHIFT    (13U)
#define CCM_ANALOG_PLL_AUDIO_CLR_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_CLR_ENABLE_SHIFT)) & CCM_ANALOG_PLL_AUDIO_CLR_ENABLE_MASK)

#define CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_MASK     (0x10000U)
#define CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_SHIFT    (16U)
#define CCM_ANALOG_PLL_AUDIO_CLR_BYPASS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_SHIFT)) & CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_MASK)

#define CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT_MASK (0x180000U)
#define CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT_SHIFT (19U)
/*! POST_DIV_SELECT
 *  0b00..Divide by 4.
 *  0b01..Divide by 2.
 *  0b10..Divide by 1.
 *  0b11..Reserved
 */
#define CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_AUDIO_CLR_LOCK_MASK       (0x80000000U)
#define CCM_ANALOG_PLL_AUDIO_CLR_LOCK_SHIFT      (31U)
#define CCM_ANALOG_PLL_AUDIO_CLR_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_CLR_LOCK_SHIFT)) & CCM_ANALOG_PLL_AUDIO_CLR_LOCK_MASK)
/*! @} */

/*! @name PLL_AUDIO_TOG - Analog Audio PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT_MASK (0x7FU)
#define CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT_SHIFT (0U)
#define CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN_MASK  (0x1000U)
#define CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN_SHIFT (12U)
#define CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_AUDIO_TOG_ENABLE_MASK     (0x2000U)
#define CCM_ANALOG_PLL_AUDIO_TOG_ENABLE_SHIFT    (13U)
#define CCM_ANALOG_PLL_AUDIO_TOG_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_TOG_ENABLE_SHIFT)) & CCM_ANALOG_PLL_AUDIO_TOG_ENABLE_MASK)

#define CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_MASK     (0x10000U)
#define CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_SHIFT    (16U)
#define CCM_ANALOG_PLL_AUDIO_TOG_BYPASS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_SHIFT)) & CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_MASK)

#define CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT_MASK (0x180000U)
#define CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT_SHIFT (19U)
/*! POST_DIV_SELECT
 *  0b00..Divide by 4.
 *  0b01..Divide by 2.
 *  0b10..Divide by 1.
 *  0b11..Reserved
 */
#define CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_AUDIO_TOG_LOCK_MASK       (0x80000000U)
#define CCM_ANALOG_PLL_AUDIO_TOG_LOCK_SHIFT      (31U)
#define CCM_ANALOG_PLL_AUDIO_TOG_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_TOG_LOCK_SHIFT)) & CCM_ANALOG_PLL_AUDIO_TOG_LOCK_MASK)
/*! @} */

/*! @name PLL_AUDIO_NUM - Numerator of Audio PLL Fractional Loop Divider Register */
/*! @{ */

#define CCM_ANALOG_PLL_AUDIO_NUM_A_MASK          (0x3FFFFFFFU)
#define CCM_ANALOG_PLL_AUDIO_NUM_A_SHIFT         (0U)
#define CCM_ANALOG_PLL_AUDIO_NUM_A(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_NUM_A_SHIFT)) & CCM_ANALOG_PLL_AUDIO_NUM_A_MASK)
/*! @} */

/*! @name PLL_AUDIO_DENOM - Denominator of Audio PLL Fractional Loop Divider Register */
/*! @{ */

#define CCM_ANALOG_PLL_AUDIO_DENOM_B_MASK        (0x3FFFFFFFU)
#define CCM_ANALOG_PLL_AUDIO_DENOM_B_SHIFT       (0U)
#define CCM_ANALOG_PLL_AUDIO_DENOM_B(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_AUDIO_DENOM_B_SHIFT)) & CCM_ANALOG_PLL_AUDIO_DENOM_B_MASK)
/*! @} */

/*! @name PLL_VIDEO - Analog Video PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_VIDEO_DIV_SELECT_MASK     (0x7FU)
#define CCM_ANALOG_PLL_VIDEO_DIV_SELECT_SHIFT    (0U)
#define CCM_ANALOG_PLL_VIDEO_DIV_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_VIDEO_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_VIDEO_POWERDOWN_MASK      (0x1000U)
#define CCM_ANALOG_PLL_VIDEO_POWERDOWN_SHIFT     (12U)
#define CCM_ANALOG_PLL_VIDEO_POWERDOWN(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_VIDEO_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_VIDEO_ENABLE_MASK         (0x2000U)
#define CCM_ANALOG_PLL_VIDEO_ENABLE_SHIFT        (13U)
#define CCM_ANALOG_PLL_VIDEO_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_ENABLE_SHIFT)) & CCM_ANALOG_PLL_VIDEO_ENABLE_MASK)

#define CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_VIDEO_BYPASS_MASK         (0x10000U)
#define CCM_ANALOG_PLL_VIDEO_BYPASS_SHIFT        (16U)
#define CCM_ANALOG_PLL_VIDEO_BYPASS(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_BYPASS_SHIFT)) & CCM_ANALOG_PLL_VIDEO_BYPASS_MASK)

#define CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT_MASK (0x180000U)
#define CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT_SHIFT (19U)
/*! POST_DIV_SELECT
 *  0b00..Divide by 4.
 *  0b01..Divide by 2.
 *  0b10..Divide by 1.
 *  0b11..Reserved
 */
#define CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_VIDEO_LOCK_MASK           (0x80000000U)
#define CCM_ANALOG_PLL_VIDEO_LOCK_SHIFT          (31U)
#define CCM_ANALOG_PLL_VIDEO_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_LOCK_SHIFT)) & CCM_ANALOG_PLL_VIDEO_LOCK_MASK)
/*! @} */

/*! @name PLL_VIDEO_SET - Analog Video PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT_MASK (0x7FU)
#define CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT_SHIFT (0U)
#define CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN_MASK  (0x1000U)
#define CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN_SHIFT (12U)
#define CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_VIDEO_SET_ENABLE_MASK     (0x2000U)
#define CCM_ANALOG_PLL_VIDEO_SET_ENABLE_SHIFT    (13U)
#define CCM_ANALOG_PLL_VIDEO_SET_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_SET_ENABLE_SHIFT)) & CCM_ANALOG_PLL_VIDEO_SET_ENABLE_MASK)

#define CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_VIDEO_SET_BYPASS_MASK     (0x10000U)
#define CCM_ANALOG_PLL_VIDEO_SET_BYPASS_SHIFT    (16U)
#define CCM_ANALOG_PLL_VIDEO_SET_BYPASS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_SET_BYPASS_SHIFT)) & CCM_ANALOG_PLL_VIDEO_SET_BYPASS_MASK)

#define CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT_MASK (0x180000U)
#define CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT_SHIFT (19U)
/*! POST_DIV_SELECT
 *  0b00..Divide by 4.
 *  0b01..Divide by 2.
 *  0b10..Divide by 1.
 *  0b11..Reserved
 */
#define CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_VIDEO_SET_LOCK_MASK       (0x80000000U)
#define CCM_ANALOG_PLL_VIDEO_SET_LOCK_SHIFT      (31U)
#define CCM_ANALOG_PLL_VIDEO_SET_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_SET_LOCK_SHIFT)) & CCM_ANALOG_PLL_VIDEO_SET_LOCK_MASK)
/*! @} */

/*! @name PLL_VIDEO_CLR - Analog Video PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT_MASK (0x7FU)
#define CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT_SHIFT (0U)
#define CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN_MASK  (0x1000U)
#define CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN_SHIFT (12U)
#define CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_VIDEO_CLR_ENABLE_MASK     (0x2000U)
#define CCM_ANALOG_PLL_VIDEO_CLR_ENABLE_SHIFT    (13U)
#define CCM_ANALOG_PLL_VIDEO_CLR_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_CLR_ENABLE_SHIFT)) & CCM_ANALOG_PLL_VIDEO_CLR_ENABLE_MASK)

#define CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_MASK     (0x10000U)
#define CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_SHIFT    (16U)
#define CCM_ANALOG_PLL_VIDEO_CLR_BYPASS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_SHIFT)) & CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_MASK)

#define CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT_MASK (0x180000U)
#define CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT_SHIFT (19U)
/*! POST_DIV_SELECT
 *  0b00..Divide by 4.
 *  0b01..Divide by 2.
 *  0b10..Divide by 1.
 *  0b11..Reserved
 */
#define CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_VIDEO_CLR_LOCK_MASK       (0x80000000U)
#define CCM_ANALOG_PLL_VIDEO_CLR_LOCK_SHIFT      (31U)
#define CCM_ANALOG_PLL_VIDEO_CLR_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_CLR_LOCK_SHIFT)) & CCM_ANALOG_PLL_VIDEO_CLR_LOCK_MASK)
/*! @} */

/*! @name PLL_VIDEO_TOG - Analog Video PLL control Register */
/*! @{ */

#define CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT_MASK (0x7FU)
#define CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT_SHIFT (0U)
#define CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN_MASK  (0x1000U)
#define CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN_SHIFT (12U)
#define CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_VIDEO_TOG_ENABLE_MASK     (0x2000U)
#define CCM_ANALOG_PLL_VIDEO_TOG_ENABLE_SHIFT    (13U)
#define CCM_ANALOG_PLL_VIDEO_TOG_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_TOG_ENABLE_SHIFT)) & CCM_ANALOG_PLL_VIDEO_TOG_ENABLE_MASK)

#define CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_MASK     (0x10000U)
#define CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_SHIFT    (16U)
#define CCM_ANALOG_PLL_VIDEO_TOG_BYPASS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_SHIFT)) & CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_MASK)

#define CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT_MASK (0x180000U)
#define CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT_SHIFT (19U)
/*! POST_DIV_SELECT
 *  0b00..Divide by 4.
 *  0b01..Divide by 2.
 *  0b10..Divide by 1.
 *  0b11..Reserved
 */
#define CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_VIDEO_TOG_LOCK_MASK       (0x80000000U)
#define CCM_ANALOG_PLL_VIDEO_TOG_LOCK_SHIFT      (31U)
#define CCM_ANALOG_PLL_VIDEO_TOG_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_TOG_LOCK_SHIFT)) & CCM_ANALOG_PLL_VIDEO_TOG_LOCK_MASK)
/*! @} */

/*! @name PLL_VIDEO_NUM - Numerator of Video PLL Fractional Loop Divider Register */
/*! @{ */

#define CCM_ANALOG_PLL_VIDEO_NUM_A_MASK          (0x3FFFFFFFU)
#define CCM_ANALOG_PLL_VIDEO_NUM_A_SHIFT         (0U)
#define CCM_ANALOG_PLL_VIDEO_NUM_A(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_NUM_A_SHIFT)) & CCM_ANALOG_PLL_VIDEO_NUM_A_MASK)
/*! @} */

/*! @name PLL_VIDEO_DENOM - Denominator of Video PLL Fractional Loop Divider Register */
/*! @{ */

#define CCM_ANALOG_PLL_VIDEO_DENOM_B_MASK        (0x3FFFFFFFU)
#define CCM_ANALOG_PLL_VIDEO_DENOM_B_SHIFT       (0U)
#define CCM_ANALOG_PLL_VIDEO_DENOM_B(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_VIDEO_DENOM_B_SHIFT)) & CCM_ANALOG_PLL_VIDEO_DENOM_B_MASK)
/*! @} */

/*! @name PLL_ENET - Analog ENET PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_ENET_DIV_SELECT_MASK      (0x3U)
#define CCM_ANALOG_PLL_ENET_DIV_SELECT_SHIFT     (0U)
#define CCM_ANALOG_PLL_ENET_DIV_SELECT(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ENET_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT_MASK (0xCU)
#define CCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT_SHIFT (2U)
/*! ENET2_DIV_SELECT
 *  0b00..25MHz
 *  0b01..50MHz
 *  0b10..100MHz (not 50% duty cycle)
 *  0b11..125MHz
 */
#define CCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ENET_POWERDOWN_MASK       (0x1000U)
#define CCM_ANALOG_PLL_ENET_POWERDOWN_SHIFT      (12U)
#define CCM_ANALOG_PLL_ENET_POWERDOWN(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_ENET_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_ENET_ENABLE_MASK          (0x2000U)
#define CCM_ANALOG_PLL_ENET_ENABLE_SHIFT         (13U)
#define CCM_ANALOG_PLL_ENET_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_ENABLE_SHIFT)) & CCM_ANALOG_PLL_ENET_ENABLE_MASK)

#define CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC_MASK  (0xC000U)
#define CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_ENET_BYPASS_MASK          (0x10000U)
#define CCM_ANALOG_PLL_ENET_BYPASS_SHIFT         (16U)
#define CCM_ANALOG_PLL_ENET_BYPASS(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_BYPASS_SHIFT)) & CCM_ANALOG_PLL_ENET_BYPASS_MASK)

#define CCM_ANALOG_PLL_ENET_ENET2_REF_EN_MASK    (0x100000U)
#define CCM_ANALOG_PLL_ENET_ENET2_REF_EN_SHIFT   (20U)
#define CCM_ANALOG_PLL_ENET_ENET2_REF_EN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_ENET2_REF_EN_SHIFT)) & CCM_ANALOG_PLL_ENET_ENET2_REF_EN_MASK)

#define CCM_ANALOG_PLL_ENET_ENET_25M_REF_EN_MASK (0x200000U)
#define CCM_ANALOG_PLL_ENET_ENET_25M_REF_EN_SHIFT (21U)
#define CCM_ANALOG_PLL_ENET_ENET_25M_REF_EN(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_ENET_25M_REF_EN_SHIFT)) & CCM_ANALOG_PLL_ENET_ENET_25M_REF_EN_MASK)

#define CCM_ANALOG_PLL_ENET_LOCK_MASK            (0x80000000U)
#define CCM_ANALOG_PLL_ENET_LOCK_SHIFT           (31U)
#define CCM_ANALOG_PLL_ENET_LOCK(x)              (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_LOCK_SHIFT)) & CCM_ANALOG_PLL_ENET_LOCK_MASK)
/*! @} */

/*! @name PLL_ENET_SET - Analog ENET PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_ENET_SET_DIV_SELECT_MASK  (0x3U)
#define CCM_ANALOG_PLL_ENET_SET_DIV_SELECT_SHIFT (0U)
#define CCM_ANALOG_PLL_ENET_SET_DIV_SELECT(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_SET_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ENET_SET_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ENET_SET_ENET2_DIV_SELECT_MASK (0xCU)
#define CCM_ANALOG_PLL_ENET_SET_ENET2_DIV_SELECT_SHIFT (2U)
/*! ENET2_DIV_SELECT
 *  0b00..25MHz
 *  0b01..50MHz
 *  0b10..100MHz (not 50% duty cycle)
 *  0b11..125MHz
 */
#define CCM_ANALOG_PLL_ENET_SET_ENET2_DIV_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_SET_ENET2_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ENET_SET_ENET2_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ENET_SET_POWERDOWN_MASK   (0x1000U)
#define CCM_ANALOG_PLL_ENET_SET_POWERDOWN_SHIFT  (12U)
#define CCM_ANALOG_PLL_ENET_SET_POWERDOWN(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_SET_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_ENET_SET_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_ENET_SET_ENABLE_MASK      (0x2000U)
#define CCM_ANALOG_PLL_ENET_SET_ENABLE_SHIFT     (13U)
#define CCM_ANALOG_PLL_ENET_SET_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_SET_ENABLE_SHIFT)) & CCM_ANALOG_PLL_ENET_SET_ENABLE_MASK)

#define CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_ENET_SET_BYPASS_MASK      (0x10000U)
#define CCM_ANALOG_PLL_ENET_SET_BYPASS_SHIFT     (16U)
#define CCM_ANALOG_PLL_ENET_SET_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_SET_BYPASS_SHIFT)) & CCM_ANALOG_PLL_ENET_SET_BYPASS_MASK)

#define CCM_ANALOG_PLL_ENET_SET_ENET2_REF_EN_MASK (0x100000U)
#define CCM_ANALOG_PLL_ENET_SET_ENET2_REF_EN_SHIFT (20U)
#define CCM_ANALOG_PLL_ENET_SET_ENET2_REF_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_SET_ENET2_REF_EN_SHIFT)) & CCM_ANALOG_PLL_ENET_SET_ENET2_REF_EN_MASK)

#define CCM_ANALOG_PLL_ENET_SET_ENET_25M_REF_EN_MASK (0x200000U)
#define CCM_ANALOG_PLL_ENET_SET_ENET_25M_REF_EN_SHIFT (21U)
#define CCM_ANALOG_PLL_ENET_SET_ENET_25M_REF_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_SET_ENET_25M_REF_EN_SHIFT)) & CCM_ANALOG_PLL_ENET_SET_ENET_25M_REF_EN_MASK)

#define CCM_ANALOG_PLL_ENET_SET_LOCK_MASK        (0x80000000U)
#define CCM_ANALOG_PLL_ENET_SET_LOCK_SHIFT       (31U)
#define CCM_ANALOG_PLL_ENET_SET_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_SET_LOCK_SHIFT)) & CCM_ANALOG_PLL_ENET_SET_LOCK_MASK)
/*! @} */

/*! @name PLL_ENET_CLR - Analog ENET PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT_MASK  (0x3U)
#define CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT_SHIFT (0U)
#define CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ENET_CLR_ENET2_DIV_SELECT_MASK (0xCU)
#define CCM_ANALOG_PLL_ENET_CLR_ENET2_DIV_SELECT_SHIFT (2U)
/*! ENET2_DIV_SELECT
 *  0b00..25MHz
 *  0b01..50MHz
 *  0b10..100MHz (not 50% duty cycle)
 *  0b11..125MHz
 */
#define CCM_ANALOG_PLL_ENET_CLR_ENET2_DIV_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_CLR_ENET2_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ENET_CLR_ENET2_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ENET_CLR_POWERDOWN_MASK   (0x1000U)
#define CCM_ANALOG_PLL_ENET_CLR_POWERDOWN_SHIFT  (12U)
#define CCM_ANALOG_PLL_ENET_CLR_POWERDOWN(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_CLR_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_ENET_CLR_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_ENET_CLR_ENABLE_MASK      (0x2000U)
#define CCM_ANALOG_PLL_ENET_CLR_ENABLE_SHIFT     (13U)
#define CCM_ANALOG_PLL_ENET_CLR_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_CLR_ENABLE_SHIFT)) & CCM_ANALOG_PLL_ENET_CLR_ENABLE_MASK)

#define CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_ENET_CLR_BYPASS_MASK      (0x10000U)
#define CCM_ANALOG_PLL_ENET_CLR_BYPASS_SHIFT     (16U)
#define CCM_ANALOG_PLL_ENET_CLR_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_CLR_BYPASS_SHIFT)) & CCM_ANALOG_PLL_ENET_CLR_BYPASS_MASK)

#define CCM_ANALOG_PLL_ENET_CLR_ENET2_REF_EN_MASK (0x100000U)
#define CCM_ANALOG_PLL_ENET_CLR_ENET2_REF_EN_SHIFT (20U)
#define CCM_ANALOG_PLL_ENET_CLR_ENET2_REF_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_CLR_ENET2_REF_EN_SHIFT)) & CCM_ANALOG_PLL_ENET_CLR_ENET2_REF_EN_MASK)

#define CCM_ANALOG_PLL_ENET_CLR_ENET_25M_REF_EN_MASK (0x200000U)
#define CCM_ANALOG_PLL_ENET_CLR_ENET_25M_REF_EN_SHIFT (21U)
#define CCM_ANALOG_PLL_ENET_CLR_ENET_25M_REF_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_CLR_ENET_25M_REF_EN_SHIFT)) & CCM_ANALOG_PLL_ENET_CLR_ENET_25M_REF_EN_MASK)

#define CCM_ANALOG_PLL_ENET_CLR_LOCK_MASK        (0x80000000U)
#define CCM_ANALOG_PLL_ENET_CLR_LOCK_SHIFT       (31U)
#define CCM_ANALOG_PLL_ENET_CLR_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_CLR_LOCK_SHIFT)) & CCM_ANALOG_PLL_ENET_CLR_LOCK_MASK)
/*! @} */

/*! @name PLL_ENET_TOG - Analog ENET PLL Control Register */
/*! @{ */

#define CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT_MASK  (0x3U)
#define CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT_SHIFT (0U)
#define CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ENET_TOG_ENET2_DIV_SELECT_MASK (0xCU)
#define CCM_ANALOG_PLL_ENET_TOG_ENET2_DIV_SELECT_SHIFT (2U)
/*! ENET2_DIV_SELECT
 *  0b00..25MHz
 *  0b01..50MHz
 *  0b10..100MHz (not 50% duty cycle)
 *  0b11..125MHz
 */
#define CCM_ANALOG_PLL_ENET_TOG_ENET2_DIV_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_TOG_ENET2_DIV_SELECT_SHIFT)) & CCM_ANALOG_PLL_ENET_TOG_ENET2_DIV_SELECT_MASK)

#define CCM_ANALOG_PLL_ENET_TOG_POWERDOWN_MASK   (0x1000U)
#define CCM_ANALOG_PLL_ENET_TOG_POWERDOWN_SHIFT  (12U)
#define CCM_ANALOG_PLL_ENET_TOG_POWERDOWN(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_TOG_POWERDOWN_SHIFT)) & CCM_ANALOG_PLL_ENET_TOG_POWERDOWN_MASK)

#define CCM_ANALOG_PLL_ENET_TOG_ENABLE_MASK      (0x2000U)
#define CCM_ANALOG_PLL_ENET_TOG_ENABLE_SHIFT     (13U)
#define CCM_ANALOG_PLL_ENET_TOG_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_TOG_ENABLE_SHIFT)) & CCM_ANALOG_PLL_ENET_TOG_ENABLE_MASK)

#define CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC_MASK (0xC000U)
#define CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC_SHIFT (14U)
/*! BYPASS_CLK_SRC
 *  0b00..Select the 24MHz oscillator as source.
 *  0b01..Select the CLK1_N / CLK1_P as source.
 *  0b10..Reserved1
 *  0b11..Reserved2
 */
#define CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC_SHIFT)) & CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC_MASK)

#define CCM_ANALOG_PLL_ENET_TOG_BYPASS_MASK      (0x10000U)
#define CCM_ANALOG_PLL_ENET_TOG_BYPASS_SHIFT     (16U)
#define CCM_ANALOG_PLL_ENET_TOG_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_TOG_BYPASS_SHIFT)) & CCM_ANALOG_PLL_ENET_TOG_BYPASS_MASK)

#define CCM_ANALOG_PLL_ENET_TOG_ENET2_REF_EN_MASK (0x100000U)
#define CCM_ANALOG_PLL_ENET_TOG_ENET2_REF_EN_SHIFT (20U)
#define CCM_ANALOG_PLL_ENET_TOG_ENET2_REF_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_TOG_ENET2_REF_EN_SHIFT)) & CCM_ANALOG_PLL_ENET_TOG_ENET2_REF_EN_MASK)

#define CCM_ANALOG_PLL_ENET_TOG_ENET_25M_REF_EN_MASK (0x200000U)
#define CCM_ANALOG_PLL_ENET_TOG_ENET_25M_REF_EN_SHIFT (21U)
#define CCM_ANALOG_PLL_ENET_TOG_ENET_25M_REF_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_TOG_ENET_25M_REF_EN_SHIFT)) & CCM_ANALOG_PLL_ENET_TOG_ENET_25M_REF_EN_MASK)

#define CCM_ANALOG_PLL_ENET_TOG_LOCK_MASK        (0x80000000U)
#define CCM_ANALOG_PLL_ENET_TOG_LOCK_SHIFT       (31U)
#define CCM_ANALOG_PLL_ENET_TOG_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PLL_ENET_TOG_LOCK_SHIFT)) & CCM_ANALOG_PLL_ENET_TOG_LOCK_MASK)
/*! @} */

/*! @name PFD_480 - 480MHz Clock (PLL3) Phase Fractional Divider Control Register */
/*! @{ */

#define CCM_ANALOG_PFD_480_PFD0_FRAC_MASK        (0x3FU)
#define CCM_ANALOG_PFD_480_PFD0_FRAC_SHIFT       (0U)
#define CCM_ANALOG_PFD_480_PFD0_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD0_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_PFD0_FRAC_MASK)

#define CCM_ANALOG_PFD_480_PFD0_STABLE_MASK      (0x40U)
#define CCM_ANALOG_PFD_480_PFD0_STABLE_SHIFT     (6U)
#define CCM_ANALOG_PFD_480_PFD0_STABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD0_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_PFD0_STABLE_MASK)

#define CCM_ANALOG_PFD_480_PFD0_CLKGATE_MASK     (0x80U)
#define CCM_ANALOG_PFD_480_PFD0_CLKGATE_SHIFT    (7U)
#define CCM_ANALOG_PFD_480_PFD0_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD0_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_PFD0_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_PFD1_FRAC_MASK        (0x3F00U)
#define CCM_ANALOG_PFD_480_PFD1_FRAC_SHIFT       (8U)
#define CCM_ANALOG_PFD_480_PFD1_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD1_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_PFD1_FRAC_MASK)

#define CCM_ANALOG_PFD_480_PFD1_STABLE_MASK      (0x4000U)
#define CCM_ANALOG_PFD_480_PFD1_STABLE_SHIFT     (14U)
#define CCM_ANALOG_PFD_480_PFD1_STABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD1_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_PFD1_STABLE_MASK)

#define CCM_ANALOG_PFD_480_PFD1_CLKGATE_MASK     (0x8000U)
#define CCM_ANALOG_PFD_480_PFD1_CLKGATE_SHIFT    (15U)
#define CCM_ANALOG_PFD_480_PFD1_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD1_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_PFD1_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_PFD2_FRAC_MASK        (0x3F0000U)
#define CCM_ANALOG_PFD_480_PFD2_FRAC_SHIFT       (16U)
#define CCM_ANALOG_PFD_480_PFD2_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD2_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_PFD2_FRAC_MASK)

#define CCM_ANALOG_PFD_480_PFD2_STABLE_MASK      (0x400000U)
#define CCM_ANALOG_PFD_480_PFD2_STABLE_SHIFT     (22U)
#define CCM_ANALOG_PFD_480_PFD2_STABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD2_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_PFD2_STABLE_MASK)

#define CCM_ANALOG_PFD_480_PFD2_CLKGATE_MASK     (0x800000U)
#define CCM_ANALOG_PFD_480_PFD2_CLKGATE_SHIFT    (23U)
#define CCM_ANALOG_PFD_480_PFD2_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD2_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_PFD2_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_PFD3_FRAC_MASK        (0x3F000000U)
#define CCM_ANALOG_PFD_480_PFD3_FRAC_SHIFT       (24U)
#define CCM_ANALOG_PFD_480_PFD3_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD3_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_PFD3_FRAC_MASK)

#define CCM_ANALOG_PFD_480_PFD3_STABLE_MASK      (0x40000000U)
#define CCM_ANALOG_PFD_480_PFD3_STABLE_SHIFT     (30U)
#define CCM_ANALOG_PFD_480_PFD3_STABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD3_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_PFD3_STABLE_MASK)

#define CCM_ANALOG_PFD_480_PFD3_CLKGATE_MASK     (0x80000000U)
#define CCM_ANALOG_PFD_480_PFD3_CLKGATE_SHIFT    (31U)
#define CCM_ANALOG_PFD_480_PFD3_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_PFD3_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name PFD_480_SET - 480MHz Clock (PLL3) Phase Fractional Divider Control Register */
/*! @{ */

#define CCM_ANALOG_PFD_480_SET_PFD0_FRAC_MASK    (0x3FU)
#define CCM_ANALOG_PFD_480_SET_PFD0_FRAC_SHIFT   (0U)
#define CCM_ANALOG_PFD_480_SET_PFD0_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD0_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD0_FRAC_MASK)

#define CCM_ANALOG_PFD_480_SET_PFD0_STABLE_MASK  (0x40U)
#define CCM_ANALOG_PFD_480_SET_PFD0_STABLE_SHIFT (6U)
#define CCM_ANALOG_PFD_480_SET_PFD0_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD0_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD0_STABLE_MASK)

#define CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE_MASK (0x80U)
#define CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE_SHIFT (7U)
#define CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_SET_PFD1_FRAC_MASK    (0x3F00U)
#define CCM_ANALOG_PFD_480_SET_PFD1_FRAC_SHIFT   (8U)
#define CCM_ANALOG_PFD_480_SET_PFD1_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD1_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD1_FRAC_MASK)

#define CCM_ANALOG_PFD_480_SET_PFD1_STABLE_MASK  (0x4000U)
#define CCM_ANALOG_PFD_480_SET_PFD1_STABLE_SHIFT (14U)
#define CCM_ANALOG_PFD_480_SET_PFD1_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD1_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD1_STABLE_MASK)

#define CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE_MASK (0x8000U)
#define CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE_SHIFT (15U)
#define CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_SET_PFD2_FRAC_MASK    (0x3F0000U)
#define CCM_ANALOG_PFD_480_SET_PFD2_FRAC_SHIFT   (16U)
#define CCM_ANALOG_PFD_480_SET_PFD2_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD2_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD2_FRAC_MASK)

#define CCM_ANALOG_PFD_480_SET_PFD2_STABLE_MASK  (0x400000U)
#define CCM_ANALOG_PFD_480_SET_PFD2_STABLE_SHIFT (22U)
#define CCM_ANALOG_PFD_480_SET_PFD2_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD2_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD2_STABLE_MASK)

#define CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE_MASK (0x800000U)
#define CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE_SHIFT (23U)
#define CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_SET_PFD3_FRAC_MASK    (0x3F000000U)
#define CCM_ANALOG_PFD_480_SET_PFD3_FRAC_SHIFT   (24U)
#define CCM_ANALOG_PFD_480_SET_PFD3_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD3_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD3_FRAC_MASK)

#define CCM_ANALOG_PFD_480_SET_PFD3_STABLE_MASK  (0x40000000U)
#define CCM_ANALOG_PFD_480_SET_PFD3_STABLE_SHIFT (30U)
#define CCM_ANALOG_PFD_480_SET_PFD3_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD3_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD3_STABLE_MASK)

#define CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE_MASK (0x80000000U)
#define CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE_SHIFT (31U)
#define CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name PFD_480_CLR - 480MHz Clock (PLL3) Phase Fractional Divider Control Register */
/*! @{ */

#define CCM_ANALOG_PFD_480_CLR_PFD0_FRAC_MASK    (0x3FU)
#define CCM_ANALOG_PFD_480_CLR_PFD0_FRAC_SHIFT   (0U)
#define CCM_ANALOG_PFD_480_CLR_PFD0_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD0_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD0_FRAC_MASK)

#define CCM_ANALOG_PFD_480_CLR_PFD0_STABLE_MASK  (0x40U)
#define CCM_ANALOG_PFD_480_CLR_PFD0_STABLE_SHIFT (6U)
#define CCM_ANALOG_PFD_480_CLR_PFD0_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD0_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD0_STABLE_MASK)

#define CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE_MASK (0x80U)
#define CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE_SHIFT (7U)
#define CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_CLR_PFD1_FRAC_MASK    (0x3F00U)
#define CCM_ANALOG_PFD_480_CLR_PFD1_FRAC_SHIFT   (8U)
#define CCM_ANALOG_PFD_480_CLR_PFD1_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD1_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD1_FRAC_MASK)

#define CCM_ANALOG_PFD_480_CLR_PFD1_STABLE_MASK  (0x4000U)
#define CCM_ANALOG_PFD_480_CLR_PFD1_STABLE_SHIFT (14U)
#define CCM_ANALOG_PFD_480_CLR_PFD1_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD1_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD1_STABLE_MASK)

#define CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE_MASK (0x8000U)
#define CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE_SHIFT (15U)
#define CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_CLR_PFD2_FRAC_MASK    (0x3F0000U)
#define CCM_ANALOG_PFD_480_CLR_PFD2_FRAC_SHIFT   (16U)
#define CCM_ANALOG_PFD_480_CLR_PFD2_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD2_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD2_FRAC_MASK)

#define CCM_ANALOG_PFD_480_CLR_PFD2_STABLE_MASK  (0x400000U)
#define CCM_ANALOG_PFD_480_CLR_PFD2_STABLE_SHIFT (22U)
#define CCM_ANALOG_PFD_480_CLR_PFD2_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD2_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD2_STABLE_MASK)

#define CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE_MASK (0x800000U)
#define CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE_SHIFT (23U)
#define CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_CLR_PFD3_FRAC_MASK    (0x3F000000U)
#define CCM_ANALOG_PFD_480_CLR_PFD3_FRAC_SHIFT   (24U)
#define CCM_ANALOG_PFD_480_CLR_PFD3_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD3_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD3_FRAC_MASK)

#define CCM_ANALOG_PFD_480_CLR_PFD3_STABLE_MASK  (0x40000000U)
#define CCM_ANALOG_PFD_480_CLR_PFD3_STABLE_SHIFT (30U)
#define CCM_ANALOG_PFD_480_CLR_PFD3_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD3_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD3_STABLE_MASK)

#define CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE_MASK (0x80000000U)
#define CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE_SHIFT (31U)
#define CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name PFD_480_TOG - 480MHz Clock (PLL3) Phase Fractional Divider Control Register */
/*! @{ */

#define CCM_ANALOG_PFD_480_TOG_PFD0_FRAC_MASK    (0x3FU)
#define CCM_ANALOG_PFD_480_TOG_PFD0_FRAC_SHIFT   (0U)
#define CCM_ANALOG_PFD_480_TOG_PFD0_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD0_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD0_FRAC_MASK)

#define CCM_ANALOG_PFD_480_TOG_PFD0_STABLE_MASK  (0x40U)
#define CCM_ANALOG_PFD_480_TOG_PFD0_STABLE_SHIFT (6U)
#define CCM_ANALOG_PFD_480_TOG_PFD0_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD0_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD0_STABLE_MASK)

#define CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE_MASK (0x80U)
#define CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE_SHIFT (7U)
#define CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_TOG_PFD1_FRAC_MASK    (0x3F00U)
#define CCM_ANALOG_PFD_480_TOG_PFD1_FRAC_SHIFT   (8U)
#define CCM_ANALOG_PFD_480_TOG_PFD1_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD1_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD1_FRAC_MASK)

#define CCM_ANALOG_PFD_480_TOG_PFD1_STABLE_MASK  (0x4000U)
#define CCM_ANALOG_PFD_480_TOG_PFD1_STABLE_SHIFT (14U)
#define CCM_ANALOG_PFD_480_TOG_PFD1_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD1_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD1_STABLE_MASK)

#define CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE_MASK (0x8000U)
#define CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE_SHIFT (15U)
#define CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_TOG_PFD2_FRAC_MASK    (0x3F0000U)
#define CCM_ANALOG_PFD_480_TOG_PFD2_FRAC_SHIFT   (16U)
#define CCM_ANALOG_PFD_480_TOG_PFD2_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD2_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD2_FRAC_MASK)

#define CCM_ANALOG_PFD_480_TOG_PFD2_STABLE_MASK  (0x400000U)
#define CCM_ANALOG_PFD_480_TOG_PFD2_STABLE_SHIFT (22U)
#define CCM_ANALOG_PFD_480_TOG_PFD2_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD2_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD2_STABLE_MASK)

#define CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE_MASK (0x800000U)
#define CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE_SHIFT (23U)
#define CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE_MASK)

#define CCM_ANALOG_PFD_480_TOG_PFD3_FRAC_MASK    (0x3F000000U)
#define CCM_ANALOG_PFD_480_TOG_PFD3_FRAC_SHIFT   (24U)
#define CCM_ANALOG_PFD_480_TOG_PFD3_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD3_FRAC_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD3_FRAC_MASK)

#define CCM_ANALOG_PFD_480_TOG_PFD3_STABLE_MASK  (0x40000000U)
#define CCM_ANALOG_PFD_480_TOG_PFD3_STABLE_SHIFT (30U)
#define CCM_ANALOG_PFD_480_TOG_PFD3_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD3_STABLE_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD3_STABLE_MASK)

#define CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE_MASK (0x80000000U)
#define CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE_SHIFT (31U)
#define CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name PFD_528 - 528MHz Clock (PLL2) Phase Fractional Divider Control Register */
/*! @{ */

#define CCM_ANALOG_PFD_528_PFD0_FRAC_MASK        (0x3FU)
#define CCM_ANALOG_PFD_528_PFD0_FRAC_SHIFT       (0U)
#define CCM_ANALOG_PFD_528_PFD0_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD0_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_PFD0_FRAC_MASK)

#define CCM_ANALOG_PFD_528_PFD0_STABLE_MASK      (0x40U)
#define CCM_ANALOG_PFD_528_PFD0_STABLE_SHIFT     (6U)
#define CCM_ANALOG_PFD_528_PFD0_STABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD0_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_PFD0_STABLE_MASK)

#define CCM_ANALOG_PFD_528_PFD0_CLKGATE_MASK     (0x80U)
#define CCM_ANALOG_PFD_528_PFD0_CLKGATE_SHIFT    (7U)
#define CCM_ANALOG_PFD_528_PFD0_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD0_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_PFD0_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_PFD1_FRAC_MASK        (0x3F00U)
#define CCM_ANALOG_PFD_528_PFD1_FRAC_SHIFT       (8U)
#define CCM_ANALOG_PFD_528_PFD1_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD1_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_PFD1_FRAC_MASK)

#define CCM_ANALOG_PFD_528_PFD1_STABLE_MASK      (0x4000U)
#define CCM_ANALOG_PFD_528_PFD1_STABLE_SHIFT     (14U)
#define CCM_ANALOG_PFD_528_PFD1_STABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD1_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_PFD1_STABLE_MASK)

#define CCM_ANALOG_PFD_528_PFD1_CLKGATE_MASK     (0x8000U)
#define CCM_ANALOG_PFD_528_PFD1_CLKGATE_SHIFT    (15U)
#define CCM_ANALOG_PFD_528_PFD1_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD1_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_PFD1_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_PFD2_FRAC_MASK        (0x3F0000U)
#define CCM_ANALOG_PFD_528_PFD2_FRAC_SHIFT       (16U)
#define CCM_ANALOG_PFD_528_PFD2_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD2_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_PFD2_FRAC_MASK)

#define CCM_ANALOG_PFD_528_PFD2_STABLE_MASK      (0x400000U)
#define CCM_ANALOG_PFD_528_PFD2_STABLE_SHIFT     (22U)
#define CCM_ANALOG_PFD_528_PFD2_STABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD2_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_PFD2_STABLE_MASK)

#define CCM_ANALOG_PFD_528_PFD2_CLKGATE_MASK     (0x800000U)
#define CCM_ANALOG_PFD_528_PFD2_CLKGATE_SHIFT    (23U)
#define CCM_ANALOG_PFD_528_PFD2_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD2_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_PFD2_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_PFD3_FRAC_MASK        (0x3F000000U)
#define CCM_ANALOG_PFD_528_PFD3_FRAC_SHIFT       (24U)
#define CCM_ANALOG_PFD_528_PFD3_FRAC(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD3_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_PFD3_FRAC_MASK)

#define CCM_ANALOG_PFD_528_PFD3_STABLE_MASK      (0x40000000U)
#define CCM_ANALOG_PFD_528_PFD3_STABLE_SHIFT     (30U)
#define CCM_ANALOG_PFD_528_PFD3_STABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD3_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_PFD3_STABLE_MASK)

#define CCM_ANALOG_PFD_528_PFD3_CLKGATE_MASK     (0x80000000U)
#define CCM_ANALOG_PFD_528_PFD3_CLKGATE_SHIFT    (31U)
#define CCM_ANALOG_PFD_528_PFD3_CLKGATE(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_PFD3_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name PFD_528_SET - 528MHz Clock (PLL2) Phase Fractional Divider Control Register */
/*! @{ */

#define CCM_ANALOG_PFD_528_SET_PFD0_FRAC_MASK    (0x3FU)
#define CCM_ANALOG_PFD_528_SET_PFD0_FRAC_SHIFT   (0U)
#define CCM_ANALOG_PFD_528_SET_PFD0_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD0_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD0_FRAC_MASK)

#define CCM_ANALOG_PFD_528_SET_PFD0_STABLE_MASK  (0x40U)
#define CCM_ANALOG_PFD_528_SET_PFD0_STABLE_SHIFT (6U)
#define CCM_ANALOG_PFD_528_SET_PFD0_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD0_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD0_STABLE_MASK)

#define CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE_MASK (0x80U)
#define CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE_SHIFT (7U)
#define CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_SET_PFD1_FRAC_MASK    (0x3F00U)
#define CCM_ANALOG_PFD_528_SET_PFD1_FRAC_SHIFT   (8U)
#define CCM_ANALOG_PFD_528_SET_PFD1_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD1_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD1_FRAC_MASK)

#define CCM_ANALOG_PFD_528_SET_PFD1_STABLE_MASK  (0x4000U)
#define CCM_ANALOG_PFD_528_SET_PFD1_STABLE_SHIFT (14U)
#define CCM_ANALOG_PFD_528_SET_PFD1_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD1_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD1_STABLE_MASK)

#define CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE_MASK (0x8000U)
#define CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE_SHIFT (15U)
#define CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_SET_PFD2_FRAC_MASK    (0x3F0000U)
#define CCM_ANALOG_PFD_528_SET_PFD2_FRAC_SHIFT   (16U)
#define CCM_ANALOG_PFD_528_SET_PFD2_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD2_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD2_FRAC_MASK)

#define CCM_ANALOG_PFD_528_SET_PFD2_STABLE_MASK  (0x400000U)
#define CCM_ANALOG_PFD_528_SET_PFD2_STABLE_SHIFT (22U)
#define CCM_ANALOG_PFD_528_SET_PFD2_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD2_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD2_STABLE_MASK)

#define CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE_MASK (0x800000U)
#define CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE_SHIFT (23U)
#define CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_SET_PFD3_FRAC_MASK    (0x3F000000U)
#define CCM_ANALOG_PFD_528_SET_PFD3_FRAC_SHIFT   (24U)
#define CCM_ANALOG_PFD_528_SET_PFD3_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD3_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD3_FRAC_MASK)

#define CCM_ANALOG_PFD_528_SET_PFD3_STABLE_MASK  (0x40000000U)
#define CCM_ANALOG_PFD_528_SET_PFD3_STABLE_SHIFT (30U)
#define CCM_ANALOG_PFD_528_SET_PFD3_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD3_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD3_STABLE_MASK)

#define CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE_MASK (0x80000000U)
#define CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE_SHIFT (31U)
#define CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name PFD_528_CLR - 528MHz Clock (PLL2) Phase Fractional Divider Control Register */
/*! @{ */

#define CCM_ANALOG_PFD_528_CLR_PFD0_FRAC_MASK    (0x3FU)
#define CCM_ANALOG_PFD_528_CLR_PFD0_FRAC_SHIFT   (0U)
#define CCM_ANALOG_PFD_528_CLR_PFD0_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD0_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD0_FRAC_MASK)

#define CCM_ANALOG_PFD_528_CLR_PFD0_STABLE_MASK  (0x40U)
#define CCM_ANALOG_PFD_528_CLR_PFD0_STABLE_SHIFT (6U)
#define CCM_ANALOG_PFD_528_CLR_PFD0_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD0_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD0_STABLE_MASK)

#define CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE_MASK (0x80U)
#define CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE_SHIFT (7U)
#define CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_CLR_PFD1_FRAC_MASK    (0x3F00U)
#define CCM_ANALOG_PFD_528_CLR_PFD1_FRAC_SHIFT   (8U)
#define CCM_ANALOG_PFD_528_CLR_PFD1_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD1_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD1_FRAC_MASK)

#define CCM_ANALOG_PFD_528_CLR_PFD1_STABLE_MASK  (0x4000U)
#define CCM_ANALOG_PFD_528_CLR_PFD1_STABLE_SHIFT (14U)
#define CCM_ANALOG_PFD_528_CLR_PFD1_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD1_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD1_STABLE_MASK)

#define CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE_MASK (0x8000U)
#define CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE_SHIFT (15U)
#define CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_CLR_PFD2_FRAC_MASK    (0x3F0000U)
#define CCM_ANALOG_PFD_528_CLR_PFD2_FRAC_SHIFT   (16U)
#define CCM_ANALOG_PFD_528_CLR_PFD2_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD2_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD2_FRAC_MASK)

#define CCM_ANALOG_PFD_528_CLR_PFD2_STABLE_MASK  (0x400000U)
#define CCM_ANALOG_PFD_528_CLR_PFD2_STABLE_SHIFT (22U)
#define CCM_ANALOG_PFD_528_CLR_PFD2_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD2_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD2_STABLE_MASK)

#define CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE_MASK (0x800000U)
#define CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE_SHIFT (23U)
#define CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_CLR_PFD3_FRAC_MASK    (0x3F000000U)
#define CCM_ANALOG_PFD_528_CLR_PFD3_FRAC_SHIFT   (24U)
#define CCM_ANALOG_PFD_528_CLR_PFD3_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD3_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD3_FRAC_MASK)

#define CCM_ANALOG_PFD_528_CLR_PFD3_STABLE_MASK  (0x40000000U)
#define CCM_ANALOG_PFD_528_CLR_PFD3_STABLE_SHIFT (30U)
#define CCM_ANALOG_PFD_528_CLR_PFD3_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD3_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD3_STABLE_MASK)

#define CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE_MASK (0x80000000U)
#define CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE_SHIFT (31U)
#define CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name PFD_528_TOG - 528MHz Clock (PLL2) Phase Fractional Divider Control Register */
/*! @{ */

#define CCM_ANALOG_PFD_528_TOG_PFD0_FRAC_MASK    (0x3FU)
#define CCM_ANALOG_PFD_528_TOG_PFD0_FRAC_SHIFT   (0U)
#define CCM_ANALOG_PFD_528_TOG_PFD0_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD0_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD0_FRAC_MASK)

#define CCM_ANALOG_PFD_528_TOG_PFD0_STABLE_MASK  (0x40U)
#define CCM_ANALOG_PFD_528_TOG_PFD0_STABLE_SHIFT (6U)
#define CCM_ANALOG_PFD_528_TOG_PFD0_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD0_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD0_STABLE_MASK)

#define CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE_MASK (0x80U)
#define CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE_SHIFT (7U)
#define CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_TOG_PFD1_FRAC_MASK    (0x3F00U)
#define CCM_ANALOG_PFD_528_TOG_PFD1_FRAC_SHIFT   (8U)
#define CCM_ANALOG_PFD_528_TOG_PFD1_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD1_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD1_FRAC_MASK)

#define CCM_ANALOG_PFD_528_TOG_PFD1_STABLE_MASK  (0x4000U)
#define CCM_ANALOG_PFD_528_TOG_PFD1_STABLE_SHIFT (14U)
#define CCM_ANALOG_PFD_528_TOG_PFD1_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD1_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD1_STABLE_MASK)

#define CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE_MASK (0x8000U)
#define CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE_SHIFT (15U)
#define CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_TOG_PFD2_FRAC_MASK    (0x3F0000U)
#define CCM_ANALOG_PFD_528_TOG_PFD2_FRAC_SHIFT   (16U)
#define CCM_ANALOG_PFD_528_TOG_PFD2_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD2_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD2_FRAC_MASK)

#define CCM_ANALOG_PFD_528_TOG_PFD2_STABLE_MASK  (0x400000U)
#define CCM_ANALOG_PFD_528_TOG_PFD2_STABLE_SHIFT (22U)
#define CCM_ANALOG_PFD_528_TOG_PFD2_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD2_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD2_STABLE_MASK)

#define CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE_MASK (0x800000U)
#define CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE_SHIFT (23U)
#define CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE_MASK)

#define CCM_ANALOG_PFD_528_TOG_PFD3_FRAC_MASK    (0x3F000000U)
#define CCM_ANALOG_PFD_528_TOG_PFD3_FRAC_SHIFT   (24U)
#define CCM_ANALOG_PFD_528_TOG_PFD3_FRAC(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD3_FRAC_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD3_FRAC_MASK)

#define CCM_ANALOG_PFD_528_TOG_PFD3_STABLE_MASK  (0x40000000U)
#define CCM_ANALOG_PFD_528_TOG_PFD3_STABLE_SHIFT (30U)
#define CCM_ANALOG_PFD_528_TOG_PFD3_STABLE(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD3_STABLE_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD3_STABLE_MASK)

#define CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE_MASK (0x80000000U)
#define CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE_SHIFT (31U)
#define CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE_SHIFT)) & CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name MISC0 - Miscellaneous Register 0 */
/*! @{ */

#define CCM_ANALOG_MISC0_REFTOP_PWD_MASK         (0x1U)
#define CCM_ANALOG_MISC0_REFTOP_PWD_SHIFT        (0U)
#define CCM_ANALOG_MISC0_REFTOP_PWD(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_REFTOP_PWD_SHIFT)) & CCM_ANALOG_MISC0_REFTOP_PWD_MASK)

#define CCM_ANALOG_MISC0_REFTOP_SELFBIASOFF_MASK (0x8U)
#define CCM_ANALOG_MISC0_REFTOP_SELFBIASOFF_SHIFT (3U)
/*! REFTOP_SELFBIASOFF
 *  0b0..Uses coarse bias currents for startup
 *  0b1..Uses bandgap-based bias currents for best performance.
 */
#define CCM_ANALOG_MISC0_REFTOP_SELFBIASOFF(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_REFTOP_SELFBIASOFF_SHIFT)) & CCM_ANALOG_MISC0_REFTOP_SELFBIASOFF_MASK)

#define CCM_ANALOG_MISC0_REFTOP_VBGADJ_MASK      (0x70U)
#define CCM_ANALOG_MISC0_REFTOP_VBGADJ_SHIFT     (4U)
/*! REFTOP_VBGADJ
 *  0b000..Nominal VBG
 *  0b001..VBG+0.78%
 *  0b010..VBG+1.56%
 *  0b011..VBG+2.34%
 *  0b100..VBG-0.78%
 *  0b101..VBG-1.56%
 *  0b110..VBG-2.34%
 *  0b111..VBG-3.12%
 */
#define CCM_ANALOG_MISC0_REFTOP_VBGADJ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_REFTOP_VBGADJ_SHIFT)) & CCM_ANALOG_MISC0_REFTOP_VBGADJ_MASK)

#define CCM_ANALOG_MISC0_REFTOP_VBGUP_MASK       (0x80U)
#define CCM_ANALOG_MISC0_REFTOP_VBGUP_SHIFT      (7U)
#define CCM_ANALOG_MISC0_REFTOP_VBGUP(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_REFTOP_VBGUP_SHIFT)) & CCM_ANALOG_MISC0_REFTOP_VBGUP_MASK)

#define CCM_ANALOG_MISC0_STOP_MODE_CONFIG_MASK   (0xC00U)
#define CCM_ANALOG_MISC0_STOP_MODE_CONFIG_SHIFT  (10U)
/*! STOP_MODE_CONFIG
 *  0b00..All analog except RTC powered down on stop mode assertion.
 *  0b01..Beside RTC, analog bandgap, 1p1 and 2p5 regulators are also on.
 *  0b10..Beside RTC, 1p1 and 2p5 regulators are also on, low-power bandgap is selected so that the normal analog
 *        bandgap together with the rest analog is powered down.
 *  0b11..Beside RTC, low-power bandgap is selected and the rest analog is powered down.
 */
#define CCM_ANALOG_MISC0_STOP_MODE_CONFIG(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_STOP_MODE_CONFIG_SHIFT)) & CCM_ANALOG_MISC0_STOP_MODE_CONFIG_MASK)

#define CCM_ANALOG_MISC0_DISCON_HIGH_SNVS_MASK   (0x1000U)
#define CCM_ANALOG_MISC0_DISCON_HIGH_SNVS_SHIFT  (12U)
/*! DISCON_HIGH_SNVS
 *  0b0..Turn on the switch
 *  0b1..Turn off the switch
 */
#define CCM_ANALOG_MISC0_DISCON_HIGH_SNVS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_DISCON_HIGH_SNVS_SHIFT)) & CCM_ANALOG_MISC0_DISCON_HIGH_SNVS_MASK)

#define CCM_ANALOG_MISC0_OSC_I_MASK              (0x6000U)
#define CCM_ANALOG_MISC0_OSC_I_SHIFT             (13U)
/*! OSC_I
 *  0b00..Nominal
 *  0b01..Decrease current by 12.5%
 *  0b10..Decrease current by 25.0%
 *  0b11..Decrease current by 37.5%
 */
#define CCM_ANALOG_MISC0_OSC_I(x)                (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_OSC_I_SHIFT)) & CCM_ANALOG_MISC0_OSC_I_MASK)

#define CCM_ANALOG_MISC0_OSC_XTALOK_MASK         (0x8000U)
#define CCM_ANALOG_MISC0_OSC_XTALOK_SHIFT        (15U)
#define CCM_ANALOG_MISC0_OSC_XTALOK(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_OSC_XTALOK_SHIFT)) & CCM_ANALOG_MISC0_OSC_XTALOK_MASK)

#define CCM_ANALOG_MISC0_OSC_XTALOK_EN_MASK      (0x10000U)
#define CCM_ANALOG_MISC0_OSC_XTALOK_EN_SHIFT     (16U)
#define CCM_ANALOG_MISC0_OSC_XTALOK_EN(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_OSC_XTALOK_EN_SHIFT)) & CCM_ANALOG_MISC0_OSC_XTALOK_EN_MASK)

#define CCM_ANALOG_MISC0_CLKGATE_CTRL_MASK       (0x2000000U)
#define CCM_ANALOG_MISC0_CLKGATE_CTRL_SHIFT      (25U)
/*! CLKGATE_CTRL
 *  0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
 *  0b1..Prevent the logic from ever gating off the clock.
 */
#define CCM_ANALOG_MISC0_CLKGATE_CTRL(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLKGATE_CTRL_SHIFT)) & CCM_ANALOG_MISC0_CLKGATE_CTRL_MASK)

#define CCM_ANALOG_MISC0_CLKGATE_DELAY_MASK      (0x1C000000U)
#define CCM_ANALOG_MISC0_CLKGATE_DELAY_SHIFT     (26U)
/*! CLKGATE_DELAY
 *  0b000..0.5ms
 *  0b001..1.0ms
 *  0b010..2.0ms
 *  0b011..3.0ms
 *  0b100..4.0ms
 *  0b101..5.0ms
 *  0b110..6.0ms
 *  0b111..7.0ms
 */
#define CCM_ANALOG_MISC0_CLKGATE_DELAY(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLKGATE_DELAY_SHIFT)) & CCM_ANALOG_MISC0_CLKGATE_DELAY_MASK)

#define CCM_ANALOG_MISC0_RTC_XTAL_SOURCE_MASK    (0x20000000U)
#define CCM_ANALOG_MISC0_RTC_XTAL_SOURCE_SHIFT   (29U)
/*! RTC_XTAL_SOURCE
 *  0b0..Internal ring oscillator
 *  0b1..RTC_XTAL
 */
#define CCM_ANALOG_MISC0_RTC_XTAL_SOURCE(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_RTC_XTAL_SOURCE_SHIFT)) & CCM_ANALOG_MISC0_RTC_XTAL_SOURCE_MASK)

#define CCM_ANALOG_MISC0_XTAL_24M_PWD_MASK       (0x40000000U)
#define CCM_ANALOG_MISC0_XTAL_24M_PWD_SHIFT      (30U)
#define CCM_ANALOG_MISC0_XTAL_24M_PWD(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_XTAL_24M_PWD_SHIFT)) & CCM_ANALOG_MISC0_XTAL_24M_PWD_MASK)
/*! @} */

/*! @name MISC0_SET - Miscellaneous Register 0 */
/*! @{ */

#define CCM_ANALOG_MISC0_SET_REFTOP_PWD_MASK     (0x1U)
#define CCM_ANALOG_MISC0_SET_REFTOP_PWD_SHIFT    (0U)
#define CCM_ANALOG_MISC0_SET_REFTOP_PWD(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_REFTOP_PWD_SHIFT)) & CCM_ANALOG_MISC0_SET_REFTOP_PWD_MASK)

#define CCM_ANALOG_MISC0_SET_REFTOP_SELFBIASOFF_MASK (0x8U)
#define CCM_ANALOG_MISC0_SET_REFTOP_SELFBIASOFF_SHIFT (3U)
/*! REFTOP_SELFBIASOFF
 *  0b0..Uses coarse bias currents for startup
 *  0b1..Uses bandgap-based bias currents for best performance.
 */
#define CCM_ANALOG_MISC0_SET_REFTOP_SELFBIASOFF(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_REFTOP_SELFBIASOFF_SHIFT)) & CCM_ANALOG_MISC0_SET_REFTOP_SELFBIASOFF_MASK)

#define CCM_ANALOG_MISC0_SET_REFTOP_VBGADJ_MASK  (0x70U)
#define CCM_ANALOG_MISC0_SET_REFTOP_VBGADJ_SHIFT (4U)
/*! REFTOP_VBGADJ
 *  0b000..Nominal VBG
 *  0b001..VBG+0.78%
 *  0b010..VBG+1.56%
 *  0b011..VBG+2.34%
 *  0b100..VBG-0.78%
 *  0b101..VBG-1.56%
 *  0b110..VBG-2.34%
 *  0b111..VBG-3.12%
 */
#define CCM_ANALOG_MISC0_SET_REFTOP_VBGADJ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_REFTOP_VBGADJ_SHIFT)) & CCM_ANALOG_MISC0_SET_REFTOP_VBGADJ_MASK)

#define CCM_ANALOG_MISC0_SET_REFTOP_VBGUP_MASK   (0x80U)
#define CCM_ANALOG_MISC0_SET_REFTOP_VBGUP_SHIFT  (7U)
#define CCM_ANALOG_MISC0_SET_REFTOP_VBGUP(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_REFTOP_VBGUP_SHIFT)) & CCM_ANALOG_MISC0_SET_REFTOP_VBGUP_MASK)

#define CCM_ANALOG_MISC0_SET_STOP_MODE_CONFIG_MASK (0xC00U)
#define CCM_ANALOG_MISC0_SET_STOP_MODE_CONFIG_SHIFT (10U)
/*! STOP_MODE_CONFIG
 *  0b00..All analog except RTC powered down on stop mode assertion.
 *  0b01..Beside RTC, analog bandgap, 1p1 and 2p5 regulators are also on.
 *  0b10..Beside RTC, 1p1 and 2p5 regulators are also on, low-power bandgap is selected so that the normal analog
 *        bandgap together with the rest analog is powered down.
 *  0b11..Beside RTC, low-power bandgap is selected and the rest analog is powered down.
 */
#define CCM_ANALOG_MISC0_SET_STOP_MODE_CONFIG(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_STOP_MODE_CONFIG_SHIFT)) & CCM_ANALOG_MISC0_SET_STOP_MODE_CONFIG_MASK)

#define CCM_ANALOG_MISC0_SET_DISCON_HIGH_SNVS_MASK (0x1000U)
#define CCM_ANALOG_MISC0_SET_DISCON_HIGH_SNVS_SHIFT (12U)
/*! DISCON_HIGH_SNVS
 *  0b0..Turn on the switch
 *  0b1..Turn off the switch
 */
#define CCM_ANALOG_MISC0_SET_DISCON_HIGH_SNVS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_DISCON_HIGH_SNVS_SHIFT)) & CCM_ANALOG_MISC0_SET_DISCON_HIGH_SNVS_MASK)

#define CCM_ANALOG_MISC0_SET_OSC_I_MASK          (0x6000U)
#define CCM_ANALOG_MISC0_SET_OSC_I_SHIFT         (13U)
/*! OSC_I
 *  0b00..Nominal
 *  0b01..Decrease current by 12.5%
 *  0b10..Decrease current by 25.0%
 *  0b11..Decrease current by 37.5%
 */
#define CCM_ANALOG_MISC0_SET_OSC_I(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_OSC_I_SHIFT)) & CCM_ANALOG_MISC0_SET_OSC_I_MASK)

#define CCM_ANALOG_MISC0_SET_OSC_XTALOK_MASK     (0x8000U)
#define CCM_ANALOG_MISC0_SET_OSC_XTALOK_SHIFT    (15U)
#define CCM_ANALOG_MISC0_SET_OSC_XTALOK(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_OSC_XTALOK_SHIFT)) & CCM_ANALOG_MISC0_SET_OSC_XTALOK_MASK)

#define CCM_ANALOG_MISC0_SET_OSC_XTALOK_EN_MASK  (0x10000U)
#define CCM_ANALOG_MISC0_SET_OSC_XTALOK_EN_SHIFT (16U)
#define CCM_ANALOG_MISC0_SET_OSC_XTALOK_EN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_OSC_XTALOK_EN_SHIFT)) & CCM_ANALOG_MISC0_SET_OSC_XTALOK_EN_MASK)

#define CCM_ANALOG_MISC0_SET_CLKGATE_CTRL_MASK   (0x2000000U)
#define CCM_ANALOG_MISC0_SET_CLKGATE_CTRL_SHIFT  (25U)
/*! CLKGATE_CTRL
 *  0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
 *  0b1..Prevent the logic from ever gating off the clock.
 */
#define CCM_ANALOG_MISC0_SET_CLKGATE_CTRL(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_CLKGATE_CTRL_SHIFT)) & CCM_ANALOG_MISC0_SET_CLKGATE_CTRL_MASK)

#define CCM_ANALOG_MISC0_SET_CLKGATE_DELAY_MASK  (0x1C000000U)
#define CCM_ANALOG_MISC0_SET_CLKGATE_DELAY_SHIFT (26U)
/*! CLKGATE_DELAY
 *  0b000..0.5ms
 *  0b001..1.0ms
 *  0b010..2.0ms
 *  0b011..3.0ms
 *  0b100..4.0ms
 *  0b101..5.0ms
 *  0b110..6.0ms
 *  0b111..7.0ms
 */
#define CCM_ANALOG_MISC0_SET_CLKGATE_DELAY(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_CLKGATE_DELAY_SHIFT)) & CCM_ANALOG_MISC0_SET_CLKGATE_DELAY_MASK)

#define CCM_ANALOG_MISC0_SET_RTC_XTAL_SOURCE_MASK (0x20000000U)
#define CCM_ANALOG_MISC0_SET_RTC_XTAL_SOURCE_SHIFT (29U)
/*! RTC_XTAL_SOURCE
 *  0b0..Internal ring oscillator
 *  0b1..RTC_XTAL
 */
#define CCM_ANALOG_MISC0_SET_RTC_XTAL_SOURCE(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_RTC_XTAL_SOURCE_SHIFT)) & CCM_ANALOG_MISC0_SET_RTC_XTAL_SOURCE_MASK)

#define CCM_ANALOG_MISC0_SET_XTAL_24M_PWD_MASK   (0x40000000U)
#define CCM_ANALOG_MISC0_SET_XTAL_24M_PWD_SHIFT  (30U)
#define CCM_ANALOG_MISC0_SET_XTAL_24M_PWD(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_SET_XTAL_24M_PWD_SHIFT)) & CCM_ANALOG_MISC0_SET_XTAL_24M_PWD_MASK)
/*! @} */

/*! @name MISC0_CLR - Miscellaneous Register 0 */
/*! @{ */

#define CCM_ANALOG_MISC0_CLR_REFTOP_PWD_MASK     (0x1U)
#define CCM_ANALOG_MISC0_CLR_REFTOP_PWD_SHIFT    (0U)
#define CCM_ANALOG_MISC0_CLR_REFTOP_PWD(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_REFTOP_PWD_SHIFT)) & CCM_ANALOG_MISC0_CLR_REFTOP_PWD_MASK)

#define CCM_ANALOG_MISC0_CLR_REFTOP_SELFBIASOFF_MASK (0x8U)
#define CCM_ANALOG_MISC0_CLR_REFTOP_SELFBIASOFF_SHIFT (3U)
/*! REFTOP_SELFBIASOFF
 *  0b0..Uses coarse bias currents for startup
 *  0b1..Uses bandgap-based bias currents for best performance.
 */
#define CCM_ANALOG_MISC0_CLR_REFTOP_SELFBIASOFF(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_REFTOP_SELFBIASOFF_SHIFT)) & CCM_ANALOG_MISC0_CLR_REFTOP_SELFBIASOFF_MASK)

#define CCM_ANALOG_MISC0_CLR_REFTOP_VBGADJ_MASK  (0x70U)
#define CCM_ANALOG_MISC0_CLR_REFTOP_VBGADJ_SHIFT (4U)
/*! REFTOP_VBGADJ
 *  0b000..Nominal VBG
 *  0b001..VBG+0.78%
 *  0b010..VBG+1.56%
 *  0b011..VBG+2.34%
 *  0b100..VBG-0.78%
 *  0b101..VBG-1.56%
 *  0b110..VBG-2.34%
 *  0b111..VBG-3.12%
 */
#define CCM_ANALOG_MISC0_CLR_REFTOP_VBGADJ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_REFTOP_VBGADJ_SHIFT)) & CCM_ANALOG_MISC0_CLR_REFTOP_VBGADJ_MASK)

#define CCM_ANALOG_MISC0_CLR_REFTOP_VBGUP_MASK   (0x80U)
#define CCM_ANALOG_MISC0_CLR_REFTOP_VBGUP_SHIFT  (7U)
#define CCM_ANALOG_MISC0_CLR_REFTOP_VBGUP(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_REFTOP_VBGUP_SHIFT)) & CCM_ANALOG_MISC0_CLR_REFTOP_VBGUP_MASK)

#define CCM_ANALOG_MISC0_CLR_STOP_MODE_CONFIG_MASK (0xC00U)
#define CCM_ANALOG_MISC0_CLR_STOP_MODE_CONFIG_SHIFT (10U)
/*! STOP_MODE_CONFIG
 *  0b00..All analog except RTC powered down on stop mode assertion.
 *  0b01..Beside RTC, analog bandgap, 1p1 and 2p5 regulators are also on.
 *  0b10..Beside RTC, 1p1 and 2p5 regulators are also on, low-power bandgap is selected so that the normal analog
 *        bandgap together with the rest analog is powered down.
 *  0b11..Beside RTC, low-power bandgap is selected and the rest analog is powered down.
 */
#define CCM_ANALOG_MISC0_CLR_STOP_MODE_CONFIG(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_STOP_MODE_CONFIG_SHIFT)) & CCM_ANALOG_MISC0_CLR_STOP_MODE_CONFIG_MASK)

#define CCM_ANALOG_MISC0_CLR_DISCON_HIGH_SNVS_MASK (0x1000U)
#define CCM_ANALOG_MISC0_CLR_DISCON_HIGH_SNVS_SHIFT (12U)
/*! DISCON_HIGH_SNVS
 *  0b0..Turn on the switch
 *  0b1..Turn off the switch
 */
#define CCM_ANALOG_MISC0_CLR_DISCON_HIGH_SNVS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_DISCON_HIGH_SNVS_SHIFT)) & CCM_ANALOG_MISC0_CLR_DISCON_HIGH_SNVS_MASK)

#define CCM_ANALOG_MISC0_CLR_OSC_I_MASK          (0x6000U)
#define CCM_ANALOG_MISC0_CLR_OSC_I_SHIFT         (13U)
/*! OSC_I
 *  0b00..Nominal
 *  0b01..Decrease current by 12.5%
 *  0b10..Decrease current by 25.0%
 *  0b11..Decrease current by 37.5%
 */
#define CCM_ANALOG_MISC0_CLR_OSC_I(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_OSC_I_SHIFT)) & CCM_ANALOG_MISC0_CLR_OSC_I_MASK)

#define CCM_ANALOG_MISC0_CLR_OSC_XTALOK_MASK     (0x8000U)
#define CCM_ANALOG_MISC0_CLR_OSC_XTALOK_SHIFT    (15U)
#define CCM_ANALOG_MISC0_CLR_OSC_XTALOK(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_OSC_XTALOK_SHIFT)) & CCM_ANALOG_MISC0_CLR_OSC_XTALOK_MASK)

#define CCM_ANALOG_MISC0_CLR_OSC_XTALOK_EN_MASK  (0x10000U)
#define CCM_ANALOG_MISC0_CLR_OSC_XTALOK_EN_SHIFT (16U)
#define CCM_ANALOG_MISC0_CLR_OSC_XTALOK_EN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_OSC_XTALOK_EN_SHIFT)) & CCM_ANALOG_MISC0_CLR_OSC_XTALOK_EN_MASK)

#define CCM_ANALOG_MISC0_CLR_CLKGATE_CTRL_MASK   (0x2000000U)
#define CCM_ANALOG_MISC0_CLR_CLKGATE_CTRL_SHIFT  (25U)
/*! CLKGATE_CTRL
 *  0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
 *  0b1..Prevent the logic from ever gating off the clock.
 */
#define CCM_ANALOG_MISC0_CLR_CLKGATE_CTRL(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_CLKGATE_CTRL_SHIFT)) & CCM_ANALOG_MISC0_CLR_CLKGATE_CTRL_MASK)

#define CCM_ANALOG_MISC0_CLR_CLKGATE_DELAY_MASK  (0x1C000000U)
#define CCM_ANALOG_MISC0_CLR_CLKGATE_DELAY_SHIFT (26U)
/*! CLKGATE_DELAY
 *  0b000..0.5ms
 *  0b001..1.0ms
 *  0b010..2.0ms
 *  0b011..3.0ms
 *  0b100..4.0ms
 *  0b101..5.0ms
 *  0b110..6.0ms
 *  0b111..7.0ms
 */
#define CCM_ANALOG_MISC0_CLR_CLKGATE_DELAY(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_CLKGATE_DELAY_SHIFT)) & CCM_ANALOG_MISC0_CLR_CLKGATE_DELAY_MASK)

#define CCM_ANALOG_MISC0_CLR_RTC_XTAL_SOURCE_MASK (0x20000000U)
#define CCM_ANALOG_MISC0_CLR_RTC_XTAL_SOURCE_SHIFT (29U)
/*! RTC_XTAL_SOURCE
 *  0b0..Internal ring oscillator
 *  0b1..RTC_XTAL
 */
#define CCM_ANALOG_MISC0_CLR_RTC_XTAL_SOURCE(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_RTC_XTAL_SOURCE_SHIFT)) & CCM_ANALOG_MISC0_CLR_RTC_XTAL_SOURCE_MASK)

#define CCM_ANALOG_MISC0_CLR_XTAL_24M_PWD_MASK   (0x40000000U)
#define CCM_ANALOG_MISC0_CLR_XTAL_24M_PWD_SHIFT  (30U)
#define CCM_ANALOG_MISC0_CLR_XTAL_24M_PWD(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_CLR_XTAL_24M_PWD_SHIFT)) & CCM_ANALOG_MISC0_CLR_XTAL_24M_PWD_MASK)
/*! @} */

/*! @name MISC0_TOG - Miscellaneous Register 0 */
/*! @{ */

#define CCM_ANALOG_MISC0_TOG_REFTOP_PWD_MASK     (0x1U)
#define CCM_ANALOG_MISC0_TOG_REFTOP_PWD_SHIFT    (0U)
#define CCM_ANALOG_MISC0_TOG_REFTOP_PWD(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_REFTOP_PWD_SHIFT)) & CCM_ANALOG_MISC0_TOG_REFTOP_PWD_MASK)

#define CCM_ANALOG_MISC0_TOG_REFTOP_SELFBIASOFF_MASK (0x8U)
#define CCM_ANALOG_MISC0_TOG_REFTOP_SELFBIASOFF_SHIFT (3U)
/*! REFTOP_SELFBIASOFF
 *  0b0..Uses coarse bias currents for startup
 *  0b1..Uses bandgap-based bias currents for best performance.
 */
#define CCM_ANALOG_MISC0_TOG_REFTOP_SELFBIASOFF(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_REFTOP_SELFBIASOFF_SHIFT)) & CCM_ANALOG_MISC0_TOG_REFTOP_SELFBIASOFF_MASK)

#define CCM_ANALOG_MISC0_TOG_REFTOP_VBGADJ_MASK  (0x70U)
#define CCM_ANALOG_MISC0_TOG_REFTOP_VBGADJ_SHIFT (4U)
/*! REFTOP_VBGADJ
 *  0b000..Nominal VBG
 *  0b001..VBG+0.78%
 *  0b010..VBG+1.56%
 *  0b011..VBG+2.34%
 *  0b100..VBG-0.78%
 *  0b101..VBG-1.56%
 *  0b110..VBG-2.34%
 *  0b111..VBG-3.12%
 */
#define CCM_ANALOG_MISC0_TOG_REFTOP_VBGADJ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_REFTOP_VBGADJ_SHIFT)) & CCM_ANALOG_MISC0_TOG_REFTOP_VBGADJ_MASK)

#define CCM_ANALOG_MISC0_TOG_REFTOP_VBGUP_MASK   (0x80U)
#define CCM_ANALOG_MISC0_TOG_REFTOP_VBGUP_SHIFT  (7U)
#define CCM_ANALOG_MISC0_TOG_REFTOP_VBGUP(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_REFTOP_VBGUP_SHIFT)) & CCM_ANALOG_MISC0_TOG_REFTOP_VBGUP_MASK)

#define CCM_ANALOG_MISC0_TOG_STOP_MODE_CONFIG_MASK (0xC00U)
#define CCM_ANALOG_MISC0_TOG_STOP_MODE_CONFIG_SHIFT (10U)
/*! STOP_MODE_CONFIG
 *  0b00..All analog except RTC powered down on stop mode assertion.
 *  0b01..Beside RTC, analog bandgap, 1p1 and 2p5 regulators are also on.
 *  0b10..Beside RTC, 1p1 and 2p5 regulators are also on, low-power bandgap is selected so that the normal analog
 *        bandgap together with the rest analog is powered down.
 *  0b11..Beside RTC, low-power bandgap is selected and the rest analog is powered down.
 */
#define CCM_ANALOG_MISC0_TOG_STOP_MODE_CONFIG(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_STOP_MODE_CONFIG_SHIFT)) & CCM_ANALOG_MISC0_TOG_STOP_MODE_CONFIG_MASK)

#define CCM_ANALOG_MISC0_TOG_DISCON_HIGH_SNVS_MASK (0x1000U)
#define CCM_ANALOG_MISC0_TOG_DISCON_HIGH_SNVS_SHIFT (12U)
/*! DISCON_HIGH_SNVS
 *  0b0..Turn on the switch
 *  0b1..Turn off the switch
 */
#define CCM_ANALOG_MISC0_TOG_DISCON_HIGH_SNVS(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_DISCON_HIGH_SNVS_SHIFT)) & CCM_ANALOG_MISC0_TOG_DISCON_HIGH_SNVS_MASK)

#define CCM_ANALOG_MISC0_TOG_OSC_I_MASK          (0x6000U)
#define CCM_ANALOG_MISC0_TOG_OSC_I_SHIFT         (13U)
/*! OSC_I
 *  0b00..Nominal
 *  0b01..Decrease current by 12.5%
 *  0b10..Decrease current by 25.0%
 *  0b11..Decrease current by 37.5%
 */
#define CCM_ANALOG_MISC0_TOG_OSC_I(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_OSC_I_SHIFT)) & CCM_ANALOG_MISC0_TOG_OSC_I_MASK)

#define CCM_ANALOG_MISC0_TOG_OSC_XTALOK_MASK     (0x8000U)
#define CCM_ANALOG_MISC0_TOG_OSC_XTALOK_SHIFT    (15U)
#define CCM_ANALOG_MISC0_TOG_OSC_XTALOK(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_OSC_XTALOK_SHIFT)) & CCM_ANALOG_MISC0_TOG_OSC_XTALOK_MASK)

#define CCM_ANALOG_MISC0_TOG_OSC_XTALOK_EN_MASK  (0x10000U)
#define CCM_ANALOG_MISC0_TOG_OSC_XTALOK_EN_SHIFT (16U)
#define CCM_ANALOG_MISC0_TOG_OSC_XTALOK_EN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_OSC_XTALOK_EN_SHIFT)) & CCM_ANALOG_MISC0_TOG_OSC_XTALOK_EN_MASK)

#define CCM_ANALOG_MISC0_TOG_CLKGATE_CTRL_MASK   (0x2000000U)
#define CCM_ANALOG_MISC0_TOG_CLKGATE_CTRL_SHIFT  (25U)
/*! CLKGATE_CTRL
 *  0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
 *  0b1..Prevent the logic from ever gating off the clock.
 */
#define CCM_ANALOG_MISC0_TOG_CLKGATE_CTRL(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_CLKGATE_CTRL_SHIFT)) & CCM_ANALOG_MISC0_TOG_CLKGATE_CTRL_MASK)

#define CCM_ANALOG_MISC0_TOG_CLKGATE_DELAY_MASK  (0x1C000000U)
#define CCM_ANALOG_MISC0_TOG_CLKGATE_DELAY_SHIFT (26U)
/*! CLKGATE_DELAY
 *  0b000..0.5ms
 *  0b001..1.0ms
 *  0b010..2.0ms
 *  0b011..3.0ms
 *  0b100..4.0ms
 *  0b101..5.0ms
 *  0b110..6.0ms
 *  0b111..7.0ms
 */
#define CCM_ANALOG_MISC0_TOG_CLKGATE_DELAY(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_CLKGATE_DELAY_SHIFT)) & CCM_ANALOG_MISC0_TOG_CLKGATE_DELAY_MASK)

#define CCM_ANALOG_MISC0_TOG_RTC_XTAL_SOURCE_MASK (0x20000000U)
#define CCM_ANALOG_MISC0_TOG_RTC_XTAL_SOURCE_SHIFT (29U)
/*! RTC_XTAL_SOURCE
 *  0b0..Internal ring oscillator
 *  0b1..RTC_XTAL
 */
#define CCM_ANALOG_MISC0_TOG_RTC_XTAL_SOURCE(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_RTC_XTAL_SOURCE_SHIFT)) & CCM_ANALOG_MISC0_TOG_RTC_XTAL_SOURCE_MASK)

#define CCM_ANALOG_MISC0_TOG_XTAL_24M_PWD_MASK   (0x40000000U)
#define CCM_ANALOG_MISC0_TOG_XTAL_24M_PWD_SHIFT  (30U)
#define CCM_ANALOG_MISC0_TOG_XTAL_24M_PWD(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC0_TOG_XTAL_24M_PWD_SHIFT)) & CCM_ANALOG_MISC0_TOG_XTAL_24M_PWD_MASK)
/*! @} */

/*! @name MISC1 - Miscellaneous Register 1 */
/*! @{ */

#define CCM_ANALOG_MISC1_LVDS1_CLK_SEL_MASK      (0x1FU)
#define CCM_ANALOG_MISC1_LVDS1_CLK_SEL_SHIFT     (0U)
/*! LVDS1_CLK_SEL
 *  0b00000..Arm PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 */
#define CCM_ANALOG_MISC1_LVDS1_CLK_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_LVDS1_CLK_SEL_SHIFT)) & CCM_ANALOG_MISC1_LVDS1_CLK_SEL_MASK)

#define CCM_ANALOG_MISC1_LVDSCLK1_OBEN_MASK      (0x400U)
#define CCM_ANALOG_MISC1_LVDSCLK1_OBEN_SHIFT     (10U)
#define CCM_ANALOG_MISC1_LVDSCLK1_OBEN(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_LVDSCLK1_OBEN_SHIFT)) & CCM_ANALOG_MISC1_LVDSCLK1_OBEN_MASK)

#define CCM_ANALOG_MISC1_LVDSCLK1_IBEN_MASK      (0x1000U)
#define CCM_ANALOG_MISC1_LVDSCLK1_IBEN_SHIFT     (12U)
#define CCM_ANALOG_MISC1_LVDSCLK1_IBEN(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_LVDSCLK1_IBEN_SHIFT)) & CCM_ANALOG_MISC1_LVDSCLK1_IBEN_MASK)

#define CCM_ANALOG_MISC1_PFD_480_AUTOGATE_EN_MASK (0x10000U)
#define CCM_ANALOG_MISC1_PFD_480_AUTOGATE_EN_SHIFT (16U)
#define CCM_ANALOG_MISC1_PFD_480_AUTOGATE_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_PFD_480_AUTOGATE_EN_SHIFT)) & CCM_ANALOG_MISC1_PFD_480_AUTOGATE_EN_MASK)

#define CCM_ANALOG_MISC1_PFD_528_AUTOGATE_EN_MASK (0x20000U)
#define CCM_ANALOG_MISC1_PFD_528_AUTOGATE_EN_SHIFT (17U)
#define CCM_ANALOG_MISC1_PFD_528_AUTOGATE_EN(x)  (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_PFD_528_AUTOGATE_EN_SHIFT)) & CCM_ANALOG_MISC1_PFD_528_AUTOGATE_EN_MASK)

#define CCM_ANALOG_MISC1_IRQ_TEMPPANIC_MASK      (0x8000000U)
#define CCM_ANALOG_MISC1_IRQ_TEMPPANIC_SHIFT     (27U)
#define CCM_ANALOG_MISC1_IRQ_TEMPPANIC(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_IRQ_TEMPPANIC_SHIFT)) & CCM_ANALOG_MISC1_IRQ_TEMPPANIC_MASK)

#define CCM_ANALOG_MISC1_IRQ_TEMPLOW_MASK        (0x10000000U)
#define CCM_ANALOG_MISC1_IRQ_TEMPLOW_SHIFT       (28U)
#define CCM_ANALOG_MISC1_IRQ_TEMPLOW(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_IRQ_TEMPLOW_SHIFT)) & CCM_ANALOG_MISC1_IRQ_TEMPLOW_MASK)

#define CCM_ANALOG_MISC1_IRQ_TEMPHIGH_MASK       (0x20000000U)
#define CCM_ANALOG_MISC1_IRQ_TEMPHIGH_SHIFT      (29U)
#define CCM_ANALOG_MISC1_IRQ_TEMPHIGH(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_IRQ_TEMPHIGH_SHIFT)) & CCM_ANALOG_MISC1_IRQ_TEMPHIGH_MASK)

#define CCM_ANALOG_MISC1_IRQ_ANA_BO_MASK         (0x40000000U)
#define CCM_ANALOG_MISC1_IRQ_ANA_BO_SHIFT        (30U)
#define CCM_ANALOG_MISC1_IRQ_ANA_BO(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_IRQ_ANA_BO_SHIFT)) & CCM_ANALOG_MISC1_IRQ_ANA_BO_MASK)

#define CCM_ANALOG_MISC1_IRQ_DIG_BO_MASK         (0x80000000U)
#define CCM_ANALOG_MISC1_IRQ_DIG_BO_SHIFT        (31U)
#define CCM_ANALOG_MISC1_IRQ_DIG_BO(x)           (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_IRQ_DIG_BO_SHIFT)) & CCM_ANALOG_MISC1_IRQ_DIG_BO_MASK)
/*! @} */

/*! @name MISC1_SET - Miscellaneous Register 1 */
/*! @{ */

#define CCM_ANALOG_MISC1_SET_LVDS1_CLK_SEL_MASK  (0x1FU)
#define CCM_ANALOG_MISC1_SET_LVDS1_CLK_SEL_SHIFT (0U)
/*! LVDS1_CLK_SEL
 *  0b00000..Arm PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 */
#define CCM_ANALOG_MISC1_SET_LVDS1_CLK_SEL(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_SET_LVDS1_CLK_SEL_SHIFT)) & CCM_ANALOG_MISC1_SET_LVDS1_CLK_SEL_MASK)

#define CCM_ANALOG_MISC1_SET_LVDSCLK1_OBEN_MASK  (0x400U)
#define CCM_ANALOG_MISC1_SET_LVDSCLK1_OBEN_SHIFT (10U)
#define CCM_ANALOG_MISC1_SET_LVDSCLK1_OBEN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_SET_LVDSCLK1_OBEN_SHIFT)) & CCM_ANALOG_MISC1_SET_LVDSCLK1_OBEN_MASK)

#define CCM_ANALOG_MISC1_SET_LVDSCLK1_IBEN_MASK  (0x1000U)
#define CCM_ANALOG_MISC1_SET_LVDSCLK1_IBEN_SHIFT (12U)
#define CCM_ANALOG_MISC1_SET_LVDSCLK1_IBEN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_SET_LVDSCLK1_IBEN_SHIFT)) & CCM_ANALOG_MISC1_SET_LVDSCLK1_IBEN_MASK)

#define CCM_ANALOG_MISC1_SET_PFD_480_AUTOGATE_EN_MASK (0x10000U)
#define CCM_ANALOG_MISC1_SET_PFD_480_AUTOGATE_EN_SHIFT (16U)
#define CCM_ANALOG_MISC1_SET_PFD_480_AUTOGATE_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_SET_PFD_480_AUTOGATE_EN_SHIFT)) & CCM_ANALOG_MISC1_SET_PFD_480_AUTOGATE_EN_MASK)

#define CCM_ANALOG_MISC1_SET_PFD_528_AUTOGATE_EN_MASK (0x20000U)
#define CCM_ANALOG_MISC1_SET_PFD_528_AUTOGATE_EN_SHIFT (17U)
#define CCM_ANALOG_MISC1_SET_PFD_528_AUTOGATE_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_SET_PFD_528_AUTOGATE_EN_SHIFT)) & CCM_ANALOG_MISC1_SET_PFD_528_AUTOGATE_EN_MASK)

#define CCM_ANALOG_MISC1_SET_IRQ_TEMPPANIC_MASK  (0x8000000U)
#define CCM_ANALOG_MISC1_SET_IRQ_TEMPPANIC_SHIFT (27U)
#define CCM_ANALOG_MISC1_SET_IRQ_TEMPPANIC(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_SET_IRQ_TEMPPANIC_SHIFT)) & CCM_ANALOG_MISC1_SET_IRQ_TEMPPANIC_MASK)

#define CCM_ANALOG_MISC1_SET_IRQ_TEMPLOW_MASK    (0x10000000U)
#define CCM_ANALOG_MISC1_SET_IRQ_TEMPLOW_SHIFT   (28U)
#define CCM_ANALOG_MISC1_SET_IRQ_TEMPLOW(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_SET_IRQ_TEMPLOW_SHIFT)) & CCM_ANALOG_MISC1_SET_IRQ_TEMPLOW_MASK)

#define CCM_ANALOG_MISC1_SET_IRQ_TEMPHIGH_MASK   (0x20000000U)
#define CCM_ANALOG_MISC1_SET_IRQ_TEMPHIGH_SHIFT  (29U)
#define CCM_ANALOG_MISC1_SET_IRQ_TEMPHIGH(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_SET_IRQ_TEMPHIGH_SHIFT)) & CCM_ANALOG_MISC1_SET_IRQ_TEMPHIGH_MASK)

#define CCM_ANALOG_MISC1_SET_IRQ_ANA_BO_MASK     (0x40000000U)
#define CCM_ANALOG_MISC1_SET_IRQ_ANA_BO_SHIFT    (30U)
#define CCM_ANALOG_MISC1_SET_IRQ_ANA_BO(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_SET_IRQ_ANA_BO_SHIFT)) & CCM_ANALOG_MISC1_SET_IRQ_ANA_BO_MASK)

#define CCM_ANALOG_MISC1_SET_IRQ_DIG_BO_MASK     (0x80000000U)
#define CCM_ANALOG_MISC1_SET_IRQ_DIG_BO_SHIFT    (31U)
#define CCM_ANALOG_MISC1_SET_IRQ_DIG_BO(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_SET_IRQ_DIG_BO_SHIFT)) & CCM_ANALOG_MISC1_SET_IRQ_DIG_BO_MASK)
/*! @} */

/*! @name MISC1_CLR - Miscellaneous Register 1 */
/*! @{ */

#define CCM_ANALOG_MISC1_CLR_LVDS1_CLK_SEL_MASK  (0x1FU)
#define CCM_ANALOG_MISC1_CLR_LVDS1_CLK_SEL_SHIFT (0U)
/*! LVDS1_CLK_SEL
 *  0b00000..Arm PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 */
#define CCM_ANALOG_MISC1_CLR_LVDS1_CLK_SEL(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_CLR_LVDS1_CLK_SEL_SHIFT)) & CCM_ANALOG_MISC1_CLR_LVDS1_CLK_SEL_MASK)

#define CCM_ANALOG_MISC1_CLR_LVDSCLK1_OBEN_MASK  (0x400U)
#define CCM_ANALOG_MISC1_CLR_LVDSCLK1_OBEN_SHIFT (10U)
#define CCM_ANALOG_MISC1_CLR_LVDSCLK1_OBEN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_CLR_LVDSCLK1_OBEN_SHIFT)) & CCM_ANALOG_MISC1_CLR_LVDSCLK1_OBEN_MASK)

#define CCM_ANALOG_MISC1_CLR_LVDSCLK1_IBEN_MASK  (0x1000U)
#define CCM_ANALOG_MISC1_CLR_LVDSCLK1_IBEN_SHIFT (12U)
#define CCM_ANALOG_MISC1_CLR_LVDSCLK1_IBEN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_CLR_LVDSCLK1_IBEN_SHIFT)) & CCM_ANALOG_MISC1_CLR_LVDSCLK1_IBEN_MASK)

#define CCM_ANALOG_MISC1_CLR_PFD_480_AUTOGATE_EN_MASK (0x10000U)
#define CCM_ANALOG_MISC1_CLR_PFD_480_AUTOGATE_EN_SHIFT (16U)
#define CCM_ANALOG_MISC1_CLR_PFD_480_AUTOGATE_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_CLR_PFD_480_AUTOGATE_EN_SHIFT)) & CCM_ANALOG_MISC1_CLR_PFD_480_AUTOGATE_EN_MASK)

#define CCM_ANALOG_MISC1_CLR_PFD_528_AUTOGATE_EN_MASK (0x20000U)
#define CCM_ANALOG_MISC1_CLR_PFD_528_AUTOGATE_EN_SHIFT (17U)
#define CCM_ANALOG_MISC1_CLR_PFD_528_AUTOGATE_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_CLR_PFD_528_AUTOGATE_EN_SHIFT)) & CCM_ANALOG_MISC1_CLR_PFD_528_AUTOGATE_EN_MASK)

#define CCM_ANALOG_MISC1_CLR_IRQ_TEMPPANIC_MASK  (0x8000000U)
#define CCM_ANALOG_MISC1_CLR_IRQ_TEMPPANIC_SHIFT (27U)
#define CCM_ANALOG_MISC1_CLR_IRQ_TEMPPANIC(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_CLR_IRQ_TEMPPANIC_SHIFT)) & CCM_ANALOG_MISC1_CLR_IRQ_TEMPPANIC_MASK)

#define CCM_ANALOG_MISC1_CLR_IRQ_TEMPLOW_MASK    (0x10000000U)
#define CCM_ANALOG_MISC1_CLR_IRQ_TEMPLOW_SHIFT   (28U)
#define CCM_ANALOG_MISC1_CLR_IRQ_TEMPLOW(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_CLR_IRQ_TEMPLOW_SHIFT)) & CCM_ANALOG_MISC1_CLR_IRQ_TEMPLOW_MASK)

#define CCM_ANALOG_MISC1_CLR_IRQ_TEMPHIGH_MASK   (0x20000000U)
#define CCM_ANALOG_MISC1_CLR_IRQ_TEMPHIGH_SHIFT  (29U)
#define CCM_ANALOG_MISC1_CLR_IRQ_TEMPHIGH(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_CLR_IRQ_TEMPHIGH_SHIFT)) & CCM_ANALOG_MISC1_CLR_IRQ_TEMPHIGH_MASK)

#define CCM_ANALOG_MISC1_CLR_IRQ_ANA_BO_MASK     (0x40000000U)
#define CCM_ANALOG_MISC1_CLR_IRQ_ANA_BO_SHIFT    (30U)
#define CCM_ANALOG_MISC1_CLR_IRQ_ANA_BO(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_CLR_IRQ_ANA_BO_SHIFT)) & CCM_ANALOG_MISC1_CLR_IRQ_ANA_BO_MASK)

#define CCM_ANALOG_MISC1_CLR_IRQ_DIG_BO_MASK     (0x80000000U)
#define CCM_ANALOG_MISC1_CLR_IRQ_DIG_BO_SHIFT    (31U)
#define CCM_ANALOG_MISC1_CLR_IRQ_DIG_BO(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_CLR_IRQ_DIG_BO_SHIFT)) & CCM_ANALOG_MISC1_CLR_IRQ_DIG_BO_MASK)
/*! @} */

/*! @name MISC1_TOG - Miscellaneous Register 1 */
/*! @{ */

#define CCM_ANALOG_MISC1_TOG_LVDS1_CLK_SEL_MASK  (0x1FU)
#define CCM_ANALOG_MISC1_TOG_LVDS1_CLK_SEL_SHIFT (0U)
/*! LVDS1_CLK_SEL
 *  0b00000..Arm PLL
 *  0b00001..System PLL
 *  0b00010..ref_pfd4_clk == pll2_pfd0_clk
 *  0b00011..ref_pfd5_clk == pll2_pfd1_clk
 *  0b00100..ref_pfd6_clk == pll2_pfd2_clk
 *  0b00101..ref_pfd7_clk == pll2_pfd3_clk
 *  0b00110..Audio PLL
 *  0b00111..Video PLL
 *  0b01001..ethernet ref clock (ENET_PLL)
 *  0b01100..USB1 PLL clock
 *  0b01101..USB2 PLL clock
 *  0b01110..ref_pfd0_clk == pll3_pfd0_clk
 *  0b01111..ref_pfd1_clk == pll3_pfd1_clk
 *  0b10000..ref_pfd2_clk == pll3_pfd2_clk
 *  0b10001..ref_pfd3_clk == pll3_pfd3_clk
 *  0b10010..xtal (24M)
 */
#define CCM_ANALOG_MISC1_TOG_LVDS1_CLK_SEL(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_TOG_LVDS1_CLK_SEL_SHIFT)) & CCM_ANALOG_MISC1_TOG_LVDS1_CLK_SEL_MASK)

#define CCM_ANALOG_MISC1_TOG_LVDSCLK1_OBEN_MASK  (0x400U)
#define CCM_ANALOG_MISC1_TOG_LVDSCLK1_OBEN_SHIFT (10U)
#define CCM_ANALOG_MISC1_TOG_LVDSCLK1_OBEN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_TOG_LVDSCLK1_OBEN_SHIFT)) & CCM_ANALOG_MISC1_TOG_LVDSCLK1_OBEN_MASK)

#define CCM_ANALOG_MISC1_TOG_LVDSCLK1_IBEN_MASK  (0x1000U)
#define CCM_ANALOG_MISC1_TOG_LVDSCLK1_IBEN_SHIFT (12U)
#define CCM_ANALOG_MISC1_TOG_LVDSCLK1_IBEN(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_TOG_LVDSCLK1_IBEN_SHIFT)) & CCM_ANALOG_MISC1_TOG_LVDSCLK1_IBEN_MASK)

#define CCM_ANALOG_MISC1_TOG_PFD_480_AUTOGATE_EN_MASK (0x10000U)
#define CCM_ANALOG_MISC1_TOG_PFD_480_AUTOGATE_EN_SHIFT (16U)
#define CCM_ANALOG_MISC1_TOG_PFD_480_AUTOGATE_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_TOG_PFD_480_AUTOGATE_EN_SHIFT)) & CCM_ANALOG_MISC1_TOG_PFD_480_AUTOGATE_EN_MASK)

#define CCM_ANALOG_MISC1_TOG_PFD_528_AUTOGATE_EN_MASK (0x20000U)
#define CCM_ANALOG_MISC1_TOG_PFD_528_AUTOGATE_EN_SHIFT (17U)
#define CCM_ANALOG_MISC1_TOG_PFD_528_AUTOGATE_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_TOG_PFD_528_AUTOGATE_EN_SHIFT)) & CCM_ANALOG_MISC1_TOG_PFD_528_AUTOGATE_EN_MASK)

#define CCM_ANALOG_MISC1_TOG_IRQ_TEMPPANIC_MASK  (0x8000000U)
#define CCM_ANALOG_MISC1_TOG_IRQ_TEMPPANIC_SHIFT (27U)
#define CCM_ANALOG_MISC1_TOG_IRQ_TEMPPANIC(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_TOG_IRQ_TEMPPANIC_SHIFT)) & CCM_ANALOG_MISC1_TOG_IRQ_TEMPPANIC_MASK)

#define CCM_ANALOG_MISC1_TOG_IRQ_TEMPLOW_MASK    (0x10000000U)
#define CCM_ANALOG_MISC1_TOG_IRQ_TEMPLOW_SHIFT   (28U)
#define CCM_ANALOG_MISC1_TOG_IRQ_TEMPLOW(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_TOG_IRQ_TEMPLOW_SHIFT)) & CCM_ANALOG_MISC1_TOG_IRQ_TEMPLOW_MASK)

#define CCM_ANALOG_MISC1_TOG_IRQ_TEMPHIGH_MASK   (0x20000000U)
#define CCM_ANALOG_MISC1_TOG_IRQ_TEMPHIGH_SHIFT  (29U)
#define CCM_ANALOG_MISC1_TOG_IRQ_TEMPHIGH(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_TOG_IRQ_TEMPHIGH_SHIFT)) & CCM_ANALOG_MISC1_TOG_IRQ_TEMPHIGH_MASK)

#define CCM_ANALOG_MISC1_TOG_IRQ_ANA_BO_MASK     (0x40000000U)
#define CCM_ANALOG_MISC1_TOG_IRQ_ANA_BO_SHIFT    (30U)
#define CCM_ANALOG_MISC1_TOG_IRQ_ANA_BO(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_TOG_IRQ_ANA_BO_SHIFT)) & CCM_ANALOG_MISC1_TOG_IRQ_ANA_BO_MASK)

#define CCM_ANALOG_MISC1_TOG_IRQ_DIG_BO_MASK     (0x80000000U)
#define CCM_ANALOG_MISC1_TOG_IRQ_DIG_BO_SHIFT    (31U)
#define CCM_ANALOG_MISC1_TOG_IRQ_DIG_BO(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC1_TOG_IRQ_DIG_BO_SHIFT)) & CCM_ANALOG_MISC1_TOG_IRQ_DIG_BO_MASK)
/*! @} */

/*! @name MISC2 - Miscellaneous Register 2 */
/*! @{ */

#define CCM_ANALOG_MISC2_REG0_BO_OFFSET_MASK     (0x7U)
#define CCM_ANALOG_MISC2_REG0_BO_OFFSET_SHIFT    (0U)
/*! REG0_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_REG0_BO_OFFSET(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG0_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_REG0_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_REG0_BO_STATUS_MASK     (0x8U)
#define CCM_ANALOG_MISC2_REG0_BO_STATUS_SHIFT    (3U)
/*! REG0_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define CCM_ANALOG_MISC2_REG0_BO_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG0_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_REG0_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_REG0_ENABLE_BO_MASK     (0x20U)
#define CCM_ANALOG_MISC2_REG0_ENABLE_BO_SHIFT    (5U)
#define CCM_ANALOG_MISC2_REG0_ENABLE_BO(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG0_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_REG0_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_REG0_OK_MASK            (0x40U)
#define CCM_ANALOG_MISC2_REG0_OK_SHIFT           (6U)
#define CCM_ANALOG_MISC2_REG0_OK(x)              (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG0_OK_SHIFT)) & CCM_ANALOG_MISC2_REG0_OK_MASK)

#define CCM_ANALOG_MISC2_PLL3_DISABLE_MASK       (0x80U)
#define CCM_ANALOG_MISC2_PLL3_DISABLE_SHIFT      (7U)
/*! PLL3_DISABLE
 *  0b0..PLL3 is being used by peripherals and is enabled when SoC is not in any low power mode
 *  0b1..PLL3 can be disabled when the SoC is not in any low power mode
 */
#define CCM_ANALOG_MISC2_PLL3_DISABLE(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_PLL3_DISABLE_SHIFT)) & CCM_ANALOG_MISC2_PLL3_DISABLE_MASK)

#define CCM_ANALOG_MISC2_REG1_BO_OFFSET_MASK     (0x700U)
#define CCM_ANALOG_MISC2_REG1_BO_OFFSET_SHIFT    (8U)
/*! REG1_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_REG1_BO_OFFSET(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG1_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_REG1_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_REG1_BO_STATUS_MASK     (0x800U)
#define CCM_ANALOG_MISC2_REG1_BO_STATUS_SHIFT    (11U)
/*! REG1_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define CCM_ANALOG_MISC2_REG1_BO_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG1_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_REG1_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_REG1_ENABLE_BO_MASK     (0x2000U)
#define CCM_ANALOG_MISC2_REG1_ENABLE_BO_SHIFT    (13U)
#define CCM_ANALOG_MISC2_REG1_ENABLE_BO(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG1_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_REG1_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_REG1_OK_MASK            (0x4000U)
#define CCM_ANALOG_MISC2_REG1_OK_SHIFT           (14U)
#define CCM_ANALOG_MISC2_REG1_OK(x)              (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG1_OK_SHIFT)) & CCM_ANALOG_MISC2_REG1_OK_MASK)

#define CCM_ANALOG_MISC2_AUDIO_DIV_LSB_MASK      (0x8000U)
#define CCM_ANALOG_MISC2_AUDIO_DIV_LSB_SHIFT     (15U)
/*! AUDIO_DIV_LSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define CCM_ANALOG_MISC2_AUDIO_DIV_LSB(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_AUDIO_DIV_LSB_SHIFT)) & CCM_ANALOG_MISC2_AUDIO_DIV_LSB_MASK)

#define CCM_ANALOG_MISC2_REG2_BO_OFFSET_MASK     (0x70000U)
#define CCM_ANALOG_MISC2_REG2_BO_OFFSET_SHIFT    (16U)
/*! REG2_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_REG2_BO_OFFSET(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG2_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_REG2_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_REG2_BO_STATUS_MASK     (0x80000U)
#define CCM_ANALOG_MISC2_REG2_BO_STATUS_SHIFT    (19U)
#define CCM_ANALOG_MISC2_REG2_BO_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG2_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_REG2_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_REG2_ENABLE_BO_MASK     (0x200000U)
#define CCM_ANALOG_MISC2_REG2_ENABLE_BO_SHIFT    (21U)
#define CCM_ANALOG_MISC2_REG2_ENABLE_BO(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG2_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_REG2_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_REG2_OK_MASK            (0x400000U)
#define CCM_ANALOG_MISC2_REG2_OK_SHIFT           (22U)
#define CCM_ANALOG_MISC2_REG2_OK(x)              (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG2_OK_SHIFT)) & CCM_ANALOG_MISC2_REG2_OK_MASK)

#define CCM_ANALOG_MISC2_AUDIO_DIV_MSB_MASK      (0x800000U)
#define CCM_ANALOG_MISC2_AUDIO_DIV_MSB_SHIFT     (23U)
/*! AUDIO_DIV_MSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define CCM_ANALOG_MISC2_AUDIO_DIV_MSB(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_AUDIO_DIV_MSB_SHIFT)) & CCM_ANALOG_MISC2_AUDIO_DIV_MSB_MASK)

#define CCM_ANALOG_MISC2_REG0_STEP_TIME_MASK     (0x3000000U)
#define CCM_ANALOG_MISC2_REG0_STEP_TIME_SHIFT    (24U)
/*! REG0_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_REG0_STEP_TIME(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG0_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_REG0_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_REG1_STEP_TIME_MASK     (0xC000000U)
#define CCM_ANALOG_MISC2_REG1_STEP_TIME_SHIFT    (26U)
/*! REG1_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_REG1_STEP_TIME(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG1_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_REG1_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_REG2_STEP_TIME_MASK     (0x30000000U)
#define CCM_ANALOG_MISC2_REG2_STEP_TIME_SHIFT    (28U)
/*! REG2_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_REG2_STEP_TIME(x)       (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_REG2_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_REG2_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_VIDEO_DIV_MASK          (0xC0000000U)
#define CCM_ANALOG_MISC2_VIDEO_DIV_SHIFT         (30U)
/*! VIDEO_DIV
 *  0b00..divide by 1 (Default)
 *  0b01..divide by 2
 *  0b10..divide by 1
 *  0b11..divide by 4
 */
#define CCM_ANALOG_MISC2_VIDEO_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_VIDEO_DIV_SHIFT)) & CCM_ANALOG_MISC2_VIDEO_DIV_MASK)
/*! @} */

/*! @name MISC2_SET - Miscellaneous Register 2 */
/*! @{ */

#define CCM_ANALOG_MISC2_SET_REG0_BO_OFFSET_MASK (0x7U)
#define CCM_ANALOG_MISC2_SET_REG0_BO_OFFSET_SHIFT (0U)
/*! REG0_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_SET_REG0_BO_OFFSET(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG0_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_SET_REG0_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_SET_REG0_BO_STATUS_MASK (0x8U)
#define CCM_ANALOG_MISC2_SET_REG0_BO_STATUS_SHIFT (3U)
/*! REG0_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define CCM_ANALOG_MISC2_SET_REG0_BO_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG0_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_SET_REG0_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_SET_REG0_ENABLE_BO_MASK (0x20U)
#define CCM_ANALOG_MISC2_SET_REG0_ENABLE_BO_SHIFT (5U)
#define CCM_ANALOG_MISC2_SET_REG0_ENABLE_BO(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG0_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_SET_REG0_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_SET_REG0_OK_MASK        (0x40U)
#define CCM_ANALOG_MISC2_SET_REG0_OK_SHIFT       (6U)
#define CCM_ANALOG_MISC2_SET_REG0_OK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG0_OK_SHIFT)) & CCM_ANALOG_MISC2_SET_REG0_OK_MASK)

#define CCM_ANALOG_MISC2_SET_PLL3_DISABLE_MASK   (0x80U)
#define CCM_ANALOG_MISC2_SET_PLL3_DISABLE_SHIFT  (7U)
/*! PLL3_DISABLE
 *  0b0..PLL3 is being used by peripherals and is enabled when SoC is not in any low power mode
 *  0b1..PLL3 can be disabled when the SoC is not in any low power mode
 */
#define CCM_ANALOG_MISC2_SET_PLL3_DISABLE(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_PLL3_DISABLE_SHIFT)) & CCM_ANALOG_MISC2_SET_PLL3_DISABLE_MASK)

#define CCM_ANALOG_MISC2_SET_REG1_BO_OFFSET_MASK (0x700U)
#define CCM_ANALOG_MISC2_SET_REG1_BO_OFFSET_SHIFT (8U)
/*! REG1_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_SET_REG1_BO_OFFSET(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG1_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_SET_REG1_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_SET_REG1_BO_STATUS_MASK (0x800U)
#define CCM_ANALOG_MISC2_SET_REG1_BO_STATUS_SHIFT (11U)
/*! REG1_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define CCM_ANALOG_MISC2_SET_REG1_BO_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG1_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_SET_REG1_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_SET_REG1_ENABLE_BO_MASK (0x2000U)
#define CCM_ANALOG_MISC2_SET_REG1_ENABLE_BO_SHIFT (13U)
#define CCM_ANALOG_MISC2_SET_REG1_ENABLE_BO(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG1_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_SET_REG1_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_SET_REG1_OK_MASK        (0x4000U)
#define CCM_ANALOG_MISC2_SET_REG1_OK_SHIFT       (14U)
#define CCM_ANALOG_MISC2_SET_REG1_OK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG1_OK_SHIFT)) & CCM_ANALOG_MISC2_SET_REG1_OK_MASK)

#define CCM_ANALOG_MISC2_SET_AUDIO_DIV_LSB_MASK  (0x8000U)
#define CCM_ANALOG_MISC2_SET_AUDIO_DIV_LSB_SHIFT (15U)
/*! AUDIO_DIV_LSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define CCM_ANALOG_MISC2_SET_AUDIO_DIV_LSB(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_AUDIO_DIV_LSB_SHIFT)) & CCM_ANALOG_MISC2_SET_AUDIO_DIV_LSB_MASK)

#define CCM_ANALOG_MISC2_SET_REG2_BO_OFFSET_MASK (0x70000U)
#define CCM_ANALOG_MISC2_SET_REG2_BO_OFFSET_SHIFT (16U)
/*! REG2_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_SET_REG2_BO_OFFSET(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG2_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_SET_REG2_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_SET_REG2_BO_STATUS_MASK (0x80000U)
#define CCM_ANALOG_MISC2_SET_REG2_BO_STATUS_SHIFT (19U)
#define CCM_ANALOG_MISC2_SET_REG2_BO_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG2_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_SET_REG2_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_SET_REG2_ENABLE_BO_MASK (0x200000U)
#define CCM_ANALOG_MISC2_SET_REG2_ENABLE_BO_SHIFT (21U)
#define CCM_ANALOG_MISC2_SET_REG2_ENABLE_BO(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG2_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_SET_REG2_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_SET_REG2_OK_MASK        (0x400000U)
#define CCM_ANALOG_MISC2_SET_REG2_OK_SHIFT       (22U)
#define CCM_ANALOG_MISC2_SET_REG2_OK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG2_OK_SHIFT)) & CCM_ANALOG_MISC2_SET_REG2_OK_MASK)

#define CCM_ANALOG_MISC2_SET_AUDIO_DIV_MSB_MASK  (0x800000U)
#define CCM_ANALOG_MISC2_SET_AUDIO_DIV_MSB_SHIFT (23U)
/*! AUDIO_DIV_MSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define CCM_ANALOG_MISC2_SET_AUDIO_DIV_MSB(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_AUDIO_DIV_MSB_SHIFT)) & CCM_ANALOG_MISC2_SET_AUDIO_DIV_MSB_MASK)

#define CCM_ANALOG_MISC2_SET_REG0_STEP_TIME_MASK (0x3000000U)
#define CCM_ANALOG_MISC2_SET_REG0_STEP_TIME_SHIFT (24U)
/*! REG0_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_SET_REG0_STEP_TIME(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG0_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_SET_REG0_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_SET_REG1_STEP_TIME_MASK (0xC000000U)
#define CCM_ANALOG_MISC2_SET_REG1_STEP_TIME_SHIFT (26U)
/*! REG1_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_SET_REG1_STEP_TIME(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG1_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_SET_REG1_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_SET_REG2_STEP_TIME_MASK (0x30000000U)
#define CCM_ANALOG_MISC2_SET_REG2_STEP_TIME_SHIFT (28U)
/*! REG2_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_SET_REG2_STEP_TIME(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_REG2_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_SET_REG2_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_SET_VIDEO_DIV_MASK      (0xC0000000U)
#define CCM_ANALOG_MISC2_SET_VIDEO_DIV_SHIFT     (30U)
/*! VIDEO_DIV
 *  0b00..divide by 1 (Default)
 *  0b01..divide by 2
 *  0b10..divide by 1
 *  0b11..divide by 4
 */
#define CCM_ANALOG_MISC2_SET_VIDEO_DIV(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_SET_VIDEO_DIV_SHIFT)) & CCM_ANALOG_MISC2_SET_VIDEO_DIV_MASK)
/*! @} */

/*! @name MISC2_CLR - Miscellaneous Register 2 */
/*! @{ */

#define CCM_ANALOG_MISC2_CLR_REG0_BO_OFFSET_MASK (0x7U)
#define CCM_ANALOG_MISC2_CLR_REG0_BO_OFFSET_SHIFT (0U)
/*! REG0_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_CLR_REG0_BO_OFFSET(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG0_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG0_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_CLR_REG0_BO_STATUS_MASK (0x8U)
#define CCM_ANALOG_MISC2_CLR_REG0_BO_STATUS_SHIFT (3U)
/*! REG0_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define CCM_ANALOG_MISC2_CLR_REG0_BO_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG0_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG0_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_CLR_REG0_ENABLE_BO_MASK (0x20U)
#define CCM_ANALOG_MISC2_CLR_REG0_ENABLE_BO_SHIFT (5U)
#define CCM_ANALOG_MISC2_CLR_REG0_ENABLE_BO(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG0_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG0_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_CLR_REG0_OK_MASK        (0x40U)
#define CCM_ANALOG_MISC2_CLR_REG0_OK_SHIFT       (6U)
#define CCM_ANALOG_MISC2_CLR_REG0_OK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG0_OK_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG0_OK_MASK)

#define CCM_ANALOG_MISC2_CLR_PLL3_DISABLE_MASK   (0x80U)
#define CCM_ANALOG_MISC2_CLR_PLL3_DISABLE_SHIFT  (7U)
/*! PLL3_DISABLE
 *  0b0..PLL3 is being used by peripherals and is enabled when SoC is not in any low power mode
 *  0b1..PLL3 can be disabled when the SoC is not in any low power mode
 */
#define CCM_ANALOG_MISC2_CLR_PLL3_DISABLE(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_PLL3_DISABLE_SHIFT)) & CCM_ANALOG_MISC2_CLR_PLL3_DISABLE_MASK)

#define CCM_ANALOG_MISC2_CLR_REG1_BO_OFFSET_MASK (0x700U)
#define CCM_ANALOG_MISC2_CLR_REG1_BO_OFFSET_SHIFT (8U)
/*! REG1_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_CLR_REG1_BO_OFFSET(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG1_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG1_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_CLR_REG1_BO_STATUS_MASK (0x800U)
#define CCM_ANALOG_MISC2_CLR_REG1_BO_STATUS_SHIFT (11U)
/*! REG1_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define CCM_ANALOG_MISC2_CLR_REG1_BO_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG1_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG1_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_CLR_REG1_ENABLE_BO_MASK (0x2000U)
#define CCM_ANALOG_MISC2_CLR_REG1_ENABLE_BO_SHIFT (13U)
#define CCM_ANALOG_MISC2_CLR_REG1_ENABLE_BO(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG1_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG1_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_CLR_REG1_OK_MASK        (0x4000U)
#define CCM_ANALOG_MISC2_CLR_REG1_OK_SHIFT       (14U)
#define CCM_ANALOG_MISC2_CLR_REG1_OK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG1_OK_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG1_OK_MASK)

#define CCM_ANALOG_MISC2_CLR_AUDIO_DIV_LSB_MASK  (0x8000U)
#define CCM_ANALOG_MISC2_CLR_AUDIO_DIV_LSB_SHIFT (15U)
/*! AUDIO_DIV_LSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define CCM_ANALOG_MISC2_CLR_AUDIO_DIV_LSB(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_AUDIO_DIV_LSB_SHIFT)) & CCM_ANALOG_MISC2_CLR_AUDIO_DIV_LSB_MASK)

#define CCM_ANALOG_MISC2_CLR_REG2_BO_OFFSET_MASK (0x70000U)
#define CCM_ANALOG_MISC2_CLR_REG2_BO_OFFSET_SHIFT (16U)
/*! REG2_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_CLR_REG2_BO_OFFSET(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG2_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG2_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_CLR_REG2_BO_STATUS_MASK (0x80000U)
#define CCM_ANALOG_MISC2_CLR_REG2_BO_STATUS_SHIFT (19U)
#define CCM_ANALOG_MISC2_CLR_REG2_BO_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG2_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG2_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_CLR_REG2_ENABLE_BO_MASK (0x200000U)
#define CCM_ANALOG_MISC2_CLR_REG2_ENABLE_BO_SHIFT (21U)
#define CCM_ANALOG_MISC2_CLR_REG2_ENABLE_BO(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG2_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG2_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_CLR_REG2_OK_MASK        (0x400000U)
#define CCM_ANALOG_MISC2_CLR_REG2_OK_SHIFT       (22U)
#define CCM_ANALOG_MISC2_CLR_REG2_OK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG2_OK_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG2_OK_MASK)

#define CCM_ANALOG_MISC2_CLR_AUDIO_DIV_MSB_MASK  (0x800000U)
#define CCM_ANALOG_MISC2_CLR_AUDIO_DIV_MSB_SHIFT (23U)
/*! AUDIO_DIV_MSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define CCM_ANALOG_MISC2_CLR_AUDIO_DIV_MSB(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_AUDIO_DIV_MSB_SHIFT)) & CCM_ANALOG_MISC2_CLR_AUDIO_DIV_MSB_MASK)

#define CCM_ANALOG_MISC2_CLR_REG0_STEP_TIME_MASK (0x3000000U)
#define CCM_ANALOG_MISC2_CLR_REG0_STEP_TIME_SHIFT (24U)
/*! REG0_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_CLR_REG0_STEP_TIME(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG0_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG0_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_CLR_REG1_STEP_TIME_MASK (0xC000000U)
#define CCM_ANALOG_MISC2_CLR_REG1_STEP_TIME_SHIFT (26U)
/*! REG1_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_CLR_REG1_STEP_TIME(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG1_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG1_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_CLR_REG2_STEP_TIME_MASK (0x30000000U)
#define CCM_ANALOG_MISC2_CLR_REG2_STEP_TIME_SHIFT (28U)
/*! REG2_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_CLR_REG2_STEP_TIME(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_REG2_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_CLR_REG2_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_CLR_VIDEO_DIV_MASK      (0xC0000000U)
#define CCM_ANALOG_MISC2_CLR_VIDEO_DIV_SHIFT     (30U)
/*! VIDEO_DIV
 *  0b00..divide by 1 (Default)
 *  0b01..divide by 2
 *  0b10..divide by 1
 *  0b11..divide by 4
 */
#define CCM_ANALOG_MISC2_CLR_VIDEO_DIV(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_CLR_VIDEO_DIV_SHIFT)) & CCM_ANALOG_MISC2_CLR_VIDEO_DIV_MASK)
/*! @} */

/*! @name MISC2_TOG - Miscellaneous Register 2 */
/*! @{ */

#define CCM_ANALOG_MISC2_TOG_REG0_BO_OFFSET_MASK (0x7U)
#define CCM_ANALOG_MISC2_TOG_REG0_BO_OFFSET_SHIFT (0U)
/*! REG0_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_TOG_REG0_BO_OFFSET(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG0_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG0_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_TOG_REG0_BO_STATUS_MASK (0x8U)
#define CCM_ANALOG_MISC2_TOG_REG0_BO_STATUS_SHIFT (3U)
/*! REG0_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define CCM_ANALOG_MISC2_TOG_REG0_BO_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG0_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG0_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_TOG_REG0_ENABLE_BO_MASK (0x20U)
#define CCM_ANALOG_MISC2_TOG_REG0_ENABLE_BO_SHIFT (5U)
#define CCM_ANALOG_MISC2_TOG_REG0_ENABLE_BO(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG0_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG0_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_TOG_REG0_OK_MASK        (0x40U)
#define CCM_ANALOG_MISC2_TOG_REG0_OK_SHIFT       (6U)
#define CCM_ANALOG_MISC2_TOG_REG0_OK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG0_OK_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG0_OK_MASK)

#define CCM_ANALOG_MISC2_TOG_PLL3_DISABLE_MASK   (0x80U)
#define CCM_ANALOG_MISC2_TOG_PLL3_DISABLE_SHIFT  (7U)
/*! PLL3_DISABLE
 *  0b0..PLL3 is being used by peripherals and is enabled when SoC is not in any low power mode
 *  0b1..PLL3 can be disabled when the SoC is not in any low power mode
 */
#define CCM_ANALOG_MISC2_TOG_PLL3_DISABLE(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_PLL3_DISABLE_SHIFT)) & CCM_ANALOG_MISC2_TOG_PLL3_DISABLE_MASK)

#define CCM_ANALOG_MISC2_TOG_REG1_BO_OFFSET_MASK (0x700U)
#define CCM_ANALOG_MISC2_TOG_REG1_BO_OFFSET_SHIFT (8U)
/*! REG1_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_TOG_REG1_BO_OFFSET(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG1_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG1_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_TOG_REG1_BO_STATUS_MASK (0x800U)
#define CCM_ANALOG_MISC2_TOG_REG1_BO_STATUS_SHIFT (11U)
/*! REG1_BO_STATUS
 *  0b1..Brownout, supply is below target minus brownout offset.
 */
#define CCM_ANALOG_MISC2_TOG_REG1_BO_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG1_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG1_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_TOG_REG1_ENABLE_BO_MASK (0x2000U)
#define CCM_ANALOG_MISC2_TOG_REG1_ENABLE_BO_SHIFT (13U)
#define CCM_ANALOG_MISC2_TOG_REG1_ENABLE_BO(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG1_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG1_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_TOG_REG1_OK_MASK        (0x4000U)
#define CCM_ANALOG_MISC2_TOG_REG1_OK_SHIFT       (14U)
#define CCM_ANALOG_MISC2_TOG_REG1_OK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG1_OK_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG1_OK_MASK)

#define CCM_ANALOG_MISC2_TOG_AUDIO_DIV_LSB_MASK  (0x8000U)
#define CCM_ANALOG_MISC2_TOG_AUDIO_DIV_LSB_SHIFT (15U)
/*! AUDIO_DIV_LSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define CCM_ANALOG_MISC2_TOG_AUDIO_DIV_LSB(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_AUDIO_DIV_LSB_SHIFT)) & CCM_ANALOG_MISC2_TOG_AUDIO_DIV_LSB_MASK)

#define CCM_ANALOG_MISC2_TOG_REG2_BO_OFFSET_MASK (0x70000U)
#define CCM_ANALOG_MISC2_TOG_REG2_BO_OFFSET_SHIFT (16U)
/*! REG2_BO_OFFSET
 *  0b100..Brownout offset = 0.100V
 *  0b111..Brownout offset = 0.175V
 */
#define CCM_ANALOG_MISC2_TOG_REG2_BO_OFFSET(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG2_BO_OFFSET_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG2_BO_OFFSET_MASK)

#define CCM_ANALOG_MISC2_TOG_REG2_BO_STATUS_MASK (0x80000U)
#define CCM_ANALOG_MISC2_TOG_REG2_BO_STATUS_SHIFT (19U)
#define CCM_ANALOG_MISC2_TOG_REG2_BO_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG2_BO_STATUS_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG2_BO_STATUS_MASK)

#define CCM_ANALOG_MISC2_TOG_REG2_ENABLE_BO_MASK (0x200000U)
#define CCM_ANALOG_MISC2_TOG_REG2_ENABLE_BO_SHIFT (21U)
#define CCM_ANALOG_MISC2_TOG_REG2_ENABLE_BO(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG2_ENABLE_BO_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG2_ENABLE_BO_MASK)

#define CCM_ANALOG_MISC2_TOG_REG2_OK_MASK        (0x400000U)
#define CCM_ANALOG_MISC2_TOG_REG2_OK_SHIFT       (22U)
#define CCM_ANALOG_MISC2_TOG_REG2_OK(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG2_OK_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG2_OK_MASK)

#define CCM_ANALOG_MISC2_TOG_AUDIO_DIV_MSB_MASK  (0x800000U)
#define CCM_ANALOG_MISC2_TOG_AUDIO_DIV_MSB_SHIFT (23U)
/*! AUDIO_DIV_MSB
 *  0b0..divide by 1 (Default)
 *  0b1..divide by 2
 */
#define CCM_ANALOG_MISC2_TOG_AUDIO_DIV_MSB(x)    (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_AUDIO_DIV_MSB_SHIFT)) & CCM_ANALOG_MISC2_TOG_AUDIO_DIV_MSB_MASK)

#define CCM_ANALOG_MISC2_TOG_REG0_STEP_TIME_MASK (0x3000000U)
#define CCM_ANALOG_MISC2_TOG_REG0_STEP_TIME_SHIFT (24U)
/*! REG0_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_TOG_REG0_STEP_TIME(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG0_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG0_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_TOG_REG1_STEP_TIME_MASK (0xC000000U)
#define CCM_ANALOG_MISC2_TOG_REG1_STEP_TIME_SHIFT (26U)
/*! REG1_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_TOG_REG1_STEP_TIME(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG1_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG1_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_TOG_REG2_STEP_TIME_MASK (0x30000000U)
#define CCM_ANALOG_MISC2_TOG_REG2_STEP_TIME_SHIFT (28U)
/*! REG2_STEP_TIME
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..512
 */
#define CCM_ANALOG_MISC2_TOG_REG2_STEP_TIME(x)   (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_REG2_STEP_TIME_SHIFT)) & CCM_ANALOG_MISC2_TOG_REG2_STEP_TIME_MASK)

#define CCM_ANALOG_MISC2_TOG_VIDEO_DIV_MASK      (0xC0000000U)
#define CCM_ANALOG_MISC2_TOG_VIDEO_DIV_SHIFT     (30U)
/*! VIDEO_DIV
 *  0b00..divide by 1 (Default)
 *  0b01..divide by 2
 *  0b10..divide by 1
 *  0b11..divide by 4
 */
#define CCM_ANALOG_MISC2_TOG_VIDEO_DIV(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ANALOG_MISC2_TOG_VIDEO_DIV_SHIFT)) & CCM_ANALOG_MISC2_TOG_VIDEO_DIV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CCM_ANALOG_Register_Masks */


/*!
 * @}
 */ /* end of group CCM_ANALOG_Peripheral_Access_Layer */


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


#endif  /* PERI_CCM_ANALOG_H_ */

