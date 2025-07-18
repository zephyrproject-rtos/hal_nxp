/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SLEEPCON1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SLEEPCON1.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SLEEPCON1
 *
 * CMSIS Peripheral Access Layer for SLEEPCON1
 */

#if !defined(PERI_SLEEPCON1_H_)
#define PERI_SLEEPCON1_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- SLEEPCON1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SLEEPCON1_Peripheral_Access_Layer SLEEPCON1 Peripheral Access Layer
 * @{
 */

/** SLEEPCON1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t SLEEPCFG;                          /**< Sleep Configuration, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t RUNCFG;                            /**< Run Configuration, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __O  uint32_t RUNCFG_SET;                        /**< RUNCFG Set, offset: 0x20 */
       uint8_t RESERVED_2[12];
  __O  uint32_t RUNCFG_CLR;                        /**< RUNCFG Clear, offset: 0x30 */
       uint8_t RESERVED_3[44];
  __IO uint32_t WAKEUPEN0;                         /**< Wakeup Enable 0, offset: 0x60 */
  __IO uint32_t WAKEUPEN1;                         /**< Wakeup Enable 1, offset: 0x64 */
  __IO uint32_t WAKEUPEN2;                         /**< Wakeup Enable 2, offset: 0x68 */
       uint8_t RESERVED_4[52];
  __O  uint32_t WAKEUPEN0_SET;                     /**< Wakeup Enable 0 Set, offset: 0xA0 */
  __O  uint32_t WAKEUPEN1_SET;                     /**< Wakeup Enable 1 Set, offset: 0xA4 */
  __O  uint32_t WAKEUPEN2_SET;                     /**< Wakeup Enable 2 Set, offset: 0xA8 */
       uint8_t RESERVED_5[84];
  __O  uint32_t WAKEUPEN0_CLR;                     /**< Wakeup Enable 0 Clear, offset: 0x100 */
  __O  uint32_t WAKEUPEN1_CLR;                     /**< Wakeup Enable 1 Clear, offset: 0x104 */
  __O  uint32_t WAKEUPEN2_CLR;                     /**< Wakeup Enable 2 Clear, offset: 0x108 */
       uint8_t RESERVED_6[80];
  __IO uint32_t LPOSC_DELAY;                       /**< LPOSC Delay, offset: 0x15C */
       uint8_t RESERVED_7[4];
  __IO uint32_t PWRDOWN_WAIT;                      /**< Power Down Wait, offset: 0x164 */
       uint8_t RESERVED_8[40];
  __IO uint32_t HW_WAKE;                           /**< eDMA Wakeup Enable, offset: 0x190 */
  __O  uint32_t HW_WAKE_SET;                       /**< eDMA Wakeup Set, offset: 0x194 */
  __O  uint32_t HW_WAKE_CLR;                       /**< eDMA Wakeup Clear, offset: 0x198 */
       uint8_t RESERVED_9[4];
  __IO uint32_t SHARED_MASK0;                      /**< Shared Resources Mask, offset: 0x1A0 */
  __O  uint32_t SHARED_MASK0_SET;                  /**< Shared Resources Mask Set, offset: 0x1A4 */
  __O  uint32_t SHARED_MASK0_CLR;                  /**< Shared Resources Mask Clear, offset: 0x1A8 */
       uint8_t RESERVED_10[4];
  __IO uint32_t SHA_MED_CCTRL0;                    /**< Media Domain Shared Controller Low-power Control, offset: 0x1B0 */
  __IO uint32_t SHA_MED_TCTRL0;                    /**< Media Domain Shared Resources Target Low-power Control, offset: 0x1B4 */
       uint8_t RESERVED_11[4];
  __IO uint32_t SHA_SEN_TCTRL0;                    /**< Shared VDD1_SENSE Domain Targets Low-power Control, offset: 0x1BC */
  __IO uint32_t PRIVATE_CCTRL0;                    /**< Private Resources Controllers Low-power Control 0, offset: 0x1C0 */
  __IO uint32_t PRIVATE_TCTRL0;                    /**< Private Resources Target Low-power Control, offset: 0x1C4 */
       uint8_t RESERVED_12[8];
  __I  uint32_t SHA_MED_CSTAT0;                    /**< Media Domain Shared Controllers Low-power Status, offset: 0x1D0 */
  __I  uint32_t SHA_MEDSEN_TSTAT0;                 /**< Media and Sense Domain Shared Targets Low-power Status, offset: 0x1D4 */
       uint8_t RESERVED_13[8];
  __I  uint32_t PRIVATE_CSTAT0;                    /**< Private Resources Controllers Low-power Status, offset: 0x1E0 */
  __I  uint32_t PRIVATE_TSTAT0;                    /**< Private Resources Targets Low-power Status 0, offset: 0x1E4 */
       uint8_t RESERVED_14[4];
  __I  uint32_t LP_HINT0;                          /**< Low-Power Hint Status 0, offset: 0x1EC */
       uint8_t RESERVED_15[4];
  __I  uint32_t LP_DENY0;                          /**< Low-Power Deny Status 0, offset: 0x1F4 */
} SLEEPCON1_Type;

/* ----------------------------------------------------------------------------
   -- SLEEPCON1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SLEEPCON1_Register_Masks SLEEPCON1 Register Masks
 * @{
 */

/*! @name SLEEPCFG - Sleep Configuration */
/*! @{ */

#define SLEEPCON1_SLEEPCFG_SENSEP_MAINCLK_SHUTOFF_MASK (0x2U)
#define SLEEPCON1_SLEEPCFG_SENSEP_MAINCLK_SHUTOFF_SHIFT (1U)
/*! SENSEP_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_SLEEPCFG_SENSEP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_SENSEP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_SLEEPCFG_SENSEP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_SLEEPCFG_SENSES_MAINCLK_SHUTOFF_MASK (0x4U)
#define SLEEPCON1_SLEEPCFG_SENSES_MAINCLK_SHUTOFF_SHIFT (2U)
/*! SENSES_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk_1 Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_SLEEPCFG_SENSES_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_SENSES_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_SLEEPCFG_SENSES_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_SLEEPCFG_RAM0_CLK_SHUTOFF_MASK (0x8U)
#define SLEEPCON1_SLEEPCFG_RAM0_CLK_SHUTOFF_SHIFT (3U)
/*! RAM0_CLK_SHUTOFF - RAM_ARBITER0 common_ram_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_SLEEPCFG_RAM0_CLK_SHUTOFF(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_RAM0_CLK_SHUTOFF_SHIFT)) & SLEEPCON1_SLEEPCFG_RAM0_CLK_SHUTOFF_MASK)

#define SLEEPCON1_SLEEPCFG_RAM1_CLK_SHUTOFF_MASK (0x10U)
#define SLEEPCON1_SLEEPCFG_RAM1_CLK_SHUTOFF_SHIFT (4U)
/*! RAM1_CLK_SHUTOFF - RAM_ARBITER1 sense_ram_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_SLEEPCFG_RAM1_CLK_SHUTOFF(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_RAM1_CLK_SHUTOFF_SHIFT)) & SLEEPCON1_SLEEPCFG_RAM1_CLK_SHUTOFF_MASK)

#define SLEEPCON1_SLEEPCFG_COMN_MAINCLK_SHUTOFF_MASK (0x20U)
#define SLEEPCON1_SLEEPCFG_COMN_MAINCLK_SHUTOFF_SHIFT (5U)
/*! COMN_MAINCLK_SHUTOFF - VDDN_COM Domain common_vddn_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_SLEEPCFG_COMN_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_COMN_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_SLEEPCFG_COMN_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_SLEEPCFG_MEDIA_MAINCLK_SHUTOFF_MASK (0x40U)
#define SLEEPCON1_SLEEPCFG_MEDIA_MAINCLK_SHUTOFF_SHIFT (6U)
/*! MEDIA_MAINCLK_SHUTOFF - VDD2_MEDIA and VDDN_MEDIA Domains media_main_clk and media_vddn_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_SLEEPCFG_MEDIA_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_MEDIA_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_SLEEPCFG_MEDIA_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_SLEEPCFG_XTAL_PD_MASK          (0x80U)
#define SLEEPCON1_SLEEPCFG_XTAL_PD_SHIFT         (7U)
/*! XTAL_PD - Xtal Oscillator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_SLEEPCFG_XTAL_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_XTAL_PD_SHIFT)) & SLEEPCON1_SLEEPCFG_XTAL_PD_MASK)

#define SLEEPCON1_SLEEPCFG_FRO2_PD_MASK          (0x400U)
#define SLEEPCON1_SLEEPCFG_FRO2_PD_SHIFT         (10U)
/*! FRO2_PD - FRO2 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_SLEEPCFG_FRO2_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_FRO2_PD_SHIFT)) & SLEEPCON1_SLEEPCFG_FRO2_PD_MASK)

#define SLEEPCON1_SLEEPCFG_LPOSC_PD_MASK         (0x800U)
#define SLEEPCON1_SLEEPCFG_LPOSC_PD_SHIFT        (11U)
/*! LPOSC_PD - LPOSC Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_SLEEPCFG_LPOSC_PD(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_LPOSC_PD_SHIFT)) & SLEEPCON1_SLEEPCFG_LPOSC_PD_MASK)

#define SLEEPCON1_SLEEPCFG_PLLANA_PD_MASK        (0x1000U)
#define SLEEPCON1_SLEEPCFG_PLLANA_PD_SHIFT       (12U)
/*! PLLANA_PD - Main PLL Analog Function Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_SLEEPCFG_PLLANA_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_PLLANA_PD_SHIFT)) & SLEEPCON1_SLEEPCFG_PLLANA_PD_MASK)

#define SLEEPCON1_SLEEPCFG_PLLLDO_PD_MASK        (0x2000U)
#define SLEEPCON1_SLEEPCFG_PLLLDO_PD_SHIFT       (13U)
/*! PLLLDO_PD - Main PLL internal regulator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_SLEEPCFG_PLLLDO_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_PLLLDO_PD_SHIFT)) & SLEEPCON1_SLEEPCFG_PLLLDO_PD_MASK)

#define SLEEPCON1_SLEEPCFG_AUDPLLANA_PD_MASK     (0x4000U)
#define SLEEPCON1_SLEEPCFG_AUDPLLANA_PD_SHIFT    (14U)
/*! AUDPLLANA_PD - Audio PLL Analog Function Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_SLEEPCFG_AUDPLLANA_PD(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_AUDPLLANA_PD_SHIFT)) & SLEEPCON1_SLEEPCFG_AUDPLLANA_PD_MASK)

#define SLEEPCON1_SLEEPCFG_AUDPLLLDO_PD_MASK     (0x8000U)
#define SLEEPCON1_SLEEPCFG_AUDPLLLDO_PD_SHIFT    (15U)
/*! AUDPLLLDO_PD - Audio PLL internal regulator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_SLEEPCFG_AUDPLLLDO_PD(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_AUDPLLLDO_PD_SHIFT)) & SLEEPCON1_SLEEPCFG_AUDPLLLDO_PD_MASK)

#define SLEEPCON1_SLEEPCFG_ADC0_PD_MASK          (0x10000U)
#define SLEEPCON1_SLEEPCFG_ADC0_PD_SHIFT         (16U)
/*! ADC0_PD - ADC0 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_SLEEPCFG_ADC0_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_ADC0_PD_SHIFT)) & SLEEPCON1_SLEEPCFG_ADC0_PD_MASK)

#define SLEEPCON1_SLEEPCFG_FRO2_GATE_MASK        (0x80000000U)
#define SLEEPCON1_SLEEPCFG_FRO2_GATE_SHIFT       (31U)
/*! FRO2_GATE - FRO2 Gating
 *  0b0..Removes gating
 *  0b1..Applies gating
 */
#define SLEEPCON1_SLEEPCFG_FRO2_GATE(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SLEEPCFG_FRO2_GATE_SHIFT)) & SLEEPCON1_SLEEPCFG_FRO2_GATE_MASK)
/*! @} */

/*! @name RUNCFG - Run Configuration */
/*! @{ */

#define SLEEPCON1_RUNCFG_SENSEP_MAINCLK_SHUTOFF_MASK (0x2U)
#define SLEEPCON1_RUNCFG_SENSEP_MAINCLK_SHUTOFF_SHIFT (1U)
/*! SENSEP_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_RUNCFG_SENSEP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SENSEP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_SENSEP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_SENSES_MAINCLK_SHUTOFF_MASK (0x4U)
#define SLEEPCON1_RUNCFG_SENSES_MAINCLK_SHUTOFF_SHIFT (2U)
/*! SENSES_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk_1 Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_RUNCFG_SENSES_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SENSES_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_SENSES_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_RAM0_CLK_SHUTOFF_MASK   (0x8U)
#define SLEEPCON1_RUNCFG_RAM0_CLK_SHUTOFF_SHIFT  (3U)
/*! RAM0_CLK_SHUTOFF - RAM_ARBITER0 common_ram_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_RUNCFG_RAM0_CLK_SHUTOFF(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_RAM0_CLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_RAM0_CLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_RAM1_CLK_SHUTOFF_MASK   (0x10U)
#define SLEEPCON1_RUNCFG_RAM1_CLK_SHUTOFF_SHIFT  (4U)
/*! RAM1_CLK_SHUTOFF - RAM_ARBITER1 sense_ram_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_RUNCFG_RAM1_CLK_SHUTOFF(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_RAM1_CLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_RAM1_CLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_COMN_MAINCLK_SHUTOFF_MASK (0x20U)
#define SLEEPCON1_RUNCFG_COMN_MAINCLK_SHUTOFF_SHIFT (5U)
/*! COMN_MAINCLK_SHUTOFF - VDDN_COM Domain common_vddn_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_RUNCFG_COMN_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_COMN_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_COMN_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_MEDIA_MAINCLK_SHUTOFF_MASK (0x40U)
#define SLEEPCON1_RUNCFG_MEDIA_MAINCLK_SHUTOFF_SHIFT (6U)
/*! MEDIA_MAINCLK_SHUTOFF - VDD2_MEDIA and VDDN_MEDIA Domains media_main_clk and media_vddn_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON1_RUNCFG_MEDIA_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_MEDIA_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_MEDIA_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_XTAL_PD_MASK            (0x80U)
#define SLEEPCON1_RUNCFG_XTAL_PD_SHIFT           (7U)
/*! XTAL_PD - Xtal Oscillator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_RUNCFG_XTAL_PD(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_XTAL_PD_SHIFT)) & SLEEPCON1_RUNCFG_XTAL_PD_MASK)

#define SLEEPCON1_RUNCFG_FRO2_PD_MASK            (0x400U)
#define SLEEPCON1_RUNCFG_FRO2_PD_SHIFT           (10U)
/*! FRO2_PD - FRO2 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_RUNCFG_FRO2_PD(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_FRO2_PD_SHIFT)) & SLEEPCON1_RUNCFG_FRO2_PD_MASK)

#define SLEEPCON1_RUNCFG_LPOSC_PD_MASK           (0x800U)
#define SLEEPCON1_RUNCFG_LPOSC_PD_SHIFT          (11U)
/*! LPOSC_PD - LPOSC Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_RUNCFG_LPOSC_PD(x)             (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_LPOSC_PD_SHIFT)) & SLEEPCON1_RUNCFG_LPOSC_PD_MASK)

#define SLEEPCON1_RUNCFG_PLLANA_PD_MASK          (0x1000U)
#define SLEEPCON1_RUNCFG_PLLANA_PD_SHIFT         (12U)
/*! PLLANA_PD - Main PLL Analog Function Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_RUNCFG_PLLANA_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_PLLANA_PD_SHIFT)) & SLEEPCON1_RUNCFG_PLLANA_PD_MASK)

#define SLEEPCON1_RUNCFG_PLLLDO_PD_MASK          (0x2000U)
#define SLEEPCON1_RUNCFG_PLLLDO_PD_SHIFT         (13U)
/*! PLLLDO_PD - Main PLL Internal Regulator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_RUNCFG_PLLLDO_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_PLLLDO_PD_SHIFT)) & SLEEPCON1_RUNCFG_PLLLDO_PD_MASK)

#define SLEEPCON1_RUNCFG_AUDPLLANA_PD_MASK       (0x4000U)
#define SLEEPCON1_RUNCFG_AUDPLLANA_PD_SHIFT      (14U)
/*! AUDPLLANA_PD - Audio PLL Analog Function Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_RUNCFG_AUDPLLANA_PD(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_AUDPLLANA_PD_SHIFT)) & SLEEPCON1_RUNCFG_AUDPLLANA_PD_MASK)

#define SLEEPCON1_RUNCFG_AUDPLLLDO_PD_MASK       (0x8000U)
#define SLEEPCON1_RUNCFG_AUDPLLLDO_PD_SHIFT      (15U)
/*! AUDPLLLDO_PD - Audio PLL Internal Regulator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_RUNCFG_AUDPLLLDO_PD(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_AUDPLLLDO_PD_SHIFT)) & SLEEPCON1_RUNCFG_AUDPLLLDO_PD_MASK)

#define SLEEPCON1_RUNCFG_ADC0_PD_MASK            (0x10000U)
#define SLEEPCON1_RUNCFG_ADC0_PD_SHIFT           (16U)
/*! ADC0_PD - ADC0 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON1_RUNCFG_ADC0_PD(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_ADC0_PD_SHIFT)) & SLEEPCON1_RUNCFG_ADC0_PD_MASK)

#define SLEEPCON1_RUNCFG_FRO2_GATE_MASK          (0x80000000U)
#define SLEEPCON1_RUNCFG_FRO2_GATE_SHIFT         (31U)
/*! FRO2_GATE - FRO2 Gating
 *  0b0..Removes gating
 *  0b1..Applies gating
 */
#define SLEEPCON1_RUNCFG_FRO2_GATE(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_FRO2_GATE_SHIFT)) & SLEEPCON1_RUNCFG_FRO2_GATE_MASK)
/*! @} */

/*! @name RUNCFG_SET - RUNCFG Set */
/*! @{ */

#define SLEEPCON1_RUNCFG_SET_SENSEP_MAINCLK_SHUTOFF_MASK (0x2U)
#define SLEEPCON1_RUNCFG_SET_SENSEP_MAINCLK_SHUTOFF_SHIFT (1U)
/*! SENSEP_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_SENSEP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_SENSEP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_SET_SENSEP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_SET_SENSES_MAINCLK_SHUTOFF_MASK (0x4U)
#define SLEEPCON1_RUNCFG_SET_SENSES_MAINCLK_SHUTOFF_SHIFT (2U)
/*! SENSES_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk_1 Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_SENSES_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_SENSES_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_SET_SENSES_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_SET_RAM0_CLK_SHUTOFF_MASK (0x8U)
#define SLEEPCON1_RUNCFG_SET_RAM0_CLK_SHUTOFF_SHIFT (3U)
/*! RAM0_CLK_SHUTOFF - RAM_ARBITER0 common_ram_clk Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_RAM0_CLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_RAM0_CLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_SET_RAM0_CLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_SET_RAM1_CLK_SHUTOFF_MASK (0x10U)
#define SLEEPCON1_RUNCFG_SET_RAM1_CLK_SHUTOFF_SHIFT (4U)
/*! RAM1_CLK_SHUTOFF - RAM_ARBITER1 sense_ram_clk Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_RAM1_CLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_RAM1_CLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_SET_RAM1_CLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_SET_COMN_MAINCLK_SHUTOFF_MASK (0x20U)
#define SLEEPCON1_RUNCFG_SET_COMN_MAINCLK_SHUTOFF_SHIFT (5U)
/*! COMN_MAINCLK_SHUTOFF - VDDN_COM Domain common_vddn_clk Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_COMN_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_COMN_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_SET_COMN_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_SET_MEDIA_MAINCLK_SHUTOFF_MASK (0x40U)
#define SLEEPCON1_RUNCFG_SET_MEDIA_MAINCLK_SHUTOFF_SHIFT (6U)
/*! MEDIA_MAINCLK_SHUTOFF - VDD2_MEDIA and VDDN_MEDIA Domains media_main_clk and media_vddn_clk Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_MEDIA_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_MEDIA_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_SET_MEDIA_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_SET_XTAL_PD_MASK        (0x80U)
#define SLEEPCON1_RUNCFG_SET_XTAL_PD_SHIFT       (7U)
/*! XTAL_PD - Xtal Oscillator Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_XTAL_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_XTAL_PD_SHIFT)) & SLEEPCON1_RUNCFG_SET_XTAL_PD_MASK)

#define SLEEPCON1_RUNCFG_SET_FRO2_PD_MASK        (0x400U)
#define SLEEPCON1_RUNCFG_SET_FRO2_PD_SHIFT       (10U)
/*! FRO2_PD - FRO2 Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_FRO2_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_FRO2_PD_SHIFT)) & SLEEPCON1_RUNCFG_SET_FRO2_PD_MASK)

#define SLEEPCON1_RUNCFG_SET_LPOSC_PD_MASK       (0x800U)
#define SLEEPCON1_RUNCFG_SET_LPOSC_PD_SHIFT      (11U)
/*! LPOSC_PD - LPOSC Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_LPOSC_PD(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_LPOSC_PD_SHIFT)) & SLEEPCON1_RUNCFG_SET_LPOSC_PD_MASK)

#define SLEEPCON1_RUNCFG_SET_PLLANA_PD_MASK      (0x1000U)
#define SLEEPCON1_RUNCFG_SET_PLLANA_PD_SHIFT     (12U)
/*! PLLANA_PD - Main PLL Analog Function Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_PLLANA_PD(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_PLLANA_PD_SHIFT)) & SLEEPCON1_RUNCFG_SET_PLLANA_PD_MASK)

#define SLEEPCON1_RUNCFG_SET_PLLLDO_PD_MASK      (0x2000U)
#define SLEEPCON1_RUNCFG_SET_PLLLDO_PD_SHIFT     (13U)
/*! PLLLDO_PD - Main PLL Internal Regulator Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_PLLLDO_PD(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_PLLLDO_PD_SHIFT)) & SLEEPCON1_RUNCFG_SET_PLLLDO_PD_MASK)

#define SLEEPCON1_RUNCFG_SET_AUDPLLANA_PD_MASK   (0x4000U)
#define SLEEPCON1_RUNCFG_SET_AUDPLLANA_PD_SHIFT  (14U)
/*! AUDPLLANA_PD - Audio PLL Analog Function Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_AUDPLLANA_PD(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_AUDPLLANA_PD_SHIFT)) & SLEEPCON1_RUNCFG_SET_AUDPLLANA_PD_MASK)

#define SLEEPCON1_RUNCFG_SET_AUDPLLLDO_PD_MASK   (0x8000U)
#define SLEEPCON1_RUNCFG_SET_AUDPLLLDO_PD_SHIFT  (15U)
/*! AUDPLLLDO_PD - Audio PLL Internal Regulator Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_AUDPLLLDO_PD(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_AUDPLLLDO_PD_SHIFT)) & SLEEPCON1_RUNCFG_SET_AUDPLLLDO_PD_MASK)

#define SLEEPCON1_RUNCFG_SET_ADC0_PD_MASK        (0x10000U)
#define SLEEPCON1_RUNCFG_SET_ADC0_PD_SHIFT       (16U)
/*! ADC0_PD - ADC0 Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_ADC0_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_ADC0_PD_SHIFT)) & SLEEPCON1_RUNCFG_SET_ADC0_PD_MASK)

#define SLEEPCON1_RUNCFG_SET_FRO2_GATE_MASK      (0x80000000U)
#define SLEEPCON1_RUNCFG_SET_FRO2_GATE_SHIFT     (31U)
/*! FRO2_GATE - FRO2 Gating Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_RUNCFG_SET_FRO2_GATE(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_SET_FRO2_GATE_SHIFT)) & SLEEPCON1_RUNCFG_SET_FRO2_GATE_MASK)
/*! @} */

/*! @name RUNCFG_CLR - RUNCFG Clear */
/*! @{ */

#define SLEEPCON1_RUNCFG_CLR_SENSEP_MAINCLK_SHUTOFF_MASK (0x2U)
#define SLEEPCON1_RUNCFG_CLR_SENSEP_MAINCLK_SHUTOFF_SHIFT (1U)
/*! SENSEP_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_SENSEP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_SENSEP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_CLR_SENSEP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_CLR_SENSES_MAINCLK_SHUTOFF_MASK (0x4U)
#define SLEEPCON1_RUNCFG_CLR_SENSES_MAINCLK_SHUTOFF_SHIFT (2U)
/*! SENSES_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk_1 Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_SENSES_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_SENSES_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_CLR_SENSES_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_CLR_RAM0_CLK_SHUTOFF_MASK (0x8U)
#define SLEEPCON1_RUNCFG_CLR_RAM0_CLK_SHUTOFF_SHIFT (3U)
/*! RAM0_CLK_SHUTOFF - RAM_ARBITER0 common_ram_clk Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_RAM0_CLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_RAM0_CLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_CLR_RAM0_CLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_CLR_RAM1_CLK_SHUTOFF_MASK (0x10U)
#define SLEEPCON1_RUNCFG_CLR_RAM1_CLK_SHUTOFF_SHIFT (4U)
/*! RAM1_CLK_SHUTOFF - RAM_ARBITER1 sense_ram_clk Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_RAM1_CLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_RAM1_CLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_CLR_RAM1_CLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_CLR_COMN_MAINCLK_SHUTOFF_MASK (0x20U)
#define SLEEPCON1_RUNCFG_CLR_COMN_MAINCLK_SHUTOFF_SHIFT (5U)
/*! COMN_MAINCLK_SHUTOFF - VDDN_COM Domain common_vddn_clk Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_COMN_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_COMN_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_CLR_COMN_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_CLR_MEDIA_MAINCLK_SHUTOFF_MASK (0x40U)
#define SLEEPCON1_RUNCFG_CLR_MEDIA_MAINCLK_SHUTOFF_SHIFT (6U)
/*! MEDIA_MAINCLK_SHUTOFF - VDD2_MEDIA and VDDN_MEDIA Domains media_main_clk and media_vddn_clk Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_MEDIA_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_MEDIA_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON1_RUNCFG_CLR_MEDIA_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON1_RUNCFG_CLR_XTAL_PD_MASK        (0x80U)
#define SLEEPCON1_RUNCFG_CLR_XTAL_PD_SHIFT       (7U)
/*! XTAL_PD - Xtal Oscillator Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_XTAL_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_XTAL_PD_SHIFT)) & SLEEPCON1_RUNCFG_CLR_XTAL_PD_MASK)

#define SLEEPCON1_RUNCFG_CLR_FRO2_PD_MASK        (0x400U)
#define SLEEPCON1_RUNCFG_CLR_FRO2_PD_SHIFT       (10U)
/*! FRO2_PD - FRO2 Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_FRO2_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_FRO2_PD_SHIFT)) & SLEEPCON1_RUNCFG_CLR_FRO2_PD_MASK)

#define SLEEPCON1_RUNCFG_CLR_LPOSC_PD_MASK       (0x800U)
#define SLEEPCON1_RUNCFG_CLR_LPOSC_PD_SHIFT      (11U)
/*! LPOSC_PD - LPOSC Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_LPOSC_PD(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_LPOSC_PD_SHIFT)) & SLEEPCON1_RUNCFG_CLR_LPOSC_PD_MASK)

#define SLEEPCON1_RUNCFG_CLR_PLLANA_PD_MASK      (0x1000U)
#define SLEEPCON1_RUNCFG_CLR_PLLANA_PD_SHIFT     (12U)
/*! PLLANA_PD - Main PLL Analog Function Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_PLLANA_PD(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_PLLANA_PD_SHIFT)) & SLEEPCON1_RUNCFG_CLR_PLLANA_PD_MASK)

#define SLEEPCON1_RUNCFG_CLR_PLLLDO_PD_MASK      (0x2000U)
#define SLEEPCON1_RUNCFG_CLR_PLLLDO_PD_SHIFT     (13U)
/*! PLLLDO_PD - Main PLL Internal Regulator Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_PLLLDO_PD(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_PLLLDO_PD_SHIFT)) & SLEEPCON1_RUNCFG_CLR_PLLLDO_PD_MASK)

#define SLEEPCON1_RUNCFG_CLR_AUDPLLANA_PD_MASK   (0x4000U)
#define SLEEPCON1_RUNCFG_CLR_AUDPLLANA_PD_SHIFT  (14U)
/*! AUDPLLANA_PD - Audio PLL Analog Function Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_AUDPLLANA_PD(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_AUDPLLANA_PD_SHIFT)) & SLEEPCON1_RUNCFG_CLR_AUDPLLANA_PD_MASK)

#define SLEEPCON1_RUNCFG_CLR_AUDPLLLDO_PD_MASK   (0x8000U)
#define SLEEPCON1_RUNCFG_CLR_AUDPLLLDO_PD_SHIFT  (15U)
/*! AUDPLLLDO_PD - Audio PLL Internal Regulator Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_AUDPLLLDO_PD(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_AUDPLLLDO_PD_SHIFT)) & SLEEPCON1_RUNCFG_CLR_AUDPLLLDO_PD_MASK)

#define SLEEPCON1_RUNCFG_CLR_ADC0_PD_MASK        (0x10000U)
#define SLEEPCON1_RUNCFG_CLR_ADC0_PD_SHIFT       (16U)
/*! ADC0_PD - ADC0 Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_ADC0_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_ADC0_PD_SHIFT)) & SLEEPCON1_RUNCFG_CLR_ADC0_PD_MASK)

#define SLEEPCON1_RUNCFG_CLR_FRO2_GATE_MASK      (0x80000000U)
#define SLEEPCON1_RUNCFG_CLR_FRO2_GATE_SHIFT     (31U)
/*! FRO2_GATE - FRO2 Gating Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_RUNCFG_CLR_FRO2_GATE(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_RUNCFG_CLR_FRO2_GATE_SHIFT)) & SLEEPCON1_RUNCFG_CLR_FRO2_GATE_MASK)
/*! @} */

/*! @name WAKEUPEN0 - Wakeup Enable 0 */
/*! @{ */

#define SLEEPCON1_WAKEUPEN0_FRO0_MASK            (0x2U)
#define SLEEPCON1_WAKEUPEN0_FRO0_SHIFT           (1U)
/*! FRO0 - FRO0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_FRO0(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_FRO0_SHIFT)) & SLEEPCON1_WAKEUPEN0_FRO0_MASK)

#define SLEEPCON1_WAKEUPEN0_FRO1_MASK            (0x4U)
#define SLEEPCON1_WAKEUPEN0_FRO1_SHIFT           (2U)
/*! FRO1 - FRO1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_FRO1(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_FRO1_SHIFT)) & SLEEPCON1_WAKEUPEN0_FRO1_MASK)

#define SLEEPCON1_WAKEUPEN0_FRO2_MASK            (0x8U)
#define SLEEPCON1_WAKEUPEN0_FRO2_SHIFT           (3U)
/*! FRO2 - FRO2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_FRO2(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_FRO2_SHIFT)) & SLEEPCON1_WAKEUPEN0_FRO2_MASK)

#define SLEEPCON1_WAKEUPEN0_UTICK1_MASK          (0x20U)
#define SLEEPCON1_WAKEUPEN0_UTICK1_SHIFT         (5U)
/*! UTICK1 - UTICK1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_UTICK1(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_UTICK1_SHIFT)) & SLEEPCON1_WAKEUPEN0_UTICK1_MASK)

#define SLEEPCON1_WAKEUPEN0_CTIMER5_MASK         (0x80U)
#define SLEEPCON1_WAKEUPEN0_CTIMER5_SHIFT        (7U)
/*! CTIMER5 - CTIMER5 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_CTIMER5(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CTIMER5_SHIFT)) & SLEEPCON1_WAKEUPEN0_CTIMER5_MASK)

#define SLEEPCON1_WAKEUPEN0_CTIMER6_MASK         (0x100U)
#define SLEEPCON1_WAKEUPEN0_CTIMER6_SHIFT        (8U)
/*! CTIMER6 - CTIMER6 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_CTIMER6(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CTIMER6_SHIFT)) & SLEEPCON1_WAKEUPEN0_CTIMER6_MASK)

#define SLEEPCON1_WAKEUPEN0_CTIMER7_MASK         (0x200U)
#define SLEEPCON1_WAKEUPEN0_CTIMER7_SHIFT        (9U)
/*! CTIMER7 - CTIMER7 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_CTIMER7(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CTIMER7_SHIFT)) & SLEEPCON1_WAKEUPEN0_CTIMER7_MASK)

#define SLEEPCON1_WAKEUPEN0_LPI2C15_MASK         (0x400U)
#define SLEEPCON1_WAKEUPEN0_LPI2C15_SHIFT        (10U)
/*! LPI2C15 - LPI2C15 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_LPI2C15(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_LPI2C15_SHIFT)) & SLEEPCON1_WAKEUPEN0_LPI2C15_MASK)

#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM17_MASK   (0x800U)
#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM17_SHIFT  (11U)
/*! LP_FLEXCOMM17 - LP_FLEXCOMM17 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM17(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM17_SHIFT)) & SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM17_MASK)

#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM18_MASK   (0x1000U)
#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM18_SHIFT  (12U)
/*! LP_FLEXCOMM18 - LP_FLEXCOMM18 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM18(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM18_SHIFT)) & SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM18_MASK)

#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM19_MASK   (0x2000U)
#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM19_SHIFT  (13U)
/*! LP_FLEXCOMM19 - LP_FLEXCOMM19 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM19(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM19_SHIFT)) & SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM19_MASK)

#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM20_MASK   (0x4000U)
#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM20_SHIFT  (14U)
/*! LP_FLEXCOMM20 - LP_FLEXCOMM20 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM20(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM20_SHIFT)) & SLEEPCON1_WAKEUPEN0_LP_FLEXCOMM20_MASK)

#define SLEEPCON1_WAKEUPEN0_ADC0_MASK            (0x8000U)
#define SLEEPCON1_WAKEUPEN0_ADC0_SHIFT           (15U)
/*! ADC0 - ADC0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_ADC0(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_ADC0_SHIFT)) & SLEEPCON1_WAKEUPEN0_ADC0_MASK)

#define SLEEPCON1_WAKEUPEN0_ACMP0_MASK           (0x40000U)
#define SLEEPCON1_WAKEUPEN0_ACMP0_SHIFT          (18U)
/*! ACMP0 - ACMP0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_ACMP0(x)             (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_ACMP0_SHIFT)) & SLEEPCON1_WAKEUPEN0_ACMP0_MASK)

#define SLEEPCON1_WAKEUPEN0_MICFIL_RD_ERR_MASK   (0x80000U)
#define SLEEPCON1_WAKEUPEN0_MICFIL_RD_ERR_SHIFT  (19U)
/*! MICFIL_RD_ERR - MICFIL Read Data Error Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_MICFIL_RD_ERR(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_MICFIL_RD_ERR_SHIFT)) & SLEEPCON1_WAKEUPEN0_MICFIL_RD_ERR_MASK)

#define SLEEPCON1_WAKEUPEN0_MICFIL_WKUP_MASK     (0x400000U)
#define SLEEPCON1_WAKEUPEN0_MICFIL_WKUP_SHIFT    (22U)
/*! MICFIL_WKUP - MICFIL Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_MICFIL_WKUP(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_MICFIL_WKUP_SHIFT)) & SLEEPCON1_WAKEUPEN0_MICFIL_WKUP_MASK)

#define SLEEPCON1_WAKEUPEN0_RTC1_ALARM_MASK      (0x800000U)
#define SLEEPCON1_WAKEUPEN0_RTC1_ALARM_SHIFT     (23U)
/*! RTC1_ALARM - RTC1_ALARM Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_RTC1_ALARM(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_RTC1_ALARM_SHIFT)) & SLEEPCON1_WAKEUPEN0_RTC1_ALARM_MASK)

#define SLEEPCON1_WAKEUPEN0_RTC1_WKUP_MASK       (0x1000000U)
#define SLEEPCON1_WAKEUPEN0_RTC1_WKUP_SHIFT      (24U)
/*! RTC1_WKUP - RTC1_WKUP Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_RTC1_WKUP(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_RTC1_WKUP_SHIFT)) & SLEEPCON1_WAKEUPEN0_RTC1_WKUP_MASK)

#define SLEEPCON1_WAKEUPEN0_MU1_MUB_MASK         (0x4000000U)
#define SLEEPCON1_WAKEUPEN0_MU1_MUB_SHIFT        (26U)
/*! MU1_MUB - MU1_MUB Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_MU1_MUB(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_MU1_MUB_SHIFT)) & SLEEPCON1_WAKEUPEN0_MU1_MUB_MASK)

#define SLEEPCON1_WAKEUPEN0_MU2_MUB_MASK         (0x8000000U)
#define SLEEPCON1_WAKEUPEN0_MU2_MUB_SHIFT        (27U)
/*! MU2_MUB - MU2_MUB Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_MU2_MUB(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_MU2_MUB_SHIFT)) & SLEEPCON1_WAKEUPEN0_MU2_MUB_MASK)

#define SLEEPCON1_WAKEUPEN0_MU3_MUA_MASK         (0x10000000U)
#define SLEEPCON1_WAKEUPEN0_MU3_MUA_SHIFT        (28U)
/*! MU3_MUA - MU3_MUA Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_MU3_MUA(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_MU3_MUA_SHIFT)) & SLEEPCON1_WAKEUPEN0_MU3_MUA_MASK)

#define SLEEPCON1_WAKEUPEN0_PMC1_MASK            (0x20000000U)
#define SLEEPCON1_WAKEUPEN0_PMC1_SHIFT           (29U)
/*! PMC1 - PMC1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_PMC1(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_PMC1_SHIFT)) & SLEEPCON1_WAKEUPEN0_PMC1_MASK)

#define SLEEPCON1_WAKEUPEN0_OSTIMER_MASK         (0x40000000U)
#define SLEEPCON1_WAKEUPEN0_OSTIMER_SHIFT        (30U)
/*! OSTIMER - OSTIMER Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN0_OSTIMER(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_OSTIMER_SHIFT)) & SLEEPCON1_WAKEUPEN0_OSTIMER_MASK)
/*! @} */

/*! @name WAKEUPEN1 - Wakeup Enable 1 */
/*! @{ */

#define SLEEPCON1_WAKEUPEN1_I3C2_MASK            (0x2U)
#define SLEEPCON1_WAKEUPEN1_I3C2_SHIFT           (1U)
/*! I3C2 - I3C2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_I3C2(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_I3C2_SHIFT)) & SLEEPCON1_WAKEUPEN1_I3C2_MASK)

#define SLEEPCON1_WAKEUPEN1_USB0_MASK            (0x4U)
#define SLEEPCON1_WAKEUPEN1_USB0_SHIFT           (2U)
/*! USB0 - USB0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_USB0(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_USB0_SHIFT)) & SLEEPCON1_WAKEUPEN1_USB0_MASK)

#define SLEEPCON1_WAKEUPEN1_USB1_MASK            (0x8U)
#define SLEEPCON1_WAKEUPEN1_USB1_SHIFT           (3U)
/*! USB1 - USB1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_USB1(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_USB1_SHIFT)) & SLEEPCON1_WAKEUPEN1_USB1_MASK)

#define SLEEPCON1_WAKEUPEN1_WWDT2_MASK           (0x10U)
#define SLEEPCON1_WAKEUPEN1_WWDT2_SHIFT          (4U)
/*! WWDT2 - WWDT2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_WWDT2(x)             (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_WWDT2_SHIFT)) & SLEEPCON1_WAKEUPEN1_WWDT2_MASK)

#define SLEEPCON1_WAKEUPEN1_WWDT3_MASK           (0x20U)
#define SLEEPCON1_WAKEUPEN1_WWDT3_SHIFT          (5U)
/*! WWDT3 - WWDT3 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_WWDT3(x)             (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_WWDT3_SHIFT)) & SLEEPCON1_WAKEUPEN1_WWDT3_MASK)

#define SLEEPCON1_WAKEUPEN1_USBPHY0_MASK         (0x40U)
#define SLEEPCON1_WAKEUPEN1_USBPHY0_SHIFT        (6U)
/*! USBPHY0 - USBPHY0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_USBPHY0(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_USBPHY0_SHIFT)) & SLEEPCON1_WAKEUPEN1_USBPHY0_MASK)

#define SLEEPCON1_WAKEUPEN1_PMIC_IRQN_MASK       (0x80U)
#define SLEEPCON1_WAKEUPEN1_PMIC_IRQN_SHIFT      (7U)
/*! PMIC_IRQN - PMIC_IRQN Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_PMIC_IRQN(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_PMIC_IRQN_SHIFT)) & SLEEPCON1_WAKEUPEN1_PMIC_IRQN_MASK)

#define SLEEPCON1_WAKEUPEN1_I3C3_MASK            (0x100U)
#define SLEEPCON1_WAKEUPEN1_I3C3_SHIFT           (8U)
/*! I3C3 - I3C3 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_I3C3(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_I3C3_SHIFT)) & SLEEPCON1_WAKEUPEN1_I3C3_MASK)

#define SLEEPCON1_WAKEUPEN1_FLEXIO_MASK          (0x200U)
#define SLEEPCON1_WAKEUPEN1_FLEXIO_SHIFT         (9U)
/*! FLEXIO - FLEXIO Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_FLEXIO(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_FLEXIO_SHIFT)) & SLEEPCON1_WAKEUPEN1_FLEXIO_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA2_CH0_MASK       (0x2000U)
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH0_SHIFT      (13U)
/*! EDMA2_CH0 - eDMA2 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA2_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA2_CH0_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA2_CH1_MASK       (0x4000U)
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH1_SHIFT      (14U)
/*! EDMA2_CH1 - eDMA2 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA2_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA2_CH1_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA2_CH2_MASK       (0x8000U)
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH2_SHIFT      (15U)
/*! EDMA2_CH2 - eDMA2 Channel 2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH2(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA2_CH2_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA2_CH2_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA2_CH3_MASK       (0x10000U)
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH3_SHIFT      (16U)
/*! EDMA2_CH3 - eDMA2 Channel 3 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH3(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA2_CH3_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA2_CH3_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA2_CH4_MASK       (0x20000U)
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH4_SHIFT      (17U)
/*! EDMA2_CH4 - eDMA2 Channel 4 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH4(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA2_CH4_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA2_CH4_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA2_CH5_MASK       (0x40000U)
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH5_SHIFT      (18U)
/*! EDMA2_CH5 - eDMA2 Channel 5 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH5(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA2_CH5_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA2_CH5_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA2_CH6_MASK       (0x80000U)
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH6_SHIFT      (19U)
/*! EDMA2_CH6 - eDMA2 Channel 6 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH6(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA2_CH6_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA2_CH6_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA2_CH7_MASK       (0x100000U)
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH7_SHIFT      (20U)
/*! EDMA2_CH7 - eDMA2 Channel 7 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA2_CH7(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA2_CH7_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA2_CH7_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA3_CH0_MASK       (0x200000U)
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH0_SHIFT      (21U)
/*! EDMA3_CH0 - eDMA3 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA3_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA3_CH0_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA3_CH1_MASK       (0x400000U)
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH1_SHIFT      (22U)
/*! EDMA3_CH1 - eDMA3 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA3_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA3_CH1_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA3_CH2_MASK       (0x800000U)
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH2_SHIFT      (23U)
/*! EDMA3_CH2 - eDMA3 Channel 2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH2(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA3_CH2_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA3_CH2_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA3_CH3_MASK       (0x1000000U)
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH3_SHIFT      (24U)
/*! EDMA3_CH3 - eDMA3 Channel 3 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH3(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA3_CH3_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA3_CH3_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA3_CH4_MASK       (0x2000000U)
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH4_SHIFT      (25U)
/*! EDMA3_CH4 - eDMA3 Channel 4 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH4(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA3_CH4_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA3_CH4_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA3_CH5_MASK       (0x4000000U)
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH5_SHIFT      (26U)
/*! EDMA3_CH5 - eDMA3 Channel 5 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH5(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA3_CH5_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA3_CH5_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA3_CH6_MASK       (0x8000000U)
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH6_SHIFT      (27U)
/*! EDMA3_CH6 - eDMA3 Channel 6 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH6(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA3_CH6_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA3_CH6_MASK)

#define SLEEPCON1_WAKEUPEN1_EDMA3_CH7_MASK       (0x10000000U)
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH7_SHIFT      (28U)
/*! EDMA3_CH7 - eDMA3 Channel 7 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_EDMA3_CH7(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_EDMA3_CH7_SHIFT)) & SLEEPCON1_WAKEUPEN1_EDMA3_CH7_MASK)

#define SLEEPCON1_WAKEUPEN1_GPIO8_CH0_MASK       (0x20000000U)
#define SLEEPCON1_WAKEUPEN1_GPIO8_CH0_SHIFT      (29U)
/*! GPIO8_CH0 - GPIO8 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_GPIO8_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_GPIO8_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_GPIO8_CH0_MASK)

#define SLEEPCON1_WAKEUPEN1_GPIO8_CH1_MASK       (0x40000000U)
#define SLEEPCON1_WAKEUPEN1_GPIO8_CH1_SHIFT      (30U)
/*! GPIO8_CH1 - GPIO8 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_GPIO8_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_GPIO8_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN1_GPIO8_CH1_MASK)

#define SLEEPCON1_WAKEUPEN1_GPIO9_CH0_MASK       (0x80000000U)
#define SLEEPCON1_WAKEUPEN1_GPIO9_CH0_SHIFT      (31U)
/*! GPIO9_CH0 - GPIO9 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN1_GPIO9_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_GPIO9_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_GPIO9_CH0_MASK)
/*! @} */

/*! @name WAKEUPEN2 - Wakeup Enable 2 */
/*! @{ */

#define SLEEPCON1_WAKEUPEN2_GPIO9_CH1_MASK       (0x1U)
#define SLEEPCON1_WAKEUPEN2_GPIO9_CH1_SHIFT      (0U)
/*! GPIO9_CH1 - GPIO9 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN2_GPIO9_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_GPIO9_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN2_GPIO9_CH1_MASK)

#define SLEEPCON1_WAKEUPEN2_GPIO10_CH0_MASK      (0x2U)
#define SLEEPCON1_WAKEUPEN2_GPIO10_CH0_SHIFT     (1U)
/*! GPIO10_CH0 - GPIO10 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN2_GPIO10_CH0(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_GPIO10_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN2_GPIO10_CH0_MASK)

#define SLEEPCON1_WAKEUPEN2_GPIO10_CH1_MASK      (0x4U)
#define SLEEPCON1_WAKEUPEN2_GPIO10_CH1_SHIFT     (2U)
/*! GPIO10_CH1 - GPIO10 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN2_GPIO10_CH1(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_GPIO10_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN2_GPIO10_CH1_MASK)

#define SLEEPCON1_WAKEUPEN2_PINT1_INTR0_MASK     (0x20U)
#define SLEEPCON1_WAKEUPEN2_PINT1_INTR0_SHIFT    (5U)
/*! PINT1_INTR0 - PINT1_INTR0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN2_PINT1_INTR0(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_PINT1_INTR0_SHIFT)) & SLEEPCON1_WAKEUPEN2_PINT1_INTR0_MASK)

#define SLEEPCON1_WAKEUPEN2_PINT1_INTR1_MASK     (0x40U)
#define SLEEPCON1_WAKEUPEN2_PINT1_INTR1_SHIFT    (6U)
/*! PINT1_INTR1 - PINT1_INTR1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN2_PINT1_INTR1(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_PINT1_INTR1_SHIFT)) & SLEEPCON1_WAKEUPEN2_PINT1_INTR1_MASK)

#define SLEEPCON1_WAKEUPEN2_PINT1_INTR2_MASK     (0x80U)
#define SLEEPCON1_WAKEUPEN2_PINT1_INTR2_SHIFT    (7U)
/*! PINT1_INTR2 - PINT1_INTR2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN2_PINT1_INTR2(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_PINT1_INTR2_SHIFT)) & SLEEPCON1_WAKEUPEN2_PINT1_INTR2_MASK)

#define SLEEPCON1_WAKEUPEN2_PINT1_INTR3_MASK     (0x100U)
#define SLEEPCON1_WAKEUPEN2_PINT1_INTR3_SHIFT    (8U)
/*! PINT1_INTR3 - PINT1_INTR3 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN2_PINT1_INTR3(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_PINT1_INTR3_SHIFT)) & SLEEPCON1_WAKEUPEN2_PINT1_INTR3_MASK)

#define SLEEPCON1_WAKEUPEN2_SAI3_MASK            (0x200U)
#define SLEEPCON1_WAKEUPEN2_SAI3_SHIFT           (9U)
/*! SAI3 - SAI3 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_WAKEUPEN2_SAI3(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_SAI3_SHIFT)) & SLEEPCON1_WAKEUPEN2_SAI3_MASK)
/*! @} */

/*! @name WAKEUPEN0_SET - Wakeup Enable 0 Set */
/*! @{ */

#define SLEEPCON1_WAKEUPEN0_SET_FRO0_MASK        (0x2U)
#define SLEEPCON1_WAKEUPEN0_SET_FRO0_SHIFT       (1U)
/*! FRO0 - FRO0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_FRO0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_FRO0_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_FRO0_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_FRO1_MASK        (0x4U)
#define SLEEPCON1_WAKEUPEN0_SET_FRO1_SHIFT       (2U)
/*! FRO1 - FRO1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_FRO1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_FRO1_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_FRO1_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_FRO2_MASK        (0x8U)
#define SLEEPCON1_WAKEUPEN0_SET_FRO2_SHIFT       (3U)
/*! FRO2 - FRO2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_FRO2(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_FRO2_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_FRO2_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_UTICK1_MASK      (0x20U)
#define SLEEPCON1_WAKEUPEN0_SET_UTICK1_SHIFT     (5U)
/*! UTICK1 - UTICK1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_UTICK1(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_UTICK1_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_UTICK1_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_CTIMER5_MASK     (0x80U)
#define SLEEPCON1_WAKEUPEN0_SET_CTIMER5_SHIFT    (7U)
/*! CTIMER5 - CTIMER5 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_CTIMER5(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_CTIMER5_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_CTIMER5_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_CTIMER6_MASK     (0x100U)
#define SLEEPCON1_WAKEUPEN0_SET_CTIMER6_SHIFT    (8U)
/*! CTIMER6 - CTIMER6 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_CTIMER6(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_CTIMER6_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_CTIMER6_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_CTIMER7_MASK     (0x200U)
#define SLEEPCON1_WAKEUPEN0_SET_CTIMER7_SHIFT    (9U)
/*! CTIMER7 - CTIMER7 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_CTIMER7(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_CTIMER7_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_CTIMER7_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_LPI2C15_MASK     (0x400U)
#define SLEEPCON1_WAKEUPEN0_SET_LPI2C15_SHIFT    (10U)
/*! LPI2C15 - LPI2C15 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_LPI2C15(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_LPI2C15_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_LPI2C15_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM17_MASK (0x800U)
#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM17_SHIFT (11U)
/*! LP_FLEXCOMM17 - LP_FLEXCOMM17 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM17(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM17_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM17_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM18_MASK (0x1000U)
#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM18_SHIFT (12U)
/*! LP_FLEXCOMM18 - LP_FLEXCOMM18 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM18(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM18_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM18_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM19_MASK (0x2000U)
#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM19_SHIFT (13U)
/*! LP_FLEXCOMM19 - LP_FLEXCOMM19 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM19(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM19_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM19_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM20_MASK (0x4000U)
#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM20_SHIFT (14U)
/*! LP_FLEXCOMM20 - LP_FLEXCOMM20 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM20(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM20_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_LP_FLEXCOMM20_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_ADC0_MASK        (0x8000U)
#define SLEEPCON1_WAKEUPEN0_SET_ADC0_SHIFT       (15U)
/*! ADC0 - ADC0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_ADC0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_ADC0_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_ADC0_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_ACMP0_MASK       (0x40000U)
#define SLEEPCON1_WAKEUPEN0_SET_ACMP0_SHIFT      (18U)
/*! ACMP0 - ACMP0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_ACMP0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_ACMP0_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_ACMP0_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_MICFIL_RD_ERR_MASK (0x80000U)
#define SLEEPCON1_WAKEUPEN0_SET_MICFIL_RD_ERR_SHIFT (19U)
/*! MICFIL_RD_ERR - MICFIL Read Data Error Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_MICFIL_RD_ERR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_MICFIL_RD_ERR_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_MICFIL_RD_ERR_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_MICFIL_WKUP_MASK (0x400000U)
#define SLEEPCON1_WAKEUPEN0_SET_MICFIL_WKUP_SHIFT (22U)
/*! MICFIL_WKUP - MICFIL Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_MICFIL_WKUP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_MICFIL_WKUP_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_MICFIL_WKUP_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_RTC1_ALARM_MASK  (0x800000U)
#define SLEEPCON1_WAKEUPEN0_SET_RTC1_ALARM_SHIFT (23U)
/*! RTC1_ALARM - RTC1_ALARM Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_RTC1_ALARM(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_RTC1_ALARM_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_RTC1_ALARM_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_RTC1_WKUP_MASK   (0x1000000U)
#define SLEEPCON1_WAKEUPEN0_SET_RTC1_WKUP_SHIFT  (24U)
/*! RTC1_WKUP - RTC1_WKUP Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_RTC1_WKUP(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_RTC1_WKUP_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_RTC1_WKUP_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_MU1_MUB_MASK     (0x4000000U)
#define SLEEPCON1_WAKEUPEN0_SET_MU1_MUB_SHIFT    (26U)
/*! MU1_MUB - MU1_MUB Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_MU1_MUB(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_MU1_MUB_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_MU1_MUB_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_MU2_MUB_MASK     (0x8000000U)
#define SLEEPCON1_WAKEUPEN0_SET_MU2_MUB_SHIFT    (27U)
/*! MU2_MUB - MU2_MUB Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_MU2_MUB(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_MU2_MUB_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_MU2_MUB_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_MU3_MUA_MASK     (0x10000000U)
#define SLEEPCON1_WAKEUPEN0_SET_MU3_MUA_SHIFT    (28U)
/*! MU3_MUA - MU3_MUA Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_MU3_MUA(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_MU3_MUA_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_MU3_MUA_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_PMC1_MASK        (0x20000000U)
#define SLEEPCON1_WAKEUPEN0_SET_PMC1_SHIFT       (29U)
/*! PMC1 - PMC1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_PMC1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_PMC1_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_PMC1_MASK)

#define SLEEPCON1_WAKEUPEN0_SET_OSTIMER_MASK     (0x40000000U)
#define SLEEPCON1_WAKEUPEN0_SET_OSTIMER_SHIFT    (30U)
/*! OSTIMER - OSTIMER Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN0_SET_OSTIMER(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_SET_OSTIMER_SHIFT)) & SLEEPCON1_WAKEUPEN0_SET_OSTIMER_MASK)
/*! @} */

/*! @name WAKEUPEN1_SET - Wakeup Enable 1 Set */
/*! @{ */

#define SLEEPCON1_WAKEUPEN1_SET_I3C2_MASK        (0x2U)
#define SLEEPCON1_WAKEUPEN1_SET_I3C2_SHIFT       (1U)
/*! I3C2 - I3C2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_I3C2(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_I3C2_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_I3C2_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_USB0_MASK        (0x4U)
#define SLEEPCON1_WAKEUPEN1_SET_USB0_SHIFT       (2U)
/*! USB0 - USB0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_USB0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_USB0_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_USB0_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_USB1_MASK        (0x8U)
#define SLEEPCON1_WAKEUPEN1_SET_USB1_SHIFT       (3U)
/*! USB1 - USB1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_USB1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_USB1_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_USB1_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_WWDT2_MASK       (0x10U)
#define SLEEPCON1_WAKEUPEN1_SET_WWDT2_SHIFT      (4U)
/*! WWDT2 - WWDT2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_WWDT2(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_WWDT2_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_WWDT2_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_WWDT3_MASK       (0x20U)
#define SLEEPCON1_WAKEUPEN1_SET_WWDT3_SHIFT      (5U)
/*! WWDT3 - WWDT3 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_WWDT3(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_WWDT3_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_WWDT3_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_USBPHY0_MASK     (0x40U)
#define SLEEPCON1_WAKEUPEN1_SET_USBPHY0_SHIFT    (6U)
/*! USBPHY0 - USBPHY0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_USBPHY0(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_USBPHY0_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_USBPHY0_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_PMIC_IRQN_MASK   (0x80U)
#define SLEEPCON1_WAKEUPEN1_SET_PMIC_IRQN_SHIFT  (7U)
/*! PMIC_IRQN - PMIC_IRQN Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_PMIC_IRQN(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_PMIC_IRQN_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_PMIC_IRQN_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_I3C3_MASK        (0x100U)
#define SLEEPCON1_WAKEUPEN1_SET_I3C3_SHIFT       (8U)
/*! I3C3 - I3C3 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_I3C3(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_I3C3_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_I3C3_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_FLEXIO_MASK      (0x200U)
#define SLEEPCON1_WAKEUPEN1_SET_FLEXIO_SHIFT     (9U)
/*! FLEXIO - FLEXIO Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_FLEXIO(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_FLEXIO_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_FLEXIO_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH0_MASK   (0x2000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH0_SHIFT  (13U)
/*! EDMA2_CH0 - eDMA2 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH0_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH1_MASK   (0x4000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH1_SHIFT  (14U)
/*! EDMA2_CH1 - eDMA2 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH1_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH2_MASK   (0x8000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH2_SHIFT  (15U)
/*! EDMA2_CH2 - eDMA2 Channel 2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH2(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH2_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH2_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH3_MASK   (0x10000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH3_SHIFT  (16U)
/*! EDMA2_CH3 - eDMA2 Channel 3 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH3(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH3_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH3_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH4_MASK   (0x20000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH4_SHIFT  (17U)
/*! EDMA2_CH4 - eDMA2 Channel 4 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH4(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH4_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH4_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH5_MASK   (0x40000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH5_SHIFT  (18U)
/*! EDMA2_CH5 - eDMA2 Channel 5 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH5(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH5_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH5_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH6_MASK   (0x80000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH6_SHIFT  (19U)
/*! EDMA2_CH6 - eDMA2 Channel 6 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH6(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH6_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH6_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH7_MASK   (0x100000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH7_SHIFT  (20U)
/*! EDMA2_CH7 - eDMA2 Channel 7 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH7(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH7_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA2_CH7_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH0_MASK   (0x200000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH0_SHIFT  (21U)
/*! EDMA3_CH0 - eDMA3 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH0_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH1_MASK   (0x400000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH1_SHIFT  (22U)
/*! EDMA3_CH1 - eDMA3 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH1_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH2_MASK   (0x800000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH2_SHIFT  (23U)
/*! EDMA3_CH2 - eDMA3 Channel 2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH2(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH2_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH2_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH3_MASK   (0x1000000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH3_SHIFT  (24U)
/*! EDMA3_CH3 - eDMA3 Channel 3 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH3(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH3_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH3_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH4_MASK   (0x2000000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH4_SHIFT  (25U)
/*! EDMA3_CH4 - eDMA3 Channel 4 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH4(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH4_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH4_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH5_MASK   (0x4000000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH5_SHIFT  (26U)
/*! EDMA3_CH5 - eDMA3 Channel 5 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH5(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH5_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH5_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH6_MASK   (0x8000000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH6_SHIFT  (27U)
/*! EDMA3_CH6 - eDMA3 Channel 6 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH6(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH6_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH6_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH7_MASK   (0x10000000U)
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH7_SHIFT  (28U)
/*! EDMA3_CH7 - eDMA3 Channel 7 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH7(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH7_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_EDMA3_CH7_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_GPIO8_CH0_MASK   (0x20000000U)
#define SLEEPCON1_WAKEUPEN1_SET_GPIO8_CH0_SHIFT  (29U)
/*! GPIO8_CH0 - GPIO8 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_GPIO8_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_GPIO8_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_GPIO8_CH0_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_GPIO8_CH1_MASK   (0x40000000U)
#define SLEEPCON1_WAKEUPEN1_SET_GPIO8_CH1_SHIFT  (30U)
/*! GPIO8_CH1 - GPIO8 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_GPIO8_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_GPIO8_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_GPIO8_CH1_MASK)

#define SLEEPCON1_WAKEUPEN1_SET_GPIO9_CH0_MASK   (0x80000000U)
#define SLEEPCON1_WAKEUPEN1_SET_GPIO9_CH0_SHIFT  (31U)
/*! GPIO9_CH0 - GPIO9 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN1_SET_GPIO9_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_SET_GPIO9_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_SET_GPIO9_CH0_MASK)
/*! @} */

/*! @name WAKEUPEN2_SET - Wakeup Enable 2 Set */
/*! @{ */

#define SLEEPCON1_WAKEUPEN2_SET_GPIO9_CH1_MASK   (0x1U)
#define SLEEPCON1_WAKEUPEN2_SET_GPIO9_CH1_SHIFT  (0U)
/*! GPIO9_CH1 - GPIO9 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN2_SET_GPIO9_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_SET_GPIO9_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN2_SET_GPIO9_CH1_MASK)

#define SLEEPCON1_WAKEUPEN2_SET_GPIO10_CH0_MASK  (0x2U)
#define SLEEPCON1_WAKEUPEN2_SET_GPIO10_CH0_SHIFT (1U)
/*! GPIO10_CH0 - GPIO10 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN2_SET_GPIO10_CH0(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_SET_GPIO10_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN2_SET_GPIO10_CH0_MASK)

#define SLEEPCON1_WAKEUPEN2_SET_GPIO10_CH1_MASK  (0x4U)
#define SLEEPCON1_WAKEUPEN2_SET_GPIO10_CH1_SHIFT (2U)
/*! GPIO10_CH1 - GPIO10 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN2_SET_GPIO10_CH1(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_SET_GPIO10_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN2_SET_GPIO10_CH1_MASK)

#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR0_MASK (0x20U)
#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR0_SHIFT (5U)
/*! PINT1_INTR0 - PINT1_INTR0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR0(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR0_SHIFT)) & SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR0_MASK)

#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR1_MASK (0x40U)
#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR1_SHIFT (6U)
/*! PINT1_INTR1 - PINT1_INTR1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR1(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR1_SHIFT)) & SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR1_MASK)

#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR2_MASK (0x80U)
#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR2_SHIFT (7U)
/*! PINT1_INTR2 - PINT1_INTR2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR2(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR2_SHIFT)) & SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR2_MASK)

#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR3_MASK (0x100U)
#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR3_SHIFT (8U)
/*! PINT1_INTR3 - PINT1_INTR3 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR3(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR3_SHIFT)) & SLEEPCON1_WAKEUPEN2_SET_PINT1_INTR3_MASK)

#define SLEEPCON1_WAKEUPEN2_SET_SAI3_MASK        (0x200U)
#define SLEEPCON1_WAKEUPEN2_SET_SAI3_SHIFT       (9U)
/*! SAI3 - SAI3 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_WAKEUPEN2_SET_SAI3(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_SET_SAI3_SHIFT)) & SLEEPCON1_WAKEUPEN2_SET_SAI3_MASK)
/*! @} */

/*! @name WAKEUPEN0_CLR - Wakeup Enable 0 Clear */
/*! @{ */

#define SLEEPCON1_WAKEUPEN0_CLR_FRO0_MASK        (0x2U)
#define SLEEPCON1_WAKEUPEN0_CLR_FRO0_SHIFT       (1U)
/*! FRO0 - FRO0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_FRO0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_FRO0_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_FRO0_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_FRO1_MASK        (0x4U)
#define SLEEPCON1_WAKEUPEN0_CLR_FRO1_SHIFT       (2U)
/*! FRO1 - FRO1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_FRO1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_FRO1_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_FRO1_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_FRO2_MASK        (0x8U)
#define SLEEPCON1_WAKEUPEN0_CLR_FRO2_SHIFT       (3U)
/*! FRO2 - FRO2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_FRO2(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_FRO2_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_FRO2_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_UTICK1_MASK      (0x20U)
#define SLEEPCON1_WAKEUPEN0_CLR_UTICK1_SHIFT     (5U)
/*! UTICK1 - UTICK1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_UTICK1(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_UTICK1_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_UTICK1_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_CTIMER5_MASK     (0x80U)
#define SLEEPCON1_WAKEUPEN0_CLR_CTIMER5_SHIFT    (7U)
/*! CTIMER5 - CTIMER5 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_CTIMER5(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_CTIMER5_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_CTIMER5_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_CTIMER6_MASK     (0x100U)
#define SLEEPCON1_WAKEUPEN0_CLR_CTIMER6_SHIFT    (8U)
/*! CTIMER6 - CTIMER6 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_CTIMER6(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_CTIMER6_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_CTIMER6_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_CTIMER7_MASK     (0x200U)
#define SLEEPCON1_WAKEUPEN0_CLR_CTIMER7_SHIFT    (9U)
/*! CTIMER7 - CTIMER7 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_CTIMER7(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_CTIMER7_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_CTIMER7_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_LPI2C15_MASK     (0x400U)
#define SLEEPCON1_WAKEUPEN0_CLR_LPI2C15_SHIFT    (10U)
/*! LPI2C15 - LPI2C15 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_LPI2C15(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_LPI2C15_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_LPI2C15_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM17_MASK (0x800U)
#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM17_SHIFT (11U)
/*! LP_FLEXCOMM17 - LP_FLEXCOMM17 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM17(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM17_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM17_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM18_MASK (0x1000U)
#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM18_SHIFT (12U)
/*! LP_FLEXCOMM18 - LP_FLEXCOMM18 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM18(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM18_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM18_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM19_MASK (0x2000U)
#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM19_SHIFT (13U)
/*! LP_FLEXCOMM19 - LP_FLEXCOMM19 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM19(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM19_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM19_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM20_MASK (0x4000U)
#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM20_SHIFT (14U)
/*! LP_FLEXCOMM20 - LP_FLEXCOMM20 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM20(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM20_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_LP_FLEXCOMM20_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_ADC0_MASK        (0x8000U)
#define SLEEPCON1_WAKEUPEN0_CLR_ADC0_SHIFT       (15U)
/*! ADC0 - ADC0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_ADC0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_ADC0_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_ADC0_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_ACMP0_MASK       (0x40000U)
#define SLEEPCON1_WAKEUPEN0_CLR_ACMP0_SHIFT      (18U)
/*! ACMP0 - ACMP0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_ACMP0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_ACMP0_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_ACMP0_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_MICFIL_RD_ERR_MASK (0x80000U)
#define SLEEPCON1_WAKEUPEN0_CLR_MICFIL_RD_ERR_SHIFT (19U)
/*! MICFIL_RD_ERR - MICFIL Read Data Error Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_MICFIL_RD_ERR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_MICFIL_RD_ERR_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_MICFIL_RD_ERR_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_MICFIL_WKUP_MASK (0x400000U)
#define SLEEPCON1_WAKEUPEN0_CLR_MICFIL_WKUP_SHIFT (22U)
/*! MICFIL_WKUP - MICFIL Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_MICFIL_WKUP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_MICFIL_WKUP_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_MICFIL_WKUP_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_RTC1_ALARM_MASK  (0x800000U)
#define SLEEPCON1_WAKEUPEN0_CLR_RTC1_ALARM_SHIFT (23U)
/*! RTC1_ALARM - RTC1_ALARM Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_RTC1_ALARM(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_RTC1_ALARM_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_RTC1_ALARM_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_RTC1_WKUP_MASK   (0x1000000U)
#define SLEEPCON1_WAKEUPEN0_CLR_RTC1_WKUP_SHIFT  (24U)
/*! RTC1_WKUP - RTC1_WKUP Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_RTC1_WKUP(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_RTC1_WKUP_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_RTC1_WKUP_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_MU1_MUB_MASK     (0x4000000U)
#define SLEEPCON1_WAKEUPEN0_CLR_MU1_MUB_SHIFT    (26U)
/*! MU1_MUB - MU1_MUB Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_MU1_MUB(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_MU1_MUB_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_MU1_MUB_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_MU2_MUB_MASK     (0x8000000U)
#define SLEEPCON1_WAKEUPEN0_CLR_MU2_MUB_SHIFT    (27U)
/*! MU2_MUB - MU2_MUB Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_MU2_MUB(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_MU2_MUB_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_MU2_MUB_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_MU3_MUA_MASK     (0x10000000U)
#define SLEEPCON1_WAKEUPEN0_CLR_MU3_MUA_SHIFT    (28U)
/*! MU3_MUA - MU3_MUA Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_MU3_MUA(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_MU3_MUA_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_MU3_MUA_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_PMC1_MASK        (0x20000000U)
#define SLEEPCON1_WAKEUPEN0_CLR_PMC1_SHIFT       (29U)
/*! PMC1 - PMC1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_PMC1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_PMC1_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_PMC1_MASK)

#define SLEEPCON1_WAKEUPEN0_CLR_OSTIMER_MASK     (0x40000000U)
#define SLEEPCON1_WAKEUPEN0_CLR_OSTIMER_SHIFT    (30U)
/*! OSTIMER - OSTIMER Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN0_CLR_OSTIMER(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN0_CLR_OSTIMER_SHIFT)) & SLEEPCON1_WAKEUPEN0_CLR_OSTIMER_MASK)
/*! @} */

/*! @name WAKEUPEN1_CLR - Wakeup Enable 1 Clear */
/*! @{ */

#define SLEEPCON1_WAKEUPEN1_CLR_I3C2_MASK        (0x2U)
#define SLEEPCON1_WAKEUPEN1_CLR_I3C2_SHIFT       (1U)
/*! I3C2 - I3C2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_I3C2(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_I3C2_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_I3C2_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_USB0_MASK        (0x4U)
#define SLEEPCON1_WAKEUPEN1_CLR_USB0_SHIFT       (2U)
/*! USB0 - USB0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_USB0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_USB0_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_USB0_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_USB1_MASK        (0x8U)
#define SLEEPCON1_WAKEUPEN1_CLR_USB1_SHIFT       (3U)
/*! USB1 - USB1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_USB1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_USB1_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_USB1_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_WWDT2_MASK       (0x10U)
#define SLEEPCON1_WAKEUPEN1_CLR_WWDT2_SHIFT      (4U)
/*! WWDT2 - WWDT2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_WWDT2(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_WWDT2_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_WWDT2_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_WWDT3_MASK       (0x20U)
#define SLEEPCON1_WAKEUPEN1_CLR_WWDT3_SHIFT      (5U)
/*! WWDT3 - WWDT3 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_WWDT3(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_WWDT3_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_WWDT3_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_USBPHY0_MASK     (0x40U)
#define SLEEPCON1_WAKEUPEN1_CLR_USBPHY0_SHIFT    (6U)
/*! USBPHY0 - USBPHY0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_USBPHY0(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_USBPHY0_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_USBPHY0_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_PMIC_IRQN_MASK   (0x80U)
#define SLEEPCON1_WAKEUPEN1_CLR_PMIC_IRQN_SHIFT  (7U)
/*! PMIC_IRQN - PMIC_IRQN Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_PMIC_IRQN(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_PMIC_IRQN_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_PMIC_IRQN_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_I3C3_MASK        (0x100U)
#define SLEEPCON1_WAKEUPEN1_CLR_I3C3_SHIFT       (8U)
/*! I3C3 - I3C3 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_I3C3(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_I3C3_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_I3C3_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_FLEXIO_MASK      (0x200U)
#define SLEEPCON1_WAKEUPEN1_CLR_FLEXIO_SHIFT     (9U)
/*! FLEXIO - FLEXIO Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_FLEXIO(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_FLEXIO_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_FLEXIO_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH0_MASK   (0x2000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH0_SHIFT  (13U)
/*! EDMA2_CH0 - eDMA2 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH0_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH1_MASK   (0x4000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH1_SHIFT  (14U)
/*! EDMA2_CH1 - eDMA2 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH1_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH2_MASK   (0x8000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH2_SHIFT  (15U)
/*! EDMA2_CH2 - eDMA2 Channel 2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH2(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH2_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH2_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH3_MASK   (0x10000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH3_SHIFT  (16U)
/*! EDMA2_CH3 - eDMA2 Channel 3 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH3(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH3_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH3_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH4_MASK   (0x20000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH4_SHIFT  (17U)
/*! EDMA2_CH4 - eDMA2 Channel 4 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH4(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH4_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH4_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH5_MASK   (0x40000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH5_SHIFT  (18U)
/*! EDMA2_CH5 - eDMA2 Channel 5 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH5(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH5_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH5_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH6_MASK   (0x80000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH6_SHIFT  (19U)
/*! EDMA2_CH6 - eDMA2 Channel 6 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH6(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH6_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH6_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH7_MASK   (0x100000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH7_SHIFT  (20U)
/*! EDMA2_CH7 - eDMA2 Channel 7 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH7(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH7_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA2_CH7_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH0_MASK   (0x200000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH0_SHIFT  (21U)
/*! EDMA3_CH0 - eDMA3 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH0_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH1_MASK   (0x400000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH1_SHIFT  (22U)
/*! EDMA3_CH1 - eDMA3 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH1_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH2_MASK   (0x800000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH2_SHIFT  (23U)
/*! EDMA3_CH2 - eDMA3 Channel 2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH2(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH2_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH2_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH3_MASK   (0x1000000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH3_SHIFT  (24U)
/*! EDMA3_CH3 - eDMA3 Channel 3 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH3(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH3_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH3_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH4_MASK   (0x2000000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH4_SHIFT  (25U)
/*! EDMA3_CH4 - eDMA3 Channel 4 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH4(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH4_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH4_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH5_MASK   (0x4000000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH5_SHIFT  (26U)
/*! EDMA3_CH5 - eDMA3 Channel 5 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH5(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH5_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH5_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH6_MASK   (0x8000000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH6_SHIFT  (27U)
/*! EDMA3_CH6 - eDMA3 Channel 6 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH6(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH6_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH6_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH7_MASK   (0x10000000U)
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH7_SHIFT  (28U)
/*! EDMA3_CH7 - eDMA3_INTR7 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH7(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH7_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_EDMA3_CH7_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_GPIO8_CH0_MASK   (0x20000000U)
#define SLEEPCON1_WAKEUPEN1_CLR_GPIO8_CH0_SHIFT  (29U)
/*! GPIO8_CH0 - GPIO8 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_GPIO8_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_GPIO8_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_GPIO8_CH0_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_GPIO8_CH1_MASK   (0x40000000U)
#define SLEEPCON1_WAKEUPEN1_CLR_GPIO8_CH1_SHIFT  (30U)
/*! GPIO8_CH1 - GPIO8 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_GPIO8_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_GPIO8_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_GPIO8_CH1_MASK)

#define SLEEPCON1_WAKEUPEN1_CLR_GPIO9_CH0_MASK   (0x80000000U)
#define SLEEPCON1_WAKEUPEN1_CLR_GPIO9_CH0_SHIFT  (31U)
/*! GPIO9_CH0 - GPIO9 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN1_CLR_GPIO9_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN1_CLR_GPIO9_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN1_CLR_GPIO9_CH0_MASK)
/*! @} */

/*! @name WAKEUPEN2_CLR - Wakeup Enable 2 Clear */
/*! @{ */

#define SLEEPCON1_WAKEUPEN2_CLR_GPIO9_CH1_MASK   (0x1U)
#define SLEEPCON1_WAKEUPEN2_CLR_GPIO9_CH1_SHIFT  (0U)
/*! GPIO9_CH1 - GPIO9 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN2_CLR_GPIO9_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_CLR_GPIO9_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN2_CLR_GPIO9_CH1_MASK)

#define SLEEPCON1_WAKEUPEN2_CLR_GPIO10_CH0_MASK  (0x2U)
#define SLEEPCON1_WAKEUPEN2_CLR_GPIO10_CH0_SHIFT (1U)
/*! GPIO10_CH0 - GPIO10 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN2_CLR_GPIO10_CH0(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_CLR_GPIO10_CH0_SHIFT)) & SLEEPCON1_WAKEUPEN2_CLR_GPIO10_CH0_MASK)

#define SLEEPCON1_WAKEUPEN2_CLR_GPIO10_CH1_MASK  (0x4U)
#define SLEEPCON1_WAKEUPEN2_CLR_GPIO10_CH1_SHIFT (2U)
/*! GPIO10_CH1 - GPIO10 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN2_CLR_GPIO10_CH1(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_CLR_GPIO10_CH1_SHIFT)) & SLEEPCON1_WAKEUPEN2_CLR_GPIO10_CH1_MASK)

#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR0_MASK (0x20U)
#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR0_SHIFT (5U)
/*! PINT1_INTR0 - PINT1_INTR0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR0(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR0_SHIFT)) & SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR0_MASK)

#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR1_MASK (0x40U)
#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR1_SHIFT (6U)
/*! PINT1_INTR1 - PINT1_INTR1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR1(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR1_SHIFT)) & SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR1_MASK)

#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR2_MASK (0x80U)
#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR2_SHIFT (7U)
/*! PINT1_INTR2 - PINT1_INTR2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR2(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR2_SHIFT)) & SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR2_MASK)

#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR3_MASK (0x100U)
#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR3_SHIFT (8U)
/*! PINT1_INTR3 - PINT1_INTR3 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR3(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR3_SHIFT)) & SLEEPCON1_WAKEUPEN2_CLR_PINT1_INTR3_MASK)

#define SLEEPCON1_WAKEUPEN2_CLR_SAI3_MASK        (0x200U)
#define SLEEPCON1_WAKEUPEN2_CLR_SAI3_SHIFT       (9U)
/*! SAI3 - SAI3 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_WAKEUPEN2_CLR_SAI3(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_WAKEUPEN2_CLR_SAI3_SHIFT)) & SLEEPCON1_WAKEUPEN2_CLR_SAI3_MASK)
/*! @} */

/*! @name LPOSC_DELAY - LPOSC Delay */
/*! @{ */

#define SLEEPCON1_LPOSC_DELAY_LPOSCDELAY_MASK    (0xFFFFU)
#define SLEEPCON1_LPOSC_DELAY_LPOSCDELAY_SHIFT   (0U)
/*! LPOSCDELAY - Delay value for LPOSC output */
#define SLEEPCON1_LPOSC_DELAY_LPOSCDELAY(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LPOSC_DELAY_LPOSCDELAY_SHIFT)) & SLEEPCON1_LPOSC_DELAY_LPOSCDELAY_MASK)
/*! @} */

/*! @name PWRDOWN_WAIT - Power Down Wait */
/*! @{ */

#define SLEEPCON1_PWRDOWN_WAIT_IGN_FRO2PDR_MASK  (0x4U)
#define SLEEPCON1_PWRDOWN_WAIT_IGN_FRO2PDR_SHIFT (2U)
/*! IGN_FRO2PDR - Ignore FRO2 Power Down Ready Signal
 *  0b0..Waits
 *  0b1..Ignores
 */
#define SLEEPCON1_PWRDOWN_WAIT_IGN_FRO2PDR(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PWRDOWN_WAIT_IGN_FRO2PDR_SHIFT)) & SLEEPCON1_PWRDOWN_WAIT_IGN_FRO2PDR_MASK)

#define SLEEPCON1_PWRDOWN_WAIT_IGN_LPOSCPDR_MASK (0x8U)
#define SLEEPCON1_PWRDOWN_WAIT_IGN_LPOSCPDR_SHIFT (3U)
/*! IGN_LPOSCPDR - Ignore LPOSC Power Down Ready Signal
 *  0b0..Waits
 *  0b1..Ignores
 */
#define SLEEPCON1_PWRDOWN_WAIT_IGN_LPOSCPDR(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PWRDOWN_WAIT_IGN_LPOSCPDR_SHIFT)) & SLEEPCON1_PWRDOWN_WAIT_IGN_LPOSCPDR_MASK)
/*! @} */

/*! @name HW_WAKE - eDMA Wakeup Enable */
/*! @{ */

#define SLEEPCON1_HW_WAKE_HWWK_SRC1_MASK         (0x2U)
#define SLEEPCON1_HW_WAKE_HWWK_SRC1_SHIFT        (1U)
/*! HWWK_SRC1 - eDMA Wakeup Source 1
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_HW_WAKE_HWWK_SRC1(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_HW_WAKE_HWWK_SRC1_SHIFT)) & SLEEPCON1_HW_WAKE_HWWK_SRC1_MASK)

#define SLEEPCON1_HW_WAKE_HWWK_SRC2_MASK         (0x4U)
#define SLEEPCON1_HW_WAKE_HWWK_SRC2_SHIFT        (2U)
/*! HWWK_SRC2 - eDMA Wakeup Source 2
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_HW_WAKE_HWWK_SRC2(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_HW_WAKE_HWWK_SRC2_SHIFT)) & SLEEPCON1_HW_WAKE_HWWK_SRC2_MASK)

#define SLEEPCON1_HW_WAKE_HWWK_SRC4_MASK         (0x10U)
#define SLEEPCON1_HW_WAKE_HWWK_SRC4_SHIFT        (4U)
/*! HWWK_SRC4 - eDMA Wakeup Source 4
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_HW_WAKE_HWWK_SRC4(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_HW_WAKE_HWWK_SRC4_SHIFT)) & SLEEPCON1_HW_WAKE_HWWK_SRC4_MASK)
/*! @} */

/*! @name HW_WAKE_SET - eDMA Wakeup Set */
/*! @{ */

#define SLEEPCON1_HW_WAKE_SET_HWWK_SRC1_SET_MASK (0x2U)
#define SLEEPCON1_HW_WAKE_SET_HWWK_SRC1_SET_SHIFT (1U)
/*! HWWK_SRC1_SET - eDMA Wakeup Source 1 Enable
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_HW_WAKE_SET_HWWK_SRC1_SET(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_HW_WAKE_SET_HWWK_SRC1_SET_SHIFT)) & SLEEPCON1_HW_WAKE_SET_HWWK_SRC1_SET_MASK)

#define SLEEPCON1_HW_WAKE_SET_HWWK_SRC2_SET_MASK (0x4U)
#define SLEEPCON1_HW_WAKE_SET_HWWK_SRC2_SET_SHIFT (2U)
/*! HWWK_SRC2_SET - eDMA Wakeup Source 2 Enable
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_HW_WAKE_SET_HWWK_SRC2_SET(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_HW_WAKE_SET_HWWK_SRC2_SET_SHIFT)) & SLEEPCON1_HW_WAKE_SET_HWWK_SRC2_SET_MASK)

#define SLEEPCON1_HW_WAKE_SET_HWWK_SRC4_SET_MASK (0x10U)
#define SLEEPCON1_HW_WAKE_SET_HWWK_SRC4_SET_SHIFT (4U)
/*! HWWK_SRC4_SET - eDMA Wakeup Source 4 Enable
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_HW_WAKE_SET_HWWK_SRC4_SET(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_HW_WAKE_SET_HWWK_SRC4_SET_SHIFT)) & SLEEPCON1_HW_WAKE_SET_HWWK_SRC4_SET_MASK)
/*! @} */

/*! @name HW_WAKE_CLR - eDMA Wakeup Clear */
/*! @{ */

#define SLEEPCON1_HW_WAKE_CLR_HWWK_SRC1_CLR_MASK (0x2U)
#define SLEEPCON1_HW_WAKE_CLR_HWWK_SRC1_CLR_SHIFT (1U)
/*! HWWK_SRC1_CLR - eDMA Wakeup Source 1 Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_HW_WAKE_CLR_HWWK_SRC1_CLR(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_HW_WAKE_CLR_HWWK_SRC1_CLR_SHIFT)) & SLEEPCON1_HW_WAKE_CLR_HWWK_SRC1_CLR_MASK)

#define SLEEPCON1_HW_WAKE_CLR_HWWK_SRC2_CLR_MASK (0x4U)
#define SLEEPCON1_HW_WAKE_CLR_HWWK_SRC2_CLR_SHIFT (2U)
/*! HWWK_SRC2_CLR - eDMA Wakeup Source 2 Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_HW_WAKE_CLR_HWWK_SRC2_CLR(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_HW_WAKE_CLR_HWWK_SRC2_CLR_SHIFT)) & SLEEPCON1_HW_WAKE_CLR_HWWK_SRC2_CLR_MASK)

#define SLEEPCON1_HW_WAKE_CLR_HWWK_SRC4_CLR_MASK (0x10U)
#define SLEEPCON1_HW_WAKE_CLR_HWWK_SRC4_CLR_SHIFT (4U)
/*! HWWK_SRC4_CLR - eDMA Wakeup Source 4 Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_HW_WAKE_CLR_HWWK_SRC4_CLR(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_HW_WAKE_CLR_HWWK_SRC4_CLR_SHIFT)) & SLEEPCON1_HW_WAKE_CLR_HWWK_SRC4_CLR_MASK)
/*! @} */

/*! @name SHARED_MASK0 - Shared Resources Mask */
/*! @{ */

#define SLEEPCON1_SHARED_MASK0_ADC0_MASK_MASK    (0x1U)
#define SLEEPCON1_SHARED_MASK0_ADC0_MASK_SHIFT   (0U)
/*! ADC0_MASK - Mask Bit of ADC0
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_ADC0_MASK(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_ADC0_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_ADC0_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_ACMP0_MASK_MASK   (0x2U)
#define SLEEPCON1_SHARED_MASK0_ACMP0_MASK_SHIFT  (1U)
/*! ACMP0_MASK - Mask Bit of ACMP0
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_ACMP0_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_ACMP0_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_ACMP0_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_MICFIL_MASK_MASK  (0x4U)
#define SLEEPCON1_SHARED_MASK0_MICFIL_MASK_SHIFT (2U)
/*! MICFIL_MASK - Mask Bit of MICFIL
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_MICFIL_MASK(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_MICFIL_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_MICFIL_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_LPI2C15_MASK_MASK (0x8U)
#define SLEEPCON1_SHARED_MASK0_LPI2C15_MASK_SHIFT (3U)
/*! LPI2C15_MASK - Mask Bit of LPI2C15
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_LPI2C15_MASK(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_LPI2C15_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_LPI2C15_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_GDET3_MASK_MASK   (0x20U)
#define SLEEPCON1_SHARED_MASK0_GDET3_MASK_SHIFT  (5U)
/*! GDET3_MASK - Mask Bit of GDET3
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_GDET3_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_GDET3_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_GDET3_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_RTC_MASK_MASK     (0x40U)
#define SLEEPCON1_SHARED_MASK0_RTC_MASK_SHIFT    (6U)
/*! RTC_MASK - Mask Bit of RTC0 and RTC1
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_RTC_MASK(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_RTC_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_RTC_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_VGPU_MASK_MASK    (0x10000U)
#define SLEEPCON1_SHARED_MASK0_VGPU_MASK_SHIFT   (16U)
/*! VGPU_MASK - Mask Bit of VGPU
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_VGPU_MASK(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_VGPU_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_VGPU_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_EZHV_MASK_MASK    (0x20000U)
#define SLEEPCON1_SHARED_MASK0_EZHV_MASK_SHIFT   (17U)
/*! EZHV_MASK - Mask Bit of EZH-V
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_EZHV_MASK(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_EZHV_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_EZHV_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_XSPI2_MASK_MASK   (0x40000U)
#define SLEEPCON1_SHARED_MASK0_XSPI2_MASK_SHIFT  (18U)
/*! XSPI2_MASK - Mask Bit of XSPI2
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_XSPI2_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_XSPI2_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_XSPI2_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_LPSPI14_MASK_MASK (0x80000U)
#define SLEEPCON1_SHARED_MASK0_LPSPI14_MASK_SHIFT (19U)
/*! LPSPI14_MASK - Mask Bit of LPSPI14
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_LPSPI14_MASK(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_LPSPI14_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_LPSPI14_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_LPSPI16_MASK_MASK (0x100000U)
#define SLEEPCON1_SHARED_MASK0_LPSPI16_MASK_SHIFT (20U)
/*! LPSPI16_MASK - Mask Bit of LPSPI16
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_LPSPI16_MASK(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_LPSPI16_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_LPSPI16_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_FLEXIO_MASK_MASK  (0x200000U)
#define SLEEPCON1_SHARED_MASK0_FLEXIO_MASK_SHIFT (21U)
/*! FLEXIO_MASK - Mask Bit of FLEXIO
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_FLEXIO_MASK(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_FLEXIO_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_FLEXIO_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_NIC0_MASK_MASK    (0x400000U)
#define SLEEPCON1_SHARED_MASK0_NIC0_MASK_SHIFT   (22U)
/*! NIC0_MASK - Mask Bit of NIC_MEDIA0
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_NIC0_MASK(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_NIC0_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_NIC0_MASK_MASK)

#define SLEEPCON1_SHARED_MASK0_NIC1_MASK_MASK    (0x800000U)
#define SLEEPCON1_SHARED_MASK0_NIC1_MASK_SHIFT   (23U)
/*! NIC1_MASK - Mask Bit of NIC_MEDIA1
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON1_SHARED_MASK0_NIC1_MASK(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_NIC1_MASK_SHIFT)) & SLEEPCON1_SHARED_MASK0_NIC1_MASK_MASK)
/*! @} */

/*! @name SHARED_MASK0_SET - Shared Resources Mask Set */
/*! @{ */

#define SLEEPCON1_SHARED_MASK0_SET_ADC0_MASK_SET_MASK (0x1U)
#define SLEEPCON1_SHARED_MASK0_SET_ADC0_MASK_SET_SHIFT (0U)
/*! ADC0_MASK_SET - ADC0 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_ADC0_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_ADC0_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_ADC0_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_ACMP0_MASK_SET_MASK (0x2U)
#define SLEEPCON1_SHARED_MASK0_SET_ACMP0_MASK_SET_SHIFT (1U)
/*! ACMP0_MASK_SET - ACMP0 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_ACMP0_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_ACMP0_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_ACMP0_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_MICFIL_MASK_SET_MASK (0x4U)
#define SLEEPCON1_SHARED_MASK0_SET_MICFIL_MASK_SET_SHIFT (2U)
/*! MICFIL_MASK_SET - MICFIL Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_MICFIL_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_MICFIL_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_MICFIL_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_LPI2C15_MASK_SET_MASK (0x8U)
#define SLEEPCON1_SHARED_MASK0_SET_LPI2C15_MASK_SET_SHIFT (3U)
/*! LPI2C15_MASK_SET - LPI2C15 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_LPI2C15_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_LPI2C15_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_LPI2C15_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_GDET3_MASK_SET_MASK (0x20U)
#define SLEEPCON1_SHARED_MASK0_SET_GDET3_MASK_SET_SHIFT (5U)
/*! GDET3_MASK_SET - GDET3 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_GDET3_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_GDET3_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_GDET3_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_RTC_MASK_SET_MASK (0x40U)
#define SLEEPCON1_SHARED_MASK0_SET_RTC_MASK_SET_SHIFT (6U)
/*! RTC_MASK_SET - RTC0 and RTC1 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_RTC_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_RTC_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_RTC_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_VGPU_MASK_SET_MASK (0x10000U)
#define SLEEPCON1_SHARED_MASK0_SET_VGPU_MASK_SET_SHIFT (16U)
/*! VGPU_MASK_SET - VGPU Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_VGPU_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_VGPU_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_VGPU_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_EZHV_MASK_SET_MASK (0x20000U)
#define SLEEPCON1_SHARED_MASK0_SET_EZHV_MASK_SET_SHIFT (17U)
/*! EZHV_MASK_SET - EZH-V Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_EZHV_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_EZHV_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_EZHV_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_XSPI2_MASK_SET_MASK (0x40000U)
#define SLEEPCON1_SHARED_MASK0_SET_XSPI2_MASK_SET_SHIFT (18U)
/*! XSPI2_MASK_SET - XSPI2 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_XSPI2_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_XSPI2_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_XSPI2_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_LPSPI14_MASK_SET_MASK (0x80000U)
#define SLEEPCON1_SHARED_MASK0_SET_LPSPI14_MASK_SET_SHIFT (19U)
/*! LPSPI14_MASK_SET - LPSPI14 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_LPSPI14_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_LPSPI14_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_LPSPI14_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_LPSPI16_MASK_SET_MASK (0x100000U)
#define SLEEPCON1_SHARED_MASK0_SET_LPSPI16_MASK_SET_SHIFT (20U)
/*! LPSPI16_MASK_SET - LPSPI16 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_LPSPI16_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_LPSPI16_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_LPSPI16_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_FLEXIO_MASK_SET_MASK (0x200000U)
#define SLEEPCON1_SHARED_MASK0_SET_FLEXIO_MASK_SET_SHIFT (21U)
/*! FLEXIO_MASK_SET - FLEXIO Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_FLEXIO_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_FLEXIO_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_FLEXIO_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_NIC0_MASK_SET_MASK (0x400000U)
#define SLEEPCON1_SHARED_MASK0_SET_NIC0_MASK_SET_SHIFT (22U)
/*! NIC0_MASK_SET - NIC_MEDIA0 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_NIC0_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_NIC0_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_NIC0_MASK_SET_MASK)

#define SLEEPCON1_SHARED_MASK0_SET_NIC1_MASK_SET_MASK (0x800000U)
#define SLEEPCON1_SHARED_MASK0_SET_NIC1_MASK_SET_SHIFT (23U)
/*! NIC1_MASK_SET - NIC_MEDIA1 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON1_SHARED_MASK0_SET_NIC1_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_SET_NIC1_MASK_SET_SHIFT)) & SLEEPCON1_SHARED_MASK0_SET_NIC1_MASK_SET_MASK)
/*! @} */

/*! @name SHARED_MASK0_CLR - Shared Resources Mask Clear */
/*! @{ */

#define SLEEPCON1_SHARED_MASK0_CLR_ADC0_MASK_CLR_MASK (0x1U)
#define SLEEPCON1_SHARED_MASK0_CLR_ADC0_MASK_CLR_SHIFT (0U)
/*! ADC0_MASK_CLR - ADC0 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_ADC0_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_ADC0_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_ADC0_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_ACMP0_MASK_CLR_MASK (0x2U)
#define SLEEPCON1_SHARED_MASK0_CLR_ACMP0_MASK_CLR_SHIFT (1U)
/*! ACMP0_MASK_CLR - ACMP0 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_ACMP0_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_ACMP0_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_ACMP0_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_MICFIL_MASK_CLR_MASK (0x4U)
#define SLEEPCON1_SHARED_MASK0_CLR_MICFIL_MASK_CLR_SHIFT (2U)
/*! MICFIL_MASK_CLR - MICFIL Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_MICFIL_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_MICFIL_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_MICFIL_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_LPI2C15_MASK_CLR_MASK (0x8U)
#define SLEEPCON1_SHARED_MASK0_CLR_LPI2C15_MASK_CLR_SHIFT (3U)
/*! LPI2C15_MASK_CLR - LPI2C15 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_LPI2C15_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_LPI2C15_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_LPI2C15_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_GDET3_MASK_CLR_MASK (0x20U)
#define SLEEPCON1_SHARED_MASK0_CLR_GDET3_MASK_CLR_SHIFT (5U)
/*! GDET3_MASK_CLR - GDET3 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_GDET3_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_GDET3_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_GDET3_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_RTC_MASK_CLR_MASK (0x40U)
#define SLEEPCON1_SHARED_MASK0_CLR_RTC_MASK_CLR_SHIFT (6U)
/*! RTC_MASK_CLR - RTC0 and RTC1 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_RTC_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_RTC_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_RTC_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_VGPU_MASK_CLR_MASK (0x10000U)
#define SLEEPCON1_SHARED_MASK0_CLR_VGPU_MASK_CLR_SHIFT (16U)
/*! VGPU_MASK_CLR - VGPU Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_VGPU_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_VGPU_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_VGPU_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_EZHV_MASK_CLR_MASK (0x20000U)
#define SLEEPCON1_SHARED_MASK0_CLR_EZHV_MASK_CLR_SHIFT (17U)
/*! EZHV_MASK_CLR - EZH-V Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_EZHV_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_EZHV_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_EZHV_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_XSPI2_MASK_CLR_MASK (0x40000U)
#define SLEEPCON1_SHARED_MASK0_CLR_XSPI2_MASK_CLR_SHIFT (18U)
/*! XSPI2_MASK_CLR - XSPI2 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_XSPI2_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_XSPI2_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_XSPI2_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_LPSPI14_MASK_CLR_MASK (0x80000U)
#define SLEEPCON1_SHARED_MASK0_CLR_LPSPI14_MASK_CLR_SHIFT (19U)
/*! LPSPI14_MASK_CLR - LPSPI14 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_LPSPI14_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_LPSPI14_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_LPSPI14_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_LPSPI16_MASK_CLR_MASK (0x100000U)
#define SLEEPCON1_SHARED_MASK0_CLR_LPSPI16_MASK_CLR_SHIFT (20U)
/*! LPSPI16_MASK_CLR - LPSPI16 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_LPSPI16_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_LPSPI16_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_LPSPI16_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_FLEXIO_MASK_CLR_MASK (0x200000U)
#define SLEEPCON1_SHARED_MASK0_CLR_FLEXIO_MASK_CLR_SHIFT (21U)
/*! FLEXIO_MASK_CLR - FLEXIO Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_FLEXIO_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_FLEXIO_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_FLEXIO_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_NIC0_MASK_CLR_MASK (0x400000U)
#define SLEEPCON1_SHARED_MASK0_CLR_NIC0_MASK_CLR_SHIFT (22U)
/*! NIC0_MASK_CLR - NIC_MEDIAO Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_NIC0_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_NIC0_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_NIC0_MASK_CLR_MASK)

#define SLEEPCON1_SHARED_MASK0_CLR_NIC1_MASK_CLR_MASK (0x800000U)
#define SLEEPCON1_SHARED_MASK0_CLR_NIC1_MASK_CLR_SHIFT (23U)
/*! NIC1_MASK_CLR - NIC_MEDIA1 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON1_SHARED_MASK0_CLR_NIC1_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHARED_MASK0_CLR_NIC1_MASK_CLR_SHIFT)) & SLEEPCON1_SHARED_MASK0_CLR_NIC1_MASK_CLR_MASK)
/*! @} */

/*! @name SHA_MED_CCTRL0 - Media Domain Shared Controller Low-power Control */
/*! @{ */

#define SLEEPCON1_SHA_MED_CCTRL0_VGPU_LPREQ_MASK (0x1U)
#define SLEEPCON1_SHA_MED_CCTRL0_VGPU_LPREQ_SHIFT (0U)
/*! VGPU_LPREQ - VGPU Low-Power Control
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_CCTRL0_VGPU_LPREQ(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_CCTRL0_VGPU_LPREQ_SHIFT)) & SLEEPCON1_SHA_MED_CCTRL0_VGPU_LPREQ_MASK)

#define SLEEPCON1_SHA_MED_CCTRL0_EZHV_STOP_MASK  (0x2U)
#define SLEEPCON1_SHA_MED_CCTRL0_EZHV_STOP_SHIFT (1U)
/*! EZHV_STOP - EZH-V Stop Control
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_CCTRL0_EZHV_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_CCTRL0_EZHV_STOP_SHIFT)) & SLEEPCON1_SHA_MED_CCTRL0_EZHV_STOP_MASK)

#define SLEEPCON1_SHA_MED_CCTRL0_EZHV_HALT_MASK  (0x4U)
#define SLEEPCON1_SHA_MED_CCTRL0_EZHV_HALT_SHIFT (2U)
/*! EZHV_HALT - EZH-V Halt Control
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_CCTRL0_EZHV_HALT(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_CCTRL0_EZHV_HALT_SHIFT)) & SLEEPCON1_SHA_MED_CCTRL0_EZHV_HALT_MASK)

#define SLEEPCON1_SHA_MED_CCTRL0_EZHV_EXIT_WAIT_MASK (0x8U)
#define SLEEPCON1_SHA_MED_CCTRL0_EZHV_EXIT_WAIT_SHIFT (3U)
/*! EZHV_EXIT_WAIT - EZH-V Exit Wait Mode
 *  0b0..No request
 *  0b1..Sends
 */
#define SLEEPCON1_SHA_MED_CCTRL0_EZHV_EXIT_WAIT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_CCTRL0_EZHV_EXIT_WAIT_SHIFT)) & SLEEPCON1_SHA_MED_CCTRL0_EZHV_EXIT_WAIT_MASK)
/*! @} */

/*! @name SHA_MED_TCTRL0 - Media Domain Shared Resources Target Low-power Control */
/*! @{ */

#define SLEEPCON1_SHA_MED_TCTRL0_XSPI2_STOP_MASK (0x1U)
#define SLEEPCON1_SHA_MED_TCTRL0_XSPI2_STOP_SHIFT (0U)
/*! XSPI2_STOP - XSPI2 Stop Control
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_TCTRL0_XSPI2_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_TCTRL0_XSPI2_STOP_SHIFT)) & SLEEPCON1_SHA_MED_TCTRL0_XSPI2_STOP_MASK)

#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI14_B_LPREQ_MASK (0x8U)
#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI14_B_LPREQ_SHIFT (3U)
/*! LPSPI14_B_LPREQ - LPSPI14 Bus Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI14_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_TCTRL0_LPSPI14_B_LPREQ_SHIFT)) & SLEEPCON1_SHA_MED_TCTRL0_LPSPI14_B_LPREQ_MASK)

#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI14_F_LPREQ_MASK (0x10U)
#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI14_F_LPREQ_SHIFT (4U)
/*! LPSPI14_F_LPREQ - LPSPI14 Function Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI14_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_TCTRL0_LPSPI14_F_LPREQ_SHIFT)) & SLEEPCON1_SHA_MED_TCTRL0_LPSPI14_F_LPREQ_MASK)

#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI16_B_LPREQ_MASK (0x40U)
#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI16_B_LPREQ_SHIFT (6U)
/*! LPSPI16_B_LPREQ - LPSPI16 Bus Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI16_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_TCTRL0_LPSPI16_B_LPREQ_SHIFT)) & SLEEPCON1_SHA_MED_TCTRL0_LPSPI16_B_LPREQ_MASK)

#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI16_F_LPREQ_MASK (0x80U)
#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI16_F_LPREQ_SHIFT (7U)
/*! LPSPI16_F_LPREQ - LPSPI16 Function Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_TCTRL0_LPSPI16_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_TCTRL0_LPSPI16_F_LPREQ_SHIFT)) & SLEEPCON1_SHA_MED_TCTRL0_LPSPI16_F_LPREQ_MASK)

#define SLEEPCON1_SHA_MED_TCTRL0_FLEXIO_B_LPREQ_MASK (0x200U)
#define SLEEPCON1_SHA_MED_TCTRL0_FLEXIO_B_LPREQ_SHIFT (9U)
/*! FLEXIO_B_LPREQ - FLEXIO Bus Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_TCTRL0_FLEXIO_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_TCTRL0_FLEXIO_B_LPREQ_SHIFT)) & SLEEPCON1_SHA_MED_TCTRL0_FLEXIO_B_LPREQ_MASK)

#define SLEEPCON1_SHA_MED_TCTRL0_FLEXIO_F_LPREQ_MASK (0x400U)
#define SLEEPCON1_SHA_MED_TCTRL0_FLEXIO_F_LPREQ_SHIFT (10U)
/*! FLEXIO_F_LPREQ - FLEXIO Function Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_TCTRL0_FLEXIO_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_TCTRL0_FLEXIO_F_LPREQ_SHIFT)) & SLEEPCON1_SHA_MED_TCTRL0_FLEXIO_F_LPREQ_MASK)

#define SLEEPCON1_SHA_MED_TCTRL0_NIC0_LPREQ_MASK (0x800U)
#define SLEEPCON1_SHA_MED_TCTRL0_NIC0_LPREQ_SHIFT (11U)
/*! NIC0_LPREQ - NIC_MEDIA0 Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_TCTRL0_NIC0_LPREQ(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_TCTRL0_NIC0_LPREQ_SHIFT)) & SLEEPCON1_SHA_MED_TCTRL0_NIC0_LPREQ_MASK)

#define SLEEPCON1_SHA_MED_TCTRL0_NIC1_LPREQ_MASK (0x1000U)
#define SLEEPCON1_SHA_MED_TCTRL0_NIC1_LPREQ_SHIFT (12U)
/*! NIC1_LPREQ - NIC_MEDIA1 Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_MED_TCTRL0_NIC1_LPREQ(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_TCTRL0_NIC1_LPREQ_SHIFT)) & SLEEPCON1_SHA_MED_TCTRL0_NIC1_LPREQ_MASK)
/*! @} */

/*! @name SHA_SEN_TCTRL0 - Shared VDD1_SENSE Domain Targets Low-power Control */
/*! @{ */

#define SLEEPCON1_SHA_SEN_TCTRL0_ADC0_STOP_MASK  (0x1U)
#define SLEEPCON1_SHA_SEN_TCTRL0_ADC0_STOP_SHIFT (0U)
/*! ADC0_STOP - ADC0 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_SEN_TCTRL0_ADC0_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_SEN_TCTRL0_ADC0_STOP_SHIFT)) & SLEEPCON1_SHA_SEN_TCTRL0_ADC0_STOP_MASK)

#define SLEEPCON1_SHA_SEN_TCTRL0_ACMP0_STOP_MASK (0x4U)
#define SLEEPCON1_SHA_SEN_TCTRL0_ACMP0_STOP_SHIFT (2U)
/*! ACMP0_STOP - ACMP0 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_SEN_TCTRL0_ACMP0_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_SEN_TCTRL0_ACMP0_STOP_SHIFT)) & SLEEPCON1_SHA_SEN_TCTRL0_ACMP0_STOP_MASK)

#define SLEEPCON1_SHA_SEN_TCTRL0_MICFIL_STOP_MASK (0x8U)
#define SLEEPCON1_SHA_SEN_TCTRL0_MICFIL_STOP_SHIFT (3U)
/*! MICFIL_STOP - MICFIL Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_SEN_TCTRL0_MICFIL_STOP(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_SEN_TCTRL0_MICFIL_STOP_SHIFT)) & SLEEPCON1_SHA_SEN_TCTRL0_MICFIL_STOP_MASK)

#define SLEEPCON1_SHA_SEN_TCTRL0_LPI2C15_B_LPREQ_MASK (0x20U)
#define SLEEPCON1_SHA_SEN_TCTRL0_LPI2C15_B_LPREQ_SHIFT (5U)
/*! LPI2C15_B_LPREQ - LPI2C15 Bus Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_SEN_TCTRL0_LPI2C15_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_SEN_TCTRL0_LPI2C15_B_LPREQ_SHIFT)) & SLEEPCON1_SHA_SEN_TCTRL0_LPI2C15_B_LPREQ_MASK)

#define SLEEPCON1_SHA_SEN_TCTRL0_LPI2C15_F_LPREQ_MASK (0x80U)
#define SLEEPCON1_SHA_SEN_TCTRL0_LPI2C15_F_LPREQ_SHIFT (7U)
/*! LPI2C15_F_LPREQ - LPI2C15 Function Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_SEN_TCTRL0_LPI2C15_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_SEN_TCTRL0_LPI2C15_F_LPREQ_SHIFT)) & SLEEPCON1_SHA_SEN_TCTRL0_LPI2C15_F_LPREQ_MASK)

#define SLEEPCON1_SHA_SEN_TCTRL0_GDET3_LPREQ_MASK (0x200U)
#define SLEEPCON1_SHA_SEN_TCTRL0_GDET3_LPREQ_SHIFT (9U)
/*! GDET3_LPREQ - GDET3 Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_SEN_TCTRL0_GDET3_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_SEN_TCTRL0_GDET3_LPREQ_SHIFT)) & SLEEPCON1_SHA_SEN_TCTRL0_GDET3_LPREQ_MASK)

#define SLEEPCON1_SHA_SEN_TCTRL0_RTC_STOP_MASK   (0x80000000U)
#define SLEEPCON1_SHA_SEN_TCTRL0_RTC_STOP_SHIFT  (31U)
/*! RTC_STOP - RTC0 and RTC1 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_SHA_SEN_TCTRL0_RTC_STOP(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_SEN_TCTRL0_RTC_STOP_SHIFT)) & SLEEPCON1_SHA_SEN_TCTRL0_RTC_STOP_MASK)
/*! @} */

/*! @name PRIVATE_CCTRL0 - Private Resources Controllers Low-power Control 0 */
/*! @{ */

#define SLEEPCON1_PRIVATE_CCTRL0_EDMA2_STOP_MASK (0x1U)
#define SLEEPCON1_PRIVATE_CCTRL0_EDMA2_STOP_SHIFT (0U)
/*! EDMA2_STOP - eDMA2 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_CCTRL0_EDMA2_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_CCTRL0_EDMA2_STOP_SHIFT)) & SLEEPCON1_PRIVATE_CCTRL0_EDMA2_STOP_MASK)

#define SLEEPCON1_PRIVATE_CCTRL0_EDMA3_STOP_MASK (0x2U)
#define SLEEPCON1_PRIVATE_CCTRL0_EDMA3_STOP_SHIFT (1U)
/*! EDMA3_STOP - eDMA3 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_CCTRL0_EDMA3_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_CCTRL0_EDMA3_STOP_SHIFT)) & SLEEPCON1_PRIVATE_CCTRL0_EDMA3_STOP_MASK)
/*! @} */

/*! @name PRIVATE_TCTRL0 - Private Resources Target Low-power Control */
/*! @{ */

#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM17__B_LPREQ_MASK (0x1U)
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM17__B_LPREQ_SHIFT (0U)
/*! LP_FLEXCOMM17__B_LPREQ - LP_FLEXCOMM17 Bus Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM17__B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM17__B_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM17__B_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM18__B_LPREQ_MASK (0x2U)
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM18__B_LPREQ_SHIFT (1U)
/*! LP_FLEXCOMM18__B_LPREQ - LP_FLEXCOMM18 Bus Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM18__B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM18__B_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM18__B_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM19__B_LPREQ_MASK (0x4U)
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM19__B_LPREQ_SHIFT (2U)
/*! LP_FLEXCOMM19__B_LPREQ - LP_FLEXCOMM19 Bus Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM19__B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM19__B_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM19__B_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM20__B_LPREQ_MASK (0x8U)
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM20__B_LPREQ_SHIFT (3U)
/*! LP_FLEXCOMM20__B_LPREQ - LP_FLEXCOMM20 Bus Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM20__B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM20__B_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM20__B_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM17_F_LPREQ_MASK (0x10U)
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM17_F_LPREQ_SHIFT (4U)
/*! LP_FLEXCOMM17_F_LPREQ - LP_FLEXCOMM17 Function Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM17_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM17_F_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM17_F_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM18_F_LPREQ_MASK (0x20U)
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM18_F_LPREQ_SHIFT (5U)
/*! LP_FLEXCOMM18_F_LPREQ - LP_FLEXCOMM18 Function Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM18_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM18_F_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM18_F_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM19_F_LPREQ_MASK (0x40U)
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM19_F_LPREQ_SHIFT (6U)
/*! LP_FLEXCOMM19_F_LPREQ - LP_FLEXCOMM19 Function Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM19_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM19_F_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM19_F_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM20_F_LPREQ_MASK (0x80U)
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM20_F_LPREQ_SHIFT (7U)
/*! LP_FLEXCOMM20_F_LPREQ - LP_FLEXCOMM20 Function Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM20_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM20_F_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_LP_FLEXCOMM20_F_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_SAI3_LPREQ_MASK (0x100U)
#define SLEEPCON1_PRIVATE_TCTRL0_SAI3_LPREQ_SHIFT (8U)
/*! SAI3_LPREQ - SAI3 Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_SAI3_LPREQ(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_SAI3_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_SAI3_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_GPIO8_LPREQ_MASK (0x200U)
#define SLEEPCON1_PRIVATE_TCTRL0_GPIO8_LPREQ_SHIFT (9U)
/*! GPIO8_LPREQ - GPIO8 Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_GPIO8_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_GPIO8_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_GPIO8_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_GPIO9_LPREQ_MASK (0x400U)
#define SLEEPCON1_PRIVATE_TCTRL0_GPIO9_LPREQ_SHIFT (10U)
/*! GPIO9_LPREQ - GPIO9 Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_GPIO9_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_GPIO9_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_GPIO9_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_GPIO10_LPREQ_MASK (0x800U)
#define SLEEPCON1_PRIVATE_TCTRL0_GPIO10_LPREQ_SHIFT (11U)
/*! GPIO10_LPREQ - GPIO10 Low-power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_GPIO10_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_GPIO10_LPREQ_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_GPIO10_LPREQ_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_I3C2_STOP_MASK  (0x100000U)
#define SLEEPCON1_PRIVATE_TCTRL0_I3C2_STOP_SHIFT (20U)
/*! I3C2_STOP - I3C2 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_I3C2_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_I3C2_STOP_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_I3C2_STOP_MASK)

#define SLEEPCON1_PRIVATE_TCTRL0_I3C3_STOP_MASK  (0x200000U)
#define SLEEPCON1_PRIVATE_TCTRL0_I3C3_STOP_SHIFT (21U)
/*! I3C3_STOP - I3C3 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON1_PRIVATE_TCTRL0_I3C3_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TCTRL0_I3C3_STOP_SHIFT)) & SLEEPCON1_PRIVATE_TCTRL0_I3C3_STOP_MASK)
/*! @} */

/*! @name SHA_MED_CSTAT0 - Media Domain Shared Controllers Low-power Status */
/*! @{ */

#define SLEEPCON1_SHA_MED_CSTAT0_VGPU_LPACCEPT_MASK (0x1U)
#define SLEEPCON1_SHA_MED_CSTAT0_VGPU_LPACCEPT_SHIFT (0U)
/*! VGPU_LPACCEPT - VGPU Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_SHA_MED_CSTAT0_VGPU_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_CSTAT0_VGPU_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MED_CSTAT0_VGPU_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MED_CSTAT0_VGPU_IDLE_MASK  (0x2U)
#define SLEEPCON1_SHA_MED_CSTAT0_VGPU_IDLE_SHIFT (1U)
/*! VGPU_IDLE - VGPU Idle Status
 *  0b0..Not in Idle status, VGPU has operation to perform.
 *  0b1..In Idle status, VGPU might accept low-power request.
 */
#define SLEEPCON1_SHA_MED_CSTAT0_VGPU_IDLE(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_CSTAT0_VGPU_IDLE_SHIFT)) & SLEEPCON1_SHA_MED_CSTAT0_VGPU_IDLE_MASK)

#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_STOP_MASK  (0x4U)
#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_STOP_SHIFT (2U)
/*! EZHV_STOP - EZH-V Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_CSTAT0_EZHV_STOP_SHIFT)) & SLEEPCON1_SHA_MED_CSTAT0_EZHV_STOP_MASK)

#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_HALT_MASK  (0x8U)
#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_HALT_SHIFT (3U)
/*! EZHV_HALT - EZH-V Halt Status
 *  0b0..Not in Halt status
 *  0b1..In Halt status
 */
#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_HALT(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_CSTAT0_EZHV_HALT_SHIFT)) & SLEEPCON1_SHA_MED_CSTAT0_EZHV_HALT_MASK)

#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_WAITING_MASK (0x10U)
#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_WAITING_SHIFT (4U)
/*! EZHV_WAITING - EZH-V Waiting Status
 *  0b0..Not in waiting status
 *  0b1..In waiting status
 */
#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_WAITING(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_CSTAT0_EZHV_WAITING_SHIFT)) & SLEEPCON1_SHA_MED_CSTAT0_EZHV_WAITING_MASK)

#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_WAKEUP_MASK (0x20U)
#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_WAKEUP_SHIFT (5U)
/*! EZHV_WAKEUP - Wakeup Request from EZH-V
 *  0b0..Not needs
 *  0b1..Needs
 */
#define SLEEPCON1_SHA_MED_CSTAT0_EZHV_WAKEUP(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MED_CSTAT0_EZHV_WAKEUP_SHIFT)) & SLEEPCON1_SHA_MED_CSTAT0_EZHV_WAKEUP_MASK)
/*! @} */

/*! @name SHA_MEDSEN_TSTAT0 - Media and Sense Domain Shared Targets Low-power Status */
/*! @{ */

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_XSPI2_STOP_MASK (0x1U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_XSPI2_STOP_SHIFT (0U)
/*! XSPI2_STOP - XSPI2 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_XSPI2_STOP(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_XSPI2_STOP_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_XSPI2_STOP_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI14_B_LPACCEPT_MASK (0x2U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI14_B_LPACCEPT_SHIFT (1U)
/*! LPSPI14_B_LPACCEPT - LPSPI14 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI14_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI14_B_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI14_B_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI14_F_LPACCEPT_MASK (0x4U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI14_F_LPACCEPT_SHIFT (2U)
/*! LPSPI14_F_LPACCEPT - LPSPI14 Function Low-power Accept Status
 *  0b0..Not ready
 *  0b1..Ready
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI14_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI14_F_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI14_F_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI16_B_LPACCEPT_MASK (0x8U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI16_B_LPACCEPT_SHIFT (3U)
/*! LPSPI16_B_LPACCEPT - LPSPI16 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI16_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI16_B_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI16_B_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI16_F_LPACCEPT_MASK (0x10U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI16_F_LPACCEPT_SHIFT (4U)
/*! LPSPI16_F_LPACCEPT - LPSPI16 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI16_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI16_F_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_LPSPI16_F_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_FLEXIO_B_LPACCEPT_MASK (0x20U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_FLEXIO_B_LPACCEPT_SHIFT (5U)
/*! FLEXIO_B_LPACCEPT - FLEXIO Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_FLEXIO_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_FLEXIO_B_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_FLEXIO_B_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_FLEXIO_F_LPACCEPT_MASK (0x40U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_FLEXIO_F_LPACCEPT_SHIFT (6U)
/*! FLEXIO_F_LPACCEPT - FLEXIO Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_FLEXIO_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_FLEXIO_F_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_FLEXIO_F_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_NIC0_LPACCEPT_MASK (0x80U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_NIC0_LPACCEPT_SHIFT (7U)
/*! NIC0_LPACCEPT - NIC_MEDIA0 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_NIC0_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_NIC0_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_NIC0_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_NIC1_LPACCEPT_MASK (0x100U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_NIC1_LPACCEPT_SHIFT (8U)
/*! NIC1_LPACCEPT - NIC_MEDIA1 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_NIC1_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_NIC1_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_NIC1_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_ADC0_STOP_MASK (0x10000U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_ADC0_STOP_SHIFT (16U)
/*! ADC0_STOP - ADC0 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_ADC0_STOP(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_ADC0_STOP_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_ADC0_STOP_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_ACMP0_STOP_MASK (0x20000U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_ACMP0_STOP_SHIFT (17U)
/*! ACMP0_STOP - ACMP0 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_ACMP0_STOP(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_ACMP0_STOP_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_ACMP0_STOP_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_MICFIL_STOP_MASK (0x40000U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_MICFIL_STOP_SHIFT (18U)
/*! MICFIL_STOP - MICFIL Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_MICFIL_STOP(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_MICFIL_STOP_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_MICFIL_STOP_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPI2C15_B_LPACCEPT_MASK (0x80000U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPI2C15_B_LPACCEPT_SHIFT (19U)
/*! LPI2C15_B_LPACCEPT - LPI2C15 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPI2C15_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_LPI2C15_B_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_LPI2C15_B_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPI2C15_F_LPACCEPT_MASK (0x100000U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPI2C15_F_LPACCEPT_SHIFT (20U)
/*! LPI2C15_F_LPACCEPT - LPI2C15 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_LPI2C15_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_LPI2C15_F_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_LPI2C15_F_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_GDET3_LPACCEPT_MASK (0x400000U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_GDET3_LPACCEPT_SHIFT (22U)
/*! GDET3_LPACCEPT - GDET3 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_GDET3_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_GDET3_LPACCEPT_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_GDET3_LPACCEPT_MASK)

#define SLEEPCON1_SHA_MEDSEN_TSTAT0_RTC_STOP_MASK (0x80000000U)
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_RTC_STOP_SHIFT (31U)
/*! RTC_STOP - RTC0 and RTC1 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON1_SHA_MEDSEN_TSTAT0_RTC_STOP(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_SHA_MEDSEN_TSTAT0_RTC_STOP_SHIFT)) & SLEEPCON1_SHA_MEDSEN_TSTAT0_RTC_STOP_MASK)
/*! @} */

/*! @name PRIVATE_CSTAT0 - Private Resources Controllers Low-power Status */
/*! @{ */

#define SLEEPCON1_PRIVATE_CSTAT0_EDMA2_STOP_MASK (0x1U)
#define SLEEPCON1_PRIVATE_CSTAT0_EDMA2_STOP_SHIFT (0U)
/*! EDMA2_STOP - eDMA2 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON1_PRIVATE_CSTAT0_EDMA2_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_CSTAT0_EDMA2_STOP_SHIFT)) & SLEEPCON1_PRIVATE_CSTAT0_EDMA2_STOP_MASK)

#define SLEEPCON1_PRIVATE_CSTAT0_EDMA3_STOP_MASK (0x2U)
#define SLEEPCON1_PRIVATE_CSTAT0_EDMA3_STOP_SHIFT (1U)
/*! EDMA3_STOP - eDMA3 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON1_PRIVATE_CSTAT0_EDMA3_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_CSTAT0_EDMA3_STOP_SHIFT)) & SLEEPCON1_PRIVATE_CSTAT0_EDMA3_STOP_MASK)
/*! @} */

/*! @name PRIVATE_TSTAT0 - Private Resources Targets Low-power Status 0 */
/*! @{ */

#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM17_B_LPACCEPT_MASK (0x1U)
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM17_B_LPACCEPT_SHIFT (0U)
/*! LP_FLEXCOMM17_B_LPACCEPT - LP_FLEXCOMM17 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM17_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM17_B_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM17_B_LPACCEPT_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM18_B_LPACCEPT_MASK (0x2U)
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM18_B_LPACCEPT_SHIFT (1U)
/*! LP_FLEXCOMM18_B_LPACCEPT - LP_FLEXCOMM18 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM18_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM18_B_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM18_B_LPACCEPT_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM19_B_LPACCEPT_MASK (0x4U)
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM19_B_LPACCEPT_SHIFT (2U)
/*! LP_FLEXCOMM19_B_LPACCEPT - LP_FLEXCOMM19 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM19_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM19_B_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM19_B_LPACCEPT_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM20_B_LPACCEPT_MASK (0x8U)
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM20_B_LPACCEPT_SHIFT (3U)
/*! LP_FLEXCOMM20_B_LPACCEPT - LP_FLEXCOMM20 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM20_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM20_B_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM20_B_LPACCEPT_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_SAI3_LPACCEPT_MASK (0x10U)
#define SLEEPCON1_PRIVATE_TSTAT0_SAI3_LPACCEPT_SHIFT (4U)
/*! SAI3_LPACCEPT - SAI3 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_SAI3_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_SAI3_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_SAI3_LPACCEPT_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_GPIO8_LPACCEPT_MASK (0x20U)
#define SLEEPCON1_PRIVATE_TSTAT0_GPIO8_LPACCEPT_SHIFT (5U)
/*! GPIO8_LPACCEPT - GPIO8 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_GPIO8_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_GPIO8_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_GPIO8_LPACCEPT_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_GPIO9_LPACCEPT_MASK (0x40U)
#define SLEEPCON1_PRIVATE_TSTAT0_GPIO9_LPACCEPT_SHIFT (6U)
/*! GPIO9_LPACCEPT - GPIO Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_GPIO9_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_GPIO9_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_GPIO9_LPACCEPT_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_GPIO10_LPACCEPT_MASK (0x80U)
#define SLEEPCON1_PRIVATE_TSTAT0_GPIO10_LPACCEPT_SHIFT (7U)
/*! GPIO10_LPACCEPT - GPIO10 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_GPIO10_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_GPIO10_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_GPIO10_LPACCEPT_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_I3C2_STOP_MASK  (0x100U)
#define SLEEPCON1_PRIVATE_TSTAT0_I3C2_STOP_SHIFT (8U)
/*! I3C2_STOP - I3C2 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON1_PRIVATE_TSTAT0_I3C2_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_I3C2_STOP_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_I3C2_STOP_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_I3C3_STOP_MASK  (0x200U)
#define SLEEPCON1_PRIVATE_TSTAT0_I3C3_STOP_SHIFT (9U)
/*! I3C3_STOP - I3C3 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON1_PRIVATE_TSTAT0_I3C3_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_I3C3_STOP_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_I3C3_STOP_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM17_F_LPACCEPT_MASK (0x10000U)
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM17_F_LPACCEPT_SHIFT (16U)
/*! LP_FLEXCOMM17_F_LPACCEPT - LP_FLEXCOMM17 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM17_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM17_F_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM17_F_LPACCEPT_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM18_F_LPACCEPT_MASK (0x20000U)
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM18_F_LPACCEPT_SHIFT (17U)
/*! LP_FLEXCOMM18_F_LPACCEPT - LP_FLEXCOMM18 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM18_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM18_F_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM18_F_LPACCEPT_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM19_F_LPACCEPT_MASK (0x40000U)
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM19_F_LPACCEPT_SHIFT (18U)
/*! LP_FLEXCOMM19_F_LPACCEPT - LP_FLEXCOMM19 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM19_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM19_F_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM19_F_LPACCEPT_MASK)

#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM20_F_LPACCEPT_MASK (0x80000U)
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM20_F_LPACCEPT_SHIFT (19U)
/*! LP_FLEXCOMM20_F_LPACCEPT - LP_FLEXCOMM20 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM20_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM20_F_LPACCEPT_SHIFT)) & SLEEPCON1_PRIVATE_TSTAT0_LP_FLEXCOMM20_F_LPACCEPT_MASK)
/*! @} */

/*! @name LP_HINT0 - Low-Power Hint Status 0 */
/*! @{ */

#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM17_B_LPHINT_MASK (0x1U)
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM17_B_LPHINT_SHIFT (0U)
/*! LP_FLEXCOMM17_B_LPHINT - LP_FLEXCOMM17 Bus Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM17_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LP_FLEXCOMM17_B_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LP_FLEXCOMM17_B_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM18_B_LPHINT_MASK (0x2U)
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM18_B_LPHINT_SHIFT (1U)
/*! LP_FLEXCOMM18_B_LPHINT - LP_FLEXCOMM18 Bus Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM18_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LP_FLEXCOMM18_B_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LP_FLEXCOMM18_B_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM19_B_LPHINT_MASK (0x4U)
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM19_B_LPHINT_SHIFT (2U)
/*! LP_FLEXCOMM19_B_LPHINT - LP_FLEXCOMM19 Bus Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM19_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LP_FLEXCOMM19_B_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LP_FLEXCOMM19_B_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM20_B_LPHINT_MASK (0x8U)
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM20_B_LPHINT_SHIFT (3U)
/*! LP_FLEXCOMM20_B_LPHINT - LP_FLEXCOMM20 Bus Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM20_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LP_FLEXCOMM20_B_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LP_FLEXCOMM20_B_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_SAI3_B_LPHINT_MASK    (0x10U)
#define SLEEPCON1_LP_HINT0_SAI3_B_LPHINT_SHIFT   (4U)
/*! SAI3_B_LPHINT - SAI3 Bus Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_SAI3_B_LPHINT(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_SAI3_B_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_SAI3_B_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_GPIO8_LPHINT_MASK     (0x20U)
#define SLEEPCON1_LP_HINT0_GPIO8_LPHINT_SHIFT    (5U)
/*! GPIO8_LPHINT - GPIO8 Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_GPIO8_LPHINT(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_GPIO8_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_GPIO8_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_GPIO9_LPHINT_MASK     (0x40U)
#define SLEEPCON1_LP_HINT0_GPIO9_LPHINT_SHIFT    (6U)
/*! GPIO9_LPHINT - GPIO9 Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_GPIO9_LPHINT(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_GPIO9_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_GPIO9_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_GPIO10_LPHINT_MASK    (0x80U)
#define SLEEPCON1_LP_HINT0_GPIO10_LPHINT_SHIFT   (7U)
/*! GPIO10_LPHINT - GPIO10 Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_GPIO10_LPHINT(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_GPIO10_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_GPIO10_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LPI2C15_B_LPHINT_MASK (0x100U)
#define SLEEPCON1_LP_HINT0_LPI2C15_B_LPHINT_SHIFT (8U)
/*! LPI2C15_B_LPHINT - LPI2C15 Bus Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LPI2C15_B_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LPI2C15_B_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LPI2C15_B_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LPSPI14_B_LPHINT_MASK (0x200U)
#define SLEEPCON1_LP_HINT0_LPSPI14_B_LPHINT_SHIFT (9U)
/*! LPSPI14_B_LPHINT - LPSPI14 Bus Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LPSPI14_B_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LPSPI14_B_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LPSPI14_B_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LPSPI16_B_LPHINT_MASK (0x400U)
#define SLEEPCON1_LP_HINT0_LPSPI16_B_LPHINT_SHIFT (10U)
/*! LPSPI16_B_LPHINT - LPSPI16 Bus Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LPSPI16_B_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LPSPI16_B_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LPSPI16_B_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_FLEXIO_B_LPHINT_MASK  (0x800U)
#define SLEEPCON1_LP_HINT0_FLEXIO_B_LPHINT_SHIFT (11U)
/*! FLEXIO_B_LPHINT - FLEXIO Bus Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_FLEXIO_B_LPHINT(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_FLEXIO_B_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_FLEXIO_B_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM17_F_LPHINT_MASK (0x10000U)
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM17_F_LPHINT_SHIFT (16U)
/*! LP_FLEXCOMM17_F_LPHINT - LP_FLEXCOMM17 Function Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM17_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LP_FLEXCOMM17_F_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LP_FLEXCOMM17_F_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM18_F_LPHINT_MASK (0x20000U)
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM18_F_LPHINT_SHIFT (17U)
/*! LP_FLEXCOMM18_F_LPHINT - LP_FLEXCOMM18 Function Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM18_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LP_FLEXCOMM18_F_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LP_FLEXCOMM18_F_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM19_F_LPHINT_MASK (0x40000U)
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM19_F_LPHINT_SHIFT (18U)
/*! LP_FLEXCOMM19_F_LPHINT - LP_FLEXCOMM19 Function Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM19_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LP_FLEXCOMM19_F_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LP_FLEXCOMM19_F_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM20_F_LPHINT_MASK (0x80000U)
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM20_F_LPHINT_SHIFT (19U)
/*! LP_FLEXCOMM20_F_LPHINT - LP_FLEXCOMM20 Function Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LP_FLEXCOMM20_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LP_FLEXCOMM20_F_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LP_FLEXCOMM20_F_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_SAI3_F_LPHINT_MASK    (0x100000U)
#define SLEEPCON1_LP_HINT0_SAI3_F_LPHINT_SHIFT   (20U)
/*! SAI3_F_LPHINT - SAI3 Function Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_SAI3_F_LPHINT(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_SAI3_F_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_SAI3_F_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LPI2C15_F_LPHINT_MASK (0x200000U)
#define SLEEPCON1_LP_HINT0_LPI2C15_F_LPHINT_SHIFT (21U)
/*! LPI2C15_F_LPHINT - LPI2C15 Function Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LPI2C15_F_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LPI2C15_F_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LPI2C15_F_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LPSPI14_F_LPHINT_MASK (0x400000U)
#define SLEEPCON1_LP_HINT0_LPSPI14_F_LPHINT_SHIFT (22U)
/*! LPSPI14_F_LPHINT - LPSPI14 Function Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LPSPI14_F_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LPSPI14_F_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LPSPI14_F_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_LPSPI16_F_LPHINT_MASK (0x800000U)
#define SLEEPCON1_LP_HINT0_LPSPI16_F_LPHINT_SHIFT (23U)
/*! LPSPI16_F_LPHINT - LPSPI16 Function Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_LPSPI16_F_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_LPSPI16_F_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_LPSPI16_F_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_FLEXIO_F_LPHINT_MASK  (0x1000000U)
#define SLEEPCON1_LP_HINT0_FLEXIO_F_LPHINT_SHIFT (24U)
/*! FLEXIO_F_LPHINT - FLEXIO Function Hint Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON1_LP_HINT0_FLEXIO_F_LPHINT(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_FLEXIO_F_LPHINT_SHIFT)) & SLEEPCON1_LP_HINT0_FLEXIO_F_LPHINT_MASK)

#define SLEEPCON1_LP_HINT0_NIC0_IDLE0_MASK       (0x2000000U)
#define SLEEPCON1_LP_HINT0_NIC0_IDLE0_SHIFT      (25U)
/*! NIC0_IDLE0 - NIC_MEDIA0 Idle Status 0
 *  0b0..Active
 *  0b1..Idle
 */
#define SLEEPCON1_LP_HINT0_NIC0_IDLE0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_NIC0_IDLE0_SHIFT)) & SLEEPCON1_LP_HINT0_NIC0_IDLE0_MASK)

#define SLEEPCON1_LP_HINT0_NIC0_IDLE1_MASK       (0x4000000U)
#define SLEEPCON1_LP_HINT0_NIC0_IDLE1_SHIFT      (26U)
/*! NIC0_IDLE1 - NIC_MEDIA0 Idle Status 1
 *  0b0..Active
 *  0b1..Idle
 */
#define SLEEPCON1_LP_HINT0_NIC0_IDLE1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_NIC0_IDLE1_SHIFT)) & SLEEPCON1_LP_HINT0_NIC0_IDLE1_MASK)

#define SLEEPCON1_LP_HINT0_NIC1_IDLE0_MASK       (0x8000000U)
#define SLEEPCON1_LP_HINT0_NIC1_IDLE0_SHIFT      (27U)
/*! NIC1_IDLE0 - NIC_MEDIA1 Idle Status 0
 *  0b0..Active
 *  0b1..Idle
 */
#define SLEEPCON1_LP_HINT0_NIC1_IDLE0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_NIC1_IDLE0_SHIFT)) & SLEEPCON1_LP_HINT0_NIC1_IDLE0_MASK)

#define SLEEPCON1_LP_HINT0_NIC1_IDLE1_MASK       (0x10000000U)
#define SLEEPCON1_LP_HINT0_NIC1_IDLE1_SHIFT      (28U)
/*! NIC1_IDLE1 - NIC_MEDIA1 Idle Status 1
 *  0b0..Active
 *  0b1..Idle
 */
#define SLEEPCON1_LP_HINT0_NIC1_IDLE1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_HINT0_NIC1_IDLE1_SHIFT)) & SLEEPCON1_LP_HINT0_NIC1_IDLE1_MASK)
/*! @} */

/*! @name LP_DENY0 - Low-Power Deny Status 0 */
/*! @{ */

#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM17_LPDENY_MASK (0x1U)
#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM17_LPDENY_SHIFT (0U)
/*! LP_FLEXCOMM17_LPDENY - LP_FLEXCOMM17 LPDENY Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM17_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_DENY0_LP_FLEXCOMM17_LPDENY_SHIFT)) & SLEEPCON1_LP_DENY0_LP_FLEXCOMM17_LPDENY_MASK)

#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM18_LPDENY_MASK (0x2U)
#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM18_LPDENY_SHIFT (1U)
/*! LP_FLEXCOMM18_LPDENY - LP_FLEXCOMM18 LPDENY Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM18_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_DENY0_LP_FLEXCOMM18_LPDENY_SHIFT)) & SLEEPCON1_LP_DENY0_LP_FLEXCOMM18_LPDENY_MASK)

#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM19_LPDENY_MASK (0x4U)
#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM19_LPDENY_SHIFT (2U)
/*! LP_FLEXCOMM19_LPDENY - LP_FLEXCOMM19 LPDENY Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM19_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_DENY0_LP_FLEXCOMM19_LPDENY_SHIFT)) & SLEEPCON1_LP_DENY0_LP_FLEXCOMM19_LPDENY_MASK)

#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM20_LPDENY_MASK (0x8U)
#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM20_LPDENY_SHIFT (3U)
/*! LP_FLEXCOMM20_LPDENY - LP_FLEXCOMM20 LPDENY Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON1_LP_DENY0_LP_FLEXCOMM20_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_DENY0_LP_FLEXCOMM20_LPDENY_SHIFT)) & SLEEPCON1_LP_DENY0_LP_FLEXCOMM20_LPDENY_MASK)

#define SLEEPCON1_LP_DENY0_LPSPI14_LPDENY_MASK   (0x10U)
#define SLEEPCON1_LP_DENY0_LPSPI14_LPDENY_SHIFT  (4U)
/*! LPSPI14_LPDENY - LPSPI14 LPDENY Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON1_LP_DENY0_LPSPI14_LPDENY(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_DENY0_LPSPI14_LPDENY_SHIFT)) & SLEEPCON1_LP_DENY0_LPSPI14_LPDENY_MASK)

#define SLEEPCON1_LP_DENY0_LPSPI16_LPDENY_MASK   (0x20U)
#define SLEEPCON1_LP_DENY0_LPSPI16_LPDENY_SHIFT  (5U)
/*! LPSPI16_LPDENY - LPSPI16 LPDENY Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON1_LP_DENY0_LPSPI16_LPDENY(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_DENY0_LPSPI16_LPDENY_SHIFT)) & SLEEPCON1_LP_DENY0_LPSPI16_LPDENY_MASK)

#define SLEEPCON1_LP_DENY0_FLEXIO_LPDENY_MASK    (0x40U)
#define SLEEPCON1_LP_DENY0_FLEXIO_LPDENY_SHIFT   (6U)
/*! FLEXIO_LPDENY - FLEXIO LPDENY Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON1_LP_DENY0_FLEXIO_LPDENY(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_DENY0_FLEXIO_LPDENY_SHIFT)) & SLEEPCON1_LP_DENY0_FLEXIO_LPDENY_MASK)

#define SLEEPCON1_LP_DENY0_LPI2C15_LPDENY_MASK   (0x80U)
#define SLEEPCON1_LP_DENY0_LPI2C15_LPDENY_SHIFT  (7U)
/*! LPI2C15_LPDENY - LPI2C15 LPDENY Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON1_LP_DENY0_LPI2C15_LPDENY(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON1_LP_DENY0_LPI2C15_LPDENY_SHIFT)) & SLEEPCON1_LP_DENY0_LPI2C15_LPDENY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SLEEPCON1_Register_Masks */


/*!
 * @}
 */ /* end of group SLEEPCON1_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_SLEEPCON1_H_ */

