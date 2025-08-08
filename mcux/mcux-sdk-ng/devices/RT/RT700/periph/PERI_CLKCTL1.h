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
**         CMSIS Peripheral Access Layer for CLKCTL1
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
 * @file PERI_CLKCTL1.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CLKCTL1
 *
 * CMSIS Peripheral Access Layer for CLKCTL1
 */

#if !defined(PERI_CLKCTL1_H_)
#define PERI_CLKCTL1_H_                          /**< Symbol preventing repeated inclusion */

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
   -- CLKCTL1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL1_Peripheral_Access_Layer CLKCTL1 Peripheral Access Layer
 * @{
 */

/** CLKCTL1 - Size of Registers Arrays */
#define CLKCTL1_CTIMERNFCLKSEL_COUNT              3u
#define CLKCTL1_CTIMER_COUNT                      3u
#define CLKCTL1_FLEXCOMM_COUNT                    4u

/** CLKCTL1 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t PSCCTL0;                           /**< VDD1_SENSE Peripheral Clock Control 0, offset: 0x10 */
  __IO uint32_t PSCCTL1;                           /**< VDD1_SENSE Peripheral Clock Control 1, offset: 0x14 */
       uint8_t RESERVED_1[40];
  __IO uint32_t PSCCTL0_SET;                       /**< VDD1_SENSE Peripheral Clock Control 0 Set, offset: 0x40 */
  __IO uint32_t PSCCTL1_SET;                       /**< VDD1_SENSE Peripheral Clock Control 1 Set, offset: 0x44 */
       uint8_t RESERVED_2[40];
  __IO uint32_t PSCCTL0_CLR;                       /**< VDD1_SENSE Peripheral Clock Control 0 Clear, offset: 0x70 */
  __IO uint32_t PSCCTL1_CLR;                       /**< VDD1_SENSE Peripheral Clock Control 1 Clear, offset: 0x74 */
       uint8_t RESERVED_3[960];
  __IO uint32_t SENSEBASECLKSEL;                   /**< VDD1_SENSE Base Clock Select Source, offset: 0x438 */
       uint8_t RESERVED_4[4];
  __IO uint32_t SENSEDSPCPUCLKDIV;                 /**< CPU Clock of DSP in VDD1_SENSE Clock Divider, offset: 0x440 */
  __IO uint32_t SENSEDSPCPUCLKSEL;                 /**< CPU Clock of DSP in VDD1_SENSE Clock Select, offset: 0x444 */
       uint8_t RESERVED_5[184];
  __IO uint32_t SAI3FCLKSEL;                       /**< SAI3 Clock Select Source, offset: 0x500 */
  __IO uint32_t SAI3CLKDIV;                        /**< SAI3 Functional Clock Divider, offset: 0x504 */
       uint8_t RESERVED_6[504];
  __IO uint32_t UTICK1FCLKSEL;                     /**< UTICK1 Functional Clock Source Select, offset: 0x700 */
  __IO uint32_t UTICK1CLKDIV;                      /**< UTICK1 Functional Clock Divider, offset: 0x704 */
       uint8_t RESERVED_7[24];
  __IO uint32_t WWDT2FCLKSEL;                      /**< WWDT2 Functional Clock Source Select, offset: 0x720 */
       uint8_t RESERVED_8[28];
  __IO uint32_t WWDT3FCLKSEL;                      /**< WWDT3 Functional Clock Source Select, offset: 0x740 */
       uint8_t RESERVED_9[28];
  __IO uint32_t SYSTICKFCLKSEL;                    /**< SYSTICK Functional Clock Select Source, offset: 0x760 */
  __IO uint32_t SYSTICKFCLKDIV;                    /**< SYSTICK Functional Clock Divider, offset: 0x764 */
       uint8_t RESERVED_10[56];
  __IO uint32_t CTIMERFCLKSEL[CLKCTL1_CTIMERNFCLKSEL_COUNT]; /**< CTIMER5 Functional Clock Source Select..CTIMER7 Functional Clock Source Select, array offset: 0x7A0, array step: 0x4 */
       uint8_t RESERVED_11[4];
  __IO uint32_t CTIMERCLKDIV[CLKCTL1_CTIMER_COUNT]; /**< CTIMER5 Functional Clock Divider..CTIMER7 Functional Clock Divider, array offset: 0x7B0, array step: 0x4 */
       uint8_t RESERVED_12[68];
  __IO uint32_t I3C23FCLKSEL;                      /**< I3C2 and I3C3 Functional Clock Source Select, offset: 0x800 */
       uint8_t RESERVED_13[12];
  __IO uint32_t I3C23FCLKDIV;                      /**< I3C2 and I3C3 Functional Clock Divider, offset: 0x810 */
       uint8_t RESERVED_14[492];
  struct {                                         /* offset: 0xA00, array step: 0x20 */
    __IO uint32_t FCFCLKSEL;                         /**< LP_FLEXCOMM17 Clock Source Select..LP_FLEXCOMM20 Clock Source Select, array offset: 0xA00, array step: 0x20 */
    __IO uint32_t FCFCLKDIV;                         /**< LP_FLEXCOMM17 Clock Divider..LP_FLEXCOMM20 Clock Divider, array offset: 0xA04, array step: 0x20 */
         uint8_t RESERVED_0[24];
  } FLEXCOMM[CLKCTL1_FLEXCOMM_COUNT];
       uint8_t RESERVED_15[32];
  __IO uint32_t AUDIOVDD1CLKSEL;                   /**< VDD1_SENSE Audio Clock Source, offset: 0xAA0 */
} CLKCTL1_Type;

/* ----------------------------------------------------------------------------
   -- CLKCTL1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL1_Register_Masks CLKCTL1 Register Masks
 * @{
 */

/*! @name PSCCTL0 - VDD1_SENSE Peripheral Clock Control 0 */
/*! @{ */

#define CLKCTL1_PSCCTL0_SLEEPCON1_MASK           (0x40U)
#define CLKCTL1_PSCCTL0_SLEEPCON1_SHIFT          (6U)
/*! SLEEPCON1 - SLEEPCON1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL0_SLEEPCON1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SLEEPCON1_SHIFT)) & CLKCTL1_PSCCTL0_SLEEPCON1_MASK)

#define CLKCTL1_PSCCTL0_SYSCON1_MASK             (0x80U)
#define CLKCTL1_PSCCTL0_SYSCON1_SHIFT            (7U)
/*! SYSCON1 - SYSCON1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL0_SYSCON1(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SYSCON1_SHIFT)) & CLKCTL1_PSCCTL0_SYSCON1_MASK)
/*! @} */

/*! @name PSCCTL1 - VDD1_SENSE Peripheral Clock Control 1 */
/*! @{ */

#define CLKCTL1_PSCCTL1_SENSE_ACCESS_RAM_ARBITER0_MASK (0x1U)
#define CLKCTL1_PSCCTL1_SENSE_ACCESS_RAM_ARBITER0_SHIFT (0U)
/*! SENSE_ACCESS_RAM_ARBITER0 - VDD1_SENSE Access RAM Arbiter0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SENSE_ACCESS_RAM_ARBITER0(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SENSE_ACCESS_RAM_ARBITER0_SHIFT)) & CLKCTL1_PSCCTL1_SENSE_ACCESS_RAM_ARBITER0_MASK)

#define CLKCTL1_PSCCTL1_HIFI1_MASK               (0x2U)
#define CLKCTL1_PSCCTL1_HIFI1_SHIFT              (1U)
/*! HiFi1 - HiFi1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_HIFI1(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_HIFI1_SHIFT)) & CLKCTL1_PSCCTL1_HIFI1_MASK)

#define CLKCTL1_PSCCTL1_EDMA2_MASK               (0x10U)
#define CLKCTL1_PSCCTL1_EDMA2_SHIFT              (4U)
/*! eDMA2 - eDMA2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_EDMA2(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_EDMA2_SHIFT)) & CLKCTL1_PSCCTL1_EDMA2_MASK)

#define CLKCTL1_PSCCTL1_EDMA3_MASK               (0x20U)
#define CLKCTL1_PSCCTL1_EDMA3_SHIFT              (5U)
/*! eDMA3 - eDMA3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_EDMA3(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_EDMA3_SHIFT)) & CLKCTL1_PSCCTL1_EDMA3_MASK)

#define CLKCTL1_PSCCTL1_LP_FLEXCOMM17_MASK       (0x40U)
#define CLKCTL1_PSCCTL1_LP_FLEXCOMM17_SHIFT      (6U)
/*! LP_FLEXCOMM17 - LP_FLEXCOMM17 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_LP_FLEXCOMM17(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_LP_FLEXCOMM17_SHIFT)) & CLKCTL1_PSCCTL1_LP_FLEXCOMM17_MASK)

#define CLKCTL1_PSCCTL1_LP_FLEXCOMM18_MASK       (0x80U)
#define CLKCTL1_PSCCTL1_LP_FLEXCOMM18_SHIFT      (7U)
/*! LP_FLEXCOMM18 - LP_FLEXCOMM18 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_LP_FLEXCOMM18(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_LP_FLEXCOMM18_SHIFT)) & CLKCTL1_PSCCTL1_LP_FLEXCOMM18_MASK)

#define CLKCTL1_PSCCTL1_LP_FLEXCOMM19_MASK       (0x100U)
#define CLKCTL1_PSCCTL1_LP_FLEXCOMM19_SHIFT      (8U)
/*! LP_FLEXCOMM19 - LP_FLEXCOMM19 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_LP_FLEXCOMM19(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_LP_FLEXCOMM19_SHIFT)) & CLKCTL1_PSCCTL1_LP_FLEXCOMM19_MASK)

#define CLKCTL1_PSCCTL1_LP_FLEXCOMM20_MASK       (0x200U)
#define CLKCTL1_PSCCTL1_LP_FLEXCOMM20_SHIFT      (9U)
/*! LP_FLEXCOMM20 - LP_FLEXCOMM20 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_LP_FLEXCOMM20(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_LP_FLEXCOMM20_SHIFT)) & CLKCTL1_PSCCTL1_LP_FLEXCOMM20_MASK)

#define CLKCTL1_PSCCTL1_SAI3_MASK                (0x400U)
#define CLKCTL1_PSCCTL1_SAI3_SHIFT               (10U)
/*! SAI3 - SAI3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SAI3(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SAI3_SHIFT)) & CLKCTL1_PSCCTL1_SAI3_MASK)

#define CLKCTL1_PSCCTL1_I3C2_MASK                (0x800U)
#define CLKCTL1_PSCCTL1_I3C2_SHIFT               (11U)
/*! I3C2 - I3C2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_I3C2(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_I3C2_SHIFT)) & CLKCTL1_PSCCTL1_I3C2_MASK)

#define CLKCTL1_PSCCTL1_I3C3_MASK                (0x1000U)
#define CLKCTL1_PSCCTL1_I3C3_SHIFT               (12U)
/*! I3C3 - I3C3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_I3C3(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_I3C3_SHIFT)) & CLKCTL1_PSCCTL1_I3C3_MASK)

#define CLKCTL1_PSCCTL1_GPIO8_MASK               (0x2000U)
#define CLKCTL1_PSCCTL1_GPIO8_SHIFT              (13U)
/*! GPIO8 - GPIO8 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_GPIO8(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_GPIO8_SHIFT)) & CLKCTL1_PSCCTL1_GPIO8_MASK)

#define CLKCTL1_PSCCTL1_GPIO9_MASK               (0x4000U)
#define CLKCTL1_PSCCTL1_GPIO9_SHIFT              (14U)
/*! GPIO9 - GPIO9 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_GPIO9(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_GPIO9_SHIFT)) & CLKCTL1_PSCCTL1_GPIO9_MASK)

#define CLKCTL1_PSCCTL1_GPIO10_MASK              (0x8000U)
#define CLKCTL1_PSCCTL1_GPIO10_SHIFT             (15U)
/*! GPIO10 - GPIO10 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_GPIO10(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_GPIO10_SHIFT)) & CLKCTL1_PSCCTL1_GPIO10_MASK)

#define CLKCTL1_PSCCTL1_PINT1_MASK               (0x10000U)
#define CLKCTL1_PSCCTL1_PINT1_SHIFT              (16U)
/*! PINT1 - PINT1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_PINT1(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_PINT1_SHIFT)) & CLKCTL1_PSCCTL1_PINT1_MASK)

#define CLKCTL1_PSCCTL1_CTIMER5_MASK             (0x20000U)
#define CLKCTL1_PSCCTL1_CTIMER5_SHIFT            (17U)
/*! CTIMER5 - CTIMER5 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_CTIMER5(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CTIMER5_SHIFT)) & CLKCTL1_PSCCTL1_CTIMER5_MASK)

#define CLKCTL1_PSCCTL1_CTIMER6_MASK             (0x40000U)
#define CLKCTL1_PSCCTL1_CTIMER6_SHIFT            (18U)
/*! CTIMER6 - CTIMER6 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_CTIMER6(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CTIMER6_SHIFT)) & CLKCTL1_PSCCTL1_CTIMER6_MASK)

#define CLKCTL1_PSCCTL1_CTIMER7_MASK             (0x80000U)
#define CLKCTL1_PSCCTL1_CTIMER7_SHIFT            (19U)
/*! CTIMER7 - CTIMER7 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_CTIMER7(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CTIMER7_SHIFT)) & CLKCTL1_PSCCTL1_CTIMER7_MASK)

#define CLKCTL1_PSCCTL1_MRT1_MASK                (0x100000U)
#define CLKCTL1_PSCCTL1_MRT1_SHIFT               (20U)
/*! MRT1 - MRT1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_MRT1(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_MRT1_SHIFT)) & CLKCTL1_PSCCTL1_MRT1_MASK)

#define CLKCTL1_PSCCTL1_UTICK1_MASK              (0x200000U)
#define CLKCTL1_PSCCTL1_UTICK1_SHIFT             (21U)
/*! UTICK1 - UTICK1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_UTICK1(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_UTICK1_SHIFT)) & CLKCTL1_PSCCTL1_UTICK1_MASK)

#define CLKCTL1_PSCCTL1_CDOG3_MASK               (0x400000U)
#define CLKCTL1_PSCCTL1_CDOG3_SHIFT              (22U)
/*! CDOG3 - CDOG3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_CDOG3(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CDOG3_SHIFT)) & CLKCTL1_PSCCTL1_CDOG3_MASK)

#define CLKCTL1_PSCCTL1_CDOG4_MASK               (0x800000U)
#define CLKCTL1_PSCCTL1_CDOG4_SHIFT              (23U)
/*! CDOG4 - CDOG4 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_CDOG4(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CDOG4_SHIFT)) & CLKCTL1_PSCCTL1_CDOG4_MASK)

#define CLKCTL1_PSCCTL1_MU3_MASK                 (0x1000000U)
#define CLKCTL1_PSCCTL1_MU3_SHIFT                (24U)
/*! MU3 - MU3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_MU3(x)                   (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_MU3_SHIFT)) & CLKCTL1_PSCCTL1_MU3_MASK)

#define CLKCTL1_PSCCTL1_SEMA42_3_MASK            (0x2000000U)
#define CLKCTL1_PSCCTL1_SEMA42_3_SHIFT           (25U)
/*! SEMA42_3 - SEMA42_3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SEMA42_3(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SEMA42_3_SHIFT)) & CLKCTL1_PSCCTL1_SEMA42_3_MASK)

#define CLKCTL1_PSCCTL1_WWDT2_MASK               (0x4000000U)
#define CLKCTL1_PSCCTL1_WWDT2_SHIFT              (26U)
/*! WWDT2 - WWDT2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_WWDT2(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_WWDT2_SHIFT)) & CLKCTL1_PSCCTL1_WWDT2_MASK)

#define CLKCTL1_PSCCTL1_WWDT3_MASK               (0x8000000U)
#define CLKCTL1_PSCCTL1_WWDT3_SHIFT              (27U)
/*! WWDT3 - WWDT3 clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_WWDT3(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_WWDT3_SHIFT)) & CLKCTL1_PSCCTL1_WWDT3_MASK)

#define CLKCTL1_PSCCTL1_INPUTMUX1_MASK           (0x40000000U)
#define CLKCTL1_PSCCTL1_INPUTMUX1_SHIFT          (30U)
/*! INPUTMUX1 - INPUTMUX1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_INPUTMUX1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_INPUTMUX1_SHIFT)) & CLKCTL1_PSCCTL1_INPUTMUX1_MASK)
/*! @} */

/*! @name PSCCTL0_SET - VDD1_SENSE Peripheral Clock Control 0 Set */
/*! @{ */

#define CLKCTL1_PSCCTL0_SET_SLEEPCON1_MASK       (0x40U)
#define CLKCTL1_PSCCTL0_SET_SLEEPCON1_SHIFT      (6U)
/*! SLEEPCON1 - SLEEPCON1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL0_SET_SLEEPCON1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_SLEEPCON1_SHIFT)) & CLKCTL1_PSCCTL0_SET_SLEEPCON1_MASK)

#define CLKCTL1_PSCCTL0_SET_SYSCON1_MASK         (0x80U)
#define CLKCTL1_PSCCTL0_SET_SYSCON1_SHIFT        (7U)
/*! SYSCON1 - SYSCON1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL0_SET_SYSCON1(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_SET_SYSCON1_SHIFT)) & CLKCTL1_PSCCTL0_SET_SYSCON1_MASK)
/*! @} */

/*! @name PSCCTL1_SET - VDD1_SENSE Peripheral Clock Control 1 Set */
/*! @{ */

#define CLKCTL1_PSCCTL1_SET_SENSE_ACCESS_RAM_ARBITER0_MASK (0x1U)
#define CLKCTL1_PSCCTL1_SET_SENSE_ACCESS_RAM_ARBITER0_SHIFT (0U)
/*! SENSE_ACCESS_RAM_ARBITER0 - VDD1_SENSE Access RAM Arbiter0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_SENSE_ACCESS_RAM_ARBITER0(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_SENSE_ACCESS_RAM_ARBITER0_SHIFT)) & CLKCTL1_PSCCTL1_SET_SENSE_ACCESS_RAM_ARBITER0_MASK)

#define CLKCTL1_PSCCTL1_SET_HIFI1_MASK           (0x2U)
#define CLKCTL1_PSCCTL1_SET_HIFI1_SHIFT          (1U)
/*! HiFi1 - HiFi1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_HIFI1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_HIFI1_SHIFT)) & CLKCTL1_PSCCTL1_SET_HIFI1_MASK)

#define CLKCTL1_PSCCTL1_SET_EDMA2_MASK           (0x10U)
#define CLKCTL1_PSCCTL1_SET_EDMA2_SHIFT          (4U)
/*! eDMA2 - eDMA2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_EDMA2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_EDMA2_SHIFT)) & CLKCTL1_PSCCTL1_SET_EDMA2_MASK)

#define CLKCTL1_PSCCTL1_SET_EDMA3_MASK           (0x20U)
#define CLKCTL1_PSCCTL1_SET_EDMA3_SHIFT          (5U)
/*! eDMA3 - eDMA3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_EDMA3(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_EDMA3_SHIFT)) & CLKCTL1_PSCCTL1_SET_EDMA3_MASK)

#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM17_MASK   (0x40U)
#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM17_SHIFT  (6U)
/*! LP_FLEXCOMM17 - LP_FLEXCOMM17 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM17(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM17_SHIFT)) & CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM17_MASK)

#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM18_MASK   (0x80U)
#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM18_SHIFT  (7U)
/*! LP_FLEXCOMM18 - LP_FLEXCOMM18 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM18(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM18_SHIFT)) & CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM18_MASK)

#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM19_MASK   (0x100U)
#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM19_SHIFT  (8U)
/*! LP_FLEXCOMM19 - LP_FLEXCOMM19 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM19(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM19_SHIFT)) & CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM19_MASK)

#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM20_MASK   (0x200U)
#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM20_SHIFT  (9U)
/*! LP_FLEXCOMM20 - LP_FLEXCOMM20 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM20(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM20_SHIFT)) & CLKCTL1_PSCCTL1_SET_LP_FLEXCOMM20_MASK)

#define CLKCTL1_PSCCTL1_SET_SAI3_MASK            (0x400U)
#define CLKCTL1_PSCCTL1_SET_SAI3_SHIFT           (10U)
/*! SAI3 - SAI3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_SAI3(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_SAI3_SHIFT)) & CLKCTL1_PSCCTL1_SET_SAI3_MASK)

#define CLKCTL1_PSCCTL1_SET_I3C2_MASK            (0x800U)
#define CLKCTL1_PSCCTL1_SET_I3C2_SHIFT           (11U)
/*! I3C2 - I3C2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_I3C2(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_I3C2_SHIFT)) & CLKCTL1_PSCCTL1_SET_I3C2_MASK)

#define CLKCTL1_PSCCTL1_SET_I3C3_MASK            (0x1000U)
#define CLKCTL1_PSCCTL1_SET_I3C3_SHIFT           (12U)
/*! I3C3 - I3C3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_I3C3(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_I3C3_SHIFT)) & CLKCTL1_PSCCTL1_SET_I3C3_MASK)

#define CLKCTL1_PSCCTL1_SET_GPIO8_MASK           (0x2000U)
#define CLKCTL1_PSCCTL1_SET_GPIO8_SHIFT          (13U)
/*! GPIO8 - GPIO8 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_GPIO8(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_GPIO8_SHIFT)) & CLKCTL1_PSCCTL1_SET_GPIO8_MASK)

#define CLKCTL1_PSCCTL1_SET_GPIO9_MASK           (0x4000U)
#define CLKCTL1_PSCCTL1_SET_GPIO9_SHIFT          (14U)
/*! GPIO9 - GPIO9 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_GPIO9(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_GPIO9_SHIFT)) & CLKCTL1_PSCCTL1_SET_GPIO9_MASK)

#define CLKCTL1_PSCCTL1_SET_GPIO10_MASK          (0x8000U)
#define CLKCTL1_PSCCTL1_SET_GPIO10_SHIFT         (15U)
/*! GPIO10 - GPIO10 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_GPIO10(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_GPIO10_SHIFT)) & CLKCTL1_PSCCTL1_SET_GPIO10_MASK)

#define CLKCTL1_PSCCTL1_SET_PINT1_MASK           (0x10000U)
#define CLKCTL1_PSCCTL1_SET_PINT1_SHIFT          (16U)
/*! PINT1 - PINT1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_PINT1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_PINT1_SHIFT)) & CLKCTL1_PSCCTL1_SET_PINT1_MASK)

#define CLKCTL1_PSCCTL1_SET_CTIMER5_MASK         (0x20000U)
#define CLKCTL1_PSCCTL1_SET_CTIMER5_SHIFT        (17U)
/*! CTIMER5 - CTIMER5 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_CTIMER5(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_CTIMER5_SHIFT)) & CLKCTL1_PSCCTL1_SET_CTIMER5_MASK)

#define CLKCTL1_PSCCTL1_SET_CTIMER6_MASK         (0x40000U)
#define CLKCTL1_PSCCTL1_SET_CTIMER6_SHIFT        (18U)
/*! CTIMER6 - CTIMER6 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_CTIMER6(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_CTIMER6_SHIFT)) & CLKCTL1_PSCCTL1_SET_CTIMER6_MASK)

#define CLKCTL1_PSCCTL1_SET_CTIMER7_MASK         (0x80000U)
#define CLKCTL1_PSCCTL1_SET_CTIMER7_SHIFT        (19U)
/*! CTIMER7 - CTIMER7 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_CTIMER7(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_CTIMER7_SHIFT)) & CLKCTL1_PSCCTL1_SET_CTIMER7_MASK)

#define CLKCTL1_PSCCTL1_SET_MRT1_MASK            (0x100000U)
#define CLKCTL1_PSCCTL1_SET_MRT1_SHIFT           (20U)
/*! MRT1 - MRT1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_MRT1(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_MRT1_SHIFT)) & CLKCTL1_PSCCTL1_SET_MRT1_MASK)

#define CLKCTL1_PSCCTL1_SET_UTICK1_MASK          (0x200000U)
#define CLKCTL1_PSCCTL1_SET_UTICK1_SHIFT         (21U)
/*! UTICK1 - UTICK1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_UTICK1(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_UTICK1_SHIFT)) & CLKCTL1_PSCCTL1_SET_UTICK1_MASK)

#define CLKCTL1_PSCCTL1_SET_CDOG3_MASK           (0x400000U)
#define CLKCTL1_PSCCTL1_SET_CDOG3_SHIFT          (22U)
/*! CDOG3 - CDOG3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_CDOG3(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_CDOG3_SHIFT)) & CLKCTL1_PSCCTL1_SET_CDOG3_MASK)

#define CLKCTL1_PSCCTL1_SET_CDOG4_MASK           (0x800000U)
#define CLKCTL1_PSCCTL1_SET_CDOG4_SHIFT          (23U)
/*! CDOG4 - CDOG4 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_CDOG4(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_CDOG4_SHIFT)) & CLKCTL1_PSCCTL1_SET_CDOG4_MASK)

#define CLKCTL1_PSCCTL1_SET_MU3_MASK             (0x1000000U)
#define CLKCTL1_PSCCTL1_SET_MU3_SHIFT            (24U)
/*! MU3 - MU3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_MU3(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_MU3_SHIFT)) & CLKCTL1_PSCCTL1_SET_MU3_MASK)

#define CLKCTL1_PSCCTL1_SET_SEMA42_3_MASK        (0x2000000U)
#define CLKCTL1_PSCCTL1_SET_SEMA42_3_SHIFT       (25U)
/*! SEMA42_3 - SEMA42_3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_SEMA42_3(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_SEMA42_3_SHIFT)) & CLKCTL1_PSCCTL1_SET_SEMA42_3_MASK)

#define CLKCTL1_PSCCTL1_SET_WWDT2_MASK           (0x4000000U)
#define CLKCTL1_PSCCTL1_SET_WWDT2_SHIFT          (26U)
/*! WWDT2 - WWDT2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_WWDT2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_WWDT2_SHIFT)) & CLKCTL1_PSCCTL1_SET_WWDT2_MASK)

#define CLKCTL1_PSCCTL1_SET_WWDT3_MASK           (0x8000000U)
#define CLKCTL1_PSCCTL1_SET_WWDT3_SHIFT          (27U)
/*! WWDT3 - WWDT3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_WWDT3(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_WWDT3_SHIFT)) & CLKCTL1_PSCCTL1_SET_WWDT3_MASK)

#define CLKCTL1_PSCCTL1_SET_INPUTMUX1_MASK       (0x40000000U)
#define CLKCTL1_PSCCTL1_SET_INPUTMUX1_SHIFT      (30U)
/*! INPUTMUX1 - INPUTMUX1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL1_PSCCTL1_SET_INPUTMUX1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_SET_INPUTMUX1_SHIFT)) & CLKCTL1_PSCCTL1_SET_INPUTMUX1_MASK)
/*! @} */

/*! @name PSCCTL0_CLR - VDD1_SENSE Peripheral Clock Control 0 Clear */
/*! @{ */

#define CLKCTL1_PSCCTL0_CLR_SLEEPCON1_MASK       (0x40U)
#define CLKCTL1_PSCCTL0_CLR_SLEEPCON1_SHIFT      (6U)
/*! SLEEPCON1 - SLEEPCON1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL0_CLR_SLEEPCON1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_SLEEPCON1_SHIFT)) & CLKCTL1_PSCCTL0_CLR_SLEEPCON1_MASK)

#define CLKCTL1_PSCCTL0_CLR_SYSCON1_MASK         (0x80U)
#define CLKCTL1_PSCCTL0_CLR_SYSCON1_SHIFT        (7U)
/*! SYSCON1 - SYSCON1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL0_CLR_SYSCON1(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL0_CLR_SYSCON1_SHIFT)) & CLKCTL1_PSCCTL0_CLR_SYSCON1_MASK)
/*! @} */

/*! @name PSCCTL1_CLR - VDD1_SENSE Peripheral Clock Control 1 Clear */
/*! @{ */

#define CLKCTL1_PSCCTL1_CLR_SENSE_ACCESS_RAM_ARBITER0_MASK (0x1U)
#define CLKCTL1_PSCCTL1_CLR_SENSE_ACCESS_RAM_ARBITER0_SHIFT (0U)
/*! SENSE_ACCESS_RAM_ARBITER0 - VDD1_SENSE Access RAM Arbiter0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_SENSE_ACCESS_RAM_ARBITER0(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_SENSE_ACCESS_RAM_ARBITER0_SHIFT)) & CLKCTL1_PSCCTL1_CLR_SENSE_ACCESS_RAM_ARBITER0_MASK)

#define CLKCTL1_PSCCTL1_CLR_HIFI1_MASK           (0x2U)
#define CLKCTL1_PSCCTL1_CLR_HIFI1_SHIFT          (1U)
/*! HiFi1 - HiFi1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_HIFI1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_HIFI1_SHIFT)) & CLKCTL1_PSCCTL1_CLR_HIFI1_MASK)

#define CLKCTL1_PSCCTL1_CLR_EDMA2_MASK           (0x10U)
#define CLKCTL1_PSCCTL1_CLR_EDMA2_SHIFT          (4U)
/*! eDMA2 - eDMA2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_EDMA2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_EDMA2_SHIFT)) & CLKCTL1_PSCCTL1_CLR_EDMA2_MASK)

#define CLKCTL1_PSCCTL1_CLR_EDMA3_MASK           (0x20U)
#define CLKCTL1_PSCCTL1_CLR_EDMA3_SHIFT          (5U)
/*! eDMA3 - eDMA3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_EDMA3(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_EDMA3_SHIFT)) & CLKCTL1_PSCCTL1_CLR_EDMA3_MASK)

#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM17_MASK   (0x40U)
#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM17_SHIFT  (6U)
/*! LP_FLEXCOMM17 - LP_FLEXCOMM17 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM17(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM17_SHIFT)) & CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM17_MASK)

#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM18_MASK   (0x80U)
#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM18_SHIFT  (7U)
/*! LP_FLEXCOMM18 - LP_FLEXCOMM18 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM18(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM18_SHIFT)) & CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM18_MASK)

#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM19_MASK   (0x100U)
#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM19_SHIFT  (8U)
/*! LP_FLEXCOMM19 - LP_FLEXCOMM19 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM19(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM19_SHIFT)) & CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM19_MASK)

#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM20_MASK   (0x200U)
#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM20_SHIFT  (9U)
/*! LP_FLEXCOMM20 - LP_FLEXCOMM20 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM20(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM20_SHIFT)) & CLKCTL1_PSCCTL1_CLR_LP_FLEXCOMM20_MASK)

#define CLKCTL1_PSCCTL1_CLR_SAI3_MASK            (0x400U)
#define CLKCTL1_PSCCTL1_CLR_SAI3_SHIFT           (10U)
/*! SAI3 - SAI3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_SAI3(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_SAI3_SHIFT)) & CLKCTL1_PSCCTL1_CLR_SAI3_MASK)

#define CLKCTL1_PSCCTL1_CLR_I3C2_MASK            (0x800U)
#define CLKCTL1_PSCCTL1_CLR_I3C2_SHIFT           (11U)
/*! I3C2 - I3C2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_I3C2(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_I3C2_SHIFT)) & CLKCTL1_PSCCTL1_CLR_I3C2_MASK)

#define CLKCTL1_PSCCTL1_CLR_I3C3_MASK            (0x1000U)
#define CLKCTL1_PSCCTL1_CLR_I3C3_SHIFT           (12U)
/*! I3C3 - I3C3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_I3C3(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_I3C3_SHIFT)) & CLKCTL1_PSCCTL1_CLR_I3C3_MASK)

#define CLKCTL1_PSCCTL1_CLR_GPIO8_MASK           (0x2000U)
#define CLKCTL1_PSCCTL1_CLR_GPIO8_SHIFT          (13U)
/*! GPIO8 - GPIO8 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_GPIO8(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_GPIO8_SHIFT)) & CLKCTL1_PSCCTL1_CLR_GPIO8_MASK)

#define CLKCTL1_PSCCTL1_CLR_GPIO9_MASK           (0x4000U)
#define CLKCTL1_PSCCTL1_CLR_GPIO9_SHIFT          (14U)
/*! GPIO9 - GPIO9 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_GPIO9(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_GPIO9_SHIFT)) & CLKCTL1_PSCCTL1_CLR_GPIO9_MASK)

#define CLKCTL1_PSCCTL1_CLR_GPIO10_MASK          (0x8000U)
#define CLKCTL1_PSCCTL1_CLR_GPIO10_SHIFT         (15U)
/*! GPIO10 - GPIO10 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_GPIO10(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_GPIO10_SHIFT)) & CLKCTL1_PSCCTL1_CLR_GPIO10_MASK)

#define CLKCTL1_PSCCTL1_CLR_PINT1_MASK           (0x10000U)
#define CLKCTL1_PSCCTL1_CLR_PINT1_SHIFT          (16U)
/*! PINT1 - PINT1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_PINT1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_PINT1_SHIFT)) & CLKCTL1_PSCCTL1_CLR_PINT1_MASK)

#define CLKCTL1_PSCCTL1_CLR_CTIMER5_MASK         (0x20000U)
#define CLKCTL1_PSCCTL1_CLR_CTIMER5_SHIFT        (17U)
/*! CTIMER5 - CTIMER5 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_CTIMER5(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_CTIMER5_SHIFT)) & CLKCTL1_PSCCTL1_CLR_CTIMER5_MASK)

#define CLKCTL1_PSCCTL1_CLR_CTIMER6_MASK         (0x40000U)
#define CLKCTL1_PSCCTL1_CLR_CTIMER6_SHIFT        (18U)
/*! CTIMER6 - CTIMER6 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_CTIMER6(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_CTIMER6_SHIFT)) & CLKCTL1_PSCCTL1_CLR_CTIMER6_MASK)

#define CLKCTL1_PSCCTL1_CLR_CTIMER7_MASK         (0x80000U)
#define CLKCTL1_PSCCTL1_CLR_CTIMER7_SHIFT        (19U)
/*! CTIMER7 - CTIMER7 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_CTIMER7(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_CTIMER7_SHIFT)) & CLKCTL1_PSCCTL1_CLR_CTIMER7_MASK)

#define CLKCTL1_PSCCTL1_CLR_MRT1_MASK            (0x100000U)
#define CLKCTL1_PSCCTL1_CLR_MRT1_SHIFT           (20U)
/*! MRT1 - MRT1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_MRT1(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_MRT1_SHIFT)) & CLKCTL1_PSCCTL1_CLR_MRT1_MASK)

#define CLKCTL1_PSCCTL1_CLR_UTICK1_MASK          (0x200000U)
#define CLKCTL1_PSCCTL1_CLR_UTICK1_SHIFT         (21U)
/*! UTICK1 - UTICK1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_UTICK1(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_UTICK1_SHIFT)) & CLKCTL1_PSCCTL1_CLR_UTICK1_MASK)

#define CLKCTL1_PSCCTL1_CLR_CDOG3_MASK           (0x400000U)
#define CLKCTL1_PSCCTL1_CLR_CDOG3_SHIFT          (22U)
/*! CDOG3 - CDOG3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_CDOG3(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_CDOG3_SHIFT)) & CLKCTL1_PSCCTL1_CLR_CDOG3_MASK)

#define CLKCTL1_PSCCTL1_CLR_CDOG4_MASK           (0x800000U)
#define CLKCTL1_PSCCTL1_CLR_CDOG4_SHIFT          (23U)
/*! CDOG4 - CDOG4 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_CDOG4(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_CDOG4_SHIFT)) & CLKCTL1_PSCCTL1_CLR_CDOG4_MASK)

#define CLKCTL1_PSCCTL1_CLR_MU3_MASK             (0x1000000U)
#define CLKCTL1_PSCCTL1_CLR_MU3_SHIFT            (24U)
/*! MU3 - MU3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_MU3(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_MU3_SHIFT)) & CLKCTL1_PSCCTL1_CLR_MU3_MASK)

#define CLKCTL1_PSCCTL1_CLR_SEMA42_3_MASK        (0x2000000U)
#define CLKCTL1_PSCCTL1_CLR_SEMA42_3_SHIFT       (25U)
/*! SEMA42_3 - SEMA42_3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_SEMA42_3(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_SEMA42_3_SHIFT)) & CLKCTL1_PSCCTL1_CLR_SEMA42_3_MASK)

#define CLKCTL1_PSCCTL1_CLR_WWDT2_MASK           (0x4000000U)
#define CLKCTL1_PSCCTL1_CLR_WWDT2_SHIFT          (26U)
/*! WWDT2 - WWDT2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_WWDT2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_WWDT2_SHIFT)) & CLKCTL1_PSCCTL1_CLR_WWDT2_MASK)

#define CLKCTL1_PSCCTL1_CLR_WWDT3_MASK           (0x8000000U)
#define CLKCTL1_PSCCTL1_CLR_WWDT3_SHIFT          (27U)
/*! WWDT3 - WWDT3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_WWDT3(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_WWDT3_SHIFT)) & CLKCTL1_PSCCTL1_CLR_WWDT3_MASK)

#define CLKCTL1_PSCCTL1_CLR_INPUTMUX1_MASK       (0x40000000U)
#define CLKCTL1_PSCCTL1_CLR_INPUTMUX1_SHIFT      (30U)
/*! INPUTMUX1 - INPUTMUX1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL1_PSCCTL1_CLR_INPUTMUX1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_PSCCTL1_CLR_INPUTMUX1_SHIFT)) & CLKCTL1_PSCCTL1_CLR_INPUTMUX1_MASK)
/*! @} */

/*! @name SENSEBASECLKSEL - VDD1_SENSE Base Clock Select Source */
/*! @{ */

#define CLKCTL1_SENSEBASECLKSEL_SEL_MASK         (0x3U)
#define CLKCTL1_SENSEBASECLKSEL_SEL_SHIFT        (0U)
/*! SEL - Clock Source Select for Main VDD1_SENSE Base Clock
 *  0b00..fro1_div3
 *  0b01..fro1_max
 *  0b10..fro2_div3
 *  0b11..1m_lposc
 */
#define CLKCTL1_SENSEBASECLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SENSEBASECLKSEL_SEL_SHIFT)) & CLKCTL1_SENSEBASECLKSEL_SEL_MASK)
/*! @} */

/*! @name SENSEDSPCPUCLKDIV - CPU Clock of DSP in VDD1_SENSE Clock Divider */
/*! @{ */

#define CLKCTL1_SENSEDSPCPUCLKDIV_DIV_MASK       (0xFFU)
#define CLKCTL1_SENSEDSPCPUCLKDIV_DIV_SHIFT      (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL1_SENSEDSPCPUCLKDIV_DIV(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SENSEDSPCPUCLKDIV_DIV_SHIFT)) & CLKCTL1_SENSEDSPCPUCLKDIV_DIV_MASK)

#define CLKCTL1_SENSEDSPCPUCLKDIV_BUSY_MASK      (0x10000000U)
#define CLKCTL1_SENSEDSPCPUCLKDIV_BUSY_SHIFT     (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL1_SENSEDSPCPUCLKDIV_BUSY(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SENSEDSPCPUCLKDIV_BUSY_SHIFT)) & CLKCTL1_SENSEDSPCPUCLKDIV_BUSY_MASK)

#define CLKCTL1_SENSEDSPCPUCLKDIV_REQFLAG_MASK   (0x80000000U)
#define CLKCTL1_SENSEDSPCPUCLKDIV_REQFLAG_SHIFT  (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL1_SENSEDSPCPUCLKDIV_REQFLAG(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SENSEDSPCPUCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_SENSEDSPCPUCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SENSEDSPCPUCLKSEL - CPU Clock of DSP in VDD1_SENSE Clock Select */
/*! @{ */

#define CLKCTL1_SENSEDSPCPUCLKSEL_SEL_MASK       (0x3U)
#define CLKCTL1_SENSEDSPCPUCLKSEL_SEL_SHIFT      (0U)
/*! SEL - Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..fro2_max
 *  0b10..audio_pll_pfd1
 *  0b11..fro1_max
 */
#define CLKCTL1_SENSEDSPCPUCLKSEL_SEL(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SENSEDSPCPUCLKSEL_SEL_SHIFT)) & CLKCTL1_SENSEDSPCPUCLKSEL_SEL_MASK)

#define CLKCTL1_SENSEDSPCPUCLKSEL_SEL_EN_MASK    (0x4U)
#define CLKCTL1_SENSEDSPCPUCLKSEL_SEL_EN_SHIFT   (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL1_SENSEDSPCPUCLKSEL_SEL_EN(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SENSEDSPCPUCLKSEL_SEL_EN_SHIFT)) & CLKCTL1_SENSEDSPCPUCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SAI3FCLKSEL - SAI3 Clock Select Source */
/*! @{ */

#define CLKCTL1_SAI3FCLKSEL_SEL_MASK             (0x3U)
#define CLKCTL1_SAI3FCLKSEL_SEL_SHIFT            (0U)
/*! SEL - Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..fro2_div8
 *  0b10..fro2_max
 *  0b11..audio_clk
 */
#define CLKCTL1_SAI3FCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SAI3FCLKSEL_SEL_SHIFT)) & CLKCTL1_SAI3FCLKSEL_SEL_MASK)

#define CLKCTL1_SAI3FCLKSEL_SEL_EN_MASK          (0x4U)
#define CLKCTL1_SAI3FCLKSEL_SEL_EN_SHIFT         (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL1_SAI3FCLKSEL_SEL_EN(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SAI3FCLKSEL_SEL_EN_SHIFT)) & CLKCTL1_SAI3FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SAI3CLKDIV - SAI3 Functional Clock Divider */
/*! @{ */

#define CLKCTL1_SAI3CLKDIV_DIV_MASK              (0xFFU)
#define CLKCTL1_SAI3CLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL1_SAI3CLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SAI3CLKDIV_DIV_SHIFT)) & CLKCTL1_SAI3CLKDIV_DIV_MASK)

#define CLKCTL1_SAI3CLKDIV_BUSY_MASK             (0x10000000U)
#define CLKCTL1_SAI3CLKDIV_BUSY_SHIFT            (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL1_SAI3CLKDIV_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SAI3CLKDIV_BUSY_SHIFT)) & CLKCTL1_SAI3CLKDIV_BUSY_MASK)

#define CLKCTL1_SAI3CLKDIV_RESET_MASK            (0x20000000U)
#define CLKCTL1_SAI3CLKDIV_RESET_SHIFT           (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL1_SAI3CLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SAI3CLKDIV_RESET_SHIFT)) & CLKCTL1_SAI3CLKDIV_RESET_MASK)

#define CLKCTL1_SAI3CLKDIV_HALT_MASK             (0x40000000U)
#define CLKCTL1_SAI3CLKDIV_HALT_SHIFT            (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL1_SAI3CLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SAI3CLKDIV_HALT_SHIFT)) & CLKCTL1_SAI3CLKDIV_HALT_MASK)

#define CLKCTL1_SAI3CLKDIV_REQFLAG_MASK          (0x80000000U)
#define CLKCTL1_SAI3CLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL1_SAI3CLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SAI3CLKDIV_REQFLAG_SHIFT)) & CLKCTL1_SAI3CLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name UTICK1FCLKSEL - UTICK1 Functional Clock Source Select */
/*! @{ */

#define CLKCTL1_UTICK1FCLKSEL_SEL_MASK           (0x3U)
#define CLKCTL1_UTICK1FCLKSEL_SEL_SHIFT          (0U)
/*! SEL - UTICK Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..1m_lposc
 *  0b10..fro2_max
 *  0b11..fro1_div2
 */
#define CLKCTL1_UTICK1FCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_UTICK1FCLKSEL_SEL_SHIFT)) & CLKCTL1_UTICK1FCLKSEL_SEL_MASK)

#define CLKCTL1_UTICK1FCLKSEL_SEL_EN_MASK        (0x4U)
#define CLKCTL1_UTICK1FCLKSEL_SEL_EN_SHIFT       (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL1_UTICK1FCLKSEL_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_UTICK1FCLKSEL_SEL_EN_SHIFT)) & CLKCTL1_UTICK1FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name UTICK1CLKDIV - UTICK1 Functional Clock Divider */
/*! @{ */

#define CLKCTL1_UTICK1CLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_UTICK1CLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL1_UTICK1CLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_UTICK1CLKDIV_DIV_SHIFT)) & CLKCTL1_UTICK1CLKDIV_DIV_MASK)

#define CLKCTL1_UTICK1CLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL1_UTICK1CLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL1_UTICK1CLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_UTICK1CLKDIV_BUSY_SHIFT)) & CLKCTL1_UTICK1CLKDIV_BUSY_MASK)

#define CLKCTL1_UTICK1CLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_UTICK1CLKDIV_RESET_SHIFT         (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL1_UTICK1CLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_UTICK1CLKDIV_RESET_SHIFT)) & CLKCTL1_UTICK1CLKDIV_RESET_MASK)

#define CLKCTL1_UTICK1CLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_UTICK1CLKDIV_HALT_SHIFT          (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL1_UTICK1CLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_UTICK1CLKDIV_HALT_SHIFT)) & CLKCTL1_UTICK1CLKDIV_HALT_MASK)

#define CLKCTL1_UTICK1CLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_UTICK1CLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL1_UTICK1CLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_UTICK1CLKDIV_REQFLAG_SHIFT)) & CLKCTL1_UTICK1CLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name WWDT2FCLKSEL - WWDT2 Functional Clock Source Select */
/*! @{ */

#define CLKCTL1_WWDT2FCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL1_WWDT2FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Clock Source Select
 *  0b00..1m_lposc
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CLKCTL1_WWDT2FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_WWDT2FCLKSEL_SEL_SHIFT)) & CLKCTL1_WWDT2FCLKSEL_SEL_MASK)

#define CLKCTL1_WWDT2FCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL1_WWDT2FCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Enable Clock Mux Output
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL1_WWDT2FCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_WWDT2FCLKSEL_SEL_EN_SHIFT)) & CLKCTL1_WWDT2FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name WWDT3FCLKSEL - WWDT3 Functional Clock Source Select */
/*! @{ */

#define CLKCTL1_WWDT3FCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL1_WWDT3FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Clock Source Select
 *  0b00..1m_lposc
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CLKCTL1_WWDT3FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_WWDT3FCLKSEL_SEL_SHIFT)) & CLKCTL1_WWDT3FCLKSEL_SEL_MASK)

#define CLKCTL1_WWDT3FCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL1_WWDT3FCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL1_WWDT3FCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_WWDT3FCLKSEL_SEL_EN_SHIFT)) & CLKCTL1_WWDT3FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SYSTICKFCLKSEL - SYSTICK Functional Clock Select Source */
/*! @{ */

#define CLKCTL1_SYSTICKFCLKSEL_SEL_MASK          (0x3U)
#define CLKCTL1_SYSTICKFCLKSEL_SEL_SHIFT         (0U)
/*! SEL - Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..1m_lposc
 *  0b10..wake32k_clk (switch to other clock source before VDD1_SENSE enters into the Deep Sleep Retention mode.)
 *  0b11..osc_clk
 */
#define CLKCTL1_SYSTICKFCLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SYSTICKFCLKSEL_SEL_SHIFT)) & CLKCTL1_SYSTICKFCLKSEL_SEL_MASK)

#define CLKCTL1_SYSTICKFCLKSEL_SEL_EN_MASK       (0x4U)
#define CLKCTL1_SYSTICKFCLKSEL_SEL_EN_SHIFT      (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL1_SYSTICKFCLKSEL_SEL_EN(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SYSTICKFCLKSEL_SEL_EN_SHIFT)) & CLKCTL1_SYSTICKFCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SYSTICKFCLKDIV - SYSTICK Functional Clock Divider */
/*! @{ */

#define CLKCTL1_SYSTICKFCLKDIV_DIV_MASK          (0xFFU)
#define CLKCTL1_SYSTICKFCLKDIV_DIV_SHIFT         (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL1_SYSTICKFCLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SYSTICKFCLKDIV_DIV_SHIFT)) & CLKCTL1_SYSTICKFCLKDIV_DIV_MASK)

#define CLKCTL1_SYSTICKFCLKDIV_BUSY_MASK         (0x10000000U)
#define CLKCTL1_SYSTICKFCLKDIV_BUSY_SHIFT        (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL1_SYSTICKFCLKDIV_BUSY(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SYSTICKFCLKDIV_BUSY_SHIFT)) & CLKCTL1_SYSTICKFCLKDIV_BUSY_MASK)

#define CLKCTL1_SYSTICKFCLKDIV_RESET_MASK        (0x20000000U)
#define CLKCTL1_SYSTICKFCLKDIV_RESET_SHIFT       (29U)
/*! RESET - Systick Clock Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL1_SYSTICKFCLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SYSTICKFCLKDIV_RESET_SHIFT)) & CLKCTL1_SYSTICKFCLKDIV_RESET_MASK)

#define CLKCTL1_SYSTICKFCLKDIV_HALT_MASK         (0x40000000U)
#define CLKCTL1_SYSTICKFCLKDIV_HALT_SHIFT        (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL1_SYSTICKFCLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SYSTICKFCLKDIV_HALT_SHIFT)) & CLKCTL1_SYSTICKFCLKDIV_HALT_MASK)

#define CLKCTL1_SYSTICKFCLKDIV_REQFLAG_MASK      (0x80000000U)
#define CLKCTL1_SYSTICKFCLKDIV_REQFLAG_SHIFT     (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL1_SYSTICKFCLKDIV_REQFLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL1_SYSTICKFCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_SYSTICKFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CTIMERFCLKSEL - CTIMER5 Functional Clock Source Select..CTIMER7 Functional Clock Source Select */
/*! @{ */

#define CLKCTL1_CTIMERFCLKSEL_SEL_MASK           (0x3U)
#define CLKCTL1_CTIMERFCLKSEL_SEL_SHIFT          (0U)
/*! SEL - CTIMER7 Functional Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..audio_clk
 *  0b10..fro2_max
 *  0b11..wake32k_clk
 */
#define CLKCTL1_CTIMERFCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CTIMERFCLKSEL_SEL_SHIFT)) & CLKCTL1_CTIMERFCLKSEL_SEL_MASK)

#define CLKCTL1_CTIMERFCLKSEL_SEL_EN_MASK        (0x4U)
#define CLKCTL1_CTIMERFCLKSEL_SEL_EN_SHIFT       (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL1_CTIMERFCLKSEL_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CTIMERFCLKSEL_SEL_EN_SHIFT)) & CLKCTL1_CTIMERFCLKSEL_SEL_EN_MASK)
/*! @} */

/* The count of CLKCTL1_CTIMERFCLKSEL */
#define CLKCTL1_CTIMERFCLKSEL_COUNT              (3U)

/*! @name CTIMERCLKDIV - CTIMER5 Functional Clock Divider..CTIMER7 Functional Clock Divider */
/*! @{ */

#define CLKCTL1_CTIMERCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_CTIMERCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL1_CTIMERCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CTIMERCLKDIV_DIV_SHIFT)) & CLKCTL1_CTIMERCLKDIV_DIV_MASK)

#define CLKCTL1_CTIMERCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL1_CTIMERCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL1_CTIMERCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CTIMERCLKDIV_BUSY_SHIFT)) & CLKCTL1_CTIMERCLKDIV_BUSY_MASK)

#define CLKCTL1_CTIMERCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_CTIMERCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL1_CTIMERCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CTIMERCLKDIV_RESET_SHIFT)) & CLKCTL1_CTIMERCLKDIV_RESET_MASK)

#define CLKCTL1_CTIMERCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_CTIMERCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL1_CTIMERCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CTIMERCLKDIV_HALT_SHIFT)) & CLKCTL1_CTIMERCLKDIV_HALT_MASK)

#define CLKCTL1_CTIMERCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_CTIMERCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL1_CTIMERCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_CTIMERCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_CTIMERCLKDIV_REQFLAG_MASK)
/*! @} */

/* The count of CLKCTL1_CTIMERCLKDIV */
#define CLKCTL1_CTIMERCLKDIV_COUNT               (3U)

/*! @name I3C23FCLKSEL - I3C2 and I3C3 Functional Clock Source Select */
/*! @{ */

#define CLKCTL1_I3C23FCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL1_I3C23FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - I3C2 and I3C3 Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..fro2_max
 *  0b10..fro1_div8
 *  0b11..osc_clk
 */
#define CLKCTL1_I3C23FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C23FCLKSEL_SEL_SHIFT)) & CLKCTL1_I3C23FCLKSEL_SEL_MASK)

#define CLKCTL1_I3C23FCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL1_I3C23FCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL1_I3C23FCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C23FCLKSEL_SEL_EN_SHIFT)) & CLKCTL1_I3C23FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name I3C23FCLKDIV - I3C2 and I3C3 Functional Clock Divider */
/*! @{ */

#define CLKCTL1_I3C23FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL1_I3C23FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - I3C2 and I3C3 Clock Divider Value */
#define CLKCTL1_I3C23FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C23FCLKDIV_DIV_SHIFT)) & CLKCTL1_I3C23FCLKDIV_DIV_MASK)

#define CLKCTL1_I3C23FCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL1_I3C23FCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL1_I3C23FCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C23FCLKDIV_BUSY_SHIFT)) & CLKCTL1_I3C23FCLKDIV_BUSY_MASK)

#define CLKCTL1_I3C23FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL1_I3C23FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL1_I3C23FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C23FCLKDIV_RESET_SHIFT)) & CLKCTL1_I3C23FCLKDIV_RESET_MASK)

#define CLKCTL1_I3C23FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL1_I3C23FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL1_I3C23FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C23FCLKDIV_HALT_SHIFT)) & CLKCTL1_I3C23FCLKDIV_HALT_MASK)

#define CLKCTL1_I3C23FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL1_I3C23FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The Divider change has been finished (The clock to be divided must be running for this status to change).
 *  0b1..The divider value is being changed.
 */
#define CLKCTL1_I3C23FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL1_I3C23FCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_I3C23FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name FCFCLKSEL - LP_FLEXCOMM17 Clock Source Select..LP_FLEXCOMM20 Clock Source Select */
/*! @{ */

#define CLKCTL1_FCFCLKSEL_SEL_MASK               (0x3U)
#define CLKCTL1_FCFCLKSEL_SEL_SHIFT              (0U)
/*! SEL - LP_FLEXCOMM20 Clock Source Select
 *  0b00..baseclk_sense
 *  0b01..fro2_max
 *  0b10..fro1_max
 *  0b11..wake32k_clk
 */
#define CLKCTL1_FCFCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FCFCLKSEL_SEL_SHIFT)) & CLKCTL1_FCFCLKSEL_SEL_MASK)

#define CLKCTL1_FCFCLKSEL_SEL_EN_MASK            (0x4U)
#define CLKCTL1_FCFCLKSEL_SEL_EN_SHIFT           (2U)
/*! SEL_EN - Clock MUX Output Enable
 *  0b0..Output of clkmux is gated.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL1_FCFCLKSEL_SEL_EN(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FCFCLKSEL_SEL_EN_SHIFT)) & CLKCTL1_FCFCLKSEL_SEL_EN_MASK)
/*! @} */

/* The count of CLKCTL1_FCFCLKSEL */
#define CLKCTL1_FCFCLKSEL_COUNT                  (4U)

/*! @name FCFCLKDIV - LP_FLEXCOMM17 Clock Divider..LP_FLEXCOMM20 Clock Divider */
/*! @{ */

#define CLKCTL1_FCFCLKDIV_DIV_MASK               (0xFFU)
#define CLKCTL1_FCFCLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL1_FCFCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FCFCLKDIV_DIV_SHIFT)) & CLKCTL1_FCFCLKDIV_DIV_MASK)

#define CLKCTL1_FCFCLKDIV_BUSY_MASK              (0x10000000U)
#define CLKCTL1_FCFCLKDIV_BUSY_SHIFT             (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL1_FCFCLKDIV_BUSY(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FCFCLKDIV_BUSY_SHIFT)) & CLKCTL1_FCFCLKDIV_BUSY_MASK)

#define CLKCTL1_FCFCLKDIV_RESET_MASK             (0x20000000U)
#define CLKCTL1_FCFCLKDIV_RESET_SHIFT            (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL1_FCFCLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FCFCLKDIV_RESET_SHIFT)) & CLKCTL1_FCFCLKDIV_RESET_MASK)

#define CLKCTL1_FCFCLKDIV_HALT_MASK              (0x40000000U)
#define CLKCTL1_FCFCLKDIV_HALT_SHIFT             (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL1_FCFCLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FCFCLKDIV_HALT_SHIFT)) & CLKCTL1_FCFCLKDIV_HALT_MASK)

#define CLKCTL1_FCFCLKDIV_REQFLAG_MASK           (0x80000000U)
#define CLKCTL1_FCFCLKDIV_REQFLAG_SHIFT          (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished
 *  0b1..A change is being made to the divider value
 */
#define CLKCTL1_FCFCLKDIV_REQFLAG(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL1_FCFCLKDIV_REQFLAG_SHIFT)) & CLKCTL1_FCFCLKDIV_REQFLAG_MASK)
/*! @} */

/* The count of CLKCTL1_FCFCLKDIV */
#define CLKCTL1_FCFCLKDIV_COUNT                  (4U)

/*! @name AUDIOVDD1CLKSEL - VDD1_SENSE Audio Clock Source */
/*! @{ */

#define CLKCTL1_AUDIOVDD1CLKSEL_SEL_MASK         (0x3U)
#define CLKCTL1_AUDIOVDD1CLKSEL_SEL_SHIFT        (0U)
/*! SEL - Clock Source Select
 *  0b00..mclk_in
 *  0b01..osc_clk
 *  0b10..fro2_div8
 *  0b11..audio_pll_pfd3
 */
#define CLKCTL1_AUDIOVDD1CLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL1_AUDIOVDD1CLKSEL_SEL_SHIFT)) & CLKCTL1_AUDIOVDD1CLKSEL_SEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CLKCTL1_Register_Masks */


/*!
 * @}
 */ /* end of group CLKCTL1_Peripheral_Access_Layer */


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


#endif  /* PERI_CLKCTL1_H_ */

