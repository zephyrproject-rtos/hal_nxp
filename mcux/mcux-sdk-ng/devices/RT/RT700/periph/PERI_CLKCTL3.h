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
**         CMSIS Peripheral Access Layer for CLKCTL3
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
 * @file PERI_CLKCTL3.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CLKCTL3
 *
 * CMSIS Peripheral Access Layer for CLKCTL3
 */

#if !defined(PERI_CLKCTL3_H_)
#define PERI_CLKCTL3_H_                          /**< Symbol preventing repeated inclusion */

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
   -- CLKCTL3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL3_Peripheral_Access_Layer CLKCTL3 Peripheral Access Layer
 * @{
 */

/** CLKCTL3 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t PSCCTL0_COMP;                      /**< VDD1_SENSE Peripheral Clock Control 0, offset: 0x10 */
       uint8_t RESERVED_1[44];
  __IO uint32_t PSCCTL0_COMP_SET;                  /**< VDD1_SENSE Peripheral Clock Control 0 Set, offset: 0x40 */
       uint8_t RESERVED_2[44];
  __IO uint32_t PSCCTL0_COMP_CLR;                  /**< VDD1_SENSE Peripheral Clock Control 0 Clear, offset: 0x70 */
       uint8_t RESERVED_3[28];
  __IO uint32_t ONE_SRC_CLKSLICE_ENABLE_COMP;      /**< One Source Clock Slice Enable for VDD2_COMP CPU, offset: 0x90 */
       uint8_t RESERVED_4[380];
  __I  uint32_t LPOSCCTL0;                         /**< Low Power Oscillator Control 0, offset: 0x210 */
  __I  uint32_t SENSEBASECLKSEL;                   /**< VDD1_SENSE Clock Source, offset: 0x214 */
       uint8_t RESERVED_5[120];
  __I  uint32_t FRO2CLKSTATUS;                     /**< FRO_TUNER2 Clock Status, offset: 0x290 */
       uint8_t RESERVED_6[4];
  __IO uint32_t FRO2MAXDOMAINEN;                   /**< FRO2MAX Clock Domain Enable, offset: 0x298 */
       uint8_t RESERVED_7[356];
  __IO uint32_t SENSEMAINCLKDIV;                   /**< VDD1_SENSE Main Clock Divider, offset: 0x400 */
       uint8_t RESERVED_8[48];
  __IO uint32_t MAINCLKSEL;                        /**< VDD1_SENSE Main Clock Source Select, offset: 0x434 */
       uint8_t RESERVED_9[24];
  __IO uint32_t SENSERAMCLKSEL;                    /**< VDD1_SENSE RAM Clock Source Select, offset: 0x450 */
       uint8_t RESERVED_10[8];
  __IO uint32_t SENSERAMCLKDIV;                    /**< VDD1_SENSE RAM Clock Divider, offset: 0x45C */
       uint8_t RESERVED_11[32];
  __IO uint32_t OSTIMERFCLKSEL;                    /**< OSTIMER Functional Clock Source Select, offset: 0x480 */
  __IO uint32_t OSTIMERFCLKDIV;                    /**< OSTIMER Functional Clock Divider, offset: 0x484 */
       uint8_t RESERVED_12[376];
  __IO uint32_t SDADCFCLKSEL;                      /**< SDADC Functional Clock Source Select, offset: 0x600 */
  __IO uint32_t SDADCFCLKDIV;                      /**< SDADC Functional Clock Divider, offset: 0x604 */
       uint8_t RESERVED_13[24];
  __IO uint32_t SARADCFCLKSEL;                     /**< ADC0 (SARADC) Functional Clock Source Select, offset: 0x620 */
  __IO uint32_t SARADCFCLKDIV;                     /**< ADC0 (SARADC) Functional Clock Divider, offset: 0x624 */
       uint8_t RESERVED_14[296];
  __IO uint32_t WAKE32KCLKSEL;                     /**< Wake 32 kHZ Clock Source Select, offset: 0x750 */
  __IO uint32_t WAKE32KCLKDIV;                     /**< Wake 32kHZ Clock Divider, offset: 0x754 */
       uint8_t RESERVED_15[40];
  __IO uint32_t MICFILFCLKSEL;                     /**< MICFIL Functional Clock Source Select, offset: 0x780 */
  __IO uint32_t MICFILFCLKDIV;                     /**< MICFIL Functional Clock Divider, offset: 0x784 */
  __IO uint32_t LPI2C15FCLKSEL;                    /**< LPI2C15 Functional Clock Source Select, offset: 0x788 */
  __IO uint32_t LPI2C15FCLKDIV;                    /**< LPI2C15 Functional Clock Divider, offset: 0x78C */
       uint8_t RESERVED_16[112];
  __IO uint32_t CLKOUTCLKSEL;                      /**< CLKOUT_VDD1 Clock Source Select, offset: 0x800 */
  __IO uint32_t CLKOUTCLKDIV;                      /**< CLKOUT_VDD1 Clock Divider, offset: 0x804 */
       uint8_t RESERVED_17[8];
  __IO uint32_t PSCCTL0_SENS;                      /**< VDD1_SENSE Peripheral Clock Control 0, offset: 0x810 */
       uint8_t RESERVED_18[44];
  __IO uint32_t PSCCTL0_SENS_SET;                  /**< VDD1_SENSE Peripheral Clock Control 0 Set, offset: 0x840 */
       uint8_t RESERVED_19[44];
  __IO uint32_t PSCCTL0_SENS_CLR;                  /**< VDD1_SENSE Peripheral Clock Control 0 Clear, offset: 0x870 */
       uint8_t RESERVED_20[28];
  __IO uint32_t ONE_SRC_CLKSLICE_ENABLE_SENSE;     /**< One Source Clock Slice Enable for VDD1_SENSE CPU, offset: 0x890 */
} CLKCTL3_Type;

/* ----------------------------------------------------------------------------
   -- CLKCTL3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL3_Register_Masks CLKCTL3 Register Masks
 * @{
 */

/*! @name PSCCTL0_COMP - VDD1_SENSE Peripheral Clock Control 0 */
/*! @{ */

#define CLKCTL3_PSCCTL0_COMP_CPU1_MASK           (0x1U)
#define CLKCTL3_PSCCTL0_COMP_CPU1_SHIFT          (0U)
/*! CPU1 - CPU1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_CPU1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CPU1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CPU1_MASK)

#define CLKCTL3_PSCCTL0_COMP_MU0_MASK            (0x10U)
#define CLKCTL3_PSCCTL0_COMP_MU0_SHIFT           (4U)
/*! MU0 - MU0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_MU0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_MU0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_MU0_MASK)

#define CLKCTL3_PSCCTL0_COMP_MU1_MASK            (0x20U)
#define CLKCTL3_PSCCTL0_COMP_MU1_SHIFT           (5U)
/*! MU1 - MU1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_MU1(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_MU1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_MU1_MASK)

#define CLKCTL3_PSCCTL0_COMP_MU2_MASK            (0x40U)
#define CLKCTL3_PSCCTL0_COMP_MU2_SHIFT           (6U)
/*! MU2 - MU2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_MU2(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_MU2_SHIFT)) & CLKCTL3_PSCCTL0_COMP_MU2_MASK)

#define CLKCTL3_PSCCTL0_COMP_OSTIMER_MASK        (0x80U)
#define CLKCTL3_PSCCTL0_COMP_OSTIMER_SHIFT       (7U)
/*! OSTIMER - OSTIMER Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_OSTIMER(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_OSTIMER_SHIFT)) & CLKCTL3_PSCCTL0_COMP_OSTIMER_MASK)

#define CLKCTL3_PSCCTL0_COMP_SEMA42_0_MASK       (0x100U)
#define CLKCTL3_PSCCTL0_COMP_SEMA42_0_SHIFT      (8U)
/*! SEMA42_0 - SEMA42_0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SEMA42_0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SEMA42_0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SEMA42_0_MASK)

#define CLKCTL3_PSCCTL0_COMP_SDADC0_MASK         (0x200U)
#define CLKCTL3_PSCCTL0_COMP_SDADC0_SHIFT        (9U)
/*! SDADC0 - SDADC0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SDADC0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SDADC0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SDADC0_MASK)

#define CLKCTL3_PSCCTL0_COMP_SARADC0_MASK        (0x400U)
#define CLKCTL3_PSCCTL0_COMP_SARADC0_SHIFT       (10U)
/*! SARADC0 - ADC0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SARADC0(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SARADC0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SARADC0_MASK)

#define CLKCTL3_PSCCTL0_COMP_ACMP0_MASK          (0x800U)
#define CLKCTL3_PSCCTL0_COMP_ACMP0_SHIFT         (11U)
/*! ACMP0 - ACMP0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_ACMP0(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_ACMP0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_ACMP0_MASK)

#define CLKCTL3_PSCCTL0_COMP_MICFIL_MASK         (0x1000U)
#define CLKCTL3_PSCCTL0_COMP_MICFIL_SHIFT        (12U)
/*! MICFIL - MICFIL Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_MICFIL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_MICFIL_SHIFT)) & CLKCTL3_PSCCTL0_COMP_MICFIL_MASK)

#define CLKCTL3_PSCCTL0_COMP_GLIKEY4_MASK        (0x2000U)
#define CLKCTL3_PSCCTL0_COMP_GLIKEY4_SHIFT       (13U)
/*! GLIKEY4 - GLIKEY4 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_GLIKEY4(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_GLIKEY4_SHIFT)) & CLKCTL3_PSCCTL0_COMP_GLIKEY4_MASK)

#define CLKCTL3_PSCCTL0_COMP_DBG_RT700_MASK      (0x100000U)
#define CLKCTL3_PSCCTL0_COMP_DBG_RT700_SHIFT     (20U)
/*! DBG_RT700 - DBG_RT700 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_DBG_RT700(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_DBG_RT700_SHIFT)) & CLKCTL3_PSCCTL0_COMP_DBG_RT700_MASK)

#define CLKCTL3_PSCCTL0_COMP_SYSCON3_MASK        (0x200000U)
#define CLKCTL3_PSCCTL0_COMP_SYSCON3_SHIFT       (21U)
/*! SYSCON3 - SYSCON3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SYSCON3(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SYSCON3_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SYSCON3_MASK)

#define CLKCTL3_PSCCTL0_COMP_IOPCTL1_MASK        (0x400000U)
#define CLKCTL3_PSCCTL0_COMP_IOPCTL1_SHIFT       (22U)
/*! IOPCTL1 - IOPCTL1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_IOPCTL1(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_IOPCTL1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_IOPCTL1_MASK)

#define CLKCTL3_PSCCTL0_COMP_GLIKEY1_MASK        (0x800000U)
#define CLKCTL3_PSCCTL0_COMP_GLIKEY1_SHIFT       (23U)
/*! GLIKEY1 - GLIKEY1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_GLIKEY1(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_GLIKEY1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_GLIKEY1_MASK)

#define CLKCTL3_PSCCTL0_COMP_LPI2C15_MASK        (0x1000000U)
#define CLKCTL3_PSCCTL0_COMP_LPI2C15_SHIFT       (24U)
/*! LPI2C15 - LPI2C15 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_LPI2C15(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_LPI2C15_SHIFT)) & CLKCTL3_PSCCTL0_COMP_LPI2C15_MASK)

#define CLKCTL3_PSCCTL0_COMP_MEDIA_ACCESS_RAM_ARBITER1_MASK (0x2000000U)
#define CLKCTL3_PSCCTL0_COMP_MEDIA_ACCESS_RAM_ARBITER1_SHIFT (25U)
/*! MEDIA_ACCESS_RAM_ARBITER1 - Media Access RAM Arbiter1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_MEDIA_ACCESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_MEDIA_ACCESS_RAM_ARBITER1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_MEDIA_ACCESS_RAM_ARBITER1_MASK)
/*! @} */

/*! @name PSCCTL0_COMP_SET - VDD1_SENSE Peripheral Clock Control 0 Set */
/*! @{ */

#define CLKCTL3_PSCCTL0_COMP_SET_CPU1_MASK       (0x1U)
#define CLKCTL3_PSCCTL0_COMP_SET_CPU1_SHIFT      (0U)
/*! CPU1 - CPU1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_CPU1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_CPU1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_CPU1_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_MU0_MASK        (0x10U)
#define CLKCTL3_PSCCTL0_COMP_SET_MU0_SHIFT       (4U)
/*! MU0 - MU0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_MU0(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_MU0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_MU0_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_MU1_MASK        (0x20U)
#define CLKCTL3_PSCCTL0_COMP_SET_MU1_SHIFT       (5U)
/*! MU1 - MU1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_MU1(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_MU1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_MU1_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_MU2_MASK        (0x40U)
#define CLKCTL3_PSCCTL0_COMP_SET_MU2_SHIFT       (6U)
/*! MU2 - MU2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_MU2(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_MU2_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_MU2_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_OSTIMER_MASK    (0x80U)
#define CLKCTL3_PSCCTL0_COMP_SET_OSTIMER_SHIFT   (7U)
/*! OSTIMER - OSTIMER Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_OSTIMER(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_OSTIMER_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_OSTIMER_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_SEMA42_0_MASK   (0x100U)
#define CLKCTL3_PSCCTL0_COMP_SET_SEMA42_0_SHIFT  (8U)
/*! SEMA42_0 - SEMA42_0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_SEMA42_0(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_SEMA42_0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_SEMA42_0_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_SDADC0_MASK     (0x200U)
#define CLKCTL3_PSCCTL0_COMP_SET_SDADC0_SHIFT    (9U)
/*! SDADC0 - SDADC0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_SDADC0(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_SDADC0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_SDADC0_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_SARADC0_MASK    (0x400U)
#define CLKCTL3_PSCCTL0_COMP_SET_SARADC0_SHIFT   (10U)
/*! SARADC0 - ADC0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_SARADC0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_SARADC0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_SARADC0_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_ACMP0_MASK      (0x800U)
#define CLKCTL3_PSCCTL0_COMP_SET_ACMP0_SHIFT     (11U)
/*! ACMP0 - ACMP0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_ACMP0(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_ACMP0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_ACMP0_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_MICFIL_MASK     (0x1000U)
#define CLKCTL3_PSCCTL0_COMP_SET_MICFIL_SHIFT    (12U)
/*! MICFIL - MICFIL Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_MICFIL(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_MICFIL_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_MICFIL_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_GLIKEY4_MASK    (0x2000U)
#define CLKCTL3_PSCCTL0_COMP_SET_GLIKEY4_SHIFT   (13U)
/*! GLIKEY4 - GLIKEY4 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_GLIKEY4(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_GLIKEY4_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_GLIKEY4_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_DBG_RT700_MASK  (0x100000U)
#define CLKCTL3_PSCCTL0_COMP_SET_DBG_RT700_SHIFT (20U)
/*! DBG_RT700 - DBG_RT700 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_DBG_RT700(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_DBG_RT700_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_DBG_RT700_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_SYSCON3_MASK    (0x200000U)
#define CLKCTL3_PSCCTL0_COMP_SET_SYSCON3_SHIFT   (21U)
/*! SYSCON3 - SYSCON3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_SYSCON3(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_SYSCON3_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_SYSCON3_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_IOPCTL1_MASK    (0x400000U)
#define CLKCTL3_PSCCTL0_COMP_SET_IOPCTL1_SHIFT   (22U)
/*! IOPCTL1 - IOPCTL1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_IOPCTL1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_IOPCTL1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_IOPCTL1_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_GLIKEY1_MASK    (0x800000U)
#define CLKCTL3_PSCCTL0_COMP_SET_GLIKEY1_SHIFT   (23U)
/*! GLIKEY1 - GLIKEY1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_GLIKEY1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_GLIKEY1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_GLIKEY1_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_LPI2C15_MASK    (0x1000000U)
#define CLKCTL3_PSCCTL0_COMP_SET_LPI2C15_SHIFT   (24U)
/*! LPI2C15 - LPI2C15 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_LPI2C15(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_LPI2C15_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_LPI2C15_MASK)

#define CLKCTL3_PSCCTL0_COMP_SET_MEDIA_ACCESS_RAM_ARBITER1_MASK (0x2000000U)
#define CLKCTL3_PSCCTL0_COMP_SET_MEDIA_ACCESS_RAM_ARBITER1_SHIFT (25U)
/*! MEDIA_ACCESS_RAM_ARBITER1 - Media Access RAM Arbiter1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_COMP_SET_MEDIA_ACCESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_SET_MEDIA_ACCESS_RAM_ARBITER1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_SET_MEDIA_ACCESS_RAM_ARBITER1_MASK)
/*! @} */

/*! @name PSCCTL0_COMP_CLR - VDD1_SENSE Peripheral Clock Control 0 Clear */
/*! @{ */

#define CLKCTL3_PSCCTL0_COMP_CLR_CPU1_MASK       (0x1U)
#define CLKCTL3_PSCCTL0_COMP_CLR_CPU1_SHIFT      (0U)
/*! CPU1 - CPU1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_CPU1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_CPU1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_CPU1_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_MU0_MASK        (0x10U)
#define CLKCTL3_PSCCTL0_COMP_CLR_MU0_SHIFT       (4U)
/*! MU0 - MU0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_MU0(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_MU0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_MU0_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_MU1_MASK        (0x20U)
#define CLKCTL3_PSCCTL0_COMP_CLR_MU1_SHIFT       (5U)
/*! MU1 - MU1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_MU1(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_MU1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_MU1_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_MU2_MASK        (0x40U)
#define CLKCTL3_PSCCTL0_COMP_CLR_MU2_SHIFT       (6U)
/*! MU2 - MU2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_MU2(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_MU2_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_MU2_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_OSTIMER_MASK    (0x80U)
#define CLKCTL3_PSCCTL0_COMP_CLR_OSTIMER_SHIFT   (7U)
/*! OSTIMER - OSTIMER Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_OSTIMER(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_OSTIMER_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_OSTIMER_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_SEMA42_0_MASK   (0x100U)
#define CLKCTL3_PSCCTL0_COMP_CLR_SEMA42_0_SHIFT  (8U)
/*! SEMA42_0 - SEMA42_0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_SEMA42_0(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_SEMA42_0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_SEMA42_0_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_SDADC0_MASK     (0x200U)
#define CLKCTL3_PSCCTL0_COMP_CLR_SDADC0_SHIFT    (9U)
/*! SDADC0 - SDADC0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_SDADC0(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_SDADC0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_SDADC0_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_SARADC0_MASK    (0x400U)
#define CLKCTL3_PSCCTL0_COMP_CLR_SARADC0_SHIFT   (10U)
/*! SARADC0 - ADC0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_SARADC0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_SARADC0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_SARADC0_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_ACMP0_MASK      (0x800U)
#define CLKCTL3_PSCCTL0_COMP_CLR_ACMP0_SHIFT     (11U)
/*! ACMP0 - ACMP0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_ACMP0(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_ACMP0_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_ACMP0_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_MICFIL_MASK     (0x1000U)
#define CLKCTL3_PSCCTL0_COMP_CLR_MICFIL_SHIFT    (12U)
/*! MICFIL - MICFIL Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_MICFIL(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_MICFIL_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_MICFIL_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_GLIKEY4_MASK    (0x2000U)
#define CLKCTL3_PSCCTL0_COMP_CLR_GLIKEY4_SHIFT   (13U)
/*! GLIKEY4 - GLIKEY4 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_GLIKEY4(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_GLIKEY4_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_GLIKEY4_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_DBG_RT700_MASK  (0x100000U)
#define CLKCTL3_PSCCTL0_COMP_CLR_DBG_RT700_SHIFT (20U)
/*! DBG_RT700 - DBG_RT700 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_DBG_RT700(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_DBG_RT700_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_DBG_RT700_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_SYSCON3_MASK    (0x200000U)
#define CLKCTL3_PSCCTL0_COMP_CLR_SYSCON3_SHIFT   (21U)
/*! SYSCON3 - SYSCON3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_SYSCON3(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_SYSCON3_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_SYSCON3_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_IOPCTL1_MASK    (0x400000U)
#define CLKCTL3_PSCCTL0_COMP_CLR_IOPCTL1_SHIFT   (22U)
/*! IOPCTL1 - IOPCTL1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_IOPCTL1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_IOPCTL1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_IOPCTL1_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_GLIKEY1_MASK    (0x800000U)
#define CLKCTL3_PSCCTL0_COMP_CLR_GLIKEY1_SHIFT   (23U)
/*! GLIKEY1 - GLIKEY1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_GLIKEY1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_GLIKEY1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_GLIKEY1_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_LPI2C15_MASK    (0x1000000U)
#define CLKCTL3_PSCCTL0_COMP_CLR_LPI2C15_SHIFT   (24U)
/*! LPI2C15 - LPI2C15 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_LPI2C15(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_LPI2C15_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_LPI2C15_MASK)

#define CLKCTL3_PSCCTL0_COMP_CLR_MEDIA_ACCESS_RAM_ARBITER1_MASK (0x2000000U)
#define CLKCTL3_PSCCTL0_COMP_CLR_MEDIA_ACCESS_RAM_ARBITER1_SHIFT (25U)
/*! MEDIA_ACCESS_RAM_ARBITER1 - Media Access RAM Arbiter1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_COMP_CLR_MEDIA_ACCESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_COMP_CLR_MEDIA_ACCESS_RAM_ARBITER1_SHIFT)) & CLKCTL3_PSCCTL0_COMP_CLR_MEDIA_ACCESS_RAM_ARBITER1_MASK)
/*! @} */

/*! @name ONE_SRC_CLKSLICE_ENABLE_COMP - One Source Clock Slice Enable for VDD2_COMP CPU */
/*! @{ */

#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_COMP_RTC_FCLK_EN_MASK (0x1U)
#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_COMP_RTC_FCLK_EN_SHIFT (0U)
/*! RTC_FCLK_EN - RTC Functional Clock Gating Enable
 *  0b0..Gates RTC functional clock.
 *  0b1..Enables RTC functional clock.
 */
#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_COMP_RTC_FCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_COMP_RTC_FCLK_EN_SHIFT)) & CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_COMP_RTC_FCLK_EN_MASK)

#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_COMP_DGDET3_FCLK_EN_MASK (0x4U)
#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_COMP_DGDET3_FCLK_EN_SHIFT (2U)
/*! dGDET3_FCLK_EN - dGDET3 Functional Clock Gating Enable
 *  0b0..Gates dGDET3 functional clock.
 *  0b1..Enables dGDET3 functional clock.
 */
#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_COMP_DGDET3_FCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_COMP_DGDET3_FCLK_EN_SHIFT)) & CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_COMP_DGDET3_FCLK_EN_MASK)
/*! @} */

/*! @name LPOSCCTL0 - Low Power Oscillator Control 0 */
/*! @{ */

#define CLKCTL3_LPOSCCTL0_CLKRDY_MASK            (0x80000000U)
#define CLKCTL3_LPOSCCTL0_CLKRDY_SHIFT           (31U)
/*! CLKRDY - LPOSC Clock Ready
 *  0b0..LPOSC clock is not ready.
 *  0b1..LPOSC clock is ready.
 */
#define CLKCTL3_LPOSCCTL0_CLKRDY(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL3_LPOSCCTL0_CLKRDY_SHIFT)) & CLKCTL3_LPOSCCTL0_CLKRDY_MASK)
/*! @} */

/*! @name SENSEBASECLKSEL - VDD1_SENSE Clock Source */
/*! @{ */

#define CLKCTL3_SENSEBASECLKSEL_SEL_MASK         (0x3U)
#define CLKCTL3_SENSEBASECLKSEL_SEL_SHIFT        (0U)
/*! SEL - VDD1_SENSE Base Clock Source Selection
 *  0b00..fro1_div3
 *  0b01..fro1_max
 *  0b10..fro2_div3
 *  0b11..1m_lposc
 */
#define CLKCTL3_SENSEBASECLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SENSEBASECLKSEL_SEL_SHIFT)) & CLKCTL3_SENSEBASECLKSEL_SEL_MASK)
/*! @} */

/*! @name FRO2CLKSTATUS - FRO_TUNER2 Clock Status */
/*! @{ */

#define CLKCTL3_FRO2CLKSTATUS_CLK_OK_MASK        (0x1U)
#define CLKCTL3_FRO2CLKSTATUS_CLK_OK_SHIFT       (0U)
/*! CLK_OK - FRO_TUNER2 Clock OK
 *  0b0..FRO_TUNER2 clock has not yet reached its final frequency.
 *  0b1..FRO_TUNER2 clock has reached its final frequency.
 */
#define CLKCTL3_FRO2CLKSTATUS_CLK_OK(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_FRO2CLKSTATUS_CLK_OK_SHIFT)) & CLKCTL3_FRO2CLKSTATUS_CLK_OK_MASK)
/*! @} */

/*! @name FRO2MAXDOMAINEN - FRO2MAX Clock Domain Enable */
/*! @{ */

#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_CMPT_MASK (0x1U)
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_CMPT_SHIFT (0U)
/*! FRO2MAX_OF_CMPT - Enable fro2_max Clock Control of VDD2_COMP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_CMPT(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_CMPT_SHIFT)) & CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_CMPT_MASK)

#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_SENSE_MASK (0x2U)
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_SENSE_SHIFT (1U)
/*! FRO2MAX_OF_SENSE - Enable fro2_max Clock Control of VDD1_SENSE Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_SENSE(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_SENSE_SHIFT)) & CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_SENSE_MASK)

#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_VDD2_DSP_MASK (0x4U)
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_VDD2_DSP_SHIFT (2U)
/*! FRO2MAX_OF_VDD2_DSP - Enable fro2_max Clock Control of VDD2_DSP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_VDD2_DSP(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_VDD2_DSP_SHIFT)) & CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_VDD2_DSP_MASK)

#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_MD2_MASK (0x8U)
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_MD2_SHIFT (3U)
/*! FRO2MAX_OF_MD2 - Enable fro2_max Clock Control of VDD2_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_MD2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_MD2_SHIFT)) & CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_MD2_MASK)

#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_MDN_MASK (0x10U)
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_MDN_SHIFT (4U)
/*! FRO2MAX_OF_MDN - Enable fro2_max Clock Control of VDDN_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_MDN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_MDN_SHIFT)) & CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_MDN_MASK)

#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_VDD2_COM_MASK (0x20U)
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_VDD2_COM_SHIFT (5U)
/*! FRO2MAX_OF_VDD2_COM - Enable fro2_max Clock Control of VDD2_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_VDD2_COM(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_VDD2_COM_SHIFT)) & CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_VDD2_COM_MASK)

#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_COMN_MASK (0x40U)
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_COMN_SHIFT (6U)
/*! FRO2MAX_OF_COMN - Enable fro2_max Clock Control of VDDN_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_COMN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_COMN_SHIFT)) & CLKCTL3_FRO2MAXDOMAINEN_FRO2MAX_OF_COMN_MASK)
/*! @} */

/*! @name SENSEMAINCLKDIV - VDD1_SENSE Main Clock Divider */
/*! @{ */

#define CLKCTL3_SENSEMAINCLKDIV_DIV_MASK         (0xFFU)
#define CLKCTL3_SENSEMAINCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL3_SENSEMAINCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SENSEMAINCLKDIV_DIV_SHIFT)) & CLKCTL3_SENSEMAINCLKDIV_DIV_MASK)

#define CLKCTL3_SENSEMAINCLKDIV_BUSY_MASK        (0x10000000U)
#define CLKCTL3_SENSEMAINCLKDIV_BUSY_SHIFT       (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_SENSEMAINCLKDIV_BUSY(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SENSEMAINCLKDIV_BUSY_SHIFT)) & CLKCTL3_SENSEMAINCLKDIV_BUSY_MASK)

#define CLKCTL3_SENSEMAINCLKDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL3_SENSEMAINCLKDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL3_SENSEMAINCLKDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SENSEMAINCLKDIV_REQFLAG_SHIFT)) & CLKCTL3_SENSEMAINCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name MAINCLKSEL - VDD1_SENSE Main Clock Source Select */
/*! @{ */

#define CLKCTL3_MAINCLKSEL_SEL_MASK              (0x3U)
#define CLKCTL3_MAINCLKSEL_SEL_SHIFT             (0U)
/*! SEL - VDD1_SENSE Main Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..fro2_max
 *  0b10..audio_pll_pfd3
 *  0b11..fro1_max
 */
#define CLKCTL3_MAINCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL3_MAINCLKSEL_SEL_SHIFT)) & CLKCTL3_MAINCLKSEL_SEL_MASK)
/*! @} */

/*! @name SENSERAMCLKSEL - VDD1_SENSE RAM Clock Source Select */
/*! @{ */

#define CLKCTL3_SENSERAMCLKSEL_SEL_MASK          (0x3U)
#define CLKCTL3_SENSERAMCLKSEL_SEL_SHIFT         (0U)
/*! SEL - VDD1_SENSE RAM Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..fro2_max
 *  0b10..audio_pll_pfd2
 *  0b11..fro1_max
 */
#define CLKCTL3_SENSERAMCLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SENSERAMCLKSEL_SEL_SHIFT)) & CLKCTL3_SENSERAMCLKSEL_SEL_MASK)
/*! @} */

/*! @name SENSERAMCLKDIV - VDD1_SENSE RAM Clock Divider */
/*! @{ */

#define CLKCTL3_SENSERAMCLKDIV_DIV_MASK          (0xFFU)
#define CLKCTL3_SENSERAMCLKDIV_DIV_SHIFT         (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL3_SENSERAMCLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SENSERAMCLKDIV_DIV_SHIFT)) & CLKCTL3_SENSERAMCLKDIV_DIV_MASK)

#define CLKCTL3_SENSERAMCLKDIV_BUSY_MASK         (0x10000000U)
#define CLKCTL3_SENSERAMCLKDIV_BUSY_SHIFT        (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_SENSERAMCLKDIV_BUSY(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SENSERAMCLKDIV_BUSY_SHIFT)) & CLKCTL3_SENSERAMCLKDIV_BUSY_MASK)

#define CLKCTL3_SENSERAMCLKDIV_REQFLAG_MASK      (0x80000000U)
#define CLKCTL3_SENSERAMCLKDIV_REQFLAG_SHIFT     (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_SENSERAMCLKDIV_REQFLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SENSERAMCLKDIV_REQFLAG_SHIFT)) & CLKCTL3_SENSERAMCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name OSTIMERFCLKSEL - OSTIMER Functional Clock Source Select */
/*! @{ */

#define CLKCTL3_OSTIMERFCLKSEL_SEL_MASK          (0x3U)
#define CLKCTL3_OSTIMERFCLKSEL_SEL_SHIFT         (0U)
/*! SEL - Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..wake32k_clk
 *  0b10..1m_lposc
 *  0b11..osc_clk
 */
#define CLKCTL3_OSTIMERFCLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_OSTIMERFCLKSEL_SEL_SHIFT)) & CLKCTL3_OSTIMERFCLKSEL_SEL_MASK)

#define CLKCTL3_OSTIMERFCLKSEL_SEL_EN_MASK       (0x4U)
#define CLKCTL3_OSTIMERFCLKSEL_SEL_EN_SHIFT      (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL3_OSTIMERFCLKSEL_SEL_EN(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL3_OSTIMERFCLKSEL_SEL_EN_SHIFT)) & CLKCTL3_OSTIMERFCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name OSTIMERFCLKDIV - OSTIMER Functional Clock Divider */
/*! @{ */

#define CLKCTL3_OSTIMERFCLKDIV_DIV_MASK          (0xFFU)
#define CLKCTL3_OSTIMERFCLKDIV_DIV_SHIFT         (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL3_OSTIMERFCLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_OSTIMERFCLKDIV_DIV_SHIFT)) & CLKCTL3_OSTIMERFCLKDIV_DIV_MASK)

#define CLKCTL3_OSTIMERFCLKDIV_BUSY_MASK         (0x10000000U)
#define CLKCTL3_OSTIMERFCLKDIV_BUSY_SHIFT        (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_OSTIMERFCLKDIV_BUSY(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_OSTIMERFCLKDIV_BUSY_SHIFT)) & CLKCTL3_OSTIMERFCLKDIV_BUSY_MASK)

#define CLKCTL3_OSTIMERFCLKDIV_RESET_MASK        (0x20000000U)
#define CLKCTL3_OSTIMERFCLKDIV_RESET_SHIFT       (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL3_OSTIMERFCLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_OSTIMERFCLKDIV_RESET_SHIFT)) & CLKCTL3_OSTIMERFCLKDIV_RESET_MASK)

#define CLKCTL3_OSTIMERFCLKDIV_HALT_MASK         (0x40000000U)
#define CLKCTL3_OSTIMERFCLKDIV_HALT_SHIFT        (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL3_OSTIMERFCLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_OSTIMERFCLKDIV_HALT_SHIFT)) & CLKCTL3_OSTIMERFCLKDIV_HALT_MASK)

#define CLKCTL3_OSTIMERFCLKDIV_REQFLAG_MASK      (0x80000000U)
#define CLKCTL3_OSTIMERFCLKDIV_REQFLAG_SHIFT     (31U)
/*! REQFLAG - Request Flag
 *  0b0..The divider change has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_OSTIMERFCLKDIV_REQFLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL3_OSTIMERFCLKDIV_REQFLAG_SHIFT)) & CLKCTL3_OSTIMERFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SDADCFCLKSEL - SDADC Functional Clock Source Select */
/*! @{ */

#define CLKCTL3_SDADCFCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL3_SDADCFCLKSEL_SEL_SHIFT           (0U)
/*! SEL - SDADC Functional Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..fro2_div8
 *  0b10..audio_pll_vco
 *  0b11..audio_clk
 */
#define CLKCTL3_SDADCFCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SDADCFCLKSEL_SEL_SHIFT)) & CLKCTL3_SDADCFCLKSEL_SEL_MASK)

#define CLKCTL3_SDADCFCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL3_SDADCFCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL3_SDADCFCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SDADCFCLKSEL_SEL_EN_SHIFT)) & CLKCTL3_SDADCFCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SDADCFCLKDIV - SDADC Functional Clock Divider */
/*! @{ */

#define CLKCTL3_SDADCFCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL3_SDADCFCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL3_SDADCFCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SDADCFCLKDIV_DIV_SHIFT)) & CLKCTL3_SDADCFCLKDIV_DIV_MASK)

#define CLKCTL3_SDADCFCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL3_SDADCFCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_SDADCFCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SDADCFCLKDIV_BUSY_SHIFT)) & CLKCTL3_SDADCFCLKDIV_BUSY_MASK)

#define CLKCTL3_SDADCFCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL3_SDADCFCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL3_SDADCFCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SDADCFCLKDIV_RESET_SHIFT)) & CLKCTL3_SDADCFCLKDIV_RESET_MASK)

#define CLKCTL3_SDADCFCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL3_SDADCFCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL3_SDADCFCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SDADCFCLKDIV_HALT_SHIFT)) & CLKCTL3_SDADCFCLKDIV_HALT_MASK)

#define CLKCTL3_SDADCFCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL3_SDADCFCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_SDADCFCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SDADCFCLKDIV_REQFLAG_SHIFT)) & CLKCTL3_SDADCFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SARADCFCLKSEL - ADC0 (SARADC) Functional Clock Source Select */
/*! @{ */

#define CLKCTL3_SARADCFCLKSEL_SEL_MASK           (0x3U)
#define CLKCTL3_SARADCFCLKSEL_SEL_SHIFT          (0U)
/*! SEL - Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..main_pll_pfd1
 *  0b10..fro2_max
 *  0b11..osc_clk
 */
#define CLKCTL3_SARADCFCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SARADCFCLKSEL_SEL_SHIFT)) & CLKCTL3_SARADCFCLKSEL_SEL_MASK)

#define CLKCTL3_SARADCFCLKSEL_SEL_EN_MASK        (0x4U)
#define CLKCTL3_SARADCFCLKSEL_SEL_EN_SHIFT       (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL3_SARADCFCLKSEL_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SARADCFCLKSEL_SEL_EN_SHIFT)) & CLKCTL3_SARADCFCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SARADCFCLKDIV - ADC0 (SARADC) Functional Clock Divider */
/*! @{ */

#define CLKCTL3_SARADCFCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL3_SARADCFCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL3_SARADCFCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SARADCFCLKDIV_DIV_SHIFT)) & CLKCTL3_SARADCFCLKDIV_DIV_MASK)

#define CLKCTL3_SARADCFCLKDIV_BUSY_MASK          (0x10000000U)
#define CLKCTL3_SARADCFCLKDIV_BUSY_SHIFT         (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_SARADCFCLKDIV_BUSY(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SARADCFCLKDIV_BUSY_SHIFT)) & CLKCTL3_SARADCFCLKDIV_BUSY_MASK)

#define CLKCTL3_SARADCFCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL3_SARADCFCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL3_SARADCFCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SARADCFCLKDIV_RESET_SHIFT)) & CLKCTL3_SARADCFCLKDIV_RESET_MASK)

#define CLKCTL3_SARADCFCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL3_SARADCFCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL3_SARADCFCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SARADCFCLKDIV_HALT_SHIFT)) & CLKCTL3_SARADCFCLKDIV_HALT_MASK)

#define CLKCTL3_SARADCFCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL3_SARADCFCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_SARADCFCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL3_SARADCFCLKDIV_REQFLAG_SHIFT)) & CLKCTL3_SARADCFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name WAKE32KCLKSEL - Wake 32 kHZ Clock Source Select */
/*! @{ */

#define CLKCTL3_WAKE32KCLKSEL_SEL_MASK           (0x3U)
#define CLKCTL3_WAKE32KCLKSEL_SEL_SHIFT          (0U)
/*! SEL - Clock Source Select
 *  0b00..osc_32k
 *  0b01..lp_32k (1m_lposc clock divided by 32)
 *  0b10..Reserved
 *  0b11..Tied to logic 0. This may be selected to reduce power when no output is needed.
 */
#define CLKCTL3_WAKE32KCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL3_WAKE32KCLKSEL_SEL_SHIFT)) & CLKCTL3_WAKE32KCLKSEL_SEL_MASK)
/*! @} */

/*! @name WAKE32KCLKDIV - Wake 32kHZ Clock Divider */
/*! @{ */

#define CLKCTL3_WAKE32KCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL3_WAKE32KCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL3_WAKE32KCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL3_WAKE32KCLKDIV_DIV_SHIFT)) & CLKCTL3_WAKE32KCLKDIV_DIV_MASK)

#define CLKCTL3_WAKE32KCLKDIV_BUSY_MASK          (0x10000000U)
#define CLKCTL3_WAKE32KCLKDIV_BUSY_SHIFT         (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_WAKE32KCLKDIV_BUSY(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_WAKE32KCLKDIV_BUSY_SHIFT)) & CLKCTL3_WAKE32KCLKDIV_BUSY_MASK)

#define CLKCTL3_WAKE32KCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL3_WAKE32KCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL3_WAKE32KCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_WAKE32KCLKDIV_RESET_SHIFT)) & CLKCTL3_WAKE32KCLKDIV_RESET_MASK)

#define CLKCTL3_WAKE32KCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL3_WAKE32KCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL3_WAKE32KCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_WAKE32KCLKDIV_HALT_SHIFT)) & CLKCTL3_WAKE32KCLKDIV_HALT_MASK)

#define CLKCTL3_WAKE32KCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL3_WAKE32KCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_WAKE32KCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL3_WAKE32KCLKDIV_REQFLAG_SHIFT)) & CLKCTL3_WAKE32KCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name MICFILFCLKSEL - MICFIL Functional Clock Source Select */
/*! @{ */

#define CLKCTL3_MICFILFCLKSEL_SEL_MASK           (0x3U)
#define CLKCTL3_MICFILFCLKSEL_SEL_SHIFT          (0U)
/*! SEL - Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..audio_pll_pfd3
 *  0b10..fro2_max
 *  0b11..audio_clk
 */
#define CLKCTL3_MICFILFCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL3_MICFILFCLKSEL_SEL_SHIFT)) & CLKCTL3_MICFILFCLKSEL_SEL_MASK)

#define CLKCTL3_MICFILFCLKSEL_SEL_EN_MASK        (0x4U)
#define CLKCTL3_MICFILFCLKSEL_SEL_EN_SHIFT       (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL3_MICFILFCLKSEL_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_MICFILFCLKSEL_SEL_EN_SHIFT)) & CLKCTL3_MICFILFCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name MICFILFCLKDIV - MICFIL Functional Clock Divider */
/*! @{ */

#define CLKCTL3_MICFILFCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL3_MICFILFCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock Divider Value */
#define CLKCTL3_MICFILFCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL3_MICFILFCLKDIV_DIV_SHIFT)) & CLKCTL3_MICFILFCLKDIV_DIV_MASK)

#define CLKCTL3_MICFILFCLKDIV_BUSY_MASK          (0x10000000U)
#define CLKCTL3_MICFILFCLKDIV_BUSY_SHIFT         (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_MICFILFCLKDIV_BUSY(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_MICFILFCLKDIV_BUSY_SHIFT)) & CLKCTL3_MICFILFCLKDIV_BUSY_MASK)

#define CLKCTL3_MICFILFCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL3_MICFILFCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL3_MICFILFCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_MICFILFCLKDIV_RESET_SHIFT)) & CLKCTL3_MICFILFCLKDIV_RESET_MASK)

#define CLKCTL3_MICFILFCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL3_MICFILFCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL3_MICFILFCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_MICFILFCLKDIV_HALT_SHIFT)) & CLKCTL3_MICFILFCLKDIV_HALT_MASK)

#define CLKCTL3_MICFILFCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL3_MICFILFCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Request Flag
 *  0b0..The divider change has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_MICFILFCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL3_MICFILFCLKDIV_REQFLAG_SHIFT)) & CLKCTL3_MICFILFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name LPI2C15FCLKSEL - LPI2C15 Functional Clock Source Select */
/*! @{ */

#define CLKCTL3_LPI2C15FCLKSEL_SEL_MASK          (0x3U)
#define CLKCTL3_LPI2C15FCLKSEL_SEL_SHIFT         (0U)
/*! SEL - LPI2C15 Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..fro1_max
 *  0b10..fro1_div2
 *  0b11..fro2_max
 */
#define CLKCTL3_LPI2C15FCLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_LPI2C15FCLKSEL_SEL_SHIFT)) & CLKCTL3_LPI2C15FCLKSEL_SEL_MASK)

#define CLKCTL3_LPI2C15FCLKSEL_SEL_EN_MASK       (0x4U)
#define CLKCTL3_LPI2C15FCLKSEL_SEL_EN_SHIFT      (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL3_LPI2C15FCLKSEL_SEL_EN(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL3_LPI2C15FCLKSEL_SEL_EN_SHIFT)) & CLKCTL3_LPI2C15FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name LPI2C15FCLKDIV - LPI2C15 Functional Clock Divider */
/*! @{ */

#define CLKCTL3_LPI2C15FCLKDIV_DIV_MASK          (0xFFU)
#define CLKCTL3_LPI2C15FCLKDIV_DIV_SHIFT         (0U)
/*! DIV - LPI2C15 Clock Divider Value */
#define CLKCTL3_LPI2C15FCLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_LPI2C15FCLKDIV_DIV_SHIFT)) & CLKCTL3_LPI2C15FCLKDIV_DIV_MASK)

#define CLKCTL3_LPI2C15FCLKDIV_BUSY_MASK         (0x10000000U)
#define CLKCTL3_LPI2C15FCLKDIV_BUSY_SHIFT        (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_LPI2C15FCLKDIV_BUSY(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_LPI2C15FCLKDIV_BUSY_SHIFT)) & CLKCTL3_LPI2C15FCLKDIV_BUSY_MASK)

#define CLKCTL3_LPI2C15FCLKDIV_RESET_MASK        (0x20000000U)
#define CLKCTL3_LPI2C15FCLKDIV_RESET_SHIFT       (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL3_LPI2C15FCLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_LPI2C15FCLKDIV_RESET_SHIFT)) & CLKCTL3_LPI2C15FCLKDIV_RESET_MASK)

#define CLKCTL3_LPI2C15FCLKDIV_HALT_MASK         (0x40000000U)
#define CLKCTL3_LPI2C15FCLKDIV_HALT_SHIFT        (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL3_LPI2C15FCLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_LPI2C15FCLKDIV_HALT_SHIFT)) & CLKCTL3_LPI2C15FCLKDIV_HALT_MASK)

#define CLKCTL3_LPI2C15FCLKDIV_REQFLAG_MASK      (0x80000000U)
#define CLKCTL3_LPI2C15FCLKDIV_REQFLAG_SHIFT     (31U)
/*! REQFLAG - Request Flag
 *  0b0..The Divider change has been finished (clock being divided must be running for this status to change).
 *  0b1..The Divider value is being changed.
 */
#define CLKCTL3_LPI2C15FCLKDIV_REQFLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL3_LPI2C15FCLKDIV_REQFLAG_SHIFT)) & CLKCTL3_LPI2C15FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CLKOUTCLKSEL - CLKOUT_VDD1 Clock Source Select */
/*! @{ */

#define CLKCTL3_CLKOUTCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL3_CLKOUTCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..audio_pll_pfd3
 *  0b10..fro2_max
 *  0b11..fro1_max
 */
#define CLKCTL3_CLKOUTCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL3_CLKOUTCLKSEL_SEL_SHIFT)) & CLKCTL3_CLKOUTCLKSEL_SEL_MASK)

#define CLKCTL3_CLKOUTCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL3_CLKOUTCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL3_CLKOUTCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_CLKOUTCLKSEL_SEL_EN_SHIFT)) & CLKCTL3_CLKOUTCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name CLKOUTCLKDIV - CLKOUT_VDD1 Clock Divider */
/*! @{ */

#define CLKCTL3_CLKOUTCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL3_CLKOUTCLKDIV_DIV_SHIFT           (0U)
/*! DIV - CLKOUT_VDD1 Clock Divider */
#define CLKCTL3_CLKOUTCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL3_CLKOUTCLKDIV_DIV_SHIFT)) & CLKCTL3_CLKOUTCLKDIV_DIV_MASK)

#define CLKCTL3_CLKOUTCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL3_CLKOUTCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT_VDD1 is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_CLKOUTCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL3_CLKOUTCLKDIV_BUSY_SHIFT)) & CLKCTL3_CLKOUTCLKDIV_BUSY_MASK)

#define CLKCTL3_CLKOUTCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL3_CLKOUTCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Divider Counter Reset
 */
#define CLKCTL3_CLKOUTCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_CLKOUTCLKDIV_RESET_SHIFT)) & CLKCTL3_CLKOUTCLKDIV_RESET_MASK)

#define CLKCTL3_CLKOUTCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL3_CLKOUTCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL3_CLKOUTCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL3_CLKOUTCLKDIV_HALT_SHIFT)) & CLKCTL3_CLKOUTCLKDIV_HALT_MASK)

#define CLKCTL3_CLKOUTCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL3_CLKOUTCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL3_CLKOUTCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_CLKOUTCLKDIV_REQFLAG_SHIFT)) & CLKCTL3_CLKOUTCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name PSCCTL0_SENS - VDD1_SENSE Peripheral Clock Control 0 */
/*! @{ */

#define CLKCTL3_PSCCTL0_SENS_MU0_MASK            (0x10U)
#define CLKCTL3_PSCCTL0_SENS_MU0_SHIFT           (4U)
/*! MU0 - MU0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_MU0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_MU0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_MU0_MASK)

#define CLKCTL3_PSCCTL0_SENS_MU1_MASK            (0x20U)
#define CLKCTL3_PSCCTL0_SENS_MU1_SHIFT           (5U)
/*! MU1 - MU1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_MU1(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_MU1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_MU1_MASK)

#define CLKCTL3_PSCCTL0_SENS_MU2_MASK            (0x40U)
#define CLKCTL3_PSCCTL0_SENS_MU2_SHIFT           (6U)
/*! MU2 - MU2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_MU2(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_MU2_SHIFT)) & CLKCTL3_PSCCTL0_SENS_MU2_MASK)

#define CLKCTL3_PSCCTL0_SENS_OSTIMER_MASK        (0x80U)
#define CLKCTL3_PSCCTL0_SENS_OSTIMER_SHIFT       (7U)
/*! OSTIMER - OSTIMER Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_OSTIMER(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_OSTIMER_SHIFT)) & CLKCTL3_PSCCTL0_SENS_OSTIMER_MASK)

#define CLKCTL3_PSCCTL0_SENS_SEMA42_0_MASK       (0x100U)
#define CLKCTL3_PSCCTL0_SENS_SEMA42_0_SHIFT      (8U)
/*! SEMA42_0 - SEMA42_0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SEMA42_0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SEMA42_0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SEMA42_0_MASK)

#define CLKCTL3_PSCCTL0_SENS_SDADC0_MASK         (0x200U)
#define CLKCTL3_PSCCTL0_SENS_SDADC0_SHIFT        (9U)
/*! SDADC0 - SDADC0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SDADC0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SDADC0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SDADC0_MASK)

#define CLKCTL3_PSCCTL0_SENS_SARADC0_MASK        (0x400U)
#define CLKCTL3_PSCCTL0_SENS_SARADC0_SHIFT       (10U)
/*! SARADC0 - ADC0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SARADC0(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SARADC0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SARADC0_MASK)

#define CLKCTL3_PSCCTL0_SENS_ACMP0_MASK          (0x800U)
#define CLKCTL3_PSCCTL0_SENS_ACMP0_SHIFT         (11U)
/*! ACMP0 - ACMP0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_ACMP0(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_ACMP0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_ACMP0_MASK)

#define CLKCTL3_PSCCTL0_SENS_MICFIL_MASK         (0x1000U)
#define CLKCTL3_PSCCTL0_SENS_MICFIL_SHIFT        (12U)
/*! MICFIL - MICFIL Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_MICFIL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_MICFIL_SHIFT)) & CLKCTL3_PSCCTL0_SENS_MICFIL_MASK)

#define CLKCTL3_PSCCTL0_SENS_GLIKEY4_MASK        (0x2000U)
#define CLKCTL3_PSCCTL0_SENS_GLIKEY4_SHIFT       (13U)
/*! GLIKEY4 - GLIKEY4 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_GLIKEY4(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_GLIKEY4_SHIFT)) & CLKCTL3_PSCCTL0_SENS_GLIKEY4_MASK)

#define CLKCTL3_PSCCTL0_SENS_DBG_RT700_MASK      (0x100000U)
#define CLKCTL3_PSCCTL0_SENS_DBG_RT700_SHIFT     (20U)
/*! DBG_RT700 - DBG_RT700 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_DBG_RT700(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_DBG_RT700_SHIFT)) & CLKCTL3_PSCCTL0_SENS_DBG_RT700_MASK)

#define CLKCTL3_PSCCTL0_SENS_SYSCON3_MASK        (0x200000U)
#define CLKCTL3_PSCCTL0_SENS_SYSCON3_SHIFT       (21U)
/*! SYSCON3 - SYSCON3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SYSCON3(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SYSCON3_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SYSCON3_MASK)

#define CLKCTL3_PSCCTL0_SENS_IOPCTL1_MASK        (0x400000U)
#define CLKCTL3_PSCCTL0_SENS_IOPCTL1_SHIFT       (22U)
/*! IOPCTL1 - IOPCTL1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_IOPCTL1(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_IOPCTL1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_IOPCTL1_MASK)

#define CLKCTL3_PSCCTL0_SENS_GLIKEY1_MASK        (0x800000U)
#define CLKCTL3_PSCCTL0_SENS_GLIKEY1_SHIFT       (23U)
/*! GLIKEY1 - GLIKEY1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_GLIKEY1(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_GLIKEY1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_GLIKEY1_MASK)

#define CLKCTL3_PSCCTL0_SENS_LPI2C15_MASK        (0x1000000U)
#define CLKCTL3_PSCCTL0_SENS_LPI2C15_SHIFT       (24U)
/*! LPI2C15 - LPI2C15 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_LPI2C15(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_LPI2C15_SHIFT)) & CLKCTL3_PSCCTL0_SENS_LPI2C15_MASK)

#define CLKCTL3_PSCCTL0_SENS_MEDIA_ACCESS_RAM_ARBITER1_MASK (0x2000000U)
#define CLKCTL3_PSCCTL0_SENS_MEDIA_ACCESS_RAM_ARBITER1_SHIFT (25U)
/*! MEDIA_ACCESS_RAM_ARBITER1 - Media Access RAM Arbiter1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_MEDIA_ACCESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_MEDIA_ACCESS_RAM_ARBITER1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_MEDIA_ACCESS_RAM_ARBITER1_MASK)
/*! @} */

/*! @name PSCCTL0_SENS_SET - VDD1_SENSE Peripheral Clock Control 0 Set */
/*! @{ */

#define CLKCTL3_PSCCTL0_SENS_SET_CPU1_MASK       (0x1U)
#define CLKCTL3_PSCCTL0_SENS_SET_CPU1_SHIFT      (0U)
/*! CPU1 - CPU1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_CPU1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_CPU1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_CPU1_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_MU0_MASK        (0x10U)
#define CLKCTL3_PSCCTL0_SENS_SET_MU0_SHIFT       (4U)
/*! MU0 - MU0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_MU0(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_MU0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_MU0_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_MU1_MASK        (0x20U)
#define CLKCTL3_PSCCTL0_SENS_SET_MU1_SHIFT       (5U)
/*! MU1 - MU1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_MU1(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_MU1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_MU1_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_MU2_MASK        (0x40U)
#define CLKCTL3_PSCCTL0_SENS_SET_MU2_SHIFT       (6U)
/*! MU2 - MU2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_MU2(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_MU2_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_MU2_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_OSTIMER_MASK    (0x80U)
#define CLKCTL3_PSCCTL0_SENS_SET_OSTIMER_SHIFT   (7U)
/*! OSTIMER - OSTIMER Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_OSTIMER(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_OSTIMER_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_OSTIMER_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_SEMA42_0_MASK   (0x100U)
#define CLKCTL3_PSCCTL0_SENS_SET_SEMA42_0_SHIFT  (8U)
/*! SEMA42_0 - SEMA42_0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_SEMA42_0(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_SEMA42_0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_SEMA42_0_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_SDADC0_MASK     (0x200U)
#define CLKCTL3_PSCCTL0_SENS_SET_SDADC0_SHIFT    (9U)
/*! SDADC0 - SDADC0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_SDADC0(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_SDADC0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_SDADC0_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_SARADC0_MASK    (0x400U)
#define CLKCTL3_PSCCTL0_SENS_SET_SARADC0_SHIFT   (10U)
/*! SARADC0 - ADC0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_SARADC0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_SARADC0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_SARADC0_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_ACMP0_MASK      (0x800U)
#define CLKCTL3_PSCCTL0_SENS_SET_ACMP0_SHIFT     (11U)
/*! ACMP0 - ACMP0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_ACMP0(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_ACMP0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_ACMP0_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_MICFIL_MASK     (0x1000U)
#define CLKCTL3_PSCCTL0_SENS_SET_MICFIL_SHIFT    (12U)
/*! MICFIL - MICFIL Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_MICFIL(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_MICFIL_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_MICFIL_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_GLIKEY4_MASK    (0x2000U)
#define CLKCTL3_PSCCTL0_SENS_SET_GLIKEY4_SHIFT   (13U)
/*! GLIKEY4 - GLIKEY4 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_GLIKEY4(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_GLIKEY4_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_GLIKEY4_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_DBG_RT700_MASK  (0x100000U)
#define CLKCTL3_PSCCTL0_SENS_SET_DBG_RT700_SHIFT (20U)
/*! DBG_RT700 - DBG_RT700 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_DBG_RT700(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_DBG_RT700_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_DBG_RT700_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_SYSCON3_MASK    (0x200000U)
#define CLKCTL3_PSCCTL0_SENS_SET_SYSCON3_SHIFT   (21U)
/*! SYSCON3 - SYSCON3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_SYSCON3(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_SYSCON3_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_SYSCON3_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_IOPCTL1_MASK    (0x400000U)
#define CLKCTL3_PSCCTL0_SENS_SET_IOPCTL1_SHIFT   (22U)
/*! IOPCTL1 - IOPCTL1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_IOPCTL1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_IOPCTL1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_IOPCTL1_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_GLIKEY1_MASK    (0x800000U)
#define CLKCTL3_PSCCTL0_SENS_SET_GLIKEY1_SHIFT   (23U)
/*! GLIKEY1 - GLIKEY1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_GLIKEY1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_GLIKEY1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_GLIKEY1_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_LPI2C15_MASK    (0x1000000U)
#define CLKCTL3_PSCCTL0_SENS_SET_LPI2C15_SHIFT   (24U)
/*! LPI2C15 - LPI2C15 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_LPI2C15(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_LPI2C15_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_LPI2C15_MASK)

#define CLKCTL3_PSCCTL0_SENS_SET_MEDIA_ACESS_RAM_ARBITER1_MASK (0x2000000U)
#define CLKCTL3_PSCCTL0_SENS_SET_MEDIA_ACESS_RAM_ARBITER1_SHIFT (25U)
/*! MEDIA_ACESS_RAM_ARBITER1 - Media Access RAM Arbiter1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL3_PSCCTL0_SENS_SET_MEDIA_ACESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_SET_MEDIA_ACESS_RAM_ARBITER1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_SET_MEDIA_ACESS_RAM_ARBITER1_MASK)
/*! @} */

/*! @name PSCCTL0_SENS_CLR - VDD1_SENSE Peripheral Clock Control 0 Clear */
/*! @{ */

#define CLKCTL3_PSCCTL0_SENS_CLR_CPU1_MASK       (0x1U)
#define CLKCTL3_PSCCTL0_SENS_CLR_CPU1_SHIFT      (0U)
/*! CPU1 - CPU1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_CPU1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_CPU1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_CPU1_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_MU0_MASK        (0x10U)
#define CLKCTL3_PSCCTL0_SENS_CLR_MU0_SHIFT       (4U)
/*! MU0 - MU0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_MU0(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_MU0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_MU0_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_MU1_MASK        (0x20U)
#define CLKCTL3_PSCCTL0_SENS_CLR_MU1_SHIFT       (5U)
/*! MU1 - MU1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_MU1(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_MU1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_MU1_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_MU2_MASK        (0x40U)
#define CLKCTL3_PSCCTL0_SENS_CLR_MU2_SHIFT       (6U)
/*! MU2 - MU2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_MU2(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_MU2_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_MU2_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_OSTIMER_MASK    (0x80U)
#define CLKCTL3_PSCCTL0_SENS_CLR_OSTIMER_SHIFT   (7U)
/*! OSTIMER - OSTIMER Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_OSTIMER(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_OSTIMER_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_OSTIMER_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_SEMA42_0_MASK   (0x100U)
#define CLKCTL3_PSCCTL0_SENS_CLR_SEMA42_0_SHIFT  (8U)
/*! SEMA42_0 - SEMA42_0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_SEMA42_0(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_SEMA42_0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_SEMA42_0_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_SDADC0_MASK     (0x200U)
#define CLKCTL3_PSCCTL0_SENS_CLR_SDADC0_SHIFT    (9U)
/*! SDADC0 - SDADC0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_SDADC0(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_SDADC0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_SDADC0_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_SARADC0_MASK    (0x400U)
#define CLKCTL3_PSCCTL0_SENS_CLR_SARADC0_SHIFT   (10U)
/*! SARADC0 - ADC0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_SARADC0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_SARADC0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_SARADC0_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_ACMP0_MASK      (0x800U)
#define CLKCTL3_PSCCTL0_SENS_CLR_ACMP0_SHIFT     (11U)
/*! ACMP0 - ACMP0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_ACMP0(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_ACMP0_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_ACMP0_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_MICFIL_MASK     (0x1000U)
#define CLKCTL3_PSCCTL0_SENS_CLR_MICFIL_SHIFT    (12U)
/*! MICFIL - MICFIL Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_MICFIL(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_MICFIL_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_MICFIL_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_GLIKEY4_MASK    (0x2000U)
#define CLKCTL3_PSCCTL0_SENS_CLR_GLIKEY4_SHIFT   (13U)
/*! GLIKEY4 - GLIKEY4 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_GLIKEY4(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_GLIKEY4_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_GLIKEY4_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_DBG_RT700_MASK  (0x100000U)
#define CLKCTL3_PSCCTL0_SENS_CLR_DBG_RT700_SHIFT (20U)
/*! DBG_RT700 - DBG_RT700 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_DBG_RT700(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_DBG_RT700_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_DBG_RT700_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_SYSCON3_MASK    (0x200000U)
#define CLKCTL3_PSCCTL0_SENS_CLR_SYSCON3_SHIFT   (21U)
/*! SYSCON3 - SYSCON3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_SYSCON3(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_SYSCON3_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_SYSCON3_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_IOPCTL1_MASK    (0x400000U)
#define CLKCTL3_PSCCTL0_SENS_CLR_IOPCTL1_SHIFT   (22U)
/*! IOPCTL1 - IOPCTL1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_IOPCTL1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_IOPCTL1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_IOPCTL1_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_GLIKEY1_MASK    (0x800000U)
#define CLKCTL3_PSCCTL0_SENS_CLR_GLIKEY1_SHIFT   (23U)
/*! GLIKEY1 - GLIKEY1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_GLIKEY1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_GLIKEY1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_GLIKEY1_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_LPI2C15_MASK    (0x1000000U)
#define CLKCTL3_PSCCTL0_SENS_CLR_LPI2C15_SHIFT   (24U)
/*! LPI2C15 - LPI2C15 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_LPI2C15(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_LPI2C15_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_LPI2C15_MASK)

#define CLKCTL3_PSCCTL0_SENS_CLR_MEDIA_ACCESS_RAM_ARBITER1_MASK (0x2000000U)
#define CLKCTL3_PSCCTL0_SENS_CLR_MEDIA_ACCESS_RAM_ARBITER1_SHIFT (25U)
/*! MEDIA_ACCESS_RAM_ARBITER1 - Media Access RAM Arbiter1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL3_PSCCTL0_SENS_CLR_MEDIA_ACCESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_PSCCTL0_SENS_CLR_MEDIA_ACCESS_RAM_ARBITER1_SHIFT)) & CLKCTL3_PSCCTL0_SENS_CLR_MEDIA_ACCESS_RAM_ARBITER1_MASK)
/*! @} */

/*! @name ONE_SRC_CLKSLICE_ENABLE_SENSE - One Source Clock Slice Enable for VDD1_SENSE CPU */
/*! @{ */

#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_SENSE_RTC_FCLK_EN_MASK (0x1U)
#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_SENSE_RTC_FCLK_EN_SHIFT (0U)
/*! RTC_FCLK_EN - RTC Functional Clock Gating Enable
 *  0b0..Gates RTC functional clock.
 *  0b1..Enables RTC functional clock.
 */
#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_SENSE_RTC_FCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_SENSE_RTC_FCLK_EN_SHIFT)) & CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_SENSE_RTC_FCLK_EN_MASK)

#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_SENSE_DGDET3_FCLK_EN_MASK (0x4U)
#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_SENSE_DGDET3_FCLK_EN_SHIFT (2U)
/*! dGDET3_FCLK_EN - dGDET3 Functional Clock Enable
 *  0b0..Gates dGDET3 functional clock.
 *  0b1..Enables dGDET3 functional clock.
 */
#define CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_SENSE_DGDET3_FCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_SENSE_DGDET3_FCLK_EN_SHIFT)) & CLKCTL3_ONE_SRC_CLKSLICE_ENABLE_SENSE_DGDET3_FCLK_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CLKCTL3_Register_Masks */


/*!
 * @}
 */ /* end of group CLKCTL3_Peripheral_Access_Layer */


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


#endif  /* PERI_CLKCTL3_H_ */

