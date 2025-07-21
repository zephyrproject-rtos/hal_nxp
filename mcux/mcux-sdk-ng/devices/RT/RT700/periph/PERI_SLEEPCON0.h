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
**         CMSIS Peripheral Access Layer for SLEEPCON0
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
 * @file PERI_SLEEPCON0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SLEEPCON0
 *
 * CMSIS Peripheral Access Layer for SLEEPCON0
 */

#if !defined(PERI_SLEEPCON0_H_)
#define PERI_SLEEPCON0_H_                        /**< Symbol preventing repeated inclusion */

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
   -- SLEEPCON0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SLEEPCON0_Peripheral_Access_Layer SLEEPCON0 Peripheral Access Layer
 * @{
 */

/** SLEEPCON0 - Register Layout Typedef */
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
  __IO uint32_t WAKEUPEN3;                         /**< Wakeup Enable 3, offset: 0x6C */
  __IO uint32_t WAKEUPEN4;                         /**< Wakeup Enable 4, offset: 0x70 */
       uint8_t RESERVED_4[44];
  __IO uint32_t WAKEUPEN0_SET;                     /**< Wakeup Enable 0 Set, offset: 0xA0 */
  __IO uint32_t WAKEUPEN1_SET;                     /**< Wakeup Enable 1 Set, offset: 0xA4 */
  __IO uint32_t WAKEUPEN2_SET;                     /**< Wakeup Enable 2 Set, offset: 0xA8 */
  __IO uint32_t WAKEUPEN3_SET;                     /**< Wakeup Enable 3 Set, offset: 0xAC */
  __IO uint32_t WAKEUPEN4_SET;                     /**< Wakeup Enable 4 Set, offset: 0xB0 */
       uint8_t RESERVED_5[76];
  __IO uint32_t WAKEUPEN0_CLR;                     /**< Wakeup Enable 0 Clear, offset: 0x100 */
  __IO uint32_t WAKEUPEN1_CLR;                     /**< Wakeup Enable 1 Clear, offset: 0x104 */
  __IO uint32_t WAKEUPEN2_CLR;                     /**< Wakeup Enable 2 Clear, offset: 0x108 */
  __IO uint32_t WAKEUPEN3_CLR;                     /**< Wakeup Enable 3 Clear, offset: 0x10C */
  __IO uint32_t WAKEUPEN4_CLR;                     /**< Wakeup Enable 4 Clear, offset: 0x110 */
       uint8_t RESERVED_6[80];
  __IO uint32_t PWRDOWN_WAIT;                      /**< Power Down Wait, offset: 0x164 */
       uint8_t RESERVED_7[40];
  __IO uint32_t HW_WAKE;                           /**< eDMA Wakeup Enable, offset: 0x190 */
  __O  uint32_t HW_WAKE_SET;                       /**< eDMA Wakeup Set, offset: 0x194 */
  __O  uint32_t HW_WAKE_CLR;                       /**< eDMA Wakeup Clear, offset: 0x198 */
       uint8_t RESERVED_8[4];
  __IO uint32_t SHARED_MASK0;                      /**< Shared Resources Mask, offset: 0x1A0 */
  __O  uint32_t SHARED_MASK0_SET;                  /**< Shared Resources Mask Set, offset: 0x1A4 */
  __O  uint32_t SHARED_MASK0_CLR;                  /**< Shared Resources Mask Clear, offset: 0x1A8 */
       uint8_t RESERVED_9[4];
  __IO uint32_t SHA_MED_CCTRL0;                    /**< Media Domain Shared Controller Low-power Control, offset: 0x1B0 */
  __IO uint32_t SHA_MED_TCTRL0;                    /**< Media Domain Shared Resources Target Low-power Control, offset: 0x1B4 */
       uint8_t RESERVED_10[4];
  __IO uint32_t SHA_SEN_TCTRL0;                    /**< Shared VDD1_SENSE Domain Targets Low-power Control, offset: 0x1BC */
  __IO uint32_t PRIVATE_CCTRL0;                    /**< Private Resources Controllers Low-power Control 0, offset: 0x1C0 */
  __IO uint32_t PRIVATE_TCTRL0;                    /**< Private Resources Targets Low-power Control 0, offset: 0x1C4 */
  __IO uint32_t PRIVATE_TCTRL1;                    /**< Private Resources Targets Low-power Control 1, offset: 0x1C8 */
  __IO uint32_t PRIVATE_TCTRL2;                    /**< Private Resources Targets Low-power Control 2, offset: 0x1CC */
  __I  uint32_t SHA_MED_CSTAT0;                    /**< Media Domain Shared Controllers Low-power Status, offset: 0x1D0 */
  __I  uint32_t SHA_MEDSEN_TSTAT0;                 /**< Media and Sense Domain Shared Targets Low-power Status, offset: 0x1D4 */
       uint8_t RESERVED_11[8];
  __I  uint32_t PRIVATE_CSTAT0;                    /**< Private Resources Controller Low-power Status, offset: 0x1E0 */
  __I  uint32_t PRIVATE_TSTAT0;                    /**< Private Resources Targets Low-power Status 0, offset: 0x1E4 */
  __I  uint32_t PRIVATE_TSTAT1;                    /**< Private Resources Targets Low-power Status 1, offset: 0x1E8 */
  __I  uint32_t LP_HINT0;                          /**< Low-Power Hints 0, offset: 0x1EC */
  __I  uint32_t LP_HINT1;                          /**< Low-Power Hints 1, offset: 0x1F0 */
  __I  uint32_t LP_DENY0;                          /**< Low-Power Request Deny Status 0, offset: 0x1F4 */
} SLEEPCON0_Type;

/* ----------------------------------------------------------------------------
   -- SLEEPCON0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SLEEPCON0_Register_Masks SLEEPCON0 Register Masks
 * @{
 */

/*! @name SLEEPCFG - Sleep Configuration */
/*! @{ */

#define SLEEPCON0_SLEEPCFG_COMP_MAINCLK_SHUTOFF_MASK (0x1U)
#define SLEEPCON0_SLEEPCFG_COMP_MAINCLK_SHUTOFF_SHIFT (0U)
/*! COMP_MAINCLK_SHUTOFF - VDD2_COMP Domain compute_main_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_SLEEPCFG_COMP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_COMP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_SLEEPCFG_COMP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_SLEEPCFG_SENSEP_MAINCLK_SHUTOFF_MASK (0x2U)
#define SLEEPCON0_SLEEPCFG_SENSEP_MAINCLK_SHUTOFF_SHIFT (1U)
/*! SENSEP_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_SLEEPCFG_SENSEP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_SENSEP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_SLEEPCFG_SENSEP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_SLEEPCFG_SENSES_MAINCLK_SHUTOFF_MASK (0x4U)
#define SLEEPCON0_SLEEPCFG_SENSES_MAINCLK_SHUTOFF_SHIFT (2U)
/*! SENSES_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk_1 Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_SLEEPCFG_SENSES_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_SENSES_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_SLEEPCFG_SENSES_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_SLEEPCFG_RAM0_CLK_SHUTOFF_MASK (0x8U)
#define SLEEPCON0_SLEEPCFG_RAM0_CLK_SHUTOFF_SHIFT (3U)
/*! RAM0_CLK_SHUTOFF - RAM_ARBITER0 common_ram_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_SLEEPCFG_RAM0_CLK_SHUTOFF(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_RAM0_CLK_SHUTOFF_SHIFT)) & SLEEPCON0_SLEEPCFG_RAM0_CLK_SHUTOFF_MASK)

#define SLEEPCON0_SLEEPCFG_RAM1_CLK_SHUTOFF_MASK (0x10U)
#define SLEEPCON0_SLEEPCFG_RAM1_CLK_SHUTOFF_SHIFT (4U)
/*! RAM1_CLK_SHUTOFF - RAM_ARBITER1 sense_ram_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_SLEEPCFG_RAM1_CLK_SHUTOFF(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_RAM1_CLK_SHUTOFF_SHIFT)) & SLEEPCON0_SLEEPCFG_RAM1_CLK_SHUTOFF_MASK)

#define SLEEPCON0_SLEEPCFG_COMN_MAINCLK_SHUTOFF_MASK (0x20U)
#define SLEEPCON0_SLEEPCFG_COMN_MAINCLK_SHUTOFF_SHIFT (5U)
/*! COMN_MAINCLK_SHUTOFF - VDDN_COM Domain common_vddn_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_SLEEPCFG_COMN_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_COMN_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_SLEEPCFG_COMN_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_SLEEPCFG_MEDIA_MAINCLK_SHUTOFF_MASK (0x40U)
#define SLEEPCON0_SLEEPCFG_MEDIA_MAINCLK_SHUTOFF_SHIFT (6U)
/*! MEDIA_MAINCLK_SHUTOFF - VDD2_MEDIA and VDDN_MEDIA Domains media_main_clk and media_vddn_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_SLEEPCFG_MEDIA_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_MEDIA_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_SLEEPCFG_MEDIA_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_SLEEPCFG_XTAL_PD_MASK          (0x80U)
#define SLEEPCON0_SLEEPCFG_XTAL_PD_SHIFT         (7U)
/*! XTAL_PD - Xtal Oscillator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_SLEEPCFG_XTAL_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_XTAL_PD_SHIFT)) & SLEEPCON0_SLEEPCFG_XTAL_PD_MASK)

#define SLEEPCON0_SLEEPCFG_FRO0_PD_MASK          (0x100U)
#define SLEEPCON0_SLEEPCFG_FRO0_PD_SHIFT         (8U)
/*! FRO0_PD - FRO0 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_SLEEPCFG_FRO0_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_FRO0_PD_SHIFT)) & SLEEPCON0_SLEEPCFG_FRO0_PD_MASK)

#define SLEEPCON0_SLEEPCFG_FRO1_PD_MASK          (0x200U)
#define SLEEPCON0_SLEEPCFG_FRO1_PD_SHIFT         (9U)
/*! FRO1_PD - FRO1 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_SLEEPCFG_FRO1_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_FRO1_PD_SHIFT)) & SLEEPCON0_SLEEPCFG_FRO1_PD_MASK)

#define SLEEPCON0_SLEEPCFG_FRO2_PD_MASK          (0x400U)
#define SLEEPCON0_SLEEPCFG_FRO2_PD_SHIFT         (10U)
/*! FRO2_PD - FRO2 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_SLEEPCFG_FRO2_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_FRO2_PD_SHIFT)) & SLEEPCON0_SLEEPCFG_FRO2_PD_MASK)

#define SLEEPCON0_SLEEPCFG_LPOSC_PD_MASK         (0x800U)
#define SLEEPCON0_SLEEPCFG_LPOSC_PD_SHIFT        (11U)
/*! LPOSC_PD - LPOSC Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_SLEEPCFG_LPOSC_PD(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_LPOSC_PD_SHIFT)) & SLEEPCON0_SLEEPCFG_LPOSC_PD_MASK)

#define SLEEPCON0_SLEEPCFG_PLLANA_PD_MASK        (0x1000U)
#define SLEEPCON0_SLEEPCFG_PLLANA_PD_SHIFT       (12U)
/*! PLLANA_PD - Main PLL Analog Function Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_SLEEPCFG_PLLANA_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_PLLANA_PD_SHIFT)) & SLEEPCON0_SLEEPCFG_PLLANA_PD_MASK)

#define SLEEPCON0_SLEEPCFG_PLLLDO_PD_MASK        (0x2000U)
#define SLEEPCON0_SLEEPCFG_PLLLDO_PD_SHIFT       (13U)
/*! PLLLDO_PD - Main PLL Internal Regulator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_SLEEPCFG_PLLLDO_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_PLLLDO_PD_SHIFT)) & SLEEPCON0_SLEEPCFG_PLLLDO_PD_MASK)

#define SLEEPCON0_SLEEPCFG_AUDPLLANA_PD_MASK     (0x4000U)
#define SLEEPCON0_SLEEPCFG_AUDPLLANA_PD_SHIFT    (14U)
/*! AUDPLLANA_PD - Audio PLL Analog Function Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_SLEEPCFG_AUDPLLANA_PD(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_AUDPLLANA_PD_SHIFT)) & SLEEPCON0_SLEEPCFG_AUDPLLANA_PD_MASK)

#define SLEEPCON0_SLEEPCFG_AUDPLLLDO_PD_MASK     (0x8000U)
#define SLEEPCON0_SLEEPCFG_AUDPLLLDO_PD_SHIFT    (15U)
/*! AUDPLLLDO_PD - Audio PLL Internal Regulator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_SLEEPCFG_AUDPLLLDO_PD(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_AUDPLLLDO_PD_SHIFT)) & SLEEPCON0_SLEEPCFG_AUDPLLLDO_PD_MASK)

#define SLEEPCON0_SLEEPCFG_ADC0_PD_MASK          (0x10000U)
#define SLEEPCON0_SLEEPCFG_ADC0_PD_SHIFT         (16U)
/*! ADC0_PD - ADC0 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_SLEEPCFG_ADC0_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_ADC0_PD_SHIFT)) & SLEEPCON0_SLEEPCFG_ADC0_PD_MASK)

#define SLEEPCON0_SLEEPCFG_FRO0_GATE_MASK        (0x20000000U)
#define SLEEPCON0_SLEEPCFG_FRO0_GATE_SHIFT       (29U)
/*! FRO0_GATE - FRO0 Gating
 *  0b0..Removes gating
 *  0b1..Applies gating
 */
#define SLEEPCON0_SLEEPCFG_FRO0_GATE(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_FRO0_GATE_SHIFT)) & SLEEPCON0_SLEEPCFG_FRO0_GATE_MASK)

#define SLEEPCON0_SLEEPCFG_FRO2_GATE_MASK        (0x80000000U)
#define SLEEPCON0_SLEEPCFG_FRO2_GATE_SHIFT       (31U)
/*! FRO2_GATE - FRO2 Gating
 *  0b0..Removes gating
 *  0b1..Applies gating
 */
#define SLEEPCON0_SLEEPCFG_FRO2_GATE(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SLEEPCFG_FRO2_GATE_SHIFT)) & SLEEPCON0_SLEEPCFG_FRO2_GATE_MASK)
/*! @} */

/*! @name RUNCFG - Run Configuration */
/*! @{ */

#define SLEEPCON0_RUNCFG_COMP_MAINCLK_SHUTOFF_MASK (0x1U)
#define SLEEPCON0_RUNCFG_COMP_MAINCLK_SHUTOFF_SHIFT (0U)
/*! COMP_MAINCLK_SHUTOFF - VDD2_COMP Domain compute_main_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_RUNCFG_COMP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_COMP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_COMP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_SENSEP_MAINCLK_SHUTOFF_MASK (0x2U)
#define SLEEPCON0_RUNCFG_SENSEP_MAINCLK_SHUTOFF_SHIFT (1U)
/*! SENSEP_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_RUNCFG_SENSEP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SENSEP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_SENSEP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_SENSES_MAINCLK_SHUTOFF_MASK (0x4U)
#define SLEEPCON0_RUNCFG_SENSES_MAINCLK_SHUTOFF_SHIFT (2U)
/*! SENSES_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk_1 Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_RUNCFG_SENSES_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SENSES_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_SENSES_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_RAM0_CLK_SHUTOFF_MASK   (0x8U)
#define SLEEPCON0_RUNCFG_RAM0_CLK_SHUTOFF_SHIFT  (3U)
/*! RAM0_CLK_SHUTOFF - RAM_ARBITER0 common_ram_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_RUNCFG_RAM0_CLK_SHUTOFF(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_RAM0_CLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_RAM0_CLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_RAM1_CLK_SHUTOFF_MASK   (0x10U)
#define SLEEPCON0_RUNCFG_RAM1_CLK_SHUTOFF_SHIFT  (4U)
/*! RAM1_CLK_SHUTOFF - RAM_ARBITER1 sense_ram_clk shut off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_RUNCFG_RAM1_CLK_SHUTOFF(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_RAM1_CLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_RAM1_CLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_COMN_MAINCLK_SHUTOFF_MASK (0x20U)
#define SLEEPCON0_RUNCFG_COMN_MAINCLK_SHUTOFF_SHIFT (5U)
/*! COMN_MAINCLK_SHUTOFF - VDDN_COM Domain common_vddn_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_RUNCFG_COMN_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_COMN_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_COMN_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_MEDIA_MAINCLK_SHUTOFF_MASK (0x40U)
#define SLEEPCON0_RUNCFG_MEDIA_MAINCLK_SHUTOFF_SHIFT (6U)
/*! MEDIA_MAINCLK_SHUTOFF - VDD2_MEDIA and VDDN_MEDIA Domains media_main_clk and media_vddn_clk Shut Off
 *  0b0..Turns on
 *  0b1..Turns off
 */
#define SLEEPCON0_RUNCFG_MEDIA_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_MEDIA_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_MEDIA_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_XTAL_PD_MASK            (0x80U)
#define SLEEPCON0_RUNCFG_XTAL_PD_SHIFT           (7U)
/*! XTAL_PD - Xtal Oscillator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_RUNCFG_XTAL_PD(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_XTAL_PD_SHIFT)) & SLEEPCON0_RUNCFG_XTAL_PD_MASK)

#define SLEEPCON0_RUNCFG_FRO0_PD_MASK            (0x100U)
#define SLEEPCON0_RUNCFG_FRO0_PD_SHIFT           (8U)
/*! FRO0_PD - FRO0 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_RUNCFG_FRO0_PD(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_FRO0_PD_SHIFT)) & SLEEPCON0_RUNCFG_FRO0_PD_MASK)

#define SLEEPCON0_RUNCFG_FRO1_PD_MASK            (0x200U)
#define SLEEPCON0_RUNCFG_FRO1_PD_SHIFT           (9U)
/*! FRO1_PD - FRO1 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_RUNCFG_FRO1_PD(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_FRO1_PD_SHIFT)) & SLEEPCON0_RUNCFG_FRO1_PD_MASK)

#define SLEEPCON0_RUNCFG_FRO2_PD_MASK            (0x400U)
#define SLEEPCON0_RUNCFG_FRO2_PD_SHIFT           (10U)
/*! FRO2_PD - FRO2 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_RUNCFG_FRO2_PD(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_FRO2_PD_SHIFT)) & SLEEPCON0_RUNCFG_FRO2_PD_MASK)

#define SLEEPCON0_RUNCFG_LPOSC_PD_MASK           (0x800U)
#define SLEEPCON0_RUNCFG_LPOSC_PD_SHIFT          (11U)
/*! LPOSC_PD - LPOSC Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_RUNCFG_LPOSC_PD(x)             (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_LPOSC_PD_SHIFT)) & SLEEPCON0_RUNCFG_LPOSC_PD_MASK)

#define SLEEPCON0_RUNCFG_PLLANA_PD_MASK          (0x1000U)
#define SLEEPCON0_RUNCFG_PLLANA_PD_SHIFT         (12U)
/*! PLLANA_PD - Main PLL Analog Function Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_RUNCFG_PLLANA_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_PLLANA_PD_SHIFT)) & SLEEPCON0_RUNCFG_PLLANA_PD_MASK)

#define SLEEPCON0_RUNCFG_PLLLDO_PD_MASK          (0x2000U)
#define SLEEPCON0_RUNCFG_PLLLDO_PD_SHIFT         (13U)
/*! PLLLDO_PD - Main PLL Internal Regulator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_RUNCFG_PLLLDO_PD(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_PLLLDO_PD_SHIFT)) & SLEEPCON0_RUNCFG_PLLLDO_PD_MASK)

#define SLEEPCON0_RUNCFG_AUDPLLANA_PD_MASK       (0x4000U)
#define SLEEPCON0_RUNCFG_AUDPLLANA_PD_SHIFT      (14U)
/*! AUDPLLANA_PD - Audio PLL Analog Function Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_RUNCFG_AUDPLLANA_PD(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_AUDPLLANA_PD_SHIFT)) & SLEEPCON0_RUNCFG_AUDPLLANA_PD_MASK)

#define SLEEPCON0_RUNCFG_AUDPLLLDO_PD_MASK       (0x8000U)
#define SLEEPCON0_RUNCFG_AUDPLLLDO_PD_SHIFT      (15U)
/*! AUDPLLLDO_PD - Audio PLL Internal Regulator Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_RUNCFG_AUDPLLLDO_PD(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_AUDPLLLDO_PD_SHIFT)) & SLEEPCON0_RUNCFG_AUDPLLLDO_PD_MASK)

#define SLEEPCON0_RUNCFG_ADC0_PD_MASK            (0x10000U)
#define SLEEPCON0_RUNCFG_ADC0_PD_SHIFT           (16U)
/*! ADC0_PD - ADC0 Power Down
 *  0b0..Powers on
 *  0b1..Powers down
 */
#define SLEEPCON0_RUNCFG_ADC0_PD(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_ADC0_PD_SHIFT)) & SLEEPCON0_RUNCFG_ADC0_PD_MASK)

#define SLEEPCON0_RUNCFG_FRO0_GATE_MASK          (0x20000000U)
#define SLEEPCON0_RUNCFG_FRO0_GATE_SHIFT         (29U)
/*! FRO0_GATE - FRO0 Gating
 *  0b0..Removes gating
 *  0b1..Applies gating
 */
#define SLEEPCON0_RUNCFG_FRO0_GATE(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_FRO0_GATE_SHIFT)) & SLEEPCON0_RUNCFG_FRO0_GATE_MASK)

#define SLEEPCON0_RUNCFG_FRO2_GATE_MASK          (0x80000000U)
#define SLEEPCON0_RUNCFG_FRO2_GATE_SHIFT         (31U)
/*! FRO2_GATE - FRO2 Gating
 *  0b0..Removes gating
 *  0b1..Applies gating
 */
#define SLEEPCON0_RUNCFG_FRO2_GATE(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_FRO2_GATE_SHIFT)) & SLEEPCON0_RUNCFG_FRO2_GATE_MASK)
/*! @} */

/*! @name RUNCFG_SET - RUNCFG Set */
/*! @{ */

#define SLEEPCON0_RUNCFG_SET_COMP_MAINCLK_SHUTOFF_MASK (0x1U)
#define SLEEPCON0_RUNCFG_SET_COMP_MAINCLK_SHUTOFF_SHIFT (0U)
/*! COMP_MAINCLK_SHUTOFF - VDD2_COMP Domain compute_main_clk Shut off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_COMP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_COMP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_SET_COMP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_SET_SENSEP_MAINCLK_SHUTOFF_MASK (0x2U)
#define SLEEPCON0_RUNCFG_SET_SENSEP_MAINCLK_SHUTOFF_SHIFT (1U)
/*! SENSEP_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_SENSEP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_SENSEP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_SET_SENSEP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_SET_SENSES_MAINCLK_SHUTOFF_MASK (0x4U)
#define SLEEPCON0_RUNCFG_SET_SENSES_MAINCLK_SHUTOFF_SHIFT (2U)
/*! SENSES_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk_1 Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_SENSES_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_SENSES_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_SET_SENSES_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_SET_RAM0_CLK_SHUTOFF_MASK (0x8U)
#define SLEEPCON0_RUNCFG_SET_RAM0_CLK_SHUTOFF_SHIFT (3U)
/*! RAM0_CLK_SHUTOFF - RAM_ARBITER0 common_ram_clk Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_RAM0_CLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_RAM0_CLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_SET_RAM0_CLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_SET_RAM1_CLK_SHUTOFF_MASK (0x10U)
#define SLEEPCON0_RUNCFG_SET_RAM1_CLK_SHUTOFF_SHIFT (4U)
/*! RAM1_CLK_SHUTOFF - RAM_ARBITER1 sense_ram_clk Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_RAM1_CLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_RAM1_CLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_SET_RAM1_CLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_SET_COMN_MAINCLK_SHUTOFF_MASK (0x20U)
#define SLEEPCON0_RUNCFG_SET_COMN_MAINCLK_SHUTOFF_SHIFT (5U)
/*! COMN_MAINCLK_SHUTOFF - VDDN_COM Domain common_vddn_clk Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_COMN_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_COMN_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_SET_COMN_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_SET_MEDIA_MAINCLK_SHUTOFF_MASK (0x40U)
#define SLEEPCON0_RUNCFG_SET_MEDIA_MAINCLK_SHUTOFF_SHIFT (6U)
/*! MEDIA_MAINCLK_SHUTOFF - VDD2_MEDIA and VDDN_MEDIA Domains media_main_clk and media_vddn_clk Shut Off Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_MEDIA_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_MEDIA_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_SET_MEDIA_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_SET_XTAL_PD_MASK        (0x80U)
#define SLEEPCON0_RUNCFG_SET_XTAL_PD_SHIFT       (7U)
/*! XTAL_PD - Xtal Oscillator Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_XTAL_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_XTAL_PD_SHIFT)) & SLEEPCON0_RUNCFG_SET_XTAL_PD_MASK)

#define SLEEPCON0_RUNCFG_SET_FRO0_PD_MASK        (0x100U)
#define SLEEPCON0_RUNCFG_SET_FRO0_PD_SHIFT       (8U)
/*! FRO0_PD - FRO0 Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_FRO0_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_FRO0_PD_SHIFT)) & SLEEPCON0_RUNCFG_SET_FRO0_PD_MASK)

#define SLEEPCON0_RUNCFG_SET_FRO1_PD_MASK        (0x200U)
#define SLEEPCON0_RUNCFG_SET_FRO1_PD_SHIFT       (9U)
/*! FRO1_PD - FRO1 Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_FRO1_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_FRO1_PD_SHIFT)) & SLEEPCON0_RUNCFG_SET_FRO1_PD_MASK)

#define SLEEPCON0_RUNCFG_SET_FRO2_PD_MASK        (0x400U)
#define SLEEPCON0_RUNCFG_SET_FRO2_PD_SHIFT       (10U)
/*! FRO2_PD - FRO2 Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_FRO2_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_FRO2_PD_SHIFT)) & SLEEPCON0_RUNCFG_SET_FRO2_PD_MASK)

#define SLEEPCON0_RUNCFG_SET_LPOSC_PD_MASK       (0x800U)
#define SLEEPCON0_RUNCFG_SET_LPOSC_PD_SHIFT      (11U)
/*! LPOSC_PD - LPOSC Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_LPOSC_PD(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_LPOSC_PD_SHIFT)) & SLEEPCON0_RUNCFG_SET_LPOSC_PD_MASK)

#define SLEEPCON0_RUNCFG_SET_PLLANA_PD_MASK      (0x1000U)
#define SLEEPCON0_RUNCFG_SET_PLLANA_PD_SHIFT     (12U)
/*! PLLANA_PD - Main PLL Analog Function Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_PLLANA_PD(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_PLLANA_PD_SHIFT)) & SLEEPCON0_RUNCFG_SET_PLLANA_PD_MASK)

#define SLEEPCON0_RUNCFG_SET_PLLLDO_PD_MASK      (0x2000U)
#define SLEEPCON0_RUNCFG_SET_PLLLDO_PD_SHIFT     (13U)
/*! PLLLDO_PD - Main PLL Internal Regulator Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_PLLLDO_PD(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_PLLLDO_PD_SHIFT)) & SLEEPCON0_RUNCFG_SET_PLLLDO_PD_MASK)

#define SLEEPCON0_RUNCFG_SET_AUDPLLANA_PD_MASK   (0x4000U)
#define SLEEPCON0_RUNCFG_SET_AUDPLLANA_PD_SHIFT  (14U)
/*! AUDPLLANA_PD - Audio PLL Analog Function Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_AUDPLLANA_PD(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_AUDPLLANA_PD_SHIFT)) & SLEEPCON0_RUNCFG_SET_AUDPLLANA_PD_MASK)

#define SLEEPCON0_RUNCFG_SET_AUDPLLLDO_PD_MASK   (0x8000U)
#define SLEEPCON0_RUNCFG_SET_AUDPLLLDO_PD_SHIFT  (15U)
/*! AUDPLLLDO_PD - Audio PLL Internal Regulator Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_AUDPLLLDO_PD(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_AUDPLLLDO_PD_SHIFT)) & SLEEPCON0_RUNCFG_SET_AUDPLLLDO_PD_MASK)

#define SLEEPCON0_RUNCFG_SET_ADC0_PD_MASK        (0x10000U)
#define SLEEPCON0_RUNCFG_SET_ADC0_PD_SHIFT       (16U)
/*! ADC0_PD - ADC0 Power Down Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_ADC0_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_ADC0_PD_SHIFT)) & SLEEPCON0_RUNCFG_SET_ADC0_PD_MASK)

#define SLEEPCON0_RUNCFG_SET_FRO0_GATE_MASK      (0x20000000U)
#define SLEEPCON0_RUNCFG_SET_FRO0_GATE_SHIFT     (29U)
/*! FRO0_GATE - FRO0 Gating Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_FRO0_GATE(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_FRO0_GATE_SHIFT)) & SLEEPCON0_RUNCFG_SET_FRO0_GATE_MASK)

#define SLEEPCON0_RUNCFG_SET_FRO2_GATE_MASK      (0x80000000U)
#define SLEEPCON0_RUNCFG_SET_FRO2_GATE_SHIFT     (31U)
/*! FRO2_GATE - FRO2 Gating Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_RUNCFG_SET_FRO2_GATE(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_SET_FRO2_GATE_SHIFT)) & SLEEPCON0_RUNCFG_SET_FRO2_GATE_MASK)
/*! @} */

/*! @name RUNCFG_CLR - RUNCFG Clear */
/*! @{ */

#define SLEEPCON0_RUNCFG_CLR_COMP_MAINCLK_SHUTOFF_MASK (0x1U)
#define SLEEPCON0_RUNCFG_CLR_COMP_MAINCLK_SHUTOFF_SHIFT (0U)
/*! COMP_MAINCLK_SHUTOFF - VDD2_COMP Domain compute_main_clk Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_COMP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_COMP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_CLR_COMP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_CLR_SENSEP_MAINCLK_SHUTOFF_MASK (0x2U)
#define SLEEPCON0_RUNCFG_CLR_SENSEP_MAINCLK_SHUTOFF_SHIFT (1U)
/*! SENSEP_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_SENSEP_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_SENSEP_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_CLR_SENSEP_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_CLR_SENSES_MAINCLK_SHUTOFF_MASK (0x4U)
#define SLEEPCON0_RUNCFG_CLR_SENSES_MAINCLK_SHUTOFF_SHIFT (2U)
/*! SENSES_MAINCLK_SHUTOFF - VDD1_SENSE Domain sense_main_clk_1 Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_SENSES_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_SENSES_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_CLR_SENSES_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_CLR_RAM0_CLK_SHUTOFF_MASK (0x8U)
#define SLEEPCON0_RUNCFG_CLR_RAM0_CLK_SHUTOFF_SHIFT (3U)
/*! RAM0_CLK_SHUTOFF - RAM_ARBITER0 common_ram_clk Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_RAM0_CLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_RAM0_CLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_CLR_RAM0_CLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_CLR_RAM1_CLK_SHUTOFF_MASK (0x10U)
#define SLEEPCON0_RUNCFG_CLR_RAM1_CLK_SHUTOFF_SHIFT (4U)
/*! RAM1_CLK_SHUTOFF - RAM_ARBITER1 sense_ram_clk Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_RAM1_CLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_RAM1_CLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_CLR_RAM1_CLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_CLR_COMN_MAINCLK_SHUTOFF_MASK (0x20U)
#define SLEEPCON0_RUNCFG_CLR_COMN_MAINCLK_SHUTOFF_SHIFT (5U)
/*! COMN_MAINCLK_SHUTOFF - VDDN_COM Domain common_vddn_clk Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_COMN_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_COMN_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_CLR_COMN_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_CLR_MEDIA_MAINCLK_SHUTOFF_MASK (0x40U)
#define SLEEPCON0_RUNCFG_CLR_MEDIA_MAINCLK_SHUTOFF_SHIFT (6U)
/*! MEDIA_MAINCLK_SHUTOFF - VDD2_MEDIA and VDDN_MEDIA Domains media_main_clk and media_vddn_clk Shut Off Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_MEDIA_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_MEDIA_MAINCLK_SHUTOFF_SHIFT)) & SLEEPCON0_RUNCFG_CLR_MEDIA_MAINCLK_SHUTOFF_MASK)

#define SLEEPCON0_RUNCFG_CLR_XTAL_PD_MASK        (0x80U)
#define SLEEPCON0_RUNCFG_CLR_XTAL_PD_SHIFT       (7U)
/*! XTAL_PD - Xtal Oscillator Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_XTAL_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_XTAL_PD_SHIFT)) & SLEEPCON0_RUNCFG_CLR_XTAL_PD_MASK)

#define SLEEPCON0_RUNCFG_CLR_FRO0_PD_MASK        (0x100U)
#define SLEEPCON0_RUNCFG_CLR_FRO0_PD_SHIFT       (8U)
/*! FRO0_PD - FRO0 Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_FRO0_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_FRO0_PD_SHIFT)) & SLEEPCON0_RUNCFG_CLR_FRO0_PD_MASK)

#define SLEEPCON0_RUNCFG_CLR_FRO1_PD_MASK        (0x200U)
#define SLEEPCON0_RUNCFG_CLR_FRO1_PD_SHIFT       (9U)
/*! FRO1_PD - FRO1 Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_FRO1_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_FRO1_PD_SHIFT)) & SLEEPCON0_RUNCFG_CLR_FRO1_PD_MASK)

#define SLEEPCON0_RUNCFG_CLR_FRO2_PD_MASK        (0x400U)
#define SLEEPCON0_RUNCFG_CLR_FRO2_PD_SHIFT       (10U)
/*! FRO2_PD - FRO2 Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_FRO2_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_FRO2_PD_SHIFT)) & SLEEPCON0_RUNCFG_CLR_FRO2_PD_MASK)

#define SLEEPCON0_RUNCFG_CLR_LPOSC_PD_MASK       (0x800U)
#define SLEEPCON0_RUNCFG_CLR_LPOSC_PD_SHIFT      (11U)
/*! LPOSC_PD - LPOSC Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_LPOSC_PD(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_LPOSC_PD_SHIFT)) & SLEEPCON0_RUNCFG_CLR_LPOSC_PD_MASK)

#define SLEEPCON0_RUNCFG_CLR_PLLANA_PD_MASK      (0x1000U)
#define SLEEPCON0_RUNCFG_CLR_PLLANA_PD_SHIFT     (12U)
/*! PLLANA_PD - Main PLL Analog Function Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_PLLANA_PD(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_PLLANA_PD_SHIFT)) & SLEEPCON0_RUNCFG_CLR_PLLANA_PD_MASK)

#define SLEEPCON0_RUNCFG_CLR_PLLLDO_PD_MASK      (0x2000U)
#define SLEEPCON0_RUNCFG_CLR_PLLLDO_PD_SHIFT     (13U)
/*! PLLLDO_PD - Main PLL Internal Regulator Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_PLLLDO_PD(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_PLLLDO_PD_SHIFT)) & SLEEPCON0_RUNCFG_CLR_PLLLDO_PD_MASK)

#define SLEEPCON0_RUNCFG_CLR_AUDPLLANA_PD_MASK   (0x4000U)
#define SLEEPCON0_RUNCFG_CLR_AUDPLLANA_PD_SHIFT  (14U)
/*! AUDPLLANA_PD - Audio PLL Analog Function Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_AUDPLLANA_PD(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_AUDPLLANA_PD_SHIFT)) & SLEEPCON0_RUNCFG_CLR_AUDPLLANA_PD_MASK)

#define SLEEPCON0_RUNCFG_CLR_AUDPLLLDO_PD_MASK   (0x8000U)
#define SLEEPCON0_RUNCFG_CLR_AUDPLLLDO_PD_SHIFT  (15U)
/*! AUDPLLLDO_PD - Audio PLL Internal Regulator Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_AUDPLLLDO_PD(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_AUDPLLLDO_PD_SHIFT)) & SLEEPCON0_RUNCFG_CLR_AUDPLLLDO_PD_MASK)

#define SLEEPCON0_RUNCFG_CLR_ADC0_PD_MASK        (0x10000U)
#define SLEEPCON0_RUNCFG_CLR_ADC0_PD_SHIFT       (16U)
/*! ADC0_PD - ADC0 Power Down Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_ADC0_PD(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_ADC0_PD_SHIFT)) & SLEEPCON0_RUNCFG_CLR_ADC0_PD_MASK)

#define SLEEPCON0_RUNCFG_CLR_FRO0_GATE_MASK      (0x20000000U)
#define SLEEPCON0_RUNCFG_CLR_FRO0_GATE_SHIFT     (29U)
/*! FRO0_GATE - FRO0 Gating Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_FRO0_GATE(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_FRO0_GATE_SHIFT)) & SLEEPCON0_RUNCFG_CLR_FRO0_GATE_MASK)

#define SLEEPCON0_RUNCFG_CLR_FRO2_GATE_MASK      (0x80000000U)
#define SLEEPCON0_RUNCFG_CLR_FRO2_GATE_SHIFT     (31U)
/*! FRO2_GATE - FRO2 Gating Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_RUNCFG_CLR_FRO2_GATE(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_RUNCFG_CLR_FRO2_GATE_SHIFT)) & SLEEPCON0_RUNCFG_CLR_FRO2_GATE_MASK)
/*! @} */

/*! @name WAKEUPEN0 - Wakeup Enable 0 */
/*! @{ */

#define SLEEPCON0_WAKEUPEN0_UTICK0_MASK          (0x2U)
#define SLEEPCON0_WAKEUPEN0_UTICK0_SHIFT         (1U)
/*! UTICK0 - UTICK0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_UTICK0(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_UTICK0_SHIFT)) & SLEEPCON0_WAKEUPEN0_UTICK0_MASK)

#define SLEEPCON0_WAKEUPEN0_CTIMER0_MASK         (0x8U)
#define SLEEPCON0_WAKEUPEN0_CTIMER0_SHIFT        (3U)
/*! CTIMER0 - CTIMER0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_CTIMER0(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CTIMER0_SHIFT)) & SLEEPCON0_WAKEUPEN0_CTIMER0_MASK)

#define SLEEPCON0_WAKEUPEN0_CTIMER1_MASK         (0x10U)
#define SLEEPCON0_WAKEUPEN0_CTIMER1_SHIFT        (4U)
/*! CTIMER1 - CTIMER1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_CTIMER1(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CTIMER1_SHIFT)) & SLEEPCON0_WAKEUPEN0_CTIMER1_MASK)

#define SLEEPCON0_WAKEUPEN0_CTIMER3_MASK         (0x40U)
#define SLEEPCON0_WAKEUPEN0_CTIMER3_SHIFT        (6U)
/*! CTIMER3 - CTIMER3 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_CTIMER3(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CTIMER3_SHIFT)) & SLEEPCON0_WAKEUPEN0_CTIMER3_MASK)

#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM0_MASK    (0x80U)
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM0_SHIFT   (7U)
/*! LP_FLEXCOMM0 - LP_FLEXCOMM0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM0(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM0_SHIFT)) & SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM0_MASK)

#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM1_MASK    (0x100U)
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM1_SHIFT   (8U)
/*! LP_FLEXCOMM1 - LP_FLEXCOMM1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM1(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM1_SHIFT)) & SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM1_MASK)

#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM2_MASK    (0x200U)
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM2_SHIFT   (9U)
/*! LP_FLEXCOMM2 - LP_FLEXCOMM2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM2(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM2_SHIFT)) & SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM2_MASK)

#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM3_MASK    (0x400U)
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM3_SHIFT   (10U)
/*! LP_FLEXCOMM3 - LP_FLEXCOMM3 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM3(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM3_SHIFT)) & SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM3_MASK)

#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM4_MASK    (0x800U)
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM4_SHIFT   (11U)
/*! LP_FLEXCOMM4 - LP_FLEXCOMM4 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM4(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM4_SHIFT)) & SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM4_MASK)

#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM5_MASK    (0x1000U)
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM5_SHIFT   (12U)
/*! LP_FLEXCOMM5 - LP_FLEXCOMM5 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM5(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM5_SHIFT)) & SLEEPCON0_WAKEUPEN0_LP_FLEXCOMM5_MASK)

#define SLEEPCON0_WAKEUPEN0_LPSPI14_MASK         (0x2000U)
#define SLEEPCON0_WAKEUPEN0_LPSPI14_SHIFT        (13U)
/*! LPSPI14 - LPSPI14 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_LPSPI14(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_LPSPI14_SHIFT)) & SLEEPCON0_WAKEUPEN0_LPSPI14_MASK)

#define SLEEPCON0_WAKEUPEN0_LPI2C15_MASK         (0x4000U)
#define SLEEPCON0_WAKEUPEN0_LPI2C15_SHIFT        (14U)
/*! LPI2C15 - LPI2C15 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_LPI2C15(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_LPI2C15_SHIFT)) & SLEEPCON0_WAKEUPEN0_LPI2C15_MASK)

#define SLEEPCON0_WAKEUPEN0_ADC0_MASK            (0x8000U)
#define SLEEPCON0_WAKEUPEN0_ADC0_SHIFT           (15U)
/*! ADC0 - ADC0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_ADC0(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_ADC0_SHIFT)) & SLEEPCON0_WAKEUPEN0_ADC0_MASK)

#define SLEEPCON0_WAKEUPEN0_ACMP0_MASK           (0x20000U)
#define SLEEPCON0_WAKEUPEN0_ACMP0_SHIFT          (17U)
/*! ACMP0 - ACMP0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_ACMP0(x)             (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_ACMP0_SHIFT)) & SLEEPCON0_WAKEUPEN0_ACMP0_MASK)

#define SLEEPCON0_WAKEUPEN0_MICFIL_RD_ERR_MASK   (0x40000U)
#define SLEEPCON0_WAKEUPEN0_MICFIL_RD_ERR_SHIFT  (18U)
/*! MICFIL_RD_ERR - MICFIL Read Data Error Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_MICFIL_RD_ERR(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_MICFIL_RD_ERR_SHIFT)) & SLEEPCON0_WAKEUPEN0_MICFIL_RD_ERR_MASK)

#define SLEEPCON0_WAKEUPEN0_MICFIL_WKUP_MASK     (0x80000U)
#define SLEEPCON0_WAKEUPEN0_MICFIL_WKUP_SHIFT    (19U)
/*! MICFIL_WKUP - MICFIL Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_MICFIL_WKUP(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_MICFIL_WKUP_SHIFT)) & SLEEPCON0_WAKEUPEN0_MICFIL_WKUP_MASK)

#define SLEEPCON0_WAKEUPEN0_RTC0_ALARM_MASK      (0x4000000U)
#define SLEEPCON0_WAKEUPEN0_RTC0_ALARM_SHIFT     (26U)
/*! RTC0_ALARM - RTC0_ALARM Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_RTC0_ALARM(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_RTC0_ALARM_SHIFT)) & SLEEPCON0_WAKEUPEN0_RTC0_ALARM_MASK)

#define SLEEPCON0_WAKEUPEN0_RTC0_WKUP_MASK       (0x8000000U)
#define SLEEPCON0_WAKEUPEN0_RTC0_WKUP_SHIFT      (27U)
/*! RTC0_WKUP - RTC0_WKUP Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_RTC0_WKUP(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_RTC0_WKUP_SHIFT)) & SLEEPCON0_WAKEUPEN0_RTC0_WKUP_MASK)

#define SLEEPCON0_WAKEUPEN0_MU0_MUA_MASK         (0x20000000U)
#define SLEEPCON0_WAKEUPEN0_MU0_MUA_SHIFT        (29U)
/*! MU0_MUA - MU0_MUA Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_MU0_MUA(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_MU0_MUA_SHIFT)) & SLEEPCON0_WAKEUPEN0_MU0_MUA_MASK)

#define SLEEPCON0_WAKEUPEN0_MU1_MUA_MASK         (0x40000000U)
#define SLEEPCON0_WAKEUPEN0_MU1_MUA_SHIFT        (30U)
/*! MU1_MUA - MU1_MUA Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_MU1_MUA(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_MU1_MUA_SHIFT)) & SLEEPCON0_WAKEUPEN0_MU1_MUA_MASK)

#define SLEEPCON0_WAKEUPEN0_MU4_MUA_MASK         (0x80000000U)
#define SLEEPCON0_WAKEUPEN0_MU4_MUA_SHIFT        (31U)
/*! MU4_MUA - MU4_MUA Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN0_MU4_MUA(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_MU4_MUA_SHIFT)) & SLEEPCON0_WAKEUPEN0_MU4_MUA_MASK)
/*! @} */

/*! @name WAKEUPEN1 - Wakeup Enable 1 */
/*! @{ */

#define SLEEPCON0_WAKEUPEN1_CTIMER2_MASK         (0x1U)
#define SLEEPCON0_WAKEUPEN1_CTIMER2_SHIFT        (0U)
/*! CTIMER2 - CTIMER2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_CTIMER2(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CTIMER2_SHIFT)) & SLEEPCON0_WAKEUPEN1_CTIMER2_MASK)

#define SLEEPCON0_WAKEUPEN1_CTIMER4_MASK         (0x2U)
#define SLEEPCON0_WAKEUPEN1_CTIMER4_SHIFT        (1U)
/*! CTIMER4 - CTIMER4 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_CTIMER4(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CTIMER4_SHIFT)) & SLEEPCON0_WAKEUPEN1_CTIMER4_MASK)

#define SLEEPCON0_WAKEUPEN1_OSTIMER_MASK         (0x4U)
#define SLEEPCON0_WAKEUPEN1_OSTIMER_SHIFT        (2U)
/*! OSTIMER - OSTIMER Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_OSTIMER(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_OSTIMER_SHIFT)) & SLEEPCON0_WAKEUPEN1_OSTIMER_MASK)

#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM6_MASK    (0x8U)
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM6_SHIFT   (3U)
/*! LP_FLEXCOMM6 - LP_FLEXCOMM6 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM6(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM6_SHIFT)) & SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM6_MASK)

#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM7_MASK    (0x10U)
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM7_SHIFT   (4U)
/*! LP_FLEXCOMM7 - LP_FLEXCOMM7 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM7(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM7_SHIFT)) & SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM7_MASK)

#define SLEEPCON0_WAKEUPEN1_I3C0_MASK            (0x80U)
#define SLEEPCON0_WAKEUPEN1_I3C0_SHIFT           (7U)
/*! I3C0 - I3C0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_I3C0(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_I3C0_SHIFT)) & SLEEPCON0_WAKEUPEN1_I3C0_MASK)

#define SLEEPCON0_WAKEUPEN1_USB0_MASK            (0x100U)
#define SLEEPCON0_WAKEUPEN1_USB0_SHIFT           (8U)
/*! USB0 - USB0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_USB0(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_USB0_SHIFT)) & SLEEPCON0_WAKEUPEN1_USB0_MASK)

#define SLEEPCON0_WAKEUPEN1_USB1_MASK            (0x200U)
#define SLEEPCON0_WAKEUPEN1_USB1_SHIFT           (9U)
/*! USB1 - USB1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_USB1(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_USB1_SHIFT)) & SLEEPCON0_WAKEUPEN1_USB1_MASK)

#define SLEEPCON0_WAKEUPEN1_WWDT0_MASK           (0x400U)
#define SLEEPCON0_WAKEUPEN1_WWDT0_SHIFT          (10U)
/*! WWDT0 - WWDT0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_WWDT0(x)             (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_WWDT0_SHIFT)) & SLEEPCON0_WAKEUPEN1_WWDT0_MASK)

#define SLEEPCON0_WAKEUPEN1_WWDT1_MASK           (0x800U)
#define SLEEPCON0_WAKEUPEN1_WWDT1_SHIFT          (11U)
/*! WWDT1 - WWDT1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_WWDT1(x)             (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_WWDT1_SHIFT)) & SLEEPCON0_WAKEUPEN1_WWDT1_MASK)

#define SLEEPCON0_WAKEUPEN1_USBPHY0_MASK         (0x1000U)
#define SLEEPCON0_WAKEUPEN1_USBPHY0_SHIFT        (12U)
/*! USBPHY0 - USBPHY0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_USBPHY0(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_USBPHY0_SHIFT)) & SLEEPCON0_WAKEUPEN1_USBPHY0_MASK)

#define SLEEPCON0_WAKEUPEN1_PMIC_IRQN_MASK       (0x4000U)
#define SLEEPCON0_WAKEUPEN1_PMIC_IRQN_SHIFT      (14U)
/*! PMIC_IRQN - PMIC_IRQN Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_PMIC_IRQN(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_PMIC_IRQN_SHIFT)) & SLEEPCON0_WAKEUPEN1_PMIC_IRQN_MASK)

#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM8_MASK    (0x8000U)
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM8_SHIFT   (15U)
/*! LP_FLEXCOMM8 - LP_FLEXCOMM8 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM8(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM8_SHIFT)) & SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM8_MASK)

#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM9_MASK    (0x10000U)
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM9_SHIFT   (16U)
/*! LP_FLEXCOMM9 - LP_FLEXCOMM9 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM9(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM9_SHIFT)) & SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM9_MASK)

#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM10_MASK   (0x20000U)
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM10_SHIFT  (17U)
/*! LP_FLEXCOMM10 - LP_FLEXCOMM10 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM10(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM10_SHIFT)) & SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM10_MASK)

#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM11_MASK   (0x40000U)
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM11_SHIFT  (18U)
/*! LP_FLEXCOMM11 - LP_FLEXCOMM11 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM11(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM11_SHIFT)) & SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM11_MASK)

#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM12_MASK   (0x80000U)
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM12_SHIFT  (19U)
/*! LP_FLEXCOMM12 - LP_FLEXCOMM12 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM12(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM12_SHIFT)) & SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM12_MASK)

#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM13_MASK   (0x100000U)
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM13_SHIFT  (20U)
/*! LP_FLEXCOMM13 - LP_FLEXCOMM13 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM13(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM13_SHIFT)) & SLEEPCON0_WAKEUPEN1_LP_FLEXCOMM13_MASK)

#define SLEEPCON0_WAKEUPEN1_LPSPI16_MASK         (0x200000U)
#define SLEEPCON0_WAKEUPEN1_LPSPI16_SHIFT        (21U)
/*! LPSPI16 - LPSPI16 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_LPSPI16(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_LPSPI16_SHIFT)) & SLEEPCON0_WAKEUPEN1_LPSPI16_MASK)

#define SLEEPCON0_WAKEUPEN1_I3C1_MASK            (0x400000U)
#define SLEEPCON0_WAKEUPEN1_I3C1_SHIFT           (22U)
/*! I3C1 - I3C1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_I3C1(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_I3C1_SHIFT)) & SLEEPCON0_WAKEUPEN1_I3C1_MASK)

#define SLEEPCON0_WAKEUPEN1_FLEXIO_MASK          (0x800000U)
#define SLEEPCON0_WAKEUPEN1_FLEXIO_SHIFT         (23U)
/*! FLEXIO - FLEXIO Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_FLEXIO(x)            (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_FLEXIO_SHIFT)) & SLEEPCON0_WAKEUPEN1_FLEXIO_MASK)

#define SLEEPCON0_WAKEUPEN1_EDMA0_CH0_MASK       (0x8000000U)
#define SLEEPCON0_WAKEUPEN1_EDMA0_CH0_SHIFT      (27U)
/*! EDMA0_CH0 - eDMA0 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_EDMA0_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_EDMA0_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN1_EDMA0_CH0_MASK)

#define SLEEPCON0_WAKEUPEN1_EDMA0_CH1_MASK       (0x10000000U)
#define SLEEPCON0_WAKEUPEN1_EDMA0_CH1_SHIFT      (28U)
/*! EDMA0_CH1 - eDMA0 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_EDMA0_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_EDMA0_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN1_EDMA0_CH1_MASK)

#define SLEEPCON0_WAKEUPEN1_EDMA0_CH2_MASK       (0x20000000U)
#define SLEEPCON0_WAKEUPEN1_EDMA0_CH2_SHIFT      (29U)
/*! EDMA0_CH2 - eDMA0 Channel 2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_EDMA0_CH2(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_EDMA0_CH2_SHIFT)) & SLEEPCON0_WAKEUPEN1_EDMA0_CH2_MASK)

#define SLEEPCON0_WAKEUPEN1_EDMA0_CH3_MASK       (0x40000000U)
#define SLEEPCON0_WAKEUPEN1_EDMA0_CH3_SHIFT      (30U)
/*! EDMA0_CH3 - eDMA0 Channel 3 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_EDMA0_CH3(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_EDMA0_CH3_SHIFT)) & SLEEPCON0_WAKEUPEN1_EDMA0_CH3_MASK)

#define SLEEPCON0_WAKEUPEN1_EDMA0_CH4_MASK       (0x80000000U)
#define SLEEPCON0_WAKEUPEN1_EDMA0_CH4_SHIFT      (31U)
/*! EDMA0_CH4 - eDMA0 Channel 4 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN1_EDMA0_CH4(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_EDMA0_CH4_SHIFT)) & SLEEPCON0_WAKEUPEN1_EDMA0_CH4_MASK)
/*! @} */

/*! @name WAKEUPEN2 - Wakeup Enable 2 */
/*! @{ */

#define SLEEPCON0_WAKEUPEN2_EDMA0_CH5_MASK       (0x1U)
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH5_SHIFT      (0U)
/*! EDMA0_CH5 - eDMA0 Channel 5 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH5(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA0_CH5_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA0_CH5_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA0_CH6_MASK       (0x2U)
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH6_SHIFT      (1U)
/*! EDMA0_CH6 - eDMA0 Channel 6 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH6(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA0_CH6_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA0_CH6_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA0_CH7_MASK       (0x4U)
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH7_SHIFT      (2U)
/*! EDMA0_CH7 - eDMA0 Channel 7 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH7(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA0_CH7_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA0_CH7_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA0_CH8_MASK       (0x8U)
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH8_SHIFT      (3U)
/*! EDMA0_CH8 - eDMA0 Channel 8 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH8(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA0_CH8_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA0_CH8_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA0_CH9_MASK       (0x10U)
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH9_SHIFT      (4U)
/*! EDMA0_CH9 - eDMA0 Channel 9 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH9(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA0_CH9_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA0_CH9_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA0_CH10_MASK      (0x20U)
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH10_SHIFT     (5U)
/*! EDMA0_CH10 - eDMA0 Channel 10 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH10(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA0_CH10_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA0_CH10_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA0_CH11_MASK      (0x40U)
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH11_SHIFT     (6U)
/*! EDMA0_CH11 - eDMA0 Channel 11 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH11(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA0_CH11_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA0_CH11_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA0_CH12_MASK      (0x80U)
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH12_SHIFT     (7U)
/*! EDMA0_CH12 - eDMA0 Channel 12 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH12(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA0_CH12_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA0_CH12_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA0_CH13_MASK      (0x100U)
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH13_SHIFT     (8U)
/*! EDMA0_CH13 - eDMA0 Channel 13 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH13(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA0_CH13_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA0_CH13_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA0_CH14_MASK      (0x200U)
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH14_SHIFT     (9U)
/*! EDMA0_CH14 - eDMA0 Channel 14 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH14(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA0_CH14_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA0_CH14_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA0_CH15_MASK      (0x400U)
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH15_SHIFT     (10U)
/*! EDMA0_CH15 - eDMA0 Channel 15 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA0_CH15(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA0_CH15_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA0_CH15_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH0_MASK       (0x800U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH0_SHIFT      (11U)
/*! EDMA1_CH0 - eDMA1 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH0_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH1_MASK       (0x1000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH1_SHIFT      (12U)
/*! EDMA1_CH1 - eDMA1 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH1_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH2_MASK       (0x2000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH2_SHIFT      (13U)
/*! EDMA1_CH2 - eDMA1 Channel 2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH2(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH2_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH2_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH3_MASK       (0x4000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH3_SHIFT      (14U)
/*! EDMA1_CH3 - eDMA1 Channel 3 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH3(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH3_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH3_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH4_MASK       (0x8000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH4_SHIFT      (15U)
/*! EDMA1_CH4 - eDMA1 Channel 4 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH4(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH4_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH4_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH5_MASK       (0x10000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH5_SHIFT      (16U)
/*! EDMA1_CH5 - eDMA1 Channel 5 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH5(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH5_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH5_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH6_MASK       (0x20000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH6_SHIFT      (17U)
/*! EDMA1_CH6 - eDMA1 Channel 6 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH6(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH6_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH6_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH7_MASK       (0x40000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH7_SHIFT      (18U)
/*! EDMA1_CH7 - eDMA1 Channel 7 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH7(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH7_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH7_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH8_MASK       (0x80000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH8_SHIFT      (19U)
/*! EDMA1_CH8 - eDMA1 Channel 8 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH8(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH8_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH8_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH9_MASK       (0x100000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH9_SHIFT      (20U)
/*! EDMA1_CH9 - eDMA1 Channel 9 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH9(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH9_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH9_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH10_MASK      (0x200000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH10_SHIFT     (21U)
/*! EDMA1_CH10 - eDMA1 Channel 10 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH10(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH10_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH10_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH11_MASK      (0x400000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH11_SHIFT     (22U)
/*! EDMA1_CH11 - eDMA1 Channel 11 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH11(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH11_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH11_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH12_MASK      (0x800000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH12_SHIFT     (23U)
/*! EDMA1_CH12 - eDMA1 Channel 12 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH12(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH12_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH12_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH13_MASK      (0x1000000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH13_SHIFT     (24U)
/*! EDMA1_CH13 - eDMA1 Channel 13 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH13(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH13_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH13_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH14_MASK      (0x2000000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH14_SHIFT     (25U)
/*! EDMA1_CH14 - eDMA1 Channel 14 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH14(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH14_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH14_MASK)

#define SLEEPCON0_WAKEUPEN2_EDMA1_CH15_MASK      (0x4000000U)
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH15_SHIFT     (26U)
/*! EDMA1_CH15 - eDMA1 Channel 15 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_EDMA1_CH15(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_EDMA1_CH15_SHIFT)) & SLEEPCON0_WAKEUPEN2_EDMA1_CH15_MASK)

#define SLEEPCON0_WAKEUPEN2_GPIO0_CH0_MASK       (0x8000000U)
#define SLEEPCON0_WAKEUPEN2_GPIO0_CH0_SHIFT      (27U)
/*! GPIO0_CH0 - GPIO0 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_GPIO0_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_GPIO0_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_GPIO0_CH0_MASK)

#define SLEEPCON0_WAKEUPEN2_GPIO0_CH1_MASK       (0x10000000U)
#define SLEEPCON0_WAKEUPEN2_GPIO0_CH1_SHIFT      (28U)
/*! GPIO0_CH1 - GPIO0 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_GPIO0_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_GPIO0_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN2_GPIO0_CH1_MASK)

#define SLEEPCON0_WAKEUPEN2_GPIO1_CH0_MASK       (0x20000000U)
#define SLEEPCON0_WAKEUPEN2_GPIO1_CH0_SHIFT      (29U)
/*! GPIO1_CH0 - GPIO1 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_GPIO1_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_GPIO1_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_GPIO1_CH0_MASK)

#define SLEEPCON0_WAKEUPEN2_GPIO1_CH1_MASK       (0x40000000U)
#define SLEEPCON0_WAKEUPEN2_GPIO1_CH1_SHIFT      (30U)
/*! GPIO1_CH1 - GPIO1 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_GPIO1_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_GPIO1_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN2_GPIO1_CH1_MASK)

#define SLEEPCON0_WAKEUPEN2_GPIO2_CH0_MASK       (0x80000000U)
#define SLEEPCON0_WAKEUPEN2_GPIO2_CH0_SHIFT      (31U)
/*! GPIO2_CH0 - GPIO2 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN2_GPIO2_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_GPIO2_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_GPIO2_CH0_MASK)
/*! @} */

/*! @name WAKEUPEN3 - Wakeup Enable 3 */
/*! @{ */

#define SLEEPCON0_WAKEUPEN3_GPIO2_CH1_MASK       (0x1U)
#define SLEEPCON0_WAKEUPEN3_GPIO2_CH1_SHIFT      (0U)
/*! GPIO2_CH1 - GPIO2 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_GPIO2_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_GPIO2_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_GPIO2_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_GPIO3_CH0_MASK       (0x2U)
#define SLEEPCON0_WAKEUPEN3_GPIO3_CH0_SHIFT      (1U)
/*! GPIO3_CH0 - GPIO3 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_GPIO3_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_GPIO3_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_GPIO3_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_GPIO3_CH1_MASK       (0x4U)
#define SLEEPCON0_WAKEUPEN3_GPIO3_CH1_SHIFT      (2U)
/*! GPIO3_CH1 - GPIO3 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_GPIO3_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_GPIO3_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_GPIO3_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_GPIO4_CH0_MASK       (0x8U)
#define SLEEPCON0_WAKEUPEN3_GPIO4_CH0_SHIFT      (3U)
/*! GPIO4_CH0 - GPIO4 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_GPIO4_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_GPIO4_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_GPIO4_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_GPIO4_CH1_MASK       (0x10U)
#define SLEEPCON0_WAKEUPEN3_GPIO4_CH1_SHIFT      (4U)
/*! GPIO4_CH1 - GPIO4 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_GPIO4_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_GPIO4_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_GPIO4_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_GPIO5_CH0_MASK       (0x20U)
#define SLEEPCON0_WAKEUPEN3_GPIO5_CH0_SHIFT      (5U)
/*! GPIO5_CH0 - GPIO5 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_GPIO5_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_GPIO5_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_GPIO5_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_GPIO5_CH1_MASK       (0x40U)
#define SLEEPCON0_WAKEUPEN3_GPIO5_CH1_SHIFT      (6U)
/*! GPIO5_CH1 - GPIO5 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_GPIO5_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_GPIO5_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_GPIO5_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_GPIO6_CH0_MASK       (0x80U)
#define SLEEPCON0_WAKEUPEN3_GPIO6_CH0_SHIFT      (7U)
/*! GPIO6_CH0 - GPIO6 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_GPIO6_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_GPIO6_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_GPIO6_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_GPIO6_CH1_MASK       (0x100U)
#define SLEEPCON0_WAKEUPEN3_GPIO6_CH1_SHIFT      (8U)
/*! GPIO6_CH1 - GPIO6 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_GPIO6_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_GPIO6_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_GPIO6_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_GPIO7_CH0_MASK       (0x200U)
#define SLEEPCON0_WAKEUPEN3_GPIO7_CH0_SHIFT      (9U)
/*! GPIO7_CH0 - GPIO7 Channel 0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_GPIO7_CH0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_GPIO7_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_GPIO7_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_GPIO7_CH1_MASK       (0x400U)
#define SLEEPCON0_WAKEUPEN3_GPIO7_CH1_SHIFT      (10U)
/*! GPIO7_CH1 - GPIO7 Channel 1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_GPIO7_CH1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_GPIO7_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_GPIO7_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_PINT0_INTR0_MASK     (0x800U)
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR0_SHIFT    (11U)
/*! PINT0_INTR0 - PINT0_INTR0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR0(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_PINT0_INTR0_SHIFT)) & SLEEPCON0_WAKEUPEN3_PINT0_INTR0_MASK)

#define SLEEPCON0_WAKEUPEN3_PINT0_INTR1_MASK     (0x1000U)
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR1_SHIFT    (12U)
/*! PINT0_INTR1 - PINT0_INTR1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR1(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_PINT0_INTR1_SHIFT)) & SLEEPCON0_WAKEUPEN3_PINT0_INTR1_MASK)

#define SLEEPCON0_WAKEUPEN3_PINT0_INTR2_MASK     (0x2000U)
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR2_SHIFT    (13U)
/*! PINT0_INTR2 - PINT0_INTR2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR2(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_PINT0_INTR2_SHIFT)) & SLEEPCON0_WAKEUPEN3_PINT0_INTR2_MASK)

#define SLEEPCON0_WAKEUPEN3_PINT0_INTR3_MASK     (0x4000U)
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR3_SHIFT    (14U)
/*! PINT0_INTR3 - PINT0_INTR3 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR3(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_PINT0_INTR3_SHIFT)) & SLEEPCON0_WAKEUPEN3_PINT0_INTR3_MASK)

#define SLEEPCON0_WAKEUPEN3_PINT0_INTR4_MASK     (0x8000U)
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR4_SHIFT    (15U)
/*! PINT0_INTR4 - PINT0_INTR4 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR4(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_PINT0_INTR4_SHIFT)) & SLEEPCON0_WAKEUPEN3_PINT0_INTR4_MASK)

#define SLEEPCON0_WAKEUPEN3_PINT0_INTR5_MASK     (0x10000U)
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR5_SHIFT    (16U)
/*! PINT0_INTR5 - PINT0_INTR5 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR5(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_PINT0_INTR5_SHIFT)) & SLEEPCON0_WAKEUPEN3_PINT0_INTR5_MASK)

#define SLEEPCON0_WAKEUPEN3_PINT0_INTR6_MASK     (0x20000U)
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR6_SHIFT    (17U)
/*! PINT0_INTR6 - PINT0_INTR6 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR6(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_PINT0_INTR6_SHIFT)) & SLEEPCON0_WAKEUPEN3_PINT0_INTR6_MASK)

#define SLEEPCON0_WAKEUPEN3_PINT0_INTR7_MASK     (0x40000U)
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR7_SHIFT    (18U)
/*! PINT0_INTR7 - PINT0_INTR7 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_PINT0_INTR7(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_PINT0_INTR7_SHIFT)) & SLEEPCON0_WAKEUPEN3_PINT0_INTR7_MASK)

#define SLEEPCON0_WAKEUPEN3_SAI0_MASK            (0x80000U)
#define SLEEPCON0_WAKEUPEN3_SAI0_SHIFT           (19U)
/*! SAI0 - SAI0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_SAI0(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SAI0_SHIFT)) & SLEEPCON0_WAKEUPEN3_SAI0_MASK)

#define SLEEPCON0_WAKEUPEN3_SAI1_MASK            (0x100000U)
#define SLEEPCON0_WAKEUPEN3_SAI1_SHIFT           (20U)
/*! SAI1 - SAI1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_SAI1(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SAI1_SHIFT)) & SLEEPCON0_WAKEUPEN3_SAI1_MASK)

#define SLEEPCON0_WAKEUPEN3_SAI2_MASK            (0x200000U)
#define SLEEPCON0_WAKEUPEN3_SAI2_SHIFT           (21U)
/*! SAI2 - SAI2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN3_SAI2(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SAI2_SHIFT)) & SLEEPCON0_WAKEUPEN3_SAI2_MASK)
/*! @} */

/*! @name WAKEUPEN4 - Wakeup Enable 4 */
/*! @{ */

#define SLEEPCON0_WAKEUPEN4_ITRC_MASK            (0x10U)
#define SLEEPCON0_WAKEUPEN4_ITRC_SHIFT           (4U)
/*! ITRC - ITRC Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN4_ITRC(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_ITRC_SHIFT)) & SLEEPCON0_WAKEUPEN4_ITRC_MASK)

#define SLEEPCON0_WAKEUPEN4_PMC0_MASK            (0x400U)
#define SLEEPCON0_WAKEUPEN4_PMC0_SHIFT           (10U)
/*! PMC0 - PMC0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN4_PMC0(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_PMC0_SHIFT)) & SLEEPCON0_WAKEUPEN4_PMC0_MASK)

#define SLEEPCON0_WAKEUPEN4_FRO0_MASK            (0x4000000U)
#define SLEEPCON0_WAKEUPEN4_FRO0_SHIFT           (26U)
/*! FRO0 - FRO0 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN4_FRO0(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_FRO0_SHIFT)) & SLEEPCON0_WAKEUPEN4_FRO0_MASK)

#define SLEEPCON0_WAKEUPEN4_FRO1_MASK            (0x8000000U)
#define SLEEPCON0_WAKEUPEN4_FRO1_SHIFT           (27U)
/*! FRO1 - FRO1 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN4_FRO1(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_FRO1_SHIFT)) & SLEEPCON0_WAKEUPEN4_FRO1_MASK)

#define SLEEPCON0_WAKEUPEN4_FRO2_MASK            (0x10000000U)
#define SLEEPCON0_WAKEUPEN4_FRO2_SHIFT           (28U)
/*! FRO2 - FRO2 Wake-up Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_WAKEUPEN4_FRO2(x)              (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_FRO2_SHIFT)) & SLEEPCON0_WAKEUPEN4_FRO2_MASK)
/*! @} */

/*! @name WAKEUPEN0_SET - Wakeup Enable 0 Set */
/*! @{ */

#define SLEEPCON0_WAKEUPEN0_SET_UTICK0_MASK      (0x2U)
#define SLEEPCON0_WAKEUPEN0_SET_UTICK0_SHIFT     (1U)
/*! UTICK0 - UTICK0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_UTICK0(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_UTICK0_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_UTICK0_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_CTIMER0_MASK     (0x8U)
#define SLEEPCON0_WAKEUPEN0_SET_CTIMER0_SHIFT    (3U)
/*! CTIMER0 - CTIMER0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_CTIMER0(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_CTIMER0_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_CTIMER0_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_CTIMER1_MASK     (0x10U)
#define SLEEPCON0_WAKEUPEN0_SET_CTIMER1_SHIFT    (4U)
/*! CTIMER1 - CTIMER1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_CTIMER1(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_CTIMER1_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_CTIMER1_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_CTIMER3_MASK     (0x40U)
#define SLEEPCON0_WAKEUPEN0_SET_CTIMER3_SHIFT    (6U)
/*! CTIMER3 - CTIMER3 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_CTIMER3(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_CTIMER3_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_CTIMER3_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM0_MASK (0x80U)
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM0_SHIFT (7U)
/*! LP_FLEXCOMM0 - LP_FLEXCOMM0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM0(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM0_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM0_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM1_MASK (0x100U)
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM1_SHIFT (8U)
/*! LP_FLEXCOMM1 - LP_FLEXCOMM1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM1(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM1_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM1_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM2_MASK (0x200U)
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM2_SHIFT (9U)
/*! LP_FLEXCOMM2 - LP_FLEXCOMM2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM2(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM2_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM2_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM3_MASK (0x400U)
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM3_SHIFT (10U)
/*! LP_FLEXCOMM3 - LP_FLEXCOMM3 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM3(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM3_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM3_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM4_MASK (0x800U)
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM4_SHIFT (11U)
/*! LP_FLEXCOMM4 - LP_FLEXCOMM4 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM4(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM4_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM4_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM5_MASK (0x1000U)
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM5_SHIFT (12U)
/*! LP_FLEXCOMM5 - LP_FLEXCOMM5 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM5(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM5_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_LP_FLEXCOMM5_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_LPSPI14_MASK     (0x2000U)
#define SLEEPCON0_WAKEUPEN0_SET_LPSPI14_SHIFT    (13U)
/*! LPSPI14 - LPSPI14 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_LPSPI14(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_LPSPI14_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_LPSPI14_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_LPI2C15_MASK     (0x4000U)
#define SLEEPCON0_WAKEUPEN0_SET_LPI2C15_SHIFT    (14U)
/*! LPI2C15 - LPI2C15 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_LPI2C15(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_LPI2C15_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_LPI2C15_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_ADC0_MASK        (0x8000U)
#define SLEEPCON0_WAKEUPEN0_SET_ADC0_SHIFT       (15U)
/*! ADC0 - ADC0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_ADC0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_ADC0_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_ADC0_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_ACMP0_MASK       (0x20000U)
#define SLEEPCON0_WAKEUPEN0_SET_ACMP0_SHIFT      (17U)
/*! ACMP0 - ACMP0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_ACMP0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_ACMP0_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_ACMP0_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_MICFIL_RD_ERR_MASK (0x40000U)
#define SLEEPCON0_WAKEUPEN0_SET_MICFIL_RD_ERR_SHIFT (18U)
/*! MICFIL_RD_ERR - MICFIL Read Data Error Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_MICFIL_RD_ERR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_MICFIL_RD_ERR_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_MICFIL_RD_ERR_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_MICFIL_WKUP_MASK (0x80000U)
#define SLEEPCON0_WAKEUPEN0_SET_MICFIL_WKUP_SHIFT (19U)
/*! MICFIL_WKUP - MICFIL Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_MICFIL_WKUP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_MICFIL_WKUP_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_MICFIL_WKUP_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_RTC0_ALARM_MASK  (0x4000000U)
#define SLEEPCON0_WAKEUPEN0_SET_RTC0_ALARM_SHIFT (26U)
/*! RTC0_ALARM - RTC0_ALARM Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_RTC0_ALARM(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_RTC0_ALARM_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_RTC0_ALARM_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_RTC0_WKUP_MASK   (0x8000000U)
#define SLEEPCON0_WAKEUPEN0_SET_RTC0_WKUP_SHIFT  (27U)
/*! RTC0_WKUP - RTC0_WKUP Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_RTC0_WKUP(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_RTC0_WKUP_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_RTC0_WKUP_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_MU0_MUA_MASK     (0x20000000U)
#define SLEEPCON0_WAKEUPEN0_SET_MU0_MUA_SHIFT    (29U)
/*! MU0_MUA - MU0_MUA Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_MU0_MUA(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_MU0_MUA_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_MU0_MUA_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_MU1_MUA_MASK     (0x40000000U)
#define SLEEPCON0_WAKEUPEN0_SET_MU1_MUA_SHIFT    (30U)
/*! MU1_MUA - MU1_MUA Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_MU1_MUA(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_MU1_MUA_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_MU1_MUA_MASK)

#define SLEEPCON0_WAKEUPEN0_SET_MU4_MUA_MASK     (0x80000000U)
#define SLEEPCON0_WAKEUPEN0_SET_MU4_MUA_SHIFT    (31U)
/*! MU4_MUA - MU4_MUA Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN0_SET_MU4_MUA(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_SET_MU4_MUA_SHIFT)) & SLEEPCON0_WAKEUPEN0_SET_MU4_MUA_MASK)
/*! @} */

/*! @name WAKEUPEN1_SET - Wakeup Enable 1 Set */
/*! @{ */

#define SLEEPCON0_WAKEUPEN1_SET_CTIMER2_MASK     (0x1U)
#define SLEEPCON0_WAKEUPEN1_SET_CTIMER2_SHIFT    (0U)
/*! CTIMER2 - CTIMER2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_CTIMER2(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_CTIMER2_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_CTIMER2_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_CTIMER4_MASK     (0x2U)
#define SLEEPCON0_WAKEUPEN1_SET_CTIMER4_SHIFT    (1U)
/*! CTIMER4 - CTIMER4 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_CTIMER4(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_CTIMER4_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_CTIMER4_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_OSTIMER_MASK     (0x4U)
#define SLEEPCON0_WAKEUPEN1_SET_OSTIMER_SHIFT    (2U)
/*! OSTIMER - OSTIMER Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_OSTIMER(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_OSTIMER_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_OSTIMER_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM6_MASK (0x8U)
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM6_SHIFT (3U)
/*! LP_FLEXCOMM6 - LP_FLEXCOMM6 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM6(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM6_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM6_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM7_MASK (0x10U)
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM7_SHIFT (4U)
/*! LP_FLEXCOMM7 - LP_FLEXCOMM7 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM7(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM7_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM7_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_I3C0_MASK        (0x80U)
#define SLEEPCON0_WAKEUPEN1_SET_I3C0_SHIFT       (7U)
/*! I3C0 - I3C0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_I3C0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_I3C0_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_I3C0_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_USB0_MASK        (0x100U)
#define SLEEPCON0_WAKEUPEN1_SET_USB0_SHIFT       (8U)
/*! USB0 - USB0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_USB0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_USB0_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_USB0_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_USB1_MASK        (0x200U)
#define SLEEPCON0_WAKEUPEN1_SET_USB1_SHIFT       (9U)
/*! USB1 - USB1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_USB1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_USB1_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_USB1_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_WWDT0_MASK       (0x400U)
#define SLEEPCON0_WAKEUPEN1_SET_WWDT0_SHIFT      (10U)
/*! WWDT0 - WWDT0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_WWDT0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_WWDT0_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_WWDT0_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_WWDT1_MASK       (0x800U)
#define SLEEPCON0_WAKEUPEN1_SET_WWDT1_SHIFT      (11U)
/*! WWDT1 - WWDT1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_WWDT1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_WWDT1_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_WWDT1_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_USBPHY0_MASK     (0x1000U)
#define SLEEPCON0_WAKEUPEN1_SET_USBPHY0_SHIFT    (12U)
/*! USBPHY0 - USBPHY0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_USBPHY0(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_USBPHY0_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_USBPHY0_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_PMIC_IRQN_MASK   (0x4000U)
#define SLEEPCON0_WAKEUPEN1_SET_PMIC_IRQN_SHIFT  (14U)
/*! PMIC_IRQN - PMIC_IRQN Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_PMIC_IRQN(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_PMIC_IRQN_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_PMIC_IRQN_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM8_MASK (0x8000U)
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM8_SHIFT (15U)
/*! LP_FLEXCOMM8 - LP_FLEXCOMM8 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM8(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM8_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM8_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM9_MASK (0x10000U)
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM9_SHIFT (16U)
/*! LP_FLEXCOMM9 - LP_FLEXCOMM9 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM9(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM9_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM9_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM10_MASK (0x20000U)
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM10_SHIFT (17U)
/*! LP_FLEXCOMM10 - LP_FLEXCOMM10 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM10(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM10_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM10_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM11_MASK (0x40000U)
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM11_SHIFT (18U)
/*! LP_FLEXCOMM11 - LP_FLEXCOMM11 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM11(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM11_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM11_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM12_MASK (0x80000U)
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM12_SHIFT (19U)
/*! LP_FLEXCOMM12 - LP_FLEXCOMM12 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM12(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM12_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM12_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM13_MASK (0x100000U)
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM13_SHIFT (20U)
/*! LP_FLEXCOMM13 - LP_FLEXCOMM13 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM13(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM13_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_LP_FLEXCOMM13_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_LPSPI16_MASK     (0x200000U)
#define SLEEPCON0_WAKEUPEN1_SET_LPSPI16_SHIFT    (21U)
/*! LPSPI16 - LPSPI16 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_LPSPI16(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_LPSPI16_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_LPSPI16_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_I3C1_MASK        (0x400000U)
#define SLEEPCON0_WAKEUPEN1_SET_I3C1_SHIFT       (22U)
/*! I3C1 - I3C1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_I3C1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_I3C1_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_I3C1_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_FLEXIO_MASK      (0x800000U)
#define SLEEPCON0_WAKEUPEN1_SET_FLEXIO_SHIFT     (23U)
/*! FLEXIO - FLEXIO Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_FLEXIO(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_FLEXIO_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_FLEXIO_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH0_MASK   (0x8000000U)
#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH0_SHIFT  (27U)
/*! EDMA0_CH0 - eDMA0 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH0_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH1_MASK   (0x10000000U)
#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH1_SHIFT  (28U)
/*! EDMA0_CH1 - eDMA0 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH1_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH2_MASK   (0x20000000U)
#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH2_SHIFT  (29U)
/*! EDMA0_CH2 - eDMA0 Channel 2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH2(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH2_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH2_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH3_MASK   (0x40000000U)
#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH3_SHIFT  (30U)
/*! EDMA0_CH3 - eDMA0 Channel 3 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH3(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH3_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH3_MASK)

#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH4_MASK   (0x80000000U)
#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH4_SHIFT  (31U)
/*! EDMA0_CH4 - eDMA0 Channel 4 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH4(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH4_SHIFT)) & SLEEPCON0_WAKEUPEN1_SET_EDMA0_CH4_MASK)
/*! @} */

/*! @name WAKEUPEN2_SET - Wakeup Enable 2 Set */
/*! @{ */

#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH5_MASK   (0x1U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH5_SHIFT  (0U)
/*! EDMA0_CH5 - eDMA0 Channel 5 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH5(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH5_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH5_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH6_MASK   (0x2U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH6_SHIFT  (1U)
/*! EDMA0_CH6 - eDMA0 Channel 6 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH6(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH6_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH6_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH7_MASK   (0x4U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH7_SHIFT  (2U)
/*! EDMA0_CH7 - eDMA0 Channel 7 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH7(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH7_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH7_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH8_MASK   (0x8U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH8_SHIFT  (3U)
/*! EDMA0_CH8 - eDMA0 Channel 8 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH8(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH8_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH8_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH9_MASK   (0x10U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH9_SHIFT  (4U)
/*! EDMA0_CH9 - eDMA0 Channel 9 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH9(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH9_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH9_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH10_MASK  (0x20U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH10_SHIFT (5U)
/*! EDMA0_CH10 - eDMA0 Channel 10 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH10(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH10_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH10_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH11_MASK  (0x40U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH11_SHIFT (6U)
/*! EDMA0_CH11 - eDMA0 Channel 11 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH11(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH11_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH11_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH12_MASK  (0x80U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH12_SHIFT (7U)
/*! EDMA0_CH12 - eDMA0 Channel 12 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH12(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH12_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH12_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH13_MASK  (0x100U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH13_SHIFT (8U)
/*! EDMA0_CH13 - eDMA0 Channel 13 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH13(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH13_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH13_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH14_MASK  (0x200U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH14_SHIFT (9U)
/*! EDMA0_CH14 - eDMA0 Channel 14 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH14(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH14_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH14_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH15_MASK  (0x400U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH15_SHIFT (10U)
/*! EDMA0_CH15 - eDMA0 Channel 15 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH15(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH15_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA0_CH15_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH0_MASK   (0x800U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH0_SHIFT  (11U)
/*! EDMA1_CH0 - eDMA1 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH0_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH1_MASK   (0x1000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH1_SHIFT  (12U)
/*! EDMA1_CH1 - eDMA1 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH1_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH2_MASK   (0x2000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH2_SHIFT  (13U)
/*! EDMA1_CH2 - eDMA1 Channel 2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH2(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH2_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH2_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH3_MASK   (0x4000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH3_SHIFT  (14U)
/*! EDMA1_CH3 - eDMA1 Channel 3 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH3(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH3_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH3_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH4_MASK   (0x8000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH4_SHIFT  (15U)
/*! EDMA1_CH4 - eDMA1 Channel 4 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH4(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH4_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH4_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH5_MASK   (0x10000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH5_SHIFT  (16U)
/*! EDMA1_CH5 - eDMA1 Channel 5 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH5(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH5_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH5_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH6_MASK   (0x20000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH6_SHIFT  (17U)
/*! EDMA1_CH6 - eDMA1 Channel 6 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH6(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH6_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH6_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH7_MASK   (0x40000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH7_SHIFT  (18U)
/*! EDMA1_CH7 - eDMA1 Channel 7 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH7(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH7_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH7_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH8_MASK   (0x80000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH8_SHIFT  (19U)
/*! EDMA1_CH8 - eDMA1 Channel 8 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH8(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH8_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH8_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH9_MASK   (0x100000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH9_SHIFT  (20U)
/*! EDMA1_CH9 - eDMA1 Channel 9 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH9(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH9_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH9_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH10_MASK  (0x200000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH10_SHIFT (21U)
/*! EDMA1_CH10 - eDMA1 Channel 10 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH10(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH10_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH10_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH11_MASK  (0x400000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH11_SHIFT (22U)
/*! EDMA1_CH11 - eDMA1 Channel 11 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH11(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH11_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH11_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH12_MASK  (0x800000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH12_SHIFT (23U)
/*! EDMA1_CH12 - eDMA1 Channel 12 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH12(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH12_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH12_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH13_MASK  (0x1000000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH13_SHIFT (24U)
/*! EDMA1_CH13 - eDMA1 Channel 13 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH13(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH13_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH13_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH14_MASK  (0x2000000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH14_SHIFT (25U)
/*! EDMA1_CH14 - eDMA1 Channel 14 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH14(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH14_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH14_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH15_MASK  (0x4000000U)
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH15_SHIFT (26U)
/*! EDMA1_CH15 - eDMA1 Channel 15 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH15(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH15_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_EDMA1_CH15_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_GPIO0_CH0_MASK   (0x8000000U)
#define SLEEPCON0_WAKEUPEN2_SET_GPIO0_CH0_SHIFT  (27U)
/*! GPIO0_CH0 - GPIO0 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_GPIO0_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_GPIO0_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_GPIO0_CH0_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_GPIO0_CH1_MASK   (0x10000000U)
#define SLEEPCON0_WAKEUPEN2_SET_GPIO0_CH1_SHIFT  (28U)
/*! GPIO0_CH1 - GPIO0 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_GPIO0_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_GPIO0_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_GPIO0_CH1_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_GPIO1_CH0_MASK   (0x20000000U)
#define SLEEPCON0_WAKEUPEN2_SET_GPIO1_CH0_SHIFT  (29U)
/*! GPIO1_CH0 - GPIO1 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_GPIO1_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_GPIO1_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_GPIO1_CH0_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_GPIO1_CH1_MASK   (0x40000000U)
#define SLEEPCON0_WAKEUPEN2_SET_GPIO1_CH1_SHIFT  (30U)
/*! GPIO1_CH1 - GPIO1 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_GPIO1_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_GPIO1_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_GPIO1_CH1_MASK)

#define SLEEPCON0_WAKEUPEN2_SET_GPIO2_CH0_MASK   (0x80000000U)
#define SLEEPCON0_WAKEUPEN2_SET_GPIO2_CH0_SHIFT  (31U)
/*! GPIO2_CH0 - GPIO2 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN2_SET_GPIO2_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_SET_GPIO2_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_SET_GPIO2_CH0_MASK)
/*! @} */

/*! @name WAKEUPEN3_SET - Wakeup Enable 3 Set */
/*! @{ */

#define SLEEPCON0_WAKEUPEN3_SET_GPIO2_CH1_MASK   (0x1U)
#define SLEEPCON0_WAKEUPEN3_SET_GPIO2_CH1_SHIFT  (0U)
/*! GPIO2_CH1 - GPIO2 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_GPIO2_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_GPIO2_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_GPIO2_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_GPIO3_CH0_MASK   (0x2U)
#define SLEEPCON0_WAKEUPEN3_SET_GPIO3_CH0_SHIFT  (1U)
/*! GPIO3_CH0 - GPIO3 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_GPIO3_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_GPIO3_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_GPIO3_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_GPIO3_CH1_MASK   (0x4U)
#define SLEEPCON0_WAKEUPEN3_SET_GPIO3_CH1_SHIFT  (2U)
/*! GPIO3_CH1 - GPIO3 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_GPIO3_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_GPIO3_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_GPIO3_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_GPIO4_CH0_MASK   (0x8U)
#define SLEEPCON0_WAKEUPEN3_SET_GPIO4_CH0_SHIFT  (3U)
/*! GPIO4_CH0 - GPIO4 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_GPIO4_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_GPIO4_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_GPIO4_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_GPIO4_CH1_MASK   (0x10U)
#define SLEEPCON0_WAKEUPEN3_SET_GPIO4_CH1_SHIFT  (4U)
/*! GPIO4_CH1 - GPIO4 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_GPIO4_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_GPIO4_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_GPIO4_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_GPIO5_CH0_MASK   (0x20U)
#define SLEEPCON0_WAKEUPEN3_SET_GPIO5_CH0_SHIFT  (5U)
/*! GPIO5_CH0 - GPIO5 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_GPIO5_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_GPIO5_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_GPIO5_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_GPIO5_CH1_MASK   (0x40U)
#define SLEEPCON0_WAKEUPEN3_SET_GPIO5_CH1_SHIFT  (6U)
/*! GPIO5_CH1 - GPIO5 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_GPIO5_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_GPIO5_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_GPIO5_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_GPIO6_CH0_MASK   (0x80U)
#define SLEEPCON0_WAKEUPEN3_SET_GPIO6_CH0_SHIFT  (7U)
/*! GPIO6_CH0 - GPIO6 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_GPIO6_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_GPIO6_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_GPIO6_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_GPIO6_CH1_MASK   (0x100U)
#define SLEEPCON0_WAKEUPEN3_SET_GPIO6_CH1_SHIFT  (8U)
/*! GPIO6_CH1 - GPIO6 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_GPIO6_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_GPIO6_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_GPIO6_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_GPIO7_CH0_MASK   (0x200U)
#define SLEEPCON0_WAKEUPEN3_SET_GPIO7_CH0_SHIFT  (9U)
/*! GPIO7_CH0 - GPIO7 Channel 0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_GPIO7_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_GPIO7_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_GPIO7_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_GPIO7_CH1_MASK   (0x400U)
#define SLEEPCON0_WAKEUPEN3_SET_GPIO7_CH1_SHIFT  (10U)
/*! GPIO7_CH1 - GPIO7 Channel 1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_GPIO7_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_GPIO7_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_GPIO7_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR0_MASK (0x800U)
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR0_SHIFT (11U)
/*! PINT0_INTR0 - PINT0_INTR0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR0(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR0_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR0_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR1_MASK (0x1000U)
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR1_SHIFT (12U)
/*! PINT0_INTR1 - PINT0_INTR1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR1(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR1_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR1_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR2_MASK (0x2000U)
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR2_SHIFT (13U)
/*! PINT0_INTR2 - PINT0_INTR2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR2(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR2_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR2_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR3_MASK (0x4000U)
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR3_SHIFT (14U)
/*! PINT0_INTR3 - PINT0_INTR3 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR3(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR3_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR3_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR4_MASK (0x8000U)
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR4_SHIFT (15U)
/*! PINT0_INTR4 - PINT0_INTR4 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR4(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR4_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR4_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR5_MASK (0x10000U)
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR5_SHIFT (16U)
/*! PINT0_INTR5 - PINT0_INTR5 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR5(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR5_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR5_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR6_MASK (0x20000U)
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR6_SHIFT (17U)
/*! PINT0_INTR6 - PINT0_INTR6 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR6(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR6_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR6_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR7_MASK (0x40000U)
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR7_SHIFT (18U)
/*! PINT0_INTR7 - PINT0_INTR7 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR7(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR7_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_PINT0_INTR7_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_SAI0_MASK        (0x80000U)
#define SLEEPCON0_WAKEUPEN3_SET_SAI0_SHIFT       (19U)
/*! SAI0 - SAI0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_SAI0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_SAI0_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_SAI0_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_SAI1_MASK        (0x100000U)
#define SLEEPCON0_WAKEUPEN3_SET_SAI1_SHIFT       (20U)
/*! SAI1 - SAI1 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_SAI1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_SAI1_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_SAI1_MASK)

#define SLEEPCON0_WAKEUPEN3_SET_SAI2_MASK        (0x200000U)
#define SLEEPCON0_WAKEUPEN3_SET_SAI2_SHIFT       (21U)
/*! SAI2 - SAI2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN3_SET_SAI2(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_SET_SAI2_SHIFT)) & SLEEPCON0_WAKEUPEN3_SET_SAI2_MASK)
/*! @} */

/*! @name WAKEUPEN4_SET - Wakeup Enable 4 Set */
/*! @{ */

#define SLEEPCON0_WAKEUPEN4_SET_ITRC_MASK        (0x10U)
#define SLEEPCON0_WAKEUPEN4_SET_ITRC_SHIFT       (4U)
/*! ITRC - ITRC Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN4_SET_ITRC(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_SET_ITRC_SHIFT)) & SLEEPCON0_WAKEUPEN4_SET_ITRC_MASK)

#define SLEEPCON0_WAKEUPEN4_SET_PMC0_MASK        (0x400U)
#define SLEEPCON0_WAKEUPEN4_SET_PMC0_SHIFT       (10U)
/*! PMC0 - PMC0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN4_SET_PMC0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_SET_PMC0_SHIFT)) & SLEEPCON0_WAKEUPEN4_SET_PMC0_MASK)

#define SLEEPCON0_WAKEUPEN4_SET_FRO0_MASK        (0x4000000U)
#define SLEEPCON0_WAKEUPEN4_SET_FRO0_SHIFT       (26U)
/*! FRO0 - FRO0 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN4_SET_FRO0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_SET_FRO0_SHIFT)) & SLEEPCON0_WAKEUPEN4_SET_FRO0_MASK)

#define SLEEPCON0_WAKEUPEN4_SET_FRO1_MASK        (0x8000000U)
#define SLEEPCON0_WAKEUPEN4_SET_FRO1_SHIFT       (27U)
/*! FRO1 - FRO1 Wake-up Enable
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN4_SET_FRO1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_SET_FRO1_SHIFT)) & SLEEPCON0_WAKEUPEN4_SET_FRO1_MASK)

#define SLEEPCON0_WAKEUPEN4_SET_FRO2_MASK        (0x10000000U)
#define SLEEPCON0_WAKEUPEN4_SET_FRO2_SHIFT       (28U)
/*! FRO2 - FRO2 Wake-up Enable Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_WAKEUPEN4_SET_FRO2(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_SET_FRO2_SHIFT)) & SLEEPCON0_WAKEUPEN4_SET_FRO2_MASK)
/*! @} */

/*! @name WAKEUPEN0_CLR - Wakeup Enable 0 Clear */
/*! @{ */

#define SLEEPCON0_WAKEUPEN0_CLR_UTICK0_MASK      (0x2U)
#define SLEEPCON0_WAKEUPEN0_CLR_UTICK0_SHIFT     (1U)
/*! UTICK0 - UTICK0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_UTICK0(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_UTICK0_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_UTICK0_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_CTIMER0_MASK     (0x8U)
#define SLEEPCON0_WAKEUPEN0_CLR_CTIMER0_SHIFT    (3U)
/*! CTIMER0 - CTIMER0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_CTIMER0(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_CTIMER0_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_CTIMER0_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_CTIMER1_MASK     (0x10U)
#define SLEEPCON0_WAKEUPEN0_CLR_CTIMER1_SHIFT    (4U)
/*! CTIMER1 - CTIMER1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_CTIMER1(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_CTIMER1_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_CTIMER1_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_CTIMER3_MASK     (0x40U)
#define SLEEPCON0_WAKEUPEN0_CLR_CTIMER3_SHIFT    (6U)
/*! CTIMER3 - CTIMER3 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_CTIMER3(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_CTIMER3_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_CTIMER3_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM0_MASK (0x80U)
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM0_SHIFT (7U)
/*! LP_FLEXCOMM0 - LP_FLEXCOMM0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM0(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM0_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM0_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM1_MASK (0x100U)
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM1_SHIFT (8U)
/*! LP_FLEXCOMM1 - LP_FLEXCOMM1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM1(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM1_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM1_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM2_MASK (0x200U)
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM2_SHIFT (9U)
/*! LP_FLEXCOMM2 - LP_FLEXCOMM2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM2(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM2_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM2_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM3_MASK (0x400U)
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM3_SHIFT (10U)
/*! LP_FLEXCOMM3 - LP_FLEXCOMM3 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM3(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM3_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM3_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM4_MASK (0x800U)
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM4_SHIFT (11U)
/*! LP_FLEXCOMM4 - LP_FLEXCOMM4 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM4(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM4_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM4_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM5_MASK (0x1000U)
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM5_SHIFT (12U)
/*! LP_FLEXCOMM5 - LP_FLEXCOMM5 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM5(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM5_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_LP_FLEXCOMM5_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_LPSPI14_MASK     (0x2000U)
#define SLEEPCON0_WAKEUPEN0_CLR_LPSPI14_SHIFT    (13U)
/*! LPSPI14 - LPSPI14 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_LPSPI14(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_LPSPI14_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_LPSPI14_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_LPI2C15_MASK     (0x4000U)
#define SLEEPCON0_WAKEUPEN0_CLR_LPI2C15_SHIFT    (14U)
/*! LPI2C15 - LPI2C15 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_LPI2C15(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_LPI2C15_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_LPI2C15_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_ADC0_MASK        (0x8000U)
#define SLEEPCON0_WAKEUPEN0_CLR_ADC0_SHIFT       (15U)
/*! ADC0 - ADC0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_ADC0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_ADC0_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_ADC0_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_ACMP0_MASK       (0x20000U)
#define SLEEPCON0_WAKEUPEN0_CLR_ACMP0_SHIFT      (17U)
/*! ACMP0 - ACMP0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_ACMP0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_ACMP0_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_ACMP0_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_MICFIL_RD_ERR_MASK (0x40000U)
#define SLEEPCON0_WAKEUPEN0_CLR_MICFIL_RD_ERR_SHIFT (18U)
/*! MICFIL_RD_ERR - MICFIL Read Data Error Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_MICFIL_RD_ERR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_MICFIL_RD_ERR_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_MICFIL_RD_ERR_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_MICFIL_WKUP_MASK (0x80000U)
#define SLEEPCON0_WAKEUPEN0_CLR_MICFIL_WKUP_SHIFT (19U)
/*! MICFIL_WKUP - MICFIL Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_MICFIL_WKUP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_MICFIL_WKUP_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_MICFIL_WKUP_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_RTC0_ALARM_MASK  (0x4000000U)
#define SLEEPCON0_WAKEUPEN0_CLR_RTC0_ALARM_SHIFT (26U)
/*! RTC0_ALARM - RTC0_ALARM Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_RTC0_ALARM(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_RTC0_ALARM_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_RTC0_ALARM_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_RTC0_WKUP_MASK   (0x8000000U)
#define SLEEPCON0_WAKEUPEN0_CLR_RTC0_WKUP_SHIFT  (27U)
/*! RTC0_WKUP - RTC0_WKUP Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_RTC0_WKUP(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_RTC0_WKUP_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_RTC0_WKUP_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_MU0_MUA_MASK     (0x20000000U)
#define SLEEPCON0_WAKEUPEN0_CLR_MU0_MUA_SHIFT    (29U)
/*! MU0_MUA - MU0_MUA Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_MU0_MUA(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_MU0_MUA_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_MU0_MUA_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_MU1_MUA_MASK     (0x40000000U)
#define SLEEPCON0_WAKEUPEN0_CLR_MU1_MUA_SHIFT    (30U)
/*! MU1_MUA - MU1_MUA Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_MU1_MUA(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_MU1_MUA_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_MU1_MUA_MASK)

#define SLEEPCON0_WAKEUPEN0_CLR_MU4_MUA_MASK     (0x80000000U)
#define SLEEPCON0_WAKEUPEN0_CLR_MU4_MUA_SHIFT    (31U)
/*! MU4_MUA - MU4 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN0_CLR_MU4_MUA(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN0_CLR_MU4_MUA_SHIFT)) & SLEEPCON0_WAKEUPEN0_CLR_MU4_MUA_MASK)
/*! @} */

/*! @name WAKEUPEN1_CLR - Wakeup Enable 1 Clear */
/*! @{ */

#define SLEEPCON0_WAKEUPEN1_CLR_CTIMER2_MASK     (0x1U)
#define SLEEPCON0_WAKEUPEN1_CLR_CTIMER2_SHIFT    (0U)
/*! CTIMER2 - CTIMER2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_CTIMER2(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_CTIMER2_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_CTIMER2_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_CTIMER4_MASK     (0x2U)
#define SLEEPCON0_WAKEUPEN1_CLR_CTIMER4_SHIFT    (1U)
/*! CTIMER4 - CTIMER4 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_CTIMER4(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_CTIMER4_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_CTIMER4_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_OSTIMER_MASK     (0x4U)
#define SLEEPCON0_WAKEUPEN1_CLR_OSTIMER_SHIFT    (2U)
/*! OSTIMER - OSTIMER Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_OSTIMER(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_OSTIMER_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_OSTIMER_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM6_MASK (0x8U)
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM6_SHIFT (3U)
/*! LP_FLEXCOMM6 - LP_FLEXCOMM6 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM6(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM6_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM6_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM7_MASK (0x10U)
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM7_SHIFT (4U)
/*! LP_FLEXCOMM7 - LP_FLEXCOMM7 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM7(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM7_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM7_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_I3C0_MASK        (0x80U)
#define SLEEPCON0_WAKEUPEN1_CLR_I3C0_SHIFT       (7U)
/*! I3C0 - I3C0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_I3C0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_I3C0_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_I3C0_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_USB0_MASK        (0x100U)
#define SLEEPCON0_WAKEUPEN1_CLR_USB0_SHIFT       (8U)
/*! USB0 - USB0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_USB0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_USB0_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_USB0_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_USB1_MASK        (0x200U)
#define SLEEPCON0_WAKEUPEN1_CLR_USB1_SHIFT       (9U)
/*! USB1 - USB1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_USB1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_USB1_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_USB1_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_WWDT0_MASK       (0x400U)
#define SLEEPCON0_WAKEUPEN1_CLR_WWDT0_SHIFT      (10U)
/*! WWDT0 - WWDT0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_WWDT0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_WWDT0_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_WWDT0_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_WWDT1_MASK       (0x800U)
#define SLEEPCON0_WAKEUPEN1_CLR_WWDT1_SHIFT      (11U)
/*! WWDT1 - WWDT1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_WWDT1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_WWDT1_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_WWDT1_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_USBPHY0_MASK     (0x1000U)
#define SLEEPCON0_WAKEUPEN1_CLR_USBPHY0_SHIFT    (12U)
/*! USBPHY0 - USBPHY0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_USBPHY0(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_USBPHY0_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_USBPHY0_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_PMIC_IRQN_MASK   (0x4000U)
#define SLEEPCON0_WAKEUPEN1_CLR_PMIC_IRQN_SHIFT  (14U)
/*! PMIC_IRQN - PMIC_IRQN Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_PMIC_IRQN(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_PMIC_IRQN_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_PMIC_IRQN_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM8_MASK (0x8000U)
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM8_SHIFT (15U)
/*! LP_FLEXCOMM8 - LP_FLEXCOMM8 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM8(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM8_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM8_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM9_MASK (0x10000U)
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM9_SHIFT (16U)
/*! LP_FLEXCOMM9 - LP_FLEXCOMM9 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM9(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM9_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM9_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM10_MASK (0x20000U)
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM10_SHIFT (17U)
/*! LP_FLEXCOMM10 - LP_FLEXCOMM10 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM10(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM10_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM10_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM11_MASK (0x40000U)
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM11_SHIFT (18U)
/*! LP_FLEXCOMM11 - LP_FLEXCOMM11 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM11(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM11_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM11_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM12_MASK (0x80000U)
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM12_SHIFT (19U)
/*! LP_FLEXCOMM12 - LP_FLEXCOMM12 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM12(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM12_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM12_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM13_MASK (0x100000U)
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM13_SHIFT (20U)
/*! LP_FLEXCOMM13 - LP_FLEXCOMM13 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM13(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM13_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_LP_FLEXCOMM13_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_LPSPI16_MASK     (0x200000U)
#define SLEEPCON0_WAKEUPEN1_CLR_LPSPI16_SHIFT    (21U)
/*! LPSPI16 - LPSPI16 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_LPSPI16(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_LPSPI16_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_LPSPI16_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_I3C1_MASK        (0x400000U)
#define SLEEPCON0_WAKEUPEN1_CLR_I3C1_SHIFT       (22U)
/*! I3C1 - I3C1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_I3C1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_I3C1_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_I3C1_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_FLEXIO_MASK      (0x800000U)
#define SLEEPCON0_WAKEUPEN1_CLR_FLEXIO_SHIFT     (23U)
/*! FLEXIO - FLEXIO Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_FLEXIO(x)        (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_FLEXIO_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_FLEXIO_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH0_MASK   (0x8000000U)
#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH0_SHIFT  (27U)
/*! EDMA0_CH0 - eDMA0 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH0_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH1_MASK   (0x10000000U)
#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH1_SHIFT  (28U)
/*! EDMA0_CH1 - eDMA0 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH1_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH2_MASK   (0x20000000U)
#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH2_SHIFT  (29U)
/*! EDMA0_CH2 - eDMA0 Channel 2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH2(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH2_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH2_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH3_MASK   (0x40000000U)
#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH3_SHIFT  (30U)
/*! EDMA0_CH3 - eDMA0 Channel 3 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH3(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH3_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH3_MASK)

#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH4_MASK   (0x80000000U)
#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH4_SHIFT  (31U)
/*! EDMA0_CH4 - eDMA0 Channel 4 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH4(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH4_SHIFT)) & SLEEPCON0_WAKEUPEN1_CLR_EDMA0_CH4_MASK)
/*! @} */

/*! @name WAKEUPEN2_CLR - Wakeup Enable 2 Clear */
/*! @{ */

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH5_MASK   (0x1U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH5_SHIFT  (0U)
/*! EDMA0_CH5 - eDMA0 Channel 5 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH5(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH5_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH5_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH6_MASK   (0x2U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH6_SHIFT  (1U)
/*! EDMA0_CH6 - eDMA0 Channel 6 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH6(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH6_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH6_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH7_MASK   (0x4U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH7_SHIFT  (2U)
/*! EDMA0_CH7 - eDMA0 Channel 7 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH7(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH7_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH7_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH8_MASK   (0x8U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH8_SHIFT  (3U)
/*! EDMA0_CH8 - eDMA0 Channel 8 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH8(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH8_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH8_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH9_MASK   (0x10U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH9_SHIFT  (4U)
/*! EDMA0_CH9 - eDMA0 Channel 9 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH9(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH9_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH9_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH10_MASK  (0x20U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH10_SHIFT (5U)
/*! EDMA0_CH10 - eDMA0 Channel 10 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH10(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH10_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH10_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH11_MASK  (0x40U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH11_SHIFT (6U)
/*! EDMA0_CH11 - eDMA0 Channel 11 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH11(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH11_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH11_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH12_MASK  (0x80U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH12_SHIFT (7U)
/*! EDMA0_CH12 - eDMA0 Channel 12 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH12(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH12_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH12_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH13_MASK  (0x100U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH13_SHIFT (8U)
/*! EDMA0_CH13 - eDMA0 Channel 13 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH13(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH13_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH13_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH14_MASK  (0x200U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH14_SHIFT (9U)
/*! EDMA0_CH14 - eDMA0 Channel 14 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH14(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH14_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH14_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH15_MASK  (0x400U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH15_SHIFT (10U)
/*! EDMA0_CH15 - eDMA0 Channel 15 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH15(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH15_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA0_CH15_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH0_MASK   (0x800U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH0_SHIFT  (11U)
/*! EDMA1_CH0 - eDMA1 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH0_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH1_MASK   (0x1000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH1_SHIFT  (12U)
/*! EDMA1_CH1 - eDMA1 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH1_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH2_MASK   (0x2000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH2_SHIFT  (13U)
/*! EDMA1_CH2 - eDMA1 Channel 2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH2(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH2_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH2_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH3_MASK   (0x4000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH3_SHIFT  (14U)
/*! EDMA1_CH3 - eDMA1 Channel 3 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH3(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH3_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH3_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH4_MASK   (0x8000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH4_SHIFT  (15U)
/*! EDMA1_CH4 - eDMA1 Channel 4 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH4(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH4_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH4_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH5_MASK   (0x10000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH5_SHIFT  (16U)
/*! EDMA1_CH5 - eDMA1 Channel 5 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH5(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH5_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH5_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH6_MASK   (0x20000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH6_SHIFT  (17U)
/*! EDMA1_CH6 - eDMA1 Channel 6 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH6(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH6_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH6_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH7_MASK   (0x40000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH7_SHIFT  (18U)
/*! EDMA1_CH7 - eDMA1 Channel 7 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH7(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH7_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH7_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH8_MASK   (0x80000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH8_SHIFT  (19U)
/*! EDMA1_CH8 - eDMA1 Channel 8 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH8(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH8_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH8_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH9_MASK   (0x100000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH9_SHIFT  (20U)
/*! EDMA1_CH9 - eDMA1 Channel 9 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH9(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH9_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH9_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH10_MASK  (0x200000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH10_SHIFT (21U)
/*! EDMA1_CH10 - eDMA1 Channel 10 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH10(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH10_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH10_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH11_MASK  (0x400000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH11_SHIFT (22U)
/*! EDMA1_CH11 - eDMA1 Channel 11 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH11(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH11_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH11_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH12_MASK  (0x800000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH12_SHIFT (23U)
/*! EDMA1_CH12 - eDMA1 Channel 12 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH12(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH12_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH12_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH13_MASK  (0x1000000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH13_SHIFT (24U)
/*! EDMA1_CH13 - eDMA1 Channel 13 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH13(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH13_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH13_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH14_MASK  (0x2000000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH14_SHIFT (25U)
/*! EDMA1_CH14 - eDMA1 Channel 14 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH14(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH14_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH14_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH15_MASK  (0x4000000U)
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH15_SHIFT (26U)
/*! EDMA1_CH15 - eDMA1 Channel 15 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH15(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH15_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_EDMA1_CH15_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_GPIO0_CH0_MASK   (0x8000000U)
#define SLEEPCON0_WAKEUPEN2_CLR_GPIO0_CH0_SHIFT  (27U)
/*! GPIO0_CH0 - GPIO0 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_GPIO0_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_GPIO0_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_GPIO0_CH0_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_GPIO0_CH1_MASK   (0x10000000U)
#define SLEEPCON0_WAKEUPEN2_CLR_GPIO0_CH1_SHIFT  (28U)
/*! GPIO0_CH1 - GPIO0 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_GPIO0_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_GPIO0_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_GPIO0_CH1_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_GPIO1_CH0_MASK   (0x20000000U)
#define SLEEPCON0_WAKEUPEN2_CLR_GPIO1_CH0_SHIFT  (29U)
/*! GPIO1_CH0 - GPIO1 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_GPIO1_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_GPIO1_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_GPIO1_CH0_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_GPIO1_CH1_MASK   (0x40000000U)
#define SLEEPCON0_WAKEUPEN2_CLR_GPIO1_CH1_SHIFT  (30U)
/*! GPIO1_CH1 - GPIO1 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_GPIO1_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_GPIO1_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_GPIO1_CH1_MASK)

#define SLEEPCON0_WAKEUPEN2_CLR_GPIO2_CH0_MASK   (0x80000000U)
#define SLEEPCON0_WAKEUPEN2_CLR_GPIO2_CH0_SHIFT  (31U)
/*! GPIO2_CH0 - GPIO2 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN2_CLR_GPIO2_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN2_CLR_GPIO2_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN2_CLR_GPIO2_CH0_MASK)
/*! @} */

/*! @name WAKEUPEN3_CLR - Wakeup Enable 3 Clear */
/*! @{ */

#define SLEEPCON0_WAKEUPEN3_CLR_GPIO2_CH1_MASK   (0x1U)
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO2_CH1_SHIFT  (0U)
/*! GPIO2_CH1 - GPIO2 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO2_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_GPIO2_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_GPIO2_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_GPIO3_CH0_MASK   (0x2U)
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO3_CH0_SHIFT  (1U)
/*! GPIO3_CH0 - GPIO3 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO3_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_GPIO3_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_GPIO3_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_GPIO3_CH1_MASK   (0x4U)
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO3_CH1_SHIFT  (2U)
/*! GPIO3_CH1 - GPIO3 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO3_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_GPIO3_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_GPIO3_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_GPIO4_CH0_MASK   (0x8U)
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO4_CH0_SHIFT  (3U)
/*! GPIO4_CH0 - GPIO4 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO4_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_GPIO4_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_GPIO4_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_GPIO4_CH1_MASK   (0x10U)
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO4_CH1_SHIFT  (4U)
/*! GPIO4_CH1 - GPIO4 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO4_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_GPIO4_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_GPIO4_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_GPIO5_CH0_MASK   (0x20U)
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO5_CH0_SHIFT  (5U)
/*! GPIO5_CH0 - GPIO5 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO5_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_GPIO5_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_GPIO5_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_GPIO5_CH1_MASK   (0x40U)
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO5_CH1_SHIFT  (6U)
/*! GPIO5_CH1 - GPIO5 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO5_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_GPIO5_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_GPIO5_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_GPIO6_CH0_MASK   (0x80U)
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO6_CH0_SHIFT  (7U)
/*! GPIO6_CH0 - GPIO6 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO6_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_GPIO6_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_GPIO6_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_GPIO6_CH1_MASK   (0x100U)
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO6_CH1_SHIFT  (8U)
/*! GPIO6_CH1 - GPIO6 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO6_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_GPIO6_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_GPIO6_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_GPIO7_CH0_MASK   (0x200U)
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO7_CH0_SHIFT  (9U)
/*! GPIO7_CH0 - GPIO7 Channel 0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO7_CH0(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_GPIO7_CH0_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_GPIO7_CH0_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_GPIO7_CH1_MASK   (0x400U)
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO7_CH1_SHIFT  (10U)
/*! GPIO7_CH1 - GPIO7 Channel 1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_GPIO7_CH1(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_GPIO7_CH1_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_GPIO7_CH1_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR0_MASK (0x800U)
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR0_SHIFT (11U)
/*! PINT0_INTR0 - PINT0_INTR0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR0(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR0_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR0_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR1_MASK (0x1000U)
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR1_SHIFT (12U)
/*! PINT0_INTR1 - PINT0_INTR1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR1(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR1_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR1_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR2_MASK (0x2000U)
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR2_SHIFT (13U)
/*! PINT0_INTR2 - PINT0_INTR2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR2(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR2_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR2_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR3_MASK (0x4000U)
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR3_SHIFT (14U)
/*! PINT0_INTR3 - PINT0_INTR3 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR3(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR3_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR3_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR4_MASK (0x8000U)
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR4_SHIFT (15U)
/*! PINT0_INTR4 - PINT0_INTR4 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR4(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR4_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR4_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR5_MASK (0x10000U)
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR5_SHIFT (16U)
/*! PINT0_INTR5 - PINT0_INTR5 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR5(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR5_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR5_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR6_MASK (0x20000U)
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR6_SHIFT (17U)
/*! PINT0_INTR6 - PINT0_INTR6 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR6(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR6_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR6_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR7_MASK (0x40000U)
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR7_SHIFT (18U)
/*! PINT0_INTR7 - PINT0_INTR7 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR7(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR7_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_PINT0_INTR7_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_SAI0_MASK        (0x80000U)
#define SLEEPCON0_WAKEUPEN3_CLR_SAI0_SHIFT       (19U)
/*! SAI0 - SAI0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_SAI0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_SAI0_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_SAI0_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_SAI1_MASK        (0x100000U)
#define SLEEPCON0_WAKEUPEN3_CLR_SAI1_SHIFT       (20U)
/*! SAI1 - SAI1 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_SAI1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_SAI1_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_SAI1_MASK)

#define SLEEPCON0_WAKEUPEN3_CLR_SAI2_MASK        (0x200000U)
#define SLEEPCON0_WAKEUPEN3_CLR_SAI2_SHIFT       (21U)
/*! SAI2 - SAI2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN3_CLR_SAI2(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN3_CLR_SAI2_SHIFT)) & SLEEPCON0_WAKEUPEN3_CLR_SAI2_MASK)
/*! @} */

/*! @name WAKEUPEN4_CLR - Wakeup Enable 4 Clear */
/*! @{ */

#define SLEEPCON0_WAKEUPEN4_CLR_ITRC_MASK        (0x10U)
#define SLEEPCON0_WAKEUPEN4_CLR_ITRC_SHIFT       (4U)
/*! ITRC - ITRC Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN4_CLR_ITRC(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_CLR_ITRC_SHIFT)) & SLEEPCON0_WAKEUPEN4_CLR_ITRC_MASK)

#define SLEEPCON0_WAKEUPEN4_CLR_PMC0_MASK        (0x400U)
#define SLEEPCON0_WAKEUPEN4_CLR_PMC0_SHIFT       (10U)
/*! PMC0 - PMC0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN4_CLR_PMC0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_CLR_PMC0_SHIFT)) & SLEEPCON0_WAKEUPEN4_CLR_PMC0_MASK)

#define SLEEPCON0_WAKEUPEN4_CLR_FRO0_MASK        (0x4000000U)
#define SLEEPCON0_WAKEUPEN4_CLR_FRO0_SHIFT       (26U)
/*! FRO0 - FRO0 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN4_CLR_FRO0(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_CLR_FRO0_SHIFT)) & SLEEPCON0_WAKEUPEN4_CLR_FRO0_MASK)

#define SLEEPCON0_WAKEUPEN4_CLR_FRO1_MASK        (0x8000000U)
#define SLEEPCON0_WAKEUPEN4_CLR_FRO1_SHIFT       (27U)
/*! FRO1 - FRO1 Wake-up Enable
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN4_CLR_FRO1(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_CLR_FRO1_SHIFT)) & SLEEPCON0_WAKEUPEN4_CLR_FRO1_MASK)

#define SLEEPCON0_WAKEUPEN4_CLR_FRO2_MASK        (0x10000000U)
#define SLEEPCON0_WAKEUPEN4_CLR_FRO2_SHIFT       (28U)
/*! FRO2 - FRO2 Wake-up Enable Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_WAKEUPEN4_CLR_FRO2(x)          (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_WAKEUPEN4_CLR_FRO2_SHIFT)) & SLEEPCON0_WAKEUPEN4_CLR_FRO2_MASK)
/*! @} */

/*! @name PWRDOWN_WAIT - Power Down Wait */
/*! @{ */

#define SLEEPCON0_PWRDOWN_WAIT_IGN_FRO0PDR_MASK  (0x1U)
#define SLEEPCON0_PWRDOWN_WAIT_IGN_FRO0PDR_SHIFT (0U)
/*! IGN_FRO0PDR - Ignore FRO0 Power Down Ready Signal
 *  0b0..Waits
 *  0b1..Ignores
 */
#define SLEEPCON0_PWRDOWN_WAIT_IGN_FRO0PDR(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PWRDOWN_WAIT_IGN_FRO0PDR_SHIFT)) & SLEEPCON0_PWRDOWN_WAIT_IGN_FRO0PDR_MASK)

#define SLEEPCON0_PWRDOWN_WAIT_IGN_FRO1PDR_MASK  (0x2U)
#define SLEEPCON0_PWRDOWN_WAIT_IGN_FRO1PDR_SHIFT (1U)
/*! IGN_FRO1PDR - Ignore FRO1 Power Down Ready Signals
 *  0b0..Waits
 *  0b1..Ignores
 */
#define SLEEPCON0_PWRDOWN_WAIT_IGN_FRO1PDR(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PWRDOWN_WAIT_IGN_FRO1PDR_SHIFT)) & SLEEPCON0_PWRDOWN_WAIT_IGN_FRO1PDR_MASK)

#define SLEEPCON0_PWRDOWN_WAIT_IGN_FRO2PDR_MASK  (0x4U)
#define SLEEPCON0_PWRDOWN_WAIT_IGN_FRO2PDR_SHIFT (2U)
/*! IGN_FRO2PDR - Ignore FRO2 Power Down Ready Signals
 *  0b0..Waits
 *  0b1..Ignores
 */
#define SLEEPCON0_PWRDOWN_WAIT_IGN_FRO2PDR(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PWRDOWN_WAIT_IGN_FRO2PDR_SHIFT)) & SLEEPCON0_PWRDOWN_WAIT_IGN_FRO2PDR_MASK)

#define SLEEPCON0_PWRDOWN_WAIT_IGN_LPOSCPDR_MASK (0x8U)
#define SLEEPCON0_PWRDOWN_WAIT_IGN_LPOSCPDR_SHIFT (3U)
/*! IGN_LPOSCPDR - Ignore LPOSC Power Down Ready Signals
 *  0b0..Waits
 *  0b1..Ignores
 */
#define SLEEPCON0_PWRDOWN_WAIT_IGN_LPOSCPDR(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PWRDOWN_WAIT_IGN_LPOSCPDR_SHIFT)) & SLEEPCON0_PWRDOWN_WAIT_IGN_LPOSCPDR_MASK)
/*! @} */

/*! @name HW_WAKE - eDMA Wakeup Enable */
/*! @{ */

#define SLEEPCON0_HW_WAKE_HWWK_SRC1_MASK         (0x2U)
#define SLEEPCON0_HW_WAKE_HWWK_SRC1_SHIFT        (1U)
/*! HWWK_SRC1 - eDMA Wakeup Source 1
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_HW_WAKE_HWWK_SRC1(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_HWWK_SRC1_SHIFT)) & SLEEPCON0_HW_WAKE_HWWK_SRC1_MASK)

#define SLEEPCON0_HW_WAKE_HWWK_SRC2_MASK         (0x4U)
#define SLEEPCON0_HW_WAKE_HWWK_SRC2_SHIFT        (2U)
/*! HWWK_SRC2 - eDMA Wakeup Source 2
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_HW_WAKE_HWWK_SRC2(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_HWWK_SRC2_SHIFT)) & SLEEPCON0_HW_WAKE_HWWK_SRC2_MASK)

#define SLEEPCON0_HW_WAKE_HWWK_SRC3_MASK         (0x8U)
#define SLEEPCON0_HW_WAKE_HWWK_SRC3_SHIFT        (3U)
/*! HWWK_SRC3 - eDMA Wakeup source 3
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_HW_WAKE_HWWK_SRC3(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_HWWK_SRC3_SHIFT)) & SLEEPCON0_HW_WAKE_HWWK_SRC3_MASK)

#define SLEEPCON0_HW_WAKE_HWWK_SRC4_MASK         (0x10U)
#define SLEEPCON0_HW_WAKE_HWWK_SRC4_SHIFT        (4U)
/*! HWWK_SRC4 - eDMA Wakeup Source 4
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_HW_WAKE_HWWK_SRC4(x)           (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_HWWK_SRC4_SHIFT)) & SLEEPCON0_HW_WAKE_HWWK_SRC4_MASK)
/*! @} */

/*! @name HW_WAKE_SET - eDMA Wakeup Set */
/*! @{ */

#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC1_SET_MASK (0x2U)
#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC1_SET_SHIFT (1U)
/*! HWWK_SRC1_SET - eDMA Wakeup Source 1 Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC1_SET(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_SET_HWWK_SRC1_SET_SHIFT)) & SLEEPCON0_HW_WAKE_SET_HWWK_SRC1_SET_MASK)

#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC2_SET_MASK (0x4U)
#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC2_SET_SHIFT (2U)
/*! HWWK_SRC2_SET - eDMA Wakeup Source 2 Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC2_SET(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_SET_HWWK_SRC2_SET_SHIFT)) & SLEEPCON0_HW_WAKE_SET_HWWK_SRC2_SET_MASK)

#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC3_SET_MASK (0x8U)
#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC3_SET_SHIFT (3U)
/*! HWWK_SRC3_SET - eDMA Wakeup Source 3 Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC3_SET(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_SET_HWWK_SRC3_SET_SHIFT)) & SLEEPCON0_HW_WAKE_SET_HWWK_SRC3_SET_MASK)

#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC4_SET_MASK (0x10U)
#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC4_SET_SHIFT (4U)
/*! HWWK_SRC4_SET - eDMA Wakeup Source 4 Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_HW_WAKE_SET_HWWK_SRC4_SET(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_SET_HWWK_SRC4_SET_SHIFT)) & SLEEPCON0_HW_WAKE_SET_HWWK_SRC4_SET_MASK)
/*! @} */

/*! @name HW_WAKE_CLR - eDMA Wakeup Clear */
/*! @{ */

#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC1_CLR_MASK (0x2U)
#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC1_CLR_SHIFT (1U)
/*! HWWK_SRC1_CLR - eDMA Wakeup Source 1 Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC1_CLR(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_CLR_HWWK_SRC1_CLR_SHIFT)) & SLEEPCON0_HW_WAKE_CLR_HWWK_SRC1_CLR_MASK)

#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC2_CLR_MASK (0x4U)
#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC2_CLR_SHIFT (2U)
/*! HWWK_SRC2_CLR - eDMA Wakeup Source 2 Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC2_CLR(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_CLR_HWWK_SRC2_CLR_SHIFT)) & SLEEPCON0_HW_WAKE_CLR_HWWK_SRC2_CLR_MASK)

#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC3_CLR_MASK (0x8U)
#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC3_CLR_SHIFT (3U)
/*! HWWK_SRC3_CLR - eDMA Wakeup Source 3 Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC3_CLR(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_CLR_HWWK_SRC3_CLR_SHIFT)) & SLEEPCON0_HW_WAKE_CLR_HWWK_SRC3_CLR_MASK)

#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC4_CLR_MASK (0x10U)
#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC4_CLR_SHIFT (4U)
/*! HWWK_SRC4_CLR - eDMA Wakeup Source 4 Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_HW_WAKE_CLR_HWWK_SRC4_CLR(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_HW_WAKE_CLR_HWWK_SRC4_CLR_SHIFT)) & SLEEPCON0_HW_WAKE_CLR_HWWK_SRC4_CLR_MASK)
/*! @} */

/*! @name SHARED_MASK0 - Shared Resources Mask */
/*! @{ */

#define SLEEPCON0_SHARED_MASK0_ADC0_MASK_MASK    (0x1U)
#define SLEEPCON0_SHARED_MASK0_ADC0_MASK_SHIFT   (0U)
/*! ADC0_MASK - ADC0 Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_ADC0_MASK(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_ADC0_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_ADC0_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_ACMP0_MASK_MASK   (0x2U)
#define SLEEPCON0_SHARED_MASK0_ACMP0_MASK_SHIFT  (1U)
/*! ACMP0_MASK - ACMP0 Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_ACMP0_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_ACMP0_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_ACMP0_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_MICFIL_MASK_MASK  (0x4U)
#define SLEEPCON0_SHARED_MASK0_MICFIL_MASK_SHIFT (2U)
/*! MICFIL_MASK - MICFIL Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_MICFIL_MASK(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_MICFIL_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_MICFIL_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_LPI2C15_MASK_MASK (0x8U)
#define SLEEPCON0_SHARED_MASK0_LPI2C15_MASK_SHIFT (3U)
/*! LPI2C15_MASK - LPI2C15 Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_LPI2C15_MASK(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_LPI2C15_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_LPI2C15_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_GDET3_MASK_MASK   (0x20U)
#define SLEEPCON0_SHARED_MASK0_GDET3_MASK_SHIFT  (5U)
/*! GDET3_MASK - GDET3 Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_GDET3_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_GDET3_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_GDET3_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_RTC_MASK_MASK     (0x40U)
#define SLEEPCON0_SHARED_MASK0_RTC_MASK_SHIFT    (6U)
/*! RTC_MASK - Mask bit of RTC0 and RTC1
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_RTC_MASK(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_RTC_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_RTC_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_VGPU_MASK_MASK    (0x10000U)
#define SLEEPCON0_SHARED_MASK0_VGPU_MASK_SHIFT   (16U)
/*! VGPU_MASK - VGPU Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_VGPU_MASK(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_VGPU_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_VGPU_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_EZHV_MASK_MASK    (0x20000U)
#define SLEEPCON0_SHARED_MASK0_EZHV_MASK_SHIFT   (17U)
/*! EZHV_MASK - EZH-V Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_EZHV_MASK(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_EZHV_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_EZHV_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_XSPI2_MASK_MASK   (0x40000U)
#define SLEEPCON0_SHARED_MASK0_XSPI2_MASK_SHIFT  (18U)
/*! XSPI2_MASK - XSPI2 Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_XSPI2_MASK(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_XSPI2_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_XSPI2_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_LPSPI14_MASK_MASK (0x80000U)
#define SLEEPCON0_SHARED_MASK0_LPSPI14_MASK_SHIFT (19U)
/*! LPSPI14_MASK - LPSPI14 Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_LPSPI14_MASK(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_LPSPI14_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_LPSPI14_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_LPSPI16_MASK_MASK (0x100000U)
#define SLEEPCON0_SHARED_MASK0_LPSPI16_MASK_SHIFT (20U)
/*! LPSPI16_MASK - LPSPI16 Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_LPSPI16_MASK(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_LPSPI16_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_LPSPI16_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_FLEXIO_MASK_MASK  (0x200000U)
#define SLEEPCON0_SHARED_MASK0_FLEXIO_MASK_SHIFT (21U)
/*! FLEXIO_MASK - FLEXIO Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_FLEXIO_MASK(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_FLEXIO_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_FLEXIO_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_NIC0_MASK_MASK    (0x400000U)
#define SLEEPCON0_SHARED_MASK0_NIC0_MASK_SHIFT   (22U)
/*! NIC0_MASK - NIC_MEDIA0 Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_NIC0_MASK(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_NIC0_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_NIC0_MASK_MASK)

#define SLEEPCON0_SHARED_MASK0_NIC1_MASK_MASK    (0x800000U)
#define SLEEPCON0_SHARED_MASK0_NIC1_MASK_SHIFT   (23U)
/*! NIC1_MASK - NIC_MEDIA1 Mask
 *  0b0..Disables
 *  0b1..Enables
 */
#define SLEEPCON0_SHARED_MASK0_NIC1_MASK(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_NIC1_MASK_SHIFT)) & SLEEPCON0_SHARED_MASK0_NIC1_MASK_MASK)
/*! @} */

/*! @name SHARED_MASK0_SET - Shared Resources Mask Set */
/*! @{ */

#define SLEEPCON0_SHARED_MASK0_SET_ADC0_MASK_SET_MASK (0x1U)
#define SLEEPCON0_SHARED_MASK0_SET_ADC0_MASK_SET_SHIFT (0U)
/*! ADC0_MASK_SET - ADC0 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_ADC0_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_ADC0_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_ADC0_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_ACMP0_MASK_SET_MASK (0x2U)
#define SLEEPCON0_SHARED_MASK0_SET_ACMP0_MASK_SET_SHIFT (1U)
/*! ACMP0_MASK_SET - ACMP0 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_ACMP0_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_ACMP0_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_ACMP0_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_MICFIL_MASK_SET_MASK (0x4U)
#define SLEEPCON0_SHARED_MASK0_SET_MICFIL_MASK_SET_SHIFT (2U)
/*! MICFIL_MASK_SET - MICFIL Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_MICFIL_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_MICFIL_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_MICFIL_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_LPI2C15_MASK_SET_MASK (0x8U)
#define SLEEPCON0_SHARED_MASK0_SET_LPI2C15_MASK_SET_SHIFT (3U)
/*! LPI2C15_MASK_SET - LPI2C15 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_LPI2C15_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_LPI2C15_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_LPI2C15_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_GDET3_MASK_SET_MASK (0x20U)
#define SLEEPCON0_SHARED_MASK0_SET_GDET3_MASK_SET_SHIFT (5U)
/*! GDET3_MASK_SET - GDET3 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_GDET3_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_GDET3_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_GDET3_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_RTC_MASK_SET_MASK (0x40U)
#define SLEEPCON0_SHARED_MASK0_SET_RTC_MASK_SET_SHIFT (6U)
/*! RTC_MASK_SET - RTC0 and RTC1 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_RTC_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_RTC_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_RTC_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_VGPU_MASK_SET_MASK (0x10000U)
#define SLEEPCON0_SHARED_MASK0_SET_VGPU_MASK_SET_SHIFT (16U)
/*! VGPU_MASK_SET - VGPU Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_VGPU_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_VGPU_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_VGPU_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_EZHV_MASK_SET_MASK (0x20000U)
#define SLEEPCON0_SHARED_MASK0_SET_EZHV_MASK_SET_SHIFT (17U)
/*! EZHV_MASK_SET - EZH-V Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_EZHV_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_EZHV_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_EZHV_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_XSPI2_MASK_SET_MASK (0x40000U)
#define SLEEPCON0_SHARED_MASK0_SET_XSPI2_MASK_SET_SHIFT (18U)
/*! XSPI2_MASK_SET - XSPI2 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_XSPI2_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_XSPI2_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_XSPI2_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_LPSPI14_MASK_SET_MASK (0x80000U)
#define SLEEPCON0_SHARED_MASK0_SET_LPSPI14_MASK_SET_SHIFT (19U)
/*! LPSPI14_MASK_SET - LPSPI14 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_LPSPI14_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_LPSPI14_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_LPSPI14_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_LPSPI16_MASK_SET_MASK (0x100000U)
#define SLEEPCON0_SHARED_MASK0_SET_LPSPI16_MASK_SET_SHIFT (20U)
/*! LPSPI16_MASK_SET - LPSPI16 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_LPSPI16_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_LPSPI16_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_LPSPI16_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_FLEXIO_MASK_SET_MASK (0x200000U)
#define SLEEPCON0_SHARED_MASK0_SET_FLEXIO_MASK_SET_SHIFT (21U)
/*! FLEXIO_MASK_SET - FLEXIO Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_FLEXIO_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_FLEXIO_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_FLEXIO_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_NIC0_MASK_SET_MASK (0x400000U)
#define SLEEPCON0_SHARED_MASK0_SET_NIC0_MASK_SET_SHIFT (22U)
/*! NIC0_MASK_SET - NIC_MEDIA0 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_NIC0_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_NIC0_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_NIC0_MASK_SET_MASK)

#define SLEEPCON0_SHARED_MASK0_SET_NIC1_MASK_SET_MASK (0x800000U)
#define SLEEPCON0_SHARED_MASK0_SET_NIC1_MASK_SET_SHIFT (23U)
/*! NIC1_MASK_SET - NIC_MEDIA1 Mask Set
 *  0b0..No effect
 *  0b1..Sets the bit
 */
#define SLEEPCON0_SHARED_MASK0_SET_NIC1_MASK_SET(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_SET_NIC1_MASK_SET_SHIFT)) & SLEEPCON0_SHARED_MASK0_SET_NIC1_MASK_SET_MASK)
/*! @} */

/*! @name SHARED_MASK0_CLR - Shared Resources Mask Clear */
/*! @{ */

#define SLEEPCON0_SHARED_MASK0_CLR_ADC0_MASK_CLR_MASK (0x1U)
#define SLEEPCON0_SHARED_MASK0_CLR_ADC0_MASK_CLR_SHIFT (0U)
/*! ADC0_MASK_CLR - ADC0 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_ADC0_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_ADC0_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_ADC0_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_ACMP0_MASK_CLR_MASK (0x2U)
#define SLEEPCON0_SHARED_MASK0_CLR_ACMP0_MASK_CLR_SHIFT (1U)
/*! ACMP0_MASK_CLR - ACMP0 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_ACMP0_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_ACMP0_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_ACMP0_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_MICFIL_MASK_CLR_MASK (0x4U)
#define SLEEPCON0_SHARED_MASK0_CLR_MICFIL_MASK_CLR_SHIFT (2U)
/*! MICFIL_MASK_CLR - MICFIL Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_MICFIL_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_MICFIL_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_MICFIL_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_LPI2C15_MASK_CLR_MASK (0x8U)
#define SLEEPCON0_SHARED_MASK0_CLR_LPI2C15_MASK_CLR_SHIFT (3U)
/*! LPI2C15_MASK_CLR - LPI2C15 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_LPI2C15_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_LPI2C15_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_LPI2C15_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_GDET3_MASK_CLR_MASK (0x20U)
#define SLEEPCON0_SHARED_MASK0_CLR_GDET3_MASK_CLR_SHIFT (5U)
/*! GDET3_MASK_CLR - GDET3 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_GDET3_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_GDET3_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_GDET3_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_RTC_MASK_CLR_MASK (0x40U)
#define SLEEPCON0_SHARED_MASK0_CLR_RTC_MASK_CLR_SHIFT (6U)
/*! RTC_MASK_CLR - RTC0 and RTC1 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_RTC_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_RTC_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_RTC_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_VGPU_MASK_CLR_MASK (0x10000U)
#define SLEEPCON0_SHARED_MASK0_CLR_VGPU_MASK_CLR_SHIFT (16U)
/*! VGPU_MASK_CLR - VGPU Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_VGPU_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_VGPU_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_VGPU_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_EZHV_MASK_CLR_MASK (0x20000U)
#define SLEEPCON0_SHARED_MASK0_CLR_EZHV_MASK_CLR_SHIFT (17U)
/*! EZHV_MASK_CLR - EZH-V Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_EZHV_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_EZHV_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_EZHV_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_XSPI2_MASK_CLR_MASK (0x40000U)
#define SLEEPCON0_SHARED_MASK0_CLR_XSPI2_MASK_CLR_SHIFT (18U)
/*! XSPI2_MASK_CLR - XSPI2 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_XSPI2_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_XSPI2_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_XSPI2_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_LPSPI14_MASK_CLR_MASK (0x80000U)
#define SLEEPCON0_SHARED_MASK0_CLR_LPSPI14_MASK_CLR_SHIFT (19U)
/*! LPSPI14_MASK_CLR - LPSPI14 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_LPSPI14_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_LPSPI14_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_LPSPI14_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_LPSPI16_MASK_CLR_MASK (0x100000U)
#define SLEEPCON0_SHARED_MASK0_CLR_LPSPI16_MASK_CLR_SHIFT (20U)
/*! LPSPI16_MASK_CLR - LPSPI16 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_LPSPI16_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_LPSPI16_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_LPSPI16_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_FLEXIO_MASK_CLR_MASK (0x200000U)
#define SLEEPCON0_SHARED_MASK0_CLR_FLEXIO_MASK_CLR_SHIFT (21U)
/*! FLEXIO_MASK_CLR - FLEXIO Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_FLEXIO_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_FLEXIO_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_FLEXIO_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_NIC0_MASK_CLR_MASK (0x400000U)
#define SLEEPCON0_SHARED_MASK0_CLR_NIC0_MASK_CLR_SHIFT (22U)
/*! NIC0_MASK_CLR - NIC_MEDIA0 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_NIC0_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_NIC0_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_NIC0_MASK_CLR_MASK)

#define SLEEPCON0_SHARED_MASK0_CLR_NIC1_MASK_CLR_MASK (0x800000U)
#define SLEEPCON0_SHARED_MASK0_CLR_NIC1_MASK_CLR_SHIFT (23U)
/*! NIC1_MASK_CLR - NIC_MEDIA1 Mask Clear
 *  0b0..No effect
 *  0b1..Clears the bit
 */
#define SLEEPCON0_SHARED_MASK0_CLR_NIC1_MASK_CLR(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHARED_MASK0_CLR_NIC1_MASK_CLR_SHIFT)) & SLEEPCON0_SHARED_MASK0_CLR_NIC1_MASK_CLR_MASK)
/*! @} */

/*! @name SHA_MED_CCTRL0 - Media Domain Shared Controller Low-power Control */
/*! @{ */

#define SLEEPCON0_SHA_MED_CCTRL0_VGPU_LPREQ_MASK (0x1U)
#define SLEEPCON0_SHA_MED_CCTRL0_VGPU_LPREQ_SHIFT (0U)
/*! VGPU_LPREQ - VGPU Low-Power Control
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_CCTRL0_VGPU_LPREQ(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_CCTRL0_VGPU_LPREQ_SHIFT)) & SLEEPCON0_SHA_MED_CCTRL0_VGPU_LPREQ_MASK)

#define SLEEPCON0_SHA_MED_CCTRL0_EZHV_STOP_MASK  (0x2U)
#define SLEEPCON0_SHA_MED_CCTRL0_EZHV_STOP_SHIFT (1U)
/*! EZHV_STOP - EZH-V Stop Control
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_CCTRL0_EZHV_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_CCTRL0_EZHV_STOP_SHIFT)) & SLEEPCON0_SHA_MED_CCTRL0_EZHV_STOP_MASK)

#define SLEEPCON0_SHA_MED_CCTRL0_EZHV_HALT_MASK  (0x4U)
#define SLEEPCON0_SHA_MED_CCTRL0_EZHV_HALT_SHIFT (2U)
/*! EZHV_HALT - EZH-V Halt Control
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_CCTRL0_EZHV_HALT(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_CCTRL0_EZHV_HALT_SHIFT)) & SLEEPCON0_SHA_MED_CCTRL0_EZHV_HALT_MASK)

#define SLEEPCON0_SHA_MED_CCTRL0_EZHV_EXIT_WAIT_MASK (0x8U)
#define SLEEPCON0_SHA_MED_CCTRL0_EZHV_EXIT_WAIT_SHIFT (3U)
/*! EZHV_EXIT_WAIT - EZH-V Exit Wait Mode
 *  0b0..No request
 *  0b1..Sends
 */
#define SLEEPCON0_SHA_MED_CCTRL0_EZHV_EXIT_WAIT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_CCTRL0_EZHV_EXIT_WAIT_SHIFT)) & SLEEPCON0_SHA_MED_CCTRL0_EZHV_EXIT_WAIT_MASK)
/*! @} */

/*! @name SHA_MED_TCTRL0 - Media Domain Shared Resources Target Low-power Control */
/*! @{ */

#define SLEEPCON0_SHA_MED_TCTRL0_XSPI2_STOP_MASK (0x1U)
#define SLEEPCON0_SHA_MED_TCTRL0_XSPI2_STOP_SHIFT (0U)
/*! XSPI2_STOP - XSPI2 Stop Control
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_TCTRL0_XSPI2_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_TCTRL0_XSPI2_STOP_SHIFT)) & SLEEPCON0_SHA_MED_TCTRL0_XSPI2_STOP_MASK)

#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI14_B_LPREQ_MASK (0x8U)
#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI14_B_LPREQ_SHIFT (3U)
/*! LPSPI14_B_LPREQ - LPSPI14 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI14_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_TCTRL0_LPSPI14_B_LPREQ_SHIFT)) & SLEEPCON0_SHA_MED_TCTRL0_LPSPI14_B_LPREQ_MASK)

#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI14_F_LPREQ_MASK (0x10U)
#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI14_F_LPREQ_SHIFT (4U)
/*! LPSPI14_F_LPREQ - LPSPI14 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI14_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_TCTRL0_LPSPI14_F_LPREQ_SHIFT)) & SLEEPCON0_SHA_MED_TCTRL0_LPSPI14_F_LPREQ_MASK)

#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI16_B_LPREQ_MASK (0x40U)
#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI16_B_LPREQ_SHIFT (6U)
/*! LPSPI16_B_LPREQ - LPSPI16 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI16_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_TCTRL0_LPSPI16_B_LPREQ_SHIFT)) & SLEEPCON0_SHA_MED_TCTRL0_LPSPI16_B_LPREQ_MASK)

#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI16_F_LPREQ_MASK (0x80U)
#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI16_F_LPREQ_SHIFT (7U)
/*! LPSPI16_F_LPREQ - LPSPI16 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_TCTRL0_LPSPI16_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_TCTRL0_LPSPI16_F_LPREQ_SHIFT)) & SLEEPCON0_SHA_MED_TCTRL0_LPSPI16_F_LPREQ_MASK)

#define SLEEPCON0_SHA_MED_TCTRL0_FLEXIO_B_LPREQ_MASK (0x200U)
#define SLEEPCON0_SHA_MED_TCTRL0_FLEXIO_B_LPREQ_SHIFT (9U)
/*! FLEXIO_B_LPREQ - FLEXIO Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_TCTRL0_FLEXIO_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_TCTRL0_FLEXIO_B_LPREQ_SHIFT)) & SLEEPCON0_SHA_MED_TCTRL0_FLEXIO_B_LPREQ_MASK)

#define SLEEPCON0_SHA_MED_TCTRL0_FLEXIO_F_LPREQ_MASK (0x400U)
#define SLEEPCON0_SHA_MED_TCTRL0_FLEXIO_F_LPREQ_SHIFT (10U)
/*! FLEXIO_F_LPREQ - FLEXIO Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_TCTRL0_FLEXIO_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_TCTRL0_FLEXIO_F_LPREQ_SHIFT)) & SLEEPCON0_SHA_MED_TCTRL0_FLEXIO_F_LPREQ_MASK)

#define SLEEPCON0_SHA_MED_TCTRL0_NIC0_LPREQ_MASK (0x800U)
#define SLEEPCON0_SHA_MED_TCTRL0_NIC0_LPREQ_SHIFT (11U)
/*! NIC0_LPREQ - NIC_MEDIA0 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_TCTRL0_NIC0_LPREQ(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_TCTRL0_NIC0_LPREQ_SHIFT)) & SLEEPCON0_SHA_MED_TCTRL0_NIC0_LPREQ_MASK)

#define SLEEPCON0_SHA_MED_TCTRL0_NIC1_LPREQ_MASK (0x1000U)
#define SLEEPCON0_SHA_MED_TCTRL0_NIC1_LPREQ_SHIFT (12U)
/*! NIC1_LPREQ - NIC_MEDIA1 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_MED_TCTRL0_NIC1_LPREQ(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_TCTRL0_NIC1_LPREQ_SHIFT)) & SLEEPCON0_SHA_MED_TCTRL0_NIC1_LPREQ_MASK)
/*! @} */

/*! @name SHA_SEN_TCTRL0 - Shared VDD1_SENSE Domain Targets Low-power Control */
/*! @{ */

#define SLEEPCON0_SHA_SEN_TCTRL0_ADC0_STOP_MASK  (0x1U)
#define SLEEPCON0_SHA_SEN_TCTRL0_ADC0_STOP_SHIFT (0U)
/*! ADC0_STOP - ADC0 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_SEN_TCTRL0_ADC0_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_SEN_TCTRL0_ADC0_STOP_SHIFT)) & SLEEPCON0_SHA_SEN_TCTRL0_ADC0_STOP_MASK)

#define SLEEPCON0_SHA_SEN_TCTRL0_ACMP0_STOP_MASK (0x4U)
#define SLEEPCON0_SHA_SEN_TCTRL0_ACMP0_STOP_SHIFT (2U)
/*! ACMP0_STOP - ACMP0 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_SEN_TCTRL0_ACMP0_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_SEN_TCTRL0_ACMP0_STOP_SHIFT)) & SLEEPCON0_SHA_SEN_TCTRL0_ACMP0_STOP_MASK)

#define SLEEPCON0_SHA_SEN_TCTRL0_MICFIL_STOP_MASK (0x8U)
#define SLEEPCON0_SHA_SEN_TCTRL0_MICFIL_STOP_SHIFT (3U)
/*! MICFIL_STOP - MICFIL Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_SEN_TCTRL0_MICFIL_STOP(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_SEN_TCTRL0_MICFIL_STOP_SHIFT)) & SLEEPCON0_SHA_SEN_TCTRL0_MICFIL_STOP_MASK)

#define SLEEPCON0_SHA_SEN_TCTRL0_LPI2C15_B_LPREQ_MASK (0x20U)
#define SLEEPCON0_SHA_SEN_TCTRL0_LPI2C15_B_LPREQ_SHIFT (5U)
/*! LPI2C15_B_LPREQ - LPI2C15 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_SEN_TCTRL0_LPI2C15_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_SEN_TCTRL0_LPI2C15_B_LPREQ_SHIFT)) & SLEEPCON0_SHA_SEN_TCTRL0_LPI2C15_B_LPREQ_MASK)

#define SLEEPCON0_SHA_SEN_TCTRL0_LPI2C15_F_LPREQ_MASK (0x80U)
#define SLEEPCON0_SHA_SEN_TCTRL0_LPI2C15_F_LPREQ_SHIFT (7U)
/*! LPI2C15_F_LPREQ - LPI2C15 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_SEN_TCTRL0_LPI2C15_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_SEN_TCTRL0_LPI2C15_F_LPREQ_SHIFT)) & SLEEPCON0_SHA_SEN_TCTRL0_LPI2C15_F_LPREQ_MASK)

#define SLEEPCON0_SHA_SEN_TCTRL0_GDET3_LPREQ_MASK (0x200U)
#define SLEEPCON0_SHA_SEN_TCTRL0_GDET3_LPREQ_SHIFT (9U)
/*! GDET3_LPREQ - GDET3 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_SEN_TCTRL0_GDET3_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_SEN_TCTRL0_GDET3_LPREQ_SHIFT)) & SLEEPCON0_SHA_SEN_TCTRL0_GDET3_LPREQ_MASK)

#define SLEEPCON0_SHA_SEN_TCTRL0_RTC_STOP_MASK   (0x80000000U)
#define SLEEPCON0_SHA_SEN_TCTRL0_RTC_STOP_SHIFT  (31U)
/*! RTC_STOP - RTC0 and RTC1 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_SHA_SEN_TCTRL0_RTC_STOP(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_SEN_TCTRL0_RTC_STOP_SHIFT)) & SLEEPCON0_SHA_SEN_TCTRL0_RTC_STOP_MASK)
/*! @} */

/*! @name PRIVATE_CCTRL0 - Private Resources Controllers Low-power Control 0 */
/*! @{ */

#define SLEEPCON0_PRIVATE_CCTRL0_EDMA0_STOP_MASK (0x1U)
#define SLEEPCON0_PRIVATE_CCTRL0_EDMA0_STOP_SHIFT (0U)
/*! EDMA0_STOP - eDMA0 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_CCTRL0_EDMA0_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_CCTRL0_EDMA0_STOP_SHIFT)) & SLEEPCON0_PRIVATE_CCTRL0_EDMA0_STOP_MASK)

#define SLEEPCON0_PRIVATE_CCTRL0_EDMA1_STOP_MASK (0x2U)
#define SLEEPCON0_PRIVATE_CCTRL0_EDMA1_STOP_SHIFT (1U)
/*! EDMA1_STOP - eDMA1 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_CCTRL0_EDMA1_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_CCTRL0_EDMA1_STOP_SHIFT)) & SLEEPCON0_PRIVATE_CCTRL0_EDMA1_STOP_MASK)
/*! @} */

/*! @name PRIVATE_TCTRL0 - Private Resources Targets Low-power Control 0 */
/*! @{ */

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM0_B_LPREQ_MASK (0x1U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM0_B_LPREQ_SHIFT (0U)
/*! LP_FLEXCOMM0_B_LPREQ - LP_FLEXCOMM0 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM0_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM0_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM0_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM1_B_LPREQ_MASK (0x2U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM1_B_LPREQ_SHIFT (1U)
/*! LP_FLEXCOMM1_B_LPREQ - LP_FLEXCOMM1 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM1_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM1_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM1_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM2_B_LPREQ_MASK (0x4U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM2_B_LPREQ_SHIFT (2U)
/*! LP_FLEXCOMM2_B_LPREQ - LP_FLEXCOMM2 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM2_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM2_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM2_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM3_B_LPREQ_MASK (0x8U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM3_B_LPREQ_SHIFT (3U)
/*! LP_FLEXCOMM3_B_LPREQ - LP_FLEXCOMM3 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM3_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM3_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM3_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM4_B_LPREQ_MASK (0x10U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM4_B_LPREQ_SHIFT (4U)
/*! LP_FLEXCOMM4_B_LPREQ - LP_FLEXCOMM4 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM4_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM4_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM4_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM5_B_LPREQ_MASK (0x20U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM5_B_LPREQ_SHIFT (5U)
/*! LP_FLEXCOMM5_B_LPREQ - LP_FLEXCOMM5 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM5_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM5_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM5_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM6_B_LPREQ_MASK (0x40U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM6_B_LPREQ_SHIFT (6U)
/*! LP_FLEXCOMM6_B_LPREQ - LP_FLEXCOMM6 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM6_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM6_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM6_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM7_B_LPREQ_MASK (0x80U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM7_B_LPREQ_SHIFT (7U)
/*! LP_FLEXCOMM7_B_LPREQ - LP_FLEXCOMM7 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM7_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM7_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM7_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM8_B_LPREQ_MASK (0x100U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM8_B_LPREQ_SHIFT (8U)
/*! LP_FLEXCOMM8_B_LPREQ - LP_FLEXCOMM8 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM8_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM8_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM8_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM9_B_LPREQ_MASK (0x200U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM9_B_LPREQ_SHIFT (9U)
/*! LP_FLEXCOMM9_B_LPREQ - LP_FLEXCOMM9 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM9_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM9_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM9_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM10_B_LPREQ_MASK (0x400U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM10_B_LPREQ_SHIFT (10U)
/*! LP_FLEXCOMM10_B_LPREQ - LP_FLEXCOMM10 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM10_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM10_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM10_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM11_B_LPREQ_MASK (0x800U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM11_B_LPREQ_SHIFT (11U)
/*! LP_FLEXCOMM11_B_LPREQ - LP_FLEXCOMM11 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM11_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM11_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM11_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM12_B_LPREQ_MASK (0x1000U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM12_B_LPREQ_SHIFT (12U)
/*! LP_FLEXCOMM12_B_LPREQ - LP_FLEXCOMM12 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM12_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM12_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM12_B_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM13_B_LPREQ_MASK (0x2000U)
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM13_B_LPREQ_SHIFT (13U)
/*! LP_FLEXCOMM13_B_LPREQ - LP_FLEXCOMM13 Bus Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM13_B_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM13_B_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL0_LP_FLEXCOMM13_B_LPREQ_MASK)
/*! @} */

/*! @name PRIVATE_TCTRL1 - Private Resources Targets Low-power Control 1 */
/*! @{ */

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM0_F_LPREQ_MASK (0x1U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM0_F_LPREQ_SHIFT (0U)
/*! LP_FLEXCOMM0_F_LPREQ - LP_FLEXCOMM0 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM0_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM0_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM0_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM1_F_LPREQ_MASK (0x2U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM1_F_LPREQ_SHIFT (1U)
/*! LP_FLEXCOMM1_F_LPREQ - LP_FLEXCOMM1 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM1_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM1_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM1_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM2_F_LPREQ_MASK (0x4U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM2_F_LPREQ_SHIFT (2U)
/*! LP_FLEXCOMM2_F_LPREQ - LP_FLEXCOMM2 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM2_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM2_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM2_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM3_F_LPREQ_MASK (0x8U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM3_F_LPREQ_SHIFT (3U)
/*! LP_FLEXCOMM3_F_LPREQ - LP_FLEXCOMM3 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM3_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM3_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM3_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM4_F_LPREQ_MASK (0x10U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM4_F_LPREQ_SHIFT (4U)
/*! LP_FLEXCOMM4_F_LPREQ - LP_FLEXCOMM4 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM4_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM4_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM4_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM5_F_LPREQ_MASK (0x20U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM5_F_LPREQ_SHIFT (5U)
/*! LP_FLEXCOMM5_F_LPREQ - LP_FLEXCOMM5 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM5_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM5_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM5_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM6_F_LPREQ_MASK (0x40U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM6_F_LPREQ_SHIFT (6U)
/*! LP_FLEXCOMM6_F_LPREQ - LP_FLEXCOMM6 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM6_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM6_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM6_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM7_F_LPREQ_MASK (0x80U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM7_F_LPREQ_SHIFT (7U)
/*! LP_FLEXCOMM7_F_LPREQ - LP_FLEXCOMM7 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM7_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM7_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM7_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM8_F_LPREQ_MASK (0x100U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM8_F_LPREQ_SHIFT (8U)
/*! LP_FLEXCOMM8_F_LPREQ - LP_FLEXCOMM8 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM8_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM8_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM8_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM9_F_LPREQ_MASK (0x200U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM9_F_LPREQ_SHIFT (9U)
/*! LP_FLEXCOMM9_F_LPREQ - LP_FLEXCOMM9 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM9_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM9_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM9_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM10_F_LPREQ_MASK (0x400U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM10_F_LPREQ_SHIFT (10U)
/*! LP_FLEXCOMM10_F_LPREQ - LP_FLEXCOMM10 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM10_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM10_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM10_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM11_F_LPREQ_MASK (0x800U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM11_F_LPREQ_SHIFT (11U)
/*! LP_FLEXCOMM11_F_LPREQ - LP_FLEXCOMM11 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM11_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM11_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM11_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM12_F_LPREQ_MASK (0x1000U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM12_F_LPREQ_SHIFT (12U)
/*! LP_FLEXCOMM12_F_LPREQ - LP_FLEXCOMM12 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM12_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM12_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM12_F_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM13_F_LPREQ_MASK (0x2000U)
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM13_F_LPREQ_SHIFT (13U)
/*! LP_FLEXCOMM13_F_LPREQ - LP_FLEXCOMM13 Function Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM13_F_LPREQ(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM13_F_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL1_LP_FLEXCOMM13_F_LPREQ_MASK)
/*! @} */

/*! @name PRIVATE_TCTRL2 - Private Resources Targets Low-power Control 2 */
/*! @{ */

#define SLEEPCON0_PRIVATE_TCTRL2_GPIO0_LPREQ_MASK (0x1U)
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO0_LPREQ_SHIFT (0U)
/*! GPIO0_LPREQ - GPIO0 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO0_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_GPIO0_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_GPIO0_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_GPIO1_LPREQ_MASK (0x2U)
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO1_LPREQ_SHIFT (1U)
/*! GPIO1_LPREQ - GPIO1 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO1_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_GPIO1_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_GPIO1_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_GPIO2_LPREQ_MASK (0x4U)
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO2_LPREQ_SHIFT (2U)
/*! GPIO2_LPREQ - GPIO2 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO2_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_GPIO2_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_GPIO2_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_GPIO3_LPREQ_MASK (0x8U)
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO3_LPREQ_SHIFT (3U)
/*! GPIO3_LPREQ - GPIO3 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO3_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_GPIO3_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_GPIO3_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_GPIO4_LPREQ_MASK (0x10U)
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO4_LPREQ_SHIFT (4U)
/*! GPIO4_LPREQ - GPIO4 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO4_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_GPIO4_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_GPIO4_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_GPIO5_LPREQ_MASK (0x20U)
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO5_LPREQ_SHIFT (5U)
/*! GPIO5_LPREQ - GPIO5 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO5_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_GPIO5_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_GPIO5_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_GPIO6_LPREQ_MASK (0x40U)
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO6_LPREQ_SHIFT (6U)
/*! GPIO6_LPREQ - GPIO6 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO6_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_GPIO6_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_GPIO6_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_GPIO7_LPREQ_MASK (0x80U)
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO7_LPREQ_SHIFT (7U)
/*! GPIO7_LPREQ - GPIO7 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_GPIO7_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_GPIO7_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_GPIO7_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_SAI0_LPREQ_MASK (0x100U)
#define SLEEPCON0_PRIVATE_TCTRL2_SAI0_LPREQ_SHIFT (8U)
/*! SAI0_LPREQ - SAI0 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_SAI0_LPREQ(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_SAI0_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_SAI0_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_SAI1_LPREQ_MASK (0x200U)
#define SLEEPCON0_PRIVATE_TCTRL2_SAI1_LPREQ_SHIFT (9U)
/*! SAI1_LPREQ - SAI1 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_SAI1_LPREQ(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_SAI1_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_SAI1_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_SAI2_LPREQ_MASK (0x400U)
#define SLEEPCON0_PRIVATE_TCTRL2_SAI2_LPREQ_SHIFT (10U)
/*! SAI2_LPREQ - SAI2 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_SAI2_LPREQ(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_SAI2_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_SAI2_LPREQ_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_TRNG_STOP_MASK  (0x800U)
#define SLEEPCON0_PRIVATE_TCTRL2_TRNG_STOP_SHIFT (11U)
/*! TRNG_STOP - TRNG Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_TRNG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_TRNG_STOP_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_TRNG_STOP_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_XSPI0_STOP_MASK (0x1000U)
#define SLEEPCON0_PRIVATE_TCTRL2_XSPI0_STOP_SHIFT (12U)
/*! XSPI0_STOP - XSPI0 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_XSPI0_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_XSPI0_STOP_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_XSPI0_STOP_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_XSPI1_STOP_MASK (0x4000U)
#define SLEEPCON0_PRIVATE_TCTRL2_XSPI1_STOP_SHIFT (14U)
/*! XSPI1_STOP - XSPI1 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_XSPI1_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_XSPI1_STOP_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_XSPI1_STOP_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_I3C0_STOP_MASK  (0x10000U)
#define SLEEPCON0_PRIVATE_TCTRL2_I3C0_STOP_SHIFT (16U)
/*! I3C0_STOP - I3C0 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_I3C0_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_I3C0_STOP_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_I3C0_STOP_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_I3C1_STOP_MASK  (0x20000U)
#define SLEEPCON0_PRIVATE_TCTRL2_I3C1_STOP_SHIFT (17U)
/*! I3C1_STOP - I3C1 Stop
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_I3C1_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_I3C1_STOP_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_I3C1_STOP_MASK)

#define SLEEPCON0_PRIVATE_TCTRL2_GDET0_LPREQ_MASK (0x40000U)
#define SLEEPCON0_PRIVATE_TCTRL2_GDET0_LPREQ_SHIFT (18U)
/*! GDET0_LPREQ - GDET0 Low-Power Request
 *  0b0..No request
 *  0b1..Sends request
 */
#define SLEEPCON0_PRIVATE_TCTRL2_GDET0_LPREQ(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TCTRL2_GDET0_LPREQ_SHIFT)) & SLEEPCON0_PRIVATE_TCTRL2_GDET0_LPREQ_MASK)
/*! @} */

/*! @name SHA_MED_CSTAT0 - Media Domain Shared Controllers Low-power Status */
/*! @{ */

#define SLEEPCON0_SHA_MED_CSTAT0_VGPU_LPACCEPT_MASK (0x1U)
#define SLEEPCON0_SHA_MED_CSTAT0_VGPU_LPACCEPT_SHIFT (0U)
/*! VGPU_LPACCEPT - VGPU Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MED_CSTAT0_VGPU_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_CSTAT0_VGPU_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MED_CSTAT0_VGPU_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MED_CSTAT0_VGPU_IDLE_MASK  (0x2U)
#define SLEEPCON0_SHA_MED_CSTAT0_VGPU_IDLE_SHIFT (1U)
/*! VGPU_IDLE - VGPU Idle Status
 *  0b0..Not in Idle status, VGPU has operation to perform.
 *  0b1..In Idle status, VGPU might accept low-power request.
 */
#define SLEEPCON0_SHA_MED_CSTAT0_VGPU_IDLE(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_CSTAT0_VGPU_IDLE_SHIFT)) & SLEEPCON0_SHA_MED_CSTAT0_VGPU_IDLE_MASK)

#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_STOPPED_MASK (0x4U)
#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_STOPPED_SHIFT (2U)
/*! EZHV_STOPPED - EZH-V Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_STOPPED(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_CSTAT0_EZHV_STOPPED_SHIFT)) & SLEEPCON0_SHA_MED_CSTAT0_EZHV_STOPPED_MASK)

#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_HALTED_MASK (0x8U)
#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_HALTED_SHIFT (3U)
/*! EZHV_HALTED - EZH-V Halt Status
 *  0b0..Not in Halt status
 *  0b1..In Halt status
 */
#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_HALTED(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_CSTAT0_EZHV_HALTED_SHIFT)) & SLEEPCON0_SHA_MED_CSTAT0_EZHV_HALTED_MASK)

#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAITING_MASK (0x10U)
#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAITING_SHIFT (4U)
/*! EZHV_WAITING - EZH-V Waiting Status
 *  0b0..Not in waiting status
 *  0b1..In waiting status
 */
#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAITING(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAITING_SHIFT)) & SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAITING_MASK)

#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAKEUP_MASK (0x20U)
#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAKEUP_SHIFT (5U)
/*! EZHV_WAKEUP - Wakeup Request from EZH-V
 *  0b0..Not needs
 *  0b1..Needs
 */
#define SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAKEUP(x)  (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAKEUP_SHIFT)) & SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAKEUP_MASK)
/*! @} */

/*! @name SHA_MEDSEN_TSTAT0 - Media and Sense Domain Shared Targets Low-power Status */
/*! @{ */

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_XSPI2_STOP_MASK (0x1U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_XSPI2_STOP_SHIFT (0U)
/*! XSPI2_STOP - XSPI2 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_XSPI2_STOP(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_XSPI2_STOP_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_XSPI2_STOP_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI14_B_LPACCEPT_MASK (0x2U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI14_B_LPACCEPT_SHIFT (1U)
/*! LPSPI14_B_LPACCEPT - LPSPI14 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI14_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI14_B_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI14_B_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI14_F_LPACCEPT_MASK (0x4U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI14_F_LPACCEPT_SHIFT (2U)
/*! LPSPI14_F_LPACCEPT - LPSPI14 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI14_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI14_F_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI14_F_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI16_B_LPACCEPT_MASK (0x8U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI16_B_LPACCEPT_SHIFT (3U)
/*! LPSPI16_B_LPACCEPT - LPSPI16 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI16_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI16_B_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI16_B_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI16_F_LPACCEPT_MASK (0x10U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI16_F_LPACCEPT_SHIFT (4U)
/*! LPSPI16_F_LPACCEPT - LPSPI16 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI16_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI16_F_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_LPSPI16_F_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_FLEXIO_B_LPACCEPT_MASK (0x20U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_FLEXIO_B_LPACCEPT_SHIFT (5U)
/*! FLEXIO_B_LPACCEPT - FLEXIO Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_FLEXIO_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_FLEXIO_B_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_FLEXIO_B_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_FLEXIO_F_LPACCEPT_MASK (0x40U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_FLEXIO_F_LPACCEPT_SHIFT (6U)
/*! FLEXIO_F_LPACCEPT - FLEXIO Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_FLEXIO_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_FLEXIO_F_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_FLEXIO_F_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_NIC0_LPACCEPT_MASK (0x80U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_NIC0_LPACCEPT_SHIFT (7U)
/*! NIC0_LPACCEPT - NIC_MEDIA0 Accept Low-power Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_NIC0_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_NIC0_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_NIC0_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_NIC1_LPACCEPT_MASK (0x100U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_NIC1_LPACCEPT_SHIFT (8U)
/*! NIC1_LPACCEPT - NIC_MEDIA1 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_NIC1_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_NIC1_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_NIC1_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_ADC0_STOP_MASK (0x10000U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_ADC0_STOP_SHIFT (16U)
/*! ADC0_STOP - ADC0 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_ADC0_STOP(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_ADC0_STOP_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_ADC0_STOP_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_ACMP0_STOP_MASK (0x20000U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_ACMP0_STOP_SHIFT (17U)
/*! ACMP0_STOP - ACMP0 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_ACMP0_STOP(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_ACMP0_STOP_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_ACMP0_STOP_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_MICFIL_STOPPED_MASK (0x40000U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_MICFIL_STOPPED_SHIFT (18U)
/*! MICFIL_STOPPED - MICFIL Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_MICFIL_STOPPED(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_MICFIL_STOPPED_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_MICFIL_STOPPED_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPI2C15_B_LPACCEPT_MASK (0x80000U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPI2C15_B_LPACCEPT_SHIFT (19U)
/*! LPI2C15_B_LPACCEPT - LPI2C15 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPI2C15_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_LPI2C15_B_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_LPI2C15_B_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPI2C15_F_LPACCEPT_MASK (0x100000U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPI2C15_F_LPACCEPT_SHIFT (20U)
/*! LPI2C15_F_LPACCEPT - LPI2C15 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_LPI2C15_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_LPI2C15_F_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_LPI2C15_F_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_GDET3_LPACCEPT_MASK (0x400000U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_GDET3_LPACCEPT_SHIFT (22U)
/*! GDET3_LPACCEPT - GDET3 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_GDET3_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_GDET3_LPACCEPT_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_GDET3_LPACCEPT_MASK)

#define SLEEPCON0_SHA_MEDSEN_TSTAT0_RTC_STOPPED_MASK (0x80000000U)
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_RTC_STOPPED_SHIFT (31U)
/*! RTC_STOPPED - RTC0 and RTC1 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_SHA_MEDSEN_TSTAT0_RTC_STOPPED(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_SHA_MEDSEN_TSTAT0_RTC_STOPPED_SHIFT)) & SLEEPCON0_SHA_MEDSEN_TSTAT0_RTC_STOPPED_MASK)
/*! @} */

/*! @name PRIVATE_CSTAT0 - Private Resources Controller Low-power Status */
/*! @{ */

#define SLEEPCON0_PRIVATE_CSTAT0_EDMA0_STOP_MASK (0x1U)
#define SLEEPCON0_PRIVATE_CSTAT0_EDMA0_STOP_SHIFT (0U)
/*! EDMA0_STOP - eDMA0 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_PRIVATE_CSTAT0_EDMA0_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_CSTAT0_EDMA0_STOP_SHIFT)) & SLEEPCON0_PRIVATE_CSTAT0_EDMA0_STOP_MASK)

#define SLEEPCON0_PRIVATE_CSTAT0_EDMA1_STOP_MASK (0x2U)
#define SLEEPCON0_PRIVATE_CSTAT0_EDMA1_STOP_SHIFT (1U)
/*! EDMA1_STOP - eDMA1 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_PRIVATE_CSTAT0_EDMA1_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_CSTAT0_EDMA1_STOP_SHIFT)) & SLEEPCON0_PRIVATE_CSTAT0_EDMA1_STOP_MASK)
/*! @} */

/*! @name PRIVATE_TSTAT0 - Private Resources Targets Low-power Status 0 */
/*! @{ */

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM0_B_LPACCEPT_MASK (0x1U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM0_B_LPACCEPT_SHIFT (0U)
/*! LP_FLEXCOMM0_B_LPACCEPT - LP_FLEXCOMM0 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM0_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM0_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM0_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM1_B_LPACCEPT_MASK (0x2U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM1_B_LPACCEPT_SHIFT (1U)
/*! LP_FLEXCOMM1_B_LPACCEPT - LP_FLEXCOMM1 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM1_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM1_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM1_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM2_B_LPACCEPT_MASK (0x4U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM2_B_LPACCEPT_SHIFT (2U)
/*! LP_FLEXCOMM2_B_LPACCEPT - LP_FLEXCOMM2 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM2_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM2_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM2_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM3_B_LPACCEPT_MASK (0x8U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM3_B_LPACCEPT_SHIFT (3U)
/*! LP_FLEXCOMM3_B_LPACCEPT - LP_FLEXCOMM3 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM3_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM3_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM3_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM4_B_LPACCEPT_MASK (0x10U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM4_B_LPACCEPT_SHIFT (4U)
/*! LP_FLEXCOMM4_B_LPACCEPT - LP_FLEXCOMM4 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM4_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM4_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM4_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM5_B_LPACCEPT_MASK (0x20U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM5_B_LPACCEPT_SHIFT (5U)
/*! LP_FLEXCOMM5_B_LPACCEPT - LP_FLEXCOMM5 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM5_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM5_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM5_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM6_B_LPACCEPT_MASK (0x40U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM6_B_LPACCEPT_SHIFT (6U)
/*! LP_FLEXCOMM6_B_LPACCEPT - LP_FLEXCOMM6 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM6_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM6_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM6_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM7_B_LPACCEPT_MASK (0x80U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM7_B_LPACCEPT_SHIFT (7U)
/*! LP_FLEXCOMM7_B_LPACCEPT - LP_FLEXCOMM7 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM7_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM7_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM7_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM8_B_LPACCEPT_MASK (0x100U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM8_B_LPACCEPT_SHIFT (8U)
/*! LP_FLEXCOMM8_B_LPACCEPT - LP_FLEXCOMM8 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM8_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM8_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM8_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM9_B_LPACCEPT_MASK (0x200U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM9_B_LPACCEPT_SHIFT (9U)
/*! LP_FLEXCOMM9_B_LPACCEPT - LP_FLEXCOMM9 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM9_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM9_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM9_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM10_B_LPACCEPT_MASK (0x400U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM10_B_LPACCEPT_SHIFT (10U)
/*! LP_FLEXCOMM10_B_LPACCEPT - LP_FLEXCOMM10 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM10_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM10_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM10_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM11_B_LPACCEPT_MASK (0x800U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM11_B_LPACCEPT_SHIFT (11U)
/*! LP_FLEXCOMM11_B_LPACCEPT - LP_FLEXCOMM11 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM11_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM11_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM11_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM12_B_LPACCEPT_MASK (0x1000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM12_B_LPACCEPT_SHIFT (12U)
/*! LP_FLEXCOMM12_B_LPACCEPT - LP_FLEXCOMM12 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM12_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM12_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM12_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM13_B_LPACCEPT_MASK (0x2000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM13_B_LPACCEPT_SHIFT (13U)
/*! LP_FLEXCOMM13_B_LPACCEPT - LP_FLEXCOMM13 Bus Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM13_B_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM13_B_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM13_B_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM0_F_LPACCEPT_MASK (0x10000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM0_F_LPACCEPT_SHIFT (16U)
/*! LP_FLEXCOMM0_F_LPACCEPT - LP_FLEXCOMM0 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM0_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM0_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM0_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM1_F_LPACCEPT_MASK (0x20000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM1_F_LPACCEPT_SHIFT (17U)
/*! LP_FLEXCOMM1_F_LPACCEPT - LP_FLEXCOMM1 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM1_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM1_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM1_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM2_F_LPACCEPT_MASK (0x40000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM2_F_LPACCEPT_SHIFT (18U)
/*! LP_FLEXCOMM2_F_LPACCEPT - LP_FLEXCOMM2 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM2_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM2_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM2_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM3_F_LPACCEPT_MASK (0x80000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM3_F_LPACCEPT_SHIFT (19U)
/*! LP_FLEXCOMM3_F_LPACCEPT - LP_FLEXCOMM3 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM3_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM3_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM3_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM4_F_LPACCEPT_MASK (0x100000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM4_F_LPACCEPT_SHIFT (20U)
/*! LP_FLEXCOMM4_F_LPACCEPT - LP_FLEXCOMM4 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM4_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM4_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM4_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM5_F_LPACCEPT_MASK (0x200000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM5_F_LPACCEPT_SHIFT (21U)
/*! LP_FLEXCOMM5_F_LPACCEPT - LP_FLEXCOMM5 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM5_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM5_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM5_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM6_F_LPACCEPT_MASK (0x400000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM6_F_LPACCEPT_SHIFT (22U)
/*! LP_FLEXCOMM6_F_LPACCEPT - LP_FLEXCOMM6 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM6_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM6_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM6_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM7_F_LPACCEPT_MASK (0x800000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM7_F_LPACCEPT_SHIFT (23U)
/*! LP_FLEXCOMM7_F_LPACCEPT - LP_FLEXCOMM7 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM7_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM7_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM7_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM8_F_LPACCEPT_MASK (0x1000000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM8_F_LPACCEPT_SHIFT (24U)
/*! LP_FLEXCOMM8_F_LPACCEPT - LP_FLEXCOMM8 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM8_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM8_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM8_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM9_F_LPACCEPT_MASK (0x2000000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM9_F_LPACCEPT_SHIFT (25U)
/*! LP_FLEXCOMM9_F_LPACCEPT - LP_FLEXCOMM9 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM9_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM9_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM9_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM10_F_LPACCEPT_MASK (0x4000000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM10_F_LPACCEPT_SHIFT (26U)
/*! LP_FLEXCOMM10_F_LPACCEPT - LP_FLEXCOMM10 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM10_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM10_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM10_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM11_F_LPACCEPT_MASK (0x8000000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM11_F_LPACCEPT_SHIFT (27U)
/*! LP_FLEXCOMM11_F_LPACCEPT - LP_FLEXCOMM11 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM11_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM11_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM11_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM12_F_LPACCEPT_MASK (0x10000000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM12_F_LPACCEPT_SHIFT (28U)
/*! LP_FLEXCOMM12_F_LPACCEPT - LP_FLEXCOMM12 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM12_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM12_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM12_F_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM13_F_LPACCEPT_MASK (0x20000000U)
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM13_F_LPACCEPT_SHIFT (29U)
/*! LP_FLEXCOMM13_F_LPACCEPT - LP_FLEXCOMM13 Function Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM13_F_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM13_F_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT0_LP_FLEXCOMM13_F_LPACCEPT_MASK)
/*! @} */

/*! @name PRIVATE_TSTAT1 - Private Resources Targets Low-power Status 1 */
/*! @{ */

#define SLEEPCON0_PRIVATE_TSTAT1_GDET0_LPACCEPT_MASK (0x1U)
#define SLEEPCON0_PRIVATE_TSTAT1_GDET0_LPACCEPT_SHIFT (0U)
/*! GDET0_LPACCEPT - GDET0 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_GDET0_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_GDET0_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_GDET0_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_GPIO0_LPACCEPT_MASK (0x4U)
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO0_LPACCEPT_SHIFT (2U)
/*! GPIO0_LPACCEPT - GPIO0 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO0_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_GPIO0_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_GPIO0_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_GPIO1_LPACCEPT_MASK (0x8U)
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO1_LPACCEPT_SHIFT (3U)
/*! GPIO1_LPACCEPT - GPIO1 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO1_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_GPIO1_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_GPIO1_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_GPIO2_LPACCEPT_MASK (0x10U)
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO2_LPACCEPT_SHIFT (4U)
/*! GPIO2_LPACCEPT - GPIO2 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO2_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_GPIO2_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_GPIO2_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_GPIO3_LPACCEPT_MASK (0x20U)
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO3_LPACCEPT_SHIFT (5U)
/*! GPIO3_LPACCEPT - GPIO3 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO3_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_GPIO3_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_GPIO3_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_GPIO4_LPACCEPT_MASK (0x40U)
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO4_LPACCEPT_SHIFT (6U)
/*! GPIO4_LPACCEPT - GPIO4 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO4_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_GPIO4_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_GPIO4_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_GPIO5_LPACCEPT_MASK (0x80U)
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO5_LPACCEPT_SHIFT (7U)
/*! GPIO5_LPACCEPT - GPIO5 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO5_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_GPIO5_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_GPIO5_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_GPIO6_LPACCEPT_MASK (0x100U)
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO6_LPACCEPT_SHIFT (8U)
/*! GPIO6_LPACCEPT - GPIO6 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO6_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_GPIO6_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_GPIO6_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_GPIO7_LPACCEPT_MASK (0x200U)
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO7_LPACCEPT_SHIFT (9U)
/*! GPIO7_LPACCEPT - GPIO7 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_GPIO7_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_GPIO7_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_GPIO7_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_SAI0_LPACCEPT_MASK (0x400U)
#define SLEEPCON0_PRIVATE_TSTAT1_SAI0_LPACCEPT_SHIFT (10U)
/*! SAI0_LPACCEPT - SAI0 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_SAI0_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_SAI0_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_SAI0_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_SAI1_LPACCEPT_MASK (0x800U)
#define SLEEPCON0_PRIVATE_TSTAT1_SAI1_LPACCEPT_SHIFT (11U)
/*! SAI1_LPACCEPT - SAI1 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_SAI1_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_SAI1_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_SAI1_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_SAI2_LPACCEPT_MASK (0x1000U)
#define SLEEPCON0_PRIVATE_TSTAT1_SAI2_LPACCEPT_SHIFT (12U)
/*! SAI2_LPACCEPT - SAI2 Low-power Accept Status
 *  0b0..Not accept
 *  0b1..Accept
 */
#define SLEEPCON0_PRIVATE_TSTAT1_SAI2_LPACCEPT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_SAI2_LPACCEPT_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_SAI2_LPACCEPT_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_TRNG_STOP_MASK  (0x2000U)
#define SLEEPCON0_PRIVATE_TSTAT1_TRNG_STOP_SHIFT (13U)
/*! TRNG_STOP - TRNG Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_PRIVATE_TSTAT1_TRNG_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_TRNG_STOP_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_TRNG_STOP_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_XSPI0_STOP_MASK (0x4000U)
#define SLEEPCON0_PRIVATE_TSTAT1_XSPI0_STOP_SHIFT (14U)
/*! XSPI0_STOP - XSPI0 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_PRIVATE_TSTAT1_XSPI0_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_XSPI0_STOP_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_XSPI0_STOP_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_XSPI1_STOP_MASK (0x8000U)
#define SLEEPCON0_PRIVATE_TSTAT1_XSPI1_STOP_SHIFT (15U)
/*! XSPI1_STOP - XSPI1 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_PRIVATE_TSTAT1_XSPI1_STOP(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_XSPI1_STOP_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_XSPI1_STOP_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_I3C0_STOP_MASK  (0x10000U)
#define SLEEPCON0_PRIVATE_TSTAT1_I3C0_STOP_SHIFT (16U)
/*! I3C0_STOP - I3C0 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_PRIVATE_TSTAT1_I3C0_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_I3C0_STOP_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_I3C0_STOP_MASK)

#define SLEEPCON0_PRIVATE_TSTAT1_I3C1_STOP_MASK  (0x20000U)
#define SLEEPCON0_PRIVATE_TSTAT1_I3C1_STOP_SHIFT (17U)
/*! I3C1_STOP - I3C1 Stop Status
 *  0b0..Not in Stop status
 *  0b1..In Stop status
 */
#define SLEEPCON0_PRIVATE_TSTAT1_I3C1_STOP(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_PRIVATE_TSTAT1_I3C1_STOP_SHIFT)) & SLEEPCON0_PRIVATE_TSTAT1_I3C1_STOP_MASK)
/*! @} */

/*! @name LP_HINT0 - Low-Power Hints 0 */
/*! @{ */

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM0_B_LPHINT_MASK (0x1U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM0_B_LPHINT_SHIFT (0U)
/*! LP_FLEXCOMM0_B_LPHINT - LP_FLEXCOMM0 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM0_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM0_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM0_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM1_B_LPHINT_MASK (0x2U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM1_B_LPHINT_SHIFT (1U)
/*! LP_FLEXCOMM1_B_LPHINT - LP_FLEXCOMM1 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM1_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM1_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM1_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM2_B_LPHINT_MASK (0x4U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM2_B_LPHINT_SHIFT (2U)
/*! LP_FLEXCOMM2_B_LPHINT - LP_FLEXCOMM2 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM2_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM2_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM2_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM3_B_LPHINT_MASK (0x8U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM3_B_LPHINT_SHIFT (3U)
/*! LP_FLEXCOMM3_B_LPHINT - LP_FLEXCOMM3 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM3_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM3_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM3_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM4_B_LPHINT_MASK (0x10U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM4_B_LPHINT_SHIFT (4U)
/*! LP_FLEXCOMM4_B_LPHINT - LP_FLEXCOMM4 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM4_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM4_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM4_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM5_B_LPHINT_MASK (0x20U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM5_B_LPHINT_SHIFT (5U)
/*! LP_FLEXCOMM5_B_LPHINT - LP_FLEXCOMM5 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM5_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM5_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM5_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM6_B_LPHINT_MASK (0x40U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM6_B_LPHINT_SHIFT (6U)
/*! LP_FLEXCOMM6_B_LPHINT - LP_FLEXCOMM6 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM6_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM6_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM6_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM7_B_LPHINT_MASK (0x80U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM7_B_LPHINT_SHIFT (7U)
/*! LP_FLEXCOMM7_B_LPHINT - LP_FLEXCOMM7 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM7_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM7_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM7_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM8_B_LPHINT_MASK (0x100U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM8_B_LPHINT_SHIFT (8U)
/*! LP_FLEXCOMM8_B_LPHINT - LP_FLEXCOMM8 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM8_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM8_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM8_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM9_B_LPHINT_MASK (0x200U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM9_B_LPHINT_SHIFT (9U)
/*! LP_FLEXCOMM9_B_LPHINT - LP_FLEXCOMM9 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM9_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM9_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM9_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM10_B_LPHINT_MASK (0x400U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM10_B_LPHINT_SHIFT (10U)
/*! LP_FLEXCOMM10_B_LPHINT - LP_FLEXCOMM10 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM10_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM10_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM10_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM11_B_LPHINT_MASK (0x800U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM11_B_LPHINT_SHIFT (11U)
/*! LP_FLEXCOMM11_B_LPHINT - LP_FLEXCOMM11 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM11_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM11_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM11_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM12_B_LPHINT_MASK (0x1000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM12_B_LPHINT_SHIFT (12U)
/*! LP_FLEXCOMM12_B_LPHINT - LP_FLEXCOMM12 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM12_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM12_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM12_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM13_B_LPHINT_MASK (0x2000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM13_B_LPHINT_SHIFT (13U)
/*! LP_FLEXCOMM13_B_LPHINT - LP_FLEXCOMM13 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM13_B_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM13_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM13_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LPSPI14_B_LPHINT_MASK (0x4000U)
#define SLEEPCON0_LP_HINT0_LPSPI14_B_LPHINT_SHIFT (14U)
/*! LPSPI14_B_LPHINT - LPSPI14 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LPSPI14_B_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LPSPI14_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LPSPI14_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LPSPI16_B_LPHINT_MASK (0x8000U)
#define SLEEPCON0_LP_HINT0_LPSPI16_B_LPHINT_SHIFT (15U)
/*! LPSPI16_B_LPHINT - LPSPI16 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LPSPI16_B_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LPSPI16_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LPSPI16_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM0_F_LPHINT_MASK (0x10000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM0_F_LPHINT_SHIFT (16U)
/*! LP_FLEXCOMM0_F_LPHINT - LP_FLEXCOMM0 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM0_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM0_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM0_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM1_F_LPHINT_MASK (0x20000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM1_F_LPHINT_SHIFT (17U)
/*! LP_FLEXCOMM1_F_LPHINT - LP_FLEXCOMM1 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM1_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM1_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM1_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM2_F_LPHINT_MASK (0x40000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM2_F_LPHINT_SHIFT (18U)
/*! LP_FLEXCOMM2_F_LPHINT - LP_FLEXCOMM2 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM2_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM2_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM2_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM3_F_LPHINT_MASK (0x80000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM3_F_LPHINT_SHIFT (19U)
/*! LP_FLEXCOMM3_F_LPHINT - LP_FLEXCOMM3 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM3_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM3_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM3_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM4_F_LPHINT_MASK (0x100000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM4_F_LPHINT_SHIFT (20U)
/*! LP_FLEXCOMM4_F_LPHINT - LP_FLEXCOMM4 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM4_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM4_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM4_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM5_F_LPHINT_MASK (0x200000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM5_F_LPHINT_SHIFT (21U)
/*! LP_FLEXCOMM5_F_LPHINT - LP_FLEXCOMM5 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM5_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM5_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM5_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM6_F_LPHINT_MASK (0x400000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM6_F_LPHINT_SHIFT (22U)
/*! LP_FLEXCOMM6_F_LPHINT - LP_FLEXCOMM6 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM6_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM6_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM6_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM7_F_LPHINT_MASK (0x800000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM7_F_LPHINT_SHIFT (23U)
/*! LP_FLEXCOMM7_F_LPHINT - LP_FLEXCOMM7 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM7_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM7_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM7_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM8_F_LPHINT_MASK (0x1000000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM8_F_LPHINT_SHIFT (24U)
/*! LP_FLEXCOMM8_F_LPHINT - LP_FLEXCOMM8 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM8_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM8_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM8_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM9_F_LPHINT_MASK (0x2000000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM9_F_LPHINT_SHIFT (25U)
/*! LP_FLEXCOMM9_F_LPHINT - LP_FLEXCOMM9 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM9_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM9_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM9_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM10_F_LPHINT_MASK (0x4000000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM10_F_LPHINT_SHIFT (26U)
/*! LP_FLEXCOMM10_F_LPHINT - LP_FLEXCOMM10 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM10_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM10_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM10_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM11_F_LPHINT_MASK (0x8000000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM11_F_LPHINT_SHIFT (27U)
/*! LP_FLEXCOMM11_F_LPHINT - LP_FLEXCOMM11 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM11_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM11_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM11_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM12_F_LPHINT_MASK (0x10000000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM12_F_LPHINT_SHIFT (28U)
/*! LP_FLEXCOMM12_F_LPHINT - LP_FLEXCOMM12 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM12_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM12_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM12_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM13_F_LPHINT_MASK (0x20000000U)
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM13_F_LPHINT_SHIFT (29U)
/*! LP_FLEXCOMM13_F_LPHINT - LP_FLEXCOMM13 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LP_FLEXCOMM13_F_LPHINT(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LP_FLEXCOMM13_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LP_FLEXCOMM13_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LPSPI14_F_LPHINT_MASK (0x40000000U)
#define SLEEPCON0_LP_HINT0_LPSPI14_F_LPHINT_SHIFT (30U)
/*! LPSPI14_F_LPHINT - LPSPI14 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LPSPI14_F_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LPSPI14_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LPSPI14_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT0_LPSPI16_F_LPHINT_MASK (0x80000000U)
#define SLEEPCON0_LP_HINT0_LPSPI16_F_LPHINT_SHIFT (31U)
/*! LPSPI16_F_LPHINT - LPSPI16 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT0_LPSPI16_F_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT0_LPSPI16_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT0_LPSPI16_F_LPHINT_MASK)
/*! @} */

/*! @name LP_HINT1 - Low-Power Hints 1 */
/*! @{ */

#define SLEEPCON0_LP_HINT1_GPIO0_LPHINT_MASK     (0x1U)
#define SLEEPCON0_LP_HINT1_GPIO0_LPHINT_SHIFT    (0U)
/*! GPIO0_LPHINT - GPIO0 Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_GPIO0_LPHINT(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_GPIO0_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_GPIO0_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_GPIO1_LPHINT_MASK     (0x2U)
#define SLEEPCON0_LP_HINT1_GPIO1_LPHINT_SHIFT    (1U)
/*! GPIO1_LPHINT - GPIO1 Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_GPIO1_LPHINT(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_GPIO1_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_GPIO1_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_GPIO2_LPHINT_MASK     (0x4U)
#define SLEEPCON0_LP_HINT1_GPIO2_LPHINT_SHIFT    (2U)
/*! GPIO2_LPHINT - GPIO2 Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_GPIO2_LPHINT(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_GPIO2_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_GPIO2_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_GPIO3_LPHINT_MASK     (0x8U)
#define SLEEPCON0_LP_HINT1_GPIO3_LPHINT_SHIFT    (3U)
/*! GPIO3_LPHINT - GPIO3 Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_GPIO3_LPHINT(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_GPIO3_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_GPIO3_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_GPIO4_LPHINT_MASK     (0x10U)
#define SLEEPCON0_LP_HINT1_GPIO4_LPHINT_SHIFT    (4U)
/*! GPIO4_LPHINT - GPIO4 Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_GPIO4_LPHINT(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_GPIO4_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_GPIO4_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_GPIO5_LPHINT_MASK     (0x20U)
#define SLEEPCON0_LP_HINT1_GPIO5_LPHINT_SHIFT    (5U)
/*! GPIO5_LPHINT - GPIO5 Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_GPIO5_LPHINT(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_GPIO5_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_GPIO5_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_GPIO6_LPHINT_MASK     (0x40U)
#define SLEEPCON0_LP_HINT1_GPIO6_LPHINT_SHIFT    (6U)
/*! GPIO6_LPHINT - GPIO6 Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_GPIO6_LPHINT(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_GPIO6_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_GPIO6_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_GPIO7_LPHINT_MASK     (0x80U)
#define SLEEPCON0_LP_HINT1_GPIO7_LPHINT_SHIFT    (7U)
/*! GPIO7_LPHINT - GPIO7 Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_GPIO7_LPHINT(x)       (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_GPIO7_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_GPIO7_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_SAI0_B_LPHINT_MASK    (0x100U)
#define SLEEPCON0_LP_HINT1_SAI0_B_LPHINT_SHIFT   (8U)
/*! SAI0_B_LPHINT - SAI0 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_SAI0_B_LPHINT(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_SAI0_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_SAI0_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_SAI1_B_LPHINT_MASK    (0x200U)
#define SLEEPCON0_LP_HINT1_SAI1_B_LPHINT_SHIFT   (9U)
/*! SAI1_B_LPHINT - SAI1 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_SAI1_B_LPHINT(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_SAI1_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_SAI1_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_SAI2_B_LPHINT_MASK    (0x400U)
#define SLEEPCON0_LP_HINT1_SAI2_B_LPHINT_SHIFT   (10U)
/*! SAI2_B_LPHINT - SAI2 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_SAI2_B_LPHINT(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_SAI2_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_SAI2_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_SAI0_F_LPHINT_MASK    (0x800U)
#define SLEEPCON0_LP_HINT1_SAI0_F_LPHINT_SHIFT   (11U)
/*! SAI0_F_LPHINT - SAI0 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_SAI0_F_LPHINT(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_SAI0_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_SAI0_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_SAI1_F_LPHINT_MASK    (0x1000U)
#define SLEEPCON0_LP_HINT1_SAI1_F_LPHINT_SHIFT   (12U)
/*! SAI1_F_LPHINT - SAI1 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_SAI1_F_LPHINT(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_SAI1_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_SAI1_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_SAI2_F_LPHINT_MASK    (0x2000U)
#define SLEEPCON0_LP_HINT1_SAI2_F_LPHINT_SHIFT   (13U)
/*! SAI2_F_LPHINT - SAI2 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_SAI2_F_LPHINT(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_SAI2_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_SAI2_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_FLEXIO_B_LPHINT_MASK  (0x4000U)
#define SLEEPCON0_LP_HINT1_FLEXIO_B_LPHINT_SHIFT (14U)
/*! FLEXIO_B_LPHINT - FLEXIO Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_FLEXIO_B_LPHINT(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_FLEXIO_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_FLEXIO_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_LPI2C15_B_LPHINT_MASK (0x8000U)
#define SLEEPCON0_LP_HINT1_LPI2C15_B_LPHINT_SHIFT (15U)
/*! LPI2C15_B_LPHINT - LPI2C15 Bus Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_LPI2C15_B_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_LPI2C15_B_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_LPI2C15_B_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_FLEXIO_F_LPHINT_MASK  (0x10000U)
#define SLEEPCON0_LP_HINT1_FLEXIO_F_LPHINT_SHIFT (16U)
/*! FLEXIO_F_LPHINT - FLEXIO Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_FLEXIO_F_LPHINT(x)    (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_FLEXIO_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_FLEXIO_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_LPI2C15_F_LPHINT_MASK (0x20000U)
#define SLEEPCON0_LP_HINT1_LPI2C15_F_LPHINT_SHIFT (17U)
/*! LPI2C15_F_LPHINT - LPI2C15 Function Clock Related Logic Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define SLEEPCON0_LP_HINT1_LPI2C15_F_LPHINT(x)   (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_LPI2C15_F_LPHINT_SHIFT)) & SLEEPCON0_LP_HINT1_LPI2C15_F_LPHINT_MASK)

#define SLEEPCON0_LP_HINT1_NIC0_IDLE0_MASK       (0x40000U)
#define SLEEPCON0_LP_HINT1_NIC0_IDLE0_SHIFT      (18U)
/*! NIC0_IDLE0 - NIC_MEDIA0 Idle Status
 *  0b0..Active
 *  0b1..Idle
 */
#define SLEEPCON0_LP_HINT1_NIC0_IDLE0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_NIC0_IDLE0_SHIFT)) & SLEEPCON0_LP_HINT1_NIC0_IDLE0_MASK)

#define SLEEPCON0_LP_HINT1_NIC0_IDLE1_MASK       (0x80000U)
#define SLEEPCON0_LP_HINT1_NIC0_IDLE1_SHIFT      (19U)
/*! NIC0_IDLE1 - NIC_MEDIA0 Idle Status
 *  0b0..Active
 *  0b1..Idle
 */
#define SLEEPCON0_LP_HINT1_NIC0_IDLE1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_NIC0_IDLE1_SHIFT)) & SLEEPCON0_LP_HINT1_NIC0_IDLE1_MASK)

#define SLEEPCON0_LP_HINT1_NIC1_IDLE0_MASK       (0x100000U)
#define SLEEPCON0_LP_HINT1_NIC1_IDLE0_SHIFT      (20U)
/*! NIC1_IDLE0 - NIC_MEDIA1 Idle Status
 *  0b0..Active
 *  0b1..Idle
 */
#define SLEEPCON0_LP_HINT1_NIC1_IDLE0(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_NIC1_IDLE0_SHIFT)) & SLEEPCON0_LP_HINT1_NIC1_IDLE0_MASK)

#define SLEEPCON0_LP_HINT1_NIC1_IDLE1_MASK       (0x200000U)
#define SLEEPCON0_LP_HINT1_NIC1_IDLE1_SHIFT      (21U)
/*! NIC1_IDLE1 - NIC_MEDIA1 Idle Status
 *  0b0..Active
 *  0b1..Idle
 */
#define SLEEPCON0_LP_HINT1_NIC1_IDLE1(x)         (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_HINT1_NIC1_IDLE1_SHIFT)) & SLEEPCON0_LP_HINT1_NIC1_IDLE1_MASK)
/*! @} */

/*! @name LP_DENY0 - Low-Power Request Deny Status 0 */
/*! @{ */

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM0_LPDENY_MASK (0x1U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM0_LPDENY_SHIFT (0U)
/*! LP_FLEXCOMM0_LPDENY - LP_FLEXCOMM0 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM0_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM0_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM0_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM1_LPDENY_MASK (0x2U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM1_LPDENY_SHIFT (1U)
/*! LP_FLEXCOMM1_LPDENY - LP_FLEXCOMM1 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM1_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM1_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM1_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM2_LPDENY_MASK (0x4U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM2_LPDENY_SHIFT (2U)
/*! LP_FLEXCOMM2_LPDENY - LP_FLEXCOMM2 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM2_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM2_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM2_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM3_LPDENY_MASK (0x8U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM3_LPDENY_SHIFT (3U)
/*! LP_FLEXCOMM3_LPDENY - LP_FLEXCOMM3 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM3_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM3_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM3_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM4_LPDENY_MASK (0x10U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM4_LPDENY_SHIFT (4U)
/*! LP_FLEXCOMM4_LPDENY - LP_FLEXCOMM4 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM4_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM4_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM4_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM5_LPDENY_MASK (0x20U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM5_LPDENY_SHIFT (5U)
/*! LP_FLEXCOMM5_LPDENY - LP_FLEXCOMM5 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM5_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM5_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM5_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM6_LPDENY_MASK (0x40U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM6_LPDENY_SHIFT (6U)
/*! LP_FLEXCOMM6_LPDENY - LP_FLEXCOMM6 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM6_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM6_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM6_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM7_LPDENY_MASK (0x80U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM7_LPDENY_SHIFT (7U)
/*! LP_FLEXCOMM7_LPDENY - LP_FLEXCOMM7 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM7_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM7_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM7_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM8_LPDENY_MASK (0x100U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM8_LPDENY_SHIFT (8U)
/*! LP_FLEXCOMM8_LPDENY - LP_FLEXCOMM8 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM8_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM8_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM8_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM9_LPDENY_MASK (0x200U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM9_LPDENY_SHIFT (9U)
/*! LP_FLEXCOMM9_LPDENY - LP_FLEXCOMM9 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM9_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM9_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM9_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM10_LPDENY_MASK (0x400U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM10_LPDENY_SHIFT (10U)
/*! LP_FLEXCOMM10_LPDENY - LP_FLEXCOMM10 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM10_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM10_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM10_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM11_LPDENY_MASK (0x800U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM11_LPDENY_SHIFT (11U)
/*! LP_FLEXCOMM11_LPDENY - LP_FLEXCOMM11 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM11_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM11_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM11_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM12_LPDENY_MASK (0x1000U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM12_LPDENY_SHIFT (12U)
/*! LP_FLEXCOMM12_LPDENY - LP_FLEXCOMM12 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM12_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM12_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM12_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM13_LPDENY_MASK (0x2000U)
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM13_LPDENY_SHIFT (13U)
/*! LP_FLEXCOMM13_LPDENY - LP_FLEXCOMM13 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LP_FLEXCOMM13_LPDENY(x) (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LP_FLEXCOMM13_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LP_FLEXCOMM13_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LPSPI14_LPDENY_MASK   (0x4000U)
#define SLEEPCON0_LP_DENY0_LPSPI14_LPDENY_SHIFT  (14U)
/*! LPSPI14_LPDENY - LPSPI14 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LPSPI14_LPDENY(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LPSPI14_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LPSPI14_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LPSPI16_LPDENY_MASK   (0x8000U)
#define SLEEPCON0_LP_DENY0_LPSPI16_LPDENY_SHIFT  (15U)
/*! LPSPI16_LPDENY - LPSPI16 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LPSPI16_LPDENY(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LPSPI16_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LPSPI16_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_FLEXIO_LPDENY_MASK    (0x10000U)
#define SLEEPCON0_LP_DENY0_FLEXIO_LPDENY_SHIFT   (16U)
/*! FLEXIO_LPDENY - FLEXIO Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_FLEXIO_LPDENY(x)      (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_FLEXIO_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_FLEXIO_LPDENY_MASK)

#define SLEEPCON0_LP_DENY0_LPI2C15_LPDENY_MASK   (0x20000U)
#define SLEEPCON0_LP_DENY0_LPI2C15_LPDENY_SHIFT  (17U)
/*! LPI2C15_LPDENY - LPI2C15 Low-Power Deny Status
 *  0b0..Not deny
 *  0b1..Deny
 */
#define SLEEPCON0_LP_DENY0_LPI2C15_LPDENY(x)     (((uint32_t)(((uint32_t)(x)) << SLEEPCON0_LP_DENY0_LPI2C15_LPDENY_SHIFT)) & SLEEPCON0_LP_DENY0_LPI2C15_LPDENY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SLEEPCON0_Register_Masks */


/*!
 * @}
 */ /* end of group SLEEPCON0_Peripheral_Access_Layer */


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


#endif  /* PERI_SLEEPCON0_H_ */

