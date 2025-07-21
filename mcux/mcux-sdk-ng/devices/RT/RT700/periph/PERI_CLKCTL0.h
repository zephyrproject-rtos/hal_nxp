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
**         CMSIS Peripheral Access Layer for CLKCTL0
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
 * @file PERI_CLKCTL0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CLKCTL0
 *
 * CMSIS Peripheral Access Layer for CLKCTL0
 */

#if !defined(PERI_CLKCTL0_H_)
#define PERI_CLKCTL0_H_                          /**< Symbol preventing repeated inclusion */

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
   -- CLKCTL0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL0_Peripheral_Access_Layer CLKCTL0 Peripheral Access Layer
 * @{
 */

/** CLKCTL0 - Size of Registers Arrays */
#define CLKCTL0_FLEXCOMM_COUNT                    14u
#define CLKCTL0_CTIMER_COUNT                      5u
#define CLKCTL0_CTIMERNFCLKSEL_COUNT              5u

/** CLKCTL0 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t PSCCTL0;                           /**< VDD2_COMP Peripheral Clock Control 0, offset: 0x10 */
  __IO uint32_t PSCCTL1;                           /**< VDD2_COMP Peripheral Clock Control 1, offset: 0x14 */
  __IO uint32_t PSCCTL2;                           /**< VDD2_COMP Peripheral Clock Control 2, offset: 0x18 */
  __IO uint32_t PSCCTL3;                           /**< VDD2_COMP Peripheral Clock Control 3, offset: 0x1C */
  __IO uint32_t PSCCTL4;                           /**< VDD2_COMP Peripheral Clock Control 4, offset: 0x20 */
  __IO uint32_t PSCCTL5;                           /**< VDD2_COMP Peripheral Clock Control 5, offset: 0x24 */
       uint8_t RESERVED_1[24];
  __IO uint32_t PSCCTL0_SET;                       /**< VDD2_COMP Peripheral Clock Control 0 Set, offset: 0x40 */
  __IO uint32_t PSCCTL1_SET;                       /**< VDD2_COMP Peripheral Clock Control 1 Set, offset: 0x44 */
  __IO uint32_t PSCCTL2_SET;                       /**< VDD2_COMP Peripheral Clock Control 2 Set, offset: 0x48 */
  __IO uint32_t PSCCTL3_SET;                       /**< VDD2_COMP Peripheral Clock Control 3 Set, offset: 0x4C */
  __IO uint32_t PSCCTL4_SET;                       /**< VDD2_COMP Peripheral Clock Control 4 Set, offset: 0x50 */
  __IO uint32_t PSCCTL5_SET;                       /**< VDD2_COMP Peripheral Clock Control 5 Set, offset: 0x54 */
       uint8_t RESERVED_2[24];
  __IO uint32_t PSCCTL0_CLR;                       /**< VDD2_COMP Peripheral Clock Control 0 Clear, offset: 0x70 */
  __IO uint32_t PSCCTL1_CLR;                       /**< VDD2_COMP Peripheral Clock Control 1 Clear, offset: 0x74 */
  __IO uint32_t PSCCTL2_CLR;                       /**< VDD2_COMP Peripheral Clock Control 2 Clear, offset: 0x78 */
  __IO uint32_t PSCCTL3_CLR;                       /**< VDD2_COMP Peripheral Clock Control 3 Clear, offset: 0x7C */
  __IO uint32_t PSCCTL4_CLR;                       /**< VDD2_COMP Peripheral Clock Control 4 Clear, offset: 0x80 */
  __IO uint32_t PSCCTL5_CLR;                       /**< VDD2_COMP Peripheral Clock Control 5 Clear, offset: 0x84 */
       uint8_t RESERVED_3[8];
  __IO uint32_t ONE_SRC_CLKSLICE_ENABLE;           /**< One Source Clock Slice Enable, offset: 0x90 */
       uint8_t RESERVED_4[132];
  __I  uint32_t FRO01CLKSTATUS;                    /**< FRO_TUNER0 and FRO_TUNER1 Clock Status, offset: 0x118 */
       uint8_t RESERVED_5[12];
  __IO uint32_t FRO0MAXDOMAINEN;                   /**< FRO0MAX Clock Domain Enable, offset: 0x128 */
       uint8_t RESERVED_6[724];
  __IO uint32_t MAINCLKDIV;                        /**< VDD2_COMP Main Clock Divider, offset: 0x400 */
       uint8_t RESERVED_7[28];
  __IO uint32_t CMPTBASECLKSEL;                    /**< VDD2_COMP Base Clock Select Source, offset: 0x420 */
  __IO uint32_t DSPBASECLKSEL;                     /**< VDD2_DSP Base Clock Select Source, offset: 0x424 */
  __IO uint32_t VDD2COMBASECLKSEL;                 /**< VDD2_COM Base Clock Select Source, offset: 0x428 */
       uint8_t RESERVED_8[8];
  __IO uint32_t MAINCLKSEL;                        /**< VDD2_COMP Main Clock Source Select, offset: 0x434 */
       uint8_t RESERVED_9[8];
  __IO uint32_t DSPCPUCLKDIV;                      /**< VDD2_DSP Clock Divider, offset: 0x440 */
  __IO uint32_t DSPCPUCLKSEL;                      /**< VDD2_DSP Clock Select Source, offset: 0x444 */
       uint8_t RESERVED_10[8];
  __IO uint32_t RAMCLKSEL;                         /**< RAM Clock Select Source, offset: 0x450 */
       uint8_t RESERVED_11[8];
  __IO uint32_t RAMCLKDIV;                         /**< RAM Clock Divider, offset: 0x45C */
       uint8_t RESERVED_12[256];
  __IO uint32_t TPIUFCLKSEL;                       /**< TPIU (TRACE_RT700) Functional Clock Select Source, offset: 0x560 */
  __IO uint32_t TPIUCLKDIV;                        /**< TPIU (TRACE_RT700) Functional Clock Divider, offset: 0x564 */
       uint8_t RESERVED_13[152];
  __IO uint32_t XSPI0FCLKSEL;                      /**< XSPI0 Functional Clock Source Select, offset: 0x600 */
  __IO uint32_t XSPI0FCLKDIV;                      /**< XSPI0 Functional Clock Divider, offset: 0x604 */
       uint8_t RESERVED_14[24];
  __IO uint32_t XSPI1FCLKSEL;                      /**< XSPI1 Functional Clock Select Source, offset: 0x620 */
  __IO uint32_t XSPI1FCLKDIV;                      /**< XSPI1 Functional Clock Divider, offset: 0x624 */
       uint8_t RESERVED_15[24];
  __IO uint32_t SCTFCLKSEL;                        /**< SCT Functional Clock Source Select, offset: 0x640 */
  __IO uint32_t SCTFCLKDIV;                        /**< SCT Functional Clock Divider, offset: 0x644 */
       uint8_t RESERVED_16[184];
  __IO uint32_t UTICK0FCLKSEL;                     /**< UTICK0 Functional Clock Select Source, offset: 0x700 */
  __IO uint32_t UTICK0FCLKDIV;                     /**< UTICK0 Functional Clock Divider, offset: 0x704 */
       uint8_t RESERVED_17[24];
  __IO uint32_t WWDT0FCLKSEL;                      /**< WWDT0 Functional Clock Source Select, offset: 0x720 */
       uint8_t RESERVED_18[28];
  __IO uint32_t WWDT1FCLKSEL;                      /**< WWDT1 Functional Clock Source Select, offset: 0x740 */
       uint8_t RESERVED_19[28];
  __IO uint32_t SYSTICKFCLKSEL;                    /**< SYSTICK Functional Clock Source Select, offset: 0x760 */
  __IO uint32_t SYSTICKFCLKDIV;                    /**< SYSTICK Functional Clock Divider, offset: 0x764 */
       uint8_t RESERVED_20[152];
  struct {                                         /* offset: 0x800, array step: 0x20 */
    __IO uint32_t FCCLKSEL;                          /**< LP_FLEXCOMM 0 to 13 Clock Source 0 Select..LP_FLEXCOMM 0 to 13 Clock Source 3 Select, array offset: 0x800, array step: 0x20, valid indices: [0-3] */
    __IO uint32_t FCCLKDIV;                          /**< LP_FLEXCOMM 0 to 13 Clock Source 0 Divider..LP_FLEXCOMM 0 to 13 Clock Source 3 Divider, array offset: 0x804, array step: 0x20, valid indices: [0-3] */
    __IO uint32_t FCFCLKSEL;                         /**< LP_FLEXCOMM0 Clock Source Select..LP_FLEXCOMM13 Clock Source Select, array offset: 0x808, array step: 0x20 */
         uint8_t RESERVED_0[20];
  } FLEXCOMM[CLKCTL0_FLEXCOMM_COUNT];
       uint8_t RESERVED_21[8];
  __IO uint32_t SAI012FCLKSEL;                     /**< SAI0, SAI1 and SAI2 Clock Source Select, offset: 0x9C8 */
  __IO uint32_t SAI012CLKDIV;                      /**< SAI0, SAI1 and SAI2 Functional Clock Divider, offset: 0x9CC */
       uint8_t RESERVED_22[48];
  __IO uint32_t CTIMERCLKDIV[CLKCTL0_CTIMER_COUNT]; /**< CTIMER0 Functional Clock Divider..CTIMER4 Functional Clock Divider, array offset: 0xA00, array step: 0x4 */
       uint8_t RESERVED_23[140];
  __IO uint32_t CTIMERFCLKSEL[CLKCTL0_CTIMERNFCLKSEL_COUNT]; /**< CTIMER0 Functional Clock Source Select..CTIMER4 Functional Clock Source Select, array offset: 0xAA0, array step: 0x4 */
       uint8_t RESERVED_24[12];
  __IO uint32_t TRNGFCLKSEL;                       /**< TRNG Functional Clock Source Select, offset: 0xAC0 */
  __IO uint32_t TRNGFCLKDIV;                       /**< TRNG FCLK Clock Divider, offset: 0xAC4 */
       uint8_t RESERVED_25[56];
  __IO uint32_t I3C01FCLKSEL;                      /**< I3C0 and I3C1 Functional Clock Source Select, offset: 0xB00 */
  __IO uint32_t I3C01PCLKSEL;                      /**< I3C0 and I3C1 P-CLK Source Select, offset: 0xB04 */
  __IO uint32_t I3C01PCLKDIV;                      /**< I3C0 and I3C1 P-CLK Divider, offset: 0xB08 */
       uint8_t RESERVED_26[4];
  __IO uint32_t I3C01FCLKDIV;                      /**< I3C0 and I3C1 Functional Clock Divider, offset: 0xB10 */
       uint8_t RESERVED_27[12];
  __IO uint32_t CLKOUTCLKSEL;                      /**< CLKOUT_VDD2 Clock Select Source, offset: 0xB20 */
  __IO uint32_t CLKOUTCLKDIV;                      /**< CLKOUT_VDD2 Clock Divider, offset: 0xB24 */
       uint8_t RESERVED_28[8];
  __IO uint32_t AUDIOVDD2CLKSEL;                   /**< VDD2_COMP Audio Clock Source Select, offset: 0xB30 */
} CLKCTL0_Type;

/* ----------------------------------------------------------------------------
   -- CLKCTL0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL0_Register_Masks CLKCTL0 Register Masks
 * @{
 */

/*! @name PSCCTL0 - VDD2_COMP Peripheral Clock Control 0 */
/*! @{ */

#define CLKCTL0_PSCCTL0_CODE_CACHE_MASK          (0x2U)
#define CLKCTL0_PSCCTL0_CODE_CACHE_SHIFT         (1U)
/*! CODE_CACHE - Code Cache Clock (XCACHE 1)
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_CODE_CACHE(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CODE_CACHE_SHIFT)) & CLKCTL0_PSCCTL0_CODE_CACHE_MASK)

#define CLKCTL0_PSCCTL0_SYSTEM_CACHE_MASK        (0x4U)
#define CLKCTL0_PSCCTL0_SYSTEM_CACHE_SHIFT       (2U)
/*! SYSTEM_CACHE - System Cache Clock (XCACHE 0)
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_SYSTEM_CACHE(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SYSTEM_CACHE_SHIFT)) & CLKCTL0_PSCCTL0_SYSTEM_CACHE_MASK)

#define CLKCTL0_PSCCTL0_VDD2_OTP0_MASK           (0x20U)
#define CLKCTL0_PSCCTL0_VDD2_OTP0_SHIFT          (5U)
/*! VDD2_OTP0 - VDD2_OTP_CTRL0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_VDD2_OTP0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_VDD2_OTP0_SHIFT)) & CLKCTL0_PSCCTL0_VDD2_OTP0_MASK)

#define CLKCTL0_PSCCTL0_SLEEPCON0_MASK           (0x1000U)
#define CLKCTL0_PSCCTL0_SLEEPCON0_SHIFT          (12U)
/*! SLEEPCON0 - SLEEPCON0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_SLEEPCON0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SLEEPCON0_SHIFT)) & CLKCTL0_PSCCTL0_SLEEPCON0_MASK)

#define CLKCTL0_PSCCTL0_SYSCON0_MASK             (0x2000U)
#define CLKCTL0_PSCCTL0_SYSCON0_SHIFT            (13U)
/*! SYSCON0 - SYSCON0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_SYSCON0(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SYSCON0_SHIFT)) & CLKCTL0_PSCCTL0_SYSCON0_MASK)

#define CLKCTL0_PSCCTL0_GLIKEY0_MASK             (0x4000U)
#define CLKCTL0_PSCCTL0_GLIKEY0_SHIFT            (14U)
/*! GLIKEY0 - GLIKEY0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_GLIKEY0(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_GLIKEY0_SHIFT)) & CLKCTL0_PSCCTL0_GLIKEY0_MASK)

#define CLKCTL0_PSCCTL0_GLIKEY3_MASK             (0x8000U)
#define CLKCTL0_PSCCTL0_GLIKEY3_SHIFT            (15U)
/*! GLIKEY3 - GLIKEY3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_GLIKEY3(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_GLIKEY3_SHIFT)) & CLKCTL0_PSCCTL0_GLIKEY3_MASK)
/*! @} */

/*! @name PSCCTL1 - VDD2_COMP Peripheral Clock Control 1 */
/*! @{ */

#define CLKCTL0_PSCCTL1_TPIU_TRACE_CLKIN_MASK    (0x4U)
#define CLKCTL0_PSCCTL1_TPIU_TRACE_CLKIN_SHIFT   (2U)
/*! TPIU_TRACE_CLKIN - TPIU_TRACE_CLKIN (TRACE_RT700) Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_TPIU_TRACE_CLKIN(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_TPIU_TRACE_CLKIN_SHIFT)) & CLKCTL0_PSCCTL1_TPIU_TRACE_CLKIN_MASK)

#define CLKCTL0_PSCCTL1_SWO_TRACECLKIN_MASK      (0x8U)
#define CLKCTL0_PSCCTL1_SWO_TRACECLKIN_SHIFT     (3U)
/*! SWO_TRACECLKIN - SWO_TRACECLKIN (TRACE_RT700) Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SWO_TRACECLKIN(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SWO_TRACECLKIN_SHIFT)) & CLKCTL0_PSCCTL1_SWO_TRACECLKIN_MASK)

#define CLKCTL0_PSCCTL1_TSCLK_MASK               (0x10U)
#define CLKCTL0_PSCCTL1_TSCLK_SHIFT              (4U)
/*! TSCLK - TS (TRACE_RT700) Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_TSCLK(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_TSCLK_SHIFT)) & CLKCTL0_PSCCTL1_TSCLK_MASK)

#define CLKCTL0_PSCCTL1_EDMA0_MASK               (0x20U)
#define CLKCTL0_PSCCTL1_EDMA0_SHIFT              (5U)
/*! eDMA0 - eDMA0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_EDMA0(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_EDMA0_SHIFT)) & CLKCTL0_PSCCTL1_EDMA0_MASK)

#define CLKCTL0_PSCCTL1_EDMA1_MASK               (0x40U)
#define CLKCTL0_PSCCTL1_EDMA1_SHIFT              (6U)
/*! eDMA1 - eDMA1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_EDMA1(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_EDMA1_SHIFT)) & CLKCTL0_PSCCTL1_EDMA1_MASK)

#define CLKCTL0_PSCCTL1_PKC_RAM_CTRL_MASK        (0x80U)
#define CLKCTL0_PSCCTL1_PKC_RAM_CTRL_SHIFT       (7U)
/*! PKC_RAM_CTRl - RAM Control Clock of PKC
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_PKC_RAM_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_PKC_RAM_CTRL_SHIFT)) & CLKCTL0_PSCCTL1_PKC_RAM_CTRL_MASK)

#define CLKCTL0_PSCCTL1_PKC_MASK                 (0x100U)
#define CLKCTL0_PSCCTL1_PKC_SHIFT                (8U)
/*! PKC - PKC Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_PKC(x)                   (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_PKC_SHIFT)) & CLKCTL0_PSCCTL1_PKC_MASK)

#define CLKCTL0_PSCCTL1_ROMCP_MASK               (0x200U)
#define CLKCTL0_PSCCTL1_ROMCP_SHIFT              (9U)
/*! ROMCP - ROMCP Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_ROMCP(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_ROMCP_SHIFT)) & CLKCTL0_PSCCTL1_ROMCP_MASK)

#define CLKCTL0_PSCCTL1_XSPI0_MASK               (0x400U)
#define CLKCTL0_PSCCTL1_XSPI0_SHIFT              (10U)
/*! XSPI0 - XSPI0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_XSPI0(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_XSPI0_SHIFT)) & CLKCTL0_PSCCTL1_XSPI0_MASK)

#define CLKCTL0_PSCCTL1_XSPI1_MASK               (0x800U)
#define CLKCTL0_PSCCTL1_XSPI1_SHIFT              (11U)
/*! XSPI1 - XSPI1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_XSPI1(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_XSPI1_SHIFT)) & CLKCTL0_PSCCTL1_XSPI1_MASK)

#define CLKCTL0_PSCCTL1_CACHE64_0_MASK           (0x1000U)
#define CLKCTL0_PSCCTL1_CACHE64_0_SHIFT          (12U)
/*! CACHE64_0 - CACHE64_0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_CACHE64_0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CACHE64_0_SHIFT)) & CLKCTL0_PSCCTL1_CACHE64_0_MASK)

#define CLKCTL0_PSCCTL1_CACHE64_1_MASK           (0x2000U)
#define CLKCTL0_PSCCTL1_CACHE64_1_SHIFT          (13U)
/*! CACHE64_1 - CACHE64_1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_CACHE64_1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CACHE64_1_SHIFT)) & CLKCTL0_PSCCTL1_CACHE64_1_MASK)

#define CLKCTL0_PSCCTL1_QK_SUBSYS_MASK           (0x4000U)
#define CLKCTL0_PSCCTL1_QK_SUBSYS_SHIFT          (14U)
/*! QK_SUBSYS - QK SUBSYS (PUF_CTRL) Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_QK_SUBSYS(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_QK_SUBSYS_SHIFT)) & CLKCTL0_PSCCTL1_QK_SUBSYS_MASK)

#define CLKCTL0_PSCCTL1_MMU0_MASK                (0x10000U)
#define CLKCTL0_PSCCTL1_MMU0_SHIFT               (16U)
/*! MMU0 - MMU0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_MMU0(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_MMU0_SHIFT)) & CLKCTL0_PSCCTL1_MMU0_MASK)

#define CLKCTL0_PSCCTL1_MMU1_MASK                (0x20000U)
#define CLKCTL0_PSCCTL1_MMU1_SHIFT               (17U)
/*! MMU1 - MMU1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_MMU1(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_MMU1_SHIFT)) & CLKCTL0_PSCCTL1_MMU1_MASK)

#define CLKCTL0_PSCCTL1_GPIO0_MASK               (0x40000U)
#define CLKCTL0_PSCCTL1_GPIO0_SHIFT              (18U)
/*! GPIO0 - GPIO0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_GPIO0(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_GPIO0_SHIFT)) & CLKCTL0_PSCCTL1_GPIO0_MASK)

#define CLKCTL0_PSCCTL1_GPIO1_MASK               (0x80000U)
#define CLKCTL0_PSCCTL1_GPIO1_SHIFT              (19U)
/*! GPIO1 - GPIO1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_GPIO1(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_GPIO1_SHIFT)) & CLKCTL0_PSCCTL1_GPIO1_MASK)

#define CLKCTL0_PSCCTL1_GPIO2_MASK               (0x100000U)
#define CLKCTL0_PSCCTL1_GPIO2_SHIFT              (20U)
/*! GPIO2 - GPIO2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_GPIO2(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_GPIO2_SHIFT)) & CLKCTL0_PSCCTL1_GPIO2_MASK)

#define CLKCTL0_PSCCTL1_GPIO3_MASK               (0x200000U)
#define CLKCTL0_PSCCTL1_GPIO3_SHIFT              (21U)
/*! GPIO3 - GPIO3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_GPIO3(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_GPIO3_SHIFT)) & CLKCTL0_PSCCTL1_GPIO3_MASK)

#define CLKCTL0_PSCCTL1_GPIO4_MASK               (0x400000U)
#define CLKCTL0_PSCCTL1_GPIO4_SHIFT              (22U)
/*! GPIO4 - GPIO4 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_GPIO4(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_GPIO4_SHIFT)) & CLKCTL0_PSCCTL1_GPIO4_MASK)

#define CLKCTL0_PSCCTL1_GPIO5_MASK               (0x800000U)
#define CLKCTL0_PSCCTL1_GPIO5_SHIFT              (23U)
/*! GPIO5 - GPIO5 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_GPIO5(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_GPIO5_SHIFT)) & CLKCTL0_PSCCTL1_GPIO5_MASK)

#define CLKCTL0_PSCCTL1_GPIO6_MASK               (0x1000000U)
#define CLKCTL0_PSCCTL1_GPIO6_SHIFT              (24U)
/*! GPIO6 - GPIO6 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_GPIO6(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_GPIO6_SHIFT)) & CLKCTL0_PSCCTL1_GPIO6_MASK)

#define CLKCTL0_PSCCTL1_GPIO7_MASK               (0x2000000U)
#define CLKCTL0_PSCCTL1_GPIO7_SHIFT              (25U)
/*! GPIO7 - GPIO7 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_GPIO7(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_GPIO7_SHIFT)) & CLKCTL0_PSCCTL1_GPIO7_MASK)

#define CLKCTL0_PSCCTL1_SCT0_MASK                (0x4000000U)
#define CLKCTL0_PSCCTL1_SCT0_SHIFT               (26U)
/*! SCT0 - SCT0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SCT0(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SCT0_SHIFT)) & CLKCTL0_PSCCTL1_SCT0_MASK)

#define CLKCTL0_PSCCTL1_CDOG0_MASK               (0x8000000U)
#define CLKCTL0_PSCCTL1_CDOG0_SHIFT              (27U)
/*! CDOG0 - CDOG0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_CDOG0(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CDOG0_SHIFT)) & CLKCTL0_PSCCTL1_CDOG0_MASK)

#define CLKCTL0_PSCCTL1_CDOG1_MASK               (0x10000000U)
#define CLKCTL0_PSCCTL1_CDOG1_SHIFT              (28U)
/*! CDOG1 - CDOG1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_CDOG1(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CDOG1_SHIFT)) & CLKCTL0_PSCCTL1_CDOG1_MASK)

#define CLKCTL0_PSCCTL1_CDOG2_MASK               (0x20000000U)
#define CLKCTL0_PSCCTL1_CDOG2_SHIFT              (29U)
/*! CDOG2 - CDOG2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_CDOG2(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CDOG2_SHIFT)) & CLKCTL0_PSCCTL1_CDOG2_MASK)

#define CLKCTL0_PSCCTL1_LP_FLEXCOMM0_MASK        (0x40000000U)
#define CLKCTL0_PSCCTL1_LP_FLEXCOMM0_SHIFT       (30U)
/*! LP_FLEXCOMM0 - LP_FLEXCOMM0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_LP_FLEXCOMM0(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_LP_FLEXCOMM0_SHIFT)) & CLKCTL0_PSCCTL1_LP_FLEXCOMM0_MASK)

#define CLKCTL0_PSCCTL1_LP_FLEXCOMM1_MASK        (0x80000000U)
#define CLKCTL0_PSCCTL1_LP_FLEXCOMM1_SHIFT       (31U)
/*! LP_FLEXCOMM1 - LP_FLEXCOMM1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_LP_FLEXCOMM1(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_LP_FLEXCOMM1_SHIFT)) & CLKCTL0_PSCCTL1_LP_FLEXCOMM1_MASK)
/*! @} */

/*! @name PSCCTL2 - VDD2_COMP Peripheral Clock Control 2 */
/*! @{ */

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM2_MASK        (0x1U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM2_SHIFT       (0U)
/*! LP_FLEXCOMM2 - LP_FLEXCOMM2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM2(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM2_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM2_MASK)

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM3_MASK        (0x2U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM3_SHIFT       (1U)
/*! LP_FLEXCOMM3 - LP_FLEXCOMM3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM3(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM3_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM3_MASK)

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM4_MASK        (0x4U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM4_SHIFT       (2U)
/*! LP_FLEXCOMM4 - LP_FLEXCOMM4 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM4(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM4_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM4_MASK)

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM5_MASK        (0x8U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM5_SHIFT       (3U)
/*! LP_FLEXCOMM5 - LP_FLEXCOMM5 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM5(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM5_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM5_MASK)

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM6_MASK        (0x10U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM6_SHIFT       (4U)
/*! LP_FLEXCOMM6 - LP_FLEXCOMM6 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM6(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM6_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM6_MASK)

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM7_MASK        (0x20U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM7_SHIFT       (5U)
/*! LP_FLEXCOMM7 - LP_FLEXCOMM7 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM7(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM7_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM7_MASK)

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM8_MASK        (0x40U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM8_SHIFT       (6U)
/*! LP_FLEXCOMM8 - LP_FLEXCOMM8 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM8(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM8_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM8_MASK)

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM9_MASK        (0x80U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM9_SHIFT       (7U)
/*! LP_FLEXCOMM9 - LP_FLEXCOMM9 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM9(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM9_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM9_MASK)

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM10_MASK       (0x100U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM10_SHIFT      (8U)
/*! LP_FLEXCOMM10 - LP_FLEXCOMM10 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM10(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM10_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM10_MASK)

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM11_MASK       (0x200U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM11_SHIFT      (9U)
/*! LP_FLEXCOMM11 - LP_FLEXCOMM11 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM11(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM11_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM11_MASK)

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM12_MASK       (0x400U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM12_SHIFT      (10U)
/*! LP_FLEXCOMM12 - LP_FLEXCOMM12 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM12(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM12_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM12_MASK)

#define CLKCTL0_PSCCTL2_LP_FLEXCOMM13_MASK       (0x800U)
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM13_SHIFT      (11U)
/*! LP_FLEXCOMM13 - LP_FLEXCOMM13 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_LP_FLEXCOMM13(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_LP_FLEXCOMM13_SHIFT)) & CLKCTL0_PSCCTL2_LP_FLEXCOMM13_MASK)

#define CLKCTL0_PSCCTL2_SAI0_MASK                (0x2000U)
#define CLKCTL0_PSCCTL2_SAI0_SHIFT               (13U)
/*! SAI0 - SAI0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SAI0(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SAI0_SHIFT)) & CLKCTL0_PSCCTL2_SAI0_MASK)

#define CLKCTL0_PSCCTL2_SAI1_MASK                (0x4000U)
#define CLKCTL0_PSCCTL2_SAI1_SHIFT               (14U)
/*! SAI1 - SAI1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SAI1(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SAI1_SHIFT)) & CLKCTL0_PSCCTL2_SAI1_MASK)

#define CLKCTL0_PSCCTL2_SAI2_MASK                (0x8000U)
#define CLKCTL0_PSCCTL2_SAI2_SHIFT               (15U)
/*! SAI2 - SAI2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SAI2(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SAI2_SHIFT)) & CLKCTL0_PSCCTL2_SAI2_MASK)

#define CLKCTL0_PSCCTL2_I3C0_MASK                (0x10000U)
#define CLKCTL0_PSCCTL2_I3C0_SHIFT               (16U)
/*! I3C0 - I3C0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_I3C0(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_I3C0_SHIFT)) & CLKCTL0_PSCCTL2_I3C0_MASK)

#define CLKCTL0_PSCCTL2_I3C1_MASK                (0x20000U)
#define CLKCTL0_PSCCTL2_I3C1_SHIFT               (17U)
/*! I3C1 - I3C1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_I3C1(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_I3C1_SHIFT)) & CLKCTL0_PSCCTL2_I3C1_MASK)

#define CLKCTL0_PSCCTL2_CRC0_MASK                (0x40000U)
#define CLKCTL0_PSCCTL2_CRC0_SHIFT               (18U)
/*! CRC0 - CRC0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_CRC0(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CRC0_SHIFT)) & CLKCTL0_PSCCTL2_CRC0_MASK)

#define CLKCTL0_PSCCTL2_WWDT0_MASK               (0x80000U)
#define CLKCTL0_PSCCTL2_WWDT0_SHIFT              (19U)
/*! WWDT0 - WWDT0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_WWDT0(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_WWDT0_SHIFT)) & CLKCTL0_PSCCTL2_WWDT0_MASK)

#define CLKCTL0_PSCCTL2_WWDT1_MASK               (0x100000U)
#define CLKCTL0_PSCCTL2_WWDT1_SHIFT              (20U)
/*! WWDT1 - WWDT1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_WWDT1(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_WWDT1_SHIFT)) & CLKCTL0_PSCCTL2_WWDT1_MASK)

#define CLKCTL0_PSCCTL2_CTIMER0_MASK             (0x200000U)
#define CLKCTL0_PSCCTL2_CTIMER0_SHIFT            (21U)
/*! CTIMER0 - CTIMER0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_CTIMER0(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CTIMER0_SHIFT)) & CLKCTL0_PSCCTL2_CTIMER0_MASK)

#define CLKCTL0_PSCCTL2_CTIMER1_MASK             (0x400000U)
#define CLKCTL0_PSCCTL2_CTIMER1_SHIFT            (22U)
/*! CTIMER1 - CTIMER1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_CTIMER1(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CTIMER1_SHIFT)) & CLKCTL0_PSCCTL2_CTIMER1_MASK)

#define CLKCTL0_PSCCTL2_CTIMER2_MASK             (0x800000U)
#define CLKCTL0_PSCCTL2_CTIMER2_SHIFT            (23U)
/*! CTIMER2 - CTIMER2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_CTIMER2(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CTIMER2_SHIFT)) & CLKCTL0_PSCCTL2_CTIMER2_MASK)

#define CLKCTL0_PSCCTL2_CTIMER3_MASK             (0x1000000U)
#define CLKCTL0_PSCCTL2_CTIMER3_SHIFT            (24U)
/*! CTIMER3 - CTIMER3 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_CTIMER3(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CTIMER3_SHIFT)) & CLKCTL0_PSCCTL2_CTIMER3_MASK)

#define CLKCTL0_PSCCTL2_CTIMER4_MASK             (0x2000000U)
#define CLKCTL0_PSCCTL2_CTIMER4_SHIFT            (25U)
/*! CTIMER4 - CTIMER4 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_CTIMER4(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CTIMER4_SHIFT)) & CLKCTL0_PSCCTL2_CTIMER4_MASK)

#define CLKCTL0_PSCCTL2_MRT0_MASK                (0x4000000U)
#define CLKCTL0_PSCCTL2_MRT0_SHIFT               (26U)
/*! MRT0 - MRT0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_MRT0(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_MRT0_SHIFT)) & CLKCTL0_PSCCTL2_MRT0_MASK)

#define CLKCTL0_PSCCTL2_UTICK0_MASK              (0x8000000U)
#define CLKCTL0_PSCCTL2_UTICK0_SHIFT             (27U)
/*! UTICK0 - UTICK0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_UTICK0(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_UTICK0_SHIFT)) & CLKCTL0_PSCCTL2_UTICK0_MASK)

#define CLKCTL0_PSCCTL2_SEMA42_4_MASK            (0x40000000U)
#define CLKCTL0_PSCCTL2_SEMA42_4_SHIFT           (30U)
/*! SEMA42_4 - SEMA42_4 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SEMA42_4(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SEMA42_4_SHIFT)) & CLKCTL0_PSCCTL2_SEMA42_4_MASK)

#define CLKCTL0_PSCCTL2_MU4_MASK                 (0x80000000U)
#define CLKCTL0_PSCCTL2_MU4_SHIFT                (31U)
/*! MU4 - MU4 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_MU4(x)                   (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_MU4_SHIFT)) & CLKCTL0_PSCCTL2_MU4_MASK)
/*! @} */

/*! @name PSCCTL3 - VDD2_COMP Peripheral Clock Control 3 */
/*! @{ */

#define CLKCTL0_PSCCTL3_PINT0_MASK               (0x20U)
#define CLKCTL0_PSCCTL3_PINT0_SHIFT              (5U)
/*! PINT0 - PINT0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_PINT0(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_PINT0_SHIFT)) & CLKCTL0_PSCCTL3_PINT0_MASK)

#define CLKCTL0_PSCCTL3_FREQME0_MASK             (0x100U)
#define CLKCTL0_PSCCTL3_FREQME0_SHIFT            (8U)
/*! FREQME0 - FREQME0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_FREQME0(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_FREQME0_SHIFT)) & CLKCTL0_PSCCTL3_FREQME0_MASK)

#define CLKCTL0_PSCCTL3_INPUTMUX0_MASK           (0x400U)
#define CLKCTL0_PSCCTL3_INPUTMUX0_SHIFT          (10U)
/*! INPUTMUX0 - INPUTMUX0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_INPUTMUX0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_INPUTMUX0_SHIFT)) & CLKCTL0_PSCCTL3_INPUTMUX0_MASK)

#define CLKCTL0_PSCCTL3_SAFO_SGI_MASK            (0x1000U)
#define CLKCTL0_PSCCTL3_SAFO_SGI_SHIFT           (12U)
/*! SAFO_SGI - SAFO_SGI Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_SAFO_SGI(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_SAFO_SGI_SHIFT)) & CLKCTL0_PSCCTL3_SAFO_SGI_MASK)

#define CLKCTL0_PSCCTL3_TRACE_MASK               (0x2000U)
#define CLKCTL0_PSCCTL3_TRACE_SHIFT              (13U)
/*! TRACE - TRACE_RT700 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_TRACE(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_TRACE_SHIFT)) & CLKCTL0_PSCCTL3_TRACE_MASK)

#define CLKCTL0_PSCCTL3_PRINCE0_MASK             (0x8000U)
#define CLKCTL0_PSCCTL3_PRINCE0_SHIFT            (15U)
/*! PRINCE0 - PRINCE0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_PRINCE0(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_PRINCE0_SHIFT)) & CLKCTL0_PSCCTL3_PRINCE0_MASK)

#define CLKCTL0_PSCCTL3_PRINCE1_MASK             (0x10000U)
#define CLKCTL0_PSCCTL3_PRINCE1_SHIFT            (16U)
/*! PRINCE1 - PRINCE1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_PRINCE1(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_PRINCE1_SHIFT)) & CLKCTL0_PSCCTL3_PRINCE1_MASK)

#define CLKCTL0_PSCCTL3_XSPI1_PRINCE_XEX_MASK    (0x20000U)
#define CLKCTL0_PSCCTL3_XSPI1_PRINCE_XEX_SHIFT   (17U)
/*! XSPI1_PRINCE_XEX - XSPI1 PRINCE_XEX Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_XSPI1_PRINCE_XEX(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_XSPI1_PRINCE_XEX_SHIFT)) & CLKCTL0_PSCCTL3_XSPI1_PRINCE_XEX_MASK)

#define CLKCTL0_PSCCTL3_CMX_PERFMON0_MASK        (0x40000U)
#define CLKCTL0_PSCCTL3_CMX_PERFMON0_SHIFT       (18U)
/*! CMX_PERFMON0 - CMX_PERFMON0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_CMX_PERFMON0(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CMX_PERFMON0_SHIFT)) & CLKCTL0_PSCCTL3_CMX_PERFMON0_MASK)

#define CLKCTL0_PSCCTL3_CMX_PERFMON1_MASK        (0x80000U)
#define CLKCTL0_PSCCTL3_CMX_PERFMON1_SHIFT       (19U)
/*! CMX_PERFMON1 - CMX_PERFMON1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_CMX_PERFMON1(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CMX_PERFMON1_SHIFT)) & CLKCTL0_PSCCTL3_CMX_PERFMON1_MASK)
/*! @} */

/*! @name PSCCTL4 - VDD2_COMP Peripheral Clock Control 4 */
/*! @{ */

#define CLKCTL0_PSCCTL4_HIFI4_MASK               (0x1U)
#define CLKCTL0_PSCCTL4_HIFI4_SHIFT              (0U)
/*! HiFi4 - HiFi4 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL4_HIFI4(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL4_HIFI4_SHIFT)) & CLKCTL0_PSCCTL4_HIFI4_MASK)
/*! @} */

/*! @name PSCCTL5 - VDD2_COMP Peripheral Clock Control 5 */
/*! @{ */

#define CLKCTL0_PSCCTL5_NPU0_MASK                (0x1U)
#define CLKCTL0_PSCCTL5_NPU0_SHIFT               (0U)
/*! NPU0 - NPU0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL5_NPU0(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_NPU0_SHIFT)) & CLKCTL0_PSCCTL5_NPU0_MASK)

#define CLKCTL0_PSCCTL5_COMP_ACCESS_RAM_ARBITER1_MASK (0x4U)
#define CLKCTL0_PSCCTL5_COMP_ACCESS_RAM_ARBITER1_SHIFT (2U)
/*! COMP_ACCESS_RAM_ARBITER1 - VDD2_COMP Access RAM Arbiter1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL5_COMP_ACCESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_COMP_ACCESS_RAM_ARBITER1_SHIFT)) & CLKCTL0_PSCCTL5_COMP_ACCESS_RAM_ARBITER1_MASK)

#define CLKCTL0_PSCCTL5_IOPCTL0_MASK             (0x8U)
#define CLKCTL0_PSCCTL5_IOPCTL0_SHIFT            (3U)
/*! IOPCTL0 - IOPCTL0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL5_IOPCTL0(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_IOPCTL0_SHIFT)) & CLKCTL0_PSCCTL5_IOPCTL0_MASK)

#define CLKCTL0_PSCCTL5_HIFI4_ACCESS_RAM_ARBITER1_MASK (0x10U)
#define CLKCTL0_PSCCTL5_HIFI4_ACCESS_RAM_ARBITER1_SHIFT (4U)
/*! HiFi4_ACCESS_RAM_ARBITER1 - HiFi4 Access RAM Arbiter1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL5_HIFI4_ACCESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_HIFI4_ACCESS_RAM_ARBITER1_SHIFT)) & CLKCTL0_PSCCTL5_HIFI4_ACCESS_RAM_ARBITER1_MASK)

#define CLKCTL0_PSCCTL5_MEDIA_ACCESS_RAM_ARBITER0_MASK (0x20U)
#define CLKCTL0_PSCCTL5_MEDIA_ACCESS_RAM_ARBITER0_SHIFT (5U)
/*! MEDIA_ACCESS_RAM_ARBITER0 - VDD2_Media Access RAM Arbiter 0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL5_MEDIA_ACCESS_RAM_ARBITER0(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_MEDIA_ACCESS_RAM_ARBITER0_SHIFT)) & CLKCTL0_PSCCTL5_MEDIA_ACCESS_RAM_ARBITER0_MASK)
/*! @} */

/*! @name PSCCTL0_SET - VDD2_COMP Peripheral Clock Control 0 Set */
/*! @{ */

#define CLKCTL0_PSCCTL0_SET_CODE_CACHE_MASK      (0x2U)
#define CLKCTL0_PSCCTL0_SET_CODE_CACHE_SHIFT     (1U)
/*! CODE_CACHE - XCACHE1 (Code Cache) Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_SET_CODE_CACHE(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_CODE_CACHE_SHIFT)) & CLKCTL0_PSCCTL0_SET_CODE_CACHE_MASK)

#define CLKCTL0_PSCCTL0_SET_SYSTEM_CACHE_MASK    (0x4U)
#define CLKCTL0_PSCCTL0_SET_SYSTEM_CACHE_SHIFT   (2U)
/*! SYSTEM_CACHE - XCACHE0 (System Cache) Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_SET_SYSTEM_CACHE(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_SYSTEM_CACHE_SHIFT)) & CLKCTL0_PSCCTL0_SET_SYSTEM_CACHE_MASK)

#define CLKCTL0_PSCCTL0_SET_VDD2_OTP0_MASK       (0x20U)
#define CLKCTL0_PSCCTL0_SET_VDD2_OTP0_SHIFT      (5U)
/*! VDD2_OTP0 - VDD2_OTP_CTRL0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_SET_VDD2_OTP0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_VDD2_OTP0_SHIFT)) & CLKCTL0_PSCCTL0_SET_VDD2_OTP0_MASK)

#define CLKCTL0_PSCCTL0_SET_SLEEPCON0_MASK       (0x1000U)
#define CLKCTL0_PSCCTL0_SET_SLEEPCON0_SHIFT      (12U)
/*! SLEEPCON0 - SLEEPCON0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_SET_SLEEPCON0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_SLEEPCON0_SHIFT)) & CLKCTL0_PSCCTL0_SET_SLEEPCON0_MASK)

#define CLKCTL0_PSCCTL0_SET_SYSCON0_MASK         (0x2000U)
#define CLKCTL0_PSCCTL0_SET_SYSCON0_SHIFT        (13U)
/*! SYSCON0 - SYSCON0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_SET_SYSCON0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_SYSCON0_SHIFT)) & CLKCTL0_PSCCTL0_SET_SYSCON0_MASK)

#define CLKCTL0_PSCCTL0_SET_GLIKEY0_MASK         (0x4000U)
#define CLKCTL0_PSCCTL0_SET_GLIKEY0_SHIFT        (14U)
/*! GLIKEY0 - GLIKEY0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_SET_GLIKEY0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_GLIKEY0_SHIFT)) & CLKCTL0_PSCCTL0_SET_GLIKEY0_MASK)

#define CLKCTL0_PSCCTL0_SET_GLIKEY3_MASK         (0x8000U)
#define CLKCTL0_PSCCTL0_SET_GLIKEY3_SHIFT        (15U)
/*! GLIKEY3 - GLIKEY3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL0_SET_GLIKEY3(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_SET_GLIKEY3_SHIFT)) & CLKCTL0_PSCCTL0_SET_GLIKEY3_MASK)
/*! @} */

/*! @name PSCCTL1_SET - VDD2_COMP Peripheral Clock Control 1 Set */
/*! @{ */

#define CLKCTL0_PSCCTL1_SET_TPIU_TRACE_CLKIN_MASK (0x4U)
#define CLKCTL0_PSCCTL1_SET_TPIU_TRACE_CLKIN_SHIFT (2U)
/*! TPIU_TRACE_CLKIN - TPIU_TRACE_CLKIN (TRACE_RT700) Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_TPIU_TRACE_CLKIN(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_TPIU_TRACE_CLKIN_SHIFT)) & CLKCTL0_PSCCTL1_SET_TPIU_TRACE_CLKIN_MASK)

#define CLKCTL0_PSCCTL1_SET_SWO_TRACECLKIN_MASK  (0x8U)
#define CLKCTL0_PSCCTL1_SET_SWO_TRACECLKIN_SHIFT (3U)
/*! SWO_TRACECLKIN - SWO TRACECLKIN (TRACE_RT700) Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_SWO_TRACECLKIN(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_SWO_TRACECLKIN_SHIFT)) & CLKCTL0_PSCCTL1_SET_SWO_TRACECLKIN_MASK)

#define CLKCTL0_PSCCTL1_SET_TSCLK_MASK           (0x10U)
#define CLKCTL0_PSCCTL1_SET_TSCLK_SHIFT          (4U)
/*! TSCLK - TS (TRACE_RT700) Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_TSCLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_TSCLK_SHIFT)) & CLKCTL0_PSCCTL1_SET_TSCLK_MASK)

#define CLKCTL0_PSCCTL1_SET_EDMA0_MASK           (0x20U)
#define CLKCTL0_PSCCTL1_SET_EDMA0_SHIFT          (5U)
/*! eDMA0 - eDMA0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_EDMA0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_EDMA0_SHIFT)) & CLKCTL0_PSCCTL1_SET_EDMA0_MASK)

#define CLKCTL0_PSCCTL1_SET_EDMA1_MASK           (0x40U)
#define CLKCTL0_PSCCTL1_SET_EDMA1_SHIFT          (6U)
/*! eDMA1 - eDMA1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_EDMA1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_EDMA1_SHIFT)) & CLKCTL0_PSCCTL1_SET_EDMA1_MASK)

#define CLKCTL0_PSCCTL1_SET_PKC_RAM_CTRL_MASK    (0x80U)
#define CLKCTL0_PSCCTL1_SET_PKC_RAM_CTRL_SHIFT   (7U)
/*! PKC_RAM_CTRl - RAM Control Clock of PKC
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_PKC_RAM_CTRL(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_PKC_RAM_CTRL_SHIFT)) & CLKCTL0_PSCCTL1_SET_PKC_RAM_CTRL_MASK)

#define CLKCTL0_PSCCTL1_SET_PKC_MASK             (0x100U)
#define CLKCTL0_PSCCTL1_SET_PKC_SHIFT            (8U)
/*! PKC - PKC Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_PKC(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_PKC_SHIFT)) & CLKCTL0_PSCCTL1_SET_PKC_MASK)

#define CLKCTL0_PSCCTL1_SET_ROMCP_MASK           (0x200U)
#define CLKCTL0_PSCCTL1_SET_ROMCP_SHIFT          (9U)
/*! ROMCP - ROMCP Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_ROMCP(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_ROMCP_SHIFT)) & CLKCTL0_PSCCTL1_SET_ROMCP_MASK)

#define CLKCTL0_PSCCTL1_SET_XSPI0_MASK           (0x400U)
#define CLKCTL0_PSCCTL1_SET_XSPI0_SHIFT          (10U)
/*! XSPI0 - XSPI0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_XSPI0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_XSPI0_SHIFT)) & CLKCTL0_PSCCTL1_SET_XSPI0_MASK)

#define CLKCTL0_PSCCTL1_SET_XSPI1_MASK           (0x800U)
#define CLKCTL0_PSCCTL1_SET_XSPI1_SHIFT          (11U)
/*! XSPI1 - XSPI1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_XSPI1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_XSPI1_SHIFT)) & CLKCTL0_PSCCTL1_SET_XSPI1_MASK)

#define CLKCTL0_PSCCTL1_SET_CACHE64_0_MASK       (0x1000U)
#define CLKCTL0_PSCCTL1_SET_CACHE64_0_SHIFT      (12U)
/*! CACHE64_0 - CACHE64_0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_CACHE64_0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_CACHE64_0_SHIFT)) & CLKCTL0_PSCCTL1_SET_CACHE64_0_MASK)

#define CLKCTL0_PSCCTL1_SET_CACHE64_1_MASK       (0x2000U)
#define CLKCTL0_PSCCTL1_SET_CACHE64_1_SHIFT      (13U)
/*! CACHE64_1 - CACHE64_1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_CACHE64_1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_CACHE64_1_SHIFT)) & CLKCTL0_PSCCTL1_SET_CACHE64_1_MASK)

#define CLKCTL0_PSCCTL1_SET_QK_SUBSYS_MASK       (0x4000U)
#define CLKCTL0_PSCCTL1_SET_QK_SUBSYS_SHIFT      (14U)
/*! QK_SUBSYS - QK_SUBSYS (PUF_CTRL) Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_QK_SUBSYS(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_QK_SUBSYS_SHIFT)) & CLKCTL0_PSCCTL1_SET_QK_SUBSYS_MASK)

#define CLKCTL0_PSCCTL1_SET_MMU0_MASK            (0x10000U)
#define CLKCTL0_PSCCTL1_SET_MMU0_SHIFT           (16U)
/*! MMU0 - MMU0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_MMU0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_MMU0_SHIFT)) & CLKCTL0_PSCCTL1_SET_MMU0_MASK)

#define CLKCTL0_PSCCTL1_SET_MMU1_MASK            (0x20000U)
#define CLKCTL0_PSCCTL1_SET_MMU1_SHIFT           (17U)
/*! MMU1 - MMU1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_MMU1(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_MMU1_SHIFT)) & CLKCTL0_PSCCTL1_SET_MMU1_MASK)

#define CLKCTL0_PSCCTL1_SET_GPIO0_MASK           (0x40000U)
#define CLKCTL0_PSCCTL1_SET_GPIO0_SHIFT          (18U)
/*! GPIO0 - GPIO0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_GPIO0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_GPIO0_SHIFT)) & CLKCTL0_PSCCTL1_SET_GPIO0_MASK)

#define CLKCTL0_PSCCTL1_SET_GPIO1_MASK           (0x80000U)
#define CLKCTL0_PSCCTL1_SET_GPIO1_SHIFT          (19U)
/*! GPIO1 - GPIO1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_GPIO1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_GPIO1_SHIFT)) & CLKCTL0_PSCCTL1_SET_GPIO1_MASK)

#define CLKCTL0_PSCCTL1_SET_GPIO2_MASK           (0x100000U)
#define CLKCTL0_PSCCTL1_SET_GPIO2_SHIFT          (20U)
/*! GPIO2 - GPIO2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_GPIO2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_GPIO2_SHIFT)) & CLKCTL0_PSCCTL1_SET_GPIO2_MASK)

#define CLKCTL0_PSCCTL1_SET_GPIO3_MASK           (0x200000U)
#define CLKCTL0_PSCCTL1_SET_GPIO3_SHIFT          (21U)
/*! GPIO3 - GPIO3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_GPIO3(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_GPIO3_SHIFT)) & CLKCTL0_PSCCTL1_SET_GPIO3_MASK)

#define CLKCTL0_PSCCTL1_SET_GPIO4_MASK           (0x400000U)
#define CLKCTL0_PSCCTL1_SET_GPIO4_SHIFT          (22U)
/*! GPIO4 - GPIO4 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_GPIO4(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_GPIO4_SHIFT)) & CLKCTL0_PSCCTL1_SET_GPIO4_MASK)

#define CLKCTL0_PSCCTL1_SET_GPIO5_MASK           (0x800000U)
#define CLKCTL0_PSCCTL1_SET_GPIO5_SHIFT          (23U)
/*! GPIO5 - GPIO5 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_GPIO5(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_GPIO5_SHIFT)) & CLKCTL0_PSCCTL1_SET_GPIO5_MASK)

#define CLKCTL0_PSCCTL1_SET_GPIO6_MASK           (0x1000000U)
#define CLKCTL0_PSCCTL1_SET_GPIO6_SHIFT          (24U)
/*! GPIO6 - GPIO6 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_GPIO6(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_GPIO6_SHIFT)) & CLKCTL0_PSCCTL1_SET_GPIO6_MASK)

#define CLKCTL0_PSCCTL1_SET_GPIO7_MASK           (0x2000000U)
#define CLKCTL0_PSCCTL1_SET_GPIO7_SHIFT          (25U)
/*! GPIO7 - GPIO7 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_GPIO7(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_GPIO7_SHIFT)) & CLKCTL0_PSCCTL1_SET_GPIO7_MASK)

#define CLKCTL0_PSCCTL1_SET_SCT0_MASK            (0x4000000U)
#define CLKCTL0_PSCCTL1_SET_SCT0_SHIFT           (26U)
/*! SCT0 - SCT0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_SCT0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_SCT0_SHIFT)) & CLKCTL0_PSCCTL1_SET_SCT0_MASK)

#define CLKCTL0_PSCCTL1_SET_CDOG0_MASK           (0x8000000U)
#define CLKCTL0_PSCCTL1_SET_CDOG0_SHIFT          (27U)
/*! CDOG0 - CDOG0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_CDOG0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_CDOG0_SHIFT)) & CLKCTL0_PSCCTL1_SET_CDOG0_MASK)

#define CLKCTL0_PSCCTL1_SET_CDOG1_MASK           (0x10000000U)
#define CLKCTL0_PSCCTL1_SET_CDOG1_SHIFT          (28U)
/*! CDOG1 - CDOG1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_CDOG1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_CDOG1_SHIFT)) & CLKCTL0_PSCCTL1_SET_CDOG1_MASK)

#define CLKCTL0_PSCCTL1_SET_CDOG2_MASK           (0x20000000U)
#define CLKCTL0_PSCCTL1_SET_CDOG2_SHIFT          (29U)
/*! CDOG2 - CDOG2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_CDOG2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_CDOG2_SHIFT)) & CLKCTL0_PSCCTL1_SET_CDOG2_MASK)

#define CLKCTL0_PSCCTL1_SET_LP_FLEXCOMM0_MASK    (0x40000000U)
#define CLKCTL0_PSCCTL1_SET_LP_FLEXCOMM0_SHIFT   (30U)
/*! LP_FLEXCOMM0 - LP_FLEXCOMM0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_LP_FLEXCOMM0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_LP_FLEXCOMM0_SHIFT)) & CLKCTL0_PSCCTL1_SET_LP_FLEXCOMM0_MASK)

#define CLKCTL0_PSCCTL1_SET_LP_FLEXCOMM1_MASK    (0x80000000U)
#define CLKCTL0_PSCCTL1_SET_LP_FLEXCOMM1_SHIFT   (31U)
/*! LP_FLEXCOMM1 - LP_FLEXCOMM1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL1_SET_LP_FLEXCOMM1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_SET_LP_FLEXCOMM1_SHIFT)) & CLKCTL0_PSCCTL1_SET_LP_FLEXCOMM1_MASK)
/*! @} */

/*! @name PSCCTL2_SET - VDD2_COMP Peripheral Clock Control 2 Set */
/*! @{ */

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM2_MASK    (0x1U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM2_SHIFT   (0U)
/*! LP_FLEXCOMM2 - LP_FLEXCOMM2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM2(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM2_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM2_MASK)

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM3_MASK    (0x2U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM3_SHIFT   (1U)
/*! LP_FLEXCOMM3 - LP_FLEXCOMM3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM3(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM3_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM3_MASK)

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM4_MASK    (0x4U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM4_SHIFT   (2U)
/*! LP_FLEXCOMM4 - LP_FLEXCOMM4 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM4(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM4_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM4_MASK)

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM5_MASK    (0x8U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM5_SHIFT   (3U)
/*! LP_FLEXCOMM5 - LP_FLEXCOMM5 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM5(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM5_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM5_MASK)

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM6_MASK    (0x10U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM6_SHIFT   (4U)
/*! LP_FLEXCOMM6 - LP_FLEXCOMM6 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM6(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM6_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM6_MASK)

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM7_MASK    (0x20U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM7_SHIFT   (5U)
/*! LP_FLEXCOMM7 - LP_FLEXCOMM7 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM7(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM7_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM7_MASK)

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM8_MASK    (0x40U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM8_SHIFT   (6U)
/*! LP_FLEXCOMM8 - LP_FLEXCOMM8 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM8(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM8_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM8_MASK)

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM9_MASK    (0x80U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM9_SHIFT   (7U)
/*! LP_FLEXCOMM9 - LP_FLEXCOMM9 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM9(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM9_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM9_MASK)

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM10_MASK   (0x100U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM10_SHIFT  (8U)
/*! LP_FLEXCOMM10 - LP_FLEXCOMM10 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM10(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM10_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM10_MASK)

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM11_MASK   (0x200U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM11_SHIFT  (9U)
/*! LP_FLEXCOMM11 - LP_FLEXCOMM11 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM11(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM11_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM11_MASK)

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM12_MASK   (0x400U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM12_SHIFT  (10U)
/*! LP_FLEXCOMM12 - LP_FLEXCOMM12 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM12(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM12_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM12_MASK)

#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM13_MASK   (0x800U)
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM13_SHIFT  (11U)
/*! LP_FLEXCOMM13 - LP_FLEXCOMM13 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM13(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM13_SHIFT)) & CLKCTL0_PSCCTL2_SET_LP_FLEXCOMM13_MASK)

#define CLKCTL0_PSCCTL2_SET_SAI0_MASK            (0x2000U)
#define CLKCTL0_PSCCTL2_SET_SAI0_SHIFT           (13U)
/*! SAI0 - SAI0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_SAI0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_SAI0_SHIFT)) & CLKCTL0_PSCCTL2_SET_SAI0_MASK)

#define CLKCTL0_PSCCTL2_SET_SAI1_MASK            (0x4000U)
#define CLKCTL0_PSCCTL2_SET_SAI1_SHIFT           (14U)
/*! SAI1 - SAI1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_SAI1(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_SAI1_SHIFT)) & CLKCTL0_PSCCTL2_SET_SAI1_MASK)

#define CLKCTL0_PSCCTL2_SET_SAI2_MASK            (0x8000U)
#define CLKCTL0_PSCCTL2_SET_SAI2_SHIFT           (15U)
/*! SAI2 - SAI2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_SAI2(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_SAI2_SHIFT)) & CLKCTL0_PSCCTL2_SET_SAI2_MASK)

#define CLKCTL0_PSCCTL2_SET_I3C0_MASK            (0x10000U)
#define CLKCTL0_PSCCTL2_SET_I3C0_SHIFT           (16U)
/*! I3C0 - I3C0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_I3C0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_I3C0_SHIFT)) & CLKCTL0_PSCCTL2_SET_I3C0_MASK)

#define CLKCTL0_PSCCTL2_SET_I3C1_MASK            (0x20000U)
#define CLKCTL0_PSCCTL2_SET_I3C1_SHIFT           (17U)
/*! I3C1 - I3C1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_I3C1(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_I3C1_SHIFT)) & CLKCTL0_PSCCTL2_SET_I3C1_MASK)

#define CLKCTL0_PSCCTL2_SET_CRC0_MASK            (0x40000U)
#define CLKCTL0_PSCCTL2_SET_CRC0_SHIFT           (18U)
/*! CRC0 - CRC0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_CRC0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_CRC0_SHIFT)) & CLKCTL0_PSCCTL2_SET_CRC0_MASK)

#define CLKCTL0_PSCCTL2_SET_WWDT0_MASK           (0x80000U)
#define CLKCTL0_PSCCTL2_SET_WWDT0_SHIFT          (19U)
/*! WWDT0 - WWDT0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_WWDT0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_WWDT0_SHIFT)) & CLKCTL0_PSCCTL2_SET_WWDT0_MASK)

#define CLKCTL0_PSCCTL2_SET_WWDT1_MASK           (0x100000U)
#define CLKCTL0_PSCCTL2_SET_WWDT1_SHIFT          (20U)
/*! WWDT1 - WWDT1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_WWDT1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_WWDT1_SHIFT)) & CLKCTL0_PSCCTL2_SET_WWDT1_MASK)

#define CLKCTL0_PSCCTL2_SET_CTIMER0_MASK         (0x200000U)
#define CLKCTL0_PSCCTL2_SET_CTIMER0_SHIFT        (21U)
/*! CTIMER0 - CTIMER0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_CTIMER0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_CTIMER0_SHIFT)) & CLKCTL0_PSCCTL2_SET_CTIMER0_MASK)

#define CLKCTL0_PSCCTL2_SET_CTIMER1_MASK         (0x400000U)
#define CLKCTL0_PSCCTL2_SET_CTIMER1_SHIFT        (22U)
/*! CTIMER1 - CTIMER1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_CTIMER1(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_CTIMER1_SHIFT)) & CLKCTL0_PSCCTL2_SET_CTIMER1_MASK)

#define CLKCTL0_PSCCTL2_SET_CTIMER2_MASK         (0x800000U)
#define CLKCTL0_PSCCTL2_SET_CTIMER2_SHIFT        (23U)
/*! CTIMER2 - CTIMER2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_CTIMER2(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_CTIMER2_SHIFT)) & CLKCTL0_PSCCTL2_SET_CTIMER2_MASK)

#define CLKCTL0_PSCCTL2_SET_CTIMER3_MASK         (0x1000000U)
#define CLKCTL0_PSCCTL2_SET_CTIMER3_SHIFT        (24U)
/*! CTIMER3 - CTIMER3 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_CTIMER3(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_CTIMER3_SHIFT)) & CLKCTL0_PSCCTL2_SET_CTIMER3_MASK)

#define CLKCTL0_PSCCTL2_SET_CTIMER4_MASK         (0x2000000U)
#define CLKCTL0_PSCCTL2_SET_CTIMER4_SHIFT        (25U)
/*! CTIMER4 - CTIMER4 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_CTIMER4(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_CTIMER4_SHIFT)) & CLKCTL0_PSCCTL2_SET_CTIMER4_MASK)

#define CLKCTL0_PSCCTL2_SET_MRT0_MASK            (0x4000000U)
#define CLKCTL0_PSCCTL2_SET_MRT0_SHIFT           (26U)
/*! MRT0 - MRT0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_MRT0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_MRT0_SHIFT)) & CLKCTL0_PSCCTL2_SET_MRT0_MASK)

#define CLKCTL0_PSCCTL2_SET_UTICK0_MASK          (0x8000000U)
#define CLKCTL0_PSCCTL2_SET_UTICK0_SHIFT         (27U)
/*! UTICK0 - UTICK0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_UTICK0(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_UTICK0_SHIFT)) & CLKCTL0_PSCCTL2_SET_UTICK0_MASK)

#define CLKCTL0_PSCCTL2_SET_SEMA42_4_MASK        (0x40000000U)
#define CLKCTL0_PSCCTL2_SET_SEMA42_4_SHIFT       (30U)
/*! SEMA42_4 - SEMA42_4 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_SEMA42_4(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_SEMA42_4_SHIFT)) & CLKCTL0_PSCCTL2_SET_SEMA42_4_MASK)

#define CLKCTL0_PSCCTL2_SET_MU4_MASK             (0x80000000U)
#define CLKCTL0_PSCCTL2_SET_MU4_SHIFT            (31U)
/*! MU4 - MU4 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL2_SET_MU4(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_SET_MU4_SHIFT)) & CLKCTL0_PSCCTL2_SET_MU4_MASK)
/*! @} */

/*! @name PSCCTL3_SET - VDD2_COMP Peripheral Clock Control 3 Set */
/*! @{ */

#define CLKCTL0_PSCCTL3_SET_PINT0_MASK           (0x20U)
#define CLKCTL0_PSCCTL3_SET_PINT0_SHIFT          (5U)
/*! PINT0 - PINT0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_SET_PINT0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_SET_PINT0_SHIFT)) & CLKCTL0_PSCCTL3_SET_PINT0_MASK)

#define CLKCTL0_PSCCTL3_SET_FREQME0_MASK         (0x100U)
#define CLKCTL0_PSCCTL3_SET_FREQME0_SHIFT        (8U)
/*! FREQME0 - FREQME0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_SET_FREQME0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_SET_FREQME0_SHIFT)) & CLKCTL0_PSCCTL3_SET_FREQME0_MASK)

#define CLKCTL0_PSCCTL3_SET_INPUTMUX0_MASK       (0x400U)
#define CLKCTL0_PSCCTL3_SET_INPUTMUX0_SHIFT      (10U)
/*! INPUTMUX0 - INPUTMUX0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_SET_INPUTMUX0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_SET_INPUTMUX0_SHIFT)) & CLKCTL0_PSCCTL3_SET_INPUTMUX0_MASK)

#define CLKCTL0_PSCCTL3_SET_SAFO_SGI_MASK        (0x1000U)
#define CLKCTL0_PSCCTL3_SET_SAFO_SGI_SHIFT       (12U)
/*! SAFO_SGI - SAFO_SGI Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_SET_SAFO_SGI(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_SET_SAFO_SGI_SHIFT)) & CLKCTL0_PSCCTL3_SET_SAFO_SGI_MASK)

#define CLKCTL0_PSCCTL3_SET_TRACE_MASK           (0x2000U)
#define CLKCTL0_PSCCTL3_SET_TRACE_SHIFT          (13U)
/*! TRACE - TRACE_RT700 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_SET_TRACE(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_SET_TRACE_SHIFT)) & CLKCTL0_PSCCTL3_SET_TRACE_MASK)

#define CLKCTL0_PSCCTL3_SET_PRINCE0_MASK         (0x8000U)
#define CLKCTL0_PSCCTL3_SET_PRINCE0_SHIFT        (15U)
/*! PRINCE0 - PRINCE0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_SET_PRINCE0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_SET_PRINCE0_SHIFT)) & CLKCTL0_PSCCTL3_SET_PRINCE0_MASK)

#define CLKCTL0_PSCCTL3_SET_PRINCE1_MASK         (0x10000U)
#define CLKCTL0_PSCCTL3_SET_PRINCE1_SHIFT        (16U)
/*! PRINCE1 - PRINCE1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_SET_PRINCE1(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_SET_PRINCE1_SHIFT)) & CLKCTL0_PSCCTL3_SET_PRINCE1_MASK)

#define CLKCTL0_PSCCTL3_SET_XSPI1_PRINCE_XEX_MASK (0x20000U)
#define CLKCTL0_PSCCTL3_SET_XSPI1_PRINCE_XEX_SHIFT (17U)
/*! XSPI1_PRINCE_XEX - XSPI1_PRINCE XEX Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_SET_XSPI1_PRINCE_XEX(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_SET_XSPI1_PRINCE_XEX_SHIFT)) & CLKCTL0_PSCCTL3_SET_XSPI1_PRINCE_XEX_MASK)

#define CLKCTL0_PSCCTL3_SET_CMX_PERFMON0_MASK    (0x40000U)
#define CLKCTL0_PSCCTL3_SET_CMX_PERFMON0_SHIFT   (18U)
/*! CMX_PERFMON0 - CMX_PERFMON0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_SET_CMX_PERFMON0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_SET_CMX_PERFMON0_SHIFT)) & CLKCTL0_PSCCTL3_SET_CMX_PERFMON0_MASK)

#define CLKCTL0_PSCCTL3_SET_CMX_PERFMON1_MASK    (0x80000U)
#define CLKCTL0_PSCCTL3_SET_CMX_PERFMON1_SHIFT   (19U)
/*! CMX_PERFMON1 - CMX_PERFMON1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL3_SET_CMX_PERFMON1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_SET_CMX_PERFMON1_SHIFT)) & CLKCTL0_PSCCTL3_SET_CMX_PERFMON1_MASK)
/*! @} */

/*! @name PSCCTL4_SET - VDD2_COMP Peripheral Clock Control 4 Set */
/*! @{ */

#define CLKCTL0_PSCCTL4_SET_HIFI4_MASK           (0x1U)
#define CLKCTL0_PSCCTL4_SET_HIFI4_SHIFT          (0U)
/*! HiFi4 - HiFi4 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL4_SET_HIFI4(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL4_SET_HIFI4_SHIFT)) & CLKCTL0_PSCCTL4_SET_HIFI4_MASK)
/*! @} */

/*! @name PSCCTL5_SET - VDD2_COMP Peripheral Clock Control 5 Set */
/*! @{ */

#define CLKCTL0_PSCCTL5_SET_NPU0_MASK            (0x1U)
#define CLKCTL0_PSCCTL5_SET_NPU0_SHIFT           (0U)
/*! NPU0 - NPU0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL5_SET_NPU0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_SET_NPU0_SHIFT)) & CLKCTL0_PSCCTL5_SET_NPU0_MASK)

#define CLKCTL0_PSCCTL5_SET_COMP_ACCESS_RAM_ARBITER1_MASK (0x4U)
#define CLKCTL0_PSCCTL5_SET_COMP_ACCESS_RAM_ARBITER1_SHIFT (2U)
/*! COMP_ACCESS_RAM_ARBITER1 - VDD2_COMP Access RAM Arbiter1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL5_SET_COMP_ACCESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_SET_COMP_ACCESS_RAM_ARBITER1_SHIFT)) & CLKCTL0_PSCCTL5_SET_COMP_ACCESS_RAM_ARBITER1_MASK)

#define CLKCTL0_PSCCTL5_SET_IOPCTL0_MASK         (0x8U)
#define CLKCTL0_PSCCTL5_SET_IOPCTL0_SHIFT        (3U)
/*! IOPCTL0 - IOPCTL0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL5_SET_IOPCTL0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_SET_IOPCTL0_SHIFT)) & CLKCTL0_PSCCTL5_SET_IOPCTL0_MASK)

#define CLKCTL0_PSCCTL5_SET_HIFI4_ACCESS_RAM_ARBITER1_MASK (0x10U)
#define CLKCTL0_PSCCTL5_SET_HIFI4_ACCESS_RAM_ARBITER1_SHIFT (4U)
/*! HiFi4_ACCESS_RAM_ARBITER1 - HiFi4 Access RAM Arbiter1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL5_SET_HIFI4_ACCESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_SET_HIFI4_ACCESS_RAM_ARBITER1_SHIFT)) & CLKCTL0_PSCCTL5_SET_HIFI4_ACCESS_RAM_ARBITER1_MASK)

#define CLKCTL0_PSCCTL5_SET_MEDIA_ACCESS_RAM_ARBITER0_MASK (0x20U)
#define CLKCTL0_PSCCTL5_SET_MEDIA_ACCESS_RAM_ARBITER0_SHIFT (5U)
/*! MEDIA_ACCESS_RAM_ARBITER0 - VDD2_Media Access RAM Arbiter 0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL0_PSCCTL5_SET_MEDIA_ACCESS_RAM_ARBITER0(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_SET_MEDIA_ACCESS_RAM_ARBITER0_SHIFT)) & CLKCTL0_PSCCTL5_SET_MEDIA_ACCESS_RAM_ARBITER0_MASK)
/*! @} */

/*! @name PSCCTL0_CLR - VDD2_COMP Peripheral Clock Control 0 Clear */
/*! @{ */

#define CLKCTL0_PSCCTL0_CLR_CODE_CACHE_MASK      (0x2U)
#define CLKCTL0_PSCCTL0_CLR_CODE_CACHE_SHIFT     (1U)
/*! CODE_CACHE - CODE CACHE (XCACHE1) Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL0_CLR_CODE_CACHE(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_CODE_CACHE_SHIFT)) & CLKCTL0_PSCCTL0_CLR_CODE_CACHE_MASK)

#define CLKCTL0_PSCCTL0_CLR_SYSTEM_CACHE_MASK    (0x4U)
#define CLKCTL0_PSCCTL0_CLR_SYSTEM_CACHE_SHIFT   (2U)
/*! SYSTEM_CACHE - SYSTEM CACHE (XCACHE0)Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL0_CLR_SYSTEM_CACHE(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_SYSTEM_CACHE_SHIFT)) & CLKCTL0_PSCCTL0_CLR_SYSTEM_CACHE_MASK)

#define CLKCTL0_PSCCTL0_CLR_VDD2_OTP0_MASK       (0x20U)
#define CLKCTL0_PSCCTL0_CLR_VDD2_OTP0_SHIFT      (5U)
/*! VDD2_OTP0 - VDD2_OTP_CTRL0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL0_CLR_VDD2_OTP0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_VDD2_OTP0_SHIFT)) & CLKCTL0_PSCCTL0_CLR_VDD2_OTP0_MASK)

#define CLKCTL0_PSCCTL0_CLR_SLEEPCON0_MASK       (0x1000U)
#define CLKCTL0_PSCCTL0_CLR_SLEEPCON0_SHIFT      (12U)
/*! SLEEPCON0 - SLEEPCON0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL0_CLR_SLEEPCON0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_SLEEPCON0_SHIFT)) & CLKCTL0_PSCCTL0_CLR_SLEEPCON0_MASK)

#define CLKCTL0_PSCCTL0_CLR_SYSCON0_MASK         (0x2000U)
#define CLKCTL0_PSCCTL0_CLR_SYSCON0_SHIFT        (13U)
/*! SYSCON0 - SYSCON0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL0_CLR_SYSCON0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_SYSCON0_SHIFT)) & CLKCTL0_PSCCTL0_CLR_SYSCON0_MASK)

#define CLKCTL0_PSCCTL0_CLR_GLIKEY0_MASK         (0x4000U)
#define CLKCTL0_PSCCTL0_CLR_GLIKEY0_SHIFT        (14U)
/*! GLIKEY0 - GLIKEY0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL0_CLR_GLIKEY0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_GLIKEY0_SHIFT)) & CLKCTL0_PSCCTL0_CLR_GLIKEY0_MASK)

#define CLKCTL0_PSCCTL0_CLR_GLIKEY3_MASK         (0x8000U)
#define CLKCTL0_PSCCTL0_CLR_GLIKEY3_SHIFT        (15U)
/*! GLIKEY3 - GLIKEY3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL0_CLR_GLIKEY3(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL0_CLR_GLIKEY3_SHIFT)) & CLKCTL0_PSCCTL0_CLR_GLIKEY3_MASK)
/*! @} */

/*! @name PSCCTL1_CLR - VDD2_COMP Peripheral Clock Control 1 Clear */
/*! @{ */

#define CLKCTL0_PSCCTL1_CLR_TPIU_TRACE_CLKIN_MASK (0x4U)
#define CLKCTL0_PSCCTL1_CLR_TPIU_TRACE_CLKIN_SHIFT (2U)
/*! TPIU_TRACE_CLKIN - TPIU TRACE_CLKIN (TRACE_RT700)Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_TPIU_TRACE_CLKIN(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_TPIU_TRACE_CLKIN_SHIFT)) & CLKCTL0_PSCCTL1_CLR_TPIU_TRACE_CLKIN_MASK)

#define CLKCTL0_PSCCTL1_CLR_SWO_TRACECLKIN_MASK  (0x8U)
#define CLKCTL0_PSCCTL1_CLR_SWO_TRACECLKIN_SHIFT (3U)
/*! SWO_TRACECLKIN - SWO TRACECLKIN (TRACE_RT700) Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_SWO_TRACECLKIN(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_SWO_TRACECLKIN_SHIFT)) & CLKCTL0_PSCCTL1_CLR_SWO_TRACECLKIN_MASK)

#define CLKCTL0_PSCCTL1_CLR_TSCLK_MASK           (0x10U)
#define CLKCTL0_PSCCTL1_CLR_TSCLK_SHIFT          (4U)
/*! TSCLK - TS (TRACE_RT700) Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_TSCLK(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_TSCLK_SHIFT)) & CLKCTL0_PSCCTL1_CLR_TSCLK_MASK)

#define CLKCTL0_PSCCTL1_CLR_EDMA0_MASK           (0x20U)
#define CLKCTL0_PSCCTL1_CLR_EDMA0_SHIFT          (5U)
/*! eDMA0 - eDMA0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_EDMA0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_EDMA0_SHIFT)) & CLKCTL0_PSCCTL1_CLR_EDMA0_MASK)

#define CLKCTL0_PSCCTL1_CLR_EDMA1_MASK           (0x40U)
#define CLKCTL0_PSCCTL1_CLR_EDMA1_SHIFT          (6U)
/*! eDMA1 - eDMA1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_EDMA1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_EDMA1_SHIFT)) & CLKCTL0_PSCCTL1_CLR_EDMA1_MASK)

#define CLKCTL0_PSCCTL1_CLR_PKC_RAM_CTRL_MASK    (0x80U)
#define CLKCTL0_PSCCTL1_CLR_PKC_RAM_CTRL_SHIFT   (7U)
/*! PKC_RAM_CTRl - RAM CTRl Clock of PKC
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_PKC_RAM_CTRL(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_PKC_RAM_CTRL_SHIFT)) & CLKCTL0_PSCCTL1_CLR_PKC_RAM_CTRL_MASK)

#define CLKCTL0_PSCCTL1_CLR_PKC_MASK             (0x100U)
#define CLKCTL0_PSCCTL1_CLR_PKC_SHIFT            (8U)
/*! PKC - PKC Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_PKC(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_PKC_SHIFT)) & CLKCTL0_PSCCTL1_CLR_PKC_MASK)

#define CLKCTL0_PSCCTL1_CLR_ROMCP_MASK           (0x200U)
#define CLKCTL0_PSCCTL1_CLR_ROMCP_SHIFT          (9U)
/*! ROMCP - ROMCP Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_ROMCP(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_ROMCP_SHIFT)) & CLKCTL0_PSCCTL1_CLR_ROMCP_MASK)

#define CLKCTL0_PSCCTL1_CLR_XSPI0_MASK           (0x400U)
#define CLKCTL0_PSCCTL1_CLR_XSPI0_SHIFT          (10U)
/*! XSPI0 - XSPI0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_XSPI0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_XSPI0_SHIFT)) & CLKCTL0_PSCCTL1_CLR_XSPI0_MASK)

#define CLKCTL0_PSCCTL1_CLR_XSPI1_MASK           (0x800U)
#define CLKCTL0_PSCCTL1_CLR_XSPI1_SHIFT          (11U)
/*! XSPI1 - XSPI1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_XSPI1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_XSPI1_SHIFT)) & CLKCTL0_PSCCTL1_CLR_XSPI1_MASK)

#define CLKCTL0_PSCCTL1_CLR_CACHE64_0_MASK       (0x1000U)
#define CLKCTL0_PSCCTL1_CLR_CACHE64_0_SHIFT      (12U)
/*! CACHE64_0 - CACHE64_0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_CACHE64_0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_CACHE64_0_SHIFT)) & CLKCTL0_PSCCTL1_CLR_CACHE64_0_MASK)

#define CLKCTL0_PSCCTL1_CLR_CACHE64_1_MASK       (0x2000U)
#define CLKCTL0_PSCCTL1_CLR_CACHE64_1_SHIFT      (13U)
/*! CACHE64_1 - CACHE64_1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_CACHE64_1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_CACHE64_1_SHIFT)) & CLKCTL0_PSCCTL1_CLR_CACHE64_1_MASK)

#define CLKCTL0_PSCCTL1_CLR_QK_SUBSYS_MASK       (0x4000U)
#define CLKCTL0_PSCCTL1_CLR_QK_SUBSYS_SHIFT      (14U)
/*! QK_SUBSYS - QK_SUBSYS (PUF_CTRL) Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_QK_SUBSYS(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_QK_SUBSYS_SHIFT)) & CLKCTL0_PSCCTL1_CLR_QK_SUBSYS_MASK)

#define CLKCTL0_PSCCTL1_CLR_MMU0_MASK            (0x10000U)
#define CLKCTL0_PSCCTL1_CLR_MMU0_SHIFT           (16U)
/*! MMU0 - MMU0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_MMU0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_MMU0_SHIFT)) & CLKCTL0_PSCCTL1_CLR_MMU0_MASK)

#define CLKCTL0_PSCCTL1_CLR_MMU1_MASK            (0x20000U)
#define CLKCTL0_PSCCTL1_CLR_MMU1_SHIFT           (17U)
/*! MMU1 - MMU1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_MMU1(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_MMU1_SHIFT)) & CLKCTL0_PSCCTL1_CLR_MMU1_MASK)

#define CLKCTL0_PSCCTL1_CLR_GPIO0_MASK           (0x40000U)
#define CLKCTL0_PSCCTL1_CLR_GPIO0_SHIFT          (18U)
/*! GPIO0 - GPIO0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_GPIO0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_GPIO0_SHIFT)) & CLKCTL0_PSCCTL1_CLR_GPIO0_MASK)

#define CLKCTL0_PSCCTL1_CLR_GPIO1_MASK           (0x80000U)
#define CLKCTL0_PSCCTL1_CLR_GPIO1_SHIFT          (19U)
/*! GPIO1 - GPIO1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_GPIO1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_GPIO1_SHIFT)) & CLKCTL0_PSCCTL1_CLR_GPIO1_MASK)

#define CLKCTL0_PSCCTL1_CLR_GPIO2_MASK           (0x100000U)
#define CLKCTL0_PSCCTL1_CLR_GPIO2_SHIFT          (20U)
/*! GPIO2 - GPIO2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_GPIO2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_GPIO2_SHIFT)) & CLKCTL0_PSCCTL1_CLR_GPIO2_MASK)

#define CLKCTL0_PSCCTL1_CLR_GPIO3_MASK           (0x200000U)
#define CLKCTL0_PSCCTL1_CLR_GPIO3_SHIFT          (21U)
/*! GPIO3 - GPIO3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_GPIO3(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_GPIO3_SHIFT)) & CLKCTL0_PSCCTL1_CLR_GPIO3_MASK)

#define CLKCTL0_PSCCTL1_CLR_GPIO4_MASK           (0x400000U)
#define CLKCTL0_PSCCTL1_CLR_GPIO4_SHIFT          (22U)
/*! GPIO4 - GPIO4 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_GPIO4(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_GPIO4_SHIFT)) & CLKCTL0_PSCCTL1_CLR_GPIO4_MASK)

#define CLKCTL0_PSCCTL1_CLR_GPIO5_MASK           (0x800000U)
#define CLKCTL0_PSCCTL1_CLR_GPIO5_SHIFT          (23U)
/*! GPIO5 - GPIO5 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_GPIO5(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_GPIO5_SHIFT)) & CLKCTL0_PSCCTL1_CLR_GPIO5_MASK)

#define CLKCTL0_PSCCTL1_CLR_GPIO6_MASK           (0x1000000U)
#define CLKCTL0_PSCCTL1_CLR_GPIO6_SHIFT          (24U)
/*! GPIO6 - GPIO6 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_GPIO6(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_GPIO6_SHIFT)) & CLKCTL0_PSCCTL1_CLR_GPIO6_MASK)

#define CLKCTL0_PSCCTL1_CLR_GPIO7_MASK           (0x2000000U)
#define CLKCTL0_PSCCTL1_CLR_GPIO7_SHIFT          (25U)
/*! GPIO7 - GPIO7 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_GPIO7(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_GPIO7_SHIFT)) & CLKCTL0_PSCCTL1_CLR_GPIO7_MASK)

#define CLKCTL0_PSCCTL1_CLR_SCT0_MASK            (0x4000000U)
#define CLKCTL0_PSCCTL1_CLR_SCT0_SHIFT           (26U)
/*! SCT0 - SCT0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_SCT0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_SCT0_SHIFT)) & CLKCTL0_PSCCTL1_CLR_SCT0_MASK)

#define CLKCTL0_PSCCTL1_CLR_CDOG0_MASK           (0x8000000U)
#define CLKCTL0_PSCCTL1_CLR_CDOG0_SHIFT          (27U)
/*! CDOG0 - CDOG0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_CDOG0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_CDOG0_SHIFT)) & CLKCTL0_PSCCTL1_CLR_CDOG0_MASK)

#define CLKCTL0_PSCCTL1_CLR_CDOG1_MASK           (0x10000000U)
#define CLKCTL0_PSCCTL1_CLR_CDOG1_SHIFT          (28U)
/*! CDOG1 - CDOG1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_CDOG1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_CDOG1_SHIFT)) & CLKCTL0_PSCCTL1_CLR_CDOG1_MASK)

#define CLKCTL0_PSCCTL1_CLR_CDOG2_MASK           (0x20000000U)
#define CLKCTL0_PSCCTL1_CLR_CDOG2_SHIFT          (29U)
/*! CDOG2 - CDOG2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_CDOG2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_CDOG2_SHIFT)) & CLKCTL0_PSCCTL1_CLR_CDOG2_MASK)

#define CLKCTL0_PSCCTL1_CLR_LP_FLEXCOMM0_MASK    (0x40000000U)
#define CLKCTL0_PSCCTL1_CLR_LP_FLEXCOMM0_SHIFT   (30U)
/*! LP_FLEXCOMM0 - LP_FLEXCOMM0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_LP_FLEXCOMM0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_LP_FLEXCOMM0_SHIFT)) & CLKCTL0_PSCCTL1_CLR_LP_FLEXCOMM0_MASK)

#define CLKCTL0_PSCCTL1_CLR_LP_FLEXCOMM1_MASK    (0x80000000U)
#define CLKCTL0_PSCCTL1_CLR_LP_FLEXCOMM1_SHIFT   (31U)
/*! LP_FLEXCOMM1 - LP_FLEXCOMM1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL1_CLR_LP_FLEXCOMM1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL1_CLR_LP_FLEXCOMM1_SHIFT)) & CLKCTL0_PSCCTL1_CLR_LP_FLEXCOMM1_MASK)
/*! @} */

/*! @name PSCCTL2_CLR - VDD2_COMP Peripheral Clock Control 2 Clear */
/*! @{ */

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM2_MASK    (0x1U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM2_SHIFT   (0U)
/*! LP_FLEXCOMM2 - LP_FLEXCOMM2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM2(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM2_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM2_MASK)

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM3_MASK    (0x2U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM3_SHIFT   (1U)
/*! LP_FLEXCOMM3 - LP_FLEXCOMM3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM3(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM3_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM3_MASK)

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM4_MASK    (0x4U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM4_SHIFT   (2U)
/*! LP_FLEXCOMM4 - LP_FLEXCOMM4 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM4(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM4_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM4_MASK)

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM5_MASK    (0x8U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM5_SHIFT   (3U)
/*! LP_FLEXCOMM5 - LP_FLEXCOMM5 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM5(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM5_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM5_MASK)

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM6_MASK    (0x10U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM6_SHIFT   (4U)
/*! LP_FLEXCOMM6 - LP_FLEXCOMM6 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM6(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM6_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM6_MASK)

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM7_MASK    (0x20U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM7_SHIFT   (5U)
/*! LP_FLEXCOMM7 - LP_FLEXCOMM7 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM7(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM7_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM7_MASK)

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM8_MASK    (0x40U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM8_SHIFT   (6U)
/*! LP_FLEXCOMM8 - LP_FLEXCOMM8 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM8(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM8_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM8_MASK)

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM9_MASK    (0x80U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM9_SHIFT   (7U)
/*! LP_FLEXCOMM9 - LP_FLEXCOMM9 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM9(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM9_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM9_MASK)

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM10_MASK   (0x100U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM10_SHIFT  (8U)
/*! LP_FLEXCOMM10 - LP_FLEXCOMM10 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM10(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM10_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM10_MASK)

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM11_MASK   (0x200U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM11_SHIFT  (9U)
/*! LP_FLEXCOMM11 - LP_FLEXCOMM11 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM11(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM11_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM11_MASK)

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM12_MASK   (0x400U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM12_SHIFT  (10U)
/*! LP_FLEXCOMM12 - LP_FLEXCOMM12 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM12(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM12_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM12_MASK)

#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM13_MASK   (0x800U)
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM13_SHIFT  (11U)
/*! LP_FLEXCOMM13 - LP_FLEXCOMM13 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM13(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM13_SHIFT)) & CLKCTL0_PSCCTL2_CLR_LP_FLEXCOMM13_MASK)

#define CLKCTL0_PSCCTL2_CLR_SAI0_MASK            (0x2000U)
#define CLKCTL0_PSCCTL2_CLR_SAI0_SHIFT           (13U)
/*! SAI0 - SAI0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_SAI0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_SAI0_SHIFT)) & CLKCTL0_PSCCTL2_CLR_SAI0_MASK)

#define CLKCTL0_PSCCTL2_CLR_SAI1_MASK            (0x4000U)
#define CLKCTL0_PSCCTL2_CLR_SAI1_SHIFT           (14U)
/*! SAI1 - SAI1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_SAI1(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_SAI1_SHIFT)) & CLKCTL0_PSCCTL2_CLR_SAI1_MASK)

#define CLKCTL0_PSCCTL2_CLR_SAI2_MASK            (0x8000U)
#define CLKCTL0_PSCCTL2_CLR_SAI2_SHIFT           (15U)
/*! SAI2 - SAI2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_SAI2(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_SAI2_SHIFT)) & CLKCTL0_PSCCTL2_CLR_SAI2_MASK)

#define CLKCTL0_PSCCTL2_CLR_I3C0_MASK            (0x10000U)
#define CLKCTL0_PSCCTL2_CLR_I3C0_SHIFT           (16U)
/*! I3C0 - I3C0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_I3C0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_I3C0_SHIFT)) & CLKCTL0_PSCCTL2_CLR_I3C0_MASK)

#define CLKCTL0_PSCCTL2_CLR_I3C1_MASK            (0x20000U)
#define CLKCTL0_PSCCTL2_CLR_I3C1_SHIFT           (17U)
/*! I3C1 - I3C1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_I3C1(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_I3C1_SHIFT)) & CLKCTL0_PSCCTL2_CLR_I3C1_MASK)

#define CLKCTL0_PSCCTL2_CLR_CRC0_MASK            (0x40000U)
#define CLKCTL0_PSCCTL2_CLR_CRC0_SHIFT           (18U)
/*! CRC0 - CRC0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_CRC0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_CRC0_SHIFT)) & CLKCTL0_PSCCTL2_CLR_CRC0_MASK)

#define CLKCTL0_PSCCTL2_CLR_WWDT0_MASK           (0x80000U)
#define CLKCTL0_PSCCTL2_CLR_WWDT0_SHIFT          (19U)
/*! WWDT0 - WWDT0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_WWDT0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_WWDT0_SHIFT)) & CLKCTL0_PSCCTL2_CLR_WWDT0_MASK)

#define CLKCTL0_PSCCTL2_CLR_WWDT1_MASK           (0x100000U)
#define CLKCTL0_PSCCTL2_CLR_WWDT1_SHIFT          (20U)
/*! WWDT1 - WWDT1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_WWDT1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_WWDT1_SHIFT)) & CLKCTL0_PSCCTL2_CLR_WWDT1_MASK)

#define CLKCTL0_PSCCTL2_CLR_CTIMER0_MASK         (0x200000U)
#define CLKCTL0_PSCCTL2_CLR_CTIMER0_SHIFT        (21U)
/*! CTIMER0 - CTIMER0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_CTIMER0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_CTIMER0_SHIFT)) & CLKCTL0_PSCCTL2_CLR_CTIMER0_MASK)

#define CLKCTL0_PSCCTL2_CLR_CTIMER1_MASK         (0x400000U)
#define CLKCTL0_PSCCTL2_CLR_CTIMER1_SHIFT        (22U)
/*! CTIMER1 - CTIMER1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_CTIMER1(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_CTIMER1_SHIFT)) & CLKCTL0_PSCCTL2_CLR_CTIMER1_MASK)

#define CLKCTL0_PSCCTL2_CLR_CTIMER2_MASK         (0x800000U)
#define CLKCTL0_PSCCTL2_CLR_CTIMER2_SHIFT        (23U)
/*! CTIMER2 - CTIMER2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_CTIMER2(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_CTIMER2_SHIFT)) & CLKCTL0_PSCCTL2_CLR_CTIMER2_MASK)

#define CLKCTL0_PSCCTL2_CLR_CTIMER3_MASK         (0x1000000U)
#define CLKCTL0_PSCCTL2_CLR_CTIMER3_SHIFT        (24U)
/*! CTIMER3 - CTIMER3 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_CTIMER3(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_CTIMER3_SHIFT)) & CLKCTL0_PSCCTL2_CLR_CTIMER3_MASK)

#define CLKCTL0_PSCCTL2_CLR_CTIMER4_MASK         (0x2000000U)
#define CLKCTL0_PSCCTL2_CLR_CTIMER4_SHIFT        (25U)
/*! CTIMER4 - CTIMER4 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_CTIMER4(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_CTIMER4_SHIFT)) & CLKCTL0_PSCCTL2_CLR_CTIMER4_MASK)

#define CLKCTL0_PSCCTL2_CLR_MRT0_MASK            (0x4000000U)
#define CLKCTL0_PSCCTL2_CLR_MRT0_SHIFT           (26U)
/*! MRT0 - MRT0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_MRT0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_MRT0_SHIFT)) & CLKCTL0_PSCCTL2_CLR_MRT0_MASK)

#define CLKCTL0_PSCCTL2_CLR_UTICK0_MASK          (0x8000000U)
#define CLKCTL0_PSCCTL2_CLR_UTICK0_SHIFT         (27U)
/*! UTICK0 - UTICK0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_UTICK0(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_UTICK0_SHIFT)) & CLKCTL0_PSCCTL2_CLR_UTICK0_MASK)

#define CLKCTL0_PSCCTL2_CLR_SEMA42_4_MASK        (0x40000000U)
#define CLKCTL0_PSCCTL2_CLR_SEMA42_4_SHIFT       (30U)
/*! SEMA42_4 - SEMA42_4 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_SEMA42_4(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_SEMA42_4_SHIFT)) & CLKCTL0_PSCCTL2_CLR_SEMA42_4_MASK)

#define CLKCTL0_PSCCTL2_CLR_MU4_MASK             (0x80000000U)
#define CLKCTL0_PSCCTL2_CLR_MU4_SHIFT            (31U)
/*! MU4 - MU4 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL2_CLR_MU4(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL2_CLR_MU4_SHIFT)) & CLKCTL0_PSCCTL2_CLR_MU4_MASK)
/*! @} */

/*! @name PSCCTL3_CLR - VDD2_COMP Peripheral Clock Control 3 Clear */
/*! @{ */

#define CLKCTL0_PSCCTL3_CLR_PINT0_MASK           (0x20U)
#define CLKCTL0_PSCCTL3_CLR_PINT0_SHIFT          (5U)
/*! PINT0 - PINT0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL3_CLR_PINT0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CLR_PINT0_SHIFT)) & CLKCTL0_PSCCTL3_CLR_PINT0_MASK)

#define CLKCTL0_PSCCTL3_CLR_FREQME0_MASK         (0x100U)
#define CLKCTL0_PSCCTL3_CLR_FREQME0_SHIFT        (8U)
/*! FREQME0 - FREQME0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL3_CLR_FREQME0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CLR_FREQME0_SHIFT)) & CLKCTL0_PSCCTL3_CLR_FREQME0_MASK)

#define CLKCTL0_PSCCTL3_CLR_INPUTMUX0_MASK       (0x400U)
#define CLKCTL0_PSCCTL3_CLR_INPUTMUX0_SHIFT      (10U)
/*! INPUTMUX0 - INPUTMUX0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL3_CLR_INPUTMUX0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CLR_INPUTMUX0_SHIFT)) & CLKCTL0_PSCCTL3_CLR_INPUTMUX0_MASK)

#define CLKCTL0_PSCCTL3_CLR_SAFO_SGI_MASK        (0x1000U)
#define CLKCTL0_PSCCTL3_CLR_SAFO_SGI_SHIFT       (12U)
/*! SAFO_SGI - SAFO_SGI Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL3_CLR_SAFO_SGI(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CLR_SAFO_SGI_SHIFT)) & CLKCTL0_PSCCTL3_CLR_SAFO_SGI_MASK)

#define CLKCTL0_PSCCTL3_CLR_TRACE_MASK           (0x2000U)
#define CLKCTL0_PSCCTL3_CLR_TRACE_SHIFT          (13U)
/*! TRACE - TRACE Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL3_CLR_TRACE(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CLR_TRACE_SHIFT)) & CLKCTL0_PSCCTL3_CLR_TRACE_MASK)

#define CLKCTL0_PSCCTL3_CLR_PRINCE0_MASK         (0x8000U)
#define CLKCTL0_PSCCTL3_CLR_PRINCE0_SHIFT        (15U)
/*! PRINCE0 - PRINCE0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL3_CLR_PRINCE0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CLR_PRINCE0_SHIFT)) & CLKCTL0_PSCCTL3_CLR_PRINCE0_MASK)

#define CLKCTL0_PSCCTL3_CLR_PRINCE1_MASK         (0x10000U)
#define CLKCTL0_PSCCTL3_CLR_PRINCE1_SHIFT        (16U)
/*! PRINCE1 - PRINCE1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL3_CLR_PRINCE1(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CLR_PRINCE1_SHIFT)) & CLKCTL0_PSCCTL3_CLR_PRINCE1_MASK)

#define CLKCTL0_PSCCTL3_CLR_XSPI1_PRINCE_XEX_MASK (0x20000U)
#define CLKCTL0_PSCCTL3_CLR_XSPI1_PRINCE_XEX_SHIFT (17U)
/*! XSPI1_PRINCE_XEX - XSPI1 PRINCE_XEX Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL3_CLR_XSPI1_PRINCE_XEX(x)  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CLR_XSPI1_PRINCE_XEX_SHIFT)) & CLKCTL0_PSCCTL3_CLR_XSPI1_PRINCE_XEX_MASK)

#define CLKCTL0_PSCCTL3_CLR_CMX_PERFMON0_MASK    (0x40000U)
#define CLKCTL0_PSCCTL3_CLR_CMX_PERFMON0_SHIFT   (18U)
/*! CMX_PERFMON0 - CMX_PERFMON0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL3_CLR_CMX_PERFMON0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CLR_CMX_PERFMON0_SHIFT)) & CLKCTL0_PSCCTL3_CLR_CMX_PERFMON0_MASK)

#define CLKCTL0_PSCCTL3_CLR_CMX_PERFMON1_MASK    (0x80000U)
#define CLKCTL0_PSCCTL3_CLR_CMX_PERFMON1_SHIFT   (19U)
/*! CMX_PERFMON1 - CMX_PERFMON1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL3_CLR_CMX_PERFMON1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL3_CLR_CMX_PERFMON1_SHIFT)) & CLKCTL0_PSCCTL3_CLR_CMX_PERFMON1_MASK)
/*! @} */

/*! @name PSCCTL4_CLR - VDD2_COMP Peripheral Clock Control 4 Clear */
/*! @{ */

#define CLKCTL0_PSCCTL4_CLR_HIFI4_MASK           (0x1U)
#define CLKCTL0_PSCCTL4_CLR_HIFI4_SHIFT          (0U)
/*! HiFi4 - HiFi4 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL4_CLR_HIFI4(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL4_CLR_HIFI4_SHIFT)) & CLKCTL0_PSCCTL4_CLR_HIFI4_MASK)
/*! @} */

/*! @name PSCCTL5_CLR - VDD2_COMP Peripheral Clock Control 5 Clear */
/*! @{ */

#define CLKCTL0_PSCCTL5_CLR_NPU0_MASK            (0x1U)
#define CLKCTL0_PSCCTL5_CLR_NPU0_SHIFT           (0U)
/*! NPU0 - NPU0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL5_CLR_NPU0(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_CLR_NPU0_SHIFT)) & CLKCTL0_PSCCTL5_CLR_NPU0_MASK)

#define CLKCTL0_PSCCTL5_CLR_COMP_ACCESS_RAM_ARBITER1_MASK (0x4U)
#define CLKCTL0_PSCCTL5_CLR_COMP_ACCESS_RAM_ARBITER1_SHIFT (2U)
/*! COMP_ACCESS_RAM_ARBITER1 - VDD2_COMP Access RAM Arbiter1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL5_CLR_COMP_ACCESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_CLR_COMP_ACCESS_RAM_ARBITER1_SHIFT)) & CLKCTL0_PSCCTL5_CLR_COMP_ACCESS_RAM_ARBITER1_MASK)

#define CLKCTL0_PSCCTL5_CLR_IOPCTL0_MASK         (0x8U)
#define CLKCTL0_PSCCTL5_CLR_IOPCTL0_SHIFT        (3U)
/*! IOPCTL0 - IOPCTL0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL5_CLR_IOPCTL0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_CLR_IOPCTL0_SHIFT)) & CLKCTL0_PSCCTL5_CLR_IOPCTL0_MASK)

#define CLKCTL0_PSCCTL5_CLR_HIFI4_ACCESS_RAM_ARBITER1_MASK (0x10U)
#define CLKCTL0_PSCCTL5_CLR_HIFI4_ACCESS_RAM_ARBITER1_SHIFT (4U)
/*! HiFi4_ACCESS_RAM_ARBITER1 - HiFi4 Access RAM Arbiter1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL5_CLR_HIFI4_ACCESS_RAM_ARBITER1(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_CLR_HIFI4_ACCESS_RAM_ARBITER1_SHIFT)) & CLKCTL0_PSCCTL5_CLR_HIFI4_ACCESS_RAM_ARBITER1_MASK)

#define CLKCTL0_PSCCTL5_CLR_MEDIA_ACCESS_RAM_ARBITER0_MASK (0x20U)
#define CLKCTL0_PSCCTL5_CLR_MEDIA_ACCESS_RAM_ARBITER0_SHIFT (5U)
/*! MEDIA_ACCESS_RAM_ARBITER0 - VDD2_Media Access RAM Arbiter0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL0_PSCCTL5_CLR_MEDIA_ACCESS_RAM_ARBITER0(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_PSCCTL5_CLR_MEDIA_ACCESS_RAM_ARBITER0_SHIFT)) & CLKCTL0_PSCCTL5_CLR_MEDIA_ACCESS_RAM_ARBITER0_MASK)
/*! @} */

/*! @name ONE_SRC_CLKSLICE_ENABLE - One Source Clock Slice Enable */
/*! @{ */

#define CLKCTL0_ONE_SRC_CLKSLICE_ENABLE_DGDET0_FCLK_EN_MASK (0x1U)
#define CLKCTL0_ONE_SRC_CLKSLICE_ENABLE_DGDET0_FCLK_EN_SHIFT (0U)
/*! dGDET0_FCLK_EN - dGDET0 Functional Clock Enable
 *  0b0..Gates dGDET0 functional clock.
 *  0b1..Enables dGDET0 functional clock.
 */
#define CLKCTL0_ONE_SRC_CLKSLICE_ENABLE_DGDET0_FCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_ONE_SRC_CLKSLICE_ENABLE_DGDET0_FCLK_EN_SHIFT)) & CLKCTL0_ONE_SRC_CLKSLICE_ENABLE_DGDET0_FCLK_EN_MASK)
/*! @} */

/*! @name FRO01CLKSTATUS - FRO_TUNER0 and FRO_TUNER1 Clock Status */
/*! @{ */

#define CLKCTL0_FRO01CLKSTATUS_FRO1_CLK_OK_MASK  (0x1U)
#define CLKCTL0_FRO01CLKSTATUS_FRO1_CLK_OK_SHIFT (0U)
/*! FRO1_CLK_OK - FRO_TUNER1 Clock OK
 *  0b0..FRO_TUNER1 clock has not yet reached its final frequency.
 *  0b1..FRO_TUNER1 clock has reached its final frequency.
 */
#define CLKCTL0_FRO01CLKSTATUS_FRO1_CLK_OK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO01CLKSTATUS_FRO1_CLK_OK_SHIFT)) & CLKCTL0_FRO01CLKSTATUS_FRO1_CLK_OK_MASK)

#define CLKCTL0_FRO01CLKSTATUS_FRO0_CLK_OK_MASK  (0x2U)
#define CLKCTL0_FRO01CLKSTATUS_FRO0_CLK_OK_SHIFT (1U)
/*! FRO0_CLK_OK - FRO_TUNER0 Clock OK
 *  0b0..FRO_TUNER0 clock has not yet reached its final frequency.
 *  0b1..FRO_TUNER0 clock has reached its final frequency.
 */
#define CLKCTL0_FRO01CLKSTATUS_FRO0_CLK_OK(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO01CLKSTATUS_FRO0_CLK_OK_SHIFT)) & CLKCTL0_FRO01CLKSTATUS_FRO0_CLK_OK_MASK)
/*! @} */

/*! @name FRO0MAXDOMAINEN - FRO0MAX Clock Domain Enable */
/*! @{ */

#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_CMPT_MASK (0x1U)
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_CMPT_SHIFT (0U)
/*! FRO0MAX_OF_CMPT - fro0_max Clock of VDD2_COMP
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_CMPT(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_CMPT_SHIFT)) & CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_CMPT_MASK)

#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_SENSE_MASK (0x2U)
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_SENSE_SHIFT (1U)
/*! FRO0MAX_OF_SENSE - fro0_max Clock of VDD1_SENSE Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_SENSE(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_SENSE_SHIFT)) & CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_SENSE_MASK)

#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_VDD2_DSP_MASK (0x4U)
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_VDD2_DSP_SHIFT (2U)
/*! FRO0MAX_OF_VDD2_DSP - fro0_max Clock of VDD2_DSP Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_VDD2_DSP(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_VDD2_DSP_SHIFT)) & CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_VDD2_DSP_MASK)

#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_MD2_MASK (0x8U)
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_MD2_SHIFT (3U)
/*! FRO0MAX_OF_MD2 - fro0_max Clock of VDD2_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_MD2(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_MD2_SHIFT)) & CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_MD2_MASK)

#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_MDN_MASK (0x10U)
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_MDN_SHIFT (4U)
/*! FRO0MAX_OF_MDN - fro0_max Clock of VDDN_MEDIA Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_MDN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_MDN_SHIFT)) & CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_MDN_MASK)

#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_VDD2_COM_MASK (0x20U)
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_VDD2_COM_SHIFT (5U)
/*! FRO0MAX_OF_VDD2_COM - fro0_max Clock of VDD2_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_VDD2_COM(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_VDD2_COM_SHIFT)) & CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_VDD2_COM_MASK)

#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_COMN_MASK (0x40U)
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_COMN_SHIFT (6U)
/*! FRO0MAX_OF_COMN - fro0_max Clock of VDDN_COM Domain
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_COMN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_COMN_SHIFT)) & CLKCTL0_FRO0MAXDOMAINEN_FRO0MAX_OF_COMN_MASK)
/*! @} */

/*! @name MAINCLKDIV - VDD2_COMP Main Clock Divider */
/*! @{ */

#define CLKCTL0_MAINCLKDIV_DIV_MASK              (0xFFU)
#define CLKCTL0_MAINCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_MAINCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINCLKDIV_DIV_SHIFT)) & CLKCTL0_MAINCLKDIV_DIV_MASK)

#define CLKCTL0_MAINCLKDIV_BUSY_MASK             (0x10000000U)
#define CLKCTL0_MAINCLKDIV_BUSY_SHIFT            (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_MAINCLKDIV_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINCLKDIV_BUSY_SHIFT)) & CLKCTL0_MAINCLKDIV_BUSY_MASK)

#define CLKCTL0_MAINCLKDIV_REQFLAG_MASK          (0x80000000U)
#define CLKCTL0_MAINCLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_MAINCLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_MAINCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CMPTBASECLKSEL - VDD2_COMP Base Clock Select Source */
/*! @{ */

#define CLKCTL0_CMPTBASECLKSEL_SEL_MASK          (0x3U)
#define CLKCTL0_CMPTBASECLKSEL_SEL_SHIFT         (0U)
/*! SEL - VDD2_COMP Base Clock Select Source
 *  0b00..fro1_div3
 *  0b01..fro1_max
 *  0b10..fro0_div3
 *  0b11..1m_lposc
 */
#define CLKCTL0_CMPTBASECLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CMPTBASECLKSEL_SEL_SHIFT)) & CLKCTL0_CMPTBASECLKSEL_SEL_MASK)
/*! @} */

/*! @name DSPBASECLKSEL - VDD2_DSP Base Clock Select Source */
/*! @{ */

#define CLKCTL0_DSPBASECLKSEL_SEL_MASK           (0x3U)
#define CLKCTL0_DSPBASECLKSEL_SEL_SHIFT          (0U)
/*! SEL - VDD2_DSP Base Clock Select Source
 *  0b00..fro1_div3
 *  0b01..fro1_max
 *  0b10..fro0_div3
 *  0b11..1m_lposc
 */
#define CLKCTL0_DSPBASECLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPBASECLKSEL_SEL_SHIFT)) & CLKCTL0_DSPBASECLKSEL_SEL_MASK)
/*! @} */

/*! @name VDD2COMBASECLKSEL - VDD2_COM Base Clock Select Source */
/*! @{ */

#define CLKCTL0_VDD2COMBASECLKSEL_SEL_MASK       (0x3U)
#define CLKCTL0_VDD2COMBASECLKSEL_SEL_SHIFT      (0U)
/*! SEL - VDD2_COM Base Clock Select Source
 *  0b00..fro1_div3
 *  0b01..fro1_max
 *  0b10..fro0_div3
 *  0b11..1m_lposc
 */
#define CLKCTL0_VDD2COMBASECLKSEL_SEL(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_VDD2COMBASECLKSEL_SEL_SHIFT)) & CLKCTL0_VDD2COMBASECLKSEL_SEL_MASK)
/*! @} */

/*! @name MAINCLKSEL - VDD2_COMP Main Clock Source Select */
/*! @{ */

#define CLKCTL0_MAINCLKSEL_SEL_MASK              (0x3U)
#define CLKCTL0_MAINCLKSEL_SEL_SHIFT             (0U)
/*! SEL - VDD2_COMP Main Clock Select Source
 *  0b00..baseclk_cmpt
 *  0b01..main_pll_pfd0
 *  0b10..fro0_max
 *  0b11..audio_pll_pfd1
 */
#define CLKCTL0_MAINCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_MAINCLKSEL_SEL_SHIFT)) & CLKCTL0_MAINCLKSEL_SEL_MASK)
/*! @} */

/*! @name DSPCPUCLKDIV - VDD2_DSP Clock Divider */
/*! @{ */

#define CLKCTL0_DSPCPUCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_DSPCPUCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_DSPCPUCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPCPUCLKDIV_DIV_SHIFT)) & CLKCTL0_DSPCPUCLKDIV_DIV_MASK)

#define CLKCTL0_DSPCPUCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL0_DSPCPUCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_DSPCPUCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPCPUCLKDIV_BUSY_SHIFT)) & CLKCTL0_DSPCPUCLKDIV_BUSY_MASK)

#define CLKCTL0_DSPCPUCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_DSPCPUCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_DSPCPUCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPCPUCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_DSPCPUCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DSPCPUCLKSEL - VDD2_DSP Clock Select Source */
/*! @{ */

#define CLKCTL0_DSPCPUCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL0_DSPCPUCLKSEL_SEL_SHIFT           (0U)
/*! SEL - VDD2_DSP Clock Select Source
 *  0b00..baseclk_dsp
 *  0b01..main_pll_pfd0
 *  0b10..fro0_max
 *  0b11..main_pll_pfd1
 */
#define CLKCTL0_DSPCPUCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPCPUCLKSEL_SEL_SHIFT)) & CLKCTL0_DSPCPUCLKSEL_SEL_MASK)

#define CLKCTL0_DSPCPUCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL0_DSPCPUCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates output of clock mux.
 *  0b1..Enables output of clock mux.
 */
#define CLKCTL0_DSPCPUCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_DSPCPUCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_DSPCPUCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name RAMCLKSEL - RAM Clock Select Source */
/*! @{ */

#define CLKCTL0_RAMCLKSEL_SEL_MASK               (0x3U)
#define CLKCTL0_RAMCLKSEL_SEL_SHIFT              (0U)
/*! SEL - RAM Clock Select Source
 *  0b00..baseclk_com2
 *  0b01..main_pll_pfd0
 *  0b10..fro0_max
 *  0b11..fro1_max
 */
#define CLKCTL0_RAMCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_RAMCLKSEL_SEL_SHIFT)) & CLKCTL0_RAMCLKSEL_SEL_MASK)
/*! @} */

/*! @name RAMCLKDIV - RAM Clock Divider */
/*! @{ */

#define CLKCTL0_RAMCLKDIV_DIV_MASK               (0xFFU)
#define CLKCTL0_RAMCLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_RAMCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_RAMCLKDIV_DIV_SHIFT)) & CLKCTL0_RAMCLKDIV_DIV_MASK)

#define CLKCTL0_RAMCLKDIV_BUSY_MASK              (0x10000000U)
#define CLKCTL0_RAMCLKDIV_BUSY_SHIFT             (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_RAMCLKDIV_BUSY(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_RAMCLKDIV_BUSY_SHIFT)) & CLKCTL0_RAMCLKDIV_BUSY_MASK)

#define CLKCTL0_RAMCLKDIV_REQFLAG_MASK           (0x80000000U)
#define CLKCTL0_RAMCLKDIV_REQFLAG_SHIFT          (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_RAMCLKDIV_REQFLAG(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_RAMCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_RAMCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name TPIUFCLKSEL - TPIU (TRACE_RT700) Functional Clock Select Source */
/*! @{ */

#define CLKCTL0_TPIUFCLKSEL_SEL_MASK             (0x3U)
#define CLKCTL0_TPIUFCLKSEL_SEL_SHIFT            (0U)
/*! SEL - TPIU (TRACE_RT700) Clock Select Source
 *  0b00..baseclk_cmpt
 *  0b01..main_pll_pfd0
 *  0b10..fro0_max
 *  0b11..fro0_div6
 */
#define CLKCTL0_TPIUFCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TPIUFCLKSEL_SEL_SHIFT)) & CLKCTL0_TPIUFCLKSEL_SEL_MASK)

#define CLKCTL0_TPIUFCLKSEL_SEL_EN_MASK          (0x4U)
#define CLKCTL0_TPIUFCLKSEL_SEL_EN_SHIFT         (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for TPIU clock.
 *  0b1..Enables mux output for TPIU clock.
 */
#define CLKCTL0_TPIUFCLKSEL_SEL_EN(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TPIUFCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_TPIUFCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name TPIUCLKDIV - TPIU (TRACE_RT700) Functional Clock Divider */
/*! @{ */

#define CLKCTL0_TPIUCLKDIV_DIV_MASK              (0xFFU)
#define CLKCTL0_TPIUCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_TPIUCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TPIUCLKDIV_DIV_SHIFT)) & CLKCTL0_TPIUCLKDIV_DIV_MASK)

#define CLKCTL0_TPIUCLKDIV_BUSY_MASK             (0x10000000U)
#define CLKCTL0_TPIUCLKDIV_BUSY_SHIFT            (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_TPIUCLKDIV_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TPIUCLKDIV_BUSY_SHIFT)) & CLKCTL0_TPIUCLKDIV_BUSY_MASK)

#define CLKCTL0_TPIUCLKDIV_RESET_MASK            (0x20000000U)
#define CLKCTL0_TPIUCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Reset Divider Counter
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL0_TPIUCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TPIUCLKDIV_RESET_SHIFT)) & CLKCTL0_TPIUCLKDIV_RESET_MASK)

#define CLKCTL0_TPIUCLKDIV_HALT_MASK             (0x40000000U)
#define CLKCTL0_TPIUCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halt Divider Counter
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL0_TPIUCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TPIUCLKDIV_HALT_SHIFT)) & CLKCTL0_TPIUCLKDIV_HALT_MASK)

#define CLKCTL0_TPIUCLKDIV_REQFLAG_MASK          (0x80000000U)
#define CLKCTL0_TPIUCLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_TPIUCLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TPIUCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_TPIUCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name XSPI0FCLKSEL - XSPI0 Functional Clock Source Select */
/*! @{ */

#define CLKCTL0_XSPI0FCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL0_XSPI0FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - XSPI0 Functional Clock Source Select
 *  0b00..baseclk_comn
 *  0b01..audio_pll_pfd0
 *  0b10..fro0_max
 *  0b11..main_pll_pfd1
 */
#define CLKCTL0_XSPI0FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_XSPI0FCLKSEL_SEL_SHIFT)) & CLKCTL0_XSPI0FCLKSEL_SEL_MASK)

#define CLKCTL0_XSPI0FCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL0_XSPI0FCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for XSPI0 clock.
 *  0b1..Enables mux output for XSPI0 clock.
 */
#define CLKCTL0_XSPI0FCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_XSPI0FCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_XSPI0FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name XSPI0FCLKDIV - XSPI0 Functional Clock Divider */
/*! @{ */

#define CLKCTL0_XSPI0FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_XSPI0FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_XSPI0FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_XSPI0FCLKDIV_DIV_SHIFT)) & CLKCTL0_XSPI0FCLKDIV_DIV_MASK)

#define CLKCTL0_XSPI0FCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL0_XSPI0FCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_XSPI0FCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_XSPI0FCLKDIV_BUSY_SHIFT)) & CLKCTL0_XSPI0FCLKDIV_BUSY_MASK)

#define CLKCTL0_XSPI0FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_XSPI0FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_XSPI0FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_XSPI0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_XSPI0FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name XSPI1FCLKSEL - XSPI1 Functional Clock Select Source */
/*! @{ */

#define CLKCTL0_XSPI1FCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL0_XSPI1FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Select Clock Source
 *  0b00..baseclk_comn
 *  0b01..audio_pll_pfd1
 *  0b10..fro0_max
 *  0b11..main_pll_pfd2
 */
#define CLKCTL0_XSPI1FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_XSPI1FCLKSEL_SEL_SHIFT)) & CLKCTL0_XSPI1FCLKSEL_SEL_MASK)

#define CLKCTL0_XSPI1FCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL0_XSPI1FCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for XSPI1 clock.
 *  0b1..Enables mux output for XSPI1 clock.
 */
#define CLKCTL0_XSPI1FCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_XSPI1FCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_XSPI1FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name XSPI1FCLKDIV - XSPI1 Functional Clock Divider */
/*! @{ */

#define CLKCTL0_XSPI1FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_XSPI1FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_XSPI1FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_XSPI1FCLKDIV_DIV_SHIFT)) & CLKCTL0_XSPI1FCLKDIV_DIV_MASK)

#define CLKCTL0_XSPI1FCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL0_XSPI1FCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_XSPI1FCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_XSPI1FCLKDIV_BUSY_SHIFT)) & CLKCTL0_XSPI1FCLKDIV_BUSY_MASK)

#define CLKCTL0_XSPI1FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_XSPI1FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_XSPI1FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_XSPI1FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_XSPI1FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SCTFCLKSEL - SCT Functional Clock Source Select */
/*! @{ */

#define CLKCTL0_SCTFCLKSEL_SEL_MASK              (0x3U)
#define CLKCTL0_SCTFCLKSEL_SEL_SHIFT             (0U)
/*! SEL - SCT Functional Clock Source Select
 *  0b00..baseclk_cmpt
 *  0b01..main_pll_pfd0
 *  0b10..fro0_max
 *  0b11..fro0_div6
 */
#define CLKCTL0_SCTFCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKSEL_SEL_SHIFT)) & CLKCTL0_SCTFCLKSEL_SEL_MASK)

#define CLKCTL0_SCTFCLKSEL_SEL_EN_MASK           (0x4U)
#define CLKCTL0_SCTFCLKSEL_SEL_EN_SHIFT          (2U)
/*! SEL_EN - Enable Clock Mux Output
 *  0b0..Gates mux output for SCT clock.
 *  0b1..Enables mux output for SCT clock.
 */
#define CLKCTL0_SCTFCLKSEL_SEL_EN(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_SCTFCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SCTFCLKDIV - SCT Functional Clock Divider */
/*! @{ */

#define CLKCTL0_SCTFCLKDIV_DIV_MASK              (0xFFU)
#define CLKCTL0_SCTFCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock Divider Value Selection */
#define CLKCTL0_SCTFCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKDIV_DIV_SHIFT)) & CLKCTL0_SCTFCLKDIV_DIV_MASK)

#define CLKCTL0_SCTFCLKDIV_BUSY_MASK             (0x10000000U)
#define CLKCTL0_SCTFCLKDIV_BUSY_SHIFT            (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_SCTFCLKDIV_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKDIV_BUSY_SHIFT)) & CLKCTL0_SCTFCLKDIV_BUSY_MASK)

#define CLKCTL0_SCTFCLKDIV_RESET_MASK            (0x20000000U)
#define CLKCTL0_SCTFCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Reset Divider Counter
 *  0b0..No effect
 *  0b1..Reset the divider counter
 */
#define CLKCTL0_SCTFCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKDIV_RESET_SHIFT)) & CLKCTL0_SCTFCLKDIV_RESET_MASK)

#define CLKCTL0_SCTFCLKDIV_HALT_MASK             (0x40000000U)
#define CLKCTL0_SCTFCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halt Divider Counter
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL0_SCTFCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKDIV_HALT_SHIFT)) & CLKCTL0_SCTFCLKDIV_HALT_MASK)

#define CLKCTL0_SCTFCLKDIV_REQFLAG_MASK          (0x80000000U)
#define CLKCTL0_SCTFCLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_SCTFCLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SCTFCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SCTFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name UTICK0FCLKSEL - UTICK0 Functional Clock Select Source */
/*! @{ */

#define CLKCTL0_UTICK0FCLKSEL_SEL_MASK           (0x3U)
#define CLKCTL0_UTICK0FCLKSEL_SEL_SHIFT          (0U)
/*! SEL - Select Clock Source
 *  0b00..baseclk_cmpt
 *  0b01..1m_lposc
 *  0b10..fro0_max
 *  0b11..fro1_div2
 */
#define CLKCTL0_UTICK0FCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_UTICK0FCLKSEL_SEL_SHIFT)) & CLKCTL0_UTICK0FCLKSEL_SEL_MASK)

#define CLKCTL0_UTICK0FCLKSEL_SEL_EN_MASK        (0x4U)
#define CLKCTL0_UTICK0FCLKSEL_SEL_EN_SHIFT       (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for UTICK0 clock.
 *  0b1..Enables mux output for UTICK0 clock.
 */
#define CLKCTL0_UTICK0FCLKSEL_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_UTICK0FCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_UTICK0FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name UTICK0FCLKDIV - UTICK0 Functional Clock Divider */
/*! @{ */

#define CLKCTL0_UTICK0FCLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL0_UTICK0FCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_UTICK0FCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_UTICK0FCLKDIV_DIV_SHIFT)) & CLKCTL0_UTICK0FCLKDIV_DIV_MASK)

#define CLKCTL0_UTICK0FCLKDIV_BUSY_MASK          (0x10000000U)
#define CLKCTL0_UTICK0FCLKDIV_BUSY_SHIFT         (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_UTICK0FCLKDIV_BUSY(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_UTICK0FCLKDIV_BUSY_SHIFT)) & CLKCTL0_UTICK0FCLKDIV_BUSY_MASK)

#define CLKCTL0_UTICK0FCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL0_UTICK0FCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset Divider Counter
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL0_UTICK0FCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_UTICK0FCLKDIV_RESET_SHIFT)) & CLKCTL0_UTICK0FCLKDIV_RESET_MASK)

#define CLKCTL0_UTICK0FCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL0_UTICK0FCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt Divider Counter
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL0_UTICK0FCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_UTICK0FCLKDIV_HALT_SHIFT)) & CLKCTL0_UTICK0FCLKDIV_HALT_MASK)

#define CLKCTL0_UTICK0FCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL0_UTICK0FCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_UTICK0FCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_UTICK0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_UTICK0FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name WWDT0FCLKSEL - WWDT0 Functional Clock Source Select */
/*! @{ */

#define CLKCTL0_WWDT0FCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL0_WWDT0FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Select Clock Source
 *  0b00..1m_lposc
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CLKCTL0_WWDT0FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_WWDT0FCLKSEL_SEL_SHIFT)) & CLKCTL0_WWDT0FCLKSEL_SEL_MASK)

#define CLKCTL0_WWDT0FCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL0_WWDT0FCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Enable Clock Mux Output
 *  0b0..Gates mux output for WWDT0 clock.
 *  0b1..Enables mux output for WWDT0 clock.
 */
#define CLKCTL0_WWDT0FCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_WWDT0FCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_WWDT0FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name WWDT1FCLKSEL - WWDT1 Functional Clock Source Select */
/*! @{ */

#define CLKCTL0_WWDT1FCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL0_WWDT1FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - WWDT1 Functional Clock Source Select
 *  0b00..1m_lposc
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define CLKCTL0_WWDT1FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_WWDT1FCLKSEL_SEL_SHIFT)) & CLKCTL0_WWDT1FCLKSEL_SEL_MASK)

#define CLKCTL0_WWDT1FCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL0_WWDT1FCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Enable Clock Mux Output
 *  0b0..Gates mux output for WWDT1 clock.
 *  0b1..Enables mux output for WWDT1 clock.
 */
#define CLKCTL0_WWDT1FCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_WWDT1FCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_WWDT1FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SYSTICKFCLKSEL - SYSTICK Functional Clock Source Select */
/*! @{ */

#define CLKCTL0_SYSTICKFCLKSEL_SEL_MASK          (0x3U)
#define CLKCTL0_SYSTICKFCLKSEL_SEL_SHIFT         (0U)
/*! SEL - Select Clock Source for SYSTICK
 *  0b00..baseclk_cmpt
 *  0b01..1m_lposc
 *  0b10..wake32k_clk (switch to other clock source before VDD2_COMP enters into the Deep Sleep Retention mode.)
 *  0b11..osc_clk
 */
#define CLKCTL0_SYSTICKFCLKSEL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKSEL_SEL_SHIFT)) & CLKCTL0_SYSTICKFCLKSEL_SEL_MASK)

#define CLKCTL0_SYSTICKFCLKSEL_SEL_EN_MASK       (0x4U)
#define CLKCTL0_SYSTICKFCLKSEL_SEL_EN_SHIFT      (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for SYSTICK clock.
 *  0b1..Enables mux output for SYSTICK clock.
 */
#define CLKCTL0_SYSTICKFCLKSEL_SEL_EN(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_SYSTICKFCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SYSTICKFCLKDIV - SYSTICK Functional Clock Divider */
/*! @{ */

#define CLKCTL0_SYSTICKFCLKDIV_DIV_MASK          (0xFFU)
#define CLKCTL0_SYSTICKFCLKDIV_DIV_SHIFT         (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_SYSTICKFCLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_DIV_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_DIV_MASK)

#define CLKCTL0_SYSTICKFCLKDIV_BUSY_MASK         (0x10000000U)
#define CLKCTL0_SYSTICKFCLKDIV_BUSY_SHIFT        (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_SYSTICKFCLKDIV_BUSY(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_BUSY_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_BUSY_MASK)

#define CLKCTL0_SYSTICKFCLKDIV_RESET_MASK        (0x20000000U)
#define CLKCTL0_SYSTICKFCLKDIV_RESET_SHIFT       (29U)
/*! RESET - Reset Divider Counter
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL0_SYSTICKFCLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_RESET_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_RESET_MASK)

#define CLKCTL0_SYSTICKFCLKDIV_HALT_MASK         (0x40000000U)
#define CLKCTL0_SYSTICKFCLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halt Divider Counter
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL0_SYSTICKFCLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_HALT_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_HALT_MASK)

#define CLKCTL0_SYSTICKFCLKDIV_REQFLAG_MASK      (0x80000000U)
#define CLKCTL0_SYSTICKFCLKDIV_REQFLAG_SHIFT     (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_SYSTICKFCLKDIV_REQFLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SYSTICKFCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SYSTICKFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name FCCLKSEL - LP_FLEXCOMM 0 to 13 Clock Source 0 Select..LP_FLEXCOMM 0 to 13 Clock Source 3 Select */
/*! @{ */

#define CLKCTL0_FCCLKSEL_SEL_MASK                (0x3U)
#define CLKCTL0_FCCLKSEL_SEL_SHIFT               (0U)
/*! SEL - LP_FLEXCOMM 0 to 13 Source Clock 3 Select
 *  0b00..baseclk_cmpt
 *  0b01..fro0_max
 *  0b10..main_pll_pfd3
 *  0b11..osc_clk
 */
#define CLKCTL0_FCCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FCCLKSEL_SEL_SHIFT)) & CLKCTL0_FCCLKSEL_SEL_MASK)

#define CLKCTL0_FCCLKSEL_SEL_EN_MASK             (0x4U)
#define CLKCTL0_FCCLKSEL_SEL_EN_SHIFT            (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for FC clock 0.
 *  0b1..Enables mux output for FC clock 0.
 */
#define CLKCTL0_FCCLKSEL_SEL_EN(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FCCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_FCCLKSEL_SEL_EN_MASK)
/*! @} */

/* The count of CLKCTL0_FCCLKSEL */
#define CLKCTL0_FCCLKSEL_COUNT                   (14U)

/*! @name FCCLKDIV - LP_FLEXCOMM 0 to 13 Clock Source 0 Divider..LP_FLEXCOMM 0 to 13 Clock Source 3 Divider */
/*! @{ */

#define CLKCTL0_FCCLKDIV_DIV_MASK                (0xFFU)
#define CLKCTL0_FCCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_FCCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FCCLKDIV_DIV_SHIFT)) & CLKCTL0_FCCLKDIV_DIV_MASK)

#define CLKCTL0_FCCLKDIV_BUSY_MASK               (0x10000000U)
#define CLKCTL0_FCCLKDIV_BUSY_SHIFT              (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_FCCLKDIV_BUSY(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FCCLKDIV_BUSY_SHIFT)) & CLKCTL0_FCCLKDIV_BUSY_MASK)

#define CLKCTL0_FCCLKDIV_RESET_MASK              (0x20000000U)
#define CLKCTL0_FCCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Reset Divider Counter
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL0_FCCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FCCLKDIV_RESET_SHIFT)) & CLKCTL0_FCCLKDIV_RESET_MASK)

#define CLKCTL0_FCCLKDIV_HALT_MASK               (0x40000000U)
#define CLKCTL0_FCCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halt Divider Counter
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL0_FCCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FCCLKDIV_HALT_SHIFT)) & CLKCTL0_FCCLKDIV_HALT_MASK)

#define CLKCTL0_FCCLKDIV_REQFLAG_MASK            (0x80000000U)
#define CLKCTL0_FCCLKDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_FCCLKDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FCCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_FCCLKDIV_REQFLAG_MASK)
/*! @} */

/* The count of CLKCTL0_FCCLKDIV */
#define CLKCTL0_FCCLKDIV_COUNT                   (14U)

/*! @name FCFCLKSEL - LP_FLEXCOMM0 Clock Source Select..LP_FLEXCOMM13 Clock Source Select */
/*! @{ */

#define CLKCTL0_FCFCLKSEL_SEL_MASK               (0x3U)
#define CLKCTL0_FCFCLKSEL_SEL_SHIFT              (0U)
/*! SEL - LP_FLEXCOMM Functional Clock Source Select
 *  0b00..fcclk0
 *  0b01..fcclk1
 *  0b10..fcclk2
 *  0b11..fcclk3
 */
#define CLKCTL0_FCFCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FCFCLKSEL_SEL_SHIFT)) & CLKCTL0_FCFCLKSEL_SEL_MASK)

#define CLKCTL0_FCFCLKSEL_SEL_EN_MASK            (0x4U)
#define CLKCTL0_FCFCLKSEL_SEL_EN_SHIFT           (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for LP_FLEXCOMM10 clock.
 *  0b1..Enables mux output for LP_FLEXCOMM10 clock.
 */
#define CLKCTL0_FCFCLKSEL_SEL_EN(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_FCFCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_FCFCLKSEL_SEL_EN_MASK)
/*! @} */

/* The count of CLKCTL0_FCFCLKSEL */
#define CLKCTL0_FCFCLKSEL_COUNT                  (14U)

/*! @name SAI012FCLKSEL - SAI0, SAI1 and SAI2 Clock Source Select */
/*! @{ */

#define CLKCTL0_SAI012FCLKSEL_SEL_MASK           (0x3U)
#define CLKCTL0_SAI012FCLKSEL_SEL_SHIFT          (0U)
/*! SEL - SAI0, SAI1 and SAI2 Clock Source Select
 *  0b00..baseclk_cmpt
 *  0b01..fro2_div8
 *  0b10..fro0_max
 *  0b11..audio_clk_cmpt
 */
#define CLKCTL0_SAI012FCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SAI012FCLKSEL_SEL_SHIFT)) & CLKCTL0_SAI012FCLKSEL_SEL_MASK)

#define CLKCTL0_SAI012FCLKSEL_SEL_EN_MASK        (0x4U)
#define CLKCTL0_SAI012FCLKSEL_SEL_EN_SHIFT       (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for SAI0, SAI1 and SAI2 clocks.
 *  0b1..Enables mux output for SAI0, SAI1 and SAI2 clocks.
 */
#define CLKCTL0_SAI012FCLKSEL_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SAI012FCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_SAI012FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SAI012CLKDIV - SAI0, SAI1 and SAI2 Functional Clock Divider */
/*! @{ */

#define CLKCTL0_SAI012CLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_SAI012CLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_SAI012CLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SAI012CLKDIV_DIV_SHIFT)) & CLKCTL0_SAI012CLKDIV_DIV_MASK)

#define CLKCTL0_SAI012CLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL0_SAI012CLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_SAI012CLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SAI012CLKDIV_BUSY_SHIFT)) & CLKCTL0_SAI012CLKDIV_BUSY_MASK)

#define CLKCTL0_SAI012CLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_SAI012CLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset Divider Counter
 *  0b0..No effect
 *  0b1..Reset the divider counter.
 */
#define CLKCTL0_SAI012CLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SAI012CLKDIV_RESET_SHIFT)) & CLKCTL0_SAI012CLKDIV_RESET_MASK)

#define CLKCTL0_SAI012CLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_SAI012CLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt Divider Counter
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL0_SAI012CLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SAI012CLKDIV_HALT_SHIFT)) & CLKCTL0_SAI012CLKDIV_HALT_MASK)

#define CLKCTL0_SAI012CLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_SAI012CLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_SAI012CLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_SAI012CLKDIV_REQFLAG_SHIFT)) & CLKCTL0_SAI012CLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CTIMERCLKDIV - CTIMER0 Functional Clock Divider..CTIMER4 Functional Clock Divider */
/*! @{ */

#define CLKCTL0_CTIMERCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_CTIMERCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_CTIMERCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CTIMERCLKDIV_DIV_SHIFT)) & CLKCTL0_CTIMERCLKDIV_DIV_MASK)

#define CLKCTL0_CTIMERCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL0_CTIMERCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_CTIMERCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CTIMERCLKDIV_BUSY_SHIFT)) & CLKCTL0_CTIMERCLKDIV_BUSY_MASK)

#define CLKCTL0_CTIMERCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_CTIMERCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset Divider Counter
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL0_CTIMERCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CTIMERCLKDIV_RESET_SHIFT)) & CLKCTL0_CTIMERCLKDIV_RESET_MASK)

#define CLKCTL0_CTIMERCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_CTIMERCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt Divider Counter
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL0_CTIMERCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CTIMERCLKDIV_HALT_SHIFT)) & CLKCTL0_CTIMERCLKDIV_HALT_MASK)

#define CLKCTL0_CTIMERCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_CTIMERCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_CTIMERCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CTIMERCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_CTIMERCLKDIV_REQFLAG_MASK)
/*! @} */

/* The count of CLKCTL0_CTIMERCLKDIV */
#define CLKCTL0_CTIMERCLKDIV_COUNT               (5U)

/*! @name CTIMERFCLKSEL - CTIMER0 Functional Clock Source Select..CTIMER4 Functional Clock Source Select */
/*! @{ */

#define CLKCTL0_CTIMERFCLKSEL_SEL_MASK           (0x3U)
#define CLKCTL0_CTIMERFCLKSEL_SEL_SHIFT          (0U)
/*! SEL - CTIMER4 Functional Clock Source Select
 *  0b00..baseclk_cmpt
 *  0b01..audio_clk_cmpt
 *  0b10..fro0_max
 *  0b11..wake32k_clk
 */
#define CLKCTL0_CTIMERFCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CTIMERFCLKSEL_SEL_SHIFT)) & CLKCTL0_CTIMERFCLKSEL_SEL_MASK)

#define CLKCTL0_CTIMERFCLKSEL_SEL_EN_MASK        (0x4U)
#define CLKCTL0_CTIMERFCLKSEL_SEL_EN_SHIFT       (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for CTIMER0 clock.
 *  0b1..Enables mux output for CTIMER0 clock.
 */
#define CLKCTL0_CTIMERFCLKSEL_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CTIMERFCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_CTIMERFCLKSEL_SEL_EN_MASK)
/*! @} */

/* The count of CLKCTL0_CTIMERFCLKSEL */
#define CLKCTL0_CTIMERFCLKSEL_COUNT              (5U)

/*! @name TRNGFCLKSEL - TRNG Functional Clock Source Select */
/*! @{ */

#define CLKCTL0_TRNGFCLKSEL_SEL_MASK             (0x3U)
#define CLKCTL0_TRNGFCLKSEL_SEL_SHIFT            (0U)
/*! SEL - TRNG Functional Clock Source Select
 *  0b00..baseclk_cmpt
 *  0b01..fro1_div2
 *  0b10..fro1_div8
 *  0b11..fro1_div3
 */
#define CLKCTL0_TRNGFCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TRNGFCLKSEL_SEL_SHIFT)) & CLKCTL0_TRNGFCLKSEL_SEL_MASK)

#define CLKCTL0_TRNGFCLKSEL_SEL_EN_MASK          (0x4U)
#define CLKCTL0_TRNGFCLKSEL_SEL_EN_SHIFT         (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for TRNG clock.
 *  0b1..Enables mux output for TRNG clock.
 */
#define CLKCTL0_TRNGFCLKSEL_SEL_EN(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TRNGFCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_TRNGFCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name TRNGFCLKDIV - TRNG FCLK Clock Divider */
/*! @{ */

#define CLKCTL0_TRNGFCLKDIV_DIV_MASK             (0xFFU)
#define CLKCTL0_TRNGFCLKDIV_DIV_SHIFT            (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_TRNGFCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TRNGFCLKDIV_DIV_SHIFT)) & CLKCTL0_TRNGFCLKDIV_DIV_MASK)

#define CLKCTL0_TRNGFCLKDIV_BUSY_MASK            (0x10000000U)
#define CLKCTL0_TRNGFCLKDIV_BUSY_SHIFT           (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_TRNGFCLKDIV_BUSY(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TRNGFCLKDIV_BUSY_SHIFT)) & CLKCTL0_TRNGFCLKDIV_BUSY_MASK)

#define CLKCTL0_TRNGFCLKDIV_RESET_MASK           (0x20000000U)
#define CLKCTL0_TRNGFCLKDIV_RESET_SHIFT          (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL0_TRNGFCLKDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TRNGFCLKDIV_RESET_SHIFT)) & CLKCTL0_TRNGFCLKDIV_RESET_MASK)

#define CLKCTL0_TRNGFCLKDIV_HALT_MASK            (0x40000000U)
#define CLKCTL0_TRNGFCLKDIV_HALT_SHIFT           (30U)
/*! HALT - Halt Divider Counter
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL0_TRNGFCLKDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TRNGFCLKDIV_HALT_SHIFT)) & CLKCTL0_TRNGFCLKDIV_HALT_MASK)

#define CLKCTL0_TRNGFCLKDIV_REQFLAG_MASK         (0x80000000U)
#define CLKCTL0_TRNGFCLKDIV_REQFLAG_SHIFT        (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_TRNGFCLKDIV_REQFLAG(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_TRNGFCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_TRNGFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name I3C01FCLKSEL - I3C0 and I3C1 Functional Clock Source Select */
/*! @{ */

#define CLKCTL0_I3C01FCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL0_I3C01FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - I3C0 and I3C1 Functional Clock Source Select
 *  0b00..baseclk_cmpt
 *  0b01..fro0_max
 *  0b10..fro1_div8
 *  0b11..osc_clk
 */
#define CLKCTL0_I3C01FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01FCLKSEL_SEL_SHIFT)) & CLKCTL0_I3C01FCLKSEL_SEL_MASK)

#define CLKCTL0_I3C01FCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL0_I3C01FCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Enable Clock Mux Output
 *  0b0..Gates mux output for I3C0 and I3C1 clocks.
 *  0b1..Enables mux output for I3C0 and I3C1 clocks.
 */
#define CLKCTL0_I3C01FCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01FCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_I3C01FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name I3C01PCLKSEL - I3C0 and I3C1 P-CLK Source Select */
/*! @{ */

#define CLKCTL0_I3C01PCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL0_I3C01PCLKSEL_SEL_SHIFT           (0U)
/*! SEL - I3C0 and I3C1 P-CLK Source Select
 *  0b00..baseclk_cmpt
 *  0b01..main_pll_pfd0
 *  0b10..fro0_max
 *  0b11..fro1_max
 */
#define CLKCTL0_I3C01PCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01PCLKSEL_SEL_SHIFT)) & CLKCTL0_I3C01PCLKSEL_SEL_MASK)

#define CLKCTL0_I3C01PCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL0_I3C01PCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for I3C0 and I3C1 P-CLK.
 *  0b1..Enables mux output for I3C0 and I3C1 P-CLK.
 */
#define CLKCTL0_I3C01PCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01PCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_I3C01PCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name I3C01PCLKDIV - I3C0 and I3C1 P-CLK Divider */
/*! @{ */

#define CLKCTL0_I3C01PCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_I3C01PCLKDIV_DIV_SHIFT           (0U)
/*! DIV - I3C0, I3C1 Clock Divider Value */
#define CLKCTL0_I3C01PCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01PCLKDIV_DIV_SHIFT)) & CLKCTL0_I3C01PCLKDIV_DIV_MASK)

#define CLKCTL0_I3C01PCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL0_I3C01PCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_I3C01PCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01PCLKDIV_BUSY_SHIFT)) & CLKCTL0_I3C01PCLKDIV_BUSY_MASK)

#define CLKCTL0_I3C01PCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_I3C01PCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset Divider Counter
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL0_I3C01PCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01PCLKDIV_RESET_SHIFT)) & CLKCTL0_I3C01PCLKDIV_RESET_MASK)

#define CLKCTL0_I3C01PCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_I3C01PCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt Divider Counter
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL0_I3C01PCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01PCLKDIV_HALT_SHIFT)) & CLKCTL0_I3C01PCLKDIV_HALT_MASK)

#define CLKCTL0_I3C01PCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_I3C01PCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The Divider change has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL0_I3C01PCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01PCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_I3C01PCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name I3C01FCLKDIV - I3C0 and I3C1 Functional Clock Divider */
/*! @{ */

#define CLKCTL0_I3C01FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_I3C01FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - I3C0 and I3C1 Clock Divider Value */
#define CLKCTL0_I3C01FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01FCLKDIV_DIV_SHIFT)) & CLKCTL0_I3C01FCLKDIV_DIV_MASK)

#define CLKCTL0_I3C01FCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL0_I3C01FCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_I3C01FCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01FCLKDIV_BUSY_SHIFT)) & CLKCTL0_I3C01FCLKDIV_BUSY_MASK)

#define CLKCTL0_I3C01FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_I3C01FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset Divider Counter
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL0_I3C01FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01FCLKDIV_RESET_SHIFT)) & CLKCTL0_I3C01FCLKDIV_RESET_MASK)

#define CLKCTL0_I3C01FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_I3C01FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt Divider Counter
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL0_I3C01FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01FCLKDIV_HALT_SHIFT)) & CLKCTL0_I3C01FCLKDIV_HALT_MASK)

#define CLKCTL0_I3C01FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_I3C01FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change has been finished.
 *  0b1..The change is being made to the divider counter.
 */
#define CLKCTL0_I3C01FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_I3C01FCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_I3C01FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CLKOUTCLKSEL - CLKOUT_VDD2 Clock Select Source */
/*! @{ */

#define CLKCTL0_CLKOUTCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL0_CLKOUTCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Select Clock Source
 *  0b00..baseclk_com2
 *  0b01..main_pll_pfd0
 *  0b10..fro0_max
 *  0b11..fro1_max
 */
#define CLKCTL0_CLKOUTCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CLKOUTCLKSEL_SEL_SHIFT)) & CLKCTL0_CLKOUTCLKSEL_SEL_MASK)

#define CLKCTL0_CLKOUTCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL0_CLKOUTCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Enable Clock Mux Output
 *  0b0..Gates mux output for CLKOUT_VDD2 clock.
 *  0b1..Enables mux output for CLKOUT_VDD2 clock.
 */
#define CLKCTL0_CLKOUTCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CLKOUTCLKSEL_SEL_EN_SHIFT)) & CLKCTL0_CLKOUTCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name CLKOUTCLKDIV - CLKOUT_VDD2 Clock Divider */
/*! @{ */

#define CLKCTL0_CLKOUTCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL0_CLKOUTCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL0_CLKOUTCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CLKOUTCLKDIV_DIV_SHIFT)) & CLKCTL0_CLKOUTCLKDIV_DIV_MASK)

#define CLKCTL0_CLKOUTCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL0_CLKOUTCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT_VDD2 is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_CLKOUTCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CLKOUTCLKDIV_BUSY_SHIFT)) & CLKCTL0_CLKOUTCLKDIV_BUSY_MASK)

#define CLKCTL0_CLKOUTCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL0_CLKOUTCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset the Divider Counter
 *  0b0..No effect
 *  0b1..Reset the Divider Counter
 */
#define CLKCTL0_CLKOUTCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CLKOUTCLKDIV_RESET_SHIFT)) & CLKCTL0_CLKOUTCLKDIV_RESET_MASK)

#define CLKCTL0_CLKOUTCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL0_CLKOUTCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt Divider Counter
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL0_CLKOUTCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CLKOUTCLKDIV_HALT_SHIFT)) & CLKCTL0_CLKOUTCLKDIV_HALT_MASK)

#define CLKCTL0_CLKOUTCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL0_CLKOUTCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL0_CLKOUTCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL0_CLKOUTCLKDIV_REQFLAG_SHIFT)) & CLKCTL0_CLKOUTCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name AUDIOVDD2CLKSEL - VDD2_COMP Audio Clock Source Select */
/*! @{ */

#define CLKCTL0_AUDIOVDD2CLKSEL_SEL_MASK         (0x3U)
#define CLKCTL0_AUDIOVDD2CLKSEL_SEL_SHIFT        (0U)
/*! SEL - Clock Source Select
 *  0b00..mclk_in
 *  0b01..osc_clk
 *  0b10..fro2_div8
 *  0b11..audio_pll_pfd3
 */
#define CLKCTL0_AUDIOVDD2CLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL0_AUDIOVDD2CLKSEL_SEL_SHIFT)) & CLKCTL0_AUDIOVDD2CLKSEL_SEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CLKCTL0_Register_Masks */


/*!
 * @}
 */ /* end of group CLKCTL0_Peripheral_Access_Layer */


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


#endif  /* PERI_CLKCTL0_H_ */

